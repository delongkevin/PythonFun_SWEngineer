/*
 * File: TeVBII_e_EssEngState.h
 */

#ifndef RTW_HEADER_TeVBII_e_EssEngState_h_
#define RTW_HEADER_TeVBII_e_EssEngState_h_

typedef enum {
  TeVBII_e_EssEngState_ENS_STOPPED = 1,/* Default value */
  TeVBII_e_EssEngState_ENS_RQ_ST = 2,
  TeVBII_e_EssEngState_ENS_RUN = 3,
  TeVBII_e_EssEngState_ENS_STOP_PEND = 4,
  TeVBII_e_EssEngState_ENS_ST_PRTCT = 5,
  TeVBII_e_EssEngState_ENS_ST_INH = 6,
  TeVBII_e_EssEngState_ENS_DSBL = 7,
  TeVBII_e_EssEngState_ENS_IHB_LATCH = 8,
  TeVBII_e_EssEngState_ENS_Starting = 9,
  TeVBII_e_EssEngState_SNA = 15,
  TeVBII_e_EssEngState_Dummy = 2147483647
} TeVBII_e_EssEngState;

#endif                                 /* RTW_HEADER_TeVBII_e_EssEngState_h_ */
