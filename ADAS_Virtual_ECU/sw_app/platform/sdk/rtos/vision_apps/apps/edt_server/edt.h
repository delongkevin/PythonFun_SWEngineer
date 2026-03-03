
/*******************************************************************************
 * edt.h
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

#ifndef __EDT_API_H
#define __EDT_API_H

#include <../can-gw/diag_stellantis_camera_mapping.h>

#define EDT_RPMSG_ENDPOINT 30
#define INIT_MSG_MAGIC     0xAA
#define INIT_MSG_LEN       1

enum {
    CMD_NULL,
    CMD_CAM,
    CMD_MAX,
};

enum TPG_ID {
    TPG_NONE,
    TPG_VERT_COL_BAR = 2,
    TPG_VERT_COL_BAR_FADE,
    TPG_SOLID_BLACK,
    TPG_SOLID_WHITE,
    TPG_SOLID_RED,
    TPG_SOLID_GREEN,
    TPG_SOLID_BLUE,
};

typedef struct edt_rpmsg_cmd_octo
{
    uint8_t cam_id;
    uint8_t cam_tpg;
    uint8_t cam_retent;
}   __attribute__((packed)) edt_rpmsg_cmd_cam_t;

typedef struct edt_rpmsg
{
    uint8_t cmd;

    union {
        edt_rpmsg_cmd_cam_t cam_cmd;
    };
}   __attribute__((packed)) edt_rpmsg_t;

#endif
