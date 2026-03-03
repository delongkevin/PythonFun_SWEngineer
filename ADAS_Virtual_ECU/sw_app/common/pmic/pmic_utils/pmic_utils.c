/**
 * @file pmic_error.c
 * @brief Safe state implementation for PMIC driver
 *
 * @details Safe state implementation for PMIC driver
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
 * @author 
 */
 
/* ===========================================================================
*
*   Include Files
*
* ========================================================================= */
#include "pmic_utils.h"
#include "pmic_cfg.h"
#include <ti/drv/pmic/pmic.h>
#include <ti/drv/pmic/src/pmic_io_priv.h>

#include <ti/board/src/j721s2_hyd/include/board_power.h>
#include <ti/board/src/j721s2_hyd/include/board_utils.h>
#include "app_log_Boot.h"
#include "tps65941_Reg.h"
#include <ti/drv/pmic/include/pmic_irq.h>
#include <ti/drv/pmic/src/pmic_core_priv.h>
#include <ti/drv/pmic/src/pmic_wdg_priv.h>
#include "pmic_reg_lock.h"
#include <ti/osal/osal.h>
#include "fusa_application.h"
#include "OsHooks_RpStruct.h"
#include "Wdg.h"
#include "ErrorManagerSatellite.h"
#include "fusa_application.h"

extern uint16_t Rte_Safety_Guard_SafeStat2_ResetReason_MirrorBlock_copy;
extern sint8_t Cdd_Safety_Wait_for_NVM_Write_Status(void);
extern void NvM_MainFunction(void);
extern void Ea_MainFunction(void);
extern void Eep_30_XXi2c01_MainFunction(void);
extern void SafetyGuard_NVM_Write_ResetReason(void);
extern sint8_t SafetyGuard_Wait_for_NVM_Write_Status(void);
/* ===========================================================================
*
*   Defines
*
* ========================================================================= */


/* ===========================================================================
*
* Typedefs
*
* ========================================================================= */
#define CHECK_VALUE(x,y)                ((x)==(y)?0x0:0x1)
#define PMIC_NVM_STORE_CNT			    (1000u)
#define NVM_WR_TIMEOUT_CNT			    (25u)
#define PMIC_WDG_RESET_VAL              (0xFF)
#define PMIC_SET_INT_FSM_NSLEEP         (3u)
#define PMIC_CLR_INT_STARTUP            (2u)
#define PMIC_CLR_INT_MISC               (1u)
#define WDG_RST_SEID_VAL_1              (1u)
#define WDG_RST_SEID_VAL_2              (2u)
#define WDG_RST_SEID_VAL_3              (3u)
#define WDG_RST_SEID_VAL_4              (4u)
#define WDG_RST_SEID_VAL_5              (5u)
#define WDG_RST_SEID_VAL_6              (6u)
#define WDG_RST_SEID_VAL_7              (7u)
#define WDG_RST_SEID_VAL_8              (8u)
/* ===========================================================================
*
* Private functions
*
* ========================================================================= */
static void Set_ResetPMICFlag(bool bFlag);
static uint8_t Pmic_utils_CheckforWdgReset(uint16_t u16ErrMngrVal, uint8_t u8SoftRebootReason);

/* ===========================================================================
*
*   Private variables
*
* ========================================================================= */
static bool pmic_req_soft_reboot = false;
static uint8_t pmic_req_soft_reboot_reason = 0U;

/* ===========================================================================
*
*   Global variables
*
* ========================================================================= */
/* PMIC error variable */
static bool gu8ResetPMICFlag;
/**/

/* ========================================================================== */
/*                          Function Implementation                           */
/* ========================================================================== */

/*
 * Purpose: Util function for Pmic write.
 * Description: Util function for Pmic write
 * Return Type: int32_t
 */
int32_t Pmic_utils_Write(Pmic_CoreHandle_t *pPmicCoreHandle, uint16_t regaddr, uint8_t regData)
{
    /* DD-ID:{67287C3A-124A-4caf-8EF4-4D5C0B0285A7}*/
    int32_t pmicStatus;
    uint8_t slaveAddr;

    if( NULL != pPmicCoreHandle)
    {
        slaveAddr = pmic_device[pPmicCoreHandle->deviceNum].pmicConfigData.slaveAddr;

        if((true == pPmicCoreHandle->crcEnable) || (true == pmic_device[pPmicCoreHandle->deviceNum].pmicInitCompleted))
        {
            pmicStatus = Pmic_commIntf_sendByte(pPmicCoreHandle, regaddr, regData);
        }
        else
        {
            if(0U != (regaddr & PMIC_WDG_PAGEADDR))
            {
                regaddr = (regaddr & PMIC_WDG_PAGEADDR_MASK);
                slaveAddr = pmic_device[pPmicCoreHandle->deviceNum].pmicConfigData.qaSlaveAddr;
            } else {/* Do Nothing */}
            pmicStatus = PMIC_Write(slaveAddr, (uint8_t)regaddr, regData);
        }
    }
    else
    {
        pmicStatus = PMIC_ST_ERR_INV_HANDLE;
    }

    return pmicStatus;
}

/*
 * Purpose: Util function for Pmic write.
 * Description: Util function for Pmic write
 * Return Type: int32_t
 */
int32_t Pmic_utils_read(Pmic_CoreHandle_t *pPmicCoreHandle, uint16_t regaddr, uint8_t *regData)
{
    /* DD-ID:{74E4016A-1475-4924-8769-9D533B2A889F}*/
    int32_t pmicStatus;
    uint8_t slaveAddr;

    if( NULL != pPmicCoreHandle )
    {
        slaveAddr = pmic_device[pPmicCoreHandle->deviceNum].pmicConfigData.slaveAddr;

        if((true == pPmicCoreHandle->crcEnable) || (true == pmic_device[pPmicCoreHandle->deviceNum].pmicInitCompleted))
        {
            pmicStatus = Pmic_commIntf_recvByte(pPmicCoreHandle, regaddr, regData);
        }
        else
        {
            if(0U != (regaddr & PMIC_WDG_PAGEADDR))
            {
                regaddr = (regaddr & PMIC_WDG_PAGEADDR_MASK);
                slaveAddr = pmic_device[pPmicCoreHandle->deviceNum].pmicConfigData.qaSlaveAddr;
            }
            else if(0U != (regaddr & PMIC_SERIAL_IF_CONFIG_PAGEADDR))
            {
                regaddr = (regaddr & PMIC_SERIAL_IF_CONFIG_PAGEADDR_MASK);
                slaveAddr = pmic_device[pPmicCoreHandle->deviceNum].pmicConfigData.nvmSlaveAddr;
            }
            else
            {
                /* Do Nothing */
            }
            pmicStatus = PMIC_Read(slaveAddr, (uint8_t)regaddr, regData);
        }
    }
    else
    {
        pmicStatus = PMIC_ST_ERR_INV_HANDLE;
    }
    return pmicStatus;
}

/**
 * \brief   Clear the TPS65941 Recovery Counter
 *
 * This function is used to set/clear the watchdog powerhold function in the
 * TPS65941.
 *
 * \param   handle          [IN]    Low level driver
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   wdtDisable      [IN]    Enable/Disable the watchdog
 *                                  Valid values:
 *                                  0
 *                                  1
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
int32_t Pmic_utils_tps65941RecovCounterClear(Pmic_CoreHandle_t *pPmicCoreHandle)
{
    /* DD-ID:{C803405B-CC83-42df-B8A0-1D94033A001F}*/
    int32_t pmicStatus = PMIC_ST_SUCCESS;
    uint8_t regData = (uint8_t)0u;

    if(pPmicCoreHandle == NULL)
    {
        pmicStatus = PMIC_ST_ERR_INV_HANDLE;
    } else {/* Do Nothing */}

    if(pmicStatus == PMIC_ST_SUCCESS)
    {
        /* Set/clear the Recovery Count*/
        pmicStatus = Pmic_utils_read(pPmicCoreHandle, BOARD_TPS65941_RECOV_CNT, &regData);
    } else {/* Do Nothing */}

    regData &= ~(BOARD_TPS65941_RECOV_CNT_BIT_MASK);
    regData |= (1U << BOARD_TPS65941_RECOV_CNT_SHIFT);

    if(pmicStatus == PMIC_ST_SUCCESS)
    {
        pmicStatus = Pmic_utils_Write(pPmicCoreHandle, BOARD_TPS65941_RECOV_CNT, regData);
    } else {/* Do Nothing */}

    return pmicStatus;
}

#if 0 /* Unused function */
/**
 * \brief   Enable/Disable the TPS65941 Watchdog function.
 *
 * This function is used to enable/disable the watchdog function in the
 * TPS65941.
 *
 * \param   handle          [IN]    Low level driver
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   wdtDisable      [IN]    Enable/Disable the watchdog
 *                                  Valid values:
 *                                  BOARD_TPS65941_WDT_DISABLE
 *                                  BOARD_TPS65941_WDT_ENABLE
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
int32_t Pmic_utils_tps65941WdtDisable(Pmic_CoreHandle_t *pPmicCoreHandle,
                                      uint8_t wdtDisable)
{
    /* DD-ID:{4C804DF4-43D3-4cc4-814A-E32EBC259B76}*/
    int32_t pmicStatus = PMIC_ST_SUCCESS;
    uint8_t regData = 0;

    if(pPmicCoreHandle == NULL)
    {
        pmicStatus = PMIC_ST_ERR_INV_HANDLE;
    }

    if((pmicStatus == PMIC_ST_SUCCESS) &&
        (wdtDisable > BOARD_TPS65941_WDT_ENABLE))
    {
        pmicStatus = PMIC_ST_ERR_INV_PARAM;
    }

    if(pmicStatus == PMIC_ST_SUCCESS)
    {
        /* Enable/Disable the WDT */
        pmicStatus = Pmic_utils_read(pPmicCoreHandle, D_PMIC_TPS65941_WD_THR_CFG, &regData);
    }

    regData &= ~(BOARD_TPS65941_WDT_EN_BIT_MASK);
    regData |= (wdtDisable << BOARD_TPS65941_WDT_EN_SHIFT);

    if(pmicStatus == PMIC_ST_SUCCESS)
    {
        pmicStatus = Pmic_utils_Write(pPmicCoreHandle, D_PMIC_TPS65941_WD_THR_CFG, regData);
    }

    return pmicStatus;
}

/**
 * \brief   Set/Clear the TPS65941 WDG PWR HOLD register.
 *
 * This function is used to set/clear the watchdog powerhold function in the
 * TPS65941.
 *
 * \param   handle          [IN]    Low level driver
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   wdtDisable      [IN]    Enable/Disable the watchdog
 *                                  Valid values:
 *                                  0
 *                                  1
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
int32_t Pmic_utils_tps65941WdPwrhold(Pmic_CoreHandle_t *pPmicCoreHandle,
                                      uint8_t value)
{
    /* DD-ID:{C628CC17-8894-42c2-B5B7-321E88B87A8E}*/
    int32_t pmicStatus = PMIC_ST_SUCCESS;
    uint8_t regData = 0;

    if(pPmicCoreHandle == NULL)
    {
        pmicStatus = PMIC_ST_ERR_INV_HANDLE;
    }

    if(pmicStatus == PMIC_ST_SUCCESS)
    {
        /* Set/clear the WDT Power hold*/
        pmicStatus = Pmic_utils_read(pPmicCoreHandle, D_PMIC_TPS65941_WD_MODE_REG, &regData);
    }

        regData &= ~(BOARD_TPS65941_WDT_PWRHOLD_BIT_MASK);
        regData |= (value << BOARD_TPS65941_WDT_PWRHOLD_SHIFT);

    if(pmicStatus == PMIC_ST_SUCCESS)
    {
        pmicStatus = Pmic_utils_Write(pPmicCoreHandle, D_PMIC_TPS65941_WD_MODE_REG, regData);
    }

    return pmicStatus;
}

/**
 * \brief  TPS65941 Enter or exit to Long Window
 *
 * This function is used to return to Long Window or exit window
 * In  TPS65941 in either Long Window or exit Window.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   val             [IN]    Valid values:
 *                                  1 - Enter to Long Window
 *                                  0 - Exit from Long Window


 * \return  BOARD_SOK in case of success or appropriate error code.
 */
int32_t Pmic_utils_tps65941RetToLongWinDisable(void)
{
    /* DD-ID:{B82CBB65-ECB3-44e6-A6EC-C501E65AB45D}*/
    int32_t pmicStatus = PMIC_ST_SUCCESS;
    uint8_t regData = 0U;
    uint8_t retry = 0U;

    pmicStatus = Pmic_utils_Write(&pmic_device[PMIC_DEV_0].pmicCoreHandle, D_PMIC_TPS65941_WD_MODE_REG, 0x00 );

    if(pmicStatus == PMIC_ST_SUCCESS)
    {
       //pmicStatus = PMIC_Read(LEO_PMICA_WDG_SLAVE_ADDR, BOARD_TPS65941_WDT_MODE_REG, &regData);
        pmicStatus = Pmic_utils_read(&pmic_device[PMIC_DEV_0].pmicCoreHandle, D_PMIC_TPS65941_WD_MODE_REG, &regData);
    }

    while((regData != 0U) && (retry < 3U))
    {
        //pmicStatus = PMIC_Write(LEO_PMICA_WDG_SLAVE_ADDR, BOARD_TPS65941_WDT_MODE_REG, 0x00);
          pmicStatus = Pmic_utils_Write(&pmic_device[PMIC_DEV_0].pmicCoreHandle, D_PMIC_TPS65941_WD_MODE_REG, 0x00 );
        if(pmicStatus == PMIC_ST_SUCCESS)
        {
            //pmicStatus = PMIC_Read(LEO_PMICA_WDG_SLAVE_ADDR, BOARD_TPS65941_WDT_MODE_REG, &regData);
            pmicStatus = Pmic_utils_read(&pmic_device[PMIC_DEV_0].pmicCoreHandle, D_PMIC_TPS65941_WD_MODE_REG, &regData);
        }
        retry++;
    }
    return pmicStatus;

}
#endif

/**
 * \brief   TPS65941 watchdog Long Windows status function.
 *
 * This function is used to get the error status from the TPS65941 watchdog.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   wdtErrStat      [OUT]   TPS65941 Watchdog Long window status
 *                                  Valid Values:
 *                                  BOARD_TPS65941_WDT_ERR_LATCHED
 *                                  BOARD_TPS65941_WDT_NO_ERR
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
int32_t Pmic_utils_tps65941GetWdtFirstOkStat(Pmic_CoreHandle_t *pPmicCoreHandle,
                                      uint8_t *wdtFirstOK)
{
    /* DD-ID:{F86386EE-4043-4399-B3FD-4596B9CB3406}*/
    int32_t pmicStatus = PMIC_ST_SUCCESS;
    uint8_t regData = 0;

    if(pPmicCoreHandle == NULL)
    {
        pmicStatus = PMIC_ST_ERR_INV_HANDLE;
    } else {/* Do Nothing */}

    *wdtFirstOK = BOARD_TPS65941_WDT_FIRST_OK; //Assuming it will be good in most cases

    /* Reading the WDT Error status */
    if(pmicStatus == PMIC_ST_SUCCESS)
    {
        pmicStatus = Pmic_utils_read(pPmicCoreHandle, D_PMIC_TPS65941_WD_FAIL_CNT_REG, &regData);
    } else {/* Do Nothing */}

    *wdtFirstOK = ((regData & BOARD_TPS65941_WDT_FIRST_OK_BIT_MASK) >> BOARD_TPS65941_WDT_FIRST_OK_SHIFT);

    return pmicStatus;
}

/*
 * \brief  Function to set watchdog Threshold values
 */
static int32_t Pmic_utils_WdgSetThresholdReg(Pmic_WdgCfg_t wdg_Cfg)
{
    /* DD-ID:{B9BE8A3B-DE57-4b8f-B428-F059D68F5E5D}*/
    int32_t status;
    uint8_t regVal = 0U;
    uint8_t rstEnableVal = 0U;
    bool isParamValid;

    status = Pmic_utils_read(&pmic_device[PMIC_DEV_0].pmicCoreHandle, D_PMIC_TPS65941_WD_THR_CFG, &regVal);

    /* Set wdg fail threshold value */
    if((true) == pmic_validParamCheck(wdg_Cfg.validParams,
                              PMIC_CFG_WDG_FAILTHRESHOLD_VALID))
    {
        if(wdg_Cfg.failThreshold > (uint8_t)PMIC_WDG_FAIL_THRESHOLD_COUNT_7)
        {
            status = PMIC_ST_ERR_INV_PARAM;
        } else {/* Do Nothing */}

        if(PMIC_ST_SUCCESS == status)
        {
            /* Set wdg fail threshold value */
            Pmic_setBitField(&regVal,
                             PMIC_WD_THR_CFG_WD_FAIL_TH_SHIFT,
                             PMIC_WD_THR_CFG_WD_FAIL_TH_MASK,
                             wdg_Cfg.failThreshold);
        } else {/* Do Nothing */}
    } else {/* Do Nothing */}

    /* Set wdg reset threshold value */
    isParamValid = pmic_validParamCheck(wdg_Cfg.validParams, PMIC_CFG_WDG_RSTTHRESHOLD_VALID);    
    if((PMIC_ST_SUCCESS == status) && (true == isParamValid))
    {
        if(wdg_Cfg.rstThreshold > (uint8_t)PMIC_WDG_RESET_THRESHOLD_COUNT_7)
        {
            status = PMIC_ST_ERR_INV_PARAM;
        } else {/* Do Nothing */}

        if(PMIC_ST_SUCCESS == status)
        {
            Pmic_setBitField(&regVal,
                             PMIC_WD_THR_CFG_WD_RST_TH_SHIFT,
                             PMIC_WD_THR_CFG_WD_RST_TH_MASK,
                             wdg_Cfg.rstThreshold);
        } else {/* Do Nothing */}
    } else {/* Do Nothing */}

    /* Set wdg warm reset enable value */
    isParamValid = pmic_validParamCheck(wdg_Cfg.validParams, PMIC_CFG_WDG_RSTENABLE_VALID);    
    if((PMIC_ST_SUCCESS == status) && (true == isParamValid))
    {
        if((true) == wdg_Cfg.rstEnable)
        {
            rstEnableVal = 1U;
        } else {/* Do Nothing */}

        Pmic_setBitField(&regVal,
                         PMIC_WD_THR_CFG_WD_RST_EN_SHIFT,
                         PMIC_WD_THR_CFG_WD_RST_EN_MASK,
                         rstEnableVal);
    } else {/* Do Nothing */}

    /* Set wdg enable value */
    isParamValid = pmic_validParamCheck(wdg_Cfg.validParams, PMIC_CFG_WDG_ENABLE_VALID);    
    if((PMIC_ST_SUCCESS == status) && (true == isParamValid))
    {

        Pmic_setBitField(&regVal,
                         PMIC_WD_THR_CFG_WD_EN_SHIFT,
                         PMIC_WD_THR_CFG_WD_EN_MASK,
                         wdg_Cfg.wdgEnable);
    } else {/* Do Nothing */}

    if(PMIC_ST_SUCCESS == status)
    {
        //status = PMIC_Write(LEO_PMICA_WDG_SLAVE_ADDR, BOARD_TPS65941_WDT_THR_CFG, regVal);
        status = Pmic_utils_Write(&pmic_device[PMIC_DEV_0].pmicCoreHandle, D_PMIC_TPS65941_WD_THR_CFG, regVal);
    } else {/* Do Nothing */}

    return status;
}

/*
 * \brief  Function to set watchdog control parameters
 */
static int32_t Pmic_utils_WdgSetModeReg(Pmic_WdgCfg_t wdg_Cfg)
{
    /* DD-ID:{71C523DA-84E9-49d3-AAD8-C9C83C34E815}*/
    int32_t status;
    uint8_t regVal = 0U;
    uint8_t wdgMode = 0U;
    uint8_t pwrHold = 0U;
    uint8_t retLongWin = 0U;
    bool isParamValid;

    //status = PMIC_Read(LEO_PMICA_WDG_SLAVE_ADDR, BOARD_TPS65941_WDT_MODE_REG, &regVal);
    status = Pmic_utils_read(&pmic_device[PMIC_DEV_0].pmicCoreHandle, D_PMIC_TPS65941_WD_MODE_REG, &regVal);

    /* Set wdg mode */
    isParamValid = pmic_validParamCheck(wdg_Cfg.validParams, PMIC_CFG_WDG_WDGMODE_VALID);     
    if((PMIC_ST_SUCCESS == status) && (true == isParamValid))
    {
        if((true) == wdg_Cfg.wdgMode)
        {
            wdgMode = 1U;
        } else {/* Do Nothing */}

        Pmic_setBitField(&regVal,
                         PMIC_WD_MODE_REG_WD_MODE_SELECT_SHIFT,
                         PMIC_WD_MODE_REG_WD_MODE_SELECT_MASK,
                         wdgMode);
    } else {/* Do Nothing */}

    /* Set wdg power hold value */
    isParamValid = pmic_validParamCheck(wdg_Cfg.validParams, PMIC_CFG_WDG_PWRHOLD_VALID);     
    if((PMIC_ST_SUCCESS == status) && (true == isParamValid))
    {
        if((true) == wdg_Cfg.pwrHold)
        {
            pwrHold = 1U;
        } else {/* Do Nothing */}

        Pmic_setBitField(&regVal,
                         PMIC_WD_MODE_REG_WD_PWRHOLD_SHIFT,
                         PMIC_WD_MODE_REG_WD_PWRHOLD_MASK,
                         pwrHold);
    } else {/* Do Nothing */}

    /* Set wdg return to long window bit */
    isParamValid = pmic_validParamCheck(wdg_Cfg.validParams, PMIC_CFG_WDG_RETLONGWIN_VALID);     
    if((PMIC_ST_SUCCESS == status) && (true == isParamValid))
    {

        if((true) == wdg_Cfg.retLongWin)
        {
            retLongWin = 1U;
        } else {/* Do Nothing */}

        Pmic_setBitField(&regVal,
                         PMIC_WD_MODE_REG_WD_RETURN_LONGWIN_SHIFT,
                         PMIC_WD_MODE_REG_WD_RETURN_LONGWIN_MASK,
                         retLongWin);
    } else {/* Do Nothing */}

    //status = PMIC_Write(LEO_PMICA_WDG_SLAVE_ADDR, BOARD_TPS65941_WDT_MODE_REG, regVal);
    status = Pmic_utils_Write(&pmic_device[PMIC_DEV_0].pmicCoreHandle, D_PMIC_TPS65941_WD_MODE_REG, regVal);

    return status;
}
/*!
 * \brief   This function is used to set window1 and window 2 time intervals
 */
static int32_t Pmic_utils_WdgSetWindow1Window2TimeIntervals(Pmic_WdgCfg_t  wdg_Cfg)
{
    /* DD-ID:{C260D78E-8B8C-4439-8340-FFA76BFAAB44}*/
    int32_t status = PMIC_ST_SUCCESS;
    uint8_t win1Duration;
    uint8_t win2Duration;
    bool isParamValid;

    /* WIN1 Configuration */
    isParamValid = pmic_validParamCheck(wdg_Cfg.validParams, PMIC_CFG_WDG_WIN1DURATION_VALID);     
    if((PMIG_WD_WIN1_2_MICROSEC_DEFAULT != wdg_Cfg.win1Duration_us) && (true == isParamValid))
    {
        win1Duration = ((uint8_t)(wdg_Cfg.win1Duration_us /
                             PMIG_WD_WIN1_2_MICROSEC_DIV) - 1U);
        win1Duration &= PMIC_WD_WIN1_CFG_WD_WIN1_MASK;

        //status = PMIC_Write(LEO_PMICA_WDG_SLAVE_ADDR, BOARD_TPS65941_WDT_WIN1_CFG, win1Duration);
        status = Pmic_utils_Write(&pmic_device[PMIC_DEV_0].pmicCoreHandle, D_PMIC_TPS65941_WD_WIN1_CFG, win1Duration);
    } else {/* Do Nothing */}

    /* WIN2 Configuration */
    isParamValid = pmic_validParamCheck(wdg_Cfg.validParams, PMIC_CFG_WDG_WIN2DURATION_VALID);    
    if((PMIC_ST_SUCCESS == status) &&
         (PMIG_WD_WIN1_2_MICROSEC_DEFAULT != wdg_Cfg.win2Duration_us) && (true == isParamValid))
    {
        win2Duration = ((uint8_t)(wdg_Cfg.win2Duration_us /
                             PMIG_WD_WIN1_2_MICROSEC_DIV) - 1U);
        win2Duration &= PMIC_WD_WIN2_CFG_WD_WIN2_MASK;

        //status = PMIC_Write(LEO_PMICA_WDG_SLAVE_ADDR, BOARD_TPS65941_WDT_WIN2_CFG, win2Duration);
        status = Pmic_utils_Write(&pmic_device[PMIC_DEV_0].pmicCoreHandle, D_PMIC_TPS65941_WD_WIN2_CFG, win2Duration);
    } else {/* Do Nothing */}

    return status;
}
/*!
 * \brief   This function is used to set window1 and window 2 time intervals
 */
static int32_t Pmic_WdgSetWindowsTimeIntervals(Pmic_WdgCfg_t  wdg_Cfg)
{
    /* DD-ID:{B220ACCE-6B22-46b9-8475-953AF6096117}*/
    int32_t status = PMIC_ST_SUCCESS;
    uint8_t WdtLongWin = 0;

     /* Set wdg long window time interval */
    if((true) == pmic_validParamCheck(wdg_Cfg.validParams,
                              PMIC_CFG_WDG_LONGWINDURATION_VALID))
    {
        if((PMIG_WD_LONGWIN_80_MILLISEC != wdg_Cfg.longWinDuration_ms) &&
               ((PMIG_WD_LONGWIN_MILLISEC_MIN_PG_2_0 >
                                             wdg_Cfg.longWinDuration_ms) ||
                (PMIG_WD_LONGWIN_MILLISEC_MAX_PG_2_0 <
                                             wdg_Cfg.longWinDuration_ms)))
        {
            status = PMIC_ST_ERR_INV_WDG_WINDOW;
        } else {/* Do Nothing */}

        if(PMIC_ST_SUCCESS == status)
        {
            WdtLongWin = Pmic_WdgCovertLongWinTimeIntervaltoRegBits(wdg_Cfg);
        } else {/* Do Nothing */}
        //status = PMIC_Write(LEO_PMICA_WDG_SLAVE_ADDR, BOARD_TPS65941_WDT_LONGWIN_CFG, WdtLongWin);
        status = Pmic_utils_Write(&pmic_device[PMIC_DEV_0].pmicCoreHandle, D_PMIC_TPS65941_WD_LONGWIN_CFG, WdtLongWin);
    } else {/* Do Nothing */}

    if(PMIC_ST_SUCCESS == status)
    {
        /* Set wdg window1 and window2 time interval */
        status = Pmic_utils_WdgSetWindow1Window2TimeIntervals(wdg_Cfg);
    } else {/* Do Nothing */}

    return status;
}
/*!
 * \brief   This function is used to set watchdog config
 */
int32_t Pmic_utils_WdgSetConfig(Pmic_WdgCfg_t  wdg_Cfg)
{
    /* DD-ID:{C9A972D6-F02F-41da-BDC1-3524011FC8A8}*/
    int32_t status;

    status = Pmic_WdgSetWindowsTimeIntervals(wdg_Cfg);

    if(PMIC_ST_SUCCESS == status)
    {
    	status = Pmic_utils_WdgSetModeReg(wdg_Cfg);
    } else {/* Do Nothing */}

    if(PMIC_ST_SUCCESS == status)
    {
    	status = Pmic_utils_WdgSetThresholdReg(wdg_Cfg);
    } else {/* Do Nothing */}

    return status;

}
/*!
 * \brief   API to get PMIC watchdog configurations.
 *
 * Requirement: REQ_TAG(PDK-5839), REQ_TAG(PDK-5854), REQ_TAG(PDK-9115),
 *              REQ_TAG(PDK-9116)
 * Design: did_pmic_wdg_cfg_readback
 * Architecture: aid_pmic_wdg_cfg
 *
 *          This function is used to get configuration of the watchdog
 *          from the PMIC for trigger mode or Q&A(question and answer) mode,
 *          when corresponding validParam bit fields are set in
 *          Pmic_WdgCfg_t structure.
 *          User has to call Pmic_wdgEnable() before get the configuration.
 *
 * \param   pPmicCoreHandle [IN]       PMIC Interface Handle
 * \param   pWdgCfg         [IN/OUT]   Watchdog configuration pointer
 *
 * \return  PMIC_ST_SUCCESS in case of success or appropriate error code
 *          For valid values \ref Pmic_ErrorCodes
 */
int32_t Pmic_utils_tps65941CheckWdtConfig(Pmic_CoreHandle_t *pPmicCoreHandle,
                                     Pmic_WdgCfg_t  wdg_Cfg)
{
    /* DD-ID:{A594F7B4-C96E-4c40-897B-1EEB7CDA853A}*/
    int32_t pmicStatus;
    int32_t wdgCfgData = D_PMIC_WDG_CFG_SUCCESS;
    Pmic_WdgCfg_t wdgCfg_rd = {(uint32_t)PMIC_WDG_CFG_SETPARAMS_TRIGGER_FORALL, 0u ,0u, 0u, 0u, 0u, false, false, false, false, 0u, 0u, 0u, 0u};

    if(pPmicCoreHandle == NULL)
    {
        pmicStatus = PMIC_ST_ERR_INV_HANDLE;
    } else {/* Do Nothing */}

    pmicStatus = Pmic_wdgGetCfg(pPmicCoreHandle, &wdgCfg_rd);

    if(pmicStatus == PMIC_ST_SUCCESS)
    {
        wdgCfgData |= (CHECK_VALUE(wdg_Cfg.longWinDuration_ms, wdgCfg_rd.longWinDuration_ms)) << D_PMIC_WDG_LONGWIN_SHIFT;
        wdgCfgData |= (CHECK_VALUE(wdg_Cfg.win1Duration_us, wdgCfg_rd.win1Duration_us)) << D_PMIC_WDG_WIN1_SHIFT;
        wdgCfgData |= (CHECK_VALUE(wdg_Cfg.win2Duration_us, wdgCfg_rd.win2Duration_us)) << D_PMIC_WDG_WIN2_SHIFT;
        wdgCfgData |= (CHECK_VALUE(wdg_Cfg.failThreshold, wdgCfg_rd.failThreshold)) << D_PMIC_WDG_FAIL_THR_SHIFT;
        wdgCfgData |= (CHECK_VALUE(wdg_Cfg.rstThreshold, wdgCfg_rd.rstThreshold)) << D_PMIC_WDG_RST_THR_SHIFT;
        wdgCfgData |= (CHECK_VALUE(wdg_Cfg.wdgMode, wdgCfg_rd.wdgMode)) << D_PMIC_WDG_WDT_MODE_SHIFT;
        //wdgCfgData |= CHECK_VALUE(wdg_Cfg.pwrHold, wdgCfg_rd.pwrHold) << D_PMIC_WDG_PWRHOLD_SHIFT;
        wdgCfgData |= (CHECK_VALUE(wdg_Cfg.rstEnable, wdgCfg_rd.rstEnable)) << D_PMIC_WDG_RST_ENABLE_SHIFT;
        wdgCfgData |= (CHECK_VALUE(wdg_Cfg.retLongWin, wdgCfg_rd.retLongWin)) << D_PMIC_WDG_RETLONWIN_SHIFT;
        wdgCfgData |= (CHECK_VALUE(wdg_Cfg.wdgEnable, wdgCfg_rd.wdgEnable)) << D_PMIC_WDG_ENABLE_SHIFT;
    }
    else
    {
        wdgCfgData = PMIC_WDG_RESET_VAL;
    }

    #ifdef PMIC_PRINT_ENABLE
    APP_log(APP_LOG_MAX,"WDG Configuration 0x%x \n", wdgCfgData); /*  PRQA S 2880*//* URAT Print Lib is not Included in QAC includes */
    APP_log(APP_LOG_MAX,"WDG Configuration data LONGWIN:%d WIN1:%d WIN2:%d FAILTHR:%d RSTTHR:%d WDGMODE:%d PWRHOLD:%d RSTEN:%d RETLONGWIN:%d WDGEN:%d\n", /*  PRQA S 2880*//* URAT Print Lib is not Included in QAC includes */
        wdgCfg_rd.longWinDuration_ms, wdgCfg_rd.win1Duration_us, wdgCfg_rd.win2Duration_us,
        wdgCfg_rd.failThreshold, wdgCfg_rd.rstThreshold, wdgCfg_rd.wdgMode, wdgCfg_rd.pwrHold, wdgCfg_rd.rstEnable, wdgCfg_rd.retLongWin, wdgCfg_rd.wdgEnable);
    #endif

    return wdgCfgData;
}

#ifdef PMIC_DEBUG_RAW_INTERRUPTS
/*!
 * \brief   This function is used to read interrupts
 */
static int32_t Pmic_utils_ReadRawInterrupts(Pmic_CoreHandle_t *pPmicCoreHandle)
{
    /* DD-ID:{0DA8043E-0C23-4119-8646-487F707E65F8}*/
    int32_t pmicStatus = PMIC_ST_SUCCESS;
    uint8_t intStat[20U] = {0};

    for(uint8_t i =0U; i <= 20U; i++)
    {
        pmicStatus = Pmic_utils_read(pPmicCoreHandle, (D_PMIC_TPS65941_INT_TOP+i), &intStat[i]);
        //APP_log(APP_LOG_MAX,"INT[%d] 0x%0x \n", i, intStat[i])
    }

    return pmicStatus;
}
#endif

/*!
 * \brief   This function is used to read interrupts
 */
int32_t Pmic_utils_ReadInterrupts(Pmic_CoreHandle_t *pPmicCoreHandle, bool irqClear, Pmic_IrqStatus_t *errStat)
{
    /* DD-ID:{63C0D465-DFE7-4de4-BC48-38144AA643AB}*/
    int32_t pmicStatus = PMIC_ST_SUCCESS;
    //Pmic_IrqStatus_t errStat = {0U};

    if(pPmicCoreHandle == NULL)
    {
        pmicStatus = PMIC_ST_ERR_INV_HANDLE;
    } else {/* Do Nothing */}

    if(pmicStatus == PMIC_ST_SUCCESS)
    {
        #ifdef PMIC_DEBUG_RAW_INTERRUPTS
        pmicStatus = Pmic_utils_ReadRawInterrupts(pPmicCoreHandle);
        #endif
        /* Get Interrupt bits*/
        pmicStatus = Pmic_irqGetErrStatus(pPmicCoreHandle, errStat, (const bool)irqClear);
        //APP_log(APP_LOG_MAX,"[%s] INT %08x %08x %08x %08x \n", pmic_device[pPmicCoreHandle->deviceNum].name, errStat->intStatus[0], errStat->intStatus[1], errStat->intStatus[2], errStat->intStatus[3]);
    } else {/* Do Nothing */}

    return pmicStatus;
}
/*!
 * \brief   This function is used to clear interrupts
 */
int32_t Pmic_utils_ClearInterrupts(Pmic_CoreHandle_t *pPmicCoreHandle, bool irqClear)
{
    /* DD-ID:{1C6DC1F8-BCCE-4fe8-91E9-DDDCF735800F}*/
    int32_t pmicStatus;

    pmicStatus = Pmic_utils_Write(pPmicCoreHandle, BOARD_TPS65941_FSM_NSLEEP_REGISTERS, PMIC_SET_INT_FSM_NSLEEP); // set to active before clearing interrupts

    if(true == irqClear)
    {
        pmicStatus = Pmic_irqClrErrStatus(pPmicCoreHandle, PMIC_IRQ_ALL);
    }
    else
    {
        if(pmicStatus == PMIC_ST_SUCCESS)
        {
            pmicStatus = Pmic_utils_Write(pPmicCoreHandle, BOARD_TPS65941_INT_STARTUP, PMIC_CLR_INT_STARTUP); //Clear ENABLE_INT
            pmicStatus = Pmic_utils_Write(pPmicCoreHandle, BOARD_TPS65941_INT_MISC, PMIC_CLR_INT_MISC); //Clear BIST_PASS_INT
        } else {/* Do Nothing */}
    }

    return pmicStatus;
}
/*!
 * \brief   This function is used to trigger soft reboot
 */
void Pmic_utils_SoftReboot(uint8_t SafeStateReason)
{
    /* DD-ID:{BA11B16D-122A-4a26-A64B-F3E4429735C2}*/
    static bool pmic_reqsoft_reboot_set = false;
    /* Trigger soft reboot only once */
    if(true != pmic_reqsoft_reboot_set)
    {
        pmic_reqsoft_reboot_set = true;
        pmic_req_soft_reboot = true;
        pmic_req_soft_reboot_reason = SafeStateReason;
    } else {/* Do Nothing */}
}

#if 0 /* Unused function */
/*!
 * \brief   This function is used to get IRQ status
 */
uint32_t Pmic_utils_GetIrqStatus(uint8_t device, uint8_t pos)
{
    /* DD-ID:{38EFFB31-2164-451a-ABBE-673B237B0D20}*/
    return pmic_device[device].errStat.intStatus[pos];
}
/*!
 * \brief   This function is used to get recovery counter
 */
uint8_t Pmic_utils_GetRecoveryCounter(uint8_t device)
{
    /* DD-ID:{2ABFED9A-23B4-47c5-BA95-2849CD4F6EF0}*/
    return pmic_device[device].CurRecoveryCounter;
}
#endif

static void Set_ResetPMICFlag(bool bFlag)
{
    /* DD-ID:{C70D035E-C8F9-41fa-AF47-E5516046AF9B}*/
    gu8ResetPMICFlag = bFlag;
}
bool Get_ResetPMICFlag(void)
{
    /* DD-ID:{BD4CAD3D-9757-4bf9-83D1-08B5F2DC2670}*/
    return gu8ResetPMICFlag;
}
/*!
 * \brief   This function is used to Check recovery counter
 */
int32_t Pmic_utils_CheckRecoveryCounter(void)
{
    /* DD-ID:{443A14E6-3D27-4b32-9CB7-E06B7AFB710A}*/
    int32_t pmicStatus;
    uint8_t regData;
    uint8_t v_id_u8;

    for (v_id_u8 = 0U; v_id_u8 < (uint8_t)PMIC_DEV_NUM; v_id_u8++)
    {
        regData = 0U;
        pmicStatus = Pmic_utils_read(&pmic_device[v_id_u8].pmicCoreHandle, D_PMIC_TPS65941_RECOV_CNT_REG_1, &regData);
        //APP_log(APP_LOG_MAX, "[%s] Recovery Counter value %d\n", pmic_device[v_id_u8].name, regData);
        pmic_device[v_id_u8].CurRecoveryCounter = regData;
        if(D_PMIC_RECOV_CNT_THR == regData)
        {
            /* At this point, PMIC shoudl be reset */
            Set_ResetPMICFlag(true);
        } else {/* Do Nothing */}
    }

    return pmicStatus;
}

/*!
 * \brief   This function is used to check for wdg error
* Core 	Core Id on CAN Msg		        SEID					   SEID on CAN Msg		Data on CAN		Value in FDF2 on failure
*                                                                                                         In Dec			In HEX
* MCU1_0		1					Cdd_Wdg_MCU1_0_Checkpoint			    1				    0x0101		26				    1A
*                                   Safety_Task_00_10ms_Checkpoint		    5				    0x0105		27				    1B
*                                   Safety_Task_01_10ms_Checkpoint		    6				    0x0106		28				    1C
*                                   Safety_Com_Task_10ms_Checkpoint		    7				    0x0107		29				    1D
*                                   Safety_Task_200ms_Checkpoint		    8				    0x0108		43				    2B
* MCU2_0		2					TaskBswB10msec  					    1				    0x0201		30				    1E
*                                   TaskAppB10msec  					    2				    0x0202		37				    25
*                                   TaskAppB30msec  					    3				    0x0203		38				    26
* MCU2_1		3				    TaskBSWSafety10msec					    1				    0x0301		31				    1F
*                                   TaskAppB10msecHiPrio				    2				    0x0302		32				    20
*                                   TaskBSWQM1msec						    3				    0x0303		33				    21
*                                   TaskBSWQM10msec						    4				    0x0304		34				    22
* MPU1_0		4					NA									    4				    0x0404		35				    23
 */
static uint8_t Pmic_utils_CheckforWdgReset(uint16_t u16ErrMngrVal, uint8_t u8SoftRebootReason)
{
    /* DD-ID:{4B939843-C9AD-4771-A198-65A28974A54A}*/
    uint8_t  u8RetVal;
    uint8_t  u8SEID;
    uint16_t u16WdgErrVal = V_wdgGetWdgErrorVal();

    u8SEID = (uint8_t)u16WdgErrVal;

    switch(u16ErrMngrVal)
    {
        case (uint16_t)ldef_B_ErrorMgr_Error_SysIntFlt_WDG_Health_Monitoring_Failure_2_1_Main_Domain:
        {
            if(WDG_RST_SEID_VAL_1 == u8SEID){
                u8RetVal = SAFESTATE_REASON_MCU2_1_CHKPT_0_Task_BSW_Safety_10ms;
            }
            else if(WDG_RST_SEID_VAL_2 == u8SEID){
                u8RetVal = SAFESTATE_REASON_MCU2_1_CHKPT_1_Task_BSW_QM_1ms;
            }
            else if(WDG_RST_SEID_VAL_3 == u8SEID){
                u8RetVal = SAFESTATE_REASON_MCU2_1_CHKPT_2_Task_BSW_QM_10ms;
            }
            else if(0x04u == u8SEID){
                u8RetVal = SAFESTATE_REASON_MCU2_1_CHKPT_3;
            }
            else{
                u8RetVal = SAFESTATE_REASON_MCU2_1_CHKPT_UNKNOWN;
            }                        
        }
        break;

        case (uint16_t)ldef_B_ErrorMgr_Error_SysIntFlt_WDG_Health_Monitoring_Failure_1_0_MCU_Domain:
        {
            if(WDG_RST_SEID_VAL_1 == u8SEID){
                u8RetVal = SAFESTATE_REASON_MCU1_0_CHKPT_0_Task_WDG_Main;
            }
            else if(WDG_RST_SEID_VAL_2 == u8SEID){
                u8RetVal =  SAFESTATE_REASON_MCU2_0_CHKPT_0;
            }
            else if(WDG_RST_SEID_VAL_4 == u8SEID){
                u8RetVal =  SAFESTATE_REASON_MPU1_0_CHKPT_0;
            }                 
            else if(WDG_RST_SEID_VAL_5 == u8SEID){
                u8RetVal = SAFESTATE_REASON_MCU1_0_CHKPT_4_Safety_Task_00_10ms;
            }
            else if(WDG_RST_SEID_VAL_6 == u8SEID){
                u8RetVal = SAFESTATE_REASON_MCU1_0_CHKPT_5_Safety_Task_01_10ms;
            }
            else if(WDG_RST_SEID_VAL_7 == u8SEID){
                u8RetVal = SAFESTATE_REASON_MCU1_0_CHKPT_6_Safety_Com_Task_10ms;
            }
            else if(WDG_RST_SEID_VAL_8 == u8SEID){
                u8RetVal = SAFESTATE_REASON_MCU1_0_CHKPT_7_Safety_Task_200ms;
            }            
            else{
                u8RetVal = SAFESTATE_REASON_MCU1_0_CHKPT_UNKNOWN;
            }              
        }
        break;

        case (uint16_t)ldef_B_ErrorMgr_Error_SysIntFlt_WDG_Health_Monitoring_Failure_2_0_Main_Domain:
        {
            if(WDG_RST_SEID_VAL_1 == u8SEID){
                u8RetVal = SAFESTATE_REASON_MCU2_0_CHKPT_0;
            }
            else if(WDG_RST_SEID_VAL_2 == u8SEID){
                u8RetVal = SAFESTATE_REASON_MCU2_0_CHKPT_1;
            }
            else if(WDG_RST_SEID_VAL_3 == u8SEID){
                u8RetVal = SAFESTATE_REASON_MCU2_0_CHKPT_2;
            }
            else{
                u8RetVal = SAFESTATE_REASON_MCU2_0_CHKPT_UNKNOWN;
            }                             
        }
        break;

        case (uint16_t)ldef_B_ErrorMgr_Error_SysIntFlt_WDG_Health_Monitoring_Failure_1_0_MPU_Domain:
        {
            if(WDG_RST_SEID_VAL_4 == u8SEID){
                u8RetVal =  SAFESTATE_REASON_MPU1_0_CHKPT_0;
            }
            else{
                u8RetVal = SAFESTATE_REASON_MPU1_0_CHKPT_UNKNOWN;
            }             
        }
        break;

        default:
        {
            u8RetVal = u8SoftRebootReason;
        }
        break;
    }

    return u8RetVal;
}


/*!
 * \brief   This function is used to check for soft reset requets and trigger one
 */
void Pmic_utils_CheckforSoftResetReq(void)
{
    /* DD-ID:{00918467-49BF-45c6-AF92-BE5556474DF5}*/
    static volatile int32_t v_u32_forever_loop = 0;
    static uint8_t ss2_switch = 0u;
    static bool bFlagErrMngr = false;
    static sint8_t bSafetyGuardNvM = 0;
    static sint8_t bSafeState2NvM = 0;
    static uint8_t nvmWrTimeoutCnt = 0;
    uint16_t ss2_nvmCnt = 0u;

    if(true == pmic_req_soft_reboot)
    {
    	nvmWrTimeoutCnt++;
        switch(ss2_switch)
        {
            case 0:
            {
                /* Check for Wdg error only if Safe state 2 is triggered from Error Manager */
                if(SAFESTATE_REASON_ERROR_MGR == pmic_req_soft_reboot_reason)
                {
                    bFlagErrMngr = true;
                    /* Write ErrorMgr reset reasonEnum in NVM */
                    SafetyGuard_NVM_Write_ResetReason();
                    pmic_req_soft_reboot_reason = Pmic_utils_CheckforWdgReset(Rte_Safety_Guard_SafeStat2_ResetReason_MirrorBlock_copy, pmic_req_soft_reboot_reason);
                } else {/* Do Nothing */}
                /* Write Safe State Reason in NVM */
                Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus(0u, pmic_req_soft_reboot_reason, (uint8_t)FALSE);
                #ifdef PMIC_PRINT_ENABLE
                APP_log(APP_LOG_ERR, "  Error Manager Reset Reason: %d & Safe State 2 Reason: %d ", \
                    Rte_Safety_Guard_SafeStat2_ResetReason_MirrorBlock_copy, pmic_req_soft_reboot_reason);
                #endif
                ss2_switch++;
            }
            break;

            case 1:
            {
            	do{
            		ss2_nvmCnt++;
            		/* Call NVM related runnables to fasten NVM storage process */
            		NvM_MainFunction();
            		Ea_MainFunction();
            		Eep_30_XXi2c01_MainFunction();
            		/* Check if Reset from ErrorMgr */
                    if(true == bFlagErrMngr)
                    {
                        /* Get SafetyGuard NVM block status */
                        bSafetyGuardNvM = SafetyGuard_Wait_for_NVM_Write_Status();
                		if((sint8_t)NVM_WR_FAILED == bSafetyGuardNvM)
                		{
                			/* NVM Req failed, rewrite */
                        	SafetyGuard_NVM_Write_ResetReason();
                		} else {/* Do Nothing */}
                    }
                    else
                    {
                        bSafetyGuardNvM = NVM_WR_DONE;
                    }
                    /* Get SafeState2 NVM block status */
                    bSafeState2NvM = Cdd_Safety_Wait_for_NVM_Write_Status();
            		if((sint8_t)NVM_WR_FAILED == bSafeState2NvM)
            		{
            			/* NVM Req failed, rewrite */
            			Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus(0u, pmic_req_soft_reboot_reason, (uint8_t)FALSE);
            		} else {/* Do Nothing */}

                    /* Check if NVM block storage done? */
            		if((((sint8_t)NVM_WR_DONE == bSafetyGuardNvM) && ((sint8_t)NVM_WR_DONE == bSafeState2NvM)) || (nvmWrTimeoutCnt > (uint8_t)NVM_WR_TIMEOUT_CNT))
            		{
            			if(true == pmic_device[PMIC_DEV_0].regLocked)
            			{
            				(void)Pmic_utils_Write(&pmic_device[PMIC_DEV_2].pmicCoreHandle, D_PMIC_TPS65941_REGISTER_LOCK, D_PMIC_REG_UNLOCK_KEY);
            				(void)Pmic_utils_Write(&pmic_device[PMIC_DEV_0].pmicCoreHandle, D_PMIC_TPS65941_REGISTER_LOCK, D_PMIC_REG_UNLOCK_KEY);
            				(void)Pmic_utils_Write(&pmic_device[PMIC_DEV_1].pmicCoreHandle, D_PMIC_TPS65941_REGISTER_LOCK, D_PMIC_REG_UNLOCK_KEY);
            			} else {/* Do Nothing */}

            			/* restore the values of BUCKX_CTRL */
            			(void)Pmic_utils_Write(&pmic_device[PMIC_DEV_0].pmicCoreHandle, D_PMIC_TPS65941_BUCK3_CTRL, LEOA_BUCK3_CTRL_SOFT_REBOOT);
            			(void)Pmic_utils_Write(&pmic_device[PMIC_DEV_0].pmicCoreHandle, D_PMIC_TPS65941_BUCK5_CTRL, LEOA_BUCK5_CTRL_SOFT_REBOOT);
            			(void)Pmic_utils_Write(&pmic_device[PMIC_DEV_1].pmicCoreHandle, D_PMIC_TPS65941_BUCK3_CTRL, LEOB_BUCK3_CTRL_SOFT_REBOOT);
            			(void)Pmic_utils_Write(&pmic_device[PMIC_DEV_1].pmicCoreHandle, D_PMIC_TPS65941_BUCK4_CTRL, LEOB_BUCK4_CTRL_SOFT_REBOOT);
            			(void)Pmic_utils_Write(&pmic_device[PMIC_DEV_1].pmicCoreHandle, D_PMIC_TPS65941_BUCK5_CTRL, LEOB_BUCK5_CTRL_SOFT_REBOOT);
            			/* Write user spare regs for notifying this is a soft reboot */
            			/*pmicStatus = Pmic_utils_Write(&pmic_device[PMIC_DEV_2].pmicCoreHandle, D_PMIC_TPS65941_USER_SPARE_REGS, (pmic_req_soft_reboot_reason & 0x0F));*/
            			/* Put Wdg to Long Window during safestate */
            			(void)Pmic_WdgSetRetToLongWindowCfg(&pmic_device[PMIC_DEV_0].pmicCoreHandle, PMIC_WDG_RETLONGWIN_ENABLE);

            			/* Trigger Soft reboot */
            			(void)Pmic_utils_Write(&pmic_device[PMIC_DEV_0].pmicCoreHandle, D_PMIC_TPS65941_SOFT_REBOOT_REG, D_PMIC_SOFT_REBOOR_TRIG);
            			while(v_u32_forever_loop == 0)
                        {
                            /* Intentional empty loop - waiting for Wdg to reset if PMIC cold rebood failed */
                        }
            		} else {/* Do Nothing */}
            	}while(ss2_nvmCnt < (uint16_t)PMIC_NVM_STORE_CNT);
            }
            break;

            default:
            {
                /* Do Nothing */
                break;
            }
        }
    } else {/* Do Nothing */}
}

/*!
 * \brief   This function will be called at Init and read the NvM for last reset reason and clear the NVM data
 */
void Pmic_utils_NvMRead_PMICLastResetReason(void)
{
    /* DD-ID:{A6E38263-B861-4629-ADAE-A1A2B2D501EF}*/
    /* Locals */
    uint8_t u8_NvMData = 0x0u;
    /* Read the PMIC Last Reset Reason from NvM memory */
    Cdd_Safety_NVM_Read_PMICLastResetReason_BISTStatus(0u, &u8_NvMData);
    /* Store the last reset reason */
    if(SAFESTATE_REASON_PMIC_WDG_RESET_MCU1_0 != pmic_lastReset)
    {
        pmic_lastReset = u8_NvMData;
    } else {/* Do Nothing */}
    /* Write Safe State SAFESTATE_REASON_NO_ERROR in NVM */
    if(u8_NvMData != SAFESTATE_REASON_NO_ERROR)
    {
    	Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus(0u, SAFESTATE_REASON_NO_ERROR, (uint8_t)FALSE);
    } else {/* Do Nothing */}   
}

/*!
 * \brief   This function is used to get last reset status from pmic in case of soft reboot
 */
uint8_t pmic_utils_getLastReset(void)
{
    /* DD-ID:{C43567D2-73F1-4b31-8005-8D07D153EA7F}*/
    return pmic_lastReset;
}

uint8_t Pmic_utils_getCRCStatus(void)
{
    /* DD-ID:{38EFDCFD-DC25-419d-9608-B263783D591A}*/
    uint8_t regData = 0, i2c1SpiCrcStatus = 0;
    int32_t pmicStatus;
    pmicStatus = Pmic_utils_read(&pmic_device[PMIC_DEV_0].pmicCoreHandle, PMIC_SERIAL_IF_CONFIG_REGADDR, &regData);
    if(PMIC_ST_SUCCESS == pmicStatus)
    {
        i2c1SpiCrcStatus = Pmic_getBitField(regData,PMIC_SERIAL_IF_CONFIG_I2C1_SPI_CRC_EN_SHIFT,PMIC_SERIAL_IF_CONFIG_I2C1_SPI_CRC_EN_MASK);
    } else {/* Do Nothing */}

    return i2c1SpiCrcStatus;
    
}
