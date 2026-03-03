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
 *            Module: vDam
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vDam_Cfg.h
 *   Generation Time: 2025-03-05 18:52:34
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined (VDAM_CFG_H)
#define VDAM_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dcm_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef VDAM_USE_DUMMY_STATEMENT
#define VDAM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VDAM_DUMMY_STATEMENT
#define VDAM_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VDAM_DUMMY_STATEMENT_CONST
#define VDAM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VDAM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define VDAM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_ON /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef VDAM_ATOMIC_VARIABLE_ACCESS
#define VDAM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef VDAM_PROCESSOR_TDA4VE88
#define VDAM_PROCESSOR_TDA4VE88
#endif
#ifndef VDAM_COMP_LLVMTEXASINSTRUMENTS
#define VDAM_COMP_LLVMTEXASINSTRUMENTS
#endif
#ifndef VDAM_GEN_GENERATOR_MSR
#define VDAM_GEN_GENERATOR_MSR
#endif
#ifndef VDAM_CPUTYPE_BITORDER_LSB2MSB
#define VDAM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef VDAM_CONFIGURATION_VARIANT_PRECOMPILE
#define VDAM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef VDAM_CONFIGURATION_VARIANT_LINKTIME
#define VDAM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef VDAM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define VDAM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef VDAM_CONFIGURATION_VARIANT
#define VDAM_CONFIGURATION_VARIANT VDAM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef VDAM_POSTBUILD_VARIANT_SUPPORT
#define VDAM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* Microsar Define Block for Boolean and Integers */
#define VDAM_VERSION_INFO_API                                                                       STD_OFF 
#define VDAM_SAFE_BSW_CHECKS                                                                        STD_ON 
#define VDAM_USER_ROLE_CALLOUT                                                                      STD_ON 

#define VDAM_ALLOW_NOT_CONFIGURED                                                                   0x00u 
#define VDAM_ALLOW_NOT_CONFIGURED_SERVICE                                                           0x01u 
#define VDAM_DENY_NOT_CONFIGURED                                                                    0x02u 

#ifndef VDAM_DEV_ERROR_DETECT
#define VDAM_DEV_ERROR_DETECT STD_ON
#endif
#ifndef VDAM_DEV_ERROR_REPORT
#define VDAM_DEV_ERROR_REPORT STD_ON
#endif


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  vDamPCDataSwitches  vDam Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define VDAM_CUSTOMREMAPNRCCALLOUTFUNCOFGENERAL                                                     STD_ON
#define VDAM_EXPECTEDCOMPATIBILITYVERSION                                                           STD_OFF  /**< Deactivateable: 'vDam_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VDAM_FINALMAGICNUMBER                                                                       STD_OFF  /**< Deactivateable: 'vDam_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define VDAM_FUNCOFUSERROLECALLOUT                                                                  STD_ON
#define VDAM_GENERATORCOMPATIBILITYVERSION                                                          STD_OFF  /**< Deactivateable: 'vDam_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VDAM_IDENTIFIERINFO                                                                         STD_ON
#define VDAM_IDENTIFIERIDOFIDENTIFIERINFO                                                           STD_ON
#define VDAM_IDENTIFIERROLESOFIDENTIFIERINFO                                                        STD_ON
#define VDAM_INITDATAHASHCODE                                                                       STD_OFF  /**< Deactivateable: 'vDam_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define VDAM_SAFEBSWCHECKSOFGENERAL                                                                 STD_ON
#define VDAM_SERVICECONFIGURATIONSTRATEGYOFGENERAL                                                  STD_ON
#define VDAM_SERVICEINFO                                                                            STD_ON
#define VDAM_SERVICEIDOFSERVICEINFO                                                                 STD_ON
#define VDAM_SERVICEROLESOFSERVICEINFO                                                              STD_ON
#define VDAM_SERVICEROLESVALIDOFSERVICEINFO                                                         STD_ON
#define VDAM_SUBSERVICEINFOENDIDXOFSERVICEINFO                                                      STD_ON
#define VDAM_SUBSERVICEINFOSTARTIDXOFSERVICEINFO                                                    STD_ON
#define VDAM_SUBSERVICEINFOUSEDOFSERVICEINFO                                                        STD_ON
#define VDAM_SIZEOFIDENTIFIERINFO                                                                   STD_ON
#define VDAM_SIZEOFSERVICEINFO                                                                      STD_ON
#define VDAM_SIZEOFSUBSERVICEINFO                                                                   STD_ON
#define VDAM_SUBSERVICEINFO                                                                         STD_ON
#define VDAM_IDENTIFIERINFOENDIDXOFSUBSERVICEINFO                                                   STD_ON
#define VDAM_IDENTIFIERINFOSTARTIDXOFSUBSERVICEINFO                                                 STD_ON
#define VDAM_IDENTIFIERINFOUSEDOFSUBSERVICEINFO                                                     STD_ON
#define VDAM_SUBSERVICEIDOFSUBSERVICEINFO                                                           STD_ON
#define VDAM_SUBSERVICEROLESOFSUBSERVICEINFO                                                        STD_ON
#define VDAM_SUBSERVICEROLESVALIDOFSUBSERVICEINFO                                                   STD_ON
#define VDAM_VERSIONINFOAPIOFGENERAL                                                                STD_ON
#define VDAM_PCCONFIG                                                                               STD_ON
#define VDAM_CUSTOMREMAPNRCCALLOUTFUNCOFGENERALOFPCCONFIG                                           STD_ON
#define VDAM_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                                 STD_OFF  /**< Deactivateable: 'vDam_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VDAM_FINALMAGICNUMBEROFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'vDam_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define VDAM_FUNCOFUSERROLECALLOUTOFPCCONFIG                                                        STD_ON
#define VDAM_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                                STD_OFF  /**< Deactivateable: 'vDam_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VDAM_IDENTIFIERINFOOFPCCONFIG                                                               STD_ON
#define VDAM_INITDATAHASHCODEOFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'vDam_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define VDAM_SAFEBSWCHECKSOFGENERALOFPCCONFIG                                                       STD_ON
#define VDAM_SERVICECONFIGURATIONSTRATEGYOFGENERALOFPCCONFIG                                        STD_ON
#define VDAM_SERVICEINFOOFPCCONFIG                                                                  STD_ON
#define VDAM_SIZEOFIDENTIFIERINFOOFPCCONFIG                                                         STD_ON
#define VDAM_SIZEOFSERVICEINFOOFPCCONFIG                                                            STD_ON
#define VDAM_SIZEOFSUBSERVICEINFOOFPCCONFIG                                                         STD_ON
#define VDAM_SUBSERVICEINFOOFPCCONFIG                                                               STD_ON
#define VDAM_VERSIONINFOAPIOFGENERALOFPCCONFIG                                                      STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  vDamPCNoReferenceDefines  vDam No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define VDAM_NO_SUBSERVICEINFOENDIDXOFSERVICEINFO                                                   255u
#define VDAM_NO_SUBSERVICEINFOSTARTIDXOFSERVICEINFO                                                 255u
#define VDAM_NO_IDENTIFIERINFOENDIDXOFSUBSERVICEINFO                                                255u
#define VDAM_NO_IDENTIFIERINFOSTARTIDXOFSUBSERVICEINFO                                              255u
#define VDAM_NO_EXPECTEDCOMPATIBILITYVERSION                                                        65535u
/** 
  \}
*/ 

/** 
  \defgroup  vDamPCIsReducedToDefineDefines  vDam Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define VDAM_ISDEF_IDENTIFIERIDOFIDENTIFIERINFO                                                     STD_OFF
#define VDAM_ISDEF_IDENTIFIERROLESOFIDENTIFIERINFO                                                  STD_OFF
#define VDAM_ISDEF_SERVICEIDOFSERVICEINFO                                                           STD_OFF
#define VDAM_ISDEF_SERVICEROLESOFSERVICEINFO                                                        STD_OFF
#define VDAM_ISDEF_SERVICEROLESVALIDOFSERVICEINFO                                                   STD_OFF
#define VDAM_ISDEF_SUBSERVICEINFOENDIDXOFSERVICEINFO                                                STD_OFF
#define VDAM_ISDEF_SUBSERVICEINFOSTARTIDXOFSERVICEINFO                                              STD_OFF
#define VDAM_ISDEF_SUBSERVICEINFOUSEDOFSERVICEINFO                                                  STD_OFF
#define VDAM_ISDEF_IDENTIFIERINFOENDIDXOFSUBSERVICEINFO                                             STD_OFF
#define VDAM_ISDEF_IDENTIFIERINFOSTARTIDXOFSUBSERVICEINFO                                           STD_OFF
#define VDAM_ISDEF_IDENTIFIERINFOUSEDOFSUBSERVICEINFO                                               STD_OFF
#define VDAM_ISDEF_SUBSERVICEIDOFSUBSERVICEINFO                                                     STD_OFF
#define VDAM_ISDEF_SUBSERVICEROLESOFSUBSERVICEINFO                                                  STD_OFF
#define VDAM_ISDEF_SUBSERVICEROLESVALIDOFSUBSERVICEINFO                                             STD_OFF
#define VDAM_ISDEF_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                           STD_OFF
#define VDAM_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                                       STD_OFF
#define VDAM_ISDEF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                          STD_OFF
#define VDAM_ISDEF_IDENTIFIERINFOOFPCCONFIG                                                         STD_ON
#define VDAM_ISDEF_INITDATAHASHCODEOFPCCONFIG                                                       STD_OFF
#define VDAM_ISDEF_SERVICEINFOOFPCCONFIG                                                            STD_ON
#define VDAM_ISDEF_SUBSERVICEINFOOFPCCONFIG                                                         STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  vDamPCEqualsAlwaysToDefines  vDam Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define VDAM_EQ2_IDENTIFIERIDOFIDENTIFIERINFO                                                       
#define VDAM_EQ2_IDENTIFIERROLESOFIDENTIFIERINFO                                                    
#define VDAM_EQ2_SERVICEIDOFSERVICEINFO                                                             
#define VDAM_EQ2_SERVICEROLESOFSERVICEINFO                                                          
#define VDAM_EQ2_SERVICEROLESVALIDOFSERVICEINFO                                                     
#define VDAM_EQ2_SUBSERVICEINFOENDIDXOFSERVICEINFO                                                  
#define VDAM_EQ2_SUBSERVICEINFOSTARTIDXOFSERVICEINFO                                                
#define VDAM_EQ2_SUBSERVICEINFOUSEDOFSERVICEINFO                                                    
#define VDAM_EQ2_IDENTIFIERINFOENDIDXOFSUBSERVICEINFO                                               
#define VDAM_EQ2_IDENTIFIERINFOSTARTIDXOFSUBSERVICEINFO                                             
#define VDAM_EQ2_IDENTIFIERINFOUSEDOFSUBSERVICEINFO                                                 
#define VDAM_EQ2_SUBSERVICEIDOFSUBSERVICEINFO                                                       
#define VDAM_EQ2_SUBSERVICEROLESOFSUBSERVICEINFO                                                    
#define VDAM_EQ2_SUBSERVICEROLESVALIDOFSUBSERVICEINFO                                               
#define VDAM_EQ2_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                             
#define VDAM_EQ2_FINALMAGICNUMBEROFPCCONFIG                                                         
#define VDAM_EQ2_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                            
#define VDAM_EQ2_IDENTIFIERINFOOFPCCONFIG                                                           vDam_IdentifierInfo
#define VDAM_EQ2_INITDATAHASHCODEOFPCCONFIG                                                         
#define VDAM_EQ2_SERVICEINFOOFPCCONFIG                                                              vDam_ServiceInfo
#define VDAM_EQ2_SUBSERVICEINFOOFPCCONFIG                                                           vDam_SubServiceInfo
/** 
  \}
*/ 

/** 
  \defgroup  vDamPCSymbolicInitializationPointers  vDam Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define vDam_Config_Ptr                                                                             NULL_PTR  /**< symbolic identifier which shall be used to initialize 'vDam' */
/** 
  \}
*/ 

/** 
  \defgroup  vDamPCInitializationSymbols  vDam Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define vDam_Config                                                                                 NULL_PTR  /**< symbolic identifier which could be used to initialize 'vDam */
/** 
  \}
*/ 

/** 
  \defgroup  vDamPCGeneral  vDam General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define VDAM_CHECK_INIT_POINTER                                                                     STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define VDAM_FINAL_MAGIC_NUMBER                                                                     0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of vDam */
#define VDAM_INDIVIDUAL_POSTBUILD                                                                   STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'vDam' is not configured to be postbuild capable. */
#define VDAM_INIT_DATA                                                                              VDAM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define VDAM_INIT_DATA_HASH_CODE                                                                    1893483745  /**< the precompile constant to validate the initialization structure at initialization time of vDam with a hashcode. The seed value is '0xFF1Eu' */
#define VDAM_USE_ECUM_BSW_ERROR_HOOK                                                                STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define VDAM_USE_INIT_POINTER                                                                       STD_OFF  /**< STD_ON if the init pointer vDam shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  vDamPBDataSwitches  vDam Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define VDAM_PBCONFIG                                                                               STD_OFF  /**< Deactivateable: 'vDam_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define VDAM_LTCONFIGIDXOFPBCONFIG                                                                  STD_OFF  /**< Deactivateable: 'vDam_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define VDAM_PCCONFIGIDXOFPBCONFIG                                                                  STD_OFF  /**< Deactivateable: 'vDam_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  vDamPBIsReducedToDefineDefines  vDam Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define VDAM_ISDEF_LTCONFIGIDXOFPBCONFIG                                                            STD_OFF
#define VDAM_ISDEF_PCCONFIGIDXOFPBCONFIG                                                            STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  vDamPBEqualsAlwaysToDefines  vDam Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define VDAM_EQ2_LTCONFIGIDXOFPBCONFIG                                                              
#define VDAM_EQ2_PCCONFIGIDXOFPBCONFIG                                                              
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
  \defgroup  vDamPCGetRootDataMacros  vDam Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define vDam_GetExpectedCompatibilityVersionOfPCConfig()                                              /**< Deactivateable: 'vDam_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vDam_GetFinalMagicNumberOfPCConfig()                                                          /**< Deactivateable: 'vDam_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vDam_GetGeneratorCompatibilityVersionOfPCConfig()                                             /**< Deactivateable: 'vDam_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vDam_GetInitDataHashCodeOfPCConfig()                                                          /**< Deactivateable: 'vDam_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
/** 
  \}
*/ 

/** 
  \defgroup  vDamPCGetConstantDuplicatedRootDataMacros  vDam Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define vDam_GetCustomRemapNrcCalloutFuncOfGeneralOfPCConfig()                                      Os_Call_Appl_vDamRemapNrcCalloutFunc
#define vDam_GetFuncOfUserRoleCalloutOfPCConfig()                                                   Appl_vDamUserRoleCalloutFunc
#define vDam_GetIdentifierInfoOfPCConfig()                                                          vDam_IdentifierInfo  /**< the pointer to vDam_IdentifierInfo */
#define vDam_IsSafeBswChecksOfGeneralOfPCConfig()                                                   (((TRUE)) != FALSE)
#define vDam_GetServiceConfigurationStrategyOfGeneralOfPCConfig()                                   VDAM_ALLOW_NOT_CONFIGURED
#define vDam_GetServiceInfoOfPCConfig()                                                             vDam_ServiceInfo  /**< the pointer to vDam_ServiceInfo */
#define vDam_GetSizeOfIdentifierInfoOfPCConfig()                                                    177u  /**< the number of accomplishable value elements in vDam_IdentifierInfo */
#define vDam_GetSizeOfServiceInfoOfPCConfig()                                                       8u  /**< the number of accomplishable value elements in vDam_ServiceInfo */
#define vDam_GetSizeOfSubServiceInfoOfPCConfig()                                                    6u  /**< the number of accomplishable value elements in vDam_SubServiceInfo */
#define vDam_GetSubServiceInfoOfPCConfig()                                                          vDam_SubServiceInfo  /**< the pointer to vDam_SubServiceInfo */
#define vDam_IsVersionInfoApiOfGeneralOfPCConfig()                                                  (((FALSE)) != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  vDamPCGetDataMacros  vDam Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define vDam_GetIdentifierIdOfIdentifierInfo(Index)                                                 (vDam_GetIdentifierInfoOfPCConfig()[(Index)].IdentifierIdOfIdentifierInfo)
#define vDam_GetIdentifierRolesOfIdentifierInfo(Index)                                              (vDam_GetIdentifierInfoOfPCConfig()[(Index)].IdentifierRolesOfIdentifierInfo)
#define vDam_GetServiceIdOfServiceInfo(Index)                                                       (vDam_GetServiceInfoOfPCConfig()[(Index)].ServiceIdOfServiceInfo)
#define vDam_GetServiceRolesOfServiceInfo(Index)                                                    (vDam_GetServiceInfoOfPCConfig()[(Index)].ServiceRolesOfServiceInfo)
#define vDam_IsServiceRolesValidOfServiceInfo(Index)                                                ((vDam_GetServiceInfoOfPCConfig()[(Index)].ServiceRolesValidOfServiceInfo) != FALSE)
#define vDam_GetSubServiceInfoEndIdxOfServiceInfo(Index)                                            (vDam_GetServiceInfoOfPCConfig()[(Index)].SubServiceInfoEndIdxOfServiceInfo)
#define vDam_GetSubServiceInfoStartIdxOfServiceInfo(Index)                                          (vDam_GetServiceInfoOfPCConfig()[(Index)].SubServiceInfoStartIdxOfServiceInfo)
#define vDam_GetIdentifierInfoEndIdxOfSubServiceInfo(Index)                                         (vDam_GetSubServiceInfoOfPCConfig()[(Index)].IdentifierInfoEndIdxOfSubServiceInfo)
#define vDam_GetIdentifierInfoStartIdxOfSubServiceInfo(Index)                                       (vDam_GetSubServiceInfoOfPCConfig()[(Index)].IdentifierInfoStartIdxOfSubServiceInfo)
#define vDam_GetSubServiceIdOfSubServiceInfo(Index)                                                 (vDam_GetSubServiceInfoOfPCConfig()[(Index)].SubServiceIdOfSubServiceInfo)
#define vDam_GetSubServiceRolesOfSubServiceInfo(Index)                                              (vDam_GetSubServiceInfoOfPCConfig()[(Index)].SubServiceRolesOfSubServiceInfo)
#define vDam_IsSubServiceRolesValidOfSubServiceInfo(Index)                                          ((vDam_GetSubServiceInfoOfPCConfig()[(Index)].SubServiceRolesValidOfSubServiceInfo) != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  vDamPCGetDeduplicatedDataMacros  vDam Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define vDam_GetCustomRemapNrcCalloutFuncOfGeneral()                                                vDam_GetCustomRemapNrcCalloutFuncOfGeneralOfPCConfig()
#define vDam_GetExpectedCompatibilityVersion()                                                        /**< Deactivateable: 'vDam_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vDam_GetFinalMagicNumber()                                                                    /**< Deactivateable: 'vDam_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vDam_GetFuncOfUserRoleCallout()                                                             vDam_GetFuncOfUserRoleCalloutOfPCConfig()
#define vDam_GetGeneratorCompatibilityVersion()                                                       /**< Deactivateable: 'vDam_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vDam_GetInitDataHashCode()                                                                    /**< Deactivateable: 'vDam_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define vDam_IsSafeBswChecksOfGeneral()                                                             vDam_IsSafeBswChecksOfGeneralOfPCConfig()
#define vDam_GetServiceConfigurationStrategyOfGeneral()                                             vDam_GetServiceConfigurationStrategyOfGeneralOfPCConfig()
#define vDam_IsSubServiceInfoUsedOfServiceInfo(Index)                                               (((boolean)(vDam_GetSubServiceInfoStartIdxOfServiceInfo(Index) != VDAM_NO_SUBSERVICEINFOSTARTIDXOFSERVICEINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to vDam_SubServiceInfo */
#define vDam_GetSizeOfIdentifierInfo()                                                              vDam_GetSizeOfIdentifierInfoOfPCConfig()
#define vDam_GetSizeOfServiceInfo()                                                                 vDam_GetSizeOfServiceInfoOfPCConfig()
#define vDam_GetSizeOfSubServiceInfo()                                                              vDam_GetSizeOfSubServiceInfoOfPCConfig()
#define vDam_IsIdentifierInfoUsedOfSubServiceInfo(Index)                                            (((boolean)(vDam_GetIdentifierInfoStartIdxOfSubServiceInfo(Index) != VDAM_NO_IDENTIFIERINFOSTARTIDXOFSUBSERVICEINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to vDam_IdentifierInfo */
#define vDam_IsVersionInfoApiOfGeneral()                                                            vDam_IsVersionInfoApiOfGeneralOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  vDamPCHasMacros  vDam Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define vDam_HasCustomRemapNrcCalloutFuncOfGeneral()                                                (TRUE != FALSE)
#define vDam_HasExpectedCompatibilityVersion()                                                        /**< Deactivateable: 'vDam_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vDam_HasFinalMagicNumber()                                                                    /**< Deactivateable: 'vDam_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vDam_HasFuncOfUserRoleCallout()                                                             (TRUE != FALSE)
#define vDam_HasGeneratorCompatibilityVersion()                                                       /**< Deactivateable: 'vDam_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vDam_HasIdentifierInfo()                                                                    (TRUE != FALSE)
#define vDam_HasIdentifierIdOfIdentifierInfo()                                                      (TRUE != FALSE)
#define vDam_HasIdentifierRolesOfIdentifierInfo()                                                   (TRUE != FALSE)
#define vDam_HasInitDataHashCode()                                                                    /**< Deactivateable: 'vDam_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define vDam_HasSafeBswChecksOfGeneral()                                                            (TRUE != FALSE)
#define vDam_HasServiceConfigurationStrategyOfGeneral()                                             (TRUE != FALSE)
#define vDam_HasServiceInfo()                                                                       (TRUE != FALSE)
#define vDam_HasServiceIdOfServiceInfo()                                                            (TRUE != FALSE)
#define vDam_HasServiceRolesOfServiceInfo()                                                         (TRUE != FALSE)
#define vDam_HasServiceRolesValidOfServiceInfo()                                                    (TRUE != FALSE)
#define vDam_HasSubServiceInfoEndIdxOfServiceInfo()                                                 (TRUE != FALSE)
#define vDam_HasSubServiceInfoStartIdxOfServiceInfo()                                               (TRUE != FALSE)
#define vDam_HasSubServiceInfoUsedOfServiceInfo()                                                   (TRUE != FALSE)
#define vDam_HasSizeOfIdentifierInfo()                                                              (TRUE != FALSE)
#define vDam_HasSizeOfServiceInfo()                                                                 (TRUE != FALSE)
#define vDam_HasSizeOfSubServiceInfo()                                                              (TRUE != FALSE)
#define vDam_HasSubServiceInfo()                                                                    (TRUE != FALSE)
#define vDam_HasIdentifierInfoEndIdxOfSubServiceInfo()                                              (TRUE != FALSE)
#define vDam_HasIdentifierInfoStartIdxOfSubServiceInfo()                                            (TRUE != FALSE)
#define vDam_HasIdentifierInfoUsedOfSubServiceInfo()                                                (TRUE != FALSE)
#define vDam_HasSubServiceIdOfSubServiceInfo()                                                      (TRUE != FALSE)
#define vDam_HasSubServiceRolesOfSubServiceInfo()                                                   (TRUE != FALSE)
#define vDam_HasSubServiceRolesValidOfSubServiceInfo()                                              (TRUE != FALSE)
#define vDam_HasVersionInfoApiOfGeneral()                                                           (TRUE != FALSE)
#define vDam_HasPCConfig()                                                                          (TRUE != FALSE)
#define vDam_HasCustomRemapNrcCalloutFuncOfGeneralOfPCConfig()                                      (TRUE != FALSE)
#define vDam_HasExpectedCompatibilityVersionOfPCConfig()                                              /**< Deactivateable: 'vDam_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vDam_HasFinalMagicNumberOfPCConfig()                                                          /**< Deactivateable: 'vDam_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vDam_HasFuncOfUserRoleCalloutOfPCConfig()                                                   (TRUE != FALSE)
#define vDam_HasGeneratorCompatibilityVersionOfPCConfig()                                             /**< Deactivateable: 'vDam_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vDam_HasIdentifierInfoOfPCConfig()                                                          (TRUE != FALSE)
#define vDam_HasInitDataHashCodeOfPCConfig()                                                          /**< Deactivateable: 'vDam_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define vDam_HasSafeBswChecksOfGeneralOfPCConfig()                                                  (TRUE != FALSE)
#define vDam_HasServiceConfigurationStrategyOfGeneralOfPCConfig()                                   (TRUE != FALSE)
#define vDam_HasServiceInfoOfPCConfig()                                                             (TRUE != FALSE)
#define vDam_HasSizeOfIdentifierInfoOfPCConfig()                                                    (TRUE != FALSE)
#define vDam_HasSizeOfServiceInfoOfPCConfig()                                                       (TRUE != FALSE)
#define vDam_HasSizeOfSubServiceInfoOfPCConfig()                                                    (TRUE != FALSE)
#define vDam_HasSubServiceInfoOfPCConfig()                                                          (TRUE != FALSE)
#define vDam_HasVersionInfoApiOfGeneralOfPCConfig()                                                 (TRUE != FALSE)
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
  \defgroup  vDamPBGetRootDataMacros  vDam Get Root Data Macros (POST_BUILD)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define vDam_GetLTConfigIdxOfPBConfig()                                                               /**< Deactivateable: 'vDam_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define vDam_GetPCConfigIdxOfPBConfig()                                                               /**< Deactivateable: 'vDam_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  vDamPBHasMacros  vDam Has Macros (POST_BUILD)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define vDam_HasPBConfig()                                                                            /**< Deactivateable: 'vDam_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define vDam_HasLTConfigIdxOfPBConfig()                                                               /**< Deactivateable: 'vDam_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define vDam_HasPCConfigIdxOfPBConfig()                                                               /**< Deactivateable: 'vDam_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
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






/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 vDam_InternalErrorStateType;



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vDamPCIterableTypes  vDam Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate vDam_IdentifierInfo */
/*! \spec strong type invariant () { self < vDam_GetSizeOfIdentifierInfo() } \endspec */ 
typedef uint8_least vDam_IdentifierInfoIterType;

/**   \brief  type used to iterate vDam_ServiceInfo */
/*! \spec strong type invariant () { self < vDam_GetSizeOfServiceInfo() } \endspec */ 
typedef uint8_least vDam_ServiceInfoIterType;

/**   \brief  type used to iterate vDam_SubServiceInfo */
/*! \spec strong type invariant () { self < vDam_GetSizeOfSubServiceInfo() } \endspec */ 
typedef uint8_least vDam_SubServiceInfoIterType;

/** 
  \}
*/ 

/** 
  \defgroup  vDamPCValueTypes  vDam Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for vDam_CustomRemapNrcCalloutFuncOfGeneral */
typedef uint32 vDam_CustomRemapNrcCalloutFuncOfGeneralType;

/**   \brief  value based type definition for vDam_FuncOfUserRoleCallout */
typedef uint32 vDam_FuncOfUserRoleCalloutType;

/**   \brief  value based type definition for vDam_IdentifierIdOfIdentifierInfo */
typedef uint16 vDam_IdentifierIdOfIdentifierInfoType;

/**   \brief  value based type definition for vDam_IdentifierRolesOfIdentifierInfo */
typedef uint16 vDam_IdentifierRolesOfIdentifierInfoType;

/**   \brief  value based type definition for vDam_SafeBswChecksOfGeneral */
typedef boolean vDam_SafeBswChecksOfGeneralType;

/**   \brief  value based type definition for vDam_ServiceConfigurationStrategyOfGeneral */
typedef uint8 vDam_ServiceConfigurationStrategyOfGeneralType;

/**   \brief  value based type definition for vDam_ServiceIdOfServiceInfo */
typedef uint8 vDam_ServiceIdOfServiceInfoType;

/**   \brief  value based type definition for vDam_ServiceRolesOfServiceInfo */
typedef uint16 vDam_ServiceRolesOfServiceInfoType;

/**   \brief  value based type definition for vDam_ServiceRolesValidOfServiceInfo */
typedef boolean vDam_ServiceRolesValidOfServiceInfoType;

/**   \brief  value based type definition for vDam_SubServiceInfoEndIdxOfServiceInfo */
/*! \spec strong type invariant () { self < vDam_GetSizeOfSubServiceInfo() } \endspec */ 
typedef uint8 vDam_SubServiceInfoEndIdxOfServiceInfoType;

/**   \brief  value based type definition for vDam_SubServiceInfoStartIdxOfServiceInfo */
/*! \spec strong type invariant () { self < vDam_GetSizeOfSubServiceInfo() } \endspec */ 
typedef uint8 vDam_SubServiceInfoStartIdxOfServiceInfoType;

/**   \brief  value based type definition for vDam_SubServiceInfoUsedOfServiceInfo */
typedef boolean vDam_SubServiceInfoUsedOfServiceInfoType;

/**   \brief  value based type definition for vDam_SizeOfIdentifierInfo */
typedef uint8 vDam_SizeOfIdentifierInfoType;

/**   \brief  value based type definition for vDam_SizeOfServiceInfo */
typedef uint8 vDam_SizeOfServiceInfoType;

/**   \brief  value based type definition for vDam_SizeOfSubServiceInfo */
typedef uint8 vDam_SizeOfSubServiceInfoType;

/**   \brief  value based type definition for vDam_IdentifierInfoEndIdxOfSubServiceInfo */
/*! \spec strong type invariant () { self < vDam_GetSizeOfIdentifierInfo() } \endspec */ 
typedef uint8 vDam_IdentifierInfoEndIdxOfSubServiceInfoType;

/**   \brief  value based type definition for vDam_IdentifierInfoStartIdxOfSubServiceInfo */
/*! \spec strong type invariant () { self < vDam_GetSizeOfIdentifierInfo() } \endspec */ 
typedef uint8 vDam_IdentifierInfoStartIdxOfSubServiceInfoType;

/**   \brief  value based type definition for vDam_IdentifierInfoUsedOfSubServiceInfo */
typedef boolean vDam_IdentifierInfoUsedOfSubServiceInfoType;

/**   \brief  value based type definition for vDam_SubServiceIdOfSubServiceInfo */
typedef uint8 vDam_SubServiceIdOfSubServiceInfoType;

/**   \brief  value based type definition for vDam_SubServiceRolesOfSubServiceInfo */
typedef uint16 vDam_SubServiceRolesOfSubServiceInfoType;

/**   \brief  value based type definition for vDam_SubServiceRolesValidOfSubServiceInfo */
typedef boolean vDam_SubServiceRolesValidOfSubServiceInfoType;

/**   \brief  value based type definition for vDam_VersionInfoApiOfGeneral */
typedef boolean vDam_VersionInfoApiOfGeneralType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vDamPCStructTypes  vDam Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in vDam_IdentifierInfo */
typedef struct svDam_IdentifierInfoType
{
  vDam_IdentifierIdOfIdentifierInfoType IdentifierIdOfIdentifierInfo;  /**< Id of the Identifier. */
  vDam_IdentifierRolesOfIdentifierInfoType IdentifierRolesOfIdentifierInfo;  /**< Bit Mask for Roles which are allowed on this level. */
} vDam_IdentifierInfoType;

/**   \brief  type used in vDam_ServiceInfo */
/*! 
 * \spec strong type invariant () { 
 *   (!(self.SubServiceInfoStartIdxOfServiceInfo != VDAM_NO_SUBSERVICEINFOSTARTIDXOFSERVICEINFO) || (self.SubServiceInfoEndIdxOfServiceInfo < vDam_GetSizeOfSubServiceInfo())) &&
 *   (!(self.SubServiceInfoStartIdxOfServiceInfo != VDAM_NO_SUBSERVICEINFOSTARTIDXOFSERVICEINFO) || (self.SubServiceInfoStartIdxOfServiceInfo < vDam_GetSizeOfSubServiceInfo()))
 * }
 * \endspec 
 */ 
typedef struct svDam_ServiceInfoType
{
  vDam_ServiceRolesOfServiceInfoType ServiceRolesOfServiceInfo;  /**< Bit Mask for Roles which are allowed on this level. */
  vDam_ServiceRolesValidOfServiceInfoType ServiceRolesValidOfServiceInfo;  /**< Determines if the Roles field has a valid value. */
  vDam_ServiceIdOfServiceInfoType ServiceIdOfServiceInfo;  /**< Id of the Service. */
  vDam_SubServiceInfoEndIdxOfServiceInfoType SubServiceInfoEndIdxOfServiceInfo;  /**< the end index of the 0:n relation pointing to vDam_SubServiceInfo */
  vDam_SubServiceInfoStartIdxOfServiceInfoType SubServiceInfoStartIdxOfServiceInfo;  /**< the start index of the 0:n relation pointing to vDam_SubServiceInfo */
} vDam_ServiceInfoType;

/**   \brief  type used in vDam_SubServiceInfo */
/*! 
 * \spec strong type invariant () { 
 *   (!(self.IdentifierInfoStartIdxOfSubServiceInfo != VDAM_NO_IDENTIFIERINFOSTARTIDXOFSUBSERVICEINFO) || (self.IdentifierInfoEndIdxOfSubServiceInfo < vDam_GetSizeOfIdentifierInfo())) &&
 *   (!(self.IdentifierInfoStartIdxOfSubServiceInfo != VDAM_NO_IDENTIFIERINFOSTARTIDXOFSUBSERVICEINFO) || (self.IdentifierInfoStartIdxOfSubServiceInfo < vDam_GetSizeOfIdentifierInfo()))
 * }
 * \endspec 
 */ 
typedef struct svDam_SubServiceInfoType
{
  vDam_SubServiceRolesOfSubServiceInfoType SubServiceRolesOfSubServiceInfo;  /**< Bit Mask for Roles which are allowed on this level. */
  vDam_SubServiceRolesValidOfSubServiceInfoType SubServiceRolesValidOfSubServiceInfo;  /**< Determines if the Roles field has a valid value. */
  vDam_IdentifierInfoEndIdxOfSubServiceInfoType IdentifierInfoEndIdxOfSubServiceInfo;  /**< the end index of the 0:n relation pointing to vDam_IdentifierInfo */
  vDam_IdentifierInfoStartIdxOfSubServiceInfoType IdentifierInfoStartIdxOfSubServiceInfo;  /**< the start index of the 0:n relation pointing to vDam_IdentifierInfo */
  vDam_SubServiceIdOfSubServiceInfoType SubServiceIdOfSubServiceInfo;  /**< Id of the Sub-Service. */
} vDam_SubServiceInfoType;

/** 
  \}
*/ 

/** 
  \defgroup  vDamPCRootPointerTypes  vDam Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to vDam_IdentifierInfo */
typedef P2CONST(vDam_IdentifierInfoType, TYPEDEF, VDAM_CONST) vDam_IdentifierInfoPtrType;

/**   \brief  type used to point to vDam_ServiceInfo */
typedef P2CONST(vDam_ServiceInfoType, TYPEDEF, VDAM_CONST) vDam_ServiceInfoPtrType;

/**   \brief  type used to point to vDam_SubServiceInfo */
typedef P2CONST(vDam_SubServiceInfoType, TYPEDEF, VDAM_CONST) vDam_SubServiceInfoPtrType;

/**   \brief  type used to point to vDam_CustomRemapNrcCalloutFuncOfGeneralOfPCConfig */
typedef P2CONST(vDam_CustomRemapNrcCalloutFuncOfGeneralType, TYPEDEF, VDAM_CONST) vDam_CustomRemapNrcCalloutFuncOfGeneralOfPCConfigPtrType;

/**   \brief  type used to point to vDam_FuncOfUserRoleCalloutOfPCConfig */
typedef P2CONST(vDam_FuncOfUserRoleCalloutType, TYPEDEF, VDAM_CONST) vDam_FuncOfUserRoleCalloutOfPCConfigPtrType;

/**   \brief  type used to point to vDam_ServiceConfigurationStrategyOfGeneralOfPCConfig */
typedef P2CONST(vDam_ServiceConfigurationStrategyOfGeneralType, TYPEDEF, VDAM_CONST) vDam_ServiceConfigurationStrategyOfGeneralOfPCConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  vDamPCRootValueTypes  vDam Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in vDam_PCConfig */
typedef struct svDam_PCConfigType
{
  uint8 vDam_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} vDam_PCConfigType;

typedef vDam_PCConfigType vDam_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vDamPBValueTypes  vDam Value Types (POST_BUILD)
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
  \defgroup  vDamPBRootValueTypes  vDam Root Value Types (POST_BUILD)
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
  vDam_IdentifierInfo
**********************************************************************************************************************/
/** 
  \var    vDam_IdentifierInfo
  \brief  List of Identifiers.
  \details
  Element            Description
  IdentifierId       Id of the Identifier.
  IdentifierRoles    Bit Mask for Roles which are allowed on this level.
*/ 
#define VDAM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "vDam_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vDam_IdentifierInfoType, VDAM_CONST) vDam_IdentifierInfo[177];
#define VDAM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "vDam_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vDam_ServiceInfo
**********************************************************************************************************************/
/** 
  \var    vDam_ServiceInfo
  \brief  List of Services.
  \details
  Element                   Description
  ServiceRoles              Bit Mask for Roles which are allowed on this level.
  ServiceRolesValid         Determines if the Roles field has a valid value.
  ServiceId                 Id of the Service.
  SubServiceInfoEndIdx      the end index of the 0:n relation pointing to vDam_SubServiceInfo
  SubServiceInfoStartIdx    the start index of the 0:n relation pointing to vDam_SubServiceInfo
*/ 
#define VDAM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "vDam_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vDam_ServiceInfoType, VDAM_CONST) vDam_ServiceInfo[8];
#define VDAM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "vDam_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vDam_SubServiceInfo
**********************************************************************************************************************/
/** 
  \var    vDam_SubServiceInfo
  \brief  List of Sub-Services.
  \details
  Element                   Description
  SubServiceRoles           Bit Mask for Roles which are allowed on this level.
  SubServiceRolesValid      Determines if the Roles field has a valid value.
  IdentifierInfoEndIdx      the end index of the 0:n relation pointing to vDam_IdentifierInfo
  IdentifierInfoStartIdx    the start index of the 0:n relation pointing to vDam_IdentifierInfo
  SubServiceId              Id of the Sub-Service.
*/ 
#define VDAM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "vDam_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vDam_SubServiceInfoType, VDAM_CONST) vDam_SubServiceInfo[6];
#define VDAM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "vDam_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
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




#define VDAM_START_SEC_CALLOUT_CODE
/*lint -save -esym(961, 19.1) */
#include "vDam_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
 *  User Callout
 *********************************************************************************************************************/
/*!
 * \fn          Appl_vDamUserRoleCalloutFunc
 * \brief       Provide current user Role
 * \param[in]   TesterSourceAddress  source address of the tester.
 * \param[out]  userRole             Current user role.
 * \return      E_OK      Operation successful
 * \return      E_NOT_OK  Operation failed
 * \pre         -
 * \reentrant   FALSE
 * \synchronous TRUE
 */
extern FUNC(Std_ReturnType, VDAM_CALLOUT_CODE) Appl_vDamUserRoleCalloutFunc( uint16 TesterSourceAddress, P2VAR(uint32, AUTOMATIC, AUTOMATIC) userRole );

/**********************************************************************************************************************
 *  User Callout
 *********************************************************************************************************************/
/*!
 * \fn          Os_Call_Appl_vDamRemapNrcCalloutFunc
 * \brief       Callout to remap internal errors to negative response codes.
 * \details     Provides the opportunity to remap the internal error value to a custom negative response code. The NRC
 *              is already filled according to the standard behavior of vDam.
 * \param[in]   SID           Contains the diagnostic service Id
 * \param[in]   intErrorCode  Contains the internal error code of vDam
 * \param[in,out]ErrorCode     Error code which will provided to the DCM
 * \pre         ErrorCode must only be written with 1 byte
 * \reentrant   TRUE
 * \synchronous TRUE
 */
extern FUNC(void, VDAM_CALLOUT_CODE) Os_Call_Appl_vDamRemapNrcCalloutFunc(uint8 SID, vDam_InternalErrorStateType intErrorCode, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, VDAM_DCM_VAR) errorCode);

#define VDAM_STOP_SEC_CALLOUT_CODE
/*lint -save -esym(961, 19.1) */
#include "vDam_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


#if !defined (VDAM_NOUNIT_CSLUNIT)
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/

#endif



#endif /* VDAM_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: vDam_Cfg.h
 *********************************************************************************************************************/

