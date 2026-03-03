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
 *            Module: Fee
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D12
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Fee_PrivateCfg.h
 *   Generation Time: 2023-10-27 18:05:39
 *           Project: DemoUpdater - Version 1.0
 *          Delivery: CBD2101146_D12
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] AR-ECUC02027 - Integer value out of range 
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/Fee/FeePartitionConfiguration[0:FeeWriteAlignment](value=2048) is not in range [8, 1024].
 * Erroneous configuration elements:
 * /ActiveEcuC/Fee/FeePartitionConfiguration[0:FeeWriteAlignment](value=2048) (DefRef: /MICROSAR/Fee/FeePartitionConfiguration/FeeWriteAlignment)
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  PRIVATE SECTION
 *********************************************************************************************************************/
#if !defined (FEE_PRIVATE_CFG_H)
# define FEE_PRIVATE_CFG_H

  /****************************************************************************
   * VERSION IDENTIFICATION
   ***************************************************************************/
# define FEE_PRIVATE_CFG_MAJOR_VERSION                                (10u)
# define FEE_PRIVATE_CFG_MINOR_VERSION                                (0u)
# define FEE_PRIVATE_CFG_PATCH_VERSION                                (0u)

#ifndef FEE_USE_DUMMY_STATEMENT
#define FEE_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef FEE_DUMMY_STATEMENT
#define FEE_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef FEE_DUMMY_STATEMENT_CONST
#define FEE_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef FEE_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define FEE_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef FEE_ATOMIC_VARIABLE_ACCESS
#define FEE_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef FEE_PROCESSOR_TDA4VE88
#define FEE_PROCESSOR_TDA4VE88
#endif
#ifndef FEE_COMP_LLVMTEXASINSTRUMENTS
#define FEE_COMP_LLVMTEXASINSTRUMENTS
#endif
#ifndef FEE_GEN_GENERATOR_MSR
#define FEE_GEN_GENERATOR_MSR
#endif
#ifndef FEE_CPUTYPE_BITORDER_LSB2MSB
#define FEE_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef FEE_CONFIGURATION_VARIANT_PRECOMPILE
#define FEE_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef FEE_CONFIGURATION_VARIANT_LINKTIME
#define FEE_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef FEE_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define FEE_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef FEE_CONFIGURATION_VARIANT
#define FEE_CONFIGURATION_VARIANT FEE_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef FEE_POSTBUILD_VARIANT_SUPPORT
#define FEE_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


  /****************************************************************************
   * Data consistency 
   ***************************************************************************/
#include "SchM_Fee.h"

#define Fee_GlobalSuspend() SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_0() 
#define Fee_GlobalRestore() SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_0() 


  /****************************************************************************
   * Configurations for Development mode
   ***************************************************************************/

#include "Det.h"

/* PRQA S 3453 1 *//* MD_MSR_19.7 */
#define Fee_Errorhook(funcId, errId) Det_ReportError((FEE_MODULE_ID), (FEE_INSTANCE_ID), (funcId), (errId))


  /*******************************************************************************************************************
   *  GLOBAL CONSTANT MACROS
   ******************************************************************************************************************/
   
# define FEE_INTERNAL_BUFFER_SIZE                             (512u)
   
  /****************************************************************************
   * LOWER LAYER CONFIGURATION PARAMETERS
   ***************************************************************************/
# define FEE_POLLING_MODE                                     (STD_ON)

# define Fee_FlsRead                                          FlsWrapper_Read
# define Fee_FlsReadBlank                                     FlsWrapper_Read
# define Fee_FlsWrite                                         Fls_Write
# define Fee_FlsErase                                         Fls_Erase
# define Fee_FlsCompare                                       Fls_Compare
# define Fee_FlsCancel                                        FlsWrapper_Cancel
# define Fee_FlsGetStatus                                     Fls_GetStatus
# define Fee_FlsGetJobResult                                  Fls_GetJobResult


  /****************************************************************************
   * UPPER LAYER CONFIGURATION PARAMETERS
   ***************************************************************************/
# define FEE_NVM_POLLING_MODE                                (STD_ON)

# if (STD_OFF == FEE_NVM_POLLING_MODE)
#  define Fee_NvMJobEndNotification()                        ()
#  define Fee_NvMJobErrorNotification()                      ()
# endif

  /****************************************************************************
   * Error Callback Notification
   ***************************************************************************/
# define FEE_USE_APPL_ERROR_CALLBACK                        (STD_OFF)

# if (STD_ON == FEE_USE_APPL_ERROR_CALLBACK)
#  include "Appl_Include.h"
# endif

  /********************************************************************************************************************
   *  INCLUDES
   *******************************************************************************************************************/


#include "FlsWrapper.h" 


# if (STD_OFF == FEE_NVM_POLLING_MODE)

# endif

/********************************************************************************************************************
   *  Extern Definitions
 *******************************************************************************************************************/

#include "Fee_LookUpTableDefs.h"
extern CONST(struct Fee_BlockConfigStruct, FEE_APPL_CONFIG) Fee_BlockConfig_at[15];

#endif /* !defined (FEE_PRIVATE_CFG_H) */

/**********************************************************************************************************************
 *  END OF FILE: Fee_PrivateCfg.h
 *********************************************************************************************************************/
 

