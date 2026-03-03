/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:   DltIbp
 * DESIGN:  <tbd>
 * DESCRIPTION:
 *    Header file for the DltIbp module
 * ======================================================================== */

#ifndef DLTIBP_H_
#define DLTIBP_H_

/* --- Public Typedefinitions, Enumerations, Defines ------------------------------- */
#include <platform/PlatformSpecs.h>

#ifdef __cplusplus
extern "C"
{
#endif
/* Some QACPP/C++-rules cannot be followed, because the header is used for both C and C++,
 * hence the following rules are deactivated: */
/* PRQA S 1025 EOF */ /* Macro may be used as a literal */
/* PRQA S 2400 EOF */ /* Definitions _are_ in the global scope */

/* QA-C */
/* PRQA S 3210 EOF */  /* Suppressed QAC warning, functions provided for other DLT modules */
/* PRQA S 3447 EOF */  /* Suppressed QAC warning, functions are declared in a header file */
/* PRQA S 3448 EOF */  /* Suppressed QAC warning, functions are declared in a header file */

/* -------------------------------------------------------------------------- */
/* --------------------------- Standard Header ------------------------------ */
/* -------------------------------------------------------------------------- */

#define sDltEncap_d_HEADER_LEN       0x03
#define sDltEncap_d_START_FRAME_LEN  0x08

#define sDltEncap_d_TYPE_SIZE        0x04
#define sDltEncap_d_DATALEN_SIZE     0x02
#define sDltEncap_d_NAMELEN_SIZE     0x02

typedef enum DltEncap_FrameType_e
{
  eDltEncap_d_START_FRAME       = 0x00U,
  eDltEncap_d_CONTINUE_FRAME    = 0x01U,
  eDltEncap_d_END_FRAME         = 0x02U
} DltEncap_FrameType_t;

typedef enum DltEncap_CompressionType_e
{
  eDltEncap_d_NOT_COMPRESSED     = 0x00U,
  eDltEncap_d_SNAPPY_COMPRESSED  = 0x04U
} DltEncap_CompressionType_t;

typedef enum DltEncap_Content_e
{
  eDltEncap_d_CONTENT_IMAGE      = 0x00U,
  eDltEncap_d_CONTENT_RAW_BINARY = 0x10U
} DltEncap_Content_t;

/* Image type used in sDltEncap_F_writeHeaderImageData_u8 */
typedef enum DltEncap_ImageType_e
{
  eDltEncap_d_IMAGE_RGB          = 0x00U,
  eDltEncap_d_IMAGE_RGBA         = 0x01U,
  eDltEncap_d_IMAGE_ARGB         = 0x02U,
  eDltEncap_d_IMAGE_GRAYSCALE8   = 0x04U,
  eDltEncap_d_IMAGE_UNDEFINED    = 0xFFU
} DltEncap_ImageType_t;

/* --- Public Function Declarations ------------------------------------------------ */
/**
 * Writes header data for a binary DLT message to the given buffer
 *
 * @param[out] o_Buf_pu8 Buffer to write to
 * @param[in]  i_BufLen_u16 buffer length
 * @param[in]  i_CompressionType_t compression type
 * @param[in]  i_FrameType_t frame type - continuation flag
 * @param[in]  i_Content_t type of data: either binary or image content
 * @param[in]  i_SerialNo_u16 - on start frame the number of frames, then the frame index
 *
 * @return length of the header written = sDltEncap_d_HEADER_LEN
 */
uint8_t sDltEncap_F_writeHeaderData_u8(uint8_t o_Buf_au8[],
                                       uint16_t i_BufLen_u16,
                                       DltEncap_CompressionType_t i_CompressionType_t,
                                       DltEncap_FrameType_t i_FrameType_t,
                                       DltEncap_Content_t i_Content_t,
                                       uint16_t i_SerialNo_u16);


/**
 * Write the image meta info to the DLT header.
 *
 * @param[out] o_Buf_pu8 Buffer to write to
 * @param[in]  i_BufLen_u16 length of the write buffer
 *
 * @param[in]  i_ImageType_t     Type of the image
 * @param[in]  i_ImageWidth_u16   Image width in pixels
 * @param[in]  i_ImageHeight_u16  Image height in pixels
 *
 * @return continued write index in the buffer
 */
uint8_t sDltEncap_F_writeHeaderImageData_u8(uint8_t o_Buf_au8[],
                                            uint16_t i_BufLen_u16,
                                            DltEncap_ImageType_t i_ImageType_t,
                                            uint16_t i_ImageWidth_u16,
                                            uint16_t i_ImageHeight_u16);


#ifdef __cplusplus
}
#endif

/* --------------------------------------------------------------------------------- */
#endif /* DLTIBP_H_ */

/* --------------------------------------------------------------------------------- */
/* END OF FILE: dltibp.h */
