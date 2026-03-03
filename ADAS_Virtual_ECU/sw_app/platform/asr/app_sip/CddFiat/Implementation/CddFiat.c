/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  CddFiat.c
 *    Component:  Cdd_Asr4Cdd_Fiat
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  The purpose of this complex device driver is, do map certain node events to the referenced message
 *
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
#define CDDFIAT_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "CddFiat.h"
#include "CanSM.h"
#include "SchM_CddFiat.h"
#if(CDDFIAT_DEV_ERROR_DETECT == STD_ON)
# include "Det.h"
#endif
#if ( CDDFIAT_USE_INIT_POINTER == STD_ON ) && ( CDDFIAT_USE_ECUM_BSW_ERROR_HOOK == STD_ON )
# include "EcuM_Error.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Check the version of CddFiat header file */
#if (  (CDDFIAT_SW_MAJOR_VERSION != (0x04)) \
    || (CDDFIAT_SW_MINOR_VERSION != (0x00)) \
    || (CDDFIAT_SW_PATCH_VERSION != (0x00)) )
# error "Vendor specific version numbers of CddFiat.c and CddFiat.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

#if !defined (CDDFIAT_LOCAL) /* COV_CDDFIAT_LOCALFUNCTIONS */
# define CDDFIAT_LOCAL static
#endif

/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/
#define CDDFIAT_START_SEC_CONST_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! CddFiat version constants. */
CONST(uint8, CDDFIAT_CONST) CddFiat_MainVersion      = CDDFIAT_SW_MAJOR_VERSION;
CONST(uint8, CDDFIAT_CONST) CddFiat_SubVersion       = CDDFIAT_SW_MINOR_VERSION;
CONST(uint8, CDDFIAT_CONST) CddFiat_ReleaseVersion   = CDDFIAT_SW_PATCH_VERSION;

#define CDDFIAT_STOP_SEC_CONST_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/
#define CDDFIAT_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ( CDDFIAT_USE_INIT_POINTER == STD_ON )
/*! References to the current configuration. */
CDDFIAT_LOCAL P2CONST( CddFiat_ConfigType, CDDFIAT_VAR_ZERO_INIT, CDDFIAT_INIT_DATA) CddFiat_ConfigDataPtr = NULL_PTR;
#endif


#define CDDFIAT_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define CDDFIAT_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if(CDDFIAT_NM_CLASS_B == STD_ON)
/*! Indicates current EOL status. */
CDDFIAT_LOCAL VAR(boolean, CDDFIAT_VAR) CddFiat_EOLStatus_b;
/*! Indicates current Dem fail status. */
CDDFIAT_LOCAL VAR(boolean, CDDFIAT_VAR) CddFiat_CurrentDemFailStatus_b;
/*! Indicates generic Dem fail status. */
CDDFIAT_LOCAL VAR(boolean, CDDFIAT_VAR) CddFiat_GenericDemFailStatus_b;
#endif

#define CDDFIAT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define CDDFIAT_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  CddFiat_CanSM_BusOffBegin
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
 * \trace CREQ-126213
 */
FUNC(void, CDDFIAT_CODE) CddFiat_CanSM_BusOffBegin( NetworkHandleType NetworkHandle, P2VAR(uint8, AUTOMATIC, CDDFIAT_APPL_VAR) OnlineDelayCyclesPtr ) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CDDFIAT_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if ( CDDFIAT_DEV_ERROR_DETECT == STD_ON )
  /* #1 Check if module is initialized. */
  if ( !CddFiat_IsModuleInitialized() )
  {
    errorId = CDDFIAT_E_UNINIT;
  }
  /* #2 Check if parameter 'NetworkHandle' is valid. */
# if ( CDDFIAT_COMMTOLOCALCHANNELIND == STD_ON )
  else if( NetworkHandle >= CddFiat_GetSizeOfComMToLocalChannelInd() )
  {
    errorId = CDDFIAT_E_PARAM_CHANNEL;
  }
  else if( CddFiat_GetComMToLocalChannelInd(NetworkHandle) >= CddFiat_GetSizeOfChannelConfig() )
# else
  else if( NetworkHandle >= CddFiat_GetSizeOfChannelConfig() )
# endif
  {
    errorId = CDDFIAT_E_PARAM_CHANNEL;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
#if ( CDDFIAT_COMMTOLOCALCHANNELIND == STD_ON )
    NetworkHandleType channel = CddFiat_GetComMToLocalChannelInd(NetworkHandle);
#else
    NetworkHandleType channel = NetworkHandle;
#endif

    SchM_Enter_CddFiat_CDDFIAT_EXCLUSIVE_AREA_0();

    /* #3 Set the bus off status depending on the NM active on the channel.
            For Class B, set BusOff status in BusOffStatusVar.
            For ASR, Class C Wakeup and Class C, set BusOff Flag in status message. 
            For Nm Osek, call NmOsek_CanSM_BusOffBegin. */
    switch (CddFiat_GetChannelTypeOfChannelConfig(channel))
    {
#if ( CDDFIAT_NM_CLASS_B == STD_ON )
      case CDDFIAT_CLASS_B_ECU:
        CddFiat_SetBusOffStatusVar(channel, TRUE); /* SBSW_CDDFIAT_CSL_CHANNEL_INDEX_ACCESS */
        break;
#endif

#if ( (CDDFIAT_NM_CLASS_C == STD_ON) || (CDDFIAT_NM_CLASS_C_WAKEUP == STD_ON) || (CDDFIAT_NM_ASR == STD_ON) )
# if ( CDDFIAT_NM_CLASS_C_WAKEUP == STD_ON )
      case CDDFIAT_CLASS_C_WAKEUP_ECU:
        CddFiat_SetBusOffStatusVar(channel, TRUE); /* SBSW_CDDFIAT_CSL_CHANNEL_INDEX_ACCESS */
# endif
# if ( CDDFIAT_NM_ASR == STD_ON )
        /* fall through */
      case CDDFIAT_ASR_ECU:  /* PRQA S 2003 */ /* MD_CDDFIAT_Rule16.3 */
# endif
# if ( CDDFIAT_NM_CLASS_C == STD_ON )
        /* fall through */
      case CDDFIAT_CLASS_C_ECU:  /* PRQA S 2003 */ /* MD_CDDFIAT_Rule16.3 */
# endif
        CddFiat_GetStoreBusOffValueOfChannelConfig(channel)(CDDFIAT_BUSOFF_OCCURED_MASK_VALUE, &CddFiat_GetNodeInformation(channel)); /* SBSW_CDDFIAT_CSL_FCT_PTR_CALL */
        break;
#endif

#if ( CDDFIAT_NM_OSEK == STD_ON )
      case CDDFIAT_OSEKNM_ECU:
        NmOsek_CanSM_BusOffBegin(NetworkHandle, OnlineDelayCyclesPtr); /* SBSW_CDDFIAT_POINTER_PASSED_THROUGH */
        break;
#endif

      default: /* COV_DEFAULT_SWITCH_LABEL X */
        /* The expected COM channel is not handled by the component */
        break;
    }
    SchM_Exit_CddFiat_CDDFIAT_EXCLUSIVE_AREA_0();
  }

  /* ----- Development Error Report --------------------------------------- */
  /* #4 Report error if applicable. */
#if ( CDDFIAT_DEV_ERROR_REPORT == STD_ON )
  if ( errorId != CDDFIAT_E_NO_ERROR )
  {
    (void)Det_ReportError(CDDFIAT_MODULE_ID, CDDFIAT_DEV_ERROR_INSTANCE_ID, CDDFIAT_SID_BUSOFF_BEGIN, errorId);
  }
#else
  CDDFIAT_DUMMY_STATEMENT(errorId); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
#endif

#if ( CDDFIAT_NM_OSEK == STD_OFF )
  CDDFIAT_DUMMY_STATEMENT(OnlineDelayCyclesPtr); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
#endif
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */ /* End of CddFiat_CanSM_BusOffBegin() */


/***********************************************************************************************************************
*  CddFiat_CanSM_BusOffEnd
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 * \trace CREQ-126214
 */
FUNC(void, CDDFIAT_CODE) CddFiat_CanSM_BusOffEnd( NetworkHandleType NetworkHandle )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CDDFIAT_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if ( CDDFIAT_DEV_ERROR_DETECT == STD_ON )
  /* #1 Check if module is initialized. */
  if ( !CddFiat_IsModuleInitialized() )
  {
    errorId = CDDFIAT_E_UNINIT;
  }
  /* #2 Check if parameter 'NetworkHandle' is valid. */
# if ( CDDFIAT_COMMTOLOCALCHANNELIND == STD_ON )
  else if( NetworkHandle >= CddFiat_GetSizeOfComMToLocalChannelInd() )
  {
    errorId = CDDFIAT_E_PARAM_CHANNEL;
  }
  else if( CddFiat_GetComMToLocalChannelInd(NetworkHandle) >= CddFiat_GetSizeOfChannelConfig() )
# else
  else if( NetworkHandle >= CddFiat_GetSizeOfChannelConfig() )
# endif
  {
    errorId = CDDFIAT_E_PARAM_CHANNEL;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
#if( CDDFIAT_COMMTOLOCALCHANNELIND == STD_ON )
    NetworkHandleType channel = CddFiat_GetComMToLocalChannelInd(NetworkHandle);
#else
    NetworkHandleType channel = NetworkHandle;
#endif

#if( (CDDFIAT_NM_CLASS_B == STD_ON) || (CDDFIAT_NM_CLASS_C_WAKEUP == STD_ON) || (CDDFIAT_NM_OSEK == STD_ON) )
    /* #3 Clear or forward bus off status, depending on the active NM. */
# if( (CDDFIAT_NM_CLASS_B == STD_ON) || (CDDFIAT_NM_CLASS_C_WAKEUP == STD_ON) )
    if((CddFiat_GetChannelTypeOfChannelConfig(channel) == (CDDFIAT_CLASS_B_ECU)) ||
        (CddFiat_GetChannelTypeOfChannelConfig(channel) == (CDDFIAT_CLASS_C_WAKEUP_ECU))) /* COV_CERTAIN_CHANNEL_TYPE_NOT_EXISTENT_IN_CONFIG */
    {
      CddFiat_SetBusOffStatusVar(channel, FALSE); /* SBSW_CDDFIAT_CSL_CHANNEL_INDEX_ACCESS */
    }
    else
# endif
    {
# if ( CDDFIAT_NM_OSEK == STD_ON )
      if (CddFiat_GetChannelTypeOfChannelConfig(channel) == CDDFIAT_OSEKNM_ECU) /* COV_CERTAIN_CHANNEL_TYPE_NOT_EXISTENT_IN_CONFIG TX */
      {
        NmOsek_CanSM_BusOffEnd(NetworkHandle);
      }
# endif
    }
#else
    CDDFIAT_DUMMY_STATEMENT( channel ); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
#endif
  }

  /* ----- Development Error Report --------------------------------------- */
  /* #4 Report error if applicable. */
#if ( CDDFIAT_DEV_ERROR_REPORT == STD_ON )
  if ( errorId != CDDFIAT_E_NO_ERROR )
  {
    (void)Det_ReportError(CDDFIAT_MODULE_ID, CDDFIAT_DEV_ERROR_INSTANCE_ID, CDDFIAT_SID_BUSOFF_END, errorId);
  }
#else
  CDDFIAT_DUMMY_STATEMENT(errorId); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
#endif
} /* End of CddFiat_CanSM_BusOffEnd() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */


/***********************************************************************************************************************
*  CddFiat_GenericFailStateChangeNotification
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
 */
FUNC(void, CDDFIAT_CODE) CddFiat_GenericFailStateChangeNotification( boolean failState )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CDDFIAT_E_NO_ERROR;
  uint8 channelIndex;

  /* ----- Development Error Checks ------------------------------------- */
#if ( CDDFIAT_DEV_ERROR_DETECT == STD_ON )
  /* #1 Check if module is initialized. */
  if ( !CddFiat_IsModuleInitialized() )
  {
    errorId = CDDFIAT_E_UNINIT;
  }
  /* #2 Check if parameter 'failState' is valid. */
  else if ( (failState != TRUE) && (failState != FALSE) )
  {
    errorId = CDDFIAT_E_PARAM;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    SchM_Enter_CddFiat_CDDFIAT_EXCLUSIVE_AREA_0();

    /* #3 Store provided fail state status.  */
#if ( CDDFIAT_NM_CLASS_B == STD_ON )
    CddFiat_GenericDemFailStatus_b = failState;
#endif

    /* #4 Iterate over all channels. */
    for ( channelIndex = 0; channelIndex < CddFiat_GetSizeOfChannelConfig(); channelIndex++ )
    {
      /* #41 Update fail state in node information, depending on the active NM. */
      switch (CddFiat_GetChannelTypeOfChannelConfig(channelIndex))
      {
#if ( (CDDFIAT_NM_CLASS_C_WAKEUP == STD_ON) || (CDDFIAT_NM_CLASS_C == STD_ON) || (CDDFIAT_NM_ASR == STD_ON) )
# if ( CDDFIAT_NM_CLASS_C_WAKEUP == STD_ON )
        case CDDFIAT_CLASS_C_WAKEUP_ECU:
          /* Fall through intended. */
# endif
# if ( CDDFIAT_NM_ASR == STD_ON )
        case CDDFIAT_ASR_ECU:
          /* Fall through intended */
# endif
# if ( CDDFIAT_NM_CLASS_C == STD_ON )
        case CDDFIAT_CLASS_C_ECU:
# endif
          if (failState == TRUE)
          {
            CddFiat_GetStoreGenFailStateOfChannelConfig(channelIndex)(CDDFIAT_GENERIC_FAIL_STATE_MASK_TRUE, &CddFiat_GetNodeInformation(channelIndex)); /* SBSW_CDDFIAT_CSL_FCT_PTR_CALL */
          }
          else
          {
            CddFiat_GetStoreGenFailStateOfChannelConfig(channelIndex)(CDDFIAT_GENERIC_FAIL_STATE_MASK_FALSE, &CddFiat_GetNodeInformation(channelIndex)); /* SBSW_CDDFIAT_CSL_FCT_PTR_CALL */
          }
          break;
#endif
        default: /* COV_DEFAULT_SWITCH_LABEL X */
          /* Other variants are not handled in switch. */
          break;
      } /* PRQA S 3315 */ /* MD_CDDFIAT_Rule16.6 */
    }
    SchM_Exit_CddFiat_CDDFIAT_EXCLUSIVE_AREA_0();
  }

  /* ----- Development Error Report --------------------------------------- */
  /* #5 Report error if applicable. */
#if ( CDDFIAT_DEV_ERROR_REPORT == STD_ON )
  if ( errorId != CDDFIAT_E_NO_ERROR )
  {
    (void)Det_ReportError(CDDFIAT_MODULE_ID, CDDFIAT_DEV_ERROR_INSTANCE_ID, CDDFIAT_SID_GENERIC_FAIL_STATE_NOTIFICATION, errorId);
  }
#else
  CDDFIAT_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
} /* End of CddFiat_GenericFailStateChangeNotification() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */


/***********************************************************************************************************************
*  CddFiat_CurrentFailStateChangeNotification
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
 */
FUNC(void, CDDFIAT_CODE) CddFiat_CurrentFailStateChangeNotification( boolean failState )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CDDFIAT_E_NO_ERROR;
  uint8 channelIndex;

  /* ----- Development Error Checks ------------------------------------- */
#if ( CDDFIAT_DEV_ERROR_DETECT == STD_ON )
  /* #1 Check if module is initialized. */
  if ( !CddFiat_IsModuleInitialized() )
  {
    errorId = CDDFIAT_E_UNINIT;
  }
  /* #2 Check if parameter 'failState' is valid. */
  else if ( (failState != TRUE) && (failState != FALSE) )
  {
    errorId = CDDFIAT_E_PARAM;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    SchM_Enter_CddFiat_CDDFIAT_EXCLUSIVE_AREA_0();

    /* #3 Store provided fail state status.  */
#if ( CDDFIAT_NM_CLASS_B == STD_ON )
    CddFiat_CurrentDemFailStatus_b = failState;
#endif

    /* #4 Iterate over all channels. */
    for ( channelIndex = 0; channelIndex < CddFiat_GetSizeOfChannelConfig(); channelIndex++ )
    {
      /* #41 Update fail state in node information, depending on the active NM. */
      switch (CddFiat_GetChannelTypeOfChannelConfig(channelIndex))
      {
#if ( (CDDFIAT_NM_CLASS_C == STD_ON) || (CDDFIAT_NM_CLASS_C_WAKEUP == STD_ON) || (CDDFIAT_NM_ASR == STD_ON) )
# if ( CDDFIAT_NM_CLASS_C_WAKEUP == STD_ON )
        case CDDFIAT_CLASS_C_WAKEUP_ECU:
          /* Fall through intended. */
# endif
#if ( CDDFIAT_NM_ASR == STD_ON )
        case CDDFIAT_ASR_ECU:
          /* Fall through intended. */
#endif
# if ( CDDFIAT_NM_CLASS_C == STD_ON )
        case CDDFIAT_CLASS_C_ECU:
# endif
          if (failState != FALSE)
          {
            CddFiat_GetStoreCurFailStateOfChannelConfig(channelIndex)(CDDFIAT_CURRENT_FAIL_STATE_MASK_TRUE, &CddFiat_GetNodeInformation(channelIndex)); /* SBSW_CDDFIAT_CSL_FCT_PTR_CALL */
          }
          else
          {
            CddFiat_GetStoreCurFailStateOfChannelConfig(channelIndex)(CDDFIAT_CURRENT_FAIL_STATE_MASK_FALSE, &CddFiat_GetNodeInformation(channelIndex)); /* SBSW_CDDFIAT_CSL_FCT_PTR_CALL */
          }
          break;
#endif
        default: /* COV_DEFAULT_SWITCH_LABEL X */
          /* Other variants are not handled in switch. */
          break;
      } /* PRQA S 3315 */ /* MD_CDDFIAT_Rule16.6 */
    }
    SchM_Exit_CddFiat_CDDFIAT_EXCLUSIVE_AREA_0();
  }

  /* ----- Development Error Report --------------------------------------- */
  /* #5 Report error if applicable. */
#if ( CDDFIAT_DEV_ERROR_REPORT == STD_ON )
  if ( errorId != CDDFIAT_E_NO_ERROR )
  {
    (void)Det_ReportError(CDDFIAT_MODULE_ID, CDDFIAT_DEV_ERROR_INSTANCE_ID, CDDFIAT_SID_CURRENT_FAIL_STATE_NOTIFICATION, errorId);
  }
#else
  CDDFIAT_DUMMY_STATEMENT(errorId); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
#endif
} /* End Of CddFiat_CurrentFailStateChangeNotification() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */


/**********************************************************************************************************************
 * CddFiat_Init
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
FUNC(void, CDDFIAT_CODE) CddFiat_Init( CONSTP2CONST( CddFiat_ConfigType, AUTOMATIC, CDDFIAT_INIT_DATA ) configPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  NetworkHandleType channelIndex;
  uint8 errorId = CDDFIAT_E_NO_ERROR;
  uint8 ecumErrorId = CDDFIAT_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if ( CDDFIAT_DEV_ERROR_DETECT == STD_ON )
  /* #1 Check if module is uninitialized. */
  if ( CddFiat_IsModuleInitialized() )
  {
    errorId = CDDFIAT_E_INIT_FAILED;
  }
  else
#endif
#if ( CDDFIAT_USE_INIT_POINTER == STD_ON )
  /* #2 Check if parameter 'configPtr' is valid. */
  if ( configPtr == NULL_PTR )
  {
# if ( CDDFIAT_USE_ECUM_BSW_ERROR_HOOK == STD_ON )
    ecumErrorId = ECUM_BSWERROR_NULLPTR;
# endif
    errorId = CDDFIAT_E_PARAM_POINTER;
  }
  else
#endif
  {
#if ( CDDFIAT_USE_INIT_POINTER == STD_ON )
    /* #3 Store pointer to configuration. */
    CddFiat_ConfigDataPtr = configPtr;
# if ( CDDFIAT_FINALMAGICNUMBER == STD_ON )
    /* #4 Check if FinalMagicNumber is valid. */
    if( CddFiat_GetFinalMagicNumber() != CDDFIAT_FINAL_MAGIC_NUMBER )
    {
      ecumErrorId = ECUM_BSWERROR_MAGICNUMBER;
      errorId = CDDFIAT_E_PARAM_POINTER;
    }
    else
# endif
#endif
    {
      /* ----- Implementation ----------------------------------------------- */
      /* #5 Initialize global and local variables for all channels. */
#if ( CDDFIAT_NM_CLASS_B == STD_ON )
      CddFiat_CurrentDemFailStatus_b = FALSE;
      CddFiat_GenericDemFailStatus_b = FALSE;
      CddFiat_EOLStatus_b = FALSE;
#endif
      for ( channelIndex = 0; channelIndex < CddFiat_GetSizeOfChannelConfig(); channelIndex++ )
      {
        CddFiat_SetNodeInformation(channelIndex, 0u); /* SBSW_CDDFIAT_CSL_CHANNEL_INDEX_ACCESS */
#if ( (CDDFIAT_NM_CLASS_B == STD_ON) || (CDDFIAT_NM_CLASS_C_WAKEUP == STD_ON) )
        CddFiat_SetBusOffStatusVar(channelIndex, FALSE); /* SBSW_CDDFIAT_CSL_CHANNEL_INDEX_ACCESS */
#endif
      }

#if ( CDDFIAT_DEV_ERROR_DETECT == STD_ON )
      /* #6 Set global state of module to initialized. */
      CddFiat_SetModuleInitialized( TRUE ); /* SBSW_CDDFIAT_CSL_POINTER_ACCESS */
#endif
    }
  }

  /* ----- EcuM Error Hook --------------------------------------- */
#if ( CDDFIAT_USE_INIT_POINTER == STD_ON ) && ( CDDFIAT_USE_ECUM_BSW_ERROR_HOOK == STD_ON )
  /* #7 Report EcuM error if applicable. */
  if (ecumErrorId != CDDFIAT_E_NO_ERROR)
  {
    (void)EcuM_BswErrorHook( CDDFIAT_MODULE_ID, ecumErrorId );
  }
#else
  CDDFIAT_DUMMY_STATEMENT( ecumErrorId ); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
#endif

  /* ----- Development Error Report --------------------------------------- */
  /* #8 Report error if applicable. */
#if ( CDDFIAT_DEV_ERROR_REPORT == STD_ON )
  if ( errorId != CDDFIAT_E_NO_ERROR )
  {
    (void)Det_ReportError( CDDFIAT_MODULE_ID, CDDFIAT_DEV_ERROR_INSTANCE_ID, CDDFIAT_SID_INIT, errorId );
  }
#else
  CDDFIAT_DUMMY_STATEMENT( errorId ); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
#endif

#if ( CDDFIAT_USE_INIT_POINTER == STD_OFF )
  CDDFIAT_DUMMY_STATEMENT_CONST( configPtr ); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
#endif
} /* End of CddFiat_Init() */


/**********************************************************************************************************************
 * CddFiat_InitMemory
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, CDDFIAT_CODE) CddFiat_InitMemory( void )
{
#if ( CDDFIAT_DEV_ERROR_DETECT == STD_ON )
  /* #1 Set global module state to uninitialized. */
  CddFiat_SetModuleInitialized( FALSE ); /* SBSW_CDDFIAT_CSL_POINTER_ACCESS */
#endif
#if ( CDDFIAT_USE_INIT_POINTER == STD_ON )
  CddFiat_ConfigDataPtr = NULL_PTR;
#endif
} /* End of CddFiat_InitMemory() */


#if ( (CDDFIAT_NM_CLASS_B == STD_ON) || (CDDFIAT_NM_CLASS_C_WAKEUP == STD_ON) )
/***********************************************************************************************************************
 *  CddFiat_GetBusOffStatus
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CDDFIAT_CODE) CddFiat_GetBusOffStatus( VAR( NetworkHandleType, AUTOMATIC ) networkHandle, P2VAR(boolean, AUTOMATIC, CDDFIAT_COM_APPL_DATA) statePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CDDFIAT_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if ( CDDFIAT_DEV_ERROR_DETECT == STD_ON )
  /* #1 Check if module is initialized. */
  if ( !CddFiat_IsModuleInitialized() )
  {
    errorId = CDDFIAT_E_UNINIT;
  }
  /* #2 Check if parameter 'networkHandle' is valid. */
#  if ( CDDFIAT_COMMTOLOCALCHANNELIND == STD_ON )
  else if( networkHandle >= CddFiat_GetSizeOfComMToLocalChannelInd() )
  {
    errorId = CDDFIAT_E_PARAM_CHANNEL;
  }
  else if( CddFiat_GetComMToLocalChannelInd(networkHandle) >= CddFiat_GetSizeOfChannelConfig() )
#  else
  else if( networkHandle >= CddFiat_GetSizeOfChannelConfig() )
#  endif
  {
    errorId = CDDFIAT_E_PARAM_CHANNEL;
  }
  /* #3 Check if parameter 'statePtr' is valid. */
  else if ( statePtr == NULL_PTR )
  {
    errorId = CDDFIAT_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
# if ( CDDFIAT_COMMTOLOCALCHANNELIND == STD_ON )
    NetworkHandleType channel = CddFiat_GetComMToLocalChannelInd(networkHandle);
# else
    NetworkHandleType channel = networkHandle;
# endif
    /* #4 Store current bus off status to the provided variable. */
    if(    ( CddFiat_GetChannelTypeOfChannelConfig(channel) == CDDFIAT_CLASS_B_ECU ) \
        || ( CddFiat_GetChannelTypeOfChannelConfig(channel) == CDDFIAT_CLASS_C_WAKEUP_ECU )) /* COV_CERTAIN_CHANNEL_TYPE_NOT_EXISTENT_IN_CONFIG */
    {
      *statePtr = (boolean)CddFiat_IsBusOffStatusVar(channel); /* PRQA S 4304 */ /* MD_MSR_AutosarBoolean */ /* SBSW_CDDFIAT_PARAM_POINTER_ACCESS */
    }

    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
  /* #5 Report error if applicable. */
# if ( CDDFIAT_DEV_ERROR_REPORT == STD_ON )
  if ( errorId != CDDFIAT_E_NO_ERROR )
  {
    (void)Det_ReportError(CDDFIAT_MODULE_ID, CDDFIAT_DEV_ERROR_INSTANCE_ID, CDDFIAT_SID_GET_BUS_OFF_STATUS, errorId);
  }
# else
  CDDFIAT_DUMMY_STATEMENT(errorId); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
# endif

  return retVal;
} /* End of CddFiat_GetBusOffStatus() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif


#if ( CDDFIAT_NM_CLASS_B == STD_ON )
/***********************************************************************************************************************
 *  CddFiat_GetEOLStatus
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CDDFIAT_CODE) CddFiat_GetEOLStatus( P2VAR(boolean, AUTOMATIC, CDDFIAT_COM_APPL_DATA) statePtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CDDFIAT_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if ( CDDFIAT_DEV_ERROR_DETECT == STD_ON )
  /* #1 Check if module is initialized. */
  if ( !CddFiat_IsModuleInitialized() )
  {
    errorId = CDDFIAT_E_UNINIT;
  }
  /* #2 Check if parameter 'statePtr' is valid. */
  else if ( statePtr == NULL_PTR )
  {
    errorId = CDDFIAT_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #3 Store current EOL status to the provided variable. */
    *statePtr = CddFiat_EOLStatus_b; /* SBSW_CDDFIAT_PARAM_POINTER_ACCESS */
    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
  /* #4 Report error if applicable. */
# if ( CDDFIAT_DEV_ERROR_REPORT == STD_ON )
  if ( errorId != CDDFIAT_E_NO_ERROR )
  {
    (void)Det_ReportError(CDDFIAT_MODULE_ID, CDDFIAT_DEV_ERROR_INSTANCE_ID, CDDFIAT_SID_GET_EOL_STATUS, errorId);
  }
# else
  CDDFIAT_DUMMY_STATEMENT(errorId); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
# endif

  return retVal;
} /* End of CddFiat_GetEOLStatus() */
#endif


/***********************************************************************************************************************
 *  CddFiat_SetEOLStatus
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
 */
FUNC(Std_ReturnType, CDDFIAT_CODE) CddFiat_SetEOLStatus( VAR(boolean, AUTOMATIC) eolStatus )
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CDDFIAT_E_NO_ERROR;
#if ( (CDDFIAT_NM_CLASS_C == STD_ON) \
   || (CDDFIAT_NM_ASR == STD_ON) \
   || (CDDFIAT_NM_CLASS_C_WAKEUP == STD_ON) )
  NetworkHandleType channelIndex;
#endif
#if ( CDDFIAT_NM_CLASS_B != STD_ON )
  boolean CddFiat_EOLStatus_b;
#endif

  /* ----- Development Error Checks ------------------------------------- */
#if ( CDDFIAT_DEV_ERROR_DETECT == STD_ON )
  /* #1 Check if module is initialized. */
  if ( !CddFiat_IsModuleInitialized() )
  {
    errorId = CDDFIAT_E_UNINIT;
  }
  /* #2 Check if parameter 'eolStatus' is valid. */
  else if ( (eolStatus != TRUE) && (eolStatus != FALSE) )
  {
    errorId = CDDFIAT_E_PARAM;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    SchM_Enter_CddFiat_CDDFIAT_EXCLUSIVE_AREA_0();
    /* #3 Store current EOL status. */
    CddFiat_EOLStatus_b = eolStatus;

    /* #4 Iterate over all channels. */
#if ( (CDDFIAT_NM_CLASS_C == STD_ON) || (CDDFIAT_NM_CLASS_C_WAKEUP == STD_ON) || (CDDFIAT_NM_ASR == STD_ON) )
    /* For ClassC and ASR the EOL status must be written to the NodeInformation for all channels. */
    for ( channelIndex = 0; channelIndex < CddFiat_GetSizeOfChannelConfig(); channelIndex++ )
    {
      /* #41 Update EOL status in node information, depending on the active NM. */
      switch (CddFiat_GetChannelTypeOfChannelConfig(channelIndex))
      {
# if ( CDDFIAT_NM_CLASS_C_WAKEUP == STD_ON )
        case CDDFIAT_CLASS_C_WAKEUP_ECU:
          /* Fall through intended */
# endif
# if ( CDDFIAT_NM_ASR == STD_ON )
        case CDDFIAT_ASR_ECU:
          /* Fall through intended */
# endif
# if ( CDDFIAT_NM_CLASS_C == STD_ON )
        case CDDFIAT_CLASS_C_ECU:
# endif
          if (CddFiat_EOLStatus_b == TRUE)
          {
            CddFiat_GetStoreEOLValueOfChannelConfig(channelIndex)(CDDFIAT_EOL_YES_MASK_VALUE, &CddFiat_GetNodeInformation(channelIndex)); /* SBSW_CDDFIAT_CSL_FCT_PTR_CALL */
          }
          else
          {
            CddFiat_GetStoreEOLValueOfChannelConfig(channelIndex)(CDDFIAT_EOL_NO_MASK_VALUE, &CddFiat_GetNodeInformation(channelIndex)); /* SBSW_CDDFIAT_CSL_FCT_PTR_CALL */
          }
          break;

        default: /* COV_DEFAULT_SWITCH_LABEL X */
          /* Other variants are not handled in switch. */
          break;
      }
    }
#else
    CDDFIAT_DUMMY_STATEMENT(CddFiat_EOLStatus_b); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
#endif
    SchM_Exit_CddFiat_CDDFIAT_EXCLUSIVE_AREA_0();
    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
  /* #5 Report error if applicable. */
#if ( CDDFIAT_DEV_ERROR_REPORT == STD_ON )
  if ( errorId != CDDFIAT_E_NO_ERROR )
  {
    (void)Det_ReportError(CDDFIAT_MODULE_ID, CDDFIAT_DEV_ERROR_INSTANCE_ID, CDDFIAT_SID_SET_EOL_STATUS, errorId);
  }
#else
  CDDFIAT_DUMMY_STATEMENT(errorId); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
#endif

  return retVal;
} /* End of CddFiat_SetEOLStatus() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */


#if ( CDDFIAT_NM_CLASS_B == STD_ON )
/***********************************************************************************************************************
 *  CddFiat_GetFailStatus
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CDDFIAT_CODE) CddFiat_GetFailStatus( P2VAR(boolean, AUTOMATIC, CDDFIAT_COM_APPL_DATA) genericFailStatePtr,
                                                          P2VAR(boolean, AUTOMATIC, CDDFIAT_COM_APPL_DATA) currentFailStatePtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CDDFIAT_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if ( CDDFIAT_DEV_ERROR_DETECT == STD_ON )
  /* #1 Check if module is initialized. */
  if ( !CddFiat_IsModuleInitialized() )
  {
    errorId = CDDFIAT_E_UNINIT;
  }
  /* #2 Check if parameter 'genericFailStatePtr' is valid. */
  else if ( genericFailStatePtr == NULL_PTR )
  {
    errorId = CDDFIAT_E_PARAM_POINTER;
  }
  /* #3 Check if parameter 'currentFailStatePtr' is valid. */
  else if ( currentFailStatePtr == NULL_PTR )
  {
    errorId = CDDFIAT_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #4 Store current fail state to the provided variable. */
    *currentFailStatePtr = CddFiat_CurrentDemFailStatus_b; /* SBSW_CDDFIAT_PARAM_POINTER_ACCESS */
    *genericFailStatePtr = CddFiat_GenericDemFailStatus_b; /* SBSW_CDDFIAT_PARAM_POINTER_ACCESS */

    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
  /* #5 Report error if applicable. */
# if ( CDDFIAT_DEV_ERROR_REPORT == STD_ON )
  if ( errorId != CDDFIAT_E_NO_ERROR )
  {
    (void)Det_ReportError(CDDFIAT_MODULE_ID, CDDFIAT_DEV_ERROR_INSTANCE_ID, CDDFIAT_SID_GET_FAIL_STATUS, errorId);
  }
# else
  CDDFIAT_DUMMY_STATEMENT(errorId); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif

  return retVal;
} /* End of CddFiat_GetFailStatus() */
#endif


#if ( CDDFIAT_VERSION_INFO_API == STD_ON )
/**********************************************************************************************************************
 * CddFiat_GetVersionInfo()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC( void, CDDFIAT_CODE ) CddFiat_GetVersionInfo( P2VAR( Std_VersionInfoType, AUTOMATIC, CDDFIAT_APPL_VAR ) versionInfo )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CDDFIAT_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if ( CDDFIAT_DEV_ERROR_DETECT == STD_ON )
  /* #1 Check if parameter 'versionInfo' is not NULL. */
  if ( versionInfo == NULL_PTR )
  {
    errorId = CDDFIAT_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #2 Read out vendor ID, module ID and version data. */
    versionInfo->vendorID   = CDDFIAT_VENDOR_ID; /* SBSW_CDDFIAT_PARAM_POINTER_ACCESS */
    versionInfo->moduleID   = CDDFIAT_MODULE_ID; /* SBSW_CDDFIAT_PARAM_POINTER_ACCESS */
    versionInfo->sw_major_version = CDDFIAT_SW_MAJOR_VERSION; /* SBSW_CDDFIAT_PARAM_POINTER_ACCESS */
    versionInfo->sw_minor_version = CDDFIAT_SW_MINOR_VERSION; /* SBSW_CDDFIAT_PARAM_POINTER_ACCESS */
    versionInfo->sw_patch_version = CDDFIAT_SW_PATCH_VERSION; /* SBSW_CDDFIAT_PARAM_POINTER_ACCESS */
  }
  /* ----- Development Error Report --------------------------------------- */
  /* #3 Report error if applicable. */
# if ( CDDFIAT_DEV_ERROR_REPORT == STD_ON )
  if (errorId != CDDFIAT_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDFIAT_MODULE_ID, CDDFIAT_DEV_ERROR_INSTANCE_ID, CDDFIAT_SID_GETVERSIONINFO, errorId);
  }
# else
  CDDFIAT_DUMMY_STATEMENT(errorId); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif
}
#endif /* #if ( CDDFIAT_VERSION_INFO_API == STD_ON ) */


#if ( (CDDFIAT_NM_CLASS_C == STD_ON) || (CDDFIAT_NM_CLASS_C_WAKEUP == STD_ON) || ( CDDFIAT_NM_ASR == STD_ON) )
/***********************************************************************************************************************
*  CddFiat_TxConfirmation
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, CDDFIAT_CODE) CddFiat_TxConfirmation( NetworkHandleType networkHandle )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CDDFIAT_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if ( CDDFIAT_DEV_ERROR_DETECT == STD_ON )
  /* #1 Check if module is initialized. */
  if ( !CddFiat_IsModuleInitialized() )
  {
    errorId = CDDFIAT_E_UNINIT;
  }
  /* #2 Check if parameter 'networkHandle' is valid. */
#  if ( CDDFIAT_COMMTOLOCALCHANNELIND == STD_ON )
  else if( networkHandle >= CddFiat_GetSizeOfComMToLocalChannelInd() )
  {
    errorId = CDDFIAT_E_PARAM_CHANNEL;
  }
  else if( CddFiat_GetComMToLocalChannelInd(networkHandle) >= CddFiat_GetSizeOfChannelConfig() )
#  else
  else if( networkHandle >= CddFiat_GetSizeOfChannelConfig() )
#  endif
  {
    errorId = CDDFIAT_E_PARAM_CHANNEL;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
# if ( CDDFIAT_COMMTOLOCALCHANNELIND == STD_ON )
    NetworkHandleType channel = CddFiat_GetComMToLocalChannelInd(networkHandle);
# else
    NetworkHandleType channel = networkHandle;
# endif

    /* #3 Set the bus off value back to OK because the event was sent, depending on the active NM. */
    SchM_Enter_CddFiat_CDDFIAT_EXCLUSIVE_AREA_0();
    switch (CddFiat_GetChannelTypeOfChannelConfig(channel))
    {
# if ( CDDFIAT_NM_ASR == STD_ON )
      case CDDFIAT_ASR_ECU:
        /* Fall through intended. */
# endif
# if (CDDFIAT_NM_CLASS_C_WAKEUP == STD_ON)
      case CDDFIAT_CLASS_C_WAKEUP_ECU:
        /* Fall through intended. */
# endif
# if ( CDDFIAT_NM_CLASS_C == STD_ON )
      case CDDFIAT_CLASS_C_ECU:
# endif
        CddFiat_GetStoreBusOffValueOfChannelConfig(channel)(CDDFIAT_BUSOFF_OK_MASK_VALUE, &CddFiat_GetNodeInformation(channel)); /* SBSW_CDDFIAT_CSL_FCT_PTR_CALL */

        break;

      default: /* COV_DEFAULT_SWITCH_LABEL X */
        /* Other variants are not handled in switch. */
        break;
    }
    SchM_Exit_CddFiat_CDDFIAT_EXCLUSIVE_AREA_0();
  }

  /* ----- Development Error Report --------------------------------------- */
  /* #4 Report error if applicable. */
# if ( CDDFIAT_DEV_ERROR_REPORT == STD_ON )
  if ( errorId != CDDFIAT_E_NO_ERROR )
  {
    (void)Det_ReportError(CDDFIAT_MODULE_ID, CDDFIAT_DEV_ERROR_INSTANCE_ID, CDDFIAT_SID_TXCONFIRMATION, errorId);
  }
# else
  CDDFIAT_DUMMY_STATEMENT(errorId); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif
}


/***********************************************************************************************************************
 *  CddFiat_PreTransmit
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(boolean, CDDFIAT_CODE) CddFiat_PreTransmit( NetworkHandleType networkHandle, CONSTP2VAR(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CDDFIAT_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if ( CDDFIAT_DEV_ERROR_DETECT == STD_ON )
  /* #1 Check if module is initialized. */
  if ( !CddFiat_IsModuleInitialized() )
  {
    errorId = CDDFIAT_E_UNINIT;
  }
  /* #2 Check if parameter 'networkHandle' is valid. */
#  if ( CDDFIAT_COMMTOLOCALCHANNELIND == STD_ON )
  else if( networkHandle >= CddFiat_GetSizeOfComMToLocalChannelInd() )
  {
    errorId = CDDFIAT_E_PARAM_CHANNEL;
  }
  else if( CddFiat_GetComMToLocalChannelInd(networkHandle) >= CddFiat_GetSizeOfChannelConfig() )
#  else
  else if( networkHandle >= CddFiat_GetSizeOfChannelConfig() )
#  endif
  {
    errorId = CDDFIAT_E_PARAM_CHANNEL;
  }
  /* #3 Check if parameter 'PduInfoPtr' is valid. */
  else if ( PduInfoPtr == NULL_PTR )
  {
    errorId = CDDFIAT_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
# if ( CDDFIAT_COMMTOLOCALCHANNELIND == STD_ON )
    NetworkHandleType channel = CddFiat_GetComMToLocalChannelInd(networkHandle);
# else
    NetworkHandleType channel = networkHandle;
# endif
    /* #4 Update the node event message depending on the active NM. */
    SchM_Enter_CddFiat_CDDFIAT_EXCLUSIVE_AREA_0();

    switch( CddFiat_GetChannelTypeOfChannelConfig(channel) )
    {
# if ( CDDFIAT_NM_CLASS_C_WAKEUP == STD_ON )
      case CDDFIAT_CLASS_C_WAKEUP_ECU:
        /* Fall through intended. */
# endif
# if ( CDDFIAT_NM_ASR == STD_ON )
      case CDDFIAT_ASR_ECU:
        /* Fall through intended. */
# endif
# if ( CDDFIAT_NM_CLASS_C == STD_ON )
      case CDDFIAT_CLASS_C_ECU:
# endif
        CddFiat_GetStoreMaskInAllSignalsOfChannelConfig(channel)(CddFiat_GetNodeInformation(channel), &(PduInfoPtr->SduDataPtr[0])); /* SBSW_CDDFIAT_CSL_FCT_PTR_CALL */
        break;

      default: /* COV_DEFAULT_SWITCH_LABEL X */
        /* Other variants are not handled in switch. */
        break;
    }
    SchM_Exit_CddFiat_CDDFIAT_EXCLUSIVE_AREA_0();

    retVal = TRUE;
  }

  /* ----- Development Error Report --------------------------------------- */
  /* #5 Report error if applicable. */
# if ( CDDFIAT_DEV_ERROR_REPORT == STD_ON )
  if ( errorId != CDDFIAT_E_NO_ERROR )
  {
    (void)Det_ReportError(CDDFIAT_MODULE_ID, CDDFIAT_DEV_ERROR_INSTANCE_ID, CDDFIAT_SID_PRETRANSMIT, errorId);
  }
# else
  CDDFIAT_DUMMY_STATEMENT(errorId); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif


#define CDDFIAT_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* module specific MISRA deviations:

  MD_CDDFIAT_Rule16.3:
    Reason:     Fall through used for code optimizations.
    Risk:       There is a risk that a fall through is overseen by a code review and lead to unexpected results.
    Prevention: Fall through is marked with explicit comments to draw attention to it when code review is performed.

  MD_CDDFIAT_Rule16.6:
    Reason:     In configurations with only Class B or NmOsek network variant, the switch statement always results in the default case.
    Risk:       No functional risk.
    Prevention: Covered by code review.

*/

/* COV_JUSTIFICATION_BEGIN

\ID COV_CDDFIAT_LOCALFUNCTIONS
   \ACCEPT TX
   \REASON Define wrapper usually ends up with same result.

\ID COV_DEFAULT_SWITCH_LABEL
   \REASON In each configuration there is always a certain channel type activated. Thus the default-switch label is
           never active.

\ID COV_CERTAIN_CHANNEL_TYPE_NOT_EXISTENT_IN_CONFIG
   \ACCEPT TX xf tx
   \ACCEPT TX tf tx
   \ACCEPT TX tx xx
   \ACCEPT TF xf tf
   \ACCEPT TF tf xf
   \REASON There are configurations where certain channel types do not exist and thus the comparison can not be covered
           completely.

   COV_JUSTIFICATION_END */

/* SBSW_JUSTIFICATION_BEGIN

\ID                SBSW_CDDFIAT_CSL_CHANNEL_INDEX_ACCESS
\DESCRIPTION       Access of CddFiat_BusOffStatusVara and CddFiat_NodeInformation via indirection 
                   over ChannelConfig structure. The 'channel' variable which is used as index is always checked.
\COUNTERMEASURE \N Qualified use-case CSL02 of ComStackLib.

\ID                SBSW_CDDFIAT_CSL_POINTER_ACCESS
\DESCRIPTION       A ComStackLib generated variable is accessed.
\COUNTERMEASURE \N The variable is written using a generated macro of the CSL. It immediately dereferences the variables
                   address without pointer arithmetic.

\ID                SBSW_CDDFIAT_PARAM_POINTER_ACCESS
\DESCRIPTION       The functions CddFiat_GetBusOffStatus, CddFiat_GetEOLStatus, CddFiat_GetVersionInfo and CddFiat_GetFailStatus
                   write to the object referenced by parameter 'statePtr', 'versionInfo', 'currentFailStatePtr',
                   'genericFailStatePtr'.
\COUNTERMEASURE \N The caller of this function must ensure that the pointer passed to the parameter 'statePtr', 'versionInfo',
                   'currentFailStatePtr' and 'genericFailStatePtr' references a valid memory location.

\ID                SBSW_CDDFIAT_POINTER_PASSED_THROUGH
\DESCRIPTION       The Pointer parameter 'OnlineDelayCyclesPtr' is passed to the function NmOsek_CanSM_BusOffBegin.
\COUNTERMEASURE \N The pointer is not used to access any memory address but only passed through.
                   Thus the Parameter 'OnlineDelayCyclePtr' is ignored by CddFiat.

\ID                SBSW_CDDFIAT_FUNCTION_CALL_PARAM_POINTER
\DESCRIPTION       The function CddFiat_PreTransmit is called with the parameter 'PduInfoPtr'.
\COUNTERMEASURE \N The caller of this function must verify that the pointer passed to the parameter 'PduInfoPtr'
                   references a valid memory location.

\ID                SBSW_CDDFIAT_CSL_FCT_PTR_CALL
\DESCRIPTION       The function referenced by the function pointer is called with the given arguments.
\COUNTERMEASURE \S The correct referenced function called by the function pointer is generated and verified by the CSL.
                   [SMI-8]

\ID                SBSW_CDDFIAT_NODEINFO_PTR_ACCESS
\DESCRIPTION       The function is only called with the pointer parameter '&CddFiat_GetNodeInformation(channel)' and writes to
                   the corresponding memory location.
\COUNTERMEASURE \N Access of NodeInformation via indirection over ChannelConfig structure. Thus, the size of
                   NodeInformation is verified by the CSL.
                   The 'channel' variable which is used as index is always checked during runtime.

   SBSW_JUSTIFICATION_END */

/**********************************************************************************************************************
*  END OF FILE: CddFiat.c
*********************************************************************************************************************/
