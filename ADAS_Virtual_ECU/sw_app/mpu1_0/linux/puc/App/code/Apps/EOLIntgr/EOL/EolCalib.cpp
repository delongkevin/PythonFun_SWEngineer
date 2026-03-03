
//PRQA S 1051 1
//#define ENABLE_DEBUG_OPENCV_VT
#ifdef ENABLE_DEBUG_OPENCV_VT//EOL_PC_BUILD
#include<stdio.h>
#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>

IplImage *g_TransImg_pcv, *g_RawImg_pcv;
IplImage *g_TransImg_pcv2,*TestImg_pcv;
CvPoint point1,point2,point3,point4,point5,point6,point7,point8;


#endif //MR_Modified

#include "EolTypesInternal.h"
#include <stdlib.h>
#include "vgg.h"
#include "corner.h"
#include "EolCalib.h"
#include "mecl/math/FDecompose.h"
#include "mecl/math/Math.h"

namespace eol
{

//PRQA S 1021 1 //Macro comes from c header file //roi
uint8_t TransImg_pu8[LTARGET_MAX_NORMALIZE_IMAGE];
uint8_t GlobalImg_au8[720U*480U];

EolCalib::EolCalib()
: c_EolInitData_ps(NULL)
, iSizeX_u16(IMAGE_WIDTH)
, iSizeY_u16(IMAGE_HEIGHT)
, cntOfDebugImages_u32(0U)
{
  memset(&lCaliVCalibration_s,0,sizeof(aParaMgr_S_Calibration_t));
  for(uint32_t v_I_u32 = 0U; v_I_u32 < c_MaxNumberOfDebugImages_u32; v_I_u32++)
  {
    roiImages_as[v_I_u32] = DebugScreenInfo_s();
  }
}


EolCalib::~EolCalib()
{
}

void EolCalib::f_SetRealTarget_v(T_Target_t *b_Target_pt) const
{
  /* DD-ID: {150FACD0-4A04-4183-A6A0-E60B89175DF1}*/
  if (b_Target_pt->index_s8 == 0)
  {
    b_Target_pt->real_af64[0][0] = ((static_cast<float64_t> (0 / 6)) - 1.5) * TARGET_SIZE * 25.4;
    b_Target_pt->real_af64[0][1] = ((static_cast<float64_t> (5 / 6)) - 1.5) * TARGET_SIZE * 25.4;
    b_Target_pt->real_af64[0][2] = ((static_cast<float64_t> (18 / 6)) - 1.5) * TARGET_SIZE * 25.4;
    b_Target_pt->real_af64[0][3] = ((static_cast<float64_t> (23 / 6)) - 1.5) * TARGET_SIZE * 25.4;
  }
  else if (b_Target_pt->index_s8 <= -100)
  {
    b_Target_pt->real_af64[0][0] = (-3.5 + ((static_cast<float64_t> (b_Target_pt->index_s8)) + 100.0) * 3.0) * TARGET_SIZE * 25.4;
    b_Target_pt->real_af64[0][1] = (-3.5 + ((static_cast<float64_t> (b_Target_pt->index_s8)) + 100.0) * 3.0) * TARGET_SIZE * 25.4;
    b_Target_pt->real_af64[0][2] = (-1.5 + ((static_cast<float64_t> (b_Target_pt->index_s8)) + 100.0) * 3.0) * TARGET_SIZE * 25.4;
    b_Target_pt->real_af64[0][3] = (-1.5 + ((static_cast<float64_t> (b_Target_pt->index_s8)) + 100.0) * 3.0) * TARGET_SIZE * 25.4;
  }
  else if (b_Target_pt->index_s8 >= 100)
  {
    b_Target_pt->real_af64[0][0] = (1.5 + ((static_cast<float64_t> (b_Target_pt->index_s8)) - 100.0) * 3.0) * TARGET_SIZE * 25.4;
    b_Target_pt->real_af64[0][1] = (1.5 + ((static_cast<float64_t> (b_Target_pt->index_s8)) - 100.0) * 3.0) * TARGET_SIZE * 25.4;
    b_Target_pt->real_af64[0][2] = (3.5 + ((static_cast<float64_t> (b_Target_pt->index_s8)) - 100.0) * 3.0) * TARGET_SIZE * 25.4;
    b_Target_pt->real_af64[0][3] = (3.5 + ((static_cast<float64_t> (b_Target_pt->index_s8)) - 100.0) * 3.0) * TARGET_SIZE * 25.4;
  }
  else
  {
    b_Target_pt->real_af64[0][0] = ((static_cast<float64_t> (0 / 6)) - 0.5
        + (static_cast<float64_t>(b_Target_pt->index_s8 / mecl::core::abs_x(b_Target_pt->index_s8))) * 1.0 + 3.0 * (static_cast<float64_t>(b_Target_pt->index_s8)))
                                  * TARGET_SIZE * 25.4;
    b_Target_pt->real_af64[0][1] = ((static_cast<float64_t> (5 / 6)) - 0.5
        + (static_cast<float64_t>(b_Target_pt->index_s8 / mecl::core::abs_x(b_Target_pt->index_s8))) * 1.0 + 3.0 * (static_cast<float64_t>(b_Target_pt->index_s8)))
                                  * TARGET_SIZE * 25.4;
    b_Target_pt->real_af64[0][2] = ((static_cast<float64_t> (6 / 6)) - 0.5
        + (static_cast<float64_t>(b_Target_pt->index_s8 / mecl::core::abs_x(b_Target_pt->index_s8))) * 1.0 + 3.0 * (static_cast<float64_t>(b_Target_pt->index_s8)))
                                  * TARGET_SIZE * 25.4;
    b_Target_pt->real_af64[0][3] = ((static_cast<float64_t> (11 / 6)) - 0.5
        + (static_cast<float64_t>(b_Target_pt->index_s8 / mecl::core::abs_x(b_Target_pt->index_s8))) * 1.0 + 3.0 * (static_cast<float64_t>(b_Target_pt->index_s8)))
                                  * TARGET_SIZE * 25.4;
  }

  b_Target_pt->real_af64[1][0] =  (static_cast<float64_t>(0 % 6) - 2.5) * TARGET_SIZE * 25.4
      + ((static_cast<float64_t> (b_Target_pt->side_e)) - 1.0) * static_cast<float64_t>(c_EolInitData_ps->targetSeperation_f32);
  b_Target_pt->real_af64[1][1] =  (static_cast<float64_t>(5 % 6) - 2.5) * TARGET_SIZE * 25.4
      + ((static_cast<float64_t> (b_Target_pt->side_e)) - 1.0) * static_cast<float64_t>(c_EolInitData_ps->targetSeperation_f32);
  b_Target_pt->real_af64[1][2] =  (static_cast<float64_t>(6 % 6) - 2.5) * TARGET_SIZE * 25.4
      + ((static_cast<float64_t> (b_Target_pt->side_e)) - 1.0) * static_cast<float64_t>(c_EolInitData_ps->targetSeperation_f32);
  b_Target_pt->real_af64[1][3] =  (static_cast<float64_t>(11 % 6) - 2.5) * TARGET_SIZE * 25.4
      + ((static_cast<float64_t> (b_Target_pt->side_e)) - 1.0) * static_cast<float64_t>(c_EolInitData_ps->targetSeperation_f32);

  b_Target_pt->real_af64[2][0] = 0.0;
  b_Target_pt->real_af64[2][1] = 0.0;
  b_Target_pt->real_af64[2][2] = 0.0;
  b_Target_pt->real_af64[2][3] = 0.0;

  b_Target_pt->real_af64[3][0] = 1.0;
  b_Target_pt->real_af64[3][1] = 1.0;
  b_Target_pt->real_af64[3][2] = 1.0;
  b_Target_pt->real_af64[3][3] = 1.0;
}

void EolCalib::f_TransReal2Screen_v(T_Target_t *b_Target_pt,
                                    float64_t i_Zoom_f64)
{
  /* DD-ID: {4C7BBA4C-6988-4de1-B906-FA34A108EAEA}*/
  uint8_t v_Count_u8;

  for (v_Count_u8 = 0; v_Count_u8 < 4; ++v_Count_u8)
  {
      b_Target_pt->screen_af64[0][v_Count_u8] = i_Zoom_f64 * (b_Target_pt->real_af64[1][v_Count_u8] / RATIOMM2PXX) + (static_cast<float64_t> (LOGIVIEW_OUTPUT_SIZE_X)) / 4.0;
      b_Target_pt->screen_af64[1][v_Count_u8] = i_Zoom_f64 * (b_Target_pt->real_af64[0][v_Count_u8] / RATIOMM2PXY) + (static_cast<float64_t> (LOGIVIEW_OUTPUT_SIZE_Y)) / 4.0;
      b_Target_pt->screen_af64[2][v_Count_u8] = 1.0;
  }
}

void EolCalib::f_TransReal2Cam_v(T_Target_t *b_Target_pt) const
{
  /* DD-ID: {76529466-1162-441f-B00E-F9E474FE4AAB}*/
  uint8_t v_Count_u8;
  mecl::core::Point4D<float64_t> v_RealPt4D_x;
  mecl::core::Point2D<float64_t> v_CamUpPt2D_x;
  
  for (v_Count_u8 = 0; v_Count_u8 < 4; v_Count_u8++)
  {
    v_RealPt4D_x(0) = b_Target_pt->real_af64[0][v_Count_u8];
    v_RealPt4D_x(1) = b_Target_pt->real_af64[1][v_Count_u8];
    v_RealPt4D_x(2) = b_Target_pt->real_af64[2][v_Count_u8];
    v_RealPt4D_x(3) = b_Target_pt->real_af64[3][v_Count_u8];
    c_EolInitData_ps->camera_po->applyFullProjection_v(v_RealPt4D_x,1.0,v_CamUpPt2D_x);
    b_Target_pt->cam_af64[0][v_Count_u8] = v_CamUpPt2D_x(0);
    b_Target_pt->cam_af64[1][v_Count_u8] = v_CamUpPt2D_x(1);
    b_Target_pt->cam_af64[2][v_Count_u8] = 1.0;
   
  }
}

void EolCalib::f_CalcH_v(T_Target_t *b_Target_pt)
{
  /* DD-ID: {EB1B3192-DB7F-48fa-990A-A857B754AFC8}*/
  float64_t v_Px1_af64[4];
  float64_t v_Px2_af64[4];
  float64_t v_Py1_af64[4];
  float64_t v_Py2_af64[4];

  /* apply homography estimation */
  memcpy(v_Px1_af64, &b_Target_pt->screen_af64[0][0], sizeof(float64_t) * 4);
  memcpy(v_Px2_af64, &b_Target_pt->cam_af64[0][0], sizeof(float64_t) * 4);
  memcpy(v_Py1_af64, &b_Target_pt->screen_af64[1][0], sizeof(float64_t) * 4);
  memcpy(v_Py2_af64, &b_Target_pt->cam_af64[1][0], sizeof(float64_t) * 4);

  float64_t v_H_af64[9];
  float64_t v_Hinv_af64[9];
  
  for (uint32_t v_I_u32 = 0; v_I_u32 < 9; v_I_u32++)
  {
    v_H_af64[v_I_u32] = (b_Target_pt->h_af64[v_I_u32]);
    v_Hinv_af64[v_I_u32] = (b_Target_pt->hinv_af64[v_I_u32]);
  }
  //vgg_H)from_x_lin function is from c and will be removed by mecl
  //So leave it like that
  //PRQA S 3840 1
  vggHFromXLin_s8(v_Px1_af64, v_Py1_af64, v_Px2_af64, v_Py2_af64, v_H_af64, 4);

  memcpy(v_Px1_af64, &b_Target_pt->screen_af64[0][0], sizeof(float64_t) * 4);
  memcpy(v_Px2_af64, &b_Target_pt->cam_af64[0][0], sizeof(float64_t) * 4);
  memcpy(v_Py1_af64, &b_Target_pt->screen_af64[1][0], sizeof(float64_t) * 4);
  memcpy(v_Py2_af64, &b_Target_pt->cam_af64[1][0], sizeof(float64_t) * 4);
  
  //vgg_H)from_x_lin function is from c and will be removed by mecl
  //So leave it like that
  //PRQA S 3840 1
  vggHFromXLin_s8(v_Px2_af64, v_Py2_af64, v_Px1_af64, v_Py1_af64, v_Hinv_af64, 4);
  for (uint32_t v_I_u32 = 0; v_I_u32 < 9; v_I_u32++)
  {
    b_Target_pt->h_af64[v_I_u32] = (v_H_af64[v_I_u32]);
    b_Target_pt->hinv_af64[v_I_u32] = (v_Hinv_af64[v_I_u32]);
  }
}

void EolCalib::f_CalcNominalH_v(T_Target_t *b_Target_pt) const
{
  /* DD-ID: {07A5E021-584F-4f61-B114-71F455FFC219}*/
  f_SetRealTarget_v(b_Target_pt);

  /* tranform real point coordinats into camera and screen coordinats */
  f_TransReal2Screen_v(b_Target_pt, LTARGET_DETECTION_ZOOM_FACTOR);
  f_TransReal2Cam_v(b_Target_pt);

  /* apply homography estimation */
  f_CalcH_v(b_Target_pt);
}

void EolCalib::getRoi_v(T_Target_t *b_Target_ps,
                          sint8_t i_IndexDir_s8,
                          uint16_t *o_Roi_pu16)
{
  /* DD-ID: {3C4A178F-F80D-4417-8611-D35E66E4EC6B}*/
#ifdef ENABLE_DEBUG_OPENCV
  uint8_t i;
#endif
  float64_t v_Tmp_f64;
  float64_t v_SlopeX_af64[4] = {0.0,0.0,0.0,0.0};
  float64_t v_SlopeY_af64[4] = {0.0,0.0,0.0,0.0};
  uint8_t v_M_u8 = b_Target_ps->nx_u8;
  uint8_t v_N_u8 = b_Target_ps->ny_u8;
  

  /* expand points in regular direction */
  v_Tmp_f64 =
      mecl::math::max_x<float64_t>(b_Target_ps->screen_af64[0][1]-b_Target_ps->screen_af64[0][0], b_Target_ps->screen_af64[0][3]-b_Target_ps->screen_af64[0][2]) / (static_cast<float64_t>(v_M_u8)
          - 1.0);

  switch (i_IndexDir_s8)
  {
    case 0:
    {
      uint8_t v_GFactorSidesInit_au8[4] = {0,0,0,0};
	  if (b_Target_ps->camId_e == e_LeftCamAlgo)
      {
        v_GFactorSidesInit_au8[0] = 5;//4;
        v_GFactorSidesInit_au8[1] = 2;
        v_GFactorSidesInit_au8[2] = 4;//3;
        v_GFactorSidesInit_au8[3] = 3;
      }
      else if (b_Target_ps->camId_e == e_RightCamAlgo)
      {
        v_GFactorSidesInit_au8[0] = 2;
        v_GFactorSidesInit_au8[1] = 5;//4;
        v_GFactorSidesInit_au8[2] = 4;//3;
        v_GFactorSidesInit_au8[3] = 3;
      }
      else if (b_Target_ps->camId_e == e_FrontCamAlgo)
      {
        if (b_Target_ps->side_e == e_TargetLeft)
        {
          v_GFactorSidesInit_au8[0] = 5;
          v_GFactorSidesInit_au8[1] = 3;
          v_GFactorSidesInit_au8[2] = 2;
          v_GFactorSidesInit_au8[3] = 1;
        }
        else if (b_Target_ps->side_e == e_TargetRight)
        {
          v_GFactorSidesInit_au8[0] = 3;
          v_GFactorSidesInit_au8[1] = 5;
          v_GFactorSidesInit_au8[2] = 2;
          v_GFactorSidesInit_au8[3] = 1;
        }
		else
		{
		}

        if (mecl::core::abs_x(b_Target_ps->index_s8) < 100)
        {
          v_GFactorSidesInit_au8[2] *= 2;
          v_GFactorSidesInit_au8[3] *= 2;
        }
      }
      else if (b_Target_ps->camId_e == e_RearCamAlgo)
      {
        if (b_Target_ps->side_e == e_TargetLeft)
        {
          v_GFactorSidesInit_au8[0] = 6;
          v_GFactorSidesInit_au8[1] = 3;
          v_GFactorSidesInit_au8[2] = 1;
          v_GFactorSidesInit_au8[3] = 2;
        }
        else if (b_Target_ps->side_e == e_TargetRight)
        {
          v_GFactorSidesInit_au8[0] = 3;
          v_GFactorSidesInit_au8[1] = 6;
          v_GFactorSidesInit_au8[2] = 1;
          v_GFactorSidesInit_au8[3] = 2;
        }
		else
		{
		}
		
        if (mecl::core::abs_x(b_Target_ps->index_s8) < 100)
        {
          v_GFactorSidesInit_au8[2] *= 2;
          v_GFactorSidesInit_au8[3] *= 2;
        }
      }
      else
      {
      }
      v_SlopeX_af64[0] = b_Target_ps->screen_af64[0][0]
          + (static_cast <float64_t> (v_GFactorSidesInit_au8[0])) * (-1.0 * (b_Target_ps->screen_af64[0][1] - b_Target_ps->screen_af64[0][0]) / ((static_cast <float64_t> (v_M_u8)) - 1.0));
      v_SlopeX_af64[1] = b_Target_ps->screen_af64[0][1]
          + (static_cast <float64_t> (v_GFactorSidesInit_au8[1])) * (-1.0 * (b_Target_ps->screen_af64[0][3] - b_Target_ps->screen_af64[0][2]) / ((static_cast <float64_t> (v_M_u8)) - 1.0));
      v_SlopeX_af64[2] = b_Target_ps->screen_af64[0][2]
          + (static_cast <float64_t> (v_GFactorSidesInit_au8[0])) * (+1.0 * (b_Target_ps->screen_af64[0][1] - b_Target_ps->screen_af64[0][0]) / ((static_cast <float64_t> (v_M_u8)) - 1.0));
      v_SlopeX_af64[3] = b_Target_ps->screen_af64[0][3]
          + (static_cast <float64_t> (v_GFactorSidesInit_au8[1])) * (+1.0 * (b_Target_ps->screen_af64[0][3] - b_Target_ps->screen_af64[0][2]) / ((static_cast <float64_t> (v_M_u8)) - 1.0));
      v_SlopeY_af64[0] = b_Target_ps->screen_af64[1][0]
          + (static_cast <float64_t> (v_GFactorSidesInit_au8[2])) * (-1.0 * (b_Target_ps->screen_af64[1][2] - b_Target_ps->screen_af64[1][0]) / ((static_cast <float64_t> (v_N_u8)) - 1.0));
      v_SlopeY_af64[1] = b_Target_ps->screen_af64[1][1]
          + (static_cast <float64_t> (v_GFactorSidesInit_au8[2])) * (-1.0 * (b_Target_ps->screen_af64[1][3] - b_Target_ps->screen_af64[1][1]) / ((static_cast <float64_t> (v_N_u8)) - 1.0));
      v_SlopeY_af64[2] = b_Target_ps->screen_af64[1][2]
          + (static_cast <float64_t> (v_GFactorSidesInit_au8[3])) * (+1.0 * (b_Target_ps->screen_af64[1][2] - b_Target_ps->screen_af64[1][0]) / ((static_cast <float64_t> (v_N_u8)) - 1.0));
      v_SlopeY_af64[3] = b_Target_ps->screen_af64[1][3]
          + (static_cast <float64_t> (v_GFactorSidesInit_au8[3])) * (+1.0 * (b_Target_ps->screen_af64[1][3] - b_Target_ps->screen_af64[1][1]) / ((static_cast <float64_t> (v_N_u8)) - 1.0));
      break;
	}
    case 1:
	{
#ifdef ENABLE_DEBUG_OPENCV
      for (i=0; i<4; ++i)
      cvDrawCircle (g_TransImg_pcv, cvPoint((int)b_Target_ps->screen_af64[0][i], (int)b_Target_ps->screen_af64[1][i]), 2, cvScalar(255,0,0,0), 2, 8, 0);
      cvNamedWindow("Target Find", CV_WINDOW_NORMAL);
      cvShowImage("Target Find", g_TransImg_pcv);
      cvWaitKey (OPENCV_WAITIME);
#endif
      v_SlopeX_af64[2] = b_Target_ps->screen_af64[0][0] - v_Tmp_f64;
      v_SlopeX_af64[3] = b_Target_ps->screen_af64[0][1] + v_Tmp_f64;
      v_SlopeX_af64[0] = b_Target_ps->screen_af64[0][0] - v_Tmp_f64;
      v_SlopeX_af64[1] = b_Target_ps->screen_af64[0][1] + v_Tmp_f64;
      if (b_Target_ps->index_s8 >= 100)
      {
        v_SlopeY_af64[0] = ((b_Target_ps->screen_af64[1][2]))
            - 0.5 * (b_Target_ps->screen_af64[1][2] - b_Target_ps->screen_af64[1][0]) / (static_cast <float64_t> (v_N_u8) - 1.0);
        v_SlopeY_af64[1] = ((b_Target_ps->screen_af64[1][3]))
            - 0.5 * (b_Target_ps->screen_af64[1][3] - b_Target_ps->screen_af64[1][1]) / (static_cast <float64_t> (v_N_u8) - 1.0);
        v_SlopeY_af64[2] = ((b_Target_ps->screen_af64[1][2]))
            + 1.0 * (b_Target_ps->screen_af64[1][2] - b_Target_ps->screen_af64[1][0]) / (static_cast <float64_t> (v_N_u8) - 1.0);
        v_SlopeY_af64[3] = ((b_Target_ps->screen_af64[1][3]))
            + 1.0 * (b_Target_ps->screen_af64[1][3] - b_Target_ps->screen_af64[1][1]) / (static_cast <float64_t> (v_N_u8) - 1.0);
        b_Target_ps->index_s8 += 1 - 100;
      }
      else if (b_Target_ps->index_s8 <= -100)
      {
        v_SlopeY_af64[0] = ((b_Target_ps->screen_af64[1][2]))
            - 0.5 * (b_Target_ps->screen_af64[1][2] - b_Target_ps->screen_af64[1][0]) / (static_cast <float64_t> (v_N_u8) - 1.0);
        v_SlopeY_af64[1] = ((b_Target_ps->screen_af64[1][3]))
            - 0.5 * (b_Target_ps->screen_af64[1][3] - b_Target_ps->screen_af64[1][1]) / (static_cast <float64_t> (v_N_u8) - 1.0);
        v_SlopeY_af64[2] = ((b_Target_ps->screen_af64[1][2]))
            + 1.0 * (b_Target_ps->screen_af64[1][2] - b_Target_ps->screen_af64[1][0]) / (static_cast <float64_t> (v_N_u8) - 1.0);
        v_SlopeY_af64[3] = ((b_Target_ps->screen_af64[1][3]))
            + 1.0 * (b_Target_ps->screen_af64[1][3] - b_Target_ps->screen_af64[1][1]) / (static_cast <float64_t> (v_N_u8) - 1.0);
        b_Target_ps->index_s8 += 100;
      }
      else
      {
        v_SlopeY_af64[0] = ((b_Target_ps->screen_af64[1][2]))
            + 1.0 * (b_Target_ps->screen_af64[1][2] - b_Target_ps->screen_af64[1][0]) / (static_cast <float64_t> (v_N_u8) - 1.0);
        v_SlopeY_af64[1] = ((b_Target_ps->screen_af64[1][3]))
            + 1.0 * (b_Target_ps->screen_af64[1][3] - b_Target_ps->screen_af64[1][1]) / (static_cast <float64_t> (v_N_u8) - 1.0);
        v_SlopeY_af64[2] = ((b_Target_ps->screen_af64[1][2]))
            + 4.0 * (b_Target_ps->screen_af64[1][2] - b_Target_ps->screen_af64[1][0]) / (static_cast <float64_t> (v_N_u8) - 1.0);
        v_SlopeY_af64[3] = ((b_Target_ps->screen_af64[1][3]))
            + 4.0 * (b_Target_ps->screen_af64[1][3] - b_Target_ps->screen_af64[1][1]) / (static_cast <float64_t> (v_N_u8) - 1.0);
        b_Target_ps->index_s8 += i_IndexDir_s8;
      }

      b_Target_ps->nx_u8 = 6;
      b_Target_ps->ny_u8 = 2;
      break;
	}
	  //new case 
	case 2:		
	{	
		v_SlopeX_af64[2] = b_Target_ps->screen_af64[0][0] - v_Tmp_f64;
		v_SlopeX_af64[3] = b_Target_ps->screen_af64[0][1] + v_Tmp_f64;
		v_SlopeX_af64[0] = b_Target_ps->screen_af64[0][0] - v_Tmp_f64;
		v_SlopeX_af64[1] = b_Target_ps->screen_af64[0][1] + v_Tmp_f64;

		v_SlopeY_af64[0] = ((b_Target_ps->screen_af64[1][2])) + 4.0 * (b_Target_ps->screen_af64[1][2]-b_Target_ps->screen_af64[1][0]) / (static_cast <float64_t>(v_N_u8)-1.0);
		v_SlopeY_af64[1] = ((b_Target_ps->screen_af64[1][3])) + 4.0 * (b_Target_ps->screen_af64[1][3]-b_Target_ps->screen_af64[1][1]) / (static_cast <float64_t>(v_N_u8)-1.0);
		v_SlopeY_af64[2] = ((b_Target_ps->screen_af64[1][2])) + 7.0 * (b_Target_ps->screen_af64[1][2]-b_Target_ps->screen_af64[1][0]) / (static_cast <float64_t>(v_N_u8)-1.0);
		v_SlopeY_af64[3] = ((b_Target_ps->screen_af64[1][3])) + 7.0 * (b_Target_ps->screen_af64[1][3]-b_Target_ps->screen_af64[1][1]) / (static_cast <float64_t>(v_N_u8)-1.0);
		b_Target_ps->index_s8 += i_IndexDir_s8;
		break;
	}


    case -1:
	{
#ifdef ENABLE_DEBUG_OPENCV
      for (i=0; i<4; ++i)
      cvDrawCircle (g_TransImg_pcv, cvPoint((int)b_Target_ps->screen_af64[0][i], (int)b_Target_ps->screen_af64[1][i]), 2, cvScalar(255,0,0,0), 2, 8, 0);
      cvNamedWindow("Target Find", CV_WINDOW_NORMAL);
      cvShowImage("Target Find", g_TransImg_pcv);
      cvWaitKey (OPENCV_WAITIME);
#endif
      v_SlopeX_af64[0] = b_Target_ps->screen_af64[0][0] - v_Tmp_f64;
      v_SlopeX_af64[1] = b_Target_ps->screen_af64[0][1] + v_Tmp_f64;
      v_SlopeX_af64[2] = b_Target_ps->screen_af64[0][0] - v_Tmp_f64;
      v_SlopeX_af64[3] = b_Target_ps->screen_af64[0][1] + v_Tmp_f64;
      if (b_Target_ps->index_s8 >= 100)
      {
        v_SlopeY_af64[0] = ((b_Target_ps->screen_af64[1][0]))
            - 1.0 * (b_Target_ps->screen_af64[1][2] - b_Target_ps->screen_af64[1][0]) / (static_cast <float64_t>(v_N_u8)-1.0);
        v_SlopeY_af64[1] = ((b_Target_ps->screen_af64[1][1]))
            - 1.0 * (b_Target_ps->screen_af64[1][3] - b_Target_ps->screen_af64[1][1]) / (static_cast <float64_t>(v_N_u8)-1.0);
        v_SlopeY_af64[2] = ((b_Target_ps->screen_af64[1][0]))
            + 0.5 * (b_Target_ps->screen_af64[1][2] - b_Target_ps->screen_af64[1][0]) / (static_cast <float64_t>(v_N_u8)-1.0);
        v_SlopeY_af64[3] = ((b_Target_ps->screen_af64[1][1]))
            + 0.5 * (b_Target_ps->screen_af64[1][3] - b_Target_ps->screen_af64[1][1]) / (static_cast <float64_t>(v_N_u8)-1.0);
        b_Target_ps->index_s8 -= 100;
      }
      else if (b_Target_ps->index_s8 <= -100)
      {
        v_SlopeY_af64[0] = ((b_Target_ps->screen_af64[1][0]))
            - 1.0 * (b_Target_ps->screen_af64[1][2] - b_Target_ps->screen_af64[1][0]) / (static_cast <float64_t>(v_N_u8)-1.0);
        v_SlopeY_af64[1] = ((b_Target_ps->screen_af64[1][1]))
            - 1.0 * (b_Target_ps->screen_af64[1][3] - b_Target_ps->screen_af64[1][1]) / (static_cast <float64_t>(v_N_u8)-1.0);
        v_SlopeY_af64[2] = ((b_Target_ps->screen_af64[1][0]))
            + 0.5 * (b_Target_ps->screen_af64[1][2] - b_Target_ps->screen_af64[1][0]) / (static_cast <float64_t>(v_N_u8)-1.0);
        v_SlopeY_af64[3] = ((b_Target_ps->screen_af64[1][1]))
            + 0.5 * (b_Target_ps->screen_af64[1][3] - b_Target_ps->screen_af64[1][1]) / (static_cast <float64_t>(v_N_u8)-1.0);
        b_Target_ps->index_s8 += 100 + i_IndexDir_s8;
      }
      else
      {
        v_SlopeY_af64[0] = ((b_Target_ps->screen_af64[1][0]))
            - 4.0 * (b_Target_ps->screen_af64[1][2] - b_Target_ps->screen_af64[1][0]) / (static_cast <float64_t>(v_N_u8)-1.0);
        v_SlopeY_af64[1] = ((b_Target_ps->screen_af64[1][1]))
            - 4.0 * (b_Target_ps->screen_af64[1][3] - b_Target_ps->screen_af64[1][1]) / (static_cast <float64_t>(v_N_u8)-1.0);
        v_SlopeY_af64[2] = ((b_Target_ps->screen_af64[1][0]))
            - 1.0 * (b_Target_ps->screen_af64[1][2] - b_Target_ps->screen_af64[1][0]) / (static_cast <float64_t>(v_N_u8)-1.0);
        v_SlopeY_af64[3] = ((b_Target_ps->screen_af64[1][1]))
            - 1.0 * (b_Target_ps->screen_af64[1][3] - b_Target_ps->screen_af64[1][1]) / (static_cast <float64_t>(v_N_u8)-1.0);
        b_Target_ps->index_s8 += i_IndexDir_s8;
      }

      b_Target_ps->nx_u8 = 6;
      b_Target_ps->ny_u8 = 2;
      break;
	}
	case -2:	
	{
		v_SlopeX_af64[0] = b_Target_ps->screen_af64[0][0] - v_Tmp_f64;
		v_SlopeX_af64[1] = b_Target_ps->screen_af64[0][1] + v_Tmp_f64;
		v_SlopeX_af64[2] = b_Target_ps->screen_af64[0][0] - v_Tmp_f64;
		v_SlopeX_af64[3] = b_Target_ps->screen_af64[0][1] + v_Tmp_f64;
				
		v_SlopeY_af64[0] = ((b_Target_ps->screen_af64[1][0])) - 7.0 * (b_Target_ps->screen_af64[1][2]-b_Target_ps->screen_af64[1][0]) / (static_cast <float64_t>(v_N_u8)-1.0);
		v_SlopeY_af64[1] = ((b_Target_ps->screen_af64[1][1])) - 7.0 * (b_Target_ps->screen_af64[1][3]-b_Target_ps->screen_af64[1][1]) / (static_cast <float64_t>(v_N_u8)-1.0);
		v_SlopeY_af64[2] = ((b_Target_ps->screen_af64[1][0])) - 4.0 * (b_Target_ps->screen_af64[1][2]-b_Target_ps->screen_af64[1][0]) / (static_cast <float64_t>(v_N_u8)-1.0);
		v_SlopeY_af64[3] = ((b_Target_ps->screen_af64[1][1])) - 4.0 * (b_Target_ps->screen_af64[1][3]-b_Target_ps->screen_af64[1][1]) / (static_cast <float64_t>(v_N_u8)-1.0);
		b_Target_ps->index_s8 += i_IndexDir_s8;
		break;
	}
	default:
		{break;}
  }
  //PRQA S 3706 4
   o_Roi_pu16[0] = static_cast<uint16_t> (mecl::math::max_x<float64_t>(0.0, mecl::math::min_x<float64_t> (v_SlopeX_af64[0], v_SlopeX_af64[2])));
   o_Roi_pu16[1] = static_cast<uint16_t> (mecl::math::min_x<float64_t>((static_cast<float64_t>(LOGIVIEW_OUTPUT_SIZE_X))-1.0, mecl::math::max_x<float64_t> (v_SlopeX_af64[1], v_SlopeX_af64[3])));
   o_Roi_pu16[2] = static_cast<uint16_t> (mecl::math::max_x<float64_t>(0.0, mecl::math::min_x<float64_t> (v_SlopeY_af64[0], v_SlopeY_af64[1])));
   o_Roi_pu16[3] = static_cast<uint16_t> (mecl::math::min_x<float64_t>((static_cast<float64_t>(LOGIVIEW_OUTPUT_SIZE_X))-1.0, mecl::math::max_x<float64_t> (v_SlopeY_af64[2], v_SlopeY_af64[3])));

#ifdef ENABLE_DEBUG_OPENCV
  for (i=0; i<4; ++i)
  cvDrawCircle (g_TransImg_pcv, cvPoint((int)b_Target_ps->screen_af64[0][i], (int)b_Target_ps->screen_af64[1][i]), 2, cvScalar(0,0,255,0), 2, 8, 0);

  cvDrawCircle (g_TransImg_pcv, cvPoint((int)o_Roi_pu16[0], (int)o_Roi_pu16[2]), 2, cvScalar(0,255,0,0), 2, 8, 0);
  cvDrawCircle (g_TransImg_pcv, cvPoint((int)o_Roi_pu16[1], (int)o_Roi_pu16[3]), 2, cvScalar(0,255,0,0), 2, 8, 0);

  cvNamedWindow("Target Find", CV_WINDOW_NORMAL);
  cvShowImage("Target Find", g_TransImg_pcv);
  cvWaitKey (OPENCV_WAITIME);
#endif
}

void EolCalib::f_TransScreen2Cam_v(T_Target_t *b_Target_pt)
{
  /* DD-ID: {D7DF1D0F-FF32-40f4-BB56-A3E6556EF0F6}*/
  uint8_t v_Count_u8;
  uint8_t v_InnerCount_u8;
  mecl::core::Matrix<float64_t, 3, 4>::Config_s v_CamF64Cfg_s;
  mecl::core::Matrix<float64_t, 3, 4> v_Screen_x;
  mecl::core::Matrix<float64_t, 3, 4> v_Cam_x;
  mecl::core::Matrix<float64_t, 3, 3> v_H_x;

  for (v_Count_u8 = 0; v_Count_u8 < 9; v_Count_u8++)
  {
    v_H_x(v_Count_u8) = b_Target_pt->h_af64[v_Count_u8];
  }

  for (v_Count_u8 = 0; v_Count_u8 < 3; v_Count_u8++)
  {
    for (v_InnerCount_u8 = 0; v_InnerCount_u8 < 4; v_InnerCount_u8++)
    {
      v_Screen_x(v_Count_u8, v_InnerCount_u8) = b_Target_pt->screen_af64[v_Count_u8][v_InnerCount_u8];
    }
  }

  v_Cam_x = v_H_x % v_Screen_x; //hongtao
  v_Cam_x.copyConfig_v(v_CamF64Cfg_s);
  /* transfer screen point into camera domain */
  for (v_Count_u8 = 0; v_Count_u8 < 4; ++v_Count_u8)
  {
    b_Target_pt->cam_af64[0][v_Count_u8] = v_CamF64Cfg_s.cVal_ax[v_Count_u8] / v_CamF64Cfg_s.cVal_ax[v_Count_u8 + 8];
    b_Target_pt->cam_af64[1][v_Count_u8] = v_CamF64Cfg_s.cVal_ax[v_Count_u8 + 4] / v_CamF64Cfg_s.cVal_ax[v_Count_u8 + 8];
    b_Target_pt->cam_af64[2][v_Count_u8] = 1.0;
  }
}

sint8_t EolCalib::f_FindSubTarget_s8(T_Target_t const *i_TargetInit_ps,
                                     T_Target_t *b_TargetNext_pt,
                                     sint8_t i_Dir_s8)
{
  /* DD-ID: {89794F22-A85F-4eba-B66C-C44107126C0E}*/
  uint16_t v_Roi_au16[4];
  aAlgoECInputPara_t v_AlgoConfig_t;
  sint8_t v_StartPattern_s8;
  float32_t v_CornerRatio_f32;

  uint32_t 	v_CornerCnt_u32;
  float32_t v_CornerX_af32[100];
  float32_t v_CornerY_af32[100];
  
  sint32_t Flag = 0U;

  memcpy(b_TargetNext_pt, i_TargetInit_ps, sizeof(T_Target_t));

  /* configure algo */
  memset(&v_AlgoConfig_t, 0, sizeof(aAlgoECInputPara_t));
  if ((mecl::core::abs_x(b_TargetNext_pt->index_s8) >= 100) && (i_Dir_s8 == 0))
  {
    v_StartPattern_s8 = -1;
    v_CornerRatio_f32 = 2.0F;
  }
  else
  {
    v_StartPattern_s8 = 1;
    v_CornerRatio_f32 = 1.0F;
  }

  /* prepare roi and image data */
  getRoi_v(b_TargetNext_pt, i_Dir_s8, &v_Roi_au16[0]);

  
  /* prepare roi image data */
  f_ViewTrans(&v_Roi_au16[0], c_EolInitData_ps->c_Image_pu8, &v_AlgoConfig_t.cropix_u16, &v_AlgoConfig_t.cropiy_u16, &(i_TargetInit_ps->h_af64[0]), IMAGE_WIDTH,
      IMAGE_HEIGHT); //homography maybe wrong hongtao
  

#if 0
  vm_cprintf("\n\n\n\nAlgoConfig_t.cropix_u16 %u, AlgoConfig_t.cropiy_u16 %u\n\n",v_AlgoConfig_t.cropix_u16, v_AlgoConfig_t.cropiy_u16);
  log_printf("** TransImg_pu8 %p\n", TransImg_pu8);
  for (uint32_t i = 0x0U; i < static_cast<uint32_t>(v_AlgoConfig_t.cropix_u16*v_AlgoConfig_t.cropiy_u16); ++i)
  {
    // PRQA S 3706 1 //Just printf with offset to pointer.
    vm_cprintf("%d,", static_cast<sint32_t>(c_EolInitData_ps->c_Image_pu8[i]));
  }
  vm_cprintf("\n");
#endif
  /* Run corner detector */
  v_AlgoConfig_t.nx_u8 = b_TargetNext_pt->nx_u8;
  v_AlgoConfig_t.ny_u8 = b_TargetNext_pt->ny_u8;
  if (0 > aCorner_F_mainDetector_s8(&TransImg_pu8[0], &v_AlgoConfig_t, &v_CornerX_af32[0], &v_CornerY_af32[0], &v_CornerCnt_u32,
                                    v_CornerRatio_f32, v_StartPattern_s8))
    {Flag = Flag -1U;}
	
  if(Flag == 0U)
  {
  uint32_t v_I_u32;
  uint32_t v_J_u32;

  /*screen debug info*/
  
  roiImages_as[cntOfDebugImages_u32].patternId_s32 = b_TargetNext_pt->index_s8;
  roiImages_as[cntOfDebugImages_u32].imgSide_e = b_TargetNext_pt->side_e;
  roiImages_as[cntOfDebugImages_u32].imageSizeX_u32 = v_Roi_au16[1] - v_Roi_au16[0] + 1;
  roiImages_as[cntOfDebugImages_u32].imageSizeY_u32 = v_Roi_au16[3] - v_Roi_au16[2] + 1;

  (roiImages_as[cntOfDebugImages_u32].corners_ao[0])(0) = v_CornerX_af32[0];
  (roiImages_as[cntOfDebugImages_u32].corners_ao[0])(1) = v_CornerY_af32[0];
  (roiImages_as[cntOfDebugImages_u32].corners_ao[1])(0) = v_CornerX_af32[5];
  (roiImages_as[cntOfDebugImages_u32].corners_ao[1])(1) = v_CornerY_af32[5];
  (roiImages_as[cntOfDebugImages_u32].corners_ao[2])(0) = v_CornerX_af32[v_CornerCnt_u32-6];
  (roiImages_as[cntOfDebugImages_u32].corners_ao[2])(1) = v_CornerY_af32[v_CornerCnt_u32-6];
  (roiImages_as[cntOfDebugImages_u32].corners_ao[3])(0) = v_CornerX_af32[v_CornerCnt_u32-1];
  (roiImages_as[cntOfDebugImages_u32].corners_ao[3])(1) = v_CornerY_af32[v_CornerCnt_u32-1];

  if(cntOfDebugImages_u32==0U)
  {
	  roiImages_as[cntOfDebugImages_u32].arrayIndex_u32 = 0U;
  }
  else
  {
	  roiImages_as[cntOfDebugImages_u32].arrayIndex_u32 = roiImages_as[cntOfDebugImages_u32-1].arrayIndex_u32 + (roiImages_as[cntOfDebugImages_u32-1].imageSizeX_u32)*(roiImages_as[cntOfDebugImages_u32-1].imageSizeY_u32);
  }

  for (v_I_u32 = 0; v_I_u32 < (v_Roi_au16[3]-v_Roi_au16[2]+1U); v_I_u32++)
  {
    for (v_J_u32 = 0; v_J_u32 < (v_Roi_au16[1]-v_Roi_au16[0]+1U); v_J_u32++)
    {
      memcpy(&GlobalImg_au8[roiImages_as[cntOfDebugImages_u32].arrayIndex_u32+v_I_u32*((v_Roi_au16[1]-v_Roi_au16[0]+1))+v_J_u32], &TransImg_pu8[v_I_u32*((v_Roi_au16[1]-v_Roi_au16[0]+1))+v_J_u32], 1);
    }
  }

  cntOfDebugImages_u32++;
  /*screen debug info end*/

  /* bring indexes from roi space into global image space */
  for (v_I_u32 = 0; v_I_u32 < v_CornerCnt_u32; ++v_I_u32)
  {
    v_CornerX_af32[v_I_u32] += static_cast<float32_t> (v_Roi_au16[0]);
    v_CornerY_af32[v_I_u32] += static_cast<float32_t> (v_Roi_au16[2]);
  }

#ifdef ENABLE_DEBUG_OPENCV
  cvDrawLine (g_TransImg_pcv, cvPoint(v_Roi_au16[0], v_Roi_au16[2]), cvPoint(v_Roi_au16[1], v_Roi_au16[2]), cvScalar(0,0,255,0), 2, 8, 0);
  cvDrawLine (g_TransImg_pcv, cvPoint(v_Roi_au16[1], v_Roi_au16[2]), cvPoint(v_Roi_au16[1], v_Roi_au16[3]), cvScalar(0,0,255,0), 2, 8, 0);
  cvDrawLine (g_TransImg_pcv, cvPoint(v_Roi_au16[1], v_Roi_au16[3]), cvPoint(v_Roi_au16[0], v_Roi_au16[3]), cvScalar(0,0,255,0), 2, 8, 0);
  cvDrawLine (g_TransImg_pcv, cvPoint(v_Roi_au16[0], v_Roi_au16[3]), cvPoint(v_Roi_au16[0], v_Roi_au16[2]), cvScalar(0,0,255,0), 2, 8, 0);

  for (v_I_u32=0; v_I_u32<v_CornerCnt_u32; ++v_I_u32)
  cvDrawCircle (g_TransImg_pcv, cvPoint((int)v_CornerX_af32[v_I_u32], (int)v_CornerY_af32[v_I_u32]), 2, cvScalar(0,0,255,0), 2, 8, 0);
  cvNamedWindow("Target Find", CV_WINDOW_NORMAL);
  cvShowImage("Target Find", g_TransImg_pcv);
  cvWaitKey (OPENCV_WAITIME);
#endif

  /* reduce to extrem corners */
  b_TargetNext_pt->screen_af64[0][2] = static_cast<float64_t>(v_CornerX_af32[0]);
  b_TargetNext_pt->screen_af64[1][2] = static_cast<float64_t>(v_CornerY_af32[0]);
  b_TargetNext_pt->screen_af64[0][3] = static_cast<float64_t>(v_CornerX_af32[b_TargetNext_pt->nx_u8 - 1]);
  b_TargetNext_pt->screen_af64[1][3] = static_cast<float64_t>(v_CornerY_af32[b_TargetNext_pt->nx_u8 - 1]);
  b_TargetNext_pt->screen_af64[0][0] = static_cast<float64_t>(v_CornerX_af32[b_TargetNext_pt->nx_u8 * (b_TargetNext_pt->ny_u8 - 1)]);
  b_TargetNext_pt->screen_af64[1][0] = static_cast<float64_t>(v_CornerY_af32[b_TargetNext_pt->nx_u8 * (b_TargetNext_pt->ny_u8 - 1)]);
  b_TargetNext_pt->screen_af64[0][1] = static_cast<float64_t>(v_CornerX_af32[b_TargetNext_pt->nx_u8 * b_TargetNext_pt->ny_u8 - 1]);
  b_TargetNext_pt->screen_af64[1][1] = static_cast<float64_t>(v_CornerY_af32[b_TargetNext_pt->nx_u8 * b_TargetNext_pt->ny_u8 - 1]);

  /* transfer detected screen points into camera domain */
  
  f_TransScreen2Cam_v(b_TargetNext_pt);
  f_SetRealTarget_v(b_TargetNext_pt);
  }
  
  return Flag;
}

sint8_t EolCalib::f_FindInitTarget_s8(T_Target_t *b_Target_pt)
{
  /* DD-ID: {96BD4316-07B2-4a83-979D-BDB3EC4E75B7}*/
  sint32_t  Flag = 0U;

  f_SetRealTarget_v(b_Target_pt);

  /* tranform real point coordinats into camera and screen coordinats */
  f_TransReal2Screen_v(b_Target_pt, LTARGET_DETECTION_ZOOM_FACTOR);

  /* find sub target */
  if (0 > f_FindSubTarget_s8(b_Target_pt, b_Target_pt, 0))
   { Flag = Flag -1U;}

  if(Flag == 0U) 
  {
	float64_t v_Px1_af64[4];
	float64_t v_Px2_af64[4];
	float64_t v_Py1_af64[4];
	float64_t v_Py2_af64[4];
	f_TransReal2Screen_v(b_Target_pt, LTARGET_DETECTION_ZOOM_FACTOR);

	/* apply homography estimation */
	memcpy(v_Px1_af64, &b_Target_pt->screen_af64[0][0], sizeof(float64_t) * 4);
	memcpy(v_Px2_af64, &b_Target_pt->cam_af64[0][0], sizeof(float64_t) * 4);
	memcpy(v_Py1_af64, &b_Target_pt->screen_af64[1][0], sizeof(float64_t) * 4);
	memcpy(v_Py2_af64, &b_Target_pt->cam_af64[1][0], sizeof(float64_t) * 4);

	float64_t v_H_af64[9];
	float64_t v_Hinv_af64[9];
	for (uint32_t v_I_u32 = 0; v_I_u32 < 9; v_I_u32++)
	{
	  v_H_af64[v_I_u32] = (b_Target_pt->h_af64[v_I_u32]);
	  v_Hinv_af64[v_I_u32] = (b_Target_pt->hinv_af64[v_I_u32]);
	}
	//vgg_H)from_x_lin function is from c and will be removed by mecl
	//So leave it like that
	//PRQA S 3840 2
	vggHFromXLin_s8(v_Px1_af64, v_Py1_af64, v_Px2_af64, v_Py2_af64, v_H_af64, 4);
	vggHFromXLin_s8(v_Px2_af64, v_Py2_af64, v_Px1_af64, v_Py1_af64, v_Hinv_af64, 4);

	for (uint32_t v_I_u32 = 0; v_I_u32 < 9; v_I_u32++)
	{
	  b_Target_pt->h_af64[v_I_u32] = (v_H_af64[v_I_u32]);
	  b_Target_pt->hinv_af64[v_I_u32] = (v_Hinv_af64[v_I_u32]);
	}
  }
  return Flag;
}

void EolCalib::f_MergeTargets_v(T_Target_t *b_TargetFL_ps,
                                T_Target_t *b_TargetFR_ps,
                                T_Target_t *b_TargetRL_ps,
                                T_Target_t *b_TargetRR_ps,
                                float64_t i_Zoom_f64,
                                T_Target_t *o_Target_pt)
{
  /* DD-ID: {41567F37-EEAE-4f40-850A-1D906F8BA517}*/
  f_TransReal2Screen_v(b_TargetFL_ps, i_Zoom_f64);
  f_TransReal2Screen_v(b_TargetRL_ps, i_Zoom_f64);
  f_TransReal2Screen_v(b_TargetFR_ps, i_Zoom_f64);
  f_TransReal2Screen_v(b_TargetRR_ps, i_Zoom_f64);
  
  o_Target_pt->camId_e = b_TargetFL_ps->camId_e;

  o_Target_pt->cam_af64[0][0] = b_TargetFL_ps->cam_af64[0][0];
  o_Target_pt->cam_af64[0][1] = b_TargetFR_ps->cam_af64[0][1];
  o_Target_pt->cam_af64[0][2] = b_TargetRL_ps->cam_af64[0][2];
  o_Target_pt->cam_af64[0][3] = b_TargetRR_ps->cam_af64[0][3];

  o_Target_pt->cam_af64[1][0] = b_TargetFL_ps->cam_af64[1][0];
  o_Target_pt->cam_af64[1][1] = b_TargetFR_ps->cam_af64[1][1];
  o_Target_pt->cam_af64[1][2] = b_TargetRL_ps->cam_af64[1][2];
  o_Target_pt->cam_af64[1][3] = b_TargetRR_ps->cam_af64[1][3];

  o_Target_pt->cam_af64[2][0] = 1.0;
  o_Target_pt->cam_af64[2][1] = 1.0;
  o_Target_pt->cam_af64[2][2] = 1.0;
  o_Target_pt->cam_af64[2][3] = 1.0;

  o_Target_pt->screen_af64[0][0] = b_TargetFL_ps->screen_af64[0][0];
  o_Target_pt->screen_af64[0][1] = b_TargetFR_ps->screen_af64[0][1];
  o_Target_pt->screen_af64[0][2] = b_TargetRL_ps->screen_af64[0][2];
  o_Target_pt->screen_af64[0][3] = b_TargetRR_ps->screen_af64[0][3];

  o_Target_pt->screen_af64[1][0] = b_TargetFL_ps->screen_af64[1][0];
  o_Target_pt->screen_af64[1][1] = b_TargetFR_ps->screen_af64[1][1];
  o_Target_pt->screen_af64[1][2] = b_TargetRL_ps->screen_af64[1][2];
  o_Target_pt->screen_af64[1][3] = b_TargetRR_ps->screen_af64[1][3];

  o_Target_pt->screen_af64[2][0] = 1.0;
  o_Target_pt->screen_af64[2][1] = 1.0;
  o_Target_pt->screen_af64[2][2] = 1.0;
  o_Target_pt->screen_af64[2][3] = 1.0;

  o_Target_pt->real_af64[0][0] = b_TargetFL_ps->real_af64[0][0];
  o_Target_pt->real_af64[0][1] = b_TargetFR_ps->real_af64[0][1];
  o_Target_pt->real_af64[0][2] = b_TargetRL_ps->real_af64[0][2];
  o_Target_pt->real_af64[0][3] = b_TargetRR_ps->real_af64[0][3];

  o_Target_pt->real_af64[1][0] = b_TargetFL_ps->real_af64[1][0];
  o_Target_pt->real_af64[1][1] = b_TargetFR_ps->real_af64[1][1];
  o_Target_pt->real_af64[1][2] = b_TargetRL_ps->real_af64[1][2];
  o_Target_pt->real_af64[1][3] = b_TargetRR_ps->real_af64[1][3];

  o_Target_pt->real_af64[2][0] = b_TargetFL_ps->real_af64[2][0];
  o_Target_pt->real_af64[2][1] = b_TargetFR_ps->real_af64[2][1];
  o_Target_pt->real_af64[2][2] = b_TargetRL_ps->real_af64[2][2];
  o_Target_pt->real_af64[2][3] = b_TargetRR_ps->real_af64[2][3];

  o_Target_pt->real_af64[3][0] = 1.0;
  o_Target_pt->real_af64[3][1] = 1.0;
  o_Target_pt->real_af64[3][2] = 1.0;
  o_Target_pt->real_af64[3][3] = 1.0;

  f_CalcH_v(o_Target_pt);

  memcpy(b_TargetFL_ps->h_af64, o_Target_pt->h_af64, sizeof(float64_t) * 9);
  memcpy(b_TargetFL_ps->hinv_af64, o_Target_pt->hinv_af64, sizeof(float64_t) * 9);
  memcpy(b_TargetFR_ps->h_af64, o_Target_pt->h_af64, sizeof(float64_t) * 9);
  memcpy(b_TargetFR_ps->hinv_af64, o_Target_pt->hinv_af64, sizeof(float64_t) * 9);
  memcpy(b_TargetRL_ps->h_af64, o_Target_pt->h_af64, sizeof(float64_t) * 9);
  memcpy(b_TargetRL_ps->hinv_af64, o_Target_pt->hinv_af64, sizeof(float64_t) * 9);
  memcpy(b_TargetRR_ps->h_af64, o_Target_pt->h_af64, sizeof(float64_t) * 9);
  memcpy(b_TargetRR_ps->hinv_af64, o_Target_pt->hinv_af64, sizeof(float64_t) * 9);
}


void EolCalib::f_AlignTarget_v(T_Target_t *b_Target_ps) const
{
  /* DD-ID: {50940FB9-57AD-49e9-AC20-F61E528AD63D}*/
  float64_t v_T_af64[3] = { 0.0, 0.0, 0.0};
  uint32_t v_J_u32;

  float64_t v_Px1_af64[4];
  float64_t v_Px2_af64[4];
  float64_t v_Py1_af64[4];
  float64_t v_Py2_af64[4];
  
  float64_t v_HTemp_af64[9];
  mecl::core::Point2D<float64_t> v_PointTemp2D_x;
  mecl::core::Point2D<float64_t> v_PointTemp2dMetric_x;

  for (uint32_t v_I_u32 = 0; v_I_u32 < 4; v_I_u32++)
  {
    v_PointTemp2D_x(0) = b_Target_ps->cam_af64[0][v_I_u32];
    v_PointTemp2D_x(1) = b_Target_ps->cam_af64[1][v_I_u32];
    c_EolInitData_ps->camera_po->pixelToMetric_v(v_PointTemp2D_x, v_PointTemp2dMetric_x);
    v_Px2_af64[v_I_u32] = v_PointTemp2dMetric_x(0);
    v_Py2_af64[v_I_u32] = v_PointTemp2dMetric_x(1);
  }

  memcpy(v_Px1_af64, &b_Target_ps->real_af64[0][0], sizeof(float64_t) * 4);
  memcpy(v_Py1_af64, &b_Target_ps->real_af64[1][0], sizeof(float64_t) * 4);

  //vgg_H)from_x_lin function is from c and will be removed by mecl
  //So leave it like that
  //PRQA S 3840 1
  vggHFromXLin_s8(v_Px1_af64, v_Py1_af64, v_Px2_af64, v_Py2_af64, v_HTemp_af64, 4);

  // PRQA S 3077 1 // This downcast is necessary here.
  mecl::model::Pinhole<float64_t> &v_PinHole_rx = dynamic_cast<mecl::model::Pinhole<float64_t>&>(c_EolInitData_ps->camera_po->getImager_rx());
  mecl::core::RotationMatrix<float64_t> v_Rot_o;
  mecl::core::Point3D<float64_t> v_T_o;
  mecl::core::Point3D<float64_t> v_T2_o;
  mecl::core::Matrix3x3<float64_t> v_H_x;

  T_Target_t v_TargetTmp_t;
  memcpy(&v_TargetTmp_t, b_Target_ps, sizeof(T_Target_t));

  f_TransReal2Cam_v(&v_TargetTmp_t);
  memcpy(&v_TargetTmp_t.screen_af64, b_Target_ps->cam_af64, sizeof(float64_t) * 4 * 3);

  f_CalcH_v(&v_TargetTmp_t);

  for (uint32_t v_I_u32 = 0; v_I_u32 < 9; v_I_u32++)
  {
    v_H_x(v_I_u32) = -v_HTemp_af64[v_I_u32];
  }

  mecl::math::FDecompose<float64_t>::Homography::calcRotationAndTranslation_v(v_H_x, v_Rot_o, v_T2_o);
  v_T_o = v_PinHole_rx.getCameraCenter_x(v_Rot_o,v_T2_o);

  if (v_T_o(2) <= 0.0)
  {
	  for (uint32_t v_I_u32 = 0U; v_I_u32 < 9U; v_I_u32++)
	  {
	    v_H_x(v_I_u32) = v_HTemp_af64[v_I_u32];
	  }
	  mecl::math::FDecompose<float64_t>::Homography::calcRotationAndTranslation_v(v_H_x, v_Rot_o, v_T2_o);
	  v_T_o = v_PinHole_rx.getCameraCenter_x(v_Rot_o,v_T2_o);
  }

  for (uint32_t v_I_u32 = 0; v_I_u32 < 3; v_I_u32++)
  {
    for (v_J_u32 = 0; v_J_u32 < 3; v_J_u32++)
    {
      v_T_af64[v_I_u32] = v_T_o(v_I_u32);
    }
  }
  
  //Couldn't be fixed with eol, related to mecl
  //PRQA S 3077 1
  mecl::core::Point3D<float64_t> v_TDsg_x = v_PinHole_rx.getTranslationVector_x();
  v_TDsg_x = v_PinHole_rx.getCameraCenter_x(v_TDsg_x);
  
  if ((v_T_af64[0] - v_TDsg_x.getPosX()) < (-4.5 * TARGET_SIZE * 25.4))
  {
    b_Target_ps->index_s8 += 2;
  }
  else if ((v_T_af64[0] - v_TDsg_x.getPosX()) < (-1.5 * TARGET_SIZE * 25.4))
  {
    b_Target_ps->index_s8 += 1;
  }
  else if ((v_T_af64[0] - v_TDsg_x.getPosX()) > (4.5 * TARGET_SIZE * 25.4))
  {
    b_Target_ps->index_s8 -= 2;
  }
  else if ((v_T_af64[0] - v_TDsg_x.getPosX()) > (1.5 * TARGET_SIZE * 25.4))
  {
    b_Target_ps->index_s8 -= 1;
  }
  else
  {
  }
  
  f_SetRealTarget_v(b_Target_ps);
}

sint8_t EolCalib::f_FindCascadedTarget_s8(
                                          sint8_t i_Limit_s8,
                                          sint8_t i_Dir_s8,
                                          T_Target_t const *i_TargetInit_pt,
                                          T_Target_t *o_Target_pt)
{
  /* DD-ID: {9EDAA2C9-2DAF-488f-A9E2-812346B7D2CB}*/
  T_Target_t v_TargetTmp_t;
  bool_t v_BreakLoop_b = false;

  /* cascade twards front */
  memcpy(o_Target_pt, i_TargetInit_pt, sizeof(T_Target_t));
  while ((i_Dir_s8 * i_Limit_s8) > (i_Dir_s8 * o_Target_pt->index_s8 % 100))
  {
    if (0 != f_FindSubTarget_s8 (o_Target_pt, &v_TargetTmp_t, i_Dir_s8))
    {
      if ((mecl::core::abs_x(o_Target_pt->index_s8)<100) && ((mecl::core::abs_x(i_Limit_s8)-mecl::core::abs_x(o_Target_pt->index_s8%100))>=2))
      {
        if (0 != f_FindSubTarget_s8 (o_Target_pt, &v_TargetTmp_t, i_Dir_s8/mecl::core::abs_x(i_Dir_s8)*(mecl::core::abs_x(i_Dir_s8)+1)))
        {
          v_BreakLoop_b = true;
        }
      }
      else
      {
        v_BreakLoop_b = true;
      }
      if(true == v_BreakLoop_b)
      {
        break;
      }
    }
    memcpy (o_Target_pt, &v_TargetTmp_t, sizeof(T_Target_t));
  }

  return 0;
}

void EolCalib::f_MergeTargetsSides_v(T_Target_t *b_TargetF_ps,
                                     T_Target_t *b_TargetR_ps,
                                     float64_t i_Zoom_f64,
                                     T_Target_t *o_Target_pt)
{
  /* DD-ID: {CC9E4E16-6B5A-4805-A1D4-22FB1CCC9CDB}*/
  f_TransReal2Screen_v(b_TargetF_ps, i_Zoom_f64);
  f_TransReal2Screen_v(b_TargetR_ps, i_Zoom_f64);

  o_Target_pt->camId_e = b_TargetF_ps->camId_e;
  o_Target_pt->cam_af64[0][0] = b_TargetF_ps->cam_af64[0][0];
  o_Target_pt->cam_af64[0][1] = b_TargetF_ps->cam_af64[0][1];
  o_Target_pt->cam_af64[0][2] = b_TargetR_ps->cam_af64[0][2];
  o_Target_pt->cam_af64[0][3] = b_TargetR_ps->cam_af64[0][3];

  o_Target_pt->cam_af64[1][0] = b_TargetF_ps->cam_af64[1][0];
  o_Target_pt->cam_af64[1][1] = b_TargetF_ps->cam_af64[1][1];
  o_Target_pt->cam_af64[1][2] = b_TargetR_ps->cam_af64[1][2];
  o_Target_pt->cam_af64[1][3] = b_TargetR_ps->cam_af64[1][3];

  o_Target_pt->cam_af64[2][0] = 1.0;
  o_Target_pt->cam_af64[2][1] = 1.0;
  o_Target_pt->cam_af64[2][2] = 1.0;
  o_Target_pt->cam_af64[2][3] = 1.0;

  o_Target_pt->screen_af64[0][0] = b_TargetF_ps->screen_af64[0][0];
  o_Target_pt->screen_af64[0][1] = b_TargetF_ps->screen_af64[0][1];
  o_Target_pt->screen_af64[0][2] = b_TargetR_ps->screen_af64[0][2];
  o_Target_pt->screen_af64[0][3] = b_TargetR_ps->screen_af64[0][3];

  o_Target_pt->screen_af64[1][0] = b_TargetF_ps->screen_af64[1][0];
  o_Target_pt->screen_af64[1][1] = b_TargetF_ps->screen_af64[1][1];
  o_Target_pt->screen_af64[1][2] = b_TargetR_ps->screen_af64[1][2];
  o_Target_pt->screen_af64[1][3] = b_TargetR_ps->screen_af64[1][3];

  o_Target_pt->screen_af64[2][0] = 1.0;
  o_Target_pt->screen_af64[2][1] = 1.0;
  o_Target_pt->screen_af64[2][2] = 1.0;
  o_Target_pt->screen_af64[2][3] = 1.0;

  o_Target_pt->real_af64[0][0] = b_TargetF_ps->real_af64[0][0];
  o_Target_pt->real_af64[0][1] = b_TargetF_ps->real_af64[0][1];
  o_Target_pt->real_af64[0][2] = b_TargetR_ps->real_af64[0][2];
  o_Target_pt->real_af64[0][3] = b_TargetR_ps->real_af64[0][3];

  o_Target_pt->real_af64[1][0] = b_TargetF_ps->real_af64[1][0];
  o_Target_pt->real_af64[1][1] = b_TargetF_ps->real_af64[1][1];
  o_Target_pt->real_af64[1][2] = b_TargetR_ps->real_af64[1][2];
  o_Target_pt->real_af64[1][3] = b_TargetR_ps->real_af64[1][3];

  o_Target_pt->real_af64[2][0] = b_TargetF_ps->real_af64[2][0];
  o_Target_pt->real_af64[2][1] = b_TargetF_ps->real_af64[2][1];
  o_Target_pt->real_af64[2][2] = b_TargetR_ps->real_af64[2][2];
  o_Target_pt->real_af64[2][3] = b_TargetR_ps->real_af64[2][3];

  o_Target_pt->real_af64[3][0] = 1.0;
  o_Target_pt->real_af64[3][1] = 1.0;
  o_Target_pt->real_af64[3][2] = 1.0;
  o_Target_pt->real_af64[3][3] = 1.0;

  f_CalcH_v(o_Target_pt);

  memcpy(b_TargetF_ps->h_af64, o_Target_pt->h_af64, sizeof(float64_t) * 9);
  memcpy(b_TargetF_ps->hinv_af64, o_Target_pt->hinv_af64, sizeof(float64_t) * 9);
  memcpy(b_TargetR_ps->h_af64, o_Target_pt->h_af64, sizeof(float64_t) * 9);
  memcpy(b_TargetR_ps->hinv_af64, o_Target_pt->hinv_af64, sizeof(float64_t) * 9);
}

uint8_t EolCalib::lTarget_F_FindTarget_v(T_Target_t *o_Target_pt,
                                         T_Target_t *o_TargetExt_pt)
{
  /* DD-ID: {386F997D-A46C-4744-9C9A-35BFC64EF8B9}*/
  T_Target_t 	v_TargetL_t;
  T_Target_t  	v_TargetR_t;
  T_Target_t	v_TargetF_t;
  T_Target_t 	v_TargetLR_t;
  T_Target_t 	v_TargetLF_t;
  T_Target_t 	v_TargetRR_t;
  T_Target_t 	v_TargetRF_t;
  
  aParaMgr_E_CalibrationStatus_t v_Flag_t = e_InProcess;

#ifdef ENABLE_DEBUG_OPENCV
  g_TransImg_pcv = cvCreateImage (cvSize(LOGIVIEW_OUTPUT_SIZE_X,LOGIVIEW_OUTPUT_SIZE_Y), 8, 3);
  cvSetImageROI(g_TransImg_pcv,cvRect(0,0,LOGIVIEW_OUTPUT_SIZE_X/2*3,LOGIVIEW_OUTPUT_SIZE_Y/2*3));
#endif

  o_Target_pt->camId_e = lCaliVCalibration_s.camId_e;

  switch (o_Target_pt->camId_e)
  {
    case e_FrontCamAlgo:
	 {
      o_Target_pt->index_s8 = -102;
      o_Target_pt->nx_u8 = 6;
      o_Target_pt->ny_u8 = 2;
      o_Target_pt->side_e = e_TargetLeft;
      break;
	 }
    case e_LeftCamAlgo:
	 {
      o_Target_pt->index_s8 = 0;
      o_Target_pt->nx_u8 = 6;
      o_Target_pt->ny_u8 = 4;
      o_Target_pt->side_e = e_TargetLeft;
      break;
	  }
    case e_RearCamAlgo:
	 {
      o_Target_pt->index_s8 = 99 + lCaliVCalibration_s.errorState_s.camState_s.targetInit_s8;
      o_Target_pt->nx_u8 = 6;
      o_Target_pt->ny_u8 = 2;
      o_Target_pt->side_e = e_TargetLeft;
      break;
	  }
    case e_RightCamAlgo:
	 {
      o_Target_pt->index_s8 = 0;
      o_Target_pt->nx_u8 = 6;
      o_Target_pt->ny_u8 = 4;
      o_Target_pt->side_e = e_TargetRight;
      break;
	  }
    default:
	 {
	  break;
	 }
  }
  /* transform image per design */
  f_CalcNominalH_v(o_Target_pt);

  if ((o_Target_pt->camId_e == e_FrontCamAlgo) || (o_Target_pt->camId_e == e_RearCamAlgo))
  {
    sint8_t v_Ret1_s8;
	sint8_t v_Ret2_s8;

    memcpy(&v_TargetL_t, o_Target_pt, sizeof(T_Target_t));
    memcpy(&v_TargetR_t, o_Target_pt, sizeof(T_Target_t));
    v_TargetR_t.side_e = e_TargetRight;

    /* acquire init target for left and right side */
    v_Ret1_s8 = f_FindInitTarget_s8(&v_TargetL_t);
    f_AlignTarget_v(&v_TargetL_t);
    v_Ret2_s8 = f_FindInitTarget_s8(&v_TargetR_t);
    f_AlignTarget_v(&v_TargetR_t);

    /* retry if big target could be found */
    if ((v_Ret1_s8 != 0) && (v_Ret2_s8 != 0))
    {
      o_Target_pt->index_s8 = o_Target_pt->index_s8 % 100;
      memcpy(&v_TargetL_t, o_Target_pt, sizeof(T_Target_t));
      memcpy(&v_TargetR_t, o_Target_pt, sizeof(T_Target_t));
      v_TargetR_t.side_e = e_TargetRight;
      v_Ret1_s8 = f_FindInitTarget_s8(&v_TargetL_t);
      f_AlignTarget_v(&v_TargetL_t);
      v_Ret2_s8 = f_FindInitTarget_s8(&v_TargetR_t);
      f_AlignTarget_v(&v_TargetR_t);
    }

    if ((v_Ret1_s8 == 0) && (v_Ret2_s8 == 0))
    {
      f_MergeTargets_v(&v_TargetL_t, &v_TargetR_t, &v_TargetL_t, &v_TargetR_t, LTARGET_DETECTION_ZOOM_FACTOR, o_Target_pt);
    }

    else if (v_Ret1_s8 == 0)
    {
      f_MergeTargets_v(&v_TargetL_t, &v_TargetL_t, &v_TargetL_t, &v_TargetL_t, LTARGET_DETECTION_ZOOM_FACTOR, o_Target_pt);

      memcpy(&v_TargetR_t, o_Target_pt, sizeof(T_Target_t));
      v_TargetR_t.side_e = e_TargetRight;
      if (0 != f_FindInitTarget_s8(&v_TargetR_t))
        {v_Flag_t = (e_TargetNotFoundRight);}

	  if(v_Flag_t == e_TargetNotFoundRight)
	  {
	  }
	  else
	  {
		f_AlignTarget_v(&v_TargetR_t);
		f_MergeTargets_v(&v_TargetL_t, &v_TargetR_t, &v_TargetL_t, &v_TargetR_t, LTARGET_DETECTION_ZOOM_FACTOR, o_Target_pt);
	  }

    }
    else if (v_Ret2_s8 == 0)
    {
      f_MergeTargets_v(&v_TargetR_t, &v_TargetR_t, &v_TargetR_t, &v_TargetR_t, LTARGET_DETECTION_ZOOM_FACTOR, o_Target_pt);

      memcpy(&v_TargetL_t, o_Target_pt, sizeof(T_Target_t));
      v_TargetL_t.side_e = e_TargetLeft;
      if (0 != f_FindInitTarget_s8(&v_TargetL_t))
        {v_Flag_t = e_TargetNotFoundLeft;}

	  if(v_Flag_t == e_TargetNotFoundLeft)
	  {
	  }
	  else
	  {
		f_AlignTarget_v(&v_TargetL_t);
		f_MergeTargets_v(&v_TargetL_t, &v_TargetR_t, &v_TargetL_t, &v_TargetR_t, LTARGET_DETECTION_ZOOM_FACTOR, o_Target_pt);
	  }

    }
    else
      {v_Flag_t = e_TargetNotFoundInit;}


	if (v_Flag_t == e_InProcess )
	{

		/* cascade to target limits */
		f_FindCascadedTarget_s8(lCaliVCalibration_s.errorState_s.camState_s.targetLimitF_s8, -1, &v_TargetL_t,
                            &v_TargetLF_t);
		f_FindCascadedTarget_s8( lCaliVCalibration_s.errorState_s.camState_s.targetLimitR_s8, 1, &v_TargetL_t,
                            &v_TargetLR_t);
		f_FindCascadedTarget_s8( lCaliVCalibration_s.errorState_s.camState_s.targetLimitF_s8, -1, &v_TargetR_t,
                            &v_TargetRF_t);
		f_FindCascadedTarget_s8( lCaliVCalibration_s.errorState_s.camState_s.targetLimitR_s8, 1, &v_TargetR_t,
                            &v_TargetRR_t);
		f_MergeTargets_v(&v_TargetLF_t, &v_TargetRF_t, &v_TargetLR_t, &v_TargetRR_t, 1.0, o_Target_pt);
		f_MergeTargets_v(&v_TargetRF_t, &v_TargetLF_t, &v_TargetRR_t, &v_TargetLR_t, 1.0, o_TargetExt_pt);

		/* set calibration structures */
		lCaliVCalibration_s.errorState_s.camState_s.targetDetectLF_s8 = v_TargetLF_t.index_s8;
		lCaliVCalibration_s.errorState_s.camState_s.targetDetectLR_s8 = v_TargetLR_t.index_s8;
		lCaliVCalibration_s.errorState_s.camState_s.targetDetectRF_s8 = v_TargetRF_t.index_s8;
		lCaliVCalibration_s.errorState_s.camState_s.targetDetectRR_s8 = v_TargetRR_t.index_s8;
	}

  }
  else
  {
    /* acquire single init target */
    if (0 != f_FindInitTarget_s8(o_Target_pt))
      {v_Flag_t = e_TargetNotFoundInit;}

	if(v_Flag_t == e_TargetNotFoundInit)
	{
	}
	else
	{
		T_Target_t    v_Targettmp_t;
		memcpy(&v_Targettmp_t,o_Target_pt,sizeof(T_Target_t));

		/* cascade to abs(1) subtarget to get higher accuracy */
		f_FindCascadedTarget_s8( -1, -1, o_Target_pt, &v_TargetF_t);
		f_FindCascadedTarget_s8( 1, 1, o_Target_pt, &v_TargetR_t);
		f_MergeTargetsSides_v(&v_TargetF_t, &v_TargetR_t, LTARGET_DETECTION_ZOOM_FACTOR, o_Target_pt);
    
		if (o_TargetExt_pt != NULL)
			{memcpy(o_TargetExt_pt, o_Target_pt, sizeof(T_Target_t));}

		memcpy(&v_Targettmp_t.h_af64,o_Target_pt->h_af64,sizeof(float64_t)*9);
		memcpy(&v_Targettmp_t.hinv_af64,o_Target_pt->hinv_af64,sizeof(float64_t)*9);

		/* cascade to target limits */
		f_FindCascadedTarget_s8( lCaliVCalibration_s.errorState_s.camState_s.targetLimitF_s8, -1, &v_Targettmp_t,&v_TargetF_t);
		f_FindCascadedTarget_s8( lCaliVCalibration_s.errorState_s.camState_s.targetLimitR_s8, 1, &v_Targettmp_t,&v_TargetR_t);
		f_MergeTargetsSides_v(&v_TargetF_t, &v_TargetR_t, 1.0, o_Target_pt);
		f_MergeTargetsSides_v(&v_TargetR_t, &v_TargetF_t, 1.0, o_TargetExt_pt);

		lCaliVCalibration_s.errorState_s.camState_s.targetDetectLF_s8 = v_TargetF_t.index_s8;
		lCaliVCalibration_s.errorState_s.camState_s.targetDetectRF_s8 = v_TargetF_t.index_s8;
		lCaliVCalibration_s.errorState_s.camState_s.targetDetectLR_s8 = v_TargetR_t.index_s8;
		lCaliVCalibration_s.errorState_s.camState_s.targetDetectRR_s8 = v_TargetR_t.index_s8;
	}
  }

  return (static_cast<uint8_t> (v_Flag_t));
}

void EolCalib::f_TransReal2BevScreen_v(T_Target_t *b_Target_pt)
{
  /* DD-ID: {E04EE657-C0CA-4433-91DF-D7780E4A4D5E}*/
  uint8_t v_Count_u8;

  for (v_Count_u8 = 0; v_Count_u8 < 4; ++v_Count_u8)
  {
    b_Target_pt->screen_af64[0][v_Count_u8] = (b_Target_pt->real_af64[1][v_Count_u8] / RATIOMM2PXX
        + ORIGINALX);
    b_Target_pt->screen_af64[1][v_Count_u8] = (b_Target_pt->real_af64[0][v_Count_u8] / RATIOMM2PXY
        + ORIGINALY);
    b_Target_pt->screen_af64[2][v_Count_u8] = 1.0;
  }
}

aParaMgr_E_CalibrationStatus_t EolCalib::checkQuality_t(void) const
{
  /* DD-ID: {29A02101-8D90-4b1a-8F83-AB8D8D1AA39E}*/
  sint8_t v_Limit_as8[4];
  aParaMgr_E_CalibrationStatus_t v_Flag_t = e_InProcess;

  /*update rectangle pattern id*/
  uint8_t v_LF_u8;
  uint8_t v_RF_u8;
  uint8_t v_LR_u8;
  uint8_t v_RR_u8;

  v_LF_u8 = lCaliVCalibration_s.errorState_s.camState_s.targetDetectLF_s8;
  v_RF_u8 = lCaliVCalibration_s.errorState_s.camState_s.targetDetectRF_s8;
  v_LR_u8 = lCaliVCalibration_s.errorState_s.camState_s.targetDetectLR_s8;
  v_RR_u8 = lCaliVCalibration_s.errorState_s.camState_s.targetDetectRR_s8;


  if (lCaliVCalibration_s.errorState_s.camState_s.targetDetectLF_s8 <= -100)
    {v_LF_u8 = lCaliVCalibration_s.errorState_s.camState_s.targetDetectLF_s8 + 100;}
  if (lCaliVCalibration_s.errorState_s.camState_s.targetDetectLF_s8 >= 100)
    {v_LF_u8 = lCaliVCalibration_s.errorState_s.camState_s.targetDetectLF_s8 - 100;}

  if (lCaliVCalibration_s.errorState_s.camState_s.targetDetectRF_s8 <= -100)
    {v_RF_u8 = lCaliVCalibration_s.errorState_s.camState_s.targetDetectRF_s8 + 100;}
  if (lCaliVCalibration_s.errorState_s.camState_s.targetDetectRF_s8 >= 100)
    {v_RF_u8 = lCaliVCalibration_s.errorState_s.camState_s.targetDetectRF_s8 - 100;}

  if (lCaliVCalibration_s.errorState_s.camState_s.targetDetectLR_s8 <= -100)
    {v_LR_u8 = lCaliVCalibration_s.errorState_s.camState_s.targetDetectLR_s8 + 100;}
  if (lCaliVCalibration_s.errorState_s.camState_s.targetDetectLR_s8 >= 100)
    {v_LR_u8 = lCaliVCalibration_s.errorState_s.camState_s.targetDetectLR_s8 - 100;}

  if (lCaliVCalibration_s.errorState_s.camState_s.targetDetectRR_s8 <= -100)
    {v_RR_u8 = lCaliVCalibration_s.errorState_s.camState_s.targetDetectRR_s8 + 100;}
  if (lCaliVCalibration_s.errorState_s.camState_s.targetDetectRR_s8 >= 100)
    {v_RR_u8 = lCaliVCalibration_s.errorState_s.camState_s.targetDetectRR_s8 - 100;}

  v_Limit_as8[0] =
      mecl::core::abs_x(v_LF_u8 - lCaliVCalibration_s.errorState_s.camState_s.targetLimitF_s8) - LCALI_MAX_QUALITY_ISSUE_LIMIT;
  v_Limit_as8[1] =
      mecl::core::abs_x(v_RF_u8 - lCaliVCalibration_s.errorState_s.camState_s.targetLimitF_s8) - LCALI_MAX_QUALITY_ISSUE_LIMIT;
  v_Limit_as8[2] =
      mecl::core::abs_x(v_LR_u8 - lCaliVCalibration_s.errorState_s.camState_s.targetLimitR_s8) - LCALI_MAX_QUALITY_ISSUE_LIMIT;
  v_Limit_as8[3] =
      mecl::core::abs_x(v_RR_u8 - lCaliVCalibration_s.errorState_s.camState_s.targetLimitR_s8) - LCALI_MAX_QUALITY_ISSUE_LIMIT;



  if ((v_Limit_as8[0] > 0) || (v_Limit_as8[1] > 0) || (v_Limit_as8[2] > 0) || (v_Limit_as8[3] > 0))
    {v_Flag_t = e_ExceededQualityLimit;}

  return v_Flag_t;
}

void EolCalib::lCaliFCalibrate360_v()
{
  /* DD-ID: {6B20EF0D-7D71-468b-BBD9-8DBBF4022457}*/
  T_Target_t  v_Target_t;
  T_Target_t  v_TargetExt_t;

  /* find target board */
  lCaliVCalibration_s.errorState_s.camState_s.status_u8 = lTarget_F_FindTarget_v(&v_Target_t, &v_TargetExt_t);
  f_TransReal2BevScreen_v(&v_Target_t);

  /* check if quality limit are viloated */
  if (lCaliVCalibration_s.errorState_s.camState_s.status_u8 == e_InProcess)
    {lCaliVCalibration_s.errorState_s.camState_s.status_u8 = checkQuality_t();}

  /* check varinat coding deviations */
  if (lCaliVCalibration_s.errorState_s.camState_s.status_u8 == e_InProcess)
  {
	lCaliVCalibration_s.errorState_s.camState_s.status_u8 = checkDeviationLimit_t(&v_Target_t,&v_TargetExt_t);
  }

  /* check correct target placemented */
  if ((lCaliVCalibration_s.calibrationType_u8 == e_ServiceCalibration) && (lCaliVCalibration_s.errorState_s.camState_s.status_u8
      == e_InProcess))
    {lCaliVCalibration_s.errorState_s.camState_s.status_u8 = fCheckTargetShift_t();}

  /* set success if all checks were pass */
  if (lCaliVCalibration_s.errorState_s.camState_s.status_u8 == e_InProcess)
    {lCaliVCalibration_s.errorState_s.camState_s.status_u8 = e_Success;}
}


aParaMgr_E_CalibrationStatus_t EolCalib::fCheckTargetShift_t() const
{
  /* DD-ID: {1E98072A-F6EF-440a-A7BA-28DFCBD5A245}*/
  aParaMgr_E_CalibrationStatus_t v_Flag_e = e_InProcess;
  //Couldn't be fixed with eol, related to mecl
  //PRQA S 3077 1
  mecl::model::Pinhole<float64_t> &v_PinHole_rx = dynamic_cast<mecl::model::Pinhole<float64_t>&>(c_EolInitData_ps->camera_po->getImager_rx());
  mecl::core::Point3D<float64_t> v_T_o = v_PinHole_rx.getTranslationVector_x();
  v_T_o = v_PinHole_rx.getCameraCenter_x(v_T_o);

  if (mecl::core::abs_x(lCaliVCalibration_s.camX_f32 - static_cast<float32_t>(v_T_o.getPosX())) > MAXDEVIATIONLOC)
  {
    v_Flag_e = e_TargetIdentErrorLeft;
  }
  if (mecl::core::abs_x(lCaliVCalibration_s.camY_f32 - static_cast<float32_t>(v_T_o.getPosY())) > MAXDEVIATIONLOC)
  {
    v_Flag_e = e_TargetIdentErrorRight;
  }

  return v_Flag_e;
}

void EolCalib::lCali_extrinsic_tad(T_Target_t const *i_Target_pt,T_Target_t const *i_TargetExt_pt) //hongtao
{
  /* DD-ID: {85663660-18D9-4f28-A0D8-CCF40BFF5D65}*/
  uint32_t v_I_u32;

  mecl::core::RotationMatrix<float64_t> v_Rot_o;
  mecl::core::Point3D<float64_t> v_T_o;
  mecl::core::Matrix3x3<float64_t> v_H_o;
  mecl::core::Matrix3x3<float64_t> v_RotTemp_x;

  float64_t v_Px1_af64[8];
  float64_t v_Px2_af64[8];
  float64_t v_Py1_af64[8];
  float64_t v_Py2_af64[8];
  float64_t v_H_af64[9];
  mecl::core::Point2D<float64_t> v_P2dTemp_x;
  mecl::core::Point2D<float64_t> v_P2dTempM_x;

  /* prepare coresponding points */
  for (v_I_u32 = 0U; v_I_u32 < 4U; v_I_u32++)
  {
    v_P2dTemp_x(0) = i_Target_pt->screen_af64[0][v_I_u32];
    v_P2dTemp_x(1) = i_Target_pt->screen_af64[1][v_I_u32];
    c_EolInitData_ps->camera_po->pixelToMetric_v(v_P2dTemp_x, v_P2dTempM_x);
    v_Px2_af64[v_I_u32] = v_P2dTempM_x(0);
    v_Py2_af64[v_I_u32] = v_P2dTempM_x(1);

    v_P2dTemp_x(0) = i_TargetExt_pt->screen_af64[0][v_I_u32];
    v_P2dTemp_x(1) = i_TargetExt_pt->screen_af64[1][v_I_u32];
    c_EolInitData_ps->camera_po->pixelToMetric_v(v_P2dTemp_x, v_P2dTempM_x);
    v_Px2_af64[v_I_u32+4] = v_P2dTempM_x(0);
    v_Py2_af64[v_I_u32+4] = v_P2dTempM_x(1);

    v_Px1_af64[v_I_u32] = i_Target_pt->real_af64[0][v_I_u32];
    v_Py1_af64[v_I_u32] = i_Target_pt->real_af64[1][v_I_u32];
    v_Px1_af64[v_I_u32+4] = i_TargetExt_pt->real_af64[0][v_I_u32];
    v_Py1_af64[v_I_u32+4] = i_TargetExt_pt->real_af64[1][v_I_u32];
  }

  /* estimate homography */
  //vgg_H)from_x_lin function is from c and will be removed by mecl
  //So leave it like that
  //PRQA S 3840 1
  vggHFromXLin_s8(v_Px1_af64, v_Py1_af64, v_Px2_af64, v_Py2_af64, v_H_af64, 8);

  if((static_cast<uint8_t>(v_H_af64[8])) == 1U)
  {
    for (v_I_u32 = 0; v_I_u32 < 9; v_I_u32++)
    {
      v_H_o(v_I_u32) = -v_H_af64[v_I_u32];
    }

    /* decompose homography */
    //Couldn't be fixed with eol, related to mecl
    //PRQA S 3077 1
    mecl::model::Pinhole<float64_t> &v_PinHole_rx =dynamic_cast<mecl::model::Pinhole<float64_t>&>(c_EolInitData_ps->camera_po->getImager_rx());
    mecl::math::FDecompose<float64_t>::Homography::calcRotationAndTranslation_v(v_H_o, v_Rot_o, v_T_o);
    v_T_o = v_PinHole_rx.getCameraCenter_x(v_Rot_o, v_T_o);
    /* work around of decompose error */
    if (v_T_o(2) <= 0.0)
    {
      for (v_I_u32 = 0; v_I_u32 < 9; v_I_u32++)
      {
        v_H_o(v_I_u32) = v_H_af64[v_I_u32];
      }
      mecl::math::FDecompose<float64_t>::Homography::calcRotationAndTranslation_v(v_H_o, v_Rot_o, v_T_o);
      v_T_o = v_PinHole_rx.getCameraCenter_x(v_Rot_o, v_T_o);
    }

    mecl::core::RotationMatrix<float64_t>::EulerAngles_s v_Euler_s = v_PinHole_rx.getEulerAngles_s(v_Rot_o);

    /* fill output struct */
    lCaliVCalibration_s.camPitch_f32 = static_cast<float32_t>(mecl::math::toDegrees_x(v_Euler_s.pitch_x));
    lCaliVCalibration_s.camRoll_f32 = static_cast<float32_t>(mecl::math::toDegrees_x(v_Euler_s.roll_x));
    lCaliVCalibration_s.camYaw_f32 = static_cast<float32_t>(mecl::math::toDegrees_x(v_Euler_s.yaw_x));
    lCaliVCalibration_s.camX_f32 = static_cast<float32_t>(v_T_o(0));
    lCaliVCalibration_s.camY_f32 = static_cast<float32_t>(v_T_o(1));
    lCaliVCalibration_s.camZ_f32 = static_cast<float32_t>(v_T_o(2));

    if (lCaliVCalibration_s.camRoll_f32 > 180.0F)
    {
      lCaliVCalibration_s.camRoll_f32 -= 360.0F;
    }
    else if (lCaliVCalibration_s.camRoll_f32 < -180.0F)
    {
      lCaliVCalibration_s.camRoll_f32 += 360.0F;
    }
    else
    {
      /* Do Nothing */
    }
  }
  else
  {
    lCaliVCalibration_s.errorState_s.camState_s.status_u8 = e_HomographyEstimationError;
  }
}


aParaMgr_E_CalibrationStatus_t EolCalib::checkDeviationLimit_t(T_Target_t const *i_Target_pt,T_Target_t const *i_TargetExt_pt)
{
  /* DD-ID: {75C20063-43B7-4bce-85E7-E4CFD3713F5B}*/
  T_Target_t v_TargetTmp_t;
  T_Target_t v_TargetTmpExt_t;

  memcpy(&v_TargetTmp_t, i_Target_pt, sizeof(T_Target_t));
  memcpy(&v_TargetTmpExt_t, i_TargetExt_pt, sizeof(T_Target_t));

  aParaMgr_E_CalibrationStatus_t v_Flag_t = e_InProcess;
  /* work around for pixel shift */
  f_TransReal2Cam_v(&v_TargetTmp_t);
  f_TransReal2Cam_v(&v_TargetTmpExt_t);
  memcpy(&v_TargetTmp_t.screen_af64, i_Target_pt->cam_af64, sizeof(float64_t) * 4 * 3);
  memcpy(&v_TargetTmpExt_t.screen_af64, i_TargetExt_pt->cam_af64, sizeof(float64_t) * 4 * 3);

  f_CalcH_v(&v_TargetTmp_t);
  f_CalcH_v(&v_TargetTmpExt_t);

#ifdef ENABLE_DEBUG_OPENCV_VT
  IplImage* iplImage;
  uint32_t i;
  iplImage  = cvCreateImage(cvSize(IMAGE_WIDTH,IMAGE_HEIGHT), 8, 1);
  memcpy (iplImage->imageData, c_EolInitData_ps->c_Image_pu8, IMAGE_WIDTH*IMAGE_HEIGHT);
  mecl::core::Point2D<float64_t> P_2d_pixel;
  mecl::core::Point2D<float64_t> P_2d_metric;
  mecl::core::Point3D<float64_t> P_3d_metric;
  mecl::core::Point4D<float64_t> P_4d;

  for(i=0;i<4;i++)
  {
    P_2d_pixel(0) = v_TargetTmp_t.cam_af64[0][i];
    P_2d_pixel(1) = v_TargetTmp_t.cam_af64[1][i];
    P_2d_pixel.print("Design Loc");

    c_EolInitData_ps->camera_po->pixelToMetric_v(P_2d_pixel, P_2d_metric);
    P_3d_metric(0) = P_2d_metric(0);
    P_3d_metric(1) = P_2d_metric(1);
    P_3d_metric(2) = 1.0;

    c_EolInitData_ps->camera_po->applyDistortion_v(P_3d_metric, 0.0, P_2d_metric);

    c_EolInitData_ps->camera_po->metricToPixel_v(P_2d_metric, P_2d_pixel);

    P_2d_pixel.print("Cam");
    cvCircle(iplImage, cvPoint(P_2d_pixel(0), P_2d_pixel(1)), 5, cvScalar(125,0,0,0), 1, 8, 0 );

    P_2d_pixel(0) = v_TargetTmp_t.screen_af64[0][i];
    P_2d_pixel(1) = v_TargetTmp_t.screen_af64[1][i];
    P_2d_pixel.print("Real Loc");

    c_EolInitData_ps->camera_po->pixelToMetric_v(P_2d_pixel, P_2d_metric);
    P_3d_metric(0) = P_2d_metric(0);
    P_3d_metric(1) = P_2d_metric(1);
    P_3d_metric(2) = 1.0;

    c_EolInitData_ps->camera_po->applyDistortion_v(P_3d_metric, 0.0, P_2d_metric);

    c_EolInitData_ps->camera_po->metricToPixel_v(P_2d_metric, P_2d_pixel);

    P_2d_pixel.print("Screen");
    cvCircle(iplImage, cvPoint(P_2d_pixel(0), P_2d_pixel(1)), 5, cvScalar(255,0,0,0), 1, 8, 0 );
  }

  cvShowImage ("Cam Points", iplImage);
  cvSaveImage("Front_Cam.png",iplImage,0);
  cvWaitKey(0);

#endif


  lCali_extrinsic_tad(&v_TargetTmp_t,&v_TargetTmpExt_t);
  if (lCaliVCalibration_s.errorState_s.camState_s.status_u8 == e_HomographyEstimationError)
  {
    v_Flag_t = e_HomographyEstimationError;
  }

  if (v_Flag_t == e_HomographyEstimationError)
  {
  }
  else
  {
    //Couldn't be fixed with eol, related to mecl
    //PRQA S 3077 1
    mecl::model::Pinhole<float64_t> &v_PinHole_rx = dynamic_cast<mecl::model::Pinhole<float64_t>&>(c_EolInitData_ps->camera_po->getImager_rx());
    mecl::core::Point3D<float64_t> v_TDsg_x = v_PinHole_rx.getTranslationVector_x();
    v_TDsg_x = v_PinHole_rx.getCameraCenter_x(v_TDsg_x);

    mecl::core::RotationMatrix<float64_t>::EulerAngles_s v_Euler_s = v_PinHole_rx.getEulerAngles_s(
        v_PinHole_rx.getRotationMatrix_x());

    //PRQA S 1052 10
    if (   (mecl::core::abs_x(lCaliVCalibration_s.camX_f32 - static_cast<float32_t>(v_TDsg_x.getPosX())) > MAXDEVIATIONLOC)
        || (mecl::core::abs_x(lCaliVCalibration_s.camY_f32 - static_cast<float32_t>(v_TDsg_x.getPosY())) > MAXDEVIATIONLOC)
        /*|| (mecl::core::abs_x(lCali_V_CalibrationExt[TargetTmp.CamId_e].V_dZ_f32	-V_CameraParam_s[TargetTmp.CamId_e].Z_f32) > MAXDEVIATIONLOC) *//*check disabled due to issue with vertical */
        /*|| (mecl::core::abs_x(lCali_V_CalibrationExt[TargetTmp.CamId_e].V_dPitch_f32-V_CameraParam_s[TargetTmp.CamId_e].Pitch_f32) > MAXDEVIATIONANGLE) */
        || (mecl::core::abs_x(lCaliVCalibration_s.camYaw_f32 - static_cast<float32_t>(mecl::math::toDegrees_x(v_Euler_s.yaw_x))) > MAXDEVIATIONANGLE)
        || (mecl::core::abs_x(lCaliVCalibration_s.camRoll_f32 - static_cast<float32_t>(mecl::math::toDegrees_x(v_Euler_s.roll_x))) > MAXDEVIATIONANGLE))
    {
      //PRQA S 1051 1
      //flag = APARAMGR_E_H_ESTIMATION_ERROR;
    }
  }
  return v_Flag_t;
}

void EolCalib::lCaliFCalibrateTadVertical_v()
{
  /* DD-ID: {177B359C-8C08-4c01-B2E7-37412D41A30A}*/

}

void EolCalib::lCaliFCalibrate_v()
{
  /* DD-ID: {1A113301-3398-44df-85C4-C21B862B0586}*/
  switch (lCaliVCalibration_s.calibrationType_u8)
  {
    case e_EndOfLineCalibration:
    case e_ServiceCalibration:
    {
    	lCaliFCalibrate360_v();
      break;
    }
    case e_ServiceTadHorizontalCalibration:
    case e_EndOfLineTadVerticalCalibration:
    {
      if (lCaliVCalibration_s.camId_e == e_RearCamAlgo)
      {lCaliFCalibrate360_v();}
      break;
    }
    case e_EndOfLineTadCalibration:
    {
      if (lCaliVCalibration_s.camId_e == e_RearCamAlgo)
      {lCaliFCalibrateTadVertical_v();}
      break;
    }
    default:
    {
      break;
    }
  }
}

void EolCalib::lCaliFInit_v()
{
  /* DD-ID: {6AC616C2-C64F-4f03-893F-DA29FBE259D3}*/
  if (lCaliVCalibration_s.calibrationType_u8 == e_EndOfLineTadCalibration)
  {

  }
  else
  {
	  initTargetLimits_v();
  }
}

void EolCalib::initTargetLimits_v(void)
{
  /* DD-ID: {1E50977B-6D6F-48eb-BF66-A91ABF0131F6}*/
  lCaliVCalibration_s.errorState_s.camState_s.targetLimitF_s8 = c_EolInitData_ps->targetLimitF_s8;
  lCaliVCalibration_s.errorState_s.camState_s.targetInit_s8	 = c_EolInitData_ps->targetInit_s8;
  lCaliVCalibration_s.errorState_s.camState_s.targetLimitR_s8 = c_EolInitData_ps->targetLimitR_s8;
}


void EolCalib::f_ViewTrans(uint16_t const *i_Roi_pu16,
                           uint8_t  const *i_SrcImage_pu8,
                           uint16_t *o_CropSizeX_pu16,
                           uint16_t *o_CropSizeY_pu16,
                           float64_t  const *i_H_pf64,
                           uint16_t i_Col_u16,
                           uint16_t i_Row_u16) const
{
  /* DD-ID: {07D7B09C-5CE6-40ee-A3E8-655A74466537}*/
  uint32_t v_Count_u32;
  uint32_t v_InnerCount_u32;
  uint32_t v_Temp_u32;
  
  
  //PRQA S 3706 2
  *o_CropSizeX_pu16 = i_Roi_pu16[1] - i_Roi_pu16[0] + 1;
  *o_CropSizeY_pu16 = i_Roi_pu16[3] - i_Roi_pu16[2] + 1;
  

  mecl::core::Point2D<float64_t> v_P2dPixel_x;
  mecl::core::Point2D<float64_t> v_P2dMetric_x;
  mecl::core::Point3D<float64_t> v_P3dMetric_x;
  //MR_Modified
#ifdef ENABLE_DEBUG_OPENCV_VT
  IplImage *TestImg_pcv;
  TestImg_pcv = cvCreateImage (cvSize(*o_CropSizeX_pu16, *o_CropSizeY_pu16), 8, 1);
#endif

  mecl::core::Matrix<float64_t,3,3> v_HInv_x;
  for(v_Count_u32=0; v_Count_u32<9; v_Count_u32++)
  {
    //PRQA S 3706 1 //Pointer to an array
		v_HInv_x(v_Count_u32) = i_H_pf64[v_Count_u32];
  }
 
  mecl::core::Point3D<float64_t> v_P3dBevPixel_x;
  mecl::core::Point3D<float64_t> v_P3dCam_x;

  for (v_Count_u32 = 0; v_Count_u32 < *o_CropSizeY_pu16; v_Count_u32++)
  {
    for (v_InnerCount_u32 = 0; v_InnerCount_u32 < *o_CropSizeX_pu16; v_InnerCount_u32++)
    {
      //PRQA S 3706 3
      v_P3dBevPixel_x(0) = static_cast<float64_t>(i_Roi_pu16[0] + v_InnerCount_u32);
      v_P3dBevPixel_x(1) = static_cast<float64_t>(i_Roi_pu16[2] + v_Count_u32);
      v_P3dBevPixel_x(2) = 1.0;

      v_P3dCam_x = v_HInv_x%v_P3dBevPixel_x;
      c_EolInitData_ps->camera_po->applyNormalization_v(v_P3dCam_x,1.0,v_P2dPixel_x);

      c_EolInitData_ps->camera_po->pixelToMetric_v(v_P2dPixel_x, v_P2dMetric_x);

      v_P3dMetric_x(0) = v_P2dMetric_x(0);
      v_P3dMetric_x(1) = v_P2dMetric_x(1);
      v_P3dMetric_x(2) = 1.0;

      c_EolInitData_ps->camera_po->applyDistortion_v(v_P3dMetric_x, 0.0, v_P2dMetric_x);
      c_EolInitData_ps->camera_po->metricToPixel_v(v_P2dMetric_x, v_P2dPixel_x);
      /*with one pixel only*/


      if ((v_P2dPixel_x(0) < 0) || (v_P2dPixel_x(0) > (static_cast <float64_t> (i_Col_u16))) || (v_P2dPixel_x(1) < 0) || (v_P2dPixel_x(1) > static_cast <float64_t> (i_Row_u16)))
      {
      }
      else
      {
        v_Temp_u32 = static_cast<uint32_t> (round_local(v_P2dPixel_x(1)) * IMAGE_WIDTH);
        v_Temp_u32 = v_Temp_u32 +  static_cast<uint32_t> (round_local(v_P2dPixel_x(0)));

        //PRQA S 3706 1
        memcpy(&(TransImg_pu8)[v_Count_u32 * (*o_CropSizeX_pu16) + v_InnerCount_u32], &i_SrcImage_pu8[v_Temp_u32], 1);

#ifdef ENABLE_DEBUG_OPENCV_VT
        memcpy (&TestImg_pcv->imageData[v_Count_u32*TestImg_pcv->widthStep+v_InnerCount_u32], &i_SrcImage_pu8[v_Temp_u32], 1);
#endif			
      }
    }
  }

#ifdef ENABLE_DEBUG_OPENCV_VT
  cvSaveImage("ROI_HW.png",TestImg_pcv,0); //MR_Modified
#endif
}

float64_t EolCalib::round_local(float64_t i_Number_f64)
{
  /* DD-ID: {CA5E2F35-DB94-4f08-AAC3-8558C778FE86}*/
  return (i_Number_f64 < 0.0) ? (mecl::math::numeric<float64_t>::ceil_x(i_Number_f64 - 0.5)) : (mecl::math::numeric<float64_t>::floor_x(i_Number_f64 + 0.5));
}

} //namespace
