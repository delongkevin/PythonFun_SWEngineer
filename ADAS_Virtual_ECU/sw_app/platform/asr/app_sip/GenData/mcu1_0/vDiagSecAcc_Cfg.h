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
 *            Module: vDiagSecAcc
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vDiagSecAcc_Cfg.h
 *   Generation Time: 2024-02-13 13:07:47
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined (VDIAGSECACC_CFG_H)
#define VDIAGSECACC_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Csm.h"
#include "Dcm_Types.h"
/* PRQA S 0292 EOF */ /* MD_VDIAGSECACC_CHARACTER_REQUIRED_FOR_VCA */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef VDIAGSECACC_USE_DUMMY_STATEMENT
#define VDIAGSECACC_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VDIAGSECACC_DUMMY_STATEMENT
#define VDIAGSECACC_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VDIAGSECACC_DUMMY_STATEMENT_CONST
#define VDIAGSECACC_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VDIAGSECACC_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define VDIAGSECACC_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_ON /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef VDIAGSECACC_ATOMIC_VARIABLE_ACCESS
#define VDIAGSECACC_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef VDIAGSECACC_PROCESSOR_TDA4VE88
#define VDIAGSECACC_PROCESSOR_TDA4VE88
#endif
#ifndef VDIAGSECACC_COMP_LLVMTEXASINSTRUMENTS
#define VDIAGSECACC_COMP_LLVMTEXASINSTRUMENTS
#endif
#ifndef VDIAGSECACC_GEN_GENERATOR_MSR
#define VDIAGSECACC_GEN_GENERATOR_MSR
#endif
#ifndef VDIAGSECACC_CPUTYPE_BITORDER_LSB2MSB
#define VDIAGSECACC_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef VDIAGSECACC_CONFIGURATION_VARIANT_PRECOMPILE
#define VDIAGSECACC_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef VDIAGSECACC_CONFIGURATION_VARIANT_LINKTIME
#define VDIAGSECACC_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef VDIAGSECACC_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define VDIAGSECACC_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef VDIAGSECACC_CONFIGURATION_VARIANT
#define VDIAGSECACC_CONFIGURATION_VARIANT VDIAGSECACC_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef VDIAGSECACC_POSTBUILD_VARIANT_SUPPORT
#define VDIAGSECACC_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* Microsar Define Block for Boolean and Integers */
#define VDIAGSECACC_VERSION_INFO_API                                                                STD_OFF 

/* Symbolic Name Define Block */
#define vDiagSecAccConf_vDiagSecAccSecurityLevel_vDiagSecAccSecurityLevel                           0u 

#ifndef VDIAGSECACC_DEV_ERROR_DETECT
#define VDIAGSECACC_DEV_ERROR_DETECT STD_ON
#endif
#ifndef VDIAGSECACC_DEV_ERROR_REPORT
#define VDIAGSECACC_DEV_ERROR_REPORT STD_ON
#endif
#define VDIAGSECACC_CSM_ASYNC_RANDOM_GENERATE                                                       STD_OFF
#define VDIAGSECACC_CSM_ASYNC_COMPARE_KEY                                                           STD_OFF


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  vDiagSecAccPCDataSwitches  vDiagSecAcc Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define VDIAGSECACC_EXPECTEDCOMPATIBILITYVERSION                                                    STD_OFF  /**< Deactivateable: 'vDiagSecAcc_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VDIAGSECACC_FINALMAGICNUMBER                                                                STD_OFF  /**< Deactivateable: 'vDiagSecAcc_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define VDIAGSECACC_GENERATORCOMPATIBILITYVERSION                                                   STD_OFF  /**< Deactivateable: 'vDiagSecAcc_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VDIAGSECACC_INITDATAHASHCODE                                                                STD_OFF  /**< Deactivateable: 'vDiagSecAcc_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define VDIAGSECACC_RANDOMGENERATEJOBREFOFGENERAL                                                   STD_ON
#define VDIAGSECACC_SECURITYLEVEL                                                                   STD_ON
#define VDIAGSECACC_COMPAREKEYCSMJOBREFOFSECURITYLEVEL                                              STD_ON
#define VDIAGSECACC_KEYLENGTHOFSECURITYLEVEL                                                        STD_ON
#define VDIAGSECACC_SEEDBUFFERENDIDXOFSECURITYLEVEL                                                 STD_ON
#define VDIAGSECACC_SEEDBUFFERLENGTHOFSECURITYLEVEL                                                 STD_ON
#define VDIAGSECACC_SEEDBUFFERSTARTIDXOFSECURITYLEVEL                                               STD_ON
#define VDIAGSECACC_VDIAGSECACCCOMPAREKEYCSMJOBREFASYNCOFSECURITYLEVEL                              STD_ON
#define VDIAGSECACC_SEEDBUFFER                                                                      STD_ON
#define VDIAGSECACC_SIZEOFSECURITYLEVEL                                                             STD_ON
#define VDIAGSECACC_SIZEOFSEEDBUFFER                                                                STD_ON
#define VDIAGSECACC_VERSIONINFOAPIOFGENERAL                                                         STD_ON
#define VDIAGSECACC_PCCONFIG                                                                        STD_ON
#define VDIAGSECACC_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                          STD_OFF  /**< Deactivateable: 'vDiagSecAcc_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VDIAGSECACC_FINALMAGICNUMBEROFPCCONFIG                                                      STD_OFF  /**< Deactivateable: 'vDiagSecAcc_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define VDIAGSECACC_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                         STD_OFF  /**< Deactivateable: 'vDiagSecAcc_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VDIAGSECACC_INITDATAHASHCODEOFPCCONFIG                                                      STD_OFF  /**< Deactivateable: 'vDiagSecAcc_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define VDIAGSECACC_RANDOMGENERATEJOBREFOFGENERALOFPCCONFIG                                         STD_ON
#define VDIAGSECACC_SECURITYLEVELOFPCCONFIG                                                         STD_ON
#define VDIAGSECACC_SEEDBUFFEROFPCCONFIG                                                            STD_ON
#define VDIAGSECACC_SIZEOFSECURITYLEVELOFPCCONFIG                                                   STD_ON
#define VDIAGSECACC_SIZEOFSEEDBUFFEROFPCCONFIG                                                      STD_ON
#define VDIAGSECACC_VERSIONINFOAPIOFGENERALOFPCCONFIG                                               STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPCMinNumericValueDefines  vDiagSecAcc Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define VDIAGSECACC_MIN_SEEDBUFFER                                                                  0u
/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPCMaxNumericValueDefines  vDiagSecAcc Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define VDIAGSECACC_MAX_SEEDBUFFER                                                                  255u
/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPCNoReferenceDefines  vDiagSecAcc No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define VDIAGSECACC_NO_EXPECTEDCOMPATIBILITYVERSION                                                 65535u
/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPCIsReducedToDefineDefines  vDiagSecAcc Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define VDIAGSECACC_ISDEF_COMPAREKEYCSMJOBREFOFSECURITYLEVEL                                        STD_ON
#define VDIAGSECACC_ISDEF_KEYLENGTHOFSECURITYLEVEL                                                  STD_ON
#define VDIAGSECACC_ISDEF_SEEDBUFFERENDIDXOFSECURITYLEVEL                                           STD_ON
#define VDIAGSECACC_ISDEF_SEEDBUFFERLENGTHOFSECURITYLEVEL                                           STD_ON
#define VDIAGSECACC_ISDEF_SEEDBUFFERSTARTIDXOFSECURITYLEVEL                                         STD_ON
#define VDIAGSECACC_ISDEF_VDIAGSECACCCOMPAREKEYCSMJOBREFASYNCOFSECURITYLEVEL                        STD_ON
#define VDIAGSECACC_ISDEF_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                    STD_OFF
#define VDIAGSECACC_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                                STD_OFF
#define VDIAGSECACC_ISDEF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                   STD_OFF
#define VDIAGSECACC_ISDEF_INITDATAHASHCODEOFPCCONFIG                                                STD_OFF
#define VDIAGSECACC_ISDEF_SECURITYLEVELOFPCCONFIG                                                   STD_ON
#define VDIAGSECACC_ISDEF_SEEDBUFFEROFPCCONFIG                                                      STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPCEqualsAlwaysToDefines  vDiagSecAcc Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define VDIAGSECACC_EQ2_COMPAREKEYCSMJOBREFOFSECURITYLEVEL                                          CsmConf_CsmJob_CsmJob_SignatureVerify_ADA
#define VDIAGSECACC_EQ2_KEYLENGTHOFSECURITYLEVEL                                                    256u
#define VDIAGSECACC_EQ2_SEEDBUFFERENDIDXOFSECURITYLEVEL                                             32u
#define VDIAGSECACC_EQ2_SEEDBUFFERLENGTHOFSECURITYLEVEL                                             32u
#define VDIAGSECACC_EQ2_SEEDBUFFERSTARTIDXOFSECURITYLEVEL                                           0u
#define VDIAGSECACC_EQ2_VDIAGSECACCCOMPAREKEYCSMJOBREFASYNCOFSECURITYLEVEL                          FALSE
#define VDIAGSECACC_EQ2_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                      
#define VDIAGSECACC_EQ2_FINALMAGICNUMBEROFPCCONFIG                                                  
#define VDIAGSECACC_EQ2_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                     
#define VDIAGSECACC_EQ2_INITDATAHASHCODEOFPCCONFIG                                                  
#define VDIAGSECACC_EQ2_SECURITYLEVELOFPCCONFIG                                                     vDiagSecAcc_SecurityLevel
#define VDIAGSECACC_EQ2_SEEDBUFFEROFPCCONFIG                                                        vDiagSecAcc_SeedBuffer.raw
/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPCSymbolicInitializationPointers  vDiagSecAcc Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define vDiagSecAcc_Config_Ptr                                                                      NULL_PTR  /**< symbolic identifier which shall be used to initialize 'vDiagSecAcc' */
/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPCInitializationSymbols  vDiagSecAcc Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define vDiagSecAcc_Config                                                                          NULL_PTR  /**< symbolic identifier which could be used to initialize 'vDiagSecAcc */
/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPCGeneral  vDiagSecAcc General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define VDIAGSECACC_CHECK_INIT_POINTER                                                              STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define VDIAGSECACC_FINAL_MAGIC_NUMBER                                                              0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of vDiagSecAcc */
#define VDIAGSECACC_INDIVIDUAL_POSTBUILD                                                            STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'vDiagSecAcc' is not configured to be postbuild capable. */
#define VDIAGSECACC_INIT_DATA                                                                       VDIAGSECACC_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define VDIAGSECACC_INIT_DATA_HASH_CODE                                                             -835211787  /**< the precompile constant to validate the initialization structure at initialization time of vDiagSecAcc with a hashcode. The seed value is '0xFF1Eu' */
#define VDIAGSECACC_USE_ECUM_BSW_ERROR_HOOK                                                         STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define VDIAGSECACC_USE_INIT_POINTER                                                                STD_OFF  /**< STD_ON if the init pointer vDiagSecAcc shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  vDiagSecAccPBDataSwitches  vDiagSecAcc Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define VDIAGSECACC_PBCONFIG                                                                        STD_OFF  /**< Deactivateable: 'vDiagSecAcc_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define VDIAGSECACC_LTCONFIGIDXOFPBCONFIG                                                           STD_OFF  /**< Deactivateable: 'vDiagSecAcc_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define VDIAGSECACC_PCCONFIGIDXOFPBCONFIG                                                           STD_OFF  /**< Deactivateable: 'vDiagSecAcc_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPBIsReducedToDefineDefines  vDiagSecAcc Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define VDIAGSECACC_ISDEF_LTCONFIGIDXOFPBCONFIG                                                     STD_OFF
#define VDIAGSECACC_ISDEF_PCCONFIGIDXOFPBCONFIG                                                     STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPBEqualsAlwaysToDefines  vDiagSecAcc Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define VDIAGSECACC_EQ2_LTCONFIGIDXOFPBCONFIG                                                       
#define VDIAGSECACC_EQ2_PCCONFIGIDXOFPBCONFIG                                                       
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
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
  \defgroup  vDiagSecAccPCGetRootDataMacros  vDiagSecAcc Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define vDiagSecAcc_GetExpectedCompatibilityVersionOfPCConfig()                                       /**< Deactivateable: 'vDiagSecAcc_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vDiagSecAcc_GetFinalMagicNumberOfPCConfig()                                                   /**< Deactivateable: 'vDiagSecAcc_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vDiagSecAcc_GetGeneratorCompatibilityVersionOfPCConfig()                                      /**< Deactivateable: 'vDiagSecAcc_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vDiagSecAcc_GetInitDataHashCodeOfPCConfig()                                                   /**< Deactivateable: 'vDiagSecAcc_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPCGetConstantDuplicatedRootDataMacros  vDiagSecAcc Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define vDiagSecAcc_GetRandomGenerateJobRefOfGeneralOfPCConfig()                                    CsmConf_CsmJob_CsmJob_Random
#define vDiagSecAcc_GetSecurityLevelOfPCConfig()                                                    vDiagSecAcc_SecurityLevel  /**< the pointer to vDiagSecAcc_SecurityLevel */
#define vDiagSecAcc_GetSeedBufferOfPCConfig()                                                       vDiagSecAcc_SeedBuffer.raw  /**< the pointer to vDiagSecAcc_SeedBuffer */
#define vDiagSecAcc_GetSizeOfSecurityLevelOfPCConfig()                                              1u  /**< the number of accomplishable value elements in vDiagSecAcc_SecurityLevel */
#define vDiagSecAcc_GetSizeOfSeedBufferOfPCConfig()                                                 32u  /**< the number of accomplishable value elements in vDiagSecAcc_SeedBuffer */
#define vDiagSecAcc_IsVersionInfoApiOfGeneralOfPCConfig()                                           (((FALSE)) != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPCGetDataMacros  vDiagSecAcc Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define vDiagSecAcc_GetSeedBuffer(Index)                                                            (vDiagSecAcc_GetSeedBufferOfPCConfig()[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPCGetDeduplicatedDataMacros  vDiagSecAcc Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define vDiagSecAcc_GetExpectedCompatibilityVersion()                                                 /**< Deactivateable: 'vDiagSecAcc_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vDiagSecAcc_GetFinalMagicNumber()                                                             /**< Deactivateable: 'vDiagSecAcc_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vDiagSecAcc_GetGeneratorCompatibilityVersion()                                                /**< Deactivateable: 'vDiagSecAcc_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vDiagSecAcc_GetInitDataHashCode()                                                             /**< Deactivateable: 'vDiagSecAcc_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define vDiagSecAcc_GetRandomGenerateJobRefOfGeneral()                                              vDiagSecAcc_GetRandomGenerateJobRefOfGeneralOfPCConfig()
#define vDiagSecAcc_GetCompareKeyCsmJobRefOfSecurityLevel(Index)                                    CsmConf_CsmJob_CsmJob_SignatureVerify_ADA  /**< Contains values of DefinitionRef: /MICROSAR/vDiagSecAcc/vDiagSecAccSecurityLevels/vDiagSecAccSecurityLevel/vDiagSecAccCompareKeyCsmJobRef. */
#define vDiagSecAcc_GetKeyLengthOfSecurityLevel(Index)                                              256u  /**< Contains values of DefinitionRef: /MICROSAR/vDiagSecAcc/vDiagSecAccSecurityLevels/vDiagSecAccSecurityLevel/vDiagSecAccKeyLength. */
#define vDiagSecAcc_GetSeedBufferEndIdxOfSecurityLevel(Index)                                       32u  /**< the end index of the 1:n relation pointing to vDiagSecAcc_SeedBuffer */
#define vDiagSecAcc_GetSeedBufferLengthOfSecurityLevel(Index)                                       32u  /**< the number of relations pointing to vDiagSecAcc_SeedBuffer */
#define vDiagSecAcc_GetSeedBufferStartIdxOfSecurityLevel(Index)                                     0u  /**< the start index of the 1:n relation pointing to vDiagSecAcc_SeedBuffer */
#define vDiagSecAcc_IsvDiagSecAccCompareKeyCsmJobRefAsyncOfSecurityLevel(Index)                     (((FALSE)) != FALSE)
#define vDiagSecAcc_GetSizeOfSecurityLevel()                                                        vDiagSecAcc_GetSizeOfSecurityLevelOfPCConfig()
#define vDiagSecAcc_GetSizeOfSeedBuffer()                                                           vDiagSecAcc_GetSizeOfSeedBufferOfPCConfig()
#define vDiagSecAcc_IsVersionInfoApiOfGeneral()                                                     vDiagSecAcc_IsVersionInfoApiOfGeneralOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPCSetDataMacros  vDiagSecAcc Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define vDiagSecAcc_SetSeedBuffer(Index, Value)                                                     vDiagSecAcc_GetSeedBufferOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPCGetAddressOfDataMacros  vDiagSecAcc Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define vDiagSecAcc_GetAddrSeedBuffer(Index)                                                        (&vDiagSecAcc_GetSeedBuffer(Index))
/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPCHasMacros  vDiagSecAcc Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define vDiagSecAcc_HasExpectedCompatibilityVersion()                                                 /**< Deactivateable: 'vDiagSecAcc_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vDiagSecAcc_HasFinalMagicNumber()                                                             /**< Deactivateable: 'vDiagSecAcc_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vDiagSecAcc_HasGeneratorCompatibilityVersion()                                                /**< Deactivateable: 'vDiagSecAcc_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vDiagSecAcc_HasInitDataHashCode()                                                             /**< Deactivateable: 'vDiagSecAcc_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define vDiagSecAcc_HasRandomGenerateJobRefOfGeneral()                                              (TRUE != FALSE)
#define vDiagSecAcc_HasSecurityLevel()                                                              (TRUE != FALSE)
#define vDiagSecAcc_HasCompareKeyCsmJobRefOfSecurityLevel()                                         (TRUE != FALSE)
#define vDiagSecAcc_HasKeyLengthOfSecurityLevel()                                                   (TRUE != FALSE)
#define vDiagSecAcc_HasSeedBufferEndIdxOfSecurityLevel()                                            (TRUE != FALSE)
#define vDiagSecAcc_HasSeedBufferLengthOfSecurityLevel()                                            (TRUE != FALSE)
#define vDiagSecAcc_HasSeedBufferStartIdxOfSecurityLevel()                                          (TRUE != FALSE)
#define vDiagSecAcc_HasvDiagSecAccCompareKeyCsmJobRefAsyncOfSecurityLevel()                         (TRUE != FALSE)
#define vDiagSecAcc_HasSeedBuffer()                                                                 (TRUE != FALSE)
#define vDiagSecAcc_HasSizeOfSecurityLevel()                                                        (TRUE != FALSE)
#define vDiagSecAcc_HasSizeOfSeedBuffer()                                                           (TRUE != FALSE)
#define vDiagSecAcc_HasVersionInfoApiOfGeneral()                                                    (TRUE != FALSE)
#define vDiagSecAcc_HasPCConfig()                                                                   (TRUE != FALSE)
#define vDiagSecAcc_HasExpectedCompatibilityVersionOfPCConfig()                                       /**< Deactivateable: 'vDiagSecAcc_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vDiagSecAcc_HasFinalMagicNumberOfPCConfig()                                                   /**< Deactivateable: 'vDiagSecAcc_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vDiagSecAcc_HasGeneratorCompatibilityVersionOfPCConfig()                                      /**< Deactivateable: 'vDiagSecAcc_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vDiagSecAcc_HasInitDataHashCodeOfPCConfig()                                                   /**< Deactivateable: 'vDiagSecAcc_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define vDiagSecAcc_HasRandomGenerateJobRefOfGeneralOfPCConfig()                                    (TRUE != FALSE)
#define vDiagSecAcc_HasSecurityLevelOfPCConfig()                                                    (TRUE != FALSE)
#define vDiagSecAcc_HasSeedBufferOfPCConfig()                                                       (TRUE != FALSE)
#define vDiagSecAcc_HasSizeOfSecurityLevelOfPCConfig()                                              (TRUE != FALSE)
#define vDiagSecAcc_HasSizeOfSeedBufferOfPCConfig()                                                 (TRUE != FALSE)
#define vDiagSecAcc_HasVersionInfoApiOfGeneralOfPCConfig()                                          (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPCIncrementDataMacros  vDiagSecAcc Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define vDiagSecAcc_IncSeedBuffer(Index)                                                            vDiagSecAcc_GetSeedBuffer(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPCDecrementDataMacros  vDiagSecAcc Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define vDiagSecAcc_DecSeedBuffer(Index)                                                            vDiagSecAcc_GetSeedBuffer(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPCAddDataMacros  vDiagSecAcc Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define vDiagSecAcc_AddSeedBuffer(Index, Value)                                                     vDiagSecAcc_SetSeedBuffer(Index, (vDiagSecAcc_GetSeedBuffer(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPCSubstractDataMacros  vDiagSecAcc Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define vDiagSecAcc_SubSeedBuffer(Index, Value)                                                     vDiagSecAcc_SetSeedBuffer(Index, (vDiagSecAcc_GetSeedBuffer(Index) - Value))
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
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  vDiagSecAccPBGetRootDataMacros  vDiagSecAcc Get Root Data Macros (POST_BUILD)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define vDiagSecAcc_GetLTConfigIdxOfPBConfig()                                                        /**< Deactivateable: 'vDiagSecAcc_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define vDiagSecAcc_GetPCConfigIdxOfPBConfig()                                                        /**< Deactivateable: 'vDiagSecAcc_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPBHasMacros  vDiagSecAcc Has Macros (POST_BUILD)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define vDiagSecAcc_HasPBConfig()                                                                     /**< Deactivateable: 'vDiagSecAcc_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define vDiagSecAcc_HasLTConfigIdxOfPBConfig()                                                        /**< Deactivateable: 'vDiagSecAcc_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define vDiagSecAcc_HasPCConfigIdxOfPBConfig()                                                        /**< Deactivateable: 'vDiagSecAcc_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


#define VDIAGSECACC_COMPAREKEY_L0X000B STD_ON 
#define VDIAGSECACC_GETSEED_L0X000B    STD_ON 




/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vDiagSecAccPCIterableTypes  vDiagSecAcc Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate vDiagSecAcc_SecurityLevel */
/*! \spec strong type invariant () { self < vDiagSecAcc_GetSizeOfSecurityLevel() } \endspec */ 
typedef uint8_least vDiagSecAcc_SecurityLevelIterType;

/**   \brief  type used to iterate vDiagSecAcc_SeedBuffer */
/*! \spec strong type invariant () { self < vDiagSecAcc_GetSizeOfSeedBuffer() } \endspec */ 
typedef uint8_least vDiagSecAcc_SeedBufferIterType;

/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPCValueTypes  vDiagSecAcc Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for vDiagSecAcc_RandomGenerateJobRefOfGeneral */
typedef uint32 vDiagSecAcc_RandomGenerateJobRefOfGeneralType;

/**   \brief  value based type definition for vDiagSecAcc_CompareKeyCsmJobRefOfSecurityLevel */
typedef uint32 vDiagSecAcc_CompareKeyCsmJobRefOfSecurityLevelType;

/**   \brief  value based type definition for vDiagSecAcc_KeyLengthOfSecurityLevel */
typedef uint16 vDiagSecAcc_KeyLengthOfSecurityLevelType;

/**   \brief  value based type definition for vDiagSecAcc_SeedBufferEndIdxOfSecurityLevel */
/*! \spec strong type invariant () { self < vDiagSecAcc_GetSizeOfSeedBuffer() } \endspec */ 
typedef uint8 vDiagSecAcc_SeedBufferEndIdxOfSecurityLevelType;

/**   \brief  value based type definition for vDiagSecAcc_SeedBufferLengthOfSecurityLevel */
typedef uint8 vDiagSecAcc_SeedBufferLengthOfSecurityLevelType;

/**   \brief  value based type definition for vDiagSecAcc_SeedBufferStartIdxOfSecurityLevel */
/*! \spec strong type invariant () { self < vDiagSecAcc_GetSizeOfSeedBuffer() } \endspec */ 
typedef uint8 vDiagSecAcc_SeedBufferStartIdxOfSecurityLevelType;

/**   \brief  value based type definition for vDiagSecAcc_vDiagSecAccCompareKeyCsmJobRefAsyncOfSecurityLevel */
typedef boolean vDiagSecAcc_vDiagSecAccCompareKeyCsmJobRefAsyncOfSecurityLevelType;

/**   \brief  value based type definition for vDiagSecAcc_SeedBuffer */
typedef uint8 vDiagSecAcc_SeedBufferType;

/**   \brief  value based type definition for vDiagSecAcc_SizeOfSecurityLevel */
typedef uint8 vDiagSecAcc_SizeOfSecurityLevelType;

/**   \brief  value based type definition for vDiagSecAcc_SizeOfSeedBuffer */
typedef uint8 vDiagSecAcc_SizeOfSeedBufferType;

/**   \brief  value based type definition for vDiagSecAcc_VersionInfoApiOfGeneral */
typedef boolean vDiagSecAcc_VersionInfoApiOfGeneralType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vDiagSecAccPCStructTypes  vDiagSecAcc Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in vDiagSecAcc_SecurityLevel */
typedef struct svDiagSecAcc_SecurityLevelType
{
  uint8 vDiagSecAcc_SecurityLevelNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} vDiagSecAcc_SecurityLevelType;

/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPCSymbolicStructTypes  vDiagSecAcc Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to vDiagSecAcc_SeedBuffer */
typedef struct vDiagSecAcc_SeedBufferStructSTag
{
  vDiagSecAcc_SeedBufferType vDiagSecAccSecurityLevel[32];
} vDiagSecAcc_SeedBufferStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPCUnionIndexAndSymbolTypes  vDiagSecAcc Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access vDiagSecAcc_SeedBuffer in an index and symbol based style. */
typedef union vDiagSecAcc_SeedBufferUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  vDiagSecAcc_SeedBufferType raw[32];
  vDiagSecAcc_SeedBufferStructSType str;
} vDiagSecAcc_SeedBufferUType;

/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPCRootPointerTypes  vDiagSecAcc Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to vDiagSecAcc_SecurityLevel */
typedef P2CONST(vDiagSecAcc_SecurityLevelType, TYPEDEF, VDIAGSECACC_CONST) vDiagSecAcc_SecurityLevelPtrType;

/**   \brief  type used to point to vDiagSecAcc_SeedBuffer */
typedef P2VAR(vDiagSecAcc_SeedBufferType, TYPEDEF, VDIAGSECACC_VAR_NOINIT) vDiagSecAcc_SeedBufferPtrType;

/**   \brief  type used to point to vDiagSecAcc_RandomGenerateJobRefOfGeneralOfPCConfig */
typedef P2CONST(vDiagSecAcc_RandomGenerateJobRefOfGeneralType, TYPEDEF, VDIAGSECACC_CONST) vDiagSecAcc_RandomGenerateJobRefOfGeneralOfPCConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  vDiagSecAccPCRootValueTypes  vDiagSecAcc Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in vDiagSecAcc_PCConfig */
typedef struct svDiagSecAcc_PCConfigType
{
  uint8 vDiagSecAcc_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} vDiagSecAcc_PCConfigType;

typedef vDiagSecAcc_PCConfigType vDiagSecAcc_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vDiagSecAccPBValueTypes  vDiagSecAcc Value Types (POST_BUILD)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vDiagSecAccPBRootValueTypes  vDiagSecAcc Root Value Types (POST_BUILD)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  vDiagSecAcc_SeedBuffer
**********************************************************************************************************************/
#define VDIAGSECACC_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "vDiagSecAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(vDiagSecAcc_SeedBufferUType, VDIAGSECACC_VAR_NOINIT) vDiagSecAcc_SeedBuffer;  /* PRQA S 0759 */  /* MD_CSL_Union */  /* 31 */
#define VDIAGSECACC_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "vDiagSecAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/

 
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


#define VDIAGSECACC_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "vDiagSecAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
 *  SecurityLevel: 0x000B vDiagSecAcc_CompareKey_L0x000B
 *********************************************************************************************************************/
/*!
 * \fn          vDiagSecAcc_CompareKey_L0x000B
 * \brief       Functions of this group execute a comparison of a received key to the former send seed for a fixed
 *              level.
 * \param[in]   Key        Pointer to key buffer which shall be compared.
 * \param[in]   OpStatus   Current operation status
 * \param[out]  ErrorCode  Pointer to store the ERROR code which will be returned to tester in case of failure.
 * \return      E_OK      Comparison successful
 * \return      E_NOT_OK  Comparison failed, details passed in ErrorCode.
 * \pre         GetSeed was called before. Key need to be a valid pointer with at least the length of 256 bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \spec
 *              requires Key != NULL_PTR;
 *              requires $lengthOf(Key) >= 256;
 *              requires ErrorCode != NULL_PTR;
 *              requires $lengthOf(ErrorCode) >= 1;
 * \endspec
 */
extern FUNC(Std_ReturnType, VDIAGSECACC_CODE) vDiagSecAcc_CompareKey_L0x000B(P2CONST(uint8, AUTOMATIC, VDIAGSECACC_DCM_VAR) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, VDIAGSECACC_DCM_VAR) ErrorCode);

/**********************************************************************************************************************
 *  SecurityLevel: 0x000B vDiagSecAcc_GetSeed_L0x000B
 *********************************************************************************************************************/
/*!
 * \fn          vDiagSecAcc_GetSeed_L0x000B
 * \brief       Function to generate a seed for a specific level
 * \param[in]   OpStatus   Current operation status
 * \param[out]  Seed       Pointer to a buffer where generated seed shall be stored.
 * \param[out]  ErrorCode  Pointer to store the ERROR code which will be returned to tester in case of failure.
 * \return      E_OK      Generating seed was successful
 * \return      E_NOT_OK  Generating seed failed, details passed in ErrorCode.
 * \pre         Seed need to be a valid pointer with at least the length of 32 bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \spec
 *              requires Seed != NULL_PTR;
 *              requires $lengthOf(Seed) >= 32;
 *              requires ErrorCode != NULL_PTR;
 *              requires $lengthOf(ErrorCode) >= 1;
 * \endspec
 */
extern FUNC(Std_ReturnType, VDIAGSECACC_CODE) vDiagSecAcc_GetSeed_L0x000B(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, VDIAGSECACC_DCM_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, VDIAGSECACC_DCM_VAR) ErrorCode);
#define VDIAGSECACC_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "vDiagSecAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */




#if !defined (VDIAGSECACC_NOUNIT_CSLUNIT)
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/

#endif



#endif /* VDIAGSECACC_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: vDiagSecAcc_Cfg.h
 *********************************************************************************************************************/

