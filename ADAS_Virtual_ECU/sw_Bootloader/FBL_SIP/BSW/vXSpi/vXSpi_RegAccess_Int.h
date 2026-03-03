/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vXSpi_RegAccess_Int.h
 *        \brief  Register access abstraction of vXSpi driver.
 *
 *      \details  Abstraction of vXSpi driver register access.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VXSPI_REGACCESS_INT_H)
# define VXSPI_REGACCESS_INT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL TYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# if !defined (VXSPI_REG_ACCESS_INLINE) /* COV_VXSPI_COMPATIBILITY */
#  define VXSPI_REG_ACCESS_INLINE static INLINE
# endif /* VXSPI_REG_ACCESS_INLINE */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define VXSPI_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vXSpi_GetRegBaseAddress()
 *********************************************************************************************************************/
/*! \brief        Retrieves the register base address of the given xSPI hardware unit.
 *  \details      -
 *  \param[in]    HwUnitId   Id of the hardware unit.
 *  \return       Register base address.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
VXSPI_REG_ACCESS_INLINE FUNC(vXSpi_AddressType, VXSPI_CODE) vXSpi_GetRegBaseAddress
(
    vXSpi_HwUnitIdType HwUnitId
);

/**********************************************************************************************************************
 *  vXSpi_CreateRegPtr()
 *********************************************************************************************************************/
/*! \brief        Creates a pointer to the addressed register by the offset into the xSPI register space.
 *  \details      -
 *  \param[in]    HwUnitId   Id of the hardware unit.
 *  \param[in]    RegOffset  Offset in bytes into the xSPI register space.
 *  \return       Pointer to the register addressed.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
VXSPI_REG_ACCESS_INLINE FUNC(vXSpi_RegPtrType, VXSPI_CODE) vXSpi_CreateRegPtr
(
    vXSpi_HwUnitIdType HwUnitId,
    vXSpi_RegOffsetType RegOffset
);

/**********************************************************************************************************************
 *  vXSpi_Reg_Write()
 *********************************************************************************************************************/
/*! \brief        Writes the given value to the addressed register.
 *  \details      -
 *  \param[in]    HwUnitId   Id of the hardware unit.
 *  \param[in]    RegOffset  Offset in bytes into the xSPI register space.
 *  \param[in]    regValue   Value to be written to the register.
 *  \context      ANY
 *  \reentrant    TRUE for different registers
 *  \synchronous  TRUE
 *  \pre          -
 */
VXSPI_REG_ACCESS_INLINE FUNC(void, VXSPI_CODE) vXSpi_Reg_Write
(
    vXSpi_HwUnitIdType HwUnitId,
    vXSpi_RegOffsetType RegOffset,
    vXSpi_RegWidthType regValue
);

/**********************************************************************************************************************
 *  vXSpi_Reg_Read()
 *********************************************************************************************************************/
/*! \brief        Reads the value of the addressed register
 *  \details      -
 *  \param[in]    HwUnitId   Id of the hardware unit.
 *  \param[in]    RegOffset  Offset in bytes into the xSPI register space.
 *  \return       Value of the register.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
VXSPI_REG_ACCESS_INLINE FUNC(vXSpi_RegWidthType, VXSPI_CODE) vXSpi_Reg_Read
(
    vXSpi_HwUnitIdType HwUnitId,
    vXSpi_RegOffsetType RegOffset
);

/**********************************************************************************************************************
 *  vXSpi_Reg_ReadBits()
 *********************************************************************************************************************/
/*! \brief        Reads the value of the addressed register and applies bit mask.
 *  \details      -
 *  \param[in]    HwUnitId  Id of the hardware unit.
 *  \param[in]    RegOffset  Offset in bytes into the xSPI register space.
 *  \param[in]    BitMask    Bit mask to apply on register value.
 *  \return       Value of the register.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
VXSPI_REG_ACCESS_INLINE FUNC(vXSpi_RegWidthType, VXSPI_CODE) vXSpi_Reg_ReadBits
(
    vXSpi_HwUnitIdType HwUnitId,
    vXSpi_RegOffsetType RegOffset,
    vXSpi_RegWidthType BitMask
);

/**********************************************************************************************************************
 *  vXSpi_Reg_WriteBits()
 *********************************************************************************************************************/
/*! \brief        Writes the given value to the specified bit group.
 *  \details      -
 *  \param[in]    HwUnitId      Id of the hardware unit.
 *  \param[in]    RegOffset     Offset in bytes into the xSPI register space.
 *  \param[in]    BitMask       Bit mask to apply on register value.
 *  \param[in]    BitsValue     Value to be written to the register.
 *  \return       Value of the register.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
VXSPI_REG_ACCESS_INLINE FUNC(void, VXSPI_CODE) vXSpi_Reg_WriteBits
(
    vXSpi_HwUnitIdType HwUnitId,
    vXSpi_RegOffsetType RegOffset,
    vXSpi_RegWidthType BitMask,
    vXSpi_RegWidthType BitsValue
);

/**********************************************************************************************************************
 *  vXSpi_Reg_SetBitMask()
 *********************************************************************************************************************/
/*! \brief        Sets the bits given by the bit mask in the addressed register.
 *  \details      -
 *  \param[in]    HwUnitId   Id of the hardware unit.
 *  \param[in]    RegOffset  Offset in bytes into the xSPI register space.
 *  \param[in]    BitMask    Bits to be set.
 *  \context      ANY
 *  \reentrant    TRUE for different registers.
 *  \synchronous  TRUE
 *  \pre          -
 */
VXSPI_REG_ACCESS_INLINE FUNC(void, VXSPI_CODE) vXSpi_Reg_SetBitMask
(
    vXSpi_HwUnitIdType HwUnitId,
    vXSpi_RegOffsetType RegOffset,
    vXSpi_RegWidthType BitMask
);

/**********************************************************************************************************************
 *  vXSpi_Reg_ClearBitMask()
 *********************************************************************************************************************/
/*! \brief        Clears the bits given by the bit mask in the addressed register.
 *  \details      -
 *  \param[in]    HwUnitId   Id of the hardware unit.
 *  \param[in]    RegOffset  Offset in bytes into the xSPI register space.
 *  \param[in]    BitMask    Bits to be cleared.
 *  \context      ANY
 *  \reentrant    TRUE for different registers.
 *  \synchronous  TRUE
 *  \pre          -
 */
VXSPI_REG_ACCESS_INLINE FUNC(void, VXSPI_CODE) vXSpi_Reg_ClearBitMask
(
    vXSpi_HwUnitIdType HwUnitId,
    vXSpi_RegOffsetType RegOffset,
    vXSpi_RegWidthType BitMask
);

/**********************************************************************************************************************
 *  vXSpi_Reg_IsBitMaskSet()
 *********************************************************************************************************************/
/*! \brief        Checks if all of the bits given by the bit mask are set in the addressed register.
 *  \details      -
 *  \param[in]    HwUnitId   Id of the hardware unit.
 *  \param[in]    RegOffset  Offset in bytes into the xSPI register space.
 *  \param[in]    BitMask    Bits to be checked for being set.
 *  \return       FALSE - At least one bit of the bit mask isn't set in the register.
 *  \return       TRUE - All bits of the bit mask are set in the register.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
VXSPI_REG_ACCESS_INLINE FUNC(boolean, VXSPI_CODE) vXSpi_Reg_IsBitMaskSet
(
    vXSpi_HwUnitIdType HwUnitId,
    vXSpi_RegOffsetType RegOffset,
    vXSpi_RegWidthType BitMask
);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  vXSpi_GetRegBaseAddress()
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
VXSPI_REG_ACCESS_INLINE FUNC(vXSpi_AddressType, VXSPI_CODE) vXSpi_GetRegBaseAddress /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_HwUnitIdType HwUnitId
)
{
  return vXSpi_Cfg_HwUnit_GetRegisterBaseAddress(HwUnitId);
} /* vXSpi_GetRegBaseAddress */

/**********************************************************************************************************************
 *  vXSpi_CreateRegPtr()
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
VXSPI_REG_ACCESS_INLINE FUNC(vXSpi_RegPtrType, VXSPI_CODE) vXSpi_CreateRegPtr /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_HwUnitIdType HwUnitId,
    vXSpi_RegOffsetType RegOffset
)
{
  return (vXSpi_RegPtrType)(vXSpi_GetRegBaseAddress(HwUnitId) + RegOffset); /* PRQA S 0303 */ /* MD_vXSpi_0303 */
} /* vXSpi_CreateRegPtr */

/**********************************************************************************************************************
 *  vXSpi_Reg_Write()
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
VXSPI_REG_ACCESS_INLINE FUNC(void, VXSPI_CODE) vXSpi_Reg_Write /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_HwUnitIdType HwUnitId,
    vXSpi_RegOffsetType RegOffset,
    vXSpi_RegWidthType regValue
)
{
# if (VXSPI_USE_PERIPHERAL_ACCESS_API == STD_ON)
  /* PRQA S 0306 2 */ /* MD_vXSpi_MemoryMappedAccess */
  Os_WritePeripheral32(vXSpi_Cfg_HwUnit_GetPeripheralId(HwUnitId), 
                      (P2VAR(uint32, AUTOMATIC, VXSPI_APPL_VAR)) (RegOffset + vXSpi_GetRegBaseAddress(HwUnitId)), regValue);
# else
  vXSpi_RegPtrType reg = vXSpi_CreateRegPtr(HwUnitId, RegOffset);
  *reg = regValue;
# endif
} /* vXSpi_Reg_Write */

/**********************************************************************************************************************
 *  vXSpi_Reg_Read()
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
VXSPI_REG_ACCESS_INLINE FUNC(vXSpi_RegWidthType, VXSPI_CODE) vXSpi_Reg_Read /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_HwUnitIdType HwUnitId,
    vXSpi_RegOffsetType RegOffset
)
{
# if (VXSPI_USE_PERIPHERAL_ACCESS_API == STD_ON)
  /* PRQA S 0306 2 */ /* MD_vXSpi_MemoryMappedAccess */
  return Os_ReadPeripheral32(vXSpi_Cfg_HwUnit_GetPeripheralId(HwUnitId), 
                            (P2CONST(uint32, AUTOMATIC, VXSPI_APPL_CONST)) (RegOffset + vXSpi_GetRegBaseAddress(HwUnitId)));
# else
  vXSpi_ConstRegPtrType reg = vXSpi_CreateRegPtr(HwUnitId, RegOffset);
  return *reg;
# endif
} /* vXSpi_Reg_Read */

/**********************************************************************************************************************
 *  vXSpi_Reg_ReadBits()
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
VXSPI_REG_ACCESS_INLINE FUNC(vXSpi_RegWidthType, VXSPI_CODE) vXSpi_Reg_ReadBits /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_HwUnitIdType HwUnitId,
    vXSpi_RegOffsetType RegOffset,
    vXSpi_RegWidthType BitMask
)
{
  return (vXSpi_Reg_Read(HwUnitId, RegOffset) & BitMask);
} /* vXSpi_Reg_ReadBits */

/**********************************************************************************************************************
 *  vXSpi_Reg_WriteBits()
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
VXSPI_REG_ACCESS_INLINE FUNC(void, VXSPI_CODE) vXSpi_Reg_WriteBits  /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_HwUnitIdType HwUnitId,
    vXSpi_RegOffsetType RegOffset,
    vXSpi_RegWidthType BitMask,
    vXSpi_RegWidthType BitsValue
)
{
  vXSpi_RegWidthType regValue = vXSpi_Reg_Read(HwUnitId, RegOffset);
  vXSpi_Reg_Write(HwUnitId, RegOffset, (regValue & ~BitMask) | (BitsValue & BitMask));

} /* vXSpi_Reg_WriteBits */

/**********************************************************************************************************************
 *  vXSpi_Reg_SetBitMask()
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
VXSPI_REG_ACCESS_INLINE FUNC(void, VXSPI_CODE) vXSpi_Reg_SetBitMask /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_HwUnitIdType HwUnitId,
    vXSpi_RegOffsetType RegOffset,
    vXSpi_RegWidthType BitMask
)
{
  vXSpi_Reg_Write(HwUnitId, RegOffset, vXSpi_Reg_Read(HwUnitId, RegOffset) | BitMask);
} /* vXSpi_Reg_SetBitMask */

/**********************************************************************************************************************
 *  vXSpi_Reg_ClearBitMask()
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
VXSPI_REG_ACCESS_INLINE FUNC(void, VXSPI_CODE) vXSpi_Reg_ClearBitMask /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_HwUnitIdType HwUnitId,
    vXSpi_RegOffsetType RegOffset,
    vXSpi_RegWidthType BitMask
)
{
  vXSpi_Reg_Write(HwUnitId, RegOffset, vXSpi_Reg_Read(HwUnitId, RegOffset) & ~BitMask);
} /* vXSpi_Reg_ClearBitMask */

/**********************************************************************************************************************
 *  vXSpi_Reg_IsBitMaskSet()
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
VXSPI_REG_ACCESS_INLINE FUNC(boolean, VXSPI_CODE) vXSpi_Reg_IsBitMaskSet /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_HwUnitIdType HwUnitId,
    vXSpi_RegOffsetType RegOffset,
    vXSpi_RegWidthType BitMask
)
{
  boolean result = FALSE;

  if((vXSpi_Reg_Read(HwUnitId, RegOffset) & BitMask) == BitMask)
  {
    result = TRUE;
  }

  return result;
} /* vXSpi_Reg_IsBitMaskSet */

# define VXSPI_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* VXSPI_REGACCESS_INT_H */

/**********************************************************************************************************************
 *  END OF FILE: vXSpi_RegAccess_Int.h
 *********************************************************************************************************************/

