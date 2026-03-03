/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vRoE.c
 *        \brief  vRoE source file
 *      \details  Implements ResponseOnEvent Lite
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/
#define VROE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vRoE.h"

#include "Rte_vRoE.h"
#include "SchM_vRoE.h"

#if (VROE_DEV_ERROR_DETECT == STD_ON)
# include "Det.h"
#endif
#include "NvM.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Check the version of vRoE header file */
#if (  (VROE_SW_MAJOR_VERSION != (3u)) \
    || (VROE_SW_MINOR_VERSION != (0u)) \
    || (VROE_SW_PATCH_VERSION != (0u)) )
# error "Vendor specific version numbers of vRoE.c and vRoE.h are inconsistent"
#endif

/* Check the version of the configuration header file */
#if (  (VROE_CFG_GEN_MAJOR_VERSION != (3u)) \
    || (VROE_CFG_GEN_MINOR_VERSION != (0u)) \
    || (VROE_CFG_GEN_PATCH_VERSION != (0u)) )
# error "Version numbers of vRoE.c and vRoE_Cfg.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
/*! DTC status bits */
#define VROE_DTC_STATUS_TESTFAILED                                   0x01u
#define VROE_DTC_STATUS_TESTFAILEDTHISOPERATIONCYCLE                 0x02u
#define VROE_DTC_STATUS_PENDINGDTC                                   0x04u
#define VROE_DTC_STATUS_CONFIRMEDDTC                                 0x08u
#define VROE_DTC_STATUS_TESTNOTCOMPLETEDSINCELASTCLEAR               0x10u
#define VROE_DTC_STATUS_TESTFAILEDSINCELASTCLEAR                     0x20u
#define VROE_DTC_STATUS_TESTNOTCOMPLETEDTHISOPERATIONCYCLE           0x40u
#define VROE_DTC_STATUS_WARNINGINDICATORREQUESTED                    0x80u

/*! AR vRoE generic return codes */
#define VROE_E_OK                                                    ((Std_ReturnType)E_OK)     /*!< Successful operation */
#define VROE_E_NOT_OK                                                ((Std_ReturnType)E_NOT_OK) /*!< Failed operation */
#define VROE_E_PENDING                                               ((Std_ReturnType)10)       /*!< Invoked callout needs to be called again */

/*! Optional development error reporting */
#if (VROE_DEV_ERROR_REPORT == STD_ON)
# define vRoE_ReportError(apiId, errId)                              ((void)Det_ReportError(VROE_MODULE_ID, VROE_INSTANCE_ID, (apiId), (errId)))     /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

#if !defined (VROE_LOCAL)
# define VROE_LOCAL                                                  static
#endif

#if !defined (VROE_LOCAL_INLINE)
# define VROE_LOCAL_INLINE                                           LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/*! Functions for entering and leaving of exclusive areas */
#define vRoE_EnterCriticalSection()                                  SchM_Enter_vRoE_VROE_EXCLUSIVE_AREA_0()                                         /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define vRoE_LeaveCriticalSection()                                  SchM_Exit_vRoE_VROE_EXCLUSIVE_AREA_0()                                          /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Retuns the index of the next queue entry while considering a wrap around */
#define vRoe_QueueGetNextIndex(index)                                ((uint8)((index + 1u) % VROE_QUEUE_SIZE))                                       /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*! Structure for storing all relevant information of a RoE event */
struct VROE_QUEUEENTRYTYPE_TAG
{
  uint32                DTC;        /*!< Diagnostic Trouble Code */
  Dem_UdsStatusByteType DTCStatus;  /*!< DTC status */
};
typedef struct VROE_QUEUEENTRYTYPE_TAG vRoE_QueueEntryType;
typedef P2VAR(vRoE_QueueEntryType, TYPEDEF, AUTOMATIC) vRoE_QueueEntryPtrType;
typedef P2CONST(vRoE_QueueEntryType, TYPEDEF, AUTOMATIC) vRoE_QueueEntryConstPtrType;

/*! Structure for storing the state of the RoE Lite queue */
struct VROE_QUEUECONTEXTTYPE_TAG
{
  uint8 IndexRead;   /*!< Index of the next ready for reading or going to be ready for reading slot in the queue */
  uint8 IndexWrite;  /*!< Index of the next free or going to be free slot in the queue */
  uint8 NumEntries;  /*!< Number entries in the queue */
};
typedef struct VROE_QUEUECONTEXTTYPE_TAG vRoE_QueueContextType;

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
#define VROE_START_SEC_VAR_CLEARED_8
#include "vRoE_MemMap.h"                                                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (VROE_DEV_ERROR_DETECT == STD_ON)
/*! Initialization state of the module */
VROE_LOCAL VAR(uint8, VROE_VAR_CLEARED) vRoE_ModuleInitialized = VROE_UNINIT;
#endif

#define VROE_STOP_SEC_VAR_CLEARED_8
#include "vRoE_MemMap.h"                                                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VROE_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "vRoE_MemMap.h"                                                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! RoE Lite queue */
VROE_LOCAL VAR(vRoE_QueueEntryType, VROE_VAR_NOINIT) vRoE_Queue[VROE_QUEUE_SIZE];                                                                    /* PRQA S 3218 */ /* MD_vRoE_3218 */

/*! RoE Lite queue context */
VROE_LOCAL VAR(vRoE_QueueContextType, VROE_VAR_NOINIT) vRoE_QueueContext;

#define VROE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "vRoE_MemMap.h"                                                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
#define VROE_START_SEC_CONST_8
#include "vRoE_MemMap.h"                                                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Default activation state in case that the value cannot be restored from non-volatile memory */
CONST(vRoE_ActivationStateType, VROE_CONST) vRoE_DefaultActivationState = VROE_STATE_ENABLED;

#define VROE_STOP_SEC_CONST_8
#include "vRoE_MemMap.h"                                                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VROE_START_SEC_VAR_NO_INIT_8
#include "vRoE_MemMap.h"                                                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Activation state that can be read from and written to NvM */
VAR(vRoE_ActivationStateType, VROE_VAR_NOINIT) vRoE_ActivationState;

#define VROE_STOP_SEC_VAR_NO_INIT_8
#include "vRoE_MemMap.h"                                                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define VROE_START_SEC_CODE
#include "vRoE_MemMap.h"                                                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vRoE_QueueGetEntry()
 *********************************************************************************************************************/
/*! \brief         Returns a queue entry of the given index.
 *  \details       -
 *  \param[in]     Index to the queued RoE Lite event entry.
 *  \return        The queue entry of the given index
 *  \context       ISR1|ISR2|TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           -
 *********************************************************************************************************************/
VROE_LOCAL_INLINE FUNC(vRoE_QueueEntryPtrType, VROE_CODE) vRoE_QueueGetEntry(
  uint8_least index
  );

/**********************************************************************************************************************
 *  vRoE_QueuePush()
 *********************************************************************************************************************/
/*! \brief         Adds a new element to the end of the queue (FIFO).
 *  \details       -
 *  \param[in]     entry    Pointer to the RoE Lite event entry.
 *  \context       ISR1|ISR2|TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           The element is not already added to the queue (unique DTC).
 *  \trace         DSGN-vRoE22788
 *********************************************************************************************************************/
VROE_LOCAL_INLINE FUNC(void, VROE_CODE) vRoE_QueuePush(
  P2CONST(vRoE_QueueEntryType, AUTOMATIC, AUTOMATIC) entry
  );

/**********************************************************************************************************************
 *  vRoE_QueuePop()
 *********************************************************************************************************************/
/*! \brief         Returns and removes the first element of the queue (FIFO) if available.
 *  \details       -
 *  \param[out]    entry    Pointer to the RoE Lite event entry.
 *  \return        TRUE     An element was found and removed from the queue.
 *  \return        FALSE    The queue was empty.
 *  \context       ISR1|ISR2|TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           -
 *  \trace         DSGN-vRoE22788
 *********************************************************************************************************************/
VROE_LOCAL_INLINE FUNC(boolean, VROE_CODE) vRoE_QueuePop(
  P2VAR(vRoE_QueueEntryType, AUTOMATIC, AUTOMATIC) entry
  );

/**********************************************************************************************************************
 *  vRoE_QueueUpdate()
 *********************************************************************************************************************/
/*! \brief         Updates an RoE Lite event within the queue (FIFO).
 *  \details       Searches for an RoE Lite event with the given DTC and updates its DTC status.
 *  \param[in]     entry    Pointer to the RoE Lite event entry.
 *  \return        TRUE     An element was found and updated.
 *  \return        FALSE    No element was found with the given DTC.
 *  \context       ISR1|ISR2|TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           -
 *  \trace         DSGN-vRoE22788
 *********************************************************************************************************************/
VROE_LOCAL_INLINE FUNC(boolean, VROE_CODE) vRoE_QueueUpdate(
  P2CONST(vRoE_QueueEntryType, AUTOMATIC, AUTOMATIC) entry
  );

/**********************************************************************************************************************
 *  vRoE_QueueClear()
 *********************************************************************************************************************/
/*! \brief         Removes all elements from the queue (FIFO).
 *  \details       -
 *  \context       ISR1|ISR2|TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           -
 *  \trace         DSGN-vRoE22788
 *********************************************************************************************************************/
VROE_LOCAL_INLINE FUNC(void, VROE_CODE) vRoE_QueueClear(
  void
  );

/**********************************************************************************************************************
 *  vRoE_MemoryWriteBlock()
 *********************************************************************************************************************/
/*! \brief         Triggers the writing of the activation state NvM block.
 *  \details       -
 *  \param[in]     data              The activation state (VROE_STATE_ENABLED or VROE_STATE_DISABLED).
 *  \return        E_OK              Writing the activation state was successful.
 *  \return        E_NOT_OK          Some error occurred during writing of the activation state.
 *  \context       ISR1|ISR2|TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 *********************************************************************************************************************/
VROE_LOCAL_INLINE FUNC(Std_ReturnType, VROE_CODE) vRoE_MemoryWriteBlock(
  P2CONST(void, AUTOMATIC, VROE_APPL_DATA) data
  );

/**********************************************************************************************************************
 *  vRoE_MemoryCancelJobs()
 *********************************************************************************************************************/
/*! \brief         Cancels an ongoing NvM operation.
 *  \details       -
 *  \context       ISR1|ISR2|TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 *********************************************************************************************************************/
VROE_LOCAL_INLINE FUNC(void, VROE_CODE) vRoE_MemoryCancelJobs(
  void
  );

/**********************************************************************************************************************
 *  vRoE_MemoryGetErrorStatus()
 *********************************************************************************************************************/
/*! \brief         Polls the current error/status information.
 *  \details       After successful operation the activation state is updated.
 *  \param[in]     data              The activation state (VROE_STATE_ENABLED or VROE_STATE_DISABLED).
 *  \return        E_OK              The error/status information was read successful.
 *  \return        E_NOT_OK          Some error occurred.
 *  \context       ISR1|ISR2|TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 *********************************************************************************************************************/
VROE_LOCAL_INLINE FUNC(Std_ReturnType, VROE_CODE) vRoE_MemoryGetErrorStatus(
  P2CONST(uint8, AUTOMATIC, VROE_APPL_DATA) data
  );

/**********************************************************************************************************************
 *  vRoE_OnActivationStateChange()
 *********************************************************************************************************************/
/*! \brief         Updates the activation state and clears the transmission queue.
 *  \details       -
 *  \param[in]     ActivationStateOld    The old activation state.
 *  \param[in]     ActivationStateNew    The new activation state.
 *  \context       ISR1|ISR2|TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           -
 *********************************************************************************************************************/
VROE_LOCAL_INLINE FUNC(void, VROE_CODE) vRoE_OnActivationStateChange(
  uint8 ActivationStateOld,
  uint8 ActivationStateNew
  );

#define VROE_STOP_SEC_CODE
#include "vRoE_MemMap.h"                                                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
#define VROE_START_SEC_CODE
#include "vRoE_MemMap.h"                                                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vRoE_QueueGetEntry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VROE_LOCAL_INLINE FUNC(vRoE_QueueEntryPtrType, VROE_CODE) vRoE_QueueGetEntry(
  uint8_least index
  )
{
  return &vRoE_Queue[index % VROE_QUEUE_SIZE];                                                                                                       /* VCA_VROE_SATURATED_ACCESS */
}

/**********************************************************************************************************************
 *  vRoE_QueuePush()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
VROE_LOCAL_INLINE FUNC(void, VROE_CODE) vRoE_QueuePush(
  P2CONST(vRoE_QueueEntryType, AUTOMATIC, AUTOMATIC) entry
  )
{
  /* Enter critical section (Reason: Function is reentrant) */
  vRoE_EnterCriticalSection();
  /*=================================*
    BEGIN CRITICAL SECTION
   *=================================*/

  if (vRoE_QueueContext.NumEntries < VROE_QUEUE_SIZE)
  {
    vRoE_QueueEntryPtrType pEntry;

    pEntry = vRoE_QueueGetEntry(vRoE_QueueContext.IndexWrite);

    *pEntry = *entry;                                                                                                                                /* VCA_VROE_POINTER_WRITE_QUEUE_ENTRY */

    vRoE_QueueContext.IndexWrite = vRoe_QueueGetNextIndex(vRoE_QueueContext.IndexWrite);
    vRoE_QueueContext.NumEntries++;
  }

  vRoE_LeaveCriticalSection();
  /*=================================*
    END CRITICAL SECTION
   *=================================*/
  /* Leave critical section */
}

/**********************************************************************************************************************
 *  vRoE_QueuePop()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
VROE_LOCAL_INLINE FUNC(boolean, VROE_CODE) vRoE_QueuePop(
  P2VAR(vRoE_QueueEntryType, AUTOMATIC, AUTOMATIC) entry
  )
{
  boolean lResult = FALSE;

  /* Enter critical section (Reason: Protect against interrupts from vRoE_OnDTCStatusChange()) */
  vRoE_EnterCriticalSection();
  /*=================================*
    BEGIN CRITICAL SECTION
   *=================================*/

  if (vRoE_QueueContext.NumEntries  > 0u)
  {
    vRoE_QueueEntryConstPtrType pEntry;

    pEntry = vRoE_QueueGetEntry(vRoE_QueueContext.IndexRead);

    *entry = *pEntry;
    lResult = TRUE;

    vRoE_QueueContext.IndexRead = vRoe_QueueGetNextIndex(vRoE_QueueContext.IndexRead);
    vRoE_QueueContext.NumEntries--;
  }

  vRoE_LeaveCriticalSection();
  /*=================================*
    END CRITICAL SECTION
   *=================================*/
  /* Leave critical section */

  return lResult;
}

/**********************************************************************************************************************
 *  vRoE_QueueUpdate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
VROE_LOCAL_INLINE FUNC(boolean, VROE_CODE) vRoE_QueueUpdate(
  P2CONST(vRoE_QueueEntryType, AUTOMATIC, AUTOMATIC) entry
  )
{
  boolean lResult = FALSE;

  /* Enter critical section (Reason: Function is reentrant) */
  vRoE_EnterCriticalSection();
  /*=================================*
    BEGIN CRITICAL SECTION
   *=================================*/
  {
    uint8_least lIndex;
    uint8_least lEntriesToProcess;

    lIndex            = vRoE_QueueContext.IndexRead;
    lEntriesToProcess = vRoE_QueueContext.NumEntries;

    while (lEntriesToProcess != 0u)
    {
      vRoE_QueueEntryPtrType pEntry;

      pEntry = vRoE_QueueGetEntry(lIndex);

      if (pEntry->DTC == entry->DTC)
      {
        pEntry->DTCStatus = entry->DTCStatus;                                                                                                        /* VCA_VROE_POINTER_WRITE_QUEUE_ENTRY */
        lResult = TRUE;
        break;
      }

      lIndex = vRoe_QueueGetNextIndex(lIndex);
      lEntriesToProcess--;
    }
  }
  vRoE_LeaveCriticalSection();
  /*=================================*
    END CRITICAL SECTION
   *=================================*/
  /* Leave critical section */

  return lResult;
}

/**********************************************************************************************************************
 *  vRoE_QueueClear()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VROE_LOCAL_INLINE FUNC(void, VROE_CODE) vRoE_QueueClear(
  void
  )
{
  /* Enter critical section (Reason: Protect against interrupts from vRoE_OnDTCStatusChange() and vRoe_MainFunction()) */
  vRoE_EnterCriticalSection();
  /*=================================*
    BEGIN CRITICAL SECTION
   *=================================*/
  {
    vRoE_QueueContext.IndexRead  = 0;
    vRoE_QueueContext.IndexWrite = 0;
    vRoE_QueueContext.NumEntries = 0;
  }
  vRoE_LeaveCriticalSection();
  /*=================================*
    END CRITICAL SECTION
   *=================================*/
  /* Leave critical section */
}

/**********************************************************************************************************************
 *  vRoE_OnActivationStateChange()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VROE_LOCAL_INLINE FUNC(void, VROE_CODE) vRoE_OnActivationStateChange(
  uint8 ActivationStateOld,
  uint8 ActivationStateNew
  )
{
  if ((ActivationStateOld == VROE_STATE_DISABLED) && (ActivationStateNew == VROE_STATE_ENABLED))
  {
    vRoE_QueueClear();
  }

  vRoE_ActivationState = ActivationStateNew;
}

/**********************************************************************************************************************
 *  vRoE_MemoryWriteBlock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VROE_LOCAL_INLINE FUNC(Std_ReturnType, VROE_CODE) vRoE_MemoryWriteBlock(
  P2CONST(void, AUTOMATIC, VROE_APPL_DATA) data
  )
{
  Std_ReturnType lResult;

  lResult = NvM_WriteBlock(VROE_BLOCK_ID, data);                                                                                                     /* VCA_VROE_NVM_ACCESS */

  if (lResult != VROE_E_OK)
  {
    lResult = VROE_E_NOT_OK;
  }

  return lResult;
}

/**********************************************************************************************************************
 *  vRoE_MemoryCancelJobs()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VROE_LOCAL_INLINE FUNC(void, VROE_CODE) vRoE_MemoryCancelJobs(
  void
  )
{
  (void)NvM_CancelJobs(VROE_BLOCK_ID);
}

/**********************************************************************************************************************
 *  vRoE_MemoryGetErrorStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
VROE_LOCAL_INLINE FUNC(Std_ReturnType, VROE_CODE) vRoE_MemoryGetErrorStatus(
  P2CONST(uint8, AUTOMATIC, VROE_APPL_DATA) data
  )
{
  Std_ReturnType        lResult;
  NvM_RequestResultType lStatus;

  lResult = NvM_GetErrorStatus(VROE_BLOCK_ID, &lStatus);                                                                                             /* VCA_VROE_POINTER_FORWARD_STACK */

  if(lResult == VROE_E_OK)
  {
    switch (lStatus)
    {
    case NVM_REQ_OK:
      vRoE_OnActivationStateChange(vRoE_ActivationState, *data);
      break;
    case NVM_REQ_PENDING:
      lResult = VROE_E_PENDING;
      break;
    default:
      lResult = VROE_E_NOT_OK;
      break;
    }
  }
  else
  {
    lResult = VROE_E_NOT_OK;
  }

  return lResult;
}

#define VROE_STOP_SEC_CODE
#include "vRoE_MemMap.h"                                                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
#define VROE_START_SEC_CODE
#include "vRoE_MemMap.h"                                                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (VROE_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  vRoE_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, VROE_CODE) vRoE_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, VROE_APPL_DATA) versioninfo
  )
{
  uint8 lErrorId = VROE_E_NO_ERROR;

# if (VROE_DEV_ERROR_DETECT == STD_ON)
  if(versioninfo == NULL_PTR)
  {
    lErrorId = VROE_E_PARAM_POINTER;
  }
  else
# endif
  {
    versioninfo->vendorID = (uint16)VROE_VENDOR_ID;
    versioninfo->moduleID = (uint16)VROE_MODULE_ID;
    versioninfo->sw_major_version = (uint8)VROE_SW_MAJOR_VERSION;
    versioninfo->sw_minor_version = (uint8)VROE_SW_MINOR_VERSION;
    versioninfo->sw_patch_version = (uint8)VROE_SW_PATCH_VERSION;
  }

# if (VROE_DEV_ERROR_REPORT == STD_ON)
  if (lErrorId != VROE_E_NO_ERROR)
  {
    vRoE_ReportError(VROE_SID_GETVERSIONINFO, lErrorId);
  }
# else
  VROE_DUMMY_STATEMENT(lErrorId);                                                                                                                    /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
# endif
}
#endif

/**********************************************************************************************************************
 *  vRoE_InitMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VROE_CODE) vRoE_InitMemory(
  void
  )
{
#if (VROE_DEV_ERROR_DETECT == STD_ON)
  vRoE_ModuleInitialized = VROE_UNINIT;
#endif
}

/**********************************************************************************************************************
 *  vRoE_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, VROE_CODE) vRoE_Init(
  void
  )
{
  vRoE_QueueClear();

#if (VROE_DEV_ERROR_DETECT == STD_ON)
  vRoE_ModuleInitialized = VROE_INIT;
#endif
}

/***********************************************************************************************************************
 *  vRoE_MainFunction()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, VROE_CODE) vRoE_MainFunction(
  void
  )
{
  uint8 lErrorId = VROE_E_NO_ERROR;

#if (VROE_DEV_ERROR_DETECT == STD_ON)
  if(vRoE_ModuleInitialized == VROE_UNINIT)
  {
    lErrorId = VROE_E_UNINIT;
  }
  else
#endif
  {
    vRoE_QueueEntryType lEntry;

    if (vRoE_ActivationState == VROE_STATE_ENABLED)
    {
      if (vRoE_QueuePop(&lEntry))
      {
        Dem_UdsStatusByteType lDTCStatusMask;

        if (Dem_GetDTCStatusAvailabilityMask(VROE_DEM_CLIENT_ID, &lDTCStatusMask) == E_OK)                                                           /* VCA_VROE_POINTER_FORWARD_STACK */
        {
          uint8 lMessage[8];

          lMessage[0] = 0x07;                      /* PCI */
          lMessage[1] = 0x59;                      /* Pos. Resp. SID of ReadDTCInformation */
          lMessage[2] = 0x0E;                      /* Report Most Recent Confirmed DTC */
          lMessage[3] = lDTCStatusMask;            /* Status availability mask */
          lMessage[4] = (uint8)(lEntry.DTC >> 16); /* High-Byte of DTC */
          lMessage[5] = (uint8)(lEntry.DTC >> 8);  /* Middle-Byte of DTC */
          lMessage[6] = (uint8)(lEntry.DTC);       /* Low-Byte of DTC */
          lMessage[7] = lEntry.DTCStatus;          /* DTC status */

          (void)Rte_Write_vRoE_RoEMessage_Data(&lMessage[0]);                                                                                        /* VCA_VROE_POINTER_FORWARD_STACK */
        }
      }
    }
  }

#if (VROE_DEV_ERROR_REPORT == STD_ON)
  if (lErrorId != VROE_E_NO_ERROR)
  {
    vRoE_ReportError(VROE_SID_MAINFUNCTION, lErrorId);
  }
#else
  VROE_DUMMY_STATEMENT(lErrorId);                                                                                                                    /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif
}

/***********************************************************************************************************************
 *  vRoE_OnDTCStatusChange()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VROE_CODE) vRoE_OnDTCStatusChange(
  uint32 DTC,
  Dem_UdsStatusByteType DTCStatusOld,
  Dem_UdsStatusByteType DTCStatusNew
  )
{
  uint8 lErrorId = VROE_E_NO_ERROR;

#if (VROE_DEV_ERROR_DETECT == STD_ON)
  if(vRoE_ModuleInitialized == VROE_UNINIT)
  {
    lErrorId = VROE_E_UNINIT;
  }
  else
#endif
  {
    if (vRoE_ActivationState == VROE_STATE_ENABLED)
    {
      vRoE_QueueEntryType lEntry;

      lEntry.DTC = DTC;
      lEntry.DTCStatus = DTCStatusNew;

      if (!vRoE_QueueUpdate(&lEntry))
      {
        if ((DTCStatusNew & VROE_DTC_STATUS_TESTNOTCOMPLETEDSINCELASTCLEAR) == 0u)
        {
          if (((DTCStatusOld & VROE_DTC_STATUS_TESTFAILED) != (DTCStatusNew & VROE_DTC_STATUS_TESTFAILED)) ||
            (((DTCStatusOld & VROE_DTC_STATUS_CONFIRMEDDTC) == 0u) &&
            ((DTCStatusNew & VROE_DTC_STATUS_CONFIRMEDDTC) != 0u)))
          {
            vRoE_QueuePush(&lEntry);
          }
        }
      }
    }
  }

#if (VROE_DEV_ERROR_REPORT == STD_ON)
  if (lErrorId != VROE_E_NO_ERROR)
  {
    vRoE_ReportError(VROE_SID_ONDTCSTATUSCHANGED, lErrorId);
  }
#else
  VROE_DUMMY_STATEMENT(lErrorId);                                                                                                                    /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

  return E_OK;
}                                                                                                                                                    /* PRQA S 6080 */ /* MD_MSR_STMIF */

/***********************************************************************************************************************
 *  vRoE_GetActivationState()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, VROE_CODE) vRoE_GetActivationState(
  vRoE_OpStatusType opStatus,
  P2VAR(vRoE_ActivationStateType, AUTOMATIC, VROE_APPL_DATA) data
  )
{
  Std_ReturnType lResult;

  uint8 lErrorId = VROE_E_NO_ERROR;

  VROE_DUMMY_STATEMENT(opStatus);                                                                                                                    /* PRQA S 3112 */ /* MD_MSR_DummyStmt */

#if (VROE_DEV_ERROR_DETECT == STD_ON)
  lResult = VROE_E_NOT_OK;

  if (vRoE_ModuleInitialized == VROE_UNINIT)
  {
    lErrorId = VROE_E_UNINIT;
  }
  else if (data == NULL_PTR)
  {
    lErrorId = VROE_E_PARAM_POINTER;
  }
  else
#endif
  {
    *data = vRoE_ActivationState;
    lResult = VROE_E_OK;
  }

#if (VROE_DEV_ERROR_REPORT == STD_ON)
  if (lErrorId != VROE_E_NO_ERROR)
  {
    vRoE_ReportError(VROE_SID_GETACTIVATIONSTATE, lErrorId);
  }
#else
  VROE_DUMMY_STATEMENT(lErrorId);                                                                                                                    /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

  return lResult;
}

/***********************************************************************************************************************
 *  vRoE_SetActivationState()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VROE_CODE) vRoE_SetActivationState(
  P2CONST(vRoE_ActivationStateType, AUTOMATIC, VROE_APPL_DATA) data,
  vRoE_OpStatusType opStatus,
  P2VAR(vRoE_NegativeResponseCodeType, AUTOMATIC, VROE_APPL_DATA) errorCode
  )
{
  Std_ReturnType lResult;

  uint8 lErrorId = VROE_E_NO_ERROR;

#if (VROE_DEV_ERROR_DETECT == STD_ON)
  lResult = VROE_E_NOT_OK;

  if (vRoE_ModuleInitialized == VROE_UNINIT)
  {
    lErrorId = VROE_E_UNINIT;
  }
  else if ((opStatus != VROE_INITIAL) && (opStatus != VROE_PENDING) && (opStatus != VROE_CANCEL))
  {
    lErrorId = VROE_E_PARAM;
  }
  else if (data == NULL_PTR)
  {
    lErrorId = VROE_E_PARAM_POINTER;
  }
  else if (errorCode == NULL_PTR)
  {
    lErrorId = VROE_E_PARAM_POINTER;
  }
  else
#endif
  {
    if ((*data != VROE_STATE_ENABLED) && (*data != VROE_STATE_DISABLED))
    {
      *errorCode = VROE_E_REQUESTOUTOFRANGE;
      lResult = VROE_E_NOT_OK;
    }
    else
    {
      lResult = VROE_E_OK;

      if (opStatus == VROE_INITIAL)
      {
        lResult = vRoE_MemoryWriteBlock(data);                                                                                                       /* PRQA S 0315 */ /* MD_MSR_Dir1.1 */
      }

      if (lResult == VROE_E_OK)
      {
        if (opStatus == VROE_CANCEL)
        {
          vRoE_MemoryCancelJobs();
        }
        else
        {
          lResult = vRoE_MemoryGetErrorStatus(data);
        }
      }

      if (lResult == VROE_E_NOT_OK)
      {
        *errorCode = VROE_E_CONDITIONSNOTCORRECT;
      }
    }
  }

#if (VROE_DEV_ERROR_REPORT == STD_ON)
  if (lErrorId != VROE_E_NO_ERROR)
  {
    vRoE_ReportError(VROE_SID_SETACTIVATIONSTATE, lErrorId);
  }
#else
  VROE_DUMMY_STATEMENT(lErrorId);                                                                                                                    /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

  return lResult;
}                                                                                                                                                    /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

#define VROE_STOP_SEC_CODE
#include "vRoE_MemMap.h"                                                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA JUSTIFICATIONS
 **********************************************************************************************************************/
/* Justification for module-specific MISRA deviations:

  MD_vRoE_MultiDecl:
    Description: Rule 8.5
                 An external object or function shall be declared in one and only one file.
    Reason:      MICROSAR Rte generates prototypes for callbacks. Some callbacks are also contained in a replacement
                 header in case no Rte is used. This leads to duplicate definitions.
    Risk:        None.
    Prevention:  None.

   MD_vRoE_3218:
     Description: Rule 8.9
                  An object should be defined at block scope if its identifier only appears in a single function.
     Reason:      Vector style guide prevents usage of static variables/constant objects in function scope.
     Risk:        None.
     Prevention:  None.
*/

/**********************************************************************************************************************
 *  SILENTBSW JUSTIFICATIONS
 *********************************************************************************************************************/
/* SBSW_JUSTIFICATION_BEGIN

\ID VCA_VROE_POINTER_FORWARD_STACK
  \DESCRIPTION    A pointer is passed to a function expecting a valid pointer. The called function does not store its
                  pointer parameter(s).
  \COUNTERMEASURE \N The pointer is taken from a local variable, as such it is always valid.

\ID VCA_VROE_SATURATED_ACCESS
  \DESCRIPTION    In an internal function, an element of an array is accessed via an index.
  \COUNTERMEASURE \R [CM_VROE_R_SATURATED_ACCESS]

\ID VCA_VROE_NVM_ACCESS
  \DESCRIPTION    In a function, a pointer to a NvM data structure is passed to a function expecting valid pointers.
  \COUNTERMEASURE \S [CM_VROE_S_NVM_BLOCK_ID_ACCESS]

\ID VCA_VROE_POINTER_WRITE_QUEUE_ENTRY
  \DESCRIPTION    In an internal function, data is written through a pointer to a queue element, or the
                  pointer is passed to a function expecting a valid reference to a queue element.
                  The memory entry pointer is initialized by vRoE_QueueGetEntry() which will always return a
                  pointer to a valid memory entry.
  \COUNTERMEASURE \R [CM_VROE_R_GET_QUEUE_ENTRY]

\CM CM_VROE_R_SATURATED_ACCESS
  The index cannot exceed the size of the array as only the remainder of a division using the size of the array
  is used.

\CM CM_VROE_S_NVM_BLOCK_ID_ACCESS
  The user of MICROSAR Safe shall verify that the NvM Block with the ID defined by VROE_BLOCK_ID located
  in vRoE_Cfg.h is intended to be used exclusively by vRoE.

  The user of MICROSAR Safe shall verify that the NvM Block with the ID defined by VROE_BLOCK_ID located
  in vRoE_Cfg.h has a size equals to the size of the structure data type vRoE_ActivationStateType.

  SMI-668138, SMI-668139

\CM CM_VROE_R_GET_QUEUE_ENTRY
  vRoE_QueueGetEntry() will always return a valid queue element pointer even if the passed memory index is
  not a handle to a queue element.

SBSW_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: vRoE.c
 *********************************************************************************************************************/
