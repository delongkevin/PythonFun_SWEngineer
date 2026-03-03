//--------------------------------------------------------------------------
/// @file FpgaZCU102.h
/// @brief Implementation of QNX camera interface
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
//  --------------------------------------------------------------------------

#ifndef FPGA_ZCU102_H_
#define FPGA_ZCU102_H_

#include <platform/PlatformAPI.h>

// TODO: Remove variants from CMAKE
#include <variants/Enums.h>

#include <osal/threading/Thread.h>

#include "FpgaLayerEngine.h"
#include "FpgaViewGen.h"
#include "FpgaAlgoView.h"
#include "FpgaVideoInput.h"
#include "FpgaVideoOutput.h"
#include "AxisMipMem.h"

namespace bsp
{


enum FpgaState_e
{
  e_FpgaStateNotInitialized = 0,
  e_FpgaStateInitalized,
  e_FpgaStateCount,
  e_FpgaStateInvalid
};

struct FpgaVersion_s
{
  uint8_t year_u8;
  uint8_t week_u8;
  uint8_t day_u8;
  uint8_t buildNumber_u8;
};

class FpgaZCU102
{

  static void* frameTriggerThread_pv(void* i_Args_pv);

public:

  FpgaZCU102();

  virtual ~FpgaZCU102();

public:

  bool_t     init_b();

public:

  FpgaLayerEngine&     getFpgaLayerEngine_ro();

  FpgaViewGen&         getFpgaViewGen_ro();

  FpgaAlgoView&        getFpgaAlgoView_ro();

  FpgaVideoInput&      getFpgaVideoInput_ro();

  FpgaVideoOutput&     getFpgaVideoOutput_ro();

  AxisMipMem&          getAxisMipMem_ro();

public:

  void                 setFrameNumber_v(uint32_t i_FrameNumber_u32);

public:

  FpgaVersion_s        getFpgaVersion_s();

  variants::ViewId_t   getViewId_t() const { return viewId_t; }

  FpgaState_e          getFpgaState_e() const { return fpgaState_e; }

  uint32_t             getFrameTrigger_u32();

private:

  FpgaState_e                        fpgaState_e;

  FpgaLayerEngine                    fpgaLayerEngine_o;

  FpgaViewGen                        fpgaViewGen_o;

  FpgaAlgoView                       fpgaAlgoView_o;

  FpgaVideoInput                     fpgaVideoInput_o;

  FpgaVideoOutput                    fpgaVideoOutput_o;

  AxisMipMem                         axisMipMem_o;

private:

  osal::SoftwareInterrupt            softwareInterrupt_o;

  uint32_t                           frameNumber_u32;

protected:

  /// -------------------------------------------------------------------------------

  void*                              plBaseAddress_pv;

  /// Temporary
  variants::ViewId_t                 viewId_t;

  InterruptHandle_t                  interruptHandle_t;
};


} // namespace bsp



#endif // FPGA_ZCU102_H_
