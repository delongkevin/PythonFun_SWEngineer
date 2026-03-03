/**
 * @file ipc_crc.c
 * @brief Calculate CRC8 and CRC32 of data shared over IPC
 *
 * @details This file provide API to calculate CRC8 and CRC32 for provided data
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

/* ===========================================================================
*
*   Include Files
*
* ========================================================================= */
#include <stdint.h>
#include <stdio.h>
#include "ipc_cfg.h"
#include "ipc_error.h"
#include "ipc_diag.h"
#include "ipc_crc.h"
/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
#define D_CRC8_INIT_VAL        (0xFFU)
#define D_CRC8_FINAL_XOR_VAL   (0xFFU)

#define D_CRC32_INIT_VAL       (0xFFFFFFFFU)
#define D_CRC32_FINAL_XOR_VAL  (0xFFFFFFFFU)

/* ===========================================================================
*
*   Global variables
*
* ========================================================================= */


/* ===========================================================================
*
*   Private variables
*
* ========================================================================= */
/*
 * CRC8 lookup table
 * Polynomial: 0x1D ( x^4 + x^3 + x^2 + 1 )
 */
static const uint8_t V_crc8Table_au8[256] =
{
    0x00u, 0x1du, 0x3au, 0x27u, 0x74u, 0x69u, 0x4eu, 0x53u,
    0xe8u, 0xf5u, 0xd2u, 0xcfu, 0x9cu, 0x81u, 0xa6u, 0xbbu,
    0xcdu, 0xd0u, 0xf7u, 0xeau, 0xb9u, 0xa4u, 0x83u, 0x9eu,
    0x25u, 0x38u, 0x1fu, 0x02u, 0x51u, 0x4cu, 0x6bu, 0x76u,
    0x87u, 0x9au, 0xbdu, 0xa0u, 0xf3u, 0xeeu, 0xc9u, 0xd4u,
    0x6fu, 0x72u, 0x55u, 0x48u, 0x1bu, 0x06u, 0x21u, 0x3cu,
    0x4au, 0x57u, 0x70u, 0x6du, 0x3eu, 0x23u, 0x04u, 0x19u,
    0xa2u, 0xbfu, 0x98u, 0x85u, 0xd6u, 0xcbu, 0xecu, 0xf1u,
    0x13u, 0x0eu, 0x29u, 0x34u, 0x67u, 0x7au, 0x5du, 0x40u,
    0xfbu, 0xe6u, 0xc1u, 0xdcu, 0x8fu, 0x92u, 0xb5u, 0xa8u,
    0xdeu, 0xc3u, 0xe4u, 0xf9u, 0xaau, 0xb7u, 0x90u, 0x8du,
    0x36u, 0x2bu, 0x0cu, 0x11u, 0x42u, 0x5fu, 0x78u, 0x65u,
    0x94u, 0x89u, 0xaeu, 0xb3u, 0xe0u, 0xfdu, 0xdau, 0xc7u,
    0x7cu, 0x61u, 0x46u, 0x5bu, 0x08u, 0x15u, 0x32u, 0x2fu,
    0x59u, 0x44u, 0x63u, 0x7eu, 0x2du, 0x30u, 0x17u, 0x0au,
    0xb1u, 0xacu, 0x8bu, 0x96u, 0xc5u, 0xd8u, 0xffu, 0xe2u,
    0x26u, 0x3bu, 0x1cu, 0x01u, 0x52u, 0x4fu, 0x68u, 0x75u,
    0xceu, 0xd3u, 0xf4u, 0xe9u, 0xbau, 0xa7u, 0x80u, 0x9du,
    0xebu, 0xf6u, 0xd1u, 0xccu, 0x9fu, 0x82u, 0xa5u, 0xb8u,
    0x03u, 0x1eu, 0x39u, 0x24u, 0x77u, 0x6au, 0x4du, 0x50u,
    0xa1u, 0xbcu, 0x9bu, 0x86u, 0xd5u, 0xc8u, 0xefu, 0xf2u,
    0x49u, 0x54u, 0x73u, 0x6eu, 0x3du, 0x20u, 0x07u, 0x1au,
    0x6cu, 0x71u, 0x56u, 0x4bu, 0x18u, 0x05u, 0x22u, 0x3fu,
    0x84u, 0x99u, 0xbeu, 0xa3u, 0xf0u, 0xedu, 0xcau, 0xd7u,
    0x35u, 0x28u, 0x0fu, 0x12u, 0x41u, 0x5cu, 0x7bu, 0x66u,
    0xddu, 0xc0u, 0xe7u, 0xfau, 0xa9u, 0xb4u, 0x93u, 0x8eu,
    0xf8u, 0xe5u, 0xc2u, 0xdfu, 0x8cu, 0x91u, 0xb6u, 0xabu,
    0x10u, 0x0du, 0x2au, 0x37u, 0x64u, 0x79u, 0x5eu, 0x43u,
    0xb2u, 0xafu, 0x88u, 0x95u, 0xc6u, 0xdbu, 0xfcu, 0xe1u,
    0x5au, 0x47u, 0x60u, 0x7du, 0x2eu, 0x33u, 0x14u, 0x09u,
    0x7fu, 0x62u, 0x45u, 0x58u, 0x0bu, 0x16u, 0x31u, 0x2cu,
    0x97u, 0x8au, 0xadu, 0xb0u, 0xe3u, 0xfeu, 0xd9u, 0xc4u
};

#if (D_IPC_FEATURE_CRC32 == 1)
/*
 * CRC8 lookup table
 * Polynomial: 0x04C11DB7 ( x^26 + x^23 + x^22 + x^16 x^12 + x^11 + x^10 + x^8 + x^7 + x^5 + x^4 + x^2 + x^1 + 1 )
 */

/*! Lookup table for CRC32 table based calculation */
const uint32_t V_crc32Table_au32[256] =
{
    0x00000000uL, 0x77073096uL, 0xEE0E612CuL, 0x990951BAuL, 0x076DC419uL, 0x706AF48FuL, 0xE963A535uL, 0x9E6495A3uL,
    0x0EDB8832uL, 0x79DCB8A4uL, 0xE0D5E91EuL, 0x97D2D988uL, 0x09B64C2BuL, 0x7EB17CBDuL, 0xE7B82D07uL, 0x90BF1D91uL,
    0x1DB71064uL, 0x6AB020F2uL, 0xF3B97148uL, 0x84BE41DEuL, 0x1ADAD47DuL, 0x6DDDE4EBuL, 0xF4D4B551uL, 0x83D385C7uL,
    0x136C9856uL, 0x646BA8C0uL, 0xFD62F97AuL, 0x8A65C9ECuL, 0x14015C4FuL, 0x63066CD9uL, 0xFA0F3D63uL, 0x8D080DF5uL,
    0x3B6E20C8uL, 0x4C69105EuL, 0xD56041E4uL, 0xA2677172uL, 0x3C03E4D1uL, 0x4B04D447uL, 0xD20D85FDuL, 0xA50AB56BuL,
    0x35B5A8FAuL, 0x42B2986CuL, 0xDBBBC9D6uL, 0xACBCF940uL, 0x32D86CE3uL, 0x45DF5C75uL, 0xDCD60DCFuL, 0xABD13D59uL,
    0x26D930ACuL, 0x51DE003AuL, 0xC8D75180uL, 0xBFD06116uL, 0x21B4F4B5uL, 0x56B3C423uL, 0xCFBA9599uL, 0xB8BDA50FuL,
    0x2802B89EuL, 0x5F058808uL, 0xC60CD9B2uL, 0xB10BE924uL, 0x2F6F7C87uL, 0x58684C11uL, 0xC1611DABuL, 0xB6662D3DuL,
    0x76DC4190uL, 0x01DB7106uL, 0x98D220BCuL, 0xEFD5102AuL, 0x71B18589uL, 0x06B6B51FuL, 0x9FBFE4A5uL, 0xE8B8D433uL,
    0x7807C9A2uL, 0x0F00F934uL, 0x9609A88EuL, 0xE10E9818uL, 0x7F6A0DBBuL, 0x086D3D2DuL, 0x91646C97uL, 0xE6635C01uL,
    0x6B6B51F4uL, 0x1C6C6162uL, 0x856530D8uL, 0xF262004EuL, 0x6C0695EDuL, 0x1B01A57BuL, 0x8208F4C1uL, 0xF50FC457uL,
    0x65B0D9C6uL, 0x12B7E950uL, 0x8BBEB8EAuL, 0xFCB9887CuL, 0x62DD1DDFuL, 0x15DA2D49uL, 0x8CD37CF3uL, 0xFBD44C65uL,
    0x4DB26158uL, 0x3AB551CEuL, 0xA3BC0074uL, 0xD4BB30E2uL, 0x4ADFA541uL, 0x3DD895D7uL, 0xA4D1C46DuL, 0xD3D6F4FBuL,
    0x4369E96AuL, 0x346ED9FCuL, 0xAD678846uL, 0xDA60B8D0uL, 0x44042D73uL, 0x33031DE5uL, 0xAA0A4C5FuL, 0xDD0D7CC9uL,
    0x5005713CuL, 0x270241AAuL, 0xBE0B1010uL, 0xC90C2086uL, 0x5768B525uL, 0x206F85B3uL, 0xB966D409uL, 0xCE61E49FuL,
    0x5EDEF90EuL, 0x29D9C998uL, 0xB0D09822uL, 0xC7D7A8B4uL, 0x59B33D17uL, 0x2EB40D81uL, 0xB7BD5C3BuL, 0xC0BA6CADuL,
    0xEDB88320uL, 0x9ABFB3B6uL, 0x03B6E20CuL, 0x74B1D29AuL, 0xEAD54739uL, 0x9DD277AFuL, 0x04DB2615uL, 0x73DC1683uL,
    0xE3630B12uL, 0x94643B84uL, 0x0D6D6A3EuL, 0x7A6A5AA8uL, 0xE40ECF0BuL, 0x9309FF9DuL, 0x0A00AE27uL, 0x7D079EB1uL,
    0xF00F9344uL, 0x8708A3D2uL, 0x1E01F268uL, 0x6906C2FEuL, 0xF762575DuL, 0x806567CBuL, 0x196C3671uL, 0x6E6B06E7uL,
    0xFED41B76uL, 0x89D32BE0uL, 0x10DA7A5AuL, 0x67DD4ACCuL, 0xF9B9DF6FuL, 0x8EBEEFF9uL, 0x17B7BE43uL, 0x60B08ED5uL,
    0xD6D6A3E8uL, 0xA1D1937EuL, 0x38D8C2C4uL, 0x4FDFF252uL, 0xD1BB67F1uL, 0xA6BC5767uL, 0x3FB506DDuL, 0x48B2364BuL,
    0xD80D2BDAuL, 0xAF0A1B4CuL, 0x36034AF6uL, 0x41047A60uL, 0xDF60EFC3uL, 0xA867DF55uL, 0x316E8EEFuL, 0x4669BE79uL,
    0xCB61B38CuL, 0xBC66831AuL, 0x256FD2A0uL, 0x5268E236uL, 0xCC0C7795uL, 0xBB0B4703uL, 0x220216B9uL, 0x5505262FuL,
    0xC5BA3BBEuL, 0xB2BD0B28uL, 0x2BB45A92uL, 0x5CB36A04uL, 0xC2D7FFA7uL, 0xB5D0CF31uL, 0x2CD99E8BuL, 0x5BDEAE1DuL,
    0x9B64C2B0uL, 0xEC63F226uL, 0x756AA39CuL, 0x026D930AuL, 0x9C0906A9uL, 0xEB0E363FuL, 0x72076785uL, 0x05005713uL,
    0x95BF4A82uL, 0xE2B87A14uL, 0x7BB12BAEuL, 0x0CB61B38uL, 0x92D28E9BuL, 0xE5D5BE0DuL, 0x7CDCEFB7uL, 0x0BDBDF21uL,
    0x86D3D2D4uL, 0xF1D4E242uL, 0x68DDB3F8uL, 0x1FDA836EuL, 0x81BE16CDuL, 0xF6B9265BuL, 0x6FB077E1uL, 0x18B74777uL,
    0x88085AE6uL, 0xFF0F6A70uL, 0x66063BCAuL, 0x11010B5CuL, 0x8F659EFFuL, 0xF862AE69uL, 0x616BFFD3uL, 0x166CCF45uL,
    0xA00AE278uL, 0xD70DD2EEuL, 0x4E048354uL, 0x3903B3C2uL, 0xA7672661uL, 0xD06016F7uL, 0x4969474DuL, 0x3E6E77DBuL,
    0xAED16A4AuL, 0xD9D65ADCuL, 0x40DF0B66uL, 0x37D83BF0uL, 0xA9BCAE53uL, 0xDEBB9EC5uL, 0x47B2CF7FuL, 0x30B5FFE9uL,
    0xBDBDF21CuL, 0xCABAC28AuL, 0x53B39330uL, 0x24B4A3A6uL, 0xBAD03605uL, 0xCDD70693uL, 0x54DE5729uL, 0x23D967BFuL,
    0xB3667A2EuL, 0xC4614AB8uL, 0x5D681B02uL, 0x2A6F2B94uL, 0xB40BBE37uL, 0xC30C8EA1uL, 0x5A05DF1BuL, 0x2D02EF8DuL
};
#endif

/* ===========================================================================
*
*   Private functions
*
* ========================================================================= */


/* ===========================================================================
*
*   Global functions
*
* ========================================================================= */
/*
 * Purpose: Calculate CRC8.
 * Description: Calculate CRC8.
 * Return Type : uint8_t (CRC8 value)
 * Requirement ID - 16062146
*/
uint8_t IPC_F_CalcCrc8_u8 (const uint8_t *i_DataRcv_pu8, uint16_t i_dataSize_u16)
{
  /* DD-ID: {09BF7882-709A-4d55-BBC7-0360ADCA9110}*/
    uint8_t  v_crcVal_u8;
    uint16_t v_dataCntr_u16;

    v_crcVal_u8 = D_CRC8_INIT_VAL;

    for (v_dataCntr_u16 = 0; v_dataCntr_u16 < i_dataSize_u16; v_dataCntr_u16++)
    {
      v_crcVal_u8 = V_crc8Table_au8[v_crcVal_u8 ^ i_DataRcv_pu8[v_dataCntr_u16]];
    }

    v_crcVal_u8 ^= D_CRC8_FINAL_XOR_VAL;

    return v_crcVal_u8;
}

/*
 * Purpose: Calculate CRC32.
 * Description: Calculate CRC32.
 * Return Type : uint32_t (CRC32 value)
*/
uint32_t IPC_F_CalcCrc32_u32(uint8_t *i_DataRcv_pu8, uint16_t i_dataSize_u16)
{
  /* DD-ID: {5F0F7A91-0F4D-42d6-AA95-9F7008B154F3}*/
    uint32_t v_crcVal_u32 = 0;
#if (D_IPC_FEATURE_CRC32 == 1)
    uint16_t v_dataCntr_u16;

    v_crcVal_u32 = D_CRC32_INIT_VAL;

    for (v_dataCntr_u16 = 0; v_dataCntr_u16 < i_dataSize_u16; v_dataCntr_u16++)
    {
        v_crcVal_u32 ^= (uint32_t) i_DataRcv_pu8[v_dataCntr_u16];
        v_crcVal_u32 = ( v_crcVal_u32 >> 8u ) ^ ( V_crc32Table_au32[(uint8_t)(v_crcVal_u32 )]);
    }

    v_crcVal_u32 ^= D_CRC32_FINAL_XOR_VAL;
#endif
    return v_crcVal_u32;
}

/*
 * Purpose: Validate CRC8 of received data over IPC.
 * Description: Validate CRC8 of received data over IPC.
 * Return Type : uint32_t
*/
uint32_t IPC_F_validateCrc8_u32 (uint16_t i_msgId_u16, const uint8_t *i_DataRcv_pu8, uint16_t i_DataLen_u16)
{
  /* DD-ID: {D2B305D0-A48C-458d-9C37-8EAE950D4FD1}*/
    (void)i_msgId_u16;
    uint32_t v_ret_u32 = D_IPC_NO_ERROR;
    uint8_t v_crc8_u8 = 0;

    /* Calculate CRC8 of received data */
    v_crc8_u8 = IPC_F_CalcCrc8_u8(i_DataRcv_pu8, i_DataLen_u16);
    
    /* Compare if calculated CRC8 and received CRC8 in IPC message are same */
    if (v_crc8_u8 != i_DataRcv_pu8[i_DataLen_u16])
    {
        /* Data corrupted while transmission -> Capture error */
        D_IPC_COLLECT_RX_ERR(v_ret_u32, D_IPC_RX_ERR_CRC8_MISMATCH, i_msgId_u16, NULL);
    }

    return v_ret_u32;
}


/*
 * Purpose: Validate CRC32 of received data in shared memory.
 * Description: Validate CRC32 of received data in shared memory.
 * Return Type : uint32_t
*/
uint32_t IPC_F_validateCrc32_u32(uint16_t i_msgId_u16, uint8_t *i_DataRcv_pu8, uint16_t i_DataLen_u16)
{
  /* DD-ID: {7772EE74-3949-43ca-856B-F238519ACF6F}*/
	(void)i_msgId_u16;
    uint32_t v_ret_u32 = D_IPC_NO_ERROR;
#if (D_IPC_FEATURE_CRC32 == 1)
    uint32_t v_crc32_u32 = 0;
    uint32_t v_rcvdCrc32_u32 = 0;

    /* Calculate CRC32 of received data */    
    v_crc32_u32 = IPC_F_CalcCrc32_u32(i_DataRcv_pu8, i_DataLen_u16);
    
    /* Extract CRC32 from shared memory */
    /* ToDo -> QAC Needs to be fixed */
    v_rcvdCrc32_u32 = (*(uint32_t *)&i_DataRcv_pu8[i_DataLen_u16]); 
    
    /* Compare if calculated CRC32 and received CRC32 are same */
    if (v_crc32_u32 != v_rcvdCrc32_u32)
    {
        /* Data corrupted while transmission -> Capture error */
        D_IPC_COLLECT_RX_ERR(v_ret_u32, D_IPC_RX_ERR_CRC32_MISMATCH, i_msgId_u16, NULL);
    }
#endif    
    return v_ret_u32;
}

/*===============================End Of File========================================================*/
