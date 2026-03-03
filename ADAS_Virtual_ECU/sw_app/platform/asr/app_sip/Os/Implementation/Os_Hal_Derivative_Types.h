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
 *  \ingroup      Os_Hal
 *  \defgroup     Os_Hal_Derivative HAL Derivative
 *  \brief        Defines derivative specific functionality.
 *  \details
 *  This modules decides which HAL specific sub components are needed to implement HAL functionality on a specific
 *  derivative.
 *
 *  \{
 *
 * \file          Os_Hal_Derivative_Types.h
 *  \brief        Selects a derivative specific header and includes it.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/


#ifndef OS_HAL_DERIVATIVE_TYPES_H
# define OS_HAL_DERIVATIVE_TYPES_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Cfg.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
# if defined(OS_CFG_DERIVATIVEGROUP_S6J311X)                                                                            /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_S6J311x_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_S6J312X)                                                                          /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_S6J312x_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_S6J32XX)                                                                          /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_S6J32xx_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_S6J33XX)                                                                          /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_S6J33xx_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_S6J336X)                                                                          /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_S6J336x_Types.h"
# elif defined (OS_CFG_DERIVATIVEGROUP_S6J34XX)                                                                         /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_S6J34xx_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_ZUXXX)                                                                            /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_ZUxxx_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_ZUXXX_A53)                                                                        /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_ZUxxx_A53_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RCARX3)                                                                           /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RCARx3_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RCARX3_A57)                                                                       /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RCARx3_A57_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_IMX6DX)                                                                           /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_iMX6Dx_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_IMX6QX)                                                                           /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_iMX6Qx_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_AR16XX)                                                                           /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_AR16xx_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_AM26XX)                                                                           /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_AM26xx_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_AM62XX)                                                                           /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_AM62xx_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_AM62XXA)                                                                          /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_AM62xxA_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_TMS570LS21X_31X)                                                                  /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_TMS570LS21x_31x_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_TMS570LC43X)                                                                      /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_TMS570LC43x_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_TMPV770X)                                                                         /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_TMPV770x_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_XAVIER)                                                                           /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_Xavier_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_GENERIC_CORTEXR52)                                                                /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_Generic_CortexR52_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_SR6XX)                                                                            /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_SR6xx_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_JACINTO7)                                                                         /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_Jacinto7_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_TCC803X)                                                                          /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_TCC803x_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_TPRXX)                                                                            /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_TPRxx_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_TCC701X)                                                                          /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_TCC701x_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_G9X)                                                                              /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_G9x_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_CYCLONEV)                                                                         /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_CycloneV_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_S32GXX)                                                                           /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_S32GxxInt_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_E36XX)                                                                            /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_E36xx_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_E34XX)                                                                            /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_E34xx_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_E31XX_E32XX_E33XX)                                                                      /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_E31xx_E32xx_E33xx_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RCARV4H)                                                                          /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RCARV4H_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_LG61XX)                                                                           /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_LG61xx_Types.h"
# else
#  error "The selected derivative is not supported!"
# endif /* OS_CFG_DERIVATIVEGROUP_<> */
 
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

#endif /* OS_HAL_DERIVATIVE_TYPES_H */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Derivative_Types.h
 **********************************************************************************************************************/
