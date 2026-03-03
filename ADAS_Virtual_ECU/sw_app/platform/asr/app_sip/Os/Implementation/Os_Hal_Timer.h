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
 *  \file
 *  \brief  HAL interface to work with timer hardware.
 *  \details
 *  This file chooses the appropriate timer implementation file depending on configuration.
 *  If there is no timer configured a stub implementation is provided.
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_TIMER_H
# define OS_HAL_TIMER_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os kernel module dependencies */
# include "Os_Common.h"

/* Os Hal dependencies */
# include "Os_Hal_TimerInt.h"
# include "Os_Hal_Derivative.h"
# include "Os_Hal_Compiler.h"

# if defined(OS_HAL_TIMER_FRT_RTI)                                                                                      /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_Timer_Frt_Rti.h"
# elif defined(OS_HAL_TIMER_FRT_TTC)                                                                                    /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_Timer_Frt_Ttc.h"
# elif defined(OS_HAL_TIMER_FRT_FRT)                                                                                    /* COV_OS_DERIVATIVEDUMMYMODULE */
#  include "Os_Hal_Timer_Frt_Frt.h"
# elif defined(OS_HAL_TIMER_FRT_SICMPT)                                                                                 /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_Timer_Frt_Sicmpt.h"
# elif defined(OS_HAL_TIMER_FRT_TIMER_JACINTO7)                                                                         /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Timer_Frt_Jacinto7.h"
# elif defined(OS_HAL_TIMER_FRTPIT_TIMER_TC803X_MICOM)                                                                  /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_Timer_Frt_TCC803x_MICOM.h"
# elif defined(OS_HAL_TIMER_FRT_V8R_GENERICTIMER)                                                                       /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_Timer_Frt_V8RGeneric.h"
# elif defined(OS_HAL_TIMER_FRT_BTM_SEMIDRIVE)                                                                          /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_Timer_Frt_BTM_Semidrive.h"
# else
#  include "Os_Hal_Timer_Frt_Dummy.h"
# endif

# if defined(OS_HAL_TIMER_PIT_PRIVATETIMER)                                                                             /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_Timer_Pit_PrivateTimer.h"
# elif defined(OS_HAL_TIMER_PIT_RTI)                                                                                    /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_Timer_Pit_Rti.h"
# elif defined(OS_HAL_TIMER_PIT_TTC)                                                                                    /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_Timer_Pit_Ttc.h"
# elif defined(OS_HAL_TIMER_PIT_TMU)                                                                                    /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_Timer_Pit_TMU.h"
# elif defined(OS_HAL_TIMER_PIT_RELOADTIMER)                                                                            /* COV_OS_DERIVATIVEDUMMYMODULE */
#  include "Os_Hal_Timer_Pit_ReloadTimer.h"
# elif defined(OS_HAL_TIMER_PIT_SICMPT)                                                                                 /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_Timer_Pit_Sicmpt.h"
# elif defined(OS_HAL_TIMER_PIT_TMR)                                                                                    /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_Timer_Pit_Tmr.h"
# elif defined(OS_HAL_TIMER_FRTPIT_TCCX_MICOM)                                                                          /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_Timer_Pit_TCC803x_MICOM.h"
# elif defined(OS_HAL_TIMER_PIT_ETMR_SEMIDRIVE)                                                                         /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_Timer_Pit_ETMR_Semidrive.h"
# elif defined(OS_HAL_TIMER_PIT_TMR_SEMIDRIVE)                                                                          /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_Timer_Pit_TMR_Semidrive.h"
# elif defined(OS_HAL_TIMER_PIT_DUALTIMER)                                                                              /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_Timer_Pit_DualTimer.h"
# else
#  include "Os_Hal_Timer_Pit_Dummy.h"
# endif

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* OS_HAL_TIMER_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer.h
 **********************************************************************************************************************/

