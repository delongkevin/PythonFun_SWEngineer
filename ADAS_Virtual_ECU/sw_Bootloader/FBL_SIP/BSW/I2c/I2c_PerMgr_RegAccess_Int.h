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
/*!        \file  I2c_PerMgr_RegAccess_Int.h
 *        \brief  Register access abstraction of I2c driver.
 *
 *      \details  -*
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#if !defined (I2C_PERMGR_REGACCESS_INT_H)
# define I2C_PERMGR_REGACCESS_INT_H
typedef  I2c_HwUnitType I2c_PerMgr_HwUnitIdType;

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# if (I2C_PROTECTED_MODE == STD_ON)
#  include "Os.h"
# endif /* I2C_PERMGR_USE_PERIPHERAL_ACCESS_API */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL TYPES
 *********************************************************************************************************************/
/*! Width of a register */
typedef uint32 I2c_PerMgr_RegWidthType;
/*! Offset within the register space of the I2c */
typedef uint8 I2c_PerMgr_RegOffsetType;
/*! Register access type */
typedef volatile I2c_PerMgr_RegWidthType I2c_PerMgr_RegAccessType;
/*! Pointer to a register */
typedef P2VAR(I2c_PerMgr_RegAccessType, AUTOMATIC, MSR_REGSPACE) I2c_PerMgr_RegPtrType;
typedef P2CONST(I2c_PerMgr_RegAccessType, AUTOMATIC, MSR_REGSPACE) I2c_PerMgr_ConstRegPtrType;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# if !defined (I2C_PERMGR_REG_ACCESS_INLINE) /* COV_I2C_PERMGR_COMPATIBILITY */
#  define I2C_PERMGR_REG_ACCESS_INLINE  static INLINE
# endif /* I2C_PERMGR_REG_ACCESS_INLINE */

/**********************************************************************************************************************
 *  HARDWARE SOFTWARE INTERFACE (HSI)
 *********************************************************************************************************************/
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
 */
 
 
/*! I2C Register Offsets (from BASE address). */
# define REG_OFFSET_REVNB_LO                (0x00u)    /*!< Revision Number register (Low). */
# define REG_OFFSET_REVNB_HI                (0x04u)    /*!< Revision Number register (High). */
# define REG_OFFSET_SYSC                    (0x10u)    /*!< System Configuration register. */
# define REG_OFFSET_EOI                     (0x20u)    /*!< End Of Interrupt number. */
# define REG_OFFSET_IRQSTATUS_RAW           (0x24u)    /*!< Per-event raw interrupt status vector. */
# define REG_OFFSET_IRQSTATUS               (0x28u)    /*!< Per-event enabled interrupt status vector. */
# define REG_OFFSET_IRQENABLE_SET           (0x2Cu)    /*!< Per-event interrupt enable bit vector. */
# define REG_OFFSET_IRQENABLE_CLR           (0x30u)    /*!< Per-event interrupt clear bit vector. */
# define REG_OFFSET_WE                      (0x34u)    /*!< I2C wakeup enable vector (legacy). */
# define REG_OFFSET_DMARXENABLE_SET         (0x38u)    /*!< Per-event DMA RX enable set. */
# define REG_OFFSET_DMATXENABLE_SET         (0x3Cu)    /*!< Per-event DMA TX enable set. */
# define REG_OFFSET_DMARXENABLE_CLR         (0x40u)    /*!< Per-event DMA RX enable clear. */
# define REG_OFFSET_DMATXENABLE_CLR         (0x44u)    /*!< Per-event DMA TX enable clear. */
# define REG_OFFSET_DMARXWAKE_EN            (0x48u)    /*!< Per-event DMA RX wakeup enable. */
# define REG_OFFSET_DMATXWAKE_EN            (0x4Cu)    /*!< Per-event DMA TX wakeup enable. */
# define REG_OFFSET_IE                      (0x84u)    /*!< I2C interrupt enable vector (legacy). */
# define REG_OFFSET_STAT                    (0x88u)    /*!< I2C interrupt status vector (legacy). */
# define REG_OFFSET_SYSS                    (0x90u)    /*!< System Status register. */
# define REG_OFFSET_BUF                     (0x94u)    /*!< Buffer Configuration register. */
# define REG_OFFSET_CNT                     (0x98u)    /*!< Data counter register. */
# define REG_OFFSET_DATA                    (0x9Cu)    /*!< Data access register. */
# define REG_OFFSET_CON                     (0xA4u)    /*!< I2C configuration register. */
# define REG_OFFSET_OA                      (0xA8u)    /*!< Own address register. */
# define REG_OFFSET_SA                      (0xACu)    /*!< Slave address register. */
# define REG_OFFSET_PSC                     (0xB0u)    /*!< I2C Clock Prescaler Register. */
# define REG_OFFSET_SCLL                    (0xB4u)    /*!< I2C SCL Low Time Register. */
# define REG_OFFSET_SCLH                    (0xB8u)    /*!< I2C SCL High Time Register. */
# define REG_OFFSET_SYSTEST                 (0xBCu)    /*!< I2C System Test Register. */
# define REG_OFFSET_BUFSTAT                 (0xC0u)    /*!< I2C Buffer Status Register. */
# define REG_OFFSET_OA1                     (0xC4u)    /*!< I2C Own Address 1 Register. */
# define REG_OFFSET_OA2                     (0xC8u)    /*!< I2C Own Address 2 Register. */
# define REG_OFFSET_OA3                     (0xCCu)    /*!< I2C Own Address 3 Register. */
# define REG_OFFSET_ACTOA                   (0xD0u)    /*!< I2C Active Own Address Register. */
# define REG_OFFSET_SBLOCK                  (0xD4u)    /*!< I2C Clock Blocking Enable Register. */

/*! Register masks. */
/*! Register masks for SYSC */
# define REG_MASK_SYSC_AUTOIDLE           (0x0001u)    /*!< Autoidle bit. */
# define REG_MASK_SYSC_SRST               (0x0002u)    /*!< SoftReset bit. */
# define REG_MASK_SYSC_ENAWAKEUP          (0x0004u)    /*!< Enable Wakeup control bit. */
# define REG_MASK_SYSC_IDLEMODE           (0x0018u)    /*!< Idle Mode selection bits. */
# define REG_MASK_SYSC_CLKACTIVITY        (0x0300u)    /*!< Clock Activity selection bits. */

/*! Register masks for IRQSTATUS_RAW */
/*! Register masks for IRQSTATUS */
/*! Register masks for IRQENABLE_SET */
/*! Register masks for IRQENABLE_CLR */
# define REG_MASK_IRQ_AL                  (0x0001u)    /*!< Arbitration lost IRQ. */
# define REG_MASK_IRQ_NACK                (0x0002u)    /*!< No acknowledgement IRQ. */
# define REG_MASK_IRQ_ARDY                (0x0004u)    /*!< Register access ready IRQ. */
# define REG_MASK_IRQ_RRDY                (0x0008u)    /*!< Receive data ready IRQ. */
# define REG_MASK_IRQ_XRDY                (0x0010u)    /*!< Transmit data ready IRQ. */
# define REG_MASK_IRQ_GC                  (0x0020u)    /*!< General call IRQ. */ 
# define REG_MASK_IRQ_STC                 (0x0040u)    /*!< Start Condition IRQ. */
# define REG_MASK_IRQ_AERR                (0x0080u)    /*!< Access Error IRQ. */
# define REG_MASK_IRQ_BF                  (0x0100u)    /*!< Bus Free IRQ. */
# define REG_MASK_IRQ_AAS                 (0x0200u)    /*!< Address recognized as slave IRQ. */
# define REG_MASK_IRQ_XUDF                (0x0400u)    /*!< Transmit underflow. */
# define REG_MASK_IRQ_ROVR                (0x0800u)    /*!< Receive overrun. */
# define REG_MASK_IRQ_BB                  (0x1000u)    /*!< Bus busy. */
# define REG_MASK_IRQ_RDR                 (0x2000u)    /*!< Receive draining. */
# define REG_MASK_IRQ_XDR                 (0x4000u)    /*!< Transmit draining. */

/*! Register masks for all interrupts on IRQSTATUS_RAW, IRQSTATUS, IRQENABLE_SET, IRQENABLE_CLR */
# define REG_MASK_IRQ_ALL                 (0x7FFFu)

/*! Register masks for SYSS */
# define REG_MASK_SYSS_RDONE              (0x0001u)    /*!< Reset done bit. */

/*! Register masks for BUF */
# define REG_MASK_BUF_TXTRSH              (0x003Fu)    /*!< Threshold value for FIFO buffer in TX mode. */
# define REG_MASK_BUF_TXFIFO_CLR          (0x0040u)    /*!< Transmit FIFO clear. */
# define REG_MASK_BUF_XDMA_EN             (0x0080u)    /*!< Transmit DMA channel enable. */
# define REG_MASK_BUF_RXTRSH              (0x3F00u)    /*!< Threshold value for FIFO buffer in RX mode. */
# define REG_MASK_BUF_RXFIFO_CLR          (0x4000u)    /*!< Receive FIFO clear. */
# define REG_MASK_BUF_RDMA_EN             (0x8000u)    /*!< Receive DMA channel enable. */

/*! Register masks for CNT */
# define REG_MASK_CNT_DCOUNT              (0x00FFu)    /*!< Data count. */

/*! Register masks for DATA */
# define REG_MASK_DATA_DATA               (0x00FFu)    /*!< Transmit/Receive data FIFO endpoint. */

/*! Register masks for CON */
# define REG_MASK_CON_STT                 (0x0001u)    /*!< Start condition [master mode only]. */
# define REG_MASK_CON_STP                 (0x0002u)    /*!< Stop condition [master mode only]. */
# define REG_MASK_CON_XOA3                (0x0010u)    /*!< Expand Own address 3. */
# define REG_MASK_CON_XOA2                (0x0020u)    /*!< Expand Own address 2. */
# define REG_MASK_CON_XOA1                (0x0040u)    /*!< Expand Own address 1. */ 
# define REG_MASK_CON_XOA0                (0x0080u)    /*!< Expand Own address 0. */
# define REG_MASK_CON_XSA                 (0x0100u)    /*!< Expand Slave address. */
# define REG_MASK_CON_TRX                 (0x0200u)    /*!< Transmitter/Receiver mode [master mode only]. */
# define REG_MASK_CON_MST                 (0x0400u)    /*!< Master/slave mode. */
# define REG_MASK_CON_STB                 (0x0800u)    /*!< Start byte mode [master mode only]. */
# define REG_MASK_CON_OPMODE              (0x3000u)    /*!< Operation mode selection. */
# define REG_MASK_CON_I2C_EN              (0x8000u)    /*!< I2C module enable. */

/*! Register masks for SA */
# define REG_MASK_SA_SA                   (0x03FFu)    /*!< Slave address. */

/*! Register masks for PSC */
# define REG_MASK_PSC                     (0x00FFu)    /*!< Bitmask for prescaler. */

/*! Register masks for I2C_SYSTEST */
# define REG_MASK_SYSTEST_SDA_O           (0x0001u)    /*!< SDA line drive output value. */
# define REG_MASK_SYSTEST_SDA_I           (0x0002u)    /*!< SDA line sense input value. */
# define REG_MASK_SYSTEST_SCL_O           (0x0004u)    /*!< SCL line drive output value. */
# define REG_MASK_SYSTEST_SCL_I           (0x0008u)    /*!< SCL line sense input value. */
# define REG_MASK_SYSTEST_SCCB_E_O        (0x0010u)    /*!< SCCB_E line sense output value. */
# define REG_MASK_SYSTEST_SDA_O_FUNC      (0x0020u)    /*!< SDA line output value [functional mode]. */ 
# define REG_MASK_SYSTEST_SDA_I_FUNC      (0x0040u)    /*!< SDA line input value [functional mode]. */
# define REG_MASK_SYSTEST_SCL_O_FUNC      (0x0080u)    /*!< SCL line output value [functional mode]. */
# define REG_MASK_SYSTEST_SCL_I_FUNC      (0x0100u)    /*!< SCL line input value [functional mode]. */
# define REG_MASK_SYSTEST_SSB             (0x0800u)    /*!< Set status bits. */
# define REG_MASK_SYSTEST_TMODE           (0x3000u)    /*!< Test mode select. */
# define REG_MASK_SYSTEST_FREE            (0x4000u)    /*!< Free running mode [on breakpoint]. */
# define REG_MASK_SYSTEST_ST_EN           (0x8000u)    /*!< System test enable. */            

/*! Register masks&shifts for BUFSTAT */
# define REG_MASK_BUFSTAT_TXSTAT          (0x003Fu)    /*!< TX Buffer Status. */
# define REG_MASK_BUFSTAT_RXSTAT          (0x3F00u)    /*!< RX Buffer Status. */
# define REG_MASK_BUFSTAT_FIFODEPTH       (0xC000u)    /*!< Internal FIFO buffers depth. */
# define REG_SHIFT_BUFSTAT_FIFODEPTH          (14u)    /*!< Internal FIFO buffers depth field shift. */

/*! Operation modes */
# define REG_CON_OPMODE_FS                (0x0000u)    /*!< Fast mode. */
# define REG_CON_OPMODE_HS                (0x1000u)    /*!< High speed mode. */
# define REG_CON_OPMODE_SCCB              (0x2000u)    /*!< Serial Camera Control Bus (SCCB) Protocol. */


/*! System test modes */
# define REG_SYSTEST_TMODE_FUNCTIONAL     (0x0000u)    /*!< Functional mode. */
# define REG_SYSTEST_TMODE_TEST           (0x2000u)    /*!< Test of SCL serial clock line. */
# define REG_SYSTEST_TMODE_LOOPBACK       (0x3000u)    /*!< Loop-back mode + SCL/SDA I/O. */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define I2C_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  I2c_PerMgr_GetRegBaseAddress
 *********************************************************************************************************************/
/*! \brief        Retrieves the register base address of the given I2c hardware unit.
 *  \details      -
 *  \param[in]    hwUnitId   Id of the hardware unit.
 *  \return       Register base address.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
I2C_PERMGR_REG_ACCESS_INLINE FUNC(uint32, I2C_CODE) I2c_PerMgr_GetRegBaseAddress
(
    I2c_PerMgr_HwUnitIdType hwUnitId
);

# if (I2C_PROTECTED_MODE == STD_ON)
/**********************************************************************************************************************
 *  I2c_PerMgr_GetPeripheralRegion
 *********************************************************************************************************************/
/*! \brief        Retrieves the peripheral region of the given I2c hardware unit.
 *  \details      -
 *  \param[in]    hwUnitId   Id of the hardware unit.
 *  \return       Peripheral region.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
I2C_PERMGR_REG_ACCESS_INLINE FUNC(Os_PeripheralIdType, I2C_CODE) I2c_PerMgr_GetPeripheralRegion
(
    I2c_PerMgr_HwUnitIdType hwUnitId
);

# else

/**********************************************************************************************************************
 *  I2c_PerMgr_CreateRegPtr
 *********************************************************************************************************************/
/*! \brief        Creates a pointer to the addressed register by the offset into the I2c register space.
 *  \details      -
 *  \param[in]    hwUnitId   Id of the hardware unit.
 *  \param[in]    regOffset  Offset in bytes into the I2c register space.
 *  \return       Pointer to the register addressed.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
I2C_PERMGR_REG_ACCESS_INLINE FUNC(I2c_PerMgr_RegPtrType, I2C_CODE) I2c_PerMgr_CreateRegPtr
(
    I2c_PerMgr_HwUnitIdType hwUnitId,
    I2c_PerMgr_RegOffsetType regOffset
);

# endif

/**********************************************************************************************************************
 *  I2c_PerMgr_Reg_Write
 *********************************************************************************************************************/
/*! \brief        Writes the given value to the addressed register.
 *  \details      -
 *  \param[in]    hwUnitId   Id of the hardware unit.
 *  \param[in]    regOffset  Offset in bytes into the I2c register space.
 *  \param[in]    regValue   Value to be written to the register.
 *  \context      ANY
 *  \reentrant    TRUE for different registers
 *  \synchronous  TRUE
 *  \pre          -
 */
I2C_PERMGR_REG_ACCESS_INLINE FUNC(void, I2C_CODE) I2c_PerMgr_Reg_Write
(
    I2c_PerMgr_HwUnitIdType hwUnitId,
    I2c_PerMgr_RegOffsetType regOffset,
    I2c_PerMgr_RegWidthType regValue
);

/**********************************************************************************************************************
 *  I2c_PerMgr_Reg_Read
 *********************************************************************************************************************/
/*! \brief        Reads the value of the addressed register
 *  \details      -
 *  \param[in]    hwUnitId   Id of the hardware unit.
 *  \param[in]    regOffset  Offset in bytes into the I2c register space.
 *  \return       Value of the register.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
I2C_PERMGR_REG_ACCESS_INLINE FUNC(I2c_PerMgr_RegWidthType, I2C_CODE) I2c_PerMgr_Reg_Read
(
    I2c_PerMgr_HwUnitIdType hwUnitId,
    I2c_PerMgr_RegOffsetType regOffset
);

/**********************************************************************************************************************
 *  I2c_PerMgr_Reg_WriteBits
 *********************************************************************************************************************/
/*! \brief        Writes the given value to the specified bit group.
 *  \details      -
 *  \param[in]    hwUnitId      Id of the hardware unit.
 *  \param[in]    regOffset     Offset in bytes into the I2c register space.
 *  \param[in]    bitMask       Bit mask to apply on register value.
 *  \param[in]    bitsValue     Value to be written to the register.
 *  \return       Value of the register.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
I2C_PERMGR_REG_ACCESS_INLINE FUNC(void, I2C_CODE) I2c_PerMgr_Reg_WriteBits
(
    I2c_PerMgr_HwUnitIdType hwUnitId,
    I2c_PerMgr_RegOffsetType regOffset,
    I2c_PerMgr_RegWidthType bitMask,
    I2c_PerMgr_RegWidthType bitsValue
);

/**********************************************************************************************************************
 *  I2c_PerMgr_Reg_SetBitMask
 *********************************************************************************************************************/
/*! \brief        Sets the bits given by the bit mask in the addressed register.
 *  \details      -
 *  \param[in]    hwUnitId   Id of the hardware unit.
 *  \param[in]    regOffset  Offset in bytes into the I2c register space.
 *  \param[in]    bitMask    Bits to be set.
 *  \context      ANY
 *  \reentrant    TRUE for different registers.
 *  \synchronous  TRUE
 *  \pre          -
 */
I2C_PERMGR_REG_ACCESS_INLINE FUNC(void, I2C_CODE) I2c_PerMgr_Reg_SetBitMask
(
    I2c_PerMgr_HwUnitIdType hwUnitId,
    I2c_PerMgr_RegOffsetType regOffset,
    I2c_PerMgr_RegWidthType bitMask
);

/**********************************************************************************************************************
 *  I2c_PerMgr_Reg_ClearBitMask
 *********************************************************************************************************************/
/*! \brief        Clears the bits given by the bit mask in the addressed register.
 *  \details      -
 *  \param[in]    hwUnitId   Id of the hardware unit.
 *  \param[in]    regOffset  Offset in bytes into the I2c register space.
 *  \param[in]    bitMask    Bits to be cleared.
 *  \context      ANY
 *  \reentrant    TRUE for different registers.
 *  \synchronous  TRUE
 *  \pre          -
 */
I2C_PERMGR_REG_ACCESS_INLINE FUNC(void, I2C_CODE) I2c_PerMgr_Reg_ClearBitMask
(
    I2c_PerMgr_HwUnitIdType hwUnitId,
    I2c_PerMgr_RegOffsetType regOffset,
    I2c_PerMgr_RegWidthType bitMask
);

/**********************************************************************************************************************
 *  I2c_PerMgr_Reg_IsBitMaskSet
 *********************************************************************************************************************/
/*! \brief        Checks if all of the bits given by the bit mask are set in the addressed register.
 *  \details      -
 *  \param[in]    hwUnitId   Id of the hardware unit.
 *  \param[in]    regOffset  Offset in bytes into the I2c register space.
 *  \param[in]    bitMask    Bits to be checked for being set.
 *  \return       FALSE - At least one bit of the bit mask isn't set in the register.
 *  \return       TRUE - All bits of the bit mask are set in the register.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
I2C_PERMGR_REG_ACCESS_INLINE FUNC(boolean, I2C_CODE) I2c_PerMgr_Reg_IsBitMaskSet
(
    I2c_PerMgr_HwUnitIdType hwUnitId,
    I2c_PerMgr_RegOffsetType regOffset,
    I2c_PerMgr_RegWidthType bitMask
);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  I2c_PerMgr_GetRegBaseAddress
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
I2C_PERMGR_REG_ACCESS_INLINE FUNC(uint32, I2C_CODE) I2c_PerMgr_GetRegBaseAddress
(
    I2c_PerMgr_HwUnitIdType hwUnitId
)
{
  return I2c_ConfigPtr->HwCfgPtr[hwUnitId].UnitBaseAddr;
} /* I2c_PerMgr_GetRegBaseAddress() */

# if (I2C_PROTECTED_MODE == STD_ON)
/**********************************************************************************************************************
 *  I2c_PerMgr_GetPeripheralRegion
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
I2C_PERMGR_REG_ACCESS_INLINE FUNC(Os_PeripheralIdType, I2C_CODE) I2c_PerMgr_GetPeripheralRegion
(
    I2c_PerMgr_HwUnitIdType hwUnitId
)
{
  return I2c_ConfigPtr->HwCfgPtr[hwUnitId].OsAreaReg;
} /* I2c_PerMgr_GetPeripheralRegion() */

# else
/**********************************************************************************************************************
 *  I2c_PerMgr_CreateRegPtr
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
I2C_PERMGR_REG_ACCESS_INLINE FUNC(I2c_PerMgr_RegPtrType, I2C_CODE) I2c_PerMgr_CreateRegPtr
(
    I2c_PerMgr_HwUnitIdType hwUnitId,
    I2c_PerMgr_RegOffsetType regOffset
)
{
  return (I2c_PerMgr_RegPtrType)(I2c_PerMgr_GetRegBaseAddress(hwUnitId) + regOffset); /* PRQA S 0303 */ /* MD_I2c_PerMgr_0303 */
} /* I2c_PerMgr_CreateRegPtr() */
# endif
/**********************************************************************************************************************
 *  I2c_PerMgr_Reg_Write
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */

I2C_PERMGR_REG_ACCESS_INLINE FUNC(void, I2C_CODE) I2c_PerMgr_Reg_Write
(
    I2c_PerMgr_HwUnitIdType hwUnitId,
    I2c_PerMgr_RegOffsetType regOffset,
    I2c_PerMgr_RegWidthType regValue
)
{
# if (I2C_POLLING_MODE == STD_ON)
  if(regOffset != REG_OFFSET_IRQENABLE_SET)
# endif
  {
# if (I2C_PROTECTED_MODE == STD_ON)
    Os_WritePeripheral32(I2c_PerMgr_GetPeripheralRegion(hwUnitId),
        (P2VAR(uint32, AUTOMATIC, I2C_VAR))(regOffset + I2c_PerMgr_GetRegBaseAddress(hwUnitId)), regValue); /* PRQA S 306 */ /* MD_I2c_PerMgr_0306 */ /* SBSW_I2C_PERMGR_REGACCESS */
# else
    I2c_PerMgr_RegPtrType reg = I2c_PerMgr_CreateRegPtr(hwUnitId, regOffset);
    *reg = regValue; /* SBSW_I2C_PERMGR_REGACCESS */
# endif
  }
} /* I2c_PerMgr_Reg_Write() */

/**********************************************************************************************************************
 *  I2c_PerMgr_Reg_Read
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
I2C_PERMGR_REG_ACCESS_INLINE FUNC(I2c_PerMgr_RegWidthType, I2C_CODE) I2c_PerMgr_Reg_Read
(
    I2c_PerMgr_HwUnitIdType hwUnitId,
    I2c_PerMgr_RegOffsetType regOffset
)
{
# if (I2C_PROTECTED_MODE == STD_ON)
  return Os_ReadPeripheral32(I2c_PerMgr_GetPeripheralRegion(hwUnitId),
      (P2CONST(uint32, AUTOMATIC, I2C_VAR))(regOffset + I2c_PerMgr_GetRegBaseAddress(hwUnitId))); /* PRQA S 306 */ /* MD_I2c_PerMgr_0306 */ /* SBSW_I2C_PERMGR_REGACCESS */
# else
  I2c_PerMgr_RegWidthType regValue;
  I2c_PerMgr_ConstRegPtrType reg = I2c_PerMgr_CreateRegPtr(hwUnitId, regOffset);
  regValue = *reg;
  return regValue;
# endif
} /* I2c_PerMgr_Reg_Read() */

/**********************************************************************************************************************
 *  I2c_PerMgr_Reg_SetBitMask
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
I2C_PERMGR_REG_ACCESS_INLINE FUNC(void, I2C_CODE) I2c_PerMgr_Reg_SetBitMask
(
    I2c_PerMgr_HwUnitIdType hwUnitId,
    I2c_PerMgr_RegOffsetType regOffset,
    I2c_PerMgr_RegWidthType bitMask
)
{
  I2c_PerMgr_Reg_Write(hwUnitId, regOffset, I2c_PerMgr_Reg_Read(hwUnitId, regOffset) | bitMask);
} /* I2c_PerMgr_Reg_SetBitMask() */

/**********************************************************************************************************************
 *  I2c_PerMgr_Reg_ClearBitMask
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
I2C_PERMGR_REG_ACCESS_INLINE FUNC(void, I2C_CODE) I2c_PerMgr_Reg_ClearBitMask
(
    I2c_PerMgr_HwUnitIdType hwUnitId,
    I2c_PerMgr_RegOffsetType regOffset,
    I2c_PerMgr_RegWidthType bitMask
)
{
  I2c_PerMgr_Reg_Write(hwUnitId, regOffset, I2c_PerMgr_Reg_Read(hwUnitId, regOffset) & (~bitMask));
} /* I2c_PerMgr_Reg_ClearBitMask() */

/**********************************************************************************************************************
 *  I2c_PerMgr_Reg_IsBitMaskSet
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */

I2C_PERMGR_REG_ACCESS_INLINE FUNC(boolean, I2C_CODE) I2c_PerMgr_Reg_IsBitMaskSet
(
    I2c_PerMgr_HwUnitIdType hwUnitId,
    I2c_PerMgr_RegOffsetType regOffset,
    I2c_PerMgr_RegWidthType bitMask
)
{
  boolean result = FALSE;
  if((I2c_PerMgr_Reg_Read(hwUnitId, regOffset) & bitMask) == bitMask)
  {
    result = TRUE;
  }
  return result;
} /* I2c_PerMgr_Reg_IsBitMaskSet() */

/**********************************************************************************************************************
 *  I2c_PerMgr_Reg_WriteBits
 *********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
I2C_PERMGR_REG_ACCESS_INLINE FUNC(void, I2C_CODE) I2c_PerMgr_Reg_WriteBits
(
    I2c_PerMgr_HwUnitIdType hwUnitId,
    I2c_PerMgr_RegOffsetType regOffset,
    I2c_PerMgr_RegWidthType bitMask,
    I2c_PerMgr_RegWidthType bitsValue
)
{
  I2c_PerMgr_RegWidthType regValue = I2c_PerMgr_Reg_Read(hwUnitId, regOffset);
  regValue &= (~bitMask);
  regValue |= bitsValue;
  I2c_PerMgr_Reg_Write(hwUnitId, regOffset, regValue);
} /* I2c_PerMgr_Reg_WriteBits() */

/**********************************************************************************************************************
 *  I2c_PerMgr_Reg_WaitStatusMask()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */

# define I2C_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

#endif /* I2C_PERMGR_REGACCESS_INT_H */

/* Justification for module-specific MISRA deviations
 MD_I2c_PerMgr_0303:
    Reason:     Hardware register accesses need a cast from integral type to a pointer to volatile object.
    Risk:       There is no risk as the register is mapped to the respective memory address.
    Prevention: Covered by code review.

 MD_I2c_PerMgr_0306:
    Reason:     Hardware register accesses need a cast from integral type to a pointer to object.
    Risk:       There is no risk as the register is mapped to the respective memory address.
    Prevention: Covered by code review.
*/

/* START_COVERAGE_JUSTIFICATION

Code coverage:

Variant coverage:

\ID COV_I2C_PERMGR_COMPATIBILITY
 \ACCEPT TX
 \REASON COV_MSR_COMPATIBILITY

END_COVERAGE_JUSTIFICATION */

/**********************************************************************************************************************
 *  END OF FILE: I2c_PerMgr_RegAccess_Int.h
 *********************************************************************************************************************/

