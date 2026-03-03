/*
*
* Copyright (c) 2020 Texas Instruments Incorporated
*
* All rights reserved not granted herein.
*
* Limited License.
*
* Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
* license under copyrights and patents it now or hereafter owns or controls to make,
* have made, use, import, offer to sell and sell ("Utilize") this software subject to the
* terms herein.  With respect to the foregoing patent license, such license is granted
* solely to the extent that any such patent is necessary to Utilize the software alone.
* The patent license shall not apply to any combinations which include this software,
* other than combinations with devices manufactured by or for TI ("TI Devices").
* No hardware patent is licensed hereunder.
*
* Redistributions must preserve existing copyright notices and reproduce this license
* (including the above copyright notice and the disclaimer and (if applicable) source
* code license limitations below) in the documentation and/or other materials provided
* with the distribution
*
* Redistribution and use in binary form, without modification, are permitted provided
* that the following conditions are met:
*
* *       No reverse engineering, decompilation, or disassembly of this software is
* permitted with respect to any software provided in binary form.
*
* *       any redistribution and use are licensed by TI for use only with TI Devices.
*
* *       Nothing shall obligate TI to provide you with source code for the software
* licensed and provided to you in object code.
*
* If software source code is provided to you, modification and redistribution of the
* source code are permitted provided that the following conditions are met:
*
* *       any redistribution and use of the source code, including any resulting derivative
* works, are licensed by TI for use only with TI Devices.
*
* *       any redistribution and use of any object code compiled from the source code
* and any resulting derivative works, are licensed by TI for use only with TI Devices.
*
* Neither the name of Texas Instruments Incorporated nor the names of its suppliers
*
* may be used to endorse or promote products derived from this software without
* specific prior written permission.
*
* DISCLAIMER.
*
* THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL TI AND TI'S LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
* OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
* OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

/**
 *  \file     Fls_Ospi.h
 *
 *  \brief    This file contains interface header for FLS MCAL driver
 *
 */

#ifndef FLS_OSPI_H
#define FLS_OSPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "Fls_Spi_Intf.h"
#include "Fls_Cfg.h"
#include <ti/csl/src/ip/ospi/V0/cslr_ospi.h>
#include <ti/csl/src/ip/ospi/V0/csl_ospi.h>
#include <ti/osal/osal.h>



/**
 *  \brief  Set SPI controller into CONFIG Mode
 *
 *  Command code used with SPI_control()
 */
#define SPI_V0_CMD_SET_CFG_MODE        (SPI_CMD_RESERVED + 0U)


/**
 *  \brief  Set SPI controller into Transfer Mode
 *
 *  Command code used with SPI_control()
 */
#define SPI_V0_CMD_SET_XFER_MODE       (SPI_CMD_RESERVED + 1U)

/**
 *  \brief  Set direction of data flow when in memory mapped mode.
 *
 *  Conventional SPI_transfer() calls no not require a read or write direction
 *  as SPI operates a in full duplex mode. This function is only used in
 *  combination with memory mapped mode where a read or write direction is
 *  required with SPI flash memory.
 */
#define SPI_V0_CMD_XFER_MODE_RW        (SPI_CMD_RESERVED + 2U)

/**
 *  \brief  Set flash specific command when in indirect transfer mode.
 *
 */
#define SPI_V0_CMD_XFER_OPCODE         (SPI_CMD_RESERVED + 3U)

/**
 *  \brief  Set number of lines configured for RX/TX operation.
 *
 */
#define SPI_V0_CMD_SET_XFER_LINES      (SPI_CMD_RESERVED + 4U)

/**
 *  \brief  Set number of dummy clock cycles for read operation.
 *
 */
#define SPI_V0_CMD_RD_DUMMY_CLKS       (SPI_CMD_RESERVED + 5U)

/**
 *  \brief  Set command to configure phy.
 *
 */
#define SPI_V0_CMD_CFG_PHY             (SPI_CMD_RESERVED + 6U)

/**
 *  \brief  Set command to enable DDR mode
 *
 */
#define SPI_V0_CMD_ENABLE_DDR          (SPI_CMD_RESERVED + 7U)

/**
 *  \brief  Set command to enable XIP mode
 *
 */
#define SPI_V0_CMD_CFG_XIP          (SPI_CMD_RESERVED + 8U)

/**
 *  \brief  Set command to disable DDR mode
 *
 */
#define SPI_V0_CMD_ENABLE_SDR          (SPI_CMD_RESERVED + 9U)

/*
 *
 *  \brief  Set extended opcodes when in indirect transfer mode.
 */
#define SPI_V0_CMD_XFER_OPCODE_EXT     (SPI_CMD_RESERVED + 10U)

/*
 *
 *  \brief  Set extended opcode command read dummy cycles.
 */
#define SPI_V0_CMD_EXT_RD_DUMMY_CLKS   (SPI_CMD_RESERVED + 11U)

/*
 *
 *  \brief  Set read capture delay.
 */
#define SPI_V0_CMD_CFG_RD_DELAY        (SPI_CMD_RESERVED + 12U)

/*
 *
 *  \brief  Set dummy cycles in flash device.
 */
#define SPI_V0_CMD_CFG_DUMMY_CYCLE     (SPI_CMD_RESERVED + 13U)



/**
 *  \brief      Type of the SPI transaction.
 */
typedef enum SPI_TransactionType_e {
    SPI_TRANSACTION_TYPE_READ = 0,
    /**< Read transaction */
    SPI_TRANSACTION_TYPE_WRITE
    /**< Write transaction */
} SPI_TransactionType;

/**
 *  \brief  OSPI controller modes.
 */
typedef enum OSPI_OperMode_e {
    OSPI_OPER_MODE_CFG = 0U,
    /**< OSPI controller is in config mode */
    OSPI_OPER_MODE_IND_XFER,
    /**< OSPI controller is in indirect transfer mode */
    OSPI_OPER_MODE_DAC_XFER,
    /**< OSPI controller is in direct transfer mode */
} OSPI_OperMode;


/**
 *  \brief  Number of lines used for OSPI read/write transaction
 */
typedef enum OSPI_xferLines_e {
    OSPI_XFER_LINES_SINGLE = 0U,
    /**< Single line is used */
    OSPI_XFER_LINES_DUAL,
    /**< Two lines are used */
    OSPI_XFER_LINES_QUAD,
    /**< Four lines are used */
    OSPI_XFER_LINES_OCTAL
    /**< Four lines are used */
} OSPI_xferLines;

/**
 *  \brief  OSPI IP V0 Hardware attributes
 */
typedef struct OSPI_HwAttrs_s {
    const CSL_ospi_flash_cfgRegs *baseAddr;
    /**< OSPI IP V0 Peripheral base address. */
    uint32       dataAddr;
    /**< OSPI Data base address */
    uint32        funcClk;
    /**< OSPI IP V0 functional clock */
    uint32        intrNum;
    /**< OSPI IP V0 Peripheral CorePac interrupt vector */
    uint32        eventId;
    /**< OSPI IP V0 Peripheral CorePac intc event ID */
    OSPI_OperMode   operMode;
    /**< OSPI controller mode */
    uint32        chipSelect;
    /**< OSPI chip select number */
    CSL_OspiClkMode frmFmt;
    /**< OSPI frame format */
    uint32        devDelays[4];
    /**< OSPI device delays (CSSOT, CSEOT, CSDADS and CSDA delays) */
    uint32        pageSize;
    /**< OSPI device page size in bytes */
    uint32        blkSize;
    /**< OSPI device block size is 2 ^ blkSize (bytes) */
    OSPI_xferLines  xferLines;
    /**< Number of lines used for OSPI reading/writing */
    boolean       intrEnable;
    /**< Enable interrupts. */
    boolean       dacEnable;
    /**< Direct Access Controller Enable */
    boolean       dmaEnable;
    /**< Enable DMA */
    boolean       phyEnable;
    /**< Enable PHY */
    uint32        rdDataCapDelay;
    /**< Read data capture delay in # of ref_clk cycles */
    boolean       dtrEnable;
    /**< Enable DTR protocol */
    boolean       xipEnable;
    /**< XIP Enable */
    uint32        csSotDelay;
    /**< Chip Select Start of Transfer delay in # of ref_clk cycles  */
    uint32        baudRateDiv;
    /**< Master mode baud rate divisor value */
    boolean       tuneDone;
} OSPI_HwAttrs;


/**
 *  \brief  OSPI IP V0 driver object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct OSPI_Object_s {
    void             *transferComplete;
    /**< Transfer complete lock */
    void             *hwi;
    /**< Hardware interrupt object */
    uint32          waitTimeout;
    /**< Wait time out */
    SPI_Params        ospiParams;
    /**< input parameters */
    uint32          transactionType;
    /**< Read or Write Transaction */
    uint32          transferCmd;
    /**< Transfer command */
    uint32          ospiMode;
    /**< Config or Memory map mode */
    uint32          xferLines;
    /**< Number of transfer Lines */
    uint32          rdDummyClks;
    /**< Number of dummy clock cycles for read op */
    uint32          extRdDummyClks;
    /* Number of dummy clock cycles for extended opcode command read op */
    uint32          intrPollMode;
    /**< Interrupt or polling mode */
    SPI_TransferMode  transferMode;
    /**< Transfer mode */
    SPI_Transaction  *transaction;
    /**< Transaction structure */
    uint8          *writeBufIdx;
    /**< Internal inc. writeBuf index */
    uint32          writeCountIdx;
    /**< Internal dec. writeCounter */
    uint8          *readBufIdx;
    /**< Internal inc. readBuf index */
    uint32          readCountIdx;
    /**< Internal dec. readCounter */
    boolean         isOpen;
    /**< flag to indicate module is open */
    uint32          rdStatusCmd;
    /**< flash command to read status register */

} OSPI_Object;

extern void       OSPI_init(SPI_Handle handle);
extern void       OSPI_close(SPI_Handle handle);
extern Std_ReturnType    OSPI_control(SPI_Handle handle, uint32 cmd, const void *arg);
extern boolean       OSPI_transfer(SPI_Handle handle,
                                   SPI_Transaction *transaction_xfer);
extern void       OSPI_transferCancel(SPI_Handle handle);
extern SPI_Handle OSPI_open(SPI_Handle handle, const SPI_Params *params);
extern void       OSPI_hwi(SPI_Handle handle);
extern void       OSPI_hwi_2(SPI_Handle handle);



#ifdef __cplusplus
}
#endif

#endif /* FLS_OSPI_H */
