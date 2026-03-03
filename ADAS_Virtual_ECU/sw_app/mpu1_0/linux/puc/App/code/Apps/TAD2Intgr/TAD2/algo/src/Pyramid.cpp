// ----------------------------------------------------------------------------
// --- Written by Sandip Suman Senapati [04-Feb-2025]
// ----------------------------------------------------------------------------
#include "Pyramid.h"

template <> int PyrDownVecH<uint16_t, int, 1>( const uint16_t* src, int* row, int width )
{
    int x = 0;
    // Gaussian kernel weights: 1, 4, 6, 4, 1
    const int kernel[5] = { 1, 4, 6, 4, 1 };
    const int kernel_sum = 16;  // Sum of the kernel weights for normalization

    // Process each pixel in the row
    for( ; x <= width - 2; ++x )
    {
        // Apply the 5-pixel horizontal kernel
        row[x] = ( src[x] * kernel[2] +        // Center pixel (weight = 6)
                   src[x - 2] * kernel[0] +     // Leftmost pixel (weight = 1)
                   src[x - 1] * kernel[1] +     // Left neighbor (weight = 4)
                   src[x + 1] * kernel[3] +     // Right neighbor (weight = 4)
                   src[x + 2] * kernel[4] ) / kernel_sum; // Rightmost pixel (weight = 1)
    }

    return x;  // Return the number of processed pixels
}
template<> int PyrDownVecV<int, uint8_t>( int** src, uint8_t* dst, int width )
{
    int x = 0;
    const int* row0 = src[0], *row1 = src[1], *row2 = src[2], *row3 = src[3], *row4 = src[4];

    // Loop through all pixels in the width
    for( ; x < width; x++ )
    {
        // Perform the vertical convolution using the 5 rows
        int r0 = row0[x];
        int r1 = row1[x];
        int r2 = row2[x];
        int r3 = row3[x];
        int r4 = row4[x];
        // Compute the weighted sum
        int t0 = r0 + r4 + ( r2 + r2 ) + ( ( r1 + r3 + r2 ) << 2 );
        // Divide by 256 to simulate the right-shift operation for 8 bits
        dst[x] = static_cast<uint8_t>( ( t0 + ( 1 << 7 ) ) >> 8 ); // Add rounding factor (128)
    }

    return x;
}
template<class CastOp>
PyramidDownInvoker<CastOp>::PyramidDownInvoker( const image::Image<uint8_t>* src, const image::Image<uint8_t>* dst, int borderType, int** tabR, int** tabM, int** tabL )
{
    _src = src;
    _dst = dst;
    _borderType = borderType;
    _tabR = tabR;
    _tabM = tabM;
    _tabL = tabL;
}
template<class CastOp>
void PyramidDownInvoker<CastOp>::sequenceOperation( const Range& range )
{
    const int PD_SZ = 5;
    typedef typename CastOp::type1 WT;
    typedef typename CastOp::rtype T;
    size2i ssize = size2i( _src->getWidth(), _src->getHeight() ), dsize = size2i( _dst->getWidth(), _dst->getHeight() );
    int cn = _src->getNumChannels();
    int bufstep = ( int )alinSize( dsize.width * cn, 16 );
    AutoBuffer<WT> _buf( bufstep * PD_SZ + 16 );
    WT* buf = alnPtr( ( WT* )_buf.data(), 16 );
    WT* rows[PD_SZ];
    CastOp castOp;
    int sy0 = -PD_SZ / 2, sy = range.start * 2 + sy0, width0 = min_int32( ( ssize.width - PD_SZ / 2 - 1 ) / 2 + 1, dsize.width );
    ssize.width *= cn;
    dsize.width *= cn;
    width0 *= cn;

    for( int y = range.start; y < range.end; y++ )
    {
        //T* dst = ( T* )_dst->ptr( y );
        T* dst = ( T* )( _dst->getData() + _dst->getStep() * y );
        WT* row0, *row1, *row2, *row3, *row4;
        // fill the ring buffer (horizontal convolution and decimation)
        int sy_limit = y * 2 + 2;

        for( ; sy <= sy_limit; sy++ )
        {
            WT* row = buf + ( ( sy - sy0 ) % PD_SZ ) * bufstep;
            int _sy = brderInterpolate( sy, ssize.height, _borderType );
            //T* src = _src->ptr( _sy );
            T* src = ( T* )( _src->getData() + _src->getStep() * _sy );

            do
            {
                int x = 0;
                const int* tabL = *_tabL;

                for( ; x < cn; x++ )
                {
                    row[x] = src[tabL[x + cn * 2]] * 6 + ( src[tabL[x + cn]] + src[tabL[x + cn * 3]] ) * 4 +
                             src[tabL[x]] + src[tabL[x + cn * 4]];
                }

                if( x == dsize.width )
                {
                    break;
                }

                if( cn == 1 )
                {
                    x += PyrDownVecH<T, WT, 1>( src + x * 2 - 2, row + x, width0 - x );

                    for( ; x < width0; x++ )
                        row[x] = src[x * 2] * 6 + ( src[x * 2 - 1] + src[x * 2 + 1] ) * 4 +
                                 src[x * 2 - 2] + src[x * 2 + 2];
                }
                // else if( cn == 2 )
                // {
                //     x += PyrDownVecH<T, WT, 2>(src + x * 2 - 4, row + x, width0 - x);
                //     for( ; x < width0; x += 2 )
                //     {
                //         const T* s = src + x*2;
                //         WT t0 = s[0] * 6 + (s[-2] + s[2]) * 4 + s[-4] + s[4];
                //         WT t1 = s[1] * 6 + (s[-1] + s[3]) * 4 + s[-3] + s[5];
                //         row[x] = t0; row[x + 1] = t1;
                //     }
                // }
                // else if( cn == 3 )
                // {
                //     x += PyrDownVecH<T, WT, 3>(src + x * 2 - 6, row + x, width0 - x);
                //     for( ; x < width0; x += 3 )
                //     {
                //         const T* s = src + x*2;
                //         WT t0 = s[0]*6 + (s[-3] + s[3])*4 + s[-6] + s[6];
                //         WT t1 = s[1]*6 + (s[-2] + s[4])*4 + s[-5] + s[7];
                //         WT t2 = s[2]*6 + (s[-1] + s[5])*4 + s[-4] + s[8];
                //         row[x] = t0; row[x+1] = t1; row[x+2] = t2;
                //     }
                // }
                // else if( cn == 4 )
                // {
                //     x += PyrDownVecH<T, WT, 4>(src + x * 2 - 8, row + x, width0 - x);
                //     for( ; x < width0; x += 4 )
                //     {
                //         const T* s = src + x*2;
                //         WT t0 = s[0]*6 + (s[-4] + s[4])*4 + s[-8] + s[8];
                //         WT t1 = s[1]*6 + (s[-3] + s[5])*4 + s[-7] + s[9];
                //         row[x] = t0; row[x+1] = t1;
                //         t0 = s[2]*6 + (s[-2] + s[6])*4 + s[-6] + s[10];
                //         t1 = s[3]*6 + (s[-1] + s[7])*4 + s[-5] + s[11];
                //         row[x+2] = t0; row[x+3] = t1;
                //     }
                // }
                else
                {
                    for( ; x < width0; x++ )
                    {
                        int sx = ( *_tabM )[x];
                        row[x] = src[sx] * 6 + ( src[sx - cn] + src[sx + cn] ) * 4 +
                                 src[sx - cn * 2] + src[sx + cn * 2];
                    }
                }

                // tabR
                const int* tabR = *_tabR;

                for( int x_ = 0; x < dsize.width; x++, x_++ )
                {
                    row[x] = src[tabR[x_ + cn * 2]] * 6 + ( src[tabR[x_ + cn]] + src[tabR[x_ + cn * 3]] ) * 4 +
                             src[tabR[x_]] + src[tabR[x_ + cn * 4]];
                }
            }
            while( 0 );
        }

        // do vertical convolution and decimation and write the result to the destination image
        for( int k = 0; k < PD_SZ; k++ )
        {
            rows[k] = buf + ( ( y * 2 - PD_SZ / 2 + k - sy0 ) % PD_SZ ) * bufstep;
        }

        row0 = rows[0];
        row1 = rows[1];
        row2 = rows[2];
        row3 = rows[3];
        row4 = rows[4];
        int x = PyrDownVecV<WT, T>( rows, dst, dsize.width );

        for( ; x < dsize.width; x++ )
        {
            dst[x] = castOp( row2[x] * 6 + ( row1[x] + row3[x] ) * 4 + row0[x] + row4[x] );
        }
    }
}
template<class CastOp> void
pyrDown_( const image::Image<uint8_t>& _src, image::Image<uint8_t>& _dst, int borderType )
{
    const int PD_SZ = 5;
    assert( _src.getData() != NULL );
    size2i ssize = size2i( _src.getWidth(), _src.getHeight() ), dsize = size2i( _dst.getWidth(), _dst.getHeight() );
    int cn = _src.getNumChannels();
    AutoBuffer<int> _tabM( dsize.width * cn ), _tabL( cn * ( PD_SZ + 2 ) ),
               _tabR( cn * ( PD_SZ + 2 ) );
    int* tabM = _tabM.data(), *tabL = _tabL.data(), *tabR = _tabR.data();
    assert( ssize.width > 0 && ssize.height > 0 &&
            mecl::math::abs_x( dsize.width * 2 - ssize.width ) <= 2 &&
            mecl::math::abs_x( dsize.height * 2 - ssize.height ) <= 2 );
    int width0 = min_int32( ( ssize.width - PD_SZ / 2 - 1 ) / 2 + 1, dsize.width );

    for( int x = 0; x <= PD_SZ + 1; x++ )
    {
        //int sx0 = cv::borderInterpolate( x - PD_SZ / 2, ssize.width, borderType ) * cn;
        int sx0 = brderInterpolate( x - PD_SZ / 2, ssize.width, borderType ) * cn;
        //int sx1 = cv::borderInterpolate( x + width0 * 2 - PD_SZ / 2, ssize.width, borderType ) * cn;
        int sx1 = brderInterpolate( x + width0 * 2 - PD_SZ / 2, ssize.width, borderType ) * cn;

        for( int k = 0; k < cn; k++ )
        {
            tabL[x * cn + k] = sx0 + k;
            tabR[x * cn + k] = sx1 + k;
        }
    }

    for( int x = 0; x < dsize.width * cn; x++ )
    {
        tabM[x] = ( x / cn ) * 2 * cn + x % cn;
    }

    int* tabLPtr = tabL;
    int* tabRPtr = tabR;
    PyramidDownInvoker<CastOp> tempInvoker = PyramidDownInvoker<CastOp>( &_src, &_dst, borderType, &tabRPtr, &tabM, &tabLPtr );
    tempInvoker.sequenceOperation( Range( 0, dsize.height ) );
}


void pyramidDown( image::Image<uint8_t> _src, image::Image<uint8_t> _dst, const size2i& _dsz, int borderType )
{
    assert( borderType != APP_BORDER_CONSTANT );
    size2i dsz = _dsz.empty() ? size2i( ( _src.getWidth() + 1 ) / 2, ( _src.getHeight() + 1 ) / 2 ) : _dsz;
    int depth = 0;
    PyrFunc func = 0;

    //if( depth == CV_8U )
    if( depth == 0 )
    {
        func = pyrDown_< FixPtCast<uint8_t,  8> >;
    }
    //else if( depth == CV_16S )
    else if( depth == 3 )
    {
        func = pyrDown_< FixPtCast<short, 8> >;
    }
    //else if( depth == CV_16U )
    else if( depth == 2 )
    {
        func = pyrDown_< FixPtCast<uint16_t, 8> >;
    }
    else
    {
        fprintf( stderr, "Unsupported Format" );
    }

    func( _src, _dst, borderType );
}
