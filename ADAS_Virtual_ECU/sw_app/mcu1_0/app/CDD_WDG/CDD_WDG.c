/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  CDD_WDG.c
 *           Config:  D:/git/L2H4060_Software/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  CDD_WDG
 *  Generation Time:  2023-08-18 16:57:57
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <CDD_WDG>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * DeviceAddress
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * WdgM_CheckpointIdType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 *
 * Operation Prototypes:
 * =====================
 * CheckpointReached of Port Interface WdgM_AliveSupervision
 *   Indicates to the Watchdog Manager that a Checkpoint within a Supervised Entity has been reached.
 *
 *********************************************************************************************************************/

#include "Rte_CDD_WDG.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include <ti/csl/cslr.h>
#include <ti/csl/src/ip/vtm/V1/csl_vtm.h>
#include <ti/csl/arch/r5/csl_vim.h>
#include <ti/csl/csl_gpio.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>
#include <ti/osal/osal.h>
#include <ti/osal/TaskP.h>
#include <ti/osal/src/nonos/Nonos_config.h>
#include "Wdg.h"
#include "pmic.h"
#include "Enums.h"
#include "Os_Lcfg.h"
#include "pmic_wdg.h"
#include "pmic_cfg.h"
#include "fusa_application.h"
#include "app_log.h"
#include "app_log_Boot.h"

#define WDG_2_0_INIT_WAIT_TIME              (1000u)     /* (1000 * 10ms)    = 10 seconds */
#define WDG_2_0_RESET_TIMEOUT               (100u)      /* (100 * 10ms)     = 1 second */
#define D_CORE_A_MAX_WDG_FAILURE_COUNT      (50U)       /* (50 * 10ms)      = 500ms Reset Timeout Count Value */
#define D_CORE_A_INIT_WAIT_TIME             (600U)      /* (600 * 10ms)     = 6 Seconds initial wait time to detect wdg error from A-Core */

#define WDG_CORE_ID_ZERO                    (0u)
#define WDG_CORE_ID_ONE                     (1u)
#define WDG_CORE_ID_TWO                     (2u)
#define WDG_CORE_ID_THREE                   (3u)
#define WDG_ALL_CORE_CNT                    (4u)
#define INCREMENT_BY_ONE                    (1u)
#define DECREMENT_BY_ONE                    (1u)

#if defined( BUILD_MCU1_0 )
#define CDD_WDG_START_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_WDG_MemMap.h"
#endif

uint8 DebugFlag = FALSE; 

#if defined( BUILD_MCU1_0 )
#define CDD_WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_WDG_MemMap.h"
#endif

#if defined( BUILD_MCU1_0 )
#define CDD_WDG_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "CDD_WDG_MemMap.h"
#endif

#if defined( BUILD_MCU1_0 )
#define CDD_WDG_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "CDD_WDG_MemMap.h"
#endif

static void f_CoreA_KeepAlive_Monitoring(void);
static void f_Core2_0_KeepAlive_Monitoring(void);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * DeviceAddress: Integer in interval [0...255]
 * WdgM_CheckpointIdType: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Record Types:
 * =============
 * KeepAliveResponse_t: Record with elements
 *   FrameID_u32 of type uint32
 *   ResponseCode_u8 of type uint8
 * WdgCheckpointStatus_t: Record with elements
 *   timeoutCntr_u16 of type uint16
 *   seid_s of type uint16
 *   wdgDataLiveCntr_u32 of type uint32
 *
 *********************************************************************************************************************/


#define CDD_WDG_START_SEC_CODE
#include "CDD_WDG_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_WDG_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_WDG_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_WDG_CODE) RE_WDG_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_WDG_Init
 *********************************************************************************************************************/
  /* DD-ID: {F7D6EBCC-A698-4320-9FEA-C1A012357E30}*/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_WDG_Main
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_RpFailsafeDebug_Debugflag(uint8 *data)
 *   Std_ReturnType Rte_Read_RpKeepAliveResponse_KeepAliveResponse_t(KeepAliveResponse_t *data)
 *   Std_ReturnType Rte_Read_RpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t(WdgCheckpointStatus_t *data)
 *   Std_ReturnType Rte_Read_RpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t(WdgCheckpointStatus_t *data)
 *   Std_ReturnType Rte_Read_RpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t(WdgCheckpointStatus_t *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_RpMCUDeviceRegReadWrite_MCUReadDeviceReg(DeviceAddress DeviceAdd, uint16 RegAddress)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK, RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpMCUDeviceRegReadWrite_MCUReadDeviceRegData(DeviceAddress DeviceAdd, uint16 *RegAddress)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK, RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpMCUDeviceRegReadWrite_MCUWriteDeviceReg(DeviceAddress DeviceAdd, uint16 RegAddress, uint16 RegData)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK, RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_WdgM_AliveSupervision_MCU1_0_CheckpointReached(WdgM_CheckpointIdType CPID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *   Std_ReturnType Rte_Call_WdgM_AliveSupervision_MCU2_0_CheckpointReached(WdgM_CheckpointIdType CPID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *   Std_ReturnType Rte_Call_WdgM_AliveSupervision_MCU2_1_CheckpointReached(WdgM_CheckpointIdType CPID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *   Std_ReturnType Rte_Call_WdgM_AliveSupervision_MPU1_0_CheckpointReached(WdgM_CheckpointIdType CPID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_WDG_Main_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_WDG_CODE) RE_WDG_Main(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_WDG_Main
 *********************************************************************************************************************/
  /* DD-ID: {DB94FE34-5CB6-41fc-8F34-DB28D47E4B8A}*/

  /* Locals */
  static boolean LockDebug = TRUE;
  static uint8 su8Count = 0u;
  static volatile const uint8 testarray[WDG_ALL_CORE_CNT] = {TRUE,TRUE,TRUE,TRUE};
  
  /*Check the wathcdog keep alive signal for A core */ 
  f_CoreA_KeepAlive_Monitoring();

  /*Check the wathcdog  keep alive signal for 2_0 core */ 
  f_Core2_0_KeepAlive_Monitoring();

  /* Read the debug flag status from NVM and take action accordingly */
  (void)Rte_Read_RpFailsafeDebug_Debugflag(&DebugFlag);
  if((uint8)FALSE != DebugFlag)
  {
      su8Count = su8Count + (uint8)INCREMENT_BY_ONE;
      Pmic_F_StopPettingWdg_v();
      if ((LockDebug == (uint8)TRUE) && (su8Count >= (uint8)e_TEN))
      {
          (void)Pmic_wdgDisable(&pmic_device[0].pmicCoreHandle);
          LockDebug = FALSE;
          su8Count = 0u;
      }
  } else{ /* Do Nothing */}
  if(testarray[WDG_CORE_ID_ZERO] == (uint8)TRUE)
  {
      (void)Rte_Call_WdgM_AliveSupervision_MCU1_0_CheckpointReached((WdgM_SupervisedEntityIdType)0);
  } else{ /* Do Nothing */}
  if(testarray[WDG_CORE_ID_ONE] == (uint8)TRUE)
  {
    /*  (void)Rte_Call_WdgM_AliveSupervision_MCU2_0_CheckpointReached((WdgM_SupervisedEntityIdType)0); */
  } else{ /* Do Nothing */}
  if(testarray[WDG_CORE_ID_TWO] == (uint8)TRUE)
  {
    /*  (void)Rte_Call_WdgM_AliveSupervision_MCU2_1_CheckpointReached((WdgM_SupervisedEntityIdType)0); */
  } else{ /* Do Nothing */}
  if(testarray[WDG_CORE_ID_THREE] == (uint8)TRUE)
  {
   /*   (void)Rte_Call_WdgM_AliveSupervision_MPU1_0_CheckpointReached((WdgM_SupervisedEntityIdType)0); */
  } else{ /* Do Nothing */}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}




/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* ===========================================================================
 *
 *   Name: f_CoreA_KeepAlive_Monitoring
 *
 *   Function:  To be called from 10ms task to Monitor A Core health
 *
 *   Inputs: None
 *
 *   Outputs: None
 *
 *   Side Effects: None
 *
 *   Remarks: None
 *		
 * ========================================================================= */
static void f_CoreA_KeepAlive_Monitoring(void)
{
  /* DD-ID: {2176AEA6-F685-4688-83A6-2101CC31D936}*/
    /* Locals */
	static bool bFirstTimeFlag = false;
    static bool  first_keepAliveRecv = false;
    static uint16 wdgWarning = 0u;     
    static uint32 Iniatial_Wait = 0u;
    static uint32  prevs_FrameID_u32 = 0u;
	uint16 TSDStatus;    
    KeepAliveResponse_t v_keepAliveResponse_t = {0u};

    /* Check the wathcdog  keep alive signal for Core A */
    (void)Rte_Read_RpKeepAliveResponse_KeepAliveResponse_t(&v_keepAliveResponse_t);
    TSDStatus = Cdd_Safety_GetTSDStatus();

    if((false == first_keepAliveRecv) && (!(bFirstTimeFlag)))
    {
        first_keepAliveRecv = true;	
        prevs_FrameID_u32 = v_keepAliveResponse_t.FrameID_u32;
    }
    else
    {
      /* VCAST Jenkins requirement - do not modify */
      /* VCAST Jenkins requirement - do not modify */
        if(prevs_FrameID_u32 == v_keepAliveResponse_t.FrameID_u32)
      /* VCAST Jenkins requirement - do not modify */
      /* VCAST Jenkins requirement - do not modify */
        {
            wdgWarning = wdgWarning + (uint16)INCREMENT_BY_ONE;

            /*The fail scenario check*/      
            if( wdgWarning >= (uint16)D_CORE_A_MAX_WDG_FAILURE_COUNT)
            {
                /* stop pinging to wathcdog as it has reached the maximum failure count limit */
                first_keepAliveRecv = false;
                bFirstTimeFlag = true;	
            	#ifdef Enable_Printf
                appLogPrintf("\n Value of Waring countr is %d  Value of FrameID is %d ", wdgWarning ,v_keepAliveResponse_t.FrameID_u32 );
                #endif

            } else{ /* Do Nothing */}
        }
        else
        {
            /* the success scenario */
            first_keepAliveRecv = true;
            prevs_FrameID_u32 = v_keepAliveResponse_t.FrameID_u32;
            wdgWarning = 0u ;
        }
    }

    /* start watchdog and ping continousley */
    Iniatial_Wait = Iniatial_Wait + (uint32)INCREMENT_BY_ONE;
    if(Iniatial_Wait < (uint32)D_CORE_A_INIT_WAIT_TIME)
    {
        (void)Rte_Call_WdgM_AliveSupervision_MPU1_0_CheckpointReached((WdgM_SupervisedEntityIdType)0);  /* Wait at initatial Timeout 6sec */
    }
    else if((true == first_keepAliveRecv) ||
    		((uint16)SDL_VTM_TSD_REQ == TSDStatus) ||
   		    ((uint16)SDL_VTM_TSD_DONE == TSDStatus)) /* Note: Mask Alive monitoring of remote cores in case of Thermal-Shutdown */
    {
        (void)Rte_Call_WdgM_AliveSupervision_MPU1_0_CheckpointReached((WdgM_SupervisedEntityIdType)0);
    }	  
    else 
    {
        /* Data is not getting recived from A core Do nothing and Let Wdg Reset the SOC */
    }
}

/* ===========================================================================
 *
 *   Name: f_Core2_0_KeepAlive_Monitoring
 *
 *   Function:  To be called from 10ms task to Monitor MCU2_0 Core health
 *
 *   Inputs: None
 *
 *   Outputs: None
 *
 *   Side Effects: None
 *
 *   Remarks: None
 *		
 * ========================================================================= */
static void f_Core2_0_KeepAlive_Monitoring(void)
{
  /* DD-ID: {6B58E639-3E7F-42e0-BDF9-DD8F4BD91B77}*/
    /* Locals */
    static bool wdgInitCompleteFlag = false;
	static uint16_t wdgInitWaitTime_u16 = 0x0u;
    static uint16_t wdgDataLiveCntrTimeout_u32 = WDG_2_0_RESET_TIMEOUT;    
    static uint32_t wdgDataLiveCntrPrev_u32 = 0x0u;
    WdgCheckpointStatus_t WdgCheckpointStatus_Data = {0};
    uint16_t TSDStatus;

    /* Read the 2_0 core IPC live counter value */
    (void)Rte_Read_RpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t(&WdgCheckpointStatus_Data);
    TSDStatus = Cdd_Safety_GetTSDStatus();

    /* Initial wait */
    if(true != wdgInitCompleteFlag)
    {
        wdgInitWaitTime_u16 = wdgInitWaitTime_u16 + (uint16_t)INCREMENT_BY_ONE;
        (void)Rte_Call_WdgM_AliveSupervision_MCU2_0_CheckpointReached((WdgM_SupervisedEntityIdType)0);
        if(wdgInitWaitTime_u16 >= (uint16_t)WDG_2_0_INIT_WAIT_TIME)
        {
            wdgInitCompleteFlag = true;
        } else{ /* Do Nothing */}
    }
    else
    {
        /* Check freshness of data */
        if (WdgCheckpointStatus_Data.wdgDataLiveCntr_u32 != wdgDataLiveCntrPrev_u32)
        {
            /* Update previous counter same as new */
            wdgDataLiveCntrPrev_u32 = WdgCheckpointStatus_Data.wdgDataLiveCntr_u32;

            /* Call checkpoint reached for respective core */
            (void)Rte_Call_WdgM_AliveSupervision_MCU2_0_CheckpointReached((WdgM_SupervisedEntityIdType)0);

            /* Reset the Data Live Counter Timeout */
            wdgDataLiveCntrTimeout_u32 = WDG_2_0_RESET_TIMEOUT;
        }
        else if ((wdgDataLiveCntrTimeout_u32 > (uint8_t)e_ZERO) &&
                (((uint16_t)SDL_VTM_TSD_REQ != TSDStatus) ||
                ((uint16_t)SDL_VTM_TSD_DONE != TSDStatus)))
        {
            /* Decrement the Live Cntr Timeout */
            wdgDataLiveCntrTimeout_u32 = wdgDataLiveCntrTimeout_u32 - (uint16_t)DECREMENT_BY_ONE;

            /* Call checkpoint reached function (If Wdg status received in last 1 sec ) */
            (void)Rte_Call_WdgM_AliveSupervision_MCU2_0_CheckpointReached((WdgM_SupervisedEntityIdType)0);
        }
        else if(((uint16_t)SDL_VTM_TSD_REQ == TSDStatus) ||
                ((uint16_t)SDL_VTM_TSD_DONE == TSDStatus)) /* Note: Mask Alive monitoring of remote cores in case of Thermal-Shutdown */
        {
            (void)Rte_Call_WdgM_AliveSupervision_MCU2_0_CheckpointReached((WdgM_SupervisedEntityIdType)0);
        }	        
        else
        {
            /* Data is not getting received from 2_0 core, Do nothing and Let Wdg Reset the SOC */    
        }
    }
}

#define CDD_WDG_STOP_SEC_CODE
#include "CDD_WDG_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
