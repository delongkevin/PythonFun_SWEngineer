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
 * \ingroup      Os_Hal
 * \defgroup     Os_Hal_Derivative HAL Derivative
 *
 * \{
 * \file         Os_Hal_DerivativeInt.h
 * \brief        Selects a derivative specific header and includes it.
 * \details
 *  This modules decides which HAL specific sub components are needed to implement HAL functionality on a specific
 *  derivative.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/


#ifndef  OS_HAL_DERIVATIVEINT_H
# define OS_HAL_DERIVATIVEINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */

/* Os module declarations */
# include "Os_Cfg.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
# if defined(OS_CFG_DERIVATIVEGROUP_S6J311X)                                                                            /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_S6J311xInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_S6J312X)                                                                          /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_S6J312xInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_S6J32XX)                                                                          /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_S6J32xxInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_S6J33XX)                                                                          /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_S6J33xxInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_S6J336X)                                                                          /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_S6J336xInt.h"
# elif defined (OS_CFG_DERIVATIVEGROUP_S6J34XX)                                                                         /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_S6J34xxInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_ZUXXX)                                                                            /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_ZUxxxInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_ZUXXX_A53)                                                                        /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_ZUxxx_A53Int.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RCARX3)                                                                           /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RCARx3Int.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RCARX3_A57)                                                                       /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RCARx3_A57Int.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_IMX6DX)                                                                           /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_iMX6DxInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_IMX6QX)                                                                           /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_iMX6QxInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_AR16XX)                                                                           /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_AR16xxInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_AM26XX)                                                                           /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_AM26xxInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_AM62XX)                                                                           /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_AM62xxInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_AM62XXA)                                                                          /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_AM62xxAInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_TMS570LS21X_31X)                                                                  /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_TMS570LS21x_31xInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_TMS570LC43X)                                                                      /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_TMS570LC43xInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_TMPV770X)                                                                         /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_TMPV770xInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_XAVIER)                                                                           /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_XavierInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_GENERIC_CORTEXR52)                                                                /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_Generic_CortexR52Int.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_SR6XX)                                                                            /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_SR6xxInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_JACINTO7)                                                                         /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_Jacinto7Int.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_TCC803X)                                                                          /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_TCC803xInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_TPRXX)                                                                            /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_TPRxxInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_TCC701X)                                                                          /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_TCC701xInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_G9X)                                                                              /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_G9xInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_CYCLONEV)                                                                         /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_CycloneVInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_S32GXX)                                                                           /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_S32GxxInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_E36XX)                                                                            /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_E36xxInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_E34XX)                                                                            /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_E34xxInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_E31XX_E32XX_E33XX)                                                                      /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_E31xx_E32xx_E33xxInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RCARV4H)                                                                          /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RCARV4HInt.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_LG61XX)                                                                           /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_LG61xxInt.h"
# else
#  error "The selected derivative is not supported!"
# endif /* OS_CFG_DERIVATIVE_<> */

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


#endif /* OS_HAL_DERIVATIVEINT_H */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_DerivativeInt.h
 **********************************************************************************************************************/
