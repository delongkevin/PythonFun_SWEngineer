#ifndef CALDATAPROVIDER_H_INCLUDEGUARD
#define CALDATAPROVIDER_H_INCLUDEGUARD

#include "SSM_Slave.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
extern void CDP_Cal_DataProvider_Init_v(void);
extern void CalDataProvider_Run_v(void);
/* Resend Cal Data update to all cores */
extern void CDP_F_CalData_update_to_core_v(SSM_CORE_Defs i_coreid);
void Get_Vehicle_Variant(uint8_t* vehicle_variant);

#endif
