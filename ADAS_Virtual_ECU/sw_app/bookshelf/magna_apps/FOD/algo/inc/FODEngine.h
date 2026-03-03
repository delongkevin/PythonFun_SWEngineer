#pragma once
#ifndef _FOD_ENGINE_H
#define _FOD_ENGINE_H

#include "StateMachine.h"
#include "../algo/common/FODConfig.h"
#include "JobFODInput.h"


namespace fod
{
    // structure to hold event data passed into state machine
    struct FODData : public EventData
    {
    protected:
        /*float32_t IeCANFD2_kph_VehicleSpeedVSOSig;
        fod::ProxiAutonomyLevel_t MePRX_e_AutonomyLvl;
        fod::FODFID_t m_A_FID_FOD_DISABLED;
        fod::FODFID_t m_A_FID_FOD_LIMITED;
        fod::FODFID_t m_A_FID_FOD_DISABLED_SensorBlockage;
        fod::FODFID_t m_A_FID_FOD_LIMITED_SensorBlockage;*/
    };


    // the state machine class
    class FODState : public StateMachine
    {
    public:
        //Constructor
        //FODState() : StateMachine( FOD_SMStatus_t::ST_MAX_STATES ) {}
        FODState();

        //Destructor
        virtual ~FODState() noexcept;

        void UpdateFODStateMachine( const Job_Inputs_t i_FodInput, const FODCONFIGData i_FodConfig, FODHealth_t& o_FodHealth );
        // external events taken by this state machine
        void Halt();
        void Active( FODData* pData );

    private:
        FOD_SMStatus_t FODSMStatus_e;
        bool_t isFaulted;
        bool_t isBlocked;
        bool_t isCANFaulted;
        bool_t isFIDFaulted;
        FODData* FOD_Inputs_Data = new FODData();

        // state machine state functions
        void ST_Idle();
        void ST_Active( const FODData* pData );
        void ST_Fault();

        // state map to define state function order
        BEGIN_STATE_MAP
        STATE_MAP_ENTRY( &FODState::ST_Idle )
        STATE_MAP_ENTRY( &FODState::ST_Active )
        STATE_MAP_ENTRY( &FODState::ST_Fault )
        END_STATE_MAP
    };
}

#endif //_FOD_ENGINE_H