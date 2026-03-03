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
 *             File:  Rte_SSM_Master_Type.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application types header file for SW-C <SSM_Master>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SSM_MASTER_TYPE_H
# define RTE_SSM_MASTER_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef SSM_APPSTATE_UNINIT
#   define SSM_APPSTATE_UNINIT (0U)
#  endif

#  ifndef SSM_APPSTATE_INIT
#   define SSM_APPSTATE_INIT (1U)
#  endif

#  ifndef SSM_APPSTATE_RUNNING
#   define SSM_APPSTATE_RUNNING (2U)
#  endif

#  ifndef SSM_APPSTATE_DEGRADED
#   define SSM_APPSTATE_DEGRADED (3U)
#  endif

#  ifndef SSM_APPSTATE_STOPPED
#   define SSM_APPSTATE_STOPPED (4U)
#  endif

#  ifndef SSM_APPSTATE_MAX
#   define SSM_APPSTATE_MAX (5U)
#  endif

#  ifndef SSM_APPSTATE_UNINIT
#   define SSM_APPSTATE_UNINIT (0U)
#  endif

#  ifndef SSM_APPSTATE_INIT
#   define SSM_APPSTATE_INIT (1U)
#  endif

#  ifndef SSM_APPSTATE_RUNNING
#   define SSM_APPSTATE_RUNNING (2U)
#  endif

#  ifndef SSM_APPSTATE_DEGRADED
#   define SSM_APPSTATE_DEGRADED (3U)
#  endif

#  ifndef SSM_APPSTATE_STOPPED
#   define SSM_APPSTATE_STOPPED (4U)
#  endif

#  ifndef SSM_APPSTATE_MAX
#   define SSM_APPSTATE_MAX (5U)
#  endif

#  ifndef SSM_SlaveCore_State_Unknown
#   define SSM_SlaveCore_State_Unknown (0U)
#  endif

#  ifndef SSM_SlaveCore_State_BSP_Booting
#   define SSM_SlaveCore_State_BSP_Booting (1U)
#  endif

#  ifndef SSM_SlaveCore_State_BSP_Init_Done
#   define SSM_SlaveCore_State_BSP_Init_Done (2U)
#  endif

#  ifndef SSM_SlaveCore_State_Calibrated
#   define SSM_SlaveCore_State_Calibrated (3U)
#  endif

#  ifndef SSM_SlaveCore_State_AppInitialized
#   define SSM_SlaveCore_State_AppInitialized (4U)
#  endif

#  ifndef SSM_SlaveCore_State_Running
#   define SSM_SlaveCore_State_Running (5U)
#  endif

#  ifndef SSM_SlaveCore_State_MAX
#   define SSM_SlaveCore_State_MAX (6U)
#  endif

#  ifndef SSM_SlaveCore_State_Unknown
#   define SSM_SlaveCore_State_Unknown (0U)
#  endif

#  ifndef SSM_SlaveCore_State_BSP_Booting
#   define SSM_SlaveCore_State_BSP_Booting (1U)
#  endif

#  ifndef SSM_SlaveCore_State_BSP_Init_Done
#   define SSM_SlaveCore_State_BSP_Init_Done (2U)
#  endif

#  ifndef SSM_SlaveCore_State_Calibrated
#   define SSM_SlaveCore_State_Calibrated (3U)
#  endif

#  ifndef SSM_SlaveCore_State_AppInitialized
#   define SSM_SlaveCore_State_AppInitialized (4U)
#  endif

#  ifndef SSM_SlaveCore_State_Running
#   define SSM_SlaveCore_State_Running (5U)
#  endif

#  ifndef SSM_SlaveCore_State_MAX
#   define SSM_SlaveCore_State_MAX (6U)
#  endif

#  ifndef SSM_DEGRADEDSTATE_MAX
#   define SSM_DEGRADEDSTATE_MAX (0U)
#  endif

#  ifndef SSM_STATE_BOOTING
#   define SSM_STATE_BOOTING (0U)
#  endif

#  ifndef SSM_STATE_IPCREADY
#   define SSM_STATE_IPCREADY (1U)
#  endif

#  ifndef SSM_STATE_RUNNING
#   define SSM_STATE_RUNNING (2U)
#  endif

#  ifndef SSM_STATE_DEGRADED
#   define SSM_STATE_DEGRADED (3U)
#  endif

#  ifndef SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP
#   define SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP (4U)
#  endif

#  ifndef SSM_STATE_SHUTTINGDOWN_REMOTECORES
#   define SSM_STATE_SHUTTINGDOWN_REMOTECORES (5U)
#  endif

#  ifndef SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE
#   define SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE (6U)
#  endif

#  ifndef SSM_STATE_OFF
#   define SSM_STATE_OFF (7U)
#  endif

#  ifndef SSM_STATE_BOOT_ERROR
#   define SSM_STATE_BOOT_ERROR (8U)
#  endif

#  ifndef SSM_STATE_MAX
#   define SSM_STATE_MAX (9U)
#  endif

# endif /* RTE_CORE */


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
# ifndef RTE_MODETYPE_SSM_SystemState_Mode
#  define RTE_MODETYPE_SSM_SystemState_Mode
typedef uint8 Rte_ModeType_SSM_SystemState_Mode;
# endif

# define RTE_MODE_SSM_Master_SSM_SystemState_Mode_SSM_STATE_BOOTING (0U)
# ifndef RTE_MODE_SSM_SystemState_Mode_SSM_STATE_BOOTING
#  define RTE_MODE_SSM_SystemState_Mode_SSM_STATE_BOOTING (0U)
# endif
# define RTE_MODE_SSM_Master_SSM_SystemState_Mode_SSM_STATE_BOOT_ERROR (1U)
# ifndef RTE_MODE_SSM_SystemState_Mode_SSM_STATE_BOOT_ERROR
#  define RTE_MODE_SSM_SystemState_Mode_SSM_STATE_BOOT_ERROR (1U)
# endif
# define RTE_MODE_SSM_Master_SSM_SystemState_Mode_SSM_STATE_DEGRADED (2U)
# ifndef RTE_MODE_SSM_SystemState_Mode_SSM_STATE_DEGRADED
#  define RTE_MODE_SSM_SystemState_Mode_SSM_STATE_DEGRADED (2U)
# endif
# define RTE_MODE_SSM_Master_SSM_SystemState_Mode_SSM_STATE_IPCREADY (3U)
# ifndef RTE_MODE_SSM_SystemState_Mode_SSM_STATE_IPCREADY
#  define RTE_MODE_SSM_SystemState_Mode_SSM_STATE_IPCREADY (3U)
# endif
# define RTE_MODE_SSM_Master_SSM_SystemState_Mode_SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE (4U)
# ifndef RTE_MODE_SSM_SystemState_Mode_SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE
#  define RTE_MODE_SSM_SystemState_Mode_SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE (4U)
# endif
# define RTE_MODE_SSM_Master_SSM_SystemState_Mode_SSM_STATE_MAX (5U)
# ifndef RTE_MODE_SSM_SystemState_Mode_SSM_STATE_MAX
#  define RTE_MODE_SSM_SystemState_Mode_SSM_STATE_MAX (5U)
# endif
# define RTE_MODE_SSM_Master_SSM_SystemState_Mode_SSM_STATE_OFF (6U)
# ifndef RTE_MODE_SSM_SystemState_Mode_SSM_STATE_OFF
#  define RTE_MODE_SSM_SystemState_Mode_SSM_STATE_OFF (6U)
# endif
# define RTE_MODE_SSM_Master_SSM_SystemState_Mode_SSM_STATE_RUNNING (7U)
# ifndef RTE_MODE_SSM_SystemState_Mode_SSM_STATE_RUNNING
#  define RTE_MODE_SSM_SystemState_Mode_SSM_STATE_RUNNING (7U)
# endif
# define RTE_MODE_SSM_Master_SSM_SystemState_Mode_SSM_STATE_SHUTTINGDOWN_REMOTECORES (8U)
# ifndef RTE_MODE_SSM_SystemState_Mode_SSM_STATE_SHUTTINGDOWN_REMOTECORES
#  define RTE_MODE_SSM_SystemState_Mode_SSM_STATE_SHUTTINGDOWN_REMOTECORES (8U)
# endif
# define RTE_MODE_SSM_Master_SSM_SystemState_Mode_SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP (9U)
# ifndef RTE_MODE_SSM_SystemState_Mode_SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP
#  define RTE_MODE_SSM_SystemState_Mode_SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP (9U)
# endif
# define RTE_TRANSITION_SSM_Master_SSM_SystemState_Mode (10U)
# ifndef RTE_TRANSITION_SSM_SystemState_Mode
#  define RTE_TRANSITION_SSM_SystemState_Mode (10U)
# endif

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SSM_MASTER_TYPE_H */
