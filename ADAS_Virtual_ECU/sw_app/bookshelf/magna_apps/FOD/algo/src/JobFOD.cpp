// ----------------------------------------------------------------------------
// --- Copyright (c) Magna Vectrics 2019
// ----------------------------------------------------------------------------

#include "../algo/inc/JobFOD.h"

#define FOD_DEBUG_PRINTS 0

#if FOD_DEBUG_PRINTS
#include "UART_stdio.h"
#endif

namespace fod
{
    JobFOD::JobFOD( IDataProviderFOD *i_dataProvider_ro )
    {
        dataProvider_ro = i_dataProvider_ro;            
    }


    JobFOD::~JobFOD()
    {
#if WINDOWS_CODE

        if( m_KpiFile.is_open() )
        {
            m_KpiFile.close();
        }
        else
        {
            // Do Nothing.
        }

#endif
    }


#if WINDOWS_CODE
    char* JobFOD::getGearDirText( const eVehicleGear_t gearDirection )
    {
        switch( gearDirection )
        {
            case eVehicleGear_t::GearValues_E_GEAR_REVERSE:
            {
                return "REVERSE";
                break;
            }

            case eVehicleGear_t::GearValues_E_GEAR_NEUTRAL:
            {
                return "NEUTRAL";
                break;
            }

            case eVehicleGear_t::GearValues_E_GEAR_FORWARD:
            {
                return "FORWARD";
                break;
            }

            case eVehicleGear_t::GearValues_E_GEAR_PARK:
            {
                return "PARK";
                break;
            }

            default:
            {
                break;
            }
        }
    }


    char* JobFOD::getFODHealthText( const FODHealth_t frontSensorDetHealth )
    {
        switch( frontSensorDetHealth )
        {
            case FODHealth_t::Faulted:
            {
                return "FAULTED";
                break;
            }

            case FODHealth_t::Blocked:
            {
                return "BLOCKED";
                break;
            }

            case FODHealth_t::Healthy:
            {
                return "HEALTHY";
                break;
            }

            case FODHealth_t::Unknown:
            default:
            {
                return "UNKNOWN";
                break;
            }
        }
    }


    char* JobFOD::getObjConfText( const Confidence_t objConf )
    {
        switch( objConf )
        {
            case Confidence_t::Detected_High_Confidence:
            {
                return "HIGH";
                break;
            }

            case Confidence_t::Detected_Medium_Confidence:
            {
                return "MEDIUM";
                break;
            }

            case Confidence_t::Detected_Low_Confidence:
            {
                return "LOW";
                break;
            }

            case Confidence_t::Not_Detected:
            default:
            {
                return "NONE";
                break;
            }
        }
    }


    void JobFOD::InitKPIResult()
    {
        if( m_KpiFile.is_open() )
        {
            m_KpiFile.close();
        }

        char vidFileName[MAX_PATH_LEN];
        _splitpath( g__pAppCtrl->m_VideoName, NULL, NULL, vidFileName, NULL );
        std::string strCsvFileName = std::string( vidFileName ) + ".csv";
        // open the file
        m_KpiFile.open( strCsvFileName );
        std::string m_Header = "FrameNum,GearDir,FODHealth,FODConf";
        m_KpiFile << m_Header << std::endl;
    }


    void JobFOD::WriteKPIResult( FODKPIOutputData FODKpiOutputData )
    {
        // --- Frame number
        m_KpiFile << g__pAppCtrl->m_FrameNumber << ",";
        // --- Front Object info
        m_KpiFile << getGearDirText( FODKpiOutputData.gearDir ) << ","
                  << getFODHealthText( FODKpiOutputData.frontSensorDetHealth ) << ","
                  << getObjConfText( FODKpiOutputData.objConf ) << ",";
        m_KpiFile << std::endl;
    }
#endif


    void JobFOD::init_v( void )
    {
        //*** Get FOD Configs ***
        m_FODCfg = dataProvider_ro->c_getFODConfig();
        //*** Get Tuning Parameters ***
        m_FodTuningParam = dataProvider_ro->getFODTunningParams(m_FODCfg);

        //***
        m_fodAlgo.Init( m_FODCfg, m_FodTuningParam );
        FrontObjectDetection_initialize();
        MeFOD_m_MinXDist = 0.0f;
        MeFOD_m_MinXDistSide = 0.0f;
        m_FodHealth_e = FODHealth_t::Unknown;
#if WINDOWS_CODE

        if( m_FODCfg.KPIConfigParams.KpiEnable == true )
        {
            InitKPIResult();
        }
        else
        {
            // Do Nothing
        }

#endif
    }


    bool_t JobFOD::hasNext_b( void )
    {
        bool_t out = true;
        return out;
    }


    void JobFOD::start_v( void )
    {
#if FOD_DEBUG_PRINTS
        UART_printf("*************** JobFOD::start_v() ***************\n");
#endif
        reset_v();
        //*** Init & Get Job Input ***
        m_JobFODInput = dataProvider_ro->getFODInput();
        FrontObjectDetection_step();
        MeFOD_m_MinXDist = 0.0f;
        MeFOD_m_MinXDistSide = 0.0f;
        //*** Update FOD state machine
        m_FodState.UpdateFODStateMachine( m_JobFODInput, m_FODCfg, m_FodHealth_e );
    }


    void JobFOD::execute_v( void )
    {
        //************************************
        //         Object Processing
        //************************************

        //*** If FOD Status is Active and FOD sensor health is Healthy, then process the algorithm ***
        if( ( m_FodHealth_e == FODHealth_t::Healthy ) )
        {
            //int16_t MeFOD_cm_FrntCenterMinXDist = 200;
            //int16_t MeFOD_cm_FrntSideMinXDist = 200;
            MeFOD_m_MinXDist = static_cast<float32_t>( MeFOD_cm_FrntCenterMinXDist / 100.0f ); // convert cm into m;
            MeFOD_m_MinXDistSide = static_cast<float32_t>( MeFOD_cm_FrntSideMinXDist / 100.0f ); // convert cm into m;
            //*** get output from algorithm ***
            m_fodAlgo.Run( MeFOD_m_MinXDist, MeFOD_m_MinXDistSide );
            m_JobFODOutput = m_fodAlgo.getFODDetOutputAlgo();
        }
    }


    void JobFOD::end_v( void )
    {
        //--- FOD CAN output
        m_JobFODOutput.FOD_Outputs_ADASFDLANES1_s.IeFOD_e_FODHealth = m_FodHealth_e;
        //--- FOD debug output
        m_JobFODOutput.Debug_FODObject_s.obj_Pos_Longi = MeFOD_m_MinXDist;
        m_JobFODOutput.Debug_FODObject_s.obj_Pos_Lat = MeFOD_m_MinXDistSide;
        m_JobFODOutput.Debug_FODObject_s.FrontSensorDetHealth_e = m_JobFODOutput.FOD_Outputs_ADASFDLANES1_s.IeFOD_e_FODHealth;
        m_JobFODOutput.Debug_FODObject_s.objConf_e = m_JobFODOutput.FOD_Outputs_ADASFDLANES1_s.IeFOD_e_FODConfidence;
        //--- Put FOD output data
        dataProvider_ro->putFODOutput( m_JobFODOutput );
#if FOD_DEBUG_PRINTS
        UART_printf("*************** m_JobFODOutput.IeFOD_e_FODHealth = %d***************\n", (int)m_JobFODOutput.FOD_Outputs_ADASFDLANES1_s.IeFOD_e_FODHealth);
        UART_printf("*************** m_JobFODOutput.Fod_Status_e = %d***************\n", (int)Fod_Status_e);
        UART_printf("*************** m_JobFODOutput.m_FodHealth_e = %d***************\n\n\n", (int)m_FodHealth_e);
        
        UART_printf("*************** JobFOD::end_v() ***************\n");
#endif
    }


    void JobFOD::dump_v( void )
    {
#if WINDOWS_CODE
        FODKpiOutputData.gearDir = m_JobFODInput.m_VehicleData.IeVBII_e_GearRptState;
        FODKpiOutputData.frontSensorDetHealth = m_JobFODOutput.FOD_Outputs_ADASFDLANES1_s.IeFOD_e_FODHealth;
        FODKpiOutputData.objConf = m_JobFODOutput.FOD_Outputs_ADASFDLANES1_s.IeFOD_e_FODConfidence;
        WriteKPIResult( FODKpiOutputData );
#endif
    }


    void JobFOD::reset_v( void )
    {
        // --- Reset Algo output parameters
        m_fodAlgo.Reset();
        // --- Reset input parameters
        m_JobFODInput.Reset();
        // --- Reset output parameters
        m_JobFODOutput.Reset();
        FrontObjectDetection_terminate();
#if WINDOWS_CODE
        // --- Reset KPI output parameters
        FODKpiOutputData.Reset();
#endif
    }
}
