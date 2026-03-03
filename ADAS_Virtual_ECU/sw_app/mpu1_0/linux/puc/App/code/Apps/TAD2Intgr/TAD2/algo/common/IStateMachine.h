#ifndef __I_STATE_MACHINE_H
#define __I_STATE_MACHINE_H

#include "IState.h"

/**
* State machine interface.
*/
template<class this_type, class event_type, class output_type>
class IStateMachine
{
public:
    IStateMachine();
    virtual ~IStateMachine();

    void Start1( int entryState );
    void Stop1();
    void ProcessEvent( event_type& e );


protected:
    // Pointer to the current state.
    IState<this_type, event_type, output_type>* m_state;

    // Map integer number to a state.
    virtual IState<this_type, event_type, output_type>* StateMap( int i ) = 0;
    // Process the output from a state
    virtual void ProcessOutput( output_type& o ) = 0;

};

//------------------------------------------------------------------------------
// IStateMachine concrete function definitions.
//------------------------------------------------------------------------------

/**
* Constructor
*/
template<class this_type, class event_type, class output_type>
inline IStateMachine<this_type, event_type, output_type>::IStateMachine() :
    m_state( nullptr )
{
}

/**
* Destructor
*/
template<class this_type, class event_type, class output_type>
inline IStateMachine<this_type, event_type, output_type>::~IStateMachine()
{
}

/**
* Start the state machine.
*/
template<class this_type, class event_type, class output_type>
inline void IStateMachine<this_type, event_type, output_type>::Start1( int entryState )
{
    m_state = StateMap( entryState );

    if( m_state == nullptr )
    {
        return;
    }

    m_state->OnEnter();
}

/**
* Stop the state machine.
*/
template<class this_type, class event_type, class output_type>
inline void IStateMachine<this_type, event_type, output_type>::Stop1()
{
    if( m_state != nullptr )
    {
        m_state->OnExit();
        //delete m_state;
        m_state = nullptr;
    }
}

/**
* Process the given event and return the next state.
*/
template<class this_type, class event_type, class output_type>
inline void IStateMachine<this_type, event_type, output_type>::ProcessEvent( event_type& e )
{
    if( m_state == nullptr )
    {
        return;
    }

    output_type o;
    int nextState = m_state->Process( e, o );
    ProcessOutput( o );

    if( nextState != m_state->GetEnum() )
    {
        m_state->OnExit();
        //delete m_state;
        m_state = StateMap( nextState );

        if( m_state )
        {
            m_state->OnEnter();
        }
    }

    return;
}

#endif // !__I_STATE_MACHINE_H
