/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2019-2020
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#include <stdint.h>
#include <ti/osal/osal.h>
#include <include/soc/j721s2/sdlr_soc_baseaddress.h>
#include "ecc_ddr.h"
#include "fusa_application.h"

/* ----------------- Constant definitions ----------------- */
#define CDD_Safety_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* Local variables */
#if ( SDL_APP_DDR_ECC_SELFTEST_ENABLED == SDL_APP_ON )
volatile uint32_t testVal;
volatile uint32_t *gTest_Addr;
#endif
#define CDD_Safety_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* -------------------------------------------------------- */
#define CDD_Safety_START_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* ----------------- Function prototypes ------------------ */
static int32_t DDREccConfig(uint32_t eccMemType);
#if ( SDL_APP_DDR_ECC_SELFTEST_ENABLED == SDL_APP_ON )
static int32_t DDRSecErrTest(CSL_ecc_aggrRegs *eccAggrRegs, uint32_t ramId);
static int32_t DDRDedErrTest(CSL_ecc_aggrRegs *eccAggrRegs, uint32_t ramId);
#endif
/* -------------------------------------------------------- */


#if ( SDL_APP_DDR_ECC_SELFTEST_ENABLED == SDL_APP_ON )
extern volatile uint32_t gSecTestPass;
extern volatile uint32_t gDedTestPass;
/* Function executes Emif ECC Test */
int32_t DDREccTest(void)
{
  /* DD-ID: {285443DB-730A-41dd-91CC-033E13CB6686}*/
    int32_t retVal;
    uint32_t   ramId = ECC_AGGR_UNKNOWN_RAM_ID;

     /* Single bit error */
    retVal = DDRSecErrTest(NULL, ramId);
      /* double bit error */
  /*  retVal = DDRDedErrTest(NULL, ramId);*/

    return retVal;
}
#endif
/* Function initialized DDR ECC */
void DDREccInit(void)
{
  /* DD-ID: {5FB567AC-3368-4f43-8448-D0F0118B1C37}*/
    int32_t cslRet;

    /* Ecc config */
    cslRet = DDREccConfig(APP_ECC_MEMTYPE_DDR);

    if (cslRet != CSL_PASS)
    {
    }
    return;
}
#if ( SDL_APP_DDR_ECC_SELFTEST_ENABLED == SDL_APP_ON )
uintptr_t DDRGetTranslatedAddress(uintptr_t memAddress)
{
  /* DD-ID: {EC7036D2-1B7A-4dc6-86D2-3E86A23153C4}*/
    uint32_t memIndex;
    uintptr_t translatedMemAddr;

    memIndex = (memAddress-0x80000000u)/EMIF_ECC_MEM_BLOCK_SIZE;
    if ((memIndex & 0x1u) == 0)
    {
        translatedMemAddr = memAddress + ((memIndex)*EMIF_ECC_DATA_SIZE_PER_BLOCK);
    }
    else
    {
        translatedMemAddr = memAddress + ((memIndex+1u)*EMIF_ECC_DATA_SIZE_PER_BLOCK);
    }
    return  translatedMemAddr;
}
#endif

/* Function configures DDR ECC
 * Also primes the memory area
 */
static int32_t DDREccConfig(uint32_t eccMemType)
{
  /* DD-ID: {ECFEA006-1053-4bfe-99F1-508A57C7CAAC}*/
    int32_t    cslResult = CSL_PASS;
    int32_t    retVal = 0;

   (void)eccMemType;

    /* clear interrupt status */
    cslResult = CSL_emifClearECCInterruptStatus((CSL_emif_sscfgRegs *)SDL_COMPUTE_CLUSTER0_DDR0_0_SS_CFG_BASE,
                                            CSL_EMIF_SSCFG_V2A_INT_SET_REG_ECC1BERR_EN_MASK
                                            | CSL_EMIF_SSCFG_V2A_INT_SET_REG_ECCM1BERR_EN_MASK
                                            | CSL_EMIF_SSCFG_V2A_INT_SET_REG_ECC2BERR_EN_MASK);
    if (cslResult != CSL_PASS)
    {
        retVal = -1;
    }

    if ( retVal == 0 )
    {
        /* Configure ECC interrupts : 1 bit error , 1 bit error multiple and 2 bit errors */
        cslResult = CSL_emifEnableECCInterrupts((CSL_emif_sscfgRegs *)SDL_COMPUTE_CLUSTER0_DDR0_0_SS_CFG_BASE,
                                                CSL_EMIF_SSCFG_V2A_INT_SET_REG_ECC1BERR_EN_MASK
                                                | CSL_EMIF_SSCFG_V2A_INT_SET_REG_ECCM1BERR_EN_MASK
                                                | CSL_EMIF_SSCFG_V2A_INT_SET_REG_ECC2BERR_EN_MASK);
        if (cslResult != CSL_PASS)
        {

            retVal = -1;
        }
    }

    if ( retVal != 0 )
    {

    }

    return (retVal);
}

#if ( SDL_APP_DDR_ECC_SELFTEST_ENABLED == SDL_APP_ON )
/* Function performs DDR single bit error test
 * Configures ECC, Inserts single bit error
 * and waits for handler to finish
 */
int32_t DDRSecErrTest(CSL_ecc_aggrRegs *eccAggrRegs, uint32_t ramId)
{
  /* DD-ID: {AC052C4C-FFE1-4b2c-AD53-A6EACC4C6910}*/
    int32_t  retVal = CSL_EFAIL;
    volatile uint32_t testVal2, testVal3;
    volatile uint32_t *translatedMemPtr;
    uint32_t waitCount = 0;

    /* set the test status to false */
    gSecTestPass = FALSE;

    /* Below code runs in SRAM so in order to make sure the timer interrupt
    does not disturb the below test, disable timer interrupt*/
    Osal_DisableInterrupt(0, 39);

    /* Clear any residual ECC errors */
    CSL_emifClearAllECCErrors((CSL_emif_sscfgRegs *)SDL_COMPUTE_CLUSTER0_DDR0_0_SS_CFG_BASE);

    /* Inject error */
    gTest_Addr = (uint32_t *) (DDR_ECC_TEST_ADDR);

    /* Write back any pending writes */
    CacheP_wbInv((const void *)gTest_Addr, 4);

    /* Read value from test location */
    testVal = gTest_Addr[0];

    /* Flip one bit to introduce error */
    testVal2       = testVal ^ 0x00010000u;

    /* Calculate translated address */
    translatedMemPtr = (volatile uint32_t *)(DDRGetTranslatedAddress((uintptr_t)gTest_Addr));

    /* NOTE: The following section is test code only cannot be used in real application */
    /* ================================================================================ */

    /* Temporarily disable ECC */
    CSL_emifDisableECC((CSL_emif_sscfgRegs *)SDL_COMPUTE_CLUSTER0_DDR0_0_SS_CFG_BASE);

    /* Now corrupt the value */
    *(translatedMemPtr) = testVal2;
    CacheP_wbInv((const void *)translatedMemPtr, 4);

    /* Enable back ECC */
    CSL_emifEnableECC((CSL_emif_sscfgRegs *)SDL_COMPUTE_CLUSTER0_DDR0_0_SS_CFG_BASE);

    /* ================================================================================ */

    /* Invalidate cache */
    CacheP_Inv((const void *)gTest_Addr, 4);

    /* Read value to trigger error */
    testVal3 = gTest_Addr[0];

    /* wait until the test passes */

    while ((gSecTestPass == FALSE)&& (waitCount++ < 300u)) {
        Osal_delay(10);
    }

    /* Restore original value */
    gTest_Addr[0] = testVal;

    /* Write back any pending writes */
    CacheP_wbInv((const void *)gTest_Addr, 4);

    /* Enable the timer interrupt */
    Osal_EnableInterrupt(0, 39);

    /* return the test status */
    return retVal;
}

/* Function performs DDR double bit error test
 * Inserts double bit error and waits for handler to finish
 */
static int32_t DDRDedErrTest(CSL_ecc_aggrRegs *eccAggrRegs, uint32_t ramId)
{
  /* DD-ID: {8A731171-9C95-4576-AB5C-A0C3EE6EEE3D}*/
    int32_t  retVal = CSL_EFAIL;
    volatile uint32_t testVal;
    volatile uint32_t testVal2, testVal3;
    volatile uint32_t *translatedMemPtr;
    uint32_t waitCount = 0;
    uint32_t ictr=0;

    /* MCU_ESM0_ESM_INT_HI_LVL_0 -49*/
    int32_t interruptarr[10]={0,2,6,7,18,36,37,39,44,47,48,53,70,71,72,73,78,79,96,98,99,100,140,141,142,290,291,295,296,297,298,299,300,
    304,305,306,307,308,309,310,312,313,314,317,376,377};

    int32_t arr_size = sizeof(interruptarr) / sizeof(interruptarr[0]);


    gDedTestPass = FALSE;
    /* Below code runs in SRAM so in order to make sure the timer interrupt
    does not disturb the below test, disable timer interrupt*/

    for(ictr=0;ictr<=arr_size;ictr++)
    {
      Osal_DisableInterrupt(0, interruptarr[ictr]);
    }
    /* Clear any residual ECC errors */
    CSL_emifClearAllECCErrors((CSL_emif_sscfgRegs *)SDL_COMPUTE_CLUSTER0_DDR0_0_SS_CFG_BASE);

    gTest_Addr = (uint32_t *) (DDR_ECC_TEST_ADDR);

    CacheP_wbInv((const void *)gTest_Addr, 4);
     /* Read reference value */
    testVal       = gTest_Addr[0];
    /* flip 2 bits */
    testVal2       = testVal ^ 0x00101000u;
    /* Calculate translated address */
    translatedMemPtr = (volatile uint32_t *)(DDRGetTranslatedAddress((uintptr_t)gTest_Addr));

    /* Temporarily disable ECC */
    CSL_emifDisableECC((CSL_emif_sscfgRegs *)SDL_COMPUTE_CLUSTER0_DDR0_0_SS_CFG_BASE);

    /* Now corrupt the value */
    *(translatedMemPtr) = testVal2;

    /* Make sure the values are written back */
    CacheP_wbInv((const void *)translatedMemPtr, 4);

    /* Enable back ECC */
    CSL_emifEnableECC((CSL_emif_sscfgRegs *)SDL_COMPUTE_CLUSTER0_DDR0_0_SS_CFG_BASE);

    /* Invalidate cache */
    CacheP_Inv((const void *)gTest_Addr, 4);

    /* Read value to trigger error */
    testVal3 = gTest_Addr[0];

    /* wait until the test passes */

     while ((gDedTestPass == FALSE)&& (waitCount++ < 300u)) {
        Osal_delay(10);
    }

    /* Restore original value */
    gTest_Addr[0] = testVal;

    /* Enable the timer interrupt */
    Osal_EnableInterrupt(0, 39);

    /* return the test status */
    return retVal;
}
#endif
#define CDD_Safety_STOP_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* Nothing past this point */
