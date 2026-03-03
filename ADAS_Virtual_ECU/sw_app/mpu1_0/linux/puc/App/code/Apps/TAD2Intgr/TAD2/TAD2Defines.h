//--------------------------------------------------------------------------
/// @file TAD2Defines.h
/// @brief Contains the definition of Macros for TAD2 algorithm.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Pravin Pawar (pravin.pawar@magna.com)
//  --------------------------------------------------------------------------

#ifndef TAD2_DEFINES_H_
#define TAD2_DEFINES_H_

#define TAD2_SIGM_TESTING      		  1
#define TAD2_NVM_ACCESS_ENABLED		  1
#define ENABLE_TAD2_THREAD			    1

#define READ_VARIANT_ID             0
#define TAD2_DEBUG_PRINTS      		  0
#define PROFILE_TAD2           		  0
#define DUMP_ALGO_VIEW_FOR_STATE7  	0
#if (TAD2_SIGM_TESTING)
#define DUMP_ALGO_VIEW		  				0
#define DUMP_REAR_FISHEYE_ALGO_VIEW	0 // When this flag is enabled, disable THA execution as
											// it uses same algo view and hence crashes
#endif
#define UART_PRINT_TAD2_OUTPUT 		0
#define DUMP_TRSC_CALIB_ON_SD_CARD	0
#define DUMP_TRAILER_IMAGE			0
#define DUMP_FISHEYE_1920x1280		0
#define DUMP_TRACKING_LOST_PARAMS	0
#define DUMP_TRAILER_TEMPLATE_FROM_SCANNING  0
#define TAD2_HARDCODING_FOR_TEST	0
#define DEBUG_HITCH_POINT			0
#define NVM_SANITY_TEST             0
#define PRINT_ALGO_VIEW_DEBUG_DATA  0
#define PRINT_CALIBRATED_TRAILER_COUNT  0


#endif // TAD2_DEFINES_H_
