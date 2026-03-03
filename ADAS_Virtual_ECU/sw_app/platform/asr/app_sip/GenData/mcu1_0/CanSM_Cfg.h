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
 *            Module: CanSM
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanSM_Cfg.h
 *   Generation Time: 2024-02-13 13:07:48
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined (CANSM_CFG_H)
# define CANSM_CFG_H

 /**********************************************************************************************************************
 *  Includes
 **********************************************************************************************************************/

#include "CanSM_Int.h"



 /**********************************************************************************************************************
 *  Precompile Definitions
 **********************************************************************************************************************/


#define CANSM_VERSION_INFO_API                STD_OFF

#define CANSM_BOR_CHECK_LEVEL                 STD_OFF
#define CANSM_BUSOFF_BEGIN_INDICATION         STD_ON
#define CANSM_BUSOFF_END_INDICATION           STD_ON
#define CANSM_CHANGE_BAUDRATE_API             STD_OFF
#define CANSM_SET_BAUDRATE_API                STD_OFF
#define CANSM_ECU_PASSIVE_MODE                STD_OFF
#define CANSM_PREVENT_BUSSLEEP_AT_STARTUP     STD_ON
#define CANSM_SWIFT_TX_TIMEOUT_RECOVERY       STD_OFF
#define CANSM_EXPANDED_TX_TIMEOUT_RECOVERY    STD_OFF
#define CANSM_EXTENDED_RAM_CHECK              STD_OFF

/* General Module Defines */
#ifndef CANSM_DEV_ERROR_DETECT
#define CANSM_DEV_ERROR_DETECT STD_ON
#endif
#ifndef CANSM_DEV_ERROR_REPORT
#define CANSM_DEV_ERROR_REPORT STD_ON
#endif
#ifndef CANSM_USE_DUMMY_STATEMENT
#define CANSM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANSM_DUMMY_STATEMENT
#define CANSM_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANSM_DUMMY_STATEMENT_CONST
#define CANSM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANSM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CANSM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_ON /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CANSM_ATOMIC_VARIABLE_ACCESS
#define CANSM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CANSM_PROCESSOR_TDA4VE88
#define CANSM_PROCESSOR_TDA4VE88
#endif
#ifndef CANSM_COMP_LLVMTEXASINSTRUMENTS
#define CANSM_COMP_LLVMTEXASINSTRUMENTS
#endif
#ifndef CANSM_GEN_GENERATOR_MSR
#define CANSM_GEN_GENERATOR_MSR
#endif
#ifndef CANSM_CPUTYPE_BITORDER_LSB2MSB
#define CANSM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CANSM_CONFIGURATION_VARIANT_PRECOMPILE
#define CANSM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CANSM_CONFIGURATION_VARIANT_LINKTIME
#define CANSM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CANSM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CANSM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CANSM_CONFIGURATION_VARIANT
#define CANSM_CONFIGURATION_VARIANT CANSM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CANSM_POSTBUILD_VARIANT_SUPPORT
#define CANSM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif



#define CANSM_ENABLE_SET_BUS_SLEEP_ARRAY_MAX_SIZE                     2u


 /* \trace SPEC-634 */


# define  CanSM_Dem_ReportErrorEvent(Index, eventStatus )


/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanSMPCGetRootDataMacros  CanSM Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define CanSM_GetFinalMagicNumberOfPCConfig()                                                         /**< Deactivateable: 'CanSM_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CanSM_GetInitDataHashCodeOfPCConfig()                                                         /**< Deactivateable: 'CanSM_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCGetConstantDuplicatedRootDataMacros  CanSM Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define CanSM_GetChannelConfigOfPCConfig()                                                          CanSM_ChannelConfig  /**< the pointer to CanSM_ChannelConfig */
#define CanSM_GetChannelVarRecordOfPCConfig()                                                       CanSM_ChannelVarRecord  /**< the pointer to CanSM_ChannelVarRecord */
#define CanSM_GetModeRequestRepetitionMaxOfPCConfig()                                               10u  /**< getCanSMModeRequestRepetitionMax */
#define CanSM_GetModeRequestRepetitionTimeOfPCConfig()                                              10u  /**< periond of ModeRequest Repetition */
#define CanSM_GetSizeOfChannelConfigOfPCConfig()                                                    2u  /**< the number of accomplishable value elements in CanSM_ChannelConfig */
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCGetDuplicatedRootDataMacros  CanSM Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define CanSM_GetSizeOfChannelVarRecordOfPCConfig()                                                 CanSM_GetSizeOfChannelConfigOfPCConfig()  /**< the number of accomplishable value elements in CanSM_ChannelVarRecord */
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCGetDataMacros  CanSM Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define CanSM_IsBor_Tx_Confirmation_PollingOfChannelConfig(Index)                                     /**< Deactivateable: 'CanSM_ChannelConfig.Bor_Tx_Confirmation_Polling' Reason: 'the value of CanSM_Bor_Tx_Confirmation_PollingOfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CanSM_GetNetworkHandleOfChannelConfig(Index)                                                (CanSM_GetChannelConfigOfPCConfig()[(Index)].NetworkHandleOfChannelConfig)
#define CanSM_IsPartial_Network_Trcv_SupportOfChannelConfig(Index)                                    /**< Deactivateable: 'CanSM_ChannelConfig.Partial_Network_Trcv_Support' Reason: 'the value of CanSM_Partial_Network_Trcv_SupportOfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CanSM_IsPartial_Network_Wakeup_FilterOfChannelConfig(Index)                                   /**< Deactivateable: 'CanSM_ChannelConfig.Partial_Network_Wakeup_Filter' Reason: 'the value of CanSM_Partial_Network_Wakeup_FilterOfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CanSM_IsProdErrorDetect_BusOff_OfChannelConfig(Index)                                         /**< Deactivateable: 'CanSM_ChannelConfig.ProdErrorDetect_BusOff_' Reason: 'the value of CanSM_ProdErrorDetect_BusOff_OfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CanSM_IsProdErrorDetect_ModeRequest_OfChannelConfig(Index)                                    /**< Deactivateable: 'CanSM_ChannelConfig.ProdErrorDetect_ModeRequest_' Reason: 'the value of CanSM_ProdErrorDetect_ModeRequest_OfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CanSM_GetTransceiverIdOfChannelConfig(Index)                                                (CanSM_GetChannelConfigOfPCConfig()[(Index)].TransceiverIdOfChannelConfig)
#define CanSM_IsTrcv_InActive_AtAll_NonPNCannelsOfChannelConfig(Index)                              ((CanSM_GetChannelConfigOfPCConfig()[(Index)].Trcv_InActive_AtAll_NonPNCannelsOfChannelConfig) != FALSE)
#define CanSM_GetChannelVarRecord(Index)                                                            (CanSM_GetChannelVarRecordOfPCConfig()[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCGetDeduplicatedDataMacros  CanSM Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define CanSM_GetBorCounterL1ToL2OfChannelConfig(Index)                                             5u
#define CanSM_GetBorTimeL1OfChannelConfig(Index)                                                    100u
#define CanSM_GetBorTimeL2OfChannelConfig(Index)                                                    300u
#define CanSM_GetBorTimeTxEnsuredOfChannelConfig(Index)                                             500u
#define CanSM_GetControllerIdOfChannelConfig(Index)                                                 ((CanSM_ControllerIdOfChannelConfigType)((Index)))
#define CanSM_GetDemEventId_BusOff_OfChannelConfig(Index)                                           0xFFu
#define CanSM_GetDemEventId_ModeRequest_OfChannelConfig(Index)                                      0xFFu
#define CanSM_IsTransceiver_Channel_SupportOfChannelConfig(Index)                                   (((!(CanSM_IsTrcv_InActive_AtAll_NonPNCannelsOfChannelConfig(Index)))) != FALSE)
#define CanSM_GetFinalMagicNumber()                                                                   /**< Deactivateable: 'CanSM_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CanSM_GetInitDataHashCode()                                                                   /**< Deactivateable: 'CanSM_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CanSM_GetModeRequestRepetitionMax()                                                         CanSM_GetModeRequestRepetitionMaxOfPCConfig()
#define CanSM_GetModeRequestRepetitionTime()                                                        CanSM_GetModeRequestRepetitionTimeOfPCConfig()
#define CanSM_GetSizeOfChannelConfig()                                                              CanSM_GetSizeOfChannelConfigOfPCConfig()
#define CanSM_GetSizeOfChannelVarRecord()                                                           CanSM_GetSizeOfChannelVarRecordOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCSetDataMacros  CanSM Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define CanSM_SetChannelVarRecord(Index, Value)                                                     CanSM_GetChannelVarRecordOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCGetAddressOfDataMacros  CanSM Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define CanSM_GetAddrChannelVarRecord(Index)                                                        (&CanSM_GetChannelVarRecord(Index))
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCHasMacros  CanSM Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define CanSM_HasChannelConfig()                                                                    (TRUE != FALSE)
#define CanSM_HasBorCounterL1ToL2OfChannelConfig()                                                  (TRUE != FALSE)
#define CanSM_HasBorTimeL1OfChannelConfig()                                                         (TRUE != FALSE)
#define CanSM_HasBorTimeL2OfChannelConfig()                                                         (TRUE != FALSE)
#define CanSM_HasBorTimeTxEnsuredOfChannelConfig()                                                  (TRUE != FALSE)
#define CanSM_HasBor_Tx_Confirmation_PollingOfChannelConfig()                                         /**< Deactivateable: 'CanSM_ChannelConfig.Bor_Tx_Confirmation_Polling' Reason: 'the value of CanSM_Bor_Tx_Confirmation_PollingOfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CanSM_HasControllerIdOfChannelConfig()                                                      (TRUE != FALSE)
#define CanSM_HasDemEventId_BusOff_OfChannelConfig()                                                (TRUE != FALSE)
#define CanSM_HasDemEventId_ModeRequest_OfChannelConfig()                                           (TRUE != FALSE)
#define CanSM_HasNetworkHandleOfChannelConfig()                                                     (TRUE != FALSE)
#define CanSM_HasPartial_Network_Trcv_SupportOfChannelConfig()                                        /**< Deactivateable: 'CanSM_ChannelConfig.Partial_Network_Trcv_Support' Reason: 'the value of CanSM_Partial_Network_Trcv_SupportOfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CanSM_HasPartial_Network_Wakeup_FilterOfChannelConfig()                                       /**< Deactivateable: 'CanSM_ChannelConfig.Partial_Network_Wakeup_Filter' Reason: 'the value of CanSM_Partial_Network_Wakeup_FilterOfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CanSM_HasProdErrorDetect_BusOff_OfChannelConfig()                                             /**< Deactivateable: 'CanSM_ChannelConfig.ProdErrorDetect_BusOff_' Reason: 'the value of CanSM_ProdErrorDetect_BusOff_OfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CanSM_HasProdErrorDetect_ModeRequest_OfChannelConfig()                                        /**< Deactivateable: 'CanSM_ChannelConfig.ProdErrorDetect_ModeRequest_' Reason: 'the value of CanSM_ProdErrorDetect_ModeRequest_OfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CanSM_HasTransceiverIdOfChannelConfig()                                                     (TRUE != FALSE)
#define CanSM_HasTransceiver_Channel_SupportOfChannelConfig()                                       (TRUE != FALSE)
#define CanSM_HasTrcv_InActive_AtAll_NonPNCannelsOfChannelConfig()                                  (TRUE != FALSE)
#define CanSM_HasChannelVarRecord()                                                                 (TRUE != FALSE)
#define CanSM_HasFinalMagicNumber()                                                                   /**< Deactivateable: 'CanSM_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CanSM_HasInitDataHashCode()                                                                   /**< Deactivateable: 'CanSM_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CanSM_HasModeRequestRepetitionMax()                                                         (TRUE != FALSE)
#define CanSM_HasModeRequestRepetitionTime()                                                        (TRUE != FALSE)
#define CanSM_HasSizeOfChannelConfig()                                                              (TRUE != FALSE)
#define CanSM_HasSizeOfChannelVarRecord()                                                           (TRUE != FALSE)
#define CanSM_HasPCConfig()                                                                         (TRUE != FALSE)
#define CanSM_HasChannelConfigOfPCConfig()                                                          (TRUE != FALSE)
#define CanSM_HasChannelVarRecordOfPCConfig()                                                       (TRUE != FALSE)
#define CanSM_HasFinalMagicNumberOfPCConfig()                                                         /**< Deactivateable: 'CanSM_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CanSM_HasInitDataHashCodeOfPCConfig()                                                         /**< Deactivateable: 'CanSM_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CanSM_HasModeRequestRepetitionMaxOfPCConfig()                                               (TRUE != FALSE)
#define CanSM_HasModeRequestRepetitionTimeOfPCConfig()                                              (TRUE != FALSE)
#define CanSM_HasSizeOfChannelConfigOfPCConfig()                                                    (TRUE != FALSE)
#define CanSM_HasSizeOfChannelVarRecordOfPCConfig()                                                 (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCIncrementDataMacros  CanSM Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define CanSM_IncChannelVarRecord(Index)                                                            CanSM_GetChannelVarRecord(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCDecrementDataMacros  CanSM Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define CanSM_DecChannelVarRecord(Index)                                                            CanSM_GetChannelVarRecord(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCAddDataMacros  CanSM Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define CanSM_AddChannelVarRecord(Index, Value)                                                     CanSM_SetChannelVarRecord(Index, (CanSM_GetChannelVarRecord(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCSubstractDataMacros  CanSM Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define CanSM_SubChannelVarRecord(Index, Value)                                                     CanSM_SetChannelVarRecord(Index, (CanSM_GetChannelVarRecord(Index) - Value))
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanSMPCDataSwitches  CanSM Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CANSM_CHANNELCONFIG                                                                         STD_ON
#define CANSM_BORCOUNTERL1TOL2OFCHANNELCONFIG                                                       STD_ON
#define CANSM_BORTIMEL1OFCHANNELCONFIG                                                              STD_ON
#define CANSM_BORTIMEL2OFCHANNELCONFIG                                                              STD_ON
#define CANSM_BORTIMETXENSUREDOFCHANNELCONFIG                                                       STD_ON
#define CANSM_BOR_TX_CONFIRMATION_POLLINGOFCHANNELCONFIG                                            STD_OFF  /**< Deactivateable: 'CanSM_ChannelConfig.Bor_Tx_Confirmation_Polling' Reason: 'the value of CanSM_Bor_Tx_Confirmation_PollingOfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CANSM_CONTROLLERIDOFCHANNELCONFIG                                                           STD_ON
#define CANSM_DEMEVENTID_BUSOFF_OFCHANNELCONFIG                                                     STD_ON
#define CANSM_DEMEVENTID_MODEREQUEST_OFCHANNELCONFIG                                                STD_ON
#define CANSM_NETWORKHANDLEOFCHANNELCONFIG                                                          STD_ON
#define CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG                                           STD_OFF  /**< Deactivateable: 'CanSM_ChannelConfig.Partial_Network_Trcv_Support' Reason: 'the value of CanSM_Partial_Network_Trcv_SupportOfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CANSM_PARTIAL_NETWORK_WAKEUP_FILTEROFCHANNELCONFIG                                          STD_OFF  /**< Deactivateable: 'CanSM_ChannelConfig.Partial_Network_Wakeup_Filter' Reason: 'the value of CanSM_Partial_Network_Wakeup_FilterOfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CANSM_PRODERRORDETECT_BUSOFF_OFCHANNELCONFIG                                                STD_OFF  /**< Deactivateable: 'CanSM_ChannelConfig.ProdErrorDetect_BusOff_' Reason: 'the value of CanSM_ProdErrorDetect_BusOff_OfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CANSM_PRODERRORDETECT_MODEREQUEST_OFCHANNELCONFIG                                           STD_OFF  /**< Deactivateable: 'CanSM_ChannelConfig.ProdErrorDetect_ModeRequest_' Reason: 'the value of CanSM_ProdErrorDetect_ModeRequest_OfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CANSM_TRANSCEIVERIDOFCHANNELCONFIG                                                          STD_ON
#define CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG                                            STD_ON
#define CANSM_TRCV_INACTIVE_ATALL_NONPNCANNELSOFCHANNELCONFIG                                       STD_ON
#define CANSM_CHANNELVARRECORD                                                                      STD_ON
#define CANSM_FINALMAGICNUMBER                                                                      STD_OFF  /**< Deactivateable: 'CanSM_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANSM_INITDATAHASHCODE                                                                      STD_OFF  /**< Deactivateable: 'CanSM_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANSM_MODEREQUESTREPETITIONMAX                                                              STD_ON
#define CANSM_MODEREQUESTREPETITIONTIME                                                             STD_ON
#define CANSM_SIZEOFCHANNELCONFIG                                                                   STD_ON
#define CANSM_SIZEOFCHANNELVARRECORD                                                                STD_ON
#define CANSM_PCCONFIG                                                                              STD_ON
#define CANSM_CHANNELCONFIGOFPCCONFIG                                                               STD_ON
#define CANSM_CHANNELVARRECORDOFPCCONFIG                                                            STD_ON
#define CANSM_FINALMAGICNUMBEROFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'CanSM_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANSM_INITDATAHASHCODEOFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'CanSM_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANSM_MODEREQUESTREPETITIONMAXOFPCCONFIG                                                    STD_ON
#define CANSM_MODEREQUESTREPETITIONTIMEOFPCCONFIG                                                   STD_ON
#define CANSM_SIZEOFCHANNELCONFIGOFPCCONFIG                                                         STD_ON
#define CANSM_SIZEOFCHANNELVARRECORDOFPCCONFIG                                                      STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCNoReferenceDefines  CanSM No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CANSM_NO_BORCOUNTERL1TOL2OFCHANNELCONFIG                                                    255u
#define CANSM_NO_BORTIMEL1OFCHANNELCONFIG                                                           255u
#define CANSM_NO_BORTIMEL2OFCHANNELCONFIG                                                           65535u
#define CANSM_NO_BORTIMETXENSUREDOFCHANNELCONFIG                                                    65535u
#define CANSM_NO_CONTROLLERIDOFCHANNELCONFIG                                                        255u
#define CANSM_NO_NETWORKHANDLEOFCHANNELCONFIG                                                       255u
#define CANSM_NO_TRANSCEIVERIDOFCHANNELCONFIG                                                       255u
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCIsReducedToDefineDefines  CanSM Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CANSM_ISDEF_BORCOUNTERL1TOL2OFCHANNELCONFIG                                                 STD_ON
#define CANSM_ISDEF_BORTIMEL1OFCHANNELCONFIG                                                        STD_ON
#define CANSM_ISDEF_BORTIMEL2OFCHANNELCONFIG                                                        STD_ON
#define CANSM_ISDEF_BORTIMETXENSUREDOFCHANNELCONFIG                                                 STD_ON
#define CANSM_ISDEF_BOR_TX_CONFIRMATION_POLLINGOFCHANNELCONFIG                                      STD_OFF
#define CANSM_ISDEF_CONTROLLERIDOFCHANNELCONFIG                                                     STD_OFF
#define CANSM_ISDEF_DEMEVENTID_BUSOFF_OFCHANNELCONFIG                                               STD_ON
#define CANSM_ISDEF_DEMEVENTID_MODEREQUEST_OFCHANNELCONFIG                                          STD_ON
#define CANSM_ISDEF_NETWORKHANDLEOFCHANNELCONFIG                                                    STD_OFF
#define CANSM_ISDEF_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG                                     STD_OFF
#define CANSM_ISDEF_PARTIAL_NETWORK_WAKEUP_FILTEROFCHANNELCONFIG                                    STD_OFF
#define CANSM_ISDEF_PRODERRORDETECT_BUSOFF_OFCHANNELCONFIG                                          STD_OFF
#define CANSM_ISDEF_PRODERRORDETECT_MODEREQUEST_OFCHANNELCONFIG                                     STD_OFF
#define CANSM_ISDEF_TRANSCEIVERIDOFCHANNELCONFIG                                                    STD_OFF
#define CANSM_ISDEF_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG                                      STD_OFF
#define CANSM_ISDEF_TRCV_INACTIVE_ATALL_NONPNCANNELSOFCHANNELCONFIG                                 STD_OFF
#define CANSM_ISDEF_CHANNELCONFIGOFPCCONFIG                                                         STD_ON
#define CANSM_ISDEF_CHANNELVARRECORDOFPCCONFIG                                                      STD_ON
#define CANSM_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                                      STD_OFF
#define CANSM_ISDEF_INITDATAHASHCODEOFPCCONFIG                                                      STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCEqualsAlwaysToDefines  CanSM Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CANSM_EQ2_BORCOUNTERL1TOL2OFCHANNELCONFIG                                                   5u
#define CANSM_EQ2_BORTIMEL1OFCHANNELCONFIG                                                          100u
#define CANSM_EQ2_BORTIMEL2OFCHANNELCONFIG                                                          300u
#define CANSM_EQ2_BORTIMETXENSUREDOFCHANNELCONFIG                                                   500u
#define CANSM_EQ2_BOR_TX_CONFIRMATION_POLLINGOFCHANNELCONFIG                                        
#define CANSM_EQ2_CONTROLLERIDOFCHANNELCONFIG                                                       
#define CANSM_EQ2_DEMEVENTID_BUSOFF_OFCHANNELCONFIG                                                 0xFFu
#define CANSM_EQ2_DEMEVENTID_MODEREQUEST_OFCHANNELCONFIG                                            0xFFu
#define CANSM_EQ2_NETWORKHANDLEOFCHANNELCONFIG                                                      
#define CANSM_EQ2_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG                                       
#define CANSM_EQ2_PARTIAL_NETWORK_WAKEUP_FILTEROFCHANNELCONFIG                                      
#define CANSM_EQ2_PRODERRORDETECT_BUSOFF_OFCHANNELCONFIG                                            
#define CANSM_EQ2_PRODERRORDETECT_MODEREQUEST_OFCHANNELCONFIG                                       
#define CANSM_EQ2_TRANSCEIVERIDOFCHANNELCONFIG                                                      
#define CANSM_EQ2_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG                                        
#define CANSM_EQ2_TRCV_INACTIVE_ATALL_NONPNCANNELSOFCHANNELCONFIG                                   
#define CANSM_EQ2_CHANNELCONFIGOFPCCONFIG                                                           CanSM_ChannelConfig
#define CANSM_EQ2_CHANNELVARRECORDOFPCCONFIG                                                        CanSM_ChannelVarRecord
#define CANSM_EQ2_FINALMAGICNUMBEROFPCCONFIG                                                        
#define CANSM_EQ2_INITDATAHASHCODEOFPCCONFIG                                                        
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCSymbolicInitializationPointers  CanSM Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define CanSM_Config_Ptr                                                                            NULL_PTR  /**< symbolic identifier which shall be used to initialize 'CanSM' */
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCInitializationSymbols  CanSM Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define CanSM_Config                                                                                NULL_PTR  /**< symbolic identifier which could be used to initialize 'CanSM */
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCGeneral  CanSM General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CANSM_CHECK_INIT_POINTER                                                                    STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CANSM_FINAL_MAGIC_NUMBER                                                                    0x8C1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of CanSM */
#define CANSM_INDIVIDUAL_POSTBUILD                                                                  STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'CanSM' is not configured to be postbuild capable. */
#define CANSM_INIT_DATA                                                                             CANSM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CANSM_INIT_DATA_HASH_CODE                                                                   337218771  /**< the precompile constant to validate the initialization structure at initialization time of CanSM with a hashcode. The seed value is '0x8C1Eu' */
#define CANSM_USE_ECUM_BSW_ERROR_HOOK                                                               STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CANSM_USE_INIT_POINTER                                                                      STD_OFF  /**< STD_ON if the init pointer CanSM shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanSMPCIterableTypes  CanSM Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate CanSM_ChannelConfig */
typedef uint8_least CanSM_ChannelConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCIterableTypesWithSizeRelations  CanSM Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate CanSM_ChannelVarRecord */
typedef CanSM_ChannelConfigIterType CanSM_ChannelVarRecordIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCValueTypes  CanSM Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for CanSM_BorCounterL1ToL2OfChannelConfig */
typedef uint8 CanSM_BorCounterL1ToL2OfChannelConfigType;

/**   \brief  value based type definition for CanSM_BorTimeL1OfChannelConfig */
typedef uint8 CanSM_BorTimeL1OfChannelConfigType;

/**   \brief  value based type definition for CanSM_BorTimeL2OfChannelConfig */
typedef uint16 CanSM_BorTimeL2OfChannelConfigType;

/**   \brief  value based type definition for CanSM_BorTimeTxEnsuredOfChannelConfig */
typedef uint16 CanSM_BorTimeTxEnsuredOfChannelConfigType;

/**   \brief  value based type definition for CanSM_ControllerIdOfChannelConfig */
typedef uint8 CanSM_ControllerIdOfChannelConfigType;

/**   \brief  value based type definition for CanSM_NetworkHandleOfChannelConfig */
typedef uint8 CanSM_NetworkHandleOfChannelConfigType;

/**   \brief  value based type definition for CanSM_TransceiverIdOfChannelConfig */
typedef uint8 CanSM_TransceiverIdOfChannelConfigType;

/**   \brief  value based type definition for CanSM_Transceiver_Channel_SupportOfChannelConfig */
typedef boolean CanSM_Transceiver_Channel_SupportOfChannelConfigType;

/**   \brief  value based type definition for CanSM_Trcv_InActive_AtAll_NonPNCannelsOfChannelConfig */
typedef boolean CanSM_Trcv_InActive_AtAll_NonPNCannelsOfChannelConfigType;

/**   \brief  value based type definition for CanSM_ModeRequestRepetitionMax */
typedef uint8 CanSM_ModeRequestRepetitionMaxType;

/**   \brief  value based type definition for CanSM_ModeRequestRepetitionTime */
typedef uint8 CanSM_ModeRequestRepetitionTimeType;

/**   \brief  value based type definition for CanSM_SizeOfChannelConfig */
typedef uint8 CanSM_SizeOfChannelConfigType;

/**   \brief  value based type definition for CanSM_SizeOfChannelVarRecord */
typedef uint8 CanSM_SizeOfChannelVarRecordType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanSMPCStructTypes  CanSM Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in CanSM_ChannelConfig */
typedef struct sCanSM_ChannelConfigType
{
  CanSM_Trcv_InActive_AtAll_NonPNCannelsOfChannelConfigType Trcv_InActive_AtAll_NonPNCannelsOfChannelConfig;  /**< Config feature which determines if Trvc is active at a Non PN channel */
  CanSM_NetworkHandleOfChannelConfigType NetworkHandleOfChannelConfig;
  CanSM_TransceiverIdOfChannelConfigType TransceiverIdOfChannelConfig;
} CanSM_ChannelConfigType;

/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCSymbolicStructTypes  CanSM Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCUnionIndexAndSymbolTypes  CanSM Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCRootPointerTypes  CanSM Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to CanSM_ChannelConfig */
typedef P2CONST(CanSM_ChannelConfigType, TYPEDEF, CANSM_CONST) CanSM_ChannelConfigPtrType;

/**   \brief  type used to point to CanSM_ChannelVarRecord */
typedef P2VAR(CanSM_ChannelVarRecordType, TYPEDEF, CANSM_VAR_NOINIT) CanSM_ChannelVarRecordPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCRootValueTypes  CanSM Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in CanSM_PCConfig */
typedef struct sCanSM_PCConfigType
{
  uint8 CanSM_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} CanSM_PCConfigType;

typedef CanSM_PCConfigType CanSM_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanSM_ChannelConfig
**********************************************************************************************************************/
/** 
  \var    CanSM_ChannelConfig
  \details
  Element                             Description
  Trcv_InActive_AtAll_NonPNCannels    Config feature which determines if Trvc is active at a Non PN channel
  NetworkHandle                   
  TransceiverId                   
*/ 
#define CANSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanSM_ChannelConfigType, CANSM_CONST) CanSM_ChannelConfig[2];
#define CANSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanSM_ChannelVarRecord
**********************************************************************************************************************/
#define CANSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanSM_ChannelVarRecordType, CANSM_VAR_NOINIT) CanSM_ChannelVarRecord[2];
#define CANSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/




#define CANSM_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, CANSM_VAR_ZERO_INIT) CanSM_EnableSetBusSleep[]; /* PRQA S 3684 */ /* MD_CANSM_Rule8.11 */
#define CANSM_STOP_SEC_VAR_ZERO_INIT_8BIT 
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */



typedef P2FUNC(void, CANSM_APPL_CODE, CanSM_BusOffBeginIndicationFctPtrType) ( NetworkHandleType  NetworkHandle, P2VAR(uint8, AUTOMATIC, CANSM_APPL_VAR) OnlineDelayCyclesPtr ); /* PRQA S 0850 */  /* MD_MSR_MacroArgumentEmpty  */

#define CANSM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST ( CanSM_BusOffBeginIndicationFctPtrType, CANSM_CONST ) CanSM_BusOffBeginIndicationFctPtr;

#define CANSM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define CANSM_START_SEC_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern FUNC(void, CANSM_APPL_CODE) Appl_BusOffBegin( NetworkHandleType  NetworkHandle, P2VAR(uint8, AUTOMATIC, CANSM_APPL_VAR) OnlineDelayCyclesPtr );

#define CANSM_STOP_SEC_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */



typedef P2FUNC(void, CANSM_APPL_CODE, CanSM_BusOffEndIndicationFctPtrType) ( NetworkHandleType  NetworkHandle ); /* PRQA S 0850 */  /* MD_MSR_MacroArgumentEmpty  */

#define CANSM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST ( CanSM_BusOffEndIndicationFctPtrType, CANSM_CONST ) CanSM_BusOffEndIndicationFctPtr;

#define CANSM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define CANSM_START_SEC_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern FUNC(void, CANSM_APPL_CODE) Appl_BusOffEnd( NetworkHandleType  NetworkHandle );

#define CANSM_STOP_SEC_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */





#endif /* CANSM_CFG_H */

