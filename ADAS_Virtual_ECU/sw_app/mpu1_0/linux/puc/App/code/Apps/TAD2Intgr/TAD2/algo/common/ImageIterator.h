// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [23-Jan-2019]
// --- Last Modified by Joshua Teichroeb [23-Jan-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __IMAGE_ITERATOR__H_
#define __IMAGE_ITERATOR__H_

namespace _iterator
{
    /**
    * Iterator to iterate over all data in an image in any order.
    */
    template <typename T>
    class ImageIterator
    {
    public:
        explicit ImageIterator( T* i_row, T* i_pos, uint32_t i_width, uint32_t i_step );
        ~ImageIterator();

        inline ImageIterator<T>&   operator= ( const ImageIterator<T>& other );

        inline bool_t              operator== ( const ImageIterator<T>& other ) const;
        inline bool_t              operator!= ( const ImageIterator<T>& other ) const;
        inline bool_t              operator< ( const ImageIterator<T>& other ) const;
        inline bool_t              operator<= ( const ImageIterator<T>& other ) const;
        inline bool_t              operator> ( const ImageIterator<T>& other ) const;
        inline bool_t              operator>= ( const ImageIterator<T>& other ) const;

        inline ImageIterator<T>&   operator+= ( int32_t n );
        inline ImageIterator<T>&   operator-= ( int32_t n );
        inline ImageIterator<T>&   operator++ (); // Pre
        inline ImageIterator<T>&   operator-- (); // Pre
        inline ImageIterator<T>    operator++ ( const int32_t ); // Post
        inline ImageIterator<T>    operator-- ( const int32_t ); // Post
        inline ImageIterator<T>    operator+ ( int32_t n ) const;
        inline ImageIterator<T>    operator- ( int32_t n ) const;
        inline int32_t             operator- ( const ImageIterator<T>& other ) const;

        inline T&            operator* () const;
        inline T*                  operator-> ();
        inline const T&            operator[]( const int32_t i ) const;
        inline T&                  operator[]( const int32_t i );

        inline T*                  pos() const;

    private:
        T* _row;
        T* _pos;
        int32_t _x;
        int32_t _step;
        int32_t _width;

    };

    /**
    * Iterator to iterate over the rows of an image.
    */
    template <typename T>
    class RowIterator
    {
    public:
        explicit RowIterator( T* ptr_i, int32_t i_row, int32_t i_step );
        RowIterator();
        ~RowIterator();

        inline RowIterator<T>&  operator= ( const RowIterator<T>& other );
        inline RowIterator<T>&  operator= ( const int32_t n );

        inline bool_t           operator== ( const int32_t n ) const;
        inline bool_t           operator== ( const RowIterator<T>& other ) const;
        inline bool_t           operator!= ( const int32_t n ) const ;
        inline bool_t           operator!= ( const RowIterator<T>& other ) const;
        inline bool_t           operator< ( const int32_t n ) const;
        inline bool_t           operator< ( const RowIterator<T>& other ) const;
        inline bool_t           operator<= ( const int32_t n ) const;
        inline bool_t           operator<= ( const RowIterator<T>& other ) const;
        inline bool_t           operator> ( const int32_t n ) const;
        inline bool_t           operator> ( const RowIterator<T>& other )const;
        inline bool_t           operator>= ( const int32_t n ) const;
        inline bool_t           operator>= ( const RowIterator<T>& other ) const;

        inline RowIterator<T>&  operator+= ( const int32_t n );
        inline RowIterator<T>&  operator-= ( const int32_t n );
        inline RowIterator<T>&  operator++ (); // Pre
        inline RowIterator<T>&  operator-- (); // Pre
        inline RowIterator<T>   operator++ ( const int32_t ); // Post
        inline RowIterator<T>   operator-- ( const int32_t ); // Post
        inline RowIterator<T>   operator+ ( const int32_t n ) const;
        inline RowIterator<T>   operator- ( const int32_t n ) const;


        inline int32_t          operator* () const;
        inline T*               ptr() const;

    private:
        T* _ptr;
        int32_t _row;
        int32_t _step;

    };

    /**
    * Iterator to iterate over the columns of an image.
    */
    template <typename T>
    class ColumnIterator
    {
    public:
        explicit ColumnIterator( int32_t i_col );
        ColumnIterator();
        ~ColumnIterator();

        inline ColumnIterator<T>&   operator= ( const ColumnIterator<T>& other );
        inline ColumnIterator<T>&   operator= ( const int32_t n );

        inline bool_t               operator== ( const int32_t n ) const;
        inline bool_t               operator== ( const ColumnIterator<T>& other ) const;
        inline bool_t               operator!= ( const int32_t n ) const;
        inline bool_t               operator!= ( const ColumnIterator<T>& other ) const;
        inline bool_t               operator< ( const int32_t n ) const;
        inline bool_t               operator< ( const ColumnIterator<T>& other )  const;
        inline bool_t               operator<= ( const int32_t n ) const;
        inline bool_t               operator<= ( const ColumnIterator<T>& other ) const;
        inline bool_t               operator> ( const int32_t n ) const;
        inline bool_t               operator> ( const ColumnIterator<T>& other )const;
        inline bool_t               operator>= ( const int32_t n ) const;
        inline bool_t               operator>= ( const ColumnIterator<T>& other ) const;

        inline ColumnIterator<T>&   operator+= ( const int32_t n );
        inline ColumnIterator<T>&   operator-= ( const int32_t n );
        inline ColumnIterator<T>&   operator++ (); // Pre
        inline ColumnIterator<T>&   operator-- (); // Pre
        inline ColumnIterator<T>    operator++ ( const int32_t ); // Post
        inline ColumnIterator<T>    operator-- ( const int32_t ); // Post
        inline ColumnIterator<T>    operator+ ( const int32_t n ) const;
        inline ColumnIterator<T>    operator- ( const int32_t n ) const;

        inline int32_t              operator* () const;

    private:
        int32_t _col;

    };
}

///------------------------------------------------------------------------------
/// ImageIterator function definitions.
///------------------------------------------------------------------------------


/*
* Constructor.
*/
template<typename T>
inline _iterator::ImageIterator<T>::ImageIterator( T* i_row, T* i_pos, uint32_t i_width, uint32_t i_step ) :
    _row( i_row ),
    _pos( i_pos ),
    _x( i_pos - i_row ),/*PRQA S 3705*/
    _step( i_step ),
    _width( i_width )
{
}

/*
* Destructor.
*/
template<typename T>
inline _iterator::ImageIterator<T>::~ImageIterator()
{
}

/*
* Compare equaltiy.
*/
template<typename T>
inline bool_t _iterator::ImageIterator<T>::operator==( const _iterator::ImageIterator<T>& other ) const
{
    return ( _pos == other._pos );
}

/*
* Compare inequaltiy.
*/
template<typename T>
inline bool_t _iterator::ImageIterator<T>::operator!=( const _iterator::ImageIterator<T>& other ) const
{
    return ( _pos != other._pos );
}

/*
* Compare less than.
*/
template<typename T>
inline bool_t _iterator::ImageIterator<T>::operator<( const _iterator::ImageIterator<T>& other ) const
{
    return ( _pos < other._pos );
}

/*
* Compare less than or equal.
*/
template<typename T>
inline bool_t _iterator::ImageIterator<T>::operator<=( const _iterator::ImageIterator<T>& other ) const
{
    return ( _pos <= other._pos );
}

/*
* Compare greater than.
*/
template<typename T>
inline bool_t _iterator::ImageIterator<T>::operator>( const _iterator::ImageIterator<T>& other ) const
{
    return ( _pos > other._pos );
}

/*
* Compare greater than or equal.
*/
template<typename T>
inline bool_t _iterator::ImageIterator<T>::operator>=( const _iterator::ImageIterator<T>& other ) const
{
    return ( _pos >= other._pos );
}

/*
* Increment by an integer number of pixels.
*/
template<typename T>
inline _iterator::ImageIterator<T>& _iterator::ImageIterator<T>::operator+=( int32_t n )
{
    int32_t remaining = _width - _x;

    while( remaining <= n )
    {
        _row += _step;
        n -= remaining;
        _x = 0;
        remaining = _width;
    }

    _x += n;
    _pos = _row + _x;
    return ( *this );
}

/*
* Decrement by an integer number of pixels.
*/
template<typename T>
inline _iterator::ImageIterator<T>& _iterator::ImageIterator<T>::operator-=( int32_t n )
{
    int32_t remaining = _x;

    while( remaining <= n )
    {
        _row -= _step;
        n -= remaining;
        _x = _width - 1;
        remaining = _width;
    }

    _x -= n;
    _pos = _row + _x;
    return ( *this );
}

/*
* Prefix increment one pixel.
*/
template<typename T>
inline _iterator::ImageIterator<T>& _iterator::ImageIterator<T>::operator++()
{
    ++_pos;
    ++_x;

    if( _x == _width )
    {
        _row += _step;
        _pos = _row;
        _x = 0;
    }

    return ( *this );
}

/*
* Prefix decrement one pixel.
*/
template<typename T>
inline _iterator::ImageIterator<T>& _iterator::ImageIterator<T>::operator--()
{
    if( _pos == _row )
    {
        _row -= _step;
        _pos = _row + _width - 1;
    }
    else
    {
        --_pos;
    }

    return ( *this );
}

/*
* Postfix increment one pixel.
*/
template<typename T>
inline _iterator::ImageIterator<T> _iterator::ImageIterator<T>::operator++( const int32_t )
{
    ImageIterator temp = *this;
    ++( *this );
    return temp;
}

/*
* Postfix decrement one pixel.
*/
template<typename T>
inline _iterator::ImageIterator<T> _iterator::ImageIterator<T>::operator--( const int32_t )
{
    ImageIterator temp = *this;
    --( *this );
    return temp;
}

/*
* Return the iterator located 'n' pixels further than this one.
*/
template<typename T>
inline _iterator::ImageIterator<T> _iterator::ImageIterator<T>::operator+( const int32_t n ) const
{
    ImageIterator temp = *this;
    temp += n;
    return temp;
}

/*
* Return the iterator located 'n' pixels further back from this one.
*/
template<typename T>
inline _iterator::ImageIterator<T> _iterator::ImageIterator<T>::operator-( const int32_t n ) const
{
    ImageIterator temp = *this;
    temp -= n;
    return temp;
}

/*
* Return the number of pixels between this iterator and the given one.
*/
template<typename T>
inline int32_t _iterator::ImageIterator<T>::operator-( const _iterator::ImageIterator<T>& other ) const
{
    int32_t dx = ( _pos - _row ) - ( other._pos - other._row );
    return ( _row - other._row ) / _step + dx;
}



/*
* Return the data object located at the current pixel.
*/
template<typename T>
inline T& _iterator::ImageIterator<T>::operator*() const
{
    return *_pos;
}

/*
* Return a pointer to the data object located at the current pixel.
*/
template<typename T>
inline T* _iterator::ImageIterator<T>::operator->()
{
    return _pos;
}

/*
* Return a pointer to the data object located at the current pixel.
*/
template<typename T>
inline const T& _iterator::ImageIterator<T>::operator[]( const int32_t i ) const
{
    return _pos[i];
}

/*
* Access elements in the image as if this were a pointer in the image.
*/
template<typename T>
inline T& _iterator::ImageIterator<T>::operator[]( const int32_t i )
{
    return _pos[i];
}

/*
* Return a pointer to the data object located at the current pixel.
*/
template<typename T>
inline T* _iterator::ImageIterator<T>::pos() const
{
    return _pos;
}

///------------------------------------------------------------------------------
/// RowIterator function definitions.
///------------------------------------------------------------------------------

/*
* Constructor.
*/
template<typename T>
inline _iterator::RowIterator<T>::RowIterator( T* ptr_i, int32_t i_row, int32_t i_step ) :
    _ptr( ptr_i ),
    _row( i_row ),
    _step( i_step )
{
}

/*
* Destructor.
*/
template<typename T>
inline _iterator::RowIterator<T>::~RowIterator()
{
}

/*
* Set to the n'th row.
*/
template<typename T>
inline _iterator::RowIterator<T>& _iterator::RowIterator<T>::operator=( const int32_t n )
{
    _ptr = _ptr + ( n - _row ) * _step;
    _row = n;
    return ( *this );
}

/*
* Compare equality to an integer row value.
*/
template<typename T>
inline bool_t _iterator::RowIterator<T>::operator== ( const int32_t n ) const
{
    return _row == n;
};

/*
* Compare equality.
*/
template<typename T>
inline bool_t _iterator::RowIterator<T>::operator== ( const _iterator::RowIterator<T>& other ) const
{
    return _row == other._row;
};

/*
* Compare inequality to an integer row value.
*/
template<typename T>
inline bool_t _iterator::RowIterator<T>::operator!= ( const int32_t n ) const
{
    return _row != n;
};

/*
* Compare inequality.
*/
template<typename T>
inline bool_t _iterator::RowIterator<T>::operator!= ( const _iterator::RowIterator<T>& other ) const
{
    return _row != other._row;
};

/*
* Compare less than, to an integer row value.
*/
template<typename T>
inline bool_t _iterator::RowIterator<T>::operator< ( const int32_t n ) const
{
    return _row < n;
};

/*
* Compare less than.
*/
template<typename T>
inline bool_t _iterator::RowIterator<T>::operator< ( const _iterator::RowIterator<T>& other ) const
{
    return _row < other._row;
};

/*
* Compare less than or equal to, to an integer row value.
*/
template<typename T>
inline bool_t _iterator::RowIterator<T>:: operator<= ( const int32_t n ) const
{
    return _row <= n;
};

/*
* Compare less than or equal to.
*/
template<typename T>
inline bool_t _iterator::RowIterator<T>::operator<=( const _iterator::RowIterator<T>& other ) const
{
    return _row <= other._row;
}

/*
* Compare greater than, to an integer row value.
*/
template<typename T>
inline bool_t _iterator::RowIterator<T>::operator>( const int32_t n ) const
{
    return _row > n;
}

/*
* Compare greater than.
*/
template<typename T>
inline bool_t _iterator::RowIterator<T>::operator>( const _iterator::RowIterator<T>& other ) const
{
    return _row > other._row;
}

/*
* Compare greater than or equal to, to an integer row value.
*/
template<typename T>
inline bool_t _iterator::RowIterator<T>::operator>=( const int32_t n ) const
{
    return _row >= n;
}

/*
* Compare greater than or equal to.
*/
template<typename T>
inline bool_t _iterator::RowIterator<T>::operator>=( const _iterator::RowIterator<T>& other ) const
{
    return _row >= other._row;
}

/*
* Increment by n rows.
*/
template<typename T>
inline _iterator::RowIterator<T>& _iterator::RowIterator<T>::operator+=( const int32_t n )
{
    _row += n;
    _ptr += n * _step;
    return ( *this );
}

/*
* Decrement by n rows.
*/
template<typename T>
inline _iterator::RowIterator<T>& _iterator::RowIterator<T>::operator-=( const int32_t n )
{
    _row -= n;
    _ptr -= n * _step;
    return ( *this );
}

/*
* Prefix increment.
*/
template<typename T>
inline _iterator::RowIterator<T>& _iterator::RowIterator<T>::operator++()
{
    ++_row;
    _ptr += _step;
    return ( *this );
}

/*
* Prefix deccrement.
*/
template<typename T>
inline _iterator::RowIterator<T>& _iterator::RowIterator<T>::operator--()
{
    --_row;
    _ptr -= _step;
    return ( *this );
}

/*
* Postfix increment.
*/
template<typename T>
inline _iterator::RowIterator<T> _iterator::RowIterator<T>::operator++( const int32_t )
{
    RowIterator<T> temp = ( *this );
    ++( *this );
    return temp;
}

/*
* Postfix deccrement.
*/
template<typename T>
inline _iterator::RowIterator<T> _iterator::RowIterator<T>::operator--( const int32_t )
{
    RowIterator<T> temp = ( *this );
    --( *this );
    return temp;
}

/*
* Return the iterator at the row 'n' rows further than this one.
*/
template<typename T>
inline _iterator::RowIterator<T> _iterator::RowIterator<T>::operator+( const int32_t n ) const
{
    RowIterator<T> temp = ( *this );
    temp += n;
    return temp;
}

/*
* Return the iterator at the row 'n' rows further back from this one.
*/
template<typename T>
inline _iterator::RowIterator<T> _iterator::RowIterator<T>::operator-( const int32_t n ) const
{
    RowIterator<T> temp = ( *this );
    temp -= n;
    return temp;
}

/*
* Return the current row as an integer value.
*/
template<typename T>
inline int32_t _iterator::RowIterator<T>::operator*() const
{
    return _row;
}

/*
* Return a pointer to the first element of the current row.
*/
template<typename T>
inline T* _iterator::RowIterator<T>::ptr() const
{
    return _ptr;
}

///------------------------------------------------------------------------------
/// ColumnIterator function definitions.
///------------------------------------------------------------------------------

/*
* Constructor.
*/
template<typename T>
inline _iterator::ColumnIterator<T>::ColumnIterator( int32_t i_col ) :
    _col( i_col )
{
}

/*
* Destructor.
*/
template<typename T>
inline _iterator::ColumnIterator<T>::~ColumnIterator()
{
}

/*
* Set to the n'th column.
*/
template<typename T>
inline _iterator::ColumnIterator<T>& _iterator::ColumnIterator<T>::operator=( const int32_t n )
{
    _col = n;
    return ( *this );
}

/*
* Compare equality, to an integer column value.
*/
template<typename T>
inline bool_t _iterator::ColumnIterator<T>::operator== ( const int32_t n ) const
{
    return _col == n;
};

/*
* Compare equality.
*/
template<typename T>
inline bool_t _iterator::ColumnIterator<T>::operator== ( const _iterator::ColumnIterator<T>& other ) const
{
    return _col == other._col;
};

/*
* Compare inequality, to an integer column value.
*/
template<typename T>
inline bool_t _iterator::ColumnIterator<T>::operator!= ( const int32_t n ) const
{
    return _col != n;
};

/*
* Compare inequality.
*/
template<typename T>
inline bool_t _iterator::ColumnIterator<T>::operator!= ( const _iterator::ColumnIterator<T>& other ) const
{
    return _col != other._col;
};

/*
* Compare less than, to an integer column value.
*/
template<typename T>
inline bool_t _iterator::ColumnIterator<T>::operator< ( const int32_t n ) const
{
    return _col < n;
};

/*
* Compare less than.
*/
template<typename T>
inline bool_t _iterator::ColumnIterator<T>::operator< ( const _iterator::ColumnIterator<T>& other )  const
{
    return _col < other._col;
};

/*
* Compare less than or equal to, to an integer column value.
*/
template<typename T>
inline bool_t _iterator::ColumnIterator<T>::operator<= ( const int32_t n ) const
{
    return _col <= n;
};

/*
* Compare less than or equal to.
*/
template<typename T>
inline bool_t _iterator::ColumnIterator<T>::operator<= ( const _iterator::ColumnIterator<T>& other ) const
{
    return _col <= other._col;
};

/*
* Compare greater than, to an integer column value.
*/
template<typename T>
inline bool_t _iterator::ColumnIterator<T>::operator> ( const int32_t n ) const
{
    return _col > n;
};

/*
* Compare greater than.
*/
template<typename T>
inline bool_t _iterator::ColumnIterator<T>::operator> ( const _iterator::ColumnIterator<T>& other )const
{
    return _col > other._col;
};

/*
* Compare greater than or equal to, to an integer column value.
*/
template<typename T>
inline bool_t _iterator::ColumnIterator<T>::operator>= ( const int32_t n ) const
{
    return _col >= n;
};

/*
* Compare greater than or equal to.
*/
template<typename T>
inline bool_t _iterator::ColumnIterator<T>::operator>= ( const _iterator::ColumnIterator<T>& other ) const
{
    return _col >= other._col;
};

/*
* Increment by 'n' columns.
*/
template<typename T>
inline _iterator::ColumnIterator<T>& _iterator::ColumnIterator<T>::operator+= ( const int32_t n )
{
    _col += n;
    return ( *this );
};

/*
* Decrement by 'n' columns.
*/
template<typename T>
inline _iterator::ColumnIterator<T>& _iterator::ColumnIterator<T>::operator-= ( const int32_t n )
{
    _col -= n;
    return ( *this );
};

/*
* Prefix increment column.
*/
template<typename T>
inline _iterator::ColumnIterator<T>& _iterator::ColumnIterator<T>::operator++ () // Pre
{
    ++_col;
    return ( *this );
};

/*
* Prefix decrement column.
*/
template<typename T>
inline _iterator::ColumnIterator<T>&   _iterator::ColumnIterator<T>::operator-- ()// Pre
{
    --_col;
    return ( *this );
};

/*
* Postfix increment column.
*/
template<typename T>
inline _iterator::ColumnIterator<T> _iterator::ColumnIterator<T>::operator++( const int32_t ) // Post
{
    ColumnIterator<T> temp = ( *this );
    ++( *this );
    return temp;
}

/*
* Postfix decrement column.
*/
template<typename T>
inline _iterator::ColumnIterator<T> _iterator::ColumnIterator<T>::operator--( const int32_t ) // Post
{
    ColumnIterator<T> temp = ( *this );
    --( *this );
    return temp;
}

/*
* Return the iterator at the column 'n' columns further than this one.
*/
template<typename T>
inline _iterator::ColumnIterator<T> _iterator::ColumnIterator<T>::operator+( const int32_t n ) const
{
    ColumnIterator<T> temp = ( *this );
    temp += n;
    return temp;
}

/*
* Return the iterator at the column 'n' columns further back from this one.
*/
template<typename T>
inline _iterator::ColumnIterator<T> _iterator::ColumnIterator<T>::operator-( const int32_t n ) const
{
    ColumnIterator<T> temp = ( *this );
    temp -= n;
    return temp;
}


/*
* Return the integer column value of this iterator.
*/
template<typename T>
inline int32_t _iterator::ColumnIterator<T>::operator*() const
{
    return _col;
}

#endif // !__IMAGE_ITERATOR__H_
