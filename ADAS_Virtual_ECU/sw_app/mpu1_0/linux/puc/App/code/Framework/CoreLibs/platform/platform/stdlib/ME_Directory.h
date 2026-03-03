/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

//--------------------------------------------------------------------------
/// @file ME_Directory.h
/// @brief Contains the interface to platform specific directory and path control functions
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------


#ifndef ME_DIRECTORY_H
#define ME_DIRECTORY_H

#include "platform/PlatformSpecs.h"
#include "platform/stdlib/StdLibTypes.h"

#if defined(__cplusplus)
extern "C"
{
#endif

// --------------------------------------------------------------------------
/// Checks the directory path passed in on representing an absolute path.
///
/// @param[i] i_Path_pc    The path string to be checked
/// @param[i] i_Length_u32 Length of the path string to be checked
/// @return \c true if the check passes, \c false otherwise
// --------------------------------------------------------------------------
bool_t ME_Directory_IsAbsolutePath_b(const char_t* i_Path_pc, uint32_t i_Length_u32);

// --------------------------------------------------------------------------
/// Checks the directory path passed in on representing a relative path.
///
/// @param[i] i_Path_pc    The directory path string to be checked
/// @param[i] i_Length_u32 Length of the directory path string to be checked
/// @return   \c true if the check passes, \c false otherwise
// --------------------------------------------------------------------------
bool_t ME_Directory_IsRelativePath_b(const char_t* i_Path_pc, uint32_t i_Length_u32);

// --------------------------------------------------------------------------
/// Creates the directory path passed in.
///
/// @param[i] i_Path_pc The directory path string to be checked
/// @return   \c true if the operation succeeds, \c false otherwise
// --------------------------------------------------------------------------
bool_t ME_Directory_Create_b(const char_t* i_Path_pc);

// --------------------------------------------------------------------------
/// Deletes the directory path passed in.
///
/// @param[i] i_Path_pc The directory path string to be checked
/// @return   \c true if the operation succeeds, \c false otherwise
// --------------------------------------------------------------------------
bool_t ME_Directory_Delete_b(const char_t* i_Path_pc);

// --------------------------------------------------------------------------
/// Check the directory path passed in on existence.
///
/// @param[i] i_Path_pc The directory path string to be checked
/// @return   \c true if the check passes, \c false otherwise
// --------------------------------------------------------------------------
bool_t ME_Directory_Exists_b(const char_t* i_Path_pc);

// --------------------------------------------------------------------------
/// Returns the current directory.
///
/// @param[i] i_BufferLen_u32 Length of the character buffer current directory has to be stored to
/// @param[i] o_CurrentDir_pc The character buffer current directory has to be stored to
/// @return   \c true if the operation succeeds, \c false otherwise
// --------------------------------------------------------------------------
bool_t ME_Directory_GetCurrentDir_b(uint32_t i_BufferLen_u32, char_t* o_CurrentDir_pc);


#if defined(__cplusplus)
}; // extern C
#endif

#endif // ME_DIRECTORY_H
