/** \file Us_Csm_StateActions_If.h
 *  \version 1.00
 *  \date 2013-06-05
 *  \author Amol Gore (Amol.Gore\magna.com)
 *  \brief This files contains the function list which can be used by other files.
 *
 *  \copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 */

#ifndef _US_CSM_STATE_ACTIONS_IF_H_
#define _US_CSM_STATE_ACTIONS_IF_H_
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
extern UsCsm_StdReturn_Type UsCsm_StateAction_DuringUninit(void);
extern UsCsm_StdReturn_Type UsCsm_StateAction_ExitUninit(void);

extern UsCsm_StdReturn_Type UsCsm_StateAction_OnEntryInitState(void);
extern UsCsm_StdReturn_Type UsCsm_StateAction_DuringInitState(void);
extern UsCsm_StdReturn_Type UsCsm_StateAction_ExitInit(void);


extern UsCsm_StdReturn_Type UsCsm_StateAction_OnEntryPreSafeState1(void);
extern UsCsm_StdReturn_Type UsCsm_StateAction_DuringPreSafestate1(void);
extern UsCsm_StdReturn_Type UsCsm_StateAction_ExitPreSafestate1(void);

extern UsCsm_StdReturn_Type UsCsm_StateAction_OnEntryPreShutdown(void);
extern UsCsm_StdReturn_Type UsCsm_StateAction_DuringPreShutdown(void);
extern UsCsm_StdReturn_Type UsCsm_StateAction_DuringDegraded(void);

#endif