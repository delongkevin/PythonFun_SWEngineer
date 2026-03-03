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
 *         File:  CddFiat.h
 *    Component:  Cdd_Asr4Cdd_Fiat
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This files provides all configuration switches for the component CddFiat.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Martin Nonnenmann             vismno        Vector Informatik GmbH
 *  Marco Pfalzgraf               vismpf        Vector Informatik GmbH
 *  Patrick Kleemann              vispkn        Vector Informatik GmbH
 *  Philipp Seeger                vispps        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2015-11-23  vismno  ESCAN00084861 First Version
 *  01.00.01  2016-02-08  vismpf  ESCAN00088144 Added missing memory sections
 *                                ESCAN00088150 Adapted compiler abstraction
 *                                ESCAN00088172 Added missing compiler abstraction
 *                                ESCAN00088195 Added include of EcuM_Error.h
 *                                ESCAN00088727 Adapted used channel indirection macros
 *  02.00.00  2017-04-25  vispkn  ESCAN00094611 Name Change of SID_BUSOFF_BEGINN
 *                                ESCAN00094879 Correction of if-statement
 *                                ESCAN00094896 Added Comments to Attain MISRA, Doxygen conformity and CREQ Tracing
 *                                ESCAN00094912 "static" Expression changed to LOCAL_INLINE macro
 *  03.00.00  2018-08-06  vispkn  STORYC-6135   Update to MISRA2012
 *  04.00.00  2019-02-15  vispps  STORYC-7711   Provide Process 3.0 CddFiat Component
 *                                STORYC-7634   Finalization of CddFiat CanFd Layout changes
 *********************************************************************************************************************/
#if !defined (CDDFIAT_H)
# define CDDFIAT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "CddFiat_Cfg.h"

# if ( CDDFIAT_NM_CLASS_C_WAKEUP == STD_ON )
#  include "NmFiatC.h"
# endif

# if ( CDDFIAT_NM_OSEK == STD_ON )
#  include "NmOsek.h"
# endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
 
/* Vendor and module identification */
# define CDDFIAT_VENDOR_ID                                       (30u)
# define CDDFIAT_MODULE_ID                                       (255u)

/* AUTOSAR Software specification version information */
# define CDDFIAT_AR_RELEASE_MAJOR_VERSION                        (0x04u)
# define CDDFIAT_AR_RELEASE_MINOR_VERSION                        (0x00u)
# define CDDFIAT_AR_RELEASE_REVISION_VERSION                     (0x03u)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define CDDFIAT_SW_MAJOR_VERSION                                (0x04u)
# define CDDFIAT_SW_MINOR_VERSION                                (0x00u)
# define CDDFIAT_SW_PATCH_VERSION                                (0x00u)

/*---------CddFiat Service Identification--------------------------------------*/
# define CDDFIAT_SID_INIT                                        (0x01u) /* API CddFiat_Init */
# define CDDFIAT_SID_TXCONFIRMATION                              (0x02u) /* API CddFiat_TxConfirmation */
# define CDDFIAT_SID_PRETRANSMIT                                 (0x03u) /* API CddFiat_PreTransmit */
# define CDDFIAT_SID_BUSOFF_BEGIN                                (0x04u) /* API CddFiat_CanSM_BusOffBegin */
# define CDDFIAT_SID_BUSOFF_END                                  (0x05u) /* API CddFiat_CanSM_BusOFFEnd */
# define CDDFIAT_SID_GENERIC_FAIL_STATE_NOTIFICATION             (0x06u) /* API CddFiat_GenericFailStateChangeNotification */
# define CDDFIAT_SID_CURRENT_FAIL_STATE_NOTIFICATION             (0x07u) /* API CddFiat_CurrentFailStateChangeNotification */
# define CDDFIAT_SID_GET_BUS_OFF_STATUS                          (0x08u) /* API CddFiat_GetBusOffStatus */
# define CDDFIAT_SID_GET_EOL_STATUS                              (0x09u) /* API CddFiat_GetEOLStatus */
# define CDDFIAT_SID_GET_FAIL_STATUS                             (0x0Au) /* API CddFiat_GetFailStatus */
# define CDDFIAT_SID_GETVERSIONINFO                              (0x0Bu) /* API CddFiat_GetVersionInfo */
# define CDDFIAT_SID_SET_EOL_STATUS                              (0x0Cu) /* API CddFiat_SetEOLStatus */

/*----------Error Codes in Development-Mode----------------------------------*/
# define CDDFIAT_E_NO_ERROR                                      ((uint8)0xFFu) /*!< used to check if no error occurred - use a value unequal to any error code */
# define CDDFIAT_E_UNINIT                                        ((uint8)0x01u) /*!< Error code: API service used without module initialization */
# define CDDFIAT_E_PARAM_CHANNEL                                 ((uint8)0x02u) /*!< Error code: API service used with invalid channel handle */
# define CDDFIAT_E_PARAM                                         ((uint8)0x03u) /*!< Error code: API service used with invalid parameter */
# define CDDFIAT_E_PARAM_POINTER                                 ((uint8)0x04u) /*!< Error code: API service used with invalid pointer parameter (NULL) */
# define CDDFIAT_E_INIT_FAILED                                   ((uint8)0x05u) /*!< Error code: The service CddFiat_Init() is called while the module is already initialized */

/*Bus Off Values*/
# define CDDFIAT_BUSOFF_OCCURED_MASK_VALUE                       (0x02u)
# define CDDFIAT_BUSOFF_OK_MASK_VALUE                            (0x00u)
# define CDDFIAT_CURRENT_FAIL_STATE_MASK_TRUE                    (0x01u)
# define CDDFIAT_CURRENT_FAIL_STATE_MASK_FALSE                   (0x00u)
# define CDDFIAT_EOL_YES_MASK_VALUE                              (0x01u)
# define CDDFIAT_EOL_NO_MASK_VALUE                               (0x00u)
# define CDDFIAT_GENERIC_FAIL_STATE_MASK_TRUE                    (0x01u)
# define CDDFIAT_GENERIC_FAIL_STATE_MASK_FALSE                   (0x00u)

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
# define CDDFIAT_START_SEC_CONST_8BIT
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*! Indicates CddFiat version. */
extern CONST(uint8, CDDFIAT_CONST) CddFiat_MainVersion;
extern CONST(uint8, CDDFIAT_CONST) CddFiat_SubVersion;
extern CONST(uint8, CDDFIAT_CONST) CddFiat_ReleaseVersion;

# define CDDFIAT_STOP_SEC_CONST_8BIT
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define CDDFIAT_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Service Functions */
/**********************************************************************************************************************
 * CddFiat_Init
 **********************************************************************************************************************/
/*! \brief        Initializes the CddFiat module
 *  \details      All variables are set to default values and initialization state is set to initialized.
 *  \param[in]    configPtr                       Pointer to component configuration structure
 *  \pre          Interrupts are disabled
 *  \pre          Module is uninitialized
 *  \pre          CddFiat_InitMemory has been called
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \trace        CREQ-126208
**********************************************************************************************************************/
extern FUNC(void, CDDFIAT_CODE) CddFiat_Init( CONSTP2CONST( CddFiat_ConfigType, AUTOMATIC, CDDFIAT_INIT_DATA ) configPtr );

/**********************************************************************************************************************
 * CddFiat_InitMemory
 **********************************************************************************************************************/
/*! \brief        Power-up memeory initialization
 *  \details      Sets CddFiat initialization state to uninitialized.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \trace        CREQ-126208
**********************************************************************************************************************/
extern FUNC(void, CDDFIAT_CODE) CddFiat_InitMemory( void );

/**********************************************************************************************************************
 * CddFiat_SetEOLStatus
 **********************************************************************************************************************/
/*! \brief        Sets the EOL status
 *  \details      -
 *  \param[in]    eolStatus                       Parameter providing the desired EOL status.
 *  \return       - E_OK                          Setting the current EOL status was successful
 *                - E_NOT_OK                      Setting the current EOL status has failed due to an invalid parameter
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \trace        CREQ-126210
**********************************************************************************************************************/
extern FUNC(Std_ReturnType, CDDFIAT_CODE) CddFiat_SetEOLStatus( VAR(boolean, AUTOMATIC) eolStatus );

# if(CDDFIAT_NM_CLASS_B == STD_ON)
/**********************************************************************************************************************
 * CddFiat_GetEOLStatus
 **********************************************************************************************************************/
/*! \brief        Returns the current EOL status
 *  \details      -
 *  \param[in]    statePtr                        Reference to a variable in which the current EOL status should be stored in.
 *  \return       - E_OK                          Getting the current EOL status was successful
 *                - E_NOT_OK                      Getting the current EOL status has failed due to an invalid parameter
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \config       CDDFIAT_NM_CLASS_B == STD_ON
 *  \trace        CREQ-129970
**********************************************************************************************************************/
extern FUNC(Std_ReturnType, CDDFIAT_CODE) CddFiat_GetEOLStatus( P2VAR(boolean, AUTOMATIC, CDDFIAT_COM_APPL_DATA) statePtr );

/**********************************************************************************************************************
 * CddFiat_GetFailStatus
 **********************************************************************************************************************/
/*! \brief        Returns the current fail status
 *  \details      -
 *  \param[out]   genericFailStatePtr             Pointer where the generic fail status shall be copied to
 *  \param[out]   currentFailStatePtr             Pointer where the current fail status shall be copied to
 *  \return       - E_OK                          Getting the generic fail status was successful
 *                - E_NOT_OK                      Getting the current fail status has failed due to an invalid parameter
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \config       CDDFIAT_NM_CLASS_B == STD_ON
 *  \trace        CREQ-129971
**********************************************************************************************************************/
extern FUNC(Std_ReturnType, CDDFIAT_CODE) CddFiat_GetFailStatus( P2VAR(boolean, AUTOMATIC, CDDFIAT_COM_APPL_DATA) genericFailStatePtr,
                                                                 P2VAR(boolean, AUTOMATIC, CDDFIAT_COM_APPL_DATA) currentFailStatePtr);
# endif

# if ((CDDFIAT_NM_CLASS_C_WAKEUP == STD_ON) || (CDDFIAT_NM_CLASS_B == STD_ON))
/**********************************************************************************************************************
 * CddFiat_GetBusOffStatus
 **********************************************************************************************************************/
/*! \brief        Returns the current bus off status
 *  \details      -
 *  \param[in]    networkHandle                   System channel handle
 *  \param[out]   statePtr                        Pointer where current bus off status shall be copied to
 *  \return       - E_OK                          Getting the current bus off status was successful
 *                - E_NOT_OK                      Getting the current bus off status has failed due to an invalid parameter
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \config       CDDFIAT_NM_CLASS_C_WAKEUP == STD_ON || CDDFIAT_NM_CLASS_B == STD_ON
 *  \trace        CREQ-129972
**********************************************************************************************************************/
extern FUNC(Std_ReturnType, CDDFIAT_CODE) CddFiat_GetBusOffStatus( VAR( NetworkHandleType, AUTOMATIC ) networkHandle,
                                                                   P2VAR(boolean, AUTOMATIC, CDDFIAT_COM_APPL_DATA) statePtr);
# endif

/**********************************************************************************************************************
 * CddFiat_GenericFailStateChangeNotification
 **********************************************************************************************************************/
/*! \brief        Reports the generic fail state.
 *  \details      -
 *  \param[in]    failState                       Provides information whether fail state is set or not
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \trace        CREQ-126212
**********************************************************************************************************************/
extern FUNC(void, CDDFIAT_CODE) CddFiat_GenericFailStateChangeNotification( boolean failState );

/**********************************************************************************************************************
 * CddFiat_CurrentFailStateChangeNotification
 **********************************************************************************************************************/
/*! \brief        Reports the current fail state.
 *  \details      -
 *  \param[in]    failState                       Provides information whether fail state is set or not
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \trace        CREQ-126211
**********************************************************************************************************************/
extern FUNC(void, CDDFIAT_CODE) CddFiat_CurrentFailStateChangeNotification( boolean failState );

/**********************************************************************************************************************
 * CddFiat_GetVersionInfo
 **********************************************************************************************************************/
/*! \brief        Returns the VersionInfo of the CddFiat Component 
 *  \details      -
 *  \param[in]    Pointer to versionInfo
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \trace        CREQ-126209
**********************************************************************************************************************/
extern FUNC( void, CDDFIAT_CODE ) CddFiat_GetVersionInfo( P2VAR( Std_VersionInfoType, AUTOMATIC, CDDFIAT_APPL_VAR ) versionInfo );

# if ( (CDDFIAT_NM_CLASS_C == STD_ON) || (CDDFIAT_NM_CLASS_C_WAKEUP == STD_ON) || ( CDDFIAT_NM_ASR == STD_ON) )
/* Callback Functions */
/***********************************************************************************************************************
 *  CddFiat_TxConfirmation
 **********************************************************************************************************************/
/*! \brief        Provides the indication that the bus off event was send successfully by the COM
 *  \details      -
 *  \param[in]    networkHandle                   System channel handle
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \config       CDDFIAT_NM_CLASS_C == STD_ON || CDDFIAT_NM_CLASS_C_WAKEUP == STD_ON || CDDFIAT_NM_ASR == STD_ON
 *  \trace        CREQ-126216
 *  \note         This function is called by CddFiat_TxNoti_CddFiat<ChannelName>().
 **********************************************************************************************************************/
extern FUNC(void, CDDFIAT_CODE) CddFiat_TxConfirmation( NetworkHandleType networkHandle );

/***********************************************************************************************************************
 *  CddFiat_PreTransmit
 **********************************************************************************************************************/
/*! \brief        Provides the indication that the message with the involved node events is going to be send
 *  \details      This method provides the indication that the message with the involved node events is going to be send.
 *                Therefore the referenced signal values will be updated to the newest state.
 *  \param[in]    networkHandle                   System channel handle
 *  \param[in]    PduInfoPtr                      Pointer to CAN PDU related data containing DLC and pointer to CAN SDU buffer.
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \config       CDDFIAT_NM_CLASS_C == STD_ON || CDDFIAT_NM_CLASS_C_WAKEUP == STD_ON || CDDFIAT_NM_ASR == STD_ON
 *  \trace        CREQ-126215
 *  \note         This function is called by CddFiat_TxCout_CddFiat<ChannelName>().
 **********************************************************************************************************************/
extern FUNC(boolean, CDDFIAT_CODE) CddFiat_PreTransmit( NetworkHandleType networkHandle, CONSTP2VAR(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr );
# endif

# define CDDFIAT_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*!
 * \exclusivearea CDDFIAT_EXCLUSIVE_AREA_0
 * Protects global variables while modifying data.
 * \protects CddFiat_BusOffStatus, CddFiat_NodeInformation, CddFiat_GenericDemFailStatus_b, CddFiat_CurrentDemFailStatus_b
 *           PduInfoPtr
 * \usedin CddFiat_CanSM_BusOffBegin, CddFiat_GenericFailStateChangeNotification,
 *         CddFiat_CurrentFailStateChangeNotification, CddFiat_TxConfirmation,
 *         CddFiat_PreTransmit, CddFiat_SetEOLStatus
 * \exclude CddFiat_CanSM_BusOffBegin, CddFiat_CanSM_BusOffEnd, CddFiat_GenericFailStateChangeNotification,
 *          CddFiat_CurrentFailStateChangeNotification, CddFiat_SetEOLStatus, CddFiat_TxConfirmation
 * \length LONG This exclusive area covers a call to a BSW sub-function.
 * \endexclusivearea
 */

#endif  /* CDDFIAT_H */

/**********************************************************************************************************************
 *  END OF FILE: CddFiat.h
 *********************************************************************************************************************/
