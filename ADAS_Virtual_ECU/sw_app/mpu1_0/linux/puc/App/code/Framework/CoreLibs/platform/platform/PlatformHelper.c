/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

#include "PlatformHelper.h"

#ifdef ME_PLATFORM_QNX
#include <string.h>
#elif defined(ME_PLATFORM_WIN)
#include <string.h>
#endif

// PRQA S 4130 EOF // Bitwise operations on signed data necessary in whole file
// PRQA S 0502 EOF // Only logical shift
// PRQA S 2985 EOF // It's easier to read the code with masking the bits

// PRQA S 0750 EOF // Using unions is a common method to do the endian swap for float values
// PRQA S 0759 EOF // Using unions is a common method to do the endian swap for float values
// PRQA S 3629 EOF // Using unions is a common method to do the endian swap for float values


bool_t ME_Platform_F_SafetyCheck_b(void)
{
  // Endian check
  bool_t v_Return_b = true;
  uint32_t v_X_u32 = 1;

  if (((uint8_t*)&v_X_u32)[0] == 1) // PRQA S 0310 // needed here to evaluate endianness
  {
#if ME_BIG_ENDIAN
    // wrong endian!
    v_Return_b = false;
#endif
  }
  else
  {
#if ME_LITTLE_ENDIAN
    // wrong endianness!
    v_Return_b = false;
#endif
  }

  return v_Return_b;
}

sint16_t ME_Platform_F_EndianSwap_s16(sint16_t i_X_s16)
{
  return ((i_X_s16 & 0xff) << 8) | ((i_X_s16 >> 8) & 0xff);
}

uint16_t ME_Platform_F_EndianSwap_u16(uint16_t i_X_u16)
{
  return ((i_X_u16 & 0xff) << 8) | ((i_X_u16 >> 8) & 0xff); // PRQA S 2985 // Ensure only using the lowest 8 bit
}

sint32_t ME_Platform_F_EndianSwap_s32(sint32_t i_X_s32)
{
  return ((i_X_s32 & 0xff) << 24) | (((i_X_s32 >> 8) & 0xff) << 16) |
    (((i_X_s32 >> 16) & 0xff) << 8 ) | ((i_X_s32 >> 24) & 0xff);
}

uint32_t ME_Platform_F_EndianSwap_u32(uint32_t i_X_u32) /* PRQA S 1505 */ /* keep it public */
{
  return ((i_X_u32 & 0xff) << 24) | (((i_X_u32 >> 8) & 0xff) << 16) |
    (((i_X_u32 >> 16) & 0xff) << 8 ) | ((i_X_u32 >> 24) & 0xff);
}

sint64_t ME_Platform_F_EndianSwap_s64(sint64_t i_X_s64) /* PRQA S 1505 */ /* keep it public */
{
  return
    ((i_X_s64 & 0xff) << 56)         | (((i_X_s64 >>  8) & 0xff) << 48) |
    (((i_X_s64 >> 16) & 0xff) << 40) | (((i_X_s64 >> 24) & 0xff) << 32) |
    (((i_X_s64 >> 32) & 0xff) << 24) | (((i_X_s64 >> 40) & 0xff) << 16) |
    (((i_X_s64 >> 48) & 0xff) << 8 ) |  ((i_X_s64 >> 56) & 0xff);
}

uint64_t ME_Platform_F_EndianSwap_u64(uint64_t i_X_u64) /* PRQA S 1505 */ /* keep this function public */
{
  /* get rid of Msg 7:2790: shift two times  */
  return
    (((i_X_u64 & 0xff) << 30) << 26)         | ((((i_X_u64 >> 8 ) & 0xff) << 20) << 28) |
    ((((i_X_u64 >> 16) & 0xff) << 20) << 20) | ((((i_X_u64 >> 24) & 0xff) << 20) << 12) |
    ((((i_X_u64 >> 20) >> 12) & 0xff) << 24) | ((((i_X_u64 >> 20) >> 20) & 0xff) << 16) |
    ((((i_X_u64 >> 20) >> 28) & 0xff) << 8 ) | ( ((i_X_u64 >> 30) >> 26) & 0xff);
}

float32_t ME_Platform_F_EndianSwap_f32(float32_t i_X_f32)
{
  // C++' strict aliasing rule prohibits the usage of *(uint32_t)&x,
  // so we use a union here
  union
  {
    float32_t d;
    uint32_t  u;

  } helperUnion;

  helperUnion.d = i_X_f32;
  helperUnion.u = ME_Platform_F_EndianSwap_u32(helperUnion.u);
  return helperUnion.d;
}

float64_t ME_Platform_F_EndianSwap_f64(float64_t i_X_f64)
{
  // C++' strict aliasing rule prohibits the usage of *(uint32_t)&x,
  // so we use a union here
  union
  {
    float64_t d;
    uint64_t  u;

  } helperUnion;

  helperUnion.d = i_X_f64;
  helperUnion.u = ME_Platform_F_EndianSwap_u64(helperUnion.u);
  return helperUnion.d;
}

uint16_t ME_Platform_F_MakeWord_u16(uint8_t i_High_u8, uint8_t i_Low_u8)
{
  return ((uint16_t)i_High_u8 << 8) | (uint16_t)i_Low_u8;
}

uint8_t ME_Platform_F_GetLoByte_u8(uint16_t i_X_u16)
{
  return (uint8_t)(i_X_u16 & 0xff);
}

uint8_t ME_Platform_F_GetHiByte_u8(uint16_t i_X_u16)
{
  return (uint8_t)((i_X_u16 >> 8) & 0xff);
}

uint32_t ME_Platform_F_MakeDword_u32(uint16_t i_High_u16, uint16_t i_Low_u16)
{
  return ((uint32_t)i_High_u16 << 16) | (uint32_t)i_Low_u16;
}

uint16_t ME_Platform_F_GetLoWord_u16(uint32_t i_X_u32)
{
  return (uint16_t)(i_X_u32 & 0xffff);
}

uint16_t ME_Platform_F_GetHiWord_u16(uint32_t i_X_u32)
{
  return (uint16_t)((i_X_u32 >> 16) & 0xffff);
}

uint64_t ME_Platform_F_MakeQword_u64(uint32_t i_High_u32, uint32_t i_Low_u32)
{
  /* QAC: For example, if the type of the left hand operand is unsigned long, and long is implemented in 32 bits, the value of the right hand operand must not be less than 0 or greater than 31.*/
  return (((uint64_t)i_High_u32 << 16) << 16) | (uint64_t)i_Low_u32; /* get rid of Msg 7:2790: shift two times by 16 */
}

uint32_t ME_Platform_F_GetLoDword_u32(uint64_t i_X_u64)
{
  return (uint32_t)(i_X_u64 & 0xffffffffU);
}

uint32_t ME_Platform_F_GetHiDword_u32(uint64_t i_X_u64)
{
  /* QAC: For example, if the type of the left hand operand is unsigned long, and long is implemented in 32 bits, the value of the right hand operand must not be less than 0 or greater than 31.*/
  return (uint32_t)(((i_X_u64 >> 16) >> 16) & 0xffffffffU); /* get rid of Msg 7:2790: shift two times by 16 */
}

uint32_t ME_Platform_F_MakeFourCC_u32(const char_t* i_CC_pc)
{
  return ((uint32_t)i_CC_pc[0] | ((uint32_t)i_CC_pc[1] << 8) | ((uint32_t)i_CC_pc[2] << 16) | ((uint32_t)i_CC_pc[3] << 24));
}

void ME_Platform_F_MakeFourCCInv_v(uint32_t i_Input_u32, sint8_t* v_C0_c, sint8_t* v_C1_c, sint8_t* v_C2_c, sint8_t* v_C3_c)
{
  if ((v_C0_c != NULL) && (v_C1_c != NULL) && (v_C2_c != NULL) && (v_C3_c != NULL))
  {
    *v_C0_c = (sint8_t)(i_Input_u32 & 0x000000FFU);
    *v_C1_c = (sint8_t)((i_Input_u32 & 0x0000FF00U) >> 8);
    *v_C2_c = (sint8_t)((i_Input_u32 & 0x00FF0000U) >> 16);
    *v_C3_c = (sint8_t)((i_Input_u32 & 0xFF000000U) >> 24);
  }
}

void ME_Platform_F_U32ToStr_v(const uint32_t i_Input_u32, char_t* o_Output_pc)
{
  if(o_Output_pc != NULL)
  {
    // PRQA S 0492 ++ // subscript operator necessary here
    o_Output_pc[3] = (char_t)((i_Input_u32 & 0xFF000000U) >> 24);
    o_Output_pc[2] = (char_t)((i_Input_u32 & 0x00FF0000U) >> 16);
    o_Output_pc[1] = (char_t)((i_Input_u32 & 0x0000FF00U) >> 8);
    o_Output_pc[0] = (char_t)(i_Input_u32 & 0x000000FFU);
    o_Output_pc[4] = '\0';
    // PRQA S 0492 -- // subscript operator necessary here
  }
}

uint16_t ME_Platform_F_NetworkToHost_u16(uint16_t i_X_u16)
{
#if ME_BIG_ENDIAN
  return ME_Platform_F_EndianSwap_u16(i_X_u16);
#else
  return i_X_u16;
#endif
}

uint16_t ME_Platform_F_HostToNetwork_u16(uint16_t i_X_u16)
{
#if ME_BIG_ENDIAN
  return ME_Platform_F_EndianSwap_u16(i_X_u16);
#else
  return i_X_u16;
#endif
}
