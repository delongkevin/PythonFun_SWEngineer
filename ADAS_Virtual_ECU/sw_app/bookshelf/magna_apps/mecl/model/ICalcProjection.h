//--------------------------------------------------------------------------
/// @file ICalcProjection.h
/// @brief Contains the interface for the class Pinhole.
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

#ifndef MECL_MODEL_ICALCPROJECTION_H_
#define MECL_MODEL_ICALCPROJECTION_H_

//! @cond
// PRQA S 1020 1 // macro is used by MKS
#define ICalcProjection_D_VERSION_ID "$Id: ICalcProjection.h 1.6 2015/05/04 12:09:07EDT Zollner, Helmut (SAI_HeZol) draft  $"
//! @endcond

namespace mecl
{
namespace core
{
/// @cond
// --------------------------------------------------------------------------
// Empty Matrix class definition to allow compilation of ICalcProjection 
// without including "Core/Matrix.h".
//
// --------------------------------------------------------------------------
template <typename T, uint32_t m, uint32_t n>
class Matrix;
/// @endcond

} // namespace core

namespace model
{
// --------------------------------------------------------------------------
/// @class ICalcProjection
/// @brief Partial interface for the Pinhole camera class.
///
// --------------------------------------------------------------------------
template <typename T>
class ICalcProjection
{
public:
  /// Deconstructor
  virtual ~ICalcProjection() {};

  /// Calculate projection matrix based on translation and rotation matrices
  virtual void calc_v(mecl::core::Matrix<T, 3, 4>& o_Projection_rx) const = 0;

};

} // namespace model
} // namespace mecl

#endif // MECL_MODEL_ICALCPROJECTION_H_

/// @}
/// @}
