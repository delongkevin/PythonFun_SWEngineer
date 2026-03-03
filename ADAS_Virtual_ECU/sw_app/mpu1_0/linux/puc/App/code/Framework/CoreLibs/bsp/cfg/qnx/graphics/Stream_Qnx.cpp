//--------------------------------------------------------------------------
/// @file ME_Stream_QNX.h
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

#include "bsp/graphics/Stream.h"
#include <platform/stdlib/ME_Assert.h>
#include <platform/stdlib/ME_String.h>
#include <platform/stdlib/ME_Process.h>

#ifdef ME_PLATFORM_QNX


namespace bsp
{


Stream::Stream()
  : context_t()
  , stream_t()
  , producerStream_t()
{

}

Stream::~Stream()
{

}

bool_t Stream::create_b(const char_t* i_StreamName_pc, ScreenContext_t i_ScreenContext_t)
{
  bool_t v_Result_b = false;
  screen_event_t v_ScreenEvent_t;

  sint32_t v_Error_s32 = screen_create_stream(&stream_t, i_ScreenContext_t);

  context_t = i_ScreenContext_t;

  if((i_StreamName_pc != NULL) && (v_Error_s32 == EOK))
  {
    v_Error_s32 = screen_set_stream_property_cv(stream_t, SCREEN_PROPERTY_ID_STRING, ME_String_CountCharacters_s32(i_StreamName_pc), i_StreamName_pc);
  }

  if(v_Error_s32 == EOK)
  {
    v_Result_b = setPermission_b(e_StreamPermissionNone);
  }

  if(v_Error_s32 == EOK)
  {
    v_Error_s32 = screen_create_event(&v_ScreenEvent_t);
  }

  if(v_Error_s32 == EOK)
  {
    sint32_t v_EventType_s32 = SCREEN_EVENT_CREATE;

    v_Error_s32 = screen_set_event_property_iv(v_ScreenEvent_t, SCREEN_PROPERTY_TYPE, &v_EventType_s32);

    if(v_Error_s32 == EOK)
    {
      sint32_t v_ObjectType_s32 = SCREEN_OBJECT_TYPE_WINDOW;
      v_Error_s32 = screen_set_event_property_iv(v_ScreenEvent_t, SCREEN_PROPERTY_OBJECT_TYPE, &v_ObjectType_s32);
    }
  }

  if(v_Error_s32 == EOK)
  {
    char_t* v_StreamName_pc = const_cast<char_t*>(i_StreamName_pc); // PRQA S 3083 // impossible to avoid const_cast
    v_Error_s32 = screen_set_event_property_pv(v_ScreenEvent_t, SCREEN_PROPERTY_STREAM, reinterpret_cast<void**>(&v_StreamName_pc));
  }

  if(v_Error_s32 == EOK)
  {
    v_Error_s32 = screen_send_event(i_ScreenContext_t, v_ScreenEvent_t, ME_Process_GetCurrentID_t());
  }

  if(v_Error_s32 == EOK)
  {
    v_Result_b = true;
  }

  return v_Result_b;
}

bool_t Stream::createConsumer_b()
{
  bool_t v_Result_b = false;
  sint32_t v_Result_s32 = EINVAL;

  v_Result_s32 = screen_create_stream(&stream_t, context_t);

  if(v_Result_s32 == EOK)
  {
    v_Result_s32 = screen_consume_stream_buffers(stream_t, 0, producerStream_t);
  }

  if(EOK == v_Result_b)
  {
    v_Result_b = true;
  }
  else
  {
    destroy_b();
  }

  return v_Result_b;
}

bool_t Stream::destroy_b() const
{
  bool_t v_Result_b = false;
  sint32_t v_Result_s32 = EINVAL;

  v_Result_s32 = screen_destroy_stream(stream_t);

  if(v_Result_s32 == EOK)
  {
    v_Result_b = true;
  }

  return v_Result_b;
}

// --------------------------------------------------------------------------------------------------
// Buffer related functions

bool_t Stream::acquireBuffer_b(ImageBufferData_t* o_ImageBufferData_pt, bool_t i_Blocking_b) const
{
  bool_t v_Result_b = false;
  sint32_t v_Result_s32 = EINVAL;
  screen_buffer_t v_ScreenBuffer_t = 0;
  sint32_t v_Format_s32 = 0;
  sint32_t v_Stride_s32 = 0;
  sint32_t v_Size_as32[2];

  sint32_t v_Flags_s32 = 0;

  if(true == i_Blocking_b)
  {
    v_Flags_s32 = 0;
  }

  o_ImageBufferData_pt->frameNumber_u32 = 0;

  v_Result_s32 = screen_acquire_buffer(&v_ScreenBuffer_t, stream_t, NULL, NULL, NULL, v_Flags_s32);

  if(v_ScreenBuffer_t == NULL)
  {
    v_Result_s32 = ETIMEDOUT;
  }
  else
  {
    o_ImageBufferData_pt->buffer_t = v_ScreenBuffer_t;
  }

  if(EOK == v_Result_s32)
  {
    v_Result_s32 = screen_get_buffer_property_iv(v_ScreenBuffer_t, SCREEN_PROPERTY_BUFFER_SIZE, &v_Size_as32[0]);
  }

  if(EOK == v_Result_s32)
  {
    v_Result_s32 = screen_get_buffer_property_iv(v_ScreenBuffer_t, SCREEN_PROPERTY_FORMAT, &v_Format_s32);
  }

  if(EOK == v_Result_s32)
  {
    v_Result_s32 = screen_get_buffer_property_iv(v_ScreenBuffer_t, SCREEN_PROPERTY_STRIDE, &v_Stride_s32);
  }

  if(EOK == v_Result_s32)
  {
    o_ImageBufferData_pt->width_u32 = static_cast<uint32_t>(v_Size_as32[0]);
    o_ImageBufferData_pt->height_u32 = static_cast<uint32_t>(v_Size_as32[1]);
    o_ImageBufferData_pt->format_s32 = Pixmap::mapFormat_t(v_Format_s32);
    o_ImageBufferData_pt->stride_u32 = static_cast<uint32_t>(v_Stride_s32);
  }

  if(EOK == v_Result_s32)
  {
    v_Result_s32 = screen_get_buffer_property_pv(v_ScreenBuffer_t, SCREEN_PROPERTY_POINTER, reinterpret_cast<void**>(&o_ImageBufferData_pt->imageData_pu8));
  }

  if(EOK == v_Result_s32)
  {
    v_Result_s32 = screen_release_buffer(v_ScreenBuffer_t);
  }

  if(EOK == v_Result_s32)
  {
    v_Result_b = true;
  }

  return v_Result_b;
}

sint32_t Stream::getId_s32() const
{
  return getId_s32(&stream_t);
}

bool_t Stream::waitForProducer_b(ScreenContext_t i_ScreenContext_t, sint32_t i_ProducerStreamId_s32)
{
  bool_t v_Result_b = false;
  sint32_t v_Result_s32 = EINVAL;

  screen_event_t v_ScreenEvent_t = 0;

  v_Result_s32 = screen_create_event(&v_ScreenEvent_t);

  if((v_Result_s32 == EOK) && (v_ScreenEvent_t != NULL))
  {
    sint32_t v_EventType_s32 = 0;

    v_Result_s32 = screen_get_event(i_ScreenContext_t, v_ScreenEvent_t, static_cast<uint64_t>(-1)); // PRQA S 2895 // ScreenAPI wants it like this

    if (v_Result_s32 == EOK)
    {
      v_Result_s32 = screen_get_event_property_iv(v_ScreenEvent_t, SCREEN_PROPERTY_TYPE, &v_EventType_s32);
    }

    if (v_Result_s32 == EOK)
    {
      switch(v_EventType_s32)
      {
        case SCREEN_EVENT_NONE:
        {
          v_Result_s32 = ETIMEDOUT;
          break;
        }
        case SCREEN_EVENT_CREATE:
        {
          // Got a create event, make sure it is for a window/stream creation
          sint32_t v_ObjectType_s32 = 0;
          v_Result_s32 = screen_get_event_property_iv(v_ScreenEvent_t, SCREEN_PROPERTY_OBJECT_TYPE, &v_ObjectType_s32);

          if (v_Result_s32 == EOK)
          {
            if (v_ObjectType_s32 == SCREEN_OBJECT_TYPE_STREAM)
            {
              v_Result_s32 = screen_get_event_property_pv(v_ScreenEvent_t, SCREEN_PROPERTY_STREAM, reinterpret_cast<void**>(&producerStream_t)); // PRQA S 0310 // necessary here, ScreenAPI wants it like this

              sint32_t v_StreamId_s32 = getId_s32(&producerStream_t);

              if((v_Result_s32 == EOK))
              {
                if(v_StreamId_s32 == i_ProducerStreamId_s32)
                {
                  context_t = i_ScreenContext_t;
                  v_Result_s32 = screen_destroy_event(v_ScreenEvent_t);
                }
                else
                {
                  screen_send_event(i_ScreenContext_t, v_ScreenEvent_t, ME_Process_GetCurrentID_t());
                  v_Result_s32 = EFAULT;
                }
              }
              else
              {
                ME_Debugger_F_Printf_v("ich war hier NOK [%d]: stream [%d]\n", v_Result_s32, v_StreamId_s32);
              }
            }
          }
          break;
        }
        default:
        {
          screen_destroy_event(v_ScreenEvent_t);
          v_Result_s32 = EFAULT;
          break;
        }
      }
    }
  }

  if(v_Result_s32 == EOK)
  {
    v_Result_b = true;
  }

  return v_Result_b;
}

bool_t Stream::setPermission_b(StreamPermission_t i_Permission_t)const
{
  bool_t v_Result_b = false;
  sint32_t v_Error_s32 = EINVAL;

  switch(i_Permission_t)
  {
  case e_StreamPermissionNone:
  {
    // TODO
    break;
  }
  case e_StreamPermissionAll:
  {
    sint32_t v_Permissions_s32 = (SCREEN_PERMISSION_IXOTH | SCREEN_PERMISSION_IWOTH | SCREEN_PERMISSION_IROTH); // PRQA S 3710 // QNX wants it
    v_Error_s32 = screen_set_stream_property_iv(stream_t, SCREEN_PROPERTY_PERMISSIONS, &v_Permissions_s32);
    break;
  }
  default:
  {
    // do nothing
    break;
  }
  }

  if(v_Error_s32 == EOK)
  {
    v_Result_b = true;
  }

  return v_Result_b;
}

bool_t Stream::isValid_b(const Stream& i_Stream_ro)
{
  bool_t v_Result_b = false;

  if((i_Stream_ro.stream_t != 0) && (i_Stream_ro.context_t != 0))
  {
    v_Result_b = true;
  }

  return v_Result_b;
}

sint32_t Stream::getId_s32(const Stream_t* i_Stream_pt)
{
  sint32_t v_Id_s32 = -1;
  char_t v_IdString_ac[64];

  if(EOK == screen_get_stream_property_cv(*i_Stream_pt, SCREEN_PROPERTY_ID_STRING, 64, &v_IdString_ac[0]))
  {
    if (NULL != ME_String_StrStr_pc(&v_IdString_ac[0], "stream-unit-"))
    {
      v_Id_s32 = strtol(&v_IdString_ac[12], NULL, 10);
    }
  }

  return v_Id_s32;
}

} // namespace bsp

#endif // ME_PLATFORM_QNX
