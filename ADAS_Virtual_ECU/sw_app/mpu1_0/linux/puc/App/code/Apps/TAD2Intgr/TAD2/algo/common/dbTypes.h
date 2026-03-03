// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [17-Jan-2019]
// --- Last Modified by Joshua Teichroeb [17-Jan-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __DB_TYPES__H_
#define __DB_TYPES__H_

#ifdef __QNX__
    #include "mecl/mecl.h"
    #include "meal/camera/core/inc/CameraPoint.h"
#else
    #include "MECL\mecl.h"
    #include "Point.h"
#endif


///------------------------------------------------------------------------------
/// Debugging library
///
/// This header is to remain free from OpenCV and std library functions/classes.
///------------------------------------------------------------------------------
namespace db
{
    ///------------------------------------------------------------------------------
    /// Classes and typedefs to replace OpenCV classes.
    ///------------------------------------------------------------------------------

    /*
    * BGR colour class.
    */
    struct Colour
    {
        int b, g, r;
        Colour() : b( 0 ), g( 0 ), r( 0 ) {};
        Colour( int b, int g, int r ) : b( b ), g( g ), r( r ) {};
        bool operator==( const db::Colour& other ) const
        {
            return ( b == other.b && g == other.g && r == other.r );
        };
    };

    /**
    * Types of plots.
    */
    enum ePlotType
    {
        PlotLines,
        PlotDots
    };

    // Typedefs
    typedef Point2i Point;


    ///------------------------------------------------------------------------------
    /// Other helpful classes.
    ///------------------------------------------------------------------------------

    /*
    * Range object which creates an array and populates its values with numbers from
    * 'start' to 'end', with an optional 'step'.
    */
    template<typename T, uint32_t max_size>
    struct Range
    {
        T data[max_size];

        Range( double start, double end, double step = 1 );
        ~Range();

        T* ptr();
    };

    /*
    * Imshow option definitions.
    */
    enum imshow_options
    {
        ImShow_Grey2Colour,
        ImShow_Binary,
        ImShow_BGR,
        ImShow_Grey,
        ImShow_Default = ImShow_Grey
    };
}

///------------------------------------------------------------------------------
/// Range template function definitions.
///------------------------------------------------------------------------------

template<typename T, uint32_t max_size>
inline db::Range<T, max_size>::Range( double start, double end, double step )
{
    int32_t i = 0;

    for( double val = start; val < end; val += step, ++i )
    {
        data[i] = ( T )val;
    }
}

template<typename T, uint32_t max_size>
inline db::Range<T, max_size>::~Range()
{
    //if( _ptr != nullptr )
    //{
    //    delete[] _ptr;
    //}
}

template<typename T, uint32_t max_size>
inline T* db::Range<T, max_size>::ptr()
{
    return &data[0];
}


#endif  // !__DB_TYPES__H_
