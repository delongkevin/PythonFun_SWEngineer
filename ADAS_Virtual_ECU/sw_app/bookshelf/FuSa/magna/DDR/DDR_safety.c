/** @file DDR_safety.c 
 *  @brief  DDR safety Application
 * 
 *  DDR Safety Application
 * 
 *  --------------------------------------------------------------------------
 *  @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * 
 *  @author Raghavender Yadagiri (Raghavender.Yadagiri@magna.com)
 */

/**
 * This file contains functions that monitors safety
 * for the DDR module.
 *
 *  \details DDR Safety module
 */
 
/* ===========================================================================
*
*   Include Files
*
* ========================================================================= */

#include "sdlr_soc_baseaddress.h"
#include <string.h>
#include "app_log_Boot.h"
#include "fusa_application.h"

#include "DDR_safety.h"

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

  typedef struct {
    uint32_t DDRSS_SS_ID_REV_REG;                 /* Offset 0h */
    uint32_t DDRSS_SS_CTL_REG;                    /* Offset 4h */
    uint8_t  Reserved_bytes_1[24];                /* Reserved bytes */
    uint32_t DDRSS_V2A_CTL_REG;                   /* Offset 20h */
    uint32_t DDRSS_V2A_R1_MAT_REG;                /* Offset 24h */
    uint32_t DDRSS_V2A_R2_MAT_REG;                /* Offset 28h */
    uint32_t DDRSS_V2A_R3_MAT_REG;                /* Offset 2Ch */
    uint32_t DDRSS_V2A_LPT_DEF_PRI_MAP_REG;       /* Offset 30h */
    uint32_t DDRSS_V2A_LPT_R1_PRI_MAP_REG;        /* Offset 34h */
    uint32_t DDRSS_V2A_LPT_R2_PRI_MAP_REG;        /* Offset 38h */
    uint32_t DDRSS_V2A_LPT_R3_PRI_MAP_REG;        /* Offset 3Ch */
    uint8_t  Reserved_bytes_2[12];                /* Reserved bytes */
    uint32_t DDRSS_V2A_HPT_DEF_PRI_MAP_REG;       /* Offset 4Ch */
    uint32_t DDRSS_V2A_HPT_R1_PRI_MAP_REG;        /* Offset 50h */
    uint32_t DDRSS_V2A_HPT_R2_PRI_MAP_REG;        /* Offset 54h */
    uint32_t DDRSS_V2A_HPT_R3_PRI_MAP_REG;        /* Offset 58h */
    uint8_t  Reserved_bytes_3[20];                /* Reserved bytes */
    uint32_t DDRSS_V2A_AERR_LOG1_REG;             /* Offset 70h */
    uint32_t DDRSS_V2A_AERR_LOG2_REG;             /* Offset 74h */
    uint32_t DDRSS_V2A_OERR_LOG_REG;              /* Offset 78h */
    uint8_t  Reserved_bytes_4[4];                 /* Reserved bytes */
    uint32_t DDRSS_V2A_1B_ERR_CNT_REG;            /* Offset 80h */
    uint32_t DDRSS_V2A_1B_ERR_LOG1_REG;           /* Offset 84h */
    uint32_t DDRSS_V2A_1B_ERR_LOG2_REG;           /* Offset 88h */
    uint32_t DDRSS_V2A_2B_ERR_LOG1_REG;           /* Offset 8Ch */
    uint32_t DDRSS_V2A_2B_ERR_LOG2_REG;           /* Offset 90h */
    uint8_t  Reserved_bytes_5[8];                 /* Reserved bytes */
    uint32_t DDRSS_V2A_BUS_TO;                    /* Offset 9Ch */
    uint32_t DDRSS_V2A_INT_RAW_REG;               /* Offset A0h */
    uint32_t DDRSS_V2A_INT_STAT_REG;               /* Offset A4h */
    uint32_t DDRSS_V2A_INT_SET_REG;               /* Offset A8h */
    uint32_t DDRSS_V2A_INT_CLR_REG;               /* Offset ACh */
    uint32_t DDRSS_V2A_EOI_REG;                   /* Offset B0h */
    uint8_t  Reserved_bytes_7[76];                /* Reserved bytes */
    uint32_t DDRSS_PERF_CNT_SEL_REG;              /* Offset 100h */
    uint32_t DDRSS_PERF_CNT1_REG;                 /* Offset 104h */
    uint32_t DDRSS_PERF_CNT2_REG;                 /* Offset 108h */
    uint32_t DDRSS_PERF_CNT3_REG;                 /* Offset 10Ch */
    uint32_t DDRSS_PERF_CNT4_REG;                 /* Offset 110h */
    uint8_t  Reserved_bytes_8[12];                /* Reserved bytes */
    uint32_t DDRSS_ECC_CTRL_REG;                  /* Offset 120h */
    uint32_t DDRSS_ECC_RID_INDX_REG;              /* Offset 124h */
    uint32_t DDRSS_ECC_RID_VAL_REG;               /* Offset 128h */
    uint8_t  Reserved_bytes_9[4];                 /* Reserved bytes */
    uint32_t DDRSS_ECC_R0_STR_ADDR_REG;           /* Offset 130h */
    uint32_t DDRSS_ECC_R0_END_ADDR_REG;           /* Offset 134h */
    uint32_t DDRSS_ECC_R1_STR_ADDR_REG;           /* Offset 138h */
    uint32_t DDRSS_ECC_R1_END_ADDR_REG;           /* Offset 13Ch */
    uint32_t DDRSS_ECC_R2_STR_ADDR_REG;           /* Offset 140h */
    uint32_t DDRSS_ECC_R2_END_ADDR_REG;           /* Offset 144h */
    uint8_t  Reserved_bytes_10[8];                /* Reserved bytes */
    uint32_t DDRSS_ECC_1B_ERR_CNT_REG;            /* Offset 150h */
    uint32_t DDRSS_ECC_1B_ERR_THRSH_REG;          /* Offset 154h */
    uint32_t DDRSS_ECC_1B_ERR_ADR_LOG_REG;        /* Offset 158h */
    uint32_t DDRSS_ECC_1B_ERR_MSK_LOG_REG;        /* Offset 15Ch */
    uint32_t DDRSS_ECC_2B_ERR_ADR_LOG_REG;        /* Offset 160h */
    uint32_t DDRSS_ECC_2B_ERR_MSK_LOG_REG;        /* Offset 164h */
    uint8_t  Reserved_bytes_11[24];               /* Reserved bytes */
    uint32_t DDRSS_PHY_BIST_CTRL_REG;             /* Offset 180h */
} DDRSS_Reg_t; 


/* Ti ticket reference
https:e2e.ti.com/e2eprivate/magna/magna---ep-automotive/f/magna-jacinto-forum/1204475/tda4vm-safety-configuration-registers-for-ddr/4563365#4563365
 */
typedef struct DDRSS_critical_regs {

   uint32_t DDRSS_SS_CTL_REG;             
   uint32_t DDRSS_V2A_CTL_REG;            
   uint32_t DDRSS_V2A_R1_MAT_REG;         
   uint32_t DDRSS_V2A_R2_MAT_REG;         
   uint32_t DDRSS_V2A_R3_MAT_REG;         
   uint32_t DDRSS_V2A_LPT_DEF_PRI_MAP_REG;
   uint32_t DDRSS_V2A_LPT_R1_PRI_MAP_REG; 
   uint32_t DDRSS_V2A_LPT_R2_PRI_MAP_REG; 
   uint32_t DDRSS_V2A_LPT_R3_PRI_MAP_REG; 
   uint32_t DDRSS_V2A_HPT_DEF_PRI_MAP_REG;
   uint32_t DDRSS_V2A_HPT_R1_PRI_MAP_REG; 
   uint32_t DDRSS_V2A_HPT_R2_PRI_MAP_REG; 
   uint32_t DDRSS_V2A_HPT_R3_PRI_MAP_REG; 
   uint32_t DDRSS_V2A_BUS_TO;             
   uint32_t DDRSS_V2A_INT_SET_REG;
   /* There is issue with this register this is not a constant(static) register */       
   /* uint32_t DDRSS_PERF_CNT_SEL_REG; */       
   uint32_t DDRSS_ECC_CTRL_REG;           
   uint32_t DDRSS_ECC_RID_INDX_REG;       
   uint32_t DDRSS_ECC_RID_VAL_REG;        
   uint32_t DDRSS_ECC_R0_STR_ADDR_REG;    
   uint32_t DDRSS_ECC_R0_END_ADDR_REG;    
   uint32_t DDRSS_ECC_R1_STR_ADDR_REG;    
   uint32_t DDRSS_ECC_R1_END_ADDR_REG;    
   uint32_t DDRSS_ECC_R2_STR_ADDR_REG;    
   uint32_t DDRSS_ECC_R2_END_ADDR_REG;    
   uint32_t DDRSS_ECC_1B_ERR_THRSH_REG;   
   uint32_t DDRSS_PHY_BIST_CTRL_REG;      

} DDRSS_critical_regs_t;


/* ===========================================================================
*
* Private functions
*
* ========================================================================= */

static void DDR_safety_readStaticRegs(DDRSS_critical_regs_t* pdata);

/* ===========================================================================
*
*   Private variables
*
* ========================================================================= */
#define CDD_Safety_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
static DDRSS_critical_regs_t gDDR_regs_content;

#define CDD_Safety_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* ===========================================================================
*
*   Global variables
*
* ========================================================================= */
#define CDD_Safety_START_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ========================================================================== */
/*                          Function Implementation                           */
/* ========================================================================== */

/*!
 * \brief   Read DDRSS HW register config function
 *
 * \param   pdata [IN]    pointer to HW reg storage 
 *
 * \retval  None 
 */
static void DDR_safety_readStaticRegs(DDRSS_critical_regs_t* pdata)
{
  /* DD-ID: {A23EB2AC-719B-4c82-AB81-8FD1952D488B}*/
    /* DDRSS */
    DDRSS_Reg_t* ptr = (DDRSS_Reg_t*) SDL_COMPUTE_CLUSTER0_DDR0_0_SS_CFG_BASE;
  

    /* Read safety critical registers for DDRSS */
    pdata->DDRSS_SS_CTL_REG              = ptr->DDRSS_SS_CTL_REG;             
    pdata->DDRSS_V2A_CTL_REG             = ptr->DDRSS_V2A_CTL_REG;            
    pdata->DDRSS_V2A_R1_MAT_REG          = ptr->DDRSS_V2A_R1_MAT_REG;         
    pdata->DDRSS_V2A_R2_MAT_REG          = ptr->DDRSS_V2A_R2_MAT_REG;         
    pdata->DDRSS_V2A_R3_MAT_REG          = ptr->DDRSS_V2A_R3_MAT_REG;         
    pdata->DDRSS_V2A_LPT_DEF_PRI_MAP_REG = ptr->DDRSS_V2A_LPT_DEF_PRI_MAP_REG;
    pdata->DDRSS_V2A_LPT_R1_PRI_MAP_REG  = ptr->DDRSS_V2A_LPT_R1_PRI_MAP_REG; 
    pdata->DDRSS_V2A_LPT_R2_PRI_MAP_REG  = ptr->DDRSS_V2A_LPT_R2_PRI_MAP_REG; 
    pdata->DDRSS_V2A_LPT_R3_PRI_MAP_REG  = ptr->DDRSS_V2A_LPT_R3_PRI_MAP_REG; 
    pdata->DDRSS_V2A_HPT_DEF_PRI_MAP_REG = ptr->DDRSS_V2A_HPT_DEF_PRI_MAP_REG;
    pdata->DDRSS_V2A_HPT_R1_PRI_MAP_REG  = ptr->DDRSS_V2A_HPT_R1_PRI_MAP_REG; 
    pdata->DDRSS_V2A_HPT_R2_PRI_MAP_REG  = ptr->DDRSS_V2A_HPT_R2_PRI_MAP_REG; 
    pdata->DDRSS_V2A_HPT_R3_PRI_MAP_REG  = ptr->DDRSS_V2A_HPT_R3_PRI_MAP_REG; 
    pdata->DDRSS_V2A_BUS_TO              = ptr->DDRSS_V2A_BUS_TO;             
    pdata->DDRSS_V2A_INT_SET_REG         = ptr->DDRSS_V2A_INT_SET_REG;    
    /* There is issue with this register this is not a constant(static) register */    
    /* pdata->DDRSS_PERF_CNT_SEL_REG        = ptr->DDRSS_PERF_CNT_SEL_REG;    */    
    pdata->DDRSS_ECC_CTRL_REG            = ptr->DDRSS_ECC_CTRL_REG;           
    pdata->DDRSS_ECC_RID_INDX_REG        = ptr->DDRSS_ECC_RID_INDX_REG;       
    pdata->DDRSS_ECC_RID_VAL_REG         = ptr->DDRSS_ECC_RID_VAL_REG;        
    pdata->DDRSS_ECC_R0_STR_ADDR_REG     = ptr->DDRSS_ECC_R0_STR_ADDR_REG;    
    pdata->DDRSS_ECC_R0_END_ADDR_REG     = ptr->DDRSS_ECC_R0_END_ADDR_REG;    
    pdata->DDRSS_ECC_R1_STR_ADDR_REG     = ptr->DDRSS_ECC_R1_STR_ADDR_REG;    
    pdata->DDRSS_ECC_R1_END_ADDR_REG     = ptr->DDRSS_ECC_R1_END_ADDR_REG;    
    pdata->DDRSS_ECC_R2_STR_ADDR_REG     = ptr->DDRSS_ECC_R2_STR_ADDR_REG;    
    pdata->DDRSS_ECC_R2_END_ADDR_REG     = ptr->DDRSS_ECC_R2_END_ADDR_REG;    
    pdata->DDRSS_ECC_1B_ERR_THRSH_REG    = ptr->DDRSS_ECC_1B_ERR_THRSH_REG;   
    pdata->DDRSS_PHY_BIST_CTRL_REG       = ptr->DDRSS_PHY_BIST_CTRL_REG;      
 
}

/* ===========================================================================
*
*   Global functions
*
* ========================================================================= */
/*
 * Purpose: Initialize DDR safety and Read the first pass DDR registers 
 * Description: Readback ddr HW registers after initialization 
 * Return Type : void 
 */

void TASK_DDR_safety_init(void)
{
  /* DD-ID: {FAA11F2B-B32A-410a-B616-816D6321ED25}*/
    #if ( SDL_APP_DDR_ENABLED == SDL_APP_ON )
    /* Read DDRSS Static Registers for future compare */
    DDR_safety_readStaticRegs(&gDDR_regs_content);
   
    #endif
}

/*
 * Purpose: DDR safety mainfunction to check registers against first pass values 
 * Description: Will set fault if mismatch 
 * Return Type : void 
 */
void TASK_DDR_safety_MainFunction(void)
{
  /* DD-ID: {4C50FDA7-EE1C-47aa-8E19-691A0916222F}*/
	static DDRSS_critical_regs_t tempDDR_regs_content;
    #if ( SDL_APP_DDR_ENABLED == SDL_APP_ON )
    /* Read DDR Static Registers */
    DDR_safety_readStaticRegs(&tempDDR_regs_content);

    /* Check current read of tempDDR_regs_content matches the intial gDDR_regs_content */
    if (0x00 != memcmp((const void*)&gDDR_regs_content, (const void*)&tempDDR_regs_content, (sizeof(DDRSS_critical_regs_t))))
    {
        #if defined (SDL_APP_DDR_UART_PRINTS_ENABLED)
        appLogPrintf("DDR_safety_readStaticRegs: Compare failure for DDR on line no. %d \n", __LINE__);
        #endif
        Sdl_Application_SetDDRSafetyCriticalConfigFailFlag();
    } 
    else
    {
        #if defined (SDL_APP_DDR_UART_PRINTS_ENABLED)
        appLogPrintf("DDR_safety_readStaticRegs: PASS for DDR\n");
        #endif
    }
    #endif
}

#define CDD_Safety_STOP_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* Nothing past this point */


