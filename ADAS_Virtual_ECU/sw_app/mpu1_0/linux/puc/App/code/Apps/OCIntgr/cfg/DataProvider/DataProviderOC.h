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
/// @author Nikhil Parlapalli
///
//  --------------------------------------------------------------------------

#ifndef DATAPROVIDER_OC_H_
#define DATAPROVIDER_OC_H_

#include <sensor/CameraBase.h>
#include "oc/IDataProviderOC.h"
#include <cfg/IDataProvider.h>
#include "tscApi.h"
#include "../../oc/World2ImageTypes.h"
#include "DataVariantProviderOc.h"
#include "VehicleData.h"
#include <../../../code/Framework/CoreLibs/container/cfg/shmdata/CalSmMData.h>
#include <../../../code/Framework/CoreLibs/container/cfg/shmdata/CamMData.h>
#include <bsp/io/tiovx/TIOVXConsumer.h>

#define OFFSET_640x400  (0xFA000)   // Offset of 0xFA000 (based on full-resolution buffer base-addresses) for the quad-views
#define IMAGE_WIDTH 960U
#define IMAGE_HEIGHT 640U
#define OC_ALGO_VIEW_ENABLE 1
//#define WRITE_CAN_OC  // Write inputs to CAN
//#define OC_SIMINP_DEBUG
//#define OC_SIMINP_DEBUG1


namespace oc
{

    class DataProviderOC : public IDataProviderOC
    {
        public:
            explicit DataProviderOC(container::IDataProvider& b_DataProvider_ro);
            virtual ~DataProviderOC();

        virtual bsp::TIOVXHost& getTIOVX_ro() override;
        virtual container::OVL3DData* getOVL3DData_po() override;

        uint32_t getFrameNum_u32() const override;
        void setFrameNum_u32() override;
		
        float32_t getSpeed_f32() const override;
        float32_t getWheelAngle_f32() const override;
		
        unsigned long& getProcessedFrameNum() override;

        do_CameraParam& getFrontDoCameraParam() override;
        do_CameraParam& getLeftDoCameraParam() override;
        do_CameraParam& getRearDoCameraParam() override;
        do_CameraParam& getRightDoCameraParam() override;

        const uint8_t* getFrontInputImage() const override;
        const uint8_t* getLeftInputImage() const override;
        const uint8_t* getRearInputImage() const override;
        const uint8_t* getRightInputImage() const override;

        void setFrontInputImage() override;
        void setLeftInputImage() override;
        void setRightInputImage() override; 
        void setRearInputImage() override; 

        //PDImplConfigurationData& getPDImplData() override;
        //PdTracker& getPDTracker() override;
        unsigned long getOCImpl() const override;
        //DetectionModel& getDetectionModel() const override;

        //void putExclusionMapOutput(const ExclusionMapOutput& output) override;
        //void putDetectionPtrs(const JobPDDetectionOutput& Detectionptrs) override;
        //void putOutputObjects(const JobPDOutput& output) override;

        void getOCRequest_v ( container::RequestOCCalibCmd_t& o_OCRequest_rt ) override;//tested
        void getOCConfig_v ( uint32_t i_CamID, tscApi::tscPlatformExtConfigType *i_CamConfig_p ) override;//tested
        void getOCKMConfig_v ( tscApi::tscPlatformExtConfigType * i_OCKMConfig_p) override;//tested
        void setCameraparams(container::CameraId_e i_CamID_e, variants::CalibrationTypeE_t i_calibrationType_e) override;
        
		void setOCResponse_v( const ME_Hydra3defs_E_AlgoCommand_t i_RequestCmd_t, tscApi::CalibrationParams_s* o_Output_ro, container::OcData_s *o_OCStatus_p) override;
		
		void dump_FrontAlgoViewImages() override;
		void dump_LeftAlgoViewImages() override;
		void dump_RearAlgoViewImages() override;
		void dump_RightAlgoViewImages() override;

        void setOCRuntime(uint32_t u_Runtime_u32);
        void setOCThreadRuntime(uint32_t u_Runtime_u32);
        virtual PerformanceStatsEnable_t get_PerformanceStatsEnable(void) ME_OVERRIDE;

    private:
        uint32_t u_frameNo;
        container::IDataProvider&    dataProvider_ro;
        TbSVS_e_SVSCalibSMToAlgoCamCalib_t i_SMToOCAlgo;
        //pd::Setup& initialization_configuration;
        do_CameraParam m_aFrontCameraInfo;
        do_CameraParam m_aLeftCameraInfo;
        do_CameraParam m_aRearCameraInfo;
        do_CameraParam m_aRightCameraInfo;
        // 640x400 FE Camera view pointers
        uint8_t *m_pFrontInputImage;
        uint8_t *m_pLeftInputImage;
        uint8_t *m_pRearInputImage;
        uint8_t *m_pRightInputImage;
        ME_Hydra3defs_S_OCStatus_t  OcData_s; 
        oc::VehicleData o_VehData_oc; 
        bsp::TIOVXConsumer tiovxConsumer;
        bool Logging_enabled;
        unsigned long& ProcessedFrameNum;
        ME_Hydra3defs_E_AlgoID_t CalsmAlgoType;
        unsigned long hOCImpl;
        uint32_t  cameraVersion_t[tscApi::e_TscNumCam];
        container::Oc_hmi_data_s oc_hmi_info;
    };

    
}  // namespace oc

#endif  // DATAPROVIDER_OC_H_
