/*
 * File: TeVBII_e_TrlrPrsntSts.h
 */

#ifndef RTW_HEADER_TeVBII_e_TrlrPrsntSts_h_
#define RTW_HEADER_TeVBII_e_TrlrPrsntSts_h_

typedef enum {
  TeVBII_e_TrlrPrsntSts_NO_TRLR = 0,   /* Default value */
  TeVBII_e_TrlrPrsntSts_TRLR_PRSNT = 1,
  TeVBII_e_TrlrPrsntSts_TRLR_DCONN = 2,
  TeVBII_e_TrlrPrsntSts_SNA = 3,
  TeVBII_e_TrlrPrsntSts_Dummy = 2147483647
} TeVBII_e_TrlrPrsntSts;

#endif                                 /* RTW_HEADER_TeVBII_e_TrlrPrsntSts_h_ */
