//--------------------------------------------------------------------------
/// @file MeclTypes.h
/// @brief Contains the global type definitions for simple types.
///
/// The types defined in this file shall be used for the primitive types
/// instead of using plain int, float or bool_t types.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Michael Schulte (michael.schulte@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef MECLTYPES_H_
#define MECLTYPES_H_

#include <platform/PlatformAPI.h>

// PRQA S 2400 EOF // global scope, this is a header file

typedef enum { e_Degrees = 0, e_Radians } AngleUnit_e;

typedef enum { e_RowMajor = 0, e_ColumnMajor } MatrixOrder_e;

typedef enum { e_Default,
               e_UpperTriangle,
               e_LowerTriangle,
               e_Symmetric,
               e_AntiSymmetric,
               e_Sparse
             } MatrixType_e;

typedef enum { e_Standard = 0,  // Matrix standard output format
               e_Octave,        // Octave/Matlab readable output, take comment as lhs operand of assignment
               e_CStruct        // Expression for initializing a Matrix<T>::Config_s POD instance
             } MatrixOutputFormatStyle_e;


//! @struct MatrixOutputFormat_s
//! @brief Datastructure for defining output format of matrix print
typedef struct
{
  char_t headingChars[256];         ///< Characters to print before content
  char_t rowSeperatorChars[16];     ///< Characters to print between rows
  char_t columnSeperatorChars[16];  ///< Characters to print between columns
  char_t trailingChars[256];        ///< Characters to print after contents
} MatrixOutputFormat_s;

#endif // MECLTYPES_H_
