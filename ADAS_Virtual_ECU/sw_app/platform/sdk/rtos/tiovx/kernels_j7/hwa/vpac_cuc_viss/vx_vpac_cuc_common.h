/*******************************************************************************
 * vx_vpac_cuc_common.h
 *
 * Copyright (c) 2019 Texas Instruments Incorporated
 *
 * All rights reserved not granted herein.
 *
 * Limited License.
 *
 * Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
 * license under copyrights and patents it now or hereafter owns or controls to make,
 * have made, use, import, offer to sell and sell ("Utilize") this software subject to the
 * terms herein.  With respect to the foregoing patent license, such license is granted
 * solely to the extent that any such patent is necessary to Utilize the software alone.
 * The patent license shall not apply to any combinations which include this software,
 * other than combinations with devices manufactured by or for TI ("TI Devices").
 * No hardware patent is licensed hereunder.
 *
 * Redistributions must preserve existing copyright notices and reproduce this license
 * (including the above copyright notice and the disclaimer and (if applicable) source
 * code license limitations below) in the documentation and/or other materials provided
 * with the distribution
 *
 * Redistribution and use in binary form, without modification, are permitted provided
 * that the following conditions are met:
 *
 * *       No reverse engineering, decompilation, or disassembly of this software is
 * permitted with respect to any software provided in binary form.
 *
 * *       any redistribution and use are licensed by TI for use only with TI Devices.
 *
 * *       Nothing shall obligate TI to provide you with source code for the software
 * licensed and provided to you in object code.
 *
 * If software source code is provided to you, modification and redistribution of the
 * source code are permitted provided that the following conditions are met:
 *
 * *       any redistribution and use of the source code, including any resulting derivative
 * works, are licensed by TI for use only with TI Devices.
 *
 * *       any redistribution and use of any object code compiled from the source code
 * and any resulting derivative works, are licensed by TI for use only with TI Devices.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of its suppliers
 *
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * DISCLAIMER.
 *
 * THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL TI AND TI'S LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef VX_VPAC_CUC_COMMON_H_
#define VX_VPAC_CUC_COMMON_H_

#include "TI/tivx.h"
#include "VX/vx.h"
#include "tivx_hwa_kernels.h"
#include "tivx_kernel_vpac_cuc_viss.h"
#include "TI/tivx_target_kernel.h"
#include "tivx_kernels_target_utils.h"
#include "TI/tivx_event.h"
#include "TI/tivx_mutex.h"

#include "ti/drv/vhwa/include/vhwa_m2mViss.h"

#include <math.h>
#include <float.h>
#include <time.h>

#if defined(__TI_ARM_V7R5__)
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Timestamp.h>
#endif

#include <cogent_api.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef float float32_t;
typedef double float64_t;

/*********************************
 *      VPAC_COGENT_HYDRA3_ISP STRUCTURES
 *********************************/

#define HISTOGRAM_MAX_BIN 5

/*! Histogram thresholds configuration */
typedef struct {
    uint16_t Hist_Thresh_01;         /*!< Histogram threshold for bin 0/1 boundary */
    uint16_t Hist_Thresh_12;         /*!< Histogram threshold for bin 1/2 boundary  */
    uint16_t Hist_Thresh_23;         /*!< Histogram threshold for bin 2/3 boundary  */
    uint16_t Hist_Thresh_34;         /*!< Histogram threshold for bin 3/4 boundary  */
} hist_cfg_t;

typedef struct
{
    /*! FVID2 VISS Driver Config for NSF4 Module */
    Nsf4v_Config                        nsf4Cfg;
    /*! FVID2 VISS Driver Config for H3A Module */
    H3a_Config                          h3aCfg;
    /*! FVID2 VISS Driver Config for FCP CCM Module */
    Fcp_CcmConfig                       ccmCfg;
    /*! FVID2 VISS Driver Config for RAWFE PWL Module */
    Rfe_PwlConfig                       pwlCfg1;
    /*! FVID2 VISS Driver Config for RAWFE PWL Module */
    Rfe_PwlConfig                       pwlCfg2;
    /*! FVID2 VISS Driver Config for RAWFE PWL Module */
    Rfe_PwlConfig                       pwlCfg3;
    Vhwa_LutConfig                      decomp1Cfg;
    Vhwa_LutConfig                      decomp2Cfg;
    Vhwa_LutConfig                      decomp3Cfg;

    Rfe_WdrConfig                       merge1Cfg;
    Rfe_WdrConfig                       merge2Cfg;

    Vhwa_LutConfig                      rfeLut20to16Cfg;

    Rfe_DpcOtfConfig                    dpcOtfCfg;
    Rfe_DpcLutConfig                    dpcLutCfg;
    Rfe_LscConfig                       lscCfg;
    /*! FVID2 VISS Driver Config for White Balance module, after LSC */
    Rfe_GainOfstConfig                  wbCfg;
    /*! FVID2 VISS Driver Config for H3A Input */
    Rfe_H3aInConfig                     h3aInCfg;
    /*! FVID2 VISS Driver Config for H3A LUT */
    Vhwa_LutConfig                      h3aLutCfg;

    /*! FVID2 VISS Driver Config for Flex CFA */
    Fcp_CfaConfig                       cfaCfg;

    Vhwa_LutConfig                      cfaLut16to12Cfg;

    Fcp_Rgb2YuvConfig                   rgb2yuvCfg;

    Fcp_Rgb2HsvConfig                   rgb2hsvCfg;

    Fcp_GammaConfig                     gammaCfg;

    Fcp_YuvSatLutConfig                 yuvSatLutCfg;

    Fcp_HistConfig                      histCfg;

    Glbce_Config                        glbceCfg;
    Glbce_PerceptConfig                 fwdPrcpCfg;
    Glbce_PerceptConfig                 revPrcpCfg;

    Fcp_EeConfig                        eeCfg;
    hist_cfg_t                          h3a_hist_cfg;
} tivxVpacCucVissConfig;

typedef struct
{
    Rfe_PwlConfig                      *vsPwlCfg;
    Rfe_PwlConfig                      *sPwlCfg;
    Rfe_PwlConfig                      *lPwlCfg;

    Vhwa_LutConfig                     *vsLutCfg;
    Vhwa_LutConfig                     *sLutCfg;
    Vhwa_LutConfig                     *lLutCfg;

    Rfe_WdrConfig                      *wdr1Cfg;
    Rfe_WdrConfig                      *wdr2Cfg;
    Vhwa_LutConfig                     *comp20To16LutCfg;

    Rfe_DpcOtfConfig                   *dpcOtf;
    Rfe_DpcLutConfig                   *dpcLut;

    Rfe_LscConfig                      *lscCfg;

    Rfe_GainOfstConfig                 *wbCfg;

    Rfe_H3aInConfig                    *rfeH3aInCfg;
    Vhwa_LutConfig                     *h3aLutCfg;

    Vhwa_LutConfig                     *cfaLut16to12Cfg;
    Fcp_CfaConfig                      *cfaCfg;
    Fcp_CcmConfig                      *ccm;
    Fcp_GammaConfig                    *gamma;
    Fcp_Rgb2HsvConfig                  *rgb2Hsv;
    Fcp_Rgb2YuvConfig                  *rgb2yuv;
    Fcp_YuvSatLutConfig                *yuvSatLutCfg;

    Nsf4v_Config                       *nsf4Cfg;
    Glbce_Config                       *glbceCfg;
    Glbce_PerceptConfig                *fwdPrcpCfg;
    Glbce_PerceptConfig                *revPrcpCfg;

    H3a_Config                         *h3aCfg;
    Fcp_EeConfig                       *eeCfg;
    Fcp_HistConfig                     *histCfg;
} tivxVpacCucVissConfigRef;


/*! Buffers which are set by DCC and the driver doesn't already have space
 * reserved to put it in the context, can reside here.  This way, if there
 * are multiple cameras configured with different tables, there is a instance
 * specific location as part of the instance context where it can reside
 * independently (this may be a waste of memory in the case of homogenous cameras)*/
typedef struct
{
    uint32_t h3aLut[RFE_H3A_COMP_LUT_SIZE];
    uint32_t cfa_lut_16to12[RFE_COMP_DECOMP_LUT_SIZE];
    uint32_t rawfe_pwl_vshort_lut[RFE_COMP_DECOMP_LUT_SIZE];
    uint32_t lsc_tbl[(RFE_LSC_TBL_SIZE * RFE_MAX_COLOR_COMP)];
    int32_t  yee_lut[(FCP_EE_LUT_SIZE)];
    uint32_t luma_lut[(FCP_RGB_YUVSAT_LUT_SIZE)];
    uint32_t chroma_lut[(FCP_RGB_YUVSAT_LUT_SIZE)];
    uint32_t satur_lut[(FCP_RGB_YUVSAT_LUT_SIZE)];
    uint32_t gamma_table_c1[(FCP_GAMMA_LUT_SIZE)];
    uint32_t gamma_table_c2[(FCP_GAMMA_LUT_SIZE)];
    uint32_t gamma_table_c3[(FCP_GAMMA_LUT_SIZE)];
    uint32_t rfeLut20to16Cfg[(RFE_H3A_COMP_LUT_SIZE)];
} tivxVpacCucIspLUTAllocation;

typedef struct {
    float32_t rg;   // ratio of average value for red pixels in current pixel
    float32_t green; // Average value for green pixels in current pixel
    float32_t bg;  // ratio of average value for blue pixels in current pixel
} h3a_pixel_data_t;

#define SENSOR_DATA_ARRAY_MAX_SZ (64*4)

#define TIVX_VPAC_CUC_CTLVAL_RECORD_COUNT   8
typedef struct {
    uint16_t obj_desc_id;
    uint16_t ctlval;
    uint32_t verified;          /* keep it 32bits for overall alignment */
} ctlval_record_t;

typedef struct
{
    tivx_mutex          lock;

    tivx_event          eventVissCmpl;
    tivx_event          eventRcCmpl;
    tivx_event          eventProcessCmpl;

    /* VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV */

    /*! Flag to indicate if this object is free or not */
    tivxVpacCucIspLUTAllocation               lut_allocation_ptr;

    /*! VISS configuration containing instances of VISS module's configuration,
     *  supported by driver.
     *  This is mainly used to map DCC output configuration to driver's
     *  configuration. */
    struct ISP_config                     vissCfg;

    /*! Contains pointer to Module's configuration
     *  When app passes DCC database, it is parsed and output is stored in
     *  vissCfg. The pointers in vissCfgRef point to these objects.
     *  vissCfgRef contains pointer to only those modules, for which
     *  config is passed in DCC database.
     *  When the next process API is called, Pointers in vissCfgRef
     *  are checked and if any of them is set to null, module's
     *  configuration is set in the driver and corresponding pointer
     *  is reset to null. */
    tivxVpacCucVissConfigRef               vissCfgRef;

    /*! Flag to indicate if the pointers in vissCfgRef are updated
     *  and pointing to new config or not.
     *  When process API is called, this is used to know if config
     *  is updated and if driver can be called to update modules config. */
    uint64_t                            isConfigUpdated;

    struct ISP_data isp_data_storage;
    struct ar014x_sensor_data sensorData;

    uint8_t sensor_register_list[SENSOR_DATA_ARRAY_MAX_SZ];
    uint32_t list_elements_counter;

    /* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */

    tivx_vpac_cuc_isp_params_t ispPrms;

    uint32_t            frame_counter;
    uint32_t            need_reinit;

    Fvid2_Handle        handle;

    /*! VISS M2M Driver Parameters */
    Vhwa_M2mVissParams  vissPrms;

    /*! VISS M2M Driver Input Frame List, used for providing
     *  an array of input frames */
    Fvid2_FrameList     inFrmList;
    /*! VISS M2M Driver Output Frame List, used for providing
     *  an array of output frames */
    Fvid2_FrameList     outFrmList;
    /*! VISS M2M Driver Input Frames */
    Fvid2_Frame         inFrm[VHWA_M2M_VISS_MAX_INPUTS];
    /*! VISS M2M Driver Output Frames */
    Fvid2_Frame         outFrm[VHWA_M2M_VISS_MAX_OUTPUTS];

    /*! Number of input buffer pointers */
    uint32_t            num_in_buf;
    /*! Number of output buffer pointers for each output */
    uint32_t            num_out_buf_addr[TIVX_KERNEL_VPAC_CUC_VISS_MAX_IMAGE_OUTPUT];

    /*! VISS configuration containing instances of VISS module's configuration,
     *  supported by driver. */
    // tivxVpacCucVissConfig    vissCfg;

    uint32_t            h3a_output_size;
    uint8_t             h3a_stats_data[TIVX_VPAC_CUC_VISS_MAX_H3A_STAT_NUMBYTES] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));

    v3xISP_ManufacturingTestType_t tpg;
    tivx_shared_mem_ptr_t               ctx_mem_ptr;
    uint64_t                            ctx_mem_phys_ptr;
    Glbce_StatsInfo                     glbceStatInfo;
    Vhwa_M2mVissConfigAppBuff           configurationBuffer;

    ctlval_record_t ctlval_records[TIVX_VPAC_CUC_CTLVAL_RECORD_COUNT];
} tivxVpacCucIspObj;

/*********************************
 *      Function Prototypes
 *********************************/

/*! Sets entire ISP config in DRV */
// vx_status tivxVpacCucVissWriteConfigInDriver(struct isp_config_ref *isp_config_ref,
//                                                Fvid2_Handle handle,
//                                                Vhwa_M2mVissParams *vissDrvPrms,
//                                                uint32_t *h3a_output_size);

vx_status tivxVpacCucMapUserDesc(void **target_ptr,
                                const tivx_obj_desc_user_data_object_t *desc,
                                uint32_t size, vx_enum rw);
void tivxVpacCucUnmapUserDesc(void **target_ptr,
                             const tivx_obj_desc_user_data_object_t *desc,
                             vx_enum rw);


/*! Sets entire VISS config in DRV */
vx_status tivxVpacCucVissSetConfigInDrv(tivxVpacCucIspObj *ispObj);

/*! This is used to update VISS parameters based on AEWB output.
 *  It uses DCC to get the updated parameter values
 */
// vx_status tivxVpacCucIspApplyAEWBParams(tivxVpacCucRcObj *vissObj,
    // tivx_TI_ae_awb_params_t *aewb_result);

#ifdef __cplusplus
}
#endif

#endif /* VX_VPAC_CUC_COMMON_H_ */

