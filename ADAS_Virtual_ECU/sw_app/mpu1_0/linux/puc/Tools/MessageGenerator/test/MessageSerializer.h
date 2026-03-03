#ifndef MESSAGE_SERIALIZER_H
#define MESSAGE_SERIALIZER_H

// TODO: include platform specs
#include <stddef.h>
typedef signed    __int8   sint8_t;
typedef unsigned  __int8   uint8_t;
typedef signed    __int16  sint16_t;
typedef unsigned  __int16  uint16_t;
typedef signed    __int32  sint32_t;
typedef unsigned  __int32  uint32_t;
typedef signed    __int64  sint64_t;
typedef unsigned  __int64  uint64_t;
typedef float              float32_t;
typedef double             float64_t;
typedef char               char_t;
typedef bool               bool_t;


uint64_t read_s64(const uint8_t* i_Data_pc, uint32_t* b_Index_pu32)
{
  uint64_t v_Data_u64 = 
    ((uint64_t)i_Data_pc[*b_Index_pu32  ]      ) | 
    ((uint64_t)i_Data_pc[*b_Index_pu32+1] <<  8) | 
    ((uint64_t)i_Data_pc[*b_Index_pu32+2] << 16) | 
    ((uint64_t)i_Data_pc[*b_Index_pu32+3] << 24) |
    ((uint64_t)i_Data_pc[*b_Index_pu32+4] << 32) |
    ((uint64_t)i_Data_pc[*b_Index_pu32+5] << 40) |
    ((uint64_t)i_Data_pc[*b_Index_pu32+6] << 48) |
    ((uint64_t)i_Data_pc[*b_Index_pu32+7] << 56);

  *b_Index_pu32 += 8;

  return v_Data_u64;
}

uint64_t read_u64(const uint8_t* i_Data_pc, uint32_t* b_Index_pu32)
{
  sint64_t v_Data_s64 = 
    ((uint64_t)i_Data_pc[*b_Index_pu32  ]      ) | 
    ((uint64_t)i_Data_pc[*b_Index_pu32+1] <<  8) | 
    ((uint64_t)i_Data_pc[*b_Index_pu32+2] << 16) | 
    ((uint64_t)i_Data_pc[*b_Index_pu32+3] << 24) |
    ((uint64_t)i_Data_pc[*b_Index_pu32+4] << 32) |
    ((uint64_t)i_Data_pc[*b_Index_pu32+5] << 40) |
    ((uint64_t)i_Data_pc[*b_Index_pu32+6] << 48) |
    ((uint64_t)i_Data_pc[*b_Index_pu32+7] << 56);

  *b_Index_pu32 += 8;

  return v_Data_s64;
}


float32_t read_f32(const uint8_t* i_Data_pc, uint32_t* b_Index_pu32)
{
  float32_t v_Data_f32 = (float32_t)(
    (i_Data_pc[*b_Index_pu32    ]    ) | 
    (i_Data_pc[*b_Index_pu32+1] <<  8) | 
    (i_Data_pc[*b_Index_pu32+2] << 16) | 
    (i_Data_pc[*b_Index_pu32+3] << 24));

  *b_Index_pu32 += 4;

  return v_Data_f32;
}

sint32_t read_s32(const uint8_t* i_Data_pc, uint32_t* b_Index_pu32)
{
  sint32_t v_Data_s32 = 
    (i_Data_pc[*b_Index_pu32  ]      ) | 
    (i_Data_pc[*b_Index_pu32+1] <<  8) | 
    (i_Data_pc[*b_Index_pu32+2] << 16) | 
    (i_Data_pc[*b_Index_pu32+3] << 24);

  *b_Index_pu32 += 4;

  return v_Data_s32;
}

uint32_t read_u32(const uint8_t* i_Data_pc, uint32_t* b_Index_pu32)
{
  uint32_t v_Data_u32 = 
    (i_Data_pc[*b_Index_pu32    ]    ) | 
    (i_Data_pc[*b_Index_pu32+1] <<  8) | 
    (i_Data_pc[*b_Index_pu32+2] << 16) | 
    (i_Data_pc[*b_Index_pu32+3] << 24);

  *b_Index_pu32 += 4;

  return v_Data_u32;
}


sint16_t read_s16(const uint8_t* i_Data_pc, uint32_t* b_Index_pu32)
{
  sint16_t v_Data_s16 = 
    (i_Data_pc[*b_Index_pu32  ]      ) | 
    (i_Data_pc[*b_Index_pu32+1] <<  8);

  *b_Index_pu32 += 2;

  return v_Data_s16;
}

uint16_t read_u16(const uint8_t* i_Data_pc, uint32_t* b_Index_pu32)
{
  uint16_t v_Data_u16 = 
    (i_Data_pc[*b_Index_pu32  ]      ) | 
    (i_Data_pc[*b_Index_pu32+1] <<  8);

  *b_Index_pu32 += 2;

  return v_Data_u16;
}

sint8_t read_s8(const uint8_t* i_Data_pc, uint32_t* b_Index_pu32)
{
  sint8_t v_Data_s8 = i_Data_pc[*b_Index_pu32];

  (*b_Index_pu32)++;

  return v_Data_s8;
}

uint8_t read_u8(const uint8_t* i_Data_pc, uint32_t* b_Index_pu32)
{
  uint8_t v_Data_u8 = i_Data_pc[*b_Index_pu32];

  (*b_Index_pu32)++;

  return v_Data_u8;
}

// --- Write Functions ---

void write_s64(uint8_t* b_Data_pc, uint32_t* b_Index_pu32, sint64_t i_Value_s64)
{
  uint8_t v_0_u8 = (i_Value_s64      ) & 0xFF;
  uint8_t v_1_u8 = (i_Value_s64 >> 8 ) & 0xFF;
  uint8_t v_2_u8 = (i_Value_s64 >> 16) & 0xFF;
  uint8_t v_3_u8 = (i_Value_s64 >> 24) & 0xFF;
  uint8_t v_4_u8 = (i_Value_s64 >> 32) & 0xFF;
  uint8_t v_5_u8 = (i_Value_s64 >> 40) & 0xFF;
  uint8_t v_6_u8 = (i_Value_s64 >> 48) & 0xFF;
  uint8_t v_7_u8 = (i_Value_s64 >> 56) & 0xFF;

  b_Data_pc[(*b_Index_pu32)    ] = v_0_u8;
  b_Data_pc[(*b_Index_pu32) + 1] = v_1_u8;
  b_Data_pc[(*b_Index_pu32) + 2] = v_2_u8;
  b_Data_pc[(*b_Index_pu32) + 3] = v_3_u8;
  b_Data_pc[(*b_Index_pu32) + 4] = v_4_u8;
  b_Data_pc[(*b_Index_pu32) + 5] = v_5_u8;
  b_Data_pc[(*b_Index_pu32) + 6] = v_6_u8;
  b_Data_pc[(*b_Index_pu32) + 7] = v_7_u8;

  (*b_Index_pu32) += 8;
}

void write_u64(uint8_t* b_Data_pc, uint32_t* b_Index_pu32, uint64_t i_Value_u64)
{
  uint8_t v_0_u8 = (i_Value_u64      ) & 0xFF;
  uint8_t v_1_u8 = (i_Value_u64 >> 8 ) & 0xFF;
  uint8_t v_2_u8 = (i_Value_u64 >> 16) & 0xFF;
  uint8_t v_3_u8 = (i_Value_u64 >> 24) & 0xFF;
  uint8_t v_4_u8 = (i_Value_u64 >> 32) & 0xFF;
  uint8_t v_5_u8 = (i_Value_u64 >> 40) & 0xFF;
  uint8_t v_6_u8 = (i_Value_u64 >> 48) & 0xFF;
  uint8_t v_7_u8 = (i_Value_u64 >> 56) & 0xFF;

  b_Data_pc[(*b_Index_pu32)    ] = v_0_u8;
  b_Data_pc[(*b_Index_pu32) + 1] = v_1_u8;
  b_Data_pc[(*b_Index_pu32) + 2] = v_2_u8;
  b_Data_pc[(*b_Index_pu32) + 3] = v_3_u8;
  b_Data_pc[(*b_Index_pu32) + 4] = v_4_u8;
  b_Data_pc[(*b_Index_pu32) + 5] = v_5_u8;
  b_Data_pc[(*b_Index_pu32) + 6] = v_6_u8;
  b_Data_pc[(*b_Index_pu32) + 7] = v_7_u8;

  (*b_Index_pu32) += 8;
}

void write_f32(uint8_t* b_Data_pc, uint32_t* b_Index_pu32, float32_t i_Value_f32)
{
  uint8_t v_0_u8 = ((uint32_t)i_Value_f32      ) & 0xFF;
  uint8_t v_1_u8 = ((uint32_t)i_Value_f32 >> 8 ) & 0xFF;
  uint8_t v_2_u8 = ((uint32_t)i_Value_f32 >> 16) & 0xFF;
  uint8_t v_3_u8 = ((uint32_t)i_Value_f32 >> 24) & 0xFF;

  b_Data_pc[(*b_Index_pu32)    ] = v_0_u8;
  b_Data_pc[(*b_Index_pu32) + 1] = v_1_u8;
  b_Data_pc[(*b_Index_pu32) + 2] = v_2_u8;
  b_Data_pc[(*b_Index_pu32) + 3] = v_3_u8;

  (*b_Index_pu32) += 4;
}

void write_s32(uint8_t* b_Data_pc, uint32_t* b_Index_pu32, sint32_t i_Value_s32)
{
  uint8_t v_0_u8 = (i_Value_s32      ) & 0xFF;
  uint8_t v_1_u8 = (i_Value_s32 >> 8 ) & 0xFF;
  uint8_t v_2_u8 = (i_Value_s32 >> 16) & 0xFF;
  uint8_t v_3_u8 = (i_Value_s32 >> 24) & 0xFF;

  b_Data_pc[(*b_Index_pu32)    ] = v_0_u8;
  b_Data_pc[(*b_Index_pu32) + 1] = v_1_u8;
  b_Data_pc[(*b_Index_pu32) + 2] = v_2_u8;
  b_Data_pc[(*b_Index_pu32) + 3] = v_3_u8;

  (*b_Index_pu32) += 4;
}

void write_u32(uint8_t* b_Data_pc, uint32_t* b_Index_pu32, uint32_t i_Value_u32)
{
  uint8_t v_0_u8 = (i_Value_u32      ) & 0xFF;
  uint8_t v_1_u8 = (i_Value_u32 >> 8 ) & 0xFF;
  uint8_t v_2_u8 = (i_Value_u32 >> 16) & 0xFF;
  uint8_t v_3_u8 = (i_Value_u32 >> 24) & 0xFF;

  b_Data_pc[(*b_Index_pu32)    ] = v_0_u8;
  b_Data_pc[(*b_Index_pu32) + 1] = v_1_u8;
  b_Data_pc[(*b_Index_pu32) + 2] = v_2_u8;
  b_Data_pc[(*b_Index_pu32) + 3] = v_3_u8;

  (*b_Index_pu32) += 4;
}

void write_s16(uint8_t* b_Data_pc, uint32_t* b_Index_pu32, sint16_t i_Value_s16)
{
  uint8_t v_0_u8 = (i_Value_s16)      & 0xFF;
  uint8_t v_1_u8 = (i_Value_s16 >> 8) & 0xFF;

  b_Data_pc[(*b_Index_pu32)    ] = v_0_u8;
  b_Data_pc[(*b_Index_pu32) + 1] = v_1_u8;

  (*b_Index_pu32) += 2;
}

void write_u16(uint8_t* b_Data_pc, uint32_t* b_Index_pu32, uint16_t i_Value_u16)
{
  uint8_t v_0_u8 = (i_Value_u16)      & 0xFF;
  uint8_t v_1_u8 = (i_Value_u16 >> 8) & 0xFF;

  b_Data_pc[(*b_Index_pu32)    ] = v_0_u8;
  b_Data_pc[(*b_Index_pu32) + 1] = v_1_u8;

  (*b_Index_pu32) += 2;
}

void write_s8(uint8_t* b_Data_pc, uint32_t* b_Index_pu32, sint8_t i_Value_s8)
{
  b_Data_pc[(*b_Index_pu32)] = i_Value_s8;

  (*b_Index_pu32)++;
}

void write_u8(uint8_t* b_Data_pc, uint32_t* b_Index_pu32, uint8_t i_Value_u8)
{
  b_Data_pc[(*b_Index_pu32)] = i_Value_u8;

  (*b_Index_pu32)++;
}


#endif // MESSAGE_SERIALIZER_H