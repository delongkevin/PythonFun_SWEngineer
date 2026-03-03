/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2007 - 2013 by Vector Informatik GmbH.                                           All rights reserved.
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
 *         File:  _Compiler_Cfg.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This File is a template for the Compiler_Cfg.h
 *                This file has to be extended with the memory and pointer classes for all BSW modules
 *                which where used.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Joachim Kalmbach              Jk            Vector Informatik GmbH
 *  Heike Honert                  Ht            Vector Informatik GmbH
 *  Eugen Stripling               Seu           Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2007-08-01  Jk                    Initial creation
 *  01.01.00  2007-12-14  Jk                    Component specific defines filtering added
 *  01.01.01  2008-12-17  Ht                    Improve list of components  (Tp_AsrTpCan,Tp_AsrTpFr,DrvMcu,DrvIcu added)
 *  01.01.02  2009-04-27  Ht                    support OEM specific _compiler_cfg.inc file, improve list of components 
 *                                              (Cp_XcpOnCanAsr, Il_AsrIpduM, If_VxFblDcm, If_VxFblVpm_Volvo_ab, DrvFls added)
 *  01.01.03  2009-04-24  Msr                   Renamed J1939_AsrBase as TpJ1939_AsrBase
 *  01.01.04  2009-06-03  Ht                    Improve list of components (Adc, Dio, Gpt, Pwm, Spi, Wdg, Fls, Port, Fim)
 *  01.02.00  2009-08-01  Ht                    Improve list of components (Fee_30_Inst2, Can, ...Sub)
 *                                              Support filtering for RTE
 *  01.02.01  2009-09-02  Lo                    add external Flash driver support
 *  01.02.02  2009-09-21  Lo                    add DrvFls_Mcs12xFslftm01ExtVx
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
 *  01.03.02  2010-02-15  Ht                   support SysService_SswRcs_Daimler, SysService_Tls, Tp_Http, 
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
 *  01.05.04  2010-11-16  Ht                    add SysService_Exi, DrvTrans_Int6400EthAsr, Cdd_AsrCdd_Fiat, Diag_AsrDem_Fiat,
 *  01.05.05  2010-12-17  Ht                    add SysService_AsrSchM, DrvEep_XXStubAsr, DrvIcu_Tms570Tinhet01ExtVx
 *                                                  DrvWd_XTle4278gEAsr, DrvWd_XXStubAsr
 *  01.05.06  2011-02-17  Ht                    add DrvEed, SysService_AsrBswM
 *  01.05.07  2011-03-04  Ht                    add DrvTrans_Tja1055CandioAsr
 *                                              rename CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1040
 *                                              add SysService_XmlEngine
 *  01.06.00  2011-03-04  Ht                    support ASR4.0
 *                                              add Ccl_Asr4ComM, Ccl_Asr4SmCan, Nm_Asr4NmIf, Nm_AsrNmDirOsek
 *  01.06.01  2011-04-15  Ht                    add Diag_AsrDcm_<OEM>
 *  01.06.02  2011-06-17  Ht                    correct Diag_AsrDcm_<OEM>
 *                                              add Monitoring_AsrDlt and Monitoring_GenericMeasurement
 *  01.06.03  2011-09-01  Ht                    add DrvTrans_Tja1145CanSpiAsr, DrvTrans_E52013CanspiAsr, DrvFls_XXStubAsr,
 *                                              If_AsrIfFeeV85xNec05Sub, If_AsrIfFeeV85xNec06Sub, If_AsrIfFeeV85xNec07Sub
 *                                              SysService_AsrWdMTttechSub and If_AsrIfWdTttechSub
 *  01.06.04  2011-10-20  Ht                    ESCAN00054334: add If_AsrIfFeeTiSub
 *                                              ESCAN00054719: add Cdd_AsrCdd
 *  01.06.05  2011-12-09  Ht                    add Tp_IpV4, Tp_IpV6
 *  01.06.06  2011-12-14  Ht                    add Monitoring_RuntimeMeasurement
 *  01.06.07  2012-01-03  Ht                    add DrvI2c, SysService_Asr4BswM
 *  01.06.08  2012-01-31  Ht                    add DrvTrans_Ar7000EthAsr, DrvTrans_GenericEthmiiAsr
 *  01.06.09  2012-03-06  Ht                    add If_AsrIfFeeMb9df126Fuji01Sub, 
 *                                              Infineon_Tc1767Inf01Sub, Infineon_Tc178xInf01Sub, Infineon_Tc1797Inf01Sub, Infineon_Tc1797Inf02Sub
 *  01.06.10  2012-03-13  Ht                    add Gw_AsrPduRCfg5, Il_AsrComCfg5, Il_AsrIpduMCfg5, Cdd_AsrCddCfg5,
 *                                              Tp_Asr4TpCan, Diag_Asr4Dcm, Diag_Asr4Dem
 *  01.06.11  2012-03-20  Ht                    add Cp_AsrCcp, Cp_XcpOnTcpIpAsr
 *  01.07.00  2012-07-26  Ht                    add Nm_Asr4NmCan, Nm_Asr4NmFr, Infineon_Xc2000Inf01Sub, Ccl_Asr4ComMCfg5, SysService_Asr4BswMCfg5, SysService_Asr4EcuM, SysService_AsrRamTst,
 *                                                  Ccl_Asr4SmLin
 *                                              add define REGSPACE - add support for ASR specification 4.0 R3
 *  01.07.01  2012-10-23  Seu                   add SysService_XmlSecurity
 *  01.07.02  2013-12-16  Seu                   MISRA compliance: usage of character "'" removed, typos corrected
 *********************************************************************************************************************/
#ifndef COMPILER_CFG_H
#define COMPILER_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
/* Package Merger: Start Section CompilerCfgIncludes */


#include "Rte_Compiler_Cfg.h"

/* Package Merger: Stop Section CompilerCfgIncludes */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define AUTOSAR_COMSTACKDATA

#define MSR_REGSPACE  REGSPACE

/* Configurable memory class for pointers to registers (e.g. static volatile CONSTP2VAR(uint16, PWM_CONST, REGSPACE)). */
#define REGSPACE


/* due to compatibility to ASR 2.1 */
#define _STATIC_   STATIC
#define _INLINE_   INLINE

/* Package Merger: Start Section CompilerCfgModuleList */



/**********************************************************************************************************************
 *  COMM START 
 *********************************************************************************************************************/

#define COMM_CODE

#define COMM_CONST
#define COMM_PBCFG

#define COMM_VAR_NO_INIT
#define COMM_VAR_PBCFG
#define COMM_VAR_CLEARED

#define COMM_APPL_VAR
#define COMM_NVM_DATA
#define COMM_NVM_DATA_NO_INIT

/**********************************************************************************************************************
 *  COMM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CanSM START
 *********************************************************************************************************************/

#define CANSM_CODE

#define CANSM_CONST


#define CANSM_APPL_CODE

#define CANSM_VAR_NOINIT
#define CANSM_VAR_ZERO_INIT

#define CANSM_APPL_VAR


/*******  FAST sections **********************************************************************************************/

#define CANSM_CONST_FAST

#define CANSM_VAR_NOINIT_FAST
#define CANSM_VAR_ZERO_INIT_FAST


/**********************************************************************************************************************
 *  CanSM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHSM START 
 *********************************************************************************************************************/

#define ETHSM_CODE

#define ETHSM_CONST
#define ETHSM_APPL_CONST
#define ETHSM_PBCFG
#define ETHSM_APPL_DATA

#define ETHSM_VAR_NOINIT
#define ETHSM_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  ETHSM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CddFiat START 
 *********************************************************************************************************************/

#define CDDFIAT_CODE
#define CDDFIAT_VAR
#define CDDFIAT_APPL_CODE
#define CDDFIAT_VAR_NOINIT
#define CDDFIAT_VAR_ZERO_INIT
#define CDDFIAT_CONST
#define CDDFIAT_COM_APPL_DATA
#define CDDFIAT_APPL_VAR
#define CDDFIAT_PBCFG

/**********************************************************************************************************************
 *  CddFiat END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  Cdd_AsrCdd START 
 *********************************************************************************************************************/

/* Copy the compiler abstraction defines for each of your configured CDDs and replace the prefix _CDD with the MSN of your configured CDD as higher case. */

#define _CDD_CODE
#define _CDD_APPL_DATA

/* Add additional compiler abstraction defines for each of you configured CDDs here. */

/**********************************************************************************************************************
 *  Cdd_AsrCdd END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  XCP START 
 *********************************************************************************************************************/

#define XCP_CODE
#define XCP_CONST
#define XCP_PBCFG

#define XCP_VAR_INIT
#define XCP_VAR_NOINIT
#define XCP_VAR_ZERO_INIT
#define XCP_VAR_NOINIT_NOCACHE
#define XCP_APPL_DATA
#define XCP_APPL_VAR



/**********************************************************************************************************************
 *  XCP END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CANXCP START 
 *********************************************************************************************************************/

#define CANXCP_VAR_INIT
#define CANXCP_VAR_NOINIT
#define CANXCP_CONST
#define CANXCP_PBCFG
#define CANXCP_CODE
#define CANXCP_APPL_VAR

/*-------------------------------------------------------------------------------------------------------------------*/
/* CANXCP END                                                                                                        */
/*-------------------------------------------------------------------------------------------------------------------*/



/**********************************************************************************************************************
 *  TCPIPXCP START 
 *********************************************************************************************************************/

#define TCPIPXCP_VAR_NOINIT
#define TCPIPXCP_VAR_INIT
#define TCPIPXCP_CONST
#define TCPIPXCP_PBCFG
#define TCPIPXCP_CODE
#define TCPIPXCP_APPL_VAR
#define TCPIPXCP_APPL_DATA

/**********************************************************************************************************************
 *  TCPIPXCP END 
 *********************************************************************************************************************/


#define DCM_CODE                /* code */
#define DCM_CONST               /* global/static constants */
#define DCM_CAL_PRM             /* calibrateable constants */
#define DCM_APPL_CODE           /* callback functions outside of Dcm */
#define DCM_APPL_CONST          /* constants outside Dcm */ 
#define DCM_APPL_DATA           /* variables/buffers outside of Dcm */
#define DCM_CALLOUT_CODE        /* callback functions outside of Dcm but part of Dcm (callouts) */
#define DCM_VAR_INIT            /* initialized global/static variables */
#define DCM_VAR_NOINIT          /* uninitialized global/static variables */
#define DCM_VAR_PBCFG           /* global/static variable for PostBuildLoadable */
#define DCM_PBCFG               /* global/static constants for PostBuildLoadable */



/*==== DEM ==================================================================*/
#define DEM_CODE                /* code */
#define DEM_VAR_INIT            /* initialized global/static variables */
#define DEM_VAR_ZERO_INIT       /* initialized global/static variables with initialization value 0 */
#define DEM_VAR_NOINIT          /* uninitialized global/static variables */
#define DEM_VAR_UNCACHED        /* uninitialized global/static un-cached variables */
#define DEM_CONST               /* global/static constants */
#define DEM_CONST_ROOT          /* global/static constants */
#define DEM_PBCFG               /* global/static constants for PostBuild */
#define DEM_PBCFG_ROOT          /* global/static constants for PostBuild */
#define DEM_VAR_PBCFG           /* post-buildable RAM */
#define DEM_DCM_DATA            /* variables/buffers passed by Dcm to Dem */
#define DEM_J1939DCM_DATA       /* variables/buffers passed by J1939Dcm to Dem */
#define DEM_DLT_DATA            /* variables/buffers passed by Dlt to Dem */
#define DEM_NVM_DATA            /* variables/buffers managed by NvM */
#define DEM_APPL_CODE           /* callback functions outside of Dem */
#define DEM_APPL_DATA           /* variables/buffers outside of Dem */
#define DEM_APPL_CONST          /* constants outside Dem */
#define DEM_SHARED_DATA         /* variables/buffers shared by all */
#define DEM_CAL_PRM             /* calibrateable constants */
#define DEM_NVM_DATA_NOINIT     DEM_NVM_DATA
#define DEM_VAR_SATELLITE       /* variables/buffers of Dem satellites */
/*===========================================================================*/


/*==== VDEM42 ================================================================*/
#define VDEM42_CODE             /* code */
#define VDEM42_APPL_DATA        /* data variables/buffers outside of VDEM42 */
#define VDEM42_APPL_VAR         /* variables/buffers outside of VDEM42 */
/*============================================================================*/



/**********************************************************************************************************************
 *  VDAM START
 *********************************************************************************************************************/

#define VDAM_CODE
#define VDAM_APPL_CODE
#define VDAM_CALLOUT_CODE
#define VDAM_DCM_CALLOUT_CODE

#define VDAM_CONST
#define VDAM_VAR_CLEARED
#define VDAM_VAR_NO_INIT

#define VDAM_APPL_VAR
#define VDAM_APPL_DATA
#define VDAM_APPL_CONST
#define VDAM_DCM_VAR

#define VDAM_PBCFG

/**********************************************************************************************************************
 *  VDAM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  VDIAGSECACC START
 *********************************************************************************************************************/

#define VDIAGSECACC_CODE
#define VDIAGSECACC_DCM_CALLOUT_CODE

#define VDIAGSECACC_CONST
#define VDIAGSECACC_VAR_ZERO_INIT
#define VDIAGSECACC_VAR_NOINIT

#define VDIAGSECACC_APPL_VAR
#define VDIAGSECACC_APPL_DATA
#define VDIAGSECACC_DCM_VAR

/**********************************************************************************************************************
 *  VDIAGSECACC END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vRoE_Compiler_Cfg.inc
 *        \brief  vRoE CompilerConfiguration file
 *********************************************************************************************************************/

/* Used for vRoE specific code */
#define VROE_CODE

/* Used for all vRoE specific variables that are initialized by the startup code of the compiler */
#define VROE_VAR_CLEARED

/* Used for global or static vRoE specific constants */
#define VROE_CONST

/* Used for all vRoE specific variables that are not initialized by the startup code of the compiler */
#define VROE_VAR_NOINIT

/* Used for references on application data (constants or variables) */
#define VROE_APPL_DATA

/**********************************************************************************************************************
 *  END OF FILE: vRoE_Compiler_Cfg.inc
 *********************************************************************************************************************/


/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 697 */

/*        STARTSINGLE_OF_MULTIPLE_COMMENT      */


/**********************************************************************************************************************
 *  Can START    DRVCAN_MPC5700MCANASR
 *********************************************************************************************************************/

#define CAN_30_MCAN_CODE                                   /* CAN modules code qualifier               */ /* PRQA S 0883 */ /* Appears only while testing */
#define CAN_30_MCAN_STATIC_CODE                            /* CAN local code qualifier                 */
#define CAN_30_MCAN_CONST                                  /* constant memory                          */
#define CAN_30_MCAN_CONST_PBCFG                            /* postbuild generated constant/flash       */
#define CAN_30_MCAN_VAR_NOINIT                             /* none initialized variables               */
#define CAN_30_MCAN_VAR_INIT                               /* initialized variables                    */
#define CAN_30_MCAN_VAR_PBCFG                              /* postbuild generated variables/dynamic RAM (CFG5 only) */
#define CAN_30_MCAN_INT_CTRL                               /* access to Interrupt controller registers */
#define CAN_30_MCAN_REG_CANCELL                            /* CAN cell register qualifier              */
#define CAN_30_MCAN_RX_TX_DATA                             /* pointer width >= CAN_30_MCAN_REG_CANCELL  / CAN rx/tx data / RAM or SFR    (rx data pointer for Indication and PreCopy functions to higher layers / tx data pointers / sdu  from application)   */
#define CAN_30_MCAN_APPL_CODE                              /* Application code qualifier               */
#define CAN_30_MCAN_APPL_CONST                             /* Application constant memory              */
#define CAN_30_MCAN_APPL_VAR                               /* Application variables                    */
#define CAN_30_MCAN_VAR_FAR                                /* far local variable qualifier */
#define CAN_30_MCAN_VAR_NEAR                               /* near local variable qualifier */

#define CAN_30_MCAN_PBCFG  CAN_30_MCAN_CONST_PBCFG       /* used for compatibility (used by upper layer EcuM) */

/**********************************************************************************************************************
 *  Can END    DRVCAN_MPC5700MCANASR
 *********************************************************************************************************************/

/*  STOPSINGLE_OF_MULTIPLE_COMMENT  */
/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 697 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 697 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 697 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 697 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 697 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 697 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 697 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 697 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 697 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 697 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 697 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 697 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 697 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 697 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 697 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 697 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 697 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 697 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCan_Arm32Mcan Erzeugungsgangnummer: 697 */



/**********************************************************************************************************************
 *  CRYPTO_30_VHSM START
 *********************************************************************************************************************/

#define CRYPTO_30_VHSM_CODE
#define CRYPTO_30_VHSM_APPL_CODE
#define CRYPTO_30_VHSM_CONST

#define CRYPTO_30_VHSM_VAR_NOINIT
#define CRYPTO_30_VHSM_VAR_INIT
#define CRYPTO_30_VHSM_VAR_ZERO_INIT
#define CRYPTO_30_VHSM_APPL_VAR
#define CRYPTO_30_VHSM_APPL_DATA

/**********************************************************************************************************************
 *  CRYPTO_30_VHSM END
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  EEP_30_XXI2C01 START
 *********************************************************************************************************************/

#define EEP_30_XXI2C01_CODE
#define EEP_30_XXI2C01_APPL_CODE
#define EEP_30_XXI2C01_CONST
#define EEP_30_XXI2C01_PBCFG
#define EEP_30_XXI2C01_VAR_NO_INIT
#define EEP_30_XXI2C01_VAR_INIT
#define EEP_30_XXI2C01_APPL_DATA

/**********************************************************************************************************************
 *  EEP_30_XXI2C01 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  EEP_30_VMEMACCM START
 *********************************************************************************************************************/

#define EEP_30_VMEMACCM_CODE
#define EEP_30_VMEMACCM_APPL_VAR
#define EEP_30_VMEMACCM_VAR_INIT

/**********************************************************************************************************************
 *  EEP_30_VMEMACCM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  FLS_30_VMEMACCM START
 *********************************************************************************************************************/

#define FLS_30_VMEMACCM_CODE
#define FLS_30_VMEMACCM_CONST
#define FLS_30_VMEMACCM_VAR


#define FLS_30_VMEMACCM_APPL_VAR /* use for user data buffers located in RAM */



/**********************************************************************************************************************
 *  FLS_30_VMEMACCM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  I2C START
 *********************************************************************************************************************/
#define I2C_CODE
#define I2C_PRIVATE_CODE
#define I2C_VAR
#define I2C_CONST
#define I2C_PBCFG
#define I2C_VAR_NO_INIT
#define I2C_VAR_INIT

/**********************************************************************************************************************
 *  I2C END
 *********************************************************************************************************************/



/***********************************************************************************************************************
 *  VMEM START
 **********************************************************************************************************************/

#define VMEM_30_BLOCKING_CODE
#define VMEM_30_BLOCKING_CONST
#define VMEM_30_BLOCKING_VAR
#define VMEM_30_BLOCKING_APPL_VAR
#define VMEM_30_BLOCKING_APPL_CONST
#define VMEM_30_BLOCKING_APPL_CODE

/***********************************************************************************************************************
 *  VMEM END
 **********************************************************************************************************************/



/***********************************************************************************************************************
 *  VMEM_30_EEP START
 **********************************************************************************************************************/

#define VMEM_30_EEP_CODE
#define VMEM_30_EEP_CONST
#define VMEM_30_EEP_APPL_VAR
#define VMEM_30_EEP_VAR_ZERO_INIT
#define VMEM_30_EEP_PBCFG
#define VMEM_30_EEP_VAR

/***********************************************************************************************************************
 *  VMEM_30_EEP END
 **********************************************************************************************************************/


#if !defined ( VMEM_30_FLS_COMPILER_CFG_INC )
#define VMEM_30_FLS_COMPILER_CFG_INC


/***********************************************************************************************************************
 *  VMEM_30_FLS START
 **********************************************************************************************************************/

#define VMEM_30_FLS_CODE
#define VMEM_30_FLS_CONST
#define VMEM_30_FLS_APPL_VAR
#define VMEM_30_FLS_VAR_ZERO_INIT

/***********************************************************************************************************************
 *  VMEM_30_FLS END
 **********************************************************************************************************************/
#endif /* VMEM_30_FLS_COMPILER_CFG_INC */



/***********************************************************************************************************************
 *  VMEM_30_MMFLASHRO START
 **********************************************************************************************************************/

#define VMEM_30_MMFLASHRO_CODE
#define VMEM_30_MMFLASHRO_CONST
#define VMEM_30_MMFLASHRO_APPL_VAR
#define VMEM_30_MMFLASHRO_VAR_ZERO_INIT
#define VMEM_30_MMFLASHRO_VAR_NOINIT
#define VMEM_30_MMFLASHRO_PBCFG

/***********************************************************************************************************************
 *  VMEM_30_MMFLASHRO END
 **********************************************************************************************************************/



/***********************************************************************************************************************
 *  VMEM_30_XXRAM START
 **********************************************************************************************************************/

#define VMEM_30_XXRAM_CODE
#define VMEM_30_XXRAM_CONST
#define VMEM_30_XXRAM_APPL_VAR
#define VMEM_30_XXRAM_VAR_ZERO_INIT
#define VMEM_30_XXRAM_VAR_INIT
#define VMEM_30_XXRAM_PBCFG
#define VMEM_30_XXRAM_VAR
/***********************************************************************************************************************
 *  VMEM_30_XXRAM END
 **********************************************************************************************************************/



/***********************************************************************************************************************
 *  VMEM_30_VXSPI_NAND START
 **********************************************************************************************************************/

#define VMEM_30_VXSPI_NAND_CODE
#define VMEM_30_VXSPI_NAND_CODE
#define VMEM_30_VXSPI_NAND_CONST
#define VMEM_30_VXSPI_NAND_VAR
#define VMEM_30_VXSPI_NAND_VAR_NOINIT
#define VMEM_30_VXSPI_NAND_APPL_VAR
#define VMEM_30_VXSPI_NAND_VAR_ZERO_INIT
#define VMEM_30_VXSPI_NAND_PBCFG

/***********************************************************************************************************************
 *  VMEM_30_VXSPI_NAND END
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHTRCV_30_DP83TC811 START 
 *********************************************************************************************************************/

#define ETHTRCV_30_DP83TC811_CODE
#define ETHTRCV_30_DP83TC811_CODE_INLINE
#define ETHTRCV_30_DP83TC811_CODE_FAST
#define ETHTRCV_30_DP83TC811_CODE_ISR

#define ETHTRCV_30_DP83TC811_CONST
#define ETHTRCV_30_DP83TC811_CONST_FAST
#define ETHTRCV_30_DP83TC811_PBCFG


#define ETHTRCV_30_DP83TC811_PBCFG_ROOT

#define ETHTRCV_30_DP83TC811_VAR_PBCFG

#define ETHTRCV_30_DP83TC811_APPL_VAR
#define ETHTRCV_30_DP83TC811_APPL_CONST
#define ETHTRCV_30_DP83TC811_APPL_CODE
#define ETHTRCV_30_DP83TC811_APPL_DATA
#define ETHTRCV_30_DP83TC811_VAR_NOINIT
#define ETHTRCV_30_DP83TC811_VAR_ZERO_INIT
#define ETHTRCV_30_DP83TC811_VAR_INIT_FAST
#define ETHTRCV_30_DP83TC811_VAR_NOINIT_FAST
#define ETHTRCV_30_DP83TC811_VAR_ZERO_INIT_FAST

#define ETHTRCV_30_DP83TC811_VAR_INIT_NOCACHE
#define ETHTRCV_30_DP83TC811_VAR_NOINIT_NOCACHE
#define ETHTRCV_30_DP83TC811_VAR_ZERO_INIT_NOCACHE

/**********************************************************************************************************************
 *  ETHTRCV_30_DP83TC811 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CANTRCV_30_GENERICCAN START 
 *********************************************************************************************************************/

#define CANTRCV_30_GENERICCAN_CODE
#define CANTRCV_30_GENERICCAN_CODE_FAST
#define CANTRCV_30_GENERICCAN_CODE_ISR

#define CANTRCV_30_GENERICCAN_CONST
#define CANTRCV_30_GENERICCAN_CONST_FAST
#define CANTRCV_30_GENERICCAN_PBCFG

#define CANTRCV_30_GENERICCAN_VAR_PBCFG /* ESCAN00065502 */

#define CANTRCV_30_GENERICCAN_VAR_INIT
#define CANTRCV_30_GENERICCAN_VAR_NOINIT
#define CANTRCV_30_GENERICCAN_APPL_VAR
#define CANTRCV_30_GENERICCAN_APPL_CODE
#define CANTRCV_30_GENERICCAN_VAR_ZERO_INIT
#define CANTRCV_30_GENERICCAN_VAR_INIT_FAST
#define CANTRCV_30_GENERICCAN_VAR_NOINIT_FAST
#define CANTRCV_30_GENERICCAN_VAR_ZERO_INIT_FAST

#define CANTRCV_30_GENERICCAN_VAR_INIT_NOCACHE
#define CANTRCV_30_GENERICCAN_VAR_NOINIT_NOCACHE
#define CANTRCV_30_GENERICCAN_VAR_ZERO_INIT_NOCACHE



/**********************************************************************************************************************
 *  CANTRCV_30_GENERICCAN END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */


/**********************************************************************************************************************
 *  CANTRCV_30_TJA1043 START 
 *********************************************************************************************************************/

#define CANTRCV_30_TJA1043_CODE
#define CANTRCV_30_TJA1043_CODE_FAST
#define CANTRCV_30_TJA1043_CODE_ISR

#define CANTRCV_30_TJA1043_CONST
#define CANTRCV_30_TJA1043_CONST_FAST
#define CANTRCV_30_TJA1043_PBCFG

#define CANTRCV_30_TJA1043_VAR_PBCFG /* ESCAN00065502 */

#define CANTRCV_30_TJA1043_VAR_INIT
#define CANTRCV_30_TJA1043_VAR_NOINIT
#define CANTRCV_30_TJA1043_APPL_VAR
#define CANTRCV_30_TJA1043_APPL_CODE
#define CANTRCV_30_TJA1043_VAR_ZERO_INIT
#define CANTRCV_30_TJA1043_VAR_INIT_FAST
#define CANTRCV_30_TJA1043_VAR_NOINIT_FAST
#define CANTRCV_30_TJA1043_VAR_ZERO_INIT_FAST

#define CANTRCV_30_TJA1043_VAR_INIT_NOCACHE
#define CANTRCV_30_TJA1043_VAR_NOINIT_NOCACHE
#define CANTRCV_30_TJA1043_VAR_ZERO_INIT_NOCACHE



/**********************************************************************************************************************
 *  CANTRCV_30_TJA1043 END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */


/**********************************************************************************************************************
 *  VXSPI START 
 *********************************************************************************************************************/

#define VXSPI_CODE
#define VXSPI_CODE_FAST
#define VXSPI_CODE_ISR

#define VXSPI_CONST
#define VXSPI_CONST_FAST
#define VXSPI_CFG
#define VXSPI_VAR_PBCFG

#define VXSPI_VAR_ZERO_INIT
#define VXSPI_VAR
#define VXSPI_APPL_CONST
#define VXSPI_APPL_VAR

#define VXSPI_VAR_INIT
#define VXSPI_VAR_NOINIT
#define VXSPI_VAR_CLEARED

#define VXSPI_VAR_INIT_FAST
#define VXSPI_VAR_NOINIT_FAST
#define VXSPI_VAR_CLEARED_FAST

#define VXSPI_VAR_INIT_NOCACHE
#define VXSPI_VAR_NOINIT_NOCACHE
#define VXSPI_VAR_CLEARED_NOCACHE

/**********************************************************************************************************************
 *  VXSPI END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  EcuAb_AsrIoHwAb START
 *********************************************************************************************************************/

#define IOHWAB_CODE

#define IOHWAB_VAR

#define IOHWAB_APPL_DATA
#define IOHWAB_APPL_CODE

#define IOHWAB_CONST

/**********************************************************************************************************************
 *  EcuAb_AsrIoHwAb END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  PDUR START 
 *********************************************************************************************************************/

#define PDUR_CODE
#define PDUR_VAR_NO_INIT
#define PDUR_VAR_CLEARED
#define PDUR_VAR
#define PDUR_CONST
#define PDUR_PBCFG
#define PDUR_VAR_PBCFG
#define PDUR_APPL_DATA
#define PDUR_APPL_CODE

/**********************************************************************************************************************
 *  PDUR END
 *********************************************************************************************************************/



/***********************************************************************************************************************
 *  MIRROR START 
 **********************************************************************************************************************/

#define MIRROR_CODE

#define MIRROR_CONST
#define MIRROR_APPL_VAR

#define MIRROR_APPL_DATA
#define MIRROR_APPL_CODE
#define MIRROR_VAR_ZERO_INIT
#define MIRROR_VAR_NOINIT
#define MIRROR_VAR_PBCFG
#define MIRROR_PBCFG

/***********************************************************************************************************************
 *  MIRROR END
 **********************************************************************************************************************/



/**********************************************************************************************************************
 *  If_Asr4IfWd START
 *********************************************************************************************************************/

#define WDGIF_CODE
#define WDGIF_CONST
#define WDGIF_VAR
#define WDGIF_APPL_DATA
#define WDGIF_APPL_CONST

/**********************************************************************************************************************
 *  If_Asr4IfWd END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CANIF START 
 *********************************************************************************************************************/

#define CANIF_CODE
#define CANIF_CODE_FAST
#define CANIF_CODE_ISR


#define CANIF_CONST
#define CANIF_CONST_FAST
#define CANIF_PBCFG

#define CANIF_VAR_PBCFG /* ESCAN00065502 */

#define CANIF_VAR_INIT
#define CANIF_VAR_NOINIT
#define CANIF_VAR_ZERO_INIT

#define CANIF_VAR_INIT_FAST
#define CANIF_VAR_NOINIT_FAST
#define CANIF_VAR_ZERO_INIT_FAST

#define CANIF_VAR_INIT_NOCACHE
#define CANIF_VAR_NOINIT_NOCACHE
#define CANIF_VAR_ZERO_INIT_NOCACHE


#define CANIF_APPL_CODE
#define CANIF_APPL_VAR
#define CANIF_APPL_PBCFG


/*-------------------------------------------------------------------------------------------------------------------*/

/* Has to be kept in default section -> Default access */
#define CANIF_VAR_STACK


/* VAR section of higher layers (TP / NM / PduR / CanSM / EcuM) automatically mapped to APPL_VAR */
#define CANIF_APPL_STATE_VAR   CANIF_APPL_VAR
#define CANIF_APPL_MSG_VAR     CANIF_APPL_VAR

/* VAR section of lower layers (CAN Driver / Transceiver Driver) automatically mapped to APPL_VAR */
#define CANIF_CBK_VAR          CANIF_APPL_VAR

/* #define CANIF_CBK_TRCV_VAR     CANIF_CBK_VAR    not used yet */
#define CANIF_CBK_DRV_VAR      CANIF_CBK_VAR

/* Code sections - DO NOT MODIFY */
#define CANIF_CBK_TRCV_CODE     CANIF_APPL_CODE
#define CANIF_CBK_CANDRV_CODE   CANIF_APPL_CODE
#define CANIF_APPL_STATE_CODE   CANIF_APPL_CODE
#define CANIF_APPL_MSG_CODE     CANIF_APPL_CODE


/* Upper layer data pointer */
#define CANIF_UL_STANDARD_VAR    CANIF_APPL_VAR
#define CANIF_UL_ADVANCED_VAR    CANIF_APPL_VAR
#define CANIF_UL_OSEKNM_VAR      CANIF_APPL_VAR

/**********************************************************************************************************************
 *  CANIF END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CRYIF START
 *********************************************************************************************************************/

#define CRYIF_CODE
#define CRYIF_CONST

#define CRYIF_VAR_ZERO_INIT
#define CRYIF_APPL_VAR
#define CRYIF_APPL_DATA

/**********************************************************************************************************************
 *  CRYIF END
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  If_AsrIfEa START 
 *********************************************************************************************************************/

#define EA_PUBLIC_CODE
#define EA_PRIVATE_CODE

#define EA_APPL_DATA
#define EA_FAST_DATA

#define EA_PRIVATE_CONST
#define EA_PUBLIC_CONST

#define EA_NVM_CODE

/* In ASR4 SchM/RTE declares Ea_MainFunction, using EA_CODE *
 * It MUST be defined to EA_PUBLIC_CODE!                     */
#define EA_CODE EA_PUBLIC_CODE

/**********************************************************************************************************************
 *  If_AsrIfEa END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHIF START 
 *********************************************************************************************************************/

#define ETHIF_CODE
#define ETHIF_CODE_ISR
#define ETHIF_ETHCTRL_INLINE_CODE
#define ETHIF_ETHTRCV_INLINE_CODE
#define ETHIF_ETHSWT_INLINE_CODE
#define ETHIF_GW_INLINE_CODE
#define ETHIF_LINK_INLINE_CODE
#define ETHIF_MIRROR_INLINE_CODE
#define ETHIF_MODE_INLINE_CODE
#define ETHIF_RX_INLINE_CODE
#define ETHIF_STATS_INLINE_CODE
#define ETHIF_TX_INLINE_CODE
#define ETHIF_UTILS_INLINE_CODE
#define ETHIF_ZEROCOPY_INLINE_CODE

#define ETHIF_CONST

#define ETHIF_APPL_VAR
#define ETHIF_APPL_DATA
#define ETHIF_APPL_CODE

#define ETHIF_VAR_NO_INIT
#define ETHIF_VAR_NO_INIT_FAST

#define ETHIF_VAR_INIT

/**********************************************************************************************************************
 *  ETHIF END
 *********************************************************************************************************************/


#define MEMIF_CODE
#define MEMIF_PRIVATE_CODE
#define MEMIF_CONST
#define MEMIF_APPL_DATA


/**********************************************************************************************************************
 *  SOAD START 
 *********************************************************************************************************************/

#define SOAD_CODE

#define SOAD_APPL_DATA
#define SOAD_APPL_VAR

#define SOAD_CONST
#define SOAD_PBCFG

#define SOAD_VAR_NO_INIT
#define SOAD_VAR_CLEARED
#define SOAD_VAR_PBCFG

/**********************************************************************************************************************
 *  SOAD END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  FEE_30_FLEXNOR START 
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_CODE

#define FEE_30_FLEXNOR_VAR

#define FEE_30_FLEXNOR_CONST
#define FEE_30_FLEXNOR_PBCFG
#define FEE_30_FLEXNOR_VAR_PBCFG

#define FEE_30_FLEXNOR_VAR_INIT
#define FEE_30_FLEXNOR_VAR_NOINIT
#define FEE_30_FLEXNOR_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  FEE_30_FLEXNOR END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  FEE_30_FLEXNOR START 
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_CODE

#define FEE_30_FLEXNOR_VAR

#define FEE_30_FLEXNOR_CONST
#define FEE_30_FLEXNOR_PBCFG
#define FEE_30_FLEXNOR_VAR_PBCFG

#define FEE_30_FLEXNOR_VAR_INIT
#define FEE_30_FLEXNOR_VAR_NOINIT
#define FEE_30_FLEXNOR_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  FEE_30_FLEXNOR END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VFEEACC START 
 *********************************************************************************************************************/

#define VFEEACC_CODE
#define VFEEACC_APPL_CODE
#define VFEEACC_APPL_DATA
#define VFEEACC_CONST
#define VFEEACC_PRIVATE_CODE
#define VFEEACC_PRIVATE_CONST
#define VFEEACC_PRIVATE_DATA

/**********************************************************************************************************************
 *  VFEEACC END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  VMEMACCM START
 *********************************************************************************************************************/

#define VMEMACCM_CODE

#define VMEMACCM_CONST

#define VMEMACCM_VMEM_CODE
#define VMEMACCM_VMEM_CONST

#define VMEMACCM_APPL_VAR /* use for user data buffers located in RAM */

#define VMEMACCM_VAR_INIT
#define VMEMACCM_VAR_NOINIT
#define VMEMACCM_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  VMEMACCM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  Com START 
 *********************************************************************************************************************/

/* Module Constant Data */
#define COM_CONST
/* Module Constant Data of the Postbuild Configuration */
#define COM_PBCFG
/* Module Var Data of the Postbuild Configuration */
#define COM_VAR_PBCFG


/* Module Implementation */
#define COM_CODE

/* Module Variables which are initialized by the startup code or by the call of Com_InitMemory() */
#define COM_VAR_NO_INIT
/* Module Variables which are initialized by call of Com_Init() */
#define COM_VAR_CLEARED
/* Module Variables which are initialized by call of Com_Init() */
#define COM_VAR_INIT

/* Application Code Implementation (e.g. Callbacks) */
#define COM_APPL_CODE
/* Application Buffer which is located in RAM */
#define COM_APPL_VAR
/* Application Buffer which is located in ROM or RAM */
#define COM_APPL_DATA

/**********************************************************************************************************************
 *  Com END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  IpduM START 
 *********************************************************************************************************************/

#define IPDUM_CODE
#define IPDUM_CONST
#define IPDUM_PBCFG
#define IPDUM_VAR_PBCFG
#define IPDUM_VAR_INIT
#define IPDUM_VAR_CLEARED
#define IPDUM_VAR_NO_INIT
#define IPDUM_APPL_DATA

/**********************************************************************************************************************
 *  IpduM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  LDCOM START
 *********************************************************************************************************************/
/* Module Implementation */
#define LDCOM_CODE

/* Module Constant Data */
#define LDCOM_CONST
/* Module Constant Data of the Postbuild Configuration */
#define LDCOM_PBCFG
/* Module Var Data of the Postbuild Configuration */
#define LDCOM_VAR_PBCFG

/* Module Variables which are initialized by call of LdCom_Init() */
#define LDCOM_VAR_INIT
/* Module Variables which are initialized by the startup code or by the call of LdCom_InitMemory() */
#define LDCOM_VAR_NOINIT
/* Module Variables which are initialized by call of LdCom_Init() */
#define LDCOM_VAR_ZERO_INIT

/* Application Code Implementation (e.g. Callbacks) */
#define LDCOM_APPL_CODE
/* Application Buffer which is located in RAM */
#define LDCOM_APPL_VAR
/* Application Buffer which is located in ROM or RAM */
#define LDCOM_APPL_DATA

/**********************************************************************************************************************
 *  LDCOM END
 *********************************************************************************************************************/




 /* virelt: needed for the integration of the Eth wrapper (Eth_30_Generic) */
/* #include "Eth_30_Generic_Compiler_Cfg.h"	*/
/** \brief Dummy defines for MCU Build */
#define ADC_CONFIG_DATA_SECTION_NON_CONST
#define ADC_CONFIG_DATA_SECTION_CONST
#define ADC_VAR_CONST_8_SECTION
#define ADC_VAR_CONST_16_SECTION
#define ADC_VAR_CONST_32_SECTION
#define ADC_VAR_CONST_PTR_SECTION
#define ADC_VAR_CONST_UNSPECIFIED_SECTION
#define ADC_VAR_DATA_NO_INIT_8_SECTION
#define ADC_VAR_DATA_NO_INIT_16_SECTION
#define ADC_VAR_DATA_NO_INIT_32_SECTION
#define ADC_VAR_DATA_NO_INIT_PTR_SECTION
#define ADC_VAR_DATA_NO_INIT_UNSPECIFIED_SECTION
#define ADC_VAR_DATA_INIT_8_SECTION
#define ADC_VAR_DATA_INIT_16_SECTION
#define ADC_VAR_DATA_INIT_32_SECTION
#define ADC_VAR_DATA_INIT_PTR_SECTION
#define ADC_VAR_DATA_INIT_UNSPECIFIED_SECTION
#define ADC_FUNC_TEXT_SECTION
#define ADC_ISR_TEXT_SECTION
#define ADC_FUNC_CALLOUT_TEXT_SECTION

#define CDD_IPC_CONFIG_DATA_SECTION
#define CDD_IPC_VAR_CONST_8_SECTION
#define CDD_IPC_VAR_CONST_16_SECTION
#define CDD_IPC_VAR_CONST_32_SECTION
#define CDD_IPC_VAR_CONST_PTR_SECTION
#define CDD_IPC_VAR_CONST_UNSPECIFIED_SECTION
#define CDD_IPC_VAR_DATA_NO_INIT_8_SECTION
#define CDD_IPC_VAR_DATA_NO_INIT_8_SECTION_ALIGN_8B
#define CDD_IPC_VAR_DATA_NO_INIT_16_SECTION
#define CDD_IPC_VAR_DATA_NO_INIT_32_SECTION
#define CDD_IPC_VAR_DATA_NO_INIT_PTR_SECTION
#define CDD_IPC_VAR_DATA_NO_INIT_UNSPECIFIED_SECTION
#define CDD_IPC_VAR_DATA_INIT_8_SECTION
#define CDD_IPC_VAR_DATA_INIT_16_SECTION
#define CDD_IPC_VAR_DATA_INIT_32_SECTION
#define CDD_IPC_VAR_DATA_INIT_PTR_SECTION
#define CDD_IPC_VAR_DATA_INIT_UNSPECIFIED_SECTION
#define CDD_IPC_FUNC_TEXT_SECTION
#define CDD_IPC_ISR_TEXT_SECTION
#define CDD_IPC_FUNC_CALLOUT_TEXT_SECTION

/** \brief Dummy defines for M4 Build */
#define DIO_CONFIG_DATA_SECTION_CONST
#define DIO_CONFIG_DATA_SECTION_NON_CONST
#define DIO_VAR_CONST_8_SECTION
#define DIO_VAR_CONST_16_SECTION
#define DIO_VAR_CONST_32_SECTION
#define DIO_VAR_CONST_PTR_SECTION
#define DIO_VAR_CONST_UNSPECIFIED_SECTION
#define DIO_VAR_DATA_NO_INIT_8_SECTION
#define DIO_VAR_DATA_NO_INIT_16_SECTION
#define DIO_VAR_DATA_NO_INIT_32_SECTION
#define DIO_VAR_DATA_NO_INIT_PTR_SECTION
#define DIO_VAR_DATA_NO_INIT_UNSPECIFIED_SECTION
#define DIO_VAR_DATA_INIT_8_SECTION
#define DIO_VAR_DATA_INIT_16_SECTION
#define DIO_VAR_DATA_INIT_32_SECTION
#define DIO_VAR_DATA_INIT_PTR_SECTION
#define DIO_VAR_DATA_INIT_UNSPECIFIED_SECTION
#define DIO_FUNC_TEXT_SECTION
#define DIO_ISR_TEXT_SECTION
#define DIO_FUNC_CALLOUT_TEXT_SECTION

/** \brief Dummy defines for M4 Build */
#define ETH_CONFIG_DATA_SECTION
#define ETH_VAR_CONST_8_SECTION
#define ETH_VAR_CONST_16_SECTION
#define ETH_VAR_CONST_32_SECTION
#define ETH_VAR_CONST_PTR_SECTION
#define ETH_VAR_CONST_UNSPECIFIED_SECTION
#define ETH_VAR_DATA_NO_INIT_8_SECTION
#define ETH_VAR_DATA_NO_INIT_16_SECTION
#define ETH_VAR_DATA_NO_INIT_32_SECTION
#define ETH_VAR_DATA_NO_INIT_PTR_SECTION
#define ETH_VAR_DATA_NO_INIT_UNSPECIFIED_SECTION
#define ETH_VAR_DATA_INIT_8_SECTION
#define ETH_VAR_DATA_INIT_16_SECTION
#define ETH_VAR_DATA_INIT_32_SECTION
#define ETH_VAR_DATA_INIT_PTR_SECTION
#define ETH_VAR_DATA_INIT_UNSPECIFIED_SECTION
#define ETH_FUNC_TEXT_SECTION
#define ETH_ISR_TEXT_SECTION
#define ETH_FUNC_CALLOUT_TEXT_SECTION

/** \brief Dummy defines for M4 Build */
#define FLS_CONFIG_DATA_SECTION
#define FLS_VAR_CONST_8_SECTION
#define FLS_VAR_CONST_16_SECTION
#define FLS_VAR_CONST_32_SECTION
#define FLS_VAR_CONST_PTR_SECTION
#define FLS_VAR_CONST_UNSPECIFIED_SECTION
#define FLS_VAR_DATA_NO_INIT_8_SECTION
#define FLS_VAR_DATA_NO_INIT_16_SECTION
#define FLS_VAR_DATA_NO_INIT_32_SECTION
#define FLS_VAR_DATA_NO_INIT_PTR_SECTION
#define FLS_VAR_DATA_NO_INIT_UNSPECIFIED_SECTION
#define FLS_VAR_DATA_INIT_8_SECTION
#define FLS_VAR_DATA_INIT_16_SECTION
#define FLS_VAR_DATA_INIT_32_SECTION
#define FLS_VAR_DATA_INIT_PTR_SECTION
#define FLS_VAR_DATA_INIT_UNSPECIFIED_SECTION
#define FLS_FUNC_TEXT_SECTION
#define FLS_ISR_TEXT_SECTION
#define FLS_FUNC_CALLOUT_TEXT_SECTION

/** \brief Dummy defines for M4 Build */
#define GPT_CONFIG_DATA_SECTION
#define GPT_VAR_CONST_8_SECTION
#define GPT_VAR_CONST_16_SECTION
#define GPT_VAR_CONST_32_SECTION
#define GPT_VAR_CONST_PTR_SECTION
#define GPT_VAR_CONST_UNSPECIFIED_SECTION
#define GPT_VAR_DATA_NO_INIT_8_SECTION
#define GPT_VAR_DATA_NO_INIT_16_SECTION
#define GPT_VAR_DATA_NO_INIT_32_SECTION
#define GPT_VAR_DATA_NO_INIT_PTR_SECTION
#define GPT_VAR_DATA_NO_INIT_UNSPECIFIED_SECTION
#define GPT_VAR_DATA_INIT_8_SECTION
#define GPT_VAR_DATA_INIT_16_SECTION
#define GPT_VAR_DATA_INIT_32_SECTION
#define GPT_VAR_DATA_INIT_PTR_SECTION
#define GPT_VAR_DATA_INIT_UNSPECIFIED_SECTION
#define GPT_FUNC_TEXT_SECTION
#define GPT_ISR_TEXT_SECTION
#define GPT_FUNC_CALLOUT_TEXT_SECTION

/** \brief Dummy defines for M4 Build */
#define ICU_CONFIG_DATA_SECTION
#define ICU_VAR_CONST_8_SECTION
#define ICU_VAR_CONST_16_SECTION
#define ICU_VAR_CONST_32_SECTION
#define ICU_VAR_CONST_PTR_SECTION
#define ICU_VAR_CONST_UNSPECIFIED_SECTION
#define ICU_VAR_DATA_NO_INIT_8_SECTION
#define ICU_VAR_DATA_NO_INIT_16_SECTION
#define ICU_VAR_DATA_NO_INIT_32_SECTION
#define ICU_VAR_DATA_NO_INIT_PTR_SECTION
#define ICU_VAR_DATA_NO_INIT_UNSPECIFIED_SECTION
#define ICU_VAR_DATA_INIT_8_SECTION
#define ICU_VAR_DATA_INIT_16_SECTION
#define ICU_VAR_DATA_INIT_32_SECTION
#define ICU_VAR_DATA_INIT_PTR_SECTION
#define ICU_VAR_DATA_INIT_UNSPECIFIED_SECTION
#define ICU_FUNC_TEXT_SECTION
#define ICU_ISR_TEXT_SECTION
#define ICU_FUNC_CALLOUT_TEXT_SECTION

/** \brief Dummy defines for M4 Build */
#define PWM_CONFIG_DATA_SECTION
#define PWM_VAR_CONST_8_SECTION
#define PWM_VAR_CONST_16_SECTION
#define PWM_VAR_CONST_32_SECTION
#define PWM_VAR_CONST_PTR_SECTION
#define PWM_VAR_CONST_UNSPECIFIED_SECTION
#define PWM_VAR_DATA_NO_INIT_8_SECTION
#define PWM_VAR_DATA_NO_INIT_16_SECTION
#define PWM_VAR_DATA_NO_INIT_32_SECTION
#define PWM_VAR_DATA_NO_INIT_PTR_SECTION
#define PWM_VAR_DATA_NO_INIT_UNSPECIFIED_SECTION
#define PWM_VAR_DATA_INIT_8_SECTION
#define PWM_VAR_DATA_INIT_16_SECTION
#define PWM_VAR_DATA_INIT_32_SECTION
#define PWM_VAR_DATA_INIT_PTR_SECTION
#define PWM_VAR_DATA_INIT_UNSPECIFIED_SECTION
#define PWM_FUNC_TEXT_SECTION
#define PWM_ISR_TEXT_SECTION
#define PWM_FUNC_CALLOUT_TEXT_SECTION

/** \brief Dummy defines for M4 Build */
#define SPI_CONFIG_DATA_SECTION
#define SPI_VAR_CONST_8_SECTION
#define SPI_VAR_CONST_16_SECTION
#define SPI_VAR_CONST_32_SECTION
#define SPI_VAR_CONST_PTR_SECTION
#define SPI_VAR_CONST_UNSPECIFIED_SECTION
#define SPI_VAR_DATA_NO_INIT_8_SECTION
#define SPI_VAR_DATA_NO_INIT_16_SECTION
#define SPI_VAR_DATA_NO_INIT_32_SECTION
#define SPI_VAR_DATA_NO_INIT_PTR_SECTION
#define SPI_VAR_DATA_NO_INIT_UNSPECIFIED_SECTION
#define SPI_VAR_DATA_INIT_8_SECTION
#define SPI_VAR_DATA_INIT_16_SECTION
#define SPI_VAR_DATA_INIT_32_SECTION
#define SPI_VAR_DATA_INIT_PTR_SECTION
#define SPI_VAR_DATA_INIT_UNSPECIFIED_SECTION
#define SPI_FUNC_TEXT_SECTION
#define SPI_ISR_TEXT_SECTION
#define SPI_FUNC_CALLOUT_TEXT_SECTION

/** \brief Dummy defines for M4 Build */
#define WDG_CONFIG_DATA_SECTION
#define WDG_VAR_CONST_8_SECTION
#define WDG_VAR_CONST_16_SECTION
#define WDG_VAR_CONST_32_SECTION
#define WDG_VAR_CONST_PTR_SECTION
#define WDG_VAR_CONST_UNSPECIFIED_SECTION
#define WDG_VAR_DATA_NO_INIT_8_SECTION
#define WDG_VAR_DATA_NO_INIT_16_SECTION
#define WDG_VAR_DATA_NO_INIT_32_SECTION
#define WDG_VAR_DATA_NO_INIT_PTR_SECTION
#define WDG_VAR_DATA_NO_INIT_UNSPECIFIED_SECTION
#define WDG_VAR_DATA_INIT_8_SECTION
#define WDG_VAR_DATA_INIT_16_SECTION
#define WDG_VAR_DATA_INIT_32_SECTION
#define WDG_VAR_DATA_INIT_PTR_SECTION
#define WDG_VAR_DATA_INIT_UNSPECIFIED_SECTION
#define WDG_FUNC_TEXT_SECTION
#define WDG_ISR_TEXT_SECTION
#define WDG_FUNC_CALLOUT_TEXT_SECTION

#define ADC_APPL_CODE
#define ADC_CALLOUT_CODE
#define ADC_VAR_NOINIT
#define ADC_VAR_FAST
#define ADC_VAR
#define ADC_REGSPACE
#define ADC_CODE
#define ADC_CODE_FAST
#define ADC_CODE_SLOW
#define ADC_CONST
#define ADC_CALIB
#define ADC_CONFIG_DATA
#define ADC_APPL_DATA
#define ADC_APPL_CONST
#define ADC_VAR_NO_INIT
#define ADC_VAR_CLEARED
#define ADC_VAR_POWER_ON_CLEARED
#define ADC_VAR_INIT
#define ADC_VAR_POWER_ON_INIT
#define ADC_VAR_FAST_NO_INIT
#define ADC_VAR_FAST_CLEARED
#define ADC_VAR_FAST_POWER_ON_CLEARED
#define ADC_VAR_FAST_INIT
#define ADC_VAR_FAST_POWER_ON_INIT
#define ADC_VAR_SLOW_NO_INIT
#define ADC_VAR_SLOW_CLEARED
#define ADC_VAR_SLOW_POWER_ON_CLEARED
#define ADC_VAR_SLOW_INIT
#define ADC_VAR_SLOW_POWER_ON_INIT
#define ADC_INTERNAL_VAR_NO_INIT
#define ADC_INTERNAL_VAR_CLEARED
#define ADC_INTERNAL_VAR_POWER_ON_CLEARED
#define ADC_INTERNAL_VAR_INIT
#define ADC_INTERNAL_VAR_POWER_ON_INIT

#define CDD_IPC_APPL_CODE
#define CDD_IPC_CALLOUT_CODE
#define CDD_IPC_VAR_NOINIT
#define CDD_IPC_VAR_FAST
#define CDD_IPC_VAR
#define CDD_IPC_REGSPACE
#define CDD_IPC_CODE
#define CDD_IPC_CODE_FAST
#define CDD_IPC_CODE_SLOW
#define CDD_IPC_CONST
#define CDD_IPC_CALIB
#define CDD_IPC_CONFIG_DATA
#define CDD_IPC_APPL_DATA
#define CDD_IPC_APPL_CONST
#define CDD_IPC_VAR_NO_INIT
#define CDD_IPC_VAR_CLEARED
#define CDD_IPC_VAR_POWER_ON_CLEARED
#define CDD_IPC_VAR_INIT
#define CDD_IPC_VAR_POWER_ON_INIT
#define CDD_IPC_VAR_FAST_NO_INIT
#define CDD_IPC_VAR_FAST_CLEARED
#define CDD_IPC_VAR_FAST_POWER_ON_CLEARED
#define CDD_IPC_VAR_FAST_INIT
#define CDD_IPC_VAR_FAST_POWER_ON_INIT
#define CDD_IPC_VAR_SLOW_NO_INIT
#define CDD_IPC_VAR_SLOW_CLEARED
#define CDD_IPC_VAR_SLOW_POWER_ON_CLEARED
#define CDD_IPC_VAR_SLOW_INIT
#define CDD_IPC_VAR_SLOW_POWER_ON_INIT
#define CDD_IPC_INTERNAL_VAR_NO_INIT
#define CDD_IPC_INTERNAL_VAR_CLEARED
#define CDD_IPC_INTERNAL_VAR_POWER_ON_CLEARED
#define CDD_IPC_INTERNAL_VAR_INIT
#define CDD_IPC_INTERNAL_VAR_POWER_ON_INIT

#define DIO_APPL_CODE
#define DIO_CALLOUT_CODE
#define DIO_VAR_NOINIT
#define DIO_VAR_FAST
#define DIO_VAR
#define DIO_REGSPACE
#define DIO_CODE
#define DIO_CODE_FAST
#define DIO_CODE_SLOW
#define DIO_CONST
#define DIO_CALIB
#define DIO_CONFIG_DATA
#define DIO_APPL_DATA
#define DIO_APPL_CONST
#define DIO_VAR_NO_INIT
#define DIO_VAR_CLEARED
#define DIO_VAR_POWER_ON_CLEARED
#define DIO_VAR_INIT
#define DIO_VAR_POWER_ON_INIT
#define DIO_VAR_FAST_NO_INIT
#define DIO_VAR_FAST_CLEARED
#define DIO_VAR_FAST_POWER_ON_CLEARED
#define DIO_VAR_FAST_INIT
#define DIO_VAR_FAST_POWER_ON_INIT
#define DIO_VAR_SLOW_NO_INIT
#define DIO_VAR_SLOW_CLEARED
#define DIO_VAR_SLOW_POWER_ON_CLEARED
#define DIO_VAR_SLOW_INIT
#define DIO_VAR_SLOW_POWER_ON_INIT
#define DIO_INTERNAL_VAR_NO_INIT
#define DIO_INTERNAL_VAR_CLEARED
#define DIO_INTERNAL_VAR_POWER_ON_CLEARED
#define DIO_INTERNAL_VAR_INIT
#define DIO_INTERNAL_VAR_POWER_ON_INIT

#define ETH_APPL_CODE
#define ETH_CALLOUT_CODE
#define ETH_VAR_NOINIT
#define ETH_VAR_FAST
#define ETH_VAR
#define ETH_REGSPACE
#define ETH_CODE
#define ETH_CODE_FAST
#define ETH_CODE_SLOW
#define ETH_CONST
#define ETH_CALIB
#define ETH_CONFIG_DATA
#define ETH_APPL_DATA
#define ETH_APPL_CONST
#define ETH_VAR_NO_INIT
#define ETH_VAR_CLEARED
#define ETH_VAR_POWER_ON_CLEARED
#define ETH_VAR_INIT
#define ETH_VAR_POWER_ON_INIT
#define ETH_VAR_FAST_NO_INIT
#define ETH_VAR_FAST_CLEARED
#define ETH_VAR_FAST_POWER_ON_CLEARED
#define ETH_VAR_FAST_INIT
#define ETH_VAR_FAST_POWER_ON_INIT
#define ETH_VAR_SLOW_NO_INIT
#define ETH_VAR_SLOW_CLEARED
#define ETH_VAR_SLOW_POWER_ON_CLEARED
#define ETH_VAR_SLOW_INIT
#define ETH_VAR_SLOW_POWER_ON_INIT
#define ETH_INTERNAL_VAR_NO_INIT
#define ETH_INTERNAL_VAR_CLEARED
#define ETH_INTERNAL_VAR_POWER_ON_CLEARED
#define ETH_INTERNAL_VAR_INIT
#define ETH_INTERNAL_VAR_POWER_ON_INIT
#define ETH_VAR_NO_INIT_UDMA

#define FLS_CODE
#define FLS_CODE_FAST
#define FLS_CODE_SLOW
#define FLS_VAR
#define FLS_REGSPACE
#define FLS_CONST
#define FLS_CALIB
#define FLS_CONFIG_DATA
#define FLS_APPL_DATA
#define FLS_APPL_CONST
#define FLS_APPL_CODE
#define FLS_CALLOUT_CODE
#define FLS_VAR_NOINIT
#define FLS_VAR_NO_INIT
#define FLS_VAR_CLEARED
#define FLS_VAR_POWER_ON_CLEARED
#define FLS_VAR_INIT
#define FLS_VAR_POWER_ON_INIT
#define FLS_VAR_FAST
#define FLS_VAR_FAST_NO_INIT
#define FLS_VAR_FAST_CLEARED
#define FLS_VAR_FAST_POWER_ON_CLEARED
#define FLS_VAR_FAST_INIT
#define FLS_VAR_FAST_POWER_ON_INIT
#define FLS_VAR_SLOW_NO_INIT
#define FLS_VAR_SLOW_CLEARED
#define FLS_VAR_SLOW_POWER_ON_CLEARED
#define FLS_VAR_SLOW_INIT
#define FLS_VAR_SLOW_POWER_ON_INIT
#define FLS_INTERNAL_VAR_NO_INIT
#define FLS_INTERNAL_VAR_CLEARED
#define FLS_INTERNAL_VAR_POWER_ON_CLEARED
#define FLS_INTERNAL_VAR_INIT
#define FLS_INTERNAL_VAR_POWER_ON_INIT

#define GPT_APPL_CODE
#define GPT_CALLOUT_CODE
#define GPT_VAR_NOINIT
#define GPT_VAR_FAST
#define GPT_VAR
#define GPT_REGSPACE
#define GPT_CODE
#define GPT_CODE_FAST
#define GPT_CODE_SLOW
#define GPT_CONST
#define GPT_CALIB
#define GPT_CONFIG_DATA
#define GPT_APPL_DATA
#define GPT_APPL_CONST
#define GPT_VAR_NO_INIT
#define GPT_VAR_CLEARED
#define GPT_VAR_POWER_ON_CLEARED
#define GPT_VAR_INIT
#define GPT_VAR_POWER_ON_INIT
#define GPT_VAR_FAST_NO_INIT
#define GPT_VAR_FAST_CLEARED
#define GPT_VAR_FAST_POWER_ON_CLEARED
#define GPT_VAR_FAST_INIT
#define GPT_VAR_FAST_POWER_ON_INIT
#define GPT_VAR_SLOW_NO_INIT
#define GPT_VAR_SLOW_CLEARED
#define GPT_VAR_SLOW_POWER_ON_CLEARED
#define GPT_VAR_SLOW_INIT
#define GPT_VAR_SLOW_POWER_ON_INIT
#define GPT_INTERNAL_VAR_NO_INIT
#define GPT_INTERNAL_VAR_CLEARED
#define GPT_INTERNAL_VAR_POWER_ON_CLEARED
#define GPT_INTERNAL_VAR_INIT
#define GPT_INTERNAL_VAR_POWER_ON_INIT

#define ICU_APPL_CODE
#define ICU_CALLOUT_CODE
#define ICU_VAR_NOINIT
#define ICU_VAR_FAST
#define ICU_VAR
#define ICU_REGSPACE
#define ICU_CODE
#define ICU_CODE_FAST
#define ICU_CODE_SLOW
#define ICU_CONST
#define ICU_CALIB
#define ICU_CONFIG_DATA
#define ICU_APPL_DATA
#define ICU_APPL_CONST
#define ICU_VAR_NO_INIT
#define ICU_VAR_CLEARED
#define ICU_VAR_POWER_ON_CLEARED
#define ICU_VAR_INIT
#define ICU_VAR_POWER_ON_INIT
#define ICU_VAR_FAST_NO_INIT
#define ICU_VAR_FAST_CLEARED
#define ICU_VAR_FAST_POWER_ON_CLEARED
#define ICU_VAR_FAST_INIT
#define ICU_VAR_FAST_POWER_ON_INIT
#define ICU_VAR_SLOW_NO_INIT
#define ICU_VAR_SLOW_CLEARED
#define ICU_VAR_SLOW_POWER_ON_CLEARED
#define ICU_VAR_SLOW_INIT
#define ICU_VAR_SLOW_POWER_ON_INIT
#define ICU_INTERNAL_VAR_NO_INIT
#define ICU_INTERNAL_VAR_CLEARED
#define ICU_INTERNAL_VAR_POWER_ON_CLEARED
#define ICU_INTERNAL_VAR_INIT
#define ICU_INTERNAL_VAR_POWER_ON_INIT

#define PWM_APPL_CODE
#define PWM_CALLOUT_CODE
#define PWM_VAR_NOINIT
#define PWM_VAR_FAST
#define PWM_VAR
#define PWM_REGSPACE
#define PWM_CODE
#define PWM_CODE_FAST
#define PWM_CODE_SLOW
#define PWM_CONST
#define PWM_CALIB
#define PWM_CONFIG_DATA
#define PWM_APPL_DATA
#define PWM_APPL_CONST
#define PWM_VAR_NO_INIT
#define PWM_VAR_CLEARED
#define PWM_VAR_POWER_ON_CLEARED
#define PWM_VAR_INIT
#define PWM_VAR_POWER_ON_INIT
#define PWM_VAR_FAST_NO_INIT
#define PWM_VAR_FAST_CLEARED
#define PWM_VAR_FAST_POWER_ON_CLEARED
#define PWM_VAR_FAST_INIT
#define PWM_VAR_FAST_POWER_ON_INIT
#define PWM_VAR_SLOW_NO_INIT
#define PWM_VAR_SLOW_CLEARED
#define PWM_VAR_SLOW_POWER_ON_CLEARED
#define PWM_VAR_SLOW_INIT
#define PWM_VAR_SLOW_POWER_ON_INIT
#define PWM_INTERNAL_VAR_NO_INIT
#define PWM_INTERNAL_VAR_CLEARED
#define PWM_INTERNAL_VAR_POWER_ON_CLEARED
#define PWM_INTERNAL_VAR_INIT
#define PWM_INTERNAL_VAR_POWER_ON_INIT

#define SPI_APPL_CODE
#define SPI_CALLOUT_CODE
#define SPI_VAR_NOINIT
#define SPI_VAR_FAST
#define SPI_VAR
#define SPI_REGSPACE
#define SPI_CODE
#define SPI_CODE_FAST
#define SPI_CODE_SLOW
#define SPI_CONST
#define SPI_CALIB
#define SPI_CONFIG_DATA
#define SPI_APPL_DATA
#define SPI_APPL_CONST
#define SPI_VAR_NO_INIT
#define SPI_VAR_CLEARED
#define SPI_VAR_POWER_ON_CLEARED
#define SPI_VAR_INIT
#define SPI_VAR_POWER_ON_INIT
#define SPI_VAR_FAST_NO_INIT
#define SPI_VAR_FAST_CLEARED
#define SPI_VAR_FAST_POWER_ON_CLEARED
#define SPI_VAR_FAST_INIT
#define SPI_VAR_FAST_POWER_ON_INIT
#define SPI_VAR_SLOW_NO_INIT
#define SPI_VAR_SLOW_CLEARED
#define SPI_VAR_SLOW_POWER_ON_CLEARED
#define SPI_VAR_SLOW_INIT
#define SPI_VAR_SLOW_POWER_ON_INIT
#define SPI_INTERNAL_VAR_NO_INIT
#define SPI_INTERNAL_VAR_CLEARED
#define SPI_INTERNAL_VAR_POWER_ON_CLEARED
#define SPI_INTERNAL_VAR_INIT
#define SPI_INTERNAL_VAR_POWER_ON_INIT

#define WDG_APPL_CODE
#define WDG_CALLOUT_CODE
#define WDG_VAR_NOINIT
#define WDG_VAR_FAST
#define WDG_VAR
#define WDG_REGSPACE
#define WDG_CODE
#define WDG_CODE_FAST
#define WDG_CODE_SLOW
#define WDG_CONST
#define WDG_CALIB
#define WDG_CONFIG_DATA
#define WDG_APPL_DATA
#define WDG_APPL_CONST
#define WDG_VAR_NO_INIT
#define WDG_VAR_CLEARED
#define WDG_VAR_POWER_ON_CLEARED
#define WDG_VAR_INIT
#define WDG_VAR_POWER_ON_INIT
#define WDG_VAR_FAST_NO_INIT
#define WDG_VAR_FAST_CLEARED
#define WDG_VAR_FAST_POWER_ON_CLEARED
#define WDG_VAR_FAST_INIT
#define WDG_VAR_FAST_POWER_ON_INIT
#define WDG_VAR_SLOW_NO_INIT
#define WDG_VAR_SLOW_CLEARED
#define WDG_VAR_SLOW_POWER_ON_CLEARED
#define WDG_VAR_SLOW_INIT
#define WDG_VAR_SLOW_POWER_ON_INIT
#define WDG_INTERNAL_VAR_NO_INIT
#define WDG_INTERNAL_VAR_CLEARED
#define WDG_INTERNAL_VAR_POWER_ON_CLEARED
#define WDG_INTERNAL_VAR_INIT
#define WDG_INTERNAL_VAR_POWER_ON_INIT




/**********************************************************************************************************************
 *  NvM START 
 *********************************************************************************************************************/

#define NVM_APPL_DATA
#define NVM_APPL_CODE
#define NVM_APPL_CONST

#define NVM_CONFIG_DATA
#define NVM_CONFIG_CONST

#define NVM_FAST_DATA

#define NVM_PRIVATE_CODE
#define NVM_PRIVATE_CONST
#define NVM_PRIVATE_DATA

#define NVM_PUBLIC_CODE
#define NVM_PUBLIC_CONST

/* SchM/RTE declares NvM_MainFunction, using NVM_CODE *
 * It MUST be defined to NVM_PUBLIC_CODE!             */
#define NVM_CODE NVM_PUBLIC_CODE

/**********************************************************************************************************************
 *  NvM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  ARTI START
 *********************************************************************************************************************/

#define ARTI_CODE
#define ARTI_APPL_VAR
#define ARTI_VAR_NO_INIT

/**********************************************************************************************************************
 *  ARTI END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  DLT START 
 *********************************************************************************************************************/

#define DLT_CODE
#define DLT_VAR_INIT
#define DLT_VAR_NO_INIT
#define DLT_VAR_CLEARED
#define DLT_VAR
#define DLT_CONST
#define DLT_PBCFG
#define DLT_VAR_PBCFG
#define DLT_APPL_VAR
#define DLT_APPL_CODE

/**********************************************************************************************************************
 *  DLT END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CANNM START 
 *********************************************************************************************************************/

#define CANNM_CODE

#define CANNM_CONST
#define CANNM_PBCFG

#define CANNM_VAR_NOINIT
#define CANNM_VAR_INIT
#define CANNM_VAR_ZERO_INIT
#define CANNM_VAR_PBCFG
#define CANNM_APPL_VAR

/**********************************************************************************************************************
 *  CANNM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  NM START 
 *********************************************************************************************************************/
 
#define NM_CODE
#define NM_APPL_CODE

#define NM_CONST

#define NM_VAR_NO_INIT
#define NM_VAR_INIT
#define NM_APPL_VAR
#define NM_VAR_CLEARED

/**********************************************************************************************************************
 *  NM END
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  OS START
 *********************************************************************************************************************/

#define OS_CODE                         /* Regular OS code. */
#define OS_CODE_FAST                    /* Time critical OS code. (currently not used) */
#define OS_CODE_SLOW                    /* Not time critical OS code. (currently not used) */
#define OS_CODE_ISR                     /* OS ISRs. (currently not used) */

#define OS_PANICHOOK_CODE               /* Panic Hook */
#define OS_PRETASKHOOK_CODE             /* PreTask Hook */
#define OS_POSTTASKHOOK_CODE            /* PostTask Hook */
#define OS_STARTUPHOOK_CODE             /* Startup Hook */
#define OS_ERRORHOOK_CODE               /* Error Hook */
#define OS_PROTECTIONHOOK_CODE          /* Protection Hook */
#define OS_SHUTDOWNHOOK_CODE            /* Shutdown Hook */

#define OS_CONST                        /* Constant data. */
#define OS_CONST_FAST                   /* Constant data with fast access. (currently not used) */

#define OS_VAR_INIT                     /* Initialized dynamic data. (Not used by the OS) */
#define OS_VAR_NOINIT                   /* Not initialized dynamic data. */
#define OS_VAR_ZERO_INIT                /* Zero initialized dynamic data. */
#define OS_VAR_INIT_FAST                /* Initialized dynamic data with fast access. (Not used by the OS) */
#define OS_VAR_NOINIT_FAST              /* Not initialized dynamic data with fast access. */
#define OS_VAR_ZERO_INIT_FAST           /* Zero initialized dynamic data with fast access. */

#define OS_VAR_INIT_NOCACHE             /* Initialized dynamic data not cached. (Not used by the OS) */
#define OS_VAR_NOINIT_NOCACHE           /* Not initialized dynamic data not cached. */
#define OS_VAR_ZERO_INIT_NOCACHE        /* Zero initialized dynamic data not cached. */

#define OS_APPL_VAR                     /* Dynamic data from user space (always in RAM). */
#define OS_APPL_DATA                    /* Data from user space (maybe in RAM or ROM). */


#include "Os_Compiler_Cfg.h"

/**********************************************************************************************************************
 *  OS END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CSM START
 *********************************************************************************************************************/

#define CSM_CODE
#define CSM_APPL_CODE
#define CSM_RTE_CODE

#define CSM_CONST

#define CSM_VAR_NOINIT
#define CSM_VAR_ZERO_INIT
#define CSM_APPL_VAR
#define CSM_APPL_CONST

/**********************************************************************************************************************
 *  CSM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  KEYM START
 *********************************************************************************************************************/

#define KEYM_CODE
#define KEYM_APPL_CODE
#define KEYM_RTE_CODE

#define KEYM_CONST
#define KEYM_PBCFG

#define KEYM_VAR_INIT
#define KEYM_VAR_NO_INIT
#define KEYM_VAR_ZERO_INIT
#define KEYM_APPL_VAR
#define KEYM_APPL_DATA

/**********************************************************************************************************************
 *  KEYM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  BSWM START 
 *********************************************************************************************************************/

#define BSWM_CODE
#define BSWM_CONST
#define BSWM_PBCFG
#define BSWM_APPL_DATA
#define BSWM_VAR_NO_INIT
#define BSWM_VAR_PBCFG

/**********************************************************************************************************************
 *  BSWM END
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  SYSSERVICE_ASR4ECUM START 
 *********************************************************************************************************************/
#define ECUM_APPL_DATA 
#define ECUM_CODE
#define ECUM_CONST
#define ECUM_PBCFG
#define ECUM_VAR_NO_INIT 

/**********************************************************************************************************************
 *  SYSSERVICE_ASR4ECUM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SysService_Asr4WdM START 
 *********************************************************************************************************************/

#define WDGM_CODE
#define WDGM_APPL_CODE
#define WDGM_CONST
#define WDGM_VAR_INIT
#define WDGM_VAR_NOINIT
#define WDGM_VAR_ZERO_INIT
#define WDGM_APPL_DATA
#define WDGM_APPL_CONST

/**********************************************************************************************************************
 *  SysService_Asr4WdM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SYSSERVICE_ASRCRC START 
 *********************************************************************************************************************/

#define CRC_APPL_DATA
#define CRC_PRIVATE_CODE
#define CRC_CODE
#define CRC_CONST

/**********************************************************************************************************************
 *  SYSSERVICE_ASRCRC END
 *********************************************************************************************************************/


# define DET_CODE
# define DET_VAR
# define DET_APPL_DATA
# define DET_CONST




/**********************************************************************************************************************
 *  SysService_AsrRamTst START
 *********************************************************************************************************************/

#define RAMTST_APPL_DATA
#define RAMTST_CODE
#define RAMTST_VAR
#define RAMTST_CONST
#define RAMTST_PBCFG

/**********************************************************************************************************************
 *  SysService_AsrRamTst END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SD START
 *********************************************************************************************************************/

#define SD_CODE

#define SD_APPL_DATA
#define SD_APPL_VAR

#define SD_CONST
#define SD_PBCFG

#define SD_VAR_NO_INIT
#define SD_VAR_INIT
#define SD_VAR_CLEARED
#define SD_VAR_PBCFG

/**********************************************************************************************************************
 *  SD END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  SysService_E2eLib START 
 *********************************************************************************************************************/

#define E2E_CODE
#define E2E_VAR_FAST
#define E2E_VAR
#define E2E_CONST
#define E2E_DATA
#define E2E_APPL_DATA
#define E2E_APPL_CONST
#define E2E_APPL_CODE

/**********************************************************************************************************************
 *  SysService_E2eLib END
 *********************************************************************************************************************/





/**********************************************************************************************************************
 *  E2E START 
 *********************************************************************************************************************/


#define E2EPW_CODE
#define E2EPW_VAR_NOINIT
#define E2EPW_VAR_INIT
#define E2EPW_VAR_POWER_ON_INIT
#define E2EPW_VAR_FAST
#define E2EPW_VAR
#define E2EPW_CONST
#define E2EPW_APPL_DATA
#define E2EPW_APPL_CONST
#define E2EPW_APPL_CODE
#define E2EPW_APPL_VAR


/**********************************************************************************************************************
 *  E2E END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  IPBASE START
 *********************************************************************************************************************/

#define IPBASE_CODE

#define IPBASE_CONST
#define IPBASE_APPL_CONST
#define IPBASE_PBCFG
#define IPBASE_APPL_DATA

#define IPBASE_VAR_NOINIT

/**********************************************************************************************************************
 *  IPBASE END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CANTP START 
 *********************************************************************************************************************/

#define CANTP_CODE
#define CANTP_CONST

#define CANTP_PBCFG
#define CANTP_VAR_PBCFG

#define CANTP_VAR_INIT
#define CANTP_VAR_NOINIT

#define CANTP_APPL_CODE
#define CANTP_APPL_DATA

/**********************************************************************************************************************
 *  CANTP END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  TCPIP START
 *********************************************************************************************************************/

#define TCPIP_CODE
#define TCPIP_CODE_ISR

#define TCPIP_CONST
#define TCPIP_PBCFG

#define TCPIP_APPL_CODE
#define TCPIP_APPL_CONST
#define TCPIP_APPL_DATA
#define TCPIP_APPL_VAR

#define TCPIP_VAR_INIT
#define TCPIP_VAR_CLEARED
#define TCPIP_VAR_NO_INIT

/**********************************************************************************************************************
 *  TCPIP END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  VSTDLIB START
 *********************************************************************************************************************/

#define VSTDLIB_CODE
#define VSTDLIB_VAR_FAR
#define VSTDLIB_APPL_VAR
#define VSTDLIB_CONST

/**********************************************************************************************************************
 *  VSTDLIB END
 *********************************************************************************************************************/



#define _TEXAS_INSTRUMENTS_C_ARM_



/* Package Merger: Stop Section CompilerCfgModuleList */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif  /* COMPILER_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Compiler_Cfg.h
 *********************************************************************************************************************/
