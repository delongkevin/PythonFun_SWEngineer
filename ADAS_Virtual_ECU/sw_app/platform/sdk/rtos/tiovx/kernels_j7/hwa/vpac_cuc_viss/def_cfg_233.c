/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           def_cfg.c
 *  @brief          default ISP configuration implementation
 *
 *
 *  @version        3.31
 *  @author         Ronzhin Alexander
 *  @date           01.10.2021
 *
 * =========================================================================
 *
 *  @par          Change History:
 *
 * ========================================================================= */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#ifdef ISP_SENSOR_AR233

#include <def_cfg.h>


static void set_default_nsf4Cfg(Nsf4v_Config *t)
{
    /*0-3 bit per BAYER color component indicating Decomp sub component*/
    /*4 bit controlling T_n calculation*/
    t->mode = 16;
    /*U4.9*/
    t->gains[0] = 512;
    t->gains[1] = 512;
    t->gains[2] = 512;
    t->gains[3] = 512;
    /* U suppression curve knee. Same knee value for all 9 levels x 4 color components.
    * X (LL2) value which separates constant suppression of 1.0 from linear suppression.
    * U0.6
    */
    t->tKnee = 32;
    /* Tn scaling factor multiplied by all 4 color components Tn after 12 segment PWL.
    * Different scaling factor per level
    * U3.5
    */
    t->tnScale[0] = 32;
    t->tnScale[1] = 0;
    t->tnScale[2] = 0;
    /*
    * LL2 averaged input value into lookup rounded down to nearest X value.
    * (X0 programmed value is unused and defaults to a value of 0 in hardware implementation)
    * U16
    */
    t->tnCurve[0][0].posX = 0;//0;//0;
    t->tnCurve[0][1].posX = 64;//2048;//64;
    t->tnCurve[0][2].posX = 256;//3040;//256;
    t->tnCurve[0][3].posX = 1024;//4096;//1024;
    t->tnCurve[0][4].posX = 4096;//4096;//1024;
    t->tnCurve[0][5].posX = 8192;//4096;//1024;
    t->tnCurve[0][6].posX = 16384;//4096;//1024;
    t->tnCurve[0][7].posX = 32768;//4096;//1024;
    t->tnCurve[0][8].posX = 40960;//4096;//1024;
    t->tnCurve[0][9].posX = 49152;//4096;//1024;
    t->tnCurve[0][10].posX = 57344;//4096;//1024;
    t->tnCurve[0][11].posX = 64000;//4096;//1024;
    t->tnCurve[1][0].posX = 0;//0;//0;
    t->tnCurve[1][1].posX = 64;//2048;//64;
    t->tnCurve[1][2].posX = 256;//3040;//256;
    t->tnCurve[1][3].posX = 1024;//4096;//1024;
    t->tnCurve[1][4].posX = 4096;//4096;//1024;
    t->tnCurve[1][5].posX = 8192;//4096;//1024;
    t->tnCurve[1][6].posX = 16384;//4096;//1024;
    t->tnCurve[1][7].posX = 32768;//4096;//1024;
    t->tnCurve[1][8].posX = 40960;//4096;//1024;
    t->tnCurve[1][9].posX = 49152;//4096;//1024;
    t->tnCurve[1][10].posX = 57344;//4096;//1024;
    t->tnCurve[1][11].posX = 64000;//4096;//1024;
    t->tnCurve[2][0].posX = 0;//0;//0;
    t->tnCurve[2][1].posX = 64;//2048;//64;
    t->tnCurve[2][2].posX = 256;//3040;//256;
    t->tnCurve[2][3].posX = 1024;//4096;//1024;
    t->tnCurve[2][4].posX = 4096;//4096;//1024;
    t->tnCurve[2][5].posX = 8192;//4096;//1024;
    t->tnCurve[2][6].posX = 16384;//4096;//1024;
    t->tnCurve[2][7].posX = 32768;//4096;//1024;
    t->tnCurve[2][8].posX = 40960;//4096;//1024;
    t->tnCurve[2][9].posX = 49152;//4096;//1024;
    t->tnCurve[2][10].posX = 57344;//4096;//1024;
    t->tnCurve[2][11].posX = 64000;//4096;//1024;
    t->tnCurve[3][0].posX = 0;//0;//0;
    t->tnCurve[3][1].posX = 64;//2048;//64;
    t->tnCurve[3][2].posX = 256;//3040;//256;
    t->tnCurve[3][3].posX = 1024;//4096;//1024;
    t->tnCurve[3][4].posX = 4096;//4096;//1024;
    t->tnCurve[3][5].posX = 8192;//4096;//1024;
    t->tnCurve[3][6].posX = 16384;//4096;//1024;
    t->tnCurve[3][7].posX = 32768;//4096;//1024;
    t->tnCurve[3][8].posX = 40960;//4096;//1024;
    t->tnCurve[3][9].posX = 49152;//4096;//1024;
    t->tnCurve[3][10].posX = 57344;//4096;//1024;
    t->tnCurve[3][11].posX = 64000;//4096;//1024;

    /*
    * T_n resulting value from lookup.
    * Starting point from which SLOPE will linearly calculate between X Y points
    * U15
    */
    t->tnCurve[0][0].posY = 32;//0;//16;
    t->tnCurve[0][1].posY = 64;//2048;//20;
    t->tnCurve[0][2].posY = 96;//65536;//38;
    t->tnCurve[0][3].posY = 128;//0;//76;
    t->tnCurve[1][0].posY = 32;//0;//16;
    t->tnCurve[1][1].posY = 64;//2048;//20;
    t->tnCurve[1][2].posY = 96;//65536;//38;
    t->tnCurve[1][3].posY = 128;//0;//76;
    t->tnCurve[2][0].posY = 32;//0;//16;
    t->tnCurve[2][1].posY = 64;//2048;//20;
    t->tnCurve[2][2].posY = 96;//65536;//38;
    t->tnCurve[2][3].posY = 128;//0;//76;
    t->tnCurve[3][0].posY = 32;//0;//16;
    t->tnCurve[3][1].posY = 64;//2048;//20;
    t->tnCurve[3][2].posY = 96;//65536;//38;
    t->tnCurve[3][3].posY = 128;//0;//76;

    /*S5.11*/
    t->tnCurve[0][0].slope = 4096;//1;//128;
    t->tnCurve[0][1].slope = 4096;//64;//192;
    t->tnCurve[0][2].slope = 2048;//1024;//100;
    t->tnCurve[0][3].slope = 2048;//0;//52;
    t->tnCurve[0][4].slope = 2048;//0;//52;
    t->tnCurve[0][5].slope = 2048;//0;//52;
    t->tnCurve[0][6].slope = 2048;//0;//52;
    t->tnCurve[0][7].slope = 2048;//0;//52;
    t->tnCurve[0][8].slope = 2048;//0;//52;
    t->tnCurve[0][9].slope = 2048;//0;//52;
    t->tnCurve[0][10].slope = 2048;//0;//52;
    t->tnCurve[0][11].slope = 2048;//0;//52;
    t->tnCurve[1][0].slope = 4096;//1;//128;
    t->tnCurve[1][1].slope = 4096;//64;//192;
    t->tnCurve[1][2].slope = 2048;//1024;//100;
    t->tnCurve[1][3].slope = 2048;//0;//52;
    t->tnCurve[1][4].slope = 2048;//0;//52;
    t->tnCurve[1][5].slope = 2048;//0;//52;
    t->tnCurve[1][6].slope = 2048;//0;//52;
    t->tnCurve[1][7].slope = 2048;//0;//52;
    t->tnCurve[1][8].slope = 2048;//0;//52;
    t->tnCurve[1][9].slope = 2048;//0;//52;
    t->tnCurve[1][10].slope = 2048;//0;//52;
    t->tnCurve[1][11].slope = 2048;//0;//52;
    t->tnCurve[2][0].slope = 4096;//1;//128;
    t->tnCurve[2][1].slope = 4096;//64;//192;
    t->tnCurve[2][2].slope = 2048;//1024;//100;
    t->tnCurve[2][3].slope = 2048;//0;//52;
    t->tnCurve[2][4].slope = 2048;//0;//52;
    t->tnCurve[2][5].slope = 2048;//0;//52;
    t->tnCurve[2][6].slope = 2048;//0;//52;
    t->tnCurve[2][7].slope = 2048;//0;//52;
    t->tnCurve[2][8].slope = 2048;//0;//52;
    t->tnCurve[2][9].slope = 2048;//0;//52;
    t->tnCurve[2][10].slope = 2048;//0;//52;
    t->tnCurve[2][11].slope = 2048;//0;//52;
    t->tnCurve[3][0].slope = 4096;//1;//128;
    t->tnCurve[3][1].slope = 4096;//64;//192;
    t->tnCurve[3][2].slope = 2048;//1024;//100;
    t->tnCurve[3][3].slope = 2048;//0;//52;
    t->tnCurve[3][4].slope = 2048;//0;//52;
    t->tnCurve[3][5].slope = 2048;//0;//52;
    t->tnCurve[3][6].slope = 2048;//0;//52;
    t->tnCurve[3][7].slope = 2048;//0;//52;
    t->tnCurve[3][8].slope = 2048;//0;//52;
    t->tnCurve[3][9].slope = 2048;//0;//52;
    t->tnCurve[3][10].slope = 2048;//0;//52;
    t->tnCurve[3][11].slope = 2048;//0;//52;


    t->lsccCfg.enable         = 0;
    t->lsccCfg.lensCenterX    = 0;
    t->lsccCfg.lensCenterY    = 0;
    t->lsccCfg.tCfg           = 0;
    t->lsccCfg.khCfg          = 0;
    t->lsccCfg.kvCfg          = 0;
    t->lsccCfg.gMaxCfg        = 0;
    t->lsccCfg.setSel         = 0;
    uint32_t j;

    /*Set 0 will be setted by tuned values*/
    int32_t posX_default[NSF4_LSCC_MAX_SEGMENT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int32_t posY_default[NSF4_LSCC_MAX_SEGMENT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int32_t slope_default[NSF4_LSCC_MAX_SEGMENT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (j = 0U; j < NSF4_LSCC_MAX_SEGMENT; j ++)
    {
            t->lsccCfg.pwlCurve[0][j].posX = posX_default[j];
            t->lsccCfg.pwlCurve[0][j].posY = posY_default[j];
            t->lsccCfg.pwlCurve[0][j].slope = slope_default[j];
    }

    /*Set 1 will not be used*/
    for (j = 0U; j < NSF4_LSCC_MAX_SEGMENT; j ++)
    {
            t->lsccCfg.pwlCurve[1][j].posX = 0;
            t->lsccCfg.pwlCurve[1][j].posY = 0;
            t->lsccCfg.pwlCurve[1][j].slope = 0;
    }
}

static void set_default_pwl_lut_cfg(Vhwa_LutConfig  *lutCfg, uint32_t enable)
{
    uint32_t i;

    /*Gamma 0.8*/
    uint32_t tableAddr_default[RFE_COMP_DECOMP_LUT_SIZE] = {0, 16, 28, 39, 49, 58, 67, 76, 84, 93, 101, 109, 117, 125, 132, 140, 147, 154, 162, 169, 176, 183, 190, 197, 203, 210, 217, 223, 230, 237, 243, 250, 256, 262, 269, 275, 281, 288, 294, 300, 306, 312, 318, 324, 330, 336, 342, 348, 354, 360, 366, 372, 378, 383, 389, 395, 401, 406, 412, 418, 423, 429, 435, 440, 446, 451, 457, 462, 468, 473, 479, 484, 490, 495, 501, 506, 511, 517, 522, 527, 533, 538, 543, 549, 554, 559, 565, 570, 575, 580, 585, 591, 596, 601, 606, 611, 617, 622, 627, 632, 637, 642, 647, 652, 657, 662, 667, 672, 677, 682, 687, 692, 697, 702, 707, 712, 717, 722, 727, 732, 737, 742, 747, 752, 757, 761, 766, 771, 776, 1073, 1351, 1615, 1869, 2114, 2353, 2585, 2812, 3035, 3254, 3469, 3681, 3890, 4096, 4300, 4501, 4700, 4897, 5091, 5284, 5476, 5665, 5854, 6040, 6225, 6409, 6591, 6773, 6953, 7132, 7309, 7486, 7662, 7836, 8010, 8183, 8354, 8525, 8695, 8865, 9033, 9201, 9368, 9534, 9699, 9864, 10028, 10192, 10354, 10516, 10678, 10839, 10999, 11159, 11318, 11476, 11634, 11792, 11949, 12105, 12261, 12417, 12572, 12726, 12880, 13034, 13187, 13340, 13492, 13644, 13795, 13946, 14097, 14247, 14396, 14546, 14695, 14843, 14992, 15140, 15287, 15434, 15581, 15728, 15874, 16020, 16165, 16310, 16455, 16599, 16744, 16888, 17031, 17174, 17317, 17460, 17602, 17745, 17886, 18028, 18169, 18310, 18451, 18591, 18731, 18871, 19011, 19150, 19290, 19428, 19567, 19706, 19844, 19982, 20119, 20257, 20394, 20531, 20668, 20804, 20941, 21077, 21213, 21348, 21484, 21619, 21754, 21889, 22023, 22158, 22292, 22426, 22560, 22693, 22827, 22960, 23093, 23226, 23358, 23491, 23623, 23755, 23887, 24019, 24150, 24281, 24413, 24544, 24674, 24805, 24935, 25066, 25196, 25326, 25456, 25585, 25715, 25844, 25973, 26102, 26231, 26360, 26488, 26616, 26745, 26873, 27001, 27128, 27256, 27383, 27511, 27638, 27765, 27892, 28018, 28145, 28271, 28398, 28524, 28650, 28776, 28901, 29027, 29152, 29278, 29403, 29528, 29653, 29778, 29902, 30027, 30151, 30276, 30400, 30524, 30648, 30771, 30895, 31019, 31142, 31265, 31388, 31511, 31634, 31757, 31880, 32002, 32125, 32247, 32369, 32491, 32613, 32735, 32857, 32979, 33100, 33222, 33343, 33464, 33585, 33706, 33827, 33948, 34068, 34189, 34309, 34430, 34550, 34670, 34790, 34910, 35030, 35149, 35269, 35389, 35508, 35627, 35746, 35866, 35985, 36103, 36222, 36341, 36460, 36578, 36697, 36815, 36933, 37051, 37169, 37287, 37405, 37523, 37641, 37758, 37876, 37993, 38110, 38228, 38345, 38462, 38579, 38696, 38812, 38929, 39046, 39162, 39279, 39395, 39511, 39627, 39743, 39859, 39975, 40091, 40207, 40322, 40438, 40554, 40669, 40784, 40900, 41015, 41130, 41245, 41360, 41475, 41589, 41704, 41819, 41933, 42048, 42162, 42276, 42391, 42505, 42619, 42733, 42847, 42961, 43074, 43188, 43302, 43415, 43529, 43642, 43755, 43869, 43982, 44095, 44208, 44321, 44434, 44547, 44659, 44772, 44885, 44997, 45109, 45222, 45334, 45446, 45559, 45671, 45783, 45895, 46007, 46118, 46230, 46342, 46454, 46565, 46677, 46788, 46899, 47011, 47122, 47233, 47344, 47455, 47566, 47677, 47788, 47899, 48010, 48120, 48231, 48341, 48452, 48562, 48673, 48783, 48893, 49003, 49113, 49223, 49333, 49443, 49553, 49663, 49772, 49882, 49992, 50101, 50211, 50320, 50430, 50539, 50648, 50757, 50866, 50975, 51084, 51193, 51302, 51411, 51520, 51629, 51737, 51846, 51954, 52063, 52171, 52280, 52388, 52496, 52605, 52713, 52821, 52929, 53037, 53145, 53253, 53361, 53468, 53576, 53684, 53791, 53899, 54006, 54114, 54221, 54329, 54436, 54543, 54650, 54757, 54864, 54971, 55078, 55185, 55292, 55399, 55506, 55613, 55719, 55826, 55932, 56039, 56145, 56252, 56358, 56464, 56571, 56677, 56783, 56889, 56995, 57101, 57207, 57313, 57419, 57525, 57631, 57736, 57842, 57948, 58053, 58159, 58264, 58370, 58475, 58580, 58686, 58791, 58896, 59001, 59106, 59211, 59316, 59421, 59526, 59631, 59736, 59841, 59945, 60050, 60155, 60259, 60364, 60468, 60573, 60677, 60782, 60886, 60990, 61095, 61199, 61303, 61407, 61511, 61615, 61719, 61823, 61927, 62031, 62134, 62238, 62342, 62446, 62549, 62653, 62756, 62860, 62963, 63067, 63170, 63273, 63377, 63480, 63583, 63686, 63789, 63892, 63995, 64098, 64201, 64304, 64407, 64510, 64613, 64716, 64818, 64921, 65023, 65126, 65229, 65331, 65434, 65535};

    lutCfg->enable    = enable;
    lutCfg->inputBits = 20;
    lutCfg->clip      = 65535;

    for (i = 0; i < RFE_COMP_DECOMP_LUT_SIZE; i++)
    {
        lutCfg->tableAddr[i] = tableAddr_default[i];
    }
}

static void set_default_ccm_cfg(Fcp_CcmConfig *ccmCfg)
{
    uint32_t i;
    /*
    * The offsets are 13 bit signed notation (S13Q11) representing a range of -4096 to +4095.
    * The offset is effectively shifted by one (left shifted/ multiplied by 2) before being applied.
    * Note that the block diagram shows a shift of two, however the offset is applied at an intermediate
    * node which is followed by rightshift of 1.
    * With the given notation, an offset of 2048 should be programmed to apply a +1 offset to the incoming pixel value.
    * This way the effective range of offset is -2 to +1.995 with 11 bits of fraction.
    */
    for (i = 0u; i < FCP_MAX_CCM_COEFF; i ++)
    {
        ccmCfg->offsets[i] = 0;
    }

    ccmCfg->weights[0][0] = 411;
    ccmCfg->weights[0][1] = 3982;
    ccmCfg->weights[0][2] = 4055;
    ccmCfg->weights[0][3] = 0;
    ccmCfg->weights[1][0] = 3998;
    ccmCfg->weights[1][1] = 381;
    ccmCfg->weights[1][2] = 4069;
    ccmCfg->weights[1][3] = 0;
    ccmCfg->weights[2][0] = 4093;
    ccmCfg->weights[2][1] = 3860;
    ccmCfg->weights[2][2] = 495;
    ccmCfg->weights[2][3] = 0;
}

static void set_default_H3A_config(H3a_Config *h3aCfg, uint32_t width, uint32_t height)
{

    /* MAP DCC config to FVID2 driver config */
    h3aCfg->module                  = H3A_MODULE_AEWB;
    h3aCfg->pos.startX              = 0u;
    h3aCfg->pos.startY              = 0u;
    h3aCfg->aewbCfg.enableALowComp         = 0;
    h3aCfg->aewbCfg.enableMedFilt          = 0;
    h3aCfg->aewbCfg.winCfg.pos.startX      = 0;
    h3aCfg->aewbCfg.winCfg.pos.startY      = 0;
    h3aCfg->aewbCfg.winCfg.horzCount       = 32;
    h3aCfg->aewbCfg.winCfg.vertCount       = 16;

    uint32_t h3a_win_width = (uint32_t)(floorf(((float32_t)width / (float32_t)h3aCfg->aewbCfg.winCfg.horzCount) / 2.0f) * 2.0f);
    uint32_t h3a_win_height = (uint32_t)(floorf(((float32_t)height / (float32_t)h3aCfg->aewbCfg.winCfg.vertCount) / 2.0f) * 2.0f);
    uint32_t horzIncr = (uint32_t)(ceilf((h3a_win_width / 8.0f) / 2.0f) * 2.0f);
    uint32_t vertIncr = (uint32_t)(ceilf((h3a_win_height / 8.0f) / 2.0f) * 2.0f);
    h3aCfg->aewbCfg.winCfg.width = h3a_win_width;
    h3aCfg->aewbCfg.winCfg.height = h3a_win_height;
    h3aCfg->aewbCfg.winCfg.horzIncr = horzIncr;
    h3aCfg->aewbCfg.winCfg.vertIncr = vertIncr;

    h3aCfg->aewbCfg.blackLineVertStart     = height - 2;
    h3aCfg->aewbCfg.blackLineHeight        = 2;
    h3aCfg->aewbCfg.outMode                = 2;
    h3aCfg->aewbCfg.sumShift               = 2;
    h3aCfg->aewbCfg.satLimit               = 1023;
}

static void set_default_h3a_lut_config(Vhwa_LutConfig *h3aLutCfg)
{
    uint32_t i;
    h3aLutCfg->enable = (uint32_t)TRUE;
    h3aLutCfg->inputBits = 16U;
    h3aLutCfg->clip = 0x3FFU;
    /*Gamma 0.625*/
    static uint32_t def_lut[RFE_H3A_COMP_LUT_SIZE] = {0, 9, 13, 17, 21, 24, 27, 29, 32, 34, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 58, 60, 62, 64, 65, 67, 68, 70, 72, 73, 75, 76, 78, 79, 80, 82, 83, 85, 86, 87, 89, 90, 92, 93, 94, 95, 97, 98, 99, 101, 102, 103, 104, 106, 107, 108, 109, 110, 112, 113, 114, 115, 116, 117, 119, 120, 121, 122, 123, 124, 125, 126, 127, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 177, 178, 179, 180, 181, 185, 188, 191, 195, 198, 202, 205, 208, 211, 215, 218, 221, 224, 227, 230, 233, 236, 239, 242, 245, 248, 251, 254, 257, 260, 263, 265, 268, 271, 274, 276, 279, 282, 285, 287, 290, 293, 295, 298, 300, 303, 306, 308, 311, 313, 316, 318, 321, 323, 326, 328, 331, 333, 336, 338, 341, 343, 345, 348, 350, 353, 355, 357, 360, 362, 364, 367, 369, 371, 374, 376, 378, 380, 383, 385, 387, 389, 392, 394, 396, 398, 400, 403, 405, 407, 409, 411, 414, 416, 418, 420, 422, 424, 426, 428, 431, 433, 435, 437, 439, 441, 443, 445, 447, 449, 451, 453, 455, 457, 459, 461, 463, 465, 467, 469, 471, 473, 475, 477, 479, 481, 483, 485, 487, 489, 491, 493, 495, 497, 499, 501, 503, 505, 506, 508, 510, 512, 514, 516, 518, 520, 522, 523, 525, 527, 529, 531, 533, 535, 536, 538, 540, 542, 544, 546, 547, 549, 551, 553, 555, 557, 558, 560, 562, 564, 565, 567, 569, 571, 573, 574, 576, 578, 580, 581, 583, 585, 587, 588, 590, 592, 594, 595, 597, 599, 601, 602, 604, 606, 607, 609, 611, 613, 614, 616, 618, 619, 621, 623, 624, 626, 628, 629, 631, 633, 634, 636, 638, 639, 641, 643, 644, 646, 648, 649, 651, 653, 654, 656, 657, 659, 661, 662, 664, 666, 667, 669, 670, 672, 674, 675, 677, 678, 680, 682, 683, 685, 686, 688, 690, 691, 693, 694, 696, 698, 699, 701, 702, 704, 705, 707, 708, 710, 712, 713, 715, 716, 718, 719, 721, 722, 724, 726, 727, 729, 730, 732, 733, 735, 736, 738, 739, 741, 742, 744, 745, 747, 748, 750, 751, 753, 754, 756, 757, 759, 760, 762, 763, 765, 766, 768, 769, 771, 772, 774, 775, 777, 778, 780, 781, 783, 784, 786, 787, 788, 790, 791, 793, 794, 796, 797, 799, 800, 802, 803, 804, 806, 807, 809, 810, 812, 813, 815, 816, 817, 819, 820, 822, 823, 825, 826, 827, 829, 830, 832, 833, 834, 836, 837, 839, 840, 841, 843, 844, 846, 847, 849, 850, 851, 853, 854, 855, 857, 858, 860, 861, 862, 864, 865, 867, 868, 869, 871, 872, 873, 875, 876, 878, 879, 880, 882, 883, 884, 886, 887, 889, 890, 891, 893, 894, 895, 897, 898, 899, 901, 902, 903, 905, 906, 907, 909, 910, 911, 913, 914, 916, 917, 918, 920, 921, 922, 924, 925, 926, 927, 929, 930, 931, 933, 934, 935, 937, 938, 939, 941, 942, 943, 945, 946, 947, 949, 950, 951, 952, 954, 955, 956, 958, 959, 960, 962, 963, 964, 965, 967, 968, 969, 971, 972, 973, 975, 976, 977, 978, 980, 981, 982, 984, 985, 986, 987, 989, 990, 991, 992, 994, 995, 996, 998, 999, 1000, 1001, 1003, 1004, 1005, 1006, 1008, 1009, 1010, 1011, 1013, 1014, 1015, 1016, 1018, 1019, 1020, 1021, 1023, 1023};

    for (i = 0U; i < RFE_H3A_COMP_LUT_SIZE; i ++)
    {
        h3aLutCfg->tableAddr[i] = def_lut[i];
    }
}

static void set_default_rfeLut20to16Cfg_config(Vhwa_LutConfig *rfeLut20to16Cfg)
{
    uint32_t i;
    rfeLut20to16Cfg->enable = (uint32_t)FALSE;
    rfeLut20to16Cfg->inputBits = 20;
    rfeLut20to16Cfg->clip = 65535;
    /*Gamma 0.625*/
    static uint32_t def_lut[RFE_H3A_COMP_LUT_SIZE] = {0, 16, 28, 39, 49, 58, 67, 76, 84, 93, 101, 109, 117, 125, 132, 140, 147, 154, 162, 169, 176, 183, 190, 197, 203, 210, 217, 223, 230, 237, 243, 250, 256, 262, 269, 275, 281, 288, 294, 300, 306, 312, 318, 324, 330, 336, 342, 348, 354, 360, 366, 372, 378, 383, 389, 395, 401, 406, 412, 418, 423, 429, 435, 440, 446, 451, 457, 462, 468, 473, 479, 484, 490, 495, 501, 506, 511, 517, 522, 527, 533, 538, 543, 549, 554, 559, 565, 570, 575, 580, 585, 591, 596, 601, 606, 611, 617, 622, 627, 632, 637, 642, 647, 652, 657, 662, 667, 672, 677, 682, 687, 692, 697, 702, 707, 712, 717, 722, 727, 732, 737, 742, 747, 752, 757, 761, 766, 771, 776, 1073, 1351, 1615, 1869, 2114, 2353, 2585, 2812, 3035, 3254, 3469, 3681, 3890, 4096, 4300, 4501, 4700, 4897, 5091, 5284, 5476, 5665, 5854, 6040, 6225, 6409, 6591, 6773, 6953, 7132, 7309, 7486, 7662, 7836, 8010, 8183, 8354, 8525, 8695, 8865, 9033, 9201, 9368, 9534, 9699, 9864, 10028, 10192, 10354, 10516, 10678, 10839, 10999, 11159, 11318, 11476, 11634, 11792, 11949, 12105, 12261, 12417, 12572, 12726, 12880, 13034, 13187, 13340, 13492, 13644, 13795, 13946, 14097, 14247, 14396, 14546, 14695, 14843, 14992, 15140, 15287, 15434, 15581, 15728, 15874, 16020, 16165, 16310, 16455, 16599, 16744, 16888, 17031, 17174, 17317, 17460, 17602, 17745, 17886, 18028, 18169, 18310, 18451, 18591, 18731, 18871, 19011, 19150, 19290, 19428, 19567, 19706, 19844, 19982, 20119, 20257, 20394, 20531, 20668, 20804, 20941, 21077, 21213, 21348, 21484, 21619, 21754, 21889, 22023, 22158, 22292, 22426, 22560, 22693, 22827, 22960, 23093, 23226, 23358, 23491, 23623, 23755, 23887, 24019, 24150, 24281, 24413, 24544, 24674, 24805, 24935, 25066, 25196, 25326, 25456, 25585, 25715, 25844, 25973, 26102, 26231, 26360, 26488, 26616, 26745, 26873, 27001, 27128, 27256, 27383, 27511, 27638, 27765, 27892, 28018, 28145, 28271, 28398, 28524, 28650, 28776, 28901, 29027, 29152, 29278, 29403, 29528, 29653, 29778, 29902, 30027, 30151, 30276, 30400, 30524, 30648, 30771, 30895, 31019, 31142, 31265, 31388, 31511, 31634, 31757, 31880, 32002, 32125, 32247, 32369, 32491, 32613, 32735, 32857, 32979, 33100, 33222, 33343, 33464, 33585, 33706, 33827, 33948, 34068, 34189, 34309, 34430, 34550, 34670, 34790, 34910, 35030, 35149, 35269, 35389, 35508, 35627, 35746, 35866, 35985, 36103, 36222, 36341, 36460, 36578, 36697, 36815, 36933, 37051, 37169, 37287, 37405, 37523, 37641, 37758, 37876, 37993, 38110, 38228, 38345, 38462, 38579, 38696, 38812, 38929, 39046, 39162, 39279, 39395, 39511, 39627, 39743, 39859, 39975, 40091, 40207, 40322, 40438, 40554, 40669, 40784, 40900, 41015, 41130, 41245, 41360, 41475, 41589, 41704, 41819, 41933, 42048, 42162, 42276, 42391, 42505, 42619, 42733, 42847, 42961, 43074, 43188, 43302, 43415, 43529, 43642, 43755, 43869, 43982, 44095, 44208, 44321, 44434, 44547, 44659, 44772, 44885, 44997, 45109, 45222, 45334, 45446, 45559, 45671, 45783, 45895, 46007, 46118, 46230, 46342, 46454, 46565, 46677, 46788, 46899, 47011, 47122, 47233, 47344, 47455, 47566, 47677, 47788, 47899, 48010, 48120, 48231, 48341, 48452, 48562, 48673, 48783, 48893, 49003, 49113, 49223, 49333, 49443, 49553, 49663, 49772, 49882, 49992, 50101, 50211, 50320, 50430, 50539, 50648, 50757, 50866, 50975, 51084, 51193, 51302, 51411, 51520, 51629, 51737, 51846, 51954, 52063, 52171, 52280, 52388, 52496, 52605, 52713, 52821, 52929, 53037, 53145, 53253, 53361, 53468, 53576, 53684, 53791, 53899, 54006, 54114, 54221, 54329, 54436, 54543, 54650, 54757, 54864, 54971, 55078, 55185, 55292, 55399, 55506, 55613, 55719, 55826, 55932, 56039, 56145, 56252, 56358, 56464, 56571, 56677, 56783, 56889, 56995, 57101, 57207, 57313, 57419, 57525, 57631, 57736, 57842, 57948, 58053, 58159, 58264, 58370, 58475, 58580, 58686, 58791, 58896, 59001, 59106, 59211, 59316, 59421, 59526, 59631, 59736, 59841, 59945, 60050, 60155, 60259, 60364, 60468, 60573, 60677, 60782, 60886, 60990, 61095, 61199, 61303, 61407, 61511, 61615, 61719, 61823, 61927, 62031, 62134, 62238, 62342, 62446, 62549, 62653, 62756, 62860, 62963, 63067, 63170, 63273, 63377, 63480, 63583, 63686, 63789, 63892, 63995, 64098, 64201, 64304, 64407, 64510, 64613, 64716, 64818, 64921, 65023, 65126, 65229, 65331, 65434, 65535};

    for (i = 0U; i < RFE_H3A_COMP_LUT_SIZE; i ++)
    {
        rfeLut20to16Cfg->tableAddr[i] = def_lut[i];
    }
}

static void set_default_ltm_config(Glbce_Config *glbceCfg,
                       Glbce_PerceptConfig *fwdPrcpCfg,
                       Glbce_PerceptConfig *revPrcpCfg)
{
    glbceCfg->irStrength = 255;
    glbceCfg->blackLevel = 0;
    glbceCfg->whiteLevel = 65535;
    glbceCfg->intensityVariance = 12;
    glbceCfg->spaceVariance = 6;
    glbceCfg->brightAmplLimit = 0;
    glbceCfg->darkAmplLimit = 0;
    glbceCfg->dither = 0;
    glbceCfg->maxSlopeLimit = 230;
    glbceCfg->minSlopeLimit = 24;
    glbceCfg->asymLut[0] =  0;
    glbceCfg->asymLut[1] =  38823;
    glbceCfg->asymLut[2] =  43719;
    glbceCfg->asymLut[3] =  46720;
    glbceCfg->asymLut[4] =  48904;
    glbceCfg->asymLut[5] =  50626;
    glbceCfg->asymLut[6] =  52049;
    glbceCfg->asymLut[7] =  53263;
    glbceCfg->asymLut[8] =  54322;
    glbceCfg->asymLut[9] =  55261;
    glbceCfg->asymLut[10] = 56105;
    glbceCfg->asymLut[11] = 56870;
    glbceCfg->asymLut[12] = 57572;
    glbceCfg->asymLut[13] = 58219;
    glbceCfg->asymLut[14] = 58819;
    glbceCfg->asymLut[15] = 59378;
    glbceCfg->asymLut[16] = 59903;
    glbceCfg->asymLut[17] = 60396;
    glbceCfg->asymLut[18] = 60862;
    glbceCfg->asymLut[19] = 61303;
    glbceCfg->asymLut[20] = 61721;
    glbceCfg->asymLut[21] = 62120;
    glbceCfg->asymLut[22] = 62500;
    glbceCfg->asymLut[23] = 62863;
    glbceCfg->asymLut[24] = 63211;
    glbceCfg->asymLut[25] = 63545;
    glbceCfg->asymLut[26] = 63866;
    glbceCfg->asymLut[27] = 64175;
    glbceCfg->asymLut[28] = 64473;
    glbceCfg->asymLut[29] = 64761;
    glbceCfg->asymLut[30] = 65038;
    glbceCfg->asymLut[31] = 65307;
    glbceCfg->asymLut[32] = 65535;
    fwdPrcpCfg->enable = 1;
    fwdPrcpCfg->table[0] =  0;
    fwdPrcpCfg->table[1] =  4622;
    fwdPrcpCfg->table[2] =  8653;
    fwdPrcpCfg->table[3] =  11684;
    fwdPrcpCfg->table[4] =  14195;
    fwdPrcpCfg->table[5] =  16380;
    fwdPrcpCfg->table[6] =  18335;
    fwdPrcpCfg->table[7] =  20118;
    fwdPrcpCfg->table[8] =  21766;
    fwdPrcpCfg->table[9] =  23304;
    fwdPrcpCfg->table[10] = 24751;
    fwdPrcpCfg->table[11] = 26119;
    fwdPrcpCfg->table[12] = 27422;
    fwdPrcpCfg->table[13] = 28665;
    fwdPrcpCfg->table[14] = 29857;
    fwdPrcpCfg->table[15] = 31003;
    fwdPrcpCfg->table[16] = 32108;
    fwdPrcpCfg->table[17] = 33176;
    fwdPrcpCfg->table[18] = 34209;
    fwdPrcpCfg->table[19] = 35211;
    fwdPrcpCfg->table[20] = 36185;
    fwdPrcpCfg->table[21] = 37132;
    fwdPrcpCfg->table[22] = 38055;
    fwdPrcpCfg->table[23] = 38955;
    fwdPrcpCfg->table[24] = 39834;
    fwdPrcpCfg->table[25] = 40693;
    fwdPrcpCfg->table[26] = 41533;
    fwdPrcpCfg->table[27] = 42355;
    fwdPrcpCfg->table[28] = 43161;
    fwdPrcpCfg->table[29] = 43951;
    fwdPrcpCfg->table[30] = 44727;
    fwdPrcpCfg->table[31] = 45488;
    fwdPrcpCfg->table[32] = 46236;
    fwdPrcpCfg->table[33] = 46971;
    fwdPrcpCfg->table[34] = 47694;
    fwdPrcpCfg->table[35] = 48405;
    fwdPrcpCfg->table[36] = 49106;
    fwdPrcpCfg->table[37] = 49795;
    fwdPrcpCfg->table[38] = 50475;
    fwdPrcpCfg->table[39] = 51145;
    fwdPrcpCfg->table[40] = 51805;
    fwdPrcpCfg->table[41] = 52456;
    fwdPrcpCfg->table[42] = 53099;
    fwdPrcpCfg->table[43] = 53733;
    fwdPrcpCfg->table[44] = 54360;
    fwdPrcpCfg->table[45] = 54978;
    fwdPrcpCfg->table[46] = 55589;
    fwdPrcpCfg->table[47] = 56193;
    fwdPrcpCfg->table[48] = 56789;
    fwdPrcpCfg->table[49] = 57379;
    fwdPrcpCfg->table[50] = 57963;
    fwdPrcpCfg->table[51] = 58539;
    fwdPrcpCfg->table[52] = 59110;
    fwdPrcpCfg->table[53] = 59675;
    fwdPrcpCfg->table[54] = 60234;
    fwdPrcpCfg->table[55] = 60787;
    fwdPrcpCfg->table[56] = 61335;
    fwdPrcpCfg->table[57] = 61877;
    fwdPrcpCfg->table[58] = 62414;
    fwdPrcpCfg->table[59] = 62946;
    fwdPrcpCfg->table[60] = 63473;
    fwdPrcpCfg->table[61] = 63996;
    fwdPrcpCfg->table[62] = 64513;
    fwdPrcpCfg->table[63] = 65026;
    fwdPrcpCfg->table[64] = 65535;
    revPrcpCfg->enable = 1;
    revPrcpCfg->table[0] =  0;
    revPrcpCfg->table[1] =  228;
    revPrcpCfg->table[2] =  455;
    revPrcpCfg->table[3] =  683;
    revPrcpCfg->table[4] =  910;
    revPrcpCfg->table[5] =  1138;
    revPrcpCfg->table[6] =  1369;
    revPrcpCfg->table[7] =  1628;
    revPrcpCfg->table[8] =  1912;
    revPrcpCfg->table[9] =  2221;
    revPrcpCfg->table[10] = 2556;
    revPrcpCfg->table[11] = 2916;
    revPrcpCfg->table[12] = 3304;
    revPrcpCfg->table[13] = 3717;
    revPrcpCfg->table[14] = 4158;
    revPrcpCfg->table[15] = 4626;
    revPrcpCfg->table[16] = 5122;
    revPrcpCfg->table[17] = 5645;
    revPrcpCfg->table[18] = 6197;
    revPrcpCfg->table[19] = 6777;
    revPrcpCfg->table[20] = 7386;
    revPrcpCfg->table[21] = 8024;
    revPrcpCfg->table[22] = 8691;
    revPrcpCfg->table[23] = 9387;
    revPrcpCfg->table[24] = 10113;
    revPrcpCfg->table[25] = 10869;
    revPrcpCfg->table[26] = 11654;
    revPrcpCfg->table[27] = 12471;
    revPrcpCfg->table[28] = 13317;
    revPrcpCfg->table[29] = 14194;
    revPrcpCfg->table[30] = 15103;
    revPrcpCfg->table[31] = 16042;
    revPrcpCfg->table[32] = 17012;
    revPrcpCfg->table[33] = 18014;
    revPrcpCfg->table[34] = 19048;
    revPrcpCfg->table[35] = 20113;
    revPrcpCfg->table[36] = 21210;
    revPrcpCfg->table[37] = 22340;
    revPrcpCfg->table[38] = 23501;
    revPrcpCfg->table[39] = 24696;
    revPrcpCfg->table[40] = 25922;
    revPrcpCfg->table[41] = 27182;
    revPrcpCfg->table[42] = 28475;
    revPrcpCfg->table[43] = 29800;
    revPrcpCfg->table[44] = 31159;
    revPrcpCfg->table[45] = 32552;
    revPrcpCfg->table[46] = 33977;
    revPrcpCfg->table[47] = 35437;
    revPrcpCfg->table[48] = 36930;
    revPrcpCfg->table[49] = 38458;
    revPrcpCfg->table[50] = 40019;
    revPrcpCfg->table[51] = 41615;
    revPrcpCfg->table[52] = 43245;
    revPrcpCfg->table[53] = 44910;
    revPrcpCfg->table[54] = 46609;
    revPrcpCfg->table[55] = 48343;
    revPrcpCfg->table[56] = 50112;
    revPrcpCfg->table[57] = 51916;
    revPrcpCfg->table[58] = 53755;
    revPrcpCfg->table[59] = 55630;
    revPrcpCfg->table[60] = 57539;
    revPrcpCfg->table[61] = 59485;
    revPrcpCfg->table[62] = 61466;
    revPrcpCfg->table[63] = 63482;
    revPrcpCfg->table[64] = 65535;
}

static void set_default_demosaic(Fcp_CfaConfig *cfaCfg)
{
    uint32_t i;
    uint32_t set0Thr[FCP_CFA_MAX_SET_THR] = {500, 600, 700, 800, 900, 1000, 1100};
    uint32_t set1Thr[FCP_CFA_MAX_SET_THR] = {0, 100, 200, 300, 400, 500, 600};
    uint32_t set0GradHzMask[FCP_MAX_COLOR_COMP] = {175, 95, 95, 175};
    uint32_t set1GradHzMask[FCP_MAX_COLOR_COMP] = {175, 95, 95, 175};
    uint32_t set0GradVtMask[FCP_MAX_COLOR_COMP] = {175, 95, 95, 175};
    uint32_t set1GradVtMask[FCP_MAX_COLOR_COMP] = {276, 196, 196, 276};
    uint32_t set0IntensityMask[FCP_MAX_COLOR_COMP] = {0, 1, 2, 3};
    uint32_t set0IntensityShift[FCP_MAX_COLOR_COMP] = {4, 5, 6, 7};
    uint32_t set1IntensityMask[FCP_MAX_COLOR_COMP] = {8, 9, 10, 11};
    uint32_t set1IntensityShift[FCP_MAX_COLOR_COMP] = {12, 13, 14, 15};
    static int32_t default_coeff[FCP_MAX_CFA_COEFF] = {-2, 12, -5, 18, -4, 5, 0, -24, 0, -45, 0, -7, -6, 46, 73, 68, 21, 18, 0, 21, 0, 73, 0, -6, -7, 29, -45, 46, -24, 12, 0, -4, 0, -5, 0, -2, 5, -4, 18, -5, 12, -2, -7, 0, -45, 0, -24, 0, 18, 21, 68, 73, 46, -6, -6, 0, 73, 0, 21, 0, 12, -24, 46, -45, 29, -7, -2, 0, -5, 0, -4, 0, 0, -4, 0, -5, 0, -2, -7, 29, -45, 46, -24, 12, 0, 21, 0, 73, 0, -6, -6, 46, 73, 68, 21, 18, 0, -24, 0, -45, 0, -7, -2, 12, -5, 18, -4, 5, -2, 0, -5, 0, -4, 0, 12, -24, 46, -45, 29, -7, -6, 0, 73, 0, 21, 0, 18, 21, 68, 73, 46, -6, -7, 0, -45, 0, -24, 0, 5, -4, 18, -5, 12, -2, -2, 12, -6, 18, -7, 5, 0, -24, 0, 21, 0, -4, -5, 46, 73, 68, -45, 18, 0, -45, 0, 73, 0, -5, -4, 29, 21, 46, -24, 12, 0, -7, 0, -6, 0, -2, 5, -7, 18, -6, 12, -2, -4, 0, 21, 0, -24, 0, 18, -45, 68, 73, 46, -5, -5, 0, 73, 0, -45, 0, 12, -24, 46, 21, 29, -4, -2, 0, -6, 0, -7, 0, 0, -7, 0, -6, 0, -2, -4, 29, 21, 46, -24, 12, 0, -45, 0, 73, 0, -5, -5, 46, 73, 68, -45, 18, 0, -24, 0, 21, 0, -4, -2, 12, -6, 18, -7, 5, -2, 0, -6, 0, -7, 0, 12, -24, 46, 21, 29, -4, -5, 0, 73, 0, -45, 0, 18, -45, 68, 73, 46, -5, -4, 0, 21, 0, -24, 0, 5, -7, 18, -6, 12, -2, 0, 12, 0, 18, 0, 5, 0, 0, 0, 0, 0, 0, 0, 46, 0, 68, 0, 18, 0, 0, 0, 0, 0, 0, 0, 29, 0, 46, 0, 12, 0, 0, 0, 0, 0, 0, 5, 0, 18, 0, 12, 0, 0, 0, 0, 0, 0, 0, 18, 0, 68, 0, 46, 0, 0, 0, 0, 0, 0, 0, 12, 0, 46, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 0, 46, 0, 12, 0, 0, 0, 0, 0, 0, 0, 46, 0, 68, 0, 18, 0, 0, 0, 0, 0, 0, 0, 12, 0, 18, 0, 5, 0, 0, 0, 0, 0, 0, 12, 0, 46, 0, 29, 0, 0, 0, 0, 0, 0, 0, 18, 0, 68, 0, 46, 0, 0, 0, 0, 0, 0, 0, 5, 0, 18, 0, 12, 0, 0, 0, 4, 0, 2, 0, 0, -9, 0, -22, 0, -1, 3, 0, 107, 0, 44, 0, 0, 44, 0, 107, 0, 3, -1, 0, -22, 0, -9, 0, 0, 2, 0, 4, 0, 0, 0, 2, 0, 4, 0, 0, -1, 0, -22, 0, -9, 0, 0, 44, 0, 107, 0, 3, 3, 0, 107, 0, 44, 0, 0, -9, 0, -22, 0, -1, 0, 0, 4, 0, 2, 0, 0, 2, 0, 4, 0, 0, -1, 0, -22, 0, -9, 0, 0, 44, 0, 107, 0, 3, 3, 0, 107, 0, 44, 0, 0, -9, 0, -22, 0, -1, 0, 0, 4, 0, 2, 0, 0, 0, 4, 0, 2, 0, 0, -9, 0, -22, 0, -1, 3, 0, 107, 0, 44, 0, 0, 44, 0, 107, 0, 3, -1, 0, -22, 0, -9, 0, 0, 2, 0, 4, 0, 0, 0, 0, 3, 0, -1, 0, 0, -9, 0, 44, 0, 2, 4, 0, 107, 0, -22, 0, 0, -22, 0, 107, 0, 4, 2, 0, 44, 0, -9, 0, 0, -1, 0, 3, 0, 0, 0, -1, 0, 3, 0, 0, 2, 0, 44, 0, -9, 0, 0, -22, 0, 107, 0, 4, 4, 0, 107, 0, -22, 0, 0, -9, 0, 44, 0, 2, 0, 0, 3, 0, -1, 0, 0, -1, 0, 3, 0, 0, 2, 0, 44, 0, -9, 0, 0, -22, 0, 107, 0, 4, 4, 0, 107, 0, -22, 0, 0, -9, 0, 44, 0, 2, 0, 0, 3, 0, -1, 0, 0, 0, 3, 0, -1, 0, 0, -9, 0, 44, 0, 2, 4, 0, 107, 0, -22, 0, 0, -22, 0, 107, 0, 4, 2, 0, 44, 0, -9, 0, 0, -1, 0, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, -1, 0, -3, 0, 0, 1, 0, 132, 0, -3, 0, 0, -3, 0, 132, 0, 1, 0, 0, -3, 0, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, -3, 0, -1, 0, 0, -3, 0, 132, 0, 1, 1, 0, 132, 0, -3, 0, 0, -1, 0, -3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, -3, 0, -1, 0, 0, -3, 0, 132, 0, 1, 1, 0, 132, 0, -3, 0, 0, -1, 0, -3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, -1, 0, -3, 0, 0, 1, 0, 132, 0, -3, 0, 0, -3, 0, 132, 0, 1, 0, 0, -3, 0, -1, 0, 0, 0, 0, 1, 0, 0, -2, 0, -5, 0, -4, 0, 12, -24, 46, -45, 29, -7, -6, 0, 73, 0, 21, 0, 18, 21, 68, 73, 46, -6, -7, 0, -45, 0, -24, 0, 5, -4, 18, -5, 12, -2, 0, -4, 0, -5, 0, -2, -7, 29, -45, 46, -24, 12, 0, 21, 0, 73, 0, -6, -6, 46, 73, 68, 21, 18, 0, -24, 0, -45, 0, -7, -2, 12, -5, 18, -4, 5, 5, -4, 18, -5, 12, -2, -7, 0, -45, 0, -24, 0, 18, 21, 68, 73, 46, -6, -6, 0, 73, 0, 21, 0, 12, -24, 46, -45, 29, -7, -2, 0, -5, 0, -4, 0, -2, 12, -5, 18, -4, 5, 0, -24, 0, -45, 0, -7, -6, 46, 73, 68, 21, 18, 0, 21, 0, 73, 0, -6, -7, 29, -45, 46, -24, 12, 0, -4, 0, -5, 0, -2, -2, 0, -6, 0, -7, 0, 12, -24, 46, 21, 29, -4, -5, 0, 73, 0, -45, 0, 18, -45, 68, 73, 46, -5, -4, 0, 21, 0, -24, 0, 5, -7, 18, -6, 12, -2, 0, -7, 0, -6, 0, -2, -4, 29, 21, 46, -24, 12, 0, -45, 0, 73, 0, -5, -5, 46, 73, 68, -45, 18, 0, -24, 0, 21, 0, -4, -2, 12, -6, 18, -7, 5, 5, -7, 18, -6, 12, -2, -4, 0, 21, 0, -24, 0, 18, -45, 68, 73, 46, -5, -5, 0, 73, 0, -45, 0, 12, -24, 46, 21, 29, -4, -2, 0, -6, 0, -7, 0, -2, 12, -6, 18, -7, 5, 0, -24, 0, 21, 0, -4, -5, 46, 73, 68, -45, 18, 0, -45, 0, 73, 0, -5, -4, 29, 21, 46, -24, 12, 0, -7, 0, -6, 0, -2, 0, 0, 0, 0, 0, 0, 12, 0, 46, 0, 29, 0, 0, 0, 0, 0, 0, 0, 18, 0, 68, 0, 46, 0, 0, 0, 0, 0, 0, 0, 5, 0, 18, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 29, 0, 46, 0, 12, 0, 0, 0, 0, 0, 0, 0, 46, 0, 68, 0, 18, 0, 0, 0, 0, 0, 0, 0, 12, 0, 18, 0, 5, 5, 0, 18, 0, 12, 0, 0, 0, 0, 0, 0, 0, 18, 0, 68, 0, 46, 0, 0, 0, 0, 0, 0, 0, 12, 0, 46, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 18, 0, 5, 0, 0, 0, 0, 0, 0, 0, 46, 0, 68, 0, 18, 0, 0, 0, 0, 0, 0, 0, 29, 0, 46, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    memcpy(cfaCfg->coeff, default_coeff, FCP_MAX_CFA_COEFF * sizeof(cfaCfg->coeff[0]));
    for (i = 0u; i < FCP_MAX_COLOR_COMP; i ++)
    {
        cfaCfg->bypass[i]            = (uint32_t)FALSE;
        cfaCfg->coreSel[i]           = 0;
        cfaCfg->coreBlendMode[i]     = 2;

        cfaCfg->gradHzPh[0u][i]     = set0GradHzMask[i];
        cfaCfg->gradHzPh[1u][i]     = set1GradHzMask[i];

        cfaCfg->gradVtPh[0u][i]     = set0GradVtMask[i];
        cfaCfg->gradVtPh[1u][i]     = set1GradVtMask[i];

        cfaCfg->intsBitField[0u][i] = set0IntensityMask[i];
        cfaCfg->intsBitField[1u][i] = set1IntensityMask[i];

        cfaCfg->intsShiftPh[0u][i]  = set0IntensityShift[i];
        cfaCfg->intsShiftPh[1u][i]  = set1IntensityShift[i];
    }
    for (i = 0u; i < FCP_CFA_MAX_SET_THR; i++)
    {
        cfaCfg->thr[0u][i] = set0Thr[i];
        cfaCfg->thr[1u][i] = set1Thr[i];
    }
}

static void set_default_rfe_pwl(Rfe_PwlConfig *pwlCfg)
{
    if (NULL != pwlCfg)
    {
        pwlCfg->mask         = 4095u;
        pwlCfg->shift        = 0u;
        pwlCfg->offset[0u]   = -168;
        pwlCfg->offset[1u]   = -168;
        pwlCfg->offset[2u]   = -168;
        pwlCfg->offset[3u]   = -168;
        pwlCfg->gain[0u]     = 512u;
        pwlCfg->gain[1u]     = 512u;
        pwlCfg->gain[2u]     = 512u;
        pwlCfg->gain[3u]     = 512u;

        pwlCfg->enable       = 1u;
        pwlCfg->xthr1        = 2048;
        pwlCfg->xthr2        = 3040;
        pwlCfg->xthr3        = 4000;
        pwlCfg->ythr1        = 2048;
        pwlCfg->ythr2        = 65536;
        pwlCfg->ythr3        = 1048576;
        pwlCfg->slope1       = 1 << 0;
        pwlCfg->slope2       = 1 << 6;
        pwlCfg->slope3       = 1 << 10;
        pwlCfg->slope4       = 1 << 10;
        pwlCfg->slopeShift   = 0u;
        pwlCfg->outClip      = 1048576;
    }
}

static void set_default_rfe_pwl_zero(Rfe_PwlConfig *pwlCfg)
{
    if (NULL != pwlCfg)
    {
        pwlCfg->mask         = 4095u;
        pwlCfg->shift        = 0u;
        pwlCfg->offset[0u]   = 0;
        pwlCfg->offset[1u]   = 0;
        pwlCfg->offset[2u]   = 0;
        pwlCfg->offset[3u]   = 0;
        pwlCfg->gain[0u]     = 512u;
        pwlCfg->gain[1u]     = 512u;
        pwlCfg->gain[2u]     = 512u;
        pwlCfg->gain[3u]     = 512u;

        pwlCfg->enable       = 0u;
        pwlCfg->xthr1        = 2048;
        pwlCfg->xthr2        = 3040;
        pwlCfg->xthr3        = 4000;
        pwlCfg->ythr1        = 2048;
        pwlCfg->ythr2        = 65536;
        pwlCfg->ythr3        = 1048576;
        pwlCfg->slope1       = 1 << 0;
        pwlCfg->slope2       = 1 << 6;
        pwlCfg->slope3       = 1 << 10;
        pwlCfg->slope4       = 1 << 10;
        pwlCfg->slopeShift   = 0u;
        pwlCfg->outClip      = 1048576;
    }
}

static void set_default_rfe_lsc(Rfe_LscConfig *lscCfg, uint32_t width, uint32_t height)
{
    if (NULL != lscCfg)
    {
        lscCfg->enable = 1;
        lscCfg->gainFmt         = RFE_LSC_GAIN_FMT_U8Q7_1;
        lscCfg->horzDsFactor    = RFE_LSC_DS_FACTOR_32;
        lscCfg->vertDsFactor    = RFE_LSC_DS_FACTOR_32;
        static uint32_t lsc_tbl[] = {0, 0, 0, 0, 0, 0, 352330773, 167778826, 50335491, 3328, 2816, 2304, 1792, 1792, 1536, 1280, 1024, 1024, 1024, 768, 768, 512, 512, 512, 256, 256, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 256, 256, 256, 512, 512, 512, 768, 768, 1024, 1024, 1280, 1280, 1536, 1792, 2048, 2304, 3072, 3328, 67113220, 234888462, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 218111245, 50335747, 3328, 2816, 2304, 1792, 1792, 1536, 1280, 1024, 1024, 768, 768, 512, 512, 256, 256, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 256, 256, 256, 512, 512, 512, 768, 1024, 1024, 1280, 1280, 1536, 1792, 2048, 2560, 3072, 3328, 83890949, 285220881, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 285220881, 83890949, 3328, 3072, 2304, 1792, 1792, 1536, 1280, 1024, 1024, 768, 768, 512, 512, 256, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 256, 256, 256, 512, 512, 768, 768, 1024, 1280, 1280, 1536, 1792, 2048, 2560, 3072, 16780801, 134223368, 335553556, 0, 0, 0, 0, 0, 0, 0, 0, 0, 352331029, 134223624, 16780801, 3072, 2560, 2048, 1792, 1536, 1280, 1024, 1024, 768, 768, 512, 256, 256, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 256, 256, 512, 512, 768, 768, 1024, 1280, 1280, 1536, 1792, 2048, 2816, 3072, 33558274, 184556299, 0, 0, 0, 0, 0, 0, 0, 0, 0, 218110989, 50335747, 3072, 2816, 2048, 1792, 1536, 1280, 1024, 1024, 768, 768, 512, 256, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 256, 256, 512, 512, 768, 768, 1024, 1280, 1536, 1536, 1792, 2304, 2816, 3328, 83890949, 285221137, 0, 0, 0, 0, 0, 0, 0, 318776083, 100668422, 3328, 3072, 2304, 1792, 1536, 1536, 1280, 1024, 768, 768, 512, 256, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 256, 512, 512, 768, 768, 1024, 1280, 1536, 1792, 1792, 2560, 3072, 16780801, 151001097, 385885463, 0, 0, 0, 0, 0, 0, 201333516, 33558274, 3072, 2560, 2048, 1792, 1536, 1280, 1024, 768, 768, 512, 256, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 256, 512, 512, 768, 1024, 1024, 1280, 1536, 1792, 2048, 2816, 3328, 67113220, 251666191, 0, 0, 0, 0, 0, 318776339, 100668422, 3328, 2816, 2304, 1792, 1536, 1280, 1024, 1024, 768, 512, 512, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 256, 512, 512, 768, 1024, 1280, 1536, 1792, 1792, 2304, 3072, 16780801, 151001097, 402662936, 0, 0, 0, 0, 218110989, 33558274, 3072, 2560, 2048, 1792, 1536, 1280, 1024, 768, 512, 512, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65536, 65536, 65536, 65536, 65536, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 65536, 65536, 65536, 65536, 0, 0, 0, 0, 0, 0, 0, 0, 0, 256, 256, 512, 768, 768, 1024, 1280, 1536, 1792, 2048, 2816, 3328, 83890693, 285221137, 0, 0, 0, 385885975, 134223368, 16780545, 3072, 2304, 1792, 1536, 1280, 1024, 1024, 768, 512, 256, 256, 0, 0, 0, 0, 0, 0, 0, 0, 65536, 65536, 65536, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 65536, 65536, 65536, 65536, 0, 0, 0, 0, 0, 0, 0, 0, 256, 512, 512, 768, 1024, 1024, 1280, 1792, 1792, 2560, 3072, 33558018, 184556043, 0, 0, 0, 268443664, 67113220, 3072, 2816, 2048, 1792, 1536, 1280, 1024, 768, 512, 512, 256, 0, 0, 0, 0, 0, 0, 0, 0, 65536, 65536, 65536, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 65536, 65536, 65536, 0, 0, 0, 0, 0, 0, 0, 0, 256, 512, 768, 768, 1024, 1280, 1536, 1792, 2048, 2816, 3328, 117445895, 369108758, 0, 0, 184556299, 33558018, 3072, 2560, 1792, 1536, 1280, 1024, 1024, 768, 512, 256, 256, 0, 0, 0, 0, 0, 0, 0, 65536, 65536, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16908289, 16908289, 16908289, 16908289, 16908289, 16908289, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 65536, 65536, 65536, 0, 0, 0, 0, 0, 0, 0, 256, 256, 512, 768, 1024, 1280, 1536, 1792, 2048, 2560, 3072, 67113220, 251666191, 0, 402662936, 134223368, 16780545, 2816, 2304, 1792, 1536, 1280, 1024, 768, 512, 512, 256, 0, 0, 0, 0, 0, 0, 0, 65536, 65536, 65536, 16842753, 16842753, 16842753, 16842753, 16908289, 16908289, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 16908289, 16908289, 16842753, 16842753, 16842753, 16842753, 65536, 65536, 0, 0, 0, 0, 0, 0, 0, 0, 256, 512, 768, 768, 1024, 1280, 1536, 1792, 2304, 3072, 33558018, 184556043, 0, 318776339, 83890949, 3328, 2816, 2048, 1792, 1536, 1280, 1024, 768, 512, 256, 256, 0, 0, 0, 0, 0, 0, 0, 65536, 65536, 16842753, 16842753, 16842753, 16842753, 16908289, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 16908289, 16842753, 16842753, 16842753, 16842753, 65536, 65536, 0, 0, 0, 0, 0, 0, 0, 256, 512, 512, 768, 1024, 1280, 1536, 1792, 2304, 2816, 16780545, 134223624, 419440153, 251666191, 50335747, 3072, 2560, 1792, 1792, 1280, 1024, 1024, 768, 512, 256, 0, 0, 0, 0, 0, 0, 0, 65536, 65536, 16842753, 16842753, 16842753, 16842753, 16908289, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 16908289, 16842753, 16842753, 16842753, 16842753, 65536, 65536, 0, 0, 0, 0, 0, 0, 256, 256, 512, 768, 1024, 1280, 1536, 1792, 2048, 2816, 3328, 100668166, 335553812, 201333516, 33558274, 3072, 2304, 1792, 1536, 1280, 1024, 768, 512, 512, 256, 0, 0, 0, 0, 0, 0, 0, 65536, 65536, 16842753, 16842753, 16842753, 16908289, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33751042, 33751042, 33751042, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 16908289, 16842753, 16842753, 16842753, 65536, 65536, 0, 0, 0, 0, 0, 0, 0, 256, 512, 768, 1024, 1024, 1280, 1792, 1792, 2560, 3072, 67113220, 268443664, 167778570, 16780801, 3072, 2304, 1792, 1536, 1280, 1024, 768, 512, 512, 256, 0, 0, 0, 0, 0, 0, 65536, 65536, 16842753, 16842753, 16842753, 16908289, 33685506, 33685506, 33685506, 33685506, 33685506, 33751042, 33751042, 33751042, 33751042, 33751042, 33751042, 33751042, 33685506, 33685506, 33685506, 33685506, 16908289, 16842753, 16842753, 16842753, 16842753, 65536, 0, 0, 0, 0, 0, 0, 0, 256, 512, 768, 768, 1024, 1280, 1536, 1792, 2560, 3072, 50335747, 234888718, 134223368, 16780545, 2816, 2048, 1792, 1536, 1280, 1024, 768, 512, 256, 256, 0, 0, 0, 0, 0, 0, 65536, 65536, 16842753, 16842753, 16842753, 16908289, 33685506, 33685506, 33685506, 33685506, 33751042, 33751042, 33751042, 33751042, 33751042, 33751042, 33751042, 33751042, 33751042, 33685506, 33685506, 33685506, 33685506, 16908289, 16842753, 16842753, 16842753, 65536, 65536, 0, 0, 0, 0, 0, 0, 256, 512, 512, 768, 1024, 1280, 1536, 1792, 2304, 3072, 33558274, 201333516, 117445895, 3328, 2816, 2048, 1792, 1536, 1280, 1024, 768, 512, 256, 0, 0, 0, 0, 0, 0, 0, 65536, 65536, 16842753, 16842753, 16842753, 33685506, 33685506, 33685506, 33685506, 33751042, 33751042, 33751042, 33751042, 33751042, 33751042, 33751042, 33751042, 33751042, 33751042, 33751042, 33685506, 33685506, 33685506, 16908289, 16842753, 16842753, 16842753, 65536, 65536, 0, 0, 0, 0, 0, 0, 256, 512, 512, 768, 1024, 1280, 1536, 1792, 2304, 3072, 33558018, 184556043, 100668422, 3328, 2816, 2048, 1792, 1536, 1280, 1024, 768, 512, 256, 0, 0, 0, 0, 0, 0, 0, 65536, 65536, 16842753, 16842753, 16908289, 33685506, 33685506, 33685506, 33685506, 33751042, 33751042, 33751042, 33751042, 50528259, 50528259, 50528259, 33751042, 33751042, 33751042, 33751042, 33685506, 33685506, 33685506, 16908289, 16842753, 16842753, 16842753, 65536, 65536, 0, 0, 0, 0, 0, 0, 256, 256, 512, 768, 1024, 1280, 1536, 1792, 2304, 3072, 16780801, 167778570, 100668166, 3328, 2816, 2048, 1792, 1536, 1280, 1024, 768, 512, 256, 0, 0, 0, 0, 0, 0, 0, 65536, 16842753, 16842753, 16842753, 16842753, 33685506, 33685506, 33685506, 33685506, 33751042, 33751042, 33751042, 50528259, 50528259, 50528259, 50528259, 33751042, 33751042, 33751042, 33751042, 33685506, 33685506, 33685506, 33685506, 16842753, 16842753, 16842753, 65536, 65536, 0, 0, 0, 0, 0, 0, 256, 256, 512, 768, 1024, 1280, 1536, 1792, 2304, 3072, 16780801, 151001097, 100668166, 3328, 2816, 2048, 1792, 1536, 1280, 1024, 768, 512, 256, 0, 0, 0, 0, 0, 0, 0, 65536, 16842753, 16842753, 16842753, 16842753, 33685506, 33685506, 33685506, 33685506, 33751042, 33751042, 33751042, 50528259, 50528259, 33751042, 50528259, 33751042, 33751042, 33751042, 33751042, 33685506, 33685506, 33685506, 33685506, 16842753, 16842753, 16842753, 65536, 65536, 0, 0, 0, 0, 0, 0, 256, 256, 512, 768, 1024, 1280, 1536, 1792, 2304, 3072, 16780801, 151001097, 117445639, 3328, 2816, 2048, 1792, 1536, 1280, 1024, 768, 512, 256, 0, 0, 0, 0, 0, 0, 0, 65536, 65536, 16842753, 16842753, 16842753, 33685506, 33685506, 33685506, 33685506, 33751042, 33751042, 33751042, 33751042, 50528259, 50528259, 50528259, 33751042, 33751042, 33751042, 33751042, 33685506, 33685506, 33685506, 16908289, 16842753, 16842753, 16842753, 65536, 65536, 0, 0, 0, 0, 0, 0, 256, 256, 512, 768, 1024, 1280, 1536, 1792, 2304, 3072, 16780801, 167778570, 117445895, 3328, 2816, 2048, 1792, 1536, 1280, 1024, 768, 512, 256, 0, 0, 0, 0, 0, 0, 0, 65536, 65536, 16842753, 16842753, 16842753, 16908289, 33685506, 33685506, 33685506, 33751042, 33751042, 33751042, 33751042, 33751042, 33751042, 33751042, 33751042, 33751042, 33751042, 33751042, 33685506, 33685506, 33685506, 16908289, 16842753, 16842753, 16842753, 65536, 65536, 0, 0, 0, 0, 0, 0, 256, 512, 512, 768, 1024, 1280, 1536, 1792, 2304, 3072, 33558018, 184556043, 134223368, 16780545, 2816, 2048, 1792, 1536, 1280, 1024, 768, 512, 256, 256, 0, 0, 0, 0, 0, 0, 65536, 65536, 16842753, 16842753, 16842753, 16908289, 33685506, 33685506, 33685506, 33685506, 33751042, 33751042, 33751042, 33751042, 33751042, 33751042, 33751042, 33751042, 33751042, 33685506, 33685506, 33685506, 33685506, 16908289, 16842753, 16842753, 16842753, 65536, 65536, 0, 0, 0, 0, 0, 0, 256, 512, 512, 768, 1024, 1280, 1536, 1792, 2304, 3072, 33558274, 218110989, 167778570, 16780801, 3072, 2304, 1792, 1536, 1280, 1024, 768, 512, 512, 256, 0, 0, 0, 0, 0, 0, 65536, 65536, 16842753, 16842753, 16842753, 16842753, 33685506, 33685506, 33685506, 33685506, 33685506, 33751042, 33751042, 33751042, 33751042, 33751042, 33751042, 33751042, 33685506, 33685506, 33685506, 33685506, 16908289, 16842753, 16842753, 16842753, 16842753, 65536, 0, 0, 0, 0, 0, 0, 0, 256, 512, 768, 768, 1024, 1280, 1536, 1792, 2560, 3072, 50335747, 234888718, 218110989, 33558274, 3072, 2560, 1792, 1536, 1280, 1024, 768, 768, 512, 256, 0, 0, 0, 0, 0, 0, 0, 65536, 65536, 16842753, 16842753, 16842753, 16908289, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33751042, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 16842753, 16842753, 16842753, 16842753, 65536, 65536, 0, 0, 0, 0, 0, 0, 0, 256, 512, 768, 1024, 1024, 1536, 1792, 2048, 2560, 3072, 67113476, 285221137, 251666191, 50336003, 3072, 2560, 1792, 1792, 1280, 1024, 1024, 768, 512, 256, 0, 0, 0, 0, 0, 0, 0, 65536, 65536, 16842753, 16842753, 16842753, 16842753, 16908289, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 16908289, 16842753, 16842753, 16842753, 16842753, 65536, 0, 0, 0, 0, 0, 0, 0, 256, 256, 512, 768, 1024, 1280, 1536, 1792, 2048, 2816, 3328, 100668422, 352331029, 335553812, 100668166, 3328, 2816, 2048, 1792, 1536, 1280, 1024, 768, 512, 256, 256, 0, 0, 0, 0, 0, 0, 0, 65536, 65536, 16842753, 16842753, 16842753, 16842753, 16908289, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 16908289, 16842753, 16842753, 16842753, 16842753, 65536, 65536, 0, 0, 0, 0, 0, 0, 0, 256, 512, 512, 768, 1024, 1280, 1536, 1792, 2304, 3072, 16780545, 151001097, 402662680, 369107990, 134223624, 16780545, 3072, 2304, 1792, 1536, 1280, 1024, 768, 512, 512, 256, 0, 0, 0, 0, 0, 0, 0, 65536, 65536, 65536, 16842753, 16842753, 16842753, 16842753, 16908289, 16908289, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 33685506, 16908289, 16842753, 16842753, 16842753, 16842753, 16842753, 65536, 65536, 0, 0, 0, 0, 0, 0, 0, 0, 256, 512, 768, 1024, 1024, 1280, 1536, 1792, 2560, 3072, 33558274, 201333516, 0, 0, 201333772, 33558274, 3072, 2560, 1792, 1536, 1280, 1024, 1024, 768, 512, 256, 256, 0, 0, 0, 0, 0, 0, 0, 65536, 65536, 65536, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16908289, 16908289, 16908289, 16908289, 16908289, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 65536, 65536, 0, 0, 0, 0, 0, 0, 0, 0, 256, 512, 512, 768, 1024, 1280, 1536, 1792, 2048, 2816, 3072, 67113220, 268443664, 0, 0, 285221137, 83890693, 3328, 2816, 2048, 1792, 1536, 1280, 1024, 768, 512, 512, 256, 0, 0, 0, 0, 0, 0, 0, 0, 65536, 65536, 65536, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 65536, 65536, 0, 0, 0, 0, 0, 0, 0, 0, 0, 256, 512, 768, 768, 1024, 1280, 1536, 1792, 2304, 2816, 3328, 117445895, 369109014, 0, 0, 385885719, 134223624, 16780545, 3072, 2304, 1792, 1536, 1280, 1024, 1024, 768, 512, 256, 256, 0, 0, 0, 0, 0, 0, 0, 0, 65536, 65536, 65536, 65536, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 65536, 65536, 65536, 0, 0, 0, 0, 0, 0, 0, 0, 0, 256, 512, 512, 768, 1024, 1280, 1536, 1792, 1792, 2560, 3072, 33558274, 201333516, 0, 0, 0, 0, 234888462, 50335747, 3072, 2560, 2048, 1792, 1536, 1280, 1024, 768, 768, 512, 256, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65536, 65536, 65536, 65536, 16842753, 16842753, 16842753, 16842753, 16842753, 16842753, 65536, 65536, 65536, 65536, 65536, 65536, 0, 0, 0, 0, 0, 0, 0, 0, 256, 256, 512, 768, 768, 1024, 1280, 1536, 1792, 2048, 2816, 3328, 83890949, 301998610, 0, 0, 0, 0, 335553812, 117445895, 3328, 3072, 2304, 1792, 1536, 1280, 1024, 1024, 768, 512, 512, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 256, 256, 512, 512, 768, 1024, 1280, 1536, 1792, 1792, 2560, 3072, 16780801, 167778570, 402661400, 0, 0, 0, 0, 0, 218110989, 50335491, 3072, 2560, 2048, 1792, 1536, 1280, 1024, 1024, 768, 512, 512, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65536, 65536, 65536, 65536, 65536, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 256, 512, 512, 768, 1024, 1024, 1280, 1536, 1792, 2048, 2816, 3328, 83890693, 285221137, 0, 0, 0, 0, 0, 0, 335553812, 117445895, 16780545, 3072, 2304, 1792, 1792, 1536, 1280, 1024, 768, 768, 512, 256, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 256, 256, 512, 512, 768, 1024, 1024, 1280, 1536, 1792, 2048, 2560, 3072, 33558018, 167778570, 402662168, 0, 0, 0, 0, 0, 0, 0, 234888718, 67113220, 3328, 2816, 2048, 1792, 1536, 1280, 1280, 1024, 768, 768, 512, 256, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 256, 256, 512, 512, 768, 768, 1024, 1280, 1536, 1792, 1792, 2304, 3072, 3328, 100668422, 301998610, 0, 0, 0, 0, 0, 0, 0, 0, 369108502, 151001097, 33558018, 3072, 2560, 2048, 1792, 1536, 1280, 1024, 1024, 768, 768, 512, 512, 256, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 256, 256, 512, 512, 768, 768, 1024, 1280, 1280, 1536, 1792, 2048, 2816, 3072, 50335747, 218110989, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 301998610, 100668422, 3328, 3072, 2560, 1792, 1792, 1536, 1280, 1024, 1024, 768, 768, 512, 512, 256, 256, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 256, 256, 256, 512, 512, 768, 768, 1024, 1280, 1280, 1536, 1792, 2048, 2560, 3072, 33558018, 151001097, 352331029, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 234888718, 67113220, 3328, 3072, 2304, 1792, 1792, 1536, 1280, 1024, 1024, 768, 768, 512, 512, 512, 256, 256, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 256, 256, 256, 512, 512, 768, 768, 1024, 1024, 1280, 1280, 1536, 1792, 2048, 2560, 3072, 16780545, 100668422, 301998354, 0, 0, 0, 0, 0, 0};
        uint32_t full_width = 2048;
        uint32_t full_height = 1280;
        uint32_t crop_width = width;
        uint32_t crop_height = height;
        int16_t full_cols = ((int16_t)floorf(full_width / (1 << lscCfg->horzDsFactor)) + 1);
        int16_t full_rows = ((int16_t)floorf(full_height / (1 << lscCfg->vertDsFactor)) + 1);
        int16_t crop_cols = ((int16_t)floorf(crop_width / (1 << lscCfg->horzDsFactor)) + 1);
        int16_t crop_rows = ((int16_t)floorf(crop_height / (1 << lscCfg->vertDsFactor)) + 1);
        int16_t half_diff_cols = (full_cols - crop_cols) / 2;
        int16_t half_diff_rows = (full_rows - crop_rows) / 2;
        uint8_t channel_number = 1;
        uint32_t i;
        uint32_t j;

        if ((half_diff_cols + half_diff_rows) > 0)
        {
            for (i = 0; i < crop_rows; i++)
            {
                uint16_t full_y_offset = (i + half_diff_rows) * full_cols;
                uint16_t crop_y_offset = i * crop_cols;

                for (j = 0; j < crop_cols; j++)
                {
                    uint16_t full_x_offset = ((full_y_offset + j) + half_diff_cols) * channel_number;
                    uint16_t crop_x_offset = (crop_y_offset + j) * channel_number;
                    lscCfg->tableAddr[crop_x_offset + 0] = lsc_tbl[full_x_offset + 0];
                }
            }
        }
        lscCfg->numTblEntry = crop_cols * crop_rows;
    }
}

static void set_default_rfe_otf_dpc(Rfe_DpcOtfConfig *dpcOtfCfg)
{
    if (NULL != dpcOtfCfg)
    {
        dpcOtfCfg->enable          = (uint32_t)TRUE;
        /*S4.8*/
        dpcOtfCfg->slope[0] = 256;
        dpcOtfCfg->slope[1] = 512;
        dpcOtfCfg->slope[2] = 512;
        dpcOtfCfg->slope[3] = 512;
        dpcOtfCfg->slope[4] = 512;
        dpcOtfCfg->slope[5] = 512;
        dpcOtfCfg->slope[6] = 512;
        dpcOtfCfg->slope[7] = 512;
        /*U16*/
        dpcOtfCfg->threshold[0] = 512;
        dpcOtfCfg->threshold[1] = 1024;
        dpcOtfCfg->threshold[2] = 2048;
        dpcOtfCfg->threshold[3] = 4096;
        dpcOtfCfg->threshold[4] = 8192;
        dpcOtfCfg->threshold[5] = 16384;
        dpcOtfCfg->threshold[6] = 32768;
        dpcOtfCfg->threshold[7] = 65535;
    }
}

static void set_default_ee(Fcp_EeConfig *eeCfg)
{
    if (eeCfg != NULL)
    {
        eeCfg->enable = TRUE;
        eeCfg->alignY12withChroma = FALSE;
        eeCfg->alignY8withChroma = FALSE;
        eeCfg->eeForY12OrY8 = 1;
        eeCfg->bypassY12 = TRUE;
        eeCfg->bypassC12 = TRUE;
        eeCfg->bypassY8 = FALSE;
        eeCfg->bypassC8 = TRUE;
        /*U3*/
        eeCfg->leftShift = 2;
        /*U3*/
        eeCfg->rightShift = 2;
        /*U6*/
        eeCfg->yeeShift = 4;
        /*U10*/
        eeCfg->yeeEThr = 200;

        /* top left quadrant is 3х3 programmable coefficients of 5x5 HPF filter*/
        /*S10*/
        eeCfg->coeff[0] = -1;
        eeCfg->coeff[1] = -3;
        eeCfg->coeff[2] = -5;
        eeCfg->coeff[3] = -3;
        eeCfg->coeff[4] = -2;
        eeCfg->coeff[5] =  2;
        eeCfg->coeff[6] = -5;
        eeCfg->coeff[7] =  2;
        eeCfg->coeff[8] = 48;


        /* Edge sharpener parameters*/
        eeCfg->yeeMergeSel = 0;
        eeCfg->haloReductionOn = 1;
        /*U2.6, The Gradient Gain*/
        eeCfg->yesGGain = 64;
        /*U6.6, The Band-pass filter gain*/
        eeCfg->yesEGain = 64;
        /*U10.6, The shrink threshold*/
        eeCfg->yesEThr1 = 64;
        /*U10, The clip threshold*/
        eeCfg->yesEThr2 = 1023;
        /*U10, The offset applied to the Gradient gain*/
        eeCfg->yesGOfset = 0;
        static int16_t yee_lut[EE_LUT_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -448, -448, -448, -448, -448, -448, -448, -448, -448, -448, -448, -448, -448, -448, -448, -448, -448, -448, -448, -448, -512, -512, -512, -512, -512, -512, -512, -512, -512, -512, -512, -512, -512, -512, -512, -512, -576, -576, -576, -576, -576, -576, -576, -576, -576, -576, -576, -576, -576, -576, -576, -576, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -704, -704, -704, -704, -704, -704, -704, -704, -704, -704, -704, -704, -704, -704, -704, -704, -768, -768, -768, -768, -768, -768, -768, -768, -768, -768, -768, -768, -768, -768, -768, -768, -832, -832, -832, -832, -832, -832, -832, -832, -832, -832, -832, -832, -832, -832, -832, -832, -896, -896, -896, -896, -896, -896, -896, -896, -896, -896, -896, -896, -960, -960, -960, -960, -960, -960, -960, -960, -960, -960, -960, -960, -960, -960, -960, -960, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1152, -1152, -1152, -1152, -1152, -1152, -1152, -1152, -1152, -1152, -1152, -1152, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1280, -1280, -1280, -1280, -1280, -1280, -1280, -1280, -1280, -1280, -1280, -1280, -1280, -1280, -1280, -1280, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1408, -1408, -1408, -1408, -1408, -1408, -1408, -1408, -1408, -1408, -1408, -1408, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1600, -1600, -1600, -1600, -1600, -1600, -1600, -1600, -1600, -1600, -1600, -1600, -1600, -1600, -1600, -1600, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1728, -1728, -1728, -1728, -1728, -1728, -1728, -1728, -1728, -1728, -1728, -1728, -1728, -1728, -1728, -1728, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1856, -1856, -1856, -1856, -1856, -1856, -1856, -1856, -1856, -1856, -1856, -1856, -1856, -1856, -1856, -1856, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2624, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2496, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2432, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2368, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2304, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2240, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2176, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2112, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -2048, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1984, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1920, -1856, -1856, -1856, -1856, -1856, -1856, -1856, -1856, -1856, -1856, -1856, -1856, -1856, -1856, -1856, -1856, -1856, -1856, -1856, -1856, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1792, -1728, -1728, -1728, -1728, -1728, -1728, -1728, -1728, -1728, -1728, -1728, -1728, -1728, -1728, -1728, -1728, -1728, -1728, -1728, -1728, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1600, -1600, -1600, -1600, -1600, -1600, -1600, -1600, -1600, -1600, -1600, -1600, -1600, -1600, -1600, -1600, -1600, -1600, -1600, -1600, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1536, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1472, -1408, -1408, -1408, -1408, -1408, -1408, -1408, -1408, -1408, -1408, -1408, -1408, -1408, -1408, -1408, -1408, -1408, -1408, -1408, -1408, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1280, -1280, -1280, -1280, -1280, -1280, -1280, -1280, -1280, -1280, -1280, -1280, -1280, -1280, -1280, -1280, -1280, -1280, -1280, -1280, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1216, -1152, -1152, -1152, -1152, -1152, -1152, -1152, -1152, -1152, -1152, -1152, -1152, -1152, -1152, -1152, -1152, -1152, -1152, -1152, -1152, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1088, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -960, -960, -960, -960, -960, -960, -960, -960, -960, -960, -960, -960, -960, -960, -960, -960, -960, -960, -960, -960, -960, -960, -960, -960, -896, -896, -896, -896, -896, -896, -896, -896, -896, -896, -896, -896, -896, -896, -896, -896, -896, -896, -896, -896, -896, -896, -896, -896, -832, -832, -832, -832, -832, -832, -832, -832, -832, -832, -832, -832, -832, -832, -832, -832, -832, -832, -832, -832, -768, -768, -768, -768, -768, -768, -768, -768, -768, -768, -768, -768, -768, -768, -768, -768, -768, -768, -768, -768, -768, -768, -768, -768, -704, -704, -704, -704, -704, -704, -704, -704, -704, -704, -704, -704, -704, -704, -704, -704, -704, -704, -704, -704, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -640, -576, -576, -576, -576, -576, -576, -576, -576, -576, -576, -576, -576, -576, -576, -576, -576, -576, -576, -576, -576, -512, -512, -512, -512, -512, -512, -512, -512, -512, -512, -512, -512, -512, -512, -512, -512, -512, -512, -512, -512, -512, -512, -512, -512, -448, -448, -448, -448, -448, -448, -448, -448, -448, -448, -448, -448, -448, -448, -448, -448, -448, -448, -448, -448, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -384, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -320, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -256, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -192, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, -64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 576, 576, 576, 576, 576, 576, 576, 576, 576, 576, 576, 576, 576, 576, 576, 576, 576, 576, 576, 576, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 704, 704, 704, 704, 704, 704, 704, 704, 704, 704, 704, 704, 704, 704, 704, 704, 704, 704, 704, 704, 768, 768, 768, 768, 768, 768, 768, 768, 768, 768, 768, 768, 768, 768, 768, 768, 768, 768, 768, 768, 768, 768, 768, 768, 832, 832, 832, 832, 832, 832, 832, 832, 832, 832, 832, 832, 832, 832, 832, 832, 832, 832, 832, 832, 896, 896, 896, 896, 896, 896, 896, 896, 896, 896, 896, 896, 896, 896, 896, 896, 896, 896, 896, 896, 896, 896, 896, 896, 960, 960, 960, 960, 960, 960, 960, 960, 960, 960, 960, 960, 960, 960, 960, 960, 960, 960, 960, 960, 960, 960, 960, 960, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1280, 1280, 1280, 1280, 1280, 1280, 1280, 1280, 1280, 1280, 1280, 1280, 1280, 1280, 1280, 1280, 1280, 1280, 1280, 1280, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1408, 1408, 1408, 1408, 1408, 1408, 1408, 1408, 1408, 1408, 1408, 1408, 1408, 1408, 1408, 1408, 1408, 1408, 1408, 1408, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2624, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2560, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2496, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2432, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2368, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2304, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2112, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1984, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1920, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1792, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1664, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1536, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1472, 1408, 1408, 1408, 1408, 1408, 1408, 1408, 1408, 1408, 1408, 1408, 1408, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1280, 1280, 1280, 1280, 1280, 1280, 1280, 1280, 1280, 1280, 1280, 1280, 1280, 1280, 1280, 1280, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1216, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1088, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 960, 960, 960, 960, 960, 960, 960, 960, 960, 960, 960, 960, 960, 960, 960, 960, 896, 896, 896, 896, 896, 896, 896, 896, 896, 896, 896, 896, 832, 832, 832, 832, 832, 832, 832, 832, 832, 832, 832, 832, 832, 832, 832, 832, 768, 768, 768, 768, 768, 768, 768, 768, 768, 768, 768, 768, 768, 768, 768, 768, 704, 704, 704, 704, 704, 704, 704, 704, 704, 704, 704, 704, 704, 704, 704, 704, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 640, 576, 576, 576, 576, 576, 576, 576, 576, 576, 576, 576, 576, 576, 576, 576, 576, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 448, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 384, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        /*S16*/
        uint32_t i = 0;
        for (i = 0; i < EE_LUT_SIZE; i++)
        {
            eeCfg->lut[i] = yee_lut[i];
        }
    }
}

static void set_default_rgb2yuv(Fcp_Rgb2YuvConfig  *r2y)
{
    r2y->weights[0u][0u] = 77;
    r2y->weights[0u][1u] = 150;
    r2y->weights[0u][2u] = 29;
    r2y->weights[1u][0u] = -44;
    r2y->weights[1u][1u] = -84;
    r2y->weights[1u][2u] = 128;
    r2y->weights[2u][0u] = 128;
    r2y->weights[2u][1u] = -108;
    r2y->weights[2u][2u] = -20;

    r2y->offsets[0u]     = 0;
    r2y->offsets[1u]     = 128;
    r2y->offsets[2u]     = 128;
}

static void set_default_rgb2hsv(Fcp_Rgb2HsvConfig *rgb2hsvCfg)
{
    rgb2hsvCfg->inputSelect = 0;
    rgb2hsvCfg->h1Input = 0;
    rgb2hsvCfg->h2Input = 0;
    rgb2hsvCfg->weights[0] = 64;
    rgb2hsvCfg->weights[1] = 64;
    rgb2hsvCfg->weights[2] = 128;
    rgb2hsvCfg->offset = 0;
    rgb2hsvCfg->useWbDataForGreyCalc = false;
    rgb2hsvCfg->wbOffset[0] = 0;
    rgb2hsvCfg->wbOffset[1] = 0;
    rgb2hsvCfg->wbOffset[2] = 0;
    rgb2hsvCfg->threshold[0] = 0;
    rgb2hsvCfg->threshold[1] = 0;
    rgb2hsvCfg->threshold[2] = 0;
    rgb2hsvCfg->satMinThr = 0;
    rgb2hsvCfg->satMode = 0;
    rgb2hsvCfg->satDiv = 2;
}

static void set_default_wb(Rfe_GainOfstConfig  *wbCfg)
{
    wbCfg->gain[0u]     = 512;
    wbCfg->gain[1u]     = 512;
    wbCfg->gain[2u]     = 512;
    wbCfg->gain[3u]     = 512;
    wbCfg->offset[0u]     = 0;
    wbCfg->offset[1u]     = 0;
    wbCfg->offset[2u]     = 0;
    wbCfg->offset[3u]     = 0;
}

static void set_default_cfaLut16to12Cfg(Vhwa_LutConfig *lut16to12Cfg)
{
    lut16to12Cfg->enable = 0;
    lut16to12Cfg->inputBits = 16;
    lut16to12Cfg->clip = ((1 << 12) - 1);

    static uint32_t def_lut[RFE_H3A_COMP_LUT_SIZE] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98, 100, 102, 104, 106, 108, 110, 112, 114, 116, 118, 120, 122, 124, 126, 128, 130, 132, 134, 136, 138, 140, 142, 144, 146, 148, 150, 152, 154, 156, 158, 160, 162, 164, 166, 168, 170, 172, 174, 176, 178, 180, 182, 184, 186, 188, 190, 192, 194, 196, 198, 200, 202, 204, 206, 208, 210, 212, 214, 216, 218, 220, 222, 224, 226, 228, 230, 232, 234, 236, 238, 240, 242, 244, 246, 248, 250, 252, 254, 256, 264, 272, 280, 288, 296, 304, 312, 320, 328, 336, 344, 352, 360, 368, 376, 384, 392, 400, 408, 416, 424, 432, 440, 448, 456, 464, 472, 480, 488, 496, 504, 512, 520, 528, 536, 544, 552, 560, 568, 576, 584, 592, 600, 608, 616, 624, 632, 640, 648, 656, 664, 672, 680, 688, 696, 704, 712, 720, 728, 736, 744, 752, 760, 768, 776, 784, 792, 800, 808, 816, 824, 832, 840, 848, 856, 864, 872, 880, 888, 896, 904, 912, 920, 928, 936, 944, 952, 960, 968, 976, 984, 992, 1000, 1008, 1016, 1024, 1032, 1040, 1048, 1056, 1064, 1072, 1080, 1088, 1096, 1104, 1112, 1120, 1128, 1136, 1144, 1152, 1160, 1168, 1176, 1184, 1192, 1200, 1208, 1216, 1224, 1232, 1240, 1248, 1256, 1264, 1272, 1280, 1288, 1296, 1304, 1312, 1320, 1328, 1336, 1344, 1352, 1360, 1368, 1376, 1384, 1392, 1400, 1408, 1416, 1424, 1432, 1440, 1448, 1456, 1464, 1472, 1480, 1488, 1496, 1504, 1512, 1520, 1528, 1536, 1544, 1552, 1560, 1568, 1576, 1584, 1592, 1600, 1608, 1616, 1624, 1632, 1640, 1648, 1656, 1664, 1672, 1680, 1688, 1696, 1704, 1712, 1720, 1728, 1736, 1744, 1752, 1760, 1768, 1776, 1784, 1792, 1800, 1808, 1816, 1824, 1832, 1840, 1848, 1856, 1864, 1872, 1880, 1888, 1896, 1904, 1912, 1920, 1928, 1936, 1944, 1952, 1960, 1968, 1976, 1984, 1992, 2000, 2008, 2016, 2024, 2032, 2040, 2048, 2056, 2064, 2072, 2080, 2088, 2096, 2104, 2112, 2120, 2128, 2136, 2144, 2152, 2160, 2168, 2176, 2184, 2192, 2200, 2208, 2216, 2224, 2232, 2240, 2248, 2256, 2264, 2272, 2280, 2288, 2296, 2304, 2312, 2320, 2328, 2336, 2344, 2352, 2360, 2368, 2376, 2384, 2392, 2400, 2408, 2416, 2424, 2432, 2440, 2448, 2456, 2464, 2472, 2480, 2488, 2496, 2504, 2512, 2520, 2528, 2536, 2544, 2552, 2560, 2568, 2576, 2584, 2592, 2600, 2608, 2616, 2624, 2632, 2640, 2648, 2656, 2664, 2672, 2680, 2688, 2696, 2704, 2712, 2720, 2728, 2736, 2744, 2752, 2760, 2768, 2776, 2784, 2792, 2800, 2808, 2816, 2824, 2832, 2840, 2848, 2856, 2864, 2872, 2880, 2888, 2896, 2904, 2912, 2920, 2928, 2936, 2944, 2952, 2960, 2968, 2976, 2984, 2992, 3000, 3008, 3016, 3024, 3032, 3040, 3048, 3056, 3064, 3072, 3080, 3088, 3096, 3104, 3112, 3120, 3128, 3136, 3144, 3152, 3160, 3168, 3176, 3184, 3192, 3200, 3208, 3216, 3224, 3232, 3240, 3248, 3256, 3264, 3272, 3280, 3288, 3296, 3304, 3312, 3320, 3328, 3336, 3344, 3352, 3360, 3368, 3376, 3384, 3392, 3400, 3408, 3416, 3424, 3432, 3440, 3448, 3456, 3464, 3472, 3480, 3488, 3496, 3504, 3512, 3520, 3528, 3536, 3544, 3552, 3560, 3568, 3576, 3584, 3592, 3600, 3608, 3616, 3624, 3632, 3640, 3648, 3656, 3664, 3672, 3680, 3688, 3696, 3704, 3712, 3720, 3728, 3736, 3744, 3752, 3760, 3768, 3776, 3784, 3792, 3800, 3808, 3816, 3824, 3832, 3840, 3848, 3856, 3864, 3872, 3880, 3888, 3896, 3904, 3912, 3920, 3928, 3936, 3944, 3952, 3960, 3968, 3976, 3984, 3992, 4000, 4008, 4016, 4024, 4032, 4040, 4048, 4056, 4064, 4072, 4080, 4088, 4095};
    uint32_t i;
    for (i = 0U; i < RFE_H3A_COMP_LUT_SIZE; i ++)
    {
        lut16to12Cfg->tableAddr[i] = def_lut[i];
    }
}

static void set_default_gamma(Fcp_GammaConfig *gammaCfg)
{
    gammaCfg->enable = 1;
    gammaCfg->outClip = 10;
    static uint16_t def_lut[FCP_GAMMA_LUT_SIZE] = {0,60,82,99,113,125,136,146,155,163,171,179,186,193,199,205,212,218,224,229,234,239,245,250,255,259,264,269,273,278,282,286,290,294,299,303,307,310,314,318,321,325,328,332,335,339,342,346,350,353,356,359,362,365,369,372,375,378,381,384,387,389,392,395,398,401,404,406,409,412,415,417,420,423,425,428,431,433,436,438,441,443,446,448,450,452,455,457,460,462,464,467,469,471,474,476,478,481,483,485,488,490,492,494,497,499,501,502,504,506,509,511,513,515,517,519,521,524,526,528,530,532,534,536,538,539,541,543,545,547,549,551,553,555,557,559,561,563,565,567,567,569,571,573,575,577,579,581,583,584,586,588,590,592,593,594,596,598,600,602,603,605,607,609,611,612,614,615,617,618,620,622,624,625,627,629,630,632,634,635,636,638,640,641,643,645,646,648,650,651,653,654,656,657,658,660,662,663,665,666,668,670,671,673,674,675,677,678,680,681,683,684,686,687,689,691,692,693,694,696,697,699,700,702,703,705,706,708,709,710,711,713,714,716,717,719,720,722,723,725,726,727,728,729,731,732,734,735,737,738,740,741,741,743,744,746,747,748,750,751,753,754,756,756,757,759,760,761,763,764,766,767,768,770,771,771,773,774,776,777,778,780,781,782,784,785,785,787,788,789,791,792,793,795,796,797,799,799,800,802,803,804,805,807,808,809,811,812,813,814,815,816,817,819,820,821,822,824,825,826,827,828,829,830,832,833,834,835,837,838,839,839,841,842,843,844,846,847,848,849,850,851,852,853,854,856,857,858,859,860,862,863,864,864,865,867,868,869,870,871,873,874,875,876,876,878,879,880,881,882,883,885,886,887,888,888,890,891,892,893,894,895,896,898,899,899,900,901,902,904,905,906,907,908,909,910,911,912,913,914,915,916,917,918,920,921,922,922,923,924,925,926,928,929,930,931,932,933,934,934,935,937,938,939,940,941,942,943,944,945,945,947,948,949,950,951,952,953,954,955,956,956,957,959,960,961,962,963,964,965,966,966,967,968,969,970,971,972,973,975,976,977,977,978,979,980,981,982,983,984,985,986,987,987,988,989,990,991,992,993,994,996,997,998,998,999,1000,1001,1002,1003,1004,1005,1006,1007,1008,1008,1009,1010,1011,1012,1013,1014,1015,1016,1017,1018,1018,1019,1020,1021,1022,1023,1023};
    uint32_t i;
    for (i = 0U; i < FCP_GAMMA_LUT_SIZE; i ++)
    {
        gammaCfg->tableC1[i] = def_lut[i];
        gammaCfg->tableC2[i] = def_lut[i];
        gammaCfg->tableC3[i] = def_lut[i];
    }
}

static void set_default_yuvSatLutCfg(Fcp_YuvSatLutConfig *yuvSatLutCfg)
{
    yuvSatLutCfg->lumaInputBits = 10;
    yuvSatLutCfg->enableLumaLut = 0;
    yuvSatLutCfg->enableChromaLut = 0;
    yuvSatLutCfg->enableSaturLut = 0;
    static uint16_t def_lut[FCP_GAMMA_LUT_SIZE] = {0, 6, 9, 12, 14, 16, 18, 19, 21, 23, 24, 26, 27, 28, 30, 31, 32, 33, 34, 35, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 49, 50, 51, 52, 53, 54, 55, 55, 56, 57, 58, 59, 60, 60, 61, 62, 63, 63, 64, 65, 66, 66, 67, 68, 69, 69, 70, 71, 71, 72, 73, 74, 74, 75, 76, 76, 77, 78, 78, 79, 80, 80, 81, 82, 82, 83, 83, 84, 85, 85, 86, 87, 87, 88, 88, 89, 90, 90, 91, 91, 92, 93, 93, 94, 94, 95, 96, 96, 97, 97, 98, 98, 99, 100, 100, 101, 101, 102, 102, 103, 103, 104, 104, 105, 106, 106, 107, 107, 108, 108, 109, 109, 110, 110, 111, 111, 112, 112, 113, 114, 114, 115, 115, 116, 116, 117, 117, 118, 118, 119, 119, 120, 120, 121, 121, 122, 122, 123, 123, 124, 124, 125, 125, 125, 126, 126, 127, 127, 128, 128, 129, 129, 130, 130, 131, 131, 132, 132, 133, 133, 134, 134, 134, 135, 135, 136, 136, 137, 137, 138, 138, 139, 139, 139, 140, 140, 141, 141, 142, 142, 143, 143, 143, 144, 144, 145, 145, 146, 146, 147, 147, 147, 148, 148, 149, 149, 150, 150, 150, 151, 151, 152, 152, 153, 153, 153, 154, 154, 155, 155, 155, 156, 156, 157, 157, 158, 158, 158, 159, 159, 160, 160, 160, 161, 161, 162, 162, 162, 163, 163, 164, 164, 165, 165, 165, 166, 166, 167, 167, 167, 168, 168, 169, 169, 169, 170, 170, 170, 171, 171, 172, 172, 172, 173, 173, 174, 174, 174, 175, 175, 176, 176, 176, 177, 177, 177, 178, 178, 179, 179, 179, 180, 180, 181, 181, 181, 182, 182, 182, 183, 183, 184, 184, 184, 185, 185, 185, 186, 186, 187, 187, 187, 188, 188, 188, 189, 189, 189, 190, 190, 191, 191, 191, 192, 192, 192, 193, 193, 193, 194, 194, 195, 195, 195, 196, 196, 196, 197, 197, 197, 198, 198, 198, 199, 199, 200, 200, 200, 201, 201, 201, 202, 202, 202, 203, 203, 203, 204, 204, 204, 205, 205, 206, 206, 206, 207, 207, 207, 208, 208, 208, 209, 209, 209, 210, 210, 210, 211, 211, 211, 212, 212, 212, 213, 213, 213, 214, 214, 214, 215, 215, 215, 216, 216, 216, 217, 217, 217, 218, 218, 218, 219, 219, 219, 220, 220, 220, 221, 221, 221, 222, 222, 222, 223, 223, 223, 224, 224, 224, 225, 225, 225, 226, 226, 226, 227, 227, 227, 228, 228, 228, 229, 229, 229, 230, 230, 230, 231, 231, 231, 232, 232, 232, 232, 233, 233, 233, 234, 234, 234, 235, 235, 235, 236, 236, 236, 237, 237, 237, 238, 238, 238, 238, 239, 239, 239, 240, 240, 240, 241, 241, 241, 242, 242, 242, 243, 243, 243, 243, 244, 244, 244, 245, 245, 245, 246, 246, 246, 247, 247, 247, 248, 248, 248, 248, 249, 249, 249, 250, 250, 250, 251, 251, 251, 251, 252, 252, 252, 253, 253, 253, 254, 254, 254, 254, 255, 255, 255, 255, 255};
    uint32_t i;
    for (i = 0U; i < FCP_GAMMA_LUT_SIZE; i ++)
    {
        yuvSatLutCfg->lumaLutAddr[i] = def_lut[i];
        yuvSatLutCfg->chromaLutAddr[i] = def_lut[i];
        yuvSatLutCfg->saturLutAddr[i] = def_lut[i];
    }
}

static void set_default_hist(Fcp_HistConfig *histCfg)
{
    histCfg->enable = 0;
    histCfg->input = 0;
    histCfg->roi.cropStartX = 0;
    histCfg->roi.cropStartY = 0;
    histCfg->roi.cropWidth = 500;
    histCfg->roi.cropHeight = 500;
}

static void set_default_mergeCfg(Rfe_WdrConfig *mergeCfg)
{
    mergeCfg->enable = 0;
    mergeCfg->useShortExpForWgtCalc = 0;
    mergeCfg->dst = 15;
    mergeCfg->sbit = 4;
    mergeCfg->lbit = 4;
    mergeCfg->gshort = 32768;
    mergeCfg->glong = 2048;
    mergeCfg->lbk[0] = 0;
    mergeCfg->lbk[1] = 0;
    mergeCfg->lbk[2] = 0;
    mergeCfg->sbk[0] = 0;
    mergeCfg->sbk[1] = 0;
    mergeCfg->sbk[2] = 0;
    mergeCfg->lwb[0] = 512;
    mergeCfg->lwb[1] = 512;
    mergeCfg->lwb[2] = 512;
    mergeCfg->swb[0] = 512;
    mergeCfg->swb[1] = 512;
    mergeCfg->swb[2] = 512;
    mergeCfg->wdrThr = 4094;
    mergeCfg->afe = 0;
    mergeCfg->afm = 0;
    mergeCfg->bf = 0;
    mergeCfg->mas = 0;
    mergeCfg->mad = 65535;
    mergeCfg->mergeShift = 0;
    mergeCfg->mergeClip = 262143;
}

/**
 * @brief Allocates tables in the Cuc ISP config.
 *
 * @param t Kernel context object.
 */
static void point_isp_tables_on_static_allocated_memory(tivxVpacCucIspObj *t)
{
    t->vissCfg.h3aLutCfg.tableAddr = t->lut_allocation_ptr.h3aLut;
    t->vissCfg.cfaLut16to12Cfg.tableAddr = t->lut_allocation_ptr.cfa_lut_16to12;
    t->vissCfg.decomp1Cfg.tableAddr = t->lut_allocation_ptr.rawfe_pwl_vshort_lut;
    t->vissCfg.decomp2Cfg.tableAddr = t->lut_allocation_ptr.rawfe_pwl_vshort_lut;
    t->vissCfg.decomp3Cfg.tableAddr = t->lut_allocation_ptr.rawfe_pwl_vshort_lut;
    t->vissCfg.lscCfg.tableAddr = t->lut_allocation_ptr.lsc_tbl;
    t->vissCfg.eeCfg.lut = t->lut_allocation_ptr.yee_lut;
    t->vissCfg.yuvSatLutCfg.lumaLutAddr = t->lut_allocation_ptr.luma_lut;
    t->vissCfg.yuvSatLutCfg.chromaLutAddr = t->lut_allocation_ptr.chroma_lut;
    t->vissCfg.yuvSatLutCfg.saturLutAddr = t->lut_allocation_ptr.satur_lut;
    t->vissCfg.gammaCfg.tableC1 = t->lut_allocation_ptr.gamma_table_c1;
    t->vissCfg.gammaCfg.tableC2 = t->lut_allocation_ptr.gamma_table_c2;
    t->vissCfg.gammaCfg.tableC3 = t->lut_allocation_ptr.gamma_table_c3;
    t->vissCfg.rfeLut20to16Cfg.tableAddr = t->lut_allocation_ptr.rfeLut20to16Cfg;
}

void set_default_isp_config_233(tivxVpacCucIspObj *t, uint32_t width, uint32_t height)
{
    point_isp_tables_on_static_allocated_memory(t);
    Rfe_PwlConfig *pwlCfg = &t->vissCfg.pwlCfg1;
    set_default_rfe_pwl_zero(pwlCfg);
    t->vissCfgRef.lPwlCfg = pwlCfg;
    pwlCfg = &t->vissCfg.pwlCfg2;
    set_default_rfe_pwl_zero(pwlCfg);
    t->vissCfgRef.sPwlCfg = pwlCfg;
    pwlCfg = &t->vissCfg.pwlCfg3;
    set_default_rfe_pwl(pwlCfg);
    t->vissCfgRef.vsPwlCfg = pwlCfg;

    Vhwa_LutConfig  *lutCfg;
    lutCfg = &t->vissCfg.decomp1Cfg;
    set_default_pwl_lut_cfg(lutCfg, 0);
    t->vissCfgRef.lLutCfg = lutCfg;
    lutCfg = &t->vissCfg.decomp2Cfg;
    set_default_pwl_lut_cfg(lutCfg, 0);
    t->vissCfgRef.sLutCfg = lutCfg;
    lutCfg = &t->vissCfg.decomp3Cfg;
    set_default_pwl_lut_cfg(lutCfg, 1);
    t->vissCfgRef.vsLutCfg = lutCfg;

    Rfe_WdrConfig *mergeCfg = &t->vissCfg.merge1Cfg;
    set_default_mergeCfg(mergeCfg);
    t->vissCfgRef.wdr1Cfg = mergeCfg;
    mergeCfg = &t->vissCfg.merge2Cfg;
    set_default_mergeCfg(mergeCfg);
    t->vissCfgRef.wdr2Cfg = mergeCfg;

    Vhwa_LutConfig *rfeLut20to16Cfg = &t->vissCfg.rfeLut20to16Cfg;
    set_default_rfeLut20to16Cfg_config(rfeLut20to16Cfg);
    t->vissCfgRef.comp20To16LutCfg = rfeLut20to16Cfg;

    Rfe_DpcOtfConfig *dpcOtfCfg = &t->vissCfg.dpcOtfCfg;
    set_default_rfe_otf_dpc(dpcOtfCfg);
    t->vissCfgRef.dpcOtf = dpcOtfCfg;


    Rfe_DpcLutConfig *dpcLutCfg = &t->vissCfg.dpcLutCfg;
    dpcLutCfg->enable           = 0;
    dpcLutCfg->isReplaceWhite   = 0;
    dpcLutCfg->maxDefectPixels  = 0x1u;
    t->vissCfgRef.dpcLut  = dpcLutCfg;

    Rfe_LscConfig *lscCfg = &t->vissCfg.lscCfg;
    set_default_rfe_lsc(lscCfg, width, height);
    t->vissCfgRef.lscCfg = lscCfg;

    Rfe_GainOfstConfig  *wbCfg = &t->vissCfg.wbCfg;
    set_default_wb(wbCfg);
    t->vissCfgRef.wbCfg = wbCfg;

    Nsf4v_Config *t_Nsf4v_Config = &t->vissCfg.nsf4Cfg;
    set_default_nsf4Cfg(t_Nsf4v_Config);
    t->vissCfgRef.nsf4Cfg = t_Nsf4v_Config;

    H3a_Config *h3aCfg = &t->vissCfg.h3aCfg;
    set_default_H3A_config(h3aCfg, width, height);
    t->vissCfgRef.h3aCfg = h3aCfg;

    Vhwa_LutConfig *h3aLutCfg = &t->vissCfg.h3aLutCfg;
    set_default_h3a_lut_config(h3aLutCfg);
    t->vissCfgRef.h3aLutCfg = h3aLutCfg;

    Rfe_H3aInConfig *h3aInCfg = &t->vissCfg.h3aInCfg;
    h3aInCfg->inSel = 3;
    h3aInCfg->shift = 0;
    t->vissCfgRef.rfeH3aInCfg = h3aInCfg;

    Glbce_Config *glbceCfg = &t->vissCfg.glbceCfg;
    Glbce_PerceptConfig *fwdPrcpCfg = &t->vissCfg.fwdPrcpCfg;
    Glbce_PerceptConfig *revPrcpCfg = &t->vissCfg.revPrcpCfg;
    set_default_ltm_config(glbceCfg, fwdPrcpCfg, revPrcpCfg);
    t->vissCfgRef.glbceCfg = glbceCfg;
    t->vissCfgRef.fwdPrcpCfg = fwdPrcpCfg;
    t->vissCfgRef.revPrcpCfg = revPrcpCfg;

    Fcp_EeConfig *eeCfg = &t->vissCfg.eeCfg;
    set_default_ee(eeCfg);
    t->vissCfgRef.eeCfg = eeCfg;

    Fcp_Rgb2YuvConfig  *r2y = &t->vissCfg.rgb2yuvCfg;
    set_default_rgb2yuv(r2y);
    t->vissCfgRef.rgb2yuv = r2y;

    Fcp_Rgb2HsvConfig *rgb2hsvCfg = &t->vissCfg.rgb2hsvCfg;
    set_default_rgb2hsv(rgb2hsvCfg);
    t->vissCfgRef.rgb2Hsv = rgb2hsvCfg;

    Fcp_CcmConfig *ccmCfg = &t->vissCfg.ccmCfg;
    set_default_ccm_cfg(ccmCfg);
    t->vissCfgRef.ccm = ccmCfg;

    Fcp_CfaConfig *cfaCfg = &t->vissCfg.cfaCfg;
    set_default_demosaic(cfaCfg);
    t->vissCfgRef.cfaCfg = cfaCfg;

    Vhwa_LutConfig *lut16to12Cfg = &t->vissCfg.cfaLut16to12Cfg;
    set_default_cfaLut16to12Cfg(lut16to12Cfg);
    t->vissCfgRef.cfaLut16to12Cfg = lut16to12Cfg;

    Fcp_GammaConfig *gamma = &t->vissCfg.gammaCfg;
    set_default_gamma(gamma);
    t->vissCfgRef.gamma = gamma;

    Fcp_HistConfig *histCfg = &t->vissCfg.histCfg;
    set_default_hist(histCfg);
    t->vissCfgRef.histCfg = histCfg;

    Fcp_YuvSatLutConfig *yuvSatLutCfg = &t->vissCfg.yuvSatLutCfg;
    set_default_yuvSatLutCfg(yuvSatLutCfg);
    t->vissCfgRef.yuvSatLutCfg = yuvSatLutCfg;

    t->vissCfg.usageFlag = 1U;
}
#endif
