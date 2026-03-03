//--------------------------------------------------------------------------
/// @file ME_Stream.h
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

#ifndef ME_STREAM_H
#define ME_STREAM_H

#include "Pixmap.h"

#include "cfg/BspTypes.h"


namespace bsp
{

typedef enum StreamPermission_e
{
  e_StreamPermissionNone,
  e_StreamPermissionAll,
  e_StreamPermissionCount,
  e_StreamPermissionInvalid
} StreamPermission_t;


typedef struct ImageBufferData_s
{
  uint8_t*       imageData_pu8;
  uint32_t       width_u32;
  uint32_t       height_u32;
  uint32_t       stride_u32;
  uint32_t       frameNumber_u32;
  bsp::PixelFormat_t  format_s32;
  Buffer_t       buffer_t;
} ImageBufferData_t;




class Stream
{

public:

  Stream();

  ~Stream();

  // --------------------------------------------------------------------------
  /// Create a data stream object within a given screen context
  ///
  /// @param[in/out]  i_ScreenStream_t
  /// @param[in] i_StreamName_pc
  /// @param[in] i_ScreenContext_t
  /// @return bool_t
  // --------------------------------------------------------------------------
  bool_t        create_b(const char_t* i_StreamName_pc, ScreenContext_t i_ScreenContext_t);

  // --------------------------------------------------------------------------
  /// Attach a consumer to a producer stream, buffers are shared between them.
  /// Returns e_PeOk, if the consumer stream is successully attached. Otherwise, check return value from
  ///
  /// @param[in]  i_ProducerStream_t
  /// @param[out] o_ConsumerStream_pt
  /// @return bool_t
  // --------------------------------------------------------------------------
  bool_t        createConsumer_b();

  // --------------------------------------------------------------------------
  /// Destroys existing video stream
  ///
  /// @param[in/out]  b_ScreenStream_t
  /// @return bool_t
  // --------------------------------------------------------------------------
  bool_t        destroy_b() const;

  // --------------------------------------------------------------------------
  /// Get access to all buffer information from a given stream.
  ///
  /// @param[in]  i_ScreenStream_pt
  /// @param[out] o_ImageBufferData_pt
  /// @return bool_t
  // --------------------------------------------------------------------------
  bool_t        acquireBuffer_b(ImageBufferData_t* o_ImageBufferData_pt, bool_t i_Blocking_b) const;

  // --------------------------------------------------------------------------------------------------
  // Event related functions

  // --------------------------------------------------------------------------
  /// Retreive ID from a given stream.
  ///
  /// @param[in]     i_ScreenStream_t
  /// @param[out]    o_StreamId_ps32
  /// @return sint32_t
  // --------------------------------------------------------------------------
  sint32_t      getId_s32() const;

  // --------------------------------------------------------------------------
  /// Waiting for a notification, that a stream with a given ID was created.
  ///
  /// @param[in]     i_ScreenContext_t
  /// @param[in]     i_StreamId_s32
  /// @param[out]    o_ScreenStream_pt
  /// @param[in]     i_TimeOut_s64
  /// @return bool_t
  // --------------------------------------------------------------------------
  bool_t        waitForProducer_b(ScreenContext_t i_ScreenContext_t, sint32_t i_ProducerStreamId_s32);

  // --------------------------------------------------------------------------
  /// Set the permission for a given stream, to allow other 'users' access the stream.
  ///
  /// @param[in]     i_ScreenStream_pt
  /// @param[in]     i_Permission_t
  /// @return bool_t
  // --------------------------------------------------------------------------
  bool_t        setPermission_b(StreamPermission_t i_Permission_t) const;

  // --------------------------------------------------------------------------
  /// Checks, if stream is already created and valid
  ///
  /// @param[in]     i_ScreenStream_pt
  /// @return bool_t
  // --------------------------------------------------------------------------
  static bool_t isValid_b(const Stream& i_Stream_ro);

private:

  static sint32_t getId_s32(const Stream_t* i_Stream_pt);

private:

  ScreenContext_t context_t;

  Stream_t        stream_t;

  Stream_t        producerStream_t;

};

} // namespace bsp

#endif // ME_SCREEN_H
