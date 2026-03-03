
#include "Assets.h"
namespace variants
{
static CameraRadialLens cameraFrontVariant0_o(c_CameraFrontVariant0_u32, "CameraFrontVariant0");
static CameraRadialLens cameraLeftVariant0_o(c_CameraLeftVariant0_u32, "CameraLeftVariant0");
static CameraRadialLens cameraRearVariant0_o(c_CameraRearVariant0_u32, "CameraRearVariant0");
static CameraRadialLens cameraRightVariant0_o(c_CameraRightVariant0_u32, "CameraRightVariant0");
static CameraRadialLens cameraChmslVariant0_o(c_CameraChmslVariant0_u32, "CameraChmslVariant0");
static CameraRadialLens cameraAuxVariant0_o(c_CameraAuxVariant0_u32, "CameraAuxVariant0");
static VehicleData vehicleDataVariant0_o(c_VehicleDataVariant0_u32, "VehicleDataVariant0");
static MirrorObscuration mirrorObscuration_o(c_MirrorObscuration_u32, "MirrorObscuration");
static VariantConfig variantConfig_o(c_VariantConfig_u32, "VariantConfig");
static JobConfig jobConfig_o(c_JobConfig_u32, "JobConfig");
static ErrorManagerConfig errorManagerConfig_o(c_ErrorManagerConfig_u32, "ErrorManagerConfig");
static CameraEOLcalibration eOLCalibFrontVariant0_o(c_EOLCalibFrontVariant0_u32, "EOLCalibFrontVariant0");
static CameraEOLcalibration eOLCalibLeftVariant0_o(c_EOLCalibLeftVariant0_u32, "EOLCalibLeftVariant0");
static CameraEOLcalibration eOLCalibRearVariant0_o(c_EOLCalibRearVariant0_u32, "EOLCalibRearVariant0");
static CameraEOLcalibration eOLCalibRighttVariant0_o(c_EOLCalibRighttVariant0_u32, "EOLCalibRighttVariant0");
static CameraEOLcalibration eOLCalibChmslVariant0_o(c_EOLCalibChmslVariant0_u32, "EOLCalibChmslVariant0");
static CameraOCcalibration oCFrontVariant0_o(c_OCFrontVariant0_u32, "OCFrontVariant0");
static CameraOCcalibration oCLeftVariant0_o(c_OCLeftVariant0_u32, "OCLeftVariant0");
static CameraOCcalibration oCRearVariant0_o(c_OCRearVariant0_u32, "OCRearVariant0");
static CameraOCcalibration oCRightvariant0_o(c_OCRightvariant0_u32, "OCRightvariant0");
static KinematicsOC oCKinematics_o(c_OCKinematics_u32, "OCKinematics");
static CameraOCcalibration oCChmslVariant0_o(c_OCChmslVariant0_u32, "OCChmslVariant0");
static CameraSCcalibration sCCalibFrontVariant0_o(c_SCCalibFrontVariant0_u32, "SCCalibFrontVariant0");
static CameraSCcalibration sCCalibLeftVariant0_o(c_SCCalibLeftVariant0_u32, "SCCalibLeftVariant0");
static CameraSCcalibration sCCalibRearVariant0_o(c_SCCalibRearVariant0_u32, "SCCalibRearVariant0");
static CameraSCcalibration sCCalibRightVariant0_o(c_SCCalibRightVariant0_u32, "SCCalibRightVariant0");
static CameraSCcalibration sCCalibChmslVariant0_o(c_SCCalibChmslVariant0_u32, "SCCalibChmslVariant0");
static ScreenConfig screenConfig_o(c_ScreenConfig_u32, "ScreenConfig");
static SingleView singleViewFullFront_o(c_SingleViewFullFront_u32, "SingleViewFullFront");
static SingleView singleViewFullRearWide_o(c_SingleViewFullRearWide_u32, "SingleViewFullRearWide");
static SingleView singleViewFullRearNarrow_o(c_SingleViewFullRearNarrow_u32, "SingleViewFullRearNarrow");
static SingleView singleViewFullRearHitch_o(c_SingleViewFullRearHitch_u32, "SingleViewFullRearHitch");
static SingleView singleViewTopPrimaryFront_o(c_SingleViewTopPrimaryFront_u32, "SingleViewTopPrimaryFront");
static SingleView singleViewTopPrimaryRear_o(c_SingleViewTopPrimaryRear_u32, "SingleViewTopPrimaryRear");
static SingleView singleViewTopAllFront_o(c_SingleViewTopAllFront_u32, "SingleViewTopAllFront");
static SingleView singleViewTopAllLeft_o(c_SingleViewTopAllLeft_u32, "SingleViewTopAllLeft");
static SingleView singleViewTopAllRear_o(c_SingleViewTopAllRear_u32, "SingleViewTopAllRear");
static SingleView singleViewTopAllRight_o(c_SingleViewTopAllRight_u32, "SingleViewTopAllRight");
static SingleView singleViewTopFlFront_o(c_SingleViewTopFlFront_u32, "SingleViewTopFlFront");
static SingleView singleViewTopFrFront_o(c_SingleViewTopFrFront_u32, "SingleViewTopFrFront");
static SingleView singleViewTopFlLeft_o(c_SingleViewTopFlLeft_u32, "SingleViewTopFlLeft");
static SingleView singleViewTopRlLeft_o(c_SingleViewTopRlLeft_u32, "SingleViewTopRlLeft");
static SingleView singleViewTopRlRear_o(c_SingleViewTopRlRear_u32, "SingleViewTopRlRear");
static SingleView singleViewTopRrRear_o(c_SingleViewTopRrRear_u32, "SingleViewTopRrRear");
static SingleView singleViewTopFrRight_o(c_SingleViewTopFrRight_u32, "SingleViewTopFrRight");
static SingleView singleViewTopRrRight_o(c_SingleViewTopRrRight_u32, "SingleViewTopRrRight");
static SingleView singleViewFrontSplitLeft_o(c_SingleViewFrontSplitLeft_u32, "SingleViewFrontSplitLeft");
static SingleView singleViewFrontSplitRight_o(c_SingleViewFrontSplitRight_u32, "SingleViewFrontSplitRight");
static SingleView singleViewBed_o(c_SingleViewBed_u32, "SingleViewBed");
static SingleView singleViewAux_o(c_SingleViewAux_u32, "SingleViewAux");
static SingleView singleViewRearSplitCenterLeft_o(c_SingleViewRearSplitCenterLeft_u32, "SingleViewRearSplitCenterLeft");
static SingleView singleViewRearSplitCenterRight_o(c_SingleViewRearSplitCenterRight_u32, "SingleViewRearSplitCenterRight");
static SingleView singleViewRearSplitRightLeft_o(c_SingleViewRearSplitRightLeft_u32, "SingleViewRearSplitRightLeft");
static SingleView singleViewRearSplitRightRight_o(c_SingleViewRearSplitRightRight_u32, "SingleViewRearSplitRightRight");
static SingleView singleViewRearSplitLeftLeft_o(c_SingleViewRearSplitLeftLeft_u32, "SingleViewRearSplitLeftLeft");
static SingleView singleViewRearSplitLeftRight_o(c_SingleViewRearSplitLeftRight_u32, "SingleViewRearSplitLeftRight");
static SingleView singleViewRearSplitFarLeft_o(c_SingleViewRearSplitFarLeft_u32, "SingleViewRearSplitFarLeft");
static SingleView singleViewRearSplitFarRight_o(c_SingleViewRearSplitFarRight_u32, "SingleViewRearSplitFarRight");
static SingleView singleViewMtmFrontSideOverallLeft_o(c_SingleViewMtmFrontSideOverallLeft_u32, "SingleViewMtmFrontSideOverallLeft");
static SingleView singleViewMtmFrontSideOverallCenter_o(c_SingleViewMtmFrontSideOverallCenter_u32, "SingleViewMtmFrontSideOverallCenter");
static SingleView singleViewMtmFrontSideOverallRight_o(c_SingleViewMtmFrontSideOverallRight_u32, "SingleViewMtmFrontSideOverallRight");
static SingleView singleViewMtmFrontSideLeft_o(c_SingleViewMtmFrontSideLeft_u32, "SingleViewMtmFrontSideLeft");
static SingleView singleViewMtmFrontSideCenter_o(c_SingleViewMtmFrontSideCenter_u32, "SingleViewMtmFrontSideCenter");
static SingleView singleViewMtmFrontSideRight_o(c_SingleViewMtmFrontSideRight_u32, "SingleViewMtmFrontSideRight");
static SingleView singleViewMtmRearSideOverallLeft_o(c_SingleViewMtmRearSideOverallLeft_u32, "SingleViewMtmRearSideOverallLeft");
static SingleView singleViewMtmRearSideOverallCenter_o(c_SingleViewMtmRearSideOverallCenter_u32, "SingleViewMtmRearSideOverallCenter");
static SingleView singleViewMtmRearSideOverallRight_o(c_SingleViewMtmRearSideOverallRight_u32, "SingleViewMtmRearSideOverallRight");
static SingleView singleViewMtmRearFull_o(c_SingleViewMtmRearFull_u32, "SingleViewMtmRearFull");
static SingleView singleViewQuadFront_o(c_SingleViewQuadFront_u32, "SingleViewQuadFront");
static SingleView singleViewQuadLeft_o(c_SingleViewQuadLeft_u32, "SingleViewQuadLeft");
static SingleView singleViewQuadRear_o(c_SingleViewQuadRear_u32, "SingleViewQuadRear");
static SingleView singleViewQuadRight_o(c_SingleViewQuadRight_u32, "SingleViewQuadRight");
static SingleView singleViewTopAllFrontCalibration_o(c_SingleViewTopAllFrontCalibration_u32, "SingleViewTopAllFrontCalibration");
static SingleView singleViewTopAllLeftCalibration_o(c_SingleViewTopAllLeftCalibration_u32, "SingleViewTopAllLeftCalibration");
static SingleView singleViewTopAllRearCalibration_o(c_SingleViewTopAllRearCalibration_u32, "SingleViewTopAllRearCalibration");
static SingleView singleViewTopAllRightCalibration_o(c_SingleViewTopAllRightCalibration_u32, "SingleViewTopAllRightCalibration");
static SingleView singleViewMtmUnderfloorSideOverallCenterHistoric_o(c_SingleViewMtmUnderfloorSideOverallCenterHistoric_u32, "SingleViewMtmUnderfloorSideOverallCenterHistoric");
static SingleView singleViewMtmUnderfloorSideOverallCenterFront_o(c_SingleViewMtmUnderfloorSideOverallCenterFront_u32, "SingleViewMtmUnderfloorSideOverallCenterFront");
static SingleView singleViewMtmUnderfloorSideOverallCenterLeft_o(c_SingleViewMtmUnderfloorSideOverallCenterLeft_u32, "SingleViewMtmUnderfloorSideOverallCenterLeft");
static SingleView singleViewMtmUnderfloorSideOverallCenterRight_o(c_SingleViewMtmUnderfloorSideOverallCenterRight_u32, "SingleViewMtmUnderfloorSideOverallCenterRight");
static SingleView singleViewMtmUnderfloorSideCenterHistoric_o(c_SingleViewMtmUnderfloorSideCenterHistoric_u32, "SingleViewMtmUnderfloorSideCenterHistoric");
static SingleView singleViewMtmUnderfloorSideCenterFront_o(c_SingleViewMtmUnderfloorSideCenterFront_u32, "SingleViewMtmUnderfloorSideCenterFront");
static SingleView singleViewMtmUnderfloorSideCenterLeft_o(c_SingleViewMtmUnderfloorSideCenterLeft_u32, "SingleViewMtmUnderfloorSideCenterLeft");
static SingleView singleViewMtmUnderfloorSideCenterRight_o(c_SingleViewMtmUnderfloorSideCenterRight_u32, "SingleViewMtmUnderfloorSideCenterRight");
static SingleView singleViewRawFront_o(c_SingleViewRawFront_u32, "SingleViewRawFront");
static SingleView singleViewRawLeft_o(c_SingleViewRawLeft_u32, "SingleViewRawLeft");
static SingleView singleViewRawRear_o(c_SingleViewRawRear_u32, "SingleViewRawRear");
static SingleView singleViewRawRight_o(c_SingleViewRawRight_u32, "SingleViewRawRight");
static SingleView singleViewRawChmsl_o(c_SingleViewRawChmsl_u32, "SingleViewRawChmsl");
static VirtualCameraStretchLens virtualCameraFullFront_o(c_VirtualCameraFullFront_u32, "VirtualCameraFullFront");
static VirtualCameraStretchLens virtualCameraFullRearWide_o(c_VirtualCameraFullRearWide_u32, "VirtualCameraFullRearWide");
static VirtualCameraStretchLens virtualCameraFullRearNarrow_o(c_VirtualCameraFullRearNarrow_u32, "VirtualCameraFullRearNarrow");
static VirtualCameraNoLens virtualCameraFullRearHitch_o(c_VirtualCameraFullRearHitch_u32, "VirtualCameraFullRearHitch");
static VirtualCameraStretchLens virtualCameraTopPrimaryFront_o(c_VirtualCameraTopPrimaryFront_u32, "VirtualCameraTopPrimaryFront");
static VirtualCameraStretchLens virtualCameraTopPrimaryRear_o(c_VirtualCameraTopPrimaryRear_u32, "VirtualCameraTopPrimaryRear");
static VirtualCameraNoLens virtualCameraTopAll_o(c_VirtualCameraTopAll_u32, "VirtualCameraTopAll");
static VirtualCameraNoLens virtualCameraTopFl_o(c_VirtualCameraTopFl_u32, "VirtualCameraTopFl");
static VirtualCameraNoLens virtualCameraTopFr_o(c_VirtualCameraTopFr_u32, "VirtualCameraTopFr");
static VirtualCameraNoLens virtualCameraTopRl_o(c_VirtualCameraTopRl_u32, "VirtualCameraTopRl");
static VirtualCameraNoLens virtualCameraTopRr_o(c_VirtualCameraTopRr_u32, "VirtualCameraTopRr");
static VirtualCameraNoLens virtualCameraFrontSplitLeft_o(c_VirtualCameraFrontSplitLeft_u32, "VirtualCameraFrontSplitLeft");
static VirtualCameraNoLens virtualCameraFrontSplitRight_o(c_VirtualCameraFrontSplitRight_u32, "VirtualCameraFrontSplitRight");
static VirtualCameraRadialLens virtualCameraBed_o(c_VirtualCameraBed_u32, "VirtualCameraBed");
static VirtualCameraRadialLens virtualCameraAux_o(c_VirtualCameraAux_u32, "VirtualCameraAux");
static VirtualCameraNoLens virtualCameraRearSplitCenterLeft_o(c_VirtualCameraRearSplitCenterLeft_u32, "VirtualCameraRearSplitCenterLeft");
static VirtualCameraNoLens virtualCameraRearSplitCenterRight_o(c_VirtualCameraRearSplitCenterRight_u32, "VirtualCameraRearSplitCenterRight");
static VirtualCameraNoLens virtualCameraRearSplitRightLeft_o(c_VirtualCameraRearSplitRightLeft_u32, "VirtualCameraRearSplitRightLeft");
static VirtualCameraNoLens virtualCameraRearSplitRightRight_o(c_VirtualCameraRearSplitRightRight_u32, "VirtualCameraRearSplitRightRight");
static VirtualCameraNoLens virtualCameraRearSplitLeftLeft_o(c_VirtualCameraRearSplitLeftLeft_u32, "VirtualCameraRearSplitLeftLeft");
static VirtualCameraNoLens virtualCameraRearSplitLeftRight_o(c_VirtualCameraRearSplitLeftRight_u32, "VirtualCameraRearSplitLeftRight");
static VirtualCameraNoLens virtualCameraRearSplitFarLeft_o(c_VirtualCameraRearSplitFarLeft_u32, "VirtualCameraRearSplitFarLeft");
static VirtualCameraNoLens virtualCameraRearSplitFarRight_o(c_VirtualCameraRearSplitFarRight_u32, "VirtualCameraRearSplitFarRight");
static VirtualCameraNoLens virtualCameraMtmFrontSideOverallLeft_o(c_VirtualCameraMtmFrontSideOverallLeft_u32, "VirtualCameraMtmFrontSideOverallLeft");
static VirtualCameraCylinderLens virtualCameraMtmFrontSideOverallCenter_o(c_VirtualCameraMtmFrontSideOverallCenter_u32, "VirtualCameraMtmFrontSideOverallCenter");
static VirtualCameraNoLens virtualCameraMtmFrontSideOverallRight_o(c_VirtualCameraMtmFrontSideOverallRight_u32, "VirtualCameraMtmFrontSideOverallRight");
static VirtualCameraNoLens virtualCameraMtmFrontSideLeft_o(c_VirtualCameraMtmFrontSideLeft_u32, "VirtualCameraMtmFrontSideLeft");
static VirtualCameraCylinderLens virtualCameraMtmFrontSideCenter_o(c_VirtualCameraMtmFrontSideCenter_u32, "VirtualCameraMtmFrontSideCenter");
static VirtualCameraNoLens virtualCameraMtmFrontSideRight_o(c_VirtualCameraMtmFrontSideRight_u32, "VirtualCameraMtmFrontSideRight");
static VirtualCameraNoLens virtualCameraMtmRearSideOverallLeft_o(c_VirtualCameraMtmRearSideOverallLeft_u32, "VirtualCameraMtmRearSideOverallLeft");
static VirtualCameraStretchLens virtualCameraMtmRearSideOverallCenter_o(c_VirtualCameraMtmRearSideOverallCenter_u32, "VirtualCameraMtmRearSideOverallCenter");
static VirtualCameraNoLens virtualCameraMtmRearSideOverallRight_o(c_VirtualCameraMtmRearSideOverallRight_u32, "VirtualCameraMtmRearSideOverallRight");
static VirtualCameraStretchLens virtualCameraMtmRearFull_o(c_VirtualCameraMtmRearFull_u32, "VirtualCameraMtmRearFull");
static VirtualCameraRadialLens virtualCameraMtmUnderfloorSideOverallCenter_o(c_VirtualCameraMtmUnderfloorSideOverallCenter_u32, "VirtualCameraMtmUnderfloorSideOverallCenter");
static VirtualCameraRadialLens virtualCameraMtmUnderfloorSideCenter_o(c_VirtualCameraMtmUnderfloorSideCenter_u32, "VirtualCameraMtmUnderfloorSideCenter");
static VirtualCameraNoLens virtualCameraQuadFront_o(c_VirtualCameraQuadFront_u32, "VirtualCameraQuadFront");
static VirtualCameraNoLens virtualCameraQuadLeft_o(c_VirtualCameraQuadLeft_u32, "VirtualCameraQuadLeft");
static VirtualCameraNoLens virtualCameraQuadRear_o(c_VirtualCameraQuadRear_u32, "VirtualCameraQuadRear");
static VirtualCameraNoLens virtualCameraQuadRight_o(c_VirtualCameraQuadRight_u32, "VirtualCameraQuadRight");
static VirtualCameraNoLens virtualCameraTopAllCalibration_o(c_VirtualCameraTopAllCalibration_u32, "VirtualCameraTopAllCalibration");
static VirtualCameraNoLens virtualCameraRawFront_o(c_VirtualCameraRawFront_u32, "VirtualCameraRawFront");
static VirtualCameraNoLens virtualCameraRawLeft_o(c_VirtualCameraRawLeft_u32, "VirtualCameraRawLeft");
static VirtualCameraNoLens virtualCameraRawRear_o(c_VirtualCameraRawRear_u32, "VirtualCameraRawRear");
static VirtualCameraNoLens virtualCameraRawRight_o(c_VirtualCameraRawRight_u32, "VirtualCameraRawRight");
static VirtualCameraNoLens virtualCameraRawChmsl_o(c_VirtualCameraRawChmsl_u32, "VirtualCameraRawChmsl");
static CombinedView combinedViewFrontTopAll_o(c_CombinedViewFrontTopAll_u32, "CombinedViewFrontTopAll");
static CombinedView combinedViewFrontTopFl_o(c_CombinedViewFrontTopFl_u32, "CombinedViewFrontTopFl");
static CombinedView combinedViewFrontTopFr_o(c_CombinedViewFrontTopFr_u32, "CombinedViewFrontTopFr");
static CombinedView combinedViewFrontTopRl_o(c_CombinedViewFrontTopRl_u32, "CombinedViewFrontTopRl");
static CombinedView combinedViewFrontTopRr_o(c_CombinedViewFrontTopRr_u32, "CombinedViewFrontTopRr");
static CombinedView combinedViewFrontSplitTopAll_o(c_CombinedViewFrontSplitTopAll_u32, "CombinedViewFrontSplitTopAll");
static CombinedView combinedViewFrontSplitTopFl_o(c_CombinedViewFrontSplitTopFl_u32, "CombinedViewFrontSplitTopFl");
static CombinedView combinedViewFrontSplitTopFr_o(c_CombinedViewFrontSplitTopFr_u32, "CombinedViewFrontSplitTopFr");
static CombinedView combinedViewFrontSplitTopRl_o(c_CombinedViewFrontSplitTopRl_u32, "CombinedViewFrontSplitTopRl");
static CombinedView combinedViewFrontSplitTopRr_o(c_CombinedViewFrontSplitTopRr_u32, "CombinedViewFrontSplitTopRr");
static CombinedView combinedViewRearTopAll_o(c_CombinedViewRearTopAll_u32, "CombinedViewRearTopAll");
static CombinedView combinedViewRearTopFl_o(c_CombinedViewRearTopFl_u32, "CombinedViewRearTopFl");
static CombinedView combinedViewRearTopFr_o(c_CombinedViewRearTopFr_u32, "CombinedViewRearTopFr");
static CombinedView combinedViewRearTopRl_o(c_CombinedViewRearTopRl_u32, "CombinedViewRearTopRl");
static CombinedView combinedViewRearTopRr_o(c_CombinedViewRearTopRr_u32, "CombinedViewRearTopRr");
static CombinedView combinedViewRearSplitCenterTopAll_o(c_CombinedViewRearSplitCenterTopAll_u32, "CombinedViewRearSplitCenterTopAll");
static CombinedView combinedViewRearSplitCenterTopFl_o(c_CombinedViewRearSplitCenterTopFl_u32, "CombinedViewRearSplitCenterTopFl");
static CombinedView combinedViewRearSplitCenterTopFr_o(c_CombinedViewRearSplitCenterTopFr_u32, "CombinedViewRearSplitCenterTopFr");
static CombinedView combinedViewRearSplitCenterTopRl_o(c_CombinedViewRearSplitCenterTopRl_u32, "CombinedViewRearSplitCenterTopRl");
static CombinedView combinedViewRearSplitCenterTopRr_o(c_CombinedViewRearSplitCenterTopRr_u32, "CombinedViewRearSplitCenterTopRr");
static CombinedView combinedViewRearSplitRightTopAll_o(c_CombinedViewRearSplitRightTopAll_u32, "CombinedViewRearSplitRightTopAll");
static CombinedView combinedViewRearSplitRightTopFl_o(c_CombinedViewRearSplitRightTopFl_u32, "CombinedViewRearSplitRightTopFl");
static CombinedView combinedViewRearSplitRightTopFr_o(c_CombinedViewRearSplitRightTopFr_u32, "CombinedViewRearSplitRightTopFr");
static CombinedView combinedViewRearSplitRightTopRl_o(c_CombinedViewRearSplitRightTopRl_u32, "CombinedViewRearSplitRightTopRl");
static CombinedView combinedViewRearSplitRightTopRr_o(c_CombinedViewRearSplitRightTopRr_u32, "CombinedViewRearSplitRightTopRr");
static CombinedView combinedViewRearSplitFarRightTopAll_o(c_CombinedViewRearSplitFarRightTopAll_u32, "CombinedViewRearSplitFarRightTopAll");
static CombinedView combinedViewRearSplitFarRightTopFl_o(c_CombinedViewRearSplitFarRightTopFl_u32, "CombinedViewRearSplitFarRightTopFl");
static CombinedView combinedViewRearSplitFarRightTopFr_o(c_CombinedViewRearSplitFarRightTopFr_u32, "CombinedViewRearSplitFarRightTopFr");
static CombinedView combinedViewRearSplitFarRightTopRl_o(c_CombinedViewRearSplitFarRightTopRl_u32, "CombinedViewRearSplitFarRightTopRl");
static CombinedView combinedViewRearSplitFarRightTopRr_o(c_CombinedViewRearSplitFarRightTopRr_u32, "CombinedViewRearSplitFarRightTopRr");
static CombinedView combinedViewRearSplitLeftTopAll_o(c_CombinedViewRearSplitLeftTopAll_u32, "CombinedViewRearSplitLeftTopAll");
static CombinedView combinedViewRearSplitLeftTopFl_o(c_CombinedViewRearSplitLeftTopFl_u32, "CombinedViewRearSplitLeftTopFl");
static CombinedView combinedViewRearSplitLeftTopFr_o(c_CombinedViewRearSplitLeftTopFr_u32, "CombinedViewRearSplitLeftTopFr");
static CombinedView combinedViewRearSplitLeftTopRl_o(c_CombinedViewRearSplitLeftTopRl_u32, "CombinedViewRearSplitLeftTopRl");
static CombinedView combinedViewRearSplitLeftTopRr_o(c_CombinedViewRearSplitLeftTopRr_u32, "CombinedViewRearSplitLeftTopRr");
static CombinedView combinedViewRearSplitFarLeftTopAll_o(c_CombinedViewRearSplitFarLeftTopAll_u32, "CombinedViewRearSplitFarLeftTopAll");
static CombinedView combinedViewRearSplitFarLeftTopFl_o(c_CombinedViewRearSplitFarLeftTopFl_u32, "CombinedViewRearSplitFarLeftTopFl");
static CombinedView combinedViewRearSplitFarLeftTopFr_o(c_CombinedViewRearSplitFarLeftTopFr_u32, "CombinedViewRearSplitFarLeftTopFr");
static CombinedView combinedViewRearSplitFarLeftTopRl_o(c_CombinedViewRearSplitFarLeftTopRl_u32, "CombinedViewRearSplitFarLeftTopRl");
static CombinedView combinedViewRearSplitFarLeftTopRr_o(c_CombinedViewRearSplitFarLeftTopRr_u32, "CombinedViewRearSplitFarLeftTopRr");
static CombinedView combinedViewFrontFull_o(c_CombinedViewFrontFull_u32, "CombinedViewFrontFull");
static CombinedView combinedViewRearFullWide_o(c_CombinedViewRearFullWide_u32, "CombinedViewRearFullWide");
static CombinedView combinedViewRearFullNarrow_o(c_CombinedViewRearFullNarrow_u32, "CombinedViewRearFullNarrow");
static CombinedView combinedViewRearFullHitch_o(c_CombinedViewRearFullHitch_u32, "CombinedViewRearFullHitch");
static CombinedView combinedViewBedSt_o(c_CombinedViewBedSt_u32, "CombinedViewBedSt");
static CombinedView combinedViewMtmFrontSideOverall_o(c_CombinedViewMtmFrontSideOverall_u32, "CombinedViewMtmFrontSideOverall");
static CombinedView combinedViewMtmFrontSide_o(c_CombinedViewMtmFrontSide_u32, "CombinedViewMtmFrontSide");
static CombinedView combinedViewMtmUnderfloorSideOverall_o(c_CombinedViewMtmUnderfloorSideOverall_u32, "CombinedViewMtmUnderfloorSideOverall");
static CombinedView combinedViewMtmUnderfloorSide_o(c_CombinedViewMtmUnderfloorSide_u32, "CombinedViewMtmUnderfloorSide");
static CombinedView combinedViewMtmRearSideOverall_o(c_CombinedViewMtmRearSideOverall_u32, "CombinedViewMtmRearSideOverall");
static CombinedView combinedViewMtmRearFull_o(c_CombinedViewMtmRearFull_u32, "CombinedViewMtmRearFull");
static CombinedView combinedViewNoView_o(c_CombinedViewNoView_u32, "CombinedViewNoView");
static CombinedView combinedViewQuad_o(c_CombinedViewQuad_u32, "CombinedViewQuad");
static CombinedView combinedViewTopAllCalibration_o(c_CombinedViewTopAllCalibration_u32, "CombinedViewTopAllCalibration");
static CombinedView combinedViewRawFront_o(c_CombinedViewRawFront_u32, "CombinedViewRawFront");
static CombinedView combinedViewRawLeft_o(c_CombinedViewRawLeft_u32, "CombinedViewRawLeft");
static CombinedView combinedViewRawRear_o(c_CombinedViewRawRear_u32, "CombinedViewRawRear");
static CombinedView combinedViewRawRight_o(c_CombinedViewRawRight_u32, "CombinedViewRawRight");
static CombinedView combinedViewRawChmsl_o(c_CombinedViewRawChmsl_u32, "CombinedViewRawChmsl");
static PixelArea pixelAreaFull_o(c_PixelAreaFull_u32, "PixelAreaFull");
static PixelArea pixelAreaTopAll_o(c_PixelAreaTopAll_u32, "PixelAreaTopAll");
static PixelArea pixelAreaTopAllFront_o(c_PixelAreaTopAllFront_u32, "PixelAreaTopAllFront");
static PixelArea pixelAreaTopAllLeft_o(c_PixelAreaTopAllLeft_u32, "PixelAreaTopAllLeft");
static PixelArea pixelAreaTopAllRear_o(c_PixelAreaTopAllRear_u32, "PixelAreaTopAllRear");
static PixelArea pixelAreaTopAllRight_o(c_PixelAreaTopAllRight_u32, "PixelAreaTopAllRight");
static PixelArea pixelAreaTopZoomFront_o(c_PixelAreaTopZoomFront_u32, "PixelAreaTopZoomFront");
static PixelArea pixelAreaTopZoomLeft_o(c_PixelAreaTopZoomLeft_u32, "PixelAreaTopZoomLeft");
static PixelArea pixelAreaTopZoomRear_o(c_PixelAreaTopZoomRear_u32, "PixelAreaTopZoomRear");
static PixelArea pixelAreaTopZoomRight_o(c_PixelAreaTopZoomRight_u32, "PixelAreaTopZoomRight");
static PixelArea pixelAreaTopPrimary_o(c_PixelAreaTopPrimary_u32, "PixelAreaTopPrimary");
static PixelArea pixelAreaSplitCenterLeft_o(c_PixelAreaSplitCenterLeft_u32, "PixelAreaSplitCenterLeft");
static PixelArea pixelAreaSplitCenterRight_o(c_PixelAreaSplitCenterRight_u32, "PixelAreaSplitCenterRight");
static PixelArea pixelAreaSplitRightLeft_o(c_PixelAreaSplitRightLeft_u32, "PixelAreaSplitRightLeft");
static PixelArea pixelAreaSplitRightRight_o(c_PixelAreaSplitRightRight_u32, "PixelAreaSplitRightRight");
static PixelArea pixelAreaSplitLeftLeft_o(c_PixelAreaSplitLeftLeft_u32, "PixelAreaSplitLeftLeft");
static PixelArea pixelAreaSplitLeftRight_o(c_PixelAreaSplitLeftRight_u32, "PixelAreaSplitLeftRight");
static PixelArea pixelAreaMtmSideOverallLeft_o(c_PixelAreaMtmSideOverallLeft_u32, "PixelAreaMtmSideOverallLeft");
static PixelArea pixelAreaMtmSideOverallCenter_o(c_PixelAreaMtmSideOverallCenter_u32, "PixelAreaMtmSideOverallCenter");
static PixelArea pixelAreaMtmSideOverallRight_o(c_PixelAreaMtmSideOverallRight_u32, "PixelAreaMtmSideOverallRight");
static PixelArea pixelAreaMtmSideLeft_o(c_PixelAreaMtmSideLeft_u32, "PixelAreaMtmSideLeft");
static PixelArea pixelAreaMtmSideCenter_o(c_PixelAreaMtmSideCenter_u32, "PixelAreaMtmSideCenter");
static PixelArea pixelAreaMtmSideRight_o(c_PixelAreaMtmSideRight_u32, "PixelAreaMtmSideRight");
static PixelArea pixelAreaMtmFull_o(c_PixelAreaMtmFull_u32, "PixelAreaMtmFull");
static PixelArea pixelAreaQuadTop_o(c_PixelAreaQuadTop_u32, "PixelAreaQuadTop");
static PixelArea pixelAreaQuadFront_o(c_PixelAreaQuadFront_u32, "PixelAreaQuadFront");
static PixelArea pixelAreaQuadLeft_o(c_PixelAreaQuadLeft_u32, "PixelAreaQuadLeft");
static PixelArea pixelAreaQuadRear_o(c_PixelAreaQuadRear_u32, "PixelAreaQuadRear");
static PixelArea pixelAreaQuadRight_o(c_PixelAreaQuadRight_u32, "PixelAreaQuadRight");
static PixelArea pixelAreaTopAllCalibration_o(c_PixelAreaTopAllCalibration_u32, "PixelAreaTopAllCalibration");
static PixelArea pixelAreaTopAllFrontCalibration_o(c_PixelAreaTopAllFrontCalibration_u32, "PixelAreaTopAllFrontCalibration");
static PixelArea pixelAreaTopAllLeftCalibration_o(c_PixelAreaTopAllLeftCalibration_u32, "PixelAreaTopAllLeftCalibration");
static PixelArea pixelAreaTopAllRearCalibration_o(c_PixelAreaTopAllRearCalibration_u32, "PixelAreaTopAllRearCalibration");
static PixelArea pixelAreaTopAllRightCalibration_o(c_PixelAreaTopAllRightCalibration_u32, "PixelAreaTopAllRightCalibration");
static PixelArea pixelAreaRaw_o(c_PixelAreaRaw_u32, "PixelAreaRaw");
static PixelArea pixelAreaQuadBottom_o(c_PixelAreaQuadBottom_u32, "PixelAreaQuadBottom");
static PixelArea pixelAreaMtmSideOverallCenterHistoric_o(c_PixelAreaMtmSideOverallCenterHistoric_u32, "PixelAreaMtmSideOverallCenterHistoric");
static PixelArea pixelAreaMtmSideOverallCenterFront_o(c_PixelAreaMtmSideOverallCenterFront_u32, "PixelAreaMtmSideOverallCenterFront");
static PixelArea pixelAreaMtmSideOverallCenterLeft_o(c_PixelAreaMtmSideOverallCenterLeft_u32, "PixelAreaMtmSideOverallCenterLeft");
static PixelArea pixelAreaMtmSideOverallCenterRight_o(c_PixelAreaMtmSideOverallCenterRight_u32, "PixelAreaMtmSideOverallCenterRight");
static PixelArea pixelAreaMtmSideCenterHistoric_o(c_PixelAreaMtmSideCenterHistoric_u32, "PixelAreaMtmSideCenterHistoric");
static PixelArea pixelAreaMtmSideCenterFront_o(c_PixelAreaMtmSideCenterFront_u32, "PixelAreaMtmSideCenterFront");
static PixelArea pixelAreaMtmSideCenterLeft_o(c_PixelAreaMtmSideCenterLeft_u32, "PixelAreaMtmSideCenterLeft");
static PixelArea pixelAreaMtmSideCenterRight_o(c_PixelAreaMtmSideCenterRight_u32, "PixelAreaMtmSideCenterRight");
static StitchParams stitchParamsTopAllFrontLeft_o(c_StitchParamsTopAllFrontLeft_u32, "StitchParamsTopAllFrontLeft");
static StitchParams stitchParamsTopAllFrontRight_o(c_StitchParamsTopAllFrontRight_u32, "StitchParamsTopAllFrontRight");
static StitchParams stitchParamsTopAllRearLeft_o(c_StitchParamsTopAllRearLeft_u32, "StitchParamsTopAllRearLeft");
static StitchParams stitchParamsTopAllRearRight_o(c_StitchParamsTopAllRearRight_u32, "StitchParamsTopAllRearRight");
static StitchParams stitchParamsTopZoomFrontLeft_o(c_StitchParamsTopZoomFrontLeft_u32, "StitchParamsTopZoomFrontLeft");
static StitchParams stitchParamsTopZoomFrontRight_o(c_StitchParamsTopZoomFrontRight_u32, "StitchParamsTopZoomFrontRight");
static StitchParams stitchParamsTopZoomRearLeft_o(c_StitchParamsTopZoomRearLeft_u32, "StitchParamsTopZoomRearLeft");
static StitchParams stitchParamsTopZoomRearRight_o(c_StitchParamsTopZoomRearRight_u32, "StitchParamsTopZoomRearRight");
static StitchParams stitchParamsTopAllFrontLeftCalibration_o(c_StitchParamsTopAllFrontLeftCalibration_u32, "StitchParamsTopAllFrontLeftCalibration");
static StitchParams stitchParamsTopAllFrontRightCalibration_o(c_StitchParamsTopAllFrontRightCalibration_u32, "StitchParamsTopAllFrontRightCalibration");
static StitchParams stitchParamsTopAllRearLeftCalibration_o(c_StitchParamsTopAllRearLeftCalibration_u32, "StitchParamsTopAllRearLeftCalibration");
static StitchParams stitchParamsTopAllRearRightCalibration_o(c_StitchParamsTopAllRearRightCalibration_u32, "StitchParamsTopAllRearRightCalibration");
static StitchParams stitchParamsMtmSideOverallCenterFrontLeft_o(c_StitchParamsMtmSideOverallCenterFrontLeft_u32, "StitchParamsMtmSideOverallCenterFrontLeft");
static StitchParams stitchParamsMtmSideOverallCenterFrontRight_o(c_StitchParamsMtmSideOverallCenterFrontRight_u32, "StitchParamsMtmSideOverallCenterFrontRight");
static StitchParams stitchParamsMtmSideOverallCenterHistoricLeft_o(c_StitchParamsMtmSideOverallCenterHistoricLeft_u32, "StitchParamsMtmSideOverallCenterHistoricLeft");
static StitchParams stitchParamsMtmSideOverallCenterHistoricRight_o(c_StitchParamsMtmSideOverallCenterHistoricRight_u32, "StitchParamsMtmSideOverallCenterHistoricRight");
static StitchParams stitchParamsMtmSideCenterFrontLeft_o(c_StitchParamsMtmSideCenterFrontLeft_u32, "StitchParamsMtmSideCenterFrontLeft");
static StitchParams stitchParamsMtmSideCenterFrontRight_o(c_StitchParamsMtmSideCenterFrontRight_u32, "StitchParamsMtmSideCenterFrontRight");
static StitchParams stitchParamsMtmSideCenterHistoricLeft_o(c_StitchParamsMtmSideCenterHistoricLeft_u32, "StitchParamsMtmSideCenterHistoricLeft");
static StitchParams stitchParamsMtmSideCenterHistoricRight_o(c_StitchParamsMtmSideCenterHistoricRight_u32, "StitchParamsMtmSideCenterHistoricRight");
static ViewsMap viewsMap_o(c_ViewsMap_u32, "ViewsMap");
static SingleViewsMap singleViewsMap_o(c_SingleViewsMap_u32, "SingleViewsMap");
static CarModelConfig carModelConfig0_o(c_CarModelConfig0_u32, "CarModelConfig0");
static KinematicModelConfig kinematicModelConfig0_o(c_KinematicModelConfig0_u32, "KinematicModelConfig0");

void serialize_v( osal::InOut& b_IO_ro )
{
      cameraFrontVariant0_o.serialize_v(b_IO_ro);
      cameraLeftVariant0_o.serialize_v(b_IO_ro);
      cameraRearVariant0_o.serialize_v(b_IO_ro);
      cameraRightVariant0_o.serialize_v(b_IO_ro);
      cameraChmslVariant0_o.serialize_v(b_IO_ro);
      cameraAuxVariant0_o.serialize_v(b_IO_ro);
      vehicleDataVariant0_o.serialize_v(b_IO_ro);
      mirrorObscuration_o.serialize_v(b_IO_ro);
      variantConfig_o.serialize_v(b_IO_ro);
      jobConfig_o.serialize_v(b_IO_ro);
      errorManagerConfig_o.serialize_v(b_IO_ro);
      eOLCalibFrontVariant0_o.serialize_v(b_IO_ro);
      eOLCalibLeftVariant0_o.serialize_v(b_IO_ro);
      eOLCalibRearVariant0_o.serialize_v(b_IO_ro);
      eOLCalibRighttVariant0_o.serialize_v(b_IO_ro);
      eOLCalibChmslVariant0_o.serialize_v(b_IO_ro);
      oCFrontVariant0_o.serialize_v(b_IO_ro);
      oCLeftVariant0_o.serialize_v(b_IO_ro);
      oCRearVariant0_o.serialize_v(b_IO_ro);
      oCRightvariant0_o.serialize_v(b_IO_ro);
      oCKinematics_o.serialize_v(b_IO_ro);
      oCChmslVariant0_o.serialize_v(b_IO_ro);
      sCCalibFrontVariant0_o.serialize_v(b_IO_ro);
      sCCalibLeftVariant0_o.serialize_v(b_IO_ro);
      sCCalibRearVariant0_o.serialize_v(b_IO_ro);
      sCCalibRightVariant0_o.serialize_v(b_IO_ro);
      sCCalibChmslVariant0_o.serialize_v(b_IO_ro);
      screenConfig_o.serialize_v(b_IO_ro);
      singleViewFullFront_o.serialize_v(b_IO_ro);
      singleViewFullRearWide_o.serialize_v(b_IO_ro);
      singleViewFullRearNarrow_o.serialize_v(b_IO_ro);
      singleViewFullRearHitch_o.serialize_v(b_IO_ro);
      singleViewTopPrimaryFront_o.serialize_v(b_IO_ro);
      singleViewTopPrimaryRear_o.serialize_v(b_IO_ro);
      singleViewTopAllFront_o.serialize_v(b_IO_ro);
      singleViewTopAllLeft_o.serialize_v(b_IO_ro);
      singleViewTopAllRear_o.serialize_v(b_IO_ro);
      singleViewTopAllRight_o.serialize_v(b_IO_ro);
      singleViewTopFlFront_o.serialize_v(b_IO_ro);
      singleViewTopFrFront_o.serialize_v(b_IO_ro);
      singleViewTopFlLeft_o.serialize_v(b_IO_ro);
      singleViewTopRlLeft_o.serialize_v(b_IO_ro);
      singleViewTopRlRear_o.serialize_v(b_IO_ro);
      singleViewTopRrRear_o.serialize_v(b_IO_ro);
      singleViewTopFrRight_o.serialize_v(b_IO_ro);
      singleViewTopRrRight_o.serialize_v(b_IO_ro);
      singleViewFrontSplitLeft_o.serialize_v(b_IO_ro);
      singleViewFrontSplitRight_o.serialize_v(b_IO_ro);
      singleViewBed_o.serialize_v(b_IO_ro);
      singleViewAux_o.serialize_v(b_IO_ro);
      singleViewRearSplitCenterLeft_o.serialize_v(b_IO_ro);
      singleViewRearSplitCenterRight_o.serialize_v(b_IO_ro);
      singleViewRearSplitRightLeft_o.serialize_v(b_IO_ro);
      singleViewRearSplitRightRight_o.serialize_v(b_IO_ro);
      singleViewRearSplitLeftLeft_o.serialize_v(b_IO_ro);
      singleViewRearSplitLeftRight_o.serialize_v(b_IO_ro);
      singleViewRearSplitFarLeft_o.serialize_v(b_IO_ro);
      singleViewRearSplitFarRight_o.serialize_v(b_IO_ro);
      singleViewMtmFrontSideOverallLeft_o.serialize_v(b_IO_ro);
      singleViewMtmFrontSideOverallCenter_o.serialize_v(b_IO_ro);
      singleViewMtmFrontSideOverallRight_o.serialize_v(b_IO_ro);
      singleViewMtmFrontSideLeft_o.serialize_v(b_IO_ro);
      singleViewMtmFrontSideCenter_o.serialize_v(b_IO_ro);
      singleViewMtmFrontSideRight_o.serialize_v(b_IO_ro);
      singleViewMtmRearSideOverallLeft_o.serialize_v(b_IO_ro);
      singleViewMtmRearSideOverallCenter_o.serialize_v(b_IO_ro);
      singleViewMtmRearSideOverallRight_o.serialize_v(b_IO_ro);
      singleViewMtmRearFull_o.serialize_v(b_IO_ro);
      singleViewQuadFront_o.serialize_v(b_IO_ro);
      singleViewQuadLeft_o.serialize_v(b_IO_ro);
      singleViewQuadRear_o.serialize_v(b_IO_ro);
      singleViewQuadRight_o.serialize_v(b_IO_ro);
      singleViewTopAllFrontCalibration_o.serialize_v(b_IO_ro);
      singleViewTopAllLeftCalibration_o.serialize_v(b_IO_ro);
      singleViewTopAllRearCalibration_o.serialize_v(b_IO_ro);
      singleViewTopAllRightCalibration_o.serialize_v(b_IO_ro);
      singleViewMtmUnderfloorSideOverallCenterHistoric_o.serialize_v(b_IO_ro);
      singleViewMtmUnderfloorSideOverallCenterFront_o.serialize_v(b_IO_ro);
      singleViewMtmUnderfloorSideOverallCenterLeft_o.serialize_v(b_IO_ro);
      singleViewMtmUnderfloorSideOverallCenterRight_o.serialize_v(b_IO_ro);
      singleViewMtmUnderfloorSideCenterHistoric_o.serialize_v(b_IO_ro);
      singleViewMtmUnderfloorSideCenterFront_o.serialize_v(b_IO_ro);
      singleViewMtmUnderfloorSideCenterLeft_o.serialize_v(b_IO_ro);
      singleViewMtmUnderfloorSideCenterRight_o.serialize_v(b_IO_ro);
      singleViewRawFront_o.serialize_v(b_IO_ro);
      singleViewRawLeft_o.serialize_v(b_IO_ro);
      singleViewRawRear_o.serialize_v(b_IO_ro);
      singleViewRawRight_o.serialize_v(b_IO_ro);
      singleViewRawChmsl_o.serialize_v(b_IO_ro);
      virtualCameraFullFront_o.serialize_v(b_IO_ro);
      virtualCameraFullRearWide_o.serialize_v(b_IO_ro);
      virtualCameraFullRearNarrow_o.serialize_v(b_IO_ro);
      virtualCameraFullRearHitch_o.serialize_v(b_IO_ro);
      virtualCameraTopPrimaryFront_o.serialize_v(b_IO_ro);
      virtualCameraTopPrimaryRear_o.serialize_v(b_IO_ro);
      virtualCameraTopAll_o.serialize_v(b_IO_ro);
      virtualCameraTopFl_o.serialize_v(b_IO_ro);
      virtualCameraTopFr_o.serialize_v(b_IO_ro);
      virtualCameraTopRl_o.serialize_v(b_IO_ro);
      virtualCameraTopRr_o.serialize_v(b_IO_ro);
      virtualCameraFrontSplitLeft_o.serialize_v(b_IO_ro);
      virtualCameraFrontSplitRight_o.serialize_v(b_IO_ro);
      virtualCameraBed_o.serialize_v(b_IO_ro);
      virtualCameraAux_o.serialize_v(b_IO_ro);
      virtualCameraRearSplitCenterLeft_o.serialize_v(b_IO_ro);
      virtualCameraRearSplitCenterRight_o.serialize_v(b_IO_ro);
      virtualCameraRearSplitRightLeft_o.serialize_v(b_IO_ro);
      virtualCameraRearSplitRightRight_o.serialize_v(b_IO_ro);
      virtualCameraRearSplitLeftLeft_o.serialize_v(b_IO_ro);
      virtualCameraRearSplitLeftRight_o.serialize_v(b_IO_ro);
      virtualCameraRearSplitFarLeft_o.serialize_v(b_IO_ro);
      virtualCameraRearSplitFarRight_o.serialize_v(b_IO_ro);
      virtualCameraMtmFrontSideOverallLeft_o.serialize_v(b_IO_ro);
      virtualCameraMtmFrontSideOverallCenter_o.serialize_v(b_IO_ro);
      virtualCameraMtmFrontSideOverallRight_o.serialize_v(b_IO_ro);
      virtualCameraMtmFrontSideLeft_o.serialize_v(b_IO_ro);
      virtualCameraMtmFrontSideCenter_o.serialize_v(b_IO_ro);
      virtualCameraMtmFrontSideRight_o.serialize_v(b_IO_ro);
      virtualCameraMtmRearSideOverallLeft_o.serialize_v(b_IO_ro);
      virtualCameraMtmRearSideOverallCenter_o.serialize_v(b_IO_ro);
      virtualCameraMtmRearSideOverallRight_o.serialize_v(b_IO_ro);
      virtualCameraMtmRearFull_o.serialize_v(b_IO_ro);
      virtualCameraMtmUnderfloorSideOverallCenter_o.serialize_v(b_IO_ro);
      virtualCameraMtmUnderfloorSideCenter_o.serialize_v(b_IO_ro);
      virtualCameraQuadFront_o.serialize_v(b_IO_ro);
      virtualCameraQuadLeft_o.serialize_v(b_IO_ro);
      virtualCameraQuadRear_o.serialize_v(b_IO_ro);
      virtualCameraQuadRight_o.serialize_v(b_IO_ro);
      virtualCameraTopAllCalibration_o.serialize_v(b_IO_ro);
      virtualCameraRawFront_o.serialize_v(b_IO_ro);
      virtualCameraRawLeft_o.serialize_v(b_IO_ro);
      virtualCameraRawRear_o.serialize_v(b_IO_ro);
      virtualCameraRawRight_o.serialize_v(b_IO_ro);
      virtualCameraRawChmsl_o.serialize_v(b_IO_ro);
      combinedViewFrontTopAll_o.serialize_v(b_IO_ro);
      combinedViewFrontTopFl_o.serialize_v(b_IO_ro);
      combinedViewFrontTopFr_o.serialize_v(b_IO_ro);
      combinedViewFrontTopRl_o.serialize_v(b_IO_ro);
      combinedViewFrontTopRr_o.serialize_v(b_IO_ro);
      combinedViewFrontSplitTopAll_o.serialize_v(b_IO_ro);
      combinedViewFrontSplitTopFl_o.serialize_v(b_IO_ro);
      combinedViewFrontSplitTopFr_o.serialize_v(b_IO_ro);
      combinedViewFrontSplitTopRl_o.serialize_v(b_IO_ro);
      combinedViewFrontSplitTopRr_o.serialize_v(b_IO_ro);
      combinedViewRearTopAll_o.serialize_v(b_IO_ro);
      combinedViewRearTopFl_o.serialize_v(b_IO_ro);
      combinedViewRearTopFr_o.serialize_v(b_IO_ro);
      combinedViewRearTopRl_o.serialize_v(b_IO_ro);
      combinedViewRearTopRr_o.serialize_v(b_IO_ro);
      combinedViewRearSplitCenterTopAll_o.serialize_v(b_IO_ro);
      combinedViewRearSplitCenterTopFl_o.serialize_v(b_IO_ro);
      combinedViewRearSplitCenterTopFr_o.serialize_v(b_IO_ro);
      combinedViewRearSplitCenterTopRl_o.serialize_v(b_IO_ro);
      combinedViewRearSplitCenterTopRr_o.serialize_v(b_IO_ro);
      combinedViewRearSplitRightTopAll_o.serialize_v(b_IO_ro);
      combinedViewRearSplitRightTopFl_o.serialize_v(b_IO_ro);
      combinedViewRearSplitRightTopFr_o.serialize_v(b_IO_ro);
      combinedViewRearSplitRightTopRl_o.serialize_v(b_IO_ro);
      combinedViewRearSplitRightTopRr_o.serialize_v(b_IO_ro);
      combinedViewRearSplitFarRightTopAll_o.serialize_v(b_IO_ro);
      combinedViewRearSplitFarRightTopFl_o.serialize_v(b_IO_ro);
      combinedViewRearSplitFarRightTopFr_o.serialize_v(b_IO_ro);
      combinedViewRearSplitFarRightTopRl_o.serialize_v(b_IO_ro);
      combinedViewRearSplitFarRightTopRr_o.serialize_v(b_IO_ro);
      combinedViewRearSplitLeftTopAll_o.serialize_v(b_IO_ro);
      combinedViewRearSplitLeftTopFl_o.serialize_v(b_IO_ro);
      combinedViewRearSplitLeftTopFr_o.serialize_v(b_IO_ro);
      combinedViewRearSplitLeftTopRl_o.serialize_v(b_IO_ro);
      combinedViewRearSplitLeftTopRr_o.serialize_v(b_IO_ro);
      combinedViewRearSplitFarLeftTopAll_o.serialize_v(b_IO_ro);
      combinedViewRearSplitFarLeftTopFl_o.serialize_v(b_IO_ro);
      combinedViewRearSplitFarLeftTopFr_o.serialize_v(b_IO_ro);
      combinedViewRearSplitFarLeftTopRl_o.serialize_v(b_IO_ro);
      combinedViewRearSplitFarLeftTopRr_o.serialize_v(b_IO_ro);
      combinedViewFrontFull_o.serialize_v(b_IO_ro);
      combinedViewRearFullWide_o.serialize_v(b_IO_ro);
      combinedViewRearFullNarrow_o.serialize_v(b_IO_ro);
      combinedViewRearFullHitch_o.serialize_v(b_IO_ro);
      combinedViewBedSt_o.serialize_v(b_IO_ro);
      combinedViewMtmFrontSideOverall_o.serialize_v(b_IO_ro);
      combinedViewMtmFrontSide_o.serialize_v(b_IO_ro);
      combinedViewMtmUnderfloorSideOverall_o.serialize_v(b_IO_ro);
      combinedViewMtmUnderfloorSide_o.serialize_v(b_IO_ro);
      combinedViewMtmRearSideOverall_o.serialize_v(b_IO_ro);
      combinedViewMtmRearFull_o.serialize_v(b_IO_ro);
      combinedViewNoView_o.serialize_v(b_IO_ro);
      combinedViewQuad_o.serialize_v(b_IO_ro);
      combinedViewTopAllCalibration_o.serialize_v(b_IO_ro);
      combinedViewRawFront_o.serialize_v(b_IO_ro);
      combinedViewRawLeft_o.serialize_v(b_IO_ro);
      combinedViewRawRear_o.serialize_v(b_IO_ro);
      combinedViewRawRight_o.serialize_v(b_IO_ro);
      combinedViewRawChmsl_o.serialize_v(b_IO_ro);
      pixelAreaFull_o.serialize_v(b_IO_ro);
      pixelAreaTopAll_o.serialize_v(b_IO_ro);
      pixelAreaTopAllFront_o.serialize_v(b_IO_ro);
      pixelAreaTopAllLeft_o.serialize_v(b_IO_ro);
      pixelAreaTopAllRear_o.serialize_v(b_IO_ro);
      pixelAreaTopAllRight_o.serialize_v(b_IO_ro);
      pixelAreaTopZoomFront_o.serialize_v(b_IO_ro);
      pixelAreaTopZoomLeft_o.serialize_v(b_IO_ro);
      pixelAreaTopZoomRear_o.serialize_v(b_IO_ro);
      pixelAreaTopZoomRight_o.serialize_v(b_IO_ro);
      pixelAreaTopPrimary_o.serialize_v(b_IO_ro);
      pixelAreaSplitCenterLeft_o.serialize_v(b_IO_ro);
      pixelAreaSplitCenterRight_o.serialize_v(b_IO_ro);
      pixelAreaSplitRightLeft_o.serialize_v(b_IO_ro);
      pixelAreaSplitRightRight_o.serialize_v(b_IO_ro);
      pixelAreaSplitLeftLeft_o.serialize_v(b_IO_ro);
      pixelAreaSplitLeftRight_o.serialize_v(b_IO_ro);
      pixelAreaMtmSideOverallLeft_o.serialize_v(b_IO_ro);
      pixelAreaMtmSideOverallCenter_o.serialize_v(b_IO_ro);
      pixelAreaMtmSideOverallRight_o.serialize_v(b_IO_ro);
      pixelAreaMtmSideLeft_o.serialize_v(b_IO_ro);
      pixelAreaMtmSideCenter_o.serialize_v(b_IO_ro);
      pixelAreaMtmSideRight_o.serialize_v(b_IO_ro);
      pixelAreaMtmFull_o.serialize_v(b_IO_ro);
      pixelAreaQuadTop_o.serialize_v(b_IO_ro);
      pixelAreaQuadFront_o.serialize_v(b_IO_ro);
      pixelAreaQuadLeft_o.serialize_v(b_IO_ro);
      pixelAreaQuadRear_o.serialize_v(b_IO_ro);
      pixelAreaQuadRight_o.serialize_v(b_IO_ro);
      pixelAreaTopAllCalibration_o.serialize_v(b_IO_ro);
      pixelAreaTopAllFrontCalibration_o.serialize_v(b_IO_ro);
      pixelAreaTopAllLeftCalibration_o.serialize_v(b_IO_ro);
      pixelAreaTopAllRearCalibration_o.serialize_v(b_IO_ro);
      pixelAreaTopAllRightCalibration_o.serialize_v(b_IO_ro);
      pixelAreaRaw_o.serialize_v(b_IO_ro);
      pixelAreaQuadBottom_o.serialize_v(b_IO_ro);
      pixelAreaMtmSideOverallCenterHistoric_o.serialize_v(b_IO_ro);
      pixelAreaMtmSideOverallCenterFront_o.serialize_v(b_IO_ro);
      pixelAreaMtmSideOverallCenterLeft_o.serialize_v(b_IO_ro);
      pixelAreaMtmSideOverallCenterRight_o.serialize_v(b_IO_ro);
      pixelAreaMtmSideCenterHistoric_o.serialize_v(b_IO_ro);
      pixelAreaMtmSideCenterFront_o.serialize_v(b_IO_ro);
      pixelAreaMtmSideCenterLeft_o.serialize_v(b_IO_ro);
      pixelAreaMtmSideCenterRight_o.serialize_v(b_IO_ro);
      stitchParamsTopAllFrontLeft_o.serialize_v(b_IO_ro);
      stitchParamsTopAllFrontRight_o.serialize_v(b_IO_ro);
      stitchParamsTopAllRearLeft_o.serialize_v(b_IO_ro);
      stitchParamsTopAllRearRight_o.serialize_v(b_IO_ro);
      stitchParamsTopZoomFrontLeft_o.serialize_v(b_IO_ro);
      stitchParamsTopZoomFrontRight_o.serialize_v(b_IO_ro);
      stitchParamsTopZoomRearLeft_o.serialize_v(b_IO_ro);
      stitchParamsTopZoomRearRight_o.serialize_v(b_IO_ro);
      stitchParamsTopAllFrontLeftCalibration_o.serialize_v(b_IO_ro);
      stitchParamsTopAllFrontRightCalibration_o.serialize_v(b_IO_ro);
      stitchParamsTopAllRearLeftCalibration_o.serialize_v(b_IO_ro);
      stitchParamsTopAllRearRightCalibration_o.serialize_v(b_IO_ro);
      stitchParamsMtmSideOverallCenterFrontLeft_o.serialize_v(b_IO_ro);
      stitchParamsMtmSideOverallCenterFrontRight_o.serialize_v(b_IO_ro);
      stitchParamsMtmSideOverallCenterHistoricLeft_o.serialize_v(b_IO_ro);
      stitchParamsMtmSideOverallCenterHistoricRight_o.serialize_v(b_IO_ro);
      stitchParamsMtmSideCenterFrontLeft_o.serialize_v(b_IO_ro);
      stitchParamsMtmSideCenterFrontRight_o.serialize_v(b_IO_ro);
      stitchParamsMtmSideCenterHistoricLeft_o.serialize_v(b_IO_ro);
      stitchParamsMtmSideCenterHistoricRight_o.serialize_v(b_IO_ro);
      viewsMap_o.serialize_v(b_IO_ro);
      singleViewsMap_o.serialize_v(b_IO_ro);
      carModelConfig0_o.serialize_v(b_IO_ro);
      kinematicModelConfig0_o.serialize_v(b_IO_ro);
}

AssetBase* getAssetById_po( uint32_t id )
{
      AssetBase* v_FoundAsset_po = NULL;
      switch(id)
      {
            case 38 : 
            {
                  v_FoundAsset_po = &cameraFrontVariant0_o;
                  break;
            }
            case 102 : 
            {
                  v_FoundAsset_po = &cameraLeftVariant0_o;
                  break;
            }
            case 619 : 
            {
                  v_FoundAsset_po = &cameraRearVariant0_o;
                  break;
            }
            case 796 : 
            {
                  v_FoundAsset_po = &cameraRightVariant0_o;
                  break;
            }
            case 5694 : 
            {
                  v_FoundAsset_po = &cameraChmslVariant0_o;
                  break;
            }
            case 4846 : 
            {
                  v_FoundAsset_po = &cameraAuxVariant0_o;
                  break;
            }
            case 264 : 
            {
                  v_FoundAsset_po = &vehicleDataVariant0_o;
                  break;
            }
            case 8621 : 
            {
                  v_FoundAsset_po = &mirrorObscuration_o;
                  break;
            }
            case 486 : 
            {
                  v_FoundAsset_po = &variantConfig_o;
                  break;
            }
            case 698 : 
            {
                  v_FoundAsset_po = &jobConfig_o;
                  break;
            }
            case 1050 : 
            {
                  v_FoundAsset_po = &errorManagerConfig_o;
                  break;
            }
            case 1753 : 
            {
                  v_FoundAsset_po = &eOLCalibFrontVariant0_o;
                  break;
            }
            case 951 : 
            {
                  v_FoundAsset_po = &eOLCalibLeftVariant0_o;
                  break;
            }
            case 285 : 
            {
                  v_FoundAsset_po = &eOLCalibRearVariant0_o;
                  break;
            }
            case 1767 : 
            {
                  v_FoundAsset_po = &eOLCalibRighttVariant0_o;
                  break;
            }
            case 5812 : 
            {
                  v_FoundAsset_po = &eOLCalibChmslVariant0_o;
                  break;
            }
            case 953 : 
            {
                  v_FoundAsset_po = &oCFrontVariant0_o;
                  break;
            }
            case 1800 : 
            {
                  v_FoundAsset_po = &oCLeftVariant0_o;
                  break;
            }
            case 1208 : 
            {
                  v_FoundAsset_po = &oCRearVariant0_o;
                  break;
            }
            case 466 : 
            {
                  v_FoundAsset_po = &oCRightvariant0_o;
                  break;
            }
            case 579 : 
            {
                  v_FoundAsset_po = &oCKinematics_o;
                  break;
            }
            case 4055 : 
            {
                  v_FoundAsset_po = &oCChmslVariant0_o;
                  break;
            }
            case 2320 : 
            {
                  v_FoundAsset_po = &sCCalibFrontVariant0_o;
                  break;
            }
            case 2509 : 
            {
                  v_FoundAsset_po = &sCCalibLeftVariant0_o;
                  break;
            }
            case 2698 : 
            {
                  v_FoundAsset_po = &sCCalibRearVariant0_o;
                  break;
            }
            case 2887 : 
            {
                  v_FoundAsset_po = &sCCalibRightVariant0_o;
                  break;
            }
            case 6348 : 
            {
                  v_FoundAsset_po = &sCCalibChmslVariant0_o;
                  break;
            }
            case 7636 : 
            {
                  v_FoundAsset_po = &screenConfig_o;
                  break;
            }
            case 4735 : 
            {
                  v_FoundAsset_po = &singleViewFullFront_o;
                  break;
            }
            case 3608 : 
            {
                  v_FoundAsset_po = &singleViewFullRearWide_o;
                  break;
            }
            case 5134 : 
            {
                  v_FoundAsset_po = &singleViewFullRearNarrow_o;
                  break;
            }
            case 2618 : 
            {
                  v_FoundAsset_po = &singleViewFullRearHitch_o;
                  break;
            }
            case 2024 : 
            {
                  v_FoundAsset_po = &singleViewTopPrimaryFront_o;
                  break;
            }
            case 5891 : 
            {
                  v_FoundAsset_po = &singleViewTopPrimaryRear_o;
                  break;
            }
            case 7420 : 
            {
                  v_FoundAsset_po = &singleViewTopAllFront_o;
                  break;
            }
            case 2678 : 
            {
                  v_FoundAsset_po = &singleViewTopAllLeft_o;
                  break;
            }
            case 2033 : 
            {
                  v_FoundAsset_po = &singleViewTopAllRear_o;
                  break;
            }
            case 5821 : 
            {
                  v_FoundAsset_po = &singleViewTopAllRight_o;
                  break;
            }
            case 4927 : 
            {
                  v_FoundAsset_po = &singleViewTopFlFront_o;
                  break;
            }
            case 7023 : 
            {
                  v_FoundAsset_po = &singleViewTopFrFront_o;
                  break;
            }
            case 2035 : 
            {
                  v_FoundAsset_po = &singleViewTopFlLeft_o;
                  break;
            }
            case 5946 : 
            {
                  v_FoundAsset_po = &singleViewTopRlLeft_o;
                  break;
            }
            case 2575 : 
            {
                  v_FoundAsset_po = &singleViewTopRlRear_o;
                  break;
            }
            case 3163 : 
            {
                  v_FoundAsset_po = &singleViewTopRrRear_o;
                  break;
            }
            case 1497 : 
            {
                  v_FoundAsset_po = &singleViewTopFrRight_o;
                  break;
            }
            case 7540 : 
            {
                  v_FoundAsset_po = &singleViewTopRrRight_o;
                  break;
            }
            case 3396 : 
            {
                  v_FoundAsset_po = &singleViewFrontSplitLeft_o;
                  break;
            }
            case 3572 : 
            {
                  v_FoundAsset_po = &singleViewFrontSplitRight_o;
                  break;
            }
            case 1524 : 
            {
                  v_FoundAsset_po = &singleViewBed_o;
                  break;
            }
            case 7585 : 
            {
                  v_FoundAsset_po = &singleViewAux_o;
                  break;
            }
            case 7053 : 
            {
                  v_FoundAsset_po = &singleViewRearSplitCenterLeft_o;
                  break;
            }
            case 2044 : 
            {
                  v_FoundAsset_po = &singleViewRearSplitCenterRight_o;
                  break;
            }
            case 1460 : 
            {
                  v_FoundAsset_po = &singleViewRearSplitRightLeft_o;
                  break;
            }
            case 7595 : 
            {
                  v_FoundAsset_po = &singleViewRearSplitRightRight_o;
                  break;
            }
            case 3795 : 
            {
                  v_FoundAsset_po = &singleViewRearSplitLeftLeft_o;
                  break;
            }
            case 4173 : 
            {
                  v_FoundAsset_po = &singleViewRearSplitLeftRight_o;
                  break;
            }
            case 390 : 
            {
                  v_FoundAsset_po = &singleViewRearSplitFarLeft_o;
                  break;
            }
            case 4204 : 
            {
                  v_FoundAsset_po = &singleViewRearSplitFarRight_o;
                  break;
            }
            case 6421 : 
            {
                  v_FoundAsset_po = &singleViewMtmFrontSideOverallLeft_o;
                  break;
            }
            case 4166 : 
            {
                  v_FoundAsset_po = &singleViewMtmFrontSideOverallCenter_o;
                  break;
            }
            case 5143 : 
            {
                  v_FoundAsset_po = &singleViewMtmFrontSideOverallRight_o;
                  break;
            }
            case 7551 : 
            {
                  v_FoundAsset_po = &singleViewMtmFrontSideLeft_o;
                  break;
            }
            case 188 : 
            {
                  v_FoundAsset_po = &singleViewMtmFrontSideCenter_o;
                  break;
            }
            case 4659 : 
            {
                  v_FoundAsset_po = &singleViewMtmFrontSideRight_o;
                  break;
            }
            case 1462 : 
            {
                  v_FoundAsset_po = &singleViewMtmRearSideOverallLeft_o;
                  break;
            }
            case 3804 : 
            {
                  v_FoundAsset_po = &singleViewMtmRearSideOverallCenter_o;
                  break;
            }
            case 4222 : 
            {
                  v_FoundAsset_po = &singleViewMtmRearSideOverallRight_o;
                  break;
            }
            case 6133 : 
            {
                  v_FoundAsset_po = &singleViewMtmRearFull_o;
                  break;
            }
            case 2885 : 
            {
                  v_FoundAsset_po = &singleViewQuadFront_o;
                  break;
            }
            case 3545 : 
            {
                  v_FoundAsset_po = &singleViewQuadLeft_o;
                  break;
            }
            case 5659 : 
            {
                  v_FoundAsset_po = &singleViewQuadRear_o;
                  break;
            }
            case 4616 : 
            {
                  v_FoundAsset_po = &singleViewQuadRight_o;
                  break;
            }
            case 17 : 
            {
                  v_FoundAsset_po = &singleViewTopAllFrontCalibration_o;
                  break;
            }
            case 3020 : 
            {
                  v_FoundAsset_po = &singleViewTopAllLeftCalibration_o;
                  break;
            }
            case 3868 : 
            {
                  v_FoundAsset_po = &singleViewTopAllRearCalibration_o;
                  break;
            }
            case 3762 : 
            {
                  v_FoundAsset_po = &singleViewTopAllRightCalibration_o;
                  break;
            }
            case 2803 : 
            {
                  v_FoundAsset_po = &singleViewMtmUnderfloorSideOverallCenterHistoric_o;
                  break;
            }
            case 8313 : 
            {
                  v_FoundAsset_po = &singleViewMtmUnderfloorSideOverallCenterFront_o;
                  break;
            }
            case 8324 : 
            {
                  v_FoundAsset_po = &singleViewMtmUnderfloorSideOverallCenterLeft_o;
                  break;
            }
            case 8335 : 
            {
                  v_FoundAsset_po = &singleViewMtmUnderfloorSideOverallCenterRight_o;
                  break;
            }
            case 3928 : 
            {
                  v_FoundAsset_po = &singleViewMtmUnderfloorSideCenterHistoric_o;
                  break;
            }
            case 8393 : 
            {
                  v_FoundAsset_po = &singleViewMtmUnderfloorSideCenterFront_o;
                  break;
            }
            case 8405 : 
            {
                  v_FoundAsset_po = &singleViewMtmUnderfloorSideCenterLeft_o;
                  break;
            }
            case 8475 : 
            {
                  v_FoundAsset_po = &singleViewMtmUnderfloorSideCenterRight_o;
                  break;
            }
            case 2556 : 
            {
                  v_FoundAsset_po = &singleViewRawFront_o;
                  break;
            }
            case 2830 : 
            {
                  v_FoundAsset_po = &singleViewRawLeft_o;
                  break;
            }
            case 3308 : 
            {
                  v_FoundAsset_po = &singleViewRawRear_o;
                  break;
            }
            case 3493 : 
            {
                  v_FoundAsset_po = &singleViewRawRight_o;
                  break;
            }
            case 3633 : 
            {
                  v_FoundAsset_po = &singleViewRawChmsl_o;
                  break;
            }
            case 3984 : 
            {
                  v_FoundAsset_po = &virtualCameraFullFront_o;
                  break;
            }
            case 1134 : 
            {
                  v_FoundAsset_po = &virtualCameraFullRearWide_o;
                  break;
            }
            case 6974 : 
            {
                  v_FoundAsset_po = &virtualCameraFullRearNarrow_o;
                  break;
            }
            case 4545 : 
            {
                  v_FoundAsset_po = &virtualCameraFullRearHitch_o;
                  break;
            }
            case 8216 : 
            {
                  v_FoundAsset_po = &virtualCameraTopPrimaryFront_o;
                  break;
            }
            case 5263 : 
            {
                  v_FoundAsset_po = &virtualCameraTopPrimaryRear_o;
                  break;
            }
            case 1887 : 
            {
                  v_FoundAsset_po = &virtualCameraTopAll_o;
                  break;
            }
            case 4273 : 
            {
                  v_FoundAsset_po = &virtualCameraTopFl_o;
                  break;
            }
            case 5389 : 
            {
                  v_FoundAsset_po = &virtualCameraTopFr_o;
                  break;
            }
            case 6482 : 
            {
                  v_FoundAsset_po = &virtualCameraTopRl_o;
                  break;
            }
            case 1891 : 
            {
                  v_FoundAsset_po = &virtualCameraTopRr_o;
                  break;
            }
            case 1914 : 
            {
                  v_FoundAsset_po = &virtualCameraFrontSplitLeft_o;
                  break;
            }
            case 3985 : 
            {
                  v_FoundAsset_po = &virtualCameraFrontSplitRight_o;
                  break;
            }
            case 5192 : 
            {
                  v_FoundAsset_po = &virtualCameraBed_o;
                  break;
            }
            case 2354 : 
            {
                  v_FoundAsset_po = &virtualCameraAux_o;
                  break;
            }
            case 4293 : 
            {
                  v_FoundAsset_po = &virtualCameraRearSplitCenterLeft_o;
                  break;
            }
            case 5409 : 
            {
                  v_FoundAsset_po = &virtualCameraRearSplitCenterRight_o;
                  break;
            }
            case 6898 : 
            {
                  v_FoundAsset_po = &virtualCameraRearSplitRightLeft_o;
                  break;
            }
            case 2543 : 
            {
                  v_FoundAsset_po = &virtualCameraRearSplitRightRight_o;
                  break;
            }
            case 2666 : 
            {
                  v_FoundAsset_po = &virtualCameraRearSplitLeftLeft_o;
                  break;
            }
            case 4005 : 
            {
                  v_FoundAsset_po = &virtualCameraRearSplitLeftRight_o;
                  break;
            }
            case 5212 : 
            {
                  v_FoundAsset_po = &virtualCameraRearSplitFarLeft_o;
                  break;
            }
            case 7081 : 
            {
                  v_FoundAsset_po = &virtualCameraRearSplitFarRight_o;
                  break;
            }
            case 1491 : 
            {
                  v_FoundAsset_po = &virtualCameraMtmFrontSideOverallLeft_o;
                  break;
            }
            case 3307 : 
            {
                  v_FoundAsset_po = &virtualCameraMtmFrontSideOverallCenter_o;
                  break;
            }
            case 5117 : 
            {
                  v_FoundAsset_po = &virtualCameraMtmFrontSideOverallRight_o;
                  break;
            }
            case 6373 : 
            {
                  v_FoundAsset_po = &virtualCameraMtmFrontSideLeft_o;
                  break;
            }
            case 1845 : 
            {
                  v_FoundAsset_po = &virtualCameraMtmFrontSideCenter_o;
                  break;
            }
            case 3055 : 
            {
                  v_FoundAsset_po = &virtualCameraMtmFrontSideRight_o;
                  break;
            }
            case 4062 : 
            {
                  v_FoundAsset_po = &virtualCameraMtmRearSideOverallLeft_o;
                  break;
            }
            case 6939 : 
            {
                  v_FoundAsset_po = &virtualCameraMtmRearSideOverallCenter_o;
                  break;
            }
            case 3296 : 
            {
                  v_FoundAsset_po = &virtualCameraMtmRearSideOverallRight_o;
                  break;
            }
            case 3641 : 
            {
                  v_FoundAsset_po = &virtualCameraMtmRearFull_o;
                  break;
            }
            case 2738 : 
            {
                  v_FoundAsset_po = &virtualCameraMtmUnderfloorSideOverallCenter_o;
                  break;
            }
            case 3074 : 
            {
                  v_FoundAsset_po = &virtualCameraMtmUnderfloorSideCenter_o;
                  break;
            }
            case 5090 : 
            {
                  v_FoundAsset_po = &virtualCameraQuadFront_o;
                  break;
            }
            case 6699 : 
            {
                  v_FoundAsset_po = &virtualCameraQuadLeft_o;
                  break;
            }
            case 5509 : 
            {
                  v_FoundAsset_po = &virtualCameraQuadRear_o;
                  break;
            }
            case 3287 : 
            {
                  v_FoundAsset_po = &virtualCameraQuadRight_o;
                  break;
            }
            case 2223 : 
            {
                  v_FoundAsset_po = &virtualCameraTopAllCalibration_o;
                  break;
            }
            case 3817 : 
            {
                  v_FoundAsset_po = &virtualCameraRawFront_o;
                  break;
            }
            case 4313 : 
            {
                  v_FoundAsset_po = &virtualCameraRawLeft_o;
                  break;
            }
            case 4827 : 
            {
                  v_FoundAsset_po = &virtualCameraRawRear_o;
                  break;
            }
            case 5386 : 
            {
                  v_FoundAsset_po = &virtualCameraRawRight_o;
                  break;
            }
            case 5843 : 
            {
                  v_FoundAsset_po = &virtualCameraRawChmsl_o;
                  break;
            }
            case 6352 : 
            {
                  v_FoundAsset_po = &combinedViewFrontTopAll_o;
                  break;
            }
            case 4321 : 
            {
                  v_FoundAsset_po = &combinedViewFrontTopFl_o;
                  break;
            }
            case 5776 : 
            {
                  v_FoundAsset_po = &combinedViewFrontTopFr_o;
                  break;
            }
            case 4461 : 
            {
                  v_FoundAsset_po = &combinedViewFrontTopRl_o;
                  break;
            }
            case 5088 : 
            {
                  v_FoundAsset_po = &combinedViewFrontTopRr_o;
                  break;
            }
            case 4210 : 
            {
                  v_FoundAsset_po = &combinedViewFrontSplitTopAll_o;
                  break;
            }
            case 4171 : 
            {
                  v_FoundAsset_po = &combinedViewFrontSplitTopFl_o;
                  break;
            }
            case 4937 : 
            {
                  v_FoundAsset_po = &combinedViewFrontSplitTopFr_o;
                  break;
            }
            case 3569 : 
            {
                  v_FoundAsset_po = &combinedViewFrontSplitTopRl_o;
                  break;
            }
            case 3305 : 
            {
                  v_FoundAsset_po = &combinedViewFrontSplitTopRr_o;
                  break;
            }
            case 5309 : 
            {
                  v_FoundAsset_po = &combinedViewRearTopAll_o;
                  break;
            }
            case 3880 : 
            {
                  v_FoundAsset_po = &combinedViewRearTopFl_o;
                  break;
            }
            case 7214 : 
            {
                  v_FoundAsset_po = &combinedViewRearTopFr_o;
                  break;
            }
            case 1427 : 
            {
                  v_FoundAsset_po = &combinedViewRearTopRl_o;
                  break;
            }
            case 1598 : 
            {
                  v_FoundAsset_po = &combinedViewRearTopRr_o;
                  break;
            }
            case 5697 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitCenterTopAll_o;
                  break;
            }
            case 3165 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitCenterTopFl_o;
                  break;
            }
            case 3627 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitCenterTopFr_o;
                  break;
            }
            case 4905 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitCenterTopRl_o;
                  break;
            }
            case 3367 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitCenterTopRr_o;
                  break;
            }
            case 4286 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitRightTopAll_o;
                  break;
            }
            case 1404 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitRightTopFl_o;
                  break;
            }
            case 7042 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitRightTopFr_o;
                  break;
            }
            case 1478 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitRightTopRl_o;
                  break;
            }
            case 7492 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitRightTopRr_o;
                  break;
            }
            case 7099 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitFarRightTopAll_o;
                  break;
            }
            case 3371 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitFarRightTopFl_o;
                  break;
            }
            case 3044 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitFarRightTopFr_o;
                  break;
            }
            case 3922 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitFarRightTopRl_o;
                  break;
            }
            case 3852 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitFarRightTopRr_o;
                  break;
            }
            case 3246 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitLeftTopAll_o;
                  break;
            }
            case 247 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitLeftTopFl_o;
                  break;
            }
            case 5607 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitLeftTopFr_o;
                  break;
            }
            case 6523 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitLeftTopRl_o;
                  break;
            }
            case 3321 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitLeftTopRr_o;
                  break;
            }
            case 6059 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitFarLeftTopAll_o;
                  break;
            }
            case 2739 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitFarLeftTopFl_o;
                  break;
            }
            case 1465 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitFarLeftTopFr_o;
                  break;
            }
            case 2085 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitFarLeftTopRl_o;
                  break;
            }
            case 2722 : 
            {
                  v_FoundAsset_po = &combinedViewRearSplitFarLeftTopRr_o;
                  break;
            }
            case 3304 : 
            {
                  v_FoundAsset_po = &combinedViewFrontFull_o;
                  break;
            }
            case 7335 : 
            {
                  v_FoundAsset_po = &combinedViewRearFullWide_o;
                  break;
            }
            case 2667 : 
            {
                  v_FoundAsset_po = &combinedViewRearFullNarrow_o;
                  break;
            }
            case 4670 : 
            {
                  v_FoundAsset_po = &combinedViewRearFullHitch_o;
                  break;
            }
            case 2254 : 
            {
                  v_FoundAsset_po = &combinedViewBedSt_o;
                  break;
            }
            case 5440 : 
            {
                  v_FoundAsset_po = &combinedViewMtmFrontSideOverall_o;
                  break;
            }
            case 3265 : 
            {
                  v_FoundAsset_po = &combinedViewMtmFrontSide_o;
                  break;
            }
            case 4567 : 
            {
                  v_FoundAsset_po = &combinedViewMtmUnderfloorSideOverall_o;
                  break;
            }
            case 6164 : 
            {
                  v_FoundAsset_po = &combinedViewMtmUnderfloorSide_o;
                  break;
            }
            case 946 : 
            {
                  v_FoundAsset_po = &combinedViewMtmRearSideOverall_o;
                  break;
            }
            case 5956 : 
            {
                  v_FoundAsset_po = &combinedViewMtmRearFull_o;
                  break;
            }
            case 3046 : 
            {
                  v_FoundAsset_po = &combinedViewNoView_o;
                  break;
            }
            case 7402 : 
            {
                  v_FoundAsset_po = &combinedViewQuad_o;
                  break;
            }
            case 6874 : 
            {
                  v_FoundAsset_po = &combinedViewTopAllCalibration_o;
                  break;
            }
            case 6053 : 
            {
                  v_FoundAsset_po = &combinedViewRawFront_o;
                  break;
            }
            case 6564 : 
            {
                  v_FoundAsset_po = &combinedViewRawLeft_o;
                  break;
            }
            case 8072 : 
            {
                  v_FoundAsset_po = &combinedViewRawRear_o;
                  break;
            }
            case 8106 : 
            {
                  v_FoundAsset_po = &combinedViewRawRight_o;
                  break;
            }
            case 8140 : 
            {
                  v_FoundAsset_po = &combinedViewRawChmsl_o;
                  break;
            }
            case 4183 : 
            {
                  v_FoundAsset_po = &pixelAreaFull_o;
                  break;
            }
            case 4284 : 
            {
                  v_FoundAsset_po = &pixelAreaTopAll_o;
                  break;
            }
            case 4385 : 
            {
                  v_FoundAsset_po = &pixelAreaTopAllFront_o;
                  break;
            }
            case 1511 : 
            {
                  v_FoundAsset_po = &pixelAreaTopAllLeft_o;
                  break;
            }
            case 3458 : 
            {
                  v_FoundAsset_po = &pixelAreaTopAllRear_o;
                  break;
            }
            case 3559 : 
            {
                  v_FoundAsset_po = &pixelAreaTopAllRight_o;
                  break;
            }
            case 3660 : 
            {
                  v_FoundAsset_po = &pixelAreaTopZoomFront_o;
                  break;
            }
            case 3761 : 
            {
                  v_FoundAsset_po = &pixelAreaTopZoomLeft_o;
                  break;
            }
            case 3862 : 
            {
                  v_FoundAsset_po = &pixelAreaTopZoomRear_o;
                  break;
            }
            case 3963 : 
            {
                  v_FoundAsset_po = &pixelAreaTopZoomRight_o;
                  break;
            }
            case 4064 : 
            {
                  v_FoundAsset_po = &pixelAreaTopPrimary_o;
                  break;
            }
            case 4165 : 
            {
                  v_FoundAsset_po = &pixelAreaSplitCenterLeft_o;
                  break;
            }
            case 3150 : 
            {
                  v_FoundAsset_po = &pixelAreaSplitCenterRight_o;
                  break;
            }
            case 3251 : 
            {
                  v_FoundAsset_po = &pixelAreaSplitRightLeft_o;
                  break;
            }
            case 3352 : 
            {
                  v_FoundAsset_po = &pixelAreaSplitRightRight_o;
                  break;
            }
            case 4261 : 
            {
                  v_FoundAsset_po = &pixelAreaSplitLeftLeft_o;
                  break;
            }
            case 4362 : 
            {
                  v_FoundAsset_po = &pixelAreaSplitLeftRight_o;
                  break;
            }
            case 7441 : 
            {
                  v_FoundAsset_po = &pixelAreaMtmSideOverallLeft_o;
                  break;
            }
            case 5839 : 
            {
                  v_FoundAsset_po = &pixelAreaMtmSideOverallCenter_o;
                  break;
            }
            case 5834 : 
            {
                  v_FoundAsset_po = &pixelAreaMtmSideOverallRight_o;
                  break;
            }
            case 5759 : 
            {
                  v_FoundAsset_po = &pixelAreaMtmSideLeft_o;
                  break;
            }
            case 4754 : 
            {
                  v_FoundAsset_po = &pixelAreaMtmSideCenter_o;
                  break;
            }
            case 4042 : 
            {
                  v_FoundAsset_po = &pixelAreaMtmSideRight_o;
                  break;
            }
            case 5036 : 
            {
                  v_FoundAsset_po = &pixelAreaMtmFull_o;
                  break;
            }
            case 3355 : 
            {
                  v_FoundAsset_po = &pixelAreaQuadTop_o;
                  break;
            }
            case 1707 : 
            {
                  v_FoundAsset_po = &pixelAreaQuadFront_o;
                  break;
            }
            case 6792 : 
            {
                  v_FoundAsset_po = &pixelAreaQuadLeft_o;
                  break;
            }
            case 2988 : 
            {
                  v_FoundAsset_po = &pixelAreaQuadRear_o;
                  break;
            }
            case 7913 : 
            {
                  v_FoundAsset_po = &pixelAreaQuadRight_o;
                  break;
            }
            case 569 : 
            {
                  v_FoundAsset_po = &pixelAreaTopAllCalibration_o;
                  break;
            }
            case 3550 : 
            {
                  v_FoundAsset_po = &pixelAreaTopAllFrontCalibration_o;
                  break;
            }
            case 4419 : 
            {
                  v_FoundAsset_po = &pixelAreaTopAllLeftCalibration_o;
                  break;
            }
            case 4972 : 
            {
                  v_FoundAsset_po = &pixelAreaTopAllRearCalibration_o;
                  break;
            }
            case 5387 : 
            {
                  v_FoundAsset_po = &pixelAreaTopAllRightCalibration_o;
                  break;
            }
            case 8174 : 
            {
                  v_FoundAsset_po = &pixelAreaRaw_o;
                  break;
            }
            case 8182 : 
            {
                  v_FoundAsset_po = &pixelAreaQuadBottom_o;
                  break;
            }
            case 8361 : 
            {
                  v_FoundAsset_po = &pixelAreaMtmSideOverallCenterHistoric_o;
                  break;
            }
            case 8369 : 
            {
                  v_FoundAsset_po = &pixelAreaMtmSideOverallCenterFront_o;
                  break;
            }
            case 8377 : 
            {
                  v_FoundAsset_po = &pixelAreaMtmSideOverallCenterLeft_o;
                  break;
            }
            case 8385 : 
            {
                  v_FoundAsset_po = &pixelAreaMtmSideOverallCenterRight_o;
                  break;
            }
            case 8501 : 
            {
                  v_FoundAsset_po = &pixelAreaMtmSideCenterHistoric_o;
                  break;
            }
            case 8509 : 
            {
                  v_FoundAsset_po = &pixelAreaMtmSideCenterFront_o;
                  break;
            }
            case 8517 : 
            {
                  v_FoundAsset_po = &pixelAreaMtmSideCenterLeft_o;
                  break;
            }
            case 8525 : 
            {
                  v_FoundAsset_po = &pixelAreaMtmSideCenterRight_o;
                  break;
            }
            case 7077 : 
            {
                  v_FoundAsset_po = &stitchParamsTopAllFrontLeft_o;
                  break;
            }
            case 7542 : 
            {
                  v_FoundAsset_po = &stitchParamsTopAllFrontRight_o;
                  break;
            }
            case 3149 : 
            {
                  v_FoundAsset_po = &stitchParamsTopAllRearLeft_o;
                  break;
            }
            case 3250 : 
            {
                  v_FoundAsset_po = &stitchParamsTopAllRearRight_o;
                  break;
            }
            case 6693 : 
            {
                  v_FoundAsset_po = &stitchParamsTopZoomFrontLeft_o;
                  break;
            }
            case 2793 : 
            {
                  v_FoundAsset_po = &stitchParamsTopZoomFrontRight_o;
                  break;
            }
            case 1946 : 
            {
                  v_FoundAsset_po = &stitchParamsTopZoomRearLeft_o;
                  break;
            }
            case 3962 : 
            {
                  v_FoundAsset_po = &stitchParamsTopZoomRearRight_o;
                  break;
            }
            case 3348 : 
            {
                  v_FoundAsset_po = &stitchParamsTopAllFrontLeftCalibration_o;
                  break;
            }
            case 2737 : 
            {
                  v_FoundAsset_po = &stitchParamsTopAllFrontRightCalibration_o;
                  break;
            }
            case 7240 : 
            {
                  v_FoundAsset_po = &stitchParamsTopAllRearLeftCalibration_o;
                  break;
            }
            case 2735 : 
            {
                  v_FoundAsset_po = &stitchParamsTopAllRearRightCalibration_o;
                  break;
            }
            case 8409 : 
            {
                  v_FoundAsset_po = &stitchParamsMtmSideOverallCenterFrontLeft_o;
                  break;
            }
            case 8424 : 
            {
                  v_FoundAsset_po = &stitchParamsMtmSideOverallCenterFrontRight_o;
                  break;
            }
            case 8439 : 
            {
                  v_FoundAsset_po = &stitchParamsMtmSideOverallCenterHistoricLeft_o;
                  break;
            }
            case 8454 : 
            {
                  v_FoundAsset_po = &stitchParamsMtmSideOverallCenterHistoricRight_o;
                  break;
            }
            case 8533 : 
            {
                  v_FoundAsset_po = &stitchParamsMtmSideCenterFrontLeft_o;
                  break;
            }
            case 8548 : 
            {
                  v_FoundAsset_po = &stitchParamsMtmSideCenterFrontRight_o;
                  break;
            }
            case 8563 : 
            {
                  v_FoundAsset_po = &stitchParamsMtmSideCenterHistoricLeft_o;
                  break;
            }
            case 8578 : 
            {
                  v_FoundAsset_po = &stitchParamsMtmSideCenterHistoricRight_o;
                  break;
            }
            case 7105 : 
            {
                  v_FoundAsset_po = &viewsMap_o;
                  break;
            }
            case 6381 : 
            {
                  v_FoundAsset_po = &singleViewsMap_o;
                  break;
            }
            case 2009 : 
            {
                  v_FoundAsset_po = &carModelConfig0_o;
                  break;
            }
            case 5650 : 
            {
                  v_FoundAsset_po = &kinematicModelConfig0_o;
                  break;
            }
            default : 
            {
                  v_FoundAsset_po = NULL;
            }
      }
      return v_FoundAsset_po;
}} // namespace variants