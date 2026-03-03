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
/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

static uint32_t UssHsd_Adc_Raw_value[4];
static uint32_t Uss_Hsd_IntrRawStatus;
/* ===========================================================================*/
/* UssHsd_F_ReadADCValue.
* Brief: Store ADC value from FIFO to UssHsd_Adc_Raw_value
* \param: ChannelID
* \return: None
* \remarks  no remarks
*Req.-ID: 13473299
*Req.-ID: 13767883
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 UssHsd_F_ReadADCValue
 * Remarks:  DD-ID: {DE1DE662-90E2-4839-BCC2-19DF54A20AD4}
 * Req.-ID:
 * ===========================================================================*/
void UssHsd_F_ReadADCValue(uint8_t ChannelID)
{
    uint32_t        loopcnt, fifoData, fifoWordCnt, stepID;
    Uss_Hsd_IntrRawStatus = ADCGetIntrRawStatus(APP_ADC_MODULE);
    if(1 == ((ADC_IRQSTATUS_END_OF_SEQUENCE_MASK & Uss_Hsd_IntrRawStatus)>>BIT0))
    {
        fifoWordCnt = ADCGetFIFOWordCount(APP_ADC_MODULE, ADC_FIFO_NUM_0);
        for (loopcnt = 0U; loopcnt < fifoWordCnt; loopcnt++)
        {
            fifoData = ADCGetFIFOData(APP_ADC_MODULE, ADC_FIFO_NUM_0);
            stepID   = ((fifoData & ADC_FIFODATA_ADCCHNLID_MASK) >>
                    ADC_FIFODATA_ADCCHNLID_SHIFT);
            fifoData = ((fifoData & ADC_FIFODATA_ADCDATA_MASK) >>
                    ADC_FIFODATA_ADCDATA_SHIFT);
            switch(ChannelID)
            {
                case (uint8_t)Uss_Hsd_Channel_PWR_A:
                    switch(stepID)
                    {
                        case ADC_STEP_1:
                            /* Read FIFO data for HSD_USS_PWR_A_MON */
                            UssHsd_Adc_Raw_value[0] = fifoData;
                            break;

                        case ADC_STEP_4:
                            if(0 == (GPIOPinOutValueRead_v0(CSL_GPIO0_BASE, 14)))
                            {
                                /* Read FIFO data for HSD_USS_PWR_IS1_MON */
                                UssHsd_Adc_Raw_value[2] = fifoData;
                            }
                            break;

                        default:
                            break;
                    }
                    break;

                case (uint8_t)Uss_Hsd_Channel_PWR_B:
                    switch(stepID)
                    {
                        case ADC_STEP_2:
                            /* Read FIFO data for HSD_USS_PWR_B_MON */
                            UssHsd_Adc_Raw_value[1] = fifoData;
                            break;

                        case ADC_STEP_4:
                            if(1 == (GPIOPinOutValueRead_v0(CSL_GPIO0_BASE, 14)))
                            {
                                /* Read FIFO data for HSD_USS_PWR_IS1_MON */
                                UssHsd_Adc_Raw_value[3] = fifoData;
                            }
                            break;

                        default:
                            break;
                    }
                   break;

               default:
                   break;
            }
        }
    }
}
/* ===========================================================================*/
/* UssHsd_F_ADC_RawValueConversion.
* Brief: This function will convert value read from ADC into voltage and current
* \param: ChannelID
* \return: None
* \remarks  no remarks
* Req.-ID: 13389457
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 UssHsd_F_ADC_RawValueConversion
 * Remarks:  DD-ID: {9986A641-C47D-4cc5-8BF8-7BA11C2D1590}
 * Req.-ID:
 * ===========================================================================*/
void UssHsd_F_ADC_RawValueConversion(uint8_t ChannelID)
{
    uint32_t ADC_temp = 0U;
    switch(ChannelID)
    {
        case (uint8_t)Uss_Hsd_Channel_PWR_A:
            ADC_temp  = UssHsd_Adc_Raw_value[0] * (uint32_t) APP_ADC_REF_VOLTAGE  ;
            ADC_temp /= (uint32_t) APP_ADC_RANGE_MAX;
            ADC_temp *= ADC_VTG_CONV_FAC;
            Uss_HsdStateMachine[ChannelID].vVoltage = (uint16_t)ADC_temp;


            ADC_temp  = UssHsd_Adc_Raw_value[2] * (uint32_t) APP_ADC_REF_VOLTAGE  ;
            ADC_temp /= (uint32_t) APP_ADC_RANGE_MAX;
            ADC_temp *= 670U;
            ADC_temp /= 3000U;
            Uss_HsdStateMachine[ChannelID].vCurrent = (uint16_t)ADC_temp;
            break;

        case (uint8_t)Uss_Hsd_Channel_PWR_B:
            ADC_temp  = UssHsd_Adc_Raw_value[1] * (uint32_t) APP_ADC_REF_VOLTAGE  ;
            ADC_temp /= (uint32_t) APP_ADC_RANGE_MAX;
            ADC_temp *= ADC_VTG_CONV_FAC;
            Uss_HsdStateMachine[ChannelID].vVoltage = (uint16_t)ADC_temp;

            ADC_temp  = UssHsd_Adc_Raw_value[3] * (uint32_t) APP_ADC_REF_VOLTAGE  ;
            ADC_temp /= (uint32_t) APP_ADC_RANGE_MAX;
            ADC_temp *= 670U;
            ADC_temp /= 3000U;
            Uss_HsdStateMachine[ChannelID].vCurrent = (uint16_t)ADC_temp;
            break;

        default:
            break;
    }
}
/********************************* End of file ******************************/
