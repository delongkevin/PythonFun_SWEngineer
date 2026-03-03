/*******************************************************************************
 * pbr-model.cpp
 *
 * PBR model definitions
 *
 * Copyright (c) 2021 Cogent Embedded Inc.
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

#ifndef __LIBMODEL_PBR_MODEL_H
#define __LIBMODEL_PBR_MODEL_H

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "math-helpers.h"

/*******************************************************************************
 * Types definitions
 ******************************************************************************/

/**
 * @brief   PBR material descriptor
 */
typedef struct pbr_material
{
    GLfloat         baseColorFactor[4];
    GLfloat         emissiveFactor[3];
    GLfloat         metallicFactor;
    GLfloat         roughnessFactor;
    GLfloat         clearcoatFactor;
    GLfloat         clearcoatRoughnessFactor;
    GLfloat         transmissionFactor;

    int             baseColorTexture;
    __mat3x3        baseColorTextureUVT;

    int             normalTexture;
    GLfloat         normal_scale;
    __mat3x3        normalTextureUVT;

    int             occlusionTexture;
    __mat3x3        occlusionTextureUVT;

    int             emissiveTexture;
    __mat3x3        emissiveTextureUVT;

    int             metallicRoughnessTexture;

    union
    {
        struct
        {
            int             is_opaque;
            int             is_double_sided;
            int             is_unlit;

            int             with_clearcoat;
            int             with_mipmaps;
            int             with_transmission;

            int             albedo_tex_channels;
            int             normal_tex_channels;
            int             occlusion_tex_channels;
            int             emissive_tex_channels;

            int             with_base_color_uvt;
            int             with_normal_uvt;
            int             with_occlusion_uvt;
            int             with_emissive_uvt;
        };

        int                 key;
    };

}   pbr_material_t;

/**
 * @brief   Rendering primitive geometry
 */
typedef struct pbr_geometry
{
    int             texcoord1_component_count;
    int             normal_component_count;
    int             tangent_component_count;
    int             joints_component_count;
    int             weights_component_count;

}   pbr_geometry_t;

/**
 * @brief   Image data
 */
typedef struct pbr_image
{
    /**> Texture GL id */
    GLuint          id;

    /**> Components count */
    int32_t         component;

    /**> Dimensions */
    int32_t         width, height;

    /**> Pixel-type */
    int32_t         pixel_type;

    /**> Size? - tbd */

}   pbr_image_t;

/**
 * @brief   Sampler data
 */
typedef struct pbr_sampler
{
    /**> Minimization filter */
    int32_t         min_filter;

    /**> Magnification filter */
    int32_t         mag_filter;

    /**> Wrap-S parameter */
    int32_t         wrap_s;

    /**> Wrap-T parameter */
    int32_t         wrap_t;

}   pbr_sampler_t;

/**
 * @brief   Texture data
 */
typedef struct pbr_tex
{
    /**> Index of the image */
    int32_t         image;

    /**> Index of the samples */
    int32_t         sampler;

}   pbr_tex_t;

/**
 * @brief   Light source data
 */
typedef struct pbr_light
{
    /**> Light direction */
    GLfloat         direction[3];

    /**> Effective range */
    GLfloat         range;

    /**> Light color */
    GLfloat         color[3];

    /**> Light intensity */
    GLfloat         intensity;

    /**> Light source position */
    GLfloat         position[3];

    /**> Inner cone cosine value */
    GLfloat         innerConeCos;

    /**> Outer cone cosine value */
    GLfloat         outerConeCos;

    /**> Type of the source */
    GLint           type;

    /**> Extra padding */
    GLfloat         padding[2];

}   pbr_light_t;

/**
 * @brief   Animation data
 */
typedef struct pbr_animation
{
    /**> Animation type */
    int             type;

    /**> Target node */
    int             node;

    /**> Number of steps in input array */
    int             count;

    /**> Array of input parameters (time) */
    float32_t      *input;

    /**> Array of output parameters (vec3/vec4) */
    void           *output;

}   pbr_animation_t;

/**
 * @brief   Image-based lighting data
 */
typedef struct ibl_data
{
    int             mipLevels;
    GLuint          brdfLUT;
    GLuint          diffuseIrradiance;
    GLuint          specular;
    int             bands_count;
    GLfloat         sh_irradiance_matrix[4 * 4];
    GLfloat       (*sh_irradiance_vec)[3];
    int             sh_irradiance_vec_num;

}   ibl_data_t;

/**
 * @brief   Rendering primitive data
 */
typedef struct render_primitive
{
    /**> Vertex-array object */
    GLuint              vao;

    /**> Primitive mode */
    GLenum              mode;

    /**> Primitive IBO size */
    GLsizei             size;

    /**> Primitive element type */
    GLenum              type;

    /**> Offset to a IBO */
    GLsizei             offset;

    /**> Index of the material */
    int                 material;

    /**> Primitive geometry info */
    pbr_geometry_t      geometry;

    /**> Shader reference */
    shader_data_t      *shader;

}   render_primitive_t;

/**
 * @brief   Render object data
 */
typedef struct render_object
{
    /**> Index of the associated rendering node */
    int                 node;

    /**> Object dimensions */
    float32_t           dim[2][3];

    /**> Number of primitives */
    uint32_t            num;

    /**> Render primitives array */
    render_primitive_t *prim;

}   render_object_t;

/**
 * @brief   Node transformation parameters
 */
typedef struct pbr_xform
{
    /**> Local translation parameters */
    float32_t       translation[3];
    float32_t       rotation[4];
    float32_t       scale[3];

}   pbr_xform_t;

/**
 * @brief   Rendering scene node
 */
typedef struct render_node
{
    /**> Local node transformation parameters */
    pbr_xform_t     xform;

    /**> Global node transformation matrix */
    GLfloat         matrix[16];

    /**> IBL data for a subhierarchy */
    ibl_data_t     *ibl;

    /**> Render node skip flag */
    int             skip;

    /**> Index of render-object (if there is one) */
    int             mesh;

    /**> Parent node index */
    int             parent;

    /**> Number of children */
    int             num;

    /**> Array of child nodes indices */
    int            *nodes;

}   render_node_t;

/**
 * @brief   Rendering scene data
 */
typedef struct render_scene
{
    /**> Number of VBO/IBO objects */
    int32_t             vbo_num;

    /**> VBO/IBO arrays */
    GLuint             *vbo;

    /**> Number of images */
    int                 img_num;

    /**> Images array */
    pbr_image_t        *img;

    /**> Number of samplers */
    int                 smp_num;

    /**> Samplers array */
    pbr_sampler_t      *smp;

    /**> Number of textures */
    int                 tex_num;

    /**> Textures array */
    pbr_tex_t          *tex;

    /**> Number of materials */
    int                 material_num;

    /**> Materials array */
    pbr_material_t     *material;

    /**> Number of render-objects */
    int32_t             ro_num;

    /**> Render-objects array */
    render_object_t    *ro;

    /**> Number of light sources */
    int32_t             lights_num;

    /**> Light sources */
    pbr_light_t        *lights;

    /**> Light sources uniforms block array */
    GLuint              lights_ubo;

    /**> Scene exposure */
    GLfloat             exposure;

    /**> Number of render nodes */
    int                 rn_num;

    /**> Array of render nodes */
    render_node_t      *rn;

    /**> Root node */
    render_node_t      *root;

    /**> Animations number */
    int                 anim_num;

    /**> Animations array */
    pbr_animation_t    *anim;

}   render_scene_t;

/**
 * @brief   Scene loading callback
 */
typedef struct render_load_cb
{
    /**
     * @brief   Render object loading callback
     *
     * @param   cdata[in]       Client data
     * @param   rn[in]          Render node handle
     * @param   name[in]        Render node name
     *
     * @param                   Return non-zero if render-node is to be processed
     */
    int   (*load)(void *cdata, render_node_t *rn, const char *name);

    /**
     * @brief   Animation object loading callback
     *
     * @param   cdata[in]       Client data
     * @param   anim[in]        Animation descriptor
     * @param   name[in]        Animation name
     *
     * @param                   Return non-zero if animation is to be processed
     */
    int   (*anim)(void *cdata, pbr_animation_t *anim, const char *name);

    /**
     * @brief   Render scene saving callback
     *
     * @param   cdata[in]       Client data
     * @param   scene[in]       Scene data
     * @param   f[in]           File handle
     *
     * @return                  Negative on failure
     */
    int   (*save)(void *cdata, render_scene_t *scene, FILE *f);

}   render_load_cb_t;

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Render object loading callback
 *
 * @param   cdata[in]       Client data
 * @param   ro[in]          Render object handle
 * @param   name[in]        Render object name
 *
 * @param                   Return non-zero if render-object is to be loaded
 */
typedef int render_bin_load_cb(void *cdata, render_scene_t *scene, FILE *f);

/**
 * @brief   Load rendering scene from GLTF file
 *
 * @param   fname[in]       File name
 * @param   cb[in]          Render object loading callback
 * @param   cdata[in]       Client data
 *
 * @return                  Rendering scene handle, or NULL on failure
 */
extern render_scene_t * gltf_load(const char *fname, render_load_cb_t *cb, void *cdata);

/**
 * @brief   Save car model into file
 *
 * @param   car[in]         Car model data
 * @param   fname[in]       File name
 *
 * @return                  Rendering scene handle
 */
extern render_scene_t * pbr_model_load(const char *fname, render_bin_load_cb cb, void *cdata);

/**
 * @brief   Load IBL configuration from file
 *
 * @param   cfg[in]         IBL configuration data
 *
 * @return                  IBL data handle, or NULL on failure
 */
extern ibl_data_t * ibl_load(cfg_ibl_t *cfg);

/**
 * @brief   Set scene transformation matrices
 *
 * @param   scene[in]       Rendering scene data
 * @param   rn[in]          Rendering node
 * @param   M[in]           Transformation matrix
 */
extern void pbr_scene_xform(render_scene_t *scene, render_node_t *rn, GLfloat *M);

/**
 * @brief   Render object processing
 *
 * @param   scene[in]   Rendering scene data
 * @param   rp[in]      Rendering primitive data
 * @param   pvm[in]     PVM matrix
 * @param   vm[in]      Model VM matrix
 * @param   vmn[in]     Inverse VM matrix
 */
extern void render_object_process(render_scene_t *scene, render_object_t *ro, ibl_data_t *ibl, const GLfloat *PV, const GLfloat *M, const GLfloat *N, const GLfloat *T, GLfloat intensity);

/**
 * @brief   Render object processing
 *
 * @param   scene[in]   Rendering scene data
 * @param   rp[in]      Rendering primitive data
 * @param   pvm[in]     PVM matrix
 * @param   vm[in]      Model VM matrix
 * @param   vmn[in]     Inverse VM matrix
 */
extern void render_node_process(render_scene_t *scene, render_node_t *rn, const GLfloat *PV, const GLfloat *T, GLfloat intensity);

/**
 * @brief   Render object processing
 *
 * @param   scene[in]   Rendering scene data
 * @param   rn[in]      Rendering node data
 * @param   cb[in]      Callback function for each node within subtree
 * @param   cdata[in]   Client data
 */
extern void render_node_iterate(render_scene_t *scene, render_node_t *rn, int (*cb)(void *cdata, render_node_t *rn), void *cdata);

/**
 * @brief   Shader creation callback
 *
 * @param   cdata[in]       Client data
 * @param   rn[in]          Rendering node
 */
extern int render_create_shader_cb(void *cdata, render_node_t *rn);

/**
 * @brief   Linear interpolation of the output element
 *
 * @param   anim[in]        Animation descriptor
 * @param   rn[in]          Target render node
 * @param   t[in]           Time since animation start
 */
extern void render_animation_process(pbr_animation_t *anim, render_node_t *rn, float32_t t);

#endif  /* __LIBMODEL_PBR_MODEL_H */
