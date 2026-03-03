/*
 * File: TeVBII_e_CmdIgnSts.h
 */

#ifndef RTW_HEADER_TeVBII_e_CmdIgnSts_h_
#define RTW_HEADER_TeVBII_e_CmdIgnSts_h_

typedef enum {
  TeVBII_e_CmdIgnSts_Initialization = 0,/* Default value */
  TeVBII_e_CmdIgnSts_IGN_LK = 1,
  TeVBII_e_CmdIgnSts_ACC = 3,
  TeVBII_e_CmdIgnSts_RUN = 4,
  TeVBII_e_CmdIgnSts_START = 5,
  TeVBII_e_CmdIgnSts_SNA = 7,
  TeVBII_e_CmdIgnSts_Dummy = 2147483647
} TeVBII_e_CmdIgnSts;

#endif                                 /* RTW_HEADER_TeVBII_e_CmdIgnSts_h_ */
