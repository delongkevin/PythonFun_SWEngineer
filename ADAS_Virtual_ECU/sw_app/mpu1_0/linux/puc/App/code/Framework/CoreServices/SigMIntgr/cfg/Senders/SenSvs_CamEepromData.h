//--------------------------------------------------------------------------
/// @file SenSvs_CamEepromData.h
/// @brief Contains
///
///
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
//  --------------------------------------------------------------------------

#ifndef SIGM_SENDERS_SVS_CAM_EEPROM_DATA_H_
#define SIGM_SENDERS_SVS_CAM_EEPROM_DATA_H_

#include "BaseSender.h"

namespace sigm
{

class SenSvs_CamEepromData : public BaseSender
{
public:
	SenSvs_CamEepromData();
  virtual ~SenSvs_CamEepromData();

  virtual bool_t handleSpecificSender_b();


private:
  bool_t handle_Svs_CamEepromDataSender_b();
};

} // namespace sigm
#endif // SIGM_SENDERS_SVS_CAM_EEPROM_DATA_H_
