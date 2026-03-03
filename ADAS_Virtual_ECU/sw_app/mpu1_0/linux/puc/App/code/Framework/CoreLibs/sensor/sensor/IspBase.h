//--------------------------------------------------------------------------
/// @file CameraBase.h
/// @brief Defines a general interface implementation for cameras
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

#ifndef ISP_BASE_H_
#define ISP_BASE_H_

#include <platform/PlatformAPI.h>

#include "cfg/CamTypes.h"

namespace sensor
{
  
class IspBase 
{
public: 

  IspBase();

  ~IspBase();

public: 

  // --------------------------------------------------------------------------
  /// set ISPCfgData_t per camera
  ///
  /// @return bool_t
  // --------------------------------------------------------------------------
  virtual bool_t         setISPConfig_b(const ISPCfgData_t& i_ISPCfgData_rt) = 0;

  // --------------------------------------------------------------------------
  /// set ISPCfgData_t per camera
  ///
  /// @return bool_t
  // --------------------------------------------------------------------------
  virtual bool_t         setISPData_b(const ISPData_t& i_ISPData_rt) = 0;

protected:

  ISPCfgData_t           ispConfigData_t;

  ISPData_t              ispData_t;

};

} // namespace sensor

#endif // ISP_BASE_H_