/** @file asil_memmap.h
 *  @brief  
 *  Includes compiler specific asil data definitions
 *  
 * 
 *  --------------------------------------------------------------------------
 *  @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * 
 *  @author Anonymous Author (Anonymous.Author@magna.com)
 */
 

#ifdef START_ASILB_CODE_SECTION
# undef START_ASILB_CODE_SECTION /* PRQA S 0841 */ /* MD_MSR_Undef */
#pragma clang section text="__asilb_code__"
#endif

#ifdef START_ASILB_DATA_SECTION
# undef START_ASILB_DATA_SECTION /* PRQA S 0841 */ /* MD_MSR_Undef */
#pragma clang section data="__asilb_data__"
#endif

#ifdef START_ASILB_BSS_SECTION
# undef START_ASILB_BSS_SECTION /* PRQA S 0841 */ /* MD_MSR_Undef */
#pragma clang section bss="__asilb_bss__"
#endif

#ifdef START_ASILB_CONST_SECTION
# undef START_ASILB_CONST_SECTION /* PRQA S 0841 */ /* MD_MSR_Undef */
#pragma clang section rodata="__asilb_const__"
#endif

#ifdef STOP_ASILB_CODE_SECTION
# undef STOP_ASILB_CODE_SECTION /* PRQA S 0841 */ /* MD_MSR_Undef */
#pragma clang section text=""
#endif

#ifdef STOP_ASILB_DATA_SECTION
# undef STOP_ASILB_DATA_SECTION /* PRQA S 0841 */ /* MD_MSR_Undef */
#pragma clang section data=""
#endif

#ifdef STOP_ASILB_BSS_SECTION
# undef STOP_ASILB_BSS_SECTION /* PRQA S 0841 */ /* MD_MSR_Undef */
#pragma clang section bss=""
#endif

#ifdef STOP_ASILB_CONST_SECTION
# undef STOP_ASILB_CONST_SECTION /* PRQA S 0841 */ /* MD_MSR_Undef */
#pragma clang section rodata=""
#endif

