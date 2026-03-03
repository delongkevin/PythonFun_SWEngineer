//--------------------------------------------------------------------------
/// @file IDataProviderTHA.h
/// @brief Contains interface for THA Dataprovider
///
/// IDataProvider is an interface used by the algorithm to define what data
/// is actually needed. Implementation is delegated to a derived data provider
/// that is component/mTHAule specific and belongs to the framework implementation.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Afshan Shaikh (afshan.shaikh@magna.com)
//  --------------------------------------------------------------------------
#ifndef I_DATA_PROVIDER_THA_H_
#define I_DATA_PROVIDER_THA_H_

#include <cfg/DataProvider.h>
#include "meal/camera/core/inc/Camera.h"
#include "algo/common/THADefs.h"
#include "algo/common/THAConfig.h"
#include "algo/inc/JobTHADetOutput.h"
#include "algo/inc/JobTHAInput.h"

#define ENABLE_DEBUG_THA 0
#define ENABLE_VIEW_WORKAROUND 1
#define DUMP_THA_ALGO_VIEW 0
#define PROFILE_THA 0
#define ENABLE_OFFLINE_TEST_THA 0

namespace tha
{
class IDataProviderTHA
{
public:
  explicit IDataProviderTHA()
  {
  }

  virtual ~IDataProviderTHA()
  {
  }

  // Get HMI signals
  virtual void getSVSHMIdata() = 0;
  
  // Get THA SM VC output
  virtual void getTHAsmVCdata() = 0;

  // Get Vehicle CAN signals
  virtual void getVCANdata() = 0;

  // Get Kinematic data
  virtual void getKMdata() = 0;

  /*
  * Get Config
  */
  virtual const StateProcessConfig getStateProcessConfig() = 0;
  virtual const TrailerTrackCfg getTrailerTrackCfg() = 0;
  
  // Get algo view buffer
  virtual void c_getInputcolorImage_pu8() = 0;
  virtual void get_grayFisheye_Image() = 0;
  virtual bsp::TIOVXHost& getTIOVX_ro() = 0;
  virtual container::OVL3DData* getOVL3DData_po() = 0;
  
  // Get m_THADetEnable value
  virtual bool_t getTHADetEnableFlag() = 0;

  // Get m_SCEnable value
  virtual bool_t isTHAFeatureAllowedToRun() = 0;

  //Get calib data
  virtual void getCalibData() = 0;

  /*
  * Get detection input
  */
  virtual const JobTHAInput_t getTHAInput() = 0;
  /*
  * Put detection output
  */
  virtual void putTHADetOutput( JobTHAAlgoDetOutput_t i_detectionOutput ) = 0;
  virtual void putTHADetDebugOutput( JobTHAAlgoDetDebug_t i_detectionDebugOutput ) = 0;
  
  /*
  * Get camera info & functions
  */
  virtual float32_t getDeltaX() = 0;
  virtual float32_t getDeltaY() = 0;
  virtual void getP_MECL( float32_t i_P[3][4] ) = 0;
  virtual Point2f pixel_warp( Point2f& pt ) = 0;
  virtual Point2f pixel_unwarp( const Point2f* pPtInput ) = 0;
  virtual Point2f unwarped_distance( Point2f i_unwarp_pts ) = 0;
  virtual Point2f ProjectTo2D( Point3f i_3d_pts, const float32_t i_P[3][4], bool warp = false ) = 0;
  virtual Point2f ProjectTo2D( Point3f i_3d_pts, bool warp = false ) = 0;
  virtual Point3f BackProjectTo3D( const Point2f& pt, bool unwarp ) = 0;
  void TransformFlipPntInp( Point2i& b_UsrSelCplrPnt_rs32, uint16_t& i_HMICplrX_ru16, uint16_t& i_HMICplrY_ru16 );
  virtual void setTHARuntime(uint32_t u_Runtime_u32) = 0;
  virtual void setTHAThreadRuntime(uint32_t u_Runtime_u32) = 0;
  virtual PerformanceStatsEnable_t get_PerformanceStatsEnable(void) = 0;
};
} // namespace tha

#endif // I_DATA_PROVIDER_THA_H_
