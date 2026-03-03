//--------------------------------------------------------------------------
/// @file DataInputAlgoStream.h
/// @brief Contains

/// DataProvider is an interface between the application module and the shared memory.
/// It implements the pure virtual interface definition to adapt the
/// module/component to the framework by specifying where the data comes from
/// or goes to. This means, this file contains all the interfaces required
/// to access input and output data.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------
/// \addtogroup container
/// @{

#include "VideoStreamProvider.h"

#include <osal/threading/Mutex.h>

#include <logging/Logger.h>




namespace container
{

typedef enum StreamHumanVisionId_e
{
  e_StreamHumanVisionIdRight = 1,
  e_StreamHumanVisionIdRear,
  e_StreamHumanVisionIdFront,
  e_StreamHumanVisionIdLeft,
  e_StreamHumanVisionIdCount,
  e_StreamHumanVisionIdInvalid
} StreamHumanVisionId_t;


VideoStreamConsumer::VideoStreamConsumer()
  : streamId_s32(-1)
  , screenContext_t()
  , stream_o()
  , producerStreamAvailable_b(false)
{
}

VideoStreamConsumer::~VideoStreamConsumer()
{

}


bool_t VideoStreamConsumer::init_b(variants::Camera_t i_CameraId_t, ScreenContext_t i_ScreenContext_t)
{
  bool_t v_Result_b = false;

  if(producerStreamAvailable_b == false)
  {
    ThreadHandle_s v_Thread_s;

    streamId_s32 = mapCameraToStreamId_s32(i_CameraId_t);
    screenContext_t = i_ScreenContext_t;

    logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf, "VideoStreamProvider::init_v() - Stream [%d], Camera [%d]", streamId_s32, i_CameraId_t);

    ME_Thread_Create_t(&v_Thread_s, &waitForProducer_pv, static_cast<void*>(this), ME_Thread_C_DefaultStackSize_t);
    ME_Thread_Attribute_SetPriority_e(&v_Thread_s, e_PriorityRealtime);
  }

  return v_Result_b;
}


void* VideoStreamConsumer::waitForProducer_pv(void* arg)
{
  VideoStreamConsumer* v_Job_po = (reinterpret_cast<VideoStreamConsumer*>(arg)); // PRQA S 3090 // cast necessary here, need access to JobCamM member variable
  osal::Mutex mutex_o;

  ScreenContext_t v_ScreenContext_t = v_Job_po->screenContext_t;

  bool_t v_Success_b = false;

  while(v_Success_b == false)
  {
    bool_t v_Error_t = v_Job_po->stream_o.waitForProducer_b(v_ScreenContext_t, v_Job_po->streamId_s32);

    if((true == v_Error_t))
    {
      logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf, "VideoStreamProvider::waitForProducer_pv() - JobStream [%d]", v_Job_po->streamId_s32);
      v_Job_po->producerStreamAvailable_b = true;
      v_Success_b = true;
    }
  }

  logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf, "VideoStreamProvider::waitForProducer_pv() - Finished [%d]!!!", v_Job_po->streamId_s32);

  return NULL;
}

variants::Camera_t VideoStreamConsumer::mapStreamToCameraId_t(sint32_t i_StreamId_s32)
{
  variants::Camera_t v_CameraId_t = variants::e_CameraInvalid;

  switch(i_StreamId_s32)
  {
  case e_StreamHumanVisionIdFront:
  {
    v_CameraId_t = variants::e_CameraFront;
    break;
  }
  case e_StreamHumanVisionIdLeft:
  {
    v_CameraId_t = variants::e_CameraLeft;
    break;
  }
  case e_StreamHumanVisionIdRight:
  {
    v_CameraId_t = variants::e_CameraRight;
    break;
  }
  case e_StreamHumanVisionIdRear:
  {
    v_CameraId_t = variants::e_CameraRear;
    break;
  }
  default:
  {
    //do nothing
    break;
  }
  }

  return v_CameraId_t;
}

sint32_t VideoStreamConsumer::mapCameraToStreamId_s32(variants::Camera_t i_CameraId_t)
{
  sint32_t v_StreamId_s32 = e_StreamHumanVisionIdInvalid;

  switch(i_CameraId_t)
  {
  case variants::e_CameraFront:
  {
    v_StreamId_s32 = e_StreamHumanVisionIdFront;
    break;
  }
  case variants::e_CameraLeft:
  {
    v_StreamId_s32 = e_StreamHumanVisionIdLeft;
    break;
  }
  case variants::e_CameraRight:
  {
    v_StreamId_s32 = e_StreamHumanVisionIdRight;
    break;
  }
  case variants::e_CameraRear:
  {
    v_StreamId_s32 = e_StreamHumanVisionIdRear;
    break;
  }
  default:
  {
    //do nothing
    break;
  }
  }

  return v_StreamId_s32;
}

bool_t VideoStreamConsumer::aquireBuffer_b(bsp::ImageBufferData_t* b_ImageData_pt, bool_t i_Blocking_b)
{
  bool_t v_Result_b = false;

  if(producerStreamAvailable_b == true)
  {
    stream_o.createConsumer_b();
    producerStreamAvailable_b = false;
  }

  if ( true == bsp::Stream::isValid_b(stream_o) )
  {
    v_Result_b = stream_o.acquireBuffer_b(b_ImageData_pt, i_Blocking_b);
  }

  return v_Result_b;
}


bool_t VideoStreamConsumer::deInit_b() 
{
  return true;
}


};

/// @}
