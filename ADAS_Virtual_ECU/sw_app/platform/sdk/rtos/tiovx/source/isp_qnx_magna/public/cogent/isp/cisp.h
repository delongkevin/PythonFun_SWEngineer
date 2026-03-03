/*!
 *  @file       Cisp.h
 *  @brief      ISP driver for V3x (API)
 *  @date       2019/Jan/23 latest update
 *  @author     A. Lanari
 *  @version    2.1.0
 *  @par        history
 *  @note
 */

/*! \mainpage ISP pipeline
 * @image html pics/isp_pipeline.png
 */

#ifndef CISP_H
#define CISP_H

#ifdef __cplusplus
extern "C" {
#endif

/* All the functions of the API must use the following error codes to signal an error condition */
#define CISP_RET_E_OK                         (0U)    /*!< OK: Execution successful */
#define CISP_RET_ERR_WRONG_ARGUMENTS          (101U)  /*!< Error: Parameter error */
#define CISP_RET_ERR_WRONG_READDATA           (102U)  /*!< Error: Wrong data that read out from register */
#define CISP_RET_ERR_REGBASEADDR              (103U)  /*!< Error: Register base address corrupted to invalid base address */
#define CISP_RET_ERR_STATE_WRONGSEQUENCE      (104U)  /*!< Error: Sequence error in CISP state machine flow (for state machine APIs) */
#define CISP_RET_ERR_OPERATION_WRONGSTATE     (105U)  /*!< Error: Operation initiated in wrong state (APIs except state machine APIs)*/
#define CISP_RET_ERR_DRYRUN_WRONG_HWUNIT      (106U)  /*!< Error: Wrong HW unit number in dry run. Only unit 0 supported in dry run */
#define CISP_RET_ERR_FRABORT_SLOTSEARCH       (107U)  /*!< Error: FrameAbort: Searching for a slot to abort */
#define CISP_RET_ERR_FRABORT_SLOT_NOT_CANCEL  (108U)  /*!< Error: FrameAbort: Error in cancelling the current slot */
#define CISP_RET_ERR_CONTEXT_NOT_INIT         (110U)  /*!< Error: Context not initialized */
#define CISP_RET_ERR_INPUTPORT_NOT_START      (111U)  /*!< Error: Input port mode request not equal to mode status for start */
#define CISP_RET_ERR_INPUTPORT_NOT_STOP       (112U)  /*!< Error: Input port mode request not equal to mode status for stop */

#define ISP_TOTAL_NUM_OF_VCH        (4U)    /*!< Number of virtual channels */
#define ISP_TOTAL_NUM_OF_CTX        (7U)    /*!< Number of ISP context (contexts+hw) */
#define ISP_TOTAL_NUM_OF_EV         (3U)    /*!< Number of Events available */
#define ISP_TOTAL_NUM_OF_INP        (4U)    /*!< Number of Inputs available */
#define ISP_TOTAL_NUM_OF_OUTPUT     (3U)    /*!< Number of Outputs available (excluded the consistency plane) */
#define ISP_TOTAL_NUM_OF_OUT        (4U)    /*!< Number of Outputs available */
#define ISP_TOTAL_NUM_OF_SLOTS      (6U)    /*!< Number of Slots available */

#define ISP_RAW_BUFFER_NUM          (10U)   /*!< Number of RAW buffers available */
#define ISP_OUT_BUFFER_NUM          (32U)   /*!< Number of Output buffers available */

#define ISP_GAMMA_FE_LUT_SIZE       (4096U + 1U) /*!< Gamma Frontend Number of entries. */
#define ISP_RAWFE_NP_LUT_SIZE       (128U)  /*!< RAW Frontend Noise Profile LUT size */
#define ISP_SINT_NP_LUT_SIZE        (128U)  /*!< Sinter Noise Profile LUT size */
#define ISP_SINT_RS_LUT_SIZE        (33U)   /*!< Sinter Radial Shading LUT size */
#define ISP_CA_CORR_LUT_SIZE        (8192U) /*!< Chromatic Aberration correction Number of entries. */
#define ISP_CA_FILT_LUT_SIZE        (32U)   /*!< Chromatic Aberration filter Number of entries. */
#define ISP_GAMMA_BE_LUT0_SIZE      (32U + 1U)   /*!< Gamma Backend LUT0 size */
#define ISP_GAMMA_BE_LUT1_SIZE      (256U + 1U)  /*!< Gamma Backend LUT1 size */
#define ISP_RAD_SHAD_LUT_SIZE       (33U)   /*!< Radial Shading correction Number of entries. */
#define ISP_MESH_SHAD_LUT_SIZE      (4096U) /*!< Mesh Shading correction Number of entries. */
#define ISP_TM_GAMMA_LUT_SIZE       (129U)  /*!< Tone Mapping Gamma LUT number of entries */
#define ISP_TM_LTM_ASYM_LUT_SIZE    (65U)   /*!< Iridix Asymmetry LUT number of entries */
#define ISP_TM_GTM_LUT_SIZE         (33U)   /*!< Global Tone Mapping 2D LUT number of entries */
#define ISP_DPIX_TBL_SIZE           (1024U) /*!< Defect pixels Table size size */
#define ISP_OUTF_LUT_SIZE           (256U + 1U)  /*!< Output Formatter LUT number of entries. */
#define ISP_DEM_NP_LUT_SIZE         (128U)  /*!< Demosaic Noise Profile LUT size. */
#define ISP_UROI_NUM                (16U)   /*!< Number of Micro ROI available */
#define ISP_UROI_PIX_NUM            (256U)  /*!< Number of Micro ROI pixels collected */
#define ISP_ROI_HIST_NUM            (4U)    /*!< Number of ROI Histograms available */
#define ISP_HIST_NUM                (4U)    /*!< Number of Histograms available */
#define ISP_HIST_NUM_BINS           (1024U) /*!< Number of Histograms bins */
#define ISP_HIST_NUM_ZONES          (225U)  /*!< Max number of Histograms zones */
#define ISP_HIST_LUT_SIZE           (17U)   /*!< Histograms shading LUT elements */
#define ISP_AEXP_NUM_ZONES          (225U)  /*!< Max number of Exposure statistics zones */
#define ISP_AWB_NUM_ZONES           (225U)  /*!< Max number of White Point statistics zones */
#define ISP_AF_NUM_ZONES            (225U)  /*!< Max number of Antifog statistics zones */
#define ISP_AF_LUT_SIZE             (17U)   /*!< Antifog statistics LUT elements */
#define ISP_FAULT_STS_NUM           (13U)   /*!< Number of ISP fault registers */

#define ISP_SLOT_CFG_SIZE           (0x20000U) /*!< Slot configuration memory area size (131072 bytes) */

#define ISP_BUFFER_NOT_USED         (0x3FU) /*!< Mark buffer as not used */
#define ISP_INPUT_NOT_USED          (0x3FU) /*!< Mark input as not used */
#define ISP_OUTPUT_NOT_USED         (0x3FU) /*!< Mark output as not used */

/*! Context types */
#define ISP_SLOT0                   (0U) /*!< Slot 0 (can be accessed only after the slot memory area is configured) */
#define ISP_SLOT1                   (1U) /*!< Slot 1 (can be accessed only after the slot memory area is configured) */
#define ISP_SLOT2                   (2U) /*!< Slot 2 (can be accessed only after the slot memory area is configured) */
#define ISP_SLOT3                   (3U) /*!< Slot 3 (can be accessed only after the slot memory area is configured) */
#define ISP_SLOT4                   (4U) /*!< Slot 4 (can be accessed only after the slot memory area is configured) */
#define ISP_SLOT5                   (5U) /*!< Slot 5 (can be accessed only after the slot memory area is configured) */
#define ISP_HARDWARE                (6U) /*!< ISP hardware registers area */

/*! Events available */
typedef enum {
    ISP_FRAME_START_EV = 0u, /*!< Frame Start Event */
    ISP_FRAME_END_EV,        /*!< Frame End Event */
    ISP_STAT_EV              /*!< Statistic Ready Event */
} drvISP_EventType_t;

/*! Interrupt Events configuration */
typedef struct {
    UINT8  Enable;     /*!< Enable */
    UINT32 EventFlags; /*!< Event Flags */
} drvISP_EventIntCfg_t;

/*! ISP Faults */
typedef struct {
    UINT32 IspFault[ISP_FAULT_STS_NUM]; /*!< ISP Fault status */
} drvISP_Fault_t;

/*! Buffer configuration */
typedef struct {
    UINT64 BaseAddr;       /*!< Base address */
    UINT32 LineByteStride; /*!< Line offset (bytes) */
    UINT16 Width;          /*!< Width (pixel) */
    UINT16 Height;         /*!< Height (pixel) */
    UINT8 BitWidth;        /*!< Bit width */
} drvISP_BufCfg_t;

/*! Buffer status */
typedef enum {
    ISP_BUFF_EMPTY = 0u,      /*!< 0 - empty */
    ISP_BUFF_FILLED,          /*!< 1 - filled */
    ISP_BUFF_WRITING,         /*!< 2 - writing */
    ISP_BUFF_WRITE_CANCELING, /*!< 3 - write canceling */
    ISP_BUFF_READING,         /*!< 4 - reading */
    ISP_BUFF_READ_CANCELING,  /*!< 5 - read canceling */
    ISP_BUFF_READ_WRITE,      /*!< 6 - reading+writing */
    ISP_BUFF_CANCELLED        /*!< 7 - cancelled */
} drvISP_BufStatus_t;

/*! Frame check configuration */
typedef struct {
    UINT8 FieldMode;     /*!< Field mode (0=pulse; 1=edge) */
    UINT8 ManualTrigger; /*!< Manual triggering of the fault */
    UINT32 Width;        /*!< Expected active width (pixel) */
    UINT32 Height;       /*!< Expected active height (pixel) */
    UINT32 HblankMin;    /*!< Expected minimal horizontal blank */
    UINT32 HblankMax;    /*!< Expected maximal horizontal blank */
    UINT32 VblankMin;    /*!< Expected minimal vertical blank */
    UINT32 VblankMax;    /*!< Expected maximal vertical blank */
} drvISP_FrameChkCfg_t;

/*! Pipeline frame check configuration */
typedef struct {
    drvISP_FrameChkCfg_t Output[ISP_TOTAL_NUM_OF_OUTPUT]; /*!< Output frame check (see #drvISP_FrameChkCfg_t) */
    drvISP_FrameChkCfg_t Isp;                             /*!< ISP frame check (see #drvISP_FrameChkCfg_t) */
    drvISP_FrameChkCfg_t Crop;                            /*!< Output formatter crop frame check (see #drvISP_FrameChkCfg_t) */
} drvISP_PipeFrameChkCfg_t;

/*! Module frame counter */
typedef struct {
    UINT8 Active;   /*!< Active video flag */
    UINT8 Overflow; /*!< Frame count */
    UINT32 Counter; /*!< Counter overflow flag */
} drvISP_ModFrameCnt_t;

/*! Frame counters data */
typedef struct {
    drvISP_ModFrameCnt_t Sensor[ISP_TOTAL_NUM_OF_INP];     /*!< Frame counter Sensor(n) */
    drvISP_ModFrameCnt_t ISP_Start;                        /*!< Frame counter ISP pipeline */
    drvISP_ModFrameCnt_t ISP_VTGP;                         /*!< Frame counter Video Test Pattern Generator */
    drvISP_ModFrameCnt_t ISP_Iridix;                       /*!< Frame counter Iridix */
    drvISP_ModFrameCnt_t ISP_Demosaic;                     /*!< Frame counter demosaic */
    drvISP_ModFrameCnt_t ISP_Out[ISP_TOTAL_NUM_OF_OUT];    /*!< Frame counter Out(n) */
    drvISP_ModFrameCnt_t ISP_AxiOut[ISP_TOTAL_NUM_OF_OUT]; /*!< Frame counter AXI Out(n) */
    drvISP_ModFrameCnt_t ISP_AxiPc;                        /*!< Frame counter  */
} drvISP_FrameCntData_t;

/*! Output modes */
typedef enum {
    ISP_AXI_OFF = 0u,        /*!< AXI Output Off */
    ISP_AXI_RGB_R14,         /*!< RBG - R Unit 14bpp */
    ISP_AXI_RGB_G14,         /*!< RBG - G Unit 14bpp */
    ISP_AXI_RGB_B14,         /*!< RBG - B Unit 14bpp */
    ISP_AXI_YUV_Y12,         /*!< YUV - Y Unit 12bpp (only on mux A2, otherwise 14bpp) */
    ISP_AXI_YUV_U12,         /*!< YUV - U Unit 12bpp */
    ISP_AXI_YUV_V12,         /*!< YUV - V Unit 12bpp */
    ISP_AXI_YUV_UV8,         /*!< YUV - UV Units 8bpp */
    ISP_AXI_YUV_VU8,         /*!< YUV - VU Units 8bpp */
    ISP_AXI_S8,              /*!< HS - S Unit 8bpp */
    ISP_AXI_HS88,            /*!< HS - HS Units 8bpp */
    ISP_AXI_LUV_L12,         /*!< LUV - L Unit 12bpp (only on mux A1, otherwise 14bpp) */
    ISP_AXI_LUV_UV8,         /*!< LUV - UV Units 8bpp */
    ISP_AXI_IR12,            /*!< Ir - Ir Unit 12bpp */
    ISP_AXI_IR8,             /*!< Ir - Ir Unit 8bpp */
    ISP_AXI_RGB888,          /*!< RGB - RGB Units 8bpp */
    ISP_AXI_LUV_U12,         /*!< LUV - U Unit 12bpp */
    ISP_AXI_LUV_V12,         /*!< LUV - V Unit 12bpp */
    ISP_AXI_S12,             /*!< HS - S Unit 12bpp */
    ISP_AXI_HS_H12,          /*!< HS - H Unit 12bpp */
    ISP_AXI_HS_S12,          /*!< HS - S Unit 12bpp */
    ISP_AXI_SH88,            /*!< HS - HS Units 8bpp */
    ISP_AXI_LUV_VU8,         /*!< LUV - VU Units 8bpp */
    ISP_AXI_RAW_data8 = 24u, /*!< RAW - RAW/8 8bpp */
    ISP_AXI_RAW_data10,      /*!< RAW - RAW/10 dense 10bpp */
    ISP_AXI_RAW_data12,      /*!< RAW - RAW/12 12bpp */
    ISP_AXI_RAW_data16,      /*!< RAW - RAW/16 16bpp */
    ISP_AXI_RAW_full = 30u,  /*!< RAW - RAW/24 dense 24bpp */
} drvISP_OutMode_t;

/*! Output configuration (AXI and Output Streaming) */
typedef struct {
    UINT8 Data_Width[3];             /*!< Output Data Width Unit n:<br>
                                          0: channel 0<br>
                                          1: channel 1<br>
                                          2: channel 2 */
    drvISP_OutMode_t Mode_Select[3]; /*!< Output Mode Unit n:<br>
                                          0: channel 0<br>
                                          1: channel 1<br>
                                          2: channel 2 */
    UINT8 Msb_Align[3];              /*!< Output MSB Align Unit n (0=LBS, 1=MSB):<br>
                                          0: channel 0<br>
                                          1: channel 1<br>
                                          2: channel 2 */
} drvISP_OutCfg_t;

/*! Hardware Crossbar mode */
typedef enum {
   ISP_INPUT_MODE_DIRECT = 0u,
   ISP_INPUT_MODE_FILTER_ID
} drvISP_InputMode_t;

/*! Hardware Crossbar configuration */
typedef struct {
    drvISP_InputMode_t Mode; /*!< Input mode (see #drvISP_InputMode_t) */
    UINT32 Source;           /*!< Camera source index (0-3) */
    UINT32 MipiId;           /*!< Id of the virtual Mipi channel (only for ISP_INPUT_MODE_FILTER_ID mode) */
} drvISP_InputCfg_t;

/*! Hardware MCFE Input caching mode */
typedef enum {
    ISP_BUFFER_MODE_FIFO = 0u, /*!< Direct through FIFO */
    ISP_BUFFER_MODE_PART_FB,   /*!< Partial delay through frame buffer */
    ISP_BUFFER_MODE_FULL_FB    /*!< Full frame write for TDMF */
} drvISP_BufferMode_t;

/*! Hardware MCFE Input caching configuration */
typedef struct {
    drvISP_BufferMode_t Mode; /*!< Input caching mode */
    UINT32 DataWidth;         /*!< Number of bits per pixel */
    UINT32 RawBuffer[2];      /*!< RAW buffers index (unused for FIFO mode) */
} drvISP_BufferCfg_t;

/*! Hardware Input Port mode */
typedef enum {
    ISP_FRAME_MODE_AUTO = 0u, /*!< The frame size is determined by FV and HV signals encapsulating the active video */
    ISP_FRAME_MODE_WINDOW,    /*!< As in ISP_FRAME_MODE_AUTO but the active frame can be windowed */
    ISP_FRAME_MODE_CUSTOM     /*!< Custom setting is used (see #drvISP_CustomCfg) */
} drvISP_FrameMode_t;

/*! Custom Hardware Input Port timings */
typedef struct {
    UINT8 VS_use_field;    /*!< 0 = Use vsync_i port for vertical sync <br>1 = Use field_i port for vertical sync */
    UINT8 VS_toggle;       /*!< 0 = vsync is pulse-type<br>1 = vsync is toggle-type (field signal)*/
    UINT8 VS_polarity;     /*!< 0 = horizontal counter reset on rising edge<br>1 = horizontal counter reset on falling edge */
    UINT8 VS_polarity_acl; /*!< 0 = don't invert polarity for ACL gate<br>1 = invert polarity for ACL gate */
    UINT8 HS_use_acl;      /*!< 0 = use hsync_i port for active-line<br>1 = use acl_i port for active-line */
    UINT8 VC_C_select;     /*!< 0 = vertical counter counts on hs<br>1 = vertical counter counts on horizontal counter overflow or reset */
    UINT8 VC_R_select;     /*!< 0 = vertical counter is reset on edge of vs<br>1 = vertical counter is reset after timeout on hs */
    UINT8 HS_xor_VS;       /*!< 0 = normal mode<br>1 = hvalid = hsync XOR vsync */
    UINT8 HS_polarity;     /*!< 0 = don't invert polarity of HS for ACL gate<br>1 = invert polarity of HS for ACL gate */
    UINT8 HS_polarity_acl; /*!< 0 = don't invert polarity of HS for HS gate<br>1 = invert polarity of HS for HS gate */
    UINT8 HS_polarity_hs;  /*!< 0 = horizontal counter is reset on rising edge of hs<br>1 = horizontal counter is reset on vsync (e.g. when hsync is not available) */
    UINT8 HS_polarity_vc;  /*!< 0 = vertical counter increments on rising edge of HS<br>1 = vertical counter increments on falling edge of HS */
    UINT8 HC_R_select;     /*!< 0 = vertical counter is reset on rising edge of hs<br>1 = vertical counter is reset on rising edge of vs */
    UINT8 Acl_polarity;    /*!< 0 = don't invert acl_i for acl gate<br>1 = invert acl_i for acl gate */
    UINT8 Field_polarity;  /*!< 0 = don't invert field_i for field gate<br>1 = invert field_i for field gate */
    UINT8 Field_toggle;    /*!< 0 = field is pulse-type<br>1 = field is toggle-type */
    UINT8 Aclg_window0;    /*!< 0 = exclude window0 signal in ACL gate<br>1 = include window0 signal in ACL gate */
    UINT8 Aclg_HSync;      /*!< 0 = exclude hsync signal in ACL gate<br>1 = include hsync signal in ACL gate */
    UINT8 Aclg_window2;    /*!< 0 = exclude window2 signal in ACL gate<br>1 = include window2 signal in ACL gate */
    UINT8 Aclg_acl;        /*!< 0 = exclude acl_i signal in ACL gate<br>1 = include acl_i signal in ACL gate */
    UINT8 Aclg_vsync;      /*!< 0 = exclude vsync signal in ACL gate<br>1 = include vsync signal in ACL gate */
    UINT8 HSg_window1;     /*!< 0 = exclude window1 signal in HS gate<br>1 = include window1 signal in HS gate */
    UINT8 HSg_hsync;       /*!< 0 = exclude hsync signal in HS gate<br>1 = include hsync signal in HS gate */
    UINT8 HSg_vsync;       /*!< 0 = exclude vsync signal in HS gate<br>1 = include vsync signal in HS gate */
    UINT8 HSg_window2;     /*!< 0 = exclude window2 signal in HS gate<br>1 = include window2 signal in HS gate (mask out spurious hs during blank) */
    UINT8 Fieldg_vsync;    /*!< 0 = exclude vsync signal in Field gate<br>1 = include vsync signal in Field gate */
    UINT8 Fieldg_window2;  /*!< 0 = exclude window2 signal in Field gate<br>1 = include window2 signal in Field gate */
    UINT8 Fieldg_field;    /*!< 0 = exclude field_i signal in Field gate<br>1 = include field_i signal in Field gate */
    UINT8 Field_mode;      /*!< 0 = pulse field<br>1 = toggle field */
} drvISP_CustomCfg;

/*! Hardware Input Port configuration */
typedef struct {
    drvISP_FrameMode_t Mode; /*!< Select the routing mode (see #drvISP_FrameMode_t) */
    UINT16 StartX;           /*!< Active Frame start column (unused with ISP_FRAME_MODE_AUTO mode) */
    UINT16 StartY;           /*!< Active Frame start row (unused with ISP_FRAME_MODE_AUTO mode) */
    UINT16 SizeX;            /*!< Active Frame width (unused with ISP_FRAME_MODE_AUTO mode) */
    UINT16 SizeY;            /*!< Active Frame height (unused with ISP_FRAME_MODE_AUTO mode) */
    drvISP_CustomCfg Custom; /*!< Custom timing settings (see #drvISP_CustomCfg) */
} drvISP_FrameCfg_t;

/*! Statistic collected at Hardware Input Port configuration */
typedef struct {
    UINT64 BaseAddr;  /*!< Base address of the statistics memory area */
    UINT32 Size;      /*!< Size of the statistics memory area */
    UINT32 ReadUnits; /*!< Bitmap of statistics chunks to be transferred from ISP to RAM in the moment they are available */
} drvISP_StatCfg_t;

/*! Input Port configuration */
typedef struct {
    UINT8 Enable;               /*!< Enable port */
    drvISP_InputCfg_t Input;    /*!< Input configuration */
    drvISP_BufferCfg_t Buffer;  /*!< Buffering configuration */
    drvISP_FrameCfg_t Frame;    /*!< Frame configuration */
    drvISP_StatCfg_t Statistic; /*!< Histogram collection configuration */
} drvISP_InputPortCfg_t;

/*! MCFE Slot mode */
typedef enum {
    ISP_MCFE_SLOT_OFF       = 0u, /*!< Inactive */
    ISP_MCFE_SLOT_PASSTHR   = 1u, /*!< Pass through, including sub-frame delay through AXI. slot_delay is added after frame finished before processing the next frame */
    ISP_MCFE_SLOT_TDMF_FIX  = 2u, /*!< TDMF fixed. Slot_event is input to sync, processing will start after slot_delay) */
    ISP_MCFE_SLOT_TDMF_FLEX = 3u, /*!< TDMF flex slot. Also test context if no inputs are assigned. */
    ISP_MCFE_SLOT_RAM_INPUT = 4u, /*!< Frame and/or config from RAM source. Trigger TPG if no inputs are assigned.<br>
                                      Effectively one-shot mode with any combination of upload config, feed frame, download config.<br>
                                      Triggered by changing start_slot from 0xF to slot number */
    ISP_MCFE_SLOT_CONF_TM   = 5u, /*!< Config transfer mode. Effectively one-shot mode with any combination of upload config and download config.<br>
                                      Triggered by changing start_slot from -1 to slot number */
    ISP_MCFE_SLOT_CLEAR_ERR = 6u, /*!< Cancel and clear errors */
} drvISP_McfeSlotMode_t;

/*! Bitmap of configuration chunks */
typedef enum {
    ISP_AP_R_Metering_histogram1  = 0x00000001u, /*!< Address range 0x08000-0x0881F Size (bytes) 2080<br>
                                                      Address range 0x0F108-0x0F12F Size (bytes) 40 */
    ISP_AP_R_Metering_histogram2  = 0x00000002u, /*!< Address range 0x08820-0x0903F Size (bytes) 2080<br>
                                                      Address range 0x0F288-0x0F2AF Size (bytes) 40 */
    ISP_AP_R_Metering_histogram3  = 0x00000004u, /*!< Address range 0x09040-0x0985F Size (bytes) 2080<br>
                                                      Address range 0x0F408-0x0F42F Size (bytes) 40 */
    ISP_AP_R_Metering_histogram4  = 0x00000008u, /*!< Address range 0x09860-0x0A07F Size (bytes) 2080<br>
                                                      Address range 0x0F588-0x0F5AF Size (bytes) 40 */
    ISP_AP_R_Antifog_histogram    = 0x00000010u, /*!< Address range 0x0A080-0x0A89F Size (bytes) 2080<br>
                                                      Address range 0x0EF88-0x0EFAF Size (bytes) 40 */
    ISP_AP_R_ROI_histogram1       = 0x00000020u, /*!< Address range 0x0A8A0-0x0B0Bf Size (bytes) 2080<br>
                                                      Address range 0x0F708-0x0F72F Size (bytes) 40 */
    ISP_AP_R_ROI_histogram2       = 0x00000040u, /*!< Address range 0x0B0C0-0x0B8DF Size (bytes) 2080<br>
                                                      Address range 0x0F788-0x0F7AF Size (bytes) 40 */
    ISP_AP_R_ROI_histogram3       = 0x00000080u, /*!< Address range 0x0B8E0-0x0C0FF Size (bytes) 2080<br>
                                                     Address range 0x0F808-0x0F82F Size (bytes) 40 */
    ISP_AP_R_ROI_histogram4       = 0x00000100u, /*!< Address range 0x0C100-0x0C91F Size (bytes) 2080<br>
                                                      Address range 0x0F888-0x0F8AF Size (bytes) 40 */
    ISP_AP_R_Metering_AE          = 0x00000200u, /*!< Address range 0x0D000-0x0D73F Size (bytes) 1856<br>
                                                      Address range 0x0EDA0-0x0EDAF Size (bytes) 16 */
    ISP_AP_R_Metering_AWB         = 0x00000400u, /*!< Address range 0x0D740-0x0DE7F Size (bytes) 1856<br>
                                                      Address range 0x0EDE0-0x0EDEB Size (bytes) 12 */
    ISP_AP_R_Micro_ROI            = 0x00000800u, /*!< Address range 0x04000-0x0603F Size (bytes) 8256 */
    ISP_AP_R_ISP_statistics       = 0x00001000u, /*!< Address range 0x00680-0x006BF Size (bytes) 64<br>
                                                      Address range 0x0EBA0-0x0EBE7 Size (bytes) 72<br>
                                                      Address range 0x0F108-0x0F12F Size (bytes) 40<br>
                                                      Address range 0x0F288-0x0F2AF Size (bytes) 40<br>
                                                      Address range 0x0F408-0x0F42F Size (bytes) 40<br>
                                                      Address range 0x0F588-0x0F5AF Size (bytes) 40<br>
                                                      Address range 0x0EF88-0x0EFAF Size (bytes) 40<br>
                                                      Address range 0x0F708-0x0F72F Size (bytes) 40<br>
                                                      Address range 0x0F788-0x0F7AF Size (bytes) 40<br>
                                                      Address range 0x0F808-0x0F22F Size (bytes) 40<br>
                                                      Address range 0x0F888-0x0F8AF Size (bytes) 40<br>
                                                      Address range 0x0EDA0-0x0EDAF Size (bytes) 16<br>
                                                      Address range 0x0EDE0-0x0EDEB Size (bytes) 12<br>
                                                      Address range 0x0E084-0x0E097 Size (bytes) 20<br> */
    ISP_AP_RW_ISP_setup           = 0x00002000u, /*!< Address range 0x0E000-0x0E75F Size (bytes) 1888<br>
                                                      Address range 0x0EB00-0x0EB9F Size (bytes) 160 */
    ISP_AP_RW_BIST                = 0x00004000u, /*!< Address range 0x0E000-0x0E07F Size (bytes) 128<br>
                                                      Address range 0x0E160-0x0E1BF Size (bytes) 96<br>
                                                      Address range 0x0EBF4-0x0EBFF Size (bytes) 12 */
    ISP_AP_RW_Global_tm           = 0x00008000u, /*!< Address range 0x0EC00-0x0ED5F Size (bytes) 352 */
    ISP_AP_RW_Metering            = 0x00010000u, /*!< Address range 0x0ED80-0x0EEFF Size (bytes) 384 */
    ISP_AP_RW_Micro_ROI_Config    = 0x00020000u, /*!< Address range 0x0EE00-0x0EEBF Size (bytes) 192 */
    ISP_AP_RW_Histogram_config    = 0x00040000u, /*!< Address range 0x0EF80-0x0F8FF Size (bytes) 2432 */
    ISP_AP_RW_Iridix_LUT          = 0x00080000u, /*!< Address range 0x0F900-0x0FA03 Size (bytes) 260<br>
                                                      Address range 0x12000-0x12203 Size (bytes) 516<br>
                                                      Address range 0x12400-0x12603 Size (bytes) 516 */
    ISP_AP_RW_Sinter_rm           = 0x00100000u, /*!< Address range 0x0FA40-0x0FA63 Size (bytes) 36 */
    ISP_AP_Noise_profiles         = 0x00200000u, /*!< Address range 0x0FA80-0x0FDFF Size (bytes) 896 */
    ISP_AP_RW_AE_AWB_AEXP_zones   = 0x00400000u, /*!< Address range 0x0FE00-0x0FEE3 Size (bytes) 228<br>
                                                      Address range 0x0FF00-0x0FFE3 Size (bytes) 228 */
    ISP_AP_RW_Gamma_BE            = 0x00800000u, /*!< Address range 0x10000-0x1007F Size (bytes) 128<br>
                                                      Address range 0x12C00-0x12FFF Size (bytes) 1024 */
    ISP_AP_RW_CA_memory           = 0x01000000u, /*!< Address range 0x10100-0x1017F Size (bytes) 128<br>
                                                      Address range 0x18000-0x1BFFF Size (bytes) 16384 */
    ISP_AP_RW_Out_format_LUT      = 0x02000000u, /*!< Address range 0x11000-0x11FFF Size (bytes) 4096 */
    ISP_AP_RW_Radial_shading_LUT  = 0x04000000u, /*!< Address range 0x12800-0x12B03 Size (bytes) 772 */
    ISP_AP_RW_Defect_pixel_memory = 0x08000000u, /*!< Address range 0x13000-0x13FFF Size (bytes) 4096 */
    ISP_AP_RW_Gamma_FE            = 0x10000000u, /*!< Address range 0x14000-0x17FFF Size (bytes) 16384 */
    ISP_AP_RW_Shading_mesh_memory = 0x20000000u, /*!< Address range 0x1C000-0x1FFFF Size (bytes) 16384 */
    ISP_AP_RW_Full_configuration  = 0x40000000u, /*!< Address range 0x00000-0x03FFF Size (bytes) 16384<br>
                                                      Address range 0x04000-0x1FFFF Size (bytes) 114688 */
} drvISP_AperturesFlags_t;

/*! MCFE Slot configuration */
typedef struct {
    drvISP_McfeSlotMode_t Mode; /*!< Slot mode (see #drvISP_McfeSlotMode_t) */
    UINT8 Sync_Input;           /*!< For fixed TDMF operation is the input number to synchronize with */
    UINT32 Status;              /*!< Slot Status (only used in get function) */
    UINT32 Delay;               /*!< For fixed TDMF operation: delay after the slot_event.<br>
                                     For flexible TDMF and for streaming modes - delay after post-frame downloading of the config. */
    UINT64 CfgBase;             /*!< Local Base Address of the configuration memory area for the slot */
    UINT32 CfgSize;             /*!< Size of the configuration memory area for the slot */
    UINT32 CfgReadUnits;        /*!< Bitmap of configuration chunks to be transferred to RAM from ISP after slot is processed (see #drvISP_AperturesFlags_t) */
    UINT32 CfgWriteUnits;       /*!< Bitmap of configuration chunks to be transferred from RAM to ISP before slot is processed (see #drvISP_AperturesFlags_t) */
    UINT8 Inputs[4];            /*!< Input streams that will be processed by ISP in this slot */
    UINT8 AxiOutBuf1[4];        /*!< First buffer for AXI output n */
    UINT8 AxiOutBuf2[4];        /*!< Second buffer for AXI output n */
} drvISP_McfeSlotCfg_t;

/*! Scheduler mode */
typedef enum {
    ISP_SCHED_STOPPED = 0u,        /*!< Stopped */
    ISP_SCHED_MANUAL,              /*!< Manual scheduling */
    ISP_SCHED_1STREAM,             /*!< Single stream on first input */
    ISP_SCHED_2STREAM_FIFO,        /*!< Dual stream (FIFO only) */
    ISP_SCHED_2STREAM_FB,          /*!< Dual stream (frame buffer) */
    ISP_SCHED_3STREAM,             /*!< Triple stream (first through frame buffer, second through FIFO, third direct) */
    ISP_SCHED_4STREAM,             /*!< Quad stream (first and second through frame buffer, third through FIFO, fourth direct) */
    ISP_SCHED_1STREAM_DOL,         /*!< Single stream DOL, configuraton is defined by input_mode (valid input_modes 0..2) */
    ISP_SCHED_2SENS_TDMF_FLEX,     /*!< Two sensors TDMF flex schedule */
    ISP_SCHED_2SENS_TDMF_FLEX_DOL, /*!< Two 2x DOL sensors TDMF flex schedule */
    ISP_SCHED_3SENS_TDMF_FLEX,     /*!< Three sensors TDMF flex schedule */
    ISP_SCHED_4SENS_TDMF_FLEX,     /*!< Four sensors TDMF flex schedule */
    ISP_SCHED_2SENS_TDMF_FIX,      /*!< Two sensors TDMF fix schedule */
    ISP_SCHED_2SENS_TDMF_FIX_DOL,  /*!< Two 2x DOL sensors TDMF fix schedule */
    ISP_SCHED_3SENS_TDMF_FIX,      /*!< Three sensors TDMF fix schedule */
    ISP_SCHED_4SENS_TDMF_FIX,      /*!< Four sensors TDMF fix schedule */
} drvISP_SchedulerMode_t;

/*! Consistency Plane configuration */
typedef struct {
    UINT8 DyDefectPixelEnable;    /*!< Enable dynamic defect flag bit plane */
    UINT8 StDefectPixelEnable;    /*!< Enable static defect flag bit plane */
    UINT8 WdrInconsistencyEnable; /*!< Enable WDR inconsistency bit plane */
    UINT8 WdrFlickerEnable;       /*!< Enable WDR flicker bit plane */
} drvISP_CplaneCfg_t;

/*! Consistency Plane statistics */
typedef struct {
    UINT8 DyDefectPixelOv;      /*!< Overflow flag for dynamic defect pixel counter */
    UINT8 StDefectPixelOv;      /*!< Overflow flag for static defect pixel counter */
    UINT8 WdrInconsistencyOv;   /*!< Overflow flag for WDR inconsistency counter */
    UINT8 WdrFlickerOv;         /*!< Overflow flag for WDR flicker counter */
    UINT32 DyDefectPixelCnt;    /*!< Count of the dynamic defect pixels in the last frame */
    UINT32 StDefectPixelCnt;    /*!< Count of the static defect pixels in the last frame */
    UINT32 WdrInconsistencyCnt; /*!< Count of pixels with WDR inconsistency during frame stitch in the last frame */
    UINT32 WdrFlickerCnt;       /*!< Count of the pixels with detected flicker in the last frame */
} drvISP_CplaneStatsData_t;

/*! RGGB Starting color for RGGB pattern */
typedef enum {
    ISP_RGGB_RGrGbB = 0u, /*!< R Gr Gb B */
    ISP_RGGB_GrRBGb,      /*!< Gr R B Gb */
    ISP_RGGB_GbBRGr,      /*!< Gb B R Gr */
    ISP_RGGB_BGbGrR       /*!< B Gb Gr R */
} drvISP_RGGBstart_t;

/*! CFA pattern  */
typedef enum {
    ISP_CFA_RGGB = 0u, /*!< R G G B */
    ISP_CFA_RCCC,      /*!< R C C C */
    ISP_CFA_RIrGB,     /*!< R Ir G B */
    ISP_CFA_RGIrB      /*!< R G Ir B */
} drvISP_CfaPattern_t;

/*! Exposure statistics record
 *  @details Histogram bin data is normalized so total count in all bins including implicit bin 2 is always 65535
 * */
typedef struct {
    UINT16 Bin0; /*!< Bin0 normalized pixel sum */
    UINT16 Bin1; /*!< Bin1 normalized pixel sum */
    UINT16 Bin3; /*!< Bin3 normalized pixel sum */
    UINT16 Bin4; /*!< Bin4 normalized pixel sum */
} drvISP_ExpStatRecord_t;

/*! Exposure statistics data */
typedef struct {
    UINT32 ctEntries;               /*!< Count of array elements array provided by user */
    drvISP_ExpStatRecord_t *pEntry; /*!< Array of length provided by user, Pointer to the statistics of each node */
    UINT16 Nodes_Used_Horiz;        /*!< Number of horizontal nodes used */
    UINT16 Nodes_Used_Vert;         /*!< Number of vertical nodes used */
    UINT16 Glob_Avg_Bin0;           /*!< Global average for Bin0 */
    UINT16 Glob_Avg_Bin1;           /*!< Global average for Bin1 */
    UINT16 Glob_Avg_Bin3;           /*!< Global average for Bin3 */
    UINT16 Glob_Avg_Bin4;           /*!< Global average for Bin4 */
    UINT32 FrameCount;              /*!< Frame counter */
    UINT32 CRC16;                   /*!< CRC16 */
} drvISP_ExpStatsData_t;

/*! White Point statistics node statistics */
typedef struct {
        UINT16 Avg_RG;     /*!< Average Red/Green ratio */
        UINT16 Avg_BG;     /*!< Average Blue/Green ratio */
        UINT32 PixelCount; /*!< Pixels processed */
} drvISP_WbStatRecord_t;

/*! White Point statistics data */
typedef struct {
    UINT32 ctEntries;              /*!< Count of array elements array provided by user */
    drvISP_WbStatRecord_t *pEntry; /*!< Array of length provided by user, Pointer to the statistics of each node */
    UINT16 Nodes_Used_Horiz;       /*!< Number of horizontal nodes used */
    UINT16 Nodes_Used_Vert;        /*!< Number of vertical nodes used */
    UINT16 Global_Avg_RG;          /*!< Global average Red/Green ratio */
    UINT16 Global_Avg_BG;          /*!< Global average Blue/Green ratio */
    UINT32 Global_PixelCount;      /*!< Pixels processed */
    UINT32 FrameCount;             /*!< Frame counter */
    UINT32 CRC16;                  /*!< CRC16 */
} drvISP_WbStatsData_t;

/*! Histogram statistics data */
typedef struct {
    UINT32 ctEntries;              /*!< Count of array elements array provided by user */
    UINT16 *pEntry;                /*!< Pointer to the statistics of each node */
    UINT16 Nodes_Used_Horiz;       /*!< Number of horizontal nodes used */
    UINT16 Nodes_Used_Vert;        /*!< Number of vertical nodes used */
    UINT32 Tot_PixelNumber;        /*!< Total pixels */
    UINT32 CountedPixels;          /*!< Pixels processed */
    UINT32 Plane0_Tot_PixelNumber; /*!< Number of pixel in plane 0 */
    UINT32 Plane1_Tot_PixelNumber; /*!< Number of pixel in plane 1 */
    UINT32 Plane2_Tot_PixelNumber; /*!< Number of pixel in plane 2 */
    UINT32 Plane3_Tot_PixelNumber; /*!< Number of pixel in plane 3 */
    UINT32 Plane0_CountedPixels;   /*!< Counted pixels in plane 0 */
    UINT32 Plane1_CountedPixels;   /*!< Counted pixels in plane 1 */
    UINT32 Plane2_CountedPixels;   /*!< Counted pixels in plane 2 */
    UINT32 Plane3_CountedPixels;   /*!< Counted pixels in plane 3 */
    UINT32 FrameCount;             /*!< Frame counter */
    UINT32 CRC16;                  /*!< CRC16 */
} drvISP_HistStatsData_t;

/*! Histogram statistics tap points */
typedef enum {
    HistStat_After_InputPort_20bpp = 0u, /*!< After Input Port, bits [19:0] */
    HistStat_After_InputPort_12bpp,      /*!< After Input Port, bits [11:0] */
    HistStat_After_WDR_Gain,             /*!< After WDR Gain (WDR data path), the WDR channel is dependent by the Histogram number */
    HistStat_Before_Sensor_offset,       /*!< Before Sensor Offset module */
    HistStat_After_Gamma_FE,        /*!< After Gamma FE module */
    HistStat_After_Mesh_Shading     /*!< After Mesh Shading module */
} drvISP_HistStat_Tp_t;

/*! Histogram statistics mode (how the data are written in memory) */
typedef enum {
    HistStat_All_planes_in_one_histogram                  = 0u, /*!< Collect all the planes in one histogram */
    HistStat_4_Bayer_planes_into_4_banks                  = 1u, /*!< Collect 4 Bayer planes into 4 separate banks */
    HistStat_Every_pixel_of_4_Bayer_planes_into_4_banks   = 2u, /*!< Collect every pixel of 4 Bayer planes into 4 separate banks */
    HistStat_Odd_x_odd_y_plane_to_bank_0_rest_to_bank_1   = 4u, /*!< Collect odd x odd y plane to bank 0, rest to bank 1 */
    HistStat_Even_x_odd_y_plane_to_bank_0_rest_to_bank_1  = 5u, /*!< Collect even x odd y plane to bank 0, rest to bank 1 */
    HistStat_Odd_x_even_y_plane_to_bank_0_rest_to_bank_1  = 6u, /*!< Collect odd x even y plane to bank 0, rest to bank 1 */
    HistStat_Even_x_even_y_plane_to_bank_0_rest_to_bank_1 = 7u  /*!< Collect even x even y plane to bank 0, rest to bank 1 */
} drvISP_HistStat_Mode_t;

/*! Histogram statistics configuration */
typedef struct {
    UINT8 Enable;                    /*!< Enable */
    drvISP_HistStat_Tp_t TapPoint;   /*!< Tap point (see #drvISP_HistStat_Tp_t) */
    drvISP_HistStat_Mode_t Mode;     /*!< Mode (see #drvISP_HistStat_Mode_t) */
    drvISP_CfaPattern_t CFA_pattern; /*!< Frame CFA pattern (see #drvISP_CfaPattern_t) */
    drvISP_RGGBstart_t RGGB_start;   /*!< RGGB starting color (see #drvISP_RGGBstart_t) */
    UINT16 Active_Width;             /*!< Active frame width in pixels */
    UINT16 Active_Height;            /*!< Active frame height in lines */
    UINT8 Nodes_Used_Horiz;          /*!< Number of horizontal nodes used */
    UINT8 Nodes_Used_Vert;           /*!< Number of vertical nodes used */
    UINT8 Radial_shading_enable;     /*!< Enable radial shading correction */
    UINT8 offset_x;                  /*!< 0= start from the first column; 1=start from second column */
    UINT8 offset_y;                  /*!< 0= start from the first row; 1= start from second row */
    UINT8 skip_x;                    /*!< Histogram decimation in horizontal direction: 0=every 2nd pixel; 1=every 3rd pixel; 2=every 4th pixel; 3=every 5th pixel; 4=every 8th pixel ; 5+=every 9th pixel */
    UINT8 skip_y;                    /*!< Histogram decimation in vertical direction: 0=every pixel; 1=every 2nd pixel; 2=every 3rd pixel; 3=every 4th pixel; 4=every 5th pixel; 5=every 8th pixel ; 6+=every 9th pixel */
    UINT8 scale_bottom;              /*!< Scale of bottom half of the range: 0=1x ,1=2x, 2=4x, 4=8x, 4=16x */
    UINT8 scale_top;                 /*!< Scale of top half of the range: 0=1x ,1=2x, 2=4x, 4=8x, 4=16x */
    UINT16 Gain[4];                  /*!< Multiplier for color channel 00 (R), 01 (Gr), 10 (Gb), 11 (B).<br>
                                          Format: unsigned 4.8-bit fixed-point. */
    UINT32 Black[4];                 /*!< Black offset for color channel 00 (R), 01 (Gr), 10 (Gb), 11 (B). */
    UINT16 CenterX;                  /*!< Center x coordinate of the shading map */
    UINT16 CenterY;                  /*!< Center y coordinate of the shading map */
    UINT16 Off_Center_multX;         /*!< Normalizing X factor which scales the radial table to the edge of the image.<br>
                                          Calculated as \f$ 2^{31}/R^2 \f$ where R is the furthest distance from the center coordinate to the edge of the image in pixels. */
    UINT16 Off_Center_multY;         /*!< Normalizing Y factor which scales the radial table to the edge of the image.<br>
                                          Calculated as \f$ 2^{31}/R^2 \f$ where R is the furthest distance from the center coordinate to the edge of the image in pixels. */
    UINT16 Shading_LUT[ISP_HIST_LUT_SIZE]; /*!< Radial shading lookup table */
    UINT8 Node_Weight[ISP_HIST_NUM_ZONES]; /*!< Nodes weight */
} drvISP_HistStatsCfg_t;

/*! Micro ROI data */
typedef struct {
    UINT32 ctEntries;   /*!< Count of array elements array provided by user */
    UINT16 *pEntry;     /*!< Pointer to the Micro ROI data */
    UINT16 CRC16;       /*!< CRC16 */
} drvISP_uRoiCropData_t;

/*! Micro ROI tap points */
typedef enum {
    uROI_MCFE_Output_Ch0 = 0u,  /*!< After MCFE channel 0 (16bpp) */
    uROI_MCFE_Output_Ch1,       /*!< After MCFE channel 1 (16bpp) */
    uROI_MCFE_Output_Ch2,       /*!< After MCFE channel 2 (16bpp) */
    uROI_MCFE_Output_Ch3,       /*!< After MCFE channel 3 (16bpp) */
    uROI_WDR_Stitched_MSB,      /*!< After Frame Stitch (MSB of 24bpp) */
    uROI_WDR_Stitched_LSB,      /*!< After Frame Stitch (LSB of 24bpp) */
    uROI_After_Shading_MSB,     /*!< After Mesh Shading (MSB of 24bpp) */
    uROI_After_Shading_LSB,     /*!< After Mesh Shading (LSB of 24bpp) */
    uROI_After_ToneMapping_MSB, /*!< After Tone Mapping (MSB of 24bpp) */
    uROI_After_ToneMapping_LSB, /*!< After Tone Mapping (LSB of 24bpp) */
    uROI_After_Demosaic_Ch0,    /*!< After Demosaic R/C channel (14bpp) */
    uROI_After_Demosaic_Ch1,    /*!< After Demosaic G/C channel (14bpp) */
    uROI_After_Demosaic_Ch2,    /*!< After Demosaic B/C channel (14bpp) */
    uROI_After_Demosaic_Ch3,    /*!< After Demosaic Ir channel (14bpp) */
    uROI_YCbCr_Output_Y,        /*!< At Y of YUV output (14bpp) */
    uROI_LUV_Output_L,          /*!< At L of LUV output (14bpp) */
    uROI_YCbCr_Output_CbCr,     /*!< At UV of YUV output (14bpp) */
    uROI_LUV_Output_UV,         /*!< At UV of LUV output (14bpp) */
    uROI_HH_Output              /*!< At H output (14bpp) */
} drvISP_uROI_Tp_t;

/*! Micro ROI crop configuration */
typedef struct {
    UINT8 Enable;              /*!< Enable Micro ROI */
    drvISP_uROI_Tp_t TapPoint; /*!< Tap Point (see #drvISP_uROI_Tp_t) */
    UINT16 PosX;               /*!< Horizontal position */
    UINT16 PosY;               /*!< Vertical position */
} drvISP_uRoiCropCfg_t;

/*! Antifog statistics configuration */
typedef struct {
    UINT8 Enable;                 /*!< Enable Antifog statistics */
    drvISP_HistStat_Mode_t Mode;  /*!< Mode (see #drvISP_HistStat_Mode_t) */
    UINT8 Nodes_Used_Horiz;       /*!< Number of horizontal nodes used */
    UINT8 Nodes_Used_Vert;        /*!< Number of vertical nodes used */
    UINT8 Radial_shading_enable;  /*!< Enable radial shading correction */
    UINT8 offset_x;               /*!< 0= start from the first column; 1=start from second column */
    UINT8 offset_y;               /*!< 0= start from the first row; 1= start from second row */
    UINT8 skip_x;                 /*!< Histogram decimation in horizontal direction: 0=every 2nd pixel; 1=every 3rd pixel; 2=every 4th pixel; 3=every 5th pixel; 4=every 8th pixel ; 5+=every 9th pixel */
    UINT8 skip_y;                 /*!< Histogram decimation in vertical direction: 0=every pixel; 1=every 2nd pixel; 2=every 3rd pixel; 3=every 4th pixel; 4=every 5th pixel; 5=every 8th pixel ; 6+=every 9th pixel */
    UINT8 scale_bottom;           /*!< Scale of bottom half of the range: 0=1x ,1=2x, 2=4x, 4=8x, 4=16x */
    UINT8 scale_top;              /*!< Scale of top half of the range: 0=1x ,1=2x, 2=4x, 4=8x, 4=16x */
    UINT16 Gain[4];               /*!< Multiplier for color channel 00 (R), 01 (Gr), 10 (Gb), 11 (B).<br>Format: unsigned 4.8-bit fixed-point. */
    UINT32 Black[4];              /*!< Black offset for color channel 00 (R), 01 (Gr), 10 (Gb), 11 (B). */
    UINT16 CenterX;               /*!< Center x coordinate of the shading map */
    UINT16 CenterY;               /*!< Center y coordinate of the shading map */
    UINT16 Off_Center_multX;      /*!< Normalizing X factor which scales the radial table to the edge of the image.<br>
                                       Calculated as \f$ 2^{31}/R^2 \f$ where R is the furthest distance from the center coordinate to the edge of the image in pixels. */
    UINT16 Off_Center_multY;      /*!< Normalizing Y factor which scales the radial table to the edge of the image.<br>
                                       Calculated as \f$ 2^{31}/R^2 \f$ where R is the furthest distance from the center coordinate to the edge of the image in pixels. */
    UINT16 Shading_LUT[ISP_HIST_LUT_SIZE]; /*!< Radial shading lookup table */
    UINT8 Node_Weight[ISP_HIST_NUM_ZONES]; /*!< Nodes weight */
} drvISP_AfStatsCfg_t;

/*! ROI tap points */
typedef enum {
    RoiStat_Before_Sensor_offset = 0u, /*!< Before sensor offset module */
    RoiStat_After_Gamma_FE             /*!< After Gamma FE module */
} drvISP_RoiStat_Tp_t;

/*! ROI statistics configuration */
typedef struct {
    drvISP_RoiStat_Tp_t TapPoint;  /*!< Tap point (see #drvISP_RoiStat_Tp_t) */
    drvISP_RGGBstart_t RGGB_start; /*!< RGGB start color (see #drvISP_RGGBstart_t) */
    drvISP_HistStat_Mode_t Mode;   /*!< Mode (see #drvISP_HistStat_Mode_t) */
    UINT8 offset_x;                /*!< 0= start from the first column; 1=start from second column */
    UINT8 offset_y;                /*!< 0= start from the first row; 1= start from second row */
    UINT8 skip_x;                  /*!< Histogram decimation in horizontal direction: 0=every 2nd pixel; 1=every 3rd pixel; 2=every 4th pixel; 3=every 5th pixel; 4=every 8th pixel ; 5+=every 9th pixel */
    UINT8 skip_y;                  /*!< Histogram decimation in vertical direction: 0=every pixel; 1=every 2nd pixel; 2=every 3rd pixel; 3=every 4th pixel; 4=every 5th pixel; 5=every 8th pixel ; 6+=every 9th pixel */
    UINT8 scale_bottom;            /*!< Scale of bottom half of the range: 0=1x ,1=2x, 2=4x, 4=8x, 4=16x */
    UINT8 scale_top;               /*!< Scale of top half of the range: 0=1x ,1=2x, 2=4x, 4=8x, 4=16x */
    UINT16 Gain[4];                /*!< Multiplier for color channel 00 (R), 01 (Gr), 10 (Gb), 11 (B).<br>Format: unsigned 4.8-bit fixed-point. */
    UINT32 Black[4];               /*!< Black offset for color channel 00 (R), 01 (Gr), 10 (Gb), 11 (B). */
    UINT16 start_x;                /*!< Horizontal start point */
    UINT16 size_x;                 /*!< Horizontal width */
    UINT16 start_y;                /*!< Vertical start point */
    UINT16 size_y;                 /*!< Vertical width */
} drvISP_RoiStatsCfg_t;

/*! White point statistics tap points */
typedef enum {
    WbStat_After_Demosaic_LSB_Align = 0u, /*!< After demosaic, LSB aligned */
    WbStat_After_Demosaic_MSB_Align       /*!< After demosaic, MSB aligned */
} drvISP_WbStat_Tp_t;

/*! White point statistics mode */
typedef enum {
    WbStat_Mode_Legacy_GR_BR = 0u, /*!< legacy (G/R, B/R) */
    WbStat_Mode_Current_RG_BG      /*!< current (R/G, B/G) */
} drvISP_WbStat_Mode_t;

/*! White point statistics configuration */
typedef struct {
    drvISP_WbStat_Tp_t TapPoint; /*!< Tap point (see #drvISP_WbStat_Tp_t) */
    drvISP_WbStat_Mode_t Mode;   /*!< Mode (see #drvISP_WbStat_Mode_t) */
    UINT16 Active_Width;         /*!< Active frame width in pixels */
    UINT16 Active_Height;        /*!< Active frame height in lines */
    UINT8 Nodes_Used_Horiz;      /*!< Number of horizontal nodes used */
    UINT8 Nodes_Used_Vert;       /*!< Number of vertical nodes used */
    UINT16 White_Level;          /*!< Upper limit of valid data for AWB */
    UINT16 Black_Level;          /*!< Lower limit of valid data for AWB */
    UINT16 Cr_Ref_Max;           /*!< Maximum value of R/G for white region<br>Format: unsigned 4.8-bit fixed-point */
    UINT16 Cr_Ref_Min;           /*!< Minimum value of R/G for white region<br>Format: unsigned 4.8-bit fixed-point */
    UINT16 Cb_Ref_Max;           /*!< Maximum value of B/G for white region<br>Format: unsigned 4.8-bit fixed-point */
    UINT16 Cb_Ref_Min;           /*!< Minimum value of B/G for white region<br>Format: unsigned 4.8-bit fixed-point */
    UINT16 Cr_Ref_High;          /*!< Maximum value of R/G for white region<br>Format: unsigned 4.8-bit fixed-point */
    UINT16 Cr_Ref_Low;           /*!< Minimum value of R/G for white region<br>Format: unsigned 4.8-bit fixed-point */
    UINT16 Cb_Ref_High;          /*!< Maximum value of B/G for white region<br>Format: unsigned 4.8-bit fixed-point */
    UINT16 Cb_Ref_Low;           /*!< Minimum value of B/G for white region<br>Format: unsigned 4.8-bit fixed-point */
    UINT8 Node_Weight[ISP_AWB_NUM_ZONES]; /*!< Nodes weight */
} drvISP_WbStatsCfg_t;

/*! Exposure statistics tap points */
typedef enum {
    ExpStat_After_Static_White_Balance = 0u, /*!< After Static White Balance module */
    ExpStat_After_WDR_Gain,                  /*!< After WDR Gain module */
    ExpStat_After_Mesh_Shading,              /*!< After Mesh Shading module */
    ExpStat_Before_Sensor_offset,            /*!< Before Sensor Offset module */
    ExpStat_After_Gamma_FE                   /*!< After Gamma FE module */
} drvISP_ExpStat_Tp_t;

/*! Exposure statistics configuration */
typedef struct {
    UINT8 Enable;                 /*!< Enable */
    drvISP_ExpStat_Tp_t TapPoint; /*!< Tap point (see #drvISP_ExpStat_Tp_t) */
    UINT8 Nodes_Used_Horiz;       /*!< Number of horizontal nodes used */
    UINT8 Nodes_Used_Vert;        /*!< Number of vertical nodes used */
    UINT8 Hist_Thresh_01;         /*!< Histogram threshold for bin 0/1 boundary */
    UINT8 Hist_Thresh_12;         /*!< Histogram threshold for bin 1/2 boundary  */
    UINT8 Hist_Thresh_23;         /*!< Histogram threshold for bin 2/3 boundary  */
    UINT8 Hist_Thresh_34;         /*!< Histogram threshold for bin 3/4 boundary  */
    UINT8 Node_Weight[ISP_AEXP_NUM_ZONES]; /*!< Nodes weight */
} drvISP_ExpStatsCfg_t;

/*! Video Test Pattern type */
typedef enum {
    ISP_VTG_FLAT_FIELD = 0u,  /*!< Flat field */
    ISP_VTG_HOR_GRAD,         /*!< Horizontal gradient */
    ISP_VTG_VER_GRAD,         /*!< Vertical gradient */
    ISP_VTG_VER_BARS,         /*!< Vertical bars */
    ISP_VTG_RECTANGLE,        /*!< Rectangle */
    ISP_VTG_RANDOM,           /*!< Random */
    ISP_VTG_WHITE_FR_ON_BLACK /*!< White frame on black */
} drvISP_VtgPattern_t;

/*! Video Test Generator position */
typedef enum {
    ISP_VTG_After_MCFE = 0u, /*!< After MCFE */
    ISP_VTG_Before_MCFE      /*!< Before MCFE */
} drvISP_VtgPosition_t;

/*! Video Test Generator configuration */
typedef struct {
    UINT8 Enable;                  /*!< Enable */
    drvISP_VtgPosition_t Position; /*!< Position (see #drvISP_VtgPosition_t) */
    drvISP_VtgPattern_t Pattern;   /*!< Pattern type select (see #drvISP_VtgPattern_t) */
    UINT8 Video_Source;            /*!< Selects sync source:<br>0 = Video input<br>1 = Internal Video sync generator */
    UINT8 Generate_Mode;           /*!< 0 = One Shot (on request) generation.<br>
                                        1 = Free Run (continuous) generation. */
    UINT8 Bayer_RGB_Input;         /*!< Bayer or RGB select for input video:<br>0 = Bayer<br>1 = RBG */
    UINT8 Bayer_RGB_Output;        /*!< Bayer or RGB select for output video:<br>0 = Bayer<br>1 = RBG */
    UINT8 Frame_Request;           /*!< Request autogenerated frame */
    UINT16 Hor_Blanking;           /*!< Horizontal blank for autogenerated frame */
    UINT16 Ver_Blanking;           /*!< Vertical blank for autogenerated frame */
    UINT32 R_Back;                 /*!< Red background value 16-bit, MSB aligned to used width */
    UINT32 G_Back;                 /*!< Blue background value 16-bit, MSB aligned to used width */
    UINT32 B_Back;                 /*!< Green background value 16-bit, MSB aligned to used width */
    UINT32 Ir_Back;                /*!< IR background value 16-bit, MSB aligned to used width */
    UINT32 R_Fore;                 /*!< Red foreground value 16-bit, MSB aligned to used width */
    UINT32 G_Fore;                 /*!< Blue foreground value 16-bit, MSB aligned to used width */
    UINT32 B_Fore;                 /*!< Green foreground value 16-bit, MSB aligned to used width */
    UINT32 Ir_Fore;                /*!< IR foreground value 16-bit, MSB aligned to used width */
    UINT16 RGB_Gradient[4];        /*!< RGB gradient increment per pixel (0-15) for channel n:<br>
                                        0 = Unit 1<br>
                                        1 = Unit 2<br>
                                        2 = Unit 3<br>
                                        3 = Unit 4<br>
                                        Format: unsigned 4.12-bit fixed-point */
    UINT32 RGB_Gradient_Start[4];  /*!< RGB gradient start value for channel n:<br>
                                        0 = Unit 1<br>
                                        1 = Unit 2<br>
                                        2 = Unit 3<br>
                                        3 = Unit 4<br>
                                        Format: 16-bit, MSB aligned to used width */
    UINT16 Rect_Top;               /*!< Rectangle top line number (0 = 1st line) */
    UINT16 Rect_Bottom;            /*!< Rectangle bottom line number (0 = 1st line) */
    UINT16 Rect_Left;              /*!< Rectangle left pixel number (0 = 1st column) */
    UINT16 Rect_Right;             /*!< Rectangle right pixel number (0 = 1st column) */
    UINT32 PRBS_Seed[4];           /*!< PRBS seed n:<br>
                                        0 = Seed 1<br>
                                        1 = Seed 2<br>
                                        2 = Seed 3<br>
                                        3 = Seed 4<br>
                                        The PRBS LFSR is seeded with this value when reset on a frame boundary. */
} drvISP_VtgCfg_t;

/*! Channel Selector configuration */
typedef struct {
    UINT8 Enable;      /*!< Enable */
    UINT8 ChSelect[4]; /*!< Select an input from MCFE as input N form the following modules */
} drvISP_ChSelCfg_t;

/*! Sinter® BIST tests */
#define ISP_BIST_SNT_DISABLE       0        /*!< No test */
#define ISP_BIST_SNT_FF_FAILURE    (1 << 0) /*!< Failure test */
#define ISP_BIST_SNT_FF_2560x1280  (1 << 1) /*!< Full frame test */
#define ISP_BIST_SNT_RP_180x94     (1 << 2) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_SNT_RP_128x70     (1 << 3) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_SNT_RP_32x256     (1 << 4) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_SNT_RP_264x32     (1 << 5) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_SNT_ENABLE_ALL    0x3Eu    /*!< Enable all tests (except Failure test) */

/*! Frame stitch BIST tests */
#define ISP_BIST_FS_DISABLE        0        /*!< No test */
#define ISP_BIST_FS_FF_FAILURE     (1 << 0) /*!< Failure test */
#define ISP_BIST_FS_FF_2560x1280   (1 << 1) /*!< Full frame test */
#define ISP_BIST_FS_RP_32x400      (1 << 2) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_FS_RP_180x96      (1 << 3) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_FS_RP_32x128      (1 << 4) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_FS_RP_64x64       (1 << 5) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_FS_RP_32x96       (1 << 6) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_FS_RP_128x32      (1 << 7) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_FS_RP_132x48      (1 << 8) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_FS_ENABLE_ALL     0x1FEu   /*!< Enable all tests (except Failure test) */

/*! Raw frontend BIST tests */
#define ISP_BIST_RAWFE_DISABLE      0        /*!< No test */
#define ISP_BIST_RAWFE_FF_FAILURE   (1 << 0) /*!< Failure test */
#define ISP_BIST_RAWFE_FF_2560x1280 (1 << 1) /*!< Full frame test */
#define ISP_BIST_RAWFE_RP_32x32     (1 << 2) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_RAWFE_RP_128x32    (1 << 3) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_RAWFE_RP_32x128    (1 << 4) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_RAWFE_RP_64x32     (1 << 5) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_RAWFE_ENABLE_ALL   0x3Eu    /*!< Enable all tests (except Failure test) */

/*! Iridix® BIST tests */
#define ISP_BIST_IRDX_DISABLE       0        /*!< No test */
#define ISP_BIST_IRDX_FF_FAILURE    (1 << 0) /*!< Failure test */
#define ISP_BIST_IRDX_FF_2560x1280  (1 << 1) /*!< Full frame test */
#define ISP_BIST_IRDX_RP_200x80     (1 << 2) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_IRDX_RP_128x64     (1 << 3) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_IRDX_RP_32x128     (1 << 4) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_IRDX_RP_64x32      (1 << 5) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_IRDX_ENABLE_ALL    0x3Eu    /*!< Enable all tests (except Failure test) */

/*! Radial shading tests */
#define ISP_BIST_RS_DISABLE       0        /*!< No test */
#define ISP_BIST_RS_FF_FAILURE    (1 << 0) /*!< Failure test */
#define ISP_BIST_RS_FF_2560x1280  (1 << 1) /*!< Full frame test */
#define ISP_BIST_RS_RP_32x32      (1 << 2) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_RS_RP_128x32     (1 << 3) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_RS_RP_32x128     (1 << 4) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_RS_RP_64x32      (1 << 5) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_RS_ENABLE_ALL    0x3Eu    /*!< Enable all tests (except Failure test) */

/*! Gamma BeDl tests */
#define ISP_BIST_GBEDL_DISABLE       0        /*!< No test */
#define ISP_BIST_GBEDL_FF_FAILURE    (1 << 0) /*!< Failure test */
#define ISP_BIST_GBEDL_FF_2560x1280  (1 << 1) /*!< Full frame test */
#define ISP_BIST_GBEDL_RP_24x192     (1 << 2) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_GBEDL_RP_128x32     (1 << 3) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_GBEDL_RP_32x128     (1 << 4) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_GBEDL_RP_64x48      (1 << 5) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_GBEDL_ENABLE_ALL    0x3Eu    /*!< Enable all tests (except Failure test) */

/*! Gamma FeDl tests */
#define ISP_BIST_GFEDL_DISABLE       0        /*!< No test */
#define ISP_BIST_GFEDL_FF_FAILURE    (1 << 0) /*!< Failure test */
#define ISP_BIST_GFEDL_FF_2560x1280  (1 << 1) /*!< Full frame test */
#define ISP_BIST_GFEDL_RP_32x32      (1 << 2) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_GFEDL_RP_128x32     (1 << 3) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_GFEDL_RP_32x128     (1 << 4) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_GFEDL_RP_64x32      (1 << 5) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_GFEDL_ENABLE_ALL    0x3Eu    /*!< Enable all tests (except Failure test) */

/*! Out format tests */
#define ISP_BIST_OUTF_DISABLE       0        /*!< No test */
#define ISP_BIST_OUTF_FF_FAILURE    (1 << 0) /*!< Failure test */
#define ISP_BIST_OUTF_FF_2560x1280  (1 << 1) /*!< Full frame test */
#define ISP_BIST_OUTF_RP_180x96     (1 << 2) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_OUTF_RP_128x124    (1 << 3) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_OUTF_RP_32x224     (1 << 4) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_OUTF_RP_64x132     (1 << 5) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_OUTF_ENABLE_ALL    0x3Eu    /*!< Enable all tests (except Failure test) */

/*! Demosaic RCCC tests */
#define ISP_BIST_DMRCCC_DISABLE       0        /*!< No test */
#define ISP_BIST_DMRCCC_FF_FAILURE    (1 << 0) /*!< Failure test */
#define ISP_BIST_DMRCCC_FF_2560x1280  (1 << 1) /*!< Full frame test */
#define ISP_BIST_DMRCCC_RP_190x64     (1 << 2) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_DMRCCC_RP_128x96     (1 << 3) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_DMRCCC_RP_32x128     (1 << 4) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_DMRCCC_RP_256x32     (1 << 5) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_DMRCCC_ENABLE_ALL    0x3Eu    /*!< Enable all tests (except Failure test) */

/*! Demosaic RGBIr tests */
#define ISP_BIST_DMRGBIr_DISABLE       0        /*!< No test */
#define ISP_BIST_DMRGBIr_FF_FAILURE    (1 << 0) /*!< Failure test */
#define ISP_BIST_DMRGBIr_FF_2560x1280  (1 << 1) /*!< Full frame test */
#define ISP_BIST_DMRGBIr_RP_200x64     (1 << 2) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_DMRGBIr_RP_128x100    (1 << 3) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_DMRGBIr_RP_96x140     (1 << 4) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_DMRGBIr_RP_300x32     (1 << 5) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_DMRGBIr_ENABLE_ALL    0x3Eu    /*!< Enable all tests (except Failure test) */

/*! Demosaic tests */
#define ISP_BIST_DM_DISABLE       0        /*!< No test */
#define ISP_BIST_DM_FF_FAILURE    (1 << 0) /*!< Failure test */
#define ISP_BIST_DM_FF_2560x1280  (1 << 1) /*!< Full frame test */
#define ISP_BIST_DM_RP_190x90     (1 << 2) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_DM_RP_128x64     (1 << 3) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_DM_RP_32x128     (1 << 4) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_DM_RP_64x32      (1 << 5) /*!< Alternative configuration to increase coverage */
#define ISP_BIST_DM_ENABLE_ALL    0x3Eu    /*!< Enable all tests (except Failure test) */

/*! Test Mode (BIST) configuration */
typedef struct {
    UINT8 Enable;        /*!< Enable */
    UINT8 TestTrigger;   /*!< Trigger test mode patterns manually */
    UINT8 EnableOutCrc;  /*!< Enable output CRC */
    UINT8 RawFeTest;     /*!< Raw Frontend test */
    UINT16 FsTest;       /*!< Frame stitch test */
    UINT8 GammaFeDlTest; /*!< Gamma FeDl test */
    UINT8 SinterTest;    /*!< Sinter® tests */
    UINT8 GammaBeDlTest; /*!< Gamma BeDl test */
    UINT8 RadShadTest;   /*!< Radial shading test */
    UINT8 IridixTest;    /*!< Iridix® test */
    UINT8 DemTest;       /*!< Demosaic test */
    UINT8 DemRcccTest;   /*!< Demosaic RCCC test */
    UINT8 DemRgbIrTest;  /*!< Demosaic RGBIr test */
    UINT8 OutFormTest;   /*!< Out format test */
} drvISP_BistCfg_t;

/*! Test Mode (BIST) expected CRC configuration */
typedef struct {
    UINT16 ExpCrcOut[3];    /*!< Expected CRC of the data at streaming output n */
    UINT16 ExpCrcAxiOut[3]; /*!< Expected CRC of the data at input n of MCBE */
} drvISP_BistCrcCfg_t;

/*! Test Mode (BIST) CRC results */
typedef struct {
    UINT16 CrcOut[3];    /*!< CRC of the data at streaming output n */
    UINT16 CrcAxiOut[3]; /*!< CRC of the data at input n of MCBE */
} drvISP_BistCrc_t;

/*! Frame Repeat CRC results */
typedef struct {
    UINT32 CrcInputFrame[4]; /*!< CRC of the last frame at input n of MCFE */
    UINT32 CrCLastFrame;     /*!< CRC of the last frame at the linear data multiplexor */
} drvISP_FrameCrc_t;

/*! Module Config CRC results */
typedef struct {
    UINT16 RawFrontend;   /*!< CRC of configuration applied to the Raw Frontend module */
    UINT16 DefectPixel;   /*!< CRC of configuration applied to the Defect Pixel module */
    UINT16 FrameStitch;   /*!< CRC of configuration applied to the Frame Stitch module */
    UINT16 Sinter;        /*!< CRC of configuration applied to the Sinter module */
    UINT16 CaCorrection;  /*!< CRC of configuration applied to the Chromatic Aberration Correction module */
    UINT16 GammaFeDl;     /*!< CRC of configuration applied to the Frontend Gamma module */
    UINT16 GammaBeDl;     /*!< CRC of configuration applied to the Backend Gamma module */
    UINT16 RadialShading; /*!< CRC of configuration applied to the Radial Shading module */
    UINT16 MeshShading;   /*!< CRC of configuration applied to the Mesh Shading module */
    UINT16 Iridix;        /*!< CRC of configuration applied to the Iridix module */
    UINT16 Demosaic;      /*!< CRC of configuration applied to the RGB Demosaic module */
    UINT16 DemosaicRgbIr; /*!< CRC of configuration applied to the RGBIr Demosaic module */
    UINT16 DemosaicRccc;  /*!< CRC of configuration applied to the RCCC Demosaic module */
    UINT16 OutFormat;     /*!< CRC of configuration applied to the Output Formater module */
    UINT16 MeteringAexp;  /*!< CRC of configuration applied to the Auto Exposure Metering module */
    UINT16 MeteringAwb;   /*!< CRC of configuration applied to the Auto White Balance Metering module */
    UINT16 MeteringHist0; /*!< CRC of configuration applied to the Global Histogram module for input channel 0 */
    UINT16 MeteringHist1; /*!< CRC of configuration applied to the Global Histogram module for input channel 1 */
    UINT16 MeteringHist2; /*!< CRC of configuration applied to the Global Histogram module for input channel 2 */
    UINT16 MeteringHist3; /*!< CRC of configuration applied to the Global Histogram module for input channel 3 */
    UINT16 RoiHist0;      /*!< CRC of configuration applied to the ROI Histogram module for input channel 0 */
    UINT16 RoiHist1;      /*!< CRC of configuration applied to the ROI Histogram module for input channel 1 */
    UINT16 RoiHist2;      /*!< CRC of configuration applied to the ROI Histogram module for input channel 2 */
    UINT16 RoiHist3;      /*!< CRC of configuration applied to the ROI Histogram module for input channel 3 */
    UINT16 uRoi;          /*!< CRC of configuration applied to the Micro ROI module */
    UINT16 AntifogHist;   /*!< CRC of configuration applied to the Antifog histogram module */
} drvISP_ModuleConfCrc_t;

/*! CRC Data */
typedef struct {
    drvISP_ModuleConfCrc_t ModuleConfCrc; /*!< Module Config CRC results */
    drvISP_BistCrc_t BistCrc;             /*!< Test Mode (BIST) CRC results */
    drvISP_FrameCrc_t FrameCrc;           /*!< Frame Repeat CRC results */
} drvISP_CrcData_t;

/*! Top configuration */
typedef struct {
    drvISP_CfaPattern_t CFA_pattern; /*!< Frame CFA pattern (see #drvISP_CfaPattern_t) */
    drvISP_RGGBstart_t RGGB_start;   /*!< RGGB start color (see #drvISP_RGGBstart_t) */
    UINT16 Active_Width;             /*!< Active frame width in pixels */
    UINT16 Active_Height;            /*!< Active frame height in lines */
} drvISP_TopCfg_t;

/*! Input Formatter input frames mode */
typedef enum {
    ISP_IFORM_LINEAR = 0u, /*!< Linear frame */
    ISP_IFORM_WDR_2_3,     /*!< Reconstruct 3rd exposure when only 2 are available<br>HDR separated exposures */
    ISP_IFORM_LOG,         /*!< Logarithmic encoding<br>HDR combined exposures */
    ISP_IFORM_KNEE         /*!< Companding curve with knee points<br>HDR combined exposures */
} drvISP_InputFormMode_t;

/*! Input Formatter input bitwidth */
typedef enum {
    ISP_IFORM_8BITS = 0u, /*!< 8bpp */
    ISP_IFORM_10BITS,     /*!< 10bpp */
    ISP_IFORM_12BITS,     /*!< 12bpp */
    ISP_IFORM_14BITS,     /*!< 14bpp */
    ISP_IFORM_16BITS,     /*!< 16bpp */
    ISP_IFORM_20BITS,     /*!< 20bpp */
    ISP_IFORM_22BITS,     /*!< 22bpp */
    ISP_IFORM_24BITS      /*!< 24bpp */
} drvISP_InputFormBw_t;

/*! Input Formatter 2:3 reconstruction configuration */
typedef struct {
    UINT32 factor_ML; /*!< 6.12 fix point - ratio between long and medium exposure for 2:3 multiplexed mode */
    UINT16 factor_MS; /*!< 1.12 fix point - ratio between short and medium exposure for 2:3 multiplexed mode */
} drvISP_InputForm2_3Cfg_t;

/*! Input Formatter Slopes */
typedef enum {
    ISP_IFORM_SLOPE_1x = 0u, /*!< Multiply by 1x */
    ISP_IFORM_SLOPE_2x,      /*!< Multiply by 2x */
    ISP_IFORM_SLOPE_4x,      /*!< Multiply by 4x */
    ISP_IFORM_SLOPE_8x,      /*!< Multiply by 8x */
    ISP_IFORM_SLOPE_16x,     /*!< Multiply by 16x */
    ISP_IFORM_SLOPE_32x,     /*!< Multiply by 32x */
    ISP_IFORM_SLOPE_64x,     /*!< Multiply by 64x */
    ISP_IFORM_SLOPE_128x,    /*!< Multiply by 128x */
    ISP_IFORM_SLOPE_256x,    /*!< Multiply by 256x */
    ISP_IFORM_SLOPE_512x,    /*!< Multiply by 512x */
    ISP_IFORM_SLOPE_1024x,   /*!< Multiply by 1024x */
    ISP_IFORM_SLOPE_2048x,   /*!< Multiply by 2048x */
    ISP_IFORM_SLOPE_4096x,   /*!< Multiply by 4096x */
    ISP_IFORM_SLOPE_8192x,   /*!< Multiply by 8192x */
    ISP_IFORM_SLOPE_16384x,  /*!< Multiply by 16384x */
    ISP_IFORM_SLOPE_32768x,  /*!< Multiply by 32768x */
} drvISP_InputFormSlope_t;

/*! Input Formatter Knee/Slopes configuration */
typedef struct {
    UINT16 knee_point[3];                    /*!< Knee points 0, 1, 2<br>Calculated on a 16bit range */
    drvISP_InputFormSlope_t slope_select[4]; /*!< Slopes 0, 1, 2, 3 (see #drvISP_InputFormSlope_t) */
} drvISP_InputFormKneeCfg_t;

/*! Input Formatter configuration */
typedef struct {
    UINT8 Enable;                   /*!< Enable */
    drvISP_InputFormMode_t Mode;    /*!< Mode (see #drvISP_InputFormMode_t) */
    drvISP_InputFormBw_t Bit_Width; /*!< Input frame bit width (see #drvISP_InputFormBw_t) */
    UINT16 Black_Level;             /*!< Black level of sensor data */
    drvISP_InputForm2_3Cfg_t Ext1;  /*!< 2:3 Mode configuration (see #drvISP_InputFormMode_t) */
    drvISP_InputFormKneeCfg_t Ext2; /*!< Knee/Slopes Mode configuration (see #drvISP_InputFormMode_t) */
} drvISP_InputFormCfg_t;

/*! Static White Balance configuration */
typedef struct {
    UINT8 Enable;     /*!< Enable */
    UINT16 Gain[4];   /*!< 12 bit Color gain in 4.8 format:<br>
                           0 - 00<br>
                           1 - 01<br>
                           2 - 10<br>
                           3 - 11<br> */
    UINT32 Offset[4]; /*!< Black offset: 24 bit <br>
                           0 - 00<br>
                           1 - 01<br>
                           2 - 10<br>
                           3 - 11<br> */
} drvISP_WbCfg_t;

/*! WDR Black Offset channel configuration */
typedef struct {
    UINT32 Black00; /*!< Black offset for color channel 00 (R) */
    UINT32 Black01; /*!< Black offset for color channel 01 (Gr) */
    UINT32 Black10; /*!< Black offset for color channel 10 (Gb) */
    UINT32 Black11; /*!< Black offset for color channel 11 (B) */
} drvISP_WdrChOffCfg_t;

/*! WDR Black Offset configuration */
typedef struct {
    UINT8 Enable;             /*!< Enable */
    drvISP_WdrChOffCfg_t Ch[4]; /*!< Unit configuration */
} drvISP_WdrOffCfg_t;

/*! WDR Gain configuration */
typedef struct {
    UINT8 Enable;     /*!< Enable */
    UINT16 Gain[4];   /*!< Gain:<br>
                           0 - Unit 1<br>
                           1 - Unit 2<br>
                           2 - Unit 3<br>
                           3 - Unit 4<br>
                           Format: unsigned 5.8-bit fixed-point */
    UINT32 Offset[4]; /*!< Offset:<br>
                           0 - Unit 1<br>
                           1 - Unit 2<br>
                           2 - Unit 3<br>
                           3 - Unit 4<br> */
} drvISP_WdrGainCfg_t;

/*! WDR Stitch configuration */
typedef struct {
    UINT16 ExpRatio;      /*!< Exposure ratio: this must match the actual exposure ratio on the sensor<br>
                               Format: unsigned 6.6-bit fixed-point */
    UINT16 HighThresh;    /*!< Data above this threshold will be taken from shorter exposure only */
    UINT16 LowThresh;     /*!< Data below this threshold will be taken from longer exposure only */
    UINT16 NpMult;        /*!< Noise Profile Multiplicator:<br>
                               the noise profile weights are multiplied by this value to give expected noise amplitude */
    UINT16 AlphaMovSlope; /*!< This defines the gradient of the motion alpha ramp<br>
                               Higher values mean a steeper ramp and so a more rapid transition<br>
                               between non-motion-corrected and motion-corrected regions */
} drvISP_WdrExpCfg_t;

/*! Frame Stitch configuration */
typedef struct {
    UINT8 Enable;          /*!< Enable */
    UINT8 Mode;            /*!< 4-exposure wide-dynamic-range blending<br>
                                Note:<br>
                                If the WDR is configured to stitch 2 exposures,<br>
                                then the configuration must be done through the LM_ pair;<br>
                                the short exposures black level must be programmed through the med_black_level register<br>
                                so that the LM pair can be used.<br>
                                0 : 4-exposure<br>
                                1 : 2-exposure<br>
                                2 : 3-exposure<br>
                                3 : 4-exposure */
    UINT8 OutputSelect;    /*!< Select Output (used during calibration, keep to 0 for normal operation)<br>
                                Note:<br>
                                This register is only for debug purpose.<br>
                                For normal operation it must be kept in its default value (0)<br>
                                0 : normal stitched output<br>
                                1 : long data routed out<br>
                                2 : medium data routed out<br>
                                4 : short data routed out<br>
                                8 : very short data routed out<br>
                                16: LM stitched output taken out<br>
                                32: MS stitched output taken out<br>
                                64: SVS stitched output taken out<br>
                                others: reserved */
    drvISP_WdrExpCfg_t LM; /*!< Configuration between long and medium exposures (see #drvISP_WdrExpCfg_t) */
    drvISP_WdrExpCfg_t MS; /*!< Configuration between medium and short exposures (see #drvISP_WdrExpCfg_t) */
    drvISP_WdrExpCfg_t SVS; /*!< Configuration between short and very short exposures (see #drvISP_WdrExpCfg_t) */
    UINT16 GainR;          /*!< Multiplier for color channel R<br>
                                Format: unsigned 4.8-bit fixed-point */
    UINT16 GainB;          /*!< Multiplier for color channel B<br>
                                Format: unsigned 4.8-bit fixed-point */
    UINT16 ConsMovTh;      /*!< Pixel consistency reporting - motion threshold<br>
                                Format: unsigned 4.8-bit fixed-point */
    UINT32 ConsLvlTh;      /*!< Pixel consistency reporting - flicker threshold<br>
                                Format: unsigned 24-bit integer */
    UINT16 LM_MedTh;       /*!< This threshold is used only for the LM pair stitching.<br>
                                This determines if the short exposure for the blending<br>
                                will be taken from the current pixel or the median value */
    UINT16 L_BlackLevel;   /*!< Black level for long exposure input */
    UINT16 M_BlackLevel;   /*!< Black level for medium exposure input<br>
                                Note:<br>
                                If the WDR unit is configured to use as 2-exposure,<br>
                                THIS REGISTER POSITION must contain the black level of short exposure<br>
                                as the LM pair is used for all other configurations */
    UINT16 S_BlackLevel;   /*!< Black level for short exposure input */
    UINT16 VS_BlackLevel;  /*!< Black level for very short exposure input */
    UINT32 BlackLevel_Out; /*!< Black level for module output */
} drvISP_WdrStCfg_t;

/*! Digital Gain configuration */
typedef struct {
    UINT8 Enable;  /*!< Enable */
    UINT32 Gain;   /*!< Gain applied to data in 5.8 format */
    UINT32 Offset; /*!< Data black level */
} drvISP_DgCfg_t;

/*! Gamma DL configuration */
typedef struct {
    UINT8 Enable;               /*!< Enable */
    UINT32 Alpha;               /*!< Alpha parameter for the Gamma transform curve (10.12 fixed point)<br>
                                     The companding and decompanding function is as follows:<br>
                                     \f$y = x * 2^{32} / (alpha * 2^{20} + (4096 - alpha) * x)\f$<br>
                                     Gamma DL and InvGammaDL must be programmed accordingly (if used together).<br>
                                     @image html pics/gamma_dl.png
                                     */
    UINT32 Black_Level_Before; /*!< Black Level before the module */
    UINT32 Black_Level_After;  /*!< Black level after the module */
} drvISP_GammaDlCfg_t;

/*! Black Offset module */
typedef struct {
    UINT8 Enable;     /*!< Enable */
    UINT32 Offset[4]; /*!< Black offset:<br>
                           0 - channel 00<br>
                           1 - channel 01<br>
                           2 - channel 10<br>
                           3 - channel 11<br> */
} drvISP_LinOffCfg_t;

/*! Tone Mapping (de)companding mode */
typedef enum {
    TM_PASS_THROUGH = 0u, /*!< No (de)companding */
    TM_GAMMA_DL     = 1u, /*!< Gamma DL */
    TM_GAMMA_SQRT   = 2u, /*!< Gamma SQRT */
    TM_GAMMA_LUT    = 3u, /*!< Gamma LUT */
} drvISP_ToneMapGamma_t;

/*! Iridix ROI configuration */
typedef struct {
    UINT16 Hor_Start;       /*!< Left edge of the ROI for strength modulation */
    UINT16 Hor_End;         /*!< Right edge of the ROI for strength modulation */
    UINT16 Ver_Start;       /*!< Top edge of the ROI for strength modulation */
    UINT16 Ver_End;         /*!< Bottom edge of the ROI for strength modulation */
    UINT16 InRoi_Strength;  /*!< Iridix strength inside ROI.<br>Fixed point in 1.9 format */
    UINT16 OutRoi_Strength; /*!< Iridix strength outside ROI.<br>Fixed point in 1.9 format */
} drvISP_IridixROI_t;

/*! Tone Mapping White Balance configuration */
typedef struct {
    UINT32 Offset; /*!< Black level for white balance correction */
    UINT16 GainR;  /*!< Gain for red channel for white balance correction<br>4.8 fixed point format */
    UINT16 GainGr; /*!< Gain for green channel on the red line for white balance correction<br>4.8 fixed point format */
    UINT16 GainGb; /*!< Gain for green channel on the blue line for white balance correction<br>4.8 fixed point format */
    UINT16 GainB;  /*!< Gain for blue channel for white balance correction<br>4.8 fixed point format */
} drvISP_ToneMapWB_t;

/*! Iridix configuration */
typedef struct {
    UINT8 Mode;               /*!< 0 = Iridix7 algorithm<br>1 = Iridix8 algorithm */
    UINT8 Slope_Min;          /*!< Restricts the minimum slope (gain) which can be generated by the adaptive algorithm */
    UINT8 Slope_Max;          /*!< Restricts the maximum slope (gain) which can be generated by the adaptive algorithm */
    UINT8 Variance_Intensity; /*!< Sets the degree of luminance sensitivity(Iridix7) */
    UINT8 Variance_Space;     /*!< Sets the degree of spatial sensitivity (Iridix7) */
    UINT8 Contrast;           /*!< Contrast parameter (Iridix8) */
    UINT8 Bright_Pres;        /*!< Bright area preservation (Iridix8) */
    UINT8 Space_Variance;     /*!< Spatial variance (Iridix8) */
    UINT16 Dark_Enh;          /*!< Dark enhancement (Iridix8) */
    drvISP_IridixROI_t ROI;   /*!< ROI configuration (see #drvISP_IridixROI_t) */
} drvISP_IridixCfg_t;

/*! Tone Mapping configuration */
typedef struct {
    UINT8 Enable;                 /*!< Enable */
    UINT8 Mode;                   /*!< 0 = Local tone mapping (Iridix)<br>1 = Global tone mapping */
    drvISP_ToneMapWB_t WB;        /*!< White Balance configuration (see #drvISP_ToneMapWB_t) */
    drvISP_IridixCfg_t Iridix;    /*!< Local tone mapping (Iridix) configuration */
    UINT8 PostGamma_Pos;          /*!< PosGamma application<br>
                                       0 = gamma is applied to the gain used for tone mapping.<br>
                                       1 = gamma is applied to the data after tone mapping. */
    UINT8 Use_Black_Level;        /*!< 0 = Ignore Black level (set to zero) in amplificator.<br>1 = Use Black level value. */
    UINT8 Max_Alg_Type;           /*!< Max Bayer Algorithm Type. */

    UINT32 Black_Level;           /*!< Black level: values below this will not be affected by Tone Mapping. */
    UINT32 White_Level;           /*!< White level: alues above this will not be affected by Tone Mapping. */
    UINT16 Collection_Correction; /*!< Used to compensate for difference in brightness between successive frames due to
                                       changes in integration time or analogue or digital gain. */
    drvISP_ToneMapGamma_t PreGammaMode;  /*!< Data decompanding mode (see #drvISP_ToneMapGamma_t) */
    drvISP_ToneMapGamma_t PostGammaMode; /*!< Data decompanding mode (see #drvISP_ToneMapGamma_t) */
    UINT32 PreGammaAlpha;          /*!< Alpha parameter for the Gamma transform curve (10.12 fixed point)<br>
                                        The companding and decompanding function is as follows:<br>
                                        \f$y = x * 2^{32} / (alpha * 2^{20} + (4096 - alpha) * x)\f$<br>
                                        Gamma DL and InvGammaDL are programmed accordingly */
    UINT32 PostGammaAlpha;         /*!< Alpha parameter for the Gamma transform curve (10.12 fixed point)<br>
                                        The companding and decompanding function is as follows:<br>
                                        \f$y = x * 2^{32} / (alpha * 2^{20} + (4096 - alpha) * x)\f$<br>
                                        Gamma DL and InvGammaDL are programmed accordingly */
} drvISP_ToneMapCfg_t;


/*! LUT structure used for Iridix Asymmetry LUT, Tone Mapping Pre/Post LUT Gamma */
typedef struct {
    UINT32 *pEntry; /*!< Entries pointer. 24 bit used in each element  */
    UINT32 Size;    /*!< Number of entries. */
} drvISP_ToneMapLutCfg_t;

/*! Tone Mapping 2DLUT configuration */
typedef struct {
    UINT32 *pEntryX; /*!< Entries pointer to X LUT. 24 bits used in each element */
    UINT32 *pEntryY; /*!< Entries pointer to Y LUT. 25 bits used in each element  */
    UINT32 Size;     /*!< Number of entries. */
} drvISP_ToneMap_2DLUT_Cfg_t;

/*! RAW Frontend configuration */
typedef struct {
    UINT8 Enable;                /*!< Enable */
    UINT8 GE_Enable;             /*!< Green equalization enable:<br>
                                      0 = off<br>
                                      1 = on */
    UINT8 DynDP_Enable;          /*!< Dynamic Defect Pixel enable:<br>
                                      0 = off<br>
                                      1=on */
    UINT8 DynDP_Show;            /*!< Show Defect Pixel:<br>
                                      0 = off<br>
                                      1 = on */
    UINT8 RFE_L2_Disable;        /*!< Disable L2 function. */
    UINT8 Dark_Disable;          /*!< Disable detection of dark pixels. */
    UINT8 Bright_Disable;        /*!< Disable detection of bright pixels. */
    UINT8 GE_Strength;           /*!< Controls strength of Green equalization. Set during calibration. */
    UINT16 DP_Threshold;         /*!< Defect pixel threshold. */
    UINT16 GE_Threshold;         /*!< Green equalization threshold. */
    UINT16 DP_Slope;             /*!< Slope for DP Mask function. */
    UINT16 GE_Slope;             /*!< Slope for GE Mask function. */
    UINT8 GE_Sensitivity;        /*!< Controls the sensitivity of green equalization to edges. */
    UINT16 DynDP_Threshold;      /*!< Controls the aggressiveness of the dynamic defect pixel correction near edges. */
    UINT16 DynDP_Line_Threshold; /*!< Controls the directional nature of the dynamic defect pixel correction near edges. */
    UINT8 DynDP_Blending;        /*!< Controls blending between non-directional and directional replacement values in dynamic defect pixel correction.<br>
                                      0x00 Replace detected defects with non-directional replacement value.<br>
                                      0xFF Replace detected defects with directional replacement value. */
    UINT16 Sigma_In;             /*!< Manual override of noise estimation. */
    UINT8 ShortExp_Threshold;    /*!< Noise threshold for short exposure data.<br>
                                      Format: unsigned 4.4-bit floating-point. */
    UINT8 LongExp_Threshold;     /*!< Noise threshold for long exposure data.<br>
                                      Format: unsigned 4.4-bit floating-point. */
} drvISP_RawFeCfg_t;

/*! Defect Pixels configuration */
typedef struct {
    UINT8 Enable;                    /*!< Enable */
    UINT8 Detection_Trigger;         /*!< Trigger detection */
    UINT8 Show_Static_Defect_Pixels; /*!< Show which pixels have been detected as bad */
    UINT8 Show_Reference;            /*!< Show which pixels have been detected as bad */
    UINT8 Pointer_Reset;             /*!< Reset static defect-pixel table pointer each frame.<br>
                                          Set this when defect-pixel table has been written from CPU */
} drvISP_DefectPixCfg_t;

/*! Defect Pixels status */
typedef struct {
    UINT8 Overflow;               /*!< Table overflow flag */
    UINT16 Defect_Pixel_Count;    /*!< Number of defect-pixels detected */
    UINT16 Table_Start;           /*!< Address of first defect-pixel in defect-pixel store */
    UINT16 Defect_Pixel_Count_In; /*!< Number of defect-pixels in the written table */
    UINT32 Dynamic_Defect_Count;  /*!< Number of dynamic defect pixels in the last frame */
    UINT32 Static_Defect_Count;   /*!< Number of static defect pixels in the last frame */
} drvISP_DefectPixSts_t;

/*! Defect Pixels table entry
 * @details Top left pixel of the image has X and Y coordinates of (1,1)
 * */
typedef struct {
    UINT16 CoordX; /*!< Defect pixel X coordinate. 13 bits used in each element  */
    UINT16 CoordY; /*!< Defect pixel Y coordinate. 12 bits used in each element  */
} drvISP_DefectPixEntry_t;

/*! Defect Pixels table configuration
 * @details Table for static defect pixels contains 1024 entries.
 * */
typedef struct {
    drvISP_DefectPixEntry_t *pEntry; /*!< Entries pointer. */
    UINT32 Size;                     /*!< Number of entries. */
} drvISP_DefectPixLutCfg_t;

/*! Noise Profile LUT.
 * @details This is an array of 128 8-bit registers.
 * */
typedef struct {
    UINT8 *pEntry; /*!< Entries pointer. */
    UINT32 Size;   /*!< Number of entries. */
} drvISP_NpLUT_t;

/*! Pipeline Noise Profile configuration. */
typedef struct {
    UINT16 Exp_Thresh;      /*!< Threshold for determining long/short exposure data. */
    UINT8 Short_Ratio;      /*!< Multiplier applied to short exposure data for noise profile calculation.<br>
                                 Format: unsigned 6.2-bit fixed-point */
    UINT8 Long_Ratio;       /*!< Multiplier applied to long exposure data for noise profile calculation.<br>
                                 Format: unsigned 6.2-bit fixed-point */
    UINT8 Black_Offset;     /*!< Noise profile black level offset. */
    UINT8 Below_Black_Mode; /*!< Defines how values below black level are obtained.<br>
                                 0: Repeat the first table entry.<br>
                                 1: Reflect the noise profile curve below black level */
    drvISP_NpLUT_t LUT;     /*!< Noise Profile LUT (See #drvISP_NpLUT_t) */
} drvISP_PipeNpCfg_t;

/*! Sinter Radial Shading correction LUT.
 * @details This is an array of 33 8-bit registers.
 * */
typedef struct {
    UINT8 *pEntry; /*!< Entries pointer. */
    UINT32 Size;   /*!< Number of entries. */
} drvISP_SinterRsLUT_t;

/*! Sinter Radial Shading correction configuration
 * @details Adjusts Sinter strength radially from center to compensate for Lens shading correction.
 * */
typedef struct {
    UINT8 Enable;           /*!< Enable */
    UINT16 CenterX;         /*!< Center x coordinate of shading map. */
    UINT16 CenterY;         /*!< Center y coordinate of shading map. */
    UINT16 Off_Center_Mult; /*!< Normalizing factor which scales the radial table to the edge of the image.<br>
                                 Calculated as: \f$ 2^{31} / R^2 \f$<br>
                                 where R is the furthest distance from the center coordinate to the edge of the image in pixels. */
    drvISP_SinterRsLUT_t LUT; /*!< Radial Shading correction LUT .*/
} drvISP_SinterRsCfg_t;

/*! Sinter configuration */
typedef struct {
    UINT8 Enable;           /*!< Enable */
    UINT8 Intensity_Config; /*!< Intensity blending with mosaic raw. */
    UINT8 Intensity_Select; /*!< Select intensity filter. Should not be modified from suggested values. */
    UINT8 Filter_Select;    /*!< Sinter filter fine tuning. Should not be modified from suggested values. */
    UINT8 Thresh_1h;        /*!< Noise threshold for high horizontal spatial frequencies */
    UINT8 Thresh_4h;        /*!< Noise threshold for low horizontal spatial frequencies */
    UINT8 Thresh_1v;        /*!< Noise threshold for high vertical spatial frequencies */
    UINT8 Thresh_4v;        /*!< Noise threshold for low vertical spatial frequencies */
    UINT8 Thresh_Short;     /*!< Noise threshold adjustment for short exposure data */
    UINT8 Thresh_Long;      /*!< Noise threshold adjustment for long exposure data */
    UINT8 Strength_1;       /*!< Noise reduction effect for high spatial frequencies */
    UINT8 Strength_4;       /*!< Noise reduction effect for low spatial frequencies */
} drvISP_SinterCfg_t;

/*! Gamma LUT configuration */
typedef struct {
    UINT8 Enable;   /*!< Enable */
    UINT32 *pEntry; /*!< LUT entries pointer. 25 bits used in each element */
    UINT16 Size;    /*!< Number of entries. */
} drvISP_GammaCfg_t;

/*! Chromatic Aberration configuration */
typedef struct {
    UINT8 Enable;        /*!< Enable */
    UINT8 Mesh_Width;    /*!< Number of horizontal nodes */
    UINT8 Mesh_Height;   /*!< Number of vertical nodes */
    UINT8 Mesh_Scale;    /*!< Mesh scaling */
    UINT16 Plane_Offset; /*!< Offset to next plane of mesh data */
    UINT16 Line_Offset;  /*!< Offset to next line of mesh data */
} drvISP_CaCfg_t;

/*! Chromatic Aberration filter LUT entry
 * Each entry address corresponds to fractional part of the pixel displacement.<br>
 * Each entry is four 8-bit filter coefficients in fix point format.<br>
 * - Codes 0...128 correspond to values 0.0 ... 1.0 (with resolution 1/128)<br>
 * - Codes 129...191 correspond to values 129/128 ... 191/128<br>
 * - Codes 192...255 correspond to values -64/128 ... -1/128 */
typedef struct {
    UINT8 Coeff[4]; /*!< 1 to 4 Coefficient */
} drvISP_CaFiltLutEntry_t;

/*! Chromatic Aberration filter LUT configuration */
typedef struct {
    drvISP_CaFiltLutEntry_t *pEntry; /*!< Entries pointer (See #drvISP_CaFiltLutEntry_t) */
    UINT8 Size;                      /*!< Number of entries. */
} drvISP_CaFiltLutCfg_t;

/*! Chromatic Aberration correctionLUT configuration
 * Chromatic aberration correction coordinate lookup table, 8192 entries for tile displacement of 16 bits each.<br>
 * Each entry is 16 bits, 8 LSBs is X displacement of the tile and 8 MSBs is Y displacement.<br>
 * The coordiantes are coded as two's complement, 3.5 fixed point.
 * */
typedef struct {
    UINT16 *pEntry; /*!< Entries pointer. */
    UINT16 Size;    /*!< Number of entries. */
} drvISP_CaCorrLutCfg_t;

/*! Radial Shading shading map configuration */
typedef struct {
    UINT16 Center_X;          /*!< Center x coordinate of the shading map */
    UINT16 Center_Y;          /*!< Center y coordinate of the shading map */
    UINT16 Off_Center_Mult_X; /*!< Normalizing X factor which scales the radial table to the edge of the image.<br>
                                   Calculated as \f$ 2^{31}/R^2 \f$ where R is the furthest distance from the center coordinate to the edge of the image in pixels. */
    UINT16 Off_Center_Mult_Y; /*!< Normalizing Y factor which scales the radial table to the edge of the image.<br>
                                   Calculated as \f$ 2^{31}/R^2 \f$ where R is the furthest distance from the center coordinate to the edge of the image in pixels. */
} drvISP_RS_ShMapCfg_t;

/*! Radial Shading configuration */
typedef struct {
    UINT8 Enable;            /*!< Enable */
    drvISP_RS_ShMapCfg_t R;  /*!< Red shading correction configuration */
    drvISP_RS_ShMapCfg_t G;  /*!< Green shading correction configuration. */
    drvISP_RS_ShMapCfg_t B;  /*!< Blue shading correction configuration. */
    drvISP_RS_ShMapCfg_t Ir; /*!< Ir shading correction configuration. */
} drvISP_RadialShadingCfg_t;

/*! Radial Shading LUT configuration
 * Each entry occupies 32 bits, of which 16 least significant bits are encoding shading correction factor in 4.12 fix point format.
 * */
typedef struct {
    UINT16 *pR_Data;  /*!< Red Entries pointer. Value should be Shading correction factor in 4.12 fix point format */
    UINT16 *pG_Data;  /*!< Green Entries pointer. Value should be Shading correction factor in 4.12 fix point format */
    UINT16 *pB_Data;  /*!< Blue Entries pointer. Value should be Shading correction factor in 4.12 fix point format */
    UINT16 *pIr_Data; /*!< Infra Red Entries pointer. Value should be Shading correction factor in 4.12 fix point format */
    UINT16 Size;      /*!< Number of entries. */
} drvISP_RadialShadingLutCfg_t;

/*! Mesh Shading configuration */
typedef struct {
    UINT8 Enable;             /*!< Enable */
    UINT8 Mesh_Show;          /*!< Lens shading correction debug: 0=off, 1=on (show mesh data) */
    UINT8 Mesh_Scale;         /*!< Selects the precision and maximal gain range of mesh shading correction<br>
                                   For scales 0..3 the data format of the mesh table is fixed point 1.7, 2.6, 3.5 and 4.4 respectively.<br>
                                   For scales 4..7 the data format of the mesh table is fixed point 0.8, 1.7, 2.6 and 3.5 respectively.<br>
                                   1 is added to resultant value for scales 4..7.<br>
                                   This results in the following gain ranges for each scale.<br>
                                   00 -> 0..2<br>
                                   01 -> 0..4<br>
                                   02 -> 0..8<br>
                                   03 -> 0..16<br>
                                   04 -> 1..2<br>
                                   05 -> 1..3<br>
                                   06 -> 1..5<br>
                                   07 -> 1..9 */
    UINT8 Mesh_Page_R;        /*!< Selects memory page for red pixels correction.  */
    UINT8 Mesh_Page_G;        /*!< Selects memory page for green pixels correction.  */
    UINT8 Mesh_Page_B;        /*!< Selects memory page for blue pixels correction.  */
    UINT8 Mesh_Page_Ir;       /*!< Selects memory page for IR pixels correction. */
    UINT8 Mesh_Width;         /*!< Number of horizontal nodes minus 1 */
    UINT8 Mesh_Height;        /*!< Number of vertical nodes minus 1 */
    UINT8 Mesh_Alpha_Mode;    /*!< Sets alpha blending between mesh shading tables.<br>
                                   0 = no alpha blending<br>
                                   1=2 banks (odd/even bytes)<br>
                                   2=4 banks (one per 8 bit lane in each dword) */
    UINT8 Mesh_Alpha_R;       /*!< Alpha blend coeff for R */
    UINT8 Mesh_Alpha_Bank_R;  /*!< Bank selection for R blend: 0: 0+1; 1: 1+2; 2: 2:3; 3: 3+0; 4:0+2; 5: 1+3; 6,7: reserved */
    UINT8 Mesh_Alpha_G;       /*!< Alpha blend coeff for G */
    UINT8 Mesh_Alpha_Bank_G;  /*!< Bank selection for G blend: 0: 0+1; 1: 1+2; 2: 2:3; 3: 3+0; 4:0+2; 5: 1+3; 6,7: reserved */
    UINT8 Mesh_Alpha_B;       /*!< Alpha blend coeff for B */
    UINT8 Mesh_Alpha_Bank_B;  /*!< Bank selection for B blend: 0: 0+1; 1: 1+2; 2: 2:3; 3: 3+0; 4:0+2; 5: 1+3; 6,7: reserved */
    UINT8 Mesh_Alpha_Ir;      /*!< Alpha blend coeff for Ir */
    UINT8 Mesh_Alpha_Bank_Ir; /*!< Bank selection for Ir blend: 0: 0+1; 1: 1+2; 2: 2:3; 3: 3+0; 4:0+2; 5: 1+3; 6,7: reserved */
    UINT16 Mesh_Strength;     /*!< Mesh strength in 4.12 format, e.g. 0 - no correction, 4096 - correction to match mesh data.<br>
                                   Can be used to reduce shading correction based on AE. */
} drvISP_MeshShadingCfg_t;

/*! Mesh Shading LUT configuration */
typedef struct {
    UINT32 *pEntry; /*!< Entries pointer. */
    UINT16 Size;    /*!< Number of entries. */
} drvISP_MeshShadingLutCfg_t;

/*! Demosaic AC, Sat blending configuration */
typedef struct {
    UINT8 Slope;   /*!< Slope of blending threshold<br>
                        Format: unsigned 2.6-bit fixed point */
    UINT16 Thresh; /*!< Threshold for the range of blending<br>
                        Format: unsigned 3.11-bit fixed-point */
    UINT16 Offset; /*!< Offset for blending threshold<br>
                        Format: sign/magnitude 3.11-bit fixed-point */
} drvISP_DemBlCfg_t;

/*! Demosaic VH, VA, AA, UU blending configuration */
typedef struct {
    UINT8 Slope;   /*!< Slope of blending threshold<br>
                        Format: logarithmic 4.4 fixed point */
    UINT16 Thresh;  /*!< Threshold for the range of blending<br>
                        Format: unsigned 2.6-bit fixed-point */
    UINT16 Offset; /*!< Offset for blending threshold<br>
                        Format: TBD */
} drvISP_DemBlLogCfg_t;

/*! RGBIr demosaic configuration */
typedef struct {
    UINT16 Clip_Level;                   /*!< Pixel values above this are deemed to be clipped */
    UINT16 Clip_Debloom;                 /*!< Debloom level */
    UINT16 IrCorrMat[4][4];              /*!< Coefficients for IR correction. Coefficients on main diagonal should be at least 256 (0.25).<br>
                                              Format: unsigned 2.10-bit fixed-point */
    UINT16 Gain_R;                       /*!< White Balance gain for Red channel of output<br>
                                              Format: unsigned 4.8-bit fixed-point */
    UINT16 Gain_B;                       /*!< White Balance gain for Blue channel of output<br>
                                              Format: unsigned 4.8-bit fixed-point */
    UINT16 Static_Gain_R;                /*!< Static White Balance gain for Red channel of input<br>
                                              Format: unsigned 4.8-bit fixed-point */
    UINT16 Static_Gain_B;                /*!< Static White Balance gain for Blue channel of input<br>
                                              Format: unsigned 4.8-bit fixed-point */
    UINT16 Static_Gain_I;                /*!< Static White Balance gain for IR channel of input<br>
                                              Format: unsigned 4.8-bit fixed-point */
    UINT16 Interpolation_Directionality; /*!< Sensitivity of directional interpolation to local gradient. Lower value means more sensitive. Increasing value will eventually result in bilinear demosaic */
    UINT16 FC_Low;                       /*!< Value to start Colour Aliasing Alpha ramp */
    UINT16 FC_Grad;                      /*!< Gradient of Colour Aliasing Alpha ramp<br>
                                              Format: unsigned 5.7-bit fixed-point */
    UINT16 Sharp_Low;                    /*!< Sharpening strength in flat regions<br>
                                              Format: unsigned 2.10-bit fixed-point */
    UINT16 Sharp_High;                   /*!< Sharpening strength in edge and detail regions<br>
                                              Format: unsigned 2.10-bit fixed-point */
    UINT16 Sharp_Limit;                  /*!< Limit sharpening amount to prevent overshoot */
    UINT8 Declip_Mode;                   /*!< Method of declipping in regions where R, G, and B are all clipped<br>
                                              0 = Use local intensity to estimate.
                                              1 = Use constant value of 1. */
} drvISP_DemRGBI_Cfg_t;

/*! RCCC demosaic configuration */
typedef struct {
    UINT16 Gain_R;                       /*!< Gain of Red channel (relative to the clear channel) - used for WDR feature. */
    UINT16 Interpolation_Directionality; /*!< Sensitivity of directional interpolation to local gradient. Lower value means more sensitive.<br>
                                              Increasing value will eventually result in bilinear demosaic. */
    UINT16 C2_imbalance_strength;        /*!< Strength of correction for clear channel directly above/below red pixels. */
    UINT16 C3_imbalance_strength;        /*!< Strength of correction for clear channel diagonally between red pixels. */
    UINT16 Flatness_value;               /*!< Sensitivity of directional interpolation to local gradient, in interpolation of C values at R location.<br>
                                              Lower value means more sensitive. */
    UINT16 Sharp_Low;                    /*!< Sharpening strength in edge and detail regions.<br>
                                              Format: unsigned 2.10-bit fixed-point */
    UINT16 Sharp_High;                   /*!< Sharpening strength in flat regions.<br>
                                              Format: unsigned 2.10-bit fixed-point */
    UINT16 Sharp_Limit;                  /*!< Limit sharpening amount to prevent overshoot.<br>
                                              Format: unsigned 4.10-bit fixed-point */
    UINT16 WDR_Thresh_high;              /*!< Value at which to end blending ramp for Red/Clear WDR. Clear values above this will not be used. */
    UINT16 WDR_Thresh_low;               /*!< Value at which to begin blending ramp for Red/Clear WDR. */
    UINT16 WDR_Max_gain_rec;             /*!< Reciprocal of maximal WDR gain in Clear channel from Red channel.<br>
                                              Format: unsigned 1.11-bit fixed-point */
} drvISP_DemRCCC_Cfg_t;

/*! RGGB demosaic configuration */
typedef struct {
    drvISP_DemBlLogCfg_t VH; /*!< Vertical/Horizontal blending configuration */
    drvISP_DemBlLogCfg_t AA; /*!< Angular (45, 135 deg) blending configuration */
    drvISP_DemBlLogCfg_t VA; /*!< Vertical/Angular blending configuration */
    drvISP_DemBlLogCfg_t UU; /*!< Undefined blending configuration */
    drvISP_DemBlCfg_t Sat;   /*!< Saturation blending configuration */
    drvISP_DemBlCfg_t AC;    /*!< Alias Correction configuration */
    UINT16 Luminance_Th;      /*!< Luminance threshold for directional sharpening */
    UINT8 FC_Slope;          /*!< Slope (strength) of false color correction<br>
                                  Format:logarithmic 4.4-bit fixed-point */
    UINT8 FC_Alias_Slope;    /*!< Slope (strength) of false colour correction after blending with saturation value<br>
                                  Format: unsigned 2.6-bit fixed-point */
    UINT8 FC_Alias_Thresh;   /*!< Threshold of false colour correction after blending with saturation value<br>
                                  Format: unsigned 0.8-bit fixed-point */
    UINT8 Sad_Amplifier;     /*!< Sad amplifier<br>
                                  Format: unsigned 4.4-bit fixed-point */
    UINT8 Sharp_Algorithm;   /*!< Sharpening algorithm (0=old, 1=new) */
    UINT8 Sharp_Str_d;       /*!< Directional sharp mask strength<br>
                                  Format: sign/magnitude 4.4-bit fixed-point */
    UINT8 Sharp_Str_ud;      /*!< Non-directional sharp mask strength<br>
                                  Format: sign/magnitude 4.4-bit fixed-point */
    UINT8 Sharp_Str_Lu;      /*!< Sharpen strength for L_Lu<br>
                                  Format: unsigned 4.4-bit fixed-point */
    UINT8 Sharp_Str_Ldu;     /*!< Sharpen strength for L_Ldu<br>
                                  Format: unsigned 4.4-bit fixed-point */
    UINT8 Sharp_Str_Ld;      /*!< Sharpen strength for L_Ld<br>
                                  Format: unsigned 4.4-bit fixed-point */
    UINT16 Thresh_Min_d;     /*!< Min threshold for the directional L_L<br>
                                  Format: signed 2's complement s.12 */
    UINT16 Thresh_Min_ud;    /*!< Min threshold for the un-directional L_Lu<br>
                                  Format: signed 2's complement s.12 format */
} drvISP_DemRGGB_Cfg_t;

/*! Demosaic configuration */
typedef struct {
    UINT8 Enable;              /*!< Enable */
    drvISP_DemRGGB_Cfg_t RGGB; /*!< RGGB demosaic configuration */
    drvISP_DemRGBI_Cfg_t RGBI; /*!< RGBIr demosaic configuration */
    drvISP_DemRCCC_Cfg_t RCCC; /*!< RCCC demosaic configuration */
} drvISP_DemCfg_t;

/*! Demosaic Noise Profile configuration */
typedef struct {
    UINT8 Noise_Profile_Offset; /*!< Noise profile offset in logarithmic 4.4 format */
    UINT8 Black_Offset;         /*!< Noise profile black level offset. */
    UINT8 Below_Black_Mode;     /*!< Defines how values below black level are obtained.<br>
                                     0: Repeat the first table entry.<br>
                                     1: Reflect the noise profile curve below black level */
    drvISP_NpLUT_t LUT;         /*!< Noise Profile LUT (See #drvISP_NpLUT_t) */
} drvISP_DemNpCfg_t;

/*! Crop configuration */
typedef struct {
    UINT8 Enable;   /*!< Enable */
    UINT16 start_x; /*!< Horizontal offset from left side of image in pixels for output crop window */
    UINT16 start_y; /*!< Vertical offset from top of image in lines for output crop window */
    UINT16 size_x;  /*!< Width of output crop window */
    UINT16 size_y;  /*!< Height of output crop window */
} drvISP_CropCfg_t;

/*! 3x4 Matrix<br> <br>
 * \f$
 * \begin{bmatrix}
 * OUT_0 \\ OUT_1 \\ OUT_2 \\
 * \end{bmatrix}
 * =
 * \begin{bmatrix}
 * C_{00} C_{01} C_{02} C_{03} \\
 * C_{10} C_{11} C_{12} C_{13} \\
 * C_{20} C_{21} C_{22} C_{23} \\
 * \end{bmatrix}
 * *
 * \begin{bmatrix}
 * IN_0 \\ IN_1 \\ IN_2 \\ IN_3 \\
 * \end{bmatrix}
 * +
 * \begin{bmatrix}
 * B_0 \\ B_1 \\ B_2 \\
 * \end{bmatrix}
 * \f$
 * */
typedef struct {
    UINT8 Enable;   /*!< Enable */
    UINT16 c[3][4]; /*!< Coefficients - Format: sign/magnitude 8.8-bit fixed-point */
    UINT16 b[3];    /*!< Offsets - Format: signed (2's complement) 15-bit integer */
} drvISP_3x4_Matrix_t;

/*! 3x3 Matrix<br> <br>
 * \f$
 * \begin{bmatrix}
 * OUT_0 \\ OUT_1 \\ OUT_2 \\
 * \end{bmatrix}
 * =
 * \begin{bmatrix}
 * C_{00} C_{01} C_{02} \\
 * C_{10} C_{11} C_{12} \\
 * C_{20} C_{21} C_{22} \\
 * \end{bmatrix}
 * *
 * \begin{bmatrix}
 * IN_0 \\ IN_1 \\ IN_2 \\
 * \end{bmatrix}
 * +
 * \begin{bmatrix}
 * B_0 \\ B_1 \\ B_2 \\
 * \end{bmatrix}
 * \f$
 * */
typedef struct {
    UINT8 Enable;   /*!< Enable */
    UINT16 c[3][3]; /*!< Coefficients - Format: sign/magnitude 8.8-bit fixed-point */
    UINT16 b[3];    /*!< Offsets - Format: signed (2's complement) 15-bit integer */
} drvISP_3x3_Matrix_t;

/*! Output Formatter Clipping configuration */
typedef struct {
    UINT8 Enable;    /*!< Enable */
    UINT16 Value[4]; /*!< Maximum value for input video data of the channel n. Values above this are clipped.<br>
                          Format: unsigned 14-bit integer */
} drvISP_OutFormClipCfg_t;

/*! Output Formatter LUT */
typedef struct {
    UINT8 Enable;   /*!< Enable */
    UINT32 *pEntry; /*!< LUT entries pointer. Format for all nodes of this LUT:<br>
                         if [17:16] = 3 then format is: signed (2's complement) 15.3-bit fixed-point<br>
                         else format is: unsigned 15.3-bit fixed-point */
    UINT32 Size;    /*!< Number of entries. */
} drvISP_OutForm_LUT_t;

/*! Output Formatter LPF */
typedef struct {
    UINT8 Enable;                /*!< Enable */
    UINT8 Horizontal_Downsample; /*!< Horizontal Downsampling Enable */
    UINT8 Vertical_Downsample;   /*!< Vertical Downsampling Enable */
    UINT8 Horizontal_Filter;     /*!< Filter Enable */
} drvISP_2DLPF_t;

/*! Output Formatter YUV LPF */
typedef struct {
    UINT8 Enable;                /*!< Enable */
    UINT8 Horizontal_Downsample; /*!< Horizontal Downsampling Enable */
} drvISP_YUV_LPF_t;

/*! Output Formatter RGB2S conversion mode */
typedef enum {
    ISP_OUTF_RGB2S_MODE_0 = 0u, /*!< S=(max(R,G,B)-min(R,G,B))/2 */
    ISP_OUTF_RGB2S_MODE_1,      /*!< S=max(0,max(R,G,B)-max(min(R,G,B),ClipValue)) (See #drvISP_OutForm_Ss_Cfg_t) */
    ISP_OUTF_RGB2S_MODE_2       /*!< S=max(R,G,B)/max(min(R,G,B),ClipValue) (See #drvISP_OutForm_Ss_Cfg_t) */
} drvISP_OutForm_RGB2S_Mode_t;

/*! Output Formatter<br>
 *  Subsampling mode of IR channel video data
 */
typedef enum {
    ISP_OUTF_IR_SUBS_NONE  = 0x00u, /*!< Disabled */
    ISP_OUTF_IR_SUBS_ER_EC = 0x04u, /*!< Even row and even column pixels are selected */
    ISP_OUTF_IR_SUBS_ER_OC = 0x05u, /*!< Even row and odd column pixels are selected */
    ISP_OUTF_IR_SUBS_OR_EC = 0x06u, /*!< Odd row and even column pixels are selected */
    ISP_OUTF_IR_SUBS_OR_OC = 0x07u  /*!< Odd row and odd column pixels are selected */
} drvISP_OutForm_Ir_SubsMode_t;

/*! Output Formatter Ir output configuration */
typedef struct {
    UINT8 ChannelNumber;                      /*!< Selector of video data channel for IR pipeline from four input video data channels */
    drvISP_OutForm_Ir_SubsMode_t SubSampMode; /*!< Subsampling mode of IR channel video data (see #drvISP_OutForm_Ir_SubsMode_t) */
    drvISP_OutForm_LUT_t LUT;                 /*!< LUT (see #drvISP_OutForm_LUT_t) */
} drvISP_OutForm_Ir_Cfg_t;

/*! Output Formatter LUV output configuration */
typedef struct {
    drvISP_OutFormClipCfg_t Clip; /*!< Clipping configuration */
    drvISP_3x4_Matrix_t RGB2XYZ;  /*!< RGB to XYZ conversion matrix (see #drvISP_3x4_Matrix_t) */
    UINT8 EnableXYZtoLUV;         /*!< Enable XYZ to LUV conversion */
    drvISP_2DLPF_t LPF;           /*!< 2D LPF (see #drvISP_2DLPF_t) */
    drvISP_OutForm_LUT_t LUT;     /*!< LUT (see #drvISP_OutForm_LUT_t) */
} drvISP_OutForm_LUV_Cfg_t;

/*! Output Formatter S* output configuration */
typedef struct {
    UINT8 Enable;                     /*!< Enable */
    drvISP_OutForm_RGB2S_Mode_t Mode; /*!< RGB to S conversion mode (see #drvISP_OutForm_RGB2S_Mode_t) */
    UINT16 ClipValue;                 /*!< Clipping value for Mode 1,2 (See #drvISP_OutForm_RGB2S_Mode_t) */
} drvISP_OutForm_Ss_Cfg_t;

/*! Output Formatter HS output configuration */
typedef struct {
    UINT8 EnableRGB2AB; /*!< Enable RGB 2 AB conversion */
    UINT8 EnableAB2HS;  /*!< Enable AB to HS conversion */
    drvISP_2DLPF_t LPF; /*!< 2D LPF (see #drvISP_2DLPF_t) */
} drvISP_OutForm_HS_Cfg_t;

/*! Output Formatter YUV Special Mode Configuration */
typedef enum {
    ISP_OUTF_YUV_SP_MODE_0 = 0u, /*!< U=(B-G+2048)/16, V=(R-G+2048)/16 */
    ISP_OUTF_YUV_SP_MODE_1,      /*!< U=B/max(G,ClipValue), V=R/max(G,ClipValue) (See #drvISP_OutForm_YUV_Cfg_t) */
    ISP_OUTF_YUV_SP_MODE_2,      /*!< Y=(R+2G+B)/4 */
    ISP_OUTF_YUV_SP_MODE_3,      /*!< Y=(R+G+B)/3 */
    ISP_OUTF_YUV_MODE_MATRIX     /*!< Use matrix RGB2YUV (See #drvISP_3x3_Matrix_t) */
} drvISP_OutForm_YUV_Mode_t;

/*! Output Formatter YUV output configuration */
typedef struct {
    drvISP_OutForm_YUV_Mode_t Mode; /*!< YUV Conversion Mode (See #drvISP_OutForm_YUV_Mode_t) */
    UINT16 ClipValue;               /*!< Clipping value for Mode 1 */
    drvISP_3x3_Matrix_t RGB2YUV;    /*!< RGB to YUV conversion matrix (see #drvISP_3x3_Matrix_t) */
    drvISP_YUV_LPF_t LPF;           /*!< 2D LPF (see #drvISP_YUV_LPF_t) */
    drvISP_OutForm_LUT_t LUT;       /*!< LUT (see #drvISP_OutForm_LUT_t) */
} drvISP_OutForm_YUV_Cfg_t;

/*! Output Formatter HS/RGB/YUV branch configuration */
typedef struct {
    drvISP_OutFormClipCfg_t Clip; /*!< Clipping (See #drvISP_OutFormClipCfg_t) */
    drvISP_3x4_Matrix_t RGB2RGB;  /*!< RGB to RGB conversion matrix (see #drvISP_3x4_Matrix_t) */
    drvISP_OutForm_LUT_t LUT;     /*!< Gamma LUT (see #drvISP_OutForm_LUT_t) */
    drvISP_OutForm_Ss_Cfg_t Ss;   /*!< S configuration */
    drvISP_OutForm_HS_Cfg_t HS;   /*!< HS configuration */
    drvISP_OutForm_YUV_Cfg_t YUV; /*!< YUV configuration */
} drvISP_OutForm_HSRGBYUV_Cfg_t;

/*! Output Formatter configuration
 * @image html pics/output_formatter.png
 * */
typedef struct {
    UINT8 Enable;                           /*!< Enable */
    UINT8 RawSelect;                        /*!< Source for raw data output in the output mux:<br>
                                                 0 = Companded sensor data<br>
                                                 1 = Frame stitch<br>
                                                 2 = Post gamma FE companding curve<br>
                                                 3 = Tone mapped data */
    drvISP_OutForm_Ir_Cfg_t Ir;             /*!< Output Formatter Ir branch configuration (see #drvISP_OutForm_Ir_Cfg_t) */
    drvISP_OutForm_LUV_Cfg_t LUV;           /*!< Output Formatter LUV branch configuration (see #drvISP_OutForm_LUV_Cfg_t) */
    drvISP_OutForm_HSRGBYUV_Cfg_t HSRGBYUV; /*!< Output Formatter HS/RGB/YUV branch configuration (see #drvISP_OutForm_HSRGBYUV_Cfg_t) */
} drvISP_OutFormCfg_t;

/*!
 * @brief Event callback function
 * @details Called upon an event occurs
 * @param Slot Current slot in use
 * @param Event Event occurred
 * @param Status Event status register
 * @return None
 */
typedef void (*drvISP_EventCb_t)(UINT8 Slot, drvISP_EventType_t EventType, UINT32 Status);

/*!
 * @brief   Lock function
 * @details Controls a mutex (system dependent) for a thread safe usage
 * @param   uUnit The ISP number
 * @param   uContext Context to use (see #UINT64)
 * @param   Lock 1 = Lock<br>0 = Unlock
 * @return  Error code (UINT16)
 */
typedef UINT16 (*drvISP_LockCb_t)(UINT8 uUnit, UINT64 uContext, UINT8 Lock);

/*!
 * @brief   Read register callback
 * @details Read a 32bit register
 * @param   Addr Register address
 * @return  Register value
 */
typedef UINT32 (*drvISP_ReadReg32Cb_t)(UINT64 Addr);

/*!
 * @brief   Write register callback
 * @details Write a 32bit register
 * @param   Addr Register address
 * @param   Data Register data
 * @return None
 */
typedef void (*drvISP_WriteReg32Cb_t)(UINT64 Addr, UINT32 Data);

/*!
 * @brief   Write register callback
 * @details Translate the argument into a physical memory address and write 32bit register
 * @param   Addr Register address
 * @param   Mvirt Virtual memory address
 * @param   Msize Size of the memory area that the HW can alter (used in safe environments)
 * @return None
 */
typedef void (*drvISP_WriteReg32MphysCb_t)(UINT64 Addr, UINT64 Mvirt, UINT64 Msize);

/*!
 * @brief   Interrupt callback prototype
 * @details The prototype of the function that will be called upon interrupt notification
 * @param   SpiID Interrupt number
 * @return None
 */
typedef void (*drvISP_IntCbFunc_t)(UINT16 SpiID);

/*!
 * @brief   Register interrupt callback
 * @details Register the interrupt callback
 * @param   CallbackFunc Callback function to be registered
 * @return  Error code (UINT16)
 */
typedef UINT16 (*drvISP_IntRegisterIntCb_t)(drvISP_IntCbFunc_t CallbackFunc);

/*!
 * @brief   Unregister interrupt callback
 * @details Unregister the interrupt callback
 * @return  Error code (UINT16)
 */
typedef UINT16 (*drvISP_IntUnregisterIntCb_t)(void);

/*! Interrupt configuration */
typedef struct {
    UINT16                      SpiID;           /*!< Interrupt number */
    drvISP_IntRegisterIntCb_t   RegisterIntCb;   /*!< Register interrupt callback */
    drvISP_IntUnregisterIntCb_t UnregisterIntCb; /*!< unregister interrupt callback */
} drvISP_IntCbCfg_t;

/*! Memory configuration */
typedef struct {
    UINT8                      DryRun;            /*!< 0=normal mode, 1=Skip the HW and use only context related functions to program memory buffers */
    UINT64                     RegBaseAddr;       /*!< Register base address */
    drvISP_ReadReg32Cb_t       ReadReg32Cb;       /*!< Read 32bit register */
    drvISP_WriteReg32Cb_t      WriteReg32Cb;      /*!< Write 32bit register */
    drvISP_WriteReg32MphysCb_t WriteReg32MphysCb; /*!< Translate the argument into a physical memory address and write 32bit register */
} drvISP_MemCfg_t;

/*!
 * @brief   Wait callback
 * @details Wait function (system dependent)
 * @param   WaitMs ms to wait
 * @return  Error code (UINT16)
 */
typedef UINT16 (*drvISP_WaitMsCb_t) (UINT32 WaitMs);

/*! Initialization configuration */
typedef struct { 
    drvISP_MemCfg_t   MemCfg;   /*!< Memory configuration */
    drvISP_IntCbCfg_t IntCbCfg; /*!< Interrupt configuration */
    drvISP_LockCb_t   LockCb;   /*!< Mutex callback */
    drvISP_WaitMsCb_t WaitMsCb; /*!< Wait callback (ms) */
} drvISP_InitCfg_t;

/*! @defgroup group1 Context Independent Functions
 *  This group of settings is independent from the context.
 *  @{
 */

/*! @defgroup subgroup1_1 General
 *  General functions.
 *  @{
 */

/*!
 *  @brief          Start the clock supply to ISP module supply and initialize the mutex
 *  @details
 *  @param          uUnit The ISP number
 *  @param          pConfig Abstraction layer configuration (see #drvISP_InitCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_Init(UINT8 uUnit, drvISP_InitCfg_t *pConfig);

/*!
 *  @brief          Deinitialize the ISP module and stop the clock supply
 *  @details
 *  @param          uUnit The ISP number
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_DeInit(UINT8 uUnit);

/*!
 *  @brief          Open the ISP channel and initialize the default values
 *  @details
 *  @param          uUnit The ISP number
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_Open(UINT8 uUnit);

/*!
 *  @brief          Close the ISP channel
 *  @details
 *  @param          uUnit The ISP number
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_Close(UINT8 uUnit);

/*!
 *  @brief          Initialize a memory area with a proper base configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SlotInit(UINT8 uUnit, UINT64 uContext);

/*!
 *  @brief      ISP Set Event callback
 *  @details    Enable/disable an event notification and set the callback.
 *  @param      uUnit The ISP number
 *  @param      Event Event that runs the callback (see #drvISP_EventType_t)
 *  @param      Callback Callback (see #drvISP_EventCb_t)
 *  @param      pConfig Configuration structure (see #drvISP_EventIntCfg_t)
 *  @return         UINT16
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetEventCb(UINT8 uUnit, drvISP_EventType_t Event, drvISP_EventCb_t Callback, const drvISP_EventIntCfg_t *pConfig);

/*!
 *  @brief      ISP Set Fault notification configuration
 *  @details    Set which faults are notified to MFIS
 *  @param      uUnit The ISP number
 *  @param      pConfig Configuration structure (see #drvISP_Fault_t)
 *  @return     UINT16 0 on success or error code on failure
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetFaultInt(UINT8 uUnit, const drvISP_Fault_t *pConfig);

/*!
 *  @brief      ISP Get Fault notification configuration
 *  @details    Get which faults are notified to MFIS
 *  @param      uUnit The ISP number
 *  @param      pConfig Configuration structure (see #drvISP_Fault_t)
 *  @return     UINT16 0 on success or error code on failure
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetFaultInt(UINT8 uUnit, drvISP_Fault_t *pConfig);

/*!
 *  @brief      ISP Get fault status
 *  @details    Get the fault status registers and clear the fault interrupt.
 *  @param      uUnit The ISP number
 *  @param      pStatus Fault status structure (see #drvISP_Fault_t)
 *  @return     UINT16 0 on success or error code on failure
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetFaultStatus(UINT8 uUnit, drvISP_Fault_t *pStatus);

/*!
 *  @brief          Set the scheduler mode
 *  @details
 *  @param          uUnit The ISP number
 *  @param          enMode Scheduler mode
 *                  0 = Stopped
 *                  1 = Manual scheduling
 *                  2 = Single stream on first input
 *                  3 = Dual stream (FIFO only)
 *                  4 = Dual stream (frame buffer)
 *                  5 = Triple stream (first through frame buffer, second through FIFO, third direct)
 *                  6 = Quad stream (first and second through frame buffer, third through FIFO, fourth
 *                  direct)
 *                  7 = Single stream DOL, configuraton is defined by input_mode (valid input_modes
 *                  0..2)
 *                  8 = Two sensors TDMF flex schedule
 *                  9 = Two 2x DOL sensors TDMF flex schedule
 *                  10 = Three sensors TDMF flex schedule
 *                  11 = Four sensors TDMF flex schedule
 *                  12 = Two sensors TDMF fix schedule
 *                  13 = Two 2x DOL sensors TDMF fix schedule
 *                  14 = Three sensors TDMF fix schedule
 *                  15 = Four sensors TDMF fix schedule
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetScheduler(UINT8 uUnit, drvISP_SchedulerMode_t enMode);

/*!
 *  @brief          Get the scheduler mode
 *  @details
 *  @param          uUnit The ISP number
 *  @param          pMode Scheduler mode
 *                  0 = Stopped
 *                  1 = Manual scheduling
 *                  2 = Single stream on first input
 *                  3 = Dual stream (FIFO only)
 *                  4 = Dual stream (frame buffer)
 *                  5 = Triple stream (first through frame buffer, second through FIFO, third direct)
 *                  6 = Quad stream (first and second through frame buffer, third through FIFO, fourth
 *                  direct)
 *                  7 = Single stream DOL, configuraton is defined by input_mode (valid input_modes
 *                  0..2)
 *                  8 = Two sensors TDMF flex schedule
 *                  9 = Two 2x DOL sensors TDMF flex schedule
 *                  10 = Three sensors TDMF flex schedule
 *                  11 = Four sensors TDMF flex schedule
 *                  12 = Two sensors TDMF fix schedule
 *                  13 = Two 2x DOL sensors TDMF fix schedule
 *                  14 = Three sensors TDMF fix schedule
 *                  15 = Four sensors TDMF fix schedule
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetScheduler(UINT8 uUnit, drvISP_SchedulerMode_t *pMode);

/*!
 *  @brief          Start a context
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context number
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_Start(UINT8 uUnit, UINT64 uContext);

/*!
 *  @brief          Stop the execution
 *  @details
 *  @param          uUnit The ISP number
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_Stop(UINT8 uUnit);

/*!
 *  @brief          Abort the current frame processing
 *  @details
 *  @param          uUnit The ISP number
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_FrameAbort(UINT8 uUnit);

/*!
 *  @brief      ISP Get frame counters
 *  @details    Get the current frame counters values
 *  @param      uUnit The ISP number
 *  @param      pData Frame counters data (see #drvISP_FrameCntData_t)
 *  @return     Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetFrameCntData(UINT8 uUnit, drvISP_FrameCntData_t *pData);

/*!
 *  @brief      ISP Reset frame counters
 *  @details    Reset the current frame counters values
 *  @param      uUnit The ISP number
 *  @return     Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_ResetFrameCnt(UINT8 uUnit);

/*!
 *  @brief          Dump the ISP apertures on the console (development only)
 *  @details
 *  @param          uUnit The ISP number
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_DumpApertures(UINT8 uUnit);

/*! @} */ // end of subgroup1_1

/*! @defgroup subgroup1_2 Input Buffers
 *  Input (RAW) buffers configuration.
 *  @{
 */

/*!
 *  @brief          Set the RAW buffers configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uBufIndex Buffer index
 *  @param          pConfig Configuration structure (see #drvISP_BufCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetInBuffer(UINT8 uUnit,UINT8 uBufIndex, const drvISP_BufCfg_t *pConfig);

/*!
 *  @brief          Get the RAW buffers configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uBufIndex Buffer index
 *  @param          pConfig Configuration structure (see #drvISP_BufCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetInBuffer(UINT8 uUnit, UINT8 uBufIndex, drvISP_BufCfg_t *pConfig);

/*!
 *  @brief          Set the RAW buffers status
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uBufIndex Buffer index
 *  @param          Status Buffer status (see #drvISP_BufStatus_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetInBufferStatus(UINT8 uUnit, UINT8 uBufIndex, drvISP_BufStatus_t enStatus);

/*!
 *  @brief          Get the RAW buffers status
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uBufIndex Buffer index
 *  @param          pStatus Buffer status (see #drvISP_BufStatus_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetInBufferStatus(UINT8 uUnit, UINT8 uBufIndex, drvISP_BufStatus_t *pStatus);

/*! @} */ // end of subgroup1_2

/*! @defgroup subgroup1_3 Output Buffers
 *  Output buffers configuration.
 *  @{
 */

/*!
 *  @brief          Set the Output buffers configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uBufIndex Buffer index
 *  @param          pConfig Configuration structure (see #drvISP_BufCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetOutBuffer(UINT8 uUnit, UINT8 uBufIndex, const drvISP_BufCfg_t *pConfig);

/*!
 *  @brief          Set the Output buffers configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uBufIndex Buffer index
 *  @param          pConfig Configuration structure (see #drvISP_BufCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetOutBuffer(UINT8 uUnit, UINT8 uBufIndex, drvISP_BufCfg_t *pConfig);

/*!
 *  @brief          Set the Output buffers status
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uBufIndex Buffer index
 *  @param          Status Buffer status (see #drvISP_BufStatus_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetOutBufferStatus(UINT8 uUnit, UINT8 uBufIndex, drvISP_BufStatus_t Status);

/*!
 *  @brief          Get the Output buffers status
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uBufIndex Buffer index
 *  @param          pStatus Buffer status (see #drvISP_BufStatus_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetOutBufferStatus(UINT8 uUnit, UINT8 uBufIndex, drvISP_BufStatus_t *pStatus);

/*! @} */ // end of subgroup1_3

/*! @defgroup subgroup1_4 Input Ports
 *  Input ports configuration.
 *  @{
 */

/*!
 *  @brief          Set the input port configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uPort Input Port Index (0..3)
 *  @param          pConfig Configuration structure (see #drvISP_InputPortCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetInputPort(UINT8 uUnit, UINT8 uPort, const drvISP_InputPortCfg_t *pConfig);

/*!
 *  @brief          Get the input port configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uPort Input Port Index (0..3)
 *  @param          pConfig Configuration structure (see #drvISP_InputPortCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetInputPort(UINT8 uUnit, UINT8 uPort, drvISP_InputPortCfg_t *pConfig);

/*!
 *  @brief          Set the input port size
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uInput Input number (0..3)
 *  @param          pWidth Width of the incoming frames
 *  @param          pHeight Height of the incoming frames
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetInputPortSize(UINT8 uUnit, UINT8 uInput, UINT16 *pWidth, UINT16 *pHeight);

/*! @} */ // end of subgroup1_4

/*! @defgroup subgroup1_5 MCFE Slots
 *  MCFE slots configuration.
 *  @{
 */

/*!
 *  @brief          Set the MCFE slots configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uSlot Slot number
 *  @param          pConfig Configuration structure (see #drvISP_McfeSlotCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetMcfeSlot(UINT8 uUnit, UINT8 uSlot, const drvISP_McfeSlotCfg_t *pConfig);

/*!
 *  @brief          Get the MCFE slots configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uSlot Slot number
 *  @param          pConfig Configuration structure (see #drvISP_McfeSlotCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetMcfeSlot(UINT8 uUnit, UINT8 uSlot, drvISP_McfeSlotCfg_t *pConfig);

/*! @} */ // end of subgroup1_5

/*! @defgroup subgroup1_6 Sensor Frame Check
 *  Sensor Frame Check configuration.
 *  @{
 */

/*!
 *  @brief          Set the Frame check configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uSensor The sensor number
 *  @param          pConfig Configuration structure (see #drvISP_FrameChkCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetSensFrameCheck(UINT8 uUnit, UINT8 uSensor, const drvISP_FrameChkCfg_t *pConfig);

/*!
 *  @brief          Set the Frame check configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uSensor The sensor number
 *  @param          pConfig Configuration structure (see #drvISP_FrameChkCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetSensFrameCheck(UINT8 uUnit, UINT8 uSensor, drvISP_FrameChkCfg_t *pConfig);
 
/*! @} */ // end of subgroup1_6

/*! @} */ // end of group1

/*! @defgroup group2 Context Dependent Functions
 *  This group of settings dependent from the context.
 *  @{
 */

/*! @defgroup subgroup2_1 Video Test generator
 *  Test pattern generator configuration.
 *  @{
 */
 
/*!
 *  @brief          Set the Video Test Generator configuration.
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_VtgCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetVideoTestGen(UINT8 uUnit, UINT64 uContext, const drvISP_VtgCfg_t *pConfig);

/*!
 *  @brief          Get the Video Test Generator configuration.
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_VtgCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetVideoTestGen(UINT8 uUnit, UINT64 uContext, drvISP_VtgCfg_t *pConfig);

/*! @} */ // end of subgroup2_1

/*! @defgroup subgroup2_2 Channel Selector
 *  Channel Selector configuration.
 *  @{
 */
 
/*!
 *  @brief          Set the Channel Selector configuration.
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_ChSelCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetChSelector(UINT8 uUnit, UINT64 uContext, const drvISP_ChSelCfg_t *pConfig);

/*!
 *  @brief          Get the Channel Selector configuration.
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_ChSelCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetChSelector(UINT8 uUnit, UINT64 uContext, drvISP_ChSelCfg_t *pConfig);

/*!
 *  @brief          Set the Frame Stitch Channel Selector configuration.
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_ChSelCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetFsChSelector(UINT8 uUnit, UINT64 uContext, const drvISP_ChSelCfg_t *pConfig);

/*!
 *  @brief          Get the Frame Stitch Channel Selector configuration.
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_ChSelCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetFsChSelector(UINT8 uUnit, UINT64 uContext, drvISP_ChSelCfg_t *pConfig);

/*! @} */ // end of subgroup2_2

/*! @defgroup subgroup2_3 Top
 *  Top configuration.
 *  @{
 */

/*!
 *  @brief          Set the global frame layout
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_TopCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetTop(UINT8 uUnit, UINT64 uContext, const drvISP_TopCfg_t *pConfig);

/*!
 *  @brief          Get the global frame layout
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_TopCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetTop(UINT8 uUnit, UINT64 uContext, drvISP_TopCfg_t *pConfig);

/*! @} */ // end of subgroup2_3

/*! @defgroup subgroup2_4 Input Formatter
 *  Top configuration.
 *  @{
 */

/*!
 *  @brief          Set the input formatter
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_InputFormCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetInputForm(UINT8 uUnit, UINT64 uContext, const drvISP_InputFormCfg_t *pConfig);

/*!
 *  @brief          Get the input formatter
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_InputFormCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetInputForm(UINT8 uUnit, UINT64 uContext, drvISP_InputFormCfg_t *pConfig);

/*! @} */ // end of subgroup2_4

/*! @defgroup subgroup2_5 WDR Offset & Gain
 *  WDR sensor offset and digital gain configuration.
 *  @{
 */

/*!
 *  @brief          Set the WDR Black Offset configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_WdrOffCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetWdrBlOffset(UINT8 uUnit, UINT64 uContext, const drvISP_WdrOffCfg_t *pConfig);

/*!
 *  @brief          Get the WDR Black Offset configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_WdrOffCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetWdrBlOffset(UINT8 uUnit, UINT64 uContext, drvISP_WdrOffCfg_t *pConfig);

/*!
 *  @brief          Set the WDR Gain configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_WdrGainCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetWdrGain(UINT8 uUnit, UINT64 uContext, const drvISP_WdrGainCfg_t *pConfig);

/*!
 *  @brief          Get the WDR Gain configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_WdrGainCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetWdrGain(UINT8 uUnit, UINT64 uContext, drvISP_WdrGainCfg_t *pConfig);

/*! @} */ // end of subgroup2_5

/*! @defgroup subgroup2_6 WDR Frame Stitch
 *  WDR frame stitch configuration.
 *  @{
 */

/*!
 *  @brief          Set the WDR Stitch configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_WdrStCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetWdrStitch(UINT8 uUnit, UINT64 uContext, const drvISP_WdrStCfg_t *pConfig);

/*!
 *  @brief          Get the WDR Stitch configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_WdrStCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetWdrStitch(UINT8 uUnit, UINT64 uContext, drvISP_WdrStCfg_t *pConfig);

/*! @} */ // end of subgroup2_6

/*! @defgroup subgroup2_7 Linear Offset
 *  Sensor linear offset configuration.
 *  @{
 */

/*!
 *  @brief          Set the Linear Offset configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_LinOffCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetLinearOffset(UINT8 uUnit, UINT64 uContext, const drvISP_LinOffCfg_t *pConfig);

/*!
 *  @brief          Get the Linear Offset configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_LinOffCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetLinearOffset(UINT8 uUnit, UINT64 uContext, drvISP_LinOffCfg_t *pConfig);

/*! @} */ // end of subgroup2_7

/*! @defgroup subgroup2_8 Digital Gain
 *  Sensor gain configuration.
 *  @{
 */

/*!
 *  @brief          Set the Digital Gain configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_DgCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetDigitalGain(UINT8 uUnit, UINT64 uContext, const drvISP_DgCfg_t *pConfig);

/*!
 *  @brief          Get the Digital Gain configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_DgCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetDigitalGain(UINT8 uUnit, UINT64 uContext, drvISP_DgCfg_t *pConfig);

/*! @} */ // end of subgroup2_8

/*! @defgroup subgroup2_9 Gamma DL
 *  Gamma DL (and invGamma DL) configuration.
 *  @{
 */

/*!
 *  @brief          Set the Gamma DL configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_GammaDlCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetGammaDL(UINT8 uUnit, UINT64 uContext, const drvISP_GammaDlCfg_t *pConfig);

/*!
 *  @brief          Get the Gamma DL configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_GammaDlCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetGammaDL(UINT8 uUnit, UINT64 uContext, drvISP_GammaDlCfg_t *pConfig);

/*!
 *  @brief          Set the Inverse Gamma DL configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_GammaDlCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetInvGammaDL(UINT8 uUnit, UINT64 uContext, const drvISP_GammaDlCfg_t *pConfig);

/*!
 *  @brief          Get the Inverse Gamma DL configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_GammaDlCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetInvGammaDL(UINT8 uUnit, UINT64 uContext, drvISP_GammaDlCfg_t *pConfig);

/*! @} */ // end of subgroup2_9

/*! @defgroup subgroup2_10 Gamma FE
 *  Gamma Frontend (LUT based) configuration.
 *  @{
 */

/*!
 *  @brief          Set the Gamma FE LUT configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_GammaCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetGammaFE(UINT8 uUnit, UINT64 uContext, const drvISP_GammaCfg_t *pConfig);

/*!
 *  @brief          Get the Gamma FE LUT configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_GammaCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetGammaFE(UINT8 uUnit, UINT64 uContext, drvISP_GammaCfg_t *pConfig);

/*! @} */ // end of subgroup2_10

/*! @defgroup subgroup2_11 RAW Frontend
 *  Green equalization & dynamic defect pixel detection
 *  @{
 */

/*!
 *  @brief          Set the RAW Frontend configuration (green equalization and dynamic defect pixel detection)
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_RawFeCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetRawFE(UINT8 uUnit, UINT64 uContext, const drvISP_RawFeCfg_t *pConfig);

/*!
 *  @brief          Get the RAW Frontend configuration (green equalization and dynamic defect pixel detection)
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_RawFeCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetRawFE(UINT8 uUnit, UINT64 uContext, drvISP_RawFeCfg_t *pConfig);

/*!
 *  @brief          Set the RAW Frontend Noise Profile configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_PipeNpCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetRawFE_NP(UINT8 uUnit, UINT64 uContext, const drvISP_PipeNpCfg_t *pConfig);

/*!
 *  @brief          Get the RAW Frontend Noise Profile configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_PipeNpCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetRawFE_NP(UINT8 uUnit, UINT64 uContext, drvISP_PipeNpCfg_t *pConfig);

/*! @} */ // end of subgroup2_11

/*! @defgroup subgroup2_12 Defect Pixel Correction
 *  Defect pixel correction configuration
 *  @{
 */

/*!
 *  @brief          Set the Static Defect Pixel configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_DefectPixCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetDefectPixel(UINT8 uUnit, UINT64 uContext, const drvISP_DefectPixCfg_t *pConfig);

/*!
 *  @brief          Get the Static Defect Pixel configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_DefectPixCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetDefectPixel(UINT8 uUnit, UINT64 uContext, drvISP_DefectPixCfg_t *pConfig);

/*!
 *  @brief          Get the Defect Pixels status
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pStatus Defect pixels status (see #drvISP_DefectPixSts_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetDefectPixelStatus(UINT8 uUnit, UINT64 uContext, drvISP_DefectPixSts_t *pStatus);

/*!
 *  @brief          Set the Static Defect Pixel Table
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_DefectPixLutCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetDefectPixel_LUT(UINT8 uUnit, UINT64 uContext, const drvISP_DefectPixLutCfg_t *pConfig);

/*!
 *  @brief          Get the Static Defect Pixel Table
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_DefectPixLutCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetDefectPixel_LUT(UINT8 uUnit, UINT64 uContext, drvISP_DefectPixLutCfg_t *pConfig);

/*! @} */ // end of subgroup2_12

/*! @defgroup subgroup2_13 Sinter
 *  Spatial noise reduction configuration
 *  @{
 */

/*!
 *  @brief          Set Sinter configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_SinterCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetSinter(UINT8 uUnit, UINT64 uContext, const drvISP_SinterCfg_t *pConfig);

/*!
 *  @brief          Get Sinter configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_SinterCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetSinter(UINT8 uUnit, UINT64 uContext, drvISP_SinterCfg_t *pConfig);

/*!
 *  @brief          Set Sinter Noise Profile configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_PipeNpCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetSinter_NP(UINT8 uUnit, UINT64 uContext, const drvISP_PipeNpCfg_t *pConfig);

/*!
 *  @brief          Get Sinter Noise Profile configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_PipeNpCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetSinter_NP(UINT8 uUnit, UINT64 uContext, drvISP_PipeNpCfg_t *pConfig);

/*!
 *  @brief          Set Sinter Radial Shading correction configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_SinterRsCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetSinter_RS(UINT8 uUnit, UINT64 uContext, const drvISP_SinterRsCfg_t *pConfig);

/*!
 *  @brief          Get Sinter Radial Shading correction configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_SinterRsCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetSinter_RS(UINT8 uUnit, UINT64 uContext, drvISP_SinterRsCfg_t *pConfig);

/*! @} */ // end of subgroup2_13

/*! @defgroup subgroup2_14 Chromatic Aberration
 *  Chromatic aberration correction configuration
 *  @{
 */

/*!
 *  @brief          Set the Chromatic Aberration configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_CaCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetChrAb(UINT8 uUnit, UINT64 uContext, const drvISP_CaCfg_t *pConfig);

/*!
 *  @brief          Get the Chromatic Aberration configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_CaCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetChrAb(UINT8 uUnit, UINT64 uContext, drvISP_CaCfg_t *pConfig);

/*!
 *  @brief          Set the Chromatic Aberration Filter LUT
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig LUT table configuration (see #drvISP_CaFiltLutCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetChrAb_Filter_LUT(UINT8 uUnit, UINT64 uContext, const drvISP_CaFiltLutCfg_t *pConfig);

/*!
 *  @brief          Get the Chromatic Aberration Filter LUT
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig LUT table configuration (see #drvISP_CaFiltLutCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetChrAb_Filter_LUT(UINT8 uUnit, UINT64 uContext, drvISP_CaFiltLutCfg_t *pConfig);

/*!
 *  @brief          Set the Chromatic Aberration correction LUT
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig LUT table configuration (see #drvISP_CaCorrLutCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetChrAb_Corr_LUT(UINT8 uUnit, UINT64 uContext, const drvISP_CaCorrLutCfg_t *pConfig);

/*!
 *  @brief          Get the Chromatic Aberration correction LUT
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig LUT table configuration (see #drvISP_CaCorrLutCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetChrAb_Corr_LUT(UINT8 uUnit, UINT64 uContext, drvISP_CaCorrLutCfg_t *pConfig);

/*! @} */ // end of subgroup2_14

/*! @defgroup subgroup2_15 Gamma BE
 *  Gamma BE (LUT based) configuration
 *  @{
 */

/*!
 *  @brief          Set the Gamma BE LUT0 configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_GammaCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetGammaBE0(UINT8 uUnit, UINT64 uContext, const drvISP_GammaCfg_t *pConfig);

/*!
 *  @brief          Get the Gamma BE LUT0 configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_GammaCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetGammaBE0(UINT8 uUnit, UINT64 uContext, drvISP_GammaCfg_t *pConfig);

/*!
 *  @brief          Set the Gamma BE LUT1 configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_GammaCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetGammaBE1(UINT8 uUnit, UINT64 uContext, const drvISP_GammaCfg_t *pConfig);

/*!
 *  @brief          Get the Gamma BE LUT1 configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_GammaCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetGammaBE1(UINT8 uUnit, UINT64 uContext, drvISP_GammaCfg_t *pConfig);

/*! @} */ // end of subgroup2_15

/*! @defgroup subgroup2_16 White Balance
 *  White balance configuration
 *  @{
 */

/*!
 *  @brief          Set the White Balance configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_WbCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetWhiteBalance(UINT8 uUnit, UINT64 uContext, const drvISP_WbCfg_t *pConfig);

/*!
 *  @brief          Get the White Balance configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_WbCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetWhiteBalance(UINT8 uUnit, UINT64 uContext, drvISP_WbCfg_t *pConfig);

/*! @} */ // end of subgroup2_16

/*! @defgroup subgroup2_17 Radial Shading
 *  Radial shading correction configuration
 *  @{
 */

/*!
 *  @brief          Set the Radial Shading configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_RadialShadingCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetRadialShading(UINT8 uUnit, UINT64 uContext, const drvISP_RadialShadingCfg_t *pConfig);

/*!
 *  @brief          Get the Radial Shading configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_RadialShadingCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetRadialShading(UINT8 uUnit, UINT64 uContext, drvISP_RadialShadingCfg_t *pConfig);

/*!
 *  @brief          Set the Radial Shading LUT
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_RadialShadingLutCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetRadialShading_LUT(UINT8 uUnit, UINT64 uContext, const drvISP_RadialShadingLutCfg_t *pConfig);

/*!
 *  @brief          Get the Radial Shading LUT
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_RadialShadingLutCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetRadialShading_LUT(UINT8 uUnit, UINT64 uContext, drvISP_RadialShadingLutCfg_t *pConfig);

/*! @} */ // end of subgroup2_17

/*! @defgroup subgroup2_18 Mesh Shading
 *  Mesh shading correction configuration
 *  @{
 */

/*!
 *  @brief          Set the Mesh Shading configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_MeshShadingCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetMeshShading(UINT8 uUnit, UINT64 uContext, const drvISP_MeshShadingCfg_t *pConfig);

/*!
 *  @brief          Get the Mesh Shading configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_MeshShadingCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetMeshShading(UINT8 uUnit, UINT64 uContext, drvISP_MeshShadingCfg_t *pConfig);

/*!
 *  @brief          Set the Mesh Shading LUT configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_MeshShadingLutCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetMeshShading_LUT(UINT8 uUnit, UINT64 uContext, const drvISP_MeshShadingLutCfg_t *pConfig);

/*!
 *  @brief          Get the Mesh Shading LUT configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_MeshShadingLutCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetMeshShading_LUT(UINT8 uUnit, UINT64 uContext, drvISP_MeshShadingLutCfg_t *pConfig);

/*! @} */ // end of subgroup2_18

/*! @defgroup subgroup2_19 Tone Mapping
 *  Tone Mapping configuration
 *  @{
 */

/*!
 *  @brief          Set the Tone Mapping Digital Gain configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_DgCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetToneMapGain(UINT8 uUnit, UINT64 uContext, const drvISP_DgCfg_t *pConfig);

/*!
 *  @brief          Get the Tone Mapping Digital Gain configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_DgCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetToneMapGain(UINT8 uUnit, UINT64 uContext, drvISP_DgCfg_t *pConfig);

/*!
 *  @brief          Set the Tone Mapping configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_ToneMapCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetToneMap(UINT8 uUnit, UINT64 uContext, const drvISP_ToneMapCfg_t *pConfig);

/*!
 *  @brief          Get the Tone Mapping configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_ToneMapCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetToneMap(UINT8 uUnit, UINT64 uContext, drvISP_ToneMapCfg_t *pConfig);

/*!
 *  @brief          Set the Tone Mapping Pre Gamma LUT Table
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_ToneMapLutCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetToneMapPreGamma_LUT(UINT8 uUnit, UINT64 uContext, const drvISP_ToneMapLutCfg_t *pConfig);

/*!
 *  @brief          Get the Tone Mapping Pre Gamma LUT Table
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_ToneMapLutCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetToneMapPreGamma_LUT(UINT8 uUnit, UINT64 uContext, drvISP_ToneMapLutCfg_t *pConfig);

/*!
 *  @brief          Set the Tone Mapping Post Gamma LUT Table
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_ToneMapLutCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetToneMapPostGamma_LUT(UINT8 uUnit, UINT64 uContext, const drvISP_ToneMapLutCfg_t *pConfig);

/*!
 *  @brief          Get the Tone Mapping Post Gamma LUT Table
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_ToneMapLutCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetToneMapPostGamma_LUT(UINT8 uUnit, UINT64 uContext, drvISP_ToneMapLutCfg_t *pConfig);

/*!
 *  @brief          Set the Global Tone Mapping 2D Asymmetry LUT Table
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_ToneMap_2DLUT_Cfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetToneMapGlobal_2DLUT(UINT8 uUnit, UINT64 uContext, const drvISP_ToneMap_2DLUT_Cfg_t *pConfig);

/*!
 *  @brief          Get the Global Tone Mapping 2D Asymmetry LUT Table
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_ToneMap_2DLUT_Cfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetToneMapGlobal_2DLUT(UINT8 uUnit, UINT64 uContext, drvISP_ToneMap_2DLUT_Cfg_t *pConfig);

/*!
 *  @brief          Set the Local Tone Mapping (Iridix) Asymmetry LUT Table
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_ToneMapLutCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetToneMapLocalAsym_LUT(UINT8 uUnit, UINT64 uContext, const drvISP_ToneMapLutCfg_t *pConfig);

/*!
 *  @brief          Get the Local Tone Mapping (Iridix) Asymmetry LUT Table
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_ToneMapLutCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetToneMapLocalAsym_LUT(UINT8 uUnit, UINT64 uContext, drvISP_ToneMapLutCfg_t *pConfig);

/*! @} */ // end of subgroup2_19

/*! @defgroup subgroup2_20 Demosaic
 *  Demosaic configuration
 *  @{
 */

/*!
 *  @brief          Set the Demosaicing configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_DemCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetDemosaic(UINT8 uUnit, UINT64 uContext, const drvISP_DemCfg_t *pConfig);

/*!
 *  @brief          Get the Demosaicing configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_DemCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetDemosaic(UINT8 uUnit, UINT64 uContext, drvISP_DemCfg_t *pConfig);

/*!
 *  @brief          Set the Demosaicing Noise Profile configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_PipeNpCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetDemosaicNP(UINT8 uUnit, UINT64 uContext, const drvISP_DemNpCfg_t *pConfig);

/*!
 *  @brief          Get the Demosaicing Noise Profile configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_PipeNpCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetDemosaicNP(UINT8 uUnit, UINT64 uContext, drvISP_DemNpCfg_t *pConfig);

/*! @} */ // end of subgroup2_20

/*! @defgroup subgroup2_21 Crop
 *  Crop configuration
 *  @{
 */

/*!
 *  @brief          Set the Cropping configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_CropCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetCrop(UINT8 uUnit, UINT64 uContext, const drvISP_CropCfg_t *pConfig);

/*!
 *  @brief          Get the Cropping configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_CropCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetCrop(UINT8 uUnit, UINT64 uContext, drvISP_CropCfg_t *pConfig);

/*! @} */ // end of subgroup2_21

/*! @defgroup subgroup2_22 Output Formatter
 *  Output formatter configuration
 *  @image html pics/output_formatter.png
 *  @{
 */

/*!
 *  @brief          Set the Output Formatter configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_OutFormCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetOutForm(UINT8 uUnit, UINT64 uContext, const drvISP_OutFormCfg_t *pConfig);

/*!
 *  @brief          Get the Output Formatter configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_OutFormCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetOutForm(UINT8 uUnit, UINT64 uContext, drvISP_OutFormCfg_t *pConfig);

/*! @} */ // end of subgroup2_22

/*! @defgroup subgroup2_23 AXI Output
 *  AXI output configuration
 *  @{
 */

/*!
 *  @brief          Set the AXI Output configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_OutCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetAxiOut(UINT8 uUnit, UINT64 uContext, const drvISP_OutCfg_t *pConfig);

/*!
 *  @brief          Get the AXI Output configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_OutCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetAxiOut(UINT8 uUnit, UINT64 uContext, drvISP_OutCfg_t *pConfig);

/*! @} */ // end of subgroup2_23

/*! @defgroup subgroup2_24 Streaming Output
 *  AXI output configuration
 *  @{
 */

/*!
 *  @brief          Set the Output configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_OutCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetOut(UINT8 uUnit, UINT64 uContext, const drvISP_OutCfg_t *pConfig);

/*!
 *  @brief          Get the Output configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_OutCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetOut(UINT8 uUnit, UINT64 uContext, drvISP_OutCfg_t *pConfig);

/*! @} */ // end of subgroup2_24

/*! @defgroup subgroup2_25 Statistics
 *  Statistics configuration
 *  @{
 */

/*! @defgroup subgroup2_25_1 Antifog
 *  Antifog statistics configuration
 *  @{
 */

/*!
 *  @brief          Get the Antifog Histogram statistics
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context number
 *  @param          pStats Statistics (see #drvISP_HistStatsData_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetAfStatsData(UINT8 uUnit, UINT64 uContext, drvISP_HistStatsData_t *pStats);

/*!
 *  @brief          Set the Antifog Histogram configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_AfStatsCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetAfStats(UINT8 uUnit, UINT64 uContext, const drvISP_AfStatsCfg_t *pConfig);

/*!
 *  @brief          Get the Antifog Histogram configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_AfStatsCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetAfStats(UINT8 uUnit, UINT64 uContext, drvISP_AfStatsCfg_t *pConfig);

/*! @} */ // end of subgroup2_25_1

/*! @defgroup subgroup2_25_2 Exposure
 *  Exposure statistics configuration
 *  @{
 */

/*!
 *  @brief          Get the Exposure statistics
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context number
 *  @param          pStats Statistics (see #drvISP_ExpStatsData_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetExpStatsData(UINT8 uUnit, UINT64 uContext, drvISP_ExpStatsData_t *pStats);

/*!
 *  @brief          Set the Exposure statistics configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_ExpStatsCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetExpStats(UINT8 uUnit, UINT64 uContext, const drvISP_ExpStatsCfg_t *pConfig);

/*!
 *  @brief          Get the Exposure statistics configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_ExpStatsCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetExpStats(UINT8 uUnit, UINT64 uContext, drvISP_ExpStatsCfg_t *pConfig);

/*! @} */ // end of subgroup2_25_2

/*! @defgroup subgroup2_25_3 White Point
 *  White point statistics configuration
 *  @{
 */

/*!
 *  @brief          Get the White Balancing statistics
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context number
 *  @param          pStats Statistics (see #drvISP_WbStatsData_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetWbStatsData(UINT8 uUnit, UINT64 uContext, drvISP_WbStatsData_t *pStats);

/*!
 *  @brief          Set the White Balancing statistics configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_WbStatsCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetWbStats(UINT8 uUnit, UINT64 uContext, const drvISP_WbStatsCfg_t *pConfig);

/*!
 *  @brief          Get the White Balancing statistics configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_WbStatsCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetWbStats(UINT8 uUnit, UINT64 uContext, drvISP_WbStatsCfg_t *pConfig);

/*! @} */ // end of subgroup2_25_3

/*! @defgroup subgroup2_25_4 Histograms
 *  Metering histograms statistics configuration
 *  @{
 */

/*!
 *  @brief          Get the Metering Histograms statistics
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context number
 *  @param          HistNum Histogram number (0..3)
 *  @param          pStats Statistics (see #drvISP_HistStatsData_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetHistStatsData(UINT8 uUnit, UINT64 uContext, UINT8 HistNum, drvISP_HistStatsData_t *pStats);

/*!
 *  @brief          Set the Metering Histograms configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          HistNum Histogram number (0..3)
 *  @param          pConfig Configuration structure (see #drvISP_HistStatsCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetHistStats(UINT8 uUnit, UINT64 uContext, UINT8 HistNum, const drvISP_HistStatsCfg_t *pConfig);

/*!
 *  @brief          Get the Metering Histograms configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          HistNum Histogram number (0..3)
 *  @param          pConfig Configuration structure (see #drvISP_HistStatsCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetHistStats(UINT8 uUnit, UINT64 uContext, UINT8 HistNum, drvISP_HistStatsCfg_t *pConfig);

/*! @} */ // end of subgroup2_25_4

/*! @defgroup subgroup2_25_5 ROI Histograms
 *  Metering ROI histograms statistics configuration
 *  @{
 */

/*!
 *  @brief          Get the ROI Histograms statistics
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context number
 *  @param          HistNum Histogram number (0..3)
 *  @param          pStats Statistics (see #drvISP_HistStatsData_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetRoiStatsData(UINT8 uUnit, UINT64 uContext, UINT8 HistNum, drvISP_HistStatsData_t *pStats);

/*!
 *  @brief          Set the ROI Histograms configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          HistNum Histogram number (0..3)
 *  @param          pConfig Configuration structure (see #drvISP_RoiStatsCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetRoiStats(UINT8 uUnit, UINT64 uContext, UINT8 HistNum, const drvISP_RoiStatsCfg_t *pConfig);

/*!
 *  @brief          Get the ROI Histograms configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          HistNum Histogram number (0..3)
 *  @param          pConfig Configuration structure (see #drvISP_RoiStatsCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetRoiStats(UINT8 uUnit, UINT64 uContext, UINT8 HistNum, drvISP_RoiStatsCfg_t *pConfig);

/*! @} */ // end of subgroup2_25_5

/*! @defgroup subgroup2_25_6 Micro ROI
 *  Micro ROI crops configuration
 *  @{
 */

/*!
 *  @brief          Get the uROI crop data
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context number
 *  @param          uRoiNum Micro ROI number (0..15)
 *  @param          pData Crop data (see #drvISP_uRoiCropData_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetMicroRoiCropData(UINT8 uUnit, UINT64 uContext, UINT8 uRoiNum, drvISP_uRoiCropData_t *pData);

/*!
 *  @brief          Set the uROI crop configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          uRoiNum Micro ROI number (0..15)
 *  @param          pConfig Configuration structure (see #drvISP_uRoiCropCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetMicroRoiCrop(UINT8 uUnit, UINT64 uContext, UINT8 uRoiNum, const drvISP_uRoiCropCfg_t *pConfig);

/*!
 *  @brief          Get the uROI crop configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          uRoiNum Micro ROI number (0..15)
 *  @param          pConfig Configuration structure (see #drvISP_uRoiCropCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetMicroRoiCrop(UINT8 uUnit, UINT64 uContext, UINT8 uRoiNum, drvISP_uRoiCropCfg_t *pConfig);

/*! @} */ // end of subgroup2_25_6

/*! @defgroup subgroup2_25_7 Consistency Plane
 *  Consistency Plane configuration
 *  @{
 */

/*!
 *  @brief          Set the Consistency Plane configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_CplaneCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetCplane(UINT8 uUnit, UINT64 uContext, const drvISP_CplaneCfg_t *pConfig);

/*!
 *  @brief          Get the Consistency Plane configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_CplaneCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetCplane(UINT8 uUnit, UINT64 uContext, drvISP_CplaneCfg_t *pConfig);

/*!
 *  @brief          Set the Consistency Plane configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pStats Statistics (see #drvISP_CplaneStatsData_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetCplaneStatsData(UINT8 uUnit, UINT64 uContext, drvISP_CplaneStatsData_t *pStats);

/*! @} */ // end of subgroup2_25_7

/*! @} */ // end of subgroup2_25

/*! @defgroup subgroup2_26 BIST
 *  BIST configuration.
 *  @{
 */

/*!
 *  @brief          Set the Build In Self Test (BIST) configuration.
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_BistCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetBist(UINT8 uUnit, UINT64 uContext, const drvISP_BistCfg_t *pConfig);

/*!
 *  @brief          Get the Build In Self Test (BIST) configuration.
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_BistCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetBist(UINT8 uUnit, UINT64 uContext, drvISP_BistCfg_t *pConfig);

/*!
 *  @brief          Set the Build In Self Test (BIST) expected CRC.
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_BistCrcCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetBistCrc(UINT8 uUnit, UINT64 uContext, const drvISP_BistCrcCfg_t *pConfig);

/*!
 *  @brief          Get the Build In Self Test (BIST) expected CRC.
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_BistCrcCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetBistCrc(UINT8 uUnit, UINT64 uContext, drvISP_BistCrcCfg_t *pConfig);

/*!
 *  @brief          Get the CRC data.
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pCrcData Data structure (see #drvISP_CrcData_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetCrcData(UINT8 uUnit, UINT64 uContext, drvISP_CrcData_t *pCrcData);

/*! @} */ // end of subgroup2_26

/*! @defgroup subgroup2_27 Pipeline Frame Check
 *  Pipeline Frame Check configuration.
 *  @{
 */

/*!
 *  @brief          Set the Pipeline Frame check configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_PipeFrameChkCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_SetPipeFrameCheck(UINT8 uUnit, UINT64 uContext, const drvISP_PipeFrameChkCfg_t *pConfig);

/*!
 *  @brief          Get the Pipeline Frame check configuration
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uContext Context to use (see #UINT64)
 *  @param          pConfig Configuration structure (see #drvISP_PipeFrameChkCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvISP_GetPipeFrameCheck(UINT8 uUnit, UINT64 uContext, drvISP_PipeFrameChkCfg_t *pConfig);
 
/*! @} */ // end of subgroup1_6

/*! @} */ // end of group2

#ifdef __cplusplus
}
#endif

#endif      /* CISP_H */

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/multimedia/branches/ADAS2.0/lib/3rdparty/renesas/isp/public/renesas/cisp.h $ $Rev: 880257 $")
#endif
