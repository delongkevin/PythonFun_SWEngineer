//--------------------------------------------------------------------------
/// @file LensStretchVertical.h
/// @brief Vertical stretch lens model
///
/// The lens model provides a warping and an un-warping function.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Hagen Marczok (hagen.marczok@magna.com)
///
//  --------------------------------------------------------------------------
/// \addtogroup mecl
/// @{
/// \addtogroup model
/// @{

#ifndef MECL_MODEL_LENSSTRETCHVERTICAL_H_
#define MECL_MODEL_LENSSTRETCHVERTICAL_H_


#include "mecl/math/Math.h"
#include "mecl/math/FPolynomial.h"
#include "mecl/core/Matrix.h"
#include "mecl/core/Point.h"
#include "ILens.h"

namespace mecl
{
namespace model
{

//--------------------------------------------------------------------------
/// @class Lens
/// @brief Vertical stretch lens model
///
/// Model of a vertically stretched radial camera lens.
/// Implements radial lens correction plus a vertical stretch functionality
/// (distortion/undistortion)
// --------------------------------------------------------------------------
template<typename T, uint32_t od=5, uint32_t ou=5, uint32_t of=6, uint32_t ob=6>
class LensStretchVertical : public ILens<T>
{
public:

  /// @struct Config_s
  /// @brief Configuration data set
  struct Config_s
  {
    T world2image_x[od+1];       ///< Radial distortion polynomial (world to image)
    T image2world_x[ou+1];       ///< Radial undistortion polynomial (image to world)
    T elevationMaxCfg_x;         ///< Maximal applicable elevation angle in degrees,
                                 ///< valid range is [0,180]
    T stretchFactor_x[of+1];     ///< Vertical stretch factor polynomial
    T stretchBase_x[ob+1];       ///< Vertical stretch base polynomial
  };

  /// Default constructor
  LensStretchVertical(void);

  /// Constructor with initialization
  explicit LensStretchVertical(const Config_s& i_LensConfig_rs);

  /// Virtual destructor
  virtual ~LensStretchVertical(void) {};

  /// Copy configuration of lens parameters to POD
  void copyConfig_v(Config_s& o_Config_rs) const;

  /// Copy configuration of lens parameters to POD of different base type T1
  template<typename T1>
  void copyConfig_v(typename LensStretchVertical<T1, od, ou, of, ob>::Config_s& o_Config_rs) const;

  /// Copy configuration of lens parameters to volatile POD
  void copyConfigVolatile_v(volatile Config_s& o_Config_rs) const;

  /// Update configuration of lens parameters
  void updateConfig_v(const Config_s& i_LensConfig_rs);

  /// Update configuration of lens parameter with POD of different base type T1
  template<typename T1>
  void updateConfig_v(const typename LensStretchVertical<T1, od, ou, of, ob>::Config_s& i_Config_rs);

  /// Returns true if lens was properly configured
  virtual bool_t isConfigured_b(void) const;

  /// Applies lens distortion to undistorted points in camera coordinate system
  virtual bool_t applyDistortion_b(const core::Point3D<T>& i_Pos_rx,
                                         core::Point2D<T>& o_Pos_rx) const;

  /// Removes distortion of metric image coordinates
  virtual void applyUndistortion_v(const core::Point2D<T>& i_Pos_rx,
                                         core::Point3D<T>& o_Pos_rx) const;

  /// Checks 3D coordinates if it is applicable to the lens model
  virtual bool_t isApplicable_b(const core::Point3D<T>& i_Pos_rx) const;

  /// Get field of view for which this lens model is applicable
  virtual typename ILens<T>::FieldOfView_s getFieldOfView_s(AngleUnit_e i_AngleUnit_e = e_Degrees) const;

  /// Get field of view for a image area defined by rectangle spanned by 2 metric coordinates
  virtual typename ILens<T>::FieldOfView_s getFieldOfView_s(const core::Point2D<T>& i_Pos1_rx,
                                                            const core::Point2D<T>& i_Pos2_rx,
                                                            AngleUnit_e i_AngleUnit_e = e_Degrees) const;

  /// convert this lens to a different base type
  template<typename T1>
  LensStretchVertical<T1, od, ou, of, ob> convert_x(void) const;

  /// try to get vertical stretch lens model from ILens reference
  static LensStretchVertical<T, od, ou, of, ob>& get_rx(ILens<T>& i_ILens_rx);

  /// try to convert vertical stretch lens model from ILens reference of different base type
  template<typename T1>
  static LensStretchVertical<T, od, ou, of, ob> convert_x(ILens<T1>& i_Lens_rx);

  /// cast operator for conversion
  template<typename T1>
  operator LensStretchVertical<T1, od, ou, of, ob>() const;

private:

  Config_s coeff_s;       ///< Coefficients of distortion+udistortion and stretch factor/base polynomials
  T elevationMax_x;       ///< Maximal elevation angle in radians (@attention: configuration value is in degrees!)
  bool_t   configured_b;  ///< Flag indicating if lens object has been configured (true) or not (false)
};



} // namespace model
} // namespace mecl

#include "LensStretchVertical.hpp"

#endif // MECL_MODEL_LENSSTRETCHVERTICAL_H_
/// @}
/// @}
