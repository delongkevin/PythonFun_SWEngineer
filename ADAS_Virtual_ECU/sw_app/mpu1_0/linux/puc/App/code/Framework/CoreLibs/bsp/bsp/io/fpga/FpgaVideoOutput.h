//--------------------------------------------------------------------------
/// @file FpgaVideoOutput.h
/// @brief Implementation of FPGA Video Output interface
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
//  --------------------------------------------------------------------------

#ifndef FPGA_VIDEO_OUTPUT_H_
#define FPGA_VIDEO_OUTPUT_H_

#include <platform/PlatformAPI.h>

#include <variants/Enums.h>

namespace bsp
{


class FpgaVideoOutput
{
public:

  FpgaVideoOutput();

  ~FpgaVideoOutput();

  bool_t    initVideoOutput_b();

  void      powerEnable_v() const;

  void      powerDisable_v() const;

private:

  /// -------------------------------------------------------------------------------

  void*             plBaseAddress_pv;

};


} // namespace bsp



#endif // FPGA_VIDEO_INPUT_H_
