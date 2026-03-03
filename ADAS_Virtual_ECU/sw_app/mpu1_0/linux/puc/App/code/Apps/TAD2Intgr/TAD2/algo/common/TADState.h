// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [06-Mar-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __TAD_STATE_H
#define __TAD_STATE_H

#include "stdint.h"

namespace TAD2
{
    /**
    * TAD State interface.
    */
    template<class parent_type, class event_type, class output_type>
    class TADState
    {
    public:
        explicit TADState( parent_type* parent );
        virtual ~TADState();

        // Process this state.
        virtual int32_t Process( event_type& e, output_type& o ) = 0;

        // Enter this state. Called once each time this state is entered.
        virtual void OnEnter() = 0;

        // Exit this state. Called once each time this state is exited.
        virtual void OnExit() = 0;

        // Get the integer value referring to this state.
        virtual int32_t GetEnum() = 0;

    protected:
        // Pointer to the state machine this state is a part of.
        parent_type* super;

    };


    //------------------------------------------------------------------------------
    // TADState concrete function definitions.
    //------------------------------------------------------------------------------

    /**
    * Constructor.
    */
    template<class parent_type, class event_type, class output_type>
    inline TADState<parent_type, event_type, output_type>::TADState( parent_type* parent ) :
        super( parent )
    {
    }

    /**
    * Destructor.
    */
    template<class parent_type, class event_type, class output_type>
    inline TADState<parent_type, event_type, output_type>::~TADState()
    {
    }

}
#endif // !__TAD_STATE_H
