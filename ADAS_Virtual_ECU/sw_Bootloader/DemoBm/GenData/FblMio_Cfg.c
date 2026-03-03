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
 *            Module: FblMio_vMemAccM
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FblMio_Cfg.c
 *   Generation Time: 2024-11-25 13:00:27
 *           Project: DemoBm - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/


#define FBLMIO_CFG_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"
#include "vMemAccM.h"
#include "vMem_30_vXSpi_Nand.h"

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

V_MEMROM0 V_MEMROM1 tFblMemInstanceMapping V_MEMROM2 FblMemInstanceMapping[FBL_MIO_SIZE_OF_INSTANCE_MAPPING] =
{
  {VMEMACCM_VMEM_30_VXSPI_NAND_VMEMINSTANCE_EXTFLASH, FALSE, 0xFFu}
};

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/*-- FlashWrapper MemoryDevice Init/Deinit functions -----------------------------------------------------------------*/

IO_ErrorType FlashWrapperDriver_InitSync(void * address) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 1 */ /* MD_MSR_DummyStmt */
   (void)address;
#endif



   return IO_E_OK;
}

IO_ErrorType FlashWrapperDriver_DeinitSync(void * address) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 1 */ /* MD_MSR_DummyStmt */
   (void)address;
#endif


   return IO_E_OK;
}

/***********************************************************************************************************************
 *  STUB FUNCTIONS
 **********************************************************************************************************************/
/*-- FlashWrapper MemoryDevice stub ----------------------------------------------------------------------------------*/
IO_ErrorType FlashWrapperDriver_RWriteSync(IO_MemPtrType writeBuffer, IO_SizeType writeLength, IO_PositionType writeAddress) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 3 */ /* MD_MSR_DummyStmt */
   (void)writeBuffer;
   (void)writeLength;
   (void)writeAddress;
#endif

   return IO_E_NOT_OK;
}

IO_ErrorType FlashWrapperDriver_REraseSync(IO_SizeType eraseLength, IO_PositionType eraseAddress) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 2 */ /* MD_MSR_DummyStmt */
   (void)eraseLength;
   (void)eraseAddress;
#endif

   return IO_E_NOT_OK;
}

IO_ErrorType FlashWrapperDriver_RReadSync(IO_MemPtrType readBuffer, IO_SizeType readLength, IO_PositionType readAddress) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 3 */ /* MD_MSR_DummyStmt */
   (void)readBuffer;
   (void)readLength;
   (void)readAddress;
#endif

   return IO_E_NOT_OK;
}

/***********************************************************************************************************************
 *  END OF FILE: FblMio_Cfg.c
 **********************************************************************************************************************/

