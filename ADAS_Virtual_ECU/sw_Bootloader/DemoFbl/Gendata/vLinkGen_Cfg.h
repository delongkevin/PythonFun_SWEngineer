/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: vLinkGen
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vLinkGen_Cfg.h
 *   Generation Time: 2024-11-25 15:00:22
 *           Project: DemoFbl - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EXAMPLE CODE ONLY
 *  -------------------------------------------------------------------------------------------------------------------
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
 *  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
 *  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
 *  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
 *  according to the state of the art before their use.
 *********************************************************************************************************************/

#ifndef VLINKGEN_CFG_H
# define VLINKGEN_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "vBrsCfg.h"

/**********************************************************************************************************************
 *  USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Configuration major version identification. */
# define VLINKGEN_CFG_MAJOR_VERSION                   2u
/*! Configuration minor version identification. */
# define VLINKGEN_CFG_MINOR_VERSION                   6u

/* Number of entries for different initialization tables */
# define VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS      1u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_ONE_BLOCKS        3u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_BLOCKS 1u 

#ifdef DemoAppl
/* Number of entries for different initialization tables of variant: DemoAppl */
# define VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS      2u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_ZERO_GROUPS       1u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_ONE_GROUPS        2u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_TWO_GROUPS        1u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_THREE_GROUPS      1u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_GROUPS 1u 
# define VLINKGEN_CFG_NUM_INIT_ZERO_GROUPS            1u 
# define VLINKGEN_CFG_NUM_INIT_ONE_GROUPS             3u 
# define VLINKGEN_CFG_NUM_INIT_TWO_GROUPS             1u 
# define VLINKGEN_CFG_NUM_INIT_THREE_GROUPS           1u 
# define VLINKGEN_CFG_NUM_INIT_HARD_RESET_GROUPS      1u 
#endif /* DemoAppl */

#ifdef DemoBm
/* Number of entries for different initialization tables of variant: DemoBm */
# define VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS      2u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_ZERO_GROUPS       1u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_ONE_GROUPS        2u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_TWO_GROUPS        1u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_THREE_GROUPS      1u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_GROUPS 1u 
# define VLINKGEN_CFG_NUM_INIT_ZERO_GROUPS            1u 
# define VLINKGEN_CFG_NUM_INIT_ONE_GROUPS             3u 
# define VLINKGEN_CFG_NUM_INIT_TWO_GROUPS             1u 
# define VLINKGEN_CFG_NUM_INIT_THREE_GROUPS           1u 
# define VLINKGEN_CFG_NUM_INIT_HARD_RESET_GROUPS      1u 
#endif /* DemoBm */

#ifdef DemoFbl
/* Number of entries for different initialization tables of variant: DemoFbl */
# define VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS      2u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_ZERO_GROUPS       1u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_ONE_GROUPS        2u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_TWO_GROUPS        1u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_THREE_GROUPS      1u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_GROUPS 1u 
# define VLINKGEN_CFG_NUM_INIT_ZERO_GROUPS            1u 
# define VLINKGEN_CFG_NUM_INIT_ONE_GROUPS             3u 
# define VLINKGEN_CFG_NUM_INIT_TWO_GROUPS             1u 
# define VLINKGEN_CFG_NUM_INIT_THREE_GROUPS           1u 
# define VLINKGEN_CFG_NUM_INIT_HARD_RESET_GROUPS      1u 
#endif /* DemoFbl */

#ifdef DemoUpd
/* Number of entries for different initialization tables of variant: DemoUpd */
# define VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS      2u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_ZERO_GROUPS       1u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_ONE_GROUPS        2u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_TWO_GROUPS        1u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_THREE_GROUPS      1u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_GROUPS 1u 
# define VLINKGEN_CFG_NUM_INIT_ZERO_GROUPS            1u 
# define VLINKGEN_CFG_NUM_INIT_ONE_GROUPS             3u 
# define VLINKGEN_CFG_NUM_INIT_TWO_GROUPS             1u 
# define VLINKGEN_CFG_NUM_INIT_THREE_GROUPS           1u 
# define VLINKGEN_CFG_NUM_INIT_HARD_RESET_GROUPS      1u 
#endif /* DemoUpd */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#endif /* VLINKGEN_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: vLinkGen_Cfg.h
 *********************************************************************************************************************/
