/*******************************************************************************
 * spi_test.c
 *******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
/**> DSI commands flags */


#include <stdio.h>
#include <stdint.h>

#include <csl_arch.h>
#include <soc.h>
#include <cslr.h>

#include <osal.h>

#include <board.h>
#include <UART.h>
#include <UART_stdio.h>
#include <sciclient.h>
#include <UART_stdio.h>
#include <SSM_Defs.h>                   
/* XDCtools Header files */
#include <ti/drv/sciclient/sciclient.h>

#include <ti/board/board.h>
#include <ti/board/src/j721s2_evm/include/board_clock.h>


#include <ti/csl/csl_gpio.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

#include <ti/drv/spi/soc/SPI_soc.h>
#include <ti/drv/spi/src/SPI_osal.h>
#include <ti/drv/spi/SPI.h>

#include <ti/csl/src/ip/timer/V1/timer.h>
#include <ti/osal/CacheP.h>
#include <ti/drv/udma/udma.h>

#include "US_ME_Typedefs_Global.h"
#include "US_Platform_Global.h"
#include "US_SnrDrv_Global.h"
#include "US_SysMgr_Global.h"
#include "US_HsdLocal.h"
#include "US_Hsd_Global.h"
#include "US_Diagnostic_Global.h"

#if(US_CSM_ENABLE == ME_TRUE)
#include "Us_Csm_If.h" 
#include "Us_Platform_CsmIf.h"
#endif
/*
 * Ring parameters
 */
/** \brief Number of ring entries - we can prime this much memcpy operations */
#define UDMA_TEST_APP_RING_ENTRIES      (1U)
/** \brief Size (in bytes) of each ring entry (Size of pointer - 64-bit) */
#define UDMA_TEST_APP_RING_ENTRY_SIZE   (sizeof(uint64_t))
/** \brief Total ring memory */
#define UDMA_TEST_APP_RING_MEM_SIZE     (UDMA_TEST_APP_RING_ENTRIES * \
                                         UDMA_TEST_APP_RING_ENTRY_SIZE)
/** \brief This ensures every channel memory is aligned */
#define UDMA_TEST_APP_RING_MEM_SIZE_ALIGN ((UDMA_TEST_APP_RING_MEM_SIZE + UDMA_CACHELINE_ALIGNMENT) & ~(UDMA_CACHELINE_ALIGNMENT - 1U))

/** \brief UDMA host mode buffer descriptor memory size. */
#define UDMA_TEST_APP_DESC_SIZE         (sizeof(CSL_UdmapCppi5HMPD))
/** \brief This ensures every channel memory is aligned */
#define UDMA_TEST_APP_DESC_SIZE_ALIGN   ((UDMA_TEST_APP_DESC_SIZE + UDMA_CACHELINE_ALIGNMENT) & ~(UDMA_CACHELINE_ALIGNMENT - 1U))
/* Macro to extract GPIO port number from the gpio pin configuration */
#define GPIO_GET_PORT_NUM1(gpioConfig) (((gpioConfig) & (0x0000FF00U)) >> 8)

/* \brief Value used to drive 0 on PT */
#define TIMER_PT_VALUE_0        (TIMER_TCLR_PT_PT_VALUE_0)

/* \brief Value used to drive 1 on PT */
#define TIMER_PT_VALUE_1        (TIMER_TCLR_PT_PT_VALUE_1 << \
                                 TIMER_TCLR_PT_SHIFT)


/**
 * \anchor Timer_TRG_Values
 * \name Values that can be passed to TIMERTRGConfigure as trgConfig.
 *  
**/
/* \brief No output trigger */
#define TIMER_TRG_NO_TRIGGER      (0 << TIMER_TCLR_TRG_SHIFT)

/* \brief Trigger output on overflow */
#define TIMER_TRG_OVERFLOW        (1 << TIMER_TCLR_TRG_SHIFT)

/* \brief Trigger on overflow and match */
#define TIMER_TRG_OVERFLOW_AND_MATCH    (2 << TIMER_TCLR_TRG_SHIFT)



#define GPIO_INT_ID                  (396U)
#define GPIO_INT_CORE_OFFSET         (4)
#define MAX_WAIT_DSI_INT             (30)

#define DCR_GPIO_INT_PRI_ADDR          (0xFF812C0)
#define SPI_DMA_CMP_INT1_PRI_ADDR      (0xFF81394) 
#define SPI_DMA_CMP_INT2_PRI_ADDR      (0xFF81398) 

#define IPC_INT1_PRI_ADDR              (0xFF813EC) 
#define IPC_INT2_PRI_ADDR              (0xFF813F0)   
#define IPC_INT3_PRI_ADDR              (0xFF813F4)

#define US_PLATFORM_MAX_RETRY_COUNT_SPI        (16)
#define US_PLATFORM_MAX_RETRY_COUNT_GPIO       (16)
#define US_PLATFORM_MAX_RETRY_COUNT_DSI3REFCLK (16)
#define  MAX_RE_TRY_CNT                        (16) 

#define  MAX_TIME_CNT                          (100u) 

/*
 * UDMA driver objects
 */
struct Udma_DrvObj      gUdmaDrvObj;
struct Udma_ChObj       gUdmaTxChObj;
struct Udma_ChObj       gUdmaRxChObj;
struct Udma_EventObj    gUdmaTxCqEventObj;
struct Udma_EventObj    gUdmaRxCqEventObj;

Udma_DrvHandle          gDrvHandle = NULL;

static uint8_t gTxRingMem[UDMA_TEST_APP_RING_MEM_SIZE_ALIGN] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gTxCompRingMem[UDMA_TEST_APP_RING_MEM_SIZE_ALIGN] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gUdmaTxHpdMem[UDMA_TEST_APP_DESC_SIZE_ALIGN] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gRxRingMem[UDMA_TEST_APP_RING_MEM_SIZE_ALIGN] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gRxCompRingMem[UDMA_TEST_APP_RING_MEM_SIZE_ALIGN] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gUdmaRxHpdMem[UDMA_TEST_APP_DESC_SIZE_ALIGN] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static SPI_dmaInfo gUdmaInfo;
static SPI_Handle   spi_handle;
/*static Event_Handle US_SnrDrvCom_Event */
extern EventP_Handle TaskEventHandle_BSW_QM_Events_Ev;

/*******************************************************************************
 * Internal functions definitions
 ******************************************************************************/



static volatile uint8_t DSI3_ch0_int = ZERO;
static volatile uint8_t DSI3_ch1_int = ZERO;
static volatile uint8_t DSI3_int = ZERO;
static volatile uint8_t DMA_int = ZERO;

static uint8_t SPI_Snd_Dev,*SPI_Snd_Data;
static uint16_t SPI_InLen,SPI_OutLen;
typedef uint16_t hw_rev_t;

#if(US_CSM_ENABLE == ME_TRUE)
static UsCsm_LocalStateId_Type LocalStateId_Platform = US_CSM_LOCAL_STATE_UN_INIT;
#endif

static uint8_t Us_Platform_Gpio_Init(void);
static uint8_t Us_Platform_Dsi3RefClk_Init(void);
static uint8_t Us_Platform_Spi_Init(void);
extern void US_Clr_Transceiver_Flag(void);
extern uint8_t US_DSI3Drv_GetCurBusFlag(uint8_t dev);

#if 0
/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] =
{

  /* Input pin with interrupt enabled */
    GPIO_DEVICE_CONFIG(0u, 18u) |
    GPIO_CFG_IN_INT_FALLING | GPIO_CFG_INPUT,
	
    /* Input pin with interrupt enabled */
    GPIO_DEVICE_CONFIG(0u, 19u) |
    GPIO_CFG_IN_INT_FALLING | GPIO_CFG_INPUT,
	
    /* Input pin with interrupt enabled */
    GPIO_DEVICE_CONFIG(0u, 31u) |
    GPIO_CFG_IN_INT_FALLING | GPIO_CFG_INPUT

};

/* GPIO Driver call back functions */
GPIO_CallbackFxn gpioCallbackFunctions[] =
{
    NULL,
    NULL,
    NULL
};

/* GPIO Driver configuration structure */
GPIO_v0_Config GPIO_v0_config =
{
    gpioPinConfigs,
    gpioCallbackFunctions,
    sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
    sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
#ifdef __TI_ARM_V7R4__
    0x8U
#else
#if defined(__C7100__)
    0x01U
#else
    0x20U
#endif
#endif
};

#endif

void LED_output(uint32_t value)
{
    (void)value;
/*comment out GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE, 37, value); */
}


#if((US_D_CUR_PLATFORM == US_D_PLATFORM_FISKER)||((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS))
void US_SPIDMA_ByEvent(uint8_t dev,uint8_t* Data,uint16_t inLen,uint16_t outLen)
{
    SPI_Snd_Dev = dev;
	SPI_Snd_Data = Data;
	SPI_InLen = inLen;
	SPI_OutLen = outLen;
    (void)EventP_post(TaskEventHandle_BSW_QM_Events_Ev, EventP_ID_02);
}
#endif
void dsi_spi_DMA_ISR(SPI_Handle handle, SPI_Transaction *transaction)
{
    (void)transaction;
    (void)handle;
     /*comment out EventP_post(TaskEventHandle_BSW_QM_Events_Ev, EventP_ID_00); */
	   US_SnrDrvCom_F_SPIDMACall(US_DSI3_DEV0);
   /*comment out led++; */
   /*LED_output((led>>8)&1);    change every 256 times */
}

static uint32_t   device_instance = 0u;
static SPI_Params params = {
        .transferMode = SPI_MODE_CALLBACK,   /*SPI_MODE_CALLBACK,          SPI_MODE_CALLBACK,         SPI_MODE_CALLBACK,   SPI_MODE_BLOCKING,SPI_MODE_CALLBACK, */
        .transferTimeout = 100000, /*SemaphoreP_WAIT_FOREVER, */
        .transferCallbackFxn =dsi_spi_DMA_ISR,   /*comment out dsi_spi_DMA_ISR,        dsi_spi_DMA_ISR,       dsi_spi_DMA_ISR,    NULL, */
        .mode = SPI_MASTER,
        .bitRate = 1846000U,
        .dataSize = 16,
        .frameFormat = SPI_POL0_PHA1,
    };
	
#if 0
/**> Wakeup GPIO pinmux data */
static pinmuxPerCfg_t gMain_WakeupgpioPinCfg[] = {
    {
        /* (E19) PIN_MCU_OSPI0_CSN1.WAKEUP_GPIO0_28 */ 
        PIN_MCU_OSPI0_CSN1, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION))
    },
	{
        /* (AE2) PIN_MCU_OSPI1_CSN1.WAKEUP_GPIO0_37 */
        PIN_MCU_OSPI1_CSN1, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION))
    },

    {PINMUX_END}
};
#endif
	
/**> GPIO0 pinmux data */
static pinmuxPerCfg_t gMain_gpio0PinCfg[] = {
	
    {
        /* (V23) PIN_GPIO0_11 USS_RFC*/
        PIN_GPIO0_11, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {
        /* (AB27) PIN_MCASP0_AXR2.GPIO0_18 USS_DCR_A(1B)*/
        PIN_MCASP0_AXR2, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {
        /* (V27) PIN_MCASP1_AXR1.GPIO0_19 USS_DCR_B(2B)*/
        PIN_MCASP1_AXR1, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {
        /* (W27) PIN_MCASP1_AXR2.GPIO0_20 USS_RESET*/
        PIN_MCASP1_AXR2, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION))
    },

    {PINMUX_END}
};

/**> TIMER1 pinmux data */
static pinmuxPerCfg_t gMain_timer0PinCfg[] = {
    {
        /* (V6) PIN_TIMER_IO1 */
        PIN_TIMER_IO0, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};
/**> TIMER1 pinmux data */
static pinmuxPerCfg_t gMain_timer1PinCfg[] = {
    {
        /* (V5) PIN_TIMER_IO1 */
        PIN_TIMER_IO1, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};


/**> MAIN-SPI0 pinmux data */
static pinmuxPerCfg_t gMain_spi0PinCfg[] = {
    {
        PIN_SPI0_D0, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION))
    },
    {
        PIN_SPI0_D1, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {
        PIN_SPI0_CS0, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION))
    },
    {
        PIN_SPI0_CLK, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION))
    },

    {PINMUX_END}
};

/**> DSI transceiver pinmux data */
static pinmuxModuleCfg_t gDsiPinCfg0[] = {
    {0, TRUE, gMain_spi0PinCfg},
    {1, TRUE, gMain_timer0PinCfg},
    {2, TRUE, gMain_gpio0PinCfg},
    {PINMUX_END},
};
/**> DSI transceiver pinmux data */
static pinmuxModuleCfg_t gDsiPinCfg1[] = {
    {0, TRUE, gMain_spi0PinCfg},
    {1, TRUE, gMain_timer1PinCfg},
    {2, TRUE, gMain_gpio0PinCfg},
    {PINMUX_END},
};
#if 0
/**> DSI transceiver pinmux data */
static pinmuxModuleCfg_t gLEDPinCfg[] = {
    {0, TRUE, gMain_WakeupgpioPinCfg},
    {PINMUX_END},
};
#endif
/**> Global pinmux data */
static pinmuxBoardCfg_t gDsiPinmuxDataInfo0[] = {
    {0, gDsiPinCfg0},
    {PINMUX_END}
};
/**> Global pinmux data */
static pinmuxBoardCfg_t gDsiPinmuxDataInfo1[] = {
    {0, gDsiPinCfg1},
    {PINMUX_END}
};
#if 0
/**> Global pinmux data */
static pinmuxBoardCfg_t gLEDPinmuxDataInfo[] = {
    {0, gLEDPinCfg},
    {PINMUX_END}
};
#endif
Udma_DrvHandle MCSPIApp_udmaInit(SPI_v1_HWAttrs *cfg)
{
    int32_t         retVal = UDMA_SOK;
    Udma_InitPrms   initPrms;
    uint32_t        instId;

    if (gDrvHandle == NULL)
    {
        /* UDMA driver init */
#if defined (SOC_AM64X)
        /* Use Block Copy DMA instance for AM64x */
        instId = UDMA_INST_ID_BCDMA_0;
#else
        /* Use MCU NAVSS for MCU domain cores. Rest cores all uses Main NAVSS */
#if defined (BUILD_MCU1_0) || defined (BUILD_MCU1_1)
        instId = UDMA_INST_ID_MCU_0;
#else
        instId = UDMA_INST_ID_MAIN_0;
#endif
#endif

        (void)UdmaInitPrms_init(instId, &initPrms);
        retVal = Udma_init(&gUdmaDrvObj, &initPrms);
        if(UDMA_SOK == retVal)
        {
            gDrvHandle = &gUdmaDrvObj;
        }
        else
        {
            ;/* No Action */
        }
    }
    else
    {
        ;/* No Action */
    }

    if(gDrvHandle != NULL)
    {
        gDrvHandle = &gUdmaDrvObj;

        gUdmaInfo.txChHandle     = (void *)&gUdmaTxChObj;
        gUdmaInfo.rxChHandle     = (void *)&gUdmaRxChObj;
        gUdmaInfo.txRingMem      = (void *)&gTxRingMem[0];
        gUdmaInfo.cqTxRingMem    = (void *)&gTxCompRingMem[0];
        gUdmaInfo.rxRingMem      = (void *)&gRxRingMem[0];
        gUdmaInfo.cqRxRingMem    = (void *)&gRxCompRingMem[0];
        gUdmaInfo.txHpdMem       = (void *)&gUdmaTxHpdMem[0];
        gUdmaInfo.rxHpdMem       = (void *)&gUdmaRxHpdMem[0];
        gUdmaInfo.txEventHandle  = (void *)&gUdmaTxCqEventObj;
        gUdmaInfo.rxEventHandle  = (void *)&gUdmaRxCqEventObj;
        cfg->dmaInfo             = &gUdmaInfo;
    }
    else
    {
       /*comment out  UART_printf("MCSPIApp_udmaInit:  Udma_init failed with error code: %d\n", retVal); */
    }

    return (gDrvHandle);
}

/*
 * Utility function which converts a local GEM L2 memory address
 * to global memory address.
 */
static uintptr_t l2_global_address (uintptr_t addr)
{
#if defined(SOC_K2H) || defined(SOC_K2K) || defined(SOC_K2L) || defined(SOC_K2E) || defined(SOC_K2G) || defined(SOC_C6678) || defined(SOC_C6657)
#ifdef _TMS320C6X
    uint32_t corenum;

    /* Get the core number. */
    corenum = CSL_chipReadReg (CSL_CHIP_DNUM);

    /* Compute the global address. */
    return (addr + (0x10000000 + (corenum * 0x1000000)));
#else
    return addr;
#endif
#else
    return addr;
#endif
}


/**
 * \brief   Get current time in usec (since core start-up)
 */
uint64_t get_timestamp_us(void)
{
    
	return TimerP_getTimeInUsecs();
	
}


/* ========================================================================== */
/*                      Internal Function Definitions                         */
/* ========================================================================== */
static inline int32_t TimerWaitForWrite(uint32_t reg, uint32_t baseAddr)
{
    int32_t          retVal = CSL_PASS;
    volatile uint32_t exit_count = (uint32_t) 0U;
    uint32_t step_size           = (uint32_t) 1U;

    if (0U != (HW_RD_FIELD32(baseAddr + TIMER_TSICR, TIMER_TSICR_POSTED)))
    {
        while ((uint32_t) 0U != (reg & TIMERWritePostedStatusGet(baseAddr)))
        {
             exit_count += step_size;
            /* Do nothing - Busy wait,
             * quit the loop if posted transations are not complete 
             * by one full cycle of counting
             * This check and break prevents getting stuck in the loop
             */
             if (exit_count == 0U)
             {
                retVal = CSL_ETIMEOUT;
                break;
             }
             else
             {
                ;/* No Action */
             }
        }
    }
    else
    {
        ;/* No Action */
    }
    return (retVal);
}


static int32_t TIMERTRGConfigure(uint32_t baseAddr, uint32_t trgCfg)
{
    int32_t retVal = CSL_EBADARGS;

    if (baseAddr != (uint32_t)(0u))
    {
        if ((trgCfg == ((uint32_t) (TIMER_TRG_NO_TRIGGER)))         ||                      
            (trgCfg == ((uint32_t) (TIMER_TRG_OVERFLOW)))         ||                                 
            (trgCfg == ((uint32_t) (TIMER_TRG_OVERFLOW_AND_MATCH))))                   
        {
            /* Wait for previous write to complete */
            (void)TimerWaitForWrite(TIMER_WRITE_POST_TCLR, baseAddr);

            /* Clear the TRG field of TCLR */
            HW_WR_FIELD32(baseAddr + TIMER_TCLR,
                          TIMER_TCLR_TRG,
                          TIMER_TCLR_TRG_TRG_VALUE_0X0);

            /* Wait for previous write to complete */
            (void)TimerWaitForWrite(TIMER_WRITE_POST_TCLR, baseAddr);

            /* Write to the gpoCfg field of TCLR */
            HW_WR_FIELD32(baseAddr + TIMER_TCLR,
                          TIMER_TCLR_TRG,
                          trgCfg >> TIMER_TCLR_TRG_SHIFT);

            {
                (void)TimerWaitForWrite(TIMER_WRITE_POST_TCLR, baseAddr);
                /*comment out UART_printf("trgCfg=%X, reg=%X\n", trgCfg, *(uint32_t*)(uintptr_t)(baseAddr+TIMER_TCLR)); */
            }
            
            retVal = CSL_PASS;
        }
        else
        {
            ;/* No Action */
        }
    }
    else
    {
        ;/* No Action */
    }
    return (retVal);
}
static int32_t TIMERPTConfigure(uint32_t baseAddr, uint32_t ptCfg)
{
    int32_t retVal = CSL_EBADARGS;

    if (baseAddr != (uint32_t)(0u))
    {
        if ((ptCfg == ((uint32_t) (TIMER_PT_VALUE_0)))         ||
            (ptCfg == ((uint32_t) (TIMER_PT_VALUE_1))))
        {
            /* Wait for previous write to complete */
            (void)TimerWaitForWrite(TIMER_WRITE_POST_TCLR, baseAddr);

            /* Clear the TP_CFG field of TCLR */
            HW_WR_FIELD32(baseAddr + TIMER_TCLR,
                          TIMER_TCLR_PT,
                          TIMER_TCLR_PT_PT_VALUE_0);

            /* Wait for previous write to complete */
            (void)TimerWaitForWrite(TIMER_WRITE_POST_TCLR, baseAddr);

            /* Write to the gpoCfg field of TCLR */
            HW_WR_FIELD32(baseAddr + TIMER_TCLR,
                          TIMER_TCLR_PT,
                          ptCfg >> TIMER_TCLR_PT_SHIFT);
            retVal = CSL_PASS;
        }
        else
        {
            ;/* No Action */
        }
    }
    else
    {
        ;/* No Action */
    }
    return (retVal);
}


/**
 * \brief   Configure timer for DSI3_CLK pin
 */
static int32_t dsi_clock_config(hw_rev_t board,uint32_t freq)
{
    uint32_t    baseAddress = (uint32_t)CSL_TIMER7_CFG_BASE;
    int32_t     cnt,status = CSL_PASS;

    if (freq != 0u)
    {
        uint64_t    clk;
        uint32_t    val = ~0U - ((125000000u) / freq - 1);   
        
        uint8_t   i;

        /* ...map TIMERIO7 pad to be driven by TIMER7 */
        CSL_main_ctrl_mmr_cfg0Regs *regs = (CSL_main_ctrl_mmr_cfg0Regs *)(uintptr_t)CSL_CTRL_MMR0_CFG0_BASE;

        /* ...unlock partition #1 access */
        regs->LOCK1_KICK0 = 0x68EF3490u;
        regs->LOCK1_KICK1 = 0xD172BC5Au;
 		cnt = 0;
        while (((regs->LOCK1_KICK0 & (uint32_t)0x1u) == 0u)&&(cnt < (int32_t)MAX_TIME_CNT))
		{
			TaskP_sleep(1);
		    cnt++;
		}
        if((regs->LOCK1_KICK0 & 0x1u) == 0u)
		{
        	status =  (int32_t)DIAG_FLAG_ECU_DSI_CLOCK_INITIAL_ERR;
		} 
        else
        {
            ;/* No Action */
        }
      /*comment out TRACE(1, _b("partition #1 unlocked: %X"), regs->TIMERIO1_CTRL); */

        /* ...TIMERIO7 is driven by TIMER1 */
        if(status == CSL_PASS)
		{
	        if(board == 0u)
			{
				regs->TIMERIO1_CTRL = 7;
	        }
			else if(board == 1u)
			{
				regs->TIMERIO0_CTRL = 7;
			}
else{ /*empty */}
        /* ...lock partition #1? */
/*comment out regs->LOCK1_KICK0 = 0x0; */

     /*comment out TRACE(1, _b("TIMERIO7_CTRL=%x"), regs->TIMERIO1_CTRL); */

	        regs->LOCK2_KICK0 = 0x68EF3490u;
	        regs->LOCK2_KICK1 = 0xD172BC5Au;
			cnt = 0;
  	       while (((regs->LOCK2_KICK0 & (uint32_t)0x1u) == 0u)&&(cnt < (int32_t)MAX_TIME_CNT)) 
		   {
			TaskP_sleep(1);
		    cnt++;
		   }
		   if((regs->LOCK2_KICK0 & 0x1u) == 0u)
		   {
       	      status =  DIAG_FLAG_ECU_DSI_CLOCK_INITIAL_ERR;
		   }
           else
           {
            ;/* No Action */
           }
        }
        else
        {
            ;/* No Action */
        }
        if(status == CSL_PASS)
		{
	        regs->TIMER7_CLKSEL = 0x2;
/*comment out regs->LOCK2_KICK0 = 0x0; */
        
    /*comment out TRACE(1, _b("TIMER7-CLKSEL: %X"), regs->TIMER7_CLKSEL); */

	        for (i = 0u; i < THREE; i++)
 	       {
	            if ((status =Sciclient_pmGetModuleClkFreq(TISCI_DEV_TIMER7, i, &clk, SCICLIENT_SERVICE_WAIT_FOREVER)) == 0)
	            {
              
 	            }
                else
                {
                    ;/* No Action */
                }
 	       }
           if(status == CSL_PASS)
		   {
	          (void)TIMERReset(baseAddress);
	          status = TIMERModeConfigure(baseAddress, TIMER_AUTORLD_NOCMP_ENABLE);
		   }
           else
           {
            ;/* No Action */
           }
		}
        else
        {
            ;/* No Action */
        }
        if(status == CSL_PASS)
        {
          status = TIMERTRGConfigure(baseAddress, TIMER_TRG_OVERFLOW);    
        }
        else
        {
            ;/* No Action */
        }
     /* TODO The two timer apis are not defined in 8.2. */		

         if(status == CSL_PASS)
        {
            status = (int32_t)TIMERPTConfigure(baseAddress, (uint32_t)TIMER_PT_VALUE_1);
        }
        else
        {
            ;/* No Action */
        }
 
       if(status == CSL_PASS)
        {
		     status = TIMERGPOConfigure(baseAddress, TIMER_GPO_CFG_0);
        }
        else
        {
            ;/* No Action */
        }
 
       if(status == CSL_PASS)
        {
		     status = TIMERReloadSet(baseAddress, val);
        }
        else
        {
            ;/* No Action */
        }
 
       if(status == CSL_PASS)
        {
		     status = TIMERCounterSet(baseAddress, val);
        }
        else
        {
            ;/* No Action */
        }
 
        if(status == CSL_PASS)
        {
		     status = TIMEREnable(baseAddress);
        }
        else
        {
            ;/* No Action */
        }
 
     }
    else
    {
        status = TIMERReset(baseAddress);
     }
    return status;
}
#if 0
int32_t appSetI2cExpPinDir(uint8_t exp_id, uint8_t pin, uint8_t dir, uint8_t val)
{
    int32_t status = -1;
    uint8_t cmdPrm[CMD_PARAM_SIZE];

    /*comment out  appLogPrintf("ISS: Set pin %d to %d\n", pin, val); */

    memset(cmdPrm, 0, CMD_PARAM_SIZE);

    memcpy(cmdPrm, &exp_id, 1);
    memcpy(cmdPrm + 1, &pin, 1);
    memcpy(cmdPrm + 2, &dir, 1);
    memcpy(cmdPrm + 3, &val, 1);

    status = appRemoteServiceRun(
        APP_IPC_CPU_MCU2_0 ,
        IMAGE_SENSOR_REMOTE_SERVICE_NAME,
        IM_SENSOR_CMD_I2C_EXP_SET_DIR,
        (void*)cmdPrm,
        CMD_PARAM_SIZE,
        0
    );

    if(status == 0)
    {
        /*comment out  appLogPrintf("ISS: Set pin done !!!\n"); */
    }
    else
    {
      /*comment out appLogPrintf("ISS: Set pin failed !!!\n"); */
    }

    return status;
}
#endif
/**
 * \brief   USS0 device setup function
 */

uint8_t US_CheckUSSPower(void);
void US_TurnOnUSSPower(bool on);
/* extern "C" void SigMgr_PpSR_State_MCU2_State_2_0_Get(SSM_2_0_CoreStatus *data); */ /* Header file included for this, to remove QAC parse error */


/* ===========================================================================*/
/**Port_E_ISR1.
* used to process command from cmd queue.
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_DSI3_Check_INTB_State
 * Remarks:  DD-ID: 
 * ===========================================================================*/
uint8_t US_DSI3_Check_INTB_State(void)
{
    
	uint32_t PortInput;

	PortInput = GPIOPinRead_v0(CSL_GPIO0_BASE, 31u);                 

 	return (uint8_t)(PortInput & 0xffu);
}

/* ===========================================================================*/
/**US_CheckDSI3Ready.
* used to Check if DSI3 is ready.
* \param None
* \return True if ready
* \remarks  no remarks
*/
/* ========================================================================= */
/* ===========================================================================
 * Name:	 US_CheckDSI3Ready
 * Remarks:  DD-ID: {83C5BD53-D274-4e47-8E26-0B8E80CED558}
 * Req.-ID: 13473273
 * ===========================================================================*/
uint8_t US_CheckDSI3Ready(void)
{
   return (uint8_t)((GPIOPinRead_v0(CSL_GPIO0_BASE, 11))&0xffu);     
}
/* ===========================================================================*/
/**US_Reset_DSI3Tranceiver.
* used to DSI3 Transceiver.
* \param None
* \return void
* \remarks  no remarks
*/
/* ========================================================================= */

/* ===========================================================================
 * Name:	 US_Reset_DSI3Tranceiver
 * Remarks:  DD-ID: 
 * ===========================================================================*/
void US_Reset_DSI3Tranceiver(void)
{
	    GPIOPinWrite_v0(CSL_GPIO0_BASE, 20, GPIO_PIN_LOW);   /*Reset pin to low */
}
/* ===========================================================================
 * Name:	 US_Release_Reset_DSI3Tranceiver
 * Remarks:  DD-ID: 
 * ===========================================================================*/
void US_Release_Reset_DSI3Tranceiver(void)
{
        GPIOPinWrite_v0(CSL_GPIO0_BASE, 20, GPIO_PIN_HIGH);    /*Reset pin to High */
}

/**
 * \brief 
 * 
 */
void clearDSIISR(void)
{
	DSI3_ch0_int = ZERO;
	DSI3_ch1_int = ZERO;
        DSI3_int = ZERO;
}

/* ===========================================================================*/
/**US_DSI3_SPI_Drv_CH0_ISR.
* used to process interrupt of ch0.
* \param none

* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */
static void US_DSI3Drv_CH0_ISR(void)
{

	uint32_t gpioIntStatus;
	uint16_t cnt,status = ME_OK;
		        /* Find out which pins have their interrupt flags set */
		cnt = ZERO;
	do{
        GPIOIntrStatusMask_v0(CSL_GPIO0_BASE, 0, &gpioIntStatus);        
        gpioIntStatus &= (1u<<(18u % GPIO_NUM_PINS_PER_BANK)) | (1u<<(19u% GPIO_NUM_PINS_PER_BANK));
        /* Clear all the set bits at once */
        GPIOIntrClearMask_v0(CSL_GPIO0_BASE, 0, gpioIntStatus);
        if((gpioIntStatus & (1u<<(18u % GPIO_NUM_PINS_PER_BANK))) != ZERO)
        {
                     US_DSI3Drv_SetCurBusFlag(US_DSI3_DEV0,BIT0);
        } 
        else
        {
            ;/* No Action */
        }  
        if((gpioIntStatus & (1u<<(19u% GPIO_NUM_PINS_PER_BANK))) != ZERO)
        {
           US_DSI3Drv_SetCurBusFlag(US_DSI3_DEV0,BIT1);
        } 
        else
        {
            ;/* No Action */
        }  
        DSI3_ch0_int ++;
	    cnt++;

    	 if(US_DSI3Drv_GetCurBusFlag(US_DSI3_DEV0) != ZERO)
	     {
		   status = US_SnrDrvCom_F_SPIDCRProcess(US_DSI3_DEV0);
		}
        else
        {
            ;/* No Action */
        }
	}while((status !=(uint16_t) ME_OK)&&(cnt < (uint16_t)MAX_WAIT_DSI_INT));
	if(status !=(uint16_t) ME_OK)
	{
           (void)EventP_post(TaskEventHandle_BSW_QM_Events_Ev, EventP_ID_01);
	}
    else
    {
        ;/* No Action */
    }

}
/* ===========================================================================*/
/**US_DSI3_SPI_Drv_CH1_ISR.
* used to process interrupt ch1.
* \param none
* \return no returns

* \remarks  no remarks
*/
/* ========================================================================= */
uint8_t US_get_ch_ISR(int chn)
{
   if(chn == 0)
    {
      return DSI3_ch0_int;
    }
    else
   {
      return DSI3_ch1_int;
    }
}

void US_DSI3Drv_CH1_ISR(void)
{
 	DSI3_ch1_int ++;
       /*comment out Event_post(TaskEventHandle_BSW_QM_Events_Ev, Event_Id_02); */

}
/* ===========================================================================*/
/**US_SnrDrvCom_F_SPITask function.
* used to process GPIO interrupt and DMA complete interrupt.
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */
volatile uint32_t DSI3_Ch0_Ready, DSI3_Ch1_Ready;
void US_USIntDeferProcessTask(uint32_t events)
{
	 
 	 uint32_t gpioIntStatus;
        if(UssMgr_eGetSysState() != SYSMGR_SYS_INIT)
          {
            /*comment out events = Event_pend(TaskEventHandle_BSW_QM_Events_Ev, Event_Id_NONE, Event_Id_00 + Event_Id_01, BIOS_WAIT_FOREVER); */
            if((events & EventP_ID_00)!= ZERO)
            {
  
               US_SnrDrvCom_F_SPIDMACall(US_DSI3_DEV0);              /*DMA complete interrupt process */
            }
            else
            {
                ;/* No Action */
            }
            if((events & EventP_ID_01)!= ZERO)                                 /*DCR1B/DCR2B interrupt process */
            {                                
                
               GPIOIntrStatusMask_v0(CSL_GPIO0_BASE, 0, &gpioIntStatus);
               gpioIntStatus &= (1u<<(18u % GPIO_NUM_PINS_PER_BANK)) | (1u<<(19u% GPIO_NUM_PINS_PER_BANK));
 
               /* Clear all the set bits at once */
               GPIOIntrClearMask_v0(CSL_GPIO0_BASE, 0, gpioIntStatus);
               if((gpioIntStatus & (1u<<(18u % GPIO_NUM_PINS_PER_BANK))) != ZERO)
               {
                      US_DSI3Drv_SetCurBusFlag(US_DSI3_DEV0,BIT0);
               } 
               else
               {
                ;/* No Action */
               }  
               if((gpioIntStatus & (1u<<(19u% GPIO_NUM_PINS_PER_BANK))) != ZERO)
               {
                   US_DSI3Drv_SetCurBusFlag(US_DSI3_DEV0,BIT1);
                } 
                else
                {
                    ;/* No Action */
                }  
              
    	       if(US_DSI3Drv_GetCurBusFlag(US_DSI3_DEV0) != ZERO)
	           {
                  (void) US_SnrDrvCom_F_SPIDCRProcess(US_DSI3_DEV0); 
			   }
               else
               {
                ;/* No Action */
               }
            }
            else
            {
                ;/* No Action */
            }
           if((events & EventP_ID_02) != ZERO)                                 /*DCR1B/DCR2B interrupt process */
            {                                
               US_SnrDrvCom_F_SendCRM_ByEvent(SPI_Snd_Dev,SPI_Snd_Data,SPI_InLen,SPI_OutLen);
			}
            else
            {
                ;/* No Action */
            }
          }
          else
          {
            US_Sleep(5);
          }

}


/* ===========================================================================*/
/**US_DSI3Drv_INTB_ISR.
* used to process interrupt of INTB
* \param none
* \return no returns
* \remarks  no remarks
*/
/* ========================================================================= */

void US_DSI3Drv_INTB_ISR(void)
{
   DSI3_int++;
}
/* ===========================================================================*/
/**DSI3Drv_triggerDmaSpiTxRx.  
* used to trigger SPI DMA.
* \param none
* \return no returns
* \remarks  no remarks
* Traceability to source Code: Req.-ID: 20680390
*/
/* ========================================================================= */

 static SPI_Transaction     transaction;              
 static uint32_t   terminateXfer = 1; 
uint16_t US_DSI3Drv_triggerDmaSpiTxRx(uint8_t nDev,uint8_t *snd_buffer,uint8_t *rcv_buffer,uint32_t size)
{
	uint16_t *rx,*tx, len,ret = 0;
    bool status; 
    (void)nDev;
        if(size > MCSPI_RX_TX_FIFO_SIZE)
	{
		len = (uint16_t)size/MCSPI_RX_TX_FIFO_SIZE;
		if((size%MCSPI_RX_TX_FIFO_SIZE) != ZERO)
		{
			len ++;
		}
        else
        {
          ;/* No Action */  
        }
		len *= (MCSPI_RX_TX_FIFO_SIZE/TWO); 
	}
	else
	{
		len = (uint16_t)size / TWO;
	}
        rx = (uint16_t *)l2_global_address((uintptr_t)rcv_buffer);
        tx = (uint16_t *)l2_global_address((uintptr_t)snd_buffer);
        CacheP_wbInv((void *)tx, DSI3DRV_SEND_BUFFER_SIZE);
        CacheP_wbInv((void *)rx, DSI3DRV_RECEIVE_BUFFER_SIZE);

        transaction.count = len;
        transaction.txBuf = tx;             
        transaction.rxBuf = rx;
        transaction.arg = (void *)&terminateXfer; 
      /*comment out tries = ZERO; */
        /* ...initiate SPI transfer */
	/*do{ */
		   status =SPI_transfer(spi_handle, &transaction);	
           if ((!status)&& (transaction.status != SPI_TRANSFER_COMPLETED))
          {
              ret = (uint16_t)DIAG_FLAG_ECU_SPI_DMA_ERR;
		      US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_SPI_DMA_ERR);
          }
		  else
		  {
			  US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_SPI_DMA_ERR);
		/*break; */
		  }
	/*comment out tries++; */
	/*comment out }while((ret == DIAG_FLAG_ECU_SPI_DMA_ERR)&&(tries < MAX_RE_TRY_CNT)); */
     /*comment out dsi_spi_DMA_ISR(spi_handle,&transaction); */
         return ret;
}
#define GPIOMUX_INTRTR0_OUTP_START_R5FSS1    (16U)
#define NUM_GPIO_INT  (3u)
uint32_t GPIO0_PINNUM_INT[NUM_GPIO_INT] = {18,19,31};
void *GpioIsr[NUM_GPIO_INT] ={(void*)&US_DSI3Drv_CH0_ISR,(void*)&US_DSI3Drv_CH1_ISR,(void*)&US_DSI3Drv_INTB_ISR}; 
/* ===========================================================================*/
/* Traceability to source Code: Req.-ID: 
===========================================================================*/
static uint16_t SetRmIrqGPIO(void)
{
    int32_t status = (int32_t)ME_OK;
    HwiP_Params hwiParams;
    HwiP_Handle intrHndl[NUM_GPIO_INT];
    struct tisci_msg_rm_irq_set_req rmIrqReq;
    struct tisci_msg_rm_irq_set_resp rmIrqResp;

   (void) memset(&rmIrqReq, 0x0, sizeof(rmIrqReq));
    (void)memset(&rmIrqResp, 0x0, sizeof(rmIrqResp));

    rmIrqReq.valid_params = 0U;
    rmIrqReq.global_event = 0U;
    rmIrqReq.src_id = 0U;
    rmIrqReq.src_index = 0U;
    rmIrqReq.dst_id = 0U;
    rmIrqReq.dst_host_irq = 0U;
    rmIrqReq.ia_id = 0U;
    rmIrqReq.vint = 0U;
    rmIrqReq.vint_status_bit_index = 0U;
    rmIrqReq.secondary_host = TISCI_MSG_VALUE_RM_UNUSED_SECONDARY_HOST;
   
         rmIrqReq.src_id = TISCI_DEV_GPIO0;  /*comment out TISCI_DEV_GPIOMUX_INTRTR0;    TISCI_DEV_GPIO0; */
        rmIrqReq.src_index = ONE;   /*GPIO0_PINNUM_INT[i]; Need to add 128 for GPIO1 */

        /* Set the destination based on the core */
        rmIrqReq.dst_id = TISCI_DEV_R5FSS0_CORE1;    /*comment out TISCI_DEV_R5FSS1_CORE0;  TISCI_DEV_GPIOMUX_INTRTR0; */
        rmIrqReq.dst_host_irq = (uint32_t)GPIO_INT_ID +(uint32_t) GPIO_INT_CORE_OFFSET;

        /* Set the destination interrupt */
        rmIrqReq.valid_params |= TISCI_MSG_VALUE_RM_DST_ID_VALID;
        rmIrqReq.valid_params |= TISCI_MSG_VALUE_RM_DST_HOST_IRQ_VALID;

        status = Sciclient_rmIrqSet(                                  /*Sciclient_rmIrqSetRaw  Sciclient_rmIrqSet */
            (const struct tisci_msg_rm_irq_set_req *)&rmIrqReq,
            &rmIrqResp,
            SCICLIENT_SERVICE_WAIT_FOREVER);

         if(status == CSL_PASS)
        {
            HwiP_Params_init(&hwiParams);
            intrHndl[ZERO] = HwiP_create((uint32_t)GPIO_INT_ID +(uint32_t) GPIO_INT_CORE_OFFSET, (HwiP_Fxn)GpioIsr[ZERO], &hwiParams); 
            if (NULL != intrHndl[ZERO])
            {
               GPIOIntrEnable_v0(CSL_GPIO0_BASE,18,GPIO_INTR_MASK_FALL_EDGE);   
               GPIOIntrEnable_v0(CSL_GPIO0_BASE,19,GPIO_INTR_MASK_FALL_EDGE);
    	       status = CSL_PASS;   
			   US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_GPIO_INT_INITIAL_ERR);
            }
			else
			{
                GPIOIntrDisable_v0(CSL_GPIO0_BASE,18);
                GPIOIntrDisable_v0(CSL_GPIO0_BASE,19);
				status = DIAG_FLAG_ECU_GPIO_INT_INITIAL_ERR;
			}
        }
        else
        {
            ;/* No Action */
        }
    if (status != CSL_PASS)
	{
		US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_GPIO_INT_INITIAL_ERR);
 	}
    else
    {
        ;/* No Action */
    }
    return (uint16_t)status;
 }



/**
 * \brief   DSI transceiver module initialization
 */
volatile uint16_t US_debug = 0;
uint16_t US_DSI3Drv_init(void)
{
  uint16_t status;
  
  status = (uint16_t)Us_Platform_Gpio_Init();
  status = (uint16_t)Us_Platform_Dsi3RefClk_Init();
  status = (uint16_t)Us_Platform_Spi_Init();

   /*comment out US_Sleep(100); */

  return status;
}


/**
 * \brief   CPU clock test
 */


void US_DSI3Drv_test(void)
{
#if 1
static volatile uint16_t cnt =0;
 
 /* ...update pinmux configuration for MAIN-SPI0 hardware */
  (void)Board_pinmuxUpdate(gDsiPinmuxDataInfo1, BOARD_SOC_DOMAIN_MAIN);     
  (void)Board_moduleClockEnable(TISCI_DEV_MCSPI0);
 /*comment out Board_pinmuxUpdate(gLEDPinmuxDataInfo, BOARD_SOC_DOMAIN_WKUP); */
   GPIOSetDirMode_v0(CSL_GPIO0_BASE, 20, GPIO_DIRECTION_OUTPUT);
   GPIOPinWrite_v0(CSL_GPIO0_BASE, 20, GPIO_PIN_LOW);   /*reset Elmos chip */
   GPIOSetDirMode_v0(CSL_GPIO0_BASE, 18, GPIO_DIRECTION_OUTPUT);
   GPIOSetDirMode_v0(CSL_GPIO0_BASE, 19, GPIO_DIRECTION_OUTPUT);

         
  

 
 
        while(TRUE)                 
		{
			if(cnt == 0x8000u)      
			{
				GPIOPinWrite_v0(CSL_GPIO0_BASE, 18, GPIO_PIN_LOW);
			}
            else
            {
                ;/* No Action */
            }
			if(cnt == 0x0000u)
			{
				GPIOPinWrite_v0(CSL_GPIO0_BASE, 18, GPIO_PIN_HIGH);
			}
            else
            {
                ;/* No Action */
            }

			cnt++;
		}

#endif
}

#if(US_CSM_ENABLE == ME_TRUE)
/**
 * \brief 
 * 
 * \param instanceId 
 * \param reqState 
 * \return UsCsm_StdReturn_Type 
 */
UsCsm_StdReturn_Type Us_Platform_ReqState_Csm(UsCsm_InstanceId_Type instanceId,UsCsm_LocalStateId_Type reqState)
  {
    (void)instanceId;
    LocalStateId_Platform = reqState; /*Dummy state handling, can be removed when init support addedd*/
    return US_CSM_STD_RET_OK;
  }


/**
 * \brief 
 * 
 * \param instanceId 
 * \return UsCsm_LocalStateId_Type 
 */
 UsCsm_LocalStateId_Type Us_Platform_GetState_Csm(UsCsm_InstanceId_Type instanceId)
 {
    (void)instanceId;
    return (LocalStateId_Platform);
 }
 #endif


/**
 * \brief This function initialize the gpio pins
 * 
 * \return uint8 
* Traceability to source Code: Req.-ID: 
===========================================================================*/

 static uint8_t Us_Platform_Gpio_Init(void)
 {
    uint8_t retInitRslt = ME_NOT_OK;
    uint8_t initRetryCount = US_PLATFORM_MAX_RETRY_COUNT_GPIO;
    int32_t status;

   do
   {
	  status = Board_pinmuxUpdate(gDsiPinmuxDataInfo1, BOARD_SOC_DOMAIN_MAIN);	 
      
      if(status == (int32_t)ME_OK)
	  {
 	    status = Board_moduleClockEnable(TISCI_DEV_MCSPI0);
		if(status == (int32_t)ME_OK)
	   {
       	GPIOSetDirMode_v0(CSL_GPIO0_BASE, 18, GPIO_DIRECTION_INPUT);
		GPIOSetDirMode_v0(CSL_GPIO0_BASE, 19, GPIO_DIRECTION_INPUT);
			/* set RFC pin directions */
		GPIOSetDirMode_v0(CSL_GPIO0_BASE, 11, GPIO_DIRECTION_INPUT);
			/* set INTB pin directions */
		GPIOSetDirMode_v0(CSL_GPIO0_BASE, 31, GPIO_DIRECTION_INPUT);
			/* set RESET pin directions */
		GPIOSetDirMode_v0(CSL_GPIO0_BASE, 20, GPIO_DIRECTION_OUTPUT);      
        US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_PIN_INITIAL_ERR);
	   }
       else
       {
        ;/* No Action */
       }
       
        if(ME_OK == SetRmIrqGPIO())
        {
            retInitRslt = ME_OK;
            break;
        }
        else
        {
            ;/* No Action */
        }
	  }
      else
      {
        ;/* No Action */
      }
	  if(status != (int32_t)ME_OK)
	  {
        US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_PIN_INITIAL_ERR);
	  }
      else
      {
        ;/* No Action */
      }
      initRetryCount--;

   }while(initRetryCount != ZERO);
     return (retInitRslt);
 }


/**
 * \brief This function initialize the timer module to generate the 500Khz frq
 * 
 * \return uint8 
 * Traceability to source Code: Req.-ID: 
 */
 static uint8_t Us_Platform_Dsi3RefClk_Init(void)
 {
    uint8_t retInitRslt = ME_NOT_OK;
    uint8_t initRetryCount = US_PLATFORM_MAX_RETRY_COUNT_DSI3REFCLK;

    do
    {
        if((int32_t)ME_OK == dsi_clock_config(0,500000u))
        {
            retInitRslt = ME_OK;
			US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_DSI_CLOCK_INITIAL_ERR);
            break;
        }
        else
        {
            ;/* No Action */
        }
        US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_DSI_CLOCK_INITIAL_ERR);
        initRetryCount--;
    }while(initRetryCount != ZERO);


    return (retInitRslt);
 }


 /**
 * \brief This function initialize the spi module.
 * 
 * \return uint8_t 
* Traceability to source Code: Req.-ID: 
 */
 static uint8_t Us_Platform_Spi_Init(void)
 {
    uint8_t spiInitStatus = ME_NOT_OK;
    uint8_t spiInitRetryCount = US_PLATFORM_MAX_RETRY_COUNT_SPI;    
   
    SPI_HWAttrs spi_cfg = 
    {
        .baseAddr = CSL_MCSPI0_CFG_BASE,
        .intNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCSPI0_INTR_SPI_0,
        .pinMode = (uint32_t)SPI_PINMODE_4_PIN,
        .chNum = MCSPI_CHANNEL_0,
        .chMode = MCSPI_SINGLE_CH,
        .enableIntr = (bool)ME_FALSE,
        .inputClkFreq = 48000000U,
        .initDelay = MCSPI_INITDLY_0,
        .rxTrigLvl = MCSPI_RX_TX_FIFO_SIZE,
        .txTrigLvl = MCSPI_RX_TX_FIFO_SIZE,
        .chnCfg = 
        {
            [0] = 
            {
                .csPolarity = MCSPI_CS_POL_LOW,
                .dataLineCommMode = MCSPI_DATA_LINE_COMM_MODE_7,
                .tcs = MCSPI_CH0CONF_TCS0_ZEROCYCLEDLY,
                .trMode = MCSPI_TX_RX_MODE,
            },
        },               
        .rxDmaEventNumber = CSL_PDMA_CH_MAIN_MCSPI0_CH0_RX,
        .txDmaEventNumber = CSL_PDMA_CH_MAIN_MCSPI0_CH0_TX,
    };

    spi_cfg.edmaHandle = (void *)MCSPIApp_udmaInit(&spi_cfg);
    spi_cfg.dmaMode    = (bool)TRUE;
    device_instance = 0;

    /*Perform the spi initialization and retry if fails*/
    do{
        
        SPI_init();

        if ((SPI_socSetInitCfg(BOARD_OSPI_DOMAIN, device_instance, &spi_cfg)) == 0)
        {
            if ((spi_handle = SPI_open(BOARD_OSPI_DOMAIN, device_instance, &params)) != NULL)
            {
                spiInitStatus = ME_OK;
				US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_SPI_INITIAL_ERR);
                break; /*Exit the loop as spi initialization is sucessfull*/
            }
            else
            {
                ;/* No Action */
            }
        }
        else
        {
            ;/* No Action */
        }
        US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_SPI_INITIAL_ERR);
        spiInitRetryCount--;

    }while(spiInitRetryCount != ZERO);
    return(spiInitStatus);
 }
 /* End Of File */
 

