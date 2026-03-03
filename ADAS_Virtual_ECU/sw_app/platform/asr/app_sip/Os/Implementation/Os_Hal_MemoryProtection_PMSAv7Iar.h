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
 * \file       Os_Hal_MemoryProtection_PMSAv7Iar.h
 * \brief      Memory protection primitives for the Protected Memory System Architecture (PMSA) used by ARMv7-A and
 *             ARMv7-R.
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

#ifndef  OS_HAL_MEMORYPROTECTION_PMSAV7IAR_H
# define OS_HAL_MEMORYPROTECTION_PMSAV7IAR_H
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
/*! \brief        Set MPU Region Number Register (RGNR) of the PMSA.
 *  \details      Write to coprocessor register.
 *  \param[in]    Value  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_MpSetRegionNumber(Value)          Os_Hal_WriteToCoprocessor(Value, 15, 0, 6, 2, 0)


/***********************************************************************************************************************
 *  Os_Hal_MpSetRegionBaseAddress()
 **********************************************************************************************************************/
/*! \brief        Set Data Region Base Address Register (DRBAR) of the PMSA.
 *  \details      Write to coprocessor register.
 *  \param[in]    Value  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_MpSetRegionBaseAddress(Value)     Os_Hal_WriteToCoprocessor(Value, 15, 0, 6, 1, 0)


/***********************************************************************************************************************
 *  Os_Hal_MpGetRegionBaseAddress()
 **********************************************************************************************************************/
/*! \brief        Returns Data Region Base Address Register (DRBAR) of the PMSA.
 *  \details      Read from coprocessor register.
 *  \return       DRBAR value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_MpGetRegionBaseAddress()          Os_Hal_ReadFromCoprocessor(15, 0, 6, 1, 0)


/***********************************************************************************************************************
 *  Os_Hal_MpSetRegionSizeAndEnable()
 **********************************************************************************************************************/
/*! \brief        Set Data Region Size and Enable Register (DRSR) of the PMSA.
 *  \details      Write to coprocessor register.
 *  \param[in]    Value  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_MpSetRegionSizeAndEnable(Value)   Os_Hal_WriteToCoprocessor(Value, 15, 0, 6, 1, 2)


/***********************************************************************************************************************
 *  Os_Hal_MpGetRegionSizeAndEnable()
 **********************************************************************************************************************/
/*! \brief        Returns Data Region Size and Enable Register (DRSR) of the PMSA.
 *  \details      Read from coprocessor register.
 *  \return       DRSR value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_MpGetRegionSizeAndEnable()        Os_Hal_ReadFromCoprocessor(15, 0, 6, 1, 2)


/***********************************************************************************************************************
 *  Os_Hal_MpSetRegionAccessControl()
 **********************************************************************************************************************/
/*! \brief        Set Data Region Access Control Register (DRACR) of the PMSA.
 *  \details      Write to coprocessor register.
 *  \param[in]    Value  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_MpSetRegionAccessControl(Value)   Os_Hal_WriteToCoprocessor(Value, 15, 0, 6, 1, 4)


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
 *  Os_Hal_MpDisableMPU()
 **********************************************************************************************************************/
/*! \brief        Disables the MPU.
 *  \details      -
 *  \context      ANY
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_Hal_MpDisableMPU, (void));


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
 *  Os_Hal_MpSetStartupRegion()
 **********************************************************************************************************************/
/*! \brief        Sets a startup region.
 *  \details      Set up a temporary region with the highest priority and RWX access to the whole address space.
 *  \context      ANY
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_Hal_MpSetStartupRegion, (void));


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
 *  Os_Hal_MpDisableMPU()
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
OS_ALWAYS_INLINE, Os_Hal_MpDisableMPU, (void))
{
  /* #10 Get SCTLR. */
  uint32 systemControl = Os_Hal_GetSystemControl();
  systemControl &= ~(OS_HAL_MP_SYSTEMCONTROL_ENABLE_MPU);

  /* #20 Data Sync Barrier. */
  Os_Hal_DataSyncBarrier();

  /* #30 Clear SCTLR.M and SCTLR.BR bits. */
  Os_Hal_SetSystemControl(systemControl);

  /* #40 Instruction Sync Barrier. */
  Os_Hal_InstructionSyncBarrier();
}


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
  systemControl |= OS_HAL_MP_SYSTEMCONTROL_ENABLE_MPU | OS_HAL_MP_SYSTEMCONTROL_BACKGROUND_REGION;

  /* #20 Data Sync Barrier. */
  Os_Hal_DataSyncBarrier();

  /* #30 Set SCTLR.M and SCTLR.BR bits. */
  Os_Hal_SetSystemControl(systemControl);

  /* #40 Instruction Sync Barrier. */
  Os_Hal_InstructionSyncBarrier();
}


/***********************************************************************************************************************
 *  Os_Hal_MpSetStartupRegion()
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
OS_ALWAYS_INLINE, Os_Hal_MpSetStartupRegion,
(
  void
))
{
  /* #10 Data Sync Barrier. */
  Os_Hal_DataSyncBarrier();

  /* #20 Select the MPU Region for reprogramming. */
  Os_Hal_MpSetRegionNumber(OS_HAL_MP_STACK_REGION_NUMBER);

  /* #30 Set region attributes to full access incl execution. */
  Os_Hal_MpSetRegionAccessControl(OS_HAL_MP_STARTUP_REGION_ACCESSRIGHTS);

  /* #40 Write the base address to the MPU region. */
  Os_Hal_MpSetRegionBaseAddress(OS_HAL_MP_STARTUP_REGION_BASE);

  /* #50 Set region size and enable it. */
  Os_Hal_MpSetRegionSizeAndEnable(OS_HAL_MP_STARTUP_REGION_SIZE);

  /* #60 Instruction Sync Barrier. */
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
  const uint8_least NumberOfRegions = (uint8_least)(((Os_Hal_MpGetMpuType() >> 8) & 0xFFuL) - 1u);

  /* #10 For all available MPU regions except the stack region: */
  for(index = 0u; index < NumberOfRegions; index++)                                                                     /* FETA_OS_HAL_ARM_MPU */
  {
    /* #20 Disable the region. */
    Os_Hal_MpSetRegionNumber(index);
    Os_Hal_MpSetRegionSizeAndEnable(0u);
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
  Os_Hal_MpSetRegionSizeAndEnable(0u);

  /* #30 Write given configuration to the MPU region and enable it again. */
  Os_Hal_MpSetRegionBaseAddress(Region->RegionBaseAddress);
  Os_Hal_MpSetRegionAccessControl(Region->RegionAccessControl);
  Os_Hal_MpSetRegionSizeAndEnable(Region->RegionSizeAndEnable);
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
  Os_Hal_MpSetRegionSizeAndEnable(0u);

  /* #40 Write stack base address to the MPU region. */
  Os_Hal_MpSetRegionBaseAddress(BaseAddress);

  /* #50 Set region attributes to execute forbidden, cache and RW for Supervisor and User mode to the MPU region. */
  Os_Hal_MpSetRegionAccessControl(OS_HAL_MP_ACCESS_EXECUTE_FORBIDDEN |
                                  OS_HAL_MP_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE |
                                  OS_HAL_MP_ACCESS_S_RW_U_RW);

  /* #60 Set region size and enable it again. */
  Os_Hal_MpSetRegionSizeAndEnable(Size);

  /* #70 Instruction Sync Barrier. */
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
  /* #20 Read base address and size of the stack region. */
  *BaseAddress = Os_Hal_MpGetRegionBaseAddress();                                                                       /* SBSW_OS_HAL_PWA_CALLER */
  *Size = Os_Hal_MpGetRegionSizeAndEnable();                                                                            /* SBSW_OS_HAL_PWA_CALLER */
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

  /* #20  Disable the MPU. */
  Os_Hal_MpDisableMPU();

  /* #30 Setup a startup region to be used during initialization. */
  Os_Hal_MpSetStartupRegion();

  /* #40 Disable all other MPU regions. */
  Os_Hal_MpDisableAllRegions();

  /* #50 If this is really a stack and not the startup region: */
  if((InitialStackRegion->StackRegionEnd   != OS_HAL_MP_STARTUP_REGION_END)  ||
     (InitialStackRegion->StackRegionStart != OS_HAL_MP_STARTUP_REGION_BASE) ||
     (InitialStackRegion->StackRegionSize  != OS_HAL_MP_STARTUP_REGION_SIZE) )
  {
    /* #60 Set stack region to the passed values. */
    Os_Hal_MpSetStackRegion(InitialStackRegion->StackRegionStart, InitialStackRegion->StackRegionSize);
  }

  /* #70 For each configured MPU region: */
  for(index = 0; index < CoreConfig->MpuRegionCount; index++)                                                           /* FETA_OS_HAL_ARM_MPU */
  {
    /* #80 Write configuration to the MPU. */
    Os_Hal_MpWriteRegionDescriptor(&(CoreConfig->MpuRegions[index]));                                                   /* SBSW_OS_HAL_FC_MPUCONFIG */
  }

  /* #90 Enable the MPU. */
  Os_Hal_MpEnableMPU();

  /* #100 Restore old interrupt state. */
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

#endif /* OS_HAL_MEMORYPROTECTION_PMSAV7IAR_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_MemoryProtection_PMSAv7Iar.h
 *********************************************************************************************************************/
