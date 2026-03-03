// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [08-Feb-2019]
// --- Last Modified by Joshua Teichroeb [12-Mar-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "TADStructures.h"
#ifdef _WINDOWS_
    #include "common/TRSC_Inputs_Outputs.h"
#else
    #include "TRSC_Inputs_Outputs.h"
#endif

///------------------------------------------------------------------------------
/// TrailerParameters function definitions.
///------------------------------------------------------------------------------

/*
* Constructor.
*/
TAD2::TrailerParameters::TrailerParameters( float32_t i_beamLength_mm, float32_t i_width_mm, float32_t i_frontOverhang_mm ) :
    beamLength_mm( i_beamLength_mm ),
    width_mm( i_width_mm ),
    frontOverhang_mm( i_frontOverhang_mm )
{
}

TAD2::TrailerParameters::TrailerParameters() :
    beamLength_mm( 0.0f ),
    width_mm( 0.0f ),
    frontOverhang_mm( 0.0f )
{
}

///------------------------------------------------------------------------------
/// WarpedTopViewParameters function definitions.
///------------------------------------------------------------------------------

/*
* To accurately compare floating points numbers
*/
bool TAD2::_isEqual( float64_t a, float64_t b )
{
    float64_t epsilon = std::numeric_limits<float64_t>::epsilon();
    float64_t scale = ( fabs( a ) + fabs( b ) ) / 2.0;
    return ( fabs( a - b ) ) <= ( epsilon * scale );
}
/*
* Compare with other WarpedTopViewParameters object.
*/
bool_t TAD2::WarpedTopViewParameters::operator==( const WarpedTopViewParameters& other ) const
{
    //PRQA S 3270 ++
    //confirming identical objects so float comparison is fine
    return ( ( width == other.width ) &&
             ( height == other.height ) &&
             ( yOffset == other.yOffset ) &&
             ( _isEqual( start_deg, other.start_deg ) ) &&
             ( _isEqual( range_deg, other.range_deg ) ) &&
             ( _isEqual( degreesPerPixel, other.degreesPerPixel ) ) );
    //PRQA S 3270 --
}

///------------------------------------------------------------------------------
/// TrailerTemplate function definitions.
///------------------------------------------------------------------------------

/**
* Shallow copy to an Image.
*/
void TAD2::TrailerTemplate::operator=( const Image<uint8_t>& other )
{
    Image<uint8_t>::operator=( other );
}

/**
* Get the number of bytes required to store this Features.
*/
uint32_t TAD2::TrailerFeatures::GetFeatureStorageSize() const
{
    uint32_t size = 0;

    for( uint32_t i = 0; i < TrailerID_e::Trailer_MAX; i++ )
    {
        size += sizeof( bool_t );
        size += sizeof( uint32_t );
        size += sizeof( uint32_t );
        size += sizeof( uint8_t ) * TrailerData[i].trailerTemplate.getWidth() * TrailerData[i].trailerTemplate.getHeight();
        size += sizeof( TrailerID_e );
        size += sizeof( int32_t );
        size += sizeof( bool_t );
        size += sizeof( int32_t );
        size += sizeof( int32_t );
        size += sizeof( uint32_t );
        size += sizeof( bool_t );
        size += sizeof( uint32_t );
        size += sizeof( bool_t );
        size += sizeof( float32_t );
        size += sizeof( uint32_t );
        size += sizeof( uint32_t );
    }

    return size;
}
/**
* Read just the Template size from the given buffer as if it were a serialized TrailerFeatures.
*/
uint32_t TAD2::TrailerFeatures::ReadFeatureTemplateSize( uint8_t* buffer )
{
    uint32_t tc_ret;
    uint8_t* buf_ptr = buffer;
    uint32_t l_versionNum = 0;
    memcpy( &l_versionNum, buf_ptr, sizeof( l_versionNum ) );
    buf_ptr += sizeof( uint32_t );
    bool_t v_FeatureImageValid;
    memcpy( &v_FeatureImageValid, buf_ptr, sizeof( bool_t ) );
    buf_ptr += sizeof( bool_t );

    if( !v_FeatureImageValid )
    {
        tc_ret = 0;
    }
    else
    {
        uint32_t width;
        uint32_t height;
        memcpy( &width, buf_ptr, sizeof( uint32_t ) );
        buf_ptr += sizeof( uint32_t );
        memcpy( &height, buf_ptr, sizeof( uint32_t ) );
        buf_ptr += sizeof( uint32_t );
        tc_ret = width * height;
    }

    return tc_ret;
}
/**
* Serialize this calibration.
*/
void TAD2::TrailerFeatures::SerializeFeature( uint8_t* buffer ) const
{
    uint8_t* buf_ptr = buffer;
    const uint32_t l_versionNum = 7000100;
    memcpy( buf_ptr, &l_versionNum, sizeof( l_versionNum ) );
    buf_ptr += sizeof( uint32_t );

    // ++++ Trailer Data
    for( uint32_t i = 0; i < TrailerID_e::Trailer_MAX; i++ )
    {
        memcpy( buf_ptr, &TrailerData[i].Is_Valid, sizeof( bool_t ) );
        buf_ptr += sizeof( bool_t );
        //
        memcpy( buf_ptr, TrailerData[i].trailerTemplate.getWidthRef(), sizeof( uint32_t ) );
        buf_ptr += sizeof( uint32_t );
        memcpy( buf_ptr, TrailerData[i].trailerTemplate.getHeightRef(), sizeof( uint32_t ) );
        buf_ptr += sizeof( uint32_t );

        //
        if( TrailerData[i].Is_Valid )
        {
            if( TrailerData[i].trailerTemplate.isContinuous() )
            {
                memcpy( buf_ptr, TrailerData[i].trailerTemplate.getData(), sizeof( uint8_t ) * TrailerData[i].trailerTemplate.getSize() );
                buf_ptr += sizeof( uint8_t ) * TrailerData[i].trailerTemplate.getSize();
            }
            else
            {
                uint8_t* img_ptr = TrailerData[i].trailerTemplate.getData();

                for( uint32_t y = 0; y < TrailerData[i].trailerTemplate.getHeight(); y++ )
                {
                    memcpy( buf_ptr, img_ptr, sizeof( uint8_t ) * TrailerData[i].trailerTemplate.getWidth() );
                    buf_ptr += sizeof( uint8_t ) * TrailerData[i].trailerTemplate.getWidth();
                    img_ptr += TrailerData[i].trailerTemplate.getStep();
                }
            }
        }

        memcpy( buf_ptr, &TrailerData[i].Trailer_ID, sizeof( TrailerID_e ) );
        buf_ptr += sizeof( TrailerID_e );
        memcpy( buf_ptr, &TrailerData[i].UsedCount, sizeof( int32_t ) );
        buf_ptr += sizeof( int32_t );
        memcpy( buf_ptr, &TrailerData[i].hitchPointValid, sizeof( bool_t ) );
        buf_ptr += sizeof( bool_t );
        memcpy( buf_ptr, &TrailerData[i].hitchPoint.x, sizeof( int32_t ) );
        buf_ptr += sizeof( int32_t );
        memcpy( buf_ptr, &TrailerData[i].hitchPoint.y, sizeof( int32_t ) );
        buf_ptr += sizeof( int32_t );
        memcpy( buf_ptr, &TrailerData[i].HitchLength, sizeof( uint32_t ) );
        buf_ptr += sizeof( uint32_t );
        memcpy( buf_ptr, &TrailerData[i].CollisionAngleValid, sizeof( bool_t ) );
        buf_ptr += sizeof( bool_t );
        memcpy( buf_ptr, &TrailerData[i].CollisionAngle, sizeof( uint32_t ) );
        buf_ptr += sizeof( uint32_t );
        memcpy( buf_ptr, &TrailerData[i].beamlengthValid, sizeof( bool_t ) );
        buf_ptr += sizeof( bool_t );
        memcpy( buf_ptr, &TrailerData[i].BeamLength, sizeof( float32_t ) );
        buf_ptr += sizeof( float32_t );
        memcpy( buf_ptr, &TrailerData[i].JacknifeAngle, sizeof( uint32_t ) );
        buf_ptr += sizeof( uint32_t );
        memcpy( buf_ptr, &TrailerData[i].JacknifeThreshAngle, sizeof( uint32_t ) );
        buf_ptr += sizeof( uint32_t );
    }
}

/**
* Deserialize this calibration. Assumes trailerImage.data points to enough allocated memory
* to store the image in the buffer.
*/
void TAD2::TrailerFeatures::DeserializeFeature( uint8_t* buffer )
{
    uint8_t* buf_ptr = buffer;
    uint32_t l_versionNum = 0;
    memcpy( &l_versionNum, buf_ptr, sizeof( l_versionNum ) );
    buf_ptr += sizeof( uint32_t );

    if( l_versionNum == ( uint32_t )7000100 )
    {
        // ++++ Trailer Data
        for( uint32_t i = 0; i < TrailerID_e::Trailer_MAX; i++ )
        {
            memcpy( &TrailerData[i].Is_Valid, buf_ptr, sizeof( bool_t ) );
            buf_ptr += sizeof( bool_t );
            //
            uint32_t tmp_width;
            uint32_t tmp_height;
            memcpy( &tmp_width, buf_ptr, sizeof( uint32_t ) );
            TrailerData[i].trailerTemplate.setWidth( tmp_width );
            buf_ptr += sizeof( uint32_t );
            memcpy( &tmp_height, buf_ptr, sizeof( uint32_t ) );
            TrailerData[i].trailerTemplate.setHeight( tmp_height );
            buf_ptr += sizeof( uint32_t );
            //
            TrailerData[i].trailerTemplate.setNumChannels( 1 );
            TrailerData[i].trailerTemplate.setStep( TrailerData[i].trailerTemplate.getWidth() );
            TrailerData[i].trailerTemplate.setSize( TrailerData[i].trailerTemplate.getWidth() * TrailerData[i].trailerTemplate.getHeight() );

            if( TrailerData[i].Is_Valid )
            {
                if( TrailerData[i].trailerTemplate.isContinuous() )
                {
                    memcpy( TrailerData[i].trailerTemplate.getData(), buf_ptr, sizeof( uint8_t ) * TrailerData[i].trailerTemplate.getSize() );
                    buf_ptr += sizeof( uint8_t ) * TrailerData[i].trailerTemplate.getSize();
                }
                else
                {
                    uint8_t* img_ptr = TrailerData[i].trailerTemplate.getData();

                    for( uint32_t y = 0; y < TrailerData[i].trailerTemplate.getHeight(); y++ )
                    {
                        memcpy( img_ptr, buf_ptr, sizeof( uint8_t ) * TrailerData[i].trailerTemplate.getWidth() );
                        buf_ptr += sizeof( uint8_t ) * TrailerData[i].trailerTemplate.getWidth();
                        img_ptr += TrailerData[i].trailerTemplate.getStep();
                    }
                }
            }
            else
            {
                TrailerData[i].trailerTemplate.setData( NULL );
            }

            memcpy( &TrailerData[i].Trailer_ID, buf_ptr, sizeof( TrailerID_t ) );
            buf_ptr += sizeof( TrailerID_e );
            memcpy( &TrailerData[i].UsedCount, buf_ptr, sizeof( int32_t ) );
            buf_ptr += sizeof( int32_t );
            memcpy( &TrailerData[i].hitchPointValid, buf_ptr, sizeof( bool_t ) );
            buf_ptr += sizeof( bool_t );
            int32_t tmp_x;
            memcpy( &tmp_x, buf_ptr, sizeof( int32_t ) );
            TrailerData[i].hitchPoint.x = tmp_x;
            buf_ptr += sizeof( int32_t );
            int32_t tmp_y;
            memcpy( &tmp_y, buf_ptr, sizeof( int32_t ) );
            TrailerData[i].hitchPoint.y = tmp_y;
            buf_ptr += sizeof( int32_t );
            memcpy( &TrailerData[i].HitchLength, buf_ptr, sizeof( uint32_t ) );
            buf_ptr += sizeof( uint32_t );
            //CollisionAngle
            memcpy( &TrailerData[i].CollisionAngleValid, buf_ptr, sizeof( bool_t ) );
            buf_ptr += sizeof( bool_t );
            memcpy( &TrailerData[i].CollisionAngle, buf_ptr, sizeof( uint32_t ) );
            buf_ptr += sizeof( uint32_t );
            //BeamLength
            memcpy( &TrailerData[i].beamlengthValid, buf_ptr, sizeof( bool_t ) );
            buf_ptr += sizeof( bool_t );
            memcpy( &TrailerData[i].BeamLength, buf_ptr, sizeof( float32_t ) );
            buf_ptr += sizeof( float32_t );
            //Jacknife
            memcpy( &TrailerData[i].JacknifeAngle, buf_ptr, sizeof( uint32_t ) );
            buf_ptr += sizeof( uint32_t );
            memcpy( &TrailerData[i].JacknifeThreshAngle, buf_ptr, sizeof( uint32_t ) );
            buf_ptr += sizeof( uint32_t );
        }
    }
    else
    {
        ME_Debugger_F_Printf_v("\n Version number for The Trailer Calibration file does not match. Please erase the NVM data and recalibrate the trailer. \n");
    }
}
