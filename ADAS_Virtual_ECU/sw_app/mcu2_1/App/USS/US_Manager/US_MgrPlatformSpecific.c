/*
 * US_MgrPlatformSpecific.c
 *
 *  Created on: Mar 18, 2021
 *      Author: jonapais
 */

#include "US_ME_Typedefs_Global.h"

#if 0

bool_t isSend = ME_FALSE;
void SendBurstTimeLog(void)
{
#if Amazon_Debug_Msg
  if(isSend==ME_FALSE)
  {
      cMELog_F_LogDebug_v("Send Burst Interval: %dms", US_GetTimeStampTimeMs() - preTime2);
    preTime2 = US_GetTimeStampTimeMs();
    isSend = ME_TRUE;
  }
#endif
}

#endif
