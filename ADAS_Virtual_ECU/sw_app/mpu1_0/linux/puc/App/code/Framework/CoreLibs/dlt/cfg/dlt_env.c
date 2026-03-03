/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:   DltEnv
 * DESIGN:  <tbd>
 * DESCRIPTION:
 *    Configuration and interface functions for Dlt
 * ======================================================================== */

/* --- Defines, Includes ----------------------------------------------------------- */
#include "dlt_env.h"
#include <string.h>


/* --- Private Typedefinitions, Enumerations, Defines ------------------------------ */

/* --- Extern Declarations --------------------------------------------------------- */

/* --- Private Function Declarations ----------------------------------------------- */

/* --- Private Function Definitions ------------------------------------------------ */

/* --- Public Function Definitions ------------------------------------------------- */
void sDltEnv_Memset_v(void* i_Dest_pv, s16 i_Value_u8, u16 i_Size_u16)
{
  if(i_Dest_pv != NULL)
  {
   (void)memset(i_Dest_pv, i_Value_u8, i_Size_u16);
  }
}

u16 sDltEnv_Strlen_u16(const char_t* i_Name_pc)
{
  u16 v_RetVal_u16 = 0;

  if(i_Name_pc != NULL)
  {
    v_RetVal_u16 = (u16)strlen(i_Name_pc);
  }

  return v_RetVal_u16;
}

void sDltEnv_MemCpy_v(void* i_Dest_pv, const void* i_Src_pv, u16 i_Size_u16)
{
  if((i_Dest_pv != NULL) && (i_Src_pv != NULL))
  {
    (void)memcpy(i_Dest_pv, i_Src_pv, i_Size_u16);
  }
}

/* --------------------------------------------------------------------------------- */
/* END OF FILE: dlt_env.c */
