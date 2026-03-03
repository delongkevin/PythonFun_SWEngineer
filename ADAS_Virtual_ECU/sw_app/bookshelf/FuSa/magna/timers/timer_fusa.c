#include <stdio.h>
#include "PlatformDataTypes.h"
#include "timer_fusa.h"
#include "Os.h"
#include "ErrorManagerSatellite.h"
#include "ErrorManagerShared.h"
#include "app_log_Boot.h"
#include <inttypes.h>
#include <ti/drv/sciclient/sciclient.h>
#include <osal/osal_clock_user.h>


#define ENABLE_SAFETY_SIGNALLING    (1)
/*Commented -- Can be enabled in future -> #define ENABLE_UART_PRINTS */
/*------------------------- Macros & Defines -------------------------*/
#define MAX_U32                     (0xFFFFFFFFU)
#define MAX_U64                     (0xFFFFFFFFFFFFFFFFUL)
#define VALUE_ZERO                  (0x00000000u)
#define TIMER_FAULT_INVALID         (0xFFFFu)
#define GTC_MAX_READ_CNT            (10u)
#define SHIFT_BY_32BITS         	(32u)
#define DELAY_1US					(1u)

/*------------------------- Constructs -------------------------*/
typedef enum
{
    eTimer_MCU_Timer_0,
    eTimer_MCU_Timer_1,
    eTimer_MCU_Timer_2,
    eTimer_MCU_Timer_3,
    eTimer_MCU_Timer_4,
    eTimer_MCU_Timer_5,
    eTimer_MCU_Timer_6,
    eTimer_MCU_Timer_7,
    eTimer_MCU_Timer_8,
    eTimer_MCU_Timer_9,
    eTimer_Timer_0,
    eTimer_Timer_1,
    eTimer_Timer_2,
    eTimer_Timer_3,
    eTimer_Timer_4,
    eTimer_Timer_5,
    eTimer_Timer_6,
    eTimer_Timer_7,
    eTimer_Timer_8,
    eTimer_Timer_9,
    eTimer_Timer_10,
    eTimer_Timer_11,
    eTimer_Timer_12,
    eTimer_Timer_13,
    eTimer_Timer_14,
    eTimer_Timer_15,
    eTimer_Timer_16,
    eTimer_Timer_17,
    eTimer_Timer_18,
    eTimer_Timer_19,
    eTimer_GTC_Counter,
    MAX_FUSA_TIMER
}eTimers;

typedef enum
{
    eTimerStatus_Ok = 0,
    eTimerStatus_Init,
    eTimerStatus_Stuck,
    eTimerStatus_Drifted
}eTimer_Status;

typedef struct
{
    const uint8_t enabled;
    eTimer_Status status;
    uint32_t init_wait_counter;
    const uint32_t upper_register_address;
    const uint32_t lower_register_address;
    volatile uint64_t delta;
    volatile uint64_t last_timer_value;
    uint8_t stuck_counter;
    uint8_t drift_counter;
    const uint32_t debounce_counter;
    uint64_t lower_threshold;
    uint64_t upper_threshold;
    uint64_t current_timer_value;
    ldef_ErrorMgr_enErrorNo ErrMgr_Signal;
}sTimer_Context;

typedef union {
    uint32_t addr;
    uint32_t *ptr;
    uint64_t *ptr64;
} ptrCastUnionU32_t;

#define CDD_Safety_START_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"
/*------------------------- Global Variables -------------------------*/


static sTimer_Context Fusa_TimersInfo[MAX_FUSA_TIMER] =
{
    /* Enabled, Status, Init Wait, Upper Address, Lower Address, Delta Value, Last Value, Stuck Counter, Drift Counter, Debounce Counter, Lower Threshold, Upper Threshold, Current Timer Value,Error Manger Signal */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x4040003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_MCU_Timer_2TimerSyncCheck},  /* eTimer_MCU_Timer_0 */
    {TRUE,  eTimerStatus_Init, 100u, 0x00000000u, 0x4041003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000017674u,  0x000000000004635Eu, 0u, ldef_ErrorMgr_Error_SysIntFlt_MCU_Timer_2TimerSyncCheck},  /* eTimer_MCU_Timer_1 1_0 OS timer */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x4042003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_MCU_Timer_2TimerSyncCheck},  /* eTimer_MCU_Timer_2 */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x4043003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_MCU_Timer_2TimerSyncCheck},  /* eTimer_MCU_Timer_3 */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x4044003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_MCU_Timer_2TimerSyncCheck},  /* eTimer_MCU_Timer_4 */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x4045003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_MCU_Timer_2TimerSyncCheck},  /* eTimer_MCU_Timer_5 */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x4046003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_MCU_Timer_2TimerSyncCheck},  /* eTimer_MCU_Timer_6 */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x4047003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_MCU_Timer_2TimerSyncCheck},  /* eTimer_MCU_Timer_7 */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x4048003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_MCU_Timer_2TimerSyncCheck},  /* eTimer_MCU_Timer_8 */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x4049003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_MCU_Timer_2TimerSyncCheck},  /* eTimer_MCU_Timer_9 */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x0240003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_Main_Timer_2TimerSyncCheck_MainDomain}, /* eTimer_Timer_0 */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x0241003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_Main_Timer_2TimerSyncCheck_MainDomain}, /* eTimer_Timer_1 C7x Timer */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x0242003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_Main_Timer_2TimerSyncCheck_MainDomain}, /* eTimer_Timer_2 2_0 OS timer */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x0243003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_Main_Timer_2TimerSyncCheck_MainDomain}, /* eTimer_Timer_3 2_0 task timer */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x0244003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_Main_Timer_2TimerSyncCheck_MainDomain}, /* eTimer_Timer_4 2_1 OS timer */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x0245003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_Main_Timer_2TimerSyncCheck_MainDomain}, /* eTimer_Timer_5 2_1 task timer */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x0246003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_Main_Timer_2TimerSyncCheck_MainDomain}, /* eTimer_Timer_6 */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x0247003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_Main_Timer_2TimerSyncCheck_MainDomain}, /* eTimer_Timer_7  USS timer */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x0248003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_Main_Timer_2TimerSyncCheck_MainDomain}, /* eTimer_Timer_8 */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x0249003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_Main_Timer_2TimerSyncCheck_MainDomain}, /* eTimer_Timer_9 */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x024A003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_Main_Timer_2TimerSyncCheck_MainDomain}, /* eTimer_Timer_10 */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x024B003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_Main_Timer_2TimerSyncCheck_MainDomain}, /* eTimer_Timer_11 */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x024C003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_Main_Timer_2TimerSyncCheck_MainDomain}, /* eTimer_Timer_12 */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x024D003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_Main_Timer_2TimerSyncCheck_MainDomain}, /* eTimer_Timer_13 */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x024E003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_Main_Timer_2TimerSyncCheck_MainDomain}, /* eTimer_Timer_14 */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x024F003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_Main_Timer_2TimerSyncCheck_MainDomain}, /* eTimer_Timer_15 */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x0250003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_Main_Timer_2TimerSyncCheck_MainDomain}, /* eTimer_Timer_16 */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x0251003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_Main_Timer_2TimerSyncCheck_MainDomain}, /* eTimer_Timer_17 */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x0252003Cu, 0u, 0u, 0u, 0u, 25u, 0x0000000000000000u,  0xFFFFFFFFFFFFFFFFu, 0u, ldef_ErrorMgr_Error_SysIntFlt_Main_Timer_2TimerSyncCheck_MainDomain}, /* eTimer_Timer_18 */
    {FALSE, eTimerStatus_Init, 100u, 0x00000000u, 0x0253003Cu, 0u, 0u, 0u, 0u, 25u, 0x000000000001766Bu,  0x0000000000046341u, 0u, ldef_ErrorMgr_Error_SysIntFlt_Main_Timer_2TimerSyncCheck_MainDomain}, /* eTimer_Timer_19 */
    {TRUE,  eTimerStatus_Init, 100u, 0x00A9000Cu, 0x00A90008u, 0u, 0u, 0u, 0u, 25u, 0x00000000000F3AB4u,  0x00000000002DB01Eu, 0u, (ldef_ErrorMgr_enErrorNo)TIMER_FAULT_INVALID}             /* eTimer_GTC_Counter */   /* ToDo: Fault mapping to be updated to GTC fault */
};
#define CDD_Safety_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"

/*------------------------- Local Prototypes -------------------------*/
static eTimer_Status Timers_DeltaValueCheck(eTimers tmr_indx, uint64_t current_value);
static uint64_t Timers_ReadGTCCnt(void);

#define CDD_Safety_START_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* Safe read function for 64-bit GTC counter */
static uint64_t Timers_ReadGTCCnt(void)
{
	uint8_t timer_Cnt1 = 0u;
	uint8_t timer_Cnt2 = 0u;
    uint32_t gtc_hi_last = 0u;
    uint32_t gtc_lo_last = 0u;
    uint32_t hi1 = 0u;
    uint32_t lo = 0u;
    uint32_t hi2 = 0u;
	uint8_t flag = FALSE;
    ptrCastUnionU32_t lower_timer_value;
    ptrCastUnionU32_t upper_timer_value;
    uint64_t ret_timerCnt;
#ifdef ENABLE_UART_PRINTS
    uint32_t gtc_lo_fault = 0u;
    uint32_t gtc_hi_fault = 0u;
#endif

	/* Get last read count */
	gtc_hi_last = (uint32_t)(Fusa_TimersInfo[eTimer_GTC_Counter].last_timer_value >> SHIFT_BY_32BITS);
	gtc_lo_last = (uint32_t)(Fusa_TimersInfo[eTimer_GTC_Counter].last_timer_value);
    /* Copy timer register address */
    lower_timer_value.addr = Fusa_TimersInfo[eTimer_GTC_Counter].lower_register_address;
    upper_timer_value.addr = Fusa_TimersInfo[eTimer_GTC_Counter].upper_register_address;
	do
    {
        flag = FALSE;
        timer_Cnt1 = 0u;
        /* Patch from TI */
        do {
            hi1 = *upper_timer_value.ptr;
            lo  = *lower_timer_value.ptr;
            hi2 = *upper_timer_value.ptr;
            timer_Cnt1++;
        } while ((hi1 != hi2) && ((uint8_t)GTC_MAX_READ_CNT > timer_Cnt1));

#ifdef ENABLE_UART_PRINTS
        if(timer_Cnt1 > 1u)
        {
            APP_log(APP_LOG_ERR,"timer_Cnt1 : %d\n",\
            		timer_Cnt1);
        }
#endif

        /* Roll-over at upper count */
        if ((gtc_hi_last < hi1) &&
            (gtc_lo_last < lo))
        {
			/* Re-read count */
            flag = TRUE;
#ifdef ENABLE_UART_PRINTS
			/* Store Faulty count */
            gtc_lo_fault = lo;
            gtc_hi_fault = hi1 ;
#endif
            /* Add delay of 1us */
            osal_delay(DELAY_1US);
        }

        /* Roll-over at lower count */
        if ((gtc_hi_last == hi1) &&
            (gtc_lo_last > lo))
        {
			/* Re-read count */
            flag = TRUE;
#ifdef ENABLE_UART_PRINTS
			/* Store Faulty count */
            gtc_lo_fault = lo;
            gtc_hi_fault = hi1;
#endif
            /* Add delay of 1us */
            osal_delay(DELAY_1US);
        }

        timer_Cnt2++;

    }while (((uint8_t)TRUE == flag) && ((uint8_t)GTC_MAX_READ_CNT > timer_Cnt2));

#ifdef ENABLE_UART_PRINTS
	/* Print if Faulty count is detected */
    if(timer_Cnt2 > 1u)
    {
        APP_log(APP_LOG_ERR," 0x%08X%08X  0x%08X%08X 0x%08X%08X %d\n",\
                gtc_hi_last, gtc_lo_last, \
                gtc_hi_fault, gtc_lo_fault,
				\
                hi1, lo, timer_Cnt2);
    }
#endif
    /* Fill 64-bit count */
    ret_timerCnt = ((uint64_t)hi1 << SHIFT_BY_32BITS) | lo;

    return ret_timerCnt;
}
/*
 * Timers_SafetyChecks_MainFunction()
 *
 * Main background timer monitoring routine. Ensures timers are updating according to configured paramters.
 */
void Timers_SafetyChecks_MainFunction(void)
{
  /* DD-ID: {A5738702-3E30-4dee-868E-BA497CBFE8B2}*/
    uint8_t tmr_indx = 0;
    double GTC_delta_ms, mcu1_0_delta_ms;
    static ldef_ErrorMgr_stAddData error_param = {0u};
    volatile ptrCastUnionU32_t lower_timer_value;
    static volatile uint32_t gTimer_RunTimer = 0;

    SuspendAllInterrupts();

    for(tmr_indx = 0u; tmr_indx < (uint8_t)MAX_FUSA_TIMER; tmr_indx++)
    {
        /* Only compare enabled timers. */
        if (Fusa_TimersInfo[tmr_indx].enabled ==(uint8_t) TRUE)
        {
        	/* Grab current time compensating for roll-over and possible u32/u64 configurations. */
            lower_timer_value.addr = Fusa_TimersInfo[tmr_indx].lower_register_address;

            if(Fusa_TimersInfo[tmr_indx].upper_register_address != VALUE_ZERO)
            {
            	/* Get 64-bit GTC timer count in one read */
                Fusa_TimersInfo[tmr_indx].current_timer_value = Timers_ReadGTCCnt();
            }
            else
            {
                Fusa_TimersInfo[tmr_indx].current_timer_value = (uint64_t) *lower_timer_value.ptr;
            }
        }

    }
    ResumeAllInterrupts();

    for(tmr_indx = 0u; tmr_indx < (uint8_t)MAX_FUSA_TIMER; tmr_indx++)
    {
        /* Only compare enabled timers. */
        if (Fusa_TimersInfo[tmr_indx].enabled ==(uint8_t) TRUE)
        {

            /* Check the timer if past the initialization window. Presently faults latch. */
            if ((gTimer_RunTimer >= Fusa_TimersInfo[tmr_indx].init_wait_counter) &&
                (Fusa_TimersInfo[tmr_indx].status != eTimerStatus_Stuck) &&
                (Fusa_TimersInfo[tmr_indx].status != eTimerStatus_Drifted))
            {
                eTimer_Status current_status = Timers_DeltaValueCheck((eTimers)tmr_indx, Fusa_TimersInfo[tmr_indx].current_timer_value);

                /* Update the Error Counters */
                if(current_status == eTimerStatus_Stuck)
                {
                    Fusa_TimersInfo[tmr_indx].stuck_counter++;
                }
                else if(current_status == eTimerStatus_Drifted)
                {
                    Fusa_TimersInfo[tmr_indx].drift_counter++;
                }
                else
                {
                    Fusa_TimersInfo[tmr_indx].stuck_counter = 0;
                    Fusa_TimersInfo[tmr_indx].drift_counter = 0;
                }

                /* Check for faults w/ configured hysteresis */
                if(Fusa_TimersInfo[tmr_indx].stuck_counter >= Fusa_TimersInfo[tmr_indx].debounce_counter)
                {
                    Fusa_TimersInfo[tmr_indx].status = eTimerStatus_Stuck;
                }
                else if(Fusa_TimersInfo[tmr_indx].drift_counter >= Fusa_TimersInfo[tmr_indx].debounce_counter)
                {
                    Fusa_TimersInfo[tmr_indx].status = eTimerStatus_Drifted;
                }
                else
                {
                    /* Refresh */
                    Fusa_TimersInfo[tmr_indx].status = eTimerStatus_Ok;
                }

#if ENABLE_SAFETY_SIGNALLING
                if(((Fusa_TimersInfo[tmr_indx].status == eTimerStatus_Stuck) || (Fusa_TimersInfo[tmr_indx].status == eTimerStatus_Drifted))
                 &&(Fusa_TimersInfo[tmr_indx].ErrMgr_Signal != (ldef_ErrorMgr_enErrorNo)TIMER_FAULT_INVALID))
                {
                    error_param.AdditionalData[0] = tmr_indx;
                    error_param.AdditionalData[1] = (uint8_t) Fusa_TimersInfo[tmr_indx].status;
                    /* Report error to CAN msg */
                   f_Send_Dbg_SDLFault_CanTx((uint16)Fusa_TimersInfo[tmr_indx].ErrMgr_Signal);
                   (void)ErrorMgrSatellite_ReportErrorStatus(Fusa_TimersInfo[tmr_indx].ErrMgr_Signal, ldef_ErrorMgr_ErrorActive,(const ldef_ErrorMgr_stAddData *)&error_param);

#ifdef ENABLE_UART_PRINTS
                        APP_log(APP_LOG_ERR,"0x%08X%08X  0x%08X%08X  0x%08X%08X  0x%08X%08X \n",\
                        		(uint32_t)(Fusa_TimersInfo[eTimer_MCU_Timer_1].last_timer_value >> 32u), (uint32_t)(Fusa_TimersInfo[eTimer_MCU_Timer_1].last_timer_value & 0xFFFFFFFFu),\
								(uint32_t)(Fusa_TimersInfo[eTimer_MCU_Timer_1].current_timer_value >> 32u), (uint32_t)(Fusa_TimersInfo[eTimer_MCU_Timer_1].current_timer_value & 0xFFFFFFFFu),\
								(uint32_t)(Fusa_TimersInfo[eTimer_GTC_Counter].last_timer_value >> 32u), (uint32_t)(Fusa_TimersInfo[eTimer_GTC_Counter].last_timer_value & 0xFFFFFFFFu),\
								(uint32_t)(Fusa_TimersInfo[eTimer_GTC_Counter].current_timer_value >> 32u), (uint32_t)(Fusa_TimersInfo[eTimer_GTC_Counter].current_timer_value & 0xFFFFFFFFu));
#endif
                }
#endif
            }

            Fusa_TimersInfo[tmr_indx].last_timer_value = Fusa_TimersInfo[tmr_indx].current_timer_value;
        }
    }

    /* Check MCU1_0 and MCU3_1 OS timer against GTC timer */
    mcu1_0_delta_ms = (double)Fusa_TimersInfo[1].delta / TIMERS_SAFETY_MCU_TIMER_1_FREQ_HZ;
    GTC_delta_ms    = (double)Fusa_TimersInfo[30].delta / TIMERS_SAFETY_GTC_TIMER_FREQ_HZ;
#if ENABLE_SAFETY_SIGNALLING
    if ((mcu1_0_delta_ms > GTC_delta_ms * GTC_TIMER_ERROR_MAX_ALLOWANCE)
     || (mcu1_0_delta_ms < GTC_delta_ms * GTC_TIMER_ERROR_MIN_ALLOWANCE))
    {
        /* Report error to CAN msg */
        f_Send_Dbg_SDLFault_CanTx((uint16)Fusa_TimersInfo[1].ErrMgr_Signal);
        (void)ErrorMgrSatellite_ReportErrorStatus(Fusa_TimersInfo[1].ErrMgr_Signal, ldef_ErrorMgr_ErrorActive,(const ldef_ErrorMgr_stAddData *)&error_param);

#ifdef ENABLE_UART_PRINTS
        APP_log(APP_LOG_ERR," 0x%08X%08X  0x%08X%08X  0x%08X%08X  0x%08X%08X \n",\
        		(uint32_t)(Fusa_TimersInfo[eTimer_MCU_Timer_1].last_timer_value >> 32u), (uint32_t)(Fusa_TimersInfo[eTimer_MCU_Timer_1].last_timer_value & 0xFFFFFFFFu),\
        		(uint32_t)(Fusa_TimersInfo[eTimer_MCU_Timer_1].current_timer_value >> 32u), (uint32_t)(Fusa_TimersInfo[eTimer_MCU_Timer_1].current_timer_value & 0xFFFFFFFFu),\
				(uint32_t)(Fusa_TimersInfo[eTimer_GTC_Counter].last_timer_value >> 32u), (uint32_t)(Fusa_TimersInfo[eTimer_GTC_Counter].last_timer_value & 0xFFFFFFFFu),\
				(uint32_t)(Fusa_TimersInfo[eTimer_GTC_Counter].current_timer_value >> 32u), (uint32_t)(Fusa_TimersInfo[eTimer_GTC_Counter].current_timer_value & 0xFFFFFFFFu));
#endif
    }
    else
    {
        (void)ErrorMgrSatellite_ReportErrorStatus(Fusa_TimersInfo[1].ErrMgr_Signal, ldef_ErrorMgr_ErrorInactive,(const ldef_ErrorMgr_stAddData *)&error_param);
    }
#endif
    if(gTimer_RunTimer < MAX_U32)
    {
        gTimer_RunTimer++;
    }
}


/* Timers_DeltaValueCheck()
 *
 * Compares current timer value against configured parameters to ensure the value is landing within
 * an expected window. Returns true on failure.
 */
static eTimer_Status Timers_DeltaValueCheck(eTimers tmr_indx, uint64_t current_value)
{
  /* DD-ID: {B6C7A180-46C5-41b1-A4E9-D16D7A3710A5}*/
    eTimer_Status timer_status;
    uint64_t delta_time = 0;

    /* Check for counter rollover and calculate the elapsed time since last value */
    if(current_value < Fusa_TimersInfo[tmr_indx].last_timer_value)
    {
        if(Fusa_TimersInfo[tmr_indx].upper_register_address == VALUE_ZERO)
        {
            /* 32 bit Timer */
            delta_time = MAX_U32 - Fusa_TimersInfo[tmr_indx].last_timer_value;
        }
        else
        {
            /* 64 bit Timer */
            delta_time = MAX_U64 - Fusa_TimersInfo[tmr_indx].last_timer_value;
        }

        delta_time += current_value;
    }
    else
    {
        delta_time = current_value - Fusa_TimersInfo[tmr_indx].last_timer_value;
    }

    /* Save it for profiling */
    Fusa_TimersInfo[tmr_indx].delta = delta_time;

    /* Check for a stuck timer */
    if (current_value == Fusa_TimersInfo[tmr_indx].last_timer_value)
    {
        timer_status = eTimerStatus_Stuck;
    }
    /* Compare against thresholds */
    else if ((delta_time < Fusa_TimersInfo[tmr_indx].lower_threshold) || (delta_time > Fusa_TimersInfo[tmr_indx].upper_threshold))
    {
        timer_status = eTimerStatus_Drifted;
    }
    else
    {
        timer_status = eTimerStatus_Ok;
    }

    return timer_status;
}

#define CDD_Safety_STOP_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
