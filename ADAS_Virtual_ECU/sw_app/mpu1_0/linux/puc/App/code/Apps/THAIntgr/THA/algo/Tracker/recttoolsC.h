/*
Author: Christian Bailer
Contact address: Christian.Bailer@dfki.de
Department Augmented Vision DFKI

                          License Agreement
               For Open Source Computer Vision Library
                       (3-clause BSD License)

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.

  * Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

  * Neither the names of the copyright holders nor the names of the contributors
    may be used to endorse or promote products derived from this software
    without specific prior written permission.

This software is provided by the copyright holders and contributors "as is" and
any express or implied warranties, including, but not limited to, the implied
warranties of merchantability and fitness for a particular purpose are disclaimed.
In no event shall copyright holders or contributors be liable for any direct,
indirect, incidental, special, exemplary, or consequential damages
(including, but not limited to, procurement of substitute goods or services;
loss of use, data, or profits; or business interruption) however caused
and on any theory of liability, whether in contract, strict liability,
or tort (including negligence or otherwise) arising in any way out of
the use of this software, even if advised of the possibility of such damage.
*/
#ifndef RECTTOOLSC_H
#define RECTTOOLSC_H

#ifdef _WIN32
    #include "Point.h"
#else
    #include "meal/camera/core/inc/CameraPoint.h"
#endif // _WIN32
#include "../common/THAParams.h"
namespace RectToolsC
{

    inline int32_t x2( const Recti& rect )
    {
        return rect.x + rect.width;
    }


    inline int32_t y2( const Recti& rect )
    {
        return rect.y + rect.height;
    }

    inline void limit( Recti& rect, Recti i_limit )
    {
        if( ( rect.x + rect.width ) > ( i_limit.x + i_limit.width ) )
        {
            rect.width = ( i_limit.x + i_limit.width - rect.x );
        }

        if( ( rect.y + rect.height ) > ( i_limit.y + i_limit.height ) )
        {
            rect.height = ( i_limit.y + i_limit.height - rect.y );
        }

        if( rect.x < i_limit.x )
        {
            rect.width -= ( i_limit.x - rect.x );
            rect.x = i_limit.x;
        }

        if( rect.y < i_limit.y )
        {
            rect.height -= ( i_limit.y - rect.y );
            rect.y = i_limit.y;
        }

        if( rect.width < 0 )
        {
            rect.width = 0;
        }

        if( rect.height < 0 )
        {
            rect.height = 0;
        }
    }


    inline Recti getBorder( const Recti& original, Recti& limited )
    {
        Recti res;
        res.x = limited.x - original.x;
        res.y = limited.y - original.y;
        res.width = x2( original ) - x2( limited );
        res.height = y2( original ) - y2( limited );
        Assert( ( res.x >= 0 ) && ( res.y >= 0 ) && ( res.width >= 0 ) && ( res.height >= 0 ) );
        return res;
    }

    inline mecl::core::Matrix<uint8_t, tha::ScaleWindowSize, tha::ScaleWindowSize, e_Default> subwindow_c( const mecl::core::Matrix<uint8_t, 400, 640, e_Default>& i_img, const Recti& window )
    {
        Recti cutWindow = window;
        RectToolsC::limit( cutWindow, Recti( 0, 0, i_img.cols, i_img.rows ) );

        if( ( cutWindow.height <= 0 ) || ( cutWindow.width <= 0 ) )
        {
            Assert( 0 );
        }

        Recti border = RectToolsC::getBorder( window, cutWindow );
        const uint32_t cutX = cutWindow.x;
        const uint32_t cutY = cutWindow.y;
        mecl::core::Matrix<uint8_t, tha::ScaleWindowSize, tha::ScaleWindowSize, e_Default> I1;
        I1 = i_img.subMatrix<tha::ScaleWindowSize, tha::ScaleWindowSize>( cutY, cutX );
        return I1;
    }

    inline Rectf Recti2Rectf_c( const Recti& in_Rect )
    {
        Rectf out_CVRect;
        out_CVRect.x = static_cast<float32_t>( in_Rect.x );
        out_CVRect.y = static_cast<float32_t>( in_Rect.y );
        out_CVRect.width = static_cast<float32_t>( in_Rect.width );
        out_CVRect.height = static_cast<float32_t>( in_Rect.height );
        return out_CVRect;
    }

    inline Recti Rectf2Recti_c( Rectf& in_CVRect )
    {
        Recti out_Rect;
        out_Rect.x = static_cast<int32_t>( in_CVRect.x + 0.5f );
        out_Rect.y = static_cast<int32_t>( in_CVRect.y + 0.5f );
        out_Rect.width = static_cast<int32_t>( in_CVRect.width + 0.5f );
        out_Rect.height = static_cast<int32_t>( in_CVRect.height + 0.5f );
        return out_Rect;
    }

}

#endif // !RECTTOOLSC_H


