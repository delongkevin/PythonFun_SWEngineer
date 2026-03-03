#ifndef DATA_SERIALIZER_H
#define DATA_SERIALIZER_H

#include <platform/PlatformSpecs.h>

/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */
/* PRQA S 3080 EOF */ /* uses old style casts, as used in cpp and c */
/* PRQA S 3706 EOF */ /* needed to pick out data */
/* PRQA S 2000 EOF */ /* global scope, this is a header file */
/* PRQA S 1025 EOF */ /* Macro may be used as a literal */
/* PRQA S 1021 EOF */ /* Macro may be used as a literal */

/* PRQA S 3450 EOF */ /* with internal linkage, is being defined without a previous declaration. */
/* PRQA S 3480 EOF */ /* with internal linkage, has been defined in a header file. */
/* PRQA S 0492 EOF */ /* subscript operator necessary here. */
/* PRQA S 0491 EOF */ /* subscript operator necessary here. */
/* PRQA S 4131 EOF */ /* Left shift operation on signed operand. */
/* PRQA S 4130 EOF */ /* Bitwise operations on signed data will give implementation defined results. */
/* PRQA S 1594 EOF */ /* declared here. */

// v_NetworkEndianness_b: 0=Little 1=Big
#define NETWORK_ENDIANNESS_LITTLE  0
#define NETWORK_ENDIANNESS_BIG     1

static sint64_t ME_DataSerializer_Read_s64(const uint8_t* i_Data_pc, uint32_t* b_Index_pu32, bool_t v_NetworkEndianness_b)
{
  sint64_t v_Data_u64;

  if(NETWORK_ENDIANNESS_LITTLE == v_NetworkEndianness_b)
  {
    v_Data_u64 =
                ((sint64_t)i_Data_pc[*b_Index_pu32  ] <<  0) |
                ((sint64_t)i_Data_pc[*b_Index_pu32+1] <<  8) |
                ((sint64_t)i_Data_pc[*b_Index_pu32+2] << 16) |
                ((sint64_t)i_Data_pc[*b_Index_pu32+3] << 24) |
                ((sint64_t)i_Data_pc[*b_Index_pu32+4] << 32) |
                ((sint64_t)i_Data_pc[*b_Index_pu32+5] << 40) |
                ((sint64_t)i_Data_pc[*b_Index_pu32+6] << 48) |
                ((sint64_t)i_Data_pc[*b_Index_pu32+7] << 56);
  }
  else
  {
    v_Data_u64 =
                ((sint64_t)i_Data_pc[*b_Index_pu32  ] << 56) |
                ((sint64_t)i_Data_pc[*b_Index_pu32+1] << 48) |
                ((sint64_t)i_Data_pc[*b_Index_pu32+2] << 40) |
                ((sint64_t)i_Data_pc[*b_Index_pu32+3] << 32) |
                ((sint64_t)i_Data_pc[*b_Index_pu32+4] << 24) |
                ((sint64_t)i_Data_pc[*b_Index_pu32+5] << 16) |
                ((sint64_t)i_Data_pc[*b_Index_pu32+6] <<  8) |
                ((sint64_t)i_Data_pc[*b_Index_pu32+7] <<  0);
  }

  *b_Index_pu32 += 8;

  return v_Data_u64;
}

static uint64_t ME_DataSerializer_Read_u64(const uint8_t* i_Data_pc, uint32_t* b_Index_pu32, bool_t v_NetworkEndianness_b)
{
  uint64_t v_Data_u64;

  if(NETWORK_ENDIANNESS_LITTLE == v_NetworkEndianness_b)
  {
    v_Data_u64 =
                ((uint64_t)i_Data_pc[*b_Index_pu32  ] <<  0) |
                ((uint64_t)i_Data_pc[*b_Index_pu32+1] <<  8) |
                ((uint64_t)i_Data_pc[*b_Index_pu32+2] << 16) |
                ((uint64_t)i_Data_pc[*b_Index_pu32+3] << 24) |
                /* For example, if the type of the left hand operand is unsigned long, and long is implemented in 32 bits, the value of the right hand operand must not be less than 0 or greater than 31.*/
                /* PRQA S 2790 4 */ /* tested on our platform */
                ((uint64_t)i_Data_pc[*b_Index_pu32+4] << 32) |
                ((uint64_t)i_Data_pc[*b_Index_pu32+5] << 40) |
                ((uint64_t)i_Data_pc[*b_Index_pu32+6] << 48) |
                ((uint64_t)i_Data_pc[*b_Index_pu32+7] << 56);
  }
  else
  {
    v_Data_u64 =
                /* For example, if the type of the left hand operand is unsigned long, and long is implemented in 32 bits, the value of the right hand operand must not be less than 0 or greater than 31.*/
                /* PRQA S 2790 4 */ /* tested on our platform */
                ((uint64_t)i_Data_pc[*b_Index_pu32  ] << 56) |
                ((uint64_t)i_Data_pc[*b_Index_pu32+1] << 48) |
                ((uint64_t)i_Data_pc[*b_Index_pu32+2] << 40) |
                ((uint64_t)i_Data_pc[*b_Index_pu32+3] << 32) |
                ((uint64_t)i_Data_pc[*b_Index_pu32+4] << 24) |
                ((uint64_t)i_Data_pc[*b_Index_pu32+5] << 16) |
                ((uint64_t)i_Data_pc[*b_Index_pu32+6] <<  8) |
                ((uint64_t)i_Data_pc[*b_Index_pu32+7] <<  0);
  }

  *b_Index_pu32 += 8;

  return v_Data_u64;
}

static float32_t ME_DataSerializer_Read_f32(const uint8_t* i_Data_pc, uint32_t* b_Index_pu32, bool_t v_NetworkEndianness_b)
{
  float32_t v_Data_f32;
  uint8_t *pdata = (uint8_t*)&v_Data_f32; /* PRQA S 3017 */ /* PRQA S 310 */  /* needed to properly pick out data */

  if(NETWORK_ENDIANNESS_LITTLE == v_NetworkEndianness_b)
  {
    pdata[0] = i_Data_pc[*b_Index_pu32    ];
    pdata[1] = i_Data_pc[*b_Index_pu32 + 1];
    pdata[2] = i_Data_pc[*b_Index_pu32 + 2];
    pdata[3] = i_Data_pc[*b_Index_pu32 + 3];
  }
  else
  {
    pdata[0] = i_Data_pc[*b_Index_pu32 + 3];
    pdata[1] = i_Data_pc[*b_Index_pu32 + 2];
    pdata[2] = i_Data_pc[*b_Index_pu32 + 1];
    pdata[3] = i_Data_pc[*b_Index_pu32    ];
  }

  *b_Index_pu32 += 4;

  return v_Data_f32;
}

static sint32_t ME_DataSerializer_Read_s32(const uint8_t* i_Data_pc, uint32_t* b_Index_pu32, bool_t v_NetworkEndianness_b)
{
  sint32_t v_Data_s32;

  if(NETWORK_ENDIANNESS_LITTLE == v_NetworkEndianness_b)
  {
    v_Data_s32 =
                  ((sint32_t)i_Data_pc[*b_Index_pu32  ] <<  0) |
                  ((sint32_t)i_Data_pc[*b_Index_pu32+1] <<  8) |
                  ((sint32_t)i_Data_pc[*b_Index_pu32+2] << 16) |
                  ((sint32_t)i_Data_pc[*b_Index_pu32+3] << 24);
  }
  else
  {
    v_Data_s32 =
                  ((sint32_t)i_Data_pc[*b_Index_pu32  ] << 24) |
                  ((sint32_t)i_Data_pc[*b_Index_pu32+1] << 16) |
                  ((sint32_t)i_Data_pc[*b_Index_pu32+2] <<  8) |
                  ((sint32_t)i_Data_pc[*b_Index_pu32+3] <<  0);
  }

  *b_Index_pu32 += 4;

  return v_Data_s32;
}

static uint32_t ME_DataSerializer_Read_u32(const uint8_t* i_Data_pc, uint32_t* b_Index_pu32, bool_t v_NetworkEndianness_b)
{
  uint32_t v_Data_u32;

  if(NETWORK_ENDIANNESS_LITTLE == v_NetworkEndianness_b)
  {
    v_Data_u32 =
                  ((uint32_t)i_Data_pc[*b_Index_pu32  ] <<  0) |
                  ((uint32_t)i_Data_pc[*b_Index_pu32+1] <<  8) |
                  ((uint32_t)i_Data_pc[*b_Index_pu32+2] << 16) |
                  ((uint32_t)i_Data_pc[*b_Index_pu32+3] << 24);
  }
  else
  {
    v_Data_u32 =
                  ((uint32_t)i_Data_pc[*b_Index_pu32  ] << 24) |
                  ((uint32_t)i_Data_pc[*b_Index_pu32+1] << 16) |
                  ((uint32_t)i_Data_pc[*b_Index_pu32+2] <<  8) |
                  ((uint32_t)i_Data_pc[*b_Index_pu32+3] <<  0);
  }

  *b_Index_pu32 += 4;

  return v_Data_u32;
}

static sint16_t ME_DataSerializer_Read_s16(const uint8_t* i_Data_pc, uint32_t* b_Index_pu32, bool_t v_NetworkEndianness_b)
{
  sint16_t v_Data_s16;

  if(NETWORK_ENDIANNESS_LITTLE == v_NetworkEndianness_b)
  {
    v_Data_s16 = (sint16_t)( ( (uint16_t)i_Data_pc[*b_Index_pu32]     << 0) |
                             ( (uint16_t)i_Data_pc[*b_Index_pu32 + 1] << 8)  );
  }
  else
  {
    v_Data_s16 = (sint16_t)( ( (uint16_t)i_Data_pc[*b_Index_pu32]     << 8) |
                             ( (uint16_t)i_Data_pc[*b_Index_pu32 + 1] << 0)  );
  }

  *b_Index_pu32 += 2;

  return v_Data_s16;
}

static uint16_t ME_DataSerializer_Read_u16(const uint8_t* i_Data_pc, uint32_t* b_Index_pu32, bool_t v_NetworkEndianness_b)
{
  uint16_t v_Data_u16;

  if(NETWORK_ENDIANNESS_LITTLE == v_NetworkEndianness_b)
  {
    v_Data_u16 = ((uint16_t)i_Data_pc[*b_Index_pu32]     << 0) |
                 ((uint16_t)i_Data_pc[*b_Index_pu32 + 1] << 8);
  }
  else
  {
    v_Data_u16 = ((uint16_t)i_Data_pc[*b_Index_pu32]     << 8) |
               ((uint16_t)i_Data_pc[*b_Index_pu32 + 1] << 0);
  }

  *b_Index_pu32 += 2;

  return v_Data_u16;
}

static sint8_t ME_DataSerializer_Read_s8(const uint8_t* i_Data_pc, uint32_t* b_Index_pu32, bool_t v_NetworkEndianness_b) // PRQA S 3206 // PRQA S 4327 // keep argument v_NetworkEndianness_b
{
  sint8_t v_Data_s8 = (sint8_t)i_Data_pc[*b_Index_pu32];

  (*b_Index_pu32)++;

  return v_Data_s8;
}

static uint8_t ME_DataSerializer_Read_u8(const uint8_t* i_Data_pc, uint32_t* b_Index_pu32, bool_t v_NetworkEndianness_b) // PRQA S 3206 // PRQA S 4327 // keep argument v_NetworkEndianness_b
{
  uint8_t v_Data_u8 = i_Data_pc[*b_Index_pu32];

  (*b_Index_pu32)++;

  return v_Data_u8;
}

// --- Write Functions ---

static void ME_DataSerializer_Write_s64(uint8_t* b_Data_pc, uint32_t* b_Index_pu32, sint64_t i_Value_s64, bool_t i_NetworkEndianness_b)
{
  uint8_t v_0_u8 = (uint8_t)(((uint64_t)i_Value_s64 >> 0 ) & 0xFF);
  uint8_t v_1_u8 = (uint8_t)(((uint64_t)i_Value_s64 >> 8 ) & 0xFF);
  uint8_t v_2_u8 = (uint8_t)(((uint64_t)i_Value_s64 >> 16) & 0xFF);
  uint8_t v_3_u8 = (uint8_t)(((uint64_t)i_Value_s64 >> 24) & 0xFF);
  /* For example, if the type of the left hand operand is unsigned long, and long is implemented in 32 bits, the value of the right hand operand must not be less than 0 or greater than 31.*/
  /* PRQA S 2790 4 */ /* tested on our platform */
  uint8_t v_4_u8 = (uint8_t)(((uint64_t)i_Value_s64 >> 32) & 0xFF);
  uint8_t v_5_u8 = (uint8_t)(((uint64_t)i_Value_s64 >> 40) & 0xFF);
  uint8_t v_6_u8 = (uint8_t)(((uint64_t)i_Value_s64 >> 48) & 0xFF);
  uint8_t v_7_u8 = (uint8_t)(((uint64_t)i_Value_s64 >> 56) & 0xFF);

  if(NETWORK_ENDIANNESS_LITTLE == i_NetworkEndianness_b)
  {
    b_Data_pc[(*b_Index_pu32)    ] = v_0_u8;
    b_Data_pc[(*b_Index_pu32) + 1] = v_1_u8;
    b_Data_pc[(*b_Index_pu32) + 2] = v_2_u8;
    b_Data_pc[(*b_Index_pu32) + 3] = v_3_u8;
    b_Data_pc[(*b_Index_pu32) + 4] = v_4_u8;
    b_Data_pc[(*b_Index_pu32) + 5] = v_5_u8;
    b_Data_pc[(*b_Index_pu32) + 6] = v_6_u8;
    b_Data_pc[(*b_Index_pu32) + 7] = v_7_u8;
  }
  else
  {
    b_Data_pc[(*b_Index_pu32)    ] = v_7_u8;
    b_Data_pc[(*b_Index_pu32) + 1] = v_6_u8;
    b_Data_pc[(*b_Index_pu32) + 2] = v_5_u8;
    b_Data_pc[(*b_Index_pu32) + 3] = v_4_u8;
    b_Data_pc[(*b_Index_pu32) + 4] = v_3_u8;
    b_Data_pc[(*b_Index_pu32) + 5] = v_2_u8;
    b_Data_pc[(*b_Index_pu32) + 6] = v_1_u8;
    b_Data_pc[(*b_Index_pu32) + 7] = v_0_u8;
  }

  (*b_Index_pu32) += 8;
}

static void ME_DataSerializer_Write_u64(uint8_t* b_Data_pc, uint32_t* b_Index_pu32, uint64_t i_Value_u64, bool_t i_NetworkEndianness_b)
{
  uint8_t v_0_u8 = (uint8_t)((i_Value_u64      ) & 0xFF);
  uint8_t v_1_u8 = (uint8_t)((i_Value_u64 >> 8 ) & 0xFF);
  uint8_t v_2_u8 = (uint8_t)((i_Value_u64 >> 16) & 0xFF);
  uint8_t v_3_u8 = (uint8_t)((i_Value_u64 >> 24) & 0xFF);
  /* For example, if the type of the left hand operand is unsigned long, and long is implemented in 32 bits, the value of the right hand operand must not be less than 0 or greater than 31.*/
  /* PRQA S 2790 4 */ /* tested on our platform */
  uint8_t v_4_u8 = (uint8_t)((i_Value_u64 >> 32) & 0xFF);
  uint8_t v_5_u8 = (uint8_t)((i_Value_u64 >> 40) & 0xFF);
  uint8_t v_6_u8 = (uint8_t)((i_Value_u64 >> 48) & 0xFF);
  uint8_t v_7_u8 = (uint8_t)((i_Value_u64 >> 56) & 0xFF);

  if(NETWORK_ENDIANNESS_LITTLE == i_NetworkEndianness_b)
  {
    b_Data_pc[(*b_Index_pu32)    ] = v_0_u8;
    b_Data_pc[(*b_Index_pu32) + 1] = v_1_u8;
    b_Data_pc[(*b_Index_pu32) + 2] = v_2_u8;
    b_Data_pc[(*b_Index_pu32) + 3] = v_3_u8;
    b_Data_pc[(*b_Index_pu32) + 4] = v_4_u8;
    b_Data_pc[(*b_Index_pu32) + 5] = v_5_u8;
    b_Data_pc[(*b_Index_pu32) + 6] = v_6_u8;
    b_Data_pc[(*b_Index_pu32) + 7] = v_7_u8;
  }
  else
  {
    b_Data_pc[(*b_Index_pu32)    ] = v_7_u8;
    b_Data_pc[(*b_Index_pu32) + 1] = v_6_u8;
    b_Data_pc[(*b_Index_pu32) + 2] = v_5_u8;
    b_Data_pc[(*b_Index_pu32) + 3] = v_4_u8;
    b_Data_pc[(*b_Index_pu32) + 4] = v_3_u8;
    b_Data_pc[(*b_Index_pu32) + 5] = v_2_u8;
    b_Data_pc[(*b_Index_pu32) + 6] = v_1_u8;
    b_Data_pc[(*b_Index_pu32) + 7] = v_0_u8;
  }

  (*b_Index_pu32) += 8;
}

static void ME_DataSerializer_Write_f32(uint8_t* b_Data_pc, uint32_t* b_Index_pu32, float32_t i_Value_f32, bool_t i_NetworkEndianness_b)
{
  uint8_t *pdata = (uint8_t*)&i_Value_f32; /* PRQA S 3017 */ /* PRQA S 310 */ /* it is OK here to cast from float to uint8 data as it is copied in binary format here */

  uint8_t v_0_u8 = pdata[0];
  uint8_t v_1_u8 = pdata[1];
  uint8_t v_2_u8 = pdata[2];
  uint8_t v_3_u8 = pdata[3];

  if(NETWORK_ENDIANNESS_LITTLE == i_NetworkEndianness_b)
  {
    b_Data_pc[(*b_Index_pu32)    ] = v_0_u8;
    b_Data_pc[(*b_Index_pu32) + 1] = v_1_u8;
    b_Data_pc[(*b_Index_pu32) + 2] = v_2_u8;
    b_Data_pc[(*b_Index_pu32) + 3] = v_3_u8;
  }
  else
  {
    b_Data_pc[(*b_Index_pu32)    ] = v_3_u8;
    b_Data_pc[(*b_Index_pu32) + 1] = v_2_u8;
    b_Data_pc[(*b_Index_pu32) + 2] = v_1_u8;
    b_Data_pc[(*b_Index_pu32) + 3] = v_0_u8;
  }

  (*b_Index_pu32) += 4;
}

static void ME_DataSerializer_Write_s32(uint8_t* b_Data_pc, uint32_t* b_Index_pu32, sint32_t i_Value_s32, bool_t i_NetworkEndianness_b)
{
  uint8_t v_0_u8 = (uint8_t)(((uint32_t)i_Value_s32      ) & 0xFF);
  uint8_t v_1_u8 = (uint8_t)(((uint32_t)i_Value_s32 >> 8 ) & 0xFF);
  uint8_t v_2_u8 = (uint8_t)(((uint32_t)i_Value_s32 >> 16) & 0xFF);
  uint8_t v_3_u8 = (uint8_t)(((uint32_t)i_Value_s32 >> 24) & 0xFF);

  if(NETWORK_ENDIANNESS_LITTLE == i_NetworkEndianness_b)
  {
    b_Data_pc[(*b_Index_pu32)    ] = v_0_u8;
    b_Data_pc[(*b_Index_pu32) + 1] = v_1_u8;
    b_Data_pc[(*b_Index_pu32) + 2] = v_2_u8;
    b_Data_pc[(*b_Index_pu32) + 3] = v_3_u8;
  }
  else
  {
    b_Data_pc[(*b_Index_pu32)    ] = v_3_u8;
    b_Data_pc[(*b_Index_pu32) + 1] = v_2_u8;
    b_Data_pc[(*b_Index_pu32) + 2] = v_1_u8;
    b_Data_pc[(*b_Index_pu32) + 3] = v_0_u8;
  }

  (*b_Index_pu32) += 4;
}

static void ME_DataSerializer_Write_u32(uint8_t* b_Data_pc, uint32_t* b_Index_pu32, uint32_t i_Value_u32, bool_t i_NetworkEndianness_b)
{
  uint8_t v_0_u8 = (uint8_t)((i_Value_u32      ) & 0xFF);
  uint8_t v_1_u8 = (uint8_t)((i_Value_u32 >> 8 ) & 0xFF);
  uint8_t v_2_u8 = (uint8_t)((i_Value_u32 >> 16) & 0xFF);
  uint8_t v_3_u8 = (uint8_t)((i_Value_u32 >> 24) & 0xFF);

  if(NETWORK_ENDIANNESS_LITTLE == i_NetworkEndianness_b)
  {
    b_Data_pc[(*b_Index_pu32)    ] = v_0_u8;
    b_Data_pc[(*b_Index_pu32) + 1] = v_1_u8;
    b_Data_pc[(*b_Index_pu32) + 2] = v_2_u8;
    b_Data_pc[(*b_Index_pu32) + 3] = v_3_u8;
  }
  else
  {
    b_Data_pc[(*b_Index_pu32)    ] = v_3_u8;
    b_Data_pc[(*b_Index_pu32) + 1] = v_2_u8;
    b_Data_pc[(*b_Index_pu32) + 2] = v_1_u8;
    b_Data_pc[(*b_Index_pu32) + 3] = v_0_u8;
  }

  (*b_Index_pu32) += 4;
}

static void ME_DataSerializer_Write_s16(uint8_t* b_Data_pc, uint32_t* b_Index_pu32, sint16_t i_Value_s16, bool_t i_NetworkEndianness_b)
{
  uint8_t v_0_u8 = (uint8_t)(((uint16_t)i_Value_s16)      & 0xFF);
  uint8_t v_1_u8 = (uint8_t)(((uint16_t)i_Value_s16 >> 8) & 0xFF);

  if(NETWORK_ENDIANNESS_LITTLE == i_NetworkEndianness_b)
  {
    b_Data_pc[(*b_Index_pu32)    ] = v_0_u8;
    b_Data_pc[(*b_Index_pu32) + 1] = v_1_u8;
  }
  else
  {
    b_Data_pc[(*b_Index_pu32)    ] = v_1_u8;
    b_Data_pc[(*b_Index_pu32) + 1] = v_0_u8;
  }

  (*b_Index_pu32) += 2;
}

static void ME_DataSerializer_Write_u16(uint8_t* b_Data_pc, uint32_t* b_Index_pu32, uint16_t i_Value_u16, bool_t i_NetworkEndianness_b)
{
  uint8_t v_0_u8 = (uint8_t)((i_Value_u16)      & 0xFF);
  uint8_t v_1_u8 = (uint8_t)((i_Value_u16 >> 8) & 0xFF);

  if(NETWORK_ENDIANNESS_LITTLE == i_NetworkEndianness_b)
  {
    b_Data_pc[(*b_Index_pu32)    ] = v_0_u8;
    b_Data_pc[(*b_Index_pu32) + 1] = v_1_u8;
  }
  else
  {
    b_Data_pc[(*b_Index_pu32)    ] = v_1_u8;
    b_Data_pc[(*b_Index_pu32) + 1] = v_0_u8;
  }

  (*b_Index_pu32) += 2;
}

static void ME_DataSerializer_Write_s8(uint8_t* b_Data_pc, uint32_t* b_Index_pu32, sint8_t i_Value_s8, bool_t i_NetworkEndianness_b)
{
  if(NETWORK_ENDIANNESS_LITTLE == i_NetworkEndianness_b)
  {
    b_Data_pc[(*b_Index_pu32)] = (uint8_t)i_Value_s8;
  }
  else
  {
    b_Data_pc[(*b_Index_pu32)] = (uint8_t)i_Value_s8;
  }

  (*b_Index_pu32)++;
}

static void ME_DataSerializer_Write_u8(uint8_t* b_Data_pc, uint32_t* b_Index_pu32, uint8_t i_Value_u8, bool_t i_NetworkEndianness_b)
{
  if(NETWORK_ENDIANNESS_LITTLE == i_NetworkEndianness_b)
  {
    b_Data_pc[(*b_Index_pu32)] = i_Value_u8;
  }
  else
  {
    b_Data_pc[(*b_Index_pu32)] = i_Value_u8;
  }

  (*b_Index_pu32)++;
}


#endif // DATA_SERIALIZER_H
