/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

/*
 * PlatformAssert.h
 *
 *  Creation Date: 24.09.2021
 *         Author: Sivakumar Asoka Kumaran
 *        Company: Magna Electronics
 */

#ifndef ME_ATOMIC_H
#define ME_ATOMIC_H

#include "platform/PlatformSpecs.h"
#include "platform/stdlib/StdLibTypes.h"

// PRQA S 3412 EOF // unrecognized code fragments used here by design
// PRQA S 1020 EOF // macros needed here for Assert function

#if defined(__cplusplus)
extern "C"
{
#endif
// --------------------------------------------------------------------------
/// A function to perform atomic addition
///
/// Atomic variable and value to add
///
/// @param[in] i_Location_pu32,i_Increment_u32
// --------------------------------------------------------------------------
PlatformError_t ME_Atomic_Add_t(atomic_address_t *i_Location_pu32,uint32_t i_Increment_u32);
// --------------------------------------------------------------------------
/// A function to perform atomic addition and return the value , prior to addition
///
/// Atomic variable and value to add
///
/// @param[in] i_Location_pu32,i_Increment_u32
///       [out] o_Previousvalue_pu32
// --------------------------------------------------------------------------
PlatformError_t ME_Atomic_Add_Value_t(atomic_address_t *i_Location_pu32,uint32_t i_Increment_u32,uint32_t *o_Previousvalue_pu32);
// --------------------------------------------------------------------------
/// A function to perform atomic bit clear operation
///
/// Atomic variable and bits to clear
///
/// @param[in] i_Location_pu32,i_Bits_u32
// --------------------------------------------------------------------------
PlatformError_t ME_Atomic_Clr(atomic_address_t *i_Location_pu32,uint32_t i_Bits_u32);
// --------------------------------------------------------------------------
/// A function to perform atomic clear operation and return the value prior to clear
///
/// Atomic variable and bits to clear
///
/// @param[in] i_Location_pu32,i_Bits_u32
///       [out] o_Previousvalue_pu32
// --------------------------------------------------------------------------
PlatformError_t ME_Atomic_Clr_Value_t(atomic_address_t *i_Location_pu32,uint32_t i_Bits_u32,uint32_t *o_Previousvalue_pu32);
// --------------------------------------------------------------------------
/// A function to perform atomic bit set operation
///
/// Atomic variable and bits to set
///
/// @param[in] i_Location_pu32,i_Bits_u32
// --------------------------------------------------------------------------
PlatformError_t ME_Atomic_Set(volatile uint32_t *i_Location_pu32,uint32_t i_Bits_u32);
// --------------------------------------------------------------------------
/// A function to perform atomic set bit operation and return the value prior to clear
///
/// Atomic variable and bits to set
///
/// @param[in] i_Location_pu32,i_Bits_u32
///       [out] o_Previousvalue_pu32
// --------------------------------------------------------------------------
PlatformError_t ME_Atomic_Set_Value_t(volatile uint32_t *i_Location_pu32,uint32_t i_Bits_u32,uint32_t *o_Previousvalue_pu32);
// --------------------------------------------------------------------------
/// A function to perform atomic subtraction
///
/// Atomic variable and value to subtraction
///
/// @param[in] i_Location_pu32,i_Decrement_u32
// --------------------------------------------------------------------------
PlatformError_t ME_Atomic_Sub_t(volatile uint32_t *i_Location_pu32,uint32_t i_Decrement_u32);
// --------------------------------------------------------------------------
/// A function to perform atomic subtraction and return the value prior to subtraction
///
/// Atomic variable and value to subtract
///
/// @param[in] i_Location_pu32,i_Decrement_u32
///       [out] o_Previousvalue_pu32
// --------------------------------------------------------------------------
PlatformError_t ME_Atomic_Sub_Value_t(volatile uint32_t *i_Location_pu32,uint32_t i_Decrement_u32,uint32_t *o_Previousvalue_pu32);
// --------------------------------------------------------------------------
/// A function to perform atomic toggle
///
/// Atomic variable and value to toggle
///
/// @param[in] i_Location_pu32,i_Decrement_u32
// --------------------------------------------------------------------------
PlatformError_t ME_Atomic_Toggle_t(volatile uint32_t *i_Location_pu32,uint32_t i_Decrement_u32);
// --------------------------------------------------------------------------
/// A function to perform atomic toggle and return the value prior to toggle
///
/// Atomic variable and value to toggle
///
/// @param[in] i_Location_pu32,i_Decrement_u32
///       [out] o_Previousvalue_pu32
// --------------------------------------------------------------------------
PlatformError_t ME_Atomic_Toggle_Value_t(volatile uint32_t *i_Location_pu32,uint32_t i_Decrement_u32,uint32_t *o_Previousvalue_pu32);

#if defined(__cplusplus)
}; // extern C
#endif


#endif /* ME_ASSERT_H */
