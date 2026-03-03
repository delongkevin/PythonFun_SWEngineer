// ----------------------------------------------------------------------------
// --- Written by Sandip Suman Senapati [04-Feb-2025]
// ----------------------------------------------------------------------------
#pragma once
#ifndef TAD_PYRAMID_H
#define TAD_PYRAMID_H

#include "Utility.h"
#include "Image.h"
template<class CastOp>
struct PyramidDownInvoker
{
    PyramidDownInvoker( const image::Image<uint8_t>* src, const image::Image<uint8_t>* dst, int borderType, int** tabR, int** tabM, int** tabL );
    //{
    //    _src = src;
    //    _dst = dst;
    //    _borderType = borderType;
    //    _tabR = tabR;
    //    _tabM = tabM;
    //    _tabL = tabL;
    //}

    //void operator()(const Range& range) const CV_OVERRIDE;
    void sequenceOperation( const Range& range );

    int** _tabR;
    int** _tabM;
    int** _tabL;
    const image::Image<uint8_t>* _src;
    const image::Image<uint8_t>* _dst;
    int _borderType;
};


template<typename T1, typename T2, int cn> int PyrDownVecH( const T1*, T2*, int )
{
    //   row[x       ] = src[x * 2 + 2*cn  ] * 6 + (src[x * 2 +   cn  ] + src[x * 2 + 3*cn  ]) * 4 + src[x * 2       ] + src[x * 2 + 4*cn  ];
    //   row[x +    1] = src[x * 2 + 2*cn+1] * 6 + (src[x * 2 +   cn+1] + src[x * 2 + 3*cn+1]) * 4 + src[x * 2 +    1] + src[x * 2 + 4*cn+1];
    //   ....
    //   row[x + cn-1] = src[x * 2 + 3*cn-1] * 6 + (src[x * 2 + 2*cn-1] + src[x * 2 + 4*cn-1]) * 4 + src[x * 2 + cn-1] + src[x * 2 + 5*cn-1];
    return 0;
}

template<typename T1, typename T2> int PyrDownVecV( T1**, T2*, int )
{
    return 0;
}


template<class CastOp> void
pyrDown_( const image::Image<uint8_t>& _src, image::Image<uint8_t>& _dst, int borderType );

void pyramidDown( image::Image<uint8_t> src, image::Image<uint8_t> dst,
                  const size2i& dstsize = size2i(), int borderType = APP_BORDER_DEFAULT );

template<typename T, int shift> struct FixPtCast
{
    typedef int type1;
    typedef T rtype;
    rtype operator()( type1 arg ) const
    {
        return ( T )( ( arg + ( 1 << ( shift - 1 ) ) ) >> shift );
    }
};
typedef void( *PyrFunc )( const image::Image<uint8_t>&, image::Image<uint8_t>&, int );
#endif