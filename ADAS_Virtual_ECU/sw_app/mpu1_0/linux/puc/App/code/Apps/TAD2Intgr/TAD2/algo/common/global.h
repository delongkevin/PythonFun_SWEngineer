//--------------------------------------------------------------------------
/// @file Global.h
//--------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author HAROLD JOSEPH (harold.joseph@magna.com)
///
//--------------------------------------------------------------------------
#ifndef _GLOBAL_H
#define _GLOBAL_H

#include "stdtad.h"

class CTADImpl;

namespace global
{
    struct Globals
    {
        char vidName[260];
        char vidPath[260];
    };

    void init( CTADImpl* i_pTADImpl );
    void uninit();
    void reset();

    const char* getVidName();
    const char* getVidPath();
    uint32_t getFrameNum();
    float32_t getGroundTruth();
}

#endif // !__GLOBAL__H_
