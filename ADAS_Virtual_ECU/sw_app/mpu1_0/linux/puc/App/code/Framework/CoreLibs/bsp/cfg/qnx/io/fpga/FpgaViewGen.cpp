//--------------------------------------------------------------------------
/// @file Cam.cpp
/// @brief Implementation of QNX camera interface
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
//  --------------------------------------------------------------------------

// PRQA S 3706 EOF // Subscript operator necessary to access the FPGA data properly

#include <platform/PlatformAPI.h>

#include <bsp/io/fpga/FpgaViewGen.h>

#include <mecl/core/Crc.h>

#ifdef ME_PLATFORM_QNX



namespace bsp
{

void* FpgaViewGen::viewGenTrigger_pv(void* i_Arg_pv)
{
  FpgaViewGen& v_ViewGen_ro = *reinterpret_cast<FpgaViewGen*>(i_Arg_pv);

  InterruptHandle_t v_ViewGenInterrupt_t;
  ME_Interrupt_Attach_t(&v_ViewGenInterrupt_t, c_ViewGenProcessedIRQ_u32);

  uint32_t v_InterruptType_u32 = 0U;

  while(true)
  {
    if(v_ViewGen_ro.isEnabled_b() == true)
    {
      ME_Interrupt_Wait_t(&v_ViewGenInterrupt_t);
      ME_IO_In32_b(v_ViewGen_ro.viewGenConfigBase_pv, 0x1CU, &v_InterruptType_u32);

      /// notify all "registers" modules, which are waiting for trigger
      if((v_InterruptType_u32 & 0x1U) == 0x01U)
      {
        uint32_t v_Retries_u32 = 0;
        MEP_BEGIN("Interrupt", "FpgaViewGen");
        ME_IO_Out32_b(v_ViewGen_ro.viewGenConfigBase_pv, 0x001CU, 0x01U);
        ME_IO_In32_b(v_ViewGen_ro.viewGenConfigBase_pv, 0x001CU, &v_InterruptType_u32);

        if(v_InterruptType_u32 == 0x00U)
        {
          v_ViewGen_ro.softwareInterrupt_o.broadcast_v();
        }

        MEP_END("Interrupt", "FpgaViewGen");
#if 0
        /// grab statistics
        // Enable statistic readout
        ME_IO_Out32_b(v_ViewGen_ro.viewGenConfigBase_pv, 0x0CU, 0x1U);

        uint32_t v_ProcessDuration_u32 = 0x00U;
        ME_IO_In32_b(v_ViewGen_ro.viewGenConfigBase_pv, 0x01028U, &v_ProcessDuration_u32);

        uint32_t v_FrameCount_u32 = 0x00U;
        ME_IO_In32_b(v_ViewGen_ro.viewGenConfigBase_pv, 0x0102CU, &v_FrameCount_u32);
        ME_Debugger_F_Printf_v("Statistics for frame [%d]: duration %f\n", (v_FrameCount_u32 & 0xFFFFF000U) >> 12, v_ProcessDuration_u32 * 5.0F / 1000000.0F);

        // Disable statistic data collection
        ME_IO_Out32_b(v_ViewGen_ro.viewGenConfigBase_pv, 0x0CU, 0x0U);
#endif
      }

      ME_Interrupt_Unmask_t(&v_ViewGenInterrupt_t);
    }
    else
    {
      ME_Thread_Sleep_t(1);
      v_ViewGen_ro.softwareInterrupt_o.broadcast_v();
    }
  }
  return NULL;
}

static ThreadID_t s_LockThreadID_t = ME_INVALID_PROCESS_ID;
static uint8_t s_LockDepth_u8 = 0;

FpgaViewGen::FpgaViewGen()
  : time_o()
  , mutex_o()
  , lockMutex_o()
  , isViewGenEnabled_b(false)
  , isViewGenInitialized_b(false)
  , isViewGenLocked_b(false)
  , isDistortionInitialized_b(false)
  , isViewGenProcessed_b(false)
  , isViewGenConfigDone_b(false)
  , viewGenConfigBase_pv(NULL)
  , viewGenConfig_o()
  , imageViewGenConfig_o()
  , cacheViewGenConfig_o()
  , underfloorReadBuffer_u32(18U)
{
  memset(imageBufferViewGenConfig_au8, 0, c_ViewGen3Size_u32 / sizeof(uint32_t));
  memset(cacheBufferViewGenConfig_au8, 0, c_ViewGen3Size_u32 / sizeof(uint32_t));
}

FpgaViewGen::~FpgaViewGen()
{

}

bool_t FpgaViewGen::initViewGen_b()
{
  void* v_ViewGenBuffer0_pv   = NULL;
  void* v_ViewGenBuffer1_pv   = NULL;
  void* v_HistoricBuffer18_pv = NULL;

  ME_SharedMemory_MapPhysicalByAddress_t(c_ViewGenBuffer0_u32, 3U * 0x00300000U, &v_ViewGenBuffer0_pv);
  ME_SharedMemory_MapPhysicalByAddress_t(c_ViewGenBuffer1_u32, 3U * 0x00300000U, &v_ViewGenBuffer1_pv);
  ME_SharedMemory_MapPhysicalByAddress_t(c_HistoricBuffer18_u32,    0x00320000U, &v_HistoricBuffer18_pv);

  ME_IO_MapDeviceAdress_b(c_ViewGen3Base_u32, 0x50000U, &viewGenConfigBase_pv);

  if((v_ViewGenBuffer0_pv != NULL) && (v_ViewGenBuffer1_pv != NULL) && (v_HistoricBuffer18_pv != NULL) && (viewGenConfigBase_pv != NULL))
  {
    for(uint32_t v_I_u32 = 0; v_I_u32 < ((3 * 0x00300000U) / 8); v_I_u32++)
    {
      reinterpret_cast<uint64_t*>(v_ViewGenBuffer0_pv)[v_I_u32] = 0x8000800080008000ULL;
      reinterpret_cast<uint64_t*>(v_ViewGenBuffer1_pv)[v_I_u32] = 0x8000800080008000ULL;
    }

    for(uint32_t v_I_u32 = 0; v_I_u32 < (0x00320000U / 8); v_I_u32++)
    {
      reinterpret_cast<uint64_t*>(v_HistoricBuffer18_pv)[v_I_u32] = 0x8000800080008000ULL;
    }

    viewGenConfig_o.init_b(viewGenConfigBase_pv);
    imageViewGenConfig_o.init_b(imageBufferViewGenConfig_au8);
    cacheViewGenConfig_o.init_b(cacheBufferViewGenConfig_au8);

    softwareInterrupt_o.init_v();

    ThreadHandle_s v_Thread_s;
    ME_Thread_Create_t(&v_Thread_s, viewGenTrigger_pv, this, ME_Thread_C_DefaultStackSize_t);
    ME_Thread_SetPriority_t(&v_Thread_s, e_PriorityRealtime);
    ME_Thread_SetName_t(&v_Thread_s, "viewGenTriggerThread");

    isViewGenInitialized_b = true;
  }

  return isViewGenInitialized_b;
}


bool_t FpgaViewGen::enable_b(bool_t i_Lock_b)
{
  bool_t v_Result_b = false;
  uint32_t v_ReadVal_u32 = 0x00U;

  if((isEnabled_b() == false) && (isInitialized_b() == true))
  {
    if(i_Lock_b == true)
    {
      while(false == lock_b());
    }

    ME_IO_Out32_b(viewGenConfig_o.getAxiLite_pv(), 0x00000014U, 0x00008080U); // set user color
    ME_IO_Out32_b(viewGenConfig_o.getAxiLite_pv(), 0x00000020U, 0x00000001U);
    ME_IO_Out32_b(viewGenConfig_o.getAxiLite_pv(), 0x00000018U, 0x00000001U); // enable interrupt

    if(i_Lock_b == true)
    {
      unlock_b();
    }

    v_Result_b = true;

    isViewGenEnabled_b = true;
  }
  else
  {
    v_Result_b = true;
  }

  return v_Result_b;
}

bool_t FpgaViewGen::disable_b(bool_t i_Lock_b)
{
  bool_t v_Result_b = false;
  uint32_t v_ReadVal_u32 = 0x00U;

  if(isEnabled_b() == true)
  {
    if(i_Lock_b == true)
    {
      while(false == lock_b());
    }

    ME_IO_Out32_b(viewGenConfig_o.getAxiLite_pv(), 0x00000014U, 0x00008080U); // set user color
    ME_IO_Out32_b(viewGenConfig_o.getAxiLite_pv(), 0x00000020U, 0x00000000U);
    ME_IO_Out32_b(viewGenConfig_o.getAxiLite_pv(), 0x00000018U, 0x00000000U);

    if(i_Lock_b == true)
    {
      unlock_b();
    }

    isViewGenEnabled_b = false;

    softwareInterrupt_o.broadcast_v();

    v_Result_b = true;
  }
  else
  {
    v_Result_b = true;
  }

  return v_Result_b;
}


ViewGenConfig& FpgaViewGen::getViewGenConfig_rs()
{
  return cacheViewGenConfig_o;
}


bool_t FpgaViewGen::getViewGenTrigger_b()
{
  MEP_BEGIN("Trigger", "ViewGen");

  if(isEnabled_b() == true)
  {
    uint8_t v_InterruptId_u8 = softwareInterrupt_o.attach_u8();

    while(v_InterruptId_u8 == osal::c_MAX_ATTACHMENTS_u8)
    {
      v_InterruptId_u8 = softwareInterrupt_o.attach_u8();
    }

    softwareInterrupt_o.receive_v(v_InterruptId_u8);

    softwareInterrupt_o.detach_v(v_InterruptId_u8);
  }

  MEP_END("Trigger", "ViewGen");

  return true;
}

bool_t FpgaViewGen::getHarmonComutationResults_b(uint32_t* o_HarmonComputationResults_pu32)
{
  mutex_o.take_b();
  if(o_HarmonComputationResults_pu32 != NULL)
  {
    memcpy(o_HarmonComputationResults_pu32, viewGenConfig_o.getHarmonComputationResults_pv(), c_HarmonComputationResultsSize_u32);
  }
  mutex_o.give_v();
  return true;
}


bool_t FpgaViewGen::configViewGenDone_b()
{
  bool_t v_Result_b = false;

  isViewGenConfigDone_b = isViewGenProcessed_b;

  v_Result_b = isViewGenConfigDone_b;

  return v_Result_b;
}

bool_t FpgaViewGen::setReadBuffer_b(uint8_t i_BufferIdx_u8)
{
  bool_t v_Result_b = false;

  if(lock_b() == true)
  {
    if(isViewGenEnabled_b == true)
    {
      underfloorReadBuffer_u32 = i_BufferIdx_u8;

      v_Result_b = updateReadBuffer_b();
    }

    unlock_b();
  }

  return v_Result_b;
}

bool_t FpgaViewGen::setProcessViewGen_b()
{
  bool_t v_Result_b = false;

  mutex_o.take_b();
  // Either distortion has not been updated or ViewGen is enabled
  if((isViewGenProcessed_b == false))
  {
    isViewGenProcessed_b = true;
  }
  mutex_o.give_v();

  v_Result_b = isViewGenProcessed_b;

  return v_Result_b;
}

bool_t FpgaViewGen::isEnabled_b()
{
  mutex_o.take_b();
  bool_t v_Result_b = isViewGenEnabled_b;
  mutex_o.give_v();

  return v_Result_b;
}

bool_t FpgaViewGen::isInitialized_b()
{
  mutex_o.take_b();
  bool_t v_Result_b = (isViewGenInitialized_b && isDistortionInitialized_b);
  mutex_o.give_v();

  return v_Result_b;
}

bool_t FpgaViewGen::isConfigViewGenDone_b()
{
  bool_t v_Result_b = isViewGenConfigDone_b;

  return v_Result_b;
}

bool_t FpgaViewGen::isProcessingViewGen_b()
{
  bool_t v_Result_b = isViewGenProcessed_b;

  return v_Result_b;
}

bool_t FpgaViewGen::lock_b()
{
  bool_t v_Result_b = false;
  static const uint32_t c_MaxReTries_u32 = 33U;

  if(s_LockThreadID_t == ME_INVALID_PROCESS_ID)
  {
    if(lockMutex_o.take_b() == true)
    {
      s_LockDepth_u8 = 1;
      uint32_t v_Read_u32 = 0x00U;
      uint32_t v_ReTries_u32 = 0U;

      while((v_Result_b != true))
      {
        ME_IO_Out32_b(viewGenConfigBase_pv, 0x10U, 0x01U);
        ME_Thread_Sleep_t(1);
        ME_IO_In32_b(viewGenConfigBase_pv, 0x10U, &v_Read_u32);
        v_Result_b = (v_Read_u32 == 0x01U);

        v_ReTries_u32++;
        if(v_ReTries_u32 > c_MaxReTries_u32)
        {
          v_Result_b = false;
          break;
        }
      }

      if(false == v_Result_b)
      {
        //ME_Debugger_F_Printf_v("Viewgen lock failed: %d\n", ME_Thread_GetCurrentID_t());
        s_LockDepth_u8 = 0;
        s_LockThreadID_t = ME_INVALID_PROCESS_ID;
        lockMutex_o.give_v();
      }
      else
      {
        mutex_o.take_b();
        s_LockThreadID_t = ME_Thread_GetCurrentID_t();
      }
    }
  }
  else if(s_LockThreadID_t == ME_Thread_GetCurrentID_t())
  {
    s_LockDepth_u8++;
    v_Result_b = true;
  }

  return v_Result_b;
}

bool_t FpgaViewGen::unlock_b()
{
  bool_t v_Result_b = false;
  static const uint32_t c_MaxReTries_u32 = 33U;

  if(s_LockThreadID_t == ME_Thread_GetCurrentID_t() && (s_LockDepth_u8 == 1))
  {
    uint32_t v_Read_u32 = 0x00U;
    uint32_t v_ReTries_u32 = 0U;

    while((v_Result_b != true))
    {
      ME_IO_Out32_b(viewGenConfigBase_pv, 0x10U, 0x00U);
      ME_Thread_Sleep_t(1);
      ME_IO_In32_b(viewGenConfigBase_pv, 0x10U, &v_Read_u32);
      v_Result_b = ((v_Read_u32 & 0x01U) == 0x00U);

      v_ReTries_u32++;
      if(v_ReTries_u32 > c_MaxReTries_u32)
      {
        v_Result_b = false;
        break;
      }
    }

    if(true == v_Result_b)
    {
      s_LockThreadID_t = ME_INVALID_PROCESS_ID;
      s_LockDepth_u8 = 0;
      mutex_o.give_v();
      lockMutex_o.give_v();
    }
  }
  else if((s_LockThreadID_t == ME_Thread_GetCurrentID_t()) && s_LockDepth_u8 > 1)
  {
    s_LockDepth_u8--;
    v_Result_b = true;
  }

  return v_Result_b;
}


bool_t FpgaViewGen::update_b()
{
  bool_t v_Result_b = false;

  if(lock_b() == true)
  {
    if(isViewGenInitialized_b == true)
    {
      MEP_BEGIN("update", "ViewGen");
      v_Result_b = updateViewGen_b();
      MEP_END("update", "ViewGen");
    }

    unlock_b();
  }

  return v_Result_b;
}

bool_t FpgaViewGen::updateNonLock_b()
{
  bool_t v_Result_b = false;

  if(isViewGenInitialized_b == true)
  {
    MEP_BEGIN("update", "ViewGen");
    v_Result_b = updateDistortLut_b();
    v_Result_b = updateViewGen_b();
    MEP_END("update", "ViewGen");
  }

  return v_Result_b;
}

void FpgaViewGen::free_v()
{
  mutex_o.take_b();

  if((isViewGenConfigDone_b == true) && (isViewGenProcessed_b == true))
  {
    isViewGenConfigDone_b = false;
    isViewGenProcessed_b = false;
  }

  mutex_o.give_v();
}

bool_t FpgaViewGen::updateViewGen_b()
{
  bool_t v_Result_b = true;

  if((isDistortionInitialized_b == true) && (v_Result_b == true))
  {
    v_Result_b = v_Result_b && updateSequenceTable_b();
    v_Result_b = v_Result_b && updateUndist_b();
    v_Result_b = v_Result_b && updateMatMul_b();
  }
  else
  {
    v_Result_b = false;
  }

  return v_Result_b;
}

bool_t FpgaViewGen::updateDistortLut_b()
{
  bool_t v_Result_b = false;

  MEP_BEGIN("updateDistortLUT", "viewGen");

  if(isViewGenInitialized_b == true)
  {
    uint32_t v_DistCRC_u32 = mecl::crc::c_CRC_INITIAL_VALUE_u32;

    for(uint32_t v_CamID_u32 = 0; v_CamID_u32 < variants::e_CameraCount; v_CamID_u32++)
    {
      void* v_DistPixelDensity_pv   = viewGenConfig_o.getDistPixelDensity_pv(static_cast<variants::Camera_t>(v_CamID_u32));
      void* v_DistPrincipalPoint_pv = viewGenConfig_o.getDistPrincipalPoints_pv(static_cast<variants::Camera_t>(v_CamID_u32));
      void* v_DistLUT_pv            = viewGenConfig_o.getDistortLUT_pv(static_cast<variants::Camera_t>(v_CamID_u32));

      uint32_t* v_ImageDistPixelDensity_pv   = reinterpret_cast<uint32_t*>(imageViewGenConfig_o.getDistPixelDensity_pv(static_cast<variants::Camera_t>(v_CamID_u32)));
      uint32_t* v_ImageDistPrincipalPoint_pv = reinterpret_cast<uint32_t*>(imageViewGenConfig_o.getDistPrincipalPoints_pv(static_cast<variants::Camera_t>(v_CamID_u32)));
      uint32_t* v_ImageDistLUT_pv            = reinterpret_cast<uint32_t*>(imageViewGenConfig_o.getDistortLUT_pv(static_cast<variants::Camera_t>(v_CamID_u32)));

      uint32_t* v_CacheDistPixelDensity_pv   = reinterpret_cast<uint32_t*>(cacheViewGenConfig_o.getDistPixelDensity_pv(static_cast<variants::Camera_t>(v_CamID_u32)));
      uint32_t* v_CacheDistPrincipalPoint_pv = reinterpret_cast<uint32_t*>(cacheViewGenConfig_o.getDistPrincipalPoints_pv(static_cast<variants::Camera_t>(v_CamID_u32)));
      uint32_t* v_CacheDistLUT_pv            = reinterpret_cast<uint32_t*>(cacheViewGenConfig_o.getDistortLUT_pv(static_cast<variants::Camera_t>(v_CamID_u32)));

      for(uint32_t v_I_u32 = 0; v_I_u32 < ViewGenConfig::getDistPixelDensityEntryCount_u32(); v_I_u32++)
      {
        ME_IO_Out32_b(                      v_DistPixelDensity_pv, v_I_u32 * sizeof(uint32_t),
          (reinterpret_cast<uint32_t*>(v_CacheDistPixelDensity_pv)[v_I_u32]));
        v_ImageDistPixelDensity_pv[v_I_u32] = reinterpret_cast<uint32_t*>(v_CacheDistPixelDensity_pv)[v_I_u32];
      }

#ifdef USE_CRC
      v_DistCRC_u32 = mecl::crc::calculateFpgaCRC32(reinterpret_cast<uint32_t*>(v_CacheDistPixelDensity_pv),
                                                  ViewGenConfig::getDistPixelDensityEntryCount_u32(), v_DistCRC_u32);
#endif
      for(uint32_t v_I_u32 = 0; v_I_u32 < ViewGenConfig::getDistPrincipalPointsEntryCount_u32(); v_I_u32++)
      {
        ME_IO_Out32_b(                      v_DistPrincipalPoint_pv, v_I_u32 * sizeof(uint32_t),
          (reinterpret_cast<uint32_t*>(v_CacheDistPrincipalPoint_pv)[v_I_u32]));
        v_ImageDistPrincipalPoint_pv[v_I_u32] = reinterpret_cast<uint32_t*>(v_CacheDistPrincipalPoint_pv)[v_I_u32];
      }
#ifdef USE_CRC
      v_DistCRC_u32 = mecl::crc::calculateFpgaCRC32(reinterpret_cast<uint32_t*>(v_CacheDistPrincipalPoint_pv),
                                                  ViewGenConfig::getDistPrincipalPointsEntryCount_u32(), v_DistCRC_u32);
#endif
      for(uint32_t v_I_u32 = 0; v_I_u32 < ViewGenConfig::getDistortLUTEntryCount_u32(); v_I_u32++)
      {
        ME_IO_Out32_b(                      v_DistLUT_pv, v_I_u32 * sizeof(uint32_t),
          (reinterpret_cast<uint32_t*>(v_CacheDistLUT_pv)[v_I_u32]));
        v_ImageDistLUT_pv[v_I_u32] = reinterpret_cast<uint32_t*>(v_CacheDistLUT_pv)[v_I_u32];
      }
#ifdef USE_CRC
      v_DistCRC_u32 = mecl::crc::calculateFpgaCRC32(reinterpret_cast<uint32_t*>(v_CacheDistLUT_pv),
                                                  ViewGenConfig::getDistortLUTEntryCount_u32(), v_DistCRC_u32);
#endif
    }

    uint32_t v_FpgaCRC_u32 = 0x00U;
    ME_IO_In32_b(viewGenConfigBase_pv, 0x28U, &v_FpgaCRC_u32);

    if(v_DistCRC_u32 == mecl::crc::c_CRC_INITIAL_VALUE_u32)
    {
      v_Result_b = true;
    }
    else
    {
      v_Result_b = (v_DistCRC_u32 == v_FpgaCRC_u32);
    }

    if(v_Result_b == true)
    {
      isDistortionInitialized_b = true;
    }
  }

  MEP_END("updateDistortLUT", "viewGen");

  return v_Result_b;
}

bool_t FpgaViewGen::updateReadBuffer_b() const
{
  static uint32_t v_PrevUnderfloorReadBuffer_u32 = 0;

  if(underfloorReadBuffer_u32 != v_PrevUnderfloorReadBuffer_u32)
  {
    ME_IO_Out32_b(viewGenConfigBase_pv, 0x24U, underfloorReadBuffer_u32 << 8U);
    v_PrevUnderfloorReadBuffer_u32 = underfloorReadBuffer_u32;
  }

  return true;
}

bool_t FpgaViewGen::updateDistImm_b()
{
  bool_t v_Result_b = false;

  if(isProcessingViewGen_b() == false)
  {
    mutex_o.take_b();
    for(uint32_t v_CamID_u32 = 0; v_CamID_u32 < variants::e_CameraCount; v_CamID_u32++)
    {
      if(0 != memcmp(cacheViewGenConfig_o.getDistPixelDensity_pv(static_cast<variants::Camera_t>(v_CamID_u32)),
             imageViewGenConfig_o.getDistPixelDensity_pv(static_cast<variants::Camera_t>(v_CamID_u32)),
             ViewGenConfig::getDistPixelDensityEntryCount_u32() * sizeof(uint32_t)))
      {
        v_Result_b = true;
      }

      if(0 != memcmp(cacheViewGenConfig_o.getDistPrincipalPoints_pv(static_cast<variants::Camera_t>(v_CamID_u32)),
             imageViewGenConfig_o.getDistPrincipalPoints_pv(static_cast<variants::Camera_t>(v_CamID_u32)),
             ViewGenConfig::getDistPrincipalPointsEntryCount_u32() * sizeof(uint32_t)))
      {
        v_Result_b = true;
      }

      if(0 != memcmp(cacheViewGenConfig_o.getDistortLUT_pv(static_cast<variants::Camera_t>(v_CamID_u32)),
               imageViewGenConfig_o.getDistortLUT_pv(static_cast<variants::Camera_t>(v_CamID_u32)),
               ViewGenConfig::getDistortLUTEntryCount_u32() * sizeof(uint32_t)))
      {
        v_Result_b = true;
      }
    }

    mutex_o.give_v();

    if(v_Result_b == true)
    {
      if((disable_b() == true))
      {
        while(false == lock_b());
        v_Result_b = updateDistortLut_b() && v_Result_b;
        unlock_b();

        v_Result_b = enable_b(true) && v_Result_b;
      }
      else
      {
        v_Result_b = false;
      }
    }
    else
    {
      v_Result_b = true;
    }
  }

  return v_Result_b;
}

bool_t FpgaViewGen::updateHarmonizationImm_b()
{
  bool_t v_Result_b = false;

  if((isEnabled_b() == true) && (isProcessingViewGen_b() == false))
  {
    if(lock_b() == true)
    {
      v_Result_b = updateHarmonization_b();

      unlock_b();
    }
  }

  return v_Result_b;
}

bool_t FpgaViewGen::updateHarmonization_b() const
{
  bool_t v_Result_b = true;

  void* v_HarmonApplFactors_pv      = viewGenConfig_o.getHarmonApplicationFactors_pv();
  void* v_CacheHarmonApplFactors_pv = cacheViewGenConfig_o.getHarmonApplicationFactors_pv();

  for(uint32_t v_I_u32 = 0; v_I_u32 < (c_HarmonApplicationFactorsSize_u32 / sizeof(uint32_t)); ++v_I_u32)
  {
    ME_IO_Out32_b(                      v_HarmonApplFactors_pv, v_I_u32 * sizeof(uint32_t),
      (reinterpret_cast<uint32_t*>(v_CacheHarmonApplFactors_pv)[v_I_u32]));
    ME_Thread_Sleep_t(1);
  }

  void* v_HarmonApplOffsets_pv      = viewGenConfig_o.getHarmonApplicationOffsets_pv();
  void* v_CacheHarmonApplOffsets_pv = cacheViewGenConfig_o.getHarmonApplicationOffsets_pv();

  for(uint32_t v_I_u32 = 0; v_I_u32 < (c_HarmonApplicationOffsetsSize_u32 / sizeof(uint32_t)); ++v_I_u32)
  {
    ME_IO_Out32_b(                      v_HarmonApplOffsets_pv, v_I_u32 * sizeof(uint32_t),
      (reinterpret_cast<uint32_t*>(v_CacheHarmonApplOffsets_pv)[v_I_u32]));
    ME_Thread_Sleep_t(1);
  }

  void* v_HarmonThresh_pv      = viewGenConfig_o.getHarmonThresh_pv();
  void* v_CacheHarmonThresh_pv = cacheViewGenConfig_o.getHarmonThresh_pv();

  for(uint32_t v_I_u32 = 0; v_I_u32 < (c_HarmonThresholdSize_u32 / sizeof(uint32_t)); ++v_I_u32)
  {
    ME_IO_Out32_b(                      v_HarmonThresh_pv, v_I_u32 * sizeof(uint32_t),
      (reinterpret_cast<uint32_t*>(v_CacheHarmonThresh_pv)[v_I_u32]));
    ME_Thread_Sleep_t(2);
  }

  return v_Result_b;
}

bool_t FpgaViewGen::updateSequenceTable_b() const
{
  bool_t v_Result_b = false;
  uint32_t v_SequencingTableCRC_u32 = mecl::crc::c_CRC_INITIAL_VALUE_u32;

  void* v_SequencingTable_pv      = viewGenConfig_o.getSequencingTable_pv();
  void* v_CacheSequencingTable_pv = cacheViewGenConfig_o.getSequencingTable_pv();
  for(uint32_t v_I_u32 = 0; v_I_u32 < (c_SequencingTableSize_u32 / sizeof(uint32_t)); v_I_u32++)
  {
    ME_IO_Out32_b(                      v_SequencingTable_pv, v_I_u32 * sizeof(uint32_t),
      (reinterpret_cast<uint32_t*>(v_CacheSequencingTable_pv)[v_I_u32]));
  }

#ifdef USE_CRC
  v_SequencingTableCRC_u32 = mecl::crc::calculateFpgaCRC32(reinterpret_cast<uint32_t*>(v_CacheSequencingTable_pv),
                                                (c_SequencingTableSize_u32 / sizeof(uint32_t)), v_SequencingTableCRC_u32);
#endif

  uint32_t v_FpgaCRC_u32 = 0x00U;
  ME_IO_In32_b(viewGenConfigBase_pv, 0x30U, &v_FpgaCRC_u32);

  if(v_SequencingTableCRC_u32 == mecl::crc::c_CRC_INITIAL_VALUE_u32)
  {
    v_Result_b = true;
  }
  else
  {
    v_Result_b = (v_SequencingTableCRC_u32 == v_FpgaCRC_u32);
  }

  return v_Result_b;
}

bool_t FpgaViewGen::updateUndist_b() const
{
  bool_t v_Result_b = false;
  uint32_t v_UndistCRC_u32 = mecl::crc::c_CRC_INITIAL_VALUE_u32;

  for(uint32_t v_LensId_u32 = 0; v_LensId_u32 < c_MaxLensCount_u32; v_LensId_u32++)
  {
    void* v_UndistPrincipalPoint_pv = viewGenConfig_o.getUndistPrincipalPoints_pv(v_LensId_u32);
    void* v_CacheUndistPrincipalPoint_pv = cacheViewGenConfig_o.getUndistPrincipalPoints_pv(v_LensId_u32);

    void* v_UndistLUT_pv = viewGenConfig_o.getUndistortLUT_pv(v_LensId_u32);
    void* v_CacheUndistLUT_pv = cacheViewGenConfig_o.getUndistortLUT_pv(v_LensId_u32);

    for(uint32_t v_I_u32 = 0; v_I_u32 < ViewGenConfig::getUndistPrincipalPoitnsEntryCount_u32(); v_I_u32++)
    {
      ME_IO_Out32_b(                      v_UndistPrincipalPoint_pv, v_I_u32 * sizeof(uint32_t),
        (reinterpret_cast<uint32_t*>(v_CacheUndistPrincipalPoint_pv)[v_I_u32]));
    }

#ifdef USE_CRC
    v_UndistCRC_u32 = mecl::crc::calculateFpgaCRC32(reinterpret_cast<uint32_t*>(v_CacheUndistPrincipalPoint_pv),
                                                  ViewGenConfig::getUndistPrincipalPoitnsEntryCount_u32(), v_UndistCRC_u32);
#endif

    uint32_t v_SpViewGen_u32 = 0U;
    uint32_t v_SpViewGenCache_u32 = 0U;

    for(uint32_t v_LineID_u32 = 0; v_LineID_u32 < 35U; v_LineID_u32++)
    {
      v_SpViewGen_u32 = v_LineID_u32 * (0x100U / sizeof(uint32_t));

      for(uint32_t v_SpID_u32 = 0; v_SpID_u32 < 61U; v_SpID_u32++)
      {
        ME_IO_Out32_b(                           v_UndistLUT_pv, v_SpViewGen_u32 * sizeof(uint32_t),
               (reinterpret_cast<uint32_t*>(v_CacheUndistLUT_pv)[v_SpViewGenCache_u32]));

        v_SpViewGen_u32++;
        v_SpViewGenCache_u32++;
      }
    }

#ifdef USE_CRC
    v_UndistCRC_u32 = mecl::crc::calculateFpgaCRC32(reinterpret_cast<uint32_t*>(v_CacheUndistLUT_pv),
                                                    v_SpViewGenCache_u32, v_UndistCRC_u32);
#endif
  }

  uint32_t v_FpgaCRC_u32 = 0x00U;
  ME_IO_In32_b(viewGenConfigBase_pv, 0x34U, &v_FpgaCRC_u32);

  if(v_UndistCRC_u32 == mecl::crc::c_CRC_INITIAL_VALUE_u32)
  {
    v_Result_b = true;
  }
  else
  {
    v_Result_b = (v_UndistCRC_u32 == v_FpgaCRC_u32);
  }

  return v_Result_b;
}

bool_t FpgaViewGen::updateMatMul_b() const
{
  bool_t v_Result_b = false;
  uint32_t v_MatMulCRC_u32 = mecl::crc::c_CRC_INITIAL_VALUE_u32;

  for(uint32_t v_ProjID_u32 = 0; v_ProjID_u32 < c_MaxProjectionCount_u32; v_ProjID_u32++)
  {
    void* v_MatMul_pv      = viewGenConfig_o.getMatMul_pv(v_ProjID_u32);
    void* v_CacheMatMul_pv = cacheViewGenConfig_o.getMatMul_pv(v_ProjID_u32);

    for(uint32_t v_I_u32 = 0; v_I_u32 < ViewGenConfig::getMatMulEntryCount_u32(); v_I_u32++)
    {
      ME_IO_Out32_b(v_MatMul_pv, v_I_u32 * sizeof(uint32_t), (reinterpret_cast<uint32_t*>(v_CacheMatMul_pv)[v_I_u32]));
    }

#ifdef USE_CRC
    v_MatMulCRC_u32 = mecl::crc::calculateFpgaCRC32(reinterpret_cast<uint32_t*>(v_CacheMatMul_pv),
                                                      ViewGenConfig::getMatMulEntryCount_u32(), v_MatMulCRC_u32);
#endif
  }

  uint32_t v_FpgaMatMulCRC_u32 = 0U;
  ME_IO_In32_b(viewGenConfigBase_pv, 0x2CU, &v_FpgaMatMulCRC_u32);

  if(v_MatMulCRC_u32 == mecl::crc::c_CRC_INITIAL_VALUE_u32)
  {
    v_Result_b = true;
  }
  else
  {
    v_Result_b = (v_MatMulCRC_u32 == v_FpgaMatMulCRC_u32);
  }

  return v_Result_b;
}

bool_t FpgaViewGen::updateMatMulImm_b()
{
  bool_t v_Result_b = false;

  if((isEnabled_b() == true) && (isProcessingViewGen_b() == false))
  {
    if(true == lock_b())
    {
      v_Result_b = updateMatMul_b();

      unlock_b();
    }
  }

  return v_Result_b;
}

bool_t FpgaViewGen::updateMatMulImmSetReadBuffer_b(uint8_t i_BufferIdx_u8)
{
  bool_t v_Result_b = false;

  if((isEnabled_b() == true) && (isProcessingViewGen_b() == false))
  {
    if(true == lock_b())
    {
      v_Result_b = updateMatMul_b();

      if(isViewGenEnabled_b == true)
      {
        {
          underfloorReadBuffer_u32 = i_BufferIdx_u8;

          v_Result_b = updateReadBuffer_b();
        }
      }

      unlock_b();
    }
  }

  return v_Result_b;
}

bool_t FpgaViewGen::updateSequenceTableImm_b()
{
  bool_t v_Result_b = false;

  if(isEnabled_b() == true && isProcessingViewGen_b() == false)
  {
    if(true == lock_b())
    {
      v_Result_b = updateSequenceTable_b();
      unlock_b();
    }
  }

  return v_Result_b;
}

} // namespace bsp

#endif // ME_PLATFORM_QNX

