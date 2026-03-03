/// --------------------------------------------------------------------------
/// @file JobTHAInput.h
/// @brief Contains THA detection input structure definition
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Jignesh Vasoya (jignesh.vasoya@magna.com)
/// --------------------------------------------------------------------------

#ifndef JOBTHA_INPUT_H
#define JOBTHA_INPUT_H

#include "../common/THADefs.h"
#include "../../../../../../../../../bookshelf/includes/HMI_SVS.h"
#include "../../../../../../../../../bookshelf/includes/THA_Detection_Inputs_Outputs.h"
namespace tha
{
struct KMData_s
{
    float32_t dx_m_f32;
    float32_t dy_m_f32;
    float32_t dyaw_rad_f32;
    float32_t timestamp_s_f32;
};

enum GearValuesDsply
{
    INITIALIZE = 0,
    GEAR_DISP1 = 1,
    GEAR_DISP2 = 2,
    GEAR_DISP3 = 3,
    GEAR_DISP4 = 4,
    GEAR_DISP5 = 5,
    GEAR_DISP6 = 6,
    GEAR_DISP7 = 7,
    GEAR_DISP8 = 8,
    GEAR_DISP9 = 9,
    NOT_USED1 = 10,
    NOT_USED2 = 11,
    GEAR_DISP_PARK = 12,
    GEAR_DISP_NEUTRAL = 13,
    GEAR_DISP_REVERSE = 14,
    GEAR_DISP_FORWARD = 15,
    L = 16,
    M = 17,
    S = 18,
    SNA = 31,
    GEAR_Size_Enforcer = 0xFFFFFFFFu
};

/*
* Detection structures
*/
enum ODType
    {
        Obj_Trailer = 0,
        Obj_Coupler = 1,
        Obj_Hitch = 2,
        Obj_CouplerReg = 3,
        Obj_Pose = 4,
        Obj_Unknown = 5,
        Obj_Size_Enforcer = 0xFFFFFFFFu
    };

    struct ODInfo
    {
    private:
        ODType Type;
        Recti Rect;
        Point2i Point_2D;
        Point2i Point_2D_Ground;
        Point3f Point_3D;
        float32_t Pose;
        float32_t Score;
        float32_t DetConf;

    public:
        ODInfo() : Type( Obj_Unknown ), Rect( Recti( 0, 0, 0, 0 ) ), Point_2D( Point2i( 0, 0 ) ), Point_2D_Ground( Point2i( 0, 0 ) ), Point_3D( Point3f( 0.0f, 0.0f, 0.0f ) ), Pose( 180.0f ), Score( -1.0f ), DetConf( 0.0f )
        {
        }
        float32_t getDetConf() const
        {
            return DetConf;
        }
        Recti getRect() const
        {
            return Rect;
        }
        ODType getType() const
        {
            return Type;
        }
        Point2i getPoint_2D() const
        {
            return Point_2D;
        }
        Point3f getPoint_3D() const
        {
            return Point_3D;
        }
        void setType( ODType i_Type )
        {
            Type = i_Type;
        }
        void setRect( Recti i_Rect )
        {
            Rect = i_Rect;
        }
        void setDetConf( float32_t i_DetConf )
        {
            DetConf = i_DetConf;
        }
        void setPoint_2D( Point2i i_Point2D )
        {
            Point_2D = i_Point2D;
        }
        void setPoint_2D_Ground( Point2i i_Point2DGround )
        {
            Point_2D_Ground = i_Point2DGround;
        }
        void setPoint_3D( Point3f i_Point3D )
        {
            Point_3D = i_Point3D;
        }
    };


/*
*   ONNX Structure, enums
*/

typedef struct BBBox_s
{
    int32_t left;
    int32_t right;
    int32_t top;
    int32_t bottom;
    float32_t conf;
} BBBox_t;

typedef struct DetectionObject_s
{
    BBBox_t m_box;
    int32_t ClassID;
    float32_t prob;
    int32_t centerImagePoint_X;
    int32_t centerImagePoint_Y;
    bool_t validFlag;
} DetectionObject_t;

/*
* KM config data
*/
struct KMCfgInfo
{
    float32_t m_DistanceCoG2ReAxis;
    float32_t m_DistanceCoG2FrAxis;
    int16_t m_VehicleWidth_mm;
    int16_t m_VehicleLength_mm;
    int16_t m_FrontOverhang_mm;
    int16_t m_RearOverhang_mm;
};

typedef struct THADet_Inputs_from_THASM_s
{
    /*
    @@ ELEMENT = THAState_e
    @@ STRUCTURE = THADet_Inputs_from_THASM_t
    @@ A2L_TYPE = PARAMETER WRITEABLE
    @@ DATA_TYPE = UBYTE
    @@ END
    */
    THAState_e THASmState_e;                  /* <IPC signal name: MeTHA_e_THAStateInfo>State of THA main state machine */

    /*
    @@ ELEMENT = THATrgTypeScrReq_e
    @@ STRUCTURE = THADet_Inputs_from_THASM_t
    @@ A2L_TYPE = PARAMETER WRITEABLE
    @@ DATA_TYPE = UBYTE
    @@ END
    */
    aSigConverter_E_THAScreenRequest_t THATrgTypeScrReq_e;        /* <IPC signal name: MeTHA_e_ScreenRequest> THA screen request message from main state machine */
    /*
    @@ ELEMENT = UsrHitchCnfm_b
    @@ STRUCTURE = THADet_Inputs_from_THASM_t
    @@ A2L_TYPE = PARAMETER WRITEABLE
    @@ DATA_TYPE = UBYTE [0 ... 1]
    @@ END
    */
    bool_t UsrHitchCnfm_b;                  /* <IPC signal name: MeTHA_b_UsrHitchCnfm> Status of Hitch confirmation by user */

    /*
    @@ ELEMENT = UsrCplrSelected_b
    @@ STRUCTURE = THADet_Inputs_from_THASM_t
    @@ A2L_TYPE = PARAMETER WRITEABLE
    @@ DATA_TYPE = UBYTE [0 ... 1]
    @@ END
    */
    bool_t UsrCplrSelected_b;               /* <IPC signal name: MeTHA_b_UsrCplrSelCnfm> Status of Coupler selection confirmation by user */

} THADet_Inputs_from_THASM_t;

typedef struct THADet_Inputs_from_HMI_s
{
    /*
    @@ ELEMENT = CplrPixX_u16
    @@ STRUCTURE = THADet_Inputs_from_HMI_t
    @@ A2L_TYPE = PARAMETER WRITEABLE
    @@ DATA_TYPE = UWORD
    @@ END
    */
    uint16_t CplrPixX_u16;                  /* <IPC signal name: MeSVS_px_THACplrPosX> Coupler pixel X (Longitudinal direction) */

    /*
    @@ ELEMENT = CplrPixY_u16
    @@ STRUCTURE = THADet_Inputs_from_HMI_t
    @@ A2L_TYPE = PARAMETER WRITEABLE
    @@ DATA_TYPE = UWORD
    @@ END
    */
    uint16_t CplrPixY_u16;                  /* <IPC signal name: MeSVS_px_THACplrPosY> Coupler pixel Y (Lateral direction) */
} THADet_Inputs_from_HMI_t;

typedef struct THADet_Inputs_from_KM_s
{
    KMData_s KMDataInfo_s;                  /* Kinematic vehicle data */
} THADet_Inputs_from_KM_t;

typedef struct THADet_Inputs_from_VehInp_s
{
    /*
    @@ ELEMENT = VehSpeed_f32
    @@ STRUCTURE = THADet_Inputs_from_VehInp_t
    @@ A2L_TYPE = PARAMETER WRITEABLE
    @@ DATA_TYPE = FLOAT
    @@ END
    */
    float32_t VehSpeed_f32;                 /* <IPC signal name: IeVBII_kph_VehSpeedVSOSig> Vehicle speed */

    /*
    @@ ELEMENT = GearDirection_e
    @@ STRUCTURE = THADet_Inputs_from_VehInp_t
    @@ A2L_TYPE = PARAMETER WRITEABLE
    @@ DATA_TYPE = UBYTE
    @@ END
    */
    GearValuesDsply GearDirection_e;        /* <IPC signal name: IeVBII_e_GearEngagedForDsply> Vehicle gear */
} THADet_Inputs_from_VehInp_t;

typedef struct JobTHAInput_s
{
    /*
    @@ ELEMENT = InputImgGray_u8_ptr
    @@ STRUCTURE = JobTHAInput_t
    @@ A2L_TYPE = PARAMETER WRITEABLE
    @@ DATA_TYPE = ULONG
    @@ END
    */
    uint8_t* InputImgGray_pu8;//const 640wX 400h - tracker - validate size

    /*
    @@ ELEMENT = InputImgColor_u8_ptr
    @@ STRUCTURE = JobTHAInput_t
    @@ A2L_TYPE = PARAMETER WRITEABLE
    @@ DATA_TYPE = ULONG
    @@ END
    */
    uint8_t* InputImgColor_pu8;//1920x1280 yet to be received - Detecion CD HD GD -> BB-> crop pending-> Classification -> done

    /*
    @@ SUB_STRUCTURE = HMIInput_s
    @@ STRUCTURE = JobTHAInput_t
    @@ DATA_TYPE = STRUCTURE THADet_Inputs_from_HMI_t
    @@ END
    */
    THADet_Inputs_from_HMI_t HMIInput_s;

    /*
    @@ SUB_STRUCTURE = SMInput_s
    @@ STRUCTURE = JobTHAInput_t
    @@ DATA_TYPE = STRUCTURE THADet_Inputs_from_THASM_t
    @@ END
    */
    THADet_Inputs_from_THASM_t SMInput_s;

    /*
    @@ SUB_STRUCTURE = VehInput_s
    @@ STRUCTURE = JobTHAInput_t
    @@ DATA_TYPE = STRUCTURE THADet_Inputs_from_VehInp_t
    @@ END
    */
    THADet_Inputs_from_VehInp_t VehInput_s;

    /*
    @@ SUB_STRUCTURE = KMInput_s
    @@ STRUCTURE = JobTHAInput_t
    @@ DATA_TYPE = STRUCTURE THADet_Inputs_from_KM_t
    @@ END
    */
    THADet_Inputs_from_KM_t KMInput_s;
} JobTHAInput_t;

// Removed THADet_Inputs_from_CalData_t from here to avoid redefinition error
} // namespace tha
#endif // !JOBTHA_INPUT_H