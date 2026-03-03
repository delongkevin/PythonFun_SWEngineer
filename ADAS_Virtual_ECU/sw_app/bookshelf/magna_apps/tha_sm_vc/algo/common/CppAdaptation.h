/*
* File: CppAdaptation.h
* Author: jignesh.vasoya@magna.com
*/

#ifndef CPP_ADAPTION_H
#define CPP_ADAPTION_H

typedef unsigned char		  uint8_t;
typedef unsigned short		  uint16_t;
typedef unsigned int		  uint32_t;
//typedef unsigned long long    uint64_t; // PRQA S 48

typedef signed char           sint8_t;
typedef signed short          sint16_t;
typedef signed int            sint32_t;
//typedef signed long long      sint64_t; // PRQA S 47

typedef float                 float32_t;
typedef double                float64_t;

// typedef bool         bool_t;
/*==========================================================================*
* Generic type definitions for Point data									*
*===========================================================================*/

typedef struct
{
	sint32_t x;
	sint32_t y;
}Point2i_c;

typedef struct
{
	float32_t x;
	float32_t y;
}Point2f_c;

typedef struct
{
	float64_t x;
	float64_t y;
}Point2d_c;

typedef struct
{
	sint32_t x;
	sint32_t y;
	sint32_t z;
}Point3i_c;

typedef struct
{
	float32_t x;
	float32_t y;
	float32_t z;
}Point3f_c;

typedef struct
{
	float64_t x;
	float64_t y;
	float64_t z;
}Point3d_c;

typedef struct 
{
	sint32_t x;
	sint32_t y;
	sint32_t width;
	sint32_t height;
	
}Recti_c;

#endif // !CPP_ADAPTION_H


