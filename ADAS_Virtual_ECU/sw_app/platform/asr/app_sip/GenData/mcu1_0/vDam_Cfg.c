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
 *            Module: vDam
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vDam_Cfg.c
 *   Generation Time: 2025-03-05 18:52:34
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#define VDAM_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vDam_Cfg.h"
#include "vDam.h"



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (VDAM_LOCAL)
# define VDAM_LOCAL static
#endif

#if !defined (VDAM_LOCAL_INLINE)
# define VDAM_LOCAL_INLINE LOCAL_INLINE
#endif




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
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/






/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  vDam_IdentifierInfo
**********************************************************************************************************************/
/** 
  \var    vDam_IdentifierInfo
  \brief  List of Identifiers.
  \details
  Element            Description
  IdentifierId       Id of the Identifier.
  IdentifierRoles    Bit Mask for Roles which are allowed on this level.
*/ 
#define VDAM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "vDam_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vDam_IdentifierInfoType, VDAM_CONST) vDam_IdentifierInfo[177] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IdentifierId  IdentifierRoles        Comment                   Referable Keys */
  { /*     0 */      0x0103u,         0x0BFFu },  /* [ISID_0x103]  */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_220103] */
  { /*     1 */      0x0107u,         0x0BFFu },  /* [ISID_0x107]  */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_220107] */
  { /*     2 */      0x0108u,         0x0BFFu },  /* [ISID_0x108]  */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_220108] */
  { /*     3 */      0x1002u,         0x0BFFu },  /* [ISID_0x1002] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_221002] */
  { /*     4 */      0x1004u,         0x0BFFu },  /* [ISID_0x1004] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_221004] */
  { /*     5 */      0x1008u,         0x0BFFu },  /* [ISID_0x1008] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_221008] */
  { /*     6 */      0x1009u,         0x0BFFu },  /* [ISID_0x1009] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_221009] */
  { /*     7 */      0x100Bu,         0x0BFFu },  /* [ISID_0x100b] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22100B] */
  { /*     8 */      0x100Cu,         0x0BFFu },  /* [ISID_0x100c] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22100C] */
  { /*     9 */      0x102Au,         0x0BFFu },  /* [ISID_0x102a] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22102A] */
  { /*    10 */      0x191Du,         0x0BFFu },  /* [ISID_0x191d] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22191D] */
  { /*    11 */      0x1921u,         0x0BFFu },  /* [ISID_0x1921] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_221921] */
  { /*    12 */      0x2001u,         0x0BFFu },  /* [ISID_0x2001] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_222001] */
  { /*    13 */      0x2002u,         0x0BFFu },  /* [ISID_0x2002] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_222002] */
  { /*    14 */      0x2003u,         0x018Fu },  /* [ISID_0x2003] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_222003] */
  { /*    15 */      0x2008u,         0x0BFFu },  /* [ISID_0x2008] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_222008] */
  { /*    16 */      0x200Au,         0x0BFFu },  /* [ISID_0x200a] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22200A] */
  { /*    17 */      0x200Bu,         0x0BFFu },  /* [ISID_0x200b] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22200B] */
  { /*    18 */      0x200Cu,         0x0BFFu },  /* [ISID_0x200c] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22200C] */
  { /*    19 */      0x200Du,         0x0BFFu },  /* [ISID_0x200d] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22200D] */
  { /*    20 */      0x2010u,         0x0BFFu },  /* [ISID_0x2010] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_222010] */
  { /*    21 */      0x2013u,         0x0BFFu },  /* [ISID_0x2013] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_222013] */
  { /*    22 */      0x201Au,         0x0BFFu },  /* [ISID_0x201a] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22201A] */
  { /*    23 */      0x201Bu,         0x0BFFu },  /* [ISID_0x201b] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22201B] */
  { /*    24 */      0x201Fu,         0x0BFFu },  /* [ISID_0x201f] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22201F] */
  { /*    25 */      0x2024u,         0x0BFFu },  /* [ISID_0x2024] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_222024] */
  { /*    26 */      0x2026u,         0x0BFFu },  /* [ISID_0x2026] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_222026] */
  { /*    27 */      0x2030u,         0x000Du },  /* [ISID_0x2030] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_222030] */
  { /*    28 */      0x2031u,         0x000Du },  /* [ISID_0x2031] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_222031] */
  { /*    29 */      0x2032u,         0x000Du },  /* [ISID_0x2032] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_222032] */
  { /*    30 */      0x292Eu,         0x0BFFu },  /* [ISID_0x292e] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22292E] */
  { /*    31 */      0x2939u,         0x0BFFu },  /* [ISID_0x2939] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_222939] */
  { /*    32 */      0x2945u,         0x0BFFu },  /* [ISID_0x2945] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_222945] */
  { /*    33 */      0x2951u,         0x0BFFu },  /* [ISID_0x2951] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_222951] */
  { /*    34 */      0x2954u,         0x0BFFu },  /* [ISID_0x2954] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_222954] */
  { /*    35 */      0x2957u,         0x000Du },  /* [ISID_0x2957] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_222957] */
  { /*    36 */      0x2958u,         0x000Du },  /* [ISID_0x2958] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_222958] */
  { /*    37 */      0x2959u,         0x000Du },  /* [ISID_0x2959] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_222959] */
  { /*    38 */      0x295Au,         0x000Du },  /* [ISID_0x295a] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22295A] */
  { /*    39 */      0x295Bu,         0x000Du },  /* [ISID_0x295b] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22295B] */
  { /*    40 */      0x295Cu,         0x000Du },  /* [ISID_0x295c] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22295C] */
  { /*    41 */      0x295Eu,         0x000Du },  /* [ISID_0x295e] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22295E] */
  { /*    42 */      0x295Fu,         0x000Du },  /* [ISID_0x295f] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22295F] */
  { /*    43 */      0x4421u,         0x0BFFu },  /* [ISID_0x4421] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_224421] */
  { /*    44 */      0x4422u,         0x0BFFu },  /* [ISID_0x4422] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_224422] */
  { /*    45 */      0x4423u,         0x0BFFu },  /* [ISID_0x4423] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_224423] */
  { /*    46 */      0x4424u,         0x0BFFu },  /* [ISID_0x4424] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_224424] */
  { /*    47 */      0x4425u,         0x0BFFu },  /* [ISID_0x4425] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_224425] */
  { /*    48 */      0x4426u,         0x0BFFu },  /* [ISID_0x4426] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_224426] */
  { /*    49 */      0x4427u,         0x0BFFu },  /* [ISID_0x4427] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_224427] */
    /* Index    IdentifierId  IdentifierRoles        Comment                   Referable Keys */
  { /*    50 */      0x4428u,         0x0BFFu },  /* [ISID_0x4428] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_224428] */
  { /*    51 */      0x4429u,         0x0BFFu },  /* [ISID_0x4429] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_224429] */
  { /*    52 */      0x442Au,         0x0BFFu },  /* [ISID_0x442a] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22442A] */
  { /*    53 */      0x442Bu,         0x0BFFu },  /* [ISID_0x442b] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22442B] */
  { /*    54 */      0x442Cu,         0x0BFFu },  /* [ISID_0x442c] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22442C] */
  { /*    55 */      0x4451u,         0x0BFFu },  /* [ISID_0x4451] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_224451] */
  { /*    56 */      0x5100u,         0x0BFFu },  /* [ISID_0x5100] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_225100] */
  { /*    57 */      0x5102u,         0x000Du },  /* [ISID_0x5102] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_225102] */
  { /*    58 */      0x5103u,         0x000Du },  /* [ISID_0x5103] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_225103] */
  { /*    59 */      0x5104u,         0x000Du },  /* [ISID_0x5104] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_225104] */
  { /*    60 */      0x5105u,         0x000Du },  /* [ISID_0x5105] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_225105] */
  { /*    61 */      0x5107u,         0x000Du },  /* [ISID_0x5107] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_225107] */
  { /*    62 */      0x5109u,         0x000Du },  /* [ISID_0x5109] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_225109] */
  { /*    63 */      0x5201u,         0x0BFFu },  /* [ISID_0x5201] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_225201] */
  { /*    64 */      0x5300u,         0x0BFFu },  /* [ISID_0x5300] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_225300] */
  { /*    65 */      0x5301u,         0x0BFFu },  /* [ISID_0x5301] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_225301] */
  { /*    66 */      0x5302u,         0x0BFFu },  /* [ISID_0x5302] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_225302] */
  { /*    67 */      0x5303u,         0x0BFFu },  /* [ISID_0x5303] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_225303] */
  { /*    68 */      0x5304u,         0x0BFFu },  /* [ISID_0x5304] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_225304] */
  { /*    69 */      0x5305u,         0x0BFFu },  /* [ISID_0x5305] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_225305] */
  { /*    70 */      0x5500u,         0x000Du },  /* [ISID_0x5500] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_225500] */
  { /*    71 */      0x5501u,         0x000Du },  /* [ISID_0x5501] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_225501] */
  { /*    72 */      0xF10Bu,         0x0BFFu },  /* [ISID_0xf10b] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F10B] */
  { /*    73 */      0xF10Du,         0x0BFFu },  /* [ISID_0xf10d] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F10D] */
  { /*    74 */      0xF110u,         0x0BFFu },  /* [ISID_0xf110] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F110] */
  { /*    75 */      0xF111u,         0x000Du },  /* [ISID_0xf111] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F111] */
  { /*    76 */      0xF112u,         0x0BFFu },  /* [ISID_0xf112] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F112] */
  { /*    77 */      0xF122u,         0x0BFFu },  /* [ISID_0xf122] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F122] */
  { /*    78 */      0xF132u,         0x0BFFu },  /* [ISID_0xf132] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F132] */
  { /*    79 */      0xF133u,         0x0BFFu },  /* [ISID_0xf133] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F133] */
  { /*    80 */      0xF134u,         0x0BFFu },  /* [ISID_0xf134] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F134] */
  { /*    81 */      0xF154u,         0x0BFFu },  /* [ISID_0xf154] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F154] */
  { /*    82 */      0xF155u,         0x0BFFu },  /* [ISID_0xf155] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F155] */
  { /*    83 */      0xF180u,         0x0BFFu },  /* [ISID_0xf180] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F180] */
  { /*    84 */      0xF181u,         0x0BFFu },  /* [ISID_0xf181] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F181] */
  { /*    85 */      0xF182u,         0x0BFFu },  /* [ISID_0xf182] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F182] */
  { /*    86 */      0xF186u,         0x0BFFu },  /* [ISID_0xf186] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F186] */
  { /*    87 */      0xF187u,         0x0BFFu },  /* [ISID_0xf187] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F187] */
  { /*    88 */      0xF188u,         0x0BFFu },  /* [ISID_0xf188] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F188] */
  { /*    89 */      0xF18Au,         0x0BFFu },  /* [ISID_0xf18a] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F18A] */
  { /*    90 */      0xF18Bu,         0x0BFFu },  /* [ISID_0xf18b] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F18B] */
  { /*    91 */      0xF18Cu,         0x0BFFu },  /* [ISID_0xf18c] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F18C] */
  { /*    92 */      0xF190u,         0x0BFFu },  /* [ISID_0xf190] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F190] */
  { /*    93 */      0xF191u,         0x0BFFu },  /* [ISID_0xf191] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F191] */
  { /*    94 */      0xF192u,         0x0BFFu },  /* [ISID_0xf192] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F192] */
  { /*    95 */      0xF193u,         0x0BFFu },  /* [ISID_0xf193] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F193] */
  { /*    96 */      0xF194u,         0x0BFFu },  /* [ISID_0xf194] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F194] */
  { /*    97 */      0xF195u,         0x0BFFu },  /* [ISID_0xf195] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F195] */
  { /*    98 */      0xF1A0u,         0x0BFFu },  /* [ISID_0xf1a0] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F1A0] */
  { /*    99 */      0xF1A1u,         0x0BFFu },  /* [ISID_0xf1a1] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F1A1] */
    /* Index    IdentifierId  IdentifierRoles        Comment                   Referable Keys */
  { /*   100 */      0xF1A2u,         0x0BFFu },  /* [ISID_0xf1a2] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F1A2] */
  { /*   101 */      0xF1A6u,         0x0BFFu },  /* [ISID_0xf1a6] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F1A6] */
  { /*   102 */      0xF1B0u,         0x0BFFu },  /* [ISID_0xf1b0] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F1B0] */
  { /*   103 */      0xF1B3u,         0x0BFFu },  /* [ISID_0xf1b3] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F1B3] */
  { /*   104 */      0xF1B4u,         0x0BFFu },  /* [ISID_0xf1b4] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F1B4] */
  { /*   105 */      0xF1B5u,         0x0BFFu },  /* [ISID_0xf1b5] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22F1B5] */
  { /*   106 */      0xFD00u,         0x0BFFu },  /* [ISID_0xfd00] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD00] */
  { /*   107 */      0xFD01u,         0x0BFFu },  /* [ISID_0xfd01] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD01] */
  { /*   108 */      0xFD07u,         0x0BFFu },  /* [ISID_0xfd07] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD07] */
  { /*   109 */      0xFD08u,         0x0BFFu },  /* [ISID_0xfd08] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD08] */
  { /*   110 */      0xFD0Au,         0x0BFFu },  /* [ISID_0xfd0a] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD0A] */
  { /*   111 */      0xFD0Cu,         0x0BFFu },  /* [ISID_0xfd0c] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD0C] */
  { /*   112 */      0xFD0Du,         0x0BFFu },  /* [ISID_0xfd0d] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD0D] */
  { /*   113 */      0xFD0Eu,         0x0BFFu },  /* [ISID_0xfd0e] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD0E] */
  { /*   114 */      0xFD0Fu,         0x0BFFu },  /* [ISID_0xfd0f] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD0F] */
  { /*   115 */      0xFD13u,         0x0BFFu },  /* [ISID_0xfd13] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD13] */
  { /*   116 */      0xFD14u,         0x0BFFu },  /* [ISID_0xfd14] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD14] */
  { /*   117 */      0xFD15u,         0x0BFFu },  /* [ISID_0xfd15] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD15] */
  { /*   118 */      0xFD16u,         0x0BFFu },  /* [ISID_0xfd16] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD16] */
  { /*   119 */      0xFD17u,         0x0BFFu },  /* [ISID_0xfd17] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD17] */
  { /*   120 */      0xFD1Cu,         0x0BFFu },  /* [ISID_0xfd1c] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD1C] */
  { /*   121 */      0xFD1Du,         0x0BFFu },  /* [ISID_0xfd1d] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD1D] */
  { /*   122 */      0xFD1Eu,         0x0BFFu },  /* [ISID_0xfd1e] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD1E] */
  { /*   123 */      0xFD20u,         0x0BFFu },  /* [ISID_0xfd20] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD20] */
  { /*   124 */      0xFD28u,         0x0BFFu },  /* [ISID_0xfd28] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD28] */
  { /*   125 */      0xFD29u,         0x0BFFu },  /* [ISID_0xfd29] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD29] */
  { /*   126 */      0xFD2Au,         0x0BFFu },  /* [ISID_0xfd2a] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD2A] */
  { /*   127 */      0xFD2Bu,         0x0BFFu },  /* [ISID_0xfd2b] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD2B] */
  { /*   128 */      0xFD2Cu,         0x0BFFu },  /* [ISID_0xfd2c] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD2C] */
  { /*   129 */      0xFD2Du,         0x0BFFu },  /* [ISID_0xfd2d] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD2D] */
  { /*   130 */      0xFD2Eu,         0x0BFFu },  /* [ISID_0xfd2e] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD2E] */
  { /*   131 */      0xFD31u,         0x0BFFu },  /* [ISID_0xfd31] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD31] */
  { /*   132 */      0xFD33u,         0x0BFFu },  /* [ISID_0xfd33] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD33] */
  { /*   133 */      0xFD38u,         0x0BFFu },  /* [ISID_0xfd38] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD38] */
  { /*   134 */      0xFD42u,         0x0BFFu },  /* [ISID_0xfd42] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD42] */
  { /*   135 */      0xFD43u,         0x0BFFu },  /* [ISID_0xfd43] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD43] */
  { /*   136 */      0xFD44u,         0x0BFFu },  /* [ISID_0xfd44] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD44] */
  { /*   137 */      0xFD46u,         0x0BFFu },  /* [ISID_0xfd46] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD46] */
  { /*   138 */      0xFD47u,         0x0BFFu },  /* [ISID_0xfd47] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD47] */
  { /*   139 */      0xFD48u,         0x0BFFu },  /* [ISID_0xfd48] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD48] */
  { /*   140 */      0xFD49u,         0x0BFFu },  /* [ISID_0xfd49] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD49] */
  { /*   141 */      0xFD4Au,         0x0BFFu },  /* [ISID_0xfd4a] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD4A] */
  { /*   142 */      0xFD60u,         0x0BFFu },  /* [ISID_0xfd60] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD60] */
  { /*   143 */      0xFD61u,         0x0BFFu },  /* [ISID_0xfd61] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD61] */
  { /*   144 */      0xFD62u,         0x0BFFu },  /* [ISID_0xfd62] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD62] */
  { /*   145 */      0xFD64u,         0x0BFFu },  /* [ISID_0xfd64] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD64] */
  { /*   146 */      0xFD74u,         0x0BFFu },  /* [ISID_0xfd74] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD74] */
  { /*   147 */      0xFD86u,         0x0BFFu },  /* [ISID_0xfd86] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FD86] */
  { /*   148 */      0xFDF0u,         0x0BFFu },  /* [ISID_0xfdf0] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FDF0] */
  { /*   149 */      0xFDF1u,         0x0BFFu },  /* [ISID_0xfdf1] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FDF1] */
    /* Index    IdentifierId  IdentifierRoles        Comment                   Referable Keys */
  { /*   150 */      0xFDF2u,         0x0BFFu },  /* [ISID_0xfdf2] */  /* [SID_0x22|SSID_0xff, /ActiveEcuC/vDam/vDamService_22FDF2] */
  { /*   151 */      0x0107u,         0x038Fu },  /* [ISID_0x107]  */  /* [SID_0x2e|SSID_0xff, /ActiveEcuC/vDam/vDamService_2E0107] */
  { /*   152 */      0x2023u,         0x0BFFu },  /* [ISID_0x2023] */  /* [SID_0x2e|SSID_0xff, /ActiveEcuC/vDam/vDamService_2E2023] */
  { /*   153 */      0x2945u,         0x038Fu },  /* [ISID_0x2945] */  /* [SID_0x2e|SSID_0xff, /ActiveEcuC/vDam/vDamService_2E2945] */
  { /*   154 */      0xF184u,         0x038Fu },  /* [ISID_0xf184] */  /* [SID_0x2e|SSID_0xff, /ActiveEcuC/vDam/vDamService_2EF184] */
  { /*   155 */      0xF185u,         0x038Fu },  /* [ISID_0xf185] */  /* [SID_0x2e|SSID_0xff, /ActiveEcuC/vDam/vDamService_2EF185] */
  { /*   156 */      0x5001u,         0x000Du },  /* [ISID_0x5001] */  /* [SID_0x2f|SSID_0x0, /ActiveEcuC/vDam/vDamService_2F5001] */
  { /*   157 */      0x5001u,         0x000Du },  /* [ISID_0x5001] */  /* [SID_0x2f|SSID_0x3, /ActiveEcuC/vDam/vDamService_2F5001] */
  { /*   158 */      0x1000u,         0x0BFFu },  /* [ISID_0x1000] */  /* [SID_0x31|SSID_0xff, /ActiveEcuC/vDam/vDamService_31011000] */
  { /*   159 */      0x2000u,         0x038Fu },  /* [ISID_0x2000] */  /* [SID_0x31|SSID_0xff, /ActiveEcuC/vDam/vDamService_31012000] */
  { /*   160 */      0x2001u,         0x0005u },  /* [ISID_0x2001] */  /* [SID_0x31|SSID_0xff, /ActiveEcuC/vDam/vDamService_31012001] */
  { /*   161 */      0x3000u,         0x0BFFu },  /* [ISID_0x3000] */  /* [SID_0x31|SSID_0xff, /ActiveEcuC/vDam/vDamService_31013000] */
  { /*   162 */      0x5000u,         0x000Du },  /* [ISID_0x5000] */  /* [SID_0x31|SSID_0xff, /ActiveEcuC/vDam/vDamService_31015000] */
  { /*   163 */      0x5101u,         0x0BFFu },  /* [ISID_0x5101] */  /* [SID_0x31|SSID_0xff, /ActiveEcuC/vDam/vDamService_31015101] */
  { /*   164 */      0x5200u,         0x0BFFu },  /* [ISID_0x5200] */  /* [SID_0x31|SSID_0xff, /ActiveEcuC/vDam/vDamService_31015200] */
  { /*   165 */      0x5400u,         0x0BFFu },  /* [ISID_0x5400] */  /* [SID_0x31|SSID_0xff, /ActiveEcuC/vDam/vDamService_31015400] */
  { /*   166 */      0x5401u,         0x0BFFu },  /* [ISID_0x5401] */  /* [SID_0x31|SSID_0xff, /ActiveEcuC/vDam/vDamService_31015401] */
  { /*   167 */      0xD001u,         0x038Fu },  /* [ISID_0xd001] */  /* [SID_0x31|SSID_0xff, /ActiveEcuC/vDam/vDamService_3101D001] */
  { /*   168 */      0xD002u,         0x0BFFu },  /* [ISID_0xd002] */  /* [SID_0x31|SSID_0xff, /ActiveEcuC/vDam/vDamService_3101D002] */
  { /*   169 */      0xD003u,         0x038Fu },  /* [ISID_0xd003] */  /* [SID_0x31|SSID_0xff, /ActiveEcuC/vDam/vDamService_3101D003] */
  { /*   170 */      0xF000u,         0x038Fu },  /* [ISID_0xf000] */  /* [SID_0x31|SSID_0xff, /ActiveEcuC/vDam/vDamService_3101F000] */
  { /*   171 */      0xFE01u,         0x0BFFu },  /* [ISID_0xfe01] */  /* [SID_0x31|SSID_0xff, /ActiveEcuC/vDam/vDamService_3101FE01] */
  { /*   172 */      0xFE02u,         0x0BFFu },  /* [ISID_0xfe02] */  /* [SID_0x31|SSID_0xff, /ActiveEcuC/vDam/vDamService_3101FE02] */
  { /*   173 */      0xFE0Eu,         0x0BFFu },  /* [ISID_0xfe0e] */  /* [SID_0x31|SSID_0xff, /ActiveEcuC/vDam/vDamService_3101FE0E] */
  { /*   174 */      0xFF00u,         0x038Fu },  /* [ISID_0xff00] */  /* [SID_0x31|SSID_0xff, /ActiveEcuC/vDam/vDamService_3101FF00] */
  { /*   175 */      0xFF01u,         0x038Fu },  /* [ISID_0xff01] */  /* [SID_0x31|SSID_0xff, /ActiveEcuC/vDam/vDamService_3101FF01] */
  { /*   176 */      0xFF03u,         0x0BFFu }   /* [ISID_0xff03] */  /* [SID_0x31|SSID_0xff, /ActiveEcuC/vDam/vDamService_3101FF03] */
};
#define VDAM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "vDam_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vDam_ServiceInfo
**********************************************************************************************************************/
/** 
  \var    vDam_ServiceInfo
  \brief  List of Services.
  \details
  Element                   Description
  ServiceRoles              Bit Mask for Roles which are allowed on this level.
  ServiceRolesValid         Determines if the Roles field has a valid value.
  ServiceId                 Id of the Service.
  SubServiceInfoEndIdx      the end index of the 0:n relation pointing to vDam_SubServiceInfo
  SubServiceInfoStartIdx    the start index of the 0:n relation pointing to vDam_SubServiceInfo
*/ 
#define VDAM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "vDam_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vDam_ServiceInfoType, VDAM_CONST) vDam_ServiceInfo[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ServiceRoles  ServiceRolesValid  ServiceId  SubServiceInfoEndIdx                       SubServiceInfoStartIdx                             Comment                Referable Keys */
  { /*     0 */      0x0000u,             FALSE,     0x10u,                                        1u,                                          0u },  /* [SID_0x10] */  /* [/ActiveEcuC/vDam/vDamService_1002] */
  { /*     1 */      0x0000u,             FALSE,     0x22u,                                        2u,                                          1u },  /* [SID_0x22] */  /* [/ActiveEcuC/vDam/vDamService_220103, /ActiveEcuC/vDam/vDamService_220107, /ActiveEcuC/vDam/vDamService_22102A, /ActiveEcuC/vDam/vDamService_222010, /ActiveEcuC/vDam/vDamService_222013, /ActiveEcuC/vDam/vDamService_22201A, /ActiveEcuC/vDam/vDamService_22201B, /ActiveEcuC/vDam/vDamService_22201F, /ActiveEcuC/vDam/vDamService_222032, /ActiveEcuC/vDam/vDamService_22292E, /ActiveEcuC/vDam/vDamService_222939, /ActiveEcuC/vDam/vDamService_222945, /ActiveEcuC/vDam/vDamService_222954, /ActiveEcuC/vDam/vDamService_225100, /ActiveEcuC/vDam/vDamService_225102, /ActiveEcuC/vDam/vDamService_225103, /ActiveEcuC/vDam/vDamService_225104, /ActiveEcuC/vDam/vDamService_225105, /ActiveEcuC/vDam/vDamService_225107, /ActiveEcuC/vDam/vDamService_225109, /ActiveEcuC/vDam/vDamService_225201, /ActiveEcuC/vDam/vDamService_225303, /ActiveEcuC/vDam/vDamService_225304, /ActiveEcuC/vDam/vDamService_225305, /ActiveEcuC/vDam/vDamService_22F10B, /ActiveEcuC/vDam/vDamService_22F10D, /ActiveEcuC/vDam/vDamService_22F111, /ActiveEcuC/vDam/vDamService_22F112, /ActiveEcuC/vDam/vDamService_22F122, /ActiveEcuC/vDam/vDamService_22F132, /ActiveEcuC/vDam/vDamService_22F133, /ActiveEcuC/vDam/vDamService_22F134, /ActiveEcuC/vDam/vDamService_22F154, /ActiveEcuC/vDam/vDamService_22F155, /ActiveEcuC/vDam/vDamService_22F180, /ActiveEcuC/vDam/vDamService_22F182, /ActiveEcuC/vDam/vDamService_22F181, /ActiveEcuC/vDam/vDamService_22F187, /ActiveEcuC/vDam/vDamService_22F188, /ActiveEcuC/vDam/vDamService_22F18A, /ActiveEcuC/vDam/vDamService_22F18B, /ActiveEcuC/vDam/vDamService_22F191, /ActiveEcuC/vDam/vDamService_22F192, /ActiveEcuC/vDam/vDamService_22F193, /ActiveEcuC/vDam/vDamService_22F194, /ActiveEcuC/vDam/vDamService_22F195, /ActiveEcuC/vDam/vDamService_22F1A0, /ActiveEcuC/vDam/vDamService_22F1A1, /ActiveEcuC/vDam/vDamService_22F1A2, /ActiveEcuC/vDam/vDamService_22F1B3, /ActiveEcuC/vDam/vDamService_22F1B4, /ActiveEcuC/vDam/vDamService_22F1B5, /ActiveEcuC/vDam/vDamService_22FD33, /ActiveEcuC/vDam/vDamService_220108, /ActiveEcuC/vDam/vDamService_221004, /ActiveEcuC/vDam/vDamService_221008, /ActiveEcuC/vDam/vDamService_221009, /ActiveEcuC/vDam/vDamService_22100B, /ActiveEcuC/vDam/vDamService_22100C, /ActiveEcuC/vDam/vDamService_22191D, /ActiveEcuC/vDam/vDamService_221921, /ActiveEcuC/vDam/vDamService_222001, /ActiveEcuC/vDam/vDamService_222002, /ActiveEcuC/vDam/vDamService_222008, /ActiveEcuC/vDam/vDamService_22200A, /ActiveEcuC/vDam/vDamService_22200B, /ActiveEcuC/vDam/vDamService_22200C, /ActiveEcuC/vDam/vDamService_22200D, /ActiveEcuC/vDam/vDamService_222026, /ActiveEcuC/vDam/vDamService_225300, /ActiveEcuC/vDam/vDamService_225301, /ActiveEcuC/vDam/vDamService_225302, /ActiveEcuC/vDam/vDamService_225500, /ActiveEcuC/vDam/vDamService_225501, /ActiveEcuC/vDam/vDamService_22F110, /ActiveEcuC/vDam/vDamService_22F186, /ActiveEcuC/vDam/vDamService_22F18C, /ActiveEcuC/vDam/vDamService_22F190, /ActiveEcuC/vDam/vDamService_22F1A6, /ActiveEcuC/vDam/vDamService_22F1B0, /ActiveEcuC/vDam/vDamService_22FD00, /ActiveEcuC/vDam/vDamService_22FD01, /ActiveEcuC/vDam/vDamService_22FD46, /ActiveEcuC/vDam/vDamService_22FD47, /ActiveEcuC/vDam/vDamService_22FD48, /ActiveEcuC/vDam/vDamService_22FD49, /ActiveEcuC/vDam/vDamService_22FD4A, /ActiveEcuC/vDam/vDamService_22FD38, /ActiveEcuC/vDam/vDamService_22FD17, /ActiveEcuC/vDam/vDamService_22FD13, /ActiveEcuC/vDam/vDamService_22FD08, /ActiveEcuC/vDam/vDamService_22FD0A, /ActiveEcuC/vDam/vDamService_22FD0D, /ActiveEcuC/vDam/vDamService_22FD0E, /ActiveEcuC/vDam/vDamService_22FD0F, /ActiveEcuC/vDam/vDamService_22FD14, /ActiveEcuC/vDam/vDamService_22FD15, /ActiveEcuC/vDam/vDamService_22FD16, /ActiveEcuC/vDam/vDamService_22FD1C, /ActiveEcuC/vDam/vDamService_22FD1E, /ActiveEcuC/vDam/vDamService_22FD20, /ActiveEcuC/vDam/vDamService_22FD28, /ActiveEcuC/vDam/vDamService_22FD29, /ActiveEcuC/vDam/vDamService_22FD2A, /ActiveEcuC/vDam/vDamService_22FD2B, /ActiveEcuC/vDam/vDamService_22FD2C, /ActiveEcuC/vDam/vDamService_22FD2D, /ActiveEcuC/vDam/vDamService_22FD2E, /ActiveEcuC/vDam/vDamService_22FD31, /ActiveEcuC/vDam/vDamService_22FD86, /ActiveEcuC/vDam/vDamService_22FD42, /ActiveEcuC/vDam/vDamService_224421, /ActiveEcuC/vDam/vDamService_224422, /ActiveEcuC/vDam/vDamService_224423, /ActiveEcuC/vDam/vDamService_224424, /ActiveEcuC/vDam/vDamService_224425, /ActiveEcuC/vDam/vDamService_224426, /ActiveEcuC/vDam/vDamService_224427, /ActiveEcuC/vDam/vDamService_224428, /ActiveEcuC/vDam/vDamService_224429, /ActiveEcuC/vDam/vDamService_22442A, /ActiveEcuC/vDam/vDamService_22442B, /ActiveEcuC/vDam/vDamService_22FD62, /ActiveEcuC/vDam/vDamService_22FD64, /ActiveEcuC/vDam/vDamService_22FDF0, /ActiveEcuC/vDam/vDamService_22FDF1, /ActiveEcuC/vDam/vDamService_22FDF2, /ActiveEcuC/vDam/vDamService_22442C, /ActiveEcuC/vDam/vDamService_224451, /ActiveEcuC/vDam/vDamService_22FD61, /ActiveEcuC/vDam/vDamService_22FD1D, /ActiveEcuC/vDam/vDamService_221002, /ActiveEcuC/vDam/vDamService_222003, /ActiveEcuC/vDam/vDamService_222030, /ActiveEcuC/vDam/vDamService_222031, /ActiveEcuC/vDam/vDamService_222957, /ActiveEcuC/vDam/vDamService_222958, /ActiveEcuC/vDam/vDamService_222959, /ActiveEcuC/vDam/vDamService_22295A, /ActiveEcuC/vDam/vDamService_22295E, /ActiveEcuC/vDam/vDamService_22295F, /ActiveEcuC/vDam/vDamService_22FD60, /ActiveEcuC/vDam/vDamService_22FD07, /ActiveEcuC/vDam/vDamService_22FD0C, /ActiveEcuC/vDam/vDamService_222024, /ActiveEcuC/vDam/vDamService_222951, /ActiveEcuC/vDam/vDamService_22FD43, /ActiveEcuC/vDam/vDamService_22FD44, /ActiveEcuC/vDam/vDamService_22FD74, /ActiveEcuC/vDam/vDamService_22295B, /ActiveEcuC/vDam/vDamService_22295C] */
  { /*     2 */      0x0000u,             FALSE,     0x2Eu,                                        3u,                                          2u },  /* [SID_0x2e] */  /* [/ActiveEcuC/vDam/vDamService_2E2023, /ActiveEcuC/vDam/vDamService_2EF184, /ActiveEcuC/vDam/vDamService_2EF185, /ActiveEcuC/vDam/vDamService_2E0107, /ActiveEcuC/vDam/vDamService_2E2945] */
  { /*     3 */      0x0000u,             FALSE,     0x2Fu,                                        5u,                                          3u },  /* [SID_0x2f] */  /* [/ActiveEcuC/vDam/vDamService_2F5001] */
  { /*     4 */      0x0BFFu,              TRUE,     0x31u,                                        6u,                                          5u },  /* [SID_0x31] */  /* [/ActiveEcuC/vDam/vDamService_31012000, /ActiveEcuC/vDam/vDamService_31012001, /ActiveEcuC/vDam/vDamService_31015000, /ActiveEcuC/vDam/vDamService_31015101, /ActiveEcuC/vDam/vDamService_31015200, /ActiveEcuC/vDam/vDamService_31015400, /ActiveEcuC/vDam/vDamService_31015401, /ActiveEcuC/vDam/vDamService_3101D001, /ActiveEcuC/vDam/vDamService_3101D002, /ActiveEcuC/vDam/vDamService_3101D003, /ActiveEcuC/vDam/vDamService_3101F000, /ActiveEcuC/vDam/vDamService_3101FF00, /ActiveEcuC/vDam/vDamService_3101FF01, /ActiveEcuC/vDam/vDamService_3101FE0E, /ActiveEcuC/vDam/vDamService_31011000, /ActiveEcuC/vDam/vDamService_31013000, /ActiveEcuC/vDam/vDamService_3101FE01, /ActiveEcuC/vDam/vDamService_3101FE02, /ActiveEcuC/vDam/vDamService_3101FE0B, /ActiveEcuC/vDam/vDamService_3101FE12, /ActiveEcuC/vDam/vDamService_3101FF03] */
  { /*     5 */      0x078Fu,              TRUE,     0x34u, VDAM_NO_SUBSERVICEINFOENDIDXOFSERVICEINFO, VDAM_NO_SUBSERVICEINFOSTARTIDXOFSERVICEINFO },  /* [SID_0x34] */  /* [/ActiveEcuC/vDam/vDamService_34] */
  { /*     6 */      0x078Fu,              TRUE,     0x36u, VDAM_NO_SUBSERVICEINFOENDIDXOFSERVICEINFO, VDAM_NO_SUBSERVICEINFOSTARTIDXOFSERVICEINFO },  /* [SID_0x36] */  /* [/ActiveEcuC/vDam/vDamService_36] */
  { /*     7 */      0x078Fu,              TRUE,     0x37u, VDAM_NO_SUBSERVICEINFOENDIDXOFSERVICEINFO, VDAM_NO_SUBSERVICEINFOSTARTIDXOFSERVICEINFO }   /* [SID_0x37] */  /* [/ActiveEcuC/vDam/vDamService_37] */
};
#define VDAM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "vDam_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vDam_SubServiceInfo
**********************************************************************************************************************/
/** 
  \var    vDam_SubServiceInfo
  \brief  List of Sub-Services.
  \details
  Element                   Description
  SubServiceRoles           Bit Mask for Roles which are allowed on this level.
  SubServiceRolesValid      Determines if the Roles field has a valid value.
  IdentifierInfoEndIdx      the end index of the 0:n relation pointing to vDam_IdentifierInfo
  IdentifierInfoStartIdx    the start index of the 0:n relation pointing to vDam_IdentifierInfo
  SubServiceId              Id of the Sub-Service.
*/ 
#define VDAM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "vDam_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vDam_SubServiceInfoType, VDAM_CONST) vDam_SubServiceInfo[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    SubServiceRoles  SubServiceRolesValid  IdentifierInfoEndIdx                          IdentifierInfoStartIdx                          SubServiceId        Comment                 Referable Keys */
  { /*     0 */         0x078Fu,                 TRUE, VDAM_NO_IDENTIFIERINFOENDIDXOFSUBSERVICEINFO, VDAM_NO_IDENTIFIERINFOSTARTIDXOFSUBSERVICEINFO,        0x02u },  /* [SSID_0x2]  */  /* [SID_0x10, /ActiveEcuC/vDam/vDamService_1002] */
  { /*     1 */         0x0000u,                FALSE,                                         151u,                                             0u,        0xFFu },  /* [SSID_0xff] */  /* [SID_0x22, /ActiveEcuC/vDam/vDamService_220103, /ActiveEcuC/vDam/vDamService_220107, /ActiveEcuC/vDam/vDamService_22102A, /ActiveEcuC/vDam/vDamService_222010, /ActiveEcuC/vDam/vDamService_222013, /ActiveEcuC/vDam/vDamService_22201A, /ActiveEcuC/vDam/vDamService_22201B, /ActiveEcuC/vDam/vDamService_22201F, /ActiveEcuC/vDam/vDamService_222032, /ActiveEcuC/vDam/vDamService_22292E, /ActiveEcuC/vDam/vDamService_222939, /ActiveEcuC/vDam/vDamService_222945, /ActiveEcuC/vDam/vDamService_222954, /ActiveEcuC/vDam/vDamService_225100, /ActiveEcuC/vDam/vDamService_225102, /ActiveEcuC/vDam/vDamService_225103, /ActiveEcuC/vDam/vDamService_225104, /ActiveEcuC/vDam/vDamService_225105, /ActiveEcuC/vDam/vDamService_225107, /ActiveEcuC/vDam/vDamService_225109, /ActiveEcuC/vDam/vDamService_225201, /ActiveEcuC/vDam/vDamService_225303, /ActiveEcuC/vDam/vDamService_225304, /ActiveEcuC/vDam/vDamService_225305, /ActiveEcuC/vDam/vDamService_22F10B, /ActiveEcuC/vDam/vDamService_22F10D, /ActiveEcuC/vDam/vDamService_22F111, /ActiveEcuC/vDam/vDamService_22F112, /ActiveEcuC/vDam/vDamService_22F122, /ActiveEcuC/vDam/vDamService_22F132, /ActiveEcuC/vDam/vDamService_22F133, /ActiveEcuC/vDam/vDamService_22F134, /ActiveEcuC/vDam/vDamService_22F154, /ActiveEcuC/vDam/vDamService_22F155, /ActiveEcuC/vDam/vDamService_22F180, /ActiveEcuC/vDam/vDamService_22F182, /ActiveEcuC/vDam/vDamService_22F181, /ActiveEcuC/vDam/vDamService_22F187, /ActiveEcuC/vDam/vDamService_22F188, /ActiveEcuC/vDam/vDamService_22F18A, /ActiveEcuC/vDam/vDamService_22F18B, /ActiveEcuC/vDam/vDamService_22F191, /ActiveEcuC/vDam/vDamService_22F192, /ActiveEcuC/vDam/vDamService_22F193, /ActiveEcuC/vDam/vDamService_22F194, /ActiveEcuC/vDam/vDamService_22F195, /ActiveEcuC/vDam/vDamService_22F1A0, /ActiveEcuC/vDam/vDamService_22F1A1, /ActiveEcuC/vDam/vDamService_22F1A2, /ActiveEcuC/vDam/vDamService_22F1B3, /ActiveEcuC/vDam/vDamService_22F1B4, /ActiveEcuC/vDam/vDamService_22F1B5, /ActiveEcuC/vDam/vDamService_22FD33, /ActiveEcuC/vDam/vDamService_220108, /ActiveEcuC/vDam/vDamService_221004, /ActiveEcuC/vDam/vDamService_221008, /ActiveEcuC/vDam/vDamService_221009, /ActiveEcuC/vDam/vDamService_22100B, /ActiveEcuC/vDam/vDamService_22100C, /ActiveEcuC/vDam/vDamService_22191D, /ActiveEcuC/vDam/vDamService_221921, /ActiveEcuC/vDam/vDamService_222001, /ActiveEcuC/vDam/vDamService_222002, /ActiveEcuC/vDam/vDamService_222008, /ActiveEcuC/vDam/vDamService_22200A, /ActiveEcuC/vDam/vDamService_22200B, /ActiveEcuC/vDam/vDamService_22200C, /ActiveEcuC/vDam/vDamService_22200D, /ActiveEcuC/vDam/vDamService_222026, /ActiveEcuC/vDam/vDamService_225300, /ActiveEcuC/vDam/vDamService_225301, /ActiveEcuC/vDam/vDamService_225302, /ActiveEcuC/vDam/vDamService_225500, /ActiveEcuC/vDam/vDamService_225501, /ActiveEcuC/vDam/vDamService_22F110, /ActiveEcuC/vDam/vDamService_22F186, /ActiveEcuC/vDam/vDamService_22F18C, /ActiveEcuC/vDam/vDamService_22F190, /ActiveEcuC/vDam/vDamService_22F1A6, /ActiveEcuC/vDam/vDamService_22F1B0, /ActiveEcuC/vDam/vDamService_22FD00, /ActiveEcuC/vDam/vDamService_22FD01, /ActiveEcuC/vDam/vDamService_22FD46, /ActiveEcuC/vDam/vDamService_22FD47, /ActiveEcuC/vDam/vDamService_22FD48, /ActiveEcuC/vDam/vDamService_22FD49, /ActiveEcuC/vDam/vDamService_22FD4A, /ActiveEcuC/vDam/vDamService_22FD38, /ActiveEcuC/vDam/vDamService_22FD17, /ActiveEcuC/vDam/vDamService_22FD13, /ActiveEcuC/vDam/vDamService_22FD08, /ActiveEcuC/vDam/vDamService_22FD0A, /ActiveEcuC/vDam/vDamService_22FD0D, /ActiveEcuC/vDam/vDamService_22FD0E, /ActiveEcuC/vDam/vDamService_22FD0F, /ActiveEcuC/vDam/vDamService_22FD14, /ActiveEcuC/vDam/vDamService_22FD15, /ActiveEcuC/vDam/vDamService_22FD16, /ActiveEcuC/vDam/vDamService_22FD1C, /ActiveEcuC/vDam/vDamService_22FD1E, /ActiveEcuC/vDam/vDamService_22FD20, /ActiveEcuC/vDam/vDamService_22FD28, /ActiveEcuC/vDam/vDamService_22FD29, /ActiveEcuC/vDam/vDamService_22FD2A, /ActiveEcuC/vDam/vDamService_22FD2B, /ActiveEcuC/vDam/vDamService_22FD2C, /ActiveEcuC/vDam/vDamService_22FD2D, /ActiveEcuC/vDam/vDamService_22FD2E, /ActiveEcuC/vDam/vDamService_22FD31, /ActiveEcuC/vDam/vDamService_22FD86, /ActiveEcuC/vDam/vDamService_22FD42, /ActiveEcuC/vDam/vDamService_224421, /ActiveEcuC/vDam/vDamService_224422, /ActiveEcuC/vDam/vDamService_224423, /ActiveEcuC/vDam/vDamService_224424, /ActiveEcuC/vDam/vDamService_224425, /ActiveEcuC/vDam/vDamService_224426, /ActiveEcuC/vDam/vDamService_224427, /ActiveEcuC/vDam/vDamService_224428, /ActiveEcuC/vDam/vDamService_224429, /ActiveEcuC/vDam/vDamService_22442A, /ActiveEcuC/vDam/vDamService_22442B, /ActiveEcuC/vDam/vDamService_22FD62, /ActiveEcuC/vDam/vDamService_22FD64, /ActiveEcuC/vDam/vDamService_22FDF0, /ActiveEcuC/vDam/vDamService_22FDF1, /ActiveEcuC/vDam/vDamService_22FDF2, /ActiveEcuC/vDam/vDamService_22442C, /ActiveEcuC/vDam/vDamService_224451, /ActiveEcuC/vDam/vDamService_22FD61, /ActiveEcuC/vDam/vDamService_22FD1D, /ActiveEcuC/vDam/vDamService_221002, /ActiveEcuC/vDam/vDamService_222003, /ActiveEcuC/vDam/vDamService_222030, /ActiveEcuC/vDam/vDamService_222031, /ActiveEcuC/vDam/vDamService_222957, /ActiveEcuC/vDam/vDamService_222958, /ActiveEcuC/vDam/vDamService_222959, /ActiveEcuC/vDam/vDamService_22295A, /ActiveEcuC/vDam/vDamService_22295E, /ActiveEcuC/vDam/vDamService_22295F, /ActiveEcuC/vDam/vDamService_22FD60, /ActiveEcuC/vDam/vDamService_22FD07, /ActiveEcuC/vDam/vDamService_22FD0C, /ActiveEcuC/vDam/vDamService_222024, /ActiveEcuC/vDam/vDamService_222951, /ActiveEcuC/vDam/vDamService_22FD43, /ActiveEcuC/vDam/vDamService_22FD44, /ActiveEcuC/vDam/vDamService_22FD74, /ActiveEcuC/vDam/vDamService_22295B, /ActiveEcuC/vDam/vDamService_22295C] */
  { /*     2 */         0x0000u,                FALSE,                                         156u,                                           151u,        0xFFu },  /* [SSID_0xff] */  /* [SID_0x2e, /ActiveEcuC/vDam/vDamService_2E2023, /ActiveEcuC/vDam/vDamService_2EF184, /ActiveEcuC/vDam/vDamService_2EF185, /ActiveEcuC/vDam/vDamService_2E0107, /ActiveEcuC/vDam/vDamService_2E2945] */
  { /*     3 */         0x0000u,                FALSE,                                         157u,                                           156u,        0x00u },  /* [SSID_0x0]  */  /* [SID_0x2f, /ActiveEcuC/vDam/vDamService_2F5001] */
  { /*     4 */         0x0000u,                FALSE,                                         158u,                                           157u,        0x03u },  /* [SSID_0x3]  */  /* [SID_0x2f, /ActiveEcuC/vDam/vDamService_2F5001] */
  { /*     5 */         0x0000u,                FALSE,                                         177u,                                           158u,        0xFFu }   /* [SSID_0xff] */  /* [SID_0x31, /ActiveEcuC/vDam/vDamService_31012000, /ActiveEcuC/vDam/vDamService_31012001, /ActiveEcuC/vDam/vDamService_31015000, /ActiveEcuC/vDam/vDamService_31015101, /ActiveEcuC/vDam/vDamService_31015200, /ActiveEcuC/vDam/vDamService_31015400, /ActiveEcuC/vDam/vDamService_31015401, /ActiveEcuC/vDam/vDamService_3101D001, /ActiveEcuC/vDam/vDamService_3101D002, /ActiveEcuC/vDam/vDamService_3101D003, /ActiveEcuC/vDam/vDamService_3101F000, /ActiveEcuC/vDam/vDamService_3101FF00, /ActiveEcuC/vDam/vDamService_3101FF01, /ActiveEcuC/vDam/vDamService_3101FE0E, /ActiveEcuC/vDam/vDamService_31011000, /ActiveEcuC/vDam/vDamService_31013000, /ActiveEcuC/vDam/vDamService_3101FE01, /ActiveEcuC/vDam/vDamService_3101FE02, /ActiveEcuC/vDam/vDamService_3101FF03] */
};
#define VDAM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "vDam_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/



 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  END OF FILE: vDam_Cfg.c
 *********************************************************************************************************************/
