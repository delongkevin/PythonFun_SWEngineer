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
/**
 * \addtogroup Os_Hal_MemoryProtection
 * \{
 *
 * \file       Os_Hal_MemoryProtection_PMSAv8.h
 * \brief      Memory protection primitives for the Protected Memory System Architecture (PMSA) used by ARMv8-A and
 *             ARMv8-R.
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_MEMORYPROTECTION_PMSAV8_H
# define OS_HAL_MEMORYPROTECTION_PMSAV8_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"

/* Os kernel module dependencies */
# include "Os_Common.h"

/* Os module declarations */
# include "Os_Hal_MemoryProtectionInt.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_Hal_MpGetMpuType()
 **********************************************************************************************************************/
/*! \brief        Returns MPU Type Register (MPUIR) of the PMSA.
 *  \details      Read from coprocessor register.
 *  \return       MPUIR value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_MpGetMpuType()                    Os_Hal_ReadFromCoprocessor(15, 0, 0, 0, 4)


/***********************************************************************************************************************
 *  Os_Hal_MpSetRegionNumber()
 **********************************************************************************************************************/
/*! \brief        Set Protection Region Selector Register (PRSELR) of the PMSA.
 *  \details      Write to coprocessor register.
 *  \param[in]    Value  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_MpSetRegionNumber(Value)          Os_Hal_WriteToCoprocessor(Value, 15, 0, 6, 2, 1)


/***********************************************************************************************************************
 *  Os_Hal_MpSetRegionBaseAddressAndAccessRights()
 **********************************************************************************************************************/
/*! \brief        Set Protection Region Base Address Register (PRBAR) of the PMSA.
 *  \details      Write to coprocessor register.
 *  \param[in]    Value  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_MpSetRegionBaseAddressAndAccessRights(Value)   Os_Hal_WriteToCoprocessor(Value, 15, 0, 6, 3, 0);


/***********************************************************************************************************************
 *  Os_Hal_MpGetRegionBaseAddressAndAccessRights()
 **********************************************************************************************************************/
/*! \brief        Returns Protection Region Base Address Register (PRBAR) of the PMSA.
 *  \details      Read from coprocessor register.
 *  \return       PRBAR value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_MpGetRegionBaseAddressAndAccessRights()     Os_Hal_ReadFromCoprocessor(15, 0, 6, 3, 0)


/***********************************************************************************************************************
 *  Os_Hal_MpSetRegionEndAddressAndEnable()
 **********************************************************************************************************************/
/*! \brief        Set Protection Region Limit Address and Enable Register (PRLAR) of the PMSA.
 *  \details      Write to coprocessor register.
 *  \param[in]    Value  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_MpSetRegionEndAddressAndEnable(Value)   Os_Hal_WriteToCoprocessor(Value, 15, 0, 6, 3, 1)


/***********************************************************************************************************************
 *  Os_Hal_MpGetRegionEndAddressAndEnable()
 **********************************************************************************************************************/
/*! \brief        Returns Protection Region Limit Address and Enable Register (PRLAR) of the PMSA.
 *  \details      Read from coprocessor register.
 *  \return       PRLAR value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_MpGetRegionEndAddressAndEnable()        Os_Hal_ReadFromCoprocessor(15, 0, 6, 3, 1)


/***********************************************************************************************************************
 *  Os_Hal_MpGetDataFaultAddress()
 **********************************************************************************************************************/
/*! \brief        Returns Data Fault Address Register (DFAR) of the PMSA.
 *  \details      Read from coprocessor register.
 *  \return       DFAR value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_MpGetDataFaultAddress()           Os_Hal_ReadFromCoprocessor(15, 0, 6, 0, 0)


/***********************************************************************************************************************
 *  Os_Hal_MpGetDataFaultIndicator()
 **********************************************************************************************************************/
/*! \brief        Returns Data Fault Status Register (DFSR) of the PMSA.
 *  \details      Read from coprocessor register.
 *  \return       DFSR value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_MpGetDataFaultIndicator()         Os_Hal_ReadFromCoprocessor(15, 0, 5, 0, 0)


/***********************************************************************************************************************
 *  Os_Hal_MpGetInstructionFaultAddress()
 **********************************************************************************************************************/
/*! \brief        Returns Instruction Fault Address Register (IFAR) of the PMSA.
 *  \details      Read from coprocessor register.
 *  \return       IFAR value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_MpGetInstructionFaultAddress()    Os_Hal_ReadFromCoprocessor(15, 0, 6, 0, 2)


/***********************************************************************************************************************
 *  Os_Hal_MpGetInstructionFaultIndicator()
 **********************************************************************************************************************/
/*! \brief        Returns Instruction Fault Status Register (IFSR) of the PMSA.
 *  \details      Read from coprocessor register.
 *  \return       IFSR value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_MpGetInstructionFaultIndicator()  Os_Hal_ReadFromCoprocessor(15, 0, 5, 0, 1)


/***********************************************************************************************************************
 *  Os_Hal_MpSetMemoryAttributeIndirection0()
 **********************************************************************************************************************/
/*! \brief        Set memory attribute indirection register 0 Region (MAIR0) of the PMSA.
 *  \details      Write to coprocessor register.
 *  \param[in]    Value  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_MpSetMemoryAttributeIndirection0(Value)   Os_Hal_WriteToCoprocessor(Value, 15, 0, 10, 2, 0)


/***********************************************************************************************************************
 *  Os_Hal_MpSetMemoryAttributeIndirection1()
 **********************************************************************************************************************/
/*! \brief        Set memory attribute indirection register 1 Region (MAIR1) of the PMSA.
 *  \details      Write to coprocessor register.
 *  \param[in]    Value  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_MpSetMemoryAttributeIndirection1(Value)   Os_Hal_WriteToCoprocessor(Value, 15, 0, 10, 2, 1)


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  Os_Hal_MpEnableMPU()
 **********************************************************************************************************************/
/*! \brief        Enables the MPU.
 *  \details      -
 *  \context      ANY
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_Hal_MpEnableMPU, (void));


/***********************************************************************************************************************
 *  Os_Hal_MpDisableAllRegions()
 **********************************************************************************************************************/
/*! \brief        Disables all available MPU regions.
 *  \details      -
 *  \context      ANY
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_Hal_MpDisableAllRegions, (void));


/***********************************************************************************************************************
 *  Os_Hal_MpWriteRegionDescriptor()
 **********************************************************************************************************************/
/*! \brief        Writes given MPU region configuration into peripheral.
 *  \details      -
 *  \param[in]    Region  MPU region configuration which shall be written. Parameter must not be NULL.
 *  \context      ANY
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_Hal_MpWriteRegionDescriptor,
(
  P2CONST(Os_Hal_MpRegionType, TYPEDEF, OS_CONST) Region
));


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_Hal_MpEnableMPU()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_Hal_MpEnableMPU, (void))
{
  /* #10 Get SCTLR. */
  uint32 systemControl = Os_Hal_GetSystemControl();
  systemControl |= OS_HAL_MP_SYSTEMCONTROL_ENABLE_MPU;

  /* #20 Data Sync Barrier. */
  Os_Hal_DataSyncBarrier();

  /* #30 Set SCTLR.M bits. */
  Os_Hal_SetSystemControl(systemControl);

  /* #40 Instruction Sync Barrier. */
  Os_Hal_InstructionSyncBarrier();
}


/***********************************************************************************************************************
 *  Os_Hal_MpDisableAllRegions()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_Hal_MpDisableAllRegions, (void))
{
  uint8_least index;
  const uint8_least NumberOfRegions = (uint8_least)((Os_Hal_MpGetMpuType() >> 8) & 0xFFuL);

  /* #10 For all available MPU regions. */
  for(index = 0; index < NumberOfRegions; index++)                                                                      /* FETA_OS_HAL_ARM_MPU */
  {
    /* #20 Disable the region. */
    Os_Hal_MpSetRegionNumber(index);
    Os_Hal_MpSetRegionEndAddressAndEnable(0);
  }
}


/***********************************************************************************************************************
 *  Os_Hal_MpWriteRegionDescriptor()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_Hal_MpWriteRegionDescriptor,
(
  P2CONST(Os_Hal_MpRegionType, TYPEDEF, OS_CONST) Region
))
{
  /* #10 Select the MPU Region for reprogramming. */
  Os_Hal_MpSetRegionNumber(Region->RegionNumber);

  /* #20 Disable the MPU region for the duration of reprogramming. */
  Os_Hal_MpSetRegionEndAddressAndEnable(0);

  /* #30 Write given configuration to the MPU region and enable it again. */
  Os_Hal_MpSetRegionBaseAddressAndAccessRights(Region->RegionBaseAddress | Region-> RegionAccessControl);
  Os_Hal_MpSetRegionEndAddressAndEnable(OS_HAL_MP_REGION_SIZE_64BYTE_ALIGNED(Region->RegionEndAddress)
                                                                            | Region->RegionEnableAndFlags);
}


/***********************************************************************************************************************
 *  Os_Hal_MpInitStackProtectionRegions()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_Hal_MpInitStackProtectionRegions,
(
  P2CONST(Os_Hal_MpRegionType, TYPEDEF, OS_CONST) StartRegion,
  P2CONST(Os_Hal_MpRegionType, TYPEDEF, OS_CONST) EndRegion,
  P2CONST(Os_Hal_ContextStackConfigType, AUTOMATIC, OS_VAR_NOINIT) InitialStackRegion
))
{
  /* #10 Select the Stack Protection MPU Region 0 for reprogramming. */
  Os_Hal_MpSetRegionNumber(OS_HAL_MP_STACK_PROTECTION_REGION_0_NUMBER);

  /* #20 Disable the MPU region for the duration of reprogramming. */
  Os_Hal_MpSetRegionEndAddressAndEnable(0);

  Os_Hal_MpSetRegionBaseAddressAndAccessRights(StartRegion->RegionBaseAddress
                                                    | OS_HAL_MP_ACCESS_EXECUTE_FORBIDDEN | OS_HAL_MP_ACCESS_S_R_U_R);

  /* #30 Write End Address to the MPU region and enable it again. */
  Os_Hal_MpSetRegionEndAddressAndEnable(OS_HAL_MP_REGION_SIZE_64BYTE_ALIGNED(InitialStackRegion->StackRegionStart -64uL)
                                                    | OS_HAL_MP_REGION_SIZE_ENABLE);

  /* #40 Select the Stack Protection MPU Region 1 for reprogramming. */
  Os_Hal_MpSetRegionNumber(OS_HAL_MP_STACK_PROTECTION_REGION_1_NUMBER);

  /* #50 Disable the MPU region for the duration of reprogramming. */
  Os_Hal_MpSetRegionEndAddressAndEnable(0);

  /* #60 Write given configuration to the MPU region and enable it again. */
  Os_Hal_MpSetRegionBaseAddressAndAccessRights((InitialStackRegion->StackRegionEnd +64uL)
                                                    | OS_HAL_MP_ACCESS_EXECUTE_FORBIDDEN | OS_HAL_MP_ACCESS_S_R_U_R);

  Os_Hal_MpSetRegionEndAddressAndEnable(OS_HAL_MP_REGION_SIZE_64BYTE_ALIGNED(EndRegion->RegionEndAddress)
                                                    | OS_HAL_MP_REGION_SIZE_ENABLE);

  /* #70 Instruction Sync Barrier. */
  Os_Hal_InstructionSyncBarrier();
}


/***********************************************************************************************************************
 *  Os_Hal_MpSetStackRegion()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_Hal_MpSetStackRegion,
(
  VAR(uint32, AUTOMATIC) BaseAddress,
  VAR(uint32, AUTOMATIC) Size
))
{
  /* #10 Data Sync Barrier. */
  Os_Hal_DataSyncBarrier();

  /* #20 Select the MPU Region for reprogramming. */
  Os_Hal_MpSetRegionNumber(OS_HAL_MP_STACK_REGION_NUMBER);

  /* #30 Disable the MPU region for the duration of reprogramming. */
  Os_Hal_MpSetRegionEndAddressAndEnable(0);

  /* #40 Write stack base address to the MPU region. */
  /* Set region attributes to execute forbidden, cache and RW for Supervisor and User mode to the MPU region. */
  Os_Hal_MpSetRegionBaseAddressAndAccessRights(BaseAddress |
                                               OS_HAL_MP_ACCESS_EXECUTE_FORBIDDEN |
                                               OS_HAL_MP_ACCESS_S_RW_U_RW);

  /* #50 Set region size and enable it again. Size reflects EndAddress, the name is used only for compatability. */
  Os_Hal_MpSetRegionEndAddressAndEnable(OS_HAL_MP_REGION_SIZE_64BYTE_ALIGNED(Size) | OS_HAL_MP_REGION_SIZE_ENABLE);

  /* #60 Instruction Sync Barrier. */
  Os_Hal_InstructionSyncBarrier();
}


/***********************************************************************************************************************
 *  Os_Hal_MpGetStackRegion()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,                                                             /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_Hal_MpGetStackRegion,
(
  P2VAR(uint32, AUTOMATIC, OS_VAR_NOINIT) BaseAddress,
  P2VAR(uint32, AUTOMATIC, OS_VAR_NOINIT) Size
))
{
  /* #10 Select the MPU Region for reading. */
  Os_Hal_MpSetRegionNumber(OS_HAL_MP_STACK_REGION_NUMBER);

  /* #20 Read base and end address of the stack region. */
  *BaseAddress = Os_Hal_MpGetRegionBaseAddressAndAccessRights() & OS_HAL_MP_REGION_SIZE_ALIGNMENT;                      /* SBSW_OS_HAL_PWA_CALLER */
  /* Size means EndAddress for v8r. The name is used only for compatibility with v7r. */
  *Size = Os_Hal_MpGetRegionEndAddressAndEnable() & OS_HAL_MP_REGION_SIZE_ALIGNMENT;                                    /* SBSW_OS_HAL_PWA_CALLER */
}


/***********************************************************************************************************************
 *  Os_Hal_MpCoreInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_Hal_MpCoreInit,
(
  P2CONST(Os_Hal_MpCoreConfigType , TYPEDEF, OS_CONST) CoreConfig,
  P2CONST(Os_Hal_ContextStackConfigType, AUTOMATIC, OS_VAR_NOINIT) InitialStackRegion
))
{
  uint32 index;
  Os_Hal_IntGlobalStateType state;

  /* #10 Disable interrupts and save old interrupt state. */
  state = Os_Hal_DisableAndReturnPriorState();

  /* #20 Initialize memory attribute indirection registers 0 and 1. */
  Os_Hal_InstructionSyncBarrier();
  Os_Hal_MpSetMemoryAttributeIndirection0(OS_HAL_MP_MAIR0_INIT_VALUE);
  Os_Hal_MpSetMemoryAttributeIndirection1(OS_HAL_MP_MAIR1_INIT_VALUE);

  /* #30 Synchronization barriers. */
  Os_Hal_DataSyncBarrier();
  Os_Hal_InstructionSyncBarrier();

  /* #40 Disable all other MPU regions. */
  Os_Hal_MpDisableAllRegions();

  /* #50 For each configured MPU region: */
  for(index = 3; index < CoreConfig->MpuRegionCount; index++)                                                           /* FETA_OS_HAL_ARM_MPU */
  {
    /* #60 Write configuration to the MPU. */
    Os_Hal_MpWriteRegionDescriptor(&(CoreConfig->MpuRegions[index]));                                                   /* SBSW_OS_HAL_FC_MPUCONFIG */
  }

  /* #70 If this is really a stack and not the startup region: */
  if((InitialStackRegion->StackRegionEnd   != (OS_HAL_MP_STARTUP_REGION_END))  ||
     (InitialStackRegion->StackRegionStart != (OS_HAL_MP_STARTUP_REGION_BASE)) ||
     (InitialStackRegion->StackRegionSize  != OS_HAL_MP_STARTUP_REGION_SIZE))
  {
    /* #80 Set stack region to the passed values. */
    Os_Hal_MpSetStackRegion(InitialStackRegion->StackRegionStart, InitialStackRegion->StackRegionEnd);

    /* #90 Initialize stack protection regions. */
    Os_Hal_MpInitStackProtectionRegions(&(CoreConfig->MpuRegions[OS_HAL_MP_STACK_PROTECTION_REGION_0_NUMBER]), &(CoreConfig->MpuRegions[OS_HAL_MP_STACK_PROTECTION_REGION_1_NUMBER]),InitialStackRegion); /* SBSW_OS_HAL_FC_MPUCONFIG */
  }

  /* #100 Enable the MPU. */
  Os_Hal_MpEnableMPU();

  /* #110 Restore old interrupt state. */
  Os_Hal_RestorePriorIntState(state);
}


/***********************************************************************************************************************
 *  Os_Hal_MpAppSwitch()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_Hal_MpAppSwitch,
(
  P2CONST(Os_Hal_MpAppConfigType, TYPEDEF, OS_CONST) AppConfig
))
{
  uint32 index;

  /* #5 Data Sync Barrier. */
  Os_Hal_DataSyncBarrier();

  /* #10 For each configured MPU region: */
  for(index = 0; index < AppConfig->MpuRegionCount; index++)                                                            /* FETA_OS_HAL_ARM_MPU */
  {
    /* #20 Write the region configuration into the MPU. */
    Os_Hal_MpWriteRegionDescriptor(&(AppConfig->MpuRegions[index]));                                                    /* SBSW_OS_HAL_FC_MPUCONFIG */
  }

  /* #30 Instruction Sync Barrier. */
  Os_Hal_InstructionSyncBarrier();
}


/***********************************************************************************************************************
 *  Os_Hal_MpThreadSwitch()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_Hal_MpThreadSwitch,
(
  P2CONST(Os_Hal_MpThreadConfigType, TYPEDEF, OS_CONST) ThreadConfig
))
{
  uint32 index;

  /* #5 Data Sync Barrier. */
  Os_Hal_DataSyncBarrier();

  /* #10 For each configured MPU region: */
  for(index = 0; index < ThreadConfig->MpuRegionCount; index++)                                                         /* FETA_OS_HAL_ARM_MPU */
  {
    /* #20 Write the region configuration into the MPU. */
    Os_Hal_MpWriteRegionDescriptor(&(ThreadConfig->MpuRegions[index]));                                                 /* SBSW_OS_HAL_FC_MPUCONFIG */
  }

  /* #30 Instruction Sync Barrier. */
  Os_Hal_InstructionSyncBarrier();
}



# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* OS_HAL_MEMORYPROTECTION_PMSAV8_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_MemoryProtection_PMSAv8.h
 *********************************************************************************************************************/
