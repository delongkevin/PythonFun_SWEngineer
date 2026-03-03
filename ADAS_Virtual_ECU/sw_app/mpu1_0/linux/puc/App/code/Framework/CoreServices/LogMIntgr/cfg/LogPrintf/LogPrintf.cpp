//--------------------------------------------------------------------------
/// @file LogPrintf.h
/// @brief
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

#include "LogPrintf.h"

namespace logm
{

LogPrintf::LogPrintf(mecl::buffer::IBuffer& i_Buffer_ro)
  : LogBase(i_Buffer_ro)
{

}

LogPrintf::~LogPrintf()
{

}

void LogPrintf::onInit_v()
{

}

bool_t LogPrintf::processLogMsg_b(const logging::LogHeader_t* i_LogHeader_pt)
{
  bool_t v_Result_b = false;

  if(i_LogHeader_pt != NULL)
  {
    static uint64_t v_Counter_u64 = 0;

    const char_t* v_Payload_pc = reinterpret_cast<const char_t*>(i_LogHeader_pt);
    sint8_t v_AppId_ac[5];
    sint8_t v_ContextId_ac[5];

    ME_Platform_F_MakeFourCCInv_v(i_LogHeader_pt->AppId_u32, &v_AppId_ac[0], &v_AppId_ac[1], &v_AppId_ac[2], &v_AppId_ac[3]); // PRQA S 3706 // subscipt operator necessary here
    v_AppId_ac[4] = static_cast<sint8_t>('\0');
    ME_Platform_F_MakeFourCCInv_v(i_LogHeader_pt->ContextId_s32, &v_ContextId_ac[0], &v_ContextId_ac[1], &v_ContextId_ac[2], &v_ContextId_ac[3]); // PRQA S 3706 // subscipt operator necessary here
    v_ContextId_ac[4] = static_cast<sint8_t>('\0');

    ME_Debugger_F_Printf_v("(%llu) Time %f; Apid %s; Ctid %s; LogLvl %d: %s\n"
                           , v_Counter_u64
                           , static_cast<float32_t>(i_LogHeader_pt->Timestamp_u32) / 10000.0F
                           , &v_AppId_ac[0]
                           , &v_ContextId_ac[0]
                           , i_LogHeader_pt->LogLevel_u8
                           , &v_Payload_pc[sizeof(logging::LogHeader_t)]); // PRQA S 3706 // must remove header from payload string

    v_Counter_u64 += 1;

    v_Result_b = true;
  }

  return v_Result_b;
}

void LogPrintf::onCleanup_v()
{

}

} // namespace logm
