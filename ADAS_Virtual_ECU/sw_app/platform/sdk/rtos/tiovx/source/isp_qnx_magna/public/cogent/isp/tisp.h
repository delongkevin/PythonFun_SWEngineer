/*!
 *  @file       tisp.h
 *  @brief      ISP TOP driver for V3x (API)
 *  @date       2018/Oct/01 latest update
 *  @author     A. Lanari
 *  @version    2.0.0
 *  @par        history
 *  @note
 */

/*! \mainpage ISP TOP
 * <table>
 * <tr>
 * <td>
 * @image html pics/V3M.png
 * </td><td>
 * @image html pics/V3H.png
 * </td>
 * </tr><tr>
 * <th>V3M</th><th>V3H</th>
 * </tr>
 * </table>
 */

#ifndef TISP_H
#define TISP_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************
* Macro definitions                                        *
***********************************************************/
#ifndef ISP_CFG_TARGET_DEVICE
#error "TISP: Unknown target device configuration!!!"
#endif

#if (ISP_CFG_TARGET_DEVICE == ISP_CFG_DEVICE_RCAR_V3M)
#define TISP_FAULT_STS_NUM                  (1u)    /*!< Number of TOP fault registers */
#define TISP_MDAT_LINE_SIZE                 (1280u) /*!< Top Metadata line size in dwords */
#define TISP_MDAT_MAX_NUM_LINES             (4u)    /*!< Top Metadata max number of lines */
#elif (ISP_CFG_TARGET_DEVICE == ISP_CFG_DEVICE_RCAR_V3H)
#define TISP_FAULT_STS_NUM                  (2u)    /*!< Number of TOP fault registers */
#define TISP_WUP_EOF_NUM_ADDR               (32u)   /*!< Number of ISP TOP WUP EOF addresses */
#define TISP_NUM_DT_CODES                   (64u)   /*!< Number of DT codes */
#define TISP_NUM_DT_FILTERS                 (8u)    /*!< Number of DT codes filters */
#define TISP_TOTAL_NUM_OF_VCH               (4U)    /*!< Number of virtual channels */
#endif

#define TISP_TRACE_CH_NUM                   (2U)    /*!< Number of TOP trace channels */

/* All the functions of the API must use the following error codes to signal an error condition */
#define TISP_RET_E_OK                       (0u)   /*!< OK:    Execution successful */
#define TISP_RET_ERR_WRONG_ARGUMENTS        (101u) /*!< Error: Parameter error */
#define TISP_RET_ERR_WRONG_READDATA         (102u) /*!< Error: Wrong in data that read out */
#define TISP_RET_ERR_REGBASEADDR            (103u) /*!< Error: Register base address corrupted to invalid base address */
#define TISP_RET_ERR_STATE_WRONGSEQUENCE    (104u) /*!< Error: Sequence error in TISP state machine flow */
#define TISP_RET_ERR_OPERATION_WRONGSTATE   (105u) /*!< Error: Operation API called in wrong state.
                                                               Operation APIs are APIs except state machine APIs */
#define TISP_RET_ERR_UNSUPPORTED_VERSION    (106u) /*!< Error: Unsupported TISP version */

/***********************************************************
* Typedef definitions                                      *
***********************************************************/
/*! ISP Wrapper Unit Selector */
typedef enum {
    ISP_TOP_INPUT_CSI = 0u, /*!< MIPI input only */
    ISP_TOP_INPUT_CSI_DVI0, /*!< MIPI + VIN0 (Input 2) */
    ISP_TOP_INPUT_CSI_DVI1, /*!< MIPI + VIN1 (Input 3) */
    ISP_TOP_INPUT_CSI_DVI01 /*!< MIPI + VIN0 (Input 2) + VIN1 (Input 3) */
} drvTISP_Input_t;

/*! ISP Wrapper Trace configuration */
typedef struct {
    UINT8 Trace[TISP_TRACE_CH_NUM]; /*!< Input index to trace */
} drvTISP_InputTraceCfg_t;

#if (ISP_CFG_TARGET_DEVICE == ISP_CFG_DEVICE_RCAR_V3H)
/*! ISP Top Virtual Unit Configuration */
typedef struct {
    UINT8 VC_Filter;                             /*!< Virtual channel (VC) number to pass is specified at VC_Filter<br>
                                                       Only either B’0000 or one hot value is available. Other value are for bidden.<br>
                                                       B’0001： Pass VC0<br>
                                                       B’0010： Pass VC1<br>
                                                       B’0100： Pass VC2<br>
                                                       B’1000： Pass VC3<br>
                                                       Other : Forbidden<br>
                                                       [default]<br>
                                                       CH0 = B’0001, CH1 = B’0010, CH2 = B’0100, CH3 = B’1000<br>
                                                       CH4 = B’0001, CH5 = B’0001, CH6 = B’0010, CH7 = B’0100<br>
                                                       CH8 = B’1000 */
    UINT8 DT_Filter[TISP_NUM_DT_FILTERS];        /*!< Number of DT_CODE at DT Filter (6 bit, LSB aligned)<br>
                                                      When DT_CODE match setting value by DT Filter, those data be though */
    UINT8 LC_Filter_Enable[TISP_NUM_DT_FILTERS]; /*!< Enable bit for though stream in LC Filter */
    UINT8 LC_Filter_ID;                          /*!< Number of ID thought at LineCountFilter<br>
                                                      When ID added by LineCountID match ID added by LC_Filter_ID, those data be though */
    UINT8 LC_Modulo[TISP_TOTAL_NUM_OF_VCH];      /*!< Divisor minus 1 for modulo calculation on the line number<br>
                                                      of the input frame (VCn) for calculating the line count ID */
    UINT8 LC_Hold[TISP_NUM_DT_FILTERS];          /*!< Enable bit for increment counter at Line Count ID (0=enable, 1=disable) */
    UINT16 H_Clip_Post[TISP_NUM_DT_FILTERS];     /*!< Specifies the number of removing pixels at the right edge of one line (per DT code) */
    UINT16 H_Clip_Pre[TISP_NUM_DT_FILTERS];      /*!< Specifies the number of removing pixels at the right edge of one line (per DT code) */
    UINT16 V_Clip_Post[TISP_TOTAL_NUM_OF_VCH];   /*!< Specifies the number of removed lines at the top edge of one frame (per virtual channel) */
    UINT16 V_Clip_Pre[TISP_TOTAL_NUM_OF_VCH];    /*!< Specifies the number of removed lines at the bottom edge of one frame (per virtual channel) */
} drvTISP_ChSelCfg_t;

/*! ISP TOP Synchronization with IMR */
typedef struct {
    UINT8 InputSelect;                             /*!< Select input channel<br>
                                                        0：ISP output channel plane 0 [default]<br>
                                                        1：ISP output channel plane 1<br>
                                                        2：ISP output channel plane 2<br>
                                                        Others : Forbidden */
    UINT8 EnableChannels;                          /*!< Enable channel control for each IMR channel. Each bit corresponds to IMR channel<br>
                                                        B’1：enable<br>
                                                        B’0：disable [default] */
    UINT16 StartHcount;                            /*!< Starter if horizontal count matched */
    UINT16 Interval;                               /*!< Interval for next signal<br>
                                                        Write the interval number – 1 */
    UINT16 RepeatNumber;                           /*!< Repeat number for total number
                                                        Write the total number – 1 */
    UINT8 EofMaxCount;                             /*!< Max count per frame<br>
                                                        0：Flash and EOF disable [default]
                                                        4-31：Setting prohibited */
    UINT8 EofAddressSelect;                        /*!< Select Address Channel<br>
                                                        0：AXI0 [default]
                                                        1：AXI1*/
    UINT32 EofMatchAddress[TISP_WUP_EOF_NUM_ADDR]; /*!< EOF match address */
    UINT8 EofMatchId[TISP_WUP_EOF_NUM_ADDR];       /*!< EOF match ID<br>
                                                        3：No flash request is generated  */
} drvTISP_ImrSyncCfg_t;

/*! Output Format */
typedef enum {
    TISP_PIXFMT_2BPP = 0u, /*!< 2 Bytes (16bit) per pixel */
    TISP_PIXFMT_4BPP,      /*!< 4 Bytes (32bit) per pixel */
    TISP_PIXFMT_4BPP_SW    /*!< 4 Bytes (32bit) per pixel (order changed) */
} drvTISP_PixFmt_t;

/*! ISP TOP Tee function */
typedef struct {
    UINT8 Enable;            /*!< Enabling control of Meta data transfer to VIN (1=enabled, 0= disabled) */
    drvTISP_PixFmt_t Format; /*!< Pixel format select to output to VIN (see #drvTISP_PixFmt_t) */
} drvTISP_TeeCfg_t;

/*! ISP Top CSI Data Types (V3H only) */
typedef enum {
    ISP_TOP_DT_RAW8 = 0u,
    ISP_TOP_DT_RAW10,
    ISP_TOP_DT_RAW12,
    ISP_TOP_DT_RAW14,
    ISP_TOP_DT_RAW16,
    ISP_TOP_DT_RAW20,
    ISP_TOP_DT_RAW24,
    ISP_TOP_DT_EMB8
} drvTISP_DataType_t;

/*! ISP Top DT Processing Mode Table */
typedef struct {
    drvTISP_DataType_t DtProcMode[TISP_NUM_DT_CODES]; /*!< Custom data type processing per DT code (see #drvTISP_DataType_t)  */
} drvTISP_DtPmodeCfg_t;

/*! Event register */
typedef union {
    struct {
        UINT32 FIFO_FULL_DVP0_INPUT:1; /*!< Interrupt enable of FIFO_FULL_DVP0_INPUT */
        UINT32 FIFO_FULL_DVP1_INPUT:1; /*!< Interrupt enable of FIFO_FULL_DVP1_INPUT */
        UINT32 FIFO_FULL_CSI0_INPUT:1; /*!< Interrupt enable of FIFO_FULL_CSI_INPUT */
        UINT32 bit3_7:5;
        UINT32 FIFO_FULL_OUTPUT0:1;    /*!< Interrupt enable of FIFO_FULL_OUTPUT0 */
        UINT32 FIFO_FULL_OUTPUT1:1;    /*!< Interrupt enable of FIFO_FULL_OUTPUT1 */
        UINT32 FIFO_FULL_OUTPUT2:1;    /*!< Interrupt enable of FIFO_FULL_OUTPUT2 */
        UINT32 bit11_15:5;
        UINT32 WUP_ERROR0:1;           /*!< Interrupt enable of WUP_ERROR0 */
        UINT32 WUP_ERROR1:1;           /*!< Interrupt enable of WUP_ERROR1 */
        UINT32 WUP_ERROR2:1;           /*!< Interrupt enable of WUP_ERROR2 */
        UINT32 WUP_EOF:1;              /*!< Interrupt enable of WUP_EOF */
        UINT32 bit20_31:12;
    } V3H; /*!< V3H specific events */
    UINT32 INT; /*!< Register 32-bit value */
} drvTISP_Event_t;
#endif

#if (ISP_CFG_TARGET_DEVICE == ISP_CFG_DEVICE_RCAR_V3M)
/*! ISP Top Data Force RAW (V3M only) */
typedef enum {
    ISP_TOP_FRAW_DISABLE = 0u,
    ISP_TOP_FRAW_8,
    ISP_TOP_FRAW_10,
    ISP_TOP_FRAW_12,
    ISP_TOP_FRAW_14,
    ISP_TOP_FRAW_16,
    ISP_TOP_FRAW_20
} drvTISP_ForceRaw_t;

/*! ISP Top Pixel Format Configuration (V3M only) */
typedef struct {
    drvTISP_ForceRaw_t ForceRaw; /*!< Force RAW format (see #drvTISP_ForceRaw_t) */
} drvTISP_PixelFmtCfg_t;

/*! ISP Top Metadata Configuration */
typedef struct {
    UINT8 CapMode;      /*!< 0: Continuous mode<br>
                             1: Only one frame */
    UINT8 BottomOnly;   /*!< 0: Capture meta data at top and bottom edge<br>1: Capture meta data at only bottom edge */
    UINT8 VirtChanSel0; /*!< Target virtual channel (VC) to capture<br>
                             0： VC0<br>
                             1： VC1<br>
                             2： VC2<br>
                             3： VC3 */
    UINT8 VirtChanSel1; /*!< Target virtual channel (VC) to capture (ignored if CapMode= 1)<br>
                             0： VC0<br>
                             1： VC1<br>
                             2： VC2<br>
                             3： VC3 */
    UINT8 HsyncSel;     /*!< Selection of H-sync signal to ISP core.<br>
                             By writing 1, you can send a particular h-sync signal for meta data packet<br>
                             (dt_code= H’12) to the ISP core in addition to h-sync of raw pixel packet.<br>
                             0： H-sync of raw pixel packet<br>
                             1： Logical OR of h-sync of raw pixel packet and h-sync of meta data packet (dt_code= H’12). */
} drvTISP_MdataCfg_t;

/*! Event register */
typedef union {
    struct {
        UINT32 FIFO_FULL_DVP0_INPUT:1; /*!< Interrupt enable of FIFO_FULL_DVP0_INPUT */
        UINT32 FIFO_FULL_DVP1_INPUT:1; /*!< Interrupt enable of FIFO_FULL_DVP1_INPUT */
        UINT32 FIFO_FULL_CSI0_INPUT:1; /*!< Interrupt enable of FIFO_FULL_CSI_INPUT */
        UINT32 bit3_7:5;
        UINT32 FIFO_FULL_OUTPUT0:1;    /*!< Interrupt enable of FIFO_FULL_OUTPUT0 */
        UINT32 FIFO_FULL_OUTPUT1:1;    /*!< Interrupt enable of FIFO_FULL_OUTPUT1 */
        UINT32 FIFO_FULL_OUTPUT2:1;    /*!< Interrupt enable of FIFO_FULL_OUTPUT2 */
        UINT32 bit11_23:13;
        UINT32 CAP_FINISH_VCSEL0_BTM:1; /*!< Interrupt enable of CAP_FINISH_VC_SEL0_BTM */
        UINT32 CAP_FINISH_VCSEL0_TOP:1; /*!< Interrupt enable of CAP_FINISH_VC_SEL0_TOP */
        UINT32 CAP_FINISH_VCSEL1_BTM:1; /*!< Interrupt enable of CAP_FINISH_VC_SEL1_BTM */
        UINT32 CAP_FINISH_VCSEL1_TOP:1; /*!< Interrupt enable of CAP_FINISH_VC_SEL1_TOP */
        UINT32 bit28_31:4;
    } V3M; /*!< V3M specific events */
    UINT32 INT; /*!< Register 32-bit value */
} drvTISP_Event_t;
#endif

/*! Fault status */
typedef struct {
    UINT32 TopFault[TISP_FAULT_STS_NUM]; /*!< TOP Fault status */
} drvTISP_Fault_t;

/*! Metadata Interrupts configuration */
typedef struct {
    UINT8  Enable; /*!< Enable */
    drvTISP_Event_t  Event;  /*!< Event from the ISP TOP */
} drvTISP_EventIntCfg_t;

/*!
 * @brief Metadata capture callback function
 * @details Called upon a metadata capture occurs
 * @param Status Metadata capture status (TBD)
 * @return None
 */
typedef void (*drvTISP_EventCb_t)(drvTISP_Event_t Status);

/*!
 * @brief TOP Lock function
 * @details Controls a mutex (system dependent) for a thread safe usage
 * @param          uUnit The ISP number
 * @param Lock 1 = Lock<br>0 = Unlock
 * @return None
 */
typedef UINT16 (*drvTISP_LockCb_t)(UINT8 uUnit, UINT8 Lock);

/*!
 * @brief   Read register callback
 * @details Read a 32bit register
 * @param   Addr Register address
 * @return  Register value
 */
typedef UINT32 (*drvTISP_ReadReg32Cb_t)(UINT64 Addr);

/*!
 * @brief   Write register callback
 * @details Write a 32bit register
 * @param   Addr Register address
 * @param   Data Register data
 * @return None
 */
typedef void (*drvTISP_WriteReg32Cb_t)(UINT64 Addr, UINT32 Data);

/*!
 * @brief   Interrupt callback prototype
 * @details The prototype of the function that will be called upon interrupt notification
 * @param   SpiID Interrupt number
 * @return None
 */
typedef void (*drvTISP_IntCbFunc_t)(UINT16 SpiID);

/*!
 * @brief   Register interrupt callback
 * @details Register the interrupt callback
 * @param   CallbackFunc Callback function to be registered
 * @return  Error code (UINT16)
 */
typedef UINT16 (*drvTISP_IntRegisterIntCb_t)(drvTISP_IntCbFunc_t CallbackFunc);

/*!
 * @brief   Unregister interrupt callback
 * @details Unregister the interrupt callback
 * @return  Error code (UINT16)
 */
typedef UINT16 (*drvTISP_IntUnregisterIntCb_t)(void);

/*! Interrupt configuration */
typedef struct {
    UINT16                       SpiID;           /*!< Interrupt number */
    drvTISP_IntRegisterIntCb_t   RegisterIntCb;   /*!< Register interrupt callback */
    drvTISP_IntUnregisterIntCb_t UnregisterIntCb; /*!< unregister interrupt callback */
} drvTISP_IntCbCfg_t;

/*! Memory configuration */
typedef struct {
    UINT64                 RegBaseAddr;  /*!< Register base address */
    drvTISP_ReadReg32Cb_t  ReadReg32Cb;  /*!< Read 32bit register */
    drvTISP_WriteReg32Cb_t WriteReg32Cb; /*!< Write 32bit register */
} drvTISP_MemCfg_t;

/*! Initialization configuration */
typedef struct { 
    drvTISP_MemCfg_t   MemCfg;   /*!< Memory configuration */
    drvTISP_IntCbCfg_t IntCbCfg; /*!< Interrupt configuration */
    drvTISP_LockCb_t   LockCb;   /*!< Mutex callback */
} drvTISP_InitCfg_t;

/*! Hardware information */
typedef struct {
    UINT8 NumUnits;    /*!< Number of ISP units */
    UINT32 HwVersion;  /*!< Hardware version */
} drvTISP_Info;

/***********************************************************
* Exported global functions (to be accessed by other files)*
***********************************************************/
/*! @defgroup group1 Common
 *  This group of settings is about the common functions
 *  @{
 */

/*!
 *  @brief          Initialize the ISP TOP
 *  @details
 *  @param          uUnit The ISP number
 *  @param          pConfig Abstraction layer configuration
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_Init(UINT8 uUnit, drvTISP_InitCfg_t *pConfig);

/*!
 *  @brief          Deinitialize the ISP TOP
 *  @details
 *  @param          uUnit The ISP number
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_DeInit(UINT8 uUnit);

/*!
 *  @brief          Open the ISP TOP
 *  @details
 *  @param          uUnit The ISP number
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_Open(UINT8 uUnit);

/*!
 *  @brief          Close the ISP TOP
 *  @details
 *  @param          uUnit The ISP number
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_Close(UINT8 uUnit);

/*!
 *  @brief          Start the ISP
 *  @details
 *  @param          uUnit The ISP number
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_Start(UINT8 uUnit);

/*!
 *  @brief          Stop the ISP
 *  @details
 *  @param          uUnit The ISP number
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_Stop(UINT8 uUnit);

/*!
 *  @brief          Get the ISP TOP info
 *  @details
 *  @param          uUnit The ISP number
 *  @param          pInfo ISP information (see drvTISP_Info)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_GetInfo(UINT8 uUnit, drvTISP_Info *pInfo);

/*!
 *  @brief      TOP ISP Set Event notification callback
 *  @details    Enable/disable the event notification and set the callback.
 *  @param      uUnit The ISP number
 *  @param      Callback Callback function (see #drvTISP_EventCb_t)
 *  @param      pConfig Configuration structure (see #drvTISP_EventIntCfg_t)
 *  @return     UINT16 0 on success or error code on failure
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_SetEventCb(UINT8 uUnit, drvTISP_EventCb_t Callback, const drvTISP_EventIntCfg_t *pConfig);

/*!
 *  @brief      ISP Set Fault notification configuration
 *  @details    Set which faults are notified to MFIS
 *  @param      uUnit The ISP number
 *  @param      pConfig Configuration structure (see #drvTISP_Fault_t)
 *  @return     UINT16 0 on success or error code on failure
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_SetFaultInt(UINT8 uUnit, const drvTISP_Fault_t *pConfig);

/*!
 *  @brief      ISP Get Fault notification configuration
 *  @details    Get which faults are notified to MFIS
 *  @param      uUnit The ISP number
 *  @param      pConfig Configuration structure (see #drvTISP_Fault_t)
 *  @return     UINT16 0 on success or error code on failure
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_GetFaultInt(UINT8 uUnit, drvTISP_Fault_t *pConfig);

/*!
 *  @brief      ISP Get fault status
 *  @details    Get the fault status registers and clear the fault interrupt.
 *  @param      uUnit The ISP number
 *  @param      pStatus Fault status structure (see #drvTISP_Fault_t)
 *  @return     UINT16 0 on success or error code on failure
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_GetFaultIntStatus(UINT8 uUnit, drvTISP_Fault_t *pStatus);

/*!
 *  @brief          Set the TOP CSI/DVP Selector
 *  @details
 *  @param          uUnit The ISP number
 *  @param          pInputMode Configuration value (see #drvTISP_Input_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_SetInputMode(UINT8 uUnit, const drvTISP_Input_t *pInputMode);

/*!
 *  @brief          Get the TOP CSI/DVP Selector
 *  @details
 *  @param          uUnit The ISP number
 *  @param          pInputMode Configuration value (see #drvTISP_Input_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_GetInputMode(UINT8 uUnit, drvTISP_Input_t *pInputMode);

/*!
 *  @brief          Set the TOP Input trace
 *  @details
 *  @param          uUnit The ISP number
 *  @param          pConfig Configuration structure (see #drvTISP_InputTraceCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_SetInputTrace(UINT8 uUnit, const drvTISP_InputTraceCfg_t *pConfig);

/*!
 *  @brief          Get the TOP Input trace
 *  @details
 *  @param          uUnit The ISP number
 *  @param          pConfig Configuration structure (see #drvTISP_InputTraceCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_GetInputTrace(UINT8 uUnit, drvTISP_InputTraceCfg_t *pConfig);

/*! @} */ /* end of group1 */

/***********************************************************
* Exported global functions (RCAR V3M device)              *
***********************************************************/
#if (ISP_CFG_TARGET_DEVICE == ISP_CFG_DEVICE_RCAR_V3M)
/*! @defgroup group2 V3M
 *  This group of settings is about the V3M functions
 *  @{
 */

/*!
 *  @brief          Set the TOP RAW format (overrides automatic detection)
 *  @details
 *  @param          uUnit The ISP number
 *  @param          pConfig Configuration structure (see #drvTISP_PixelFmtCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_SetPixelFormat(UINT8 uUnit, const drvTISP_PixelFmtCfg_t *pConfig);

/*!
 *  @brief          Get the TOP RAW format (overrides automatic detection)
 *  @details
 *  @param          uUnit The ISP number
 *  @param          pConfig Configuration structure (see #drvTISP_PixelFmtCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_GetPixelFormat(UINT8 uUnit, drvTISP_PixelFmtCfg_t *pConfig);

/*!
 *  @brief          Set the metadata capture configuration in the V3M ISP wrapper
 *  @details
 *  @param          uUnit The ISP number
 *  @param          pConfig Configuration structure
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_SetMdata(UINT8 uUnit, const drvTISP_MdataCfg_t *pConfig);

/*!
 *  @brief          Get the metadata capture configuration in the V3M ISP wrapper
 *  @details
 *  @param          uUnit The ISP number
 *  @param          pConfig Configuration structure
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_GetMdata(UINT8 uUnit, drvTISP_MdataCfg_t *pConfig);

/*!
 *  @brief          Start the metadata capture in the V3M ISP wrapper
 *  @details
 *  @param          uUnit The ISP number
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_StartMdata(UINT8 uUnit);

/*!
 *  @brief          Stop the metadata capture in the V3M ISP wrapper
 *  @details
 *  @param          uUnit The ISP number
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_StopMdata(UINT8 uUnit);

/*!
 *  @brief          Read the metadata in the V3M ISP wrapper
 *  @details
 *  @param          uUnit The ISP number
 *  @param          pBuffer Storage buffer for embedded data
 *  @param          BufferSize Size of the buffer in bytes
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_GetMdataStat(UINT8 uUnit, UINT32 *pBuffer, UINT32 BufferSize);

/*! @} */ /* end of group2 */
#endif

/***********************************************************
* Exported global functions (RCAR V3H device)              *
***********************************************************/
#if (ISP_CFG_TARGET_DEVICE == ISP_CFG_DEVICE_RCAR_V3H)
/*! @defgroup group3 V3H
 *  This group of settings is about the V3H functions
 *  @{
 */

/*!
 *  @brief          Set the Top DT processing mode configuration in the ISP TOP of V3H
 *  @details
 *  @param          uUnit The ISP number
 *  @param          VirtChan The Virtual Channel
 *  @param          pConfig Configuration structure (see #drvTISP_DtPmodeCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_SetDtProcMode(UINT8 uUnit, UINT8 VirtChan, const drvTISP_DtPmodeCfg_t *pConfig);

/*!
 *  @brief          Set the Top DT processing mode configuration in the ISP TOP of V3H
 *  @details
 *  @param          uUnit The ISP number
 *  @param          VirtChan The Virtual Channel
 *  @param          pConfig Configuration structure (see #drvTISP_DtPmodeCfg_t)
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_GetDtProcMode(UINT8 uUnit, UINT8 VirtChan, drvTISP_DtPmodeCfg_t *pConfig);

/*!
 *  @brief          Set the Top Channel Selector configuration in the ISP TOP of V3H
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uChannel The Virtual Channel
 *  @param          pConfig Configuration structure
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_SetChSelector(UINT8 uUnit, UINT8 uChannel, const drvTISP_ChSelCfg_t *pConfig);

/*!
 *  @brief          Get the Top Channel Selector configuration in the ISP TOP of V3H
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uChannel The Virtual Channel
 *  @param          pConfig Configuration structure
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_GetChSelector(UINT8 uUnit, UINT8 uChannel, drvTISP_ChSelCfg_t *pConfig);

/*!
 *  @brief          Set the Top Tee configuration in the ISP TOP of V3H
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uChannel The Virtual Channel
 *  @param          pConfig Configuration structure
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_SetTee(UINT8 uUnit, UINT8 uChannel, const drvTISP_TeeCfg_t *pConfig);

/*!
 *  @brief          Get the Top Tee configuration in the ISP TOP of V3H
 *  @details
 *  @param          uUnit The ISP number
 *  @param          uChannel The Virtual Channel
 *  @param          pConfig Configuration structure
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_GetTee(UINT8 uUnit, UINT8 uChannel, drvTISP_TeeCfg_t *pConfig);

/*!
 *  @brief          Set the TOP ISP Synchronization with IMR (V3H only)
 *  @details
 *  @param          uUnit The ISP number
 *  @param          pConfig Configuration structure
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_SetImrSync(UINT8 uUnit, const drvTISP_ImrSyncCfg_t *pConfig);

/*!
 *  @brief          Get the TOP ISP Synchronization with IMR (V3H only)
 *  @details
 *  @param          uUnit The ISP number
 *  @param          pConfig Configuration structure
 *  @return         Error code (UINT16)
 *  @par    Refer   (none)
 *  @par    Modify  (none)
 */
extern UINT16 drvTISP_GetImrSync(UINT8 uUnit, drvTISP_ImrSyncCfg_t *pConfig);

/*! @} */ /* end of group3 */
#endif

#ifdef __cplusplus
}
#endif
#endif      /* TISP_H */


#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/multimedia/branches/ADAS2.0/lib/3rdparty/renesas/isp/public/renesas/tisp.h $ $Rev: 873044 $")
#endif
