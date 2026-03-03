// ----------------------------------------------------------------------------
// --- Written by Prasanna A [05-Jan-2022]
// --- Last Modified by Prasanna A [05-Jan-2022]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------
#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "TrailerRecognitionState.h"
#include "TADStateMachine.h"
#include <TrailerPresenceDetection.h>


#define PI      (3.1415926535897)

namespace RecognitionState
{
    /*
    * Constructor.
    */
    TrailerRecognitionState::TrailerRecognitionState( const tad2config::TrailerRecognitionConfigData& i_config, const tad2config::TrailerPresenceDetectionConfigData& i_Presenceconfig, TAD2::StateMachine* parent, TAD2::VehicleKinematics* kinematic, TAD2::PreProcessing* i_preProcessing, TAD2::ImageThresholding* i_pImageThresholding, TAD2::FeatureExtraction* i_pFeatureExtraction ) :
        TAD2::State( parent ),
        m_initialized( false ),
        m_config( i_config ),
        m_PresenceConfig( i_Presenceconfig ),
        m_pVehicle( kinematic ),
        m_pPreProcessing( i_preProcessing ),
        m_pImageThresholding( i_pImageThresholding ),
        m_pFeatureExtraction( i_pFeatureExtraction ),
        m_scanningObj()
    {
    }
    /*
    * Destructor.
    */
    TrailerRecognitionState::~TrailerRecognitionState()
    {
    }

    /*
    * Called once when entering this state.
    */
    void TrailerRecognitionState::OnEnter()
    {
        // --- Initialize modules
        if( !m_initialized )
        {
            m_initialized = true;
            m_initialized = m_initialized && m_scanningObj.Init( super->GetWarpedTopViewParams(), m_pPreProcessing );

            if( !m_initialized )
            {
                super->SetError( 2, "Couldn't initialize Trailer Recognition state." );
            }
        }

#if PRINT_CALIBRATED_TRAILER_COUNT
        TAD2::TrailerFeatures Trailer_Features = super->GetTrailerFeatures();
        printf( "\nTAD2: Valid Trailers: " );

        for( uint32_t i = 0; i < TrailerID_t::Trailer_MAX; i++ )
        {
            printf( "[%d]: %d, ", i, Trailer_Features.TrailerData[i].Is_Valid );
        }

        printf( "\n" );
#endif
        TotalRetry = 0;
        super->SetTrailerDetectionComplete( false );
        super->ResetTurnaroundState();
        ScannindInitializationDone = false;
        warpedimage = TAD2::WarpedImage<uint8_t>( super->GetWarpedTopViewParams(), memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );
        warpedEdges = TAD2::WarpedImage<uint8_t>( super->GetWarpedTopViewParams(), memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );
        warpedLabelImage = TAD2::WarpedImage<uint8_t>( super->GetWarpedTopViewParams(), memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );
        iswarpedlabeledImage = memory::MemoryPool::GetImage<bool_t>( itype::IMTP_TopView_U8C1 );
        Trailer_count = 0;
        WarpedImageROI.setX( 0 );
        WarpedImageROI.setY( 0 );
        WarpedImageROI.setHeight( 150 );
        WarpedImageROI.setWidth( 640 );
        // user input for loading trailer
        userinput_loadingtrailer();
    }

    /*
    * Called once when exiting this state.
    */
    void TrailerRecognitionState::OnExit()
    {
        TotalRetry = 0;
        Trailer_count = 0;
        memory::MemoryPool::ReleaseImage( warpedimage );
        memory::MemoryPool::ReleaseImage( warpedEdges );
        memory::MemoryPool::ReleaseImage( warpedLabelImage );
        memory::MemoryPool::ReleaseImage( iswarpedlabeledImage );
    }

    /*
    * Process the given event. Called once per frame during this state.
    *
    * Will return the next state.
    */
    int32_t TrailerRecognitionState::Process( TAD2::Event& e, TAD2::Output& o )
    {
        /*
        *  Name: TrailerRecognitionState
        //DT
        *  Remarks: DD-ID: {68CFC5DF-E84F-4f35-9462-AE3D2B124AE1}
        //BEV
        *  Remarks: DD-ID: {841536BA-54C7-4b21-A7AE-4FDA80AD7767}
        //HD
        *  Remarks: DD-ID: {F39A508D-2483-452a-9DFA-C83A96F0D678}
        */
        TAD2::State::Enum returnState = TAD2::State::TrailerRecognition;
        bool_t ret_val = true;
        // -- Trailer Detection warping
        // --- Warp edges
        //cv::Mat input_img10 = processing::ImageProcessing::ConvertToCV( e.topView );
        TAD2::TrailerFeatures Trailer_Features = super->GetTrailerFeatures();
        bool_t valid = false;

        for( uint32_t i = 0; i < TrailerID_t::Trailer_MAX; i++ )
        {
            valid = valid || Trailer_Features.TrailerData[i].Is_Valid;
        }

        if( !valid || super->CalibrateTrailer() )
        {
            super->SetTrailerPredictionCompleted();

            if( super->GetTrailerPresenceDetectionDone() )
            {
                super->SetTrailerPresenceDetectionDone( false );
                returnState = TAD2::State::Calibration;
            }
            else
            {
                returnState = TAD2::State::TrailerDetection;
            }

            return returnState;
        }

        //m_pPreProcessing->CreateWarpLUTHeader();
        // Getting Trailer Features
        bool_t IterationDone = false;
        float32_t scores;
        bool_t TrailerFound = false;

        if( TrailerFeat.Is_Valid )
        {
#if DUMP_TRAILER_TEMPLATE
            FILE* fp, *fp1;
            static bool_t fileDumped = false;

            if( false == fileDumped )
            {
                fp = fopen( "/ti_sd/after-calib-trailerImage.csv", "a+" );
                fp1 = fopen( "/ti_sd/after-calib-trailerImage.bin", "a+" );
                fwrite( ( void* )TrailerFeat.trailerTemplate.getData(), 1, 203 * 150, fp1 );

                for( uint32_t y = 0; y < TrailerFeat.trailerTemplate.getHeight(); y++ )
                {
                    for( uint32_t x = 0; x < TrailerFeat.trailerTemplate.getWidth(); x++ )
                    {
                        int val = *TrailerFeat.trailerTemplate.at( x, y );
                        fprintf( fp, "%d,", val );
                    }

                    fprintf( fp, "\n" );
                }

                fclose( fp );
                fileDumped = true;
            }

#endif
            //cv::Mat input_img11 = processing::ImageProcessing::ConvertToCV( TrailerFeat.trailerTemplate );
            Point2i hitchPoint = super->GetHitchPoint();
            // --- Warp edges
            m_pPreProcessing->WarpImage( e.topView, warpedEdges, hitchPoint );
            //cv::Mat im2 = processing::ImageProcessing::ConvertToCV( warpedEdges );
            // --- Pre-processing
            m_pPreProcessing->Run( e.frame, warpedEdges, e.roi );
            image::Image<uint8_t> topView = m_pPreProcessing->GetWorkingTopView();
            float32_t averageIllumination = super->FindAverageIllumination( warpedEdges, e.roi );
            super->Set_averageillumination( averageIllumination );
            //cv::Mat im3 = processing::ImageProcessing::ConvertToCV( topView );
            //
            // --- Edge Detection
            image::Image<uint16_t> lowThresh = memory::MemoryPool::GetImage<uint16_t>( itype::IMTP_TopView_U16C1 );
            image::Image<uint16_t> highThresh = memory::MemoryPool::GetImage<uint16_t>( itype::IMTP_TopView_U16C1 );
            image::Image<uint16_t> gradMag = memory::MemoryPool::GetImage<uint16_t>( itype::IMTP_TopView_U16C1 );
            image::Image<uint8_t> gradDir = memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 );
            //
            bool_t warpedimg = true;
            m_pImageThresholding->Run( e.frame, topView, e.roi, hitchPoint, e.currentTrailerAngle_deg, e.trailerAngleKnown, lowThresh, highThresh, gradMag, gradDir, false, warpedimg );
            m_pFeatureExtraction->Run( e.frame, topView, lowThresh, highThresh, e.roi, gradMag, gradDir );
            image::Image<uint8_t>& edges = m_pFeatureExtraction->GetEdges();
            //cv::Mat im4 = processing::ImageProcessing::ConvertToCV( edges );
            memcpy( warpedEdges.getData(), edges.getData(), global::WARPED_TOPVIEW_IMAGE_HEIGHT * global::WARPED_TOPVIEW_IMAGE_WIDTH );
            //
            memory::MemoryPool::ReleaseImage( lowThresh );
            memory::MemoryPool::ReleaseImage( highThresh );
            memory::MemoryPool::ReleaseImage( gradMag );
            memory::MemoryPool::ReleaseImage( gradDir );
            //cv::Mat input_img2 = processing::ImageProcessing::ConvertToCV( warpedEdges );
            // applying connected components
            _roi::ROI ImageROI;
            ImageROI.setX( e.roi.getX() + 3 );
            ImageROI.setY( e.roi.getY() + 3 );
            ImageROI.setHeight( warpedEdges.getHeight() - 6 );
            ImageROI.setWidth( e.roi.getWidth() - 6 );
            float32_t thresh = m_scanningObj.LabelComponent( &warpedEdges, &warpedLabelImage, ImageROI, &iswarpedlabeledImage, true );
            //
#ifdef DIAGNOSTICS
            db::imshow( "(TAD 1) Warped Edges", edges, db::ImShow_Binary );
#endif
            TrailerFound = true;

            if( !ScannindInitializationDone )
            {
                ScannindInitializationDone = true;
                bool_t result = m_scanningObj.Start( TrailerFeat.trailerTemplate );
                //cv::Mat im = processing::ImageProcessing::ConvertToCV( TrailerFeat.trailerTemplate );

                if( !result )
                {
                    super->SetError( 1, "Couldn't start Scanning state." );
                }
            }

            // --- Run scan
            m_scanningObj.Run( e.frame, warpedEdges, m_pImageThresholding->_getotsuthresh(), averageIllumination );
            scores = m_scanningObj.GetScore();

            if( ( ( scores > m_config.getthreshold() ) || !m_config.getEnabled() ) && m_scanningObj.IsTrailerAngleFound() )
            {
                o.detectedAngle_deg = m_scanningObj.GetTrailerAngle();
                o.detectedAngleValid = true;
                o.detectedHitchPoint = TrailerFeat.hitchPoint;
                o.detectedhitchlength = TrailerFeat.HitchLength;
                o.detectedHitchPointValid = true;
                o.detectedBeamLengthValid = true;
                o.detectedBeamLength = TrailerFeat.BeamLength;
                o.detectedJacknifeAngle = TrailerFeat.JacknifeAngle;
                o.detectedJacknifeThreshAngle = TrailerFeat.JacknifeThreshAngle;
                super->SetScanningScore( scores );
                super->SetTrailerTemplatefeatures( TrailerFeat );
                super->SetTrailerUsedCount( Trailer_count );
                //
                super->SetTrailerCalibrated();
                super->SetTrailerPredictionCompleted();
                super->SetHitchCalibrated();
                TrailerID_t TrailerID = GetTrailerID( Trailer_count );
                super->SetCurrentTraielrID( TrailerID );
                m_scanningObj.Finish();
                super->SetTrailerPresenceDetectionDone( false );
                returnState = TAD2::State::AngleDetection;
                Trailer_count = 0;
            }
        }
        else
        {
            TotalRetry++;

            if( TotalRetry >= m_config.getNoOfRetry() )
            {
                super->SetTrailerPredictionCompleted();

                if( super->GetTrailerPresenceDetectionDone() )
                {
                    super->SetTrailerPresenceDetectionDone( false );
                    returnState = TAD2::State::Calibration;
                }
                else
                {
                    returnState = TAD2::State::TrailerDetection;
                }
            }

            IterationDone = true;
            Trailer_count = 0;
        }

        if( m_scanningObj.IsScanningComplete() || !TrailerFound )
        {
            m_scanningObj.Finish();
            ScannindInitializationDone = false;

            if( !IterationDone )
            {
                Trailer_count++;
            }

            bool_t TrailerLoadedSuccessfully = false;
            TrailerFeat = GetTrailerFeatureCalibration( Trailer_count, TrailerLoadedSuccessfully );

            if( TrailerFeat.Is_Valid )
            {
                super->SetTempHitchPos( TrailerFeat.hitchPoint, true );
            }
            else
            {
                super->SetTempHitchPos( super->Get_hitch_Config_Point(), false );
            }
        }

        if( Trailer_count >= TrailerID_t::Trailer_MAX )
        {
            TotalRetry++;

            if( TotalRetry >= m_config.getNoOfRetry() )
            {
                super->SetTrailerPredictionCompleted();

                if( super->GetTrailerPresenceDetectionDone() )
                {
                    super->SetTrailerPresenceDetectionDone( false );
                    returnState = TAD2::State::Calibration;
                }
                else
                {
                    returnState = TAD2::State::TrailerDetection;
                }
            }

            Trailer_count = 0;
        }

        return returnState;
    }
    /*
    * userinput_loadingtrailer
    */
    void TrailerRecognitionState::userinput_loadingtrailer()
    {
        bool_t trailerLoadedSuccessfully = false;
        TrailerFeat.Is_Valid = false;

        if( !m_config.getEnabled() )
        {
            if( super->GetConfigTrailerID() == -1 )
            {
                TrailerFeat = GetTrailerFeatureCalibration( super->GetInputTrailerID(), trailerLoadedSuccessfully );
                super->SetTempHitchPos( TrailerFeat.hitchPoint, true );

                if( trailerLoadedSuccessfully )
                {
                    Trailer_count = super->GetInputTrailerID();
                }
            }
            else
            {
                TrailerFeat = GetTrailerFeatureCalibration( super->GetConfigTrailerID(), trailerLoadedSuccessfully );
                super->SetTempHitchPos( TrailerFeat.hitchPoint, true );

                if( trailerLoadedSuccessfully )
                {
                    Trailer_count = super->GetInputTrailerID();
                }
            }
        }
        else
        {
            TrailerFeat = GetTrailerFeatureCalibration( Trailer_count, trailerLoadedSuccessfully );

            if( TrailerFeat.Is_Valid )
            {
                super->SetTempHitchPos( TrailerFeat.hitchPoint, true );
            }
            else
            {
                super->SetTempHitchPos( super->Get_hitch_Config_Point(), false );
            }
        }
    }
    /*
    * Get the TrailerFeatureCalibration
    */
    TAD2::TrailerFeatures::Trailers TrailerRecognitionState::GetTrailerFeatureCalibration( uint32_t i_trailerCount, bool_t& trailerLoadedSuccessfully )
    {
        TAD2::TrailerFeatures Trailer_Features = super->GetTrailerFeatures();
        TAD2::TrailerFeatures::Trailers EmptyTrailer;
        bool_t valid = Trailer_Features.TrailerData[i_trailerCount].Is_Valid;

        if( ( i_trailerCount < TrailerID_t::Trailer_MAX ) && valid )
        {
            trailerLoadedSuccessfully = true;
            return Trailer_Features.TrailerData[i_trailerCount];
        }
        else
        {
            EmptyTrailer.Is_Valid = false;
            trailerLoadedSuccessfully = false;
            return EmptyTrailer;
        }
    }
    /*
    * Get the Trailer ID
    */
    TrailerID_t TrailerRecognitionState::GetTrailerID( uint32_t i_trailerCount )
    {
        if( i_trailerCount == 0 )
        {
            return TrailerID_t::Trailer_ID1;
        }
        else if( i_trailerCount == 1 )
        {
            return TrailerID_t::Trailer_ID2;
        }
        else if( i_trailerCount == 2 )
        {
            return TrailerID_t::Trailer_ID3;
        }
        else if( i_trailerCount == 3 )
        {
            return TrailerID_t::Trailer_ID4;
        }
        else if( i_trailerCount == 4 )
        {
            return TrailerID_t::Trailer_ID5;
        }
        // else if( i_trailerCount == 5 )
        // {
        //     return TrailerID_t::Trailer_ID6;
        // }
        else
        {
            return TrailerID_t::Trailer_MAX;
        }
    }
    /*
    * Get the enum for this state.
    */
    int32_t TrailerRecognitionState::GetEnum()
    {
        return TeTRSC_e_TADState::TeTRSC_e_TADState_TrailerRecognition;
    }
}
