/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vXSpi_Regs_Int.h
 *        \brief  Register header of the vXSpi driver
 *
 *      \details  Defines macros and data types representing and abstracting the register layout of the
 *                Peripheral Interface.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VXSPI_REGS_INT_H)
# define VXSPI_REGS_INT_H

/**********************************************************************************************************************
 * HARDWARE SOFTWARE INTERFACE (HSI)
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Registers address offsets */
#define VXSPI_OSPI_CONFIG_REG_OFFSET                            (0x00u)

#define VXSPI_OSPI_DEV_INSTR_RD_CONFIG_REG_OFFSET               (0x04u)
#define VXSPI_OSPI_DEV_INSTR_WR_CONFIG_REG_OFFSET               (0x08u)
#define VXSPI_OSPI_DEV_SIZE_CONFIG_REG_OFFSET                   (0x14u)
#define VXSPI_OSPI_WRITE_COMPLETION_CTRL_REG_OFFSET             (0x38u)
#define VXSPI_OSPI_DEV_DELAY_REG_OFFSET                         (0x0Cu)
#define VXSPI_OSPI_RD_DATA_CAPTURE_REG                          (0x10u)

#define VXSPI_OSPI_FLASH_CMD_CTRL_REG_OFFSET                    (0x90u)
#define VXSPI_OSPI_FLASH_CMD_ADDR_REG_OFFSET                    (0x94u)
#define VXSPI_OSPI_FLASH_RD_DATA_LOWER_REG_OFFSET               (0xA0u)
#define VXSPI_OSPI_FLASH_WR_DATA_LOWER_REG_OFFSET               (0xA8u)

#define VXSPI_OSPI_SRAM_FILL_REG_OFFSET                         (0x2Cu)
#define VXSPI_OSPI_INDIRECT_READ_XFER_CTRL_REG_OFFSET           (0x60u)
#define VXSPI_OSPI_INDIRECT_READ_XFER_START_REG_OFFSET          (0x68u)
#define VXSPI_OSPI_INDIRECT_READ_XFER_NUM_BYTES_REG_OFFSET      (0x6Cu)
#define VXSPI_OSPI_INDIRECT_WRITE_XFER_CTRL_REG_OFFSET          (0x70u)
#define VXSPI_OSPI_INDIRECT_WRITE_XFER_START_REG_OFFSET         (0x78u)
#define VXSPI_OSPI_INDIRECT_WRITE_XFER_NUM_BYTES_REG_OFFSET     (0x7Cu)
#define VXSPI_OSPI_IND_AHB_ADDR_TRIGGER_REG_OFFSET              (0x1Cu)
#define VXSPI_OSPI_INDIRECT_TRIGGER_ADDR_RANGE_REG_OFFSET       (0x80u)

#define VXSPI_INDIRECT_TRIGGER_BASE_ADDRESS               (0x00000000u)

/* Register masks */
#define VXSPI_MSTR_BAUD_DIV_BIT_MASK                             (0xFu)
#define VXSPI_PERIPH_CS_LINES_BIT_MASK                           (0xFu)
#define VXSPI_SRAM_FILL_INDAC_READ_FLD_MASK               (0x0000FFFFu)

/* Register bit shift values */ 

/* bit shift values for the OSPI_CONFIG_REG */
#define VXSPI_IDLE_FLD                         (31u) /* bit shift value for the field to poll the Idle state of the OSPI Controller */
#define VXSPI_MSTR_BAUD_DIV_FLD                (19u) /* bit shift value for the field to set the baud rate Divider */
#define VXSPI_PERIPH_CS_LINES_FLD              (10u) /* bit shift value for the field for chip select */
#define VXSPI_ENB_DIR_ACC_CTLR_FLD              (7u) /* bit shift value for the field to enable the direct access controler (DAC) */

/* bit shift values for the OSPI_DEV_INSTR_RD_CONFIG_REG */    
#define VXSPI_DUMMY_RD_CLK_CYCLES_FLD          (24u) /* bit shift value for the field to configure read dummy cycles */
#define VXSPI_DATA_XFER_TYPE_EXT_MODE_FLD      (16u) /* bit shift value for the field to configure data data width */
#define VXSPI_ADDR_XFER_TYPE_STD_MODE_FLD      (12u) /* bit shift value for the field to configure address data width */
#define VXSPI_DDR_EN_FLD                       (10u) /* bit shift value for the field to enable double data rate */
#define VXSPI_INSTR_TYPE_FLD                    (8u) /* bit shift value for the field to configure command data width */
#define VXSPI_RD_OPCODE_NON_XIP_FLD             (0u) /* bit shift value for the field to configure the spi read opcode */

/* bit shift values for the OSPI_DEV_INSTR_WR_CONFIG_REG */ 
#define VXSPI_DUMMY_WR_CLK_CYCLES_FLD          (24u) /* bit shift value for the field to configure write dummy cycles */
#define VXSPI_WEL_DIS_FLD                       (8u) /* bit shift value for the field to disable automatic write enable */
#define VXSPI_WR_OPCODE_FLD                     (0u) /* bit shift value for the field to configure the spi write opcode */

/* bit shift values for the OSPI_DEV_SIZE_CONFIG_REG */  
#define VXSPI_BYTES_PER_DEVICE_PAGE_FLD         (4u) /* bit shift value for the field to configure the page size of the external flash device */
#define VXSPI_NUM_DEV_ADDR_BYTES_FLD            (0u) /* bit shift value for the field to configure the number of address bytes of the external flash device */

/* bit shift values for the OSPI_WRITE_COMPLETION_CTRL_REG */
#define VXSPI_DISABLE_POLLING_FLD              (14u) /* bit shift value for the field to disable the automatic polling of the status register of the external device */

/* bit shift values for the OSPI_FLASH_CMD_CTRL_REG */
#define VXSPI_CMD_OPCODE_FLD                   (24u) /* bit shift value for the field to configure the command opcode */
#define VXSPI_ENB_READ_DATA_FLD                (23u) /* bit shift value for the field to enable data to be received */
#define VXSPI_NUM_RD_DATA_BYTES_FLD            (20u) /* bit shift value for the field to confiugre the number of read data bytes */
#define VXSPI_ENB_COMD_ADDR_FLD                (19u) /* bit shift value for the field to enable to transmit an address */
#define VXSPI_NUM_ADDR_BYTES_FLD               (16u) /* bit shift value for the field to configure the number of address bytes */
#define VXSPI_ENB_WRITE_DATA_FLD               (15u) /* bit shift value for the field to enable data to be transmitted */
#define VXSPI_NUM_WR_DATA_BYTES_FLD            (12u) /* bit shift value for the field to configure the number of write data bytes */
#define VXSPI_NUM_DUMMY_CYCLES_FLD              (7u) /* bit shift value for the field to confiugre the number of dummy cycles */
#define VXSPI_CMD_EXEC_STATUS_FLD               (1u) /* bit shift value for the field to poll the command execution progress */
#define VXSPI_CMD_EXEC_FLD                      (0u) /* bit shift value for the field to trigger the command execution */

/* bit shift values for the OSPI_INDIRECT_READ_XFER_CTRL_REG and OSPI_INDIRECT_WRITE_XFER_CTRL_REG */
#define VXSPI_IND_OPS_DONE_STATUS_FLD           (5u) /* bit shift value for the field to poll the INDAC done status */
#define VXSPI_CANCEL_FLD                        (1u) /* bit shift value for the field to cancel an INCDAC operation */
#define VXSPI_START_FLD                         (0u) /* bit shift value for the field to start an INDAC operation */

/* bit shift values for the OSPI_SRAM_FILL_REG */
#define VXSPI_SRAM_FILL_INDAC_WRITE_FLD        (16u) /* bit shift value for the field to read the current fill level of SRAM Indirect Write partition */

/* other macros */
#define VXSPI_READ_CMD_INIT_VALUE               (0u) /* Invalid value for read command for initialization */
#define VXSPI_WRITE_CMD_INIT_VALUE              (0u) /* Invalid value for write command for initialization */
#define VXSPI_MAX_DATA_LENGTH_STIG_MODE         (4u) /* Maximal number of data bytes which can be transmitted and received in STIG mode */

#define VXSPI_REG_VAL_TRUE                      (1u) /* BitValue 1 */
#define VXSPI_REG_VAL_FALSE                     (0u) /* BitValue 0 */

#define SRAM_MAX_ALLOWED_FILL_LEVEL          (0x80u) /* Maximal allowed number of 4 byte places of data to be left in the SRAM */
#define VXSPI_TRIGGER_ADDR_RANGE             (0x07u) /* Indirect Addres Range is 2^7 = 128 Bytes wide */

#endif /* VXSPI_REGS_INT_H */

/**********************************************************************************************************************
 *  END OF FILE: vXSpi_Regs_Int.h
 *********************************************************************************************************************/
