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
 *            Module: vXSpi
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D12
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vXSpi_Cfg_Int.h
 *   Generation Time: 2023-10-27 18:05:39
 *           Project: DemoUpdater - Version 1.0
 *          Delivery: CBD2101146_D12
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined VXSPI_CFG_INT_H_
# define VXSPI_CFG_INT_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "vXSpi_Types_Int.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Register access over Os peripheral access Api. */
# define VXSPI_USE_PERIPHERAL_ACCESS_API               STD_OFF

/*! Maximum number of devices over all hardware configurations. */
# define VXSPI_MAX_NUMBER_OF_DEVICES                   1u

/*! Maximum wait cycles for synchronous processing. */
# define VXSPI_SP_LOOP_CYCLES                          100000000u

/*! Maximum wait cycles for hardware. */
# define VXSPI_HW_LOOP_CYCLES                          1000u

/*! Number of hardware configs. */
# define VXSPI_NUMBER_OF_HW_CONFIGS                    1u

/*! Maximum number of hardware units. */
# define VXSPI_MAX_NUMBER_OF_HW_UNITS                  1u

/*! Alignment of the data buffer for reading and writing of user data needed by the vXSpi peripheral.  */
# define VXSPI_DATA_BUFFER_ALIGNMENT_IN_BYTES          1u

/**********************************************************************************************************************
 *  GENERAL DEFINE BLOCK
 *********************************************************************************************************************/
# ifndef VXSPI_USE_DUMMY_STATEMENT
#  define VXSPI_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
# endif
# ifndef VXSPI_DUMMY_STATEMENT
#  define VXSPI_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
# endif
# ifndef VXSPI_DUMMY_STATEMENT_CONST
#  define VXSPI_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
# endif
# ifndef VXSPI_ATOMIC_BIT_ACCESS_IN_BITFIELD
#  define VXSPI_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
# endif
# ifndef VXSPI_ATOMIC_VARIABLE_ACCESS
#  define VXSPI_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
# endif
# ifndef VXSPI_PROCESSOR_TDA4VE88
#  define VXSPI_PROCESSOR_TDA4VE88
# endif
# ifndef VXSPI_COMP_LLVMTEXASINSTRUMENTS
#  define VXSPI_COMP_LLVMTEXASINSTRUMENTS
# endif
# ifndef VXSPI_GEN_GENERATOR_MSR
#  define VXSPI_GEN_GENERATOR_MSR
# endif
# ifndef VXSPI_CPUTYPE_BITORDER_LSB2MSB
#  define VXSPI_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
# endif
# ifndef VXSPI_CONFIGURATION_VARIANT_PRECOMPILE
#  define VXSPI_CONFIGURATION_VARIANT_PRECOMPILE 1
# endif
# ifndef VXSPI_CONFIGURATION_VARIANT_LINKTIME
#  define VXSPI_CONFIGURATION_VARIANT_LINKTIME 2
# endif
# ifndef VXSPI_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#  define VXSPI_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
# endif
# ifndef VXSPI_CONFIGURATION_VARIANT
#  define VXSPI_CONFIGURATION_VARIANT VXSPI_CONFIGURATION_VARIANT_PRECOMPILE
# endif
# ifndef VXSPI_POSTBUILD_VARIANT_SUPPORT
#  define VXSPI_POSTBUILD_VARIANT_SUPPORT STD_OFF
# endif


/**********************************************************************************************************************
 * GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
# define VXSPI_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(vXSpi_ConfigPtrType, VXSPI_CFG) vXSpi_ConfigPtr;

# define VXSPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



#endif /* VXSPI_CFG_INT_H_ */

/*********************************************************************************************************************
 *  END OF FILE: vXSpi_Cfg_Int.h
 *********************************************************************************************************************/

