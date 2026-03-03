/*
 * File: TeVBII_e_VehEPBSts.h
 */

#ifndef RTW_HEADER_TeVBII_e_VehEPBSts_h_
#define RTW_HEADER_TeVBII_e_VehEPBSts_h_

typedef enum {
  TeVBII_e_VehEPBSts_Released = 0,     /* Default value */
  TeVBII_e_VehEPBSts_Applied = 1,
  TeVBII_e_VehEPBSts_DynamicBrkESC = 2,
  TeVBII_e_VehEPBSts_DynamicBrkEPB = 3,
  TeVBII_e_VehEPBSts_Emergency_Braking = 4,
  TeVBII_e_VehEPBSts_Applying = 5,
  TeVBII_e_VehEPBSts_Maintenance_Mode = 6,
  TeVBII_e_VehEPBSts_Assembly_Check = 7,
  TeVBII_e_VehEPBSts_Inspection_Mode = 8,
  TeVBII_e_VehEPBSts_Re_Clamping = 9,
  TeVBII_e_VehEPBSts_Adjust_Mode = 10,
  TeVBII_e_VehEPBSts_Releasing = 11,
  TeVBII_e_VehEPBSts_Fault_EPB_Released = 12,
  TeVBII_e_VehEPBSts_Fault_EPB_Applied = 13,
  TeVBII_e_VehEPBSts_Fault_Present = 14,
  TeVBII_e_VehEPBSts_SNA = 15,
  TeVBII_e_VehEPBSts_Dummy = 2147483647
} TeVBII_e_VehEPBSts;

#endif                                 /* RTW_HEADER_TeVBII_e_VehEPBSts_h_ */
