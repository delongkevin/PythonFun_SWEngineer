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
 *            Module: Fbl
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D12
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Fbl_Lbt.h
 *   Generation Time: 2023-10-27 18:05:39
 *           Project: DemoUpdater - Version 1.0
 *          Delivery: CBD2101146_D12
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/


#if !defined(__FBL_LBT_H__)
#define __FBL_LBT_H__

/* Includes **********************************************************************************************************/
#include "Platform_Types.h"

/* Defines ***********************************************************************************************************/
#define FBL_LBT_DISABLE_REPROGRAMMABLE_LBT 
#define FBL_LBT_ENABLE_MANDATORY_TYPE 
#define FBL_LBT_ENABLE_BLOCK_INDEX 
#define FBL_LBT_ENABLE_BLOCK_TYPE 
#define FBL_LBT_ENABLE_BM_HEADER_ADDRESS 
#define FBL_LBT_ENABLE_MAX_PROG_ATTEMPTS 
#define FBL_LBT_ENABLE_VERIFY_INPUT 
#define FBL_LBT_ENABLE_VERIFY_PROCESSED 
#define FBL_LBT_ENABLE_VERIFY_PIPELINED 
#define FBL_LBT_ENABLE_VERIFY_OUTPUT 
#define FBL_LBT_FBL_BLOCK_NUMBER                  0u 
#define FBL_LBT_FBL_BLOCK_INDEX                   0x00000000u 
#define FBL_LBT_MCU10_APPLICATION_LB_BLOCK_NUMBER 1u 
#define FBL_LBT_MCU10_APPLICATION_LB_BLOCK_INDEX  0x00000001u 
#define FBL_LBT_BM_HSM_LB_BLOCK_NUMBER            2u 
#define FBL_LBT_BM_HSM_LB_BLOCK_INDEX             0x00000002u 
#define FBL_LBT_SBL_LB_BLOCK_NUMBER               3u 
#define FBL_LBT_SBL_LB_BLOCK_INDEX                0x00000003u 
#define FBL_LBT_TIFS_LB_BLOCK_NUMBER              4u 
#define FBL_LBT_TIFS_LB_BLOCK_INDEX               0x00000004u 
#define kBlockTypeCode                            0x00000001u 
#define kBlockTypeData                            0x00000002u 
#define kBlockTypeBoot                            0x00000000u 
#define kBlockTypeCodeBlockCount                  0x00000004u 
#define kBlockTypeDataBlockCount                  0x00000000u 
#define kBlockTypeBootBlockCount                  0x00000001u 
#define FBL_LBT_BLOCK_COUNT                       9u 
#define kNrOfValidationBytes                      2u 
#define FBL_LBT_MAGIC_FLAG                        0x3AF7573Fu 

/* Macro to determine if the block table is valid */
#define IsLogicalBlockTableValid()        (FblLogicalBlockTable.magicFlag == FBL_LBT_MAGIC_FLAG)

/* Compatibility defines */
#define FBL_MTAB_FBL_BLOCK_NUMBER                  FBL_LBT_FBL_BLOCK_NUMBER 
#define FBL_MTAB_FBL_BLOCK_INDEX                   FBL_LBT_FBL_BLOCK_INDEX 
#define FBL_MTAB_MCU10_APPLICATION_LB_BLOCK_NUMBER FBL_LBT_MCU10_APPLICATION_LB_BLOCK_NUMBER 
#define FBL_MTAB_MCU10_APPLICATION_LB_BLOCK_INDEX  FBL_LBT_MCU10_APPLICATION_LB_BLOCK_INDEX 
#define FBL_MTAB_BM_HSM_LB_BLOCK_NUMBER            FBL_LBT_BM_HSM_LB_BLOCK_NUMBER 
#define FBL_MTAB_BM_HSM_LB_BLOCK_INDEX             FBL_LBT_BM_HSM_LB_BLOCK_INDEX 
#define FBL_MTAB_SBL_LB_BLOCK_NUMBER               FBL_LBT_SBL_LB_BLOCK_NUMBER 
#define FBL_MTAB_SBL_LB_BLOCK_INDEX                FBL_LBT_SBL_LB_BLOCK_INDEX 
#define FBL_MTAB_TIFS_LB_BLOCK_NUMBER              FBL_LBT_TIFS_LB_BLOCK_NUMBER 
#define FBL_MTAB_TIFS_LB_BLOCK_INDEX               FBL_LBT_TIFS_LB_BLOCK_INDEX 
#define kBlockTypeCodeNoOfBlocks                   kBlockTypeCodeBlockCount 
#define kBlockTypeDataNoOfBlocks                   kBlockTypeDataBlockCount 
#define kBlockTypeBootNoOfBlocks                   kBlockTypeBootBlockCount 
#define FBL_MTAB_NO_OF_BLOCKS                      FBL_LBT_BLOCK_COUNT 
#define FBL_MTAB_MAGIC_FLAG                        FBL_LBT_MAGIC_FLAG 


/* Typedefs **********************************************************************************************************/
typedef vuint8 tFblLbtBlockNr; 
typedef boolean tFblLbtMandatoryType; 
typedef vuint32 tFblLbtBlockIndex; 
typedef vuint32 tFblLbtBlockType; 
typedef vuint16 tFblLbtMaxProgAttempts; 
typedef vuint32 tFblLbtMagicFlag; 
typedef vuint8 tFblLbtAssignFlags; 
typedef vuint8 tFblLbtBlockCount; 


/* Entry type of logical block table */
typedef struct tBlockDescriptorTag {
  tFblLbtBlockNr blockNr; /*  Number of logical block  */ 
  tFblLbtMandatoryType mandatoryType; /*  Optional or mandatory block  */ 
  tFblLbtBlockIndex blockIndex;
  tFblLbtBlockType blockType;
  tFblAddress blockStartAddress; /*  Start address of current block  */ 
  tFblLength blockLength; /*  Block length in bytes  */ 
  tFblAddress bmHeaderAddress; /*  BM Header Address  */ 
  tFblLbtMaxProgAttempts maxProgAttempts; /*  Maximum number of reprogramming attempts  */ 
  tExportFct verifyInput; /*  Input Verification  */ 
  tExportFct verifyProcessed; /*  Processed Verification  */ 
  tExportFct verifyPipelined; /*  Pipelined Verification  */ 
  tExportFct verifyOutput; /*  Output Verification  */ 
} tBlockDescriptor;

/* The logical block table describes the memory layout of logical blocks */
typedef struct tLogicalBlockTableTag {
  tFblLbtMagicFlag magicFlag; /*  Value of FBL_LBT_MAGIC_FLAG - Indicates the existence of the table  */ 
  tFblLbtAssignFlags assignFlags[kNrOfValidationBytes]; /*  Disposability bit field (mandatory/optional)  */ 
  tFblLbtBlockCount noOfBlocks; /*  Number of configured logical blocks  */ 
  tBlockDescriptor logicalBlock[FBL_LBT_BLOCK_COUNT];
} tLogicalBlockTable;

/* Global data *******************************************************************************************************/
V_MEMROM0 extern V_MEMROM1 tLogicalBlockTable V_MEMROM2 FblLogicalBlockTable;

#endif /* __FBL_LBT_H__ */
