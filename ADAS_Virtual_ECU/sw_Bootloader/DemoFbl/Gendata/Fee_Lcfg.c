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
 *              File: Fee_Lcfg.c
 *   Generation Time: 2024-11-25 15:00:22
 *           Project: DemoFbl - Version 1.0
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
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/Fee/FeePartitionConfiguration[0:FeeWriteAlignment](value=2048) is not in range [8, 1024].
 * Erroneous configuration elements:
 * /ActiveEcuC/Fee/FeePartitionConfiguration[0:FeeWriteAlignment](value=2048) (DefRef: /MICROSAR/Fee/FeePartitionConfiguration/FeeWriteAlignment)
 *********************************************************************************************************************/

/* macro identifying this compilation unit */
#define FEE_LCFG_C_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_InitEx.h"
#include "Fee_Int.h"
#include "Fee_PartitionDefs.h"

/**********************************************************************************************************************
 * VERSION IDENTIFICATION
 *********************************************************************************************************************/
# define FEE_CFG_C_MAJOR_VERSION                                        (10u)
# define FEE_CFG_C_MINOR_VERSION                                        (0u)
# define FEE_CFG_C_PATCH_VERSION                                        (0u)

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
#if (  (FEE_CFG_MAJOR_VERSION != FEE_CFG_C_MAJOR_VERSION) \
    || (FEE_CFG_MINOR_VERSION != FEE_CFG_C_MINOR_VERSION) )
# error "Version numbers of Fee_Lcfg.c and Fee_Cfg.h are inconsistent!"
#endif

#if (  (FEE_PRIVATE_CFG_MAJOR_VERSION != FEE_CFG_C_MAJOR_VERSION) \
    || (FEE_PRIVATE_CFG_MINOR_VERSION != FEE_CFG_C_MINOR_VERSION))
# error "Version numbers of Fee_Lcfg.c and Fee_PrivateCfg.h are inconsistent!"
#endif

#define FEE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */


static VAR(struct Fee_PartitionsRamDataStruct, FEE_VAR_NOINIT) Fee_PartitionRamData[FEE_NUMBER_OF_PARTITIONS];
#define FEE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL DATA CONSTANT
 *********************************************************************************************************************/
#define FEE_START_SEC_APPL_CONFIG_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */

  /*<FEE_BLOCK_CONFIGURATION>*/
CONST(struct Fee_BlockConfigStruct, FEE_APPL_CONFIG) Fee_BlockConfig_at[] =
{
  { /*  Block: FeeBlockDescriptor_ExhaustRegulationTan  */ 
    12u /*  index of the block in the linktable  */ , 
    6u /*  payload length  */ , 
    1u /*  number of datasets  */ , 
    FeePartitionConfiguration /*  partition where the block resides in  */ , 
    1u /*  the exponent of the number of instances per chunk (2^n)-1  */ , 
    FALSE /*  immediate data  */ , 
    FALSE /*  critical data  */ , 
    FALSE /*  look up table block  */ , 
    0u /*  base index of the block in the LookUpTable  */ 
  }, 
  { /*  Block: FeeBlockDescriptor_ApplValidity  */ 
    0u /*  index of the block in the linktable  */ , 
    1u /*  payload length  */ , 
    1u /*  number of datasets  */ , 
    FeePartitionConfiguration /*  partition where the block resides in  */ , 
    1u /*  the exponent of the number of instances per chunk (2^n)-1  */ , 
    FALSE /*  immediate data  */ , 
    FALSE /*  critical data  */ , 
    FALSE /*  look up table block  */ , 
    0u /*  base index of the block in the LookUpTable  */ 
  }, 
  { /*  Block: FeeBlockDescriptor_ProgrammingStatus  */ 
    13u /*  index of the block in the linktable  */ , 
    2u /*  payload length  */ , 
    1u /*  number of datasets  */ , 
    FeePartitionConfiguration /*  partition where the block resides in  */ , 
    1u /*  the exponent of the number of instances per chunk (2^n)-1  */ , 
    TRUE /*  immediate data  */ , 
    FALSE /*  critical data  */ , 
    FALSE /*  look up table block  */ , 
    0u /*  base index of the block in the LookUpTable  */ 
  }, 
  { /*  Block: FeeBlockDescriptor_VehicleManufEcuSwNumber  */ 
    14u /*  index of the block in the linktable  */ , 
    11u /*  payload length  */ , 
    1u /*  number of datasets  */ , 
    FeePartitionConfiguration /*  partition where the block resides in  */ , 
    1u /*  the exponent of the number of instances per chunk (2^n)-1  */ , 
    TRUE /*  immediate data  */ , 
    FALSE /*  critical data  */ , 
    FALSE /*  look up table block  */ , 
    0u /*  base index of the block in the LookUpTable  */ 
  }, 
  { /*  Block: FeeBlockDescriptor_ResetResponseFlag  */ 
    4u /*  index of the block in the linktable  */ , 
    1u /*  payload length  */ , 
    1u /*  number of datasets  */ , 
    FeePartitionConfiguration /*  partition where the block resides in  */ , 
    1u /*  the exponent of the number of instances per chunk (2^n)-1  */ , 
    FALSE /*  immediate data  */ , 
    FALSE /*  critical data  */ , 
    FALSE /*  look up table block  */ , 
    0u /*  base index of the block in the LookUpTable  */ 
  }, 
  { /*  Block: FeeBlockDescriptor_ApplUpdate  */ 
    8u /*  index of the block in the linktable  */ , 
    1u /*  payload length  */ , 
    1u /*  number of datasets  */ , 
    FeePartitionConfiguration /*  partition where the block resides in  */ , 
    1u /*  the exponent of the number of instances per chunk (2^n)-1  */ , 
    FALSE /*  immediate data  */ , 
    FALSE /*  critical data  */ , 
    FALSE /*  look up table block  */ , 
    0u /*  base index of the block in the LookUpTable  */ 
  }, 
  { /*  Block: FeeBlockDescriptor_EbomEcuPartNumber  */ 
    11u /*  index of the block in the linktable  */ , 
    10u /*  payload length  */ , 
    1u /*  number of datasets  */ , 
    FeePartitionConfiguration /*  partition where the block resides in  */ , 
    1u /*  the exponent of the number of instances per chunk (2^n)-1  */ , 
    TRUE /*  immediate data  */ , 
    FALSE /*  critical data  */ , 
    FALSE /*  look up table block  */ , 
    0u /*  base index of the block in the LookUpTable  */ 
  }, 
  { /*  Block: FeeBlockDescriptor_MetaData  */ 
    2u /*  index of the block in the linktable  */ , 
    126u /*  payload length  */ , 
    2u /*  number of datasets  */ , 
    FeePartitionConfiguration /*  partition where the block resides in  */ , 
    1u /*  the exponent of the number of instances per chunk (2^n)-1  */ , 
    FALSE /*  immediate data  */ , 
    FALSE /*  critical data  */ , 
    FALSE /*  look up table block  */ , 
    0u /*  base index of the block in the LookUpTable  */ 
  }, 
  { /*  Block: FeeBlockDescriptor_CoDePEcuPartNumber  */ 
    9u /*  index of the block in the linktable  */ , 
    11u /*  payload length  */ , 
    1u /*  number of datasets  */ , 
    FeePartitionConfiguration /*  partition where the block resides in  */ , 
    1u /*  the exponent of the number of instances per chunk (2^n)-1  */ , 
    TRUE /*  immediate data  */ , 
    FALSE /*  critical data  */ , 
    FALSE /*  look up table block  */ , 
    0u /*  base index of the block in the LookUpTable  */ 
  }, 
  { /*  Block: FeeBlockDescriptor_ProgReqFlag  */ 
    3u /*  index of the block in the linktable  */ , 
    1u /*  payload length  */ , 
    1u /*  number of datasets  */ , 
    FeePartitionConfiguration /*  partition where the block resides in  */ , 
    1u /*  the exponent of the number of instances per chunk (2^n)-1  */ , 
    FALSE /*  immediate data  */ , 
    FALSE /*  critical data  */ , 
    FALSE /*  look up table block  */ , 
    0u /*  base index of the block in the LookUpTable  */ 
  }, 
  { /*  Block: FeeBlockDescriptor_DiagnosticVersion  */ 
    10u /*  index of the block in the linktable  */ , 
    2u /*  payload length  */ , 
    1u /*  number of datasets  */ , 
    FeePartitionConfiguration /*  partition where the block resides in  */ , 
    1u /*  the exponent of the number of instances per chunk (2^n)-1  */ , 
    TRUE /*  immediate data  */ , 
    FALSE /*  critical data  */ , 
    FALSE /*  look up table block  */ , 
    0u /*  base index of the block in the LookUpTable  */ 
  }, 
  { /*  Block: FeeBlockDescriptor_SecAccessDelayFlag  */ 
    5u /*  index of the block in the linktable  */ , 
    1u /*  payload length  */ , 
    1u /*  number of datasets  */ , 
    FeePartitionConfiguration /*  partition where the block resides in  */ , 
    1u /*  the exponent of the number of instances per chunk (2^n)-1  */ , 
    FALSE /*  immediate data  */ , 
    FALSE /*  critical data  */ , 
    FALSE /*  look up table block  */ , 
    0u /*  base index of the block in the LookUpTable  */ 
  }, 
  { /*  Block: FeeBlockDescriptor_SecAccessInvalidCount  */ 
    6u /*  index of the block in the linktable  */ , 
    1u /*  payload length  */ , 
    1u /*  number of datasets  */ , 
    FeePartitionConfiguration /*  partition where the block resides in  */ , 
    1u /*  the exponent of the number of instances per chunk (2^n)-1  */ , 
    FALSE /*  immediate data  */ , 
    FALSE /*  critical data  */ , 
    FALSE /*  look up table block  */ , 
    0u /*  base index of the block in the LookUpTable  */ 
  }, 
  { /*  Block: FeeBlockDescriptor_DcmDslRxTesterSourceAddr  */ 
    1u /*  index of the block in the linktable  */ , 
    2u /*  payload length  */ , 
    1u /*  number of datasets  */ , 
    FeePartitionConfiguration /*  partition where the block resides in  */ , 
    1u /*  the exponent of the number of instances per chunk (2^n)-1  */ , 
    FALSE /*  immediate data  */ , 
    FALSE /*  critical data  */ , 
    FALSE /*  look up table block  */ , 
    0u /*  base index of the block in the LookUpTable  */ 
  }, 
  { /*  Block: FeeBlockDescriptor_ValidityFlags  */ 
    7u /*  index of the block in the linktable  */ , 
    2u /*  payload length  */ , 
    1u /*  number of datasets  */ , 
    FeePartitionConfiguration /*  partition where the block resides in  */ , 
    1u /*  the exponent of the number of instances per chunk (2^n)-1  */ , 
    FALSE /*  immediate data  */ , 
    FALSE /*  critical data  */ , 
    FALSE /*  look up table block  */ , 
    0u /*  base index of the block in the LookUpTable  */ 
  }
};
/*</FEE_BLOCK_CONFIGURATION>*/


/* Describe the partitions */
static CONST(struct Fee_PartitionConfigStruct, FEE_APPL_CONFIG) Fee_PartitionConfig_at[FEE_NUMBER_OF_PARTITIONS] =
{
  {
    &Fee_PartitionRamData[0], 
    {
      77312u /*  FSS threshold  */ , 
      67071u /*  BSS threshold  */ 
    }, 
    { /*  AssociatedSectors_at  */ 
      { /*  LowerSector  */ 
        0xFFFFFFFFu /*  Fls Erase Value  */ , 
        { /*  physical sector  */ 
          0x03FC0000u /*  physical sector start address  */ , 
          0x00040000u /*  physical sector size  */ 
        }, 
        { /*  configured sector  */ 
          0x03FE0000u /*  configured sector start address  */ , 
          0x00020000u /*  configured sector size  */ 
        }, 
        { /*  alignments  */ 
          11u /*  write alignment  */ , 
          8u /*  address alignment  */ 
        }
      }, 
      { /*  UpperSector  */ 
        0xFFFFFFFFu /*  Fls Erase Value  */ , 
        { /*  physical sector  */ 
          0x04000000u /*  physical sector start address  */ , 
          0x00040000u /*  physical sector size  */ 
        }, 
        { /*  configured sector  */ 
          0x04000000u /*  configured sector start address  */ , 
          0x00020000u /*  configured sector size  */ 
        }, 
        { /*  alignments  */ 
          11u /*  write alignment  */ , 
          8u /*  address alignment  */ 
        }
      }
    }, 
    (15u), 
    0u, 
    FALSE /*  No LookUpTable configured for this partition  */ , 
    0u /*  Index of LookUpTable configuration  */ 
  } /*  ramData_pt  */ 
};

CONST(struct Fee_ConfigStruct, FEE_APPL_CONFIG) Fee_Config = /* PRQA S 1533 */ /* MD_FEE_8.9_fee_config_struct */
{
    Fee_BlockConfig_at,
    Fee_PartitionConfig_at,
    (0x000Fu /*  number of blocks  */ ),
    FEE_NUMBER_OF_PARTITIONS,
    (1u /*  dataset selection bits  */ ),
    (FALSE /*  fbl config  */ )
};



#define FEE_STOP_SEC_APPL_CONFIG_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define FEE_START_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(Fee_ErrorCallbackReturnType, FEE_APPL_CODE) Fee_ErrorCallbackNotification(uint8 partitionId, Fee_SectorErrorType err) /* PRQA S 3206 */ /* MD_FEE_2.7_Parameter_Used_For_Other_Configs*/
{
#if (STD_ON == FEE_USE_APPL_ERROR_CALLBACK)
     return  Appl_CriticalErrorCallback(partitionId, err);
#else
     /* check partitionId -> avoid waning about unused parameter */
     FEE_DUMMY_STATEMENT(partitionId);
     return (Fee_ErrorCallbackReturnType)(
                        (err != FEE_SECTOR_FORMAT_FAILED) ? FEE_ERRCBK_RESOLVE_AUTOMATICALLY : FEE_ERRCBK_REJECT_WRITE);
#endif
}

#define FEE_STOP_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  END OF FILE: Fee_Lcfg.c
 *********************************************************************************************************************/
 

