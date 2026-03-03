/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

/*
 * PlatformAssert.h
 *
 *  Creation Date: 14.11.2017
 *         Author: Marcel Engelhardt
 *        Company: Magna Electronics
 */

#ifndef ME_ASSERT_H
#define ME_ASSERT_H

#include "platform/PlatformSpecs.h"
#include "platform/stdlib/StdLibTypes.h"
#include "platform/stdlib/ME_Debugger.h"

// PRQA S 3412 EOF // unrecognized code fragments used here by design
// PRQA S 1020 EOF // macros needed here for Assert function

#if defined(__cplusplus)
extern "C"
{
#endif

// --------------------------------------------------------------------------
/// Executes assembler instruction \code nop \endcode.
// --------------------------------------------------------------------------
void noOperation_v(void);

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
                 const sint32_t i_Line_i32);


// --------------------------------------------------------------------------
/// @brief Test for null pointer.
///
/// Function tests argument value \p i_Pointer_p against NULL
///
/// @param[in] i_Pointer_p Pointer to be tested
/// @return Boolean, True = null pointer, False = valid non-null pointer
// --------------------------------------------------------------------------
bool_t isNull_b (const void *i_Pointer_p);

// --------------------------------------------------------------------------
/// @brief Test for non-null pointer
///
/// Function tests argument value \p i_Pointer_p against NULL. Function
/// is accessed through the AssertNotNull() macro
///
/// @param[in] i_Pointer_p Pointer to be tested
/// @return Boolean, True = valid non-null pointer, False = null pointer
// --------------------------------------------------------------------------
bool_t isNotNull_b (const void *i_Pointer_p);
#if defined(__cplusplus)
}; // extern C
#endif

// static assert only available for c++
#if defined(__cplusplus)
  // --------------------------------------------------------------------------
  /// Default template for static asserts.
  ///
  /// Here the initialization works. There is no compile error when the checked condition in template argument is true.
  // --------------------------------------------------------------------------
  template<bool_t b>
  struct StaticAssertTemplate // PRQA S 2400 // global scope, this is a shared c and cpp header file
  {
    static void assertSuccess() {}
  };

  // --------------------------------------------------------------------------
  /// Template specialized on false that does not contain an implementation.
  ///
  /// This yields a compile error if the template argument (i.e. the checked condition) is false.
  // --------------------------------------------------------------------------
  template<>
  struct StaticAssertTemplate<false>; // PRQA S 2400 // global scope, this is a shared c and cpp header file
#endif

// Examples in the comments should be OK
// PRQA S 1051 EOF
// The "stringify" # operator is used here to generate output according to the condition that was checked.
// This is used for debug purposes and makes usage of # necessary
// PRQA S 1038 4 // suppress stringify message for the next 4 lines


// --------------------------------------------------------------------------
/// @brief Assertion macro
///
/// Asserts that a condition is true. If the condition is false the system may be halted. Function calls assertion abstraction.
// --------------------------------------------------------------------------
#ifndef Assert
// PRQA S 1038,341 1 // stringify used for convenience/better error output in Assert macro
#define Assert(condition) ((condition) ? noOperation_v() : AssertExt_v(#condition, __FILE__, __LINE__))
#endif

// --------------------------------------------------------------------------
/// Assertion macro with output message
// --------------------------------------------------------------------------
#ifndef AssertMsg
// PRQA S 1030 1 // Macro defined with variable argument list. We have modern compilers, so this is pretty neat, isn't it?
#define AssertMsg(condition,...) \
    if (!(condition)) { \
        ME_Debugger_F_Printf_v(__VA_ARGS__); \
   } \
   Assert(condition) 
  // enforce semicolon
#endif

// --------------------------------------------------------------------------
/// Assertion macro with function signature and output message
// --------------------------------------------------------------------------
// PRQA S 1598 5 //__PRETTY_FUNCTION__ is defined for all platforms
#ifndef AssertFunction
// PRQA S 1030 1 // Macro defined with variable argument list. We have modern compilers, so this is pretty neat, isn't it?
#define AssertFunction(condition, ...) \
    if (!(condition)) { \
        ME_Debugger_F_Printf_v("%s: ", ME_PRETTY_FUNCTION); \
        ME_Debugger_F_Printf_v(__VA_ARGS__); \
    } \
    Assert(condition)
#endif

// --------------------------------------------------------------------------
/// Asserts that a pointer is not null.
// --------------------------------------------------------------------------
// PRQA S 3453 1 //  Convenience macro. Provides easier usage
#define AssertNotNull(pointer) Assert(isNotNull_b(pointer))

// --------------------------------------------------------------------------
/// @brief Compile-time assert.
///
/// This can be used to check constant values or sizes against specific bounds.
/// use like:
///
/// @code{cpp}
/// StaticAssert(Size > 0, "Size must not be 0");
/// @endcode
///
/// All used values have to be known at compile time (constant expression)
/// the default template has no body
/// - hence object instantiation does not work
// --------------------------------------------------------------------------
#define StaticAssert(condition, text) \
    StaticAssertTemplate<(condition)>::assertSuccess();



#endif /* ME_ASSERT_H */
