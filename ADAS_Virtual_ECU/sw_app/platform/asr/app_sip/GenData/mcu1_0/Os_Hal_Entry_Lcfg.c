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
 *              File: Os_Hal_Entry_Lcfg.c
 *   Generation Time: 2024-02-13 13:07:50
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_ENTRY_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Entry_Cfg.h"
#include "Os_Hal_Entry_Lcfg.h"
#include "Os_Hal_Entry.h"

/* Os kernel module dependencies */
#include "Os_Isr_Lcfg.h"
#include "Os.h"

/* Os hal dependencies */
#include "Os_Hal_Cfg.h"
#include "Os_Hal_Core_Lcfg.h"
#include "Os_Hal_Interrupt_Cfg.h"
#include "Os_Hal_Trap.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EXCEPTION VECTOR TABLE CORE 0
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  INTERRUPT VECTOR TABLE CORE 0
 *********************************************************************************************************************/

#define OS_START_SEC_INTVEC_CORE0_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Extern declarations of the ISR wrappers. */
extern void Os_Isr_Core0_Interrupt_0(void);
extern void Os_Isr_Core0_UnhandledInterrupt_1(void);
extern void Os_Isr_Core0_Interrupt_2(void);
extern void Os_Isr_Core0_UnhandledInterrupt_3(void);
extern void Os_Isr_Core0_UnhandledInterrupt_4(void);
extern void Os_Isr_Core0_UnhandledInterrupt_5(void);
extern void Os_Isr_Core0_Interrupt_6(void);
extern void Os_Isr_Core0_Interrupt_7(void);
extern void Os_Isr_Core0_UnhandledInterrupt_8(void);
extern void Os_Isr_Core0_UnhandledInterrupt_9(void);
extern void Os_Isr_Core0_UnhandledInterrupt_10(void);
extern void Os_Isr_Core0_UnhandledInterrupt_11(void);
extern void Os_Isr_Core0_UnhandledInterrupt_12(void);
extern void Os_Isr_Core0_UnhandledInterrupt_13(void);
extern void Os_Isr_Core0_UnhandledInterrupt_14(void);
extern void Os_Isr_Core0_UnhandledInterrupt_15(void);
extern void Os_Isr_Core0_UnhandledInterrupt_16(void);
extern void Os_Isr_Core0_UnhandledInterrupt_17(void);
extern void Os_Isr_Core0_Interrupt_18(void);
extern void Os_Isr_Core0_UnhandledInterrupt_19(void);
extern void Os_Isr_Core0_UnhandledInterrupt_20(void);
extern void Os_Isr_Core0_UnhandledInterrupt_21(void);
extern void Os_Isr_Core0_UnhandledInterrupt_22(void);
extern void Os_Isr_Core0_UnhandledInterrupt_23(void);
extern void Os_Isr_Core0_UnhandledInterrupt_24(void);
extern void Os_Isr_Core0_UnhandledInterrupt_25(void);
extern void Os_Isr_Core0_UnhandledInterrupt_26(void);
extern void Os_Isr_Core0_UnhandledInterrupt_27(void);
extern void Os_Isr_Core0_UnhandledInterrupt_28(void);
extern void Os_Isr_Core0_UnhandledInterrupt_29(void);
extern void Os_Isr_Core0_UnhandledInterrupt_30(void);
extern void Os_Isr_Core0_UnhandledInterrupt_31(void);
extern void Os_Isr_Core0_UnhandledInterrupt_32(void);
extern void Os_Isr_Core0_UnhandledInterrupt_33(void);
extern void Os_Isr_Core0_UnhandledInterrupt_34(void);
extern void Os_Isr_Core0_UnhandledInterrupt_35(void);
extern void Os_Isr_Core0_Interrupt_36(void);
extern void Os_Isr_Core0_Interrupt_37(void);
extern void Os_Isr_Core0_UnhandledInterrupt_38(void);
extern void Os_Isr_Core0_Interrupt_39(void);
extern void Os_Isr_Core0_UnhandledInterrupt_40(void);
extern void Os_Isr_Core0_UnhandledInterrupt_41(void);
extern void Os_Isr_Core0_UnhandledInterrupt_42(void);
extern void Os_Isr_Core0_UnhandledInterrupt_43(void);
extern void Os_Isr_Core0_Interrupt_44(void);
extern void Os_Isr_Core0_UnhandledInterrupt_45(void);
extern void Os_Isr_Core0_UnhandledInterrupt_46(void);
extern void Os_Isr_Core0_Interrupt_47(void);
extern void Os_Isr_Core0_Interrupt_48(void);
extern void Os_Isr_Core0_Interrupt_49(void);
extern void Os_Isr_Core0_UnhandledInterrupt_50(void);
extern void Os_Isr_Core0_UnhandledInterrupt_51(void);
extern void Os_Isr_Core0_UnhandledInterrupt_52(void);
extern void Os_Isr_Core0_Interrupt_53(void);
extern void Os_Isr_Core0_UnhandledInterrupt_54(void);
extern void Os_Isr_Core0_UnhandledInterrupt_55(void);
extern void Os_Isr_Core0_UnhandledInterrupt_56(void);
extern void Os_Isr_Core0_UnhandledInterrupt_57(void);
extern void Os_Isr_Core0_UnhandledInterrupt_58(void);
extern void Os_Isr_Core0_UnhandledInterrupt_59(void);
extern void Os_Isr_Core0_UnhandledInterrupt_60(void);
extern void Os_Isr_Core0_UnhandledInterrupt_61(void);
extern void Os_Isr_Core0_UnhandledInterrupt_62(void);
extern void Os_Isr_Core0_UnhandledInterrupt_63(void);
extern void Os_Isr_Core0_UnhandledInterrupt_64(void);
extern void Os_Isr_Core0_UnhandledInterrupt_65(void);
extern void Os_Isr_Core0_UnhandledInterrupt_66(void);
extern void Os_Isr_Core0_UnhandledInterrupt_67(void);
extern void Os_Isr_Core0_UnhandledInterrupt_68(void);
extern void Os_Isr_Core0_UnhandledInterrupt_69(void);
extern void Os_Isr_Core0_Interrupt_70(void);
extern void Os_Isr_Core0_Interrupt_71(void);
extern void Os_Isr_Core0_Interrupt_72(void);
extern void Os_Isr_Core0_Interrupt_73(void);
extern void Os_Isr_Core0_UnhandledInterrupt_74(void);
extern void Os_Isr_Core0_UnhandledInterrupt_75(void);
extern void Os_Isr_Core0_UnhandledInterrupt_76(void);
extern void Os_Isr_Core0_UnhandledInterrupt_77(void);
extern void Os_Isr_Core0_Interrupt_78(void);
extern void Os_Isr_Core0_Interrupt_79(void);
extern void Os_Isr_Core0_UnhandledInterrupt_80(void);
extern void Os_Isr_Core0_UnhandledInterrupt_81(void);
extern void Os_Isr_Core0_UnhandledInterrupt_82(void);
extern void Os_Isr_Core0_UnhandledInterrupt_83(void);
extern void Os_Isr_Core0_UnhandledInterrupt_84(void);
extern void Os_Isr_Core0_UnhandledInterrupt_85(void);
extern void Os_Isr_Core0_UnhandledInterrupt_86(void);
extern void Os_Isr_Core0_UnhandledInterrupt_87(void);
extern void Os_Isr_Core0_UnhandledInterrupt_88(void);
extern void Os_Isr_Core0_UnhandledInterrupt_89(void);
extern void Os_Isr_Core0_UnhandledInterrupt_90(void);
extern void Os_Isr_Core0_UnhandledInterrupt_91(void);
extern void Os_Isr_Core0_UnhandledInterrupt_92(void);
extern void Os_Isr_Core0_UnhandledInterrupt_93(void);
extern void Os_Isr_Core0_UnhandledInterrupt_94(void);
extern void Os_Isr_Core0_UnhandledInterrupt_95(void);
extern void Os_Isr_Core0_Interrupt_96(void);
extern void Os_Isr_Core0_UnhandledInterrupt_97(void);
extern void Os_Isr_Core0_Interrupt_98(void);
extern void Os_Isr_Core0_Interrupt_99(void);
extern void Os_Isr_Core0_Interrupt_100(void);
extern void Os_Isr_Core0_UnhandledInterrupt_101(void);
extern void Os_Isr_Core0_UnhandledInterrupt_102(void);
extern void Os_Isr_Core0_UnhandledInterrupt_103(void);
extern void Os_Isr_Core0_UnhandledInterrupt_104(void);
extern void Os_Isr_Core0_UnhandledInterrupt_105(void);
extern void Os_Isr_Core0_UnhandledInterrupt_106(void);
extern void Os_Isr_Core0_UnhandledInterrupt_107(void);
extern void Os_Isr_Core0_UnhandledInterrupt_108(void);
extern void Os_Isr_Core0_UnhandledInterrupt_109(void);
extern void Os_Isr_Core0_UnhandledInterrupt_110(void);
extern void Os_Isr_Core0_UnhandledInterrupt_111(void);
extern void Os_Isr_Core0_UnhandledInterrupt_112(void);
extern void Os_Isr_Core0_UnhandledInterrupt_113(void);
extern void Os_Isr_Core0_UnhandledInterrupt_114(void);
extern void Os_Isr_Core0_UnhandledInterrupt_115(void);
extern void Os_Isr_Core0_UnhandledInterrupt_116(void);
extern void Os_Isr_Core0_UnhandledInterrupt_117(void);
extern void Os_Isr_Core0_UnhandledInterrupt_118(void);
extern void Os_Isr_Core0_UnhandledInterrupt_119(void);
extern void Os_Isr_Core0_UnhandledInterrupt_120(void);
extern void Os_Isr_Core0_UnhandledInterrupt_121(void);
extern void Os_Isr_Core0_UnhandledInterrupt_122(void);
extern void Os_Isr_Core0_UnhandledInterrupt_123(void);
extern void Os_Isr_Core0_UnhandledInterrupt_124(void);
extern void Os_Isr_Core0_UnhandledInterrupt_125(void);
extern void Os_Isr_Core0_UnhandledInterrupt_126(void);
extern void Os_Isr_Core0_UnhandledInterrupt_127(void);
extern void Os_Isr_Core0_UnhandledInterrupt_128(void);
extern void Os_Isr_Core0_UnhandledInterrupt_129(void);
extern void Os_Isr_Core0_UnhandledInterrupt_130(void);
extern void Os_Isr_Core0_UnhandledInterrupt_131(void);
extern void Os_Isr_Core0_UnhandledInterrupt_132(void);
extern void Os_Isr_Core0_UnhandledInterrupt_133(void);
extern void Os_Isr_Core0_UnhandledInterrupt_134(void);
extern void Os_Isr_Core0_UnhandledInterrupt_135(void);
extern void Os_Isr_Core0_UnhandledInterrupt_136(void);
extern void Os_Isr_Core0_UnhandledInterrupt_137(void);
extern void Os_Isr_Core0_UnhandledInterrupt_138(void);
extern void Os_Isr_Core0_UnhandledInterrupt_139(void);
extern void Os_Isr_Core0_Interrupt_140(void);
extern void Os_Isr_Core0_Interrupt_141(void);
extern void Os_Isr_Core0_Interrupt_142(void);
extern void Os_Isr_Core0_UnhandledInterrupt_143(void);
extern void Os_Isr_Core0_UnhandledInterrupt_144(void);
extern void Os_Isr_Core0_UnhandledInterrupt_145(void);
extern void Os_Isr_Core0_UnhandledInterrupt_146(void);
extern void Os_Isr_Core0_UnhandledInterrupt_147(void);
extern void Os_Isr_Core0_UnhandledInterrupt_148(void);
extern void Os_Isr_Core0_UnhandledInterrupt_149(void);
extern void Os_Isr_Core0_UnhandledInterrupt_150(void);
extern void Os_Isr_Core0_UnhandledInterrupt_151(void);
extern void Os_Isr_Core0_UnhandledInterrupt_152(void);
extern void Os_Isr_Core0_UnhandledInterrupt_153(void);
extern void Os_Isr_Core0_UnhandledInterrupt_154(void);
extern void Os_Isr_Core0_UnhandledInterrupt_155(void);
extern void Os_Isr_Core0_UnhandledInterrupt_156(void);
extern void Os_Isr_Core0_UnhandledInterrupt_157(void);
extern void Os_Isr_Core0_UnhandledInterrupt_158(void);
extern void Os_Isr_Core0_UnhandledInterrupt_159(void);
extern void Os_Isr_Core0_UnhandledInterrupt_160(void);
extern void Os_Isr_Core0_UnhandledInterrupt_161(void);
extern void Os_Isr_Core0_UnhandledInterrupt_162(void);
extern void Os_Isr_Core0_UnhandledInterrupt_163(void);
extern void Os_Isr_Core0_UnhandledInterrupt_164(void);
extern void Os_Isr_Core0_UnhandledInterrupt_165(void);
extern void Os_Isr_Core0_UnhandledInterrupt_166(void);
extern void Os_Isr_Core0_UnhandledInterrupt_167(void);
extern void Os_Isr_Core0_UnhandledInterrupt_168(void);
extern void Os_Isr_Core0_UnhandledInterrupt_169(void);
extern void Os_Isr_Core0_UnhandledInterrupt_170(void);
extern void Os_Isr_Core0_UnhandledInterrupt_171(void);
extern void Os_Isr_Core0_UnhandledInterrupt_172(void);
extern void Os_Isr_Core0_UnhandledInterrupt_173(void);
extern void Os_Isr_Core0_UnhandledInterrupt_174(void);
extern void Os_Isr_Core0_UnhandledInterrupt_175(void);
extern void Os_Isr_Core0_UnhandledInterrupt_176(void);
extern void Os_Isr_Core0_UnhandledInterrupt_177(void);
extern void Os_Isr_Core0_UnhandledInterrupt_178(void);
extern void Os_Isr_Core0_UnhandledInterrupt_179(void);
extern void Os_Isr_Core0_UnhandledInterrupt_180(void);
extern void Os_Isr_Core0_UnhandledInterrupt_181(void);
extern void Os_Isr_Core0_UnhandledInterrupt_182(void);
extern void Os_Isr_Core0_UnhandledInterrupt_183(void);
extern void Os_Isr_Core0_UnhandledInterrupt_184(void);
extern void Os_Isr_Core0_UnhandledInterrupt_185(void);
extern void Os_Isr_Core0_UnhandledInterrupt_186(void);
extern void Os_Isr_Core0_UnhandledInterrupt_187(void);
extern void Os_Isr_Core0_UnhandledInterrupt_188(void);
extern void Os_Isr_Core0_UnhandledInterrupt_189(void);
extern void Os_Isr_Core0_UnhandledInterrupt_190(void);
extern void Os_Isr_Core0_UnhandledInterrupt_191(void);
extern void Os_Isr_Core0_UnhandledInterrupt_192(void);
extern void Os_Isr_Core0_UnhandledInterrupt_193(void);
extern void Os_Isr_Core0_UnhandledInterrupt_194(void);
extern void Os_Isr_Core0_UnhandledInterrupt_195(void);
extern void Os_Isr_Core0_UnhandledInterrupt_196(void);
extern void Os_Isr_Core0_UnhandledInterrupt_197(void);
extern void Os_Isr_Core0_UnhandledInterrupt_198(void);
extern void Os_Isr_Core0_UnhandledInterrupt_199(void);
extern void Os_Isr_Core0_UnhandledInterrupt_200(void);
extern void Os_Isr_Core0_UnhandledInterrupt_201(void);
extern void Os_Isr_Core0_UnhandledInterrupt_202(void);
extern void Os_Isr_Core0_UnhandledInterrupt_203(void);
extern void Os_Isr_Core0_UnhandledInterrupt_204(void);
extern void Os_Isr_Core0_UnhandledInterrupt_205(void);
extern void Os_Isr_Core0_UnhandledInterrupt_206(void);
extern void Os_Isr_Core0_UnhandledInterrupt_207(void);
extern void Os_Isr_Core0_UnhandledInterrupt_208(void);
extern void Os_Isr_Core0_UnhandledInterrupt_209(void);
extern void Os_Isr_Core0_UnhandledInterrupt_210(void);
extern void Os_Isr_Core0_UnhandledInterrupt_211(void);
extern void Os_Isr_Core0_UnhandledInterrupt_212(void);
extern void Os_Isr_Core0_UnhandledInterrupt_213(void);
extern void Os_Isr_Core0_UnhandledInterrupt_214(void);
extern void Os_Isr_Core0_UnhandledInterrupt_215(void);
extern void Os_Isr_Core0_UnhandledInterrupt_216(void);
extern void Os_Isr_Core0_UnhandledInterrupt_217(void);
extern void Os_Isr_Core0_UnhandledInterrupt_218(void);
extern void Os_Isr_Core0_UnhandledInterrupt_219(void);
extern void Os_Isr_Core0_UnhandledInterrupt_220(void);
extern void Os_Isr_Core0_UnhandledInterrupt_221(void);
extern void Os_Isr_Core0_UnhandledInterrupt_222(void);
extern void Os_Isr_Core0_UnhandledInterrupt_223(void);
extern void Os_Isr_Core0_UnhandledInterrupt_224(void);
extern void Os_Isr_Core0_UnhandledInterrupt_225(void);
extern void Os_Isr_Core0_UnhandledInterrupt_226(void);
extern void Os_Isr_Core0_UnhandledInterrupt_227(void);
extern void Os_Isr_Core0_UnhandledInterrupt_228(void);
extern void Os_Isr_Core0_UnhandledInterrupt_229(void);
extern void Os_Isr_Core0_UnhandledInterrupt_230(void);
extern void Os_Isr_Core0_UnhandledInterrupt_231(void);
extern void Os_Isr_Core0_UnhandledInterrupt_232(void);
extern void Os_Isr_Core0_UnhandledInterrupt_233(void);
extern void Os_Isr_Core0_UnhandledInterrupt_234(void);
extern void Os_Isr_Core0_UnhandledInterrupt_235(void);
extern void Os_Isr_Core0_UnhandledInterrupt_236(void);
extern void Os_Isr_Core0_UnhandledInterrupt_237(void);
extern void Os_Isr_Core0_UnhandledInterrupt_238(void);
extern void Os_Isr_Core0_UnhandledInterrupt_239(void);
extern void Os_Isr_Core0_UnhandledInterrupt_240(void);
extern void Os_Isr_Core0_UnhandledInterrupt_241(void);
extern void Os_Isr_Core0_UnhandledInterrupt_242(void);
extern void Os_Isr_Core0_UnhandledInterrupt_243(void);
extern void Os_Isr_Core0_UnhandledInterrupt_244(void);
extern void Os_Isr_Core0_UnhandledInterrupt_245(void);
extern void Os_Isr_Core0_UnhandledInterrupt_246(void);
extern void Os_Isr_Core0_UnhandledInterrupt_247(void);
extern void Os_Isr_Core0_UnhandledInterrupt_248(void);
extern void Os_Isr_Core0_UnhandledInterrupt_249(void);
extern void Os_Isr_Core0_UnhandledInterrupt_250(void);
extern void Os_Isr_Core0_UnhandledInterrupt_251(void);
extern void Os_Isr_Core0_UnhandledInterrupt_252(void);
extern void Os_Isr_Core0_UnhandledInterrupt_253(void);
extern void Os_Isr_Core0_UnhandledInterrupt_254(void);
extern void Os_Isr_Core0_UnhandledInterrupt_255(void);
extern void Os_Isr_Core0_UnhandledInterrupt_256(void);
extern void Os_Isr_Core0_UnhandledInterrupt_257(void);
extern void Os_Isr_Core0_UnhandledInterrupt_258(void);
extern void Os_Isr_Core0_UnhandledInterrupt_259(void);
extern void Os_Isr_Core0_UnhandledInterrupt_260(void);
extern void Os_Isr_Core0_UnhandledInterrupt_261(void);
extern void Os_Isr_Core0_UnhandledInterrupt_262(void);
extern void Os_Isr_Core0_UnhandledInterrupt_263(void);
extern void Os_Isr_Core0_UnhandledInterrupt_264(void);
extern void Os_Isr_Core0_UnhandledInterrupt_265(void);
extern void Os_Isr_Core0_UnhandledInterrupt_266(void);
extern void Os_Isr_Core0_UnhandledInterrupt_267(void);
extern void Os_Isr_Core0_UnhandledInterrupt_268(void);
extern void Os_Isr_Core0_UnhandledInterrupt_269(void);
extern void Os_Isr_Core0_UnhandledInterrupt_270(void);
extern void Os_Isr_Core0_UnhandledInterrupt_271(void);
extern void Os_Isr_Core0_UnhandledInterrupt_272(void);
extern void Os_Isr_Core0_UnhandledInterrupt_273(void);
extern void Os_Isr_Core0_UnhandledInterrupt_274(void);
extern void Os_Isr_Core0_UnhandledInterrupt_275(void);
extern void Os_Isr_Core0_UnhandledInterrupt_276(void);
extern void Os_Isr_Core0_UnhandledInterrupt_277(void);
extern void Os_Isr_Core0_UnhandledInterrupt_278(void);
extern void Os_Isr_Core0_UnhandledInterrupt_279(void);
extern void Os_Isr_Core0_UnhandledInterrupt_280(void);
extern void Os_Isr_Core0_UnhandledInterrupt_281(void);
extern void Os_Isr_Core0_UnhandledInterrupt_282(void);
extern void Os_Isr_Core0_UnhandledInterrupt_283(void);
extern void Os_Isr_Core0_UnhandledInterrupt_284(void);
extern void Os_Isr_Core0_UnhandledInterrupt_285(void);
extern void Os_Isr_Core0_UnhandledInterrupt_286(void);
extern void Os_Isr_Core0_UnhandledInterrupt_287(void);
extern void Os_Isr_Core0_UnhandledInterrupt_288(void);
extern void Os_Isr_Core0_UnhandledInterrupt_289(void);
extern void Os_Isr_Core0_Interrupt_290(void);
extern void Os_Isr_Core0_Interrupt_291(void);
extern void Os_Isr_Core0_UnhandledInterrupt_292(void);
extern void Os_Isr_Core0_UnhandledInterrupt_293(void);
extern void Os_Isr_Core0_UnhandledInterrupt_294(void);
extern void Os_Isr_Core0_Interrupt_295(void);
extern void Os_Isr_Core0_Interrupt_296(void);
extern void Os_Isr_Core0_Interrupt_297(void);
extern void Os_Isr_Core0_Interrupt_298(void);
extern void Os_Isr_Core0_Interrupt_299(void);
extern void Os_Isr_Core0_Interrupt_300(void);
extern void Os_Isr_Core0_UnhandledInterrupt_301(void);
extern void Os_Isr_Core0_UnhandledInterrupt_302(void);
extern void Os_Isr_Core0_UnhandledInterrupt_303(void);
extern void Os_Isr_Core0_Interrupt_304(void);
extern void Os_Isr_Core0_Interrupt_305(void);
extern void Os_Isr_Core0_Interrupt_306(void);
extern void Os_Isr_Core0_Interrupt_307(void);
extern void Os_Isr_Core0_Interrupt_308(void);
extern void Os_Isr_Core0_Interrupt_309(void);
extern void Os_Isr_Core0_Interrupt_310(void);
extern void Os_Isr_Core0_UnhandledInterrupt_311(void);
extern void Os_Isr_Core0_Interrupt_312(void);
extern void Os_Isr_Core0_Interrupt_313(void);
extern void Os_Isr_Core0_Interrupt_314(void);
extern void Os_Isr_Core0_UnhandledInterrupt_315(void);
extern void Os_Isr_Core0_UnhandledInterrupt_316(void);
extern void Os_Isr_Core0_Interrupt_317(void);
extern void Os_Isr_Core0_UnhandledInterrupt_318(void);
extern void Os_Isr_Core0_UnhandledInterrupt_319(void);
extern void Os_Isr_Core0_UnhandledInterrupt_320(void);
extern void Os_Isr_Core0_UnhandledInterrupt_321(void);
extern void Os_Isr_Core0_UnhandledInterrupt_322(void);
extern void Os_Isr_Core0_UnhandledInterrupt_323(void);
extern void Os_Isr_Core0_UnhandledInterrupt_324(void);
extern void Os_Isr_Core0_UnhandledInterrupt_325(void);
extern void Os_Isr_Core0_UnhandledInterrupt_326(void);
extern void Os_Isr_Core0_UnhandledInterrupt_327(void);
extern void Os_Isr_Core0_UnhandledInterrupt_328(void);
extern void Os_Isr_Core0_UnhandledInterrupt_329(void);
extern void Os_Isr_Core0_UnhandledInterrupt_330(void);
extern void Os_Isr_Core0_UnhandledInterrupt_331(void);
extern void Os_Isr_Core0_UnhandledInterrupt_332(void);
extern void Os_Isr_Core0_UnhandledInterrupt_333(void);
extern void Os_Isr_Core0_UnhandledInterrupt_334(void);
extern void Os_Isr_Core0_UnhandledInterrupt_335(void);
extern void Os_Isr_Core0_UnhandledInterrupt_336(void);
extern void Os_Isr_Core0_UnhandledInterrupt_337(void);
extern void Os_Isr_Core0_UnhandledInterrupt_338(void);
extern void Os_Isr_Core0_UnhandledInterrupt_339(void);
extern void Os_Isr_Core0_UnhandledInterrupt_340(void);
extern void Os_Isr_Core0_UnhandledInterrupt_341(void);
extern void Os_Isr_Core0_UnhandledInterrupt_342(void);
extern void Os_Isr_Core0_UnhandledInterrupt_343(void);
extern void Os_Isr_Core0_UnhandledInterrupt_344(void);
extern void Os_Isr_Core0_UnhandledInterrupt_345(void);
extern void Os_Isr_Core0_UnhandledInterrupt_346(void);
extern void Os_Isr_Core0_UnhandledInterrupt_347(void);
extern void Os_Isr_Core0_UnhandledInterrupt_348(void);
extern void Os_Isr_Core0_UnhandledInterrupt_349(void);
extern void Os_Isr_Core0_UnhandledInterrupt_350(void);
extern void Os_Isr_Core0_UnhandledInterrupt_351(void);
extern void Os_Isr_Core0_UnhandledInterrupt_352(void);
extern void Os_Isr_Core0_UnhandledInterrupt_353(void);
extern void Os_Isr_Core0_UnhandledInterrupt_354(void);
extern void Os_Isr_Core0_UnhandledInterrupt_355(void);
extern void Os_Isr_Core0_UnhandledInterrupt_356(void);
extern void Os_Isr_Core0_UnhandledInterrupt_357(void);
extern void Os_Isr_Core0_UnhandledInterrupt_358(void);
extern void Os_Isr_Core0_UnhandledInterrupt_359(void);
extern void Os_Isr_Core0_UnhandledInterrupt_360(void);
extern void Os_Isr_Core0_UnhandledInterrupt_361(void);
extern void Os_Isr_Core0_UnhandledInterrupt_362(void);
extern void Os_Isr_Core0_UnhandledInterrupt_363(void);
extern void Os_Isr_Core0_UnhandledInterrupt_364(void);
extern void Os_Isr_Core0_UnhandledInterrupt_365(void);
extern void Os_Isr_Core0_UnhandledInterrupt_366(void);
extern void Os_Isr_Core0_UnhandledInterrupt_367(void);
extern void Os_Isr_Core0_UnhandledInterrupt_368(void);
extern void Os_Isr_Core0_UnhandledInterrupt_369(void);
extern void Os_Isr_Core0_UnhandledInterrupt_370(void);
extern void Os_Isr_Core0_UnhandledInterrupt_371(void);
extern void Os_Isr_Core0_UnhandledInterrupt_372(void);
extern void Os_Isr_Core0_UnhandledInterrupt_373(void);
extern void Os_Isr_Core0_UnhandledInterrupt_374(void);
extern void Os_Isr_Core0_UnhandledInterrupt_375(void);
extern void Os_Isr_Core0_Interrupt_376(void);
extern void Os_Isr_Core0_Interrupt_377(void);
extern void Os_Isr_Core0_UnhandledInterrupt_378(void);
extern void Os_Isr_Core0_UnhandledInterrupt_379(void);
extern void Os_Isr_Core0_UnhandledInterrupt_380(void);
extern void Os_Isr_Core0_UnhandledInterrupt_381(void);
extern void Os_Isr_Core0_UnhandledInterrupt_382(void);
extern void Os_Isr_Core0_UnhandledInterrupt_383(void);

#define OS_STOP_SEC_INTVEC_CORE0_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_INTVEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(Os_Hal_VectorTableEntryType, OS_CONST) OsCfg_Hal_Core_OsCore0_VectorTable[384] =
{
   Os_Isr_Core0_Interrupt_0, 
  Os_Isr_Core0_UnhandledInterrupt_1,
   Os_Isr_Core0_Interrupt_2, 
  Os_Isr_Core0_UnhandledInterrupt_3,
  Os_Isr_Core0_UnhandledInterrupt_4,
  Os_Isr_Core0_UnhandledInterrupt_5,
   Os_Isr_Core0_Interrupt_6, 
   Os_Isr_Core0_Interrupt_7, 
  Os_Isr_Core0_UnhandledInterrupt_8,
  Os_Isr_Core0_UnhandledInterrupt_9,
  Os_Isr_Core0_UnhandledInterrupt_10,
  Os_Isr_Core0_UnhandledInterrupt_11,
  Os_Isr_Core0_UnhandledInterrupt_12,
  Os_Isr_Core0_UnhandledInterrupt_13,
  Os_Isr_Core0_UnhandledInterrupt_14,
  Os_Isr_Core0_UnhandledInterrupt_15,
  Os_Isr_Core0_UnhandledInterrupt_16,
  Os_Isr_Core0_UnhandledInterrupt_17,
   Os_Isr_Core0_Interrupt_18, 
  Os_Isr_Core0_UnhandledInterrupt_19,
  Os_Isr_Core0_UnhandledInterrupt_20,
  Os_Isr_Core0_UnhandledInterrupt_21,
  Os_Isr_Core0_UnhandledInterrupt_22,
  Os_Isr_Core0_UnhandledInterrupt_23,
  Os_Isr_Core0_UnhandledInterrupt_24,
  Os_Isr_Core0_UnhandledInterrupt_25,
  Os_Isr_Core0_UnhandledInterrupt_26,
  Os_Isr_Core0_UnhandledInterrupt_27,
  Os_Isr_Core0_UnhandledInterrupt_28,
  Os_Isr_Core0_UnhandledInterrupt_29,
  Os_Isr_Core0_UnhandledInterrupt_30,
  Os_Isr_Core0_UnhandledInterrupt_31,
  Os_Isr_Core0_UnhandledInterrupt_32,
  Os_Isr_Core0_UnhandledInterrupt_33,
  Os_Isr_Core0_UnhandledInterrupt_34,
  Os_Isr_Core0_UnhandledInterrupt_35,
   Os_Isr_Core0_Interrupt_36, 
   Os_Isr_Core0_Interrupt_37, 
  Os_Isr_Core0_UnhandledInterrupt_38,
   Os_Isr_Core0_Interrupt_39, 
  Os_Isr_Core0_UnhandledInterrupt_40,
  Os_Isr_Core0_UnhandledInterrupt_41,
  Os_Isr_Core0_UnhandledInterrupt_42,
  Os_Isr_Core0_UnhandledInterrupt_43,
   Os_Isr_Core0_Interrupt_44, 
  Os_Isr_Core0_UnhandledInterrupt_45,
  Os_Isr_Core0_UnhandledInterrupt_46,
   Os_Isr_Core0_Interrupt_47, 
   Os_Isr_Core0_Interrupt_48, 
   Os_Isr_Core0_Interrupt_49, 
  Os_Isr_Core0_UnhandledInterrupt_50,
  Os_Isr_Core0_UnhandledInterrupt_51,
  Os_Isr_Core0_UnhandledInterrupt_52,
   Os_Isr_Core0_Interrupt_53, 
  Os_Isr_Core0_UnhandledInterrupt_54,
  Os_Isr_Core0_UnhandledInterrupt_55,
  Os_Isr_Core0_UnhandledInterrupt_56,
  Os_Isr_Core0_UnhandledInterrupt_57,
  Os_Isr_Core0_UnhandledInterrupt_58,
  Os_Isr_Core0_UnhandledInterrupt_59,
  Os_Isr_Core0_UnhandledInterrupt_60,
  Os_Isr_Core0_UnhandledInterrupt_61,
  Os_Isr_Core0_UnhandledInterrupt_62,
  Os_Isr_Core0_UnhandledInterrupt_63,
  Os_Isr_Core0_UnhandledInterrupt_64,
  Os_Isr_Core0_UnhandledInterrupt_65,
  Os_Isr_Core0_UnhandledInterrupt_66,
  Os_Isr_Core0_UnhandledInterrupt_67,
  Os_Isr_Core0_UnhandledInterrupt_68,
  Os_Isr_Core0_UnhandledInterrupt_69,
   Os_Isr_Core0_Interrupt_70, 
   Os_Isr_Core0_Interrupt_71, 
   Os_Isr_Core0_Interrupt_72, 
   Os_Isr_Core0_Interrupt_73, 
  Os_Isr_Core0_UnhandledInterrupt_74,
  Os_Isr_Core0_UnhandledInterrupt_75,
  Os_Isr_Core0_UnhandledInterrupt_76,
  Os_Isr_Core0_UnhandledInterrupt_77,
   Os_Isr_Core0_Interrupt_78, 
   Os_Isr_Core0_Interrupt_79, 
  Os_Isr_Core0_UnhandledInterrupt_80,
  Os_Isr_Core0_UnhandledInterrupt_81,
  Os_Isr_Core0_UnhandledInterrupt_82,
  Os_Isr_Core0_UnhandledInterrupt_83,
  Os_Isr_Core0_UnhandledInterrupt_84,
  Os_Isr_Core0_UnhandledInterrupt_85,
  Os_Isr_Core0_UnhandledInterrupt_86,
  Os_Isr_Core0_UnhandledInterrupt_87,
  Os_Isr_Core0_UnhandledInterrupt_88,
  Os_Isr_Core0_UnhandledInterrupt_89,
  Os_Isr_Core0_UnhandledInterrupt_90,
  Os_Isr_Core0_UnhandledInterrupt_91,
  Os_Isr_Core0_UnhandledInterrupt_92,
  Os_Isr_Core0_UnhandledInterrupt_93,
  Os_Isr_Core0_UnhandledInterrupt_94,
  Os_Isr_Core0_UnhandledInterrupt_95,
   Os_Isr_Core0_Interrupt_96, 
  Os_Isr_Core0_UnhandledInterrupt_97,
   Os_Isr_Core0_Interrupt_98, 
   Os_Isr_Core0_Interrupt_99, 
   Os_Isr_Core0_Interrupt_100, 
  Os_Isr_Core0_UnhandledInterrupt_101,
  Os_Isr_Core0_UnhandledInterrupt_102,
  Os_Isr_Core0_UnhandledInterrupt_103,
  Os_Isr_Core0_UnhandledInterrupt_104,
  Os_Isr_Core0_UnhandledInterrupt_105,
  Os_Isr_Core0_UnhandledInterrupt_106,
  Os_Isr_Core0_UnhandledInterrupt_107,
  Os_Isr_Core0_UnhandledInterrupt_108,
  Os_Isr_Core0_UnhandledInterrupt_109,
  Os_Isr_Core0_UnhandledInterrupt_110,
  Os_Isr_Core0_UnhandledInterrupt_111,
  Os_Isr_Core0_UnhandledInterrupt_112,
  Os_Isr_Core0_UnhandledInterrupt_113,
  Os_Isr_Core0_UnhandledInterrupt_114,
  Os_Isr_Core0_UnhandledInterrupt_115,
  Os_Isr_Core0_UnhandledInterrupt_116,
  Os_Isr_Core0_UnhandledInterrupt_117,
  Os_Isr_Core0_UnhandledInterrupt_118,
  Os_Isr_Core0_UnhandledInterrupt_119,
  Os_Isr_Core0_UnhandledInterrupt_120,
  Os_Isr_Core0_UnhandledInterrupt_121,
  Os_Isr_Core0_UnhandledInterrupt_122,
  Os_Isr_Core0_UnhandledInterrupt_123,
  Os_Isr_Core0_UnhandledInterrupt_124,
  Os_Isr_Core0_UnhandledInterrupt_125,
  Os_Isr_Core0_UnhandledInterrupt_126,
  Os_Isr_Core0_UnhandledInterrupt_127,
  Os_Isr_Core0_UnhandledInterrupt_128,
  Os_Isr_Core0_UnhandledInterrupt_129,
  Os_Isr_Core0_UnhandledInterrupt_130,
  Os_Isr_Core0_UnhandledInterrupt_131,
  Os_Isr_Core0_UnhandledInterrupt_132,
  Os_Isr_Core0_UnhandledInterrupt_133,
  Os_Isr_Core0_UnhandledInterrupt_134,
  Os_Isr_Core0_UnhandledInterrupt_135,
  Os_Isr_Core0_UnhandledInterrupt_136,
  Os_Isr_Core0_UnhandledInterrupt_137,
  Os_Isr_Core0_UnhandledInterrupt_138,
  Os_Isr_Core0_UnhandledInterrupt_139,
   Os_Isr_Core0_Interrupt_140, 
   Os_Isr_Core0_Interrupt_141, 
   Os_Isr_Core0_Interrupt_142, 
  Os_Isr_Core0_UnhandledInterrupt_143,
  Os_Isr_Core0_UnhandledInterrupt_144,
  Os_Isr_Core0_UnhandledInterrupt_145,
  Os_Isr_Core0_UnhandledInterrupt_146,
  Os_Isr_Core0_UnhandledInterrupt_147,
  Os_Isr_Core0_UnhandledInterrupt_148,
  Os_Isr_Core0_UnhandledInterrupt_149,
  Os_Isr_Core0_UnhandledInterrupt_150,
  Os_Isr_Core0_UnhandledInterrupt_151,
  Os_Isr_Core0_UnhandledInterrupt_152,
  Os_Isr_Core0_UnhandledInterrupt_153,
  Os_Isr_Core0_UnhandledInterrupt_154,
  Os_Isr_Core0_UnhandledInterrupt_155,
  Os_Isr_Core0_UnhandledInterrupt_156,
  Os_Isr_Core0_UnhandledInterrupt_157,
  Os_Isr_Core0_UnhandledInterrupt_158,
  Os_Isr_Core0_UnhandledInterrupt_159,
  Os_Isr_Core0_UnhandledInterrupt_160,
  Os_Isr_Core0_UnhandledInterrupt_161,
  Os_Isr_Core0_UnhandledInterrupt_162,
  Os_Isr_Core0_UnhandledInterrupt_163,
  Os_Isr_Core0_UnhandledInterrupt_164,
  Os_Isr_Core0_UnhandledInterrupt_165,
  Os_Isr_Core0_UnhandledInterrupt_166,
  Os_Isr_Core0_UnhandledInterrupt_167,
  Os_Isr_Core0_UnhandledInterrupt_168,
  Os_Isr_Core0_UnhandledInterrupt_169,
  Os_Isr_Core0_UnhandledInterrupt_170,
  Os_Isr_Core0_UnhandledInterrupt_171,
  Os_Isr_Core0_UnhandledInterrupt_172,
  Os_Isr_Core0_UnhandledInterrupt_173,
  Os_Isr_Core0_UnhandledInterrupt_174,
  Os_Isr_Core0_UnhandledInterrupt_175,
  Os_Isr_Core0_UnhandledInterrupt_176,
  Os_Isr_Core0_UnhandledInterrupt_177,
  Os_Isr_Core0_UnhandledInterrupt_178,
  Os_Isr_Core0_UnhandledInterrupt_179,
  Os_Isr_Core0_UnhandledInterrupt_180,
  Os_Isr_Core0_UnhandledInterrupt_181,
  Os_Isr_Core0_UnhandledInterrupt_182,
  Os_Isr_Core0_UnhandledInterrupt_183,
  Os_Isr_Core0_UnhandledInterrupt_184,
  Os_Isr_Core0_UnhandledInterrupt_185,
  Os_Isr_Core0_UnhandledInterrupt_186,
  Os_Isr_Core0_UnhandledInterrupt_187,
  Os_Isr_Core0_UnhandledInterrupt_188,
  Os_Isr_Core0_UnhandledInterrupt_189,
  Os_Isr_Core0_UnhandledInterrupt_190,
  Os_Isr_Core0_UnhandledInterrupt_191,
  Os_Isr_Core0_UnhandledInterrupt_192,
  Os_Isr_Core0_UnhandledInterrupt_193,
  Os_Isr_Core0_UnhandledInterrupt_194,
  Os_Isr_Core0_UnhandledInterrupt_195,
  Os_Isr_Core0_UnhandledInterrupt_196,
  Os_Isr_Core0_UnhandledInterrupt_197,
  Os_Isr_Core0_UnhandledInterrupt_198,
  Os_Isr_Core0_UnhandledInterrupt_199,
  Os_Isr_Core0_UnhandledInterrupt_200,
  Os_Isr_Core0_UnhandledInterrupt_201,
  Os_Isr_Core0_UnhandledInterrupt_202,
  Os_Isr_Core0_UnhandledInterrupt_203,
  Os_Isr_Core0_UnhandledInterrupt_204,
  Os_Isr_Core0_UnhandledInterrupt_205,
  Os_Isr_Core0_UnhandledInterrupt_206,
  Os_Isr_Core0_UnhandledInterrupt_207,
  Os_Isr_Core0_UnhandledInterrupt_208,
  Os_Isr_Core0_UnhandledInterrupt_209,
  Os_Isr_Core0_UnhandledInterrupt_210,
  Os_Isr_Core0_UnhandledInterrupt_211,
  Os_Isr_Core0_UnhandledInterrupt_212,
  Os_Isr_Core0_UnhandledInterrupt_213,
  Os_Isr_Core0_UnhandledInterrupt_214,
  Os_Isr_Core0_UnhandledInterrupt_215,
  Os_Isr_Core0_UnhandledInterrupt_216,
  Os_Isr_Core0_UnhandledInterrupt_217,
  Os_Isr_Core0_UnhandledInterrupt_218,
  Os_Isr_Core0_UnhandledInterrupt_219,
  Os_Isr_Core0_UnhandledInterrupt_220,
  Os_Isr_Core0_UnhandledInterrupt_221,
  Os_Isr_Core0_UnhandledInterrupt_222,
  Os_Isr_Core0_UnhandledInterrupt_223,
  Os_Isr_Core0_UnhandledInterrupt_224,
  Os_Isr_Core0_UnhandledInterrupt_225,
  Os_Isr_Core0_UnhandledInterrupt_226,
  Os_Isr_Core0_UnhandledInterrupt_227,
  Os_Isr_Core0_UnhandledInterrupt_228,
  Os_Isr_Core0_UnhandledInterrupt_229,
  Os_Isr_Core0_UnhandledInterrupt_230,
  Os_Isr_Core0_UnhandledInterrupt_231,
  Os_Isr_Core0_UnhandledInterrupt_232,
  Os_Isr_Core0_UnhandledInterrupt_233,
  Os_Isr_Core0_UnhandledInterrupt_234,
  Os_Isr_Core0_UnhandledInterrupt_235,
  Os_Isr_Core0_UnhandledInterrupt_236,
  Os_Isr_Core0_UnhandledInterrupt_237,
  Os_Isr_Core0_UnhandledInterrupt_238,
  Os_Isr_Core0_UnhandledInterrupt_239,
  Os_Isr_Core0_UnhandledInterrupt_240,
  Os_Isr_Core0_UnhandledInterrupt_241,
  Os_Isr_Core0_UnhandledInterrupt_242,
  Os_Isr_Core0_UnhandledInterrupt_243,
  Os_Isr_Core0_UnhandledInterrupt_244,
  Os_Isr_Core0_UnhandledInterrupt_245,
  Os_Isr_Core0_UnhandledInterrupt_246,
  Os_Isr_Core0_UnhandledInterrupt_247,
  Os_Isr_Core0_UnhandledInterrupt_248,
  Os_Isr_Core0_UnhandledInterrupt_249,
  Os_Isr_Core0_UnhandledInterrupt_250,
  Os_Isr_Core0_UnhandledInterrupt_251,
  Os_Isr_Core0_UnhandledInterrupt_252,
  Os_Isr_Core0_UnhandledInterrupt_253,
  Os_Isr_Core0_UnhandledInterrupt_254,
  Os_Isr_Core0_UnhandledInterrupt_255,
  Os_Isr_Core0_UnhandledInterrupt_256,
  Os_Isr_Core0_UnhandledInterrupt_257,
  Os_Isr_Core0_UnhandledInterrupt_258,
  Os_Isr_Core0_UnhandledInterrupt_259,
  Os_Isr_Core0_UnhandledInterrupt_260,
  Os_Isr_Core0_UnhandledInterrupt_261,
  Os_Isr_Core0_UnhandledInterrupt_262,
  Os_Isr_Core0_UnhandledInterrupt_263,
  Os_Isr_Core0_UnhandledInterrupt_264,
  Os_Isr_Core0_UnhandledInterrupt_265,
  Os_Isr_Core0_UnhandledInterrupt_266,
  Os_Isr_Core0_UnhandledInterrupt_267,
  Os_Isr_Core0_UnhandledInterrupt_268,
  Os_Isr_Core0_UnhandledInterrupt_269,
  Os_Isr_Core0_UnhandledInterrupt_270,
  Os_Isr_Core0_UnhandledInterrupt_271,
  Os_Isr_Core0_UnhandledInterrupt_272,
  Os_Isr_Core0_UnhandledInterrupt_273,
  Os_Isr_Core0_UnhandledInterrupt_274,
  Os_Isr_Core0_UnhandledInterrupt_275,
  Os_Isr_Core0_UnhandledInterrupt_276,
  Os_Isr_Core0_UnhandledInterrupt_277,
  Os_Isr_Core0_UnhandledInterrupt_278,
  Os_Isr_Core0_UnhandledInterrupt_279,
  Os_Isr_Core0_UnhandledInterrupt_280,
  Os_Isr_Core0_UnhandledInterrupt_281,
  Os_Isr_Core0_UnhandledInterrupt_282,
  Os_Isr_Core0_UnhandledInterrupt_283,
  Os_Isr_Core0_UnhandledInterrupt_284,
  Os_Isr_Core0_UnhandledInterrupt_285,
  Os_Isr_Core0_UnhandledInterrupt_286,
  Os_Isr_Core0_UnhandledInterrupt_287,
  Os_Isr_Core0_UnhandledInterrupt_288,
  Os_Isr_Core0_UnhandledInterrupt_289,
   Os_Isr_Core0_Interrupt_290, 
   Os_Isr_Core0_Interrupt_291, 
  Os_Isr_Core0_UnhandledInterrupt_292,
  Os_Isr_Core0_UnhandledInterrupt_293,
  Os_Isr_Core0_UnhandledInterrupt_294,
   Os_Isr_Core0_Interrupt_295, 
   Os_Isr_Core0_Interrupt_296, 
   Os_Isr_Core0_Interrupt_297, 
   Os_Isr_Core0_Interrupt_298, 
   Os_Isr_Core0_Interrupt_299, 
   Os_Isr_Core0_Interrupt_300, 
  Os_Isr_Core0_UnhandledInterrupt_301,
  Os_Isr_Core0_UnhandledInterrupt_302,
  Os_Isr_Core0_UnhandledInterrupt_303,
   Os_Isr_Core0_Interrupt_304, 
   Os_Isr_Core0_Interrupt_305, 
   Os_Isr_Core0_Interrupt_306, 
   Os_Isr_Core0_Interrupt_307, 
   Os_Isr_Core0_Interrupt_308, 
   Os_Isr_Core0_Interrupt_309, 
   Os_Isr_Core0_Interrupt_310, 
  Os_Isr_Core0_UnhandledInterrupt_311,
   Os_Isr_Core0_Interrupt_312, 
   Os_Isr_Core0_Interrupt_313, 
   Os_Isr_Core0_Interrupt_314, 
  Os_Isr_Core0_UnhandledInterrupt_315,
  Os_Isr_Core0_UnhandledInterrupt_316,
   Os_Isr_Core0_Interrupt_317, 
  Os_Isr_Core0_UnhandledInterrupt_318,
  Os_Isr_Core0_UnhandledInterrupt_319,
  Os_Isr_Core0_UnhandledInterrupt_320,
  Os_Isr_Core0_UnhandledInterrupt_321,
  Os_Isr_Core0_UnhandledInterrupt_322,
  Os_Isr_Core0_UnhandledInterrupt_323,
  Os_Isr_Core0_UnhandledInterrupt_324,
  Os_Isr_Core0_UnhandledInterrupt_325,
  Os_Isr_Core0_UnhandledInterrupt_326,
  Os_Isr_Core0_UnhandledInterrupt_327,
  Os_Isr_Core0_UnhandledInterrupt_328,
  Os_Isr_Core0_UnhandledInterrupt_329,
  Os_Isr_Core0_UnhandledInterrupt_330,
  Os_Isr_Core0_UnhandledInterrupt_331,
  Os_Isr_Core0_UnhandledInterrupt_332,
  Os_Isr_Core0_UnhandledInterrupt_333,
  Os_Isr_Core0_UnhandledInterrupt_334,
  Os_Isr_Core0_UnhandledInterrupt_335,
  Os_Isr_Core0_UnhandledInterrupt_336,
  Os_Isr_Core0_UnhandledInterrupt_337,
  Os_Isr_Core0_UnhandledInterrupt_338,
  Os_Isr_Core0_UnhandledInterrupt_339,
  Os_Isr_Core0_UnhandledInterrupt_340,
  Os_Isr_Core0_UnhandledInterrupt_341,
  Os_Isr_Core0_UnhandledInterrupt_342,
  Os_Isr_Core0_UnhandledInterrupt_343,
  Os_Isr_Core0_UnhandledInterrupt_344,
  Os_Isr_Core0_UnhandledInterrupt_345,
  Os_Isr_Core0_UnhandledInterrupt_346,
  Os_Isr_Core0_UnhandledInterrupt_347,
  Os_Isr_Core0_UnhandledInterrupt_348,
  Os_Isr_Core0_UnhandledInterrupt_349,
  Os_Isr_Core0_UnhandledInterrupt_350,
  Os_Isr_Core0_UnhandledInterrupt_351,
  Os_Isr_Core0_UnhandledInterrupt_352,
  Os_Isr_Core0_UnhandledInterrupt_353,
  Os_Isr_Core0_UnhandledInterrupt_354,
  Os_Isr_Core0_UnhandledInterrupt_355,
  Os_Isr_Core0_UnhandledInterrupt_356,
  Os_Isr_Core0_UnhandledInterrupt_357,
  Os_Isr_Core0_UnhandledInterrupt_358,
  Os_Isr_Core0_UnhandledInterrupt_359,
  Os_Isr_Core0_UnhandledInterrupt_360,
  Os_Isr_Core0_UnhandledInterrupt_361,
  Os_Isr_Core0_UnhandledInterrupt_362,
  Os_Isr_Core0_UnhandledInterrupt_363,
  Os_Isr_Core0_UnhandledInterrupt_364,
  Os_Isr_Core0_UnhandledInterrupt_365,
  Os_Isr_Core0_UnhandledInterrupt_366,
  Os_Isr_Core0_UnhandledInterrupt_367,
  Os_Isr_Core0_UnhandledInterrupt_368,
  Os_Isr_Core0_UnhandledInterrupt_369,
  Os_Isr_Core0_UnhandledInterrupt_370,
  Os_Isr_Core0_UnhandledInterrupt_371,
  Os_Isr_Core0_UnhandledInterrupt_372,
  Os_Isr_Core0_UnhandledInterrupt_373,
  Os_Isr_Core0_UnhandledInterrupt_374,
  Os_Isr_Core0_UnhandledInterrupt_375,
   Os_Isr_Core0_Interrupt_376, 
   Os_Isr_Core0_Interrupt_377, 
  Os_Isr_Core0_UnhandledInterrupt_378,
  Os_Isr_Core0_UnhandledInterrupt_379,
  Os_Isr_Core0_UnhandledInterrupt_380,
  Os_Isr_Core0_UnhandledInterrupt_381,
  Os_Isr_Core0_UnhandledInterrupt_382,
  Os_Isr_Core0_UnhandledInterrupt_383,
};

#define OS_STOP_SEC_INTVEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Entry_Lcfg.c
 *********************************************************************************************************************/
