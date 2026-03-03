/*******************************************************************************
 * config_dump.h
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
#ifndef TIVX_HWA_VPAC_COGENT_HYDRA3_ISP_CONFIG_DUMP_H_
#define TIVX_HWA_VPAC_COGENT_HYDRA3_ISP_CONFIG_DUMP_H_
#include "isp_process.h"


void drvISP_tivxVpaccogent_hydra3_ispConfig_dump(const struct ISP_config* data);

void drvISP_Nsf4v_Config_dump(const char* name, const Nsf4v_Config* data);
void drvISP_H3a_Config_dump(const char* name, const H3a_Config* data);
void drvISP_Fcp_CcmConfig_dump(const char* name, const Fcp_CcmConfig* data);
void drvISP_Rfe_PwlConfig_dump(const char* name, const Rfe_PwlConfig* data);
void drvISP_Vhwa_LutConfig_dump(const char* name, const Vhwa_LutConfig* data);
void drvISP_Rfe_WdrConfig_dump(const char* name, const Rfe_WdrConfig* data);
void drvISP_Rfe_DpcOtfConfig_dump(const char* name, const Rfe_DpcOtfConfig* data);
void drvISP_Rfe_DpcLutConfig_dump(const char* name, const Rfe_DpcLutConfig* data);
void drvISP_Rfe_LscConfig_dump(const char* name, const Rfe_LscConfig* data);
void drvISP_Rfe_GainOfstConfig_dump(const char* name, const Rfe_GainOfstConfig* data);
void drvISP_Rfe_H3aInConfig_dump(const char* name, const Rfe_H3aInConfig* data);
void drvISP_Fcp_CfaConfig_dump(const char* name, const Fcp_CfaConfig* data);
void drvISP_Fcp_Rgb2YuvConfig_dump(const char* name, const Fcp_Rgb2YuvConfig* data);
void drvISP_Fcp_Rgb2HsvConfig_dump(const char* name, const Fcp_Rgb2HsvConfig* data);
void drvISP_Fcp_GammaConfig_dump(const char* name, const Fcp_GammaConfig* data);
void drvISP_Fcp_YuvSatLutConfig_dump(const char* name, const Fcp_YuvSatLutConfig* data);
void drvISP_Fcp_HistConfig_dump(const char* name, const Fcp_HistConfig* data);
void drvISP_Glbce_Config_dump(const char* name, const Glbce_Config* data);
void drvISP_Glbce_PerceptConfig_dump(const char* name, const Glbce_PerceptConfig* data);
void drvISP_Fcp_EeConfig_dump(const char* name, const Fcp_EeConfig* data);

#endif /* TIVX_HWA_VPAC_COGENT_HYDRA3_ISP_CONFIG_DUMP_H_ */
