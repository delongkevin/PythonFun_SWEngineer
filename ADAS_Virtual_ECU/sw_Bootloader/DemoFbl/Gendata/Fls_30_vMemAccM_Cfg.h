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
 *            Module: Fls_30_vMemAccM
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Fls_30_vMemAccM_Cfg.h
 *   Generation Time: 2024-11-25 15:00:21
 *           Project: DemoFbl - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

/** Protection against multiple inclusion ***************************************************************************/
#if !defined (FLS_30_VMEMACCM_CFG_H)
# define FLS_30_VMEMACCM_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"

/***********************************************************************************************************************
 *  GENERAL DEFINE BLOCK
 **********************************************************************************************************************/
#ifndef FLS_30_VMEMACCM_USE_DUMMY_STATEMENT
#define FLS_30_VMEMACCM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef FLS_30_VMEMACCM_DUMMY_STATEMENT
#define FLS_30_VMEMACCM_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef FLS_30_VMEMACCM_DUMMY_STATEMENT_CONST
#define FLS_30_VMEMACCM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef FLS_30_VMEMACCM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define FLS_30_VMEMACCM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef FLS_30_VMEMACCM_ATOMIC_VARIABLE_ACCESS
#define FLS_30_VMEMACCM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef FLS_30_VMEMACCM_PROCESSOR_TDA4VE88
#define FLS_30_VMEMACCM_PROCESSOR_TDA4VE88
#endif
#ifndef FLS_30_VMEMACCM_COMP_LLVMTEXASINSTRUMENTS
#define FLS_30_VMEMACCM_COMP_LLVMTEXASINSTRUMENTS
#endif
#ifndef FLS_30_VMEMACCM_GEN_GENERATOR_MSR
#define FLS_30_VMEMACCM_GEN_GENERATOR_MSR
#endif
#ifndef FLS_30_VMEMACCM_CPUTYPE_BITORDER_LSB2MSB
#define FLS_30_VMEMACCM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef FLS_30_VMEMACCM_CONFIGURATION_VARIANT_PRECOMPILE
#define FLS_30_VMEMACCM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef FLS_30_VMEMACCM_CONFIGURATION_VARIANT_LINKTIME
#define FLS_30_VMEMACCM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef FLS_30_VMEMACCM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define FLS_30_VMEMACCM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef FLS_30_VMEMACCM_CONFIGURATION_VARIANT
#define FLS_30_VMEMACCM_CONFIGURATION_VARIANT FLS_30_VMEMACCM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef FLS_30_VMEMACCM_POSTBUILD_VARIANT_SUPPORT
#define FLS_30_VMEMACCM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/* Version information */
/* This is not the sub-package version but a compatibility version, which will only be updated if a change in the 
   generator (i.e. generated files) affects the implementation sub-package */
# define FLS_30_VMEMACCM_CFG_MAJOR_VERSION 5u 
# define FLS_30_VMEMACCM_CFG_MINOR_VERSION 0u 
# define FLS_30_VMEMACCM_CFG_PATCH_VERSION 0u 


/* API configuration */
# define FLS_30_VMEMACCM_VERSION_INFO_API STD_OFF
# define FLS_30_VMEMACCM_BLANK_CHECK_API STD_OFF
# define FLS_30_VMEMACCM_READBLANK_API STD_OFF
# define FLS_30_VMEMACCM_COMPARE_API STD_OFF

/* Module configuration */
# define FLS_30_VMEMACCM_DEV_ERROR_DETECT STD_ON
# define FLS_30_VMEMACCM_DEV_ERROR_REPORT STD_ON
# define FLS_30_VMEMACCM_WRITE_RAM_ALIGNMENT STD_OFF

/* Notification functionality between Fee <- Fls_30_vMemAccM */
# define FLS_30_VMEMACCM_FEE_NOTIFICATION STD_OFF

/* Notification functionality between Fls_30_vMemAccM <- vMemAccM */
# define FLS_30_VMEMACCM_POLLING_MODE STD_ON


#endif /* FLS_30_VMEMACCM_CFG_H */
/**********************************************************************************************************************
  END OF FILE: Fls_30_vMemAccM_Cfg.h
**********************************************************************************************************************/

