// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for Linux only
#ifdef ME_PLATFORM_LINUX

#include <stdarg.h>
#include <stdio.h> // PRQA S 5124 // standard library needed here, use of vprintf and vscan here

#include "platform/stdlib/ME_Debugger.h"

void ME_Debugger_F_BreakPoint_v(void)
{
  // gdb_breakpoint(); // TODO: find QNX function

  return;
}

void ME_Debugger_F_Printf_v(const char_t* i_Format_pc, ...)
{
  if(NULL != i_Format_pc)
  {
    va_list v_Arguments_pc;
    va_start(v_Arguments_pc, i_Format_pc);

    if(NULL != i_Format_pc)
    {
      (void)vprintf(i_Format_pc, v_Arguments_pc);
    }

    va_end(v_Arguments_pc);
  }

  return;
}

void ME_Debugger_F_GetAverageCpuUsage_v(float32_t* b_Percentage_pf32)
{
  (void*)b_Percentage_pf32;
}

#endif // ME_PLATFORM_LINUX // PRQA S 862 // this define decides which platform is defined
