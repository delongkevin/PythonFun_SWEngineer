// Compile this file for windows only
#include "platform/PlatformSpecs.h"
#ifdef ME_PLATFORM_WIN

#include "platform/stdlib/ME_Debugger.h"
#include "platform/win/WinInclude.h"
#include <stdio.h>


void ME_Debugger_F_BreakPoint_v(void)
{
  DebugBreak();
}

void ME_Debugger_F_Printf_v(const char_t* i_Format_pc, ...)
{
  va_list v_Arguments_pc;
  va_start(v_Arguments_pc, i_Format_pc);

  _vprintf_s_l(i_Format_pc, NULL, v_Arguments_pc);

  va_end(v_Arguments_pc);
}

void ME_Debugger_F_GetAverageCpuUsage_v(float32_t* b_Percentage_pf32)
{
  (void*)b_Percentage_pf32;
}

#endif // ME_PLATFORM_WIN // PRQA S 862 // this define decides which platform is defined
