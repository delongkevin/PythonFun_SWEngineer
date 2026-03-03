//--------------------------------------------------------------------------
/// @file EolMData.cpp
/// @brief Contains the base functions for all data containers
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@Magna.com)
///
//  --------------------------------------------------------------------------

#include "EolMData.h"
#include <platform/stdlib/ME_Assert.h>

#if defined (__EOLTEST)
static const uint8_t c_Left_au8[container::EolMData::c_ImgLength_u32] = 
{
#include "eoldata/Left.img"
};
static const uint8_t c_Right_au8[container::EolMData::c_ImgLength_u32] = 
{
#include "eoldata/Right.img"
};
static const uint8_t c_Rear_au8[container::EolMData::c_ImgLength_u32] = 
{
#include "eoldata/Rear.img"
};
static const uint8_t c_Front_au8[container::EolMData::c_ImgLength_u32] = 
{
#include "eoldata/Front.img"
};
#endif

namespace container
{

EolMData::EolMData()
  : DataContainer()
  , mutex_o()
{
    memset(getImageBuffer_pu8(variants::e_CameraFront), 0, c_ImgLength_u32);
    memset(getImageBuffer_pu8(variants::e_CameraLeft), 0, c_ImgLength_u32);
    memset(getImageBuffer_pu8(variants::e_CameraRear), 0, c_ImgLength_u32);
    memset(getImageBuffer_pu8(variants::e_CameraRight), 0, c_ImgLength_u32);
}

EolMData::~EolMData()
{
}


}; // namespace container
