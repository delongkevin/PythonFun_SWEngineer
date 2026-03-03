/// --------------------------------------------------------------------------
/// @file DLDStateMachine.h
/// @brief Contains state machine for DLD camera selection
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Sharad Benakatti (sharad.benakatti@magna.com)
/// --------------------------------------------------------------------------

#ifndef DLD_STATE_MACHINE_H
#define DLD_STATE_MACHINE_H

#include "meal/camera/core/inc/Camera.h"
#include "../common/DLDDef.h"

namespace dld {

class DLDStateMachine
{
private:
  bool_t          m_participants[DLD_Camera_ID::DLD_NUM_CAMS];
  DLD_Camera_ID m_currentCamId;
  uint32_t      m_maxCyclesPerCamera;
  uint32_t      m_cyclesInCurCam;

  bool_t isCameraParticipating(DLD_Camera_ID) const;
  DLD_Camera_ID getNextCameraId() const;

public:
  explicit DLDStateMachine(uint32_t maxCyclesPerCamera);
  virtual ~DLDStateMachine();

  DLD_Camera_ID getCameraID();
  uint8_t   getCyclesInCurCam() const{ return static_cast<uint8_t>(m_cyclesInCurCam); }
  void      updateParticipation(DLD_Camera_ID camId, bool_t isParticipating);
};

} // namespace dld

#endif // DLD_STATE_MACHINE_H