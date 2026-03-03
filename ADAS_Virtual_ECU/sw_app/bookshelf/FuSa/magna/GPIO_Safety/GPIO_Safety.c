
/**
 * @file GPIO_Safetty.c
 * @brief Implement GPIO FuSa requirement
 *
 * @details This file implement functons that satisfy FuSa requirment for GPIO
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
 * @author Fengyi Chen (fengyi.chen@magna.com)
 */
 
/* ===========================================================================
*
*   Include Files
*
* ========================================================================= */
#include "GPIO_Safety.h"
#include "fusa_application.h"

/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
/* Commented -- can be enabled in Future
* #define GPIO_SAFETY_REG_BINTEN_EN       (1U)
* #define GPIO_SAFETY_REG_DIR_EN          (1U << 1U)
* #define GPIO_SAFETY_REG_OUT_DATA_EN     (1U << 2U)
* #define GPIO_SAFETY_REG_SET_RIS_TRIG_EN (1U << 3U)
* #define GPIO_SAFETY_REG_SET_FAL_TRIG_EN (1U << 4U)
*/

/*#define GPIO_DEBUG_ENABLE*/
#define SHIFT_BIT_POSITION_1 		    (1U)
#define SHIFT_BIT_POSITION_2 		    (2U)
#define SHIFT_BIT_POSITION_3 		    (3U)
#define SHIFT_BIT_POSITION_4 		    (4U)
#define GPIO_PIN_3 				    	(3U)

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

static GPIO_safetyConfig gpio_getPinSafetyConfig(const uint32_t baseAddr, const uint32_t pinNum);
static uint8_t gpio_checkPin(const GPIO_modules gpio, const uint32_t pinNum, const GPIO_safetyConfig expectedCfg);

#define CDD_Safety_START_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"
/* ===========================================================================
*
*   Private variables
*
* ========================================================================= */

/* ===========================================================================
*
*   Global variables
*
* ========================================================================= */
static GPIO_safetyConfig gGPIO_config;

#define CDD_Safety_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"

#define CDD_Safety_START_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* ========================================================================== */
/*                          Function Implementation                           */
/* ========================================================================== */

/* ===========================================================================
*
*   Global functions
*
* ========================================================================= */
/*!
 * \brief   Read GPIO HW register config function for Pin
 *
 *
 * \param   baseAddr  [IN]    Base Address of GPIO module 
 * \param   pinNumber [IN]    Number of Pin of the GPIO module 
 *
 * \retval  Register value for specific pin
 */
static GPIO_safetyConfig gpio_getPinSafetyConfig(const uint32_t baseAddr, const uint32_t pinNum)
{
  /* DD-ID: {B9D9C3DF-D666-44e5-AD10-637610F40DBF}*/
    const CSL_GpioHandle gpio_regHandle = (CSL_GpioHandle) baseAddr;
    const uint32_t bankIndex =  pinNum / GPIO_NUM_PINS_PER_BANK;
    const uint32_t bitPos = pinNum % GPIO_NUM_PINS_PER_BANK;
    GPIO_safetyConfig ret;
    uint32_t result;

    result = CSL_FEXTR(gpio_regHandle->BINTEN, bankIndex, bankIndex);
    /*ret = (uint8_t)((uint8_t)ret | ((uint8_t)((uint8_t)CSL_FEXTR(gpio_regHandle->BANK_REGISTERS[bankIndex].DIR, bitPos, bitPos) << SHIFT_BIT_POSITION_1)));*/
    result |= result | CSL_FEXTR(gpio_regHandle->BANK_REGISTERS[bankIndex].DIR, bitPos, bitPos) << SHIFT_BIT_POSITION_1;
    /*ret = (uint8_t)((uint8_t)ret | ((uint8_t)((uint8_t)CSL_FEXTR(gpio_regHandle->BANK_REGISTERS[bankIndex].OUT_DATA, bitPos, bitPos) << SHIFT_BIT_POSITION_2)));*/
    result |=  result | CSL_FEXTR(gpio_regHandle->BANK_REGISTERS[bankIndex].OUT_DATA, bitPos, bitPos) << SHIFT_BIT_POSITION_2;
    /*ret = (uint8_t)((uint8_t)ret | ((uint8_t)((uint8_t)CSL_FEXTR(gpio_regHandle->BANK_REGISTERS[bankIndex].SET_RIS_TRIG, bitPos, bitPos) << SHIFT_BIT_POSITION_3)));*/
    result |= CSL_FEXTR(gpio_regHandle->BANK_REGISTERS[bankIndex].SET_RIS_TRIG, bitPos, bitPos) << SHIFT_BIT_POSITION_3;
    /*ret = (uint8_t)((uint8_t)ret | ((uint8_t)((uint8_t)CSL_FEXTR(gpio_regHandle->BANK_REGISTERS[bankIndex].SET_FAL_TRIG, bitPos, bitPos) << SHIFT_BIT_POSITION_4)));*/
    result |= CSL_FEXTR(gpio_regHandle->BANK_REGISTERS[bankIndex].SET_FAL_TRIG, bitPos, bitPos) << SHIFT_BIT_POSITION_4;
    ret = (uint8_t)(result);

    return ret; 
}

/*!
 * \brief   
 *
 *
 * \param   gpio      [IN]    Name of GPIO module for FuSa monitoring 
 * \param   pinNumber [IN]    Number of Pin of the GPIO module 
 * \param   cfg       [IN]    Expected GPIO pin safety config 
 *
 * \retval  GPIO_SAFETY_PASS, GPIO_SAFETY_FAIL 
 */
static uint8_t gpio_checkPin(const GPIO_modules gpio, const uint32_t pinNum, const GPIO_safetyConfig expectedCfg)
{
  /* DD-ID: {238CDCDD-B51E-47d8-A6FD-2DBAC8DDC42B}*/
    GPIO_safetyConfig readCfg;

    switch(gpio)
    {
    default:
    case WKUP_GPIO0:
        readCfg = gpio_getPinSafetyConfig((uint32_t)CSL_WKUP_GPIO0_BASE, pinNum);
        break;
    case WKUP_GPIO1:
        readCfg = gpio_getPinSafetyConfig((uint32_t)CSL_WKUP_GPIO1_BASE, pinNum);
        break;
    case GPIO0:
        readCfg = gpio_getPinSafetyConfig((uint32_t)CSL_GPIO0_BASE, pinNum);
        break; 
    case GPIO2:
        readCfg = gpio_getPinSafetyConfig((uint32_t)CSL_GPIO2_BASE, pinNum);
        break; 
    case GPIO4:
        readCfg = gpio_getPinSafetyConfig((uint32_t)CSL_GPIO4_BASE, pinNum);
        break; 
    case GPIO6:
        readCfg = gpio_getPinSafetyConfig((uint32_t)CSL_GPIO6_BASE, pinNum);
        break; 
    }

    if ((uint32_t)readCfg == (uint32_t)expectedCfg)
    {
        return GPIO_SAFETY_PASS;
    }
    else
    {
        return GPIO_SAFETY_FAIL;
    }
}

/*
 * Purpose: GPIO safety check init function 
 * Description: Readback all the safety related GPIO registers 
 * Return Type : void 
 */

void TASK_gpio_safety_init(void)
{
  /* DD-ID: {7F8D5069-2BC3-443b-AEFD-ADB97A79F4DC}*/
    /* Store GPIO config in global parameter*/
    gGPIO_config = gpio_getPinSafetyConfig((uint32_t)CSL_WKUP_GPIO0_BASE, GPIO_PIN_3);
}

/*
 * Purpose: GPIO safety check main function 
 * Description: Readback and check all the safety related GPIO registers 
 * Return Type : void 
 */

void TASK_gpio_safety_MainFunction(void)
{
  /* DD-ID: {ED3BF704-1482-421c-BFAE-43601DF9D74C}*/
    uint8_t result = GPIO_SAFETY_FAIL;
#ifdef GPIO_DEBUG_ENABLE
    static GPIO_safetyConfig tmpGPIO_config;

    /* Store for debug purposes */
    tmpGPIO_config = gpio_getPinSafetyConfig((uint32_t)CSL_WKUP_GPIO0_BASE, GPIO_PIN_3);
#endif
    /* Need to monitor WKUP_GPIO0_3 MCU_INTn_3V3 pin*/
    result = gpio_checkPin(WKUP_GPIO0, GPIO_PIN_3, gGPIO_config);

    if ((uint32_t)result == (uint32_t)GPIO_SAFETY_FAIL)
    {
        Fusa_Application_SetGpioSafetyCriticalConfigFailFlag();
    } 
    else
    {
        Fusa_Application_ClearGpioSafetyCriticalConfigFailFlag();
    }

}
/*===============================End Of File========================================================*/

#define CDD_Safety_STOP_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
