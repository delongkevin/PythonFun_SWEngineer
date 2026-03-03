#ifndef TIMEMANAGERPROXY_INCLUDEGUARD
#define TIMEMANAGERPROXY_INCLUDEGUARD

void TimeManagerProxy_InitEndPoint(void);
void TimeManagerProxy_MainFunction(void);
uint64_t TimeManagerProxy_GetCurrSyncedTime(void);
uint64_t TimeManagerProxy_CalcCurrSyncedTime(uint64_t stbmTimeStamp, uint64_t appLogTimeStamp);
#endif
