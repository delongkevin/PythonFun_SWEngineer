//--------------------------------------------------------------------------
/// @file VideoStreamProvider.h
/// @brief Contains

/// DataProvider is an interface between the application module and the shared memory.
/// It implements the pure virtual interface definition to adapt the
/// module/component to the framework by specifying where the data comes from
/// or goes to. This means, this file contains all the interfaces required
/// to access input and output data.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Detlef Hafer (detlef.hafer.extern@magna.com)
///
//  --------------------------------------------------------------------------
/// \addtogroup EolIntgr
/// @{

#ifndef VIDEOSTREAMPROVIDER_H_
#define VIDEOSTREAMPROVIDER_H_

#include <platform/PlatformAPI.h>

#include <bsp/graphics/Stream.h>

#include <variants/Enums.h>

namespace container
{




class VideoStreamConsumer
{

public:

  VideoStreamConsumer();

  virtual ~VideoStreamConsumer();

  bool_t                    init_b(variants::Camera_t i_CameraId_t, ScreenContext_t i_ScreenContext_t);

  static bool_t                    deInit_b();

  bool_t                    aquireBuffer_b(bsp::ImageBufferData_t* b_ImageData_pt, bool_t i_Blocking_b);

public:

  static variants::Camera_t mapStreamToCameraId_t(sint32_t i_StreamId_s32);

  static sint32_t           mapCameraToStreamId_s32(variants::Camera_t i_CameraId_t);

private:

  static void*              waitForProducer_pv(void* arg);

protected:

  sint32_t                  streamId_s32;

  ScreenContext_t           screenContext_t;

  bsp::Stream               stream_o;

  bool_t                    producerStreamAvailable_b;
};

};

#endif // VIDEOSTREAMPROVIDER_H_

/// @}

