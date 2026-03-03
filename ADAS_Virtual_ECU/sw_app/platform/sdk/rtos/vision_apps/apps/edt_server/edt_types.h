
/*******************************************************************************
 * edt_types.h
 *
 * Copyright (c) 2022 Cogent Embedded Inc.
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

#ifndef __EDT_TYPES_H
#define __EDT_TYPES_H

/* TODO: Should be defined via cogent_api.h */
typedef enum {
    /**
     * To configure the  ISP to disable any manufacturing test.
     */
    ISP_MANUFACTURING_TEST_NONE,
    /**
     * To configure the ISP for Solid White Color test pattern
       specific manufacturing test.
     */
    ISP_MANUFACTURING_SOLID_WHITE,
    /**
     * To configure the ISP for Solid Black Color test pattern
       specific manufacturing test.
     */
    ISP_MANUFACTURING_SOLID_BLACK,
    /**
     * To configure the ISP for Solid Red Color test pattern
       specific manufacturing test.
     */
    ISP_MANUFACTURING_SOLID_RED,
    /**
     * To configure the ISP for Solid Green Color test pattern
       specific manufacturing test.
     */
    ISP_MANUFACTURING_SOLID_GREEN,
    /**
     * To configure the ISP for Solid Blue Color test pattern
       specific manufacturing test.
     */
    ISP_MANUFACTURING_SOLID_BLUE,
    /**
     * To configure the ISP for 100% Vertical Color Bars test pattern
       specific manufacturing test.
     */
    ISP_MANUFACTURING_COLOR_BAR,
    /**
     * To configure the ISP for Fade−to−Gray Vertical Color Bars test pattern
       specific manufacturing test.
     */
    ISP_MANUFACTURING_COLOR_BAR_GRADIENT,
    /**
     * To configure the ISP for Walking 1s test pattern (12−bit)
       specific manufacturing test.
     */
    ISP_MANUFACTURING_WALKING,
    /**
     * Number of supported manufacturing tests.
     */
    ISP_MANUFACTURING_TEST_NUM
} v3xISP_ManufacturingTestType_t;

#endif /* __EDT_TYPES_H */
