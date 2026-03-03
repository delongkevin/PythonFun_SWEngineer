// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [05-Dec-2018]
// --- Last Modified by Joshua Teichroeb [17-Dec-2018]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __IMAGE__H_
#define __IMAGE__H_

#include "ImageType.h"
#include "ImageIterator.h"
#include "assert.h"

#ifdef __QNX__
    #include "meal/camera/core/inc/CameraPoint.h"
#else
    #include <Point.h>
#endif

struct Size2i
{
    int height;
    int width;
};

/*
* Defines a region of interest. Like opencv's 'Rect' class.
*/
namespace _roi
{
    class ROI
    {
    public:
        inline uint32_t getX() const
        {
            return x;
        }

        inline void setX( uint32_t x_val )
        {
            x = x_val;
        }
        inline uint32_t getY() const
        {
            return y;
        }
        inline void setY( uint32_t y_val )
        {
            y = y_val;
        }
        inline uint32_t getWidth() const
        {
            return width;
        }
        inline void setWidth( uint32_t width_val )
        {
            width = width_val;
        }
        inline uint32_t getHeight() const
        {
            return height;
        }
        inline void setHeight( uint32_t height_val )
        {
            height = height_val;
        }



        ROI();
        ROI( uint32_t i_x, uint32_t i_y, uint32_t i_width, uint32_t i_height );

        ROI operator|=( const ROI& other ) const;
        ROI operator&=( const ROI& other ) const;

    private:
        uint32_t x;
        uint32_t y;
        uint32_t width;
        uint32_t height;

    };
}

namespace image
{
    /**
    * Image type used to hold data regarding an image.
    */
    template <typename T>
    class Image
    {
    public:
        typedef _iterator::ImageIterator<T> iterator;
        typedef _iterator::RowIterator<T> row_iterator;
        typedef _iterator::ColumnIterator<T> col_iterator;

        // --- Public data
        inline uint32_t getWidth() const
        {
            return width;
        }

        inline uint32_t getHeight() const
        {
            return height;
        }

        inline uint32_t getStep() const
        {
            return step;
        }

        inline uint32_t getSize() const
        {
            return size;
        }
        inline T* getData() const
        {
            return data;
        }
        T* ptr( int y )
        {
            assert( y == 0 || ( data && numChannels >= 1 && ( unsigned )y < ( unsigned )step ) );
            return data + step * y;
        }
        inline uint32_t getNumChannels() const
        {
            return numChannels;
        }
        inline itype::eImageType getType() const
        {
            return type;
        }

        inline void setWidth( uint32_t width_val )
        {
            width = width_val;
        }

        inline void setHeight( uint32_t height_val )
        {
            height = height_val;
        }

        inline void setStep( uint32_t step_val )
        {
            step = step_val;
        }

        inline void setNumChannels( uint32_t numChannels_val )
        {
            numChannels = numChannels_val;
        }
        inline void setData( T* data_val )
        {
            data = data_val;
        }

        inline void setDataI( int32_t num, uint32_t i ) const
        {
            data[i] = static_cast<T>( num ); /* PRQA S 3706*/
        }

        inline void setSize( uint32_t size_val )
        {
            size = size_val;
        }

        inline const uint32_t* getWidthRef() const
        {
            return &width;
        }

        inline const uint32_t* getHeightRef() const
        {
            return &height;
        }

        inline  int16_t elemSize()
        {
            return sizeof( T ) / sizeof( uint8_t ) * numChannels;
        }




        // --- Constructors / Destructor
        Image( uint32_t i_width, uint32_t i_height, T* i_data, uint32_t i_numChannels, uint32_t i_step, itype::eImageType i_type );
        Image( uint32_t i_width, uint32_t i_height, T* i_data, uint32_t i_numChannels, uint32_t i_step );
        Image( uint32_t i_width, uint32_t i_height, T* i_data, uint32_t i_numChannels );
        explicit Image( itype::eImageType type );
        Image();
        virtual ~Image();

        // --- Data access
        T* at( uint32_t x, uint32_t y ) const;
        static T* at( row_iterator row_i, col_iterator col_i );

        // --- Other functions
        Image<T> subImage( uint32_t x, uint32_t y, uint32_t i_width, uint32_t i_height ) const;
        Image<T> subImage( _roi::ROI roi ) const;
        bool_t isContinuous() const;
        template <typename U>
        void get_dimensions_from( Image<U>& other );

        // --- Iterators
        inline iterator begin() const;
        inline iterator end() const;
        inline row_iterator row( int32_t n ) const;
        static inline col_iterator col( int32_t n );

        // --- Operators
        Image<T>& operator+= ( const T val );
        uint32_t element1 = 0;
        uint8_t* datastart = nullptr;
        uint8_t* dataend = nullptr;

    private:
        uint32_t    width;
        uint32_t    height;
        uint32_t    step;
        uint32_t    size;

        T*          data;
        uint32_t    numChannels;
        itype::eImageType  type;

    };

    // --- typedefs
    typedef Image<uint8_t> Image_u8;
    typedef Image<uint32_t> Image_u32;
    typedef Image<sint8_t> Image_s8;
    typedef Image<sint32_t> Image_s32;
    typedef Image<float32_t> Image_f32;
    typedef Image<float64_t> Image_f64;

    /*
    * Sub-class of image whose data pointer is null.
    *
    * Used like 'NULL' to make reading code easier.
    */
    template <typename T>
    class NullImage : public Image<T>
    {
#ifdef ME_PLATFORM_QNX
        T* data;
#endif
    public:
        NullImage() : Image<T>()
#ifdef ME_PLATFORM_QNX
            , data( NULL )
#endif
        {
        };
        virtual ~NullImage() {};
    };



    /**
    * Kernel type useful for filtering images.
    */
    template <typename T, uint32_t W, uint32_t H>
    class Kernel
    {
    public:


        // --- Constructors / Destructor
        Kernel();
        Kernel( uint32_t i_anchorX, uint32_t i_anchorY, const T* i_data );
        Kernel( uint32_t i_anchorX, uint32_t i_anchorY );

        // --- Operators
        template <typename U>
        Kernel<T, W, H>&  operator=( const Kernel<U, W, H>& other );
        Kernel<T, W, H>&  operator=( const Kernel<T, W, H>& other );

        // --- Other functions
        T sum();
        void normalize();
        const T& at( uint32_t x, uint32_t y ) const;
        T& at( uint32_t x, uint32_t y );
    private:
        uint32_t    width;
        uint32_t    height;
        Point2i     anchor;
        T           data[H][W];
    };

    ///------------------------------------------------------------------------------
    /// Image function definitions.
    ///------------------------------------------------------------------------------
}
/*
* Full constructor.
*/
template<typename T>
inline image::Image<T>::Image( uint32_t i_width, uint32_t i_height, T* i_data, uint32_t i_numChannels, uint32_t i_step, itype::eImageType i_type ) :
    width( i_width ),
    height( i_height ),
    step( i_step ),
    size( i_width * i_height * i_numChannels ),
    data( i_data ),
    numChannels( i_numChannels ),
    type( i_type )

{
}


template<typename T>
image::Image<T>::Image( uint32_t i_width, uint32_t i_height, T* i_data, uint32_t i_numChannels, uint32_t i_step ) :
    width( i_width ),
    height( i_height ),
    step( i_step ),
    size( i_width * i_height * i_numChannels ),
    data( i_data ),
    numChannels( i_numChannels ),
    type( itype::IMTP_ANY_TYPE )
{
}
/*
* Constructor with default step size.
*/
template<typename T>
inline image::Image<T>::Image( uint32_t i_width, uint32_t i_height, T* i_data, uint32_t i_numChannels ) :
    width( i_width ),
    height( i_height ),
    step( i_width * i_numChannels ),
    size( i_width * i_height * i_numChannels ),
    data( i_data ),
    numChannels( i_numChannels ),
    type( itype::IMTP_ANY_TYPE )
{
}

/*
* Constructor using image type definitions.
*/
template<typename T>
inline image::Image<T>::Image( itype::eImageType type ) :
    width( imtp::GetImageWidth( type ) ),
    height( imtp::GetImageHeight( type ) ),
    step( imtp::GetImageWidth( type ) * imtp::GetImageNumChannels( type ) ),
    size( imtp::GetImageWidth( type ) * imtp::GetImageHeight( type ) * imtp::GetImageNumChannels( type ) ),
    data( NULL ),
    numChannels( imtp::GetImageNumChannels( type ) ),
    type( type )
{
}

/*
* Default constructor.
*/
template<typename T>
image::Image<T>::Image() :
    width( 0 ),
    height( 0 ),
    step( 0 ),
    size( 0 ),
    data( NULL ),
    numChannels( 0 ),
    type( itype::IMTP_ANY_TYPE )
{
}

/*
* Destructor.
*/
template<typename T>
image::Image<T>::~Image()
{
}



/*
* Return pointer to pixel at row 'y' and column 'x'.
*/
template<typename T>
inline T* image::Image<T>::at( uint32_t x, uint32_t y ) const //added const
{
    T* dataPtr = &data[( y * step ) + x  * numChannels]; /* PRQA S 3706*/
    return dataPtr;
}

/*
* Return pointer to pixel using row and column iterators.
*/
template<typename T>
inline T* image::Image<T>::at( row_iterator row_i, col_iterator col_i )
{
    return row_i.ptr() + *col_i; //PRQA S 3705
}

/*
* Return a sub-image of this image. Shallow copy.
*/
template<typename T>
inline image::Image<T> image::Image<T>::subImage( uint32_t x, uint32_t y, uint32_t i_width, uint32_t i_height ) const
{
    image::Image<T> result = image::Image<T>( i_width, i_height, at( x, y ), numChannels, step );
    result.type = type;
    return result;
}

/*
* Return a sub-image of this image. Shallow copy.
*/
template<typename T>
inline image::Image<T> image::Image<T>::subImage( _roi::ROI roi ) const
{
    image::Image<T> result = image::Image<T>( roi.getWidth(), roi.getHeight(), at( roi.getX(), roi.getY() ), numChannels, step );
    result.type = type;
    return result;
}

/*
* Return 'true' if the data in this image is continuous, 'false' otherwise.
*/
template<typename T>
inline bool_t image::Image<T>::isContinuous() const
{
    return ( ( width * numChannels ) == step );
}

/*
* Copy the dimensions from the given image to this one.
*/
template<typename T>
template<typename U>
inline void image::Image<T>::get_dimensions_from( image::Image<U>& other )
{
    width = other.getWidth();
    height = other.getHeight();
    numChannels = other.getNumChannels();
}

/*
* Add 'val' to every pixel in this image.
*/
template<typename T>
inline image::Image<T>& image::Image<T>::operator+=( const T val )
{
    T* ptr = data;
    uint32_t n = 0;

    while( n < size )
    {
        ( *ptr ) += val;
        ++ptr;
        ++n;
    }
}

/*
* Get an iterator pointing to the first element of this image.
*/
template<typename T>
inline typename image::Image<T>::iterator image::Image<T>::begin() const
{
    return iterator( data, data, width * numChannels, step );
}

/*
* Get an iterator pointing past the last element of this image.
*/
template<typename T>
inline typename image::Image<T>::iterator image::Image<T>::end() const
{
    T* end_row = data + ( step * ( height ) );/*PRQA S 3705*/
    return iterator( end_row, end_row, width * numChannels, step );
}

/*
* Get a row iterator pointing to the n'th row.
*/
template<typename T>
inline typename image::Image<T>::row_iterator image::Image<T>::row( int32_t n ) const
{
    return row_iterator( data + step * n, n, step ); //PRQA S 3705
}

/*
* Get a column iterator pointing to the n'th column.
*/
template<typename T>
inline typename image::Image<T>::col_iterator image::Image<T>::col( int32_t n )
{
    return col_iterator( n );
}

///------------------------------------------------------------------------------
/// Kernel function definitions.
///------------------------------------------------------------------------------

/*
* Default constructor.
*/
template<typename T, uint32_t W, uint32_t H>
inline image::Kernel<T, W, H>::Kernel() :
    width( 0 ),
    height( 0 ),
    anchor( 0, 0 )
{
}

/*
* Constructor to initialize data in kernel to that of an array.
*/
template<typename T, uint32_t W, uint32_t H>
inline image::Kernel<T, W, H>::Kernel( uint32_t i_anchorX, uint32_t i_anchorY, const T* i_data ) :
    width( W ),
    height( H ),
    anchor( i_anchorX, i_anchorY )
{
    for( uint32_t y = 0; y < H; y++ )
    {
        for( uint32_t x = 0; x < W; x++ )
        {
            data[y][x] = static_cast<T>( i_data[y * W + x] );   /* PRQA S 3706*/
        }
    }
}

/*
* Constructor without data initializer.
*/
template<typename T, uint32_t W, uint32_t H>
inline image::Kernel<T, W, H>::Kernel( uint32_t i_anchorX, uint32_t i_anchorY ) :
    width( W ),
    height( H ),
    anchor( i_anchorX, i_anchorY )
{
}


/*
* Copy elements in the given kernel.
*/
template<typename T, uint32_t W, uint32_t H>
template<typename U>
inline image::Kernel<T, W, H>& image::Kernel<T, W, H>::operator=( const Kernel<U, W, H>& other )
{
    anchor = other.anchor;

    for( uint32_t y = 0; y < H; y++ )
    {
        for( uint32_t x = 0; x < W; x++ )
        {
            data[y][x] = ( T )( other.at( x, y ) );
        }
    }

    return *this;
}

/*
* Sum the elements in the kernel.
*/
template<typename T, uint32_t W, uint32_t H>
inline T image::Kernel<T, W, H>::sum()
{
    T* ptr = &data[0][0];
    T sum_i = 0;

    for( uint32_t i = 0; i < W * H; i++ )
    {
        sum_i += *ptr;
        ++ptr;
    }

    return sum;
}

/*
* Normalize the elements in the kernel.
*/
template<typename T, uint32_t W, uint32_t H>
inline void image::Kernel<T, W, H>::normalize()
{
    T* ptr = &data[0][0];
    T summation = ( T )0;

    for( uint32_t i = 0; i < W * H; i++ )
    {
        summation += ( T )abs( *ptr );
        ++ptr;
    }

    ptr = &data[0][0];

    for( uint32_t i = 0; i < W * H; i++ )
    {
        *ptr = ( *ptr ) / summation;
        ++ptr;
    }
}

/*
* Access value at row 'y' and column 'x'. (const)
*/
template<typename T, uint32_t W, uint32_t H>
inline const T& image::Kernel<T, W, H>::at( uint32_t x, uint32_t y ) const
{
    return data[y][x];
}

/*
* Access value at row 'y' and column 'x'.
*/
template<typename T, uint32_t W, uint32_t H>
inline T& image::Kernel<T, W, H>::at( uint32_t x, uint32_t y )
{
    return data[y][x];
}

#endif // !__IMAGE__H_
