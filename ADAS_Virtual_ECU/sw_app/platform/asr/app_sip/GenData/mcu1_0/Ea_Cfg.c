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
 *            Module: Ea
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Ea_Cfg.c
 *   Generation Time: 2024-12-05 16:58:36
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#define EA_IMPLEMENTATION_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

#include "Eep_30_XXi2c01.h" 

#include "Ea.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
 
#if (   (EA_CFG_MAJOR_VERSION != (5u)) \
     || (EA_CFG_MINOR_VERSION != (3u)))
# error "Version numbers of Ea_Cfg.c and Ea_Cfg.h are inconsistent!"
#endif

#if (   (EA_SW_MAJOR_VERSION != (3u)) \
     || (EA_SW_MINOR_VERSION != (3u)))
# error "Version numbers of Ea_Cfg.c and Ea.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

#ifndef EA_LOCAL /* COV_EA_COMPATIBILITY */
# define EA_LOCAL static
#endif

#if !defined (EA_LOCAL_INLINE) /* COV_EA_COMPATIBILITY */
# define EA_LOCAL_INLINE LOCAL_INLINE
#endif

#define EA_START_SEC_CONST_8BIT
#include "MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(uint8, EA_PRIVATE_CONST) Ea_DatasetSelectionBits = (4u);

#define EA_STOP_SEC_CONST_8BIT
#include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define EA_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(Ea_PartitionConfigType, EA_PRIVATE_CONST) Ea_PartitionConfigList[EA_NUMBER_OF_PARTITIONS] = 
{
   /*  EAPARTITIONCONFIGURATION_FBLAPP  */ {
     /*  Partition Start Address  */ 0x00000000u, 
     /*  Partition Address Alignment  */ 0x0001u, 
     /*  Partition Write Alignment  */ 0x0001u, 
     /*  Partition Read Alignment  */ 0x0001u, 
     /*  EEP Device Index  */ 0x0000u, 
     /*  EEP API Reference  */ &Ea_EepApi0, 
     /*  EEP Erase Value  */ 0xFFu
  }, 
   /*  EAPARTITIONCONFIGURATION_APP  */ {
     /*  Partition Start Address  */ 0x00000E58u, 
     /*  Partition Address Alignment  */ 0x0001u, 
     /*  Partition Write Alignment  */ 0x0001u, 
     /*  Partition Read Alignment  */ 0x0001u, 
     /*  EEP Device Index  */ 0x0000u, 
     /*  EEP API Reference  */ &Ea_EepApi0, 
     /*  EEP Erase Value  */ 0xFFu
  }, 
   /*  EAPARTITIONCONFIGURATION_DEM  */ {
     /*  Partition Start Address  */ 0x000016F9u, 
     /*  Partition Address Alignment  */ 0x0001u, 
     /*  Partition Write Alignment  */ 0x0001u, 
     /*  Partition Read Alignment  */ 0x0001u, 
     /*  EEP Device Index  */ 0x0000u, 
     /*  EEP API Reference  */ &Ea_EepApi0, 
     /*  EEP Erase Value  */ 0xFFu
  }, 
   /*  EAPARTITIONCONFIGURATION_TIMETAMP  */ {
     /*  Partition Start Address  */ 0x00001BC9u, 
     /*  Partition Address Alignment  */ 0x0001u, 
     /*  Partition Write Alignment  */ 0x0001u, 
     /*  Partition Read Alignment  */ 0x0001u, 
     /*  EEP Device Index  */ 0x0000u, 
     /*  EEP API Reference  */ &Ea_EepApi0, 
     /*  EEP Erase Value  */ 0xFFu
  }, 
   /*  EAPARTITIONCONFIGURATION_SECURELOG  */ {
     /*  Partition Start Address  */ 0x00001C00u, 
     /*  Partition Address Alignment  */ 0x0001u, 
     /*  Partition Write Alignment  */ 0x0001u, 
     /*  Partition Read Alignment  */ 0x0001u, 
     /*  EEP Device Index  */ 0x0000u, 
     /*  EEP API Reference  */ &Ea_EepApi0, 
     /*  EEP Erase Value  */ 0xFFu
  }
};

/* BlockConfigList is sorted by BlockNumbers in ascending order */
CONST(Ea_BlockConfigType, EA_PRIVATE_CONST) Ea_BlockConfigList[EA_NUMBER_OF_BLOCKS] =
{
   /*  EABLOCKCONFIGURATION  */ {
     /*  Block Start Address  */ 0x00000000u, 
     /*  Data Length  */ 0x0004u, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDEM_ADMINDATA  */ {
     /*  Block Start Address  */ 0x00000000u, 
     /*  Data Length  */ 0x000Eu, 
     /*  Partition Index  */ 0x0002u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDEM_AGING  */ {
     /*  Block Start Address  */ 0x00000010u, 
     /*  Data Length  */ 0x0086u, 
     /*  Partition Index  */ 0x0002u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDEM_EVENTSTATUS  */ {
     /*  Block Start Address  */ 0x00000098u, 
     /*  Data Length  */ 0x004Eu, 
     /*  Partition Index  */ 0x0002u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDEM_PRIMARY0  */ {
     /*  Block Start Address  */ 0x000000E8u, 
     /*  Data Length  */ 0x0056u, 
     /*  Partition Index  */ 0x0002u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDEM_PRIMARY1  */ {
     /*  Block Start Address  */ 0x00000140u, 
     /*  Data Length  */ 0x0056u, 
     /*  Partition Index  */ 0x0002u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDEM_PRIMARY2  */ {
     /*  Block Start Address  */ 0x00000198u, 
     /*  Data Length  */ 0x0056u, 
     /*  Partition Index  */ 0x0002u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDEM_PRIMARY3  */ {
     /*  Block Start Address  */ 0x000001F0u, 
     /*  Data Length  */ 0x0056u, 
     /*  Partition Index  */ 0x0002u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDEM_PRIMARY4  */ {
     /*  Block Start Address  */ 0x00000248u, 
     /*  Data Length  */ 0x0056u, 
     /*  Partition Index  */ 0x0002u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDEM_PRIMARY5  */ {
     /*  Block Start Address  */ 0x000002A0u, 
     /*  Data Length  */ 0x0056u, 
     /*  Partition Index  */ 0x0002u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDEM_PRIMARY6  */ {
     /*  Block Start Address  */ 0x000002F8u, 
     /*  Data Length  */ 0x0056u, 
     /*  Partition Index  */ 0x0002u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDEM_PRIMARY7  */ {
     /*  Block Start Address  */ 0x00000350u, 
     /*  Data Length  */ 0x0056u, 
     /*  Partition Index  */ 0x0002u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDEM_PRIMARY8  */ {
     /*  Block Start Address  */ 0x000003A8u, 
     /*  Data Length  */ 0x0056u, 
     /*  Partition Index  */ 0x0002u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDEM_PRIMARY9  */ {
     /*  Block Start Address  */ 0x00000400u, 
     /*  Data Length  */ 0x0056u, 
     /*  Partition Index  */ 0x0002u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EASWC_VROE_ACTIVATION_STATE  */ {
     /*  Block Start Address  */ 0x000006D2u, 
     /*  Data Length  */ 0x0003u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDESCRIPTOR_APPLVALIDITY  */ {
     /*  Block Start Address  */ 0x00000020u, 
     /*  Data Length  */ 0x0003u, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDESCRIPTOR_DID_2002_ODOFLASHING  */ {
     /*  Block Start Address  */ 0x00000E4Au, 
     /*  Data Length  */ 0x0004u, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDESCRIPTOR_DID_2010_PROGRAMMINGSTATUS  */ {
     /*  Block Start Address  */ 0x00000051u, 
     /*  Data Length  */ 0x0004u, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDESCRIPTOR_DID_F110_ECU_DIAG_ID_FLASHDEFINITIONNUMBER  */ {
     /*  Block Start Address  */ 0x00000E2Du, 
     /*  Data Length  */ 0x0008u, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDESCRIPTOR_DID_F132_EBOM_ECU_PARTNUM  */ {
     /*  Block Start Address  */ 0x00000E0Au, 
     /*  Data Length  */ 0x000Cu, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDESCRIPTOR_DID_F133_EBOM_ASM_PARTNUM  */ {
     /*  Block Start Address  */ 0x00000DC2u, 
     /*  Data Length  */ 0x000Cu, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDESCRIPTOR_DID_F134_CODEP_ASM_PARTNUM  */ {
     /*  Block Start Address  */ 0x00000DFBu, 
     /*  Data Length  */ 0x000Du, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDESCRIPTOR_DID_F180_BOOT_SW_VER_INFO  */ {
     /*  Block Start Address  */ 0x00000040u, 
     /*  Data Length  */ 0x000Fu, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDESCRIPTOR_DID_F187_CODEP_ECU_PARTNUM  */ {
     /*  Block Start Address  */ 0x00000DECu, 
     /*  Data Length  */ 0x000Du, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDESCRIPTOR_DID_F188_FCA_ESLM_ECU_SW_NUM  */ {
     /*  Block Start Address  */ 0x00000DB3u, 
     /*  Data Length  */ 0x000Du, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDESCRIPTOR_DID_F18A_FCA_ESLM_ECU_SW_CAL_NUM  */ {
     /*  Block Start Address  */ 0x00000DD0u, 
     /*  Data Length  */ 0x000Cu, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDESCRIPTOR_DID_F18B_FCA_ESLM_ECU_SW_APP_NUM  */ {
     /*  Block Start Address  */ 0x00000DDEu, 
     /*  Data Length  */ 0x000Cu, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDESCRIPTOR_DID_F194_SUPPLIER_ECU_SW_PARTNUM  */ {
     /*  Block Start Address  */ 0x00000E18u, 
     /*  Data Length  */ 0x000Du, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDESCRIPTOR_DID_F195_SUPPLIER_ECU_SW_VERNUM  */ {
     /*  Block Start Address  */ 0x00000E27u, 
     /*  Data Length  */ 0x0004u, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDESCRIPTOR_DCMDSLRXTESTERSOURCEADDR  */ {
     /*  Block Start Address  */ 0x00000025u, 
     /*  Data Length  */ 0x0004u, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDESCRIPTOR_EXHAUSTREGULATIONTAN  */ {
     /*  Block Start Address  */ 0x00000031u, 
     /*  Data Length  */ 0x0008u, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDESCRIPTOR_METADATA  */ {
     /*  Block Start Address  */ 0x00000057u, 
     /*  Data Length  */ 0x0080u, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x0Au, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDESCRIPTOR_RESETRESPONSEFLAG  */ {
     /*  Block Start Address  */ 0x0000003Bu, 
     /*  Data Length  */ 0x0003u, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDESCRIPTOR_SECACCESSDELAYFLAG  */ {
     /*  Block Start Address  */ 0x00000016u, 
     /*  Data Length  */ 0x0003u, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDESCRIPTOR_SECACCESSINVALIDCOUNT  */ {
     /*  Block Start Address  */ 0x0000001Bu, 
     /*  Data Length  */ 0x0003u, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDESCRIPTOR_VALIDITYFLAGS  */ {
     /*  Block Start Address  */ 0x0000002Bu, 
     /*  Data Length  */ 0x0004u, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCK_APPLUPDATE  */ {
     /*  Block Start Address  */ 0x0000000Cu, 
     /*  Data Length  */ 0x0003u, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EACDD_GENERICBSWDID_2939_WAKEUPREASON  */ {
     /*  Block Start Address  */ 0x0000069Du, 
     /*  Data Length  */ 0x0014u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EACDD_GENERICBSWDID_FDF0_SLEEPPROCESS  */ {
     /*  Block Start Address  */ 0x000006B3u, 
     /*  Data Length  */ 0x0001u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EASWC_CONFIGMGRDID_2013_VIN_LOCK_STATUS  */ {
     /*  Block Start Address  */ 0x000006CCu, 
     /*  Data Length  */ 0x0001u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EASWC_CONFIGMGRDID_5201_PLANTMODE  */ {
     /*  Block Start Address  */ 0x000006B6u, 
     /*  Data Length  */ 0x0001u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EASWC_CONFIGMGRVIN_CURRENTVAL  */ {
     /*  Block Start Address  */ 0x000006B9u, 
     /*  Data Length  */ 0x0011u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EASWC_CONFIGMGRVIN_ODOMETERCNT  */ {
     /*  Block Start Address  */ 0x000006CFu, 
     /*  Data Length  */ 0x0001u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EASWC_CONFIGMGRVIN_ORIGINALVAL  */ {
     /*  Block Start Address  */ 0x00000E37u, 
     /*  Data Length  */ 0x0011u, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EASWC_DIDMGRDID_191D_POWERLATCH  */ {
     /*  Block Start Address  */ 0x000006D7u, 
     /*  Data Length  */ 0x0003u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EASWC_DIDMGRDID_2002_PROGREQFLAG  */ {
     /*  Block Start Address  */ 0x00000011u, 
     /*  Data Length  */ 0x0003u, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EASWC_DIDMGRDID_200A_IGONCOUNTER  */ {
     /*  Block Start Address  */ 0x000006DCu, 
     /*  Data Length  */ 0x0004u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EASWC_DIDMGRDID_200B_TIMESINCEFIRSTDTC  */ {
     /*  Block Start Address  */ 0x000006E2u, 
     /*  Data Length  */ 0x0006u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EASWC_DIDMGRDID_200C_TIMESINCEIGNONFIRSTDTC  */ {
     /*  Block Start Address  */ 0x000006EAu, 
     /*  Data Length  */ 0x0004u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EASWC_DIDMGRDID_200D_LASTCLEARDTCODO  */ {
     /*  Block Start Address  */ 0x000006F0u, 
     /*  Data Length  */ 0x0004u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EASWC_DIDMGRDID_FD33_MAGNATESTING  */ {
     /*  Block Start Address  */ 0x00000775u, 
     /*  Data Length  */ 0x000Cu, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EASWC_DIDMGRECU_LIFETIME  */ {
     /*  Block Start Address  */ 0x000006F6u, 
     /*  Data Length  */ 0x0006u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EASWC_PARTNUMMGRDID_FD31_EOLCODINGSTATE  */ {
     /*  Block Start Address  */ 0x000006FEu, 
     /*  Data Length  */ 0x0006u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EASWC_PROXIMGRPROXICONFIGTABLE  */ {
     /*  Block Start Address  */ 0x00000000u, 
     /*  Data Length  */ 0x0044u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ TRUE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EASWC_PROXIMGRPROXIERRORDATA  */ {
     /*  Block Start Address  */ 0x0000008Cu, 
     /*  Data Length  */ 0x000Bu, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EACALDATAPROVIDERSVSCAMCURRENTCALIBDATA  */ {
     /*  Block Start Address  */ 0x00000099u, 
     /*  Data Length  */ 0x00CAu, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EACALDATAPROVIDERSVSCAMEOLCALIBDATA  */ {
     /*  Block Start Address  */ 0x00000231u, 
     /*  Data Length  */ 0x00CAu, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EACALDATAPROVIDERSVSCAMOCCALIBDATA  */ {
     /*  Block Start Address  */ 0x000003C9u, 
     /*  Data Length  */ 0x0066u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EACALDATAPROVIDERSVSCAMSCCALIBDATA  */ {
     /*  Block Start Address  */ 0x00000499u, 
     /*  Data Length  */ 0x0066u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EASWC_PARTNUMMGRUSSSENSORMARRDATA  */ {
     /*  Block Start Address  */ 0x00000706u, 
     /*  Data Length  */ 0x003Au, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EASWC_DIDMGRDID_FD01_PREVCALIBDATACOPY  */ {
     /*  Block Start Address  */ 0x000005D9u, 
     /*  Data Length  */ 0x00C2u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EASWC_DIDMGRDID_FD42_FAILSAFEDEBUG  */ {
     /*  Block Start Address  */ 0x00000764u, 
     /*  Data Length  */ 0x0003u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EASWC_DIDMGRDID_REARBRAKEEVENT  */ {
     /*  Block Start Address  */ 0x000007FBu, 
     /*  Data Length  */ 0x002Eu, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EASWC_DIDMGRDID_SPMABRTEVENT  */ {
     /*  Block Start Address  */ 0x0000082Bu, 
     /*  Data Length  */ 0x003Au, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EACDD_IPCHANDLERFEATUREAP_HMI_NVMDATA  */ {
     /*  Block Start Address  */ 0x00000742u, 
     /*  Data Length  */ 0x0003u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EABLOCKCONFIGURATION_SECURELOGGROUP1  */ {
     /*  Block Start Address  */ 0x00000000u, 
     /*  Data Length  */ 0x01F8u, 
     /*  Partition Index  */ 0x0004u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EABLOCKCONFIGURATION_SECURELOGGROUP2  */ {
     /*  Block Start Address  */ 0x000001FAu, 
     /*  Data Length  */ 0x01F8u, 
     /*  Partition Index  */ 0x0004u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EASWC_DIDMGRDID_FD86_FUNCTIONALSETTINGS  */ {
     /*  Block Start Address  */ 0x00000747u, 
     /*  Data Length  */ 0x000Au, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EABLOCKDESCRIPTOR_FILEHEADER  */ {
     /*  Block Start Address  */ 0x0000056Bu, 
     /*  Data Length  */ 0x00B2u, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x09u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EABLOCKDESCRIPTOR_SERIALNUMBER  */ {
     /*  Block Start Address  */ 0x00000BBFu, 
     /*  Data Length  */ 0x0030u, 
     /*  Partition Index  */ 0x0000u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x0Au, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ TRUE
  }, 
   /*  EASWC_DIDMGRDID_CDD_IPCHANDLERFPA_SLOTDATA  */ {
     /*  Block Start Address  */ 0x00000783u, 
     /*  Data Length  */ 0x003Au, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EASAFETY_GUARDSAFESTAT2_RESETREASON  */ {
     /*  Block Start Address  */ 0x00000769u, 
     /*  Data Length  */ 0x0004u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EACALDATAPROVIDERFRONTCAMSERIALNUMBER  */ {
     /*  Block Start Address  */ 0x00000569u, 
     /*  Data Length  */ 0x000Cu, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ TRUE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EACALDATAPROVIDERLEFTCAMSERIALNUMBER  */ {
     /*  Block Start Address  */ 0x00000585u, 
     /*  Data Length  */ 0x000Cu, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ TRUE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EACALDATAPROVIDERREARCAMSERIALNUMBER  */ {
     /*  Block Start Address  */ 0x000005A1u, 
     /*  Data Length  */ 0x000Cu, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ TRUE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EACALDATAPROVIDERRIGHTCAMSERIALNUMBER  */ {
     /*  Block Start Address  */ 0x000005BDu, 
     /*  Data Length  */ 0x000Cu, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ TRUE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EABLOCKDESCRIPTOR_SECONDCOUNTER  */ {
     /*  Block Start Address  */ 0x00000000u, 
     /*  Data Length  */ 0x0006u, 
     /*  Partition Index  */ 0x0003u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EABLOCKDESCRIPTOR_SYSTEMTIMESTAMP  */ {
     /*  Block Start Address  */ 0x00000008u, 
     /*  Data Length  */ 0x0011u, 
     /*  Partition Index  */ 0x0003u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EABLOCKDESCRIPTOR_CERTIFICATEEXPIRED  */ {
     /*  Block Start Address  */ 0x0000001Bu, 
     /*  Data Length  */ 0x0003u, 
     /*  Partition Index  */ 0x0003u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EACDD_SAFETYCDD_PMICLASTRESETREASON_BISTSTATUS  */ {
     /*  Block Start Address  */ 0x0000076Fu, 
     /*  Data Length  */ 0x0004u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ TRUE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EASWC_DIDMGRDID_FD74_BUFFMARKCOMPERR  */ {
     /*  Block Start Address  */ 0x00000758u, 
     /*  Data Length  */ 0x0004u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EASWC_DIDMGRDID_FD74_PHY_TUNINGERR  */ {
     /*  Block Start Address  */ 0x0000075Eu, 
     /*  Data Length  */ 0x0004u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ FALSE
  }, 
   /*  EASWC_DTCMGRDTC_APAREQUESTSTS_PAMREQUESTSTS  */ {
     /*  Block Start Address  */ 0x00000753u, 
     /*  Data Length  */ 0x0003u, 
     /*  Partition Index  */ 0x0001u, 
     /*  Number of Instances  */ 0x01u, 
     /*  Number of Datasets  */ 0x01u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification  */ FALSE
  }
};
#define EA_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  EEP Function Pointer Tables
 *********************************************************************************************************************/

/**-- EEP Read, Write, Compare and Erase Wrapper Functions --**/ 
#define EA_START_SEC_CODE
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_MemMap */
EA_LOCAL FUNC (Std_ReturnType, EA_PRIVATE_CODE) Ea_Eep0_ReadWrapper(Ea_AddressType EepAddress, Ea_DataBufferPtrType TargetAddressPtr, uint16 Length); 
EA_LOCAL FUNC (Std_ReturnType, EA_PRIVATE_CODE) Ea_Eep0_WriteWrapper(Ea_AddressType EepAddress, Ea_DataBufferPtrType SourceAddressPtr, uint16 Length); 
EA_LOCAL FUNC (Std_ReturnType, EA_PRIVATE_CODE) Ea_Eep0_CompareWrapper(Ea_AddressType EepAddress, Ea_DataBufferPtrType DataBufferPtr, uint16 Length); 
EA_LOCAL FUNC (Std_ReturnType, EA_PRIVATE_CODE) Ea_Eep0_EraseWrapper(Ea_AddressType EepAddress, uint16 Length); 

 
EA_LOCAL FUNC (Std_ReturnType, EA_PRIVATE_CODE) Ea_Eep0_ReadWrapper(Ea_AddressType EepAddress, Ea_DataBufferPtrType TargetAddressPtr, uint16 Length) 
{
    return Eep_30_XXi2c01_Read((Eep_30_XXi2c01_AddressType) EepAddress, TargetAddressPtr, (Eep_30_XXi2c01_LengthType) Length); /* SBSW_EA_110 */
}
 
EA_LOCAL FUNC (Std_ReturnType, EA_PRIVATE_CODE) Ea_Eep0_WriteWrapper(Ea_AddressType EepAddress, Ea_DataBufferPtrType SourceAddressPtr, uint16 Length) /* PRQA S 3673 */ /* MD_EA_ConstPtr */ 
{
    return Eep_30_XXi2c01_Write((Eep_30_XXi2c01_AddressType) EepAddress, SourceAddressPtr, (Eep_30_XXi2c01_LengthType) Length); /* SBSW_EA_110 */
}
 
EA_LOCAL FUNC (Std_ReturnType, EA_PRIVATE_CODE) Ea_Eep0_CompareWrapper(Ea_AddressType EepAddress, Ea_DataBufferPtrType DataBufferPtr, uint16 Length) /* PRQA S 3673 */ /* MD_EA_ConstPtr */ 
{
    return Eep_30_XXi2c01_Compare((Eep_30_XXi2c01_AddressType) EepAddress, DataBufferPtr, (Eep_30_XXi2c01_LengthType) Length); /* SBSW_EA_110 */
}
 
EA_LOCAL FUNC (Std_ReturnType, EA_PRIVATE_CODE) Ea_Eep0_EraseWrapper(Ea_AddressType EepAddress, uint16 Length) 
{
    return Eep_30_XXi2c01_Erase((Eep_30_XXi2c01_AddressType) EepAddress, (Eep_30_XXi2c01_LengthType) Length);
}
 

#define EA_STOP_SEC_CODE
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**-- EEP Function Pointers --**/
#define EA_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
CONST(Ea_EepApiType, EA_PRIVATE_CONST) Ea_EepApi0 = 
{
   /*  Read Service  */ Ea_Eep0_ReadWrapper, 
   /*  Write Service  */ Ea_Eep0_WriteWrapper, 
   /*  Compare Service  */ Ea_Eep0_CompareWrapper, 
   /*  Erase Service  */ Ea_Eep0_EraseWrapper, 
   /*  Cancel Service  */ Eep_30_XXi2c01_Cancel, 
   /*  Get Status Service  */ Eep_30_XXi2c01_GetStatus, 
   /*  Get Job Result Service  */ Eep_30_XXi2c01_GetJobResult, 
   /*  Set Mode Service  */ Eep_30_XXi2c01_SetMode
}; 
 


/**********************************************************************************************************************
 *  NVM Callback Assignments
 *********************************************************************************************************************/
CONST(Ea_CbkJobEndNotificationType, EA_PRIVATE_CONST) Ea_CbkJobEndNotification = /* PRQA S 1533 */  /* MD_EA_ExternalDefinition */
  NULL_PTR;
CONST(Ea_CbkJobErrorNotificationType, EA_PRIVATE_CONST) Ea_CbkJobErrorNotification = /* PRQA S 1533 */  /* MD_EA_ExternalDefinition */
  NULL_PTR;

#define EA_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Justification for module-specific MISRA deviations:

 MD_EA_ExternalDefinition: rule 8.9
      Reason:     The function pointer is only used inside one translation unit of the static files. The assignment of 
                  this function pointer needs to be done seperately inside the generated file as the related Nvm callback function is configurable.
      Risk:       No risk. 
      Prevention: Program flow has been verified by component tests and review.

      
 MD_EA_ConstPtr: rule 8.13
      Reason:     Buffer pointer is not declared const in order to support both EEP interfaces with const and non-const buffers.
      Risk:       No risk. By using this wrapper functions without const pointers compiler warnings are solved.
      Prevention: Program flow has been verified by component tests and review.

*/

/* SBSW_JUSTIFICATION_BEGIN
    \ID SBSW_EA_110
      \DESCRIPTION EEP function is called with pointer parameter
      \COUNTERMEASURE \N  Pointer parameter is passed by caller of the function, thus caller has to ensure that pointer is valid.
SBSW_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: Ea_Cfg.c
 *********************************************************************************************************************/

