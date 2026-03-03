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

#ifndef MECL_CORE_RECTANGLE_H_
#define MECL_CORE_RECTANGLE_H_


namespace mecl
{
namespace core
{


//--------------------------------------------------------------------------
/// @class Rectangle
/// @brief Storage class of a 2 dimensional rectangle location
// --------------------------------------------------------------------------

template<typename T>
class Rectangle
{
public:

  // --------------------------------------------------------------------------
  // constructors + destructor

  /// Default constructor
  explicit Rectangle(void);

  /// Constructor with initialization value of base type
  explicit Rectangle(T i_TLX_x,T i_TLY_x,T i_BRX_x,T i_BRY_x);

  /// Parameter
  T tLX_x;           // TopLeft Pos-X
  T tLY_x;           // TopLeft Pos-Y
  T bRX_x;           // BottomRight Pos-X
  T bRY_x;           // BottomRight Pos-Y
  T width_x(void) const;   // Width of the Rectangle
  T height_x(void) const;  // Hight of the Rectangle



  // --------------------------------------------------------------------------
  // additional operators

  // assign operator
  Rectangle& operator=(const Rectangle& i_Other_rx);
  
  // operator '&=' to unite two rect each other
  Rectangle& operator&=(Rectangle& i_Other_rx);
  
  // operator '&' to unite two rect each other
  template<typename T1> friend Rectangle<T1> operator& (Rectangle<T1> i_Lhs_rx,Rectangle<T1>& i_Rhs_rx);
  
  // operator '|=' to intersect two rect each other
  Rectangle& operator|=(Rectangle& i_Other_rx);
  
  // operator '|' to intersect two rect each other
  template<typename T1> friend Rectangle<T1> operator| (Rectangle<T1> i_Lhs_rx,Rectangle<T1>& i_Rhs_rx);
  

  // Cast to different base type
  template<typename T1> operator Rectangle<T1>() const;
  
private:

  // --------------------------------------------------------------------------
  // math operations

  void unite_v(Rectangle& i_Rect_rx); 
  void intersect_v(Rectangle& i_Rect_rx);
  
};


} //namespace mecl
} //namespace core

#endif //MECL_CORE_RECTANGLE_H_

#include "Rectangle.hpp"


  
