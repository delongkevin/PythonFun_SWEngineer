// ----------------------------------------------------------------------------
// --- Written by Ehsan Parvizi [19-Aug-2013]
// --- Modified by Hany Kashif [25-Sep-2014]
// --- Copyright (c) Magna Vectrics (MEVC) 2013
// ----------------------------------------------------------------------------
// --- TSCImplConfig.cpp - Loading configuration method for Impl Object
// ----------------------------------------------------------------------------
#include "tscAlgImpl.h"
// ----------------------------------------------------------------------------
bool_t tsc::TSCAlgImpl::loadConfiguration_b()
{
  /* DD-ID: {1761432D-3CB3-4dc4-85FB-1D24320A2B97}*/
    return true;
}

// PRQA S 4327 ++
// PRQA S 4212 ++
bool_t tsc::TSCAlgImpl::UpdateExternalConfiguration(tscApi::enuCameraID i_CameraID_t) const
{
  /* DD-ID: {799EDAA3-6BE9-4cbc-85B9-D3803B934BCC}*/
    bool_t v_Status_b = true;
    mecl::core::UnusedParameter(i_CameraID_t); //To suppress warning
    return v_Status_b;
}
// PRQA S 4327 --
// PRQA S 4212 --
