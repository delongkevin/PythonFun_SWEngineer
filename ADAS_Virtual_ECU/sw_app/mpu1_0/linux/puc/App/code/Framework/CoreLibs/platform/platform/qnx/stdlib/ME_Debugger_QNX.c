
// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for QNX only
#ifdef ME_PLATFORM_QNX

#include <sys/slog2.h>
#include "platform/stdlib/ME_Debugger.h"

void ME_Debugger_F_BreakPoint_v(void)
{
  // gdb_breakpoint(); // TODO: find QNX function

  return;
}

#ifdef  USE_SLOG2_FOR_OUTPUT

/// @brief Global variable for accessing the slog2 handle
static slog2_buffer_t   bufferHandle_pv;

/// @brief  Register logging buffer
static void ME_Debugger_Register_Slog2(void)
{
    slog2_buffer_set_config_t   v_bufferConfig_t;
    
    v_bufferConfig_t.buffer_set_name = "puc-app";
    v_bufferConfig_t.num_buffers = 1;
    v_bufferConfig_t.verbosity_level = SLOG2_INFO;

    v_bufferConfig_t.buffer_config[0].buffer_name = "main";
    v_bufferConfig_t.buffer_config[0].num_pages = 8;

    // Register the buffer set
    if (-1 == slog2_register(&v_bufferConfig_t, &bufferHandle_pv, 0))
    {
        fprintf(stderr, "Error registering slogger2 buffer\n");
    }
}
#endif

void ME_Debugger_F_Printf_v(const char_t* i_Format_pc, ...)
{
  if(NULL != i_Format_pc)
  {
    va_list v_Arguments_pc;
    va_start(v_Arguments_pc, i_Format_pc);

    if(NULL != i_Format_pc)
    {
#ifdef USE_SLOG2_FOR_OUTPUT
            if (bufferHandle_pv == NULL)
            {
                ME_Debugger_Register_Slog2();
            }

            if (bufferHandle_pv != NULL)
            {
                (void)vslog2f(bufferHandle_pv, 0, SLOG2_INFO, i_Format_pc, v_Arguments_pc);
            }
            else
            {
                (void)vprintf(i_Format_pc, v_Arguments_pc);
            }
#else
            (void)vprintf(i_Format_pc, v_Arguments_pc);
#endif
    }

    va_end(v_Arguments_pc);
  }

  return;
}

void ME_Debugger_F_GetAverageCpuUsage_v(float32_t* b_Percentage_pf32)
{
  FILE* v_Output_po = popen("top -i 1 a | awk '/states/ {print$3}'", "r");
  char_t v_Result_ac[64] = { 0x0 };
  char_t* v_EndPtr_pc = NULL;

  if(NULL != v_Output_po)
  {
    while (fgets(v_Result_ac, sizeof(v_Result_ac), v_Output_po) != NULL )
    {
      if (NULL != b_Percentage_pf32)
      {
        *b_Percentage_pf32 = strtof(v_Result_ac, &v_EndPtr_pc);
      }
    }
    (void)pclose(v_Output_po);
  }
}

#endif // ME_PLATFORM_QNX
