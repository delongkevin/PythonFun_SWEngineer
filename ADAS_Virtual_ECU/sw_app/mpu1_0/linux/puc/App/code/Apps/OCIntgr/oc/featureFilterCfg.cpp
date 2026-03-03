// ----------------------------------------------------------------------------
// --- Written by Ehsan Parvizi [14-Jul-2013]
// --- Modified by Ehsan Parvizi [20-Aug-2014]
// --- Modified by Hany Kashif [25-Sep-2014]
// --- Copyright (c) Magna Vectrics (MEVC) 2014
// ----------------------------------------------------------------------------
// --- Config.cpp - Loading configuration method
// ----------------------------------------------------------------------------
#include "configuration.h"
#include "featureCollection.h"
#include "featureFilter.h"
// ----------------------------------------------------------------------------
//-------------------------------------------------------------------------

bool_t ff::FeatureFilter::loadConfiguration_b()
{
  /* DD-ID: {0E20CC88-B7ED-4a1e-A98A-C59DB6A01A4B}*/
    bool_t v_Ret_b = true;

    if(!UpdateExternalConfiguration(cameraID_t))
    {
        v_Ret_b = false;
    }

    return v_Ret_b;
}

//-------------------------------------------------------------------------
bool_t ff::FeatureFilter::UpdateExternalConfiguration(tscApi::enuCameraID i_CameraID_t)
{
  /* DD-ID: {4AADCDF8-6D76-4b4c-8486-0AAC385F926C}*/
    bool_t v_Status_b = true;

    tsc_cfg::roi_ConfigStrType v_FcROIConfigData_t;

     /* Point to the camera configuration corresponding to the configuration */
    v_Status_b = CExtConfig::FC_LoadFromPlatform(i_CameraID_t,&v_FcROIConfigData_t);

    minPixelMotionThresh_u32 = v_FcROIConfigData_t.trajectoryFilterConfig_t.minPixelMotionThresh_u32;

    slopeDifferenceThresh_f64 = v_FcROIConfigData_t.trajectoryFilterConfig_t.slopeDifferenceThreshold_f64;

    angleThreshIGDeg_f32 = v_FcROIConfigData_t.trajectoryFilterConfig_t.angleThresholdDegIG_f64;

    deviationPercentageIG_u32 = v_FcROIConfigData_t.trajectoryFilterConfig_t.deviationPercentageIG_u32;

    useInitialGuessCombinations_b = v_FcROIConfigData_t.trajectoryFilterConfig_t.useCombinations_b;

    initialGuessDiffThresholdDeg_f32 = v_FcROIConfigData_t.trajectoryFilterConfig_t.combinationsDiffThresholdDeg_f64;

    useSfmFilter_b = v_FcROIConfigData_t.trajectoryFilterConfig_t.useSfmFilter_b;
    maxHeightDiffMm_f64 = v_FcROIConfigData_t.trajectoryFilterConfig_t.maxHeightDiffMm_f64;

    return v_Status_b;
}

//-------------------------------------------------------------------------
