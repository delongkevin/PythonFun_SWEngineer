/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

/*
 * PlatformAssert.c
 *
 *  Creation Date: 14.11.2017
 *         Author: Marcel Engelhardt
 *        Company: Magna Electronics
 */

/* include needed to check OS define */
#include "platform/PlatformSpecs.h"

/* compile this file for RTOS only */
#ifdef ME_PLATFORM_RTOS

/* #include <assert.h> */
#include "platform/stdlib/ME_Debugger.h"
#include "platform/stdlib/ME_Assert.h"

// --------------------------------------------------------------------------
/// @brief Test for null pointer
///
/// Function tests argument value \p i_Pointer_p against NULL
///
/// @param[in] i_Pointer_p Pointer to be tested
/// @return Boolean, True = null pointer, False = valid non-null pointer
// --------------------------------------------------------------------------
bool_t isNull_b (const void *i_Pointer_p)
{
  return i_Pointer_p == NULL;
}

// --------------------------------------------------------------------------
/// @brief Test for non-null pointer
///
/// Function tests argument value \p i_Pointer_p against NULL. Function
/// is accessed through the AssertNotNull() macro
///
/// @param[in] i_Pointer_p Pointer to be tested
/// @return Boolean, True = valid non-null pointer, False = null pointer
// --------------------------------------------------------------------------
bool_t isNotNull_b (const void *i_Pointer_p)
{
  return i_Pointer_p != NULL;
}

// --------------------------------------------------------------------------
/// @brief Assertion abstraction
///
/// Function implements call redirect to system specific assertion interface. Function
/// is never directly called but accessed through the AssertMsg() and Assert() macros
///
/// @param[in]  i_Message_pc  Assertion message text
/// @param[in]  i_File_pc     File name in which assertion failed
/// @param[in]  i_Line_i32    Line number in which assertion failed
/// @return     void
// --------------------------------------------------------------------------
void AssertExt_v(const char_t i_Message_pc[],
                 const char_t i_File_pc[],
                 const sint32_t i_Line_i32)
{
#ifdef ME_DEBUG
  ME_Debugger_F_BreakPoint_v();
#endif

  ME_Debugger_F_Printf_v("ASSERT FAILED %s - %s:%u\n", i_Message_pc, i_File_pc, i_Line_i32);
  abort(); /* not available on CR7 */
}

void noOperation_v(void)
{
  //asm("nop");
}

#endif // ME_PLATFORM_RTOS // PRQA S 862 // this define decides which platform is defined
