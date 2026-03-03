/*******************************************************************************
 * pbr-renderer.c
 *
 * PBR renderer implementation
 *
 * Copyright (c) 2018-2021 Cogent Embedded Inc.
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

#define MODULE_TAG                      PBR

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "common.h"
#include "display.h"
#include "config.h"
#include "pbr-model.h"
#include <search.h>

/*******************************************************************************
 * Tracing configuration
 ******************************************************************************/

TRACE_TAG(INIT, 1);
TRACE_TAG(INFO, 3);
TRACE_TAG(DEBUG, 6);

/*******************************************************************************
 * Local functions definitions
 ******************************************************************************/

/**> Vertex/fragment shaders implementation */
#include "pbr/pbr-shaders.h"

/*******************************************************************************
 * Shader construction
 ******************************************************************************/

#define SHADER_TAG                      PBR
#define SHADER_VERTEX_SOURCE            primitive_vert
#define SHADER_FRAGMENT_SOURCE          pbr_frag

/* ...shader uniforms */
#define __SHADER_UNIFORMS                       \
    __U(u_ViewProjectionMatrix),                \
    __U(u_ModelMatrix),                         \
    __U(u_NormalMatrix),                        \
    __U(u_MetallicFactor),                      \
    __U(u_RoughnessFactor),                     \
    __U(u_BaseColorFactor),                     \
    __U(u_SpecularFactor),                      \
    __U(u_DiffuseFactor),                       \
    __U(u_GlossinessFactor),                    \
    __U(u_SheenIntensityFactor),                \
    __U(u_SheenColorFactor),                    \
    __U(u_SheenRoughness),                      \
    __U(u_ClearcoatFactor),                     \
    __U(u_ClearcoatRoughnessFactor),            \
    __U(u_MetallicRoughnessSpecularFactor),     \
    __U(u_Anisotropy),                          \
    __U(u_AnisotropyDirection),                 \
    __U(u_SubsurfaceScale),                     \
    __U(u_SubsurfaceDistortion),                \
    __U(u_SubsurfacePower),                     \
    __U(u_SubsurfaceColorFactor),               \
    __U(u_SubsurfaceThicknessFactor),           \
    __U(u_ThinFilmFactor),                      \
    __U(u_ThinFilmThicknessMinimum),            \
    __U(u_ThinFilmThicknessMaximum),            \
    __U(u_IOR_and_f0),                          \
    __U(u_Thickness),                           \
    __U(u_AbsorptionColor),                     \
    __U(u_Transmission),                        \
    __U(u_AlphaCutoff),                         \
    __U(u_Camera),                              \
    __U(u_BaseColorSampler),                    \
    __U(u_DiffuseSampler),                      \
    __U(u_NormalSampler),                       \
    __U(u_NormalScale),                         \
    __U(u_OcclusionSampler),                    \
    __U(u_OcclusionStrength),                   \
    __U(u_MetallicRoughnessSampler),            \
    __U(u_EmissiveSampler),                     \
    __U(u_EmissiveFactor),                      \
    __U(u_Exposure),                            \
    __U(u_MipCount),                            \
    __U(u_GGXLUT),                              \
    __U(u_SphericalHarmonics),                  \
    __U(u_LambertianEnvSampler),                \
    __U(u_GGXEnvSampler),                       \
    __U(u_BaseColorUVTransform),                \
    __U(u_NormalUVTransform),                   \
    __U(u_EmissiveUVTransform),                 \
    __U(u_OcclusionUVTransform)

/* ...shader attributes */
#define __SHADER_ATTRIBUTES                     \
    __A(a_Position),                            \
    __A(a_Normal),                              \
    __A(a_UV1),                                 \
    __A(a_Tangent),                             \
    __A(a_Weight1),                             \
    __A(a_Joint1)

/**> Shader attributes ordinals */
#define __A(id)                 __PBR_SHADER_ATTRIBUTE_##id

enum __pbr_shader_attributes {
    __SHADER_ATTRIBUTES,
    __SHADER_ATTRIBUTES_NUM
};
#undef  __A

/**> Shader uniforms ordinals */
#define __U(id)                 __PBR_SHADER_UNIFORM_##id

enum __pbr_shader_uniforms {
    __SHADER_UNIFORMS,
    __SHADER_UNIFORMS_NUM
};
#undef  __U

/**> Shader attributes literals */
#define __A(id)                 #id
static const char * const __pbr_shader_attributes_id[__SHADER_ATTRIBUTES_NUM + 1] = {
    __SHADER_ATTRIBUTES,
    NULL
};
#undef  __A

/**> Shader uniforms literals */
#define __U(id)                 #id
static const char * const __pbr_shader_uniforms_id[__SHADER_UNIFORMS_NUM + 1] = {
    __SHADER_UNIFORMS,
    NULL
};
#undef  __U

/*******************************************************************************
 * Shader program compilation
 ******************************************************************************/

/* ...additional defines */
#define __SH_DEF(name)                      "#define " #name "\n"
#define __SH_DEFV(name, value)              "#define " #name " " #value "\n"

#define USE_SPECULAR_AA             1
#define USE_CENTROID_FOR_MSAA       1
#define SKIN_JOINTS_COUNT           1

/**> Maximal number of strings in an array */
#define SHADER_MAX_STRINGS_NUM      64

static inline const char ** shader_add_string(const char ***arr, int *num, const char *str)
{
    if (*num < SHADER_MAX_STRINGS_NUM - 1)
    {
        (*num)++;
        *(*arr)++ = str;
        return *arr;
    }
    else
    {
        return NULL;
    }
}

/**
 * @brief   Create PBR shader for specific material type
 *
 * @param   scene[in]       Renedering scene data
 * @param   material[in]    Material descriptor
 * @param   geometry[in]    Primitive geometry descriptor
 * @param   ibl[in]         IBL data
 *
 * @return                  Shader data, or NULL on failure
 */
static shader_data_t * pbr_shader_compile(render_scene_t *scene, pbr_material_t *material, pbr_geometry_t *geometry, ibl_data_t *ibl)
{
    shader_data_t  *shader;
    shader_desc_t   desc;
    const char     *v_src;
    const char     *v_strings[SHADER_MAX_STRINGS_NUM], **v_str = &v_strings[0];
    const char     *f_strings[SHADER_MAX_STRINGS_NUM], **f_str = &f_strings[0];
    int             v_num = 0;
    int             f_num = 0;

    /* ...reset descriptor */
    memset(&desc, 0, sizeof(desc));

    /* ...add GLSL version directive */
    CHK_ERR(shader_add_string(&v_str, &v_num, "#version 320 es\n"), NULL);
    CHK_ERR(shader_add_string(&f_str, &f_num, "#version 320 es\n"), NULL);

    CHK_ERR(shader_add_string(&v_str, &v_num, __SH_DEF(MATERIAL_METALLICROUGHNESS)), NULL);
    CHK_ERR(shader_add_string(&f_str, &f_num, __SH_DEF(MATERIAL_METALLICROUGHNESS)), NULL);

    if (USE_SPECULAR_AA)
    {
        CHK_ERR(shader_add_string(&f_str, &f_num, __SH_DEF(SPECULAR_AA) __SH_DEFV(MAX_SPEC_CUTOFF, 0.6)), NULL);
    }

    if (USE_CENTROID_FOR_MSAA)
    {
        CHK_ERR(shader_add_string(&f_str, &f_num, __SH_DEFV(CENTROID, centroid)), NULL);
    }
    else
    {
        CHK_ERR(shader_add_string(&f_str, &f_num, __SH_DEF(CENTROID)), NULL);
    }

    if (geometry->texcoord1_component_count)
    {
        CHK_ERR(shader_add_string(&v_str, &v_num, __SH_DEF(HAS_UV_SET1)), NULL);
        CHK_ERR(shader_add_string(&f_str, &f_num, __SH_DEF(HAS_UV_SET1)), NULL);
    }

    if (geometry->normal_component_count)
    {
        CHK_ERR(shader_add_string(&v_str, &v_num, __SH_DEF(HAS_NORMALS)), NULL);
        CHK_ERR(shader_add_string(&f_str, &f_num, __SH_DEF(HAS_NORMALS)), NULL);
    }

    if (geometry->tangent_component_count)
    {
        CHK_ERR(shader_add_string(&v_str, &v_num, __SH_DEF(HAS_TANGENTS)), NULL);
        CHK_ERR(shader_add_string(&f_str, &f_num, __SH_DEF(HAS_TANGENTS)), NULL);
    }

    if (geometry->joints_component_count && geometry->joints_component_count && SKIN_JOINTS_COUNT)
    {
        char   *t;

        CHK_ERR(asprintf(&t, __SH_DEFV(JOINT_COUNT, %u), SKIN_JOINTS_COUNT) >= 0, NULL);

        CHK_ERR(shader_add_string(&v_str, &v_num, __SH_DEF(USE_SKINNING) __SH_DEF(HAS_WEIGHT_SET1) __SH_DEF(HAS_JOINT_SET1)), NULL);
        CHK_ERR(shader_add_string(&v_str, &v_num, t), NULL);
    }

    if (material->albedo_tex_channels > 0)
    {
        CHK_ERR(shader_add_string(&v_str, &v_num, __SH_DEF(HAS_BASE_COLOR_MAP)), NULL);
        CHK_ERR(shader_add_string(&f_str, &f_num, __SH_DEF(HAS_BASE_COLOR_MAP)), NULL);

        if (material->with_base_color_uvt)
        {
            CHK_ERR(shader_add_string(&f_str, &f_num, __SH_DEF(HAS_BASECOLOR_UV_TRANSFORM)), NULL);
        }
    }

    if (1 && material->normal_tex_channels > 0)
    {
        CHK_ERR(shader_add_string(&v_str, &v_num, __SH_DEF(HAS_NORMAL_MAP)), NULL);
        CHK_ERR(shader_add_string(&f_str, &f_num, __SH_DEF(HAS_NORMAL_MAP)), NULL);

        if (material->with_normal_uvt)
        {
            CHK_ERR(shader_add_string(&f_str, &f_num, __SH_DEF(HAS_NORMAL_UV_TRANSFORM)), NULL);
        }
    }

    if (material->occlusion_tex_channels > 0)
    {
        CHK_ERR(shader_add_string(&v_str, &v_num, __SH_DEF(HAS_OCCLUSION_MAP)), NULL);
        CHK_ERR(shader_add_string(&f_str, &f_num, __SH_DEF(HAS_OCCLUSION_MAP)), NULL);

        if (material->with_occlusion_uvt)
        {
            CHK_ERR(shader_add_string(&f_str, &f_num, __SH_DEF(HAS_OCCLUSION_UV_TRANSFORM)), NULL);
        }

        if (material->occlusion_tex_channels > 1)
        {
            CHK_ERR(shader_add_string(&v_str, &v_num, __SH_DEF(HAS_METALLIC_ROUGHNESS_MAP)), NULL);
            CHK_ERR(shader_add_string(&f_str, &f_num, __SH_DEF(HAS_METALLIC_ROUGHNESS_MAP)), NULL);
        }
    }

    if (material->emissive_tex_channels > 0)
    {
        CHK_ERR(shader_add_string(&f_str, &f_num, __SH_DEF(HAS_EMISSIVE_MAP)), NULL);

        if (material->with_emissive_uvt)
        {
            CHK_ERR(shader_add_string(&f_str, &f_num, __SH_DEF(HAS_EMISSIVE_UV_TRANSFORM)), NULL);
        }
    }

    if (material->is_unlit != 0)
    {
        CHK_ERR(shader_add_string(&v_str, &v_num, __SH_DEF(MATERIAL_UNLIT)), NULL);
        CHK_ERR(shader_add_string(&f_str, &f_num, __SH_DEF(MATERIAL_UNLIT)), NULL);
    }

    if (material->is_double_sided != 0)
    {
        CHK_ERR(shader_add_string(&f_str, &f_num, __SH_DEF(MATERIAL_DOUBLE_SIDED)), NULL);
    }

    if (material->with_clearcoat != 0)
    {
        CHK_ERR(shader_add_string(&f_str, &f_num, __SH_DEF(MATERIAL_CLEARCOAT)), NULL);
    }

    if (material->with_transmission != 0)
    {
        CHK_ERR(shader_add_string(&f_str, &f_num, __SH_DEF(MATERIAL_TRANSMISSION)), NULL);
    }

    if (scene->lights_num != 0)
    {
        char   *t;

        CHK_ERR(asprintf(&t, __SH_DEFV(LIGHT_COUNT, %u), scene->lights_num) >= 0, NULL);

        CHK_ERR(shader_add_string(&v_str, &v_num, __SH_DEF(USE_PUNCTUAL)), NULL);
        CHK_ERR(shader_add_string(&v_str, &v_num, t), NULL);

        CHK_ERR(shader_add_string(&f_str, &f_num, __SH_DEF(USE_PUNCTUAL)), NULL);
        CHK_ERR(shader_add_string(&f_str, &f_num, t), NULL);
    }

    if (ibl != NULL)
    {
        CHK_ERR(shader_add_string(&v_str, &v_num, __SH_DEF(USE_IBL)), NULL);
        CHK_ERR(shader_add_string(&f_str, &f_num, __SH_DEF(USE_IBL) __SH_DEF(USE_HDR)), NULL);

        if (ibl->bands_count > 0)
        {
            char   *t;

            CHK_ERR(asprintf(&t, __SH_DEFV(SH_IRRADIANCE_BANDS, %u), ibl->bands_count) >= 0, NULL);
            CHK_ERR(shader_add_string(&f_str, &f_num, t), NULL);
        }
    }

    //CHK_ERR(shader_add_string(&f_str, &f_num, __SH_DEF(DEBUG_OUTPUT) __SH_DEF(DEBUG_NORMAL)), NULL);

    CHK_ERR(shader_add_string(&v_str, &v_num, SHADER_VERTEX_SOURCE), NULL);
    CHK_ERR(shader_add_string(&f_str, &f_num, SHADER_FRAGMENT_SOURCE), NULL);

    desc.v_src = (const char * const *)v_strings;
    desc.v_src_num = v_num;

    TRACE(DEBUG, _b("shader v_num: %u"), v_num);
    for (int i = 0; i < v_num - 1; i++)
    {
        TRACE(DEBUG, _b("[%d]: %s"), i, v_strings[i]);
    }

    desc.f_src = (const char * const *)f_strings;
    desc.f_src_num = f_num;

    TRACE(DEBUG, _b("shader f_num: %u"), f_num);
    for (int i = 0; i < f_num - 1; i++)
    {
        TRACE(DEBUG, _b("[%d]: %s"), i, f_strings[i]);
    }

    desc.attr = __pbr_shader_attributes_id;
    desc.attr_num = __SHADER_ATTRIBUTES_NUM;
    desc.uni = __pbr_shader_uniforms_id;
    desc.uni_num = __SHADER_UNIFORMS_NUM;

    static int count;

    /* ...assign shader name - use just an ordinal number */
    asprintf((char **)&desc.name, "pbr-prog-%d.bin", count++);

    /* ...compile shader */
    shader = shader_create(&desc);

    free((char *)desc.name);

    return shader;
}

/**
 * @brief   Materials comparison functor
 *
 * @param   a[in]       First parameter
 * @param   b[in]       Second parameter
 *
 * @return              Comparison result
 */
static inline int pbr_material_compare(const pbr_material_t *a, const pbr_material_t *b)
{
    return memcmp(&a->key, &b->key, sizeof(pbr_material_t) - offset_of(pbr_material_t, key));
}

/**
 * @brief   Geometry comparison functor
 *
 * @param   a[in]       First parameter
 * @param   b[in]       Second parameter
 *
 * @return              Comparison result
 */
static inline int pbr_geometry_compare(const pbr_geometry_t *a, const pbr_geometry_t *b)
{
    return memcmp(a, b, sizeof(pbr_geometry_t));
}

/**
 * @brief   IBL comparison functor
 *
 * @param   a[in]       First parameter
 * @param   b[in]       Second parameter
 *
 * @return              Comparison result
 */
static inline int pbr_ibl_compare(const ibl_data_t *a, const ibl_data_t *b)
{
    if (a == b)     return 0;
    if (!a)         return -1;
    if (!b)         return +1;

    return memcmp(&a->bands_count, &b->bands_count, sizeof(a->bands_count));
}

typedef struct pbr_key
{
    pbr_material_t     *material;
    pbr_geometry_t     *geometry;
    ibl_data_t         *ibl;
    shader_data_t      *shader;

}   pbr_key_t;

/**
 * @brief   Shader comparison functor
 *
 * @param   a[in]       First parameter
 * @param   b[in]       Second parameter
 *
 * @return              Comparison result
 */
static int pbr_shader_compare(const void *a, const void *b)
{
    const pbr_key_t    *A = a, *B = b;
    int                 r;

    if ((r = pbr_geometry_compare(A->geometry, B->geometry)) != 0)  return r;
    if ((r = pbr_material_compare(A->material, B->material)) != 0)  return r;
    if ((r = pbr_ibl_compare(A->ibl, B->ibl)) != 0)                 return r;

    return 0;
}

/**
 * @brief   Get shader for given rendering object; compile as necessary
 *
 * @param   scene[in]       Rendering scene
 * @param   rp[in]          Rendering primitive
 * @param   ibl[in]         IBL data
 *
 * @return                  Shader data, or NULL on failure
 */
static shader_data_t * pbr_get_shader(render_scene_t *scene, render_primitive_t *rp, ibl_data_t *ibl)
{
    static void    *root;
    shader_data_t  *shader = rp->shader;

    if (shader == NULL)
    {
        pbr_key_t  *key, *val;

        CHK_ERR(key = malloc(sizeof(*key)), NULL);
        key->geometry = &rp->geometry;
        key->material = &scene->material[rp->material];
        key->ibl = ibl;
        key->shader = NULL;

        CHK_ERR(val = tsearch(key, &root, pbr_shader_compare), NULL);

        /* ...compile shader if it is a new key */
        if (*(pbr_key_t **)val == key)
        {
            TRACE(DEBUG, _b("material-%d [%p] shader setup"), rp->material, key->material);
            CHK_ERR(key->shader = pbr_shader_compile(scene, key->material, key->geometry, key->ibl), NULL);
            shader = key->shader;
        }
        else
        {
            TRACE(DEBUG, _b("material-%d: reuse shader material %d"), rp->material, (int)((*(pbr_key_t **)val)->material - scene->material));
            shader = (*(pbr_key_t **)val)->shader;
            free(key);
        }

        rp->shader = shader;
    }

    return shader;
}

/*******************************************************************************
 * Scene matrices preparation
 ******************************************************************************/

/**
 * @param   Calculate transformation matrix from PBR xform structure
 *
 * @param   xform[in]       PBR transformation descriptor
 * @param   M[out]          Transformation 4x4 matrix
 */
static void pbr_xform_to_matrix(pbr_xform_t *xform, __mat4x4 M)
{
    TRACE(0, _b("xform: scale=%f,%f,%f, rotation=%f,%f,%f,%f, translation=%f,%f,%f"),
          xform->scale[0], xform->scale[1], xform->scale[2],
          xform->rotation[0], xform->rotation[1], xform->rotation[2], xform->rotation[3],
          xform->translation[0], xform->translation[1], xform->translation[2]);

    __M(4, M, 0, 3) = xform->translation[0];
    __M(4, M, 1, 3) = xform->translation[1];
    __M(4, M, 2, 3) = xform->translation[2];

    float32_t x2 = xform->rotation[0] + xform->rotation[0];
    float32_t y2 = xform->rotation[1] + xform->rotation[1];
    float32_t z2 = xform->rotation[2] + xform->rotation[2];

    float32_t xx2 = xform->rotation[0] * x2;
    float32_t yy2 = xform->rotation[1] * y2;
    float32_t zz2 = xform->rotation[2] * z2;

    __M(4, M, 0, 0) = (1.0f - (yy2 + zz2)) * xform->scale[0];
    __M(4, M, 1, 1) = (1.0f - (xx2 + zz2)) * xform->scale[1];
    __M(4, M, 2, 2) = (1.0f - (xx2 + yy2)) * xform->scale[2];

    float32_t yz2 = xform->rotation[1] * z2;
    float32_t wx2 = xform->rotation[3] * x2;

    __M(4, M, 1, 2) = (yz2 - wx2) * xform->scale[2];
    __M(4, M, 2, 1) = (yz2 + wx2) * xform->scale[1];

    float32_t xy2 = xform->rotation[0] * y2;
    float32_t wz2 = xform->rotation[3] * z2;

    __M(4, M, 0, 1) = (xy2 - wz2) * xform->scale[1];
    __M(4, M, 1, 0) = (xy2 + wz2) * xform->scale[0];

    float32_t xz2 = xform->rotation[0] * z2;
    float32_t wy2 = xform->rotation[3] * y2;

    __M(4, M, 0, 2) = (xz2 + wy2) * xform->scale[2];
    __M(4, M, 2, 0) = (xz2 - wy2) * xform->scale[0];

    __M(4, M, 3, 0) = 0.0f;
    __M(4, M, 3, 1) = 0.0f;
    __M(4, M, 3, 2) = 0.0f;
    __M(4, M, 3, 3) = 1.0f;

    (TRACE_CFG(0) ? __mat4x4_dump(M, "M") : 0);
}

/**
 * @brief   Set scene transformation matrices
 *
 * @param   scene[in]       Rendering scene data
 * @param   rn[in]          Rendering node
 * @param   M[in]           Transformation matrix
 */
void pbr_scene_xform(render_scene_t *scene, render_node_t *rn, GLfloat *M)
{
    render_node_t  *stack[scene->rn_num];
    int             top = 0;
    __mat4x4        t;

    if (rn == scene->root)
    {
        if (M != NULL)
        {
            memcpy(rn->matrix, M, sizeof(GLfloat[16]));
        }
        else
        {
            __mat4x4_identity(rn->matrix);
        }
    }
    else
    {
        /* ...calculate local tranformation matrix */
        pbr_xform_to_matrix(&rn->xform, t);
        __mat4x4_mul(M, t, rn->matrix);
    }

    stack[top++] = rn;

    while (top != 0)
    {
        int     i;

        rn = stack[--top];

        /* ...get global node matrix */
        M = rn->matrix;

        for (i = 0; i < rn->num; i++)
        {
            render_node_t  *child = &scene->rn[rn->nodes[i]];

            /* ...calculate local tranformation matrix */
            pbr_xform_to_matrix(&child->xform, t);

            /* ...set global transformation matrix */
            __mat4x4_mul(M, t, child->matrix);

            /* ...push child into stack */
            stack[top++] = child;
        }
    }
}

/*******************************************************************************
 * Rendering function
 ******************************************************************************/

/**
 * @brief   Bind texture to specified texture unit
 *
 * @param   scene[in]       Scene data
 * @param   id[in]          Texture id
 * @param   u[in]           Sampler uniform
 * @param   unit[in, out]   Active texture unit
 */
static inline void render_bind_tex(render_scene_t *scene, int id, GLuint u, int *unit)
{
    pbr_tex_t      *tex = &scene->tex[id];
    pbr_image_t    *img = &scene->img[tex->image];
    pbr_sampler_t  *smp = (tex->sampler >= 0 ? &scene->smp[tex->sampler] : NULL);

    glActiveTexture(GL_TEXTURE0 + *unit);    GLCHECK();
    glBindTexture(GL_TEXTURE_2D, img->id);  GLCHECK();
    glUniform1iv(u, 1, unit);  GLCHECK();
#if 0
    if (smp != NULL)
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, smp->mag_filter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, smp->min_filter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, smp->wrap_s);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, smp->wrap_t);
    }
    else
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }
#endif
    TRACE(0, _b("bind-tex-%d: image=%d, sampler=%d, id=%u, u=%u, unit=%d"), id, tex->image, tex->sampler, img->id, u, *unit);

    (*unit)++;
}

/**
 * @brief   Bind texture to specified texture unit
 *
 * @param   scene[in]       Scene data
 * @param   id[in]          Texture id
 * @param   u[in]           Sampler uniform
 * @param   unit[in, out]   Active texture unit
 */
static inline void render_bind_tex_ext(GLenum target, GLuint id, GLuint u, int *unit)
{
    glActiveTexture(GL_TEXTURE0 + *unit);    GLCHECK();
    glBindTexture(target, id);  GLCHECK();
    glUniform1iv(u, 1, unit);  GLCHECK();

    (*unit)++;
}

#define U(id)       u[__PBR_SHADER_UNIFORM_##id]
#define A(id)       (__PBR_SHADER_ATTRIBUTE_##id)

/**
 * @brief   Rendering primitive processing
 *
 * @param   scene[in]   Rendering scene data
 * @param   rp[in]      Rendering primitive data
 * @param   pvm[in]     PVM matrix
 * @param   vm[in]      Model VM matrix
 * @param   vmn[in]     Inverse VM matrix
 */
void render_primitive_process(render_scene_t *scene, render_primitive_t *rp, ibl_data_t *ibl, const GLfloat *PV, const GLfloat *M, const GLfloat *N, const GLfloat *T, GLfloat intensity)
{
    pbr_material_t *material = &scene->material[rp->material];
    shader_data_t  *shader = pbr_get_shader(scene, rp, ibl);

    /* ...bail out if shader is not ready */
    if (!shader)    return;

    const GLint    *u = shader_uniforms(shader);
    GLint           program = shader_program(shader);

    TRACE(0, _b("mat-%d: a=%u, n=%u, o=%u, e=%u"), rp->material, material->albedo_tex_channels, material->normal_tex_channels, material->occlusion_tex_channels, material->emissive_tex_channels);

    glUseProgram(program); GLCHECK();

    /* ...bind uniforms; projection matrices and light source specification */
    glUniformMatrix4fv(U(u_ViewProjectionMatrix), 1, GL_FALSE, PV); GLCHECK();
    glUniformMatrix4fv(U(u_ModelMatrix), 1, GL_FALSE, M); GLCHECK();
    glUniformMatrix4fv(U(u_NormalMatrix), 1, GL_FALSE, N);  GLCHECK();
    glUniform3fv(U(u_Camera), 1, T);    GLCHECK();

    if (TRACE_CFG(0))
    {
        __mat4x4_dump(PV, "PV");
        __mat4x4_dump(M, "M");
        __mat3x3_dump(N, "N");
        __vec3_dump(T, "T");
    }

    if (scene->lights_num > 0)
    {
        GLuint  block = glGetUniformBlockIndex(program, "LightBlock");
        glBindBufferBase(GL_UNIFORM_BUFFER, block, scene->lights_ubo);  GLCHECK();
        glUniformBlockBinding(program, block, 0);   GLCHECK();

        for (int i = 0; i < scene->lights_num; i++)
        {
            TRACE(0, _b("light-%d: pos=%f,%f,%f, intensity=%f, range=%f, color=%f,%f,%f"),
                  i, scene->lights[i].position[0], scene->lights[i].position[1], scene->lights[i].position[2],
                  scene->lights[i].intensity, scene->lights[i].range,
                  scene->lights[i].color[0], scene->lights[i].color[1], scene->lights[i].color[2]);
        }
    }

    GLint           texture_unit = 0;

    if (material->albedo_tex_channels != 0)
    {
        TRACE(DEBUG, _b("set albedo-tex: %d"), material->baseColorTexture);

//        render_bind_tex(scene, material->baseColorTexture, U(u_BaseColorSampler), &texture_unit);
        render_bind_tex(scene, material->baseColorTexture, U(u_DiffuseSampler), &texture_unit);

        if (material->with_base_color_uvt)
        {
            glUniformMatrix3fv(U(u_BaseColorUVTransform), 1, 0, material->baseColorTextureUVT);   GLCHECK();
        }
    }

    if (material->normal_tex_channels != 0)
    {
        TRACE(DEBUG, _b("set normal-tex: %d"), material->normalTexture);

        render_bind_tex(scene, material->normalTexture, U(u_NormalSampler), &texture_unit);

        glUniform1fv(U(u_NormalScale), 1, &material->normal_scale); GLCHECK();

        if (material->with_normal_uvt)
        {
            glUniformMatrix3fv(U(u_NormalUVTransform), 1, 0, material->normalTextureUVT);   GLCHECK();
        }
    }

    if (material->occlusion_tex_channels != 0)
    {
        GLfloat     occlusion_strength = 1.0f;  // --tbd - read from GLTF

        TRACE(DEBUG, _b("set occlusion-tex: %d"), material->occlusionTexture);

        render_bind_tex(scene, material->occlusionTexture, U(u_OcclusionSampler), &texture_unit);

        if (material->with_occlusion_uvt)
        {
            glUniformMatrix3fv(U(u_OcclusionUVTransform), 1, 0, material->occlusionTextureUVT);   GLCHECK();
        }

        render_bind_tex(scene, material->occlusionTexture, U(u_MetallicRoughnessSampler), &texture_unit);

        glUniform1f(U(u_OcclusionStrength), occlusion_strength);    GLCHECK();
    }

    if (material->emissive_tex_channels != 0)
    {
        TRACE(DEBUG, _b("set emissive-tex: %d"), material->emissiveTexture);

        render_bind_tex(scene, material->emissiveTexture, U(u_EmissiveSampler), &texture_unit);

        if (material->with_emissive_uvt)
        {
            glUniformMatrix3fv(U(u_EmissiveUVTransform), 1, 0, material->emissiveTextureUVT);   GLCHECK();
        }
    }

    if (material->with_clearcoat != 0)
    {
        glUniform1f(U(u_ClearcoatFactor), material->clearcoatFactor);  GLCHECK();
        glUniform1f(U(u_ClearcoatRoughnessFactor), material->clearcoatRoughnessFactor);  GLCHECK();
    }

    if (material->with_transmission != 0)
    {
        glUniform1f(U(u_Transmission), material->transmissionFactor);  GLCHECK();
    }

    if (material->is_unlit)
    {
        glUniform4fv(U(u_BaseColorFactor), 1, material->baseColorFactor);  GLCHECK();
    }
    else
    {
        glUniform4fv(U(u_BaseColorFactor), 1, material->baseColorFactor);  GLCHECK();
        glUniform1f(U(u_MetallicFactor), material->metallicFactor);  GLCHECK();
        glUniform1f(U(u_RoughnessFactor), material->roughnessFactor);  GLCHECK();
        glUniform1f(U(u_Exposure), scene->exposure);  GLCHECK();
        glUniform3fv(U(u_EmissiveFactor), 1, material->emissiveFactor);  GLCHECK();
    }

    if (ibl != NULL)
    {
        glUniform1i(U(u_MipCount), ibl->mipLevels);  GLCHECK();

        render_bind_tex_ext(GL_TEXTURE_2D, ibl->brdfLUT, U(u_GGXLUT), &texture_unit);

        if (ibl->diffuseIrradiance == 0U)
        {
            if (ibl->sh_irradiance_vec_num == 0)
            {
                glUniformMatrix4fv(U(u_SphericalHarmonics), 1, 0, ibl->sh_irradiance_matrix);   GLCHECK();
            }
            else
            {
                glUniform3fv(U(u_SphericalHarmonics), ibl->sh_irradiance_vec_num, *ibl->sh_irradiance_vec); GLCHECK();
            }
        }
        else
        {
            render_bind_tex_ext(GL_TEXTURE_CUBE_MAP, ibl->diffuseIrradiance, U(u_LambertianEnvSampler), &texture_unit);
        }

        render_bind_tex_ext(GL_TEXTURE_CUBE_MAP, ibl->specular, U(u_GGXEnvSampler), &texture_unit);
    }

    if (!material->is_opaque)
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glDepthMask(GL_FALSE);
    }
    else
    {
        glDisable(GL_BLEND);
        glDepthMask(GL_TRUE);
        glEnable(GL_CULL_FACE);
    }

    if (material->is_double_sided)
    {
        glDisable(GL_CULL_FACE);
    }

    /* ...render Vertex-Array-Object */
    glBindVertexArray(rp->vao);     GLCHECK();

    TRACE(DEBUG, _b("render-ibo: %u points (%u textures)"), rp->size, texture_unit);

    glDrawElements(rp->mode, rp->size, rp->type, (void *)(uintptr_t)rp->offset);    GLCHECK();

    /* ...cleanup after rendering */
    glUseProgram(0);
    glBindVertexArray(0);

    while (texture_unit-- != 0)
    {
        glActiveTexture(GL_TEXTURE0 + texture_unit);
        glBindTexture(GL_TEXTURE_2D, 0);
        glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
    }
}

#undef U
#undef A

/**
 * @brief   Render object processing
 *
 * @param   scene[in]   Rendering scene data
 * @param   ro[in]      Rendering object data
 * @pram    ibl[in]     IBL data
 * @param   pvm[in]     PVM matrix
 * @param   vm[in]      Model VM matrix
 * @param   vmn[in]     Inverse VM matrix
 */
void render_object_process(render_scene_t *scene, render_object_t *ro, ibl_data_t *ibl, const GLfloat *PV, const GLfloat *M, const GLfloat *N, const GLfloat *T, GLfloat intensity)
{
    __mat4x4    m;
    int         i;

    TRACE(DEBUG, _b("process ro-%d: %u primitives"), (int)(ro - scene->ro), ro->num);

    __mat4x4_mul(M, scene->rn[ro->node].matrix, m);

    for (i = 0; i < ro->num; i++)
    {
        render_primitive_process(scene, &ro->prim[i], ibl, PV, m, N, T, intensity);
    }
}

/**
 * @brief   Prepare matrices for rendering operation
 *
 * @param   P[in]           Projection matrix
 * @param   V[in]           View matrix
 * @param   M[in]           Model matrix
 * @param   PV[out]         PV matrix for rendering
 * @param   VM[out]         View-Model matrix
 * @param   N[out]          Normale matrix
 */
static inline void calc_normale_matrix(__mat4x4 M, __mat4x4 N)
{
    __mat3x3    minv;

    /* ...get inverse of major 3x3 minor of M */
    __mat4x4_min3x3_inv(M, minv, NULL);

    __M(4, N, 0, 0) = __M(3, minv, 0, 0);
    __M(4, N, 1, 0) = __M(3, minv, 0, 1);
    __M(4, N, 2, 0) = __M(3, minv, 0, 2);
    __M(4, N, 3, 0) = __MATH_ZERO;

    __M(4, N, 0, 1) = __M(3, minv, 1, 0);
    __M(4, N, 1, 1) = __M(3, minv, 1, 1);
    __M(4, N, 2, 1) = __M(3, minv, 1, 2);
    __M(4, N, 3, 1) = __MATH_ZERO;

    __M(4, N, 0, 2) = __M(3, minv, 2, 0);
    __M(4, N, 1, 2) = __M(3, minv, 2, 1);
    __M(4, N, 2, 2) = __M(3, minv, 2, 2);
    __M(4, N, 3, 2) = __MATH_ZERO;

    __M(4, N, 0, 3) = __MATH_ZERO;
    __M(4, N, 1, 3) = __MATH_ZERO;
    __M(4, N, 2, 3) = __MATH_ZERO;
    __M(4, N, 3, 3) = __MATH_ONE;
}

/**
 * @brief   Render object processing
 *
 * @param   scene[in]   Rendering scene data
 * @param   ro[in]      Rendering object data
 * @param   ibl[in]     IBL data
 * @param   pvm[in]     PVM matrix
 * @param   vm[in]      Model VM matrix
 * @param   vmn[in]     Inverse VM matrix
 */
static void render_object_process_n(render_scene_t *scene, render_object_t *ro, ibl_data_t *ibl, const GLfloat *PV, const GLfloat *T, GLfloat intensity)
{
    __mat4x4    N;
    int         i;

    TRACE(DEBUG, _b("process ro-%d[node: %d]: %u primitives"), (int)(ro - scene->ro), ro->node, ro->num);

    calc_normale_matrix(scene->rn[ro->node].matrix, N);

    for (i = 0; i < ro->num; i++)
    {
        render_primitive_process(scene, &ro->prim[i], ibl, PV, scene->rn[ro->node].matrix, N, T, intensity);
    }
}

/**
 * @brief   Render object processing
 *
 * @param   scene[in]   Rendering scene data
 * @param   rp[in]      Rendering primitive data
 * @param   pvm[in]     PVM matrix
 * @param   vm[in]      Model VM matrix
 * @param   vmn[in]     Inverse VM matrix
 */
void render_node_process(render_scene_t *scene, render_node_t *rn, const GLfloat *PV, const GLfloat *T, GLfloat intensity)
{
    render_node_t  *stack[scene->rn_num];
    int             top = 0;

    /* ...put root node into stack */
    stack[top++] = rn;

    while (top != 0)
    {
        int     i;

        rn = stack[--top];

        TRACE(DEBUG, _b("process rn[%d]"), (rn == scene->root ? -1 : (int)(rn - scene->rn)));

        if (rn->mesh >= 0)
        {
            render_object_process_n(scene, &scene->ro[rn->mesh], rn->ibl, PV, T, intensity);
        }

        for (i = 0; i < rn->num; i++)
        {
            render_node_t  *child = &scene->rn[rn->nodes[i]];

            /* ...skip subtree as needed */
            if (child->skip)        continue;

            /* ...put child into stack */
            stack[top++] = child;
        }
    }
}

/**
 * @brief   Render object processing
 *
 * @param   scene[in]   Rendering scene data
 * @param   rn[in]      Rendering node data
 * @param   cb[in]      Callback function for each node within subtree
 * @param   cdata[in]   Client data
 */
void render_node_iterate(render_scene_t *scene, render_node_t *rn, int (*cb)(void *cdata, render_node_t *rn), void *cdata)
{
    render_node_t  *stack[scene->rn_num];
    int             top = 0;

    /* ...put root node into stack */
    stack[top++] = rn;

    while (top != 0)
    {
        int     i;

        rn = stack[--top];

        TRACE(DEBUG, _b("process rn[%d]"), (rn == scene->root ? -1 : (int)(rn - scene->rn)));

        /* ...invoke callback for a node */
        if (cb(cdata, rn) != 0)
        {
            for (i = 0; i < rn->num; i++)
            {
                render_node_t  *child = &scene->rn[rn->nodes[i]];

                /* ...skip subtree as needed - tbd - think of this */
                if (child->skip)        continue;

                /* ...put child into stack */
                stack[top++] = child;
            }
        }
    }
}

/**
 * @brief   Create PBR shader
 */
void render_create_shader(void)
{
    //BUG(1, _x("shader built: %p"), __model_shader);
}

/**
 * @brief   Shader creation callback
 *
 * @param   cdata[in]       Client data
 * @param   rn[in]          Rendering node
 */
int render_create_shader_cb(void *cdata, render_node_t *rn)
{
    render_scene_t *scene = cdata;

    if (rn->mesh >= 0)
    {
        render_object_t    *ro = &scene->ro[rn->mesh];
        ibl_data_t         *ibl = rn->ibl;
        int                 i;

        for (i = 0; i < ro->num; i++)
        {
            render_primitive_t *rp = &ro->prim[i];
            shader_data_t      *shader;

            if ((shader = pbr_get_shader(scene, rp, ibl)) == NULL)
            {
                TRACE(ERROR, _b("failed to get shader for primitive #%d"), rp->material);
            }
        }
    }

    return 1;
}

/*******************************************************************************
 * Animation processing
 ******************************************************************************/

/**
 * @brief   Find interval in input timestamps array
 */
static inline float32_t interpolate_input(float32_t *input, float32_t t, uint32_t count, uint32_t *idx)
{
    uint32_t    left = 0U, right = count - 1U, mid;
    float32_t   share;

    /* ...search for a leftmost position */
    while ((mid = (left + right) >> 1U) > left)
    {
        if (input[mid] <= t)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }

    /* ...choose the position within interval */
    if (t < input[left])
    {
        share = 0.0f;
    }
    else if (t > input[right])
    {
        share = 1.0f;
    }
    else
    {
        share = (t - input[left]) / (input[right] - input[left]);
    }

    *idx = left;

    return share;
}

/**
 * @brief   Linear interpolation of the output element
 *
 * @param   anim[in]        Animation descriptor
 * @param   rn[in]          Target render node
 * @param   t[in]           Time since animation start
 */
void render_animation_process(pbr_animation_t *anim, render_node_t *rn, float32_t t)
{
    float32_t   share;
    uint32_t    idx;

    /* ...select time instant */
    share = interpolate_input(anim->input, t, anim->count, &idx);

    if (anim->type == 0 || anim->type == 2)
    {
        __vec3 *v = (__vec3 *)anim->output + idx;
        __vec3  d;

        __vec3_sub(v[1], v[0], d);
        __vec3_mac(v[0], d, share, d);

        if (anim->type == 0)
        {
            /* ...set translation vector */
            memcpy(rn->xform.translation, d, sizeof(__vec3));
        }
        else
        {
            /* ...set scale vector */
            memcpy(rn->xform.scale, d, sizeof(__vec3));
        }
    }
    else
    {
        __vec4 *v = (__vec4 *)anim->output + idx;
        __vec4  d;

        __vec4_sub(v[1], v[0], d);
        __vec4_mac(v[0], d, share, d);

        /* ...set rotation quaternion */
        memcpy(rn->xform.rotation, d, sizeof(__vec4));
    }
}
