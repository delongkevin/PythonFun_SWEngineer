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
 *            Module: vRoE
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vRoE_Cfg.h
 *   Generation Time: 2024-02-13 13:07:48
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined(VROE_CFG_H)
#define VROE_CFG_H

/**********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 * Version information
 **********************************************************************************************************************/
/* SW version number of BSW-IMPLEMENTATION */
#define VROE_CFG_SW_MAJOR_VERSION                                    3u
#define VROE_CFG_SW_MINOR_VERSION                                    0u
#define VROE_CFG_SW_PATCH_VERSION                                    0u

/* Generator Version Information */
#define VROE_CFG_GEN_MAJOR_VERSION                                   3u
#define VROE_CFG_GEN_MINOR_VERSION                                   0u
#define VROE_CFG_GEN_PATCH_VERSION                                   0u

/**********************************************************************************************************************
 * General Defines
 **********************************************************************************************************************/
/*! Access to version information */
#define VROE_VERSION_INFO_API                                        STD_OFF /* /MICROSAR/vRoE/Cdd/CddGeneral/CddVersionInfoApi */
/*! Instance ID used for DET */
#define VROE_INSTANCE_ID                                             0u /* /MICROSAR/vRoE/Cdd/CddGeneral/CddInstanceId */
/*! Size of the transmission queue */
#define VROE_QUEUE_SIZE                                              8u /* /MICROSAR/vRoE/Cdd/CddGeneral/CddQueueSize */
/*! Client ID used for DEM interaction */
#define VROE_DEM_CLIENT_ID                                           DemConf_DemClient_DemClient /* /MICROSAR/vRoE/Cdd/CddGeneral/CddDemClientRef */
/*! NvM block ID */
#define VROE_BLOCK_ID                                                NvMConf_NvMBlockDescriptor_NvM_Dem_STATUS /* /MICROSAR/vRoE/Cdd/CddGeneral/CddNvMBlockRef */
/*! Highest possible safety module usage */
#define VROE_DEV_ERROR_DETECT                                        STD_ON
/*! Development error detection and reporting */
#define VROE_DEV_ERROR_REPORT                                        STD_ON

#ifndef VROE_USE_DUMMY_STATEMENT
#define VROE_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VROE_DUMMY_STATEMENT
#define VROE_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VROE_DUMMY_STATEMENT_CONST
#define VROE_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VROE_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define VROE_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_ON /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef VROE_ATOMIC_VARIABLE_ACCESS
#define VROE_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef VROE_PROCESSOR_TDA4VE88
#define VROE_PROCESSOR_TDA4VE88
#endif
#ifndef VROE_COMP_LLVMTEXASINSTRUMENTS
#define VROE_COMP_LLVMTEXASINSTRUMENTS
#endif
#ifndef VROE_GEN_GENERATOR_MSR
#define VROE_GEN_GENERATOR_MSR
#endif
#ifndef VROE_CPUTYPE_BITORDER_LSB2MSB
#define VROE_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef VROE_CONFIGURATION_VARIANT_PRECOMPILE
#define VROE_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef VROE_CONFIGURATION_VARIANT_LINKTIME
#define VROE_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef VROE_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define VROE_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef VROE_CONFIGURATION_VARIANT
#define VROE_CONFIGURATION_VARIANT VROE_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef VROE_POSTBUILD_VARIANT_SUPPORT
#define VROE_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#endif /* VROE_CFG_H */

