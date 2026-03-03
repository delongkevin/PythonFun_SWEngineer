//--------------------------------------------------------------------------
/// @file DataProviderTHA.h
/// @brief Contains
///
/// DataProvider is an interface between FPGA module and the shared memory.
/// This file contains all the implementation required to access input and
/// output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Afshan Shaikh (afshan.shaikh@magna.com)
//  --------------------------------------------------------------------------
#ifndef DATA_PROVIDER_THA_H_
#define DATA_PROVIDER_THA_H_

#include "THA/IDataProviderTHA.h"
#include <cfg/IDataProvider.h>
#include <bsp/io/tiovx/TIOVXConsumer.h>
#include "ME_CalibSVS.h"

namespace tha
{

class DataProviderTHA: public IDataProviderTHA
{

public:

  explicit DataProviderTHA(container::IDataProvider &b_DataProvider_ro);
  virtual ~DataProviderTHA();
  //Get calib data
  virtual void getCalibData() ME_OVERRIDE;
  
  // Get HMI signals
  virtual void getSVSHMIdata() ME_OVERRIDE;

  // Get THA SM VC output
  virtual void getTHAsmVCdata() ME_OVERRIDE;

  // Get Vehicle CAN signals
  virtual void getVCANdata() ME_OVERRIDE;

  // Get Kinematic data
  virtual void getKMdata() ME_OVERRIDE;
  
  // Get m_THADetEnable value
  virtual bool_t getTHADetEnableFlag() ME_OVERRIDE;

  // Get m_SCEnable value
  virtual bool_t isTHAFeatureAllowedToRun() ME_OVERRIDE;

  /*
  * Get THA input data
  */
  virtual const JobTHAInput_t getTHAInput() ME_OVERRIDE;
  virtual void c_getInputcolorImage_pu8() ME_OVERRIDE;

  // Get algo view buffer
  virtual void get_grayFisheye_Image() ME_OVERRIDE;
  virtual bsp::TIOVXHost& getTIOVX_ro() ME_OVERRIDE;
  virtual container::OVL3DData* getOVL3DData_po() ME_OVERRIDE;
  
  /*
  * Set THA output data from algo to dataprovider
  */
  virtual void putTHADetOutput( JobTHAAlgoDetOutput_t i_detectionOutput ) ME_OVERRIDE;
  virtual void putTHADetDebugOutput( JobTHAAlgoDetDebug_t i_detectionDebugOutput ) ME_OVERRIDE;
  /*
  * Get Config
  */
  virtual const StateProcessConfig getStateProcessConfig() ME_OVERRIDE;
  virtual const TrailerTrackCfg getTrailerTrackCfg() ME_OVERRIDE;

  virtual void getP_MECL( float32_t i_P[3][4] ) ME_OVERRIDE;
  virtual Point2f pixel_warp( Point2f& pt ) ME_OVERRIDE;
  virtual Point2f pixel_unwarp( const Point2f* pPtInput ) ME_OVERRIDE;
  virtual float32_t getDeltaX() ME_OVERRIDE;
  virtual float32_t getDeltaY() ME_OVERRIDE;
  virtual Point2f unwarped_distance( Point2f i_unwarp_pts ) ME_OVERRIDE;
  virtual Point2f ProjectTo2D( Point3f i_3d_pts, const float32_t i_P[3][4], bool warp = false ) ME_OVERRIDE;
  virtual Point2f ProjectTo2D( Point3f i_3d_pts, bool warp = false ) ME_OVERRIDE;
  virtual Point3f BackProjectTo3D( const Point2f& pt, bool unwarp ) ME_OVERRIDE;
  void TransformFlipPntInp( Point2i& b_UsrSelCplrPnt_rs32, uint16_t& i_HMICplrX_ru16, uint16_t& i_HMICplrY_ru16 );
  void PointWorld2ImagePixel( Point3f i_World3D, Point2i& o_Pixel2D );
  virtual void setTHARuntime(uint32_t u_Runtime_u32) ME_OVERRIDE;
  virtual void setTHAThreadRuntime(uint32_t u_Runtime_u32) ME_OVERRIDE;
  virtual PerformanceStatsEnable_t get_PerformanceStatsEnable(void) ME_OVERRIDE;

private:
  uint32_t v_THAFrameNum_u32;
  container::IDataProvider &dataProvider_ro;
  bsp::TIOVXConsumer tiovxConsumer;
  bool_t m_THADetEnable;
  JobTHAInput_t m_THAInput;
  JobTHAAlgoDetOutput_t m_THADetOutput;
  JobTHAAlgoDetDebug_t m_JobTHADetDebugOutput;

  StateProcessConfig m_THAStateConfig;
  TrailerTrackCfg m_TrailerTrackConfig;
  do_CameraParam m_aCameraInfo;

#if 0
  unsigned long long m_handleKMImpl;
  unsigned long long m_LastTrailerFrameNum;
  int m_StartFrameNum;
  const CouplerConfig m_CouplerFinderConfig;
#endif

};

}//namesoace THA

#endif // DATA_PROVIDER_THA_H_

