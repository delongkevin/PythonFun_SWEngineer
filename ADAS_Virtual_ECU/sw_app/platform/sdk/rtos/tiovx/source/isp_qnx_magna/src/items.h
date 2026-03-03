/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           cogent_api.h
 *  @brief          External API
 *
 *  @version        3.21_tda4_01
 *  @author         Mikhail Vakhrushev & Alexander Ronzhin
 *  @date           12.10.2020
 *
 * =========================================================================
 *
 *  @par          Change History:
 *
 * ========================================================================= */


#ifndef ITEMS_H
#define ITEMS_H

#include "yuv_data.h"

/* PRQA S 3453 ++ */
/* PRQA S 3410 ++ */
#include "registers_setup_233.h"

/* PRQA S 3410 -- */

#ifdef LIST_ISP_CFG
#undef LIST_ISP_CFG
#endif
#ifdef MAGNA_PSA
#define LIST_ISP_CFG() \
    ITEM_PROC_I(caCfg__Enable) \
    ITEM_PROC_I(caCfg__Line_Offset) \
    ITEM_PROC_I(caCfg__Mesh_Height) \
    ITEM_PROC_I(caCfg__Mesh_Scale) \
    ITEM_PROC_I(caCfg__Mesh_Width) \
    ITEM_PROC_I(caCfg__Plane_Offset) \
    ITEM_PROC_I(caCorrLutCfg__pEntry) \
    ITEM_PROC_I(caCorrLutCfg__Size) \
    ITEM_PROC_I(caFiltLutCfg__pEntry) \
    ITEM_PROC_I(caFiltLutCfg__Size) \
    ITEM_PROC_I(demCfg__Enable) \
    ITEM_PROC_I(demCfg__RCCC__C2_imbalance_strength) \
    ITEM_PROC_I(demCfg__RCCC__C3_imbalance_strength) \
    ITEM_PROC_I(demCfg__RCCC__Flatness_value) \
    ITEM_PROC_I(demCfg__RCCC__Gain_R) \
    ITEM_PROC_I(demCfg__RCCC__Interpolation_Directionality) \
    ITEM_PROC_I(demCfg__RCCC__Sharp_High) \
    ITEM_PROC_I(demCfg__RCCC__Sharp_Limit) \
    ITEM_PROC_I(demCfg__RCCC__Sharp_Low) \
    ITEM_PROC_I(demCfg__RCCC__WDR_Max_gain_rec) \
    ITEM_PROC_I(demCfg__RCCC__WDR_Thresh_high) \
    ITEM_PROC_I(demCfg__RCCC__WDR_Thresh_low) \
    ITEM_PROC_I(demCfg__RGBI__Clip_Debloom) \
    ITEM_PROC_I(demCfg__RGBI__Clip_Level) \
    ITEM_PROC_I(demCfg__RGBI__Declip_Mode) \
    ITEM_PROC_I(demCfg__RGBI__FC_Grad) \
    ITEM_PROC_I(demCfg__RGBI__FC_Low) \
    ITEM_PROC_I(demCfg__RGBI__Gain_B) \
    ITEM_PROC_I(demCfg__RGBI__Gain_R) \
    ITEM_PROC_I(demCfg__RGBI__Interpolation_Directionality) \
    ITEM_PROC_I(demCfg__RGBI__IrCorrMat) \
    ITEM_PROC_I(demCfg__RGBI__Sharp_High) \
    ITEM_PROC_I(demCfg__RGBI__Sharp_Limit) \
    ITEM_PROC_I(demCfg__RGBI__Sharp_Low) \
    ITEM_PROC_I(demCfg__RGBI__Static_Gain_B) \
    ITEM_PROC_I(demCfg__RGBI__Static_Gain_I) \
    ITEM_PROC_I(demCfg__RGBI__Static_Gain_R) \
    ITEM_PROC_I(demCfg__RGGB__AA__Offset) \
    ITEM_PROC_I(demCfg__RGGB__AA__Slope) \
    ITEM_PROC_I(demCfg__RGGB__AA__Thresh) \
    ITEM_PROC_I(demCfg__RGGB__AC__Offset) \
    ITEM_PROC_I(demCfg__RGGB__AC__Slope) \
    ITEM_PROC_I(demCfg__RGGB__AC__Thresh) \
    ITEM_PROC_I(demCfg__RGGB__FC_Alias_Slope) \
    ITEM_PROC_I(demCfg__RGGB__FC_Alias_Thresh) \
    ITEM_PROC_I(demCfg__RGGB__FC_Slope) \
    ITEM_PROC_I(demCfg__RGGB__Luminance_Th) \
    ITEM_PROC_I(demCfg__RGGB__Sad_Amplifier) \
    ITEM_PROC_I(demCfg__RGGB__Sat__Offset) \
    ITEM_PROC_I(demCfg__RGGB__Sat__Slope) \
    ITEM_PROC_I(demCfg__RGGB__Sat__Thresh) \
    ITEM_PROC_I(demCfg__RGGB__Sharp_Algorithm) \
    ITEM_PROC_I(demCfg__RGGB__Sharp_Str_d) \
    ITEM_PROC_I(demCfg__RGGB__Sharp_Str_Ld) \
    ITEM_PROC_I(demCfg__RGGB__Sharp_Str_Ldu) \
    ITEM_PROC_I(demCfg__RGGB__Sharp_Str_Lu) \
    ITEM_PROC_I(demCfg__RGGB__Sharp_Str_ud) \
    ITEM_PROC_I(demCfg__RGGB__Thresh_Min_d) \
    ITEM_PROC_I(demCfg__RGGB__Thresh_Min_ud) \
    ITEM_PROC_I(demCfg__RGGB__UU__Offset) \
    ITEM_PROC_I(demCfg__RGGB__UU__Slope) \
    ITEM_PROC_I(demCfg__RGGB__UU__Thresh) \
    ITEM_PROC_I(demCfg__RGGB__VA__Offset) \
    ITEM_PROC_I(demCfg__RGGB__VA__Slope) \
    ITEM_PROC_I(demCfg__RGGB__VA__Thresh) \
    ITEM_PROC_I(demCfg__RGGB__VH__Offset) \
    ITEM_PROC_I(demCfg__RGGB__VH__Slope) \
    ITEM_PROC_I(demCfg__RGGB__VH__Thresh) \
    ITEM_PROC_I(demNpCfg__Below_Black_Mode) \
    ITEM_PROC_I(demNpCfg__Black_Offset) \
    ITEM_PROC_I(demNpCfg__LUT__pEntry) \
    ITEM_PROC_I(demNpCfg__LUT__Size) \
    ITEM_PROC_I(demNpCfg__Noise_Profile_Offset) \
    ITEM_PROC_I(dgCfg__Enable) \
    ITEM_PROC_I(dgCfg__Gain) \
    ITEM_PROC_I(dgCfg__Offset) \
    ITEM_PROC_I(toneMapGainCfg__Enable) \
    ITEM_PROC_I(toneMapGainCfg__Gain) \
    ITEM_PROC_I(toneMapGainCfg__Offset) \
    ITEM_PROC_I(expStatsCfg__Enable) \
    ITEM_PROC_I(expStatsCfg__Hist_Thresh_01) \
    ITEM_PROC_I(expStatsCfg__Hist_Thresh_12) \
    ITEM_PROC_I(expStatsCfg__Hist_Thresh_23) \
    ITEM_PROC_I(expStatsCfg__Hist_Thresh_34) \
    ITEM_PROC_I(expStatsCfg__Nodes_Used_Horiz) \
    ITEM_PROC_I(expStatsCfg__Nodes_Used_Vert) \
    ITEM_PROC_I(expStatsCfg__TapPoint) \
    ITEM_PROC_I(gammaBe0Cfg__Enable) \
    ITEM_PROC_I(gammaBe0Cfg__pEntry) \
    ITEM_PROC_I(gammaBe0Cfg__Size) \
    ITEM_PROC_I(gammaBe1Cfg__Enable) \
    ITEM_PROC_I(gammaBe1Cfg__pEntry) \
    ITEM_PROC_I(gammaBe1Cfg__Size) \
    ITEM_PROC_I(gammaCfg__Enable) \
    ITEM_PROC_I(gammaCfg__pEntry) \
    ITEM_PROC_I(gammaCfg__Size) \
    ITEM_PROC_I(gammaDlCfg__Alpha) \
    ITEM_PROC_I(gammaDlCfg__Black_Level_After) \
    ITEM_PROC_I(gammaDlCfg__Black_Level_Before) \
    ITEM_PROC_I(gammaDlCfg__Enable) \
    ITEM_PROC_I(histStatsCfg__Active_Height) \
    ITEM_PROC_I(histStatsCfg__Active_Width) \
    ITEM_PROC_I(histStatsCfg__Black) \
    ITEM_PROC_I(histStatsCfg__CenterX) \
    ITEM_PROC_I(histStatsCfg__CenterY) \
    ITEM_PROC_I(histStatsCfg__CFA_pattern) \
    ITEM_PROC_I(histStatsCfg__Enable) \
    ITEM_PROC_I(histStatsCfg__Gain) \
    ITEM_PROC_I(histStatsCfg__Mode) \
    ITEM_PROC_I(histStatsCfg__Nodes_Used_Horiz) \
    ITEM_PROC_I(histStatsCfg__Nodes_Used_Vert) \
    ITEM_PROC_I(histStatsCfg__Off_Center_multX) \
    ITEM_PROC_I(histStatsCfg__Off_Center_multY) \
    ITEM_PROC_I(histStatsCfg__offset_x) \
    ITEM_PROC_I(histStatsCfg__offset_y) \
    ITEM_PROC_I(histStatsCfg__Radial_shading_enable) \
    ITEM_PROC_I(histStatsCfg__RGGB_start) \
    ITEM_PROC_I(histStatsCfg__scale_bottom) \
    ITEM_PROC_I(histStatsCfg__scale_top) \
    ITEM_PROC_I(histStatsCfg__Shading_LUT) \
    ITEM_PROC_I(histStatsCfg__skip_x) \
    ITEM_PROC_I(histStatsCfg__skip_y) \
    ITEM_PROC_I(histStatsCfg__TapPoint) \
    ITEM_PROC_I(inputFormCfg__Bit_Width) \
    ITEM_PROC_I(inputFormCfg__Black_Level) \
    ITEM_PROC_I(inputFormCfg__Enable) \
    ITEM_PROC_I(inputFormCfg__Ext1__factor_ML) \
    ITEM_PROC_I(inputFormCfg__Ext1__factor_MS) \
    ITEM_PROC_I(inputFormCfg__Ext2__knee_point) \
    ITEM_PROC_I(inputFormCfg__Ext2__slope_select) \
    ITEM_PROC_I(inputFormCfg__Mode) \
    ITEM_PROC_I(invGammaDlCfg__Alpha) \
    ITEM_PROC_I(invGammaDlCfg__Black_Level_After) \
    ITEM_PROC_I(invGammaDlCfg__Black_Level_Before) \
    ITEM_PROC_I(invGammaDlCfg__Enable) \
    ITEM_PROC_I(linOffCfg__Enable) \
    ITEM_PROC_I(linOffCfg__Offset) \
    ITEM_PROC_I(outFormCfg__Enable) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__Clip__Enable) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__Clip__Value) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__HS__EnableAB2HS) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__HS__EnableRGB2AB) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__HS__LPF__Enable) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__HS__LPF__Horizontal_Downsample) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__HS__LPF__Horizontal_Filter) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__HS__LPF__Vertical_Downsample) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__LUT__Enable) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__LUT__pEntry) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__LUT__Size) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__RGB2RGB__b) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__RGB2RGB__c) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__RGB2RGB__Enable) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__Ss__ClipValue) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__Ss__Enable) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__Ss__Mode) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__YUV__ClipValue) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__YUV__LPF__Enable) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__YUV__LPF__Horizontal_Downsample) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__YUV__LUT__Enable) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__YUV__LUT__Size) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__YUV__Mode) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__YUV__RGB2YUV__b) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__YUV__RGB2YUV__c) \
    ITEM_PROC_I(outFormCfg__HSRGBYUV__YUV__RGB2YUV__Enable) \
    ITEM_PROC_I(outFormCfg__Ir__ChannelNumber) \
    ITEM_PROC_I(outFormCfg__Ir__LUT__Enable) \
    ITEM_PROC_I(outFormCfg__Ir__LUT__Size) \
    ITEM_PROC_I(outFormCfg__Ir__SubSampMode) \
    ITEM_PROC_I(outFormCfg__LUV__Clip__Enable) \
    ITEM_PROC_I(outFormCfg__LUV__Clip__Value) \
    ITEM_PROC_I(outFormCfg__LUV__EnableXYZtoLUV) \
    ITEM_PROC_I(outFormCfg__LUV__LPF__Enable) \
    ITEM_PROC_I(outFormCfg__LUV__LPF__Horizontal_Downsample) \
    ITEM_PROC_I(outFormCfg__LUV__LPF__Horizontal_Filter) \
    ITEM_PROC_I(outFormCfg__LUV__LPF__Vertical_Downsample) \
    ITEM_PROC_I(outFormCfg__LUV__LUT__Enable) \
    ITEM_PROC_I(outFormCfg__LUV__LUT__Size) \
    ITEM_PROC_I(outFormCfg__LUV__RGB2XYZ__b) \
    ITEM_PROC_I(outFormCfg__LUV__RGB2XYZ__c) \
    ITEM_PROC_I(outFormCfg__LUV__RGB2XYZ__Enable) \
    ITEM_PROC_I(pipeNpCfg__Below_Black_Mode) \
    ITEM_PROC_I(pipeNpCfg__Black_Offset) \
    ITEM_PROC_I(pipeNpCfg__Exp_Thresh) \
    ITEM_PROC_I(pipeNpCfg__Long_Ratio) \
    ITEM_PROC_I(pipeNpCfg__LUT__pEntry) \
    ITEM_PROC_I(pipeNpCfg__LUT__Size) \
    ITEM_PROC_I(pipeNpCfg__Short_Ratio) \
    ITEM_PROC_I(radialShadingCfg__B__Center_X) \
    ITEM_PROC_I(radialShadingCfg__B__Center_Y) \
    ITEM_PROC_I(radialShadingCfg__B__Off_Center_Mult_X) \
    ITEM_PROC_I(radialShadingCfg__B__Off_Center_Mult_Y) \
    ITEM_PROC_I(radialShadingCfg__Enable) \
    ITEM_PROC_I(radialShadingCfg__G__Center_X) \
    ITEM_PROC_I(radialShadingCfg__G__Center_Y) \
    ITEM_PROC_I(radialShadingCfg__G__Off_Center_Mult_X) \
    ITEM_PROC_I(radialShadingCfg__G__Off_Center_Mult_Y) \
    ITEM_PROC_I(radialShadingCfg__Ir__Center_X) \
    ITEM_PROC_I(radialShadingCfg__Ir__Center_Y) \
    ITEM_PROC_I(radialShadingCfg__Ir__Off_Center_Mult_X) \
    ITEM_PROC_I(radialShadingCfg__Ir__Off_Center_Mult_Y) \
    ITEM_PROC_I(radialShadingCfg__R__Center_X) \
    ITEM_PROC_I(radialShadingCfg__R__Center_Y) \
    ITEM_PROC_I(radialShadingCfg__R__Off_Center_Mult_X) \
    ITEM_PROC_I(radialShadingCfg__R__Off_Center_Mult_Y) \
    ITEM_PROC_I(radialShadingLutCfg__pB_Data) \
    ITEM_PROC_I(radialShadingLutCfg__pG_Data) \
    ITEM_PROC_I(radialShadingLutCfg__pIr_Data) \
    ITEM_PROC_I(radialShadingLutCfg__pR_Data) \
    ITEM_PROC_I(radialShadingLutCfg__Size) \
    ITEM_PROC_I(rawFeCfg__Bright_Disable) \
    ITEM_PROC_I(rawFeCfg__Dark_Disable) \
    ITEM_PROC_I(rawFeCfg__DP_Slope) \
    ITEM_PROC_I(rawFeCfg__DP_Threshold) \
    ITEM_PROC_I(rawFeCfg__DynDP_Blending) \
    ITEM_PROC_I(rawFeCfg__DynDP_Enable) \
    ITEM_PROC_I(rawFeCfg__DynDP_Line_Threshold) \
    ITEM_PROC_I(rawFeCfg__DynDP_Show) \
    ITEM_PROC_I(rawFeCfg__DynDP_Threshold) \
    ITEM_PROC_I(rawFeCfg__Enable) \
    ITEM_PROC_I(rawFeCfg__GE_Enable) \
    ITEM_PROC_I(rawFeCfg__GE_Sensitivity) \
    ITEM_PROC_I(rawFeCfg__GE_Slope) \
    ITEM_PROC_I(rawFeCfg__GE_Strength) \
    ITEM_PROC_I(rawFeCfg__GE_Threshold) \
    ITEM_PROC_I(rawFeCfg__LongExp_Threshold) \
    ITEM_PROC_I(rawFeCfg__RFE_L2_Disable) \
    ITEM_PROC_I(rawFeCfg__ShortExp_Threshold) \
    ITEM_PROC_I(rawFeCfg__Sigma_In) \
    ITEM_PROC_I(sinterCfg__Enable) \
    ITEM_PROC_I(sinterCfg__Filter_Select) \
    ITEM_PROC_I(sinterCfg__Intensity_Config) \
    ITEM_PROC_I(sinterCfg__Intensity_Select) \
    ITEM_PROC_I(sinterCfg__Strength_1) \
    ITEM_PROC_I(sinterCfg__Strength_4) \
    ITEM_PROC_I(sinterCfg__Thresh_1h) \
    ITEM_PROC_I(sinterCfg__Thresh_1v) \
    ITEM_PROC_I(sinterCfg__Thresh_4h) \
    ITEM_PROC_I(sinterCfg__Thresh_4v) \
    ITEM_PROC_I(sinterCfg__Thresh_Long) \
    ITEM_PROC_I(sinterCfg__Thresh_Short) \
    ITEM_PROC_I(sinterRsCfg__CenterX) \
    ITEM_PROC_I(sinterRsCfg__CenterY) \
    ITEM_PROC_I(sinterRsCfg__Enable) \
    ITEM_PROC_I(sinterRsCfg__LUT__pEntry) \
    ITEM_PROC_I(sinterRsCfg__LUT__Size) \
    ITEM_PROC_I(sinterRsCfg__Off_Center_Mult) \
    ITEM_PROC_I(toneMap2DLutCfg__pEntryX) \
    ITEM_PROC_I(toneMap2DLutCfg__pEntryY) \
    ITEM_PROC_I(toneMap2DLutCfg__Size) \
    ITEM_PROC_I(toneMapCfg__Black_Level) \
    ITEM_PROC_I(toneMapCfg__Collection_Correction) \
    ITEM_PROC_I(toneMapCfg__Enable) \
    ITEM_PROC_I(toneMapCfg__Iridix__Bright_Pres) \
    ITEM_PROC_I(toneMapCfg__Iridix__Contrast) \
    ITEM_PROC_I(toneMapCfg__Iridix__Dark_Enh) \
    ITEM_PROC_I(toneMapCfg__Iridix__Mode) \
    ITEM_PROC_I(toneMapCfg__Iridix__ROI__Hor_End) \
    ITEM_PROC_I(toneMapCfg__Iridix__ROI__Hor_Start) \
    ITEM_PROC_I(toneMapCfg__Iridix__ROI__InRoi_Strength) \
    ITEM_PROC_I(toneMapCfg__Iridix__ROI__OutRoi_Strength) \
    ITEM_PROC_I(toneMapCfg__Iridix__ROI__Ver_End) \
    ITEM_PROC_I(toneMapCfg__Iridix__ROI__Ver_Start) \
    ITEM_PROC_I(toneMapCfg__Iridix__Slope_Max) \
    ITEM_PROC_I(toneMapCfg__Iridix__Slope_Min) \
    ITEM_PROC_I(toneMapCfg__Iridix__Space_Variance) \
    ITEM_PROC_I(toneMapCfg__Iridix__Variance_Intensity) \
    ITEM_PROC_I(toneMapCfg__Iridix__Variance_Space) \
    ITEM_PROC_I(toneMapCfg__Max_Alg_Type) \
    ITEM_PROC_I(toneMapCfg__Mode) \
    ITEM_PROC_I(toneMapCfg__PostGammaAlpha) \
    ITEM_PROC_I(toneMapCfg__PostGammaMode) \
    ITEM_PROC_I(toneMapCfg__PostGamma_Pos) \
    ITEM_PROC_I(toneMapCfg__PreGammaAlpha) \
    ITEM_PROC_I(toneMapCfg__PreGammaMode) \
    ITEM_PROC_I(toneMapCfg__Use_Black_Level) \
    ITEM_PROC_I(toneMapCfg__WB__GainB) \
    ITEM_PROC_I(toneMapCfg__WB__GainGb) \
    ITEM_PROC_I(toneMapCfg__WB__GainGr) \
    ITEM_PROC_I(toneMapCfg__WB__GainR) \
    ITEM_PROC_I(toneMapCfg__WB__Offset) \
    ITEM_PROC_I(toneMapCfg__White_Level) \
    ITEM_PROC_I(toneMapLocalAsymLutCfg__pEntry) \
    ITEM_PROC_I(toneMapLocalAsymLutCfg__Size) \
    ITEM_PROC_I(wbCfg__Enable) \
    ITEM_PROC_I(wbCfg__Gain) \
    ITEM_PROC_I(wbCfg__Offset)
#else
#define LIST_ISP_CFG() \
    ITEM_PROC_I(ccmCfg__offsets) \
    ITEM_PROC_I(ccmCfg__weights) \
    ITEM_PROC_I(cfaCfg__bypass) \
    ITEM_PROC_I(cfaCfg__coeff) \
    ITEM_PROC_I(cfaCfg__coreBlendMode) \
    ITEM_PROC_I(cfaCfg__coreSel) \
    ITEM_PROC_I(cfaCfg__gradHzPh) \
    ITEM_PROC_I(cfaCfg__gradVtPh) \
    ITEM_PROC_I(cfaCfg__intsBitField) \
    ITEM_PROC_I(cfaCfg__intsShiftPh) \
    ITEM_PROC_I(cfaCfg__thr) \
    ITEM_PROC_I(cfaLut16to12Cfg__clip) \
    ITEM_PROC_I(cfaLut16to12Cfg__enable) \
    ITEM_PROC_I(cfaLut16to12Cfg__inputBits) \
    ITEM_PROC_I(cfaLut16to12Cfg__tableAddr) \
    ITEM_PROC_I(decomp1Cfg__clip) \
    ITEM_PROC_I(decomp1Cfg__enable) \
    ITEM_PROC_I(decomp1Cfg__inputBits) \
    ITEM_PROC_I(decomp1Cfg__tableAddr) \
    ITEM_PROC_I(decomp2Cfg__clip) \
    ITEM_PROC_I(decomp2Cfg__enable) \
    ITEM_PROC_I(decomp2Cfg__inputBits) \
    ITEM_PROC_I(decomp2Cfg__tableAddr) \
    ITEM_PROC_I(decomp3Cfg__clip) \
    ITEM_PROC_I(decomp3Cfg__enable) \
    ITEM_PROC_I(decomp3Cfg__inputBits) \
    ITEM_PROC_I(decomp3Cfg__tableAddr) \
    ITEM_PROC_I(dpcLutCfg__enable) \
    ITEM_PROC_I(dpcLutCfg__isReplaceWhite) \
    ITEM_PROC_I(dpcLutCfg__maxDefectPixels) \
    ITEM_PROC_I(dpcLutCfg__table) \
    ITEM_PROC_I(dpcOtfCfg__enable) \
    ITEM_PROC_I(dpcOtfCfg__slope) \
    ITEM_PROC_I(dpcOtfCfg__threshold) \
    ITEM_PROC_I(eeCfg__alignY12withChroma) \
    ITEM_PROC_I(eeCfg__alignY8withChroma) \
    ITEM_PROC_I(eeCfg__bypassC12) \
    ITEM_PROC_I(eeCfg__bypassC8) \
    ITEM_PROC_I(eeCfg__bypassY12) \
    ITEM_PROC_I(eeCfg__bypassY8) \
    ITEM_PROC_I(eeCfg__coeff) \
    ITEM_PROC_I(eeCfg__eeForY12OrY8) \
    ITEM_PROC_I(eeCfg__enable) \
    ITEM_PROC_I(eeCfg__haloReductionOn) \
    ITEM_PROC_I(eeCfg__leftShift) \
    ITEM_PROC_I(eeCfg__lut) \
    ITEM_PROC_I(eeCfg__rightShift) \
    ITEM_PROC_I(eeCfg__yeeEThr) \
    ITEM_PROC_I(eeCfg__yeeMergeSel) \
    ITEM_PROC_I(eeCfg__yeeShift) \
    ITEM_PROC_I(eeCfg__yesEGain) \
    ITEM_PROC_I(eeCfg__yesEThr1) \
    ITEM_PROC_I(eeCfg__yesEThr2) \
    ITEM_PROC_I(eeCfg__yesGGain) \
    ITEM_PROC_I(eeCfg__yesGOfset) \
    ITEM_PROC_I(fwdPrcpCfg__enable) \
    ITEM_PROC_I(fwdPrcpCfg__table) \
    ITEM_PROC_I(revPrcpCfg__enable) \
    ITEM_PROC_I(revPrcpCfg__table) \
    ITEM_PROC_I(gammaCfg__enable) \
    ITEM_PROC_I(gammaCfg__outClip) \
    ITEM_PROC_I(gammaCfg__tableC1) \
    ITEM_PROC_I(gammaCfg__tableC2) \
    ITEM_PROC_I(gammaCfg__tableC3) \
    ITEM_PROC_I(glbceCfg__asymLut) \
    ITEM_PROC_I(glbceCfg__blackLevel) \
    ITEM_PROC_I(glbceCfg__brightAmplLimit) \
    ITEM_PROC_I(glbceCfg__darkAmplLimit) \
    ITEM_PROC_I(glbceCfg__dither) \
    ITEM_PROC_I(glbceCfg__intensityVariance) \
    ITEM_PROC_I(glbceCfg__irStrength) \
    ITEM_PROC_I(glbceCfg__maxSlopeLimit) \
    ITEM_PROC_I(glbceCfg__minSlopeLimit) \
    ITEM_PROC_I(glbceCfg__spaceVariance) \
    ITEM_PROC_I(glbceCfg__whiteLevel) \
    ITEM_PROC_I(h3aCfg__aewbCfg__blackLineHeight) \
    ITEM_PROC_I(h3aCfg__aewbCfg__blackLineVertStart) \
    ITEM_PROC_I(h3aCfg__aewbCfg__enableALowComp) \
    ITEM_PROC_I(h3aCfg__aewbCfg__enableMedFilt) \
    ITEM_PROC_I(h3aCfg__aewbCfg__midFiltThreshold) \
    ITEM_PROC_I(h3aCfg__aewbCfg__outMode) \
    ITEM_PROC_I(h3aCfg__aewbCfg__satLimit) \
    ITEM_PROC_I(h3aCfg__aewbCfg__sumShift) \
    ITEM_PROC_I(h3aCfg__aewbCfg__winCfg__height) \
    ITEM_PROC_I(h3aCfg__aewbCfg__winCfg__horzCount) \
    ITEM_PROC_I(h3aCfg__aewbCfg__winCfg__horzIncr) \
    ITEM_PROC_I(h3aCfg__aewbCfg__winCfg__pos__startX) \
    ITEM_PROC_I(h3aCfg__aewbCfg__winCfg__pos__startY) \
    ITEM_PROC_I(h3aCfg__aewbCfg__winCfg__vertCount) \
    ITEM_PROC_I(h3aCfg__aewbCfg__winCfg__vertIncr) \
    ITEM_PROC_I(h3aCfg__aewbCfg__winCfg__width) \
    ITEM_PROC_I(h3aCfg__afCfg__enableALowCompr) \
    ITEM_PROC_I(h3aCfg__afCfg__enableMedFilt) \
    ITEM_PROC_I(h3aCfg__afCfg__firCfg1__coeff) \
    ITEM_PROC_I(h3aCfg__afCfg__firCfg1__threshold) \
    ITEM_PROC_I(h3aCfg__afCfg__firCfg2__coeff) \
    ITEM_PROC_I(h3aCfg__afCfg__firCfg2__threshold) \
    ITEM_PROC_I(h3aCfg__afCfg__fvMode) \
    ITEM_PROC_I(h3aCfg__afCfg__iirCfg1__coeff) \
    ITEM_PROC_I(h3aCfg__afCfg__iirCfg1__threshold) \
    ITEM_PROC_I(h3aCfg__afCfg__iirCfg2__coeff) \
    ITEM_PROC_I(h3aCfg__afCfg__iirCfg2__threshold) \
    ITEM_PROC_I(h3aCfg__afCfg__iirFiltStartPos) \
    ITEM_PROC_I(h3aCfg__afCfg__midFiltThreshold) \
    ITEM_PROC_I(h3aCfg__afCfg__paxelCfg__height) \
    ITEM_PROC_I(h3aCfg__afCfg__paxelCfg__horzCount) \
    ITEM_PROC_I(h3aCfg__afCfg__paxelCfg__horzIncr) \
    ITEM_PROC_I(h3aCfg__afCfg__paxelCfg__pos__startX) \
    ITEM_PROC_I(h3aCfg__afCfg__paxelCfg__pos__startY) \
    ITEM_PROC_I(h3aCfg__afCfg__paxelCfg__vertCount) \
    ITEM_PROC_I(h3aCfg__afCfg__paxelCfg__vertIncr) \
    ITEM_PROC_I(h3aCfg__afCfg__paxelCfg__width) \
    ITEM_PROC_I(h3aCfg__afCfg__rgbPos) \
    ITEM_PROC_I(h3aCfg__afCfg__vfMode) \
    ITEM_PROC_I(h3aCfg__module) \
    ITEM_PROC_I(h3aCfg__outputSize) \
    ITEM_PROC_I(h3aCfg__pos__startX) \
    ITEM_PROC_I(h3aCfg__pos__startY) \
    ITEM_PROC_I(h3aInCfg__inSel) \
    ITEM_PROC_I(h3aInCfg__shift) \
    ITEM_PROC_I(h3aLutCfg__clip) \
    ITEM_PROC_I(h3aLutCfg__enable) \
    ITEM_PROC_I(h3aLutCfg__inputBits) \
    ITEM_PROC_I(h3aLutCfg__tableAddr) \
    ITEM_PROC_I(histCfg__enable) \
    ITEM_PROC_I(histCfg__input) \
    ITEM_PROC_I(histCfg__roi__cropHeight) \
    ITEM_PROC_I(histCfg__roi__cropStartX) \
    ITEM_PROC_I(histCfg__roi__cropStartY) \
    ITEM_PROC_I(histCfg__roi__cropWidth) \
    ITEM_PROC_I(lscCfg__enable) \
    ITEM_PROC_I(lscCfg__gainFmt) \
    ITEM_PROC_I(lscCfg__horzDsFactor) \
    ITEM_PROC_I(lscCfg__numTblEntry) \
    ITEM_PROC_I(lscCfg__tableAddr) \
    ITEM_PROC_I(lscCfg__vertDsFactor) \
    ITEM_PROC_I(merge1Cfg__afe) \
    ITEM_PROC_I(merge1Cfg__afm) \
    ITEM_PROC_I(merge1Cfg__bf) \
    ITEM_PROC_I(merge1Cfg__dst) \
    ITEM_PROC_I(merge1Cfg__enable) \
    ITEM_PROC_I(merge1Cfg__glong) \
    ITEM_PROC_I(merge1Cfg__gshort) \
    ITEM_PROC_I(merge1Cfg__lbit) \
    ITEM_PROC_I(merge1Cfg__lbk) \
    ITEM_PROC_I(merge1Cfg__lwb) \
    ITEM_PROC_I(merge1Cfg__mad) \
    ITEM_PROC_I(merge1Cfg__mas) \
    ITEM_PROC_I(merge1Cfg__mergeClip) \
    ITEM_PROC_I(merge1Cfg__mergeShift) \
    ITEM_PROC_I(merge1Cfg__sbit) \
    ITEM_PROC_I(merge1Cfg__sbk) \
    ITEM_PROC_I(merge1Cfg__swb) \
    ITEM_PROC_I(merge1Cfg__useShortExpForWgtCalc) \
    ITEM_PROC_I(merge1Cfg__wdrThr) \
    ITEM_PROC_I(merge2Cfg__afe) \
    ITEM_PROC_I(merge2Cfg__afm) \
    ITEM_PROC_I(merge2Cfg__bf) \
    ITEM_PROC_I(merge2Cfg__dst) \
    ITEM_PROC_I(merge2Cfg__enable) \
    ITEM_PROC_I(merge2Cfg__glong) \
    ITEM_PROC_I(merge2Cfg__gshort) \
    ITEM_PROC_I(merge2Cfg__lbit) \
    ITEM_PROC_I(merge2Cfg__lbk) \
    ITEM_PROC_I(merge2Cfg__lwb) \
    ITEM_PROC_I(merge2Cfg__mad) \
    ITEM_PROC_I(merge2Cfg__mas) \
    ITEM_PROC_I(merge2Cfg__mergeClip) \
    ITEM_PROC_I(merge2Cfg__mergeShift) \
    ITEM_PROC_I(merge2Cfg__sbit) \
    ITEM_PROC_I(merge2Cfg__sbk) \
    ITEM_PROC_I(merge2Cfg__swb) \
    ITEM_PROC_I(merge2Cfg__useShortExpForWgtCalc) \
    ITEM_PROC_I(merge2Cfg__wdrThr) \
    ITEM_PROC_I(nsf4Cfg__gains) \
    ITEM_PROC_I(nsf4Cfg__lsccCfg__enable) \
    ITEM_PROC_I(nsf4Cfg__lsccCfg__gMaxCfg) \
    ITEM_PROC_I(nsf4Cfg__lsccCfg__khCfg) \
    ITEM_PROC_I(nsf4Cfg__lsccCfg__kvCfg) \
    ITEM_PROC_I(nsf4Cfg__lsccCfg__lensCenterX) \
    ITEM_PROC_I(nsf4Cfg__lsccCfg__lensCenterY) \
    ITEM_PROC_I(nsf4Cfg__lsccCfg__pwlCurve) \
    ITEM_PROC_I(nsf4Cfg__lsccCfg__setSel) \
    ITEM_PROC_I(nsf4Cfg__lsccCfg__tCfg) \
    ITEM_PROC_I(nsf4Cfg__mode) \
    ITEM_PROC_I(nsf4Cfg__tKnee) \
    ITEM_PROC_I(nsf4Cfg__tnCurve) \
    ITEM_PROC_F(nsf4Cfg__tnScale_0) \
    ITEM_PROC_F(nsf4Cfg__tnScale_1) \
    ITEM_PROC_F(nsf4Cfg__tnScale_2) \
    ITEM_PROC_I(pwlCfg1__enable) \
    ITEM_PROC_I(pwlCfg1__gain) \
    ITEM_PROC_I(pwlCfg1__mask) \
    ITEM_PROC_I(pwlCfg1__offset) \
    ITEM_PROC_I(pwlCfg1__outClip) \
    ITEM_PROC_I(pwlCfg1__shift) \
    ITEM_PROC_I(pwlCfg1__slope1) \
    ITEM_PROC_I(pwlCfg1__slope2) \
    ITEM_PROC_I(pwlCfg1__slope3) \
    ITEM_PROC_I(pwlCfg1__slope4) \
    ITEM_PROC_I(pwlCfg1__slopeShift) \
    ITEM_PROC_I(pwlCfg1__xthr1) \
    ITEM_PROC_I(pwlCfg1__xthr2) \
    ITEM_PROC_I(pwlCfg1__xthr3) \
    ITEM_PROC_I(pwlCfg1__ythr1) \
    ITEM_PROC_I(pwlCfg1__ythr2) \
    ITEM_PROC_I(pwlCfg1__ythr3) \
    ITEM_PROC_I(pwlCfg2__enable) \
    ITEM_PROC_I(pwlCfg2__gain) \
    ITEM_PROC_I(pwlCfg2__mask) \
    ITEM_PROC_I(pwlCfg2__offset) \
    ITEM_PROC_I(pwlCfg2__outClip) \
    ITEM_PROC_I(pwlCfg2__shift) \
    ITEM_PROC_I(pwlCfg2__slope1) \
    ITEM_PROC_I(pwlCfg2__slope2) \
    ITEM_PROC_I(pwlCfg2__slope3) \
    ITEM_PROC_I(pwlCfg2__slope4) \
    ITEM_PROC_I(pwlCfg2__slopeShift) \
    ITEM_PROC_I(pwlCfg2__xthr1) \
    ITEM_PROC_I(pwlCfg2__xthr2) \
    ITEM_PROC_I(pwlCfg2__xthr3) \
    ITEM_PROC_I(pwlCfg2__ythr1) \
    ITEM_PROC_I(pwlCfg2__ythr2) \
    ITEM_PROC_I(pwlCfg2__ythr3) \
    ITEM_PROC_I(pwlCfg3__enable) \
    ITEM_PROC_I(pwlCfg3__gain) \
    ITEM_PROC_I(pwlCfg3__mask) \
    ITEM_PROC_I(pwlCfg3__offset) \
    ITEM_PROC_I(pwlCfg3__outClip) \
    ITEM_PROC_I(pwlCfg3__shift) \
    ITEM_PROC_I(pwlCfg3__slope1) \
    ITEM_PROC_I(pwlCfg3__slope2) \
    ITEM_PROC_I(pwlCfg3__slope3) \
    ITEM_PROC_I(pwlCfg3__slope4) \
    ITEM_PROC_I(pwlCfg3__slopeShift) \
    ITEM_PROC_I(pwlCfg3__xthr1) \
    ITEM_PROC_I(pwlCfg3__xthr2) \
    ITEM_PROC_I(pwlCfg3__xthr3) \
    ITEM_PROC_I(pwlCfg3__ythr1) \
    ITEM_PROC_I(pwlCfg3__ythr2) \
    ITEM_PROC_I(pwlCfg3__ythr3) \
    ITEM_PROC_I(rfeLut20to16Cfg__clip) \
    ITEM_PROC_I(rfeLut20to16Cfg__enable) \
    ITEM_PROC_I(rfeLut20to16Cfg__inputBits) \
    ITEM_PROC_I(rgb2hsvCfg__h1Input) \
    ITEM_PROC_I(rgb2hsvCfg__h2Input) \
    ITEM_PROC_I(rgb2hsvCfg__inputSelect) \
    ITEM_PROC_I(rgb2hsvCfg__offset) \
    ITEM_PROC_I(rgb2hsvCfg__satDiv) \
    ITEM_PROC_I(rgb2hsvCfg__satMinThr) \
    ITEM_PROC_I(rgb2hsvCfg__satMode) \
    ITEM_PROC_I(rgb2hsvCfg__threshold) \
    ITEM_PROC_I(rgb2hsvCfg__useWbDataForGreyCalc) \
    ITEM_PROC_I(rgb2hsvCfg__wbOffset) \
    ITEM_PROC_I(rgb2hsvCfg__weights) \
    ITEM_PROC_I(rgb2yuvCfg__offsets) \
    ITEM_PROC_I(rgb2yuvCfg__weights) \
    ITEM_PROC_I(wbCfg__gain) \
    ITEM_PROC_I(wbCfg__offset) \
    ITEM_PROC_I(yuvSatLutCfg__enableChromaLut) \
    ITEM_PROC_I(yuvSatLutCfg__enableLumaLut) \
    ITEM_PROC_I(yuvSatLutCfg__enableSaturLut) \
    ITEM_PROC_I(yuvSatLutCfg__lumaInputBits) \
    ITEM_PROC_I(dgCfg__Gain)
#endif

#define SET_INTERNAL_EMB_ID(x,y) ITEM_PROC_I(ISP_INTERNAL_##y)
#define SET_INTERNAL_TRACE_EMB_ID(x,y) ITEM_PROC_I(ISP_INTERNAL_TRACE_##y)

#ifdef LIST_INTERNAL_CFG
#undef LIST_INTERNAL_CFG
#endif
#define LIST_INTERNAL_CFG() \
    ITEM_PROC_I(ISP_INTERNAL_AVE_BR) \
    ITEM_PROC_I(ISP_INTERNAL_WHITE_Q) \
    ITEM_PROC_I(ISP_INTERNAL_APPLIED_COMP_TO_STATS) \
    ITEM_PROC_F(ISP_INTERNAL_TEMPERATURE) \
    ITEM_PROC_I(ISP_INTERNAL_DLO_GAIN) \
    ITEM_PROC_I(ISP_INTERNAL_GAIN) \
    ITEM_PROC_I(ISP_INTERNAL_AE_EXPOSURE) \
    ITEM_PROC_I(ISP_INTERNAL_SENSOR_EXPOSURE) \
    ITEM_PROC_F(ISP_INTERNAL_ADD_TO_SENSOR_AE_EXPOSURE)\
    ITEM_PROC_F(ISP_INTERNAL_ADD_TO_SENSOR_ISP_VERSION)\
    ITEM_PROC_F(ISP_INTERNAL_ADD_TO_SENSOR_SENSOR_VIRTUAL_GAIN_T0)\
    ITEM_PROC_F(ISP_INTERNAL_ADD_TO_SENSOR_SENSOR_VIRTUAL_GAIN_T1)\
    ITEM_PROC_I(ISP_INTERNAL_DBLC_CONTROL)\
    ITEM_PROC_F(ISP_INTERNAL_SATURATION)\
    ITEM_PROC_F(ISP_INTERNAL_demCfg__RGGB__Sharp_Str_ud)\
    ITEM_PROC_F(ISP_INTERNAL_demCfg__RGGB__Sharp_Str_Lu)\
    ITEM_PROC_F(ISP_INTERNAL_demCfg__RGGB__Sharp_Str_Ldu)\
    ITEM_PROC_F(ISP_INTERNAL_demCfg__RGGB__Sharp_Str_Ld)\
    ITEM_PROC_F(ISP_INTERNAL_SENSOR_EV) \
    ITEM_PROC_F(ISP_INTERNAL_CALC_LTM_CC_FROM_EV) \
    ITEM_PROC_F(ISP_INTERNAL_LTM_CC_DIFF_FROM_EV) \
    ITEM_PROC_I(ISP_INTERNAL_LUX) \
    ITEM_PROC_F(ISP_INTERNAL_SENSOR_VIRTUAL_GAIN_T0) \
    ITEM_PROC_F(ISP_INTERNAL_SENSOR_VIRTUAL_GAIN_T1) \
    ITEM_PROC_I(ISP_INTERNAL_AE_NM_GAIN_MIN) \
    ITEM_PROC_I(ISP_INTERNAL_AE_NM_GAIN_MAX) \
    ITEM_PROC_I(ISP_INTERNAL_AE_NM_EXP_MIN) \
    ITEM_PROC_I(ISP_INTERNAL_AE_NM_EXP_MAX) \
    ITEM_PROC_I(ISP_INTERNAL_AE_FINISH) \
    ITEM_PROC_I(ISP_INTERNAL_NULL) \
    ITEM_PROC_F(ISP_INTERNAL_AWB_R) \
    ITEM_PROC_F(ISP_INTERNAL_AWB_G) \
    ITEM_PROC_F(ISP_INTERNAL_AWB_B) \
    ITEM_PROC_F(ISP_INTERNAL_AWB_R_SENSOR) \
    ITEM_PROC_F(ISP_INTERNAL_AWB_G_SENSOR) \
    ITEM_PROC_F(ISP_INTERNAL_AWB_B_SENSOR) \
    ITEM_PROC_I(ISP_INTERNAL_CONTROLS_B_VAL) \
    ITEM_PROC_I(ISP_INTERNAL_CONTROLS_C_VAL) \
    ITEM_PROC_I(ISP_INTERNAL_TPG_VAL) \
    ITEM_PROC_I(ISP_INTERNAL_MVMODE_VAL) \
    ITEM_PROC_I(ISP_INTERNAL_TESTMODE_VAL) \
    ITEM_PROC_I(ISP_INTERNAL_SINTER_VAL) \
    ITEM_PROC_F(ISP_INTERNAL_SINTER_SCALE_0) \
    ITEM_PROC_F(ISP_INTERNAL_SINTER_SCALE_1) \
    ITEM_PROC_F(ISP_INTERNAL_SINTER_SCALE_2) \
    ITEM_PROC_F(ISP_INTERNAL_TABLE_ID) \
    ITEM_PROC_I(ISP_INTERNAL_TOTAL_GAIN) \
    ITEM_PROC_I(ISP_INTERNAL_dgCfg__Gain) \
    ITEM_PROC_F(ISP_INTERNAL_ISPGAIN_CONTROL_GAMMA_VALUE) \
    ITEM_PROC_F(ISP_INTERNAL_LTM_CONTROL_SLOPE_VALUE) \
    ITEM_PROC_I(ISP_INTERNAL_LTM_CONTROL_ART_BL_VAL) \
    ITEM_PROC_F(ISP_INTERNAL_LTM_CONTROL_BL_VAL) \
    ITEM_PROC_F(ISP_INTERNAL_LTM_CONTROL_MAX_SLOPE_VAL) \
    ITEM_PROC_I(ISP_INTERNAL_linOffCfg__Offset) \
    ITEM_PROC_I(ISP_INTERNAL_SENSOR_ANALOG_GAIN) \
    ITEM_PROC_F(ISP_INTERNAL_SENSOR_PRE_HDR_GAIN) \
    ITEM_PROC_F(ISP_INTERNAL_ANALOG_GAIN_COMPENSATION) \
    ITEM_PROC_I(ISP_INTERNAL_SENSOR_DC_GAIN) \
    ITEM_PROC_I(ISP_INTERNAL_expStatsCfg__Hist_Thresh_01) \
    ITEM_PROC_I(ISP_INTERNAL_expStatsCfg__Hist_Thresh_12) \
    ITEM_PROC_I(ISP_INTERNAL_expStatsCfg__Hist_Thresh_23) \
    ITEM_PROC_I(ISP_INTERNAL_expStatsCfg__Hist_Thresh_34) \
    ITEM_PROC_I(ISP_INTERNAL_Collection_Correction) \
    ITEM_PROC_F(ISP_INTERNAL_SENSOR_EXPOSURE_COMP)\
    ITEM_PROC_F(ISP_INTERNAL_T0_PREPIPE)\
    ITEM_PROC_I(ISP_INTERNAL_HISTORY_SENSOR_EXPOSURE) \
    ITEM_PROC_I(ISP_INTERNAL_HISTORY_REAL_EXPOSURE) \
    ITEM_PROC_I(ISP_INTERNAL_HISTORY_SENSOR_DLO_GAIN) \
    ITEM_PROC_I(ISP_INTERNAL_HISTORY_SENSOR_DC_GAIN) \
    ITEM_PROC_I(ISP_INTERNAL_HISTORY_SENSOR_ANALOG_GAIN) \
    ITEM_PROC_F(ISP_INTERNAL_HISTORY_SENSOR_PRE_HDR_GAIN) \
    ITEM_PROC_F(ISP_INTERNAL_HISTORY_SENSOR_VIRTUAL_GAIN_T0) \
    ITEM_PROC_F(ISP_INTERNAL_HISTORY_SENSOR_VIRTUAL_GAIN_T1) \
    ITEM_PROC_F(ISP_INTERNAL_HISTORY_LTM_SENSOR_VIRTUAL_GAIN_T1) \
    ITEM_PROC_F(ISP_INTERNAL_HISTORY_LTM_SENSOR_GAIN) \
    ITEM_PROC_F(ISP_INTERNAL_HISTORY_LTM_SENSOR_EXP) \
    ITEM_PROC_F(ISP_INTERNAL_HISTORY_LTM_SENSOR_ANALOG_GAIN) \
    ITEM_PROC_I(ISP_INTERNAL_TABLES_ANALOG_GAIN_FROM_BR_PHASE_PREV) \
    ITEM_PROC_F(ISP_INTERNAL_AGAIN_OUT_DIR) \
    ITEM_PROC_I(ISP_INTERNAL_GLOBAL_NM)\
    ITEM_PROC_I(ISP_INTERNAL_MIN_EXPOSURE_AF)\
    ITEM_PROC_I(ISP_INTERNAL_MIN_AGAIN_COMP)\
    ITEM_PROC_I(ISP_INTERNAL_FRAME_COUNTER)\
    ITEM_PROC_F(ISP_INTERNAL_PINK_SUN_COMP) \
    ITEM_PROC_F(ISP_INTERNAL_CCM_MAT_0_0)\
    ITEM_PROC_F(ISP_INTERNAL_CCM_MAT_0_1)\
    ITEM_PROC_F(ISP_INTERNAL_CCM_MAT_0_2)\
    ITEM_PROC_F(ISP_INTERNAL_CCM_MAT_1_0)\
    ITEM_PROC_F(ISP_INTERNAL_CCM_MAT_1_1)\
    ITEM_PROC_F(ISP_INTERNAL_CCM_MAT_1_2)\
    ITEM_PROC_F(ISP_INTERNAL_CCM_MAT_2_0)\
    ITEM_PROC_F(ISP_INTERNAL_CCM_MAT_2_1)\
    ITEM_PROC_F(ISP_INTERNAL_CCM_MAT_2_2)\
    EMB_DATA_REGISTER_LIST(SET_INTERNAL_EMB_ID) \
    EMB_DATA_REGISTER_LIST(SET_INTERNAL_TRACE_EMB_ID)

#define GET_EMB_ID(x,y) ITEM_PROC_I(y)
#define GET_OUT_EMB_ID(x,y) ITEM_PROC_F(y##_OUT_VAL)

#ifdef LIST_NON_ISP_CFG
#undef LIST_NON_ISP_CFG
#endif
#define LIST_NON_ISP_CFG() \
    ITEM_PROC_I(ISP_VERSION)\
    ITEM_PROC_I(SENSOR_WRITE)\
    ITEM_PROC_I(AE_EXPOSURE)\
    ITEM_PROC_I(SENSOR_EXPOSURE)\
    ITEM_PROC_I(FRAME_COUNTER)\
    ITEM_PROC_I(SENSOR_FRAME_COUNTER)\
    ITEM_PROC_I(SENSOR_DBLC_CONFIG)\
    ITEM_PROC_F(SENSOR_EXPOSURE_COMP)\
    ITEM_PROC_I(AE_NM_EXP_MIN_OUT)\
    ITEM_PROC_I(AE_NM_EXP_MAX_OUT)\
    ITEM_PROC_I(AE_FINISH_OUT)\
    ITEM_PROC_I(AE_OUT_GAIN)\
    ITEM_PROC_I(AE_DLO_GAIN)\
    ITEM_PROC_I(AE_DC_GAIN)\
    ITEM_PROC_I(GAIN_IN_GAMMA)\
    ITEM_PROC_I(STATISTIC_IN_GAMMA)\
    ITEM_PROC_I(SENSOR_LPD_SPD_RATIO)\
    ITEM_PROC_I(AE_ANALOG_GAIN)\
    ITEM_PROC_I(N_FRAMES_WO_CHANGES_EXP_AGAIN)\
    ITEM_PROC_I(DBLC_FRAMES_THRESHOLD)\
    ITEM_PROC_F(WHITE_Q_PIXEL_PERCENT)\
    ITEM_PROC_F(SENSOR_PRE_HDR_GAIN)\
    ITEM_PROC_F(PREHDRGAIN_FORCE)\
    ITEM_PROC_F(ANALOG_GAIN_COMPENSATION)\
    ITEM_PROC_F(SENSOR_VIRTUAL_GAIN_T1)\
    ITEM_PROC_F(SENSOR_EV)\
    ITEM_PROC_F(AVE_BR)\
    ITEM_PROC_F(WHITE_Q)\
    ITEM_PROC_F(SNR)\
    ITEM_PROC_F(SNR_SMOOTH)\
    ITEM_PROC_F(TARGET_AVE_BR)\
    ITEM_PROC_F(ISP_CALC_LTM_CC_FROM_EV)\
    ITEM_PROC_F(AE_RED_GAIN)\
    ITEM_PROC_F(AE_GREEN_GAIN)\
    ITEM_PROC_F(AE_BLUE_GAIN)\
    ITEM_PROC_I(DISABLE_CCM)\
    ITEM_PROC_I(TPG_CCM_GAIN)\
    ITEM_PROC_F(SENSOR_RED_GAIN_DEFAULT)\
    ITEM_PROC_F(SENSOR_GREEN_GAIN_DEFAULT)\
    ITEM_PROC_F(SENSOR_BLUE_GAIN_DEFAULT)\
    ITEM_PROC_F(SENSOR_BLACK_LEVEL_DEFAULT)\
    ITEM_PROC_F(SENSOR_LONG_EXPOSURE_THRESHOLD)\
    ITEM_PROC_F(ExpStats_Hist_Thresh_01_DEFAULT)\
    ITEM_PROC_F(ExpStats_Hist_Thresh_12_DEFAULT)\
    ITEM_PROC_F(ExpStats_Hist_Thresh_23_DEFAULT)\
    ITEM_PROC_F(ExpStats_Hist_Thresh_34_DEFAULT)\
    ITEM_PROC_F(demCfg__RGGB__Sharp_Str_ud_DEFAULT)\
    ITEM_PROC_F(demCfg__RGGB__Sharp_Str_Lu_DEFAULT)\
    ITEM_PROC_F(demCfg__RGGB__Sharp_Str_Ldu_DEFAULT)\
    ITEM_PROC_F(demCfg__RGGB__Sharp_Str_Ld_DEFAULT)\
    ITEM_PROC_I(SENSOR_IN_DELAY_NM)\
    ITEM_PROC_I(SENSOR_IN_DELAY_DM)\
    ITEM_PROC_I(TPG_PART1)\
    ITEM_PROC_I(TPG_PART2)\
    ITEM_PROC_I(TEST_DATA_R)\
    ITEM_PROC_I(TEST_DATA_GR)\
    ITEM_PROC_I(TEST_DATA_B)\
    ITEM_PROC_I(TEST_DATA_GB)\
    ITEM_PROC_I(AE_NIGHT_MODE)\
    ITEM_PROC_I(AE_OUT_GLOBAL_NM)\
    ITEM_PROC_I(AE_TEST_FORCE_NM_L)\
    ITEM_PROC_I(AE_TEST_FORCE_NM_G)\
    ITEM_PROC_F(AWB_OUT_R)\
    ITEM_PROC_F(AWB_OUT_G)\
    ITEM_PROC_F(AWB_OUT_B)\
    ITEM_PROC_I(AWB_SKIP_COUNTER)\
    ITEM_PROC_I(AWB_VALID_BLOCKS)\
    ITEM_PROC_I(AWB_OUT_MODE)\
    ITEM_PROC_I(AWB_OUT_ENABLED) \
    ITEM_PROC_I(AWB_OUT_TEMP_NONCLAMP) \
    ITEM_PROC_I(AWB_OUT_TINT_NONCLAMP) \
    ITEM_PROC_I(AWB_OUT_PREV_INV_TEMP) \
    ITEM_PROC_I(AWB_OUT_PREV_TINT) \
    ITEM_PROC_I(AUTO_DUMP_OUT_ENABLED) \
    ITEM_PROC_I(AG_ENABLE) \
    ITEM_PROC_I(T1_ENABLE) \
\
    ITEM_PROC_I(ALG_TWEAK_IP)\
    ITEM_PROC_I(ALG_TWEAK_PORT)\
    ITEM_PROC_I(ALG_SIXTY_HERTZ)\
    ITEM_PROC_I(ALG_LOG_LEVEL)\
    ITEM_PROC_I(ALG_LOG_EMB)\
    ITEM_PROC_I(ALG_LOG_REGS)\
    ITEM_PROC_I(ALG_LOG_STATS)\
    ITEM_PROC_I(ALG_LOG_TEST_NUM)\
    ITEM_PROC_I(ALG_LOG_CAM)\
    ITEM_PROC_I(ALG_LOG_TO_FILE)\
    ITEM_PROC_I(ALG_DUMP_STATISTIC)\
    ITEM_PROC_I(ALG_COMMON_SATURATION)\
    ITEM_PROC_I(ALG_SENSOR_TYPE)\
    ITEM_PROC_I(CFG_VERSION)\
\
    ITEM_PROC_F(AE_IN_MIN_EXP_DM)\
    ITEM_PROC_F(AE_IN_MAX_EXP_DM)\
    ITEM_PROC_F(AE_IN_MIN_EXP_NM)\
    ITEM_PROC_F(AE_IN_MAX_EXP_NM)\
    ITEM_PROC_F(AE_IN_MIN_GAIN_DM)\
    ITEM_PROC_F(AE_IN_MAX_GAIN_DM)\
    ITEM_PROC_F(AE_IN_MIN_GAIN_NM)\
    ITEM_PROC_F(AE_IN_MAX_GAIN_NM)\
    ITEM_PROC_F(AE_IN_DEF_GAIN)\
    ITEM_PROC_F(AE_IN_MODE_THRESHOLD)\
    ITEM_PROC_F(AE_IN_TARGET_LIGHT)\
    ITEM_PROC_F(AE_IN_TARGET_INDOOR)\
    ITEM_PROC_F(AE_IN_TARGET_BR_LIGHT)\
    ITEM_PROC_F(AE_IN_TARGET_BR_NIGHT)\
    ITEM_PROC_F(AE_IN_SPEED)\
    ITEM_PROC_F(AE_IN_MODE)\
    ITEM_PROC_F(AE_IN_DARK_EXP)\
    ITEM_PROC_F(AE_IN_NIGHT_TARGET)\
    ITEM_PROC_F(AE_IN_DAY_TARGET_DELTA)\
    ITEM_PROC_I(AE_IN_GLOBAL_NM)\
    ITEM_PROC_I(AWB_IN_MODE)\
    ITEM_PROC_I(AWB_IN_CFA_PATTERN)\
    ITEM_PROC_F(AWB_IN_PIX_COUNT_THRESHOLD)\
    ITEM_PROC_F(AWB_IN_MIN_VALID_BLOCKS_RATIO)\
    ITEM_PROC_F(AWB_IN_LOW_BRIGHTNESS_THRESHOLD)\
    ITEM_PROC_F(AWB_IN_UPPER_BRIGHTNESS_THRESHOLD)\
    ITEM_PROC_F(AWB_IN_QDA_WEIGHT_0)\
    ITEM_PROC_F(AWB_IN_QDA_WEIGHT_1)\
    ITEM_PROC_F(AWB_IN_QDA_WEIGHT_2)\
    ITEM_PROC_F(AWB_IN_QDA_WEIGHT_3)\
    ITEM_PROC_F(AWB_IN_QDA_WEIGHT_4)\
    ITEM_PROC_F(AWB_IN_TEMPERATURES_0)\
    ITEM_PROC_F(AWB_IN_TEMPERATURES_1)\
    ITEM_PROC_F(AWB_IN_TEMP_RANGE_MIN)\
    ITEM_PROC_F(AWB_IN_TEMP_RANGE_MAX)\
    ITEM_PROC_F(AWB_IN_TINT_RANGE_MIN)\
    ITEM_PROC_F(AWB_IN_TINT_RANGE_MAX)\
    ITEM_PROC_F(AWB_IN_TEMP_RESULT_RANGE_MIN)\
    ITEM_PROC_F(AWB_IN_TEMP_RESULT_RANGE_MAX)\
    ITEM_PROC_F(AWB_IN_TINT_RESULT_RANGE_MIN)\
    ITEM_PROC_F(AWB_IN_TINT_RESULT_RANGE_MAX)\
    ITEM_PROC_F(AWB_IN_CONFIDENCE_THRESHOLD)\
    ITEM_PROC_F(AWB_IN_TEMP_CALIB_COLD_RG)\
    ITEM_PROC_F(AWB_IN_TEMP_CALIB_COLD_BG)\
    ITEM_PROC_F(AWB_IN_TEMP_CALIB_WARM_RG)\
    ITEM_PROC_F(AWB_IN_TEMP_CALIB_WARM_BG)\
    ITEM_PROC_F(AWB_IN_GW_MODEL_VAL_0)\
    ITEM_PROC_F(AWB_IN_GW_MODEL_VAL_1)\
    ITEM_PROC_F(AWB_IN_GW_MODEL_VAL_2)\
    ITEM_PROC_F(AWB_IN_GW_MODEL_VAL_3)\
    ITEM_PROC_F(AWB_IN_SECOND_COMPONENT_THRESHOLD)\
    ITEM_PROC_F(AWB_IN_HULL_DIST_THRESH)\
    ITEM_PROC_F(AWB_IN_Q6)\
    ITEM_PROC_F(AWB_IN_AVE_LR)\
    ITEM_PROC_F(AWB_IN_AVE_LG)\
    ITEM_PROC_F(AWB_IN_AVE_LB)\
    ITEM_PROC_F(AWB_IN_SPEED)\
    ITEM_PROC_I(CONTROLS_IN_B_STEP)\
    ITEM_PROC_I(CONTROLS_IN_C_STEP)\
    ITEM_PROC_I(CONTROLS_IN_B_VAL)\
    ITEM_PROC_I(CONTROLS_IN_C_VAL)\
    ITEM_PROC_I(CONTROLS_OUT_B_VAL)\
    ITEM_PROC_I(CONTROLS_OUT_C_VAL)\
    ITEM_PROC_F(ISPGAIN_CONTROL_IN_MAX_GAIN)\
    ITEM_PROC_F(ISPGAIN_CONTROL_GAMMA_VALUE)\
    ITEM_PROC_I(ISPGAIN_CONTROL_GAMMA_ENABLE)\
    ITEM_PROC_I(ISPGAIN_CONTROL_WEINER_ENABLE)\
    ITEM_PROC_I(LTM_CONTROL_UPDATE_ENABLE)\
    ITEM_PROC_F(LTM_CONTROL_DEFAULT_CURVE_SLOPE)\
    ITEM_PROC_F(LTM_CONTROL_CURVE_SLOPE)\
    ITEM_PROC_F(LTM_CONTROL_LOW_CURVE_SLOPE)\
    ITEM_PROC_F(LTM_CONTROL_HIGH_CURVE_SLOPE)\
    ITEM_PROC_F(LTM_CONTROL_LOW_THRESH)\
    ITEM_PROC_F(LTM_CONTROL_HIGH_THRESH)\
    ITEM_PROC_I(LTM_CONTROL_ART_BLACK_LEVEL)\
    ITEM_PROC_F(LTM_CONTROL_BL_SCALE)\
    ITEM_PROC_F(LTM_CONTROL_DEFAULT_MAX_SLOPE)\
    ITEM_PROC_I(LTM_CONTROL_ENABLE_MAX_SLOPE)\
    ITEM_PROC_F(LTM_CONTROL_PREV_MAX_SLOPE)\
    ITEM_PROC_F(BLACK_LEVEL_RESIDUE)\
    ITEM_PROC_F(DECOMP_BLACK_LEVEL)\
    ITEM_PROC_I(ROI_X_VAL)\
    ITEM_PROC_I(ROI_Y_VAL)\
    ITEM_PROC_I(ROI_WIDTH_VAL)\
    ITEM_PROC_I(ROI_HEIGHT_VAL)\
    ITEM_PROC_I(TPG_IN_VAL)\
    ITEM_PROC_I(TPG_OUT_VAL)\
    ITEM_PROC_I(MODES_MV_IN_VAL)\
    ITEM_PROC_I(MODES_MV_OUT_VAL)\
    ITEM_PROC_I(MODES_TEST_IN_VAL)\
    ITEM_PROC_I(MODES_TEST_OUT_VAL)\
    ITEM_PROC_F(TEMPERATURE_IN_TSTEP)\
    ITEM_PROC_F(TEMPERATURE_OUT_VAL)\
    ITEM_PROC_F(PINK_SUN_COMP_OUT_VAL)\
    ITEM_PROC_F(ANTI_FLICKER_EXPOSURE_ENABLED)\
    ITEM_PROC_F(EXP_MS_CONVERTION)\
    ITEM_PROC_F(NR_POWER_COEFF)\
    ITEM_PROC_F(NR_RSHARP_COEFF)\
    ITEM_PROC_F(ANTI_FLICKER_50_EXP_MS_0)\
    ITEM_PROC_F(ANTI_FLICKER_50_EXP_MS_1)\
    ITEM_PROC_F(ANTI_FLICKER_50_EXP_MS_2)\
    ITEM_PROC_F(ANTI_FLICKER_50_EXP_MS_3)\
    ITEM_PROC_F(ANTI_FLICKER_50_EXP_MS_4)\
    ITEM_PROC_F(ANTI_FLICKER_50_EXP_MS_5)\
    ITEM_PROC_F(ANTI_FLICKER_60_EXP_MS_0)\
    ITEM_PROC_F(ANTI_FLICKER_60_EXP_MS_1)\
    ITEM_PROC_F(ANTI_FLICKER_60_EXP_MS_2)\
    ITEM_PROC_F(ANTI_FLICKER_60_EXP_MS_3)\
    ITEM_PROC_F(ANTI_FLICKER_60_EXP_MS_4)\
    ITEM_PROC_F(ANTI_FLICKER_60_EXP_MS_5)\
    ITEM_PROC_I(TABLES_ANALOG_GAIN_FROM_BR) \
    ITEM_PROC_I(TABLES_ANALOG_GAIN_FROM_NM) \
    ITEM_PROC_I(TABLES_ANALOG_GAIN_FROM_BR_PHASE) \
    ITEM_PROC_I(TABLES_ANALOG_GAIN_FROM_BR_PHASE_PREV) \
    ITEM_PROC_F(TABLES_ANALOG_GAIN_COMP) \
    ITEM_PROC_F(TABLES_AF_50hz) \
    ITEM_PROC_F(TABLES_AF_60hz) \
    ITEM_PROC_F(TABLES_AWB_PLANCK_TEMP_TABLE)\
    ITEM_PROC_F(TABLES_AWB_PLANCK_LRG_TABLE)\
    ITEM_PROC_F(TABLES_AWB_PLANCK_LBG_TABLE)\
    ITEM_PROC_F(TABLES_AWB_GRAY_HULL_TEMP)\
    ITEM_PROC_F(TABLES_AWB_GRAY_HULL_TINT)\
    ITEM_PROC_F(TABLES_CCM_INTERP_TEMP)\
    ITEM_PROC_F(TABLES_CCM_INTERP_TEMP_STR)\
    ITEM_PROC_F(TABLES_CCM_INTERP_LINK_TEMP_CCM)\
    ITEM_PROC_F(TABLES_CCM_INTERP_1_CCM)\
    ITEM_PROC_F(TABLES_CCM_INTERP_2_CCM)\
    ITEM_PROC_F(TABLES_CCM_INTERP_3_CCM)\
    ITEM_PROC_F(TABLES_CCM_INTERP_4_CCM)\
    ITEM_PROC_F(TABLES_CCM_INTERP_5_CCM)\
    ITEM_PROC_F(TABLES_CCM_INTERP_6_CCM)\
    ITEM_PROC_F(TABLES_CCM_INTERP_7_CCM)\
    ITEM_PROC_F(CCM_INTERP_NEGATIVE_TINT_STR)\
    ITEM_PROC_F(TABLES_ANR_TEMP_TABLE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_1_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_2_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_3_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_4_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_5_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_1_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_2_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_3_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_4_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_5_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_1_CFA0_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_1_CFA1_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_1_CFA2_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_1_CFA3_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_2_CFA0_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_2_CFA1_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_2_CFA2_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_2_CFA3_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_3_CFA0_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_3_CFA1_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_3_CFA2_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_3_CFA3_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_4_CFA0_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_4_CFA1_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_4_CFA2_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_4_CFA3_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_5_CFA0_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_5_CFA1_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_5_CFA2_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_5_CFA3_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_1_CFA0_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_1_CFA1_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_1_CFA2_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_1_CFA3_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_2_CFA0_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_2_CFA1_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_2_CFA2_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_2_CFA3_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_3_CFA0_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_3_CFA1_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_3_CFA2_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_3_CFA3_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_4_CFA0_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_4_CFA1_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_4_CFA2_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_4_CFA3_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_5_CFA0_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_5_CFA1_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_5_CFA2_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_5_CFA3_X_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_1_CFA0_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_1_CFA1_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_1_CFA2_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_1_CFA3_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_2_CFA0_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_2_CFA1_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_2_CFA2_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_2_CFA3_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_3_CFA0_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_3_CFA1_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_3_CFA2_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_3_CFA3_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_4_CFA0_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_4_CFA1_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_4_CFA2_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_4_CFA3_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_5_CFA0_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_5_CFA1_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_5_CFA2_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_0_TEMP_5_CFA3_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_1_CFA0_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_1_CFA1_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_1_CFA2_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_1_CFA3_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_2_CFA0_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_2_CFA1_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_2_CFA2_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_2_CFA3_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_3_CFA0_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_3_CFA1_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_3_CFA2_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_3_CFA3_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_4_CFA0_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_4_CFA1_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_4_CFA2_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_4_CFA3_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_5_CFA0_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_5_CFA1_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_5_CFA2_Y_PROFILE)\
    ITEM_PROC_F(TABLES_ANR_INTERP_EP_1_TEMP_5_CFA3_Y_PROFILE)\
    ITEM_PROC_I(TABLES_ANR_ID) \
    ITEM_PROC_F(AGAIN_OUT_DIR) \
    ITEM_PROC_I(HISTORY_ADAPTIVE_SENSOR_EXPOSURE)\
    ITEM_PROC_I(HISTORY_ADAPTIVE_REAL_EXPOSURE)\
    ITEM_PROC_I(HISTORY_ADAPTIVE_SENSOR_DLO_GAIN)\
    ITEM_PROC_I(HISTORY_ADAPTIVE_SENSOR_DC_GAIN)\
    ITEM_PROC_I(HISTORY_ADAPTIVE_SENSOR_ANALOG_GAIN)\
    ITEM_PROC_F(HISTORY_ADAPTIVE_SENSOR_PRE_HDR_GAIN)\
    ITEM_PROC_F(HISTORY_SENSOR_VIRTUAL_GAIN_T0)\
    ITEM_PROC_F(HISTORY_SENSOR_VIRTUAL_GAIN_T1)\
    ITEM_PROC_F(HISTORY_LTM_SENSOR_VIRTUAL_GAIN_T1)\
    ITEM_PROC_F(HISTORY_LTM_SENSOR_GAIN)\
    ITEM_PROC_F(HISTORY_LTM_SENSOR_EXP)\
    ITEM_PROC_F(HISTORY_LTM_SENSOR_ANALOG_GAIN)\
    ITEM_PROC_F(ALG_CCM_MAT_0_0)\
    ITEM_PROC_F(ALG_CCM_MAT_0_1)\
    ITEM_PROC_F(ALG_CCM_MAT_0_2)\
    ITEM_PROC_F(ALG_CCM_MAT_1_0)\
    ITEM_PROC_F(ALG_CCM_MAT_1_1)\
    ITEM_PROC_F(ALG_CCM_MAT_1_2)\
    ITEM_PROC_F(ALG_CCM_MAT_2_0)\
    ITEM_PROC_F(ALG_CCM_MAT_2_1)\
    ITEM_PROC_F(ALG_CCM_MAT_2_2)\
    ITEM_PROC_F(ALG_FRAME_COUNTER)\
    ITEM_PROC_F(ALG_FRAME_DUMP_INIT_DELAY)\
    ITEM_PROC_F(ALG_FRAME_DUMP_AMOUNT)\
    ITEM_PROC_F(ALG_FRAME_DUMP_FREQUENCY)\
    ITEM_PROC_F(ADD_TO_SENSOR_AE_EXPOSURE_OUT_VAL)\
    ITEM_PROC_F(ADD_TO_SENSOR_ISP_VERSION_OUT_VAL)\
    ITEM_PROC_F(ADD_TO_SENSOR_SENSOR_VIRTUAL_GAIN_T0_OUT_VAL)\
    ITEM_PROC_F(ADD_TO_SENSOR_SENSOR_VIRTUAL_GAIN_T1_OUT_VAL)\
    ITEM_PROC_F(SAT_SHARP_OFFSET)\
    ITEM_PROC_F(SAT_SHARP_SLOPE)\
    ITEM_PROC_F(SAT_TARGET_SNR)\
    ITEM_PROC_F(SAT_ALGO)\
    ITEM_PROC_F(SATURATION_OUT_VAL)\
    ITEM_PROC_I(TOOLS_DUMP_SETTINGS)\
    ITEM_PROC_I(DBLC_PERIOD)\
    ITEM_PROC_I(DBLC_CONFIG_ON)\
    ITEM_PROC_I(DBLC_CONFIG_OFF)\
    EMB_DATA_REGISTER_LIST(GET_EMB_ID)\
    EMB_DATA_REGISTER_LIST(GET_OUT_EMB_ID)\
    ITEM_PROC_I(EMB_LINE_WB_B_HCG)\
    ITEM_PROC_I(EMB_LINE_WB_GB_HCG)\
    ITEM_PROC_I(EMB_LINE_WB_GR_HCG)\
    ITEM_PROC_I(EMB_LINE_WB_R_HCG)\
    ITEM_PROC_I(EMB_LINE_WB_B_LCG)\
    ITEM_PROC_I(EMB_LINE_WB_GB_LCG)\
    ITEM_PROC_I(EMB_LINE_WB_GR_LCG)\
    ITEM_PROC_I(EMB_LINE_WB_R_LCG)\
    ITEM_PROC_I(EMB_LINE_WB_B_SPD)\
    ITEM_PROC_I(EMB_LINE_WB_GB_SPD)\
    ITEM_PROC_I(EMB_LINE_WB_GR_SPD)\
    ITEM_PROC_I(EMB_LINE_WB_R_SPD)\
    ITEM_PROC_I(EMB_LINE_WB_B_VS)\
    ITEM_PROC_I(EMB_LINE_WB_GB_VS)\
    ITEM_PROC_I(EMB_LINE_WB_GR_VS)\
    ITEM_PROC_I(EMB_LINE_WB_R_VS)\
    ITEM_PROC_I(EMB_LINE_HTS)\
    ITEM_PROC_I(EMB_LINE_VTS)\
    ITEM_PROC_I(EMB_LINE_EXP_CUR)\
    ITEM_PROC_I(EMB_LINE_EXP_CUR_SPD)\
    ITEM_PROC_I(EMB_LINE_EXP_CUR_VS)


#ifndef OUT_PARAM_MACRO
#define OUT_PARAM_MACRO(A, B, NAME) {A,B, NAME##_IN_FREQ, NAME##_IN_PHASE},

#define AE_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_AE_EXPOSURE,AE_EXPOSURE, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_GAIN, AE_OUT_GAIN, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_GLOBAL_NM, AE_OUT_GLOBAL_NM, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_AE_NM_EXP_MIN, AE_NM_EXP_MIN_OUT, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_AE_NM_EXP_MAX, AE_NM_EXP_MAX_OUT, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_AE_FINISH, AE_FINISH_OUT, NAME)

#define AWB_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_AWB_R_SENSOR, AE_RED_GAIN, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_AWB_G_SENSOR, AE_GREEN_GAIN, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_AWB_B_SENSOR, AE_BLUE_GAIN, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_AWB_R, AWB_OUT_R, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_AWB_G, AWB_OUT_G, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_AWB_B, AWB_OUT_B, NAME)\
    OUT_PARAM_MACRO(AWB_IN_ENABLED, AWB_OUT_ENABLED, NAME)\
    OUT_PARAM_MACRO(AWB_IN_MODE, AWB_OUT_MODE, NAME)


#define AUTO_DUMP_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_SENSOR_EXPOSURE, SENSOR_EXPOSURE, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_SENSOR_DC_GAIN, AE_DC_GAIN, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_FRAME_COUNTER, ALG_FRAME_COUNTER, NAME)\
    OUT_PARAM_MACRO(AUTO_DUMP_IN_ENABLED, AUTO_DUMP_OUT_ENABLED, NAME)\

#define CONTROLS_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_CONTROLS_B_VAL, CONTROLS_OUT_B_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_CONTROLS_C_VAL, CONTROLS_OUT_C_VAL, NAME)

#ifdef MAGNA_PSA
#define SINTER_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_SINTER_VAL, sinterCfg__Thresh_Long, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TABLE_ID, TABLES_ANR_ID, NAME)
#else
#define SINTER_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_SINTER_SCALE_0, nsf4Cfg__tnScale_0, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_SINTER_SCALE_1, nsf4Cfg__tnScale_1, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_SINTER_SCALE_2, nsf4Cfg__tnScale_2, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TABLE_ID, TABLES_ANR_ID, NAME)
#endif
#define TPG_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_TPG_VAL, TPG_OUT_VAL, NAME)

#define TEMPERATURE_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_TEMPERATURE, TEMPERATURE_OUT_VAL, NAME)


#define EMB_LINE_TRACE_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_EXPOSURE, EMB_LINE_EXPOSURE_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_DLO_GAIN, EMB_LINE_DLO_GAIN_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_DC_GAIN, EMB_LINE_DC_GAIN_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_ANALOG_GAIN, EMB_LINE_ANALOG_GAIN_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_ANALOG_GAIN_COARSE, EMB_LINE_ANALOG_GAIN_COARSE_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_GREEN_GAIN, EMB_LINE_GREEN_GAIN_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_RED_GAIN, EMB_LINE_RED_GAIN_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_BLUE_GAIN, EMB_LINE_BLUE_GAIN_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_CURRENT_TEMPERATERE, EMB_LINE_CURRENT_TEMPERATERE_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_TEMPSENS0_CALIB1, EMB_LINE_TEMPSENS0_CALIB1_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_TEMPSENS0_CALIB2, EMB_LINE_TEMPSENS0_CALIB2_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_RT1T2, EMB_LINE_RT1T2_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_RT2T3, EMB_LINE_RT2T3_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_RT1T4, EMB_LINE_RT1T4_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_AE_EXPOSURE, EMB_LINE_AE_EXPOSURE_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_DCG_TRIM, EMB_LINE_DCG_TRIM_OUT_VAL, NAME)\
\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_ISP_VERSION, EMB_LINE_ISP_VERSION_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_SENSOR_VERSION, EMB_LINE_SENSOR_VERSION_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_SENSOR_VIRTUAL_GAIN_T0, EMB_LINE_SENSOR_VIRTUAL_GAIN_T0_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_SENSOR_VIRTUAL_GAIN_T1, EMB_LINE_SENSOR_VIRTUAL_GAIN_T1_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_DBLC_CONFIG, EMB_LINE_DBLC_CONFIG_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_TPG_PART1, EMB_LINE_TPG_PART1_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_TPG_PART2, EMB_LINE_TPG_PART2_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_TEST_DATA_R, EMB_LINE_TEST_DATA_R_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_TEST_DATA_GR, EMB_LINE_TEST_DATA_GR_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_TEST_DATA_B, EMB_LINE_TEST_DATA_B_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_TEST_DATA_GB, EMB_LINE_TEST_DATA_GB_OUT_VAL, NAME)\
\
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_VT_PIX_CLK_DIV, EMB_LINE_VT_PIX_CLK_DIV_OUT_VAL, NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_PRE_PLL_CLK_DIV, EMB_LINE_PRE_PLL_CLK_DIV_OUT_VAL, NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_PLL_MULTIPLIER, EMB_LINE_PLL_MULTIPLIER_OUT_VAL, NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_FLL, EMB_LINE_FLL_OUT_VAL, NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_LLPCK, EMB_LINE_LLPCK_OUT_VAL, NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_DBLC_BTM_ROW, EMB_LINE_DBLC_BTM_ROW_OUT_VAL, NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_Y_ADDR_START, EMB_LINE_Y_ADDR_START_OUT_VAL, NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_Y_ADDR_END, EMB_LINE_Y_ADDR_END_OUT_VAL, NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_VERTICAL_FLIP, EMB_LINE_VERTICAL_FLIP_OUT_VAL, NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_SE_MODE, EMB_LINE_SE_MODE_OUT_VAL, NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_AB_PERIOD, EMB_LINE_AB_PERIOD_OUT_VAL, NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_T3T4_SH_ADV, EMB_LINE_T3T4_SH_ADV_OUT_VAL, NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_FIT, EMB_LINE_FIT_OUT_VAL, NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_TRACE_EMB_LINE_FIT4, EMB_LINE_FIT4_OUT_VAL, NAME) \


#define MODES_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_MVMODE_VAL, MODES_MV_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TESTMODE_VAL, MODES_TEST_OUT_VAL, NAME)


#define AGAIN_CONTROL_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_SENSOR_ANALOG_GAIN, AE_ANALOG_GAIN, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_TABLES_ANALOG_GAIN_FROM_BR_PHASE_PREV, TABLES_ANALOG_GAIN_FROM_BR_PHASE_PREV, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_AGAIN_OUT_DIR, AGAIN_OUT_DIR, NAME)

#define PREHDRGAIN_CONTROL_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_SENSOR_PRE_HDR_GAIN, SENSOR_PRE_HDR_GAIN, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_ANALOG_GAIN_COMPENSATION, ANALOG_GAIN_COMPENSATION, NAME)

#define AGAIN_COMPENSATE_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_SENSOR_VIRTUAL_GAIN_T1, SENSOR_VIRTUAL_GAIN_T1, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_SENSOR_EXPOSURE, SENSOR_EXPOSURE, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_DLO_GAIN, AE_DLO_GAIN, NAME)\

#define CCM_INTERP_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_CCM_MAT_0_0, ALG_CCM_MAT_0_0, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_CCM_MAT_0_1, ALG_CCM_MAT_0_1, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_CCM_MAT_0_2, ALG_CCM_MAT_0_2, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_CCM_MAT_1_0, ALG_CCM_MAT_1_0, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_CCM_MAT_1_1, ALG_CCM_MAT_1_1, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_CCM_MAT_1_2, ALG_CCM_MAT_1_2, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_CCM_MAT_2_0, ALG_CCM_MAT_2_0, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_CCM_MAT_2_1, ALG_CCM_MAT_2_1, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_CCM_MAT_2_2, ALG_CCM_MAT_2_2, NAME)\

#ifdef MAGNA_PSA
#define STATISTIC_UPDATE_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_expStatsCfg__Hist_Thresh_01, expStatsCfg__Hist_Thresh_01, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_expStatsCfg__Hist_Thresh_12, expStatsCfg__Hist_Thresh_12, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_expStatsCfg__Hist_Thresh_23, expStatsCfg__Hist_Thresh_23, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_expStatsCfg__Hist_Thresh_34, expStatsCfg__Hist_Thresh_34, NAME)
#endif

#define PINK_SUN_COMPENSATE_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_PINK_SUN_COMP, PINK_SUN_COMP_OUT_VAL, NAME)\

#ifdef MAGNA_PSA
#define ISPGAIN_CONTROL_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_dgCfg__Gain, dgCfg__Gain, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_linOffCfg__Offset, linOffCfg__Offset, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_Collection_Correction, toneMapCfg__Collection_Correction, NAME)
#else
#define ISPGAIN_CONTROL_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_dgCfg__Gain, dgCfg__Gain, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_ISPGAIN_CONTROL_GAMMA_VALUE, ISPGAIN_CONTROL_GAMMA_VALUE, NAME)
#endif

#ifdef MAGNA_PSA
#define LTM_CONTROL_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_LTM_CONTROL_SLOPE_VALUE, LTM_CONTROL_CURVE_SLOPE, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_LTM_CONTROL_ART_BL_VAL, wbCfg__offset, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_LTM_CONTROL_BL_VAL, toneMapCfg__Black_Level, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_LTM_CONTROL_MAX_SLOPE_VAL, LTM_CONTROL_PREV_MAX_SLOPE, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_LTM_CONTROL_MAX_SLOPE_VAL, toneMapCfg__Iridix__Slope_Max, NAME)
#else
#define LTM_CONTROL_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_LTM_CONTROL_SLOPE_VALUE, LTM_CONTROL_CURVE_SLOPE, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_LTM_CONTROL_ART_BL_VAL, wbCfg__offset, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_LTM_CONTROL_BL_VAL, glbceCfg__blackLevel, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_LTM_CONTROL_MAX_SLOPE_VAL, LTM_CONTROL_PREV_MAX_SLOPE, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_LTM_CONTROL_MAX_SLOPE_VAL, glbceCfg__maxSlopeLimit, NAME)
#endif

#define EV_CALC_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_SENSOR_EV, SENSOR_EV, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_CALC_LTM_CC_FROM_EV, ISP_CALC_LTM_CC_FROM_EV, NAME)

#define ADD_TO_SENSOR_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_ADD_TO_SENSOR_AE_EXPOSURE, ADD_TO_SENSOR_AE_EXPOSURE_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_ADD_TO_SENSOR_ISP_VERSION, ADD_TO_SENSOR_ISP_VERSION_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_ADD_TO_SENSOR_SENSOR_VIRTUAL_GAIN_T0, ADD_TO_SENSOR_SENSOR_VIRTUAL_GAIN_T0_OUT_VAL, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_ADD_TO_SENSOR_SENSOR_VIRTUAL_GAIN_T1, ADD_TO_SENSOR_SENSOR_VIRTUAL_GAIN_T1_OUT_VAL, NAME)

#define SATURATION_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_SATURATION, SATURATION_OUT_VAL, NAME)\

#ifdef MAGNA_PSA
#define SHARPNESS_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_demCfg__RGGB__Sharp_Str_ud, demCfg__RGGB__Sharp_Str_ud, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_demCfg__RGGB__Sharp_Str_Lu, demCfg__RGGB__Sharp_Str_Lu, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_demCfg__RGGB__Sharp_Str_Ldu, demCfg__RGGB__Sharp_Str_Ldu, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_demCfg__RGGB__Sharp_Str_Ld, demCfg__RGGB__Sharp_Str_Ld, NAME)
#else
#define SHARPNESS_OUT(NAME) \
    /*STUB*/ OUT_PARAM_MACRO(ISP_INTERNAL_demCfg__RGGB__Sharp_Str_ud, ISP_INTERNAL_demCfg__RGGB__Sharp_Str_ud, NAME)\
    /*STUB*/ OUT_PARAM_MACRO(ISP_INTERNAL_demCfg__RGGB__Sharp_Str_Lu, ISP_INTERNAL_demCfg__RGGB__Sharp_Str_Lu, NAME)\
    /*STUB*/ OUT_PARAM_MACRO(ISP_INTERNAL_demCfg__RGGB__Sharp_Str_Ldu, ISP_INTERNAL_demCfg__RGGB__Sharp_Str_Ldu, NAME)\
    /*STUB*/ OUT_PARAM_MACRO(ISP_INTERNAL_demCfg__RGGB__Sharp_Str_Ld, ISP_INTERNAL_demCfg__RGGB__Sharp_Str_Ld, NAME)
#endif

#define DBLC_CONTROL_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_DBLC_CONTROL, SENSOR_DBLC_CONFIG, NAME)\

#define HISTORY_ADAPTIVE_OUT(NAME) \
    OUT_PARAM_MACRO(ISP_INTERNAL_HISTORY_SENSOR_EXPOSURE, HISTORY_ADAPTIVE_SENSOR_EXPOSURE, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_HISTORY_REAL_EXPOSURE, HISTORY_ADAPTIVE_REAL_EXPOSURE, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_HISTORY_SENSOR_DLO_GAIN, HISTORY_ADAPTIVE_SENSOR_DLO_GAIN, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_HISTORY_SENSOR_DC_GAIN, HISTORY_ADAPTIVE_SENSOR_DC_GAIN, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_HISTORY_SENSOR_ANALOG_GAIN, HISTORY_ADAPTIVE_SENSOR_ANALOG_GAIN, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_HISTORY_SENSOR_PRE_HDR_GAIN, HISTORY_ADAPTIVE_SENSOR_PRE_HDR_GAIN, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_HISTORY_SENSOR_VIRTUAL_GAIN_T0, HISTORY_SENSOR_VIRTUAL_GAIN_T0, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_HISTORY_SENSOR_VIRTUAL_GAIN_T1, HISTORY_SENSOR_VIRTUAL_GAIN_T1, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_HISTORY_LTM_SENSOR_VIRTUAL_GAIN_T1, HISTORY_LTM_SENSOR_VIRTUAL_GAIN_T1, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_HISTORY_LTM_SENSOR_GAIN, HISTORY_LTM_SENSOR_GAIN, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_HISTORY_LTM_SENSOR_EXP, HISTORY_LTM_SENSOR_EXP, NAME)\
    OUT_PARAM_MACRO(ISP_INTERNAL_HISTORY_LTM_SENSOR_ANALOG_GAIN, HISTORY_LTM_SENSOR_ANALOG_GAIN, NAME)\

#ifdef NON_LOGABLE_PARAMETERS
#undef NON_LOGABLE_PARAMETERS
#endif
#define NON_LOGABLE_PARAMETERS() \
    ITEM_PROC(ISP_INTERNAL_SENSOR_ANALOG_GAIN)\
    ITEM_PROC(EMB_LINE_DLO_GAIN_OUT_VAL)\
    ITEM_PROC(EMB_LINE_DC_GAIN_OUT_VAL)\
    ITEM_PROC(EMB_LINE_GREEN_GAIN_OUT_VAL)\
    ITEM_PROC(EMB_LINE_RED_GAIN_OUT_VAL)\
    ITEM_PROC(EMB_LINE_BLUE_GAIN_OUT_VAL)\
    ITEM_PROC(EMB_LINE_CURRENT_TEMPERATERE_OUT_VAL)\
    ITEM_PROC(EMB_LINE_TEMPSENS0_CALIB1_OUT_VAL)\
    ITEM_PROC(EMB_LINE_TEMPSENS0_CALIB2_OUT_VAL)\
    ITEM_PROC(EMB_LINE_RT1T2_OUT_VAL)\
    ITEM_PROC(EMB_LINE_RT2T3_OUT_VAL)\
    ITEM_PROC(EMB_LINE_RT1T4_OUT_VAL)\
    ITEM_PROC(EMB_LINE_ISP_VERSION_OUT_VAL)\
    ITEM_PROC(EMB_LINE_AE_EXPOSURE_OUT_VAL)\
    ITEM_PROC(EMB_LINE_DCG_TRIM_OUT_VAL)\
    ITEM_PROC(EMB_LINE_SENSOR_VIRTUAL_GAIN_T0_OUT_VAL)\
    ITEM_PROC(EMB_LINE_SENSOR_VIRTUAL_GAIN_T1_OUT_VAL)\
    ITEM_PROC(EMB_LINE_DBLC_CONFIG_OUT_VAL)\
    ITEM_PROC(EMB_LINE_TPG_PART1_OUT_VAL)\
    ITEM_PROC(EMB_LINE_TPG_PART2_OUT_VAL)\
    ITEM_PROC(EMB_LINE_TEST_DATA_R_OUT_VAL)\
    ITEM_PROC(EMB_LINE_TEST_DATA_GR_OUT_VAL)\
    ITEM_PROC(EMB_LINE_TEST_DATA_B_OUT_VAL)\
    ITEM_PROC(EMB_LINE_TEST_DATA_GB_OUT_VAL)\
    ITEM_PROC(EMB_LINE_VT_PIX_CLK_DIV_OUT_VAL)\
    ITEM_PROC(EMB_LINE_PRE_PLL_CLK_DIV_OUT_VAL)\
    ITEM_PROC(EMB_LINE_PLL_MULTIPLIER_OUT_VAL)\
    ITEM_PROC(EMB_LINE_FLL_OUT_VAL)\
    ITEM_PROC(EMB_LINE_LLPCK_OUT_VAL)\
    ITEM_PROC(EMB_LINE_DBLC_BTM_ROW_OUT_VAL)\
    ITEM_PROC(EMB_LINE_Y_ADDR_START_OUT_VAL)\
    ITEM_PROC(EMB_LINE_Y_ADDR_END_OUT_VAL)\
    ITEM_PROC(EMB_LINE_VERTICAL_FLIP_OUT_VAL)\
    ITEM_PROC(EMB_LINE_SE_MODE_OUT_VAL)\
    ITEM_PROC(EMB_LINE_AB_PERIOD_OUT_VAL)\
    ITEM_PROC(EMB_LINE_T3T4_SH_ADV_OUT_VAL)\
    ITEM_PROC(EMB_LINE_FIT_OUT_VAL)\
    ITEM_PROC(EMB_LINE_FIT4_OUT_VAL)\


#ifdef LIST_OF_BUFFERS_REQUIRE_PARAMS
#undef LIST_OF_BUFFERS_REQUIRE_PARAMS
#endif
#ifdef MAGNA_PSA
#define LIST_OF_BUFFERS_REQUIRE_PARAMS() \
    ITEM_PROC(AE_EXPOSURE)\
    ITEM_PROC(SENSOR_EXPOSURE)\
    ITEM_PROC(SENSOR_EV)\
    ITEM_PROC(toneMapCfg__Collection_Correction)\
    ITEM_PROC(AE_DLO_GAIN)\
    ITEM_PROC(AE_DC_GAIN)\
    ITEM_PROC(AE_ANALOG_GAIN)\
    ITEM_PROC(SENSOR_PRE_HDR_GAIN)\
    ITEM_PROC(HISTORY_SENSOR_VIRTUAL_GAIN_T0)
#else
#define LIST_OF_BUFFERS_REQUIRE_PARAMS() \
    ITEM_PROC(AE_EXPOSURE)\
    ITEM_PROC(SENSOR_EXPOSURE)\
    ITEM_PROC(SENSOR_EV)\
    ITEM_PROC(AE_DLO_GAIN)\
    ITEM_PROC(AE_DC_GAIN)\
    ITEM_PROC(AE_ANALOG_GAIN)\
    ITEM_PROC(SENSOR_PRE_HDR_GAIN)\
    ITEM_PROC(HISTORY_SENSOR_VIRTUAL_GAIN_T0)\
    ITEM_PROC(ISP_INTERNAL_EMB_LINE_RED_GAIN)\
    ITEM_PROC(ISP_INTERNAL_EMB_LINE_GREEN_GAIN)\
    ITEM_PROC(ISP_INTERNAL_EMB_LINE_BLUE_GAIN)\
    ITEM_PROC(AWB_IN_AVE_LR)\
    ITEM_PROC(AWB_IN_AVE_LG)\
    ITEM_PROC(AWB_IN_AVE_LB)
#endif




#endif

/* PRQA S 3453 -- */

#endif /*ITEMS_H*/
