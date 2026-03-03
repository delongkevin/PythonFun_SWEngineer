/*******************************************************************************
 * config_parser.h
 *
 * Config parser from YAML file
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

#ifndef __CONFIG_PARSER_H
#define __CONFIG_PARSER_H

/*******************************************************************************
 * Includes
 ******************************************************************************/

//#include "math-helpers.h"

/*******************************************************************************
 * Global constants definitions
 ******************************************************************************/

/**> Maximal amount of supported cameras */
#define PBB_MAX_CAMERAS             32

/*******************************************************************************
 * Types definitions
 ******************************************************************************/

/**
 * @brief   Configuration data
 */
typedef struct cfg_data
{
    struct {
        /* ...camera friendly name */
        char       *name;

        /* ...camera identifier */
        char       *id;

        /* ...distortion vector */
        float32_t   distortion[4];
        
        /* ...camera matrix 2*3; row-major order */
        float32_t   intrinsics[2 * 3];

        /* ...camera position in world */
        float32_t   position[3];

        /* ...camera rotation vector in world */
        float32_t   rotation[3];

    }   camera[PBB_MAX_CAMERAS];

}   cfg_data_t;

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Parse configuration file
 *
 * @param   cfg[in]     Configuration data structure
 * @param   fname[in]   Configuration file name
 */
extern int config_parse(cfg_data_t *cfg, char *data, uint32_t sz);

extern int variant_config_parse(cfg_data_t *cfg, unsigned int variant_id, char *fname);


#endif  /* __CONFIG_PARSER_H */
