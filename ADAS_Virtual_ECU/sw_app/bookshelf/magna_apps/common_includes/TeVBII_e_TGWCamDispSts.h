/*
 * File: TeVBII_e_TGWCamDispSts.h
 */

#ifndef RTW_HEADER_TeVBII_e_TGWCamDispSts_h_
#define RTW_HEADER_TeVBII_e_TGWCamDispSts_h_

typedef enum {
  TeVBII_e_TGWCamDispSts_DISP_NON_CAMERA = 0,/* Default value */
  TeVBII_e_TGWCamDispSts_DISP_DIGITAL_RVC_CAMERA = 1,
  TeVBII_e_TGWCamDispSts_DISP_ANALOG_RVC_CAMERA = 2,
  TeVBII_e_TGWCamDispSts_DISP_ANALOG_CHMSL_CAMERA = 3,
  TeVBII_e_TGWCamDispSts_DISP_SURROUND_VIEW_CAMERA = 4,
  TeVBII_e_TGWCamDispSts_DISP_TRAILER_CAMERA = 5,
  TeVBII_e_TGWCamDispSts_DISP_WIRLESS_CAMERA = 6,
  TeVBII_e_TGWCamDispSts_DISP_SVS_MORECAMS_POPUP = 7,
  TeVBII_e_TGWCamDispSts_DISP_INTERIOR_CAMERA = 8,
  TeVBII_e_TGWCamDispSts_SNA = 15,
  TeVBII_e_TGWCamDispSts_Dummy = 2147483647
} TeVBII_e_TGWCamDispSts;

#endif                                /* RTW_HEADER_TeVBII_e_TGWCamDispSts_h_ */
