/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

#ifndef PLATFORM_HELPER_H_
#define PLATFORM_HELPER_H_

#include "PlatformSpecs.h"

#ifdef __cplusplus
extern "C"
{
#endif

  // --------------------------------------------------------------------------
  /// Safety check to be called at application start for some basic checks.
  //
  /// The check shall include platform specific stuff, e.g. the endianness expected for the platform underneath.
  //
  /// @return true if the check passes, false otherwise.
  // --------------------------------------------------------------------------
  bool_t ME_Platform_F_SafetyCheck_b(void);

  // --------------------------------------------------------------------------
  /// Returns a signed WORD value corresponding to the value passed in with the endianness is swapped.
  ///
  /// The function converts the byte order of the passed parameter, i.e. from MSB to LSB and vice versa.
  ///
  /// @param[in] i_X_s16 Input parameter whose reversed byte-order correspondence has to be returned
  /// @return    Reversed byte-ordered value based on the passed parameter.
  // --------------------------------------------------------------------------
  sint16_t  ME_Platform_F_EndianSwap_s16(sint16_t  i_X_s16);

  // --------------------------------------------------------------------------
  /// Returns an unsigned WORD value corresponding to the value passed in with the endianness is swapped.
  ///
  /// The function converts the byte order of the passed parameter, i.e. from MSB to LSB and vice versa.
  ///
  /// @param[in] i_X_u16 Input parameter whose reversed byte-order correspondence has to be returned
  /// @return    Reversed byte-ordered value based on the passed parameter.
  // --------------------------------------------------------------------------
  uint16_t  ME_Platform_F_EndianSwap_u16(uint16_t  i_X_u16);

  // --------------------------------------------------------------------------
  /// Returns a signed DWORD value corresponding to the value passed in with the endianness is swapped.
  ///
  /// The function converts the byte order of the passed parameter, i.e. from MSB to LSB and vice versa.
  ///
  /// @param[in] i_X_s32 Input parameter whose reversed byte-order correspondence has to be returned
  /// @return    Reversed byte-ordered value based on the passed parameter.
  // --------------------------------------------------------------------------
  sint32_t  ME_Platform_F_EndianSwap_s32(sint32_t  i_X_s32);

  // --------------------------------------------------------------------------
  /// Returns an unsigned DWORD value corresponding to the value passed in with the endianness is swapped.
  ///
  /// The function converts the byte order of the passed parameter, i.e. from MSB to LSB and vice versa.
  ///
  /// @param[in] i_X_u32 Input parameter whose reversed byte-order correspondence has to be returned
  /// @return    Reversed byte-ordered value based on the passed parameter.
  // --------------------------------------------------------------------------
  uint32_t  ME_Platform_F_EndianSwap_u32(uint32_t  i_X_u32);

  // --------------------------------------------------------------------------
  /// Returns a signed DDWORD value corresponding to the value passed in with the endianness is swapped.
  ///
  /// The function converts the byte order of the passed parameter, i.e. from MSB to LSB and vice versa.
  ///
  /// @param[in] i_X_s64 Input parameter whose reversed byte-order correspondence has to be returned
  /// @return    Reversed byte-ordered value based on the passed parameter.
  // --------------------------------------------------------------------------
  sint64_t  ME_Platform_F_EndianSwap_s64(sint64_t  i_X_s64);

  // --------------------------------------------------------------------------
  /// Returns an unsigned DDWORD value corresponding to the value passed in with the endianness is swapped.
  ///
  /// The function converts the byte order of the passed parameter, i.e. from MSB to LSB and vice versa.
  ///
  /// @param[in] i_X_u64 Input parameter whose reversed byte-order correspondence has to be returned
  /// @return    Reversed byte-ordered value based on the passed parameter.
  // --------------------------------------------------------------------------
  uint64_t  ME_Platform_F_EndianSwap_u64(uint64_t  i_X_u64);

  // --------------------------------------------------------------------------
  /// Returns a float value corresponding to the value passed in with the endianness is swapped.
  ///
  /// The function converts the byte order of the passed parameter, i.e. from MSB to LSB and vice versa.
  ///
  /// @param[in] i_X_f32 Input parameter whose reversed byte-order correspondence has to be returned
  /// @return    Reversed byte-ordered value based on the passed parameter.
  // --------------------------------------------------------------------------
  float32_t ME_Platform_F_EndianSwap_f32(float32_t i_X_f32);

  // --------------------------------------------------------------------------
  /// Returns a double value corresponding to the value passed in with the endianness is swapped.
  ///
  /// The function converts the byte order of the passed parameter, i.e. from MSB to LSB and vice versa.
  ///
  /// @param[in] i_X_f64 Input parameter whose reversed byte-order correspondence has to be returned
  /// @return    Reversed byte-ordered value based on the passed parameter.
  // --------------------------------------------------------------------------
  float64_t ME_Platform_F_EndianSwap_f64(float64_t i_X_f64);

  // --------------------------------------------------------------------------
  /// Combines two bytes into a WORD.
  ///
  /// @param[in] i_High_u8 Byte value being the high byte of the returned value
  /// @param[in] i_Low_u8  Byte value being the low byte of the returned value
  /// @return    Calculated WORD value
  // --------------------------------------------------------------------------
  uint16_t ME_Platform_F_MakeWord_u16(uint8_t i_High_u8, uint8_t i_Low_u8);

  // --------------------------------------------------------------------------
  /// Returns the low byte of a WORD.
  /// @param[in] i_X_u16 WORD value whose low byte has to be extracted
  /// @return    Low byte of the passed WORD
  // --------------------------------------------------------------------------
  uint8_t  ME_Platform_F_GetLoByte_u8(uint16_t i_X_u16);

  // --------------------------------------------------------------------------
  /// Returns the high byte of a WORD.
  ///
  /// @param[in] i_X_u16 WORD value whose high byte has to be extracted
  /// @return    High byte of the passed WORD
  // --------------------------------------------------------------------------
  uint8_t  ME_Platform_F_GetHiByte_u8(uint16_t i_X_u16);

  // --------------------------------------------------------------------------
  /// Combines two WORDs into a DWORD
  ///
  /// @param[in] i_High_u16 WORD value being the high WORD of the returned value
  /// @param[in] i_Low_u16  WORD value being the low WORD of the returned value
  /// @return    Calculated DWORD value
  // --------------------------------------------------------------------------
  uint32_t ME_Platform_F_MakeDword_u32(uint16_t i_High_u16, uint16_t i_Low_u16);

  // --------------------------------------------------------------------------
  /// Returns the low WORD of a DWORD.
  ///
  /// @param[in] i_X_u32 DWORD value whose low WORD has to be extracted
  /// @return    Low WORD of the passed DWORD
  // --------------------------------------------------------------------------
  uint16_t ME_Platform_F_GetLoWord_u16(uint32_t i_X_u32);

  // --------------------------------------------------------------------------
  /// Returns the high WORD of a DWORD.
  ///
  /// @param[in] i_X_u32 DWORD value whose high WORD has to be extracted
  /// @return    High WORD of the passed DWORD
  // --------------------------------------------------------------------------
  uint16_t ME_Platform_F_GetHiWord_u16(uint32_t i_X_u32);

  // --------------------------------------------------------------------------
  /// Combines two DWORDs into a DDWORD
  ///
  /// @param[in] i_High_u32 DWORD value being the high DWORD of the returned value
  /// @param[in] i_Low_u32  DWORD value being the low DWORD of the returned value
  /// @return    Calculated DDWORD value
  // --------------------------------------------------------------------------
  uint64_t ME_Platform_F_MakeQword_u64(uint32_t i_High_u32, uint32_t i_Low_u32);

  // --------------------------------------------------------------------------
  /// Returns the low DWORD of a DDWORD.
  ///
  /// @param[in] i_X_u64 DDWORD value whose low DWORD has to be extracted
  /// @return    Low DWORD of the passed DDWORD
  // --------------------------------------------------------------------------
  uint32_t ME_Platform_F_GetLoDword_u32(uint64_t i_X_u64);

  // --------------------------------------------------------------------------
  /// Returns the high DWORD of a DDWORD.
  ///
  /// @param[in] i_X_u64 DDWORD value whose high DWORD has to be extracted
  /// @return    High DWORD of the passed DDWORD
  // --------------------------------------------------------------------------
  uint32_t ME_Platform_F_GetHiDword_u32(uint64_t i_X_u64);

  // --------------------------------------------------------------------------
  /// Encodes the specified characters into one unsigned DWORD.
  ///
  /// @param[in] v_C0_c Character value representing bits [0..7] of the returned value
  /// @param[in] v_C1_c Character value representing bits [8..15] of the returned value
  /// @param[in] v_C2_c Character value representing bits [16..23] of the returned value.
  /// @param[in] v_C3_c Character value representing bits [24..31] of the returned value.
  /// @return    Encoded uint32_t value.
  // --------------------------------------------------------------------------
  uint32_t ME_Platform_F_MakeFourCC_u32(const char_t* i_CC_pc);

  // --------------------------------------------------------------------------
  /// Extracts bytes out of a unsigned DWORD and stores them into the byte variables passed in.
  ///
  /// @param[in]  i_Input_u32 DWORD value from which bytes have to be extracted
  /// @param[out] v_C0_c Byte variable bits [0..7] have to be stored to
  /// @param[out] v_C1_c Byte variable bits [8..15] have to be stored to
  /// @param[out] v_C2_c Byte variable bits [16..23] have to be stored to
  /// @param[out] v_C3_c Byte variable bits [24..31] have to be stored to
  // --------------------------------------------------------------------------
  void ME_Platform_F_MakeFourCCInv_v(uint32_t i_Input_u32, sint8_t* v_C0_c, sint8_t* v_C1_c, sint8_t* v_C2_c, sint8_t* v_C3_c);

  // --------------------------------------------------------------------------
  /// Provides string representation of the DWORD value passed in.
  ///
  /// @pre        Size of the character buffer passed in is assumed to be equal or larger than 5.
  ///
  /// @param[in]  i_Input_u32 DWORD value to be represented as string
  /// @param[out] o_Output_pc Character buffer to be stored to
  // --------------------------------------------------------------------------
  void ME_Platform_F_U32ToStr_v(const uint32_t i_Input_u32, char_t* o_Output_pc);

  // --------------------------------------------------------------------------
  /// Calculates the population count of an unsigned 32 bit integer.
  ///
  /// The population count is the number of bits in the integer set to 1.
  ///
  /// @param[in] i_X_u32 Unsigned DWORD value whose population count is to be calculated
  /// @return    Population count calculated
  // --------------------------------------------------------------------------
  ME_INLINE uint32_t ME_Platform_F_PopCount_u32(uint32_t i_X_u32)
  {
    const uint32_t a = i_X_u32 - ( ( i_X_u32 >> 1 )       & 0x55555555 );
    const uint32_t b =   ( ( ( a >> 2 )       & 0x33333333 ) + ( a & 0x33333333 ) );
    const uint32_t c =   ( ( ( b >> 4 ) + b ) & 0x0f0f0f0f );
    const uint32_t d =   c + ( c >> 8 );
    const uint32_t e =   d + ( d >> 16 );
    const uint32_t result = e & 0x0000003f;
    return result;
  }

  // --------------------------------------------------------------------------
  /// Converts a unsigned WORD value from network byte order to local byte order.
  ///
  /// @pre       Passed in value is assumed to be of network byte order already.
  /// @pre       Local byte order is assumed to be defined based on the configuration setting of
  ///            the compile switch \c ME_BIG_ENDIAN, i.e. \c 1 for big endian,
  ///            \c 0 for little endian.
  ///
  /// @param[in] i_X_u16 Unsigned WORD value to be converted according to the local byte order
  /// @return    Calculated value based on local byte order
  /// @note      The implementation seems to do exactly the reverse of what is supposed to do!
  // --------------------------------------------------------------------------
  uint16_t ME_Platform_F_NetworkToHost_u16(uint16_t i_X_u16);

  // --------------------------------------------------------------------------
  /// Converts a unsigned WORD value from local byte order to network byte order.
  ///
  /// @pre       Passed in value is assumed to be of local byte order already.
  /// @pre       Local byte order is assumed to be defined based on the configuration setting of
  ///            the compile switch \c ME_BIG_ENDIAN, i.e. \c 1 for big endian,
  ///            \c 0 for little endian.
  ///
  /// @param[in] i_X_u16 Unsigned WORD value to be converted according to the network byte order
  /// @return    Calculated value based on network byte order
  /// @note      The implementation seems to do exactly the reverse of what is supposed to do!
  // --------------------------------------------------------------------------
  uint16_t ME_Platform_F_HostToNetwork_u16(uint16_t i_X_u16);

#ifdef __cplusplus
}
#endif

#endif // PLATFORM_HELPER_H_
