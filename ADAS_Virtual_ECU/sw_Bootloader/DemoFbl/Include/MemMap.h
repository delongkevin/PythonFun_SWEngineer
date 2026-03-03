/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        MemMap section definition to locate (link) data or code in memory
 *  \details      This file contains compiler specific section definition for every segment that can be mapped
 *                within the Flash Bootloader to a specific location.
 *
 *  \note
 *                Please note, that this file contains a collection of definitions to be used with the Flash Bootloader.
 *                This code may influence the behavior of the Bootloader in principle. Therefore, great care
 *                must be taken to verify the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples resp. implementation proposals.
 *                With regard to the fact that these definitions are meant for demonstration purposes only,
 *                Vector Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the
 *                extent admissible by law or statute.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  THIS IS A GENERATED FILE
 *  Generator version : 01.10.01
 *********************************************************************************************************************/

/* PRQA S 0841 EOF */ /* MD_MSR_Undef */
/* PRQA S 0883 EOF */ /* MD_MemMap_0883 */
/* PRQA S 3116 EOF */ /* MD_MSR_Pragma */

#define FBL_MEMMAP_ERROR

#if defined( ADC_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_CONFIG_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_CONFIG_DATA
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_CONFIG_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_CONFIG_DATA
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_ISR_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_ISR_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_ISR_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_ISR_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_VAR_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_VAR_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_VAR_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_VAR_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CONST_FAST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_CONST_FAST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CONST_FAST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_CONST_FAST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CONST_FAST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_CONST_FAST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CONST_FAST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_CONST_FAST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CONST_FAST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_CONST_FAST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CONST_FAST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_CONST_FAST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CONST_FAST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_CONST_FAST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CONST_FAST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_CONST_FAST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_START_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_STOP_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_START_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_STOP_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_CODE_ISR )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_CODE_ISR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_CODE_ISR )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CODE_ISR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_CONST_FAST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_CONST_FAST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_CONST_FAST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CONST_FAST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_CONST_FAST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_CONST_FAST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_CONST_FAST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CONST_FAST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_CONST_FAST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_CONST_FAST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_CONST_FAST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CONST_FAST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_CONST_FAST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_CONST_FAST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_CONST_FAST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CONST_FAST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_GENERICCAN_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_GENERICCAN_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_CODE_ISR )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_CODE_ISR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_CODE_ISR )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_CODE_ISR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_CONST_FAST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_CONST_FAST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_CONST_FAST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_CONST_FAST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_CONST_FAST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_CONST_FAST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_CONST_FAST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_CONST_FAST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_30_MCAN_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_30_MCAN_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_30_MCAN_START_SEC_CODE_APPL )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_START_SEC_CODE_APPL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_30_MCAN_STOP_SEC_CODE_APPL )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_STOP_SEC_CODE_APPL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_30_MCAN_START_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_30_MCAN_STOP_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_30_MCAN_START_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_30_MCAN_STOP_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_30_MCAN_START_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_30_MCAN_STOP_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_30_MCAN_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_30_MCAN_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_30_MCAN_START_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_START_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_30_MCAN_STOP_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_STOP_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_30_MCAN_START_SEC_STATIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_START_SEC_STATIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_30_MCAN_STOP_SEC_STATIC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_STOP_SEC_STATIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_30_MCAN_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_30_MCAN_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_30_MCAN_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_30_MCAN_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_30_MCAN_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_30_MCAN_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_30_MCAN_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_30_MCAN_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_30_MCAN_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_30_MCAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_30_MCAN_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_30_MCAN_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_30_MCAN_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_CONFIG_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_START_SEC_CONFIG_DATA
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_CONFIG_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_STOP_SEC_CONFIG_DATA
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_CONST_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_START_SEC_CONST_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_CONST_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_STOP_SEC_CONST_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_ISR_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_START_SEC_ISR_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_ISR_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_STOP_SEC_ISR_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_VAR_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_START_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_VAR_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_STOP_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CDD_IPC_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CDD_IPC_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CDD_IPC_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CDD_IPC_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CDD_IPC_START_SEC_CONFIG_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef CDD_IPC_START_SEC_CONFIG_DATA
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CDD_IPC_STOP_SEC_CONFIG_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef CDD_IPC_STOP_SEC_CONFIG_DATA
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CDD_IPC_START_SEC_ISR_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CDD_IPC_START_SEC_ISR_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CDD_IPC_STOP_SEC_ISR_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CDD_IPC_STOP_SEC_ISR_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CDD_IPC_START_SEC_VAR_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef CDD_IPC_START_SEC_VAR_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CDD_IPC_STOP_SEC_VAR_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef CDD_IPC_STOP_SEC_VAR_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CDD_IPC_START_SEC_VAR_NO_INIT_8_ALIGN_8B )
   /* #pragma <enter your compiler specific pragma> */
# undef CDD_IPC_START_SEC_VAR_NO_INIT_8_ALIGN_8B
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CDD_IPC_STOP_SEC_VAR_NO_INIT_8_ALIGN_8B )
   /* #pragma <enter your compiler specific pragma> */
# undef CDD_IPC_STOP_SEC_VAR_NO_INIT_8_ALIGN_8B
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CDD_IPC_START_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CDD_IPC_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CDD_IPC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CDD_IPC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( COMM_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef COMM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( COMM_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef COMM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYIF_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYIF_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYIF_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYIF_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYIF_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYIF_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYIF_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYIF_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYIF_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYIF_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYIF_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYIF_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_LIBCV_START_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_LIBCV_STOP_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_LIBCV_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_LIBCV_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_LIBCV_START_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_LIBCV_STOP_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_LIBCV_START_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_LIBCV_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_LIBCV_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_CODE_ISR )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_START_SEC_CODE_ISR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_CODE_ISR )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_STOP_SEC_CODE_ISR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT )

  /* Move section to global RAM on platforms which need this. */
# if defined(__ghs__) && (defined(__CORE_CORTEXM4__) || defined(__CORE_CORTEXM4F__) || defined(__CORE_CORTEXM7__)) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmGlobalRamBuffer"
# elif defined(__ghs__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmGlobalRamBuffer"
#  pragma ghs section sbss=".svHsmGlobalRamBuffer"
# elif defined(__TASKING__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section all "vHsmGlobalRamBuffer"
# elif defined(_GNU_C_TRICORE_) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section ".vHsmGlobalRamBuffer" aw 4
# elif defined(_MSC_VER) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma data_seg(".vHsmGlobalRamBuffer") /* PRQA S 3116 */ /* MD_MSR_Pragma */
#  pragma bss_seg(".vHsmGlobalRamBuffer") /* PRQA S 3116 */ /* MD_MSR_Pragma */
# elif defined(__arm__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma clang section bss = "vHsmGlobalRamBuffer"
# endif
# undef CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT )

  /* Move section to global RAM on platforms which need this. */
# if defined(__ghs__) && (defined(__CORE_CORTEXM4__) || defined(__CORE_CORTEXM4F__) || defined(__CORE_CORTEXM7__)) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
# elif defined(__ghs__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
#  pragma ghs section sbss=default
# elif defined(__TASKING__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section all restore
# elif defined(_GNU_C_TRICORE_) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section
# elif defined(_MSC_VER) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma data_seg() /* PRQA S 3116 */ /* MD_MSR_Pragma */
#  pragma bss_seg() /* PRQA S 3116 */ /* MD_MSR_Pragma */
# elif defined(__arm__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma clang section bss = ""
# endif
# undef CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_64BIT )

  /* Move section to global RAM on platforms which need this. */
# if defined(__ghs__) && (defined(__CORE_CORTEXM4__) || defined(__CORE_CORTEXM4F__) || defined(__CORE_CORTEXM7__)) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmGlobalRamBuffer"
# elif defined(__ghs__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmGlobalRamBuffer"
#  pragma ghs section sbss=".svHsmGlobalRamBuffer"
# elif defined(__TASKING__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section all "vHsmGlobalRamBuffer"
# elif defined(_GNU_C_TRICORE_) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section ".vHsmGlobalRamBuffer" aw 4
# elif defined(_MSC_VER) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma data_seg(".vHsmGlobalRamBuffer") /* PRQA S 3116 */ /* MD_MSR_Pragma */
#  pragma bss_seg(".vHsmGlobalRamBuffer") /* PRQA S 3116 */ /* MD_MSR_Pragma */
# elif defined(__arm__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma clang section bss = "vHsmGlobalRamBuffer"
# endif
# undef CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_64BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_64BIT )

  /* Move section to global RAM on platforms which need this. */
# if defined(__ghs__) && (defined(__CORE_CORTEXM4__) || defined(__CORE_CORTEXM4F__) || defined(__CORE_CORTEXM7__)) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
# elif defined(__ghs__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
#  pragma ghs section sbss=default
# elif defined(__TASKING__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section all restore
# elif defined(_GNU_C_TRICORE_) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section
# elif defined(_MSC_VER) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma data_seg() /* PRQA S 3116 */ /* MD_MSR_Pragma */
#  pragma bss_seg() /* PRQA S 3116 */ /* MD_MSR_Pragma */
# elif defined(__arm__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma clang section bss = ""
# endif
# undef CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_64BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED )

  /* Move section to global RAM on platforms which need this. */
# if defined(__ghs__) && (defined(__CORE_CORTEXM4__) || defined(__CORE_CORTEXM4F__) || defined(__CORE_CORTEXM7__)) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmGlobalRamBuffer"
# elif defined(__ghs__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmGlobalRamBuffer"
#  pragma ghs section sbss=".svHsmGlobalRamBuffer"
# elif defined(__TASKING__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section all "vHsmGlobalRamBuffer"
# elif defined(_GNU_C_TRICORE_) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section ".vHsmGlobalRamBuffer" aw 4
# elif defined(_MSC_VER) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma data_seg(".vHsmGlobalRamBuffer") /* PRQA S 3116 */ /* MD_MSR_Pragma */
#  pragma bss_seg(".vHsmGlobalRamBuffer") /* PRQA S 3116 */ /* MD_MSR_Pragma */
# elif defined(__arm__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma clang section bss = "vHsmGlobalRamBuffer"
# endif
# undef CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED )

  /* Move section to global RAM on platforms which need this. */
# if defined(__ghs__) && (defined(__CORE_CORTEXM4__) || defined(__CORE_CORTEXM4F__) || defined(__CORE_CORTEXM7__)) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
# elif defined(__ghs__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
#  pragma ghs section sbss=default
# elif defined(__TASKING__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section all restore
# elif defined(_GNU_C_TRICORE_) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section
# elif defined(_MSC_VER) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma data_seg() /* PRQA S 3116 */ /* MD_MSR_Pragma */
#  pragma bss_seg() /* PRQA S 3116 */ /* MD_MSR_Pragma */
# elif defined(__arm__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma clang section bss = ""
# endif
# undef CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_IPC_MEMORY_VAR_NOINIT_32BIT )

  /* Move section to the same memory which is used by the vHsm as IPC memory */
# if defined(__DCC__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section VHSMIPCMEMORY ".bss" ".vHsmIpcMemory" far-absolute
#  if defined( VHSMIPCMEMORY_USESECTION ) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  else
#   pragma use_section VHSMIPCMEMORY Crypto_30_vHsm_Ipc_Memory
#  endif
# endif
# if defined(__ghs__) && (defined(__CORE_CORTEXM4__) || defined(__CORE_CORTEXM4F__) || defined(__CORE_CORTEXM7__)) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmIpcMemory"
# elif defined(__ghs__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmIpcMemory"
#  pragma ghs section sbss=".svHsmIpcMemory"
# elif defined(__TASKING__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section all "vHsmIpcMemory"
# elif defined(_GNU_C_TRICORE_) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section ".vHsmIpcMemory" aw 4
# elif defined(_MSC_VER) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma data_seg(".vHsmIpcMemory") /* PRQA S 3116 */ /* MD_MSR_Pragma */
#  pragma bss_seg(".vHsmIpcMemory") /* PRQA S 3116 */ /* MD_MSR_Pragma */
# elif defined(__arm__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma clang section bss = "vHsmIpcMemory"
# endif
# undef CRYPTO_30_VHSM_START_SEC_IPC_MEMORY_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_IPC_MEMORY_VAR_NOINIT_32BIT )

  /* Move section to the same memory which is used by the vHsm as IPC memory */
# if defined(__DCC__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section BSS
# endif
# if defined(__ghs__) && (defined(__CORE_CORTEXM4__) || defined(__CORE_CORTEXM4F__) || defined(__CORE_CORTEXM7__)) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
# elif defined(__ghs__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
#  pragma ghs section sbss=default
# elif defined(__TASKING__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section all restore
# elif defined(_GNU_C_TRICORE_) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section
# elif defined(_MSC_VER) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma data_seg() /* PRQA S 3116 */ /* MD_MSR_Pragma */
#  pragma bss_seg() /* PRQA S 3116 */ /* MD_MSR_Pragma */
# elif defined(__arm__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma clang section bss = ""
# endif
# undef CRYPTO_30_VHSM_STOP_SEC_IPC_MEMORY_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_RAMCODE )

  /* Move section to RAM on platforms which need this. */
# if defined(__ghs__) && defined (__RH850__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section text=".vHsmRamCode"
# endif
# undef CRYPTO_30_VHSM_START_SEC_RAMCODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_RAMCODE )

  /* Move section to RAM on platforms which need this. */
# if defined(__ghs__) && defined (__RH850__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section text=default
# endif
# undef CRYPTO_30_VHSM_STOP_SEC_RAMCODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CSM_START_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CSM_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CSM_STOP_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CSM_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CSM_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CSM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CSM_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CSM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CSM_START_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CSM_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CSM_STOP_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CSM_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CSM_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CSM_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CSM_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CSM_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CSM_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CSM_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CSM_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CSM_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CSM_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CSM_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CSM_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CSM_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CSM_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CSM_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CSM_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DEM_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef DEM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DEM_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef DEM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DEM_START_SEC_VAR_CLEARED_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DEM_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DEM_STOP_SEC_VAR_CLEARED_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DEM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DET_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef DET_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DET_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef DET_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DET_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DET_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DET_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DET_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DET_START_SEC_VAR_CLEARED_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DET_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DET_STOP_SEC_VAR_CLEARED_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DET_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DET_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DET_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DET_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DET_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DET_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DET_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DET_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DET_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DET_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DET_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DIO_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DIO_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DIO_START_SEC_CONFIG_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_START_SEC_CONFIG_DATA
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DIO_STOP_SEC_CONFIG_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_STOP_SEC_CONFIG_DATA
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DIO_START_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_START_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DIO_STOP_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_STOP_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DIO_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DIO_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( EA_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef EA_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( EA_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef EA_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( EA_START_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef EA_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( EA_STOP_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef EA_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( EA_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef EA_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( EA_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef EA_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( EA_START_SEC_VAR_FAST_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef EA_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( EA_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef EA_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( EA_START_SEC_VAR_NOINIT_INTERNAL_READ_BUFFER )
/* Non-standard MemMap section for internal read buffer, which will be forwarded to the EEPROM driver.
 * Depending on restrictions, this buffer might have to be aligned to prevent unaligned memory access exceptions. */
# undef EA_START_SEC_VAR_NOINIT_INTERNAL_READ_BUFFER
# undef FBL_MEMMAP_ERROR
#endif

#if defined( EA_STOP_SEC_VAR_NOINIT_INTERNAL_READ_BUFFER )
   /* #pragma <enter your compiler specific pragma> */
# undef EA_STOP_SEC_VAR_NOINIT_INTERNAL_READ_BUFFER
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( EA_START_SEC_VAR_NOINIT_INTERNAL_WRITE_BUFFER )
/* Non-standard MemMap section for internal write buffer, which will be forwarded to the EEPROM driver.
 * Depending on restrictions, this buffer might have to be aligned to prevent unaligned memory access exceptions. */
# undef EA_START_SEC_VAR_NOINIT_INTERNAL_WRITE_BUFFER
# undef FBL_MEMMAP_ERROR
#endif

#if defined( EA_STOP_SEC_VAR_NOINIT_INTERNAL_WRITE_BUFFER )
   /* #pragma <enter your compiler specific pragma> */
# undef EA_STOP_SEC_VAR_NOINIT_INTERNAL_WRITE_BUFFER
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( EA_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef EA_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( EA_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef EA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ECUM_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ECUM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ECUM_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ECUM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ECUM_START_SEC_VAR_CLEARED_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ECUM_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ECUM_STOP_SEC_VAR_CLEARED_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ECUM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( EEPDUMMY_FULL_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef EEPDUMMY_FULL_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( EEPDUMMY_FULL_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef EEPDUMMY_FULL_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( EEPDUMMY_START_SEC_VAR )
__attribute__ ((section (".EepDummySection")))

# undef EEPDUMMY_START_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( EEPDUMMY_STOP_SEC_VAR )

# undef EEPDUMMY_STOP_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( EEP_30_HISEEPROM_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef EEP_30_HISEEPROM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( EEP_30_HISEEPROM_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef EEP_30_HISEEPROM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( EEP_30_XXI2C01_INST2_START_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef EEP_30_XXI2C01_INST2_START_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( EEP_30_XXI2C01_INST2_STOP_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef EEP_30_XXI2C01_INST2_STOP_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( EEP_30_XXI2C01_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef EEP_30_XXI2C01_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( EEP_30_XXI2C01_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef EEP_30_XXI2C01_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( EEP_30_XXI2C01_START_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef EEP_30_XXI2C01_START_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( EEP_30_XXI2C01_STOP_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef EEP_30_XXI2C01_STOP_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( EEP_30_XXI2C01_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef EEP_30_XXI2C01_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( EEP_30_XXI2C01_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef EEP_30_XXI2C01_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( EEP_30_XXI2C01_START_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef EEP_30_XXI2C01_START_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( EEP_30_XXI2C01_STOP_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef EEP_30_XXI2C01_STOP_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( EEP_30_XXI2C01_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef EEP_30_XXI2C01_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( EEP_30_XXI2C01_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef EEP_30_XXI2C01_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( EEP_30_XXI2C01_START_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef EEP_30_XXI2C01_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( EEP_30_XXI2C01_STOP_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef EEP_30_XXI2C01_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_START_SEC_CONFIG_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_START_SEC_CONFIG_DATA
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_STOP_SEC_CONFIG_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_STOP_SEC_CONFIG_DATA
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_START_SEC_VAR_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_START_SEC_VAR_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_STOP_SEC_VAR_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_STOP_SEC_VAR_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_START_SEC_VAR_NO_INIT_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_START_SEC_VAR_NO_INIT_16
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_STOP_SEC_VAR_NO_INIT_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_STOP_SEC_VAR_NO_INIT_16
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_START_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_START_SEC_CONFIG_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_START_SEC_CONFIG_DATA
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_STOP_SEC_CONFIG_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_STOP_SEC_CONFIG_DATA
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_START_SEC_ISR_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_START_SEC_ISR_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_STOP_SEC_ISR_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_STOP_SEC_ISR_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_START_SEC_RX_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_START_SEC_RX_DATA
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_STOP_SEC_RX_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_STOP_SEC_RX_DATA
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_START_SEC_TX_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_START_SEC_TX_DATA
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_STOP_SEC_TX_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_STOP_SEC_TX_DATA
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_START_SEC_UDMA )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_START_SEC_UDMA
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_STOP_SEC_UDMA )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_STOP_SEC_UDMA
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_START_SEC_UDMA_DESC )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_START_SEC_UDMA_DESC
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_STOP_SEC_UDMA_DESC )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_STOP_SEC_UDMA_DESC
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_START_SEC_UDMA_RING )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_START_SEC_UDMA_RING
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_STOP_SEC_UDMA_RING )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_STOP_SEC_UDMA_RING
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_START_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLAP_RAMCODE_START_SEC_CODE ) || \
    defined( FBLAP_RAMCODE_START_SEC_CODE_EXPORT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLAP_RAMCODE_START_SEC_CODE
# undef FBLAP_RAMCODE_START_SEC_CODE_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLAP_RAMCODE_STOP_SEC_CODE ) || \
    defined( FBLAP_RAMCODE_STOP_SEC_CODE_EXPORT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLAP_RAMCODE_STOP_SEC_CODE
# undef FBLAP_RAMCODE_STOP_SEC_CODE_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLASRSTUBS_DEM_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLASRSTUBS_DEM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLASRSTUBS_DEM_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLASRSTUBS_DEM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBMAP_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBMAP_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBMAP_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBMAP_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBMAP_START_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBMAP_START_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBMAP_STOP_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBMAP_STOP_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBMHDR_BMHEADER_START_SEC_CONST )
   __attribute__ ((section (".BmHdrHeaderSection")))
   __attribute__ ((retain))
# define FBLBMHDR_BMHEADER_DATA_SECTION
# undef FBLBMHDR_BMHEADER_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBMHDR_BMHEADER_STOP_SEC_CONST )

# undef FBLBMHDR_BMHEADER_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBMHDR_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBMHDR_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBMHDR_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBMHDR_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBMHDR_START_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBMHDR_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBMHDR_STOP_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBMHDR_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBM_HEADER_START_SEC_CONST )
   __attribute__ ((section (".BmHeaderSection")))


# define FBLBM_HEADER_DATA_SECTION
# undef FBLBM_HEADER_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBM_HEADER_STOP_SEC_CONST )

# undef FBLBM_HEADER_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBM_MAIN_APPLSTART_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBM_MAIN_APPLSTART_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBM_MAIN_APPLSTART_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBM_MAIN_APPLSTART_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBM_MAIN_FBLSTART_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBM_MAIN_FBLSTART_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBM_MAIN_FBLSTART_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBM_MAIN_FBLSTART_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBM_MAIN_MAGICFLAG_START_SEC_VAR_NOINIT )
   __attribute__ ((section (".MagicFlagSection")))

# undef FBLBM_MAIN_MAGICFLAG_START_SEC_VAR_NOINIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBM_MAIN_MAGICFLAG_STOP_SEC_VAR_NOINIT )

# undef FBLBM_MAIN_MAGICFLAG_STOP_SEC_VAR_NOINIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBM_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBM_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBM_FBLSTART_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBM_FBLSTART_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBM_FBLSTART_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBM_FBLSTART_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBM_START_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBM_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBM_STOP_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBM_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBM_START_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBM_START_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBM_STOP_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBM_STOP_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_CAN_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_CAN_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_CAN_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_CAN_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif
/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_LIN_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_LIN_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_LIN_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_LIN_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif



/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_CONST_64BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_CONST_64BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_CONST_64BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_CONST_64BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_NOINIT_64BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_NOINIT_64BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_NOINIT_64BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_NOINIT_64BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_NOINIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_NOINIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_NOINIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_NOINIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLDIAG_RAMCODE_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLDIAG_RAMCODE_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLDIAG_RAMCODE_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLDIAG_RAMCODE_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLDIAG_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLDIAG_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLDIAG_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLDIAG_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLDIAG_START_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLDIAG_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLDIAG_STOP_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLDIAG_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLDIAG_START_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLDIAG_START_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLDIAG_STOP_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLDIAG_STOP_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLFLIO_START_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLFLIO_START_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLFLIO_STOP_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLFLIO_STOP_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */
#if defined( FBLFLIO_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLFLIO_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLFLIO_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLFLIO_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */
#if defined( FBLFLIO_FLASHCODE_START_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLFLIO_FLASHCODE_START_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLFLIO_FLASHCODE_STOP_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLFLIO_FLASHCODE_STOP_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLHEADER_START_SEC_CONST )
 __attribute__ ((section (".FblHeaderSection")))
 __attribute__ ((retain))

# define FBLHEADER_DATA_SECTION
# undef FBLHEADER_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLHEADER_STOP_SEC_CONST )

# undef FBLHEADER_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLHW_RAMCODE_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLHW_RAMCODE_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLHW_RAMCODE_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLHW_RAMCODE_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLHW_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLHW_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLHW_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLHW_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLHW_START_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLHW_START_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLHW_STOP_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLHW_STOP_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLLIB_MEM_RAMCODE_START_SEC_CODE ) || \
    defined( FBLLIB_MEM_RAMCODE_START_SEC_CODE_EXPORT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLLIB_MEM_RAMCODE_START_SEC_CODE
# undef FBLLIB_MEM_RAMCODE_START_SEC_CODE_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLLIB_MEM_RAMCODE_STOP_SEC_CODE ) || \
    defined( FBLLIB_MEM_RAMCODE_STOP_SEC_CODE_EXPORT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLLIB_MEM_RAMCODE_STOP_SEC_CODE
# undef FBLLIB_MEM_RAMCODE_STOP_SEC_CODE_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLLIB_MEM_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLLIB_MEM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLLIB_MEM_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLLIB_MEM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLLIB_MEM_START_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLLIB_MEM_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLLIB_MEM_STOP_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLLIB_MEM_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLLIB_MEM_START_SEC_VAR ) || \
    defined( FBLLIB_MEM_START_SEC_VAR_EXPORT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLLIB_MEM_START_SEC_VAR
# undef FBLLIB_MEM_START_SEC_VAR_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLLIB_MEM_STOP_SEC_VAR ) || \
    defined( FBLLIB_MEM_STOP_SEC_VAR_EXPORT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLLIB_MEM_STOP_SEC_VAR
# undef FBLLIB_MEM_STOP_SEC_VAR_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLMIO_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLMIO_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLMIO_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLMIO_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLMIO_START_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLMIO_START_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLMIO_STOP_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLMIO_STOP_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLNVPATTERN_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLNVPATTERN_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLNVPATTERN_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLNVPATTERN_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLNVPATTERN_START_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLNVPATTERN_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLNVPATTERN_STOP_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLNVPATTERN_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLNVPATTERN_START_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLNVPATTERN_START_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLNVPATTERN_STOP_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLNVPATTERN_STOP_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLSB_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLSB_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLSB_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLSB_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLSB_START_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLSB_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLSB_STOP_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLSB_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLWD_INIT_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLWD_INIT_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLWD_INIT_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLWD_INIT_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLWD_RAMCODE_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLWD_RAMCODE_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLWD_RAMCODE_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLWD_RAMCODE_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLWD_START_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLWD_START_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLWD_STOP_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLWD_STOP_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBL_APPLVECT_START_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_APPLVECT_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_APPLVECT_STOP_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_APPLVECT_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_APPL_CONFIG_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_APPL_CONFIG_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_APPL_CONFIG_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_APPL_CONFIG_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_START_SEC_CONFIG_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_START_SEC_CONFIG_DATA
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_STOP_SEC_CONFIG_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_STOP_SEC_CONFIG_DATA
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_START_SEC_ISR_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_START_SEC_ISR_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_STOP_SEC_ISR_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_STOP_SEC_ISR_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_CONFIG_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_CONFIG_DATA
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_CONFIG_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_CONFIG_DATA
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_ISR_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_ISR_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_ISR_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_ISR_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_VAR_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_VAR_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_VAR_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_VAR_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif
/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( NVM_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef NVM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( NVM_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef NVM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif
/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( I2C_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef I2C_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( I2C_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef I2C_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( I2C_START_SEC_CODE_ISR )
   /* #pragma <enter your compiler specific pragma> */
# undef I2C_START_SEC_CODE_ISR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( I2C_STOP_SEC_CODE_ISR )
   /* #pragma <enter your compiler specific pragma> */
# undef I2C_STOP_SEC_CODE_ISR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( I2C_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef I2C_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( I2C_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef I2C_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( I2C_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef I2C_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( I2C_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef I2C_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( I2C_START_SEC_PBCFG_GLOBALROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef I2C_START_SEC_PBCFG_GLOBALROOT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( I2C_STOP_SEC_PBCFG_GLOBALROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef I2C_STOP_SEC_PBCFG_GLOBALROOT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( I2C_START_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef I2C_START_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( I2C_STOP_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef I2C_STOP_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( I2C_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef I2C_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( I2C_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( I2C_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef I2C_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( I2C_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef I2C_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */
#if defined( MEMCPY_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef MEMCPY_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MEMCPY_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef MEMCPY_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PDUR_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PDUR_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_START_SEC_CONFIG_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_START_SEC_CONFIG_DATA
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_STOP_SEC_CONFIG_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_STOP_SEC_CONFIG_DATA
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_START_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_START_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_STOP_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_STOP_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_START_SEC_ISR_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_START_SEC_ISR_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_STOP_SEC_ISR_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_STOP_SEC_ISR_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_START_SEC_VAR_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_START_SEC_VAR_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_STOP_SEC_VAR_INIT_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_STOP_SEC_VAR_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_START_SEC_VAR_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_START_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_STOP_SEC_VAR_INIT_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_STOP_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_START_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( RTE_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef RTE_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( RTE_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef RTE_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SECMPAR_START_SEC_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef SECMPAR_START_SEC_DATA
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SECMPAR_STOP_SEC_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef SECMPAR_STOP_SEC_DATA
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SECM_RAMCODE_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SECM_RAMCODE_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SECM_RAMCODE_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SECM_RAMCODE_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SECM_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SECM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SECM_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SECM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SECM_START_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef SECM_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SECM_STOP_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef SECM_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SECM_START_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef SECM_START_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SECM_STOP_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef SECM_STOP_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_CONFIG_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_CONFIG_DATA
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_CONFIG_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_CONFIG_DATA
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_ISR_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_ISR_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_ISR_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_ISR_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( START_SEC_VAR_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef START_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( STOP_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef STOP_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VSECPRIM_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef VSECPRIM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VSECPRIM_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef VSECPRIM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VSECPRIM_START_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VSECPRIM_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VSECPRIM_STOP_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VSECPRIM_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VSECPRIM_START_SEC_CONST_64BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VSECPRIM_START_SEC_CONST_64BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VSECPRIM_STOP_SEC_CONST_64BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VSECPRIM_STOP_SEC_CONST_64BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VSECPRIM_START_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VSECPRIM_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VSECPRIM_STOP_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VSECPRIM_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VSECPRIM_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef VSECPRIM_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VSECPRIM_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef VSECPRIM_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VSTDLIB_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef VSTDLIB_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VSTDLIB_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef VSTDLIB_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VSTDLIB_START_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VSTDLIB_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VSTDLIB_STOP_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VSTDLIB_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_START_SEC_CONFIG_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_START_SEC_CONFIG_DATA
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_STOP_SEC_CONFIG_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_STOP_SEC_CONFIG_DATA
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_START_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_START_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_STOP_SEC_CONST_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_STOP_SEC_CONST_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_START_SEC_ISR_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_START_SEC_ISR_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_STOP_SEC_ISR_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_STOP_SEC_ISR_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDTRIGGER_START_SEC_CODE ) || \
    defined( WDTRIGGER_START_SEC_CODE_EXPORT )
   /* #pragma <enter your compiler specific pragma> */
# undef WDTRIGGER_START_SEC_CODE
# undef WDTRIGGER_START_SEC_CODE_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDTRIGGER_STOP_SEC_CODE ) || \
    defined( WDTRIGGER_STOP_SEC_CODE_EXPORT )
   /* #pragma <enter your compiler specific pragma> */
# undef WDTRIGGER_STOP_SEC_CODE
# undef WDTRIGGER_STOP_SEC_CODE_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WRAPNV_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef WRAPNV_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WRAPNV_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef WRAPNV_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WRAPNV_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WRAPNV_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WRAPNV_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WRAPNV_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WRAPNV_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WRAPNV_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WRAPNV_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WRAPNV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( _CDD_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef _CDD_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( _CDD_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef _CDD_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

/**********************************************************************************************************************
 *  VMEMACCM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VMEMACCM_START_SEC_CODE)
# undef VMEMACCM_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VMEMACCM_STOP_SEC_CODE)
# undef VMEMACCM_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(VMEMACCM_START_SEC_VAR_INIT_8BIT)
# undef VMEMACCM_START_SEC_VAR_INIT_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT          /* mapped to default var init 8bit section */
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_INIT_8BIT)
# undef VMEMACCM_STOP_SEC_VAR_INIT_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                     /* default var stop section */
#endif

#if defined(VMEMACCM_START_SEC_VAR_INIT_16BIT)
# undef VMEMACCM_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_INIT_16BIT)
# undef VMEMACCM_STOP_SEC_VAR_INIT_16BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_INIT_32BIT)
# undef VMEMACCM_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_INIT_32BIT)
# undef VMEMACCM_STOP_SEC_VAR_INIT_32BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED)
# undef VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#if defined(VMEMACCM_START_SEC_VAR_ZERO_INIT_8BIT)
# undef VMEMACCM_START_SEC_VAR_ZERO_INIT_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef VMEMACCM_STOP_SEC_VAR_ZERO_INIT_8BIT    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef VMEMACCM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef VMEMACCM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR CONST sections */

#if defined(VMEMACCM_START_SEC_CONST_UNSPECIFIED)
# undef VMEMACCM_START_SEC_CONST_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(VMEMACCM_STOP_SEC_CONST_UNSPECIFIED)
# undef VMEMACCM_STOP_SEC_CONST_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* VAR NOINIT sections */

#if defined(VMEMACCM_START_SEC_VAR_NOINIT_8BIT)
# undef VMEMACCM_START_SEC_VAR_NOINIT_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_NOINIT_8BIT)
# undef VMEMACCM_STOP_SEC_VAR_NOINIT_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_NOINIT_16BIT)
# undef VMEMACCM_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_NOINIT_16BIT)
# undef VMEMACCM_STOP_SEC_VAR_NOINIT_16BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_NOINIT_32BIT)
# undef VMEMACCM_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_NOINIT_32BIT)
# undef VMEMACCM_STOP_SEC_VAR_NOINIT_32BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VMEMACCM_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VMEMACCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* Multi partition sections. */

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID0
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID0
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if 1
   /* Pragma demo for GHS compiler: */
//# pragma clang section data = "vMemAccMPartition"
# pragma clang section data = ".vMemAccMPartition"
//#   pragma ghs section data=".vMemAccMPartition0"
//#   pragma ghs section sdata=".svMemAccMPartition0"
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID0
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID0
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if 1
    /* Pragma demo for GHS compiler: */
# pragma clang section data = ""
//#   pragma ghs section data=default
//#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif


#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID1
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID1
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if 1
   /* Pragma demo for GHS compiler: */
//# pragma clang section data = "vMemAccMPartition"
# pragma clang section data = ".vMemAccMPartition"
//#   pragma ghs section data=".vMemAccMPartition1"
//#   pragma ghs section sdata=".svMemAccMPartition1"
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID1
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID1
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if 1
    /* Pragma demo for GHS compiler: */
# pragma clang section data = ""
//#   pragma ghs section data=default
//#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID2
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID2
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition2"
#   pragma ghs section sdata=".svMemAccMPartition2"
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID2
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID2
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID3
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID3
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition3"
#   pragma ghs section sdata=".svMemAccMPartition3"
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID3
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID3
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID4
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID4
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition4"
#   pragma ghs section sdata=".svMemAccMPartition4"
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID4
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID4
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID5
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID5
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition5"
#   pragma ghs section sdata=".svMemAccMPartition5"
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID5
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID5
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID6
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID6
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition6"
#   pragma ghs section sdata=".svMemAccMPartition6"
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID6
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID6
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID7
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID7
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition7"
#   pragma ghs section sdata=".svMemAccMPartition7"
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID7
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID7
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID8
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID8
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition8"
#   pragma ghs section sdata=".svMemAccMPartition8"
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID8
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID8
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID9
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID9
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition9"
#   pragma ghs section sdata=".svMemAccMPartition9"
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID9
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID9
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID10
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID10
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition10"
#   pragma ghs section sdata=".svMemAccMPartition10"
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID10
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID10
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID11
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID11
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition11"
#   pragma ghs section sdata=".svMemAccMPartition11"
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID11
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID11
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID12
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID12
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition12"
#   pragma ghs section sdata=".svMemAccMPartition12"
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID12
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID12
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID13
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID13
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition13"
#   pragma ghs section sdata=".svMemAccMPartition13"
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID13
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID13
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID14
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID14
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition14"
#   pragma ghs section sdata=".svMemAccMPartition14"
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID14
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID14
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID15
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID15
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition15"
#   pragma ghs section sdata=".svMemAccMPartition15"
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID15
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID15
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID16
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID16
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition16"
#   pragma ghs section sdata=".svMemAccMPartition16"
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID16
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID16
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  VMEMACCM END
 *********************************************************************************************************************/

#if defined( FBL_MEMMAP_ERROR )
#undef FBL_MEMMAP_ERROR
#endif



#if defined( FBL_MEMMAP_ERROR )
# error "Error in MemMap.h: MemMap section is not included!"
#endif

/* Module specific MISRA deviations:

   MD_MemMap_0883:
      Reason:     This file has to be included multiple times explicitly, due to the memory mapping mechanism.
      Risk:       No risk due to the undef pragmas and error pragma.
      Prevention: No prevention.

*/

/**********************************************************************************************************************
 *  END OF FILE: MEMMAP.H
 *********************************************************************************************************************/
