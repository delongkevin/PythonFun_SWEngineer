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
 *  \file     Fls_Spi_Intf.h
 *
 *  \brief    This file contains interface header for FLS MCAL driver
 *
 */

#ifndef SPI_H
#define SPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"


/**
 * Common SPI_control command code reservation offset.
 * SPI driver implementations should offset command codes with SPI_CMD_RESERVED
 * growing positively
 *
 * Example implementation specific command codes:
 * @code
 * #define SPIXYZ_COMMAND0         SPI_CMD_RESERVED + 0
 * #define SPIXYZ_COMMAND1         SPI_CMD_RESERVED + 1
 * @endcode
 */
#define SPI_CMD_RESERVED            (32U)

/**
 * \brief   An error status code returned by SPI_control() for undefined
 * command codes.
 *
 * SPI_control() returns SPI_STATUS_UNDEFINEDCMD if the control code is not
 * recognized by the driver implementation.
 */
#define E_STATUS_UNDEFINED (0x02U)

/**
 *  @brief    Wait forever define
 */
#define SPI_WAIT_FOREVER (~(0U))

/**
 *  @brief      A handle that is returned from a SPI_open() call.
 */
typedef struct SPI_Config_s      *SPI_Handle;

/**
 *  @brief      Status codes that are set by the SPI driver.
 */
typedef enum SPI_Status_s {
    SPI_TRANSFER_COMPLETED = 0,
    SPI_TRANSFER_STARTED,
    SPI_TRANSFER_CANCELED,
    SPI_TRANSFER_FAILED,
    SPI_TRANSFER_CSN_DEASSERT,
    SPI_TRANSFER_TIMEOUT
} SPI_Status;

/**
 *  @brief
 *  A ::SPI_Transaction data structure is used with SPI_transfer(). It indicates
 *  how many ::SPI_FrameFormat frames are sent and received from the buffers
 *  pointed to txBuf and rxBuf.
 *  The arg variable is an user-definable argument which gets passed to the
 *  ::SPI_CallbackFxn when the SPI driver is in ::SPI_MODE_CALLBACK.
 */
typedef struct SPI_Transaction_s {
    /* User input (write-only) fields */
    uint32     count;
    /**< Number of frames for this transaction */
    void      *txBuf;
    /**< void * to a buffer with data to be transmitted */
    void      *rxBuf;
    /**< void * to a buffer to receive data */
    void      *arg;
    /**< Argument to be passed to the callback function */

    /* User output (read-only) fields */
    SPI_Status status;
    /**< Status code set by SPI_transfer */
} SPI_Transaction;

/**
 *  @brief
 *  Definitions for various SPI modes of operation.
 */
typedef enum SPI_Mode_s {
    SPI_MASTER      = 0,
    /**< SPI in master mode */
    SPI_SLAVE       = 1
    /**< SPI in slave mode */
} SPI_Mode;

/**
 *  @brief
 *  Definitions for various SPI data frame formats.
 */
typedef enum SPI_FrameFormat_s {
    SPI_POL0_PHA0   = 0,
    /**< SPI mode Polarity 0 Phase 0 */
    SPI_POL0_PHA1   = 1,
    /**< SPI mode Polarity 0 Phase 1 */
    SPI_POL1_PHA0   = 2,
    /**< SPI mode Polarity 1 Phase 0 */
    SPI_POL1_PHA1   = 3,
    /**< SPI mode Polarity 1 Phase 1 */
    SPI_TI          = 4,
    /**< TI mode */
    SPI_MW          = 5
    /**< Micro-wire mode */
} SPI_FrameFormat;

/**
 *  @brief
 *
 *  SPI transfer mode determines the whether the SPI controller operates
 *  synchronously or asynchronously. In ::SPI_MODE_BLOCKING mode SPI_transfer()
 *  blocks code execution until the SPI transaction has completed. In
 *  ::SPI_MODE_CALLBACK SPI_transfer() does not block code execution and instead
 *  calls a ::SPI_CallbackFxn callback function when the transaction has
 *  completed.
 */
typedef enum SPI_TransferMode_s {
    /**
     * SPI_transfer() blocks execution. This mode can only be used when called
     * within a Task context
     */
    SPI_MODE_BLOCKING,
    /**
     * SPI_transfer() does not block code execution and will call a
     * ::SPI_CallbackFxn. This mode can be used in a Task, Swi, or Hwi context.
     */
    SPI_MODE_CALLBACK
} SPI_TransferMode;

/**
 *  @brief SPI Parameters
 *
 *  SPI Parameters are used to with the SPI_open() call. Default values for
 *  these parameters are set using SPI_Params_init().
 *
 *  @sa         SPI_Params_init()
 */
typedef struct SPI_Params_s {
    SPI_TransferMode    transferMode;
    /**< Blocking or Callback mode */
    uint32            transferTimeout;
    /**< Transfer timeout in system ticks (Not supported with all implementations */
    SPI_Mode            mode;
    /**< Master or Slave mode */
    uint32            bitRate;
    /**< SPI bit rate in Hz */
    uint32            dataSize;
    /**< SPI data frame size in bits */
    SPI_FrameFormat     frameFormat;
    /**< SPI frame format */
    void               *custom;
    /**< Custom argument used by driver implementation */
} SPI_Params;


/**
 *  @brief SPI Global configuration
 *
 *  The SPI_Config structure contains a set of pointers used to characterize
 *  the SPI driver implementation.
 *
 *  This structure needs to be defined before calling SPI_init() and it must
 *  not be changed thereafter.
 *
 *  @sa     SPI_init()
 */
typedef struct SPI_Config_s {
    void               *object;
    /**< Pointer to a driver specific data object */
    void         const *hwAttrs;
    /**< Pointer to a driver specific hardware attributes structure */
} SPI_Config;

#define SPI_MAX_CONFIG_CNT (2U)
typedef SPI_Config SPI_config_list[SPI_MAX_CONFIG_CNT];

/**
 *  @brief  Function performs implementation specific features on a given
 *          SPI_Handle.
 *
 *  @pre    SPI_open() has to be called first.
 *
 *  @param  handle      A SPI handle returned from SPI_open()
 *
 *  @param  cmd         A command value defined by the driver specific
 *                      implementation
 *
 *  @param  arg         An optional R/W (read/write) argument that is
 *                      accompanied with cmd
 *
 *  @return Implementation specific return codes. Negative values indicate
 *          unsuccessful operations.
 *
 *  @sa     SPI_open()
 */
extern Std_ReturnType SPI_control(SPI_Handle handle, uint32 cmd, void *arg);

/**
 *  @brief  Function to close a SPI peripheral specified by the SPI handle
 *
 *  @pre    SPI_open() has to be called first.
 *
 *  @param  handle A SPI handle returned from SPI_open()
 *
 *  @sa     SPI_open()
 */
extern void SPI_close(SPI_Handle handle);

/**
 *  @brief  This function initializes the SPI module.
 *
 *  @pre    The SPI_config structure must exist and be persistent before this
 *          function can be called. This function must also be called before
 *          any other SPI driver APIs. This function call does not modify any
 *          peripheral registers.
 */
extern SPI_Handle SPI_init(void);

/**
 *  @brief  This function opens a given SPI peripheral.
 *
 *  @pre    SPI controller has been initialized using SPI_init()
 *
 *  @param  idx           Logical peripheral number for the SPI indexed into
 *                        the SPI_config table
 *
 *  @param  params        Pointer to an parameter block, if NULL it will use
 *                        default values. All the fields in this structure are
 *                        RO (read-only).
 *
 *  @return A SPI_Handle on success or a NULL on an error or if it has been
 *          opened already.
 *
 *  @sa     SPI_init()
 *  @sa     SPI_close()
 */
extern SPI_Handle SPI_open(SPI_Handle handle, SPI_Params *params);

/**
 *  @brief  Function to initialize the SPI_Params struct to its defaults
 *
 *  @param  params      An pointer to SPI_Params structure for
 *                      initialization
 *
 *  Defaults values are:
 *      transferMode        = SPI_MODE_BLOCKING
 *      transferTimeout     = SPI_WAIT_FOREVER
 *      transferCallbackFxn = NULL
 *      mode                = SPI_MASTER
 *      bitRate             = 1000000 (Hz)
 *      dataSize            = 8 (bits)
 *      frameFormat         = SPI_POL0_PHA0
 */
extern void SPI_Params_init(SPI_Params *params);

/**
 *  @brief  Function to perform SPI transactions
 *
 *  If the SPI is in ::SPI_MASTER mode, it will immediately start the
 *  transaction. If the SPI is in ::SPI_SLAVE mode, it prepares itself for a
 *  transaction with a SPI master.
 *
 *  In ::SPI_MODE_BLOCKING, SPI_transfer will block task execution until the
 *  transaction has completed.
 *
 *  In ::SPI_MODE_CALLBACK, SPI_transfer() does not block task execution and
 *  calls a ::SPI_CallbackFxn. This makes the SPI_tranfer() safe to be used
 *  within a Task, Swi, or Hwi context. The ::SPI_Transaction structure must
 *  stay persistent until the SPI_transfer function has completed*
 *
 *  @param  handle      A SPI_Handle
 *
 *  @param  spiTrans    A pointer to a SPI_Transaction. All of the fields within
 *                      transaction except SPI_Transaction.count and
 *                      SPI_Transaction.status are WO (write-only) unless
 *                      otherwise noted in the driver implementations. If a
 *                      transaction timeout has occured, SPI_Transaction.count
 *                      will contain the number of frames that were transferred.
 *
 *  @return TRUE if started successfully; else FALSE
 *
 *  @sa     SPI_open
 *  @sa     SPI_transferCancel
 */
extern boolean SPI_transfer(SPI_Handle handle, SPI_Transaction *spiTrans);

#ifdef __cplusplus
}
#endif

#endif /* _SPI_H */

/* @} */
