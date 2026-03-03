/*
* @Author: Shalhoob Manatheykad
* @Date:   2023-08-24 11:20:50
* @Last Modified by:   Manatheykad, Shalhoob
* @Last Modified time: 2023-09-05 00:18:06
*/

#include <stdint.h>
#include "vim_mainR5.h"
// #include "compiler_asildefs.h"

#define         SDL_MCU_ARMSS_VIM_NULL_ADDR           ((void *) 0 )


/* To be deleted */
#define ASILB_DATA_SECTION
#define ASILB_CODE_SECTION
#define ASILB_CONST_SECTION

/**
 * @function name - Safety_VIM_VerifyStaticRegs
 * @param - Safety_vimStaticRegs *arm_vim_static_data
 * @return - int32_t
 * @description - Verify Static registers
 */
ASILB_CODE_SECTION int32_t Safety_VIM_VerifyStaticRegs( const Safety_vimStaticRegs *arm_vim_static_data)
{
  /* DD-ID: {DD7C09CD-0C4A-4708-9FE2-DE737DEE6F82}*/
    int32_t  retVal = SDL_PASS;
    Safety_vimStaticRegs vimData;

    SDL_vimRegs *pRegs; 
    pRegs = (SDL_vimRegs *)(uintptr_t)SDL_MAIN_DOMAIN_VIM_BASE_ADDR;

    if ( pRegs == SDL_MCU_ARMSS_VIM_NULL_ADDR)
    {
        /* No actions - API fails to read back */
        retVal = SDL_EFAIL;
    }

    if (retVal == SDL_PASS)
    {
        vimData.PID  = SDL_REG32_RD(&pRegs->PID);
        vimData.INFO = SDL_REG32_RD(&pRegs->INFO);
        //vimData.IRQVEC = SDL_REG32_RD(&pRegs->IRQVEC);
        //vimData.FIQVEC = SDL_REG32_RD(&pRegs->FIQVEC);
        vimData.DEDVEC = SDL_REG32_RD(&pRegs->DEDVEC);
        retVal = SDL_PASS;
    }

    if (retVal != SDL_EFAIL)
    {
        /* verify if parameter matches */
        if ((vimData.PID != arm_vim_static_data->PID) || 
            (vimData.INFO != (uint32_t)arm_vim_static_data->INFO) ||
            //(vimData.IRQVEC != arm_vim_static_data->IRQVEC) ||
            //(vimData.FIQVEC != arm_vim_static_data->FIQVEC) ||
            (vimData.DEDVEC != arm_vim_static_data->DEDVEC))
        {
            retVal = SDL_EFAIL;
        }
    }

    return (retVal);
}

/**
 * @function name - Safety_VIM_verifyCfgIntr
 * @param - Safety_arm_vim_cfg * arm_vim_cfg_data
 * @return - int32_t
 * @description - Verify Interrupt config
 */
ASILB_CODE_SECTION int32_t Safety_VIM_verifyCfgIntr( const Safety_arm_vim_cfg *arm_vim_cfg_data)
{
  /* DD-ID: {FF26875D-A93C-432d-A1FF-9BE649FDBF52}*/
    int32_t  retVal = SDL_EFAIL;
    uint32_t bitNum, groupNum;
    uint32_t intrMapVal, intrTypeVal, priVal, vecVal, intrEnSetVal, intrEnClrVal;
    uint32_t    maxIntrs = 0, num_groups = 0;

    SDL_vimRegs *pRegs; 
    pRegs = (SDL_vimRegs *)(uintptr_t)SDL_MAIN_DOMAIN_VIM_BASE_ADDR;

    if (pRegs != SDL_MCU_ARMSS_VIM_NULL_ADDR)
    {
        maxIntrs   = pRegs->INFO;
        num_groups = maxIntrs / SDL_VIM_NUM_INTRS_PER_GROUP;
        groupNum = arm_vim_cfg_data->intrNum / SDL_VIM_NUM_INTRS_PER_GROUP;
    
        /* Condition "(vecAddr - 1U)" is need for THUMB Mode as TI ARM CLANG marks LSB as '1' */
        if( (arm_vim_cfg_data->intrNum < maxIntrs)                              &&
            (arm_vim_cfg_data->pri <= SDL_VIM_PRI_INT_VAL_MAX)                  &&
            (arm_vim_cfg_data->intrMap <= SDL_VIM_INTR_MAP_FIQ)                 &&
            (arm_vim_cfg_data->intrType <= SDL_VIM_INTR_TYPE_PULSE))
            //             &&
            //(((arm_vim_cfg_data->vecAddr & SDL_VIM_VEC_INT_VAL_MASK) == arm_vim_cfg_data->vecAddr) ||
            //    (((arm_vim_cfg_data->vecAddr - (uint32_t)1U) & SDL_VIM_VEC_INT_VAL_MASK) == (arm_vim_cfg_data->vecAddr - (uint32_t)1U))))
        {
            bitNum = arm_vim_cfg_data->intrNum & (SDL_VIM_NUM_INTRS_PER_GROUP-1U);
    
            /* Read INTMAP */
            intrMapVal  = SDL_REG32_RD( &pRegs->GRP[groupNum].INTMAP );
            /* Get the interrupt map value */
            intrMapVal  = intrMapVal >> bitNum;
            intrMapVal &= (uint32_t)(0x1U);
    
            /* Read INTTYPE */
            intrTypeVal  = SDL_REG32_RD( &pRegs->GRP[groupNum].INTTYPE );
            /* Get the interrupt type value */
            intrTypeVal  = intrTypeVal >> bitNum;
            intrTypeVal &= (uint32_t)(0x1U);

            /* Read INTR_EN_SET */
            intrEnSetVal  = SDL_REG32_RD( &pRegs->GRP[groupNum].INTR_EN_SET );
            /* Get the interrupt En Set value */
            intrEnSetVal  = intrEnSetVal >> bitNum;
            intrEnSetVal &= (uint32_t)(0x1U);

            /* Read INTR_EN_CLR */
            intrEnClrVal  = SDL_REG32_RD( &pRegs->GRP[groupNum].INTR_EN_CLR );
            /* Get the interrupt En Clear value */
            intrEnClrVal  = intrEnClrVal >> bitNum;
            intrEnClrVal &= (uint32_t)(0x1U);
    
            /* Read PRI */
            priVal = SDL_REG32_RD( &pRegs->PRI[arm_vim_cfg_data->intrNum].INT);
    
            /* Read VEC */
            //vecVal = SDL_REG32_RD( &pRegs->VEC[arm_vim_cfg_data->intrNum].INT);
                retVal = SDL_PASS;
        }
    }

    if (retVal != SDL_EFAIL)
    {
        /* verify if parameter matches */
        if ((intrMapVal != arm_vim_cfg_data->intrMap) || 
            (intrTypeVal != (uint32_t)arm_vim_cfg_data->intrType) ||
            (priVal != arm_vim_cfg_data->pri) ||
            (intrEnSetVal != arm_vim_cfg_data->intrEnSet) ||
            (intrEnClrVal != arm_vim_cfg_data->intrEnClr))
            // || (vecVal != arm_vim_cfg_data->vecAddr))
        {
            retVal = SDL_EFAIL;
        }
    }

    return retVal;
}

//static volatile uint32_t intrMapVal, intrTypeVal, priVal, vecVal, intrEnSetVal, intrEnClrVal;
/**
 * @function name - Safety_VIM_ReadCfgIntr
 * @param - Interrupt num
 * @return - int32_t
 * @description - Read VIm config for the interrupt
 */
int32_t Safety_VIM_ReadCfgIntr(uint32_t intrNum)
{
  /* DD-ID: {E6F66D19-6AE4-44d0-88E1-31ACAAE50854}*/
    int32_t  retVal = SDL_EFAIL;
    uint32_t bitNum, groupNum;
    uint32_t    maxIntrs = 0, num_groups = 0;
    uint32_t intrMapVal, intrTypeVal, priVal, vecVal, intrEnSetVal, intrEnClrVal;

    SDL_vimRegs *pRegs;
    pRegs = (SDL_vimRegs *)(uintptr_t)SDL_MAIN_DOMAIN_VIM_BASE_ADDR;

    if (pRegs != SDL_MCU_ARMSS_VIM_NULL_ADDR)
    {
        maxIntrs   = pRegs->INFO;
        num_groups = maxIntrs / SDL_VIM_NUM_INTRS_PER_GROUP;
        groupNum = intrNum / SDL_VIM_NUM_INTRS_PER_GROUP;
    
        /* Condition "(vecAddr - 1U)" is need for THUMB Mode as TI ARM CLANG marks LSB as '1' */
        if(intrNum < maxIntrs)
        {
            bitNum = intrNum & (SDL_VIM_NUM_INTRS_PER_GROUP-1U);
    
            /* Read INTMAP */
            intrMapVal  = SDL_REG32_RD( &pRegs->GRP[groupNum].INTMAP );
            /* Get the interrupt map value */
            intrMapVal  = intrMapVal >> bitNum;
            intrMapVal &= (uint32_t)(0x1U);
    
            /* Read INTTYPE */
            intrTypeVal  = SDL_REG32_RD( &pRegs->GRP[groupNum].INTTYPE );
            /* Get the interrupt type value */
            intrTypeVal  = intrTypeVal >> bitNum;
            intrTypeVal &= (uint32_t)(0x1U);

            /* Read INTR_EN_SET */
            intrEnSetVal  = SDL_REG32_RD( &pRegs->GRP[groupNum].INTR_EN_SET );
            /* Get the interrupt En Set value */
            intrEnSetVal  = intrEnSetVal >> bitNum;
            intrEnSetVal &= (uint32_t)(0x1U);

            /* Read INTR_EN_CLR */
            intrEnClrVal  = SDL_REG32_RD( &pRegs->GRP[groupNum].INTR_EN_CLR );
            /* Get the interrupt En Clear value */
            intrEnClrVal  = intrEnClrVal >> bitNum;
            intrEnClrVal &= (uint32_t)(0x1U);
    
            /* Read PRI */
            priVal = SDL_REG32_RD( &pRegs->PRI[intrNum].INT);
    
            /* Read VEC */
            vecVal = SDL_REG32_RD( &pRegs->VEC[intrNum].INT);
                retVal = SDL_PASS;
        }
    }

    return retVal;
}

/**
 * @function name - Safety_VIM_setDedVectorAddr
 * @param dedVectorAddr - DED function
 * @return - void
 * @description - Set DED function for VIM
 */
void Safety_VIM_setDedVectorAddr( uint32_t dedVectorAddr )
{
  /* DD-ID: {06356CDA-A917-487b-8A66-7CA52B795888}*/
    SDL_vimRegs *pRegs;
    pRegs = (SDL_vimRegs *)(uintptr_t)SDL_MAIN_DOMAIN_VIM_BASE_ADDR;

    if (pRegs != SDL_MCU_ARMSS_VIM_NULL_ADDR)
    {
        SDL_REG32_WR( &pRegs->DEDVEC, (dedVectorAddr & SDL_VIM_DEDVEC_ADDR_MASK) );
    }
}

__attribute__((interrupt, section(".text.hwi"), aligned(32))) void VIM_VIMDEDInterruptHandler(void);
/**
* @fn      VIM_VIMDEDInterruptHandler
* @brief   DED Interrupt handler
* @param   None
* @return   None
*/
void VIM_VIMDEDInterruptHandler(void)
{
  /* DD-ID: {0671425D-2AD1-4584-B78B-8C6E38D0F2AA}*/
    while(1)
    {
       asm volatile(" wfi");
    }
}

