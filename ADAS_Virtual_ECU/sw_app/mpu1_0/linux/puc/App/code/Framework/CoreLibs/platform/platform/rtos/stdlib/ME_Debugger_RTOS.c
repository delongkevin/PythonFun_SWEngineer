/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

/* include needed to check OS define */
#include "platform/PlatformSpecs.h"

/* compile this file for AUTOSAR only */
#ifdef ME_PLATFORM_RTOS

#include <stdarg.h>
#include <stdio.h> /* PRQA S 5124 */ /*standard library needed here, use of vprintf and vscan here*/

#include "platform/stdlib/ME_Debugger.h"

void ME_Debugger_F_BreakPoint_v(void)
{
  return;
}

void ME_Debugger_F_Printf_v(const char_t* i_Format_pc, ...)
{
  if(NULL != i_Format_pc)
  {
    va_list v_Arguments_pc; /* Type to hold information about variable arguments */ /* PRQA S 3196 */
    (void)va_start(v_Arguments_pc, i_Format_pc); /* Initialize a variable argument list */ /* PRQA S 3335 */

    if(NULL != i_Format_pc)
    {
      (void)vprintf(i_Format_pc, v_Arguments_pc);
    }

    (void)va_end(v_Arguments_pc); /* Performs the appropriate actions to facilitate a normal return */ /* PRQA S 3335 */
  }

  return;
}

void ME_Debugger_F_GetAverageCpuUsage_v(float32_t* b_Percentage_pf32)
{
  if(NULL != b_Percentage_pf32)
  {
    *b_Percentage_pf32 = 36.7f;
  }
}

#endif /* ME_PLATFORM_RTOS */ /* PRQA S 862 */ /* this define decides which platform is defined */
