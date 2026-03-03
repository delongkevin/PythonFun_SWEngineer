//--------------------------------------------------------------------------
/// @file Main.cpp
/// @brief puc_app.out starting point
///
/// Creates the basic functionalities like:
/// - context
/// - JobSys
/// - Logger
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert, Marcel Engelhardt, Martin Rachor
///
//  --------------------------------------------------------------------------

#include <platform/PlatformAPI.h>
#include <platform/stdlib/utils/ME_FileSystem.h>

#include <osal/threading/Thread.h>
#include <osal/io/File.h>

#include <bsp/graphics/Screen.h>

#include <variants/Assets.h>

#include <logging/Logger.h>

#include <varm/JobVarM.h>
#include <logm/JobLogM.h>

#include <cfg/Context.h>
#include <cfg/JobSys.h>

#include "aPuC_ver.h"
#include "fsdata/fsdata.h"
#include "ProxiParameters.h"

// PRQA S 4038 EOF // uncaught exception

//#define ME_USE_SCREEN_SERVICE

#ifndef ME_PLATFORM_LINUX
static void DebugFunctionality_RemoveOldInstancesofme_v(void); // PRQA S 2000 // global namespace, this is cpp main
#endif

static void   printSystemInfo_v();

static void   loadLogging_v();

static void   loadVariantData_v();

#ifdef ME_USE_SCREEN_SERVICE
static void   loadScreenService_v();
#endif

static void   loadContext_v();

static void   startApplication_v();


#ifdef ME_PLATFORM_RTOS
/* This demo uses heap_5.c, and these constants define the sizes of the regions
that make up the total heap.  heap_5 is only used for test and example purposes
as this demo could easily create one large heap region instead of multiple
smaller heap regions - in which case heap_4.c would be the more appropriate
choice.  See http://www.freertos.org/a00111.html for an explanation. */
#define mainREGION_1_SIZE    128U * 1024U
#define mainREGION_2_SIZE    128U * 1024U
#define mainREGION_3_SIZE    128U * 1024U

static void  prvInitialiseHeap_v()
{
  /* The Windows demo could create one large heap region, in which case it would
  be appropriate to use heap_4.  However, purely for demonstration purposes,
  heap_5 is used instead, so start by defining some heap regions.  No
  initialisation is required when any other heap implementation is used.  See
  http://www.freertos.org/a00111.html for more information.

  The xHeapRegions structure requires the regions to be defined in start address
  order, so this just creates one big array, then populates the structure with
  offsets into the array - with gaps in between and messy alignment just for test
  purposes. */
  static uint8_t ucHeap[ configTOTAL_HEAP_SIZE ];
  volatile uint32_t ulAdditionalOffset = 19; /* Just to prevent 'condition is always true' warnings in configASSERT(). */
  const HeapRegion_t xHeapRegions[] =
  {
    /* Start address with dummy offsets						Size */
    { ucHeap + 1,   mainREGION_1_SIZE },
    { ucHeap + 15 + mainREGION_1_SIZE,  mainREGION_2_SIZE },
    { ucHeap + 19 + mainREGION_1_SIZE + mainREGION_2_SIZE, mainREGION_3_SIZE },
    { NULL, 0 }
  };

  /* Sanity check that the sizes and offsets defined actually fit into the
  array. */
  configASSERT( ( ulAdditionalOffset + mainREGION_1_SIZE + mainREGION_2_SIZE + mainREGION_3_SIZE ) < configTOTAL_HEAP_SIZE );

  /* Prevent compiler warnings when configASSERT() is not defined. */
  ( void ) ulAdditionalOffset;

  vPortDefineHeapRegions( xHeapRegions );
}
#endif

// start job system thread
// PRQA S 4327 1 // PRQA S 4213 1 // PRQA S 4327 1 // keep these arguments
int main(int argc, char* argv[]) // PRQA S 2427 // use of fundamental type, this is cpp main
{
#ifdef ME_PLATFORM_WIN
  MEP_INIT("JSONProfile.json");
#else
  MEP_INIT("/tmp/JSONProfile.json");
#endif // ME_PLATFORM_WIN

#ifdef ME_PLATFORM_RTOS
  prvInitialiseHeap_v();
  ME_FileSystem_F_InitByPhysicalAddress_t(NULL);
#endif

  printSystemInfo_v();

#ifndef ME_PLATFORM_LINUX
//  DebugFunctionality_RemoveOldInstancesofme_v();
#endif

  loadLogging_v();

  loadVariantData_v();

#ifdef ME_USE_SCREEN_SERVICE
  loadScreenService_v();
#endif

  loadContext_v();

  startApplication_v();

  logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf, "Process %d is killed\n", ME_Process_GetCurrentID_t());

  return 0;
}

#ifndef ME_PLATFORM_LINUX
static void DebugFunctionality_RemoveOldInstancesofme_v(void)
{
  PlatformError_t v_Error_t;

  const uint32_t c_ProcessListCap_u32 = 500;
  ProcessID_t v_Processes_at[c_ProcessListCap_u32];
  ProcessID_t v_MyProcessesID;
  const uint32_t c_NameLength_u32 = 20;
  char_t v_Name_ac[c_NameLength_u32];
  char_t v_MyName_ac[c_NameLength_u32];

  // set invalid process id
  for (uint32_t v_I_u32 = 0U; v_I_u32 < c_ProcessListCap_u32; ++v_I_u32)
  {
    v_Processes_at[v_I_u32] = -1;
  }

  v_MyProcessesID = ME_Process_GetCurrentID_t();
#if defined(VERBOSE)
  logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, "v_MyProcessesID, PID: %d\n", v_MyProcessesID);
#endif

  (void)memset(&v_MyName_ac[0], 0x00, c_NameLength_u32);
  v_Error_t = ME_Process_GetName_t(v_MyProcessesID, &v_MyName_ac[0], c_NameLength_u32);
  Assert((e_PeOk == v_Error_t) || (e_PeNoEntry == v_Error_t));
#ifdef VERBOSE
  logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, "MyName: %s\n", &v_MyName_ac[0]);
#endif

  v_Error_t = ME_Process_EnumProcesses_t(&v_Processes_at[0], c_ProcessListCap_u32);
  Assert(e_PeOk == v_Error_t);

  for (uint32_t v_I_u32 = 0U; v_I_u32 < c_ProcessListCap_u32; ++v_I_u32)
  {
    ProcessID_t v_CurrID_t = v_Processes_at[v_I_u32];

    // ID must be valid, and NOT me
    if((-1 != v_CurrID_t) && (v_MyProcessesID != v_CurrID_t))
    {
      (void)memset(&v_Name_ac[0], 0x00, c_NameLength_u32);
      v_Error_t = ME_Process_GetName_t(v_CurrID_t, &v_Name_ac[0], c_NameLength_u32);
      Assert((e_PeOk == v_Error_t) || (e_PeNoEntry == v_Error_t));
#ifdef VERBOSE
      logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, "Process ID: %d, Name: %s\n", v_CurrID_t, &v_Name_ac[0]);
#endif

      if(0 == strcmp(&v_Name_ac[0], &v_MyName_ac[0])) // PRQA S 5029 // needed here
      {
        ME_Debugger_F_Printf_v("Killing Process ID: %d, Name: %s\n", v_CurrID_t, &v_Name_ac[0]);
        ME_Process_Kill_t(v_CurrID_t);
      }
    }
  }
}
#endif

void printSystemInfo_v()
{
  ME_Debugger_F_Printf_v("#####################################################\n");
  ME_Debugger_F_Printf_v("# Main - Magna Application                          #\n");
  ME_Debugger_F_Printf_v("# Main - Internal Build date - %s          #\n", __DATE__);
  const aPuC_ver_S_VersionInformation_t c_PuCVersion_t = { aPuC_ver_D_INTERNAL_SOFTWARE_RELEASE_NUMBER_CONSTANT_VALUE };
  ME_Debugger_F_Printf_v("# Version Info - %d , %d , %d - HW %d - B: %d V: %d      #\n", c_PuCVersion_t.YEAR, c_PuCVersion_t.WEEK, c_PuCVersion_t.DAY, c_PuCVersion_t.HW, c_PuCVersion_t.BUILD, c_PuCVersion_t.VARIANT);
  ME_Debugger_F_Printf_v("#####################################################\n");
}

void loadLogging_v()
{
  // Logging
  logm::JobLogM::initLogModes_v();
}

void loadVariantData_v()
{
  // Variant Loader
  logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, "Main - Loading variant data");

  uint8_t v_VariantId_u8 = 8U; // set default variant id
  uint16_t v_readFile = 0;
  uint8_t *temp = (uint8_t*)&v_readFile;

  osal::File v_File_o;

	ME_Proxi_MPU1_0_to_MCU1_0_t proxi_req;

	if(false == fsdata::fsdata_read_data(variants::ME_VariantHelper_GetVariantIdFilePath_pc(),(char*)&proxi_req,sizeof(proxi_req)))
	{
		printf("Variant File raeding failed, loading default variant 8\n");
		v_VariantId_u8 = 8;
	}
	else
	{
		v_VariantId_u8 = proxi_req.PRX_variantID_u8;
	}

//  if (true == v_File_o.open_b(variants::ME_VariantHelper_GetVariantIdFilePath_pc(), e_FomRead  | e_FomBinary))
//  {
//    uint64_t v_NumBytesRead_u64 = v_File_o.read_u64(reinterpret_cast<void*>(&v_readFile), sizeof(v_readFile));
//
//    v_VariantId_u8 = (temp[0] - '0')*10;
//    v_VariantId_u8 += (temp[1] - '0');
//    v_File_o.close_b();
//  }
//  else
//  {
//    logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, "Failed to open variant id file");
//  }

  if(v_VariantId_u8 > variants::e_VariantIdsCount)
  {
	  v_VariantId_u8 = 8;
	  printf("Default Variant is selected. Read VarID: %d\n",v_VariantId_u8);
  }

  bool_t v_VariantLoadingOk_b = varm::JobVarM::loadVariantDataFromID_b(v_VariantId_u8);

  if (true == v_VariantLoadingOk_b)
  {
    logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf, "Main - Loading variant data succeeded");
  }
  else
  {
    logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf, "Main - Error while loading variant Data");
  }
}

#ifdef ME_USE_SCREEN_SERVICE
void loadScreenService_v()
{
  // Screen
  logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, "Main - Starting Screen");

  variants::ScreenConfig* v_ScreenConfig_po = variants::ScreenConfig::get_po(variants::c_ScreenConfig_u32);
  const variants::ScreenConfigComponent* v_ScreenConfigComponent_po = v_ScreenConfig_po->getScreenConfigComponent_po();

  bsp::ScreenConfig_s v_ScreenConfig_s;
  v_ScreenConfig_s.width_u32 = v_ScreenConfigComponent_po->getScreenConfig_rs().screenWidth_u32;
  v_ScreenConfig_s.height_u32 = v_ScreenConfigComponent_po->getScreenConfig_rs().screenHeight_u32;
  memcpy(v_ScreenConfig_s.configFile_ac, v_ScreenConfigComponent_po->getScreenConfig_rs().configFile_ac, ME_MAX_PATH_LENGTH);

  bsp::Screen::start_b(v_ScreenConfig_s);
}
#endif

void loadContext_v()
{
  // Context
  logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, "Main - Create Context");
  container::Context::createContexts_v();
}

void startApplication_v()
{
  // Application
  logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, "Main - Starting JobSystem");
  static sys::JobSystem v_JobSys_o(container::Context::getContext_ro(variants::e_JobSys));

  v_JobSys_o.init_v();

#ifdef ME_PLATFORM_RTOS
  vTaskStartScheduler();
#endif

  v_JobSys_o.run_b();
  v_JobSys_o.cleanup_v();
}
