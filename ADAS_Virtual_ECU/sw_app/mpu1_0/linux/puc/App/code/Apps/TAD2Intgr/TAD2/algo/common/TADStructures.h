// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [08-Feb-2019]
// --- Last Modified by Joshua Teichroeb [07-Mar-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __TAD_STRUCTURES__H_
#define __TAD_STRUCTURES__H_

#include <mecl/core/MeclTypes.h>
#include <stdint.h>
#include "Image.h"
#ifdef _WINDOWS_
    #include "../common/TRSC_Inputs_Outputs.h"
#else
    #include "TRSC_Inputs_Outputs.h"
#endif

namespace TAD2
{
    bool _isEqual( float64_t a, float64_t b );
    /*
    * Vehicle parameter set used by TAD.
    */
    struct VehicleParameters
    {
        float32_t length_mm;
        float32_t width_mm;
        float32_t frontOverhang_mm;
        float32_t rearOverhang_mm;
        float32_t wheelBase_mm;

        float32_t hitchLength_mm; // distance from rear axle to hitch ball
    };

    /*
    * Trailer parameter set used by TAD.
    */
    class TrailerParameters
    {
    public:
        TrailerParameters();
        TrailerParameters( float32_t i_beamLength_mm, float32_t i_width_mm, float32_t i_frontOverhang_mm );

        inline float32_t getBeamLength() const
        {
            return beamLength_mm;
        };
        inline void setBeamLength( float32_t bl_mm )
        {
            beamLength_mm = bl_mm;
        };
    private:
        float32_t beamLength_mm;
        float32_t width_mm;
        float32_t frontOverhang_mm;
    };

    /*
    * Parameters specific to how the topview is warped.
    */
    struct WarpedTopViewParameters
    {
        uint32_t width;
        uint32_t height;
        uint32_t yOffset;
        float32_t start_deg;
        float32_t range_deg;
        float32_t degreesPerPixel;

        bool_t operator==( const WarpedTopViewParameters& other ) const;
    };

    /*
    * Sub-class of Image, holds extra information defining how the image has been warped.
    */
    template<typename T>
    class WarpedImage : public image::Image<T>
    {
    public:

        // --- Constructors / Destructor
        WarpedImage();
        WarpedImage( const WarpedTopViewParameters& params, const image::Image<uint8_t>& img );
        explicit WarpedImage( const WarpedTopViewParameters& params );
        explicit WarpedImage( const image::Image<uint8_t>& img );
        virtual ~WarpedImage();

        // --- Functions specific to warped images
        int32_t Angle2XPos( float32_t angle_deg, float32_t* error = NULL );
        float32_t XPos2Angle( float32_t xPos );
        float32_t RoundAngle( float32_t angle_deg );

        // --- Operators
        void operator=( const image::Image<uint8_t>& other );


        inline void setStart_Deg( float32_t deg )
        {
            start_deg = deg;
        }
        inline void setRange_Deg( float32_t deg )
        {
            range_deg = deg;
        }
        inline void setDegreesPixel( float32_t degPerPix )
        {
            degreesPerPixel = degPerPix;
        }
    private:
        float32_t start_deg;
        float32_t range_deg;
        float32_t degreesPerPixel;

    };

    /*
    * Template struct used in template matching.
    */
    struct TrailerTemplate : public WarpedImage<uint8_t>
    {
        void operator=( const image::Image<uint8_t>& other );
    };


    /*
    * Struct which holds the information relative to Features for Trailer Recognition
    */
    struct TrailerFeatures
    {
        struct Trailers
        {
            bool_t Is_Valid;
            image::Image<uint8_t> UnwarpedImage;
            TAD2::TrailerTemplate trailerTemplate;
            TrailerID_t Trailer_ID;
            int32_t UsedCount;
            Point2i hitchPoint;
            uint32_t HitchLength;
            uint32_t CollisionAngle;
            float32_t BeamLength;
            uint32_t JacknifeAngle;
            uint32_t JacknifeThreshAngle;
            bool_t Trailer_Present;
            bool_t AbsencePresenceValid;
            bool_t hitchPointValid;
            bool_t CollisionAngleValid;
            bool_t beamlengthValid;

            Trailers()
            {
                Is_Valid = false;
                memset( trailerTemplate.getData(), 0, sizeof( uint8_t )* trailerTemplate.getHeight() * trailerTemplate.getWidth() );
                memset( trailerTemplate.getData(), 0, sizeof( uint8_t )* trailerTemplate.getHeight() * trailerTemplate.getWidth() );
                UsedCount = 0;
                HitchLength = 0;
                CollisionAngle = 0;
                BeamLength = 0.0f;
                JacknifeAngle = 0;
                JacknifeThreshAngle = 0;
                Trailer_Present = false;
                AbsencePresenceValid = false;
                hitchPointValid = false;
                CollisionAngleValid = false;
                beamlengthValid = false;
                Trailer_ID = TrailerID_t::Trailer_MAX;
            }
        };
        Trailers TrailerData[TrailerID_e::Trailer_MAX];

        // --- Serializing functions
        uint32_t GetFeatureStorageSize() const;
        void SerializeFeature( uint8_t* buffer ) const;
        void DeserializeFeature( uint8_t* buffer );
        static uint32_t ReadFeatureTemplateSize( uint8_t* buffer );

        TrailerFeatures()
        {
            for( size_t i = 0; i < static_cast<size_t>( TrailerID_e::Trailer_MAX ); i++ )
            {
                TrailerData[i] = Trailers();
            }
        }


    };

    ///------------------------------------------------------------------------------
    /// WarpedImage function definitions.
    ///------------------------------------------------------------------------------

    /*
    * Constructor.
    */
    template<typename T>
    inline WarpedImage<T>::WarpedImage() :
        WarpedImage::Image(),
        start_deg( 0.0f ),
        range_deg( 0.0f ),
        degreesPerPixel( 0.0f ) {}

    /*
    * Constructor.
    */
    template<typename T>
    inline WarpedImage<T>::WarpedImage( const WarpedTopViewParameters& params, const image::Image<uint8_t>& img ) :
        WarpedImage::Image( params.width, params.height, img.getData(), img.getNumChannels(), img.getStep(), img.getType() ),
        start_deg( params.start_deg ),
        range_deg( params.range_deg ),
        degreesPerPixel( params.degreesPerPixel )
    {
        Assert( params.width <= img.getWidth() && params.height <= img.getHeight() );
    }

    /*
    * Constructor.
    */
    template<typename T>
    inline WarpedImage<T>::WarpedImage( const WarpedTopViewParameters& params ) :
        WarpedImage::Image( params.width, params.height, nullptr, 0 ),
        start_deg( params.start_deg ),
        range_deg( params.range_deg ),
        degreesPerPixel( params.degreesPerPixel ) {}

    /*
    * Constructor.
    */
    template<typename T>
    inline WarpedImage<T>::WarpedImage( const image::Image<uint8_t>& img ) :
#ifdef ME_PLATFORM_QNX
        WarpedImage::Image( img ),
#else
        Image( img ),
#endif
        start_deg( 0.0f ),
        range_deg( 0.0f ),
        degreesPerPixel( 0.0f ) {}

    /*
    * Destructor.
    */
    template<typename T>
    inline WarpedImage<T>::~WarpedImage() {}

    /**
    * Convert from an angle in degrees to a column in the image.
    *
    * @param angle_deg angle to be found (in degrees)
    * @param error the difference between the output columns actual degree value
    *              and the input angle
    */
    template<typename T>
    inline int32_t WarpedImage<T>::Angle2XPos( float32_t angle_deg, float32_t* error )
    {
        if( error != NULL )
        {
            float32_t xPos_f = -( angle_deg - start_deg ) / degreesPerPixel;
            int32_t xPos = ( int32_t )xPos_f;
            *error = xPos_f - ( float32_t )xPos;
            return xPos;
        }
        else
        {
            return ( int32_t )( -( angle_deg - start_deg ) / degreesPerPixel );
        }
    }

    /**
    * Get the degree value of the given column.
    */
    template<typename T>
    inline float32_t WarpedImage<T>::XPos2Angle( float32_t xPos )
    {
        return start_deg - xPos * degreesPerPixel;
    }

    /**
    * Rounds an angle to its nearest representation in the image.
    */
    template<typename T>
    inline float32_t WarpedImage<T>::RoundAngle( float32_t angle_deg )
    {
        int32_t temp = ( int32_t )Angle2XPos( angle_deg );
        return XPos2Angle( temp );
    }

    /**
    * Shallow copy to an Image.
    */
    template<typename T>
    inline void WarpedImage<T>::operator=( const image::Image<uint8_t>& other )
    {
        image::Image<uint8_t> i_image;
        i_image.operator = ( other );
    }
}

#endif // !__TAD_STRUCTURES__H_
