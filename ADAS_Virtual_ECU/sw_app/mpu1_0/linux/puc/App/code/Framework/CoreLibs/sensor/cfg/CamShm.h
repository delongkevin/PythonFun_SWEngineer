//--------------------------------------------------------------------------
/// @file CamShm.h
/// @brief Implementation of Shared Memory camera grabber
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

#ifndef CAMSHM_H_
#define CAMSHM_H_

#include "sensor/CameraBase.h"

namespace sensor
{
  class CamShm : public CameraBase
  {
  public:

    CamShm();

    virtual ~CamShm();

    bool_t                 init_b(variants::Camera_t i_CameraId_t, const char_t* i_ShmName_pc);

    // open for usage
    virtual bool_t         open_b() ME_OVERRIDE;

    virtual bool_t         close_b() ME_OVERRIDE;

    virtual bool_t         run_b() ME_OVERRIDE;

    virtual bool_t         stop_b() ME_OVERRIDE;

  public:

    virtual bool_t                     getEepromData_b(CameraEepromData_t& o_EepromData_rt) ME_OVERRIDE;

  public:

    virtual bool_t                     setPowerMode_b(variants::CameraPowerMode_e i_CameraPowerMode_e) ME_OVERRIDE;

    virtual bool_t                     setTestPatternMode_b(variants::CamTestPattern_t i_TestPatternMode_t);

    virtual bool_t                     setVideoMode_b(VideoMode_e i_VideoMode_e) ME_OVERRIDE;

    virtual void                       setCameraState_v(sensor::CameraState_e i_CameraState_e) ME_OVERRIDE;

     // not really necessary in under Windows
    CameraEepromData_t camEepromData_t;
  };

}


#endif
