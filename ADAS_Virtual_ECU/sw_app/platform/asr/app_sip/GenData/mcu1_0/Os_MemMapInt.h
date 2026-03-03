/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_MemMapInt.h
 *   Generation Time: 2024-02-13 13:07:50
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

                                                                                                                        /* PRQA S 0883 */ /* MD_Os_Dir4.10_0883_MemMap */

/**********************************************************************************************************************
 *  CODE SECTIONS  (Llvm_TexasInstruments)
 *********************************************************************************************************************/

#ifdef OS_START_SEC_ERRORHOOK_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_ERRORHOOK_CODE_OPEN
# pragma clang section text = ".OS_ERRORHOOK_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_ERRORHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_ERRORHOOK_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_ERRORHOOK_CODE_OPEN
#  error Section OS_ERRORHOOK_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_ERRORHOOK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_ERRORHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OS_COREINITHOOK_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OS_COREINITHOOK_CODE_OPEN
# pragma clang section text = ".OS_OS_COREINITHOOK_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OS_COREINITHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OS_COREINITHOOK_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OS_COREINITHOOK_CODE_OPEN
#  error Section OS_OS_COREINITHOOK_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_OS_COREINITHOOK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OS_COREINITHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_PANICHOOK_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_PANICHOOK_CODE_OPEN
# pragma clang section text = ".OS_PANICHOOK_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_PANICHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_PANICHOOK_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_PANICHOOK_CODE_OPEN
#  error Section OS_PANICHOOK_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_PANICHOOK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_PANICHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_PROTECTIONHOOK_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_PROTECTIONHOOK_CODE_OPEN
# pragma clang section text = ".OS_PROTECTIONHOOK_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_PROTECTIONHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_PROTECTIONHOOK_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_PROTECTIONHOOK_CODE_OPEN
#  error Section OS_PROTECTIONHOOK_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_PROTECTIONHOOK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_PROTECTIONHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SHUTDOWNHOOK_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SHUTDOWNHOOK_CODE_OPEN
# pragma clang section text = ".OS_SHUTDOWNHOOK_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SHUTDOWNHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SHUTDOWNHOOK_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SHUTDOWNHOOK_CODE_OPEN
#  error Section OS_SHUTDOWNHOOK_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SHUTDOWNHOOK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SHUTDOWNHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_Adc_IrqUnit0_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Adc_IrqUnit0_CODE_OPEN
# pragma clang section text = ".OS_Adc_IrqUnit0_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_Adc_IrqUnit0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_Adc_IrqUnit0_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_Adc_IrqUnit0_CODE_OPEN
#  error Section OS_Adc_IrqUnit0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Adc_IrqUnit0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_Adc_IrqUnit0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_Adc_IrqUnit1_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Adc_IrqUnit1_CODE_OPEN
# pragma clang section text = ".OS_Adc_IrqUnit1_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_Adc_IrqUnit1_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_Adc_IrqUnit1_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_Adc_IrqUnit1_CODE_OPEN
#  error Section OS_Adc_IrqUnit1_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Adc_IrqUnit1_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_Adc_IrqUnit1_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_BootAppOsTask_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_BootAppOsTask_CODE_OPEN
# pragma clang section text = ".OS_BootAppOsTask_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_BootAppOsTask_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_BootAppOsTask_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_BootAppOsTask_CODE_OPEN
#  error Section OS_BootAppOsTask_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_BootAppOsTask_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_BootAppOsTask_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_Can_30_McanIsr_0_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Can_30_McanIsr_0_CODE_OPEN
# pragma clang section text = ".OS_Can_30_McanIsr_0_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_Can_30_McanIsr_0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_Can_30_McanIsr_0_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_Can_30_McanIsr_0_CODE_OPEN
#  error Section OS_Can_30_McanIsr_0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Can_30_McanIsr_0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_Can_30_McanIsr_0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_Can_30_McanIsr_1_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Can_30_McanIsr_1_CODE_OPEN
# pragma clang section text = ".OS_Can_30_McanIsr_1_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_Can_30_McanIsr_1_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_Can_30_McanIsr_1_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_Can_30_McanIsr_1_CODE_OPEN
#  error Section OS_Can_30_McanIsr_1_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Can_30_McanIsr_1_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_Can_30_McanIsr_1_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_I2c_IrqUnit0_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_I2c_IrqUnit0_CODE_OPEN
# pragma clang section text = ".OS_I2c_IrqUnit0_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_I2c_IrqUnit0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_I2c_IrqUnit0_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_I2c_IrqUnit0_CODE_OPEN
#  error Section OS_I2c_IrqUnit0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_I2c_IrqUnit0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_I2c_IrqUnit0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_I2c_IrqUnit1_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_I2c_IrqUnit1_CODE_OPEN
# pragma clang section text = ".OS_I2c_IrqUnit1_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_I2c_IrqUnit1_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_I2c_IrqUnit1_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_I2c_IrqUnit1_CODE_OPEN
#  error Section OS_I2c_IrqUnit1_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_I2c_IrqUnit1_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_I2c_IrqUnit1_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_IPC_mailbox1_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_IPC_mailbox1_CODE_OPEN
# pragma clang section text = ".OS_IPC_mailbox1_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_IPC_mailbox1_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_IPC_mailbox1_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_IPC_mailbox1_CODE_OPEN
#  error Section OS_IPC_mailbox1_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_IPC_mailbox1_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_IPC_mailbox1_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_IPC_mailbox2_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_IPC_mailbox2_CODE_OPEN
# pragma clang section text = ".OS_IPC_mailbox2_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_IPC_mailbox2_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_IPC_mailbox2_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_IPC_mailbox2_CODE_OPEN
#  error Section OS_IPC_mailbox2_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_IPC_mailbox2_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_IPC_mailbox2_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_MAIN_ESM0_ESM_INT_CFG_LVL_0_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_MAIN_ESM0_ESM_INT_CFG_LVL_0_CODE_OPEN
# pragma clang section text = ".OS_MAIN_ESM0_ESM_INT_CFG_LVL_0_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_MAIN_ESM0_ESM_INT_CFG_LVL_0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_MAIN_ESM0_ESM_INT_CFG_LVL_0_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_MAIN_ESM0_ESM_INT_CFG_LVL_0_CODE_OPEN
#  error Section OS_MAIN_ESM0_ESM_INT_CFG_LVL_0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_MAIN_ESM0_ESM_INT_CFG_LVL_0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_MAIN_ESM0_ESM_INT_CFG_LVL_0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_MAIN_ESM0_ESM_INT_HI_LVL_0_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_MAIN_ESM0_ESM_INT_HI_LVL_0_CODE_OPEN
# pragma clang section text = ".OS_MAIN_ESM0_ESM_INT_HI_LVL_0_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_MAIN_ESM0_ESM_INT_HI_LVL_0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_MAIN_ESM0_ESM_INT_HI_LVL_0_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_MAIN_ESM0_ESM_INT_HI_LVL_0_CODE_OPEN
#  error Section OS_MAIN_ESM0_ESM_INT_HI_LVL_0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_MAIN_ESM0_ESM_INT_HI_LVL_0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_MAIN_ESM0_ESM_INT_HI_LVL_0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_MAIN_ESM0_ESM_INT_LOW_LVL_0_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_MAIN_ESM0_ESM_INT_LOW_LVL_0_CODE_OPEN
# pragma clang section text = ".OS_MAIN_ESM0_ESM_INT_LOW_LVL_0_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_MAIN_ESM0_ESM_INT_LOW_LVL_0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_MAIN_ESM0_ESM_INT_LOW_LVL_0_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_MAIN_ESM0_ESM_INT_LOW_LVL_0_CODE_OPEN
#  error Section OS_MAIN_ESM0_ESM_INT_LOW_LVL_0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_MAIN_ESM0_ESM_INT_LOW_LVL_0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_MAIN_ESM0_ESM_INT_LOW_LVL_0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_MCU_ESM0_ESM_INT_CFG_LVL_0_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_MCU_ESM0_ESM_INT_CFG_LVL_0_CODE_OPEN
# pragma clang section text = ".OS_MCU_ESM0_ESM_INT_CFG_LVL_0_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_MCU_ESM0_ESM_INT_CFG_LVL_0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_MCU_ESM0_ESM_INT_CFG_LVL_0_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_MCU_ESM0_ESM_INT_CFG_LVL_0_CODE_OPEN
#  error Section OS_MCU_ESM0_ESM_INT_CFG_LVL_0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_MCU_ESM0_ESM_INT_CFG_LVL_0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_MCU_ESM0_ESM_INT_CFG_LVL_0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_MCU_ESM0_ESM_INT_HI_LVL_0_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_MCU_ESM0_ESM_INT_HI_LVL_0_CODE_OPEN
# pragma clang section text = ".OS_MCU_ESM0_ESM_INT_HI_LVL_0_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_MCU_ESM0_ESM_INT_HI_LVL_0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_MCU_ESM0_ESM_INT_HI_LVL_0_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_MCU_ESM0_ESM_INT_HI_LVL_0_CODE_OPEN
#  error Section OS_MCU_ESM0_ESM_INT_HI_LVL_0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_MCU_ESM0_ESM_INT_HI_LVL_0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_MCU_ESM0_ESM_INT_HI_LVL_0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_MCU_ESM0_ESM_INT_LOW_LVL_0_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_MCU_ESM0_ESM_INT_LOW_LVL_0_CODE_OPEN
# pragma clang section text = ".OS_MCU_ESM0_ESM_INT_LOW_LVL_0_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_MCU_ESM0_ESM_INT_LOW_LVL_0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_MCU_ESM0_ESM_INT_LOW_LVL_0_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_MCU_ESM0_ESM_INT_LOW_LVL_0_CODE_OPEN
#  error Section OS_MCU_ESM0_ESM_INT_LOW_LVL_0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_MCU_ESM0_ESM_INT_LOW_LVL_0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_MCU_ESM0_ESM_INT_LOW_LVL_0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_CODE_OPEN
# pragma clang section text = ".OS_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_CODE_OPEN
#  error Section OS_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_CODE_OPEN
# pragma clang section text = ".OS_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_CODE_OPEN
#  error Section OS_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_QM_ComTask_10ms_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_QM_ComTask_10ms_CODE_OPEN
# pragma clang section text = ".OS_QM_ComTask_10ms_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_QM_ComTask_10ms_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_QM_ComTask_10ms_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_QM_ComTask_10ms_CODE_OPEN
#  error Section OS_QM_ComTask_10ms_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_QM_ComTask_10ms_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_QM_ComTask_10ms_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_QM_ComTask_5ms_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_QM_ComTask_5ms_CODE_OPEN
# pragma clang section text = ".OS_QM_ComTask_5ms_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_QM_ComTask_5ms_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_QM_ComTask_5ms_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_QM_ComTask_5ms_CODE_OPEN
#  error Section OS_QM_ComTask_5ms_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_QM_ComTask_5ms_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_QM_ComTask_5ms_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_QM_DiagTask_10ms_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_QM_DiagTask_10ms_CODE_OPEN
# pragma clang section text = ".OS_QM_DiagTask_10ms_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_QM_DiagTask_10ms_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_QM_DiagTask_10ms_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_QM_DiagTask_10ms_CODE_OPEN
#  error Section OS_QM_DiagTask_10ms_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_QM_DiagTask_10ms_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_QM_DiagTask_10ms_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_QM_MemTask_10ms_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_QM_MemTask_10ms_CODE_OPEN
# pragma clang section text = ".OS_QM_MemTask_10ms_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_QM_MemTask_10ms_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_QM_MemTask_10ms_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_QM_MemTask_10ms_CODE_OPEN
#  error Section OS_QM_MemTask_10ms_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_QM_MemTask_10ms_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_QM_MemTask_10ms_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_QM_Task_00_10ms_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_QM_Task_00_10ms_CODE_OPEN
# pragma clang section text = ".OS_QM_Task_00_10ms_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_QM_Task_00_10ms_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_QM_Task_00_10ms_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_QM_Task_00_10ms_CODE_OPEN
#  error Section OS_QM_Task_00_10ms_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_QM_Task_00_10ms_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_QM_Task_00_10ms_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_QM_Task_01_10ms_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_QM_Task_01_10ms_CODE_OPEN
# pragma clang section text = ".OS_QM_Task_01_10ms_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_QM_Task_01_10ms_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_QM_Task_01_10ms_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_QM_Task_01_10ms_CODE_OPEN
#  error Section OS_QM_Task_01_10ms_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_QM_Task_01_10ms_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_QM_Task_01_10ms_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_QM_Task_200ms_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_QM_Task_200ms_CODE_OPEN
# pragma clang section text = ".OS_QM_Task_200ms_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_QM_Task_200ms_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_QM_Task_200ms_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_QM_Task_200ms_CODE_OPEN
#  error Section OS_QM_Task_200ms_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_QM_Task_200ms_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_QM_Task_200ms_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_QM_Task_Init_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_QM_Task_Init_CODE_OPEN
# pragma clang section text = ".OS_QM_Task_Init_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_QM_Task_Init_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_QM_Task_Init_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_QM_Task_Init_CODE_OPEN
#  error Section OS_QM_Task_Init_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_QM_Task_Init_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_QM_Task_Init_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317_CODE_OPEN
# pragma clang section text = ".OS_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317_CODE_OPEN
#  error Section OS_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295_CODE_OPEN
# pragma clang section text = ".OS_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295_CODE_OPEN
#  error Section OS_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296_CODE_OPEN
# pragma clang section text = ".OS_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296_CODE_OPEN
#  error Section OS_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291_CODE_OPEN
# pragma clang section text = ".OS_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291_CODE_OPEN
#  error Section OS_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290_CODE_OPEN
# pragma clang section text = ".OS_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290_CODE_OPEN
#  error Section OS_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299_CODE_OPEN
# pragma clang section text = ".OS_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299_CODE_OPEN
#  error Section OS_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297_CODE_OPEN
# pragma clang section text = ".OS_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297_CODE_OPEN
#  error Section OS_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298_CODE_OPEN
# pragma clang section text = ".OS_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298_CODE_OPEN
#  error Section OS_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300_CODE_OPEN
# pragma clang section text = ".OS_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300_CODE_OPEN
#  error Section OS_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47_CODE_OPEN
# pragma clang section text = ".OS_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47_CODE_OPEN
#  error Section OS_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36_CODE_OPEN
# pragma clang section text = ".OS_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36_CODE_OPEN
#  error Section OS_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37_CODE_OPEN
# pragma clang section text = ".OS_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37_CODE_OPEN
#  error Section OS_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312_CODE_OPEN
# pragma clang section text = ".OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312_CODE_OPEN
#  error Section OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310_CODE_OPEN
# pragma clang section text = ".OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310_CODE_OPEN
#  error Section OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314_CODE_OPEN
# pragma clang section text = ".OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314_CODE_OPEN
#  error Section OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313_CODE_OPEN
# pragma clang section text = ".OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313_CODE_OPEN
#  error Section OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309_CODE_OPEN
# pragma clang section text = ".OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309_CODE_OPEN
#  error Section OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307_CODE_OPEN
# pragma clang section text = ".OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307_CODE_OPEN
#  error Section OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308_CODE_OPEN
# pragma clang section text = ".OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308_CODE_OPEN
#  error Section OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306_CODE_OPEN
# pragma clang section text = ".OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306_CODE_OPEN
#  error Section OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304_CODE_OPEN
# pragma clang section text = ".OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304_CODE_OPEN
#  error Section OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305_CODE_OPEN
# pragma clang section text = ".OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305_CODE_OPEN
#  error Section OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_Safety_Task_00_10ms_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Safety_Task_00_10ms_CODE_OPEN
# pragma clang section text = ".OS_Safety_Task_00_10ms_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_Safety_Task_00_10ms_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_Safety_Task_00_10ms_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_Safety_Task_00_10ms_CODE_OPEN
#  error Section OS_Safety_Task_00_10ms_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Safety_Task_00_10ms_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_Safety_Task_00_10ms_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_Safety_Task_01_10ms_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Safety_Task_01_10ms_CODE_OPEN
# pragma clang section text = ".OS_Safety_Task_01_10ms_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_Safety_Task_01_10ms_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_Safety_Task_01_10ms_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_Safety_Task_01_10ms_CODE_OPEN
#  error Section OS_Safety_Task_01_10ms_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Safety_Task_01_10ms_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_Safety_Task_01_10ms_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_Safety_Task_200ms_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Safety_Task_200ms_CODE_OPEN
# pragma clang section text = ".OS_Safety_Task_200ms_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_Safety_Task_200ms_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_Safety_Task_200ms_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_Safety_Task_200ms_CODE_OPEN
#  error Section OS_Safety_Task_200ms_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Safety_Task_200ms_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_Safety_Task_200ms_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_Safety_Task_Init_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Safety_Task_Init_CODE_OPEN
# pragma clang section text = ".OS_Safety_Task_Init_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_Safety_Task_Init_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_Safety_Task_Init_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_Safety_Task_Init_CODE_OPEN
#  error Section OS_Safety_Task_Init_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Safety_Task_Init_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_Safety_Task_Init_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_Safety_WdgTask_10ms_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Safety_WdgTask_10ms_CODE_OPEN
# pragma clang section text = ".OS_Safety_WdgTask_10ms_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_Safety_WdgTask_10ms_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_Safety_WdgTask_10ms_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_Safety_WdgTask_10ms_CODE_OPEN
#  error Section OS_Safety_WdgTask_10ms_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Safety_WdgTask_10ms_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_Safety_WdgTask_10ms_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SciServerHighOsTask_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SciServerHighOsTask_CODE_OPEN
# pragma clang section text = ".OS_SciServerHighOsTask_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SciServerHighOsTask_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SciServerHighOsTask_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SciServerHighOsTask_CODE_OPEN
#  error Section OS_SciServerHighOsTask_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SciServerHighOsTask_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SciServerHighOsTask_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SciServerLowOsTask_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SciServerLowOsTask_CODE_OPEN
# pragma clang section text = ".OS_SciServerLowOsTask_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SciServerLowOsTask_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SciServerLowOsTask_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SciServerLowOsTask_CODE_OPEN
#  error Section OS_SciServerLowOsTask_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SciServerLowOsTask_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SciServerLowOsTask_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SciServer_OsIsr_UserMsgHwiFxn1_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SciServer_OsIsr_UserMsgHwiFxn1_CODE_OPEN
# pragma clang section text = ".OS_SciServer_OsIsr_UserMsgHwiFxn1_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SciServer_OsIsr_UserMsgHwiFxn1_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SciServer_OsIsr_UserMsgHwiFxn1_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SciServer_OsIsr_UserMsgHwiFxn1_CODE_OPEN
#  error Section OS_SciServer_OsIsr_UserMsgHwiFxn1_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SciServer_OsIsr_UserMsgHwiFxn1_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SciServer_OsIsr_UserMsgHwiFxn1_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SciServer_OsIsr_UserMsgHwiFxn2_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SciServer_OsIsr_UserMsgHwiFxn2_CODE_OPEN
# pragma clang section text = ".OS_SciServer_OsIsr_UserMsgHwiFxn2_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SciServer_OsIsr_UserMsgHwiFxn2_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SciServer_OsIsr_UserMsgHwiFxn2_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SciServer_OsIsr_UserMsgHwiFxn2_CODE_OPEN
#  error Section OS_SciServer_OsIsr_UserMsgHwiFxn2_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SciServer_OsIsr_UserMsgHwiFxn2_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SciServer_OsIsr_UserMsgHwiFxn2_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SciServer_OsIsr_UserMsgHwiFxn3_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SciServer_OsIsr_UserMsgHwiFxn3_CODE_OPEN
# pragma clang section text = ".OS_SciServer_OsIsr_UserMsgHwiFxn3_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SciServer_OsIsr_UserMsgHwiFxn3_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SciServer_OsIsr_UserMsgHwiFxn3_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SciServer_OsIsr_UserMsgHwiFxn3_CODE_OPEN
#  error Section OS_SciServer_OsIsr_UserMsgHwiFxn3_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SciServer_OsIsr_UserMsgHwiFxn3_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SciServer_OsIsr_UserMsgHwiFxn3_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SciServer_OsIsr_UserMsgHwiFxn4_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SciServer_OsIsr_UserMsgHwiFxn4_CODE_OPEN
# pragma clang section text = ".OS_SciServer_OsIsr_UserMsgHwiFxn4_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SciServer_OsIsr_UserMsgHwiFxn4_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SciServer_OsIsr_UserMsgHwiFxn4_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SciServer_OsIsr_UserMsgHwiFxn4_CODE_OPEN
#  error Section OS_SciServer_OsIsr_UserMsgHwiFxn4_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SciServer_OsIsr_UserMsgHwiFxn4_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SciServer_OsIsr_UserMsgHwiFxn4_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_ShutdownTask_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_ShutdownTask_CODE_OPEN
# pragma clang section text = ".OS_ShutdownTask_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_ShutdownTask_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_ShutdownTask_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_ShutdownTask_CODE_OPEN
#  error Section OS_ShutdownTask_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_ShutdownTask_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_ShutdownTask_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_StartUpTask_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_StartUpTask_CODE_OPEN
# pragma clang section text = ".OS_StartUpTask_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_StartUpTask_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_StartUpTask_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_StartUpTask_CODE_OPEN
#  error Section OS_StartUpTask_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_StartUpTask_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_StartUpTask_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_WKUP_ESM0_ESM_INT_CFG_LVL_0_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_WKUP_ESM0_ESM_INT_CFG_LVL_0_CODE_OPEN
# pragma clang section text = ".OS_WKUP_ESM0_ESM_INT_CFG_LVL_0_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_WKUP_ESM0_ESM_INT_CFG_LVL_0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_WKUP_ESM0_ESM_INT_CFG_LVL_0_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_WKUP_ESM0_ESM_INT_CFG_LVL_0_CODE_OPEN
#  error Section OS_WKUP_ESM0_ESM_INT_CFG_LVL_0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_WKUP_ESM0_ESM_INT_CFG_LVL_0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_WKUP_ESM0_ESM_INT_CFG_LVL_0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_WKUP_ESM0_ESM_INT_HI_LVL_0_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_WKUP_ESM0_ESM_INT_HI_LVL_0_CODE_OPEN
# pragma clang section text = ".OS_WKUP_ESM0_ESM_INT_HI_LVL_0_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_WKUP_ESM0_ESM_INT_HI_LVL_0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_WKUP_ESM0_ESM_INT_HI_LVL_0_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_WKUP_ESM0_ESM_INT_HI_LVL_0_CODE_OPEN
#  error Section OS_WKUP_ESM0_ESM_INT_HI_LVL_0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_WKUP_ESM0_ESM_INT_HI_LVL_0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_WKUP_ESM0_ESM_INT_HI_LVL_0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_WKUP_ESM0_ESM_INT_LOW_LVL_0_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_WKUP_ESM0_ESM_INT_LOW_LVL_0_CODE_OPEN
# pragma clang section text = ".OS_WKUP_ESM0_ESM_INT_LOW_LVL_0_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_WKUP_ESM0_ESM_INT_LOW_LVL_0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_WKUP_ESM0_ESM_INT_LOW_LVL_0_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_WKUP_ESM0_ESM_INT_LOW_LVL_0_CODE_OPEN
#  error Section OS_WKUP_ESM0_ESM_INT_LOW_LVL_0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_WKUP_ESM0_ESM_INT_LOW_LVL_0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_WKUP_ESM0_ESM_INT_LOW_LVL_0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_vHsmResponseIsr_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_vHsmResponseIsr_CODE_OPEN
# pragma clang section text = ".OS_vHsmResponseIsr_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_vHsmResponseIsr_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_vHsmResponseIsr_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_vHsmResponseIsr_CODE_OPEN
#  error Section OS_vHsmResponseIsr_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_vHsmResponseIsr_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_vHsmResponseIsr_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif


/**********************************************************************************************************************
 *  CONST SECTIONS
 *********************************************************************************************************************/

#ifdef OS_START_SEC_GLOBALSHARED_CONST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_BOOLEAN_OPEN
# pragma clang section rodata = ".OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_8BIT_OPEN
# pragma clang section rodata = ".OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_8BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_16BIT_OPEN
# pragma clang section rodata = ".OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_16BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_32BIT_OPEN
# pragma clang section rodata = ".OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_32BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_UNSPECIFIED_OPEN
# pragma clang section rodata = ".OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_BOOLEAN_OPEN
# pragma clang section rodata = ".OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_8BIT_OPEN
# pragma clang section rodata = ".OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_FAST_8BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_16BIT_OPEN
# pragma clang section rodata = ".OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_FAST_16BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_32BIT_OPEN
# pragma clang section rodata = ".OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_FAST_32BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_UNSPECIFIED_OPEN
# pragma clang section rodata = ".OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_CONST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_CONST_BOOLEAN_OPEN
# pragma clang section rodata = ".OS_OsApplication_QM_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_CONST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_CONST_BOOLEAN_OPEN
#  error Section OS_OsApplication_QM_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_CONST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_CONST_8BIT_OPEN
# pragma clang section rodata = ".OS_OsApplication_QM_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_CONST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_CONST_8BIT_OPEN
#  error Section OS_OsApplication_QM_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_CONST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_CONST_16BIT_OPEN
# pragma clang section rodata = ".OS_OsApplication_QM_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_CONST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_CONST_16BIT_OPEN
#  error Section OS_OsApplication_QM_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_CONST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_CONST_32BIT_OPEN
# pragma clang section rodata = ".OS_OsApplication_QM_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_CONST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_CONST_32BIT_OPEN
#  error Section OS_OsApplication_QM_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_CONST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_CONST_UNSPECIFIED_OPEN
# pragma clang section rodata = ".OS_OsApplication_QM_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_CONST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_CONST_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_QM_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_CONST_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_CONST_FAST_BOOLEAN_OPEN
# pragma clang section rodata = ".OS_OsApplication_QM_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_CONST_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_OsApplication_QM_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_CONST_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_CONST_FAST_8BIT_OPEN
# pragma clang section rodata = ".OS_OsApplication_QM_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_CONST_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_CONST_FAST_8BIT_OPEN
#  error Section OS_OsApplication_QM_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_CONST_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_CONST_FAST_16BIT_OPEN
# pragma clang section rodata = ".OS_OsApplication_QM_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_CONST_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_CONST_FAST_16BIT_OPEN
#  error Section OS_OsApplication_QM_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_CONST_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_CONST_FAST_32BIT_OPEN
# pragma clang section rodata = ".OS_OsApplication_QM_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_CONST_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_CONST_FAST_32BIT_OPEN
#  error Section OS_OsApplication_QM_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_CONST_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_CONST_FAST_UNSPECIFIED_OPEN
# pragma clang section rodata = ".OS_OsApplication_QM_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_CONST_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_QM_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_CONST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_CONST_BOOLEAN_OPEN
# pragma clang section rodata = ".OS_OsApplication_Safety_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_CONST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_CONST_BOOLEAN_OPEN
#  error Section OS_OsApplication_Safety_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_CONST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_CONST_8BIT_OPEN
# pragma clang section rodata = ".OS_OsApplication_Safety_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_CONST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_CONST_8BIT_OPEN
#  error Section OS_OsApplication_Safety_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_CONST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_CONST_16BIT_OPEN
# pragma clang section rodata = ".OS_OsApplication_Safety_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_CONST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_CONST_16BIT_OPEN
#  error Section OS_OsApplication_Safety_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_CONST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_CONST_32BIT_OPEN
# pragma clang section rodata = ".OS_OsApplication_Safety_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_CONST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_CONST_32BIT_OPEN
#  error Section OS_OsApplication_Safety_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_CONST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_CONST_UNSPECIFIED_OPEN
# pragma clang section rodata = ".OS_OsApplication_Safety_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_CONST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_CONST_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_Safety_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_CONST_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_CONST_FAST_BOOLEAN_OPEN
# pragma clang section rodata = ".OS_OsApplication_Safety_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_CONST_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_OsApplication_Safety_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_CONST_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_CONST_FAST_8BIT_OPEN
# pragma clang section rodata = ".OS_OsApplication_Safety_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_CONST_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_CONST_FAST_8BIT_OPEN
#  error Section OS_OsApplication_Safety_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_CONST_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_CONST_FAST_16BIT_OPEN
# pragma clang section rodata = ".OS_OsApplication_Safety_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_CONST_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_CONST_FAST_16BIT_OPEN
#  error Section OS_OsApplication_Safety_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_CONST_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_CONST_FAST_32BIT_OPEN
# pragma clang section rodata = ".OS_OsApplication_Safety_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_CONST_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_CONST_FAST_32BIT_OPEN
#  error Section OS_OsApplication_Safety_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_CONST_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_CONST_FAST_UNSPECIFIED_OPEN
# pragma clang section rodata = ".OS_OsApplication_Safety_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_CONST_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_Safety_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_CONST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_CONST_BOOLEAN_OPEN
# pragma clang section rodata = ".OS_OsApplication_Trusted_Core0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_CONST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_CONST_BOOLEAN_OPEN
#  error Section OS_OsApplication_Trusted_Core0_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_CONST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_CONST_8BIT_OPEN
# pragma clang section rodata = ".OS_OsApplication_Trusted_Core0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_CONST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_CONST_8BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_CONST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_CONST_16BIT_OPEN
# pragma clang section rodata = ".OS_OsApplication_Trusted_Core0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_CONST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_CONST_16BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_CONST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_CONST_32BIT_OPEN
# pragma clang section rodata = ".OS_OsApplication_Trusted_Core0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_CONST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_CONST_32BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_CONST_UNSPECIFIED_OPEN
# pragma clang section rodata = ".OS_OsApplication_Trusted_Core0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_CONST_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_Trusted_Core0_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_CONST_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_CONST_FAST_BOOLEAN_OPEN
# pragma clang section rodata = ".OS_OsApplication_Trusted_Core0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_CONST_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_OsApplication_Trusted_Core0_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_CONST_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_CONST_FAST_8BIT_OPEN
# pragma clang section rodata = ".OS_OsApplication_Trusted_Core0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_CONST_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_CONST_FAST_8BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_CONST_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_CONST_FAST_16BIT_OPEN
# pragma clang section rodata = ".OS_OsApplication_Trusted_Core0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_CONST_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_CONST_FAST_16BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_CONST_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_CONST_FAST_32BIT_OPEN
# pragma clang section rodata = ".OS_OsApplication_Trusted_Core0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_CONST_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_CONST_FAST_32BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_CONST_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_CONST_FAST_UNSPECIFIED_OPEN
# pragma clang section rodata = ".OS_OsApplication_Trusted_Core0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_CONST_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_Trusted_Core0_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_BOOLEAN_OPEN
# pragma clang section rodata = ".OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_8BIT_OPEN
# pragma clang section rodata = ".OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_16BIT_OPEN
# pragma clang section rodata = ".OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_32BIT_OPEN
# pragma clang section rodata = ".OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_UNSPECIFIED_OPEN
# pragma clang section rodata = ".OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_FAST_BOOLEAN_OPEN
# pragma clang section rodata = ".OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_FAST_8BIT_OPEN
# pragma clang section rodata = ".OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_FAST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_FAST_16BIT_OPEN
# pragma clang section rodata = ".OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_FAST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_FAST_32BIT_OPEN
# pragma clang section rodata = ".OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_FAST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_FAST_UNSPECIFIED_OPEN
# pragma clang section rodata = ".OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section rodata = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif


/**********************************************************************************************************************
 *  VAR SECTIONS
 *********************************************************************************************************************/

#ifdef OS_START_SEC_GLOBALSHARED_VAR_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_BOOLEAN_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_8BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_16BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_32BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_8BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_16BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_32BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_8BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_16BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_32BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_BOOLEAN_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_8BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_16BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_32BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_8BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_16BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_32BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_BOOLEAN_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_8BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_16BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_32BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_BOOLEAN_OPEN
#  error Section OS_OsApplication_QM_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_8BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_16BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_32BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_QM_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_NOINIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_OsApplication_QM_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_NOINIT_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_NOINIT_8BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_NOINIT_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_NOINIT_16BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_NOINIT_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_NOINIT_32BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_NOINIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_QM_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_ZERO_INIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_OsApplication_QM_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_ZERO_INIT_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_ZERO_INIT_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_ZERO_INIT_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_QM_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_FAST_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_OsApplication_QM_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_FAST_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_FAST_8BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_FAST_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_FAST_16BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_FAST_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_FAST_32BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_FAST_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_QM_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_FAST_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_FAST_NOINIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_FAST_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_OsApplication_QM_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_FAST_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_FAST_NOINIT_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_FAST_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_FAST_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_FAST_NOINIT_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_FAST_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_FAST_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_FAST_NOINIT_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_FAST_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_FAST_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_FAST_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_QM_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_FAST_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_FAST_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_OsApplication_QM_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_FAST_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_FAST_ZERO_INIT_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_FAST_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_FAST_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_FAST_ZERO_INIT_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_FAST_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_FAST_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_FAST_ZERO_INIT_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_FAST_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_QM_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_NOCACHE_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_OsApplication_QM_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_NOCACHE_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_NOCACHE_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_NOCACHE_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_NOCACHE_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_QM_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_OsApplication_QM_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_NOCACHE_NOINIT_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_NOCACHE_NOINIT_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_NOCACHE_NOINIT_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_QM_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_QM_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_BOOLEAN_OPEN
#  error Section OS_OsApplication_Safety_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_8BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_16BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_32BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_Safety_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_NOINIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_OsApplication_Safety_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_NOINIT_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_NOINIT_8BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_NOINIT_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_NOINIT_16BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_NOINIT_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_NOINIT_32BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_NOINIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_Safety_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_ZERO_INIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_OsApplication_Safety_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_ZERO_INIT_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_ZERO_INIT_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_ZERO_INIT_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_Safety_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_FAST_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_OsApplication_Safety_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_FAST_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_FAST_8BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_FAST_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_FAST_16BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_FAST_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_FAST_32BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_FAST_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_Safety_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_FAST_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_FAST_NOINIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_OsApplication_Safety_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_FAST_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_FAST_NOINIT_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_FAST_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_FAST_NOINIT_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_FAST_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_FAST_NOINIT_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_FAST_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_Safety_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_FAST_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_OsApplication_Safety_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_FAST_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_FAST_ZERO_INIT_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_FAST_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_FAST_ZERO_INIT_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_FAST_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_FAST_ZERO_INIT_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_Safety_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_NOCACHE_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_OsApplication_Safety_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_NOCACHE_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_NOCACHE_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_NOCACHE_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_NOCACHE_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_Safety_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_OsApplication_Safety_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_NOCACHE_NOINIT_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_NOCACHE_NOINIT_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_NOCACHE_NOINIT_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_Safety_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Safety_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_BOOLEAN_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_8BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_16BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_32BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_NOINIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_NOINIT_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_NOINIT_8BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_NOINIT_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_NOINIT_16BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_NOINIT_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_NOINIT_32BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_NOINIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_FAST_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_FAST_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_FAST_8BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_FAST_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_FAST_16BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_FAST_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_FAST_32BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_FAST_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_NOCACHE_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_NOCACHE_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_NOCACHE_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_NOCACHE_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_NOCACHE_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_BOOLEAN_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_8BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_16BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_32BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOINIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOINIT_8BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOINIT_16BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOINIT_32BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_ZERO_INIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_ZERO_INIT_8BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_ZERO_INIT_16BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_ZERO_INIT_32BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_BOOLEAN_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_8BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_16BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_32BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_8BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_16BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_32BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_8BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_16BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_32BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_BOOLEAN_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_8BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_16BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_32BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_8BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_16BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_32BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# pragma clang section bss = ".OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_bss" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif


/* PRQA S 0883 */ /* MD_Os_Dir4.10_0883_MemMap */
