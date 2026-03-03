/**
 * @file ipc_crc.h
 * @brief Header file for CRC8 and CRC32 for IPC data
 *
 * @details This file contains CRC8 and CRC32 calculation API prototype for IPC data
 *
 * --------------------------------------------------------------------------
 * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *
 *   This is an unpublished work of authorship, which contains
 *   trade secrets, created in 2014.  Magna Electronics owns all
 *   rights to this work and intends to maintain it in confidence
 *   to preserve its trade secret status.  Magna Electronics
 *   reserves the right, under the copyright laws of the United
 *   States or those of any other country that may have jurisdiction,
 *   to protect this work as an unpublished work, in the event of
 *   an inadvertent or deliberate unauthorized publication.
 *   Magna Electronics also reserves its rights under all copyright
 *   laws to protect this work as a published work, when appropriate.
 *   Those having access to this work may not copy it, use it,
 *   modify it, or disclose the information contained in it without
 *   the written authorization of Magna Electronics.
 *
 * --------------------------------------------------------------------------
 * @author ----  (---- @magna.com)
 */

#ifndef IPC_CRC_H_
#define IPC_CRC_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */


/* ===========================================================================
*
*   Defines
*
* ========================================================================= */


/* ===========================================================================
*
*   Global data types
*
* ========================================================================= */


/* ========================================================================== */
/*                          External Dependencies                             */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

uint8_t  IPC_F_CalcCrc8_u8 (const uint8_t *i_DataRcv_pu8,  uint16_t i_dataSize_u16);
uint32_t IPC_F_CalcCrc32_u32(uint8_t *i_DataRcv_pu8, uint16_t i_dataSize_u16);
uint32_t IPC_F_validateCrc8_u32 (uint16_t i_msgId_u16, const uint8_t *i_DataRcv_pu8, uint16_t i_DataLen_u16);
uint32_t IPC_F_validateCrc32_u32(uint16_t i_msgId_u16, uint8_t *i_DataRcv_pu8, uint16_t i_DataLen_u16);


#endif  /* #define IPC_CRC_H_ */
