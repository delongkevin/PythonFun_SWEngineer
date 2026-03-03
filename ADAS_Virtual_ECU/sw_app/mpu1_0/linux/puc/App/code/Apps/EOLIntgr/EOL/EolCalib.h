#ifndef _EOLCALIB_H_
#define _EOLCALIB_H_

#include "mecl/mecl.h"
#include "EolTypesInternal.h"
#include "corner.h"

namespace eol
{
//PRQA S 1021 1 //Macro comes from c header file
extern uint8_t TransImg_pu8[LTARGET_MAX_NORMALIZE_IMAGE];
extern uint8_t GlobalImg_au8[720*480];

struct DebugScreenInfo_s
{
  DebugScreenInfo_s()
  : patternId_s32(0)
  , imageSizeX_u32(0U)
  , imageSizeY_u32(0U)
  , arrayIndex_u32(0U)
  , imgSide_e(e_TargetLeft)
  {
    const uint32_t c_NumElements_u32 = (sizeof(corners_ao))/(sizeof(corners_ao[0]));
    for(uint32_t v_I_u32 = 0U; v_I_u32 < c_NumElements_u32; v_I_u32++)
    {
      corners_ao[v_I_u32](0.0F, 0.0F);
    }
  }

  DebugScreenInfo_s & operator=(const DebugScreenInfo_s &i_Data_rs)
  {
    if (this != &i_Data_rs)
    {
      patternId_s32 = i_Data_rs.patternId_s32;
      imageSizeX_u32   = i_Data_rs.imageSizeX_u32;
      imageSizeY_u32 = i_Data_rs.imageSizeY_u32;
      arrayIndex_u32 = i_Data_rs.arrayIndex_u32;
      imgSide_e = i_Data_rs.imgSide_e;
      const uint32_t c_NumElements_u32 = (sizeof(corners_ao))/(sizeof(corners_ao[0]));
      for(uint32_t v_I_u32 = 0U; v_I_u32 < c_NumElements_u32; v_I_u32++)
      {
        corners_ao[v_I_u32] = i_Data_rs.corners_ao[v_I_u32];
      }
    }
    return *this;
  }

  //PRQA S 2100 6 //After review, these public members could be made private.
  sint32_t patternId_s32;
  uint32_t imageSizeX_u32; //Width
  uint32_t imageSizeY_u32; //Height
  uint32_t arrayIndex_u32; //Array Index for this image in the Global array
  mecl::core::Point2D<float32_t> corners_ao[4U];
  E_TargetSide_t  imgSide_e; // 0 is left

private:
  DebugScreenInfo_s(const DebugScreenInfo_s& i_data_rs);
};

struct EolInitData_s
{
  uint8_t *c_Image_pu8;           //store the input image
  uint8_t       calibType_u8;         //Calibration Types
  uint8_t       cameraId_u8;          //camera id
  sint8_t       targetLimitF_s8;
  sint8_t       targetInit_s8;
  sint8_t       targetLimitR_s8;
  float32_t     targetSeperation_f32; //For different types of calibration
  mecl::model::Camera<float64_t>   *camera_po;     //camera obj
};

class EolCalib
{
public:

  static const uint32_t c_MaxNumberOfDebugImages_u32 = 20U;

  //PRQA S 2100 9 //After review, these public members could be made private.
  aParaMgr_S_Calibration_t  lCaliVCalibration_s;
  const EolInitData_s       *c_EolInitData_ps;

  //image size
  uint16_t            iSizeX_u16;
  uint16_t            iSizeY_u16;

  uint32_t            cntOfDebugImages_u32;
  DebugScreenInfo_s   roiImages_as[c_MaxNumberOfDebugImages_u32];

  //functions
  EolCalib();
  ~EolCalib();
  void	lCaliFCalibrate_v ();
  void	lCaliFInit_v();

private:

  static void	lCaliFCalibrateTadVertical_v();
  void  lCaliFCalibrate360_v ();
  void	lCaliFCalibrate360Tad_v ();
  void	initTargetLimits_v (void);
  void	f_CalcNominalH_v (T_Target_t *b_Target_pt) const;
  void	f_SetRealTarget_v (T_Target_t *b_Target_pt) const;
  static void	f_TransReal2Screen_v (T_Target_t *b_Target_pt, float64_t i_Zoom_f64);
  void	f_TransReal2Cam_v (T_Target_t *b_Target_pt) const;
  static void	f_CalcH_v (T_Target_t *b_Target_pt);
  static void	getRoi_v (T_Target_t *b_Target_ps, sint8_t i_IndexDir_s8, uint16_t*o_Roi_pu16);
  static void	f_TransScreen2Cam_v (T_Target_t *b_Target_pt);
  void	f_AlignTarget_v (T_Target_t *b_Target_ps) const;
  static void	f_MergeTargets_v (T_Target_t *b_TargetFL_ps, T_Target_t *b_TargetFR_ps, T_Target_t *b_TargetRL_ps, T_Target_t *b_TargetRR_ps, float64_t i_Zoom_f64, T_Target_t *o_Target_pt);
  static void	f_MergeTargetsSides_v (T_Target_t *b_TargetF_ps, T_Target_t *b_TargetR_ps, float64_t i_Zoom_f64, T_Target_t *o_Target_pt);
  static void	f_TransReal2BevScreen_v (T_Target_t *b_Target_pt);
  void	lCali_extrinsic_tad(T_Target_t const *i_Target_pt,T_Target_t const *i_TargetExt_pt);

  uint8_t lTarget_F_FindTarget_v (T_Target_t *o_Target_pt, T_Target_t *o_TargetExt_pt);
  sint8_t f_FindInitTarget_s8 (T_Target_t *b_Target_pt);
  sint8_t f_FindSubTarget_s8 (T_Target_t const *i_TargetInit_ps, T_Target_t *b_TargetNext_pt, sint8_t i_Dir_s8);
  sint8_t f_FindCascadedTarget_s8 (sint8_t i_Limit_s8, sint8_t i_Dir_s8, T_Target_t const *i_TargetInit_pt, T_Target_t *o_Target_pt);

  aParaMgr_E_CalibrationStatus_t checkQuality_t (void) const;
  aParaMgr_E_CalibrationStatus_t checkDeviationLimit_t (T_Target_t const *i_Target_pt,T_Target_t const *i_TargetExt_pt);
  aParaMgr_E_CalibrationStatus_t fCheckTargetShift_t() const;

  /*Temporal view transformation functions*/
  void f_ViewTrans(uint16_t const *i_Roi_pu16,uint8_t const *i_SrcImage_pu8,uint16_t *o_CropSizeX_pu16,uint16_t *o_CropSizeY_pu16,float64_t const *i_H_pf64,uint16_t i_Col_u16,uint16_t i_Row_u16) const;
  static float64_t round_local(float64_t i_Number_f64);

};

}
#else

#endif /* JOBEOL_H_ */
