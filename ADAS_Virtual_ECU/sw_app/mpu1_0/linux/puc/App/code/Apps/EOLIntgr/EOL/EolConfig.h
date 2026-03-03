#ifndef EOLCONFIG_H_
#define EOLCONFIG_H_
#include "mecl/core/MeclTypes.h"
namespace eol
{

const uint32_t  LOGIVIEW_OUTPUT_SIZE_X = 2048U;
const uint32_t  LOGIVIEW_OUTPUT_SIZE_Y = 2048U;
const float64_t LTARGET_DETECTION_ZOOM_FACTOR = 2.0;
const uint8_t   LCALI_MAX_QUALITY_ISSUE_LIMIT = 2U;
const float32_t MAXDEVIATIONLOC     = 80.0F; //threshold changed from 8.5F*25.4F millimeters to 80mm
const float32_t MAXDEVIATIONANGLE   = 7.0F;

const float64_t 	RATIOMM2PXX = 20.0;
const float64_t 	RATIOMM2PXY = 20.0;
const float64_t 	ORIGINALX	= 512.0;
const float64_t 	ORIGINALY	= 512.0;


}
#endif /* EOLCONFIG_H_ */
