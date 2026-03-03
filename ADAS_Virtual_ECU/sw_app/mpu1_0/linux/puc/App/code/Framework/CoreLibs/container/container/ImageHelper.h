//--------------------------------------------------------------------------
/// @file Image.h
/// @brief This is the short description of the template module
///
/// Here may follow a longer description for the template module with examples.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------
/// \addtogroup mecl
/// @{
/// \addtogroup image
/// @{
/// @brief Magna Electronics Image Library

#ifndef IMAGEHELPER_H_
#define IMAGEHELPER_H_

#include <platform/PlatformAPI.h>

namespace container
{
namespace imagehelper
{

extern PlatformError_t Yuv422ToGrey8_t(const uint8_t* i_Yuv422_pu8, uint8_t* o_Grey8_pu8, uint32_t i_Width_u32, uint32_t i_Height_u32);

extern PlatformError_t Yuv422ToRgba8888_t(const uint8_t* i_Yuv422_pu8, uint8_t* o_Rgba8888_pu8, uint32_t i_Width_u32, uint32_t i_Height_u32);

} // namespace imagehelper
} // namespace container

#endif // MECL_IMAGE_IMAGE_H_
/// @}
/// @}
