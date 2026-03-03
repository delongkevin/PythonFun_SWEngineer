/** \file Us_Csm_Conf.c
 *  \version 1.00
 *  \date 2013-06-05
 *  \author Amol Gore (Amol.Gore\magna.com)
 *  \brief This file contains the configuration data for <UsCsm>
 *
 *  \copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 */

/************************************************************************************************************************
                                                            Includes
************************************************************************************************************************/
#include "Us_Csm_Main.h"
#include "Us_Csm_Types.h"
#include "Us_Platform_CsmIf.h"
#include "Us_Hsd_CsmIf.h"
#include "Us_Csm_Conf.h"
#include "Us_Csm_Rules_If.h"
#include "Us_Csm_Actions_If.h"
#include "Us_Csm_StateActions_If.h"

/************************************************************************************************************************
                                                            Local #defines
************************************************************************************************************************/
#define US_CSM_LOCALMODULE_INSEQ_INIT             ((UsCsm_LocalModuleId_Type)7U)
#define US_CSM_LOCALMODULE_INSEQ_SHUTDOWN         ((UsCsm_LocalModuleId_Type)7U)
#define US_CSM_LOCALMODULE_INSEQ_SAFE_STATE_1     ((UsCsm_LocalModuleId_Type)6U)

/************************************************************************************************************************
                                                            Global Variables
************************************************************************************************************************/


/************************************************************************************************************************
                                                            Local Variables
************************************************************************************************************************/


/************************************************************************************************************************
                                                            Global Functions
************************************************************************************************************************/
static UsCsm_LocalErrSts_Type UsCsm_LocalErrState_Csm[US_CSM_CSM_INSTANCE_ID_MAX][US_CSM_CSM_ERR_ID_MAX];
static UsCsm_LocalErrSts_Type UsCsm_LocalErrState_Platform[US_CSM_PLATFORM_INSTANCE_ID_MAX][US_CSM_PLATFORM_ERR_ID_MAX];
static UsCsm_LocalErrSts_Type UsCsm_LocalErrState_Hsd[US_CSM_HSD_INSTANCE_ID_MAX][US_CSM_HSD_ERR_ID_MAX];
static UsCsm_LocalErrSts_Type UsCsm_LocalErrState_Dsi3Trcv[US_CSM_DSI3_TRCV_INSTANCE_ID_MAX][US_CSM_DSI3_TRCV_ERR_ID_MAX];
static UsCsm_LocalErrSts_Type UsCsm_LocalErrState_SnrDrv[US_CSM_SNR_DRV_INSTANCE_ID_MAX][US_CSM_SNR_DRV_ERR_ID_MAX];
static UsCsm_LocalErrSts_Type UsCsm_LocalErrState_SnrCntrl[US_CSM_SNR_CNTRL_INSTANCE_ID_MAX][US_CSM_SNR_CNTRL_ERR_ID_MAX];
static UsCsm_LocalErrSts_Type UsCsm_LocalErrState_ObjDetMngr[US_CSM_OBJ_DET_MNGR_INSTANCE_ID_MAX][US_CSM_OBJ_DET_MNGR_ERR_ID_MAX];
static UsCsm_LocalErrSts_Type UsCsm_LocalErrState_Calib[US_CSM_CALIB_INSTANCE_ID_MAX][US_CSM_CALIB_ERR_ID_MAX];

/*
* This section UsCsm_ErrConf contain the error configuration like processing types and 
* what rule and action to be performed when error condtion is true or false
*/
static UsCsm_ErrConf_Type UsCsm_ErrConf_Csm[US_CSM_CSM_INSTANCE_ID_MAX][US_CSM_CSM_ERR_ID_MAX] = 
{
	{
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_SafeState1},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, NULL_PTR_EXECUTE_RULE, NULL_PTR_EXECUTE_ACTION},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, NULL_PTR_EXECUTE_RULE, NULL_PTR_EXECUTE_ACTION},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, NULL_PTR_EXECUTE_RULE, NULL_PTR_EXECUTE_ACTION},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, NULL_PTR_EXECUTE_RULE, NULL_PTR_EXECUTE_ACTION},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, NULL_PTR_EXECUTE_RULE, NULL_PTR_EXECUTE_ACTION},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, NULL_PTR_EXECUTE_RULE, NULL_PTR_EXECUTE_ACTION},
	}
};


/*
* This section UsCsm_ErrConf contain the error configuration like processing types and 
* what rule and action to be performed when error condtion is true or false
*/
static UsCsm_ErrConf_Type UsCsm_ErrConf_Platform[US_CSM_PLATFORM_INSTANCE_ID_MAX][US_CSM_PLATFORM_ERR_ID_MAX] = 
{
	{
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_SafeState1},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_SafeState1},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_SafeState1},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, NULL_PTR_EXECUTE_RULE, NULL_PTR_EXECUTE_ACTION},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, NULL_PTR_EXECUTE_RULE, NULL_PTR_EXECUTE_ACTION},
	}
};


/**
 * \brief This structure holds the error configuration of High side driver
 * 
 */
static UsCsm_ErrConf_Type UsCsm_ErrConf_Hsd[US_CSM_HSD_INSTANCE_ID_MAX][US_CSM_HSD_ERR_ID_MAX] = 
{
	{
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_IMMIGIATE,  UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_SafeState1},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_IMMIGIATE,  UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_IMMIGIATE,  UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_IMMIGIATE,  UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_IMMIGIATE,  UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
	},
	{
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_IMMIGIATE,  UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_SafeState1},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_IMMIGIATE,  UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_IMMIGIATE,  UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_IMMIGIATE,  UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_IMMIGIATE,  UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
	}
};


/**
 * \brief This structure holds the error configuration of dsi3 transreceiver module
 * 
 */
static UsCsm_ErrConf_Type UsCsm_ErrConf_Dsi3Trcv[US_CSM_DSI3_TRCV_INSTANCE_ID_MAX][US_CSM_DSI3_TRCV_ERR_ID_MAX] = 
{
	{
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_SafeState1},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_SafeState1},
	}
};
 
/**
 * \brief This structure holds the error configuration of sensor driver module
 * 
 */
static UsCsm_ErrConf_Type UsCsm_ErrConf_SnrDrv[US_CSM_SNR_DRV_INSTANCE_ID_MAX][US_CSM_SNR_DRV_ERR_ID_MAX] =
{
	{
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
	}
};


/**
 * \brief This structure holds the error configuration of sensor control module.
 * 
 */
static UsCsm_ErrConf_Type UsCsm_ErrConf_SnrCntrl[US_CSM_SNR_CNTRL_INSTANCE_ID_MAX][US_CSM_SNR_CNTRL_ERR_ID_MAX] =
{
	{
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, NULL_PTR_EXECUTE_RULE, NULL_PTR_EXECUTE_ACTION},
	}
};


/**
 * \brief This structure holds the error configuration of object detection module
 * 
 */
static UsCsm_ErrConf_Type UsCsm_ErrConf_ObjDetMngr[US_CSM_OBJ_DET_MNGR_INSTANCE_ID_MAX][US_CSM_OBJ_DET_MNGR_ERR_ID_MAX]= 
{
	{
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, NULL_PTR_EXECUTE_RULE, NULL_PTR_EXECUTE_ACTION},
	}
};


/**
 * \brief This structure holds the error configuration of calibration module
 * 
 */
static UsCsm_ErrConf_Type UsCsm_ErrConf_Calib[US_CSM_CALIB_INSTANCE_ID_MAX][US_CSM_CALIB_ERR_ID_MAX]= 
{
	{
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_Degraded},
		{US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED, UsCsm_Rule_CheckAndExecuteRule_AlwaysPass, UsCsm_Action_SafeState1},
	}
};


/**
 * \brief This structure holds the local module configuration for csm
 * 
 */
UsCsm_LocalModuleConf_Type UsCsmLocalModuleConf[US_CSM_LOCAL_MODULE_ID_MAX] = 
{ 
	{NULL_PTR_REQ_STATE,         NULL_PTR_GET_STATE,         US_CSM_CSM_INSTANCE_ID_MAX,            {&UsCsm_LocalErrState_Csm[0][0],       &UsCsm_ErrConf_Csm[0][0],       (UsCsm_LocalErrorId_Type)US_CSM_CSM_ERR_ID_MAX}},
	{Us_Platform_ReqState_Csm,   Us_Platform_GetState_Csm,   US_CSM_PLATFORM_INSTANCE_ID_MAX,       {&UsCsm_LocalErrState_Platform[0][0],  &UsCsm_ErrConf_Platform[0][0],  (UsCsm_LocalErrorId_Type)US_CSM_PLATFORM_ERR_ID_MAX}},
	{Us_Hsd_ReqState_Csm,        Us_Hsd_GetState_Csm,        US_CSM_HSD_INSTANCE_ID_MAX,            {&UsCsm_LocalErrState_Hsd[0][0],       &UsCsm_ErrConf_Hsd[0][0],       (UsCsm_LocalErrorId_Type)US_CSM_HSD_ERR_ID_MAX}},
	{Us_Dsi3Trcv_ReqState_Csm,   Us_Dsi3Trcv_GetState_Csm,   US_CSM_DSI3_TRCV_INSTANCE_ID_MAX,      {&UsCsm_LocalErrState_Dsi3Trcv[0][0],  &UsCsm_ErrConf_Dsi3Trcv[0][0],  (UsCsm_LocalErrorId_Type)US_CSM_DSI3_TRCV_ERR_ID_MAX}},
	{Us_SnrDrv_ReqState_Csm,     Us_SnrDrv_GetState_Csm,     US_CSM_SNR_DRV_INSTANCE_ID_MAX,        {&UsCsm_LocalErrState_SnrDrv[0][0],    &UsCsm_ErrConf_SnrDrv[0][0],    (UsCsm_LocalErrorId_Type)US_CSM_SNR_DRV_ERR_ID_MAX}},
	{Us_SnrCntrl_ReqState_Csm,   Us_SnrCntrl_GetState_Csm,   US_CSM_SNR_CNTRL_INSTANCE_ID_MAX,      {&UsCsm_LocalErrState_SnrCntrl[0][0],  &UsCsm_ErrConf_SnrCntrl[0][0],  (UsCsm_LocalErrorId_Type)US_CSM_SNR_CNTRL_ERR_ID_MAX}},
	{Us_ObjDetMngr_ReqState_Csm, Us_ObjDetMngr_GetState_Csm, US_CSM_OBJ_DET_MNGR_INSTANCE_ID_MAX,   {&UsCsm_LocalErrState_ObjDetMngr[0][0],&UsCsm_ErrConf_ObjDetMngr[0][0],(UsCsm_LocalErrorId_Type)US_CSM_OBJ_DET_MNGR_ERR_ID_MAX}},
	{Us_Calib_ReqState_Csm,      Us_Calib_GetState_Csm,      US_CSM_CALIB_INSTANCE_ID_MAX,          {&UsCsm_LocalErrState_Calib[0][0], 	   &UsCsm_ErrConf_Calib[0][0],     (UsCsm_LocalErrorId_Type)US_CSM_CALIB_ERR_ID_MAX}}
};

/**
 * \brief UsCsm_LocalModule_StateSeq_Init holds the sub module ID list arrangaed by SEQ for init. 
 * 
 */
static  UsCsm_LocalModuleStateActionConf_Type UsCsm_LocalModule_StateSeq_Init[US_CSM_LOCALMODULE_INSEQ_INIT] =
{
	{US_CSM_LOCAL_MODULE_ID_PLATFORM,    US_CSM_LOCAL_STATE_INIT},
	{US_CSM_LOCAL_MODULE_ID_HSD,         US_CSM_LOCAL_STATE_INIT},
	{US_CSM_LOCAL_MODULE_ID_DSI3_TRCV,   US_CSM_LOCAL_STATE_INIT},
	{US_CSM_LOCAL_MODULE_ID_SNR_DRV,     US_CSM_LOCAL_STATE_INIT},
	{US_CSM_LOCAL_MODULE_ID_SNR_CNTRL,   US_CSM_LOCAL_STATE_INIT},
	{US_CSM_LOCAL_MODULE_ID_OBJ_DET_MNGR,US_CSM_LOCAL_STATE_INIT},
	{US_CSM_LOCAL_MODULE_ID_CALIB,       US_CSM_LOCAL_STATE_INIT},
};


/**
 * \brief UsCsm_LocalModule_StateSeq_Shutdown holds the sub module ID list arrangaed by SEQ for shutdown.
 * 
 */
static UsCsm_LocalModuleStateActionConf_Type UsCsm_LocalModule_StateSeq_Shutdown[US_CSM_LOCALMODULE_INSEQ_SHUTDOWN] =
{
	{US_CSM_LOCAL_MODULE_ID_OBJ_DET_MNGR,US_CSM_LOCAL_STATE_SHUTDOWN},
	{US_CSM_LOCAL_MODULE_ID_SNR_CNTRL,   US_CSM_LOCAL_STATE_SHUTDOWN},
	{US_CSM_LOCAL_MODULE_ID_SNR_DRV,     US_CSM_LOCAL_STATE_SHUTDOWN},
	{US_CSM_LOCAL_MODULE_ID_DSI3_TRCV,   US_CSM_LOCAL_STATE_SHUTDOWN},
	{US_CSM_LOCAL_MODULE_ID_HSD,         US_CSM_LOCAL_STATE_SHUTDOWN},
	{US_CSM_LOCAL_MODULE_ID_PLATFORM,    US_CSM_LOCAL_STATE_SHUTDOWN},
	{US_CSM_LOCAL_MODULE_ID_CALIB,       US_CSM_LOCAL_STATE_SHUTDOWN},
};

/**
 * \brief UsCsm_LocalModule_StateSeq_Shutdown holds the sub module ID list arrangaed by SEQ for shutdown.
 * 
 */
 static UsCsm_LocalModuleStateActionConf_Type UsCsm_LocalModule_StateSeq_SafeState1[US_CSM_LOCALMODULE_INSEQ_SAFE_STATE_1] =
{
	{US_CSM_LOCAL_MODULE_ID_OBJ_DET_MNGR,US_CSM_LOCAL_STATE_SHUTDOWN},
	{US_CSM_LOCAL_MODULE_ID_SNR_CNTRL,   US_CSM_LOCAL_STATE_SHUTDOWN},
	{US_CSM_LOCAL_MODULE_ID_SNR_DRV,     US_CSM_LOCAL_STATE_SHUTDOWN},
	{US_CSM_LOCAL_MODULE_ID_DSI3_TRCV,   US_CSM_LOCAL_STATE_SHUTDOWN},
	{US_CSM_LOCAL_MODULE_ID_PLATFORM,    US_CSM_LOCAL_STATE_SHUTDOWN},
	{US_CSM_LOCAL_MODULE_ID_CALIB,       US_CSM_LOCAL_STATE_SHUTDOWN},
};


/**
 * \brief 
 * 
 */
 UsCsm_CsmStateActionSeqConf_Type UsCsm_CsmStateActionSeqConf[US_CSM_LOCAL_STATE_SEQ_MAX] = 
{
  {UsCsm_LocalModule_StateSeq_Init,       US_CSM_LOCALMODULE_INSEQ_INIT},
  {UsCsm_LocalModule_StateSeq_Shutdown,   US_CSM_LOCALMODULE_INSEQ_SHUTDOWN},
  {UsCsm_LocalModule_StateSeq_SafeState1, US_CSM_LOCALMODULE_INSEQ_SAFE_STATE_1}
};


/**
 * \brief 
 * 
 */
UsCsm_CsmStateChangeReason_Type UsCsmStateChangeReason_Internal =
{
	.LocalModuleId = US_CSM_LOCAL_MODULE_ID_CSM,
	.InstanceId    = US_CSM_CSM_INSTANCE_ID_0,
	.LocalErrId    = US_CSM_LOCAL_MODULE_ERR_ID_INT_DEAFULT,
	.LocalErrState = US_CSM_LOCAL_ERR_STATE_CONFIRM,
};


/**
 * \brief This structure holds configuration of the state action on state entry , during and exit. These action are optional which are confugured as NULL_PTR_STATE_ACTION
 * 
 */
UsCsm_StateConf_Type UsCsmStateConf[US_CSM_STATE_ID_MAX] =
{
	{
		.StateActionOnEntry  = NULL_PTR_STATE_ACTION, 
		.StateActionOnDuring = UsCsm_StateAction_DuringUninit, 
		.StateActionOnExit   = UsCsm_StateAction_ExitUninit
	},	/*US_CSM_STATE_ID_UN_INIT*/
	{
		.StateActionOnEntry  = UsCsm_StateAction_OnEntryInitState, 
		.StateActionOnDuring = UsCsm_StateAction_DuringInitState, 
		.StateActionOnExit   = UsCsm_StateAction_ExitInit,
	},	/*	US_CSM_STATE_ID_INIT*/
	{
		.StateActionOnEntry  = NULL_PTR_STATE_ACTION, 
		.StateActionOnDuring = NULL_PTR_STATE_ACTION, 
		.StateActionOnExit   = NULL_PTR_STATE_ACTION
	},	/*	US_CSM_STATE_ID_ACTIVE*/
	{
		.StateActionOnEntry  = NULL_PTR_STATE_ACTION, 
		.StateActionOnDuring = NULL_PTR_STATE_ACTION, 
		.StateActionOnExit   = NULL_PTR_STATE_ACTION
	},	/*	US_CSM_STATE_ID_PREDEGRADE*/
	{
		.StateActionOnEntry  = NULL_PTR_STATE_ACTION, 
		.StateActionOnDuring = UsCsm_StateAction_DuringDegraded, 
		.StateActionOnExit   = NULL_PTR_STATE_ACTION
	},	/*	US_CSM_STATE_ID_DEGRADED*/
	{
		.StateActionOnEntry  = UsCsm_StateAction_OnEntryPreSafeState1, 
		.StateActionOnDuring = UsCsm_StateAction_DuringPreSafestate1, 
		.StateActionOnExit   = NULL_PTR_STATE_ACTION
	},	/*	US_CSM_STATE_ID_PRE_SAFE_STATE_1*/
	{
		.StateActionOnEntry  = NULL_PTR_STATE_ACTION, 
		.StateActionOnDuring = NULL_PTR_STATE_ACTION, 
		.StateActionOnExit   = NULL_PTR_STATE_ACTION
	},	/*	US_CSM_STATE_ID_SAFE_STATE_1*/
	{
		.StateActionOnEntry  = UsCsm_StateAction_OnEntryPreShutdown, 
		.StateActionOnDuring = UsCsm_StateAction_DuringPreShutdown, 
		.StateActionOnExit   = NULL_PTR_STATE_ACTION
	},	/*	US_CSM_STATE_ID_PRESHUTDOWN*/
	{
		.StateActionOnEntry  = NULL_PTR_STATE_ACTION, 
		.StateActionOnDuring = NULL_PTR_STATE_ACTION, 
		.StateActionOnExit   = NULL_PTR_STATE_ACTION
	},	/*	US_CSM_STATE_ID_SHUTDOWN*/
};


/************************************************************************************************************************
                                                            Local Functions
************************************************************************************************************************/


/************************************************************************************************************************
                                                            Function Definations
************************************************************************************************************************/

