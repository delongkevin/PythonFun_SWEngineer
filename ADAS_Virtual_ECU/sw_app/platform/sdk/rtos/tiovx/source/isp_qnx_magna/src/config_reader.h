/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           config_reader.h
 *  @brief          Interface of config reading functions
 *
 *  @version        2.52
 *  @author         Mikhail Vakhrushev & Alexander Ronzhin
 *  @date           23.09.2019
 *
 * =========================================================================
 *
 *  @par          Change History:
 *
 * ========================================================================= */

#ifndef CONFIG_READER_H
#define CONFIG_READER_H

/* PRQA S 1055 ++ */
/* PRQA S 3852 ++ */
/* PRQA S 3854 ++ */
/* PRQA S 3856 ++ */
/* PRQA S 3834 ++ */
/* PRQA S 3840 ++ */
/* PRQA S 3844 ++ */
/* PRQA S 1442 ++ */
/* PRQA S 0491 ++ */
/* PRQA S 3138 ++ */
/* PRQA S 3480 ++ */
/* PRQA S 3450 ++ */
/* PRQA S 0781 ++ */
/* PRQA S 0739 ++ */
/* PRQA S 0602 ++ */

#include "../public/cogent/cogent_api.h"
#include <stdint.h>
extern const char* get_string_from_id(uint32_t id);

typedef struct
{
    const char* name;
    uint32_t id;
} read_cfg_string_t;


static inline void set_val_to_struct(const char* line, int64_t val, uint32_t id, uint32_t y, uint32_t x, struct ISP_config* cfg)
{
    switch (id)
    {
    case ccmCfg__offsets:
        // if (cfg->ccmCfg.offsets != NULL)
            cfg->ccmCfg.offsets[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->ccmCfg.offsets = NULL\n");
        break;
    case ccmCfg__weights:
        // if (cfg->ccmCfg.weights != NULL)
            cfg->ccmCfg.weights[y][x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->ccmCfg.weights = NULL\n");
        break;
    case cfaCfg__bypass:
        // if (cfg->cfaCfg.bypass != NULL)
            cfg->cfaCfg.bypass[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->cfaCfg.bypass = NULL\n");
        break;
    case cfaCfg__coeff:
        // if (cfg->cfaCfg.coeff != NULL)
            cfg->cfaCfg.coeff[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->cfaCfg.coeff = NULL\n");
        break;
    case cfaCfg__coreBlendMode:
        // if (cfg->cfaCfg.coreBlendMode != NULL)
            cfg->cfaCfg.coreBlendMode[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->cfaCfg.coreBlendMode = NULL\n");
        break;
    case cfaCfg__coreSel:
        // if (cfg->cfaCfg.coreSel != NULL)
            cfg->cfaCfg.coreSel[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->cfaCfg.coreSel = NULL\n");
        break;
    case cfaCfg__gradHzPh:
        // if (cfg->cfaCfg.gradHzPh != NULL)
            cfg->cfaCfg.gradHzPh[y][x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->cfaCfg.gradHzPh = NULL\n");
        break;
    case cfaCfg__gradVtPh:
        // if (cfg->cfaCfg.gradVtPh != NULL)
            cfg->cfaCfg.gradVtPh[y][x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->cfaCfg.gradVtPh = NULL\n");
        break;
    case cfaCfg__intsBitField:
        // if (cfg->cfaCfg.intsBitField != NULL)
            cfg->cfaCfg.intsBitField[y][x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->cfaCfg.intsBitField = NULL\n");
        break;
    case cfaCfg__intsShiftPh:
        // if (cfg->cfaCfg.intsShiftPh != NULL)
            cfg->cfaCfg.intsShiftPh[y][x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->cfaCfg.intsShiftPh = NULL\n");
        break;
    case cfaCfg__thr:
        // if (cfg->cfaCfg.thr != NULL)
            cfg->cfaCfg.thr[y][x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->cfaCfg.thr = NULL\n");
        break;
    case cfaLut16to12Cfg__clip:
        cfg->cfaLut16to12Cfg.clip = val;
        break;
    case cfaLut16to12Cfg__enable:
        cfg->cfaLut16to12Cfg.enable = val;
        break;
    case cfaLut16to12Cfg__inputBits:
        cfg->cfaLut16to12Cfg.inputBits = val;
        break;
    case decomp1Cfg__clip:
        cfg->decomp1Cfg.clip = val;
        break;
    case decomp1Cfg__enable:
        cfg->decomp1Cfg.enable = val;
        break;
    case decomp1Cfg__inputBits:
        cfg->decomp1Cfg.inputBits = val;
        break;
    case decomp2Cfg__clip:
        cfg->decomp2Cfg.clip = val;
        break;
    case decomp2Cfg__enable:
        cfg->decomp2Cfg.enable = val;
        break;
    case decomp2Cfg__inputBits:
        cfg->decomp2Cfg.inputBits = val;
        break;
    case decomp3Cfg__clip:
        cfg->decomp3Cfg.clip = val;
        break;
    case decomp3Cfg__enable:
        cfg->decomp3Cfg.enable = val;
        break;
    case decomp3Cfg__inputBits:
        cfg->decomp3Cfg.inputBits = val;
        break;
    case dpcLutCfg__enable:
        cfg->dpcLutCfg.enable = val;
        break;
    case dpcLutCfg__isReplaceWhite:
        cfg->dpcLutCfg.isReplaceWhite = val;
        break;
    case dpcLutCfg__maxDefectPixels:
        cfg->dpcLutCfg.maxDefectPixels = val;
        break;
    case dpcLutCfg__table:
        // if (cfg->dpcLutCfg.table != NULL)
            cfg->dpcLutCfg.table[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->dpcLutCfg.table = NULL\n");
        break;
    case dpcOtfCfg__enable:
        cfg->dpcOtfCfg.enable = val;
        break;
    case dpcOtfCfg__slope:
        // if (cfg->dpcOtfCfg.slope != NULL)
            cfg->dpcOtfCfg.slope[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->dpcOtfCfg.slope = NULL\n");
        break;
    case dpcOtfCfg__threshold:
        // if (cfg->dpcOtfCfg.threshold != NULL)
            cfg->dpcOtfCfg.threshold[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->dpcOtfCfg.threshold = NULL\n");
        break;
    case eeCfg__alignY12withChroma:
        cfg->eeCfg.alignY12withChroma = val;
        break;
    case eeCfg__alignY8withChroma:
        cfg->eeCfg.alignY8withChroma = val;
        break;
    case eeCfg__bypassC12:
        cfg->eeCfg.bypassC12 = val;
        break;
    case eeCfg__bypassC8:
        cfg->eeCfg.bypassC8 = val;
        break;
    case eeCfg__bypassY12:
        cfg->eeCfg.bypassY12 = val;
        break;
    case eeCfg__bypassY8:
        cfg->eeCfg.bypassY8 = val;
        break;
    case eeCfg__coeff:
        // if (cfg->eeCfg.coeff != NULL)
            cfg->eeCfg.coeff[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->eeCfg.coeff = NULL\n");
        break;
    case eeCfg__eeForY12OrY8:
        cfg->eeCfg.eeForY12OrY8 = val;
        break;
    case eeCfg__enable:
        cfg->eeCfg.enable = val;
        break;
    case eeCfg__haloReductionOn:
        cfg->eeCfg.haloReductionOn = val;
        break;
    case eeCfg__leftShift:
        cfg->eeCfg.leftShift = val;
        break;
    case eeCfg__lut:
        // if (cfg->eeCfg.lut != NULL)
            cfg->eeCfg.lut[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->eeCfg.lut = NULL\n");
        break;
    case eeCfg__rightShift:
        cfg->eeCfg.rightShift = val;
        break;
    case eeCfg__yeeEThr:
        cfg->eeCfg.yeeEThr = val;
        break;
    case eeCfg__yeeMergeSel:
        cfg->eeCfg.yeeMergeSel = val;
        break;
    case eeCfg__yeeShift:
        cfg->eeCfg.yeeShift = val;
        break;
    case eeCfg__yesEGain:
        cfg->eeCfg.yesEGain = val;
        break;
    case eeCfg__yesEThr1:
        cfg->eeCfg.yesEThr1 = val;
        break;
    case eeCfg__yesEThr2:
        cfg->eeCfg.yesEThr2 = val;
        break;
    case eeCfg__yesGGain:
        cfg->eeCfg.yesGGain = val;
        break;
    case eeCfg__yesGOfset:
        cfg->eeCfg.yesGOfset = val;
        break;
    case fwdPrcpCfg__enable:
        cfg->fwdPrcpCfg.enable = val;
        break;
    case fwdPrcpCfg__table:
        // if (cfg->fwdPrcpCfg.table != NULL)
            cfg->fwdPrcpCfg.table[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->fwdPrcpCfg.table = NULL\n");
        break;
    case gammaCfg__enable:
        cfg->gammaCfg.enable = val;
        break;
    case gammaCfg__outClip:
        cfg->gammaCfg.outClip = val;
        break;
    case gammaCfg__tableC1:
        // if (cfg->gammaCfg.tableC1 != NULL)
            cfg->gammaCfg.tableC1[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->gammaCfg.tableC1 = NULL\n");
        break;
    case gammaCfg__tableC2:
        // if (cfg->gammaCfg.tableC2 != NULL)
            cfg->gammaCfg.tableC2[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->gammaCfg.tableC2 = NULL\n");
        break;
    case gammaCfg__tableC3:
        // if (cfg->gammaCfg.tableC3 != NULL)
            cfg->gammaCfg.tableC3[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->gammaCfg.tableC3 = NULL\n");
        break;
    case glbceCfg__asymLut:
        // if (cfg->glbceCfg.asymLut != NULL)
            cfg->glbceCfg.asymLut[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->glbceCfg.asymLut = NULL\n");
        break;
    case glbceCfg__blackLevel:
        cfg->glbceCfg.blackLevel = val;
        break;
    case glbceCfg__brightAmplLimit:
        cfg->glbceCfg.brightAmplLimit = val;
        break;
    case glbceCfg__darkAmplLimit:
        cfg->glbceCfg.darkAmplLimit = val;
        break;
    case glbceCfg__dither:
        cfg->glbceCfg.dither = val;
        break;
    case glbceCfg__intensityVariance:
        cfg->glbceCfg.intensityVariance = val;
        break;
    case glbceCfg__irStrength:
        cfg->glbceCfg.irStrength = val;
        break;
    case glbceCfg__maxSlopeLimit:
        cfg->glbceCfg.maxSlopeLimit = val;
        break;
    case glbceCfg__minSlopeLimit:
        cfg->glbceCfg.minSlopeLimit = val;
        break;
    case glbceCfg__spaceVariance:
        cfg->glbceCfg.spaceVariance = val;
        break;
    case glbceCfg__whiteLevel:
        cfg->glbceCfg.whiteLevel = val;
        break;
    case h3aCfg__aewbCfg__blackLineHeight:
        cfg->h3aCfg.aewbCfg.blackLineHeight = val;
        break;
    case h3aCfg__aewbCfg__blackLineVertStart:
        cfg->h3aCfg.aewbCfg.blackLineVertStart = val;
        break;
    case h3aCfg__aewbCfg__enableALowComp:
        cfg->h3aCfg.aewbCfg.enableALowComp = val;
        break;
    case h3aCfg__aewbCfg__enableMedFilt:
        cfg->h3aCfg.aewbCfg.enableMedFilt = val;
        break;
    case h3aCfg__aewbCfg__midFiltThreshold:
        cfg->h3aCfg.aewbCfg.midFiltThreshold = val;
        break;
    case h3aCfg__aewbCfg__outMode:
        cfg->h3aCfg.aewbCfg.outMode = val;
        break;
    case h3aCfg__aewbCfg__satLimit:
        cfg->h3aCfg.aewbCfg.satLimit = val;
        break;
    case h3aCfg__aewbCfg__sumShift:
        cfg->h3aCfg.aewbCfg.sumShift = val;
        break;
    case h3aCfg__aewbCfg__winCfg__height:
        cfg->h3aCfg.aewbCfg.winCfg.height = val;
        break;
    case h3aCfg__aewbCfg__winCfg__horzCount:
        cfg->h3aCfg.aewbCfg.winCfg.horzCount = val;
        break;
    case h3aCfg__aewbCfg__winCfg__horzIncr:
        cfg->h3aCfg.aewbCfg.winCfg.horzIncr = val;
        break;
    case h3aCfg__aewbCfg__winCfg__pos__startX:
        cfg->h3aCfg.aewbCfg.winCfg.pos.startX = val;
        break;
    case h3aCfg__aewbCfg__winCfg__pos__startY:
        cfg->h3aCfg.aewbCfg.winCfg.pos.startY = val;
        break;
    case h3aCfg__aewbCfg__winCfg__vertCount:
        cfg->h3aCfg.aewbCfg.winCfg.vertCount = val;
        break;
    case h3aCfg__aewbCfg__winCfg__vertIncr:
        cfg->h3aCfg.aewbCfg.winCfg.vertIncr = val;
        break;
    case h3aCfg__aewbCfg__winCfg__width:
        cfg->h3aCfg.aewbCfg.winCfg.width = val;
        break;
    case h3aCfg__afCfg__enableALowCompr:
        cfg->h3aCfg.afCfg.enableALowCompr = val;
        break;
    case h3aCfg__afCfg__enableMedFilt:
        cfg->h3aCfg.afCfg.enableMedFilt = val;
        break;
    case h3aCfg__afCfg__firCfg1__coeff:
        // if (cfg->h3aCfg.afCfg.firCfg1.coeff != NULL)
            cfg->h3aCfg.afCfg.firCfg1.coeff[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->h3aCfg.afCfg.firCfg1.coeff = NULL\n");
        break;
    case h3aCfg__afCfg__firCfg1__threshold:
        cfg->h3aCfg.afCfg.firCfg1.threshold = val;
        break;
    case h3aCfg__afCfg__firCfg2__coeff:
        // if (cfg->h3aCfg.afCfg.firCfg2.coeff != NULL)
            cfg->h3aCfg.afCfg.firCfg2.coeff[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->h3aCfg.afCfg.firCfg2.coeff = NULL\n");
        break;
    case h3aCfg__afCfg__firCfg2__threshold:
        cfg->h3aCfg.afCfg.firCfg2.threshold = val;
        break;
    case h3aCfg__afCfg__fvMode:
        cfg->h3aCfg.afCfg.fvMode = val;
        break;
    case h3aCfg__afCfg__iirCfg1__coeff:
        // if (cfg->h3aCfg.afCfg.iirCfg1.coeff != NULL)
            cfg->h3aCfg.afCfg.iirCfg1.coeff[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->h3aCfg.afCfg.iirCfg1.coeff = NULL\n");
        break;
    case h3aCfg__afCfg__iirCfg1__threshold:
        cfg->h3aCfg.afCfg.iirCfg1.threshold = val;
        break;
    case h3aCfg__afCfg__iirCfg2__coeff:
        // if (cfg->h3aCfg.afCfg.iirCfg2.coeff != NULL)
            cfg->h3aCfg.afCfg.iirCfg2.coeff[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->h3aCfg.afCfg.iirCfg2.coeff = NULL\n");
        break;
    case h3aCfg__afCfg__iirCfg2__threshold:
        cfg->h3aCfg.afCfg.iirCfg2.threshold = val;
        break;
    case h3aCfg__afCfg__iirFiltStartPos:
        cfg->h3aCfg.afCfg.iirFiltStartPos = val;
        break;
    case h3aCfg__afCfg__midFiltThreshold:
        cfg->h3aCfg.afCfg.midFiltThreshold = val;
        break;
    case h3aCfg__afCfg__paxelCfg__height:
        cfg->h3aCfg.afCfg.paxelCfg.height = val;
        break;
    case h3aCfg__afCfg__paxelCfg__horzCount:
        cfg->h3aCfg.afCfg.paxelCfg.horzCount = val;
        break;
    case h3aCfg__afCfg__paxelCfg__horzIncr:
        cfg->h3aCfg.afCfg.paxelCfg.horzIncr = val;
        break;
    case h3aCfg__afCfg__paxelCfg__pos__startX:
        cfg->h3aCfg.afCfg.paxelCfg.pos.startX = val;
        break;
    case h3aCfg__afCfg__paxelCfg__pos__startY:
        cfg->h3aCfg.afCfg.paxelCfg.pos.startY = val;
        break;
    case h3aCfg__afCfg__paxelCfg__vertCount:
        cfg->h3aCfg.afCfg.paxelCfg.vertCount = val;
        break;
    case h3aCfg__afCfg__paxelCfg__vertIncr:
        cfg->h3aCfg.afCfg.paxelCfg.vertIncr = val;
        break;
    case h3aCfg__afCfg__paxelCfg__width:
        cfg->h3aCfg.afCfg.paxelCfg.width = val;
        break;
    case h3aCfg__afCfg__rgbPos:
        cfg->h3aCfg.afCfg.rgbPos = val;
        break;
    case h3aCfg__afCfg__vfMode:
        cfg->h3aCfg.afCfg.vfMode = val;
        break;
    case h3aCfg__module:
        cfg->h3aCfg.module = val;
        break;
    case h3aCfg__outputSize:
        cfg->h3aCfg.outputSize = val;
        break;
    case h3aCfg__pos__startX:
        cfg->h3aCfg.pos.startX = val;
        break;
    case h3aCfg__pos__startY:
        cfg->h3aCfg.pos.startY = val;
        break;
    case h3aInCfg__inSel:
        cfg->h3aInCfg.inSel = val;
        break;
    case h3aInCfg__shift:
        cfg->h3aInCfg.shift = val;
        break;
    case h3aLutCfg__clip:
        cfg->h3aLutCfg.clip = val;
        break;
    case h3aLutCfg__enable:
        cfg->h3aLutCfg.enable = val;
        break;
    case h3aLutCfg__inputBits:
        cfg->h3aLutCfg.inputBits = val;
        break;
    case histCfg__enable:
        cfg->histCfg.enable = val;
        break;
    case histCfg__input:
        cfg->histCfg.input = val;
        break;
    case histCfg__roi__cropHeight:
        cfg->histCfg.roi.cropHeight = val;
        break;
    case histCfg__roi__cropStartX:
        cfg->histCfg.roi.cropStartX = val;
        break;
    case histCfg__roi__cropStartY:
        cfg->histCfg.roi.cropStartY = val;
        break;
    case histCfg__roi__cropWidth:
        cfg->histCfg.roi.cropWidth = val;
        break;
    case lscCfg__enable:
        cfg->lscCfg.enable = val;
        break;
    case lscCfg__gainFmt:
        cfg->lscCfg.gainFmt = val;
        break;
    case lscCfg__horzDsFactor:
        cfg->lscCfg.horzDsFactor = val;
        break;
    case lscCfg__numTblEntry:
        cfg->lscCfg.numTblEntry = val;
        break;
    case lscCfg__vertDsFactor:
        cfg->lscCfg.vertDsFactor = val;
        break;
    case merge1Cfg__afe:
        cfg->merge1Cfg.afe = val;
        break;
    case merge1Cfg__afm:
        cfg->merge1Cfg.afm = val;
        break;
    case merge1Cfg__bf:
        cfg->merge1Cfg.bf = val;
        break;
    case merge1Cfg__dst:
        cfg->merge1Cfg.dst = val;
        break;
    case merge1Cfg__enable:
        cfg->merge1Cfg.enable = val;
        break;
    case merge1Cfg__glong:
        cfg->merge1Cfg.glong = val;
        break;
    case merge1Cfg__gshort:
        cfg->merge1Cfg.gshort = val;
        break;
    case merge1Cfg__lbit:
        cfg->merge1Cfg.lbit = val;
        break;
    case merge1Cfg__lbk:
        // if (cfg->merge1Cfg.lbk != NULL)
            cfg->merge1Cfg.lbk[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->merge1Cfg.lbk = NULL\n");
        break;
    case merge1Cfg__lwb:
        // if (cfg->merge1Cfg.lwb != NULL)
            cfg->merge1Cfg.lwb[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->merge1Cfg.lwb = NULL\n");
        break;
    case merge1Cfg__mad:
        cfg->merge1Cfg.mad = val;
        break;
    case merge1Cfg__mas:
        cfg->merge1Cfg.mas = val;
        break;
    case merge1Cfg__mergeClip:
        cfg->merge1Cfg.mergeClip = val;
        break;
    case merge1Cfg__mergeShift:
        cfg->merge1Cfg.mergeShift = val;
        break;
    case merge1Cfg__sbit:
        cfg->merge1Cfg.sbit = val;
        break;
    case merge1Cfg__sbk:
        // if (cfg->merge1Cfg.sbk != NULL)
            cfg->merge1Cfg.sbk[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->merge1Cfg.sbk = NULL\n");
        break;
    case merge1Cfg__swb:
        // if (cfg->merge1Cfg.swb != NULL)
            cfg->merge1Cfg.swb[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->merge1Cfg.swb = NULL\n");
        break;
    case merge1Cfg__useShortExpForWgtCalc:
        cfg->merge1Cfg.useShortExpForWgtCalc = val;
        break;
    case merge1Cfg__wdrThr:
        cfg->merge1Cfg.wdrThr = val;
        break;
    case merge2Cfg__afe:
        cfg->merge2Cfg.afe = val;
        break;
    case merge2Cfg__afm:
        cfg->merge2Cfg.afm = val;
        break;
    case merge2Cfg__bf:
        cfg->merge2Cfg.bf = val;
        break;
    case merge2Cfg__dst:
        cfg->merge2Cfg.dst = val;
        break;
    case merge2Cfg__enable:
        cfg->merge2Cfg.enable = val;
        break;
    case merge2Cfg__glong:
        cfg->merge2Cfg.glong = val;
        break;
    case merge2Cfg__gshort:
        cfg->merge2Cfg.gshort = val;
        break;
    case merge2Cfg__lbit:
        cfg->merge2Cfg.lbit = val;
        break;
    case merge2Cfg__lbk:
        // if (cfg->merge2Cfg.lbk != NULL)
            cfg->merge2Cfg.lbk[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->merge2Cfg.lbk = NULL\n");
        break;
    case merge2Cfg__lwb:
        // if (cfg->merge2Cfg.lwb != NULL)
            cfg->merge2Cfg.lwb[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->merge2Cfg.lwb = NULL\n");
        break;
    case merge2Cfg__mad:
        cfg->merge2Cfg.mad = val;
        break;
    case merge2Cfg__mas:
        cfg->merge2Cfg.mas = val;
        break;
    case merge2Cfg__mergeClip:
        cfg->merge2Cfg.mergeClip = val;
        break;
    case merge2Cfg__mergeShift:
        cfg->merge2Cfg.mergeShift = val;
        break;
    case merge2Cfg__sbit:
        cfg->merge2Cfg.sbit = val;
        break;
    case merge2Cfg__sbk:
        // if (cfg->merge2Cfg.sbk != NULL)
            cfg->merge2Cfg.sbk[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->merge2Cfg.sbk = NULL\n");
        break;
    case merge2Cfg__swb:
        // if (cfg->merge2Cfg.swb != NULL)
            cfg->merge2Cfg.swb[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->merge2Cfg.swb = NULL\n");
        break;
    case merge2Cfg__useShortExpForWgtCalc:
        cfg->merge2Cfg.useShortExpForWgtCalc = val;
        break;
    case merge2Cfg__wdrThr:
        cfg->merge2Cfg.wdrThr = val;
        break;
    case nsf4Cfg__gains:
        // if (cfg->nsf4Cfg.gains != NULL)
            cfg->nsf4Cfg.gains[0] = val;
            cfg->nsf4Cfg.gains[1] = val;
            cfg->nsf4Cfg.gains[2] = val;
            cfg->nsf4Cfg.gains[3] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->nsf4Cfg.gains = NULL\n");
        break;
    case nsf4Cfg__lsccCfg__enable:
        cfg->nsf4Cfg.lsccCfg.enable = val;
        break;
    case nsf4Cfg__lsccCfg__gMaxCfg:
        cfg->nsf4Cfg.lsccCfg.gMaxCfg = val;
        break;
    case nsf4Cfg__lsccCfg__khCfg:
        cfg->nsf4Cfg.lsccCfg.khCfg = val;
        break;
    case nsf4Cfg__lsccCfg__kvCfg:
        cfg->nsf4Cfg.lsccCfg.kvCfg = val;
        break;
    case nsf4Cfg__lsccCfg__lensCenterX:
        cfg->nsf4Cfg.lsccCfg.lensCenterX = val;
        break;
    case nsf4Cfg__lsccCfg__lensCenterY:
        cfg->nsf4Cfg.lsccCfg.lensCenterY = val;
        break;
    case nsf4Cfg__lsccCfg__pwlCurve:
        // if (cfg->nsf4Cfg.lsccCfg.pwlCurve != NULL)
            cfg->nsf4Cfg.lsccCfg.pwlCurve[y][x].posX = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->nsf4Cfg.lsccCfg.pwlCurve = NULL\n");
        break;
    case nsf4Cfg__lsccCfg__setSel:
        cfg->nsf4Cfg.lsccCfg.setSel = val;
        break;
    case nsf4Cfg__lsccCfg__tCfg:
        cfg->nsf4Cfg.lsccCfg.tCfg = val;
        break;
    case nsf4Cfg__mode:
        cfg->nsf4Cfg.mode = val;
        break;
    case nsf4Cfg__tKnee:
        cfg->nsf4Cfg.tKnee = val;
        break;
    case nsf4Cfg__tnCurve:
        // if (cfg->nsf4Cfg.tnCurve != NULL)
            cfg->nsf4Cfg.tnCurve[y][x].posX = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->nsf4Cfg.tnCurve = NULL\n");
        break;
    case nsf4Cfg__tnScale_0:
    case nsf4Cfg__tnScale_1:
    case nsf4Cfg__tnScale_2:
            cfg->nsf4Cfg.tnScale[id-nsf4Cfg__tnScale_0] = val;
        break;
    case pwlCfg1__enable:
        cfg->pwlCfg1.enable = val;
        break;
    case pwlCfg1__gain:
        // if (cfg->pwlCfg1.gain != NULL)
            cfg->pwlCfg1.gain[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->pwlCfg1.gain = NULL\n");
        break;
    case pwlCfg1__mask:
        cfg->pwlCfg1.mask = val;
        break;
    case pwlCfg1__offset:
        // if (cfg->pwlCfg1.offset != NULL)
            cfg->pwlCfg1.offset[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->pwlCfg1.offset = NULL\n");
        break;
    case pwlCfg1__outClip:
        cfg->pwlCfg1.outClip = val;
        break;
    case pwlCfg1__shift:
        cfg->pwlCfg1.shift = val;
        break;
    case pwlCfg1__slope1:
        cfg->pwlCfg1.slope1 = val;
        break;
    case pwlCfg1__slope2:
        cfg->pwlCfg1.slope2 = val;
        break;
    case pwlCfg1__slope3:
        cfg->pwlCfg1.slope3 = val;
        break;
    case pwlCfg1__slope4:
        cfg->pwlCfg1.slope4 = val;
        break;
    case pwlCfg1__slopeShift:
        cfg->pwlCfg1.slopeShift = val;
        break;
    case pwlCfg1__xthr1:
        cfg->pwlCfg1.xthr1 = val;
        break;
    case pwlCfg1__xthr2:
        cfg->pwlCfg1.xthr2 = val;
        break;
    case pwlCfg1__xthr3:
        cfg->pwlCfg1.xthr3 = val;
        break;
    case pwlCfg1__ythr1:
        cfg->pwlCfg1.ythr1 = val;
        break;
    case pwlCfg1__ythr2:
        cfg->pwlCfg1.ythr2 = val;
        break;
    case pwlCfg1__ythr3:
        cfg->pwlCfg1.ythr3 = val;
        break;
    case pwlCfg2__enable:
        cfg->pwlCfg2.enable = val;
        break;
    case pwlCfg2__gain:
        // if (cfg->pwlCfg2.gain != NULL)
            cfg->pwlCfg2.gain[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->pwlCfg2.gain = NULL\n");
        break;
    case pwlCfg2__mask:
        cfg->pwlCfg2.mask = val;
        break;
    case pwlCfg2__offset:
        // if (cfg->pwlCfg2.offset != NULL)
            cfg->pwlCfg2.offset[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->pwlCfg2.offset = NULL\n");
        break;
    case pwlCfg2__outClip:
        cfg->pwlCfg2.outClip = val;
        break;
    case pwlCfg2__shift:
        cfg->pwlCfg2.shift = val;
        break;
    case pwlCfg2__slope1:
        cfg->pwlCfg2.slope1 = val;
        break;
    case pwlCfg2__slope2:
        cfg->pwlCfg2.slope2 = val;
        break;
    case pwlCfg2__slope3:
        cfg->pwlCfg2.slope3 = val;
        break;
    case pwlCfg2__slope4:
        cfg->pwlCfg2.slope4 = val;
        break;
    case pwlCfg2__slopeShift:
        cfg->pwlCfg2.slopeShift = val;
        break;
    case pwlCfg2__xthr1:
        cfg->pwlCfg2.xthr1 = val;
        break;
    case pwlCfg2__xthr2:
        cfg->pwlCfg2.xthr2 = val;
        break;
    case pwlCfg2__xthr3:
        cfg->pwlCfg2.xthr3 = val;
        break;
    case pwlCfg2__ythr1:
        cfg->pwlCfg2.ythr1 = val;
        break;
    case pwlCfg2__ythr2:
        cfg->pwlCfg2.ythr2 = val;
        break;
    case pwlCfg2__ythr3:
        cfg->pwlCfg2.ythr3 = val;
        break;
    case pwlCfg3__enable:
        cfg->pwlCfg3.enable = val;
        break;
    case pwlCfg3__gain:
        // if (cfg->pwlCfg3.gain != NULL)
            cfg->pwlCfg3.gain[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->pwlCfg3.gain = NULL\n");
        break;
    case pwlCfg3__mask:
        cfg->pwlCfg3.mask = val;
        break;
    case pwlCfg3__offset:
        // if (cfg->pwlCfg3.offset != NULL)
            cfg->pwlCfg3.offset[0] = val;
            cfg->pwlCfg3.offset[1] = val;
            cfg->pwlCfg3.offset[2] = val;
            cfg->pwlCfg3.offset[3] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->pwlCfg3.offset = NULL\n");
        break;
    case pwlCfg3__outClip:
        cfg->pwlCfg3.outClip = val;
        break;
    case pwlCfg3__shift:
        cfg->pwlCfg3.shift = val;
        break;
    case pwlCfg3__slope1:
        cfg->pwlCfg3.slope1 = val;
        break;
    case pwlCfg3__slope2:
        cfg->pwlCfg3.slope2 = val;
        break;
    case pwlCfg3__slope3:
        cfg->pwlCfg3.slope3 = val;
        break;
    case pwlCfg3__slope4:
        cfg->pwlCfg3.slope4 = val;
        break;
    case pwlCfg3__slopeShift:
        cfg->pwlCfg3.slopeShift = val;
        break;
    case pwlCfg3__xthr1:
        cfg->pwlCfg3.xthr1 = val;
        break;
    case pwlCfg3__xthr2:
        cfg->pwlCfg3.xthr2 = val;
        break;
    case pwlCfg3__xthr3:
        cfg->pwlCfg3.xthr3 = val;
        break;
    case pwlCfg3__ythr1:
        cfg->pwlCfg3.ythr1 = val;
        break;
    case pwlCfg3__ythr2:
        cfg->pwlCfg3.ythr2 = val;
        break;
    case pwlCfg3__ythr3:
        cfg->pwlCfg3.ythr3 = val;
        break;
    case revPrcpCfg__enable:
        cfg->revPrcpCfg.enable = val;
        break;
    case revPrcpCfg__table:
        // if (cfg->revPrcpCfg.table != NULL)
            cfg->revPrcpCfg.table[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->revPrcpCfg.table = NULL\n");
        break;
    case rfeLut20to16Cfg__clip:
        cfg->rfeLut20to16Cfg.clip = val;
        break;
    case rfeLut20to16Cfg__enable:
        cfg->rfeLut20to16Cfg.enable = val;
        break;
    case rfeLut20to16Cfg__inputBits:
        cfg->rfeLut20to16Cfg.inputBits = val;
        break;
    case rgb2hsvCfg__h1Input:
        cfg->rgb2hsvCfg.h1Input = val;
        break;
    case rgb2hsvCfg__h2Input:
        cfg->rgb2hsvCfg.h2Input = val;
        break;
    case rgb2hsvCfg__inputSelect:
        cfg->rgb2hsvCfg.inputSelect = val;
        break;
    case rgb2hsvCfg__offset:
        cfg->rgb2hsvCfg.offset = val;
        break;
    case rgb2hsvCfg__satDiv:
        cfg->rgb2hsvCfg.satDiv = val;
        break;
    case rgb2hsvCfg__satMinThr:
        cfg->rgb2hsvCfg.satMinThr = val;
        break;
    case rgb2hsvCfg__satMode:
        cfg->rgb2hsvCfg.satMode = val;
        break;
    case rgb2hsvCfg__threshold:
        // if (cfg->rgb2hsvCfg.threshold != NULL)
            cfg->rgb2hsvCfg.threshold[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->rgb2hsvCfg.threshold = NULL\n");
        break;
    case rgb2hsvCfg__useWbDataForGreyCalc:
        cfg->rgb2hsvCfg.useWbDataForGreyCalc = val;
        break;
    case rgb2hsvCfg__wbOffset:
        // if (cfg->rgb2hsvCfg.wbOffset != NULL)
            cfg->rgb2hsvCfg.wbOffset[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->rgb2hsvCfg.wbOffset = NULL\n");
        break;
    case rgb2hsvCfg__weights:
        // if (cfg->rgb2hsvCfg.weights != NULL)
            cfg->rgb2hsvCfg.weights[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->rgb2hsvCfg.weights = NULL\n");
        break;
    case rgb2yuvCfg__offsets:
        // if (cfg->rgb2yuvCfg.offsets != NULL)
            cfg->rgb2yuvCfg.offsets[x] = val;
        // else
        //     isp_tracelog_e("cannot write becuase cfg->rgb2yuvCfg.offsets = NULL\n");
        break;
    case rgb2yuvCfg__weights:
        // if (cfg->rgb2yuvCfg.weights != NULL)
            cfg->rgb2yuvCfg.weights[y][x] = val;
        // else
            // isp_tracelog_e("cannot write becuase cfg->rgb2yuvCfg.weights = NULL\n");
        break;
    case wbCfg__gain:
        // if (cfg->wbCfg.gain != NULL)
            cfg->wbCfg.gain[x] = val;
        // else
            // isp_tracelog_e("cannot write becuase cfg->wbCfg.gain = NULL\n");
        break;
    case wbCfg__offset:
        // if (cfg->wbCfg.offset != NULL)
            cfg->wbCfg.offset[0] = val;
            cfg->wbCfg.offset[1] = val;
            cfg->wbCfg.offset[2] = val;
            cfg->wbCfg.offset[3] = val;
        // else
            // isp_tracelog_e("cannot write becuase cfg->wbCfg.offset = NULL\n");
        break;
    case yuvSatLutCfg__enableChromaLut:
        cfg->yuvSatLutCfg.enableChromaLut = val;
        break;
    case yuvSatLutCfg__enableLumaLut:
        cfg->yuvSatLutCfg.enableLumaLut = val;
        break;
    case yuvSatLutCfg__enableSaturLut:
        cfg->yuvSatLutCfg.enableSaturLut = val;
        break;
    case yuvSatLutCfg__lumaInputBits:
        cfg->yuvSatLutCfg.lumaInputBits = val;
        break;
    default:
        isp_tracelog_e("Cannot parse config parameter %s\n", line);
        break;
    }
}


static inline uint64_t get_val_to_struct(const char* line, uint32_t id, uint32_t y, uint32_t x, const struct ISP_config* cfg)
{
    uint64_t val = UINT64_MAX;

    switch (id)
    {
    case ccmCfg__offsets:
        // if (cfg->ccmCfg.offsets != NULL)
            val = cfg->ccmCfg.offsets[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->ccmCfg.offsets = NULL\n");
        break;
    case ccmCfg__weights:
        // if (cfg->ccmCfg.weights != NULL)
            val = cfg->ccmCfg.weights[y][x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->ccmCfg.weights = NULL\n");
        break;
    case cfaCfg__bypass:
        // if (cfg->cfaCfg.bypass != NULL)
            val = cfg->cfaCfg.bypass[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->cfaCfg.bypass = NULL\n");
        break;
    case cfaCfg__coeff:
        // if (cfg->cfaCfg.coeff != NULL)
            val = cfg->cfaCfg.coeff[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->cfaCfg.coeff = NULL\n");
        break;
    case cfaCfg__coreBlendMode:
        // if (cfg->cfaCfg.coreBlendMode != NULL)
            val = cfg->cfaCfg.coreBlendMode[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->cfaCfg.coreBlendMode = NULL\n");
        break;
    case cfaCfg__coreSel:
        // if (cfg->cfaCfg.coreSel != NULL)
            val = cfg->cfaCfg.coreSel[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->cfaCfg.coreSel = NULL\n");
        break;
    case cfaCfg__gradHzPh:
        // if (cfg->cfaCfg.gradHzPh != NULL)
            val = cfg->cfaCfg.gradHzPh[y][x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->cfaCfg.gradHzPh = NULL\n");
        break;
    case cfaCfg__gradVtPh:
        // if (cfg->cfaCfg.gradVtPh != NULL)
            val = cfg->cfaCfg.gradVtPh[y][x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->cfaCfg.gradVtPh = NULL\n");
        break;
    case cfaCfg__intsBitField:
        // if (cfg->cfaCfg.intsBitField != NULL)
            val = cfg->cfaCfg.intsBitField[y][x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->cfaCfg.intsBitField = NULL\n");
        break;
    case cfaCfg__intsShiftPh:
        // if (cfg->cfaCfg.intsShiftPh != NULL)
            val = cfg->cfaCfg.intsShiftPh[y][x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->cfaCfg.intsShiftPh = NULL\n");
        break;
    case cfaCfg__thr:
        // if (cfg->cfaCfg.thr != NULL)
            val = cfg->cfaCfg.thr[y][x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->cfaCfg.thr = NULL\n");
        break;
    case cfaLut16to12Cfg__clip:
        val = cfg->cfaLut16to12Cfg.clip;
        break;
    case cfaLut16to12Cfg__enable:
        val = cfg->cfaLut16to12Cfg.enable;
        break;
    case cfaLut16to12Cfg__inputBits:
        val = cfg->cfaLut16to12Cfg.inputBits;
        break;
    case decomp1Cfg__clip:
        val = cfg->decomp1Cfg.clip;
        break;
    case decomp1Cfg__enable:
        val = cfg->decomp1Cfg.enable;
        break;
    case decomp1Cfg__inputBits:
        val = cfg->decomp1Cfg.inputBits;
        break;
    case decomp2Cfg__clip:
        val = cfg->decomp2Cfg.clip;
        break;
    case decomp2Cfg__enable:
        val = cfg->decomp2Cfg.enable;
        break;
    case decomp2Cfg__inputBits:
        val = cfg->decomp2Cfg.inputBits;
        break;
    case decomp3Cfg__clip:
        val = cfg->decomp3Cfg.clip;
        break;
    case decomp3Cfg__enable:
        val = cfg->decomp3Cfg.enable;
        break;
    case decomp3Cfg__inputBits:
        val = cfg->decomp3Cfg.inputBits;
        break;
    case dpcLutCfg__enable:
        val = cfg->dpcLutCfg.enable;
        break;
    case dpcLutCfg__isReplaceWhite:
        val = cfg->dpcLutCfg.isReplaceWhite;
        break;
    case dpcLutCfg__maxDefectPixels:
        val = cfg->dpcLutCfg.maxDefectPixels;
        break;
    case dpcLutCfg__table:
        // if (cfg->dpcLutCfg.table != NULL)
            val = cfg->dpcLutCfg.table[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->dpcLutCfg.table = NULL\n");
        break;
    case dpcOtfCfg__enable:
        val = cfg->dpcOtfCfg.enable;
        break;
    case dpcOtfCfg__slope:
        // if (cfg->dpcOtfCfg.slope != NULL)
            val = cfg->dpcOtfCfg.slope[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->dpcOtfCfg.slope = NULL\n");
        break;
    case dpcOtfCfg__threshold:
        // if (cfg->dpcOtfCfg.threshold != NULL)
            val = cfg->dpcOtfCfg.threshold[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->dpcOtfCfg.threshold = NULL\n");
        break;
    case eeCfg__alignY12withChroma:
        val = cfg->eeCfg.alignY12withChroma;
        break;
    case eeCfg__alignY8withChroma:
        val = cfg->eeCfg.alignY8withChroma;
        break;
    case eeCfg__bypassC12:
        val = cfg->eeCfg.bypassC12;
        break;
    case eeCfg__bypassC8:
        val = cfg->eeCfg.bypassC8;
        break;
    case eeCfg__bypassY12:
        val = cfg->eeCfg.bypassY12;
        break;
    case eeCfg__bypassY8:
        val = cfg->eeCfg.bypassY8;
        break;
    case eeCfg__coeff:
        // if (cfg->eeCfg.coeff != NULL)
            val = cfg->eeCfg.coeff[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->eeCfg.coeff = NULL\n");
        break;
    case eeCfg__eeForY12OrY8:
        val = cfg->eeCfg.eeForY12OrY8;
        break;
    case eeCfg__enable:
        val = cfg->eeCfg.enable;
        break;
    case eeCfg__haloReductionOn:
        val = cfg->eeCfg.haloReductionOn;
        break;
    case eeCfg__leftShift:
        val = cfg->eeCfg.leftShift;
        break;
    case eeCfg__lut:
        // if (cfg->eeCfg.lut != NULL)
            val = cfg->eeCfg.lut[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->eeCfg.lut = NULL\n");
        break;
    case eeCfg__rightShift:
        val = cfg->eeCfg.rightShift;
        break;
    case eeCfg__yeeEThr:
        val = cfg->eeCfg.yeeEThr;
        break;
    case eeCfg__yeeMergeSel:
        val = cfg->eeCfg.yeeMergeSel;
        break;
    case eeCfg__yeeShift:
        val = cfg->eeCfg.yeeShift;
        break;
    case eeCfg__yesEGain:
        val = cfg->eeCfg.yesEGain;
        break;
    case eeCfg__yesEThr1:
        val = cfg->eeCfg.yesEThr1;
        break;
    case eeCfg__yesEThr2:
        val = cfg->eeCfg.yesEThr2;
        break;
    case eeCfg__yesGGain:
        val = cfg->eeCfg.yesGGain;
        break;
    case eeCfg__yesGOfset:
        val = cfg->eeCfg.yesGOfset;
        break;
    case fwdPrcpCfg__enable:
        val = cfg->fwdPrcpCfg.enable;
        break;
    case fwdPrcpCfg__table:
        // if (cfg->fwdPrcpCfg.table != NULL)
            val = cfg->fwdPrcpCfg.table[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->fwdPrcpCfg.table = NULL\n");
        break;
    case gammaCfg__enable:
        val = cfg->gammaCfg.enable;
        break;
    case gammaCfg__outClip:
        val = cfg->gammaCfg.outClip;
        break;
    case gammaCfg__tableC1:
        // if (cfg->gammaCfg.tableC1 != NULL)
            val = cfg->gammaCfg.tableC1[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->gammaCfg.tableC1 = NULL\n");
        break;
    case gammaCfg__tableC2:
        // if (cfg->gammaCfg.tableC2 != NULL)
            val = cfg->gammaCfg.tableC2[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->gammaCfg.tableC2 = NULL\n");
        break;
    case gammaCfg__tableC3:
        // if (cfg->gammaCfg.tableC3 != NULL)
            val = cfg->gammaCfg.tableC3[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->gammaCfg.tableC3 = NULL\n");
        break;
    case glbceCfg__asymLut:
        // if (cfg->glbceCfg.asymLut != NULL)
            val = cfg->glbceCfg.asymLut[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->glbceCfg.asymLut = NULL\n");
        break;
    case glbceCfg__blackLevel:
        val = cfg->glbceCfg.blackLevel;
        break;
    case glbceCfg__brightAmplLimit:
        val = cfg->glbceCfg.brightAmplLimit;
        break;
    case glbceCfg__darkAmplLimit:
        val = cfg->glbceCfg.darkAmplLimit;
        break;
    case glbceCfg__dither:
        val = cfg->glbceCfg.dither;
        break;
    case glbceCfg__intensityVariance:
        val = cfg->glbceCfg.intensityVariance;
        break;
    case glbceCfg__irStrength:
        val = cfg->glbceCfg.irStrength;
        break;
    case glbceCfg__maxSlopeLimit:
        val = cfg->glbceCfg.maxSlopeLimit;
        break;
    case glbceCfg__minSlopeLimit:
        val = cfg->glbceCfg.minSlopeLimit;
        break;
    case glbceCfg__spaceVariance:
        val = cfg->glbceCfg.spaceVariance;
        break;
    case glbceCfg__whiteLevel:
        val = cfg->glbceCfg.whiteLevel;
        break;
    case h3aCfg__aewbCfg__blackLineHeight:
        val = cfg->h3aCfg.aewbCfg.blackLineHeight;
        break;
    case h3aCfg__aewbCfg__blackLineVertStart:
        val = cfg->h3aCfg.aewbCfg.blackLineVertStart;
        break;
    case h3aCfg__aewbCfg__enableALowComp:
        val = cfg->h3aCfg.aewbCfg.enableALowComp;
        break;
    case h3aCfg__aewbCfg__enableMedFilt:
        val = cfg->h3aCfg.aewbCfg.enableMedFilt;
        break;
    case h3aCfg__aewbCfg__midFiltThreshold:
        val = cfg->h3aCfg.aewbCfg.midFiltThreshold;
        break;
    case h3aCfg__aewbCfg__outMode:
        val = cfg->h3aCfg.aewbCfg.outMode;
        break;
    case h3aCfg__aewbCfg__satLimit:
        val = cfg->h3aCfg.aewbCfg.satLimit;
        break;
    case h3aCfg__aewbCfg__sumShift:
        val = cfg->h3aCfg.aewbCfg.sumShift;
        break;
    case h3aCfg__aewbCfg__winCfg__height:
        val = cfg->h3aCfg.aewbCfg.winCfg.height;
        break;
    case h3aCfg__aewbCfg__winCfg__horzCount:
        val = cfg->h3aCfg.aewbCfg.winCfg.horzCount;
        break;
    case h3aCfg__aewbCfg__winCfg__horzIncr:
        val = cfg->h3aCfg.aewbCfg.winCfg.horzIncr;
        break;
    case h3aCfg__aewbCfg__winCfg__pos__startX:
        val = cfg->h3aCfg.aewbCfg.winCfg.pos.startX;
        break;
    case h3aCfg__aewbCfg__winCfg__pos__startY:
        val = cfg->h3aCfg.aewbCfg.winCfg.pos.startY;
        break;
    case h3aCfg__aewbCfg__winCfg__vertCount:
        val = cfg->h3aCfg.aewbCfg.winCfg.vertCount;
        break;
    case h3aCfg__aewbCfg__winCfg__vertIncr:
        val = cfg->h3aCfg.aewbCfg.winCfg.vertIncr;
        break;
    case h3aCfg__aewbCfg__winCfg__width:
        val = cfg->h3aCfg.aewbCfg.winCfg.width;
        break;
    case h3aCfg__afCfg__enableALowCompr:
        val = cfg->h3aCfg.afCfg.enableALowCompr;
        break;
    case h3aCfg__afCfg__enableMedFilt:
        val = cfg->h3aCfg.afCfg.enableMedFilt;
        break;
    case h3aCfg__afCfg__firCfg1__coeff:
        // if (cfg->h3aCfg.afCfg.firCfg1.coeff != NULL)
            val = cfg->h3aCfg.afCfg.firCfg1.coeff[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->h3aCfg.afCfg.firCfg1.coeff = NULL\n");
        break;
    case h3aCfg__afCfg__firCfg1__threshold:
        val = cfg->h3aCfg.afCfg.firCfg1.threshold;
        break;
    case h3aCfg__afCfg__firCfg2__coeff:
        // if (cfg->h3aCfg.afCfg.firCfg2.coeff != NULL)
            val = cfg->h3aCfg.afCfg.firCfg2.coeff[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->h3aCfg.afCfg.firCfg2.coeff = NULL\n");
        break;
    case h3aCfg__afCfg__firCfg2__threshold:
        val = cfg->h3aCfg.afCfg.firCfg2.threshold;
        break;
    case h3aCfg__afCfg__fvMode:
        val = cfg->h3aCfg.afCfg.fvMode;
        break;
    case h3aCfg__afCfg__iirCfg1__coeff:
        // if (cfg->h3aCfg.afCfg.iirCfg1.coeff != NULL)
            val = cfg->h3aCfg.afCfg.iirCfg1.coeff[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->h3aCfg.afCfg.iirCfg1.coeff = NULL\n");
        break;
    case h3aCfg__afCfg__iirCfg1__threshold:
        val = cfg->h3aCfg.afCfg.iirCfg1.threshold;
        break;
    case h3aCfg__afCfg__iirCfg2__coeff:
        // if (cfg->h3aCfg.afCfg.iirCfg2.coeff != NULL)
            val = cfg->h3aCfg.afCfg.iirCfg2.coeff[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->h3aCfg.afCfg.iirCfg2.coeff = NULL\n");
        break;
    case h3aCfg__afCfg__iirCfg2__threshold:
        val = cfg->h3aCfg.afCfg.iirCfg2.threshold;
        break;
    case h3aCfg__afCfg__iirFiltStartPos:
        val = cfg->h3aCfg.afCfg.iirFiltStartPos;
        break;
    case h3aCfg__afCfg__midFiltThreshold:
        val = cfg->h3aCfg.afCfg.midFiltThreshold;
        break;
    case h3aCfg__afCfg__paxelCfg__height:
        val = cfg->h3aCfg.afCfg.paxelCfg.height;
        break;
    case h3aCfg__afCfg__paxelCfg__horzCount:
        val = cfg->h3aCfg.afCfg.paxelCfg.horzCount;
        break;
    case h3aCfg__afCfg__paxelCfg__horzIncr:
        val = cfg->h3aCfg.afCfg.paxelCfg.horzIncr;
        break;
    case h3aCfg__afCfg__paxelCfg__pos__startX:
        val = cfg->h3aCfg.afCfg.paxelCfg.pos.startX;
        break;
    case h3aCfg__afCfg__paxelCfg__pos__startY:
        val = cfg->h3aCfg.afCfg.paxelCfg.pos.startY;
        break;
    case h3aCfg__afCfg__paxelCfg__vertCount:
        val = cfg->h3aCfg.afCfg.paxelCfg.vertCount;
        break;
    case h3aCfg__afCfg__paxelCfg__vertIncr:
        val = cfg->h3aCfg.afCfg.paxelCfg.vertIncr;
        break;
    case h3aCfg__afCfg__paxelCfg__width:
        val = cfg->h3aCfg.afCfg.paxelCfg.width;
        break;
    case h3aCfg__afCfg__rgbPos:
        val = cfg->h3aCfg.afCfg.rgbPos;
        break;
    case h3aCfg__afCfg__vfMode:
        val = cfg->h3aCfg.afCfg.vfMode;
        break;
    case h3aCfg__module:
        val = cfg->h3aCfg.module;
        break;
    case h3aCfg__outputSize:
        val = cfg->h3aCfg.outputSize;
        break;
    case h3aCfg__pos__startX:
        val = cfg->h3aCfg.pos.startX;
        break;
    case h3aCfg__pos__startY:
        val = cfg->h3aCfg.pos.startY;
        break;
    case h3aInCfg__inSel:
        val = cfg->h3aInCfg.inSel;
        break;
    case h3aInCfg__shift:
        val = cfg->h3aInCfg.shift;
        break;
    case h3aLutCfg__clip:
        val = cfg->h3aLutCfg.clip;
        break;
    case h3aLutCfg__enable:
        val = cfg->h3aLutCfg.enable;
        break;
    case h3aLutCfg__inputBits:
        val = cfg->h3aLutCfg.inputBits;
        break;
    case histCfg__enable:
        val = cfg->histCfg.enable;
        break;
    case histCfg__input:
        val = cfg->histCfg.input;
        break;
    case histCfg__roi__cropHeight:
        val = cfg->histCfg.roi.cropHeight;
        break;
    case histCfg__roi__cropStartX:
        val = cfg->histCfg.roi.cropStartX;
        break;
    case histCfg__roi__cropStartY:
        val = cfg->histCfg.roi.cropStartY;
        break;
    case histCfg__roi__cropWidth:
        val = cfg->histCfg.roi.cropWidth;
        break;
    case lscCfg__enable:
        val = cfg->lscCfg.enable;
        break;
    case lscCfg__gainFmt:
        val = cfg->lscCfg.gainFmt;
        break;
    case lscCfg__horzDsFactor:
        val = cfg->lscCfg.horzDsFactor;
        break;
    case lscCfg__numTblEntry:
        val = cfg->lscCfg.numTblEntry;
        break;
    case lscCfg__vertDsFactor:
        val = cfg->lscCfg.vertDsFactor;
        break;
    case merge1Cfg__afe:
        val = cfg->merge1Cfg.afe;
        break;
    case merge1Cfg__afm:
        val = cfg->merge1Cfg.afm;
        break;
    case merge1Cfg__bf:
        val = cfg->merge1Cfg.bf;
        break;
    case merge1Cfg__dst:
        val = cfg->merge1Cfg.dst;
        break;
    case merge1Cfg__enable:
        val = cfg->merge1Cfg.enable;
        break;
    case merge1Cfg__glong:
        val = cfg->merge1Cfg.glong;
        break;
    case merge1Cfg__gshort:
        val = cfg->merge1Cfg.gshort;
        break;
    case merge1Cfg__lbit:
        val = cfg->merge1Cfg.lbit;
        break;
    case merge1Cfg__lbk:
        // if (cfg->merge1Cfg.lbk != NULL)
            val = cfg->merge1Cfg.lbk[x];
        // else
            // isp_tracelog_e("cannot read becuase cfg->merge1Cfg.lbk = NULL\n");
        break;
    case merge1Cfg__lwb:
        // if (cfg->merge1Cfg.lwb != NULL)
            val = cfg->merge1Cfg.lwb[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->merge1Cfg.lwb = NULL\n");
        break;
    case merge1Cfg__mad:
        val = cfg->merge1Cfg.mad;
        break;
    case merge1Cfg__mas:
        val = cfg->merge1Cfg.mas;
        break;
    case merge1Cfg__mergeClip:
        val = cfg->merge1Cfg.mergeClip;
        break;
    case merge1Cfg__mergeShift:
        val = cfg->merge1Cfg.mergeShift;
        break;
    case merge1Cfg__sbit:
        val = cfg->merge1Cfg.sbit;
        break;
    case merge1Cfg__sbk:
        // if (cfg->merge1Cfg.sbk != NULL)
            val = cfg->merge1Cfg.sbk[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->merge1Cfg.sbk = NULL\n");
        break;
    case merge1Cfg__swb:
        // if (cfg->merge1Cfg.swb != NULL)
            val = cfg->merge1Cfg.swb[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->merge1Cfg.swb = NULL\n");
        break;
    case merge1Cfg__useShortExpForWgtCalc:
        val = cfg->merge1Cfg.useShortExpForWgtCalc;
        break;
    case merge1Cfg__wdrThr:
        val = cfg->merge1Cfg.wdrThr;
        break;
    case merge2Cfg__afe:
        val = cfg->merge2Cfg.afe;
        break;
    case merge2Cfg__afm:
        val = cfg->merge2Cfg.afm;
        break;
    case merge2Cfg__bf:
        val = cfg->merge2Cfg.bf;
        break;
    case merge2Cfg__dst:
        val = cfg->merge2Cfg.dst;
        break;
    case merge2Cfg__enable:
        val = cfg->merge2Cfg.enable;
        break;
    case merge2Cfg__glong:
        val = cfg->merge2Cfg.glong;
        break;
    case merge2Cfg__gshort:
        val = cfg->merge2Cfg.gshort;
        break;
    case merge2Cfg__lbit:
        val = cfg->merge2Cfg.lbit;
        break;
    case merge2Cfg__lbk:
        // if (cfg->merge2Cfg.lbk != NULL)
            val = cfg->merge2Cfg.lbk[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->merge2Cfg.lbk = NULL\n");
        break;
    case merge2Cfg__lwb:
        // if (cfg->merge2Cfg.lwb != NULL)
            val = cfg->merge2Cfg.lwb[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->merge2Cfg.lwb = NULL\n");
        break;
    case merge2Cfg__mad:
        val = cfg->merge2Cfg.mad;
        break;
    case merge2Cfg__mas:
        val = cfg->merge2Cfg.mas;
        break;
    case merge2Cfg__mergeClip:
        val = cfg->merge2Cfg.mergeClip;
        break;
    case merge2Cfg__mergeShift:
        val = cfg->merge2Cfg.mergeShift;
        break;
    case merge2Cfg__sbit:
        val = cfg->merge2Cfg.sbit;
        break;
    case merge2Cfg__sbk:
        // if (cfg->merge2Cfg.sbk != NULL)
            val = cfg->merge2Cfg.sbk[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->merge2Cfg.sbk = NULL\n");
        break;
    case merge2Cfg__swb:
        // if (cfg->merge2Cfg.swb != NULL)
            val = cfg->merge2Cfg.swb[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->merge2Cfg.swb = NULL\n");
        break;
    case merge2Cfg__useShortExpForWgtCalc:
        val = cfg->merge2Cfg.useShortExpForWgtCalc;
        break;
    case merge2Cfg__wdrThr:
        val = cfg->merge2Cfg.wdrThr;
        break;
    case nsf4Cfg__gains:
        // if (cfg->nsf4Cfg.gains != NULL)
            val = cfg->nsf4Cfg.gains[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->nsf4Cfg.gains = NULL\n");
        break;
    case nsf4Cfg__lsccCfg__enable:
        val = cfg->nsf4Cfg.lsccCfg.enable;
        break;
    case nsf4Cfg__lsccCfg__gMaxCfg:
        val = cfg->nsf4Cfg.lsccCfg.gMaxCfg;
        break;
    case nsf4Cfg__lsccCfg__khCfg:
        val = cfg->nsf4Cfg.lsccCfg.khCfg;
        break;
    case nsf4Cfg__lsccCfg__kvCfg:
        val = cfg->nsf4Cfg.lsccCfg.kvCfg;
        break;
    case nsf4Cfg__lsccCfg__lensCenterX:
        val = cfg->nsf4Cfg.lsccCfg.lensCenterX;
        break;
    case nsf4Cfg__lsccCfg__lensCenterY:
        val = cfg->nsf4Cfg.lsccCfg.lensCenterY;
        break;
    case nsf4Cfg__lsccCfg__pwlCurve:
        // if (cfg->nsf4Cfg.lsccCfg.pwlCurve != NULL)
            val = cfg->nsf4Cfg.lsccCfg.pwlCurve[y][x].posX;
        // else
        //     isp_tracelog_e("cannot read becuase cfg->nsf4Cfg.lsccCfg.pwlCurve = NULL\n");
        break;
    case nsf4Cfg__lsccCfg__setSel:
        val = cfg->nsf4Cfg.lsccCfg.setSel;
        break;
    case nsf4Cfg__lsccCfg__tCfg:
        val = cfg->nsf4Cfg.lsccCfg.tCfg;
        break;
    case nsf4Cfg__mode:
        val = cfg->nsf4Cfg.mode;
        break;
    case nsf4Cfg__tKnee:
        val = cfg->nsf4Cfg.tKnee;
        break;
    case nsf4Cfg__tnCurve:
        // if (cfg->nsf4Cfg.tnCurve != NULL)
            val = cfg->nsf4Cfg.tnCurve[y][x].posX;
        // else
        //     isp_tracelog_e("cannot read becuase cfg->nsf4Cfg.tnCurve = NULL\n");
        break;
    case nsf4Cfg__tnScale_0:
    case nsf4Cfg__tnScale_1:
    case nsf4Cfg__tnScale_2:
            val = cfg->nsf4Cfg.tnScale[nsf4Cfg__tnScale_2-id];
        break;
    case pwlCfg1__enable:
        val = cfg->pwlCfg1.enable;
        break;
    case pwlCfg1__gain:
        // if (cfg->pwlCfg1.gain != NULL)
            val = cfg->pwlCfg1.gain[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->pwlCfg1.gain = NULL\n");
        break;
    case pwlCfg1__mask:
        val = cfg->pwlCfg1.mask;
        break;
    case pwlCfg1__offset:
        // if (cfg->pwlCfg1.offset != NULL)
            val = cfg->pwlCfg1.offset[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->pwlCfg1.offset = NULL\n");
        break;
    case pwlCfg1__outClip:
        val = cfg->pwlCfg1.outClip;
        break;
    case pwlCfg1__shift:
        val = cfg->pwlCfg1.shift;
        break;
    case pwlCfg1__slope1:
        val = cfg->pwlCfg1.slope1;
        break;
    case pwlCfg1__slope2:
        val = cfg->pwlCfg1.slope2;
        break;
    case pwlCfg1__slope3:
        val = cfg->pwlCfg1.slope3;
        break;
    case pwlCfg1__slope4:
        val = cfg->pwlCfg1.slope4;
        break;
    case pwlCfg1__slopeShift:
        val = cfg->pwlCfg1.slopeShift;
        break;
    case pwlCfg1__xthr1:
        val = cfg->pwlCfg1.xthr1;
        break;
    case pwlCfg1__xthr2:
        val = cfg->pwlCfg1.xthr2;
        break;
    case pwlCfg1__xthr3:
        val = cfg->pwlCfg1.xthr3;
        break;
    case pwlCfg1__ythr1:
        val = cfg->pwlCfg1.ythr1;
        break;
    case pwlCfg1__ythr2:
        val = cfg->pwlCfg1.ythr2;
        break;
    case pwlCfg1__ythr3:
        val = cfg->pwlCfg1.ythr3;
        break;
    case pwlCfg2__enable:
        val = cfg->pwlCfg2.enable;
        break;
    case pwlCfg2__gain:
        // if (cfg->pwlCfg2.gain != NULL)
            val = cfg->pwlCfg2.gain[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->pwlCfg2.gain = NULL\n");
        break;
    case pwlCfg2__mask:
        val = cfg->pwlCfg2.mask;
        break;
    case pwlCfg2__offset:
        // if (cfg->pwlCfg2.offset != NULL)
            val = cfg->pwlCfg2.offset[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->pwlCfg2.offset = NULL\n");
        break;
    case pwlCfg2__outClip:
        val = cfg->pwlCfg2.outClip;
        break;
    case pwlCfg2__shift:
        val = cfg->pwlCfg2.shift;
        break;
    case pwlCfg2__slope1:
        val = cfg->pwlCfg2.slope1;
        break;
    case pwlCfg2__slope2:
        val = cfg->pwlCfg2.slope2;
        break;
    case pwlCfg2__slope3:
        val = cfg->pwlCfg2.slope3;
        break;
    case pwlCfg2__slope4:
        val = cfg->pwlCfg2.slope4;
        break;
    case pwlCfg2__slopeShift:
        val = cfg->pwlCfg2.slopeShift;
        break;
    case pwlCfg2__xthr1:
        val = cfg->pwlCfg2.xthr1;
        break;
    case pwlCfg2__xthr2:
        val = cfg->pwlCfg2.xthr2;
        break;
    case pwlCfg2__xthr3:
        val = cfg->pwlCfg2.xthr3;
        break;
    case pwlCfg2__ythr1:
        val = cfg->pwlCfg2.ythr1;
        break;
    case pwlCfg2__ythr2:
        val = cfg->pwlCfg2.ythr2;
        break;
    case pwlCfg2__ythr3:
        val = cfg->pwlCfg2.ythr3;
        break;
    case pwlCfg3__enable:
        val = cfg->pwlCfg3.enable;
        break;
    case pwlCfg3__gain:
        // if (cfg->pwlCfg3.gain != NULL)
            val = cfg->pwlCfg3.gain[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->pwlCfg3.gain = NULL\n");
        break;
    case pwlCfg3__mask:
        val = cfg->pwlCfg3.mask;
        break;
    case pwlCfg3__offset:
        // if (cfg->pwlCfg3.offset != NULL)
            val = cfg->pwlCfg3.offset[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->pwlCfg3.offset = NULL\n");
        break;
    case pwlCfg3__outClip:
        val = cfg->pwlCfg3.outClip;
        break;
    case pwlCfg3__shift:
        val = cfg->pwlCfg3.shift;
        break;
    case pwlCfg3__slope1:
        val = cfg->pwlCfg3.slope1;
        break;
    case pwlCfg3__slope2:
        val = cfg->pwlCfg3.slope2;
        break;
    case pwlCfg3__slope3:
        val = cfg->pwlCfg3.slope3;
        break;
    case pwlCfg3__slope4:
        val = cfg->pwlCfg3.slope4;
        break;
    case pwlCfg3__slopeShift:
        val = cfg->pwlCfg3.slopeShift;
        break;
    case pwlCfg3__xthr1:
        val = cfg->pwlCfg3.xthr1;
        break;
    case pwlCfg3__xthr2:
        val = cfg->pwlCfg3.xthr2;
        break;
    case pwlCfg3__xthr3:
        val = cfg->pwlCfg3.xthr3;
        break;
    case pwlCfg3__ythr1:
        val = cfg->pwlCfg3.ythr1;
        break;
    case pwlCfg3__ythr2:
        val = cfg->pwlCfg3.ythr2;
        break;
    case pwlCfg3__ythr3:
        val = cfg->pwlCfg3.ythr3;
        break;
    case revPrcpCfg__enable:
        val = cfg->revPrcpCfg.enable;
        break;
    case revPrcpCfg__table:
        // if (cfg->revPrcpCfg.table != NULL)
            val = cfg->revPrcpCfg.table[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->revPrcpCfg.table = NULL\n");
        break;
    case rfeLut20to16Cfg__clip:
        val = cfg->rfeLut20to16Cfg.clip;
        break;
    case rfeLut20to16Cfg__enable:
        val = cfg->rfeLut20to16Cfg.enable;
        break;
    case rfeLut20to16Cfg__inputBits:
        val = cfg->rfeLut20to16Cfg.inputBits;
        break;
    case rgb2hsvCfg__h1Input:
        val = cfg->rgb2hsvCfg.h1Input;
        break;
    case rgb2hsvCfg__h2Input:
        val = cfg->rgb2hsvCfg.h2Input;
        break;
    case rgb2hsvCfg__inputSelect:
        val = cfg->rgb2hsvCfg.inputSelect;
        break;
    case rgb2hsvCfg__offset:
        val = cfg->rgb2hsvCfg.offset;
        break;
    case rgb2hsvCfg__satDiv:
        val = cfg->rgb2hsvCfg.satDiv;
        break;
    case rgb2hsvCfg__satMinThr:
        val = cfg->rgb2hsvCfg.satMinThr;
        break;
    case rgb2hsvCfg__satMode:
        val = cfg->rgb2hsvCfg.satMode;
        break;
    case rgb2hsvCfg__threshold:
        // if (cfg->rgb2hsvCfg.threshold != NULL)
            val = cfg->rgb2hsvCfg.threshold[x];
        // else
            // isp_tracelog_e("cannot read becuase cfg->rgb2hsvCfg.threshold = NULL\n");
        break;
    case rgb2hsvCfg__useWbDataForGreyCalc:
        val = cfg->rgb2hsvCfg.useWbDataForGreyCalc;
        break;
    case rgb2hsvCfg__wbOffset:
        // if (cfg->rgb2hsvCfg.wbOffset != NULL)
            val = cfg->rgb2hsvCfg.wbOffset[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->rgb2hsvCfg.wbOffset = NULL\n");
        break;
    case rgb2hsvCfg__weights:
        // if (cfg->rgb2hsvCfg.weights != NULL)
            val = cfg->rgb2hsvCfg.weights[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->rgb2hsvCfg.weights = NULL\n");
        break;
    case rgb2yuvCfg__offsets:
        // if (cfg->rgb2yuvCfg.offsets != NULL)
            val = cfg->rgb2yuvCfg.offsets[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->rgb2yuvCfg.offsets = NULL\n");
        break;
    case rgb2yuvCfg__weights:
        // if (cfg->rgb2yuvCfg.weights != NULL)
            val = cfg->rgb2yuvCfg.weights[y][x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->rgb2yuvCfg.weights = NULL\n");
        break;
    case wbCfg__gain:
        // if (cfg->wbCfg.gain != NULL)
            val = cfg->wbCfg.gain[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->wbCfg.gain = NULL\n");
        break;
    case wbCfg__offset:
        // if (cfg->wbCfg.offset != NULL)
            val = cfg->wbCfg.offset[x];
        // else
        //     isp_tracelog_e("cannot read becuase cfg->wbCfg.offset = NULL\n");
        break;
    case yuvSatLutCfg__enableChromaLut:
        val = cfg->yuvSatLutCfg.enableChromaLut;
        break;
    case yuvSatLutCfg__enableLumaLut:
        val = cfg->yuvSatLutCfg.enableLumaLut;
        break;
    case yuvSatLutCfg__enableSaturLut:
        val = cfg->yuvSatLutCfg.enableSaturLut;
        break;
    case yuvSatLutCfg__lumaInputBits:
        val = cfg->yuvSatLutCfg.lumaInputBits;
        break;
    default:
        isp_tracelog_e("Cannot read config parameter %s id %s\n", line, get_string_from_id(id));
        break;
    }

    return val;
}

#endif //CONFIG_READER_H

/* PRQA S 1055 -- */
/* PRQA S 3852 -- */
/* PRQA S 3854 -- */
/* PRQA S 3856 -- */
/* PRQA S 3834 -- */
/* PRQA S 3840 -- */
/* PRQA S 3844 -- */
/* PRQA S 3844 -- */
/* PRQA S 1442 -- */
/* PRQA S 0491 -- */
/* PRQA S 3138 -- */
/* PRQA S 3480 -- */
/* PRQA S 3450 -- */
/* PRQA S 0781 -- */
/* PRQA S 0739 -- */
/* PRQA S 0602 -- */
