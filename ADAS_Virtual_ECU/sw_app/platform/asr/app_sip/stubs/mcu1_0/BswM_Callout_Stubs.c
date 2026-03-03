/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: BswM
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: BswM_Callout_Stubs.c
 *   Generation Time: 2024-02-13 13:07:47
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Version>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*********************************************************************************************************************
    INCLUDES
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
#define BSWM_CALLOUT_STUBS_SOURCE
#include "BswM.h"
#include "BswM_Private_Cfg.h"
#include "app_log.h"
#include "app_log_Boot.h"



/**********************************************************************************************************************
 *  Additional configured User includes
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Includes>                          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 #include "Ea.h"
#include "Eep_30_XXi2c01.h"
#include "Os_Lcfg.h"
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#  ifndef Cx0_Initialization
#   define Cx0_Initialization (0U)
#  endif

#  ifndef Cx1_IGN_LK
#   define Cx1_IGN_LK (1U)
#  endif

#  ifndef Cx3_ACC
#   define Cx3_ACC (3U)
#  endif

#  ifndef Cx4_RUN
#   define Cx4_RUN (4U)
#  endif

#  ifndef Cx5_START
#   define Cx5_START (5U)
#  endif

#  ifndef Cx7_SNA
#   define Cx7_SNA (7U)
#  endif

#define ZERO 0U
#define SIXTY_FIVE_THOUSAND_FIVE_THIRTY 65530U

typedef struct
{
  boolean bValid;
  Array_11Byte ConfigCode;
  Array_10Byte TesterCode;
  Array_04Byte ProductionDate;
  uint8 CanNode14trscm_uint8;
  uint8 Variant_ID;
  uint8 CanNode27Asm_uint8;
  uint8 CanNode63ttm_uint8;
  uint8 CanNode67dtcm_uint8;
  uint8 CanNode95itcm_uint8;
  uint8 StopandStart;
  uint8 DriverSide;
  uint16 Tyresize_uint16;
  uint8 Wheelbase;
  uint8 Rearviewcamera;
  uint8 Parkwithstop;
  uint8 SteeringRatio_uint8;
  uint8 Gearboxtype;
  uint8 Drivetypevariant;
  uint8 Pamtuningset;
  uint8 Semiautopark;
  uint8 VehicleLineConfiguration_uint8;
  uint8 CountryCode_uint8;
  uint8 Srt;
  uint8 PAMConfig_uint8;
  uint8 ModelYear_uint8;
  uint8 Hybridtype;
  uint8 Pulloutcontrol;
  uint8 Surroundviewcamera;
  uint8 Forwardfacingcamera;
  uint8 Autonomylevel;
  uint8 Fullautomaticparking;
  uint8 Radiodisplay;
  uint8 Mirrortype;
  uint8 Auxiliarycamera;
  uint8 Trailerreverseguide;
  uint8 Trailersurround;
  uint8 Trailerreversesteering;
  uint8 Trailerhitchassist;
  uint8 CVPAM_Presence_uint8;
  uint8 SideDistanceWarning;
  uint8 PROXIWriteCounter;
} ProxyConfiguration;

ProxyConfiguration Calibration_VariantId;

/**********************************************************************************************************************
 *  CALLOUT FUNCTIONS
 *********************************************************************************************************************/
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GENERIC CALLOUTS
 *********************************************************************************************************************/
FUNC(void, BSWM_CODE) BSW_AppDiag_InternalError_SysResetReq(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BSW_AppDiag_InternalError_SysResetReq>      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  AppDiag_InternalError_SysResetReq();
} /* End of BSW_AppDiag_InternalError_SysResetReq */


FUNC(void, BSWM_CODE) BSW_SSM_Master_SetRestartRequest(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BSW_SSM_Master_SetRestartRequest>       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  SSM_Master_SetRestartRequest();
} /* End of BSW_SSM_Master_SetRestartRequest */


FUNC(void, BSWM_CODE) BSW_SSM_Master_SetShutDownRequest(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BSW_SSM_Master_SetShutDownRequest>      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  SSM_Master_SetShutDownRequest();
} /* End of BSW_SSM_Master_SetShutDownRequest */


FUNC(void, BSWM_CODE) BSW_Shutdown(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BSW_Shutdown>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
	/* Disable Ext Watchdog	 */
	/* disable_pmicExtWdg() */
	/* Stop Dem operation cycle */
	(void)Dem_SetOperationCycleState(DemConf_DemOperationCycle_IgnitionCycle, DEM_CYCLE_STATE_END);
	/* Shutdown DEM */
	Dem_Shutdown();
	/* Clear Wakeup Events */
	EcuM_ClearValidatedWakeupEvent(ECUM_WKSOURCE_ALL_SOURCES);
	/* Stop RTE & Scheduler*/
	(void)Rte_Stop();
	SchM_Deinit();
	/*shutdown other cores */
	/* Set NVM Write */
	/* Write NVM */
	/* Shutdown Target will be performed when NVM write all is completed or when timeout happened*/
	/* Switch OFF the ECU */
	(void)ActivateTask(ShutdownTask);
	(void)TerminateTask();
} /* End of BSW_Shutdown */


FUNC(void, BSWM_CODE) BswM_AL_ResetProgrammableInterrupts(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_AL_ResetProgrammableInterrupts>    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
	/* Os_DisableInterruptSource(ADC0) */
	/* Os_DisableInterruptSource(ADC1) */
	/* Os_DisableInterruptSource(Can_30_McanIsr_0) */
	/* Os_DisableInterruptSource(Can_30_McanIsr_1) */

} /* End of BswM_AL_ResetProgrammableInterrupts */


FUNC(void, BSWM_CODE) BswM_AL_SetProgrammableInterrupts(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_AL_SetProgrammableInterrupts>      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
    (void)Os_EnableInterruptSource(ADC0,TRUE);
    (void)Os_EnableInterruptSource(ADC1,TRUE);
    (void)Os_EnableInterruptSource(I2c_IrqUnit0,TRUE);
    (void)Os_EnableInterruptSource(I2c_IrqUnit0,TRUE);
    (void)Os_EnableInterruptSource(I2c_IrqUnit0,TRUE);
    (void)Os_EnableInterruptSource(Can_30_McanIsr_0,TRUE);
    (void)Os_EnableInterruptSource(Can_30_McanIsr_1,TRUE);
    (void)Os_EnableInterruptSource(vHsmResponseIsr,TRUE);
} /* End of BswM_AL_SetProgrammableInterrupts */


FUNC(void, BSWM_CODE) BswM_ESH_OnEnterPostRun(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterPostRun>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterPostRun */


FUNC(void, BSWM_CODE) BswM_ESH_OnEnterPrepShutdown(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterPrepShutdown>           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterPrepShutdown */


FUNC(void, BSWM_CODE) BswM_ESH_OnEnterRun(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterRun>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterRun */


FUNC(void, BSWM_CODE) BswM_ESH_OnEnterShutdown(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterShutdown>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterShutdown */


FUNC(void, BSWM_CODE) BswM_ESH_OnEnterWaitForNvm(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterWaitForNvm>             DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterWaitForNvm */


FUNC(void, BSWM_CODE) BswM_ESH_OnEnterWakeup(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterWakeup>                 DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
    EcuM_ClearWakeupEvent(ECUM_WKSOURCE_RESET);
    EcuM_SetWakeupEvent(ECUM_WKSOURCE_CN_FDCAN2_28a8fc44);
} /* End of BswM_ESH_OnEnterWakeup */

FUNC(void, BSWM_CODE) BswM_INIT_NvMReadAll(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_INIT_NvMReadAll>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  NvM_RequestResultType Int_NvMultiBlockStatus;
  NvM_RequestResultType Int_ProxiConfigTable;

	(void)NvM_ReadAll();
	do
	{
		NvM_MainFunction();
		Ea_MainFunction();
		Eep_30_XXi2c01_MainFunction();

    (void)NvM_GetErrorStatus(NvMConf___MultiBlockRequest, &Int_NvMultiBlockStatus);
  } while (Int_NvMultiBlockStatus == (NvM_RequestResultType)NVM_REQ_PENDING);

	/* Reading NvM block of memory for Calibration variant Data */
	(void)NvM_ReadBlock(NvMConf_NvMBlockDescriptor_SWC_ProxiConfigMgrProxiConfigTable,(void*)&Calibration_VariantId);
	do
	{
		NvM_MainFunction();
		Ea_MainFunction();
		Eep_30_XXi2c01_MainFunction();

    (void)NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_SWC_ProxiConfigMgrProxiConfigTable, &Int_ProxiConfigTable);
  } while (Int_ProxiConfigTable == (NvM_RequestResultType)NVM_REQ_PENDING);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_INIT_NvMReadAll */


extern void Get_Vehicle_Variant(uint8* vehicle_variant)
{
   *vehicle_variant = Calibration_VariantId.Variant_ID;
}

FUNC(void, BSWM_CODE) BswM_NvM_WriteAll(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_NvM_WriteAll>                      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  NvM_RequestResultType Int_NvMultiBlockStatus;

  #ifdef Enable_Printf
  appLogPrintf("\n  BswM_NvM_WriteAll ");
  #endif
  volatile uint16 delayvar;

  /* PMIC_EnterLongWindow_DisableWdg(); Wdg is Already put in long window at the entry of shutdown task so this step is not required. */
  NvM_WriteAll();
  do
  {
    NvM_MainFunction();
    Ea_MainFunction();
    Eep_30_XXi2c01_MainFunction();
    for(delayvar=(uint16)ZERO;delayvar<(uint16)SIXTY_FIVE_THOUSAND_FIVE_THIRTY;delayvar++)
    {
    	/* Do nothing */
    }
    for(delayvar=(uint16)ZERO;delayvar<(uint16)SIXTY_FIVE_THOUSAND_FIVE_THIRTY;delayvar++)
    {
    	/* Do nothing */
    }


    (void)NvM_GetErrorStatus(NvMConf___MultiBlockRequest, &Int_NvMultiBlockStatus);
  } while (Int_NvMultiBlockStatus == (NvM_RequestResultType)NVM_REQ_PENDING);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_NvM_WriteAll */

FUNC(void, BSWM_CODE) BswM_SetNewDemOperationCycleState(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_SetNewDemOperationCycleState>      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  uint8 u8_CmdIgnSts ;
  BswM_BswM_PreviousNMState v_PrevNMState_u8;
  static uint8 v_DTCInitFlag_u8 = TRUE;
  
  (void)Com_ReceiveSignal(ComConf_ComSignal_CmdIgnSts_oBCM_FD_10_oFDCAN2_06c30ef2_Rx,&u8_CmdIgnSts);
  (void)Rte_Read_Request_RpPreviousNMState_requestedMode(&v_PrevNMState_u8);

  if((v_PrevNMState_u8 == RTE_MODE_BswM_PreviousNMState_NM_STATE_REPEAT) && (v_DTCInitFlag_u8 == TRUE))
  {/*This loop excute when ECU is wakeup after either "hard reset" or "sleep wakeup cycle". 
    There is no dem cycle swicth as it already swicth in DTCmgr init function*/
    v_DTCInitFlag_u8 = FALSE;
  }
  else
  {/*This loop excute when ECU is in "ready to sleep state" or if ecu move in "Repeat message state" form "wait to sleep" or "sleep state" */
      if(((v_PrevNMState_u8 == RTE_MODE_BswM_PreviousNMState_NM_STATE_REPEAT) || (v_PrevNMState_u8 == RTE_MODE_BswM_BswM_PreviousNMState_NM_STATE_READY_SLEEP)) &&
        (Cx4_RUN == u8_CmdIgnSts))
      {
        (void)Dem_SetOperationCycleState(DemConf_DemOperationCycle_IgnitionCycle, DEM_CYCLE_STATE_START);        
      }
  }
  (void) Rte_Write_Provide_BswM_DTCSettingClearFlag_requestedMode(TRUE);
} /* End of BswM_SetNewDemOperationCycleState */

FUNC(void, BSWM_CODE) ESH_ComM_CheckPendingRequests(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK ESH_ComM_CheckPendingRequests>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  ComM_StateType CN_FDCAN2_28a8fc44 = COMM_NO_COM_NO_PENDING_REQUEST;
  ComM_StateType CN_FDCAN14_a902658e = COMM_NO_COM_NO_PENDING_REQUEST;
  
  (void)ComM_GetState(ComMConf_ComMChannel_CN_FDCAN2_28a8fc44, &CN_FDCAN2_28a8fc44); /* SBSW_BSWM_FCTCALL_LOCALVAR */
  (void)ComM_GetState(ComMConf_ComMChannel_CN_FDCAN14_a902658e, &CN_FDCAN14_a902658e); /* SBSW_BSWM_FCTCALL_LOCALVAR */
  
  if((CN_FDCAN2_28a8fc44 != (ComM_StateType)COMM_NO_COM_NO_PENDING_REQUEST) || (CN_FDCAN14_a902658e != (ComM_StateType)COMM_NO_COM_NO_PENDING_REQUEST))
  {
    BswM_RequestMode(BSWM_GENERIC_ESH_ComMPendingRequests, BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_PENDING_REQUEST);
  }
  else
  {
    BswM_RequestMode(BSWM_GENERIC_ESH_ComMPendingRequests, BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_NO_REQUEST);
  }
  
} /* End of ESH_ComM_CheckPendingRequests */


FUNC(void, BSWM_CODE) ESH_Dem_PostRunRequested(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK ESH_Dem_PostRunRequested>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  boolean isRequested;
  (void)Dem_PostRunRequested(&isRequested); /* SBSW_BSWM_FCTCALL_LOCALVAR */
  if (isRequested == (boolean)TRUE)
  {
    BswM_RequestMode(BSWM_GENERIC_ESH_DemPostRunRequested, BSWM_GENERICVALUE_ESH_DemPostRunRequested_TRUE);
  }
  else
  {
    BswM_RequestMode(BSWM_GENERIC_ESH_DemPostRunRequested, BSWM_GENERICVALUE_ESH_DemPostRunRequested_FALSE);
  }
  
} /* End of ESH_Dem_PostRunRequested */




#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if 0
#endif


/**********************************************************************************************************************
 *  END OF FILE: BSWM_CALLOUT_STUBS.C
 *********************************************************************************************************************/


