/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_BswM_Type.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application types header file for SW-C <BswM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_BSWM_TYPE_H
# define RTE_BSWM_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef NM_STATE_BUS_SLEEP
#   define NM_STATE_BUS_SLEEP (1U)
#  endif

#  ifndef NM_STATE_NORMAL
#   define NM_STATE_NORMAL (4U)
#  endif

#  ifndef NM_STATE_PREPARE_SLEEP
#   define NM_STATE_PREPARE_SLEEP (2U)
#  endif

#  ifndef NM_STATE_READY_SLEEP
#   define NM_STATE_READY_SLEEP (3U)
#  endif

#  ifndef NM_STATE_REPEAT
#   define NM_STATE_REPEAT (5U)
#  endif

#  ifndef NM_UINIT
#   define NM_UINIT (0U)
#  endif

#  ifndef SC_CAL_NOT_STARTED
#   define SC_CAL_NOT_STARTED (0U)
#  endif

#  ifndef SC_CAL_FINISHED
#   define SC_CAL_FINISHED (1U)
#  endif

#  ifndef TRUE
#   define TRUE (1U)
#  endif

#  ifndef FALSE
#   define FALSE (0U)
#  endif

#  ifndef STARTUP
#   define STARTUP (0U)
#  endif

#  ifndef RUN
#   define RUN (1U)
#  endif

#  ifndef POSTRUN
#   define POSTRUN (2U)
#  endif

#  ifndef WAKEUP
#   define WAKEUP (3U)
#  endif

#  ifndef SHUTDOWN
#   define SHUTDOWN (4U)
#  endif

#  ifndef RELEASED
#   define RELEASED (0U)
#  endif

#  ifndef REQUESTED
#   define REQUESTED (1U)
#  endif

#  ifndef DCM_ENUM_NONE
#   define DCM_ENUM_NONE (0U)
#  endif

#  ifndef DCM_ENUM_HARD
#   define DCM_ENUM_HARD (1U)
#  endif

#  ifndef DCM_ENUM_KEYONOFF
#   define DCM_ENUM_KEYONOFF (2U)
#  endif

#  ifndef DCM_ENUM_SOFT
#   define DCM_ENUM_SOFT (3U)
#  endif

#  ifndef DCM_ENUM_JUMPTOBOOTLOADER
#   define DCM_ENUM_JUMPTOBOOTLOADER (4U)
#  endif

#  ifndef DCM_ENUM_JUMPTOSYSSUPPLIERBOOTLOADER
#   define DCM_ENUM_JUMPTOSYSSUPPLIERBOOTLOADER (5U)
#  endif

#  ifndef DCM_ENUM_EXECUTE
#   define DCM_ENUM_EXECUTE (6U)
#  endif

# endif /* RTE_CORE */


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
# ifndef RTE_MODETYPE_BswM_PreviousNMState
#  define RTE_MODETYPE_BswM_PreviousNMState
typedef BswM_BswM_PreviousNMState Rte_ModeType_BswM_PreviousNMState;
# endif
# ifndef RTE_MODETYPE_CalDataProSCCalStatus
#  define RTE_MODETYPE_CalDataProSCCalStatus
typedef BswM_CalDataProSCCalStatus Rte_ModeType_CalDataProSCCalStatus;
# endif
# ifndef RTE_MODETYPE_DcmEcuReset
#  define RTE_MODETYPE_DcmEcuReset
typedef Dcm_EcuResetType Rte_ModeType_DcmEcuReset;
# endif
# ifndef RTE_MODETYPE_DtcSettingClearFlagModeGrp
#  define RTE_MODETYPE_DtcSettingClearFlagModeGrp
typedef BswM_DtcSettingClearFlagModeGrp Rte_ModeType_DtcSettingClearFlagModeGrp;
# endif
# ifndef RTE_MODETYPE_ESH_Mode
#  define RTE_MODETYPE_ESH_Mode
typedef BswM_ESH_Mode Rte_ModeType_ESH_Mode;
# endif
# ifndef RTE_MODETYPE_ESH_RunRequest
#  define RTE_MODETYPE_ESH_RunRequest
typedef BswM_ESH_RunRequest Rte_ModeType_ESH_RunRequest;
# endif
# ifndef RTE_MODETYPE_MDG_CmdIgnitionState
#  define RTE_MODETYPE_MDG_CmdIgnitionState
typedef uint8 Rte_ModeType_MDG_CmdIgnitionState;
# endif
# ifndef RTE_MODETYPE_NM_State
#  define RTE_MODETYPE_NM_State
typedef uint8 Rte_ModeType_NM_State;
# endif
# ifndef RTE_MODETYPE_SSM_SystemState_Mode
#  define RTE_MODETYPE_SSM_SystemState_Mode
typedef uint8 Rte_ModeType_SSM_SystemState_Mode;
# endif
# ifndef RTE_MODETYPE_SYSModeRequestType
#  define RTE_MODETYPE_SYSModeRequestType
typedef uint8 Rte_ModeType_SYSModeRequestType;
# endif
# ifndef RTE_MODETYPE_SafetyGuard_BSWM_SafeMode
#  define RTE_MODETYPE_SafetyGuard_BSWM_SafeMode
typedef uint8 Rte_ModeType_SafetyGuard_BSWM_SafeMode;
# endif

# define RTE_MODE_BswM_BswM_PreviousNMState_NM_UINIT (0U)
# ifndef RTE_MODE_BswM_PreviousNMState_NM_UINIT
#  define RTE_MODE_BswM_PreviousNMState_NM_UINIT (0U)
# endif
# define RTE_MODE_BswM_BswM_PreviousNMState_NM_STATE_BUS_SLEEP (1U)
# ifndef RTE_MODE_BswM_PreviousNMState_NM_STATE_BUS_SLEEP
#  define RTE_MODE_BswM_PreviousNMState_NM_STATE_BUS_SLEEP (1U)
# endif
# define RTE_MODE_BswM_BswM_PreviousNMState_NM_STATE_PREPARE_SLEEP (2U)
# ifndef RTE_MODE_BswM_PreviousNMState_NM_STATE_PREPARE_SLEEP
#  define RTE_MODE_BswM_PreviousNMState_NM_STATE_PREPARE_SLEEP (2U)
# endif
# define RTE_MODE_BswM_BswM_PreviousNMState_NM_STATE_READY_SLEEP (3U)
# ifndef RTE_MODE_BswM_PreviousNMState_NM_STATE_READY_SLEEP
#  define RTE_MODE_BswM_PreviousNMState_NM_STATE_READY_SLEEP (3U)
# endif
# define RTE_MODE_BswM_BswM_PreviousNMState_NM_STATE_NORMAL (4U)
# ifndef RTE_MODE_BswM_PreviousNMState_NM_STATE_NORMAL
#  define RTE_MODE_BswM_PreviousNMState_NM_STATE_NORMAL (4U)
# endif
# define RTE_MODE_BswM_BswM_PreviousNMState_NM_STATE_REPEAT (5U)
# ifndef RTE_MODE_BswM_PreviousNMState_NM_STATE_REPEAT
#  define RTE_MODE_BswM_PreviousNMState_NM_STATE_REPEAT (5U)
# endif
# define RTE_TRANSITION_BswM_BswM_PreviousNMState (6U)
# ifndef RTE_TRANSITION_BswM_PreviousNMState
#  define RTE_TRANSITION_BswM_PreviousNMState (6U)
# endif

# define RTE_MODE_BswM_CalDataProSCCalStatus_SC_CAL_NOT_STARTED (0U)
# ifndef RTE_MODE_CalDataProSCCalStatus_SC_CAL_NOT_STARTED
#  define RTE_MODE_CalDataProSCCalStatus_SC_CAL_NOT_STARTED (0U)
# endif
# define RTE_MODE_BswM_CalDataProSCCalStatus_SC_CAL_FINISHED (1U)
# ifndef RTE_MODE_CalDataProSCCalStatus_SC_CAL_FINISHED
#  define RTE_MODE_CalDataProSCCalStatus_SC_CAL_FINISHED (1U)
# endif
# define RTE_TRANSITION_BswM_CalDataProSCCalStatus (2U)
# ifndef RTE_TRANSITION_CalDataProSCCalStatus
#  define RTE_TRANSITION_CalDataProSCCalStatus (2U)
# endif

# define RTE_MODE_BswM_DcmEcuReset_NONE (0U)
# ifndef RTE_MODE_DcmEcuReset_NONE
#  define RTE_MODE_DcmEcuReset_NONE (0U)
# endif
# define RTE_MODE_BswM_DcmEcuReset_HARD (1U)
# ifndef RTE_MODE_DcmEcuReset_HARD
#  define RTE_MODE_DcmEcuReset_HARD (1U)
# endif
# define RTE_MODE_BswM_DcmEcuReset_KEYONOFF (2U)
# ifndef RTE_MODE_DcmEcuReset_KEYONOFF
#  define RTE_MODE_DcmEcuReset_KEYONOFF (2U)
# endif
# define RTE_MODE_BswM_DcmEcuReset_SOFT (3U)
# ifndef RTE_MODE_DcmEcuReset_SOFT
#  define RTE_MODE_DcmEcuReset_SOFT (3U)
# endif
# define RTE_MODE_BswM_DcmEcuReset_JUMPTOBOOTLOADER (4U)
# ifndef RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER
#  define RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER (4U)
# endif
# define RTE_MODE_BswM_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER (5U)
# ifndef RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER
#  define RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER (5U)
# endif
# define RTE_MODE_BswM_DcmEcuReset_EXECUTE (6U)
# ifndef RTE_MODE_DcmEcuReset_EXECUTE
#  define RTE_MODE_DcmEcuReset_EXECUTE (6U)
# endif
# define RTE_TRANSITION_BswM_DcmEcuReset (7U)
# ifndef RTE_TRANSITION_DcmEcuReset
#  define RTE_TRANSITION_DcmEcuReset (7U)
# endif

# define RTE_MODE_BswM_DtcSettingClearFlagModeGrp_FALSE (0U)
# ifndef RTE_MODE_DtcSettingClearFlagModeGrp_FALSE
#  define RTE_MODE_DtcSettingClearFlagModeGrp_FALSE (0U)
# endif
# define RTE_MODE_BswM_DtcSettingClearFlagModeGrp_TRUE (1U)
# ifndef RTE_MODE_DtcSettingClearFlagModeGrp_TRUE
#  define RTE_MODE_DtcSettingClearFlagModeGrp_TRUE (1U)
# endif
# define RTE_TRANSITION_BswM_DtcSettingClearFlagModeGrp (2U)
# ifndef RTE_TRANSITION_DtcSettingClearFlagModeGrp
#  define RTE_TRANSITION_DtcSettingClearFlagModeGrp (2U)
# endif

# define RTE_MODE_BswM_ESH_Mode_STARTUP (0U)
# ifndef RTE_MODE_ESH_Mode_STARTUP
#  define RTE_MODE_ESH_Mode_STARTUP (0U)
# endif
# define RTE_MODE_BswM_ESH_Mode_RUN (1U)
# ifndef RTE_MODE_ESH_Mode_RUN
#  define RTE_MODE_ESH_Mode_RUN (1U)
# endif
# define RTE_MODE_BswM_ESH_Mode_POSTRUN (2U)
# ifndef RTE_MODE_ESH_Mode_POSTRUN
#  define RTE_MODE_ESH_Mode_POSTRUN (2U)
# endif
# define RTE_MODE_BswM_ESH_Mode_WAKEUP (3U)
# ifndef RTE_MODE_ESH_Mode_WAKEUP
#  define RTE_MODE_ESH_Mode_WAKEUP (3U)
# endif
# define RTE_MODE_BswM_ESH_Mode_SHUTDOWN (4U)
# ifndef RTE_MODE_ESH_Mode_SHUTDOWN
#  define RTE_MODE_ESH_Mode_SHUTDOWN (4U)
# endif
# define RTE_TRANSITION_BswM_ESH_Mode (5U)
# ifndef RTE_TRANSITION_ESH_Mode
#  define RTE_TRANSITION_ESH_Mode (5U)
# endif

# define RTE_MODE_BswM_ESH_RunRequest_RELEASED (0U)
# ifndef RTE_MODE_ESH_RunRequest_RELEASED
#  define RTE_MODE_ESH_RunRequest_RELEASED (0U)
# endif
# define RTE_MODE_BswM_ESH_RunRequest_REQUESTED (1U)
# ifndef RTE_MODE_ESH_RunRequest_REQUESTED
#  define RTE_MODE_ESH_RunRequest_REQUESTED (1U)
# endif
# define RTE_TRANSITION_BswM_ESH_RunRequest (2U)
# ifndef RTE_TRANSITION_ESH_RunRequest
#  define RTE_TRANSITION_ESH_RunRequest (2U)
# endif

# define RTE_MODE_BswM_MDG_CmdIgnitionState_CmdIgnitionState_OFF (0U)
# ifndef RTE_MODE_MDG_CmdIgnitionState_CmdIgnitionState_OFF
#  define RTE_MODE_MDG_CmdIgnitionState_CmdIgnitionState_OFF (0U)
# endif
# define RTE_MODE_BswM_MDG_CmdIgnitionState_CmdIgnitionState_ON (1U)
# ifndef RTE_MODE_MDG_CmdIgnitionState_CmdIgnitionState_ON
#  define RTE_MODE_MDG_CmdIgnitionState_CmdIgnitionState_ON (1U)
# endif
# define RTE_MODE_BswM_MDG_CmdIgnitionState_CmdIgnitionState_INVALID (255U)
# ifndef RTE_MODE_MDG_CmdIgnitionState_CmdIgnitionState_INVALID
#  define RTE_MODE_MDG_CmdIgnitionState_CmdIgnitionState_INVALID (255U)
# endif
# define RTE_TRANSITION_BswM_MDG_CmdIgnitionState (2U)
# ifndef RTE_TRANSITION_MDG_CmdIgnitionState
#  define RTE_TRANSITION_MDG_CmdIgnitionState (2U)
# endif

# define RTE_MODE_BswM_NM_State_NM_UINIT (0U)
# ifndef RTE_MODE_NM_State_NM_UINIT
#  define RTE_MODE_NM_State_NM_UINIT (0U)
# endif
# define RTE_MODE_BswM_NM_State_NM_STATE_BUS_SLEEP (1U)
# ifndef RTE_MODE_NM_State_NM_STATE_BUS_SLEEP
#  define RTE_MODE_NM_State_NM_STATE_BUS_SLEEP (1U)
# endif
# define RTE_MODE_BswM_NM_State_NM_STATE_PREPARE_SLEEP (2U)
# ifndef RTE_MODE_NM_State_NM_STATE_PREPARE_SLEEP
#  define RTE_MODE_NM_State_NM_STATE_PREPARE_SLEEP (2U)
# endif
# define RTE_MODE_BswM_NM_State_NM_STATE_READY_SLEEP (3U)
# ifndef RTE_MODE_NM_State_NM_STATE_READY_SLEEP
#  define RTE_MODE_NM_State_NM_STATE_READY_SLEEP (3U)
# endif
# define RTE_MODE_BswM_NM_State_NM_STATE_NORMAL (4U)
# ifndef RTE_MODE_NM_State_NM_STATE_NORMAL
#  define RTE_MODE_NM_State_NM_STATE_NORMAL (4U)
# endif
# define RTE_MODE_BswM_NM_State_NM_STATE_REPEAT (5U)
# ifndef RTE_MODE_NM_State_NM_STATE_REPEAT
#  define RTE_MODE_NM_State_NM_STATE_REPEAT (5U)
# endif
# define RTE_TRANSITION_BswM_NM_State (6U)
# ifndef RTE_TRANSITION_NM_State
#  define RTE_TRANSITION_NM_State (6U)
# endif

# define RTE_MODE_BswM_SSM_SystemState_Mode_SSM_STATE_BOOTING (0U)
# ifndef RTE_MODE_SSM_SystemState_Mode_SSM_STATE_BOOTING
#  define RTE_MODE_SSM_SystemState_Mode_SSM_STATE_BOOTING (0U)
# endif
# define RTE_MODE_BswM_SSM_SystemState_Mode_SSM_STATE_BOOT_ERROR (1U)
# ifndef RTE_MODE_SSM_SystemState_Mode_SSM_STATE_BOOT_ERROR
#  define RTE_MODE_SSM_SystemState_Mode_SSM_STATE_BOOT_ERROR (1U)
# endif
# define RTE_MODE_BswM_SSM_SystemState_Mode_SSM_STATE_DEGRADED (2U)
# ifndef RTE_MODE_SSM_SystemState_Mode_SSM_STATE_DEGRADED
#  define RTE_MODE_SSM_SystemState_Mode_SSM_STATE_DEGRADED (2U)
# endif
# define RTE_MODE_BswM_SSM_SystemState_Mode_SSM_STATE_IPCREADY (3U)
# ifndef RTE_MODE_SSM_SystemState_Mode_SSM_STATE_IPCREADY
#  define RTE_MODE_SSM_SystemState_Mode_SSM_STATE_IPCREADY (3U)
# endif
# define RTE_MODE_BswM_SSM_SystemState_Mode_SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE (4U)
# ifndef RTE_MODE_SSM_SystemState_Mode_SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE
#  define RTE_MODE_SSM_SystemState_Mode_SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE (4U)
# endif
# define RTE_MODE_BswM_SSM_SystemState_Mode_SSM_STATE_MAX (5U)
# ifndef RTE_MODE_SSM_SystemState_Mode_SSM_STATE_MAX
#  define RTE_MODE_SSM_SystemState_Mode_SSM_STATE_MAX (5U)
# endif
# define RTE_MODE_BswM_SSM_SystemState_Mode_SSM_STATE_OFF (6U)
# ifndef RTE_MODE_SSM_SystemState_Mode_SSM_STATE_OFF
#  define RTE_MODE_SSM_SystemState_Mode_SSM_STATE_OFF (6U)
# endif
# define RTE_MODE_BswM_SSM_SystemState_Mode_SSM_STATE_RUNNING (7U)
# ifndef RTE_MODE_SSM_SystemState_Mode_SSM_STATE_RUNNING
#  define RTE_MODE_SSM_SystemState_Mode_SSM_STATE_RUNNING (7U)
# endif
# define RTE_MODE_BswM_SSM_SystemState_Mode_SSM_STATE_SHUTTINGDOWN_REMOTECORES (8U)
# ifndef RTE_MODE_SSM_SystemState_Mode_SSM_STATE_SHUTTINGDOWN_REMOTECORES
#  define RTE_MODE_SSM_SystemState_Mode_SSM_STATE_SHUTTINGDOWN_REMOTECORES (8U)
# endif
# define RTE_MODE_BswM_SSM_SystemState_Mode_SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP (9U)
# ifndef RTE_MODE_SSM_SystemState_Mode_SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP
#  define RTE_MODE_SSM_SystemState_Mode_SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP (9U)
# endif
# define RTE_TRANSITION_BswM_SSM_SystemState_Mode (10U)
# ifndef RTE_TRANSITION_SSM_SystemState_Mode
#  define RTE_TRANSITION_SSM_SystemState_Mode (10U)
# endif

# define RTE_MODE_BswM_SYSModeRequestType_SYS_REQ_INIT (0U)
# ifndef RTE_MODE_SYSModeRequestType_SYS_REQ_INIT
#  define RTE_MODE_SYSModeRequestType_SYS_REQ_INIT (0U)
# endif
# define RTE_MODE_BswM_SYSModeRequestType_SYS_REQ_HARDRESET (1U)
# ifndef RTE_MODE_SYSModeRequestType_SYS_REQ_HARDRESET
#  define RTE_MODE_SYSModeRequestType_SYS_REQ_HARDRESET (1U)
# endif
# define RTE_MODE_BswM_SYSModeRequestType_SYS_REQ_JUMPTOBOOT (2U)
# ifndef RTE_MODE_SYSModeRequestType_SYS_REQ_JUMPTOBOOT
#  define RTE_MODE_SYSModeRequestType_SYS_REQ_JUMPTOBOOT (2U)
# endif
# define RTE_MODE_BswM_SYSModeRequestType_SYS_REQ_INVALID (3U)
# ifndef RTE_MODE_SYSModeRequestType_SYS_REQ_INVALID
#  define RTE_MODE_SYSModeRequestType_SYS_REQ_INVALID (3U)
# endif
# define RTE_TRANSITION_BswM_SYSModeRequestType (4U)
# ifndef RTE_TRANSITION_SYSModeRequestType
#  define RTE_TRANSITION_SYSModeRequestType (4U)
# endif

# define RTE_MODE_BswM_SafetyGuard_BSWM_SafeMode_SAFETTYGUARD_SAFASTATE_NORMAL (0U)
# ifndef RTE_MODE_SafetyGuard_BSWM_SafeMode_SAFETTYGUARD_SAFASTATE_NORMAL
#  define RTE_MODE_SafetyGuard_BSWM_SafeMode_SAFETTYGUARD_SAFASTATE_NORMAL (0U)
# endif
# define RTE_MODE_BswM_SafetyGuard_BSWM_SafeMode_SAFETYGUARD_SAFESTATE_2_RESET (1U)
# ifndef RTE_MODE_SafetyGuard_BSWM_SafeMode_SAFETYGUARD_SAFESTATE_2_RESET
#  define RTE_MODE_SafetyGuard_BSWM_SafeMode_SAFETYGUARD_SAFESTATE_2_RESET (1U)
# endif
# define RTE_TRANSITION_BswM_SafetyGuard_BSWM_SafeMode (2U)
# ifndef RTE_TRANSITION_SafetyGuard_BSWM_SafeMode
#  define RTE_TRANSITION_SafetyGuard_BSWM_SafeMode (2U)
# endif

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_BSWM_TYPE_H */
