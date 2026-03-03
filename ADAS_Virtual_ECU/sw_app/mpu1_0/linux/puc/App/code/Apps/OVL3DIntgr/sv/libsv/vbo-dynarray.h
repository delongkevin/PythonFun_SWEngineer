/*******************************************************************************
 * vbo-dynarray.h
 *
 * VBO dynamic array support
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

#ifndef __LIBSV_VBO_DYNARRAY_H
#define __LIBSV_VBO_DYNARRAY_H

/*******************************************************************************
 * Types definitions
 ******************************************************************************/

/**
 * @brief   Generic dynamic array
 */
typedef struct vbo_dynarray
{
    /**> Vertex buffer pointer (current) */
    void           *v;

    /**> Total number of available entries in array */
    uint32_t        avail;

    /**> Current (allocated) size of the vertex buffer in entries */
    uint32_t        size;

}   vbo_dynarray_t;

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Initialize dynamic VBO array
 *
 * @param   vbo[in]     VBO dynamic array handle
 * @param   elem[in]    VBO element size
 * @param   size[in]    Initial number of preallocated entries
 *
 * @return              Negative on failure
 */
static inline int vbo_dynarray_init(vbo_dynarray_t *vbo, size_t elem, uint32_t size)
{
    /* ...allocate dynamic array */
    CHK_ERR(vbo->v = malloc(elem * size), -1);

    /* ...set buffer parameters */
    vbo->avail = vbo->size = size;

    return 0;
}

/**
 * @brief   Reserve place for specified number of vertices inside dynamic VBO array
 *
 * @param   vbo[in]         VBO dynamis array
 * @param   elem[in]        VBO element size
 * @param   n[in]           Number of entries to preallocate
 *
 * @return                  Pointer to first allocated entry
 */
static inline void * vbo_dynarray_add(vbo_dynarray_t *vbo, size_t elem, uint32_t n)
{
    void        *p = vbo->v;
    uint32_t     size = vbo->size;
    uint32_t     avail = vbo->avail;

    /* ...check if we have sufficient room in buffer */
    if (avail < n)
    {
        /* ...increase reserved VBO size (exponentially) */
        uint32_t    extra = (n - avail) + (size >> 2);
        uint32_t    busy = size - avail;

        /* ...set new size of the dynamic array */
        size += extra;

        /* ...reallocate buffer */
        if ((p = realloc(p - busy * elem, size * elem)) == NULL)
        {
            TRACE(ERROR, _x("failed to reallocate buffer: size=%u, elem=%u"), size, (uint32_t)elem);
            return NULL;
        }
        else
        {
            /* ...adjust current writing position of the dynamic array */
            p += busy * elem;
        }

        /* ...update VBO size */
        vbo->size = size;

        /* ...adjust amount of available points */
        avail += extra;
    }

    /* ...update buffer cursor within mapped VBO */
    vbo->v = p + n * elem;
    vbo->avail = avail - n;

    /* ...return pointer to first added element */
    return p;
}

/**
 * @brief   Get total number of entries inside VBO
 *
 * @param   vbo[in]         Dynamic VBO array handle
 *
 * @return                  Total number of entries
 */
static inline int vbo_dynarray_num(vbo_dynarray_t *vbo)
{
    return vbo->size - vbo->avail;
}

/**
 * @brief   Get dynamic array buffer pointer
 *
 * @param   vbo[in]         Dynamic VBO array handle
 * @param   elem[in]        VBO element size
 *
 * @return                  Vertex array buffer pointer
 */
static inline void * vbo_dynarray_buffer(vbo_dynarray_t *vbo, size_t elem)
{
    return vbo->v - vbo_dynarray_num(vbo) * elem;
}

/**
 * @brief   Clear dynamic array
 *
 * @param   vbo[in]         Dynamic VBO array handle
 * @param   elem[in]        VBO element size
 */
static inline void vbo_dynarray_clear(vbo_dynarray_t *vbo, size_t elem)
{
    /* ...adjust current pointer */
    vbo->v = vbo_dynarray_buffer(vbo, elem);

    /* ...mark array is empty */
    vbo->avail = vbo->size;
}

/**
 * @brief   Destroy dynamic VBO array
 *
 * @param   vbo[in]     Dynamic VBO array handle
 */
static inline void vbo_dynarray_destroy(vbo_dynarray_t *vbo, size_t elem)
{
    /* ...destroy dynamic vertex array */
    (vbo->v ? free(vbo_dynarray_buffer(vbo, elem)) : 0);
}

#endif  /* __LIBSV_VBO_DYNARRAY_H */
