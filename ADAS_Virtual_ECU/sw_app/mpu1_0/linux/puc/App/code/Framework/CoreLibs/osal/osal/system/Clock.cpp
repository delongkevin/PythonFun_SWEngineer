//--------------------------------------------------------------------------
/// @file Clock.cpp
/// @brief implementation of Clock class
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------

#include "Clock.h"

namespace osal
{
  Clock::Clock()
    : baseTime_f64(0.0f)
    , stopTime_f64(0.0f)
    , stopped_b(false)
    , lastDeltaTime_f64(0.0f)
    , frames_u32(0.0f)
    , fpsTime_f64(0.0f)
    , fps_f32(0.0f)
  {
    reset_v();
  }

  Clock::~Clock()
  {

  }

  float64_t Clock::getAbsoluteTime_f64()
  {
    float64_t v_Time_f64 = 0.0;

    (void)ME_Time_GetTimeMsecf64_t(&v_Time_f64);
    
    // convert to seconds
    v_Time_f64 /= 1000.0;

    return v_Time_f64;
  }

  float64_t Clock::getTotalTime_f64() const
  {
    float64_t v_TotalTime_f64 = 0.0f;

    if(stopped_b == true)
    {
      v_TotalTime_f64 = (stopTime_f64 - baseTime_f64);
    }
    else
    {
      v_TotalTime_f64 = getAbsoluteTime_f64() - baseTime_f64;
    }
    return v_TotalTime_f64;
  }

  float64_t Clock::getDeltaTime_f64()
  {
    float64_t v_Time_f64 = getTotalTime_f64();

    // Compute delta time since the last time GetDeltaTime() was called
    float64_t v_DeltaTime_f64 = static_cast<float64_t>(v_Time_f64 - lastDeltaTime_f64);

    // Set new last total time
    lastDeltaTime_f64 = v_Time_f64;

    return v_DeltaTime_f64;
  }

  void Clock::start_v()
  {
    // Check if the timer is currently running
    if (stopped_b == true)
    {
      float64_t v_Time_f64 = getAbsoluteTime_f64();

      // Check if stop time is legal respectively if timer is started first time
      if (stopTime_f64 < 0)
      {
        // Timer started first time
        baseTime_f64 = v_Time_f64;
      }
      else
      {
        float64_t v_LostTime_f64 = v_Time_f64 - stopTime_f64;

        baseTime_f64 = baseTime_f64 + v_LostTime_f64;
      }

      stopTime_f64 = 0.0;
      stopped_b = false;
    }
  }

  void Clock::stop_v()
  {
    if (!stopped_b)
    {
      stopTime_f64 = getAbsoluteTime_f64();
      stopped_b = true;
    }
  }

  void Clock::reset_v()
  {
    float64_t v_Time_f64 = getAbsoluteTime_f64();

    baseTime_f64 = 0.0;
    stopTime_f64 = -1.0;
    lastDeltaTime_f64 = 0.0;
    stopped_b = true;
    frames_u32 = 0;
    fpsTime_f64 = v_Time_f64;
  }

  void Clock::markFrame_v()
  {
    frames_u32++;

    float64_t v_AbsoluteTime_f64 = getAbsoluteTime_f64();

    // Only re-compute the FPS (frames per second) once per second
    if ((v_AbsoluteTime_f64 - fpsTime_f64) > 1.0)
    {
      fps_f32 = static_cast<float64_t>(frames_u32) / static_cast<float64_t>(v_AbsoluteTime_f64 - fpsTime_f64);
      fpsTime_f64 = v_AbsoluteTime_f64;
      frames_u32 = 0;
    }
  }

  float32_t Clock::getFrameRate_f64() const
  {
    return fps_f32;
  }

  bool_t Clock::isStopped_b() const
  {
    return stopped_b;
  }

  void Clock::addTime_v(float64_t i_TimeOffset_f64)
  {
    if (!stopped_b)
    {
      baseTime_f64 -= i_TimeOffset_f64;
      lastDeltaTime_f64 += i_TimeOffset_f64;
    }
  }

} // namespace osal
