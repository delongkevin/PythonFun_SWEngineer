/*
 * File: TeVBII_e_TchScrSts.h
 */

#ifndef RTW_HEADER_TeVBII_e_TchScrSts_h_
#define RTW_HEADER_TeVBII_e_TchScrSts_h_

typedef enum {
  TeVBII_e_TchScrSts_TCH_NOT_PSD = 0,    /* Default value */
  TeVBII_e_TchScrSts_TchPSD = 1,
  TeVBII_e_TchScrSts_TchPSCan = 2,
  TeVBII_e_TchScrSts_NotUsed = 3,
  TeVBII_e_TchScrSts_TchCfgRes = 4,
  TeVBII_e_TchScrSts_TchCfgOfst = 5,
  TeVBII_e_TchScrSts_TchCfgMax = 6,
  TeVBII_e_TchScrSts_SNA = 7,
  TeVBII_e_TchScrSts_Dummy = 2147483647
} TeVBII_e_TchScrSts;

#endif                                 /* RTW_HEADER_TeVBII_e_TchScrSts_h_ */
