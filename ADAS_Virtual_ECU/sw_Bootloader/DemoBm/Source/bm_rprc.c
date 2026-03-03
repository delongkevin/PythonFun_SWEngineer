#define BM_RPRC_C

/**********************************************************************************************************************
*  INCLUDES
**********************************************************************************************************************/

#include "bm_main.h"
#include "fbl_inc.h"
#include "bm_rprc.h"
#include "sbl_soc_cfg.h"
#include "csl_arm_r5.h"

/**********************************************************************************************************************
*  FUNCTIONS
**********************************************************************************************************************/
/*#if defined(SOC_AM65XX) || defined (SOC_J721E) || defined(SOC_J7200) || defined(SOC_J721S2) || defined(SOC_AM64X)*/
#if defined(BUILD_MCU1_0)
extern void SBL_DCacheClean(void *addr, uint32_t size);
#endif
/*#endif*/

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

uint8 SystemTime[15] = {0};
uint32 TimestampCounter = 0;
uint32 SecondCounter = 0;

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

int32_t BM_RprcImageParse(void *srcAddr, uint32_t *entryPoint, int32_t CoreId);
static void BM_BootCore(uint32_t entry, uint32_t CoreID, sblEntryPoint_t *pAppEntry, uint32_t bootFlag);

uint32 getTimeStamp(void);

Std_ReturnType ParseUTCGeneralizedTime(P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) timeElementPtr,
                                       uint16 timeElementDataLength,
                                       P2VAR(CertDateTimeType_t, AUTOMATIC, AUTOMATIC) parsedTimePtr);

Std_ReturnType ConvertDateToUnixTime(P2CONST(CertDateTimeType_t, AUTOMATIC, AUTOMATIC) date, P2VAR(uint32, AUTOMATIC, AUTOMATIC) unixTime);

/***********************************************************************************************************************
 *  LOCAL FUNCTION DEFINITIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  BM_MulticoreImageParse
 **********************************************************************************************************************/
/*! \brief       Called by Bm__OSPIBootImage to parse the appimage file from NOR flash.
 *  \param[in]   srcAddr
 *  \param[in]   imageOffset
 *  \param[in]   pAppEntry
 *  \param[in]   bootFlag
 *  \return      E_PASS - If appImage is successfully parsed and loaded into destination memory
 *               E_FAIL - If appImage is NOT parsed successfully
 **********************************************************************************************************************/
int32_t BM_MulticoreImageParse(void *srcAddr,
                                uint32_t ImageOffset,
                                sblEntryPoint_t *pAppEntry,
                                uint32_t bootFlag)
{
    uint32_t            i;
    uint32_t            entryPoint = 0;
    meta_header_start_t mHdrStr;
    meta_header_core_t  mHdrCore[MAX_INPUT_FILES];
    meta_header_end_t   mHdrEnd;
    int32_t magic_str = META_HDR_MAGIC_STR;
    int32_t retVal    = E_PASS;

    if ((fp_readData == NULL) || (fp_seek == NULL))
    {
        retVal = E_FAIL;
    }
    else
    {
        /* Verify image if possible */
        /*SBL_VerifyMulticoreImage(&srcAddr, &ImageOffset, sbl_scratch_mem, sbl_scratch_sz)*/

        /* Read Meta Header Start and get the Number of Input RPRC Files */
        fp_readData(&mHdrStr, srcAddr, sizeof (meta_header_start_t));
        if (mHdrStr.magic_str != (uint32_t) magic_str)
        {
            /*UART_printf("Invalid magic number in Single image header\r\n");*/
            retVal = E_FAIL;
            while(1);
        }
        else
        {
            if (mHdrStr.dev_id != GetDeviceId())
            {
                /*UART_printf("\nWARNING: Device Id Doesnot match\r\n");*/
            }

            /* Read all the Core offset addresses */
            for (i = (0U); i < mHdrStr.num_files; i++)
            {
                fp_readData(&mHdrCore[i], srcAddr, sizeof (meta_header_core_t));
            }

            /* Add Base Offset address for All core Image start offset */
            for (i = (0U); i < mHdrStr.num_files; i++)
            {
                mHdrCore[i].image_offset += ImageOffset;
            }

            /* Read Meta Header End */
            fp_readData(&mHdrEnd, srcAddr, sizeof (meta_header_end_t));

            /* Now Parse Individual RPRC files */

            for (i = (0U); i < mHdrStr.num_files; i++)
            {
                if (mHdrCore[i].core_id != (0xFFFFFFFFU))
                {
#if defined(SOC_AM64X)
                    /* Do not touch the M4 if reset isolation is enabled */
                    uint32_t mmrMagicRegister;
                    mmrMagicRegister = (*((volatile uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE+CSL_MAIN_CTRL_MMR_CFG0_RST_MAGIC_WORD)));
                    if (mHdrCore[i].core_id == M4F_CPU0_ID && mmrMagicRegister != 0)
                    {
                        continue;
                    }
#endif
                    fp_seek(srcAddr, mHdrCore[i].image_offset);
                    if (BM_RprcImageParse(srcAddr, &entryPoint,
                                       (int32_t)(mHdrCore[i].core_id)) != E_PASS)
                    {
                        /* Error occurred parsing the RPRC file continue to
                         * parsing next
                         * image and skip booting the particular core */
                        /*UART_printf("RPRC parse error\n");*/
                        retVal = E_FAIL;
                        while(1);
                    }
                    else
                    {
                        BM_BootCore(entryPoint, mHdrCore[i].core_id, pAppEntry, bootFlag);
                    }
                }
            }
        }
    }
    return retVal;
}


/***********************************************************************************************************************
 *  BM_BootCore
 **********************************************************************************************************************/
/*! \brief       Called by BM_MulticoreImageParse .
 *  \param[in]   entry
 *  \param[in]   CoreID
 *  \param[in]   pAppEntry
 *  \param[in]   bootFlag
 *  \return
 **********************************************************************************************************************/
void BM_BootCore(uint32_t entry, uint32_t CoreID, sblEntryPoint_t *pAppEntry, uint32_t bootFlag)
{
    switch (CoreID)
    {
        case MCU1_CPU0_ID:
            /* Bootloader cores */
            /*SBL_log(SBL_LOG_MAX, "Setting entry point for core %d @0x%x\n", CoreID, entry);*/
            pAppEntry->CpuEntryPoint[CoreID] = entry;

            /* DO NOT immediately boot these cores, SBL is still running! */

            break;
      
            default:
            /* Wrong CPU ID */
            break;
    }
}


/***********************************************************************************************************************
 *  BM_SlaveCoreBoot
 **********************************************************************************************************************/
/*! \brief       Called by ApplFblBmStartSoftware .
 *  \param[in]   freqHz
 *  \param[in]   pAppEntry
 *  \param[in]   requestCoresFlag
 *  \return
 **********************************************************************************************************************/
void BM_SlaveCoreBoot(cpu_core_id_t core_id, uint32_t freqHz, sblEntryPoint_t *pAppEntry, uint32_t requestCoresFlag)
{
    /*int32_t status = CSL_EFAIL;*/
    /*struct tisci_msg_proc_set_config_req  proc_set_config_req;*/
    /*const sblSlaveCoreInfo_t *sblSlaveCoreInfoPtr = &(sbl_slave_core_info[core_id]);*/

/*#if defined(SBL_SKIP_MCU_RESET) && (defined(SBL_SKIP_BRD_CFG_BOARD) || defined(SBL_SKIP_BRD_CFG_PM) || defined(SBL_SKIP_SYSFW_INIT))*/
    /* Skip copy if R5 app entry point is already 0 */
    if ((core_id == MCU1_CPU0_ID) &&
       (pAppEntry->CpuEntryPoint[core_id]) &&
       (pAppEntry->CpuEntryPoint[core_id] <  (uint32_t)0xFFFFFFFEU))
    {
        /*SBL_log(SBL_LOG_MAX, "Copying first 128 bytes from app to MCU ATCM @ 0x%x for core %d\n", SblAtcmAddr[core_id - MCU1_CPU0_ID], core_id);*/
    	(void)BM_Memcpy(((void *)(0x0U)), (void *)(pAppEntry->CpuEntryPoint[core_id]), 128);

    	CSL_armR5CacheEnableForceWrThru(1);

        /* Branch to start of ATCM */
        ((void(*)(void))0x41010000)();

        /* control never reach here */
        return;
    }
/*#endif*/

}


/***********************************************************************************************************************
 *  BM_RprcImageParse
 **********************************************************************************************************************/
/*! \brief       Called by BM_MulticoreImageParse to parse the rprc image
 *  \param[in]   srcAddr
 *  \param[in]   entryPoint
 *  \param[in]   CoreId
 *  \return      E_PASS - If rprc image is successfully parsed and loaded into destination memory
 *               E_FAIL - If rprc image is NOT parsed successfully
 **********************************************************************************************************************/
int32_t BM_RprcImageParse(void *srcAddr,
                                  uint32_t *entryPoint,
                                  int32_t CoreId)
{
    rprcFileHeader_t    header;
    rprcSectionHeader_t section;
    uint32_t sbl_rsvd_mem_start = (uint32_t)(SBL_SCRATCH_MEM_START);
    uint32_t sbl_rsvd_mem_end = (uint32_t)(((uint32_t)(SBL_SCRATCH_MEM_START)) + ((uint32_t)(SBL_SCRATCH_MEM_SIZE)));
    uint32_t i;
    int32_t retVal = E_PASS;
    uint32_t atcmSize;
    uint32_t btcmSize;

    const uint32_t SocAtcmAddr[] =
    {
#if defined(SOC_AM64X)
    /* Use SoC level address of MCU1_0 ATCM for non-CPU writes to this TCM. Works for CPU copying as well. */
    SBL_MCU1_CPU0_ATCM_BASE_ADDR_SOC,
#else
    SBL_MCU_ATCM_BASE,
#endif
    SBL_MCU1_CPU1_ATCM_BASE_ADDR_SOC,
    SBL_MCU2_CPU0_ATCM_BASE_ADDR_SOC,
    SBL_MCU2_CPU1_ATCM_BASE_ADDR_SOC,
    SBL_MCU3_CPU0_ATCM_BASE_ADDR_SOC,
    SBL_MCU3_CPU1_ATCM_BASE_ADDR_SOC
    };

    const uint32_t SocBtcmAddr[] =
    {
#if defined(SOC_AM64X)
    /* Use SoC level address of MCU1_0 BTCM for non-CPU writes to this TCM. Works for CPU copying as well. */
    SBL_MCU1_CPU0_BTCM_BASE_ADDR_SOC,
#else
    SBL_MCU_BTCM_BASE,
#endif
    SBL_MCU1_CPU1_BTCM_BASE_ADDR_SOC,
    SBL_MCU2_CPU0_BTCM_BASE_ADDR_SOC,
    SBL_MCU2_CPU1_BTCM_BASE_ADDR_SOC,
    SBL_MCU3_CPU0_BTCM_BASE_ADDR_SOC,
    SBL_MCU3_CPU1_BTCM_BASE_ADDR_SOC
    };


    /*read application image header*/
    fp_readData(&header, srcAddr, sizeof (rprcFileHeader_t));

    /*check magic number*/
    if (header.magic != RPRC_MAGIC_NUMBER)
    {
        /*SBL_log(SBL_LOG_ERR, "Invalid magic number in boot image. Expected: %x, received: %x\n", RPRC_MAGIC_NUMBER, header.magic);*/
        retVal = E_FAIL;
    }
    else
    {
        /* Set the Entry Point */
        *entryPoint = header.entry;

        /* Setup CPUs internal memory before using it */
        /*SBL_SetupCoreMem(CoreId);*/

	/*read entrypoint and copy sections to memory*/
        for (i = (0U); i < header.SectionCount; i++)
        {
            fp_readData(&section, srcAddr, sizeof (rprcSectionHeader_t));

            switch (CoreId)
            {
#if defined(SOC_AM64X)
                /* Need address translation to SoC level addresses of MCU1_0 TCMs, when trying to copy to local addresses */
                case MCU1_CPU0_ID:
#endif
                case MCU1_CPU1_ID:
                case MCU2_CPU0_ID:
                case MCU2_CPU1_ID:
                case MCU3_CPU0_ID:
                case MCU3_CPU1_ID:
                    atcmSize = sblAtcmSize();
                    btcmSize = sblBtcmSize();
                    /*Remap TCM address from R5 local to SoC memory map*/
                    if (section.addr < (SBL_MCU_ATCM_BASE + atcmSize))
                    {
                        /* Get offset into ATCM */
                        /*SBL_log(SBL_LOG_MAX, "Translating coreid %d local ATCM addr 0x%x to ", CoreId, section.addr);*/
                        section.addr = section.addr - SBL_MCU_ATCM_BASE;
                        section.addr = SocAtcmAddr[CoreId - MCU1_CPU0_ID] + section.addr;
                        /*SBL_log(SBL_LOG_MAX, "SoC MCU ATCM addr 0x%x\n", section.addr);*/
                    }
                    else if ((section.addr >= SBL_MCU_BTCM_BASE) &&
                             (section.addr < (SBL_MCU_BTCM_BASE + btcmSize)))
                    {
                        /* Get offset into BTCM */
                        /*SBL_log(SBL_LOG_MAX, "Translating coreid %d local BTCM addr 0x%x to ", CoreId, section.addr);*/
                        section.addr = section.addr - SBL_MCU_BTCM_BASE;
                        section.addr = SocBtcmAddr[CoreId - MCU1_CPU0_ID] + section.addr;
                        /*SBL_log(SBL_LOG_MAX, "SoC MCU BTCM addr 0x%x\n", section.addr);*/
                    }
                    else
                    {
                        /* To remove MISRA C error */
                    }
                    break;
                

                default:
                    break;
            }

            if ((fp_readData == SBL_ReadMem) &&
               (((section.addr > sbl_rsvd_mem_start) && (section.addr < sbl_rsvd_mem_end)) ||
                (((section.addr + section.size) > sbl_rsvd_mem_start) && ((section.addr + section.size) < sbl_rsvd_mem_end))))
            {
                /*SBL_log(SBL_LOG_ERR, "Warning!! Section overwrites SBL reserved memory\n");*/
                retVal = E_FAIL;
            }
            else
            {
                /*SBL_log(SBL_LOG_MAX, "Copying 0x%x bytes to 0x%x\n", section.size, section.addr);*/
                fp_readData((void *)(uintptr_t)(section.addr), srcAddr, section.size);
#if defined(BUILD_MCU1_0)
                /* TODO  to be checked, it was commented to go through build process but it was uncommented in the sbl_rprc.c*/
                SBL_DCacheClean((void *)(uintptr_t)(section.addr), section.size);
#endif
            }
        }
    }
    return retVal;
}

/***********************************************************************************************************************
 *  BM_Memcpy
 **********************************************************************************************************************/
/*! \brief       Called by BM_SlaveCoreBoot to copy the data from source to destination
 *  \param[in]   dest
 *  \param[in]   source
 *  \param[in]   count - number of bytes to be copied
 *  \return
 **********************************************************************************************************************/
void* BM_Memcpy(void *dest, const void *source, uint32_t count)     /* PRQA S 5209 */ /* MD_FblHwMpc57xx_5209 */
{
   uint8_t* localDest;
   const uint8_t* localSource;
   uint32_t i;

   /* Initialize variables */
   localDest = (uint8_t*)dest;                /* PRQA S 0316 */ /* MD_FblHwMpc57xx_0316_0326_VoidPtrToObj */
   localSource = (const uint8_t*)source;      /* PRQA S 0316 */ /* MD_FblHwMpc57xx_0316_0326_VoidPtrToObj */

   for (i = 0u; i < count; i++)
   {
      /*if ((i & 0x3Fu) == 0u)
      {
         (void)FblLookForWatchdog();
      }*/
      localDest[i] = localSource[i];
   }

   return dest;
}

/***********************************************************************************************************************
 *  ParseUTCGeneralizedTime
 **********************************************************************************************************************/
/*! \brief       Parse UTC/Generalized Time from ASCII timestamp received from user certificate
 *  \param[in]   timeElementPtr - Pointer to timestamp array received from user certificate
 *               timeElementDataLength - timestamp array length
 *  \param[out]  parsedTimePtr - Pointer to parsed UTC/Generalized Time
 *  \return      retVal - E_OK/E_NOT_OK
 **********************************************************************************************************************/
Std_ReturnType ParseUTCGeneralizedTime(P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) timeElementPtr,
                                       uint16 timeElementDataLength,
                                       P2VAR(CertDateTimeType_t, AUTOMATIC, AUTOMATIC) parsedTimePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) timeElement = timeElementPtr;

  /* ----- Implementation ----------------------------------------------- */
  /* Generally:
  * UTC Formats:
  *    YYMMDDhhmm[ss]Z
  *    YYMMDDhhmm[ss](+|-)hhmm
  *  Generalized Time Formats:
  *    YYYYMMDDHH[MM[SS[.fff]]]
  *    YYYYMMDDHH[MM[SS[.fff]]]Z
  *    YYYYMMDDHH[MM[SS[.fff]]](+|-)HHMM
  */

  /* # Only UTC or Generalized Time with non-optional minutes and seconds are supported,
  *  milliseconds [.fff] and difference to local time (+|-)HHMM is not supported. */

  /* # Check that last sign is a 'Z' 0x5A. */
  if (timeElement[timeElementDataLength - 1u] != 0x5Au)
  {
    retVal = E_NOT_OK;
  }

  if (retVal == E_OK)
  {
    /* # If the element data length is 13, extract the year according to the UTC format. */
    if (timeElementDataLength == 13u)
    {
      /* UTC time with 2 digits Year */
      parsedTimePtr->year = ((uint16)timeElement[0] - 0x30u) * 10u;
      parsedTimePtr->year += (uint16)timeElement[1u] - 0x30u;

      if (parsedTimePtr->year >= 50u)
      {
        parsedTimePtr->year += 1900u;
      }
      else
      {
        parsedTimePtr->year += 2000u;
      }
      timeElement = &(timeElement[2u]);
    }
    /* # If the element data length is 15, extract the year according to the Generalized Time format. */
    else if (timeElementDataLength == 15u)
    {
      /* Generalized time with 4 digits Year */
      parsedTimePtr->year = (((uint16)timeElement[0u] - 0x30u) * 1000u);
      parsedTimePtr->year += ((((uint16)timeElement[1u] - 0x30u) * 100u));
      parsedTimePtr->year += ((((uint16)timeElement[2u] - 0x30u) * 10u));
      parsedTimePtr->year += (((uint16)timeElement[3u] - 0x30u));
      timeElement = &(timeElement[4u]);
    }
    else
    {
      /* invalid time format */
      retVal = E_NOT_OK;
    }
  }

  if (retVal == E_OK)
  {
    /* # Extract the remaining date and time information without differentiating between UTC and
    * Generalized Time format. */
    parsedTimePtr->month = (uint8)((timeElement[0u] - 0x30u) * 10u);
    parsedTimePtr->month += ((uint8)(timeElement[1u] - 0x30u));
    parsedTimePtr->day = (uint8)((timeElement[2u] - 0x30u) * 10u);
    parsedTimePtr->day += ((uint8)(timeElement[3u] - 0x30u));
    parsedTimePtr->hour = (uint8)((timeElement[4u] - 0x30u) * 10u);
    parsedTimePtr->hour += ((uint8)(timeElement[5u] - 0x30u));
    parsedTimePtr->minute = (uint8)((timeElement[6u] - 0x30u) * 10u);
    parsedTimePtr->minute += ((uint8)(timeElement[7u] - 0x30u));
    parsedTimePtr->second = (uint8)((timeElement[8u] - 0x30u) * 10u);
    parsedTimePtr->second += ((uint8)(timeElement[9u] - 0x30u));
  }

  return retVal;
}

/***********************************************************************************************************************
 *  ConvertDateToUnixTime
 **********************************************************************************************************************/
/*! \brief       Convert Date/time received from ParseUTCGeneralizedTime() To Unix Time
 *  \param[in]   date - received from ParseUTCGeneralizedTime()
 *  \param[out]  unixTime - unix/epoch Time
 *  \return      retVal - E_OK/E_NOT_OK
 **********************************************************************************************************************/
Std_ReturnType ConvertDateToUnixTime(
  P2CONST(CertDateTimeType_t, AUTOMATIC, AUTOMATIC) date,
  P2VAR(uint32, AUTOMATIC, AUTOMATIC) unixTime)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  uint32 y;
  uint32 m;
  uint32 d;

  /* ----- Implementation ----------------------------------------------- */
  /* Year */
  y = date->year;
  /* Month of year */
  m = date->month;
  /* Day of month */
  d = date->day;

  /* January and February are counted as months 13 and 14 of the previous year */
  if (m <= 2u)
  {
    m += 12u;
    y -= 1u;
  }

  /* # Convert years to days */
  /* A leap year must be evenly divisible by 4. If the year can also be evenly divided by 100, it is not a leap year, unless
     the year is also evenly divisible by 400. */
  *unixTime = ((365u * y) + (y / 4u) - (y / 100u) + (y / 400u));

  /* # Convert months to days */
  /* This formula takes into account the uneven number of days in the months across a year */
  *unixTime += ((30u * m) + (3u * (m + 1u) / 5u) + d);

  /* # Unix time starts on January 1st, 1970 */
  if (*unixTime < 719561u)
  {
    retVal = E_NOT_OK;
  }
  else
  {
    *unixTime -= 719561u;
    /* # Convert days to seconds */
    *unixTime *= 86400u;
    /* # Add hours, minutes and seconds */
    *unixTime += ((3600u * (uint32)(date->hour)) + (60u * (uint32)(date->minute)) + (uint32)(date->second));
  }

  return retVal;
}

/***********************************************************************************************************************
 *  getTimeStamp
 **********************************************************************************************************************/
/*! \brief       return TimeStamp from secure logging
 *  \param[in]   None
 *  \param[out]  None
 *  \return      TimestampCounter - System timestamp + Seconds elapsed since certificate acceptance
 **********************************************************************************************************************/
uint32 getTimeStamp(void)
{
    Std_ReturnType retVal = E_NOT_OK;
    CertDateTimeType_t UTCGenTime = {0};
    TimestampCounter = 0;

    retVal = ParseUTCGeneralizedTime(&SystemTime[0], 15, &UTCGenTime);
    if(retVal == E_OK)
    {
        retVal = ConvertDateToUnixTime(&UTCGenTime, &TimestampCounter);
        if(retVal == E_OK)
        {
            /* TimeStamp = SystemTimeStamp(notBeforeTime of Certificate) + Elapsed seconds since last IGN ON */
            TimestampCounter += SecondCounter;
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        /* Do Nothing */
    }

    return TimestampCounter;
}
/**
 * \brief  Function to read the device ID
 *
 *
 * \param   None.
 *
 * \return   Return the device id
 *
 **/
/*uint32_t GetDeviceId(void)
{
    uint32_t deviceId = 55U;
    return (deviceId);
}*/

/***********************************************************************************************************************
 *  END OF FILE: BM_RPRC.C
 **********************************************************************************************************************/
