//--------------------------------------------------------------------------
/// @file Clock.h
/// @brief Start/stop/keep track of time
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

#ifndef OSAL_CLOCK_H
#define OSAL_CLOCK_H

#include "platform/PlatformAPI.h"

namespace osal
{
  class Clock
  {
  public:
    Clock();
    ~Clock();

    // --------------------------------------------------------------------------
    /// @return the absolute system time (in seconds)
    // --------------------------------------------------------------------------
    static float64_t getAbsoluteTime_f64();

    // --------------------------------------------------------------------------
    /// @return the total time, since the timer was started (in seconds)
    // --------------------------------------------------------------------------
    float64_t getTotalTime_f64() const;

    // --------------------------------------------------------------------------
    /// @return the time that elapsed since the previous call of this method (in seconds)
    // --------------------------------------------------------------------------
    float64_t getDeltaTime_f64();

    // --------------------------------------------------------------------------
    /// Start/Continue the timer
    /// @return void
    // --------------------------------------------------------------------------
    void start_v();

    // --------------------------------------------------------------------------
    /// Pause the timer
    /// @return void
    // --------------------------------------------------------------------------
    void stop_v();

    // --------------------------------------------------------------------------
    /// Reset timer, such that the next Start() looks like the first Start()
    /// @return void
    // --------------------------------------------------------------------------
    void reset_v();

    // --------------------------------------------------------------------------
    /// Increments an internal frame counter
    /// @return void
    // --------------------------------------------------------------------------
    void markFrame_v();

    // --------------------------------------------------------------------------
    /// Gets the current frame rate
    /// @return the current frame rate
    // --------------------------------------------------------------------------
    float32_t getFrameRate_f64() const;

    // --------------------------------------------------------------------------
    /// @return true if the clock is not running
    // --------------------------------------------------------------------------
    bool_t isStopped_b() const;

    // --------------------------------------------------------------------------
    /// Add a time offset to the current clock time
    // --------------------------------------------------------------------------
    void addTime_v(float64_t i_TimeOffset_f64);

  private:
    // disallow copy
    Clock& operator=(const Clock &i_Rhs_rs);
    Clock(const Clock& i_Rhs_rs);

  private:
    float64_t baseTime_f64;       ///< Describe the base of the total time, depending on start_v() and stop_v() of the timer
    float64_t stopTime_f64;       ///< Contain the absolute time when stop_v() was called
    bool_t    stopped_b;          ///< Is timer stopped?
    float64_t lastDeltaTime_f64;  ///< Hold the total time since the last getDeltaTime_f64() call
    uint32_t  frames_u32;         ///< Frame Counter
    float64_t fpsTime_f64;        ///< Absolute time to compute the frames per second.
    float32_t fps_f32;            ///< Frames Per Second
  };

} // namespace osal

#endif // OSAL_CLOCK_H
