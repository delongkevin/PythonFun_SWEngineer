/*******************************************************************************
 * cc.c
 *
 * Color-correction calculator for surround view
 *
 * Copyright (c) 2020 Cogent Embedded Inc.
 * ALL RIGHTS RESERVED.
 *
 * The source code contained or described herein and all documents related to the
 * source code("Software") or their modified versions are owned by
 * Cogent Embedded Inc. or its affiliates.
 *
 * No part of the Software may be used, copied, reproduced, modified, published,
 * uploaded, posted, transmitted, distributed, or disclosed in any way without
 * prior express written permission from Cogent Embedded Inc.
 *
 * Cogent Embedded Inc. grants a nonexclusive, non-transferable, royalty-free
 * license to use the Software to Licensee without the right to sublicense.
 * Licensee agrees not to distribute the Software to any third-party without
 * the prior written permission of Cogent Embedded Inc.
 *
 * Unless otherwise agreed by Cogent Embedded Inc. in writing, you may not remove
 * or alter this notice or any other notice embedded in Software in any way.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *******************************************************************************/

#define MODULE_TAG                      CC

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "common.h"
#include "display.h"
#include "camera.h"
#include "math-neon.h"
#include "config.h"

/*******************************************************************************
 * Tracing configuration
 ******************************************************************************/

TRACE_TAG(INIT, 1);
TRACE_TAG(INFO, 3);
TRACE_TAG(DEBUG, 6);

/*******************************************************************************
 * Types definitions
 ******************************************************************************/

/**> Number of rows in a CC-ROI lattice */
#define CC_LATTICE_ROWS             16

/**> Number of columns in a CC-ROI lattice */
#define CC_LATTICE_COLUMNS          16

/**> Total lattice size */
#define CC_LATTICE_SIZE             (CC_LATTICE_ROWS * CC_LATTICE_COLUMNS)

/**
 * @brief   Color-correction data
 */
typedef struct cc_data
{
    /**> UV-coordinates of the cameras for lower/upper blend regions */
    float32_t   uv[4][2][CC_LATTICE_ROWS * CC_LATTICE_COLUMNS][2];

    /**> Instant mean color statistics, YUV */
    float32_t   mean[4][2][3];

    /**> Correction coefficients, YUV */
    float32_t   coeffs[4][2][3];

    /**> Correction coefficients, RGB */
    float32_t   coeffs_rgb[4][2][3];

    /**> Color correction factors */
    float32_t   factor[4][3][3];

}   cc_data_t;

/*******************************************************************************
 * External declarations - tbd - reorganize it somehow
 ******************************************************************************/

/**> Read image pixel in YUV BT.709 */
extern void img_get_yuv_bt709_f32(image_data_t *img, int32_t x, int32_t y, float32_t yuv[3]);

/*******************************************************************************
 * Internal functions definitions
 ******************************************************************************/

/**
 * @param   c0[in]          Lower-region camera
 * @param   c1[in]          Higher-region camera
 * @param   roi[in]         ROI on the ground: [Xmin,Ymin,Xmax,Ymax]
 * @param   uv0[out]        Array of UV-coordinates for lower-region camera
 * @param   uv1[out]        Array of UV-coordinates for lower-region camera
 */
static void cc_create_points(camera_data_t *c0, camera_data_t *c1, float32_t *roi, float32_t (*uv0)[2], float32_t (*uv1)[2])
{
    const int N = CC_LATTICE_COLUMNS;
    const int M = CC_LATTICE_ROWS;

    /* ...load destination tile:
     * [0]: { Xmin, Xmax }
     * [1]: { Ymin, Ymax }
     */
    float32x2x2_t   ROI = vld2_f32(roi);
    float32x2_t     P0 = vtrn1_f32(ROI.val[0], ROI.val[1]);
    float32x2_t     D = vsub_f32(vtrn2_f32(ROI.val[0], ROI.val[1]), P0);

    /* ...calculate steps for X/Y (we process 4 points at once for X-direction) */
    float32x2_t     S = vmul_f32(D, __mk_float32x2(4.0f / (float32_t)(N - 1), 1.0f / (float32_t)(M - 1)));

    /* ...produce points on the ground */
    float32_t       points[N * M][3] __attribute__((aligned(16)));
    float32_t       xyz[N * M][3] __attribute__((aligned(16)));
    float32_t     (*p)[3] = &points[0];
    int             i, j;
    float32x4x3_t   P;

    /* ...prepare first point of the tile */
    float32x4_t     X0 = vmlaq_lane_f32(vdupq_lane_f32(P0, 0), __mk_float32x4(0.0f, 0.25f, 0.5f, 0.75f), S, 0);

    P.val[1] = vdupq_lane_f32(P0, 1);
    P.val[2] = vdupq_n_f32(0.0f);

    for (j = 0; j < M; j++)
    {
        P.val[0] = X0;
        for (i = 0; i < N; i += 4)
        {
            TRACE(0, _b("[j=%d][i=%d] X=%f,%f,%f,%f, Y=%f,%f,%f,%f"), j, i, __float32x4_p(P.val[0]), __float32x4_p(P.val[1]));

            /* ...store points on the ground */
            vst3q_f32(*p, P);
            p += 4;

            /* ...advance X component */
            P.val[0] = vaddq_f32(P.val[0], vdupq_lane_f32(S, 0));
        }

        /* ...advance Y-component */
        P.val[1] = vaddq_f32(P.val[1], vdupq_lane_f32(S, 1));
    }

    /* ...map points into lower-region camera UV-space */
    map_world_to_cam(points, c0->T, c0->R, N * M, xyz);
    distort_kannala_clamp(xyz, uv0, c0->params, N * M);

    /* ...map points into upper-region camera UV-space */
    map_world_to_cam(points, c1->T, c1->R, N * M, xyz);
    distort_kannala_clamp(xyz, uv1, c1->params, N * M);
}

/**
 * @brief   Calculate average YUV color of the image pixels
 *
 * @param   image[in]       Image descriptor
 * @param   uv[in]          Array of UV-coordinates, of lattice size
 * @param   yuv[out]        Average YUV color
 */
static void cc_calc_avg_yuv(image_data_t *img, float32_t (*uv)[2], float32_t yuv[3])
{
    int32_t         i;

    /* ...reset average color accumulator */
    float32x4x3_t   YUV;
    YUV.val[0] = vdupq_n_f32(0.0f);
    YUV.val[1] = vdupq_n_f32(0.0f);
    YUV.val[2] = vdupq_n_f32(0.0f);

    /* ...calculate average YUV color of points */
    for (i = 0; i < CC_LATTICE_ROWS * CC_LATTICE_COLUMNS; i += 4)
    {
        float32x4x2_t   UV;

        /* ...read coordinates of 4 pixels:
         * [0]: {U0, U1, U2, U3}
         * [1]: {V0, V1, V2, V3}
         */
        UV = vld2q_f32(*uv);
        uv += 4;

        /* ...get integer coordinates of the points (simple truncation) */
        uint32x4x2_t    XY;
        XY.val[0] = vcvtq_u32_f32(vmulq_n_f32(UV.val[0], (float32_t)img->width));
        XY.val[1] = vcvtq_u32_f32(vmulq_n_f32(UV.val[1], (float32_t)img->height));

        /* ...get BT.709 YUV value of the pixels addressed */
        float32_t       yuv[4][3];
        img_get_yuv_bt709_f32(img, vgetq_lane_u32(XY.val[0], 0), vgetq_lane_u32(XY.val[1], 0), yuv[0]);
        img_get_yuv_bt709_f32(img, vgetq_lane_u32(XY.val[0], 1), vgetq_lane_u32(XY.val[1], 1), yuv[1]);
        img_get_yuv_bt709_f32(img, vgetq_lane_u32(XY.val[0], 2), vgetq_lane_u32(XY.val[1], 2), yuv[2]);
        img_get_yuv_bt709_f32(img, vgetq_lane_u32(XY.val[0], 3), vgetq_lane_u32(XY.val[1], 3), yuv[3]);

        /* ...add values to accumulator */
        float32x4x3_t   C = vld3q_f32(&yuv[0][0]);
        YUV.val[0] = vaddq_f32(YUV.val[0], C.val[0]);
        YUV.val[1] = vaddq_f32(YUV.val[1], C.val[1]);
        YUV.val[2] = vaddq_f32(YUV.val[2], C.val[2]);
    }

    /* ...calculate average color of the lattice */
    YUV.val[0] = vmulq_n_f32(YUV.val[0], 1.0f / (float32_t)CC_LATTICE_SIZE);
    YUV.val[1] = vmulq_n_f32(YUV.val[1], 1.0f / (float32_t)CC_LATTICE_SIZE);
    YUV.val[2] = vmulq_n_f32(YUV.val[2], 1.0f / (float32_t)CC_LATTICE_SIZE);

    /* ...build average across lanes of the accumulator */
    float32x2x3_t   C;
    C.val[0] = vpadd_f32(vget_low_f32(YUV.val[0]), vget_high_f32(YUV.val[0]));
    C.val[1] = vpadd_f32(vget_low_f32(YUV.val[1]), vget_high_f32(YUV.val[1]));
    C.val[2] = vpadd_f32(vget_low_f32(YUV.val[2]), vget_high_f32(YUV.val[2]));

    /* ...set resulting color */
    yuv[0] = vpadds_f32(C.val[0]);
    yuv[1] = vpadds_f32(C.val[1]);
    yuv[2] = vpadds_f32(C.val[2]);
}

/**> Averaging LPF coefficient - tbd - hardcode of make parametrizable? */
#define FILTER_COEF_A       (0.8f)
#define FILTER_COEF_B       (1.0f - FILTER_COEF_A)

/**
 * @brief   Update correction coefficients
 *
 * @param   M[in]           Current segment mean color:
 *                          [0] = { Y0, Y1 }
 *                          [1] = { U0, U1 }
 *                          [2] = { V0, V1 }
 * @param   ML[in]          Lower segment mean color
 * @param   MU[in]          Upper segment mean color
 * @param   clamp[in]       Coefficients clamping flag
 * @param   coeffs[out]     Correction coefficient
 */
static inline void cc_calc_segment_coefs(float32x2x3_t M, float32x2x3_t ML, float32x2x3_t MU, int clamp, float32_t coeffs[2][3])
{
    float32x2x3_t   D;

    D.val[0] = vsub_f32(vext_f32(ML.val[0], MU.val[0], 1), M.val[0]);
    D.val[1] = vsub_f32(vext_f32(ML.val[1], MU.val[1], 1), M.val[1]);
    D.val[2] = vsub_f32(vext_f32(ML.val[2], MU.val[2], 1), M.val[2]);

    TRACE(0, _b("MC: %f,%f, ML:%f,%f, MU:%f,%f"), __float32x2_p(M.val[0]), __float32x2_p(ML.val[0]), __float32x2_p(MU.val[0]));
    TRACE(0, _b("D: %f,%f : %f,%f : %f,%f"), __float32x2_p(D.val[0]), __float32x2_p(D.val[1]), __float32x2_p(D.val[2]));

    /* ...clamp coefficients */
    if (clamp != 0)
    {
        D.val[0] = vmin_f32(vmax_f32(D.val[0], vmov_n_f32(-200.0f)), vmov_n_f32(200.0f));

        float32x2_t C0 = vmin_f32(vmax_f32(vsub_f32(D.val[1], D.val[2]), vmov_n_f32(-100.0f)), vmov_n_f32(100.0f));
        float32x2_t C1 = vmin_f32(vmax_f32(vadd_f32(D.val[1], D.val[2]), vmov_n_f32(-100.0f)), vmov_n_f32(100.0f));

        D.val[1] = vmul_n_f32(vadd_f32(C1, C0), 0.5f);
        D.val[2] = vmul_n_f32(vsub_f32(C1, C0), 0.5f);
    }

    /* ...load current values of correction coefficients */
    float32x2x3_t   C = vld3_f32(coeffs[0]);

    C.val[0] = vmla_n_f32(vmul_n_f32(C.val[0], FILTER_COEF_A), D.val[0], FILTER_COEF_B * 0.5f);
    C.val[1] = vmla_n_f32(vmul_n_f32(C.val[1], FILTER_COEF_A), D.val[1], FILTER_COEF_B * 0.5f);
    C.val[2] = vmla_n_f32(vmul_n_f32(C.val[2], FILTER_COEF_A), D.val[2], FILTER_COEF_B * 0.5f);

    TRACE(0, _b("corr: [0]:%f,%f, [1]:%f,%f, [2]:%f,%f"), __float32x2_p(C.val[0]), __float32x2_p(C.val[1]), __float32x2_p(C.val[2]));

    vst3_f32(coeffs[0], C);
}

/**
 * @brief   Update statistics for a single blend region
 *
 * @param   cc[in]          Color-correction data
 * @param   img0[in]        Lower-camera image descriptor
 * @param   uv0[in]         UV-coordinates of pixels for lower camera
 * @param   img1[in]        Upper-camera image descriptor
 * @param   uv1[in]         UV-coordinates of pixels for upper camera
 */
static void cc_update_stat(image_data_t *img0, float32_t (*uv0)[2], image_data_t *img1, float32_t (*uv1)[2], float32_t *mean0, float32_t *mean1);

/*******************************************************************************
 * Color-space conversion functions
 ******************************************************************************/

/**
 * @brief   Convert RGB to YUV
 *
 * @param   rgb[in]         4 RGB color codes
 * @param   yuv[out]        4 YUV color codes
 */
void cc_cvt_rgb_to_yuv_bt709_f32(float32_t (*rgb)[3], float32_t (*yuv)[3])
{
    float32x4x3_t   RGB = vld3q_f32(*rgb);

    /* ...multiply by RGB-to-YUV matrix */
    float32x4x3_t   YUV;
    YUV.val[0] = vmlaq_n_f32(vmlaq_n_f32(vmulq_n_f32(RGB.val[0], 0.2126f), RGB.val[1], 0.7152f), RGB.val[2], 0.0722f);
    YUV.val[1] = vmlaq_n_f32(vmlaq_n_f32(vmulq_n_f32(RGB.val[0], -0.114572106f), RGB.val[1], -0.385427893f), RGB.val[2], 0.5f);
    YUV.val[2] = vmlaq_n_f32(vmlaq_n_f32(vmulq_n_f32(RGB.val[0], 0.5f), RGB.val[1], -0.454152908f), RGB.val[2], -0.045847091f);

    vst3q_f32(*yuv, YUV);
}

/**
 * @brief   Convert YUV to RGB
 *
 * @param   yuv[in]         4 YUV color codes
 * @param   rgb[out]        4 RGB color codes
 */
void cc_cvt_yuv_to_rgb_bt709_f32(float32_t (*yuv)[3], float32_t (*rgb)[3])
{
    float32x4x3_t   YUV = vld3q_f32(*yuv);

    /* ...multiply by YUV-to-RGB matrix */
    float32x4x3_t   RGB;
    RGB.val[0] = vmlaq_n_f32(YUV.val[0], YUV.val[2], 1.575f);
    RGB.val[1] = vmlaq_n_f32(vmlaq_n_f32(YUV.val[0], YUV.val[1], -0.187f), YUV.val[2], -0.468f);
    RGB.val[2] = vmlaq_n_f32(YUV.val[0], YUV.val[1], 1.856f);

    vst3q_f32(*rgb, RGB);
}

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Generate UV-coordinates of the points participating in statistics
 *          collection for correcting coefficients calculation
 *
 * @param   cc[in]          Color-correction data
 * @param   cfg[in]         Global configuration data pointer
 * @param   camera[in]      Camera data array (tbd - not too good)
 */
void cc_generate_points(cc_data_t *cc, cfg_data_t *cfg, camera_data_t *camera)
{
    int32_t     i;

    float32_t       corners[SV_CAMERAS_NUMBER][2];

    corners[0][0] = camera[0].T[0];
    corners[0][1] = camera[1].T[1];
    corners[1][0] = camera[2].T[0];
    corners[1][1] = camera[1].T[1];
    corners[2][0] = camera[2].T[0];
    corners[2][1] = camera[3].T[1];
    corners[3][0] = camera[0].T[0];
    corners[3][1] = camera[3].T[1];

    float32_t       rois[SV_CAMERAS_NUMBER][4];

    for (i = 0; i < 4; i++)
    {
        float32_t sign_x = (corners[i][0] < 0) ? -1 : 1;
        float32_t sign_y = (corners[i][1] < 0) ? -1 : 1;
        
        rois[i][0] = corners[i][0] + sign_x*cfg->cc.offset_x;
        rois[i][1] = corners[i][1] + sign_y*cfg->cc.offset_y;
        rois[i][2] = rois[i][0] + sign_x*cfg->cc.size_mm;
        rois[i][3] = rois[i][1] + sign_y*cfg->cc.size_mm;
#if 0
        for (int j = 0; j < 4; j++)
        {
            ME_Debugger_F_Printf_v("\nrois[%d][%d] = %f\n", i, j, rois[i][j]);
        }
#endif
    }

    /* ...process all blend regions: FL/RL/RR/FR */
    for (i = 0; i < 4; i++)
    {
        int32_t     k0 = i;
        int32_t     k1 = (i + 1) & 3;

        /* ...generate set of points for color-statistics calculation */
        cc_create_points(&camera[k0], &camera[k1], rois[i], cc->uv[k0][1], cc->uv[k1][0]);
    }
}

/**
 * @brief   Calculate color statistics of the regions
 *
 * @param   cc[in]              Color-correction data
 * @param   texture[in]         Array of raw input buffers
 */
void cc_update(cc_data_t *cc, texture_data_t **tex)
{
    int32_t         i;

    /* ...fetch YUV coordinates of the points for all the blend regions */
    for (i = 0; i < 4; i++)
    {
        image_data_t    image;

        if (tex[i] == NULL)     continue;

        if (texture_map(tex[i], &image) == 0)
        {
            cc_calc_avg_yuv(&image, cc->uv[i][0], cc->mean[i][0]);
            cc_calc_avg_yuv(&image, cc->uv[i][1], cc->mean[i][1]);

            TRACE(DEBUG, _b("mean[%d][0] = %f,%f,%f, mean[%d][1]=%f,%f,%f"),
                  i, cc->mean[i][0][0], cc->mean[i][0][1], cc->mean[i][0][2],
                  i, cc->mean[i][1][0], cc->mean[i][1][1], cc->mean[i][1][2]);

            texture_unmap(tex[i]);
        }
        else
        {
            TRACE(ERROR, _x("failed to map texture-%d: %s"), i, strerror(errno));
        }
    }

    /* ...update color-correction coefficients (in YUV) */
    float32x2x3_t   M0 = vld3_f32(cc->mean[0][0]);
    float32x2x3_t   M1 = vld3_f32(cc->mean[1][0]);
    float32x2x3_t   M2 = vld3_f32(cc->mean[2][0]);
    float32x2x3_t   M3 = vld3_f32(cc->mean[3][0]);
    int             clamp = 1;

    cc_calc_segment_coefs(M0, M3, M1, clamp, cc->coeffs[0]);
    cc_calc_segment_coefs(M1, M0, M2, clamp, cc->coeffs[1]);
    cc_calc_segment_coefs(M2, M1, M3, clamp, cc->coeffs[2]);
    cc_calc_segment_coefs(M3, M2, M0, clamp, cc->coeffs[3]);

    /* ...convert correction coefficients to RGB */
    cc_cvt_yuv_to_rgb_bt709_f32(cc->coeffs[0], cc->coeffs_rgb[0]);
    cc_cvt_yuv_to_rgb_bt709_f32(cc->coeffs[2], cc->coeffs_rgb[2]);

    for (int i = 0; i < 4; i++)
    {
        TRACE(0, _b("coeffs-rgb[%d]: %f,%f,%f - %f,%f,%f"), i, cc->coeffs_rgb[i][0][0], cc->coeffs_rgb[i][0][1], cc->coeffs_rgb[i][0][2], cc->coeffs_rgb[i][1][0], cc->coeffs_rgb[i][1][1], cc->coeffs_rgb[i][1][2]);
        memcpy(cc->factor[i], cc->coeffs_rgb[i], sizeof(cc->coeffs_rgb[i]));
        memcpy(cc->factor[i][2], (float32_t[3]){1.0f, 1.0f, 1.0f}, sizeof(float32_t[3]));
    }
}

/**
 * @brief   Enable/disable masking of camera image with color
 *
 * @param   cc[in]      Color-correction data
 * @param   id[in]      Camera id
 * @param   color[in]   Color to use for masking the camera
 * @param   enable[in]  Mask enable flag
 */
void cc_mask_camera(cc_data_t *cc, uint32_t id, float32_t color[3], int enable)
{
    if (enable)
    {
        memcpy(cc->factor[id][0], color, sizeof(float32_t[3]));
        memcpy(cc->factor[id][1], color, sizeof(float32_t[3]));
        memset(cc->factor[id][2], 0, sizeof(float32_t[3]));
        TRACE(0, _b("cam-%u: enable mask"), id);
    }
    else
    {
        memcpy(cc->factor[id][0], cc->coeffs_rgb[id], sizeof(float32_t[2][3]));
        memcpy(cc->factor[id][2], (float32_t [3]){1.0f, 1.0f, 1.0f}, sizeof(float32_t[3]));
    }
}

/**
 * @brief   Return color-correction coefficients array
 *
 * @param   cc[in]      Color-correction data
 *
 * @return              Pointer to RGB-correction coefficients
 */
float32_t (*cc_get_coefs(cc_data_t *cc))[3][3]
{
    return cc->factor;
}

/**
 * @brief   Create color correction module
 *
 * @param   cfg[in]         Global configuration data
 * @param   camera[in]      Camera data array (tbd - not too good)
 *
 * @return                  Color-correction module handle, or NULL
 */
cc_data_t  * cc_data_create(cfg_data_t *cfg, camera_data_t *camera)
{
    cc_data_t  *cc;

    /* ...allocate memeory */
    CHK_ERR(cc = calloc(1, sizeof(*cc)), NULL);

    /* ...generate points */
    cc_generate_points(cc, cfg, camera);

    return cc;
}
