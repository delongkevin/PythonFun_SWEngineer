/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vMem_30_vXSpi_Nand.h
 *        \brief  vMem_30_vXSpi_Nand header file
 *
 *      \details  This is the header file of the vMem_30_vXSpi_Nand. It declares the interfaces of the vMem_30_vXSpi_Nand. 
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author          Change Id                Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  00.05.00  2022-03-07  virskl          CTM-3999                 Initial creation.
 *  01.00.00  2022-05-25  virzln          CTM-4692                 Reach quality status QM.
 *  01.01.00  2022-12-09  virzln          CTM-5638                 ESCAN00113288: Reading over page boundaries brings DET error
 *                        virzln          CTM-5482                 Add support for W35N01JW
 *  01.02.00  2023-04-20  virzln          CTM-6047                 DrvMem vXSpi Nand prepare for ASIL
 *********************************************************************************************************************/

#if !defined (VMEM_30_VXSPI_NAND_H)
# define VMEM_30_VXSPI_NAND_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vMem_30_vXSpi_Nand_Cfg.h"
# include "vMem_30_vXSpi_Nand_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define VMEM_30_VXSPI_NAND_SW_MAJOR_VERSION                    (1u)
# define VMEM_30_VXSPI_NAND_SW_MINOR_VERSION                    (2u)
# define VMEM_30_VXSPI_NAND_SW_PATCH_VERSION                    (0u)

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define VMEM_30_VXSPI_NAND_START_SEC_HEADER_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Global API pointer table */
extern CONST(vMemAccM_vMemApiType, AUTOMATIC) vMem_30_vXSpi_Nand_FunctionPointerTable;

#define VMEM_30_VXSPI_NAND_STOP_SEC_HEADER_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VMEM_30_VXSPI_NAND_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_GetVersionInfo()
 *********************************************************************************************************************/
/*! \brief       Returns the version information. This service is always available.
 *  \details     vMem_30_vXSpi_Nand_GetVersionInfo() returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]  versioninfo           Pointer to where to store the version information. Parameter must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-150071
 *********************************************************************************************************************/
FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, VMEM_30_VXSPI_NAND_APPL_VAR) VersionInfo);

# define VMEM_30_VXSPI_NAND_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* VMEM_30_VXSPI_NAND_H */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_vXSpi_Nand.h
 *********************************************************************************************************************/

