 /*
 * US_CtrlEnvCheckFsm.c
 *
 *  Created on: Mar 11, 2021
 *      Author: jonapais
 */

#include "US_CtrlMain.h"
#include "US_CtrlEnvCheckFsm.h"
#include "US_SnrCmd_Global.h"
#include "US_SnrData_Typedefs_Global.h"
#include "US_Platform_Global.h"

static uint32_t uNextSnrTempMeasTime_ms = ZERO;  /* For temperature.*/

/*===========================================================================
 * \brief Update sensor internal temperature as necessary.
 *
 * \param none
 * \param none
 * \return none
 * \remarks
 * ==========================================================================
 */
/* ===========================================================================
 * Name:	 UssCtrl_UpdateSnrIntTemperature
 * Remarks:  DD-ID: {6E7707A4-DBEC-4911-9A0A-42DB51CCD6B9}
 * Req.-ID: 13411731
 * ===========================================================================*/
void UssCtrl_UpdateSnrIntTemperature(void)
{
    bool_t Mode;

    Mode   =  UssCtrl_bIsSysInPlaybackMode();
    if (Mode == (bool_t)ME_FALSE) /* Playback mode*/
    {
        uint32_t uCurTime = US_GetTimeStampTimeMs();
        if (uCurTime > uNextSnrTempMeasTime_ms)
        {
            uint16_t uStatus = (uint16_t)UssSnrCmd_ReqSensorTempCmd(US_SnrCfg_F_Get_CfgSnrMap(US_ALL_POS));
            if (uStatus == (uint16_t)ME_OK)
            {
    #if UART_SUPPORTED
                cMELog_F_LogDebug_v("UssCtrl: Sensor Temperature requested, time = %d", uCurTime);
    #endif
                uNextSnrTempMeasTime_ms = uCurTime + US_D_SNR_TEMP_UPDATE_INTERVAL;
            }
            else
            {
                ;/*Do nothing */
            }
        }
    }
}
