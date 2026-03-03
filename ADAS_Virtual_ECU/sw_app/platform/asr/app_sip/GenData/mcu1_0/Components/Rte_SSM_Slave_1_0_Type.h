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
 *             File:  Rte_SSM_Slave_1_0_Type.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application types header file for SW-C <SSM_Slave_1_0>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SSM_SLAVE_1_0_TYPE_H
# define RTE_SSM_SLAVE_1_0_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef ME_Hydra3defs_E_CalibNotStarted
#   define ME_Hydra3defs_E_CalibNotStarted (0U)
#  endif

#  ifndef ME_Hydra3defs_E_CalibPending
#   define ME_Hydra3defs_E_CalibPending (1U)
#  endif

#  ifndef ME_Hydra3defs_E_CalibRunning
#   define ME_Hydra3defs_E_CalibRunning (2U)
#  endif

#  ifndef ME_Hydra3defs_E_CalibCompletedSuccessful
#   define ME_Hydra3defs_E_CalibCompletedSuccessful (3U)
#  endif

#  ifndef ME_Hydra3defs_E_CalibAbortedFailed
#   define ME_Hydra3defs_E_CalibAbortedFailed (4U)
#  endif

#  ifndef CalibrationID_Zero
#   define CalibrationID_Zero (0U)
#  endif

#  ifndef CalibrationID_EOL
#   define CalibrationID_EOL (1U)
#  endif

#  ifndef CalibrationID_SC
#   define CalibrationID_SC (2U)
#  endif

#  ifndef CalibrationID_OC
#   define CalibrationID_OC (3U)
#  endif

#  ifndef CalibrationID_Current
#   define CalibrationID_Current (4U)
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

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SSM_SLAVE_1_0_TYPE_H */
