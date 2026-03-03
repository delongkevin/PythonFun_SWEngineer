/*
 * File: TeVBII_e_VehAscmSts.h
 */

#ifndef RTW_HEADER_TeVBII_e_VehAscmSts_h_
#define RTW_HEADER_TeVBII_e_VehAscmSts_h_

typedef enum {
  TeVBII_e_VehAscmSts_NONE = 0,        /* Default value */
  TeVBII_e_VehAscmSts_DUMP = 1,
  TeVBII_e_VehAscmSts_PARK = 2,
  TeVBII_e_VehAscmSts_AERO = 3,
  TeVBII_e_VehAscmSts_NVL = 4,
  TeVBII_e_VehAscmSts_ORL = 5,
  TeVBII_e_VehAscmSts_ORL2 = 6,
  TeVBII_e_VehAscmSts_Lifter = 7,
  TeVBII_e_VehAscmSts_RAISE = 8,
  TeVBII_e_VehAscmSts_LOWER = 9,
  TeVBII_e_VehAscmSts_SYSFAIL = 10,
  TeVBII_e_VehAscmSts_SRVS = 11,
  TeVBII_e_VehAscmSts_AERO2 = 12,
  TeVBII_e_VehAscmSts_SNA = 15,
  TeVBII_e_VehAscmSts_Dummy = 2147483647
} TeVBII_e_VehAscmSts;

#endif                                 /* RTW_HEADER_TeVBII_e_VehAscmSts_h_ */
