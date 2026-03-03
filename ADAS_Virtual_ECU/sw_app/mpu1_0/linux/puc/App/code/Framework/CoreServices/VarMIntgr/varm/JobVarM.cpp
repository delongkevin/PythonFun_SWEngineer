//--------------------------------------------------------------------------
/// @file JobVarM.cpp
/// @brief Contains the job implementation of Variant manager.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Marcel Engelhardt (Marcel.Engelhardt@magna.com)
///
//  --------------------------------------------------------------------------
#include <platform/PlatformAPI.h>

#include "JobVarM.h"
#include "container/MessageQueue.h"

// Get Default variant data 
#include <variants/Variant8/VariantData.h>
#include <variants/VariantHelper.h>
#include <variants/Assets.h>
#ifdef ENABLE_RUNTIME_STATS
#define PROFILE_VarM   (1u)
#endif
#if PROFILE_VarM
#include "osal/system/Time.h"
#endif
namespace varm
{

JobVarM::JobVarM(container::JobDesc_s& b_JobDesc_rs, IDataProviderVarM& b_DataProvider_ro)
    : JobBase(b_JobDesc_rs, b_DataProvider_ro)
{
}

JobVarM::~JobVarM()
{
}


bool_t JobVarM::onInit_b()
{
  return true;
}

void JobVarM::onVariantChanged_v(bool_t i_FirstTime_b)
{

}

bool_t JobVarM::onRun_b()
{
  #if PROFILE_VarM
  static osal::Time start;
  volatile uint32_t v_Start_t = 0;
  volatile uint32_t v_End_t = 0;
  v_Start_t = __get_time_usec();
  #endif

  logger_o.log_b(logging::e_LogLvlVerbose, "JobVarM::onRun_b() \n");

  bool_t v_Success_b = loadVariantData_b();

  logger_o.log_b(logging::e_LogLvlInfo, "JobVarM::New VariantID \n");

  float32_t xyz[3];
  ME_VariantHelper_GetCameraPosition_b(variants::e_CameraFront, &xyz[0], &xyz[1], &xyz[2]);

  float32_t worldToImage_af32[variants::e_CoefficientsCount];
  ME_VariantHelper_GetCameraLensWorldToImage_b(variants::e_CameraFront, &worldToImage_af32[0], variants::e_CoefficientsCount);
  logger_o.log_b(logging::e_LogLvlInfo, "JobVarM::CameraPosition X = %f, Y = %f, Z = %f \n", xyz[0], xyz[1], xyz[2]);
  logger_o.log_b(logging::e_LogLvlInfo, "JobVarM::WorldToImage 0 = %f, 1 = %f, 2 = %f \n", worldToImage_af32[0], worldToImage_af32[1], worldToImage_af32[2]);

  if (true == v_Success_b)
  {
    logger_o.log_b(logging::e_LogLvlInfo, "JobVarM::Reloading Variant data ok \n");
  }
  else
  {
    logger_o.log_b(logging::e_LogLvlError, "JobVarM::ERROR Reloading Variant data \n");
  }
//  printf("ONRUN_B- %s\n", __PRETTY_FUNCTION__);
  ME_Thread_Sleep_t(5);
  
  #if PROFILE_VarM
  v_End_t = __get_time_usec();
  // ME_Debugger_F_Printf_v("VarM: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
  #endif

  return true;
}

void JobVarM::onCleanup_v()
{
}

bool_t JobVarM::loadVariantData_b()
{
#ifdef ME_PLATFORM_QNX
// PRQA S 1034 1 // makes code more readable here
#define ME_VARM_LOAD_PHYSICAL
#endif


#ifdef ME_VARM_LOAD_PHYSICAL
  size_t v_MemorySize_t = variants::c_GDEVariantDataSize_t; // 2MB
  size_t v_PhysicalMemoryAddr_t = 0x4FE00000;
  void* v_VirtualMemory_pv = NULL;
  PlatformError_t v_Error_t = ME_SharedMemory_MapPhysicalByAddress_t(v_PhysicalMemoryAddr_t, v_MemorySize_t, &v_VirtualMemory_pv);
  uint8_t* v_VirtualMemory_pu8 = reinterpret_cast<uint8_t*>(v_VirtualMemory_pv);


  bool_t v_Success_b = false;
  if ((e_PeOk == v_Error_t) && (NULL != v_VirtualMemory_pv))
  {
    v_Success_b = variants::ME_VariantHelper_LoadFromMemory_b(v_VirtualMemory_pu8, v_MemorySize_t);

    v_Error_t = ME_SharedMemory_UnlockPhysical_t(v_VirtualMemory_pv, v_MemorySize_t);
    if (e_PeOk != v_Error_t)
    {
      logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskDlt, "Shared Memory Unlock Physical failed. \n");
    }
  }

  // fall back to header file
  if (false == v_Success_b)
  {
    logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskDlt, "loading variant data from physical memory failed - fallback to header file \n");

    // PRQA S 3083 1 // just read access from memory here
    v_Success_b = variants::ME_VariantHelper_LoadFromMemory_b(const_cast<uint8_t*>(&c_VariantData_au8[0]), c_VariantDataSize_u32);
  }
  else
  {
    logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskDlt, "loading variant data from physical memory succeeded \n");
  }
#else
  // PRQA S 3083 1 // just read access from memory here
  bool_t v_Success_b = variants::ME_VariantHelper_LoadFromMemory_b(const_cast<uint8_t*>(&c_VariantData_au8[0]), c_VariantDataSize_u32);
#endif

  if (false == v_Success_b)
  {
    logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskDlt, "loading variant data from header failed \n");
  }

  return v_Success_b;
}

bool_t JobVarM::loadVariantDataFromID_b(uint32_t i_ID_u32)
{
  mepl::string v_FileName_o = "/Variants/Variant" + std::to_string((uint64_t)i_ID_u32) + "/Data.bin";

#ifdef ME_PLATFORM_WIN
    v_FileName_o = "../../../../../../../App/code/Framework/CoreLibs/variants/variants/Variant" + std::to_string((uint64_t)i_ID_u32) + "/Data.bin";
#elif defined(ME_PLATFORM_RTOS)
  v_FileName_o = "Variant0.bin";
#endif

  return loadVariantDataFromFile_b(v_FileName_o);
}

bool_t JobVarM::loadVariantDataFromFile_b(const mepl::string& i_FileName_ro)
{
  bool_t v_Success_b = variants::ME_VariantHelper_LoadFromFile_b(i_FileName_ro.c_str());
  printf("Loading the file : %s\n",i_FileName_ro.c_str());
  // fall back to header file
  if (false == v_Success_b)
  {
    logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskDlt, "loading variant data from file failed - fallback to header file \n");

    // PRQA S 3083 1 // just read access from memory here
    v_Success_b = variants::ME_VariantHelper_LoadFromMemory_b(const_cast<uint8_t*>(&c_VariantData_au8[0]), c_VariantDataSize_u32);
  }
  else
  {
    logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskDlt, "loading variant data from file succeeded \n");
  }

  if (false == v_Success_b)
  {
    logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskDlt, "loading variant data from header failed \n");
  }

  return v_Success_b;
}

} // namespace varm

