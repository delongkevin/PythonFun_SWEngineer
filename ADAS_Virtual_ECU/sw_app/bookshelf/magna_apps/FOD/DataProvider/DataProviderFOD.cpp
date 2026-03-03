// ----------------------------------------------------------------------------
// --- Copyright (c) Magna Vectrics 2019
// ----------------------------------------------------------------------------

// #include "stdafx.h"
#include "PlatformDataTypes.h"

#include "SignalDef.h"
#include "DataProviderFOD.h"

#define FOD_DEBUG_PRINT 0
#define FOD_TO_USE_SIGM_DATA 1
#define FOD_TUNNING_HARDCODE_PARAMS 1

#if FOD_DEBUG_PRINT
#include "UART_stdio.h"
#endif
#if WINDOWS_CODE
#include <opencv2/highgui.hpp>
#endif //WINDOWS_CODE

#if FOD_OFFLINE_TEST
    #include "UART_stdio.h"
    #include <ti/osal/TaskP.h>

    /*Veh data*/
    #include "SanityInput\m_VehData_c\test_gearDirection_e.h"
    #include "SanityInput\m_VehData_c\test_steeringWheelAngle_f32.h"
    #include "SanityInput\m_VehData_c\test_timeStamp_f32.h"
    #include "SanityInput\m_VehData_c\test_vehSpeedB2_f32.h"
    #include "SanityInput\m_VehData_c\test_vehSpeed_f32.h"
    #include "SanityInput\m_VehData_c\test_wheelAngle_f32.h"

    static int OFFLINE_TEST_COUNTER = 0;
#endif

namespace fod
{
    DataProviderFOD::DataProviderFOD( FODCONFIGData& config,
                                      TbFOD_VrntTunParam_t& tuningParam,
                                      Job_Inputs_t& jobInput,
                                      JobFODOutput_t& jobFodOutput_s )
        : IDataProviderFOD(),
          m_FODconfig( config ),
          m_FODTuningParam( tuningParam ),
          m_JobInput_s( jobInput ),
          m_JobFodOutput_s( jobFodOutput_s )
    {
    }

    //----------------------------------------------------------------------
    /// @brief Returns FOD Configs
    ///
    /// @attention warnings, references, examples etc.
    /// @par Example usage:
    /// @code{.cpp}
    /// // comments in code are also supported.
    /// @endcode
    ///
    /// @param
    /// @return m_FODconfig
    // ---------------------------------------------------------------------

    const FODCONFIGData& DataProviderFOD::c_getFODConfig() const
    {
        //Init values taken from cfg file
        m_FODconfig.ConfigParams.FOD_SPEEDLIM_MIN_F32 = 0.00f;
        m_FODconfig.ConfigParams.FOD_SPEEDLIM_MAX_F32 = 11.00f;
        m_FODconfig.ConfigParams.ROI_ZONE = 5010000.00f;

#if FOD_OFFLINE_TEST
        m_FODconfig.FODParam.FOD_SPEEDLIM_MIN_F32 = 0.00f;
        m_FODconfig.FODParam.FOD_SPEEDLIM_MAX_F32 = 11.00f;
        m_FODconfig.FODParam.LatitudinalDistance = 2505.00f;
        m_FODconfig.FODParam.LongitudinalDistance = 2000.00f;
        m_FODconfig.FODParam.ROI_ZONE = 5010000.00f;
#endif
        return m_FODconfig;
    }

    //----------------------------------------------------------------------
    /// @brief Get vehData from m_CANTranslationInfo, Set to local variables and Returns vehData
    ///
    /// @attention warnings, references, examples etc.
    /// @par Example usage:
    /// @code{.cpp}
    /// // comments in code are also supported.
    /// @endcode
    ///
    /// @param
    /// @return vehData
    // ---------------------------------------------------------------------

    VehicleDataFOD DataProviderFOD::c_getVehicleData() const
    {
        VehicleDataFOD vehData;
#if FOD_TO_USE_SIGM_DATA
        static ME_VehInp_to_IpcSignals_t v_VehData_st = {0};
        SigMgr_ME_VehInp_to_IpcSignals_data_f_Get(&v_VehData_st);
        vehData.IeCANFD2_kph_VehicleSpeedVSOSig = ( float32_t )v_VehData_st.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig;
        //vehData.IeCANFD2_kph_VehicleSpeedVSOSigB2 = ( float32_t )v_VehData_st.CAN14_to_IPC.DataInp_FD14_BRAKE2_FD_1.FD14_VehicleSpeedVSOSig_B2;

        if( vehData.IeCANFD2_kph_VehicleSpeedVSOSig < 1 )
        {
            float32_t wheelspeed = 0;
            uint8_t sc = 0;

            if( v_VehData_st.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHFWheelSpeed < 246.24 && v_VehData_st.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHFWheelSpeed != 0 )
            {
                wheelspeed += v_VehData_st.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHFWheelSpeed;
                sc++;
            }

            if( v_VehData_st.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHFWheelSpeed < 246.24 && v_VehData_st.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHFWheelSpeed != 0 )
            {
                wheelspeed += v_VehData_st.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHFWheelSpeed;
                sc++;
            }

            if( v_VehData_st.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHRWheelSpeed < 246.24 && v_VehData_st.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHRWheelSpeed != 0 )
            {
                wheelspeed += v_VehData_st.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHRWheelSpeed;
                sc++;
            }

            if( v_VehData_st.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHRWheelSpeed < 246.24 && v_VehData_st.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHRWheelSpeed != 0 )
            {
                wheelspeed += v_VehData_st.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHRWheelSpeed; //mm per sec
                sc++;
            }

            if( sc > 0 )
            {
                vehData.IeCANFD2_kph_VehicleSpeedVSOSig = ( float )( 2.43664 * wheelspeed / sc * 0.06 );
            }
        }

        vehData.IeVBII_deg_StrWhlAng = ( float32_t )v_VehData_st.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_LwsAngle;
        vehData.wheelAngle_f32 = vehData.IeVBII_deg_StrWhlAng; 
        uint8 GearEngaged  = (eVehicleGear_t)v_VehData_st.CAN2_to_IPC.DataInp_TRANSM_FD_4.GearEngaged;

        if((1 <= GearEngaged) && (9 >= GearEngaged))
        {
            vehData.IeVBII_e_GearRptState = GearValues_E_GEAR_FORWARD;
        }
        else if(0 == GearEngaged)
        {
            vehData.IeVBII_e_GearRptState = GearValues_E_GEAR_NEUTRAL;
        }
        else if(13 == GearEngaged)
        {
            vehData.IeVBII_e_GearRptState = GearValues_E_GEAR_PARK;
        }
        else if(14 == GearEngaged)
        {
            vehData.IeVBII_e_GearRptState = GearValues_E_GEAR_REVERSE;
        }
#endif

#if FOD_OFFLINE_TEST
        vehData.IeVBII_e_GearRptState = ( eVehicleGear_t )gearDirection_e[OFFLINE_TEST_COUNTER];
        vehData.IeVBII_deg_StrWhlAng = steeringWheelAngle_f32[OFFLINE_TEST_COUNTER];
        vehData.timeStamp_f32 = timeStamp_f32[OFFLINE_TEST_COUNTER];
        //vehData.IeCANFD2_kph_VehicleSpeedVSOSigB2 = vehSpeedB2_f32[OFFLINE_TEST_COUNTER];
        vehData.IeCANFD2_kph_VehicleSpeedVSOSig = vehSpeed_f32[OFFLINE_TEST_COUNTER];
        vehData.wheelAngle_f32 = wheelAngle_f32[OFFLINE_TEST_COUNTER];

#endif

#if FOD_DEBUG_PRINT
        UART_printf("vehData.gearDirection_e : %d\n\n", GearEngaged);

        char PrintLineI1[100] = {0};
        UART_printf("vehData.vehSpeed_f32 : ");
        sprintf(PrintLineI1, "%f\n\n", vehData.IeCANFD2_kph_VehicleSpeedVSOSig);
        UART_printf("%s", PrintLineI1);
        (void)memset(PrintLineI1, 0, sizeof(PrintLineI1));

        char PrintLineI2[100] = {0};
        UART_printf("vehData.vehSpeedB2_f32 : ");
        sprintf(PrintLineI2, "%f\n\n", vehData.IeCANFD2_kph_VehicleSpeedVSOSigB2);
        UART_printf("%s", PrintLineI2);
        (void)memset(PrintLineI2, 0, sizeof(PrintLineI2));
#endif
        //vehData.timeStamp_f32 = ( float32_t )m_CANTranslationInfo->m_YawRateTimeStamp; // TODO: recheck for wheel angle Kedar N.
        return vehData;
    }

    //----------------------------------------------------------------------
    /// @brief Get kinematicData from m_MsgParserInfo, Sets to local variables and Returns kinematicData
    ///
    /// @attention warnings, references, examples etc.
    /// @par Example usage:
    /// @code{.cpp}
    /// // comments in code are also supported.
    /// @endcode
    ///
    /// @param
    /// @return kinematicData
    // ---------------------------------------------------------------------

    KinematicDataFOD DataProviderFOD::c_getKinematicData() const
    {
        KinematicDataFOD KMData;
        static IKinematicData_t v_KMData_st = {0};
        SigMgr_Data_IKinematicData_t_Get(&v_KMData_st);
        KMData.IeVBII_delta_Dx = (float32_t)v_KMData_st.dx_m;
        KMData.IeVBII_delta_Dy = (float32_t)v_KMData_st.dy_m;
        KMData.IeVBII_delta_Dyaw = (float32_t)v_KMData_st.dyaw_rad;
        KMData.timestamp_s = (float32_t)v_KMData_st.timestamp_s;
        return KMData;
    }

    /* Get FOD Input */
    Job_Inputs_t DataProviderFOD::getFODInput()
    {
#if FOD_TO_USE_SIGM_DATA    
        //static ME_VehInp_to_IpcSignals_t v_VehData_st = {0};
        //SigMgr_ME_VehInp_to_IpcSignals_data_f_Get(&v_VehData_st);
        //m_JobInput_s.FOD_Inputs_ADASFDINFO_s.IeCANFD2_e_HasStatus = (HasStatus_t)v_VehData_st.CAN14_to_IPC.DataInp_FD14_ADAS_FD_INFO.FD14_HAS_Status;
        //m_JobInput_s.FOD_Inputs_ADASFDINFO_s.IeCANFD2_e_HasStatus   = fod::HasStatus_t::Engaged;

        static ME_ProxiToMCU2_1_Def_t v_ProxiData_st = {0};
        static bool_t validProxyReceived_b = FALSE;
        if (FALSE == validProxyReceived_b)
        {
          SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Get(&v_ProxiData_st);
          if (TRUE == v_ProxiData_st.PRX_bValid_b)
          {
            validProxyReceived_b = TRUE;
          }
        }

        m_JobInput_s.FOD_Inputs_ProxiM_s.MePRX_e_AutonomyLvl = (ProxiAutonomyLevel_t)v_ProxiData_st.PRX_AutonomyLvl_u8;        

        static FID_STRUCT_B v_FOD_DegradationM_st = {0};
        SigMgr_Data_FID_STRUCT_B_Get(&v_FOD_DegradationM_st);
        m_JobInput_s.FOD_Inputs_DegradationM_s.m_A_FID_FOD_DISABLED = (FODFID_t)v_FOD_DegradationM_st.m_B_FID_FOD_DISABLED;
        m_JobInput_s.FOD_Inputs_DegradationM_s.m_A_FID_FOD_LIMITED  = (FODFID_t)v_FOD_DegradationM_st.m_B_FID_FOD_LIMITED;
        m_JobInput_s.FOD_Inputs_DegradationM_s.m_A_FID_FOD_DISABLED_SensorBlockage  = (FODFID_t)v_FOD_DegradationM_st.m_B_FID_FOD_DISABLED_SensorBlockage;
        m_JobInput_s.FOD_Inputs_DegradationM_s.m_A_FID_FOD_LIMITED_SensorBlockage  = (FODFID_t)v_FOD_DegradationM_st.m_B_FID_FOD_LIMITED_SensorBlockage;
#endif
#if 0
        //-------------Set default values to FIDs
        m_JobInput_s.FOD_Inputs_DegradationM_s.m_A_FID_FOD_DISABLED = fod::FODFID_t::FID_NotActive;
        m_JobInput_s.FOD_Inputs_DegradationM_s.m_A_FID_FOD_LIMITED  = fod::FODFID_t::FID_NotActive;
        m_JobInput_s.FOD_Inputs_DegradationM_s.m_A_FID_FOD_DISABLED_SensorBlockage = fod::FODFID_t::FID_NotActive;
        m_JobInput_s.FOD_Inputs_DegradationM_s.m_A_FID_FOD_LIMITED_SensorBlockage  = fod::FODFID_t::FID_NotActive;
        m_JobInput_s.FOD_Inputs_ProxiM_s.MePRX_e_AutonomyLvl   = fod::ProxiAutonomyLevel_t::Level2;
        m_JobInput_s.FOD_Inputs_ADASFDINFO_s.IeCANFD2_e_HasStatus   = fod::HasStatus_t::Engaged;
#endif

        m_JobInput_s.m_VehicleData = c_getVehicleData();
        #if WINDOWS_NOTINUSE_CODE
        m_JobInput_s.m_KinematicData = c_getKinematicData();
        #endif

#if FOD_DEBUG_PRINT
        UART_printf("*************** FOD Start ***************\n");
        UART_printf("*************** FOD Inputs ***************\n");

        UART_printf("m_JobInput_s.FOD_Inputs_ADASFDINFO_s.IeCANFD2_e_HasStatus                   : %d \n",(int)m_JobInput_s.FOD_Inputs_ADASFDINFO_s.IeCANFD2_e_HasStatus);
        UART_printf("m_JobInput_s.FOD_Inputs_ProxiM_s.MePRX_e_AutonomyLvl                        : %d \n",(int)m_JobInput_s.FOD_Inputs_ProxiM_s.MePRX_e_AutonomyLvl);
        UART_printf("m_JobInput_s.FOD_Inputs_ProxiM_s.MePRX_b_SurroundViewCamera                 : %d \n",(int)m_JobInput_s.FOD_Inputs_ProxiM_s.MePRX_b_SurroundViewCamera );
        UART_printf("m_JobInput_s.FOD_Inputs_DegradationM_s.FIDDisabled_e                        : %d \n",(int)m_JobInput_s.FOD_Inputs_DegradationM_s.m_A_FID_FOD_DISABLED);
        UART_printf("m_JobInput_s.FOD_Inputs_DegradationM_s.FIDLimited_e                         : %d \n",(int)m_JobInput_s.FOD_Inputs_DegradationM_s.m_A_FID_FOD_LIMITED);
        UART_printf("m_JobInput_s.FOD_Inputs_DegradationM_s.m_B_FID_FOD_DISABLED_SensorBlockage  : %d \n",(int)m_JobInput_s.FOD_Inputs_DegradationM_s.m_A_FID_FOD_DISABLED_SensorBlockage );
        UART_printf("m_JobInput_s.FOD_Inputs_DegradationM_s.m_A_FID_FOD_LIMITED_SensorBlockage   : %d \n\n",(int)m_JobInput_s.FOD_Inputs_DegradationM_s.m_A_FID_FOD_LIMITED_SensorBlockage );
#endif
        return m_JobInput_s;
    }

    void DataProviderFOD::putFODOutput( JobFODOutput_t& fodOutput )
    {
        static IFOD_Outputs_CVPAMFDData_t m_FODOutput;
        static IDebug_FODObject_t m_FODObjectInfo_Debug;
        //bool_t varChanged_b = false;

        /*FOD Main Output*/
        if( (m_FODOutput.IeFOD_e_FODHealth == fodOutput.FOD_Outputs_ADASFDLANES1_s.IeFOD_e_FODHealth)
           && (m_FODOutput.IeFOD_e_FODConfidence == fodOutput.FOD_Outputs_ADASFDLANES1_s.IeFOD_e_FODConfidence))
        {
            //varChanged_b = false;
            //Same as last cycle, so do nothing.
        }
        else // Data changed from last cycle so send the latest data to IPC
        {
            m_FODOutput.IeFOD_e_FODHealth = fodOutput.FOD_Outputs_ADASFDLANES1_s.IeFOD_e_FODHealth;
            m_FODOutput.IeFOD_e_FODConfidence =fodOutput.FOD_Outputs_ADASFDLANES1_s.IeFOD_e_FODConfidence;
            SigMgr_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t_Put(&m_FODOutput);
        }
        m_FODObjectInfo_Debug.obj_Pos_Lat = fodOutput.Debug_FODObject_s.obj_Pos_Lat;
        m_FODObjectInfo_Debug.obj_Pos_Longi = fodOutput.Debug_FODObject_s.obj_Pos_Longi;
        m_FODObjectInfo_Debug.macCvpamFdData1_u64 = fodOutput.Debug_FODObject_s.macCvpamFdData1_u64;
        m_FODObjectInfo_Debug.cntrCvpamFdData1_u16 = fodOutput.Debug_FODObject_s.cntrCvpamFdData1_u16;
        m_FODObjectInfo_Debug.msgcntrCvpamFdData1_u8 = fodOutput.Debug_FODObject_s.msgcntrCvpamFdData1_u8;
        m_FODObjectInfo_Debug.crcCvpamFdData1_u8  = fodOutput.Debug_FODObject_s.crcCvpamFdData1_u8;
        m_FODObjectInfo_Debug.FrontSensorDetHealth_e = fodOutput.Debug_FODObject_s.FrontSensorDetHealth_e;
        m_FODObjectInfo_Debug.objConf_e = fodOutput.Debug_FODObject_s.objConf_e;

        ME_CanDebugRIDStatus_t debugStatus_s;
        SigMgr_Data_ME_CanDebugRIDStatus_t_Get(&debugStatus_s);
        // Send Debug IPC message only when enabled via RID
        if (Debug_Mode == debugStatus_s.CanDebugMode)
        {
          SigMgr_PpIDebugFODObject_IDebug_FODObject_t_Put(&m_FODObjectInfo_Debug);
        }
#if FOD_DEBUG_PRINT
        UART_printf("*************** FOD Outputs ***************\n\n");

        UART_printf("m_FODOutput.frontSensorDetHealth_e : %d\n", m_FODOutput.IeFOD_e_FODHealth);
        UART_printf("m_FODOutput.objConf_e : %d\n\n\n", m_FODOutput.IeFOD_e_FODConfidence);
    
        UART_printf("*************** FOD End ***************\n\n\n");
#endif
        
        
        //m_JobFodOutput_s = fodOutput;


#if FOD_OFFLINE_TEST
       static uint8 FOD_output_print = 1;
       static char Buffer[250] = {0};
       if(FOD_output_print == 1)
       {
        UART_printf("Counter;m_JobFODOutput.frontSensorDetHealth_e;m_JobFODOutput.objConf_e;\n");
        FOD_output_print = 0;
       }
        
        sprintf(Buffer," %d ; %d ;  %d ;\n ",OFFLINE_TEST_COUNTER, fodOutput.FOD_Outputs_ADASFDLANES1_s.IeFOD_e_FODHealth , fodOutput.FOD_Outputs_ADASFDLANES1_s.IeFOD_e_FODConfidence);
        UART_printf("%s", Buffer);
        TaskP_sleepInMsecs(5);
        OFFLINE_TEST_COUNTER++;

        if(OFFLINE_TEST_COUNTER > 200)
        {
            OFFLINE_TEST_COUNTER = 0;
        }
#endif

    }

    JobFODOutput_t DataProviderFOD::getFODOutput() const
    {
        return m_JobFodOutput_s;
    }

    TbFOD_VrntTunParam_t DataProviderFOD::getFODTunningParams(FODCONFIGData& m_FODCfg)
    {
        bool_t FOD_CalBinData = true;
        if(FOD_CalBinData)
        {
#if FOD_TO_USE_SIGM_DATA
            static CalDataProvider_MCU_2_1_Def CalDataProvider_MCU_2_1_FOD;
            SigMgr_Data_CalDataProvider_MCU_2_1_Def_Get(&CalDataProvider_MCU_2_1_FOD);

            static APA_Calibration_data_MCU2_1_t FOD_Veh_Calibration_data;
            SigMgr_Data_APA_Calibration_data_MCU2_1_t_Get(&FOD_Veh_Calibration_data);
            m_FODCfg.FODCalibrationParams.VEHICLE_LENGTH = FOD_Veh_Calibration_data.CalData4.VEHICLE_LENGTH;
            m_FODCfg.FODCalibrationParams.VEHICLE_WIDTH  = FOD_Veh_Calibration_data.CalData4.VEHICLE_WIDTH;
            m_FODCfg.FODCalibrationParams.FRONT_OVERHANG = FOD_Veh_Calibration_data.CalData4.FRONT_OVERHANG;
            m_FODCfg.FODCalibrationParams.WHEEL_BASE     = FOD_Veh_Calibration_data.CalData4.WHEEL_BASE;

            static FOD_Calibration_data_t FOD_Env_Calibration_data;
            SigMgr_Data_FOD_Calibration_data_t_Get(&FOD_Env_Calibration_data);
            m_FODCfg.FODCalibrationParams.KeFOD_mm_LongiDistThd =  FOD_Env_Calibration_data.CalData.KeFOD_mm_LongiDistThd;
            m_FODCfg.FODCalibrationParams.KeFOD_mm_LatiDistThd  =  FOD_Env_Calibration_data.CalData.KeFOD_mm_LatiDistThd;
            m_FODCfg.FODCalibrationParams.KeFOD_mm_DistY1Thd    =  FOD_Env_Calibration_data.CalData.KeFOD_mm_DistY1Thd;
            m_FODCfg.FODCalibrationParams.KeFOD_mm_DistY2Thd    =  FOD_Env_Calibration_data.CalData.KeFOD_mm_DistY2Thd;
            m_FODCfg.FODCalibrationParams.KeFOD_cm_ObjDetctXThd =  FOD_Env_Calibration_data.CalData.KeFOD_cm_ObjDetctXThd;
#endif
#if FOD_TUNNING_HARDCODE_PARAMS
            m_FODTuningParam.KeFOD_mm_LongiDistThd =  2000.00f;
            m_FODTuningParam.KeFOD_mm_LatiDistThd  =  2505.00f;
            m_FODTuningParam.KeFOD_mm_DistY1Thd    =  -1252.50f;
            m_FODTuningParam.KeFOD_mm_DistY2Thd    =  1252.50f;
            m_FODTuningParam.KeFOD_cm_ObjDetctXThd =  0.1f;
#endif

#if FOD_OFFLINE_TEST
            m_FODTuningParam.VEHICLE_LENGTH = 4840;
            m_FODTuningParam.VEHICLE_WIDTH  = 1905;
            m_FODTuningParam.FRONT_OVERHANG = 897;
            m_FODTuningParam.WHEEL_BASE     = 2915.0f;
#endif
        }
        else
        {
            m_FODTuningParam.WHEEL_BASE = 2915.00f;
            m_FODTuningParam.FRONT_OVERHANG = 897;
            m_FODTuningParam.VEHICLE_LENGTH = 4840;
            m_FODTuningParam.VEHICLE_WIDTH = 1905;
            m_FODTuningParam.KeFOD_mm_LongiDistThd =  2000.00f;
            m_FODTuningParam.KeFOD_mm_LatiDistThd  =  2505.00f;
            m_FODTuningParam.KeFOD_mm_DistY1Thd    =  -1252.50f;
            m_FODTuningParam.KeFOD_mm_DistY2Thd    =  1252.50f;
            m_FODTuningParam.KeFOD_cm_ObjDetctXThd =  0.1f;
        }
        return m_FODTuningParam;
    }

} // !namespace fod
