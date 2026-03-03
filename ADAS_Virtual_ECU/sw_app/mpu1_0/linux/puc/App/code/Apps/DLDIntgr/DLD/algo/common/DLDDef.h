/// --------------------------------------------------------------------------
/// @file DLDDefs.h
/// @brief Contains common enum, structure definitions
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Kirti Balani (kirti.balani@magna.com)
/// @author Jignesh Vasoya (jignesh.vasoya@magna.com)
/// --------------------------------------------------------------------------

#ifndef DLD_DEFS_H
#define DLD_DEFS_H
#include <string.h>

#define DLD_TRACE_LOW             1
#define DLD_TRACE_MID             2
#define DLD_TRACE_HIGH            3
#define DLD_TRACE_NONE            4

/* Enable this to print debug data */
#define DLD_DEBUG_TRACE_LEVEL 	  DLD_TRACE_HIGH
#define ENABLE_DLD_DEBUG_PRINT 	  0
#define ENABLE_DLD_DEBUG_DUMP     0
#define ENABLE_DLD_OFFLINE_TEST   0
#define ENABLE_DLD_THREAD         1
#define ENABLE_DLD_PROFILE        0
#define ENABLE_DLD_CHMSL_CAMERA	  0
#define DLD_GRID_ALGO

#define DLD_INPUT_WIDTH           320
#define DLD_INPUT_HEIGHT          320
#define DLD_INPUT_CHANNELS        3
#ifdef DLD_GRID_ALGO
  #define DLD_OUTPUT_OCC_WIDTH      9
  #define DLD_OUTPUT_LUM_WIDTH      9
#else
  #define DLD_OUTPUT_OCC_WIDTH      6
  #define DLD_OUTPUT_LUM_WIDTH      2
#endif
#define DLD_OUTPUT_OCC_ID	      0
#define DLD_OUTPUT_LUM_ID	      1

#if ENABLE_DLD_DEBUG_PRINT
  #define DLD_DEBUG_PRINT(level, ...) \
	if(level >= DLD_DEBUG_TRACE_LEVEL) { \
  	  ME_Debugger_F_Printf_v (__VA_ARGS__); \
	}
#else
  #define DLD_DEBUG_PRINT(...)
#endif

#define DLD_DEBUG_PRINT_ERROR(...)  {\
	ME_Debugger_F_Printf_v("[DLD Error] ");\
	ME_Debugger_F_Printf_v(__VA_ARGS__);\
	ME_Debugger_F_Printf_v("\n");\
	ME_Debugger_F_Printf_v("in <%s> line <%d>\n", __FILE__, __LINE__);\
  }

enum DLD_Camera_ID
{
  DLD_Rear = 0,
  DLD_Front,
  DLD_Left,
  DLD_Right,
#if ENABLE_DLD_CHMSL_CAMERA
  DLD_Chmsl,
#endif
  DLD_NUM_CAMS
};

// struct KMData_s
// {
// 	float32_t dx_m_f32;
// 	float32_t dy_m_f32;
// 	float32_t dyaw_rad_f32;
// 	float32_t timestamp_s_f32;
// };
//struct occlusion_percentage_bins
//{
//	float zero;
//	float twelve_point_five;
//	float twenty_five;
//	float fifty;
//	float seventy_five;
//	float hundred;
//};
//
//struct binary_occlusion_bins
//{
//	float unoccluded;
//	float occluded;
//};
//
//struct lighting_classification_bins
//{
//	float highlight;
//	float lowlight;
//};
//
//struct binary_lighting_bins
//{
//	float highlight;
//	float lowlight;
//};
//
//struct backlight_classification_bins
//{
//	float backlight_off;
//	float backlight_small;
//	float backlight_large;
//};
//
//struct binary_backlight_bins
//{
//	float backlight_off;
//	float backlight_on;
//};

// struct modelParameters
// {
// 	//DLDLogger* m_pDLDLogger = nullptr;
// 	//std::string m_ModelProfile;
// 	uint32_t m_Width;
// 	uint32_t m_Height;
// 	uint32_t m_Channels;
// 	uint32_t m_CombineOutputs;
// 	uint32_t m_smoothenOutputs;
// };

#endif
