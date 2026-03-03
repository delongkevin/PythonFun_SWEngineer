/*
 * US_ME_Typedefs_Global.h
 */

#ifndef USS_TYPESDEF_GLOBAL_H
#define USS_TYPESDEF_GLOBAL_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h> 
#include "PlatformDataTypes.h"
	
 
/*typedef unsigned char           bool_t;*/
typedef volatile unsigned char  vbool_t;
typedef signed char 			sint8_t;
typedef volatile signed char 	vsint8_t;
typedef volatile unsigned char 	vuint8_t;
typedef char                  char_t;
typedef signed short 			sint16_t;
typedef volatile signed short 	vsint16_t;
typedef volatile unsigned short vuint16_t;

typedef signed int 				sint32_t;
typedef volatile signed int 	vsint32_t;
typedef volatile unsigned int 	vuint32_t;

typedef signed long long        sint64_t;


typedef float                   float32_t;
typedef double                  double64_t;
typedef double                  float64_t;

#ifndef uint8_t
//typedef unsigned char 			uint8_t;
#endif

#ifndef uint16_t
//typedef unsigned short 			uint16_t;
#endif

#ifndef uint32_t
//typedef unsigned int 			uint32_t;
#endif

#ifndef uint64_t
//typedef unsigned long long		uint64_t;
#endif
//KPK this is temp arrange for enabling the Play-back code

typedef uint8_t Std_ReturnType;


#define EXTERN     extern
#define ZERO         (0U)
#define ONE          (1U)
#define TWO          (2U)
#define THREE        (3U)
#define FOUR         (4U)
#define FIVE         (5U)
#define SIX          (6U)
#define SEVEN        (7U)
#define EIGHT        (8U)
#define NINE         (9U)
#define TEN          (10U)
#define ELEVEN       (11U)
#define TWELVE       (12U)
#define THIRTEEN     (13U)
#define FOURTEEN     (14U)
#define FIFTEEN      (15U)
#define SIXTEEN      (16U)
#define SEVENTEEN    (17U)
#define EIGHTEEN     (18U)
#define NINETEEN     (19U)
#define TWENTY       (20U)
#define TWENTY_ONE   (21U)
#define TWENTY_TWO   (22U)
#define TWENTY_THREE (23U)
#define TWENTY_FOUR  (24U)
#define TWENTY_FIVE  (25U)
#define TWENTY_SIX   (26U)
#define TWENTY_SEVEN (27U)
#define TWENTY_EIGHT (28U)
#define TWENTY_NINE  (29U)

#define BIT0       (0x01U)
#define BIT1       (0x02U)
#define BIT2       (0x04U)
#define BIT3       (0x08U)
#define BIT4       (0x10U)
#define BIT5       (0x20U)
#define BIT6       (0x40U)
#define BIT7       (0x80U)
#define BIT8       (0x100U)
#define BIT9       (0x200U)
#define BIT10      (0x400U)
#define BIT11      (0x800U)
#define BIT12      (0x1000U)
#define BIT13      (0x2000U)
#define BIT14      (0x4000U)
#define BIT15      (0x8000U)

#define USS_U8_MAX  (0xFFU)
#define USS_U16_MAX (0xFFFFU)
#define USS_U32_MAX (0xFFFFFFFFU)

#ifndef ME_OK
    #define ME_OK      ZERO
    #define ME_NOT_OK      1
#endif
#define ME_OFF  (0u)
#define ME_ON   (1u)

#ifndef QM_SNR_FW_VER
  #define QM_SNR_FW_VER    (0xF11AU)
#endif
#ifndef SENSOR_OP_MODE
#define SENSOR_OP_NORMAL   (1U)
#define SENSOR_OP_MFG      (3U)
#define SENSOR_OP_SWRESET  (127U)
#endif

#ifndef ME_ERROR
     #define ME_ERROR    (0xFFFFU)
#endif

#ifndef ME_FALSE
	#define ME_FALSE     (0U)
	#define ME_TRUE      (1U)
#endif
#ifndef NULL
#define NULL ((void*)0)
#endif

/* Useful math */
#define US_IDX_TO_BIT_LOC(IDX) ((uint32_t)BIT0 << (IDX))
#ifndef M_PI
  #define M_PI    ((float32_t) 3.14159265358979323846f)
#endif

#ifndef M_2PI
#define M_2PI     ((float32_t) 3.14159265358979323846f * 2.0f)
#endif

#ifndef M_PI_2
  #define M_PI_2  ((float32_t) 1.57079632679489661923f)
#endif

#define US_DEG2RAD(DEG) (float32_t)(((DEG) * (float32_t) M_PI) / 180.0f)
#define US_RAD2DEG(RAD) (float32_t)(((RAD) * 180.0f) / (float32_t) M_PI)
#define US_D_MM_TO_CM(X) (float32_t)((X) / 10.0f)
#endif /* USS_TYPESDEF_H */
