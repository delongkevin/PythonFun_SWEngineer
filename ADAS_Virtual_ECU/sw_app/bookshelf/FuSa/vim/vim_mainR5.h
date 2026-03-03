/********************************************************************
 * Copyright (C) 2017 Texas Instruments Incorporated.
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
 *  Name        : vim.h
*/
#ifndef VIM_REGISTERS_H_
#define VIM_REGISTERS_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 *
 * @ingroup SDL_IP_MODULE
 * @defgroup SDL_VIM_API VIM API
 *
 * The Vectored Interrupt Manager (VIM) aggregates interrupts to a CPU.
 * It is intended for use with a Cortex R5 from ARM in either split or lockstep
 * configuration. The VIM has up to 1024 interrupt inputs per CPU,
 * which may be either level or pulse. Each interrupt has a programmable priority
 * (0- highestthrough 15-lowest). Each interrupt may also be mapped as an
 * IRQ or FIQ (FIQ is also often denoted as Non-Maskable Interrupt, or NMI).
 *
 */
/**
@defgroup SDL_VIM_DATASTRUCT  VIM Data Structures
@ingroup SDL_VIM_API
*/
/**
@defgroup SDL_VIM_FUNCTION  VIM Functions
@ingroup SDL_VIM_API
*/
/**
@defgroup SDL_VIM_MACROS VIM Macros
@ingroup SDL_VIM_API
*/

/**
 *  @addtogroup SDL_VIM_MACROS
    @{
 *
 */

/**
 *  \anchor SDL_vimIntGroups
 *  \name   vim interrupt groups.
 *  @{
 */

/** This enumerator defines the maximum interrupt groups in VIM.*/
#define SDL_VIM_MAX_INTR_GROUPS     (32U)

/** This enumerator defines the number of interrupts per group in VIM. */
#define SDL_VIM_NUM_INTRS_PER_GROUP (32U)
/* @} */

#define SDL_VIM_NUM_MAX_INTRS         (512u)
#define SDL_VIM_NUM_MAX_INTR_GROUP_R5 (SDL_VIM_NUM_MAX_INTRS/SDL_VIM_NUM_INTRS_PER_GROUP)

/**
 * @brief This enumerator defines the possible interrupt types. Each source
 *        interrupt is either an active high level or active high pulse.
 *
 *
 */
typedef uint32_t SDL_VimIntrType;

/**
 *  \anchor SDL_vimIntTypes
 *  \name   vim interrupt types
 *  @{
 */

/** Interrupt source is a level interrupt type */
#define SDL_VIM_INTR_TYPE_LEVEL ((uint32_t)0U)

/** Interrupt source is a pulse interrupt type */
#define SDL_VIM_INTR_TYPE_PULSE ((uint32_t)1U)
/* @} */

/**
 * @brief This enumerator defines the possible output interrupt types. Each
 *        source interrupt can be configured to drive either the IRQ or FIQ
 *        output signal.
 *
 *
 */
typedef uint32_t SDL_VimIntrMap;

/**
 *  \anchor SDL_vimIntMaps
 *  \name   vim interrupt maps
 *  @{
 */

/** Output interrupt is mapped to IRQ  */
#define SDL_VIM_INTR_MAP_IRQ    ((uint32_t)0U)

/** Output interrupt is mapped to FIQ  */
#define SDL_VIM_INTR_MAP_FIQ    ((uint32_t)1U)

/** Output interrupt is mapped to IRQ or FIQ */
#define SDL_VIM_INTR_MAP_ALL    ((uint32_t)2U)
/* @} */

/* @} */

#define SDL_PASS                        ( (int32_t) (0))
#define SDL_EFAIL                       (-(int32_t) (1))

/**************************************************************************
* Hardware Region  : VIM Registers
**************************************************************************/
#define SDL_MAIN_DOMAIN_VIM_BASE_ADDR           (0x0FF80000U)

#define VIM_PRIV_VAL_0x0F    0x0F
#define VIM_PRIV_VAL_0x0B    0x0B
#define VIM_INTR_MAP_VAL_0   0x0
#define VIM_INTR_TYPE_VAL_0  0x0
#define VIM_INTR_EN_VAL_1    0x1

/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct Safety_arm_vim_cfg_tag {
    uint32_t intrNum;
    uint32_t pri;
    uint32_t intrMap;
    uint32_t intrType;
    uint32_t intrEnClr;
    uint32_t intrEnSet;
    uint32_t vecAddr;
} Safety_arm_vim_cfg __attribute__((__packed__));

typedef struct {
    volatile uint32_t RAW;                       /* Raw Status/Set Register */
    volatile uint32_t STS;                       /* Interrupt Enable Status/Clear Register */
    volatile uint32_t INTR_EN_SET;               /* Interrupt Enable Set Register */
    volatile uint32_t INTR_EN_CLR;               /* Interrupt Enabled Clear Register */
    volatile uint32_t IRQSTS;                    /* IRQ Interrupt Enable Status/Clear Register */
    volatile uint32_t FIQSTS;                    /* FIQ Interrupt Enable Status/Clear Register */
    volatile uint32_t INTMAP;                    /* Interrupt Map Register */
    volatile uint32_t INTTYPE;                   /* Interrupt Type Register */
} SDL_vimRegs_GRP;


typedef struct {
    volatile uint32_t INT;                       /* Interrupt Priority Register */
} SDL_vimRegs_PRI;


typedef struct {
    volatile uint32_t INT;                       /* Interrupt Vector Register */
} SDL_vimRegs_VEC;


typedef struct {
    volatile uint32_t PID;                       /* Revision Register */
    volatile uint32_t INFO;                      /* Info Register */
    volatile uint32_t PRIIRQ;                    /* Prioritized IRQ Register */
    volatile uint32_t PRIFIQ;                    /* Prioritized FIQ Register */
    volatile uint32_t IRQGSTS;                   /* IRQ Group Status Register */
    volatile uint32_t FIQGSTS;                   /* FIQ Group Status Register */
    volatile uint32_t IRQVEC;                    /* IRQ Vector Address Register */
    volatile uint32_t FIQVEC;                    /* FIQ Vector Address Register */
    volatile uint32_t ACTIRQ;                    /* ACtive IRQ Register */
    volatile uint32_t ACTFIQ;                    /* ACtive FIQ Register */
    volatile uint8_t  Resv_48[8];
    volatile uint32_t DEDVEC;                    /* DED Vector Address Register */
    volatile uint8_t  Resv_1024[972];
    SDL_vimRegs_GRP GRP[32];
    volatile uint8_t  Resv_4096[2048];
    SDL_vimRegs_PRI PRI[1024];
    SDL_vimRegs_VEC VEC[1024];
} SDL_vimRegs;

/**
 *  \addtogroup SDL_VIM_DATASTRUCT
 *  @{
 */

/**
 * @brief This structure defines the group registers identified for VIM static
 * registers
 *
 *
 */
typedef struct {
    volatile uint32_t INTR_EN_SET;               /** Interrupt Enable Set Register */
    volatile uint32_t INTR_EN_CLR;               /** Interrupt Enabled Clear Register */
    volatile uint32_t INTMAP;                    /** Interrupt Map Register */
    volatile uint32_t INTTYPE;                   /** Interrupt Type Register */
} SDL_vimStaticRegs_GRP;

/**
  * @brief This structure defines the static register groups identified for VIM
 *
 *
 */
typedef struct {
    volatile uint32_t PID;                       /** Revision Register */
    volatile uint32_t INFO;                      /** Info Register */
    volatile uint32_t DEDVEC;                    /** DED Vector Address Register */
} Safety_vimStaticRegs;

/**************************************************************************
* Register Macros
**************************************************************************/

#define SDL_VIM_PID                                                            (0x00000000U)
#define SDL_VIM_INFO                                                           (0x00000004U)
#define SDL_VIM_PRIIRQ                                                         (0x00000008U)
#define SDL_VIM_PRIFIQ                                                         (0x0000000CU)
#define SDL_VIM_IRQGSTS                                                        (0x00000010U)
#define SDL_VIM_FIQGSTS                                                        (0x00000014U)
#define SDL_VIM_IRQVEC                                                         (0x00000018U)
#define SDL_VIM_FIQVEC                                                         (0x0000001CU)
#define SDL_VIM_ACTIRQ                                                         (0x00000020U)
#define SDL_VIM_ACTFIQ                                                         (0x00000024U)
#define SDL_VIM_DEDVEC                                                         (0x00000030U)
#define SDL_VIM_GRP_RAW(GRP)                                                   (0x00000400U+((GRP)*0x20U))
#define SDL_VIM_GRP_STS(GRP)                                                   (0x00000404U+((GRP)*0x20U))
#define SDL_VIM_GRP_INTR_EN_SET(GRP)                                           (0x00000408U+((GRP)*0x20U))
#define SDL_VIM_GRP_INTR_EN_CLR(GRP)                                           (0x0000040CU+((GRP)*0x20U))
#define SDL_VIM_GRP_IRQSTS(GRP)                                                (0x00000410U+((GRP)*0x20U))
#define SDL_VIM_GRP_FIQSTS(GRP)                                                (0x00000414U+((GRP)*0x20U))
#define SDL_VIM_GRP_INTMAP(GRP)                                                (0x00000418U+((GRP)*0x20U))
#define SDL_VIM_GRP_INTTYPE(GRP)                                               (0x0000041CU+((GRP)*0x20U))
#define SDL_VIM_PRI_INT(PRI)                                                   (0x00001000U+((PRI)*0x4U))
#define SDL_VIM_VEC_INT(VEC)                                                   (0x00002000U+((VEC)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* RAW */

#define SDL_VIM_GRP_RAW_STS_MASK                                               (0xFFFFFFFFU)
#define SDL_VIM_GRP_RAW_STS_SHIFT                                              (0x00000000U)
#define SDL_VIM_GRP_RAW_STS_RESETVAL                                           (0x00000000U)
#define SDL_VIM_GRP_RAW_STS_MAX                                                (0xFFFFFFFFU)

#define SDL_VIM_GRP_RAW_RESETVAL                                               (0x00000000U)

/* STS */

#define SDL_VIM_GRP_STS_MSK_MASK                                               (0xFFFFFFFFU)
#define SDL_VIM_GRP_STS_MSK_SHIFT                                              (0x00000000U)
#define SDL_VIM_GRP_STS_MSK_RESETVAL                                           (0x00000000U)
#define SDL_VIM_GRP_STS_MSK_MAX                                                (0xFFFFFFFFU)

#define SDL_VIM_GRP_STS_RESETVAL                                               (0x00000000U)

/* INTR_EN_SET */

#define SDL_VIM_GRP_INTR_EN_SET_MSK_MASK                                       (0xFFFFFFFFU)
#define SDL_VIM_GRP_INTR_EN_SET_MSK_SHIFT                                      (0x00000000U)
#define SDL_VIM_GRP_INTR_EN_SET_MSK_RESETVAL                                   (0x00000000U)
#define SDL_VIM_GRP_INTR_EN_SET_MSK_MAX                                        (0xFFFFFFFFU)

#define SDL_VIM_GRP_INTR_EN_SET_RESETVAL                                       (0x00000000U)

/* INTR_EN_CLR */

#define SDL_VIM_GRP_INTR_EN_CLR_MSK_MASK                                       (0xFFFFFFFFU)
#define SDL_VIM_GRP_INTR_EN_CLR_MSK_SHIFT                                      (0x00000000U)
#define SDL_VIM_GRP_INTR_EN_CLR_MSK_RESETVAL                                   (0x00000000U)
#define SDL_VIM_GRP_INTR_EN_CLR_MSK_MAX                                        (0xFFFFFFFFU)

#define SDL_VIM_GRP_INTR_EN_CLR_RESETVAL                                       (0x00000000U)

/* IRQSTS */

#define SDL_VIM_GRP_IRQSTS_MSK_MASK                                            (0xFFFFFFFFU)
#define SDL_VIM_GRP_IRQSTS_MSK_SHIFT                                           (0x00000000U)
#define SDL_VIM_GRP_IRQSTS_MSK_RESETVAL                                        (0x00000000U)
#define SDL_VIM_GRP_IRQSTS_MSK_MAX                                             (0xFFFFFFFFU)

#define SDL_VIM_GRP_IRQSTS_RESETVAL                                            (0x00000000U)

/* FIQSTS */

#define SDL_VIM_GRP_FIQSTS_MSK_MASK                                            (0xFFFFFFFFU)
#define SDL_VIM_GRP_FIQSTS_MSK_SHIFT                                           (0x00000000U)
#define SDL_VIM_GRP_FIQSTS_MSK_RESETVAL                                        (0x00000000U)
#define SDL_VIM_GRP_FIQSTS_MSK_MAX                                             (0xFFFFFFFFU)

#define SDL_VIM_GRP_FIQSTS_RESETVAL                                            (0x00000000U)

/* INTMAP */

#define SDL_VIM_GRP_INTMAP_MSK_MASK                                            (0xFFFFFFFFU)
#define SDL_VIM_GRP_INTMAP_MSK_SHIFT                                           (0x00000000U)
#define SDL_VIM_GRP_INTMAP_MSK_RESETVAL                                        (0x00000000U)
#define SDL_VIM_GRP_INTMAP_MSK_MAX                                             (0xFFFFFFFFU)

#define SDL_VIM_GRP_INTMAP_RESETVAL                                            (0x00000000U)

/* INTTYPE */

#define SDL_VIM_GRP_INTTYPE_MSK_MASK                                           (0xFFFFFFFFU)
#define SDL_VIM_GRP_INTTYPE_MSK_SHIFT                                          (0x00000000U)
#define SDL_VIM_GRP_INTTYPE_MSK_RESETVAL                                       (0x00000000U)
#define SDL_VIM_GRP_INTTYPE_MSK_MAX                                            (0xFFFFFFFFU)

#define SDL_VIM_GRP_INTTYPE_RESETVAL                                           (0x00000000U)

/* INT */

#define SDL_VIM_PRI_INT_VAL_MASK                                               (0x0000000FU)
#define SDL_VIM_PRI_INT_VAL_SHIFT                                              (0x00000000U)
#define SDL_VIM_PRI_INT_VAL_RESETVAL                                           (0x0000000FU)
#define SDL_VIM_PRI_INT_VAL_MAX                                                (0x0000000FU)

#define SDL_VIM_PRI_INT_RESETVAL                                               (0x0000000FU)

/* INT */

#define SDL_VIM_VEC_INT_VAL_MASK                                               (0xFFFFFFFCU)
#define SDL_VIM_VEC_INT_VAL_SHIFT                                              (0x00000002U)
#define SDL_VIM_VEC_INT_VAL_RESETVAL                                           (0x00000000U)
#define SDL_VIM_VEC_INT_VAL_MAX                                                (0x3FFFFFFFU)

#define SDL_VIM_VEC_INT_RESETVAL                                               (0x00000000U)

/* PID */

#define SDL_VIM_PID_MINOR_MASK                                                 (0x0000003FU)
#define SDL_VIM_PID_MINOR_SHIFT                                                (0x00000000U)
#define SDL_VIM_PID_MINOR_RESETVAL                                             (0x00000001U)
#define SDL_VIM_PID_MINOR_MAX                                                  (0x0000003FU)

#define SDL_VIM_PID_CUSTOM_MASK                                                (0x000000C0U)
#define SDL_VIM_PID_CUSTOM_SHIFT                                               (0x00000006U)
#define SDL_VIM_PID_CUSTOM_RESETVAL                                            (0x00000000U)
#define SDL_VIM_PID_CUSTOM_MAX                                                 (0x00000003U)

#define SDL_VIM_PID_MAJOR_MASK                                                 (0x00000700U)
#define SDL_VIM_PID_MAJOR_SHIFT                                                (0x00000008U)
#define SDL_VIM_PID_MAJOR_RESETVAL                                             (0x00000000U)
#define SDL_VIM_PID_MAJOR_MAX                                                  (0x00000007U)

#define SDL_VIM_PID_RTL_MASK                                                   (0x0000F800U)
#define SDL_VIM_PID_RTL_SHIFT                                                  (0x0000000BU)
#define SDL_VIM_PID_RTL_RESETVAL                                               (0x00000000U)
#define SDL_VIM_PID_RTL_MAX                                                    (0x0000001FU)

#define SDL_VIM_PID_FUNC_MASK                                                  (0x0FFF0000U)
#define SDL_VIM_PID_FUNC_SHIFT                                                 (0x00000010U)
#define SDL_VIM_PID_FUNC_RESETVAL                                              (0x00000090U)
#define SDL_VIM_PID_FUNC_MAX                                                   (0x00000FFFU)

#define SDL_VIM_PID_BU_MASK                                                    (0x30000000U)
#define SDL_VIM_PID_BU_SHIFT                                                   (0x0000001CU)
#define SDL_VIM_PID_BU_RESETVAL                                                (0x00000002U)
#define SDL_VIM_PID_BU_MAX                                                     (0x00000003U)

#define SDL_VIM_PID_SCHEME_MASK                                                (0xC0000000U)
#define SDL_VIM_PID_SCHEME_SHIFT                                               (0x0000001EU)
#define SDL_VIM_PID_SCHEME_RESETVAL                                            (0x00000001U)
#define SDL_VIM_PID_SCHEME_MAX                                                 (0x00000003U)

#define SDL_VIM_PID_RESETVAL                                                   (0x60900001U)

/* INFO */

#define SDL_VIM_INFO_INTERRUPTS_MASK                                           (0x000007FFU)
#define SDL_VIM_INFO_INTERRUPTS_SHIFT                                          (0x00000000U)
#define SDL_VIM_INFO_INTERRUPTS_RESETVAL                                       (0x00000400U)
#define SDL_VIM_INFO_INTERRUPTS_MAX                                            (0x000007FFU)

#define SDL_VIM_INFO_RESETVAL                                                  (0x00000400U)

/* PRIIRQ */

#define SDL_VIM_PRIIRQ_VALID_MASK                                              (0x80000000U)
#define SDL_VIM_PRIIRQ_VALID_SHIFT                                             (0x0000001FU)
#define SDL_VIM_PRIIRQ_VALID_RESETVAL                                          (0x00000000U)
#define SDL_VIM_PRIIRQ_VALID_MAX                                               (0x00000001U)

#define SDL_VIM_PRIIRQ_VALID_VAL_TRUE                                          (0x1U)
#define SDL_VIM_PRIIRQ_VALID_VAL_FALSE                                         (0x0U)

#define SDL_VIM_PRIIRQ_PRI_MASK                                                (0x000F0000U)
#define SDL_VIM_PRIIRQ_PRI_SHIFT                                               (0x00000010U)
#define SDL_VIM_PRIIRQ_PRI_RESETVAL                                            (0x00000000U)
#define SDL_VIM_PRIIRQ_PRI_MAX                                                 (0x0000000FU)

#define SDL_VIM_PRIIRQ_NUM_MASK                                                (0x000003FFU)
#define SDL_VIM_PRIIRQ_NUM_SHIFT                                               (0x00000000U)
#define SDL_VIM_PRIIRQ_NUM_RESETVAL                                            (0x00000000U)
#define SDL_VIM_PRIIRQ_NUM_MAX                                                 (0x000003FFU)

#define SDL_VIM_PRIIRQ_RESETVAL                                                (0x00000000U)

/* PRIFIQ */

#define SDL_VIM_PRIFIQ_VALID_MASK                                              (0x80000000U)
#define SDL_VIM_PRIFIQ_VALID_SHIFT                                             (0x0000001FU)
#define SDL_VIM_PRIFIQ_VALID_RESETVAL                                          (0x00000000U)
#define SDL_VIM_PRIFIQ_VALID_MAX                                               (0x00000001U)

#define SDL_VIM_PRIFIQ_VALID_VAL_TRUE                                          (0x1U)
#define SDL_VIM_PRIFIQ_VALID_VAL_FALSE                                         (0x0U)

#define SDL_VIM_PRIFIQ_PRI_MASK                                                (0x000F0000U)
#define SDL_VIM_PRIFIQ_PRI_SHIFT                                               (0x00000010U)
#define SDL_VIM_PRIFIQ_PRI_RESETVAL                                            (0x00000000U)
#define SDL_VIM_PRIFIQ_PRI_MAX                                                 (0x0000000FU)

#define SDL_VIM_PRIFIQ_NUM_MASK                                                (0x000003FFU)
#define SDL_VIM_PRIFIQ_NUM_SHIFT                                               (0x00000000U)
#define SDL_VIM_PRIFIQ_NUM_RESETVAL                                            (0x00000000U)
#define SDL_VIM_PRIFIQ_NUM_MAX                                                 (0x000003FFU)

#define SDL_VIM_PRIFIQ_RESETVAL                                                (0x00000000U)

/* IRQGSTS */

#define SDL_VIM_IRQGSTS_STS_MASK                                               (0xFFFFFFFFU)
#define SDL_VIM_IRQGSTS_STS_SHIFT                                              (0x00000000U)
#define SDL_VIM_IRQGSTS_STS_RESETVAL                                           (0x00000000U)
#define SDL_VIM_IRQGSTS_STS_MAX                                                (0xFFFFFFFFU)

#define SDL_VIM_IRQGSTS_RESETVAL                                               (0x00000000U)

/* FIQGSTS */

#define SDL_VIM_FIQGSTS_STS_MASK                                               (0xFFFFFFFFU)
#define SDL_VIM_FIQGSTS_STS_SHIFT                                              (0x00000000U)
#define SDL_VIM_FIQGSTS_STS_RESETVAL                                           (0x00000000U)
#define SDL_VIM_FIQGSTS_STS_MAX                                                (0xFFFFFFFFU)

#define SDL_VIM_FIQGSTS_RESETVAL                                               (0x00000000U)

/* IRQVEC */

#define SDL_VIM_IRQVEC_ADDR_MASK                                               (0xFFFFFFFCU)
#define SDL_VIM_IRQVEC_ADDR_SHIFT                                              (0x00000002U)
#define SDL_VIM_IRQVEC_ADDR_RESETVAL                                           (0x00000000U)
#define SDL_VIM_IRQVEC_ADDR_MAX                                                (0x3FFFFFFFU)

#define SDL_VIM_IRQVEC_RESETVAL                                                (0x00000000U)

/* FIQVEC */

#define SDL_VIM_FIQVEC_ADDR_MASK                                               (0xFFFFFFFCU)
#define SDL_VIM_FIQVEC_ADDR_SHIFT                                              (0x00000002U)
#define SDL_VIM_FIQVEC_ADDR_RESETVAL                                           (0x00000000U)
#define SDL_VIM_FIQVEC_ADDR_MAX                                                (0x3FFFFFFFU)

#define SDL_VIM_FIQVEC_RESETVAL                                                (0x00000000U)

/* ACTIRQ */

#define SDL_VIM_ACTIRQ_VALID_MASK                                              (0x80000000U)
#define SDL_VIM_ACTIRQ_VALID_SHIFT                                             (0x0000001FU)
#define SDL_VIM_ACTIRQ_VALID_RESETVAL                                          (0x00000000U)
#define SDL_VIM_ACTIRQ_VALID_MAX                                               (0x00000001U)

#define SDL_VIM_ACTIRQ_VALID_VAL_TRUE                                          (0x1U)
#define SDL_VIM_ACTIRQ_VALID_VAL_FALSE                                         (0x0U)

#define SDL_VIM_ACTIRQ_PRI_MASK                                                (0x000F0000U)
#define SDL_VIM_ACTIRQ_PRI_SHIFT                                               (0x00000010U)
#define SDL_VIM_ACTIRQ_PRI_RESETVAL                                            (0x00000000U)
#define SDL_VIM_ACTIRQ_PRI_MAX                                                 (0x0000000FU)

#define SDL_VIM_ACTIRQ_NUM_MASK                                                (0x000003FFU)
#define SDL_VIM_ACTIRQ_NUM_SHIFT                                               (0x00000000U)
#define SDL_VIM_ACTIRQ_NUM_RESETVAL                                            (0x00000000U)
#define SDL_VIM_ACTIRQ_NUM_MAX                                                 (0x000003FFU)

#define SDL_VIM_ACTIRQ_RESETVAL                                                (0x00000000U)

/* ACTFIQ */

#define SDL_VIM_ACTFIQ_VALID_MASK                                              (0x80000000U)
#define SDL_VIM_ACTFIQ_VALID_SHIFT                                             (0x0000001FU)
#define SDL_VIM_ACTFIQ_VALID_RESETVAL                                          (0x00000000U)
#define SDL_VIM_ACTFIQ_VALID_MAX                                               (0x00000001U)

#define SDL_VIM_ACTFIQ_VALID_VAL_TRUE                                          (0x1U)
#define SDL_VIM_ACTFIQ_VALID_VAL_FALSE                                         (0x0U)

#define SDL_VIM_ACTFIQ_PRI_MASK                                                (0x000F0000U)
#define SDL_VIM_ACTFIQ_PRI_SHIFT                                               (0x00000010U)
#define SDL_VIM_ACTFIQ_PRI_RESETVAL                                            (0x00000000U)
#define SDL_VIM_ACTFIQ_PRI_MAX                                                 (0x0000000FU)

#define SDL_VIM_ACTFIQ_NUM_MASK                                                (0x000003FFU)
#define SDL_VIM_ACTFIQ_NUM_SHIFT                                               (0x00000000U)
#define SDL_VIM_ACTFIQ_NUM_RESETVAL                                            (0x00000000U)
#define SDL_VIM_ACTFIQ_NUM_MAX                                                 (0x000003FFU)

#define SDL_VIM_ACTFIQ_RESETVAL                                                (0x00000000U)

/* DEDVEC */

#define SDL_VIM_DEDVEC_ADDR_MASK                                               (0xFFFFFFFCU)
#define SDL_VIM_DEDVEC_ADDR_SHIFT                                              (0x00000002U)
#define SDL_VIM_DEDVEC_ADDR_RESETVAL                                           (0x00000000U)
#define SDL_VIM_DEDVEC_ADDR_MAX                                                (0x3FFFFFFFU)

#define SDL_VIM_DEDVEC_RESETVAL                                                (0x00000000U)


/**
 *  \brief   This macro reads a 32-bit value from a hardware register
 *           and returns the value.
 *
 *  \param   p      Address of the memory mapped hardware register.
 *
 *  \return  Unsigned 32-bit value read from a register.
 */
#define SDL_REG32_RD(p)         (SDL_REG32_RD_RAW((volatile uint32_t *) (p)))

/**
 *  \brief   This macro writes a 32-bit value to a hardware register.
 *
 *  \param   p       Address of the memory mapped hardware register.
 *  \param   v       Unsigned 32-bit value which has to be written to the
 *                   register.
 */
#define SDL_REG32_WR(p, v)      (SDL_REG32_WR_RAW( \
                                    (volatile uint32_t *) (p), (uint32_t) (v)))

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief   This function reads a 32-bit value from a hardware register
 *           and returns the value.
 *
 *  \param   p      Address of the memory mapped hardware register.
 *
 *  \return  Unsigned 32-bit value read from a register.
 */
static inline uint32_t SDL_REG32_RD_RAW(volatile const uint32_t * const p);
static inline uint32_t SDL_REG32_RD_RAW(volatile const uint32_t * const p)
{
    return (*p);
}

/**
 *  \brief   This function writes a 32-bit value to a hardware register.
 *
 *  \param   p      Address of the memory mapped hardware register.
 *  \param   v      Unsigned 32-bit value which has to be written to the
 *                  register.
 */
static inline void SDL_REG32_WR_RAW(volatile uint32_t * const p, uint32_t v);
static inline void SDL_REG32_WR_RAW(volatile uint32_t * const p, uint32_t v)
{
    *p = v;
    return;
}

/**
 * @function name - Safety_VIM_VerifyStaticRegs
 * @param - Safety_vimStaticRegs *arm_vim_static_data
 * @return - int32_t
 * @description - Verify Static registers
 */
int32_t Safety_VIM_VerifyStaticRegs( const Safety_vimStaticRegs *arm_vim_static_data);
/**
 * @function name - Safety_VIM_verifyCfgIntr
 * @param - Safety_arm_vim_cfg * arm_vim_cfg_data
 * @return - int32_t
 * @description - Verify Interrupt config
 */
int32_t Safety_VIM_verifyCfgIntr( const Safety_arm_vim_cfg *arm_vim_cfg_data);
/**
 * @function name - Safety_VIM_ReadCfgIntr
 * @param - Interrupt num
 * @return - int32_t
 * @description - Read VIm config for the interrupt
 */
int32_t Safety_VIM_ReadCfgIntr( uint32_t intrNum);

/**
* @fn      VIM_VIMDEDInterruptHandler
* @brief   DED Interrupt handler
* @param   None
* @return   None
*/
void VIM_VIMDEDInterruptHandler(void);
/**
 * @function name - Safety_VIM_setDedVectorAddr
 * @param dedVectorAddr - DED function
 * @return - void
 * @description - Set DED function for VIM
 */
void Safety_VIM_setDedVectorAddr( uint32_t dedVectorAddr );


#ifdef __cplusplus
}
#endif
#endif
