
/*******************************************************************************
 * Includes
 ******************************************************************************/
//#define SOC_J721E

//#include "US_uart.h"
#include "mcan_data.h"
//#include "mcan.h"
//#include "diag.h"
#include <stdio.h>
#include <stdint.h>
 
#if defined (__C7100__)
#include <ti/sysbios/family/c7x/Mmu.h>
#endif
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

#include <ti/drv/sciclient/sciclient.h>

#include <ti/board/board.h>
#include <ti/board/src/j721s2_evm/include/board_clock.h>


#include <ti/csl/csl_gpio.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

#include <ti/drv/spi/soc/SPI_soc.h>
#include <ti/drv/spi/src/SPI_osal.h>
#include <ti/drv/spi/SPI.h>

#include <ti/csl/csl_types.h>
#include <ti/csl/csl_intr_router.h>
#include <ti/csl/arch/csl_arch.h>
#include <ti/csl/csl_mcan.h>
#include "US_Platform_Global.h"
#include "US_PlatformCfg_Global.h"
#include "US_CAN_Global.h"
/*******************************************************************************
 * Internal functions definitions
 ******************************************************************************/
#if (0 != (US_D_CUR_CAN_PLATFORM & US_D_CAN_PLATFORM_CVADAS))
/**> MCAN element size encoding */
#define MCAN_ELEM_SIZE(n)           \
    ((n) <= 24 ? ((n) - 8) / 4 : ((n) <= 32 ? 5 : ((n) <= 48 ? 6 : 7)))

/**> MCAN message RAM configuration */
#define APP_MCAN_FLSSA                  (0U)
#define APP_MCAN_FLSN                   (1U)
#define APP_MCAN_FLESA                  (APP_MCAN_FLSSA + APP_MCAN_FLSN * 4)
#define APP_MCAN_FLEN                   (1U)
#define APP_MCAN_F0SA                   (APP_MCAN_FLESA + APP_MCAN_FLEN * 8)
#define APP_MCAN_F0N                    (0U)
#define APP_MCAN_F0S                    (64U)
#define APP_MCAN_F1SA                   (APP_MCAN_F0SA + APP_MCAN_F0N * (APP_MCAN_F0S + 8))
#define APP_MCAN_F1N                    (MCAN_RX_FIFO_WIDTH)
#define APP_MCAN_F1S                    (64U)
#define APP_MCAN_RBSA                   (APP_MCAN_F1SA + APP_MCAN_F1N * (APP_MCAN_F1S + 8))
#define APP_MCAN_RBN                    (0U)
#define APP_MCAN_RBS                    (64U)
#define APP_MCAN_TBSA                   (APP_MCAN_RBSA + APP_MCAN_RBN * (APP_MCAN_RBS + 8))
#define APP_MCAN_TBN                    (MCAN_TX_FIFO_WIDTH)
#define APP_MCAN_TBS                    (64U)
#define APP_MCAN_EFSA                   (APP_MCAN_TBSA + APP_MCAN_TBN * (APP_MCAN_TBS + 8))
#define APP_MCAN_EFN                    (MCAN_TX_FIFO_WIDTH)

/**> Extended CAN id mask */
#define APP_MCAN_EXT_ID_AND_MASK        (0x1FFFFFFFU)

/**> FIFO to fetch the frames */
#define APP_MCAN_FIFO                   (1U)


                     
/*******************************************************************************
 * Tracing configuration
 ******************************************************************************/
#if 0
TRACE_TAG(INIT, 1);
TRACE_TAG(INFO, 0);
TRACE_TAG(RX, 0);
TRACE_TAG(TX, 0);
TRACE_TAG(TXDBG, 0);
TRACE_TAG(RXDBG, 0);
TRACE_TAG(DEBUG, 0);
#endif
/*******************************************************************************
 * Local typedefs
 ******************************************************************************/

/**> Forward declarations */
typedef struct usmcan_device  mcan_device_t;
typedef struct usmcan_desc    mcan_desc_t;

/**
 * \brief   MCAN device descriptor
 */
struct usmcan_desc
{
    /**> Device base address */
    uint32_t        baseAddr;

    /**> RX interrupt vector */
    uint32_t        rxIntrNum;

    /**> TX interrupt vector */
    uint32_t        txIntrNum;

    /**> External timestamp roll-over interrupt vector */
    uint32_t        tsIntrNum;

    /**> IRQ router interrupt for RX */
    uint32_t        rxRouterIntrNum;

    /**> IRQ router interrupt for TX */
    uint32_t        txRouterIntrNum;

    /**> IRQ router interrupt for TS */
    uint32_t        tsRouterIntrNum;

    /**> CAN initialization function */
    int32_t       (*init)(mcan_device_t *dev, uint32_t id);

    /**> CAN setup function */
    int32_t       (*setup)(mcan_device_t *dev, uint32_t id, int32_t enable);
};

/**
 * \brief   MCAN device data
 */
struct usmcan_device
{
    /**> MCAN device descriptor */
    mcan_desc_t             desc;

    /**> Device name */
    const char             *name;

    /**> Private data pointer */
    void                   *priv;

    /**> Device id */
    uint32_t                DevId;

    /**> Device operational state */
    uint32_t                state;

    /**> Timestamp base */
    uint64_t                ts_base;

 
    /**> MCAN initialization parameters */
    MCAN_InitParams         init;

    /**> MCAN configuration parameters */
    MCAN_ConfigParams       cfg;

    /**> Nominal/data bitrate timing */
    MCAN_BitTimingParams    bitTimes;
};

/*******************************************************************************
 * MCAN device states
 ******************************************************************************/

/**> Device is in idle-mode; no CAN data flow between client and server */
#define MCAN_STATE_IDLE                0

/**> Device is configured and exchanging messages between client and server */
#define MCAN_STATE_RUNNING             1

/**> Device is in error-passive state? - tbd */
#define MCAN_STATE_ERROR_PASSIVE       2





/*******************************************************************************
 * CAN transceiver setup functions
 ******************************************************************************/

/**
 * \brief   Setup TJA1057 CAN-transceiver
 */
static int32_t mcan_tja1057_setup(mcan_device_t *dev, uint32_t id, int32_t enable)
{
    /* ...enable/disable MCU-MCAN1: HS_CAN_SILENT -> WKUP_GPIO0_8 */
    GPIOSetDirMode_v0(CSL_WKUP_GPIO0_BASE, 56, GPIO_DIRECTION_OUTPUT);
  	
    GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE, 56, (GPIO_PIN_LOW));
    GPIOPinWrite_v0(CSL_GPIO0_BASE, 56, (enable ? GPIO_PIN_LOW : GPIO_PIN_HIGH));

    // TRACE(INIT, _b("can%u operation %sabled"), id, (enable ? "en" : "dis"));

    /* ...no specific setup required? */
    return 0;
}

/*******************************************************************************
 * TJA1145 CAN transceiver support
 ******************************************************************************/

/**
 * \brief   Start SPI transfer for selected device
 */
static int32_t spi_setup_xfer(SPI_Handle spi, uint8_t *writeData, uint8_t *readData, uint32_t numBytes, uint32_t timeout)
{
    SPI_Transaction     transaction;

    /* ...initialize slave SPI transaction structure */
    transaction.count = numBytes;
    transaction.txBuf = (void *)writeData;
    transaction.rxBuf = (void *)readData;

    /* ...initiate SPI transfer */
    if (SPI_transfer(spi, &transaction))
    {
        // TRACE(DEBUG, _b("SPI transfer completed: %u bytes sent"), transaction.count);

        /* Get the actual transfer bytes */
        return transaction.count;
    }
    else
    {
        // TRACE(ERROR, _x("SPI transfer failed: status=%x"), transaction.status);
        return -1;
    }
}

/**
 * \brief   Write SPI register
 */
static inline int32_t spi_write8(SPI_Handle spi, uint8_t reg, uint8_t value)
{
    uint16_t    cmd = (reg << 1) | ((uint16_t)value << 8);
    uint16_t    res;

    return spi_setup_xfer(spi, (uint8_t *)&cmd, (uint8_t *)&res, 2, SemaphoreP_WAIT_FOREVER);
}

/**
 * \brief   Write SPI register
 */
static inline uint8_t spi_read8(SPI_Handle spi, uint8_t reg)
{
    uint16_t    cmd = (reg << 1) | 1;
    uint16_t    res;

    if (spi_setup_xfer(spi, (uint8_t *)&cmd, (uint8_t *)&res, 2, SemaphoreP_WAIT_FOREVER) < 0)
    {
        return 0xFF;
    }
    else
    {
        return res >> 8;
    }
}

/**
 * \brief   CAN TJA1145 transceiver private data
 */
typedef struct mcan_tja1145_priv
{
    /**> SPI instance */
    uint32_t            instance;

    /**> SPI clock frequency */
    uint32_t            clock_freq;

    /**> SPI parameters */
    SPI_Params          params;


}   mcan_tja1145_priv_t;

/**
 * \brief   Enable MCU-SPI0 master operation
 */
static inline int32_t mcan_spi_init(uint32_t instance, uint32_t freq)
{
    SPI_HWAttrs     spi_cfg;

    /* ...initailize SPI driver */
    SPI_init();

    /* ...set polling mode for SPI transfer */
    SPI_socGetInitCfg(instance, &spi_cfg);
    spi_cfg.enableIntr = false;
    spi_cfg.edmaHandle = NULL;
    spi_cfg.dmaMode    = FALSE;
    spi_cfg.inputClkFreq = freq;
    SPI_socSetInitCfg(instance, &spi_cfg);

    return 0;
}

/**
 * \brief   Initialize TJA1145 CAN-transceiver
 */
static int32_t mcan_tja1145_init(mcan_device_t *dev, uint32_t id)
{
    mcan_tja1145_priv_t    *priv = (mcan_tja1145_priv_t    *)dev->priv;
    SPI_Handle              spi;
 //   uint8_t                 can_id;

    /* ...init SPI device */
    if (mcan_spi_init(priv->instance, priv->clock_freq) != 0)
    {
        // // TRACE(ERROR, _x("can%u: failed to set SPI configuration"), id);
        return -1;
    }

    if ((spi = SPI_open(priv->instance, &priv->params)) == NULL)
    {
        // TRACE(ERROR, _b("failed to open SPI"));
        return -1;
    }

    /* ...read CAN transceiver ID */
   // can_id = spi_read8(spi, 0x7E);
     spi_read8(spi, 0x7E);
    // TRACE(INFO, _b("can%u TJA1145 transceiver id: %02X"), id, can_id);

    /* ...close SPI handle */
    SPI_close(spi);

    return 0;
}



/**> MCU-MCAN0 CAN transceiver configuration */
static mcan_tja1145_priv_t mcan_mcu_mcan0_tja1145 = {
    .instance = 0,
    .clock_freq = 24000000,
    .params = {
        .transferMode = SPI_MODE_BLOCKING,
        .transferTimeout = SemaphoreP_WAIT_FOREVER,
        .mode = SPI_MASTER,
        .bitRate = 1000000,
        .dataSize = 8,
        .frameFormat = SPI_POL0_PHA1,
    },
};


/**
 * \brief   Setup TJA1145 CAN-transceiver
 */
static int32_t mcan_tja1145_setup(mcan_device_t *dev, uint32_t id, int32_t enable)
{
    mcan_tja1145_priv_t    *priv = (mcan_tja1145_priv_t    *)dev->priv;
    SPI_Handle              spi;
    int32_t                 ret;

    /* ...read CAN transceiver ID */
    if ((spi = SPI_open(priv->instance, &priv->params)) == NULL)
    {
        // TRACE(ERROR, _b("can%u: failed to open SPI"), id);
        return -1;
    }

    /* ...put MCAN into normal / suspended mode */
    if ((ret = spi_write8(spi, 0x01, (enable ? 0x7 : 0x0))) < 0)
    {
        // TRACE(ERROR, _x("can%u: transceiver access failure"), id);
    }
    else
    {
        // TRACE(INFO, _b("can%u: CAN TJA1145 transceiver powered-%s"), id, (enable ? "on" : "off"));
    }

    /* ...close SPI handle */
    SPI_close(spi);

    return ret;
}


/**> Devices configuration */
static mcan_device_t    mcan_device[MCAN_DEV_NUM] = {
      [MCAN_DEV_MCU_MCAN1] = {
        .desc = {
            .baseAddr = CSL_MCU_MCAN1_SS_BASE,           //CSL_MCU_MCAN1_MSGMEM_RAM_BASE,
            .rxIntrNum = CSLR_R5FSS0_CORE1_INTR_MCU_MCAN1_MCANSS_MCAN_LVL_INT_1,
            .txIntrNum = CSLR_R5FSS0_CORE1_INTR_MCU_MCAN1_MCANSS_MCAN_LVL_INT_0,
            .tsIntrNum = CSLR_R5FSS0_CORE1_INTR_MCU_MCAN1_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
            .rxRouterIntrNum = 0,
            .txRouterIntrNum = 0,
            .tsRouterIntrNum = 0,
             .setup = mcan_tja1057_setup,
        },
        .name = "MCAN.mcu-mcan1",
        .DevId = TISCI_DEV_MCU_MCAN1,
       // .local_ept = MCAN_EP_MCU_MCAN0,
        .bitTimes = {
            .nomRatePrescalar = 0x7U,
            .nomTimeSeg1 = 0xcU,              // 5
            .nomTimeSeg2 = 0x5U,              // 2
            .nomSynchJumpWidth = 0x0U,
            .dataRatePrescalar = 0x1U,
            .dataTimeSeg1 = 0xCU,
            .dataTimeSeg2 = 0x5U,
            .dataSynchJumpWidth = 0x0U,
        },
    },
    [MCAN_DEV_MAIN_MCAN6] = {
        .desc = {
            .baseAddr = CSL_MCAN6_MSGMEM_RAM_BASE,
            .rxIntrNum = CSLR_R5FSS1_CORE0_INTR_MCAN6_MCANSS_MCAN_LVL_INT_1,
            .txIntrNum = CSLR_R5FSS1_CORE0_INTR_MCAN6_MCANSS_MCAN_LVL_INT_0,
            .tsIntrNum = CSLR_R5FSS1_CORE0_INTR_MCAN6_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
            .rxRouterIntrNum = CSLR_R5FSS1_CORE0_INTR_MCAN6_MCANSS_MCAN_LVL_INT_1,
            .txRouterIntrNum = CSLR_R5FSS1_CORE0_INTR_MCAN6_MCANSS_MCAN_LVL_INT_0,
            .tsRouterIntrNum = CSLR_R5FSS1_CORE0_INTR_MCAN6_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
            .setup = mcan_tja1057_setup,
        },
        .name = "MCAN.mcan6",
        .DevId = 0,
   //     .local_ept = CANGW_EP_MCU_MCAN1,
        .bitTimes = {
            .nomRatePrescalar = 0x7U,
            .nomTimeSeg1 = 0xcU,
            .nomTimeSeg2 = 0x5U,
            .nomSynchJumpWidth = 0x0U,
            .dataRatePrescalar = 0x1U,
            .dataTimeSeg1 = 0xcU,    //3
            .dataTimeSeg2 = 0x5U,    //2
            .dataSynchJumpWidth = 0x0U,
        },
    },
#if 0
    [MCAN_DEV_MAIN_MCAN2] = {
        .desc = {
            .baseAddr = CSL_MCAN2_MSGMEM_RAM_BASE,
            .rxIntrNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_7,
            .txIntrNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_6,
            .tsIntrNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_5,
            .rxRouterIntrNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN2_MCANSS_MCAN_LVL_INT_1,
            .txRouterIntrNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN2_MCANSS_MCAN_LVL_INT_0,
            .tsRouterIntrNum = CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN2_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0,
            .setup = mcan_tcan1042_setup,
        },
        .name = "MCAN.main-mcan2",
        .local_ept = MCAN_EP_MAIN_MCAN2,
    },
#endif
};

/*******************************************************************************
 * Forward declarations
 ******************************************************************************/

/**> CAN devices*/
//static mcan_device_t    mcan_device[MCAN_DEV_NUM];

/**> CAN device id evaluation */
static inline uint32_t mcan_device_id(mcan_device_t *dev)
{
    return (uint32_t)(dev - &mcan_device[0]);
}


struct  canfd_frame can_msg;
US_Can_msg_t US_Can_msg;
static volatile uint32_t rx_int =0;
static volatile uint32_t tx_int =0;
static volatile uint32_t ts_int =0;

/**
 * \brief   Get message "DLC" encoding for packet length
 */
static inline uint8_t mcan_dlc2len(uint8_t dlc)
{
    static const uint8_t    map[16] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 16, 20, 24, 32, 48, 64,
    };

    return map[dlc < 15 ? dlc : 15];
}


void mcan_rx_getmsg(uint32_t baseAddr, uint32_t nRX_FIFO)
{
    MCAN_RxFIFOStatus   rxfs; 
    MCAN_RxBufElement   buf;

    rxfs.num = nRX_FIFO;

    /* ...get RX-FIFO status */
    MCAN_getRxFIFOStatus(baseAddr, &rxfs);
    // TRACE(RXDBG, _b("FIFO#%d: fill=%u, get=%u, put=%u, full=%u, lost=%u"), rxfs.num, rxfs.fillLvl, rxfs.getIdx, rxfs.putIdx, rxfs.fifoFull, rxfs.msgLost);
    
    if (rxfs.getIdx != rxfs.putIdx || rxfs.fifoFull)
     {
                /* ...read packet from FIFO */
                MCAN_readMsgRam(baseAddr, MCAN_MEM_TYPE_FIFO, rxfs.getIdx, rxfs.num, &buf);

                /* ...acknowledge packet reception */
                MCAN_writeRxFIFOAck(baseAddr, rxfs.num, rxfs.getIdx);

                // TRACE(RX, _b("can: ack RX-FIFO-#%u: put-idx=%u, get-idx=%u"), rxfs.num, rxfs.putIdx, rxfs.getIdx);

 
                /* ...put canfd-frame fields */
                US_Can_msg.msgId = buf.id >> (buf.xtd ? 0 : 18);
                US_Can_msg.msgId |= (buf.rtr ? CAN_RTR_FLAG : 0);
                US_Can_msg.msgId |= (buf.xtd ? CAN_EFF_FLAG : 0);
                can_msg.flags = (buf.brs ? CANFD_BRS : 0);
                can_msg.flags |= (buf.esi ? CANFD_ESI : 0);
             //   can_msg.flags |= (buf.fdf ? CANGW_FDF : 0);
                can_msg.len = mcan_dlc2len(buf.dlc);
                US_Can_msg.dataLen = can_msg.len;
                memcpy(US_Can_msg.data, buf.data, can_msg.len);
                US_CanIf_RxIndication(&US_Can_msg); 

    }   

}

/**
 * \brief   CAN message rx-interrupt handler
 */
static void mcan_rx_isr(uintptr_t arg)
{
    mcan_device_t  *dev = (mcan_device_t *)arg;
    uint32_t        id = mcan_device_id(dev);
    uint32_t        baseAddr = dev->desc.baseAddr;
    uint32_t        status;
   
    rx_int++;
    /* ...fetch interrupt status register */
    status = MCAN_getIntrStatus(baseAddr);

    /* ...check for interrupt source */
    if ((status & (MCAN_INTR_SRC_RX_FIFO1_NEW_MSG |  MCAN_INTR_SRC_RX_FIFO1_FULL)) != 0)
    {
        /* ...notify CAN-rx task on new message availability */
       MCAN_clearIntrStatus(baseAddr, (MCAN_INTR_SRC_RX_FIFO1_NEW_MSG |  MCAN_INTR_SRC_RX_FIFO1_FULL));
       mcan_rx_getmsg(baseAddr, 1);
    }

   if ((status & (MCAN_INTR_SRC_RX_FIFO0_NEW_MSG |  MCAN_INTR_SRC_RX_FIFO0_FULL)) != 0)
    {
        /* ...signal transmission completion */
        MCAN_clearIntrStatus(baseAddr, (MCAN_INTR_SRC_RX_FIFO0_NEW_MSG |  MCAN_INTR_SRC_RX_FIFO0_FULL));
        mcan_rx_getmsg(baseAddr, 0);
        //EventP_post(dev->event, MCAN_EVENT_TX);
    }
}

/**
 * \brief   CAN message tx-interrupt handler
 */
static void mcan_tx_isr(uintptr_t arg)
{
    mcan_device_t  *dev = (mcan_device_t *)arg;
    uint32_t        id = mcan_device_id(dev);
    uint32_t        baseAddr = dev->desc.baseAddr;
    uint32_t        status;
    
    tx_int++;
    /* ...fetch interrupt status register */
    status = MCAN_getIntrStatus(baseAddr);

    /* ...check for transmission completion configuration */
    if ((status & (MCAN_INTR_SRC_TRANS_COMPLETE)) != 0)
    {
        /* ...clear transmission completed interrupt - there is no such, I guess */
        MCAN_clearIntrStatus(baseAddr, MCAN_INTR_SRC_TRANS_COMPLETE );
        US_CanIf_TxConfirmation();  

        /* ...signal transmission completion */
  //      EventP_post(dev->event, MCAN_EVENT_TX);
    }
}

/**
 * \brief   CAN external timestamp rollover interrupt handler
 */
void mcan_ts_isr(uintptr_t arg)
{
    mcan_device_t  *dev = (mcan_device_t *)arg;
    uint32_t        id = mcan_device_id(dev);
    uint32_t        baseAddr = dev->desc.baseAddr;
   // uint32_t        num;
     ts_int++;
    /* ...get number of unserviced interrupts */
   // num = MCAN_extTSGetUnservicedIntrCount(baseAddr);
     MCAN_extTSGetUnservicedIntrCount(baseAddr);
    /* ...advance base timestamp value */
    dev->ts_base++;

    // TRACE(0, _b("can%u: timestamp-wraparound: num=%u, ts-base=%llu, tscv=%u"), id, num, dev->ts_base, MCAN_getTSCounterVal(baseAddr));

    /* ...decrement rollover interrupt counter */
    MCAN_extTSClearRawStatus(baseAddr);

    /* ...mark end-of-interrupt */
    MCAN_extTSWriteEOI(baseAddr);
}

static int32_t App_mcanCfgIrqRouterMcu2Main(uint32_t devId, uint32_t Src_Index, uint32_t outputIntrNum)
{
    int32_t retVal = 0;
    struct tisci_msg_rm_irq_set_req     rmIrqReq={0};
    struct tisci_msg_rm_irq_set_resp    rmIrqResp;
	memset((void*)&rmIrqResp,0,sizeof(rmIrqResp));
    if(devId != 0)
	{
    rmIrqReq.valid_params           = (uint32_t)TISCI_MSG_VALUE_RM_DST_ID_VALID;
    rmIrqReq.valid_params          |= TISCI_MSG_VALUE_RM_DST_HOST_IRQ_VALID;
    rmIrqReq.src_id                 = devId;
    rmIrqReq.global_event           = 0U;
    rmIrqReq.src_index              = Src_Index;
    rmIrqReq.dst_id                 = TISCI_DEV_R5FSS1_CORE0;
    rmIrqReq.dst_host_irq           = outputIntrNum;
    rmIrqReq.ia_id                  = 0U;
    rmIrqReq.vint                   = 0U;
    rmIrqReq.vint_status_bit_index  = 0U;
    rmIrqReq.secondary_host         = TISCI_MSG_VALUE_RM_UNUSED_SECONDARY_HOST;
    retVal = Sciclient_rmIrqSet(&rmIrqReq, &rmIrqResp, SCICLIENT_SERVICE_WAIT_FOREVER);
    if(CSL_PASS != retVal)
    {
        // TRACE(0, _b("Error in SciClient Interrupt Params Configuration!!!"));

        // TRACE(0, _b("input Index num: %d \n"),Src_Index);
     }
    else
    {
       // TRACE(INFO, _b("SciClient Interrupt Params Configuration passed for input index num: %d \n"), Src_Index);
    }
	}
    return retVal;
}

/**
 * \brief   Configure IRQ routing
 */
int32_t mcan_irq_router_config(uint32_t inputIntrNum, uint32_t outputIntrNum)
{
    int32_t             status = 0U;

#if defined (SOC_J721E)
    CSL_IntrRouterCfg   irRegs;

#ifdef BUILD_MCU1_0
    /* ...routing MAIN MCAN interrupts to MCU Domain R5 */
    irRegs.pIntrRouterRegs =(CSL_intr_router_cfgRegs *) CSL_MAIN2MCU_LVL_INTRTR0_CFG_BASE;
    outputIntrNum = outputIntrNum - CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0;
    irRegs.numInputIntrs = 312;
    irRegs.numOutputIntrs = 64;
#else
    /* ...routing MCU MCAN interrupts to Main Domain R5 */
    irRegs.pIntrRouterRegs =(CSL_intr_router_cfgRegs *) CSL_R5FSS0_INTROUTER0_INTR_ROUTER_CFG_BASE;
    outputIntrNum = outputIntrNum - CSLR_R5FSS1_CORE1_INTR_R5FSS1_INTROUTER0_OUTL_0;
    irRegs.numInputIntrs = 432;
    irRegs.numOutputIntrs = 256;
#endif
    irRegs.pIntdRegs = (CSL_intr_router_intd_cfgRegs *) NULL;

    status = CSL_intrRouterCfgMux(&irRegs, inputIntrNum, outputIntrNum);
#endif

    return status;
}

/**
 * \brief   CAN device initialization
 */
static void mcan_setup(mcan_device_t *dev, uint32_t id)
{
    mcan_desc_t                *desc = &dev->desc;
    uint32_t                    baseAddr = desc->baseAddr;
    OsalRegisterIntrParams_t    intrPrms;
  //  OsalInterruptRetCode_e      osalRet;
    HwiP_Handle                 hwiHandle;
    Board_moduleClockEnable(dev->DevId);

    /* ...register RX interrupt */
//    (desc->rxRouterIntrNum ? mcan_irq_router_config(desc->rxRouterIntrNum, desc->rxIntrNum) : 0);
    if(desc->rxRouterIntrNum)
    { 
        App_mcanCfgIrqRouterMcu2Main(dev->DevId, 2,desc->rxIntrNum);
    }

    Osal_RegisterInterrupt_initParams(&intrPrms);
    intrPrms.corepacConfig.arg              = (uintptr_t) dev;
    intrPrms.corepacConfig.isrRoutine       = &mcan_rx_isr;
    intrPrms.corepacConfig.priority         = 4U;
    intrPrms.corepacConfig.corepacEventNum  = 0U;
    intrPrms.corepacConfig.intVecNum        = desc->rxIntrNum;
    if (( Osal_RegisterInterrupt(&intrPrms, &hwiHandle)) != OSAL_INT_SUCCESS)
    {
        // TRACE(ERROR, _b("can%u: failed to install MCAN RX interrupt: %d"), id, osalRet);
    }

    /* ...register TX interrupt (not used really? - tbd) */
    if(desc->rxRouterIntrNum)
    {
        App_mcanCfgIrqRouterMcu2Main(dev->DevId, 1,desc->txIntrNum);
    }
 //   (desc->txRouterIntrNum ? mcan_irq_router_config(desc->txRouterIntrNum, desc->txIntrNum) : 0);
    Osal_RegisterInterrupt_initParams(&intrPrms);
    intrPrms.corepacConfig.arg              = (uintptr_t) dev;
    intrPrms.corepacConfig.isrRoutine       = &mcan_tx_isr;
    intrPrms.corepacConfig.priority         = 4U;
    intrPrms.corepacConfig.corepacEventNum  = 0U;
    intrPrms.corepacConfig.intVecNum        = desc->txIntrNum;
    if ((Osal_RegisterInterrupt(&intrPrms, &hwiHandle)) != OSAL_INT_SUCCESS)
    {
        // TRACE(ERROR, _b("can%u: failed to install MCAN TX interrupt: %d"), id, osalRet);
    }

    /* ...register external timestamp rollover interrupt */
  #if 0   
      (desc->rxRouterIntrNum ? App_mcanCfgIrqRouterMcu2Main(dev->DevId, desc->tsRouterIntrNum,desc->tsIntrNum) : 0);
//   (desc->tsRouterIntrNum ? mcan_irq_router_config(desc->tsRouterIntrNum, desc->tsIntrNum) : 0);
    Osal_RegisterInterrupt_initParams(&intrPrms);
    intrPrms.corepacConfig.arg              = (uintptr_t) dev;
    intrPrms.corepacConfig.isrRoutine       = &mcan_ts_isr;
    intrPrms.corepacConfig.priority         = 4U;
    intrPrms.corepacConfig.corepacEventNum  = 0U;
    intrPrms.corepacConfig.intVecNum        = desc->tsIntrNum;
    if ((Osal_RegisterInterrupt(&intrPrms, &hwiHandle)) != OSAL_INT_SUCCESS)
    {
        // TRACE(ERROR, _b("can%u: failed to install MCAN TS interrupt: %d"), id, osalRet);
    }
   #endif
    /* ...get MCANSS Revision ID */
    MCAN_RevisionId     revId;
  //  uint32_t            fdoe;

    MCAN_getRevisionId(baseAddr, &revId);
    MCAN_isFDOpEnable(baseAddr);

    /* TRACE(INFO, _b("MCANSS Revision ID:\n"
                   "scheme:0x%x\n"
                   "Business Unit:0x%x\n"
                   "Module ID:0x%x\n"
                   "RTL Revision:0x%x\n"
                   "Major Revision:0x%x\n"
                   "Custom Revision:0x%x\n"
                   "Minor Revision:0x%x\n"
                   "CAN-FD operation:%s"),
          revId.scheme, revId.bu ,revId.modId ,revId.rtlRev,
          revId.major, revId.custom, revId.minor,
          (fdoe ? "enabled" : "disabled")
        );
    */
    /* ...wait for memory initialization */
    while (!MCAN_isMemInitDone(baseAddr))
        TaskP_sleep(1);

    /* ...do device-specific initialization */
    if (dev->desc.init && dev->desc.init(dev, id) < 0)
    {
        // TRACE(ERROR, _x("can%u: failed to initialize device"), id);
    }

    // TRACE(INIT, _b("can%u is running"), id);
}

/**
 * \brief Calculate CAN timestamp value in nanoseconds
 */
#if 0
static inline uint64_t mcan_calc_ts(mcan_device_t *dev, uint16_t ts)
{
    uint16_t    ts_now;
    uint64_t    tstamp;
    uintptr_t   cookie;

    /* ...disable interrupts */
    cookie = HwiP_disable();

    /* ...calculate timestamp value in MCAN-ICLK ticks */
    ts_now = MCAN_getTSCounterVal(dev->desc.baseAddr);
    tstamp = ((dev->ts_base + (ts_now < ts ? 1 : 0)) << 16) | ts;

    /* ...restore interrupts */
    HwiP_restore(cookie);

    /* ...convert ticks to nanoseconds wrt prescaler=166 and ICLK freq 1GHz/6 */
    return tstamp * (6 * 166);
}
#endif
/**
 * \brief   Start CAN device
 */
static int32_t mcan_enable(mcan_device_t *dev, uint32_t id)
{
    uint32_t                    baseAddr = dev->desc.baseAddr;
    MCAN_InitParams             initParams;
    MCAN_ConfigParams           configParams;
    MCAN_MsgRAMConfigParams     msgRAMConfigParams;
    MCAN_StdMsgIDFilterElement  stdFiltelem;
    MCAN_ExtMsgIDFilterElement  extFiltelem;
   // int32_t                     status;

    /* ...set MCAN initialization params (meaning is tbd - pass from user?) */
    initParams.fdMode                       = 0x1U;
    initParams.brsEnable                    = 0x1U;
    initParams.txpEnable                    = 0x0U;
    initParams.efbi                         = 0x0U;
    initParams.pxhddisable                  = 0x0U;
    initParams.darEnable                    = 0x0U;
    initParams.wkupReqEnable                = 0x1U;
    initParams.autoWkupEnable               = 0x1U;
    initParams.emulationEnable              = 0x1U;
    initParams.emulationFAck                = 0x0U;
    initParams.clkStopFAck                  = 0x0U;
    initParams.wdcPreload                   = 0xFFU;
    initParams.tdcEnable                    = 0x1U;
    initParams.tdcConfig.tdcf               = 0xAU;
    initParams.tdcConfig.tdco               = 0x6U;

    /* ...set MCAN configuration params (use external counter) */
    configParams.monEnable                  = 0x0U;
    configParams.asmEnable                  = 0x0U;
    configParams.tsPrescalar                = 0xFU;
    configParams.tsSelect                   = 0x2U;
    configParams.timeoutSelect              = MCAN_TIMEOUT_SELECT_CONT;
    configParams.timeoutPreload             = 0xFFFFU;
    configParams.timeoutCntEnable           = 0x0U;
    configParams.filterConfig.rrfs          = 0x1U;
    configParams.filterConfig.rrfe          = 0x1U;
    configParams.filterConfig.anfe          = 0x1U;
    configParams.filterConfig.anfs          = 0x1U;

    /* ...initialize Message RAM Sections Configuration Parameters */
    msgRAMConfigParams.flssa                = APP_MCAN_FLSSA;
    msgRAMConfigParams.lss                  = APP_MCAN_FLSN;
    msgRAMConfigParams.flesa                = APP_MCAN_FLESA;
    msgRAMConfigParams.lse                  = APP_MCAN_FLEN;
    msgRAMConfigParams.txStartAddr          = APP_MCAN_TBSA;
    msgRAMConfigParams.txBufNum             = 0;
    msgRAMConfigParams.txFIFOSize           = APP_MCAN_TBN;
    msgRAMConfigParams.txBufMode            = 0U;       // TX FIFO operation
    msgRAMConfigParams.txBufElemSize        = MCAN_ELEM_SIZE(APP_MCAN_TBS);
    msgRAMConfigParams.txEventFIFOStartAddr = APP_MCAN_EFSA;
    msgRAMConfigParams.txEventFIFOSize      = APP_MCAN_EFN;
    msgRAMConfigParams.txEventFIFOWaterMark = (APP_MCAN_EFN * 3 + 3) / 4;
    msgRAMConfigParams.rxFIFO0startAddr     = APP_MCAN_F0SA;
    msgRAMConfigParams.rxFIFO0size          = APP_MCAN_F0N;
    msgRAMConfigParams.rxFIFO0waterMark     = (APP_MCAN_F0N * 3 + 3) / 4;
    msgRAMConfigParams.rxFIFO0OpMode        = 0U;
    msgRAMConfigParams.rxFIFO1startAddr     = APP_MCAN_F1SA;
    msgRAMConfigParams.rxFIFO1size          = APP_MCAN_F1N;
    msgRAMConfigParams.rxFIFO1waterMark     = (APP_MCAN_F1N * 3 + 3) / 4;
    msgRAMConfigParams.rxFIFO1OpMode        = 0U;
    msgRAMConfigParams.rxBufStartAddr       = APP_MCAN_RBSA;
    msgRAMConfigParams.rxBufElemSize        = MCAN_ELEM_SIZE(APP_MCAN_RBS);
    msgRAMConfigParams.rxFIFO0ElemSize      = MCAN_ELEM_SIZE(APP_MCAN_F0S);
    msgRAMConfigParams.rxFIFO1ElemSize      = MCAN_ELEM_SIZE(APP_MCAN_F1S);

    /* TRACE(DEBUG, _b("can%u: msgRAM:\n"
                    "flssa = %u\n"
                    "lss = %u\n"
                    "flesa = %u\n"
                    "lse = %u\n"
                    "txStartAddr = %u\n"
                    "txBufNum = %u\n"
                    "txFIFOSize = %u\n"
                    "txBufMode = %u\n"
                    "txBufElemSize = %u\n"
                    "txEventFIFOStartAddr = %u\n"
                    "txEventFIFOSize = %u\n"
                    "txEventFIFOWaterMark = %u\n"
                    "rxFIFO0startAddr = %u\n"
                    "rxFIFO0size = %u\n"
                    "rxFIFO0waterMark = %u\n"
                    "rxFIFO0OpMode = %u\n"
                    "rxFIFO1startAddr = %u\n"
                    "rxFIFO1size = %u\n"
                    "rxFIFO1waterMark = %u\n"
                    "rxFIFO1OpMode = %u\n"
                    "rxBufStartAddr = %u\n"
                    "rxBufElemSize = %u\n"
                    "rxFIFO0ElemSize = %u\n"
                    "rxFIFO1ElemSize = %u\n"), id,
          msgRAMConfigParams.flssa,
          msgRAMConfigParams.lss,
          msgRAMConfigParams.flesa,
          msgRAMConfigParams.lse,
          msgRAMConfigParams.txStartAddr,
          msgRAMConfigParams.txBufNum,
          msgRAMConfigParams.txFIFOSize,
          msgRAMConfigParams.txBufMode,
          msgRAMConfigParams.txBufElemSize,
          msgRAMConfigParams.txEventFIFOStartAddr,
          msgRAMConfigParams.txEventFIFOSize,
          msgRAMConfigParams.txEventFIFOWaterMark,
          msgRAMConfigParams.rxFIFO0startAddr,
          msgRAMConfigParams.rxFIFO0size,
          msgRAMConfigParams.rxFIFO0waterMark,
          msgRAMConfigParams.rxFIFO0OpMode,
          msgRAMConfigParams.rxFIFO1startAddr,
          msgRAMConfigParams.rxFIFO1size,
          msgRAMConfigParams.rxFIFO1waterMark,
          msgRAMConfigParams.rxFIFO1OpMode,
          msgRAMConfigParams.rxBufStartAddr,
          msgRAMConfigParams.rxBufElemSize,
          msgRAMConfigParams.rxFIFO0ElemSize,
          msgRAMConfigParams.rxFIFO1ElemSize);
*/
    /* ...initialize filter params - tbd - need to pass it from user */
    stdFiltelem.sfid2 = 0x0U;
    stdFiltelem.sfid1 = 0x4U;
    stdFiltelem.sfec = 0x0U;
    stdFiltelem.sft = 0x3U;

    /* ...exetended filter params - again, currently disabled */
    extFiltelem.efid2 = 0xFU;
    extFiltelem.efid1 = 0x0U;
    extFiltelem.efec = 0x0U;
    extFiltelem.eft = 0x3U;

    /* ...initialize MCAN module */
    if ((MCAN_init(baseAddr, &initParams)) != STW_SOK)
    {
        // TRACE(ERROR, _x("status: %d"), status);
    }

    if ((MCAN_config(baseAddr, &configParams)) != STW_SOK)
    {
        // TRACE(ERROR, _x("status: %d"), status);
    }

    if (( MCAN_setBitTime(baseAddr, &dev->bitTimes)) != STW_SOK)
    {
        // TRACE(ERROR, _x("status: %d"), status);
    }

    if ((MCAN_setExtIDAndMask(baseAddr, APP_MCAN_EXT_ID_AND_MASK)) != STW_SOK)
    {
        // TRACE(ERROR, _x("status: %d"), status);
    }

    if (( MCAN_msgRAMConfig(baseAddr, &msgRAMConfigParams)) != STW_SOK)
    {
        // TRACE(ERROR, _x("status: %d"), status);
    }

    /* ...set counter resolution as 1MHz (1 is mistakenly subtracted from prescaler value) */
    MCAN_extTSEnableIntr(baseAddr, 1U);
    MCAN_extTSCounterConfig(baseAddr, 166U + 1U);
    MCAN_extTSCounterEnable(baseAddr, 1U);

    /* ...do I have to set the filters? - guess no */
    MCAN_addStdMsgIDFilter(baseAddr, 0U, &stdFiltelem);
    MCAN_addExtMsgIDFilter(baseAddr, 0U, &extFiltelem);

    // TRACE(DEBUG, _b("can%d: put MCAN into normal mode"), id);

    /* ...take MCAN out of the SW initialization mode */
    int     count = 0;
    MCAN_setOpMode(baseAddr, MCAN_OPERATION_MODE_NORMAL);
    while (MCAN_getOpMode(baseAddr) != MCAN_OPERATION_MODE_NORMAL)
    {
        if (++count < 100)
        {
            TaskP_sleep(10);
        }
        else
        {
            // TRACE(ERROR, _b("failed to set normal mode: %X"), MCAN_getOpMode(baseAddr));
            return -1;
        }
    }

   // (dev->desc.init ?  TRACE(DEBUG, _b("can%u: device-specific initialization"), id) : 0);

    /* ...do device-specific start-up */
    if (dev->desc.setup && dev->desc.setup(dev, id, 1) < 0)
    {
        // TRACE(ERROR, _x("can%u: failed to enable device"), id);
        return -1;
    }

    /* ...clear timestamp base */
    dev->ts_base = 0;

    /* ...enable MCAN interrupts except for "access to reserved register" and "timestamp-wraparound" */
    MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, 0U);
   // MCAN_enableIntr(baseAddr, MCAN_INTR_SRC_RES_ADDR_ACCESS | MCAN_INTR_SRC_TIMESTAMP_WRAPAROUND, 0U);
    MCAN_enableIntr(baseAddr, (MCAN_INTR_SRC_RX_FIFO0_NEW_MSG | MCAN_INTR_SRC_RX_FIFO1_NEW_MSG | MCAN_INTR_SRC_RX_FIFO0_FULL | MCAN_INTR_SRC_RX_FIFO1_FULL | MCAN_INTR_SRC_TRANS_COMPLETE), 1U);

    /* ...configure distribution of interrupts between lines (1 - RX, 0 - TX) */
  //  MCAN_selectIntrLine(baseAddr, MCAN_INTR_MASK_ALL, MCAN_INTR_LINE_NUM_1);
    MCAN_selectIntrLine(baseAddr, (MCAN_INTR_SRC_RX_FIFO0_NEW_MSG | MCAN_INTR_SRC_RX_FIFO1_NEW_MSG | MCAN_INTR_SRC_RX_FIFO0_FULL | MCAN_INTR_SRC_RX_FIFO1_FULL), MCAN_INTR_LINE_NUM_1);

    /* ...transmission completion interrupts are routed to line 0 */
    MCAN_selectIntrLine(baseAddr, MCAN_INTR_SRC_TRANS_COMPLETE , MCAN_INTR_LINE_NUM_0);

    /* ...enable RX-line first, TX-line second */
    MCAN_enableIntrLine(baseAddr, MCAN_INTR_LINE_NUM_1, 1U);
    MCAN_enableIntrLine(baseAddr, MCAN_INTR_LINE_NUM_0, 1U);

    /* ...enable external TS counter interrupt (pulse) */
   // MCAN_extTSEnableIntr(baseAddr, 1U);

    // TRACE(INIT, _b("can%u enabled"), id);

    return 0;
}

/**
 * \brief   Disable MCAN operation
 */

void mcan_disable(mcan_device_t *dev, uint32_t id)
{
    uint32_t    baseAddr = dev->desc.baseAddr;

    // TRACE(INIT, _b("can%u: disable device"), id);

    /* ...disable MCAN interrupts */
    MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, 0U);
    MCAN_selectIntrLine(baseAddr, MCAN_INTR_MASK_ALL, MCAN_INTR_LINE_NUM_0);
    MCAN_enableIntrLine(baseAddr, MCAN_INTR_LINE_NUM_0, 0U);
    MCAN_selectIntrLine(baseAddr, MCAN_INTR_MASK_ALL, MCAN_INTR_LINE_NUM_1);
    MCAN_enableIntrLine(baseAddr, MCAN_INTR_LINE_NUM_0, 1U);

    /* ...disable external TS counter */
    MCAN_extTSEnableIntr(baseAddr, 0U);
    MCAN_extTSCounterEnable(baseAddr, 0U);

    /* ...device specific disabling */
    if (dev->desc.setup && dev->desc.setup(dev, id, 0) < 0)
    {
        // TRACE(ERROR, _x("can%u: failed to disable device"), id);
    }

   // (dev->desc.setup ?  TRACE(INIT, _b("can%u: device-specific deinitialization done"), id) : 0);

    /* ...issue reset command */
    MCAN_setOpMode(baseAddr, MCAN_OPERATION_MODE_SW_INIT);

    /* ...wait for software reset completion */
    while (MCAN_getOpMode(baseAddr) != MCAN_OPERATION_MODE_SW_INIT)
        TaskP_sleep(1);

    // TRACE(INIT, _b("can%u device reset"), id);
}

/**
 * \brief   Get message length encoding for "DLC" field
 */
static inline uint8_t mcan_len2dlc(uint32_t len)
{
    if (len <= 8)       return len;
    if (len <= 24)      return (len - 8 + 3) / 4 + 8;
    if (len <= 64)      return (len - 24 + 15) / 16 + 12;
    return 15;
}


/**
 * \brief   Initiate transmission of CAN message
 */
int32_t mcan_xmit_start(mcan_device_t *dev, uint32_t id, canfd_frame_t *cf, uint32_t mm)
{
    uint32_t            baseAddr = dev->desc.baseAddr;
    uint32_t            can_id = cf->can_id;
    uint8_t             flags = cf->flags;
    uint8_t             len = cf->len;
    MCAN_TxFIFOStatus   txfs;
    MCAN_TxBufElement   buf;

    // TRACE(TXDBG, _b("can%u: can-id=%X, len: %u"), id, can_id, len);

    /* ...set transmission buffer parameters */
    buf.rtr = !!(can_id & CAN_RTR_FLAG);
    buf.xtd = !!(can_id & CAN_EFF_FLAG);
    buf.id = (can_id << (buf.xtd ? 0U : 18U)) & ((1U << 29U) - 1U);
    buf.esi = !!(flags & CANFD_ESI);
    buf.brs = !!(flags & CANFD_BRS);
    buf.fdf = !!(flags & MCAN_FDF);
    buf.efc = 1;
    buf.mm = mm;
    buf.dlc = mcan_len2dlc(len);
    memcpy(buf.data, cf->data, len);

    /* ...get current transmission buffer number */
    MCAN_getTxFIFOQueStatus(baseAddr, &txfs);
    if(txfs.fifoFull == 0)
    {     
    	MCAN_writeMsgRam(baseAddr, MCAN_MEM_TYPE_FIFO, txfs.putIdx, &buf);
    	MCAN_txBufTransIntrEnable(baseAddr, txfs.putIdx, TRUE);
    	MCAN_txBufAddReq(baseAddr, txfs.putIdx);

    	//// TRACE(TXDBG, _b("can%u: send buffer %u [id=%X, flags=%X, dlc=%u, len=%u]"), id, txfs.putIdx, buf.id, flags, buf.dlc, len);
        return 0;
    }
    else
    {
       return 1;

     }

#if 0
    /* ...allow 1-second timeout for sending? probably we don't need that at all */
    int count = 100;
    while ((MCAN_getTxBufReqPend(baseAddr) & (1 << txfs.putIdx)) != 0 && --count != 0)
        TaskP_sleep(10);

    if (count == 0)
    {
        // TRACE(ERROR, _x("buffer transmission timeout..."));
    }
#endif

    /* ...increment total amount of transmitted buffers? - tbd */
}



/*******************************************************************************
 * Runtime initialization
 ******************************************************************************/
/**> GPIO pinmux configuration */
#if 1
static pinmuxPerCfg_t gWkUp_gpio0PinCfg[] = {
    /* (G27) WKUP_GPIO0_56 */
    {
        PIN_WKUP_GPIO0_56, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};

#endif
/**> MCU-MCAN0 pinmux configuration */
static pinmuxPerCfg_t gMcu_mcan1PinCfg[] = {
   /* MCU_CAN1_RX -> F26 */
    {
        PIN_MCAN1_RX, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MCU_CAN1_TX -> C23 */
    {
        PIN_MCAN1_TX, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    {PINMUX_END}
};




/**> MCAN-specific pinmux configuration */
static pinmuxModuleCfg_t gMcanPinCfg[] = {
    {0, TRUE, gMcu_mcan1PinCfg},
//	{0, TRUE, gWkUp_gpio0PinCfg},
    {PINMUX_END}
};

/**> Global pinmux data */
static pinmuxBoardCfg_t gPinmuxDataInfo[] = {
    {0, gMcanPinCfg},
    {PINMUX_END}
};

/**> MCAN-specific pinmux configuration */
static pinmuxModuleCfg_t gGPIOPinCfg[] = {
 //   {0, TRUE, gMcu_mcan1PinCfg},
	{0, TRUE, gWkUp_gpio0PinCfg},
    {PINMUX_END}
};

/**> Global pinmux data */
static pinmuxBoardCfg_t gPinmuxGPIOInfo[] = {
    {0, gGPIOPinCfg},
    {PINMUX_END}
};

/*******************************************************************************
 * Entry point
 ******************************************************************************/


/*******************************************************************************
 * Entry point
 ******************************************************************************/
extern int32_t CAN_Send_test(uint32_t interface_id,uint8_t can_id);
/*******************************************************************************
 * Exported functions
 ******************************************************************************/

extern void US_Can_SetControllerState (uint8_t ControllerState);
uint16_t mcan_init(void)
{
    uint32_t    id;
    int32_t     status = 0;
    uint8_t     *Ver;
    
     US_Can_SetControllerState(0);
    /* ...update pinmux configuration for MCAN hardware */
    Board_pinmuxUpdate(gPinmuxDataInfo, BOARD_SOC_DOMAIN_MAIN);
    Board_pinmuxUpdate(gPinmuxGPIOInfo, BOARD_SOC_DOMAIN_WKUP);

    /* ...initialize MCAN devices */
    for (id = 1; id < 2; id++)
    {
        mcan_device_t  *dev =  &mcan_device[id];
       mcan_setup(dev, id);
      if ((status = mcan_enable(dev, id)) < 0)
      {
                // TRACE(ERROR, _x("failed to start can#%d '%s' device: %d"), id, dev->name, status);
      }
      else
       {
                // TRACE(INIT, _b("can%d started successfully"), id);
                 Ver = GetSoftwareVersion();
                US_can_tx_packet(0x41,Ver[0],Ver+1);
                US_Can_SetControllerState(1);
       }
    } 

    // TRACE(INIT, _b("MCAN module initialized"));
     return (uint16_t)status;
}
#endif

uint16_t US_can_tx_packet(uint32_t can_id, uint8_t len, uint8_t *data)
{
   #if (0 != (US_D_CUR_CAN_PLATFORM & US_D_CAN_PLATFORM_CVADAS))

       mcan_device_t *dev;
       canfd_frame_t fr;
       if (len > 64) {
           return 0xff10;
       }
       memset(&fr, 0, sizeof(fr));
       fr.can_id = can_id;
       fr.len = len;
       if(len > 8)
       {
          fr.flags |= MCAN_FDF;
       }
       fr.flags |= CANFD_BRS;
       memcpy(fr.data,data,len);
       dev = &mcan_device[MCAN_DEV_MCU_MCAN1];
       return (uint16_t)mcan_xmit_start(dev, MCAN_DEV_MCU_MCAN1, &fr, 0xff);
	   #else
	   return 0;
	   #endif
}

/**
 * \brief   Initialize MCAN module
 */

uint16_t US_mcan_init(void)
{
    int32_t     status = ME_OK;
  #if (0 != (US_D_CUR_CAN_PLATFORM & US_D_CAN_PLATFORM_CVADAS))
    uint32_t    id;
    uint8_t     *Ver;
     US_Can_SetControllerState(0);
    /* ...update pinmux configuration for MCAN hardware */
  //  Board_pinmuxUpdate(gPinmuxDataInfo, BOARD_SOC_DOMAIN_WKUP);

   // status = Board_pinmuxUpdate(gPinmuxDataInfo, BOARD_SOC_DOMAIN_MAIN);
    status = Board_pinmuxUpdate(gPinmuxDataInfo, BOARD_SOC_DOMAIN_MAIN);
    Board_pinmuxUpdate(gPinmuxGPIOInfo, BOARD_SOC_DOMAIN_WKUP);

    GPIOSetDirMode_v0(CSL_WKUP_GPIO0_BASE, 56, GPIO_DIRECTION_OUTPUT);
  	
    GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE, 56, (GPIO_PIN_LOW));
 
 
 /* ...initialize MCAN devices */
    for (id = 0; id < 1; id++)
    {
        mcan_device_t  *dev =  &mcan_device[id];
       mcan_setup(dev, id);
      if ((status = mcan_enable(dev, id)) < 0)
      {
                break;
      }
      else
       {
                // TRACE(INIT, _b("can%d started successfully"), id);
                Ver = GetSoftwareVersion();
                US_can_tx_packet(0x41,Ver[0],Ver+1);
                US_Can_SetControllerState(1);
       }
    } 

#endif
     return (uint16_t)status;
}



