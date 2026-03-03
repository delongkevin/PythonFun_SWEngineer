//--------------------------------------------------------------------------
/// @file DataProviderEol.h
/// @brief Contains
///
/// DataProvider is an interface between EOL module and the shared memory.
/// It implements the pure virtual interface definition to adapt the
/// module/component to the framework by specifying where the data comes form
/// or goes to. This means, this file contains all the interfaces required
/// to access input and output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Afshan Shaikh (afshan.shaikh@magna.com)
///
//  --------------------------------------------------------------------------
#ifndef DATAPROVIDEREOL_H_
#define DATAPROVIDEREOL_H_

#include <cfg/IDataProvider.h>
#include "EOL/IDataProviderEol.h"
#include <bsp/io/tiovx/TIOVXConsumer.h>

namespace eol
{
  class DataProviderEol : public IDataProviderEol
  {
  public:
    explicit DataProviderEol(container::IDataProvider& b_DataInProvider_ro);
    virtual ~DataProviderEol();

    /* Get CALSM data */
    virtual void getCalSMData();
    virtual ME_Hydra3defs_E_CameraID_t getCameraId_MEHydra3();
    virtual uint8_t getAlgoCommand_u8();
    virtual uint8_t getAlgoType_u8();

    /* Put CALSM data */
    virtual void putEolOutput(aParaMgr_S_Calibration_t& i_CaliVCalib,
        ME_Hydra3defs_E_EOLAlgoState_t i_AlgoState, ME_Hydra3defs_E_CameraID_t m_CurrCamID);

    /* Get Image bufffer from TIOVX */
    virtual EolInitData_s getEolData();

    /* Get Camera parameters (Intrinsics and Extrinsic) */
    virtual void getCameraParameters_v();
    virtual variants::Camera_t getCameraId_variants();

    void setEOLRuntime(uint32_t u_Runtime_u32);
    void setEOLThreadRuntime(uint32_t u_Runtime_u32);
    virtual PerformanceStatsEnable_t get_PerformanceStatsEnable(void) ME_OVERRIDE;

#if 0
    virtual void clearEolDataToMcu_v();
    //virtual void configureFpgaForInputImage_v(bool_t i_EnableAlgoView_b, CameraId_t i_McuCamId_e);
    //virtual const uint8_t* getInputImage_pu8() const;
    //virtual void*       getVideoInputBuffer_pv(variants::Camera_t i_CameraId_t, bsp::VideoInputBufferDesc2_t& ro_desc_t) ME_OVERRIDE;

    virtual void putEolOutput(aParaMgr_S_Calibration_t& i_CaliVCalib,
        ME_Hydra3defs_E_EOLAlgoState_t i_AlgoState, ME_Hydra3defs_E_CameraID_t m_CurrCamID);

   // virtual void setAlgoState_v( const EolAlgoState_t i_EolAlgoState_e);
    virtual void setLastUpdate_v();
    virtual void setEolActive(bool_t i_EolActive_b);
    virtual void setLastRequestedAt_v( uint32_t i_LastRequestedAt_u32);
   // virtual void setEolErrorCode_v( const EolErrorCode_t i_EolErrorCode_e );
    virtual void setDeltaPitch_v( float32_t i_DeltaPitch_f32 );
    virtual void setDeltaRoll_v( float32_t i_DeltaRoll_f32 );
    virtual void setDeltaYaw_v( float32_t i_DeltaYaw_f32 );
    virtual void setDeltaX_v( float32_t i_DeltaX_f32 );
    virtual void setDeltaY_v( float32_t i_DeltaY_f32 );
    virtual void setDeltaZ_v( float32_t i_DeltaZ_f32 );
    virtual void setEolTargetData_v( const EolCalib &i_EolCalib_ro);
    virtual void setMcuCameraId_v( uint8_t i_McuCameraId_u8);
    virtual void getCameraParameters_v();
   // virtual void setAlgoViewBuffer_v( const EolAlgoView1280x800Buffer_t i_AlgoViewBuffer_e);

    virtual void getCalSMData();
    virtual EolInitData_s getEolData();
    virtual uint32_t getLastRequestedAt_u32() const;
    virtual float32_t getDeltaPitch_f32();
    virtual float32_t getDeltaRoll_f32();
    virtual float32_t getDeltaYaw_f32();
    virtual float32_t getDeltaX_f32();
    virtual float32_t getDeltaY_f32();
    virtual float32_t getDeltaZ_f32();
    virtual uint8_t getAlgoType_u8();
    virtual uint32_t getRequestedAt_u32() const;
    //virtual ResponseState_t getResponseState_e();
    virtual uint8_t getAlgoCommand_u8();
    virtual uint8_t getCameraId_u8();
    virtual variants::Camera_t getCameraId_variants();
    virtual ME_Hydra3defs_E_CameraID_t getCameraId_MEHydra3();
    virtual float32_t getLTargetSeperation_f32();
    //virtual AlgoDebugView_t getAlgoDebugView_e();
    virtual uint32_t getFrameId_u32();
   // virtual AlgoDebugTypeEol_t getAlgoDebugTypeEol_e();
    virtual uint8_t getEolCameraMask_u8();
    virtual uint16_t getTargetId_u16();
    virtual uint16_t getTargetDistance_u16() const;
    //virtual void DataProviderEol::getCameraData(uint8_t cameraID, W2Image::SetupExtrinsicCfg_s& i_ExtrinsicCfg_rs, W2Image::SetupIntrinsicCfg_s& i_IntrinsicCfg_rs);
    //virtual VariantId_t getVariantId_e();
    //virtual AlgosDebugData_t& accessDebugLayer_rt();
    //virtual uint8_t getCameraConnectorIdFromMcuId_u8(const CameraId_t i_CameraId_e);
    //virtual prjcontainer::AdapterCameraReal& accessAdapterCameraReal_ro();
    //virtual EolErrorCode_t getEolErrorCode_e();
    //virtual shmdata::EolConfig_s getEolConfigData_s();
#endif 
  private:
    //prjcontainer::AdapterCameraReal  adapterCameraReal_o;
   // EolAlgoView1280x800Buffer_t      algoViewBufferToRead_e;

    container::IDataProvider &dataProvider_ro;

    bsp::TIOVXConsumer tiovxConsumer;

    /* Get CALSM data and OnRun Algo  */
    eol::E_CameraId_t        camID_e;
    eol::aParaMgr_E_CalibrationType_t calibType_e;
    ME_Hydra3defs_E_AlgoCommand_t algoCommand_e;
    float32_t lTargetSeperation_f32;

    /* Get Image bufffer from TIOVX and Start */
    sint8_t  targetLimitF_as8[4];
    sint8_t  targetInit_as8[4];
    sint8_t  targetLimitR_as8[4];

    mecl::model::Camera<float64_t> camera64_o;

    /* Get Camera parameters (Intrinsics and Extrinsic) */
    mecl::model::Pinhole<float64_t> pinhole64_o;
    mecl::model::Sensor<float64_t> sensor64_o;
    mecl::model::LensRadial<float64_t> lensRadial64_o;

    /* Put CALSM data and end_v*/
    aParaMgr_S_Calibration_t design_ang;
    ME_Hydra3defs_S_EOLStatus_t m_EOLStatus;

  };

} // namespace eol

#endif // DATAPROVIDEREOL_H_

