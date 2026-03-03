// ----------------------------------------------------------------------------
// --- Written by Sandip Suman Senapati [04-Feb-2025]
// ----------------------------------------------------------------------------

#include "Utility.h"

int brderInterpolate( int p, int len, int borderType )
{
    //CV_TRACE_FUNCTION_VERBOSE();
    assert( len > 0 );
#ifdef CV_STATIC_ANALYSIS

    if( p >= 0 && p < len )
#else
    if( ( unsigned )p < ( unsigned )len )
#endif
        ;
    else if( borderType == APP_BORDER_REPLICATE )
    {
        p = p < 0 ? 0 : len - 1;
    }
    else if( borderType == APP_BORDER_REFLECT || borderType == APP_BORDER_REFLECT101 )
    {
        int delta = borderType == APP_BORDER_REFLECT101;

        if( len == 1 )
        {
            return 0;
        }

        do
        {
            if( p < 0 )
            {
                p = -p - 1 + delta;
            }
            else
            {
                p = len - 1 - ( p - len ) - delta;
            }
        }

#ifdef CV_STATIC_ANALYSIS

        while( p < 0 || p >= len );

#else

        while( ( unsigned )p >= ( unsigned )len );

#endif
    }
    else if( borderType == APP_BORDER_WRAP )
    {
        assert( len > 0 );

        if( p < 0 )
        {
            p -= ( ( p - len + 1 ) / len ) * len;
        }

        if( p >= len )
        {
            p %= len;
        }
    }
    else if( borderType == APP_BORDER_CONSTANT )
    {
        p = -1;
    }
    else
    {
        fprintf( stderr, "Unknown Border type" );
    }

    return p;
}
void copyMkeBorder_8u( image::Image<uint8_t> _src, image::Image<uint8_t> _dst, int top, int bottom,
                       int left, int right, int borderType )
{
    if( top == 0 && left == 0 && bottom == 0 && right == 0 )
    {
        if( _src.getData() != _dst.getData() || _src.getStep() != _dst.getStep() )
        {
            _dst.setData( _src.getData() );
        }

        return;
    }

    borderType &= ~APP_BORDER_ISOLATED;
    size2i srcSize, destSize;
    srcSize.height = _src.getHeight();
    srcSize.width = _src.getWidth();
    destSize.height = _dst.getHeight();
    destSize.width = _dst.getWidth();

    if( borderType != APP_BORDER_CONSTANT )
    {
        copyMakeBorder_8u( ( uint8_t* )_src.getData(), _src.getStep() * 1, srcSize,
                           ( uint8_t* )_dst.getData(), _dst.getStep() * 1, destSize,
                           top, left, ( int )_src.elemSize(), borderType );
    }
    else
    {
        int cn = _src.getNumChannels(), cn1 = cn;
        AutoBuffer<double> buf( cn );
        //make _src.getStep() * 1 beacause _src is of UINT8_T and function is uint8_t
        copyMakeConstBorder_8u( ( uint8_t* )_src.getData(), _src.getStep() * 1, srcSize,
                                ( uint8_t* )_dst.getData(), _dst.getStep() * 1, destSize,
                                top, left, ( int )_src.elemSize(), ( uint8_t* )buf.data() );
    }
}


void copyMkeBorder_16u( image::Image<int16_t> _src, image::Image<int16_t> _dst, int top, int bottom,
                        int left, int right, int borderType )
{
    if( top == 0 && left == 0 && bottom == 0 && right == 0 )
    {
        if( _src.getData() != _dst.getData() || _src.getStep() != _dst.getStep() )
        {
            _dst.setData( _src.getData() );
        }

        return;
    }

    borderType &= ~APP_BORDER_ISOLATED;
    size2i srcSize, destSize;
    srcSize.height = _src.getHeight();
    srcSize.width = _src.getWidth();
    destSize.height = _dst.getHeight();
    destSize.width = _dst.getWidth();

    if( borderType != APP_BORDER_CONSTANT )
    {
        copyMakeBorder_8u( ( uint8_t* )_src.getData(), _src.getStep() * 2, srcSize,
                           ( uint8_t* )_dst.getData(), _dst.getStep() * 2, destSize,
                           top, left, ( int )_src.elemSize(), borderType );
    }
    else
    {
        int cn = _src.getNumChannels(), cn1 = cn;
        AutoBuffer<double> buf( cn );
        //make _src.getStep() * 2 beacause _src is of INT16 and function is uint8_t
        copyMakeConstBorder_8u( ( uint8_t* )_src.getData(), _src.getStep() * 2, srcSize,
                                ( uint8_t* )_dst.getData(), _dst.getStep() * 2, destSize,
                                top, left, ( int )_src.elemSize(), ( uint8_t* )buf.data() );
    }
}
void copyMakeConstBorder_8u( const uint8_t* src, size_t srcstep, size2i srcroi,
                             uint8_t* dst, size_t dststep, size2i dstroi,
                             int top, int left, int cn, const uint8_t* value )
{
    int i, j;
    AutoBuffer<uint8_t> _constBuf( dstroi.width * cn );
    uint8_t* constBuf = _constBuf.data();
    int right = dstroi.width - srcroi.width - left;
    int bottom = dstroi.height - srcroi.height - top;

    for( i = 0; i < dstroi.width; i++ )
    {
        for( j = 0; j < cn; j++ )
        {
            constBuf[i * cn + j] = value[j];
        }
    }

    srcroi.width *= cn;
    dstroi.width *= cn;
    left *= cn;
    right *= cn;
    uint8_t* dstInner = dst + dststep * top + left;

    for( i = 0; i < srcroi.height; i++, dstInner += dststep, src += srcstep )
    {
        if( dstInner != src )
        {
            memcpy( dstInner, src, srcroi.width );
        }

        memcpy( dstInner - left, constBuf, left );
        memcpy( dstInner + srcroi.width, constBuf, right );
    }

    for( i = 0; i < top; i++ )
    {
        memcpy( dst + i * dststep, constBuf, dstroi.width );
    }

    dst += ( top + srcroi.height ) * dststep;

    for( i = 0; i < bottom; i++ )
    {
        memcpy( dst + i * dststep, constBuf, dstroi.width );
    }
}
void copyMakeBorder_8u( const uint8_t* src, size_t srcstep, size2i srcroi,
                        uint8_t* dst, size_t dststep, size2i dstroi,
                        int top, int left, int cn, int borderType )
{
    const int isz = ( int )sizeof( int );
    int i, j, k, elemSize = 1;
    bool intMode = false;

    if( ( cn | srcstep | dststep | ( size_t )src | ( size_t )dst ) % isz == 0 )
    {
        cn /= isz;
        elemSize = isz;
        intMode = true;
    }

    AutoBuffer<int> _tab( ( dstroi.width - srcroi.width )*cn );
    int* tab = _tab.data();
    int right = dstroi.width - srcroi.width - left;
    int bottom = dstroi.height - srcroi.height - top;

    for( i = 0; i < left; i++ )
    {
        //j = cv::borderInterpolate( i - left, srcroi.width, borderType ) * cn;
        j = brderInterpolate( i - left, srcroi.width, borderType ) * cn;

        for( k = 0; k < cn; k++ )
        {
            tab[i * cn + k] = j + k;
        }
    }

    for( i = 0; i < right; i++ )
    {
        //j = cv::borderInterpolate( srcroi.width + i, srcroi.width, borderType ) * cn;
        j = brderInterpolate( srcroi.width + i, srcroi.width, borderType ) * cn;

        for( k = 0; k < cn; k++ )
        {
            tab[( i + left )*cn + k] = j + k;
        }
    }

    srcroi.width *= cn;
    dstroi.width *= cn;
    left *= cn;
    right *= cn;
    uint8_t* dstInner = dst + dststep * top + left * elemSize;

    for( i = 0; i < srcroi.height; i++, dstInner += dststep, src += srcstep )
    {
        if( dstInner != src )
        {
            memcpy( dstInner, src, srcroi.width * elemSize );
        }

        if( intMode )
        {
            const int* isrc = ( int* )src;
            int* idstInner = ( int* )dstInner;

            for( j = 0; j < left; j++ )
            {
                idstInner[j - left] = isrc[tab[j]];
            }

            for( j = 0; j < right; j++ )
            {
                idstInner[j + srcroi.width] = isrc[tab[j + left]];
            }
        }
        else
        {
            for( j = 0; j < left; j++ )
            {
                dstInner[j - left] = src[tab[j]];
            }

            for( j = 0; j < right; j++ )
            {
                dstInner[j + srcroi.width] = src[tab[j + left]];
            }
        }
    }

    dstroi.width *= elemSize;

    for( i = 0; i < top; i++ )
    {
        //j = cv::borderInterpolate( i - top, srcroi.height, borderType );
        j = brderInterpolate( i - top, srcroi.height, borderType );
        memcpy( dst + i * dststep, dst + ( top + j )*dststep, dstroi.width );
    }

    dst += dststep * top;

    for( i = 0; i < bottom; i++ )
    {
        //j = cv::borderInterpolate( i + srcroi.height, srcroi.height, borderType );
        j = brderInterpolate( i + srcroi.height, srcroi.height, borderType );
        memcpy( dst + ( i + srcroi.height )*dststep, dst + j * dststep, dstroi.width );
    }
}

