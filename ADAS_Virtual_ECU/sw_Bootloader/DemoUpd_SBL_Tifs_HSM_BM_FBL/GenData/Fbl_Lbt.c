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
 *              File: Fbl_Lbt.c
 *   Generation Time: 2023-10-27 18:05:39
 *           Project: DemoUpdater - Version 1.0
 *          Delivery: CBD2101146_D12
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/


/* Includes **********************************************************************************************************/
#include "fbl_inc.h"

/* Global data *******************************************************************************************************/
V_MEMROM0 V_MEMROM1 tLogicalBlockTable V_MEMROM2 FblLogicalBlockTable =
{
  FBL_LBT_MAGIC_FLAG, 
  {
    0x1Fu, 
    0x00u
  } /*  Disposability bit field (mandatory/optional)  */ , 
  5u, 
  {
    {
      0u, 
      TRUE /*  Mandatory  */ , 
      0x00000000u /*  Block Index  */ , 
      kBlockTypeBoot /*  Block Type  */ , 
      0x00280000u /*  Block Start Address  */ , 
      0x00080000u /*  Block Length (End Address = 0x002FFFFFu)  */ , 
      0x00280000u /*  BM Header Address  */ , 
      0x0000u /*  Max Prog Attempts  */ , 
      (tExportFct)0 /*  Input Verification  */ , 
      (tExportFct)0 /*  Processed Verification  */ , 
      (tExportFct)0 /*  Pipelined Verification  */ , 
      (tExportFct)0 /*  Output Verification  */ 
    } /*  Name 'FBL'  */ , 
    {
      1u, 
      TRUE /*  Mandatory  */ , 
      0x00000001u /*  Block Index  */ , 
      kBlockTypeCode /*  Block Type  */ , 
      0x00300000u /*  Block Start Address  */ , 
      0x00300000u /*  Block Length (End Address = 0x005FFFFFu)  */ , 
      0x00300240u /*  BM Header Address  */ , 
      0x0000u /*  Max Prog Attempts  */ , 
      (tExportFct)0 /*  Input Verification  */ , 
      (tExportFct)0 /*  Processed Verification  */ , 
      (tExportFct)0 /*  Pipelined Verification  */ , 
      (tExportFct)0 /*  Output Verification  */ 
    } /*  Name 'MCU10_Application_LB'  */ , 
    {
      2u, 
      TRUE /*  Mandatory  */ , 
      0x00000002u /*  Block Index  */ , 
      kBlockTypeCode /*  Block Type  */ , 
      0x000C0000u /*  Block Start Address  */ , 
      0x001C0000u /*  Block Length (End Address = 0x0027FFFFu)  */ , 
      0x000C0000u /*  BM Header Address  */ , 
      0x0000u /*  Max Prog Attempts  */ , 
      (tExportFct)0 /*  Input Verification  */ , 
      (tExportFct)0 /*  Processed Verification  */ , 
      (tExportFct)0 /*  Pipelined Verification  */ , 
      (tExportFct)0 /*  Output Verification  */ 
    } /*  Name 'BM_HSM_LB'  */ , 
    {
      3u, 
      TRUE /*  Mandatory  */ , 
      0x00000003u /*  Block Index  */ , 
      kBlockTypeCode /*  Block Type  */ , 
      0x00000000u /*  Block Start Address  */ , 
      0x00080000u /*  Block Length (End Address = 0x0007FFFFu)  */ , 
      0x00000000u /*  BM Header Address  */ , 
      0x0000u /*  Max Prog Attempts  */ , 
      (tExportFct)0 /*  Input Verification  */ , 
      (tExportFct)0 /*  Processed Verification  */ , 
      (tExportFct)0 /*  Pipelined Verification  */ , 
      (tExportFct)0 /*  Output Verification  */ 
    } /*  Name 'SBL_LB'  */ , 
    {
      4u, 
      TRUE /*  Mandatory  */ , 
      0x00000004u /*  Block Index  */ , 
      kBlockTypeCode /*  Block Type  */ , 
      0x00080000u /*  Block Start Address  */ , 
      0x00040000u /*  Block Length (End Address = 0x000BFFFFu)  */ , 
      0x00080000u /*  BM Header Address  */ , 
      0x0000u /*  Max Prog Attempts  */ , 
      (tExportFct)0 /*  Input Verification  */ , 
      (tExportFct)0 /*  Processed Verification  */ , 
      (tExportFct)0 /*  Pipelined Verification  */ , 
      (tExportFct)0 /*  Output Verification  */ 
    } /*  Name 'TIFS_LB'  */ 
  }
};

