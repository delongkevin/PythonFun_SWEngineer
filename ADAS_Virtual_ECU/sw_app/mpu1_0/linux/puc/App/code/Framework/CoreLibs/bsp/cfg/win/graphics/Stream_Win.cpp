//--------------------------------------------------------------------------
/// @file ME_Stream_WIN.h
/// @brief Interface to abstract standard-library Thread
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------

#include "bsp/graphics/Screen.h"
#include "bsp/graphics/Stream.h"

#include <platform/PlatformAPI.h>

#ifdef ME_PLATFORM_WIN

namespace bsp
{


Stream::Stream()
  : stream_t()
  , producerStream_t()
{

}

Stream::~Stream()
{

}

bool_t Stream::create_b(const char_t* i_StreamName_pc, ScreenContext_t i_ScreenContext_t)
{
  bool_t v_Result_b = true;

  return v_Result_b;
}

bool_t Stream::createConsumer_b()
{
  bool_t v_Result_b = true;

  return v_Result_b;
}

bool_t Stream::destroy_b() const
{
  bool_t v_Result_b = true;

  return v_Result_b;
}

// --------------------------------------------------------------------------------------------------
// Buffer related functions

bool_t Stream::acquireBuffer_b(ImageBufferData_t* o_ImageBufferData_pt, bool_t i_Blocking_b) const
{
  bool_t v_Result_b = true;

  return v_Result_b;
}

sint32_t Stream::getId_s32() const
{
  return getId_s32(&stream_t);
}

bool_t Stream::waitForProducer_b(ScreenContext_t i_ScreenContext_t, sint32_t i_ProducerStreamId_s32)
{
  bool_t v_Result_b = true;

  return v_Result_b;
}

bool_t Stream::setPermission_b(StreamPermission_t i_Permission_t) const
{
  bool_t v_Result_b = true;

  return v_Result_b;
}

bool_t Stream::isValid_b(const Stream& i_ScreenStream_ro)
{
  bool_t v_Result_b = true;

  return v_Result_b;
}

sint32_t Stream::getId_s32(const Stream_t* i_Stream_pt)
{
  sint32_t v_Id_s32 = -1;

  return v_Id_s32;
}

} // namespace bsp

#endif // ME_PLATFORM_QNX
