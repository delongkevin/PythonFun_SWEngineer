/**
 * @file pmic.c
 * @brief PMIC driver to handle external watchdog
 *
 * @details This file provides interface to initilaize PMIC and pet watchdog periodically
 *
 * --------------------------------------------------------------------------
 * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *
 *   This is an unpublished work of authorship, which contains
 *   trade secrets, created in 2023.  Magna Electronics owns all
 *   rights to this work and intends to maintain it in confidence
 *   to preserve its trade secret status.  Magna Electronics
 *   reserves the right, under the copyright laws of the United
 *   States or those of any other country that may have jurisdiction,
 *   to protect this work as an unpublished work, in the event of
 *   an inadvertent or deliberate unauthorized publication.
 *   Magna Electronics also reserves its rights under all copyright
 *   laws to protect this work as a published work, when appropriate.
 *   Those having access to this work may not copy it, use it,
 *   modify it, or disclose the information contained in it without
 *   the written authorization of Magna Electronics.
 *
 * --------------------------------------------------------------------------
 * @author Pramod Kumar (Pramod.kumar1@magna.com)
 */
 
/* ===========================================================================
*
*   Include Files
*
* ========================================================================= */

#include <ti/drv/sciclient/sciclient.h>
#include <ti/csl/csl_gpio.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>
#include <ti/csl/arch/csl_arch.h>

#include <ti/board/board.h>
#include <ti/board/src/j721s2_hyd/include/board_cfg.h>
#include <ti/board/src/j721s2_hyd/include/board_control.h>
#include <ti/board/src/j721s2_hyd/include/board_pinmux.h>
#include <ti/board/src/j721s2_hyd/include/board_utils.h>


/* CSL Header files */
#include <ti/csl/csl_types.h>
#include <ti/csl/soc.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_timer.h>

/* OSAL Header files */
#include <ti/osal/osal.h>

/* Board Header files */
#include <ti/board/src/devices/common/common.h>
#include <ti/board/src/j721s2_hyd/include/board_power.h>

#include <ti/drv/gpio/GPIO.h>

#include <ti/drv/i2c/I2C.h>

#include "pmic.h"
#include "pmic_cfg.h"
#include "app_log_Boot.h"
#include "Os_Lcfg.h"
#include "pmic_voltmon.h"
#include "pmic_error.h"
#include "pmic_readback.h"
#include "pmic_mcu_esm.h"
#include "pmic_thermal_warn_shutdown.h"
#include "pmic_reg_lock.h"
#include "I2c_PerMgr.h"
#include "pmic_utils.h"
#include "Enums.h"

#include "boot_cfg.h"
#include "tps65941_Reg.h"
#include "pmic_crc_mon.h"
#include "Tasks.h"

/* ===========================================================================
*
*   Defines
*
* ========================================================================= */

#define PMIC_PETTING_WAIT_TIME        (200U)  /* 200 * 10ms = 2 seconds wait time before petting the watchdog */
#define PMIC_WRITE_REG_ARRAY_SIZE     (16U)
#define PMIC_DELAY_2ms                (0x2U)   
#define PMIC_DELAY_5ms                (0x5U)

/* ===========================================================================
*
* Typedefs
*
* ========================================================================= */

/* ===========================================================================
*
* Private functions
*
* ========================================================================= */

static void Pmic_f_InitVar_v(void);

/* ===========================================================================
*
*   Private variables
*
* ========================================================================= */
/* Pmic Ext Wdg State machine variable */
static PmicExtWdgSt_t V_PmicExtWdgSmSt_e = e_PmicExtWdgSt_UNINIT;
static uint8_t V_PmicWindow1Tmr_u8 = 0U;

/* Flag to indicate request received to stop petting Wdg */
static uint8_t V_PmicStopPettingWdg_u8 = (uint8_t)FALSE;
static uint8_t gbPMICMonEnable = (uint8_t)FALSE;

/* ===========================================================================
*
*   Global variables
*
* ========================================================================= */

extern void EEP_Shutdown(void);

/* ========================================================================== */
/*                          Function Implementation                           */
/* ========================================================================== */
/*!
 * \brief   PMIC Critical section Lock function
 *          This function should have OS specific locking setup and should
 *          assigned to 'pmicConfigData->pFnPmicCritSecStart'
 */
void pmic_criticalSectionStartFn(void)
{
    /* DD-ID:{5F620929-3DE6-4214-97EA-53C7D271EFF6}*/
    if(GetIsOSInitialized() == TRUE)
    {
        (void)GetResource(OsResource_PMIC);
    } else{ /* Do Nothing */}
}

/*!
 * \brief   PMIC Critical section Unlock function
 *          This function should have OS specific locking setup and should
 *          assigned to 'pmicConfigData->pFnPmicCritSecStop'
 */
void pmic_criticalSectionStopFn(void)
{
    /* DD-ID:{379F2CCA-6457-49e5-8249-253DE2D81A3E}*/
    if(GetIsOSInitialized() == TRUE)
    {
        (void)ReleaseResource(OsResource_PMIC);
    } else{ /* Do Nothing */}
}

/**********************************************************************************************************************
 *  I2c_IrqUnit1()
 *********************************************************************************************************************/
/*!
 * \internal
 * - Forward call to interrupt handler for specific hardware unit id.
 * \endinternal
 */
ISR(I2c_IrqUnit1)
{
    /* DD-ID:{CD746BEF-52C7-4abb-9A27-D037B36F9B93}*/
  I2c_PerMgr_IrqHandler(1);
}

/*!
 * \brief   PMIC I2C read function.
 *
 * \param   pmicCorehandle [IN]     PMIC Interface Handle.
 * \param   commMode       [IN]     Communication Mode
 * \param   slaveAddr      [IN]     I2c device slave address
 * \param   regAddr        [OUT]    Register address to read from.
 * \param   pBuf           [IN]     Buffer to store data
 * \param   bufLen         [IN]     Length of data to read.
 *
 * \retval  PMIC_ST_SUCCESS in case of success or appropriate error code
 *          For valid values see \ref Pmic_ErrorCodes
 */
int32_t pmic_regRead(Pmic_CoreHandle_t  *pmicCorehandle,
                     uint8_t             instType,
                     uint16_t            regAddr,
                     uint8_t            *pBuf,
                     uint8_t             bufLen)
{
    /* DD-ID:{A25C97A4-CC6B-408b-8385-7075C2E23EFF}*/
    int32_t ret = 0;
    static I2C_Transaction rdTransaction = {0};
    static uint8_t i2c_ReadDataBuff[PMIC_WRITE_REG_ARRAY_SIZE] = {0U};

    if(((uint8_t)PMIC_INTF_SINGLE_I2C == pmicCorehandle->commMode) ||
       ((uint8_t)PMIC_INTF_DUAL_I2C   == pmicCorehandle->commMode))
    {
        I2C_transactionInit(&rdTransaction);
        (void)memset(&i2c_ReadDataBuff[0], 0x0, PMIC_WRITE_REG_ARRAY_SIZE);
        (void)memcpy(&i2c_ReadDataBuff[0], pBuf, bufLen);
       /* Set register offset for read and write */
        rdTransaction.readBuf    = i2c_ReadDataBuff;
        rdTransaction.readCount  = bufLen;
        rdTransaction.writeBuf   = &regAddr;
        rdTransaction.writeCount = 1U;

        /* Main I2c BUS */
        if(PMIC_NVM_INST == instType)
        {
            rdTransaction.slaveAddress = pmicCorehandle->nvmSlaveAddr;
        }
        else if(PMIC_QA_INST == instType)
        {
            rdTransaction.slaveAddress = pmicCorehandle->qaSlaveAddr;
        }
        else
        {
            rdTransaction.slaveAddress = pmicCorehandle->slaveAddr;
        }
        if((uint32_t)0x00u != rdTransaction.slaveAddress)
        {
            /* Handle is same for all the slaves as Single I2c is used */
            ret = (int32_t)I2C_transfer((I2C_Handle)pmicCorehandle->pCommHandle,
                                &rdTransaction);
            if(ret != I2C_STS_SUCCESS)
            {
                ret = PMIC_ST_ERR_I2C_COMM_FAIL;
            }
            else
            {
                (void)memcpy(pBuf, &i2c_ReadDataBuff[0], bufLen);
                ret = PMIC_ST_SUCCESS;
            }
            //APP_log(APP_LOG_MAX,"I2c read instance 0x%x %d %d %d \n", rdTransaction.slaveAddress, regAddr, pBuf[0], pBuf[1]);
        }
        else
        {
            ret = PMIC_ST_ERR_INV_PARAM;
        }
    }

    return ret;
}

/*!
 * \brief   PMIC I2C write function.
 *
 * \param   pmicCorehandle   [IN]     PMIC Interface Handle.
 * \param   commMode         [IN]     Communication Mode
 * \param   slaveAddr        [IN]     I2c device slave address
 * \param   regAddr          [IN]     Register address to write.
 * \param   pBuf             [IN]     Buffer to store data to write
 * \param   bufLen           [IN]     Length of data to write.
 *
 * \retval  PMIC_ST_SUCCESS in case of success or appropriate error code
 *          For valid values see \ref Pmic_ErrorCodes
 */
int32_t pmic_regWrite(Pmic_CoreHandle_t  *pmicCorehandle,
                      uint8_t             instType,
                      uint16_t            regAddr,
                      uint8_t            *pBuf,
                      uint8_t             bufLen)
{
    /* DD-ID:{614B7BAC-FBB4-4b9c-82A0-D767D0492FFB}*/
    int32_t  ret = 0;
    static I2C_Transaction wrTransaction;
    static uint8_t i2c_WriteDataBuff[PMIC_WRITE_REG_ARRAY_SIZE];

    if(((uint8_t)PMIC_INTF_SINGLE_I2C == pmicCorehandle->commMode) ||
       ((uint8_t)PMIC_INTF_DUAL_I2C   == pmicCorehandle->commMode))
    {

        /* regAddr, 8-bit-Data, 8-bit-CRC(optional) => max 3 bytes
         * Taking a databuff of size 3 only as it is enough
         */
        (void)memset(&i2c_WriteDataBuff[0], 0x0, PMIC_WRITE_REG_ARRAY_SIZE);

        /* Initializes the I2C transaction structure with default values */
        I2C_transactionInit(&wrTransaction);

        if(PMIC_NVM_INST == instType)
        {
            wrTransaction.slaveAddress = pmicCorehandle->nvmSlaveAddr;
        }
        else if(PMIC_QA_INST == instType)
        {
            wrTransaction.slaveAddress = pmicCorehandle->qaSlaveAddr;
        }
        else
        {
            wrTransaction.slaveAddress = pmicCorehandle->slaveAddr;
        }

        i2c_WriteDataBuff[0U] = (uint8_t)regAddr;
        (void)memcpy(&i2c_WriteDataBuff[1U], pBuf, bufLen);
        //APP_log(APP_LOG_MAX, "I2c write instance 0x%x 0x%x 0x%x 0x%x\n", wrTransaction.slaveAddress, i2c_WriteDataBuff[0U], i2c_WriteDataBuff[1U], i2c_WriteDataBuff[2U]);

        /* Control Byte followed by write bit */
        wrTransaction.writeBuf     = i2c_WriteDataBuff;
        wrTransaction.writeCount   = bufLen + 1U;
        wrTransaction.readCount    = 0U;
        wrTransaction.readBuf      = NULL;
        if((uint32_t)0x00u != wrTransaction.slaveAddress)
        {
            /* Main I2c BUS */
            ret = I2C_transfer((I2C_Handle)pmicCorehandle->pCommHandle,
                                    &wrTransaction);
            if(ret != I2C_STS_SUCCESS)
            {
                ret = PMIC_ST_ERR_I2C_COMM_FAIL;
            }
            else
            {
                ret = PMIC_ST_SUCCESS;
            }
        }
        else
        {
            ret = PMIC_ST_ERR_INV_PARAM;
        }
    }

    return ret;
}

static int32_t pmic_I2cLldIntfSetup(Pmic_CoreCfg_t  *pPmicConfigData,
                                            uint8_t          instType)
{
    /* DD-ID:{2EC39883-E85E-41c2-9920-C268D42B0C2D}*/
    I2C_Handle i2cHandle;

    i2cHandle = Board_getI2CHandle((uint8_t)BOARD_SOC_DOMAIN_WKUP, (uint32_t)BOARD_PMIC_I2C_INSTANCE);

    if(instType == PMIC_MAIN_INST)
    {
        pPmicConfigData->pCommHandle = i2cHandle;
    }
    /* For WDOG QA I2C BUS */
    else if(PMIC_QA_INST == instType)
    {
         /* Support only single i2c interface */
    }
    else
    {
        /* Do nothing */
    }

    return 0;

}

/*!
 * \brief   Initialize PMIC Instance and corresponding Interface.
 *
 * \param   pmicCoreHandle    [OUT]     PMIC Core Handle.
 *
 * \retval  PMIC_ST_SUCCESS in case of success or appropriate error code.
 *          For valid values see \ref Pmic_ErrorCodes
 */
static int32_t pmic_appInit(Pmic_CoreHandle_t *pmicCoreHandle,
                            Pmic_CoreCfg_t    *pmicConfigData,
                            pmic_device_t     *pmicDeviceData)
{
    /* DD-ID:{086C409E-5422-4b68-B60A-7BD586A7C925}*/
    int32_t pmicStatus = PMIC_ST_SUCCESS;
    uint8_t i2c1SpiCrcStatus = 0u, i2c2CrcStatus = 0u;
    uint8_t i2c1Speed, i2c2Speed;

    if(pmicCoreHandle == NULL)
    {
        #ifdef PMIC_PRINT_ENABLE
        APP_log(APP_LOG_ERR,"\n [%s] Invalid PMIC core Handle Reference \n", pmicDeviceData->name);
        #endif
        return PMIC_ST_ERR_INV_HANDLE;
    } else{ /* Do Nothing */}

    if(pmicConfigData == NULL)
    {
        #ifdef PMIC_PRINT_ENABLE
        APP_log(APP_LOG_ERR,"\n [%s] Invalid PMIC config Data - NULL \n", pmicDeviceData->name);
        #endif
        return PMIC_ST_ERR_NULL_PARAM;
    } else{ /* Do Nothing */}

    #ifdef PMIC_PRINT_ENABLE
    APP_log(APP_LOG_MAX,"\n PMIC Commode - %d \n", pmicConfigData->commMode); /*  PRQA S 2880*//* URAT Print Lib is not Included in QAC includes */
    #endif

    pmicStatus = pmic_I2cLldIntfSetup(pmicConfigData, PMIC_MAIN_INST);

    if(0 == pmicStatus)
    {
        /* For single I2C Instance */
        if((uint8_t)PMIC_INTF_SINGLE_I2C == pmicConfigData->commMode)
        {
            pmicConfigData->instType = PMIC_MAIN_INST;  /*  PRQA S 4499*//* The SDL lib code not advise to change the Macro definition */
            pmicCoreHandle->deviceNum = pmicDeviceData->deviceNum;
            /* Get PMIC core Handle for Main Instance */
            pmicStatus = Pmic_init(pmicConfigData, pmicCoreHandle);
            pmicDeviceData->pmicInitCompleted = true;
        }

        /* For DUAL I2C Instance */
        else if((uint8_t)PMIC_INTF_DUAL_I2C == pmicConfigData->commMode)
        {
            /* Not supported */
            pmicStatus = PMIC_ST_ERR_I2C_COMM_FAIL;
        }

        /* For SPI Instance */
        else if((uint8_t)PMIC_INTF_SPI  == pmicConfigData->commMode)
        {
            /* SPI interface is not supported */
            pmicStatus = PMIC_ST_ERR_SPI_COMM_FAIL;
        }
        else
        {
            pmicStatus = PMIC_ST_ERR_INV_PARAM;
        }
    } else{ /* Do Nothing */}

    /*
     * Check for Warning message due to Invalid Device ID.
     * And continue the application with WARNING message.
     */
    if(PMIC_ST_WARN_INV_DEVICE_ID == pmicStatus)
    {
        #ifdef PMIC_PRINT_ENABLE
        APP_log(APP_LOG_ERR,"\n [%s] *** WARNING: Found Invalid DEVICE ID ***\n\n", pmicDeviceData->name);
        #endif
        pmicStatus = 0;
    } else{ /* Do Nothing */}
    #if 0
    if(PMIC_DEV_0 == pmicDeviceData->deviceNum)
    {
        Pmic_utils_read(&pmic_device[PMIC_DEV_2].pmicCoreHandle, D_PMIC_TPS65941_USER_SPARE_REGS, &pmic_lastReset);
        if(0x0 != pmic_lastReset)
        {
            /* Clear the user spare regs for storing next soft reboot reason */

            #ifdef PMIC_PRINT_ENABLE
            APP_log(APP_LOG_ERR, "Last Reset was SafeState2 - %d %d \n", pmic_lastReset, pmicDeviceData->CurRecoveryCounter);
            #endif
        }
    }
    #endif
    if((0 == pmicStatus) && (true == pmicDeviceData->rdIntr))
    {
        (void)Pmic_utils_ReadInterrupts(pmicCoreHandle, false, (Pmic_IrqStatus_t*)&pmicDeviceData->errStat);
    } else{ /* Do Nothing */}
    if(((uint8_t)PMIC_DEV_0 == pmicDeviceData->deviceNum) &&
        (Pmic_intrBitGet((Pmic_IrqStatus_t*)&pmicDeviceData->errStat, PMIC_TPS6594X_WD_RST_INT) == (uint8_t)0x1u))
    {
        pmic_lastReset = SAFESTATE_REASON_PMIC_WDG_RESET_MCU1_0;
        #ifdef PMIC_PRINT_ENABLE
        APP_log(APP_LOG_ERR, "Last Reset was WDG Reset - %d \n", pmicDeviceData->CurRecoveryCounter);
        #endif
    } else{ /* Do Nothing */}    
    pmicStatus = Pmic_F_RegUnLockMon_v(pmicDeviceData->deviceNum);
    if(0 == pmicStatus)
    {
        pmicStatus = Pmic_utils_ClearInterrupts(pmicCoreHandle, (uint8_t)pmicDeviceData->clrIrqSts);
    } else{ /* Do Nothing */}
    if((0 == pmicStatus) && (true == pmicDeviceData->clrRecovCounter))
    {
        pmicStatus = Pmic_utils_tps65941RecovCounterClear(pmicCoreHandle);
    } else{ /* Do Nothing */}
    if((0 == pmicStatus) && (true == pmicConfigData->crcEnable))
    {
        pmicStatus = Pmic_enableCRC(pmicCoreHandle);
        if(0 == pmicStatus)
        {
            pmicCoreHandle->crcEnable = true;
            (void)Osal_delay(PMIC_DELAY_2ms);
        } else{ /* Do Nothing */}
        if(0 == pmicStatus)
        {
            pmicStatus = Pmic_getCrcStatus(pmicCoreHandle,
                                       &i2c1SpiCrcStatus,
                                       &i2c2CrcStatus);
        } else{ /* Do Nothing */}
        if((uint8_t)D_PMIC_CRC_ENABLED != i2c1SpiCrcStatus)
        {
			#ifdef PMIC_PRINT_ENABLE
            APP_log(APP_LOG_ERR," [%s] Enable CRC Failed - %d \n", pmicDeviceData->name, pmicStatus);
			#endif
        } else{ /* Do Nothing */}
		#ifdef PMIC_PRINT_ENABLE
        APP_log(APP_LOG_MAX,"\r\n [%s] enableCRC - pmicStatus %d crcEnable %d i2c1CrcStatus %d i2c2CrcStatus %d\r\n",pmicDeviceData->name, pmicStatus, pmicCoreHandle->crcEnable, i2c1SpiCrcStatus, i2c2CrcStatus);
		#endif
    } else{ /* Do Nothing */}

    if(0 == pmicStatus)
    {
        /* Setup I2C1 Speed based on commMode */
        pmicStatus = Pmic_setI2CSpeedCfg(pmicCoreHandle);
        if(0 == pmicStatus)
        {
            /* Get configured value for I2C1 Speed based on commMode */
            pmicStatus = Pmic_getI2CSpeed(pmicCoreHandle, &i2c1Speed,
                                          &i2c2Speed);
        } else{ /* Do Nothing */}

        if(0 == pmicStatus)
        {
            if((uint8_t)PMIC_I2C_STANDARD_MODE == i2c1Speed)
            {
                pmicStatus = 0;
            }
            else
            {
                pmicStatus = -1;
            }
        } else{ /* Do Nothing */}
    } else{ /* Do Nothing */}

    if((0 == pmicStatus) && (true == pmicDeviceData->checkWdgConfig))
    {
        pmicStatus = Pmic_utils_tps65941CheckWdtConfig(pmicCoreHandle, wdgCfg);
        if(0 != pmicStatus)
        {
			#ifdef PMIC_PRINT_ENABLE
            APP_log(APP_LOG_ERR,"WDG_CHECK: 0x%x \n",pmicStatus);
			#endif
            pmicStatus = PMIC_ST_ERR_WDG_CONFIG;
        }
        else
        {
			#ifdef PMIC_PRINT_ENABLE
            APP_log(APP_LOG_MAX,"WDG_CHECK: 0x%x \n",pmicStatus);
			#endif
        }
    } else{ /* Do Nothing */}

    if(0 != pmicStatus)
    {
        #ifdef PMIC_PRINT_ENABLE
        APP_log(APP_LOG_ERR,"[%s] pmicStatus: %d \n",pmicDeviceData->name,  pmicStatus);
        #endif
    }
    else
    {
		#ifdef PMIC_PRINT_ENABLE
        APP_log(APP_LOG_MAX,"[%s] pmicStatus: %d \n",pmicDeviceData->name,  pmicStatus);
		#endif
    }

    return pmicStatus;
}

/**
 * @brief   PMIC device initialization
 */
static inline int32_t pmic_device_init(pmic_device_t *dev, uint32_t id)
{
    /* DD-ID:{C820029F-ABF5-4032-B766-89BEFF4BD544}*/
    int32_t pmicStatus;

    pmicStatus = pmic_appInit(&dev->pmicCoreHandle, &dev->pmicConfigData, dev);

    if (PMIC_ST_SUCCESS != pmicStatus)
    {
        #ifdef PMIC_PRINT_ENABLE
        APP_log(APP_LOG_ERR,"[%s] pmic%u: failed to init \n", dev->name, id);
        #endif
        return -1;
    } else{ /* Do Nothing */}

    return 0;
}


/*
 * Purpose: Initialize global variable used by PMIC driver.
 * Description: Initialize global variable used by PMIC driver.
 * Return Type : void
 */
static void Pmic_f_InitVar_v(void)
{
    /* DD-ID:{57CF12D5-C206-4135-A088-2836571F5015}*/
    /* Initialize PMIC WDG state machine state to INIT */
    V_PmicExtWdgSmSt_e = e_PmicExtWdgSt_INIT;

    /* Initialize other variable used by state machine */
    V_PmicWindow1Tmr_u8 = (uint8_t)0;

}

sint32 Pmic_AppEnterInLongWindow(void)
{
    /* DD-ID:{DD90D008-6479-46fb-8E4E-1262C9B883ED}*/
    int32_t WdgDisableStat = D_PMIC_WDG_DISABLE_SUCCESS;
    int32_t pmicStatus;
    uint8_t wdgFirstOkStat, WdgFirstOnInSequence;
    uint32_t WdgDisableTimeout = 0u;
    uint8_t u8GPIO2Cfg = 0u;

    /* Unlock the Registers to Write 0x32 PMIC Register */
    (void)Pmic_F_RegUnLockMon_v(pmic_device[PMIC_DEV_0].deviceNum);

    /* Configure GPIO2 to value 0x1F this will let PMIC knows that PMIC is no longer configured in Wdg Trigger mode
	to avoid PMIC going into long window when PIN-87 goes high or by default pulled high in case of Sci-Client reset */
    (void)Pmic_utils_Write(&pmic_device[PMIC_DEV_0].pmicCoreHandle, D_PMIC_TPS65941_GPIO2_CONF, u8GPIO2Cfg);

    pmicStatus = Pmic_utils_tps65941GetWdtFirstOkStat(&pmic_device[PMIC_DEV_0].pmicCoreHandle, &wdgFirstOkStat);
    /* check if wdg Fisrt Ok Status is set during normal sequence */
    if((uint8_t)BOARD_TPS65941_WDT_FIRST_OK == wdgFirstOkStat)
    {
        WdgFirstOnInSequence = 1u;
    }
    else
    {
        WdgDisableStat |= D_PMIC_WDG_WRONG_SEQUENCE_MASK;
    }

    /* Set Wdg to Long window */
    pmicStatus = Pmic_WdgSetRetToLongWindowCfg(&pmic_device[PMIC_DEV_0].pmicCoreHandle, PMIC_WDG_RETLONGWIN_ENABLE);
    if(pmicStatus != PMIC_ST_SUCCESS)
    {
        /* Retry if fails - This is unlikely*/
        pmicStatus = Pmic_WdgSetRetToLongWindowCfg(&pmic_device[PMIC_DEV_0].pmicCoreHandle, PMIC_WDG_RETLONGWIN_ENABLE);
        /* if it still failed - TBD Decide what to do */
        if(pmicStatus != PMIC_ST_SUCCESS)
        {
            WdgDisableStat |= D_PMIC_WDG_LONGWINDOW_I2C_FAIL_MASK;
        } else{ /* Do Nothing */}
    } else{ /* Do Nothing */}

    if(pmicStatus == PMIC_ST_SUCCESS)
    {
        /* Wait until First OK Status is cleared - This happens when the Wdg is in long window */
        (void)Pmic_utils_tps65941GetWdtFirstOkStat(&pmic_device[PMIC_DEV_0].pmicCoreHandle, &wdgFirstOkStat);

        while(((uint8_t)BOARD_TPS65941_WDT_FIRST_OK == wdgFirstOkStat) && ( (uint32_t)D_PMIC_WDG_DISABLE_TIMEOUT > WdgDisableTimeout))
        {
            (void)Osal_delay(PMIC_DELAY_5ms);
            WdgDisableTimeout++;
            (void)Pmic_utils_tps65941GetWdtFirstOkStat(&pmic_device[PMIC_DEV_0].pmicCoreHandle, &wdgFirstOkStat);
            #ifdef PMIC_PRINT_ENABLE
            APP_log(APP_LOG_MAX,"PMIC first ok State %d %d %d \n", wdgFirstOkStat, WdgDisableTimeout, pmicStatus); /*  PRQA S 2880*//* URAT Print Lib is not Included in QAC includes */
            #endif
        }

        if(WdgDisableTimeout >= D_PMIC_WDG_DISABLE_TIMEOUT)
        {
            WdgDisableStat |= D_PMIC_WDG_DISABLE_TIMEOUT_MASK;
        } else{ /* Do Nothing */}        
    } else{ /* Do Nothing */}

#if 0
    /* if its timeout, sleep and reset should work fine. For Bootloader flashing, it will fail - need to handle it */
    /* if it comes out of this while loop then its in long window or timeout happened */
    pmicStatus = Pmic_wdgDisable(&pmic_device[PMIC_DEV_0].pmicCoreHandle);

    if(pmicStatus != PMIC_ST_SUCCESS)
    {
        /* Retry if fails - This is unlikely*/
        pmicStatus = Pmic_wdgDisable(&pmic_device[PMIC_DEV_0].pmicCoreHandle);
        /* if it still failed - TBD Decide what to do */
        if(pmicStatus != PMIC_ST_SUCCESS)
        {
            WdgDisableStat |= D_PMIC_WDG_DISABLE_I2C_FAIL_MASK;
        }
    }
#endif
    //APP_log(APP_LOG_ERR,"\n PMIC WDG Disable %d %d %d \n", wdgFirstOkStat, WdgDisableTimeout, WdgDisableStat);
    return WdgDisableStat;
}

/* ===========================================================================
*
*   Global functions
*
* ========================================================================= */
int32_t Pmic_F_EarlyInit_s32(void)
{
    /* DD-ID:{D5D0F192-03B0-49b2-9685-64A39E0EFA56}*/
    int32_t status;
    I2C_Handle pmicEarlyHandle;
    uint32_t    v_id_u8;
    uint8_t v_crcStatus_u8;
    uint8_t regData;
    //while(debug_wdgpmic == 1);

    pmicEarlyHandle = Board_getI2CHandle((uint8_t)BOARD_SOC_DOMAIN_WKUP, (uint32_t)BOARD_PMIC_I2C_INSTANCE);

    for (v_id_u8 = 0u; v_id_u8 < (uint32_t)PMIC_DEV_NUM; v_id_u8++)
    {
        pmic_device[v_id_u8].pmicCoreHandle.deviceNum = pmic_device[v_id_u8].deviceNum;
    }

    /* Check Recovery Register and if its equal to threshold, clear the recovery counter and stay here forever,
     CAN transceiver will move to sleep after 4 mins */
    status = Pmic_utils_CheckRecoveryCounter();

    /* if its a reset which does not affect PMIC, we need to make sure the previous cycle settings 
     should be honoured */
    v_crcStatus_u8 = Pmic_utils_getCRCStatus();

    if((uint8_t)D_PMIC_CRC_ENABLED == v_crcStatus_u8)
    {
        pmic_device[PMIC_DEV_0].pmicConfigData.instType = PMIC_MAIN_INST; /*  PRQA S 4499*//* The SDL lib code not advise to change the Macro definition */
        pmic_device[PMIC_DEV_0].pmicConfigData.pCommHandle = pmicEarlyHandle;
        /* Get PMIC core Handle for Main Instance */
        status |= Pmic_init(&pmic_device[PMIC_DEV_0].pmicConfigData, &pmic_device[PMIC_DEV_0].pmicCoreHandle);
        pmic_device[PMIC_DEV_0].pmicCoreHandle.crcEnable = true;
    } else{ /* Do Nothing */}

    status |= Pmic_utils_WdgSetConfig(wdgCfg);

    if(PMIC_ST_SUCCESS != status)
    {
        Pmic_utils_SoftReboot(SAFESTATE_REASON_PMIC_WDG_CFG_FAIL);
    } else{ /* Do Nothing */}

    /* Configuration of petting Wdg pin */
    (void)GPIOPinWrite_v0((uint32_t)CSL_WKUP_GPIO0_BASE, D_PMIC_WDG_TRIG_PIN1, GPIO_PIN_LOW);

    /* Configure GPIO2_SEL bit from GPIO2_CONF Register to TRIG_WDOG mode */
    (void)Pmic_utils_Write(&pmic_device[PMIC_DEV_0].pmicCoreHandle, D_PMIC_TPS65941_GPIO2_CONF, D_PMIC_GPIO2_CFG);
    (void)Pmic_utils_read(&pmic_device[PMIC_DEV_0].pmicCoreHandle, D_PMIC_TPS65941_GPIO2_CONF, &regData);

    /* Trigger safe state 2 if PMIC is not configured in Wdg Trigger mode */
    if((uint8_t)D_PMIC_GPIO2_CFG != regData)
    {
        Pmic_utils_SoftReboot(SAFESTATE_REASON_PMIC_GPIO2_CFG_FAIL);
    } else{ /* Do Nothing */}

    if((uint8_t)D_PMIC_CRC_ENABLED == v_crcStatus_u8)
    {
        pmic_device[PMIC_DEV_0].pmicConfigData.instType = 0u;
        pmic_device[PMIC_DEV_0].pmicConfigData.pCommHandle = NULL;
        /* Deinit PMIC core Handle for Main Instance */
        status |= Pmic_deinit(&pmic_device[PMIC_DEV_0].pmicCoreHandle);
    } else{ /* Do Nothing */}

    status |= Board_releaseI2CHandle(pmicEarlyHandle);

    for (v_id_u8 = 0u; v_id_u8 < (uint32_t)PMIC_DEV_NUM; v_id_u8++)
    {
        pmic_device[v_id_u8].earlyConfigDone = true;
    }

    return status;
}

/* ===========================================================================
*
*   Global functions
*
* ========================================================================= */
/*
 * Purpose: PMIC module initialization.
 * Description: Initialize and configure PMIC and its interfaces.
 * Return Type : int32_t (0 -> No error, -1 -> Error)
 */
int32_t Pmic_F_Init_s32(void)
{
    /* DD-ID:{4125141B-5AB1-4ef3-9B58-85BC0E2D56AE}*/
    int32_t     v_ret_s32 = 0;
#ifdef ENABLE_PMIC_EXTWDG
    uint32_t    v_id_u32;
    int32_t     v_status_s32;
    I2C_Handle  pmic_handle;

    /* Get I2C Handle */
    //pmic_handle = Board_initI2C_pmic_main();
    pmic_handle = Board_getI2CHandle((uint8_t)BOARD_SOC_DOMAIN_WKUP, (uint32_t)BOARD_PMIC_I2C_INSTANCE);

    if (NULL != pmic_handle)
    {
        for (v_id_u32 = 0u; v_id_u32 < (uint32_t)PMIC_DEV_NUM; v_id_u32++)        
        {
            /* set i2c handle */
            pmic_device[v_id_u32].pmicConfigData.pCommHandle = pmic_handle;

            /* Init PMIC device */
            if ((v_status_s32 = pmic_device_init(&pmic_device[v_id_u32], v_id_u32)) < 0)
            {
               #ifdef PMIC_PRINT_ENABLE
               APP_log(APP_LOG_ERR,"pmic%u module initialization failure: %d\n", v_id_u32, v_status_s32);
               #endif
                v_ret_s32 = -1;
                /*Enter SafeState */
                Pmic_utils_SoftReboot(SAFESTATE_REASON_PMIC_INIT_FAIL);
            } else{ /* Do Nothing */}

            if((0 == v_status_s32) && (true == pmic_device[v_id_u32].rdDeviceInfo))
            {
                (void)Pmic_getDeviceInfo((Pmic_CoreHandle_t*)&pmic_device[v_id_u32].pmicCoreHandle, (Pmic_DeviceInfo_t*)&pmic_device[v_id_u32].st_deviceinfo);
            	#ifdef PMIC_PRINT_ENABLE
                APP_log(APP_LOG_MAX," [%s] %d Device info : ID :0x%x NVM ID: 0x%x NVM Rev: 0x%x Silicon Rev: 0x%x\n",
                    pmic_device[v_id_u32].name, v_id_u32, pmic_device[v_id_u32].st_deviceinfo.deviceID, 
                    pmic_device[v_id_u32].st_deviceinfo.nvmID, pmic_device[v_id_u32].st_deviceinfo.nvmRev, 
                    pmic_device[v_id_u32].st_deviceinfo.nvmRev);
            	#endif
			} else{ /* Do Nothing */}
        }

        /* Init all global variables */
        Pmic_f_InitVar_v();
    }
    else
    {
		#ifdef PMIC_PRINT_ENABLE
        APP_log(APP_LOG_ERR,"pmic i2c open failure: %d\n", v_status_s32);
		#endif
        /* Enter Safestate */
        Pmic_utils_SoftReboot(SAFESTATE_REASON_PMIC_INIT_I2C_FAIL);
    }
#endif
    return v_ret_s32;
}

/*
 * Purpose: Configure PMIC voltage monitoring step 1.
 * Description: Configure PMIC voltage monitoring step 1.
 * Return Type : void
 */
void Pmic_F_Config_step1_v(void)
{
    /* DD-ID:{7B10404C-1108-46ea-B7BC-E73F3D46DF55}*/
    /* Configure voltage monitoring thresholds and other parameter */
    Pmic_F_VoltmonConfigStep_v((uint8_t)D_PMIC_VOLTMON_CFG_STEP_1);

    /*Enable PMIC MCU Error Signal monitoring at Startup */
    Pmic_M_ESM_config();
}


/*
 * Purpose: Refresh watchdog by toggling GPIO line.
 * Description: Refresh watchdog by toggling GPIO line.
 *              This is handled by PMIC Wdg state machine, whose states are
 *                 1. INIT                     ____________________
 *                 2. PULSE_HI                 |                   |
 *                 3. PULSE_LO                 V                   |
 *              State transition -> INIT -> PULSE_HI -> PULSE_LO ---
 * Return Type: void
 */
void Pmic_F_RefreshWdg_v(void)
{
    /* DD-ID:{C525BE69-5F30-4578-A3E7-10A37BC48D17}*/
#ifdef ENABLE_PMIC_EXTWDG
    /* If no request to stop petting Wdg from any application */
    if(V_PmicStopPettingWdg_u8 == (uint8_t)FALSE)
    {
        switch (V_PmicExtWdgSmSt_e)
        {
            case e_PmicExtWdgSt_UNINIT:
            {
                /* Log Error */
                break;
            }
            case e_PmicExtWdgSt_INIT:
            {
                static uint16 u16Count = 0u;
                if(u16Count >= (uint16_t)PMIC_PETTING_WAIT_TIME)
                {                  
                    /* Drive PMIC Wdg GPIO pin to high */
                    GPIOPinWrite_v0((uint32_t)CSL_WKUP_GPIO0_BASE, D_PMIC_WDG_TRIG_PIN1, D_PMIC_GPIO_PIN_LEVEL_HIGH);

                    /* Go to e_PmicExtWdgSt_HI state */
                    V_PmicExtWdgSmSt_e = e_PmicExtWdgSt_HI;

                    gbPMICMonEnable = (uint8_t)TRUE;
                }
                else
                {
                    u16Count++;
                    if(false != Get_ResetPMICFlag())
                    {
                        #ifdef PMIC_PRINT_ENABLE
                        APP_log(APP_LOG_ERR,"Calling ECU Reset, as PMIC recovery counter exceeds the limit...\n");
                        #endif          
                        /* Reset the PMIC as recovery counter exceeds the limit */
                        EEP_Shutdown();
                    } else {/* Do Nothing */}
                }

                break;
            }
            
            case e_PmicExtWdgSt_HI:
            {
                /* Drive PMIC Wdg GPIO pin to low */
                GPIOPinWrite_v0((uint32_t)CSL_WKUP_GPIO0_BASE, D_PMIC_WDG_TRIG_PIN1, D_PMIC_GPIO_PIN_LEVEL_LOW);

                /* Reset timer variable for window1 */
                V_PmicWindow1Tmr_u8 = 0u;

                /* Go to e_PmicExtWdgSt_LO state */
                V_PmicExtWdgSmSt_e = e_PmicExtWdgSt_LO;

                break;
            }

            case e_PmicExtWdgSt_LO:
            {
                /* Increment window 1 timer */
                V_PmicWindow1Tmr_u8 = V_PmicWindow1Tmr_u8 + 1u;

                if (V_PmicWindow1Tmr_u8 >= (uint8_t)D_PMIC_WINDOW_1_TIME)
                {
                    /* Drive PMIC Wdg GPIO pin to high */
                    GPIOPinWrite_v0((uint32_t)CSL_WKUP_GPIO0_BASE, D_PMIC_WDG_TRIG_PIN1, D_PMIC_GPIO_PIN_LEVEL_HIGH);

                    /* Go to e_PmicExtWdgSt_HI state */
                    V_PmicExtWdgSmSt_e = e_PmicExtWdgSt_HI;
                } else {/* Do Nothing */}

                break;
            }

            default:
            {
                /* Do Nothing */	
                break;
            }
        }
    } else{ /* Do Nothing */}

#endif
}

/*
 * Purpose: Accept request to stop petting wdg.
 * Description: Accept request to stop petting wdg.
 * Precondition: PMIC must be initialized
 * Return Type : void
*/
void Pmic_F_StopPettingWdg_v(void)
{
    /* DD-ID:{31EC7785-7192-4cb6-BAB1-5015B15267FC}*/
    /* Set flag to stop petting Wdg */
    V_PmicStopPettingWdg_u8 = (uint8_t)TRUE;
    #if 0
    APP_log(APP_LOG_ERR,"\nStop petting WDG \n");
    #endif
}

/*
 * Purpose: PMIC scheduled task.
 * Description: PMIC scheduled task.
 * Return Type: void
 */
void Pmic_F_MainTask_v(void)
{
    /* DD-ID:{7814869A-D158-4ba5-91DC-F1C1B875BFAE}*/
    static uint8 u8LocalCount = (uint8)e_ZERO;
    
    if((uint8_t)FALSE != gbPMICMonEnable)
    {
        u8LocalCount = u8LocalCount + 1u;
        if((uint8)e_ONE == u8LocalCount)
        {
            /* Pmic voltage monitor task */
            Pmic_F_Voltmon_v();
        }
        else if((uint8)e_TWO == u8LocalCount)
        {
            /* SM12 - Pmic Redundant ReadBack on Logic Output pins task */
            Pmic_F_ReadBackErrMonitor_v();
        }
        else
        {
            u8LocalCount = (uint8)e_ZERO;
            /* SM8 - Thermal Warning and Shutdown */
            Pmic_F_TwarnMon_v();

            /* SM17 - CRC Check */
	        Pmic_F_CRC_Mon_v();
        }
    } else{ /* Do Nothing */}

    /* Check for Soft Reboot */
   (void)Pmic_utils_CheckforSoftResetReq();
}


/* Below functions are commented, but kept for future usages */
#if 0
static int32_t pmic_esmConfig(Pmic_CoreHandle_t *pmicCoreHandle, bool esmType)
{
    /* DD-ID:{B3263505-44CE-4970-9F11-9296F26B63E3}*/
    int32_t pmicStatus      = PMIC_ST_SUCCESS;
    //bool esmType            = PMIC_ESM_MODE_MCU;
    Pmic_EsmCfg_t esmCfg_rd = {0};
    Pmic_EsmCfg_t esmCfg =
    {
        PMIC_ESM_CFG_DELAY1_VALID_SHIFT | PMIC_ESM_CFG_DELAY2_VALID_SHIFT | PMIC_ESM_CFG_HMAX_VALID_SHIFT | PMIC_ESM_CFG_HMIN_VALID_SHIFT | PMIC_ESM_CFG_LMAX_VALID_SHIFT | PMIC_ESM_CFG_LMIN_VALID_SHIFT | PMIC_ESM_CFG_MODE_VALID_SHIFT | PMIC_ESM_CFG_EN_DRV_VALID_SHIFT | PMIC_ESM_CFG_ERR_CNT_THR_VALID_SHIFT,
        4096U,
        2048U,
        30U,
        30U,
        30U,
        30U,
        4U,
        PMIC_ESM_ERR_EN_DRV_CLEAR_ENABLE,
        PMIC_ESM_PWM_MODE
    };

    pmicStatus = Pmic_esmGetConfiguration(pmicCoreHandle,
                                          esmType,
                                          &esmCfg_rd);

    #ifdef PMIC_PRINT_ENABLE
    APP_log(APP_LOG_MAX,"\n %s ESM Cfg - %d %d %d %d %d %d %d %d %d", esmCfg_rd.validParams, esmCfg_rd.esmDelay1_us, esmCfg_rd.esmDelay2_us, esmCfg_rd.esmHmax_us, esmCfg_rd.esmHmin_us, /*  PRQA S 2880*//* URAT Print Lib is not Included in QAC includes */
        esmCfg_rd.esmLmax_us, esmCfg_rd.esmLmin_us, esmCfg_rd.esmErrCntThr, esmCfg_rd.esmEnDrv, esmCfg_rd.esmMode);
    #endif

    if(PMIC_ST_SUCCESS == pmicStatus)
    {
        pmicStatus = Pmic_esmSetConfiguration(pmicCoreHandle, esmType, esmCfg);
    }

    if(PMIC_ST_SUCCESS == pmicStatus)
    {
        pmicStatus = Pmic_esmStart(pmicCoreHandle, esmType, PMIC_ESM_START);
    }

    return pmicStatus;
}

I2C_Handle Board_initI2C_pmic_main()
{
    /* DD-ID:{8A67194F-27A9-4410-B7EA-EB4DC32C3004}*/
    I2C_HwAttrs   i2c_cfg;
    I2C_Handle    i2cHandle;
    I2C_Params    i2cParams;

    I2C_init();

   /* Get the default I2C init configurations */
    I2C_socGetInitCfg(I2C_PMIC_INSTANCE, &i2c_cfg);

#if defined (SOC_J721E) || defined(SOC_J7200)
    /* No I2C instanced connected to eeprom in main domain, use i2c instance in wakeup domain */
    i2c_cfg.baseAddr = CSL_WKUP_I2C0_CFG_BASE;
#if defined (BUILD_MPU)
    i2c_cfg.intNum = CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_WKUP_I2C0_POINTRPEND_0;
#endif
#if defined (BUILD_MCU)
    CSL_ArmR5CPUInfo info;

    CSL_armR5GetCpuID(&info);
    if (info.grpId != (uint32_t)CSL_ARM_R5_CLUSTER_GROUP_ID_0)
    {
        /*
         * Pulsar R5 core is on the Main domain, use the Main Pulsar
         * interrupt router
         */
        i2c_cfg.intNum = 256U; /* value 256 - 511 reserved for IR output */
    }
    else
    {
        /* Pulsar R5 core is on the MCU domain */
        i2c_cfg.intNum = CSLR_MCU_R5FSS0_CORE0_INTR_WKUP_I2C0_POINTRPEND_0;
    }
#endif
#if defined (BUILD_C7X_1)
    i2c_cfg.eventId = CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_WKUP_I2C0_POINTRPEND_0 + 992U, /* eventId, input event # to CLEC */
#endif
#endif

    i2c_cfg.enableIntr = 0;
    /* Set the default I2C init configurations */
    I2C_socSetInitCfg(I2C_PMIC_INSTANCE, &i2c_cfg);

    I2C_Params_init(&i2cParams);

    i2cHandle = I2C_open(I2C_PMIC_INSTANCE, &i2cParams);

    return i2cHandle;

}

/**
 * @brief   Module de-initialization
 */
int32_t pmic_deinit(void)
{
    /* DD-ID:{FE4F8895-0C6C-49cc-8ACA-420509C25BD8}*/
    uint32_t    id;
    int32_t     status = 0;

    for (id = 0; id < PMIC_DEV_NUM; id++)
    {
        if ((status = pmic_device_deinit(&pmic_device[id], id)) < 0)
        {
           // TRACE(ERROR, _x("pmic%u module de-initialization failure: %d"), id, status);
            return status;
        }
    }
    
    //TRACE(INIT, _b("PMIC module de-initialized"));

    return status;
}

/**
 * @brief   Disable PMIC external Watchdog
 */
void disable_pmicExtWdg(void)
{
    /* DD-ID:{D7BEFDCE-1909-4cb7-9F43-0835917F18A7}*/
    /* Disable Watchdog */
    Board_tps65941WdtDisable((I2C_Handle)pmic_device[0].pmicConfigData.pCommHandle,pmic_device[0].pmicConfigData.qaSlaveAddr,BOARD_TPS65941_WDT_ENABLE);
}


/**
 * @brief   PMIC test function to read Power resource registers
 */
void pmic_test_func(void)
{
    /* DD-ID:{3D6C6B89-6FE7-419e-945D-003C66DA914F}*/
   uint32_t    id;


   for (id = 0; id < PMIC_DEV_NUM; id++)
   {
       int i;
       uint8_t sts;
       uint16_t mV;
       Board_STATUS boardStatus;

       for (i = 0; i <= BOARD_TPS65941_LDO4_RESOURCE; i++) {
           boardStatus = Board_tps65941GetVoltage((I2C_Handle)pmic_device[id].pmicConfigData.pCommHandle,
               pmic_device[id].pmicConfigData.slaveAddr,
               i, &mV);

           if (BOARD_SOK != boardStatus) {
               continue;
           }

           boardStatus = Board_tps65941GetRegStatus((I2C_Handle)pmic_device[id].pmicConfigData.pCommHandle,
               pmic_device[id].pmicConfigData.slaveAddr,
               i, &sts);

           if (BOARD_SOK != boardStatus) {
               continue;
           }

       }

       boardStatus = Board_tps65941GetVmonStatus((I2C_Handle)pmic_device[id].pmicConfigData.pCommHandle,
               pmic_device[id].pmicConfigData.slaveAddr,
               &sts);

       if (BOARD_SOK == boardStatus) {
       }

   }

}

/*!
 * \brief   Function to setup the QA I2c interface for PMIC
 *
 * \param   pPmicCoreHandle   [IN]    PMIC Interface Handle
 *
 * \retval  PMIC_ST_SUCCESS in case of success or appropriate error code
 *          For valid values see \ref Pmic_ErrorCodes
 */
static int32_t pmic_dual_i2c_pin_setup(Pmic_CoreHandle_t *pPmicHandle)
{
    /* DD-ID:{58B695C5-2F65-46f6-A000-E3C757F4D33B}*/
    int32_t pmicStatus     = PMIC_ST_SUCCESS;
    Pmic_GpioCfg_t gpioCfg = {0U};


    gpioCfg.validParams      = PMIC_GPIO_CFG_PINFUNC_VALID_SHIFT |
                               PMIC_GPIO_CFG_OD_VALID_SHIFT;
    gpioCfg.pinFunc          = PMIC_TPS6594X_GPIO_PINFUNC_GPIO1_SCL_I2C2_CS_SPI;
    gpioCfg.outputSignalType = PMIC_GPIO_OPEN_DRAIN_OUTPUT;

    pmicStatus = Pmic_gpioSetConfiguration(pPmicHandle,
                                           PMIC_TPS6594X_GPIO1_PIN,
                                           gpioCfg);

    if(PMIC_ST_SUCCESS == pmicStatus)
    {
        gpioCfg.validParams = PMIC_GPIO_CFG_PINFUNC_VALID_SHIFT |
                              PMIC_GPIO_CFG_OD_VALID_SHIFT;
        gpioCfg.pinFunc     = PMIC_TPS6594X_GPIO_PINFUNC_GPIO2_SDA_I2C2_SDO_SPI;
        gpioCfg.outputSignalType = PMIC_GPIO_OPEN_DRAIN_OUTPUT;

        pmicStatus = Pmic_gpioSetConfiguration(pPmicHandle,
                                               PMIC_TPS6594X_GPIO2_PIN,
                                               gpioCfg);
    }

    return pmicStatus;
}
#endif
