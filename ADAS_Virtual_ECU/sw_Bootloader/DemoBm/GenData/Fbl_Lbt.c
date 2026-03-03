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
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Fbl_Lbt.c
 *   Generation Time: 2024-11-25 13:00:27
 *           Project: DemoBm - Version 1.0
 *          Delivery: CBD2101146_D13
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
    0x11u, 
    0x00u
  } /*  Disposability bit field (mandatory/optional)  */ , 
  9u, 
  {
    {
      0u, 
      TRUE /*  Mandatory  */ , 
      0x00000000u /*  Block Index  */ , 
      kBlockTypeBoot /*  Block Type  */ , 
      0x00280000u /*  Block Start Address  */ , 
      0x00080000u /*  Block Length (End Address = 0x002FFFFFu)  */ , 
      0x002801E0u /*  BM Header Address  */ , 
      0x0000u /*  Max Prog Attempts  */ , 
      (tExportFct)0 /*  Input Verification  */ , 
      (tExportFct)0 /*  Processed Verification  */ , 
      (tExportFct)0 /*  Pipelined Verification  */ , 
      (tExportFct)0 /*  Output Verification  */ 
    } /*  Name 'FBL'  */ , 
    {
      1u, 
      FALSE /*  Optional  */ , 
      0x00000006u /*  Block Index  */ , 
      kBlockTypeData /*  Block Type  */ , 
      0x04580000u /*  Block Start Address  */ , 
      0x00100000u /*  Block Length (End Address = 0x0467FFFFu)  */ , 
      0x04580000u /*  BM Header Address  */ , 
      0x0000u /*  Max Prog Attempts  */ , 
      (tExportFct)0 /*  Input Verification  */ , 
      (tExportFct)0 /*  Processed Verification  */ , 
      (tExportFct)0 /*  Pipelined Verification  */ , 
      (tExportFct)0 /*  Output Verification  */ 
    } /*  Name 'CAL_LB'  */ , 
    {
      2u, 
      FALSE /*  Optional  */ , 
      0x00000007u /*  Block Index  */ , 
      kBlockTypeData /*  Block Type  */ , 
      0x04680000u /*  Block Start Address  */ , 
      0x00040000u /*  Block Length (End Address = 0x046BFFFFu)  */ , 
      0x04680000u /*  BM Header Address  */ , 
      0x0000u /*  Max Prog Attempts  */ , 
      (tExportFct)0 /*  Input Verification  */ , 
      (tExportFct)0 /*  Processed Verification  */ , 
      (tExportFct)0 /*  Pipelined Verification  */ , 
      (tExportFct)0 /*  Output Verification  */ 
    } /*  Name 'ExtendedKeyRing'  */ , 
    {
      3u, 
      FALSE /*  Optional  */ , 
      0x00000008u /*  Block Index  */ , 
      kBlockTypeData /*  Block Type  */ , 
      0x06600000u /*  Block Start Address  */ , 
      0x00040000u /*  Block Length (End Address = 0x0663FFFFu)  */ , 
      0x06600000u /*  BM Header Address  */ , 
      0x0000u /*  Max Prog Attempts  */ , 
      (tExportFct)0 /*  Input Verification  */ , 
      (tExportFct)0 /*  Processed Verification  */ , 
      (tExportFct)0 /*  Pipelined Verification  */ , 
      (tExportFct)0 /*  Output Verification  */ 
    } /*  Name 'Security_Cert_LB'  */ , 
    {
      4u, 
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
      5u, 
      FALSE /*  Optional  */ , 
      0x00000002u /*  Block Index  */ , 
      kBlockTypeCode /*  Block Type  */ , 
      0x00600000u /*  Block Start Address  */ , 
      0x00D00000u /*  Block Length (End Address = 0x012FFFFFu)  */ , 
      0x00600000u /*  BM Header Address  */ , 
      0x0000u /*  Max Prog Attempts  */ , 
      (tExportFct)0 /*  Input Verification  */ , 
      (tExportFct)0 /*  Processed Verification  */ , 
      (tExportFct)0 /*  Pipelined Verification  */ , 
      (tExportFct)0 /*  Output Verification  */ 
    } /*  Name 'LateApp1_MCU20_MCU21_LB'  */ , 
    {
      6u, 
      FALSE /*  Optional  */ , 
      0x00000003u /*  Block Index  */ , 
      kBlockTypeCode /*  Block Type  */ , 
      0x01300000u /*  Block Start Address  */ , 
      0x00080000u /*  Block Length (End Address = 0x0137FFFFu)  */ , 
      0x01300000u /*  BM Header Address  */ , 
      0x0000u /*  Max Prog Attempts  */ , 
      (tExportFct)0 /*  Input Verification  */ , 
      (tExportFct)0 /*  Processed Verification  */ , 
      (tExportFct)0 /*  Pipelined Verification  */ , 
      (tExportFct)0 /*  Output Verification  */ 
    } /*  Name 'AtfOptee_LB'  */ , 
    {
      7u, 
      FALSE /*  Optional  */ , 
      0x00000004u /*  Block Index  */ , 
      kBlockTypeCode /*  Block Type  */ , 
      0x01380000u /*  Block Start Address  */ , 
      0x02800000u /*  Block Length (End Address = 0x03B7FFFFu)  */ , 
      0x01380000u /*  BM Header Address  */ , 
      0x0000u /*  Max Prog Attempts  */ , 
      (tExportFct)0 /*  Input Verification  */ , 
      (tExportFct)0 /*  Processed Verification  */ , 
      (tExportFct)0 /*  Pipelined Verification  */ , 
      (tExportFct)0 /*  Output Verification  */ 
    } /*  Name 'IfsQNX_LB'  */ , 
    {
      8u, 
      FALSE /*  Optional  */ , 
      0x00000005u /*  Block Index  */ , 
      kBlockTypeCode /*  Block Type  */ , 
      0x03B80000u /*  Block Start Address  */ , 
      0x00A00000u /*  Block Length (End Address = 0x0457FFFFu)  */ , 
      0x03B80000u /*  BM Header Address  */ , 
      0x0000u /*  Max Prog Attempts  */ , 
      (tExportFct)0 /*  Input Verification  */ , 
      (tExportFct)0 /*  Processed Verification  */ , 
      (tExportFct)0 /*  Pipelined Verification  */ , 
      (tExportFct)0 /*  Output Verification  */ 
    } /*  Name 'C7x_LB'  */ 
  }
};

