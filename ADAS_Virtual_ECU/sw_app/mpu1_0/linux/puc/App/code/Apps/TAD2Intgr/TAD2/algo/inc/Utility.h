// ----------------------------------------------------------------------------
// --- Written by Sandip Suman Senapati [04-Feb-2025]
// ----------------------------------------------------------------------------

#ifndef TAD_UTILITY_H
#define TAD_UTILITY_H
#pragma once
#ifndef _WIN32
#include "meal/camera/core/inc/CameraPoint.h"
#else
#include "Point.h"
#include <windows.h>
#endif
#include "Image.h"
#include "ImageProcessing.h"
#define  CV_DESCALE(x,n)     (((x) + (1 << ((n)-1))) >> (n))
//#define MIN(a,b) ((a)<(b)?(a):(b))
//#define MAX(a,b) ((a)>(b)?(a):(b))
static inline int32_t max_int32( int32_t a, int32_t b )
{
    return ( a > b ) ? a : b;
}
static inline int32_t min_int32( int32_t a, int32_t b )
{
    return ( a < b ) ? a : b;
}


inline void swap_detail( void* p1, void* p2, void* tmp, size_t pSize )
{
    memcpy( tmp, p1, pSize );
    memcpy( p1, p2, pSize );
    memcpy( p2, tmp, pSize );
}
#define SWAP(a, b) swap_detail(&(a), &(b), (char[(sizeof(a) == sizeof(b)) ? (ptrdiff_t)sizeof(a) : -1]){0}, sizeof(a)

static inline size_t alinSize( size_t sz, int n )
{
    assert( ( n & ( n - 1 ) ) == 0 ); // n is a power of 2
    return ( sz + n - 1 ) & -n;
}
template<typename _Tp> static inline _Tp* alnPtr( _Tp* ptr, int n = ( int )sizeof( _Tp ) )
{
    assert( ( n & ( n - 1 ) ) == 0 ); // n is a power of 2
    return ( _Tp* )( ( ( size_t )ptr + n - 1 ) & -n );
}
template<typename T>
void swap_APP( T& x, T& y )
{
    T temp = x;
    x = y;
    y = temp;
}
template<typename T>
double sqrt_newton( T num )
{
    if( num < 0 )
    {
        return -1;    // Return -1 for negative numbers (error case)
    }

    double x = num;
    double y = 1.0;
    double epsilon = 0.000001; // Precision

    while( x - y > epsilon )
    {
        x = ( x + y ) / 2;
        y = num / x;
    }

    return x;
}
template < typename _Tp, size_t fixed_size = 1024 / sizeof( _Tp ) + 8 > class AutoBuffer

{
public:
    typedef _Tp value_type;

    //! the default constructor
    AutoBuffer();
    //! constructor taking the real buffer size
    explicit AutoBuffer( size_t _size );

    //! the copy constructor
    AutoBuffer( const AutoBuffer<_Tp, fixed_size>& buf );
    //! the assignment operator
    AutoBuffer<_Tp, fixed_size>& operator = ( const AutoBuffer<_Tp, fixed_size>& buf );

    //! destructor. calls deallocate()
    ~AutoBuffer();

    //! allocates the new buffer of size _size. if the _size is small enough, stack-allocated buffer is used
    void allocate( size_t _size );
    //! deallocates the buffer if it was dynamically allocated
    void deallocate();
    //! resizes the buffer and preserves the content
    void resize( size_t _size );
    //! returns the current buffer size
    size_t size() const;
    //! returns pointer to the real buffer, stack-allocated or heap-allocated
    inline _Tp* data()
    {
        return ptr;
    }
    //! returns read-only pointer to the real buffer, stack-allocated or heap-allocated
    inline const _Tp* data() const
    {
        return ptr;
    }

#if !defined(OPENCV_DISABLE_DEPRECATED_COMPATIBILITY) // use to .data() calls instead
    //! returns pointer to the real buffer, stack-allocated or heap-allocated
    operator _Tp* ()
    {
        return ptr;
    }
    //! returns read-only pointer to the real buffer, stack-allocated or heap-allocated
    operator const _Tp* () const
    {
        return ptr;
    }
#else
    //! returns a reference to the element at specified location. No bounds checking is performed in Release builds.
    inline _Tp& operator[]( size_t i )
    {
        CV_DbgCheckLT( i, sz, "out of range" );
        return ptr[i];
    }
    //! returns a reference to the element at specified location. No bounds checking is performed in Release builds.
    inline const _Tp& operator[]( size_t i ) const
    {
        CV_DbgCheckLT( i, sz, "out of range" );
        return ptr[i];
    }
#endif

protected:
    //! pointer to the real buffer, can point to buf if the buffer is small enough
    _Tp* ptr;
    //! size of the real buffer
    size_t sz;
    //! pre-allocated buffer. At least 1 element to confirm C++ standard requirements
    _Tp buf[( fixed_size > 0 ) ? fixed_size : 1];
};

template<typename _Tp, size_t fixed_size> inline
AutoBuffer<_Tp, fixed_size>::AutoBuffer()
{
    ptr = buf;
    sz = fixed_size;
}

template<typename _Tp, size_t fixed_size> inline
AutoBuffer<_Tp, fixed_size>::AutoBuffer( size_t _size )
{
    ptr = buf;
    sz = fixed_size;
    allocate( _size );
}

template<typename _Tp, size_t fixed_size> inline
AutoBuffer<_Tp, fixed_size>::AutoBuffer( const AutoBuffer<_Tp, fixed_size>& abuf )
{
    ptr = buf;
    sz = fixed_size;
    allocate( abuf.size() );

    for( size_t i = 0; i < sz; i++ )
    {
        ptr[i] = abuf.ptr[i];
    }
}

template<typename _Tp, size_t fixed_size> inline AutoBuffer<_Tp, fixed_size>&
AutoBuffer<_Tp, fixed_size>::operator = ( const AutoBuffer<_Tp, fixed_size>& abuf )
{
    if( this != &abuf )
    {
        deallocate();
        allocate( abuf.size() );

        for( size_t i = 0; i < sz; i++ )
        {
            ptr[i] = abuf.ptr[i];
        }
    }

    return *this;
}

template<typename _Tp, size_t fixed_size> inline
AutoBuffer<_Tp, fixed_size>::~AutoBuffer()
{
    deallocate();
}

template<typename _Tp, size_t fixed_size> inline void
AutoBuffer<_Tp, fixed_size>::allocate( size_t _size )
{
    if( _size <= sz )
    {
        sz = _size;
        return;
    }

    deallocate();
    sz = _size;

    if( _size > fixed_size )
    {
        ptr = new _Tp[_size];
    }
}

template<typename _Tp, size_t fixed_size> inline void
AutoBuffer<_Tp, fixed_size>::deallocate()
{
    if( ptr != buf )
    {
        delete[] ptr;
        ptr = buf;
        sz = fixed_size;
    }
}

template<typename _Tp, size_t fixed_size> inline void
AutoBuffer<_Tp, fixed_size>::resize( size_t _size )
{
    if( _size <= sz )
    {
        sz = _size;
        return;
    }

    size_t i, prevsize = sz, minsize = min_int32( prevsize, _size );
    _Tp* prevptr = ptr;
    ptr = _size > fixed_size ? new _Tp[_size] : buf;
    sz = _size;

    if( ptr != prevptr )
        for( i = 0; i < minsize; i++ )
        {
            ptr[i] = prevptr[i];
        }

    for( i = prevsize; i < _size; i++ )
    {
        ptr[i] = _Tp();
    }

    if( prevptr != buf )
    {
        delete[] prevptr;
    }
}

template<typename _Tp, size_t fixed_size> inline size_t
AutoBuffer<_Tp, fixed_size>::size() const
{
    return sz;
}


class  Range
{
public:
    Range();
    Range( int _start, int _end );
    int size() const;
    bool empty() const;
    static Range all();

    int start, end;
};

////////////////////////Range Class Start/////////////////////////////////
inline
Range::Range()
    : start( 0 ), end( 0 ) {}

inline
Range::Range( int _start, int _end )
    : start( _start ), end( _end ) {}

inline
int Range::size() const
{
    return end - start;
}

inline
bool Range::empty() const
{
    return start == end;
}

inline
Range Range::all()
{
    return Range( INT_MIN, INT_MAX );
}


static inline
bool operator == ( const Range& r1, const Range& r2 )
{
    return r1.start == r2.start && r1.end == r2.end;
}

static inline
bool operator != ( const Range& r1, const Range& r2 )
{
    return !( r1 == r2 );
}

static inline
bool operator !( const Range& r )
{
    return r.start == r.end;
}

static inline
Range operator & ( const Range& r1, const Range& r2 )
{
    Range r( max_int32( r1.start, r2.start ), min_int32( r1.end, r2.end ) );
    r.end = max_int32( r.end, r.start );
    return r;
}

static inline
Range& operator &= ( Range& r1, const Range& r2 )
{
    r1 = r1 & r2;
    return r1;
}

static inline
Range operator + ( const Range& r1, int delta )
{
    return Range( r1.start + delta, r1.end + delta );
}

static inline
Range operator + ( int delta, const Range& r1 )
{
    return Range( r1.start + delta, r1.end + delta );
}

static inline
Range operator - ( const Range& r1, int delta )
{
    return r1 + ( -delta );
}

////////////////////////Range Class End/////////////////////////////////

struct size2i
{
    int16_t height;
    int16_t width;
    size2i( int _width, int _height )
    {
        height = _height;
        width = _width;
    }
    size2i()
    {
        height = 0;
        width = 0;
    }
    inline bool empty() const
    {
        return width <= 0 || height <= 0;
    }
};
int brderInterpolate( int p, int len, int borderType );
void copyMakeConstBorder_8u( const uint8_t* src, size_t srcstep, size2i srcroi,
                             uint8_t* dst, size_t dststep, size2i dstroi,
                             int top, int left, int cn, const uint8_t* value );
void copyMakeBorder_8u( const uint8_t* src, size_t srcstep, size2i srcroi,
                        uint8_t* dst, size_t dststep, size2i dstroi,
                        int top, int left, int cn, int borderType );
void copyMkeBorder_16u( image::Image<int16_t> src, image::Image<int16_t> dst,
                        int top, int bottom, int left, int right,
                        int borderType );
void copyMkeBorder_8u( image::Image<uint8_t> _src, image::Image<uint8_t> _dst, int top, int bottom,
                       int left, int right, int borderType );
#endif // !TAD_UTILITY_H
