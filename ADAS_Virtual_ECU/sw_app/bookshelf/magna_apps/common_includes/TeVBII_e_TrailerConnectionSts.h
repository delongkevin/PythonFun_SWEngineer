/*
 * File: TeVBII_e_TrailerConnectionSts.h
 */

#ifndef RTW_HEADER_TeVBII_e_TrailerConnectionSts_h_
#define RTW_HEADER_TeVBII_e_TrailerConnectionSts_h_

typedef enum {
  TeVBII_e_TrailerConnectionSts_NotConnected = 0,/* Default value */
  TeVBII_e_TrailerConnectionSts_Connected = 1,
  TeVBII_e_TrailerConnectionSts_NotUsed = 2,
  TeVBII_e_TrailerConnectionSts_SNA = 3,
  TeVBII_e_TrailerConnectionSts_Dummy = 2147483647
} TeVBII_e_TrailerConnectionSts;

#endif                         /* RTW_HEADER_TeVBII_e_TrailerConnectionSts_h_ */
