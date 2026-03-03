//--------------------------------------------------------------------------
/// @file LogBase.cpp
/// @brief Defines the Input-Output Interface for Opject Detection Algo
///
/// IDataProvider is an interface used by the algorithm to define what data
/// is actually needed. Implementation is delegated to a derived data provider
/// that is component/module specific and belongs to the framework implementation.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
///
//  --------------------------------------------------------------------------

#include "LogBase.h"

#include <osal/system/Time.h>

namespace logm
{

  LogBase::LogBase(mecl::buffer::IBuffer& i_Buffer_ro)
    : IRunnable()
    , buffer_ro(i_Buffer_ro)
    , mutex_s()
    , numOfBytesProcessed_u32(0U)
    , numOfBytesLogged_u32(0U)
    , writeIdx_u32(0U)
    , size_u32(0U)
    , diff_u32(0U)
  {
  }

  LogBase::~LogBase()
  {
  }

  void LogBase::init_v()
  {
    buffer_ro.init_v();

    ME_Mutex_Init_t(&mutex_s, true);

    onInit_v();
  }

  bool_t LogBase::run_b()
  {
    static uint8_t v_TmpBuffer_au8[2048U];

    writeIdx_u32 = 0;
    size_u32 = 0;
    diff_u32 = 0;

    size_u32 = buffer_ro.read_u32(reinterpret_cast<void*>(&v_TmpBuffer_au8[writeIdx_u32]));
    size_u32 += writeIdx_u32;

    if (size_u32 != 0)
    {
      ME_Mutex_Lock_t(&mutex_s);

      numOfBytesProcessed_u32 += size_u32;

      ME_Mutex_UnLock_t(&mutex_s);

      uint32_t v_I_u32 = 0;
      while (v_I_u32 < size_u32)
      {
        uint32_t v_Result_s32 = 0;
        diff_u32 = (size_u32 - v_I_u32);

        logging::LogHeader_t* v_LogHeader_pt = NULL;
        v_Result_s32 = isLogMsg_pt(&v_TmpBuffer_au8[v_I_u32], diff_u32, &v_LogHeader_pt);

        if (v_Result_s32 == 1)
        {
          processLogMsg_b(v_LogHeader_pt);
          v_I_u32 += v_LogHeader_pt->Size_u32;

          writeIdx_u32 = 0;
        }
        else if (v_Result_s32 == 0)
        {
          memcpy(&v_TmpBuffer_au8[0], &v_TmpBuffer_au8[v_I_u32], diff_u32);
          memset(&v_TmpBuffer_au8[diff_u32], 0, 2048U - diff_u32);
          writeIdx_u32 = diff_u32;
          v_I_u32 = size_u32;
        }
        else
        {
          v_I_u32 = size_u32;
        }
      }
    }

    ME_Thread_Sleep_t(1U);

    return true;
  }

  void LogBase::cleanup_v()
  {
    buffer_ro.cleanup_v();
  }

  sint32_t LogBase::isLogMsg_pt(uint8_t* i_Buffer_pu8, uint32_t i_Size_u32, logging::LogHeader_t** o_LogHeader_t)
  {
    sint32_t v_Result_s32 = -2;
    *o_LogHeader_t = NULL;

    if (i_Buffer_pu8 != NULL)
    {
      *o_LogHeader_t = reinterpret_cast<logging::LogHeader_t*>(i_Buffer_pu8);

      if (i_Size_u32 < sizeof(uint32_t/*logging::LogHeader_t::Size_u32*/))
      {
        v_Result_s32 = 0;
      }
      else
      {
        v_Result_s32 = 1;
      }

      if (v_Result_s32 == 1)
      {
        if (((*o_LogHeader_t)->Size_u32 > i_Size_u32) || ((*o_LogHeader_t)->Size_u32 < sizeof(logging::LogHeader_t)))
        {
          // not plausible LogHeader
          *o_LogHeader_t = NULL;
          v_Result_s32 = 0;
        }
      }
    }

    return v_Result_s32;
  }

  bool_t LogBase::log_b(const void* i_Buffer_pv, uint32_t v_Size_u32)
  {
    osal::Time v_Time_o;
    bool_t v_Result_b = false;

    if (i_Buffer_pv != NULL)
    {
      while ((v_Result_b == false))
      {
        v_Result_b = buffer_ro.write_b(i_Buffer_pv, v_Size_u32);
      }
    }

    return v_Result_b;
  }


} // namespace logm
