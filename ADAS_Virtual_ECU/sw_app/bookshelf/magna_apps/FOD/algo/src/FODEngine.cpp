#include <assert.h>
#include "FODEngine.h"
#include <iostream>

using namespace std;

namespace fod
{
    FODState::FODState() : StateMachine( FOD_SMStatus_t::ST_MAX_STATES )
    {
        FODSMStatus_e = FOD_SMStatus_t::ST_IDLE;
        isFaulted = false;
        isBlocked = false;
        isCANFaulted = false;
        isFIDFaulted = false;
    }


    FODState::~FODState() noexcept
    {
    }

    //----------------------------------------------------------------------------------------

    // when input signals are not in range then set all the signals to default state
    void FODState::ST_Idle()
    {
        FODSMStatus_e = FOD_SMStatus_t::ST_IDLE;
    }

    // will start the algorithm when everything looks good and input signals are getting received
    void FODState::ST_Active( const FODData* pData )
    {
        FODSMStatus_e = FOD_SMStatus_t::ST_ACTIVE;
    }


    // if any received FID signals is faulty then algo will go in faulty state
    void FODState::ST_Fault()
    {
        FODSMStatus_e = FOD_SMStatus_t::ST_FAULT;
    }


    //----------------------------------------------------------------------------------------

    // halt external event
    void FODState::Halt( void )
    {
        // given the Halt event, transition to a new state based upon
        // the current state of the state machine
        if( isCANFaulted == true )
        {
            BEGIN_TRANSITION_MAP                    // - Current State -
            TRANSITION_MAP_ENTRY( EVENT_IGNORED )   // ST_Idle
            TRANSITION_MAP_ENTRY( ST_IDLE )         // ST_Active
            TRANSITION_MAP_ENTRY( ST_IDLE )         // ST_Fault
            END_TRANSITION_MAP( NULL )
        }
        else if( isFIDFaulted == true )
        {
            BEGIN_TRANSITION_MAP                    // - Current State -
            TRANSITION_MAP_ENTRY( ST_FAULT )        // ST_Idle
            TRANSITION_MAP_ENTRY( ST_FAULT )        // ST_Active
            TRANSITION_MAP_ENTRY( EVENT_IGNORED )   // ST_Fault
            END_TRANSITION_MAP( NULL )
        }
        else
        {
            // Do Nothing
        }
    }


    // set data external event
    void FODState::Active( FODData* pData )
    {
        BEGIN_TRANSITION_MAP                    // - Current State -
        TRANSITION_MAP_ENTRY( ST_ACTIVE )       // ST_Idle
        TRANSITION_MAP_ENTRY( ST_ACTIVE )       // ST_Active
        TRANSITION_MAP_ENTRY( ST_ACTIVE )       // ST_Fault
        END_TRANSITION_MAP( pData )
    }


    //----------------------------------------------------------------------------------------

    //update FOD state machine status
    void FODState::UpdateFODStateMachine( const Job_Inputs_t i_FodInput, const FODCONFIGData i_FodConfig, FODHealth_t& o_FodHealth )
    {
        isFaulted = false;
        isBlocked = false;
        isCANFaulted = false;
        isFIDFaulted = false;

        /*
        Priority for FOD State transitions:
        1. Idle state : FOD health - Unknwon ( checking CAN & Proxi inputs )
        2. Fault state : FOD health - Faulted or Blocked ( checking FID inputs )
        3. Active state : FOD health - Healthy ( checking CAN, Proxi & FID inputs )
        */

        //****** Check CAN FD inputs and set FOD health signal accordingly ******

        if( //*** Check Proxy Autonomy Level value ***
            ( i_FodInput.FOD_Inputs_ProxiM_s.MePRX_e_AutonomyLvl == ProxiAutonomyLevel_t::NoneOrLevel1 ) ||
            //*** Check Gear Direction ***
            ( i_FodInput.m_VehicleData.IeVBII_e_GearRptState != eVehicleGear_t::GearValues_E_GEAR_FORWARD ) ||
            //*** Check Vehicle Speed Limit ***
            ( i_FodInput.m_VehicleData.IeCANFD2_kph_VehicleSpeedVSOSig < i_FodConfig.ConfigParams.FOD_SPEEDLIM_MIN_F32 ) ||
            ( i_FodInput.m_VehicleData.IeCANFD2_kph_VehicleSpeedVSOSig > i_FodConfig.ConfigParams.FOD_SPEEDLIM_MAX_F32 ) )
        {
            isCANFaulted = true;
        }
        //*** Check FID_FOD_DISABLED value ***
        else if( ( i_FodInput.FOD_Inputs_DegradationM_s.m_A_FID_FOD_DISABLED == FODFID_t::FID_Active ) ||
                 ( i_FodInput.FOD_Inputs_DegradationM_s.m_A_FID_FOD_LIMITED == FODFID_t::FID_Active ) )
        {
            isFaulted = true;
            isFIDFaulted = true;
        }
        //*** Check FID_FOD_DISABLED_SensorBlockage value ***
        else if( ( i_FodInput.FOD_Inputs_DegradationM_s.m_A_FID_FOD_DISABLED_SensorBlockage == FODFID_t::FID_Active ) ||
                 ( i_FodInput.FOD_Inputs_DegradationM_s.m_A_FID_FOD_LIMITED_SensorBlockage == FODFID_t::FID_Active ) )
        {
            isBlocked = true;
            isFIDFaulted = true;
        }
        else
        {
            // Do Nothing
        }

        //*** Check for CAN & FID faults & perform transitions ***
        if( ( isCANFaulted == false ) && ( isFIDFaulted == false ) )
        {
            Active( FOD_Inputs_Data );
            //States- ST_ACTIVE
        }
        //* isCANFaulted == true OR isFIDFaulted == true
        //* isCANFaulted == true OR isFIDFaulted == false
        //* isCANFaulted == false OR isFIDFaulted == true
        else
        {
            Halt();
            //States- ST_IDLE ST_FAULT
        }

        //*** Check for FOD State Machine Status and set FOD Health Status accordingly  ***
        switch( FODSMStatus_e )
        {
            case FOD_SMStatus_t::ST_ACTIVE:
            {
                // set FOD health to Healthy
                o_FodHealth = FODHealth_t::Healthy;
                break;
            }

            case FOD_SMStatus_t::ST_FAULT:
            {
                if( isFaulted == true )
                {
                    // set FOD health to Faulted
                    o_FodHealth = FODHealth_t::Faulted;
                }
                else if( isBlocked == true )
                {
                    // set FOD health to Blocked
                    o_FodHealth = FODHealth_t::Blocked;
                }
                else
                {
                    // Do Nothing
                }

                break;
            }

            case FOD_SMStatus_t::ST_IDLE:
            case FOD_SMStatus_t::ST_MAX_STATES:
            default:
            {
                // set FOD health to Unknown
                o_FodHealth = FODHealth_t::Unknown;
                break;
            }
        };
    }

}
