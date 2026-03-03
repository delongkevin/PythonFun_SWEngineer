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
 *              File: Xcp_Cfg.h
 *   Generation Time: 2024-02-13 13:07:50
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

    
#if !defined(__XCP_CFG_H__)
#define __XCP_CFG_H__ /* PRQA S 0602, 0603 */ /* MD_XCP_0602_03 */

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


/* Development error detecting and reporting */
#define XCP_DEV_ERROR_DETECT                 STD_ON
#define XCP_DEV_ERROR_REPORT                 STD_ON

/* General settings */
#define XCP_BOOTLOADER_DOWNLOAD              STD_OFF
#define XCP_CONTROL                          STD_ON
#define XCP_AMD_RUNTIME_MEASUREMENT          STD_OFF
#define XCP_VERSION_INFO_API                 STD_ON 
#define XCP_GET_SESSION_STATUS_API           STD_OFF
#define XCP_TYPESAVE_COPY                    STD_OFF
#define XCP_DAQ_MEM_ACCESS_BY_APPL			 STD_OFF
/* Legacy settings */
#define XCP_DISABLE_UNALIGNED_MEM_ACCESS
#define XCP_ENABLE_SEND_QUEUE

/* Service Request Message */
#define XCP_SERV_TEXT                        STD_OFF
#define XCP_SEND_EVENT                       STD_OFF

/* Commands */
#define XCP_OPEN_COMMAND_IF                  STD_OFF

/*  - Standard Commands */
#define XCP_BLOCK_UPLOAD                     STD_OFF
#define XCP_COMM_MODE_INFO                   STD_ON
#define XCP_USER_COMMAND                     STD_OFF
#define XCP_SEED_KEY                         STD_OFF
#define XCP_READ_PROTECTION                  STD_OFF
#define XCP_GET_ID_GENERIC                   STD_ON
#define kXcpStationIdLength                  (0u)

/*    - CRC */
#define XCP_CHECKSUM                         STD_OFF
#define XCP_CUSTOM_CRC                       STD_OFF
#define XCP_AUTOSAR_CRC_MODULE               STD_OFF
#define kXcpChecksumMethod                   XCP_CHECKSUM_TYPE_NONE
#define kXcpChecksumBlockSize                (0u)

/*  - Calibration commands */
#define XCP_CALIBRATION                      STD_ON
#define XCP_BLOCK_DOWNLOAD                   STD_OFF
#define XCP_MODIFY_BITS                      STD_ON
#define XCP_SHORT_DOWNLOAD                   STD_OFF
#define XCP_BLOCK_DOWNLOAD_MIN_ST            (0u)

/*  - Synchronous Data Acquisition (DAQ) commands */
#define XCP_DAQ                              STD_ON
#define XCP_NUMBER_OF_CORES                  (1u)
#define XCP_DAQ_COMPLEMENTARY_CHANNEL        STD_OFF
#define XCP_STIM                             STD_OFF
#define XCP_DAQ_PRESCALER                    STD_OFF
#define XCP_DAQ_OVERRUN_INDICATION           STD_ON
#define XCP_WRITE_DAQ_MULTIPLE               STD_OFF
#define XCP_DAQ_HDR_LEN                      (0x00u + 1U)
#define XCP_DAQ_RESUME                       STD_OFF
#define XCP_DAQ_PROCESSOR_INFO               STD_ON
#define XCP_DAQ_RESOLUTION_INFO              STD_ON

#define XCP_MAX_DAQ                          (1U)
#define XCP_MAX_ODT_DAQ                      (123u)
#define XCP_MAX_ODT_ENTRIES                  (124u)
#define XCP_MAX_ODT_STIM                     (0u)

/*    - DAQ event Info */
#define XCP_DAQ_EVENT_INFO                   STD_ON
#define XCP_MAX_EVENT                        (1u)

/*    - DAQ Timestamp */
#define XCP_DAQ_TIMESTAMP_FIXED              STD_OFF
#define XCP_DAQ_TIMESTAMP_SIZE               XCP_DAQ_TIMESTAMP_OFF
#define XCP_DAQ_TIMESTAMP_UNIT               XCP_DAQ_TIMESTAMP_UNIT_1MS
#define XCP_DAQ_TIMESTAMP_TICKS_PER_UNIT     (1U)

/*  - Page switching */
#define XCP_CALIBRATION_PAGE                 STD_OFF
#define XCP_PAGE_INFO                        STD_OFF
#define XCP_MAX_SEGMENT                      (0u)
#define XCP_MAX_PAGES                        (0u)
#define XCP_PAGE_COPY                        STD_OFF
#define XCP_PAGE_FREEZE                      STD_OFF
#define XCP_COPY_CAL_PAGE                    STD_OFF

/*  - Programming */
#define XCP_PROGRAM                          STD_OFF
#define XCP_PROGRAMMING_WRITE_PROTECTION     STD_OFF
#define XCP_MAX_SECTOR                       (0u)
#define XCP_PROGRAM_INFO                     STD_OFF
#define kXcpProgramMinStPgm                  (0u)

#ifndef XCP_AUTOSARVERSION
#define XCP_AUTOSARVERSION                   (4u) 
#endif

#define XCP_CANOE_EMU                        STD_OFF


/* -----------------------------------------------------------------------------
    &&&~ Multiple transport layer support
 ----------------------------------------------------------------------------- */

#define XCP_MAX_CTO_MAX                      (8u)
#define XCP_MAX_DTO_MAX                      (8u)
/* Multiple transport layer support */
#define XCP_NUMBER_OF_TRANSPORTLAYERS        (1u)
#define XCP_NUMBER_OF_CHANNELS               ((1U))               

#define XCP_TRANSPORT_LAYER_TYPE_CAN_ASR
#define XCP_TRANSPORT_LAYER_CAN              (0u)

/* -----------------------------------------------------------------------------
    &&&~ FlexRay parameter access
 ----------------------------------------------------------------------------- */

#define XCP_READCCCONFIG                     STD_OFF
#define XCP_ADDR_EXT_READCCCONFIG            (0u)
    

/* end Fileversion check */

#endif /* __XCP_CFG_H__ */

