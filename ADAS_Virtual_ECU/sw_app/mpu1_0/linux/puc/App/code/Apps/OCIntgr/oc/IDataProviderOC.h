#ifndef IDATA_OC_PROVIDER__H
#define IDATA_OC_PROVIDER__H

#include "mecl/mecl.h"
#include "Camera.h"

#include "cfg/IDataProvider.h"
#include <cfg/shmdata/OcMData.h>
#include <cfg/shmdata/SigMData.h>
#include "tscApi.h"

namespace oc
{
    class IDataProviderOC
    {
    public:
        explicit IDataProviderOC()
        {
        }

        virtual ~IDataProviderOC()
        {
        }

        virtual bsp::TIOVXHost& getTIOVX_ro() = 0;
        virtual container::OVL3DData* getOVL3DData_po() = 0;

        virtual uint32_t getFrameNum_u32() const = 0;
        virtual void setFrameNum_u32() = 0;


        virtual float32_t getSpeed_f32() const = 0;
        virtual float32_t getWheelAngle_f32() const = 0;
 

        virtual unsigned long& getProcessedFrameNum() = 0;

        //virtual intg::CameraSource getObjCamSrc() = 0;
        virtual do_CameraParam& getFrontDoCameraParam() = 0;
        virtual do_CameraParam& getLeftDoCameraParam() = 0;
        virtual do_CameraParam& getRearDoCameraParam() = 0;
        virtual do_CameraParam& getRightDoCameraParam() = 0;

        // Placeholder functions for getting FE image pointers
        virtual const uint8_t* getFrontInputImage() const = 0;
        virtual const uint8_t* getLeftInputImage() const = 0;
        virtual const uint8_t* getRearInputImage() const = 0;
        virtual const uint8_t* getRightInputImage() const = 0;

        virtual void setFrontInputImage() = 0;
        virtual void setLeftInputImage() = 0;
        virtual void setRightInputImage() = 0;
        virtual void setRearInputImage() = 0;

        //virtual PDImplConfigurationData& getPDImplData() = 0;
        //virtual PdTracker& getPDTracker() = 0;
        virtual unsigned long getOCImpl() const = 0;
        //virtual DetectionModel& getDetectionModel() const = 0;

        //virtual void putExclusionMapOutput(const ExclusionMapOutput& output) = 0; //Output
        //virtual void putDetectionPtrs(const JobPDDetectionOutput& Detectionptrs) = 0; //Output
        //virtual void putOutputObjects(const JobPDOutput& output) = 0; //Output
        virtual void getOCRequest_v ( container::RequestOCCalibCmd_t& o_OCRequest_rt )  = 0;
        virtual void getOCConfig_v ( uint32_t i_CamID, tscApi::tscPlatformExtConfigType *i_CamConfig_p ) = 0;//tested
        virtual void getOCKMConfig_v (tscApi::tscPlatformExtConfigType * i_OCKMConfig_p) = 0;//tested
        virtual void setCameraparams(container::CameraId_e i_CamID_e, variants::CalibrationTypeE_t i_calibrationType_e) = 0;
		virtual void setOCResponse_v( const ME_Hydra3defs_E_AlgoCommand_t i_RequestCmd_t, tscApi::CalibrationParams_s* o_Output_ro, container::OcData_s *o_OCStatus_p) = 0;

		virtual void dump_FrontAlgoViewImages() = 0;
		virtual void dump_LeftAlgoViewImages()  = 0;
		virtual void dump_RearAlgoViewImages()  = 0;
		virtual void dump_RightAlgoViewImages() = 0;
        virtual void setOCRuntime(uint32_t u_Runtime_u32) = 0;
        virtual void setOCThreadRuntime(uint32_t u_Runtime_u32) = 0;
        virtual PerformanceStatsEnable_t get_PerformanceStatsEnable(void) = 0;
    };
} // namespace oc

#endif
