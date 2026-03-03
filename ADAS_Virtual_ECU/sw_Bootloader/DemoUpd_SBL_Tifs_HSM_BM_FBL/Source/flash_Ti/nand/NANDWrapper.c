/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Flash Driver wrapper for TI NAND
 *
 *  \note         
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 
 *  \endverbatim
 */
/**********************************************************************************************************************/


/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "nand.h"
#include "..\include\board_flash.h"
#include "fbl_inc.h"
/* NAND function table for NAND OSPI interface implementation */
/*const NAND_FxnTable Nand_ospiFxnTable =
{
    &Nand_ospiOpen,
    &Nand_ospiClose,
    &Nand_ospiRead,
    &Nand_ospiWrite,
    &Nand_ospiErase,
};*/


/*NAND_Config Nand_config[BOARD_FLASH_NAND_INTF_MAX] =
{
    {
        NULL
    },
    {
        NULL
    },
    {
        &Nand_ospiFxnTable
    },

};*/
extern NAND_Config Nand_config[BOARD_FLASH_NAND_INTF_MAX];


/***********************************************************************************************************************
 *   VERSION
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/
#define NAND_BLOCK_SIZE (256U * 1024U)
#define BOARD_FLASH_NAND_INTF_MAX 3
#define BOARD_FLASH_NAND_OSPI 2
#define BOARD_OSPI_INSTANCE 0

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

volatile static int debug_Var=1;
/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *   LOCAL FUNCTIONS
 **********************************************************************************************************************/

static void *boardHandlewrapper = NULL;
Board_flashHandle OSPIHandle;
void *dbg_ospi_initialize(void);
/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  NandWrapperDriver_InitSync
 **********************************************************************************************************************/
/*! \brief       Initializes the flash driver
 **********************************************************************************************************************/
IO_ErrorType NandWrapperDriver_InitSync( void * address )
{
  uint32 nandIntf;
  uint32 portNum;
  void * params;
  unsigned long handle;

  (void) address;

	/*while (debug_Var == 1)
	{
	}*/

  /*SBL_ospiInit(&boardHandlewrapper);*/
  boardHandlewrapper = dbg_ospi_initialize();

  OSPIHandle = *(const Board_flashHandle *)boardHandlewrapper;

  return kFblOk;
}

/***********************************************************************************************************************
 *  NandWrapperDriver_DeInitSync
 **********************************************************************************************************************/
/*! \brief       Deinitializes the flash driver
 **********************************************************************************************************************/
IO_ErrorType NandWrapperDriver_DeinitSync( void* address )
{

  (void) address;
  (void) NAND_close(OSPIHandle);

  return kFblOk;

}

/***********************************************************************************************************************
 *  FlashWrapperDriver_RWriteSync
 **********************************************************************************************************************/
/*! \brief       Writes data to flash memory.
 **********************************************************************************************************************/
IO_ErrorType NandWrapperDriver_RWriteSync( IO_MemPtrType writeBuffer, IO_SizeType writeLength, IO_PositionType writeAddress )
{
  IO_ErrorType retVal;
  uint32_t   writeMode = 1; /*OSPI_FLASH_OCTAL_PAGE_PROG;*/

  /*retVal = NAND_write(OSPIHandle, writeAddress, writeLength, writeBuffer);*/
  retVal = Board_flashWrite(OSPIHandle, writeAddress, &writeBuffer[0], writeLength, (void *)(&writeMode));


  return retVal;
}

/***********************************************************************************************************************
 *  FlashWrapperDriver_REraseSync
 **********************************************************************************************************************/
/*! \brief       Erases area in flash memory.
 *  \details     This function erases one or more logical sectors in flash memory.
 *  \pre         Flash driver is initialized.
 *  \param[in]   eraseLength Length of memory to be erased. The length has to be aligned to the length
 *               of one or more flash sectors. The flash area has to be contiguous - gaps in must not
 *               be included.
 *  \param[in]   eraseAddress Start address of erase area. The start address has to be the start
 *               address of a logical flash sector.
 *  \return      Reports erase success or error code.
 **********************************************************************************************************************/
IO_ErrorType NandWrapperDriver_REraseSync(IO_SizeType eraseLength, IO_PositionType eraseAddress)
{
    IO_ErrorType retVal;
    uint32 blockNum;
    uint32 pageNum,numBlocks;
    IO_PositionType localEraseAddr;

    //set the sector size in vMem of the NANDWrapper driver to 256KB


    //what if our eraseaddress and length goes over the boundary of a block?
    //allign the eraseaddress to the block size
    localEraseAddr = eraseAddress - (eraseAddress % NAND_BLOCK_SIZE);

    uint32 totalEraseLength = ((eraseAddress + eraseLength) - localEraseAddr);



    if(totalEraseLength > NAND_BLOCK_SIZE)
    {
        numBlocks = (totalEraseLength-1)/NAND_BLOCK_SIZE + 1;
    } 
    else
    {
        numBlocks = 1;
    }

    for( int i = 0; i < numBlocks ; i++)
    {
        //some logic to get the block information instead from address and length
        Board_flashOffsetToBlkPage(OSPIHandle, localEraseAddr, &blockNum, &pageNum);
        /*retVal = NAND_erase(OSPIHandle, blockNum);*/
        retVal = Board_flashEraseBlk(OSPIHandle, blockNum);
        localEraseAddr += NAND_BLOCK_SIZE;
    }

    return retVal;
}

/***********************************************************************************************************************
 *  FlashWrapperDriver_RReadSync
 **********************************************************************************************************************/
/*! \brief       Reads data from flash memory.
 *  \details     This function reads data from flash memory. It can be configured to report ECC errors to the
 *               calling function.
 *  \param[out]  readBuffer Pointer to read target buffer. The buffer size must be at least readLength Bytes.
 *  \param[in]   readLength Size of data to be read.
 *  \param[in]   readAddress Start address of data to be read.
 *  \return      Reports read success or error code.
 **********************************************************************************************************************/
IO_ErrorType NandWrapperDriver_RReadSync( IO_MemPtrType readBuffer, IO_SizeType readLength, IO_PositionType readAddress )
{
  IO_ErrorType retVal;
  uint32_t     readMode = 1;

  /*retVal = NAND_read(OSPIHandle, readAddress, readLength, readBuffer);*/
   retVal = Board_flashRead(OSPIHandle, readAddress, readBuffer, readLength, (void *)(&readMode));


  return retVal;
}

/***********************************************************************************************************************
 *  END OF FILE: FBL_FLIO.C
 **********************************************************************************************************************/
