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
 *            Module: Xcp
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanXcp_Cfg.h
 *   Generation Time: 2024-02-13 13:07:49
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/



#if !defined(CANXCP_CFG_H)
#define CANXCP_CFG_H

/* -----------------------------------------------------------------------------
    &&&~  
 ----------------------------------------------------------------------------- */

#include "CanXcp_Types.h"

#if !defined XcpConfig
#define XcpConfig    CanXcp_Config
#endif

/* CanXcpTxPduId symbolic name defines */



/**
 * \defgroup XcpHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define XcpConf_XcpTxPdu_XcpTxPdu                                     0
/**\} */

/* CanXcpRxPduId symbolic name defines */



/**
 * \defgroup XcpHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define XcpConf_XcpRxPdu_XcpRxPdu                                     0
/**\} */


#ifndef XCP_USE_DUMMY_STATEMENT
#define XCP_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef XCP_DUMMY_STATEMENT
#define XCP_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef XCP_DUMMY_STATEMENT_CONST
#define XCP_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef XCP_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define XCP_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_ON /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef XCP_ATOMIC_VARIABLE_ACCESS
#define XCP_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef XCP_PROCESSOR_TDA4VE88
#define XCP_PROCESSOR_TDA4VE88
#endif
#ifndef XCP_COMP_LLVMTEXASINSTRUMENTS
#define XCP_COMP_LLVMTEXASINSTRUMENTS
#endif
#ifndef XCP_GEN_GENERATOR_MSR
#define XCP_GEN_GENERATOR_MSR
#endif
#ifndef XCP_CPUTYPE_BITORDER_LSB2MSB
#define XCP_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef XCP_CONFIGURATION_VARIANT_PRECOMPILE
#define XCP_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef XCP_CONFIGURATION_VARIANT_LINKTIME
#define XCP_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef XCP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define XCP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef XCP_CONFIGURATION_VARIANT
#define XCP_CONFIGURATION_VARIANT XCP_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef XCP_POSTBUILD_VARIANT_SUPPORT
#define XCP_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define CANXCP_USE_PDUINFOTYPE STD_ON
#define CANXCP_DEV_ERROR_DETECT              STD_ON 
#define CANXCP_VERSION_INFO_API              STD_ON   

#ifndef CANXCP_AUTOSARVERSION
#define CANXCP_AUTOSARVERSION                4
#endif

#ifndef CANXCP_CONFIGURATOR
#define CANXCP_CONFIGURATOR                  5
#endif

#ifndef CANXCP_CONFIG_VARIANT
#define CANXCP_CONFIG_VARIANT XCP_CONFIGURATION_VARIANT
#endif

/* Transport Layer */
#define CANXCP_MULTI_CHANNEL_DISABLED
#define CANXCP_MULTI_CONN_PROT_DISABLED
#define CANXCP_TRANSPORT_LAYER_VERSION       0x0100u
#define CANXCP_VARIABLE_DLC_DISABLED
#define kXcpSendQueueMinSize                 1u
/* Enable/Disable transport layer activation control API */
#define CANXCP_ENABLE_CONTROL                STD_ON
#define CANXCP_NUMBER_OF_CHANNELS            1u
#define CANXCP_CONF_TIMEOUT                  10u
#define kCanXcpMaxCTO                        8u
#define kCanXcpMaxDTO                        8u

#define CANXCP_PDU_SIZE                      8u /* CAN-FD specific options */
#define CANXCP_ENABLE_PDUMODE                STD_OFF

#define CANXCP_SILENT_CHECK                  STD_OFF
#define CANXCP_AMD_RUNTIME_MEASUREMENT       STD_OFF


#endif /* CANXCP_CFG_H */


