/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 *  \addtogroup Os_Hal_Os
 *  \{
 *
 *  \file
 *  \brief      HAL interfaces which are visible to the user.
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2016-01-05  virbiv  -             Initial version
 *  01.00.01  2016-05-14  virbiv  -             Developer version
 *  01.00.02  2016-06-10  virbiv  -             Update according to last core interface changes
 *  01.00.03  2016-08-08  virbiv  -             Added support for Zynq UltraScale+ derivatives
 *  01.00.04  2016-09-08  visdhe  FEAT-1931     Provide access to interrupt control register (Step2)
 *                        visasl  WORKITEM6031  #HAL:CortexR: As a customer I want the MICROSAR OS to support the
 *                                              CortexR devices as QM quality (Single Core, Traveo).
 *  01.01.00  2016-10-04  virbiv  -             Generator update
 *  01.02.00  2016-10-18  virbiv  -             Partially support for Cortex-M devices.
 *  01.03.00  2016-10-26  virbiv  -             Cortex-M support.
 *  01.04.00  2016-11-14  virbse  -             Updated Generator to latest BSWMD version
 *                        virbiv  -             S6J311x, S6J312x, S6J33xx derivative groups added
 *  01.05.00  2016-11-17  virsso  WORKITEM9700  CortexR Hardware Software Interface
 *  01.06.00  2016-12-06  virsso  WORKITEM9692  Refactoring of documentation
 *                        virsso  WORKITEM11476 Added ReviewHelper Justifications and Countermeasures
 *  01.07.00  2016-12-15  virjas  -             Internal improvements
 *  01.08.00  2017-01-12  -       -             Internal improvements
 *  02.00.00  2017-02-01  -       -             Internal improvements
 *  02.01.00  2017-02-17  virbiv  ESCAN00093961 Nested interrupt may cause an exception loop
 *                        virbiv  ESCAN00093930 Possible MemoryProtection violation
 *  02.02.00  2017-02-23  virsso  WORKITEM15109 Added support for RCAR_H3 derivative
 *            2017-03-02  virbiv  ESCAN00094082 UsageFault exception during startup
 *            2017-03-13  visces  ESCAN00093389 Writing IRQPLM causes an exception after an nondeterministic time
 *            2017-03-14  virbse  ESCAN00093962 The OS does not correctly handle the unhandled exceptions
 *                        virbiv  ESCAN00094579 A reset will lead to an unhandled Exception
 *  02.03.00  2017-03-28  visto   WORKITEM14883 Support for CortexR UltraScale
 *                                ESCAN00094582 Linker Error because of missing Symbol
 *                                              OsCfg_Hal_Core_OsCore0_InterruptVectorTable
 *                        virbiv  ESCAN00094641 Incorrect context switch restoration on Cortex-R core.
 *  02.04.00  2017-04-06  virbse  WORKITEM15149 Split Cortex-M into separate platform
 *                        virbiv  ESCAN00094022 Compiler error: Function definition not found
 *                        visdfe  ESCAN00093400 Compiler error: A Wrong pre-config leads to compile error in VTT dual
 *                                              target
 *                        visdfe  WORKITEM15150 Split Cortex-A Context from Cortex-R
 *                        vismkk  ESCAN00092881 Prescaler initialization for RTT (Real-Time Timer) module does not
 *                                              match the requirement in the hardware manual if HRT is configured.
 *                        visdhe  WORKITEM14013 Support for AR16xx derivatives
 *                        virbiv  WORKITEM14014 Support for compiler Texas Instruments
 *  02.05.00  2017-05-04  virbse  WORKITEM6746  The core generator shall provide a common core entry symbol for each
 *                                              core.
 *            2017-05-09  visces  WORKITEM15708 RCar-H3: Support Cortex-A cluster in 32Bit mode (not selectable by
 *                                              customer)
 *                                ESCAN00094886 R-Car H3: Interrupts are not working properly
 *                                ESCAN00094890 R-Car H3: MPU initialization leads to exception
 *            2017-05-10  visces  WORKITEM15653 RCar-H3 Support of Interrupt controller
 *                                ESCAN00094607 TMU PIT does not function properly on Rcar-H3
 *            2017-05-11  virsmn  ESCAN00095116 Core local interrupts are not correctly initialized.
 *  2.06.00   2017-06-01  visdfe  ESCAN00094046 Wrong validation of the maximum available MPU regions
 *                        visces  STORYC-1084   Internal improvements
 *  2.07.00   2017-06-23  visshk  ESCAN00095624 ProtectionHook is called unexpectedly during a context switch
 *                        visces  STORY-1038    Added interrupts of CATEGORY_0
 *                        visces  ESCAN00095103 Endless loop during Category 1 ISR processing
 *  2.08.00   2017-07-06  virjas  WORKITEM15088 Internal improvements
 *  2.09.00   2017-08-15  virsmn  ESCAN00094867 Compiler warning: warning #1514-D: incorrect GHS #pragma: small data
 *                                              area is not supported in this configuration
 *                        virbiv  ESCAN00095532 Compiler Warning  #32-D: expression must have arithmetic type in
 *                                              Os_Hal_Context_Lcfg.c
 *  02.10.00  2017-09-11  virsso  STORYC-1840   Internal improvements
 *  02.11.00  2017-10-10  visces  ESCAN00095552 Free Running Timers configured as non High Resolution Counters do not
 *                                              work properly.
 *  02.12.00  2017-10-18  virbse  FEAT-2816     Support shared stack for non-preemptive Basic tasks
 *                                FEAT-2815     Support shared stack for tasks with same internal resource
 *                        virsso  ESCAN00095337 The pre-config of MPU region for non-trusted application contains the
 *                                              wrong accessing rights
 *  02.13.00  2017-11-02  virsmn  ESCAN00096854 Usage of High Resolution Timer and Master Protection Mechanism of INTC
 *                                              could lead to protection violation.
 *                        visdhe  STORYC-2762   Support OS SC1/SC2 with GCC Compiler Production QM
 *  02.14.00  2017-11-22  visshk  STORYC-1751   Performance improvements on some platforms
 *                        visbpz  STORY-2769    OS Interrupt API optimization by replacement of a call sequence for
 *                                              modification of the global interrupt flag.
 *                        virsso  ESCAN00097603 ProtectionHook wrongly called on spourious interrupt
 *                        virsso  ESCAN00097486 Interruption possible in OS code which should not be interrupted
 *                        visces  ESCAN00097317 Compiler error: identifier "OS_HAL_MP_ACCESS_TYPE_NON_CACHEABLE"
 *                                              is undefined
 *  02.15.00  2017-01-10  virsso  STORYC-3218   Support for user configurable FPU cotext saving
 *                        virsso  ESCAN00098050 Undefined behavior of OS after context switchUndefined behavior of
 *                                              OS after context switch
 *  02.16.00  2017-01-25  virsso  ESCAN00098044 Category 1 interrupts may not be correctly disabled.
 *                                ESCAN00097444 Big endian support missing.
 *                                STORYC-3959   Support for TMS570LS21x_31x derivatives.
 *                                ESCAN00098298 Compiler error: bad parameter vstm and vldm {d0-d31}
 *                        virsmn  STORYC-3600   Update according to CDK coding guidelines.
 *                                STORYC-3282   Support for user Msr settings.
 *  02.17.00  2018-02-22  virsso  STORYC-4341   Support for Linaro GCC 6.2.1.
 *                        virsmn  STORYC-3042   Support for OS internal exception detection.
 *  02.18.00  2018-03-23  visbpz  STORYC-4068   Performance improvment by avoiding traps
 *                        visces  STORYC-4469   Support for ARM compiler version >= 6.6.1
 *  02.19.00  2018-04-19  virsso  STORYC-3965   Support for TMS570 (Production)
 *            2018-05-03  virsmn  STORYC-3965   Added support for derivatives without interrupt level support.
 *  02.20.00  2018-05-14  virsmn  STORYC-3320   Added support for interrupt mapping feature.
 *                        virsso  ESCAN00099429 Linker error L6238E: Assembler files contain invalid call from
 *                                              '~PRES8' to 'REQ8'
 *            2018-05-28  virsso  STORYC-5502   Added support for S6J34xx derivatives.
 *            2018-05-29  virsso  ESCAN00094105 The BSW module is in BETA state (R-CAR H3 derivative support)
 *  02.21.00  2018-06-12  visbpz  STORY-5018    Only map memory protection related exceptions to OS so that
 *                                              all other not configured exceptions can be treated as unhandled
 *            2018-06-29  virsmn  STORYC-5594   Added support fo aggregated stack configuration view.
 *  02.22.00  2018-07-19  visbpz  ESCAN00099856 Not all Cortex-R MPU access rights can be configured.
 *  02.23.00  2018-08-06  virsmn  STORYC-4094   Achieve 100 percent variant coverage.
 *                        virsso            -   Internal Improvements.
 *  02.24.00  2018-09-05  visbpz  ESCAN00099597 Interrupt nesting feature not working properly on RCARx3 (CortexR).
 *                        virsso  ESCAN00099846 Inconsistent MPU Stack region and Stack pointer at context switch
 *                                              if functions inlining is deactivated
 *  02.25.00  2018-10-08  visror  STORYC-4537   MISRA-C 2012 Compliance
 *                        virsso  STORYC-6617   Added support for TMPV770x
 *  02.26.00  2018-11-06  virsmn  STORYC-4796   Interrupt API optimization.
 *  02.27.00  2018-11-29  visbpz  STORYC-7180   Support ARMv5 Compiler for RCARx3 derivatives
 *            2018-12-05  virsso  PSC-1305      Adapt SafeBSW counter measures for hardware access
 *            2018-12-05  virsso  STORYC-7283   Reduce Traveo runtime of Os_Hal_IntSetLevel
 *  02.28.00  2019-02-08  visaev  STORYC-7166   Added support for initial enabling of interrupt sources.
 *  02.29.00  2019-02-15  visbpz  STORYC-7293   Added support for TMPV770x (Production QM).
 *            2019-02-27  virsso  STORYC-7498   Added support for Xavier.
 *            2019-02-28  visaev  STORYC-7720   Internal improvement on compiler warning justification
 *  02.30.00  2019-03-13  virsmn  ESCAN00102127 Compiler Error: Unresolved Symbols.
 *            2019-03-15  visrk   STORYC-2545   Configuration of FRT timer size.
 *            2019-03-15  virsso  ESCAN00102311 Configuring an FIQ with source 0 causes an exception.
 *            2019-04-03  virsso  ESCAN00102640 Os_IsrRun returns to address 0 because of stack corruption on TMPV770x
 *  02.30.01  2019-03-13  virsso  ESCAN00102430 The BSW module has a feature with QM state TMPV770x derivative support
 *                                              with GHS compiler
 *  02.31.00  2019-05-09  virsmn  STORYC-7025   Update for hierarchical interrupt controller support.
 *  02.32.00  2019-06-18  visdqk  FIX-6174      Update for generic stack gaps
 *            2019-05-28  visbpz  STORYC-7292   Adding support for Exynos Auto 9.
 *  02.33.00  2019-07-23  virsso  ESCAN00100195 The BSW module is in BETA state (TMS570 derivative support)
 *            2019-07-24  virsso  ESCAN00103650 ErrorHook with status OS_STATUS_DISABLED_INT is wrongly thrown
 *  02.34.00  2019-08-12  virsso  PSC-3163      Internal Improvements
 *            2019-08-21  virsso  ESCAN00104081 Possible infinite loop occurs during Os initialization
 *  02.35.00  2019-09-17  virsmn  OSC-3472      Derivative specific FRT configuration.
 *            2019-09-18  visbpz  ESCAN00104206 Periodic tasks are not scheduled.
 *            2019-09-19  visbpz  ESCAN00104344 Multiple memory region flags cannot be configured.
 *  02.36.00  2019-10-10  visbpz  ESCAN00104422 Memory fault exception during untrusted code execution.
 *  02.37.00  2019-11-12  visbpz  HALBE-308     Fix Strex/ldex function in Compiler Abstraction.
 *            2019-11-11  visbpz  HALBE-303     Added support for S6J336x derivatives.
 *            2019-11-04  virrlu  HALBE-252     Add support for Jacinto7 free running timer.
 *            2019-11-13  visdri  HALBE-182     Add support for Jacinto7 VIM Interrupt Controller.
 *  02.38.00  2019-12-09  vismun  HALBE-296     Added support for ExynosAuto9 SC4.
 *  02.39.00  2019-12-20  visdqk  OSC-5248      Updated version number due to generator changes.
 *  02.40.00  2020-01-22  visdqk  -             Updated version number due to generator changes.
 *            2020-02-03  visdri  HALBE-730     Added support for Jacinto7 SC3 Multicore.
 *  02.41.00  2020-03-05  visbpz  HALBE-1201    Internal improvements.
 *  02.42.00  2020-03-16  virsmn  OSC-5361      Increase number of configurable OS Applications.
 *            2020-04-03  visdri  HALBE-1066    Added support for TCC8030.
 *            2020-04-03  visbpz  HALBE-1015    Internal fixes for Jacinto7.
 *  02.43.00  2020-04-14  visror  -             Update due to BSWMD update.
 *            2020-04-24  vismun  HALBE-831     Added support for ExynosAuto9_EVT1.
 *  02.44.00  2020-05-12  visror  OSC-6103      Internal improvements.
 *            2020-05-19  visdri  HALBE-1794    Provide new exception context APIs.
 *            2020-05-28  visbpz  -             Internal improvements.
 *            2020-05-28  vismun  HALBE-1699    Added support for Jacinto SC4.
 *  02.45.00  2020-06-16  visbpz  HALBE-715     ASIL release Toshiba TMPV770x.
 *            2020-06-24  vismun  HALBE-2124    Internal improvements.
 *  02.46.00  2020-06-16  visbpz  -             Updated version number due to generator changes.
 *            2020-07-18  visdri  HALBE-1638    Added support for Stellar SR6.
 *            2020-07-24  visbpz  ESCAN00106744 Incorrect handling of PSR registers leads to undefined behavior.
 *  02.47.00  2020-08-07  visbpz  -             Updated version number due to generator changes.
 *            2020-08-05  vismun  HALBE-2338    Generic implementation for Cortex R52.
 *            2020-08-19  visbpz  HALBE-1875    Internal fixes for Jacinto7.
 *            2020-08-19  visdri  HALBE-2359    Release Impediments v2.50.00.
 *  02.48.00  2020-09-03  virsmn  -             Updated SW version.
 *            2020-09-09  visbpz  HALBE-2754    Internal improvements.
 *            2020-09-16  visbpz  HALBE-1875    Fixes for Jacinto7.
 *  02.49.00  2020-10-06  virleh  OSC-6102      Justify all MISRA deviations after update to new QAC version.
 *            2020-10-14  virsmn  OSC-6462      Added Interrupt Post Action support.
 *            2020-10-14  visbpz  HALBE-2500    QM release Jacinto7.
 *            2020-10-14  visdqk  OSC-6655      Internal improvement.
 *            2020-10-16  visbpz  HALBE-2808    Multicore Generic implementation for Cortex R52.
 *  02.50.00  2020-10-28  virleh  OSC-6639      Internal improvement.
 *  02.51.00  2020-11-20  vismun  HALBE-3256    Added support for TPRxx.
 *  02.52.00  2020-12-23  virsmn  OSC-5882      ESCAN00088830, ESCAN00104942, ESCAN00089701
 *            2020-12-23  vismun  HALBE-2234    QM release for ARM-Cortex-R52.
 *            2020-12-31  vismaa  HALBE-2850    Added support for AWR16xx, fix for AR16xx/AWR16xx.
 *            2020-12-24  visbpz  HALBE-3473    Reworking support for TPRxx.
 *  02.53.00  2021-01-26  visbpz  HALBE-3662    Reworking support for TPRxx.
 *  02.54.00  2021-02-12  visbpz  HALBE-3650    SC1 QM release for AWR16x.
 *            2021-02-19  visdri  HALBE-3642    SC4 QM Release for Zuxxx.
 *            2021-02-23  visdqk  -             Internal improvement for MISRA.
 *            2021-02-23  vismun  HALBE-3156    ASIL release for ARM-Cortex-R52 (single core).
 *  02.55.00  2021-03-18  visdqk  ESCAN00108354 Removed obsolete HAL API.
 *            2021-03-16  visbpz  HALBE-3966    Add Missing Pulse/Level Interrupt handling.
 *            2021-03-25  vismaa  HALBE-3107    Added OS_HAL_ASM_NOP for preventing emtpy object files(TI).
 *  02.56.00  2021-04-20  visdri  HALBE-2705    Remove the macro OS_HAL_INTC_TWOLEVEL_SUPPORTED.
 *            2021-04-26  visbpz  HALBE-4339    Added the VIM nesting workaround for TPRxx.
 *            2021-04-30  visbpz  HALBE-4104    Added WindRiver Diab LLVM compiler support.
 *  02.57.00  2021-05-06  virrlu  HALBE-4237    Interrupt source not initialized for ReloadTimer.
 *            2021-05-21  visbpz  HALBE-4423    Reworked WindRiver Diab LLVM compiler support.
 *  02.58.00  2021-06-22  visdri  HALBE-3390    SC4 QM Release Jacinto7.
 *  02.59.00  2021-07-08  virrlu  HALBE-3408    Adaptions for CortexR52 multicore support.
 *            2021-07-19  visdri  HALBE-4604    SC4 ASIL Release Jacinto7.
 *            2021-07-21  vismun  HALBE-4644    Support for TCC70xx.
 *  02.60.00  2021-08-10  visbpz  HALBE-4642    ZynqUltraScale single core ASIL Release.
 *  02.61.00  2021-09-01  visbpz  HALBE-5136    SC4 development release Semidrive G9.
 *            2021-09-16  virrlu  HALBE-5828    SC3 ASIL release for TPRxx.
 *  02.62.00  2021-09-23  visdqk  OSC-7919      MISRA migration to new QAC version.
 *  02.63.00  2021-10-21  visdri  HALBE-4909    Support MPU subregions for Cortex-R (v7r).
 *                        virrlu  HALBE-149     Internal improvements.
 *            2021-11-10  virrlu  ESCAN00110664 Context corrupted when FIQ interrupts SVC exception.
 *  02.64.00  2021-11-24  visrk   OSC-8178      Internal improvement.
 *            2021-12-06  visrk   OSC-6113      64 bit support for VttOs.
 *            2021-12-09  virrlu  HALBE-5143    SC4 QM release for Semidrive G9.
 *            2021-12-10  visto   HALBE-5624NEW Jacinto7 -Support new Compiler LlvmTexasIstruments (Development)
 *  02.65.00  2021-12-16  virsmn  OSC-8186      Updates for new QAC version (MISRA).
 *            2021-12-21  visdqk  OSC-8301      Updates for QAC.
 *            2021-12-22  virrlu  HALBE-5834    Internal improvement.
 *            2021-12-30  visdri  HALBE-1360    Support GetExceptionContext API Cortex v7r.
 *  02.66.00  2022-01-13  virrlu  HALBE-5973    Rename macros used in TPRx VIM implementation.
 *            2022-01-21  virrlu  HALBE-6001    Added derivative support for AM62xx.
 *            2022-02-02  virrlu  HALBE-4756    SC3 QM release for TCC70xx.
 *            2022-02-07  visdri  HALBE-5318    Support SetExceptionContext API for Cortex-v7r.
 *  02.67.00  2022-02-24  visdri  HALBE-5980    Cortex v7r: Exception Context Reading and Manipulation improvements.
 *            2022-03-02  virrlu  HALBE-6262    Support GCC Gnu compiler for Cortex-R (v8r).
 *  02.68.00  2022-03-11  virrlu  HALBE-6398    Cortex v7r: Further exception context reading and manipulation improvements.
 *            2022-03-31  virrlu  HALBE-4893    Adaptions for CortexR52 multicore support. 
 *  02.69.00  2022-04-11  virrlu  -             Updated SW version.
 *            2022-04-12  virrlu  HALBE-5245    Split Stellar SR6 from GenericR52 implementation.
 *            2022-04-22  visto   HALBE-6681    Change RTI timer implementation to no longer OR the value of UpCounterCompare register.
 *            2022-04-27  virrlu  HALBE-2265    Added LLVM HighTec support.
 *            2022-04-28  virrlu  HALBE-5247    Support GCC Gnu compiler for CortexR52.
 *            2022-04-28  virrlu  -             Internal improvement.
 *  02.70.00  2022-05-10  visdri  HALBE-6253    Refactoring : Reduce the number of V7R exception handlers.
 *            2022-05-23  virrlu  HALBE-6879    Disable MPU before reprogramming in Os_Hal_MpCoreInit.
 *  02.71.00  2022-06-03  visdri  HALBE-6252    Refactoring : Context related.
 *            2022-06-15  vismid  HALBE-7089    Added coverage justifications for AR16XX.
 *            2022-06-15  visdri  HALBE-6250    Refactoring : Context related.
 *  02.72.00  2022-06-30  virrlu  HALBE-7324    Added support for CycloneVSE.
 *            2022-07-19  visdri  HALBE-7339    Add support to AM62xx with Llvm TI compiler (Development Release).
 *            2022-07-21  virrlu  HALBE-7000    Support for AM26xx.
 *  02.73.00  2022-08-04  virrlu  HALBE-7522    Support for S32Gxx A53.
 *            2022-08-05  mhu     HALBE-7116    Support for E3x timer.
 *                        dhe     HALBE-7118    Support for E3x multicore.
 *                        dhe     HALBE-7434    Support for all E3x derivatives.
 *            2022-08-11  visdri  HALBE-7346    Support AM62xxA with Compiler LlvmTI compiler (Development Release).
 *  02.74.00  2022-08-31  virmid  HALBE-6491    Added reference manual for Jacinto low device.
 *                        virmid  HALBE-7532    Add support for TCC7045
 *            2022-09-05  virrlu  HALBE-7440    Internal improvement.
 *            2022-09-16  dhe     HALBE-7561    Support for E3x QM.
 *  02.75.00  2022-09-27  visdri  HALBE-7701    Disable VIC interface for Jacinto7, TPR12 VIM IntC.
 *            2022-10-06  virrlu  HALBE-7443    Support for AM26xx multicore.
 *  02.76.00  2022-10-20  virrlu  HALBE-7946    Internal improvement.
 *            2022-11-02  virrlu  HALBE-6919    CortexR52 ASIL release.
 *            2022-11-03  virrlu  ESCAN00113117 Time triggered events (Timing Protection, Alarms and Schedule Tables) 
 *                                              based on Jacinto7 FRT do not occur for an unspecified amount of time.
 *  02.77.00  2022-12-06  virrlu  HALBE-8078    Extend configurable v7r MPU settings to cover all possible cache settings.
 *  02.78.00  2022-12-28  virrlu  ESCAN00113495 Interworking between thumb and arm code not working when compiling with 
 *                                              option -mthumb with LLVM Hightec compiler.
 *                        visqli  HALBE-7774    OS [E3] - Update E3 HAL to use the level register in VIC.
 *                        dhe     HALBE-7614    OS CortexR - Semidirve E3 Add SC2/SC4 support.
 *  02.79.00  2023-01-16  virrlu  HALBE-8347    Fix AM263x MISRA warning.
 *            2023-01-17  virrlu  ESCAN00113596 Compiler error: unused parameter 'RegBlock' [-Werror, -Wunused-parameter].
 *            2023-01-31  virrlu  HALBE-8573    Provide new interface Os_Hal_TimerFrtGetCompareValue().
 *            2023-02-03  virmid  HALBE-7076    Add support for RCAR V4H (Development).
 *  02.80.00  2023-02-20  visqli  PANDA-88      E3 - Adapt the eTimer and BTM implementation.
 *            2023-02-28  virrlu  HALBE-7665    FETA Analysis.
 *            2023-03-01  virmid  HALBE-7380    Support new derivatives for Jacinto7.
 *            2023-03-01  virmid  HALBE-8720    Adjusted getcoreid within a cluster (V8R).
 *  02.81.00  2023-03-21  virmid  HALBE-9091    Added MISRA and ReviewHelper justification.
 *            2023-03-21  virmid  HALBE-9090    Generator update.
 *            2023-03-21  virmid  HALBE-9009    Added FETA justifications.
 *            2023-03-29  visqli  PANDA-133     E3 - Adapt the FRT and PIT hardware usage.
 *                        visqli  PANDA-140     E3 - Refinement for avoiding interrupt interference among different cores.
 *                        visqli  ESCAN00114276 The channel number and base address of eTimer(ETMR) in E31xx and E33xx 
 *                                              are wrongly used because of an older TRM version from Semidrive.
 *            2023-03-29  xchen   HALBE-8549    Retest TMPV7706XBG (Visconti5).
 *                        virrlu  ESCAN00114297 On AM263x multi core systems the OS switches to invalid stack area when 
 *                                              exception or unhandled interrupt occurs on R5FSS1 domain cores.
 *            2023-03-30  virrlu  ESCAN00114305 Functions reading out 64 bit core registers return incorrect values 
 *                                              when using optimization option -O0 with LLVM HighTec compiler.
 *  02.82.00  2023-04-27  vcbjhao PANDA-47      G9H - Implement Multicore Support.
 *  02.83.00  2023-05-11  virrlu  HALBE-9482    Internal improvement.
 *            2023-05-12  virrlu  HALBE-9397    Updated coverage justifications for SR6P7.
 *            2023-05-24  mhu     PANDA-124     Support LG6110.
 *            2023-05-26  vcbjhao PANDA-162     G9H improvements.
 *  02.84.00  2023-06-16  xchen   HALBE-9239    Resolve compiler warnings with compiler IAR8.50.x.
 *            2023-06-20  virrlu  HALBE-9818    Add support for GccNxp compiler.
 *  02.85.00  2023-07-20  virrlu  -             Update due to BSWMD update.
 *  02.86.00  2023-08-02  virrlu  HALBE-10127   Store instruction address of unhandled interrupts on TPRxx.
 *  02.87.00  2023-08-24  visdri  HALBE-10092   Use the generic multiprocessor group Os_Hal_CoreGetId() for Zuxx.
 *                        visdri  HALBE-9155    Use the generic Os_Hal_CoreGetId() / Os_Hal_CoreGetId_Asm for Jacinto7.
 *  02.88.00  2023-10-12  virrlu  BASEENV-10427 Add support for RCARV4M.
 *  02.89.00  2023-10-26  virrlu  ESCAN00115998 OS disables MPU regions 1 and 2 even though scalability class is SC1/2.
 *            2023-10-30  virrlu  BASEENV-10835 Justify unused variable in file Os_Hal_InterruptController_VIM_Jacinto7.h.
 *            2023-12-06  virrlu  ESCAN00116053 OS does not perform cache and branch prediction maintenance during
 *                                              initial programming of the MPU.
 **********************************************************************************************************************/

#ifndef  OS_HAL_OS_H
# define OS_HAL_OS_H
                                                                                                                        /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_OsInt.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"

/* Os hal dependencies */


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/* ----- Component version information ----- */
# define OS_HAL_SW_MAJOR_VERSION                     (2u)
# define OS_HAL_SW_MINOR_VERSION                     (89u)
# define OS_HAL_SW_PATCH_VERSION                     (0u)

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#endif /* OS_HAL_OS_H */


/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Os.h
 **********************************************************************************************************************/
