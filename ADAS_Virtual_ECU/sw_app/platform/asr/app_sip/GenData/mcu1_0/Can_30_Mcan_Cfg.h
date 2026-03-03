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
 *            Module: Can
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Can_30_Mcan_Cfg.h
 *   Generation Time: 2024-02-13 13:07:50
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/* -----------------------------------------------------------------------------
    Generator Info
 ----------------------------------------------------------------------------- 
  Name:     MICROSAR M_CAN driver Generator
  Version:  5.07.03
  MSN:      Can
  Origin:   CAN
  Descrip:  MICROSAR Can driver generator
  JavaPack: com.vector.cfg.gen.DrvCan_Mpc5700McanAsr
 ----------------------------------------------------------------------------- */

#if !defined(CAN_30_MCAN_CFG_H)
#define CAN_30_MCAN_CFG_H

/* CAN222, CAN389, CAN365, CAN366, CAN367 */
/* CAN022, CAN047, CAN388, CAN397, CAN390, CAN392  */

/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2 */

/* -----------------------------------------------------------------------------
    Includes
 ----------------------------------------------------------------------------- */

#include "ComStack_Types.h"

#include "Can_GeneralTypes.h" /* CAN435 */

#if defined (CAN_30_MCAN_LCFG_SOURCE) || defined (C_DRV_30_MCAN_INTERNAL) /* ESCAN00070085 */
# include "Os.h"
#endif

/* -----------------------------------------------------------------------------
    General Switches for CAN module
 ----------------------------------------------------------------------------- */

#ifndef CAN_30_MCAN_USE_DUMMY_STATEMENT
#define CAN_30_MCAN_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CAN_30_MCAN_DUMMY_STATEMENT
#define CAN_30_MCAN_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CAN_30_MCAN_DUMMY_STATEMENT_CONST
#define CAN_30_MCAN_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CAN_30_MCAN_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CAN_30_MCAN_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_ON /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CAN_30_MCAN_ATOMIC_VARIABLE_ACCESS
#define CAN_30_MCAN_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CAN_30_MCAN_PROCESSOR_TDA4VE88
#define CAN_30_MCAN_PROCESSOR_TDA4VE88
#endif
#ifndef CAN_30_MCAN_COMP_LLVMTEXASINSTRUMENTS
#define CAN_30_MCAN_COMP_LLVMTEXASINSTRUMENTS
#endif
#ifndef CAN_30_MCAN_GEN_GENERATOR_MSR
#define CAN_30_MCAN_GEN_GENERATOR_MSR
#endif
#ifndef CAN_30_MCAN_CPUTYPE_BITORDER_LSB2MSB
#define CAN_30_MCAN_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CAN_30_MCAN_CONFIGURATION_VARIANT_PRECOMPILE
#define CAN_30_MCAN_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CAN_30_MCAN_CONFIGURATION_VARIANT_LINKTIME
#define CAN_30_MCAN_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CAN_30_MCAN_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CAN_30_MCAN_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CAN_30_MCAN_CONFIGURATION_VARIANT
#define CAN_30_MCAN_CONFIGURATION_VARIANT CAN_30_MCAN_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CAN_30_MCAN_POSTBUILD_VARIANT_SUPPORT
#define CAN_30_MCAN_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* -----------------------------------------------------------------------------
    General Switches from old v_cfg.h
 ----------------------------------------------------------------------------- */
#if !defined(V_GEN_GENERATOR5)
# define V_GEN_GENERATOR5 /* need by LL */
#endif
#if !defined(V_ENABLE_CAN_ASR_ABSTRACTION)
# define V_ENABLE_CAN_ASR_ABSTRACTION /* ATK */
#endif
#define CAN_30_MCAN_GEN_COM_STACK_LIB

#if !defined( V_OSTYPE_AUTOSAR )
# define V_OSTYPE_AUTOSAR
#endif

#if (CPU_TYPE == CPU_TYPE_32)
# if !defined( C_CPUTYPE_32BIT )
#  define C_CPUTYPE_32BIT
# endif
#endif
#if (CPU_TYPE == CPU_TYPE_16)
# if !defined( C_CPUTYPE_16BIT )
#  define C_CPUTYPE_16BIT
# endif
#endif
#if (CPU_TYPE == CPU_TYPE_8)
# if !defined( C_CPUTYPE_8BIT )
#  define C_CPUTYPE_8BIT
# endif
#endif
#if (CPU_BIT_ORDER == LSB_FIRST)
# if !defined( C_CPUTYPE_BITORDER_LSB2MSB )
#  define C_CPUTYPE_BITORDER_LSB2MSB
# endif
#endif
#if (CPU_BIT_ORDER == MSB_FIRST)
# if !defined( C_CPUTYPE_BITORDER_MSB2LSB )
#  define C_CPUTYPE_BITORDER_MSB2LSB
# endif
#endif
#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
# if !defined( C_CPUTYPE_LITTLEENDIAN )
#  define C_CPUTYPE_LITTLEENDIAN
# endif
#endif
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
# if !defined( C_CPUTYPE_BIGENDIAN )
#  define C_CPUTYPE_BIGENDIAN
# endif
#endif

#if !defined( V_DISABLE_USE_DUMMY_FUNCTIONS )
# define V_DISABLE_USE_DUMMY_FUNCTIONS
#endif
#if !defined( V_ENABLE_USE_DUMMY_STATEMENT )
# define V_ENABLE_USE_DUMMY_STATEMENT
#endif

#if !defined( V_CPU_TDA4 )
# define V_CPU_TDA4
#endif

#if !defined( C_PROCESSOR_TDA4 )
# define C_PROCESSOR_TDA4
#endif
#if !defined( V_PROCESSOR_TDA4 )
# define V_PROCESSOR_TDA4
#endif

#if !defined( C_COMP_LLVMTEXASINSTRUMENTS_TDA4_MCAN )
#define C_COMP_LLVMTEXASINSTRUMENTS_TDA4_MCAN
#endif
#if !defined( V_COMP_LLVMTEXASINSTRUMENTS )
# define V_COMP_LLVMTEXASINSTRUMENTS
#endif
#if !defined( V_COMP_LLVMTEXASINSTRUMENTS_TDA4 )
# define V_COMP_LLVMTEXASINSTRUMENTS_TDA4
#endif

#if !defined( V_SUPPRESS_EXTENDED_VERSION_CHECK )
# define V_SUPPRESS_EXTENDED_VERSION_CHECK
#endif

/* -----------------------------------------------------------------------------
    Version defines
 ----------------------------------------------------------------------------- */

/* CAN024, CAN023 */
#define CAN_30_MCAN_ASR_VERSION              0x0400u
#define CAN_30_MCAN_GEN_BASE_CFG5_VERSION    0x0103u
#define CAN_30_MCAN_GEN_BASESASR_VERSION     0x0407u
#define CAN_30_MCAN_GEN_Mpc5700McanAsr_VERSION              0x0504u
#define CAN_30_MCAN_MICROSAR_VERSION         CAN_30_MCAN_MSR403

/* -----------------------------------------------------------------------------
    Hardcoded defines
 ----------------------------------------------------------------------------- */

#define CAN_30_MCAN_INSTANCE_ID           0

#define CAN_30_MCAN_RX_BASICCAN_TYPE                 0u
#define CAN_30_MCAN_RX_FULLCAN_TYPE                  1u
#define CAN_30_MCAN_TX_BASICCAN_TYPE                 2u
#define CAN_30_MCAN_TX_FULLCAN_TYPE                  3u
#define CAN_30_MCAN_UNUSED_CAN_TYPE                  4u
#define CAN_30_MCAN_TX_BASICCAN_MUX_TYPE             5u
#define CAN_30_MCAN_TX_BASICCAN_FIFO_TYPE            6u

#define CAN_30_MCAN_INTERRUPT                        0u
#define CAN_30_MCAN_POLLING                          1u

#define kCan_30_McanChannelNotUsed                     CAN_30_MCAN_NO_CANIFCHANNELID 

#define CAN_30_MCAN_NONE                             0u
/* RAM check (also  none) */
#define CAN_30_MCAN_NOTIFY_ISSUE                     1u
#define CAN_30_MCAN_NOTIFY_MAILBOX                   2u
#define CAN_30_MCAN_EXTENDED                         3u
/* Interrupt lock (also  none) */
#define CAN_30_MCAN_DRIVER                           1u
#define CAN_30_MCAN_APPL                             2u
#define CAN_30_MCAN_BOTH                             3u
/* Overrun Notification (als none,appl) */
#define CAN_30_MCAN_DET                              1u
/* CAN FD Support */
#define CAN_30_MCAN_BRS                              1u
#define CAN_30_MCAN_FULL                             2u
/* CAN FD Configuration */
#define CAN_30_MCAN_FD_RXONLY                        2u /* FD Baudrate exist (RX) */
#define CAN_30_MCAN_FD_RXTX                          1u /* FD Baudrate also used for TX */
/* Generic Confirmation */
#define CAN_30_MCAN_API1                             1u
#define CAN_30_MCAN_API2                             2u

#define CAN_30_MCAN_OS_TICK2MS(tick)     OS_TICKS2MS_SystemTimer((tick))     /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define CAN_30_MCAN_OS_COUNTER_ID        SystemTimer

/* -----------------------------------------------------------------------------
    Defines / Switches
 ----------------------------------------------------------------------------- */

/* Version and Issue detection */
#define CAN_30_MCAN_VERSION_INFO_API                 STD_OFF   /* CAN106_Conf */
#define CAN_30_MCAN_DEV_ERROR_DETECT                 STD_ON   /* CAN064_Conf */
#define CAN_30_MCAN_DEV_ERROR_REPORT                 STD_ON
#define CAN_30_MCAN_SAFE_BSW                         STD_OFF

/* Interrupt / Polling */
#define CAN_30_MCAN_TX_PROCESSING                    CAN_30_MCAN_INTERRUPT   /* CAN318_Conf */
#define CAN_30_MCAN_RX_PROCESSING                    CAN_30_MCAN_INTERRUPT   /* CAN317_Conf */
#define CAN_30_MCAN_BUSOFF_PROCESSING                CAN_30_MCAN_INTERRUPT   /* CAN314_Conf */
#define CAN_30_MCAN_WAKEUP_PROCESSING                CAN_30_MCAN_INTERRUPT   /* CAN319_Conf */
#define CAN_30_MCAN_INDIVIDUAL_PROCESSING            STD_OFF
#define CAN_30_MCAN_INTERRUPT_USED                   STD_ON
#define CAN_30_MCAN_NESTED_INTERRUPTS                STD_OFF
#define C_30_MCAN_ENABLE_OSEK_OS_INTCAT2
#define C_30_MCAN_DISABLE_ISRVOID
#define CAN_30_MCAN_INTLOCK                          CAN_30_MCAN_DRIVER

/* Tx Handling */
#define CAN_30_MCAN_MULTIPLEXED_TX_MAX               1u
#define CAN_30_MCAN_CANCEL_SUPPORT_API               STD_OFF
#define CAN_30_MCAN_TRANSMIT_BUFFER                  STD_ON
#define CAN_30_MCAN_MULTIPLEXED_TRANSMISSION         STD_OFF   /* CAN095_Conf */
#define CAN_30_MCAN_TX_HW_FIFO                       STD_OFF
#define CAN_30_MCAN_HW_TRANSMIT_CANCELLATION         STD_OFF   /* CAN069_Conf */
#define CAN_30_MCAN_IDENTICAL_ID_CANCELLATION        STD_OFF   /* CAN378_Conf */
#define CAN_30_MCAN_MULTIPLE_BASICCAN_TX             STD_OFF

/* Rx Handling */
#define CAN_30_MCAN_MULTIPLE_BASICCAN                STD_OFF
#define CAN_30_MCAN_RX_QUEUE                         STD_OFF
#define CAN_30_MCAN_OVERRUN_NOTIFICATION             CAN_30_MCAN_APPL

/* Sleep Wakeup */
#define CAN_30_MCAN_SLEEP_SUPPORT                    STD_OFF
#define CAN_30_MCAN_WAKEUP_SUPPORT                   STD_OFF   /* CAN330_Conf */

/* Hardware loop check */
#define CAN_30_MCAN_HARDWARE_CANCELLATION            STD_ON
#define CAN_30_MCAN_TIMEOUT_DURATION                 10u   /* CAN113_Conf */
#define CAN_30_MCAN_LOOP_MAX                         5u

/* Appl calls */
#define CAN_30_MCAN_HW_LOOP_SUPPORT_API              STD_ON
#define CAN_30_MCAN_GENERIC_PRECOPY                  STD_ON
#define CAN_30_MCAN_GENERIC_CONFIRMATION             STD_OFF
#define CAN_30_MCAN_GENERIC_PRETRANSMIT              STD_OFF
#define CAN_30_MCAN_USE_OS_INTERRUPT_CONTROL         STD_OFF

/* Optimization */
#define CAN_30_MCAN_RX_FULLCAN_OBJECTS               STD_OFF
#define CAN_30_MCAN_TX_FULLCAN_OBJECTS               STD_OFF
#define CAN_30_MCAN_RX_BASICCAN_OBJECTS              STD_ON
#define CAN_30_MCAN_EXTENDED_ID                      STD_ON
#define CAN_30_MCAN_MIXED_ID                         STD_ON
#define CAN_30_MCAN_ONE_CONTROLLER_OPTIMIZATION      STD_OFF
#define CAN_30_MCAN_CHANGE_BAUDRATE_API              STD_OFF   /* CAN460_Conf */
#define CAN_30_MCAN_FD_HW_BUFFER_OPTIMIZATION        STD_ON

/* CAN FD */
#define CAN_30_MCAN_SET_BAUDRATE_API                 STD_OFF   /* CAN482_Conf */
#define CAN_30_MCAN_FD_SUPPORT                       CAN_30_MCAN_FULL

/* Other */
#define CAN_30_MCAN_COMMON_CAN                       STD_OFF
#define CAN_30_MCAN_RAM_CHECK                        CAN_30_MCAN_NOTIFY_MAILBOX
#define CAN_30_MCAN_REINIT_START                     STD_OFF
#define CAN_30_MCAN_GET_STATUS                       STD_OFF
#define CAN_30_MCAN_RUNTIME_MEASUREMENT_SUPPORT      STD_OFF
#define CAN_30_MCAN_PROTECTED_MODE                   STD_OFF
#define CAN_30_MCAN_MIRROR_MODE                      STD_OFF
#define CAN_30_MCAN_SILENT_MODE                      STD_OFF
#define CAN_30_MCAN_CHECK_WAKEUP_CAN_RET_TYPE        STD_OFF
#define CAN_30_MCAN_SECURITY_EVENT_REPORTING         STD_OFF
/* -----------------------------------------------------------------------------
    Channel And Mailbox
 ----------------------------------------------------------------------------- */
#ifndef C_DRV_30_MCAN_INTERNAL
# ifndef kCan_30_McanNumberOfChannels
#  define kCan_30_McanNumberOfChannels               2u
# endif
# ifndef kCan_30_McanNumberOfHwChannels
#  define kCan_30_McanNumberOfHwChannels             2u
# endif
#endif
#ifndef kCan_30_McanNumberOfUsedChannels /* ATK only */
# define kCan_30_McanNumberOfUsedChannels            2u
#endif

#define kCan_30_McanPhysToLogChannelIndex_0 0u
#define kCan_30_McanPhysToLogChannelIndex_1 1u

#define kCan_30_McanNumberOfPhysChannels             2u

/* -----------------------------------------------------------------------------
    Symbolic Name Values for Controller, HardwareObject and Baudrates
 ----------------------------------------------------------------------------- */
/* These definitions can change at Link-time and Post-build configuration time. Use them wisely. */



/**
 * \defgroup Can_30_McanHandleIdsactivated Handle IDs of handle space activated.
 * \brief controllers by CanControllerActivation
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define CanConf_CanController_CT_FDCAN2_c5d3d1a7                      0u
#define CanConf_CanController_CT_FDCAN14_90ecad61                     1u
/**\} */
#define CanConf_30_Mcan_CN_FDCAN14_525e7c5e_Rx 3u
#define CanConf_30_Mcan_CN_FDCAN14_a902658e_Tx 2u
#define CanConf_30_Mcan_CN_FDCAN2_28a8fc44_Tx 0u
#define CanConf_30_Mcan_CN_FDCAN2_4c0547f7_Rx 1u

#define CanConf_30_Mcan_ControllerBaudrateConfig_CT_FDCAN2_c5d3d1a7_CanControllerBaudrateConfig 0u
#define CanConf_30_Mcan_ControllerBaudrateConfig_CT_FDCAN14_90ecad61_CanControllerBaudrateConfig 0u

#define CanConf_30_Mcan_MemorySection_RxBuffer_CT_FDCAN14_90ecad61 3u
#define CanConf_30_Mcan_MemorySection_RxBuffer_CT_FDCAN2_c5d3d1a7 0u
#define CanConf_30_Mcan_MemorySection_RxFifo_CT_FDCAN14_90ecad61 4u
#define CanConf_30_Mcan_MemorySection_RxFifo_CT_FDCAN2_c5d3d1a7 1u
#define CanConf_30_Mcan_MemorySection_TxBuffer_CT_FDCAN14_90ecad61 5u
#define CanConf_30_Mcan_MemorySection_TxBuffer_CT_FDCAN2_c5d3d1a7 2u



/* -----------------------------------------------------------------------------
    Types
 ----------------------------------------------------------------------------- */
/* HW specific BEGIN */

/* HW specific Pre Can Config H file */

/* -----------------------------------------------------------------------------
    &&&~ Defines / Switches (Hw specific ) 
 ----------------------------------------------------------------------------- */

#define CAN_30_MCAN_REGEXT_MCMCAN                  STD_OFF
#define CAN_30_MCAN_REGEXT_MCANSS                  STD_ON
#define CAN_30_MCAN_REGEXT_SICANFD                 STD_OFF
#define CAN_30_MCAN_REGEXT_TTCANFD                 STD_OFF
#define CAN_30_MCAN_REGEXT_MCANAS1                 STD_OFF
#define CAN_30_MCAN_REGEXT_STMFDCAN                STD_OFF
#define CAN_30_MCAN_REGEXT_TCC                     STD_OFF
#define CAN_30_MCAN_REGEXT_TCC_PWD                 STD_OFF
#define CAN_30_MCAN_SHM_DATAQOS                    STD_OFF
#define CAN_30_MCAN_TRICORE_ERRATUM_AI_H001        STD_OFF
#define CAN_30_MCAN_PARITY_INTERRUPT               STD_ON

#define CAN_30_MCAN_MCANSS_EOI                     STD_ON
#define CAN_30_MCAN_MCANSS_ECC_EOI                 STD_OFF
#define CAN_30_MCAN_MCANSS_ECC_VBUSS               STD_ON
#define CAN_30_MCAN_MCANSS_ECC_AGGR                STD_ON
#define CAN_30_MCAN_MCANSS_CTRL_0                  STD_ON
#define CAN_30_MCAN_MCANSS_CTRL_1                  STD_OFF

#define C_30_MCAN_ENABLE_GENERATE_FULLCAN_MASK           /* FullCAN filter generation supported */

#define CAN_30_MCAN_ISR_ALL_CHAN          STD_OFF
#define CAN_30_MCAN_ISR_LEVEL_TRIGGERED   STD_OFF
#define CAN_30_MCAN_ECC_INIT_SHM          STD_ON
#define CAN_30_MCAN_UPDATE_BASE_ADDRESS   STD_OFF

typedef VAR(uint32, CAN_30_MCAN_VAR_NOINIT) tCan_30_McanLLCanIntOld;


#if (defined(CAN_30_MCAN_LCFG_SOURCE) || defined(C_30_MCAN_DRV_INTERNAL)) && (CAN_30_MCAN_USE_OS_INTERRUPT_CONTROL == STD_ON)
typedef ISRType Can_30_Mcan_OsIsrType;
#else
typedef uint8 Can_30_Mcan_OsIsrType;
#endif


/* !HW specific Pre Can Config H file */ 
/* HW specific END */ 

typedef VAR(uint8, TYPEDEF) Can_30_McanChannelHandle;

#if defined (CAN_LCFG_SOURCE) || defined (C_DRV_30_MCAN_INTERNAL)
typedef TickType Can_30_Mcan_ExternalTickType; /* PRQA S 1507 */ /* MD_Can_HL_MultipleTypeDeclaration */
#else
typedef uint32 Can_30_Mcan_ExternalTickType; /* PRQA S 1507 */ /* MD_Can_HL_MultipleTypeDeclaration */
#endif

typedef VAR(Can_30_Mcan_ExternalTickType, TYPEDEF) Can_30_Mcan_LoopTimeout_dim_type[CAN_30_MCAN_LOOP_MAX+1u];




/* -----------------------------------------------------------------------------
    CONST Declarations
 ----------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
    VAR Declarations
 ----------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
    Hw specific
 ----------------------------------------------------------------------------- */
/* HW specific BEGIN */
/* HW specific global H file */

/* !HW specific global H file */
/* HW specific END */


/**********************************************************************************************************************
  ComStackLib
**********************************************************************************************************************/
/* Can_GlobalConfig: CAN354_Conf */
/* Can_ConfigType: CAN413 */

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Can_30_McanPCDataSwitches  Can_30_Mcan Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CAN_30_MCAN_ACTIVESENDOBJECT                                                                STD_ON
#define CAN_30_MCAN_PDUOFACTIVESENDOBJECT                                                           STD_ON
#define CAN_30_MCAN_STATEOFACTIVESENDOBJECT                                                         STD_ON
#define CAN_30_MCAN_BTP                                                                             STD_ON
#define CAN_30_MCAN_BASEDLL_GENERATORVERSION                                                        STD_ON
#define CAN_30_MCAN_BUFFERCONFIG                                                                    STD_ON
#define CAN_30_MCAN_RXBCOFBUFFERCONFIG                                                              STD_ON
#define CAN_30_MCAN_RXF0COFBUFFERCONFIG                                                             STD_ON
#define CAN_30_MCAN_RXF1COFBUFFERCONFIG                                                             STD_ON
#define CAN_30_MCAN_TXBCOFBUFFERCONFIG                                                              STD_ON
#define CAN_30_MCAN_TXEFCOFBUFFERCONFIG                                                             STD_ON
#define CAN_30_MCAN_CAN_FD_NISO                                                                     STD_ON
#define CAN_30_MCAN_C_ENABLE_MPC5700_MCAN_CREL_SSTEP                                                STD_ON
#define CAN_30_MCAN_C_ENABLE_MPC5700_MCAN_CREL_STEP                                                 STD_ON
#define CAN_30_MCAN_C_ENABLE_MPC5700_MCAN_MAJOR_CREL                                                STD_ON
#define CAN_30_MCAN_CANECCAGGRBASEADDR                                                              STD_ON
#define CAN_30_MCAN_CANIFCHANNELID                                                                  STD_ON
#define CAN_30_MCAN_CANMCANSSBASEADDR                                                               STD_ON
#define CAN_30_MCAN_CONTROLLERCONFIG                                                                STD_ON
#define CAN_30_MCAN_BASISADROFCONTROLLERCONFIG                                                      STD_ON
#define CAN_30_MCAN_CANCONTROLLERDEFAULTBAUDRATEIDXOFCONTROLLERCONFIG                               STD_ON
#define CAN_30_MCAN_CANCONTROLLERDEFAULTBAUDRATEOFCONTROLLERCONFIG                                  STD_ON
#define CAN_30_MCAN_ISTTCANOFCONTROLLERCONFIG                                                       STD_ON
#define CAN_30_MCAN_MAILBOXRXBASICENDIDXOFCONTROLLERCONFIG                                          STD_ON
#define CAN_30_MCAN_MAILBOXRXBASICLENGTHOFCONTROLLERCONFIG                                          STD_ON
#define CAN_30_MCAN_MAILBOXRXBASICSTARTIDXOFCONTROLLERCONFIG                                        STD_ON
#define CAN_30_MCAN_MAILBOXRXBASICUSEDOFCONTROLLERCONFIG                                            STD_ON
#define CAN_30_MCAN_MAILBOXRXFULLENDIDXOFCONTROLLERCONFIG                                           STD_OFF  /**< Deactivateable: 'Can_30_Mcan_ControllerConfig.MailboxRxFullEndIdx' Reason: 'the optional indirection is deactivated because MailboxRxFullUsedOfControllerConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CAN_30_MCAN_MAILBOXRXFULLLENGTHOFCONTROLLERCONFIG                                           STD_OFF  /**< Deactivateable: 'Can_30_Mcan_ControllerConfig.MailboxRxFullLength' Reason: 'the optional indirection is deactivated because MailboxRxFullUsedOfControllerConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CAN_30_MCAN_MAILBOXRXFULLSTARTIDXOFCONTROLLERCONFIG                                         STD_OFF  /**< Deactivateable: 'Can_30_Mcan_ControllerConfig.MailboxRxFullStartIdx' Reason: 'the optional indirection is deactivated because MailboxRxFullUsedOfControllerConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CAN_30_MCAN_MAILBOXRXFULLUSEDOFCONTROLLERCONFIG                                             STD_OFF  /**< Deactivateable: 'Can_30_Mcan_ControllerConfig.MailboxRxFullUsed' Reason: 'the optional indirection is deactivated because MailboxRxFullUsedOfControllerConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CAN_30_MCAN_MAILBOXTXBASICENDIDXOFCONTROLLERCONFIG                                          STD_ON
#define CAN_30_MCAN_MAILBOXTXBASICLENGTHOFCONTROLLERCONFIG                                          STD_ON
#define CAN_30_MCAN_MAILBOXTXBASICSTARTIDXOFCONTROLLERCONFIG                                        STD_ON
#define CAN_30_MCAN_MAILBOXTXBASICUSEDOFCONTROLLERCONFIG                                            STD_ON
#define CAN_30_MCAN_MAILBOXTXFULLENDIDXOFCONTROLLERCONFIG                                           STD_OFF  /**< Deactivateable: 'Can_30_Mcan_ControllerConfig.MailboxTxFullEndIdx' Reason: 'the optional indirection is deactivated because MailboxTxFullUsedOfControllerConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CAN_30_MCAN_MAILBOXTXFULLLENGTHOFCONTROLLERCONFIG                                           STD_OFF  /**< Deactivateable: 'Can_30_Mcan_ControllerConfig.MailboxTxFullLength' Reason: 'the optional indirection is deactivated because MailboxTxFullUsedOfControllerConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CAN_30_MCAN_MAILBOXTXFULLSTARTIDXOFCONTROLLERCONFIG                                         STD_OFF  /**< Deactivateable: 'Can_30_Mcan_ControllerConfig.MailboxTxFullStartIdx' Reason: 'the optional indirection is deactivated because MailboxTxFullUsedOfControllerConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CAN_30_MCAN_MAILBOXTXFULLUSEDOFCONTROLLERCONFIG                                             STD_OFF  /**< Deactivateable: 'Can_30_Mcan_ControllerConfig.MailboxTxFullUsed' Reason: 'the optional indirection is deactivated because MailboxTxFullUsedOfControllerConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CAN_30_MCAN_MAILBOXUNUSEDENDIDXOFCONTROLLERCONFIG                                           STD_OFF  /**< Deactivateable: 'Can_30_Mcan_ControllerConfig.MailboxUnusedEndIdx' Reason: 'the optional indirection is deactivated because MailboxUnusedUsedOfControllerConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CAN_30_MCAN_MAILBOXUNUSEDLENGTHOFCONTROLLERCONFIG                                           STD_OFF  /**< Deactivateable: 'Can_30_Mcan_ControllerConfig.MailboxUnusedLength' Reason: 'the optional indirection is deactivated because MailboxUnusedUsedOfControllerConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CAN_30_MCAN_MAILBOXUNUSEDSTARTIDXOFCONTROLLERCONFIG                                         STD_OFF  /**< Deactivateable: 'Can_30_Mcan_ControllerConfig.MailboxUnusedStartIdx' Reason: 'the optional indirection is deactivated because MailboxUnusedUsedOfControllerConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CAN_30_MCAN_MAILBOXUNUSEDUSEDOFCONTROLLERCONFIG                                             STD_OFF  /**< Deactivateable: 'Can_30_Mcan_ControllerConfig.MailboxUnusedUsed' Reason: 'the optional indirection is deactivated because MailboxUnusedUsedOfControllerConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CAN_30_MCAN_RXBASICHWSTARTOFCONTROLLERCONFIG                                                STD_ON
#define CAN_30_MCAN_RXBASICHWSTOPOFCONTROLLERCONFIG                                                 STD_ON
#define CAN_30_MCAN_RXFULLHWSTARTOFCONTROLLERCONFIG                                                 STD_ON
#define CAN_30_MCAN_RXFULLHWSTOPOFCONTROLLERCONFIG                                                  STD_ON
#define CAN_30_MCAN_TXBASICHWSTARTOFCONTROLLERCONFIG                                                STD_ON
#define CAN_30_MCAN_TXBASICHWSTOPOFCONTROLLERCONFIG                                                 STD_ON
#define CAN_30_MCAN_TXFULLHWSTARTOFCONTROLLERCONFIG                                                 STD_ON
#define CAN_30_MCAN_TXFULLHWSTOPOFCONTROLLERCONFIG                                                  STD_ON
#define CAN_30_MCAN_UNUSEDHWSTARTOFCONTROLLERCONFIG                                                 STD_ON
#define CAN_30_MCAN_UNUSEDHWSTOPOFCONTROLLERCONFIG                                                  STD_ON
#define CAN_30_MCAN_CONTROLLERDATA                                                                  STD_ON
#define CAN_30_MCAN_BUSOFFNOTIFICATIONOFCONTROLLERDATA                                              STD_ON
#define CAN_30_MCAN_BUSOFFTRANSITIONREQUESTOFCONTROLLERDATA                                         STD_ON
#define CAN_30_MCAN_CANINTERRUPTCOUNTEROFCONTROLLERDATA                                             STD_ON
#define CAN_30_MCAN_CANINTERRUPTOLDSTATUSOFCONTROLLERDATA                                           STD_ON
#define CAN_30_MCAN_INTENABLEOFCONTROLLERDATA                                                       STD_ON
#define CAN_30_MCAN_ISBUSOFFOFCONTROLLERDATA                                                        STD_ON
#define CAN_30_MCAN_LASTINITOBJECTOFCONTROLLERDATA                                                  STD_ON
#define CAN_30_MCAN_LASTSTATEOFCONTROLLERDATA                                                       STD_ON
#define CAN_30_MCAN_LOGSTATUSOFCONTROLLERDATA                                                       STD_ON
#define CAN_30_MCAN_LOOPTIMEOUTOFCONTROLLERDATA                                                     STD_ON
#define CAN_30_MCAN_MODETRANSITIONREQUESTOFCONTROLLERDATA                                           STD_ON
#define CAN_30_MCAN_NONFDOBJECTSPENDINGFLAGOFCONTROLLERDATA                                         STD_ON
#define CAN_30_MCAN_PREVMODEOFCONTROLLERDATA                                                        STD_ON
#define CAN_30_MCAN_RAMCHECKTRANSITIONREQUESTOFCONTROLLERDATA                                       STD_ON
#define CAN_30_MCAN_TXBCROFCONTROLLERDATA                                                           STD_ON
#define CAN_30_MCAN_TXBRPOFCONTROLLERDATA                                                           STD_ON
#define CAN_30_MCAN_FBTP                                                                            STD_ON
#define CAN_30_MCAN_FINALMAGICNUMBER                                                                STD_OFF  /**< Deactivateable: 'Can_30_Mcan_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CAN_30_MCAN_GFC                                                                             STD_ON
#define CAN_30_MCAN_INITDATAHASHCODE                                                                STD_OFF  /**< Deactivateable: 'Can_30_Mcan_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CAN_30_MCAN_INITOBJECTBAUDRATE                                                              STD_ON
#define CAN_30_MCAN_INITOBJECTFDBRSCONFIG                                                           STD_ON
#define CAN_30_MCAN_INITOBJECTSTARTINDEX                                                            STD_ON
#define CAN_30_MCAN_MAILBOX                                                                         STD_ON
#define CAN_30_MCAN_ACTIVESENDOBJECTOFMAILBOX                                                       STD_ON
#define CAN_30_MCAN_CONTROLLERCONFIGIDXOFMAILBOX                                                    STD_ON
#define CAN_30_MCAN_FDPADDINGOFMAILBOX                                                              STD_ON
#define CAN_30_MCAN_HWHANDLEOFMAILBOX                                                               STD_ON
#define CAN_30_MCAN_IDVALUEOFMAILBOX                                                                STD_ON
#define CAN_30_MCAN_MAILBOXSIZEOFMAILBOX                                                            STD_ON
#define CAN_30_MCAN_MAILBOXTYPEOFMAILBOX                                                            STD_ON
#define CAN_30_MCAN_MAXDATALENOFMAILBOX                                                             STD_ON
#define CAN_30_MCAN_MEMORYSECTIONSINDEXOFMAILBOX                                                    STD_ON
#define CAN_30_MCAN_MAILBOXSTATE                                                                    STD_ON
#define CAN_30_MCAN_MEMORYSECTIONINFO                                                               STD_ON
#define CAN_30_MCAN_MEMORYSECTIONSTARTOFMEMORYSECTIONINFO                                           STD_ON
#define CAN_30_MCAN_MEMORYSECTIONOBJECTS                                                            STD_ON
#define CAN_30_MCAN_HWHANDLEOFMEMORYSECTIONOBJECTS                                                  STD_ON
#define CAN_30_MCAN_MAILBOXELEMENTOFMEMORYSECTIONOBJECTS                                            STD_ON
#define CAN_30_MCAN_MAILBOXHANDLEOFMEMORYSECTIONOBJECTS                                             STD_ON
#define CAN_30_MCAN_PLATFORMDLL_GENERATORVERSION                                                    STD_ON
#define CAN_30_MCAN_SIDFC                                                                           STD_ON
#define CAN_30_MCAN_FLSSAOFSIDFC                                                                    STD_ON
#define CAN_30_MCAN_LSSOFSIDFC                                                                      STD_ON
#define CAN_30_MCAN_SIDFEENDIDXOFSIDFC                                                              STD_ON
#define CAN_30_MCAN_SIDFESTARTIDXOFSIDFC                                                            STD_ON
#define CAN_30_MCAN_SIDFEUSEDOFSIDFC                                                                STD_ON
#define CAN_30_MCAN_SIDFE                                                                           STD_ON
#define CAN_30_MCAN_SHMADR                                                                          STD_ON
#define CAN_30_MCAN_RXBAOFSHMADR                                                                    STD_ON
#define CAN_30_MCAN_RXF0AOFSHMADR                                                                   STD_ON
#define CAN_30_MCAN_RXF1AOFSHMADR                                                                   STD_ON
#define CAN_30_MCAN_SIDFAOFSHMADR                                                                   STD_ON
#define CAN_30_MCAN_STARTADROFSHMADR                                                                STD_ON
#define CAN_30_MCAN_STOPADROFSHMADR                                                                 STD_ON
#define CAN_30_MCAN_TXBAOFSHMADR                                                                    STD_ON
#define CAN_30_MCAN_TXEFAOFSHMADR                                                                   STD_ON
#define CAN_30_MCAN_XIDFAOFSHMADR                                                                   STD_ON
#define CAN_30_MCAN_SHMELEMENTSIZE                                                                  STD_ON
#define CAN_30_MCAN_F0DSOFSHMELEMENTSIZE                                                            STD_ON
#define CAN_30_MCAN_F1DSOFSHMELEMENTSIZE                                                            STD_ON
#define CAN_30_MCAN_RBDSOFSHMELEMENTSIZE                                                            STD_ON
#define CAN_30_MCAN_TBDSOFSHMELEMENTSIZE                                                            STD_ON
#define CAN_30_MCAN_TEFBDSOFSHMELEMENTSIZE                                                          STD_ON
#define CAN_30_MCAN_SIZEOFACTIVESENDOBJECT                                                          STD_ON
#define CAN_30_MCAN_SIZEOFBTP                                                                       STD_ON
#define CAN_30_MCAN_SIZEOFBUFFERCONFIG                                                              STD_ON
#define CAN_30_MCAN_SIZEOFCANECCAGGRBASEADDR                                                        STD_ON
#define CAN_30_MCAN_SIZEOFCANIFCHANNELID                                                            STD_ON
#define CAN_30_MCAN_SIZEOFCANMCANSSBASEADDR                                                         STD_ON
#define CAN_30_MCAN_SIZEOFCONTROLLERCONFIG                                                          STD_ON
#define CAN_30_MCAN_SIZEOFCONTROLLERDATA                                                            STD_ON
#define CAN_30_MCAN_SIZEOFFBTP                                                                      STD_ON
#define CAN_30_MCAN_SIZEOFGFC                                                                       STD_ON
#define CAN_30_MCAN_SIZEOFINITOBJECTBAUDRATE                                                        STD_ON
#define CAN_30_MCAN_SIZEOFINITOBJECTFDBRSCONFIG                                                     STD_ON
#define CAN_30_MCAN_SIZEOFINITOBJECTSTARTINDEX                                                      STD_ON
#define CAN_30_MCAN_SIZEOFMAILBOX                                                                   STD_ON
#define CAN_30_MCAN_SIZEOFMAILBOXSTATE                                                              STD_ON
#define CAN_30_MCAN_SIZEOFMEMORYSECTIONINFO                                                         STD_ON
#define CAN_30_MCAN_SIZEOFMEMORYSECTIONOBJECTS                                                      STD_ON
#define CAN_30_MCAN_SIZEOFSIDFC                                                                     STD_ON
#define CAN_30_MCAN_SIZEOFSIDFE                                                                     STD_ON
#define CAN_30_MCAN_SIZEOFSHMADR                                                                    STD_ON
#define CAN_30_MCAN_SIZEOFSHMELEMENTSIZE                                                            STD_ON
#define CAN_30_MCAN_SIZEOFTDCR                                                                      STD_ON
#define CAN_30_MCAN_SIZEOFXIDAM                                                                     STD_ON
#define CAN_30_MCAN_SIZEOFXIDFC                                                                     STD_ON
#define CAN_30_MCAN_SIZEOFXIDFE                                                                     STD_ON
#define CAN_30_MCAN_TDCR                                                                            STD_ON
#define CAN_30_MCAN_XIDAM                                                                           STD_ON
#define CAN_30_MCAN_XIDFC                                                                           STD_ON
#define CAN_30_MCAN_FLESAOFXIDFC                                                                    STD_ON
#define CAN_30_MCAN_LSEOFXIDFC                                                                      STD_ON
#define CAN_30_MCAN_XIDFEENDIDXOFXIDFC                                                              STD_ON
#define CAN_30_MCAN_XIDFESTARTIDXOFXIDFC                                                            STD_ON
#define CAN_30_MCAN_XIDFEUSEDOFXIDFC                                                                STD_ON
#define CAN_30_MCAN_XIDFE                                                                           STD_ON
#define CAN_30_MCAN_EIDFE_0OFXIDFE                                                                  STD_ON
#define CAN_30_MCAN_EIDFE_1OFXIDFE                                                                  STD_ON
#define CAN_30_MCAN_PCCONFIG                                                                        STD_ON
#define CAN_30_MCAN_ACTIVESENDOBJECTOFPCCONFIG                                                      STD_ON
#define CAN_30_MCAN_BTPOFPCCONFIG                                                                   STD_ON
#define CAN_30_MCAN_BASEDLL_GENERATORVERSIONOFPCCONFIG                                              STD_ON
#define CAN_30_MCAN_BUFFERCONFIGOFPCCONFIG                                                          STD_ON
#define CAN_30_MCAN_CAN_FD_NISOOFPCCONFIG                                                           STD_ON
#define CAN_30_MCAN_C_ENABLE_MPC5700_MCAN_CREL_SSTEPOFPCCONFIG                                      STD_ON
#define CAN_30_MCAN_C_ENABLE_MPC5700_MCAN_CREL_STEPOFPCCONFIG                                       STD_ON
#define CAN_30_MCAN_C_ENABLE_MPC5700_MCAN_MAJOR_CRELOFPCCONFIG                                      STD_ON
#define CAN_30_MCAN_CANECCAGGRBASEADDROFPCCONFIG                                                    STD_ON
#define CAN_30_MCAN_CANIFCHANNELIDOFPCCONFIG                                                        STD_ON
#define CAN_30_MCAN_CANMCANSSBASEADDROFPCCONFIG                                                     STD_ON
#define CAN_30_MCAN_CONTROLLERCONFIGOFPCCONFIG                                                      STD_ON
#define CAN_30_MCAN_CONTROLLERDATAOFPCCONFIG                                                        STD_ON
#define CAN_30_MCAN_FBTPOFPCCONFIG                                                                  STD_ON
#define CAN_30_MCAN_FINALMAGICNUMBEROFPCCONFIG                                                      STD_OFF  /**< Deactivateable: 'Can_30_Mcan_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CAN_30_MCAN_GFCOFPCCONFIG                                                                   STD_ON
#define CAN_30_MCAN_INITDATAHASHCODEOFPCCONFIG                                                      STD_OFF  /**< Deactivateable: 'Can_30_Mcan_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CAN_30_MCAN_INITOBJECTBAUDRATEOFPCCONFIG                                                    STD_ON
#define CAN_30_MCAN_INITOBJECTFDBRSCONFIGOFPCCONFIG                                                 STD_ON
#define CAN_30_MCAN_INITOBJECTSTARTINDEXOFPCCONFIG                                                  STD_ON
#define CAN_30_MCAN_MAILBOXOFPCCONFIG                                                               STD_ON
#define CAN_30_MCAN_MAILBOXSTATEOFPCCONFIG                                                          STD_ON
#define CAN_30_MCAN_MEMORYSECTIONINFOOFPCCONFIG                                                     STD_ON
#define CAN_30_MCAN_MEMORYSECTIONOBJECTSOFPCCONFIG                                                  STD_ON
#define CAN_30_MCAN_PLATFORMDLL_GENERATORVERSIONOFPCCONFIG                                          STD_ON
#define CAN_30_MCAN_SIDFCOFPCCONFIG                                                                 STD_ON
#define CAN_30_MCAN_SIDFEOFPCCONFIG                                                                 STD_ON
#define CAN_30_MCAN_SHMADROFPCCONFIG                                                                STD_ON
#define CAN_30_MCAN_SHMELEMENTSIZEOFPCCONFIG                                                        STD_ON
#define CAN_30_MCAN_SIZEOFACTIVESENDOBJECTOFPCCONFIG                                                STD_ON
#define CAN_30_MCAN_SIZEOFBTPOFPCCONFIG                                                             STD_ON
#define CAN_30_MCAN_SIZEOFBUFFERCONFIGOFPCCONFIG                                                    STD_ON
#define CAN_30_MCAN_SIZEOFCANECCAGGRBASEADDROFPCCONFIG                                              STD_ON
#define CAN_30_MCAN_SIZEOFCANIFCHANNELIDOFPCCONFIG                                                  STD_ON
#define CAN_30_MCAN_SIZEOFCANMCANSSBASEADDROFPCCONFIG                                               STD_ON
#define CAN_30_MCAN_SIZEOFCONTROLLERCONFIGOFPCCONFIG                                                STD_ON
#define CAN_30_MCAN_SIZEOFCONTROLLERDATAOFPCCONFIG                                                  STD_ON
#define CAN_30_MCAN_SIZEOFFBTPOFPCCONFIG                                                            STD_ON
#define CAN_30_MCAN_SIZEOFGFCOFPCCONFIG                                                             STD_ON
#define CAN_30_MCAN_SIZEOFINITOBJECTBAUDRATEOFPCCONFIG                                              STD_ON
#define CAN_30_MCAN_SIZEOFINITOBJECTFDBRSCONFIGOFPCCONFIG                                           STD_ON
#define CAN_30_MCAN_SIZEOFINITOBJECTSTARTINDEXOFPCCONFIG                                            STD_ON
#define CAN_30_MCAN_SIZEOFMAILBOXOFPCCONFIG                                                         STD_ON
#define CAN_30_MCAN_SIZEOFMAILBOXSTATEOFPCCONFIG                                                    STD_ON
#define CAN_30_MCAN_SIZEOFMEMORYSECTIONINFOOFPCCONFIG                                               STD_ON
#define CAN_30_MCAN_SIZEOFMEMORYSECTIONOBJECTSOFPCCONFIG                                            STD_ON
#define CAN_30_MCAN_SIZEOFSIDFCOFPCCONFIG                                                           STD_ON
#define CAN_30_MCAN_SIZEOFSIDFEOFPCCONFIG                                                           STD_ON
#define CAN_30_MCAN_SIZEOFSHMADROFPCCONFIG                                                          STD_ON
#define CAN_30_MCAN_SIZEOFSHMELEMENTSIZEOFPCCONFIG                                                  STD_ON
#define CAN_30_MCAN_SIZEOFTDCROFPCCONFIG                                                            STD_ON
#define CAN_30_MCAN_SIZEOFXIDAMOFPCCONFIG                                                           STD_ON
#define CAN_30_MCAN_SIZEOFXIDFCOFPCCONFIG                                                           STD_ON
#define CAN_30_MCAN_SIZEOFXIDFEOFPCCONFIG                                                           STD_ON
#define CAN_30_MCAN_TDCROFPCCONFIG                                                                  STD_ON
#define CAN_30_MCAN_XIDAMOFPCCONFIG                                                                 STD_ON
#define CAN_30_MCAN_XIDFCOFPCCONFIG                                                                 STD_ON
#define CAN_30_MCAN_XIDFEOFPCCONFIG                                                                 STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  Can_30_McanPCMinNumericValueDefines  Can_30_Mcan Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define CAN_30_MCAN_MIN_PDUOFACTIVESENDOBJECT                                                       0u
#define CAN_30_MCAN_MIN_STATEOFACTIVESENDOBJECT                                                     0u
#define CAN_30_MCAN_MIN_BUSOFFNOTIFICATIONOFCONTROLLERDATA                                          0u
#define CAN_30_MCAN_MIN_BUSOFFTRANSITIONREQUESTOFCONTROLLERDATA                                     0u
#define CAN_30_MCAN_MIN_CANINTERRUPTCOUNTEROFCONTROLLERDATA                                         0u
#define CAN_30_MCAN_MIN_INTENABLEOFCONTROLLERDATA                                                   0u
#define CAN_30_MCAN_MIN_LASTINITOBJECTOFCONTROLLERDATA                                              0u
#define CAN_30_MCAN_MIN_LASTSTATEOFCONTROLLERDATA                                                   0u
#define CAN_30_MCAN_MIN_LOGSTATUSOFCONTROLLERDATA                                                   0u
#define CAN_30_MCAN_MIN_MODETRANSITIONREQUESTOFCONTROLLERDATA                                       0u
#define CAN_30_MCAN_MIN_NONFDOBJECTSPENDINGFLAGOFCONTROLLERDATA                                     0u
#define CAN_30_MCAN_MIN_PREVMODEOFCONTROLLERDATA                                                    0u
#define CAN_30_MCAN_MIN_RAMCHECKTRANSITIONREQUESTOFCONTROLLERDATA                                   0u
#define CAN_30_MCAN_MIN_TXBCROFCONTROLLERDATA                                                       0u
#define CAN_30_MCAN_MIN_TXBRPOFCONTROLLERDATA                                                       0u
#define CAN_30_MCAN_MIN_MAILBOXSTATE                                                                0u
/** 
  \}
*/ 

/** 
  \defgroup  Can_30_McanPCMaxNumericValueDefines  Can_30_Mcan Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define CAN_30_MCAN_MAX_PDUOFACTIVESENDOBJECT                                                       65535u
#define CAN_30_MCAN_MAX_STATEOFACTIVESENDOBJECT                                                     65535u
#define CAN_30_MCAN_MAX_BUSOFFNOTIFICATIONOFCONTROLLERDATA                                          255u
#define CAN_30_MCAN_MAX_BUSOFFTRANSITIONREQUESTOFCONTROLLERDATA                                     255u
#define CAN_30_MCAN_MAX_CANINTERRUPTCOUNTEROFCONTROLLERDATA                                         255u
#define CAN_30_MCAN_MAX_INTENABLEOFCONTROLLERDATA                                                   4294967295u
#define CAN_30_MCAN_MAX_LASTINITOBJECTOFCONTROLLERDATA                                              255u
#define CAN_30_MCAN_MAX_LASTSTATEOFCONTROLLERDATA                                                   255u
#define CAN_30_MCAN_MAX_LOGSTATUSOFCONTROLLERDATA                                                   255u
#define CAN_30_MCAN_MAX_MODETRANSITIONREQUESTOFCONTROLLERDATA                                       255u
#define CAN_30_MCAN_MAX_NONFDOBJECTSPENDINGFLAGOFCONTROLLERDATA                                     4294967295u
#define CAN_30_MCAN_MAX_PREVMODEOFCONTROLLERDATA                                                    255u
#define CAN_30_MCAN_MAX_RAMCHECKTRANSITIONREQUESTOFCONTROLLERDATA                                   255u
#define CAN_30_MCAN_MAX_TXBCROFCONTROLLERDATA                                                       4294967295u
#define CAN_30_MCAN_MAX_TXBRPOFCONTROLLERDATA                                                       4294967295u
#define CAN_30_MCAN_MAX_MAILBOXSTATE                                                                255u
/** 
  \}
*/ 

/** 
  \defgroup  Can_30_McanPCNoReferenceDefines  Can_30_Mcan No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CAN_30_MCAN_NO_CANIFCHANNELID                                                               255u
#define CAN_30_MCAN_NO_CANCONTROLLERDEFAULTBAUDRATEIDXOFCONTROLLERCONFIG                            255u
#define CAN_30_MCAN_NO_CANCONTROLLERDEFAULTBAUDRATEOFCONTROLLERCONFIG                               65535u
#define CAN_30_MCAN_NO_MAILBOXRXBASICENDIDXOFCONTROLLERCONFIG                                       255u
#define CAN_30_MCAN_NO_MAILBOXRXBASICSTARTIDXOFCONTROLLERCONFIG                                     255u
#define CAN_30_MCAN_NO_MAILBOXTXBASICENDIDXOFCONTROLLERCONFIG                                       255u
#define CAN_30_MCAN_NO_MAILBOXTXBASICSTARTIDXOFCONTROLLERCONFIG                                     255u
#define CAN_30_MCAN_NO_RXBASICHWSTARTOFCONTROLLERCONFIG                                             255u
#define CAN_30_MCAN_NO_RXBASICHWSTOPOFCONTROLLERCONFIG                                              255u
#define CAN_30_MCAN_NO_RXFULLHWSTARTOFCONTROLLERCONFIG                                              255u
#define CAN_30_MCAN_NO_RXFULLHWSTOPOFCONTROLLERCONFIG                                               255u
#define CAN_30_MCAN_NO_TXBASICHWSTARTOFCONTROLLERCONFIG                                             255u
#define CAN_30_MCAN_NO_TXBASICHWSTOPOFCONTROLLERCONFIG                                              255u
#define CAN_30_MCAN_NO_TXFULLHWSTARTOFCONTROLLERCONFIG                                              255u
#define CAN_30_MCAN_NO_TXFULLHWSTOPOFCONTROLLERCONFIG                                               255u
#define CAN_30_MCAN_NO_UNUSEDHWSTARTOFCONTROLLERCONFIG                                              255u
#define CAN_30_MCAN_NO_UNUSEDHWSTOPOFCONTROLLERCONFIG                                               255u
#define CAN_30_MCAN_NO_SIDFEENDIDXOFSIDFC                                                           255u
#define CAN_30_MCAN_NO_SIDFESTARTIDXOFSIDFC                                                         255u
#define CAN_30_MCAN_NO_XIDFEENDIDXOFXIDFC                                                           255u
#define CAN_30_MCAN_NO_XIDFESTARTIDXOFXIDFC                                                         255u
/** 
  \}
*/ 

/** 
  \defgroup  Can_30_McanPCEnumExistsDefines  Can_30_Mcan Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define CAN_30_MCAN_EXISTS_NONE_INITOBJECTFDBRSCONFIG                                               STD_OFF
#define CAN_30_MCAN_EXISTS_FD_RXTX_INITOBJECTFDBRSCONFIG                                            STD_ON
#define CAN_30_MCAN_EXISTS_FD_RXONLY_INITOBJECTFDBRSCONFIG                                          STD_OFF
#define CAN_30_MCAN_EXISTS_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX                                    STD_ON
#define CAN_30_MCAN_EXISTS_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX                                     STD_OFF
#define CAN_30_MCAN_EXISTS_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX                                    STD_ON
#define CAN_30_MCAN_EXISTS_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX                                     STD_OFF
#define CAN_30_MCAN_EXISTS_UNUSED_CAN_TYPE_MAILBOXTYPEOFMAILBOX                                     STD_OFF
#define CAN_30_MCAN_EXISTS_TX_BASICCAN_MUX_TYPE_MAILBOXTYPEOFMAILBOX                                STD_OFF
#define CAN_30_MCAN_EXISTS_TX_BASICCAN_FIFO_TYPE_MAILBOXTYPEOFMAILBOX                               STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  Can_30_McanPCEnumDefines  Can_30_Mcan Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define CAN_30_MCAN_FD_RXTX_INITOBJECTFDBRSCONFIG                                                   0x01u
#define CAN_30_MCAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX                                           0x00u
#define CAN_30_MCAN_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX                                           0x02u
/** 
  \}
*/ 

/** 
  \defgroup  Can_30_McanPCIsReducedToDefineDefines  Can_30_Mcan Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CAN_30_MCAN_ISDEF_BTP                                                                       STD_OFF
#define CAN_30_MCAN_ISDEF_RXBCOFBUFFERCONFIG                                                        STD_OFF
#define CAN_30_MCAN_ISDEF_RXF0COFBUFFERCONFIG                                                       STD_OFF
#define CAN_30_MCAN_ISDEF_RXF1COFBUFFERCONFIG                                                       STD_OFF
#define CAN_30_MCAN_ISDEF_TXBCOFBUFFERCONFIG                                                        STD_OFF
#define CAN_30_MCAN_ISDEF_TXEFCOFBUFFERCONFIG                                                       STD_OFF
#define CAN_30_MCAN_ISDEF_CANECCAGGRBASEADDR                                                        STD_OFF
#define CAN_30_MCAN_ISDEF_CANIFCHANNELID                                                            STD_OFF
#define CAN_30_MCAN_ISDEF_CANMCANSSBASEADDR                                                         STD_OFF
#define CAN_30_MCAN_ISDEF_BASISADROFCONTROLLERCONFIG                                                STD_OFF
#define CAN_30_MCAN_ISDEF_CANCONTROLLERDEFAULTBAUDRATEIDXOFCONTROLLERCONFIG                         STD_OFF
#define CAN_30_MCAN_ISDEF_CANCONTROLLERDEFAULTBAUDRATEOFCONTROLLERCONFIG                            STD_OFF
#define CAN_30_MCAN_ISDEF_ISTTCANOFCONTROLLERCONFIG                                                 STD_OFF
#define CAN_30_MCAN_ISDEF_MAILBOXRXBASICENDIDXOFCONTROLLERCONFIG                                    STD_OFF
#define CAN_30_MCAN_ISDEF_MAILBOXRXBASICLENGTHOFCONTROLLERCONFIG                                    STD_OFF
#define CAN_30_MCAN_ISDEF_MAILBOXRXBASICSTARTIDXOFCONTROLLERCONFIG                                  STD_OFF
#define CAN_30_MCAN_ISDEF_MAILBOXRXBASICUSEDOFCONTROLLERCONFIG                                      STD_OFF
#define CAN_30_MCAN_ISDEF_MAILBOXTXBASICENDIDXOFCONTROLLERCONFIG                                    STD_OFF
#define CAN_30_MCAN_ISDEF_MAILBOXTXBASICLENGTHOFCONTROLLERCONFIG                                    STD_OFF
#define CAN_30_MCAN_ISDEF_MAILBOXTXBASICSTARTIDXOFCONTROLLERCONFIG                                  STD_OFF
#define CAN_30_MCAN_ISDEF_MAILBOXTXBASICUSEDOFCONTROLLERCONFIG                                      STD_OFF
#define CAN_30_MCAN_ISDEF_RXBASICHWSTARTOFCONTROLLERCONFIG                                          STD_OFF
#define CAN_30_MCAN_ISDEF_RXBASICHWSTOPOFCONTROLLERCONFIG                                           STD_OFF
#define CAN_30_MCAN_ISDEF_RXFULLHWSTARTOFCONTROLLERCONFIG                                           STD_OFF
#define CAN_30_MCAN_ISDEF_RXFULLHWSTOPOFCONTROLLERCONFIG                                            STD_OFF
#define CAN_30_MCAN_ISDEF_TXBASICHWSTARTOFCONTROLLERCONFIG                                          STD_OFF
#define CAN_30_MCAN_ISDEF_TXBASICHWSTOPOFCONTROLLERCONFIG                                           STD_OFF
#define CAN_30_MCAN_ISDEF_TXFULLHWSTARTOFCONTROLLERCONFIG                                           STD_OFF
#define CAN_30_MCAN_ISDEF_TXFULLHWSTOPOFCONTROLLERCONFIG                                            STD_OFF
#define CAN_30_MCAN_ISDEF_UNUSEDHWSTARTOFCONTROLLERCONFIG                                           STD_OFF
#define CAN_30_MCAN_ISDEF_UNUSEDHWSTOPOFCONTROLLERCONFIG                                            STD_OFF
#define CAN_30_MCAN_ISDEF_FBTP                                                                      STD_OFF
#define CAN_30_MCAN_ISDEF_GFC                                                                       STD_OFF
#define CAN_30_MCAN_ISDEF_INITOBJECTBAUDRATE                                                        STD_OFF
#define CAN_30_MCAN_ISDEF_INITOBJECTFDBRSCONFIG                                                     STD_OFF
#define CAN_30_MCAN_ISDEF_INITOBJECTSTARTINDEX                                                      STD_OFF
#define CAN_30_MCAN_ISDEF_ACTIVESENDOBJECTOFMAILBOX                                                 STD_OFF
#define CAN_30_MCAN_ISDEF_CONTROLLERCONFIGIDXOFMAILBOX                                              STD_OFF
#define CAN_30_MCAN_ISDEF_FDPADDINGOFMAILBOX                                                        STD_OFF
#define CAN_30_MCAN_ISDEF_HWHANDLEOFMAILBOX                                                         STD_OFF
#define CAN_30_MCAN_ISDEF_IDVALUEOFMAILBOX                                                          STD_OFF
#define CAN_30_MCAN_ISDEF_MAILBOXSIZEOFMAILBOX                                                      STD_OFF
#define CAN_30_MCAN_ISDEF_MAILBOXTYPEOFMAILBOX                                                      STD_OFF
#define CAN_30_MCAN_ISDEF_MAXDATALENOFMAILBOX                                                       STD_OFF
#define CAN_30_MCAN_ISDEF_MEMORYSECTIONSINDEXOFMAILBOX                                              STD_OFF
#define CAN_30_MCAN_ISDEF_MEMORYSECTIONSTARTOFMEMORYSECTIONINFO                                     STD_OFF
#define CAN_30_MCAN_ISDEF_HWHANDLEOFMEMORYSECTIONOBJECTS                                            STD_OFF
#define CAN_30_MCAN_ISDEF_MAILBOXELEMENTOFMEMORYSECTIONOBJECTS                                      STD_OFF
#define CAN_30_MCAN_ISDEF_MAILBOXHANDLEOFMEMORYSECTIONOBJECTS                                       STD_OFF
#define CAN_30_MCAN_ISDEF_FLSSAOFSIDFC                                                              STD_OFF
#define CAN_30_MCAN_ISDEF_LSSOFSIDFC                                                                STD_OFF
#define CAN_30_MCAN_ISDEF_SIDFEENDIDXOFSIDFC                                                        STD_OFF
#define CAN_30_MCAN_ISDEF_SIDFESTARTIDXOFSIDFC                                                      STD_OFF
#define CAN_30_MCAN_ISDEF_SIDFEUSEDOFSIDFC                                                          STD_OFF
#define CAN_30_MCAN_ISDEF_SIDFE                                                                     STD_OFF
#define CAN_30_MCAN_ISDEF_RXBAOFSHMADR                                                              STD_OFF
#define CAN_30_MCAN_ISDEF_RXF0AOFSHMADR                                                             STD_OFF
#define CAN_30_MCAN_ISDEF_RXF1AOFSHMADR                                                             STD_OFF
#define CAN_30_MCAN_ISDEF_SIDFAOFSHMADR                                                             STD_OFF
#define CAN_30_MCAN_ISDEF_STARTADROFSHMADR                                                          STD_OFF
#define CAN_30_MCAN_ISDEF_STOPADROFSHMADR                                                           STD_OFF
#define CAN_30_MCAN_ISDEF_TXBAOFSHMADR                                                              STD_OFF
#define CAN_30_MCAN_ISDEF_TXEFAOFSHMADR                                                             STD_OFF
#define CAN_30_MCAN_ISDEF_XIDFAOFSHMADR                                                             STD_OFF
#define CAN_30_MCAN_ISDEF_F0DSOFSHMELEMENTSIZE                                                      STD_OFF
#define CAN_30_MCAN_ISDEF_F1DSOFSHMELEMENTSIZE                                                      STD_OFF
#define CAN_30_MCAN_ISDEF_RBDSOFSHMELEMENTSIZE                                                      STD_OFF
#define CAN_30_MCAN_ISDEF_TBDSOFSHMELEMENTSIZE                                                      STD_OFF
#define CAN_30_MCAN_ISDEF_TEFBDSOFSHMELEMENTSIZE                                                    STD_OFF
#define CAN_30_MCAN_ISDEF_TDCR                                                                      STD_OFF
#define CAN_30_MCAN_ISDEF_XIDAM                                                                     STD_OFF
#define CAN_30_MCAN_ISDEF_FLESAOFXIDFC                                                              STD_OFF
#define CAN_30_MCAN_ISDEF_LSEOFXIDFC                                                                STD_OFF
#define CAN_30_MCAN_ISDEF_XIDFEENDIDXOFXIDFC                                                        STD_OFF
#define CAN_30_MCAN_ISDEF_XIDFESTARTIDXOFXIDFC                                                      STD_OFF
#define CAN_30_MCAN_ISDEF_XIDFEUSEDOFXIDFC                                                          STD_OFF
#define CAN_30_MCAN_ISDEF_EIDFE_0OFXIDFE                                                            STD_OFF
#define CAN_30_MCAN_ISDEF_EIDFE_1OFXIDFE                                                            STD_OFF
#define CAN_30_MCAN_ISDEF_ACTIVESENDOBJECTOFPCCONFIG                                                STD_ON
#define CAN_30_MCAN_ISDEF_BTPOFPCCONFIG                                                             STD_ON
#define CAN_30_MCAN_ISDEF_BUFFERCONFIGOFPCCONFIG                                                    STD_ON
#define CAN_30_MCAN_ISDEF_CANECCAGGRBASEADDROFPCCONFIG                                              STD_ON
#define CAN_30_MCAN_ISDEF_CANIFCHANNELIDOFPCCONFIG                                                  STD_ON
#define CAN_30_MCAN_ISDEF_CANMCANSSBASEADDROFPCCONFIG                                               STD_ON
#define CAN_30_MCAN_ISDEF_CONTROLLERCONFIGOFPCCONFIG                                                STD_ON
#define CAN_30_MCAN_ISDEF_CONTROLLERDATAOFPCCONFIG                                                  STD_ON
#define CAN_30_MCAN_ISDEF_FBTPOFPCCONFIG                                                            STD_ON
#define CAN_30_MCAN_ISDEF_GFCOFPCCONFIG                                                             STD_ON
#define CAN_30_MCAN_ISDEF_INITOBJECTBAUDRATEOFPCCONFIG                                              STD_ON
#define CAN_30_MCAN_ISDEF_INITOBJECTFDBRSCONFIGOFPCCONFIG                                           STD_ON
#define CAN_30_MCAN_ISDEF_INITOBJECTSTARTINDEXOFPCCONFIG                                            STD_ON
#define CAN_30_MCAN_ISDEF_MAILBOXOFPCCONFIG                                                         STD_ON
#define CAN_30_MCAN_ISDEF_MAILBOXSTATEOFPCCONFIG                                                    STD_ON
#define CAN_30_MCAN_ISDEF_MEMORYSECTIONINFOOFPCCONFIG                                               STD_ON
#define CAN_30_MCAN_ISDEF_MEMORYSECTIONOBJECTSOFPCCONFIG                                            STD_ON
#define CAN_30_MCAN_ISDEF_SIDFCOFPCCONFIG                                                           STD_ON
#define CAN_30_MCAN_ISDEF_SIDFEOFPCCONFIG                                                           STD_ON
#define CAN_30_MCAN_ISDEF_SHMADROFPCCONFIG                                                          STD_ON
#define CAN_30_MCAN_ISDEF_SHMELEMENTSIZEOFPCCONFIG                                                  STD_ON
#define CAN_30_MCAN_ISDEF_TDCROFPCCONFIG                                                            STD_ON
#define CAN_30_MCAN_ISDEF_XIDAMOFPCCONFIG                                                           STD_ON
#define CAN_30_MCAN_ISDEF_XIDFCOFPCCONFIG                                                           STD_ON
#define CAN_30_MCAN_ISDEF_XIDFEOFPCCONFIG                                                           STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  Can_30_McanPCEqualsAlwaysToDefines  Can_30_Mcan Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CAN_30_MCAN_EQ2_BTP                                                                         
#define CAN_30_MCAN_EQ2_RXBCOFBUFFERCONFIG                                                          
#define CAN_30_MCAN_EQ2_RXF0COFBUFFERCONFIG                                                         
#define CAN_30_MCAN_EQ2_RXF1COFBUFFERCONFIG                                                         
#define CAN_30_MCAN_EQ2_TXBCOFBUFFERCONFIG                                                          
#define CAN_30_MCAN_EQ2_TXEFCOFBUFFERCONFIG                                                         
#define CAN_30_MCAN_EQ2_CANECCAGGRBASEADDR                                                          
#define CAN_30_MCAN_EQ2_CANIFCHANNELID                                                              
#define CAN_30_MCAN_EQ2_CANMCANSSBASEADDR                                                           
#define CAN_30_MCAN_EQ2_BASISADROFCONTROLLERCONFIG                                                  
#define CAN_30_MCAN_EQ2_CANCONTROLLERDEFAULTBAUDRATEIDXOFCONTROLLERCONFIG                           
#define CAN_30_MCAN_EQ2_CANCONTROLLERDEFAULTBAUDRATEOFCONTROLLERCONFIG                              
#define CAN_30_MCAN_EQ2_ISTTCANOFCONTROLLERCONFIG                                                   
#define CAN_30_MCAN_EQ2_MAILBOXRXBASICENDIDXOFCONTROLLERCONFIG                                      
#define CAN_30_MCAN_EQ2_MAILBOXRXBASICLENGTHOFCONTROLLERCONFIG                                      
#define CAN_30_MCAN_EQ2_MAILBOXRXBASICSTARTIDXOFCONTROLLERCONFIG                                    
#define CAN_30_MCAN_EQ2_MAILBOXRXBASICUSEDOFCONTROLLERCONFIG                                        
#define CAN_30_MCAN_EQ2_MAILBOXTXBASICENDIDXOFCONTROLLERCONFIG                                      
#define CAN_30_MCAN_EQ2_MAILBOXTXBASICLENGTHOFCONTROLLERCONFIG                                      
#define CAN_30_MCAN_EQ2_MAILBOXTXBASICSTARTIDXOFCONTROLLERCONFIG                                    
#define CAN_30_MCAN_EQ2_MAILBOXTXBASICUSEDOFCONTROLLERCONFIG                                        
#define CAN_30_MCAN_EQ2_RXBASICHWSTARTOFCONTROLLERCONFIG                                            
#define CAN_30_MCAN_EQ2_RXBASICHWSTOPOFCONTROLLERCONFIG                                             
#define CAN_30_MCAN_EQ2_RXFULLHWSTARTOFCONTROLLERCONFIG                                             
#define CAN_30_MCAN_EQ2_RXFULLHWSTOPOFCONTROLLERCONFIG                                              
#define CAN_30_MCAN_EQ2_TXBASICHWSTARTOFCONTROLLERCONFIG                                            
#define CAN_30_MCAN_EQ2_TXBASICHWSTOPOFCONTROLLERCONFIG                                             
#define CAN_30_MCAN_EQ2_TXFULLHWSTARTOFCONTROLLERCONFIG                                             
#define CAN_30_MCAN_EQ2_TXFULLHWSTOPOFCONTROLLERCONFIG                                              
#define CAN_30_MCAN_EQ2_UNUSEDHWSTARTOFCONTROLLERCONFIG                                             
#define CAN_30_MCAN_EQ2_UNUSEDHWSTOPOFCONTROLLERCONFIG                                              
#define CAN_30_MCAN_EQ2_FBTP                                                                        
#define CAN_30_MCAN_EQ2_GFC                                                                         
#define CAN_30_MCAN_EQ2_INITOBJECTBAUDRATE                                                          
#define CAN_30_MCAN_EQ2_INITOBJECTFDBRSCONFIG                                                       
#define CAN_30_MCAN_EQ2_INITOBJECTSTARTINDEX                                                        
#define CAN_30_MCAN_EQ2_ACTIVESENDOBJECTOFMAILBOX                                                   
#define CAN_30_MCAN_EQ2_CONTROLLERCONFIGIDXOFMAILBOX                                                
#define CAN_30_MCAN_EQ2_FDPADDINGOFMAILBOX                                                          
#define CAN_30_MCAN_EQ2_HWHANDLEOFMAILBOX                                                           
#define CAN_30_MCAN_EQ2_IDVALUEOFMAILBOX                                                            
#define CAN_30_MCAN_EQ2_MAILBOXSIZEOFMAILBOX                                                        
#define CAN_30_MCAN_EQ2_MAILBOXTYPEOFMAILBOX                                                        
#define CAN_30_MCAN_EQ2_MAXDATALENOFMAILBOX                                                         
#define CAN_30_MCAN_EQ2_MEMORYSECTIONSINDEXOFMAILBOX                                                
#define CAN_30_MCAN_EQ2_MEMORYSECTIONSTARTOFMEMORYSECTIONINFO                                       
#define CAN_30_MCAN_EQ2_HWHANDLEOFMEMORYSECTIONOBJECTS                                              
#define CAN_30_MCAN_EQ2_MAILBOXELEMENTOFMEMORYSECTIONOBJECTS                                        
#define CAN_30_MCAN_EQ2_MAILBOXHANDLEOFMEMORYSECTIONOBJECTS                                         
#define CAN_30_MCAN_EQ2_FLSSAOFSIDFC                                                                
#define CAN_30_MCAN_EQ2_LSSOFSIDFC                                                                  
#define CAN_30_MCAN_EQ2_SIDFEENDIDXOFSIDFC                                                          
#define CAN_30_MCAN_EQ2_SIDFESTARTIDXOFSIDFC                                                        
#define CAN_30_MCAN_EQ2_SIDFEUSEDOFSIDFC                                                            
#define CAN_30_MCAN_EQ2_SIDFE                                                                       
#define CAN_30_MCAN_EQ2_RXBAOFSHMADR                                                                
#define CAN_30_MCAN_EQ2_RXF0AOFSHMADR                                                               
#define CAN_30_MCAN_EQ2_RXF1AOFSHMADR                                                               
#define CAN_30_MCAN_EQ2_SIDFAOFSHMADR                                                               
#define CAN_30_MCAN_EQ2_STARTADROFSHMADR                                                            
#define CAN_30_MCAN_EQ2_STOPADROFSHMADR                                                             
#define CAN_30_MCAN_EQ2_TXBAOFSHMADR                                                                
#define CAN_30_MCAN_EQ2_TXEFAOFSHMADR                                                               
#define CAN_30_MCAN_EQ2_XIDFAOFSHMADR                                                               
#define CAN_30_MCAN_EQ2_F0DSOFSHMELEMENTSIZE                                                        
#define CAN_30_MCAN_EQ2_F1DSOFSHMELEMENTSIZE                                                        
#define CAN_30_MCAN_EQ2_RBDSOFSHMELEMENTSIZE                                                        
#define CAN_30_MCAN_EQ2_TBDSOFSHMELEMENTSIZE                                                        
#define CAN_30_MCAN_EQ2_TEFBDSOFSHMELEMENTSIZE                                                      
#define CAN_30_MCAN_EQ2_TDCR                                                                        
#define CAN_30_MCAN_EQ2_XIDAM                                                                       
#define CAN_30_MCAN_EQ2_FLESAOFXIDFC                                                                
#define CAN_30_MCAN_EQ2_LSEOFXIDFC                                                                  
#define CAN_30_MCAN_EQ2_XIDFEENDIDXOFXIDFC                                                          
#define CAN_30_MCAN_EQ2_XIDFESTARTIDXOFXIDFC                                                        
#define CAN_30_MCAN_EQ2_XIDFEUSEDOFXIDFC                                                            
#define CAN_30_MCAN_EQ2_EIDFE_0OFXIDFE                                                              
#define CAN_30_MCAN_EQ2_EIDFE_1OFXIDFE                                                              
#define CAN_30_MCAN_EQ2_ACTIVESENDOBJECTOFPCCONFIG                                                  Can_30_Mcan_ActiveSendObject
#define CAN_30_MCAN_EQ2_BTPOFPCCONFIG                                                               Can_30_Mcan_BTP
#define CAN_30_MCAN_EQ2_BUFFERCONFIGOFPCCONFIG                                                      Can_30_Mcan_BufferConfig
#define CAN_30_MCAN_EQ2_CANECCAGGRBASEADDROFPCCONFIG                                                Can_30_Mcan_CanEccAggrBaseAddr
#define CAN_30_MCAN_EQ2_CANIFCHANNELIDOFPCCONFIG                                                    Can_30_Mcan_CanIfChannelId
#define CAN_30_MCAN_EQ2_CANMCANSSBASEADDROFPCCONFIG                                                 Can_30_Mcan_CanMcanSsBaseAddr
#define CAN_30_MCAN_EQ2_CONTROLLERCONFIGOFPCCONFIG                                                  Can_30_Mcan_ControllerConfig
#define CAN_30_MCAN_EQ2_CONTROLLERDATAOFPCCONFIG                                                    Can_30_Mcan_ControllerData
#define CAN_30_MCAN_EQ2_FBTPOFPCCONFIG                                                              Can_30_Mcan_FBTP
#define CAN_30_MCAN_EQ2_GFCOFPCCONFIG                                                               Can_30_Mcan_GFC
#define CAN_30_MCAN_EQ2_INITOBJECTBAUDRATEOFPCCONFIG                                                Can_30_Mcan_InitObjectBaudrate
#define CAN_30_MCAN_EQ2_INITOBJECTFDBRSCONFIGOFPCCONFIG                                             Can_30_Mcan_InitObjectFdBrsConfig
#define CAN_30_MCAN_EQ2_INITOBJECTSTARTINDEXOFPCCONFIG                                              Can_30_Mcan_InitObjectStartIndex
#define CAN_30_MCAN_EQ2_MAILBOXOFPCCONFIG                                                           Can_30_Mcan_Mailbox
#define CAN_30_MCAN_EQ2_MAILBOXSTATEOFPCCONFIG                                                      Can_30_Mcan_MailboxState
#define CAN_30_MCAN_EQ2_MEMORYSECTIONINFOOFPCCONFIG                                                 Can_30_Mcan_MemorySectionInfo
#define CAN_30_MCAN_EQ2_MEMORYSECTIONOBJECTSOFPCCONFIG                                              Can_30_Mcan_MemorySectionObjects
#define CAN_30_MCAN_EQ2_SIDFCOFPCCONFIG                                                             Can_30_Mcan_SIDFC
#define CAN_30_MCAN_EQ2_SIDFEOFPCCONFIG                                                             Can_30_Mcan_SIDFE
#define CAN_30_MCAN_EQ2_SHMADROFPCCONFIG                                                            Can_30_Mcan_ShmAdr
#define CAN_30_MCAN_EQ2_SHMELEMENTSIZEOFPCCONFIG                                                    Can_30_Mcan_ShmElementSize
#define CAN_30_MCAN_EQ2_TDCROFPCCONFIG                                                              Can_30_Mcan_TDCR
#define CAN_30_MCAN_EQ2_XIDAMOFPCCONFIG                                                             Can_30_Mcan_XIDAM
#define CAN_30_MCAN_EQ2_XIDFCOFPCCONFIG                                                             Can_30_Mcan_XIDFC
#define CAN_30_MCAN_EQ2_XIDFEOFPCCONFIG                                                             Can_30_Mcan_XIDFE
/** 
  \}
*/ 

/** 
  \defgroup  Can_30_McanPCSymbolicInitializationPointers  Can_30_Mcan Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Can_30_Mcan_Config_Ptr                                                                      NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Can_30_Mcan' */
/** 
  \}
*/ 

/** 
  \defgroup  Can_30_McanPCInitializationSymbols  Can_30_Mcan Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Can_30_Mcan_Config                                                                          NULL_PTR  /**< symbolic identifier which could be used to initialize 'Can_30_Mcan */
/** 
  \}
*/ 

/** 
  \defgroup  Can_30_McanPCGeneral  Can_30_Mcan General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CAN_30_MCAN_CHECK_INIT_POINTER                                                              STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CAN_30_MCAN_FINAL_MAGIC_NUMBER                                                              0x501Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of Can_30_Mcan */
#define CAN_30_MCAN_INDIVIDUAL_POSTBUILD                                                            STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Can_30_Mcan' is not configured to be postbuild capable. */
#define CAN_30_MCAN_INIT_DATA                                                                       CAN_30_MCAN_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CAN_30_MCAN_INIT_DATA_HASH_CODE                                                             -381740269  /**< the precompile constant to validate the initialization structure at initialization time of Can_30_Mcan with a hashcode. The seed value is '0x501Eu' */
#define CAN_30_MCAN_USE_ECUM_BSW_ERROR_HOOK                                                         STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CAN_30_MCAN_USE_INIT_POINTER                                                                STD_OFF  /**< STD_ON if the init pointer Can_30_Mcan shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Can_30_McanLTDataSwitches  Can_30_Mcan Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CAN_30_MCAN_LTCONFIG                                                                        STD_OFF  /**< Deactivateable: 'Can_30_Mcan_LTConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Can_30_McanPBDataSwitches  Can_30_Mcan Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CAN_30_MCAN_PBCONFIG                                                                        STD_OFF  /**< Deactivateable: 'Can_30_Mcan_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CAN_30_MCAN_LTCONFIGIDXOFPBCONFIG                                                           STD_OFF  /**< Deactivateable: 'Can_30_Mcan_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CAN_30_MCAN_PCCONFIGIDXOFPBCONFIG                                                           STD_OFF  /**< Deactivateable: 'Can_30_Mcan_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
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
  \defgroup  Can_30_McanPCGetConstantDuplicatedRootDataMacros  Can_30_Mcan Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Can_30_Mcan_GetActiveSendObjectOfPCConfig()                                                 Can_30_Mcan_ActiveSendObject  /**< the pointer to Can_30_Mcan_ActiveSendObject */
#define Can_30_Mcan_GetBTPOfPCConfig()                                                              Can_30_Mcan_BTP  /**< the pointer to Can_30_Mcan_BTP */
#define Can_30_Mcan_GetBaseDll_GeneratorVersionOfPCConfig()                                         0x0103u
#define Can_30_Mcan_GetBufferConfigOfPCConfig()                                                     Can_30_Mcan_BufferConfig  /**< the pointer to Can_30_Mcan_BufferConfig */
#define Can_30_Mcan_GetCAN_FD_NISOOfPCConfig()                                                      0x00u  /**< MCAN ISO/Bosch conformance */
#define Can_30_Mcan_GetC_ENABLE_MPC5700_MCAN_CREL_SSTEPOfPCConfig()                                 0x05u  /**< MCAN Release Sub Step */
#define Can_30_Mcan_GetC_ENABLE_MPC5700_MCAN_CREL_STEPOfPCConfig()                                  0x01u  /**< MCAN Release Step */
#define Can_30_Mcan_GetC_ENABLE_MPC5700_MCAN_MAJOR_CRELOfPCConfig()                                 0x03u  /**< MCAN Release Version */
#define Can_30_Mcan_GetCanEccAggrBaseAddrOfPCConfig()                                               Can_30_Mcan_CanEccAggrBaseAddr  /**< the pointer to Can_30_Mcan_CanEccAggrBaseAddr */
#define Can_30_Mcan_GetCanIfChannelIdOfPCConfig()                                                   Can_30_Mcan_CanIfChannelId  /**< the pointer to Can_30_Mcan_CanIfChannelId */
#define Can_30_Mcan_GetCanMcanSsBaseAddrOfPCConfig()                                                Can_30_Mcan_CanMcanSsBaseAddr  /**< the pointer to Can_30_Mcan_CanMcanSsBaseAddr */
#define Can_30_Mcan_GetControllerConfigOfPCConfig()                                                 Can_30_Mcan_ControllerConfig  /**< the pointer to Can_30_Mcan_ControllerConfig */
#define Can_30_Mcan_GetControllerDataOfPCConfig()                                                   Can_30_Mcan_ControllerData  /**< the pointer to Can_30_Mcan_ControllerData */
#define Can_30_Mcan_GetFBTPOfPCConfig()                                                             Can_30_Mcan_FBTP  /**< the pointer to Can_30_Mcan_FBTP */
#define Can_30_Mcan_GetGFCOfPCConfig()                                                              Can_30_Mcan_GFC  /**< the pointer to Can_30_Mcan_GFC */
#define Can_30_Mcan_GetInitObjectBaudrateOfPCConfig()                                               Can_30_Mcan_InitObjectBaudrate  /**< the pointer to Can_30_Mcan_InitObjectBaudrate */
#define Can_30_Mcan_GetInitObjectFdBrsConfigOfPCConfig()                                            Can_30_Mcan_InitObjectFdBrsConfig  /**< the pointer to Can_30_Mcan_InitObjectFdBrsConfig */
#define Can_30_Mcan_GetInitObjectStartIndexOfPCConfig()                                             Can_30_Mcan_InitObjectStartIndex  /**< the pointer to Can_30_Mcan_InitObjectStartIndex */
#define Can_30_Mcan_GetMailboxOfPCConfig()                                                          Can_30_Mcan_Mailbox  /**< the pointer to Can_30_Mcan_Mailbox */
#define Can_30_Mcan_GetMailboxStateOfPCConfig()                                                     Can_30_Mcan_MailboxState  /**< the pointer to Can_30_Mcan_MailboxState */
#define Can_30_Mcan_GetMemorySectionInfoOfPCConfig()                                                Can_30_Mcan_MemorySectionInfo  /**< the pointer to Can_30_Mcan_MemorySectionInfo */
#define Can_30_Mcan_GetMemorySectionObjectsOfPCConfig()                                             Can_30_Mcan_MemorySectionObjects  /**< the pointer to Can_30_Mcan_MemorySectionObjects */
#define Can_30_Mcan_GetPlatformDll_GeneratorVersionOfPCConfig()                                     0x0504u
#define Can_30_Mcan_GetSIDFCOfPCConfig()                                                            Can_30_Mcan_SIDFC  /**< the pointer to Can_30_Mcan_SIDFC */
#define Can_30_Mcan_GetSIDFEOfPCConfig()                                                            Can_30_Mcan_SIDFE  /**< the pointer to Can_30_Mcan_SIDFE */
#define Can_30_Mcan_GetShmAdrOfPCConfig()                                                           Can_30_Mcan_ShmAdr  /**< the pointer to Can_30_Mcan_ShmAdr */
#define Can_30_Mcan_GetShmElementSizeOfPCConfig()                                                   Can_30_Mcan_ShmElementSize  /**< the pointer to Can_30_Mcan_ShmElementSize */
#define Can_30_Mcan_GetSizeOfActiveSendObjectOfPCConfig()                                           2u  /**< the number of accomplishable value elements in Can_30_Mcan_ActiveSendObject */
#define Can_30_Mcan_GetSizeOfBTPOfPCConfig()                                                        2u  /**< the number of accomplishable value elements in Can_30_Mcan_BTP */
#define Can_30_Mcan_GetSizeOfBufferConfigOfPCConfig()                                               2u  /**< the number of accomplishable value elements in Can_30_Mcan_BufferConfig */
#define Can_30_Mcan_GetSizeOfCanEccAggrBaseAddrOfPCConfig()                                         2u  /**< the number of accomplishable value elements in Can_30_Mcan_CanEccAggrBaseAddr */
#define Can_30_Mcan_GetSizeOfCanIfChannelIdOfPCConfig()                                             2u  /**< the number of accomplishable value elements in Can_30_Mcan_CanIfChannelId */
#define Can_30_Mcan_GetSizeOfCanMcanSsBaseAddrOfPCConfig()                                          2u  /**< the number of accomplishable value elements in Can_30_Mcan_CanMcanSsBaseAddr */
#define Can_30_Mcan_GetSizeOfControllerConfigOfPCConfig()                                           2u  /**< the number of accomplishable value elements in Can_30_Mcan_ControllerConfig */
#define Can_30_Mcan_GetSizeOfFBTPOfPCConfig()                                                       2u  /**< the number of accomplishable value elements in Can_30_Mcan_FBTP */
#define Can_30_Mcan_GetSizeOfGFCOfPCConfig()                                                        2u  /**< the number of accomplishable value elements in Can_30_Mcan_GFC */
#define Can_30_Mcan_GetSizeOfInitObjectBaudrateOfPCConfig()                                         2u  /**< the number of accomplishable value elements in Can_30_Mcan_InitObjectBaudrate */
#define Can_30_Mcan_GetSizeOfInitObjectFdBrsConfigOfPCConfig()                                      2u  /**< the number of accomplishable value elements in Can_30_Mcan_InitObjectFdBrsConfig */
#define Can_30_Mcan_GetSizeOfInitObjectStartIndexOfPCConfig()                                       3u  /**< the number of accomplishable value elements in Can_30_Mcan_InitObjectStartIndex */
#define Can_30_Mcan_GetSizeOfMailboxOfPCConfig()                                                    4u  /**< the number of accomplishable value elements in Can_30_Mcan_Mailbox */
#define Can_30_Mcan_GetSizeOfMemorySectionInfoOfPCConfig()                                          2u  /**< the number of accomplishable value elements in Can_30_Mcan_MemorySectionInfo */
#define Can_30_Mcan_GetSizeOfMemorySectionObjectsOfPCConfig()                                       64u  /**< the number of accomplishable value elements in Can_30_Mcan_MemorySectionObjects */
#define Can_30_Mcan_GetSizeOfSIDFCOfPCConfig()                                                      2u  /**< the number of accomplishable value elements in Can_30_Mcan_SIDFC */
#define Can_30_Mcan_GetSizeOfSIDFEOfPCConfig()                                                      2u  /**< the number of accomplishable value elements in Can_30_Mcan_SIDFE */
#define Can_30_Mcan_GetSizeOfShmAdrOfPCConfig()                                                     2u  /**< the number of accomplishable value elements in Can_30_Mcan_ShmAdr */
#define Can_30_Mcan_GetSizeOfShmElementSizeOfPCConfig()                                             2u  /**< the number of accomplishable value elements in Can_30_Mcan_ShmElementSize */
#define Can_30_Mcan_GetSizeOfTDCROfPCConfig()                                                       2u  /**< the number of accomplishable value elements in Can_30_Mcan_TDCR */
#define Can_30_Mcan_GetSizeOfXIDAMOfPCConfig()                                                      2u  /**< the number of accomplishable value elements in Can_30_Mcan_XIDAM */
#define Can_30_Mcan_GetSizeOfXIDFCOfPCConfig()                                                      2u  /**< the number of accomplishable value elements in Can_30_Mcan_XIDFC */
#define Can_30_Mcan_GetSizeOfXIDFEOfPCConfig()                                                      2u  /**< the number of accomplishable value elements in Can_30_Mcan_XIDFE */
#define Can_30_Mcan_GetTDCROfPCConfig()                                                             Can_30_Mcan_TDCR  /**< the pointer to Can_30_Mcan_TDCR */
#define Can_30_Mcan_GetXIDAMOfPCConfig()                                                            Can_30_Mcan_XIDAM  /**< the pointer to Can_30_Mcan_XIDAM */
#define Can_30_Mcan_GetXIDFCOfPCConfig()                                                            Can_30_Mcan_XIDFC  /**< the pointer to Can_30_Mcan_XIDFC */
#define Can_30_Mcan_GetXIDFEOfPCConfig()                                                            Can_30_Mcan_XIDFE  /**< the pointer to Can_30_Mcan_XIDFE */
/** 
  \}
*/ 

/** 
  \defgroup  Can_30_McanPCGetDuplicatedRootDataMacros  Can_30_Mcan Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define Can_30_Mcan_GetSizeOfControllerDataOfPCConfig()                                             Can_30_Mcan_GetSizeOfControllerConfigOfPCConfig()  /**< the number of accomplishable value elements in Can_30_Mcan_ControllerData */
#define Can_30_Mcan_GetSizeOfMailboxStateOfPCConfig()                                               Can_30_Mcan_GetSizeOfMailboxOfPCConfig()  /**< the number of accomplishable value elements in Can_30_Mcan_MailboxState */
/** 
  \}
*/ 

/** 
  \defgroup  Can_30_McanPCGetDataMacros  Can_30_Mcan Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Can_30_Mcan_GetPduOfActiveSendObject(Index)                                                 (Can_30_Mcan_GetActiveSendObjectOfPCConfig()[(Index)].PduOfActiveSendObject)
#define Can_30_Mcan_GetStateOfActiveSendObject(Index)                                               (Can_30_Mcan_GetActiveSendObjectOfPCConfig()[(Index)].StateOfActiveSendObject)
#define Can_30_Mcan_GetBTP(Index)                                                                   (Can_30_Mcan_GetBTPOfPCConfig()[(Index)])
#define Can_30_Mcan_GetRXBCOfBufferConfig(Index)                                                    (Can_30_Mcan_GetBufferConfigOfPCConfig()[(Index)].RXBCOfBufferConfig)
#define Can_30_Mcan_GetRXF0COfBufferConfig(Index)                                                   (Can_30_Mcan_GetBufferConfigOfPCConfig()[(Index)].RXF0COfBufferConfig)
#define Can_30_Mcan_GetRXF1COfBufferConfig(Index)                                                   (Can_30_Mcan_GetBufferConfigOfPCConfig()[(Index)].RXF1COfBufferConfig)
#define Can_30_Mcan_GetTXBCOfBufferConfig(Index)                                                    (Can_30_Mcan_GetBufferConfigOfPCConfig()[(Index)].TXBCOfBufferConfig)
#define Can_30_Mcan_GetTXEFCOfBufferConfig(Index)                                                   (Can_30_Mcan_GetBufferConfigOfPCConfig()[(Index)].TXEFCOfBufferConfig)
#define Can_30_Mcan_GetCanEccAggrBaseAddr(Index)                                                    (Can_30_Mcan_GetCanEccAggrBaseAddrOfPCConfig()[(Index)])
#define Can_30_Mcan_GetCanIfChannelId(Index)                                                        (Can_30_Mcan_GetCanIfChannelIdOfPCConfig()[(Index)])
#define Can_30_Mcan_GetCanMcanSsBaseAddr(Index)                                                     (Can_30_Mcan_GetCanMcanSsBaseAddrOfPCConfig()[(Index)])
#define Can_30_Mcan_GetBasisAdrOfControllerConfig(Index)                                            (Can_30_Mcan_GetControllerConfigOfPCConfig()[(Index)].BasisAdrOfControllerConfig)
#define Can_30_Mcan_GetCanControllerDefaultBaudrateIdxOfControllerConfig(Index)                     (Can_30_Mcan_GetControllerConfigOfPCConfig()[(Index)].CanControllerDefaultBaudrateIdxOfControllerConfig)
#define Can_30_Mcan_GetCanControllerDefaultBaudrateOfControllerConfig(Index)                        (Can_30_Mcan_GetControllerConfigOfPCConfig()[(Index)].CanControllerDefaultBaudrateOfControllerConfig)
#define Can_30_Mcan_IsIsTTCanOfControllerConfig(Index)                                              ((Can_30_Mcan_GetControllerConfigOfPCConfig()[(Index)].IsTTCanOfControllerConfig) != FALSE)
#define Can_30_Mcan_GetMailboxRxBasicEndIdxOfControllerConfig(Index)                                (Can_30_Mcan_GetControllerConfigOfPCConfig()[(Index)].MailboxRxBasicEndIdxOfControllerConfig)
#define Can_30_Mcan_GetMailboxRxBasicLengthOfControllerConfig(Index)                                (Can_30_Mcan_GetControllerConfigOfPCConfig()[(Index)].MailboxRxBasicLengthOfControllerConfig)
#define Can_30_Mcan_GetMailboxRxBasicStartIdxOfControllerConfig(Index)                              (Can_30_Mcan_GetControllerConfigOfPCConfig()[(Index)].MailboxRxBasicStartIdxOfControllerConfig)
#define Can_30_Mcan_GetMailboxTxBasicEndIdxOfControllerConfig(Index)                                (Can_30_Mcan_GetControllerConfigOfPCConfig()[(Index)].MailboxTxBasicEndIdxOfControllerConfig)
#define Can_30_Mcan_GetMailboxTxBasicLengthOfControllerConfig(Index)                                (Can_30_Mcan_GetControllerConfigOfPCConfig()[(Index)].MailboxTxBasicLengthOfControllerConfig)
#define Can_30_Mcan_GetMailboxTxBasicStartIdxOfControllerConfig(Index)                              (Can_30_Mcan_GetControllerConfigOfPCConfig()[(Index)].MailboxTxBasicStartIdxOfControllerConfig)
#define Can_30_Mcan_GetRxBasicHwStartOfControllerConfig(Index)                                      (Can_30_Mcan_GetControllerConfigOfPCConfig()[(Index)].RxBasicHwStartOfControllerConfig)
#define Can_30_Mcan_GetRxBasicHwStopOfControllerConfig(Index)                                       (Can_30_Mcan_GetControllerConfigOfPCConfig()[(Index)].RxBasicHwStopOfControllerConfig)
#define Can_30_Mcan_GetRxFullHwStartOfControllerConfig(Index)                                       (Can_30_Mcan_GetControllerConfigOfPCConfig()[(Index)].RxFullHwStartOfControllerConfig)
#define Can_30_Mcan_GetRxFullHwStopOfControllerConfig(Index)                                        (Can_30_Mcan_GetControllerConfigOfPCConfig()[(Index)].RxFullHwStopOfControllerConfig)
#define Can_30_Mcan_GetTxBasicHwStartOfControllerConfig(Index)                                      (Can_30_Mcan_GetControllerConfigOfPCConfig()[(Index)].TxBasicHwStartOfControllerConfig)
#define Can_30_Mcan_GetTxBasicHwStopOfControllerConfig(Index)                                       (Can_30_Mcan_GetControllerConfigOfPCConfig()[(Index)].TxBasicHwStopOfControllerConfig)
#define Can_30_Mcan_GetTxFullHwStartOfControllerConfig(Index)                                       (Can_30_Mcan_GetControllerConfigOfPCConfig()[(Index)].TxFullHwStartOfControllerConfig)
#define Can_30_Mcan_GetTxFullHwStopOfControllerConfig(Index)                                        (Can_30_Mcan_GetControllerConfigOfPCConfig()[(Index)].TxFullHwStopOfControllerConfig)
#define Can_30_Mcan_GetUnusedHwStartOfControllerConfig(Index)                                       (Can_30_Mcan_GetControllerConfigOfPCConfig()[(Index)].UnusedHwStartOfControllerConfig)
#define Can_30_Mcan_GetUnusedHwStopOfControllerConfig(Index)                                        (Can_30_Mcan_GetControllerConfigOfPCConfig()[(Index)].UnusedHwStopOfControllerConfig)
#define Can_30_Mcan_GetBusOffNotificationOfControllerData(Index)                                    (Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].BusOffNotificationOfControllerData)
#define Can_30_Mcan_GetBusOffTransitionRequestOfControllerData(Index)                               (Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].BusOffTransitionRequestOfControllerData)
#define Can_30_Mcan_GetCanInterruptCounterOfControllerData(Index)                                   (Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].CanInterruptCounterOfControllerData)
#define Can_30_Mcan_GetCanInterruptOldStatusOfControllerData(Index)                                 (Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].CanInterruptOldStatusOfControllerData)
#define Can_30_Mcan_GetIntEnableOfControllerData(Index)                                             (Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].IntEnableOfControllerData)
#define Can_30_Mcan_IsIsBusOffOfControllerData(Index)                                               ((Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].IsBusOffOfControllerData) != FALSE)
#define Can_30_Mcan_GetLastInitObjectOfControllerData(Index)                                        (Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].LastInitObjectOfControllerData)
#define Can_30_Mcan_GetLastStateOfControllerData(Index)                                             (Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].LastStateOfControllerData)
#define Can_30_Mcan_GetLogStatusOfControllerData(Index)                                             (Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].LogStatusOfControllerData)
#define Can_30_Mcan_GetLoopTimeoutOfControllerData(Index)                                           (Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].LoopTimeoutOfControllerData)
#define Can_30_Mcan_GetModeTransitionRequestOfControllerData(Index)                                 (Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].ModeTransitionRequestOfControllerData)
#define Can_30_Mcan_GetNonFdObjectsPendingFlagOfControllerData(Index)                               (Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].NonFdObjectsPendingFlagOfControllerData)
#define Can_30_Mcan_GetPrevModeOfControllerData(Index)                                              (Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].PrevModeOfControllerData)
#define Can_30_Mcan_GetRamCheckTransitionRequestOfControllerData(Index)                             (Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].RamCheckTransitionRequestOfControllerData)
#define Can_30_Mcan_GetTXBCROfControllerData(Index)                                                 (Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].TXBCROfControllerData)
#define Can_30_Mcan_GetTXBRPOfControllerData(Index)                                                 (Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].TXBRPOfControllerData)
#define Can_30_Mcan_GetFBTP(Index)                                                                  (Can_30_Mcan_GetFBTPOfPCConfig()[(Index)])
#define Can_30_Mcan_GetGFC(Index)                                                                   (Can_30_Mcan_GetGFCOfPCConfig()[(Index)])
#define Can_30_Mcan_GetInitObjectBaudrate(Index)                                                    (Can_30_Mcan_GetInitObjectBaudrateOfPCConfig()[(Index)])
#define Can_30_Mcan_GetInitObjectFdBrsConfig(Index)                                                 (Can_30_Mcan_GetInitObjectFdBrsConfigOfPCConfig()[(Index)])
#define Can_30_Mcan_GetInitObjectStartIndex(Index)                                                  (Can_30_Mcan_GetInitObjectStartIndexOfPCConfig()[(Index)])
#define Can_30_Mcan_GetActiveSendObjectOfMailbox(Index)                                             (Can_30_Mcan_GetMailboxOfPCConfig()[(Index)].ActiveSendObjectOfMailbox)
#define Can_30_Mcan_GetControllerConfigIdxOfMailbox(Index)                                          (Can_30_Mcan_GetMailboxOfPCConfig()[(Index)].ControllerConfigIdxOfMailbox)
#define Can_30_Mcan_GetFdPaddingOfMailbox(Index)                                                    (Can_30_Mcan_GetMailboxOfPCConfig()[(Index)].FdPaddingOfMailbox)
#define Can_30_Mcan_GetHwHandleOfMailbox(Index)                                                     (Can_30_Mcan_GetMailboxOfPCConfig()[(Index)].HwHandleOfMailbox)
#define Can_30_Mcan_GetIDValueOfMailbox(Index)                                                      (Can_30_Mcan_GetMailboxOfPCConfig()[(Index)].IDValueOfMailbox)
#define Can_30_Mcan_GetMailboxSizeOfMailbox(Index)                                                  (Can_30_Mcan_GetMailboxOfPCConfig()[(Index)].MailboxSizeOfMailbox)
#define Can_30_Mcan_GetMailboxTypeOfMailbox(Index)                                                  (Can_30_Mcan_GetMailboxOfPCConfig()[(Index)].MailboxTypeOfMailbox)
#define Can_30_Mcan_GetMaxDataLenOfMailbox(Index)                                                   (Can_30_Mcan_GetMailboxOfPCConfig()[(Index)].MaxDataLenOfMailbox)
#define Can_30_Mcan_GetMemorySectionsIndexOfMailbox(Index)                                          (Can_30_Mcan_GetMailboxOfPCConfig()[(Index)].MemorySectionsIndexOfMailbox)
#define Can_30_Mcan_GetMailboxState(Index)                                                          (Can_30_Mcan_GetMailboxStateOfPCConfig()[(Index)])
#define Can_30_Mcan_GetMemorySectionStartOfMemorySectionInfo(Index)                                 (Can_30_Mcan_GetMemorySectionInfoOfPCConfig()[(Index)].MemorySectionStartOfMemorySectionInfo)
#define Can_30_Mcan_GetHwHandleOfMemorySectionObjects(Index)                                        (Can_30_Mcan_GetMemorySectionObjectsOfPCConfig()[(Index)].HwHandleOfMemorySectionObjects)
#define Can_30_Mcan_GetMailboxElementOfMemorySectionObjects(Index)                                  (Can_30_Mcan_GetMemorySectionObjectsOfPCConfig()[(Index)].MailboxElementOfMemorySectionObjects)
#define Can_30_Mcan_GetMailboxHandleOfMemorySectionObjects(Index)                                   (Can_30_Mcan_GetMemorySectionObjectsOfPCConfig()[(Index)].MailboxHandleOfMemorySectionObjects)
#define Can_30_Mcan_GetFLSSAOfSIDFC(Index)                                                          (Can_30_Mcan_GetSIDFCOfPCConfig()[(Index)].FLSSAOfSIDFC)
#define Can_30_Mcan_GetLSSOfSIDFC(Index)                                                            (Can_30_Mcan_GetSIDFCOfPCConfig()[(Index)].LSSOfSIDFC)
#define Can_30_Mcan_GetSIDFEEndIdxOfSIDFC(Index)                                                    (Can_30_Mcan_GetSIDFCOfPCConfig()[(Index)].SIDFEEndIdxOfSIDFC)
#define Can_30_Mcan_GetSIDFEStartIdxOfSIDFC(Index)                                                  (Can_30_Mcan_GetSIDFCOfPCConfig()[(Index)].SIDFEStartIdxOfSIDFC)
#define Can_30_Mcan_GetSIDFE(Index)                                                                 (Can_30_Mcan_GetSIDFEOfPCConfig()[(Index)])
#define Can_30_Mcan_GetRXBAOfShmAdr(Index)                                                          (Can_30_Mcan_GetShmAdrOfPCConfig()[(Index)].RXBAOfShmAdr)
#define Can_30_Mcan_GetRXF0AOfShmAdr(Index)                                                         (Can_30_Mcan_GetShmAdrOfPCConfig()[(Index)].RXF0AOfShmAdr)
#define Can_30_Mcan_GetRXF1AOfShmAdr(Index)                                                         (Can_30_Mcan_GetShmAdrOfPCConfig()[(Index)].RXF1AOfShmAdr)
#define Can_30_Mcan_GetSIDFAOfShmAdr(Index)                                                         (Can_30_Mcan_GetShmAdrOfPCConfig()[(Index)].SIDFAOfShmAdr)
#define Can_30_Mcan_GetStartAdrOfShmAdr(Index)                                                      (Can_30_Mcan_GetShmAdrOfPCConfig()[(Index)].StartAdrOfShmAdr)
#define Can_30_Mcan_GetStopAdrOfShmAdr(Index)                                                       (Can_30_Mcan_GetShmAdrOfPCConfig()[(Index)].StopAdrOfShmAdr)
#define Can_30_Mcan_GetTXBAOfShmAdr(Index)                                                          (Can_30_Mcan_GetShmAdrOfPCConfig()[(Index)].TXBAOfShmAdr)
#define Can_30_Mcan_GetTXEFAOfShmAdr(Index)                                                         (Can_30_Mcan_GetShmAdrOfPCConfig()[(Index)].TXEFAOfShmAdr)
#define Can_30_Mcan_GetXIDFAOfShmAdr(Index)                                                         (Can_30_Mcan_GetShmAdrOfPCConfig()[(Index)].XIDFAOfShmAdr)
#define Can_30_Mcan_GetF0DSOfShmElementSize(Index)                                                  (Can_30_Mcan_GetShmElementSizeOfPCConfig()[(Index)].F0DSOfShmElementSize)
#define Can_30_Mcan_GetF1DSOfShmElementSize(Index)                                                  (Can_30_Mcan_GetShmElementSizeOfPCConfig()[(Index)].F1DSOfShmElementSize)
#define Can_30_Mcan_GetRBDSOfShmElementSize(Index)                                                  (Can_30_Mcan_GetShmElementSizeOfPCConfig()[(Index)].RBDSOfShmElementSize)
#define Can_30_Mcan_GetTBDSOfShmElementSize(Index)                                                  (Can_30_Mcan_GetShmElementSizeOfPCConfig()[(Index)].TBDSOfShmElementSize)
#define Can_30_Mcan_GetTEFBDSOfShmElementSize(Index)                                                (Can_30_Mcan_GetShmElementSizeOfPCConfig()[(Index)].TEFBDSOfShmElementSize)
#define Can_30_Mcan_GetTDCR(Index)                                                                  (Can_30_Mcan_GetTDCROfPCConfig()[(Index)])
#define Can_30_Mcan_GetXIDAM(Index)                                                                 (Can_30_Mcan_GetXIDAMOfPCConfig()[(Index)])
#define Can_30_Mcan_GetFLESAOfXIDFC(Index)                                                          (Can_30_Mcan_GetXIDFCOfPCConfig()[(Index)].FLESAOfXIDFC)
#define Can_30_Mcan_GetLSEOfXIDFC(Index)                                                            (Can_30_Mcan_GetXIDFCOfPCConfig()[(Index)].LSEOfXIDFC)
#define Can_30_Mcan_GetXIDFEEndIdxOfXIDFC(Index)                                                    (Can_30_Mcan_GetXIDFCOfPCConfig()[(Index)].XIDFEEndIdxOfXIDFC)
#define Can_30_Mcan_GetXIDFEStartIdxOfXIDFC(Index)                                                  (Can_30_Mcan_GetXIDFCOfPCConfig()[(Index)].XIDFEStartIdxOfXIDFC)
#define Can_30_Mcan_GetEIDFE_0OfXIDFE(Index)                                                        (Can_30_Mcan_GetXIDFEOfPCConfig()[(Index)].EIDFE_0OfXIDFE)
#define Can_30_Mcan_GetEIDFE_1OfXIDFE(Index)                                                        (Can_30_Mcan_GetXIDFEOfPCConfig()[(Index)].EIDFE_1OfXIDFE)
/** 
  \}
*/ 

/** 
  \defgroup  Can_30_McanPCGetDeduplicatedDataMacros  Can_30_Mcan Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Can_30_Mcan_GetBaseDll_GeneratorVersion()                                                   Can_30_Mcan_GetBaseDll_GeneratorVersionOfPCConfig()
#define Can_30_Mcan_GetCAN_FD_NISO()                                                                Can_30_Mcan_GetCAN_FD_NISOOfPCConfig()
#define Can_30_Mcan_GetC_ENABLE_MPC5700_MCAN_CREL_SSTEP()                                           Can_30_Mcan_GetC_ENABLE_MPC5700_MCAN_CREL_SSTEPOfPCConfig()
#define Can_30_Mcan_GetC_ENABLE_MPC5700_MCAN_CREL_STEP()                                            Can_30_Mcan_GetC_ENABLE_MPC5700_MCAN_CREL_STEPOfPCConfig()
#define Can_30_Mcan_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL()                                           Can_30_Mcan_GetC_ENABLE_MPC5700_MCAN_MAJOR_CRELOfPCConfig()
#define Can_30_Mcan_IsMailboxRxBasicUsedOfControllerConfig(Index)                                   (((boolean)(Can_30_Mcan_GetMailboxRxBasicLengthOfControllerConfig(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Can_30_Mcan_Mailbox */
#define Can_30_Mcan_IsMailboxTxBasicUsedOfControllerConfig(Index)                                   (((boolean)(Can_30_Mcan_GetMailboxTxBasicLengthOfControllerConfig(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Can_30_Mcan_Mailbox */
#define Can_30_Mcan_GetPlatformDll_GeneratorVersion()                                               Can_30_Mcan_GetPlatformDll_GeneratorVersionOfPCConfig()
#define Can_30_Mcan_IsSIDFEUsedOfSIDFC(Index)                                                       (((boolean)(Can_30_Mcan_GetSIDFEStartIdxOfSIDFC(Index) != CAN_30_MCAN_NO_SIDFESTARTIDXOFSIDFC)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Can_30_Mcan_SIDFE */
#define Can_30_Mcan_GetSizeOfActiveSendObject()                                                     Can_30_Mcan_GetSizeOfActiveSendObjectOfPCConfig()
#define Can_30_Mcan_GetSizeOfBTP()                                                                  Can_30_Mcan_GetSizeOfBTPOfPCConfig()
#define Can_30_Mcan_GetSizeOfBufferConfig()                                                         Can_30_Mcan_GetSizeOfBufferConfigOfPCConfig()
#define Can_30_Mcan_GetSizeOfCanEccAggrBaseAddr()                                                   Can_30_Mcan_GetSizeOfCanEccAggrBaseAddrOfPCConfig()
#define Can_30_Mcan_GetSizeOfCanIfChannelId()                                                       Can_30_Mcan_GetSizeOfCanIfChannelIdOfPCConfig()
#define Can_30_Mcan_GetSizeOfCanMcanSsBaseAddr()                                                    Can_30_Mcan_GetSizeOfCanMcanSsBaseAddrOfPCConfig()
#define Can_30_Mcan_GetSizeOfControllerConfig()                                                     Can_30_Mcan_GetSizeOfControllerConfigOfPCConfig()
#define Can_30_Mcan_GetSizeOfControllerData()                                                       Can_30_Mcan_GetSizeOfControllerDataOfPCConfig()
#define Can_30_Mcan_GetSizeOfFBTP()                                                                 Can_30_Mcan_GetSizeOfFBTPOfPCConfig()
#define Can_30_Mcan_GetSizeOfGFC()                                                                  Can_30_Mcan_GetSizeOfGFCOfPCConfig()
#define Can_30_Mcan_GetSizeOfInitObjectBaudrate()                                                   Can_30_Mcan_GetSizeOfInitObjectBaudrateOfPCConfig()
#define Can_30_Mcan_GetSizeOfInitObjectFdBrsConfig()                                                Can_30_Mcan_GetSizeOfInitObjectFdBrsConfigOfPCConfig()
#define Can_30_Mcan_GetSizeOfInitObjectStartIndex()                                                 Can_30_Mcan_GetSizeOfInitObjectStartIndexOfPCConfig()
#define Can_30_Mcan_GetSizeOfMailbox()                                                              Can_30_Mcan_GetSizeOfMailboxOfPCConfig()
#define Can_30_Mcan_GetSizeOfMailboxState()                                                         Can_30_Mcan_GetSizeOfMailboxStateOfPCConfig()
#define Can_30_Mcan_GetSizeOfMemorySectionInfo()                                                    Can_30_Mcan_GetSizeOfMemorySectionInfoOfPCConfig()
#define Can_30_Mcan_GetSizeOfMemorySectionObjects()                                                 Can_30_Mcan_GetSizeOfMemorySectionObjectsOfPCConfig()
#define Can_30_Mcan_GetSizeOfSIDFC()                                                                Can_30_Mcan_GetSizeOfSIDFCOfPCConfig()
#define Can_30_Mcan_GetSizeOfSIDFE()                                                                Can_30_Mcan_GetSizeOfSIDFEOfPCConfig()
#define Can_30_Mcan_GetSizeOfShmAdr()                                                               Can_30_Mcan_GetSizeOfShmAdrOfPCConfig()
#define Can_30_Mcan_GetSizeOfShmElementSize()                                                       Can_30_Mcan_GetSizeOfShmElementSizeOfPCConfig()
#define Can_30_Mcan_GetSizeOfTDCR()                                                                 Can_30_Mcan_GetSizeOfTDCROfPCConfig()
#define Can_30_Mcan_GetSizeOfXIDAM()                                                                Can_30_Mcan_GetSizeOfXIDAMOfPCConfig()
#define Can_30_Mcan_GetSizeOfXIDFC()                                                                Can_30_Mcan_GetSizeOfXIDFCOfPCConfig()
#define Can_30_Mcan_GetSizeOfXIDFE()                                                                Can_30_Mcan_GetSizeOfXIDFEOfPCConfig()
#define Can_30_Mcan_IsXIDFEUsedOfXIDFC(Index)                                                       (((boolean)(Can_30_Mcan_GetXIDFEStartIdxOfXIDFC(Index) != CAN_30_MCAN_NO_XIDFESTARTIDXOFXIDFC)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Can_30_Mcan_XIDFE */
/** 
  \}
*/ 

/** 
  \defgroup  Can_30_McanPCSetDataMacros  Can_30_Mcan Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define Can_30_Mcan_SetPduOfActiveSendObject(Index, Value)                                          Can_30_Mcan_GetActiveSendObjectOfPCConfig()[(Index)].PduOfActiveSendObject = (Value)
#define Can_30_Mcan_SetStateOfActiveSendObject(Index, Value)                                        Can_30_Mcan_GetActiveSendObjectOfPCConfig()[(Index)].StateOfActiveSendObject = (Value)
#define Can_30_Mcan_SetBusOffNotificationOfControllerData(Index, Value)                             Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].BusOffNotificationOfControllerData = (Value)
#define Can_30_Mcan_SetBusOffTransitionRequestOfControllerData(Index, Value)                        Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].BusOffTransitionRequestOfControllerData = (Value)
#define Can_30_Mcan_SetCanInterruptCounterOfControllerData(Index, Value)                            Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].CanInterruptCounterOfControllerData = (Value)
#define Can_30_Mcan_SetCanInterruptOldStatusOfControllerData(Index, Value)                          Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].CanInterruptOldStatusOfControllerData = (Value)
#define Can_30_Mcan_SetIntEnableOfControllerData(Index, Value)                                      Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].IntEnableOfControllerData = (Value)
#define Can_30_Mcan_SetIsBusOffOfControllerData(Index, Value)                                       Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].IsBusOffOfControllerData = (Value)
#define Can_30_Mcan_SetLastInitObjectOfControllerData(Index, Value)                                 Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].LastInitObjectOfControllerData = (Value)
#define Can_30_Mcan_SetLastStateOfControllerData(Index, Value)                                      Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].LastStateOfControllerData = (Value)
#define Can_30_Mcan_SetLogStatusOfControllerData(Index, Value)                                      Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].LogStatusOfControllerData = (Value)
#define Can_30_Mcan_SetLoopTimeoutOfControllerData(Index, Value)                                    Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].LoopTimeoutOfControllerData = (Value)
#define Can_30_Mcan_SetModeTransitionRequestOfControllerData(Index, Value)                          Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].ModeTransitionRequestOfControllerData = (Value)
#define Can_30_Mcan_SetNonFdObjectsPendingFlagOfControllerData(Index, Value)                        Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].NonFdObjectsPendingFlagOfControllerData = (Value)
#define Can_30_Mcan_SetPrevModeOfControllerData(Index, Value)                                       Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].PrevModeOfControllerData = (Value)
#define Can_30_Mcan_SetRamCheckTransitionRequestOfControllerData(Index, Value)                      Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].RamCheckTransitionRequestOfControllerData = (Value)
#define Can_30_Mcan_SetTXBCROfControllerData(Index, Value)                                          Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].TXBCROfControllerData = (Value)
#define Can_30_Mcan_SetTXBRPOfControllerData(Index, Value)                                          Can_30_Mcan_GetControllerDataOfPCConfig()[(Index)].TXBRPOfControllerData = (Value)
#define Can_30_Mcan_SetMailboxState(Index, Value)                                                   Can_30_Mcan_GetMailboxStateOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  Can_30_McanPCHasMacros  Can_30_Mcan Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Can_30_Mcan_HasActiveSendObject()                                                           (TRUE != FALSE)
#define Can_30_Mcan_HasPduOfActiveSendObject()                                                      (TRUE != FALSE)
#define Can_30_Mcan_HasStateOfActiveSendObject()                                                    (TRUE != FALSE)
#define Can_30_Mcan_HasBTP()                                                                        (TRUE != FALSE)
#define Can_30_Mcan_HasBaseDll_GeneratorVersion()                                                   (TRUE != FALSE)
#define Can_30_Mcan_HasBufferConfig()                                                               (TRUE != FALSE)
#define Can_30_Mcan_HasRXBCOfBufferConfig()                                                         (TRUE != FALSE)
#define Can_30_Mcan_HasRXF0COfBufferConfig()                                                        (TRUE != FALSE)
#define Can_30_Mcan_HasRXF1COfBufferConfig()                                                        (TRUE != FALSE)
#define Can_30_Mcan_HasTXBCOfBufferConfig()                                                         (TRUE != FALSE)
#define Can_30_Mcan_HasTXEFCOfBufferConfig()                                                        (TRUE != FALSE)
#define Can_30_Mcan_HasCAN_FD_NISO()                                                                (TRUE != FALSE)
#define Can_30_Mcan_HasC_ENABLE_MPC5700_MCAN_CREL_SSTEP()                                           (TRUE != FALSE)
#define Can_30_Mcan_HasC_ENABLE_MPC5700_MCAN_CREL_STEP()                                            (TRUE != FALSE)
#define Can_30_Mcan_HasC_ENABLE_MPC5700_MCAN_MAJOR_CREL()                                           (TRUE != FALSE)
#define Can_30_Mcan_HasCanEccAggrBaseAddr()                                                         (TRUE != FALSE)
#define Can_30_Mcan_HasCanIfChannelId()                                                             (TRUE != FALSE)
#define Can_30_Mcan_HasCanMcanSsBaseAddr()                                                          (TRUE != FALSE)
#define Can_30_Mcan_HasControllerConfig()                                                           (TRUE != FALSE)
#define Can_30_Mcan_HasBasisAdrOfControllerConfig()                                                 (TRUE != FALSE)
#define Can_30_Mcan_HasCanControllerDefaultBaudrateIdxOfControllerConfig()                          (TRUE != FALSE)
#define Can_30_Mcan_HasCanControllerDefaultBaudrateOfControllerConfig()                             (TRUE != FALSE)
#define Can_30_Mcan_HasIsTTCanOfControllerConfig()                                                  (TRUE != FALSE)
#define Can_30_Mcan_HasMailboxRxBasicEndIdxOfControllerConfig()                                     (TRUE != FALSE)
#define Can_30_Mcan_HasMailboxRxBasicLengthOfControllerConfig()                                     (TRUE != FALSE)
#define Can_30_Mcan_HasMailboxRxBasicStartIdxOfControllerConfig()                                   (TRUE != FALSE)
#define Can_30_Mcan_HasMailboxRxBasicUsedOfControllerConfig()                                       (TRUE != FALSE)
#define Can_30_Mcan_HasMailboxTxBasicEndIdxOfControllerConfig()                                     (TRUE != FALSE)
#define Can_30_Mcan_HasMailboxTxBasicLengthOfControllerConfig()                                     (TRUE != FALSE)
#define Can_30_Mcan_HasMailboxTxBasicStartIdxOfControllerConfig()                                   (TRUE != FALSE)
#define Can_30_Mcan_HasMailboxTxBasicUsedOfControllerConfig()                                       (TRUE != FALSE)
#define Can_30_Mcan_HasRxBasicHwStartOfControllerConfig()                                           (TRUE != FALSE)
#define Can_30_Mcan_HasRxBasicHwStopOfControllerConfig()                                            (TRUE != FALSE)
#define Can_30_Mcan_HasRxFullHwStartOfControllerConfig()                                            (TRUE != FALSE)
#define Can_30_Mcan_HasRxFullHwStopOfControllerConfig()                                             (TRUE != FALSE)
#define Can_30_Mcan_HasTxBasicHwStartOfControllerConfig()                                           (TRUE != FALSE)
#define Can_30_Mcan_HasTxBasicHwStopOfControllerConfig()                                            (TRUE != FALSE)
#define Can_30_Mcan_HasTxFullHwStartOfControllerConfig()                                            (TRUE != FALSE)
#define Can_30_Mcan_HasTxFullHwStopOfControllerConfig()                                             (TRUE != FALSE)
#define Can_30_Mcan_HasUnusedHwStartOfControllerConfig()                                            (TRUE != FALSE)
#define Can_30_Mcan_HasUnusedHwStopOfControllerConfig()                                             (TRUE != FALSE)
#define Can_30_Mcan_HasControllerData()                                                             (TRUE != FALSE)
#define Can_30_Mcan_HasBusOffNotificationOfControllerData()                                         (TRUE != FALSE)
#define Can_30_Mcan_HasBusOffTransitionRequestOfControllerData()                                    (TRUE != FALSE)
#define Can_30_Mcan_HasCanInterruptCounterOfControllerData()                                        (TRUE != FALSE)
#define Can_30_Mcan_HasCanInterruptOldStatusOfControllerData()                                      (TRUE != FALSE)
#define Can_30_Mcan_HasIntEnableOfControllerData()                                                  (TRUE != FALSE)
#define Can_30_Mcan_HasIsBusOffOfControllerData()                                                   (TRUE != FALSE)
#define Can_30_Mcan_HasLastInitObjectOfControllerData()                                             (TRUE != FALSE)
#define Can_30_Mcan_HasLastStateOfControllerData()                                                  (TRUE != FALSE)
#define Can_30_Mcan_HasLogStatusOfControllerData()                                                  (TRUE != FALSE)
#define Can_30_Mcan_HasLoopTimeoutOfControllerData()                                                (TRUE != FALSE)
#define Can_30_Mcan_HasModeTransitionRequestOfControllerData()                                      (TRUE != FALSE)
#define Can_30_Mcan_HasNonFdObjectsPendingFlagOfControllerData()                                    (TRUE != FALSE)
#define Can_30_Mcan_HasPrevModeOfControllerData()                                                   (TRUE != FALSE)
#define Can_30_Mcan_HasRamCheckTransitionRequestOfControllerData()                                  (TRUE != FALSE)
#define Can_30_Mcan_HasTXBCROfControllerData()                                                      (TRUE != FALSE)
#define Can_30_Mcan_HasTXBRPOfControllerData()                                                      (TRUE != FALSE)
#define Can_30_Mcan_HasFBTP()                                                                       (TRUE != FALSE)
#define Can_30_Mcan_HasGFC()                                                                        (TRUE != FALSE)
#define Can_30_Mcan_HasInitObjectBaudrate()                                                         (TRUE != FALSE)
#define Can_30_Mcan_HasInitObjectFdBrsConfig()                                                      (TRUE != FALSE)
#define Can_30_Mcan_HasInitObjectStartIndex()                                                       (TRUE != FALSE)
#define Can_30_Mcan_HasMailbox()                                                                    (TRUE != FALSE)
#define Can_30_Mcan_HasActiveSendObjectOfMailbox()                                                  (TRUE != FALSE)
#define Can_30_Mcan_HasControllerConfigIdxOfMailbox()                                               (TRUE != FALSE)
#define Can_30_Mcan_HasFdPaddingOfMailbox()                                                         (TRUE != FALSE)
#define Can_30_Mcan_HasHwHandleOfMailbox()                                                          (TRUE != FALSE)
#define Can_30_Mcan_HasIDValueOfMailbox()                                                           (TRUE != FALSE)
#define Can_30_Mcan_HasMailboxSizeOfMailbox()                                                       (TRUE != FALSE)
#define Can_30_Mcan_HasMailboxTypeOfMailbox()                                                       (TRUE != FALSE)
#define Can_30_Mcan_HasMaxDataLenOfMailbox()                                                        (TRUE != FALSE)
#define Can_30_Mcan_HasMemorySectionsIndexOfMailbox()                                               (TRUE != FALSE)
#define Can_30_Mcan_HasMailboxState()                                                               (TRUE != FALSE)
#define Can_30_Mcan_HasMemorySectionInfo()                                                          (TRUE != FALSE)
#define Can_30_Mcan_HasMemorySectionStartOfMemorySectionInfo()                                      (TRUE != FALSE)
#define Can_30_Mcan_HasMemorySectionObjects()                                                       (TRUE != FALSE)
#define Can_30_Mcan_HasHwHandleOfMemorySectionObjects()                                             (TRUE != FALSE)
#define Can_30_Mcan_HasMailboxElementOfMemorySectionObjects()                                       (TRUE != FALSE)
#define Can_30_Mcan_HasMailboxHandleOfMemorySectionObjects()                                        (TRUE != FALSE)
#define Can_30_Mcan_HasPlatformDll_GeneratorVersion()                                               (TRUE != FALSE)
#define Can_30_Mcan_HasSIDFC()                                                                      (TRUE != FALSE)
#define Can_30_Mcan_HasFLSSAOfSIDFC()                                                               (TRUE != FALSE)
#define Can_30_Mcan_HasLSSOfSIDFC()                                                                 (TRUE != FALSE)
#define Can_30_Mcan_HasSIDFEEndIdxOfSIDFC()                                                         (TRUE != FALSE)
#define Can_30_Mcan_HasSIDFEStartIdxOfSIDFC()                                                       (TRUE != FALSE)
#define Can_30_Mcan_HasSIDFEUsedOfSIDFC()                                                           (TRUE != FALSE)
#define Can_30_Mcan_HasSIDFE()                                                                      (TRUE != FALSE)
#define Can_30_Mcan_HasShmAdr()                                                                     (TRUE != FALSE)
#define Can_30_Mcan_HasRXBAOfShmAdr()                                                               (TRUE != FALSE)
#define Can_30_Mcan_HasRXF0AOfShmAdr()                                                              (TRUE != FALSE)
#define Can_30_Mcan_HasRXF1AOfShmAdr()                                                              (TRUE != FALSE)
#define Can_30_Mcan_HasSIDFAOfShmAdr()                                                              (TRUE != FALSE)
#define Can_30_Mcan_HasStartAdrOfShmAdr()                                                           (TRUE != FALSE)
#define Can_30_Mcan_HasStopAdrOfShmAdr()                                                            (TRUE != FALSE)
#define Can_30_Mcan_HasTXBAOfShmAdr()                                                               (TRUE != FALSE)
#define Can_30_Mcan_HasTXEFAOfShmAdr()                                                              (TRUE != FALSE)
#define Can_30_Mcan_HasXIDFAOfShmAdr()                                                              (TRUE != FALSE)
#define Can_30_Mcan_HasShmElementSize()                                                             (TRUE != FALSE)
#define Can_30_Mcan_HasF0DSOfShmElementSize()                                                       (TRUE != FALSE)
#define Can_30_Mcan_HasF1DSOfShmElementSize()                                                       (TRUE != FALSE)
#define Can_30_Mcan_HasRBDSOfShmElementSize()                                                       (TRUE != FALSE)
#define Can_30_Mcan_HasTBDSOfShmElementSize()                                                       (TRUE != FALSE)
#define Can_30_Mcan_HasTEFBDSOfShmElementSize()                                                     (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfActiveSendObject()                                                     (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfBTP()                                                                  (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfBufferConfig()                                                         (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfCanEccAggrBaseAddr()                                                   (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfCanIfChannelId()                                                       (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfCanMcanSsBaseAddr()                                                    (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfControllerConfig()                                                     (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfControllerData()                                                       (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfFBTP()                                                                 (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfGFC()                                                                  (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfInitObjectBaudrate()                                                   (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfInitObjectFdBrsConfig()                                                (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfInitObjectStartIndex()                                                 (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfMailbox()                                                              (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfMailboxState()                                                         (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfMemorySectionInfo()                                                    (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfMemorySectionObjects()                                                 (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfSIDFC()                                                                (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfSIDFE()                                                                (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfShmAdr()                                                               (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfShmElementSize()                                                       (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfTDCR()                                                                 (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfXIDAM()                                                                (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfXIDFC()                                                                (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfXIDFE()                                                                (TRUE != FALSE)
#define Can_30_Mcan_HasTDCR()                                                                       (TRUE != FALSE)
#define Can_30_Mcan_HasXIDAM()                                                                      (TRUE != FALSE)
#define Can_30_Mcan_HasXIDFC()                                                                      (TRUE != FALSE)
#define Can_30_Mcan_HasFLESAOfXIDFC()                                                               (TRUE != FALSE)
#define Can_30_Mcan_HasLSEOfXIDFC()                                                                 (TRUE != FALSE)
#define Can_30_Mcan_HasXIDFEEndIdxOfXIDFC()                                                         (TRUE != FALSE)
#define Can_30_Mcan_HasXIDFEStartIdxOfXIDFC()                                                       (TRUE != FALSE)
#define Can_30_Mcan_HasXIDFEUsedOfXIDFC()                                                           (TRUE != FALSE)
#define Can_30_Mcan_HasXIDFE()                                                                      (TRUE != FALSE)
#define Can_30_Mcan_HasEIDFE_0OfXIDFE()                                                             (TRUE != FALSE)
#define Can_30_Mcan_HasEIDFE_1OfXIDFE()                                                             (TRUE != FALSE)
#define Can_30_Mcan_HasPCConfig()                                                                   (TRUE != FALSE)
#define Can_30_Mcan_HasActiveSendObjectOfPCConfig()                                                 (TRUE != FALSE)
#define Can_30_Mcan_HasBTPOfPCConfig()                                                              (TRUE != FALSE)
#define Can_30_Mcan_HasBaseDll_GeneratorVersionOfPCConfig()                                         (TRUE != FALSE)
#define Can_30_Mcan_HasBufferConfigOfPCConfig()                                                     (TRUE != FALSE)
#define Can_30_Mcan_HasCAN_FD_NISOOfPCConfig()                                                      (TRUE != FALSE)
#define Can_30_Mcan_HasC_ENABLE_MPC5700_MCAN_CREL_SSTEPOfPCConfig()                                 (TRUE != FALSE)
#define Can_30_Mcan_HasC_ENABLE_MPC5700_MCAN_CREL_STEPOfPCConfig()                                  (TRUE != FALSE)
#define Can_30_Mcan_HasC_ENABLE_MPC5700_MCAN_MAJOR_CRELOfPCConfig()                                 (TRUE != FALSE)
#define Can_30_Mcan_HasCanEccAggrBaseAddrOfPCConfig()                                               (TRUE != FALSE)
#define Can_30_Mcan_HasCanIfChannelIdOfPCConfig()                                                   (TRUE != FALSE)
#define Can_30_Mcan_HasCanMcanSsBaseAddrOfPCConfig()                                                (TRUE != FALSE)
#define Can_30_Mcan_HasControllerConfigOfPCConfig()                                                 (TRUE != FALSE)
#define Can_30_Mcan_HasControllerDataOfPCConfig()                                                   (TRUE != FALSE)
#define Can_30_Mcan_HasFBTPOfPCConfig()                                                             (TRUE != FALSE)
#define Can_30_Mcan_HasGFCOfPCConfig()                                                              (TRUE != FALSE)
#define Can_30_Mcan_HasInitObjectBaudrateOfPCConfig()                                               (TRUE != FALSE)
#define Can_30_Mcan_HasInitObjectFdBrsConfigOfPCConfig()                                            (TRUE != FALSE)
#define Can_30_Mcan_HasInitObjectStartIndexOfPCConfig()                                             (TRUE != FALSE)
#define Can_30_Mcan_HasMailboxOfPCConfig()                                                          (TRUE != FALSE)
#define Can_30_Mcan_HasMailboxStateOfPCConfig()                                                     (TRUE != FALSE)
#define Can_30_Mcan_HasMemorySectionInfoOfPCConfig()                                                (TRUE != FALSE)
#define Can_30_Mcan_HasMemorySectionObjectsOfPCConfig()                                             (TRUE != FALSE)
#define Can_30_Mcan_HasPlatformDll_GeneratorVersionOfPCConfig()                                     (TRUE != FALSE)
#define Can_30_Mcan_HasSIDFCOfPCConfig()                                                            (TRUE != FALSE)
#define Can_30_Mcan_HasSIDFEOfPCConfig()                                                            (TRUE != FALSE)
#define Can_30_Mcan_HasShmAdrOfPCConfig()                                                           (TRUE != FALSE)
#define Can_30_Mcan_HasShmElementSizeOfPCConfig()                                                   (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfActiveSendObjectOfPCConfig()                                           (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfBTPOfPCConfig()                                                        (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfBufferConfigOfPCConfig()                                               (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfCanEccAggrBaseAddrOfPCConfig()                                         (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfCanIfChannelIdOfPCConfig()                                             (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfCanMcanSsBaseAddrOfPCConfig()                                          (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfControllerConfigOfPCConfig()                                           (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfControllerDataOfPCConfig()                                             (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfFBTPOfPCConfig()                                                       (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfGFCOfPCConfig()                                                        (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfInitObjectBaudrateOfPCConfig()                                         (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfInitObjectFdBrsConfigOfPCConfig()                                      (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfInitObjectStartIndexOfPCConfig()                                       (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfMailboxOfPCConfig()                                                    (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfMailboxStateOfPCConfig()                                               (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfMemorySectionInfoOfPCConfig()                                          (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfMemorySectionObjectsOfPCConfig()                                       (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfSIDFCOfPCConfig()                                                      (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfSIDFEOfPCConfig()                                                      (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfShmAdrOfPCConfig()                                                     (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfShmElementSizeOfPCConfig()                                             (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfTDCROfPCConfig()                                                       (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfXIDAMOfPCConfig()                                                      (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfXIDFCOfPCConfig()                                                      (TRUE != FALSE)
#define Can_30_Mcan_HasSizeOfXIDFEOfPCConfig()                                                      (TRUE != FALSE)
#define Can_30_Mcan_HasTDCROfPCConfig()                                                             (TRUE != FALSE)
#define Can_30_Mcan_HasXIDAMOfPCConfig()                                                            (TRUE != FALSE)
#define Can_30_Mcan_HasXIDFCOfPCConfig()                                                            (TRUE != FALSE)
#define Can_30_Mcan_HasXIDFEOfPCConfig()                                                            (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  Can_30_McanPCIncrementDataMacros  Can_30_Mcan Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define Can_30_Mcan_IncPduOfActiveSendObject(Index)                                                 Can_30_Mcan_GetPduOfActiveSendObject(Index)++
#define Can_30_Mcan_IncStateOfActiveSendObject(Index)                                               Can_30_Mcan_GetStateOfActiveSendObject(Index)++
#define Can_30_Mcan_IncBusOffNotificationOfControllerData(Index)                                    Can_30_Mcan_GetBusOffNotificationOfControllerData(Index)++
#define Can_30_Mcan_IncBusOffTransitionRequestOfControllerData(Index)                               Can_30_Mcan_GetBusOffTransitionRequestOfControllerData(Index)++
#define Can_30_Mcan_IncCanInterruptCounterOfControllerData(Index)                                   Can_30_Mcan_GetCanInterruptCounterOfControllerData(Index)++
#define Can_30_Mcan_IncCanInterruptOldStatusOfControllerData(Index)                                 Can_30_Mcan_GetCanInterruptOldStatusOfControllerData(Index)++
#define Can_30_Mcan_IncIntEnableOfControllerData(Index)                                             Can_30_Mcan_GetIntEnableOfControllerData(Index)++
#define Can_30_Mcan_IncLastInitObjectOfControllerData(Index)                                        Can_30_Mcan_GetLastInitObjectOfControllerData(Index)++
#define Can_30_Mcan_IncLastStateOfControllerData(Index)                                             Can_30_Mcan_GetLastStateOfControllerData(Index)++
#define Can_30_Mcan_IncLogStatusOfControllerData(Index)                                             Can_30_Mcan_GetLogStatusOfControllerData(Index)++
#define Can_30_Mcan_IncLoopTimeoutOfControllerData(Index)                                           Can_30_Mcan_GetLoopTimeoutOfControllerData(Index)++
#define Can_30_Mcan_IncModeTransitionRequestOfControllerData(Index)                                 Can_30_Mcan_GetModeTransitionRequestOfControllerData(Index)++
#define Can_30_Mcan_IncNonFdObjectsPendingFlagOfControllerData(Index)                               Can_30_Mcan_GetNonFdObjectsPendingFlagOfControllerData(Index)++
#define Can_30_Mcan_IncPrevModeOfControllerData(Index)                                              Can_30_Mcan_GetPrevModeOfControllerData(Index)++
#define Can_30_Mcan_IncRamCheckTransitionRequestOfControllerData(Index)                             Can_30_Mcan_GetRamCheckTransitionRequestOfControllerData(Index)++
#define Can_30_Mcan_IncTXBCROfControllerData(Index)                                                 Can_30_Mcan_GetTXBCROfControllerData(Index)++
#define Can_30_Mcan_IncTXBRPOfControllerData(Index)                                                 Can_30_Mcan_GetTXBRPOfControllerData(Index)++
#define Can_30_Mcan_IncMailboxState(Index)                                                          Can_30_Mcan_GetMailboxState(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  Can_30_McanPCDecrementDataMacros  Can_30_Mcan Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define Can_30_Mcan_DecPduOfActiveSendObject(Index)                                                 Can_30_Mcan_GetPduOfActiveSendObject(Index)--
#define Can_30_Mcan_DecStateOfActiveSendObject(Index)                                               Can_30_Mcan_GetStateOfActiveSendObject(Index)--
#define Can_30_Mcan_DecBusOffNotificationOfControllerData(Index)                                    Can_30_Mcan_GetBusOffNotificationOfControllerData(Index)--
#define Can_30_Mcan_DecBusOffTransitionRequestOfControllerData(Index)                               Can_30_Mcan_GetBusOffTransitionRequestOfControllerData(Index)--
#define Can_30_Mcan_DecCanInterruptCounterOfControllerData(Index)                                   Can_30_Mcan_GetCanInterruptCounterOfControllerData(Index)--
#define Can_30_Mcan_DecCanInterruptOldStatusOfControllerData(Index)                                 Can_30_Mcan_GetCanInterruptOldStatusOfControllerData(Index)--
#define Can_30_Mcan_DecIntEnableOfControllerData(Index)                                             Can_30_Mcan_GetIntEnableOfControllerData(Index)--
#define Can_30_Mcan_DecLastInitObjectOfControllerData(Index)                                        Can_30_Mcan_GetLastInitObjectOfControllerData(Index)--
#define Can_30_Mcan_DecLastStateOfControllerData(Index)                                             Can_30_Mcan_GetLastStateOfControllerData(Index)--
#define Can_30_Mcan_DecLogStatusOfControllerData(Index)                                             Can_30_Mcan_GetLogStatusOfControllerData(Index)--
#define Can_30_Mcan_DecLoopTimeoutOfControllerData(Index)                                           Can_30_Mcan_GetLoopTimeoutOfControllerData(Index)--
#define Can_30_Mcan_DecModeTransitionRequestOfControllerData(Index)                                 Can_30_Mcan_GetModeTransitionRequestOfControllerData(Index)--
#define Can_30_Mcan_DecNonFdObjectsPendingFlagOfControllerData(Index)                               Can_30_Mcan_GetNonFdObjectsPendingFlagOfControllerData(Index)--
#define Can_30_Mcan_DecPrevModeOfControllerData(Index)                                              Can_30_Mcan_GetPrevModeOfControllerData(Index)--
#define Can_30_Mcan_DecRamCheckTransitionRequestOfControllerData(Index)                             Can_30_Mcan_GetRamCheckTransitionRequestOfControllerData(Index)--
#define Can_30_Mcan_DecTXBCROfControllerData(Index)                                                 Can_30_Mcan_GetTXBCROfControllerData(Index)--
#define Can_30_Mcan_DecTXBRPOfControllerData(Index)                                                 Can_30_Mcan_GetTXBRPOfControllerData(Index)--
#define Can_30_Mcan_DecMailboxState(Index)                                                          Can_30_Mcan_GetMailboxState(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  Can_30_McanPCAddDataMacros  Can_30_Mcan Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define Can_30_Mcan_AddPduOfActiveSendObject(Index, Value)                                          Can_30_Mcan_SetPduOfActiveSendObject(Index, (Can_30_Mcan_GetPduOfActiveSendObject(Index) + Value))
#define Can_30_Mcan_AddStateOfActiveSendObject(Index, Value)                                        Can_30_Mcan_SetStateOfActiveSendObject(Index, (Can_30_Mcan_GetStateOfActiveSendObject(Index) + Value))
#define Can_30_Mcan_AddBusOffNotificationOfControllerData(Index, Value)                             Can_30_Mcan_SetBusOffNotificationOfControllerData(Index, (Can_30_Mcan_GetBusOffNotificationOfControllerData(Index) + Value))
#define Can_30_Mcan_AddBusOffTransitionRequestOfControllerData(Index, Value)                        Can_30_Mcan_SetBusOffTransitionRequestOfControllerData(Index, (Can_30_Mcan_GetBusOffTransitionRequestOfControllerData(Index) + Value))
#define Can_30_Mcan_AddCanInterruptCounterOfControllerData(Index, Value)                            Can_30_Mcan_SetCanInterruptCounterOfControllerData(Index, (Can_30_Mcan_GetCanInterruptCounterOfControllerData(Index) + Value))
#define Can_30_Mcan_AddCanInterruptOldStatusOfControllerData(Index, Value)                          Can_30_Mcan_SetCanInterruptOldStatusOfControllerData(Index, (Can_30_Mcan_GetCanInterruptOldStatusOfControllerData(Index) + Value))
#define Can_30_Mcan_AddIntEnableOfControllerData(Index, Value)                                      Can_30_Mcan_SetIntEnableOfControllerData(Index, (Can_30_Mcan_GetIntEnableOfControllerData(Index) + Value))
#define Can_30_Mcan_AddLastInitObjectOfControllerData(Index, Value)                                 Can_30_Mcan_SetLastInitObjectOfControllerData(Index, (Can_30_Mcan_GetLastInitObjectOfControllerData(Index) + Value))
#define Can_30_Mcan_AddLastStateOfControllerData(Index, Value)                                      Can_30_Mcan_SetLastStateOfControllerData(Index, (Can_30_Mcan_GetLastStateOfControllerData(Index) + Value))
#define Can_30_Mcan_AddLogStatusOfControllerData(Index, Value)                                      Can_30_Mcan_SetLogStatusOfControllerData(Index, (Can_30_Mcan_GetLogStatusOfControllerData(Index) + Value))
#define Can_30_Mcan_AddLoopTimeoutOfControllerData(Index, Value)                                    Can_30_Mcan_SetLoopTimeoutOfControllerData(Index, (Can_30_Mcan_GetLoopTimeoutOfControllerData(Index) + Value))
#define Can_30_Mcan_AddModeTransitionRequestOfControllerData(Index, Value)                          Can_30_Mcan_SetModeTransitionRequestOfControllerData(Index, (Can_30_Mcan_GetModeTransitionRequestOfControllerData(Index) + Value))
#define Can_30_Mcan_AddNonFdObjectsPendingFlagOfControllerData(Index, Value)                        Can_30_Mcan_SetNonFdObjectsPendingFlagOfControllerData(Index, (Can_30_Mcan_GetNonFdObjectsPendingFlagOfControllerData(Index) + Value))
#define Can_30_Mcan_AddPrevModeOfControllerData(Index, Value)                                       Can_30_Mcan_SetPrevModeOfControllerData(Index, (Can_30_Mcan_GetPrevModeOfControllerData(Index) + Value))
#define Can_30_Mcan_AddRamCheckTransitionRequestOfControllerData(Index, Value)                      Can_30_Mcan_SetRamCheckTransitionRequestOfControllerData(Index, (Can_30_Mcan_GetRamCheckTransitionRequestOfControllerData(Index) + Value))
#define Can_30_Mcan_AddTXBCROfControllerData(Index, Value)                                          Can_30_Mcan_SetTXBCROfControllerData(Index, (Can_30_Mcan_GetTXBCROfControllerData(Index) + Value))
#define Can_30_Mcan_AddTXBRPOfControllerData(Index, Value)                                          Can_30_Mcan_SetTXBRPOfControllerData(Index, (Can_30_Mcan_GetTXBRPOfControllerData(Index) + Value))
#define Can_30_Mcan_AddMailboxState(Index, Value)                                                   Can_30_Mcan_SetMailboxState(Index, (Can_30_Mcan_GetMailboxState(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  Can_30_McanPCSubstractDataMacros  Can_30_Mcan Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define Can_30_Mcan_SubPduOfActiveSendObject(Index, Value)                                          Can_30_Mcan_SetPduOfActiveSendObject(Index, (Can_30_Mcan_GetPduOfActiveSendObject(Index) - Value))
#define Can_30_Mcan_SubStateOfActiveSendObject(Index, Value)                                        Can_30_Mcan_SetStateOfActiveSendObject(Index, (Can_30_Mcan_GetStateOfActiveSendObject(Index) - Value))
#define Can_30_Mcan_SubBusOffNotificationOfControllerData(Index, Value)                             Can_30_Mcan_SetBusOffNotificationOfControllerData(Index, (Can_30_Mcan_GetBusOffNotificationOfControllerData(Index) - Value))
#define Can_30_Mcan_SubBusOffTransitionRequestOfControllerData(Index, Value)                        Can_30_Mcan_SetBusOffTransitionRequestOfControllerData(Index, (Can_30_Mcan_GetBusOffTransitionRequestOfControllerData(Index) - Value))
#define Can_30_Mcan_SubCanInterruptCounterOfControllerData(Index, Value)                            Can_30_Mcan_SetCanInterruptCounterOfControllerData(Index, (Can_30_Mcan_GetCanInterruptCounterOfControllerData(Index) - Value))
#define Can_30_Mcan_SubCanInterruptOldStatusOfControllerData(Index, Value)                          Can_30_Mcan_SetCanInterruptOldStatusOfControllerData(Index, (Can_30_Mcan_GetCanInterruptOldStatusOfControllerData(Index) - Value))
#define Can_30_Mcan_SubIntEnableOfControllerData(Index, Value)                                      Can_30_Mcan_SetIntEnableOfControllerData(Index, (Can_30_Mcan_GetIntEnableOfControllerData(Index) - Value))
#define Can_30_Mcan_SubLastInitObjectOfControllerData(Index, Value)                                 Can_30_Mcan_SetLastInitObjectOfControllerData(Index, (Can_30_Mcan_GetLastInitObjectOfControllerData(Index) - Value))
#define Can_30_Mcan_SubLastStateOfControllerData(Index, Value)                                      Can_30_Mcan_SetLastStateOfControllerData(Index, (Can_30_Mcan_GetLastStateOfControllerData(Index) - Value))
#define Can_30_Mcan_SubLogStatusOfControllerData(Index, Value)                                      Can_30_Mcan_SetLogStatusOfControllerData(Index, (Can_30_Mcan_GetLogStatusOfControllerData(Index) - Value))
#define Can_30_Mcan_SubLoopTimeoutOfControllerData(Index, Value)                                    Can_30_Mcan_SetLoopTimeoutOfControllerData(Index, (Can_30_Mcan_GetLoopTimeoutOfControllerData(Index) - Value))
#define Can_30_Mcan_SubModeTransitionRequestOfControllerData(Index, Value)                          Can_30_Mcan_SetModeTransitionRequestOfControllerData(Index, (Can_30_Mcan_GetModeTransitionRequestOfControllerData(Index) - Value))
#define Can_30_Mcan_SubNonFdObjectsPendingFlagOfControllerData(Index, Value)                        Can_30_Mcan_SetNonFdObjectsPendingFlagOfControllerData(Index, (Can_30_Mcan_GetNonFdObjectsPendingFlagOfControllerData(Index) - Value))
#define Can_30_Mcan_SubPrevModeOfControllerData(Index, Value)                                       Can_30_Mcan_SetPrevModeOfControllerData(Index, (Can_30_Mcan_GetPrevModeOfControllerData(Index) - Value))
#define Can_30_Mcan_SubRamCheckTransitionRequestOfControllerData(Index, Value)                      Can_30_Mcan_SetRamCheckTransitionRequestOfControllerData(Index, (Can_30_Mcan_GetRamCheckTransitionRequestOfControllerData(Index) - Value))
#define Can_30_Mcan_SubTXBCROfControllerData(Index, Value)                                          Can_30_Mcan_SetTXBCROfControllerData(Index, (Can_30_Mcan_GetTXBCROfControllerData(Index) - Value))
#define Can_30_Mcan_SubTXBRPOfControllerData(Index, Value)                                          Can_30_Mcan_SetTXBRPOfControllerData(Index, (Can_30_Mcan_GetTXBRPOfControllerData(Index) - Value))
#define Can_30_Mcan_SubMailboxState(Index, Value)                                                   Can_30_Mcan_SetMailboxState(Index, (Can_30_Mcan_GetMailboxState(Index) - Value))
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

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Can_30_McanPCIterableTypes  Can_30_Mcan Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Can_30_Mcan_ActiveSendObject */
typedef uint8_least Can_30_Mcan_ActiveSendObjectIterType;

/**   \brief  type used to iterate Can_30_Mcan_BTP */
typedef uint8_least Can_30_Mcan_BTPIterType;

/**   \brief  type used to iterate Can_30_Mcan_BufferConfig */
typedef uint8_least Can_30_Mcan_BufferConfigIterType;

/**   \brief  type used to iterate Can_30_Mcan_CanEccAggrBaseAddr */
typedef uint8_least Can_30_Mcan_CanEccAggrBaseAddrIterType;

/**   \brief  type used to iterate Can_30_Mcan_CanIfChannelId */
typedef uint8_least Can_30_Mcan_CanIfChannelIdIterType;

/**   \brief  type used to iterate Can_30_Mcan_CanMcanSsBaseAddr */
typedef uint8_least Can_30_Mcan_CanMcanSsBaseAddrIterType;

/**   \brief  type used to iterate Can_30_Mcan_ControllerConfig */
typedef uint8_least Can_30_Mcan_ControllerConfigIterType;

/**   \brief  type used to iterate Can_30_Mcan_FBTP */
typedef uint8_least Can_30_Mcan_FBTPIterType;

/**   \brief  type used to iterate Can_30_Mcan_GFC */
typedef uint8_least Can_30_Mcan_GFCIterType;

/**   \brief  type used to iterate Can_30_Mcan_InitObjectBaudrate */
typedef uint8_least Can_30_Mcan_InitObjectBaudrateIterType;

/**   \brief  type used to iterate Can_30_Mcan_InitObjectFdBrsConfig */
typedef uint8_least Can_30_Mcan_InitObjectFdBrsConfigIterType;

/**   \brief  type used to iterate Can_30_Mcan_InitObjectStartIndex */
typedef uint8_least Can_30_Mcan_InitObjectStartIndexIterType;

/**   \brief  type used to iterate Can_30_Mcan_Mailbox */
typedef uint8_least Can_30_Mcan_MailboxIterType;

/**   \brief  type used to iterate Can_30_Mcan_MemorySectionInfo */
typedef uint8_least Can_30_Mcan_MemorySectionInfoIterType;

/**   \brief  type used to iterate Can_30_Mcan_MemorySectionObjects */
typedef uint8_least Can_30_Mcan_MemorySectionObjectsIterType;

/**   \brief  type used to iterate Can_30_Mcan_SIDFC */
typedef uint8_least Can_30_Mcan_SIDFCIterType;

/**   \brief  type used to iterate Can_30_Mcan_SIDFE */
typedef uint8_least Can_30_Mcan_SIDFEIterType;

/**   \brief  type used to iterate Can_30_Mcan_ShmAdr */
typedef uint8_least Can_30_Mcan_ShmAdrIterType;

/**   \brief  type used to iterate Can_30_Mcan_ShmElementSize */
typedef uint8_least Can_30_Mcan_ShmElementSizeIterType;

/**   \brief  type used to iterate Can_30_Mcan_TDCR */
typedef uint8_least Can_30_Mcan_TDCRIterType;

/**   \brief  type used to iterate Can_30_Mcan_XIDAM */
typedef uint8_least Can_30_Mcan_XIDAMIterType;

/**   \brief  type used to iterate Can_30_Mcan_XIDFC */
typedef uint8_least Can_30_Mcan_XIDFCIterType;

/**   \brief  type used to iterate Can_30_Mcan_XIDFE */
typedef uint8_least Can_30_Mcan_XIDFEIterType;

/** 
  \}
*/ 

/** 
  \defgroup  Can_30_McanPCIterableTypesWithSizeRelations  Can_30_Mcan Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate Can_30_Mcan_ControllerData */
typedef Can_30_Mcan_ControllerConfigIterType Can_30_Mcan_ControllerDataIterType;

/**   \brief  type used to iterate Can_30_Mcan_MailboxState */
typedef Can_30_Mcan_MailboxIterType Can_30_Mcan_MailboxStateIterType;

/** 
  \}
*/ 

/** 
  \defgroup  Can_30_McanPCValueTypes  Can_30_Mcan Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Can_30_Mcan_PduOfActiveSendObject */
typedef PduIdType Can_30_Mcan_PduOfActiveSendObjectType;

/**   \brief  value based type definition for Can_30_Mcan_StateOfActiveSendObject */
typedef uint16 Can_30_Mcan_StateOfActiveSendObjectType;

/**   \brief  value based type definition for Can_30_Mcan_BTP */
typedef uint32 Can_30_Mcan_BTPType;

/**   \brief  value based type definition for Can_30_Mcan_BaseDll_GeneratorVersion */
typedef uint16 Can_30_Mcan_BaseDll_GeneratorVersionType;

/**   \brief  value based type definition for Can_30_Mcan_RXBCOfBufferConfig */
typedef uint8 Can_30_Mcan_RXBCOfBufferConfigType;

/**   \brief  value based type definition for Can_30_Mcan_RXF0COfBufferConfig */
typedef uint32 Can_30_Mcan_RXF0COfBufferConfigType;

/**   \brief  value based type definition for Can_30_Mcan_RXF1COfBufferConfig */
typedef uint8 Can_30_Mcan_RXF1COfBufferConfigType;

/**   \brief  value based type definition for Can_30_Mcan_TXBCOfBufferConfig */
typedef uint32 Can_30_Mcan_TXBCOfBufferConfigType;

/**   \brief  value based type definition for Can_30_Mcan_TXEFCOfBufferConfig */
typedef uint8 Can_30_Mcan_TXEFCOfBufferConfigType;

/**   \brief  value based type definition for Can_30_Mcan_CAN_FD_NISO */
typedef uint8 Can_30_Mcan_CAN_FD_NISOType;

/**   \brief  value based type definition for Can_30_Mcan_C_ENABLE_MPC5700_MCAN_CREL_SSTEP */
typedef uint8 Can_30_Mcan_C_ENABLE_MPC5700_MCAN_CREL_SSTEPType;

/**   \brief  value based type definition for Can_30_Mcan_C_ENABLE_MPC5700_MCAN_CREL_STEP */
typedef uint8 Can_30_Mcan_C_ENABLE_MPC5700_MCAN_CREL_STEPType;

/**   \brief  value based type definition for Can_30_Mcan_C_ENABLE_MPC5700_MCAN_MAJOR_CREL */
typedef uint8 Can_30_Mcan_C_ENABLE_MPC5700_MCAN_MAJOR_CRELType;

/**   \brief  value based type definition for Can_30_Mcan_CanEccAggrBaseAddr */
typedef uint32 Can_30_Mcan_CanEccAggrBaseAddrType;

/**   \brief  value based type definition for Can_30_Mcan_CanIfChannelId */
typedef uint8 Can_30_Mcan_CanIfChannelIdType;

/**   \brief  value based type definition for Can_30_Mcan_CanMcanSsBaseAddr */
typedef uint32 Can_30_Mcan_CanMcanSsBaseAddrType;

/**   \brief  value based type definition for Can_30_Mcan_BasisAdrOfControllerConfig */
typedef uint32 Can_30_Mcan_BasisAdrOfControllerConfigType;

/**   \brief  value based type definition for Can_30_Mcan_CanControllerDefaultBaudrateIdxOfControllerConfig */
typedef uint8 Can_30_Mcan_CanControllerDefaultBaudrateIdxOfControllerConfigType;

/**   \brief  value based type definition for Can_30_Mcan_CanControllerDefaultBaudrateOfControllerConfig */
typedef uint16 Can_30_Mcan_CanControllerDefaultBaudrateOfControllerConfigType;

/**   \brief  value based type definition for Can_30_Mcan_IsTTCanOfControllerConfig */
typedef boolean Can_30_Mcan_IsTTCanOfControllerConfigType;

/**   \brief  value based type definition for Can_30_Mcan_MailboxRxBasicEndIdxOfControllerConfig */
typedef uint8 Can_30_Mcan_MailboxRxBasicEndIdxOfControllerConfigType;

/**   \brief  value based type definition for Can_30_Mcan_MailboxRxBasicLengthOfControllerConfig */
typedef uint8 Can_30_Mcan_MailboxRxBasicLengthOfControllerConfigType;

/**   \brief  value based type definition for Can_30_Mcan_MailboxRxBasicStartIdxOfControllerConfig */
typedef uint8 Can_30_Mcan_MailboxRxBasicStartIdxOfControllerConfigType;

/**   \brief  value based type definition for Can_30_Mcan_MailboxRxBasicUsedOfControllerConfig */
typedef boolean Can_30_Mcan_MailboxRxBasicUsedOfControllerConfigType;

/**   \brief  value based type definition for Can_30_Mcan_MailboxTxBasicEndIdxOfControllerConfig */
typedef uint8 Can_30_Mcan_MailboxTxBasicEndIdxOfControllerConfigType;

/**   \brief  value based type definition for Can_30_Mcan_MailboxTxBasicLengthOfControllerConfig */
typedef uint8 Can_30_Mcan_MailboxTxBasicLengthOfControllerConfigType;

/**   \brief  value based type definition for Can_30_Mcan_MailboxTxBasicStartIdxOfControllerConfig */
typedef uint8 Can_30_Mcan_MailboxTxBasicStartIdxOfControllerConfigType;

/**   \brief  value based type definition for Can_30_Mcan_MailboxTxBasicUsedOfControllerConfig */
typedef boolean Can_30_Mcan_MailboxTxBasicUsedOfControllerConfigType;

/**   \brief  value based type definition for Can_30_Mcan_RxBasicHwStartOfControllerConfig */
typedef uint8 Can_30_Mcan_RxBasicHwStartOfControllerConfigType;

/**   \brief  value based type definition for Can_30_Mcan_RxBasicHwStopOfControllerConfig */
typedef uint8 Can_30_Mcan_RxBasicHwStopOfControllerConfigType;

/**   \brief  value based type definition for Can_30_Mcan_RxFullHwStartOfControllerConfig */
typedef uint8 Can_30_Mcan_RxFullHwStartOfControllerConfigType;

/**   \brief  value based type definition for Can_30_Mcan_RxFullHwStopOfControllerConfig */
typedef uint8 Can_30_Mcan_RxFullHwStopOfControllerConfigType;

/**   \brief  value based type definition for Can_30_Mcan_TxBasicHwStartOfControllerConfig */
typedef uint8 Can_30_Mcan_TxBasicHwStartOfControllerConfigType;

/**   \brief  value based type definition for Can_30_Mcan_TxBasicHwStopOfControllerConfig */
typedef uint8 Can_30_Mcan_TxBasicHwStopOfControllerConfigType;

/**   \brief  value based type definition for Can_30_Mcan_TxFullHwStartOfControllerConfig */
typedef uint8 Can_30_Mcan_TxFullHwStartOfControllerConfigType;

/**   \brief  value based type definition for Can_30_Mcan_TxFullHwStopOfControllerConfig */
typedef uint8 Can_30_Mcan_TxFullHwStopOfControllerConfigType;

/**   \brief  value based type definition for Can_30_Mcan_UnusedHwStartOfControllerConfig */
typedef uint8 Can_30_Mcan_UnusedHwStartOfControllerConfigType;

/**   \brief  value based type definition for Can_30_Mcan_UnusedHwStopOfControllerConfig */
typedef uint8 Can_30_Mcan_UnusedHwStopOfControllerConfigType;

/**   \brief  value based type definition for Can_30_Mcan_BusOffNotificationOfControllerData */
typedef uint8 Can_30_Mcan_BusOffNotificationOfControllerDataType;

/**   \brief  value based type definition for Can_30_Mcan_BusOffTransitionRequestOfControllerData */
typedef uint8 Can_30_Mcan_BusOffTransitionRequestOfControllerDataType;

/**   \brief  value based type definition for Can_30_Mcan_CanInterruptCounterOfControllerData */
typedef uint8 Can_30_Mcan_CanInterruptCounterOfControllerDataType;

/**   \brief  value based type definition for Can_30_Mcan_IntEnableOfControllerData */
typedef uint32 Can_30_Mcan_IntEnableOfControllerDataType;

/**   \brief  value based type definition for Can_30_Mcan_IsBusOffOfControllerData */
typedef boolean Can_30_Mcan_IsBusOffOfControllerDataType;

/**   \brief  value based type definition for Can_30_Mcan_LastInitObjectOfControllerData */
typedef uint8 Can_30_Mcan_LastInitObjectOfControllerDataType;

/**   \brief  value based type definition for Can_30_Mcan_LastStateOfControllerData */
typedef uint8 Can_30_Mcan_LastStateOfControllerDataType;

/**   \brief  value based type definition for Can_30_Mcan_LogStatusOfControllerData */
typedef uint8 Can_30_Mcan_LogStatusOfControllerDataType;

/**   \brief  value based type definition for Can_30_Mcan_ModeTransitionRequestOfControllerData */
typedef uint8 Can_30_Mcan_ModeTransitionRequestOfControllerDataType;

/**   \brief  value based type definition for Can_30_Mcan_NonFdObjectsPendingFlagOfControllerData */
typedef uint32 Can_30_Mcan_NonFdObjectsPendingFlagOfControllerDataType;

/**   \brief  value based type definition for Can_30_Mcan_PrevModeOfControllerData */
typedef uint8 Can_30_Mcan_PrevModeOfControllerDataType;

/**   \brief  value based type definition for Can_30_Mcan_RamCheckTransitionRequestOfControllerData */
typedef uint8 Can_30_Mcan_RamCheckTransitionRequestOfControllerDataType;

/**   \brief  value based type definition for Can_30_Mcan_TXBCROfControllerData */
typedef uint32 Can_30_Mcan_TXBCROfControllerDataType;

/**   \brief  value based type definition for Can_30_Mcan_TXBRPOfControllerData */
typedef uint32 Can_30_Mcan_TXBRPOfControllerDataType;

/**   \brief  value based type definition for Can_30_Mcan_FBTP */
typedef uint32 Can_30_Mcan_FBTPType;

/**   \brief  value based type definition for Can_30_Mcan_GFC */
typedef uint8 Can_30_Mcan_GFCType;

/**   \brief  value based type definition for Can_30_Mcan_InitObjectBaudrate */
typedef uint16 Can_30_Mcan_InitObjectBaudrateType;

/**   \brief  value based type definition for Can_30_Mcan_InitObjectFdBrsConfig */
typedef uint8 Can_30_Mcan_InitObjectFdBrsConfigType;

/**   \brief  value based type definition for Can_30_Mcan_InitObjectStartIndex */
typedef uint8 Can_30_Mcan_InitObjectStartIndexType;

/**   \brief  value based type definition for Can_30_Mcan_ActiveSendObjectOfMailbox */
typedef uint8 Can_30_Mcan_ActiveSendObjectOfMailboxType;

/**   \brief  value based type definition for Can_30_Mcan_ControllerConfigIdxOfMailbox */
typedef uint8 Can_30_Mcan_ControllerConfigIdxOfMailboxType;

/**   \brief  value based type definition for Can_30_Mcan_FdPaddingOfMailbox */
typedef uint8 Can_30_Mcan_FdPaddingOfMailboxType;

/**   \brief  value based type definition for Can_30_Mcan_HwHandleOfMailbox */
typedef uint8 Can_30_Mcan_HwHandleOfMailboxType;

/**   \brief  value based type definition for Can_30_Mcan_IDValueOfMailbox */
typedef uint8 Can_30_Mcan_IDValueOfMailboxType;

/**   \brief  value based type definition for Can_30_Mcan_MailboxSizeOfMailbox */
typedef uint8 Can_30_Mcan_MailboxSizeOfMailboxType;

/**   \brief  value based type definition for Can_30_Mcan_MailboxTypeOfMailbox */
typedef uint8 Can_30_Mcan_MailboxTypeOfMailboxType;

/**   \brief  value based type definition for Can_30_Mcan_MaxDataLenOfMailbox */
typedef uint8 Can_30_Mcan_MaxDataLenOfMailboxType;

/**   \brief  value based type definition for Can_30_Mcan_MemorySectionsIndexOfMailbox */
typedef uint8 Can_30_Mcan_MemorySectionsIndexOfMailboxType;

/**   \brief  value based type definition for Can_30_Mcan_MailboxState */
typedef uint8 Can_30_Mcan_MailboxStateType;

/**   \brief  value based type definition for Can_30_Mcan_MemorySectionStartOfMemorySectionInfo */
typedef uint8 Can_30_Mcan_MemorySectionStartOfMemorySectionInfoType;

/**   \brief  value based type definition for Can_30_Mcan_HwHandleOfMemorySectionObjects */
typedef uint8 Can_30_Mcan_HwHandleOfMemorySectionObjectsType;

/**   \brief  value based type definition for Can_30_Mcan_MailboxElementOfMemorySectionObjects */
typedef uint8 Can_30_Mcan_MailboxElementOfMemorySectionObjectsType;

/**   \brief  value based type definition for Can_30_Mcan_MailboxHandleOfMemorySectionObjects */
typedef uint8 Can_30_Mcan_MailboxHandleOfMemorySectionObjectsType;

/**   \brief  value based type definition for Can_30_Mcan_PlatformDll_GeneratorVersion */
typedef uint16 Can_30_Mcan_PlatformDll_GeneratorVersionType;

/**   \brief  value based type definition for Can_30_Mcan_FLSSAOfSIDFC */
typedef uint8 Can_30_Mcan_FLSSAOfSIDFCType;

/**   \brief  value based type definition for Can_30_Mcan_LSSOfSIDFC */
typedef uint8 Can_30_Mcan_LSSOfSIDFCType;

/**   \brief  value based type definition for Can_30_Mcan_SIDFEEndIdxOfSIDFC */
typedef uint8 Can_30_Mcan_SIDFEEndIdxOfSIDFCType;

/**   \brief  value based type definition for Can_30_Mcan_SIDFEStartIdxOfSIDFC */
typedef uint8 Can_30_Mcan_SIDFEStartIdxOfSIDFCType;

/**   \brief  value based type definition for Can_30_Mcan_SIDFEUsedOfSIDFC */
typedef boolean Can_30_Mcan_SIDFEUsedOfSIDFCType;

/**   \brief  value based type definition for Can_30_Mcan_SIDFE */
typedef uint32 Can_30_Mcan_SIDFEType;

/**   \brief  value based type definition for Can_30_Mcan_RXBAOfShmAdr */
typedef uint32 Can_30_Mcan_RXBAOfShmAdrType;

/**   \brief  value based type definition for Can_30_Mcan_RXF0AOfShmAdr */
typedef uint32 Can_30_Mcan_RXF0AOfShmAdrType;

/**   \brief  value based type definition for Can_30_Mcan_RXF1AOfShmAdr */
typedef uint32 Can_30_Mcan_RXF1AOfShmAdrType;

/**   \brief  value based type definition for Can_30_Mcan_SIDFAOfShmAdr */
typedef uint32 Can_30_Mcan_SIDFAOfShmAdrType;

/**   \brief  value based type definition for Can_30_Mcan_StartAdrOfShmAdr */
typedef uint32 Can_30_Mcan_StartAdrOfShmAdrType;

/**   \brief  value based type definition for Can_30_Mcan_StopAdrOfShmAdr */
typedef uint32 Can_30_Mcan_StopAdrOfShmAdrType;

/**   \brief  value based type definition for Can_30_Mcan_TXBAOfShmAdr */
typedef uint32 Can_30_Mcan_TXBAOfShmAdrType;

/**   \brief  value based type definition for Can_30_Mcan_TXEFAOfShmAdr */
typedef uint32 Can_30_Mcan_TXEFAOfShmAdrType;

/**   \brief  value based type definition for Can_30_Mcan_XIDFAOfShmAdr */
typedef uint32 Can_30_Mcan_XIDFAOfShmAdrType;

/**   \brief  value based type definition for Can_30_Mcan_F0DSOfShmElementSize */
typedef uint8 Can_30_Mcan_F0DSOfShmElementSizeType;

/**   \brief  value based type definition for Can_30_Mcan_F1DSOfShmElementSize */
typedef uint8 Can_30_Mcan_F1DSOfShmElementSizeType;

/**   \brief  value based type definition for Can_30_Mcan_RBDSOfShmElementSize */
typedef uint8 Can_30_Mcan_RBDSOfShmElementSizeType;

/**   \brief  value based type definition for Can_30_Mcan_TBDSOfShmElementSize */
typedef uint8 Can_30_Mcan_TBDSOfShmElementSizeType;

/**   \brief  value based type definition for Can_30_Mcan_TEFBDSOfShmElementSize */
typedef uint8 Can_30_Mcan_TEFBDSOfShmElementSizeType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfActiveSendObject */
typedef uint8 Can_30_Mcan_SizeOfActiveSendObjectType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfBTP */
typedef uint8 Can_30_Mcan_SizeOfBTPType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfBufferConfig */
typedef uint8 Can_30_Mcan_SizeOfBufferConfigType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfCanEccAggrBaseAddr */
typedef uint8 Can_30_Mcan_SizeOfCanEccAggrBaseAddrType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfCanIfChannelId */
typedef uint8 Can_30_Mcan_SizeOfCanIfChannelIdType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfCanMcanSsBaseAddr */
typedef uint8 Can_30_Mcan_SizeOfCanMcanSsBaseAddrType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfControllerConfig */
typedef uint8 Can_30_Mcan_SizeOfControllerConfigType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfControllerData */
typedef uint8 Can_30_Mcan_SizeOfControllerDataType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfFBTP */
typedef uint8 Can_30_Mcan_SizeOfFBTPType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfGFC */
typedef uint8 Can_30_Mcan_SizeOfGFCType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfInitObjectBaudrate */
typedef uint8 Can_30_Mcan_SizeOfInitObjectBaudrateType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfInitObjectFdBrsConfig */
typedef uint8 Can_30_Mcan_SizeOfInitObjectFdBrsConfigType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfInitObjectStartIndex */
typedef uint8 Can_30_Mcan_SizeOfInitObjectStartIndexType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfMailbox */
typedef uint8 Can_30_Mcan_SizeOfMailboxType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfMailboxState */
typedef uint8 Can_30_Mcan_SizeOfMailboxStateType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfMemorySectionInfo */
typedef uint8 Can_30_Mcan_SizeOfMemorySectionInfoType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfMemorySectionObjects */
typedef uint8 Can_30_Mcan_SizeOfMemorySectionObjectsType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfSIDFC */
typedef uint8 Can_30_Mcan_SizeOfSIDFCType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfSIDFE */
typedef uint8 Can_30_Mcan_SizeOfSIDFEType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfShmAdr */
typedef uint8 Can_30_Mcan_SizeOfShmAdrType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfShmElementSize */
typedef uint8 Can_30_Mcan_SizeOfShmElementSizeType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfTDCR */
typedef uint8 Can_30_Mcan_SizeOfTDCRType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfXIDAM */
typedef uint8 Can_30_Mcan_SizeOfXIDAMType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfXIDFC */
typedef uint8 Can_30_Mcan_SizeOfXIDFCType;

/**   \brief  value based type definition for Can_30_Mcan_SizeOfXIDFE */
typedef uint8 Can_30_Mcan_SizeOfXIDFEType;

/**   \brief  value based type definition for Can_30_Mcan_TDCR */
typedef uint8 Can_30_Mcan_TDCRType;

/**   \brief  value based type definition for Can_30_Mcan_XIDAM */
typedef uint32 Can_30_Mcan_XIDAMType;

/**   \brief  value based type definition for Can_30_Mcan_FLESAOfXIDFC */
typedef uint8 Can_30_Mcan_FLESAOfXIDFCType;

/**   \brief  value based type definition for Can_30_Mcan_LSEOfXIDFC */
typedef uint8 Can_30_Mcan_LSEOfXIDFCType;

/**   \brief  value based type definition for Can_30_Mcan_XIDFEEndIdxOfXIDFC */
typedef uint8 Can_30_Mcan_XIDFEEndIdxOfXIDFCType;

/**   \brief  value based type definition for Can_30_Mcan_XIDFEStartIdxOfXIDFC */
typedef uint8 Can_30_Mcan_XIDFEStartIdxOfXIDFCType;

/**   \brief  value based type definition for Can_30_Mcan_XIDFEUsedOfXIDFC */
typedef boolean Can_30_Mcan_XIDFEUsedOfXIDFCType;

/**   \brief  value based type definition for Can_30_Mcan_EIDFE_0OfXIDFE */
typedef uint32 Can_30_Mcan_EIDFE_0OfXIDFEType;

/**   \brief  value based type definition for Can_30_Mcan_EIDFE_1OfXIDFE */
typedef uint32 Can_30_Mcan_EIDFE_1OfXIDFEType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Can_30_McanPCStructTypes  Can_30_Mcan Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in Can_30_Mcan_ActiveSendObject */
typedef struct sCan_30_Mcan_ActiveSendObjectType
{
  Can_30_Mcan_PduOfActiveSendObjectType PduOfActiveSendObject;  /**< buffered PduId for confirmation or cancellation */
  Can_30_Mcan_StateOfActiveSendObjectType StateOfActiveSendObject;  /**< send state like cancelled or send activ */
} Can_30_Mcan_ActiveSendObjectType;

/**   \brief  type used in Can_30_Mcan_BufferConfig */
typedef struct sCan_30_Mcan_BufferConfigType
{
  Can_30_Mcan_RXF0COfBufferConfigType RXF0COfBufferConfig;
  Can_30_Mcan_TXBCOfBufferConfigType TXBCOfBufferConfig;
  Can_30_Mcan_RXBCOfBufferConfigType RXBCOfBufferConfig;
  Can_30_Mcan_RXF1COfBufferConfigType RXF1COfBufferConfig;
  Can_30_Mcan_TXEFCOfBufferConfigType TXEFCOfBufferConfig;
} Can_30_Mcan_BufferConfigType;

/**   \brief  type used in Can_30_Mcan_ControllerConfig */
/*! \spec weak type invariant () { 
 * (!((self.MailboxTxBasicLengthOfControllerConfig != 0u)) || (self.MailboxTxBasicStartIdxOfControllerConfig < Can_30_Mcan_GetSizeOfMailbox())) &&
 * (!((self.MailboxTxBasicLengthOfControllerConfig != 0u)) || (self.MailboxTxBasicEndIdxOfControllerConfig < Can_30_Mcan_GetSizeOfMailbox())) &&
 * (!((self.MailboxRxBasicLengthOfControllerConfig != 0u)) || (self.MailboxRxBasicStartIdxOfControllerConfig < Can_30_Mcan_GetSizeOfMailbox())) &&
 * (!((self.MailboxRxBasicLengthOfControllerConfig != 0u)) || (self.MailboxRxBasicEndIdxOfControllerConfig < Can_30_Mcan_GetSizeOfMailbox()))
 * } */
typedef struct sCan_30_Mcan_ControllerConfigType
{
  Can_30_Mcan_BasisAdrOfControllerConfigType BasisAdrOfControllerConfig;  /**< CAN channel base address */
  Can_30_Mcan_CanControllerDefaultBaudrateOfControllerConfigType CanControllerDefaultBaudrateOfControllerConfig;
  Can_30_Mcan_IsTTCanOfControllerConfigType IsTTCanOfControllerConfig;  /**< TTCAN channel support */
  Can_30_Mcan_CanControllerDefaultBaudrateIdxOfControllerConfigType CanControllerDefaultBaudrateIdxOfControllerConfig;
  Can_30_Mcan_MailboxRxBasicEndIdxOfControllerConfigType MailboxRxBasicEndIdxOfControllerConfig;  /**< the end index of the 0:n relation pointing to Can_30_Mcan_Mailbox */
  Can_30_Mcan_MailboxRxBasicLengthOfControllerConfigType MailboxRxBasicLengthOfControllerConfig;  /**< the number of relations pointing to Can_30_Mcan_Mailbox */
  Can_30_Mcan_MailboxRxBasicStartIdxOfControllerConfigType MailboxRxBasicStartIdxOfControllerConfig;  /**< the start index of the 0:n relation pointing to Can_30_Mcan_Mailbox */
  Can_30_Mcan_MailboxTxBasicEndIdxOfControllerConfigType MailboxTxBasicEndIdxOfControllerConfig;  /**< the end index of the 0:n relation pointing to Can_30_Mcan_Mailbox */
  Can_30_Mcan_MailboxTxBasicLengthOfControllerConfigType MailboxTxBasicLengthOfControllerConfig;  /**< the number of relations pointing to Can_30_Mcan_Mailbox */
  Can_30_Mcan_MailboxTxBasicStartIdxOfControllerConfigType MailboxTxBasicStartIdxOfControllerConfig;  /**< the start index of the 0:n relation pointing to Can_30_Mcan_Mailbox */
  Can_30_Mcan_RxBasicHwStartOfControllerConfigType RxBasicHwStartOfControllerConfig;
  Can_30_Mcan_RxBasicHwStopOfControllerConfigType RxBasicHwStopOfControllerConfig;
  Can_30_Mcan_RxFullHwStartOfControllerConfigType RxFullHwStartOfControllerConfig;
  Can_30_Mcan_RxFullHwStopOfControllerConfigType RxFullHwStopOfControllerConfig;
  Can_30_Mcan_TxBasicHwStartOfControllerConfigType TxBasicHwStartOfControllerConfig;
  Can_30_Mcan_TxBasicHwStopOfControllerConfigType TxBasicHwStopOfControllerConfig;
  Can_30_Mcan_TxFullHwStartOfControllerConfigType TxFullHwStartOfControllerConfig;
  Can_30_Mcan_TxFullHwStopOfControllerConfigType TxFullHwStopOfControllerConfig;
  Can_30_Mcan_UnusedHwStartOfControllerConfigType UnusedHwStartOfControllerConfig;
  Can_30_Mcan_UnusedHwStopOfControllerConfigType UnusedHwStopOfControllerConfig;
} Can_30_Mcan_ControllerConfigType;

/**   \brief  type used in Can_30_Mcan_ControllerData */
typedef struct sCan_30_Mcan_ControllerDataType
{
  Can_30_Mcan_IntEnableOfControllerDataType IntEnableOfControllerData;  /**< CAN Interrupt Enable state for each controller */
  Can_30_Mcan_NonFdObjectsPendingFlagOfControllerDataType NonFdObjectsPendingFlagOfControllerData;  /**< CAN Tx Objects pending with CAN-FD format */
  Can_30_Mcan_TXBCROfControllerDataType TXBCROfControllerData;  /**< CAN Tx Buffer Cancellation Request for each controller */
  Can_30_Mcan_TXBRPOfControllerDataType TXBRPOfControllerData;  /**< CAN Tx Buffer request Pending for each controller */
  Can_30_Mcan_BusOffNotificationOfControllerDataType BusOffNotificationOfControllerData;  /**< CAN state for each controller: busoff occur */
  Can_30_Mcan_BusOffTransitionRequestOfControllerDataType BusOffTransitionRequestOfControllerData;  /**< CAN state request for each controller: ContinueBusOffRecovery=0x00, FinishBusOffRecovery=0x01 */
  Can_30_Mcan_CanInterruptCounterOfControllerDataType CanInterruptCounterOfControllerData;  /**< CAN interrupt disable counter for each controller */
  Can_30_Mcan_IsBusOffOfControllerDataType IsBusOffOfControllerData;  /**< CAN state for each controller: busoff occur */
  Can_30_Mcan_LastInitObjectOfControllerDataType LastInitObjectOfControllerData;  /**< last set baudrate for reinit */
  Can_30_Mcan_LastStateOfControllerDataType LastStateOfControllerData;  /**< CAN mode transition request status for each controller */
  Can_30_Mcan_LogStatusOfControllerDataType LogStatusOfControllerData;  /**< CAN state for each controller: UNINIT=0x00, START=0x01, STOP=0x02, INIT=0x04, INCONSISTENT=0x08, WARNING =0x10, PASSIVE=0x20, BUSOFF=0x40, SLEEP=0x80 */
  Can_30_Mcan_ModeTransitionRequestOfControllerDataType ModeTransitionRequestOfControllerData;  /**< CAN state request for each controller: INIT=0x00, SLEEP=0x01, WAKEUP=0x02, STOP+INIT=0x03, START=0x04, START+INIT=0x05, NONE=0x06 */
  Can_30_Mcan_PrevModeOfControllerDataType PrevModeOfControllerData;  /**< CAN mode transition request for each controller */
  Can_30_Mcan_RamCheckTransitionRequestOfControllerDataType RamCheckTransitionRequestOfControllerData;  /**< CAN state request for each controller: kCanSuppressRamCheck=0x01, kCanExecuteRamCheck=0x00 */
  tCan_30_McanLLCanIntOld CanInterruptOldStatusOfControllerData;  /**< last CAN interrupt status for restore interrupt for each controller */
  Can_30_Mcan_LoopTimeout_dim_type LoopTimeoutOfControllerData;  /**< hw loop timeout for each controller */
} Can_30_Mcan_ControllerDataType;

/**   \brief  type used in Can_30_Mcan_Mailbox */
/*! \spec weak type invariant () { 
 * (self.ControllerConfigIdxOfMailbox < Can_30_Mcan_GetSizeOfControllerConfig())
 * } */
typedef struct sCan_30_Mcan_MailboxType
{
  Can_30_Mcan_ActiveSendObjectOfMailboxType ActiveSendObjectOfMailbox;
  Can_30_Mcan_ControllerConfigIdxOfMailboxType ControllerConfigIdxOfMailbox;  /**< the index of the 1:1 relation pointing to Can_30_Mcan_ControllerConfig */
  Can_30_Mcan_FdPaddingOfMailboxType FdPaddingOfMailbox;
  Can_30_Mcan_HwHandleOfMailboxType HwHandleOfMailbox;
  Can_30_Mcan_IDValueOfMailboxType IDValueOfMailbox;
  Can_30_Mcan_MailboxSizeOfMailboxType MailboxSizeOfMailbox;
  Can_30_Mcan_MailboxTypeOfMailboxType MailboxTypeOfMailbox;
  Can_30_Mcan_MaxDataLenOfMailboxType MaxDataLenOfMailbox;
  Can_30_Mcan_MemorySectionsIndexOfMailboxType MemorySectionsIndexOfMailbox;
} Can_30_Mcan_MailboxType;

/**   \brief  type used in Can_30_Mcan_MemorySectionInfo */
typedef struct sCan_30_Mcan_MemorySectionInfoType
{
  Can_30_Mcan_MemorySectionStartOfMemorySectionInfoType MemorySectionStartOfMemorySectionInfo;
} Can_30_Mcan_MemorySectionInfoType;

/**   \brief  type used in Can_30_Mcan_MemorySectionObjects */
typedef struct sCan_30_Mcan_MemorySectionObjectsType
{
  Can_30_Mcan_HwHandleOfMemorySectionObjectsType HwHandleOfMemorySectionObjects;
  Can_30_Mcan_MailboxElementOfMemorySectionObjectsType MailboxElementOfMemorySectionObjects;
  Can_30_Mcan_MailboxHandleOfMemorySectionObjectsType MailboxHandleOfMemorySectionObjects;
} Can_30_Mcan_MemorySectionObjectsType;

/**   \brief  type used in Can_30_Mcan_SIDFC */
/*! \spec weak type invariant () { 
 * (!((self.SIDFEStartIdxOfSIDFC != CAN_30_MCAN_NO_SIDFESTARTIDXOFSIDFC)) || (self.SIDFEStartIdxOfSIDFC < Can_30_Mcan_GetSizeOfSIDFE())) &&
 * (!((self.SIDFEStartIdxOfSIDFC != CAN_30_MCAN_NO_SIDFESTARTIDXOFSIDFC)) || (self.SIDFEEndIdxOfSIDFC < Can_30_Mcan_GetSizeOfSIDFE()))
 * } */
typedef struct sCan_30_Mcan_SIDFCType
{
  Can_30_Mcan_FLSSAOfSIDFCType FLSSAOfSIDFC;  /**< Filter List Standard Start Address */
  Can_30_Mcan_LSSOfSIDFCType LSSOfSIDFC;  /**< List size standard */
  Can_30_Mcan_SIDFEEndIdxOfSIDFCType SIDFEEndIdxOfSIDFC;  /**< the end index of the 0:n relation pointing to Can_30_Mcan_SIDFE */
  Can_30_Mcan_SIDFEStartIdxOfSIDFCType SIDFEStartIdxOfSIDFC;  /**< the start index of the 0:n relation pointing to Can_30_Mcan_SIDFE */
} Can_30_Mcan_SIDFCType;

/**   \brief  type used in Can_30_Mcan_ShmAdr */
typedef struct sCan_30_Mcan_ShmAdrType
{
  Can_30_Mcan_RXBAOfShmAdrType RXBAOfShmAdr;  /**< RX Buffer Address */
  Can_30_Mcan_RXF0AOfShmAdrType RXF0AOfShmAdr;  /**< RX FIFO0 Address */
  Can_30_Mcan_RXF1AOfShmAdrType RXF1AOfShmAdr;  /**< RX FIFO1 Address */
  Can_30_Mcan_SIDFAOfShmAdrType SIDFAOfShmAdr;  /**< Standard Filters Address */
  Can_30_Mcan_StartAdrOfShmAdrType StartAdrOfShmAdr;  /**< Start address of the shared memory area */
  Can_30_Mcan_StopAdrOfShmAdrType StopAdrOfShmAdr;  /**< Stop address of the shared memory area */
  Can_30_Mcan_TXBAOfShmAdrType TXBAOfShmAdr;  /**< TX Buffer address */
  Can_30_Mcan_TXEFAOfShmAdrType TXEFAOfShmAdr;  /**< TX Event FIFO address */
  Can_30_Mcan_XIDFAOfShmAdrType XIDFAOfShmAdr;  /**< Extended Filters Address */
} Can_30_Mcan_ShmAdrType;

/**   \brief  type used in Can_30_Mcan_ShmElementSize */
typedef struct sCan_30_Mcan_ShmElementSizeType
{
  Can_30_Mcan_F0DSOfShmElementSizeType F0DSOfShmElementSize;
  Can_30_Mcan_F1DSOfShmElementSizeType F1DSOfShmElementSize;
  Can_30_Mcan_RBDSOfShmElementSizeType RBDSOfShmElementSize;
  Can_30_Mcan_TBDSOfShmElementSizeType TBDSOfShmElementSize;
  Can_30_Mcan_TEFBDSOfShmElementSizeType TEFBDSOfShmElementSize;
} Can_30_Mcan_ShmElementSizeType;

/**   \brief  type used in Can_30_Mcan_XIDFC */
/*! \spec weak type invariant () { 
 * (!((self.XIDFEStartIdxOfXIDFC != CAN_30_MCAN_NO_XIDFESTARTIDXOFXIDFC)) || (self.XIDFEStartIdxOfXIDFC < Can_30_Mcan_GetSizeOfXIDFE())) &&
 * (!((self.XIDFEStartIdxOfXIDFC != CAN_30_MCAN_NO_XIDFESTARTIDXOFXIDFC)) || (self.XIDFEEndIdxOfXIDFC < Can_30_Mcan_GetSizeOfXIDFE()))
 * } */
typedef struct sCan_30_Mcan_XIDFCType
{
  Can_30_Mcan_FLESAOfXIDFCType FLESAOfXIDFC;  /**< Filter List Extended Start Address */
  Can_30_Mcan_LSEOfXIDFCType LSEOfXIDFC;  /**< List size extended */
  Can_30_Mcan_XIDFEEndIdxOfXIDFCType XIDFEEndIdxOfXIDFC;  /**< the end index of the 0:n relation pointing to Can_30_Mcan_XIDFE */
  Can_30_Mcan_XIDFEStartIdxOfXIDFCType XIDFEStartIdxOfXIDFC;  /**< the start index of the 0:n relation pointing to Can_30_Mcan_XIDFE */
} Can_30_Mcan_XIDFCType;

/**   \brief  type used in Can_30_Mcan_XIDFE */
typedef struct sCan_30_Mcan_XIDFEType
{
  Can_30_Mcan_EIDFE_0OfXIDFEType EIDFE_0OfXIDFE;
  Can_30_Mcan_EIDFE_1OfXIDFEType EIDFE_1OfXIDFE;
} Can_30_Mcan_XIDFEType;

/** 
  \}
*/ 

/** 
  \defgroup  Can_30_McanPCRootPointerTypes  Can_30_Mcan Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to Can_30_Mcan_ActiveSendObject */
typedef P2VAR(Can_30_Mcan_ActiveSendObjectType, TYPEDEF, CAN_30_MCAN_VAR_NOINIT) Can_30_Mcan_ActiveSendObjectPtrType;

/**   \brief  type used to point to Can_30_Mcan_BTP */
typedef P2CONST(Can_30_Mcan_BTPType, TYPEDEF, CAN_30_MCAN_CONST) Can_30_Mcan_BTPPtrType;

/**   \brief  type used to point to Can_30_Mcan_BufferConfig */
typedef P2CONST(Can_30_Mcan_BufferConfigType, TYPEDEF, CAN_30_MCAN_CONST) Can_30_Mcan_BufferConfigPtrType;

/**   \brief  type used to point to Can_30_Mcan_CanEccAggrBaseAddr */
typedef P2CONST(Can_30_Mcan_CanEccAggrBaseAddrType, TYPEDEF, CAN_30_MCAN_CONST) Can_30_Mcan_CanEccAggrBaseAddrPtrType;

/**   \brief  type used to point to Can_30_Mcan_CanIfChannelId */
typedef P2CONST(Can_30_Mcan_CanIfChannelIdType, TYPEDEF, CAN_30_MCAN_CONST) Can_30_Mcan_CanIfChannelIdPtrType;

/**   \brief  type used to point to Can_30_Mcan_CanMcanSsBaseAddr */
typedef P2CONST(Can_30_Mcan_CanMcanSsBaseAddrType, TYPEDEF, CAN_30_MCAN_CONST) Can_30_Mcan_CanMcanSsBaseAddrPtrType;

/**   \brief  type used to point to Can_30_Mcan_ControllerConfig */
typedef P2CONST(Can_30_Mcan_ControllerConfigType, TYPEDEF, CAN_30_MCAN_CONST) Can_30_Mcan_ControllerConfigPtrType;

/**   \brief  type used to point to Can_30_Mcan_ControllerData */
typedef P2VAR(Can_30_Mcan_ControllerDataType, TYPEDEF, CAN_30_MCAN_VAR_NOINIT) Can_30_Mcan_ControllerDataPtrType;

/**   \brief  type used to point to Can_30_Mcan_FBTP */
typedef P2CONST(Can_30_Mcan_FBTPType, TYPEDEF, CAN_30_MCAN_CONST) Can_30_Mcan_FBTPPtrType;

/**   \brief  type used to point to Can_30_Mcan_GFC */
typedef P2CONST(Can_30_Mcan_GFCType, TYPEDEF, CAN_30_MCAN_CONST) Can_30_Mcan_GFCPtrType;

/**   \brief  type used to point to Can_30_Mcan_InitObjectBaudrate */
typedef P2CONST(Can_30_Mcan_InitObjectBaudrateType, TYPEDEF, CAN_30_MCAN_CONST) Can_30_Mcan_InitObjectBaudratePtrType;

/**   \brief  type used to point to Can_30_Mcan_InitObjectFdBrsConfig */
typedef P2CONST(Can_30_Mcan_InitObjectFdBrsConfigType, TYPEDEF, CAN_30_MCAN_CONST) Can_30_Mcan_InitObjectFdBrsConfigPtrType;

/**   \brief  type used to point to Can_30_Mcan_InitObjectStartIndex */
typedef P2CONST(Can_30_Mcan_InitObjectStartIndexType, TYPEDEF, CAN_30_MCAN_CONST) Can_30_Mcan_InitObjectStartIndexPtrType;

/**   \brief  type used to point to Can_30_Mcan_Mailbox */
typedef P2CONST(Can_30_Mcan_MailboxType, TYPEDEF, CAN_30_MCAN_CONST) Can_30_Mcan_MailboxPtrType;

/**   \brief  type used to point to Can_30_Mcan_MailboxState */
typedef P2VAR(Can_30_Mcan_MailboxStateType, TYPEDEF, CAN_30_MCAN_VAR_NOINIT) Can_30_Mcan_MailboxStatePtrType;

/**   \brief  type used to point to Can_30_Mcan_MemorySectionInfo */
typedef P2CONST(Can_30_Mcan_MemorySectionInfoType, TYPEDEF, CAN_30_MCAN_CONST) Can_30_Mcan_MemorySectionInfoPtrType;

/**   \brief  type used to point to Can_30_Mcan_MemorySectionObjects */
typedef P2CONST(Can_30_Mcan_MemorySectionObjectsType, TYPEDEF, CAN_30_MCAN_CONST) Can_30_Mcan_MemorySectionObjectsPtrType;

/**   \brief  type used to point to Can_30_Mcan_SIDFC */
typedef P2CONST(Can_30_Mcan_SIDFCType, TYPEDEF, CAN_30_MCAN_CONST) Can_30_Mcan_SIDFCPtrType;

/**   \brief  type used to point to Can_30_Mcan_SIDFE */
typedef P2CONST(Can_30_Mcan_SIDFEType, TYPEDEF, CAN_30_MCAN_CONST) Can_30_Mcan_SIDFEPtrType;

/**   \brief  type used to point to Can_30_Mcan_ShmAdr */
typedef P2CONST(Can_30_Mcan_ShmAdrType, TYPEDEF, CAN_30_MCAN_CONST) Can_30_Mcan_ShmAdrPtrType;

/**   \brief  type used to point to Can_30_Mcan_ShmElementSize */
typedef P2CONST(Can_30_Mcan_ShmElementSizeType, TYPEDEF, CAN_30_MCAN_CONST) Can_30_Mcan_ShmElementSizePtrType;

/**   \brief  type used to point to Can_30_Mcan_TDCR */
typedef P2CONST(Can_30_Mcan_TDCRType, TYPEDEF, CAN_30_MCAN_CONST) Can_30_Mcan_TDCRPtrType;

/**   \brief  type used to point to Can_30_Mcan_XIDAM */
typedef P2CONST(Can_30_Mcan_XIDAMType, TYPEDEF, CAN_30_MCAN_CONST) Can_30_Mcan_XIDAMPtrType;

/**   \brief  type used to point to Can_30_Mcan_XIDFC */
typedef P2CONST(Can_30_Mcan_XIDFCType, TYPEDEF, CAN_30_MCAN_CONST) Can_30_Mcan_XIDFCPtrType;

/**   \brief  type used to point to Can_30_Mcan_XIDFE */
typedef P2CONST(Can_30_Mcan_XIDFEType, TYPEDEF, CAN_30_MCAN_CONST) Can_30_Mcan_XIDFEPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  Can_30_McanPCRootValueTypes  Can_30_Mcan Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Can_30_Mcan_PCConfig */
typedef struct sCan_30_Mcan_PCConfigType
{
  uint8 Can_30_Mcan_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Can_30_Mcan_PCConfigType;

typedef Can_30_Mcan_PCConfigType Can_30_Mcan_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  Can_30_Mcan_BTP
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_BTP
  \brief  Bit Timing and Prescaler
*/ 
#define CAN_30_MCAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_30_Mcan_BTPType, CAN_30_MCAN_CONST) Can_30_Mcan_BTP[2];
#define CAN_30_MCAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_BufferConfig
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_BufferConfig
  \brief  CAN Buffer Configuration
  \details
  Element    Description
  RXF0C  
  TXBC   
  RXBC   
  RXF1C  
  TXEFC  
*/ 
#define CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_30_Mcan_BufferConfigType, CAN_30_MCAN_CONST) Can_30_Mcan_BufferConfig[2];
#define CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_CanEccAggrBaseAddr
**********************************************************************************************************************/
#define CAN_30_MCAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_30_Mcan_CanEccAggrBaseAddrType, CAN_30_MCAN_CONST) Can_30_Mcan_CanEccAggrBaseAddr[2];
#define CAN_30_MCAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_CanIfChannelId
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_CanIfChannelId
  \brief  indirection table Can to CanIf controller ID
*/ 
#define CAN_30_MCAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_30_Mcan_CanIfChannelIdType, CAN_30_MCAN_CONST) Can_30_Mcan_CanIfChannelId[2];
#define CAN_30_MCAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_CanMcanSsBaseAddr
**********************************************************************************************************************/
#define CAN_30_MCAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_30_Mcan_CanMcanSsBaseAddrType, CAN_30_MCAN_CONST) Can_30_Mcan_CanMcanSsBaseAddr[2];
#define CAN_30_MCAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_ControllerConfig
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_ControllerConfig
  \brief  Global configuration for all controllers
  \details
  Element                            Description
  BasisAdr                           CAN channel base address
  CanControllerDefaultBaudrate   
  IsTTCan                            TTCAN channel support
  CanControllerDefaultBaudrateIdx
  MailboxRxBasicEndIdx               the end index of the 0:n relation pointing to Can_30_Mcan_Mailbox
  MailboxRxBasicLength               the number of relations pointing to Can_30_Mcan_Mailbox
  MailboxRxBasicStartIdx             the start index of the 0:n relation pointing to Can_30_Mcan_Mailbox
  MailboxTxBasicEndIdx               the end index of the 0:n relation pointing to Can_30_Mcan_Mailbox
  MailboxTxBasicLength               the number of relations pointing to Can_30_Mcan_Mailbox
  MailboxTxBasicStartIdx             the start index of the 0:n relation pointing to Can_30_Mcan_Mailbox
  RxBasicHwStart                 
  RxBasicHwStop                  
  RxFullHwStart                  
  RxFullHwStop                   
  TxBasicHwStart                 
  TxBasicHwStop                  
  TxFullHwStart                  
  TxFullHwStop                   
  UnusedHwStart                  
  UnusedHwStop                   
*/ 
#define CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_30_Mcan_ControllerConfigType, CAN_30_MCAN_CONST) Can_30_Mcan_ControllerConfig[2];
#define CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_FBTP
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_FBTP
  \brief  Fast Bit Timing and Prescaler
*/ 
#define CAN_30_MCAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_30_Mcan_FBTPType, CAN_30_MCAN_CONST) Can_30_Mcan_FBTP[2];
#define CAN_30_MCAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_GFC
**********************************************************************************************************************/
#define CAN_30_MCAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_30_Mcan_GFCType, CAN_30_MCAN_CONST) Can_30_Mcan_GFC[2];
#define CAN_30_MCAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_InitObjectBaudrate
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_InitObjectBaudrate
  \brief  baudrates ('InitStruct' as index)
*/ 
#define CAN_30_MCAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_30_Mcan_InitObjectBaudrateType, CAN_30_MCAN_CONST) Can_30_Mcan_InitObjectBaudrate[2];
#define CAN_30_MCAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_InitObjectFdBrsConfig
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_InitObjectFdBrsConfig
  \brief  FD config ('BaudrateObject' as index)
*/ 
#define CAN_30_MCAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_30_Mcan_InitObjectFdBrsConfigType, CAN_30_MCAN_CONST) Can_30_Mcan_InitObjectFdBrsConfig[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CAN_30_MCAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_InitObjectStartIndex
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_InitObjectStartIndex
  \brief  Start index of 'InitStruct' / baudratesets (controllers as index)
*/ 
#define CAN_30_MCAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_30_Mcan_InitObjectStartIndexType, CAN_30_MCAN_CONST) Can_30_Mcan_InitObjectStartIndex[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CAN_30_MCAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_Mailbox
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_Mailbox
  \brief  mailbox configuration (over all controllers)
  \details
  Element                Description
  ActiveSendObject   
  ControllerConfigIdx    the index of the 1:1 relation pointing to Can_30_Mcan_ControllerConfig
  FdPadding          
  HwHandle           
  IDValue            
  MailboxSize        
  MailboxType        
  MaxDataLen         
  MemorySectionsIndex
*/ 
#define CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_30_Mcan_MailboxType, CAN_30_MCAN_CONST) Can_30_Mcan_Mailbox[4];
#define CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_MemorySectionInfo
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_MemorySectionInfo
  \brief  Memory section description
  \details
  Element               Description
  MemorySectionStart
*/ 
#define CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_30_Mcan_MemorySectionInfoType, CAN_30_MCAN_CONST) Can_30_Mcan_MemorySectionInfo[2];
#define CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_MemorySectionObjects
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_MemorySectionObjects
  \brief  Memory section objects description
  \details
  Element           Description
  HwHandle      
  MailboxElement
  MailboxHandle 
*/ 
#define CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_30_Mcan_MemorySectionObjectsType, CAN_30_MCAN_CONST) Can_30_Mcan_MemorySectionObjects[64];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_SIDFC
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_SIDFC
  \brief  Standard ID filter configuration
  \details
  Element          Description
  FLSSA            Filter List Standard Start Address
  LSS              List size standard
  SIDFEEndIdx      the end index of the 0:n relation pointing to Can_30_Mcan_SIDFE
  SIDFEStartIdx    the start index of the 0:n relation pointing to Can_30_Mcan_SIDFE
*/ 
#define CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_30_Mcan_SIDFCType, CAN_30_MCAN_CONST) Can_30_Mcan_SIDFC[2];
#define CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_SIDFE
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_SIDFE
  \brief  Standard ID filters
*/ 
#define CAN_30_MCAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_30_Mcan_SIDFEType, CAN_30_MCAN_CONST) Can_30_Mcan_SIDFE[2];
#define CAN_30_MCAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_ShmAdr
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_ShmAdr
  \brief  CAN Shared Message RAM configuration
  \details
  Element     Description
  RXBA        RX Buffer Address
  RXF0A       RX FIFO0 Address
  RXF1A       RX FIFO1 Address
  SIDFA       Standard Filters Address
  StartAdr    Start address of the shared memory area
  StopAdr     Stop address of the shared memory area
  TXBA        TX Buffer address
  TXEFA       TX Event FIFO address
  XIDFA       Extended Filters Address
*/ 
#define CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_30_Mcan_ShmAdrType, CAN_30_MCAN_CONST) Can_30_Mcan_ShmAdr[2];
#define CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_ShmElementSize
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_ShmElementSize
  \brief  data buffer size in case of CAN_FD Full
  \details
  Element    Description
  F0DS   
  F1DS   
  RBDS   
  TBDS   
  TEFBDS 
*/ 
#define CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_30_Mcan_ShmElementSizeType, CAN_30_MCAN_CONST) Can_30_Mcan_ShmElementSize[2];
#define CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_TDCR
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_TDCR
  \brief  Transmitter Delay Compensation
*/ 
#define CAN_30_MCAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_30_Mcan_TDCRType, CAN_30_MCAN_CONST) Can_30_Mcan_TDCR[2];
#define CAN_30_MCAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_XIDAM
**********************************************************************************************************************/
#define CAN_30_MCAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_30_Mcan_XIDAMType, CAN_30_MCAN_CONST) Can_30_Mcan_XIDAM[2];
#define CAN_30_MCAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_XIDFC
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_XIDFC
  \brief  Extended ID filter configuration
  \details
  Element          Description
  FLESA            Filter List Extended Start Address
  LSE              List size extended
  XIDFEEndIdx      the end index of the 0:n relation pointing to Can_30_Mcan_XIDFE
  XIDFEStartIdx    the start index of the 0:n relation pointing to Can_30_Mcan_XIDFE
*/ 
#define CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_30_Mcan_XIDFCType, CAN_30_MCAN_CONST) Can_30_Mcan_XIDFC[2];
#define CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_XIDFE
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_XIDFE
  \brief  Extended ID filters
  \details
  Element    Description
  EIDFE_0
  EIDFE_1
*/ 
#define CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_30_Mcan_XIDFEType, CAN_30_MCAN_CONST) Can_30_Mcan_XIDFE[2];
#define CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_ActiveSendObject
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_ActiveSendObject
  \brief  temporary data for TX object
  \details
  Element    Description
  Pdu        buffered PduId for confirmation or cancellation
  State      send state like cancelled or send activ
*/ 
#define CAN_30_MCAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Can_30_Mcan_ActiveSendObjectType, CAN_30_MCAN_VAR_NOINIT) Can_30_Mcan_ActiveSendObject[2];
#define CAN_30_MCAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_ControllerData
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_ControllerData
  \brief  struct for all controller related variable data
  \details
  Element                      Description
  IntEnable                    CAN Interrupt Enable state for each controller
  NonFdObjectsPendingFlag      CAN Tx Objects pending with CAN-FD format
  TXBCR                        CAN Tx Buffer Cancellation Request for each controller
  TXBRP                        CAN Tx Buffer request Pending for each controller
  BusOffNotification           CAN state for each controller: busoff occur
  BusOffTransitionRequest      CAN state request for each controller: ContinueBusOffRecovery=0x00, FinishBusOffRecovery=0x01
  CanInterruptCounter          CAN interrupt disable counter for each controller
  IsBusOff                     CAN state for each controller: busoff occur
  LastInitObject               last set baudrate for reinit
  LastState                    CAN mode transition request status for each controller
  LogStatus                    CAN state for each controller: UNINIT=0x00, START=0x01, STOP=0x02, INIT=0x04, INCONSISTENT=0x08, WARNING =0x10, PASSIVE=0x20, BUSOFF=0x40, SLEEP=0x80
  ModeTransitionRequest        CAN state request for each controller: INIT=0x00, SLEEP=0x01, WAKEUP=0x02, STOP+INIT=0x03, START=0x04, START+INIT=0x05, NONE=0x06
  PrevMode                     CAN mode transition request for each controller
  RamCheckTransitionRequest    CAN state request for each controller: kCanSuppressRamCheck=0x01, kCanExecuteRamCheck=0x00
  CanInterruptOldStatus        last CAN interrupt status for restore interrupt for each controller
  LoopTimeout                  hw loop timeout for each controller
*/ 
#define CAN_30_MCAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Can_30_Mcan_ControllerDataType, CAN_30_MCAN_VAR_NOINIT) Can_30_Mcan_ControllerData[2];
#define CAN_30_MCAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_MailboxState
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_MailboxState
  \brief  state of mailbox (e.g. deactivated)
*/ 
#define CAN_30_MCAN_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Can_30_Mcan_MailboxStateType, CAN_30_MCAN_VAR_NOINIT) Can_30_Mcan_MailboxState[4];
#define CAN_30_MCAN_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/* -----------------------------------------------------------------------------
    UserConfigFile
 ----------------------------------------------------------------------------- */
/* User Config File Start */

/* User Config File End */



#endif  /* CAN_30_MCAN_CFG_H */
/**********************************************************************************************************************
  END OF FILE: Can_30_Mcan_Cfg.h
**********************************************************************************************************************/
 

