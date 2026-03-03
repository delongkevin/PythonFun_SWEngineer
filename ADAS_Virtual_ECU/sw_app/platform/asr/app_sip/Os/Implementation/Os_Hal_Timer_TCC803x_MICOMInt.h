/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 *  \addtogroup  Os_Hal_Timer
 *  \{
 *
 *  \file    Os_Hal_Timer_TCC803x_MICOMInt.h
 *  \brief   Data types and interfaces to work with the Timer.
 *  \details Timer module features:
 *              - Six counters.
 *              - Can be used either as PIT or FRT.
 *
 *  Internal comment removed.
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_TIMER_TCC803X_MICOMINT_H
# define OS_HAL_TIMER_TCC803X_MICOMINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_TimerInt.h"

/* Os kernel module dependencies */
# include "Os_Common.h"

/* Os HAL dependencies */
# include "Os_Hal_Compiler.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/*! Timer TCC803x MICOM interrupt clear control value. */
# define OS_HAL_TIMER_TCC803X_MICOM_INTCLRVAL    (0x0000001FuL)

/*! Timer TCC803x MICOM stop mask. */
# define OS_HAL_TIMER_TCC803X_MICOM_STOPMSK      (0xFEFFFFFFuL)

/*! Timer TCC803x MICOM start mask. */
# define OS_HAL_TIMER_TCC803X_MICOM_STARTMSK     (0x01000000uL)

/*! Timer TCC803x MICOM operation mode clear mask. */
# define OS_HAL_TIMER_TCC803X_MICOM_OPMODE       (0xC9FFFFFFuL)

/*! Timer TCC803x MICOM pre-scale count mask. */
# define OS_HAL_TIMER_TCC803X_MICOM_PRESCALEMSK  (0xFF000000uL)

/*! Timer TCC803x MICOM pre-scale counter load value. */
# define OS_HAL_TIMER_TCC803X_MICOM_PRESCALEVAL  (0x00000000uL)

/*! Timer TCC803x MICOM interrupt clear control mask. */
# define OS_HAL_TIMER_TCC803X_MICOM_IRQCLR       (0x80000000uL)


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
 /*! Memory mapped Timer TCC803x MICOM registers corresponding to the memory layout */
struct Os_Hal_TimerTCC803xMICOMType_Tag
{
  uint32 TimerOPENCFG;      /*! < +00h Timer operation enable and configuration register. (32 bit read/write) */
  uint32 TimerMAINCNTLVD;   /*! < +04h Timer main counter load value register. (32 bit read/write) */
  uint32 TimerCMPVALUE0;    /*! < +08h Timer counter compare value-0 register. (32 bit read/write) */
  uint32 TimerCMPVALUE1;    /*! < +0Ch Timer counter compare value-1 register. (32 bit read/write) */
  uint32 TimerPSCLCNT;      /*! < +10h Timer pre-scaled counter value register. (32 bit read) */
  uint32 TimerMAINCNT;      /*! < +14h Timer main counter value register. (32 bit read) */
  uint32 TimerIRQCTRL;      /*! < +18h Timer interrupt control configuration register. (32 bit read/write) */
};

/*! Forward declaration of platform specific TCC803x MICOM timer type. */
typedef struct Os_Hal_TimerTCC803xMICOMType_Tag Os_Hal_TimerTCC803xMICOMType;

/*! Pointer to platform specific TCC803x MICOM timer type. */
typedef CONSTP2VAR(volatile Os_Hal_TimerTCC803xMICOMType, AUTOMATIC, OS_CONST) Os_Hal_TimerTCC803xMICOMRefType;


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


#endif /* OS_HAL_TIMER_TCC803X_MICOMINT_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_TCC803x_MICOMInt
 **********************************************************************************************************************/
