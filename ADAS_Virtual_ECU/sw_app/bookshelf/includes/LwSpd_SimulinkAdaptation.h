//--------------------------------------------------------------------------
/// @file LwSpd_SimulinkAdaptation.h
/// @brief Contains LwSpd_SimulinkAdaptation struct definition
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Rohit Borse (rohit.borse@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef LwSpd_SimulinkAdaptation_H_INCGUARD
#define LwSpd_SimulinkAdaptation_H_INCGUARD

#include "PlatformDataTypes.h"
#include "float32_t.h"

#if !defined(BUILD_MCU1_0)
typedef struct 
{
	float32_t x;
	float32_t y;
}Float2;

typedef struct
{
	sint32_t x;
	sint32_t y;
}Int2;

typedef struct
{
	float64_t x;
	float64_t y;
}Float2d;
#endif
#endif //LwSpd_SimulinkAdaptation_H_INCGUARD
