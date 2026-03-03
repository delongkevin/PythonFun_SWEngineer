/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Fee_30_FlexNor.h
 *        \brief  Fee_30_FlexNor component header file
 *      \details  Header file of the Fee_30_FlexNor component interface.
 *         \unit  Fee
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  00.01.00  2020-04-02  virlra  -             Initial creation of FEE implementation.
 *                        virljs
 *  00.02.00  2020-04-24  virlra  -             Implementing instance units.
 *                        virljs
 *                        virjwa
 *  00.03.00  2020-06-17  virlra  -             Implementing chunk units.
 *                        virljs
 *  00.04.00  2020-08-04  virlra  -             Implementing sector unit.
 *                        virljs
 *                        virjwa
 *  00.05.00  2020-08-28  virlra  -             Implementing start, sector container and lookup table unit.
 *                        virjwa
 *  00.06.00  2020-10-26  virlra  -             Implementing chunk search.
 *  00.07.00  2020-12-01  virlra  MWDG-2840     Implementing basic read functionality.
 *  00.08.00  2020-12-21  virlra  MWDG-4419     Improve implementation.
 *                        virbka  MWDG-4681     Add chunk allocation service to sector unit.
 *                                MWDG-2838     Add write behavior to FEE FlexNor.
 *                                MWDG-4945     Add missing component services.
 *  00.09.00 2021-06-01   virlra  MWDG-5185     Fixing product validation findings.
 *  00.10.00 2021-08-02   virlra  MWDG-5562     Fixing issues found during component testing.
 *  00.11.00 2021-08-05   virlra  MWDG-5670     Fixing additional issues found during component testing.
 *  00.12.00 2021-09-29   virlra  MWDG-5487     Implementing job cancellation.
 *  01.00.00 2021-11-15   virlra  MWDG-6167     Prepare and execute beta release of Fee FlexNor.
 *  01.01.00 2021-12-17   virjwa  MWDG-5483     Prepare persisting of lookup table in flash for FEE FlexNor.
 *                                MWDG-5485     Load persisted lookup table block from flash for FEE FlexNor.
 *********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_H)
# define FEE_30_FLEXNOR_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Fee_30_FlexNor_Types.h"
# include "Fee_30_FlexNor_ConfigInterface.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Vendor and module identification */
# define FEE_30_FLEXNOR_VENDOR_ID                           (30u)
# define FEE_30_FLEXNOR_MODULE_ID                           (21u)

/* AUTOSAR Software specification version information */
# define FEE_30_FLEXNOR_AR_RELEASE_MAJOR_VERSION            (4u)
# define FEE_30_FLEXNOR_AR_RELEASE_MINOR_VERSION            (0u)
# define FEE_30_FLEXNOR_AR_RELEASE_REVISION_VERSION         (3u)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define FEE_30_FLEXNOR_SW_MAJOR_VERSION                    (1u)
# define FEE_30_FLEXNOR_SW_MINOR_VERSION                    (1u)
# define FEE_30_FLEXNOR_SW_PATCH_VERSION                    (0u)

# define FEE_30_FLEXNOR_INSTANCE_ID_DET                     (0u)

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
# define FEE_30_FLEXNOR_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Fee_30_FlexNor_InitMemory()
 *********************************************************************************************************************/
/*! \brief       Initialization for *_INIT_*-variables
 *  \details     Service to initialize module global variables at power up. This function initializes the
 *               variables in *_INIT_* sections. Used in case they are not initialized by the startup code.
 *  \pre         Module is uninitialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InitMemory(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Init()
 *********************************************************************************************************************/
/*! \brief       Initialization function
 *  \details     Service to initialize the module Fee_30_FlexNor. It initializes all variables 
 *               and sets the module state to initialized.
 *  \param[in]   ConfigPtr               Configuration structure for initializing the module. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Init(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SetMode()
 *********************************************************************************************************************/
/*! \brief       Service to switch the mode of the underlying flash driver
 *  \details     -
 *  \param[in]   mode               Mode to set
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SetMode(MemIf_ModeType mode);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Read()
 *********************************************************************************************************************/
/*! \brief       Service to initiate a read job
 *  \details     -
 *  \param[in]   blockNumber        Unique identifier of block
 *  \param[in]   offset             Offset in the block
 *  \param[out]  dataBufferPtr      Pointer to buffer from upper layer
 *  \param[in]   length             Amount of bytes which should be read
 *  \return      E_OK       The job was accepted
 *               E_NOT_OK   The job was rejected
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Read(
    Fee_30_FlexNor_BlockNumberType blockNumber, 
    Fee_30_FlexNor_BlockOffsetType offset,
    Fee_30_FlexNor_DataPtrType dataBufferPtr,
    uint16 length);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Write()
 *********************************************************************************************************************/
/*! \brief       Service to initiate a write job
 *  \details     -
 *  \param[in]   blockNumber        Unique identifier of block
 *  \param[out]  dataBufferPtr      Pointer to buffer from upper layer
 *  \return      E_OK       The job was accepted
 *               E_NOT_OK   The job was rejected
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Write(
    Fee_30_FlexNor_BlockNumberType blockNumber, 
    Fee_30_FlexNor_ConstDataPtrType dataBufferPtr);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Cancel()
 *********************************************************************************************************************/
/*! \brief       Service to cancel the current job
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Cancel(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_InvalidateBlock()
 *********************************************************************************************************************/
/*! \brief       Service to initiate an invalidation for the given block
 *  \details     -
 *  \param[in]   blockNumber    Unique identifier of block that shall be invalidated
 *  \return      E_OK           The job was accepted
 *               E_NOT_OK       The job was rejected
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_InvalidateBlock(Fee_30_FlexNor_BlockNumberType blockNumber);

/**********************************************************************************************************************
 * Fee_30_FlexNor_EraseImmediateBlock()
 *********************************************************************************************************************/
/*! \brief       Service to initiate an erase of immediate data block
 *  \details     The given block is erased by invalidating it.
 *  \param[in]   blockNumber    Unique identifier of block with immediate data that shall be erased
 *  \return      E_OK           The job was accepted
 *               E_NOT_OK       The job was rejected
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_EraseImmediateBlock(Fee_30_FlexNor_BlockNumberType blockNumber);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GetStatus()
 *********************************************************************************************************************/
/*! \brief       Gets the current status of the module
 *  \details     -
 *  \return      Current module status
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(MemIf_StatusType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GetStatus(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_GetJobResult()
 *********************************************************************************************************************/
/*! \brief       Gets the current job result of the module
 *  \details     -
 *  \return      Current module job result
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(MemIf_JobResultType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GetJobResult(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_MainFunction()
 *********************************************************************************************************************/
/*! \brief       Function for asynchronous processing of the component
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_MainFunction(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_PersistLookupTable()
 *********************************************************************************************************************/
/*! \brief       Service to initiate writing the content of the lookup table of the given partition to the flash.
 *  \details     -
 *  \param[in]   partitionId        Id of the partition, whose lookup table shall be persisted.
 *  \return      E_OK       The job was accepted
 *               E_NOT_OK   The job was rejected
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_PersistLookupTable(Fee_30_FlexNor_PartitionIdType partitionId);

# if (FEE_30_FLEXNOR_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  Fee_30_FlexNor_GetVersionInfo()
 *********************************************************************************************************************/
/*! \brief       Returns the version information
 *  \details     Fee_30_FlexNor_GetVersionInfo() returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]  Versioninfo             Pointer to where to store the version information. Parameter must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_GetVersionInfo(Fee_30_FlexNor_VersionInfoPtrType versioninfo);
# endif

# define FEE_30_FLEXNOR_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor.h
 *********************************************************************************************************************/
