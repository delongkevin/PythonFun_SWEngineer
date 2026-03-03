// ----------------------------------------------------------------------------
// --- Written by Prasanna Ananthakrishnan [06-Mar-2020]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "stdtad.h"
#ifdef __QNX__
    #include "mecl/math/Math.h"
#else
    #include "mecl/math/math.h"
#endif
#include "CollisionAngleDetection.h"
#include "TADStructures.h"
#ifdef DIAGNOSTICS
    #include "global.h"
    #include "db.h"
    #include "fo.h"
#endif
/*
* Constructor.
*/
cAngleDetection::CollisionAngleDetection::CollisionAngleDetection() :
    m_initOK( false ),
    m_isRunning( false ),
    m_lastFrameRun( 0 )
{
    for( uint32_t Itr_u32 = 0; Itr_u32 < 640; ++Itr_u32 )
    {
        vertical_profile[Itr_u32] = 0;
    }
}

/*
* Destructor.
*/
cAngleDetection::CollisionAngleDetection::~CollisionAngleDetection()
{
}

/*
* Initialize this module.
*
* Called once at the beginning of the program, before any other functions.
*/
bool_t cAngleDetection::CollisionAngleDetection::Init( const TAD2::WarpedTopViewParameters& i_warpedTopviewParams )
{
    m_warpedTopviewParams = i_warpedTopviewParams;
    m_collisionangle = 0.0f;
    m_initOK = true;
    return true;
}

/*
* Signifies the beginning of a period of execution. Allocates any necessary
* memory and sets any input parameters needed at runtime.
*/
bool_t cAngleDetection::CollisionAngleDetection::Start()
{
    bool_t ret_val = true;

    if( !m_initOK )
    {
        ret_val = false;
    }

    if( ret_val )
    {
        m_lastFrameRun = 0;
        nCountOfImage = 0;
        final_edge_img = TAD2::WarpedImage<uint8_t>( m_warpedTopviewParams, memory::MemoryPool::GetImage<uint8_t>( itype::IMTP_TopView_U8C1 ) );
        initializeBuffer( final_edge_img, 0 );
        collision_angle_estimatin_done = false;

        for( uint32_t i = 0; i < 640; i++ )
        {
            vertical_profile[i] = 0;
        }

        m_isRunning = true;
        ret_val = true;
    }

    return ret_val;
}

/*
* Signifies the end of a period of execution. Deallocates any memory used.
*/
void cAngleDetection::CollisionAngleDetection::Finish()
{
    m_isRunning = false;
    memory::MemoryPool::ReleaseImage( final_edge_img );
}

/*
* Run this module. First state.
*
* Will only run if called between a call to Start() and a call to Finish(), respectively.
* Records the given frame so as to not run the same frame multiple times.
*/
void cAngleDetection::CollisionAngleDetection::Run( uint32_t i_frame, image::Image<uint8_t>& i_edges, uint16_t othsuthresh, Point2i hitch_point )
{
    bool_t ret_val = true;

    if( !m_initOK )
    {
        ret_val = false;
    }

    if( ( !m_isRunning ) || ( i_frame == m_lastFrameRun ) )
    {
        ret_val = false;
    }

    if( collision_angle_estimatin_done )
    {
        ret_val = false;
    }

    if( ret_val )
    {
        if( ( m_lastFrameRun + 1 ) != ( i_frame ) )
        {
            nCountOfImage = 0;
            initializeBuffer( final_edge_img, 0 );
        }

        hitch_pos = hitch_point;
        nCountOfImage++;
        add_image( i_edges, final_edge_img, 3 * othsuthresh );

        if( nCountOfImage == 30 )
        {
            uint32_t max_val = 0;
            max_value_in_a_image( final_edge_img, max_val );
            binarization_new( final_edge_img, static_cast<uint32_t>( ( static_cast<float32_t>( max_val ) * 0.20 ) ) );
            vertical_edge_profile( final_edge_img );
            m_collisionangle = find_collision_point();
        }

        m_lastFrameRun = i_frame;
    }

    return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Fn_Name  : find_collision_point
//Fn_Work :  find the collision point of the trailer
//Fn_Return : void
//Fn_Input : input array
/////////////////////////////////////////////////////////////////////////////////////////////////////////
float32_t cAngleDetection::CollisionAngleDetection::find_collision_point()
{
    float32_t ret_val;
    uint32_t right_side_count = 0;
    uint32_t left_side_count = 0;
    uint32_t start_pos = 0;
    uint32_t end_pos = 0;
    bool_t start_pos_found = false;
    // ++ find max val
    uint32_t max_val = vertical_profile[0];

    for( uint32_t i = 0; i < 640; i++ )
    {
        if( max_val < vertical_profile[i] )
        {
            max_val = vertical_profile[i];
        }
    }

    for( uint32_t i = 0; i < 640; i++ )
    {
        if( static_cast<float32_t>( vertical_profile[i] ) > round( static_cast<float32_t>( max_val ) * 0.25 ) )
        {
            end_pos = i;

            if( !start_pos_found )
            {
                start_pos_found = true;
                start_pos = end_pos;
            }
        }
    }

    for( uint32_t i = start_pos; i < end_pos; i++ )
    {
        if( static_cast<int32_t>( i ) < hitch_pos.x )
        {
            left_side_count = left_side_count + vertical_profile[i];
        }
        else
        {
            right_side_count = right_side_count + vertical_profile[i];
        }
    }

    collision_angle_estimatin_done = true;
    float32_t left_angle = mecl::math::abs_x( TAD2::WarpedImage<uint8_t>( m_warpedTopviewParams ).XPos2Angle( static_cast<float32_t>( start_pos ) ) - 90.0f );
    float32_t right_angle = mecl::math::abs_x( TAD2::WarpedImage<uint8_t>( m_warpedTopviewParams ).XPos2Angle( static_cast<float32_t>( end_pos ) ) - 90.0f );
    m_leftcollisionangle = mecl::math::abs_x( 90.0f - left_angle );
    m_rightcollisionangle = mecl::math::abs_x( 90.0f - right_angle );

    if( m_leftcollisionangle > m_rightcollisionangle )
    {
        ret_val = m_leftcollisionangle;
    }
    else
    {
        ret_val = m_rightcollisionangle;
    }

    return ret_val;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Fn_Name  : binarization
//Fn_Work : applying binarization to the image
//Fn_Return : void
//Fn_Input : input image, threshold, output image
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void cAngleDetection::CollisionAngleDetection::binarization_new( image::Image<uint8_t>& outputArr, uint32_t thresh )const
{
    if( !outputArr.isContinuous() )
    {
        assert( 0 );
    }

    uint32_t img_width = outputArr.getWidth();
    uint32_t deltaX = mecl::math::abs_x( 0 - 150 );
    uint32_t deltaY = mecl::math::abs_x( hitch_pos.x - 160 );
    float32_t error = 0;
    // Note the below fails for completely vertical lines.
    uint32_t deltaError = deltaY / deltaX;
    uint32_t y = hitch_pos.x;
    uint32_t y_1 = hitch_pos.x;

    for( uint32_t x = 0; x < 150; x++ )
    {
        error = error + static_cast<float32_t>( deltaError );

        for( uint32_t Y = 0; Y < img_width; Y++ )
        {
            uint32_t pixel = static_cast<uint32_t>( *outputArr.at( Y, x ) );

            if( ( pixel > thresh ) && ( Y > y ) && ( Y < y_1 ) )
            {
                *outputArr.at( Y, x ) = 1; // change in to 255 for writing the binary image
            }
            else
            {
                *outputArr.at( Y, x ) = 0;
            }
        }

        if( error >= 0.5 )
        {
            --y;
            ++y_1;
            error -= 1.0;
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Fn_Name  : binarization
//Fn_Work : applying binarization to the image
//Fn_Return : void
//Fn_Input : input image, threshold, output image
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void cAngleDetection::CollisionAngleDetection::binarization( image::Image<uint8_t>& outputArr, uint32_t thresh )
{
    if( !outputArr.isContinuous() )
    {
        assert( 0 );
    }

    uint32_t img_height = outputArr.getHeight();
    uint32_t img_width = outputArr.getWidth();

    for( uint32_t i = 0; i < ( img_width * img_height ); i++ )
    {
        uint32_t pixel = static_cast<uint32_t>( outputArr.getData()[i] ); //PRQA S 3706

        if( pixel > thresh )
        {
            outputArr.setDataI( 1, 0 );  /* PRQA S 3706*/ // change in to 255 for writing the binary image
        }
        else
        {
            outputArr.setDataI( 0, i ); /* PRQA S 3706*/
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Fn_Name  : add_image
//Fn_Work :  adding matrix with another one
//Fn_Return : void
//Fn_Input : input array, output image
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void cAngleDetection::CollisionAngleDetection::add_image( image::Image<uint8_t>& inputArr, image::Image<uint8_t>& outputArr, uint16_t othsuthresh )
{
    uint32_t nRows = outputArr.getHeight();
    uint32_t nCols = outputArr.getWidth();

    for( uint32_t row = 50; row < nRows; row++ )
    {
        for( uint32_t col = 160; col < ( nCols - 160 ); col++ )
        {
            if( ( *inputArr.at( col, row ) ) > othsuthresh )
            {
                *outputArr.at( col, row ) += 1;
            }
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Fn_Name  : initializeBuffer
//Fn_Work : initialize the image with zero
//Fn_Return : void
//Fn_Input :  input image, initializing value
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void cAngleDetection::CollisionAngleDetection::initializeBuffer( image::Image<uint8_t>& input_image, uint8_t val )
{
    uint32_t total_row = input_image.getHeight();
    uint32_t total_col = input_image.getWidth();

    for( uint32_t row = 0; row < total_row; row++ )
    {
        for( uint32_t col = 0; col < total_col; col++ )
        {
            *input_image.at( col, row ) = val;
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Fn_Name  : max_value_in_a_array
//Fn_Work :  find the maximum value in a array up to the index which are given and return the maximum value and its index
//Fn_Return : void
//Fn_Input : input array, start of index, up to index which needs to be processed, maximum value, maximum index
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void cAngleDetection::CollisionAngleDetection::max_value_in_a_image( image::Image<uint8_t>& inputArr, uint32_t& max_value )
{
    float32_t max_pixel = 0;
    max_value = static_cast<uint32_t>( max_pixel );

    for( uint32_t row = 0; row < inputArr.getHeight(); row++ ) // considering only 300 row for profiling
    {
        for( uint32_t col = 0; col < inputArr.getWidth(); col++ )
        {
            if( max_pixel < static_cast<float32_t>( *inputArr.at( col, row ) ) )
            {
                max_pixel = static_cast<float32_t>( *inputArr.at( col, row ) );
                max_value = static_cast<uint32_t>( max_pixel );
            }
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Fn_Name  : edge vertical profile
//Fn_Work :  sum all the values with respect to columns
//Fn_Return : void
//Fn_Input : input array, output array
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void cAngleDetection::CollisionAngleDetection::vertical_edge_profile( image::Image<uint8_t> inputArr )
{
    if( !inputArr.isContinuous() )
    {
        assert( 0 );
    }

    for( uint32_t row = 0; row < inputArr.getHeight(); row++ )
    {
        for( uint32_t col = 0; col < inputArr.getWidth(); col++ )
        {
            vertical_profile[col] += *inputArr.at( col, row );
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Fn_Work :   Return whether or not the this module is running
/////////////////////////////////////////////////////////////////////////////////////////////////////////
bool_t cAngleDetection::CollisionAngleDetection::IsRunning()const
{
    return m_isRunning;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Fn_Work :   Return whether or not the collision angle has been found
/////////////////////////////////////////////////////////////////////////////////////////////////////////
bool_t cAngleDetection::CollisionAngleDetection::IsCollisionAngleFound()const
{
    return collision_angle_estimatin_done;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Fn_Work :   Get the collision angle
/////////////////////////////////////////////////////////////////////////////////////////////////////////
float32_t cAngleDetection::CollisionAngleDetection::GetCollisionAngle()const
{
    return m_collisionangle;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Fn_Work :   Get the left collision angle
/////////////////////////////////////////////////////////////////////////////////////////////////////////
float32_t cAngleDetection::CollisionAngleDetection::GetLeftCollisionAngle()const
{
    return m_leftcollisionangle;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Fn_Work :   Get the Right collision angle
/////////////////////////////////////////////////////////////////////////////////////////////////////////
float32_t cAngleDetection::CollisionAngleDetection::GetRightCollisionAngle()const
{
    return m_rightcollisionangle;
}
