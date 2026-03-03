// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [05-Dec-2018]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------


#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "Image.h"
#include "stdtad.h"



/*
* Default constructor.
*/
_roi::ROI::ROI() : x(), y(), width(), height()
{
}

/*
* Full constructor.
*/
_roi::ROI::ROI( uint32_t i_x, uint32_t i_y, uint32_t i_width, uint32_t i_height ) :
    x( i_x ),
    y( i_y ),
    width( i_width ),
    height( i_height )
{
}

/*
* Returns the combined region of this and another ROI. Will return the smallest
* rectangle that contains both this and the other ROI.
*/
_roi::ROI _roi::ROI::operator|=( const ROI& other )const
{
    ROI ret_val;

    if( ( width == 0 ) || ( height == 0 ) )
    {
        ret_val = other;
    }
    else
    {
        uint32_t min_x = mms::minimum( x, other.x );
        uint32_t max_x = mms::maximum( x + width, other.x + other.width );
        uint32_t min_y = mms::minimum( y, other.y );
        uint32_t max_y = mms::maximum( y + height, other.y + other.height );
        ret_val = ROI( min_x, min_y, max_x - min_x, max_y - min_y );
    }

    return ret_val;
}

/*
* Returns the intersection of this ROI and another ROI. Will have a size of 0 if
* there is no intersection.
*/
_roi::ROI _roi::ROI::operator&=( const ROI& other ) const
{
    ROI ret_val;

    if( ( width == 0 ) || ( height == 0 ) )
    {
        ret_val = other;
    }
    else
    {
        uint32_t min_x = mms::maximum( x, other.x );
        uint32_t max_x = mms::minimum( x + width, other.x + other.width );
        uint32_t min_y = mms::maximum( y, other.y );
        uint32_t max_y = mms::minimum( y + height, other.y + other.height );
        ret_val = ROI( min_x, min_y, mms::maximum( max_x - min_x, static_cast<uint32_t>( 0 ) ), mms::maximum( max_y - min_y, static_cast<uint32_t>( 0 ) ) );
    }

    return ret_val;
}
