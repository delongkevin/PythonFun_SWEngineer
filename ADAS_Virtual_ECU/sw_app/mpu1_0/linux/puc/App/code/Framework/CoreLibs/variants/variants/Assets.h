

#ifndef ASSETS
#define ASSETS

#include "Enums.h"
#include "Components.h"

namespace variants
{
class AssetBase
{
      public:
            virtual ~AssetBase( ) {  }
            uint32_t getId_u32( ) const { return id_u32; }
            const char_t* getName_pc( ) const { return name_ac; }
      protected:
            uint32_t id_u32;
            char_t name_ac[256];
};

const uint32_t c_InvalidGUID_u32 = 4294967295U;
const uint32_t c_CameraFrontVariant0_u32 = 38U;
const uint32_t c_CameraLeftVariant0_u32 = 102U;
const uint32_t c_CameraRearVariant0_u32 = 619U;
const uint32_t c_CameraRightVariant0_u32 = 796U;
const uint32_t c_CameraChmslVariant0_u32 = 5694U;
const uint32_t c_CameraAuxVariant0_u32 = 4846U;
const uint32_t c_VehicleDataVariant0_u32 = 264U;
const uint32_t c_MirrorObscuration_u32 = 8621U;
const uint32_t c_VariantConfig_u32 = 486U;
const uint32_t c_JobConfig_u32 = 698U;
const uint32_t c_ErrorManagerConfig_u32 = 1050U;
const uint32_t c_EOLCalibFrontVariant0_u32 = 1753U;
const uint32_t c_EOLCalibLeftVariant0_u32 = 951U;
const uint32_t c_EOLCalibRearVariant0_u32 = 285U;
const uint32_t c_EOLCalibRighttVariant0_u32 = 1767U;
const uint32_t c_EOLCalibChmslVariant0_u32 = 5812U;
const uint32_t c_OCFrontVariant0_u32 = 953U;
const uint32_t c_OCLeftVariant0_u32 = 1800U;
const uint32_t c_OCRearVariant0_u32 = 1208U;
const uint32_t c_OCRightvariant0_u32 = 466U;
const uint32_t c_OCKinematics_u32 = 579U;
const uint32_t c_OCChmslVariant0_u32 = 4055U;
const uint32_t c_SCCalibFrontVariant0_u32 = 2320U;
const uint32_t c_SCCalibLeftVariant0_u32 = 2509U;
const uint32_t c_SCCalibRearVariant0_u32 = 2698U;
const uint32_t c_SCCalibRightVariant0_u32 = 2887U;
const uint32_t c_SCCalibChmslVariant0_u32 = 6348U;
const uint32_t c_ScreenConfig_u32 = 7636U;
const uint32_t c_SingleViewFullFront_u32 = 4735U;
const uint32_t c_SingleViewFullRearWide_u32 = 3608U;
const uint32_t c_SingleViewFullRearNarrow_u32 = 5134U;
const uint32_t c_SingleViewFullRearHitch_u32 = 2618U;
const uint32_t c_SingleViewTopPrimaryFront_u32 = 2024U;
const uint32_t c_SingleViewTopPrimaryRear_u32 = 5891U;
const uint32_t c_SingleViewTopAllFront_u32 = 7420U;
const uint32_t c_SingleViewTopAllLeft_u32 = 2678U;
const uint32_t c_SingleViewTopAllRear_u32 = 2033U;
const uint32_t c_SingleViewTopAllRight_u32 = 5821U;
const uint32_t c_SingleViewTopFlFront_u32 = 4927U;
const uint32_t c_SingleViewTopFrFront_u32 = 7023U;
const uint32_t c_SingleViewTopFlLeft_u32 = 2035U;
const uint32_t c_SingleViewTopRlLeft_u32 = 5946U;
const uint32_t c_SingleViewTopRlRear_u32 = 2575U;
const uint32_t c_SingleViewTopRrRear_u32 = 3163U;
const uint32_t c_SingleViewTopFrRight_u32 = 1497U;
const uint32_t c_SingleViewTopRrRight_u32 = 7540U;
const uint32_t c_SingleViewFrontSplitLeft_u32 = 3396U;
const uint32_t c_SingleViewFrontSplitRight_u32 = 3572U;
const uint32_t c_SingleViewBed_u32 = 1524U;
const uint32_t c_SingleViewAux_u32 = 7585U;
const uint32_t c_SingleViewRearSplitCenterLeft_u32 = 7053U;
const uint32_t c_SingleViewRearSplitCenterRight_u32 = 2044U;
const uint32_t c_SingleViewRearSplitRightLeft_u32 = 1460U;
const uint32_t c_SingleViewRearSplitRightRight_u32 = 7595U;
const uint32_t c_SingleViewRearSplitLeftLeft_u32 = 3795U;
const uint32_t c_SingleViewRearSplitLeftRight_u32 = 4173U;
const uint32_t c_SingleViewRearSplitFarLeft_u32 = 390U;
const uint32_t c_SingleViewRearSplitFarRight_u32 = 4204U;
const uint32_t c_SingleViewMtmFrontSideOverallLeft_u32 = 6421U;
const uint32_t c_SingleViewMtmFrontSideOverallCenter_u32 = 4166U;
const uint32_t c_SingleViewMtmFrontSideOverallRight_u32 = 5143U;
const uint32_t c_SingleViewMtmFrontSideLeft_u32 = 7551U;
const uint32_t c_SingleViewMtmFrontSideCenter_u32 = 188U;
const uint32_t c_SingleViewMtmFrontSideRight_u32 = 4659U;
const uint32_t c_SingleViewMtmRearSideOverallLeft_u32 = 1462U;
const uint32_t c_SingleViewMtmRearSideOverallCenter_u32 = 3804U;
const uint32_t c_SingleViewMtmRearSideOverallRight_u32 = 4222U;
const uint32_t c_SingleViewMtmRearFull_u32 = 6133U;
const uint32_t c_SingleViewQuadFront_u32 = 2885U;
const uint32_t c_SingleViewQuadLeft_u32 = 3545U;
const uint32_t c_SingleViewQuadRear_u32 = 5659U;
const uint32_t c_SingleViewQuadRight_u32 = 4616U;
const uint32_t c_SingleViewTopAllFrontCalibration_u32 = 17U;
const uint32_t c_SingleViewTopAllLeftCalibration_u32 = 3020U;
const uint32_t c_SingleViewTopAllRearCalibration_u32 = 3868U;
const uint32_t c_SingleViewTopAllRightCalibration_u32 = 3762U;
const uint32_t c_SingleViewMtmUnderfloorSideOverallCenterHistoric_u32 = 2803U;
const uint32_t c_SingleViewMtmUnderfloorSideOverallCenterFront_u32 = 8313U;
const uint32_t c_SingleViewMtmUnderfloorSideOverallCenterLeft_u32 = 8324U;
const uint32_t c_SingleViewMtmUnderfloorSideOverallCenterRight_u32 = 8335U;
const uint32_t c_SingleViewMtmUnderfloorSideCenterHistoric_u32 = 3928U;
const uint32_t c_SingleViewMtmUnderfloorSideCenterFront_u32 = 8393U;
const uint32_t c_SingleViewMtmUnderfloorSideCenterLeft_u32 = 8405U;
const uint32_t c_SingleViewMtmUnderfloorSideCenterRight_u32 = 8475U;
const uint32_t c_SingleViewRawFront_u32 = 2556U;
const uint32_t c_SingleViewRawLeft_u32 = 2830U;
const uint32_t c_SingleViewRawRear_u32 = 3308U;
const uint32_t c_SingleViewRawRight_u32 = 3493U;
const uint32_t c_SingleViewRawChmsl_u32 = 3633U;
const uint32_t c_VirtualCameraFullFront_u32 = 3984U;
const uint32_t c_VirtualCameraFullRearWide_u32 = 1134U;
const uint32_t c_VirtualCameraFullRearNarrow_u32 = 6974U;
const uint32_t c_VirtualCameraFullRearHitch_u32 = 4545U;
const uint32_t c_VirtualCameraTopPrimaryFront_u32 = 8216U;
const uint32_t c_VirtualCameraTopPrimaryRear_u32 = 5263U;
const uint32_t c_VirtualCameraTopAll_u32 = 1887U;
const uint32_t c_VirtualCameraTopFl_u32 = 4273U;
const uint32_t c_VirtualCameraTopFr_u32 = 5389U;
const uint32_t c_VirtualCameraTopRl_u32 = 6482U;
const uint32_t c_VirtualCameraTopRr_u32 = 1891U;
const uint32_t c_VirtualCameraFrontSplitLeft_u32 = 1914U;
const uint32_t c_VirtualCameraFrontSplitRight_u32 = 3985U;
const uint32_t c_VirtualCameraBed_u32 = 5192U;
const uint32_t c_VirtualCameraAux_u32 = 2354U;
const uint32_t c_VirtualCameraRearSplitCenterLeft_u32 = 4293U;
const uint32_t c_VirtualCameraRearSplitCenterRight_u32 = 5409U;
const uint32_t c_VirtualCameraRearSplitRightLeft_u32 = 6898U;
const uint32_t c_VirtualCameraRearSplitRightRight_u32 = 2543U;
const uint32_t c_VirtualCameraRearSplitLeftLeft_u32 = 2666U;
const uint32_t c_VirtualCameraRearSplitLeftRight_u32 = 4005U;
const uint32_t c_VirtualCameraRearSplitFarLeft_u32 = 5212U;
const uint32_t c_VirtualCameraRearSplitFarRight_u32 = 7081U;
const uint32_t c_VirtualCameraMtmFrontSideOverallLeft_u32 = 1491U;
const uint32_t c_VirtualCameraMtmFrontSideOverallCenter_u32 = 3307U;
const uint32_t c_VirtualCameraMtmFrontSideOverallRight_u32 = 5117U;
const uint32_t c_VirtualCameraMtmFrontSideLeft_u32 = 6373U;
const uint32_t c_VirtualCameraMtmFrontSideCenter_u32 = 1845U;
const uint32_t c_VirtualCameraMtmFrontSideRight_u32 = 3055U;
const uint32_t c_VirtualCameraMtmRearSideOverallLeft_u32 = 4062U;
const uint32_t c_VirtualCameraMtmRearSideOverallCenter_u32 = 6939U;
const uint32_t c_VirtualCameraMtmRearSideOverallRight_u32 = 3296U;
const uint32_t c_VirtualCameraMtmRearFull_u32 = 3641U;
const uint32_t c_VirtualCameraMtmUnderfloorSideOverallCenter_u32 = 2738U;
const uint32_t c_VirtualCameraMtmUnderfloorSideCenter_u32 = 3074U;
const uint32_t c_VirtualCameraQuadFront_u32 = 5090U;
const uint32_t c_VirtualCameraQuadLeft_u32 = 6699U;
const uint32_t c_VirtualCameraQuadRear_u32 = 5509U;
const uint32_t c_VirtualCameraQuadRight_u32 = 3287U;
const uint32_t c_VirtualCameraTopAllCalibration_u32 = 2223U;
const uint32_t c_VirtualCameraRawFront_u32 = 3817U;
const uint32_t c_VirtualCameraRawLeft_u32 = 4313U;
const uint32_t c_VirtualCameraRawRear_u32 = 4827U;
const uint32_t c_VirtualCameraRawRight_u32 = 5386U;
const uint32_t c_VirtualCameraRawChmsl_u32 = 5843U;
const uint32_t c_CombinedViewFrontTopAll_u32 = 6352U;
const uint32_t c_CombinedViewFrontTopFl_u32 = 4321U;
const uint32_t c_CombinedViewFrontTopFr_u32 = 5776U;
const uint32_t c_CombinedViewFrontTopRl_u32 = 4461U;
const uint32_t c_CombinedViewFrontTopRr_u32 = 5088U;
const uint32_t c_CombinedViewFrontSplitTopAll_u32 = 4210U;
const uint32_t c_CombinedViewFrontSplitTopFl_u32 = 4171U;
const uint32_t c_CombinedViewFrontSplitTopFr_u32 = 4937U;
const uint32_t c_CombinedViewFrontSplitTopRl_u32 = 3569U;
const uint32_t c_CombinedViewFrontSplitTopRr_u32 = 3305U;
const uint32_t c_CombinedViewRearTopAll_u32 = 5309U;
const uint32_t c_CombinedViewRearTopFl_u32 = 3880U;
const uint32_t c_CombinedViewRearTopFr_u32 = 7214U;
const uint32_t c_CombinedViewRearTopRl_u32 = 1427U;
const uint32_t c_CombinedViewRearTopRr_u32 = 1598U;
const uint32_t c_CombinedViewRearSplitCenterTopAll_u32 = 5697U;
const uint32_t c_CombinedViewRearSplitCenterTopFl_u32 = 3165U;
const uint32_t c_CombinedViewRearSplitCenterTopFr_u32 = 3627U;
const uint32_t c_CombinedViewRearSplitCenterTopRl_u32 = 4905U;
const uint32_t c_CombinedViewRearSplitCenterTopRr_u32 = 3367U;
const uint32_t c_CombinedViewRearSplitRightTopAll_u32 = 4286U;
const uint32_t c_CombinedViewRearSplitRightTopFl_u32 = 1404U;
const uint32_t c_CombinedViewRearSplitRightTopFr_u32 = 7042U;
const uint32_t c_CombinedViewRearSplitRightTopRl_u32 = 1478U;
const uint32_t c_CombinedViewRearSplitRightTopRr_u32 = 7492U;
const uint32_t c_CombinedViewRearSplitFarRightTopAll_u32 = 7099U;
const uint32_t c_CombinedViewRearSplitFarRightTopFl_u32 = 3371U;
const uint32_t c_CombinedViewRearSplitFarRightTopFr_u32 = 3044U;
const uint32_t c_CombinedViewRearSplitFarRightTopRl_u32 = 3922U;
const uint32_t c_CombinedViewRearSplitFarRightTopRr_u32 = 3852U;
const uint32_t c_CombinedViewRearSplitLeftTopAll_u32 = 3246U;
const uint32_t c_CombinedViewRearSplitLeftTopFl_u32 = 247U;
const uint32_t c_CombinedViewRearSplitLeftTopFr_u32 = 5607U;
const uint32_t c_CombinedViewRearSplitLeftTopRl_u32 = 6523U;
const uint32_t c_CombinedViewRearSplitLeftTopRr_u32 = 3321U;
const uint32_t c_CombinedViewRearSplitFarLeftTopAll_u32 = 6059U;
const uint32_t c_CombinedViewRearSplitFarLeftTopFl_u32 = 2739U;
const uint32_t c_CombinedViewRearSplitFarLeftTopFr_u32 = 1465U;
const uint32_t c_CombinedViewRearSplitFarLeftTopRl_u32 = 2085U;
const uint32_t c_CombinedViewRearSplitFarLeftTopRr_u32 = 2722U;
const uint32_t c_CombinedViewFrontFull_u32 = 3304U;
const uint32_t c_CombinedViewRearFullWide_u32 = 7335U;
const uint32_t c_CombinedViewRearFullNarrow_u32 = 2667U;
const uint32_t c_CombinedViewRearFullHitch_u32 = 4670U;
const uint32_t c_CombinedViewBedSt_u32 = 2254U;
const uint32_t c_CombinedViewMtmFrontSideOverall_u32 = 5440U;
const uint32_t c_CombinedViewMtmFrontSide_u32 = 3265U;
const uint32_t c_CombinedViewMtmUnderfloorSideOverall_u32 = 4567U;
const uint32_t c_CombinedViewMtmUnderfloorSide_u32 = 6164U;
const uint32_t c_CombinedViewMtmRearSideOverall_u32 = 946U;
const uint32_t c_CombinedViewMtmRearFull_u32 = 5956U;
const uint32_t c_CombinedViewNoView_u32 = 3046U;
const uint32_t c_CombinedViewQuad_u32 = 7402U;
const uint32_t c_CombinedViewTopAllCalibration_u32 = 6874U;
const uint32_t c_CombinedViewRawFront_u32 = 6053U;
const uint32_t c_CombinedViewRawLeft_u32 = 6564U;
const uint32_t c_CombinedViewRawRear_u32 = 8072U;
const uint32_t c_CombinedViewRawRight_u32 = 8106U;
const uint32_t c_CombinedViewRawChmsl_u32 = 8140U;
const uint32_t c_PixelAreaFull_u32 = 4183U;
const uint32_t c_PixelAreaTopAll_u32 = 4284U;
const uint32_t c_PixelAreaTopAllFront_u32 = 4385U;
const uint32_t c_PixelAreaTopAllLeft_u32 = 1511U;
const uint32_t c_PixelAreaTopAllRear_u32 = 3458U;
const uint32_t c_PixelAreaTopAllRight_u32 = 3559U;
const uint32_t c_PixelAreaTopZoomFront_u32 = 3660U;
const uint32_t c_PixelAreaTopZoomLeft_u32 = 3761U;
const uint32_t c_PixelAreaTopZoomRear_u32 = 3862U;
const uint32_t c_PixelAreaTopZoomRight_u32 = 3963U;
const uint32_t c_PixelAreaTopPrimary_u32 = 4064U;
const uint32_t c_PixelAreaSplitCenterLeft_u32 = 4165U;
const uint32_t c_PixelAreaSplitCenterRight_u32 = 3150U;
const uint32_t c_PixelAreaSplitRightLeft_u32 = 3251U;
const uint32_t c_PixelAreaSplitRightRight_u32 = 3352U;
const uint32_t c_PixelAreaSplitLeftLeft_u32 = 4261U;
const uint32_t c_PixelAreaSplitLeftRight_u32 = 4362U;
const uint32_t c_PixelAreaMtmSideOverallLeft_u32 = 7441U;
const uint32_t c_PixelAreaMtmSideOverallCenter_u32 = 5839U;
const uint32_t c_PixelAreaMtmSideOverallRight_u32 = 5834U;
const uint32_t c_PixelAreaMtmSideLeft_u32 = 5759U;
const uint32_t c_PixelAreaMtmSideCenter_u32 = 4754U;
const uint32_t c_PixelAreaMtmSideRight_u32 = 4042U;
const uint32_t c_PixelAreaMtmFull_u32 = 5036U;
const uint32_t c_PixelAreaQuadTop_u32 = 3355U;
const uint32_t c_PixelAreaQuadFront_u32 = 1707U;
const uint32_t c_PixelAreaQuadLeft_u32 = 6792U;
const uint32_t c_PixelAreaQuadRear_u32 = 2988U;
const uint32_t c_PixelAreaQuadRight_u32 = 7913U;
const uint32_t c_PixelAreaTopAllCalibration_u32 = 569U;
const uint32_t c_PixelAreaTopAllFrontCalibration_u32 = 3550U;
const uint32_t c_PixelAreaTopAllLeftCalibration_u32 = 4419U;
const uint32_t c_PixelAreaTopAllRearCalibration_u32 = 4972U;
const uint32_t c_PixelAreaTopAllRightCalibration_u32 = 5387U;
const uint32_t c_PixelAreaRaw_u32 = 8174U;
const uint32_t c_PixelAreaQuadBottom_u32 = 8182U;
const uint32_t c_PixelAreaMtmSideOverallCenterHistoric_u32 = 8361U;
const uint32_t c_PixelAreaMtmSideOverallCenterFront_u32 = 8369U;
const uint32_t c_PixelAreaMtmSideOverallCenterLeft_u32 = 8377U;
const uint32_t c_PixelAreaMtmSideOverallCenterRight_u32 = 8385U;
const uint32_t c_PixelAreaMtmSideCenterHistoric_u32 = 8501U;
const uint32_t c_PixelAreaMtmSideCenterFront_u32 = 8509U;
const uint32_t c_PixelAreaMtmSideCenterLeft_u32 = 8517U;
const uint32_t c_PixelAreaMtmSideCenterRight_u32 = 8525U;
const uint32_t c_StitchParamsTopAllFrontLeft_u32 = 7077U;
const uint32_t c_StitchParamsTopAllFrontRight_u32 = 7542U;
const uint32_t c_StitchParamsTopAllRearLeft_u32 = 3149U;
const uint32_t c_StitchParamsTopAllRearRight_u32 = 3250U;
const uint32_t c_StitchParamsTopZoomFrontLeft_u32 = 6693U;
const uint32_t c_StitchParamsTopZoomFrontRight_u32 = 2793U;
const uint32_t c_StitchParamsTopZoomRearLeft_u32 = 1946U;
const uint32_t c_StitchParamsTopZoomRearRight_u32 = 3962U;
const uint32_t c_StitchParamsTopAllFrontLeftCalibration_u32 = 3348U;
const uint32_t c_StitchParamsTopAllFrontRightCalibration_u32 = 2737U;
const uint32_t c_StitchParamsTopAllRearLeftCalibration_u32 = 7240U;
const uint32_t c_StitchParamsTopAllRearRightCalibration_u32 = 2735U;
const uint32_t c_StitchParamsMtmSideOverallCenterFrontLeft_u32 = 8409U;
const uint32_t c_StitchParamsMtmSideOverallCenterFrontRight_u32 = 8424U;
const uint32_t c_StitchParamsMtmSideOverallCenterHistoricLeft_u32 = 8439U;
const uint32_t c_StitchParamsMtmSideOverallCenterHistoricRight_u32 = 8454U;
const uint32_t c_StitchParamsMtmSideCenterFrontLeft_u32 = 8533U;
const uint32_t c_StitchParamsMtmSideCenterFrontRight_u32 = 8548U;
const uint32_t c_StitchParamsMtmSideCenterHistoricLeft_u32 = 8563U;
const uint32_t c_StitchParamsMtmSideCenterHistoricRight_u32 = 8578U;
const uint32_t c_ViewsMap_u32 = 7105U;
const uint32_t c_SingleViewsMap_u32 = 6381U;
const uint32_t c_CarModelConfig0_u32 = 2009U;
const uint32_t c_KinematicModelConfig0_u32 = 5650U;

void serialize_v( osal::InOut& b_IO_ro );
AssetBase* getAssetById_po( uint32_t id );

class CameraRadialLens : public AssetBase
{
      friend void serialize_v(osal::InOut& b_IO_ro);
      public:
             CameraRadialLens( uint32_t i_Id_u32, const char_t* i_Name_pc )
            : AssetBase()
            {
                  id_u32 = i_Id_u32; 
                  ME_String_Strncpy_v(&name_ac[0], sizeof(name_ac), i_Name_pc, ME_String_CountBytes_s32(i_Name_pc));
            }
            static CameraRadialLens* get_po( uint32_t i_Id_u32 )
            {
                  // PRQA S 3076 1 // downcast is intended here
                  return dynamic_cast<CameraRadialLens*>(getAssetById_po(i_Id_u32));
            }
            const PinholeComponent* getPinholeComponent_po( ) const { return &pinholeComponent_o; }
            const LensRadialComponent* getLensRadialComponent_po( ) const { return &lensRadialComponent_o; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  pinholeComponent_o.serialize_v(b_IO_ro);
                  lensRadialComponent_o.serialize_v(b_IO_ro);
            }
            PinholeComponent pinholeComponent_o;
            LensRadialComponent lensRadialComponent_o;
};

class VehicleData : public AssetBase
{
      friend void serialize_v(osal::InOut& b_IO_ro);
      public:
             VehicleData( uint32_t i_Id_u32, const char_t* i_Name_pc )
            : AssetBase()
            {
                  id_u32 = i_Id_u32; 
                  ME_String_Strncpy_v(&name_ac[0], sizeof(name_ac), i_Name_pc, ME_String_CountBytes_s32(i_Name_pc));
            }
            static VehicleData* get_po( uint32_t i_Id_u32 )
            {
                  // PRQA S 3076 1 // downcast is intended here
                  return dynamic_cast<VehicleData*>(getAssetById_po(i_Id_u32));
            }
            const CompVehicleData* getCompVehicleData_po( ) const { return &compVehicleData_o; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  compVehicleData_o.serialize_v(b_IO_ro);
            }
            CompVehicleData compVehicleData_o;
};

class MirrorObscuration : public AssetBase
{
      friend void serialize_v(osal::InOut& b_IO_ro);
      public:
             MirrorObscuration( uint32_t i_Id_u32, const char_t* i_Name_pc )
            : AssetBase()
            {
                  id_u32 = i_Id_u32; 
                  ME_String_Strncpy_v(&name_ac[0], sizeof(name_ac), i_Name_pc, ME_String_CountBytes_s32(i_Name_pc));
            }
            static MirrorObscuration* get_po( uint32_t i_Id_u32 )
            {
                  // PRQA S 3076 1 // downcast is intended here
                  return dynamic_cast<MirrorObscuration*>(getAssetById_po(i_Id_u32));
            }
            const CompMirrorObscuration* getCompMirrorObscuration_po( ) const { return &compMirrorObscuration_o; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  compMirrorObscuration_o.serialize_v(b_IO_ro);
            }
            CompMirrorObscuration compMirrorObscuration_o;
};

class VariantConfig : public AssetBase
{
      friend void serialize_v(osal::InOut& b_IO_ro);
      public:
             VariantConfig( uint32_t i_Id_u32, const char_t* i_Name_pc )
            : AssetBase()
            {
                  id_u32 = i_Id_u32; 
                  ME_String_Strncpy_v(&name_ac[0], sizeof(name_ac), i_Name_pc, ME_String_CountBytes_s32(i_Name_pc));
            }
            static VariantConfig* get_po( uint32_t i_Id_u32 )
            {
                  // PRQA S 3076 1 // downcast is intended here
                  return dynamic_cast<VariantConfig*>(getAssetById_po(i_Id_u32));
            }
            const CompVariantConfig* getCompVariantConfig_po( ) const { return &compVariantConfig_o; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  compVariantConfig_o.serialize_v(b_IO_ro);
            }
            CompVariantConfig compVariantConfig_o;
};

class JobConfig : public AssetBase
{
      friend void serialize_v(osal::InOut& b_IO_ro);
      public:
             JobConfig( uint32_t i_Id_u32, const char_t* i_Name_pc )
            : AssetBase()
            {
                  id_u32 = i_Id_u32; 
                  ME_String_Strncpy_v(&name_ac[0], sizeof(name_ac), i_Name_pc, ME_String_CountBytes_s32(i_Name_pc));
            }
            static JobConfig* get_po( uint32_t i_Id_u32 )
            {
                  // PRQA S 3076 1 // downcast is intended here
                  return dynamic_cast<JobConfig*>(getAssetById_po(i_Id_u32));
            }
            const JobConfigComponent* getJobConfigComponent_po( ) const { return &jobConfigComponent_o; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  jobConfigComponent_o.serialize_v(b_IO_ro);
            }
            JobConfigComponent jobConfigComponent_o;
};

class ErrorManagerConfig : public AssetBase
{
      friend void serialize_v(osal::InOut& b_IO_ro);
      public:
             ErrorManagerConfig( uint32_t i_Id_u32, const char_t* i_Name_pc )
            : AssetBase()
            {
                  id_u32 = i_Id_u32; 
                  ME_String_Strncpy_v(&name_ac[0], sizeof(name_ac), i_Name_pc, ME_String_CountBytes_s32(i_Name_pc));
            }
            static ErrorManagerConfig* get_po( uint32_t i_Id_u32 )
            {
                  // PRQA S 3076 1 // downcast is intended here
                  return dynamic_cast<ErrorManagerConfig*>(getAssetById_po(i_Id_u32));
            }
            const ErrorManagerConfigComponent* getErrorManagerConfigComponent_po( ) const { return &errorManagerConfigComponent_o; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  errorManagerConfigComponent_o.serialize_v(b_IO_ro);
            }
            ErrorManagerConfigComponent errorManagerConfigComponent_o;
};

class CameraEOLcalibration : public AssetBase
{
      friend void serialize_v(osal::InOut& b_IO_ro);
      public:
             CameraEOLcalibration( uint32_t i_Id_u32, const char_t* i_Name_pc )
            : AssetBase()
            {
                  id_u32 = i_Id_u32; 
                  ME_String_Strncpy_v(&name_ac[0], sizeof(name_ac), i_Name_pc, ME_String_CountBytes_s32(i_Name_pc));
            }
            static CameraEOLcalibration* get_po( uint32_t i_Id_u32 )
            {
                  // PRQA S 3076 1 // downcast is intended here
                  return dynamic_cast<CameraEOLcalibration*>(getAssetById_po(i_Id_u32));
            }
            const CompEOL* getCompEOL_po( ) const { return &compEOL_o; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  compEOL_o.serialize_v(b_IO_ro);
            }
            CompEOL compEOL_o;
};

class CameraOCcalibration : public AssetBase
{
      friend void serialize_v(osal::InOut& b_IO_ro);
      public:
             CameraOCcalibration( uint32_t i_Id_u32, const char_t* i_Name_pc )
            : AssetBase()
            {
                  id_u32 = i_Id_u32; 
                  ME_String_Strncpy_v(&name_ac[0], sizeof(name_ac), i_Name_pc, ME_String_CountBytes_s32(i_Name_pc));
            }
            static CameraOCcalibration* get_po( uint32_t i_Id_u32 )
            {
                  // PRQA S 3076 1 // downcast is intended here
                  return dynamic_cast<CameraOCcalibration*>(getAssetById_po(i_Id_u32));
            }
            const CompCameraCfg* getCompCameraCfg_po( ) const { return &compCameraCfg_o; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  compCameraCfg_o.serialize_v(b_IO_ro);
            }
            CompCameraCfg compCameraCfg_o;
};

class KinematicsOC : public AssetBase
{
      friend void serialize_v(osal::InOut& b_IO_ro);
      public:
             KinematicsOC( uint32_t i_Id_u32, const char_t* i_Name_pc )
            : AssetBase()
            {
                  id_u32 = i_Id_u32; 
                  ME_String_Strncpy_v(&name_ac[0], sizeof(name_ac), i_Name_pc, ME_String_CountBytes_s32(i_Name_pc));
            }
            static KinematicsOC* get_po( uint32_t i_Id_u32 )
            {
                  // PRQA S 3076 1 // downcast is intended here
                  return dynamic_cast<KinematicsOC*>(getAssetById_po(i_Id_u32));
            }
            const CompKinematics* getCompKinematics_po( ) const { return &compKinematics_o; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  compKinematics_o.serialize_v(b_IO_ro);
            }
            CompKinematics compKinematics_o;
};

class CameraSCcalibration : public AssetBase
{
      friend void serialize_v(osal::InOut& b_IO_ro);
      public:
             CameraSCcalibration( uint32_t i_Id_u32, const char_t* i_Name_pc )
            : AssetBase()
            {
                  id_u32 = i_Id_u32; 
                  ME_String_Strncpy_v(&name_ac[0], sizeof(name_ac), i_Name_pc, ME_String_CountBytes_s32(i_Name_pc));
            }
            static CameraSCcalibration* get_po( uint32_t i_Id_u32 )
            {
                  // PRQA S 3076 1 // downcast is intended here
                  return dynamic_cast<CameraSCcalibration*>(getAssetById_po(i_Id_u32));
            }
            const CompEOL* getCompEOL_po( ) const { return &compEOL_o; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  compEOL_o.serialize_v(b_IO_ro);
            }
            CompEOL compEOL_o;
};

class ScreenConfig : public AssetBase
{
      friend void serialize_v(osal::InOut& b_IO_ro);
      public:
             ScreenConfig( uint32_t i_Id_u32, const char_t* i_Name_pc )
            : AssetBase()
            {
                  id_u32 = i_Id_u32; 
                  ME_String_Strncpy_v(&name_ac[0], sizeof(name_ac), i_Name_pc, ME_String_CountBytes_s32(i_Name_pc));
            }
            static ScreenConfig* get_po( uint32_t i_Id_u32 )
            {
                  // PRQA S 3076 1 // downcast is intended here
                  return dynamic_cast<ScreenConfig*>(getAssetById_po(i_Id_u32));
            }
            const ScreenConfigComponent* getScreenConfigComponent_po( ) const { return &screenConfigComponent_o; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  screenConfigComponent_o.serialize_v(b_IO_ro);
            }
            ScreenConfigComponent screenConfigComponent_o;
};

class SingleView : public AssetBase
{
      friend void serialize_v(osal::InOut& b_IO_ro);
      public:
             SingleView( uint32_t i_Id_u32, const char_t* i_Name_pc )
            : AssetBase()
            {
                  id_u32 = i_Id_u32; 
                  ME_String_Strncpy_v(&name_ac[0], sizeof(name_ac), i_Name_pc, ME_String_CountBytes_s32(i_Name_pc));
            }
            static SingleView* get_po( uint32_t i_Id_u32 )
            {
                  // PRQA S 3076 1 // downcast is intended here
                  return dynamic_cast<SingleView*>(getAssetById_po(i_Id_u32));
            }
            const SingleViewComponent* getSingleViewComponent_po( ) const { return &singleViewComponent_o; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  singleViewComponent_o.serialize_v(b_IO_ro);
            }
            SingleViewComponent singleViewComponent_o;
};

class VirtualCameraStretchLens : public AssetBase
{
      friend void serialize_v(osal::InOut& b_IO_ro);
      public:
             VirtualCameraStretchLens( uint32_t i_Id_u32, const char_t* i_Name_pc )
            : AssetBase()
            {
                  id_u32 = i_Id_u32; 
                  ME_String_Strncpy_v(&name_ac[0], sizeof(name_ac), i_Name_pc, ME_String_CountBytes_s32(i_Name_pc));
            }
            static VirtualCameraStretchLens* get_po( uint32_t i_Id_u32 )
            {
                  // PRQA S 3076 1 // downcast is intended here
                  return dynamic_cast<VirtualCameraStretchLens*>(getAssetById_po(i_Id_u32));
            }
            const PinholeComponent* getPinholeComponent_po( ) const { return &pinholeComponent_o; }
            const LensRadialComponent* getLensRadialComponent_po( ) const { return &lensRadialComponent_o; }
            const LensStretchVerticalComponent* getLensStretchVerticalComponent_po( ) const { return &lensStretchVerticalComponent_o; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  pinholeComponent_o.serialize_v(b_IO_ro);
                  lensRadialComponent_o.serialize_v(b_IO_ro);
                  lensStretchVerticalComponent_o.serialize_v(b_IO_ro);
            }
            PinholeComponent pinholeComponent_o;
            LensRadialComponent lensRadialComponent_o;
            LensStretchVerticalComponent lensStretchVerticalComponent_o;
};

class VirtualCameraNoLens : public AssetBase
{
      friend void serialize_v(osal::InOut& b_IO_ro);
      public:
             VirtualCameraNoLens( uint32_t i_Id_u32, const char_t* i_Name_pc )
            : AssetBase()
            {
                  id_u32 = i_Id_u32; 
                  ME_String_Strncpy_v(&name_ac[0], sizeof(name_ac), i_Name_pc, ME_String_CountBytes_s32(i_Name_pc));
            }
            static VirtualCameraNoLens* get_po( uint32_t i_Id_u32 )
            {
                  // PRQA S 3076 1 // downcast is intended here
                  return dynamic_cast<VirtualCameraNoLens*>(getAssetById_po(i_Id_u32));
            }
            const PinholeComponent* getPinholeComponent_po( ) const { return &pinholeComponent_o; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  pinholeComponent_o.serialize_v(b_IO_ro);
            }
            PinholeComponent pinholeComponent_o;
};

class VirtualCameraRadialLens : public AssetBase
{
      friend void serialize_v(osal::InOut& b_IO_ro);
      public:
             VirtualCameraRadialLens( uint32_t i_Id_u32, const char_t* i_Name_pc )
            : AssetBase()
            {
                  id_u32 = i_Id_u32; 
                  ME_String_Strncpy_v(&name_ac[0], sizeof(name_ac), i_Name_pc, ME_String_CountBytes_s32(i_Name_pc));
            }
            static VirtualCameraRadialLens* get_po( uint32_t i_Id_u32 )
            {
                  // PRQA S 3076 1 // downcast is intended here
                  return dynamic_cast<VirtualCameraRadialLens*>(getAssetById_po(i_Id_u32));
            }
            const PinholeComponent* getPinholeComponent_po( ) const { return &pinholeComponent_o; }
            const LensRadialComponent* getLensRadialComponent_po( ) const { return &lensRadialComponent_o; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  pinholeComponent_o.serialize_v(b_IO_ro);
                  lensRadialComponent_o.serialize_v(b_IO_ro);
            }
            PinholeComponent pinholeComponent_o;
            LensRadialComponent lensRadialComponent_o;
};

class VirtualCameraCylinderLens : public AssetBase
{
      friend void serialize_v(osal::InOut& b_IO_ro);
      public:
             VirtualCameraCylinderLens( uint32_t i_Id_u32, const char_t* i_Name_pc )
            : AssetBase()
            {
                  id_u32 = i_Id_u32; 
                  ME_String_Strncpy_v(&name_ac[0], sizeof(name_ac), i_Name_pc, ME_String_CountBytes_s32(i_Name_pc));
            }
            static VirtualCameraCylinderLens* get_po( uint32_t i_Id_u32 )
            {
                  // PRQA S 3076 1 // downcast is intended here
                  return dynamic_cast<VirtualCameraCylinderLens*>(getAssetById_po(i_Id_u32));
            }
            const PinholeComponent* getPinholeComponent_po( ) const { return &pinholeComponent_o; }
            const LensCylinderComponent* getLensCylinderComponent_po( ) const { return &lensCylinderComponent_o; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  pinholeComponent_o.serialize_v(b_IO_ro);
                  lensCylinderComponent_o.serialize_v(b_IO_ro);
            }
            PinholeComponent pinholeComponent_o;
            LensCylinderComponent lensCylinderComponent_o;
};

class CombinedView : public AssetBase
{
      friend void serialize_v(osal::InOut& b_IO_ro);
      public:
             CombinedView( uint32_t i_Id_u32, const char_t* i_Name_pc )
            : AssetBase()
            {
                  id_u32 = i_Id_u32; 
                  ME_String_Strncpy_v(&name_ac[0], sizeof(name_ac), i_Name_pc, ME_String_CountBytes_s32(i_Name_pc));
            }
            static CombinedView* get_po( uint32_t i_Id_u32 )
            {
                  // PRQA S 3076 1 // downcast is intended here
                  return dynamic_cast<CombinedView*>(getAssetById_po(i_Id_u32));
            }
            const CombinedViewComponent* getCombinedViewComponent_po( ) const { return &combinedViewComponent_o; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  combinedViewComponent_o.serialize_v(b_IO_ro);
            }
            CombinedViewComponent combinedViewComponent_o;
};

class PixelArea : public AssetBase
{
      friend void serialize_v(osal::InOut& b_IO_ro);
      public:
             PixelArea( uint32_t i_Id_u32, const char_t* i_Name_pc )
            : AssetBase()
            {
                  id_u32 = i_Id_u32; 
                  ME_String_Strncpy_v(&name_ac[0], sizeof(name_ac), i_Name_pc, ME_String_CountBytes_s32(i_Name_pc));
            }
            static PixelArea* get_po( uint32_t i_Id_u32 )
            {
                  // PRQA S 3076 1 // downcast is intended here
                  return dynamic_cast<PixelArea*>(getAssetById_po(i_Id_u32));
            }
            const PixelAreaComponent* getPixelAreaComponent_po( ) const { return &pixelAreaComponent_o; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  pixelAreaComponent_o.serialize_v(b_IO_ro);
            }
            PixelAreaComponent pixelAreaComponent_o;
};

class StitchParams : public AssetBase
{
      friend void serialize_v(osal::InOut& b_IO_ro);
      public:
             StitchParams( uint32_t i_Id_u32, const char_t* i_Name_pc )
            : AssetBase()
            {
                  id_u32 = i_Id_u32; 
                  ME_String_Strncpy_v(&name_ac[0], sizeof(name_ac), i_Name_pc, ME_String_CountBytes_s32(i_Name_pc));
            }
            static StitchParams* get_po( uint32_t i_Id_u32 )
            {
                  // PRQA S 3076 1 // downcast is intended here
                  return dynamic_cast<StitchParams*>(getAssetById_po(i_Id_u32));
            }
            const StitchParamsComponent* getStitchParamsComponent_po( ) const { return &stitchParamsComponent_o; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  stitchParamsComponent_o.serialize_v(b_IO_ro);
            }
            StitchParamsComponent stitchParamsComponent_o;
};

class ViewsMap : public AssetBase
{
      friend void serialize_v(osal::InOut& b_IO_ro);
      public:
             ViewsMap( uint32_t i_Id_u32, const char_t* i_Name_pc )
            : AssetBase()
            {
                  id_u32 = i_Id_u32; 
                  ME_String_Strncpy_v(&name_ac[0], sizeof(name_ac), i_Name_pc, ME_String_CountBytes_s32(i_Name_pc));
            }
            static ViewsMap* get_po( uint32_t i_Id_u32 )
            {
                  // PRQA S 3076 1 // downcast is intended here
                  return dynamic_cast<ViewsMap*>(getAssetById_po(i_Id_u32));
            }
            const ViewsMapComponent* getViewsMapComponent_po( ) const { return &viewsMapComponent_o; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  viewsMapComponent_o.serialize_v(b_IO_ro);
            }
            ViewsMapComponent viewsMapComponent_o;
};

class SingleViewsMap : public AssetBase
{
      friend void serialize_v(osal::InOut& b_IO_ro);
      public:
             SingleViewsMap( uint32_t i_Id_u32, const char_t* i_Name_pc )
            : AssetBase()
            {
                  id_u32 = i_Id_u32; 
                  ME_String_Strncpy_v(&name_ac[0], sizeof(name_ac), i_Name_pc, ME_String_CountBytes_s32(i_Name_pc));
            }
            static SingleViewsMap* get_po( uint32_t i_Id_u32 )
            {
                  // PRQA S 3076 1 // downcast is intended here
                  return dynamic_cast<SingleViewsMap*>(getAssetById_po(i_Id_u32));
            }
            const SingleViewsMapComponent* getSingleViewsMapComponent_po( ) const { return &singleViewsMapComponent_o; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  singleViewsMapComponent_o.serialize_v(b_IO_ro);
            }
            SingleViewsMapComponent singleViewsMapComponent_o;
};

class CarModelConfig : public AssetBase
{
      friend void serialize_v(osal::InOut& b_IO_ro);
      public:
             CarModelConfig( uint32_t i_Id_u32, const char_t* i_Name_pc )
            : AssetBase()
            {
                  id_u32 = i_Id_u32; 
                  ME_String_Strncpy_v(&name_ac[0], sizeof(name_ac), i_Name_pc, ME_String_CountBytes_s32(i_Name_pc));
            }
            static CarModelConfig* get_po( uint32_t i_Id_u32 )
            {
                  // PRQA S 3076 1 // downcast is intended here
                  return dynamic_cast<CarModelConfig*>(getAssetById_po(i_Id_u32));
            }
            const CarModelConfigComponent* getCarModelConfigComponent_po( ) const { return &carModelConfigComponent_o; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  carModelConfigComponent_o.serialize_v(b_IO_ro);
            }
            CarModelConfigComponent carModelConfigComponent_o;
};

class KinematicModelConfig : public AssetBase
{
      friend void serialize_v(osal::InOut& b_IO_ro);
      public:
             KinematicModelConfig( uint32_t i_Id_u32, const char_t* i_Name_pc )
            : AssetBase()
            {
                  id_u32 = i_Id_u32; 
                  ME_String_Strncpy_v(&name_ac[0], sizeof(name_ac), i_Name_pc, ME_String_CountBytes_s32(i_Name_pc));
            }
            static KinematicModelConfig* get_po( uint32_t i_Id_u32 )
            {
                  // PRQA S 3076 1 // downcast is intended here
                  return dynamic_cast<KinematicModelConfig*>(getAssetById_po(i_Id_u32));
            }
            const KinematicModelComponent* getKinematicModelComponent_po( ) const { return &kinematicModelComponent_o; }
      protected:
            void serialize_v( osal::InOut& b_IO_ro )
            {
                  kinematicModelComponent_o.serialize_v(b_IO_ro);
            }
            KinematicModelComponent kinematicModelComponent_o;
};

const uint32_t c_GDEVariantHeaderVersion_u32 = 0U;
const size_t c_GDEVariantDataSize_t = 16062;

} // namespace variants
#endif // ASSETS

