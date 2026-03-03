
#ifndef BM_RPRC_H
#define BM_RPRC_H

/**********************************************************************************************************************
*  INCLUDES
**********************************************************************************************************************/
#include <sbl_rprc_parse.h>
#include <sbl_qspi.h>


/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
/* Magic numbers for gforge and sourceforge */
#define MAGIC_NUM_GF          (0xA1ACED00)
#define MAGIC_NUM_SF          (0x55424CBB)


#define MCU1_CPU0_ID 27u

/* Magic number and tokens for RPRC format */
#define RPRC_MAGIC_NUMBER   0x43525052
#define RPRC_RESOURCE       0
#define RPRC_BOOTADDR       5

#define MAX_INPUT_FILES 16
#define META_HDR_MAGIC_STR 0x5254534D /* MSTR in ascii */
#define META_HDR_MAGIC_END 0x444E454D /* MEND in ascii */

#if !defined(OMAPL137_BUILD)
#define SOC_OCMC_RAM1_SIZE          ((uint32_t) 0x80000)     /*OCMC1 512KB*/
#define SOC_OCMC_RAM2_SIZE          ((uint32_t) 0x100000)    /*OCMC2 1MB   */
#define SOC_OCMC_RAM3_SIZE          ((uint32_t) 0x100000)    /*OCMC3  1MB   */

#define MPU_IPU1_ROM                    (CSL_IPU_IPU1_TARGET_REGS)

#define MPU_IPU1_RAM                    (CSL_IPU_IPU1_TARGET_REGS + \
                                            (uint32_t) 0x20000)

#define MPU_IPU2_ROM                    (CSL_IPU_IPU1_ROM_REGS)

#define MPU_IPU2_RAM                    (CSL_IPU_IPU1_ROM_REGS + \
                                            (uint32_t) 0x20000)

#define MPU_DSP1_L2_RAM                 (0x40800000)
#define MPU_DSP1_L1P_CACHE              (0x40E00000)
#define MPU_DSP1_L1D_CACHE              (0x40F00000)
#define MPU_DSP2_L2_RAM                 (0x41000000)
#define MPU_DSP2_L1P_CACHE              (0x41600000)
#define MPU_DSP2_L1D_CACHE              (0x41700000)

#if !defined (SOC_J721E)
#define SOC_DSP_L2_BASE                 (0x800000)
#define SOC_DSP_L1P_BASE                (0xe00000)
#define SOC_DSP_L1D_BASE                (0xf00000)
#endif
#endif

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

typedef struct rprcFileHeader {
    uint32_t magic;
    uint32_t entry;
    uint32_t rsvd_addr;
    uint32_t SectionCount;
    uint32_t version;
} rprcFileHeader_t;

typedef struct rprcSectionHeader {
    uint32_t addr;
    uint32_t rsvd_addr;
    uint32_t size;
    uint32_t rsvdCrc;
    uint32_t rsvd;
} rprcSectionHeader_t;

typedef struct meta_header_start
{
    uint32_t magic_str;
    uint32_t num_files;
    uint32_t dev_id;
    uint32_t rsvd;
}meta_header_start_t;

typedef struct meta_header_core
{
    uint32_t core_id;
    uint32_t image_offset;
}meta_header_core_t;

typedef struct meta_header_end
{
    uint32_t rsvd;
    uint32_t magic_string_end;
}meta_header_end_t;

/* Time stamp */
typedef struct
{
  uint16 year;
  uint8 month;
  uint8 day;
  uint8 hour;
  uint8 minute;
  uint8 second;
} CertDateTimeType_t;
/**********************************************************************************************************************
*  GLOBAL VARIABLES
**********************************************************************************************************************/
sblEntryPoint_t k3xx_evmEntry;


/**********************************************************************************************************************
*  FUNCTIONS
**********************************************************************************************************************/

extern uint32_t SBL_IsSysfwEnc(uint8_t *x509_cert_ptr);
extern int32_t  SBL_FileRead(void  *buff, void *fileptr, uint32_t size);
extern void     SBL_FileSeek(void *fileptr, uint32_t location);
extern void     SBL_DCacheClean(void *addr, uint32_t size);
/* Function Pointer used while reading data from the storage. */
extern uint32_t SBL_authentication(void *addr);

extern Std_ReturnType ParseUTCGeneralizedTime(P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) timeElementPtr,
                                       uint16 timeElementDataLength,
                                       P2VAR(CertDateTimeType_t, AUTOMATIC, AUTOMATIC) parsedTimePtr);

extern Std_ReturnType ConvertDateToUnixTime(P2CONST(CertDateTimeType_t, AUTOMATIC, AUTOMATIC) date, P2VAR(uint32, AUTOMATIC, AUTOMATIC) unixTime);

int32_t BM_MulticoreImageParse(void *srcAddr,
							uint32_t ImageOffset,
							sblEntryPoint_t *pAppEntry,
							uint32_t bootFlag);

void BM_SlaveCoreBoot(cpu_core_id_t core_id, uint32_t freqHz, sblEntryPoint_t *pAppEntry, uint32_t requestCoresFlag);
void* BM_Memcpy(void *dest, const void *source, uint32_t count);     /* PRQA S 5209 */ /* MD_FblHwMpc57xx_5209 */

uint32_t GetDeviceId(void);

/* Function Pointer used while reading data from the storage. */
int32_t (*fp_readData)(void *dstAddr, void *srcAddr,
                        uint32_t length);

/* Function Pointer used while reading data from the storage. */
void  (*fp_seek)(void *srcAddr, uint32_t location);

#endif /* BM_RPRC_H */
						
