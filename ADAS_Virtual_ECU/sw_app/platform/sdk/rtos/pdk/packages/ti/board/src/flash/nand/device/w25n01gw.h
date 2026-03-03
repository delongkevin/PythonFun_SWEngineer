/**
 * NOTE: This file did not originate at TI, and was more or less copied from TI
 * code!!! (need to check about copyright stuff)
 */

/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 *
 * \file  w25n01gw.h
 *
 * \brief This file contains W25N01GW NAND device definitions
 *
 *****************************************************************************/
#ifndef W25N01GW_H_
#define W25N01GW_H_

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************
 **                       Macro Definitions
 **************************************************************************/

/** \brief FLASH device specific items (note: sizes are in bytes) */
#define NAND_BLOCK_SIZE               (64U * 2048U)            /* 64 pages of 2048 bytes */
#define NAND_SECTOR_SIZE              (0U)                     /* TO DO */
#define NAND_SIZE                     (128U * 1024U * 1024U)   /* 128 MiB */
#define NAND_NUM_SECTORS              (0U)                          /* TO DO */
#define NAND_NUM_BLOCKS               (NAND_SIZE / NAND_BLOCK_SIZE) /* 1024 */
#define NAND_PAGE_SIZE                (2U * 1024U)
#define NAND_NUM_PAGES_PER_BLOCK      (NAND_BLOCK_SIZE / NAND_PAGE_SIZE)
#define NAND_SPARE_AREA_SIZE          (64U)
#define NAND_SPARE_AREA_BB_OFFSET     (0U) /* First 2 bits of spare area */
#define NAND_ECC_ALGO_SUPPORTED       (0U) /* Supported, but not used for now */
#define NAND_ECC_OFFSET_VALUE         (0xC) /* ECC offset in spare area */
#define NAND_ECC_BYTE_COUNT           (4U)  /* 4-Byte ECC */

/** \brief Flash device commands */
#define NAND_CMD_RSTEN                (0x66U)
#define NAND_CMD_RST_MEM              (0x99U)
#define NAND_CMD_RDID                 (0x9FU)
#define NAND_CMD_RDSR                 (0x0FU)
#define NAND_CMD_WRITE_STATUS         (0x1FU)
#define NAND_CMD_WRITE_VCR            (0x81U)
#define NAND_CMD_WREN                 (0x06U)
#define NAND_CMD_BLOCK_ERASE          (0xD8U)
#define NAND_CMD_PAGE_READ            (0x13U)
#define NAND_CMD_READ                 (0x03U)
#define NAND_CMD_FAST_READ            (0x0BU)
#define NAND_CMD_QUAD_IO_FAST_RD      (0xEBU)
#define NAND_CMD_QUAD_FAST_READ_DTR   (0xEDU)  /* Not working yet */
#define NAND_CMD_PAGE_PROG            (0x84U)
#define NAND_CMD_PAGE_PROG_EXECUTE    (0x10U)

/* Use Quad Random Load Program Data for writes (rather than 0x32) because it doesn't overwrite the bytes not specifcally addressed by a
   transfer with 0xFFs. This prevents sporatic CS de-assertions at the OSPI controller from corrupting writes when the CS is re-asserted
   and a new write command is sent. If we ever resolve the CS de-assertions so that all writes are uninterrupted, we can maybe revert
   this to 0x32. */ 
#define NAND_CMD_EXT_QUAD_FAST_PROG   (0x34U)

/** Dummy cycles for Read operation */
/* TODO (amendola) verify all dummy cycles, figure out why some of the values that work don't match flash datasheet */
#define NAND_OCTAL_READ_DUMMY_CYCLE_BUFFER_MODE             (0x04U)
/* TODO (amendola) this should actually be 12, but we need to disable sending an address in BUF=0 mode to change this value (+4 cycles for addr) */
#define NAND_OCTAL_READ_DUMMY_CYCLE_CONTINUOUS_MODE         (0x08U)

/* Dummy cycles for 0xED in BUF=1 mode */
#define NAND_QUAD_DTR_FAST_READ_DUMMY_CYCLE_BUFFER_MODE     (0x8U)

/* Dummy cycles for 0xED in BUF=0 mode */
/* This should actually be 11, but we can't seem to be able to disable sending an address
   for BUF=0. So the OSPI controller sends an address that the Flash device ignores, hence
   the +2 cycles for addr.*/
#define NAND_QUAD_DTR_FAST_READ_DUMMY_CYCLE_CONTINUOUS_MODE     (0x9U)

#define NAND_OCTAL_READ_DUMMY_CYCLE_INDAC       (0x04U)
#define NAND_SINGLE_READ_DUMMY_CYCLE            (0x08U)
#define NAND_QUAD_DTR_CMD_READ_DUMMY_CYCLE      (0x08U)
#define NAND_OCTAL_SDR_CMD_READ_DUMMY_CYCLE     (0x08U)
#define NAND_SINGLE_CMD_READ_DUMMY_CYCLE        (0x08U)

/** In Micro seconds */
/* TODO (amendola) see whether the way these are used are actually microseconds */
// Unused #define NAND_PAGE_PROG_TIMEOUT		  (1000U)              /* TO DO */
// Unused #define NAND_SECTOR_ERASE_TIMEOUT	  (1000U)              /* TO DO */
#define NAND_WRR_WRITE_TIMEOUT		  (1000U)              /* TO DO */
#define NAND_BULK_ERASE_TIMEOUT       (1000U)              /* TO DO */

/* \brief Read ID command definitions */
#define NAND_RDID_NUM_BYTES           (0x03U)
#define NAND_MANF_ID                  (0xEFU)   /* Manufacturer ID */
#define NAND_DEVICE_ID                (0xBC21U) /* Device ID */

/** Status Register, Write-in-Progress bit */
#define NAND_SR2_ADDR                 (0xB0U)
#define NAND_SR3_ADDR                 (0xC0U)

#define NAND_SR3_BUSY                 (1U << 0U)  /* BUSY bit */
#define NAND_SR3_E_FAIL_MASK          (1U << 2U)  /* Erase Failed bit */
#define NAND_SR3_P_FAIL_MASK          (1U << 3U)  /* Program Failed bit */
#define NAND_SR3_ECC0_MASK            (1U << 4U)  /* ECC-0 bit */
#define NAND_SR3_ECC1_MASK            (1U << 5U)  /* ECC-1 bit */

#ifdef __cplusplus
}
#endif

#endif /* W25N01GW_H_ */

/* Nothing past this point */
