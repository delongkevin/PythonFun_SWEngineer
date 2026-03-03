/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vRoE.h
 *        \brief  vRoE header file
 *      \details  Implements ResponseOnEvent Lite
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2020-07-29  visvkr  DCM-3150      Initial version
 *  01.00.01  2020-12-01  visvkr  ESCAN00107969 Compiler error: MemMap_Common.h: Wrong pragma command / unknown memory section used.
 *  02.00.00  2021-03-16  visvkr  DCM-4013      SafeBSW for Diag_vRoE_FCA
 *  02.00.01  2021-07-05  visvkr  ESCAN00109431 Cdd_Swc.arxml: Missing trigger for vRoE_MainFunction
 *  03.00.00  2022-02-17  visepp  DCM-4814      Usage of <Ma>_MemMap.h in vRoE
 *  03.00.00  2022-02-18  visepp  ESCAN00111133 Missing const qualifier for global variable vRoE_DefaultActivationState
 *********************************************************************************************************************/

#if !defined (VROE_H)
# define VROE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vRoE_Cfg.h"

# include "Rte_vRoE_Type.h"

# include "Dem_Dcm.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
# define VROE_VENDOR_ID                                              (30u)
# define VROE_MODULE_ID                                              (0xFFu)

/* AUTOSAR Software specification version information */
# define VROE_AR_RELEASE_MAJOR_VERSION                               (4u)
# define VROE_AR_RELEASE_MINOR_VERSION                               (3u)
# define VROE_AR_RELEASE_REVISION_VERSION                            (1u)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define VROE_SW_MAJOR_VERSION                                       (3u)
# define VROE_SW_MINOR_VERSION                                       (0u)
# define VROE_SW_PATCH_VERSION                                       (0u)

/* ----- API service IDs ----- */
# define VROE_SID_GETVERSIONINFO                                     (0x00u) /*!< SID: vRoE_GetVersionInfo()     */
# define VROE_SID_INITMEMORY                                         (0x01u) /*!< SID: vRoE_InitMemory()         */
# define VROE_SID_INIT                                               (0x02u) /*!< SID: vRoE_Init()               */
# define VROE_SID_MAINFUNCTION                                       (0x03u) /*!< SID: vRoE_MainFunction()       */
# define VROE_SID_ONDTCSTATUSCHANGED                                 (0x04u) /*!< SID: vRoE_OnDTCStatusChange()  */
# define VROE_SID_GETACTIVATIONSTATE                                 (0x05u) /*!< SID: vRoE_GetActivationState() */
# define VROE_SID_SETACTIVATIONSTATE                                 (0x06u) /*!< SID: vRoE_SetActivationState() */

/* ----- Error codes ----- */
# define VROE_E_NO_ERROR                                             (0x00u)
# define VROE_E_INTERFACE_RETURN_VALUE                               (0x01u)
# define VROE_E_UNINIT                                               (0x02u)
# define VROE_E_PARAM                                                (0x03u)
# define VROE_E_PARAM_POINTER                                        (0x04u)

/* ----- Modes ----- */
# define VROE_UNINIT                                                 (0x00u)
# define VROE_INIT                                                   (0x01u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
# define VROE_START_SEC_CONST_8
# include "vRoE_MemMap.h"                                                                                                                            /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Default activation state in case that the value cannot be restored from non-volatile memory */
extern CONST(vRoE_ActivationStateType, VROE_CONST) vRoE_DefaultActivationState;

# define VROE_STOP_SEC_CONST_8
# include "vRoE_MemMap.h"                                                                                                                            /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define VROE_START_SEC_VAR_NO_INIT_8
# include "vRoE_MemMap.h"                                                                                                                            /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Activation state that can be read from and written to NvM */
extern VAR(vRoE_ActivationStateType, VROE_VAR_NOINIT) vRoE_ActivationState;

# define VROE_STOP_SEC_VAR_NO_INIT_8
# include "vRoE_MemMap.h"                                                                                                                            /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define VROE_START_SEC_CODE
# include "vRoE_MemMap.h"                                                                                                                            /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if (VROE_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  vRoE_GetVersionInfo()
 *********************************************************************************************************************/
/*! \brief         Reports component's version information.
 *  \details       Returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]    versioninfo    Pointer to where to store the version information. Parameter must not be NULL.
 *  \context       ISR1|ISR2|TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           -
 *  \trace         CREQ-256617
 *********************************************************************************************************************/
FUNC(void, VROE_CODE) vRoE_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, VROE_APPL_DATA) versioninfo
  );
# endif

/**********************************************************************************************************************
 *  vRoE_InitMemory()
 *********************************************************************************************************************/
/*! \brief         Initialization function.
 *  \details       Module's memory initialization.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           Global interrupts shall be disabled. If used, then always prior calling vRoE_Init.
 *  \trace         CREQ-256616
 *********************************************************************************************************************/
FUNC(void, VROE_CODE) vRoE_InitMemory(
  void
  );

/**********************************************************************************************************************
 * vRoE_Init()
 *********************************************************************************************************************/
/*! \brief         Initialization function.
 *  \details       Service to initialize the module vRoE. It initializes all variables and sets the module state to
 *                 initialized.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           Interrupts are disabled.
 *  \pre           Module is uninitialized.
 *  \pre           vRoE_InitMemory() has been called unless vRoE_ModuleInitialized is initialized by start-up code.
 *  \trace         CREQ-256616
 *********************************************************************************************************************/
FUNC(void, VROE_CODE) vRoE_Init(
  void
  );

/**********************************************************************************************************************
 * vRoE_MainFunction()
 *********************************************************************************************************************/
/*! \brief         vRoE cyclic main function.
 *  \details       Cyclic function to serve as entry point to all periodic tasks of vRoE.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VROE_CODE) vRoE_MainFunction(                                                                                                             /* PRQA S 3449, 3451 */ /* MD_vRoE_MultiDecl */
  void
  );

/**********************************************************************************************************************
 * vRoE_OnDTCStatusChange()
 *********************************************************************************************************************/
/*! \brief         Notifies vRoE about the change in the status of a DTC.
 *  \details       This callback has to be configured in DemCallbackDTCStatusChanged.
 *  \param[in]     DTC             DTC for which the status is being reported.
 *  \param[in]     DTCStatusOld    DTC old status.
 *  \param[in]     DTCStatusNew    DTC new status.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VROE_CODE) vRoE_OnDTCStatusChange(
  uint32 DTC,
  Dem_UdsStatusByteType DTCStatusOld,
  Dem_UdsStatusByteType DTCStatusNew
  );

/**********************************************************************************************************************
 * vRoE_GetActivationState()
 *********************************************************************************************************************/
/*! \brief         Returns the current activation state.
 *  \details       -
 *  \param[in]     opStatus    The operation status - Not used.
 *  \param[out]    data        The activation state (VROE_STATE_ENABLED or VROE_STATE_DISABLED).
 *  \return        E_OK        Reading the activation state was successful.
 *  \return        E_NOT_OK    Some error occurred during reading of the activation state.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VROE_CODE) vRoE_GetActivationState(                                                                                             /* PRQA S 3449, 3451 */ /* MD_vRoE_MultiDecl */
  vRoE_OpStatusType opStatus,
  P2VAR(vRoE_ActivationStateType, AUTOMATIC, VROE_APPL_DATA) data
  );

/**********************************************************************************************************************
 * vRoE_SetActivationState()
 *********************************************************************************************************************/
/*! \brief         Sets the activation state.
 *  \details       The activation state is stored into non-volatile memory.
 *  \param[in]     data              The activation state (VROE_STATE_ENABLED or VROE_STATE_DISABLED).
 *  \param[in]     opStatus          The operation status:
 *                                   VROE_E_INITIAL: Signalizes the start of a new operation
 *                                   VROE_E_PENDING: Consecutive call of an ongoing operation
 *                                   VROE_E_CANCEL : Cancel ongoing operation
 *  \param[out]    errorCode         The error code in case that the activation state could not be stored.
 *  \return        E_OK              Writing the activation state was successful.
 *  \return        E_NOT_OK          Some error occurred during writing of the activation state.
 *  \return        VROE_E_PENDING    Final result is pending, retry later.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VROE_CODE) vRoE_SetActivationState(                                                                                             /* PRQA S 3449, 3451 */ /* MD_vRoE_MultiDecl */
  P2CONST(vRoE_ActivationStateType, AUTOMATIC, VROE_APPL_DATA) data,
  vRoE_OpStatusType opStatus,
  P2VAR(vRoE_NegativeResponseCodeType, AUTOMATIC, VROE_APPL_DATA) errorCode
  );

# define VROE_STOP_SEC_CODE
# include "vRoE_MemMap.h"                                                                                                                            /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*!
 * \exclusivearea VROE_EXCLUSIVE_AREA_0
 *                Ensures consistency while modifying global queue variables.
 * \protects      vRoE_Queue, vRoE_QueueContext
 * \usedin        vRoE_MainFunction, vRoE_OnDTCStatusChange, vRoE_SetActivationState
 * \exclude       vRoE_MainFunction, vRoE_OnDTCStatusChange, vRoE_SetActivationState
 * \length        MEDIUM This is the worst case assumption, typically the exclusive area is short.
 * \endexclusivearea
 */

#endif /* VROE_H */

/**********************************************************************************************************************
 *  END OF FILE: vRoE.h
 *********************************************************************************************************************/
