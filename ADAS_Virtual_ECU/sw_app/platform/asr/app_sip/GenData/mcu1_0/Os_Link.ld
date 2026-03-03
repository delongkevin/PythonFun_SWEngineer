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
 *              File: Os_Link.ld
 *   Generation Time: 2024-02-13 13:07:50
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CODE SECTIONS  (Llvm_TexasInstruments)
 *********************************************************************************************************************/

#if defined ( OS_LINK_CODE )
  _OS_CODE_START = .;
  *(.OS_CODE)
  _OS_CODE_END = .-1;
  _OS_CODE_LIMIT = .;
#endif

#if defined ( OS_LINK_INTVEC_CODE )
  _OS_INTVEC_CODE_START = .;
  *(.OS_INTVEC_CODE)
  _OS_INTVEC_CODE_END = .-1;
  _OS_INTVEC_CODE_LIMIT = .;
#endif

#if defined ( OS_LINK_CALLOUT_CODE )
  _OS_ERRORHOOK_CODE_START = .;
  *(.OS_ERRORHOOK_CODE)
  _OS_ERRORHOOK_CODE_END = .-1;
  _OS_ERRORHOOK_CODE_LIMIT = .;
  _OS_OS_COREINITHOOK_CODE_START = .;
  *(.OS_OS_COREINITHOOK_CODE)
  _OS_OS_COREINITHOOK_CODE_END = .-1;
  _OS_OS_COREINITHOOK_CODE_LIMIT = .;
  _OS_PANICHOOK_CODE_START = .;
  *(.OS_PANICHOOK_CODE)
  _OS_PANICHOOK_CODE_END = .-1;
  _OS_PANICHOOK_CODE_LIMIT = .;
  _OS_PROTECTIONHOOK_CODE_START = .;
  *(.OS_PROTECTIONHOOK_CODE)
  _OS_PROTECTIONHOOK_CODE_END = .-1;
  _OS_PROTECTIONHOOK_CODE_LIMIT = .;
  _OS_SHUTDOWNHOOK_CODE_START = .;
  *(.OS_SHUTDOWNHOOK_CODE)
  _OS_SHUTDOWNHOOK_CODE_END = .-1;
  _OS_SHUTDOWNHOOK_CODE_LIMIT = .;
#endif

#ifdef OS_LINK_CODE
# undef OS_LINK_CODE
#endif

#ifdef OS_LINK_INTVEC_CODE
# undef OS_LINK_INTVEC_CODE
#endif

#ifdef OS_LINK_CALLOUT_CODE
# undef OS_LINK_CALLOUT_CODE
#endif


/**********************************************************************************************************************
 *  CONST SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_GLOBALSHARED ) || defined ( OS_LINK_CONST_GLOBALSHARED_FAR )
  _OS_CONST_START = .;
  *(.OS_CONST)
  _OS_CONST_END = .-1;
  _OS_CONST_LIMIT = .;
  _OS_GLOBALSHARED_CONST_START = .;
  *(.OS_GLOBALSHARED_CONST)
  _OS_GLOBALSHARED_CONST_END = .-1;
  _OS_GLOBALSHARED_CONST_LIMIT = .;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_GLOBALSHARED ) || defined ( OS_LINK_CONST_GLOBALSHARED_NEAR )
  _OS_CONST_FAST_START = .;
  *(.OS_CONST_FAST)
  _OS_CONST_FAST_END = .-1;
  _OS_CONST_FAST_LIMIT = .;
  _OS_GLOBALSHARED_CONST_FAST_START = .;
  *(.OS_GLOBALSHARED_CONST_FAST)
  _OS_GLOBALSHARED_CONST_FAST_END = .-1;
  _OS_GLOBALSHARED_CONST_FAST_LIMIT = .;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_GLOBALSHARED ) || defined ( OS_LINK_CONST_GLOBALSHARED_NEAR ) || defined ( OS_LINK_CONST_GLOBALSHARED_NEAR_INIT )


#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_GLOBALSHARED ) || defined ( OS_LINK_CONST_GLOBALSHARED_NEAR ) || defined ( OS_LINK_CONST_GLOBALSHARED_NEAR_ZERO_INIT )


#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_GLOBALSHARED ) || defined ( OS_LINK_CONST_GLOBALSHARED_FAR ) || defined ( OS_LINK_CONST_GLOBALSHARED_FAR_INIT )


#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_GLOBALSHARED ) || defined ( OS_LINK_CONST_GLOBALSHARED_FAR ) || defined ( OS_LINK_CONST_GLOBALSHARED_FAR_ZERO_INIT )


#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_NEAR ) || defined ( OS_LINK_CONST_NEAR_INIT )

#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_FAR ) || defined ( OS_LINK_CONST_FAR_INIT )

#endif

#if defined ( OS_LINK_INTVEC_CONST )
  _OS_INTVEC_CONST_START = .;
  *(.OS_INTVEC_CONST)
  _OS_INTVEC_CONST_END = .-1;
  _OS_INTVEC_CONST_LIMIT = .;
#endif

#ifdef OS_LINK_CONST
# undef OS_LINK_CONST
#endif

#ifdef OS_LINK_CONST_GLOBALSHARED
# undef OS_LINK_CONST_GLOBALSHARED
#endif

#ifdef OS_LINK_CONST_GLOBALSHARED_NEAR
# undef OS_LINK_CONST_GLOBALSHARED_NEAR
#endif

#ifdef OS_LINK_CONST_GLOBALSHARED_FAR
# undef OS_LINK_CONST_GLOBALSHARED_FAR
#endif

#ifdef OS_LINK_CONST_GLOBALSHARED_NEAR_INIT
# undef OS_LINK_CONST_GLOBALSHARED_NEAR_INIT
#endif

#ifdef OS_LINK_CONST_GLOBALSHARED_FAR_INIT
# undef OS_LINK_CONST_GLOBALSHARED_FAR_INIT
#endif

#ifdef OS_LINK_CONST_GLOBALSHARED_NEAR_ZERO_INIT
# undef OS_LINK_CONST_GLOBALSHARED_NEAR_ZERO_INIT
#endif

#ifdef OS_LINK_CONST_GLOBALSHARED_FAR_ZERO_INIT
# undef OS_LINK_CONST_GLOBALSHARED_FAR_ZERO_INIT
#endif

#ifdef OS_LINK_CONST_NEAR_INIT
# undef OS_LINK_CONST_NEAR_INIT
#endif

#ifdef OS_LINK_CONST_FAR_INIT
# undef OS_LINK_CONST_FAR_INIT
#endif

#ifdef OS_LINK_INTVEC_CONST
# undef OS_LINK_INTVEC_CONST
#endif


/**********************************************************************************************************************
 *  KERNEL VAR SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_INIT )
  _OS_VAR_NOCACHE_START = .;
  *(.OS_VAR_NOCACHE)
  _OS_VAR_NOCACHE_END = .-1;
  _OS_VAR_NOCACHE_LIMIT = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOINIT )
  _OS_VAR_NOCACHE_NOINIT_START = .;
  *(.OS_VAR_NOCACHE_NOINIT)
  _OS_VAR_NOCACHE_NOINIT_END = .-1;
  _OS_VAR_NOCACHE_NOINIT_LIMIT = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_INIT )
  _OS_VAR_FAST_NOCACHE_START = .;
  *(.OS_VAR_FAST_NOCACHE)
  _OS_VAR_FAST_NOCACHE_END = .-1;
  _OS_VAR_FAST_NOCACHE_LIMIT = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOINIT )
  _OS_VAR_FAST_NOCACHE_NOINIT_START = .;
  *(.OS_VAR_FAST_NOCACHE_NOINIT)
  _OS_VAR_FAST_NOCACHE_NOINIT_END = .-1;
  _OS_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
#endif

#ifdef OS_LINK_VAR_KERNEL
# undef OS_LINK_VAR_KERNEL
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR
# undef OS_LINK_VAR_KERNEL_FAR
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_INIT
# undef OS_LINK_VAR_KERNEL_FAR_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOINIT
# undef OS_LINK_VAR_KERNEL_FAR_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR
# undef OS_LINK_VAR_KERNEL_NEAR
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOINIT
# undef OS_LINK_VAR_KERNEL_NEAR_NOINIT
#endif


/**********************************************************************************************************************
 *  GLOBALSHARED VAR SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_CACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_INIT )
  _OS_GLOBALSHARED_VAR_START = .;
  *(.OS_GLOBALSHARED_VAR)
  _OS_GLOBALSHARED_VAR_END = .-1;
  _OS_GLOBALSHARED_VAR_LIMIT = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_INIT )
  _OS_GLOBALSHARED_VAR_NOCACHE_START = .;
  *(.OS_GLOBALSHARED_VAR_NOCACHE)
  _OS_GLOBALSHARED_VAR_NOCACHE_END = .-1;
  _OS_GLOBALSHARED_VAR_NOCACHE_LIMIT = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_CACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_NOINIT )
  _OS_GLOBALSHARED_VAR_NOINIT_START = .;
  *(.OS_GLOBALSHARED_VAR_NOINIT)
  _OS_GLOBALSHARED_VAR_NOINIT_END = .-1;
  _OS_GLOBALSHARED_VAR_NOINIT_LIMIT = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_NOINIT )
  _OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_START = .;
  *(.OS_GLOBALSHARED_VAR_NOCACHE_NOINIT)
  _OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_END = .-1;
  _OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_LIMIT = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_CACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_ZERO_INIT )
  _OS_GLOBALSHARED_VAR_ZERO_INIT_START = .;
  *(.OS_GLOBALSHARED_VAR_ZERO_INIT)
  *(.OS_GLOBALSHARED_VAR_ZERO_INIT_bss)
  _OS_GLOBALSHARED_VAR_ZERO_INIT_END = .-1;
  _OS_GLOBALSHARED_VAR_ZERO_INIT_LIMIT = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_ZERO_INIT )
  _OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_START = .;
  *(.OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT)
  *(.OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_bss)
  _OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_END = .-1;
  _OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_INIT )
  _OS_GLOBALSHARED_VAR_FAST_START = .;
  *(.OS_GLOBALSHARED_VAR_FAST)
  _OS_GLOBALSHARED_VAR_FAST_END = .-1;
  _OS_GLOBALSHARED_VAR_FAST_LIMIT = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_INIT )
  _OS_GLOBALSHARED_VAR_FAST_NOCACHE_START = .;
  *(.OS_GLOBALSHARED_VAR_FAST_NOCACHE)
  _OS_GLOBALSHARED_VAR_FAST_NOCACHE_END = .-1;
  _OS_GLOBALSHARED_VAR_FAST_NOCACHE_LIMIT = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_NOINIT )
  _OS_GLOBALSHARED_VAR_FAST_NOINIT_START = .;
  *(.OS_GLOBALSHARED_VAR_FAST_NOINIT)
  _OS_GLOBALSHARED_VAR_FAST_NOINIT_END = .-1;
  _OS_GLOBALSHARED_VAR_FAST_NOINIT_LIMIT = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_NOINIT )
  _OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT_START = .;
  *(.OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT)
  _OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT_END = .-1;
  _OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_ZERO_INIT )
  _OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_START = .;
  *(.OS_GLOBALSHARED_VAR_FAST_ZERO_INIT)
  *(.OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss)
  _OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_END = .-1;
  _OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_LIMIT = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_ZERO_INIT )
  _OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_START = .;
  *(.OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT)
  *(.OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_bss)
  _OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_END = .-1;
  _OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED
# undef OS_LINK_VAR_GLOBALSHARED
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR
# undef OS_LINK_VAR_GLOBALSHARED_NEAR
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_INIT
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR
# undef OS_LINK_VAR_GLOBALSHARED_FAR
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_CACHE
# undef OS_LINK_VAR_GLOBALSHARED_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_INIT
# undef OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE
# undef OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_ZERO_INIT
#endif


/**********************************************************************************************************************
 *  CORESHARED VAR SECTIONS
 *********************************************************************************************************************/

#ifdef OS_LINK_VAR_CORESHARED
# undef OS_LINK_VAR_CORESHARED
#endif


/**********************************************************************************************************************
 *  APPSHARED VAR SECTIONS
 *********************************************************************************************************************/

#ifdef OS_LINK_VAR_APPSHARED
# undef OS_LINK_VAR_APPSHARED
#endif

#ifdef OS_LINK_VAR
# undef OS_LINK_VAR
#endif


