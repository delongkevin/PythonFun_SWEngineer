//--------------------------------------------------------------------------
/// @file CameraZyrichLite.h
/// @brief Implementation of QNX camera interface
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
///
//  --------------------------------------------------------------------------

#ifndef CAMERA_ZYRICH_LITE_H_
#define CAMERA_ZYRICH_LITE_H_

#include <platform/PlatformAPI.h>

#include "sensor/CameraBase.h"

#include "DeserializerCXD4960ER.h"
#include "SerializerCXD4963ER.h"
#include "ImagerAS0149AT.h"
#include "SpiFlashW25Q40.h"

#include <variants/Enums.h>

#ifdef ME_PLATFORM_QNX

#include <screen/screen.h>

namespace sensor
{

  class CameraZyrichLite : public CameraBase
  {

  public:

    CameraZyrichLite();

    virtual ~CameraZyrichLite();

    bool_t                                init_b(variants::Camera_t i_CameraId_t);

    bool_t                                configDeserializer_b();

    bool_t                                configCamSerializer_b();

    bool_t                                configCamImager_b();

    // open for usage
    virtual bool_t                        open_b() ME_OVERRIDE;

    virtual bool_t                        close_b() ME_OVERRIDE;

    virtual bool_t                        run_b() ME_OVERRIDE;

    virtual bool_t                        stop_b() ME_OVERRIDE;

  public:

    virtual bool_t                        getEepromData_b(CameraEepromData_t& o_EepromData_rt) ME_OVERRIDE;

    virtual variants::CameraPowerMode_t   readCameraPowerMode_t();

  public:

    // --------------------------------------------------------
    // Setter
    // --------------------------------------------------------

    virtual bool_t                        setPowerMode_b(variants::CameraPowerMode_t i_CameraPowerMode_e) ME_OVERRIDE;

    virtual bool_t                        setVideoMode_b(VideoMode_e i_VideoMode_e) ME_OVERRIDE;

    virtual bool_t                        setTestPatternMode_b(variants::CamTestPattern_t i_TestPatternMode_e) ME_OVERRIDE;

    void                                  setCameraState_v(CameraState_e i_CameraState_e);

    // --------------------------------------------------------
    // Getter
    // --------------------------------------------------------

  private:

    bool_t                                initialized_b;

    CameraEepromData_t                    cameraEepromData_t;

    uint32_t                              fpgaCameraId_u32;

    void*                                 plBaseAddress_pv;

  };

}

#endif // ME_PLATFORM_QNX


#endif // CAMERA_ZYRICH_LITE_H_
