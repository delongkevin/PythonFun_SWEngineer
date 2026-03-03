/*
 * File: TeVBII_e_EngineSts.h
 */

#ifndef RTW_HEADER_TeVBII_e_EngineSts_h_
#define RTW_HEADER_TeVBII_e_EngineSts_h_

typedef enum {
  TeVBII_e_EngineSts_Engine_Off = 0,       /* Default value */
  TeVBII_e_EngineSts_Engine_Cranking = 1,
  TeVBII_e_EngineSts_Engine_On = 2,
  TeVBII_e_EngineSts_SNA = 3,
  TeVBII_e_EngineSts_Dummy = 2147483647
} TeVBII_e_EngineSts;

#endif                                 /* RTW_HEADER_TeVBII_e_EngineSts_h_ */
