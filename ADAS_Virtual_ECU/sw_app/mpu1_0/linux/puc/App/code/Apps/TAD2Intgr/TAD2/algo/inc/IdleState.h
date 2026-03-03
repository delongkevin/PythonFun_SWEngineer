// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [12-Jul-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __IDLE_STATE_H
#define __IDLE_STATE_H

#ifdef __QNX__
    #include "../common/TADStateTypes.h"
#else
    #include "common/TADStateTypes.h"
#endif
#include "VehicleKinematics.h"

/** Idle state. Part of the TAD state machine. **/
namespace Idle
{
    class IdleState : public TAD2::State
    {
    public:
        explicit IdleState( TAD2::StateMachine* parent, TAD2::VehicleKinematics* kinematic );
        virtual ~IdleState();

        virtual int32_t Process( TAD2::Event& e, TAD2::Output& o ) override;
        virtual void OnEnter() override;
        virtual void OnExit() override;
        virtual int32_t GetEnum() override;

    private:
        // --- Top-level modules required by this state
        TAD2::VehicleKinematics* m_pVehicle;
        bool_t m_InitializationDone = false;
        int32_t last_geardir;

    };
}

#endif // !__IDLE_STATE_H

