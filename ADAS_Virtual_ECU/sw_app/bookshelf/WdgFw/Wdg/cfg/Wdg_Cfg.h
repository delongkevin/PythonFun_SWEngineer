/**
 * @file Wdg_cfg.h
 * @brief configurations for MCAL WDG driver
 *
 * @details This file configures MCAL WDG driver
 *
 * --------------------------------------------------------------------------
 * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *
 *   This is an unpublished work of authorship, which contains
 *   trade secrets, created in 2022.  Magna Electronics owns all
 *   rights to this work and intends to maintain it in confidence
 *   to preserve its trade secret status.  Magna Electronics
 *   reserves the right, under the copyright laws of the United
 *   States or those of any other country that may have jurisdiction,
 *   to protect this work as an unpublished work, in the event of
 *   an inadvertent or deliberate unauthorized publication.
 *   Magna Electronics also reserves its rights under all copyright
 *   laws to protect this work as a published work, when appropriate.
 *   Those having access to this work may not copy it, use it,
 *   modify it, or disclose the information contained in it without
 *   the written authorization of Magna Electronics.
 *
 * --------------------------------------------------------------------------
 * @author Pramod Kumar (Pramod.kumar1@magna.com)
 */
#ifndef WDG_CFG_H_
#define WDG_CFG_H_
/* ===========================================================================
*
*   Include Files
*
* ========================================================================= */
#if defined(BUILD_MCU1_0)
    void Pmic_F_RefreshWdg_v(void);
#endif


/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
/***************   Feature Enable / Disable configuration  ***************/
#define D_WDG_FEATURE_REPORT_TO_ERRMGR (1U)   /* Report WDG error to error manager enable / disable */

/* Wdg Config */
#define D_WDG_INIT_TIMEOUT  (450U)   /* 450*10 = 4.5 sec */

#if defined(BUILD_MCU1_0)
/* Call PMIC APIs to refresh or reset HW WDG */
#define D_WDG_RESET(x)       ((x) = (uint8)TRUE); Wdg_f_ReportWdgErr_v()
#define D_WDG_REFRESH()      (Pmic_F_RefreshWdg_v())

#else
/* Call local interface to pass current WDG status to MCU1_0 */
#define D_WDG_RESET(x)       (Wdg_f_WdgReset_v())
#define D_WDG_REFRESH()      (Wdg_f_WdgRefresh_v())
#endif

/* Signal Manager interface */
#if defined(BUILD_MPU1_0)
#define D_WDG_INFORM_CP_STS_TO_SIGMGR(data, msgid, size)       SigMgr_WdgCheckpointStatus_Mpu1_0_Core_Put(data)
#elif defined(BUILD_MCU2_0)
#define D_WDG_INFORM_CP_STS_TO_SIGMGR(data, msgid, size)       SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_Put(data) 
#elif defined(BUILD_MCU2_1)
#define D_WDG_INFORM_CP_STS_TO_SIGMGR(data, msgid, size)       SigMgr_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t_Put(data) //BhagwanW : Need to Fix
#elif defined(BUILD_MCU3_0)
#define D_WDG_INFORM_CP_STS_TO_SIGMGR(data, msgid, size)       SigMgr_WdgCheckpointStatus_Mcu3_0_Core_Put(data)
#elif defined(BUILD_MCU3_1)
#define D_WDG_INFORM_CP_STS_TO_SIGMGR(data, msgid, size)       Rte_Call_R_IPC_WDG_CS_IPC_Write_v((dtRef_VOID)data, msgid, size)
#endif

/* WDGM interface */
/* For AUTOSAR Core/Code -> Return SEID
 * For SafeRTOS checkpoint code -> Return CPID
 */
#if defined(BUILD_MPU1_0) || defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
#define D_WDG_GET_FIRST_EXPIRED_SEID(x)       WdgM_GetFirstExpiredSEID(x)
#else
#define D_WDG_GET_FIRST_EXPIRED_SEID(x)       WdgM_F_GetFirstExpiredCpid(x)
#endif

/**************  Report error to Error manager configuration  ************/
/* Error info -> 2 byte First CP vioaltion + rest 13 byte 0 */
 
#if defined(BUILD_MCU1_0)
#define D_WDG_REPORT_CP_VIOLATION_ERR_MCU1_0  (ErrorMgr_Error_SysIntFlt_WDG_Health_Monitoring_Failure_1_0_MCU_Domain)
#define D_WDG_REPORT_CP_VIOLATION_ERR_MCU2_0  (ErrorMgr_Error_SysIntFlt_WDG_Health_Monitoring_Failure_2_0_Main_Domain)
#define D_WDG_REPORT_CP_VIOLATION_ERR_MCU2_1  (ErrorMgr_Error_SysIntFlt_WDG_Health_Monitoring_Failure_2_1_Main_Domain)
//#define D_WDG_REPORT_CP_VIOLATION_ERR_MCU3_0  (ErrorMgr_Error_Internal_WDG_Health_Monitoring_Failure_3_0_Main_Domain)
//#define D_WDG_REPORT_CP_VIOLATION_ERR_MCU3_1  (ErrorMgr_Error_Internal_WDG_Health_Monitoring_Failure_3_1_Main_Domain)
#define D_WDG_REPORT_CP_VIOLATION_ERR_MPU1_0  (ErrorMgr_Error_SysIntFlt_WDG_Health_Monitoring_Failure_1_0_MPU_Domain)
#endif



/* Note: error manager provided 15 byte for error info */
#define D_WDG_ERR_REPORT_BUFF_SIZE     (15U)

/* Error info size of CP violation error */
#define D_WDG_CP_VIOLATION_ERR_SIZE     (2U)

/* Error manager interface */
#if defined(BUILD_MCU1_0)
#define WDG_ERR_INVALID                      (ErrorMgr_Invalid)
#define WDG_ERR_INACTIVE                     (ErrorMgr_ErrorInactive)
#define WDG_ERR_ACTIVE                       (ErrorMgr_ErrorActive)
#define D_WDG_REPORT_ERR(err, sts, info)     (Os_Call_RE_ReportErrorStatus1_0_B((ErrorMgr_enErrorNo)(err), (ErrorMgr_enErrorStatus)(sts), (ErrorMgr_stAddData *)(info)))
#endif

/* ===========================================================================
*
*   Global variables
*
* ========================================================================= */


/* ===========================================================================
*
*   Private variables
*
* ========================================================================= */


/* ===========================================================================
*
*   Private functions prototype
*
* ========================================================================= */


/* ===========================================================================
*
*   Private functions
*
* ========================================================================= */


/* ===========================================================================
*
*   Global functions
*
* ========================================================================= */

#endif  /* #ifndef WDG_CFG_H_ */
/*===============================End Of File========================================================*/
