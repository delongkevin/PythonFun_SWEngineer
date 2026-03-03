//--------------------------------------------------------------------------
/// @file LogCtxTAD.h
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// Created on: 08.12.2015
///
/// @author Roman Berngardt (Roman.Berngardt@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef LOGCTXPD_H_
#define LOGCTXPD_H_

#include "logging/LogProvider.h"

namespace pd
{
    class LogCtxPD
    {
    public:
        static void registerCtxId_v()
        {
            logging::LogProvider v_Lp_o;
            v_Lp_o.registerCtxId_v( c_LogCtxPD_u32 );
            v_Lp_o.registerCtxId_v( c_LogCtxPDEval_u32 );
            v_Lp_o.registerCtxId_v( c_LogCtxPDEvalAcquisition_u32 );
            v_Lp_o.registerCtxId_v( c_LogCtxPDEvalTracking_u32 );
        }

        static const uint32_t c_LogCtxPD_u32 = 0x10000U;
        static const uint32_t c_LogCtxPDEval_u32 = 0x10060U;
        static const uint32_t c_LogCtxPDEvalAcquisition_u32 = 0x10061U;
        static const uint32_t c_LogCtxPDEvalTracking_u32 = 0x10062U;
    };
} // namespace pd

#endif // LOGCTXTAD_H_
