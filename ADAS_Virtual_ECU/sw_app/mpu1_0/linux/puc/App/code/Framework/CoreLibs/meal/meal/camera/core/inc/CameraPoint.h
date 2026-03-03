//--------------------------------------------------------------------------
/// @file CameraPoint.h
/// @brief Definition of class templates for points.
///
/// File contains definition of CPoint2_<T> and CPoint3_<T>.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Sasha Velichko (sasha.velichko@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef _CAMERAPOINT_H_
#define _CAMERAPOINT_H_

#include "mecl/core/MeclTypes.h"
#include "mecl/math/Math.h"

// forward declarations
template<typename _Tp> class CRect_;

//////////////////////////////// CPoint2_ /////////////////////////////////////////
// -------------------------------------------------------------------------------
/// @brief Template class for 2D points specified by its coordinates `x` and `y`.
///
///There is a cast operator to convert point coordinates to the specified type.
///The conversion from floating-point coordinates to integer coordinates is done
///by rounding. Commonly, the conversion uses this operation for each of the
///coordinates. Besides the class members listed in the declaration above,
///the following operations on points are implemented:
///@code
///    pt1 = pt2 + pt3;
///    pt1 = pt2 - pt3;
///    pt1 = pt2 * a;
///    pt1 = a * pt2;
///    pt1 = pt2 / a;
///    pt1 += pt2;
///    pt1 -= pt2;
///    pt1 *= a;
///    pt1 /= a;
///    double value = norm(pt); // L2 norm
///    pt1 == pt2;
///    pt1 != pt2;
///@endcode
///For your convenience, the following type aliases are defined:
///@code
///    typedef CPoint2_<int32_t>  Point2i;
///    typedef CPoint2_<float32_t> Point2f;
///    typedef CPoint2_<float64_t> Point2d;
///@endcode
///Example:
///@code
///    Point2f a(0.3f, 0.f), b(0.f, 0.4f);
///    Point2i pt = (a + b)*10.f;
///    cout << pt.x << ", " << pt.y << endl;
///@endcode
// -------------------------------------------------------------------------------
template<typename _Tp> class CPoint2_
{
public:
	typedef _Tp value_type;

	// various constructors
	CPoint2_();
	CPoint2_(_Tp _x, _Tp _y);
	CPoint2_(const CPoint2_& pt);

	//! assignment operator
	CPoint2_& operator = (const CPoint2_& pt);

	//! dot product
	_Tp dot(const CPoint2_& pt) const;
	//! dot product computed in float64_t-precision arithmetics
	float64_t ddot(const CPoint2_& pt) const;
	//! cross-product
	_Tp cross(const CPoint2_& pt) const;
	//! cross-product computed in float64_t-precision arithmetics
	float64_t dcross(const CPoint2_& pt) const;
	//! norm
	_Tp norm(void) const;
	//! norm computed in float64_t-precision arithmetics
	float64_t dnorm(void) const;
	//! distance between two points
	_Tp dist(const CPoint2_& pt) const;
	//! distance between two points computed in float64_t-precision arithmetics
	float64_t ddist(const CPoint2_& pt) const;
	//! checks whether the point is inside the specified rectangle
	bool_t inside(const CRect_<_Tp>& r) const;

	_Tp x, y; //< the point coordinates
    public:
        inline _Tp getX() const
        {
            return x;
        }
        inline _Tp getY() const
        {
            return y;
        }
        inline const _Tp* getXRef() const
        {
            return &x;
        }
        inline const _Tp* getYRef() const
        {
            return &y;
        }
        inline void setY( _Tp y_val )
        {
            y = y_val;
        }
        inline void setX( _Tp x_val )
        {
            x = x_val;
        }

};


typedef CPoint2_<sint32_t>	Point2i;
typedef CPoint2_<float32_t>	Point2f;
typedef CPoint2_<float64_t>	Point2d;


template<typename _Tp> inline
CPoint2_<_Tp>::CPoint2_()
	: x(0), y(0) {}

template<typename _Tp> inline
CPoint2_<_Tp>::CPoint2_(_Tp _x, _Tp _y)
	: x(_x), y(_y) {}

template<typename _Tp> inline
CPoint2_<_Tp>::CPoint2_(const CPoint2_& pt)
	: x(pt.x), y(pt.y) {}

template<typename _Tp> inline
CPoint2_<_Tp>& CPoint2_<_Tp>::operator = (const CPoint2_& pt)
{
	x = pt.x; y = pt.y;
	return *this;
}

template<typename _Tp> inline
_Tp CPoint2_<_Tp>::dot(const CPoint2_& pt) const
{
	return static_cast<_Tp>(x * pt.x + y * pt.y);
}

template<typename _Tp> inline
float64_t CPoint2_<_Tp>::ddot(const CPoint2_& pt) const
{
	return static_cast<float64_t>(x) * pt.x + static_cast<float64_t>(y) * pt.y;
}

template<typename _Tp> inline
_Tp CPoint2_<_Tp>::cross(const CPoint2_& pt) const
{
	return static_cast<_Tp>(x * pt.y - y * pt.x);
}

template<typename _Tp> inline
float64_t CPoint2_<_Tp>::dcross(const CPoint2_& pt) const
{
	return static_cast<float64_t>(x) * pt.y - static_cast<float64_t>(y) * pt.x;
}

template<typename _Tp> inline
_Tp CPoint2_<_Tp>::norm(void) const
{
	return mecl::math::algebra<_Tp>::sqrt_x(x * x + y * y);
}

template<typename _Tp> inline
float64_t CPoint2_<_Tp>::dnorm(void) const
{
	return mecl::math::algebra<float64_t>::sqrt_x(static_cast<float64_t>(x) * x + static_cast<float64_t>(y) * y);
}

template<typename _Tp> inline
_Tp CPoint2_<_Tp>::dist(const CPoint2_& pt) const
{
	_Tp dX = x - pt.x;
	_Tp dY = y - pt.y;
	return mecl::math::algebra<_Tp>::sqrt_x(dX * dX + dY * dY);
}

template<typename _Tp> inline
float64_t CPoint2_<_Tp>::ddist(const CPoint2_& pt) const
{
	float64_t dX = static_cast<float64_t>(x) - pt.x;
	float64_t dY = static_cast<float64_t>(y) - pt.y;
	return mecl::math::algebra<float64_t>::sqrt_x(dX * dX + dY * dY);
}

template<typename _Tp> static inline
CPoint2_<_Tp>& operator += (CPoint2_<_Tp>& a, const CPoint2_<_Tp>& b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}

template<typename _Tp> static inline
CPoint2_<_Tp>& operator -= (CPoint2_<_Tp>& a, const CPoint2_<_Tp>& b)
{
	a.x -= b.x;
	a.y -= b.y;
	return a;
}

template<typename _Tp> static inline
CPoint2_<_Tp>& operator *= (CPoint2_<_Tp>& a, int b)
{
	a.x = static_cast<_Tp>(a.x * b);
	a.y = static_cast<_Tp>(a.y * b);
	return a;
}

template<typename _Tp> static inline
CPoint2_<_Tp>& operator *= (CPoint2_<_Tp>& a, float b)
{
	a.x = static_cast<_Tp>(a.x * b);
	a.y = static_cast<_Tp>(a.y * b);
	return a;
}

template<typename _Tp> static inline
CPoint2_<_Tp>& operator *= (CPoint2_<_Tp>& a, float64_t b)
{
	a.x = static_cast<_Tp>(a.x * b);
	a.y = static_cast<_Tp>(a.y * b);
	return a;
}

template<typename _Tp> static inline
CPoint2_<_Tp>& operator /= (CPoint2_<_Tp>& a, int b)
{
	a.x = static_cast<_Tp>(a.x / b);
	a.y = static_cast<_Tp>(a.y / b);
	return a;
}

template<typename _Tp> static inline
CPoint2_<_Tp>& operator /= (CPoint2_<_Tp>& a, float b)
{
	a.x = static_cast<_Tp>(a.x / b);
	a.y = static_cast<_Tp>(a.y / b);
	return a;
}

template<typename _Tp> static inline
CPoint2_<_Tp>& operator /= (CPoint2_<_Tp>& a, float64_t b)
{
	a.x = static_cast<_Tp>(a.x / b);
	a.y = static_cast<_Tp>(a.y / b);
	return a;
}

template<typename _Tp> static inline
bool operator == (const CPoint2_<_Tp>& a, const CPoint2_<_Tp>& b)
{
	return a.x == b.x && a.y == b.y;
}

template<typename _Tp> static inline
bool operator != (const CPoint2_<_Tp>& a, const CPoint2_<_Tp>& b)
{
	return a.x != b.x || a.y != b.y;
}

template<typename _Tp> static inline
CPoint2_<_Tp> operator + (const CPoint2_<_Tp>& a, const CPoint2_<_Tp>& b)
{
	return CPoint2_<_Tp>( static_cast<_Tp>(a.x + b.x), static_cast<_Tp>(a.y + b.y) );
}

template<typename _Tp> static inline
CPoint2_<_Tp> operator - (const CPoint2_<_Tp>& a, const CPoint2_<_Tp>& b)
{
	return CPoint2_<_Tp>( static_cast<_Tp>(a.x - b.x), static_cast<_Tp>(a.y - b.y) );
}

template<typename _Tp> static inline
CPoint2_<_Tp> operator - (const CPoint2_<_Tp>& a)
{
	return CPoint2_<_Tp>( static_cast<_Tp>(-a.x), static_cast<_Tp>(-a.y) );
}

template<typename _Tp> static inline
CPoint2_<_Tp> operator * (const CPoint2_<_Tp>& a, int b)
{
	return CPoint2_<_Tp>( static_cast<_Tp>(a.x * b), static_cast<_Tp>(a.y * b) );
}

template<typename _Tp> static inline
CPoint2_<_Tp> operator * (int a, const CPoint2_<_Tp>& b)
{
	return CPoint2_<_Tp>( static_cast<_Tp>(b.x * a), static_cast<_Tp>(b.y * a) );
}

template<typename _Tp> static inline
CPoint2_<_Tp> operator * (const CPoint2_<_Tp>& a, float b)
{
	return CPoint2_<_Tp>( static_cast<_Tp>(a.x * b), static_cast<_Tp>(a.y * b) );
}

template<typename _Tp> static inline
CPoint2_<_Tp> operator * (float a, const CPoint2_<_Tp>& b)
{
	return CPoint2_<_Tp>( static_cast<_Tp>(b.x * a), static_cast<_Tp>(b.y * a) );
}

template<typename _Tp> static inline
CPoint2_<_Tp> operator * (const CPoint2_<_Tp>& a, float64_t b)
{
	return CPoint2_<_Tp>( static_cast<_Tp>(a.x * b), static_cast<_Tp>(a.y * b) );
}

template<typename _Tp> static inline
CPoint2_<_Tp> operator * (float64_t a, const CPoint2_<_Tp>& b)
{
	return CPoint2_<_Tp>( static_cast<_Tp>(b.x * a), static_cast<_Tp>(b.y * a) );
}

template<typename _Tp> static inline
CPoint2_<_Tp> operator / (const CPoint2_<_Tp>& a, int b)
{
	CPoint2_<_Tp> tmp(a);
	tmp /= b;
	return tmp;
}

template<typename _Tp> static inline
CPoint2_<_Tp> operator / (const CPoint2_<_Tp>& a, float b)
{
	CPoint2_<_Tp> tmp(a);
	tmp /= b;
	return tmp;
}

template<typename _Tp> static inline
CPoint2_<_Tp> operator / (const CPoint2_<_Tp>& a, float64_t b)
{
	CPoint2_<_Tp> tmp(a);
	tmp /= b;
	return tmp;
}

///////////////////////////////////// CPoint3_ //////////////////////////////////////////
// -------------------------------------------------------------------------------------
/// @brief Template class for 3D points specified by its coordinates `x`, `y` and `z`.
///
///Similarly to CPoint2_ , the coordinates of 3D points can be converted to another type.
///The vector arithmetic and comparison operations are also supported.

///The following CPoint3_\<\> aliases are available:
///@code
///    typedef CPoint3_<int32_t>  Point3i;
///    typedef CPoint3_<float32_t> Point3f;
///    typedef CPoint3_<float64_t> Point3d;
///@endcode
// -------------------------------------------------------------------------------------
template<typename _Tp> class CPoint3_
{
public:
	typedef _Tp value_type;

	// various constructors
	CPoint3_();
	CPoint3_(_Tp _x, _Tp _y, _Tp _z);
	CPoint3_(const CPoint3_& pt);
	explicit CPoint3_(const CPoint2_<_Tp>& pt);

	CPoint3_& operator = (const CPoint3_& pt);

	//! dot product
	_Tp dot(const CPoint3_& pt) const;
	//! dot product computed in float64_t-precision arithmetics
	float64_t ddot(const CPoint3_& pt) const;
	//! cross product of the 2 3D points
	CPoint3_ cross(const CPoint3_& pt) const;
	//! cross product of the 2 3D points computed in float64_t-precision arithmetics
	CPoint3_<float64_t> dcross(const CPoint3_& pt) const;
	//! norm
	_Tp norm(void) const;
	//! norm computed in float64_t-precision arithmetics
	float64_t dnorm(void) const;
	//! distance between two points
	_Tp dist(const CPoint3_& pt) const;
	//! distance between two points computed in float64_t-precision arithmetics
	float64_t ddist(const CPoint3_& pt) const;

	_Tp x, y, z; //< the point coordinates
};

typedef CPoint3_<sint32_t>	Point3i;
typedef CPoint3_<float32_t>	Point3f;
typedef CPoint3_<float64_t>	Point3d;


//////////////////////////////// 3D Point ///////////////////////////////

template<typename _Tp> inline
CPoint3_<_Tp>::CPoint3_()
	: x(0), y(0), z(0) {}

template<typename _Tp> inline
CPoint3_<_Tp>::CPoint3_(_Tp _x, _Tp _y, _Tp _z)
	: x(_x), y(_y), z(_z) {}

template<typename _Tp> inline
CPoint3_<_Tp>::CPoint3_(const CPoint3_& pt)
	: x(pt.x), y(pt.y), z(pt.z) {}

template<typename _Tp> inline
CPoint3_<_Tp>::CPoint3_(const CPoint2_<_Tp>& pt)
	: x(pt.x), y(pt.y), z(_Tp()) {}

template<typename _Tp> inline
CPoint3_<_Tp>& CPoint3_<_Tp>::operator = (const CPoint3_& pt)
{
	x = pt.x; y = pt.y; z = pt.z;
	return *this;
}


template<typename _Tp> inline
_Tp CPoint3_<_Tp>::dot(const CPoint3_& pt) const
{
	return static_cast<_Tp>(x * pt.x + y * pt.y + z * pt.z);
}

template<typename _Tp> inline
float64_t CPoint3_<_Tp>::ddot(const CPoint3_& pt) const
{
	return static_cast<float64_t>(x) * pt.x + static_cast<float64_t>(y) * pt.y + static_cast<float64_t>(z) * pt.z;
}

template<typename _Tp> inline
CPoint3_<_Tp> CPoint3_<_Tp>::cross(const CPoint3_<_Tp>& pt) const
{
	return CPoint3_<_Tp>(y * pt.z - z * pt.y, z * pt.x - x * pt.z, x * pt.y - y * pt.x);
}

template<typename _Tp> inline
CPoint3_<float64_t> CPoint3_<_Tp>::dcross(const CPoint3_<_Tp>& pt) const
{
	return CPoint3_<float64_t>(static_cast<float64_t>(y) * pt.z - static_cast<float64_t>(z) * pt.y,
							  static_cast<float64_t>(z) * pt.x - static_cast<float64_t>(x) * pt.z,
							  static_cast<float64_t>(x) * pt.y - static_cast<float64_t>(y) * pt.x);
}

template<typename _Tp> inline
_Tp CPoint3_<_Tp>::norm(void) const
{
	return mecl::math::algebra<_Tp>::sqrt_x(x * x + y * y + z * z);
}

template<typename _Tp> inline
float64_t CPoint3_<_Tp>::dnorm(void) const
{
	return mecl::math::algebra<float64_t>::sqrt_x(static_cast<float64_t>(x) * x +
												  static_cast<float64_t>(y) * y +
												  static_cast<float64_t>(z) * z);
}

template<typename _Tp> inline
_Tp CPoint3_<_Tp>::dist(const CPoint3_& pt) const
{
	_Tp dX = x - pt.x;
	_Tp dY = y - pt.y;
	_Tp dZ = z - pt.z;
	return mecl::math::algebra<_Tp>::sqrt_x(dX * dX + dY * dY + dZ * dZ);
}

template<typename _Tp> inline
float64_t CPoint3_<_Tp>::ddist(const CPoint3_& pt) const
{
	float64_t dX = static_cast<float64_t>(x) - pt.x;
	float64_t dY = static_cast<float64_t>(y) - pt.y;
	float64_t dZ = static_cast<float64_t>(z) - pt.z;
	return mecl::math::algebra<float64_t>::sqrt_x(dX * dX + dY * dY + dZ * dZ);
}

template<typename _Tp> static inline
CPoint3_<_Tp>& operator += (CPoint3_<_Tp>& a, const CPoint3_<_Tp>& b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return a;
}

template<typename _Tp> static inline
CPoint3_<_Tp>& operator -= (CPoint3_<_Tp>& a, const CPoint3_<_Tp>& b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return a;
}

template<typename _Tp> static inline
CPoint3_<_Tp>& operator *= (CPoint3_<_Tp>& a, int b)
{
	a.x = static_cast<_Tp>(a.x * b);
	a.y = static_cast<_Tp>(a.y * b);
	a.z = static_cast<_Tp>(a.z * b);
	return a;
}

template<typename _Tp> static inline
CPoint3_<_Tp>& operator *= (CPoint3_<_Tp>& a, float b)
{
	a.x = static_cast<_Tp>(a.x * b);
	a.y = static_cast<_Tp>(a.y * b);
	a.z = static_cast<_Tp>(a.z * b);
	return a;
}

template<typename _Tp> static inline
CPoint3_<_Tp>& operator *= (CPoint3_<_Tp>& a, float64_t b)
{
	a.x = static_cast<_Tp>(a.x * b);
	a.y = static_cast<_Tp>(a.y * b);
	a.z = static_cast<_Tp>(a.z * b);
	return a;
}

template<typename _Tp> static inline
CPoint3_<_Tp>& operator /= (CPoint3_<_Tp>& a, int b)
{
	a.x = static_cast<_Tp>(a.x / b);
	a.y = static_cast<_Tp>(a.y / b);
	a.z = static_cast<_Tp>(a.z / b);
	return a;
}

template<typename _Tp> static inline
CPoint3_<_Tp>& operator /= (CPoint3_<_Tp>& a, float b)
{
	a.x = static_cast<_Tp>(a.x / b);
	a.y = static_cast<_Tp>(a.y / b);
	a.z = static_cast<_Tp>(a.z / b);
	return a;
}

template<typename _Tp> static inline
CPoint3_<_Tp>& operator /= (CPoint3_<_Tp>& a, float64_t b)
{
	a.x = static_cast<_Tp>(a.x / b);
	a.y = static_cast<_Tp>(a.y / b);
	a.z = static_cast<_Tp>(a.z / b);
	return a;
}

template<typename _Tp> static inline
bool operator == (const CPoint3_<_Tp>& a, const CPoint3_<_Tp>& b)
{
	return ((a.x == b.x) && (a.y == b.y) && (a.z == b.z));
}

template<typename _Tp> static inline
bool operator != (const CPoint3_<_Tp>& a, const CPoint3_<_Tp>& b)
{
	return ((a.x != b.x) || (a.y != b.y) || (a.z != b.z));
}

template<typename _Tp> static inline
CPoint3_<_Tp> operator + (const CPoint3_<_Tp>& a, const CPoint3_<_Tp>& b)
{
	return CPoint3_<_Tp>( static_cast<_Tp>(a.x + b.x), static_cast<_Tp>(a.y + b.y), static_cast<_Tp>(a.z + b.z));
}

template<typename _Tp> static inline
CPoint3_<_Tp> operator - (const CPoint3_<_Tp>& a, const CPoint3_<_Tp>& b)
{
	return CPoint3_<_Tp>( static_cast<_Tp>(a.x - b.x), static_cast<_Tp>(a.y - b.y), static_cast<_Tp>(a.z - b.z));
}

template<typename _Tp> static inline
CPoint3_<_Tp> operator - (const CPoint3_<_Tp>& a)
{
	return CPoint3_<_Tp>( static_cast<_Tp>(-a.x), static_cast<_Tp>(-a.y), static_cast<_Tp>(-a.z) );
}

template<typename _Tp> static inline
CPoint3_<_Tp> operator * (const CPoint3_<_Tp>& a, int b)
{
	return CPoint3_<_Tp>( static_cast<_Tp>(a.x*b), static_cast<_Tp>(a.y*b), static_cast<_Tp>(a.z*b) );
}

template<typename _Tp> static inline
CPoint3_<_Tp> operator * (int a, const CPoint3_<_Tp>& b)
{
	return CPoint3_<_Tp>( static_cast<_Tp>(b.x * a), static_cast<_Tp>(b.y * a), static_cast<_Tp>(b.z * a) );
}

template<typename _Tp> static inline
CPoint3_<_Tp> operator * (const CPoint3_<_Tp>& a, float b)
{
	return CPoint3_<_Tp>( static_cast<_Tp>(a.x * b), static_cast<_Tp>(a.y * b), static_cast<_Tp>(a.z * b) );
}

template<typename _Tp> static inline
CPoint3_<_Tp> operator * (float a, const CPoint3_<_Tp>& b)
{
	return CPoint3_<_Tp>( static_cast<_Tp>(b.x * a), static_cast<_Tp>(b.y * a), static_cast<_Tp>(b.z * a) );
}

template<typename _Tp> static inline
CPoint3_<_Tp> operator * (const CPoint3_<_Tp>& a, float64_t b)
{
	return CPoint3_<_Tp>( static_cast<_Tp>(a.x * b), static_cast<_Tp>(a.y * b), static_cast<_Tp>(a.z * b) );
}

template<typename _Tp> static inline
CPoint3_<_Tp> operator * (float64_t a, const CPoint3_<_Tp>& b)
{
	return CPoint3_<_Tp>( static_cast<_Tp>(b.x * a), static_cast<_Tp>(b.y * a), static_cast<_Tp>(b.z * a) );
}

template<typename _Tp> static inline
CPoint3_<_Tp> operator / (const CPoint3_<_Tp>& a, int b)
{
	CPoint3_<_Tp> tmp(a);
	tmp /= b;
	return tmp;
}

template<typename _Tp> static inline
CPoint3_<_Tp> operator / (const CPoint3_<_Tp>& a, float b)
{
	CPoint3_<_Tp> tmp(a);
	tmp /= b;
	return tmp;
}

template<typename _Tp> static inline
CPoint3_<_Tp> operator / (const CPoint3_<_Tp>& a, float64_t b)
{
	CPoint3_<_Tp> tmp(a);
	tmp /= b;
	return tmp;
}

////////////////////////////////////// CRect_ ///////////////////////////////////////////
// -------------------------------------------------------------------------------------
/// @brief Template class for The 2D up-right rectangle class.
///
///The class represents a 2D rectangle with coordinates of the specified data type.
///
///The following CRect_\<\> aliases are available:
///@code
///    typedef CRect_<int32_t>  Recti;
///    typedef CRect_<float32_t> Rectf;
///    typedef CRect_<float64_t> Rectd;
///@endcode
// -------------------------------------------------------------------------------------
template<typename _Tp> class CRect_
{
public:
	typedef _Tp value_type;

	//! various constructors
	CRect_();
	CRect_(_Tp _x, _Tp _y, _Tp _width, _Tp _height);
	CRect_(const CRect_& r);
	CRect_(const CPoint2_<_Tp>& pt1, const CPoint2_<_Tp>& pt2);

	CRect_& operator = (const CRect_& r);

	//! Y coordinate of the top-left corner
	_Tp top(void) const;
	//! X coordinate of the top-left corner
	_Tp left(void) const;
	//! Y coordinate of the bottom-right corner
	_Tp bottom(void) const;
	//! X coordinate of the bottom-right corner
	_Tp right(void) const;

	//! the top-left corner
	CPoint2_<_Tp> tl(void) const;
	//! the top-right corner
	CPoint2_<_Tp> tr(void) const;
	//! the bottom-left corner
	CPoint2_<_Tp> bl(void) const;
	//! the bottom-right corner
	CPoint2_<_Tp> br(void) const;

	//! the top-center point
	CPoint2_<_Tp> tc(void) const;
	//! the center-center point
	CPoint2_<_Tp> cc(void) const;
	//! the bottom-center point
	CPoint2_<_Tp> bc(void) const;

	//! area (width*height) of the rectangle
	_Tp area(void) const;

	//! conversion to another data type
	//template<typename _Tp2> operator CRect_<_Tp2>() const;

	//! checks whether the rectangle contains the point
	bool_t contains(const CPoint2_<_Tp>& pt) const;

	//! checks whether the rectangle intersects with another
	bool_t intersects(const CRect_<_Tp>& pt) const;

	//! checks whether the rectangle contains another
	bool_t covers(const CRect_<_Tp>& rect) const;

	_Tp x, y, width, height; //< the top-left corner, as well as width and height of the rectangle
};


typedef CRect_<sint32_t>   Recti;
typedef CRect_<float32_t> Rectf;
typedef CRect_<float64_t> Rectd;


template<typename _Tp> inline
CRect_<_Tp>::CRect_()
	: x(0), y(0), width(0), height(0) {}

template<typename _Tp> inline
CRect_<_Tp>::CRect_(_Tp _x, _Tp _y, _Tp _width, _Tp _height)
	: x(_x), y(_y), width(_width), height(_height) {}

template<typename _Tp> inline
CRect_<_Tp>::CRect_(const CRect_<_Tp>& r)
	: x(r.x), y(r.y), width(r.width), height(r.height) {}

template<typename _Tp> inline
CRect_<_Tp>::CRect_(const CPoint2_<_Tp>& pt1, const CPoint2_<_Tp>& pt2)
{
	x = mecl::math::min_x<_Tp>(pt1.x, pt2.x);
	y = mecl::math::min_x<_Tp>(pt1.y, pt2.y);
	width  = mecl::math::max_x<_Tp>(pt1.x, pt2.x) - x;
	height = mecl::math::max_x<_Tp>(pt1.y, pt2.y) - y;
}

template<typename _Tp> inline
CRect_<_Tp>& CRect_<_Tp>::operator = (const CRect_<_Tp>& r)
{
	x = r.x;
	y = r.y;
	width = r.width;
	height = r.height;
	return *this;
}

template<typename _Tp> inline
_Tp CRect_<_Tp>::top(void) const
{
	return this->tl().y;
}

template<typename _Tp> inline
_Tp CRect_<_Tp>::left(void) const
{
	return this->tl().x;
}

template<typename _Tp> inline
_Tp CRect_<_Tp>::bottom(void) const
{
	return this->br().y;
}

template<typename _Tp> inline
_Tp CRect_<_Tp>::right(void) const
{
	return this->br().x;
}

template<typename _Tp> inline
CPoint2_<_Tp> CRect_<_Tp>::tl(void) const
{ 
	return CPoint2_<_Tp>(x, y);
}

template<typename _Tp> inline
CPoint2_<_Tp> CRect_<_Tp>::tr(void) const
{
	return CPoint2_<_Tp>(x + width, y);
}

template<typename _Tp> inline
CPoint2_<_Tp> CRect_<_Tp>::bl(void) const
{
	return CPoint2_<_Tp>(x, y + height);
}

template<typename _Tp> inline
CPoint2_<_Tp> CRect_<_Tp>::br(void) const
{
	return CPoint2_<_Tp>(x + width, y + height);
}

template<typename _Tp> inline
CPoint2_<_Tp> CRect_<_Tp>::tc(void) const
{
	return CPoint2_<_Tp>(x + width / 2, y);
}

template<typename _Tp> inline
CPoint2_<_Tp> CRect_<_Tp>::cc(void) const
{
	return CPoint2_<_Tp>(x + width / 2, y + height / 2);
}

template<typename _Tp> inline
CPoint2_<_Tp> CRect_<_Tp>::bc(void) const
{
	return CPoint2_<_Tp>(x + width / 2, y + height);
}

template<typename _Tp> static inline
CRect_<_Tp>& operator += (CRect_<_Tp>& a, const CPoint2_<_Tp>& b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}

template<typename _Tp> static inline
CRect_<_Tp>& operator -= (CRect_<_Tp>& a, const CPoint2_<_Tp>& b)
{
	a.x -= b.x;
	a.y -= b.y;
	return a;
}

template<typename _Tp> static inline
CRect_<_Tp>& operator &= (CRect_<_Tp>& a, const CRect_<_Tp>& b)
{
	_Tp x1 = mecl::math::max_x<_Tp>(a.x, b.x);
	_Tp y1 = mecl::math::max_x<_Tp>(a.y, b.y);

	a.width  = mecl::math::min_x<_Tp>(a.x + a.width,  b.x + b.width)  - x1;
	a.height = mecl::math::min_x<_Tp>(a.y + a.height, b.y + b.height) - y1;
	a.x = x1;
	a.y = y1;

	if ((a.width <= 0) || (a.height <= 0))
	{
		a = CRect_<_Tp>();
	}

	return a;
}

template<typename _Tp> static inline
CRect_<_Tp>& operator |= (CRect_<_Tp>& a, const CRect_<_Tp>& b)
{
	_Tp x1 = mecl::math::min_x<_Tp>(a.x, b.x);
	_Tp y1 = mecl::math::min_x<_Tp>(a.y, b.y);

	a.width  = mecl::math::max_x<_Tp>(a.x + a.width,  b.x + b.width)  - x1;
	a.height = mecl::math::max_x<_Tp>(a.y + a.height, b.y + b.height) - y1;
	a.x = x1;
	a.y = y1;

	return a;
}

template<typename _Tp> inline
_Tp CRect_<_Tp>::area(void) const
{
	return (width * height);
}

///
/// Commented out to avoid implicit casts between different typed rects.
///
//template<typename _Tp> template<typename _Tp2> inline
//CRect_<_Tp>::operator CRect_<_Tp2>() const
//{
//	return CRect_<_Tp2>(saturate_cast<_Tp2>(x),
//						saturate_cast<_Tp2>(y),
//						saturate_cast<_Tp2>(width),
//						saturate_cast<_Tp2>(height));
//}

template<typename _Tp> inline
bool_t CRect_<_Tp>::contains(const CPoint2_<_Tp>& pt) const
{
	return ((x <= pt.x) && (pt.x < (x + width)) &&
			(y <= pt.y) && (pt.y < (y + height)));
}

template<typename _Tp> inline
bool_t CRect_<_Tp>::intersects(const CRect_<_Tp>& r) const
{
	return !((this->x >= r.right()) || (r.x >= this->right()) ||
			(this->y >= r.bottom()) || (r.y >= this->bottom()));
}

template<typename _Tp> inline
bool_t CRect_<_Tp>::covers(const CRect_<_Tp>& rect) const
{
	if (rect.left() < left())
	{
		return false;
	}

	if (rect.right() > right())
	{
		return false;
	}

	if (rect.bottom() > bottom())
	{
		return false;
	}

	if (rect.top() < top())
	{
		return false;
	}

	return true;
}

template<typename _Tp> static inline
bool_t operator == (const CRect_<_Tp>& a, const CRect_<_Tp>& b)
{
	return ((a.x == b.x) && (a.y == b.y) &&
			(a.width == b.width) && (a.height == b.height));
}

template<typename _Tp> static inline
bool_t operator != (const CRect_<_Tp>& a, const CRect_<_Tp>& b)
{
	return ((a.x != b.x) || (a.y != b.y) ||
			(a.width != b.width) || (a.height != b.height));
}

template<typename _Tp> static inline
CRect_<_Tp> operator + (const CRect_<_Tp>& a, const CPoint2_<_Tp>& b)
{
	return CRect_<_Tp>(a.x + b.x, a.y + b.y, a.width, a.height);
}

template<typename _Tp> static inline
CRect_<_Tp> operator - (const CRect_<_Tp>& a, const CPoint2_<_Tp>& b)
{
	return CRect_<_Tp>(a.x - b.x, a.y - b.y, a.width, a.height);
}

template<typename _Tp> static inline
CRect_<_Tp> operator & (const CRect_<_Tp>& a, const CRect_<_Tp>& b)
{
	CRect_<_Tp> c = a;
	return c &= b;
}

template<typename _Tp> static inline
CRect_<_Tp> operator | (const CRect_<_Tp>& a, const CRect_<_Tp>& b)
{
	CRect_<_Tp> c = a;
	return c |= b;
}

template<typename _Tp> inline
bool_t CPoint2_<_Tp>::inside(const CRect_<_Tp>& r) const
{
	return r.contains(*this);
}


//-------------------------------------------------------------------------
// TODO - EVERYTHING DOWN BELOW MUST BE MOVED TO ANOTHER HEADER FILE
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
class BoundingBox
{
public:
	int left;
	int top;
	int width;
	int height;

	BoundingBox():
		left(0),
		top(0),
		width(0),
		height(0)
	{}

	BoundingBox(uint32_t l, uint32_t t, uint32_t w, uint32_t h ):
		left(l),
		top(t),
		width(w),
		height(h)
	{}
};

//-------------------------------------------------------------------------
class Geometry
{
public:
	BoundingBox BBox;
	Point2f cog;
	Point2f base;
	Point2f base_unwarped;
	Point2f base_dist;
	Point2f cogPred;
	Point2f HiDist;

	Geometry():
		BBox(0, 0, 0, 0),
		cog(0.0f, 0.0f),
		base(0.0f, 0.0f),
		base_unwarped(0.0f, 0.0f),
		base_dist(0.0f, 0.0f),
		cogPred(0.0f, 0.0f),
		HiDist(0.0f, 0.0f)
	{}
};

//-------------------------------------------------------------------------
class Est
{
public:
	Point2f position; // Estimated position
	float32_t size; // Estimated size
	float32_t velocity; // Estimated velocity

	Est():
		position(0.0f, 0.0f),
		size(0.0f),
		velocity(0.0f)
	{}
};

//-------------------------------------------------------------------------
class FinalResult
{
public:
	Point2f CenterPt;
	Point2f distance;
	unsigned char ColorCode;
	double velocity;
	int age;
	int angle;
	double height;
	double position;
	Point2f base_raw_dist; //raw object position

	FinalResult():
		CenterPt(0.0f, 0.0f),
		distance(0.0f, 0.0f),
		ColorCode(0),
		velocity(0.0),
		age(0),
		angle(0),
		height(0.0),
		position(0.0),
		base_raw_dist(0.0f, 0.0f)
	{}
};

//-------------------------------------------------------------------------
class UnitVector
{
public:
	float32_t angle;
	float32_t ang_sin;
	float32_t ang_cos;
	float32_t velocity;
	
	UnitVector():
		angle(0.0f),
		ang_sin(0.0f),
		ang_cos(1.0f),
		velocity(0.0f)
	{}
};

#endif /* #ifndef _CAMERAPOINT_H_ */
