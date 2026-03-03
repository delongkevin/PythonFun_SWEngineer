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
 *            Module: vMem_30_XXRam
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vMem_30_XXRam_Cfg.h
 *   Generation Time: 2022-11-08 19:25:58
 *           Project: DemoUpdater - Version 1.0
 *          Delivery: CBD2101146_D04
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined (VMEM_30_XXRAM_CFG_H)
# define VMEM_30_XXRAM_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"

/**********************************************************************************************************************
 *  VERSION INFORMATION
 *********************************************************************************************************************/

/*! \brief Version defines of generator version */
# define VMEM_30_XXRAM_CFG_MAJOR_VERSION        2u
# define VMEM_30_XXRAM_CFG_MINOR_VERSION        1u
# define VMEM_30_XXRAM_CFG_PATCH_VERSION        0u

/*! \brief Version defines that are used to check the compatibility of the generated data */
# define VMEM_30_XXRAM_CFG_COMP_MAJOR_VERSION   2u
# define VMEM_30_XXRAM_CFG_COMP_MINOR_VERSION   1u
# define VMEM_30_XXRAM_CFG_COMP_PATCH_VERSION   0u


/**********************************************************************************************************************
 *  GENERAL DEFINE BLOCK
 *********************************************************************************************************************/
# ifndef VMEM_30_XXRAM_USE_DUMMY_STATEMENT
#  define VMEM_30_XXRAM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
# endif
# ifndef VMEM_30_XXRAM_DUMMY_STATEMENT
#  define VMEM_30_XXRAM_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
# endif
# ifndef VMEM_30_XXRAM_DUMMY_STATEMENT_CONST
#  define VMEM_30_XXRAM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
# endif
# ifndef VMEM_30_XXRAM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#  define VMEM_30_XXRAM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
# endif
# ifndef VMEM_30_XXRAM_ATOMIC_VARIABLE_ACCESS
#  define VMEM_30_XXRAM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
# endif
# ifndef VMEM_30_XXRAM_PROCESSOR_TDA4VE88
#  define VMEM_30_XXRAM_PROCESSOR_TDA4VE88
# endif
# ifndef VMEM_30_XXRAM_COMP_LLVMTEXASINSTRUMENTS
#  define VMEM_30_XXRAM_COMP_LLVMTEXASINSTRUMENTS
# endif
# ifndef VMEM_30_XXRAM_GEN_GENERATOR_MSR
#  define VMEM_30_XXRAM_GEN_GENERATOR_MSR
# endif
# ifndef VMEM_30_XXRAM_CPUTYPE_BITORDER_LSB2MSB
#  define VMEM_30_XXRAM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
# endif
# ifndef VMEM_30_XXRAM_CONFIGURATION_VARIANT_PRECOMPILE
#  define VMEM_30_XXRAM_CONFIGURATION_VARIANT_PRECOMPILE 1
# endif
# ifndef VMEM_30_XXRAM_CONFIGURATION_VARIANT_LINKTIME
#  define VMEM_30_XXRAM_CONFIGURATION_VARIANT_LINKTIME 2
# endif
# ifndef VMEM_30_XXRAM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#  define VMEM_30_XXRAM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
# endif
# ifndef VMEM_30_XXRAM_CONFIGURATION_VARIANT
#  define VMEM_30_XXRAM_CONFIGURATION_VARIANT VMEM_30_XXRAM_CONFIGURATION_VARIANT_PRECOMPILE
# endif
# ifndef VMEM_30_XXRAM_POSTBUILD_VARIANT_SUPPORT
#  define VMEM_30_XXRAM_POSTBUILD_VARIANT_SUPPORT STD_OFF
# endif


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/*! Enables / disables development error detection */
#ifndef VMEM_30_XXRAM_DEV_ERROR_DETECT
# define VMEM_30_XXRAM_DEV_ERROR_DETECT         STD_ON
#endif

/*! Enables / disables development error reporting (enabled whenever error detection is configured) */
#ifndef VMEM_30_XXRAM_DEV_ERROR_REPORT
# define VMEM_30_XXRAM_DEV_ERROR_REPORT         STD_ON
#endif

/*! Enables / disables the version information API (VMEM_30_XXRAM_GetVersionInfo) */
#ifndef VMEM_30_XXRAM_VERSION_INFO_API
# define VMEM_30_XXRAM_VERSION_INFO_API         STD_OFF
#endif

/*! Maximal number of sectors over all instances */
#define VMEM_30_XXRAM_MAX_NUM_OF_SECTORS_OF_ALL_INSTANCES         1u

/*! Maximal page size over all instances */
#define VMEM_30_XXRAM_MAX_PAGE_SIZE_OF_ALL_INSTANCES              1000u

/*! Enables / disables read only mode (This define will only be used if this mode is supported by the vMem low level.) */
#define VMEM_30_XXRAM_READONLY_MODE             STD_OFF

/*! vMem driver ID */
#define VMEM_30_XXRAM_DRIVER_ID                 0x000D635Cu

/* Add here additional general GLOBAL CONSTANT MACROS */


/* \brief Enables / disables the use internal buffer API (vMem_30_XXRam_UseInternalRAMBuffer) */
#ifndef VMEM_30_XXRAM_USE_INTERNAL_RAMBUFFER_API
# define VMEM_30_XXRAM_USE_INTERNAL_RAMBUFFER_API STD_OFF
#endif 

/* \brief This macro specifies the value indicating memory to be erased */
#ifndef VMEM_30_XXRAM_ERASEDVALUE
# define VMEM_30_XXRAM_ERASEDVALUE (0xFFu)
#endif 



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  vMem_30_XXRamPCDataSwitches  vMem_30_XXRam Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define VMEM_30_XXRAM_FINALMAGICNUMBER                                STD_OFF  /**< Deactivateable: 'vMem_30_XXRam_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define VMEM_30_XXRAM_INITDATAHASHCODE                                STD_OFF  /**< Deactivateable: 'vMem_30_XXRam_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define VMEM_30_XXRAM_MEMSECTOR                                       STD_ON
#define VMEM_30_XXRAM_ERASEBURSTSIZEOFMEMSECTOR                       STD_ON
#define VMEM_30_XXRAM_NROFSECTORSOFMEMSECTOR                          STD_ON
#define VMEM_30_XXRAM_PAGESIZEOFMEMSECTOR                             STD_ON
#define VMEM_30_XXRAM_RAMALIGNMENTOFMEMSECTOR                         STD_ON
#define VMEM_30_XXRAM_SECTORSIZEOFMEMSECTOR                           STD_ON
#define VMEM_30_XXRAM_STARTADDRESSOFMEMSECTOR                         STD_ON
#define VMEM_30_XXRAM_WRITEBURSTSIZEOFMEMSECTOR                       STD_ON
#define VMEM_30_XXRAM_SIZEOFMEMSECTOR                                 STD_ON
#define VMEM_30_XXRAM_SIZEOFVMEMINSTANCE                              STD_ON
#define VMEM_30_XXRAM_VMEMINSTANCE                                    STD_ON
#define VMEM_30_XXRAM_IDOFVMEMINSTANCE                                STD_ON
#define VMEM_30_XXRAM_MEMSECTORENDIDXOFVMEMINSTANCE                   STD_ON
#define VMEM_30_XXRAM_MEMSECTORLENGTHOFVMEMINSTANCE                   STD_ON
#define VMEM_30_XXRAM_MEMSECTORSTARTIDXOFVMEMINSTANCE                 STD_ON
#define VMEM_30_XXRAM_PCCONFIG                                        STD_ON
#define VMEM_30_XXRAM_FINALMAGICNUMBEROFPCCONFIG                      STD_OFF  /**< Deactivateable: 'vMem_30_XXRam_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define VMEM_30_XXRAM_INITDATAHASHCODEOFPCCONFIG                      STD_OFF  /**< Deactivateable: 'vMem_30_XXRam_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define VMEM_30_XXRAM_MEMSECTOROFPCCONFIG                             STD_ON
#define VMEM_30_XXRAM_SIZEOFMEMSECTOROFPCCONFIG                       STD_ON
#define VMEM_30_XXRAM_SIZEOFVMEMINSTANCEOFPCCONFIG                    STD_ON
#define VMEM_30_XXRAM_VMEMINSTANCEOFPCCONFIG                          STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_XXRamPCIsReducedToDefineDefines  vMem_30_XXRam Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define VMEM_30_XXRAM_ISDEF_ERASEBURSTSIZEOFMEMSECTOR                 STD_OFF
#define VMEM_30_XXRAM_ISDEF_NROFSECTORSOFMEMSECTOR                    STD_OFF
#define VMEM_30_XXRAM_ISDEF_PAGESIZEOFMEMSECTOR                       STD_OFF
#define VMEM_30_XXRAM_ISDEF_RAMALIGNMENTOFMEMSECTOR                   STD_OFF
#define VMEM_30_XXRAM_ISDEF_SECTORSIZEOFMEMSECTOR                     STD_OFF
#define VMEM_30_XXRAM_ISDEF_STARTADDRESSOFMEMSECTOR                   STD_OFF
#define VMEM_30_XXRAM_ISDEF_WRITEBURSTSIZEOFMEMSECTOR                 STD_OFF
#define VMEM_30_XXRAM_ISDEF_IDOFVMEMINSTANCE                          STD_OFF
#define VMEM_30_XXRAM_ISDEF_MEMSECTORENDIDXOFVMEMINSTANCE             STD_OFF
#define VMEM_30_XXRAM_ISDEF_MEMSECTORLENGTHOFVMEMINSTANCE             STD_OFF
#define VMEM_30_XXRAM_ISDEF_MEMSECTORSTARTIDXOFVMEMINSTANCE           STD_OFF
#define VMEM_30_XXRAM_ISDEF_MEMSECTOROFPCCONFIG                       STD_ON
#define VMEM_30_XXRAM_ISDEF_VMEMINSTANCEOFPCCONFIG                    STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_XXRamPCEqualsAlwaysToDefines  vMem_30_XXRam Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define VMEM_30_XXRAM_EQ2_ERASEBURSTSIZEOFMEMSECTOR                   
#define VMEM_30_XXRAM_EQ2_NROFSECTORSOFMEMSECTOR                      
#define VMEM_30_XXRAM_EQ2_PAGESIZEOFMEMSECTOR                         
#define VMEM_30_XXRAM_EQ2_RAMALIGNMENTOFMEMSECTOR                     
#define VMEM_30_XXRAM_EQ2_SECTORSIZEOFMEMSECTOR                       
#define VMEM_30_XXRAM_EQ2_STARTADDRESSOFMEMSECTOR                     
#define VMEM_30_XXRAM_EQ2_WRITEBURSTSIZEOFMEMSECTOR                   
#define VMEM_30_XXRAM_EQ2_IDOFVMEMINSTANCE                            
#define VMEM_30_XXRAM_EQ2_MEMSECTORENDIDXOFVMEMINSTANCE               
#define VMEM_30_XXRAM_EQ2_MEMSECTORLENGTHOFVMEMINSTANCE               
#define VMEM_30_XXRAM_EQ2_MEMSECTORSTARTIDXOFVMEMINSTANCE             
#define VMEM_30_XXRAM_EQ2_MEMSECTOROFPCCONFIG                         vMem_30_XXRam_MemSector
#define VMEM_30_XXRAM_EQ2_VMEMINSTANCEOFPCCONFIG                      vMem_30_XXRam_vMemInstance
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_XXRamPCSymbolicInitializationPointers  vMem_30_XXRam Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define vMem_30_XXRam_Config_Ptr                                      NULL_PTR  /**< symbolic identifier which shall be used to initialize 'vMem_30_XXRam' */
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_XXRamPCInitializationSymbols  vMem_30_XXRam Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define vMem_30_XXRam_Config                                          NULL_PTR  /**< symbolic identifier which could be used to initialize 'vMem_30_XXRam */
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_XXRamPCGeneral  vMem_30_XXRam General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define VMEM_30_XXRAM_CHECK_INIT_POINTER                              STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define VMEM_30_XXRAM_FINAL_MAGIC_NUMBER                              0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of vMem_30_XXRam */
#define VMEM_30_XXRAM_INDIVIDUAL_POSTBUILD                            STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'vMem_30_XXRam' is not configured to be postbuild capable. */
#define VMEM_30_XXRAM_INIT_DATA                                       VMEM_30_XXRAM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define VMEM_30_XXRAM_INIT_DATA_HASH_CODE                             1497874847  /**< the precompile constant to validate the initialization structure at initialization time of vMem_30_XXRam with a hashcode. The seed value is '0xFF1Eu' */
#define VMEM_30_XXRAM_USE_ECUM_BSW_ERROR_HOOK                         STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define VMEM_30_XXRAM_USE_INIT_POINTER                                STD_OFF  /**< STD_ON if the init pointer vMem_30_XXRam shall be used. */
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
  \defgroup  vMem_30_XXRamPCGetConstantDuplicatedRootDataMacros  vMem_30_XXRam Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define vMem_30_XXRam_GetMemSectorOfPCConfig()                        vMem_30_XXRam_MemSector  /**< the pointer to vMem_30_XXRam_MemSector */
#define vMem_30_XXRam_GetSizeOfMemSectorOfPCConfig()                  1u  /**< the number of accomplishable value elements in vMem_30_XXRam_MemSector */
#define vMem_30_XXRam_GetSizeOfvMemInstanceOfPCConfig()               1u  /**< the number of accomplishable value elements in vMem_30_XXRam_vMemInstance */
#define vMem_30_XXRam_GetvMemInstanceOfPCConfig()                     vMem_30_XXRam_vMemInstance  /**< the pointer to vMem_30_XXRam_vMemInstance */
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_XXRamPCGetDataMacros  vMem_30_XXRam Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define vMem_30_XXRam_GetEraseBurstSizeOfMemSector(Index)             (vMem_30_XXRam_GetMemSectorOfPCConfig()[(Index)].EraseBurstSizeOfMemSector)
#define vMem_30_XXRam_GetNrOfSectorsOfMemSector(Index)                (vMem_30_XXRam_GetMemSectorOfPCConfig()[(Index)].NrOfSectorsOfMemSector)
#define vMem_30_XXRam_GetPageSizeOfMemSector(Index)                   (vMem_30_XXRam_GetMemSectorOfPCConfig()[(Index)].PageSizeOfMemSector)
#define vMem_30_XXRam_GetRamAlignmentOfMemSector(Index)               (vMem_30_XXRam_GetMemSectorOfPCConfig()[(Index)].RamAlignmentOfMemSector)
#define vMem_30_XXRam_GetSectorSizeOfMemSector(Index)                 (vMem_30_XXRam_GetMemSectorOfPCConfig()[(Index)].SectorSizeOfMemSector)
#define vMem_30_XXRam_GetStartAddressOfMemSector(Index)               (vMem_30_XXRam_GetMemSectorOfPCConfig()[(Index)].StartAddressOfMemSector)
#define vMem_30_XXRam_GetWriteBurstSizeOfMemSector(Index)             (vMem_30_XXRam_GetMemSectorOfPCConfig()[(Index)].WriteBurstSizeOfMemSector)
#define vMem_30_XXRam_GetIdOfvMemInstance(Index)                      (vMem_30_XXRam_GetvMemInstanceOfPCConfig()[(Index)].IdOfvMemInstance)
#define vMem_30_XXRam_GetMemSectorEndIdxOfvMemInstance(Index)         (vMem_30_XXRam_GetvMemInstanceOfPCConfig()[(Index)].MemSectorEndIdxOfvMemInstance)
#define vMem_30_XXRam_GetMemSectorLengthOfvMemInstance(Index)         (vMem_30_XXRam_GetvMemInstanceOfPCConfig()[(Index)].MemSectorLengthOfvMemInstance)
#define vMem_30_XXRam_GetMemSectorStartIdxOfvMemInstance(Index)       (vMem_30_XXRam_GetvMemInstanceOfPCConfig()[(Index)].MemSectorStartIdxOfvMemInstance)
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_XXRamPCGetDeduplicatedDataMacros  vMem_30_XXRam Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define vMem_30_XXRam_GetSizeOfMemSector()                            vMem_30_XXRam_GetSizeOfMemSectorOfPCConfig()
#define vMem_30_XXRam_GetSizeOfvMemInstance()                         vMem_30_XXRam_GetSizeOfvMemInstanceOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_XXRamPCHasMacros  vMem_30_XXRam Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define vMem_30_XXRam_HasMemSector()                                  (TRUE != FALSE)
#define vMem_30_XXRam_HasEraseBurstSizeOfMemSector()                  (TRUE != FALSE)
#define vMem_30_XXRam_HasNrOfSectorsOfMemSector()                     (TRUE != FALSE)
#define vMem_30_XXRam_HasPageSizeOfMemSector()                        (TRUE != FALSE)
#define vMem_30_XXRam_HasRamAlignmentOfMemSector()                    (TRUE != FALSE)
#define vMem_30_XXRam_HasSectorSizeOfMemSector()                      (TRUE != FALSE)
#define vMem_30_XXRam_HasStartAddressOfMemSector()                    (TRUE != FALSE)
#define vMem_30_XXRam_HasWriteBurstSizeOfMemSector()                  (TRUE != FALSE)
#define vMem_30_XXRam_HasSizeOfMemSector()                            (TRUE != FALSE)
#define vMem_30_XXRam_HasSizeOfvMemInstance()                         (TRUE != FALSE)
#define vMem_30_XXRam_HasvMemInstance()                               (TRUE != FALSE)
#define vMem_30_XXRam_HasIdOfvMemInstance()                           (TRUE != FALSE)
#define vMem_30_XXRam_HasMemSectorEndIdxOfvMemInstance()              (TRUE != FALSE)
#define vMem_30_XXRam_HasMemSectorLengthOfvMemInstance()              (TRUE != FALSE)
#define vMem_30_XXRam_HasMemSectorStartIdxOfvMemInstance()            (TRUE != FALSE)
#define vMem_30_XXRam_HasPCConfig()                                   (TRUE != FALSE)
#define vMem_30_XXRam_HasMemSectorOfPCConfig()                        (TRUE != FALSE)
#define vMem_30_XXRam_HasSizeOfMemSectorOfPCConfig()                  (TRUE != FALSE)
#define vMem_30_XXRam_HasSizeOfvMemInstanceOfPCConfig()               (TRUE != FALSE)
#define vMem_30_XXRam_HasvMemInstanceOfPCConfig()                     (TRUE != FALSE)
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
  \defgroup  vMem_30_XXRamPCIterableTypes  vMem_30_XXRam Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate vMem_30_XXRam_MemSector */
typedef uint8_least vMem_30_XXRam_MemSectorIterType;

/**   \brief  type used to iterate vMem_30_XXRam_vMemInstance */
typedef uint8_least vMem_30_XXRam_vMemInstanceIterType;

/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_XXRamPCValueTypes  vMem_30_XXRam Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for vMem_30_XXRam_EraseBurstSizeOfMemSector */
typedef uint32 vMem_30_XXRam_EraseBurstSizeOfMemSectorType;

/**   \brief  value based type definition for vMem_30_XXRam_NrOfSectorsOfMemSector */
typedef uint8 vMem_30_XXRam_NrOfSectorsOfMemSectorType;

/**   \brief  value based type definition for vMem_30_XXRam_PageSizeOfMemSector */
typedef uint16 vMem_30_XXRam_PageSizeOfMemSectorType;

/**   \brief  value based type definition for vMem_30_XXRam_RamAlignmentOfMemSector */
typedef uint8 vMem_30_XXRam_RamAlignmentOfMemSectorType;

/**   \brief  value based type definition for vMem_30_XXRam_SectorSizeOfMemSector */
typedef uint32 vMem_30_XXRam_SectorSizeOfMemSectorType;

/**   \brief  value based type definition for vMem_30_XXRam_StartAddressOfMemSector */
typedef uint32 vMem_30_XXRam_StartAddressOfMemSectorType;

/**   \brief  value based type definition for vMem_30_XXRam_WriteBurstSizeOfMemSector */
typedef uint16 vMem_30_XXRam_WriteBurstSizeOfMemSectorType;

/**   \brief  value based type definition for vMem_30_XXRam_SizeOfMemSector */
typedef uint8 vMem_30_XXRam_SizeOfMemSectorType;

/**   \brief  value based type definition for vMem_30_XXRam_SizeOfvMemInstance */
typedef uint8 vMem_30_XXRam_SizeOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_XXRam_IdOfvMemInstance */
typedef uint8 vMem_30_XXRam_IdOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_XXRam_MemSectorEndIdxOfvMemInstance */
typedef uint8 vMem_30_XXRam_MemSectorEndIdxOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_XXRam_MemSectorLengthOfvMemInstance */
typedef uint8 vMem_30_XXRam_MemSectorLengthOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_XXRam_MemSectorStartIdxOfvMemInstance */
typedef uint8 vMem_30_XXRam_MemSectorStartIdxOfvMemInstanceType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vMem_30_XXRamPCStructTypes  vMem_30_XXRam Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in vMem_30_XXRam_MemSector */
typedef struct svMem_30_XXRam_MemSectorType
{
  vMem_30_XXRam_EraseBurstSizeOfMemSectorType EraseBurstSizeOfMemSector;  /**< Burst size for erase jobs, if configured. Otherwise sector size */
  vMem_30_XXRam_SectorSizeOfMemSectorType SectorSizeOfMemSector;  /**< Size of this sector in bytes. */
  vMem_30_XXRam_StartAddressOfMemSectorType StartAddressOfMemSector;  /**< Physical start address of the first sector. */
  vMem_30_XXRam_PageSizeOfMemSectorType PageSizeOfMemSector;  /**< Size of one page of this sector in bytes. */
  vMem_30_XXRam_WriteBurstSizeOfMemSectorType WriteBurstSizeOfMemSector;  /**< Burst size for write jobs, if configured. Otherwise page size */
  vMem_30_XXRam_NrOfSectorsOfMemSectorType NrOfSectorsOfMemSector;  /**< Number of continuous sectors with identical values for vMemSectorSize and vMemPageSize. */
  vMem_30_XXRam_RamAlignmentOfMemSectorType RamAlignmentOfMemSector;  /**< In order to perform write jobs correctly, a device might require a specific alignment of the data buffer. */
} vMem_30_XXRam_MemSectorType;

/**   \brief  type used in vMem_30_XXRam_vMemInstance */
typedef struct svMem_30_XXRam_vMemInstanceType
{
  vMem_30_XXRam_IdOfvMemInstanceType IdOfvMemInstance;  /**< Unique numeric identifier of the instance, used to distinguish between vMem instances. */
  vMem_30_XXRam_MemSectorEndIdxOfvMemInstanceType MemSectorEndIdxOfvMemInstance;  /**< the end index of the 1:n relation pointing to vMem_30_XXRam_MemSector */
  vMem_30_XXRam_MemSectorLengthOfvMemInstanceType MemSectorLengthOfvMemInstance;  /**< the number of relations pointing to vMem_30_XXRam_MemSector */
  vMem_30_XXRam_MemSectorStartIdxOfvMemInstanceType MemSectorStartIdxOfvMemInstance;  /**< the start index of the 1:n relation pointing to vMem_30_XXRam_MemSector */
} vMem_30_XXRam_vMemInstanceType;

/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_XXRamPCRootPointerTypes  vMem_30_XXRam Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to vMem_30_XXRam_MemSector */
typedef P2CONST(vMem_30_XXRam_MemSectorType, TYPEDEF, VMEM_30_XXRAM_CONST) vMem_30_XXRam_MemSectorPtrType;

/**   \brief  type used to point to vMem_30_XXRam_vMemInstance */
typedef P2CONST(vMem_30_XXRam_vMemInstanceType, TYPEDEF, VMEM_30_XXRAM_CONST) vMem_30_XXRam_vMemInstancePtrType;

/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_XXRamPCRootValueTypes  vMem_30_XXRam Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in vMem_30_XXRam_PCConfig */
typedef struct svMem_30_XXRam_PCConfigType
{
  uint8 vMem_30_XXRam_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} vMem_30_XXRam_PCConfigType;

typedef vMem_30_XXRam_PCConfigType vMem_30_XXRam_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

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
  vMem_30_XXRam_MemSector
**********************************************************************************************************************/
/** 
  \var    vMem_30_XXRam_MemSector
  \brief  Configuration description of a programmable sector or sector batch.
  \details
  Element           Description
  EraseBurstSize    Burst size for erase jobs, if configured. Otherwise sector size
  SectorSize        Size of this sector in bytes.
  StartAddress      Physical start address of the first sector.
  PageSize          Size of one page of this sector in bytes.
  WriteBurstSize    Burst size for write jobs, if configured. Otherwise page size
  NrOfSectors       Number of continuous sectors with identical values for vMemSectorSize and vMemPageSize.
  RamAlignment      In order to perform write jobs correctly, a device might require a specific alignment of the data buffer.
*/ 
#define VMEM_30_XXRAM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vMem_30_XXRam_MemSectorType, VMEM_30_XXRAM_CONST) vMem_30_XXRam_MemSector[1];
#define VMEM_30_XXRAM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMem_30_XXRam_vMemInstance
**********************************************************************************************************************/
/** 
  \var    vMem_30_XXRam_vMemInstance
  \brief  List of all configured vMem instances.
  \details
  Element              Description
  Id                   Unique numeric identifier of the instance, used to distinguish between vMem instances.
  MemSectorEndIdx      the end index of the 1:n relation pointing to vMem_30_XXRam_MemSector
  MemSectorLength      the number of relations pointing to vMem_30_XXRam_MemSector
  MemSectorStartIdx    the start index of the 1:n relation pointing to vMem_30_XXRam_MemSector
*/ 
#define VMEM_30_XXRAM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vMem_30_XXRam_vMemInstanceType, VMEM_30_XXRAM_CONST) vMem_30_XXRam_vMemInstance[1];
#define VMEM_30_XXRAM_STOP_SEC_CONST_UNSPECIFIED
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


#endif /* VMEM_30_XXRAM_CFG_H */
