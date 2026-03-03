// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [19-Mar-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <mecl/mecl.h>

/*
* A circular buffer.
*
* Has a fixed size and always overwrites the oldest element in the buffer when
* inerting an element after the buffer has been filled.
*/
namespace buffer
{
    template<typename T, uint32_t c_size>
    class CircularBuffer
    {
    public:
        CircularBuffer();
        ~CircularBuffer();

        // --- Action functions
        void push( T element );
        T pop();
        void clear();

        // --- Operators
        T& operator[]( uint32_t i );
        T operator[]( uint32_t i ) const;

        // --- Getters
        static uint32_t size();
        uint32_t fill() const;
        bool_t empty();
        bool_t full();

    private:
        T m_data[c_size + 1];
        uint32_t m_begin;
        uint32_t m_end;

        // --- Private functions
        static void indInc( uint32_t& ind );

    };
}

///------------------------------------------------------------------------------
/// CircularBuffer template function definitions.
///------------------------------------------------------------------------------

/*
* Constructor.
*/
template<typename T, uint32_t c_size>
inline buffer::CircularBuffer<T, c_size>::CircularBuffer() :
    m_begin( 0 ),
    m_end( 0 )
{
}

/*
* Destructor.
*/
template<typename T, uint32_t c_size>
inline buffer::CircularBuffer<T, c_size>::~CircularBuffer()
{
}

/*
* Push an element to the back of the buffer.
*/
template<typename T, uint32_t c_size>
inline void buffer::CircularBuffer<T, c_size>::push( T element )
{
    m_data[m_end] = element;
    indInc( m_end );

    if( m_end == m_begin )
    {
        indInc( m_begin );
    }
}

/*
* Pop an element from the front of the buffer.
*/
template<typename T, uint32_t c_size>
inline T buffer::CircularBuffer<T, c_size>::pop()
{
    if( empty() )
    {
        assert( 0 );
    }

    T result = m_data[m_begin];
    indInc( m_begin );
    return result;
}

/*
* Clear the buffer.
*/
template<typename T, uint32_t c_size>
inline void buffer::CircularBuffer<T, c_size>::clear()
{
    m_begin = 0;
    m_end = 0;
}

/*
* Element access.
*/
template<typename T, uint32_t c_size>
inline T& buffer::CircularBuffer<T, c_size>::operator[]( uint32_t i )
{
    if( i >= fill() )
    {
        assert( 0 );
    }

    return m_data[( m_begin + i ) % ( c_size + 1 )];
}

/*
* Element access. (const)
*/
template<typename T, uint32_t c_size>
inline T buffer::CircularBuffer<T, c_size>::operator[]( uint32_t i ) const
{
    if( i >= fill() )
    {
        assert( 0 );
    }

    return m_data[( m_begin + i ) % ( c_size + 1 )];
}

/*
* Get the max size of the buffer.
*/
template<typename T, uint32_t c_size>
inline uint32_t buffer::CircularBuffer<T, c_size>::size()
{
    return c_size;
}

/*
* Get the number of elements currently in the buffer.
*/
template<typename T, uint32_t c_size>
inline uint32_t buffer::CircularBuffer<T, c_size>::fill() const
{
    uint32_t ret_val;

    if( m_end >= m_begin )
    {
        ret_val = m_end - m_begin;
    }
    else
    {
        ret_val = m_end + c_size + 1 - m_begin;
    }

    return ret_val;
}

/*
* Return whether or not the buffer is empty.
*/
template<typename T, uint32_t c_size>
inline bool_t buffer::CircularBuffer<T, c_size>::empty()
{
    return m_end == m_begin;
}

/*
* Return whether or not the buffer is full.
*/
template<typename T, uint32_t c_size>
inline bool_t buffer::CircularBuffer<T, c_size>::full()
{
    uint32_t temp = m_end;
    indInc( temp );
    return temp == m_begin;
}

/*
* Increment the given index, looping around to the front if out of bounds.
*/
template<typename T, uint32_t c_size>
inline void buffer::CircularBuffer<T, c_size>::indInc( uint32_t& ind )
{
    if( ind == c_size )
    {
        ind = 0;
    }
    else
    {
        ind++;
    }
}

#endif // !CIRCULAR_BUFFER_H
