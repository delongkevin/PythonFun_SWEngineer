// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [03-Apr-2019]
// --- Last Modified by Joshua Teichroeb [03-Apr-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __QNX__
#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "global.h"
#include "TADImpl.h"

extern class CAppCtrlInfo* g__pAppCtrl;
class CTADImpl* g__pTADImpl = NULL;
struct global::Globals* g__pGlobals = NULL;

void global::init( class CTADImpl* i_pTADImpl )
{
    g__pTADImpl = i_pTADImpl;

    if( g__pGlobals == NULL )
    {
        g__pGlobals = new Globals();
        g__pGlobals->vidName[0] = '\0';
        g__pGlobals->vidPath[0] = '\0';
    }
}

void global::uninit()
{
    if( g__pGlobals )
    {
        delete g__pGlobals;
        g__pGlobals = NULL;
    }
}

void global::reset()
{
    g__pGlobals->vidName[0] = '\0';
    g__pGlobals->vidPath[0] = '\0';
}

const char* global::getVidName()
{
    if( strlen( g__pGlobals->vidName ) == 0 )
    {
        char* ptr1 = strrchr( g__pAppCtrl->m_VideoName, '\\' );
        char* ptr2 = strrchr( g__pAppCtrl->m_VideoName, '.' );
        strncpy_s( g__pGlobals->vidName, ptr1 + 1, ptr2 - ptr1 );
    }

    return g__pGlobals->vidName;
}

const char* global::getVidPath()
{
    if( strlen( g__pGlobals->vidPath ) == 0 )
    {
        char* ptr1 = &g__pAppCtrl->m_VideoName[0];
        char* ptr2 = strrchr( g__pAppCtrl->m_VideoName, '\\' );
        strncpy_s( g__pGlobals->vidPath, ptr1, ptr2 - ptr1 );
    }

    return g__pGlobals->vidPath;
}

uint32_t global::getFrameNum()
{
    return ( uint32_t )g__pAppCtrl->m_FrameNumber;
}

float32_t global::getGroundTruth()
{
    return g__pTADImpl->GetGroundTruth( g__pAppCtrl->m_FrameNumber );
}
#endif //_WINDOWS_

