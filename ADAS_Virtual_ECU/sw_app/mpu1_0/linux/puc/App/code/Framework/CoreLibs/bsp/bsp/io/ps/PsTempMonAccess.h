//--------------------------------------------------------------------------
/// @file PsTempMonAccess.h
/// @brief Handles the Information Request
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author   Roman Berngardt (Roman.Berngardt@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef PS_TEMPMON_ACCESS_H_
#define PS_TEMPMON_ACCESS_H_

namespace bsp
{

namespace tempmonconsts {
  static const uint32_t c_TemMonBaseAddress_u32 = 0xffa50000UL;
  static const uint32_t c_TemMonMapBaseAddress_u32 = 0xffa50000UL;
  static const uint32_t c_TemMonMapOffset_u32 = 0x800UL;
  static const uint32_t c_TemMonMapAreaSize_u32 = 0x1000UL;

  static const uint32_t c_TemMonAdcMask_u32  = 0x0FFC0UL;
  static const uint32_t c_TemMonAdcRSCnt_u32 = 0x06UL;

  static const float32_t c_TempCoeff_f32 = 509.3140064F; //502.9098F;
  static const float32_t c_StartTemp_f32 = 280.23087870F; //278.9265768; // 279.4265768F; //273.8195F;
  static const uint32_t c_AdcCoeff_u32 = 0xffffU;
} // namespace tempmonconsts

class PsTempMonAccess
{
public:
  static PsTempMonAccess&   getInstance_ro();
  explicit PsTempMonAccess();

  virtual bool_t readTempMonAdcValue_b(uint32_t& o_TempMonAdcValue_ru32);
  static float32_t convertAdcToTemperature_f32(const uint32_t& i_AdcValue_ru32);

private:
  PsTempMonAccess(PsTempMonAccess const&);
  void operator=(PsTempMonAccess const&);

  virtual void init_v();

private:
  bool_t isInitialized_b;
  void*  psSysMonBaseAddr_pv;
};

} /* namespace sys */

#endif /* PS_TEMPMON_ACCESS_H_ */
