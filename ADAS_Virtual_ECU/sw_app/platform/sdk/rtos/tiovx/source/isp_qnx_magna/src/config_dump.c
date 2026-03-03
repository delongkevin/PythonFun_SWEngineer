/*******************************************************************************
 * dump.c
 *
 * Dump of ISP controls values for Cogent ISP framework.
 *
 * Copyright (c) 2015-2019 Cogent Embedded Inc.
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "config_dump.h"

/* #define printf_cfg(...) { VX_PRINT(VX_ZONE_WARNING, __VA_ARGS__);} */
#define printf_cfg(...) { ;}

void drvISP_Nsf4v_Config_dump(const char* name, const Nsf4v_Config* data)
{
    uint32_t i = 0;
    uint32_t j = 0;

    printf_cfg("EXPORT_CFG%sEXPORT_CFGlsccCfg.enable = %d\n", name, data->lsccCfg.enable);
    printf_cfg("EXPORT_CFG%sEXPORT_CFGlsccCfg.setSel = %d\n", name, data->lsccCfg.setSel);
    printf_cfg("EXPORT_CFG%sEXPORT_CFGlsccCfg.gMaxCfg = %d\n", name, data->lsccCfg.gMaxCfg);
    printf_cfg("EXPORT_CFG%sEXPORT_CFGlsccCfg.tCfg = %d\n", name, data->lsccCfg.tCfg);
    printf_cfg("EXPORT_CFG%sEXPORT_CFGlsccCfg.kvCfg = %d\n", name, data->lsccCfg.kvCfg);
    printf_cfg("EXPORT_CFG%sEXPORT_CFGlsccCfg.khCfg = %d\n", name, data->lsccCfg.khCfg);
    printf_cfg("EXPORT_CFG%sEXPORT_CFGlsccCfg.lensCenterX = %d\n", name, data->lsccCfg.lensCenterX);
    printf_cfg("EXPORT_CFG%sEXPORT_CFGlsccCfg.lensCenterY = %d\n", name, data->lsccCfg.lensCenterY);

    /**< (S14) Horizontal (Y) position of lens center
         Refer to Spec for more information */
    for(i = 0; i < NSF4_LSCC_MAX_SET; i++)
    {
        for(j = 0; j < NSF4_LSCC_MAX_SEGMENT; j++)
        {
            printf_cfg("EXPORT_CFG%sEXPORT_CFGlsccCfg.pwlCurve[%d][%d].posX = %d\n", name, i, j, data->lsccCfg.pwlCurve[i][j].posX);
            printf_cfg("EXPORT_CFG%sEXPORT_CFGlsccCfg.pwlCurve[%d][%d].posY = %d\n", name, i, j, data->lsccCfg.pwlCurve[i][j].posY);
            printf_cfg("EXPORT_CFG%sEXPORT_CFGlsccCfg.pwlCurve[%d][%d].slope = %d\n", name, i, j, data->lsccCfg.pwlCurve[i][j].slope);
        }
    }
    /**< Lens Shading Correction compansation configuration */

    printf_cfg("EXPORT_CFG%sEXPORT_CFGmode = %d\n", name, data->mode);
    /**< Noise filter mode configuration,
         bit4 is used selecting tnMode
         bit0 to 3 are used for selecing uMode, one bit for each
         color component */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGgains[0] = %d\n", name, data->gains[0]);
    printf_cfg("EXPORT_CFG%sEXPORT_CFGgains[1] = %d\n", name, data->gains[1]);
    printf_cfg("EXPORT_CFG%sEXPORT_CFGgains[2] = %d\n", name, data->gains[2]);
    printf_cfg("EXPORT_CFG%sEXPORT_CFGgains[3] = %d\n", name, data->gains[3]);
    /**< White balance gains for each color */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGtKnee = %d\n", name, data->tKnee);
    /**< (U0.6) U Suppress curve knee.  X (LL2) value which separates
         constant suppression of 1.0 from linear suppression */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGtnScale[0] = %d\n", name, data->tnScale[0]);
    printf_cfg("EXPORT_CFG%sEXPORT_CFGtnScale[1] = %d\n", name, data->tnScale[1]);
    printf_cfg("EXPORT_CFG%sEXPORT_CFGtnScale[2] = %d\n", name, data->tnScale[2]);
    /**< Tn scaling factor */
    for(i = 0; i < FVID2_BAYER_COLOR_COMP_MAX; i++)
    {
        for(j = 0; j < FVID2_BAYER_COLOR_COMP_MAX; j++)
        {
            printf_cfg("EXPORT_CFG%sEXPORT_CFGtnCurve[%d][%d].posX = %d\n", name, i, j, data->tnCurve[i][j].posX);
            printf_cfg("EXPORT_CFG%sEXPORT_CFGtnCurve[%d][%d].posY = %d\n", name, i, j, data->tnCurve[i][j].posY);
            printf_cfg("EXPORT_CFG%sEXPORT_CFGtnCurve[%d][%d].slope = %d\n", name, i, j, data->tnCurve[i][j].slope);
        }
    }
}

void drvISP_H3a_Config_dump(const char* name, const H3a_Config* data)
{
    uint32_t i = 0;

    printf_cfg("EXPORT_CFG%sEXPORT_CFGmodule = %d\n", name, data->module);
    /**< H3A module to be configured,
     *   Refer \ref H3a_Module for valid values */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGpos.startX = %d\n", name, data->pos.startX);
    printf_cfg("EXPORT_CFG%sEXPORT_CFGpos.startY = %d\n", name, data->pos.startY);
    /**< Position of the actual frame start for H3A */

    /**< AEWB configuration, configured only when H3A_MODULE_AEWB is
     *   selected/enabled in #module */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGaewbCfg.enableALowComp = %d\n", name, data->aewbCfg.enableALowComp);
    /**< Flag to enable A Low Compression */

    printf_cfg("EXPORT_CFG%sEXPORT_CFGaewbCfg.enableMedFilt = %d\n", name, data->aewbCfg.enableMedFilt);
    /**< Flag to enable/disable Medial Filter, to reduce
     *   Temperature Induced Noise */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGaewbCfg.midFiltThreshold = %d\n", name, data->aewbCfg.midFiltThreshold);
    /**< Median Filter Threshold */

    /**< Paxel configuration */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGaewbCfg.winCfg.pos.startX = %d\n", name, data->aewbCfg.winCfg.pos.startX);
    printf_cfg("EXPORT_CFG%sEXPORT_CFGaewbCfg.winCfg.pos.startY = %d\n", name, data->aewbCfg.winCfg.pos.startY);
    /**< Paxel/Window start Position
     *   For AF,
     *      Start horizontal position must be iirFiltStartPos + 2 and must be even
     *      Start vertical position must be greater than 8 if vertical mode is enabled,
     *      range is 0-4095
     *   For AEWB,
     *      Start horizontal position must be in 0-4095
     *      Start vertical position must be 0-4095 */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGaewbCfg.winCfg.width = %d\n", name, data->aewbCfg.winCfg.width);
    /**< Width of the paxel,
     *   minimum width required is 8 pixels */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGaewbCfg.winCfg.height = %d\n", name, data->aewbCfg.winCfg.height);
    /**< Height of the paxel
     *   The height could be from 2 to 256 */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGaewbCfg.winCfg.horzCount = %d\n", name, data->aewbCfg.winCfg.horzCount);
    /**< Horizontal paxel count,
     *   Valid value is from 2 to 36 */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGaewbCfg.winCfg.vertCount = %d\n", name, data->aewbCfg.winCfg.vertCount);
    /**< Vertical Paxel count,
     *   Maximum value supported is 128 */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGaewbCfg.winCfg.horzIncr = %d\n", name, data->aewbCfg.winCfg.horzIncr);
    /**< Horizontal increment,
     *   The Range is from 2 to 32 */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGaewbCfg.winCfg.vertIncr = %d\n", name, data->aewbCfg.winCfg.vertIncr);
    /**< Vertical increment,
     *   The range is from 2 to 32 */

    printf_cfg("EXPORT_CFG%sEXPORT_CFGaewbCfg.blackLineVertStart = %d\n", name, data->aewbCfg.blackLineVertStart);
    /**< Vertical Window Start Position for single black line of windows.
     *   Sets the first line for the single black line of windows */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGaewbCfg.blackLineHeight = %d\n", name, data->aewbCfg.blackLineHeight);
    /**< Window Height for the single black line of windows.
     *   This specifies the window height in an even number of pixels */

    printf_cfg("EXPORT_CFG%sEXPORT_CFGaewbCfg.outMode = %d\n", name, data->aewbCfg.outMode);
    /**< Output Mode
     *   Refer to \ref H3a_AewbOutputMode for valid values */

    printf_cfg("EXPORT_CFG%sEXPORT_CFGaewbCfg.sumShift = %d\n", name, data->aewbCfg.sumShift);
    /**< AE/AWB engine shift value for the accumulation of pixel values
     *   This bit field sets the right shift value which is applied on
     *   the result of the pixel accumulation before it is stored in
     *   the packet. The accumulation takes place on 26 bits
     *   which is enough for 10-bit data and a maximum widow
     *   size of 512 x 512 which results into the accumulation of
     *   256 x 256 pixels of the same color. The shift value must
     *   be set such that the result fits on 16 bits. */

    printf_cfg("EXPORT_CFG%sEXPORT_CFGaewbCfg.satLimit = %d\n", name, data->aewbCfg.satLimit);
    /**< Saturation Limit, This is the value that all sub sampled pixels in the
     *   AE/AWB engine are compared to. If the data is greater or
     *   equal to this data then the block is considered saturated. */


    /**< AF configuration, configured only when H3A_MODULE_AF is
     *   selected/enabled in #module */

    printf_cfg("EXPORT_CFG%sEXPORT_CFGafCfg.enableALowCompr = %d\n", name, data->afCfg.enableALowCompr);
    /**< Flag to enable A Low Compression */

    printf_cfg("EXPORT_CFG%sEXPORT_CFGafCfg.enableMedFilt = %d\n", name, data->afCfg.enableMedFilt);
    /**< Flag to enable/disable Medial Filter,
     *      to reduce Temperature Induced Noise */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGafCfg.midFiltThreshold = %d\n", name, data->afCfg.midFiltThreshold);
    /**< Median Filter Threshold */

    printf_cfg("EXPORT_CFG%sEXPORT_CFGafCfg.rgbPos = %d\n", name, data->afCfg.rgbPos);
    /**< RGB layout in bayer format,
     *   Refer to \ref H3a_AfRgbPos for valid values */

    /**< Paxel configuration */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGafCfg.paxelCfg.pos.startX = %d\n", name, data->afCfg.paxelCfg.pos.startX);
    printf_cfg("EXPORT_CFG%sEXPORT_CFGafCfg.paxelCfg.pos.startY = %d\n", name, data->afCfg.paxelCfg.pos.startY);
    /**< Paxel/Window start Position
     *   For AF,
     *      Start horizontal position must be iirFiltStartPos + 2 and must be even
     *      Start vertical position must be greater than 8 if vertical mode is enabled,
     *      range is 0-4095
     *   For AEWB,
     *      Start horizontal position must be in 0-4095
     *      Start vertical position must be 0-4095 */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGafCfg.paxelCfg.width = %d\n", name, data->afCfg.paxelCfg.width);
    /**< Width of the paxel,
     *   minimum width required is 8 pixels */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGafCfg.paxelCfg.height = %d\n", name, data->afCfg.paxelCfg.height);
    /**< Height of the paxel
     *   The height could be from 2 to 256 */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGafCfg.paxelCfg.horzCount = %d\n", name, data->afCfg.paxelCfg.horzCount);
    /**< Horizontal paxel count,
     *   Valid value is from 2 to 36 */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGafCfg.paxelCfg.vertCount = %d\n", name, data->afCfg.paxelCfg.vertCount);
    /**< Vertical Paxel count,
     *   Maximum value supported is 128 */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGafCfg.paxelCfg.horzIncr = %d\n", name, data->afCfg.paxelCfg.horzIncr);
    /**< Horizontal increment,
     *   The Range is from 2 to 32 */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGafCfg.paxelCfg.vertIncr = %d\n", name, data->afCfg.paxelCfg.vertIncr);
    /**< Vertical increment,
     *   The range is from 2 to 32 */

    printf_cfg("EXPORT_CFG%sEXPORT_CFGafCfg.fvMode = %d\n", name, data->afCfg.fvMode);
    /**< Defines type of accumulation for FV to be done,
     *   Refer \ref H3a_AfFvMode for valid values */

    printf_cfg("EXPORT_CFG%sEXPORT_CFGafCfg.vfMode = %d\n", name, data->afCfg.vfMode);
    /**< Vertical Focus Mode,
     *   Refer \ref H3a_AfVfMode for valid values */

    printf_cfg("EXPORT_CFG%sEXPORT_CFGafCfg.iirCfg1.threshold = %d\n", name, data->afCfg.iirCfg1.threshold);

    for(i = 0; i < H3A_AF_IIR_COEFF_MAX; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGafCfg.iirCfg1.coeff[%d] = %d\n", name, i, data->afCfg.iirCfg1.coeff[i]);
    }

    /**< IIR parameters */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGafCfg.iirCfg2.threshold = %d\n", name, data->afCfg.iirCfg2.threshold);

    for(i = 0; i < H3A_AF_IIR_COEFF_MAX; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGafCfg.iirCfg2.coeff[%d] = %d\n", name, i, data->afCfg.iirCfg2.coeff[i]);
    }

    /**< IIR parameters */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGafCfg.firCfg1.threshold = %d\n", name, data->afCfg.firCfg1.threshold);

    for(i = 0; i < H3A_AF_IIR_COEFF_MAX; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGafCfg.firCfg1.coeff[%d] = %d\n", name, i, data->afCfg.firCfg1.coeff[i]);
    }

    /**< IIR parameters */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGafCfg.firCfg2.threshold = %d\n", name, data->afCfg.firCfg2.threshold);

    for(i = 0; i < H3A_AF_IIR_COEFF_MAX; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGafCfg.firCfg2.coeff[%d] = %d\n", name, i, data->afCfg.firCfg2.coeff[i]);
    }

    printf_cfg("EXPORT_CFG%sEXPORT_CFGafCfg.iirFiltStartPos = %d\n", name, data->afCfg.iirFiltStartPos);
    /**< IIR filter start position */

    printf_cfg("EXPORT_CFG%sEXPORT_CFGoutputSize = %d\n", name, data->outputSize);
    /**< Output Parameter returned by the driver,
     *   Internally driver calculates the output buffer required
     *   for the given AF/AEWB configuration and returns in this variable.
     *   Application can use to allocate H3A output buffer. */
}

void drvISP_Fcp_CcmConfig_dump(const char* name, const Fcp_CcmConfig* data)
{
    uint32_t i = 0;
    uint32_t j = 0;

    for(i = 0; i < FCP_MAX_CCM_COEFF; i++)
    {
        for(j = 0; j < FCP_MAX_CCM_COEFF_IN_RAW; j++)
        {
            printf_cfg("EXPORT_CFG%sEXPORT_CFGweights[%d][%d] = %d\n", name, i, j, data->weights[i][j]);
        }
    }
    /**<  Weights of the CCM matrix.
          Four weights in each row for four input color.
          Format is 12b signed each (S12Q8) representing a range
          from -8 to +7.996 with 8 bits of fraction. */
    for(i = 0; i < FCP_MAX_CCM_COEFF; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGoffsets[%d] = %d\n", name, i, data->offsets[i]);
    }
    /**<  Offsets of the CCM Matrix
          Format is 13b signed notation (S13Q11) representing a
          range of -4096 to +4095.
          An offset of 2048 should be programmed to apply a +1 offset
          to the incoming pixel value. */
}

void drvISP_Rfe_PwlConfig_dump(const char* name, const Rfe_PwlConfig* data)
{
    uint32_t i = 0;

    printf_cfg("EXPORT_CFG%sEXPORT_CFGmask = %d\n", name, data->mask);
    /**< 16bit mask bit pattern,
         used to mask out any control information present in the data
         this field is used and will be configured even if pwl module
         is disabled,
         it gets applied first in the input pixels. */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGshift = %d\n", name, data->shift);
    /**< 3 bit configuration to perform a right shift (>>) from 0 to 7 bits,
     *   used to mask/remove out any control information present in the data
     *   this field is used and will be configured even if pwl module
     *   is disabled,
     *   it gets applied after application of mask. */
    for(i = 0; i < RFE_MAX_COLOR_COMP; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGoffset[%d] = %d\n", name, i, data->offset[i]);
    }
    /**< DC Subtraction in S24 format
     *   Used for removing black level from input pixel
     *   this field is used and will be configured even if pwl module
     *   is disabled.
     *   It gets applied after PWL */
    for(i = 0; i < RFE_MAX_COLOR_COMP; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGgain[%d] = %d\n", name, i, data->gain[i]);
    }
    /**< White balance gains for each color component
     *   Used after applying DC subtraction
     *   H3A receives DC subtracted (but not WB corrected) data */


    printf_cfg("EXPORT_CFG%sEXPORT_CFGenable = %d\n", name, data->enable);
    /**< Flag to enable/disable PWL,
     *   Used to uncompress sensor compressed pixel data using PWL
     *   The PWL block supports an input size from 8 - 16 bits and
     *   can support an output up to 24 bits. */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGxthr1 = %d\n", name, data->xthr1);
    /**< Threshold value, 16bit is used */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGxthr2 = %d\n", name, data->xthr2);
    /**< Threshold value, 16bit is used */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGxthr3 = %d\n", name, data->xthr3);
    /**< Threshold value, 16bit is used */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGythr1 = %d\n", name, data->ythr1);
    /**< Threshold value, 24bit is used */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGythr2 = %d\n", name, data->ythr2);
    /**< Threshold value, 24bit is used */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGythr3 = %d\n", name, data->ythr3);
    /**< Threshold value, 24bit is used */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGslope1 = %d\n", name, data->slope1);
    /**< Slope value, 16bit is used */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGslope2 = %d\n", name, data->slope2);
    /**< Slope value, 16bit is used */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGslope3 = %d\n", name, data->slope3);
    /**< Slope value, 16bit is used */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGslope4 = %d\n", name, data->slope4);
    /**< Slope value, 16bit is used */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGslopeShift = %d\n", name, data->slopeShift);
    /**< Slope value for shift, 7 bits are used */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGoutClip = %d\n", name, data->outClip);
    /**< Output Clip Value */
}


void drvISP_Vhwa_LutConfig_dump(const char* name, const Vhwa_LutConfig* data)
{
    uint32_t i;
    printf_cfg("EXPORT_CFG%sEXPORT_CFGenable = %d\n", name, data->enable);//UINT32
    /**< Flag to enable Lut */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGinputBits = %d\n", name, data->inputBits);//UINT32
    /**< Number of input bits */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGclip = %d\n", name, data->clip);//UINT32
    /**< Output Clip value */
    for(i = 0; i < RFE_COMP_DECOMP_LUT_SIZE; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGtableAddr[%d] = %d\n", name, i, data->tableAddr[i]);//UINT32PTR
    }
    /**< Pointer to the Lut Address,
         must not be null if enable is set to TRUE */
}


void drvISP_Rfe_WdrConfig_dump(const char* name, const Rfe_WdrConfig* data)
{
    uint32_t i = 0;

    printf_cfg("EXPORT_CFG%sEXPORT_CFGenable = %d\n", name, data->enable);//UINT32
    /**< Flag to enable or bypass WDR Merge block
     *   TRUE: enables WDR merge block, in this case it expects two
     *         exposure inputs.
     *   FALSE: bypassed WDR Merge block, short exposure input will
     *          pass to the output. */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGuseShortExpForWgtCalc = %d\n", name, data->useShortExpForWgtCalc);//UINT32
    /**< Flag to make use of Short Exposure for the Weight calculation
     *   TRUE: Use Short exposure for weight calculcation
     *   FALSE: Use long exposure for weight calculation
     *   Refer to specs for more details */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGdst = %d\n", name, data->dst);//UINT32
    /**< Down shift value, after WDR merge. Range 0x0 to 0x1F */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGsbit = %d\n", name, data->sbit);//UINT32
    /**< Shift up value for short exposure frame. Range 0x0 to 0xF */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGlbit = %d\n", name, data->lbit);//UINT32
    /**< Shift up value for long exposure frame. Range 0x0 to 0xF */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGgshort = %d\n", name, data->gshort);//UINT32
    /**< WDR Merge parameter. Gain parameter to be applied for short frame.
     *      Range is 0 - 65535. */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGglong = %d\n", name, data->glong);//UINT32
    /**< WDR Merge parameter. Gain parameter to be applied for long frame.
     *      Range is 0 - 65535. */
    for(i = 0; i < RFE_MAX_COLOR_COMP; i++)
    {
    printf_cfg("EXPORT_CFG%sEXPORT_CFGlbk[%d] = %d\n", name, i, data->lbk[i]);//UINT32
    }
    /**< Black level for long exposure.
     *   The black level at index 0 is applied to even pixel on even line.
     *   The black level at index 1 is applied to odd pixel on even line.
     *   The black level at index 2 is applied to even pixel on odd line.
     *   The black level at index 3 is applied to odd pixel on odd line.
     *   only 12 bits are used. */
    for(i = 0; i < RFE_MAX_COLOR_COMP; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGsbk[%d] = %d\n", name, i, data->sbk[i]);//UINT32
    }
    /**< Black level for short exposure.
     *   The black level at index 0 is applied to even pixel on even line.
     *   The black level at index 1 is applied to odd pixel on even line.
     *   The black level at index 2 is applied to even pixel on odd line.
     *   The black level at index 3 is applied to odd pixel on odd line.
     *   only 12 bits are used. */
    for(i = 0; i < RFE_MAX_COLOR_COMP; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGlwb[%d] = %d\n", name, i, data->lwb[i]);//UINT32
    }
    /**< White balance gain for Long exposure input pixels
     *   The gain at index 0 is applied to even pixel on even line.
     *   The gain at index 1 is applied to odd pixel on even line.
     *   The gain at index 2 is applied to even pixel on odd line.
     *   The gain at index 3 is applied to odd pixel on odd line.
     *   only 13 bits are used */
    for(i = 0; i < RFE_MAX_COLOR_COMP; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGswb[%d] = %d\n", name, i, data->swb[i]);//UINT32
    }
    /**< White balance gain for Short exposure input pixels
     *   The gain at index 0 is applied to even pixel on even line.
     *   The gain at index 1 is applied to odd pixel on even line.
     *   The gain at index 2 is applied to even pixel on odd line.
     *   The gain at index 3 is applied to odd pixel on odd line.
     *   only 13 bits are used */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGwdrThr = %d\n", name, data->wdrThr);//UINT32
    /**< WDR Threshold value. only 16 bits are used */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGafe = %d\n", name, data->afe);//UINT32
    /**< WDR Merge parameter. Exponential part of value in weight calculation
     *   6 bits unsigned value */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGafm = %d\n", name, data->afm);//UINT32
    /**< WDR Merge parameter. Mantissa part of value in weight calculation
     *   16 bits signed value */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGbf = %d\n", name, data->bf);//UINT32
    /**< WDR Merge parameter. Q0.15 BF * 2 ^ -16 * 2 ^ -5
     *   16 bits are used */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGmas = %d\n", name, data->mas);//UINT32
    /**< Adaptive filter, slope config 16 bits are used. */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGmad = %d\n", name, data->mad);//UINT32
    /**< Adaptive filter, threshold config 16 bits are used. */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGmergeShift = %d\n", name, data->mergeShift);//UINT32
    /**< Post merger divide factor*/
    printf_cfg("EXPORT_CFG%sEXPORT_CFGmergeClip = %d\n", name, data->mergeClip);//UINT32
    /**< Post merger clip threshold*/
}


void drvISP_Rfe_DpcOtfConfig_dump(const char* name, const Rfe_DpcOtfConfig* data)
{
    uint32_t i = 0;

    printf_cfg("EXPORT_CFG%sEXPORT_CFGenable = %d\n", name, data->enable);//UINT32
    /**< Flag to enable/disable DPC OTF module
     *   TRUE: Enable this module
     *   FALSE: Disables this module
     *   When module disabled, it does not update threshold/slope Lut */
    for(i = 0; i < RFE_DPC_OTF_LUT_SIZE; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGthreshold[%d] = %d\n", name, i, data->threshold[i]);//UINT32
    }
    /**< Threshold value */
    for(i = 0; i < RFE_DPC_OTF_LUT_SIZE; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGslope[%d] = %d\n", name, i, data->slope[i]);//UINT32
    }
    /**< slope value */
}

void drvISP_Rfe_DpcLutConfig_dump(const char* name, const Rfe_DpcLutConfig* data)
{
    uint32_t i = 0;

    printf_cfg("EXPORT_CFG%sEXPORT_CFGenable = %d\n", name, data->enable);//UINT32
    /**< Flag to enable/disable DPC Lut module
     *   TRUE: Enable this module
     *   FALSE: Disables this module
     *   When module disabled, it does not update Lut */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGisReplaceWhite = %d\n", name, data->isReplaceWhite);//UINT32
    /**< When correction method is selected as 0
     *  (replace with white or black color) in LUT,
     *  This flag is used to select black or white color
     *  TRUE: Replace defect pixel with white color
     *  FALSE: Replace detect pixel with black color */
    for(i = 0; i < RFE_DPC_LUT_SIZE; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGtable[%d] = %d\n", name, i, data->table[i]);//UINT32
    }
    /**< Table containing defect pixel x and y position and
     *   correction method */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGmaxDefectPixels = %d\n", name, data->maxDefectPixels);//UINT32
    /**< Maximum number of detective pixels, ie size of array #table
     *   must be less than #RFE_DPC_LUT_SIZE */
}

void drvISP_Rfe_LscConfig_dump(const char* name, const Rfe_LscConfig* data)
{
    uint32_t i = 0;

    printf_cfg("EXPORT_CFG%sEXPORT_CFGenable = %d\n", name, data->enable);//UINT32
    /**< Flag to enable/disable LSC module
     *   TRUE: Enable this module
     *   FALSE: Disables this module
     *   When module disabled, it does not update Lut */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGgainFmt = %d\n", name, data->gainFmt);//UINT32
    /**< Format of the Gain the LSC Lut
     *   Refer \ref Rfe_LscGainFmt for valid values */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGhorzDsFactor = %d\n", name, data->horzDsFactor);//UINT32
    /**< Horizontal Downscaling factor for LSC Lut
     *   Refer \ref Rfe_LscDsFactor for valid values */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGvertDsFactor = %d\n", name, data->vertDsFactor);//UINT32
    /**< Vertical Downscaling factor for LSC Lut
     *   Refer \ref Rfe_LscDsFactor for valid values */
    for(i = 0; i < 4758; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGtableAddr[%d] = %d\n", name, i, data->tableAddr[i]);//UINT32PTR
    }
    /**< LSC Table Address,
     *   The size of the LSC table can be at max 4758 entries,
     *   each entry contains gains for all 4 colors.
     *   4758 locations with 4 Bytes/location, ie each entry
     *   contains gains forall four colors.
     *   TODO: Changed data type to uint64_t if required */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGnumTblEntry = %d\n", name, data->numTblEntry);//UINT32
    /**< the number of valid entries in #tableAddr
     *   The number of entries in the table must be equal to
     *  ((inputWidth / horzDcFactor) + 1) x ((inputHeight / vertDcFactor) + 1).
     *  The size of each entry is 4bytes */
}

void drvISP_Rfe_GainOfstConfig_dump(const char* name, const Rfe_GainOfstConfig* data)
{

    printf_cfg("EXPORT_CFG%sEXPORT_CFGgain[0] = %d\n", name, data->gain[0]);//UINT32
    printf_cfg("EXPORT_CFG%sEXPORT_CFGgain[1] = %d\n", name, data->gain[1]);//UINT32
    printf_cfg("EXPORT_CFG%sEXPORT_CFGgain[2] = %d\n", name, data->gain[2]);//UINT32
    printf_cfg("EXPORT_CFG%sEXPORT_CFGgain[3] = %d\n", name, data->gain[3]);//UINT32
    /**< White balance gain for each pixel in 2x2 format,
     *   The gain value at index 0 is applied to even pixel on even line.
     *   The gain value at index 1 is applied to odd pixel on even line.
     *   The gain value at index 2 is applied to even pixel on odd line.
     *   The gain value at index 3 is applied to odd pixel on odd line.
     *   in U13Q9 format */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGoffset[0] = %d\n", name, data->offset[0]);//UINT32
    printf_cfg("EXPORT_CFG%sEXPORT_CFGoffset[1] = %d\n", name, data->offset[1]);//UINT32
    printf_cfg("EXPORT_CFG%sEXPORT_CFGoffset[2] = %d\n", name, data->offset[2]);//UINT32
    printf_cfg("EXPORT_CFG%sEXPORT_CFGoffset[3] = %d\n", name, data->offset[3]);//UINT32
    /**< White balance offset for each pixel in 2x2 format,
     *   in S16 format
     *   The offset value at index 0 is applied to even pixel on even line.
     *   The offset value at index 1 is applied to odd pixel on even line.
     *   The offset value at index 2 is applied to even pixel on odd line.
     *   The offset value at index 3 is applied to odd pixel on odd line.
     *   */
}

void drvISP_Rfe_H3aInConfig_dump(const char* name, const Rfe_H3aInConfig* data)
{

    printf_cfg("EXPORT_CFG%sEXPORT_CFGinSel = %d\n", name, data->inSel);//UINT32
    /** Select input source for H3A,
     *  Refer \ref Rfe_H3aInputSelect for valid values */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGshift = %d\n", name, data->shift);//UINT32
    /**< U8, number of right shift, from 0 to 14
     *   Used to convert input bit depth to 10bit */
}

void drvISP_Fcp_CfaConfig_dump(const char* name, const Fcp_CfaConfig* data)
{
    uint32_t i = 0;
    uint32_t j = 0;

    for(i = 0; i < FCP_MAX_COLOR_COMP; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGbypass[%d] = %d\n", name, i, data->bypass[i]);//UINT32
    }
    /**< Enable/Bypass specific Core
     *   TRUE: Bypasses the code ie output = input
     *   FALSE: Enables core for CFA */
    for(i = 0; i < FCP_MAX_CFA_COEFF; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGcoeff[%d] = %d\n", name, i, data->coeff[i]);//INT32
    }
    /**< CFA Coefficients */
    for(i = 0; i < FCP_MAX_COLOR_COMP; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGcoreSel[%d] = %d\n", name, i, data->coreSel[i]);//UINT32
    }
    /**< There are two sets of gradiant and direction cores available in the CFA
     *   This enum array is used for selecting core for each input color.
     *   Refer \ref Fcp_CfaCoreSelect for valid values. */
    for(i = 0; i < FCP_MAX_COLOR_COMP; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGcoreBlendMode[%d] = %d\n", name, i, data->coreBlendMode[i]);//UINT32
    }
    /**< core Mode,
     *   Refer \ref Fcp_CfaCoreBlendMode for valid values */
    for(i = 0; i < FCP_CFA_MAX_SET; i++)
    {
        for(j = 0; j < FCP_CFA_MAX_PHASE; j++)
        {
            printf_cfg("EXPORT_CFG%sEXPORT_CFGgradHzPh[%d][%d] = %d\n", name, i, j, data->gradHzPh[i][j]);//UINT32
        }
    }
    /**< Gradient horizontal phase for both the cores,
     *   Refer to specs for more details */
    for(i = 0; i < FCP_CFA_MAX_SET; i++)
    {
        for(j = 0; j < FCP_CFA_MAX_PHASE; j++)
        {
            printf_cfg("EXPORT_CFG%sEXPORT_CFGgradVtPh[%d][%d] = %d\n", name, i, j, data->gradVtPh[i][j]);//UINT32
        }
    }
    /**< Gradient Vertical phase for both the cores,
     *   Refer to specs for more details */
    for(i = 0; i < FCP_CFA_MAX_SET; i++)
    {
        for(j = 0; j < FCP_CFA_MAX_PHASE; j++)
        {
            printf_cfg("EXPORT_CFG%sEXPORT_CFGintsBitField[%d][%d] = %d\n", name, i, j, data->intsBitField[i][j]);//UINT32
        }
    }
    /**< Intensity bit fields for both the cores,
     *   Refer to specs for more details */
    for(i = 0; i < FCP_CFA_MAX_SET; i++)
    {
        for(j = 0; j < FCP_CFA_MAX_PHASE; j++)
        {
            printf_cfg("EXPORT_CFG%sEXPORT_CFGintsShiftPh[%d][%d] = %d\n", name, i, j, data->intsShiftPh[i][j]);//UINT32
        }
    }
    /**< Intensity phase shift,
     *   Refer to specs for more details */
    for(i = 0; i < FCP_CFA_MAX_SET; i++)
    {
        for(j = 0; j < FCP_CFA_MAX_SET_THR; j++)
        {
            printf_cfg("EXPORT_CFG%sEXPORT_CFGthr[%d][%d] = %d\n", name, i, j, data->thr[i][j]);//UINT32
        }
    }
    /**< Thresholds for both the cores,
     *   Refer to specs for more details */
}

void drvISP_Fcp_Rgb2YuvConfig_dump(const char* name, const Fcp_Rgb2YuvConfig* data)
{
    uint32_t i = 0;
    uint32_t j = 0;

    for(i = 0; i < FCP_MAX_RGB2YUV_COEFF; i++)
    {
        for(j = 0; j < FCP_MAX_RGB2YUV_COEFF; j++)
        {
            printf_cfg("EXPORT_CFG%sEXPORT_CFGweights[%d][%d] = %d\n", name, i, j, data->weights[i][j]);//UINT32
        }
    }
    /**< Weights of the conversion matrix
         Signed 12 bits (S12Q8) with 8 bit of fraction precision,
         representing a range of -8 to +7.996. */
    for(i = 0; i < FCP_MAX_RGB2YUV_COEFF; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGoffsets[%d] = %d\n", name, i, data->offsets[i]);//UINT32
    }
    /**< offsts of the conversion matrix
         13bit signed value. */

}

void drvISP_Fcp_Rgb2HsvConfig_dump(const char* name, const Fcp_Rgb2HsvConfig* data)
{
    uint32_t i = 0;

    printf_cfg("EXPORT_CFG%sEXPORT_CFGinputSelect = %d\n", name, data->inputSelect);//UINT32
    /**< Flag to select input source for RGB2HSV
     *   RGB input for the RGB2HSV module can come either from the
     *   output of the Contrast block, ie after gamma correcttion
     *   or from the input of the contrast block ie before
     *   gamma correction.
     *   Used to configure MuxRGBHSV mux,
     *   Refer \ref Fcp_Rgb2HsvInput for valid values */

    /* Parameters used for calculating grey value*/
    printf_cfg("EXPORT_CFG%sEXPORT_CFGh1Input = %d\n", name, data->h1Input);//UINT32
    /**< Flag to select H1 input, it can either original color Red or
     *   Min of RGB, Configures MuxRGBHSV_H1,
     *   Refer \ref Fcp_Rgb2HsvH1InputSelect for valid values */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGh2Input = %d\n", name, data->h2Input);//UINT32
    /**< Flag to select H2 input, it can either original color Blue or
     *   Max of RGB, Configures MuxRGBHSV_H2,
     *   Refer \ref Fcp_Rgb2HsvH2InputSelect for valid values */
    for(i = 0; i < FCP_RGB2HSV_MAX_IN_COLOR; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGweights[%d] = %d\n", name, i, data->weights[i]);//UINT32
    }
    /**< Weights used in calculating grey scale value
     *   12b signed with a range of -8 to +7.9996 in S12Q8 format */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGoffset = %d\n", name, data->offset);//UINT32
    /**< Offset used in calculating grey scale value
     *   Signed 13 bits in S13Q11 format with a range of -2 to +1.995 */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGuseWbDataForGreyCalc = %d\n", name, data->useWbDataForGreyCalc);//UINT32
    /**< Flag to select either white balance correct data or
     *   uncorrected data for V/grey calculation.
     *   TRUE: Uses white balance corrected data
     *   FALSE: Uses uncorrected data
     *   Configures Mux MuxRGBHSV_Mux_V*/

    /* White Balance Parameters */
    for(i = 0; i < FCP_RGB2HSV_MAX_IN_COLOR; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGwbOffset[%d] = %d\n", name, i, data->wbOffset[i]);//UINT32
    }
    /**< Dynamic White Balance offset applied to correct the saturation plane
     *   Applied only if independent pixel values are below a
     *   threshold (RGBHSV_WB_LINLOGTHR_*)
     *   */
    for(i = 0; i < FCP_RGB2HSV_MAX_IN_COLOR; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGthreshold[%d] = %d\n", name, i, data->threshold[i]);//UINT32
    }
    /**< Dynamic White Balance threshold,
     *   pixel value is compared againts this threshold and wbOffset
     *   is applied only if pixel value is below this threshold.
     *   in U12 format
     *   index 0 is for Red channel format
     *   index 1 is for green channel format
     *   index 2 is for blue channel format */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGsatMinThr = %d\n", name, data->satMinThr);//UINT32
    /**< Threshold for comparing Min(RGB) limit
     *   Refer to FCP specs for more details */

    /* Saturation Parameters */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGsatMode = %d\n", name, data->satMode);//UINT32
    /**< Saturation Mode, used for selecting the numerator in
     *   saturation calculation,
     *   Refer \ref Fcp_SaturationMode for valid values  */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGsatDiv = %d\n", name, data->satDiv);//UINT32
    /**< Saturation Divisor,
     *   Used for selecting denominator for the divisor in
     *   saturatin calculation
     *   Refer \ref Fcp_SaturationDiv for valid values */
}

void drvISP_Fcp_GammaConfig_dump(const char* name, const Fcp_GammaConfig* data)
{
    uint32_t i = 0;

    printf_cfg("EXPORT_CFG%sEXPORT_CFGenable = %d\n", name, data->enable);//UINT32
    /**< Flag to enable/disble Contrast Stretch/Gamm Correction module */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGoutClip = %d\n", name, data->outClip);//UINT32
    /**< Sets the contrast bit clip value,
     *   Contrast module bydefault supports 12bit input and 12bit
     *   unsigned output,
     *   But by using LUT and output Clip value, different output bitwidth
     *   are possible. */
    for(i = 0; i < 513; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGtableC1[%d] = %d\n", name, i, data->tableC1[i]);//UINT32
    }
    /**< Pointer to the table containing 513 entries of Lut for C1 */
    for(i = 0; i < 513; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGtableC2[%d] = %d\n", name, i, data->tableC2[i]);//UINT32
    }
    /**< Pointer to the table containing 513 entries of Lut for C2 */
    for(i = 0; i < 513; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGtableC3[%d] = %d\n", name, i, data->tableC3[i]);//UINT32
    }
    /**< Pointer to the table containing 513 entries of Lut for C3 */
}

void drvISP_Fcp_YuvSatLutConfig_dump(const char* name, const Fcp_YuvSatLutConfig* data)
{
    uint32_t i = 0;

    printf_cfg("EXPORT_CFG%sEXPORT_CFGlumaInputBits = %d\n", name, data->lumaInputBits);//UINT32
    /**< Size of the Luma input in Bits
         Used as the input to 12to8 module and for for shift
         Must be less than or equal to 12 */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGenableLumaLut = %d\n", name, data->enableLumaLut);//UINT32
    /**< Used to enable Lut based companding for Luma 12b to 8b conversion
         When set to TRUE, #lumaLutAddr must not be Null
         When Set to FALSE, shift, calculated based on #lumaInputBits, is used
         to convert from 12b to 8b */
    for(i = 0; i < 513; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGlumaLutAddr[%d] = %d\n", name, i, data->lumaLutAddr[i]);//UINT32
    }
    /**< Pointer to the Lut with 513 entries
         Used for converting lut color from 12b to 8b */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGenableChromaLut = %d\n", name, data->enableChromaLut);//UINT32
    /**< Used to enable Lut based companding for chroma 12b to 8b conversion
         When set to TRUE, #chromaLutAddr must not be Null
         When Set to FALSE, shift to convert from 12b to 8b */
    for(i = 0; i < 513; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGchromaLutAddr[%d] = %d\n", name, i, data->chromaLutAddr[i]);//UINT32
    }
    /**< Pointer to the Lut with 513 entries
         Used for converting chroma color from 12b to 8b */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGenableSaturLut = %d\n", name, data->enableSaturLut);//UINT32
    /**< Used to enable Lut based companding for Saturation 12b to 8b conversion
         When set to TRUE, #saturLutAddr must not be Null
         When Set to FALSE, shift to convert from 12b to 8b */
    for(i = 0; i < 513; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGsaturLutAddr[%d] = %d\n", name, i, data->saturLutAddr[i]);//UINT32
    }
    /**< Pointer to the Lut with 513 entries
         Used for converting saturation color from 12b to 8b */
}

void drvISP_Fcp_HistConfig_dump(const char* name, const Fcp_HistConfig* data)
{

    printf_cfg("EXPORT_CFG%sEXPORT_CFGenable = %d\n", name, data->enable);//UINT32
    /**< Flag to enable/disable histogram module
     *   TRUE: Enables histogram module, when enabled stores the
     *         output in two 256x2bit memory in ping-pong fashion
     *   FALSE: Disables histogram module */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGinput = %d\n", name, data->input);//UINT32
    /**< Selects histogram input,
     *   Refer \ref Fcp_HistInputSelect for valid values */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGroi.cropStartX = %d\n", name, data->roi.cropStartX);//UINT32
    /**< Horizontal offset from which picture needs to be cropped. */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGroi.cropStartY = %d\n", name, data->roi.cropStartY);//UINT32
    /**< Vertical offset from which picture needs to be cropped. */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGroi.cropWidth = %d\n", name, data->roi.cropWidth);//UINT32
    /**< Width of the picture to be cropped. */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGroi.cropHeight = %d\n", name, data->roi.cropHeight);//UINT32
    /**< Height of the picture to be cropped. */
    /**< Configures ROI for histogram */
}

void drvISP_Glbce_Config_dump(const char* name, const Glbce_Config* data)
{
    uint32_t i = 0;

    printf_cfg("EXPORT_CFG%sEXPORT_CFGirStrength = %d\n", name, data->irStrength);//UINT32
    /**< This sets processing Strength. Minimum value is 0, maximum is 255.
     *   When set to 0x00, Video data will not be processed at all and will
     *   go to output unchanged. */

    printf_cfg("EXPORT_CFG%sEXPORT_CFGblackLevel = %d\n", name, data->blackLevel);//UINT32
    /**< Blank level of the input pixels,
     *   Value used here will be used as zero level for all GLBCE processing
     *   Data below Black level will not be processed and stay unchanged */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGwhiteLevel = %d\n", name, data->whiteLevel);//UINT32
    /**< White level of the input pixels,
     *   Value used here will be used as white level for all GLBCE processing
     *   Data above white level will not be processed and stay unchanged*/

    printf_cfg("EXPORT_CFG%sEXPORT_CFGintensityVariance = %d\n", name, data->intensityVariance);//UINT32
    /**< Variance Intensity - Sets the degree of sensitivity in the
     *   luminance domain. Maximum Variance is 0xF, and minimum
     *   Variance is 0x0 */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGspaceVariance = %d\n", name, data->spaceVariance);//UINT32
    /**< Variance Space - Sets the degree of spatial sensitivity of
     *   the algorithm. As this parameter is made smaller,
     *   the algorithm focuses on smaller regions within the image.
     *   Maximum Variance is 0xF, and minimum Variance is 0x0 */

    printf_cfg("EXPORT_CFG%sEXPORT_CFGbrightAmplLimit = %d\n", name, data->brightAmplLimit);//UINT32
    /**< The resultant tone curve cannot be lower than bright
     *   amplification limit line controlled by the this parameter.
     *   Maximum limit is 0xF, when the value is 0x0 there is no limit */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGdarkAmplLimit = %d\n", name, data->darkAmplLimit);//UINT32
    /**< The resultant tone curve cannot be higher than dark
     *   amplification limit line controlled by the this parameter.
     *   Maximum limit is 0xF, when the value is 0x0 there is no limit */

    printf_cfg("EXPORT_CFG%sEXPORT_CFGdither = %d\n", name, data->dither);//UINT32
    /**< Sets the number of LSB bits to dither,
     *   Refer \ref Glbce_DitherSize for valid values */

    printf_cfg("EXPORT_CFG%sEXPORT_CFGmaxSlopeLimit = %d\n", name, data->maxSlopeLimit);//UINT32
    /**< Slope Max Limit is used to restrict the slope of the
     *   tone-curve generated by GLBCE */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGminSlopeLimit = %d\n", name, data->minSlopeLimit);//UINT32
    /**< Slope Min Limit is used to restrict the slope of the
     *   tone-curve generated by GLBCE */

    for(i = 0; i < GLBCE_ASYMMETRY_LUT_SIZE; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGasymLut[%d] = %d\n", name, i, data->asymLut[i]);//UINT32
    }
    /**< The Asymmetry Function Lookup Table, The size of each entry is 16bits.
     *   The Asymmetry function is used to balance the GLBCE
     *   effect between the dark and bright regions of the image */
}

void drvISP_Glbce_PerceptConfig_dump(const char* name, const Glbce_PerceptConfig* data)
{
    uint32_t i = 0;

    printf_cfg("EXPORT_CFG%sEXPORT_CFGenable = %d\n", name, data->enable);
    /**< Flag to enable/disable Forward or Reverse Percept */
    for(i = 0; i < GLBCE_PERCEPT_LUT_SIZE; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGtable[%d] = %d\n", name, i, data->table[i]);
    }
    /**< Perceptual Table */
}

void drvISP_Fcp_EeConfig_dump(const char* name, const Fcp_EeConfig* data)
{
    uint32_t i = 0;

    printf_cfg("EXPORT_CFG%sEXPORT_CFGenable = %d\n", name, data->enable);//UINT32
    /**< Flag to Enable/Disable EE,
     *   TRUE: Enables EE
     *   FALSE: Disables EE */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGalignY12withChroma = %d\n", name, data->alignY12withChroma);//UINT32
    printf_cfg("EXPORT_CFG%sEXPORT_CFGalignY8withChroma = %d\n", name, data->alignY8withChroma);//UINT32
    printf_cfg("EXPORT_CFG%sEXPORT_CFGeeForY12OrY8 = %d\n", name, data->eeForY12OrY8);//UINT32
    /**< Selects Y12 or Y8 for EE input
        0, Y12
        1, Y8 */
    printf_cfg("EXPORT_CFG%sEXPORT_CFGbypassY12 = %d\n", name, data->bypassY12);//UINT32
    printf_cfg("EXPORT_CFG%sEXPORT_CFGbypassC12 = %d\n", name, data->bypassC12);//UINT32
    printf_cfg("EXPORT_CFG%sEXPORT_CFGbypassY8 = %d\n", name, data->bypassY8);//UINT32
    printf_cfg("EXPORT_CFG%sEXPORT_CFGbypassC8 = %d\n", name, data->bypassC8);//UINT32

    printf_cfg("EXPORT_CFG%sEXPORT_CFGleftShift = %d\n", name, data->leftShift);//UINT32
    printf_cfg("EXPORT_CFG%sEXPORT_CFGrightShift = %d\n", name, data->rightShift);//UINT32

    printf_cfg("EXPORT_CFG%sEXPORT_CFGyeeShift = %d\n", name, data->yeeShift);//UINT32
    for(i = 0; i < 9; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGcoeff[%d] = %d\n", name, i, data->coeff[i]);//INT32
    }
    printf_cfg("EXPORT_CFG%sEXPORT_CFGyeeEThr = %d\n", name, data->yeeEThr);//UINT32
    printf_cfg("EXPORT_CFG%sEXPORT_CFGyeeMergeSel = %d\n", name, data->yeeMergeSel);//UINT32
    printf_cfg("EXPORT_CFG%sEXPORT_CFGhaloReductionOn = %d\n", name, data->haloReductionOn);//UINT32
    printf_cfg("EXPORT_CFG%sEXPORT_CFGyesGGain = %d\n", name, data->yesGGain);//UINT32
    printf_cfg("EXPORT_CFG%sEXPORT_CFGyesEGain = %d\n", name, data->yesEGain);//UINT32
    printf_cfg("EXPORT_CFG%sEXPORT_CFGyesEThr1 = %d\n", name, data->yesEThr1);//UINT32
    printf_cfg("EXPORT_CFG%sEXPORT_CFGyesEThr2 = %d\n", name, data->yesEThr2);//UINT32
    printf_cfg("EXPORT_CFG%sEXPORT_CFGyesGOfset = %d\n", name, data->yesGOfset);//UINT32

    for(i = 0; i < 4096; i++)
    {
        printf_cfg("EXPORT_CFG%sEXPORT_CFGlut[%d] = %d\n", name, i, data->lut[i]);//INT32PTR
    }
}


void drvISP_tivxVpaccogent_hydra3_ispConfig_dump(const struct ISP_config* data)
{
    drvISP_Nsf4v_Config_dump("nsf4Cfg", &data->nsf4Cfg);
    /*! FVID2 VISS Driver Config for H3A Module */
    drvISP_H3a_Config_dump("h3aCfg", &data->h3aCfg);
    /*! FVID2 VISS Driver Config for FCP CCM Module */
    drvISP_Fcp_CcmConfig_dump("ccmCfg", &data->ccmCfg);
    /*! FVID2 VISS Driver Config for RAWFE PWL Module */
    drvISP_Rfe_PwlConfig_dump("pwlCfg1", &data->pwlCfg1);
    /*! FVID2 VISS Driver Config for RAWFE PWL Module */
    drvISP_Rfe_PwlConfig_dump("pwlCfg2", &data->pwlCfg2);
    /*! FVID2 VISS Driver Config for RAWFE PWL Module */
    drvISP_Rfe_PwlConfig_dump("pwlCfg3", &data->pwlCfg3);
    drvISP_Vhwa_LutConfig_dump("decomp1Cfg", &data->decomp1Cfg);
    drvISP_Vhwa_LutConfig_dump("decomp2Cfg", &data->decomp2Cfg);
    drvISP_Vhwa_LutConfig_dump("decomp3Cfg", &data->decomp3Cfg);

    drvISP_Rfe_WdrConfig_dump("merge1Cfg", &data->merge1Cfg);
    drvISP_Rfe_WdrConfig_dump("merge2Cfg", &data->merge2Cfg);

    drvISP_Vhwa_LutConfig_dump("rfeLut20to16Cfg", &data->rfeLut20to16Cfg);

    drvISP_Rfe_DpcOtfConfig_dump("dpcOtfCfg", &data->dpcOtfCfg);
    drvISP_Rfe_DpcLutConfig_dump("dpcLutCfg", &data->dpcLutCfg);
    drvISP_Rfe_LscConfig_dump("lscCfg", &data->lscCfg);
    /*! FVID2 VISS Driver Config for White Balance module, after LSC */
    drvISP_Rfe_GainOfstConfig_dump("wbCfg", &data->wbCfg);
    /*! FVID2 VISS Driver Config for H3A Input */
    drvISP_Rfe_H3aInConfig_dump("h3aInCfg", &data->h3aInCfg);
    /*! FVID2 VISS Driver Config for H3A LUT */
    drvISP_Vhwa_LutConfig_dump("h3aLutCfg", &data->h3aLutCfg);

    /*! FVID2 VISS Driver Config for Flex CFA */
    drvISP_Fcp_CfaConfig_dump("cfaCfg", &data->cfaCfg);

    drvISP_Vhwa_LutConfig_dump("cfaLut16to12Cfg", &data->cfaLut16to12Cfg);

    drvISP_Fcp_Rgb2YuvConfig_dump("rgb2yuvCfg", &data->rgb2yuvCfg);

    drvISP_Fcp_Rgb2HsvConfig_dump("rgb2hsvCfg", &data->rgb2hsvCfg);

    drvISP_Fcp_GammaConfig_dump("gammaCfg", &data->gammaCfg);

    drvISP_Fcp_YuvSatLutConfig_dump("yuvSatLutCfg", &data->yuvSatLutCfg);

    drvISP_Fcp_HistConfig_dump("histCfg", &data->histCfg);

    drvISP_Glbce_Config_dump("glbceCfg", &data->glbceCfg);
    drvISP_Glbce_PerceptConfig_dump("fwdPrcpCfg", &data->fwdPrcpCfg);
    drvISP_Glbce_PerceptConfig_dump("revPrcpCfg", &data->revPrcpCfg);

    drvISP_Fcp_EeConfig_dump("eeCfg", &data->eeCfg);
}
