//--------------------------------------------------------------------------
/// @file JobOC.h
/// @brief Contains the definition of OC = Online Calibration
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Muzammil Rasool (muzammil.rasool@magna.com)
/// @author Nikhil Parla (nikhil.parlapalli@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef JOBOC_H_
#define JOBOC_H_

#include <osal/threading/Thread.h>
#include "mecl/core/MeclTypes.h"
#include "container/JobBase.h"
#include "IDataProviderOC.h"
#include "../cfg/DataProvider/DataProviderOC.h"


// #include "prjcontainer/AdapterCameraReal.h"
// #include "shmdata/OcData.h"
// #include "shmdata/McuData.h"
#include "tscApi.h"
// #include "logging/LogProvider.h"



// This commented code is uncommented and used when debugging with synthetic images.
// PRQA S 1051 2
// #define OC_HARDCODED_INPUT_IMAGE
//#define OC_GRAB_ALGO_VIEW_IMAGES


#define SIMULATED_IMG_NUM (3000)

namespace oc
{
// TODO: check if OC_HARDCODED_INPUT_IMAGE can be replaced with OC_SIMINP_DEBUG
#ifdef OC_HARDCODED_INPUT_IMAGE
extern const uint8_t OcSyntheticImageFront_au8 [IMAGE_WIDTH*IMAGE_HEIGHT];
#endif

class OCThreadRunnable: public osal::IRunnable
{

public:
  enum State_e
  {
    e_UnInit = 0,
    e_OcInit,
    e_OcReadyToExecute,
    e_DoNothing
  };
  
  explicit OCThreadRunnable(IDataProviderOC &b_DataProvider_ro);
  virtual ~OCThreadRunnable();

  virtual void init_v() ME_OVERRIDE;
  virtual bool_t run_b() ME_OVERRIDE;
  virtual void cleanup_v() ME_OVERRIDE;

private:
  virtual bool_t hasNext_b() const;
  virtual void start_v();
  virtual void execute_v();
  virtual void end_v();
  virtual void dump_v();

  bool Logging_Enabled;
  // std::stringstream m_AlgoStateHeader;
  // std::stringstream m_AlgoStateStream;
  // std::stringstream m_ResultHeader;
  // std::stringstream m_ResultStream;

  //container::OcDriverPosition_e getDriverPosition_e( void ) const;
  const uint8_t* get640x400AlgoView_pu8( container::CameraId_e CamID ) const;
  //void configureFpgaForAlgoView_v( bool_t i_EnableAlgoView_b );
  static tscApi::enuCameraID getOcAlgoCamId_e( container::CameraId_e i_McuCamId_e );
  //static Camera_ID getWindowsCamID( container::CameraId_e OCCamID );
  void setOcKinematicModelConfiguration_v( void );
  void setOcCamModelConfiguration_v( void );
  void setOcFeatureCollectionConfiguration_v( void );

  // need to refactor for Windows
  void setCamParametersOneCam_v( container::CameraId_e i_McuCamId_e );

  // Dump image pointer to bmp
  // int vid_save_bmp( char* input_filename, char* img, int w, int h );

  // Dump Calibration results
  void DumpCalibrationResults( tscApi::enuCameraID v_OcAlgoCamId_e, container::OcData_s& v_OcData_rs );
  void setmcuCamIdToOcAlgo_e (variants :: Camera_t i_request_camera);
  void vid_save_txt(const char *input_filename, char *img, int h, int w);
  int vid_save_bmp(char *input_filename, char *img, int h, int w);

  // ignored for now
  //void createDebugView_v( const uint8_t* i_AlgoView_pu8, const uint8_t i_OcAlgoCamId_u8 );
  //void deactivateDebugView_v() const;
  
  IDataProviderOC &dataProvider_ro;

  State_e state_e;
  uint32_t ocFrameCounter_u32;
  bool_t isAlgorithmStarted_b;
        bool_t isAlgorithmFinished_b;
  bool_t isNewCommand_b;
  ME_Hydra3defs_E_AlgoCommand_t algoCommand_e;
  const mecl::model::Pinhole<float32_t>::Extrinsic_s* c_OcExtrinsics_ps;

  container::OcAlgoView640x400Buffer_e algoViewBufferToRead_e;
  uint32_t algoViewConfiguredCounter_u32;
  uint32_t prevValidFeatureCount_u32;
  uint32_t abortFrameCounter_u32;

  /* prjcontainer::AdapterCameraReal adapterCameraRealFront_o;
    prjcontainer::AdapterCameraReal adapterCameraRealLeft_o;
    prjcontainer::AdapterCameraReal adapterCameraRealRear_o;
    prjcontainer::AdapterCameraReal adapterCameraRealRight_o;*/
  // This may not be a proper analog, we'll see

  do_CameraParam& m_aFrontCameraInfo;
  do_CameraParam& m_aLeftCameraInfo;
  do_CameraParam& m_aRearCameraInfo;
  do_CameraParam& m_aRightCameraInfo;

  container::CameraId_e mcuCamIdToOcAlgo_e;

  tscApi::TSCCtrlInfo tscCtrlInfo_o;
  tscApi::TSCSavedDataInfo_s  tscIntermediateData_as[tscApi::e_TscNumCam];
  tscApi::tscPlatformExtConfigType tscStartConfiguration_as[tscApi::e_TscNumCam];
  tscApi::TSCError_e tscErrorCode_ae[tscApi::e_TscNumCam];
  tscApi::TSCState_e tscAlgoState_ae[tscApi::e_TscNumCam];
  tscApi::CalibrationParams_s tscCalibrationResults_as[tscApi::e_TscNumCam];

  static const uint32_t c_ImageWidth_u32 = IMAGE_WIDTH;
  static const uint32_t c_ImageHeight_u32 = IMAGE_HEIGHT;
  static const uint32_t c_TotalPixels_u32 = c_ImageWidth_u32 * c_ImageHeight_u32;
  static const uint32_t c_MinAbortFrameCntLimit_u32 = 4500U; //2.5 minutes, 30 Hz => 90*30 = 2700     //40 seconds, 30 Hz => 40*30 = 1200
  static const uint32_t c_FrameWindow_u32 = 200U; //In 200 consecutive frames, if 'minValidFeaturesInWindow_u32' valid features are not found, we abort.
  static const uint32_t c_MinValidFeaturesInWindow_u32 = ( c_FrameWindow_u32 / 90U );

  static const uint8_t c_DriverPositionConfigBitMask_u8 = 0x01U;

  ME_Hydra3defs_E_AlgoCommand_t m_prevRequest_cmd;
  ME_Hydra3defs_E_AlgoCommand_t m_request_cmd;
  variants :: Camera_t m_request_camera;
  container::OcData_s initialisation_data;  // write back to shared memory after done
  uint64_t v_startcal_u64, v_timeoutcal_u64;
  variants::CalibrationTypeE_t c_calibrationType_e;
};

class JobOC : public container::JobBase<IDataProviderOC>
{
public:
  explicit JobOC(container::JobDesc_s& b_JobDesc_rs, IDataProviderOC& b_DataProvider_ro);
  virtual ~JobOC();

  // JobBase implementation
  virtual bool_t        onInit_b() ME_OVERRIDE;
  virtual void          onVariantChanged_v(bool_t i_FirstTime_b) ME_OVERRIDE;
  virtual bool_t        onRun_b() ME_OVERRIDE;
  virtual void          onCleanup_v() ME_OVERRIDE;

private:
  osal::Thread        m_OCThread_o;
  OCThreadRunnable    m_OCThreadRunnable_o;
  
};

} //namespace oc

#endif /* JOBOC_H_ */
