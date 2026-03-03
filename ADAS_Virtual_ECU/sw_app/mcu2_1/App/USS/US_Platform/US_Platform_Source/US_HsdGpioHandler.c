/**
 *  \file     CDD_HSD_MainFunc.c
 *
 *  \brief    
 *
 *
 **/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */



#include <stdint.h>
#include <stdio.h>
#include "US_HsdLocal.h"
#include "US_Hsd_Global.h"
#include <ti/csl/src/ip/gpio/V0/gpio.h>
#include <ti/csl/csl_gpio.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

extern void US_Com_ReqHsdPwrChannel_A(bool on);
extern void US_Com_ReqHsdPwrChannel_B(bool on);

/* ===========================================================================*/
/* HsdGpIoWriteCbk_ChannelA.
* Brief: Callback function to make PWR_EN_A pin HIGH or LOW depending on PinValue
* \param: PinValue
* \return: None
* \remarks  no remarks
* Req.-ID: 13473299 */
/* ========================================================================= */
/* ===========================================================================
 * Name:	 HsdGpIoWriteCbk_ChannelA
 * Remarks:  DD-ID: {FD855569-8174-42c4-A149-2470C0BF15DD}
 *  Req.-ID: 
 * ===========================================================================*/
void HsdGpIoWriteCbk_ChannelA(const uint8_t pinVal)
{
    US_Com_ReqHsdPwrChannel_A((bool)pinVal);
}
/* ===========================================================================*/
/* HsdGpIoWriteCbk_ChannelB.
* Brief: Callback function to make PWR_EN_B pin HIGH or LOW depending on PinValue
* \param: PinValue
* \return: None
* \remarks  no remarks
* Req.-ID: 13767883 */
/* ========================================================================= */
/* ===========================================================================
 * Name:	 HsdGpIoWriteCbk_ChannelB
 * Remarks:  DD-ID: {FD855569-8174-42c4-A149-2470C0BF15DD}
 *  Req.-ID: 
 * ===========================================================================*/
void HsdGpIoWriteCbk_ChannelB(const uint8_t pinVal)
{
   US_Com_ReqHsdPwrChannel_B((bool)pinVal);
}
/********************************* End of file ******************************/
