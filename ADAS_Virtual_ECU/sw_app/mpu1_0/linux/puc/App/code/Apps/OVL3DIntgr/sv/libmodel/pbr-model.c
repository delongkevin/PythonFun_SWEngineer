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

#define MODULE_TAG                      GLB

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "common.h"
#include "config.h"
#include "display.h"
#include "pbr-model.h"
#include "../src/util.h"

/*******************************************************************************
 * Tracing configuration
 ******************************************************************************/

TRACE_TAG(INIT, 1);
TRACE_TAG(INFO, 3);
TRACE_TAG(DEBUG, 6);

/*******************************************************************************
 * Local functions implementation
 ******************************************************************************/

/**
 * @brief   Read data into buffer; reallocate as needed
 */
static inline int pbr_read(size_t size, void **buffer, size_t *alloc, FILE *f)
{
    void   *dst = *buffer;

    if (*alloc < size)
    {
        (dst ? free(dst) : 0);

        CHK_ERR(*buffer = dst = malloc(*alloc = size), -1);
    }

    if (size > 0)
    {
        CHK_ERR(fread(dst, size, 1, f) == 1, -1);
    }

    return 0;
}

/**
 * @brief   Load attribute parameters
 */
static int pbr_load_attribute(render_scene_t *scene, FILE *f)
{
    GLuint      attr;
    int         buffer;
    GLenum      type;
    GLsizei     stride;
    GLboolean   normalized;
    size_t      byteOffset;
    int         size;
    GLenum      error;

    CHK_ERR(fread(&attr, sizeof(attr), 1, f) == 1, -1);
    CHK_ERR(fread(&buffer, sizeof(buffer), 1, f) == 1, -1);
    CHK_ERR(fread(&type, sizeof(type), 1, f) == 1, -1);
    CHK_ERR(fread(&stride, sizeof(stride), 1, f) == 1, -1);
    CHK_ERR(fread(&normalized, sizeof(normalized), 1, f) == 1, -1);
    CHK_ERR(fread(&byteOffset, sizeof(byteOffset), 1, f) == 1, -1);
    CHK_ERR(fread(&size, sizeof(size), 1, f) == 1, -1);

    TRACE(0, _b("attr-%d: b=%d, t=%d, s=%d, n=%d, o=%ld, size=%d"), attr, buffer, type, stride, normalized, byteOffset, size);

    glBindBuffer(GL_ARRAY_BUFFER, scene->vbo[buffer]);     GLCHECK();
    glVertexAttribPointer(attr, size, type, normalized, stride, (void *)(uintptr_t)byteOffset);
    glEnableVertexAttribArray(attr);
    if ((error = glGetError()) != GL_NO_ERROR)
    {
        TRACE(ERROR, _x("failed to enable attribute-%d: %X"), attr, error);
        return -(errno = EBADF);
    }

    return 0;
}

/**
 * @brief   Load PBR scene from file
 *
 * @param   scene[in]       Scene data
 * @param   f[in]           File descriptor
 *
 * @return                  Negative on failure
 */
static int pbr_scene_load(render_scene_t *scene, FILE *f)
{
    void       *buffer = NULL;
    size_t      alloc = 0;
    void      **bufs = NULL;
    int         bufs_num;
    GLenum      error;
    int         i;

    /* ...get total number of buffers */
    CHK_ERR(fread(&bufs_num, sizeof(bufs_num), 1, f) == 1, -1);

    if (bufs_num != 0)
    {
        CHK_ERR(bufs = calloc(bufs_num, sizeof(*bufs)), -1);
    }

    for (i = 0; i < bufs_num; i++)
    {
        size_t  size;

        CHK_ERR(fread(&size, sizeof(size), 1, f) == 1, -1);
        if (size != 0)
        {
            CHK_ERR(bufs[i] = malloc(size), -1);
            CHK_ERR(fread(bufs[i], size, 1, f) == 1, -1);
        }
    }

    /* ...allocate 1MB scratch buffer */
    CHK_ERR(buffer = malloc(alloc = 1 << 20), -1);

 	/* ...get total number of buffers */
    CHK_ERR(fread(&scene->vbo_num, sizeof(scene->vbo_num), 1, f) == 1, -1);

    if (scene->vbo_num != 0)
    {
        CHK_ERR(scene->vbo = calloc(scene->vbo_num, sizeof(*scene->vbo)), -1);
    }

    for (i = 0; i < scene->vbo_num; i++)
    {
        int     buffer;
        int     target;
        size_t  byteLength;
        size_t  byteOffset;
        size_t  byteStride;

        CHK_ERR(fread(&buffer, sizeof(int), 1, f) == 1, -1);
        CHK_ERR(fread(&target, sizeof(int), 1, f) == 1, -1);
        CHK_ERR(fread(&byteLength, sizeof(size_t), 1, f) == 1, -1);
        CHK_ERR(fread(&byteOffset, sizeof(size_t), 1, f) == 1, -1);
        CHK_ERR(fread(&byteStride, sizeof(size_t), 1, f) == 1, -1);

        if (target == 0)    continue;

        glGenBuffers(1, &scene->vbo[i]);    GLCHECK();
        glBindBuffer(target, scene->vbo[i]);    GLCHECK();
        glBufferData(target, byteLength, bufs[buffer] + byteOffset, GL_STATIC_DRAW);
        if ((error = glGetError()) != GL_NO_ERROR)
        {
            TRACE(ERROR, _x("failed to create buffer-%d: size=%lu"), i, byteLength);
            return -(errno = ENOMEM);
        }

        glBindBuffer(target, 0);
    }

    /* ...load all images */
    CHK_ERR(fread(&scene->img_num, sizeof(scene->img_num), 1, f) == 1, -1);

    if (scene->img_num != 0)
    {
        CHK_ERR(scene->img = calloc(scene->img_num, sizeof(*scene->img)), -1);
    }

    for (i = 0; i < scene->img_num; i++)
    {
        pbr_image_t    *img = &scene->img[i];
        int             buf;
        size_t          size, offset, stride;
        void           *data;
        char            mime[16];

        CHK_ERR(fread(mime, sizeof(mime), 1, f) == 1, -1);
        CHK_ERR(fread(&img->component, sizeof(img->component), 1, f) == 1, -1);
        CHK_ERR(fread(&img->width, sizeof(img->width), 1, f) == 1, -1);
        CHK_ERR(fread(&img->height, sizeof(img->height), 1, f) == 1, -1);
        CHK_ERR(fread(&img->pixel_type, sizeof(img->pixel_type), 1, f) == 1, -1);
        CHK_ERR(fread(&buf, sizeof(int), 1, f) == 1, -1);

        if (buf < 0)
        {
            /* ...load external image */
            CHK_ERR(fread(&size, sizeof(size_t), 1, f) == 1, -1);
            CHK_API(pbr_read(size, &buffer, &alloc, f));

            /* ...external image is raw */
            data = buffer;
        }
        else
        {
            CHK_ERR(fread(&size, sizeof(size_t), 1, f) == 1, -1);
            CHK_ERR(fread(&offset, sizeof(size_t), 1, f) == 1, -1);
            CHK_ERR(fread(&stride, sizeof(size_t), 1, f) == 1, -1);

            data = bufs[buf] + offset;
        }

        int     width, height;

        if (tex_upload_from_mem(mime, data, size, &img->id, &width, &height) != 0)
        {
            TRACE(ERROR, _x("failed to upload image-%d"), i);
            return -1;
        }
        else
        {
            TRACE(INFO, _b("img-%d loaded: %u*%u, mime: %s"), i, width, height, mime);
        }

        if ((error = glGetError()) != GL_NO_ERROR)
        {
            TRACE(ERROR, _x("failed to create texture %d*%d:%d: %X"), img->width, img->height, img->pixel_type, error);
            return -(errno = ENOMEM);
        }
    }

    /* ...no need in raw buffers since now */
    for (i = 0; i < bufs_num; i++)
    {
        (bufs[i] != NULL ? free(bufs[i]) : 0);
    }

    (bufs != NULL ? free(bufs) : 0);

    /* ...load all samplers */
    CHK_ERR(fread(&scene->smp_num, sizeof(scene->smp_num), 1, f) == 1, -1);

    if (scene->smp_num != 0)
    {
        CHK_ERR(scene->smp = calloc(scene->smp_num, sizeof(*scene->smp)), -1);
    }

    for (i = 0; i < scene->smp_num; i++)
    {
        pbr_sampler_t  *smp = &scene->smp[i];

        CHK_ERR(fread(smp, sizeof(*smp), 1, f) == 1, -1);
    }

    /* ...load all textures */
    CHK_ERR(fread(&scene->tex_num, sizeof(scene->tex_num), 1, f) == 1, -1);

    if (scene->tex_num != 0)
    {
        CHK_ERR(scene->tex = calloc(scene->tex_num, sizeof(*scene->tex)), -1);
    }

    for (i = 0; i < scene->tex_num; i++)
    {
        pbr_tex_t   *tex = &scene->tex[i];

        CHK_ERR(fread(tex, sizeof(*tex), 1, f) == 1, -1);
    }

    /* ...load all materials */
    CHK_ERR(fread(&scene->material_num, sizeof(scene->material_num), 1, f) == 1, -1);

    /* ...allocate storage for all materials including default one */
    CHK_ERR(scene->material = calloc(scene->material_num + 1, sizeof(*scene->material)), -1);

    /* ...default material is indexed with -1 */
    scene->material++;

    for (i = -1; i < scene->material_num; i++)
    {
        pbr_material_t     *material = &scene->material[i];

        CHK_ERR(fread(material, sizeof(*material), 1, f) == 1, -1);
    }

    /* ...load all render-objects */
    CHK_ERR(fread(&scene->ro_num, sizeof(scene->ro_num), 1, f) == 1, -1);

    if (scene->ro_num != 0)
    {
        CHK_ERR(scene->ro = calloc(scene->ro_num, sizeof(*scene->ro)), -1);
    }

    for (i = 0; i < scene->ro_num; i++)
    {
        render_object_t    *ro = &scene->ro[i];
        int                 k;

        CHK_ERR(fread(&ro->node, sizeof(ro->node), 1, f) == 1, -1);
        CHK_ERR(fread(ro->dim, sizeof(ro->dim), 1, f) == 1, -1);
        CHK_ERR(fread(&ro->num, sizeof(ro->num), 1, f) == 1, -1);

        if (ro->num > 0)
        {
            CHK_ERR(ro->prim = calloc(ro->num, sizeof(*ro->prim)), -1);
        }

        for (k = 0; k < ro->num; k++)
        {
            render_primitive_t  *rp = &ro->prim[k];

            CHK_ERR(fread(&rp->mode, sizeof(rp->mode), 1, f) == 1, -1);
            CHK_ERR(fread(&rp->size, sizeof(rp->size), 1, f) == 1, -1);
            CHK_ERR(fread(&rp->type, sizeof(rp->type), 1, f) == 1, -1);
            CHK_ERR(fread(&rp->offset, sizeof(rp->offset), 1, f) == 1, -1);
            CHK_ERR(fread(&rp->material, sizeof(rp->material), 1, f) == 1, -1);
            CHK_ERR(fread(&rp->geometry, sizeof(rp->geometry), 1, f) == 1, -1);

            glGenVertexArrays(1, &rp->vao);     GLCHECK();
            glBindVertexArray(rp->vao);     GLCHECK();

            uint32_t    attr_num;
            int         a;

            CHK_ERR(fread(&attr_num, sizeof(attr_num), 1, f) == 1, -1);

            for (a = 0; a < attr_num; a++)
            {
                CHK_API(pbr_load_attribute(scene, f));
            }

            int     bufferView;
            CHK_ERR(fread(&bufferView, sizeof(bufferView), 1, f) == 1, -1);

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, scene->vbo[bufferView]);  GLCHECK();

            glBindVertexArray(0);
        }
    }

    /* ...load all lights */
    CHK_ERR(fread(&scene->lights_num, sizeof(scene->lights_num), 1, f) == 1, -1);

    if (scene->lights_num != 0)
    {
        CHK_ERR(scene->lights = calloc(scene->lights_num, sizeof(*scene->lights)), -1);
    }

    for (i = 0; i < scene->lights_num; i++)
    {
        pbr_light_t    *light = &scene->lights[i];

        CHK_ERR(fread(light, sizeof(*light), 1, f) == 1, -1);
    }

    glGenBuffers(1, &scene->lights_ubo);    GLCHECK();
    glBindBuffer(GL_UNIFORM_BUFFER, scene->lights_ubo); GLCHECK();
    glBufferData(GL_UNIFORM_BUFFER, scene->lights_num * sizeof(*scene->lights), scene->lights, GL_STATIC_DRAW);    GLCHECK();

    /* ...load all animations */
    CHK_ERR(fread(&scene->anim_num, sizeof(scene->anim_num), 1, f) == 1, -1);

    if (scene->anim_num != 0)
    {
        CHK_ERR(scene->anim = calloc(scene->anim_num, sizeof(*scene->anim)), -1);
    }

    for (i = 0; i < scene->anim_num; i++)
    {
        pbr_animation_t    *anim = &scene->anim[i];

        CHK_ERR(fread(&anim->type, sizeof(anim->type), 1, f) == 1, -1);
        CHK_ERR(fread(&anim->node, sizeof(anim->node), 1, f) == 1, -1);
        CHK_ERR(fread(&anim->count, sizeof(anim->count), 1, f) == 1, -1);

        if (anim->count != 0)
        {
            CHK_ERR(anim->input = malloc(anim->count * sizeof(float32_t)), -1);
            CHK_ERR(fread(anim->input, anim->count * sizeof(float32_t), 1, f) == 1, -1);

            size_t  elem_size = (anim->type == 0 || anim->type == 2 ? 3 : 4) * sizeof(float32_t);

            CHK_ERR(anim->output = malloc(anim->count * elem_size), -1);
            CHK_ERR(fread(anim->output, anim->count * elem_size, 1, f) == 1, -1);
        }
    }

    /* ...load all render nodes */
    CHK_ERR(fread(&scene->rn_num, sizeof(scene->rn_num), 1, f) == 1, -1);
    CHK_ERR(scene->rn = calloc(scene->rn_num + 1, sizeof(*scene->rn)), -1);
    scene->root = &scene->rn[scene->rn_num];

    for (i = 0; i < scene->rn_num + 1; i++)
    {
        render_node_t      *rn = &scene->rn[i];

        CHK_ERR(fread(&rn->xform, sizeof(rn->xform), 1, f) == 1, -1);
        CHK_ERR(fread(&rn->mesh, sizeof(rn->mesh), 1, f) == 1, -1);
        CHK_ERR(fread(&rn->parent, sizeof(rn->mesh), 1, f) == 1, -1);
        CHK_ERR(fread(&rn->num, sizeof(rn->num), 1, f) == 1, -1);

        if (rn->num != 0)
        {
            CHK_ERR(rn->nodes = malloc(rn->num * sizeof(*rn->nodes)), -1);
            CHK_ERR(fread(rn->nodes, rn->num * sizeof(*rn->nodes), 1, f) == 1, -1);
        }
    }

    /* ...release interim buffer */
    (buffer != NULL ? free(buffer) : 0);

    return 0;
}

/**
 * @brief   Save car model into file
 *
 * @param   car[in]         Car model data
 * @param   fname[in]       File name
 *
 * @return                  Rendering scene handle
 */
render_scene_t * pbr_model_load(const char *fname, render_bin_load_cb cb, void *cdata)
{
    render_scene_t     *scene;
    FILE               *f;

    CHK_ERR(f = fopen(fname, "rb"), NULL);

    CHK_ERR(scene = calloc(1, sizeof(*scene)), NULL);

    CHK_ERR(pbr_scene_load(scene, f) == 0, NULL);

    if (cb)
    {
        CHK_ERR(cb(cdata, scene, f) >= 0, NULL);
    }

    fclose(f);

    TRACE(INIT, _b("PBR model loaded from '%s'"), fname);

    return scene;
}

