#ifndef SIGNALMGR_TYPES_H_INCGUARD
#define SIGNALMGR_TYPES_H_INCGUARD

#include "SignalMgr.cfg"
#include "PlatformDataTypes.h"




typedef struct
{
	uint64_t LastUpdatedTimeStamp;
	uint32_t FreshnessCount;	
}SignalMgr_MetaData;





#if SIGMGR_PLATFORMTYPES == USE_SIGMGR_PLATFORMTYPEDEFS

#ifndef TRUE
	#define TRUE  1
	#define FALSE 0
#endif

	//typedef unsigned char bool_t;
	//typedef unsigned char uint8_t;
	//typedef unsigned short uint16_t;

#endif


#endif
