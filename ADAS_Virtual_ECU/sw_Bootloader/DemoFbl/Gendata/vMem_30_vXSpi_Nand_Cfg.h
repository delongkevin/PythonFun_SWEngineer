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
 *            Module: vMem_30_vXSpi_Nand
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vMem_30_vXSpi_Nand_Cfg.h
 *   Generation Time: 2024-11-25 15:00:21
 *           Project: DemoFbl - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined (VMEM_30_VXSPI_NAND_CFG_H)
# define VMEM_30_VXSPI_NAND_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"

/**********************************************************************************************************************
 *  VERSION INFORMATION
 *********************************************************************************************************************/

/*! \brief Version defines of generator version */
# define VMEM_30_VXSPI_NAND_CFG_MAJOR_VERSION        1u
# define VMEM_30_VXSPI_NAND_CFG_MINOR_VERSION        2u
# define VMEM_30_VXSPI_NAND_CFG_PATCH_VERSION        0u

/*! \brief Version defines that are used to check the compatibility of the generated data */
# define VMEM_30_VXSPI_NAND_CFG_COMP_MAJOR_VERSION   1u
# define VMEM_30_VXSPI_NAND_CFG_COMP_MINOR_VERSION   1u
# define VMEM_30_VXSPI_NAND_CFG_COMP_PATCH_VERSION   0u


/**********************************************************************************************************************
 *  GENERAL DEFINE BLOCK
 *********************************************************************************************************************/
# ifndef VMEM_30_VXSPI_NAND_USE_DUMMY_STATEMENT
#  define VMEM_30_VXSPI_NAND_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
# endif
# ifndef VMEM_30_VXSPI_NAND_DUMMY_STATEMENT
#  define VMEM_30_VXSPI_NAND_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
# endif
# ifndef VMEM_30_VXSPI_NAND_DUMMY_STATEMENT_CONST
#  define VMEM_30_VXSPI_NAND_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
# endif
# ifndef VMEM_30_VXSPI_NAND_ATOMIC_BIT_ACCESS_IN_BITFIELD
#  define VMEM_30_VXSPI_NAND_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
# endif
# ifndef VMEM_30_VXSPI_NAND_ATOMIC_VARIABLE_ACCESS
#  define VMEM_30_VXSPI_NAND_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
# endif
# ifndef VMEM_30_VXSPI_NAND_PROCESSOR_TDA4VE88
#  define VMEM_30_VXSPI_NAND_PROCESSOR_TDA4VE88
# endif
# ifndef VMEM_30_VXSPI_NAND_COMP_LLVMTEXASINSTRUMENTS
#  define VMEM_30_VXSPI_NAND_COMP_LLVMTEXASINSTRUMENTS
# endif
# ifndef VMEM_30_VXSPI_NAND_GEN_GENERATOR_MSR
#  define VMEM_30_VXSPI_NAND_GEN_GENERATOR_MSR
# endif
# ifndef VMEM_30_VXSPI_NAND_CPUTYPE_BITORDER_LSB2MSB
#  define VMEM_30_VXSPI_NAND_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
# endif
# ifndef VMEM_30_VXSPI_NAND_CONFIGURATION_VARIANT_PRECOMPILE
#  define VMEM_30_VXSPI_NAND_CONFIGURATION_VARIANT_PRECOMPILE 1
# endif
# ifndef VMEM_30_VXSPI_NAND_CONFIGURATION_VARIANT_LINKTIME
#  define VMEM_30_VXSPI_NAND_CONFIGURATION_VARIANT_LINKTIME 2
# endif
# ifndef VMEM_30_VXSPI_NAND_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#  define VMEM_30_VXSPI_NAND_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
# endif
# ifndef VMEM_30_VXSPI_NAND_CONFIGURATION_VARIANT
#  define VMEM_30_VXSPI_NAND_CONFIGURATION_VARIANT VMEM_30_VXSPI_NAND_CONFIGURATION_VARIANT_PRECOMPILE
# endif
# ifndef VMEM_30_VXSPI_NAND_POSTBUILD_VARIANT_SUPPORT
#  define VMEM_30_VXSPI_NAND_POSTBUILD_VARIANT_SUPPORT STD_OFF
# endif


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/*! Enables / disables development error detection */
#ifndef VMEM_30_VXSPI_NAND_DEV_ERROR_DETECT
# define VMEM_30_VXSPI_NAND_DEV_ERROR_DETECT         STD_ON
#endif

/*! Enables / disables development error reporting (enabled whenever error detection is configured) */
#ifndef VMEM_30_VXSPI_NAND_DEV_ERROR_REPORT
# define VMEM_30_VXSPI_NAND_DEV_ERROR_REPORT         STD_ON
#endif

/*! Enables / disables the version information API (VMEM_30_VXSPI_NAND_GetVersionInfo) */
#ifndef VMEM_30_VXSPI_NAND_VERSION_INFO_API
# define VMEM_30_VXSPI_NAND_VERSION_INFO_API         STD_ON
#endif

/*! Maximal number of sectors over all instances */
#define VMEM_30_VXSPI_NAND_MAX_NUM_OF_SECTORS_OF_ALL_INSTANCES         2u

/*! Maximal page size over all instances */
#define VMEM_30_VXSPI_NAND_MAX_PAGE_SIZE_OF_ALL_INSTANCES              4096u

/*! Enables / disables read only mode (This define will only be used if this mode is supported by the vMem low level.) */
#define VMEM_30_VXSPI_NAND_READONLY_MODE             STD_OFF

/*! vMem driver ID */
#define VMEM_30_VXSPI_NAND_DRIVER_ID                 0x438C82A0u

/* Add here additional general GLOBAL CONSTANT MACROS */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK tagId>
 *********************************************************************************************************************/
/* defaultContent */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/


# include "vXSpi.h"

/* Hw specific defines */

# define VMEM_30_VXSPI_NAND_REGISTER_DATA_BUFFER_LENGTH   1u 
# define VMEM_30_VXSPI_NAND_LUT_DATA_BUFFER_LENGTH        40u 
# define VMEM_30_VXSPI_NAND_LUT_MAX_ENTRIES               10u 

/* PRQA S 3453 vMem_30_vXSpi_Nand_LocalFunctionMacros_Tag */ /* MD_MSR_FctLikeMacro */

/* Function-like configuration getter macros for blankcheck buffer parameters. */
#define vMem_30_vXSpi_Nand_LL_Cfg_GetBlankCheckBufferArrayOfPCConfig()             vMem_30_vXSpi_Nand_GetBlankCheckBufferArrayOfPCConfig()

/* Function-like configuration getter macros for instance specific parameters. */
#define vMem_30_vXSpi_Nand_LL_CfgInstance_GetIdOfvMemInstance(InstanceIdx)                            vMem_30_vXSpi_Nand_GetIdOfvMemInstance(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgInstance_GetMemSectorStartIdxOfvMemInstance(InstanceIdx)             vMem_30_vXSpi_Nand_GetMemSectorStartIdxOfvMemInstance(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgInstance_GetMemSectorEndIdxOfvMemInstance(InstanceIdx)               vMem_30_vXSpi_Nand_GetMemSectorEndIdxOfvMemInstance(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgInstance_GetBlankCheckBufferArrayEndIdxOfvMemInstance(InstanceIdx)   vMem_30_vXSpi_Nand_GetBlankCheckBufferArrayOne2SortedNEndIdxOfvMemInstance(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgInstance_GetBlankCheckBufferArrayLengthOfvMemInstance(InstanceIdx)   vMem_30_vXSpi_Nand_GetBlankCheckBufferArrayOne2SortedNLengthOfvMemInstance(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgInstance_GetBlankCheckBufferArrayStartIdxOfvMemInstance(InstanceIdx) vMem_30_vXSpi_Nand_GetBlankCheckBufferArrayOne2SortedNStartIdxOfvMemInstance(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgInstance_GetBusyCheckTimeoutThresholdOfvMemInstance(InstanceIdx)     vMem_30_vXSpi_Nand_GetBusyCheckTimeoutThresholdOfvMemInstance(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgInstance_GetNumberOfDiesOfvMemInstance(InstanceIdx)                  vMem_30_vXSpi_Nand_GetvMemDieLengthOfvMemInstance(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgInstance_GetInstanceIdTovXSpiDeviceId(InstanceId)                    vMem_30_vXSpi_Nand_GetInstanceIdTovXSpiDeviceId(InstanceId)
#define vMem_30_vXSpi_Nand_LL_CfgInstance_IsSoftwareDieSelectUsed(InstanceId)                         vMem_30_vXSpi_Nand_IsSoftwareDieSelectCommandUsedOfvMemInstance(InstanceId)
#define vMem_30_vXSpi_Nand_LL_CfgInstance_GetvMemDieStartIdxOfvMemInstance(InstanceId)                vMem_30_vXSpi_Nand_GetvMemDieStartIdxOfvMemInstance(InstanceId)
#define vMem_30_vXSpi_Nand_LL_CfgInstance_IsAutomatedBadBlockManagmentUsedOfvMemInstance(InstanceIdx) vMem_30_vXSpi_Nand_IsAutomatedBadBlockManagmentOfvMemInstance(InstanceIdx)

/* Function-like configuration getter macros for device specific parameters. */
#define vMem_30_vXSpi_Nand_LL_CfgDevice_IsInputOutputModeRegisterExisting(InstanceIdx)                vMem_30_vXSpi_Nand_IsInputOutputModeRegisterExistingOfvMemDeviceConfig(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetInputOutputModeRegisterAddress(InstanceIdx)                vMem_30_vXSpi_Nand_GetInputOutputModeRegisterAddressOfvMemDeviceConfig(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetInputOutputModeRegisterValue(InstanceIdx)                  vMem_30_vXSpi_Nand_GetInputOutputModeRegisterValueOfvMemDeviceConfig(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetVolatileConfigurationRegisterDataBufferLength(InstanceIdx) vMem_30_vXSpi_Nand_GetVolatileConfigurationRegisterDataBufferLengthOfvMemDeviceConfig(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterBufferReadModeBitMask(InstanceIdx)           vMem_30_vXSpi_Nand_GetStatusRegisterBufferReadModeBitMaskOfvMemDeviceConfig(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterProgramErrorBitMask(InstanceIdx)             vMem_30_vXSpi_Nand_GetStatusRegisterProgramErrorBitMaskOfvMemDeviceConfig(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterEraseErrorBitMask(InstanceIdx)               vMem_30_vXSpi_Nand_GetStatusRegisterEraseErrorBitMaskOfvMemDeviceConfig(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterBusyFlagBitMask(InstanceIdx)                 vMem_30_vXSpi_Nand_GetStatusRegisterBusyFlagBitMaskOfvMemDeviceConfig(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterEcc0BitMask(InstanceIdx)                     vMem_30_vXSpi_Nand_GetStatusRegisterEcc0BitMaskOfvMemDeviceConfig(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterEcc1BitMask(InstanceIdx)                     vMem_30_vXSpi_Nand_GetStatusRegisterEcc1BitMaskOfvMemDeviceConfig(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterProtectionBitMask(InstanceIdx)               vMem_30_vXSpi_Nand_GetStatusRegisterProtectionBitMaskOfvMemDeviceConfig(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterLutFBitMask(InstanceIdx)                     vMem_30_vXSpi_Nand_GetStatusRegisterLutFBitMaskOfvMemDeviceConfig(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetEraseValue(InstanceIdx)                                    vMem_30_vXSpi_Nand_GetEraseValueOfvMemDeviceConfig(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegister1Address(InstanceIdx)                        vMem_30_vXSpi_Nand_GetStatusRegister1AddressOfvMemDeviceConfig(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegister2Address(InstanceIdx)                        vMem_30_vXSpi_Nand_GetStatusRegister2AddressOfvMemDeviceConfig(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegister3Address(InstanceIdx)                        vMem_30_vXSpi_Nand_GetStatusRegister3AddressOfvMemDeviceConfig(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterDataBufferLength(InstanceIdx)                vMem_30_vXSpi_Nand_GetStatusRegisterDataBufferLengthOfvMemDeviceConfig(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetLutDataBufferLength(InstanceIdx)                           vMem_30_vXSpi_Nand_GetLutDataBufferLengthOfvMemDeviceConfig(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetLutMaxEntries(InstanceIdx)                                 vMem_30_vXSpi_Nand_GetLutMaxEntriesOfvMemDeviceConfig(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetLutEntryLength(InstanceIdx)                                vMem_30_vXSpi_Nand_GetLutEntryLengthOfvMemDeviceConfig(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetLutAddressLength(InstanceIdx)                              vMem_30_vXSpi_Nand_GetLutAddressLengthOfvMemDeviceConfig(InstanceIdx)

/* Function-like configuration getter macros for sector specific parameters. */
#define vMem_30_vXSpi_Nand_LL_CfgSector_GetNrOfSectorsOfMemSector(SectorIdx)                          vMem_30_vXSpi_Nand_GetNrOfSectorsOfMemSector(SectorIdx)
#define vMem_30_vXSpi_Nand_LL_CfgSector_GetSectorSizeOfMemSector(SectorIdx)                           vMem_30_vXSpi_Nand_GetSectorSizeOfMemSector(SectorIdx)
#define vMem_30_vXSpi_Nand_LL_CfgSector_GetPageSizeOfMemSector(SectorIdx)                             vMem_30_vXSpi_Nand_GetPageSizeOfMemSector(SectorIdx)
#define vMem_30_vXSpi_Nand_LL_CfgSector_GetStartAddressOfMemSector(SectorIdx)                         vMem_30_vXSpi_Nand_GetStartAddressOfMemSector(SectorIdx)
#define vMem_30_vXSpi_Nand_LL_CfgSector_GetvMemDieIdxOfMemSector(SectorIdx)                           vMem_30_vXSpi_Nand_GetvMemDieIdxOfMemSector(SectorIdx)
#define vMem_30_vXSpi_Nand_LL_CfgSector_IsReplacementSector(SectorIdx)                                vMem_30_vXSpi_Nand_IsReplacementSectorOfMemSector(SectorIdx)

/* Function-like configuration getter macros for die specific parameters. */
#define vMem_30_vXSpi_Nand_LL_CfgDie_GetDieIdOfvMemDie(DieIdx)                                        vMem_30_vXSpi_Nand_GetDieIdOfvMemDie(DieIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDie_GetDieSizeOfvMemDie(DieIdx)                                      vMem_30_vXSpi_Nand_GetDieSizeOfvMemDie(DieIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDie_GetDieStartAddressOfvMemDie(DieIdx)                              vMem_30_vXSpi_Nand_GetDieStartAddressOfvMemDie(DieIdx)

/* Function-like configuration getter macros for commands. */
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetFlsDevicePageDataReadCommand(InstanceIdx)                  vMem_30_vXSpi_Nand_GetPageDataReadCmdOfvMemFlsCmdTbl(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetFlsDeviceReadCommand(InstanceIdx)                          vMem_30_vXSpi_Nand_GetReadCmdOfvMemFlsCmdTbl(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetFlsDeviceReadBbmLutCommand(InstanceIdx)                    vMem_30_vXSpi_Nand_GetReadBbmLutCmdOfvMemFlsCmdTbl(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetFlsDeviceReplaceLogicalSectorCommand(InstanceIdx)          vMem_30_vXSpi_Nand_GetReplaceLogicalBlocksCmdOfvMemFlsCmdTbl(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetFlsDeviceProgramExecuteCommand(InstanceIdx)                vMem_30_vXSpi_Nand_GetProgramExecuteCmdOfvMemFlsCmdTbl(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetFlsDeviceProgramDataLoadCommand(InstanceIdx)               vMem_30_vXSpi_Nand_GetProgramDataLoadCmdOfvMemFlsCmdTbl(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetFlsDeviceWriteEnableCommand(InstanceIdx)                   vMem_30_vXSpi_Nand_GetWriteEnableCmdOfvMemFlsCmdTbl(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetFlsDeviceDummyCycleCommand(InstanceIdx)                    vMem_30_vXSpi_Nand_GetDummyCycleCmdOfvMemFlsCmdTbl(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetFlsDeviceEraseCommand(InstanceIdx)                         vMem_30_vXSpi_Nand_GetEraseCmdOfvMemFlsCmdTbl(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetFlsDeviceReadStatusRegisterCommand(InstanceIdx)            vMem_30_vXSpi_Nand_GetReadStatusRegisterCmdOfvMemFlsCmdTbl(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetFlsDeviceWriteStatusRegisterCommand(InstanceIdx)           vMem_30_vXSpi_Nand_GetWriteStatusRegisterCmdOfvMemFlsCmdTbl(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetFlsDeviceReadConfigSectorLayoutCommand(InstanceIdx)        vMem_30_vXSpi_Nand_GetReadConfigSectorLayoutCmdOfvMemFlsCmdTbl(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetFlsDeviceWriteConfigSectorLayoutCommand(InstanceIdx)       vMem_30_vXSpi_Nand_GetWriteConfigSectorLayoutCmdOfvMemFlsCmdTbl(InstanceIdx)
#define vMem_30_vXSpi_Nand_LL_CfgDevice_GetFlsDeviceSelectDieCommand(InstanceIdx)                     vMem_30_vXSpi_Nand_GetSoftwareDieSelectCmdOfvMemFlsCmdTbl(InstanceIdx)

/* PRQA L:vMem_30_vXSpi_Nand_LocalFunctionMacros_Tag */

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/* Hw specific global data types and structures */

typedef vXSpi_ProtocolModeIdType vMem_30_vXSpi_Nand_vXSpiProtocolModeIdType;

/*! Defines the possible address format values. */
typedef enum
{
  VMEM_30_VXSPI_NAND_ADDRESS_FORMAT_0_BYTE,
  VMEM_30_VXSPI_NAND_ADDRESS_FORMAT_1_BYTE,
  VMEM_30_VXSPI_NAND_ADDRESS_FORMAT_2_BYTE,
  VMEM_30_VXSPI_NAND_ADDRESS_FORMAT_3_BYTE,
  VMEM_30_VXSPI_NAND_ADDRESS_FORMAT_4_BYTE
} vMem_30_vXSpi_Nand_AddressFormatType;


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  vMem_30_vXSpi_NandPCDataSwitches  vMem_30_vXSpi_Nand Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define VMEM_30_VXSPI_NAND_BLANKCHECKBUFFERARRAY                      STD_ON
#define VMEM_30_VXSPI_NAND_FINALMAGICNUMBER                           STD_OFF  /**< Deactivateable: 'vMem_30_vXSpi_Nand_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define VMEM_30_VXSPI_NAND_INITDATAHASHCODE                           STD_OFF  /**< Deactivateable: 'vMem_30_vXSpi_Nand_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define VMEM_30_VXSPI_NAND_INSTANCEIDTOVXSPIDEVICEID                  STD_ON
#define VMEM_30_VXSPI_NAND_MEMSECTOR                                  STD_ON
#define VMEM_30_VXSPI_NAND_ERASEBURSTSIZEOFMEMSECTOR                  STD_ON
#define VMEM_30_VXSPI_NAND_NROFSECTORSOFMEMSECTOR                     STD_ON
#define VMEM_30_VXSPI_NAND_PAGESIZEOFMEMSECTOR                        STD_ON
#define VMEM_30_VXSPI_NAND_RAMALIGNMENTOFMEMSECTOR                    STD_ON
#define VMEM_30_VXSPI_NAND_REPLACEMENTSECTOROFMEMSECTOR               STD_ON
#define VMEM_30_VXSPI_NAND_SECTORSIZEOFMEMSECTOR                      STD_ON
#define VMEM_30_VXSPI_NAND_STARTADDRESSOFMEMSECTOR                    STD_ON
#define VMEM_30_VXSPI_NAND_WRITEBURSTSIZEOFMEMSECTOR                  STD_ON
#define VMEM_30_VXSPI_NAND_VMEMDIEIDXOFMEMSECTOR                      STD_ON
#define VMEM_30_VXSPI_NAND_SIZEOFBLANKCHECKBUFFERARRAY                STD_ON
#define VMEM_30_VXSPI_NAND_SIZEOFINSTANCEIDTOVXSPIDEVICEID            STD_ON
#define VMEM_30_VXSPI_NAND_SIZEOFMEMSECTOR                            STD_ON
#define VMEM_30_VXSPI_NAND_SIZEOFVMEMDEVICECONFIG                     STD_ON
#define VMEM_30_VXSPI_NAND_SIZEOFVMEMDIE                              STD_ON
#define VMEM_30_VXSPI_NAND_SIZEOFVMEMFLSCMDADDRESSFORMATVALUE         STD_ON
#define VMEM_30_VXSPI_NAND_SIZEOFVMEMFLSCMDDUMMYCYCLEVALUE            STD_ON
#define VMEM_30_VXSPI_NAND_SIZEOFVMEMFLSCMDVALUE                      STD_ON
#define VMEM_30_VXSPI_NAND_SIZEOFVMEMINSTANCE                         STD_ON
#define VMEM_30_VXSPI_NAND_VMEMDEVICECONFIG                           STD_ON
#define VMEM_30_VXSPI_NAND_ERASEVALUEOFVMEMDEVICECONFIG               STD_ON
#define VMEM_30_VXSPI_NAND_INPUTOUTPUTMODEREGISTERADDRESSOFVMEMDEVICECONFIG STD_ON
#define VMEM_30_VXSPI_NAND_INPUTOUTPUTMODEREGISTEREXISTINGOFVMEMDEVICECONFIG STD_ON
#define VMEM_30_VXSPI_NAND_INPUTOUTPUTMODEREGISTERVALUEOFVMEMDEVICECONFIG STD_ON
#define VMEM_30_VXSPI_NAND_LUTADDRESSLENGTHOFVMEMDEVICECONFIG         STD_ON
#define VMEM_30_VXSPI_NAND_LUTDATABUFFERLENGTHOFVMEMDEVICECONFIG      STD_ON
#define VMEM_30_VXSPI_NAND_LUTENTRYLENGTHOFVMEMDEVICECONFIG           STD_ON
#define VMEM_30_VXSPI_NAND_LUTMAXENTRIESOFVMEMDEVICECONFIG            STD_ON
#define VMEM_30_VXSPI_NAND_STATUSREGISTER1ADDRESSOFVMEMDEVICECONFIG   STD_ON
#define VMEM_30_VXSPI_NAND_STATUSREGISTER2ADDRESSOFVMEMDEVICECONFIG   STD_ON
#define VMEM_30_VXSPI_NAND_STATUSREGISTER3ADDRESSOFVMEMDEVICECONFIG   STD_ON
#define VMEM_30_VXSPI_NAND_STATUSREGISTERBUFFERREADMODEBITMASKOFVMEMDEVICECONFIG STD_ON
#define VMEM_30_VXSPI_NAND_STATUSREGISTERBUSYFLAGBITMASKOFVMEMDEVICECONFIG STD_ON
#define VMEM_30_VXSPI_NAND_STATUSREGISTERDATABUFFERLENGTHOFVMEMDEVICECONFIG STD_ON
#define VMEM_30_VXSPI_NAND_STATUSREGISTERECC0BITMASKOFVMEMDEVICECONFIG STD_ON
#define VMEM_30_VXSPI_NAND_STATUSREGISTERECC1BITMASKOFVMEMDEVICECONFIG STD_ON
#define VMEM_30_VXSPI_NAND_STATUSREGISTERERASEERRORBITMASKOFVMEMDEVICECONFIG STD_ON
#define VMEM_30_VXSPI_NAND_STATUSREGISTERLUTFBITMASKOFVMEMDEVICECONFIG STD_ON
#define VMEM_30_VXSPI_NAND_STATUSREGISTERPROGRAMERRORBITMASKOFVMEMDEVICECONFIG STD_ON
#define VMEM_30_VXSPI_NAND_STATUSREGISTERPROTECTIONBITMASKOFVMEMDEVICECONFIG STD_ON
#define VMEM_30_VXSPI_NAND_VOLATILECONFIGURATIONREGISTERDATABUFFERLENGTHOFVMEMDEVICECONFIG STD_ON
#define VMEM_30_VXSPI_NAND_VMEMDIE                                    STD_ON
#define VMEM_30_VXSPI_NAND_DIEIDOFVMEMDIE                             STD_OFF  /**< Deactivateable: 'vMem_30_vXSpi_Nand_vMemDie.DieId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VMEM_30_VXSPI_NAND_DIESIZEOFVMEMDIE                           STD_ON
#define VMEM_30_VXSPI_NAND_DIESTARTADDRESSOFVMEMDIE                   STD_ON
#define VMEM_30_VXSPI_NAND_VMEMFLSCMDADDRESSFORMATVALUE               STD_ON
#define VMEM_30_VXSPI_NAND_ERASECMDOFVMEMFLSCMDADDRESSFORMATVALUE     STD_ON
#define VMEM_30_VXSPI_NAND_PAGEDATAREADCMDOFVMEMFLSCMDADDRESSFORMATVALUE STD_ON
#define VMEM_30_VXSPI_NAND_PROGRAMDATALOADCMDOFVMEMFLSCMDADDRESSFORMATVALUE STD_ON
#define VMEM_30_VXSPI_NAND_PROGRAMEXECUTECMDOFVMEMFLSCMDADDRESSFORMATVALUE STD_ON
#define VMEM_30_VXSPI_NAND_READBBMLUTCMDOFVMEMFLSCMDADDRESSFORMATVALUE STD_ON
#define VMEM_30_VXSPI_NAND_READCMDOFVMEMFLSCMDADDRESSFORMATVALUE      STD_ON
#define VMEM_30_VXSPI_NAND_READSTATUSREGISTERCMDOFVMEMFLSCMDADDRESSFORMATVALUE STD_ON
#define VMEM_30_VXSPI_NAND_READVOLATILECONFIGURATIONREGISTERCMDOFVMEMFLSCMDADDRESSFORMATVALUE STD_ON
#define VMEM_30_VXSPI_NAND_REPLACELOGICALBLOCKSCMDOFVMEMFLSCMDADDRESSFORMATVALUE STD_ON
#define VMEM_30_VXSPI_NAND_SOFTWAREDIESELECTCMDOFVMEMFLSCMDADDRESSFORMATVALUE STD_ON
#define VMEM_30_VXSPI_NAND_WRITEENABLECMDOFVMEMFLSCMDADDRESSFORMATVALUE STD_ON
#define VMEM_30_VXSPI_NAND_WRITESTATUSREGISTERCMDOFVMEMFLSCMDADDRESSFORMATVALUE STD_ON
#define VMEM_30_VXSPI_NAND_WRITEVOLATILECONFIGURATIONREGISTERCMDOFVMEMFLSCMDADDRESSFORMATVALUE STD_ON
#define VMEM_30_VXSPI_NAND_VMEMFLSCMDDUMMYCYCLEVALUE                  STD_ON
#define VMEM_30_VXSPI_NAND_ERASECMDOFVMEMFLSCMDDUMMYCYCLEVALUE        STD_ON
#define VMEM_30_VXSPI_NAND_PAGEDATAREADCMDOFVMEMFLSCMDDUMMYCYCLEVALUE STD_ON
#define VMEM_30_VXSPI_NAND_PROGRAMDATALOADCMDOFVMEMFLSCMDDUMMYCYCLEVALUE STD_ON
#define VMEM_30_VXSPI_NAND_PROGRAMEXECUTECMDOFVMEMFLSCMDDUMMYCYCLEVALUE STD_ON
#define VMEM_30_VXSPI_NAND_READBBMLUTCMDOFVMEMFLSCMDDUMMYCYCLEVALUE   STD_ON
#define VMEM_30_VXSPI_NAND_READCMDOFVMEMFLSCMDDUMMYCYCLEVALUE         STD_ON
#define VMEM_30_VXSPI_NAND_READSTATUSREGISTERCMDOFVMEMFLSCMDDUMMYCYCLEVALUE STD_ON
#define VMEM_30_VXSPI_NAND_READVOLATILECONFIGURATIONREGISTERCMDOFVMEMFLSCMDDUMMYCYCLEVALUE STD_ON
#define VMEM_30_VXSPI_NAND_REPLACELOGICALBLOCKSCMDOFVMEMFLSCMDDUMMYCYCLEVALUE STD_ON
#define VMEM_30_VXSPI_NAND_SOFTWAREDIESELECTCMDOFVMEMFLSCMDDUMMYCYCLEVALUE STD_ON
#define VMEM_30_VXSPI_NAND_WRITEENABLECMDOFVMEMFLSCMDDUMMYCYCLEVALUE  STD_ON
#define VMEM_30_VXSPI_NAND_WRITESTATUSREGISTERCMDOFVMEMFLSCMDDUMMYCYCLEVALUE STD_ON
#define VMEM_30_VXSPI_NAND_WRITEVOLATILECONFIGURATIONREGISTERCMDOFVMEMFLSCMDDUMMYCYCLEVALUE STD_ON
#define VMEM_30_VXSPI_NAND_VMEMFLSCMDVALUE                            STD_ON
#define VMEM_30_VXSPI_NAND_ERASECMDOFVMEMFLSCMDVALUE                  STD_ON
#define VMEM_30_VXSPI_NAND_PAGEDATAREADCMDOFVMEMFLSCMDVALUE           STD_ON
#define VMEM_30_VXSPI_NAND_PROGRAMDATALOADCMDOFVMEMFLSCMDVALUE        STD_ON
#define VMEM_30_VXSPI_NAND_PROGRAMEXECUTECMDOFVMEMFLSCMDVALUE         STD_ON
#define VMEM_30_VXSPI_NAND_READBBMLUTCMDOFVMEMFLSCMDVALUE             STD_ON
#define VMEM_30_VXSPI_NAND_READCMDOFVMEMFLSCMDVALUE                   STD_ON
#define VMEM_30_VXSPI_NAND_READSTATUSREGISTERCMDOFVMEMFLSCMDVALUE     STD_ON
#define VMEM_30_VXSPI_NAND_READVOLATILECONFIGURATIONREGISTERCMDOFVMEMFLSCMDVALUE STD_ON
#define VMEM_30_VXSPI_NAND_REPLACELOGICALBLOCKSCMDOFVMEMFLSCMDVALUE   STD_ON
#define VMEM_30_VXSPI_NAND_SOFTWAREDIESELECTCMDOFVMEMFLSCMDVALUE      STD_ON
#define VMEM_30_VXSPI_NAND_WRITEENABLECMDOFVMEMFLSCMDVALUE            STD_ON
#define VMEM_30_VXSPI_NAND_WRITESTATUSREGISTERCMDOFVMEMFLSCMDVALUE    STD_ON
#define VMEM_30_VXSPI_NAND_WRITEVOLATILECONFIGURATIONREGISTERCMDOFVMEMFLSCMDVALUE STD_ON
#define VMEM_30_VXSPI_NAND_VMEMINSTANCE                               STD_ON
#define VMEM_30_VXSPI_NAND_AUTOMATEDBADBLOCKMANAGMENTOFVMEMINSTANCE   STD_ON
#define VMEM_30_VXSPI_NAND_BLANKCHECKBUFFERARRAYONE2SORTEDNENDIDXOFVMEMINSTANCE STD_ON
#define VMEM_30_VXSPI_NAND_BLANKCHECKBUFFERARRAYONE2SORTEDNLENGTHOFVMEMINSTANCE STD_ON
#define VMEM_30_VXSPI_NAND_BLANKCHECKBUFFERARRAYONE2SORTEDNSTARTIDXOFVMEMINSTANCE STD_ON
#define VMEM_30_VXSPI_NAND_BUSYCHECKTIMEOUTTHRESHOLDOFVMEMINSTANCE    STD_ON
#define VMEM_30_VXSPI_NAND_GENERICPROTOCOLMODEIDOFVMEMINSTANCE        STD_ON
#define VMEM_30_VXSPI_NAND_IDOFVMEMINSTANCE                           STD_ON
#define VMEM_30_VXSPI_NAND_MEMSECTORENDIDXOFVMEMINSTANCE              STD_ON
#define VMEM_30_VXSPI_NAND_MEMSECTORLENGTHOFVMEMINSTANCE              STD_ON
#define VMEM_30_VXSPI_NAND_MEMSECTORSTARTIDXOFVMEMINSTANCE            STD_ON
#define VMEM_30_VXSPI_NAND_READDATAPROTOCOLMODEIDOFVMEMINSTANCE       STD_ON
#define VMEM_30_VXSPI_NAND_SOFTWAREDIESELECTCOMMANDUSEDOFVMEMINSTANCE STD_ON
#define VMEM_30_VXSPI_NAND_WRITEDATAPROTOCOLMODEIDOFVMEMINSTANCE      STD_ON
#define VMEM_30_VXSPI_NAND_VMEMDIEENDIDXOFVMEMINSTANCE                STD_ON
#define VMEM_30_VXSPI_NAND_VMEMDIELENGTHOFVMEMINSTANCE                STD_ON
#define VMEM_30_VXSPI_NAND_VMEMDIESTARTIDXOFVMEMINSTANCE              STD_ON
#define VMEM_30_VXSPI_NAND_PCCONFIG                                   STD_ON
#define VMEM_30_VXSPI_NAND_BLANKCHECKBUFFERARRAYOFPCCONFIG            STD_ON
#define VMEM_30_VXSPI_NAND_FINALMAGICNUMBEROFPCCONFIG                 STD_OFF  /**< Deactivateable: 'vMem_30_vXSpi_Nand_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define VMEM_30_VXSPI_NAND_INITDATAHASHCODEOFPCCONFIG                 STD_OFF  /**< Deactivateable: 'vMem_30_vXSpi_Nand_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define VMEM_30_VXSPI_NAND_INSTANCEIDTOVXSPIDEVICEIDOFPCCONFIG        STD_ON
#define VMEM_30_VXSPI_NAND_MEMSECTOROFPCCONFIG                        STD_ON
#define VMEM_30_VXSPI_NAND_SIZEOFBLANKCHECKBUFFERARRAYOFPCCONFIG      STD_ON
#define VMEM_30_VXSPI_NAND_SIZEOFINSTANCEIDTOVXSPIDEVICEIDOFPCCONFIG  STD_ON
#define VMEM_30_VXSPI_NAND_SIZEOFMEMSECTOROFPCCONFIG                  STD_ON
#define VMEM_30_VXSPI_NAND_SIZEOFVMEMDEVICECONFIGOFPCCONFIG           STD_ON
#define VMEM_30_VXSPI_NAND_SIZEOFVMEMDIEOFPCCONFIG                    STD_ON
#define VMEM_30_VXSPI_NAND_SIZEOFVMEMFLSCMDADDRESSFORMATVALUEOFPCCONFIG STD_ON
#define VMEM_30_VXSPI_NAND_SIZEOFVMEMFLSCMDDUMMYCYCLEVALUEOFPCCONFIG  STD_ON
#define VMEM_30_VXSPI_NAND_SIZEOFVMEMFLSCMDVALUEOFPCCONFIG            STD_ON
#define VMEM_30_VXSPI_NAND_SIZEOFVMEMINSTANCEOFPCCONFIG               STD_ON
#define VMEM_30_VXSPI_NAND_VMEMDEVICECONFIGOFPCCONFIG                 STD_ON
#define VMEM_30_VXSPI_NAND_VMEMDIEOFPCCONFIG                          STD_ON
#define VMEM_30_VXSPI_NAND_VMEMFLSCMDADDRESSFORMATVALUEOFPCCONFIG     STD_ON
#define VMEM_30_VXSPI_NAND_VMEMFLSCMDDUMMYCYCLEVALUEOFPCCONFIG        STD_ON
#define VMEM_30_VXSPI_NAND_VMEMFLSCMDVALUEOFPCCONFIG                  STD_ON
#define VMEM_30_VXSPI_NAND_VMEMINSTANCEOFPCCONFIG                     STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_vXSpi_NandPCMinNumericValueDefines  vMem_30_vXSpi_Nand Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define VMEM_30_VXSPI_NAND_MIN_BLANKCHECKBUFFERARRAY                  0u
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_vXSpi_NandPCMaxNumericValueDefines  vMem_30_vXSpi_Nand Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define VMEM_30_VXSPI_NAND_MAX_BLANKCHECKBUFFERARRAY                  255u
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_vXSpi_NandPCIsReducedToDefineDefines  vMem_30_vXSpi_Nand Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define VMEM_30_VXSPI_NAND_ISDEF_INSTANCEIDTOVXSPIDEVICEID            STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_ERASEBURSTSIZEOFMEMSECTOR            STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_NROFSECTORSOFMEMSECTOR               STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_PAGESIZEOFMEMSECTOR                  STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_RAMALIGNMENTOFMEMSECTOR              STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_REPLACEMENTSECTOROFMEMSECTOR         STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_SECTORSIZEOFMEMSECTOR                STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_STARTADDRESSOFMEMSECTOR              STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_WRITEBURSTSIZEOFMEMSECTOR            STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_VMEMDIEIDXOFMEMSECTOR                STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_ERASEVALUEOFVMEMDEVICECONFIG         STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_INPUTOUTPUTMODEREGISTERADDRESSOFVMEMDEVICECONFIG STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_INPUTOUTPUTMODEREGISTEREXISTINGOFVMEMDEVICECONFIG STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_INPUTOUTPUTMODEREGISTERVALUEOFVMEMDEVICECONFIG STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_LUTADDRESSLENGTHOFVMEMDEVICECONFIG   STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_LUTDATABUFFERLENGTHOFVMEMDEVICECONFIG STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_LUTENTRYLENGTHOFVMEMDEVICECONFIG     STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_LUTMAXENTRIESOFVMEMDEVICECONFIG      STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_STATUSREGISTER1ADDRESSOFVMEMDEVICECONFIG STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_STATUSREGISTER2ADDRESSOFVMEMDEVICECONFIG STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_STATUSREGISTER3ADDRESSOFVMEMDEVICECONFIG STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_STATUSREGISTERBUFFERREADMODEBITMASKOFVMEMDEVICECONFIG STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_STATUSREGISTERBUSYFLAGBITMASKOFVMEMDEVICECONFIG STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_STATUSREGISTERDATABUFFERLENGTHOFVMEMDEVICECONFIG STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_STATUSREGISTERECC0BITMASKOFVMEMDEVICECONFIG STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_STATUSREGISTERECC1BITMASKOFVMEMDEVICECONFIG STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_STATUSREGISTERERASEERRORBITMASKOFVMEMDEVICECONFIG STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_STATUSREGISTERLUTFBITMASKOFVMEMDEVICECONFIG STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_STATUSREGISTERPROGRAMERRORBITMASKOFVMEMDEVICECONFIG STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_STATUSREGISTERPROTECTIONBITMASKOFVMEMDEVICECONFIG STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_VOLATILECONFIGURATIONREGISTERDATABUFFERLENGTHOFVMEMDEVICECONFIG STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_DIESIZEOFVMEMDIE                     STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_DIESTARTADDRESSOFVMEMDIE             STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_ERASECMDOFVMEMFLSCMDADDRESSFORMATVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_PAGEDATAREADCMDOFVMEMFLSCMDADDRESSFORMATVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_PROGRAMDATALOADCMDOFVMEMFLSCMDADDRESSFORMATVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_PROGRAMEXECUTECMDOFVMEMFLSCMDADDRESSFORMATVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_READBBMLUTCMDOFVMEMFLSCMDADDRESSFORMATVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_READCMDOFVMEMFLSCMDADDRESSFORMATVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_READSTATUSREGISTERCMDOFVMEMFLSCMDADDRESSFORMATVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_READVOLATILECONFIGURATIONREGISTERCMDOFVMEMFLSCMDADDRESSFORMATVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_REPLACELOGICALBLOCKSCMDOFVMEMFLSCMDADDRESSFORMATVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_SOFTWAREDIESELECTCMDOFVMEMFLSCMDADDRESSFORMATVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_WRITEENABLECMDOFVMEMFLSCMDADDRESSFORMATVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_WRITESTATUSREGISTERCMDOFVMEMFLSCMDADDRESSFORMATVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_WRITEVOLATILECONFIGURATIONREGISTERCMDOFVMEMFLSCMDADDRESSFORMATVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_ERASECMDOFVMEMFLSCMDDUMMYCYCLEVALUE  STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_PAGEDATAREADCMDOFVMEMFLSCMDDUMMYCYCLEVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_PROGRAMDATALOADCMDOFVMEMFLSCMDDUMMYCYCLEVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_PROGRAMEXECUTECMDOFVMEMFLSCMDDUMMYCYCLEVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_READBBMLUTCMDOFVMEMFLSCMDDUMMYCYCLEVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_READCMDOFVMEMFLSCMDDUMMYCYCLEVALUE   STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_READSTATUSREGISTERCMDOFVMEMFLSCMDDUMMYCYCLEVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_READVOLATILECONFIGURATIONREGISTERCMDOFVMEMFLSCMDDUMMYCYCLEVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_REPLACELOGICALBLOCKSCMDOFVMEMFLSCMDDUMMYCYCLEVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_SOFTWAREDIESELECTCMDOFVMEMFLSCMDDUMMYCYCLEVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_WRITEENABLECMDOFVMEMFLSCMDDUMMYCYCLEVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_WRITESTATUSREGISTERCMDOFVMEMFLSCMDDUMMYCYCLEVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_WRITEVOLATILECONFIGURATIONREGISTERCMDOFVMEMFLSCMDDUMMYCYCLEVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_ERASECMDOFVMEMFLSCMDVALUE            STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_PAGEDATAREADCMDOFVMEMFLSCMDVALUE     STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_PROGRAMDATALOADCMDOFVMEMFLSCMDVALUE  STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_PROGRAMEXECUTECMDOFVMEMFLSCMDVALUE   STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_READBBMLUTCMDOFVMEMFLSCMDVALUE       STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_READCMDOFVMEMFLSCMDVALUE             STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_READSTATUSREGISTERCMDOFVMEMFLSCMDVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_READVOLATILECONFIGURATIONREGISTERCMDOFVMEMFLSCMDVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_REPLACELOGICALBLOCKSCMDOFVMEMFLSCMDVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_SOFTWAREDIESELECTCMDOFVMEMFLSCMDVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_WRITEENABLECMDOFVMEMFLSCMDVALUE      STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_WRITESTATUSREGISTERCMDOFVMEMFLSCMDVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_WRITEVOLATILECONFIGURATIONREGISTERCMDOFVMEMFLSCMDVALUE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_AUTOMATEDBADBLOCKMANAGMENTOFVMEMINSTANCE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_BLANKCHECKBUFFERARRAYONE2SORTEDNENDIDXOFVMEMINSTANCE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_BLANKCHECKBUFFERARRAYONE2SORTEDNLENGTHOFVMEMINSTANCE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_BLANKCHECKBUFFERARRAYONE2SORTEDNSTARTIDXOFVMEMINSTANCE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_BUSYCHECKTIMEOUTTHRESHOLDOFVMEMINSTANCE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_GENERICPROTOCOLMODEIDOFVMEMINSTANCE  STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_IDOFVMEMINSTANCE                     STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_MEMSECTORENDIDXOFVMEMINSTANCE        STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_MEMSECTORLENGTHOFVMEMINSTANCE        STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_MEMSECTORSTARTIDXOFVMEMINSTANCE      STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_READDATAPROTOCOLMODEIDOFVMEMINSTANCE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_SOFTWAREDIESELECTCOMMANDUSEDOFVMEMINSTANCE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_WRITEDATAPROTOCOLMODEIDOFVMEMINSTANCE STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_VMEMDIEENDIDXOFVMEMINSTANCE          STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_VMEMDIELENGTHOFVMEMINSTANCE          STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_VMEMDIESTARTIDXOFVMEMINSTANCE        STD_OFF
#define VMEM_30_VXSPI_NAND_ISDEF_BLANKCHECKBUFFERARRAYOFPCCONFIG      STD_ON
#define VMEM_30_VXSPI_NAND_ISDEF_INSTANCEIDTOVXSPIDEVICEIDOFPCCONFIG  STD_ON
#define VMEM_30_VXSPI_NAND_ISDEF_MEMSECTOROFPCCONFIG                  STD_ON
#define VMEM_30_VXSPI_NAND_ISDEF_VMEMDEVICECONFIGOFPCCONFIG           STD_ON
#define VMEM_30_VXSPI_NAND_ISDEF_VMEMDIEOFPCCONFIG                    STD_ON
#define VMEM_30_VXSPI_NAND_ISDEF_VMEMFLSCMDADDRESSFORMATVALUEOFPCCONFIG STD_ON
#define VMEM_30_VXSPI_NAND_ISDEF_VMEMFLSCMDDUMMYCYCLEVALUEOFPCCONFIG  STD_ON
#define VMEM_30_VXSPI_NAND_ISDEF_VMEMFLSCMDVALUEOFPCCONFIG            STD_ON
#define VMEM_30_VXSPI_NAND_ISDEF_VMEMINSTANCEOFPCCONFIG               STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_vXSpi_NandPCEqualsAlwaysToDefines  vMem_30_vXSpi_Nand Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define VMEM_30_VXSPI_NAND_EQ2_INSTANCEIDTOVXSPIDEVICEID              
#define VMEM_30_VXSPI_NAND_EQ2_ERASEBURSTSIZEOFMEMSECTOR              
#define VMEM_30_VXSPI_NAND_EQ2_NROFSECTORSOFMEMSECTOR                 
#define VMEM_30_VXSPI_NAND_EQ2_PAGESIZEOFMEMSECTOR                    
#define VMEM_30_VXSPI_NAND_EQ2_RAMALIGNMENTOFMEMSECTOR                
#define VMEM_30_VXSPI_NAND_EQ2_REPLACEMENTSECTOROFMEMSECTOR           
#define VMEM_30_VXSPI_NAND_EQ2_SECTORSIZEOFMEMSECTOR                  
#define VMEM_30_VXSPI_NAND_EQ2_STARTADDRESSOFMEMSECTOR                
#define VMEM_30_VXSPI_NAND_EQ2_WRITEBURSTSIZEOFMEMSECTOR              
#define VMEM_30_VXSPI_NAND_EQ2_VMEMDIEIDXOFMEMSECTOR                  
#define VMEM_30_VXSPI_NAND_EQ2_ERASEVALUEOFVMEMDEVICECONFIG           
#define VMEM_30_VXSPI_NAND_EQ2_INPUTOUTPUTMODEREGISTERADDRESSOFVMEMDEVICECONFIG 
#define VMEM_30_VXSPI_NAND_EQ2_INPUTOUTPUTMODEREGISTEREXISTINGOFVMEMDEVICECONFIG 
#define VMEM_30_VXSPI_NAND_EQ2_INPUTOUTPUTMODEREGISTERVALUEOFVMEMDEVICECONFIG 
#define VMEM_30_VXSPI_NAND_EQ2_LUTADDRESSLENGTHOFVMEMDEVICECONFIG     
#define VMEM_30_VXSPI_NAND_EQ2_LUTDATABUFFERLENGTHOFVMEMDEVICECONFIG  
#define VMEM_30_VXSPI_NAND_EQ2_LUTENTRYLENGTHOFVMEMDEVICECONFIG       
#define VMEM_30_VXSPI_NAND_EQ2_LUTMAXENTRIESOFVMEMDEVICECONFIG        
#define VMEM_30_VXSPI_NAND_EQ2_STATUSREGISTER1ADDRESSOFVMEMDEVICECONFIG 
#define VMEM_30_VXSPI_NAND_EQ2_STATUSREGISTER2ADDRESSOFVMEMDEVICECONFIG 
#define VMEM_30_VXSPI_NAND_EQ2_STATUSREGISTER3ADDRESSOFVMEMDEVICECONFIG 
#define VMEM_30_VXSPI_NAND_EQ2_STATUSREGISTERBUFFERREADMODEBITMASKOFVMEMDEVICECONFIG 
#define VMEM_30_VXSPI_NAND_EQ2_STATUSREGISTERBUSYFLAGBITMASKOFVMEMDEVICECONFIG 
#define VMEM_30_VXSPI_NAND_EQ2_STATUSREGISTERDATABUFFERLENGTHOFVMEMDEVICECONFIG 
#define VMEM_30_VXSPI_NAND_EQ2_STATUSREGISTERECC0BITMASKOFVMEMDEVICECONFIG 
#define VMEM_30_VXSPI_NAND_EQ2_STATUSREGISTERECC1BITMASKOFVMEMDEVICECONFIG 
#define VMEM_30_VXSPI_NAND_EQ2_STATUSREGISTERERASEERRORBITMASKOFVMEMDEVICECONFIG 
#define VMEM_30_VXSPI_NAND_EQ2_STATUSREGISTERLUTFBITMASKOFVMEMDEVICECONFIG 
#define VMEM_30_VXSPI_NAND_EQ2_STATUSREGISTERPROGRAMERRORBITMASKOFVMEMDEVICECONFIG 
#define VMEM_30_VXSPI_NAND_EQ2_STATUSREGISTERPROTECTIONBITMASKOFVMEMDEVICECONFIG 
#define VMEM_30_VXSPI_NAND_EQ2_VOLATILECONFIGURATIONREGISTERDATABUFFERLENGTHOFVMEMDEVICECONFIG 
#define VMEM_30_VXSPI_NAND_EQ2_DIESIZEOFVMEMDIE                       
#define VMEM_30_VXSPI_NAND_EQ2_DIESTARTADDRESSOFVMEMDIE               
#define VMEM_30_VXSPI_NAND_EQ2_ERASECMDOFVMEMFLSCMDADDRESSFORMATVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_PAGEDATAREADCMDOFVMEMFLSCMDADDRESSFORMATVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_PROGRAMDATALOADCMDOFVMEMFLSCMDADDRESSFORMATVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_PROGRAMEXECUTECMDOFVMEMFLSCMDADDRESSFORMATVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_READBBMLUTCMDOFVMEMFLSCMDADDRESSFORMATVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_READCMDOFVMEMFLSCMDADDRESSFORMATVALUE  
#define VMEM_30_VXSPI_NAND_EQ2_READSTATUSREGISTERCMDOFVMEMFLSCMDADDRESSFORMATVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_READVOLATILECONFIGURATIONREGISTERCMDOFVMEMFLSCMDADDRESSFORMATVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_REPLACELOGICALBLOCKSCMDOFVMEMFLSCMDADDRESSFORMATVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_SOFTWAREDIESELECTCMDOFVMEMFLSCMDADDRESSFORMATVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_WRITEENABLECMDOFVMEMFLSCMDADDRESSFORMATVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_WRITESTATUSREGISTERCMDOFVMEMFLSCMDADDRESSFORMATVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_WRITEVOLATILECONFIGURATIONREGISTERCMDOFVMEMFLSCMDADDRESSFORMATVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_ERASECMDOFVMEMFLSCMDDUMMYCYCLEVALUE    
#define VMEM_30_VXSPI_NAND_EQ2_PAGEDATAREADCMDOFVMEMFLSCMDDUMMYCYCLEVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_PROGRAMDATALOADCMDOFVMEMFLSCMDDUMMYCYCLEVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_PROGRAMEXECUTECMDOFVMEMFLSCMDDUMMYCYCLEVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_READBBMLUTCMDOFVMEMFLSCMDDUMMYCYCLEVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_READCMDOFVMEMFLSCMDDUMMYCYCLEVALUE     
#define VMEM_30_VXSPI_NAND_EQ2_READSTATUSREGISTERCMDOFVMEMFLSCMDDUMMYCYCLEVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_READVOLATILECONFIGURATIONREGISTERCMDOFVMEMFLSCMDDUMMYCYCLEVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_REPLACELOGICALBLOCKSCMDOFVMEMFLSCMDDUMMYCYCLEVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_SOFTWAREDIESELECTCMDOFVMEMFLSCMDDUMMYCYCLEVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_WRITEENABLECMDOFVMEMFLSCMDDUMMYCYCLEVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_WRITESTATUSREGISTERCMDOFVMEMFLSCMDDUMMYCYCLEVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_WRITEVOLATILECONFIGURATIONREGISTERCMDOFVMEMFLSCMDDUMMYCYCLEVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_ERASECMDOFVMEMFLSCMDVALUE              
#define VMEM_30_VXSPI_NAND_EQ2_PAGEDATAREADCMDOFVMEMFLSCMDVALUE       
#define VMEM_30_VXSPI_NAND_EQ2_PROGRAMDATALOADCMDOFVMEMFLSCMDVALUE    
#define VMEM_30_VXSPI_NAND_EQ2_PROGRAMEXECUTECMDOFVMEMFLSCMDVALUE     
#define VMEM_30_VXSPI_NAND_EQ2_READBBMLUTCMDOFVMEMFLSCMDVALUE         
#define VMEM_30_VXSPI_NAND_EQ2_READCMDOFVMEMFLSCMDVALUE               
#define VMEM_30_VXSPI_NAND_EQ2_READSTATUSREGISTERCMDOFVMEMFLSCMDVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_READVOLATILECONFIGURATIONREGISTERCMDOFVMEMFLSCMDVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_REPLACELOGICALBLOCKSCMDOFVMEMFLSCMDVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_SOFTWAREDIESELECTCMDOFVMEMFLSCMDVALUE  
#define VMEM_30_VXSPI_NAND_EQ2_WRITEENABLECMDOFVMEMFLSCMDVALUE        
#define VMEM_30_VXSPI_NAND_EQ2_WRITESTATUSREGISTERCMDOFVMEMFLSCMDVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_WRITEVOLATILECONFIGURATIONREGISTERCMDOFVMEMFLSCMDVALUE 
#define VMEM_30_VXSPI_NAND_EQ2_AUTOMATEDBADBLOCKMANAGMENTOFVMEMINSTANCE 
#define VMEM_30_VXSPI_NAND_EQ2_BLANKCHECKBUFFERARRAYONE2SORTEDNENDIDXOFVMEMINSTANCE 
#define VMEM_30_VXSPI_NAND_EQ2_BLANKCHECKBUFFERARRAYONE2SORTEDNLENGTHOFVMEMINSTANCE 
#define VMEM_30_VXSPI_NAND_EQ2_BLANKCHECKBUFFERARRAYONE2SORTEDNSTARTIDXOFVMEMINSTANCE 
#define VMEM_30_VXSPI_NAND_EQ2_BUSYCHECKTIMEOUTTHRESHOLDOFVMEMINSTANCE 
#define VMEM_30_VXSPI_NAND_EQ2_GENERICPROTOCOLMODEIDOFVMEMINSTANCE    
#define VMEM_30_VXSPI_NAND_EQ2_IDOFVMEMINSTANCE                       
#define VMEM_30_VXSPI_NAND_EQ2_MEMSECTORENDIDXOFVMEMINSTANCE          
#define VMEM_30_VXSPI_NAND_EQ2_MEMSECTORLENGTHOFVMEMINSTANCE          
#define VMEM_30_VXSPI_NAND_EQ2_MEMSECTORSTARTIDXOFVMEMINSTANCE        
#define VMEM_30_VXSPI_NAND_EQ2_READDATAPROTOCOLMODEIDOFVMEMINSTANCE   
#define VMEM_30_VXSPI_NAND_EQ2_SOFTWAREDIESELECTCOMMANDUSEDOFVMEMINSTANCE 
#define VMEM_30_VXSPI_NAND_EQ2_WRITEDATAPROTOCOLMODEIDOFVMEMINSTANCE  
#define VMEM_30_VXSPI_NAND_EQ2_VMEMDIEENDIDXOFVMEMINSTANCE            
#define VMEM_30_VXSPI_NAND_EQ2_VMEMDIELENGTHOFVMEMINSTANCE            
#define VMEM_30_VXSPI_NAND_EQ2_VMEMDIESTARTIDXOFVMEMINSTANCE          
#define VMEM_30_VXSPI_NAND_EQ2_BLANKCHECKBUFFERARRAYOFPCCONFIG        vMem_30_vXSpi_Nand_BlankCheckBufferArray.raw
#define VMEM_30_VXSPI_NAND_EQ2_INSTANCEIDTOVXSPIDEVICEIDOFPCCONFIG    vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId
#define VMEM_30_VXSPI_NAND_EQ2_MEMSECTOROFPCCONFIG                    vMem_30_vXSpi_Nand_MemSector
#define VMEM_30_VXSPI_NAND_EQ2_VMEMDEVICECONFIGOFPCCONFIG             vMem_30_vXSpi_Nand_vMemDeviceConfig
#define VMEM_30_VXSPI_NAND_EQ2_VMEMDIEOFPCCONFIG                      vMem_30_vXSpi_Nand_vMemDie
#define VMEM_30_VXSPI_NAND_EQ2_VMEMFLSCMDADDRESSFORMATVALUEOFPCCONFIG vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValue
#define VMEM_30_VXSPI_NAND_EQ2_VMEMFLSCMDDUMMYCYCLEVALUEOFPCCONFIG    vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue
#define VMEM_30_VXSPI_NAND_EQ2_VMEMFLSCMDVALUEOFPCCONFIG              vMem_30_vXSpi_Nand_vMemFlsCmdValue
#define VMEM_30_VXSPI_NAND_EQ2_VMEMINSTANCEOFPCCONFIG                 vMem_30_vXSpi_Nand_vMemInstance
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_vXSpi_NandPCSymbolicInitializationPointers  vMem_30_vXSpi_Nand Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define vMem_30_vXSpi_Nand_Config_Ptr                                 NULL_PTR  /**< symbolic identifier which shall be used to initialize 'vMem_30_vXSpi_Nand' */
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_vXSpi_NandPCInitializationSymbols  vMem_30_vXSpi_Nand Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define vMem_30_vXSpi_Nand_Config                                     NULL_PTR  /**< symbolic identifier which could be used to initialize 'vMem_30_vXSpi_Nand */
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_vXSpi_NandPCGeneral  vMem_30_vXSpi_Nand General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define VMEM_30_VXSPI_NAND_CHECK_INIT_POINTER                         STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define VMEM_30_VXSPI_NAND_FINAL_MAGIC_NUMBER                         0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of vMem_30_vXSpi_Nand */
#define VMEM_30_VXSPI_NAND_INDIVIDUAL_POSTBUILD                       STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'vMem_30_vXSpi_Nand' is not configured to be postbuild capable. */
#define VMEM_30_VXSPI_NAND_INIT_DATA                                  VMEM_30_VXSPI_NAND_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define VMEM_30_VXSPI_NAND_INIT_DATA_HASH_CODE                        826547874  /**< the precompile constant to validate the initialization structure at initialization time of vMem_30_vXSpi_Nand with a hashcode. The seed value is '0xFF1Eu' */
#define VMEM_30_VXSPI_NAND_USE_ECUM_BSW_ERROR_HOOK                    STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define VMEM_30_VXSPI_NAND_USE_INIT_POINTER                           STD_OFF  /**< STD_ON if the init pointer vMem_30_vXSpi_Nand shall be used. */
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
  \defgroup  vMem_30_vXSpi_NandPCGetConstantDuplicatedRootDataMacros  vMem_30_vXSpi_Nand Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define vMem_30_vXSpi_Nand_GetBlankCheckBufferArrayOfPCConfig()       vMem_30_vXSpi_Nand_BlankCheckBufferArray.raw  /**< the pointer to vMem_30_vXSpi_Nand_BlankCheckBufferArray */
#define vMem_30_vXSpi_Nand_GetInstanceIdTovXSpiDeviceIdOfPCConfig()   vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId  /**< the pointer to vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId */
#define vMem_30_vXSpi_Nand_GetMemSectorOfPCConfig()                   vMem_30_vXSpi_Nand_MemSector  /**< the pointer to vMem_30_vXSpi_Nand_MemSector */
#define vMem_30_vXSpi_Nand_GetSizeOfBlankCheckBufferArrayOfPCConfig() 4096u  /**< the number of accomplishable value elements in vMem_30_vXSpi_Nand_BlankCheckBufferArray */
#define vMem_30_vXSpi_Nand_GetSizeOfInstanceIdTovXSpiDeviceIdOfPCConfig() 1u  /**< the number of accomplishable value elements in vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId */
#define vMem_30_vXSpi_Nand_GetSizeOfMemSectorOfPCConfig()             2u  /**< the number of accomplishable value elements in vMem_30_vXSpi_Nand_MemSector */
#define vMem_30_vXSpi_Nand_GetSizeOfvMemDeviceConfigOfPCConfig()      1u  /**< the number of accomplishable value elements in vMem_30_vXSpi_Nand_vMemDeviceConfig */
#define vMem_30_vXSpi_Nand_GetSizeOfvMemDieOfPCConfig()               1u  /**< the number of accomplishable value elements in vMem_30_vXSpi_Nand_vMemDie */
#define vMem_30_vXSpi_Nand_GetSizeOfvMemFlsCmdAddressFormatValueOfPCConfig() 1u  /**< the number of accomplishable value elements in vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValue */
#define vMem_30_vXSpi_Nand_GetSizeOfvMemFlsCmdDummyCycleValueOfPCConfig() 1u  /**< the number of accomplishable value elements in vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue */
#define vMem_30_vXSpi_Nand_GetSizeOfvMemFlsCmdValueOfPCConfig()       1u  /**< the number of accomplishable value elements in vMem_30_vXSpi_Nand_vMemFlsCmdValue */
#define vMem_30_vXSpi_Nand_GetSizeOfvMemInstanceOfPCConfig()          1u  /**< the number of accomplishable value elements in vMem_30_vXSpi_Nand_vMemInstance */
#define vMem_30_vXSpi_Nand_GetvMemDeviceConfigOfPCConfig()            vMem_30_vXSpi_Nand_vMemDeviceConfig  /**< the pointer to vMem_30_vXSpi_Nand_vMemDeviceConfig */
#define vMem_30_vXSpi_Nand_GetvMemDieOfPCConfig()                     vMem_30_vXSpi_Nand_vMemDie  /**< the pointer to vMem_30_vXSpi_Nand_vMemDie */
#define vMem_30_vXSpi_Nand_GetvMemFlsCmdAddressFormatValueOfPCConfig() vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValue  /**< the pointer to vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValue */
#define vMem_30_vXSpi_Nand_GetvMemFlsCmdDummyCycleValueOfPCConfig()   vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue  /**< the pointer to vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue */
#define vMem_30_vXSpi_Nand_GetvMemFlsCmdValueOfPCConfig()             vMem_30_vXSpi_Nand_vMemFlsCmdValue  /**< the pointer to vMem_30_vXSpi_Nand_vMemFlsCmdValue */
#define vMem_30_vXSpi_Nand_GetvMemInstanceOfPCConfig()                vMem_30_vXSpi_Nand_vMemInstance  /**< the pointer to vMem_30_vXSpi_Nand_vMemInstance */
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_vXSpi_NandPCGetDataMacros  vMem_30_vXSpi_Nand Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define vMem_30_vXSpi_Nand_GetBlankCheckBufferArray(Index)            (vMem_30_vXSpi_Nand_GetBlankCheckBufferArrayOfPCConfig()[(Index)])
#define vMem_30_vXSpi_Nand_GetInstanceIdTovXSpiDeviceId(Index)        (vMem_30_vXSpi_Nand_GetInstanceIdTovXSpiDeviceIdOfPCConfig()[(Index)])
#define vMem_30_vXSpi_Nand_GetEraseBurstSizeOfMemSector(Index)        (vMem_30_vXSpi_Nand_GetMemSectorOfPCConfig()[(Index)].EraseBurstSizeOfMemSector)
#define vMem_30_vXSpi_Nand_GetNrOfSectorsOfMemSector(Index)           (vMem_30_vXSpi_Nand_GetMemSectorOfPCConfig()[(Index)].NrOfSectorsOfMemSector)
#define vMem_30_vXSpi_Nand_GetPageSizeOfMemSector(Index)              (vMem_30_vXSpi_Nand_GetMemSectorOfPCConfig()[(Index)].PageSizeOfMemSector)
#define vMem_30_vXSpi_Nand_GetRamAlignmentOfMemSector(Index)          (vMem_30_vXSpi_Nand_GetMemSectorOfPCConfig()[(Index)].RamAlignmentOfMemSector)
#define vMem_30_vXSpi_Nand_IsReplacementSectorOfMemSector(Index)      ((vMem_30_vXSpi_Nand_GetMemSectorOfPCConfig()[(Index)].ReplacementSectorOfMemSector) != FALSE)
#define vMem_30_vXSpi_Nand_GetSectorSizeOfMemSector(Index)            (vMem_30_vXSpi_Nand_GetMemSectorOfPCConfig()[(Index)].SectorSizeOfMemSector)
#define vMem_30_vXSpi_Nand_GetStartAddressOfMemSector(Index)          (vMem_30_vXSpi_Nand_GetMemSectorOfPCConfig()[(Index)].StartAddressOfMemSector)
#define vMem_30_vXSpi_Nand_GetWriteBurstSizeOfMemSector(Index)        (vMem_30_vXSpi_Nand_GetMemSectorOfPCConfig()[(Index)].WriteBurstSizeOfMemSector)
#define vMem_30_vXSpi_Nand_GetvMemDieIdxOfMemSector(Index)            (vMem_30_vXSpi_Nand_GetMemSectorOfPCConfig()[(Index)].vMemDieIdxOfMemSector)
#define vMem_30_vXSpi_Nand_GetEraseValueOfvMemDeviceConfig(Index)     (vMem_30_vXSpi_Nand_GetvMemDeviceConfigOfPCConfig()[(Index)].EraseValueOfvMemDeviceConfig)
#define vMem_30_vXSpi_Nand_GetInputOutputModeRegisterAddressOfvMemDeviceConfig(Index) (vMem_30_vXSpi_Nand_GetvMemDeviceConfigOfPCConfig()[(Index)].InputOutputModeRegisterAddressOfvMemDeviceConfig)
#define vMem_30_vXSpi_Nand_IsInputOutputModeRegisterExistingOfvMemDeviceConfig(Index) ((vMem_30_vXSpi_Nand_GetvMemDeviceConfigOfPCConfig()[(Index)].InputOutputModeRegisterExistingOfvMemDeviceConfig) != FALSE)
#define vMem_30_vXSpi_Nand_GetInputOutputModeRegisterValueOfvMemDeviceConfig(Index) (vMem_30_vXSpi_Nand_GetvMemDeviceConfigOfPCConfig()[(Index)].InputOutputModeRegisterValueOfvMemDeviceConfig)
#define vMem_30_vXSpi_Nand_GetLutAddressLengthOfvMemDeviceConfig(Index) (vMem_30_vXSpi_Nand_GetvMemDeviceConfigOfPCConfig()[(Index)].LutAddressLengthOfvMemDeviceConfig)
#define vMem_30_vXSpi_Nand_GetLutDataBufferLengthOfvMemDeviceConfig(Index) (vMem_30_vXSpi_Nand_GetvMemDeviceConfigOfPCConfig()[(Index)].LutDataBufferLengthOfvMemDeviceConfig)
#define vMem_30_vXSpi_Nand_GetLutEntryLengthOfvMemDeviceConfig(Index) (vMem_30_vXSpi_Nand_GetvMemDeviceConfigOfPCConfig()[(Index)].LutEntryLengthOfvMemDeviceConfig)
#define vMem_30_vXSpi_Nand_GetLutMaxEntriesOfvMemDeviceConfig(Index)  (vMem_30_vXSpi_Nand_GetvMemDeviceConfigOfPCConfig()[(Index)].LutMaxEntriesOfvMemDeviceConfig)
#define vMem_30_vXSpi_Nand_GetStatusRegister1AddressOfvMemDeviceConfig(Index) (vMem_30_vXSpi_Nand_GetvMemDeviceConfigOfPCConfig()[(Index)].StatusRegister1AddressOfvMemDeviceConfig)
#define vMem_30_vXSpi_Nand_GetStatusRegister2AddressOfvMemDeviceConfig(Index) (vMem_30_vXSpi_Nand_GetvMemDeviceConfigOfPCConfig()[(Index)].StatusRegister2AddressOfvMemDeviceConfig)
#define vMem_30_vXSpi_Nand_GetStatusRegister3AddressOfvMemDeviceConfig(Index) (vMem_30_vXSpi_Nand_GetvMemDeviceConfigOfPCConfig()[(Index)].StatusRegister3AddressOfvMemDeviceConfig)
#define vMem_30_vXSpi_Nand_GetStatusRegisterBufferReadModeBitMaskOfvMemDeviceConfig(Index) (vMem_30_vXSpi_Nand_GetvMemDeviceConfigOfPCConfig()[(Index)].StatusRegisterBufferReadModeBitMaskOfvMemDeviceConfig)
#define vMem_30_vXSpi_Nand_GetStatusRegisterBusyFlagBitMaskOfvMemDeviceConfig(Index) (vMem_30_vXSpi_Nand_GetvMemDeviceConfigOfPCConfig()[(Index)].StatusRegisterBusyFlagBitMaskOfvMemDeviceConfig)
#define vMem_30_vXSpi_Nand_GetStatusRegisterDataBufferLengthOfvMemDeviceConfig(Index) (vMem_30_vXSpi_Nand_GetvMemDeviceConfigOfPCConfig()[(Index)].StatusRegisterDataBufferLengthOfvMemDeviceConfig)
#define vMem_30_vXSpi_Nand_GetStatusRegisterEcc0BitMaskOfvMemDeviceConfig(Index) (vMem_30_vXSpi_Nand_GetvMemDeviceConfigOfPCConfig()[(Index)].StatusRegisterEcc0BitMaskOfvMemDeviceConfig)
#define vMem_30_vXSpi_Nand_GetStatusRegisterEcc1BitMaskOfvMemDeviceConfig(Index) (vMem_30_vXSpi_Nand_GetvMemDeviceConfigOfPCConfig()[(Index)].StatusRegisterEcc1BitMaskOfvMemDeviceConfig)
#define vMem_30_vXSpi_Nand_GetStatusRegisterEraseErrorBitMaskOfvMemDeviceConfig(Index) (vMem_30_vXSpi_Nand_GetvMemDeviceConfigOfPCConfig()[(Index)].StatusRegisterEraseErrorBitMaskOfvMemDeviceConfig)
#define vMem_30_vXSpi_Nand_GetStatusRegisterLutFBitMaskOfvMemDeviceConfig(Index) (vMem_30_vXSpi_Nand_GetvMemDeviceConfigOfPCConfig()[(Index)].StatusRegisterLutFBitMaskOfvMemDeviceConfig)
#define vMem_30_vXSpi_Nand_GetStatusRegisterProgramErrorBitMaskOfvMemDeviceConfig(Index) (vMem_30_vXSpi_Nand_GetvMemDeviceConfigOfPCConfig()[(Index)].StatusRegisterProgramErrorBitMaskOfvMemDeviceConfig)
#define vMem_30_vXSpi_Nand_GetStatusRegisterProtectionBitMaskOfvMemDeviceConfig(Index) (vMem_30_vXSpi_Nand_GetvMemDeviceConfigOfPCConfig()[(Index)].StatusRegisterProtectionBitMaskOfvMemDeviceConfig)
#define vMem_30_vXSpi_Nand_GetVolatileConfigurationRegisterDataBufferLengthOfvMemDeviceConfig(Index) (vMem_30_vXSpi_Nand_GetvMemDeviceConfigOfPCConfig()[(Index)].VolatileConfigurationRegisterDataBufferLengthOfvMemDeviceConfig)
#define vMem_30_vXSpi_Nand_GetDieSizeOfvMemDie(Index)                 (vMem_30_vXSpi_Nand_GetvMemDieOfPCConfig()[(Index)].DieSizeOfvMemDie)
#define vMem_30_vXSpi_Nand_GetDieStartAddressOfvMemDie(Index)         (vMem_30_vXSpi_Nand_GetvMemDieOfPCConfig()[(Index)].DieStartAddressOfvMemDie)
#define vMem_30_vXSpi_Nand_GetEraseCmdOfvMemFlsCmdAddressFormatValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdAddressFormatValueOfPCConfig()[(Index)].EraseCmdOfvMemFlsCmdAddressFormatValue)
#define vMem_30_vXSpi_Nand_GetPageDataReadCmdOfvMemFlsCmdAddressFormatValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdAddressFormatValueOfPCConfig()[(Index)].PageDataReadCmdOfvMemFlsCmdAddressFormatValue)
#define vMem_30_vXSpi_Nand_GetProgramDataLoadCmdOfvMemFlsCmdAddressFormatValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdAddressFormatValueOfPCConfig()[(Index)].ProgramDataLoadCmdOfvMemFlsCmdAddressFormatValue)
#define vMem_30_vXSpi_Nand_GetProgramExecuteCmdOfvMemFlsCmdAddressFormatValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdAddressFormatValueOfPCConfig()[(Index)].ProgramExecuteCmdOfvMemFlsCmdAddressFormatValue)
#define vMem_30_vXSpi_Nand_GetReadBbmLutCmdOfvMemFlsCmdAddressFormatValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdAddressFormatValueOfPCConfig()[(Index)].ReadBbmLutCmdOfvMemFlsCmdAddressFormatValue)
#define vMem_30_vXSpi_Nand_GetReadCmdOfvMemFlsCmdAddressFormatValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdAddressFormatValueOfPCConfig()[(Index)].ReadCmdOfvMemFlsCmdAddressFormatValue)
#define vMem_30_vXSpi_Nand_GetReadStatusRegisterCmdOfvMemFlsCmdAddressFormatValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdAddressFormatValueOfPCConfig()[(Index)].ReadStatusRegisterCmdOfvMemFlsCmdAddressFormatValue)
#define vMem_30_vXSpi_Nand_GetReadVolatileConfigurationRegisterCmdOfvMemFlsCmdAddressFormatValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdAddressFormatValueOfPCConfig()[(Index)].ReadVolatileConfigurationRegisterCmdOfvMemFlsCmdAddressFormatValue)
#define vMem_30_vXSpi_Nand_GetReplaceLogicalBlocksCmdOfvMemFlsCmdAddressFormatValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdAddressFormatValueOfPCConfig()[(Index)].ReplaceLogicalBlocksCmdOfvMemFlsCmdAddressFormatValue)
#define vMem_30_vXSpi_Nand_GetSoftwareDieSelectCmdOfvMemFlsCmdAddressFormatValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdAddressFormatValueOfPCConfig()[(Index)].SoftwareDieSelectCmdOfvMemFlsCmdAddressFormatValue)
#define vMem_30_vXSpi_Nand_GetWriteEnableCmdOfvMemFlsCmdAddressFormatValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdAddressFormatValueOfPCConfig()[(Index)].WriteEnableCmdOfvMemFlsCmdAddressFormatValue)
#define vMem_30_vXSpi_Nand_GetWriteStatusRegisterCmdOfvMemFlsCmdAddressFormatValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdAddressFormatValueOfPCConfig()[(Index)].WriteStatusRegisterCmdOfvMemFlsCmdAddressFormatValue)
#define vMem_30_vXSpi_Nand_GetWriteVolatileConfigurationRegisterCmdOfvMemFlsCmdAddressFormatValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdAddressFormatValueOfPCConfig()[(Index)].WriteVolatileConfigurationRegisterCmdOfvMemFlsCmdAddressFormatValue)
#define vMem_30_vXSpi_Nand_GetEraseCmdOfvMemFlsCmdDummyCycleValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdDummyCycleValueOfPCConfig()[(Index)].EraseCmdOfvMemFlsCmdDummyCycleValue)
#define vMem_30_vXSpi_Nand_GetPageDataReadCmdOfvMemFlsCmdDummyCycleValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdDummyCycleValueOfPCConfig()[(Index)].PageDataReadCmdOfvMemFlsCmdDummyCycleValue)
#define vMem_30_vXSpi_Nand_GetProgramDataLoadCmdOfvMemFlsCmdDummyCycleValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdDummyCycleValueOfPCConfig()[(Index)].ProgramDataLoadCmdOfvMemFlsCmdDummyCycleValue)
#define vMem_30_vXSpi_Nand_GetProgramExecuteCmdOfvMemFlsCmdDummyCycleValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdDummyCycleValueOfPCConfig()[(Index)].ProgramExecuteCmdOfvMemFlsCmdDummyCycleValue)
#define vMem_30_vXSpi_Nand_GetReadBbmLutCmdOfvMemFlsCmdDummyCycleValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdDummyCycleValueOfPCConfig()[(Index)].ReadBbmLutCmdOfvMemFlsCmdDummyCycleValue)
#define vMem_30_vXSpi_Nand_GetReadCmdOfvMemFlsCmdDummyCycleValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdDummyCycleValueOfPCConfig()[(Index)].ReadCmdOfvMemFlsCmdDummyCycleValue)
#define vMem_30_vXSpi_Nand_GetReadStatusRegisterCmdOfvMemFlsCmdDummyCycleValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdDummyCycleValueOfPCConfig()[(Index)].ReadStatusRegisterCmdOfvMemFlsCmdDummyCycleValue)
#define vMem_30_vXSpi_Nand_GetReadVolatileConfigurationRegisterCmdOfvMemFlsCmdDummyCycleValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdDummyCycleValueOfPCConfig()[(Index)].ReadVolatileConfigurationRegisterCmdOfvMemFlsCmdDummyCycleValue)
#define vMem_30_vXSpi_Nand_GetReplaceLogicalBlocksCmdOfvMemFlsCmdDummyCycleValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdDummyCycleValueOfPCConfig()[(Index)].ReplaceLogicalBlocksCmdOfvMemFlsCmdDummyCycleValue)
#define vMem_30_vXSpi_Nand_GetSoftwareDieSelectCmdOfvMemFlsCmdDummyCycleValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdDummyCycleValueOfPCConfig()[(Index)].SoftwareDieSelectCmdOfvMemFlsCmdDummyCycleValue)
#define vMem_30_vXSpi_Nand_GetWriteEnableCmdOfvMemFlsCmdDummyCycleValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdDummyCycleValueOfPCConfig()[(Index)].WriteEnableCmdOfvMemFlsCmdDummyCycleValue)
#define vMem_30_vXSpi_Nand_GetWriteStatusRegisterCmdOfvMemFlsCmdDummyCycleValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdDummyCycleValueOfPCConfig()[(Index)].WriteStatusRegisterCmdOfvMemFlsCmdDummyCycleValue)
#define vMem_30_vXSpi_Nand_GetWriteVolatileConfigurationRegisterCmdOfvMemFlsCmdDummyCycleValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdDummyCycleValueOfPCConfig()[(Index)].WriteVolatileConfigurationRegisterCmdOfvMemFlsCmdDummyCycleValue)
#define vMem_30_vXSpi_Nand_GetEraseCmdOfvMemFlsCmdValue(Index)        (vMem_30_vXSpi_Nand_GetvMemFlsCmdValueOfPCConfig()[(Index)].EraseCmdOfvMemFlsCmdValue)
#define vMem_30_vXSpi_Nand_GetPageDataReadCmdOfvMemFlsCmdValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdValueOfPCConfig()[(Index)].PageDataReadCmdOfvMemFlsCmdValue)
#define vMem_30_vXSpi_Nand_GetProgramDataLoadCmdOfvMemFlsCmdValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdValueOfPCConfig()[(Index)].ProgramDataLoadCmdOfvMemFlsCmdValue)
#define vMem_30_vXSpi_Nand_GetProgramExecuteCmdOfvMemFlsCmdValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdValueOfPCConfig()[(Index)].ProgramExecuteCmdOfvMemFlsCmdValue)
#define vMem_30_vXSpi_Nand_GetReadBbmLutCmdOfvMemFlsCmdValue(Index)   (vMem_30_vXSpi_Nand_GetvMemFlsCmdValueOfPCConfig()[(Index)].ReadBbmLutCmdOfvMemFlsCmdValue)
#define vMem_30_vXSpi_Nand_GetReadCmdOfvMemFlsCmdValue(Index)         (vMem_30_vXSpi_Nand_GetvMemFlsCmdValueOfPCConfig()[(Index)].ReadCmdOfvMemFlsCmdValue)
#define vMem_30_vXSpi_Nand_GetReadStatusRegisterCmdOfvMemFlsCmdValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdValueOfPCConfig()[(Index)].ReadStatusRegisterCmdOfvMemFlsCmdValue)
#define vMem_30_vXSpi_Nand_GetReadVolatileConfigurationRegisterCmdOfvMemFlsCmdValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdValueOfPCConfig()[(Index)].ReadVolatileConfigurationRegisterCmdOfvMemFlsCmdValue)
#define vMem_30_vXSpi_Nand_GetReplaceLogicalBlocksCmdOfvMemFlsCmdValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdValueOfPCConfig()[(Index)].ReplaceLogicalBlocksCmdOfvMemFlsCmdValue)
#define vMem_30_vXSpi_Nand_GetSoftwareDieSelectCmdOfvMemFlsCmdValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdValueOfPCConfig()[(Index)].SoftwareDieSelectCmdOfvMemFlsCmdValue)
#define vMem_30_vXSpi_Nand_GetWriteEnableCmdOfvMemFlsCmdValue(Index)  (vMem_30_vXSpi_Nand_GetvMemFlsCmdValueOfPCConfig()[(Index)].WriteEnableCmdOfvMemFlsCmdValue)
#define vMem_30_vXSpi_Nand_GetWriteStatusRegisterCmdOfvMemFlsCmdValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdValueOfPCConfig()[(Index)].WriteStatusRegisterCmdOfvMemFlsCmdValue)
#define vMem_30_vXSpi_Nand_GetWriteVolatileConfigurationRegisterCmdOfvMemFlsCmdValue(Index) (vMem_30_vXSpi_Nand_GetvMemFlsCmdValueOfPCConfig()[(Index)].WriteVolatileConfigurationRegisterCmdOfvMemFlsCmdValue)
#define vMem_30_vXSpi_Nand_IsAutomatedBadBlockManagmentOfvMemInstance(Index) ((vMem_30_vXSpi_Nand_GetvMemInstanceOfPCConfig()[(Index)].AutomatedBadBlockManagmentOfvMemInstance) != FALSE)
#define vMem_30_vXSpi_Nand_GetBlankCheckBufferArrayOne2SortedNEndIdxOfvMemInstance(Index) (vMem_30_vXSpi_Nand_GetvMemInstanceOfPCConfig()[(Index)].BlankCheckBufferArrayOne2SortedNEndIdxOfvMemInstance)
#define vMem_30_vXSpi_Nand_GetBlankCheckBufferArrayOne2SortedNLengthOfvMemInstance(Index) (vMem_30_vXSpi_Nand_GetvMemInstanceOfPCConfig()[(Index)].BlankCheckBufferArrayOne2SortedNLengthOfvMemInstance)
#define vMem_30_vXSpi_Nand_GetBlankCheckBufferArrayOne2SortedNStartIdxOfvMemInstance(Index) (vMem_30_vXSpi_Nand_GetvMemInstanceOfPCConfig()[(Index)].BlankCheckBufferArrayOne2SortedNStartIdxOfvMemInstance)
#define vMem_30_vXSpi_Nand_GetBusyCheckTimeoutThresholdOfvMemInstance(Index) (vMem_30_vXSpi_Nand_GetvMemInstanceOfPCConfig()[(Index)].BusyCheckTimeoutThresholdOfvMemInstance)
#define vMem_30_vXSpi_Nand_GetGenericProtocolModeIdOfvMemInstance(Index) (vMem_30_vXSpi_Nand_GetvMemInstanceOfPCConfig()[(Index)].GenericProtocolModeIdOfvMemInstance)
#define vMem_30_vXSpi_Nand_GetIdOfvMemInstance(Index)                 (vMem_30_vXSpi_Nand_GetvMemInstanceOfPCConfig()[(Index)].IdOfvMemInstance)
#define vMem_30_vXSpi_Nand_GetMemSectorEndIdxOfvMemInstance(Index)    (vMem_30_vXSpi_Nand_GetvMemInstanceOfPCConfig()[(Index)].MemSectorEndIdxOfvMemInstance)
#define vMem_30_vXSpi_Nand_GetMemSectorLengthOfvMemInstance(Index)    (vMem_30_vXSpi_Nand_GetvMemInstanceOfPCConfig()[(Index)].MemSectorLengthOfvMemInstance)
#define vMem_30_vXSpi_Nand_GetMemSectorStartIdxOfvMemInstance(Index)  (vMem_30_vXSpi_Nand_GetvMemInstanceOfPCConfig()[(Index)].MemSectorStartIdxOfvMemInstance)
#define vMem_30_vXSpi_Nand_GetReadDataProtocolModeIdOfvMemInstance(Index) (vMem_30_vXSpi_Nand_GetvMemInstanceOfPCConfig()[(Index)].ReadDataProtocolModeIdOfvMemInstance)
#define vMem_30_vXSpi_Nand_IsSoftwareDieSelectCommandUsedOfvMemInstance(Index) ((vMem_30_vXSpi_Nand_GetvMemInstanceOfPCConfig()[(Index)].SoftwareDieSelectCommandUsedOfvMemInstance) != FALSE)
#define vMem_30_vXSpi_Nand_GetWriteDataProtocolModeIdOfvMemInstance(Index) (vMem_30_vXSpi_Nand_GetvMemInstanceOfPCConfig()[(Index)].WriteDataProtocolModeIdOfvMemInstance)
#define vMem_30_vXSpi_Nand_GetvMemDieEndIdxOfvMemInstance(Index)      (vMem_30_vXSpi_Nand_GetvMemInstanceOfPCConfig()[(Index)].vMemDieEndIdxOfvMemInstance)
#define vMem_30_vXSpi_Nand_GetvMemDieLengthOfvMemInstance(Index)      (vMem_30_vXSpi_Nand_GetvMemInstanceOfPCConfig()[(Index)].vMemDieLengthOfvMemInstance)
#define vMem_30_vXSpi_Nand_GetvMemDieStartIdxOfvMemInstance(Index)    (vMem_30_vXSpi_Nand_GetvMemInstanceOfPCConfig()[(Index)].vMemDieStartIdxOfvMemInstance)
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_vXSpi_NandPCGetDeduplicatedDataMacros  vMem_30_vXSpi_Nand Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define vMem_30_vXSpi_Nand_GetSizeOfBlankCheckBufferArray()           vMem_30_vXSpi_Nand_GetSizeOfBlankCheckBufferArrayOfPCConfig()
#define vMem_30_vXSpi_Nand_GetSizeOfInstanceIdTovXSpiDeviceId()       vMem_30_vXSpi_Nand_GetSizeOfInstanceIdTovXSpiDeviceIdOfPCConfig()
#define vMem_30_vXSpi_Nand_GetSizeOfMemSector()                       vMem_30_vXSpi_Nand_GetSizeOfMemSectorOfPCConfig()
#define vMem_30_vXSpi_Nand_GetSizeOfvMemDeviceConfig()                vMem_30_vXSpi_Nand_GetSizeOfvMemDeviceConfigOfPCConfig()
#define vMem_30_vXSpi_Nand_GetSizeOfvMemDie()                         vMem_30_vXSpi_Nand_GetSizeOfvMemDieOfPCConfig()
#define vMem_30_vXSpi_Nand_GetSizeOfvMemFlsCmdAddressFormatValue()    vMem_30_vXSpi_Nand_GetSizeOfvMemFlsCmdAddressFormatValueOfPCConfig()
#define vMem_30_vXSpi_Nand_GetSizeOfvMemFlsCmdDummyCycleValue()       vMem_30_vXSpi_Nand_GetSizeOfvMemFlsCmdDummyCycleValueOfPCConfig()
#define vMem_30_vXSpi_Nand_GetSizeOfvMemFlsCmdValue()                 vMem_30_vXSpi_Nand_GetSizeOfvMemFlsCmdValueOfPCConfig()
#define vMem_30_vXSpi_Nand_GetSizeOfvMemInstance()                    vMem_30_vXSpi_Nand_GetSizeOfvMemInstanceOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_vXSpi_NandPCSetDataMacros  vMem_30_vXSpi_Nand Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define vMem_30_vXSpi_Nand_SetBlankCheckBufferArray(Index, Value)     vMem_30_vXSpi_Nand_GetBlankCheckBufferArrayOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_vXSpi_NandPCHasMacros  vMem_30_vXSpi_Nand Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define vMem_30_vXSpi_Nand_HasBlankCheckBufferArray()                 (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasInstanceIdTovXSpiDeviceId()             (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasMemSector()                             (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasEraseBurstSizeOfMemSector()             (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasNrOfSectorsOfMemSector()                (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasPageSizeOfMemSector()                   (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasRamAlignmentOfMemSector()               (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasReplacementSectorOfMemSector()          (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasSectorSizeOfMemSector()                 (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasStartAddressOfMemSector()               (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasWriteBurstSizeOfMemSector()             (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasvMemDieIdxOfMemSector()                 (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasSizeOfBlankCheckBufferArray()           (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasSizeOfInstanceIdTovXSpiDeviceId()       (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasSizeOfMemSector()                       (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasSizeOfvMemDeviceConfig()                (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasSizeOfvMemDie()                         (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasSizeOfvMemFlsCmdAddressFormatValue()    (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasSizeOfvMemFlsCmdDummyCycleValue()       (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasSizeOfvMemFlsCmdValue()                 (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasSizeOfvMemInstance()                    (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasvMemDeviceConfig()                      (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasEraseValueOfvMemDeviceConfig()          (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasInputOutputModeRegisterAddressOfvMemDeviceConfig() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasInputOutputModeRegisterExistingOfvMemDeviceConfig() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasInputOutputModeRegisterValueOfvMemDeviceConfig() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasLutAddressLengthOfvMemDeviceConfig()    (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasLutDataBufferLengthOfvMemDeviceConfig() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasLutEntryLengthOfvMemDeviceConfig()      (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasLutMaxEntriesOfvMemDeviceConfig()       (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasStatusRegister1AddressOfvMemDeviceConfig() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasStatusRegister2AddressOfvMemDeviceConfig() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasStatusRegister3AddressOfvMemDeviceConfig() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasStatusRegisterBufferReadModeBitMaskOfvMemDeviceConfig() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasStatusRegisterBusyFlagBitMaskOfvMemDeviceConfig() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasStatusRegisterDataBufferLengthOfvMemDeviceConfig() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasStatusRegisterEcc0BitMaskOfvMemDeviceConfig() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasStatusRegisterEcc1BitMaskOfvMemDeviceConfig() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasStatusRegisterEraseErrorBitMaskOfvMemDeviceConfig() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasStatusRegisterLutFBitMaskOfvMemDeviceConfig() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasStatusRegisterProgramErrorBitMaskOfvMemDeviceConfig() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasStatusRegisterProtectionBitMaskOfvMemDeviceConfig() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasVolatileConfigurationRegisterDataBufferLengthOfvMemDeviceConfig() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasvMemDie()                               (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasDieSizeOfvMemDie()                      (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasDieStartAddressOfvMemDie()              (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasvMemFlsCmdAddressFormatValue()          (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasEraseCmdOfvMemFlsCmdAddressFormatValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasPageDataReadCmdOfvMemFlsCmdAddressFormatValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasProgramDataLoadCmdOfvMemFlsCmdAddressFormatValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasProgramExecuteCmdOfvMemFlsCmdAddressFormatValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasReadBbmLutCmdOfvMemFlsCmdAddressFormatValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasReadCmdOfvMemFlsCmdAddressFormatValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasReadStatusRegisterCmdOfvMemFlsCmdAddressFormatValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasReadVolatileConfigurationRegisterCmdOfvMemFlsCmdAddressFormatValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasReplaceLogicalBlocksCmdOfvMemFlsCmdAddressFormatValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasSoftwareDieSelectCmdOfvMemFlsCmdAddressFormatValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasWriteEnableCmdOfvMemFlsCmdAddressFormatValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasWriteStatusRegisterCmdOfvMemFlsCmdAddressFormatValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasWriteVolatileConfigurationRegisterCmdOfvMemFlsCmdAddressFormatValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasvMemFlsCmdDummyCycleValue()             (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasEraseCmdOfvMemFlsCmdDummyCycleValue()   (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasPageDataReadCmdOfvMemFlsCmdDummyCycleValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasProgramDataLoadCmdOfvMemFlsCmdDummyCycleValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasProgramExecuteCmdOfvMemFlsCmdDummyCycleValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasReadBbmLutCmdOfvMemFlsCmdDummyCycleValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasReadCmdOfvMemFlsCmdDummyCycleValue()    (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasReadStatusRegisterCmdOfvMemFlsCmdDummyCycleValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasReadVolatileConfigurationRegisterCmdOfvMemFlsCmdDummyCycleValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasReplaceLogicalBlocksCmdOfvMemFlsCmdDummyCycleValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasSoftwareDieSelectCmdOfvMemFlsCmdDummyCycleValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasWriteEnableCmdOfvMemFlsCmdDummyCycleValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasWriteStatusRegisterCmdOfvMemFlsCmdDummyCycleValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasWriteVolatileConfigurationRegisterCmdOfvMemFlsCmdDummyCycleValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasvMemFlsCmdValue()                       (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasEraseCmdOfvMemFlsCmdValue()             (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasPageDataReadCmdOfvMemFlsCmdValue()      (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasProgramDataLoadCmdOfvMemFlsCmdValue()   (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasProgramExecuteCmdOfvMemFlsCmdValue()    (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasReadBbmLutCmdOfvMemFlsCmdValue()        (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasReadCmdOfvMemFlsCmdValue()              (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasReadStatusRegisterCmdOfvMemFlsCmdValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasReadVolatileConfigurationRegisterCmdOfvMemFlsCmdValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasReplaceLogicalBlocksCmdOfvMemFlsCmdValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasSoftwareDieSelectCmdOfvMemFlsCmdValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasWriteEnableCmdOfvMemFlsCmdValue()       (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasWriteStatusRegisterCmdOfvMemFlsCmdValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasWriteVolatileConfigurationRegisterCmdOfvMemFlsCmdValue() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasvMemInstance()                          (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasAutomatedBadBlockManagmentOfvMemInstance() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasBlankCheckBufferArrayOne2SortedNEndIdxOfvMemInstance() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasBlankCheckBufferArrayOne2SortedNLengthOfvMemInstance() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasBlankCheckBufferArrayOne2SortedNStartIdxOfvMemInstance() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasBusyCheckTimeoutThresholdOfvMemInstance() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasGenericProtocolModeIdOfvMemInstance()   (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasIdOfvMemInstance()                      (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasMemSectorEndIdxOfvMemInstance()         (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasMemSectorLengthOfvMemInstance()         (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasMemSectorStartIdxOfvMemInstance()       (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasReadDataProtocolModeIdOfvMemInstance()  (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasSoftwareDieSelectCommandUsedOfvMemInstance() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasWriteDataProtocolModeIdOfvMemInstance() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasvMemDieEndIdxOfvMemInstance()           (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasvMemDieLengthOfvMemInstance()           (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasvMemDieStartIdxOfvMemInstance()         (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasPCConfig()                              (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasBlankCheckBufferArrayOfPCConfig()       (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasInstanceIdTovXSpiDeviceIdOfPCConfig()   (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasMemSectorOfPCConfig()                   (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasSizeOfBlankCheckBufferArrayOfPCConfig() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasSizeOfInstanceIdTovXSpiDeviceIdOfPCConfig() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasSizeOfMemSectorOfPCConfig()             (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasSizeOfvMemDeviceConfigOfPCConfig()      (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasSizeOfvMemDieOfPCConfig()               (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasSizeOfvMemFlsCmdAddressFormatValueOfPCConfig() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasSizeOfvMemFlsCmdDummyCycleValueOfPCConfig() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasSizeOfvMemFlsCmdValueOfPCConfig()       (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasSizeOfvMemInstanceOfPCConfig()          (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasvMemDeviceConfigOfPCConfig()            (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasvMemDieOfPCConfig()                     (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasvMemFlsCmdAddressFormatValueOfPCConfig() (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasvMemFlsCmdDummyCycleValueOfPCConfig()   (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasvMemFlsCmdValueOfPCConfig()             (TRUE != FALSE)
#define vMem_30_vXSpi_Nand_HasvMemInstanceOfPCConfig()                (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_vXSpi_NandPCIncrementDataMacros  vMem_30_vXSpi_Nand Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define vMem_30_vXSpi_Nand_IncBlankCheckBufferArray(Index)            vMem_30_vXSpi_Nand_GetBlankCheckBufferArray(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_vXSpi_NandPCDecrementDataMacros  vMem_30_vXSpi_Nand Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define vMem_30_vXSpi_Nand_DecBlankCheckBufferArray(Index)            vMem_30_vXSpi_Nand_GetBlankCheckBufferArray(Index)--
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
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vMem_30_vXSpi_NandPCIterableTypes  vMem_30_vXSpi_Nand Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate vMem_30_vXSpi_Nand_BlankCheckBufferArray */
typedef uint16_least vMem_30_vXSpi_Nand_BlankCheckBufferArrayIterType;

/**   \brief  type used to iterate vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId */
typedef uint8_least vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceIdIterType;

/**   \brief  type used to iterate vMem_30_vXSpi_Nand_MemSector */
typedef uint8_least vMem_30_vXSpi_Nand_MemSectorIterType;

/**   \brief  type used to iterate vMem_30_vXSpi_Nand_vMemDeviceConfig */
typedef uint8_least vMem_30_vXSpi_Nand_vMemDeviceConfigIterType;

/**   \brief  type used to iterate vMem_30_vXSpi_Nand_vMemDie */
typedef uint8_least vMem_30_vXSpi_Nand_vMemDieIterType;

/**   \brief  type used to iterate vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValue */
typedef uint8_least vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValueIterType;

/**   \brief  type used to iterate vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue */
typedef uint8_least vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValueIterType;

/**   \brief  type used to iterate vMem_30_vXSpi_Nand_vMemFlsCmdValue */
typedef uint8_least vMem_30_vXSpi_Nand_vMemFlsCmdValueIterType;

/**   \brief  type used to iterate vMem_30_vXSpi_Nand_vMemInstance */
typedef uint8_least vMem_30_vXSpi_Nand_vMemInstanceIterType;

/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_vXSpi_NandPCValueTypes  vMem_30_vXSpi_Nand Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for vMem_30_vXSpi_Nand_BlankCheckBufferArray */
typedef uint8 vMem_30_vXSpi_Nand_BlankCheckBufferArrayType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId */
typedef uint8 vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceIdType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_EraseBurstSizeOfMemSector */
typedef uint32 vMem_30_vXSpi_Nand_EraseBurstSizeOfMemSectorType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_NrOfSectorsOfMemSector */
typedef uint16 vMem_30_vXSpi_Nand_NrOfSectorsOfMemSectorType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_PageSizeOfMemSector */
typedef uint16 vMem_30_vXSpi_Nand_PageSizeOfMemSectorType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_RamAlignmentOfMemSector */
typedef uint8 vMem_30_vXSpi_Nand_RamAlignmentOfMemSectorType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_ReplacementSectorOfMemSector */
typedef boolean vMem_30_vXSpi_Nand_ReplacementSectorOfMemSectorType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_SectorSizeOfMemSector */
typedef uint32 vMem_30_vXSpi_Nand_SectorSizeOfMemSectorType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_StartAddressOfMemSector */
typedef uint32 vMem_30_vXSpi_Nand_StartAddressOfMemSectorType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_WriteBurstSizeOfMemSector */
typedef uint16 vMem_30_vXSpi_Nand_WriteBurstSizeOfMemSectorType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_vMemDieIdxOfMemSector */
typedef uint8 vMem_30_vXSpi_Nand_vMemDieIdxOfMemSectorType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_SizeOfBlankCheckBufferArray */
typedef uint16 vMem_30_vXSpi_Nand_SizeOfBlankCheckBufferArrayType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_SizeOfInstanceIdTovXSpiDeviceId */
typedef uint8 vMem_30_vXSpi_Nand_SizeOfInstanceIdTovXSpiDeviceIdType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_SizeOfMemSector */
typedef uint8 vMem_30_vXSpi_Nand_SizeOfMemSectorType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_SizeOfvMemDeviceConfig */
typedef uint8 vMem_30_vXSpi_Nand_SizeOfvMemDeviceConfigType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_SizeOfvMemDie */
typedef uint8 vMem_30_vXSpi_Nand_SizeOfvMemDieType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_SizeOfvMemFlsCmdAddressFormatValue */
typedef uint8 vMem_30_vXSpi_Nand_SizeOfvMemFlsCmdAddressFormatValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_SizeOfvMemFlsCmdDummyCycleValue */
typedef uint8 vMem_30_vXSpi_Nand_SizeOfvMemFlsCmdDummyCycleValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_SizeOfvMemFlsCmdValue */
typedef uint8 vMem_30_vXSpi_Nand_SizeOfvMemFlsCmdValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_SizeOfvMemInstance */
typedef uint8 vMem_30_vXSpi_Nand_SizeOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_EraseValueOfvMemDeviceConfig */
typedef uint8 vMem_30_vXSpi_Nand_EraseValueOfvMemDeviceConfigType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_InputOutputModeRegisterAddressOfvMemDeviceConfig */
typedef uint8 vMem_30_vXSpi_Nand_InputOutputModeRegisterAddressOfvMemDeviceConfigType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_InputOutputModeRegisterExistingOfvMemDeviceConfig */
typedef boolean vMem_30_vXSpi_Nand_InputOutputModeRegisterExistingOfvMemDeviceConfigType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_InputOutputModeRegisterValueOfvMemDeviceConfig */
typedef uint8 vMem_30_vXSpi_Nand_InputOutputModeRegisterValueOfvMemDeviceConfigType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_LutAddressLengthOfvMemDeviceConfig */
typedef uint8 vMem_30_vXSpi_Nand_LutAddressLengthOfvMemDeviceConfigType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_LutDataBufferLengthOfvMemDeviceConfig */
typedef uint8 vMem_30_vXSpi_Nand_LutDataBufferLengthOfvMemDeviceConfigType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_LutEntryLengthOfvMemDeviceConfig */
typedef uint8 vMem_30_vXSpi_Nand_LutEntryLengthOfvMemDeviceConfigType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_LutMaxEntriesOfvMemDeviceConfig */
typedef uint8 vMem_30_vXSpi_Nand_LutMaxEntriesOfvMemDeviceConfigType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_StatusRegister1AddressOfvMemDeviceConfig */
typedef uint8 vMem_30_vXSpi_Nand_StatusRegister1AddressOfvMemDeviceConfigType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_StatusRegister2AddressOfvMemDeviceConfig */
typedef uint8 vMem_30_vXSpi_Nand_StatusRegister2AddressOfvMemDeviceConfigType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_StatusRegister3AddressOfvMemDeviceConfig */
typedef uint8 vMem_30_vXSpi_Nand_StatusRegister3AddressOfvMemDeviceConfigType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_StatusRegisterBufferReadModeBitMaskOfvMemDeviceConfig */
typedef uint8 vMem_30_vXSpi_Nand_StatusRegisterBufferReadModeBitMaskOfvMemDeviceConfigType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_StatusRegisterBusyFlagBitMaskOfvMemDeviceConfig */
typedef uint8 vMem_30_vXSpi_Nand_StatusRegisterBusyFlagBitMaskOfvMemDeviceConfigType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_StatusRegisterDataBufferLengthOfvMemDeviceConfig */
typedef uint8 vMem_30_vXSpi_Nand_StatusRegisterDataBufferLengthOfvMemDeviceConfigType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_StatusRegisterEcc0BitMaskOfvMemDeviceConfig */
typedef uint8 vMem_30_vXSpi_Nand_StatusRegisterEcc0BitMaskOfvMemDeviceConfigType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_StatusRegisterEcc1BitMaskOfvMemDeviceConfig */
typedef uint8 vMem_30_vXSpi_Nand_StatusRegisterEcc1BitMaskOfvMemDeviceConfigType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_StatusRegisterEraseErrorBitMaskOfvMemDeviceConfig */
typedef uint8 vMem_30_vXSpi_Nand_StatusRegisterEraseErrorBitMaskOfvMemDeviceConfigType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_StatusRegisterLutFBitMaskOfvMemDeviceConfig */
typedef uint8 vMem_30_vXSpi_Nand_StatusRegisterLutFBitMaskOfvMemDeviceConfigType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_StatusRegisterProgramErrorBitMaskOfvMemDeviceConfig */
typedef uint8 vMem_30_vXSpi_Nand_StatusRegisterProgramErrorBitMaskOfvMemDeviceConfigType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_StatusRegisterProtectionBitMaskOfvMemDeviceConfig */
typedef uint8 vMem_30_vXSpi_Nand_StatusRegisterProtectionBitMaskOfvMemDeviceConfigType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_VolatileConfigurationRegisterDataBufferLengthOfvMemDeviceConfig */
typedef uint8 vMem_30_vXSpi_Nand_VolatileConfigurationRegisterDataBufferLengthOfvMemDeviceConfigType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_DieSizeOfvMemDie */
typedef uint32 vMem_30_vXSpi_Nand_DieSizeOfvMemDieType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_DieStartAddressOfvMemDie */
typedef uint8 vMem_30_vXSpi_Nand_DieStartAddressOfvMemDieType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_EraseCmdOfvMemFlsCmdDummyCycleValue */
typedef uint8 vMem_30_vXSpi_Nand_EraseCmdOfvMemFlsCmdDummyCycleValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_PageDataReadCmdOfvMemFlsCmdDummyCycleValue */
typedef uint8 vMem_30_vXSpi_Nand_PageDataReadCmdOfvMemFlsCmdDummyCycleValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_ProgramDataLoadCmdOfvMemFlsCmdDummyCycleValue */
typedef uint8 vMem_30_vXSpi_Nand_ProgramDataLoadCmdOfvMemFlsCmdDummyCycleValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_ProgramExecuteCmdOfvMemFlsCmdDummyCycleValue */
typedef uint8 vMem_30_vXSpi_Nand_ProgramExecuteCmdOfvMemFlsCmdDummyCycleValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_ReadBbmLutCmdOfvMemFlsCmdDummyCycleValue */
typedef uint8 vMem_30_vXSpi_Nand_ReadBbmLutCmdOfvMemFlsCmdDummyCycleValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_ReadCmdOfvMemFlsCmdDummyCycleValue */
typedef uint8 vMem_30_vXSpi_Nand_ReadCmdOfvMemFlsCmdDummyCycleValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_ReadStatusRegisterCmdOfvMemFlsCmdDummyCycleValue */
typedef uint8 vMem_30_vXSpi_Nand_ReadStatusRegisterCmdOfvMemFlsCmdDummyCycleValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_ReadVolatileConfigurationRegisterCmdOfvMemFlsCmdDummyCycleValue */
typedef uint8 vMem_30_vXSpi_Nand_ReadVolatileConfigurationRegisterCmdOfvMemFlsCmdDummyCycleValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_ReplaceLogicalBlocksCmdOfvMemFlsCmdDummyCycleValue */
typedef uint8 vMem_30_vXSpi_Nand_ReplaceLogicalBlocksCmdOfvMemFlsCmdDummyCycleValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_SoftwareDieSelectCmdOfvMemFlsCmdDummyCycleValue */
typedef uint8 vMem_30_vXSpi_Nand_SoftwareDieSelectCmdOfvMemFlsCmdDummyCycleValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_WriteEnableCmdOfvMemFlsCmdDummyCycleValue */
typedef uint8 vMem_30_vXSpi_Nand_WriteEnableCmdOfvMemFlsCmdDummyCycleValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_WriteStatusRegisterCmdOfvMemFlsCmdDummyCycleValue */
typedef uint8 vMem_30_vXSpi_Nand_WriteStatusRegisterCmdOfvMemFlsCmdDummyCycleValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_WriteVolatileConfigurationRegisterCmdOfvMemFlsCmdDummyCycleValue */
typedef uint8 vMem_30_vXSpi_Nand_WriteVolatileConfigurationRegisterCmdOfvMemFlsCmdDummyCycleValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_EraseCmdOfvMemFlsCmdValue */
typedef uint8 vMem_30_vXSpi_Nand_EraseCmdOfvMemFlsCmdValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_PageDataReadCmdOfvMemFlsCmdValue */
typedef uint8 vMem_30_vXSpi_Nand_PageDataReadCmdOfvMemFlsCmdValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_ProgramDataLoadCmdOfvMemFlsCmdValue */
typedef uint8 vMem_30_vXSpi_Nand_ProgramDataLoadCmdOfvMemFlsCmdValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_ProgramExecuteCmdOfvMemFlsCmdValue */
typedef uint8 vMem_30_vXSpi_Nand_ProgramExecuteCmdOfvMemFlsCmdValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_ReadBbmLutCmdOfvMemFlsCmdValue */
typedef uint8 vMem_30_vXSpi_Nand_ReadBbmLutCmdOfvMemFlsCmdValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_ReadCmdOfvMemFlsCmdValue */
typedef uint8 vMem_30_vXSpi_Nand_ReadCmdOfvMemFlsCmdValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_ReadStatusRegisterCmdOfvMemFlsCmdValue */
typedef uint8 vMem_30_vXSpi_Nand_ReadStatusRegisterCmdOfvMemFlsCmdValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_ReadVolatileConfigurationRegisterCmdOfvMemFlsCmdValue */
typedef uint8 vMem_30_vXSpi_Nand_ReadVolatileConfigurationRegisterCmdOfvMemFlsCmdValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_ReplaceLogicalBlocksCmdOfvMemFlsCmdValue */
typedef uint8 vMem_30_vXSpi_Nand_ReplaceLogicalBlocksCmdOfvMemFlsCmdValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_SoftwareDieSelectCmdOfvMemFlsCmdValue */
typedef uint8 vMem_30_vXSpi_Nand_SoftwareDieSelectCmdOfvMemFlsCmdValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_WriteEnableCmdOfvMemFlsCmdValue */
typedef uint8 vMem_30_vXSpi_Nand_WriteEnableCmdOfvMemFlsCmdValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_WriteStatusRegisterCmdOfvMemFlsCmdValue */
typedef uint8 vMem_30_vXSpi_Nand_WriteStatusRegisterCmdOfvMemFlsCmdValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_WriteVolatileConfigurationRegisterCmdOfvMemFlsCmdValue */
typedef uint8 vMem_30_vXSpi_Nand_WriteVolatileConfigurationRegisterCmdOfvMemFlsCmdValueType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_AutomatedBadBlockManagmentOfvMemInstance */
typedef boolean vMem_30_vXSpi_Nand_AutomatedBadBlockManagmentOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_BlankCheckBufferArrayOne2SortedNEndIdxOfvMemInstance */
typedef uint16 vMem_30_vXSpi_Nand_BlankCheckBufferArrayOne2SortedNEndIdxOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_BlankCheckBufferArrayOne2SortedNLengthOfvMemInstance */
typedef uint16 vMem_30_vXSpi_Nand_BlankCheckBufferArrayOne2SortedNLengthOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_BlankCheckBufferArrayOne2SortedNStartIdxOfvMemInstance */
typedef uint16 vMem_30_vXSpi_Nand_BlankCheckBufferArrayOne2SortedNStartIdxOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_BusyCheckTimeoutThresholdOfvMemInstance */
typedef uint16 vMem_30_vXSpi_Nand_BusyCheckTimeoutThresholdOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_IdOfvMemInstance */
typedef uint8 vMem_30_vXSpi_Nand_IdOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_MemSectorEndIdxOfvMemInstance */
typedef uint8 vMem_30_vXSpi_Nand_MemSectorEndIdxOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_MemSectorLengthOfvMemInstance */
typedef uint8 vMem_30_vXSpi_Nand_MemSectorLengthOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_MemSectorStartIdxOfvMemInstance */
typedef uint8 vMem_30_vXSpi_Nand_MemSectorStartIdxOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_SoftwareDieSelectCommandUsedOfvMemInstance */
typedef boolean vMem_30_vXSpi_Nand_SoftwareDieSelectCommandUsedOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_vMemDieEndIdxOfvMemInstance */
typedef uint8 vMem_30_vXSpi_Nand_vMemDieEndIdxOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_vMemDieLengthOfvMemInstance */
typedef uint8 vMem_30_vXSpi_Nand_vMemDieLengthOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_vXSpi_Nand_vMemDieStartIdxOfvMemInstance */
typedef uint8 vMem_30_vXSpi_Nand_vMemDieStartIdxOfvMemInstanceType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vMem_30_vXSpi_NandPCStructTypes  vMem_30_vXSpi_Nand Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in vMem_30_vXSpi_Nand_MemSector */
typedef struct svMem_30_vXSpi_Nand_MemSectorType
{
  vMem_30_vXSpi_Nand_EraseBurstSizeOfMemSectorType EraseBurstSizeOfMemSector;  /**< Burst size for erase jobs, if configured. Otherwise sector size */
  vMem_30_vXSpi_Nand_SectorSizeOfMemSectorType SectorSizeOfMemSector;  /**< Size of this sector in bytes. */
  vMem_30_vXSpi_Nand_StartAddressOfMemSectorType StartAddressOfMemSector;  /**< Physical start address of the first sector. */
  vMem_30_vXSpi_Nand_NrOfSectorsOfMemSectorType NrOfSectorsOfMemSector;  /**< Number of continuous sectors with identical values for vMemSectorSize and vMemPageSize. */
  vMem_30_vXSpi_Nand_PageSizeOfMemSectorType PageSizeOfMemSector;  /**< Size of one page of this sector in bytes. */
  vMem_30_vXSpi_Nand_WriteBurstSizeOfMemSectorType WriteBurstSizeOfMemSector;  /**< Burst size for write jobs, if configured. Otherwise page size */
  vMem_30_vXSpi_Nand_ReplacementSectorOfMemSectorType ReplacementSectorOfMemSector;  /**< Specifies whether the MemSector consists of replacement sectors. */
  vMem_30_vXSpi_Nand_RamAlignmentOfMemSectorType RamAlignmentOfMemSector;  /**< In order to perform write jobs correctly, a device might require a specific alignment of the data buffer. */
  vMem_30_vXSpi_Nand_vMemDieIdxOfMemSectorType vMemDieIdxOfMemSector;  /**< the index of the 1:1 relation pointing to vMem_30_vXSpi_Nand_vMemDie */
} vMem_30_vXSpi_Nand_MemSectorType;

/**   \brief  type used in vMem_30_vXSpi_Nand_vMemDeviceConfig */
typedef struct svMem_30_vXSpi_Nand_vMemDeviceConfigType
{
  vMem_30_vXSpi_Nand_InputOutputModeRegisterExistingOfvMemDeviceConfigType InputOutputModeRegisterExistingOfvMemDeviceConfig;  /**< Is input output mode register existing */
  vMem_30_vXSpi_Nand_EraseValueOfvMemDeviceConfigType EraseValueOfvMemDeviceConfig;  /**< Erase value. */
  vMem_30_vXSpi_Nand_InputOutputModeRegisterAddressOfvMemDeviceConfigType InputOutputModeRegisterAddressOfvMemDeviceConfig;  /**< Address of input output mode register */
  vMem_30_vXSpi_Nand_InputOutputModeRegisterValueOfvMemDeviceConfigType InputOutputModeRegisterValueOfvMemDeviceConfig;  /**< Value of input output mode register */
  vMem_30_vXSpi_Nand_LutAddressLengthOfvMemDeviceConfigType LutAddressLengthOfvMemDeviceConfig;  /**< Length of one address within the Lookup table */
  vMem_30_vXSpi_Nand_LutDataBufferLengthOfvMemDeviceConfigType LutDataBufferLengthOfvMemDeviceConfig;  /**< Length of Lookup table data buffer */
  vMem_30_vXSpi_Nand_LutEntryLengthOfvMemDeviceConfigType LutEntryLengthOfvMemDeviceConfig;  /**< Length of one Lookup table entry */
  vMem_30_vXSpi_Nand_LutMaxEntriesOfvMemDeviceConfigType LutMaxEntriesOfvMemDeviceConfig;  /**< Maximal number of Lookup table entries */
  vMem_30_vXSpi_Nand_StatusRegister1AddressOfvMemDeviceConfigType StatusRegister1AddressOfvMemDeviceConfig;  /**< Address of status register 1 */
  vMem_30_vXSpi_Nand_StatusRegister2AddressOfvMemDeviceConfigType StatusRegister2AddressOfvMemDeviceConfig;  /**< Address of status register 2 */
  vMem_30_vXSpi_Nand_StatusRegister3AddressOfvMemDeviceConfigType StatusRegister3AddressOfvMemDeviceConfig;  /**< Address of status register 3 */
  vMem_30_vXSpi_Nand_StatusRegisterBufferReadModeBitMaskOfvMemDeviceConfigType StatusRegisterBufferReadModeBitMaskOfvMemDeviceConfig;  /**< Status register buffer read mode bitmask. */
  vMem_30_vXSpi_Nand_StatusRegisterBusyFlagBitMaskOfvMemDeviceConfigType StatusRegisterBusyFlagBitMaskOfvMemDeviceConfig;  /**< Status register busy flag bitmask. */
  vMem_30_vXSpi_Nand_StatusRegisterDataBufferLengthOfvMemDeviceConfigType StatusRegisterDataBufferLengthOfvMemDeviceConfig;  /**< Length of status register data buffer */
  vMem_30_vXSpi_Nand_StatusRegisterEcc0BitMaskOfvMemDeviceConfigType StatusRegisterEcc0BitMaskOfvMemDeviceConfig;  /**< Status register ECC0 bitmask. */
  vMem_30_vXSpi_Nand_StatusRegisterEcc1BitMaskOfvMemDeviceConfigType StatusRegisterEcc1BitMaskOfvMemDeviceConfig;  /**< Status register ECC1 bitmask. */
  vMem_30_vXSpi_Nand_StatusRegisterEraseErrorBitMaskOfvMemDeviceConfigType StatusRegisterEraseErrorBitMaskOfvMemDeviceConfig;  /**< Status register erase error bitmask. */
  vMem_30_vXSpi_Nand_StatusRegisterLutFBitMaskOfvMemDeviceConfigType StatusRegisterLutFBitMaskOfvMemDeviceConfig;  /**< Status register Lookup table full bitmask. */
  vMem_30_vXSpi_Nand_StatusRegisterProgramErrorBitMaskOfvMemDeviceConfigType StatusRegisterProgramErrorBitMaskOfvMemDeviceConfig;  /**< Status register program error bitmask. */
  vMem_30_vXSpi_Nand_StatusRegisterProtectionBitMaskOfvMemDeviceConfigType StatusRegisterProtectionBitMaskOfvMemDeviceConfig;  /**< Status register Protection bitmask. */
  vMem_30_vXSpi_Nand_VolatileConfigurationRegisterDataBufferLengthOfvMemDeviceConfigType VolatileConfigurationRegisterDataBufferLengthOfvMemDeviceConfig;  /**< Length of volatile configuration register data buffer */
} vMem_30_vXSpi_Nand_vMemDeviceConfigType;

/**   \brief  type used in vMem_30_vXSpi_Nand_vMemDie */
typedef struct svMem_30_vXSpi_Nand_vMemDieType
{
  vMem_30_vXSpi_Nand_DieSizeOfvMemDieType DieSizeOfvMemDie;  /**< Size of the die. */
  vMem_30_vXSpi_Nand_DieStartAddressOfvMemDieType DieStartAddressOfvMemDie;  /**< Memory start address of the die. */
} vMem_30_vXSpi_Nand_vMemDieType;

/**   \brief  type used in vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValue */
typedef struct svMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValueType
{
  vMem_30_vXSpi_Nand_AddressFormatType EraseCmdOfvMemFlsCmdAddressFormatValue;  /**< Erase command. */
  vMem_30_vXSpi_Nand_AddressFormatType PageDataReadCmdOfvMemFlsCmdAddressFormatValue;  /**< Page data read command. */
  vMem_30_vXSpi_Nand_AddressFormatType ProgramDataLoadCmdOfvMemFlsCmdAddressFormatValue;  /**< Program data load command. */
  vMem_30_vXSpi_Nand_AddressFormatType ProgramExecuteCmdOfvMemFlsCmdAddressFormatValue;  /**< Program execute command. */
  vMem_30_vXSpi_Nand_AddressFormatType ReadBbmLutCmdOfvMemFlsCmdAddressFormatValue;  /**< Read BBM LUT command. */
  vMem_30_vXSpi_Nand_AddressFormatType ReadCmdOfvMemFlsCmdAddressFormatValue;  /**< Read command. */
  vMem_30_vXSpi_Nand_AddressFormatType ReadStatusRegisterCmdOfvMemFlsCmdAddressFormatValue;  /**< Read status register command. */
  vMem_30_vXSpi_Nand_AddressFormatType ReadVolatileConfigurationRegisterCmdOfvMemFlsCmdAddressFormatValue;  /**< Read volatile configuration register command. */
  vMem_30_vXSpi_Nand_AddressFormatType ReplaceLogicalBlocksCmdOfvMemFlsCmdAddressFormatValue;  /**< Replace logical sector command. */
  vMem_30_vXSpi_Nand_AddressFormatType SoftwareDieSelectCmdOfvMemFlsCmdAddressFormatValue;  /**< Software die select command. */
  vMem_30_vXSpi_Nand_AddressFormatType WriteEnableCmdOfvMemFlsCmdAddressFormatValue;  /**< Write enable command. */
  vMem_30_vXSpi_Nand_AddressFormatType WriteStatusRegisterCmdOfvMemFlsCmdAddressFormatValue;  /**< Write status register command. */
  vMem_30_vXSpi_Nand_AddressFormatType WriteVolatileConfigurationRegisterCmdOfvMemFlsCmdAddressFormatValue;  /**< Write volatile configuration register command. */
} vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValueType;

/**   \brief  type used in vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue */
typedef struct svMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValueType
{
  vMem_30_vXSpi_Nand_EraseCmdOfvMemFlsCmdDummyCycleValueType EraseCmdOfvMemFlsCmdDummyCycleValue;  /**< Erase command. */
  vMem_30_vXSpi_Nand_PageDataReadCmdOfvMemFlsCmdDummyCycleValueType PageDataReadCmdOfvMemFlsCmdDummyCycleValue;  /**< Page data read command. */
  vMem_30_vXSpi_Nand_ProgramDataLoadCmdOfvMemFlsCmdDummyCycleValueType ProgramDataLoadCmdOfvMemFlsCmdDummyCycleValue;  /**< Program data load command. */
  vMem_30_vXSpi_Nand_ProgramExecuteCmdOfvMemFlsCmdDummyCycleValueType ProgramExecuteCmdOfvMemFlsCmdDummyCycleValue;  /**< Program execute command. */
  vMem_30_vXSpi_Nand_ReadBbmLutCmdOfvMemFlsCmdDummyCycleValueType ReadBbmLutCmdOfvMemFlsCmdDummyCycleValue;  /**< Read BBM LUT command. */
  vMem_30_vXSpi_Nand_ReadCmdOfvMemFlsCmdDummyCycleValueType ReadCmdOfvMemFlsCmdDummyCycleValue;  /**< Read command. */
  vMem_30_vXSpi_Nand_ReadStatusRegisterCmdOfvMemFlsCmdDummyCycleValueType ReadStatusRegisterCmdOfvMemFlsCmdDummyCycleValue;  /**< Read status register command. */
  vMem_30_vXSpi_Nand_ReadVolatileConfigurationRegisterCmdOfvMemFlsCmdDummyCycleValueType ReadVolatileConfigurationRegisterCmdOfvMemFlsCmdDummyCycleValue;  /**< Read volatile configuration register command. */
  vMem_30_vXSpi_Nand_ReplaceLogicalBlocksCmdOfvMemFlsCmdDummyCycleValueType ReplaceLogicalBlocksCmdOfvMemFlsCmdDummyCycleValue;  /**< Replace logical sector command. */
  vMem_30_vXSpi_Nand_SoftwareDieSelectCmdOfvMemFlsCmdDummyCycleValueType SoftwareDieSelectCmdOfvMemFlsCmdDummyCycleValue;  /**< Software die select command. */
  vMem_30_vXSpi_Nand_WriteEnableCmdOfvMemFlsCmdDummyCycleValueType WriteEnableCmdOfvMemFlsCmdDummyCycleValue;  /**< Write enable command. */
  vMem_30_vXSpi_Nand_WriteStatusRegisterCmdOfvMemFlsCmdDummyCycleValueType WriteStatusRegisterCmdOfvMemFlsCmdDummyCycleValue;  /**< Write status register command. */
  vMem_30_vXSpi_Nand_WriteVolatileConfigurationRegisterCmdOfvMemFlsCmdDummyCycleValueType WriteVolatileConfigurationRegisterCmdOfvMemFlsCmdDummyCycleValue;  /**< Write volatile configuration register command. */
} vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValueType;

/**   \brief  type used in vMem_30_vXSpi_Nand_vMemFlsCmdValue */
typedef struct svMem_30_vXSpi_Nand_vMemFlsCmdValueType
{
  vMem_30_vXSpi_Nand_EraseCmdOfvMemFlsCmdValueType EraseCmdOfvMemFlsCmdValue;  /**< Erase command. */
  vMem_30_vXSpi_Nand_PageDataReadCmdOfvMemFlsCmdValueType PageDataReadCmdOfvMemFlsCmdValue;  /**< Page data read command. */
  vMem_30_vXSpi_Nand_ProgramDataLoadCmdOfvMemFlsCmdValueType ProgramDataLoadCmdOfvMemFlsCmdValue;  /**< Program data load command. */
  vMem_30_vXSpi_Nand_ProgramExecuteCmdOfvMemFlsCmdValueType ProgramExecuteCmdOfvMemFlsCmdValue;  /**< Program execute command. */
  vMem_30_vXSpi_Nand_ReadBbmLutCmdOfvMemFlsCmdValueType ReadBbmLutCmdOfvMemFlsCmdValue;  /**< Read BBM LUT command. */
  vMem_30_vXSpi_Nand_ReadCmdOfvMemFlsCmdValueType ReadCmdOfvMemFlsCmdValue;  /**< Read command. */
  vMem_30_vXSpi_Nand_ReadStatusRegisterCmdOfvMemFlsCmdValueType ReadStatusRegisterCmdOfvMemFlsCmdValue;  /**< Read status register command. */
  vMem_30_vXSpi_Nand_ReadVolatileConfigurationRegisterCmdOfvMemFlsCmdValueType ReadVolatileConfigurationRegisterCmdOfvMemFlsCmdValue;  /**< Read volatile configuration register command. */
  vMem_30_vXSpi_Nand_ReplaceLogicalBlocksCmdOfvMemFlsCmdValueType ReplaceLogicalBlocksCmdOfvMemFlsCmdValue;  /**< Replace logical sector command. */
  vMem_30_vXSpi_Nand_SoftwareDieSelectCmdOfvMemFlsCmdValueType SoftwareDieSelectCmdOfvMemFlsCmdValue;  /**< Software die select command. */
  vMem_30_vXSpi_Nand_WriteEnableCmdOfvMemFlsCmdValueType WriteEnableCmdOfvMemFlsCmdValue;  /**< Write enable command. */
  vMem_30_vXSpi_Nand_WriteStatusRegisterCmdOfvMemFlsCmdValueType WriteStatusRegisterCmdOfvMemFlsCmdValue;  /**< Write status register command. */
  vMem_30_vXSpi_Nand_WriteVolatileConfigurationRegisterCmdOfvMemFlsCmdValueType WriteVolatileConfigurationRegisterCmdOfvMemFlsCmdValue;  /**< Write volatile configuration register command. */
} vMem_30_vXSpi_Nand_vMemFlsCmdValueType;

/**   \brief  type used in vMem_30_vXSpi_Nand_vMemInstance */
typedef struct svMem_30_vXSpi_Nand_vMemInstanceType
{
  vMem_30_vXSpi_Nand_BlankCheckBufferArrayOne2SortedNEndIdxOfvMemInstanceType BlankCheckBufferArrayOne2SortedNEndIdxOfvMemInstance;  /**< the end index of the 1:n relation pointing to vMem_30_vXSpi_Nand_BlankCheckBufferArray */
  vMem_30_vXSpi_Nand_BlankCheckBufferArrayOne2SortedNLengthOfvMemInstanceType BlankCheckBufferArrayOne2SortedNLengthOfvMemInstance;  /**< the number of relations pointing to vMem_30_vXSpi_Nand_BlankCheckBufferArray */
  vMem_30_vXSpi_Nand_BlankCheckBufferArrayOne2SortedNStartIdxOfvMemInstanceType BlankCheckBufferArrayOne2SortedNStartIdxOfvMemInstance;  /**< the start index of the 1:n relation pointing to vMem_30_vXSpi_Nand_BlankCheckBufferArray */
  vMem_30_vXSpi_Nand_BusyCheckTimeoutThresholdOfvMemInstanceType BusyCheckTimeoutThresholdOfvMemInstance;  /**< Specifies the maximum number of busy checks before the active job fails. */
  vMem_30_vXSpi_Nand_AutomatedBadBlockManagmentOfvMemInstanceType AutomatedBadBlockManagmentOfvMemInstance;  /**< Specifies if the automated bad block managment is used */
  vMem_30_vXSpi_Nand_SoftwareDieSelectCommandUsedOfvMemInstanceType SoftwareDieSelectCommandUsedOfvMemInstance;  /**< Specifies if software die select command is used. */
  vMem_30_vXSpi_Nand_IdOfvMemInstanceType IdOfvMemInstance;  /**< Unique numeric identifier of the instance, used to distinguish between vMem instances. */
  vMem_30_vXSpi_Nand_MemSectorEndIdxOfvMemInstanceType MemSectorEndIdxOfvMemInstance;  /**< the end index of the 1:n relation pointing to vMem_30_vXSpi_Nand_MemSector */
  vMem_30_vXSpi_Nand_MemSectorLengthOfvMemInstanceType MemSectorLengthOfvMemInstance;  /**< the number of relations pointing to vMem_30_vXSpi_Nand_MemSector */
  vMem_30_vXSpi_Nand_MemSectorStartIdxOfvMemInstanceType MemSectorStartIdxOfvMemInstance;  /**< the start index of the 1:n relation pointing to vMem_30_vXSpi_Nand_MemSector */
  vMem_30_vXSpi_Nand_vMemDieEndIdxOfvMemInstanceType vMemDieEndIdxOfvMemInstance;  /**< the end index of the 1:n relation pointing to vMem_30_vXSpi_Nand_vMemDie */
  vMem_30_vXSpi_Nand_vMemDieLengthOfvMemInstanceType vMemDieLengthOfvMemInstance;  /**< the number of relations pointing to vMem_30_vXSpi_Nand_vMemDie */
  vMem_30_vXSpi_Nand_vMemDieStartIdxOfvMemInstanceType vMemDieStartIdxOfvMemInstance;  /**< the start index of the 1:n relation pointing to vMem_30_vXSpi_Nand_vMemDie */
  vMem_30_vXSpi_Nand_vXSpiProtocolModeIdType GenericProtocolModeIdOfvMemInstance;  /**< Specifies the protocol mode used for all commands except reading and writing data */
  vMem_30_vXSpi_Nand_vXSpiProtocolModeIdType ReadDataProtocolModeIdOfvMemInstance;  /**< Specifies the protocol mode used reading data */
  vMem_30_vXSpi_Nand_vXSpiProtocolModeIdType WriteDataProtocolModeIdOfvMemInstance;  /**< Specifies the protocol mode used writing data */
} vMem_30_vXSpi_Nand_vMemInstanceType;

/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_vXSpi_NandPCSymbolicStructTypes  vMem_30_vXSpi_Nand Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to vMem_30_vXSpi_Nand_BlankCheckBufferArray */
typedef struct vMem_30_vXSpi_Nand_BlankCheckBufferArrayStructSTag
{
  vMem_30_vXSpi_Nand_BlankCheckBufferArrayType vMemInstance_ExtFlash[4096];
} vMem_30_vXSpi_Nand_BlankCheckBufferArrayStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_vXSpi_NandPCUnionIndexAndSymbolTypes  vMem_30_vXSpi_Nand Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access vMem_30_vXSpi_Nand_BlankCheckBufferArray in an index and symbol based style. */
typedef union vMem_30_vXSpi_Nand_BlankCheckBufferArrayUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  vMem_30_vXSpi_Nand_BlankCheckBufferArrayType raw[4096];
  vMem_30_vXSpi_Nand_BlankCheckBufferArrayStructSType str;
} vMem_30_vXSpi_Nand_BlankCheckBufferArrayUType;

/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_vXSpi_NandPCRootPointerTypes  vMem_30_vXSpi_Nand Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to vMem_30_vXSpi_Nand_BlankCheckBufferArray */
typedef P2VAR(vMem_30_vXSpi_Nand_BlankCheckBufferArrayType, TYPEDEF, VMEM_30_VXSPI_NAND_VAR_NOINIT) vMem_30_vXSpi_Nand_BlankCheckBufferArrayPtrType;

/**   \brief  type used to point to vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId */
typedef P2CONST(vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceIdType, TYPEDEF, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceIdPtrType;

/**   \brief  type used to point to vMem_30_vXSpi_Nand_MemSector */
typedef P2CONST(vMem_30_vXSpi_Nand_MemSectorType, TYPEDEF, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_MemSectorPtrType;

/**   \brief  type used to point to vMem_30_vXSpi_Nand_vMemDeviceConfig */
typedef P2CONST(vMem_30_vXSpi_Nand_vMemDeviceConfigType, TYPEDEF, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_vMemDeviceConfigPtrType;

/**   \brief  type used to point to vMem_30_vXSpi_Nand_vMemDie */
typedef P2CONST(vMem_30_vXSpi_Nand_vMemDieType, TYPEDEF, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_vMemDiePtrType;

/**   \brief  type used to point to vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValue */
typedef P2CONST(vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValueType, TYPEDEF, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValuePtrType;

/**   \brief  type used to point to vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue */
typedef P2CONST(vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValueType, TYPEDEF, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValuePtrType;

/**   \brief  type used to point to vMem_30_vXSpi_Nand_vMemFlsCmdValue */
typedef P2CONST(vMem_30_vXSpi_Nand_vMemFlsCmdValueType, TYPEDEF, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_vMemFlsCmdValuePtrType;

/**   \brief  type used to point to vMem_30_vXSpi_Nand_vMemInstance */
typedef P2CONST(vMem_30_vXSpi_Nand_vMemInstanceType, TYPEDEF, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_vMemInstancePtrType;

/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_vXSpi_NandPCRootValueTypes  vMem_30_vXSpi_Nand Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in vMem_30_vXSpi_Nand_PCConfig */
typedef struct svMem_30_vXSpi_Nand_PCConfigType
{
  uint8 vMem_30_vXSpi_Nand_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} vMem_30_vXSpi_Nand_PCConfigType;

typedef vMem_30_vXSpi_Nand_PCConfigType vMem_30_vXSpi_Nand_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId
**********************************************************************************************************************/
/** 
  \var    vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId
  \brief  Mapping between Instance Id and vXSpi Device Id
*/ 
#define VMEM_30_VXSPI_NAND_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceIdType, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define VMEM_30_VXSPI_NAND_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMem_30_vXSpi_Nand_MemSector
**********************************************************************************************************************/
/** 
  \var    vMem_30_vXSpi_Nand_MemSector
  \brief  Configuration description of a programmable sector or sector batch.
  \details
  Element              Description
  EraseBurstSize       Burst size for erase jobs, if configured. Otherwise sector size
  SectorSize           Size of this sector in bytes.
  StartAddress         Physical start address of the first sector.
  NrOfSectors          Number of continuous sectors with identical values for vMemSectorSize and vMemPageSize.
  PageSize             Size of one page of this sector in bytes.
  WriteBurstSize       Burst size for write jobs, if configured. Otherwise page size
  ReplacementSector    Specifies whether the MemSector consists of replacement sectors.
  RamAlignment         In order to perform write jobs correctly, a device might require a specific alignment of the data buffer.
  vMemDieIdx           the index of the 1:1 relation pointing to vMem_30_vXSpi_Nand_vMemDie
*/ 
#define VMEM_30_VXSPI_NAND_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vMem_30_vXSpi_Nand_MemSectorType, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_MemSector[2];
#define VMEM_30_VXSPI_NAND_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMem_30_vXSpi_Nand_vMemDeviceConfig
**********************************************************************************************************************/
/** 
  \var    vMem_30_vXSpi_Nand_vMemDeviceConfig
  \details
  Element                                          Description
  InputOutputModeRegisterExisting                  Is input output mode register existing
  EraseValue                                       Erase value.
  InputOutputModeRegisterAddress                   Address of input output mode register
  InputOutputModeRegisterValue                     Value of input output mode register
  LutAddressLength                                 Length of one address within the Lookup table
  LutDataBufferLength                              Length of Lookup table data buffer
  LutEntryLength                                   Length of one Lookup table entry
  LutMaxEntries                                    Maximal number of Lookup table entries
  StatusRegister1Address                           Address of status register 1
  StatusRegister2Address                           Address of status register 2
  StatusRegister3Address                           Address of status register 3
  StatusRegisterBufferReadModeBitMask              Status register buffer read mode bitmask.
  StatusRegisterBusyFlagBitMask                    Status register busy flag bitmask.
  StatusRegisterDataBufferLength                   Length of status register data buffer
  StatusRegisterEcc0BitMask                        Status register ECC0 bitmask.
  StatusRegisterEcc1BitMask                        Status register ECC1 bitmask.
  StatusRegisterEraseErrorBitMask                  Status register erase error bitmask.
  StatusRegisterLutFBitMask                        Status register Lookup table full bitmask.
  StatusRegisterProgramErrorBitMask                Status register program error bitmask.
  StatusRegisterProtectionBitMask                  Status register Protection bitmask.
  VolatileConfigurationRegisterDataBufferLength    Length of volatile configuration register data buffer
*/ 
#define VMEM_30_VXSPI_NAND_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vMem_30_vXSpi_Nand_vMemDeviceConfigType, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_vMemDeviceConfig[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define VMEM_30_VXSPI_NAND_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMem_30_vXSpi_Nand_vMemDie
**********************************************************************************************************************/
/** 
  \var    vMem_30_vXSpi_Nand_vMemDie
  \brief  Configuration description of a flash memory die.
  \details
  Element            Description
  DieSize            Size of the die.
  DieStartAddress    Memory start address of the die.
*/ 
#define VMEM_30_VXSPI_NAND_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vMem_30_vXSpi_Nand_vMemDieType, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_vMemDie[1];
#define VMEM_30_VXSPI_NAND_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValue
**********************************************************************************************************************/
/** 
  \var    vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValue
  \details
  Element                                  Description
  EraseCmd                                 Erase command.
  PageDataReadCmd                          Page data read command.
  ProgramDataLoadCmd                       Program data load command.
  ProgramExecuteCmd                        Program execute command.
  ReadBbmLutCmd                            Read BBM LUT command.
  ReadCmd                                  Read command.
  ReadStatusRegisterCmd                    Read status register command.
  ReadVolatileConfigurationRegisterCmd     Read volatile configuration register command.
  ReplaceLogicalBlocksCmd                  Replace logical sector command.
  SoftwareDieSelectCmd                     Software die select command.
  WriteEnableCmd                           Write enable command.
  WriteStatusRegisterCmd                   Write status register command.
  WriteVolatileConfigurationRegisterCmd    Write volatile configuration register command.
*/ 
#define VMEM_30_VXSPI_NAND_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValueType, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValue[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define VMEM_30_VXSPI_NAND_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue
**********************************************************************************************************************/
/** 
  \var    vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue
  \details
  Element                                  Description
  EraseCmd                                 Erase command.
  PageDataReadCmd                          Page data read command.
  ProgramDataLoadCmd                       Program data load command.
  ProgramExecuteCmd                        Program execute command.
  ReadBbmLutCmd                            Read BBM LUT command.
  ReadCmd                                  Read command.
  ReadStatusRegisterCmd                    Read status register command.
  ReadVolatileConfigurationRegisterCmd     Read volatile configuration register command.
  ReplaceLogicalBlocksCmd                  Replace logical sector command.
  SoftwareDieSelectCmd                     Software die select command.
  WriteEnableCmd                           Write enable command.
  WriteStatusRegisterCmd                   Write status register command.
  WriteVolatileConfigurationRegisterCmd    Write volatile configuration register command.
*/ 
#define VMEM_30_VXSPI_NAND_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValueType, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define VMEM_30_VXSPI_NAND_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMem_30_vXSpi_Nand_vMemFlsCmdValue
**********************************************************************************************************************/
/** 
  \var    vMem_30_vXSpi_Nand_vMemFlsCmdValue
  \details
  Element                                  Description
  EraseCmd                                 Erase command.
  PageDataReadCmd                          Page data read command.
  ProgramDataLoadCmd                       Program data load command.
  ProgramExecuteCmd                        Program execute command.
  ReadBbmLutCmd                            Read BBM LUT command.
  ReadCmd                                  Read command.
  ReadStatusRegisterCmd                    Read status register command.
  ReadVolatileConfigurationRegisterCmd     Read volatile configuration register command.
  ReplaceLogicalBlocksCmd                  Replace logical sector command.
  SoftwareDieSelectCmd                     Software die select command.
  WriteEnableCmd                           Write enable command.
  WriteStatusRegisterCmd                   Write status register command.
  WriteVolatileConfigurationRegisterCmd    Write volatile configuration register command.
*/ 
#define VMEM_30_VXSPI_NAND_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vMem_30_vXSpi_Nand_vMemFlsCmdValueType, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_vMemFlsCmdValue[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define VMEM_30_VXSPI_NAND_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMem_30_vXSpi_Nand_vMemInstance
**********************************************************************************************************************/
/** 
  \var    vMem_30_vXSpi_Nand_vMemInstance
  \brief  List of all configured vMem instances.
  \details
  Element                                     Description
  BlankCheckBufferArrayOne2SortedNEndIdx      the end index of the 1:n relation pointing to vMem_30_vXSpi_Nand_BlankCheckBufferArray
  BlankCheckBufferArrayOne2SortedNLength      the number of relations pointing to vMem_30_vXSpi_Nand_BlankCheckBufferArray
  BlankCheckBufferArrayOne2SortedNStartIdx    the start index of the 1:n relation pointing to vMem_30_vXSpi_Nand_BlankCheckBufferArray
  BusyCheckTimeoutThreshold                   Specifies the maximum number of busy checks before the active job fails.
  AutomatedBadBlockManagment                  Specifies if the automated bad block managment is used
  SoftwareDieSelectCommandUsed                Specifies if software die select command is used.
  Id                                          Unique numeric identifier of the instance, used to distinguish between vMem instances.
  MemSectorEndIdx                             the end index of the 1:n relation pointing to vMem_30_vXSpi_Nand_MemSector
  MemSectorLength                             the number of relations pointing to vMem_30_vXSpi_Nand_MemSector
  MemSectorStartIdx                           the start index of the 1:n relation pointing to vMem_30_vXSpi_Nand_MemSector
  vMemDieEndIdx                               the end index of the 1:n relation pointing to vMem_30_vXSpi_Nand_vMemDie
  vMemDieLength                               the number of relations pointing to vMem_30_vXSpi_Nand_vMemDie
  vMemDieStartIdx                             the start index of the 1:n relation pointing to vMem_30_vXSpi_Nand_vMemDie
  GenericProtocolModeId                       Specifies the protocol mode used for all commands except reading and writing data
  ReadDataProtocolModeId                      Specifies the protocol mode used reading data
  WriteDataProtocolModeId                     Specifies the protocol mode used writing data
*/ 
#define VMEM_30_VXSPI_NAND_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vMem_30_vXSpi_Nand_vMemInstanceType, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_vMemInstance[1];
#define VMEM_30_VXSPI_NAND_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMem_30_vXSpi_Nand_BlankCheckBufferArray
**********************************************************************************************************************/
/** 
  \var    vMem_30_vXSpi_Nand_BlankCheckBufferArray
  \brief  BlankCheckBufferArray
*/ 
#define VMEM_30_VXSPI_NAND_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(vMem_30_vXSpi_Nand_BlankCheckBufferArrayUType, VMEM_30_VXSPI_NAND_VAR_NOINIT) vMem_30_vXSpi_Nand_BlankCheckBufferArray;  /* PRQA S 0777, 0759 */  /* MD_MSR_Rule5.1, MD_CSL_Union */
#define VMEM_30_VXSPI_NAND_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  GLOBAL INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


#endif /* VMEM_30_VXSPI_NAND_CFG_H */
