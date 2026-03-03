/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                Please note, that this file contains example configuration used by the
 *                MICROSAR BSW. This code may influence the behaviour of the MICROSAR BSW
 *                in principle. Therefore, great care must be taken to verify
 *                the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples respectively
 *                implementation proposals. With regard to the fact that these functions
 *                are meant for demonstration purposes only, the liability of Vector Informatik
 *                shall be expressly excluded in cases of ordinary negligence,
 *                to the extent admissible by law or statute.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  _MemMap.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This File is a template for the MemMap.h
 *                This file has to be extended with the memory section defined for all BSW modules
 *                which are used.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2007-08-01  Jk                    Initial creation
 *  01.01.00  2007-12-14  Jk                    Component specific defines filtering added
 *  01.01.02  2008-11-04  Jk                    Component specific defines filtering added
 *  01.01.03  2008-12-17  Ht                    Improve list of components  (Tp_AsrTpCan,Tp_AsrTpFr,DrvMcu,DrvIcu added)
 *  01.01.04  2009-04-27  Ht                    improve list of components  (Cp_XcpOnCanAsr, Il_AsrIpduM, If_VxFblDcm,
 *                                              If_VxFblVpm_Volvo_ab, DrvFls added)
 *  01.01.05  2009-04-24  Msr                   Renamed J1939_AsrBase as TpJ1939_AsrBase
 *  01.01.06  2009-06-03  Ht                    Improve list of components (Adc, Dio, Gpt, Pwm, Spi, Wdg, Fls, Port, Fim)
 *  01.02.00  2009-08-01  Ht                    Improve list of components (Fee_30_Inst2, Can, ...Sub)
 *                                              Support filtering for RTE
 *  01.02.01  2009-08-18  HH                    replaced C++ comment by C comment
 *  01.02.02  2009-09-02  Lo                    add external Flash driver support
 *  01.02.03  2009-09-12  Lo                    add DrvFls_Mcs12xFslftm01ExtVx
 *                        Ht                    Improve list of components (CanTrcv_30_Tja1040dio,
 *                                                Eth, EthTrcv, EthIf, SoAd, TcpIp, EthSM)
 *  01.03.00  2009-10-30  Ht                    support R8: change EthTrcv to EthTrcv_30_Canoeemu
 *                                              support EthTrcv_30_Dp83848
 *                                              change CanTrcv_30_Xdio to CanTrcv_30___Your_Trcv__
 *                                              change CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1041
 *                                              change name FrTrcv to FrTrcv_30_Tja1080dio
 *                        Lo                    add Cp_AsrXcp
 *                        Ht                    add Cp_XcpOnFrAsr
 *  01.03.01  2010-01-13  Ht                    support SysService_AsrCal
 *  01.03.02  2010-02-15  Ht                    support SysService_SswRcs_Daimler, SysService_Tls, Tp_Http,
 *                                                      SysService_Dns, SysService_Json, DrvTrans_GenericLindioAsr
 *                        Lo                    add Diag_AsrDem for all OEMs
 *                                              rename internal variables and filter methods
 *  01.04.00  2010-03-04  Ht                    change name FrTrcv_30_Tja1080dio to FrTrcv_30_Tja1080
 *  01.04.01  2010-03-10  Ht                    support DrvTrans_GenericFrAsr, DrvTrans_As8223FrspiAsr, DrvEep and If_AsrIfEa
 *  01.04.02  2010-04-07  Lo                    change IfFee to real components and add If_AsrIfWdV85xNec01Sub
 *  01.04.03  2010-06-11  Ht                    add CanTrcv_30_Tja1043
 *                        Lo                    add Il_AsrIpduMEbBmwSub
 *  01.04.04  2010-08-24  Ht                    add CanTrcv_30_Tle62512G, DrvEep_XAt25128EAsr, Tp_AsrTpFrEbBmwSub
 *  01.05.00  2010-08-24  Ht                    support R10:
 *                                              change LinTrcv_30_Tle7259dio to LinTrcv_30_Tle7259
 *  01.05.01  2010-10-14  Ht                    add VStdLib, SysService_SswScc, SysService_IpBase, SysService_Crypto
 *  01.05.02  2010-10-20  Ht                    support comments for Package Merge Tool
 *  01.05.03  2010-11-03  Ht                    add SysService_E2eLibTttechSub, SysService_E2ePwTttechSub
 *  01.05.04  2010-11-16  Ht                    add SysService_Exi, DrvTrans_Int6400EthAsr, Cdd_AsrCdd_Fiat, Diag_AsrDem_Fiat
 *  01.05.05  2010-12-17  Ht                    add SysService_AsrSchM, DrvEep_XXStubAsr, DrvIcu_Tms570Tinhet01ExtVx
 *                                                  DrvWd_XTle4278gEAsr, DrvWd_XXStubAsr
 *  01.05.06  2011-02-17  Ht                    add DrvEed, SysService_AsrBswM
 *  01.05.07  2011-03-04  Ht                    add DrvTrans_Tja1055CandioAsr
 *                                              rename CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1040
 *                                              add SysService_XmlEngine
 *  01.06.00  2011-03-15  Ht                    support ASR4.0
 *                                              add Ccl_Asr4ComM, Ccl_Asr4SmCan, Nm_Asr4NmIf, Nm_AsrNmDirOsek
 *  01.06.01  2011-04-15  Ht                    add Diag_AsrDcm_<OEM>
 *  01.06.02  2011-06-17  Ht                    correct Diag_AsrDcm_<OEM>
 *                                              add Monitoring_AsrDlt and Monitoring_GenericMeasurement
 *  01.06.03  2011-09-20  Ht                    add DrvTrans_Tja1145CanSpiAsr, DrvTrans_E52013CanspiAsr, DrvFls_XXStubAsr,
 *                                              If_AsrIfFeeV85xNec05Sub, If_AsrIfFeeV85xNec06Sub, If_AsrIfFeeV85xNec07Sub
 *                                              SysService_AsrWdMTttechSub and If_AsrIfWdTttechSub
 *  01.06.04  2011-11-22  Ht                    add If_AsrIfFeeTiSub,
 *                                              ESCAN00054718: add Cdd_AsrCdd
 *  01.06.05  2011-12-09  Ht                    add Tp_IpV4, Tp_IpV6
 *  01.06.06  2011-12-14  Ht                    add Monitoring_RuntimeMeasurement
 *  01.06.07  2012-01-03  Ht                    add DrvI2c, SysService_Asr4BswM
 *  01.06.08  2012-01-31  Ht                    add DrvTrans_Ar7000EthAsr, DrvTrans_GenericEthmiiAsr
 *  01.06.09  2012-03-06  Ht                    add If_AsrIfFeeMb9df126Fuji01Sub,
 *                                              Infineon_Tc1767Inf01Sub, Infineon_Tc178xInf01Sub, Infineon_Tc1797Inf01Sub, Infineon_Tc1797Inf02Sub
 *  01.06.10  2012-03-13  Ht                    add Gw_AsrPduRCfg5, Il_AsrComCfg5, Il_AsrIpduMCfg5, Cdd_AsrCddCfg5,
 *                                              Tp_Asr4TpCan, Diag_Asr4Dcm, Diag_Asr4Dem
 *  01.06.11  2012-03-20  Ht                    add Cp_AsrCcp, Cp_XcpOnTcpIpAsr
 *  01.07.00  2012-07-26  Ht                    ESCAN00059365: [AUTOSAR4, compiler warning]: Wrong define name in #undef statement causes re-definition warning
 *                                              add Nm_Asr4NmCan, Nm_Asr4NmFr, Infineon_Xc2000Inf01Sub, Ccl_Asr4ComMCfg5, SysService_Asr4BswMCfg5, SysService_Asr4EcuM, SysService_AsrRamTst,
 *                                                  Ccl_Asr4SmLin
 *            2012-09-04  Ht                    add support for ASR specification 4.0 R3
 *  01.07.01  2012-10-23  Seu                   add SysService_XmlSecurity
 *  01.07.02  2013-01-10  Seu                   MISRA deviation comments added
 *  01.08.00  2013-03-01  Seu    ESCAN00065501  AR4-325: Add support for Post-build RAM memory section
 *            2013-04-12  Seu    ESCAN00066614  Add the deviation for violation of MISRA rule 19.6
 *  01.09.00  2013-12-10  Seu    ESCAN00072537  Add *_NOCACHE_* memory sections for variables
 *            2013-12-16  Seu                   MISRA compliance: usage of character "'" removed, typos corrected
 *  01.10.00  2016-09-27  Seu                   FEATC-317: FEAT-2002: CommonAsr__Common: Support 64 Bit Signal Types for COM according to ASR 4.2.2
 *  01.11.00  2017-07-05  Seu    ESCAN00095756  FEAT-2455: Support ASR4.2 compatible MemMap for MCALs
 *            2017-08-01  Seu    ESCAN00096129  MEMMAP_SW_MINOR_VERSION / MEM_SW_MINOR_VERSION is not correct
 *  01.12.00  2018-10-17  visdfe ESCAN00095695  Add support for Os_CoreGen7 within _MemMap.h (Include of Os_MemMap.h)
 *                               TASK-78775     Change MemMap_Common.h to Template
 *  01.13.00  2021-05-06  virmfr HALBE-3985     CommonAsr_MemMap shall include Common_MemMap generated compatibility header
 *  02.00.00  2021-06-09  visto  HALBE-4594     Create a branch for >=R27 Features
 *  02.01.00  2021-08-25  virmfr HALBE-4526     MemMap_Common.h removed
 *  02.01.01  2021-09-07  virmfr HALBE-5304     MemMapIncludesList removed
 *  02.02.00  2022-08.18  virmfr HALBE-7504     Interchange include order of MemMap_Common.h and MemMap_Compatibility.h
 *            2022-08.18  virmfr                ASR3 defines removed
 *********************************************************************************************************************/

/* PRQA S 0841 MEMMAP_0841_TAG */ /* MD_MSR_19.6 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

 /* PRQA S 0883 1 */ /* MD_MemMap_19.15 */
#undef MEMMAP_VENDOR_ID /* PRQA S 0841 */ /* MD_MSR_19.6 */

#define MEMMAP_VENDOR_ID        (30u)

/* AUTOSAR Software Specification Version Information */

# undef MEMMAP_AR_RELEASE_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_AR_RELEASE_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_AR_RELEASE_REVISION_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

/* AUTOSAR release 4.0 R3 */
# define MEMMAP_AR_RELEASE_MAJOR_VERSION       (4u)
# define MEMMAP_AR_RELEASE_MINOR_VERSION       (0u)
# define MEMMAP_AR_RELEASE_REVISION_VERSION    (3u)

/* compatiblity to older versions */
# undef MEM_AR_RELEASE_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_AR_RELEASE_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_AR_RELEASE_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

# define MEM_AR_RELEASE_MAJOR_VERSION          MEMMAP_AR_RELEASE_MAJOR_VERSION
# define MEM_AR_RELEASE_MINOR_VERSION          MEMMAP_AR_RELEASE_MINOR_VERSION
# define MEM_AR_RELEASE_PATCH_VERSION          MEMMAP_AR_RELEASE_REVISION_VERSION


# undef MEMMAP_SW_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_SW_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_SW_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

# define MEMMAP_SW_MAJOR_VERSION     (2u)
# define MEMMAP_SW_MINOR_VERSION     (2u)
# define MEMMAP_SW_PATCH_VERSION     (0u)

/* compatiblity to older versions */
# undef MEM_SW_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_SW_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_SW_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

# define MEM_SW_MAJOR_VERSION        MEMMAP_SW_MAJOR_VERSION
# define MEM_SW_MINOR_VERSION        MEMMAP_SW_MINOR_VERSION
# define MEM_SW_PATCH_VERSION        MEMMAP_SW_PATCH_VERSION

#define MEMMAP_ERROR

/* Package Merger: Start Section MemMapModuleList */



/**********************************************************************************************************************
 *  CanSM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef CANSM_START_SEC_CODE
# undef CANSM_START_SEC_CODE
# define START_SEC_CODE                                               /* mapped to default code section */
#endif

#ifdef CANSM_STOP_SEC_CODE
# undef CANSM_STOP_SEC_CODE
# define STOP_SEC_CODE                                                /* default code stop section */
#endif


#ifdef CANSM_START_SEC_APPL_CODE
# undef CANSM_START_SEC_APPL_CODE
# define START_SEC_CODE                                               /* mapped to default code section */
#endif

#ifdef CANSM_STOP_SEC_APPL_CODE
# undef CANSM_STOP_SEC_APPL_CODE
# define STOP_SEC_CODE                                                /* default code stop section */
#endif
 


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */


#ifdef CANSM_START_SEC_CONST_8BIT
# undef CANSM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif

#ifdef CANSM_STOP_SEC_CONST_8BIT
# undef CANSM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST                                               /* default const stop section */
#endif

#ifdef CANSM_START_SEC_CONST_32BIT
# undef CANSM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif

#ifdef CANSM_STOP_SEC_CONST_32BIT
# undef CANSM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif


#ifdef CANSM_START_SEC_CONST_UNSPECIFIED
# undef CANSM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef CANSM_STOP_SEC_CONST_UNSPECIFIED
# undef CANSM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/* FAST CONST sections */
#ifdef CANSM_START_SEC_CONST_FAST_8BIT
# undef CANSM_START_SEC_CONST_FAST_8BIT
# define START_SEC_CONST_FAST_8BIT
#endif

#ifdef CANSM_STOP_SEC_CONST_FAST_8BIT
# undef CANSM_STOP_SEC_CONST_FAST_8BIT
# define STOP_SEC_CONST                                               /* default const stop section */
#endif

#ifdef CANSM_START_SEC_CONST_FAST_32BIT
# undef CANSM_START_SEC_CONST_FAST_32BIT
# define START_SEC_CONST_FAST_32BIT
#endif

#ifdef CANSM_STOP_SEC_CONST_FAST_32BIT
# undef CANSM_STOP_SEC_CONST_FAST_32BIT
# define STOP_SEC_CONST
#endif


#ifdef CANSM_START_SEC_CONST_FAST_UNSPECIFIED
# undef CANSM_START_SEC_CONST_FAST_UNSPECIFIED
# define START_SEC_CONST_FAST_UNSPECIFIED
#endif

#ifdef CANSM_STOP_SEC_CONST_FAST_UNSPECIFIED
# undef CANSM_STOP_SEC_CONST_FAST_UNSPECIFIED
# define STOP_SEC_CONST
#endif



/* Postbuild CFG CONST sections */



/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */


/* VAR NOINIT sections */

#ifdef CANSM_START_SEC_VAR_NOINIT_8BIT
# undef CANSM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef CANSM_STOP_SEC_VAR_NOINIT_8BIT
# undef CANSM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif


#ifdef CANSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef CANSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef CANSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef CANSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef CANSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef CANSM_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif

#ifdef CANSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef CANSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

/* VAR FAST INIT sections */

/* VAR FAST NOINIT sections */

#ifdef CANSM_START_SEC_VAR_FAST_NOINIT_8BIT
# undef CANSM_START_SEC_VAR_FAST_NOINIT_8BIT
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif

#ifdef CANSM_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef CANSM_STOP_SEC_VAR_FAST_NOINIT_8BIT
# define STOP_SEC_VAR
#endif


#ifdef CANSM_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef CANSM_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif

#ifdef CANSM_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef CANSM_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR FAST ZERO INIT sections */

#ifdef CANSM_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef CANSM_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif

#ifdef CANSM_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef CANSM_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif







/**********************************************************************************************************************
 *  CanSM END
 *********************************************************************************************************************/

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 702 */

/*        STARTSINGLE_OF_MULTIPLE_COMMENT      */


/**********************************************************************************************************************
 *  Can START  DRVCAN_MPC5700MCANASR
 *********************************************************************************************************************/

#if defined (CAN_30_MCAN_REMAP_PB_SECTIONS)        /* PRQA S 0883 */ /* Appears only while testing */
/* for none PB variants the code will be mapped to standard sections, so the generated and static code can ignore the variant handling */
# if defined (CAN_30_MCAN_START_SEC_PBCFG)
#  undef CAN_30_MCAN_START_SEC_PBCFG                /* PRQA S 0841 */ /* MD_MSR_19.6 */
#  define CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED
# endif
# if defined (CAN_30_MCAN_STOP_SEC_PBCFG)
#  undef CAN_30_MCAN_STOP_SEC_PBCFG                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#  define CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED
# endif

# if defined (CAN_30_MCAN_START_SEC_VAR_PBCFG)
#  undef CAN_30_MCAN_START_SEC_VAR_PBCFG            /* PRQA S 0841 */ /* MD_MSR_19.6 */
#  define CAN_30_MCAN_START_SEC_VAR_NOINIT_UNSPECIFIED
# endif
# if defined (CAN_30_MCAN_STOP_SEC_VAR_PBCFG)
#  undef CAN_30_MCAN_STOP_SEC_VAR_PBCFG             /* PRQA S 0841 */ /* MD_MSR_19.6 */
#  define CAN_30_MCAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# endif
#endif

/*******  CODE sections **********************************************************************************************/

#ifdef CAN_30_MCAN_START_SEC_CODE                             /* CAN code */
# undef CAN_30_MCAN_START_SEC_CODE                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                               /* mapped to default code section */
#endif
#ifdef CAN_30_MCAN_STOP_SEC_CODE
# undef CAN_30_MCAN_STOP_SEC_CODE                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

#ifdef CAN_30_MCAN_START_SEC_STATIC_CODE                      /* CAN static code */
# undef CAN_30_MCAN_START_SEC_STATIC_CODE                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                               /* mapped to default code section */
#endif
#ifdef CAN_30_MCAN_STOP_SEC_STATIC_CODE
# undef CAN_30_MCAN_STOP_SEC_STATIC_CODE                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

#ifdef CAN_30_MCAN_START_SEC_CODE_APPL                        /* Appl code (generic precopy)*/
# undef CAN_30_MCAN_START_SEC_CODE_APPL                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                               /* mapped to default code section */
#endif
#ifdef CAN_30_MCAN_STOP_SEC_CODE_APPL
# undef CAN_30_MCAN_STOP_SEC_CODE_APPL                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CAN_30_MCAN_START_SEC_CONST_8BIT                       /* Const 8bit */
# undef CAN_30_MCAN_START_SEC_CONST_8BIT                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT                         /* mapped to default const 8bit section */
#endif
#ifdef CAN_30_MCAN_STOP_SEC_CONST_8BIT
# undef CAN_30_MCAN_STOP_SEC_CONST_8BIT                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef CAN_30_MCAN_START_SEC_CONST_16BIT                      /* Const 16bit */
# undef CAN_30_MCAN_START_SEC_CONST_16BIT                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT                        /* mapped to default const 16bit section */
#endif
#ifdef CAN_30_MCAN_STOP_SEC_CONST_16BIT
# undef CAN_30_MCAN_STOP_SEC_CONST_16BIT                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef CAN_30_MCAN_START_SEC_CONST_32BIT                      /* Const 32bit */
# undef CAN_30_MCAN_START_SEC_CONST_32BIT                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT                        /* mapped to default const 32bit section */
#endif
#ifdef CAN_30_MCAN_STOP_SEC_CONST_32BIT
# undef CAN_30_MCAN_STOP_SEC_CONST_32BIT                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED                /* Const unspecified */
# undef CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED                  /* mapped to default const unspec section */
#endif
#ifdef CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED
# undef CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/* FAST CONST sections */
/* unused */

/* Postbuild CFG CONST sections */

/* Root table for postbuild data (not relevant for CFG5 AutoSar4.0.3) */
#ifdef CAN_30_MCAN_START_SEC_PBCFG_ROOT                       /* Generated Postbuild Root Table */
# undef CAN_30_MCAN_START_SEC_PBCFG_ROOT                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG                        /* mapped to default const postbuild section */
#endif
#ifdef CAN_30_MCAN_STOP_SEC_PBCFG_ROOT
# undef CAN_30_MCAN_STOP_SEC_PBCFG_ROOT                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef CAN_30_MCAN_START_SEC_PBCFG                            /* Generated Postbuild */
# undef CAN_30_MCAN_START_SEC_PBCFG                             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG                        /* mapped to default const postbuild section */
#endif
#ifdef CAN_30_MCAN_STOP_SEC_PBCFG
# undef CAN_30_MCAN_STOP_SEC_PBCFG                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef CAN_30_MCAN_START_SEC_VAR_INIT_UNSPECIFIED             /* init RAM*/
# undef CAN_30_MCAN_START_SEC_VAR_INIT_UNSPECIFIED              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED               /* mapped to default init var section */
#endif
#ifdef CAN_30_MCAN_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef CAN_30_MCAN_STOP_SEC_VAR_INIT_UNSPECIFIED               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef CAN_30_MCAN_START_SEC_VAR_NOINIT_UNSPECIFIED           /* uninit RAM*/
# undef CAN_30_MCAN_START_SEC_VAR_NOINIT_UNSPECIFIED            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED             /* mapped to default uninit var section */
#endif
#ifdef CAN_30_MCAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef CAN_30_MCAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CAN_30_MCAN_START_SEC_VAR_NOINIT_8BIT                  /* uninit 8bit RAM*/
# undef CAN_30_MCAN_START_SEC_VAR_NOINIT_8BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED             /* mapped to default uninit var section */
#endif
#ifdef CAN_30_MCAN_STOP_SEC_VAR_NOINIT_8BIT
# undef CAN_30_MCAN_STOP_SEC_VAR_NOINIT_8BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CAN_30_MCAN_START_SEC_VAR_NOINIT_16BIT                  /* uninit 16bit RAM*/
# undef CAN_30_MCAN_START_SEC_VAR_NOINIT_16BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED             /* mapped to default uninit var section */
#endif
#ifdef CAN_30_MCAN_STOP_SEC_VAR_NOINIT_16BIT
# undef CAN_30_MCAN_STOP_SEC_VAR_NOINIT_16BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CAN_30_MCAN_START_SEC_VAR_NOINIT_32BIT                  /* uninit 32bit RAM*/
# undef CAN_30_MCAN_START_SEC_VAR_NOINIT_32BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED             /* mapped to default uninit var section */
#endif
#ifdef CAN_30_MCAN_STOP_SEC_VAR_NOINIT_32BIT
# undef CAN_30_MCAN_STOP_SEC_VAR_NOINIT_32BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif



/* VAR PBCFG sections */

#ifdef CAN_30_MCAN_START_SEC_VAR_PBCFG           /* Generated Postbuild RAM*/
# undef CAN_30_MCAN_START_SEC_VAR_PBCFG            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG             /* mapped to default uninit var section */
#endif
#ifdef CAN_30_MCAN_STOP_SEC_VAR_PBCFG
# undef CAN_30_MCAN_STOP_SEC_VAR_PBCFG             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
/* unused */


/* VAR FAST INIT sections */
/* unused */


/* VAR FAST NOINIT sections */
/* unused */

/* VAR FAST ZERO INIT sections */
/* unused */



/**********************************************************************************************************************
 *  Can END    DRVCAN_MPC5700MCANASR
 *********************************************************************************************************************/

/*  STOPSINGLE_OF_MULTIPLE_COMMENT  */
/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 702 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 702 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 702 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 702 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 702 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 702 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 702 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 702 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 702 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 702 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 702 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 702 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 702 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 702 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 702 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 702 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 702 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 702 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 702 */



/**********************************************************************************************************************
 *  EEP_30_XXI2C01 START
 *********************************************************************************************************************/

/******** CODE sections **********************************************************************************************/

#ifdef EEP_30_XXI2C01_START_SEC_CODE
# undef EEP_30_XXI2C01_START_SEC_CODE /* PRQA S 841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#ifdef EEP_30_XXI2C01_STOP_SEC_CODE
# undef EEP_30_XXI2C01_STOP_SEC_CODE /* PRQA S 841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef EEP_30_XXI2C01_START_SEC_CONST_32
# undef EEP_30_XXI2C01_START_SEC_CONST_32 /* PRQA S 841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32
#endif
#ifdef EEP_30_XXI2C01_STOP_SEC_CONST_32
# undef EEP_30_XXI2C01_STOP_SEC_CONST_32 /* PRQA S 841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef EEP_30_XXI2C01_START_SEC_CONST_UNSPECIFIED
# undef EEP_30_XXI2C01_START_SEC_CONST_UNSPECIFIED /* PRQA S 841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef EEP_30_XXI2C01_STOP_SEC_CONST_UNSPECIFIED
# undef EEP_30_XXI2C01_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef EEP_30_XXI2C01_START_SEC_PBCFG_ROOT
# undef EEP_30_XXI2C01_START_SEC_PBCFG_ROOT /* PRQA S 841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef EEP_30_XXI2C01_STOP_SEC_PBCFG_ROOT
# undef EEP_30_XXI2C01_STOP_SEC_PBCFG_ROOT /* PRQA S 841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef EEP_30_XXI2C01_INST2_START_SEC_PBCFG_ROOT
# undef EEP_30_XXI2C01_INST2_START_SEC_PBCFG_ROOT /* PRQA S 841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef EEP_30_XXI2C01_INST2_STOP_SEC_PBCFG_ROOT
# undef EEP_30_XXI2C01_INST2_STOP_SEC_PBCFG_ROOT /* PRQA S 841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef EEP_30_XXI2C01_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef EEP_30_XXI2C01_START_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef EEP_30_XXI2C01_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef EEP_30_XXI2C01_STOP_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef EEP_30_XXI2C01_START_SEC_VAR_INIT_UNSPECIFIED
# undef EEP_30_XXI2C01_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef EEP_30_XXI2C01_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef EEP_30_XXI2C01_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  EEP_30_XXI2C01 END
 *********************************************************************************************************************/


/***********************************************************************************************************************
 *  EEP_30_VMEMACCM START 
 **********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef EEP_30_VMEMACCM_START_SEC_CODE
# undef EEP_30_VMEMACCM_START_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#ifdef EEP_30_VMEMACCM_STOP_SEC_CODE
# undef EEP_30_VMEMACCM_STOP_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */


/*******  VAR sections  **********************************************************************************************/

/* VAR NO_INIT sections */

#ifdef EEP_30_VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED
# undef EEP_30_VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef EEP_30_VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef EEP_30_VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/***********************************************************************************************************************
 *  EEP_30_VMEMACCM END
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  FLS_30_VMEMACCM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(FLS_30_VMEMACCM_START_SEC_CODE)
# undef FLS_30_VMEMACCM_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(FLS_30_VMEMACCM_STOP_SEC_CODE)
# undef FLS_30_VMEMACCM_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */
#ifdef FLS_30_VMEMACCM_START_SEC_CONST_UNSPECIFIED
# undef FLS_30_VMEMACCM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FLS_30_VMEMACCM_STOP_SEC_CONST_UNSPECIFIED
# undef FLS_30_VMEMACCM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/


#ifdef FLS_30_VMEMACCM_START_SEC_VAR_NO_INIT_RAM_BUFFER
/* Non-standard MemMap section for internal write buffer, which will be forwarded to the vMemAccM if RAM alignment
 * feature is enabled. Depending on hardware restrictions, this buffer might have to be aligned to prevent unaligned
 * memory access exceptions. */
# undef FLS_30_VMEMACCM_START_SEC_VAR_NO_INIT_RAM_BUFFER /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_64 
#endif
#ifdef FLS_30_VMEMACCM_STOP_SEC_VAR_NO_INIT_RAM_BUFFER
# undef FLS_30_VMEMACCM_STOP_SEC_VAR_NO_INIT_RAM_BUFFER /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef FLS_30_VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED
# undef FLS_30_VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef FLS_30_VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FLS_30_VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(FLS_30_VMEMACCM_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef FLS_30_VMEMACCM_START_SEC_VAR_NOINIT_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED        /* mapped to default variable section */
#endif
#if defined(FLS_30_VMEMACCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef FLS_30_VMEMACCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR          /* default variable stop section */
#endif
/**********************************************************************************************************************
 *  FLS_30_VMEMACCM END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  I2C START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(I2C_START_SEC_CODE)
# undef I2C_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(I2C_STOP_SEC_CODE)
# undef I2C_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(I2C_START_SEC_CODE_ISR)
# undef I2C_START_SEC_CODE_ISR      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE_ISR         /* mapped to default code section */
#endif
#if defined(I2C_STOP_SEC_CODE_ISR)
# undef I2C_STOP_SEC_CODE_ISR       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE          /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(I2C_START_SEC_CONST_UNSPECIFIED)
# undef I2C_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(I2C_STOP_SEC_CONST_UNSPECIFIED)
# undef I2C_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#if defined(I2C_START_SEC_PBCFG_ROOT)
# undef I2C_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#if defined(I2C_STOP_SEC_PBCFG_ROOT)
# undef I2C_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#if defined(I2C_START_SEC_PBCFG_GLOBALROOT)
# undef I2C_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#if defined(I2C_STOP_SEC_PBCFG_GLOBALROOT)
# undef I2C_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(I2C_START_SEC_PBCFG)
# undef I2C_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#if defined(I2C_STOP_SEC_PBCFG)
# undef I2C_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(I2C_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef I2C_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(I2C_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef I2C_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(I2C_START_SEC_VAR_INIT_UNSPECIFIED)
# undef I2C_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(I2C_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  I2C END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VMEM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VMEM_30_BLOCKING_START_SEC_CODE)
# undef VMEM_30_BLOCKING_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef  */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VMEM_30_BLOCKING_STOP_SEC_CODE)
# undef VMEM_30_BLOCKING_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef  */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */
#if defined VMEM_30_BLOCKING_START_SEC_CONST_UNSPECIFIED
# undef VMEM_30_BLOCKING_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef  */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_BLOCKING_STOP_SEC_CONST_UNSPECIFIED
# undef VMEM_30_BLOCKING_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef  */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_BLOCKING_START_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_BLOCKING_START_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_BLOCKING_STOP_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_BLOCKING_STOP_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_BLOCKING_START_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_BLOCKING_START_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined VMEM_30_BLOCKING_STOP_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_BLOCKING_STOP_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */
/* ... none ... */

/* VAR ZERO INIT sections */
#ifdef VMEM_30_BLOCKING_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef VMEM_30_BLOCKING_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef  */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef VMEM_30_BLOCKING_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef VMEM_30_BLOCKING_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef  */
# define STOP_SEC_VAR
#endif


/* VAR INIT sections */
/* ... none ... */

/**********************************************************************************************************************
 *  VMEM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VMEM_30_EEP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VMEM_30_EEP_START_SEC_CODE)
# undef VMEM_30_EEP_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VMEM_30_EEP_STOP_SEC_CODE)
# undef VMEM_30_EEP_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */
#if defined VMEM_30_EEP_START_SEC_CONST_UNSPECIFIED
# undef VMEM_30_EEP_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_EEP_STOP_SEC_CONST_UNSPECIFIED
# undef VMEM_30_EEP_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_EEP_START_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_EEP_START_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_EEP_STOP_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_EEP_STOP_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_EEP_START_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_EEP_START_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined VMEM_30_EEP_STOP_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_EEP_STOP_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

/* VAR ZERO INIT sections */
#if defined VMEM_30_EEP_START_SEC_VAR_ZERO_INIT_8BIT
# undef VMEM_30_EEP_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined VMEM_30_EEP_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef VMEM_30_EEP_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR INIT sections */

/**********************************************************************************************************************
 *  VMEM_30_EEP END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VMEM_30_FLS START
 *********************************************************************************************************************/


/*******  CODE sections **********************************************************************************************/

#if defined(VMEM_30_FLS_START_SEC_CODE)
# undef VMEM_30_FLS_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VMEM_30_FLS_STOP_SEC_CODE)
# undef VMEM_30_FLS_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */
#ifdef VMEM_30_FLS_START_SEC_CONST_UNSPECIFIED
# undef VMEM_30_FLS_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef VMEM_30_FLS_STOP_SEC_CONST_UNSPECIFIED
# undef VMEM_30_FLS_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_FLS_START_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_FLS_START_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_FLS_STOP_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_FLS_STOP_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_FLS_START_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_FLS_START_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined VMEM_30_FLS_STOP_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_FLS_STOP_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

/* VAR ZERO INIT sections */
#ifdef VMEM_30_FLS_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef VMEM_30_FLS_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef VMEM_30_FLS_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef VMEM_30_FLS_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  VMEM_30_FLS END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VMEM_30_MMFLASHRO START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VMEM_30_MMFLASHRO_START_SEC_CODE)
# undef VMEM_30_MMFLASHRO_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VMEM_30_MMFLASHRO_STOP_SEC_CODE)
# undef VMEM_30_MMFLASHRO_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */
#if defined VMEM_30_MMFLASHRO_START_SEC_CONST_UNSPECIFIED
# undef VMEM_30_MMFLASHRO_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_MMFLASHRO_STOP_SEC_CONST_UNSPECIFIED
# undef VMEM_30_MMFLASHRO_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_MMFLASHRO_START_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_MMFLASHRO_START_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_MMFLASHRO_STOP_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_MMFLASHRO_STOP_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_MMFLASHRO_START_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_MMFLASHRO_START_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined VMEM_30_MMFLASHRO_STOP_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_MMFLASHRO_STOP_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

/* VAR ZERO INIT sections  */

/* VAR INIT sections */
#if defined VMEM_30_MMFLASHRO_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef VMEM_30_MMFLASHRO_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined VMEM_30_MMFLASHRO_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef VMEM_30_MMFLASHRO_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  VMEM_30_MMFLASHRO END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VMEM_30_XXRAM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VMEM_30_XXRAM_START_SEC_CODE)
# undef VMEM_30_XXRAM_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VMEM_30_XXRAM_STOP_SEC_CODE)
# undef VMEM_30_XXRAM_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */
#if defined VMEM_30_XXRAM_START_SEC_CONST_UNSPECIFIED
# undef VMEM_30_XXRAM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_XXRAM_STOP_SEC_CONST_UNSPECIFIED
# undef VMEM_30_XXRAM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_XXRAM_START_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_XXRAM_START_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_XXRAM_STOP_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_XXRAM_STOP_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_XXRAM_START_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_XXRAM_START_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined VMEM_30_XXRAM_STOP_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_XXRAM_STOP_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

/* VAR ZERO INIT sections */
#if defined VMEM_30_XXRAM_START_SEC_VAR_ZERO_INIT_8BIT
# undef VMEM_30_XXRAM_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined VMEM_30_XXRAM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef VMEM_30_XXRAM_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR INIT sections */
#if defined VMEM_30_XXRAM_START_SEC_VAR_INIT_32
# undef VMEM_30_XXRAM_START_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32
#endif
#if defined VMEM_30_XXRAM_STOP_SEC_VAR_INIT_32
# undef VMEM_30_XXRAM_STOP_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#include "vMem_30_XXRam_CfgMemMap.h"
/**********************************************************************************************************************
 *  VMEM_30_XXRAM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * VMEM_30_VXSPI_NAND START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef VMEM_30_VXSPI_NAND_START_SEC_CODE
# undef VMEM_30_VXSPI_NAND_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#ifdef VMEM_30_VXSPI_NAND_STOP_SEC_CODE
# undef VMEM_30_VXSPI_NAND_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */
#ifdef VMEM_30_VXSPI_NAND_START_SEC_CONST_UNSPECIFIED
# undef VMEM_30_VXSPI_NAND_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef VMEM_30_VXSPI_NAND_STOP_SEC_CONST_UNSPECIFIED
# undef VMEM_30_VXSPI_NAND_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef VMEM_30_VXSPI_NAND_START_SEC_CONST_8BIT
# undef VMEM_30_VXSPI_NAND_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef VMEM_30_VXSPI_NAND_STOP_SEC_CONST_8BIT
# undef VMEM_30_VXSPI_NAND_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef VMEM_30_VXSPI_NAND_START_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_VXSPI_NAND_START_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef VMEM_30_VXSPI_NAND_STOP_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_VXSPI_NAND_STOP_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef VMEM_30_VXSPI_NAND_START_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_VXSPI_NAND_START_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef VMEM_30_VXSPI_NAND_STOP_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_VXSPI_NAND_STOP_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */
#ifdef VMEM_30_VXSPI_NAND_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef VMEM_30_VXSPI_NAND_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef VMEM_30_VXSPI_NAND_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef VMEM_30_VXSPI_NAND_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VMEM_30_VXSPI_NAND_START_SEC_VAR_NOINIT_8BIT
# undef VMEM_30_VXSPI_NAND_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef VMEM_30_VXSPI_NAND_STOP_SEC_VAR_NOINIT_8BIT
# undef VMEM_30_VXSPI_NAND_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
#ifdef VMEM_30_VXSPI_NAND_START_SEC_VAR_ZERO_INIT_8BIT
# undef VMEM_30_VXSPI_NAND_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef VMEM_30_VXSPI_NAND_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef VMEM_30_VXSPI_NAND_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR INIT sections */

/**********************************************************************************************************************
 *  VMEM_30_VXSPI_NAND END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CANTRCV_30_GENERICCAN START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(CANTRCV_30_GENERICCAN_START_SEC_CODE)
# undef CANTRCV_30_GENERICCAN_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_CODE)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_CODE_FAST)
# undef CANTRCV_30_GENERICCAN_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_FAST    /* mapped to default fast code section */
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_CODE_FAST)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CODE_FAST  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_CODE_ISR)
# undef CANTRCV_30_GENERICCAN_START_SEC_CODE_ISR  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_ISR     /* mapped to default ISR code section */
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_CODE_ISR)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CODE_ISR   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(CANTRCV_30_GENERICCAN_START_SEC_CONST_8BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT     /* mapped to default const 8bit section */
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_CONST_8BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_CONST_16BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_CONST_16BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_CONST_32BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_CONST_32BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#if defined(CANTRCV_30_GENERICCAN_START_SEC_CONST_FAST_8BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_8BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_CONST_FAST_8BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_CONST_FAST_16BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_16BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_CONST_FAST_16BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_CONST_FAST_32BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_32BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_CONST_FAST_32BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_CONST_FAST_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_START_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_CONST_FAST_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#if defined(CANTRCV_30_GENERICCAN_START_SEC_PBCFG)
# undef CANTRCV_30_GENERICCAN_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_PBCFG)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_PBCFG)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_PBCFG)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CANTRCV_30_GENERICCAN END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */

/**********************************************************************************************************************
 *  CANTRCV_30_TJA1043 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(CANTRCV_30_TJA1043_START_SEC_CODE)
# undef CANTRCV_30_TJA1043_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CODE)
# undef CANTRCV_30_TJA1043_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_CODE_FAST)
# undef CANTRCV_30_TJA1043_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_FAST    /* mapped to default fast code section */
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CODE_FAST)
# undef CANTRCV_30_TJA1043_STOP_SEC_CODE_FAST  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_CODE_ISR)
# undef CANTRCV_30_TJA1043_START_SEC_CODE_ISR  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_ISR     /* mapped to default ISR code section */
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CODE_ISR)
# undef CANTRCV_30_TJA1043_STOP_SEC_CODE_ISR   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_CONST_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT     /* mapped to default const 8bit section */
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CONST_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_CONST_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CONST_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_CONST_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CONST_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_CONST_FAST_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_CONST_FAST_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_CONST_FAST_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_CONST_FAST_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_PBCFG)
# undef CANTRCV_30_TJA1043_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_PBCFG)
# undef CANTRCV_30_TJA1043_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_PBCFG)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_PBCFG)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CANTRCV_30_TJA1043 END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */


/***********************************************************************************************************************
 *  VXSPI START 
 **********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef VXSPI_START_SEC_CODE
# undef VXSPI_START_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#ifdef VXSPI_STOP_SEC_CODE
# undef VXSPI_STOP_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef VXSPI_START_SEC_CONST_8
# undef VXSPI_START_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_CONST_8
#endif
#ifdef VXSPI_STOP_SEC_CONST_8
# undef VXSPI_STOP_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef VXSPI_START_SEC_CONST_16
# undef VXSPI_START_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_CONST_16
#endif
#ifdef VXSPI_STOP_SEC_CONST_16
# undef VXSPI_STOP_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef VXSPI_START_SEC_CONST_32
# undef VXSPI_START_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_CONST_32
#endif
#ifdef VXSPI_STOP_SEC_CONST_32
# undef VXSPI_STOP_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef VXSPI_START_SEC_CONST_UNSPECIFIED
# undef VXSPI_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef VXSPI_STOP_SEC_CONST_UNSPECIFIED
# undef VXSPI_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef VXSPI_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef VXSPI_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef VXSPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef VXSPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NO_INIT sections */

#ifdef VXSPI_START_SEC_VAR_NO_INIT_8
# undef VXSPI_START_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_VAR_NO_INIT_8
#endif
#ifdef VXSPI_STOP_SEC_VAR_NO_INIT_8
# undef VXSPI_STOP_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define STOP_SEC_VAR
#endif

#ifdef VXSPI_START_SEC_VAR_NO_INIT_32
# undef VXSPI_START_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_VAR_NO_INIT_32
#endif
#ifdef VXSPI_STOP_SEC_VAR_NO_INIT_32
# undef VXSPI_STOP_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
#ifdef VXSPI_START_SEC_VAR_CLEARED_8
# undef VXSPI_START_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_VAR_CLEARED_8
#endif
#ifdef VXSPI_STOP_SEC_VAR_CLEARED_8
# undef VXSPI_STOP_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VXSPI_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef VXSPI_START_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#ifdef VXSPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef VXSPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VXSPI_START_SEC_PBCFG
# undef VXSPI_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_CONST_PBCFG
#endif
#ifdef VXSPI_STOP_SEC_PBCFG
# undef VXSPI_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define STOP_SEC_CONST
#endif

/* VAR INIT sections */
#if defined(VXSPI_START_SEC_VAR_INIT_UNSPECIFIED)
# undef VXSPI_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(VXSPI_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef VXSPI_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


#if defined(VXSPI_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VXSPI_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(VXSPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VXSPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/***********************************************************************************************************************
 *  VXSPI END
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  FBLBM_HDR START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FBLBMHDR_START_SEC_CODE
 #undef FBLBMHDR_START_SEC_CODE
 #define START_SEC_CODE                                              /* Mapped to default code section */
#endif

#ifdef FBLBMHDR_STOP_SEC_CODE
 #undef FBLBMHDR_STOP_SEC_CODE
 #define STOP_SEC_CODE                                               /* Default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef FBLBMHDR_BMHEADER_START_SEC_CONST
 #undef FBLBMHDR_BMHEADER_START_SEC_CONST
 #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FBLBMHDR_BMHEADER_STOP_SEC_CONST
 #undef FBLBMHDR_BMHEADER_STOP_SEC_CONST
 #define STOP_SEC_CONST
#endif

#ifdef FBLBMHDR_START_SEC_CONST
 #undef FBLBMHDR_START_SEC_CONST
 #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FBLBMHDR_STOP_SEC_CONST
 #undef FBLBMHDR_STOP_SEC_CONST
 #define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 *  FBLBM_HDR END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  FBLBM_MAIN START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FBLBM_START_SEC_CODE
 #undef FBLBM_START_SEC_CODE
 #define START_SEC_CODE                                              /* Mapped to default code section */
#endif

#ifdef FBLBM_STOP_SEC_CODE
 #undef FBLBM_STOP_SEC_CODE
 #define STOP_SEC_CODE                                               /* Default code stop section */
#endif

#ifdef FBLBM_MAIN_FBLSTART_START_SEC_CODE
 #undef FBLBM_MAIN_FBLSTART_START_SEC_CODE
 #define START_SEC_CODE                                              /* Mapped to default code section */
#endif

#ifdef FBLBM_MAIN_FBLSTART_STOP_SEC_CODE
 #undef FBLBM_MAIN_FBLSTART_STOP_SEC_CODE
 #define STOP_SEC_CODE                                               /* Default code stop section */
#endif

#ifdef FBLBM_MAIN_APPLSTART_START_SEC_CODE
 #undef FBLBM_MAIN_APPLSTART_START_SEC_CODE
 #define START_SEC_CODE                                              /* Mapped to default code section */
#endif

#ifdef FBLBM_MAIN_APPLSTART_STOP_SEC_CODE
 #undef FBLBM_MAIN_APPLSTART_STOP_SEC_CODE
 #define STOP_SEC_CODE                                               /* Default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef FBLBM_HEADER_START_SEC_CONST
 #undef FBLBM_HEADER_START_SEC_CONST
 #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FBLBM_HEADER_STOP_SEC_CONST
 #undef FBLBM_HEADER_STOP_SEC_CONST
 #define STOP_SEC_CONST
#endif

#ifdef FBLBM_START_SEC_CONST
 #undef FBLBM_START_SEC_CONST
 #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FBLBM_STOP_SEC_CONST
 #undef FBLBM_STOP_SEC_CONST
 #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef FBLBM_START_SEC_VAR
 #undef FBLBM_START_SEC_VAR
 #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef FBLBM_STOP_SEC_VAR
 #undef FBLBM_STOP_SEC_VAR
 #define STOP_SEC_VAR
#endif

#ifdef FBLBM_MAIN_MAGICFLAG_START_SEC_VAR_NOINIT
 #undef FBLBM_MAIN_MAGICFLAG_START_SEC_VAR_NOINIT
 #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef FBLBM_MAIN_MAGICFLAG_STOP_SEC_VAR_NOINIT
 #undef FBLBM_MAIN_MAGICFLAG_STOP_SEC_VAR_NOINIT
 #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  FBLBM_MAIN END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  FBLLIB_SECBOOT START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FBLSB_START_SEC_CODE
 #undef FBLSB_START_SEC_CODE
 #define START_SEC_CODE                                              /* Mapped to default code section */
#endif

#ifdef FBLSB_STOP_SEC_CODE
 #undef FBLSB_STOP_SEC_CODE
 #define STOP_SEC_CODE                                               /* Default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef FBLSB_START_SEC_CONST
 #undef FBLSB_START_SEC_CONST
 #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FBLSB_STOP_SEC_CONST
 #undef FBLSB_STOP_SEC_CONST
 #define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 *  FBLLIB_SECBOOT END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  FblCw START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FBLCW_START_SEC_CODE
# undef FBLCW_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef FBLCW_STOP_SEC_CODE
# undef FBLCW_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif
/* FBCW application callback code section */
#ifdef FBLCW_START_SEC_APPL_CODE
# undef FBLCW_START_SEC_APPL_CODE
# define START_SEC_CODE
#endif
#ifdef FBLCW_STOP_SEC_APPL_CODE
# undef FBLCW_STOP_SEC_APPL_CODE
# define STOP_SEC_CODE
#endif
#ifdef FBLCW_CAN_START_SEC_CODE
# undef FBLCW_CAN_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef FBLCW_CAN_STOP_SEC_CODE
# undef FBLCW_CAN_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif
#ifdef FBLCW_FR_START_SEC_CODE
# undef FBLCW_FR_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef FBLCW_FR_STOP_SEC_CODE
# undef FBLCW_FR_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif
#ifdef FBLCW_LIN_START_SEC_CODE
# undef FBLCW_LIN_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef FBLCW_LIN_STOP_SEC_CODE
# undef FBLCW_LIN_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FBLCW_START_SEC_CONST_8BIT
# undef FBLCW_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef FBLCW_STOP_SEC_CONST_8BIT
# undef FBLCW_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef FBLCW_START_SEC_CONST_16BIT
# undef FBLCW_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef FBLCW_STOP_SEC_CONST_16BIT
# undef FBLCW_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef FBLCW_START_SEC_CONST_32BIT
# undef FBLCW_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef FBLCW_STOP_SEC_CONST_32BIT
# undef FBLCW_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef FBLCW_START_SEC_CONST_64BIT
# undef FBLCW_START_SEC_CONST_64BIT
# define START_SEC_CONST_64BIT
#endif
#ifdef FBLCW_STOP_SEC_CONST_64BIT
# undef FBLCW_STOP_SEC_CONST_64BIT
# define STOP_SEC_CONST
#endif

#ifdef FBLCW_START_SEC_CONST_UNSPECIFIED
# undef FBLCW_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FBLCW_STOP_SEC_CONST_UNSPECIFIED
# undef FBLCW_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef FBLCW_START_SEC_PBCFG
# undef FBLCW_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef FBLCW_STOP_SEC_PBCFG
# undef FBLCW_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef FBLCW_START_SEC_VAR_PBCFG
# undef FBLCW_START_SEC_VAR_PBCFG
# define START_SEC_VAR_PBCFG
#endif
#ifdef FBLCW_STOP_SEC_VAR_PBCFG
# undef FBLCW_STOP_SEC_VAR_PBCFG
# define STOP_SEC_VAR
#endif


/*******  VAR sections  **********************************************************************************************/

#ifdef FBLCW_START_SEC_VAR
# undef FBLCW_START_SEC_VAR
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef FBLCW_STOP_SEC_VAR
# undef FBLCW_STOP_SEC_VAR
# define STOP_SEC_VAR
#endif

/* VAR INIT sections */

#ifdef FBLCW_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBLCW_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef FBLCW_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBLCW_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef FBLCW_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBLCW_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef FBLCW_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBLCW_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef FBLCW_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBLCW_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef FBLCW_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBLCW_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

/* VAR NOINIT sections */

#ifdef FBLCW_START_SEC_VAR_NOINIT_BOOLEAN
# undef FBLCW_START_SEC_VAR_NOINIT_BOOLEAN
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef FBLCW_STOP_SEC_VAR_NOINIT_BOOLEAN
# undef FBLCW_STOP_SEC_VAR_NOINIT_BOOLEAN
# define STOP_SEC_VAR
#endif

#ifdef FBLCW_START_SEC_VAR_NOINIT_8BIT
# undef FBLCW_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef FBLCW_STOP_SEC_VAR_NOINIT_8BIT
# undef FBLCW_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef FBLCW_START_SEC_VAR_NOINIT_16BIT
# undef FBLCW_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef FBLCW_STOP_SEC_VAR_NOINIT_16BIT
# undef FBLCW_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef FBLCW_START_SEC_VAR_NOINIT_32BIT
# undef FBLCW_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef FBLCW_STOP_SEC_VAR_NOINIT_32BIT
# undef FBLCW_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef FBLCW_START_SEC_VAR_NOINIT_64BIT
# undef FBLCW_START_SEC_VAR_NOINIT_64BIT
# define START_SEC_VAR_NOINIT_64BIT
#endif
#ifdef FBLCW_STOP_SEC_VAR_NOINIT_64BIT
# undef FBLCW_STOP_SEC_VAR_NOINIT_64BIT
# define STOP_SEC_VAR
#endif

#ifdef FBLCW_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBLCW_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef FBLCW_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBLCW_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */



/* VAR FAST INIT sections */



/* VAR FAST NOINIT sections */


/* VAR FAST ZERO INIT sections */



/**********************************************************************************************************************
 *  FblCw END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CRYIF START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef CRYIF_START_SEC_CODE
# undef CRYIF_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef CRYIF_STOP_SEC_CODE
# undef CRYIF_STOP_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CRYIF_START_SEC_CONST_UNSPECIFIED
# undef CRYIF_START_SEC_CONST_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CRYIF_STOP_SEC_CONST_UNSPECIFIED
# undef CRYIF_STOP_SEC_CONST_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */


/* VAR ZERO INIT sections */

#ifdef CRYIF_START_SEC_VAR_ZERO_INIT_8BIT
# undef CRYIF_START_SEC_VAR_ZERO_INIT_8BIT      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef CRYIF_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef CRYIF_STOP_SEC_VAR_ZERO_INIT_8BIT      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CRYIF END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  If_AsrIfEa START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef EA_START_SEC_CODE
    #undef EA_START_SEC_CODE                 /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_CODE
#endif
#ifdef EA_STOP_SEC_CODE
    #undef EA_STOP_SEC_CODE                 /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef EA_START_SEC_CONST_8BIT
    #undef EA_START_SEC_CONST_8BIT          /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_CONST_8BIT
#endif
#ifdef EA_STOP_SEC_CONST_8BIT
    #undef EA_STOP_SEC_CONST_8BIT          /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_CONST
#endif

#ifdef EA_START_SEC_CONST_UNSPECIFIED
    #undef EA_START_SEC_CONST_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef EA_STOP_SEC_CONST_UNSPECIFIED
    #undef EA_STOP_SEC_CONST_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  ********************************************************************************************/

/* VAR NOINIT sections */

#ifdef EA_START_SEC_VAR_NOINIT_INTERNAL_READ_BUFFER
/* Non-standard MemMap section for internal read buffer, which will be forwarded to the EEPROM driver.
 * Depending on restrictions, this buffer might have to be aligned to prevent unaligned memory access exceptions. */
# undef EA_START_SEC_VAR_NOINIT_INTERNAL_READ_BUFFER /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef EA_STOP_SEC_VAR_NOINIT_INTERNAL_READ_BUFFER
# undef EA_STOP_SEC_VAR_NOINIT_INTERNAL_READ_BUFFER /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef EA_START_SEC_VAR_NOINIT_INTERNAL_WRITE_BUFFER
/* Non-standard MemMap section for internal write buffer, which will be forwarded to the EEPROM driver.
 * Depending on restrictions, this buffer might have to be aligned to prevent unaligned memory access exceptions. */
# undef EA_START_SEC_VAR_NOINIT_INTERNAL_WRITE_BUFFER /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef EA_STOP_SEC_VAR_NOINIT_INTERNAL_WRITE_BUFFER
# undef EA_STOP_SEC_VAR_NOINIT_INTERNAL_WRITE_BUFFER /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef EA_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef EA_START_SEC_VAR_NOINIT_UNSPECIFIED         /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef EA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef EA_STOP_SEC_VAR_NOINIT_UNSPECIFIED          /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif

/* VAR FAST sections */

#ifdef EA_START_SEC_VAR_FAST_INIT_UNSPECIFIED
    #undef EA_START_SEC_VAR_FAST_INIT_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef EA_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
    #undef EA_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  If_AsrIfEa END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  FEE START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FEE_START_SEC_CODE
# undef FEE_START_SEC_CODE
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef FEE_STOP_SEC_CODE
# undef FEE_STOP_SEC_CODE
# define STOP_SEC_CODE                                                /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FEE_START_SEC_CONST_UNSPECIFIED
# undef FEE_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FEE_STOP_SEC_CONST_UNSPECIFIED
# undef FEE_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef FEE_START_SEC_APPL_CONFIG_UNSPECIFIED
# undef FEE_START_SEC_APPL_CONFIG_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FEE_STOP_SEC_APPL_CONFIG_UNSPECIFIED
# undef FEE_STOP_SEC_APPL_CONFIG_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef FEE_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FEE_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef FEE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FEE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef FEE_START_SEC_VAR_INIT_UNSPECIFIED
# undef FEE_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif
/**********************************************************************************************************************
 *  FEE END
 *********************************************************************************************************************/


/***********************************************************************************************************************
 *  FEE_30_FLEXNOR START 
 **********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef FEE_30_FLEXNOR_START_SEC_CODE
# undef FEE_30_FLEXNOR_START_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_CODE
# undef FEE_30_FLEXNOR_STOP_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FEE_30_FLEXNOR_START_SEC_CONST_32
# undef FEE_30_FLEXNOR_START_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_CONST_32
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_CONST_32
# undef FEE_30_FLEXNOR_STOP_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef FEE_30_FLEXNOR_START_SEC_CONST_UNSPECIFIED
# undef FEE_30_FLEXNOR_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_CONST_UNSPECIFIED
# undef FEE_30_FLEXNOR_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NO_INIT sections */
#ifdef FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_8
# undef FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_VAR_NO_INIT_8
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_8
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define STOP_SEC_VAR
#endif

#ifdef FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_32
# undef FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_VAR_NO_INIT_32
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_32
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
#ifdef FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_8
# undef FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_VAR_CLEARED_8
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_CLEARED_8
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef FEE_30_FLEXNOR_START_SEC_PBCFG
# undef FEE_30_FLEXNOR_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_CONST_PBCFG
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_PBCFG
# undef FEE_30_FLEXNOR_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define STOP_SEC_CONST
#endif

/* VAR INIT section */
#ifdef FEE_30_FLEXNOR_START_SEC_VAR_INIT_32
# undef FEE_30_FLEXNOR_START_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_VAR_INIT_32
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_INIT_32
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef FEE_30_FLEXNOR_START_SEC_VAR_INIT_UNSPECIFIED
# undef FEE_30_FLEXNOR_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/***********************************************************************************************************************
 *  FEE_30_FLEXNOR END
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  FEE_30_FLEXNOR START 
 **********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef FEE_30_FLEXNOR_START_SEC_CODE
# undef FEE_30_FLEXNOR_START_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_CODE
# undef FEE_30_FLEXNOR_STOP_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FEE_30_FLEXNOR_START_SEC_CONST_32
# undef FEE_30_FLEXNOR_START_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_CONST_32
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_CONST_32
# undef FEE_30_FLEXNOR_STOP_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef FEE_30_FLEXNOR_START_SEC_CONST_UNSPECIFIED
# undef FEE_30_FLEXNOR_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_CONST_UNSPECIFIED
# undef FEE_30_FLEXNOR_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NO_INIT sections */
#ifdef FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_8
# undef FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_VAR_NO_INIT_8
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_8
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define STOP_SEC_VAR
#endif

#ifdef FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_32
# undef FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_VAR_NO_INIT_32
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_32
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
#ifdef FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_8
# undef FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_VAR_CLEARED_8
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_CLEARED_8
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef FEE_30_FLEXNOR_START_SEC_PBCFG
# undef FEE_30_FLEXNOR_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_CONST_PBCFG
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_PBCFG
# undef FEE_30_FLEXNOR_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define STOP_SEC_CONST
#endif

/* VAR INIT section */
#ifdef FEE_30_FLEXNOR_START_SEC_VAR_INIT_32
# undef FEE_30_FLEXNOR_START_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_VAR_INIT_32
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_INIT_32
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef FEE_30_FLEXNOR_START_SEC_VAR_INIT_UNSPECIFIED
# undef FEE_30_FLEXNOR_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/***********************************************************************************************************************
 *  FEE_30_FLEXNOR END
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  VFEEACC START 
 **********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef VFEEACC_START_SEC_CODE
#  undef VFEEACC_START_SEC_CODE  /* PRQA S 0841 */ /* MD_MSR_Undef */
#  define START_SEC_CODE /* mapped to default code section */
#endif
#ifdef VFEEACC_STOP_SEC_CODE
#  undef VFEEACC_STOP_SEC_CODE  /* PRQA S 0841 */ /* MD_MSR_Undef */
#  define STOP_SEC_CODE /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef VFEEACC_START_SEC_CONST_UNSPECIFIED
#  undef VFEEACC_START_SEC_CONST_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
#  define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef VFEEACC_STOP_SEC_CONST_UNSPECIFIED
#  undef VFEEACC_STOP_SEC_CONST_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
#  define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef VFEEACC_START_SEC_VAR_NOINIT_UNSPECIFIED
#  undef VFEEACC_START_SEC_VAR_NOINIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
#  define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef VFEEACC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  undef VFEEACC_STOP_SEC_VAR_NOINIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
#  define STOP_SEC_VAR
#endif

/* VAR INIT sections */

#ifdef VFEEACC_START_SEC_VAR_INIT_UNSPECIFIED
#  undef VFEEACC_START_SEC_VAR_INIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
#  define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef VFEEACC_STOP_SEC_VAR_INIT_UNSPECIFIED
#  undef VFEEACC_STOP_SEC_VAR_INIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
#  define STOP_SEC_VAR
#endif


/***********************************************************************************************************************
 *  VFEEACC END
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  VMEMACCM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VMEMACCM_START_SEC_CODE)
# undef VMEMACCM_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VMEMACCM_STOP_SEC_CODE)
# undef VMEMACCM_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(VMEMACCM_START_SEC_VAR_INIT_8BIT)
# undef VMEMACCM_START_SEC_VAR_INIT_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT          /* mapped to default var init 8bit section */
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_INIT_8BIT)
# undef VMEMACCM_STOP_SEC_VAR_INIT_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                     /* default var stop section */
#endif

#if defined(VMEMACCM_START_SEC_VAR_INIT_16BIT)
# undef VMEMACCM_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_INIT_16BIT)
# undef VMEMACCM_STOP_SEC_VAR_INIT_16BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_INIT_32BIT)
# undef VMEMACCM_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_INIT_32BIT)
# undef VMEMACCM_STOP_SEC_VAR_INIT_32BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED)
# undef VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#if defined(VMEMACCM_START_SEC_VAR_ZERO_INIT_8BIT)
# undef VMEMACCM_START_SEC_VAR_ZERO_INIT_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef VMEMACCM_STOP_SEC_VAR_ZERO_INIT_8BIT    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef VMEMACCM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef VMEMACCM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR CONST sections */

#if defined(VMEMACCM_START_SEC_CONST_UNSPECIFIED)
# undef VMEMACCM_START_SEC_CONST_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(VMEMACCM_STOP_SEC_CONST_UNSPECIFIED)
# undef VMEMACCM_STOP_SEC_CONST_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* VAR NOINIT sections */

#if defined(VMEMACCM_START_SEC_VAR_NOINIT_8BIT)
# undef VMEMACCM_START_SEC_VAR_NOINIT_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_NOINIT_8BIT)
# undef VMEMACCM_STOP_SEC_VAR_NOINIT_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_NOINIT_16BIT)
# undef VMEMACCM_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_NOINIT_16BIT)
# undef VMEMACCM_STOP_SEC_VAR_NOINIT_16BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_NOINIT_32BIT)
# undef VMEMACCM_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_NOINIT_32BIT)
# undef VMEMACCM_STOP_SEC_VAR_NOINIT_32BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VMEMACCM_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VMEMACCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* Multi partition sections. */

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID0
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID0
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition0"
#   pragma ghs section sdata=".svMemAccMPartition0"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID0
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID0
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif


#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID1
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID1
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition1"
#   pragma ghs section sdata=".svMemAccMPartition1"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID1
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID1
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID2
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID2
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition2"
#   pragma ghs section sdata=".svMemAccMPartition2"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID2
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID2
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID3
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID3
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition3"
#   pragma ghs section sdata=".svMemAccMPartition3"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID3
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID3
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID4
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID4
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition4"
#   pragma ghs section sdata=".svMemAccMPartition4"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID4
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID4
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID5
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID5
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition5"
#   pragma ghs section sdata=".svMemAccMPartition5"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID5
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID5
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID6
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID6
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition6"
#   pragma ghs section sdata=".svMemAccMPartition6"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID6
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID6
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID7
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID7
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition7"
#   pragma ghs section sdata=".svMemAccMPartition7"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID7
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID7
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID8
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID8
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition8"
#   pragma ghs section sdata=".svMemAccMPartition8"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID8
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID8
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID9
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID9
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition9"
#   pragma ghs section sdata=".svMemAccMPartition9"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID9
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID9
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID10
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID10
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition10"
#   pragma ghs section sdata=".svMemAccMPartition10"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID10
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID10
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID11
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID11
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition11"
#   pragma ghs section sdata=".svMemAccMPartition11"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID11
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID11
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID12
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID12
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition12"
#   pragma ghs section sdata=".svMemAccMPartition12"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID12
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID12
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID13
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID13
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition13"
#   pragma ghs section sdata=".svMemAccMPartition13"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID13
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID13
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID14
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID14
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition14"
#   pragma ghs section sdata=".svMemAccMPartition14"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID14
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID14
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID15
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID15
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition15"
#   pragma ghs section sdata=".svMemAccMPartition15"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID15
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID15
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID16
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID16
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition16"
#   pragma ghs section sdata=".svMemAccMPartition16"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID16
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID16
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  VMEMACCM END
 *********************************************************************************************************************/

/**********************************************************************************************************************
* 3rdParty_Mcal START
*********************************************************************************************************************/

#ifdef ADC_START_SEC_CODE
  #undef ADC_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef ADC_STOP_SEC_CODE
  #undef ADC_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ADC_START_SEC_CONFIG_DATA
  #undef ADC_START_SEC_CONFIG_DATA
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_CONFIG_DATA
  #undef ADC_STOP_SEC_CONFIG_DATA
  #define STOP_SEC_CONST
#endif

#ifdef ADC_START_SEC_ISR_CODE
  #undef ADC_START_SEC_ISR_CODE
  #define START_SEC_CODE_ISR
#endif

#ifdef ADC_STOP_SEC_ISR_CODE
  #undef ADC_STOP_SEC_ISR_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ADC_START_SEC_VAR_INIT_32
  #undef ADC_START_SEC_VAR_INIT_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef ADC_STOP_SEC_VAR_INIT_32
  #undef ADC_STOP_SEC_VAR_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef CDD_IPC_START_SEC_CODE
  #undef CDD_IPC_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef CDD_IPC_STOP_SEC_CODE
  #undef CDD_IPC_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef CDD_IPC_START_SEC_CONFIG_DATA
  #undef CDD_IPC_START_SEC_CONFIG_DATA
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef CDD_IPC_STOP_SEC_CONFIG_DATA
  #undef CDD_IPC_STOP_SEC_CONFIG_DATA
  #define STOP_SEC_CONST
#endif

#ifdef CDD_IPC_START_SEC_ISR_CODE
  #undef CDD_IPC_START_SEC_ISR_CODE
  #define START_SEC_CODE_ISR
#endif

#ifdef CDD_IPC_STOP_SEC_ISR_CODE
  #undef CDD_IPC_STOP_SEC_ISR_CODE
  #define STOP_SEC_CODE
#endif

#ifdef CDD_IPC_START_SEC_VAR_INIT_32
  #undef CDD_IPC_START_SEC_VAR_INIT_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef CDD_IPC_STOP_SEC_VAR_INIT_32
  #undef CDD_IPC_STOP_SEC_VAR_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef CDD_IPC_START_SEC_VAR_NO_INIT_8_ALIGN_8B
  #undef CDD_IPC_START_SEC_VAR_NO_INIT_8_ALIGN_8B
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef CDD_IPC_STOP_SEC_VAR_NO_INIT_8_ALIGN_8B
  #undef CDD_IPC_STOP_SEC_VAR_NO_INIT_8_ALIGN_8B
  #define STOP_SEC_VAR
#endif

#ifdef CDD_IPC_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef CDD_IPC_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef CDD_IPC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef CDD_IPC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef DIO_START_SEC_CODE
  #undef DIO_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef DIO_STOP_SEC_CODE
  #undef DIO_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef DIO_START_SEC_CONFIG_DATA
  #undef DIO_START_SEC_CONFIG_DATA
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DIO_STOP_SEC_CONFIG_DATA
  #undef DIO_STOP_SEC_CONFIG_DATA
  #define STOP_SEC_CONST
#endif

#ifdef DIO_START_SEC_CONST_32
  #undef DIO_START_SEC_CONST_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef DIO_STOP_SEC_CONST_32
  #undef DIO_STOP_SEC_CONST_32
  #define STOP_SEC_CONST
#endif

#ifdef DIO_START_SEC_CONST_UNSPECIFIED
  #undef DIO_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DIO_STOP_SEC_CONST_UNSPECIFIED
  #undef DIO_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ETH_START_SEC_CODE
  #undef ETH_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef ETH_STOP_SEC_CODE
  #undef ETH_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ETH_START_SEC_CONST_UNSPECIFIED
  #undef ETH_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ETH_STOP_SEC_CONST_UNSPECIFIED
  #undef ETH_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif
#ifdef ETH_START_SEC_CONFIG_DATA
  #undef ETH_START_SEC_CONFIG_DATA
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ETH_STOP_SEC_CONFIG_DATA
  #undef ETH_STOP_SEC_CONFIG_DATA
  #define STOP_SEC_CONST
#endif

#ifdef ETH_START_SEC_ISR_CODE
  #undef ETH_START_SEC_ISR_CODE
  #define START_SEC_CODE_ISR
#endif

#ifdef ETH_STOP_SEC_ISR_CODE
  #undef ETH_STOP_SEC_ISR_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ETH_START_SEC_VAR_INIT_8
  #undef ETH_START_SEC_VAR_INIT_8
  #define START_SEC_VAR_INIT_8BIT
#endif

#ifdef ETH_STOP_SEC_VAR_INIT_8
  #undef ETH_STOP_SEC_VAR_INIT_8
  #define STOP_SEC_VAR
#endif
#ifdef ETH_START_SEC_RX_DATA
  #undef ETH_START_SEC_RX_DATA
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef ETH_STOP_SEC_RX_DATA
  #undef ETH_STOP_SEC_RX_DATA
  #define STOP_SEC_VAR
#endif

#ifdef ETH_START_SEC_TX_DATA
  #undef ETH_START_SEC_TX_DATA
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef ETH_STOP_SEC_TX_DATA
  #undef ETH_STOP_SEC_TX_DATA
  #define STOP_SEC_VAR
#endif

#ifdef ETH_START_SEC_UDMA
  #undef ETH_START_SEC_UDMA
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef ETH_STOP_SEC_UDMA
  #undef ETH_STOP_SEC_UDMA
  #define STOP_SEC_VAR
#endif

#ifdef ETH_START_SEC_UDMA_DESC
  #undef ETH_START_SEC_UDMA_DESC
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef ETH_STOP_SEC_UDMA_DESC
  #undef ETH_STOP_SEC_UDMA_DESC
  #define STOP_SEC_VAR
#endif

#ifdef ETH_START_SEC_UDMA_RING
  #undef ETH_START_SEC_UDMA_RING
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef ETH_STOP_SEC_UDMA_RING
  #undef ETH_STOP_SEC_UDMA_RING
  #define STOP_SEC_VAR
#endif

#ifdef ETH_START_SEC_VAR_INIT_UNSPECIFIED
  #undef ETH_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef ETH_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef ETH_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ETH_START_SEC_VAR_NO_INIT_32
  #undef ETH_START_SEC_VAR_NO_INIT_32
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef ETH_STOP_SEC_VAR_NO_INIT_32
  #undef ETH_STOP_SEC_VAR_NO_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef ETH_START_SEC_VAR_NO_INIT_8
  #undef ETH_START_SEC_VAR_NO_INIT_8
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef ETH_STOP_SEC_VAR_NO_INIT_8
  #undef ETH_STOP_SEC_VAR_NO_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef ETH_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef ETH_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef ETH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef ETH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ETH_START_SEC_VAR_NO_INIT_UNSPECIFIED_128
  #undef ETH_START_SEC_VAR_NO_INIT_UNSPECIFIED_128
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef ETH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_128
  #undef ETH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_128
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_CODE
  #undef FLS_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef FLS_STOP_SEC_CODE
  #undef FLS_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLS_START_SEC_CONFIG_DATA
  #undef FLS_START_SEC_CONFIG_DATA
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_CONFIG_DATA
  #undef FLS_STOP_SEC_CONFIG_DATA
  #define STOP_SEC_CONST
#endif

#ifdef FLS_START_SEC_ISR_CODE
  #undef FLS_START_SEC_ISR_CODE
  #define START_SEC_CODE_ISR
#endif

#ifdef FLS_STOP_SEC_ISR_CODE
  #undef FLS_STOP_SEC_ISR_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_CODE
  #undef GPT_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef GPT_STOP_SEC_CODE
  #undef GPT_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef GPT_START_SEC_CONFIG_DATA
  #undef GPT_START_SEC_CONFIG_DATA
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA
  #undef GPT_STOP_SEC_CONFIG_DATA
  #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_CONST_32
  #undef GPT_START_SEC_CONST_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef GPT_STOP_SEC_CONST_32
  #undef GPT_STOP_SEC_CONST_32
  #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_ISR_CODE
  #undef GPT_START_SEC_ISR_CODE
  #define START_SEC_CODE_ISR
#endif

#ifdef GPT_STOP_SEC_ISR_CODE
  #undef GPT_STOP_SEC_ISR_CODE
  #define STOP_SEC_CODE
#endif

#ifdef GPT_START_SEC_VAR_INIT_32
  #undef GPT_START_SEC_VAR_INIT_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_32
  #undef GPT_STOP_SEC_VAR_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ICU_START_SEC_CODE
  #undef ICU_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef ICU_STOP_SEC_CODE
  #undef ICU_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ICU_START_SEC_CONFIG_DATA
  #undef ICU_START_SEC_CONFIG_DATA
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ICU_STOP_SEC_CONFIG_DATA
  #undef ICU_STOP_SEC_CONFIG_DATA
  #define STOP_SEC_CONST
#endif

#ifdef ICU_START_SEC_CONST_32
  #undef ICU_START_SEC_CONST_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef ICU_STOP_SEC_CONST_32
  #undef ICU_STOP_SEC_CONST_32
  #define STOP_SEC_CONST
#endif

#ifdef ICU_START_SEC_ISR_CODE
  #undef ICU_START_SEC_ISR_CODE
  #define START_SEC_CODE_ISR
#endif

#ifdef ICU_STOP_SEC_ISR_CODE
  #undef ICU_STOP_SEC_ISR_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ICU_START_SEC_VAR_INIT_32
  #undef ICU_START_SEC_VAR_INIT_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef ICU_STOP_SEC_VAR_INIT_32
  #undef ICU_STOP_SEC_VAR_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef ICU_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef ICU_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef ICU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef ICU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_CODE
  #undef MCU_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef MCU_STOP_SEC_CODE
  #undef MCU_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef MCU_START_SEC_CONFIG_DATA
  #undef MCU_START_SEC_CONFIG_DATA
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_CONFIG_DATA
  #undef MCU_STOP_SEC_CONFIG_DATA
  #define STOP_SEC_CONST
#endif

#ifdef MCU_START_SEC_VAR_INIT_8
  #undef MCU_START_SEC_VAR_INIT_8
  #define START_SEC_VAR_INIT_8BIT
#endif

#ifdef MCU_STOP_SEC_VAR_INIT_8
  #undef MCU_STOP_SEC_VAR_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_CODE
  #undef PWM_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef PWM_STOP_SEC_CODE
  #undef PWM_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef PWM_START_SEC_CONFIG_DATA
  #undef PWM_START_SEC_CONFIG_DATA
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef PWM_STOP_SEC_CONFIG_DATA
  #undef PWM_STOP_SEC_CONFIG_DATA
  #define STOP_SEC_CONST
#endif

#ifdef PWM_START_SEC_CONST_32
  #undef PWM_START_SEC_CONST_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef PWM_STOP_SEC_CONST_32
  #undef PWM_STOP_SEC_CONST_32
  #define STOP_SEC_CONST
#endif

#ifdef PWM_START_SEC_ISR_CODE
  #undef PWM_START_SEC_ISR_CODE
  #define START_SEC_CODE_ISR
#endif

#ifdef PWM_STOP_SEC_ISR_CODE
  #undef PWM_STOP_SEC_ISR_CODE
  #define STOP_SEC_CODE
#endif

#ifdef PWM_START_SEC_VAR_INIT_32
  #undef PWM_START_SEC_VAR_INIT_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef PWM_STOP_SEC_VAR_INIT_32
  #undef PWM_STOP_SEC_VAR_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_VAR_INIT_8
  #undef PWM_START_SEC_VAR_INIT_8
  #define START_SEC_VAR_INIT_8BIT
#endif

#ifdef PWM_STOP_SEC_VAR_INIT_8
  #undef PWM_STOP_SEC_VAR_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef PWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef PWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef PWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_CODE
  #undef SPI_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef SPI_STOP_SEC_CODE
  #undef SPI_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef SPI_START_SEC_CONFIG_DATA
  #undef SPI_START_SEC_CONFIG_DATA
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_CONFIG_DATA
  #undef SPI_STOP_SEC_CONFIG_DATA
  #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_CONST_32
  #undef SPI_START_SEC_CONST_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef SPI_STOP_SEC_CONST_32
  #undef SPI_STOP_SEC_CONST_32
  #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_CONST_UNSPECIFIED
  #undef SPI_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_CONST_UNSPECIFIED
  #undef SPI_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_ISR_CODE
  #undef SPI_START_SEC_ISR_CODE
  #define START_SEC_CODE_ISR
#endif

#ifdef SPI_STOP_SEC_ISR_CODE
  #undef SPI_STOP_SEC_ISR_CODE
  #define STOP_SEC_CODE
#endif

#ifdef SPI_START_SEC_UDMA_RING
  #undef SPI_START_SEC_UDMA_RING
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef SPI_STOP_SEC_UDMA_RING
  #undef SPI_STOP_SEC_UDMA_RING
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_INIT_UNSPECIFIED
  #undef SPI_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_START_SEC_CODE
  #undef WDG_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef WDG_STOP_SEC_CODE
  #undef WDG_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef WDG_START_SEC_CONFIG_DATA
  #undef WDG_START_SEC_CONFIG_DATA
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef WDG_STOP_SEC_CONFIG_DATA
  #undef WDG_STOP_SEC_CONFIG_DATA
  #define STOP_SEC_CONST
#endif

#ifdef WDG_START_SEC_CONST_32
  #undef WDG_START_SEC_CONST_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef WDG_STOP_SEC_CONST_32
  #undef WDG_STOP_SEC_CONST_32
  #define STOP_SEC_CONST
#endif

#ifdef WDG_START_SEC_ISR_CODE
  #undef WDG_START_SEC_ISR_CODE
  #define START_SEC_CODE_ISR
#endif

#ifdef WDG_STOP_SEC_ISR_CODE
  #undef WDG_STOP_SEC_ISR_CODE
  #define STOP_SEC_CODE
#endif

#ifdef WDG_START_SEC_VAR_INIT_UNSPECIFIED
  #undef WDG_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
* 3rdParty_Mcal END
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  CSM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef CSM_START_SEC_CODE
# undef CSM_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef CSM_STOP_SEC_CODE
# undef CSM_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#ifdef CSM_START_SEC_APPL_CODE
# undef CSM_START_SEC_APPL_CODE  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef CSM_STOP_SEC_APPL_CODE
# undef CSM_STOP_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CSM_START_SEC_CONST_8BIT
# undef CSM_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif

#ifdef CSM_STOP_SEC_CONST_8BIT
# undef CSM_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef CSM_START_SEC_CONST_UNSPECIFIED
# undef CSM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CSM_STOP_SEC_CONST_UNSPECIFIED
# undef CSM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef CSM_START_SEC_VAR_NOINIT_8BIT
# undef CSM_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef CSM_STOP_SEC_VAR_NOINIT_8BIT
# undef CSM_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef CSM_START_SEC_VAR_NOINIT_16BIT
# undef CSM_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef CSM_STOP_SEC_VAR_NOINIT_16BIT
# undef CSM_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef CSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef CSM_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef CSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef CSM_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef CSM_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CSM END
 *********************************************************************************************************************/


/***********************************************************************************************************************
 *  KEYM START
 **********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef KEYM_START_SEC_CODE
# undef KEYM_START_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#ifdef KEYM_STOP_SEC_CODE
# undef KEYM_STOP_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

#ifdef KEYM_START_SEC_APPL_CODE
# undef KEYM_START_SEC_APPL_CODE                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#ifdef KEYM_STOP_SEC_APPL_CODE
# undef KEYM_STOP_SEC_APPL_CODE                          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef KEYM_START_SEC_CONST_8
# undef KEYM_START_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8
#endif
#ifdef KEYM_STOP_SEC_CONST_8
# undef KEYM_STOP_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef KEYM_START_SEC_CONST_16
# undef KEYM_START_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16
#endif
#ifdef KEYM_STOP_SEC_CONST_16
# undef KEYM_STOP_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef KEYM_START_SEC_CONST_32
# undef KEYM_START_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32
#endif
#ifdef KEYM_STOP_SEC_CONST_32
# undef KEYM_STOP_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef KEYM_START_SEC_CONST_UNSPECIFIED
# undef KEYM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef KEYM_STOP_SEC_CONST_UNSPECIFIED
# undef KEYM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NO_INIT sections */

#ifdef KEYM_START_SEC_VAR_NO_INIT_8
# undef KEYM_START_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_8
#endif
#ifdef KEYM_STOP_SEC_VAR_NO_INIT_8
# undef KEYM_STOP_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef KEYM_START_SEC_VAR_NO_INIT_16
# undef KEYM_START_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_16
#endif
#ifdef KEYM_STOP_SEC_VAR_NO_INIT_16
# undef KEYM_STOP_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef KEYM_START_SEC_VAR_NO_INIT_32
# undef KEYM_START_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_32
#endif
#ifdef KEYM_STOP_SEC_VAR_NO_INIT_32
# undef KEYM_STOP_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
#ifdef KEYM_START_SEC_VAR_CLEARED_8
# undef KEYM_START_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_CLEARED_8
#endif
#ifdef KEYM_STOP_SEC_VAR_CLEARED_8
# undef KEYM_STOP_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef KEYM_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef KEYM_START_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#ifdef KEYM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef KEYM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/***********************************************************************************************************************
 *  KEYM END
 **********************************************************************************************************************/

#ifdef DET_START_SEC_CODE
# undef DET_START_SEC_CODE                    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#ifdef DET_STOP_SEC_CODE
# undef DET_STOP_SEC_CODE                     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

#ifdef DET_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef DET_START_SEC_VAR_NOINIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DET_START_SEC_VAR_NOINIT_8BIT
# undef DET_START_SEC_VAR_NOINIT_8BIT         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef DET_STOP_SEC_VAR_NOINIT_8BIT
# undef DET_STOP_SEC_VAR_NOINIT_8BIT          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DET_START_SEC_VAR_INIT_UNSPECIFIED
# undef DET_START_SEC_VAR_INIT_UNSPECIFIED    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef DET_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef DET_STOP_SEC_VAR_INIT_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DET_START_SEC_CONST_UNSPECIFIED
# undef DET_START_SEC_CONST_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef DET_STOP_SEC_CONST_UNSPECIFIED
# undef DET_STOP_SEC_CONST_UNSPECIFIED        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/**********************************************************************************************************************
 *  WRAPNV START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SECM_RAMCODE_START_SEC_CODE
 #undef SECM_RAMCODE_START_SEC_CODE
 #define START_SEC_CODE                                              /* Mapped to default code section */
#endif

#ifdef SECM_RAMCODE_STOP_SEC_CODE
 #undef SECM_RAMCODE_STOP_SEC_CODE
 #define STOP_SEC_CODE                                               /* Default code stop section */
#endif

#ifdef SECM_START_SEC_CODE
 #undef SECM_START_SEC_CODE
 #define START_SEC_CODE                                              /* Mapped to default code section */
#endif

#ifdef SECM_STOP_SEC_CODE
 #undef SECM_STOP_SEC_CODE
 #define STOP_SEC_CODE                                               /* Default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef SECM_START_SEC_CONST
 #undef SECM_START_SEC_CONST
 #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef SECM_STOP_SEC_CONST
 #undef SECM_STOP_SEC_CONST
 #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef SECM_START_SEC_VAR
 #undef SECM_START_SEC_VAR
 #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef SECM_STOP_SEC_VAR
 #undef SECM_STOP_SEC_VAR
 #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  WRAPNV END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  EEP_30_HISEEPROM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef EEP_30_HISEEPROM_START_SEC_CODE
 #undef EEP_30_HISEEPROM_START_SEC_CODE
 #define START_SEC_CODE                                              /* Mapped to default code section */
#endif

#ifdef EEP_30_HISEEPROM_STOP_SEC_CODE
 #undef EEP_30_HISEEPROM_STOP_SEC_CODE
 #define STOP_SEC_CODE                                               /* Default code stop section */
#endif

/**********************************************************************************************************************
 *  EEP_30_HISEEPROM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  WRAPNV START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef WRAPNV_START_SEC_CODE
 #undef WRAPNV_START_SEC_CODE
 #define START_SEC_CODE                                              /* Mapped to default code section */
#endif

#ifdef WRAPNV_STOP_SEC_CODE
 #undef WRAPNV_STOP_SEC_CODE
 #define STOP_SEC_CODE                                               /* Default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef WRAPNV_START_SEC_CONST_UNSPECIFIED
 #undef WRAPNV_START_SEC_CONST_UNSPECIFIED
 #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef WRAPNV_STOP_SEC_CONST_UNSPECIFIED
 #undef WRAPNV_STOP_SEC_CONST_UNSPECIFIED
 #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef WRAPNV_START_SEC_VAR_NOINIT_UNSPECIFIED
 #undef WRAPNV_START_SEC_VAR_NOINIT_UNSPECIFIED
 #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef WRAPNV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
 #undef WRAPNV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
 #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  WRAPNV END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CANTP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef   CANTP_START_SEC_CODE
# undef  CANTP_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef   CANTP_STOP_SEC_CODE
# undef  CANTP_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE      /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef   CANTP_START_SEC_CONST_UNSPECIFIED
# undef  CANTP_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef   CANTP_STOP_SEC_CONST_UNSPECIFIED
# undef  CANTP_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef   CANTP_START_SEC_CONST_8BIT
# undef  CANTP_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif
#ifdef   CANTP_STOP_SEC_CONST_8BIT
# undef  CANTP_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef   CANTP_START_SEC_CONST_16BIT
# undef  CANTP_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef   CANTP_STOP_SEC_CONST_16BIT
# undef  CANTP_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* Postbuild CFG CONST sections */

#ifdef   CANTP_START_SEC_PBCFG
# undef  CANTP_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef   CANTP_STOP_SEC_PBCFG
# undef  CANTP_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif



/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef   CANTP_START_SEC_VAR_INIT_8BIT
# undef  CANTP_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT
#endif
#ifdef   CANTP_STOP_SEC_VAR_INIT_8BIT
# undef  CANTP_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef   CANTP_START_SEC_VAR_INIT_16BIT
# undef  CANTP_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef   CANTP_STOP_SEC_VAR_INIT_16BIT
# undef  CANTP_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef   CANTP_START_SEC_VAR_NOINIT_8BIT
# undef  CANTP_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef   CANTP_STOP_SEC_VAR_NOINIT_8BIT
# undef  CANTP_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef   CANTP_START_SEC_VAR_NOINIT_16BIT
# undef  CANTP_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef   CANTP_STOP_SEC_VAR_NOINIT_16BIT
# undef  CANTP_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef   CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef  CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef   CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef  CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef   CANTP_START_SEC_VAR_PBCFG
# undef  CANTP_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef   CANTP_STOP_SEC_VAR_PBCFG
# undef  CANTP_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif



/**********************************************************************************************************************
 *  CANTP END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VSTDLIB START
 *********************************************************************************************************************/

#if defined(VSTDLIB_START_SEC_CODE)
# undef VSTDLIB_START_SEC_CODE                             /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                    /* mapped to default code section */
#endif
#if defined(VSTDLIB_STOP_SEC_CODE)
# undef VSTDLIB_STOP_SEC_CODE                              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

#if defined(VSTDLIB_START_SEC_CONST_8BIT)
# undef VSTDLIB_START_SEC_CONST_8BIT                       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT                              /* mapped to const 8 bit section */
#endif
#if defined(VSTDLIB_STOP_SEC_CONST_8BIT)
# undef VSTDLIB_STOP_SEC_CONST_8BIT                        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST                                    /* default const stop section */
#endif

/**********************************************************************************************************************
 *  VSTDLIB END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETH_30_WRAPPER START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETH_30_WRAPPER_START_SEC_CODE
  #undef ETH_30_WRAPPER_START_SEC_CODE                        /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE                                                   /* mapped to default code section */
#endif

#ifdef ETH_30_WRAPPER_STOP_SEC_CODE
  #undef ETH_30_WRAPPER_STOP_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE                                                    /* default code stop section */
#endif

#ifdef ETHIF_30_WRAPPER_START_SEC_CODE
  #undef ETHIF_30_WRAPPER_START_SEC_CODE                        /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE                                                   /* mapped to default code section */
#endif

#ifdef ETHIF_30_WRAPPER_STOP_SEC_CODE
  #undef ETHIF_30_WRAPPER_STOP_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE                                                    /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef ETH_30_WRAPPER_START_SEC_CONST_8BIT
# undef ETH_30_WRAPPER_START_SEC_CONST_8BIT                   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT                                              /* mapped to default const 8bit section */
#endif

#ifdef ETH_30_WRAPPER_STOP_SEC_CONST_8BIT
# undef ETH_30_WRAPPER_STOP_SEC_CONST_8BIT                    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST                                                    /* default const stop section */
#endif

#ifdef ETH_30_WRAPPER_START_SEC_CONST_16BIT
# undef ETH_30_WRAPPER_START_SEC_CONST_16BIT                  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif

#ifdef ETH_30_WRAPPER_STOP_SEC_CONST_16BIT
# undef ETH_30_WRAPPER_STOP_SEC_CONST_16BIT                   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef ETH_30_WRAPPER_START_SEC_CONST_UNSPECIFIED
# undef ETH_30_WRAPPER_START_SEC_CONST_UNSPECIFIED            /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ETH_30_WRAPPER_STOP_SEC_CONST_UNSPECIFIED
# undef ETH_30_WRAPPER_STOP_SEC_CONST_UNSPECIFIED             /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef ETH_30_WRAPPER_START_SEC_VAR_NOINIT_8BIT
# undef ETH_30_WRAPPER_START_SEC_VAR_NOINIT_8BIT              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef ETH_30_WRAPPER_STOP_SEC_VAR_NOINIT_8BIT
# undef ETH_30_WRAPPER_STOP_SEC_VAR_NOINIT_8BIT               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef ETH_30_WRAPPER_START_SEC_VAR_NOINIT_16BIT
# undef ETH_30_WRAPPER_START_SEC_VAR_NOINIT_16BIT             /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef ETH_30_WRAPPER_STOP_SEC_VAR_NOINIT_16BIT
# undef ETH_30_WRAPPER_STOP_SEC_VAR_NOINIT_16BIT              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef ETH_30_WRAPPER_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETH_30_WRAPPER_START_SEC_VAR_NOINIT_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef ETH_30_WRAPPER_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETH_30_WRAPPER_STOP_SEC_VAR_NOINIT_UNSPECIFIED        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef ETH_30_WRAPPER_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETH_30_WRAPPER_START_SEC_VAR_ZERO_INIT_8BIT           /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif

#ifdef ETH_30_WRAPPER_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETH_30_WRAPPER_STOP_SEC_VAR_ZERO_INIT_8BIT            /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef ETH_30_WRAPPER_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETH_30_WRAPPER_START_SEC_VAR_ZERO_INIT_UNSPECIFIED    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef ETH_30_WRAPPER_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETH_30_WRAPPER_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETH_30_WRAPPER END
 *********************************************************************************************************************/


/* PRQA L:MEMMAP_0841_TAG */

#ifndef MEMMAP_REMAPPING_ONLY
# include "MemMap_Common.h"

/* MEMMAP_ERROR is
  - still defined if MemMap_Common.h did not contain a matching section
  - undefined, if MemMap_Common.h handled the section define. */
# ifdef MEMMAP_ERROR
/* contains all configured MemMap Sections */
#  include "MemMap_Compatibility.h" /* generated by module MemMap */
# endif

# ifdef MEMMAP_ERROR
#  error No MemMap section found in MemMap_Common.h and MemMap_Compatibility.h. Check your section define for validity.
# endif
#endif


/**********************************************************************************************************************
 *  END OF FILE: MemMap.h
 *********************************************************************************************************************/

