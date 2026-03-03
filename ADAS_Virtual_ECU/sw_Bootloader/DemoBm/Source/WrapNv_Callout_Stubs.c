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
 *            Module: WrapNv
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: WrapNv_Callout_Stubs.c
 *   Generation Time: 2024-11-25 13:00:27
 *           Project: DemoBm - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

#define WRAPNV_CALLOUT_STUBS_SOURCE

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "WrapNv.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK user_includes> DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#if (WRAPNV_MAINFUNCTION_POLLING == STD_ON)
# include "fbl_inc.h"
#endif /* WRAPNV_MAINFUNCTION_POLLING */

uint8 PollingCounterMain_u8=0;
uint8 PollingCounter_u8=0;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK> DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  USERCALLOUT FUNCTIONS
 *********************************************************************************************************************/

#if (WRAPNV_MAINFUNCTION_POLLING == STD_ON)

# define WRAPNV_START_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  WrapNv_TriggerFct_Callout
 **********************************************************************************************************************/
/*! \brief       Checks if the millisecond timer is expired
 *  \return      return WRAPNV_E_OK Millisecond timer expired
 *                      WRAPNV_E_NOT_OK Otherwise
 **********************************************************************************************************************/
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_TriggerFct_Callout( void )
{
   WrapNv_ReturnType result = WRAPNV_E_NOT_OK;

   /**********************************************************************************************************************
	    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK calloutstub> DO NOT CHANGE THIS COMMENT!
	    *********************************************************************************************************************/

	   if((FblLookForWatchdog() & FBL_TM_TRIGGERED ) == FBL_TM_TRIGGERED)
	   {
	//	   PollingCounter_u8++;
	//	   PollingCounterMain_u8++;
	//	   if(3u == PollingCounterMain_u8)
	//	   {
	//		   I2c_MainFunction();
	//		   PollingCounterMain_u8 = 0;
	//	   }
	//	   if(1u == PollingCounter_u8)
	//	   {
			   I2c_MainFunction();
			   I2c_PollingModeProcessing();
	//		   PollingCounter_u8 = 0;
	//	   }


		   result = WRAPNV_E_OK;
	   }

	   /**********************************************************************************************************************
	    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK> DO NOT CHANGE THIS COMMENT!
	    *********************************************************************************************************************/

   return result;
}

# define WRAPNV_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* WRAPNV_MAINFUNCTION_POLLING */

/* Unrecognized user block tags */
#if 0
#endif


/**********************************************************************************************************************
  END OF FILE: WrapNv_Callout_Stubs.c
**********************************************************************************************************************/
