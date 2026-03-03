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
/*!        \file  vMem_30_vXSpi_Nand_Extended_Func.h
 *        \brief  vMem_30_vXSpi_Nand public header file containing types and declarations of the hardware specific
 *                functionality.
 *
 *      \details  This file contains the types and declarations of the hardware specific functionality of
 *                vMem_30_vXSpi_Nand. It should be included by every user, that wants to call a hardware specific API.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VMEM_30_VXSPI_NAND_EXTENDED_FUNC_H)
# define VMEM_30_VXSPI_NAND_EXTENDED_FUNC_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*!< Service ID: vMem_30_vXSpi_Nand_ReplaceLogicalSector() */
# define VMEM_30_VXSPI_NAND_SID_REPLACE_LOGICAL_SECTOR             (0xF2u)
/*!< Service ID: vMem_30_vXSpi_Nand_GetLastErrorState() */
# define VMEM_30_VXSPI_NAND_SID_GET_LAST_ERROR_STATE               (0xF3u)
/*!< Service ID: vMem_30_vXSpi_Nand_RecoverData() */
# define VMEM_30_VXSPI_NAND_SID_RECOVER_DATA                       (0xF4u)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
  VMEM_30_VXSPI_NAND_NO_AVAILABLE_SECTOR_REMAINING = 0,   /*!< No available sector is remaining. */
  VMEM_30_VXSPI_NAND_SECTOR_REPLACEABLE                   /*!< Sector can be replaced. */
} vMem_30_vXSpi_Nand_AvailableSectorInfoType;             /*!< Indicates if sector is replaceable or why not. */

/*! Specifies the type of access to the external flash device. */
typedef enum
{
  VMEM_30_VXSPI_NAND_NO_JOB = 0,
  VMEM_30_VXSPI_NAND_WRITE_ACCESS,
  VMEM_30_VXSPI_NAND_READ_ACCESS,
  VMEM_30_VXSPI_NAND_ERASE_ACCESS,
  VMEM_30_VXSPI_NAND_BLANK_CHECK_ACCESS,
  VMEM_30_VXSPI_NAND_REPLACE_LOGICAL_SECTOR_ACCESS,
  VMEM_30_VXSPI_NAND_RECOVER_DATA_ACCESS
} vMem_30_vXSpi_Nand_AccessType;

/*! Specifies the type of error with which a job can end. */
typedef enum
{
  VMEM_30_VXSPI_NAND_NO_FAIL = 0,      /*!< No error. */
  VMEM_30_VXSPI_NAND_E_FAIL,           /*!< Hardware indicated, that the sector could not be erased. */
  VMEM_30_VXSPI_NAND_P_FAIL,           /*!< Hardware indicated, that the page could not be programmed. */
  VMEM_30_VXSPI_NAND_R_FAIL,           /*!< Software indicated, that the page could not be programmed during the data recovery execution. */
  VMEM_30_VXSPI_NAND_OTHER_FAIL        /*!< Not further specified failure, e.g. spi transmission fail. */
} vMem_30_vXSpi_Nand_JobErrorType;

typedef enum
{
  VMEM_30_VXSPI_NAND_REPLACE_LOGICAL_SECTOR = 0, /*!< Id for vMem_30_vXSpi_Nand_ReplaceLogicalSector. */
  VMEM_30_VXSPI_NAND_GET_LAST_ERROR_STATE,       /*!< Id for vMem_30_vXSpi_Nand_GetLastErrorState. */
  VMEM_30_VXSPI_NAND_RECOVER_DATA                /*!< Id for vMem_30_vXSpi_Nand_RecoverData. */
} vMem_30_vXSpi_Nand_HWSpecificFuncID;           /*!< Numeric identifier for HW specific functionality:
                                                   index in function pointer table. */

typedef struct
{
  vMem_30_vXSpi_Nand_AddressType TargetSectorAddress;             /*!< [in]  Start address of the sector that shall be replaced. 
                                                                          Value must be provided by the user of the ReplaceLogicalSector function. */
  vMem_30_vXSpi_Nand_AddressType ReplacingSectorAddress;          /*!< [out] Start address of the sector that is used for replacement.
                                                                          Value must not be provided. ReplaceLogicalSector gets this information
                                                                          and stores it here. */
  vMem_30_vXSpi_Nand_AddressType RecoverDataSourceAddress;        /*!< [out] Start address of the sector that should be used for later data recovery
                                                                          in case of P-Fail or R-Fail. Value must not be provided.
                                                                          ReplaceLogicalSector gets this information and stores it here. */
  vMem_30_vXSpi_Nand_JobErrorType LastJobError;                  /*!< [in] Indicates the error which caused triggering of bad block managment.
                                                                          From this value replace logical sector decides which address should be
                                                                          used as data recovery source address (in the case data recovery is needed). */
  vMem_30_vXSpi_Nand_AvailableSectorInfoType AvailableSectorInfo; /*!< [out] Indicates if sector is replaceable or why not. 
                                                                          Value must not be provided. ReplaceLogicalSector gets this information
                                                                          and stores it here. */
} vMem_30_vXSpi_Nand_ReplaceSectorType;                           /*!< Hardware specific structure for vMem_30_vXSpi_Nand_ReplaceLogicalSector. */

typedef P2VAR(vMem_30_vXSpi_Nand_ReplaceSectorType, AUTOMATIC, VMEM_30_VXSPI_NAND_APPL_VAR) vMem_30_vXSpi_Nand_ReplaceSectorPtrType;

typedef struct 
{
  vMem_30_vXSpi_Nand_AccessType currentJob;                 /*!< [out] Indicates the last job, which was executed. */
  vMem_30_vXSpi_Nand_JobErrorType currentErrorState;        /*!< [out] Indicates the current error states. */
  vMem_30_vXSpi_Nand_AddressType currentErrorAddressOrigin; /*!< [out] Indicates the start address of the sector where the error occurred. */
} vMem_30_vXSpi_Nand_ErrorStateType;                        /*!< Hardware specific structure for vMem_30_vXSpi_Nand_GetLastErrorState. */

typedef struct 
{
  vMem_30_vXSpi_Nand_AddressType SourceSectorAddress;  /*!< [in] Startaddress of the sector from which data should be recovered. 
                                                              Value must be provided by the user of the RecoverData function. */
  vMem_30_vXSpi_Nand_AddressType TargetSectorAddress;  /*!< [in] Startaddress of the sector to which the data should be recovered. 
                                                              Value must be provided by the user of the RecoverData function. */
} vMem_30_vXSpi_Nand_RecoverDataType;                  /*!< Hardware specific structure for vMem_30_vXSpi_Nand_RecoverData. */

typedef P2VAR(vMem_30_vXSpi_Nand_RecoverDataType, AUTOMATIC, VMEM_30_VXSPI_NAND_APPL_VAR) vMem_30_vXSpi_Nand_RecoverDataPtrType;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VMEM_30_VXSPI_NAND_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_ReplaceLogicalSector()
 *********************************************************************************************************************/
/*!
 * \brief      This service replaces a logical sector. NOTE: this service should be called via the HwSpecificReq
 *             API of the vMemAccM. The corresponding function index is VMEM_30_VXSPI_NAND_REPLACE_LOGICAL_SECTOR.
 * \details    Via this service the user can replace a (failing) logical sector. It is up to the user to decide, if and
 *             when a sector should be replaced. The vMem_30_vXSpi_Nand first checks, whether the requested sector
 *             is replaceable (a sector can only be replaced if there is still a remaining replacing sector available).
 *             If this is not the case the job result is JOB_FAILED.
 * \param[in]      InstanceId          ID of the related vMem instance.
 * \param[in,out]  ReqSpecificData     Pointer to a variable of type vMem_30_vXSpi_Nand_ReplaceSectorType. Contains the 
 *                                     address of the sector which shall be replaced. After job is processed contains 
 *                                     information, if sector is replaceable, or why not. If the sector is replaceble 
 *                                     this will also contain the startaddress of the replacing sector.
 * \param[in]  SizeOfData          Size of ReqSpecificData; in this case size of vMem_30_vXSpi_Nand_ReplaceSectorType.
 * \return     E_OK request accepted, E_NOT_OK otherwise.
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous FALSE
 * \trace       DSGN-vMem23038
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_ReplaceLogicalSector(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_DataPtrType ReqSpecificData,
    vMem_30_vXSpi_Nand_LengthType SizeOfData
    );

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_GetLastErrorState()
 *********************************************************************************************************************/
/*!
 * \brief      This service gets the content of the flash peripheral error register. NOTE: this service should be called
 *             via the HwSpecificReq API of the vMemAccM. The corresponding function index is 
 *             VMEM_30_VXSPI_NAND_GET_LAST_ERROR_STATE.
 * \details    Via this service the user can check for detailed error information when the vMem reported the generic 
 *             error state VMEM_JOB_FAILED to the user. This service reports always the latest error state of the last 
 *             job. A possible use case is to check for different error condition when implementing the replace logical 
 *             sectior feature.
 * \param[in]  InstanceId          ID of the related vMem instance.
 * \param[out] ReqSpecificData     Pointer to a variable of type vMem_30_vXSpi_Nand_ErrorStateType.
 *                                 After job is processed contains information which job was processed, which error 
 *                                 occurred and the startaddress of the sector from where the error origined. 
 * \param[in]  SizeOfData          Size of ReqSpecificData; in this case size of vMem_30_vXSpi_Nand_ErrorStateType.
 * \return     E_OK request accepted, E_NOT_OK otherwise.
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 * \trace       DSGN-vMemDrv22776
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_GetLastErrorState(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_DataPtrType ReqSpecificData,
    vMem_30_vXSpi_Nand_LengthType SizeOfData
    );

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_RecoverData()
 *********************************************************************************************************************/
/*!
 * \brief      This service recovers all data from one sector to another sector. NOTE: this service should be 
 *             called via the HwSpecificReq API of the vMemAccM. The corresponding function index is 
 *             VMEM_30_VXSPI_NAND_RECOVER_DATA.
 * \details    Via this service, the user can mirror the data of a replaced sector to the corresponding replacement
 *             sector.
 * \param[in]  InstanceId      ID of the related vMem instance.
 * \param[in]  ReqSpecificData Pointer to a variable of type vMem_30_vXSpi_Nand_RecoverDataType. Must contain the 
 *                             startaddresses of the sector from which data should be recovered and to which the data
 *                             should be recovered.
 * \param[in]  SizeOfData      Size of ReqSpecificData; in this case size of vMem_30_vXSpi_Nand_RecoverDataType.
 * \return     E_OK request accepted, E_NOT_OK otherwise.
 * \pre        -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \trace       DSGN-vMem23294
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_RecoverData(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_DataPtrType ReqSpecificData,
    vMem_30_vXSpi_Nand_LengthType SizeOfData
    );

# define VMEM_30_VXSPI_NAND_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* VMEM_30_VXSPI_NAND_EXTENDED_FUNC_H */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_vXSpi_Nand_Extended_Func.h
 *********************************************************************************************************************/
