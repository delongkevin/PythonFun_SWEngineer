//--------------------------------------------------------------------------
/// @file Rectangle.h
/// @brief Definition of class templates for points
///
/// File contains definition 2D rectangle.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Michael Nees (michael.nees@magna.com)
///
//  --------------------------------------------------------------------------
/// \addtogroup mecl
/// @{
/// \addtogroup core
/// @{

#ifndef MECL_CORE_RECTANGLE_HPP_
#define MECL_CORE_RECTANGLE_HPP_


namespace mecl
{
namespace core
{


// --------------------------------------------------------------------------
/// @brief Default constructor

/// The default constructor initializes all coordinates to zero.
///
/// @par Example usage:
/// @snippet 
///
/// @return       Rectangle
// --------------------------------------------------------------------------
template<typename T>
Rectangle<T>::Rectangle(void)
  : tLX_x(static_cast<T>(0)), tLY_x(static_cast<T>(0))
  , bRX_x(static_cast<T>(0)), bRY_x(static_cast<T>(0))
{}


// --------------------------------------------------------------------------
/// @brief Constructor with initialization value
///
/// The constructor initializes all coordinates to the input arguments.
///
/// @par Example usage:
/// @snippet 
///
/// @param[in] i_TLX_x, i_TLY_x, i_BRX_x, i_BRY_x Initialization value
/// @return Rectangle pre-initialized with specific coordinates
// --------------------------------------------------------------------------
template<typename T>
Rectangle<T>::Rectangle(T i_TLX_x,T i_TLY_x,T i_BRX_x,T i_BRY_x)
  : tLX_x(i_TLX_x), tLY_x(i_TLY_x),bRX_x(i_BRX_x),bRY_x(i_BRY_x)
{}



// --------------------------------------------------------------------------
/// @brief Get the width of the rectangle
///
/// Function returns value defining the width of this rectangle
///
/// @par Example usage:
/// @snippet 
///
/// @return width of the rectangle
// --------------------------------------------------------------------------
template<typename T>
T Rectangle<T>::width_x(void) const
{
  return bRX_x - tLX_x;
}

// --------------------------------------------------------------------------
/// @brief Get the height of the rectangle
///
/// Function returns value defining the height of this rectangle
///
/// @par Example usage:
/// @snippet 
///
/// @return height of the rectangle
// --------------------------------------------------------------------------
template<typename T>
T Rectangle<T>::height_x(void) const
{
  return bRY_x - tLY_x;
}


// --------------------------------------------------------------------------
/// @brief Assign rectangle to other
///
/// @par Example usage:
/// @snippet 
///
/// @param[in]    i_Matrix_rx New coordinates as 3x1 matrix
/// @return       Assigned rectangle
//  --------------------------------------------------------------------------
template<typename T>
Rectangle<T>& Rectangle<T>::operator=(const Rectangle<T>& i_Other_rx)
{
  if (this != (&i_Other_rx))
  { memcpy(this,&i_Other_rx,sizeof(Rectangle<T>)); }
  return *this; 
}

// --------------------------------------------------------------------------
/// @brief Unite two rect each other and assign to left hand side
///
/// @par Example usage:
/// @snippet 
///
/// @param[in]    i_Other_rx right hand rect
/// @return       United rectangle
//  --------------------------------------------------------------------------
template<typename T>
Rectangle<T>& Rectangle<T>::operator&=(Rectangle<T>& i_Other_rx)
{ 
  unite_v(i_Other_rx); 
  return *this; 
}

// --------------------------------------------------------------------------
/// @brief Unite a rect each other
///
/// @par Example usage:
/// @snippet
///
/// @param[in]    i_Other_rx right hand rect
/// @return       United rectangle
//  --------------------------------------------------------------------------
template<typename T1>
Rectangle<T1> operator& (Rectangle<T1> i_Lhs_rx,Rectangle<T1>& i_Rhs_rx)
{
  i_Lhs_rx &= i_Rhs_rx;
  return i_Lhs_rx;
}

// --------------------------------------------------------------------------
/// @brief Intersect rect each other and assign to left hand side
///
/// @par Example usage:
/// @snippet 
///
/// @param[in]    i_Other_rx right hand rect
/// @return       United rectangle
//  --------------------------------------------------------------------------
template<typename T>
Rectangle<T>& Rectangle<T>::operator|=(Rectangle<T>& i_Other_rx)
{ 
  intersect_v(i_Other_rx); 
  return *this; 
}


// --------------------------------------------------------------------------
/// @brief Intersect rect each other
///
/// @par Example usage:
/// @snippet 
///
/// @param[in]    i_Other_rx right hand rect
/// @return       United rectangle
//  --------------------------------------------------------------------------
template<typename T1>
Rectangle<T1> operator|(Rectangle<T1> i_Lhs_rx,Rectangle<T1>& i_Rhs_rx)
{ 
  i_Lhs_rx |= i_Rhs_rx; 
  return i_Lhs_rx; 
}


// Cast to different base type
template<typename T>
template<typename T1> inline
Rectangle<T>::operator Rectangle<T1>() const
{      
  return Rectangle<T1>(static_cast<T1>(this->tLX_x),
                  static_cast<T1>(this->tLY_x),
                  static_cast<T1>(this->bRX_x),
                  static_cast<T1>(this->bRY_x));
}


// --------------------------------------------------------------------------
/// @brief Unite rect each other
///
/// @par Example usage:
/// @snippet 
///
/// @param[in]    i_Rect_rx right hand side
/// @return       United rectangle
//  --------------------------------------------------------------------------
template<typename T>
void Rectangle<T>::unite_v(Rectangle<T>& i_Rect_rx)
{
  if((i_Rect_rx.width_x() > 0) || (i_Rect_rx.height_x() > 0))
  {
    if(i_Rect_rx.tLX_x < this->tLX_x){this->tLX_x = i_Rect_rx.tLX_x;}
    if(i_Rect_rx.tLY_x < this->tLY_x){this->tLY_x = i_Rect_rx.tLY_x;}
    if(i_Rect_rx.bRX_x > this->bRX_x){this->bRX_x = i_Rect_rx.bRX_x;}
    if(i_Rect_rx.bRY_x > this->bRY_x){this->bRY_x = i_Rect_rx.bRY_x;}
  }
}

// --------------------------------------------------------------------------
/// @brief Intersect rect each other
///
/// @par Example usage:
/// @snippet 
///
/// @param[in]    i_Rect_rx right hand side
/// @return       Intersected rectangle
//  --------------------------------------------------------------------------
template<typename T>
void Rectangle<T>::intersect_v(Rectangle<T>& i_Rect_rx)
{
  if((i_Rect_rx.width_x() > 0) || (i_Rect_rx.height_x() > 0))
  {
    if(i_Rect_rx.tLX_x > this->tLX_x){this->tLX_x = i_Rect_rx.tLX_x;}
    if(i_Rect_rx.tLY_x > this->tLY_x){this->tLY_x = i_Rect_rx.tLY_x;}
    if(i_Rect_rx.bRX_x < this->bRX_x){this->bRX_x = i_Rect_rx.bRX_x;}
    if(i_Rect_rx.bRY_x < this->bRY_x){this->bRY_x = i_Rect_rx.bRY_x;}
  }
}


} //namespace mecl
} //namespace core

#endif //MECL_CORE_RECTANGLE_HPP_
