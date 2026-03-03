// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [08-Feb-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __WARP_LUT__H_
#define __WARP_LUT__H_

#include "TADStructures.h"

namespace TAD2
{
    /* Functions to get the LUTs used to warp the topview. */

    sint16_t* getWarpXLUT();
    sint16_t* getWarpYLUT();
    int32_t warpLookupXOffset( uint32_t x, uint32_t y );
    int32_t warpLookupYOffset( uint32_t x, uint32_t y );
    TAD2::WarpedTopViewParameters getWarpedTopViewParams();
}

#endif // !__WARP_LUT__H_
