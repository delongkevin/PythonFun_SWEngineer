#ifndef PLATFORMDATATYPES_H_INCGUARD
#define PLATFORMDATATYPES_H_INCGUARD


//basic definitions are provided in the compiler specific file 
#include "stdint.h" 
#include "stdbool.h"

typedef signed char  	char_T;

typedef signed char  	sint8_t;


typedef signed short 	sint16_t;
typedef float 			float32_t;
typedef double 			float64_t; // For Auto Park

typedef signed int   	sint32_t;

#if !defined(BUILD_MCUQNX) 
typedef signed long long   	sint64_t;
#endif

#if defined(BUILD_MCUQNX)
typedef double double_t;
#endif

typedef uint8_t  		uint8_T;

typedef sint8_t  		sint8_T;
typedef sint8_T			int8_T;  //for rtwtypes.h


typedef uint16_t 		uint16_T;

typedef sint16_t 		sint16_T;
typedef sint16_t		int16_T;  //for rtwtypes.h



typedef float32_t 		real32_T;
typedef double real_T;   //for rtwtypes.h

#define MAGNA_PLATFORMDATATYPES_bool_t_DEFINED

#if !defined(BUILD_MCU1_0)
typedef bool  		bool_t;
#endif

typedef uint32_t 		uint32_T;

typedef sint32_t 		sint32_T;
typedef sint32_t 		int_T;   //for rtwtypes.h


#ifndef FALSE
    #define FALSE	0
#endif

#ifndef TRUE
    #define TRUE    1
#endif


#ifndef RTE_APPLICATION_HEADER_FILE

    // This file is not included in the context of the Autosar Application :
    // Define datatypes causing exclusive to non autosar system
    typedef uint8_t  		uint8; 
    typedef sint8_t  		sint8;
    typedef uint16_t 		uint16;
    typedef sint16_t 		sint16;
    typedef float32_t 		float32;
    typedef uint8_t			boolean;
    typedef uint8_t			boolean_T;
#ifndef __SINT_UINT_32__
#define __SINT_UINT_32__
    typedef uint32_t 		uint32;
    typedef sint32_t 		sint32;
#endif//__SINT_UINT_32__
    typedef uint64_t 		uint64;
 #if !defined(BUILD_MCUQNX) 
    typedef sint64_t 		sint64;
#endif	
	typedef sint16_t		int16;


    /* Some Autosar Common Definitions without including the full path */
    # define E_OK      0u
    # define E_NOT_OK  1u
    typedef uint8 Std_ReturnType;    
    typedef void * dtRef_VOID;
    typedef uint16_t UINT16;
    typedef uint8_t BOOL;

#else

#endif


#endif //PLATFORMDATATYPES_H_INCGUARD
