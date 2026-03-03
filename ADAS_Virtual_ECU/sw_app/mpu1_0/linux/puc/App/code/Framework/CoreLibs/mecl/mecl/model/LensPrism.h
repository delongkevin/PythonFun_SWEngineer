//--------------------------------------------------------------------------
/// @file LensPrism.h
/// @brief Prism lens model
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
///
//  --------------------------------------------------------------------------
/// \addtogroup mecl
/// @{
/// \addtogroup model
/// @{

#ifndef MECL_MODEL_LENSPRISM_H_
#define MECL_MODEL_LENSPRISM_H_

#include "mecl/math/Math.h"
#include "mecl/core/MeclTypes.h"
#include "mecl/core/Matrix.h"
#include "mecl/core/Point.h"
#include "ILens.h"

namespace mecl
{
namespace model
{

//--------------------------------------------------------------------------
/// @class LensPrism
/// @brief Prism lens model
///
/// Model of a prism camera lens.
/// Implements prism lens correction functionality (distortion/undistortion)
// --------------------------------------------------------------------------
template<typename T>
class LensPrism : public ILens<T>
{
public:

  /// @struct Config_s
  /// @brief Configuration data set
  struct Config_s
  {
    T angle_x;      ///< horizontal rotation angle of prism faces
    T dist_x;       ///< horizontal distance of line of intersection with unit image plane to principal point
  };

  /// Default constructor
  LensPrism(void);

  /// Constructor with initialization
  explicit LensPrism(const Config_s& i_LensConfig_rs);

  /// Virtual destructor
  virtual ~LensPrism(void) {};

  /// Copy configuration of lens parameter to POD struct
  void copyConfig_v(Config_s& o_LensConfig_rs) const;

  /// Copy configuration of lens parameter to volatile POD struct
  void copyConfigVolatile_v(volatile Config_s& o_LensConfig_rs) const;

  /// Copy configuration of lens parameter to POD struct of different base type T1
  template<typename T1>
  void copyConfig_v(typename LensPrism<T1>::Config_s& o_LensConfig_rs) const;

  /// Update configuration of lens parameters
  void updateConfig_v(const Config_s& i_LensConfig_rs);

  /// Update configuration of lens parameter with POD struct of different base type T1
  template<typename T1>
  void updateConfig_v(const typename LensPrism<T1>::Config_s& i_LensConfig_rs);

  /// Returns true if lens was properly configured
  virtual bool_t isConfigured_b(void) const;

  /// Applies lens distortion to undistorted points in camera coordinate system
  virtual bool_t applyDistortion_b(const core::Point3D<T>& i_Pos_rx,
                                         core::Point2D<T>& o_Pos_rx) const;

  /// Removes distortion of metric image coordinates
  virtual void applyUndistortion_v(const core::Point2D<T>& i_Pos_rx,
                                         core::Point3D<T>& o_Pos_rx) const;

  /// Checks if 3D coordinate is applicable to prism lens model
  virtual bool_t isApplicable_b(const core::Point3D<T>& i_Pos_rx) const;

  /// Gets field of view for which this lens model is applicable
  virtual typename ILens<T>::FieldOfView_s getFieldOfView_s(AngleUnit_e i_AngleUnit_e = e_Degrees) const;

  /// Gets field of view for a image area defined by rectangle spanned by 2 metric coordinates
  virtual typename ILens<T>::FieldOfView_s getFieldOfView_s(const core::Point2D<T>& i_Pos1_rx,
                                                            const core::Point2D<T>& i_Pos2_rx,
                                                            AngleUnit_e i_AngleUnit_e = e_Degrees) const;

  /// Convert this lens to a different base type
  template<typename T1>
  LensPrism<T1> convert_x(void) const;

  /// Try to convert prism lens from ILens reference
  static LensPrism<T>& get_rx(ILens<T>& i_ILens_rx);

  /// Try to convert prism lens from ILens reference of different base type
  template<typename T1>
  static LensPrism<T> convert_x(ILens<T1>& i_ILens_rx);

  /// Cast operator for conversion to different base type
  template<typename T1>
  operator LensPrism<T1>() const;

private:

  void calc_v(const Config_s& i_LensConfig_rs);

  T hfov_x;                         ///< horizontal field of view
  T angle_x;                        ///< horizontal rotation angle of prism faces
  T dist_x;                         ///< horizontal distance of line of intersection with unit image plane to principal point

  core::RotationMatrix<T> rot_x;    ///< rotation of prism with respect to unit image plane
  core::RotationMatrix<T> rotInv_x; ///< inverse (transposed) rotation matrix

  T focl_x;                         ///< focal length = normal distances of prism faces to optical center
  T foclInv_x;                      ///< reciprocal of the focal length
  T offset_x;                       ///< offset to be added to x coordinate

  bool_t configured_b;              ///< flag indicating if lens object has been configured (true) or not (false)
};

} // namespace model
} // namespace mecl

#include "LensPrism.hpp"

#endif // MECL_MODEL_LENSPRISM_H_
/// @}
/// @}
