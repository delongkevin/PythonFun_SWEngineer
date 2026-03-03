/**
 * @file Wdg.c
 * @brief MCAL watch dog driver to service HW watchdog through PMIC
 *
 * @details This file provides interface to service HW watchdog through PMIC
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

 /* ===========================================================================
*
*   Include Files
*
* ========================================================================= */

#include "WdgM.h"

#include "Wdg.h"
#include "Wdg_Cfg.h"
#if !defined(BUILD_MCU1_0) && !defined(BUILD_MCU3_1)
#include "WdgGlobal.h"
#include "SignalDef.h"
#endif
#if defined(BUILD_MCU3_1)
#include "Rte_SWC_WdgFw.h"
#include "ipc_lookup_table.h"
#endif
#if defined(BUILD_MCU1_0)
#include <string.h>
#include "WdgSlave.h"
#include "Os_Lcfg.h"
#include "Rte_SWC_VCANRx_Type.h"  
#include "app_log_Boot.h"
//extern void UART_printf(const char *pcString, ...);
#endif

extern uint8 DebugFlag;
/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
#if defined(BUILD_MCU1_0)
#define WDG_CORE_0_SEID_0           (0u)
#define WDG_CORE_0_SEID_4           (4u)
#define WDG_CORE_0_SEID_5           (5u)
#define WDG_CORE_0_SEID_6           (6u)
#define WDG_SHIFT_HIGHER_BYTE       (0xFF00u)
#define WDG_SHIFT_LOWER_BYTE        (0x00FFu)
#define INCREMENT_BY_ONE            (1u)
#endif

#define WDG_TIMEOUT_ZERO            (0u)
#define DECREMENT_BY_ONE            (1u)

/* ===========================================================================

*   Global variables
*
* ========================================================================= */

#if defined(BUILD_MCU1_0)
/* Function pointer declaration error reporting interface for other core */
typedef Std_ReturnType (* WDG_F_reportErr_u32) (ErrorMgr_enErrorNo err, ErrorMgr_enErrorStatus errStatus, P2CONST(ErrorMgr_stAddData, AUTOMATIC, RTE_VAR_NOINIT) addData);

#endif


/* ===========================================================================
*
*   Private variables
*
* ========================================================================= */


/* ===========================================================================
*
* Typedefs
*
* ========================================================================= */

/* ===========================================================================
*
* Private variables
*
* ========================================================================= */
static WdgConfig_t v_wdgCfg_s;

#if !defined(BUILD_MCU1_0)
static WdgCheckpointStatus_t   V_wdgTriggerInfo_s;
#endif

/* ===========================================================================
*
* Private functions
*
* ========================================================================= */
#if !defined(BUILD_MCU1_0)
void Wdg_f_WdgRefresh_v(void);
static void Wdg_f_WdgReset_v(void);
#endif
#if defined(BUILD_MCU1_0)
static void Wdg_f_ReportWdgErr_v(void);
static void V_wdgReportErrtoCAN(uint8 u8CoreId, uint8 u8seid);
extern void f_Send_Dbg_WdgErr_CanTx(uint16 WdgError);
static void V_wdgSetWdgErrorVal(uint16 u16WdgErrorVal);
static uint16 gu16WdgErrorValue;
#endif
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
static uint8 volatile V_wdgTimeoutOccur_u8 = FALSE;  /*TODO -> PRAMOD, Remove me */

/* ========================================================================== */
/*                          Function Implementation                           */
/* ========================================================================== */
#if !defined(BUILD_MCU1_0)
/*
 * Purpose: Except for MCU1_0 -> Refresh Wdg 
 * Description: Communicate CP monitoring status to MCU1_0 through IPC
 * Precondition: None
 * Return Type : void
 */
void Wdg_f_WdgRefresh_v(void)
{
  /* DD-ID: {815C2350-5806-49fb-BEFA-0A163EA8F7A5}*/
    V_wdgTriggerInfo_s.timeoutCntr_u16 = v_wdgCfg_s.timeOutCounter_u16;

    V_wdgTriggerInfo_s.seid_s = 0;
    //V_wdgTriggerInfo_s.violation_s = WDGM_VIOLATION_NONE;

    /* Increment Live data counter */
    V_wdgTriggerInfo_s.wdgDataLiveCntr_u32++;

    D_WDG_INFORM_CP_STS_TO_SIGMGR(&V_wdgTriggerInfo_s, e_IpcMsgId_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t, sizeof(WdgCheckpointStatus_t));

}

/*
 * Purpose: Except for MCU1_0 -> Reset Wdg
 * Description: In case of any CP violation, Communicate CP violation info to MCU1_0 through IPC
 * Precondition: None
 * Return Type : void
 */
static void Wdg_f_WdgReset_v(void)
{
  /* DD-ID: {B5A2F060-76CC-475b-B62B-79AA9C9D69CC}*/
    /* Reset timeout counter to 0 */
    V_wdgTriggerInfo_s.timeoutCntr_u16 = 0;

    D_WDG_GET_FIRST_EXPIRED_SEID(&V_wdgTriggerInfo_s.seid_s);

    /* Increment Live data counter */
    V_wdgTriggerInfo_s.wdgDataLiveCntr_u32++;

    /* Communicate Wdg status to MCU1_0 through IPC */
    D_WDG_INFORM_CP_STS_TO_SIGMGR(&V_wdgTriggerInfo_s, e_IpcMsgId_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t, sizeof(WdgCheckpointStatus_t));

}
#else

/*
 * Purpose: Report Wdg error to error manager
 * Description: Report Wdg error to error manager.
 * Precondition: None
 * Return Type : void
*/
static void Wdg_f_ReportWdgErr_v(void)  /* PRQA S 5700 */ /* Not possible to implement within 2 level deep if-else */
{
   /* DD-ID:{94FF9C0C-E986-4d70-B20F-2081B4AFCFB0}*/
#if (D_WDG_FEATURE_REPORT_TO_ERRMGR == 1)
    /* Interface to report error to error manager for other core */
    static const WDG_F_reportErr_u32 V_WdgReportErr_apf[D_WDG_CORE_CNT] = 
    {
        /* Rte_Call_P_Wdg_Error_CS_QM_ReportErrorStatus1_0_QM,*/  /* MPU1_0 */
        /* Rte_Call_P_Wdg_Error_CS_QM_ReportErrorStatus1_0_QM,*/  /* MCU2_0 */
        Os_Call_RE_ReportErrorStatus1_0_B                       /* MCU2_1 */
    };
    uint8                     v_idx_u8;
    uint16                    v_seid_u16;
    uint8                     v_errInfo_au8[D_WDG_ERR_REPORT_BUFF_SIZE];
    wdgOtherCoreCpViolation_t v_cpViolOtherCore_as[D_WDG_CORE_CNT];
    static uint8              v_isErrReported_u8 = 0u;

    /*Is error already reported to error manager? */
    if((uint8)0U == v_isErrReported_u8)
    {
        /* Self Core -> Get first expired SEID */
        (void)D_WDG_GET_FIRST_EXPIRED_SEID(&v_seid_u16);
        #ifdef Enable_Printf
        appLogPrintf("Wdg violation SEID = %d\n",v_seid_u16);
        #endif

        /* Self Core -> Copy CP violation info as error info to report to error manager */
        (void)memcpy(&v_errInfo_au8[0], (uint8 *)&v_seid_u16, D_WDG_CP_VIOLATION_ERR_SIZE);

        /* Set rest bytes of error info to 0 */
        (void)memset(&v_errInfo_au8[D_WDG_CP_VIOLATION_ERR_SIZE], 0, (size_t)(D_WDG_ERR_REPORT_BUFF_SIZE - D_WDG_CP_VIOLATION_ERR_SIZE));

        /* Report error to CAN msg */
        V_wdgReportErrtoCAN((uint8)v_seid_u16, (uint8)v_seid_u16);       

        /* Self Core -> Report error to error manager */
        if(DebugFlag != (uint8)TRUE)
        {
            (void)D_WDG_REPORT_ERR(D_WDG_REPORT_CP_VIOLATION_ERR_MCU1_0, WDG_ERR_ACTIVE, NULL_PTR);
        } else{ /* Do Nothing */ }
        /* Get CP violation info of other core */
        WdgSlave_F_GetOtherCoreCpViolInfo_v(&v_cpViolOtherCore_as[0]);

        /* Process info of all other cores */
        for(v_idx_u8 = 0u; v_idx_u8 < (uint8)D_WDG_CORE_CNT; v_idx_u8++)
        {
            /* Other core -> Is any violation detected? */
            if(v_cpViolOtherCore_as[v_idx_u8].isViolation_u8 == (uint8)1U)
            {
                /* Other core -> Copy CP violation info as error info to report to error manager */
                (void)memcpy(&v_errInfo_au8[0], (uint8 *)&v_cpViolOtherCore_as[v_idx_u8].seid_u16, D_WDG_CP_VIOLATION_ERR_SIZE);
                if(DebugFlag != (uint8)TRUE)
                {
                    /* Report error to CAN msg */
                    V_wdgReportErrtoCAN((uint8)v_seid_u16, (uint8)v_cpViolOtherCore_as[v_idx_u8].seid_u16);
                    /* Other Core -> Report error to error manager */            
                    V_WdgReportErr_apf[v_idx_u8](v_cpViolOtherCore_as[v_idx_u8].errorId_u32, WDG_ERR_ACTIVE, NULL_PTR);
                    #ifdef Enable_Printf
                    appLogPrintf("\n Core Id: %d \t SEID: %d\n",v_idx_u8, v_cpViolOtherCore_as[v_idx_u8].seid_u16);
                    #endif
                } else{ /* Do Nothing */ }
            } else{ /* Do Nothing */ }
        }

        /* Set this flag to avoid error reporting repeatedly */
        v_isErrReported_u8 = 1u;
    } else{ /* Do Nothing */ }
#endif
}

/*
 * Purpose: Set Wdg Error Variable
 * Description: To Set Wdg Error of failed CoreId and SEID and will be used to report during Safe state 2
 * Precondition: None
 * Return Type : void
*/
static void V_wdgSetWdgErrorVal(uint16 u16WdgErrorVal)
{
  /* DD-ID: {D2A6CA73-C910-441d-9F2E-BA54CC898F0F}*/
    gu16WdgErrorValue = u16WdgErrorVal;
}

/*
 * Purpose: Get Wdg Error Variable
 * Description: To Get Wdg Error of failed CoreId and SEID and will be used to report during Safe state 2
 * Precondition: None
 * Return Type : uint16
*/
uint16 V_wdgGetWdgErrorVal(void)
{
  /* DD-ID: {C5E1DC10-89AB-451f-A9AC-8AA7A099FFEA}*/
    return gu16WdgErrorValue;
}

/*
 * Purpose: To report Wdg Error on CAN bus
 * Description: To report Wdg Error of failed CoreId and SEID on CAN bus
 * Precondition: None
 * Return Type : uint16
*/
static void V_wdgReportErrtoCAN(uint8 u8CoreId, uint8 u8seid)
{
  /* DD-ID: {BD5A411A-A9CF-46c2-AB4E-2DC0E4BE0D64}*/
    /* Locals */
    uint16 WdgErrorVal;
    uint8 u8CoreId_local;
    uint8 u8seid_local;
    /* Review Comment: Core Id 0, 4, 5 &  6 belongs to MCU1_0 which will be sent on CAN bus as 1 . Core Id - 1 : MCU1_0 */
    if(((uint8)WDG_CORE_0_SEID_0 == u8CoreId) || ((uint8)WDG_CORE_0_SEID_4 == u8CoreId) || 
    ((uint8)WDG_CORE_0_SEID_5 == u8CoreId) || ((uint8)WDG_CORE_0_SEID_6 == u8CoreId))
    {
        u8CoreId_local = 1U;
    }
    else
    {
        /* Increment Core Id by 1 to avoid the Core 0 fault type case */
        u8CoreId_local = u8CoreId + (uint8)INCREMENT_BY_ONE;
    }
    /* Increment SEID by 1 to avoid the SEID 0 fault type case */
    u8seid_local = u8seid + (uint8)INCREMENT_BY_ONE;

    /* Store Core Id in Byte 1 & SEID in Byte 0 */
    WdgErrorVal = (uint16)(WDG_SHIFT_HIGHER_BYTE & ((uint16)u8CoreId_local << 8U)) | (uint16)(u8seid_local & WDG_SHIFT_LOWER_BYTE);
    #ifdef Enable_Printf
    appLogPrintf("\n Core Id: %d, SEID: %d, CAN Msg Error Report: %d\n", u8CoreId_local, u8seid_local, WdgErrorVal);
    #endif

    V_wdgSetWdgErrorVal(WdgErrorVal);

    /* Report error to CAN msg */
    f_Send_Dbg_WdgErr_CanTx(WdgErrorVal);
}

#endif

/*
 * Purpose: Init MCAL WDG driver
 * Description: Init MCAL WDG driver.
 * Precondition: None
 * Return Type : void
*/
void Wdg_Init (void)
{
  /* DD-ID: {742742EE-0729-40aa-B9C9-0DA1C1419848}*/
    v_wdgCfg_s.timeOutCounter_u16 = D_WDG_INIT_TIMEOUT;

#if !defined(BUILD_MCU1_0)
    /* Init Wdg live data counter used to check freshness of data at receiver end */
    V_wdgTriggerInfo_s.wdgDataLiveCntr_u32 = 0;
#else
    /* Init WdgSlave */
    WdgSlave_F_Init_v();
#endif
}

/*
 * Purpose: Reset WDG timeout counter
 * Description: Reset WDG timeout counter.
 * Precondition: WDG must be initialized
 * Return Type : void
*/
void Wdg_SetTriggerCondition(uint16 timeout)
{
  /* DD-ID: {8C586B66-C177-4003-B663-D60A3635BD79}*/
    /* Update trigger condition */
    v_wdgCfg_s.timeOutCounter_u16 = timeout;
    if ((uint16)WDG_TIMEOUT_ZERO == timeout)
    {
        /* Cause a WD reset if timeout is set as 0 */
        D_WDG_RESET(V_wdgTimeoutOccur_u8);
    } else{ /* Do Nothing */ }
}

/*
 * Purpose: Reset WDG on timeout
 * Description: Reset WDG on timeout. This function must be called in 10ms task.
 * Precondition: WDG must be initialized
 * Return Type : void
*/
void Wdg_Trigger(void)
{  
  /* DD-ID: {B77EAEFC-ABFA-4f31-8241-035EE0DDB0BA}*/
    /* If Timeout counter hasn't expired, continue trigger routine */
    if ((uint16)WDG_TIMEOUT_ZERO == v_wdgCfg_s.timeOutCounter_u16)
    {
        /* Reset WD */
        D_WDG_RESET(V_wdgTimeoutOccur_u8);
    }
    else
    {
        /* Refresh HW WDG */
        D_WDG_REFRESH();

        /* Decrement WDG timeout counter */
        v_wdgCfg_s.timeOutCounter_u16 = v_wdgCfg_s.timeOutCounter_u16 - DECREMENT_BY_ONE;
    }
}

#if !defined(BUILD_MCU2_1) && !defined(BUILD_MCU2_0)
/*
 * Purpose: Set WDG Mode
 * Description: This is dummy function, just to return E_OK if called from WDG IF layer.
 * Precondition: None
 * Return Type : void
*/
Std_ReturnType Wdg_SetMode(WdgIf_ModeType Mode)
{
  /* DD-ID: {B2416CDC-BB8B-4e80-9FCF-75DE56511967}*/
	(void)Mode;
    return (E_OK);
}
#endif


/*===============================End Of File========================================================*/
