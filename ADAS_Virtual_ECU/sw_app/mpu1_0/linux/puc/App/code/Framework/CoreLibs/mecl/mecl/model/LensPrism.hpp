//--------------------------------------------------------------------------
/// @file LensPrism.hpp
/// @brief Contains the cylinder lens model implementation.
///
/// The lens model provides a warping and an un-warping function.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Helmut Zollner (helmut.zollner@magna.com)
/// @date 05/05/2017
//  --------------------------------------------------------------------------
/// \addtogroup mecl
/// @{
/// \addtogroup model
/// @{

#ifndef MECL_MODEL_LENSPRISM_HPP_
#define MECL_MODEL_LENSPRISM_HPP_

#include "LensPrism.h"

namespace mecl
{
namespace model
{

//--------------------------------------------------------------------------
/// @brief Default constructor
///
/// The default constructor initializes all member variables to default values.
// -------------------------------------------------------------------------
template<typename T>
LensPrism<T>::LensPrism(void)
: hfov_x(math::constants<T>::pi_x())
, angle_x(math::constants<T>::zero_x())
, dist_x(math::constants<T>::zero_x())
, rot_x(core::Matrix3x3<T>::eye())
, rotInv_x(core::Matrix3x3<T>::eye())
, focl_x(math::constants<T>::one_x())
, foclInv_x(math::constants<T>::one_x())
, configured_b(false)
{}

//--------------------------------------------------------------------------
/// @brief Constructor with initialization
///
/// The constructor initializes lens configuration data based on input argument.
///
/// @param[in] i_LensConfig_rs Lens configuration to be applied to this LensPrism
// -------------------------------------------------------------------------
template<typename T>
LensPrism<T>::LensPrism(const Config_s& i_LensConfig_rs)
: hfov_x(math::constants<T>::pi_x())
, angle_x(i_LensConfig_rs.angle_x)
, dist_x(i_LensConfig_rs.dist_x)
, rot_x(core::Matrix3x3<T>::eye())
, rotInv_x(core::Matrix3x3<T>::eye())
, focl_x(math::constants<T>::one_x())
, foclInv_x(math::constants<T>::one_x())
, configured_b(true)
{
  this->calc_v(i_LensConfig_rs);
}

//--------------------------------------------------------------------------
/// @brief Copy configuration of lens parameters to POD
///
/// The function copies all elements from configuration object of LensPrism to struct \p o_LensConfig_rs.
///
/// @param[out] o_LensConfig_rs Configuration to be overwritten with contents from lens configuration
/// @return void
// -------------------------------------------------------------------------
template<typename T>
void LensPrism<T>::copyConfig_v(Config_s& o_LensConfig_rs) const
{
  o_LensConfig_rs.angle_x = this->angle_x;
  o_LensConfig_rs.dist_x  = this->dist_x;
}

//--------------------------------------------------------------------------
/// @brief Copy configuration of lens parameters to volatile POD
///
/// The function copies all elements from configuration object of LensPrism to volatile struct \p o_LensConfig_rs.
///
/// @param[out] o_LensConfig_rs Configuration in volatile memory to be overwritten with contents from lens configuration
/// @return void
// -------------------------------------------------------------------------
template<typename T>
void LensPrism<T>::copyConfigVolatile_v(volatile Config_s& o_LensConfig_rs) const
{
  o_LensConfig_rs.angle_x = this->angle_x;
  o_LensConfig_rs.dist_x  = this->dist_x;
}

//--------------------------------------------------------------------------
/// @brief Copy configuration of lens parameters to POD of different base type T1
///
/// The function copies all elements from a cylinder lens model of base type T to
/// a configuration POD struct \p o_LensConfig_rs of (different) base type T1.
///
/// @param[out] o_LensConfig_rs Configuration to be overwritten with contents from lens configuration
/// @return void
// -------------------------------------------------------------------------
template<typename T>
template<typename T1>
void LensPrism<T>::copyConfig_v(typename LensPrism<T1>::Config_s& o_LensConfig_rs) const
{
  o_LensConfig_rs.angle_x = static_cast<T1>(this->angle_x);
  o_LensConfig_rs.dist_x  = static_cast<T1>(this->dist_x);
}

//--------------------------------------------------------------------------
/// @brief Update configuration of lens parameters
///
/// The function copies all elements from \p i_LensConfig_rs struct to configuration object of LensPrism.
///
/// @param[in] i_LensConfig_rs Lens configuration to be applied to this LensPrism
/// @return void
// -------------------------------------------------------------------------
template<typename T>
void LensPrism<T>::updateConfig_v(const Config_s& i_LensConfig_rs)
{
  this->calc_v(i_LensConfig_rs);

  this->configured_b = true;
}

//--------------------------------------------------------------------------
/// @brief Update configuration of lens parameters with configuration data of different base type T1
///
/// The function copies all elements from \p i_LensConfig_rs struct of base type T1 to configuration
/// object of LensPrism of (different) base type T.
///
/// @param[in] i_LensConfig_rs Lens configuration to be applied to this LensPrism
/// @return void
// -------------------------------------------------------------------------
template<typename T>
template<typename T1>
void LensPrism<T>::updateConfig_v(const typename LensPrism<T1>::Config_s& i_LensConfig_rs)
{
  const typename LensPrism<T>::Config_s c_Config_s = {static_cast<T>(i_LensConfig_rs.angle_x),
                                                      static_cast<T>(i_LensConfig_rs.dist_x )};

  this->calc_v(c_Config_s);

  this->configured_b = true;
}

//--------------------------------------------------------------------------
/// @brief Returns true if lens was properly configured
///
/// The function returns a boolean indicating if lens object has been configured (true) or not (false).
///
/// @return Boolean, Always True = configured.
// -------------------------------------------------------------------------
template<typename T>
bool_t LensPrism<T>::isConfigured_b(void) const
{
  return this->configured_b;
}

//--------------------------------------------------------------------------
/// @brief Applies lens prism distortion to undistorted points in camera coordinate system
///
/// The function applies prism distortion to 3D camera input point \p i_Pos_rx and returns 2D distorted point in
/// image coordinate system
///
/// @param[in]  i_Pos_rx 3D coordinate of point to be distorted
/// @param[out] o_Pos_rx Distorted 2D coordinates of input point i_Pos_rx in image coordinate system.
/// @return true, if 3D point (direction) is applicable, otherwise false
// -------------------------------------------------------------------------
template<typename T>
bool_t LensPrism<T>::applyDistortion_b(const core::Point3D<T>& i_Pos_rx,
                                             core::Point2D<T>& o_Pos_rx) const
{
  bool_t v_Applicable_b = false;

  if (not  math::isZero_b<T>(i_Pos_rx(2))
       && (math::abs_x<T>(i_Pos_rx(0) / i_Pos_rx(2)) < this->dist_x))
  {
    o_Pos_rx(0) = i_Pos_rx.getNormalized()(0);
    o_Pos_rx(1) = i_Pos_rx.getNormalized()(1);

    v_Applicable_b = true;
  }
  else
  {
    core::Point3D<T> v_Pos_x(math::abs_x(i_Pos_rx(0)), i_Pos_rx(1), i_Pos_rx(2));

    v_Pos_x = this->rotInv_x.mmulFast(v_Pos_x);

    if (not math::isZero_b(v_Pos_x(2)))
    {
      v_Pos_x.normalize(this->foclInv_x);

      o_Pos_rx(0) = (v_Pos_x.getPosX() + this->offset_x) * math::sgn_x(i_Pos_rx(0));
      o_Pos_rx(1) =  v_Pos_x.getPosY();

      v_Applicable_b = true;
    }
  }

  return v_Applicable_b;
}

//--------------------------------------------------------------------------
/// @brief Checks if 3D coordinate is applicable to prism lens model
///
/// Point is applicable if ... (TODO)
///
/// @param[in] i_Pos_rx 3D coordinate of point to be checked
/// @return true, if 3D Point (direction) is applicable, otherwise false
// -------------------------------------------------------------------------

template<typename T>
bool_t LensPrism<T>::isApplicable_b(const core::Point3D<T>& i_Pos_rx) const
{
  return (i_Pos_rx.getElevationHorizontal(e_Radians) < (this->hfov_x / static_cast<T>(2)));
}

//--------------------------------------------------------------------------
/// @brief Gets field of view for which this lens model is applicable
///
/// Gets field of view of this lens in horizontal, vertical and applicable range
///
/// @param[in] i_AngleUnit_e defines degrees or radians
/// @return field of view for lens model
// -------------------------------------------------------------------------
template<typename T>
typename ILens<T>::FieldOfView_s LensPrism<T>::getFieldOfView_s(AngleUnit_e i_AngleUnit_e) const
{
  const T c_Pi_x  = i_AngleUnit_e == e_Radians ? math::constants<T>::pi_x() : static_cast<T>(180);
  const T c_Pi2_x = c_Pi_x + c_Pi_x;

  const typename ILens<T>::FieldOfView_s c_FOV_x = {c_Pi2_x, c_Pi2_x, c_Pi_x, c_Pi_x, c_Pi2_x, 0.0F, 0.0F, i_AngleUnit_e};

  return c_FOV_x;
}

/// Gets field of view for a image area defined by rectangle spanned by 2 metric coordinates
template<typename T>
typename ILens<T>::FieldOfView_s LensPrism<T>::getFieldOfView_s(const core::Point2D<T>& i_Pos1_rx,
                                                                const core::Point2D<T>& i_Pos2_rx,
                                                                AngleUnit_e i_AngleUnit_e) const
{
  typename ILens<T>::FieldOfView_s v_FieldOfView_s = {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, i_AngleUnit_e};

  core::Point3D<T> v_Pos1_x;
  core::Point3D<T> v_Pos2_x;

  this->applyUndistortion_v(i_Pos1_rx, v_Pos1_x);
  this->applyUndistortion_v(i_Pos2_rx, v_Pos2_x);

  const T c_SignHorz_x = math::sgn_x(i_Pos1_rx.getPosX()) * math::sgn_x(i_Pos2_rx.getPosX());
  const T c_SignVert_x = math::sgn_x(i_Pos1_rx.getPosY()) * math::sgn_x(i_Pos2_rx.getPosY());

  v_FieldOfView_s.horizontal_x = v_Pos1_x.getElevationHorizontal(i_AngleUnit_e)
                               - v_Pos2_x.getElevationHorizontal(i_AngleUnit_e) * c_SignHorz_x;

  v_FieldOfView_s.vertical_x   = v_Pos1_x.getElevationVertical(i_AngleUnit_e)
                               - v_Pos2_x.getElevationVertical(i_AngleUnit_e) * c_SignVert_x;

  v_FieldOfView_s.centricHorizontal_x = v_FieldOfView_s.horizontal_x;
  v_FieldOfView_s.centricVertical_x   = v_FieldOfView_s.vertical_x;

  const core::Point2D<T> c_Centroid_x((i_Pos1_rx + i_Pos2_rx) / static_cast<T>(2));

  core::Point3D<T> v_Centroid_x;

  this->applyUndistortion_v(c_Centroid_x, v_Centroid_x);

  v_FieldOfView_s.horizontalShift_x = v_Centroid_x.getElevationHorizontal(i_AngleUnit_e);
  v_FieldOfView_s.verticalShift_x   = v_Centroid_x.getElevationVertical(i_AngleUnit_e);

  return v_FieldOfView_s;
}

//--------------------------------------------------------------------------
/// @brief Removes distortion of metric image coordinates
///
/// The function applies undistortion of 2D image input point \p i_Pos_rx and returns undistorted 3D point
/// in camera coordinate system.
///
/// @param[in]  i_Pos_rx Distorted 2D coordinate of image point to be undistorted
/// @param[out] o_Pos_rx Undistorted 3D coordinates of input point i_Pos_rx in camera coordinate system.
// -------------------------------------------------------------------------
template<typename T>
void LensPrism<T>::applyUndistortion_v(const core::Point2D<T>& i_Pos_rx,
                                             core::Point3D<T>& o_Pos_rx) const
{
  if (math::abs_x<T>(i_Pos_rx(0)) < this->dist_x)
  {
    // x and y coordinates are not modified
    o_Pos_rx(0) = i_Pos_rx(0);
    o_Pos_rx(1) = i_Pos_rx(1);
    o_Pos_rx(2) = math::constants<T>::one_x();
  }
  else
  {
    core::Point3D<T> v_Pos3d_x(math::abs_x(i_Pos_rx(0)) - this->offset_x, i_Pos_rx(1), this->focl_x);

    v_Pos3d_x = this->rot_x.mmulFast(v_Pos3d_x);

    o_Pos_rx(0) = v_Pos3d_x(0) * math::sgn_x(i_Pos_rx(0));
    o_Pos_rx(1) = v_Pos3d_x(1);
    o_Pos_rx(2) = v_Pos3d_x(2);
  }
}

//--------------------------------------------------------------------------
/// @brief Create a copy of this instance of different base type T1
///
/// The function returns a copy of this instance having converted all its \n
/// floating point values of base type T to new base type T1
///
/// @return Copy of this instance of base type T1
//--------------------------------------------------------------------------
template<typename T>
template<typename T1> inline
LensPrism<T1> LensPrism<T>::convert_x(void) const
{
  typename LensPrism<T1>::Config_s v_Config_s = {};

  this->copyConfig_v(v_Config_s);

  return LensPrism<T1>(v_Config_s);
}

//--------------------------------------------------------------------------
/// @brief Get a LensPrism reference by down-casting a reference to ILens
///
/// The functions tries to cast the ILens reference to a reference of an LensPrism
/// instance. On failure this causes an assertion, otherwise the function returns
/// a valid reference to a LensPrism instance
///
/// @return Valid reference to an instance of LensPrism
//--------------------------------------------------------------------------
template<typename T>
LensPrism<T>& LensPrism<T>::get_rx(ILens<T>& i_ILens_rx)
{
  LensPrism<T>* v_Lens_px = dynamic_cast<LensPrism<T>*>(&i_ILens_rx);

  AssertFunction(NULL != v_Lens_px, "ILens reference is not a prism lens.");

  return *v_Lens_px;
}

//--------------------------------------------------------------------------
/// @brief Get an instance of LensPrism<T> referenced by ILens<T1>&
///
/// The functions tries to cast the ILens of base type T1 reference to a LensPrism
/// instance of base type T1. On failure this causes an assertion,
/// otherwise the function returns a copy of that instance converted to base type T.
///
/// @return Instance of LensPrism of base type T
//--------------------------------------------------------------------------
template<typename T>
template<typename T1>
LensPrism<T> LensPrism<T>::convert_x(ILens<T1>& i_ILens_rx)
{
  LensPrism<T1>& v_Lens_rx = LensPrism<T1>::get_rx(i_ILens_rx);

  return v_Lens_rx.template convert_x<T>();
}

//--------------------------------------------------------------------------
/// @brief Cast operator for conversion to different base type T1
///
/// Operator casts a LensPrism<T> object to different base type T1.
///
/// @return Instance of LensPrism of base type T1
//--------------------------------------------------------------------------
template<typename T>
template<typename T1>
LensPrism<T>::operator LensPrism<T1>() const
{
  return this->convert_x<T1>();
}

template<typename T>
void LensPrism<T>::calc_v(const Config_s& i_LensConfig_rs)
{
  this->angle_x = i_LensConfig_rs.angle_x;
  this->dist_x  = i_LensConfig_rs.dist_x;
  this->hfov_x  = math::constants<T>::pi_x() + static_cast<T>(2) * this->angle_x;

  const T c_SinAngle_x = math::trigonometry<T>::sin_x(this->angle_x);
  const T c_CosAngle_x = math::trigonometry<T>::cos_x(this->angle_x);

  this->offset_x  = this->dist_x + c_SinAngle_x - this->dist_x * c_CosAngle_x;
  this->focl_x    = this->dist_x * c_SinAngle_x +                c_CosAngle_x;

  this->foclInv_x = math::constants<T>::one_x() / this->focl_x;

  const typename core::RotationMatrix<T>::EulerAngles_s c_EulerAngles_s = { math::constants<T>::zero_x(),
                                                                            this->angle_x,
                                                                            math::constants<T>::zero_x()
                                                                          };
  this->rot_x.init_v(c_EulerAngles_s);
  this->rotInv_x = static_cast< core::RotationMatrix<T> >(this->rot_x.t());
}

} // namespace model
} // namespace mecl

#endif // MECL_MODEL_LENSPRSIM_HPP_

/// @}
/// @}
