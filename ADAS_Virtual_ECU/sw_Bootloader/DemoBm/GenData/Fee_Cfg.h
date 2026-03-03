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
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Fee_Cfg.h
 *   Generation Time: 2024-11-25 13:00:27
 *           Project: DemoBm - Version 1.0
 *          Delivery: CBD2101146_D13
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
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/Fee/FeePartitionConfiguration[0:FeeUpperSectorAddress](value=0) is not in range [1, 2147483648].
 * Erroneous configuration elements:
 * /ActiveEcuC/Fee/FeePartitionConfiguration[0:FeeUpperSectorAddress](value=0) (DefRef: /MICROSAR/Fee/FeePartitionConfiguration/FeeUpperSectorAddress)
 * 
 * [Warning] AR-ECUC02027 - Integer value out of range 
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/Fee/FeePartitionConfiguration[0:FeeWriteAlignment](value=2048) is not in range [8, 1024].
 * Erroneous configuration elements:
 * /ActiveEcuC/Fee/FeePartitionConfiguration[0:FeeWriteAlignment](value=2048) (DefRef: /MICROSAR/Fee/FeePartitionConfiguration/FeeWriteAlignment)
 *********************************************************************************************************************/
    
/**********************************************************************************************************************
 *  PUBLIC SECTION
 *********************************************************************************************************************/
#if !defined (FEE_CFG_H_PUBLIC)
# define FEE_CFG_H_PUBLIC

  /********************************************************************************************************************
   *  GLOBAL CONSTANT MACROS
   *******************************************************************************************************************/
  /****************************************************************************
   * VERSION IDENTIFICATION
   ***************************************************************************/
# define FEE_CFG_MAJOR_VERSION                    (10u)
# define FEE_CFG_MINOR_VERSION                    (0u)
# define FEE_CFG_PATCH_VERSION                    (0u)

  /****************************************************************************
   * API CONFIGURATION
   ***************************************************************************/
# define FEE_VERSION_INFO_API                     (STD_OFF)
# define FEE_GET_ERASE_CYCLE_API                  (STD_OFF)
# define FEE_GET_WRITE_CYCLE_API                  (STD_OFF)
# define FEE_FORCE_SECTOR_SWITCH_API              (STD_OFF)
# define FEE_FSS_CONTROL_API                      (STD_OFF)
# define FEE_DATA_CONVERSION_API                  (STD_OFF)

  /****************************************************************************
   * BEHAVIOR CONFIGURATION
   ***************************************************************************/
# define FEE_LOOKUPTABLE_MODE                     (STD_OFF)
# define FEE_EXTENDED_SECTOR_HEADER_CHECK         (STD_ON)
# define FEE_USE_RELIABLE_ERASE_PROCEDURE		  (STD_OFF)

  /****************************************************************************
   * DEVELOPMENT CONFIGURATION
   ***************************************************************************/
# define FEE_DEV_ERROR_DETECT                     (STD_ON)
# define FEE_DEBUG_REPORTING                      (STD_ON)

  /****************************************************************************
   * GENERAL CONFIGURATION PARAMETER
   ***************************************************************************/

#define FeeConf_FeeBlockConfiguration_FeeBlockDescriptor_ApplValidity (4u) 
#define FeeConf_FeeBlockConfiguration_FeeBlockDescriptor_DcmDslRxTesterSourceAddr (28u) 
#define FeeConf_FeeBlockConfiguration_FeeBlockDescriptor_MetaData (16u) 
#define FeeConf_FeeBlockConfiguration_FeeBlockDescriptor_ProgReqFlag (20u) 
#define FeeConf_FeeBlockConfiguration_FeeBlockDescriptor_ResetResponseFlag (10u) 
#define FeeConf_FeeBlockConfiguration_FeeBlockDescriptor_SecAccessDelayFlag (24u) 
#define FeeConf_FeeBlockConfiguration_FeeBlockDescriptor_SecAccessInvalidCount (26u) 
#define FeeConf_FeeBlockConfiguration_FeeBlockDescriptor_ValidityFlags (30u) 
#define FeeConf_FeeBlockConfiguration_FeeBlockDescriptor_ApplUpdate (12u) 
#define FeeConf_FeeBlockConfiguration_FeeBlockDescriptor_CoDePEcuPartNumber (18u) 
#define FeeConf_FeeBlockConfiguration_FeeBlockDescriptor_DiagnosticVersion (22u) 
#define FeeConf_FeeBlockConfiguration_FeeBlockDescriptor_EbomEcuPartNumber (14u) 
#define FeeConf_FeeBlockConfiguration_FeeBlockDescriptor_ExhaustRegulationTan (2u) 
#define FeeConf_FeeBlockConfiguration_FeeBlockDescriptor_ProgrammingStatus (6u) 
#define FeeConf_FeeBlockConfiguration_FeeBlockDescriptor_VehicleManufEcuSwNumber (8u) 


#define FeePartitionConfiguration (0u) 


#define FEE_NUMBER_OF_PARTITIONS (1)

#endif /* FEE_CFG_H_PUBLIC */

/**********************************************************************************************************************
 *  END OF FILE: Fee_Cfg.h
 *********************************************************************************************************************/
 

