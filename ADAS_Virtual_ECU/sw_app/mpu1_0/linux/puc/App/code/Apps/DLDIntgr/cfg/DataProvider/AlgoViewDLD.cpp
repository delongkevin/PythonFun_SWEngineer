//--------------------------------------------------------------------------
/// @file AlgoViewDLD.cpp
/// @brief Contains implementation of DLD AlgoView provider
///
/// AlgoView provider is an interface between DLD module and the ovl3d renderer.
/// This file contains all the implementation required to access input and
/// output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Sharad Benakatti (sharad.benakatti@magna.com)
//  --------------------------------------------------------------------------

#include "AlgoViewDLD.h"

namespace dld
{

AlgoViewDLD::AlgoViewDLD() :
m_condvar_s(),
m_algoJob(),
m_ctx1(),
m_ctx2()
{
  m_ctxRead = &m_ctx1;
  m_ctxWrite = &m_ctx2;

  memset(&m_condvar_s, 0, sizeof(m_condvar_s));
  ME_Condvar_Init_t(&m_condvar_s);

  m_algoJob.sync_ppo = NULL;
  m_algoJob.timestamp_us = 0;
  m_algoJob.condvar_po = &m_condvar_s;
}

void AlgoViewDLD::swapContext(void) {
  BufferContext_t* temp = m_ctxRead;
  m_ctxRead = m_ctxWrite;
  m_ctxWrite = temp;
}

void AlgoViewDLD::createAlgoView(container::OVL3DData *v_ovl3d_po, bsp::TIOVXHost &v_tiovx_ro, char* algoViewId) {
  m_ovl3d_po = v_ovl3d_po;
  ME_Debugger_F_Printf_v("[DLD] Creating algo view %s\n", algoViewId);

  uint32_t v_width_u32;
  uint32_t v_height_u32;
  
  // Create algo view and 2 set of buffers
  if ((m_algoJob.algoView_po = m_ovl3d_po->algoViewCreate_po(algoViewId, ALGO_VIEW_RGB_PLANAR_RAW, v_width_u32, v_height_u32)) == NULL) {
    ME_Debugger_F_Printf_v("AlgoViewDLD: failed to create algo-view %s", algoViewId);
  }
  else if (v_tiovx_ro.allocVideoBuffer_b(v_width_u32, v_height_u32, SCREEN_FORMAT_BYTE, 3, m_ctx1.v_bufferDesc_t) == false) {
    ME_Debugger_F_Printf_v("AlgoViewDLD: failed to allocate buffer (C1) %s", algoViewId);
  }
  else if (v_tiovx_ro.allocVideoBuffer_b(v_width_u32, v_height_u32, SCREEN_FORMAT_BYTE, 3, m_ctx2.v_bufferDesc_t) == false) {
    ME_Debugger_F_Printf_v("AlgoViewDLD: failed to allocate buffer (C2) %s", algoViewId);
  }
  else if (m_ovl3d_po->algoViewBuffersPrepare_b(m_ctx1.v_bufferDesc_t, m_ctx1.v_textures_apo) == false) {
    ME_Debugger_F_Printf_v("AlgoViewDLD: failed to prepare buffers (C1) %s", algoViewId);
  }
  else if (m_ovl3d_po->algoViewBuffersPrepare_b(m_ctx2.v_bufferDesc_t, m_ctx2.v_textures_apo) == false) {
    ME_Debugger_F_Printf_v("AlgoViewDLD: failed to prepare buffers (C2) %s", algoViewId);
  }
  else {
    ME_Debugger_F_Printf_v("[DLD] Created double buffers for %s\n", algoViewId);
  }

  m_algoJob.output_apo = m_ctxWrite->v_textures_apo;
}

bsp::VideoInputBufferDesc2_t AlgoViewDLD::getAlgoFrame(void) {
  if(m_ovl3d_po != NULL) {
    uint32_t now_us = __get_time_usec();
    if((now_us - m_algoJob.timestamp_us) > 500000) {
      // Buffer is too old, request new frame and wait
      ME_Mutex_Lock_t(&m_condvar_s.MEMutex_po);
      m_algoJob.timestamp_us = 0;
      m_algoJob.output_apo = m_ctxWrite->v_textures_apo;
      if (m_ovl3d_po->algoViewJobSubmit_b(&m_algoJob) == true) {
        // wait for job completion (explicitly)
        ME_Debugger_F_Printf_v("##### Prev frame is old - waiting\n");
        ME_Condvar_Wait_t(&m_condvar_s);
      }
      ME_Mutex_UnLock_t(&m_condvar_s.MEMutex_po);
    }

    swapContext();
    {
      // Request new frame for next cycle
      ME_Mutex_Lock_t(&m_condvar_s.MEMutex_po);
      if (m_algoJob.timestamp_us == 0) {
        // wait for job completion (explicitly)
        ME_Debugger_F_Printf_v("##### Job already in progress - waiting\n");
        ME_Condvar_Wait_t(&m_condvar_s);
      }
      m_algoJob.timestamp_us = 0;
      m_algoJob.output_apo = m_ctxWrite->v_textures_apo;
      m_ovl3d_po->algoViewJobSubmit_b(&m_algoJob);
      ME_Mutex_UnLock_t(&m_condvar_s.MEMutex_po);
    }
  }
  return m_ctxRead->v_bufferDesc_t;
}

} // namespace dld
