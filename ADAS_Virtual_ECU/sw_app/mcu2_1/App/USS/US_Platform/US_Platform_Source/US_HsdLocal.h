/*
 * US_HSD_Interface.h
 *
 */

#ifndef US_HSD_LOCAL_H_
#define US_HSD_LOCAL_H_

/*#include "US_ME_Typedefs_Global.h"*/
#include <ti/csl/src/ip/adc/V0/adc.h>
#include <ti/csl/tistdtypes.h>
/*#include "US_Hsd_Global.h"*/

typedef uint16_t HsdDebounceTimeInMs_Type;
typedef struct 
{
    uint8_t RetryCntSet;
    uint8_t RetryCntClr;
    uint8_t ThresholdLockSet;
    uint8_t ThresholdLockClr;
    HsdDebounceTimeInMs_Type ThresholdDebounceTimeSet;
    HsdDebounceTimeInMs_Type ThresholdDebounceTimeClr;
}HsdDiagErrConf_Type;

#define HSD_MAIN_BASE_TIME_MS            (10U)
#define HSD_TIME_CHECK_EXPIRE            (0U)

/**
 * Short to ground error detection configuration
*/
#if(US_FEATURE_HSD_FAULT_DET_SHORT_TO_GND == US_FEATURE_ON)
#define USS_HSD_PWR_STG_THRSH		 442U /* 442mA */
#define HSD_ERR_HYS_CURRENT_IN_mA_STG    (10) /*10mA*/
#define USS_HSD_PWR_STG_CLR_HYST	 353U
#define HSD_ERR_SET_DEBOUNCE_TIME_MS_STG (50U)
#define HSD_ERR_CLR_DEBOUNCE_TIME_MS_STG (50U)
#define HSD_ERR_SET_RETRY_CNT_STG        (10U)
#define HSD_ERR_CLR_RETRY_CNT_STG        (10U)
#endif
/**
 * Short to battery error detection configuration
*/
#define USS_HSD_PWR_STB_MAX               2379U
#define USS_HSD_PWR_STB_MIN			      1586U
#define HSD_ERR_SET_DEBOUNCE_TIME_MS_STB (50U)
#define HSD_ERR_CLR_DEBOUNCE_TIME_MS_STB (50U)
#define HSD_ERR_SET_RETRY_CNT_STB        (10U)
#define HSD_ERR_CLR_RETRY_CNT_STB        (10U)
#define HSD_ERR_HYS_VTG_IN_mV_STB        (20) /*0.020V*/

/**
 * voltage outoff error detection configuration
*/
#define USS_HSD_PWR_OOR_LOW 8000U /* 8V */
#define USS_HSD_PWR_OOR_MIN 8000U /* 8V */
#define HSD_ERR_SET_DEBOUNCE_TIME_MS_VTG_OOR_LOW (50U)
#define HSD_ERR_CLR_DEBOUNCE_TIME_MS_VTG_OOR_LOW (50U)
#define HSD_ERR_SET_RETRY_CNT_VTG_OOR_LOW        (10U)
#define HSD_ERR_CLR_RETRY_CNT_VTG_OOR_LOW        (10U)
#define HSD_ERR_HYS_VOLTAGE_IN_mV_VTG_OOR_LOW    (20) /*0.020V*/


/**
 * voltage outoff error detection configuration
*/
#define USS_HSD_PWR_OOR_HIGH 16500U /*16.5V */
#define USS_HSD_PWR_OOR_MAX 16000U  /*16V */
#define HSD_ERR_SET_DEBOUNCE_TIME_MS_VTG_OOR_HIGH (50U)
#define HSD_ERR_CLR_DEBOUNCE_TIME_MS_VTG_OOR_HIGH (50U)
#define HSD_ERR_SET_RETRY_CNT_VTG_OOR_HIGH        (10U)
#define HSD_ERR_CLR_RETRY_CNT_VTG_OOR_HIGH        (10U)
#define HSD_ERR_HYS_VOLTAGE_IN_mV_VTG_OOR_HIGH    (20) /*0.020V*/


/*TBD : Need to update the timeout values as per actual SRD, currently no values are present */
#define OUTPUTONCHECK_TIMEOUT 40U /*400msec = 10 *20*/ /*IPC message update frequency is 100 msec so de-bounce count is (IPC update freq) * 2*/
#define OUTPUTOFFCHECK_TIMEOUT 40U /*400msec = 10 *20*/ /*IPC message update frequency is 100 msec so de-bounce count is (IPC update freq) * 2*/
#define OUTPUT_ON_FAULT_TIMEOUT 40U  /*400msec = 10 *20*/ /*IPC message update frequency is 100 msec so de-bounce count is (IPC update freq) * 2*/
#define OUTPUT_OFF_FAULT_TIMEOUT 40U  /*400msec = 10 *20*/ /*IPC message update frequency is 100 msec so de-bounce count is (IPC update freq) * 2*/

/*VBAT within range 9-16 V*/
#define USS_HSD_PWR_MAX_ON_VTG    16000U  /*It should be VBAT higher limit i.e 16V*/
#define USS_HSD_PWR_A_MIN_ON_VTG  8892U /* 98.8% of vBAT lower limit i.e 9V*/
#define USS_HSD_PWR_B_MIN_ON_VTG  7893U /* 87.7% of vBAT lower limit i.e 9V*/
#define USS_HSD_PWR_ON_VTG 6000U /*Min voltage requirement for sensors to power on*/
#define USS_HSD_PWR_OOR_CLR_HYST_LH 8000U   /*10V hysteresis threshold Low to High transition*/
#define USS_HSD_PWR_OOR_CLR_HYST_HL 16000U   /*15V hysteresis threshold High to Low transition*/

/*Voltage Ranges for 'Open Circuit Failure' Errors*/
#define USS_HSD_OCF 8000U      /* 8V OPEN CIRCUIT FAILURE */
#define USS_HSD_OCF_CLR_HYST 8000U /* 8V HYSTERESIS FOR OPEN CIRCUIT FAILURE */

/*Current Ranges for 'Open circuit failure' Errors*/
#define USS_HSD_RAIL_CUR_MIN 54U /* 54 mA */
#define USS_HSD_RAIL_CUR_MAX 90U /* 90 mA */
#define USS_HSD_RAIL_CUR_HYST_MIN 54U /*60 mA hystersis threshold for open ckt failure recovery*/
#define USS_HSD_RAIL_CUR_HYST_MAX 90U /*85 mA hystersis threshold for open ckt failure recovery*/

typedef enum UssHsd_E_Pwr_En_Status_e
{
    UssHsd_Pwr_En_Low = 0,
    UssHsd_Pwr_En_High
}UssHsd_E_Pwr_En_Status_t;

typedef enum
{
	US_HSD_ERR_STATE_PASSIVE = 0U,
	US_HSD_ERR_STATE_ACTIVE,
	US_HSD_ERR_STATE_CONFIRM,
	US_HSD_ERR_STATE_UNDEFINED,
	US_HSD_ERR_STATE_MAX
}UsHsd_ErrState_Type;

typedef enum
{       
	US_HSD_ERR_ID_short_to_GND = 0,
	US_HSD_ERR_ID_voltage_OOR_Low,
	US_HSD_ERR_ID_Short_to_Bat,
	US_HSD_ERR_ID_voltage_OOR_High,
    US_HSD_ERR_ID_OpenCircuit,
	US_HSD_ERR_ID_MAX
}UsHsd_ErrId_Type;

#endif /*US_HSD_LOCAL_H_ */
