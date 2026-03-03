//--------------------------------------------------------------------------
/// @file OcData.h
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
/// @author Muzammil Rasool (muzammil.rasool@magna.com)
/// @author Nikhil Parla (nikhil.parlapalli@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef OCDATA_H_
#define OCDATA_H_

#include "mecl/core/MeclTypes.h"
#include <osal/threading/Mutex.h>
#include "container/DataContainer.h"
#include "ME_CalibSVS.h"
// #include "AlgosDebugData.h"

#define MAX_VALID_FEATURES  (200.0) //used for sending progress to HMI
// PRQA S 2100 EOF // public members used here by design. All structs here should be considered POD
namespace container
{

//  enum OCAlgoStateE_t /* is evaluated first by MCU */
//  {
//    e_OcStateUninit = 0,
//    e_OcStateInitOk,
//    e_OcStateError,
//    e_OcStateFeatureCollection,          /* state after starting Algo */
//    e_OcStateFeatureCollectionCompleted, /* state after min. 100 features and min. 900 frames are collected */
//    e_OcStateCalibration,
//    e_OcStateCalibrationCompleted,       /* state after 1 cam is calibrated + e_OC_NoError => values in ME_Hydra2defs_S_OCStatus_t are valid */
//    e_OcStateTerminated,
//    e_OcStatePaused,
//    e_OcStateUnknown,
//    e_OcStateEnd
//  };

  enum OcDriverPosition_e
  {
    e_DriverPositionLHD     = 0,
    e_DriverPositionRHD     = 1,
    e_DriverPositionDefault = e_DriverPositionLHD
  };

//  enum AlgoCommand_e
//	{
//		e_Start = 0,
//		e_Stop,
//		e_Pause,
//		e_Status,
//		e_Sync,//missing
//		e_GetResult,//missing
//		e_Resume,
//		e_Set,//missing
//		e_Debug,
//		e_Unknown                   // this must be the last entry ('VALID_COMMAND' < e_Unknown)
//	};

  struct  Oc_hmi_data_s
  {
	variants::OCAlgoStateE_t ocAlgoState_e[variants::e_CameraCount];
    uint16_t ocProgress_u16[variants::e_CameraCount];
  };
  struct OcDataToMcu_s
  {
    OcDataToMcu_s()
    : deltaPitch_f32(0.0)
    , deltaYaw_f32(0.0)
    , deltaRoll_f32(0.0)
    , validFeaturesCount_u32(0U)
    , ignoredFeaturesCount_u32(0U)
    , invalidFeaturesCount_u32(0U)
    , ocAlgoState_e(variants::e_OcStateUninit)
    , ocErrorCode_e(variants::e_OcErrCodeNoError)
    {}

    float32_t deltaPitch_f32;
    float32_t deltaYaw_f32;
    float32_t deltaRoll_f32;
    uint32_t  validFeaturesCount_u32;
    uint32_t  ignoredFeaturesCount_u32;
    uint32_t  invalidFeaturesCount_u32;
    variants::OCAlgoStateE_t ocAlgoState_e;
    variants::OCErrorCodeE_t ocErrorCode_e;

    OcDataToMcu_s & operator=(const OcDataToMcu_s &i_Data_rs)
    {
      if (this != &i_Data_rs)
      {
        deltaPitch_f32 = i_Data_rs.deltaPitch_f32;
        deltaYaw_f32   = i_Data_rs.deltaYaw_f32;
        deltaRoll_f32 = i_Data_rs.deltaRoll_f32;
        validFeaturesCount_u32 = i_Data_rs.validFeaturesCount_u32;
        ignoredFeaturesCount_u32 = i_Data_rs.ignoredFeaturesCount_u32;
        invalidFeaturesCount_u32 = i_Data_rs.invalidFeaturesCount_u32;
        ocAlgoState_e = i_Data_rs.ocAlgoState_e;
        ocErrorCode_e = i_Data_rs.ocErrorCode_e;
      }
      return *this;
    }

  // private:
      OcDataToMcu_s(const OcDataToMcu_s& i_data_rs);

  };

  typedef struct RequestOCCalibCmd_s // PRQA S 2400 // global scope, yes
  {
      uint32_t                        camera_u32;
      ME_Hydra3defs_E_AlgoCommand_t   cmd_t;
      variants::CalibrationTypeE_t    calibrationType_t;
      uint32_t                        frameId_u32;
  } RequestOCCalibCmd_t;

  enum OcAlgoView640x400Buffer_e
  {
    e_OcAlgoViewBuffer0 = 0,
    e_OcAlgoViewBuffer1
  };

  // --- CameraId
  enum CameraId_e
  {
      e_NoCamera = 0,
      e_Front,
      e_Left,
      e_Rear,
      e_Right,
      e_Fifth,
      e_NumCams = e_Fifth
  };

  enum VariantId_e
  {
      e_Variant1 = 1,
      e_Variant2,
      e_Variant3,
      e_Variant4,
      e_Variant5,
      e_Variant6,
      e_Variant7,
      e_Variant8,
      e_Variant9,
      e_Variant10,
      e_Variant11,
      e_Variant12,
      e_Variant13,
      e_Variant14,
      e_Variant15
  };

  struct OcData_s
    {
      OcData_s()
          : deltaPitch_f32( 0.0 )
          , deltaYaw_f32( 0.0 )
          , deltaRoll_f32( 0.0 )
          , validFeaturesCount_u32( 0U )
          , ignoredFeaturesCount_u32( 0U )
          , invalidFeaturesCount_u32( 0U )
          , ocAlgoState_e( variants::e_OcStateUninit )
          , ocErrorCode_e( variants::e_OcErrCodeNoError )
          , lastRequestedAt_u32( 0U )
          , updatedAt_u32( 0U )
          , mcuCameraId_u8( 0U )
          , algoViewBuffer_e( e_OcAlgoViewBuffer0 )
          , isOcActive_b( false )
      	  , ProcessedFrameCount( 0U )
      {}

      OcData_s& operator=( const OcData_s& i_Data_rs )
      {
          if( this != &i_Data_rs )
          {
              //copy constructor of ocDataToMcu_s
              deltaPitch_f32 = i_Data_rs.deltaPitch_f32;
              deltaYaw_f32 = i_Data_rs.deltaYaw_f32;
              deltaRoll_f32 = i_Data_rs.deltaRoll_f32;
              validFeaturesCount_u32 = i_Data_rs.validFeaturesCount_u32;
              ignoredFeaturesCount_u32 = i_Data_rs.ignoredFeaturesCount_u32;
              invalidFeaturesCount_u32 = i_Data_rs.invalidFeaturesCount_u32;
              ocAlgoState_e = i_Data_rs.ocAlgoState_e;
              ocErrorCode_e = i_Data_rs.ocErrorCode_e;
              //ocDataToMcu_s = i_Data_rs.ocDataToMcu_s;
              lastRequestedAt_u32 = i_Data_rs.lastRequestedAt_u32;
              updatedAt_u32 = i_Data_rs.updatedAt_u32;
              mcuCameraId_u8 = i_Data_rs.mcuCameraId_u8;
              algoViewBuffer_e = i_Data_rs.algoViewBuffer_e;
              isOcActive_b = i_Data_rs.isOcActive_b;
              ProcessedFrameCount =  i_Data_rs.ProcessedFrameCount;
              //debugLayer_s = i_Data_rs.debugLayer_s;
          }

          return *this;
      }

      float32_t deltaPitch_f32;
      float32_t deltaYaw_f32;
      float32_t deltaRoll_f32;
      uint32_t  validFeaturesCount_u32;
      uint32_t  ignoredFeaturesCount_u32;
      uint32_t  invalidFeaturesCount_u32;
      variants::OCAlgoStateE_t    ocAlgoState_e;
      variants::OCErrorCodeE_t ocErrorCode_e;

  //    OcDataToMcu_s ocDataToMcu_s;
      uint32_t lastRequestedAt_u32;
      uint32_t updatedAt_u32;
      uint8_t  mcuCameraId_u8;
      OcAlgoView640x400Buffer_e algoViewBuffer_e;
      bool_t isOcActive_b;
      //AlgosDebugData_s debugLayer_s;
      uint32_t ProcessedFrameCount;
  // private: // TODO :does this have to be private?
//      OcData_s( const OcData_s& i_data_rs );

  };


  class OcMData : public DataContainer
  {
    public:
      OcMData();
      virtual ~OcMData();

      static const uint32_t c_ImgMaxWidth_u32  = 960U;
      static const uint32_t c_ImgMaxHeight_u32 = 640U; 
      static const uint32_t c_ImgLength_u32    = c_ImgMaxWidth_u32 * c_ImgMaxHeight_u32;

    private:
      osal::Mutex mutex_o;
      uint8_t m_MemoryPool_ua8[4][c_ImgLength_u32];
      OcData_s ocshmdata;
      Oc_hmi_data_s oc_hmi_info;
      uint32_t m_OC_rt_data;
      uint32_t m_OCThread_rt_data;


    public:
      static uint32_t getImageMaxWidth_u32(void)
      { return c_ImgMaxWidth_u32; }
      static uint32_t getImageMaxHeight_u32(void)
      { return c_ImgMaxHeight_u32; }
      uint8_t* getImageBuffer_pu8(const variants::Camera_t i_Camera_e)
      { return &m_MemoryPool_ua8[i_Camera_e][0]; }
      int16_t getFeatureProgress();
	  Oc_hmi_data_s* get_oc_hmi_info();  // for cogent OC screen
	  void set_oc_hmi_info(Oc_hmi_data_s* i_oc_hmi_data_p);  // for cogent OC screen
	  OcData_s *get_ocm_data();
      void set_ocm_data (OcData_s data);
    uint32_t getOCRuntime(void);
    void setOCRuntime(uint32_t u_Runtime_u32);
    uint32_t getOCThreadRuntime(void);
    void setOCThreadRuntime(uint32_t u_Runtime_u32);
  };

}     // namespace container

#endif /* OCDATA_H_ */
