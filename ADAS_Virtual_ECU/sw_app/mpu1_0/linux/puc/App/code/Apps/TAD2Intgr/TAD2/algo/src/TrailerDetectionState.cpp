// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [12-Jul-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "TrailerDetectionState.h"
#include "TADStateMachine.h"
#include "common/config.h"


namespace TrailerState
{
    /*
    * Constructor.
    */
    TrailerDetectionState::TrailerDetectionState( const tad2config::TrailerPresenceDetectionConfigData& i_config, TAD2::StateMachine* parent, TAD2::VehicleKinematics* kinematic, TAD2::PreProcessing* i_preProcessing, TAD2::ImageThresholding* i_pImageThresholding, TAD2::FeatureExtraction* i_pFeatureExtraction ) :
        TAD2::State( parent ),
        m_config( i_config ),
        m_initialized( false ),
        speed_threshold( 0.833f ),
        m_trailerPresenceDetectionObj( i_preProcessing, kinematic ),
        m_pVehicle( kinematic ),
        m_pPreProcessing( i_preProcessing ),
        m_pImageThresholding( i_pImageThresholding ),
        m_pFeatureExtraction( i_pFeatureExtraction )
    {
    }

    /*
    * Destructor.
    */
    TrailerDetectionState::~TrailerDetectionState()
    {
    }

    /*
    * Process the given event. Called once per frame during this state.
    *
    * Will return the next state.
    */
    int32_t TrailerDetectionState::Process( TAD2::Event& e, TAD2::Output& o )
    {
        /*
        *  Name: TrailerDetectionState
        //DT
        *  Remarks: DD-ID: {74C633DB-924D-4cfe-8535-9EE449D0FB40}
        //BEV
        *  Remarks: DD-ID: {B45BE94E-D06C-4212-8625-8F10859F8628}
        //HD
        *  Remarks: DD-ID: {F39A508D-2483-452a-9DFA-C83A96F0D678}
        */
        State::Enum returnState = State::TrailerDetection;
        //checking vehicle is driving straight
        bool_t VehicleStraight = true;
        float32_t wheelAngle = abs( m_pVehicle->wheelAngle_deg() );
        float32_t RateofChange = abs( wheelAngle - PreviousWheelAngle );

        if( ( wheelAngle > 20.0f ) || ( RateofChange > 2.0f ) )
        {
            VehicleStraight = false;
        }

        if( ( returnState == State::TrailerDetection ) && VehicleStraight && ( m_pVehicle->gearDir() == TAD2::GearForward ) ) // 1 - gear forward
        {
            m_trailerPresenceDetectionObj.Run( e.frame, e.topView, Point2i( 320, super->GetbumperPos() ), e.roi );
        }

        PreviousWheelAngle = wheelAngle;

        if( m_trailerPresenceDetectionObj.IsComplete() )
        {
            super->SetTrailerDetectionComplete( true );
            super->SetTrailerDetected( m_trailerPresenceDetectionObj.IsTrailerPresent() );
            o.detectedAbsencePresenceValid = true;

            if( m_trailerPresenceDetectionObj.IsTrailerPresent() )
            {
                o.Trailer_Present = true;
                super->SetTrailerPresenceDetectionDone( true );
                returnState = State::TrailerRecognition;
            }
            else
            {
                fail_count++;
                m_trailerPresenceDetectionObj.Finish();
                // --- Start modules
                bool_t result = m_trailerPresenceDetectionObj.Start();

                if( !result )
                {
                    super->SetError( 1, "Couldn't start Trailer Detection state." );
                }

                if( ( fail_count > m_config.getNoOfRetry() ) && ( m_pVehicle->wheelAngle_deg() < 10.0f ) )
                {
                    o.Trailer_Present = false;
                    returnState = State::Idle;
                }
            }
        }

        return returnState;
    }

    /*
    * Called once when entering this state.
    */
    void TrailerDetectionState::OnEnter()
    {
        // --- Initialize modules
        if( !m_initialized )
        {
            m_initialized = true;
            m_initialized = m_initialized && m_trailerPresenceDetectionObj.Init( m_config, super->GetWarpedTopViewParams() );

            if( !m_initialized )
            {
                super->SetError( 2, "Couldn't initialize Trailer Detection state." );
            }
        }

        PreviousWheelAngle = 0.0f;
        super->SetTrailerPresenceDetectionDone( false );
        fail_count = 0;
        // --- Start modules
        bool_t result = m_trailerPresenceDetectionObj.Start();

        if( !result )
        {
            super->SetError( 1, "Couldn't start Trailer Detection state." );
        }
    }

    /*
    * Called once when exiting this state.
    */
    void TrailerDetectionState::OnExit()
    {
        m_trailerPresenceDetectionObj.Finish();
    }

    /*
    * Get the enum for this state.
    */
    int32_t TrailerDetectionState::GetEnum()
    {
        return TeTRSC_e_TADState::TeTRSC_e_TADState_TrailerDetection;
    }
}
