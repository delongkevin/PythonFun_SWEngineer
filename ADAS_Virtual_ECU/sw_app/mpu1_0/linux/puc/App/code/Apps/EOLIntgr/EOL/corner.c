#include "corner.h"
#include <math.h>
#include "local_extrema.h"
#include <string.h>
#include "flcompare.h"

/* PRQA S 1051 8*/ /*This commented code is uncommented and used when debugging on PC*/
/* #define ENABLE_DEBUG_OPENCV */
/* #define OPENCV_WAITIME		0 */
/* #define ENABLE_DEBUG_PRINT */
/* #define ENABLE_DEBUG_OPENCV_CONV */
/* #define ENABLE_DEBUG_OPENCV_LOC */
/* #define ENABLE_DEBUG_OPENCV_ROUND */
/* #define ENABLE_DEBUG_OPENCV_LINES */
/* #define ENABLE_DEBUG_OPENCV_GRIDS */

#ifdef ENABLE_DEBUG_OPENCV
#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#endif

/* PRQA S 612, 1041 2 */ /* Big size is ok. Empty initializers are intended. */
float32_t Corner_v_NormImg_af32[LTARGET_MAX_NORMALIZE_IMAGE] = {};
S_CornerAn_t Corner_v_CornerAn_as[LTARGET_MAX_NUMBER_CORNERS] = {};

/* --- Private Typedefinitions, Enumerations, Defines ------------------------ */


/* --- Private Variables, Constants ------------------------------------------ */
#ifdef ENABLE_DEBUG_OPENCV
IplImage* iplImage, *iplImage2;
#endif


/* --- Private Macros -------------------------------------------------------- */


/* --- Private Function Prototypes ------------------------------------------- */
static void f_convImage_v (uint8_t *i_ImgData_pu8, const uint16_t i_ImgX_u16 , const uint16_t i_ImgY_u16, float32_t *o_NormImg_pf32);
#if 0
static sint32_t f_addNextCorner (uint16_t i_ImgX_u16 , uint16_t i_ImgY_u16, float32_t *b_NormImg_pf32, io_S_PosSub_t *o_CornerList_pt);
static sint32_t f_findClosestCorner (io_S_PosSub_t *i_Corners_pt, uint16_t i_NumCorners_ui16, uint16_t i_IndexCamera_ui16, float32_t minAng_f32, float32_t maxAng_f32, sint16_t i_SkipCorner_si16);
#endif
static sint32_t f_FindCorner_s32 (const uint16_t i_ImgX_u16 , const uint16_t i_ImgY_u16, const float32_t *i_NormImg_af32, io_S_PosSub_t *o_CornerList_as, const uint16_t i_NumCorners_u16);
static sint32_t f_updateCornerAM_s32 (const io_S_PosSub_t i_Corners_as[], const uint16_t i_NumCorners_u16, const sint32_t i_IndexCamera_s32);

static sint32_t f_connectRound_s32 (io_S_PosSub_t i_Corners_as[], const uint16_t i_NumCorners_u16, Corner_S_Round_t o_Rounds_as[]);
static sint32_t f_addRound_s32 (io_S_PosSub_t i_Corners_as[], Corner_S_Round_t o_Rounds_as[], const sint32_t i_StartCorner_s32);
static sint8_t f_verifyRound_s8 (const Corner_S_Round_t i_Rounds_as[]);
static sint16_t f_findNextRound_s16 (const Corner_S_Round_t o_Rounds_as[], const uint16_t i_NumRounds_u16, const uint16_t i_Index_u16, const sint8_t i_SkipIndex_s8);

static sint32_t f_connectLine_s32 (Corner_S_Round_t o_Rounds_as[], const uint16_t i_NumRounds_u16, Corner_S_Lines_t o_Lines_as[], const uint16_t i_Nx_u16, const float32_t i_TargetRation_f32);
static sint8_t f_verifyLine_s8 (const Corner_S_Lines_t i_Line_as[], const uint16_t i_Nx_u16, float32_t i_TargetRation_f32);
static sint16_t f_findNextLine_s16 (const Corner_S_Lines_t i_Lines_as[], const uint16_t i_NumLines_u16, const uint16_t i_Index_u16, const uint16_t i_Nx_u16);

static uint8_t f_connectGrid_u8 (Corner_S_Lines_t i_Lines_as[], const uint16_t i_NumLines_u16, Corner_S_Grid_t o_Grid_as[], const uint16_t i_Nx_u16, const uint16_t i_Ny_u16, const sint8_t i_StartPattern_s8);
static sint16_t f_verifyGrid_s16 (const Corner_S_Grid_t i_Grid_as[], const uint16_t i_Nx_u16, const uint16_t i_Ny_u16, const sint8_t i_StartPattern_s8);


/* --- Private Function Definitions --------------------------------------- */
static void f_convImage_v (uint8_t *i_ImgData_pu8, const uint16_t i_ImgX_u16 , const uint16_t i_ImgY_u16, float32_t *o_NormImg_pf32)
{
  /* DD-ID: {BA35D47D-2388-405d-8153-1C33E434EB9B}*/
#if 0
  sint32_t ksz = 5;
  sint32_t x,y,x1,y1;

  /* clear normalized image */
  memset (o_NormImg_pf32, 0, i_ImgX_u16*i_ImgY_u16*sizeof(float32_t));

  /* run convolution */
  for (x=ksz ; x<i_ImgX_u16-ksz ; x++) {
    for (y=ksz ; y<i_ImgY_u16-ksz ; y++) {
      for (x1=1 ; x1<=ksz ; x1++) {
        for (y1=1 ; y1<=ksz ; y1++) {
          o_NormImg_pf32[y*i_ImgX_u16 + x] -= (float32_t)i_ImgData_pu8[(y-y1)*i_ImgX_u16 + x-x1];
          o_NormImg_pf32[y*i_ImgX_u16 + x] += (float32_t)i_ImgData_pu8[(y+y1)*i_ImgX_u16 + x-x1];
          o_NormImg_pf32[y*i_ImgX_u16 + x] += (float32_t)i_ImgData_pu8[(y-y1)*i_ImgX_u16 + x+x1];
          o_NormImg_pf32[y*i_ImgX_u16 + x] -= (float32_t)i_ImgData_pu8[(y+y1)*i_ImgX_u16 + x+x1];
        }
      }
      o_NormImg_pf32[y*i_ImgX_u16 + x] = o_NormImg_pf32[y*i_ImgX_u16 + x] / 255.0F / ((float32_t)ksz*(float32_t)ksz*4.0F);
    }
  }
#else
  aExtrema_F_getConvImg_v(i_ImgData_pu8, i_ImgX_u16, i_ImgY_u16, o_NormImg_pf32);
#endif


#ifdef ENABLE_DEBUG_OPENCV_CONV
  for (y=0 ; y<i_ImgY_u16 ; ++y) {
    for (x=0 ; x<i_ImgX_u16 ; ++x) {
      iplImage2->imageData[y*iplImage2->widthStep+x] = (uint8_t)(sqrt(o_NormImg_pf32[y*i_ImgX_u16+x]*o_NormImg_pf32[y*i_ImgX_u16+x])*255);
    }
  }
  cvShowImage ("Conv Image2", iplImage2);
  cvWaitKey(OPENCV_WAITIME);
#endif

}

#if 0
static sint32_t f_addNextCorner (uint16_t i_ImgX_u16 , uint16_t i_ImgY_u16, float32_t *b_NormImg_pf32, io_S_PosSub_t *o_CornerList_pt)
{
  sint32_t ksz = 5;
  sint32_t x,y,x1=0,y1=0;
  float32_t maxValue = 0.0F;

  /* localize highest candidate */
  for (x=ksz ; x<i_ImgX_u16-ksz ; x++) {
    for (y=ksz ; y<i_ImgY_u16-ksz ; y++) {
      if (b_NormImg_pf32[y*i_ImgX_u16 + x]*b_NormImg_pf32[y*i_ImgX_u16 + x] > maxValue*maxValue) {
        maxValue = b_NormImg_pf32[y*i_ImgX_u16 + x];
        x1 = x;
        y1 = y;
      }
    }
  }

  /* add candidate to corner list */
  o_CornerList_pt->x_f32 = (float32_t)x1;
  o_CornerList_pt->y_f32 = (float32_t)y1;
  o_CornerList_pt->v_f32 = (float32_t)maxValue;

  /* block area around candidate for next search */
  for (x=0 ; x<=ksz ; x++) {
    for (y=0 ; y<=ksz ; y++) {
      maxValue = (float32_t)(x*x+y*y)/(float32_t)(2*ksz*ksz);
      b_NormImg_pf32[(y1+y)*i_ImgX_u16 + (x1+x)] *= maxValue;
      b_NormImg_pf32[(y1-y)*i_ImgX_u16 + (x1+x)] *= maxValue;
      b_NormImg_pf32[(y1-y)*i_ImgX_u16 + (x1-x)] *= maxValue;
      b_NormImg_pf32[(y1+y)*i_ImgX_u16 + (x1-x)] *= maxValue;
    }
  }

#ifdef ENABLE_DEBUG_OPENCV_LOC
  cvCircle(iplImage2, cvPoint((sint32_t)o_CornerList_pt->x_f32, (sint32_t)o_CornerList_pt->y_f32), 5, cvScalar(255,0,0,0), 1, 8, 0 );

  cvShowImage ("Initial Candidate", iplImage2);
  cvWaitKey(OPENCV_WAITIME);
#endif

  return 1;
}

static sint32_t f_findClosestCorner (io_S_PosSub_t *i_Corners_pt, uint16_t i_NumCorners_ui16, uint16_t i_IndexCamera_ui16, float32_t minAng_f32, float32_t maxAng_f32, sint16_t i_SkipCorner_si16)
{
  sint32_t i,minIndex=-1;
  float32_t ang_f32, dist_f32, dX, dY;
  float32_t minDist = 99999999999.0F;

  for (i=0 ; i<i_NumCorners_ui16 ; i++)
  {
    if (i==i_SkipCorner_si16)
      continue;

    dX      = i_Corners_pt[i_IndexCamera_ui16].x_f32-i_Corners_pt[i].x_f32;
    dY      = i_Corners_pt[i_IndexCamera_ui16].y_f32-i_Corners_pt[i].y_f32;
    dist_f32  = dX*dX + dY*dY;
    ang_f32   = (float32_t)atan2 (dX,dY)/3.1415F*180.0F;

    if ((minAng_f32 < maxAng_f32 && ang_f32>=minAng_f32 &&  ang_f32<maxAng_f32 && dist_f32<minDist && i!=i_IndexCamera_ui16) ||
        (minAng_f32 > maxAng_f32 && ang_f32>minAng_f32 && dist_f32<minDist && i!=i_IndexCamera_ui16) ||
        (minAng_f32 > maxAng_f32 && ang_f32<=maxAng_f32 && dist_f32<minDist && i!=i_IndexCamera_ui16))
    {
      minDist = dist_f32;
      minIndex = i;
    }
  }

  return minIndex;
}
#endif

static sint32_t f_FindCorner_s32 (const uint16_t i_ImgX_u16 , const uint16_t i_ImgY_u16, const float32_t i_NormImg_af32[], io_S_PosSub_t o_CornerList_as[], const uint16_t i_NumCorners_u16)
{
  /* DD-ID: {C6057AAE-8D3E-4ace-B86F-A9F6129E9C8E}*/
  const sint32_t c_Ksz_s32 = 5;
  sint32_t v_X_s32;
  sint32_t v_Y_s32;
  sint32_t v_I_s32;
  sint32_t v_Ix_s32;
  sint32_t v_CornerCount_s32=0;
  sint32_t v_Found_s32;
  float32_t v_Value_f32 = 0.0F;
  io_S_PosSub_t v_TmpCorner_s;

  sint32_t v_Xlist_as32[LTARGET_MAX_NUMBER_CORNERS];
  float32_t v_Vlist_af32[LTARGET_MAX_NUMBER_CORNERS];

  (void)memset (v_Xlist_as32, 0, sizeof(sint32_t)*LTARGET_MAX_NUMBER_CORNERS);
  (void)memset (v_Vlist_af32, 0, sizeof(float32_t)*LTARGET_MAX_NUMBER_CORNERS);
  (void)memset (o_CornerList_as, 0, sizeof(io_S_PosSub_t)*i_NumCorners_u16);

  /* localize highest candidate */
  for (v_Y_s32=c_Ksz_s32 ; v_Y_s32<(i_ImgY_u16-c_Ksz_s32); v_Y_s32++)
  {
    /* find hot spots in line */
    v_Ix_s32=1;
    (void)memset (&v_Xlist_as32[0], 0, sizeof(sint32_t)*100);
    (void)memset (&v_Vlist_af32[0], 0, sizeof(float32_t)*100);
    for (v_X_s32=c_Ksz_s32 ; v_X_s32<(i_ImgX_u16-c_Ksz_s32) ; v_X_s32++)
    {
      v_Value_f32 = (float32_t) fabs(i_NormImg_af32[(v_Y_s32*i_ImgX_u16) + v_X_s32]);
      if (v_Value_f32 > 0.5F)
      {
        if ((v_X_s32-v_Xlist_as32[v_Ix_s32-1]) > c_Ksz_s32)
        {
          v_Ix_s32++;
        }
        if (v_Value_f32 > fabs(v_Vlist_af32[v_Ix_s32-1]))
        {
          v_Xlist_as32[v_Ix_s32-1] = v_X_s32;
          v_Vlist_af32[v_Ix_s32-1] = i_NormImg_af32[(v_Y_s32*i_ImgX_u16) + v_X_s32];
        }
      }
    }

    /* merge hot spots vertically */
    for (v_Ix_s32=1 ; (v_Ix_s32<LTARGET_MAX_NUMBER_CORNERS) && (v_Xlist_as32[v_Ix_s32]!=0) ; v_Ix_s32++)
    {
      v_Found_s32 = 0;
      for (v_I_s32=0 ; v_I_s32<v_CornerCount_s32 ; v_I_s32++)
      {
        /* PRQA S 3415 2 */ /* No side effects */
        if(    (fabs((float32_t)v_Xlist_as32[v_Ix_s32]-o_CornerList_as[v_I_s32].x_f32) < (float32_t)c_Ksz_s32)
            && (fabs((float32_t)v_Y_s32-o_CornerList_as[v_I_s32].y_f32) < (float32_t)c_Ksz_s32 ))
        {
          if (fabs(v_Vlist_af32[v_Ix_s32]) > fabs(o_CornerList_as[v_I_s32].v_f32))
          {
            o_CornerList_as[v_I_s32].v_f32 = v_Vlist_af32[v_Ix_s32];
            o_CornerList_as[v_I_s32].x_f32 = (float32_t)v_Xlist_as32[v_Ix_s32];
            o_CornerList_as[v_I_s32].y_f32 = (float32_t)v_Y_s32;
            v_Found_s32 = 1;
          }
          else
          {
            v_Found_s32 = -1;
          }
        }

      }
      if (    (v_Found_s32 == 0)
           && (v_CornerCount_s32<LTARGET_MAX_NUMBER_CORNERS))
      {
        o_CornerList_as[v_CornerCount_s32].v_f32 = v_Vlist_af32[v_Ix_s32];
        o_CornerList_as[v_CornerCount_s32].x_f32 = (float32_t)v_Xlist_as32[v_Ix_s32];
        o_CornerList_as[v_CornerCount_s32].y_f32 = (float32_t)v_Y_s32;
        v_CornerCount_s32++;
      }
    }
  }

  /*
	srand((unsigned) time(&t));
	o_CornerList_pt[iCornerCount].v_f32 = ((float32_t)(rand()%2))*2.0F-1.0F;
	o_CornerList_pt[iCornerCount].x_f32 = (float32_t)rand()*i_ImgX_u16/RAND_MAX;
	o_CornerList_pt[iCornerCount].y_f32 = (float32_t)rand()*i_ImgY_u16/RAND_MAX;
	iCornerCount++;
   */


  /* bouble sort corners */
  v_Found_s32 = 1;
  for (v_I_s32=0 ; (v_I_s32<v_CornerCount_s32) && (v_Found_s32==1); v_I_s32++)
  {
    v_Found_s32 = 0;
    for (v_Ix_s32=1 ; v_Ix_s32<v_CornerCount_s32 ; v_Ix_s32++)
    {
      if (fabs(o_CornerList_as[v_Ix_s32].v_f32) > fabs(o_CornerList_as[v_Ix_s32-1].v_f32))
      {
        (void)memcpy (&v_TmpCorner_s, &o_CornerList_as[v_Ix_s32-1], sizeof(io_S_PosSub_t));
        (void)memcpy (&o_CornerList_as[v_Ix_s32-1], &o_CornerList_as[v_Ix_s32], sizeof(io_S_PosSub_t));
        (void)memcpy (&o_CornerList_as[v_Ix_s32], &v_TmpCorner_s, sizeof(io_S_PosSub_t));
        v_Found_s32 = 1;
      }
    }
  }

#ifdef ENABLE_DEBUG_OPENCV_LOC
  for (v_I_s32=0 ; v_I_s32<v_CornerCount_s32; v_I_s32++)
  {
    cvCircle(iplImage2, cvPoint(o_CornerList_as[v_I_s32].x_f32, o_CornerList_as[v_I_s32].y_f32), 5, cvScalar(255,0,0,0), 1, 8, 0 );
    cvShowImage ("Initial Candidate", iplImage2);
    cvWaitKey(OPENCV_WAITIME);
  }
#endif

  return v_CornerCount_s32;
}

static sint32_t f_updateCornerAM_s32 (const io_S_PosSub_t i_Corners_as[], const uint16_t i_NumCorners_u16, const sint32_t i_IndexCamera_s32)
{
  /* DD-ID: {C0D1AB28-F64A-4153-819F-A0EA8A66F894}*/
  sint32_t v_I_s32;
  float32_t v_Ang_f32;
  float32_t v_Dist_f32;
  float32_t v_Dx_f32;
  float32_t v_Dy_f32;
  float32_t v_MinDist_a2f32[2][4] = {{99999999999.0F, 99999999999.0F, 99999999999.0F, 99999999999.0F},
                                     {99999999999.0F, 99999999999.0F, 99999999999.0F, 99999999999.0F}};

  /* init */
  (void)memset (&Corner_v_CornerAn_as[i_IndexCamera_s32], 0xFF, sizeof(S_CornerAn_t));

  for (v_I_s32=0 ; v_I_s32<i_NumCorners_u16 ; v_I_s32++)
  {
    if (i_IndexCamera_s32!=v_I_s32)
    {
      v_Dx_f32			= i_Corners_as[i_IndexCamera_s32].x_f32-i_Corners_as[v_I_s32].x_f32;
      v_Dy_f32			= i_Corners_as[i_IndexCamera_s32].y_f32-i_Corners_as[v_I_s32].y_f32;
      v_Dist_f32	= (v_Dx_f32*v_Dx_f32) + (v_Dy_f32*v_Dy_f32);
      v_Ang_f32		= ((float32_t)atan2 (v_Dx_f32,v_Dy_f32)/(float32_t)aAlgoECSrc_D_PI)*180.0F;

      /* R */
      if (    (-135.0F<v_Ang_f32)
           && (v_Ang_f32<=-45.0F)
           && (v_MinDist_a2f32[1][0]>v_Dist_f32))
      {
        if (v_MinDist_a2f32[0][0]>v_Dist_f32)
        {
          Corner_v_CornerAn_as[i_IndexCamera_s32].iR_as8[1] = Corner_v_CornerAn_as[i_IndexCamera_s32].iR_as8[0];
          Corner_v_CornerAn_as[i_IndexCamera_s32].iR_as8[0] = (sint8_t)v_I_s32;
          v_MinDist_a2f32[1][0] = v_MinDist_a2f32[0][0];
          v_MinDist_a2f32[0][0] = v_Dist_f32;
        }
        else
        {
          Corner_v_CornerAn_as[i_IndexCamera_s32].iR_as8[1] = (sint8_t)v_I_s32;
          v_MinDist_a2f32[1][0] = v_Dist_f32;
        }
      }

      /* L */
      if (    (45.0F<v_Ang_f32)
           && (v_Ang_f32<=135.0F)
           && (v_MinDist_a2f32[1][1]>v_Dist_f32))
      {
        if (v_MinDist_a2f32[0][1]>v_Dist_f32)
        {
          Corner_v_CornerAn_as[i_IndexCamera_s32].iL_as8[1] = Corner_v_CornerAn_as[i_IndexCamera_s32].iL_as8[0];
          Corner_v_CornerAn_as[i_IndexCamera_s32].iL_as8[0] = (sint8_t)v_I_s32;
          v_MinDist_a2f32[1][1] = v_MinDist_a2f32[0][1];
          v_MinDist_a2f32[0][1] = v_Dist_f32;
        }
        else
        {
          Corner_v_CornerAn_as[i_IndexCamera_s32].iL_as8[1] = (sint8_t)v_I_s32;
          v_MinDist_a2f32[1][1] = v_Dist_f32;
        }
      }

      /* T */
      if (    (-45.0F<v_Ang_f32)
           && (v_Ang_f32<=45.0F)
           && (v_MinDist_a2f32[1][2]>v_Dist_f32))
      {
        if (v_MinDist_a2f32[0][2]>v_Dist_f32)
        {
          Corner_v_CornerAn_as[i_IndexCamera_s32].iT_as8[1] = Corner_v_CornerAn_as[i_IndexCamera_s32].iT_as8[0];
          Corner_v_CornerAn_as[i_IndexCamera_s32].iT_as8[0] = (sint8_t)v_I_s32;
          v_MinDist_a2f32[1][2] = v_MinDist_a2f32[0][2];
          v_MinDist_a2f32[0][2] = v_Dist_f32;
        }
        else
        {
          Corner_v_CornerAn_as[i_IndexCamera_s32].iT_as8[1] = (sint8_t)v_I_s32;
          v_MinDist_a2f32[1][2] = v_Dist_f32;
        }
      }

      /* B */
      if (    (135.0F<v_Ang_f32)
           && (v_Ang_f32<=-135.0F)
           && (v_MinDist_a2f32[1][3]>v_Dist_f32))
      {
        if (v_MinDist_a2f32[0][3]>v_Dist_f32)
        {
          Corner_v_CornerAn_as[i_IndexCamera_s32].iB_as8[1] = Corner_v_CornerAn_as[i_IndexCamera_s32].iB_as8[0];
          Corner_v_CornerAn_as[i_IndexCamera_s32].iB_as8[0] = (sint8_t)v_I_s32;
          v_MinDist_a2f32[1][3] = v_MinDist_a2f32[0][3];
          v_MinDist_a2f32[0][3] = v_Dist_f32;
        }
        else
        {
          Corner_v_CornerAn_as[i_IndexCamera_s32].iB_as8[1] = (sint8_t)v_I_s32;
          v_MinDist_a2f32[1][3] = v_Dist_f32;
        }
      }
    }
  }
  return 1;
}


static sint32_t f_connectRound_s32 (io_S_PosSub_t i_Corners_as[], const uint16_t i_NumCorners_u16, Corner_S_Round_t o_Rounds_as[])
{
  /* DD-ID: {EC487529-2C57-4f80-999C-90895DD47EAF}*/
  sint32_t v_I_s32;
  sint32_t v_NumRounds_s32 = 0;

  for (v_I_s32=0 ; v_I_s32<i_NumCorners_u16 ; ++v_I_s32)
  {
    (void)f_updateCornerAM_s32 (&i_Corners_as[0], i_NumCorners_u16, v_I_s32);
  }

  for (v_I_s32=0 ; v_I_s32<i_NumCorners_u16 ; ++v_I_s32)
  {
    v_NumRounds_s32 += f_addRound_s32 (&i_Corners_as[0], &o_Rounds_as[v_NumRounds_s32], v_I_s32);
  }

#if 0

  if (i_NumCorners_u16==11)
    i_NumCorners_u16=11;
  memset (iplImage2->imageData, 0, iplImage2->width*iplImage2->height);
  for (v_I_s32=0 ; v_I_s32<v_NumRounds_s32 ; v_I_s32++)
  {
    cvLine(iplImage2, cvPoint((sint32_t)o_Rounds_as[v_I_s32].corners_aps[0]->x_f32, (sint32_t)o_Rounds_as[v_I_s32].corners_aps[0]->y_f32),
        cvPoint((sint32_t)o_Rounds_as[v_I_s32].corners_aps[1]->x_f32, (sint32_t)o_Rounds_as[v_I_s32].corners_aps[1]->y_f32), cvScalar(255,0,0,255), 1, 8, 0 );
    cvLine(iplImage2, cvPoint((sint32_t)o_Rounds_as[v_I_s32].corners_aps[1]->x_f32, (sint32_t)o_Rounds_as[v_I_s32].corners_aps[1]->y_f32),
           cvPoint((sint32_t)o_Rounds_as[v_I_s32].corners_aps[2]->x_f32, (sint32_t)o_Rounds_as[v_I_s32].corners_aps[2]->y_f32), cvScalar(255,0,0,0), 1, 8, 0 );
    cvLine(iplImage2, cvPoint((sint32_t)o_Rounds_as[v_I_s32].corners_aps[2]->x_f32, (sint32_t)o_Rounds_as[v_I_s32].corners_aps[2]->y_f32),
           cvPoint((sint32_t)o_Rounds_as[v_I_s32].corners_aps[3]->x_f32, (sint32_t)o_Rounds_as[v_I_s32].corners_aps[3]->y_f32), cvScalar(255,0,0,0), 1, 8, 0 );
    cvLine(iplImage2, cvPoint((sint32_t)o_Rounds_as[v_I_s32].corners_aps[3]->x_f32, (sint32_t)o_Rounds_as[v_I_s32].corners_aps[3]->y_f32),
           cvPoint((sint32_t)o_Rounds_as[v_I_s32].corners_aps[0]->x_f32, (sint32_t)o_Rounds_as[v_I_s32].corners_aps[0]->y_f32), cvScalar(255,0,0,0), 1, 8, 0 );
    cvShowImage ("Round Candidate", iplImage2);
    if (i_NumCorners_u16==11)
      cvWaitKey(0);
  }
#endif

  return v_NumRounds_s32;
}


static sint32_t f_addRound_s32 (io_S_PosSub_t i_Corners_as[], Corner_S_Round_t o_Rounds_as[], const sint32_t i_StartCorner_s32)
{
  /* DD-ID: {4B77C974-025D-425e-824C-C5D5095C3294}*/
  sint32_t v_Ret_s32 = 0;
  sint32_t v_I_s32;
  sint32_t v_K_s32;
  sint32_t v_L_s32;
  sint32_t v_I0_s32 = i_StartCorner_s32;
  sint32_t v_I1_s32=-1;
  sint32_t v_I2_s32=-1;
  sint32_t v_I3_s32=-1;

  for (v_I_s32=0 ; v_I_s32<2; v_I_s32++)
  {
    for (v_K_s32=0 ; v_K_s32<2; v_K_s32++)
    {
      for (v_L_s32=0 ; v_L_s32<2; v_L_s32++)
      {
        v_I1_s32=-1;
        v_I2_s32=-1;
        v_I3_s32=-1;
        if (v_I0_s32!=-1)
        {
          v_I1_s32 = Corner_v_CornerAn_as[v_I0_s32].iR_as8[v_I_s32];
        }
        if (v_I1_s32!=-1)
        {
          v_I2_s32 = Corner_v_CornerAn_as[v_I1_s32].iT_as8[v_K_s32];
        }
        if (v_I2_s32!=-1)
        {
          v_I3_s32 = Corner_v_CornerAn_as[v_I2_s32].iL_as8[v_L_s32];
        }
        if (v_I3_s32!=-1)
        {
          o_Rounds_as[v_Ret_s32].corners_aps[0] = &i_Corners_as[v_I0_s32];
          o_Rounds_as[v_Ret_s32].corners_aps[1] = &i_Corners_as[v_I1_s32];
          o_Rounds_as[v_Ret_s32].corners_aps[2] = &i_Corners_as[v_I2_s32];
          o_Rounds_as[v_Ret_s32].corners_aps[3] = &i_Corners_as[v_I3_s32];
          if (1 == f_verifyRound_s8 (&o_Rounds_as[v_Ret_s32]))
          {
#if 0
            memset (iplImage2->imageData, 0, iplImage2->width*iplImage2->height);
            cvLine(iplImage2, cvPoint((sint32_t)o_Rounds_as[v_Ret_s32].corners_aps[0]->x_f32, (sint32_t)o_Rounds_as[v_Ret_s32].corners_aps[0]->y_f32),
                   cvPoint((sint32_t)o_Rounds_as[v_Ret_s32].corners_aps[1]->x_f32, (sint32_t)o_Rounds_as[v_Ret_s32].corners_aps[1]->y_f32), cvScalar(255,0,0,255), 1, 8, 0 );
            cvLine(iplImage2, cvPoint((sint32_t)o_Rounds_as[v_Ret_s32].corners_aps[1]->x_f32, (sint32_t)o_Rounds_as[v_Ret_s32].corners_aps[1]->y_f32),
                   cvPoint((sint32_t)o_Rounds_as[v_Ret_s32].corners_aps[2]->x_f32, (sint32_t)o_Rounds_as[v_Ret_s32].corners_aps[2]->y_f32), cvScalar(255,0,0,0), 1, 8, 0 );
            cvLine(iplImage2, cvPoint((sint32_t)o_Rounds_as[v_Ret_s32].corners_aps[2]->x_f32, (sint32_t)o_Rounds_as[v_Ret_s32].corners_aps[2]->y_f32),
                   cvPoint((sint32_t)o_Rounds_as[v_Ret_s32].corners_aps[3]->x_f32, (sint32_t)o_Rounds_as[v_Ret_s32].corners_aps[3]->y_f32), cvScalar(255,0,0,0), 1, 8, 0 );
            cvLine(iplImage2, cvPoint((sint32_t)o_Rounds_as[v_Ret_s32].corners_aps[3]->x_f32, (sint32_t)o_Rounds_as[v_Ret_s32].corners_aps[3]->y_f32),
                   cvPoint((sint32_t)o_Rounds_as[v_Ret_s32].corners_aps[0]->x_f32, (sint32_t)o_Rounds_as[v_Ret_s32].corners_aps[0]->y_f32), cvScalar(255,0,0,0), 1, 8, 0 );
            cvShowImage ("Round Candidate", iplImage2);
            cvWaitKey(0);
#endif

            v_Ret_s32++;
          }
        }
      }
    }
  }

  return v_Ret_s32;
}

static sint8_t f_verifyRound_s8 (const Corner_S_Round_t i_Rounds_as[])
{
  /* DD-ID: {BEE23B6A-BFBB-4b64-B1E4-992D13826C7F}*/

  sint8_t v_Ret_s8=-1;

  if (    (i_Rounds_as->corners_aps[0]->v_f32 < 0.0F)
       && (i_Rounds_as->corners_aps[1]->v_f32 > 0.0F)
       && (i_Rounds_as->corners_aps[2]->v_f32 < 0.0F)
       && (i_Rounds_as->corners_aps[3]->v_f32 > 0.0F))
  {
    v_Ret_s8 = 1;
  }
  else if (    (i_Rounds_as->corners_aps[0]->v_f32 > 0.0F)
            && (i_Rounds_as->corners_aps[1]->v_f32 < 0.0F)
            && (i_Rounds_as->corners_aps[2]->v_f32 > 0.0F)
            && (i_Rounds_as->corners_aps[3]->v_f32 < 0.0F))
  {
    v_Ret_s8 = 1;
  }
  else
  {

  }
  return v_Ret_s8;
}


static sint16_t f_findNextRound_s16 (const Corner_S_Round_t o_Rounds_as[], const uint16_t i_NumRounds_u16, const uint16_t i_Index_u16, const sint8_t i_SkipIndex_s8)
{
  /* DD-ID: {0F46D72B-5563-43ae-A03B-7CEFA9118284}*/
  uint16_t v_I_u16;
  sint16_t v_NextIndex_s16 = -1;

  for (v_I_u16=0 ; v_I_u16<i_NumRounds_u16 ; v_I_u16++)
  {
    if (    (i_SkipIndex_s8==-1)
         || (i_SkipIndex_s8!=(sint8_t)v_I_u16))
    {
      if (    (o_Rounds_as[i_Index_u16].corners_aps[2] == o_Rounds_as[v_I_u16].corners_aps[3])
           && (o_Rounds_as[i_Index_u16].corners_aps[1] == o_Rounds_as[v_I_u16].corners_aps[0]))
      {
        v_NextIndex_s16 = (sint16_t)v_I_u16;
        break;
      }
    }
  }
  return v_NextIndex_s16;
}


static sint32_t f_connectLine_s32 (Corner_S_Round_t o_Rounds_as[], const uint16_t i_NumRounds_u16, Corner_S_Lines_t o_Lines_as[], const uint16_t i_Nx_u16, const float32_t i_TargetRation_f32)
{
  /* DD-ID: {4C1C84A5-ECDD-4a02-B3B7-B5835D8B4EB1}*/
  sint32_t v_I_s32;
  sint32_t v_I1_s32;
  sint32_t v_IN_s32;
  sint32_t v_NumLines_s32=0;
  sint16_t v_I2_s16;

  for (v_I_s32=0 ; v_I_s32<i_NumRounds_u16 ; v_I_s32++)
  {
    o_Lines_as[v_NumLines_s32].rounds_aps[0] = &o_Rounds_as[v_I_s32];
    v_I1_s32 = v_I_s32;

    for (v_IN_s32=1 ; v_IN_s32<(i_Nx_u16-1) ; v_IN_s32++)
    {
      v_I2_s16 = f_findNextRound_s16 (&o_Rounds_as[0], i_NumRounds_u16, (uint16_t)v_I1_s32, -1);
      if (v_I2_s16<0)
      {
        break;
      }
      o_Lines_as[v_NumLines_s32].rounds_aps[v_IN_s32] = &o_Rounds_as[v_I2_s16];
      v_I1_s32 = v_I2_s16;
    }
    if (v_IN_s32 == (i_Nx_u16-1))
    {
      if (1 == f_verifyLine_s8(&o_Lines_as[v_NumLines_s32], i_Nx_u16, i_TargetRation_f32))
      {
        v_NumLines_s32++;
      }
      else
      {
      }
    }
  }

#ifdef ENABLE_DEBUG_OPENCV_LINES
  memset (iplImage2->imageData, 0, iplImage2->width*iplImage2->height);
  for (v_I_s32=0 ; v_I_s32<v_NumLines_s32 ; ++v_I_s32)
  {
    for (v_I2_s16=0 ; v_I2_s16<i_Nx_u16-1 ; v_I2_s16++)
    {
      cvLine(iplImage2, cvPoint((sint32_t)o_Lines_as[v_I_s32].rounds_aps[v_I2_s16]->corners_aps[0]->x_f32, (sint32_t)o_Lines_as[v_I_s32].rounds_aps[v_I2_s16]->corners_aps[0]->y_f32),
          cvPoint((sint32_t)o_Lines_as[v_I_s32].rounds_aps[v_I2_s16]->corners_aps[1]->x_f32, (sint32_t)o_Lines_as[v_I_s32].rounds_aps[v_I2_s16]->corners_aps[1]->y_f32), cvScalar(255,0,0,0), 1, 8, 0 );
      cvLine(iplImage2, cvPoint((sint32_t)o_Lines_as[v_I_s32].rounds_aps[v_I2_s16]->corners_aps[1]->x_f32, (sint32_t)o_Lines_as[v_I_s32].rounds_aps[v_I2_s16]->corners_aps[1]->y_f32),
             cvPoint((sint32_t)o_Lines_as[v_I_s32].rounds_aps[v_I2_s16]->corners_aps[2]->x_f32, (sint32_t)o_Lines_as[v_I_s32].rounds_aps[v_I2_s16]->corners_aps[2]->y_f32), cvScalar(255,0,0,0), 1, 8, 0 );
      cvLine(iplImage2, cvPoint((sint32_t)o_Lines_as[v_I_s32].rounds_aps[v_I2_s16]->corners_aps[2]->x_f32, (sint32_t)o_Lines_as[v_I_s32].rounds_aps[v_I2_s16]->corners_aps[2]->y_f32),
             cvPoint((sint32_t)o_Lines_as[v_I_s32].rounds_aps[v_I2_s16]->corners_aps[3]->x_f32, (sint32_t)o_Lines_as[v_I_s32].rounds_aps[v_I2_s16]->corners_aps[3]->y_f32), cvScalar(255,0,0,0), 1, 8, 0 );
      cvLine(iplImage2, cvPoint((sint32_t)o_Lines_as[v_I_s32].rounds_aps[v_I2_s16]->corners_aps[3]->x_f32, (sint32_t)o_Lines_as[v_I_s32].rounds_aps[v_I2_s16]->corners_aps[3]->y_f32),
             cvPoint((sint32_t)o_Lines_as[v_I_s32].rounds_aps[v_I2_s16]->corners_aps[0]->x_f32, (sint32_t)o_Lines_as[v_I_s32].rounds_aps[v_I2_s16]->corners_aps[0]->y_f32), cvScalar(255,0,0,0), 1, 8, 0 );
    }
    cvShowImage ("Lines Candidate", iplImage2);
    cvWaitKey(0);
  }
#endif

  return v_NumLines_s32;
}

static sint8_t f_verifyLine_s8 (const Corner_S_Lines_t i_Line_as[], const uint16_t i_Nx_u16, float32_t i_TargetRation_f32)
{
  /* DD-ID: {29B738EC-9335-4798-ABA9-9F711E6324C6}*/
  sint8_t v_Ret_s8 = -1;
  float32_t v_X_f32=0.0F;
  float32_t v_Y_f32=0.0F;
  float32_t v_TmpX_f32;
  float32_t v_TmpY_f32;
  float32_t v_Ratio_f32=0.0F;

  v_TmpX_f32 = i_Line_as->rounds_aps[i_Nx_u16-2]->corners_aps[1]->x_f32 - i_Line_as->rounds_aps[0]->corners_aps[0]->x_f32;
  v_TmpY_f32 = i_Line_as->rounds_aps[i_Nx_u16-2]->corners_aps[1]->y_f32 - i_Line_as->rounds_aps[0]->corners_aps[0]->y_f32;
  v_X_f32 = (float32_t)sqrt((v_TmpX_f32*v_TmpX_f32) + (v_TmpY_f32*v_TmpY_f32))/(float32_t)(i_Nx_u16-1);

  v_TmpX_f32 = i_Line_as->rounds_aps[i_Nx_u16-2]->corners_aps[2]->x_f32 - i_Line_as->rounds_aps[0]->corners_aps[3]->x_f32;
  v_TmpY_f32 = i_Line_as->rounds_aps[i_Nx_u16-2]->corners_aps[2]->y_f32 - i_Line_as->rounds_aps[0]->corners_aps[3]->y_f32;
  v_X_f32 += (float32_t)sqrt((v_TmpX_f32*v_TmpX_f32) + (v_TmpY_f32*v_TmpY_f32))/(float32_t)(i_Nx_u16-1);

  v_TmpX_f32 = i_Line_as->rounds_aps[0]->corners_aps[3]->x_f32 - i_Line_as->rounds_aps[0]->corners_aps[0]->x_f32;
  v_TmpY_f32 = i_Line_as->rounds_aps[0]->corners_aps[3]->y_f32 - i_Line_as->rounds_aps[0]->corners_aps[0]->y_f32;
  v_Y_f32 = (float32_t)sqrt((v_TmpX_f32*v_TmpX_f32) + (v_TmpY_f32*v_TmpY_f32));

  v_TmpX_f32 = i_Line_as->rounds_aps[i_Nx_u16-2]->corners_aps[2]->x_f32 - i_Line_as->rounds_aps[i_Nx_u16-2]->corners_aps[1]->x_f32;
  v_TmpY_f32 = i_Line_as->rounds_aps[i_Nx_u16-2]->corners_aps[2]->y_f32 - i_Line_as->rounds_aps[i_Nx_u16-2]->corners_aps[1]->y_f32;
  v_Y_f32 += (float32_t)sqrt((v_TmpX_f32*v_TmpX_f32) + (v_TmpY_f32*v_TmpY_f32));

  v_Ratio_f32 = v_Y_f32/v_X_f32;

  /* ME_Debugger_F_Printf_v ("\nFinal LineRation: %f", ratio_f32); */
  if (0 == cmpNearToZeroF32_s32(i_TargetRation_f32 - 1.0F)) /* Comparing if i_TargetRation_f32 == 1.0F */
  {
    if ((v_Ratio_f32 > 0.5F) && (v_Ratio_f32 < 2.0F))
    {
      v_Ret_s8 = 1;
    }
    else
    {
    }
  }
  else if (0 == cmpNearToZeroF32_s32(i_TargetRation_f32 - 2.0F)) /* Comparing if i_TargetRation_f32 == 2.0F */
  {

    if ((v_Ratio_f32 > 1.5F) && (v_Ratio_f32 < 3.5F))
    {
      v_Ret_s8 = 1;
    }
    else
    {
    }
  }
  else
  {
  }

  return v_Ret_s8;
}


static sint16_t f_findNextLine_s16 (const Corner_S_Lines_t i_Lines_as[], const uint16_t i_NumLines_u16, const uint16_t i_Index_u16, const uint16_t i_Nx_u16)
{
  /* DD-ID: {FE57C2DF-CD30-4aa8-94A3-C417978CD1B8}*/
  uint16_t v_I_u16;
  uint16_t v_I2_u16;
  sint16_t v_NextIndex_s16 = -1;

  for (v_I_u16=0 ; v_I_u16<i_NumLines_u16 ; v_I_u16++)
  {
    for (v_I2_u16=1 ; v_I2_u16<(i_Nx_u16-1) ; v_I2_u16++)
    {
      if ((i_Lines_as[v_I_u16].rounds_aps[v_I2_u16]->corners_aps[1] != i_Lines_as[i_Index_u16].rounds_aps[v_I2_u16]->corners_aps[2]) ||
          (i_Lines_as[v_I_u16].rounds_aps[v_I2_u16]->corners_aps[0] != i_Lines_as[i_Index_u16].rounds_aps[v_I2_u16]->corners_aps[3]))
      {
        break;
      }
    }
    if (v_I2_u16==(i_Nx_u16-1))
    {
      v_NextIndex_s16 = (sint16_t)v_I_u16;
      break;
    }
  }

  return v_NextIndex_s16;
}

static uint8_t f_connectGrid_u8 (Corner_S_Lines_t i_Lines_as[], const uint16_t i_NumLines_u16, Corner_S_Grid_t o_Grid_as[], const uint16_t i_Nx_u16, const uint16_t i_Ny_u16, const sint8_t i_StartPattern_s8)
{
  /* DD-ID: {787175B0-66A2-4e90-921A-584912BF8B89}*/
  sint32_t v_I_s32;
  sint32_t v_I1_s32;
  sint32_t v_IN_s32;
  sint16_t v_I2_s16;
  uint8_t v_NumGrids_u8 = 0U;

  for (v_I_s32=0 ; v_I_s32<i_NumLines_u16 ; v_I_s32++)
  {
    o_Grid_as[v_NumGrids_u8].lines_aps[0] = &i_Lines_as[v_I_s32];
    v_I1_s32 = v_I_s32;

    for (v_IN_s32=1 ; v_IN_s32<(i_Ny_u16-1) ; v_IN_s32++)
    {
      v_I2_s16 = f_findNextLine_s16 (i_Lines_as, i_NumLines_u16, (uint16_t)v_I1_s32, i_Nx_u16);
      if (v_I2_s16<0)
      {
        break;
      }
      o_Grid_as[v_NumGrids_u8].lines_aps[v_IN_s32] = &i_Lines_as[v_I2_s16];
      v_I1_s32 = v_I2_s16;
    }
    if (v_IN_s32 == (i_Ny_u16-1))
    {
      if (1 == f_verifyGrid_s16 (&o_Grid_as[v_NumGrids_u8], i_Nx_u16, i_Ny_u16, i_StartPattern_s8))
      {
        v_NumGrids_u8++;
      }
    }
  }

#ifdef ENABLE_DEBUG_OPENCV_GRIDS

  for (v_I_s32=0 ; v_I_s32<v_NumGrids_u8 ; ++v_I_s32)
  {
    memset (iplImage2->imageData, 0, iplImage2->width*iplImage2->height);
    for (v_I1_s32=0 ; v_I1_s32<i_Ny_u16-1 ; ++v_I1_s32)
    {
      for (v_I2_s16=0 ; v_I2_s16<i_Nx_u16-1 ; v_I2_s16++)
      {
        cvLine(iplImage2, cvPoint((sint32_t)o_Grid_as[v_I_s32].lines_aps[v_I1_s32]->rounds_aps[v_I2_s16]->corners_aps[0]->x_f32, (sint32_t)o_Grid_as[v_I_s32].lines_aps[v_I1_s32]->rounds_aps[v_I2_s16]->corners_aps[0]->y_f32),
            cvPoint((sint32_t)o_Grid_as[v_I_s32].lines_aps[v_I1_s32]->rounds_aps[v_I2_s16]->corners_aps[1]->x_f32, (sint32_t)o_Grid_as[v_I_s32].lines_aps[v_I1_s32]->rounds_aps[v_I2_s16]->corners_aps[1]->y_f32), cvScalar(255,0,0,0), 1, 8, 0 );
        cvLine(iplImage2, cvPoint((sint32_t)o_Grid_as[v_I_s32].lines_aps[v_I1_s32]->rounds_aps[v_I2_s16]->corners_aps[1]->x_f32, (sint32_t)o_Grid_as[v_I_s32].lines_aps[v_I1_s32]->rounds_aps[v_I2_s16]->corners_aps[1]->y_f32),
               cvPoint((sint32_t)o_Grid_as[v_I_s32].lines_aps[v_I1_s32]->rounds_aps[v_I2_s16]->corners_aps[2]->x_f32, (sint32_t)o_Grid_as[v_I_s32].lines_aps[v_I1_s32]->rounds_aps[v_I2_s16]->corners_aps[2]->y_f32), cvScalar(255,0,0,0), 1, 8, 0 );
        cvLine(iplImage2, cvPoint((sint32_t)o_Grid_as[v_I_s32].lines_aps[v_I1_s32]->rounds_aps[v_I2_s16]->corners_aps[2]->x_f32, (sint32_t)o_Grid_as[v_I_s32].lines_aps[v_I1_s32]->rounds_aps[v_I2_s16]->corners_aps[2]->y_f32),
               cvPoint((sint32_t)o_Grid_as[v_I_s32].lines_aps[v_I1_s32]->rounds_aps[v_I2_s16]->corners_aps[3]->x_f32, (sint32_t)o_Grid_as[v_I_s32].lines_aps[v_I1_s32]->rounds_aps[v_I2_s16]->corners_aps[3]->y_f32), cvScalar(255,0,0,0), 1, 8, 0 );
        cvLine(iplImage2, cvPoint((sint32_t)o_Grid_as[v_I_s32].lines_aps[v_I1_s32]->rounds_aps[v_I2_s16]->corners_aps[3]->x_f32, (sint32_t)o_Grid_as[v_I_s32].lines_aps[v_I1_s32]->rounds_aps[v_I2_s16]->corners_aps[3]->y_f32),
               cvPoint((sint32_t)o_Grid_as[v_I_s32].lines_aps[v_I1_s32]->rounds_aps[v_I2_s16]->corners_aps[0]->x_f32, (sint32_t)o_Grid_as[v_I_s32].lines_aps[v_I1_s32]->rounds_aps[v_I2_s16]->corners_aps[0]->y_f32), cvScalar(255,0,0,0), 1, 8, 0 );
      }
    }
    cvShowImage ("Grids Candidate", iplImage2);
    cvWaitKey(0);
  }
#endif

  return v_NumGrids_u8;
}

static sint16_t f_verifyGrid_s16 (const Corner_S_Grid_t i_Grid_as[], const uint16_t i_Nx_u16, const uint16_t i_Ny_u16, const sint8_t i_StartPattern_s8)
{
  /* DD-ID: {935157AA-0B11-4db5-80EC-B5B0708C4964}*/
  uint16_t v_Ix_u16;
  uint16_t v_Iy_u16;
  uint16_t v_Iy2_u16;
  sint16_t v_Result_s16 = 1;
  float32_t v_Height_f32 = -1.0F;
  float32_t v_HeightTmp_f32;
  float32_t v_Width_f32 = -1.0F;
  float32_t v_WidthTmp_f32;

  for (v_Iy_u16=0 ; v_Iy_u16<(i_Ny_u16-1) ; v_Iy_u16++)
  {
    v_HeightTmp_f32 = 0.0F;
    for (v_Ix_u16=0 ; v_Ix_u16<(i_Nx_u16-1) ; v_Ix_u16++)
    {
      /* check corner type */
      if (    (    (    ((v_Ix_u16%2)==0)
                     && ((v_Iy_u16%2)==0))
                || (    ((v_Ix_u16%2)==1)
                     && ((v_Iy_u16%2)==1)))
           && (    (((float32_t)i_StartPattern_s8 * i_Grid_as->lines_aps[v_Iy_u16]->rounds_aps[v_Ix_u16]->corners_aps[0]->v_f32) < 0.0F)
                || (((float32_t)i_StartPattern_s8 * i_Grid_as->lines_aps[v_Iy_u16]->rounds_aps[v_Ix_u16]->corners_aps[1]->v_f32) > 0.0F)
                || (((float32_t)i_StartPattern_s8 * i_Grid_as->lines_aps[v_Iy_u16]->rounds_aps[v_Ix_u16]->corners_aps[2]->v_f32) < 0.0F)
                || (((float32_t)i_StartPattern_s8 * i_Grid_as->lines_aps[v_Iy_u16]->rounds_aps[v_Ix_u16]->corners_aps[3]->v_f32) > 0.0F)))
      {
        v_Result_s16 = -1;
      }

      /* check corner type */
      if (    (    (    ((v_Ix_u16%2)==1)
                     && ((v_Iy_u16%2)==0))
                || (    ((v_Ix_u16%2)==0)
                     && ((v_Iy_u16%2)==1)))
           && (    (((float32_t)i_StartPattern_s8 * i_Grid_as->lines_aps[v_Iy_u16]->rounds_aps[v_Ix_u16]->corners_aps[0]->v_f32) > 0.0F)
                || (((float32_t)i_StartPattern_s8 * i_Grid_as->lines_aps[v_Iy_u16]->rounds_aps[v_Ix_u16]->corners_aps[1]->v_f32) < 0.0F)
                || (((float32_t)i_StartPattern_s8 * i_Grid_as->lines_aps[v_Iy_u16]->rounds_aps[v_Ix_u16]->corners_aps[2]->v_f32) > 0.0F)
                || (((float32_t)i_StartPattern_s8 * i_Grid_as->lines_aps[v_Iy_u16]->rounds_aps[v_Ix_u16]->corners_aps[3]->v_f32) < 0.0F)))
      {
        v_Result_s16 = -1;
      }

      /* calculate height for dimesnion check */
      v_HeightTmp_f32 += (float32_t) sqrt( pow((i_Grid_as->lines_aps[v_Iy_u16]->rounds_aps[v_Ix_u16]->corners_aps[3]->x_f32 - i_Grid_as->lines_aps[v_Iy_u16]->rounds_aps[v_Ix_u16]->corners_aps[0]->x_f32), 2) +
          pow((i_Grid_as->lines_aps[v_Iy_u16]->rounds_aps[v_Ix_u16]->corners_aps[3]->y_f32 - i_Grid_as->lines_aps[v_Iy_u16]->rounds_aps[v_Ix_u16]->corners_aps[0]->y_f32), 2) );
      v_HeightTmp_f32 += (float32_t) sqrt( pow((i_Grid_as->lines_aps[v_Iy_u16]->rounds_aps[v_Ix_u16]->corners_aps[2]->x_f32 - i_Grid_as->lines_aps[v_Iy_u16]->rounds_aps[v_Ix_u16]->corners_aps[1]->x_f32), 2) +
          pow((i_Grid_as->lines_aps[v_Iy_u16]->rounds_aps[v_Ix_u16]->corners_aps[2]->y_f32 - i_Grid_as->lines_aps[v_Iy_u16]->rounds_aps[v_Ix_u16]->corners_aps[1]->y_f32), 2) );

      v_WidthTmp_f32 = 0.0;
      for (v_Iy2_u16=0 ; v_Iy2_u16<(i_Ny_u16-1) ; v_Iy2_u16++)
      {
        /* calculate width for dimesnion check */
        v_WidthTmp_f32 += (float32_t) sqrt( pow((i_Grid_as->lines_aps[v_Iy2_u16]->rounds_aps[v_Ix_u16]->corners_aps[3]->x_f32 - i_Grid_as->lines_aps[v_Iy2_u16]->rounds_aps[v_Ix_u16]->corners_aps[2]->x_f32), 2) +
            pow((i_Grid_as->lines_aps[v_Iy2_u16]->rounds_aps[v_Ix_u16]->corners_aps[3]->y_f32 - i_Grid_as->lines_aps[v_Iy2_u16]->rounds_aps[v_Ix_u16]->corners_aps[2]->y_f32), 2) );
        v_WidthTmp_f32 += (float32_t) sqrt( pow((i_Grid_as->lines_aps[v_Iy2_u16]->rounds_aps[v_Ix_u16]->corners_aps[0]->x_f32 - i_Grid_as->lines_aps[v_Iy2_u16]->rounds_aps[v_Ix_u16]->corners_aps[1]->x_f32), 2) +
            pow((i_Grid_as->lines_aps[v_Iy2_u16]->rounds_aps[v_Ix_u16]->corners_aps[0]->y_f32 - i_Grid_as->lines_aps[v_Iy2_u16]->rounds_aps[v_Ix_u16]->corners_aps[1]->y_f32), 2) );
      }

      /* height dimension check */
      v_WidthTmp_f32 /= 2.0F*(float32_t)(i_Ny_u16-1);
      if (    (v_Width_f32>0.0F)
           && (    ((v_WidthTmp_f32/v_Width_f32)>1.4F)
                || ((v_Width_f32/v_WidthTmp_f32)<0.75F)))
      {
        v_Result_s16 = -1;
      }
      v_Width_f32 = v_WidthTmp_f32;
    }

    /* height dimension check */
    v_HeightTmp_f32 /= 2.0F*(float32_t)(i_Nx_u16-1);
    if (    (v_Height_f32>0.0F)
         && (    ((v_HeightTmp_f32/v_Height_f32)>1.4F)
              || ((v_Height_f32/v_HeightTmp_f32)<0.75F)))
    {
      v_Result_s16 = -1;
    }
    v_Height_f32 = v_HeightTmp_f32;
  }

  return v_Result_s16;
}

/*
 * Main detector interface
 * input: image data
 * output: candidate position & no of candidates
 */
sint8_t aCorner_F_mainDetector_s8(uint8_t *i_ImgData_pu8,  /* input image */
                                  const aAlgoECInputPara_t *i_paras_t,
                                  float32_t o_iX_af32[],					/* output candidate list x coordinate */
                                  float32_t o_iY_af32[],					/* output candidate list y coordinate */
                                  uint32_t *o_CanCount_pu32,				/* output no of candidates */
                                  const float32_t i_TargetRation_f32,			/* threshold for distance ration */
                                  const sint8_t i_StartPattern_s8				/* start pattern type */
)
{
  /* DD-ID: {B23841CD-EC85-4c98-B428-4844DCD37436}*/
  uint16_t v_Number_u16 = 0U; /* no of candidates */
  sint8_t v_Errcode_s8 =  - 1;

  /* set input parameters */
  uint16_t i_ImgX_u16 = i_paras_t->cropix_u16;
  uint16_t i_ImgY_u16 = i_paras_t->cropiy_u16;
  uint8_t i_NX_u8 = i_paras_t->nx_u8;
  uint8_t i_NY_u8 = i_paras_t->ny_u8;
  sint32_t i_X_s32;
  sint32_t i_Y_s32;

  uint16_t v_NumCorners_u16 = 0U;
  uint16_t v_NumRounds_u16 = 0U;
  uint16_t v_NumLiness_u16 = 0U;
  uint16_t v_NumGrids_u16 = 0U;
  bool_t v_Break_b = 0;
  io_S_PosSub_t v_Corners_as[LTARGET_MAX_NUMBER_CORNERS];
  Corner_S_Round_t v_Rounds_as[LTARGET_MAX_NUMBER_CORNERS];
  Corner_S_Lines_t v_Lines_as[LTARGET_MAX_NUMBER_CORNERS];
  Corner_S_Grid_t v_Grids_as[LTARGET_MAX_NUMBER_CORNERS];

#ifdef ENABLE_DEBUG_OPENCV
  IplImage* iplImage;
  iplImage  = cvCreateImage(cvSize(i_ImgX_u16,i_ImgY_u16), 8, 1);
  iplImage2  = cvCreateImage(cvSize(i_ImgX_u16,i_ImgY_u16), 8, 1);

  memcpy (iplImage->imageData, i_ImgData_pu8, i_ImgX_u16*i_ImgY_u16);
  cvShowImage ("Input Image", iplImage);
  cvWaitKey(0);
#endif

  /* init data struct */
  (void)memset(&Corner_v_CornerAn_as, 0xff, sizeof(S_CornerAn_t)*LTARGET_MAX_NUMBER_CORNERS);

  /* convolute image */
  f_convImage_v (i_ImgData_pu8, i_ImgX_u16, i_ImgY_u16, Corner_v_NormImg_af32);

  /* localize corners once */
  v_NumCorners_u16 = (uint16_t)f_FindCorner_s32 (i_ImgX_u16, i_ImgY_u16, Corner_v_NormImg_af32, &v_Corners_as[0], i_NX_u8*i_NY_u8*LCORNER_MAX_CORNERNUMBERS);

  for( v_Number_u16 = i_NX_u8*i_NY_u8 ; v_Number_u16 <= v_NumCorners_u16 ; v_Number_u16+=1)
  {
    /* step out if confidence value droppes */
    if ((fabs(v_Corners_as[0].v_f32)*LCORNER_MAX_CONFIDENCE_DROP) > fabs(v_Corners_as[v_Number_u16-1].v_f32))
    {
      v_Break_b = 1;
    }
    if(0 == v_Break_b)
    {
      /* find all rounds */
      v_NumRounds_u16 = (uint16_t)f_connectRound_s32 (v_Corners_as, v_Number_u16, v_Rounds_as);

      /* find connected lines */
      v_NumLiness_u16 = (uint16_t)f_connectLine_s32 (v_Rounds_as, v_NumRounds_u16, v_Lines_as, i_NX_u8, i_TargetRation_f32);

      /* find connected grids */
      v_NumGrids_u16 = (uint16_t)f_connectGrid_u8 (v_Lines_as, v_NumLiness_u16, v_Grids_as, i_NX_u8, i_NY_u8, i_StartPattern_s8);

      if (v_NumGrids_u16 >0)
      {
        v_Break_b = 1;
      }
    }
    if(1 == v_Break_b)
    {
      break;
    }
  }

  *o_CanCount_pu32 = 0;
  if (v_NumGrids_u16 == 0)
  {
    *o_CanCount_pu32 = i_NX_u8 * i_NY_u8;
    v_Errcode_s8 = -9;
  }
  else
  {
    aSaddle_F_luccheseAll_v (i_ImgData_pu8, i_ImgX_u16, v_Grids_as[0].lines_aps[0]->rounds_aps[0]->corners_aps[0], 1);
    o_iX_af32[*o_CanCount_pu32] = v_Grids_as[0].lines_aps[0]->rounds_aps[0]->corners_aps[0]->x_f32;
    o_iY_af32[*o_CanCount_pu32] = v_Grids_as[0].lines_aps[0]->rounds_aps[0]->corners_aps[0]->y_f32;
    (*o_CanCount_pu32)++;
    for (i_X_s32=0 ; i_X_s32<(i_NX_u8-1) ; i_X_s32++)
    {
      aSaddle_F_luccheseAll_v (i_ImgData_pu8, i_ImgX_u16, v_Grids_as[0].lines_aps[0]->rounds_aps[i_X_s32]->corners_aps[1], 1);
      o_iX_af32[*o_CanCount_pu32] = v_Grids_as[0].lines_aps[0]->rounds_aps[i_X_s32]->corners_aps[1]->x_f32;
      o_iY_af32[*o_CanCount_pu32] = v_Grids_as[0].lines_aps[0]->rounds_aps[i_X_s32]->corners_aps[1]->y_f32;
      (*o_CanCount_pu32)++;
    }

    for (i_Y_s32=0 ; i_Y_s32<(i_NY_u8-1) ; i_Y_s32++)
    {
      aSaddle_F_luccheseAll_v (i_ImgData_pu8, i_ImgX_u16, v_Grids_as[0].lines_aps[i_Y_s32]->rounds_aps[0]->corners_aps[3], 1);
      o_iX_af32[*o_CanCount_pu32] = v_Grids_as[0].lines_aps[i_Y_s32]->rounds_aps[0]->corners_aps[3]->x_f32;
      o_iY_af32[*o_CanCount_pu32] = v_Grids_as[0].lines_aps[i_Y_s32]->rounds_aps[0]->corners_aps[3]->y_f32;
      (*o_CanCount_pu32)++;
      for (i_X_s32=0 ; i_X_s32<(i_NX_u8-1) ; i_X_s32++)
      {
        aSaddle_F_luccheseAll_v (i_ImgData_pu8, i_ImgX_u16, v_Grids_as[0].lines_aps[i_Y_s32]->rounds_aps[i_X_s32]->corners_aps[2], 1);
        o_iX_af32[*o_CanCount_pu32] = v_Grids_as[0].lines_aps[i_Y_s32]->rounds_aps[i_X_s32]->corners_aps[2]->x_f32;
        o_iY_af32[*o_CanCount_pu32] = v_Grids_as[0].lines_aps[i_Y_s32]->rounds_aps[i_X_s32]->corners_aps[2]->y_f32;
        (*o_CanCount_pu32)++;
      }
    }

    v_Errcode_s8 = 1;
  }

  return v_Errcode_s8;
}

/*  ---------------------------------- EOF -------------------------------------- */
