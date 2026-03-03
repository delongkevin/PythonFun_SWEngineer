/*******************************************************************************
 * mesh-gen.h
 *
 * Mesh generator public API
 *
 * Copyright (c) 2015-2020 Cogent Embedded Inc.
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

#ifndef __MESH_GEN_H
#define __MESH_GEN_H

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "camera.h"
#include "math-neon.h"
#include "vehicle-state.h"
#include "vbo-dynarray.h"

/*******************************************************************************
 * Opaque types declarations
 ******************************************************************************/

/**> Mesh generator */
typedef struct mesh_gen     mesh_gen_t;

typedef struct mesh_data    mesh_data_t;

typedef struct hv_data      hv_data_t;

/*******************************************************************************
 * Public module API
 ******************************************************************************/
/**
 * @brief   Create ctlval mesh
 *
 * @param   gen[in]             Mesh generator data
 * @param   cfg[in]             Global configuration data
 * @param   scv[in]             SCV-mesh configuration parameters
 * @param   mesh[in]            Mesh data
 *
 * @return                      Negative on failure
 */
extern int mesh_generate_ctl(mesh_gen_t *gen, cfg_data_t *cfg, cfg_ctlval_mesh_t* ctl, mesh_data_t *mesh);


/** ...alpha mask for TopView defined by four sectors */
typedef struct mesh_alphamask_cfg_s
{
    /** ...left lines for each blending zone (sector) */
    float l[4][4];

    /** ...right lines for each blending zone (sector) */
    float m[4][4];

    /** ...NDC to WorldSpace transformation matrix */
    float U[3 * 3];

} mesh_alphamask_cfg_t;

/**
 * @brief   Create single-camera-view mesh
 *
 * @param   gen[in]             Mesh generator data
 * @param   cfg[in]             Global configuration data
 * @param   scv[in]             SCV-mesh configuration parameters
 * @param   vehicle[in]         Vehicle state data
 * @param   mesh[in]            Mesh data
 *
 * @return                      Negative on failure
 */
extern int mesh_generate_scv(mesh_gen_t *gen, cfg_data_t *cfg, cfg_scv_mesh_t *scv_data, vehicle_state_t *vehicle, mesh_data_t *mesh);

/**
 * @brief   Create multi-camera view mesh (side-view / mosaic)
 *
 * @param   gen[in]             Mesh generator data
 * @param   cfg[in]             Global configuration data
 * @param   mcv[in]             MCV-mesh configuration parameters array
 * @param   vehicle[in]         Vehicle state data
 * @param   mesh[in]            Mesh data
 *
 * @return                      Negative on failure
 */
extern int mesh_generate_mcv(mesh_gen_t *gen, cfg_data_t *cfg, cfg_mcv_mesh_t *mcv, vehicle_state_t *vehicle, mesh_data_t *mesh);

/**
 * @brief   Create see-through-view mesh
 *
 * @param   gen[in]             Mesh generator data
 * @param   cfg[in]             STV-mesh configuration parameters
 * @param   mesh[in]            Mesh data
 *
 * @return                      Negative on failure
 */
extern int mesh_generate_stv(mesh_gen_t *gen, cfg_data_t *cfg, cfg_stv_mesh_t *stv, mesh_data_t *mesh);

/**
 * @brief   Create top-view mesh
 *
 * @param   gen[in]         Mesh generator data
 * @param   cfg[in]         Global configuration data
 * @param   tv[in]          TV-mesh configuration parameters
 * @param   mesh[in]        Mesh data
 *
 * @return                  Negative on failure
 */
extern int mesh_generate_tv(mesh_gen_t *gen, cfg_data_t *cfg, cfg_tv_mesh_t *tv, mesh_data_t *mesh);


/**
 * @brief   Generate line equations for TopView blending zone sectors
 *
 * @param   shadow[in]      TopView shadow sizes
 * @param   angles[in]      Blending zones corner angles (azimuths)
 * @param   offsets[in]     Offsets of TopView corner points from 'shadow'
 * @param   S[out]          Shadow points
 * @param   B0[out]         Packed corner sector boundary line equations (1)
 * @param   B1[out]         Packed corner sector boundary line equations (2)
 * @param   C0[out]         Output TopView corner points (1)
 * @param   C1[out]         Output TopView corner points (2)
 *
 * @return                  Void
 */
extern void mesh_calc_separation_zones(
    float32_t *shadow,
    float32_t *angles,
    float32_t *offsets,
    float32x2x2_t *S,
    float32x4x3_t *B0,
    float32x4x3_t *B1,
    float32x4x2_t *C0,
    float32x4x2_t *C1);

/**
 * @brief   Generate bird-view mesh for single camera (top-view)
 *
 * @param   gen[in]         Mesh-generator data
 * @param   cfg[in]         Global configuration data
 * @param   bv[in]          Bird-view configuration data
 * @param   mesh[in]        Mesh data
 *
 * @return                  Negative on failure
 */
extern int mesh_generate_bv(mesh_gen_t *gen, cfg_data_t *cfg, cfg_bv_mesh_t *bv, mesh_data_t *mesh);

/**
 * @brief   Prepare historical-view mesh generation
 *
 * @param   gen[in]             Mesh generator data
 * @param   cfg[in]             Global configuration parameters
 * @param   hv[in]              Historical-view module data
 * @param   vbo[in]             Historical-view VBOs array
 *
 * @return                      Negative on failure
 */
extern int mesh_prepare_hv(mesh_gen_t *gen, cfg_data_t *cfg, hv_data_t *hv, vbo_dynarray_t *vbo);

/**
 * @brief   Create mesh generator
 *
 * @param   cfg[in]             Global configuration data
 *
 * @return                      Mesh generator handle, or NULL on failure
 */
extern mesh_gen_t * mesh_gen_create(cfg_data_t *cfg);

/**
 * @brief   Create mesh generator
 *
 * @param   cfg[in]             Global configuration data
 *
 * @return                      Mesh generator handle, or NULL on failure
 */
extern void mesh_gen_destroy(mesh_gen_t *gen);

/**
 * @brief   Create SCV configuration as a LERP operator on source and
 *          destination configs
 *
 * @param   cfg[in]         SCV-mesh configuration
 * @param   src[in]         Source SCV-mesh configuration
 * @param   dst[in]         Destination SCV-mesh configuration
 * @param   t[in]           LERP factor
 */
extern void mesh_scv_cfg_lerp(cfg_scv_mesh_t *cfg, cfg_scv_mesh_t *src, cfg_scv_mesh_t *dst, float32_t t);

/**
 * @brief   Create STV configuration as a LERP operator on source and
 *          destination configs
 *
 * @param   cfg[in]         STV-mesh configuration
 * @param   src[in]         Source STV-mesh configuration
 * @param   dst[in]         Destination STV-mesh configuration
 * @param   t[in]           LERP factor
 */
extern void mesh_stv_cfg_lerp(cfg_stv_mesh_t *cfg, cfg_stv_mesh_t *src, cfg_stv_mesh_t *dst, float32_t t);

/**
 * @brief   Create STV configuration as a LERP operator on source and
 *          destination configs
 *
 * @param   cfg[in]         SCV-mesh configuration
 * @param   src[in]         Source SCV-mesh configuration
 * @param   dst[in]         Destination STV-mesh configuration
 * @param   t[in]           LERP factor
 */
extern void mesh_scv_stv_cfg_lerp_in(cfg_stv_mesh_t *cfg, cfg_scv_mesh_t *src, cfg_stv_mesh_t *dst, float32_t t);

/**
 * @brief   Create STV configuration as a LERP operator on source and
 *          destination configs
 *
 * @param   cfg[in]         SCV-mesh configuration
 * @param   src[in]         Source SCV-mesh configuration
 * @param   dst[in]         Destination STV-mesh configuration
 * @param   t[in]           LERP factor
 */
extern void mesh_scv_stv_cfg_lerp_out(cfg_scv_mesh_t *cfg, cfg_scv_mesh_t *src, cfg_stv_mesh_t *dst, float32_t t);

/**
 * @brief   Create STV/SCV configuration as a LERP operator on source and
 *          destination configs
 *
 * @param   cfg[in]         SCV-mesh configuration
 * @param   src[in]         Source STV-mesh configuration
 * @param   dst[in]         Destination SCV-mesh configuration
 * @param   t[in]           LERP factor
 */
extern void mesh_stv_scv_cfg_lerp_in(cfg_scv_mesh_t *cfg, cfg_stv_mesh_t *src, cfg_scv_mesh_t *dst, float32_t t);

/**
 * @brief   Create STV/SCV configuration as a LERP operator on source and
 *          destination configs
 *
 * @param   cfg[in]         STV-mesh configuration
 * @param   src[in]         Source STV-mesh configuration
 * @param   dst[in]         Destination SCV-mesh configuration
 * @param   t[in]           LERP factor
 */
extern void mesh_stv_scv_cfg_lerp_out(cfg_stv_mesh_t *cfg, cfg_stv_mesh_t *src, cfg_scv_mesh_t *dst, float32_t t);

/**
 * @brief   Calculate STV-mesh rotation matrix angles
 *
 * @param   stv[in]             STV-mesh configuration data
 */
extern void mesh_stv_fix_angles(cfg_stv_mesh_t *stv);

/**
 * @brief   Update top-view configuration for an aspect ratio change
 *
 * @param   cfg[in]             Global configuration pointer
 * @param   tv[in]              TV-mesh configuration
 */
extern void mesh_tv_fix_aspect(cfg_data_t *cfg, cfg_tv_mesh_t *tv, float32_t* area);

/**
 * @brief   Get camera data - tbd - doesn't look great
 *
 * @param   gen[in]     Mesh generator data
 */
extern camera_data_t * mesh_gen_cameras(mesh_gen_t *gen);

/**
 * @brief   Set camera parameters for mesh building procedure
 *
 * @param   gen[in]             Mesh generator data
 * @param   camera_cfg[in]      Camera configuration array
 */
extern void mesh_gen_camera_setup(mesh_gen_t *gen, cfg_camera_t *camera_cfg);

/**
 * @brief   Calculate aspect ratio for a tile
 *
 * @param   dst[in]     Destination tile: [X0,Y0,X1,Y1]
 *
 * @return              Tile height-to-width aspect ratio
 */
extern float32_t mesh_tile_aspect(int32_t *dst);

/**
 * @brief   Calculate aspect ratio for a camera FoV
 *
 * @param   fov[in]     Camera field-of-view angles: [HFoV, VFoV]
 *
 * @return              Tile height-to-width aspect ratio
 */
extern float32_t mesh_fov_aspect(float32_t *fov);

/**
 * @brief   Calculate position of the point on the ground matching the
 *          2D-coordinates of the point in virtual camera space
 *
 * @param   stv[in]         STV-view parameters
 * @param   uv[in]          2D-point in virtual camera space
 * @param   xyz[out]        Coordinates of matching 3D-point in the world
 */
extern float32_t mesh_stv_map_uv(cfg_stv_mesh_t *stv, float32_t *uv, float32_t *xyz);

extern void calculate_shadow_from_vehicle(const cfg_data_t *cfg, cfg_tv_mesh_t *tv);
extern void recalculate_position(cfg_scv_mesh_t* scv, const cfg_data_t* cfg);
extern void algo_get_matix(cfg_data_t *cfg, cfg_tv_mesh_t *tv, float32_t matrix[3*3]);

extern void undistort_kannala_gen(float32_t xyz[3], float32_t uv[2], mesh_gen_t* gen, uint32_t camera_id, float32_t Z);

extern int32_t mesh_gen_w2c(camera_data_t *cam_data, const float32_t xyz[3], float32_t uv[2]);
extern int32_t mesh_gen_w2c_camera(uint32_t cam_indx, const float32_t world_xyz[3], float32_t raw_coords[2]);
extern void undistort_kannala_gen_camera(float32_t xyz[3], float32_t uv[2], float32_t Z);

void mesh_tv_create_mask(mesh_data_t *mesh, mesh_alphamask_cfg_t* alpha_mask_cfg);

#endif  /* __MESH_GEN_H */
