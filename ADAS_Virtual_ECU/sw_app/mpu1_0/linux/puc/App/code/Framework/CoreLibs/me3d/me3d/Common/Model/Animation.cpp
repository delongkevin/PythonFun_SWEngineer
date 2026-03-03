
#include "Common/Model/Animation.h"


namespace me3d
{

  Animation::Animation() 
    : duration_f64(0.0)
    , ticksPerSec_f64(0.0)
    , numChannels_u32(0U)
    , name_o()
  {
  }

  Animation::~Animation()
  {
    duration_f64    = 0.0;
    ticksPerSec_f64 = 0.0;
    numChannels_u32 = 0U;

    // PRQA S 4631 1 // safe here
    name_o          = "";
  }

  const MEString& Animation::getName_ro() const
  {
    return name_o;
  }

  void Animation::setName_v(const MEString& i_Name_ro)
  {
    name_o = i_Name_ro;
  }

  float64_t Animation::getTicksPerSec_f64() const
  {
    // PRQA S 3270 1 // fine here, this checks the default value
    return (ticksPerSec_f64 != 0.0) ? ticksPerSec_f64 : 25.0;
  }

  void Animation::setTicksPerSec_f64(float64_t i_TicksPerSec_f64)
  {
    ticksPerSec_f64 = i_TicksPerSec_f64;
  }

  float64_t Animation::getDuration_f64() const
  {
    return duration_f64;
  }

  void Animation::setDuration_f64(float64_t i_Duration_f64)
  {
    duration_f64 = i_Duration_f64;
  }

  uint32_t Animation::getNumChannels_u32() const
  {
    return numChannels_u32;
  }

  void Animation::setNumChannels_v(uint32_t i_NumChannels_u32)
  {
    numChannels_u32 = i_NumChannels_u32;
  }

  AnimationChannel& Animation::getAnimationChannel_rs(uint32_t i_Index_u32)
  {
    Assert(i_Index_u32 < numChannels_u32);
    return channels_ao[i_Index_u32];
  }

  const AnimationChannel* Animation::findAnimationChannel_ps(const MEString& i_NodeName_ro)
  {
    const AnimationChannel* v_FoundChannel_ps = NULL;

    for (uint32_t v_I_u32 = 0U; v_I_u32 < numChannels_u32; v_I_u32++) 
    {
      const AnimationChannel& v_CurrentChannel_ps = getAnimationChannel_rs(v_I_u32);

      if (i_NodeName_ro == v_CurrentChannel_ps.getName_ro())
      {
        v_FoundChannel_ps = &v_CurrentChannel_ps;
        break;
      }
    }

    return v_FoundChannel_ps;
  }

  void Animation::serialize_v(InOut& b_IO_ro)
  {
    b_IO_ro.serialize_v(duration_f64);
    b_IO_ro.serialize_v(ticksPerSec_f64);
    b_IO_ro.serialize_v(numChannels_u32);
    b_IO_ro.serialize_v(name_o);

    for (uint32_t v_I_u32 = 0U; v_I_u32 < numChannels_u32; ++v_I_u32)
    {
      channels_ao[v_I_u32].serialize_v(b_IO_ro);
    }
  }

} // namespace me3d