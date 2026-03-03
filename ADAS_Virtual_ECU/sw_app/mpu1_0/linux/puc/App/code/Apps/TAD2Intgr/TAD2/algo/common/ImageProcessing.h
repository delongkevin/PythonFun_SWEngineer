// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [18-Dec-2018]
// --- Last Modified by Joshua Teichroeb [18-Dec-2018]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __IMAGE_PROCESSING__H_
#define __IMAGE_PROCESSING__H_

#include "Defines.h"
#include "Image.h"
#ifdef DIAGNOSTICS
    #include "diag.h"
#endif
#include "MemoryPool.h"
#include <typeinfo>

#ifdef ENABLE_OPENCV
    #include "highgui/highgui.hpp"
    #include "imgcodecs.hpp"
    #include "imgproc/imgproc.hpp"
#endif // !ENABLE_OPENCV

namespace processing
{
    /**
    * Our own image processing library.
    */
    class ImageProcessing
    {
    public:
        template<typename T, typename U>
        static void Copy( const image::Image<T>& src, image::Image<U>& dst );
        template<typename T>
        static void Resize( image::Image<T> src, image::Image<T> dst );
        template<typename T>
        static void Clear( image::Image<T>& ip_image );
        template<typename cast_type, typename T>
        static void Norm( const image::Image<T>& src, image::Image<T>& dst, T high, T low = 0, T new_high = 255, T new_low = 0 );
        template<typename return_type, typename T>
        static return_type Mean( const image::Image<T>& ipm_image );
        template<typename return_type, typename T>
        static return_type Variance( const image::Image<T>& ipv_image );
        template<typename T, typename U, typename V>
        static void MatrixMultiply( const image::Image<T>& src1, const image::Image<U>& src2, image::Image<V>& dst );
        template<typename T>
        static void FindHighLow( const image::Image<T>& ipf_image, T* high, T* low );
        template<typename T>
        static void CalcHist( image::Image<T>& ipc_image, int32_t* hist, int32_t* hist_sum = nullptr );
        template<uint32_t kernel_size>
        const static image::Kernel<uint32_t, kernel_size, kernel_size>& Gaussian();
        static uint32_t GaussianSum( uint32_t kernelSize );
        template<uint32_t kernel_size, typename T>
        static void Blur( const image::Image<T>& src, image::Image<T>& dst );
        template<typename cast_type, typename T, typename U>
        static void Filter( const image::Image<T>& src, image::Image<U>& dst, U* kernel, uint8_t* anchor, uint8_t* kernelSize, bool_t normalize );
        template<typename cast_type, typename T, typename U, typename V, uint32_t kW, uint32_t kH>
        static void Filter( const  image::Image<T>& src, image::Image<U>& dst, const image::Kernel<V, kW, kH>& kernel, V kernelSum );
        template<typename cast_type, typename T, typename U, typename V>
        static void Filter( const image::Image<T>& src, image::Image<U>& dst, const image::Kernel<V, 3, 3>& kernel, V kernelSum );
        template<typename cast_type, typename T, typename U, typename V>
        static void Filter( const image::Image<T>& src, image::Image<U>& dst, const image::Kernel<V, 5, 5>& kernel, V kernelSum );
        template<typename T>
        static void WarpImage( const image::Image<T>& src, image::Image<T>& dst, Point2i centre, uint32_t radius, float32_t start_deg, float32_t end_deg, float32_t inc_deg );


#ifdef ENABLE_OPENCV
        template<typename T>
        static int32_t GetCVType( const image::Image<T>& image );
        template<typename T>
        static cv::Mat ConvertToCV( image::Image<T>& image );
        template<typename U, typename T>
        static void CopyToCV( const image::Image<T>& src, cv::Mat& dst );
        template<typename U, typename T>
        static void CopyFromCV( const  cv::Mat& src, image::Image<T>& dst );
#endif // !ENABLE_OPENCV

    private:

        const static image::Kernel<uint32_t, 3, 3> c_gauss3;
        const static image::Kernel<uint32_t, 5, 5> c_gauss5;
        const static image::Kernel<uint32_t, 7, 7> c_gauss7;
        const static uint32_t c_gauss3_sum;
        const static uint32_t c_gauss5_sum;
        const static uint32_t c_gauss7_sum;


        template<typename T, typename U>
        static void _CopySameSize( const image::Image<T>& src, image::Image<U>& dst );

    };
}

//------------------------------------------------------------------------------
// ImageProcessing template function definitions.
//------------------------------------------------------------------------------

template<typename T, typename U>
inline void processing::ImageProcessing::Copy( const image::Image<T>& src, image::Image<U>& dst )
{
#ifdef DIAGNOSTICS
    diag::start( "Copy" );
#endif

    if( ( dst.getWidth() == src.getWidth() ) && ( dst.getHeight() == src.getHeight() ) && ( dst.getNumChannels() == src.getNumChannels() ) && ( dst.getSize() == src.getSize() ) )
    {
        _CopySameSize<T>( src, dst );
    }
    else
    {
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
}

/*
 * Only works resizing to a smaller size, by an integer factor;
 *
 */
template<typename T>
inline void processing::ImageProcessing::Resize( image::Image<T> src, image::Image<T> dst )
{
#ifdef DIAGNOSTICS
    diag::start( "Resize" );
#endif
    typedef float32_t calc_type;
    uint32_t src_width = src.getWidth();
    uint32_t src_height = src.getHeight();
    uint32_t dst_width = dst.getWidth();
    uint32_t dst_height = dst.getHeight();
    uint32_t src_step = src.getStep();
    uint32_t dst_step = dst.getStep();
    T* src_ptr = src.getData();
    T* dst_ptr = dst.getData();
    float32_t x_factor = static_cast<float32_t>( src_width ) / static_cast<float32_t>( dst_width );
    float32_t y_factor = static_cast<float32_t>( src_height ) / static_cast<float32_t>( dst_height );
    float32_t src_y = y_factor / 2.0f - 0.5f;

    for( uint32_t dst_y = 0; dst_y < dst_height; dst_y++ )
    {
        float32_t src_x = x_factor / 2.0f - 0.5f;

        for( uint32_t dst_x = 0; dst_x < dst_width; dst_x++ )
        {
            /* PRQA S 3706*/ calc_type Ix1 = ( src_x - floor( src_x ) ) * static_cast<calc_type>( src_ptr[static_cast<int32_t>( floor( src_y ) ) * src_step + static_cast<int32_t>( floor( src_x ) )] ) + \
                                             /* PRQA S 3706*/( ceil( src_x ) - src_x ) * static_cast<calc_type>( src_ptr[static_cast<int32_t>( floor( src_y ) ) * src_step + static_cast<int32_t>( ceil( src_x ) )] );
            /* PRQA S 3706*/calc_type Ix2 = ( src_x - floor( src_x ) ) * static_cast<calc_type>( src_ptr[static_cast<int32_t>( ceil( src_y ) ) * src_step + static_cast<int32_t>( floor( src_x ) )] ) + \
                                            /* PRQA S 3706*/( ceil( src_x ) - src_x ) * static_cast<calc_type>( src_ptr[static_cast<int32_t>( ceil( src_y ) ) * src_step + static_cast<int32_t>( ceil( src_x ) )] );
            /* PRQA S 3706*/dst_ptr[dst_y * dst_step + dst_x] = static_cast<T>( ( src_y - floor( src_y ) ) * Ix1 + \
                    ( ceil( src_y ) - src_y ) * Ix2 );
        }

        src_x += x_factor;
        src_y += y_factor;
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
}

template<typename T>
inline void processing::ImageProcessing::Clear( image::Image<T>& ip_image )
{
#ifdef DIAGNOSTICS
    diag::start( "Clear" );
#endif

    if( ip_image.isContinuous() )
    {
        memset( ip_image.getData(), 0, ip_image.getSize() * sizeof( T ) );
    }
    else
    {
        T* ptr = ip_image.getData();

        for( uint32_t y = 0; y < ip_image.getHeight(); y++ )
        {
            memset( ptr, 0, ip_image.getWidth() * ip_image.getNumChannels() * sizeof( T ) );
            ptr += ip_image.getStep();
        }
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
}
template<typename cast_type, typename T>
inline void processing::ImageProcessing::Norm( const image::Image<T>& src, image::Image<T>& dst, T high, T low , T new_high, T new_low )
{
#ifdef DIAGNOSTICS
    diag::start( "Norm" );
#endif
    image::Image<T> temp;
    _iterator::ImageIterator<T> src_it;
    src_it = src.begin();
    _iterator::ImageIterator<T> dst_it;
    dst_it = dst.begin();

    if( src.data == dst.data )
    {
        temp = memory::MemoryPool::GetImage<T>( dst.type );
        dst_it = temp.begin();
    }

    cast_type a = ( cast_type )low;
    cast_type b = ( cast_type )( high - low );

    for( ; src_it.operator != ( src.end() ); ++src_it, ++dst_it )
    {
        *dst_it = ( T )( new_low + ( ( cast_type( *src_it ) - a ) / b ) * ( new_high - new_low ) );
    }

    if( temp.data != NULL )
    {
        _CopySameSize( temp, dst );
        memory::MemoryPool::ReleaseImage( temp );
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
}
template<typename return_type, typename T>
inline return_type processing::ImageProcessing::Mean( const image::Image<T>& ipm_image )
{
#ifdef DIAGNOSTICS
    diag::start( "Mean" );
#endif
    return_type sum = 0;
    _iterator::ImageIterator<T> it = ipm_image.begin();
    _iterator::ImageIterator<T> end = ipm_image.end();

    for( ; it.operator != ( end ); ++it )
    {
        sum += static_cast<float32_t>( *it );
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
    return sum / return_type( ipm_image.getSize() * ipm_image.getNumChannels() );
}
// --- Don't use
template<typename return_type, typename T>
inline return_type processing::ImageProcessing::Variance( const image::Image<T>& ipv_image )
{
#ifdef DIAGNOSTICS
    diag::start( "Variance" );
#endif
    return_type sum = 0;
    return_type sumSqrd = 0;
    uint32_t n = 0;

    for( _iterator::ImageIterator<T> it = ipv_image.begin(); it.operator != ( ipv_image.end() ); ++it )
    {
        sum += *it;
        sumSqrd += ( *it ) * ( *it );
        ++n;
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
    return ( sumSqrd - ( sum * sum ) / return_type( n ) ) / return_type( n );
}
template<typename T>
inline void processing::ImageProcessing::FindHighLow( const image::Image<T>& ipf_image, T* high, T* low )
{
#ifdef DIAGNOSTICS
    diag::start( "FindHighLow" );
#endif
    T v_high = *ipf_image.data;
    T v_low = v_high;

    for( _iterator::ImageIterator<T> it = ipf_image.begin(); it.operator != ( ipf_image.end() ); ++it )
    {
        if( *it > v_high )
        {
            v_high = *it;
        }

        if( *it < v_low )
        {
            v_low = *it;
        }
    }

    if( high )
    {
        *high = v_high;
    }

    if( low )
    {
        *low = v_low;
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
}
template<typename T>
inline void processing::ImageProcessing::CalcHist( image::Image<T>& ipc_image, int32_t* hist, int32_t* hist_sum )
{
#ifdef DIAGNOSTICS
    diag::start( "CalcHist" );
#endif
    const int32_t NGREY = 256;
    memset( hist, 0, sizeof( int32_t ) * NGREY );
    int32_t sum = ipc_image.size;

    for( _iterator::ImageIterator<T> it = ipc_image.begin(); it.operator != ( ipc_image.end() ); ++it )
    {
        if( ( int )( *it ) >= NGREY )
        {
            sum--; // throw away out-of-range pixels
        }
        else
        {
            hist[( int )( *it )]++;
        }
    }

    if( hist_sum )
    {
        *hist_sum = sum;
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
}
template<uint32_t kernel_size>
inline const image::Kernel<uint32_t, kernel_size, kernel_size>& processing::ImageProcessing::Gaussian()
{
    assert( 0 );
    return image::Kernel<uint32_t, kernel_size, kernel_size>();
}
template<>
inline const image::Kernel<uint32_t, 3, 3>& processing::ImageProcessing::Gaussian()
{
    return c_gauss3;
}
template<>
inline const image::Kernel<uint32_t, 5, 5>& processing::ImageProcessing::Gaussian()
{
    return c_gauss5;
}
template<>
inline const image::Kernel<uint32_t, 7, 7>& processing::ImageProcessing::Gaussian()
{
    return c_gauss7;
}
inline uint32_t processing::ImageProcessing::GaussianSum( uint32_t kernelSize )
{
    uint32_t ret_val = 0;

    switch( kernelSize )
    {
        case 3:
        {
            ret_val = c_gauss3_sum;
            break;
        }

        case 5:
        {
            ret_val = c_gauss5_sum;
            break;
        }

        case 7:
        {
            ret_val = c_gauss7_sum;
            break;
        }

        default:
        {
            break;
        }

        assert( 0 );
        ret_val = 1;
    }

    return ret_val;
}
template<uint32_t kernel_size, typename T>
inline void processing::ImageProcessing::Blur( const image::Image<T>& src, image::Image<T>& dst )
{
#ifdef DIAGNOSTICS
    diag::start( "Blur" );
#endif
    Filter( src, dst, Gaussian<kernel_size>(), GaussianSum( kernel_size ) );
#ifdef DIAGNOSTICS
    diag::stop();
#endif
}

template<typename cast_type, typename T, typename U, typename V, uint32_t kW, uint32_t kH>
inline void processing::ImageProcessing::Filter( const image::Image<T>& src, image::Image<U>& dst, const image::Kernel<V, kW, kH>& kernel, V kernelSum )
{
#ifdef DIAGNOSTICS
    diag::start( "Filter" );
#endif
    image::Image<U> temp;
    _iterator::RowIterator<T> dst_row = dst.row( 0 );
    _iterator::RowIterator<T> dst_col = dst.col( 0 );
    cast_type sum;

    if( kernelSum == 0 )
    {
        kernelSum = 1;
    }

    if( ( void* )src.data == ( void* )dst.data )
    {
        temp = memory::MemoryPool::GetImage<U>( dst.type );
        dst_row = temp.row( 0 );
        dst_col = temp.col( 0 );
    }

    for( uint32_t y = 0; y < src.height; ++y, ++dst_row )
    {
        dst_col = 0;

        for( uint32_t x = 0; x < src.width; ++x, ++dst_col )
        {
            sum = 0;

            for( uint8_t i = 0; i < kH; i++ )
            {
                for( uint8_t j = 0; j < kW; j++ )
                {
                    int32_t new_x = x - ( kernel.anchor.x - j );
                    int32_t new_y = y - ( kernel.anchor.y - i );

                    if( new_x < 0 )
                    {
                        new_x = 0;
                    }
                    else if( new_x >= src.width )
                    {
                        new_x = src.width - 1;
                    }

                    if( new_y < 0 )
                    {
                        new_y = 0;
                    }
                    else if( new_y >= src.height )
                    {
                        new_y = src.height - 1;
                    }

                    sum += cast_type( kernel.at( j, i ) ) * ( cast_type )( *( src.at( new_x, new_y ) ) );
                }
            }

            *dst.at( dst_row, dst_col ) = ( U )( sum ) / ( U )( kernelSum );
        }
    }

    if( temp.data != NULL )
    {
        _CopySameSize( temp, dst );
        memory::MemoryPool::ReleaseImage( temp );
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
}
template<typename cast_type, typename T, typename U, typename V>
inline void processing::ImageProcessing::Filter( const image::Image<T>& src, image::Image<U>& dst, const image::Kernel<V, 3, 3>& kernel, V kernelSum )
{
#ifdef DIAGNOSTICS
    diag::start( "Filter<3-3>" );
#endif

    if( kernel.anchor != Point2i( 1, 1 ) )
    {
        assert( 0 );
    }

    if( kernelSum == 0 )
    {
        kernelSum = 1;
    }

    image::Image<U> temp;
    U* dst_row = dst.data;
    T* src_row = src.data;
    int32_t dst_step = dst.step;
    int32_t src_step = src.step;

    if( ( void* )src.data == ( void* )dst.data )
    {
        temp = memory::MemoryPool::GetImage<U>( dst.type );
        dst_row = temp.data;
        dst_step = temp.step;
    }

    dst_row += dst_step + 1;
    src_row += src_step + 1;
    U* dst_ptr;
    T* src_ptr0;
    T* src_ptr1;
    T* src_ptr2;
    T* src_ptr3;
    T* src_ptr4;
    T* src_ptr5;
    T* src_ptr6;
    T* src_ptr7;
    T* src_ptr8;
    cast_type sum;

    for( uint32_t y = 1; y < src.height - 1; ++y )
    {
        dst_ptr = dst_row;
        src_ptr0 = src_row - src_step - 1;
        src_ptr1 = src_row - src_step;
        src_ptr2 = src_row - src_step + 1;
        src_ptr3 = src_row - 1;
        src_ptr4 = src_row;
        src_ptr5 = src_row + 1;
        src_ptr6 = src_row + src_step - 1;
        src_ptr7 = src_row + src_step;
        src_ptr8 = src_row + src_step + 1;

        for( uint32_t x = 1; x < src.width - 1; ++x )
        {
            sum = ( cast_type )( kernel.at( 0, 0 ) ) * ( *src_ptr0 ) + \
                  ( cast_type )( kernel.at( 1, 0 ) ) * ( *src_ptr1 ) + \
                  ( cast_type )( kernel.at( 2, 0 ) ) * ( *src_ptr2 ) + \
                  ( cast_type )( kernel.at( 0, 1 ) ) * ( *src_ptr3 ) + \
                  ( cast_type )( kernel.at( 1, 1 ) ) * ( *src_ptr4 ) + \
                  ( cast_type )( kernel.at( 2, 1 ) ) * ( *src_ptr5 ) + \
                  ( cast_type )( kernel.at( 0, 2 ) ) * ( *src_ptr6 ) + \
                  ( cast_type )( kernel.at( 1, 2 ) ) * ( *src_ptr7 ) + \
                  ( cast_type )( kernel.at( 2, 2 ) ) * ( *src_ptr8 );
            *dst_ptr = ( U )( sum ) / ( U )( kernelSum );
            ++dst_ptr;
            ++src_ptr0;
            ++src_ptr1;
            ++src_ptr2;
            ++src_ptr3;
            ++src_ptr4;
            ++src_ptr5;
            ++src_ptr6;
            ++src_ptr7;
            ++src_ptr8;
        }

        dst_row += dst_step;
        src_row += src_step;
    }

    if( temp.data != NULL )
    {
        _CopySameSize( temp, dst );
        memory::MemoryPool::ReleaseImage( temp );
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
}
template<typename cast_type, typename T, typename U, typename V>
inline void processing::ImageProcessing::Filter( const image::Image<T>& src, image::Image<U>& dst, const image::Kernel<V, 5, 5>& kernel, V kernelSum )
{
#ifdef DIAGNOSTICS
    diag::start( "Filter<5-5>" );
#endif

    if( kernel.anchor != Point2i( 2, 2 ) )
    {
        assert( 0 );
    }

    if( kernelSum == 0 )
    {
        kernelSum = 1;
    }

    image::Image<U> temp;
    U* dst_row = dst.data;
    T* src_row = src.data;
    int32_t dst_step = dst.step;
    int32_t src_step = src.step;

    if( ( void* )src.data == ( void* )dst.data )
    {
        temp = memory::MemoryPool::GetImage<U>( dst.type );
        dst_row = temp.data;
        dst_step = temp.step;
    }

    dst_row += dst_step + dst_step + 2;
    src_row += src_step + src_step + 2;
    U* dst_ptr;
    T* src_ptr0;
    T* src_ptr1;
    T* src_ptr2;
    T* src_ptr3;
    T* src_ptr4;
    T* src_ptr5;
    T* src_ptr6;
    T* src_ptr7;
    T* src_ptr8;
    T* src_ptr9;
    T* src_ptr10;
    T* src_ptr11;
    T* src_ptr12;
    T* src_ptr13;
    T* src_ptr14;
    T* src_ptr15;
    T* src_ptr16;
    T* src_ptr17;
    T* src_ptr18;
    T* src_ptr19;
    T* src_ptr20;
    T* src_ptr21;
    T* src_ptr22;
    T* src_ptr23;
    T* src_ptr24;
    cast_type sum;

    for( uint32_t y = 2; y < src.height - 2; ++y )
    {
        dst_ptr = dst_row;
        src_ptr0 = src_row - src_step - src_step - 2;
        src_ptr1 = src_row - src_step - src_step - 1;
        src_ptr2 = src_row - src_step - src_step;
        src_ptr3 = src_row - src_step - src_step + 1;
        src_ptr4 = src_row - src_step - src_step + 2;
        src_ptr5 = src_row - src_step - 2;
        src_ptr6 = src_row - src_step - 1;
        src_ptr7 = src_row - src_step;
        src_ptr8 = src_row - src_step + 1;
        src_ptr9 = src_row - src_step + 2;
        src_ptr10 = src_row - 2;
        src_ptr11 = src_row - 1;
        src_ptr12 = src_row;
        src_ptr13 = src_row + 1;
        src_ptr14 = src_row + 2;
        src_ptr15 = src_row + src_step - 2;
        src_ptr16 = src_row + src_step - 1;
        src_ptr17 = src_row + src_step;
        src_ptr18 = src_row + src_step + 1;
        src_ptr19 = src_row + src_step + 2;
        src_ptr20 = src_row + src_step + src_step - 2;
        src_ptr21 = src_row + src_step + src_step - 1;
        src_ptr22 = src_row + src_step + src_step;
        src_ptr23 = src_row + src_step + src_step + 1;
        src_ptr24 = src_row + src_step + src_step + 2;

        for( uint32_t x = 2; x < src.width - 2; ++x )
        {
            sum = ( cast_type )( kernel.at( 0, 0 ) ) * ( *src_ptr0 ) + \
                  ( cast_type )( kernel.at( 1, 0 ) ) * ( *src_ptr1 ) + \
                  ( cast_type )( kernel.at( 2, 0 ) ) * ( *src_ptr2 ) + \
                  ( cast_type )( kernel.at( 3, 0 ) ) * ( *src_ptr3 ) + \
                  ( cast_type )( kernel.at( 4, 0 ) ) * ( *src_ptr4 ) + \
                  ( cast_type )( kernel.at( 0, 1 ) ) * ( *src_ptr5 ) + \
                  ( cast_type )( kernel.at( 1, 1 ) ) * ( *src_ptr6 ) + \
                  ( cast_type )( kernel.at( 2, 1 ) ) * ( *src_ptr7 ) + \
                  ( cast_type )( kernel.at( 3, 1 ) ) * ( *src_ptr8 ) + \
                  ( cast_type )( kernel.at( 4, 1 ) ) * ( *src_ptr9 ) + \
                  ( cast_type )( kernel.at( 0, 2 ) ) * ( *src_ptr10 ) + \
                  ( cast_type )( kernel.at( 1, 2 ) ) * ( *src_ptr11 ) + \
                  ( cast_type )( kernel.at( 2, 2 ) ) * ( *src_ptr12 ) + \
                  ( cast_type )( kernel.at( 3, 2 ) ) * ( *src_ptr13 ) + \
                  ( cast_type )( kernel.at( 4, 2 ) ) * ( *src_ptr14 ) + \
                  ( cast_type )( kernel.at( 0, 3 ) ) * ( *src_ptr15 ) + \
                  ( cast_type )( kernel.at( 1, 3 ) ) * ( *src_ptr16 ) + \
                  ( cast_type )( kernel.at( 2, 3 ) ) * ( *src_ptr17 ) + \
                  ( cast_type )( kernel.at( 3, 3 ) ) * ( *src_ptr18 ) + \
                  ( cast_type )( kernel.at( 4, 3 ) ) * ( *src_ptr19 ) + \
                  ( cast_type )( kernel.at( 0, 4 ) ) * ( *src_ptr20 ) + \
                  ( cast_type )( kernel.at( 1, 4 ) ) * ( *src_ptr21 ) + \
                  ( cast_type )( kernel.at( 2, 4 ) ) * ( *src_ptr22 ) + \
                  ( cast_type )( kernel.at( 3, 4 ) ) * ( *src_ptr23 ) + \
                  ( cast_type )( kernel.at( 4, 4 ) ) * ( *src_ptr24 );
            *dst_ptr = ( U )( sum ) / ( U )( kernelSum );
            ++dst_ptr;
            ++src_ptr0;
            ++src_ptr1;
            ++src_ptr2;
            ++src_ptr3;
            ++src_ptr4;
            ++src_ptr5;
            ++src_ptr6;
            ++src_ptr7;
            ++src_ptr8;
            ++src_ptr9;
            ++src_ptr10;
            ++src_ptr11;
            ++src_ptr12;
            ++src_ptr13;
            ++src_ptr14;
            ++src_ptr15;
            ++src_ptr16;
            ++src_ptr17;
            ++src_ptr18;
            ++src_ptr19;
            ++src_ptr20;
            ++src_ptr21;
            ++src_ptr22;
            ++src_ptr23;
            ++src_ptr24;
        }

        dst_row += dst_step;
        src_row += src_step;
    }

    if( temp.data != NULL )
    {
        _CopySameSize( temp, dst );
        memory::MemoryPool::ReleaseImage( temp );
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
}
template<typename T>
inline void processing::ImageProcessing::WarpImage( const image::Image<T>& src, image::Image<T>& dst, Point2i centre, uint32_t radius, float32_t start_deg, float32_t end_deg, float32_t inc_deg )
{
#ifdef DIAGNOSTICS
    diag::start( "WarpImage" );
#endif

    if( start_deg > end_deg )
    {
        float32_t temp = start_deg;
        start_deg = end_deg;
        end_deg = temp;
    }

    if( ( end_deg - start_deg ) / inc_deg > dst.width || radius > dst.height )
    {
        assert( 0 );
    }

    image::Image<T> temp;
    T* dst_ptr = dst.data;
    T* dst_ptr_row = dst.data;

    if( src.data == dst.data )
    {
        temp = memory::MemoryPool::GetImage<T>( dst.type );
        dst_ptr = temp.data;
    }

    for( uint32_t r = 0; r < radius; r++ )
    {
        for( float32_t angle = end_deg; angle > start_deg; angle -= inc_deg )
        {
            float32_t angle_rad = ( float32_t )mecl::math::toRadians_x( angle );
            uint32_t x = centre.x + ( uint32_t )( r * mecl::math::trigonometry<float32_t>::cos_x( angle_rad ) + 0.5f );
            uint32_t y = centre.y + ( uint32_t )( r * mecl::math::trigonometry<float32_t>::sin_x( angle_rad ) + 0.5f );

            if( 0 <= x && x < src.width && 0 <= y && y < src.height )
            {
                *dst_ptr = *src.at( x, y );
            }
            else
            {
                *dst_ptr = ( T )0;
            }

            ++dst_ptr;
        }

        dst_ptr_row += dst.step;
        dst_ptr = dst_ptr_row;
    }

    if( temp.data != NULL )
    {
        _CopySameSize( temp, dst );
        memory::MemoryPool::ReleaseImage( temp );
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
}
#ifdef ENABLE_OPENCV
template<typename T>
inline int32_t processing::ImageProcessing::GetCVType( const image::Image<T>& image )
{
    switch( image.getType() )
    {
        case itype::IMTP_400x640_F32C1:
        case itype::IMTP_Template_F32C1:
        case itype::IMTP_TopView_F32C1:
            return CV_32FC1;

        case itype::IMTP_400x640_U32C1:
        case itype::IMTP_Template_U32C1:
        case itype::IMTP_TopView_U32C1:
            return -1;

        case itype::IMTP_400x640_U8C1:
        case itype::IMTP_Template_U8C1:
        case itype::IMTP_TopView_U8C1:
            return CV_8UC1;

        case itype::IMTP_400x640_U8C3:
        case itype::IMTP_Template_U8C3:
        case itype::IMTP_TopView_U8C3:
            return CV_8UC3;

        case itype::IMTP_400x640_S32C1:
        case itype::IMTP_Template_S32C1:
        case itype::IMTP_TopView_S32C1:
            return CV_32SC1;

        case itype::IMTP_MAX_TYPES:
        case itype::IMTP_ANY_TYPE:
            if( image.getNumChannels() == 1 )
            {
                if( typeid( T ) == typeid( float32_t ) )
                {
                    return CV_32FC1;
                }
                else if( typeid( T ) == typeid( uint32_t ) )
                {
                    return -1;
                }
                else if( typeid( T ) == typeid( uint8_t ) )
                {
                    return CV_8UC1;
                }
                else if( typeid( T ) == typeid( sint32_t ) )
                {
                    return CV_32SC1;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                return -1;
            }
    }

    return -1;
}
template<typename T>
inline cv::Mat processing::ImageProcessing::ConvertToCV( image::Image<T>& image )
{
    return cv::Mat( cv::Size( image.getWidth(), image.getHeight() ), GetCVType( image ), image.getData(), image.getStep() * sizeof( T ) );
}
template<typename U, typename T>
inline void processing::ImageProcessing::CopyToCV( const  image::Image<T>& src, cv::Mat& dst )
{
#ifdef DIAGNOSTICS
    diag::start( "CopyToCV" );
#endif

    if( dst.data == NULL )
    {
        dst = cv::Mat( src.getHeight(), src.getWidth(), GetCVType( src ) );
    }

    U* dst_ptr = dst.ptr<U>();

    for( image::Image<T>::iterator src_it = src.begin(); src_it != src.end(); src_it += src.getNumChannels() )
    {
        if( src.getNumChannels() == 1 )
        {
            for( int i = 0; i < dst.channels(); i++ )
            {
                dst_ptr[i] = ( U ) * src_it;
            }
        }
        else if( ( int )src.getNumChannels() <= dst.channels() )
        {
            int i;

            for( i = 0; i < ( int )src.getNumChannels(); i++ )
            {
                dst_ptr[i] = ( U )src_it[i];
            }

            for( ; i < dst.channels(); i++ )
            {
                dst_ptr[i] = ( U )0;
            }
        }
        else
        {
            U sum = 0;

            for( int i = 0; i < ( int )src.getNumChannels(); i++ )
            {
                sum += ( U )src_it[i];
            }

            sum /= ( U )src.getNumChannels();

            for( int i = 0; i < dst.channels(); i++ )
            {
                dst_ptr[i] = sum;
            }
        }

        dst_ptr += dst.channels();
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
}
template<typename U, typename T>
inline void processing::ImageProcessing::CopyFromCV( const cv::Mat& src, image::Image<T>& dst )
{
#ifdef DIAGNOSTICS
    diag::start( "CopyFromCV" );
#endif
    image::Image<T>::iterator dst_it = dst.begin();
    image::Image<T>::iterator dst_end = dst.end();

    if( src.channels() != ( int )dst.getNumChannels() )
    {
        assert( 0 );
    }

    int numChannels = dst.getNumChannels();

    switch( numChannels )
    {
        case 1:
        {
            cv::MatConstIterator_<U> src_it = src.begin<U>();

            for( ; dst_it < dst_end; ++dst_it, ++src_it )
            {
                *dst_it = ( T )( *src_it );
            }

            break;
        }

        case 3:
        {
            std::vector<cv::Mat> three_channels( 3 );
            cv::split( src, three_channels );
            cv::MatConstIterator_<U> src0_it = three_channels[0].begin<U>();
            cv::MatConstIterator_<U> src1_it = three_channels[1].begin<U>();
            cv::MatConstIterator_<U> src2_it = three_channels[2].begin<U>();

            for( ; dst_it < dst_end; dst_it += 3, ++src0_it, ++src1_it, ++src2_it )
            {
                dst_it[0] = ( T )( *src0_it );
                dst_it[1] = ( T )( *src1_it );
                dst_it[2] = ( T )( *src2_it );
            }

            break;
        }

        default:
            assert( 0 );
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
}
#endif // !ENABLE_OPENCV
template<typename T, typename U>
inline void processing::ImageProcessing::_CopySameSize( const image::Image<T>& src, image::Image<U>& dst )
{
#ifdef DIAGNOSTICS
    diag::start( "_CopySameSize" );
#endif

    if( typeid( T ) == typeid( U ) )
    {
        if( src.isContinuous() && dst.isContinuous() )
        {
            memcpy( dst.getData(), src.getData(), src.getSize() * sizeof( T ) );
        }
        else
        {
            T* src_row = src.getData();
            U* dst_row = dst.getData();

            for( uint32_t y = 0; y < src.getHeight(); y++ )
            {
                memcpy( dst_row, src_row, src.getWidth() * src.getNumChannels() * sizeof( T ) );
                src_row += src.getStep();
                dst_row += dst.getStep();
            }
        }
    }
    else
    {
        _iterator::ImageIterator<T> src_it = src.begin();
        _iterator::ImageIterator<T> src_end = src.end();
        _iterator::ImageIterator<U> dst_it = dst.begin();

        for( ; src_it.operator < ( src_end ); ++src_it )
        {
            *dst_it = static_cast<U>( ( *src_it ) );
            ++dst_it;
        }
    }

#ifdef DIAGNOSTICS
    diag::stop();
#endif
}
#endif // !__IMAGE_PROCESSING__H_