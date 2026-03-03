//--------------------------------------------------------------------------
/// @file LensAxios3d.h
/// @brief Contains the lens model interface.
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
#ifndef __MECL_MODLE_LENSAAXIOS3D_H__
#define __MECL_MODLE_LENSAAXIOS3D_H__

#include "core/MeclTypes.h"
#include "core/Matrix.h"

namespace mecl {
namespace model {


//--------------------------------------------------------------------------
/// @class LensAxios3D
/// @brief Axis3D camera model implementation 
///
/// The Axis3D camera model was used durung the SVS surround view project.
// --------------------------------------------------------------------------
class LensAxios3D
{
public:

  //! @struct Config_s
  //! @brief Configuration data set
  struct Config_s
  {
    float32_t a1_f32;	//!< first      radial coefficient
    float32_t a2_f32;	//!< second     radial coefficient
    float32_t a3_f32;	//!< third      radial coefficient
    float32_t b1_f32;	//!< first  tangential coefficient
    float32_t b2_f32;	//!< second tangential coefficient
    float32_t c1_f32;	//!< first      affine coefficient
    float32_t c2_f32;	//!< second     affine coefficient
    float32_t r0_f32;	//!< zero crossing value
    float32_t pX_f32;	//!< optical axis x-offset
    float32_t pY_f32;	//!< optical axis y-offset
  };


  // *******************************
  // * construtors and initialization

  //! Default constructor
  LensAxios3D(void);

  //! Construtor with initialization
  explicit LensAxios3D(const Config_s* i_LensConfig_ps);

  //! configuration of lens parameters
  void config_v(const Config_s* i_LensConfig_ps);


  // *******************************
  // * operations

  //! Distore pixel location
  template<typename _Tp, int n>
  void applyDistortion_v(const core::Matrix<_Tp, 3, n>& i_Pos_ro, const float32_t& i_DistLevel_rf32, core::Matrix<_Tp, 2, n> &o_Pos_ro);

  //! Undistore pixel location
  template<typename _Tp, int n>
  void applyUndistortion_v(const core::Matrix<_Tp, 2, n>& i_Pos_ro, const float32_t& i_DistLevel_rf32, core::Matrix<_Tp, 2, n> &o_Pos_ro);

  void warpVector_v(float32_t& b_PosX_rf32, float32_t& b_PosY_rf32, float32_t& b_PosZ_rf32, const float32_t& i_DistLevel_rf32) const;


private:

  void applyEolData_v(float32_t& b_PosX_rf32, float32_t& b_PosY_rf32) const;

  float32_t a1_f32;               //< first      radial coefficient
  float32_t a2_f32;               //< second     radial coefficient
  float32_t a3_f32;               //< third      radial coefficient
  float32_t b1_f32;               //< first  tangential coefficient
  float32_t b2_f32;               //< second tangential coefficient
  float32_t c1_f32;               //< first      affine coefficient
  float32_t c2_f32;               //< second     affine coefficient
  float32_t r0_f32;               //< zero crossing value
  float32_t pX_f32;               //< optical axis x-offset
  float32_t pY_f32;               //< optical axis y-offset

  bool_t configured_b;            //< true if lens is configured
};


//--------------------------------------------------------------------------
/// @brief Distore pixel location
///
///
///
/// @param i_Pos_ro			Matrix of undistored input point locations
/// @param i_DistLevel_rf32	Distortion level
/// @param o_Pos_ro			Matrix of distrorted point locations
// -------------------------------------------------------------------------- 
template<typename _Tp, int n> 
void LensAxios3D::applyDistortion_v(const core::Matrix<_Tp, 3, n>& i_Pos_ro, const float32_t& i_DistLevel_rf32, core::Matrix<_Tp, 2, n> &o_Pos_ro)
{
  if(true == configured_b)
  {

  }
};


//--------------------------------------------------------------------------
/// @brief Undistore pixel location
///
///
///
/// @param i_Pos_ro			Matrix of distored input point locations
/// @param i_DistLevel_rf32	Distortion level
/// @param o_Pos_ro			Matrix of undistrorted point locations
// -------------------------------------------------------------------------- 
template<typename _Tp, int n> 
void LensAxios3D::applyUndistortion_v(const core::Matrix<_Tp, 2, n>& i_Pos_ro, const float32_t& i_DistLevel_rf32, core::Matrix<_Tp, 2, n> &o_Pos_ro)
{
  if(true == configured_b)
  {

  }
};


}; // namespace model
}; // namespace mecl

#endif // __MECL_MODLE_LENSAAXIOS3D_H__
/// @}
/// @}
