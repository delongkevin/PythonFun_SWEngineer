//--------------------------------------------------------------------------
/// @file FpgaZCU102.cpp
/// @brief Implementation of QNX fpga interface
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
//  --------------------------------------------------------------------------

#include <platform/PlatformAPI.h>

#ifdef ME_PLATFORM_QNX

#include <bsp/io/fpga/FpgaZCU102.h>
#include <bsp/io/fpga/FpgaParameters.h>

#include <logging/Logger.h>

namespace bsp
{

void* FpgaZCU102::frameTriggerThread_pv(void* i_Args_pv)
{
  FpgaZCU102* v_FpgaHandler_po = reinterpret_cast<FpgaZCU102*>(i_Args_pv);

  if(v_FpgaHandler_po != NULL)
  {
    FpgaViewGen& v_ViewGen_ro = v_FpgaHandler_po->getFpgaViewGen_ro();
    ME_Interrupt_Attach_t(&v_FpgaHandler_po->interruptHandle_t, c_VideoInSyncCtrlIRQ_u32);
    //ME_Interrupt_Attach_t(&v_FpgaHandler_po->interruptHandle_t, 124);

    uint32_t v_FrameNumber_u32 = 0;

    while(true)
    {
      if(v_FpgaHandler_po->getFpgaState_e() == e_FpgaStateInitalized)
      {
        ME_Interrupt_Wait_t(&v_FpgaHandler_po->interruptHandle_t);

        v_FrameNumber_u32++;
        v_FpgaHandler_po->setFrameNumber_v(v_FrameNumber_u32);

        ME_Thread_Sleep_t(1);

        /// notify all "registers" modules, which are waiting for trigger
        v_FpgaHandler_po->softwareInterrupt_o.broadcast_v();

        ME_Interrupt_Unmask_t(&v_FpgaHandler_po->interruptHandle_t);
      }
      else
      {
        ME_Thread_Sleep_t(1);
        v_FpgaHandler_po->softwareInterrupt_o.broadcast_v();
      }
    }
  }

  return NULL;
}

FpgaZCU102::FpgaZCU102()
  : fpgaState_e(e_FpgaStateNotInitialized)
  , fpgaLayerEngine_o()
  , fpgaViewGen_o()
  , fpgaAlgoView_o()
  , fpgaVideoInput_o()
  , fpgaVideoOutput_o()
  , axisMipMem_o()
  , frameNumber_u32(0U)
  , plBaseAddress_pv(NULL)
  , viewId_t(variants::e_ServiceHelper_E_HMIView_NoView)
  , interruptHandle_t()

{

}

FpgaZCU102::~FpgaZCU102()
{

}


bool_t FpgaZCU102::init_b()
{
  bool_t v_Result_b = true;

  MEP_BEGIN("init", "FpgaZCU102");

  ME_IO_MapDeviceAdress_b(c_AxiLiteBase_u32, c_AxiLiteSize_u32, &plBaseAddress_pv);

  v_Result_b = v_Result_b && axisMipMem_o.initAxisMipMap_b();

  v_Result_b = v_Result_b && fpgaAlgoView_o.initAlgoView_b();

  v_Result_b = v_Result_b && fpgaViewGen_o.initViewGen_b();

  v_Result_b = v_Result_b && fpgaLayerEngine_o.initLayerEngine_b();

  softwareInterrupt_o.init_v();

  ThreadHandle_s v_Thread_s;
  ME_Thread_Create_t(&v_Thread_s, frameTriggerThread_pv, this, ME_Thread_C_DefaultStackSize_t);
  ME_Thread_SetPriority_t(&v_Thread_s, e_PriorityRealtime);
  ME_Thread_SetName_t(&v_Thread_s, "FrameTriggerThread");

  fpgaState_e = e_FpgaStateInitalized;

  MEP_END("init", "FpgaZCU102");

  return v_Result_b;
}

FpgaLayerEngine& FpgaZCU102::getFpgaLayerEngine_ro()
{
  return fpgaLayerEngine_o;
}

FpgaViewGen&  FpgaZCU102::getFpgaViewGen_ro()
{
  return fpgaViewGen_o;
}

FpgaAlgoView& FpgaZCU102::getFpgaAlgoView_ro()
{
  return fpgaAlgoView_o;
}

FpgaVideoInput& FpgaZCU102::getFpgaVideoInput_ro()
{
  return fpgaVideoInput_o;
}

FpgaVideoOutput& FpgaZCU102::getFpgaVideoOutput_ro()
{
  return fpgaVideoOutput_o;
}

AxisMipMem& FpgaZCU102::getAxisMipMem_ro()
{
  return axisMipMem_o;
}

void FpgaZCU102::setFrameNumber_v(uint32_t i_FrameNumber_u32)
{
  frameNumber_u32 = i_FrameNumber_u32;
}

FpgaVersion_s FpgaZCU102::getFpgaVersion_s()
{
  FpgaVersion_s v_Version_s;
  uint32_t v_Version_u32 = 0x00U;

  ME_IO_In32_b(plBaseAddress_pv, 0x70000U, &v_Version_u32);

  v_Version_s.year_u8         = (v_Version_u32 & 0xff000000U) >> 24;
  v_Version_s.week_u8         = (v_Version_u32 & 0x00ff0000U) >> 16;
  v_Version_s.day_u8          = (v_Version_u32 & 0x0000f000U) >> 12;
  v_Version_s.buildNumber_u8  = (v_Version_u32 & 0x00000f00U) >> 8;

  return v_Version_s;
}

uint32_t FpgaZCU102::getFrameTrigger_u32()
{
  uint32_t v_Result_u32 = 1;

  if(fpgaVideoInput_o.isStreaming_b() == true)
  {
    if(fpgaState_e == e_FpgaStateInitalized)
    {
      uint8_t v_InterruptId_u8 = softwareInterrupt_o.attach_u8();

      while(v_InterruptId_u8 == osal::c_MAX_ATTACHMENTS_u8)
      {
        v_InterruptId_u8 = softwareInterrupt_o.attach_u8();
      }

      softwareInterrupt_o.receive_v(v_InterruptId_u8);

      softwareInterrupt_o.detach_v(v_InterruptId_u8);
    }
  }

  return v_Result_u32;
}

} // namespace bsp

#endif // ME_PLATFORM_QNX

