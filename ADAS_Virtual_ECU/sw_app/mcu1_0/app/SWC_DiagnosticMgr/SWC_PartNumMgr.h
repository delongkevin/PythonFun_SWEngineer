/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 * This document in its entirety is CONFIDENTIAL and may not be disclosed,
 * disseminated or distributed to parties outside MAGNA Electronics
 * without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:       Part Number Manager Module
 * DESIGN:      2020
 * DESCRIPTION: Part Number Manager Module
 * ======================================================================== */

/**
 * \file     PartNumMgr_CDD.h
 * \brief    Part Number Manager Module
 * \author   Anjali Bais
 * \version
 * \details  h file public description of module
 */
/* ======================================================================== */

#define NULL_PTR ((void *)0)

/* ======================================================================== */

#define D_DID_F10D_DATA_LEN                         4u
#define D_DID_F110_DATA_LEN                         6u
#define D_DID_F112_DATA_LEN                         10u
#define D_DID_F122_DATA_LEN                         90u
#define D_DID_F132_DATA_LEN                         10u
#define D_DID_F133_DATA_LEN                         10u
#define D_DID_F134_DATA_LEN                         11u
#define D_DID_F154_DATA_LEN                         2u
#define D_DID_F155_DATA_LEN                         2u
#define D_DID_F180_DATA_LEN                         13u
#define D_DID_F181_DATA_LEN                         65u
#define D_DID_F182_DATA_LEN                         39u
#define D_DID_F187_DATA_LEN                         11u
#define D_DID_F188_DATA_LEN                         11u
#define D_DID_F18A_DATA_LEN                         10u
#define D_DID_F18B_DATA_LEN                         10u
#define D_DID_F18C_DATA_LEN                         15u
#define D_DID_F191_DATA_LEN                         11u
#define D_DID_F192_DATA_LEN                         11u
#define D_DID_F193_DATA_LEN                         1u
#define D_DID_F194_DATA_LEN                         11u
#define D_DID_F195_DATA_LEN                         2u
#define D_DID_F1A0_DATA_LEN                         90u
#define D_DID_F1A2_DATA_LEN                         10u
#define D_DID_FD13_DATA_LEN                         32u
#define D_DID_FD14_DATA_LEN                         5u
#define D_DID_FD15_DATA_LEN                         13u
#define D_DID_FD16_DATA_LEN                         64u
#define D_DID_FD17_DATA_LEN                         3u
#define D_DID_FD1D_DATA_LEN                         14u
#define D_DID_FD31_DATA_LEN                         4u
#define D_DID_FD38_DATA_LEN                         16u
#define D_DID_F1B3_DATA_LEN                         15u
#define D_DID_F1B4_DATA_LEN                         71u
#define D_DID_F1B5_DATA_LEN                         43u
#define D_DID_2003_DATA_LEN                         8u
#define D_ALL_BIT_STATUS                            0xFFu

#define D_BUILD_NUMBER                              0u
#define D_BLANK_ASCII_VALUE                         0x20u

#define D_VIN_ORIGINAL_BYTE_SIZE                    17u
#define D_BOOT_SOFTWARE_LOGICAL_BLOCKS              1u
#define D_APP_SOFTWARE_LOGICAL_BLOCKS               5u
#define D_APP_DATA_SOFTWARE_LOGICAL_BLOCKS          3u
#define D_LOGICAL_BLOCK_0                           0u
#define D_LOGICAL_BLOCK_1                           1u
#define D_LOGICAL_BLOCK_2                           2u
#define D_LOGICAL_BLOCK_3                           3u
#define D_LOGICAL_BLOCK_4                           4u
#define D_LOGICAL_BLOCK_5                           5u
#define D_LOGICAL_BLOCK_6                           6u
#define D_LOGICAL_BLOCK_7                           7u
#define D_LOGICAL_BLOCK_8                           8u
#define D_LOGICAL_BLOCK_9                           9u

/*DID F10D ID:15210908 */
#define D_F10D_DIAGSPEC_INFO                        0x93u,0x33u,0x45u,0x53u
/* DID F10D */
#define D_F110_ECU_DIAG_VAR                         0x00u,0x30u
#define D_F110_SUPPLIER_ID_MAGNA                    0x00u,0x49u
/* DID F154 */
#define D_F154_HARDWARE_SUPPLIER_ID                 0x00u,0x49u
/* DID F155 */
#define D_F155_SOFTWARE_SUPPLIER_ID                 0x00u,0x49u
/*DID F1A2*/
#define D_F1A2_VECTOR_DELIVERY_ID                   0x28u,0x07u,0x34u,0x02u,0x10u,0x10u,0x89u,0x08u,0x04u,0x05u
#define D_LOGICALBLOCK_MAXENDURANCE                 0x27u,0x10u
#define D_EOL_MARKER_DATA                           0xA5u,0xA5u,0xA5u,0xA5u

/*DID FD13                                          SW_Year, SW_Week, SW_Day, Build_Num*/
#define D_FD13_APPLICATION                          0x19u,0x2Eu,0x05u,0x00u
#define D_FD13_BOOT                                 0x19u,0x04u,0x05u,0x00u
#define D_FD13_HSM                                  0x18u,0x32u,0x05u,0x00u
#define D_FD13_APP_PRG_VERSION_LENGTH               0x08
#define D_FD13_APP_PRG_VERSION_STRING               {'M', 'Y', '2', '7','0','4', '0', '0'}   /* Later releases should be "SORPXXXX", For Development "DEV_XXXX" */


/* Part Number DID's Address NOTE: Data updated at the time of flashing EOL*/
#define D_EOL_MARKER_DATA_ADDRESS                      ((uint32 *)0X97BFFC00U) /*EOL*/
#define D_PCB_SERIAL_NUMBER_ADDRESS                    ((uint32 *)0X97BFFC04U) /*EOL*/
#define D_PT_ESLM_HARDWARE_NUMBER_ADDRESS              ((uint32 *)0X97BFFC12U) /*EOL*/
#define D_PROGRAMMED_ASSEMBLY_ADDRESS                  ((uint32 *)0X97BFFC1CU) /*EOL*/
#define D_FCA_ESLM_ECU_HARDWARE_NUMBER_ADDRESS         ((uint32 *)0X97BFFC2CU) /*EOL*/
#define D_SUPPLIER_ECU_HARDWARE_PART_NUMBER_ADDRESS    ((uint32 *)0X97BFFC37U) /*EOL*/
#define D_SUPPLIER_ECU_HARDWARE_VERSION_NUMBER_ADDRESS ((uint32 *)0X97BFFC42U) /*EOL*/
#define D_ECU_SERIAL_NUMBER_ADDRESS                    ((uint32 *)0X97BFFC43U) /*EOL*/
#define	D_MAGNA_PRODUCTION_DATE	                       ((uint32 *)0X97BFFC52U) /*EOL*/
#define	D_MAGNA_PRODUCTION_HARDWARE_NUMBER	           ((uint32 *)0X97BFFC57U) /*EOL*/
#define	D_MAGNA_PRODUCTION_ICT_DATA	                   ((uint32 *)0X97BFFC64U) /*EOL*/
#define	D_MAGNA_PRODUCTION_HARDWARE_VERSION_INFO	   ((uint32 *)0X97BFFCA4U) /*EOL*/

#define D_Invert16Bit(x)        ((uint16)((x) ^ ((uint16)0xFFFFu)))


typedef struct metaData_s
{
  uint8 Fingerprint_au8[13u];
  uint8 ProgCounter_au8[2u];
  uint8 ProgAttempts_au8[2u];
  uint8 CRCValue_u8;
  uint8 CRCStart_u8;
  uint8 CRCLength_u8;
  uint8 SoftwareIdentification_au8[13u];
  uint8 SwEbomPartNumber_au8[10u];
  uint8 MemoryStatu_u8;
  uint8 SegmentCount_u8;
  uint8 SegmentAddrList_au8[40u];
  uint8 SegmentLengthList_au8[40u];
  uint8 FlashStatus_u8;
} metaData_t;

