/*
 *   file NvM_Callout_Stubs
 *   brief Diagnostics
 *
 *  Diagnostics
 *
 *  --------------------------------------------------------------------------
 *  copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 *
 *  author Swastik Sharma
 */
/*==================[inclusions]============================================*/
/* Standardized includes */
#include "NvM.h"
#include "Os.h"
#include "Rte_CDD_Safety_Type.h"
/*==================[internal macros]=======================================*/
#define NO_OF_REDUNDANT_BLOCKS        7u
#define THREE 3u
#define MAX_VAL_UINT8 255u
/*==================[internal type definitions]=============================*/
typedef struct
{
   uint8 count;
   NvM_BlockIdType BlockId;
}Nvm_BlockFailInfo_t;


/*==================[internal function declarations]========================*/
FUNC(void, NVM_PUBLIC_CODE) NvM_LossOfRedundancyCbk(NvM_BlockIdType BlockId);

/*==================[internal constants]====================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/



/******************************************************************************************
FUNCTION NAME:          NvM_LossOfRedundancyCbk
PURPOSE:                Function required by NvM to define action to be taken in case of
                        loss of redundancy for an NvM block.
                        Stub is created here because the application does not have an use case
                        for this scenario.

RETURN VALUE:           None.
INPUT PARAMETERS:       NvM_BlockIdType BlockId - NvM block Id.
OUTPUT PARAMETERS:      None.


ORIGINATOR:             -
DATE OF CREATION:       -
******************************************************************************************/
FUNC(void, NVM_PUBLIC_CODE) NvM_LossOfRedundancyCbk(NvM_BlockIdType BlockId)
{
   uint8 block_index=0u;
   boolean BreakForLoop = FALSE;
   static Nvm_BlockFailInfo_t Nvm_BlockFailInfo[NO_OF_REDUNDANT_BLOCKS] = {0};
   for(uint8 index = (uint8)0; index < (uint8)NO_OF_REDUNDANT_BLOCKS; index++)
   {
	   if(Nvm_BlockFailInfo[index].BlockId == BlockId)
	   {
		   if((uint8)(MAX_VAL_UINT8)>(uint8)(Nvm_BlockFailInfo[index].count+(uint8)1u))
		   {
			   Nvm_BlockFailInfo[index].count = Nvm_BlockFailInfo[index].count + (uint8)1u;
		   }
		   else
		   {
			   /* Do Nothing */
		   }
		   block_index = index;
		   BreakForLoop = TRUE;
	   }
	   else if (Nvm_BlockFailInfo[index].BlockId == (NvM_BlockIdType)0u)
	   {
		   Nvm_BlockFailInfo[index].BlockId = BlockId;
		   if((uint8)(MAX_VAL_UINT8)>(uint8)(Nvm_BlockFailInfo[index].count+(uint8)1u))
		   {
			   Nvm_BlockFailInfo[index].count = Nvm_BlockFailInfo[index].count + (uint8)1u;
		   }
		   else
		   {
			   /* Do Nothing */
		   }
		   BreakForLoop = TRUE;
	   }
	   else
	   {
		   /* Do Nothing*/
	   }
	   if((boolean)TRUE == BreakForLoop)
	   {
		   break;
	   }
	   else
	   {
		   /* Do Nothing */
	   }
   }

   if(Nvm_BlockFailInfo[block_index].count > (uint8)THREE)
   {
	   (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_SysIntFlt_MCU_CRC_Failure_in_Safety_critical_data_primary_second_copy, ErrorMgr_ErrorActive, NULL_PTR);

	   /* Send Data over CAN for debug*/
	   Os_Call_f_Send_Dbg_SDLFault_CanTx((uint16)ErrorMgr_Error_SysIntFlt_MCU_CRC_Failure_in_Safety_critical_data_primary_second_copy);
	   Nvm_BlockFailInfo[block_index].count = (uint8)0u;
	   Nvm_BlockFailInfo[block_index].BlockId = (NvM_BlockIdType)0u;
   }
   else
   {
	   /* Do Nothing */
   }

   NvM_RepairRedundantBlocks();

}
