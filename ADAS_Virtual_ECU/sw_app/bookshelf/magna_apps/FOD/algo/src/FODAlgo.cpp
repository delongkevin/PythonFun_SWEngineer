#include "../algo/inc/JobFOD.h"
#include "../algo/inc/FODAlgo.h"
#if WINDOWS_CODE
#include <opencv2/highgui.hpp>
#endif
#include "mecl/mecl.h"


namespace fod
{
    FODAlgo::FODAlgo():
        //pietoRad( 3.14159 ),
      
        vehWidth( 0.0f ),
        roiLateral( 0.0f ),
        latDistance( 0.0f ),
        longiDistance( 0.0f ),
        wheelbase( 0.0f ),
        frontOverhang( 0.0f ),
        vehiclePosI( 0.0f ),
        vehiclePosII( 0.0f ),
        vehicleMaxDist( 0.0f ),
        objDetctXThd( 0.0f )
    {
    }


    FODAlgo::~FODAlgo()
    {
    }


    void FODAlgo::Init( const FODCONFIGData& i_FodConfig, const TbFOD_VrntTunParam_t& i_FodTuningParam )
    {
        m_FODCfg = i_FodConfig;
        //
        m_FODCfg.ConfigParams.ROI_ZONE = m_FODCfg.FODCalibrationParams.KeFOD_mm_LatiDistThd * m_FODCfg.FODCalibrationParams.KeFOD_mm_LongiDistThd; //update ROI_ZONE
        //
        vehWidth = static_cast<float32_t>( m_FODCfg.FODCalibrationParams.VEHICLE_WIDTH / 1000.0f ); // convert mm into m;
        roiLateral = vehWidth + 0.3;
        latDistance = static_cast<float32_t>( m_FODCfg.FODCalibrationParams.KeFOD_mm_LatiDistThd / 1000.0f ); // convert mm into m;
        longiDistance = static_cast<float32_t>( m_FODCfg.FODCalibrationParams.KeFOD_mm_LongiDistThd / 1000.0f ); // convert mm into m
        wheelbase = static_cast<float32_t>( m_FODCfg.FODCalibrationParams.WHEEL_BASE / 1000.0f ); // convert mm into m
        frontOverhang = static_cast<float32_t>( m_FODCfg.FODCalibrationParams.FRONT_OVERHANG / 1000.0f ); // convert mm into m
        vehicleFrontBumper = 0.0f;
        vehiclePosI = static_cast<float32_t>( m_FODCfg.FODCalibrationParams.KeFOD_mm_DistY1Thd / 1000.0f ); // convert mm into m
        vehiclePosII = static_cast<float32_t>( m_FODCfg.FODCalibrationParams.KeFOD_mm_DistY2Thd / 1000.0f ); // convert mm into m
        vehicleMaxDist = static_cast<float32_t>( longiDistance + vehicleFrontBumper );
        objDetctXThd = static_cast<float32_t>( m_FODCfg.FODCalibrationParams.KeFOD_cm_ObjDetctXThd / 100.0f ); // convert cm into m
    }


    void FODAlgo::Reset()
    {
        m_JobFODOutput.Reset();
#if WINDOWS_CODE
        m_FODKPIOutputData.Reset();
#endif
    }


    JobFODOutput_t FODAlgo::getFODDetOutputAlgo() const
    {
        return m_JobFODOutput;
    }


    void FODAlgo::Run( const float32_t MeFOD_m_MinXDist, const float32_t MeFOD_m_MinXDistSide )
    {
        // Object distance between defined ROI of 2m ( > 0m and <= 2m )
        if( ( MeFOD_m_MinXDist > vehicleFrontBumper ) && ( MeFOD_m_MinXDist <= vehicleMaxDist ) )
        {
            m_JobFODOutput.FOD_Outputs_ADASFDLANES1_s.IeFOD_e_FODConfidence = Detected_High_Confidence;
        }
        else if( ( MeFOD_m_MinXDistSide > vehicleFrontBumper ) && ( MeFOD_m_MinXDistSide <= vehicleMaxDist ) )
        {
            m_JobFODOutput.FOD_Outputs_ADASFDLANES1_s.IeFOD_e_FODConfidence = Detected_Low_Confidence;
        }
        else
        {
            m_JobFODOutput.FOD_Outputs_ADASFDLANES1_s.IeFOD_e_FODConfidence = Not_Detected;
        }
    }
}
