/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

//--------------------------------------------------------------------------
/// @file PixelFormatTypes.h
/// @brief Generic Header withg enum to list all pixel formats.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------


#ifndef ME_PIXEL_FORMAT_TYPES_H
#define ME_PIXEL_FORMAT_TYPES_H

#include "platform/PlatformSpecs.h"
 // global scope, this is a shared c and cpp header file

#if defined(__cplusplus)
extern "C"
{
namespace mepl
{
#endif


// !!! Attention !!! if you change this Enum, you will break the serialization in me3d
enum PixelFormat_e
{
  // Depth GPU Formats
  e_RfD16 = 0,
  e_RfD24S8,
  e_RfD32F,

  // Standard GPU Formats
  e_RfR8G8B8X8,
  e_RfR8G8B8A8,
  e_RfR8G8B8A8SRGB,
  e_RfR8,
  e_RfR8G8,
  e_RfR8G8B8,
  e_RfR5G6B5,
  e_RfR24X8,

  // One Component Formats
  e_RfR16F,
  e_RfR16UINT,
  e_RfR32F,
  e_RfR32UINT,

  // Two Component Formats
  e_RfR32G32F,
  e_RfR32G32UINT,

  // Three-component formats
  e_RfR32G32B32F,

  // Four-component formats
  e_RfR16G16B16A16F,
  e_RfR16G16B16A16UINT,
  e_RfR32G32B32A32F,

  // Compressed Formats
  e_RfEtc1,

  // Special formats


  e_RfCount,
  e_RfUnknown
};


#if defined(__cplusplus)
} // namespace mepl

}; // extern C
#endif


#endif // ME_STD_LIB_TYPES_H
