
#ifndef CORNER_H
#define CORNER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lucchese.h"

/* --- Public Typedefinitions, Enumerations, Defines ---------------------- */

/* PRQA S 2400 1 */ /* C code */
typedef struct CornerAn_s {
  sint8_t   iT_as8[2];
  sint8_t   iB_as8[2];
  sint8_t   iL_as8[2];
  sint8_t   iR_as8[2];
} S_CornerAn_t; /* PRQA S 2400 */ /* C code */

/* PRQA S 2400 1 */ /* C code */
typedef struct CornerRound_s {
  io_S_PosSub_t *corners_aps[4];
} Corner_S_Round_t; /* PRQA S 2400 */ /* C code */

/* PRQA S 2400 1 */ /* C code */
typedef struct CornerLines_s {
  Corner_S_Round_t *rounds_aps[7];
} Corner_S_Lines_t; /* PRQA S 2400 */ /* C code */

/* PRQA S 2400 1 */ /* C code */
typedef struct CornerGrid_s {
  Corner_S_Lines_t *lines_aps[4];
} Corner_S_Grid_t; /* PRQA S 2400 */ /* C code */

/* --- Public Variables, Constants ---------------------------------------- */
/* PRQA S 1025, 1026 3 */ /* C code */
#define LTARGET_MAX_NUMBER_CORNERS      (200)
#define LTARGET_MAX_NORMALIZE_IMAGE     (75000)
#define LCORNER_MAX_CORNERNUMBERS       (3U)
/* PRQA S 1020 3 */ /* C code */
#define LCORNER_MAX_CONFIDENCE_DROP     (0.65F)

/* PRQA S 1021,2300 2 */ /* C code */
extern float32_t Corner_v_NormImg_af32[LTARGET_MAX_NORMALIZE_IMAGE];
extern S_CornerAn_t Corner_v_CornerAn_as[LTARGET_MAX_NUMBER_CORNERS];

/* --- Public Macros ------------------------------------------------------ */

/* --- Public Function Prototypes ----------------------------------------- */

sint8_t aCorner_F_mainDetector_s8(uint8_t *i_ImgData_pu8,  /* input image */
                                  const aAlgoECInputPara_t *i_paras_t,
                                  float32_t o_iX_af32[],                 /* output candidate list x coordinate */
                                  float32_t o_iY_af32[],                 /* output candidate list y coordinate */
                                  uint32_t *o_CanCount_pu32,            /* output no of candidates */
                                  const float32_t i_TargetRation_f32,         /* threshold for distance ration */
                                  const sint8_t i_StartPattern_s8            /* start pattern type */
);
#ifdef __cplusplus
}
#endif
/* === End of Header File ==================================================== */
#endif /* corner.h */
