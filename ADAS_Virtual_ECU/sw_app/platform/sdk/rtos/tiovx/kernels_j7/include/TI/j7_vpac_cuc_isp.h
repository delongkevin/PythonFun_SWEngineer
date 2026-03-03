/*******************************************************************************
 * j7_vpac_cogent_isp.h
 *
 * Cogent ISP framework Kernel API.
 *
 * THIS FILE IS AUTO-GENERATED. DO NOT EDIT.
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

#ifndef J7_VPAC_CUC_VISS_H_
#define J7_VPAC_CUC_VISS_H_

#include <VX/vx.h>
#include <VX/vx_kernels.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TIVX_TARGET_VPAC_CUC_VISS   "VPAC_CUC_VISS"
/*! \brief Target name for VPAC CUC_VISS
 * \ingroup group_tivx_ext_targets
 */
#define TIVX_TARGET_VPAC_CUC_RC   "VPAC_CUC_RC"
/*! \brief Target name for VPAC CUC_RC
 * \ingroup group_tivx_ext_targets
 */

/*!
 * \file
 * \brief The cogent_isp kernels in this kernel extension.
 */

/*! \brief cogent_isp kernel name
 *  \ingroup group_vision_function_cogent_isp
 */
#define TIVX_KERNEL_VPAC_CUC_VISS_NAME     "com.ti.hwa.vpac_cuc_viss"

/*********************************
 *      VPAC_VISS Defines
 *********************************/

/*! \brief Maximum H3A number of bytes in statistics data array
 *
 *   Allocating 24KB buffer which is large enough for 32x32 windows
 *
 *  \ingroup group_vision_function_vpac_cogent_isp
 */
#define TIVX_VPAC_CUC_VISS_MAX_H3A_STAT_NUMBYTES            (24576U)

#define TIVX_VPAC_CUC_RC_TRACE_DATA_NUMBYTES                (0x80000)

/*! \brief The H3A output memory address alignment
 *
 *   The start address of the tivx_statistic_data_t::data buffer must be aligned
 *   to this value, so the tivx_statistic_data_t::resv field is used
 *   along with this value to properly pad the structure to enable this
 *   alignment.  \see tivx_statistic_data_t::resv
 *
 *  \ingroup group_vision_function_vpac_viss
 */
#define TIVX_VPAC_CUC_VISS_H3A_OUT_BUFF_ALIGN  (64U)

/*!
 * \defgroup group_vision_function_vpac_cuc_viss_mux Enumerations
 * \brief Enumerations for configuration parameters in VPAC VISS structures
 * \ingroup group_vision_function_vpac_viss
 * @{*/

/*! \see tivx_vpac_cuc_isp_params_t::mux_output0 */
#define TIVX_VPAC_CUC_VISS_MUX0_Y12        (0U)
/*! \see tivx_vpac_cuc_isp_params_t::mux_output0 */
#define TIVX_VPAC_CUC_VISS_MUX0_VALUE12    (3U)
/*! \see tivx_vpac_cuc_isp_params_t::mux_output0 */
#define TIVX_VPAC_CUC_VISS_MUX0_NV12_P12   (4U)

/*! \see tivx_vpac_cuc_isp_params_t::mux_output1 */
#define TIVX_VPAC_CUC_VISS_MUX1_UV12       (0U)
/*! \see tivx_vpac_cuc_isp_params_t::mux_output1 */
#define TIVX_VPAC_CUC_VISS_MUX1_C1         (2U)

/*! \see tivx_vpac_cuc_isp_params_t::mux_output2*/
#define TIVX_VPAC_CUC_VISS_MUX2_Y8         (0U)
/*! \see tivx_vpac_cuc_isp_params_t::mux_output2 */
#define TIVX_VPAC_CUC_VISS_MUX2_RED        (1U)
/*! \see tivx_vpac_cuc_isp_params_t::mux_output2 */
#define TIVX_VPAC_CUC_VISS_MUX2_C2         (2U)
/*! \see tivx_vpac_cuc_isp_params_t::mux_output2 */
#define TIVX_VPAC_CUC_VISS_MUX2_VALUE8     (3U)
/*! \see tivx_vpac_cuc_isp_params_t::mux_output2 */
#define TIVX_VPAC_CUC_VISS_MUX2_NV12       (4U)
/*! \see tivx_vpac_cuc_isp_params_t::mux_output2 */
#define TIVX_VPAC_CUC_VISS_MUX2_YUV422     (5U)

/*! \see tivx_vpac_cuc_isp_params_t::mux_output3 */
#define TIVX_VPAC_CUC_VISS_MUX3_UV8        (0U)
/*! \see tivx_vpac_cuc_isp_params_t::mux_output3 */
#define TIVX_VPAC_CUC_VISS_MUX3_GREEN      (1U)
/*! \see tivx_vpac_cuc_isp_params_t::mux_output3 */
#define TIVX_VPAC_CUC_VISS_MUX3_C3         (2U)

/*! \see tivx_vpac_cuc_isp_params_t::mux_output4 */
#define TIVX_VPAC_CUC_VISS_MUX4_BLUE       (1U)
/*! \see tivx_vpac_cuc_isp_params_t::mux_output4 */
#define TIVX_VPAC_CUC_VISS_MUX4_C4         (2U)
/*! \see tivx_vpac_cuc_isp_params_t::mux_output4 */
#define TIVX_VPAC_CUC_VISS_MUX4_SAT        (3U)

#define TIVX_VPAC_CUC_VISS_M2M_CH          (-1)
#define TIVX_VPAC_CUC_VISS_MAX_CH          (7)

/* !!! this should be in sync with VHWA_M2M_VISS_MAX_HANDLES */
#define TIVX_VPAC_CUC_VISS_MAX_CTX         (7)

#define TIVX_VPAC_CUC_RC_MAX_CONFIGS             (10U)
#define TIVX_VPAC_CUC_RC_MAX_CONFIG_NAME_LEN     (64U)


/*********************************
 *   VPAC CUC RC Control Commands
 *********************************/

/*! \brief Control Command to verify input buffer's control value
 */
#define TIVX_VPAC_CUC_RC_CMD_VERIFY_BUFFER  0x10000002u

/*********************************
 *      VPAC_VISS STRUCTURES
 *********************************/

typedef struct {
    char context_name[TIVX_VPAC_CUC_RC_MAX_CONFIG_NAME_LEN];
    char configs[TIVX_VPAC_CUC_RC_MAX_CONFIGS][TIVX_VPAC_CUC_RC_MAX_CONFIG_NAME_LEN];
} rc_settings;

/*!
 * \brief The configuration data structure used by the TIVX_KERNEL_VISS kernel.
 *
 *  \details Below table provides output format supported on different
 *  outputs for the corresponding mux value in this structure.
 *  Note that mux value is used only if the corresponding output
 *  image is set to non-null. Otherwise mux value is ignored.
 *
 *  |val|  mux_output0   |   mux_output1  |   mux_output2  |   mux_output3  |   mux_output4   |
 *  |:-:|:--------------:|:--------------:|:--------------:|:--------------:|:---------------:|
 *  | 0 |  Y12(P12/U16)  | UV12(P12/U16)  |     Y8(U8)     |   UV8(P12/U16) |     Invalid     |
 *  | 1 |     Invalid    |     Invalid    |     R8(U8)     |     G8(U8)     |     B8(U8)      |
 *  | 2 |     Invalid    |  C1(P12/U16)   |  C2(P12/U16)   |  C3(P12/U16)   |  C4(P12/U16)    |
 *  | 3 | Value(P12/U16) |     Invalid    |    Value(U8)   |     Invalid    |  Saturation(U8) |
 *  | 4 |    NV12_P12    |     Invalid    |      NV12      |     Invalid    |     Invalid     |
 *  | 5 |     Invalid    |     Invalid    |     YUV422     |     Invalid    |     Invalid     |
 *
 * \ingroup group_vision_function_vpac_viss
 */
typedef struct {
    /*!  */
    uint32_t    sensor_id;

    /*! Mux to select the output format for the \a output0 parameter of \ref tivxVpacVissNode.
     *
     *  Valid values for this mux are:
     *  |          Enum                       |   Description                                  |
     *  |:------------------------------------|:-----------------------------------------------|
     *  | \ref TIVX_VPAC_CUC_VISS_MUX0_Y12        | Luma 12bit output either in U16 or P12 format  |
     *  | \ref TIVX_VPAC_CUC_VISS_MUX0_VALUE12    | Value output form the HSV module either in U16 or P12 format  |
     *  | \ref TIVX_VPAC_CUC_VISS_MUX0_NV12_P12   | NV12 output format in P12 format.              |
     *
     *  \note If this mux is set to \ref TIVX_DF_IMAGE_NV12_P12, output1
     *  must be disabled and \ref mux_output1 is ignored.
     */
    uint32_t        mux_output0;

    /*! Mux to select the output format for the \a output1 parameter of \ref tivxVpacVissNode.
     *
     *  Valid values for this mux are:
     *  |          Enum                       |   Description                                   |
     *  |:------------------------------------|:------------------------------------------------|
     *  | \ref TIVX_VPAC_CUC_VISS_MUX1_UV12       | Chroma 12bit output either in U16 or P12 format |
     *  | \ref TIVX_VPAC_CUC_VISS_MUX1_C1         | C1 output from CFA either in U16 or P12 format  |
     *
     *  \note This mux is ignored if output0 is set to output NV12 data.
     */
    uint32_t        mux_output1;

    /*! Mux to select the output format for the \a output2 parameter of \ref tivxVpacVissNode.
     *
     *  Valid values for this mux are:
     *  |          Enum                       |   Description                                  |
     *  |:------------------------------------|:-----------------------------------------------|
     *  | \ref TIVX_VPAC_CUC_VISS_MUX2_Y8         | Luma in U8 format                              |
     *  | \ref TIVX_VPAC_CUC_VISS_MUX2_RED        | Red color component in U8 format               |
     *  | \ref TIVX_VPAC_CUC_VISS_MUX2_C2         | C2 output from CFA either in U16 or P12 format |
     *  | \ref TIVX_VPAC_CUC_VISS_MUX2_VALUE8     | Value output form the HSV module in U8 format  |
     *  | \ref TIVX_VPAC_CUC_VISS_MUX2_NV12       | NV12 output format in 8bit format              |
     *  | \ref TIVX_VPAC_CUC_VISS_MUX2_YUV422     | YUV422 interleaved in UYVY or YUYV format      |
     *
     *  \note If this mux is set to VX_DF_IMAGE_NV12 or
     *  VX_DF_IMAGE_YUYV or VX_DF_IMAGE_UYVY, output3
     *  must be disabled by passing NULL to output3 input parameter
     *  and \ref mux_output3 is ignored.
     *  Also if the output0 is selected for NV12_P12 format, output2
     *  cannot be YUV422 (UYVY or YUYV).
     */
    uint32_t        mux_output2;

    /*! Mux to select the output format for the \a output3 parameter of \ref tivxVpacVissNode.
     *
     * Valid values for this mux are:
     *  |          Enum                       |   Description                                  |
     *  |:------------------------------------|:-----------------------------------------------|
     *  | \ref TIVX_VPAC_CUC_VISS_MUX3_UV8        | Chroma in U8 format                            |
     *  | \ref TIVX_VPAC_CUC_VISS_MUX3_GREEN      | Green color component in U8 format             |
     *  | \ref TIVX_VPAC_CUC_VISS_MUX3_C3         | C3 output from CFA either in U16 or P12 format |
     *
     *  \note This mux is ignored if output2 is set to output NV12 data.
     */
    uint32_t        mux_output3;

    /*! Mux to select the output format for the \a output4 parameter of \ref tivxVpacVissNode.
     *
     * Valid values for this mux are:
     *  |          Enum                       |   Description                                  |
     *  |:------------------------------------|:-----------------------------------------------|
     *  | \ref TIVX_VPAC_CUC_VISS_MUX4_BLUE       | Blue color component in U8 format              |
     *  | \ref TIVX_VPAC_CUC_VISS_MUX4_C4         | C4 output from CFA either in U16 or P12 format |
     *  | \ref TIVX_VPAC_CUC_VISS_MUX4_SAT        | Saturation from HSV module in U8 format        |
     */
    uint32_t        mux_output4;

    /*! Identifier for camera channel ID.
     */
    int32_t         channel_id;

    /*! Identifier for ISP context ID.
     */
    int32_t         context_id;

    /*! isp-rc initialization parameters.
     */
    rc_settings     rc_prms;

    /*! Enable dma TR list submission quirk.
     *  This prevent timeout on bus access in CSI (teared frames).
     *  This quirk has significant performace penalty, so snould be used only
     *  when necessary.
     **/
    uint32_t        enable_dma_quirk;

    /*! Test pattern settings.
     */
    uint32_t        test_pattern;
} tivx_vpac_cuc_isp_params_t;

typedef struct {
    uint8_t        rc_data[TIVX_VPAC_CUC_RC_TRACE_DATA_NUMBYTES];
    uint32_t       rc_data_size;
    uint8_t        h3a_data[TIVX_VPAC_CUC_VISS_MAX_H3A_STAT_NUMBYTES];
    uint32_t       h3a_data_size;
} tivx_vpac_cuc_isp_trace_t;

typedef struct {
    uint16_t ctlval;
    uint16_t group_id;		/* for requests coming for the same frame to different vpac_cuc instances,
				   this field is the same */
} tivx_vpac_cuc_isp_verify_buffer_data_t;

/*********************************
 *      Function Prototypes
 *********************************/

/*!
 * \brief Function to register HWA Kernels on the vpac_viss Target
 * \ingroup group_vision_function_vpac_viss
 */
void tivxRegisterHwaTargetVpacCucIspKernels(void);

/*!
 * \brief Function to un-register HWA Kernels on the vpac_viss Target
 * \ingroup group_vision_function_vpac_viss
 */
void tivxUnRegisterHwaTargetVpacCucIspKernels(void);

/*! \brief [Graph] Creates a VPAC_VISS Node.
 *
 * At a high level, VPAC VISS converts RAW image sensor data into
 * processed YUV or RGB images.
 *
 * VISS node supports 5 optional outputs (output0 to output4),
 * and at least one of the outputs must be enabled.
 *
 * The resolution of all the image ports should have the same width
 * and height. The only exception to this is if the
 * output1 and/or output3 is used to output chroma alone by selecting
 * appropriate tivx_vpac_cuc_isp_params_t::mux_output1 and
 * tivx_vpac_cuc_isp_params_t::mux_output3, then the height is
 * half of the input for these 2 ports if the tivx_vpac_cuc_isp_params_t::chroma_mode is
 * selected as TIVX_VPAC_CUC_VISS_CHROMA_MODE_420.
 *
 * \param [in] graph The reference to the graph.
 * \param [in] configuration             The input object of a single params structure of type
 *                                       <tt>\ref tivx_vpac_cuc_isp_params_t</tt>.
 *                                       These parameters essentially defines path inside
 *                                       VISS and are used to select output format.
 * \param [in] raw                       The RAW input image (can contain up to 3 exposures
 *                                       plus meta data) in P12 or U16 or U8 format.
 *                                       RAW Image at index 0 is used for single exposure
 *                                          processing and also for Linear mode processing.
 *                                       For two exposure WDR merge mode, RAW Image at
 *                                          index 0 is used for short exposure and image
 *                                          at index1 is used for long exposure.
 *                                       For three exposure WDR merge mode, RAW Image at
 *                                          index 0 is used for very short exposure,
 *                                          image at index1 for short exposure and image
 *                                          at index2 for long exposure.
 * \param [out] output0 (optional)       Output0 for 12bit output.
 *                                       Typically this output is used to get
 *                                          YUV420 frame in 12bit format, or
 *                                          Luma plane of the YUV420 frame or
 *                                          Value from the HSV module
 *                                        <tt>\ref tivx_vpac_cuc_isp_params_t::mux_output0</tt>
 *                                          is used to select the output format when
 *                                          data format is set to U16 or P12
 *                                       Supported image format are
 *                                          <tt>\ref VX_DF_IMAGE_U16</tt>
 *                                          <tt>\ref TIVX_DF_IMAGE_P12</tt>
 *                                          <tt>\ref TIVX_DF_IMAGE_NV12_P12</tt>.
 * \param [out] output1 (optional)       Output1 for 12bit output.
 *                                       Typically this output is used to get
 *                                          Chroma plane of YUV420 frame in 12bit format or
 *                                          One of the CFA output  in 12bit format
 *                                        <tt>\ref tivx_vpac_cuc_isp_params_t::mux_output1</tt>
 *                                          is used to select the output format
 *                                       Supported image format are
 *                                          <tt>\ref VX_DF_IMAGE_U16</tt>
 *                                          <tt>\ref TIVX_DF_IMAGE_P12</tt>
 *                                       can be enabled only when output0 is not set
 *                                          to YUV420 output format.
 * \param [out] output2  (optional)      Output2 for 12bit or 8bit output.
 *                                       Typically this output is used to get
 *                                          YUV420 frame in 8bit format or
 *                                          Luma portion of the YUV420 frame in 8bit or
 *                                          Red color plane in 8bit or
 *                                          YUV422 (YUYV or UYVY) in 8bit format or
 *                                          One of the color output CFA in 12bit or
 *                                          Value output from HSV module in 8bit
 *                                        <tt>\ref tivx_vpac_cuc_isp_params_t::mux_output2</tt>
 *                                          is used to select the output format when
 *                                          data format is set to U8 or U16 or P12
 *                                       Supported image format are
 *                                          <tt>\ref VX_DF_IMAGE_U8</tt>
 *                                          <tt>\ref VX_DF_IMAGE_U16</tt>
 *                                          <tt>\ref TIVX_DF_IMAGE_P12</tt>
 *                                          <tt>\ref VX_DF_IMAGE_NV12</tt>
 *                                          <tt>\ref VX_DF_IMAGE_YUYV</tt>
 *                                          <tt>\ref VX_DF_IMAGE_UYVY</tt>
 * \param [out] output3  (optional)      Output2 for 12bit or 8bit output.
 *                                       Typically this output is used to get
 *                                          Chroma portion of the YUV420 frame or
 *                                          One of the color output CFA in 12bit
 *                                        <tt>\ref tivx_vpac_cuc_isp_params_t::mux_output3</tt>
 *                                          is used to select the output format.
 *                                       Supported image format are
 *                                          <tt>\ref VX_DF_IMAGE_U8</tt>
 *                                          <tt>\ref VX_DF_IMAGE_U16</tt>
 *                                          <tt>\ref TIVX_DF_IMAGE_P12</tt>
 *                                       can be enabled only when output2 is not set
 *                                          to YUV420/UYVY/YUYV output formats.
 * \param [out] output4  (optional)      Output2 for 12bit or 8bit output.
 *                                       Typically this output is used to get
 *                                          Saturation from HSV block in 8bit or
 *                                          One of the color output CFA in 12bit
 *                                        <tt>\ref tivx_vpac_cuc_isp_params_t::mux_output4</tt>
 *                                          is used to select the output format.
 *                                       Supported image format are
 *                                          <tt>\ref VX_DF_IMAGE_U8</tt>
 *                                          <tt>\ref VX_DF_IMAGE_U16</tt>
 *                                          <tt>\ref TIVX_DF_IMAGE_P12</tt>
 *
 * \see <tt>TIVX_KERNEL_VPAC_CUC_VISS_NAME</tt>
 *
 * \ingroup group_vision_function_vpac_viss
 *
 * \return <tt>\ref vx_node</tt>.
 *
 * \retval vx_node A node reference.
 *         Any possible errors preventing a successful creation should
 *         be checked using <tt>\ref vxGetStatus</tt>
 */
VX_API_ENTRY vx_node VX_API_CALL tivxVpacCucVissNode(vx_graph  graph,
                                      vx_user_data_object   configuration,
                                      tivx_raw_image        raw,
                                      vx_image              output0,
                                      vx_image              output1,
                                      vx_image              output2,
                                      vx_image              output3,
                                      vx_image              output4);

/*!
 * \brief Function to initialize COGENT_ISP Parameters
 *
 * \param prms  [in] Pointer to COGENT_ISP parameters
 *
 * \ingroup group_vision_function_vpac_viss
 */
void tivx_vpac_cuc_isp_params_init(tivx_vpac_cuc_isp_params_t *prms);


/*!
 * \file
 * \brief The cogent_isp kernels in this kernel extension.
 */

/*! \brief cogent_isp kernel name
 *  \ingroup group_vision_function_cogent_isp
 */
#define TIVX_KERNEL_VPAC_CUC_RC_NAME     "com.ti.hwa.vpac_cuc_rc"

/*********************************
 *      Function Prototypes
 *********************************/

VX_API_ENTRY vx_node VX_API_CALL tivxVpacCucRcNode(vx_graph graph,
                                              vx_user_data_object config,
                                              tivx_raw_image raw,
                                              vx_user_data_object trace);



#ifdef __cplusplus
}
#endif

#endif /* J7_VPAC_CUC_VISS_H_ */
