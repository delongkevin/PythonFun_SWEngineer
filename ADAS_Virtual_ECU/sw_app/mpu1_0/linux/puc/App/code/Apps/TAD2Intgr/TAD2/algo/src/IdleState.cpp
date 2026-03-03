// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [12-Jul-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "stdtad.h"
#include "IdleState.h"

namespace Idle
{
    /*
    * Constructor.
    */
    IdleState::IdleState( TAD2::StateMachine* parent, TAD2::VehicleKinematics* kinematic ) :
        TAD2::State( parent ),
        m_pVehicle( kinematic )
    {
    }

    /*
    * Destructor.
    */
    IdleState::~IdleState()
    {
    }

    /*
    * Process the given event. Called once per frame during this state.
    *
    * Will return the next state.
    */
    int32_t IdleState::Process( TAD2::Event& e, TAD2::Output& o )
    {
        TAD2::State::Enum returnState = TAD2::State::Idle;
        int32_t gear_dir = m_pVehicle->gearDir();

        if( !m_InitializationDone )
        {
            m_InitializationDone = true;
            last_geardir = gear_dir;
        }

        if( last_geardir != gear_dir )
        {
            returnState = State::TrailerRecognition;
        }
        else
        {
            // --- Do nothing!
            returnState = State::Idle;
        }

        last_geardir = gear_dir;
        return returnState;
    }

    /*
    * Called once when entering this state.
    */
    void IdleState::OnEnter()
    {
        m_InitializationDone = false;
    }

    /*
    * Called once when exiting this state.
    */
    void IdleState::OnExit()
    {
    }

    /*
    * Get the enum for this state.
    */
    int32_t IdleState::GetEnum()
    {
        return TeTRSC_e_TADState::TeTRSC_e_TADState_Idle;
    }
}
