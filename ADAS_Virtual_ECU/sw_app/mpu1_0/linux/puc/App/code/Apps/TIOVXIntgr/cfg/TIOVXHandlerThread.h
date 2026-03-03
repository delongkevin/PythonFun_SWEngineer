//--------------------------------------------------------------------------
/// @file TIOVXHandlerThread.h
/// @brief Contains the definition of TIOVX handling thread.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Konstantin Kozhevnikov (konstantin.kozhevnikov@cogentembedded.com)
//  --------------------------------------------------------------------------

#ifndef TIOVX_HANDLER_THREAD_H_
#define TIOVX_HANDLER_THREAD_H_

#include <platform/PlatformAPI.h>

#include <bsp/io/tiovx/TIOVXHost.h>

#include <osal/threading/IRunnable.h>

#include <variants/Enums.h>

namespace tiovx
{

// think about that - tbd  
enum TIOVXUpdateState_e
{
  e_UpdateIdleState = 0,
  e_UpdateViewGenState,
  e_UpdateLayerEngineState,
  e_UpdateFinishState,
  e_UpdateStateCount,
  e_UpdateStateInvalid,
  };


  class IDataProviderTIOVX;
  class TIOVXHandlerThread: public osal::IRunnable
  {

  public:

    explicit TIOVXHandlerThread(IDataProviderTIOVX& i_DataProvider_ro);

    virtual ~TIOVXHandlerThread();
  
    virtual void    init_v()        ME_OVERRIDE;

    virtual bool_t  run_b()         ME_OVERRIDE;

    virtual void    cleanup_v()     ME_OVERRIDE;

    IDataProviderTIOVX&                 dataProvider_ro;

  public:

	void          	setTIOVX_v(bsp::TIOVXHost* i_tiovx_po) { tiovx_po = i_tiovx_po; }

  private:

    //void          printLayer_v() const;

  private:

    bool_t                  isRunning_b;

	bsp::TIOVXHost*			tiovx_po;
#if 0
    bsp::FpgaZCU102*        fpga_po;
    bsp::FpgaLayerEngine*   layerEngine_po;
    bsp::FpgaViewGen*       viewGen_po;
    bsp::AxisMipMem*        axisMipMem_po;

    bool_t                  updateAll_b;
#endif
  };

} //namespace tiovx

#endif // TIOVX_HANDLER_THREAD_H_
