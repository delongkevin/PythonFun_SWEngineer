//--------------------------------------------------------------------------
/// @file ME_Pixmap.h
/// @brief Interface to abstract standard-library Thread
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

#ifndef PIXMAP_H
#define PIXMAP_H

#include "cfg/BspTypes.h"


namespace bsp
{


typedef enum PixelFormat_e
{
  e_RGB888 = 0,
  e_RGBA8888,
  e_Grey8,
  e_NV16,
  e_PixelFormatInvalid,
  e_PixelFormatCount
} PixelFormat_t;


class Pixmap
{

public:

  Pixmap();

  ~Pixmap();

  // --------------------------------------------------------------------------
  /// Maps the platform independent pixmap format to a platform specific pixmap format
  ///
  /// @param[in] i_Format_t
  /// @return sint32_t
  // --------------------------------------------------------------------------
  static sint32_t      mapFormat_s32(PixelFormat_t i_Format_t);

  // --------------------------------------------------------------------------
  /// Maps a given integer pixmap format to a platform independent pixmap format
  ///
  /// @param[in] i_Format_s32
  /// @return PixelFormat_t
  // --------------------------------------------------------------------------
  static PixelFormat_t mapFormat_t(sint32_t i_Format_s32);

  // --------------------------------------------------------------------------
  /// Creates a pixmap object within a given screen context
  ///
  /// @param[in/out] b_Pixmap_pt
  /// @param[in]     i_ScreenContext_t
  /// @param[in]     i_Width_u32
  /// @param[in]     i_Height_u32
  /// @param[in]     i_Format_e
  /// @return bool_t
  // --------------------------------------------------------------------------
  bool_t              create_b(ScreenContext_t i_ScreenContext_t,
                               uint32_t i_Width_u32, uint32_t i_Height_u32,
                               PixelFormat_t i_Format_e);


  // --------------------------------------------------------------------------
  /// Returns the pointer to a pixmap buffer and provides the size of the image within the pixmap
  ///
  /// @param[in]  i_Pixmap_pt
  /// @param[out] o_Pointer_ppu8
  /// @param[out] o_Width_pu32
  /// @param[out] o_Height_pu32
  /// @return PlatformError_t
  // --------------------------------------------------------------------------
  bool_t              getPointer_b(uint8_t** o_Pointer_ppu8, uint32_t* o_Width_pu32, uint32_t* o_Height_pu32) const;


private:

  Pixmap_t            pixmap_t;

};


class Buffer
{

public:

  Buffer();

  ~Buffer();

  // --------------------------------------------------------------------------
  /// Destroys and releases the buffer object
  ///
  /// @param[in/out] i_Buffer_pt
  /// @return bool_t
  // --------------------------------------------------------------------------
  static bool_t release_b(const Buffer_t* i_Buffer_pt);

private:

  Buffer_t buffer_t;

};

} // namespace bsp

#endif // ME_PIXMAP_H
