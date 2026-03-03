//--------------------------------------------------------------------------
/// @file AlgoViewDLD.h
/// @brief Contains
///
/// AlgoViewDLD is a manager to fetch most recent algo buffer with double buffer.
/// This file contains all the implementation required to access frame data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Sharad Benakatti (sharad.benakatti@magna.com)
//  --------------------------------------------------------------------------
#ifndef ALGO_VIEW_DLD_H_
#define ALGO_VIEW_DLD_H_

#include "DLD/IDataProviderDLD.h"
#include <cfg/IDataProvider.h>
#include <bsp/io/tiovx/TIOVXConsumer.h>

namespace dld
{

typedef struct BufferContext_s
{
  bsp::VideoInputBufferDesc2_t v_bufferDesc_t;
  texture_data_t*  v_textures_apo[3];
} BufferContext_t;

class AlgoViewDLD {
public:
  AlgoViewDLD();
  void createAlgoView(container::OVL3DData *v_ovl3d_po, bsp::TIOVXHost &v_tiovx_ro, char* algoViewId);
  bsp::VideoInputBufferDesc2_t getAlgoFrame(void);

private:
  Condvar_s m_condvar_s;
  AlgoViewJob_s m_algoJob;
  BufferContext_t *m_ctxRead;
  BufferContext_t *m_ctxWrite;
  BufferContext_t m_ctx1, m_ctx2;
  container::OVL3DData *m_ovl3d_po;

  void swapContext(void);
};

}

#endif // ALGO_VIEW_DLD_H_

