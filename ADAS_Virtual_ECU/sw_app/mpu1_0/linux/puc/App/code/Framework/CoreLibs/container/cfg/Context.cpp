//--------------------------------------------------------------------------
/// @file Context.cpp
/// @brief
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@Magna.com)
///
//  --------------------------------------------------------------------------

#include "Context.h"

#include "container/MessageQueue.h"
#include "cfg/DataProviderTypes.h"

#include <osal/threading/Thread.h>

#include <platform/PlatformSpecs.h>

#include <logging/Logger.h>

// PRQA S 3103 EOF // needed to cast from base classes
// PRQA S 5118 EOF // false detection - using placement new here
// PRQA S 2313 EOF // static as this is context for shared mem

namespace container
{
  JobContext Context::s_ContextTable_ao[variants::e_JobCount];

  const sint32_t Context::s_MaxLogLvlError_s32 = logging::e_LogLvlInfo;//DEFAULT_LOG_LEVEL;

  // Define Queue + Data Container Sizes for each Job
  static const sint32_t c_JobAppMCpuAffinity_s32 = e_CpuAny;
  static const sint32_t c_JobAppMPriority_s32 = e_PriorityRealtime;
  static const sint32_t c_JobAppMStackSize_s32 = ME_Thread_C_DefaultStackSize_t;
  static const sint32_t c_JobAppMExternalQueueSize_s32 = 20;
  static const sint32_t c_JobAppMSystemQueueSize_s32 = 20;
  static const sint32_t c_JobAppMInternalQueueSize_s32 = 4;
  static const sint32_t c_JobAppMDataContainerSize_s32 = MAKE_ALIGNMENT_SIZE(sizeof(AppMData_t));

  static const sint32_t c_JobSigMCpuAffinity_s32 = e_CpuAny;
  static const sint32_t c_JobSigMPriority_s32 = e_PriorityAboveHigh;
  static const sint32_t c_JobSigMStackSize_s32 = ME_Thread_C_DefaultStackSize_t;
  static const sint32_t c_JobSigMExternalQueueSize_s32 = 20;
  static const sint32_t c_JobSigMSystemQueueSize_s32 = 20;
  static const sint32_t c_JobSigMInternalQueueSize_s32 = 4;
  static const sint32_t c_JobSigMDataContainerSize_s32 = MAKE_ALIGNMENT_SIZE(sizeof(SigMData_t));

  static const sint32_t c_JobVarMCpuAffinity_s32 = e_CpuAny;
  static const sint32_t c_JobVarMPriority_s32 = e_PriorityNormal;
  static const sint32_t c_JobVarMStackSize_s32 = ME_Thread_C_DefaultStackSize_t;
  static const sint32_t c_JobVarMExternalQueueSize_s32 = 20;
  static const sint32_t c_JobVarMSystemQueueSize_s32 = 20;
  static const sint32_t c_JobVarMInternalQueueSize_s32 = 4;
  static const sint32_t c_JobVarMDataContainerSize_s32 = MAKE_ALIGNMENT_SIZE(sizeof(VarMData_t));

  static const sint32_t c_JobLogMCpuAffinity_s32 = e_CpuAny;
  static const sint32_t c_JobLogMPriority_s32 = e_PriorityNormal;
  static const sint32_t c_JobLogMStackSize_s32 = ME_Thread_C_DefaultStackSize_t;
  static const sint32_t c_JobLogMExternalQueueSize_s32 = 20;
  static const sint32_t c_JobLogMSystemQueueSize_s32 = 20;
  static const sint32_t c_JobLogMInternalQueueSize_s32 = 4;
  static const sint32_t c_JobLogMDataContainerSize_s32 = 0U;

  static const sint32_t c_JobCamMCpuAffinity_s32 = e_CpuAny;
  static const sint32_t c_JobCamMPriority_s32 = e_PriorityNormal;
  static const sint32_t c_JobCamMStackSize_s32 = ME_Thread_C_DefaultStackSize_t;
  static const sint32_t c_JobCamMExternalQueueSize_s32 = 20;
  static const sint32_t c_JobCamMSystemQueueSize_s32 = 20;
  static const sint32_t c_JobCamMInternalQueueSize_s32 = 4;
  static const sint32_t c_JobCamMDataContainerSize_s32 = MAKE_ALIGNMENT_SIZE(sizeof(CamMData_t));

  static const sint32_t c_JobEOLCpuAffinity_s32 = e_CpuAny;
  static const sint32_t c_JobEOLPriority_s32 = e_PriorityBelowHigh;
  static const sint32_t c_JobEOLStackSize_s32 = /*0x500000;*/ME_Thread_C_DefaultStackSize_t;
  static const sint32_t c_JobEOLExternalQueueSize_s32 = 20;
  static const sint32_t c_JobEOLSystemQueueSize_s32 = 20;
  static const sint32_t c_JobEOLInternalQueueSize_s32 = 4;
  static const sint32_t c_JobEOLDataContainerSize_s32 = MAKE_ALIGNMENT_SIZE(sizeof(EolMData_t));

  static const sint32_t c_JobOVL3DCpuAffinity_s32 = e_CpuAny;
  static const sint32_t c_JobOVL3DPriority_s32 = e_PriorityHigh;
  static const sint32_t c_JobOVL3DStackSize_s32 = ME_Thread_C_DefaultStackSize_t;
  static const sint32_t c_JobOVL3DExternalQueueSize_s32 = 20;
  static const sint32_t c_JobOVL3DSystemQueueSize_s32 = 20;
  static const sint32_t c_JobOVL3DInternalQueueSize_s32 = 4;
  static const sint32_t c_JobOVL3DDataContainerSize_s32 = MAKE_ALIGNMENT_SIZE(sizeof(OVL3DData_t));

  static const sint32_t c_JobSysCpuAffinity_s32 = e_CpuAny;
  static const sint32_t c_JobSysPriority_s32 = e_PriorityNormal;
  static const sint32_t c_JobSysStackSize_s32 = ME_Thread_C_DefaultStackSize_t;
  static const sint32_t c_JobSysExternalQueueSize_s32 = 20;
  static const sint32_t c_JobSysSystemQueueSize_s32 = 20;
  static const sint32_t c_JobSysInternalQueueSize_s32 = 4;
  static const sint32_t c_JobSysDataContainerSize_s32 = 0;

#ifdef USE_VDG
  static const sint32_t c_JobVDGCpuAffinity_s32 = e_CpuAny;
  static const sint32_t c_JobVDGPriority_s32 = e_PriorityBelowRealtime;
  static const sint32_t c_JobVDGStackSize_s32 = ME_Thread_C_DefaultStackSize_t;
  static const sint32_t c_JobVDGExternalQueueSize_s32 = 20;
  static const sint32_t c_JobVDGSystemQueueSize_s32 = 20;
  static const sint32_t c_JobVDGInternalQueueSize_s32 = 4;
  static const sint32_t c_JobVDGDataContainerSize_s32 = MAKE_ALIGNMENT_SIZE(sizeof(VDGData_t));
#endif

  static const sint32_t c_JobSysMonCpuAffinity_s32 = e_CpuAny;
  static const sint32_t c_JobSysMonPriority_s32 = e_PriorityNormal;
  static const sint32_t c_JobSysMonStackSize_s32 = ME_Thread_C_DefaultStackSize_t;
  static const sint32_t c_JobSysMonExternalQueueSize_s32 = 20;
  static const sint32_t c_JobSysMonSystemQueueSize_s32 = 20;
  static const sint32_t c_JobSysMonInternalQueueSize_s32 = 4;
  static const sint32_t c_JobSysMonDataContainerSize_s32 = MAKE_ALIGNMENT_SIZE(sizeof(SysMonData_t));

  static const sint32_t c_JobOCCpuAffinity_s32 = e_CpuAny;
  static const sint32_t c_JobOCPriority_s32 = e_PriorityNormal;
  static const sint32_t c_JobOCStackSize_s32 = ME_Thread_C_DefaultStackSize_t;
  static const sint32_t c_JobOCExternalQueueSize_s32 = 20;
  static const sint32_t c_JobOCSystemQueueSize_s32 = 20;
  static const sint32_t c_JobOCInternalQueueSize_s32 = 4;
  static const sint32_t c_JobOCDataContainerSize_s32 = MAKE_ALIGNMENT_SIZE(sizeof(OcMData_t));

  static const sint32_t c_JobTIOVXCpuAffinity_s32 = e_CpuAny;
  static const sint32_t c_JobTIOVXPriority_s32 = e_PriorityHigh;
  static const sint32_t c_JobTIOVXStackSize_s32 = ME_Thread_C_DefaultStackSize_t;
  static const sint32_t c_JobTIOVXExternalQueueSize_s32 = 20;
  static const sint32_t c_JobTIOVXSystemQueueSize_s32 = 20;
  static const sint32_t c_JobTIOVXInternalQueueSize_s32 = 4;
  static const sint32_t c_JobTIOVXDataContainerSize_s32 = MAKE_ALIGNMENT_SIZE(sizeof(TIOVXData_t));

  static const sint32_t c_JobCALSMCpuAffinity_s32 = e_CpuAny;
  static const sint32_t c_JobCALSMPriority_s32 = e_PriorityBelowHigh;
  static const sint32_t c_JobCALSMStackSize_s32 = ME_Thread_C_DefaultStackSize_t;
  static const sint32_t c_JobCALSMExternalQueueSize_s32 = 20;
  static const sint32_t c_JobCALSMSystemQueueSize_s32 = 20;
  static const sint32_t c_JobCALSMInternalQueueSize_s32 = 4;
  static const sint32_t c_JobCALSMDataContainerSize_s32 = MAKE_ALIGNMENT_SIZE(sizeof(CalSmMData_t));

  static const sint32_t c_JobTHACpuAffinity_s32 = e_CpuAny;
  static const sint32_t c_JobTHAPriority_s32 = e_PriorityNormal;
  static const sint32_t c_JobTHAStackSize_s32 = ME_Thread_C_DefaultStackSize_t;
  static const sint32_t c_JobTHAExternalQueueSize_s32 = 20;
  static const sint32_t c_JobTHASystemQueueSize_s32 = 20;
  static const sint32_t c_JobTHAInternalQueueSize_s32 = 4;
  static const sint32_t c_JobTHADataContainerSize_s32 = MAKE_ALIGNMENT_SIZE(sizeof(THAData_t));

  static const sint32_t c_JobTAD2CpuAffinity_s32 = e_CpuAny;
  static const sint32_t c_JobTAD2Priority_s32 = e_PriorityNormal;
  static const sint32_t c_JobTAD2StackSize_s32 = ME_Thread_C_DefaultStackSize_t;
  static const sint32_t c_JobTAD2ExternalQueueSize_s32 = 20;
  static const sint32_t c_JobTAD2SystemQueueSize_s32 = 20;
  static const sint32_t c_JobTAD2InternalQueueSize_s32 = 4;
  static const sint32_t c_JobTAD2DataContainerSize_s32 = MAKE_ALIGNMENT_SIZE(sizeof(TAD2Data_t));

  static const sint32_t c_JobDLDCpuAffinity_s32 = e_CpuAny;
  static const sint32_t c_JobDLDPriority_s32 = e_PriorityNormal;
  static const sint32_t c_JobDLDStackSize_s32 = ME_Thread_C_DefaultStackSize_t;
  static const sint32_t c_JobDLDExternalQueueSize_s32 = 20;
  static const sint32_t c_JobDLDSystemQueueSize_s32 = 20;
  static const sint32_t c_JobDLDInternalQueueSize_s32 = 4;
  static const sint32_t c_JobDLDDataContainerSize_s32 = MAKE_ALIGNMENT_SIZE(sizeof(DLDData_t));
  
  // Calculate Size at Compile Time
  enum
  {
    // JobSys
    e_JobSysContextSize = HEADER_SIZE
    + QUEUE_SIZE(c_JobSysExternalQueueSize_s32)
    + QUEUE_SIZE(c_JobSysSystemQueueSize_s32)
    + QUEUE_SIZE(c_JobSysInternalQueueSize_s32)
    + c_JobSysDataContainerSize_s32,

    // JobApp
    e_JobAppMContextSize = HEADER_SIZE
    + QUEUE_SIZE(c_JobAppMExternalQueueSize_s32)
    + QUEUE_SIZE(c_JobAppMSystemQueueSize_s32)
    + QUEUE_SIZE(c_JobAppMInternalQueueSize_s32)
    + c_JobAppMDataContainerSize_s32,

    // JogSigM
    e_JobSigMContextSize = HEADER_SIZE
    + QUEUE_SIZE(c_JobSigMExternalQueueSize_s32)
    + QUEUE_SIZE(c_JobSigMSystemQueueSize_s32)
    + QUEUE_SIZE(c_JobSigMInternalQueueSize_s32)
    + c_JobSigMDataContainerSize_s32,

    // JobVarM
    e_JobVarMContextSize = HEADER_SIZE
    + QUEUE_SIZE(c_JobVarMExternalQueueSize_s32)
    + QUEUE_SIZE(c_JobVarMSystemQueueSize_s32)
    + QUEUE_SIZE(c_JobVarMInternalQueueSize_s32)
    + c_JobVarMDataContainerSize_s32,

    // JobLogM
    e_JobLogMContextSize = HEADER_SIZE
    + QUEUE_SIZE(c_JobLogMExternalQueueSize_s32)
    + QUEUE_SIZE(c_JobLogMSystemQueueSize_s32)
    + QUEUE_SIZE(c_JobLogMInternalQueueSize_s32)
    + c_JobLogMDataContainerSize_s32,

    // JobSysMon
    e_JobSysMonContextSize = HEADER_SIZE
    + QUEUE_SIZE(c_JobSysMonExternalQueueSize_s32)
    + QUEUE_SIZE(c_JobSysMonSystemQueueSize_s32)
    + QUEUE_SIZE(c_JobSysMonInternalQueueSize_s32)
    + c_JobSysMonDataContainerSize_s32,

    // JobOVL3D
    e_JobOVL3DContextSize = HEADER_SIZE
    + QUEUE_SIZE(c_JobOVL3DExternalQueueSize_s32)
    + QUEUE_SIZE(c_JobOVL3DSystemQueueSize_s32)
    + QUEUE_SIZE(c_JobOVL3DInternalQueueSize_s32)
    + c_JobOVL3DDataContainerSize_s32,

    //JobTIOVX
    e_JobTIOVXContextSize = HEADER_SIZE
    + QUEUE_SIZE(c_JobTIOVXExternalQueueSize_s32)
    + QUEUE_SIZE(c_JobTIOVXSystemQueueSize_s32)
    + QUEUE_SIZE(c_JobTIOVXInternalQueueSize_s32)
    + c_JobTIOVXDataContainerSize_s32,

    // JobEol
    e_JobEOLContextSize = HEADER_SIZE
    + QUEUE_SIZE(c_JobEOLExternalQueueSize_s32)
    + QUEUE_SIZE(c_JobEOLSystemQueueSize_s32)
    + QUEUE_SIZE(c_JobEOLInternalQueueSize_s32)
    + c_JobEOLDataContainerSize_s32,

    // JobOC
    e_JobOCContextSize = HEADER_SIZE
    + QUEUE_SIZE(c_JobOCExternalQueueSize_s32)
    + QUEUE_SIZE(c_JobOCSystemQueueSize_s32)
    + QUEUE_SIZE(c_JobOCInternalQueueSize_s32)
    + c_JobOCDataContainerSize_s32,

    // JobCamM
    e_JobCamMContextSize = HEADER_SIZE
    + QUEUE_SIZE(c_JobCamMExternalQueueSize_s32)
    + QUEUE_SIZE(c_JobCamMSystemQueueSize_s32)
    + QUEUE_SIZE(c_JobCamMInternalQueueSize_s32)
    + c_JobCamMDataContainerSize_s32,

    // JobCALSM
    e_JobCALSMContextSize = HEADER_SIZE
    + QUEUE_SIZE(c_JobCALSMExternalQueueSize_s32)
    + QUEUE_SIZE(c_JobCALSMSystemQueueSize_s32)
    + QUEUE_SIZE(c_JobCALSMInternalQueueSize_s32)
    + c_JobCALSMDataContainerSize_s32,

	// JobTHA
    e_JobTHAContextSize = HEADER_SIZE
    + QUEUE_SIZE(c_JobTHAExternalQueueSize_s32)
    + QUEUE_SIZE(c_JobTHASystemQueueSize_s32)
    + QUEUE_SIZE(c_JobTHAInternalQueueSize_s32)
    + c_JobTHADataContainerSize_s32,

    // JobTAD2
    e_JobTAD2ContextSize = HEADER_SIZE
    + QUEUE_SIZE(c_JobTAD2ExternalQueueSize_s32)
    + QUEUE_SIZE(c_JobTAD2SystemQueueSize_s32)
    + QUEUE_SIZE(c_JobTAD2InternalQueueSize_s32)
    + c_JobTAD2DataContainerSize_s32,

    // JobDLD
    e_JobDLDContextSize = HEADER_SIZE
    + QUEUE_SIZE(c_JobDLDExternalQueueSize_s32)
    + QUEUE_SIZE(c_JobDLDSystemQueueSize_s32)
    + QUEUE_SIZE(c_JobDLDInternalQueueSize_s32)
    + c_JobDLDDataContainerSize_s32,

	// Add total size for each job to this enum entry
    e_TotalSize = e_JobAppMContextSize +
    e_JobSigMContextSize +
    e_JobVarMContextSize +
    e_JobLogMContextSize +
    e_JobEOLContextSize +
    e_JobOVL3DContextSize +
    e_JobSysContextSize +
    e_JobSysMonContextSize+
    e_JobOCContextSize +
    e_JobTIOVXContextSize +
    e_JobCamMContextSize +
    e_JobCALSMContextSize +
    e_JobTHAContextSize +
    e_JobTAD2ContextSize +
    e_JobDLDContextSize 
  };

  // order must follow order enum Job_e in ContextTypes.h
  static const ContextDesc_s s_DescriptionTable_as[variants::e_JobCount] =
  {
    {
      variants::e_JobSys,
      "Sys",
      c_JobSysCpuAffinity_s32,
      c_JobSysPriority_s32,
      c_JobSysStackSize_s32,
      c_JobSysExternalQueueSize_s32,
      c_JobSysSystemQueueSize_s32,
      c_JobSysInternalQueueSize_s32,
      c_JobSysDataContainerSize_s32,
      e_JobSysContextSize
    },
    {
      variants::e_JobAppM,
      "AppM",
      c_JobAppMCpuAffinity_s32,
      c_JobAppMPriority_s32,
      c_JobAppMStackSize_s32,
      c_JobAppMExternalQueueSize_s32,
      c_JobAppMSystemQueueSize_s32,
      c_JobAppMInternalQueueSize_s32,
      c_JobAppMDataContainerSize_s32,
      e_JobAppMContextSize
    },
    {
      variants::e_JobSigM,
      "SigM",
      c_JobSigMCpuAffinity_s32,
      c_JobSigMPriority_s32,
      c_JobSigMStackSize_s32,
      c_JobSigMExternalQueueSize_s32,
      c_JobSigMSystemQueueSize_s32,
      c_JobSigMInternalQueueSize_s32,
      c_JobSigMDataContainerSize_s32,
      e_JobSigMContextSize
    },
    {
      variants::e_JobVarM,
      "VarM",
      c_JobVarMCpuAffinity_s32,
      c_JobVarMPriority_s32,
      c_JobVarMStackSize_s32,
      c_JobVarMExternalQueueSize_s32,
      c_JobVarMSystemQueueSize_s32,
      c_JobVarMInternalQueueSize_s32,
      c_JobVarMDataContainerSize_s32,
      e_JobVarMContextSize
    },
    {
      variants::e_JobLogM,
      "LogM",
      c_JobLogMCpuAffinity_s32,
      c_JobLogMPriority_s32,
      c_JobLogMStackSize_s32,
      c_JobLogMExternalQueueSize_s32,
      c_JobLogMSystemQueueSize_s32,
      c_JobLogMInternalQueueSize_s32,
      c_JobLogMDataContainerSize_s32,
      e_JobLogMContextSize
    },
    {
      variants::e_JobSysMon,
      "SysMon",
      c_JobSysMonCpuAffinity_s32,
      c_JobSysMonPriority_s32,
      c_JobSysMonStackSize_s32,
      c_JobSysMonExternalQueueSize_s32,
      c_JobSysMonSystemQueueSize_s32,
      c_JobSysMonInternalQueueSize_s32,
      c_JobSysMonDataContainerSize_s32,
      e_JobSysMonContextSize
    },
    {
      variants::e_JobOVL3D,
      "OVL3",
      c_JobOVL3DCpuAffinity_s32,
      c_JobOVL3DPriority_s32,
      c_JobOVL3DStackSize_s32,
      c_JobOVL3DExternalQueueSize_s32,
      c_JobOVL3DSystemQueueSize_s32,
      c_JobOVL3DInternalQueueSize_s32,
      c_JobOVL3DDataContainerSize_s32,
      e_JobOVL3DContextSize
    },
    {
      variants::e_JobTIOVX,
      "TIOVX",
      c_JobTIOVXCpuAffinity_s32,
      c_JobTIOVXPriority_s32,
      c_JobTIOVXStackSize_s32,
      c_JobTIOVXExternalQueueSize_s32,
      c_JobTIOVXSystemQueueSize_s32,
      c_JobTIOVXInternalQueueSize_s32,
      c_JobTIOVXDataContainerSize_s32,
      e_JobTIOVXContextSize
    },
    {
      variants::e_JobEol,
      "EOL",
      c_JobEOLCpuAffinity_s32,
      c_JobEOLPriority_s32,
      c_JobEOLStackSize_s32,
      c_JobEOLExternalQueueSize_s32,
      c_JobEOLSystemQueueSize_s32,
      c_JobEOLInternalQueueSize_s32,
      c_JobEOLDataContainerSize_s32,
      e_JobEOLContextSize
    },
    {
      variants::e_JobOC,
      "OC",
      c_JobOCCpuAffinity_s32,
      c_JobOCPriority_s32,
      c_JobOCStackSize_s32,
      c_JobOCExternalQueueSize_s32,
      c_JobOCSystemQueueSize_s32,
      c_JobOCInternalQueueSize_s32,
      c_JobOCDataContainerSize_s32,
      e_JobOCContextSize
    },
    {
      variants::e_JobCamM,
      "CamM",
      c_JobCamMCpuAffinity_s32,
      c_JobCamMPriority_s32,
      c_JobCamMStackSize_s32,
      c_JobCamMExternalQueueSize_s32,
      c_JobCamMSystemQueueSize_s32,
      c_JobCamMInternalQueueSize_s32,
      c_JobCamMDataContainerSize_s32,
      e_JobCamMContextSize
    },
    {
      variants::e_JobCalSM,
      "CALSM",
      c_JobCALSMCpuAffinity_s32,
      c_JobCALSMPriority_s32,
      c_JobCALSMStackSize_s32,
      c_JobCALSMExternalQueueSize_s32,
      c_JobCALSMSystemQueueSize_s32,
      c_JobCALSMInternalQueueSize_s32,
      c_JobCALSMDataContainerSize_s32,
      e_JobCALSMContextSize
    },
    {
      variants::e_JobTHA,
      "THA",
      c_JobTHACpuAffinity_s32,
      c_JobTHAPriority_s32,
      c_JobTHAStackSize_s32,
      c_JobTHAExternalQueueSize_s32,
      c_JobTHASystemQueueSize_s32,
      c_JobTHAInternalQueueSize_s32,
      c_JobTHADataContainerSize_s32,
      e_JobTHAContextSize
    },
    {
      variants::e_JobTAD2,
      "TAD2",
      c_JobTAD2CpuAffinity_s32,
      c_JobTAD2Priority_s32,
      c_JobTAD2StackSize_s32,
      c_JobTAD2ExternalQueueSize_s32,
      c_JobTAD2SystemQueueSize_s32,
      c_JobTAD2InternalQueueSize_s32,
      c_JobTAD2DataContainerSize_s32,
      e_JobTAD2ContextSize
    },
    {
      variants::e_JobDLD,
      "DLD",
      c_JobDLDCpuAffinity_s32,
      c_JobDLDPriority_s32,
      c_JobDLDStackSize_s32,
      c_JobDLDExternalQueueSize_s32,
      c_JobDLDSystemQueueSize_s32,
      c_JobDLDInternalQueueSize_s32,
      c_JobDLDDataContainerSize_s32,
      e_JobDLDContextSize
    }
    // add new jobs here
  };

  JobContext& Context::getContext_ro(variants::Job_e i_Job_e)
  {
    return s_ContextTable_ao[i_Job_e];
  }

  void Context::createContexts_v(void)
  {
    uint8_t* v_SharedMemory_pc = NULL;
    const char_t* c_SharedMemoryName_pc = "SharedMemory";

    SharedMemory_s v_SharedMem_s = { ME_INVALID_FILE_HANDLE }; // PRQA S 1021 // invalid file handle is defined in shared c and cpp file
    PlatformError_t v_Error_t = ME_SharedMemory_UnLink_t(&v_SharedMem_s, c_SharedMemoryName_pc);
    Assert((e_PeNoEntry == v_Error_t) || (e_PeOk == v_Error_t)); // no entry is ok here for the first time if no shared mem exists

    v_Error_t = ME_SharedMemory_Init_t(&v_SharedMem_s, c_SharedMemoryName_pc, e_TotalSize, reinterpret_cast<void**>(&v_SharedMemory_pc));
    Assert(e_PeOk == v_Error_t);

    v_Error_t = ME_SharedMemory_Map_t(&v_SharedMem_s, c_SharedMemoryName_pc, e_TotalSize, reinterpret_cast<void**>(&v_SharedMemory_pc));
    Assert(e_PeOk == v_Error_t);

    for (uint32_t v_I_u32 = 0U; v_I_u32 < variants::e_JobCount; ++v_I_u32)
    {
      s_ContextTable_ao[v_I_u32] = JobContext::createJobContext_o(v_SharedMemory_pc,
                                                                  s_DescriptionTable_as[v_I_u32].c_Name_pc,
                                                                  v_I_u32,
                                                                  s_DescriptionTable_as[v_I_u32].externalQueueSize_s32,
                                                                  s_DescriptionTable_as[v_I_u32].systemQueueSize_s32,
                                                                  s_DescriptionTable_as[v_I_u32].internalQueueSize_s32,
                                                                  s_DescriptionTable_as[v_I_u32].dataContainerSize_s32,
                                                                  s_MaxLogLvlError_s32);

      // increment pointer to next Context
      v_SharedMemory_pc += s_DescriptionTable_as[v_I_u32].sharedMemSize_s32;
    }

    uint8_t* v_DataContainer_pc = NULL;
    // initialize Data Containers here with placement new
    v_SharedMemory_pc = reinterpret_cast<uint8_t*> (&(Context::getContext_ro(variants::e_JobCamM).getDataContainer_ro()));
    v_DataContainer_pc = reinterpret_cast<uint8_t*>(new(v_SharedMemory_pc) CamMData_t()); // call constructor of CamMData
    Assert(v_DataContainer_pc == v_SharedMemory_pc);

    // initialize Data Containers here with placement new
    v_SharedMemory_pc = reinterpret_cast<uint8_t*> (&(Context::getContext_ro(variants::e_JobAppM).getDataContainer_ro()));
    v_DataContainer_pc = reinterpret_cast<uint8_t*>(new(v_SharedMemory_pc) AppMData_t()); // call constructor of AppMData
    Assert(v_DataContainer_pc == v_SharedMemory_pc);

    v_SharedMemory_pc = reinterpret_cast<uint8_t*> (&(Context::getContext_ro(variants::e_JobSigM).getDataContainer_ro()));
    v_DataContainer_pc = reinterpret_cast<uint8_t*>(new(v_SharedMemory_pc) SigMData_t()); // call constructor of SigMData
    Assert(v_DataContainer_pc == v_SharedMemory_pc);

    v_SharedMemory_pc = reinterpret_cast<uint8_t*> (&(Context::getContext_ro(variants::e_JobVarM).getDataContainer_ro()));
    v_DataContainer_pc = reinterpret_cast<uint8_t*>(new(v_SharedMemory_pc) VarMData_t()); // call constructor of VarMData
    Assert(v_DataContainer_pc == v_SharedMemory_pc);

    v_SharedMemory_pc = reinterpret_cast<uint8_t*> (&(Context::getContext_ro(variants::e_JobEol).getDataContainer_ro()));
    v_DataContainer_pc = reinterpret_cast<uint8_t*>(new(v_SharedMemory_pc) EolMData_t()); // call constructor of EolMData
    Assert(v_DataContainer_pc == v_SharedMemory_pc);

    v_SharedMemory_pc = reinterpret_cast<uint8_t*> (&(Context::getContext_ro(variants::e_JobSysMon).getDataContainer_ro()));
    v_DataContainer_pc = reinterpret_cast<uint8_t*>(new(v_SharedMemory_pc) SysMonData_t()); // call constructor of SysMonData
    Assert(v_DataContainer_pc == v_SharedMemory_pc);

    v_SharedMemory_pc = reinterpret_cast<uint8_t*> (&(Context::getContext_ro(variants::e_JobTIOVX).getDataContainer_ro()));
    v_DataContainer_pc = reinterpret_cast<uint8_t*>(new(v_SharedMemory_pc) TIOVXData_t()); // call constructor of ODData
    Assert(v_DataContainer_pc == v_SharedMemory_pc);

    v_SharedMemory_pc = reinterpret_cast<uint8_t*> (&(Context::getContext_ro(variants::e_JobOVL3D).getDataContainer_ro()));
    v_DataContainer_pc = reinterpret_cast<uint8_t*>(new(v_SharedMemory_pc) OVL3DData_t()); // call constructor of OVL3DData
    Assert(v_DataContainer_pc == v_SharedMemory_pc);

    v_SharedMemory_pc = reinterpret_cast<uint8_t*> (&(Context::getContext_ro(variants::e_JobOC).getDataContainer_ro()));
    v_DataContainer_pc = reinterpret_cast<uint8_t*>(new(v_SharedMemory_pc) OcMData_t()); // call constructor of ODData
    Assert(v_DataContainer_pc == v_SharedMemory_pc);

    v_SharedMemory_pc = reinterpret_cast<uint8_t*> (&(Context::getContext_ro(variants::e_JobCalSM).getDataContainer_ro()));
    v_DataContainer_pc = reinterpret_cast<uint8_t*>(new(v_SharedMemory_pc) CalSmMData_t()); // call constructor of ODData
    Assert(v_DataContainer_pc == v_SharedMemory_pc);
	
    v_SharedMemory_pc = reinterpret_cast<uint8_t*> (&(Context::getContext_ro(variants::e_JobTHA).getDataContainer_ro()));
    v_DataContainer_pc = reinterpret_cast<uint8_t*>(new(v_SharedMemory_pc) THAData_t()); // call constructor of THAData
    Assert(v_DataContainer_pc == v_SharedMemory_pc);

    v_SharedMemory_pc = reinterpret_cast<uint8_t*> (&(Context::getContext_ro(variants::e_JobTAD2).getDataContainer_ro()));
    v_DataContainer_pc = reinterpret_cast<uint8_t*>(new(v_SharedMemory_pc) TAD2Data_t()); // call constructor of TAD2Data
    Assert(v_DataContainer_pc == v_SharedMemory_pc);

    v_SharedMemory_pc = reinterpret_cast<uint8_t*> (&(Context::getContext_ro(variants::e_JobDLD).getDataContainer_ro()));
    v_DataContainer_pc = reinterpret_cast<uint8_t*>(new(v_SharedMemory_pc) DLDData_t()); // call constructor of DLDData
    Assert(v_DataContainer_pc == v_SharedMemory_pc);
  }

  void Context::setThreadConfig_v(osal::Thread& b_Thread_rs, variants::Job_e i_Job_e)
  {
    if ((i_Job_e >= 0) && (i_Job_e < variants::e_JobCount))
    {
      const ContextDesc_s& desc_rs = s_DescriptionTable_as[i_Job_e];

      b_Thread_rs.setName_v(desc_rs.c_Name_pc);
      b_Thread_rs.setAffinity_v(static_cast<CpuId_t>(desc_rs.cpuAffinity_s32));
      b_Thread_rs.setPriority_v(static_cast<ME_Thread_Priority_t>(desc_rs.priority_s32));
      b_Thread_rs.setStackSize_v(static_cast<size_t>(desc_rs.stackSize_s32));
    }
    else
    {
      AssertMsg(false, "Invalid job id");
    }
  }

  void Context::resetContexts_v()
  {
    for(uint32_t i = 0; i < variants::e_JobCount; i++)
    {
      s_ContextTable_ao[i].reset_v();
    }
  }

} // namespace container
