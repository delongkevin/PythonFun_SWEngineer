/** \file Us_Csm_Rules_If.h
 *  \version 1.00
 *  \date 2013-06-05
 *  \author Amol Gore (Amol.Gore\magna.com)
 *  \brief 
 *
 *  \copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 */

#ifndef _US_CSM_RULES_IF_H_
#define _US_CSM_RULES_IF_H_
/************************************************************************************************************************
                                                            Includes
************************************************************************************************************************/
#include "Us_Csm_Types.h"

/************************************************************************************************************************
                                                            #defines
************************************************************************************************************************/


/************************************************************************************************************************
                                                            #typedef
************************************************************************************************************************/


/************************************************************************************************************************
                                                            extern Variables(optional)
************************************************************************************************************************/


/************************************************************************************************************************
                                                            extern Functions(optional)
************************************************************************************************************************/
extern UsCsm_StdReturn_Type UsCsm_Rule_CheckAndExecuteRule_AlwaysPass(UsCsm_LocalModuleId_Type UsCsmLocalModuleId, UsCsm_InstanceId_Type instanceId,
										 UsCsm_LocalErrorId_Type UsCsmLocalErrorId,UsCsm_LocalErrState_Type UsCsmLocalErrState);
                                         

#endif