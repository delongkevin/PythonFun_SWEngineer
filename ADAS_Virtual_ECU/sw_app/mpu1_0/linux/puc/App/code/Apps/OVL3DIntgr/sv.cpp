#include "RenderThreadRunnable.h"
#include "sv.h"
#include "DataProviderOvl3D.h"
#include "variants/VariantHelper.h"
#include "event.h"
#include <malloc.h>
#include <string.h>
#include <math.h>
#include <utils/mem/include/app_mem.h>
#include <variants/Enums.h>
#include "tweak.h"
#define HMI_PROFILING 0
#if HMI_PROFILING
#include <ti/osal/TimerP.h>
#endif
//#define GPIO_TIMING_MEASURE_ENA
#if defined(GPIO_TIMING_MEASURE_ENA)
    #include <sys/mman.h>
#endif
#ifdef ENABLE_RUNTIME_STATS
#define PROFILE_AlgoViewThread     (1u)
#endif
#if PROFILE_AlgoViewThread
#include "osal/system/Clock.h"
static uint32_t v_AvgAlgoViewRuntime_u32 = 0;
static uint32_t v_AlgoViewRunCntr_u32 = 0;
static uint32_t v_AvgAlgoViewPeriodicity_u32 = 0;
static uint32_t v_AlgoViewPreviousTime_u32 = 0;
static uint32_t v_AlgoViewRuntimeData = 0;
static PerformanceStatsEnable_t PerformanceStatsSVEnable_dp; 
#endif
/**> Camera params */
static const int CWidth = 1920, CHeight = 1280;

/**> Default log level */
int LOG_LEVEL = 0;

/**> Toggle background colors */
int BACKGROUND_DEBUG = 0;

/**> Intensity modulation */
int INTENSITY_DEBUG = 0;

/**> Use png instead of cameras */
#ifdef ENABLE_STATIC_IMAGE
bool use_png = true;
#else
bool use_png = false;
#endif

/**> IP for tweak tool */
const char *SERV_IP_ADR = "192.168.2.3";

/**> Enable tweak-server interface */
//#define USE_TWEAK

/**> Dump FPS in console */
//#define DUMP_FPS

/**> Disable ODO overlay temporarily */
#define ENABLE_ODO              0

/**> THA response */
static int IsTouchValid = 0;
float32_t THA_cplr_raw_pos[2] = {0.0f, 0.0f};
static const uint16_t THA_ALGO_VIEW_WIDTH = 640u;
static const uint16_t THA_ALGO_VIEW_HEIGHT = 400u;

/**> THA PROGRESS BAR */
static const uint8_t THA_PROGRESS_MAX = 100u;
static const int8_t  THA_PROGRESS_MIN = 0;
static const float32_t  THA_PRG_FILTER_ALPHA = 0.25f;
/**> Gaussian filter tuned to convert pixel to mm
     y = 9198.27*e^(-(x - 244.6905)^2/(2*66.73582^2)) */
#define PIXEL_TO_DISTACE_GAUSSIAN(pix) (9198.27 * exp(-pow(pix - 244.6905, 2)/8907.34))
static const int     THA_DELTA_THRESHOLD2 = 11;
static const int     THA_DELTA_THRESHOLD2_MM = 18;

/**> Read camera parameters from framework */
#define USE_CAMERA_PARAMETERS

/**> Camera failure mask */
static uint32_t __camera_failure, __camera_failure_prev;

/**> Camera failure state update */
extern "C" void camera_failure_update(int id, int failure)
{
    if (failure)
    {
        __camera_failure |= 1 << id;
    }
    else
    {
        __camera_failure &= ~(1 << id);
    }
}

/**> Camera test mask */
static uint32_t __camera_test, __camera_test_prev;

/**> Camera test state update */
extern "C" void camera_test_update(int id, int test)
{
    if (test)
    {
        __camera_test |= 1 << id;
    }
    else
    {
        __camera_test &= ~(1 << id);
    }
}

#ifdef USE_TWEAK
extern "C" void tweak_on_connect(void *cdata)
{
    ovl3d::sv*     v_sv_po = reinterpret_cast<ovl3d::sv*>(cdata);

    ME_Debugger_F_Printf_v("tweak-server connected\n");

    v_sv_po->tweak_on_connect_v();
}
#endif

/************************************************/

namespace ovl3d
{

sv::sv(IDataProviderOvl3D* i_DataProvider_ro):dataProvider_po(i_DataProvider_ro)
{
    memset(&renderContext_t, 0, sizeof(renderContext_t));
    memset(&windowInfo_t, 0, sizeof(windowInfo_t));
    memset(&cfg_t, 0, sizeof(cfg_t));
    memset(textures_aapo, 0, sizeof(textures_aapo));
    cameraFailure_u8 = 0U;
    vm_po = NULL;
    display_po = NULL;
    window_po = NULL;
    inited_b = false;
    png_po = NULL;

    if (getenv("SVS_STATIC_IMAGE") != NULL)
    {
        use_png = true;
    }
}

/// @brief  Class destructor
sv::~sv()
{
    deinit_v();
}

static uint8_t convertServiceCalibStatus(uint8_t flag_Proc_b, uint8_t flag_Pause_b, uint8_t flag_Nok_b, uint8_t flag_Ok_b)
{
    uint8_t status = (uint8_t)AIM_STATUS_INACTIVE;
    if (flag_Proc_b)
    {
        status = (uint8_t)AIM_STATUS_PROCESSING;
    }
    else if (flag_Pause_b)
    {
        status = (uint8_t)AIM_STATUS_PAUSE;
    }
    else if (flag_Nok_b)
    {
        status = (uint8_t)AIM_STATUS_FAILURE;
    }
    else if (flag_Ok_b)
    {
        status = (uint8_t)AIM_STATUS_SUCCESS;
    }

    return status;
}

static bool_t updateServiceCalib_b(const OverlayBits_s* overlay_bits, aiming_state_t* aiming_state)
{
    bool_t upd = false;

    uint32_t progress = 0;
    progress = (overlay_bits->SrvPrgBar25Per_b) ? 25 : progress;
    progress = (overlay_bits->SrvPrgBar50Per_b) ? 50 : progress;
    progress = (overlay_bits->SrvPrgBar75Per_b) ? 75 : progress;
    progress = (overlay_bits->SrvPrgBar100Per_b) ? 100 : progress;

    uint8_t camera_front_status = convertServiceCalibStatus(overlay_bits->SrvCamIndFrNone_b, overlay_bits->SrvCamIndFrPend_b, overlay_bits->SrvCamIndFrNok_b, overlay_bits->SrvCamIndFrOk_b);
    uint8_t camera_rear_status = convertServiceCalibStatus(overlay_bits->SrvCamIndBaNone_b, overlay_bits->SrvCamIndBaPend_b, overlay_bits->SrvCamIndBaNok_b, overlay_bits->SrvCamIndBaOk_b);
    uint8_t camera_left_status = convertServiceCalibStatus(overlay_bits->SrvCamIndLeNone_b, overlay_bits->SrvCamIndLePend_b, overlay_bits->SrvCamIndLeNok_b, overlay_bits->SrvCamIndLeOk_b);
    uint8_t camera_right_status = convertServiceCalibStatus(overlay_bits->SrvCamIndRiNone_b, overlay_bits->SrvCamIndRiPend_b, overlay_bits->SrvCamIndRiNok_b, overlay_bits->SrvCamIndRiOk_b);

    uint8_t common_status = convertServiceCalibStatus(overlay_bits->SrvChkIndRun_b, overlay_bits->SrvChkIndCondNok_b, overlay_bits->SrvChkIndNok_b, overlay_bits->SrvChkIndOk_b);

    if (progress != aiming_state->camera_progress[0])
    {
        aiming_state->camera_progress[0] = progress;
        upd = true;
    }

    if (common_status != aiming_state->status)
    {
        aiming_state->status = common_status;
        upd = true;
    }

    uint8_t talbe_ap_inp[] = {
        overlay_bits->SrvSpOmIndNok_b,
        overlay_bits->SrvStAngIndNok_b,
        camera_front_status,
        camera_left_status,
        camera_rear_status,
        camera_right_status
    };

    int32_t* talbe_ap_out[] = {
        &aiming_state->inv_speed,
        &aiming_state->inv_steering,
        &aiming_state->camera_status[SV_CAMERA_FRONT],
        &aiming_state->camera_status[SV_CAMERA_LEFT],
        &aiming_state->camera_status[SV_CAMERA_REAR],
        &aiming_state->camera_status[SV_CAMERA_RIGHT]
    };

    uint32_t table_size = sizeof(talbe_ap_inp) / sizeof(talbe_ap_inp[0]);
    for (int i = 0; i < table_size; i++)
    {
        if (talbe_ap_inp[i] != *talbe_ap_out[i])
        {
            *talbe_ap_out[i] = talbe_ap_inp[i];
            upd = true;
        }
    }

    return upd;
}

// Raw to world co-ordinate conversion on view 32
// Description: Converts the given raw x and y value to world x and y co-ordinates with given reference z world value
// Inputs:
// raw_x - x value on raw view co-ordinates
// raw_y - y value on raw view co-ordinates
// refWorld_z - world Z reference value for conversion in mm
// Outputs:
// result_xy[0] -> Calculated X value (longitudinal) value in mm
// result_xy[1] -> Calculated Y value (lateral) value in mm
void sv::raw_2_world_v_rear(float32_t raw_x, float32_t raw_y, int32_t refWorld_z, float32_t result_xy[2])
{
    view_manager_raw_2_world_rear(vm_po, raw_x, raw_y, refWorld_z, result_xy);
}
 

// THA overlay start position configuration in world xyz value with reference to rear bumper position
// Description: Starts the THA overlay from given 3D reference point (x is relative to rear bumper position)
// Inputs:
// world_x - 3D world x value in mm from rear bumper offset
// world_y - 3D world y value in mm
// world_z - 3D world z value in mm from ground
void sv::update_hitch_position_v(int32_t world_x, int32_t world_y, int32_t world_z)
{
    cfg_vehicle_t* vehicle_data = &cfg_t.vehicle;
    cfg_guide_tha_t* tha = &cfg_t.guide.tha;

    tha->offset[2] = world_z;
    tha->offset[1] = world_y;
    tha->offset[0] = world_x;

    view_manager_update_guide(vm_po);
}

/// @brief  Setup camera parameters
void sv::setupCameraParams_v(sensor::CameraParams& i_meclCfg_ro, uint32_t i_camera_u32)
{
    // ignore request if we are running from external images
    if (use_png == true)
        return;

    sensor::Pinhole_t::Config_s     v_PinholeCfg_rs;
    sensor::LensRadial_t::Config_s  v_LensRadialCfg_rs;
    sensor::Sensor_t::Config_s      v_SensorCfg_rs;

    i_meclCfg_ro.getRealCameraCfg_b(v_PinholeCfg_rs, v_LensRadialCfg_rs, v_SensorCfg_rs);

    mecl::core::RotationMatrix<float32_t>::EulerAngles_s v_EulerAngles_s;
    mecl::core::Point3D<float32_t>::Config_s  v_Translation_s;
    mecl::model::PreRoll_e  v_PreRoll_e;

    v_EulerAngles_s = v_PinholeCfg_rs.extrinsic_s.eulerAngles_s;
    v_Translation_s = v_PinholeCfg_rs.extrinsic_s.pos_x;
    v_PreRoll_e = v_PinholeCfg_rs.extrinsic_s.preRoll_e;

    // extrinsics (yaw and roll seem to be inverted - tbd)
    float32_t   v_angle_af32[3] = {
        -v_EulerAngles_s.yaw_x, v_EulerAngles_s.pitch_x, -v_EulerAngles_s.roll_x
    };

    float32_t   v_pos_af32[3] = {
        v_Translation_s.cVal_ax[0], v_Translation_s.cVal_ax[1], v_Translation_s.cVal_ax[2]
    };

    float32_t   ME_angle_copy[3] = {
        v_EulerAngles_s.yaw_x, v_EulerAngles_s.pitch_x, v_EulerAngles_s.roll_x
    };

    float32_t   ME_pos_copy[3] = {
        v_Translation_s.cVal_ax[0], v_Translation_s.cVal_ax[1], v_Translation_s.cVal_ax[2]
    };

    // convert camera extrinsics from Magna to internal (ISO) format
    camera_set_magna_extrinsics(&cfg_t, i_camera_u32, v_angle_af32, v_pos_af32);

    // intrinsics
    float32_t   v_FocalX = v_PinholeCfg_rs.intrinsic_s.foclX_x;
    float32_t   v_FocalY = v_PinholeCfg_rs.intrinsic_s.foclY_x;
    mecl::core::Point2D<float32_t>::Config_s v_pppCfg_x = v_PinholeCfg_rs.intrinsic_s.pppCfg_x;
    //ME_Debugger_F_Printf_v("#Camera %d PinHole: v_FocalX=%f, v_FocalY=%f, v_EulerAngles_s=%f, v_Translation_s=%f, v_PreRoll_e=%f\n", i_camera_u32, v_FocalX, v_FocalY, v_EulerAngles_s, v_Translation_s, v_PreRoll_e);
    // polynomials
    float32_t   (&world2image_x)[6] = v_LensRadialCfg_rs.world2image_x;
    float32_t   (&image2world_x)[6] = v_LensRadialCfg_rs.image2world_x;

    // sensor data
    mecl::core::Point2D<float32_t>::Config_s   pppCfg_x;
    mecl::core::Point2D<float32_t>::Config_s   pszCfg_x;

    pppCfg_x = v_SensorCfg_rs.pppCfg_x;
    pszCfg_x = v_SensorCfg_rs.pszCfg_x;
    //ME_Debugger_F_Printf_v("#Camera %d SensorData: v_FocalX=%f, pppCfg_x=%f, pszCfg_x=%f\n", i_camera_u32, pppCfg_x, pszCfg_x);
    cfg_camera_t*   v_camera_po = &cfg_t.camera[i_camera_u32];

    // set distortion polynomial
    v_camera_po->distortion[0] = world2image_x[2] / world2image_x[1];
    v_camera_po->distortion[1] = world2image_x[3] / world2image_x[1];
    v_camera_po->distortion[2] = world2image_x[4] / world2image_x[1];
    v_camera_po->distortion[3] = world2image_x[5] / world2image_x[1];

    // set camera matrix
    v_camera_po->intrinsics[0 * 3 + 0] = v_FocalX / pszCfg_x.cVal_ax[0] * world2image_x[1];
    v_camera_po->intrinsics[1 * 3 + 1] = v_FocalY / pszCfg_x.cVal_ax[1] * world2image_x[1];
    v_camera_po->intrinsics[0 * 3 + 2] = pppCfg_x.cVal_ax[0];
    v_camera_po->intrinsics[1 * 3 + 2] = pppCfg_x.cVal_ax[1];

    // ME_Debugger_F_Printf_v("\ncam-%u: parameters updated\n", i_camera_u32);
    // ME_Debugger_F_Printf_v("\n########## intrinsics[0]: %f , intrinsics[4] : %f ,  intrinsics[2] : %f, intrinsics[5] :%f\n", v_camera_po->intrinsics[0 * 3 + 0],v_camera_po->intrinsics[1 * 3 + 1],v_camera_po->intrinsics[0 * 3 + 2],v_camera_po->intrinsics[1 * 3 + 2]);
#if 0
    static float32_t cpy_ME_pos_copy[4][3];
    static float32_t cpy_ME_angle_copy[4][3];
    static float32_t cpy_distortion[4][4];
    static float32_t cpy_intrinsics[4][9];

    if (
        false
        || memcmp(&cpy_ME_pos_copy[i_camera_u32], ME_pos_copy, sizeof(ME_pos_copy))
        || memcmp(&cpy_ME_angle_copy[i_camera_u32], ME_angle_copy, sizeof(ME_angle_copy))
        || memcmp(&cpy_distortion[i_camera_u32], v_camera_po->distortion, sizeof(v_camera_po->distortion))
        || memcmp(&cpy_intrinsics[i_camera_u32], v_camera_po->intrinsics, sizeof(v_camera_po->intrinsics))  
    )
    {
        memcpy(&cpy_ME_pos_copy[i_camera_u32], ME_pos_copy, sizeof(ME_pos_copy));
        memcpy(&cpy_ME_angle_copy[i_camera_u32], ME_angle_copy, sizeof(ME_angle_copy));
        memcpy(&cpy_distortion[i_camera_u32], v_camera_po->distortion, sizeof(v_camera_po->distortion));
        memcpy(&cpy_intrinsics[i_camera_u32], v_camera_po->intrinsics, sizeof(v_camera_po->intrinsics));

        ME_Debugger_F_Printf_v("position : [ %f , %f , %f ], #[X, Y, Z] in mm \n",
                    ME_pos_copy[0],
                    ME_pos_copy[1],
                    ME_pos_copy[2]);

        ME_Debugger_F_Printf_v("rotation : [ %f , %f , %f ], #[P, Y, R] in deg \n",
                    ME_angle_copy[1]*(180/M_PI),
                    ME_angle_copy[0]*(180/M_PI),
                    ME_angle_copy[2]*(180/M_PI));

        ME_Debugger_F_Printf_v("distortion : [ %f , %f , %f , %f ], \n",
                    v_camera_po->distortion[0],
                    v_camera_po->distortion[1],
                    v_camera_po->distortion[2],
                    v_camera_po->distortion[3]);

        ME_Debugger_F_Printf_v("intrinsics : [ %f , %f , %f , %f , %f , %f , %f , %f , %f ], \n",
                    v_camera_po->intrinsics[0],
                    v_camera_po->intrinsics[1],
                    v_camera_po->intrinsics[2],
                    v_camera_po->intrinsics[3],
                    v_camera_po->intrinsics[4],
                    v_camera_po->intrinsics[5],
                    v_camera_po->intrinsics[6],
                    v_camera_po->intrinsics[7],
                    v_camera_po->intrinsics[8]);
    }
#endif
}

/// @brief   Set cameras extrinsics/intrinsics
bool_t sv::updateCameras_b()
{
    bool_t  v_update_b = false;

    for (uint32_t v_camera_u32 = 0U; v_camera_u32 < 4U; v_camera_u32++)
    {
        sensor::CameraParams&   meclCfg_ro = dataProvider_po->getCameraParams_ro(static_cast<variants::Camera_t>(v_camera_u32));
        uint32_t                v_version_u32 = meclCfg_ro.getRealCameraCfgVersion_t();

        if (v_version_u32 != cameraVersion_au32[v_camera_u32])
        {
            setupCameraParams_v(meclCfg_ro, v_camera_u32);

            // update camera version
            cameraVersion_au32[v_camera_u32] = v_version_u32;

            v_update_b = true;
        }
    }

    return v_update_b;
}

/// @brief  get vehicle parameters from variant manager
void sv::getVehicleDesignValues_v(cfg_vehicle_t* vehicle)
{
    float32_t wheelBase_f = 0.f;
    float32_t width_f = 0.f;
    float32_t mirrors[2] = {0.f, 0.f};
    float32_t bumperFront_f = 0.f;
    float32_t bumperRear_f = 0.f;
    bool_t r = variants::ME_VariantHelper_GetWheelBase_b(&wheelBase_f);
    r &= variants::ME_VariantHelper_GetVehicleWidthAtFender_b(&width_f);
    r &= variants::ME_VariantHelper_GetFrontAndRearBumperPosX_b(&bumperFront_f, &bumperRear_f);
    r &= variants::ME_VariantHelper_GetLeftAndRightMirrorPosY_b(&mirrors[1], &mirrors[0]);
    
    if (r)
    {
        //ME_Debugger_F_Printf_v("\n####################### Reached Inside Function\n");
        // vehicle->length = bumperRear_f + bumperFront_f;
        // vehicle->width = width_f;
        // vehicle->width_mirrors = mirrors[1] - mirrors[0];
        // vehicle->wheel_base = wheelBase_f;
        // vehicle->front_overhang = bumperFront_f;
        // vehicle->rear_overhang = -bumperFront_f - wheelBase_f;
        //All vehicle values should be positive
        // vehicle->length = bumperRear_f + bumperFront_f;
        // vehicle->width = width_f;
        // vehicle->width_mirrors = mirrors[0] - mirrors[1];
        // vehicle->wheel_base = wheelBase_f;
        // vehicle->front_overhang = bumperFront_f;
        // vehicle->rear_overhang = bumperRear_f - wheelBase_f;
        vehicle->length = bumperRear_f - bumperFront_f;
        vehicle->width = width_f;
        vehicle->width_mirrors = mirrors[1] - mirrors[0];
        vehicle->wheel_base = wheelBase_f;
        vehicle->front_overhang = -bumperFront_f;
        vehicle->rear_overhang = bumperRear_f - wheelBase_f;
    }

    ME_Debugger_F_Printf_v("#Vehicle Design Data\nlength : %.2f, width : %.2f, width-mirrors: %.2f, wheelbase : %.2f, front-overhang :%.2f, rear-overhang : %.2f,\n",
        vehicle->length, vehicle->width, vehicle->width_mirrors, vehicle->wheel_base, vehicle->front_overhang, vehicle->rear_overhang);
}


#define MAX_CFG_FILE_SIZE 1024*512 // 512 Kb

typedef struct
{
    const char* section_name;
    const char* path_to_file;
    uint32_t    variant_num;
    uint32_t    file_offset;
}cfg_extension_t;

static cfg_extension_t cfg_extensions[VAR_ATTR_MAX] = {
    {"languages_1024x768", "languages_1024x768.yaml", 0, 0},
    {"languages_1200x900", "languages_1200x900.yaml", 0, 0},
    {"post-config", "post.yaml", 0, 0},
	{"custom_fcpv_view_position_data", "variant_base_info.yaml", 0, 0},
    {"custom_fcpv_view_rotation_data", "variant_base_info.yaml", 0, 0},
	{"custom_guideline_data", "variant_base_info.yaml", 0, 0},
    {"custom_vehicle_blind_area", "variant_base_info.yaml", 0, 0},
    {"tv_custom_hatched_cfg", "tv_custom.yaml", 0, 0},
};

void set_configuration(uint8_t posSelect, uint8_t rotSelect, uint8_t glSelect, uint8_t blindArea, uint8_t h_glSelect)
{
    cfg_extensions[FCPV_POSITION_DATA].variant_num = posSelect;
    cfg_extensions[FCPV_ROTATION_DATA].variant_num = rotSelect;
    cfg_extensions[FFC_GUIDELINE_DATA].variant_num = glSelect;
    cfg_extensions[BLIND_AREA].variant_num = blindArea;
    cfg_extensions[HATCHED_DATA].variant_num = h_glSelect;
}

void config_find_offsets(const char* cfg_path, cfg_extension_t* extension, uint32_t extension_numbers)
{
    uint32_t i,k;
    FILE* file = 0;
    char file_name[128];
    char buffer[512];

    for (i = 0; i < extension_numbers; i++)
    {
        if ((file != NULL) && strcmp(file_name, extension[i].path_to_file) != 0)
        {
            fclose(file);
            file = NULL;
        }

        if (file == NULL)
        {
            file = fopen(extension[i].path_to_file, "r");
            strcpy(file_name, extension[i].path_to_file);

            if (file == NULL)
            {
                continue;
            }

            while (1)
            {
                char* line = fgets(buffer, sizeof(buffer), file);

                if (line == NULL)
                {
                    break;
                }
                if (line[0] == '#' && (memcmp(line, "#SECTION", 8) == 0))
                {
                    char* section_name = line+9;
                    uint32_t section_name_len = strlen(section_name);
                    section_name[section_name_len - 1] = 0;

                    for (k = 0; k < extension_numbers; k++)
                    {
                        if (strcmp(section_name, extension[k].section_name) == 0)
                        {
                            extension[k].file_offset = ftell(file);
                            break;
                        }
                    }
                }
            }
        }
    }

    if (file != NULL)
    {
        fclose(file);
    }
}

char* config_builder(const char* cfg_path, cfg_extension_t* extension, uint32_t extension_numbers)
{
    config_find_offsets(cfg_path, extension, extension_numbers);
    FILE* f_cfg = NULL;
    char* output_buffer = (char*)malloc(MAX_CFG_FILE_SIZE);

    int32_t err = 0;
    uint32_t i;

    if (output_buffer == NULL)
    {
        ME_Debugger_F_Printf_v("failed to allocate memory\n");
        err = ENOMEM;
    }

    if (err == 0)
    {
        f_cfg = fopen(cfg_path, "r");

        if (f_cfg == NULL)
        {
            ME_Debugger_F_Printf_v("failed to open file: %s\n", cfg_path);
            err = ENOENT;
        }
    }

    FILE* file = 0;
    char file_name[128];

    if (err == 0)
    {
        char buffer[512];

        while (err == 0)
        {
            char* line = fgets(buffer, sizeof(buffer), f_cfg);

            if (line == NULL)
            {
                break;
            }

            strcat(output_buffer, line);

            if (line[0] == '#')
            {
                if (memcmp(line, "#include", 8) == 0)
                {
                    char* section_name = line+9;
                    uint32_t section_name_len = strlen(section_name);
                    section_name[section_name_len - 1] = 0;

                    for (i = 0; i < extension_numbers; i++)
                    {
                        if (strcmp(section_name, extension[i].section_name) == 0)
                        {
                            if ((file != NULL) && strcmp(file_name, extension[i].path_to_file) != 0)
                            {
                                fclose(file);
                                file = NULL;
                            }

                            if (file == NULL)
                            {

                                file = fopen(extension[i].path_to_file, "r");
                                strcpy(file_name, extension[i].path_to_file);

                                if (strstr(section_name,"languages"))
                                {
                                    config_set_languages_path(extension[i].path_to_file);
                                }

                                if (file == NULL)
                                {
                                    ME_Debugger_F_Printf_v("failed to open file: %s\n", extension[i].path_to_file);
                                    err = ENOENT;
                                    break;
                                }
                            }

                            fseek(file, extension[i].file_offset, SEEK_SET);

                            int32_t variant = -1;
                            while (1)
                            {
                                char* line = fgets(buffer, sizeof(buffer), file);

                                if (line == NULL)
                                {
                                    break;
                                }

                                if (line[0] == '#' && (memcmp(line, "#SECTION", 8) == 0))
                                {
                                    break;
                                }

                                if (line[0] == '#' && (memcmp(line, "#VARIANT", 8) == 0))
                                {
                                    char* variant_name = line+9;
                                    uint32_t variant_name_len = strlen(variant_name);
                                    variant_name[variant_name_len - 1] = 0;
                                    sscanf(variant_name, "%d", &variant);

                                    continue;
                                }

                                if (variant > (int32_t)extension[i].variant_num)
                                {
                                    break;
                                }

                                if (variant != (int32_t)extension[i].variant_num)
                                {
                                    continue;
                                }

                                strcat(output_buffer, line);
                            }
                        }
                    }
                }
            }
        }
    }

    //ME_Debugger_F_Printf_v("%s\n", output_buffer);

    if (err != 0)
    {
        ME_Debugger_F_Printf_v("failed to read file\n");
        free(output_buffer);
        output_buffer = NULL;
    }

    if (file != NULL)
    {
        fclose(file);
    }

    if(f_cfg)
    {
        fclose(f_cfg);
    }

    return output_buffer;
}

/// @brief  Set configuration
bool_t sv::setupConfig_b()
{
    if (chdir("/ti_fs/usr/lib/graphics/j721s2") != 0)
    {
        ME_Debugger_F_Printf_v("failed to set dir: %s\n", strerror(errno));
        return false;
    }

    static const uint32_t cfg_table[10][2] = {{0,0},
        {1280, 768}, //1
        {1024, 768}, //2
        {1920, 1200}, //3
        {1200, 1920}, //4
        {1920, 720}, //5
        {1920, 1200}, //6
        {1200, 900}, //7
        {1920, 720}, //8
        {1024, 768}  //9
        };

    uint32_t i;
    for (i = 0; i < sizeof(cfg_table) / sizeof(cfg_table[0]); i++)
    {
        if (dWidth_u32 == cfg_table[i][0] && dHeight_u32 == cfg_table[i][1])
        {
            break;
        }
    }

    const char* config_path = "config-my24dt_1200x900.yaml";
    uint8_t language_idx = 1;
    switch (i)
    {
    case 2:
        config_path = "config-my24dt_1024x768.yaml";
        language_idx = 0;
        ME_Debugger_F_Printf_v("Config1\n");
        break;

    case 7:
        config_path = "config-my24dt_1200x900.yaml";
        language_idx = 1;
        ME_Debugger_F_Printf_v("Config2\n");
        break;

    case 9:
        config_path = "config-my24dt_1024x768.yaml";
        language_idx = 0;
        ME_Debugger_F_Printf_v("Config3\n");
        break; 

    default:
        ME_Debugger_F_Printf_v("Theres no config file for this resolution: %dx%d\n", dWidth_u32, dHeight_u32);
        return false;
    }

    /// Select required language: put into cfg_extensions number of the language:
    /// and cfg_extensions[1].variant_num = 2;
    /// cfg_extensions[0] for 1024 cfg_extensions[1] for 1200 resolutions
    /// 0 - English -------------- 0x0B <
    /// 1 - UK-English ----------- 0x02 <
    /// 2 - EU-Spanish ----------- 0x03
    /// 3 - MEX-Spanish ---------- 0x0A
    /// 4 - CAN-French ----------- 0x0C <
    /// 5 - EU-French ------------ 0x04
    /// 6 - Italian---Full ------- 0x00
    /// 7 - Brazilian-Portuguese - 0x08 <
    /// 8 - EU-Portugese --------- 0x05
    /// 9 - Arabic --------------- 0x11
    /// 10 - German -------------- 0x01
    /// 11 - Dutch --------------- 0x07
    /// 12 - Polish -------------- 0x06
    /// 13 - Russian-Cyrillic----- 0x0D
    /// 14 - Turkish ------------- 0x09

    bool_t o_receive_status_b_p;
    ME_VehInp_to_IpcSignals_t  v_VehSpdWhlSpdData_t = dataProvider_po->getVehInp_CAN_to_IPC_Data_t(&o_receive_status_b_p);
    switch (v_VehSpdWhlSpdData_t.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.LanguageSelection) {
        case 0x00: //Italian
            cfg_extensions[language_idx].variant_num = 6;
            break;
        case 0x02: // English
            cfg_extensions[language_idx].variant_num = 1; 
            break;
        case 0x03: // Espanol
            cfg_extensions[language_idx].variant_num = 2; 
            break;
        case 0x04: // Francais
            cfg_extensions[language_idx].variant_num = 5; 
            break;
        case 0x05: // Portugese
            cfg_extensions[language_idx].variant_num = 8; 
            break;
        case 0x08: // Brazilian
            cfg_extensions[language_idx].variant_num = 7; 
            break;
        case 0x0A: // Mexican
            cfg_extensions[language_idx].variant_num = 3; 
            break;
        case 0x0B: // English_US
            cfg_extensions[language_idx].variant_num = 0; 
            break;
        case 0x0C: // Canadian
            cfg_extensions[language_idx].variant_num = 4; 
            break;
        case 0x11: // Arabic
            cfg_extensions[language_idx].variant_num = 9; 
            break;
        case 0x01: // German
            cfg_extensions[language_idx].variant_num = 10; 
            break;
        case 0x07: // Dutch
            cfg_extensions[language_idx].variant_num = 11; 
            break;
        case 0x06: // Polish
            cfg_extensions[language_idx].variant_num = 12; 
            break;
        case 0x0D: // Russian-Cyrillic
            cfg_extensions[language_idx].variant_num = 13; 
            break;
        case 0x09: // Turkish
            cfg_extensions[language_idx].variant_num = 14; 
            break;
        default: // English_US
            cfg_extensions[language_idx].variant_num = 0; 
            break;
    }

    uint8_t variantId_f = 0;
    variants::ME_VariantHelper_GetVariantID_b(&variantId_f); //get variant ID
    
    uint8_t glSelect = 0;
    uint8_t posSelect = 0;
    uint8_t rotSelect = 0;
    uint8_t h_glSelect = 0;
    uint8_t blindArea = 0;
    
    /* Get position, rotation values as per variant selection */
    cfg_get_vehModel_pos_rot(variantId_f, &posSelect, &rotSelect);

    /* Get ffc-width values as per variant selection */
    cfg_get_vehModel_gl(variantId_f, &glSelect);
    
    /* Get obs zone as per variant selection */
    cfg_get_vehModel_hatchedZone(variantId_f, &h_glSelect);

    /* Get blind area as per variant selection */
    cfg_get_vehModel_blind_area(variantId_f, &blindArea);

    /* Set position, rotation, ffc width, blind area and hatched gls as per variant selection */
    set_configuration(posSelect, rotSelect, glSelect, blindArea, h_glSelect);

    char* data = config_builder(config_path, cfg_extensions, sizeof(cfg_extensions) / sizeof(cfg_extensions[0]));
    
    /* ...parse global configuration file */
    int r = config_parse(&cfg_t, (char*)data, strlen(data));
    /*KuSa- Start*/
    updateSteeringCoeff();  //overwrite configuration with the coeeficients as per variants data
    /*KuSa- End*/
    free(data);

    if (r != 0)
    {
        ME_Debugger_F_Printf_v("failed to parse config file: %s\n", strerror(errno));
        return false;
    }

    getVehicleDesignValues_v(&cfg_t.vehicle);

#ifdef USE_CAMERA_PARAMETERS
    // reset camera parameters version
    for (uint32_t v_camera_u32 = 0U; v_camera_u32 < 4U; v_camera_u32++)
    {
        sensor::CameraParams&   meclCfg_ro = dataProvider_po->getCameraParams_ro(static_cast<variants::Camera_t>(v_camera_u32));
        uint32_t                v_version_u32 = meclCfg_ro.getRealCameraCfgVersion_t();

        bool_t                  v_Success_b;

        if (1)
        {
            sensor::Pinhole_t::Config_s     b_Config_ro;

            v_Success_b = variants::ME_VariantHelper_GetCameraRotation_b(static_cast<variants::Camera_t>(v_camera_u32), &b_Config_ro.extrinsic_s.eulerAngles_s.pitch_x, &b_Config_ro.extrinsic_s.eulerAngles_s.yaw_x, &b_Config_ro.extrinsic_s.eulerAngles_s.roll_x);

            // convert from degrees (tool) to radians
            b_Config_ro.extrinsic_s.eulerAngles_s.pitch_x = mecl::math::toRadians_x(b_Config_ro.extrinsic_s.eulerAngles_s.pitch_x);
            b_Config_ro.extrinsic_s.eulerAngles_s.yaw_x   = mecl::math::toRadians_x(b_Config_ro.extrinsic_s.eulerAngles_s.yaw_x);
            b_Config_ro.extrinsic_s.eulerAngles_s.roll_x  = mecl::math::toRadians_x(b_Config_ro.extrinsic_s.eulerAngles_s.roll_x);

            v_Success_b = variants::ME_VariantHelper_GetCameraPosition_b(static_cast<variants::Camera_t>(v_camera_u32), &b_Config_ro.extrinsic_s.pos_x.cVal_ax[0],
                                                                         &b_Config_ro.extrinsic_s.pos_x.cVal_ax[1],
                                                                         &b_Config_ro.extrinsic_s.pos_x.cVal_ax[2]) && v_Success_b;

            ME_Debugger_F_Printf_v("cam-%u design: a=%f,%f,%f, t=%f,%f,%f", v_camera_u32,
                                   b_Config_ro.extrinsic_s.eulerAngles_s.pitch_x, b_Config_ro.extrinsic_s.eulerAngles_s.yaw_x, b_Config_ro.extrinsic_s.eulerAngles_s.roll_x,
                                   b_Config_ro.extrinsic_s.pos_x.cVal_ax[0], b_Config_ro.extrinsic_s.pos_x.cVal_ax[1], b_Config_ro.extrinsic_s.pos_x.cVal_ax[2]);
        }

        if (1)
        {
            sensor::LensRadial_t::Config_s b_Config_ro;
            variants::Camera_t  cameraID_t = static_cast<variants::Camera_t>(v_camera_u32);

            v_Success_b = ME_VariantHelper_GetCameraLensMaxElevation_b(cameraID_t, &b_Config_ro.elevationMaxCfg_x);
            v_Success_b        = v_Success_b && ME_VariantHelper_GetCameraLensImageToWorld_b(cameraID_t, &b_Config_ro.image2world_x[0], variants::e_CoefficientsCount);
            v_Success_b        = v_Success_b && ME_VariantHelper_GetCameraLensWorldToImage_b(cameraID_t, &b_Config_ro.world2image_x[0], variants::e_CoefficientsCount);

            float32_t   (&world2image_x)[6] = b_Config_ro.world2image_x;

            ME_Debugger_F_Printf_v("cam-%u design: w2i=%f,%f,%f,%f,%f,%f", v_camera_u32,
                                   world2image_x[0], world2image_x[1], world2image_x[2], world2image_x[3], world2image_x[4], world2image_x[5]);
        }

        cameraVersion_au32[v_camera_u32] = v_version_u32;
        setupCameraParams_v(meclCfg_ro, v_camera_u32);
    }
#endif

    return true;
}

/// @brief  Algo-view generation thread
void* sv::algoViewProcessingThread_pv(void *i_Args_pv)
{
    sv*                     v_sv_po = reinterpret_cast<sv*>(i_Args_pv);
    container::OVL3DData*   v_ovl3d_po = v_sv_po->dataProvider_po->getOVL3DData_po();
    vehicle_state_t*        v_vehicle_po = vm_get_vehicle_state(v_sv_po->vm_po);
    mesh_gen_t*             v_meshGen_po = vm_get_mesh_gen(v_sv_po->vm_po);

    // enter event loop
    while (true)
    {
#if PROFILE_AlgoViewThread
    PerformanceStatsSVEnable_dp =  v_sv_po->dataProvider_po->get_PerformanceStatsEnable();
    static osal::Time start;
    volatile uint32_t v_Start_t = 0;
    volatile uint32_t v_End_t = 0;
    volatile uint32_t currPeriodicity = 0;
    if (TRUE ==  PerformanceStatsSVEnable_dp.RunTimeStatsEnable)
    {
        v_Start_t = __get_time_usec();
        currPeriodicity = v_Start_t - v_AlgoViewPreviousTime_u32;
    }
#endif        
        AlgoViewJob_s*  v_job_po;
        texture_data_t* v_textures_apo[NUM_CAMERAS];

        if ((v_job_po = v_ovl3d_po->algoViewJobGet_po()) != NULL)
        {
            Assert(v_job_po->output_apo != NULL);

            view_manager_lock(v_sv_po->vm_po);

            // update algo-view configuration if needed
            algo_view_update_cfg(v_job_po->algoView_po, v_meshGen_po, &v_sv_po->cfg_t, v_vehicle_po);

            // make local copy of textures (atomic)
            memcpy(v_textures_apo, v_sv_po->renderTextures_apo, sizeof(v_textures_apo));

            view_manager_unlock(v_sv_po->vm_po);

            ME_Mutex_Lock_t(&v_job_po->condvar_po->MEMutex_po);

            // render algo-view
            algo_view_render(v_job_po->algoView_po, v_textures_apo, v_job_po->output_apo, v_job_po->sync_ppo);
            v_job_po->timestamp_us = __get_time_usec();

            // notify data readiness
            ME_Condvar_Broadcast_t(v_job_po->condvar_po);

            ME_Mutex_UnLock_t(&v_job_po->condvar_po->MEMutex_po);
        }
#if PROFILE_AlgoViewThread
    if (TRUE ==  PerformanceStatsSVEnable_dp.RunTimeStatsEnable)
    {
        v_End_t = __get_time_usec();
        //ME_Debugger_F_Printf_v("AlgoViewThread: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
        v_AlgoViewRunCntr_u32++; //Increment the run counter for averaging purpose
        v_AvgAlgoViewPeriodicity_u32 = ((v_AvgAlgoViewPeriodicity_u32 * (v_AlgoViewRunCntr_u32 -1)) + currPeriodicity)/v_AlgoViewRunCntr_u32; //Average Periodicity
        v_AvgAlgoViewRuntime_u32 = ((v_AvgAlgoViewRuntime_u32 * (v_AlgoViewRunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_AlgoViewRunCntr_u32; //New Average  
        v_AlgoViewRuntimeData = (((v_AvgAlgoViewRuntime_u32/1000U)<<16U) | ((v_AvgAlgoViewPeriodicity_u32/1000U) & 0xFFFF));
        v_sv_po->dataProvider_po->setAlgoViewRuntime(v_AlgoViewRuntimeData);
        //ME_Debugger_F_Printf_v("AlgoView: E: %lld P: %lld \n", v_AvgAlgoViewRuntime_u32, v_AvgAlgoViewPeriodicity_u32);
        v_AlgoViewPreviousTime_u32 = v_Start_t;
    }
#endif        
    }
    return NULL;
}

int sv::context_init_cb(display_data_t *display, window_data_t *window, void *data)
{
    sv *v_sv_po = (sv*)data;

    if (!use_png)
    {
        for (uint32_t v_camera_u32 = 0U; v_camera_u32 < SV_CAMERAS_NUMBER; v_camera_u32++)
        {
            texture_data_t**    v_textures_apo = v_sv_po->textures_aapo[v_camera_u32];
            Pixmap_t*           v_pixmaps_apo = v_sv_po->pixmaps_aapo[v_camera_u32];

            for (uint32_t v_idx_u32 = 0U; v_idx_u32 < NUM_CAM_BUFS; v_idx_u32++)
            {
                v_textures_apo[v_idx_u32] = texture_create_native(v_pixmaps_apo[v_idx_u32], 1);
                if (!v_textures_apo[v_idx_u32])
                {
                    v_sv_po->clear_v();
                    return -EFAULT;
                }
            }
        }
    }
    else
    {
        png_image_desc_t desc[4] = {
            {
                .filename = (char*)"_camera_Front.png",
                .width = CWidth,
                .height = CHeight,
                .format = SCREEN_FORMAT_RGBA8888,
            },
            {
                .filename = (char*)"_camera_Left.png",
                .width = CWidth,
                .height = CHeight,
                .format = SCREEN_FORMAT_RGBA8888,
            },
            {
                .filename = (char*)"_camera_Rear.png",
                .width = CWidth,
                .height = CHeight,
                .format = SCREEN_FORMAT_RGBA8888,
            },
            {
                .filename = (char*)"_camera_Right.png",
                .width = CWidth,
                .height = CHeight,
                .format = SCREEN_FORMAT_RGBA8888,
            },
        };

        screen_context_t    v_context_po = display_screen_context(display);

        for (uint32_t v_idx_u32 = 0U; v_idx_u32 < NUM_CAMERAS; v_idx_u32++)
        {
            bsp::VideoInputBufferDesc2_t    v_desc_t;
            png_image_desc_t*               v_desc_po = &desc[v_idx_u32];

            if (v_sv_po->dataProvider_po->allocVideoBuffer_b(v_desc_po->width, v_desc_po->height, v_desc_po->format, 1U, v_desc_t) == true)
            {
                if (CreateVideoBufferPixmap_b(v_context_po, v_desc_t, (screen_pixmap_t*)&v_desc_po->priv) == false)
                {
                    ME_Debugger_F_Printf_v("failed to create pixmap");
                }
            }
        }

        v_sv_po->png_po = png_loader_init(desc, 4, 2, 33333);
        if (!v_sv_po->png_po)
            return -ENOMEM;
    }

    v_sv_po->vm_po = view_manager_create(&v_sv_po->cfg_t);
    if (!v_sv_po->vm_po)
    {
        ME_Debugger_F_Printf_v("view-manager init failed: %s\n", strerror(errno));
        return -EFAULT;
    }

    vehicle_state_t*    v_VehicleState_po = vm_get_vehicle_state(v_sv_po->vm_po);
    bool_t              o_receive_status_b_p;
    ScreenRequest_t     v_ScreenRequest_t = v_sv_po->dataProvider_po->getScreenRequest_t(&o_receive_status_b_p);
    OverlayBits_s       v_OverlayBits_s = v_ScreenRequest_t.MbSVS_bf_OverlayBitsReq;

    
#if TBD
    v_VehicleState_po->label_enable = v_OverlayBits_s.ViewLabelOvlEn;    
    v_VehicleState_po->exit_enable = v_OverlayBits_s.CamViewExitBtnOvlEn;
    v_VehicleState_po->check_enable = v_OverlayBits_s.CheckSurrLabelOvlEn;
    v_VehicleState_po->gl_disable = v_OverlayBits_s.DisGuideLineOvlInFault;
    v_VehicleState_po->front_gl_enable = v_OverlayBits_s.FrontGuideLineOvlEn;
    v_VehicleState_po->rear_gl_enable = v_OverlayBits_s.RearGuideLineOvEn;
    v_VehicleState_po->cta.target_lh = v_VehicleState_po->rcta.target_lh = v_OverlayBits_s.LeCTA_OvlEn;
    v_VehicleState_po->cta.target_rh = v_VehicleState_po->rcta.target_rh = v_OverlayBits_s.RiCTA_OvlEn;
#endif

    /* ...update variant configuration */
    cfg_overide_var_data(&v_sv_po->cfg_t);

#ifdef  USE_TWEAK
    // issue connection request (asynchronous)
    tweak_connect(static_cast<void*>(v_sv_po));
#endif

    return 0;
}

#ifdef  USE_TWEAK
/// @brief  Register tweak interface
void sv::tweak_on_connect_v()
{
    view_manager_lock(vm_po);
    vm_tweak_register(vm_po, &cfg_t);
    view_manager_unlock(vm_po);
}
#endif

/// @brief  Clear window background
void sv::drawBackground_v()
{
    glEnable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_SCISSOR_TEST);
    glDepthMask(GL_TRUE);
    glDisable(GL_CULL_FACE);

    static int count;

    if (BACKGROUND_DEBUG)
    {
        switch (count % 3)
        {
        case 0:
            glClearColor(0.8f, 0.0f, 0.0f, 0.0f);
            break;
        case 1:
            glClearColor(0.0f, 0.8f, 0.0f, 0.0f);
            break;
        default:
            glClearColor(0.0f, 0.0f, 0.8f, 0.0f);
        }
    }
    else
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    }

    count++;

    glClearDepthf(1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    render_context_set_view(&renderContext_t, NULL);
}

static void dump(const char *file, void *buf, int sz)
{
    FILE *fd;
    fd = fopen(file, "w");
    if(fd)
    {
        fwrite(buf, 1, sz, fd);
        fclose(fd);
        ME_Debugger_F_Printf_v("Dump OK\n");
    }
    else
    {
        ME_Debugger_F_Printf_v("Dump error\n");
    }
}


static inline void pack_uint16(uint16_t val, uint8_t* dst)
{
    uint32_t i;

    for (i = 0; i < 4; i++)
    {
        uint8_t t = (val >> (i*4)) & 15;
        dst[i] = (t << 4) + 8;
    }
}

static inline uint16_t unpack_uint16(uint8_t* src)
{
    uint16_t dst = 0;

    for (uint32_t i = 0; i < 4; i++)
    {
        dst |= ((src[i] >> 4) & 15) << (i*4);
    }

    return dst;
}

static uint16_t read_u16_from_rgba(uint8_t *rgba)
{
    uint8_t arr[4];

    // Read from G components of 4 pixels
    arr[0] = rgba[1];
    arr[1] = rgba[5];
    arr[2] = rgba[9];
    arr[3] = rgba[13];

    return unpack_uint16(arr);
}

static inline uint32_t cmap(uint32_t val)
{
    const uint32_t table[] = {
        variants::e_CameraHWFront,
        variants::e_CameraHWLeft,
        variants::e_CameraHWRear,
        variants::e_CameraHWRight};
    return table[val];
}

void sv::run_check_ctlvals_v()
{
    void* display_buffer = dataProvider_po->getRenderBuffer_pv(latestOutBufferIndx_u32);

    uint32_t width_u32 = 0;
    uint32_t height_u32 = 0;
    dataProvider_po->getResolutionInfo_v(width_u32, height_u32);

    uint32_t ctlval_mask = 0;
    uint32_t ctlval_coords[2];
    view_manager_get_ctlval_info(vm_po, &ctlval_mask, ctlval_coords);

    const uint32_t x = ctlval_coords[0];
    const uint32_t y = ctlval_coords[1];
    const uint32_t pixels_per_mark = 4U;

    if (display_buffer != NULL && width_u32 >= x + pixels_per_mark * NUM_CAMERAS && height_u32 > y)
    {
        /// Note: for the moment there is no way to get the stride from the data provider
        /// TODO: to extend the API of the data provider to get the stride and fmt info
        /// currently RGB only, but stride = width*4 is not guaranteed
        /// but it should be true for all requred resoulutions
        const uint32_t stride_x = 4U;
        const uint32_t stride_y = width_u32 * stride_x;

        uint8_t* mark_area = (uint8_t*)display_buffer + y * stride_y + x * stride_x;
        const uint32_t bytes_per_mark = pixels_per_mark * stride_x;

        appMemCacheInv(mark_area, bytes_per_mark * NUM_CAMERAS);

        uint16_t ctlvals[NUM_CAMERAS];
        bool_t ctlvalsValid[NUM_CAMERAS];

        for (uint32_t i = 0; i < NUM_CAMERAS; i++)
        {
            if (ctlval_mask & (1U << i))
            {
                ctlvals[cmap(i)] = read_u16_from_rgba(mark_area + bytes_per_mark * i);
                ctlvalsValid[cmap(i)] = true;
            }
            else
            {
                ctlvals[cmap(i)] = 0;
                ctlvalsValid[cmap(i)] = false;
            }
        }

        const bool_t ret = dataProvider_po->submitInputBufferVerificationRequest_b(latestIndex_u32, ctlvals, ctlvalsValid);
        if (!ret)
        {
            // Failure to submit means that submit buffer is full, which can happen if:
            // - mcu2_0 hanged or is slow to respond, or
            // - local request processing thread is not scheduled in time
            ME_Debugger_F_Printf_v("Error: failed to submit input buffer verification request\n");
        }
    }
    else
    {
        ME_Debugger_F_Printf_v("Error: invalid display buffer or buffer mark coordinates\n");
    }
}

/// @brief  Rendering function
void sv::draw_v()
{
    uint32_t    t0 = __get_time_usec();

    // prepare background
    drawBackground_v();

    uint32_t    t1 = __get_time_usec();

    // render new frame
    view_manager_render(vm_po, renderTextures_apo, &renderContext_t);

    uint32_t    t2 = __get_time_usec();

    // swap buffers - should not be done directly, I guess
    window_draw(window_po);
    run_check_ctlvals_v();

    uint32_t    t3 = __get_time_usec();

    // submit buffer to output pipe
    dataProvider_po->postWindow_b(dWidth_u32, dHeight_u32);

    uint32_t    t4 = __get_time_usec();

#ifdef DUMP_FPS
    static int count;
    float32_t fps = window_frame_rate_update(window_po);
    if (++count == 32)
    {
        if (LOG_LEVEL > 3)
            ME_Debugger_F_Printf_v("window-draw: %.2f, %u/%u/%u/%u (%u)\n", fps, (uint32_t)(t1 - t0), (uint32_t)(t2 - t1), (uint32_t)(t3 - t2), (uint32_t)(t4 - t3), (uint32_t)(t4 - t0));
        count = 0;
    }
#endif
}

/// @brief  Window rendering callback
void sv::redraw_cb(display_data_t *display, void *data)
{
    sv*     v_sv_po = reinterpret_cast<ovl3d::sv*>(data);

    v_sv_po->draw_v();
}

#if USE_GESTURES_FRAMEWORK
void sv::input_cb(display_data_t *display, void *data, widget_event_t *event)
{
    sv *This = (sv*)data;
    view_manager_t  *vm = This->vm_po;
    widget_gesture_event_t  *e = reinterpret_cast<widget_gesture_event_t*>(event);

    if (e->type == WIDGET_EVENT_GESTURE)
    {
        view_manager_gesture_event(vm, e->gesture, e->async);
    }
}
#endif

/// @brief  Initialize SVS data - tbd - rework
bool_t sv::init_b(bsp::Screen *screen, bsp::Window* window, Pixmap_t* _pixmaps, int cnt)
{
    bool_t      v_result_b = false;
    uint32_t    t0 = __get_time_usec();

    if (inited_b)
        return true;

    if (cnt != NUM_CAM_BUFS * NUM_CAMERAS)
        return false;

    dataProvider_po->getResolutionInfo_v(dWidth_u32, dHeight_u32);

    if (setupConfig_b() == false)
        return false;

    uint32_t    t1 = __get_time_usec();

    memcpy(pixmaps_aapo, _pixmaps, sizeof(pixmaps_aapo));


    display_po = display_create(screen->getContext_t(), dWidth_u32, dHeight_u32);
    if (!display_po)
        return false;

    uint32_t    t2 = __get_time_usec();

    cfg_t.vm.scale = 1.0f;
    windowInfo_t.width = dWidth_u32;//cfg.vm.width;
    windowInfo_t.height = dHeight_u32;//cfg.vm.height;
    windowInfo_t.title = "SV";
    windowInfo_t.init = context_init_cb;
    windowInfo_t.redraw = redraw_cb;
#if USE_GESTURES_FRAMEWORK
    windowInfo_t.event = input_cb;
#endif
    windowInfo_t.native = window->getWindowHandle_t();

    ME_Debugger_F_Printf_v("create window: %u*%u, native=%p\n", windowInfo_t.width, windowInfo_t.height, windowInfo_t.native);

    window_po = window_create(display_po, &windowInfo_t, this);
    if (!window_po)
        return false;

    // initialize shared OVL3D data
    dataProvider_po->getOVL3DData_po()->init_b(&cfg_t, screen->getContext_t());

    render_context_init(&renderContext_t, cfg_t.vm.width, cfg_t.vm.height, cfg_t.vm.scale);

    // algo-view rendering thread creation
    if (1)
    {
        // create graph processing thread
        ThreadHandle_s v_Thread_s;
        ME_Thread_Create_t(&v_Thread_s, algoViewProcessingThread_pv, this, ME_Thread_C_DefaultStackSize_t);
        ME_Thread_SetPriority_t(&v_Thread_s, e_PriorityRealtime);
        ME_Thread_SetName_t(&v_Thread_s, "AlgoViewThread");
    }

    inited_b = true;

    uint32_t    t3 = __get_time_usec();

    ME_Debugger_F_Printf_v("Initialization: %u/%u/%u (%u)\n", (t1 - t0), (t2 - t1), (t3 - t2), (t3 - t0));

    return true;
}

#if HMI_PROFILING
static uint64_t IPC_get_time, IPC_put_time;
static uint8_t LastScreenReq, LastScreenRes;
static osal::Time timer;
#endif

/// @brief  Update SVS state and produce new frame
void sv::update_v(uint32_t i_index_u32, uint32_t i_frameNum_u32, uint32_t i_video_buffer_inxd)
{
    container::OVL3DData*   v_ovl3d_po = dataProvider_po->getOVL3DData_po();
    png_job_t*              v_job_po;
    bool_t                  v_response_b;

    // process external signals - update view-manager state as appropriate
    v_response_b = updateState_b();

    if (!use_png)
    {
        // collect camera frames
        for(uint32_t v_i_u32 = 0U; v_i_u32 < NUM_CAMERAS; v_i_u32++)
        {
            texture_data_t* v_texture_po = textures_aapo[v_i_u32][i_index_u32];

            renderTextures_apo[v_i_u32] = (cameraFailure_u8 & (1U << v_i_u32) ? NULL : v_texture_po);
        }
    }
    else
    {
        // retrieve job from PNG loader (it's always static; why do I need that list? - tbd)
        v_job_po = png_get_next_job(png_po);

        // collect textures
        for (uint32_t v_i_u32 = 0; v_i_u32 < NUM_CAMERAS; v_i_u32++)
        {
            texture_data_t* v_texture_po = (v_job_po ? v_job_po->texture[v_i_u32] : NULL);

            renderTextures_apo[v_i_u32] = (cameraFailure_u8 & (1U << v_i_u32) ? NULL : v_texture_po);
        }
    }

    latestIndex_u32 = i_index_u32;
    latestOutBufferIndx_u32 = i_video_buffer_inxd;

    // notify all waiters on new input frame reception
    v_ovl3d_po->notifyFrame_v(i_frameNum_u32);

    // initiate rendering (in the same thread context - can be simplified further)
    window_schedule_redraw(window_po);

    // emit screen-response as needed
    if (v_response_b == true)
    {
        ScreenResponse_t    v_ScreenResponse_t;
        
        v_ScreenResponse_t.MeSVS_e_ViewEngResCode = lastScreenRequest_t.MeSVS_e_ViewEngReqCode;
        memcpy(&v_ScreenResponse_t.MbSVS_bf_OverlayBitsRes, &lastScreenRequest_t.MbSVS_bf_OverlayBitsReq ,sizeof(lastScreenRequest_t.MbSVS_bf_OverlayBitsReq));
        memcpy(&v_ScreenResponse_t.AP_HMI_ParkSlot[0], &lastScreenRequest_t.AP_HMI_ParkSlot[0], sizeof(lastScreenRequest_t.AP_HMI_ParkSlot[0]));
        memcpy(&v_ScreenResponse_t.AP_HMI_ParkSlot[1], &lastScreenRequest_t.AP_HMI_ParkSlot[1], sizeof(lastScreenRequest_t.AP_HMI_ParkSlot[1]));
        memcpy(&v_ScreenResponse_t.AP_HMI_ParkSlot[2], &lastScreenRequest_t.AP_HMI_ParkSlot[2], sizeof(lastScreenRequest_t.AP_HMI_ParkSlot[2]));
        memcpy(&v_ScreenResponse_t.AP_HMI_ParkSlot[3], &lastScreenRequest_t.AP_HMI_ParkSlot[3], sizeof(lastScreenRequest_t.AP_HMI_ParkSlot[3]));
        memcpy(&v_ScreenResponse_t.AP_HMI_ParkSlot[4], &lastScreenRequest_t.AP_HMI_ParkSlot[4], sizeof(lastScreenRequest_t.AP_HMI_ParkSlot[4]));
        memcpy(&v_ScreenResponse_t.AP_HMI_ParkSlot[5], &lastScreenRequest_t.AP_HMI_ParkSlot[5], sizeof(lastScreenRequest_t.AP_HMI_ParkSlot[5]));
        v_ScreenResponse_t.AP_HMI_SelectedSlot = lastScreenRequest_t.AP_HMI_SelectedSlot;
        v_ScreenResponse_t.AP_HMI_Fullscreen = lastScreenRequest_t.AP_HMI_Fullscreen;
        v_ScreenResponse_t.AP_HMI_TopBlackBanner = lastScreenRequest_t.AP_HMI_TopBlackBanner;
        v_ScreenResponse_t.AP_HMI_TopRedBanner = lastScreenRequest_t.AP_HMI_TopRedBanner;
        v_ScreenResponse_t.AP_HMI_BottomBlackBanner = lastScreenRequest_t.AP_HMI_BottomBlackBanner;
        v_ScreenResponse_t.MeSVS_e_THAScreenResponse = lastScreenRequest_t.MeSVS_e_THAScreenRequesttoA72;
        v_ScreenResponse_t.MeSVS_DesiredTrailerAngle = lastScreenRequest_t.MeSVS_DesiredTrailerAngle;
        v_ScreenResponse_t.MeSVS_ActualTrailerAngle = lastScreenRequest_t.MeSVS_ActualTrailerAngle;
        v_ScreenResponse_t.MeSVS_Orage_Arc_StartAngle = lastScreenRequest_t.MeSVS_Orage_Arc_StartAngle;
        v_ScreenResponse_t.MeSVS_Red_Arc_StartAngle = lastScreenRequest_t.MeSVS_Red_Arc_StartAngle;
        v_ScreenResponse_t.MeSVS_pct_ProgressBar = lastScreenRequest_t.MeSVS_pct_ProgressBar;
        v_ScreenResponse_t.MeSVS_px_CplrPosX = (uint16_t)THA_cplr_raw_pos[0];
        v_ScreenResponse_t.MeSVS_px_CplrPosY = (uint16_t)THA_cplr_raw_pos[1];
        v_ScreenResponse_t.MeSVS_px_ScrnTchX = lastScreenRequest_t.MeSVS_px_ScrnTchX;
        v_ScreenResponse_t.MeSVS_px_ScrnTchY = lastScreenRequest_t.MeSVS_px_ScrnTchY;
        v_ScreenResponse_t.THAViewZoomResponse = IsTouchValid;

        // submit screen response
        /*HMI Instance 4 - Sending View Response to MCU2_0*/
        #if HMI_PROFILING
            if(LastScreenRes != v_ScreenResponse_t.MeSVS_e_ViewEngResCode)
            {
                LastScreenRes = v_ScreenResponse_t.MeSVS_e_ViewEngResCode;
                IPC_put_time = timer.getTimeMsec_u64();
                #if defined(GPIO_TIMING_MEASURE_ENA)
                    /*GPIO LOW*/
                    volatile uint32_t* p = (uint32_t *)mmap_device_memory(NULL, 4u, PROT_READ|PROT_WRITE|PROT_NOCACHE,0, 0x42110044);
                    if(p == MAP_FAILED)
                    {
                    ME_Debugger_F_Printf_v("mmap called FAILED");
                    }
                    else
                    {
                    *p = 0x00000020; /* WKUP_GPIO0_37 Mask (Bank pins 63..32) */
                    //ME_Debugger_F_Printf_v("mmap called passed");
                    }
                #endif
                // ME_Debugger_F_Printf_v("GPIO 37 LOW\t");
                ME_Debugger_F_Printf_v("ID,%d,P4to5,%llu\n", v_ScreenResponse_t.MeSVS_e_ViewEngResCode, (IPC_put_time - IPC_get_time));
            }
        #endif

        dataProvider_po->setScreenResponse_v(v_ScreenResponse_t);
    }

    // release PNG job as needed
    if (use_png)
    {
        png_release_job(png_po, v_job_po);
    }
}

/**
 * @brief   Translate CTA/CTB CAN signals into internal CTA state
 */
static inline void fillCTAState(cta_state_t *cta,
                                uint8_t cta_state, uint8_t cta_target_lh, uint8_t cta_target_rh,
                                uint8_t ctb_state, uint8_t ctb_target_lh, uint8_t ctb_target_rh)
{
    cta->a_state = cta_state;
    cta->b_state = ctb_state;
    cta->a_target_lh = cta_target_lh;
    cta->a_target_rh = cta_target_rh;
    cta->b_target_lh = ctb_target_lh;
    cta->b_target_rh = ctb_target_rh;
}

/**
 * @brief   Get index of first failing camera
 */
static inline uint8_t getFailingCamera(aiming_state_t *aiming)
{
    uint8_t     v_camera_u8;

    if (aiming->failure & 0x03U)
    {
        v_camera_u8 = 0U;
    }
    else if (aiming->failure & 0x0CU)
    {
        v_camera_u8 = 1U;
    }
    else if (aiming->failure & 0x30U)
    {
        v_camera_u8 = 2U;
    }
    else
    {
        v_camera_u8 = 3U;
    }

    return v_camera_u8;
}

static ap_dynamic_slot_type cvt_park_slot_type(ParkingSlotType_t v)
{
    switch (v)
    {
    case ParkingSlotType_E_PW_NODIR:
        return CE_SLOT_NONE;
    case ParkingSlotType_E_PW_PARALLEL:
        return CE_SLOT_PARALLEL;
    case ParkingSlotType_E_PW_PERPENDICULAR:
        return CE_SLOT_PERP;
    default:
        return CE_SLOT_NONE;
    }
}

static bool_t update_ap(const ScreenRequest_t* screen_request, const OverlayBits_s* overlay_bits, vehicle_state_t* vehicle_state)
{
    uint8_t talbe_ap_inp[] = {
        overlay_bits->AP_BackBtn,
        overlay_bits->AP_BG_Main,
        overlay_bits->AP_Disclaimer_Core,
        overlay_bits->AP_ExitBtn_Not_Selected,
        overlay_bits->AP_ExitBtn_Selected,
        overlay_bits->AP_Forward_LeftBtn_Not_Selected,
        overlay_bits->AP_Forward_LeftBtn_Selected,
        overlay_bits->AP_Forward_RightBtn_Not_Selected,
        overlay_bits->AP_Forward_RightBtn_Selected,
        overlay_bits->AP_FrontInBtn_Not_Avail,
        overlay_bits->AP_FrontInBtn_Not_Selected,
        overlay_bits->AP_FrontInBtn_Selected,
        overlay_bits->AP_Grey_Banner1,
        overlay_bits->AP_Grey_Banner2,
        overlay_bits->AP_Para_Exit_Core,
        overlay_bits->AP_ParkBtn_Not_Selected,
        overlay_bits->AP_ParkBtn_Selected,
        overlay_bits->AP_ParkIn_Done,
        overlay_bits->AP_Parkout_Done,
        overlay_bits->AP_Perp_Left_Core,
        overlay_bits->AP_Perp_Right_Core,
        overlay_bits->AP_RearInBtn_Not_Avail,
        overlay_bits->AP_RearInBtn_Not_Selected,
        overlay_bits->AP_RearInBtn_Selected,
        overlay_bits->AP_Scan_Keep_Moving_Forward_Text,
        overlay_bits->AP_Scanning_Core,
        overlay_bits->AP_Scan_Reduce_Speed_Text,
        overlay_bits->AP_Scan_Searching_Text,
        overlay_bits->AP_Scan_Select_Space_Text,
        overlay_bits->AP_Scan_Space_Found_Text,
        overlay_bits->AP_Scan_STOP_Text,
    };

    uint8_t* talbe_ap_out[] = {
        &vehicle_state->ap.AP_BackBtn,
        &vehicle_state->ap.AP_BG_Main,
        &vehicle_state->ap.AP_Disclaimer_Core,
        &vehicle_state->ap.AP_ExitBtn_Not_Selected,
        &vehicle_state->ap.AP_ExitBtn_Selected,
        &vehicle_state->ap.AP_Forward_LeftBtn_Not_Selected,
        &vehicle_state->ap.AP_Forward_LeftBtn_Selected,
        &vehicle_state->ap.AP_Forward_RightBtn_Not_Selected,
        &vehicle_state->ap.AP_Forward_RightBtn_Selected,
        &vehicle_state->ap.AP_FrontInBtn_Not_Avail,
        &vehicle_state->ap.AP_FrontInBtn_Not_Selected,
        &vehicle_state->ap.AP_FrontInBtn_Selected,
        &vehicle_state->ap.AP_Grey_Banner1,
        &vehicle_state->ap.AP_Grey_Banner2,
        &vehicle_state->ap.AP_Para_Exit_Core,
        &vehicle_state->ap.AP_ParkBtn_Not_Selected,
        &vehicle_state->ap.AP_ParkBtn_Selected,
        &vehicle_state->ap.AP_ParkIn_Done,
        &vehicle_state->ap.AP_Parkout_Done,
        &vehicle_state->ap.AP_Perp_Left_Core,
        &vehicle_state->ap.AP_Perp_Right_Core,
        &vehicle_state->ap.AP_RearInBtn_Not_Avail,
        &vehicle_state->ap.AP_RearInBtn_Not_Selected,
        &vehicle_state->ap.AP_RearInBtn_Selected,
        &vehicle_state->ap.AP_Scan_Keep_Moving_Forward_Text,
        &vehicle_state->ap.AP_Scanning_Core,
        &vehicle_state->ap.AP_Scan_Reduce_Speed_Text,
        &vehicle_state->ap.AP_Scan_Searching_Text,
        &vehicle_state->ap.AP_Scan_Select_Space_Text,
        &vehicle_state->ap.AP_Scan_Space_Found_Text,
        &vehicle_state->ap.AP_Scan_STOP_Text,
    };

    bool_t upd = false;

    uint32_t table_size = sizeof(talbe_ap_inp) / sizeof(talbe_ap_inp[0]);
    for (int i = 0; i < table_size; i++)
    {
        if (talbe_ap_inp[i] != *talbe_ap_out[i])
        {
            *talbe_ap_out[i] = talbe_ap_inp[i];
            upd = true;
        }
    }

    if (vehicle_state->ap.AP_HMI_bottom_black != screen_request->AP_HMI_BottomBlackBanner)
    {
        vehicle_state->ap.AP_HMI_bottom_black = screen_request->AP_HMI_BottomBlackBanner;
        upd = true;
    }

    if (vehicle_state->ap.AP_HMI_fullscreen != screen_request->AP_HMI_Fullscreen)
    {
        vehicle_state->ap.AP_HMI_fullscreen = screen_request->AP_HMI_Fullscreen;
        upd = true;
    }

    if (vehicle_state->ap.AP_HMI_Top_red != screen_request->AP_HMI_TopRedBanner)
    {
        vehicle_state->ap.AP_HMI_Top_red = screen_request->AP_HMI_TopRedBanner;
        upd = true;
    }

    if (vehicle_state->ap.AP_HMI_top_black != screen_request->AP_HMI_TopBlackBanner)
    {
        vehicle_state->ap.AP_HMI_top_black = screen_request->AP_HMI_TopBlackBanner;
        upd = true;
    }

    if(0)
    {
        ME_Debugger_F_Printf_v("BBB:%d ",vehicle_state->ap.AP_HMI_bottom_black);
        ME_Debugger_F_Printf_v("FST:%d ",vehicle_state->ap.AP_HMI_fullscreen);
        ME_Debugger_F_Printf_v("TRB:%d ",vehicle_state->ap.AP_HMI_Top_red);
        ME_Debugger_F_Printf_v("TBB:%d \n",vehicle_state->ap.AP_HMI_top_black);
    }
    const AP_HMI_ParkSlot_t* park_slot = screen_request->AP_HMI_ParkSlot;
    uint32_t park_slot_size = sizeof(screen_request->AP_HMI_ParkSlot) / sizeof(screen_request->AP_HMI_ParkSlot[0]);

    if (1)
    {
        for (uint32_t i = 0; i < park_slot_size; i++)
        {
            if (
                cvt_park_slot_type(park_slot[i].SlotType) != vehicle_state->ap.ap_dynamic_slots[i].type ||
                park_slot[i].SlotSelected != vehicle_state->ap.ap_dynamic_slots[i].active ||
                park_slot[i].SlotPixelCoordinate_X != vehicle_state->ap.ap_dynamic_slots[i].x ||
                park_slot[i].SlotPixelCoordinate_Y != vehicle_state->ap.ap_dynamic_slots[i].y)
            {
                vehicle_state->ap.ap_dynamic_slots[i].type = cvt_park_slot_type(park_slot[i].SlotType);
                vehicle_state->ap.ap_dynamic_slots[i].active = park_slot[i].SlotSelected;
                vehicle_state->ap.ap_dynamic_slots[i].x = park_slot[i].SlotPixelCoordinate_X;
                vehicle_state->ap.ap_dynamic_slots[i].y = park_slot[i].SlotPixelCoordinate_Y;
                //ME_Debugger_F_Printf_v("Slot:%d, X:%d, Y:%d \n",i ,vehicle_state->ap.ap_dynamic_slots[i].x ,vehicle_state->ap.ap_dynamic_slots[i].y);
                upd = true;
            }
        }
    }

    return upd;
}

static uint32_t convert_zoom_bits(OverlayBits_s* overlay_bits)
{
    uint32_t bits[8] = {
                        overlay_bits->ZoomPlus_Not_Selectable_b,
                        overlay_bits->ZoomMinus_Not_Selectable_b,
                        overlay_bits->ZoomPlus_Selectable_b,
                        overlay_bits->ZoomMinus_Selectable_b,
                        overlay_bits->OneCam_ZoomPlus_Not_Selectable_b,
                        overlay_bits->OneCam_ZoomMinus_Not_Selectable_b,
                        overlay_bits->OneCam_ZoomPlus_Selectable_b,
                        overlay_bits->OneCam_ZoomMinus_Selectable_b
                        };

    uint32_t i;

    for (i = 0; i < 8; i++)
    {
        if (bits[i])
        {
            break;
        }
    }

    if (i == 8)
    {
        return 0;
    }
    else
    {
        return i + 1;
    }
}

/// @brief   Update view-manager state from shared memory
static uint32 THA_test_counter = 0;
bool_t sv::updateState_b()
{
    bool_t  			v_response_b = false;
    vehicle_state_t*    v_VehicleState_po = vm_get_vehicle_state(vm_po);
    bool_t              o_receive_status_b_p;
    ScreenRequest_t     v_ScreenRequest_t = dataProvider_po->getScreenRequest_t(&o_receive_status_b_p);
    //THARelated_ScreenReq_t v_ScreenRequest_t = dataProvider_po->getTHARelated_ScreenReq_t(&o_receive_status_b_p);
    OverlayBits_s       v_OverlayBits_s = v_ScreenRequest_t.MbSVS_bf_OverlayBitsReq;
    THA_HitchData_t     v_thaHitchData_t = dataProvider_po->getTHAHitchData_t();

    /*HMI Instance 3 - Reading View Request from MCU2_0*/
    #if HMI_PROFILING 
        if(LastScreenReq != v_ScreenRequest_t.MeSVS_e_ViewEngReqCode)
        {            
            LastScreenReq = v_ScreenRequest_t.MeSVS_e_ViewEngReqCode;
            IPC_get_time = timer.getTimeMsec_u64();
            #if defined(GPIO_TIMING_MEASURE_ENA)
                /*GPIO HIGH*/
                volatile uint32_t* p = (uint32_t *)mmap_device_memory(NULL, 4u, PROT_READ|PROT_WRITE|PROT_NOCACHE,0, 0x42110040);
                if(p == MAP_FAILED)
                {
                    ME_Debugger_F_Printf_v("mmap called FAILED");
                }
                else
                {
                    *p = 0x00000020; /* WKUP_GPIO0_37 Mask (Bank pins 63..32) */
                    //ME_Debugger_F_Printf_v("mmap called passed");
                }
            #endif
            // ME_Debugger_F_Printf_v("GPIO 37 HIGH\t");

        }
    #endif
#if 0 //THA TEST DATA
    v_ScreenRequest_t.MeSVS_e_THAScreenRequesttoA72 = (aSigConverter_E_THAScreenRequest_t)(THA_test_counter/200);
    
    if (v_ScreenRequest_t.MeSVS_e_THAScreenRequesttoA72 > 24)
    {
        THA_test_counter = 0;
        v_ScreenRequest_t.MeSVS_e_THAScreenRequesttoA72 = (aSigConverter_E_THAScreenRequest_t)0;    
    }

    (void)memset(&v_OverlayBits_s, 0, sizeof(v_OverlayBits_s));
    switch (v_ScreenRequest_t.MeSVS_e_THAScreenRequesttoA72)
    {
        case THA_Default:
        v_OverlayBits_s.THA_ButtonGrey = TRUE;
        v_ScreenRequest_t.MeSVS_e_ViewEngReqCode = 2u;
        break;

        case THA_Enable:
        v_OverlayBits_s.THA_ButtonSelectable = TRUE;
        v_ScreenRequest_t.MeSVS_e_ViewEngReqCode = 2u;
        break;

        case THA_TCS_Msg1:
        v_OverlayBits_s.THA_TriangleOverlay = TRUE;
        v_ScreenRequest_t.MeSVS_e_ViewEngReqCode = 32u;

        if ((uint8)(THA_test_counter%100) > 75u)
        {
        v_ScreenRequest_t.MeSVS_px_ScrnTchX = 600u;
        v_ScreenRequest_t.MeSVS_px_ScrnTchX = 600u;
        }
        else if ((uint8)(THA_test_counter%100) > 50u)
        {
        v_ScreenRequest_t.MeSVS_px_ScrnTchX = 100u;
        v_ScreenRequest_t.MeSVS_px_ScrnTchX = 300u;
        }
        else if ((uint8)(THA_test_counter%100) > 25u)
        {
        v_ScreenRequest_t.MeSVS_px_ScrnTchX = 1100u;
        v_ScreenRequest_t.MeSVS_px_ScrnTchX = 300u;
        }
        else if ((uint8)(THA_test_counter%100) > 0u)
        {
        v_ScreenRequest_t.MeSVS_px_ScrnTchX = 100u;
        v_ScreenRequest_t.MeSVS_px_ScrnTchX = 300u;
        }
        else
        {
            /*Do nothing*/
        }
        break;
        
        case THA_TCS_Msg2:
        v_OverlayBits_s.ZoomMinus_Selectable_b = TRUE;      
        v_OverlayBits_s.THA_CouplerBulletIcon = TRUE;
        v_ScreenRequest_t.MeSVS_e_ViewEngReqCode = 33u;

        if ((uint8)(THA_test_counter%100) > 75u)
        {
            v_ScreenRequest_t.MeSVS_px_CplrPosX = 600u;
            v_ScreenRequest_t.MeSVS_px_CplrPosY = 600u;
        }
        else if ((uint8)(THA_test_counter%100) > 50u)
        {
            v_ScreenRequest_t.MeSVS_px_CplrPosX = 100u;
            v_ScreenRequest_t.MeSVS_px_CplrPosY = 300u;
        }
        else if ((uint8)(THA_test_counter%100) > 25u)
        {
            v_ScreenRequest_t.MeSVS_px_CplrPosX = 1100u;
            v_ScreenRequest_t.MeSVS_px_CplrPosY = 300u;
        }
        else if ((uint8)(THA_test_counter%100) > 0u)
        {
            v_ScreenRequest_t.MeSVS_px_CplrPosX = 100u;
            v_ScreenRequest_t.MeSVS_px_CplrPosY = 300u;
        }
        else
        {
            /*Do nothing*/
        }
        break;
        
        case THA_TCS_Msg3:
        v_OverlayBits_s.ZoomMinus_Selectable_b = TRUE;
        v_OverlayBits_s.THA_CouplerBulletIcon = TRUE;
        v_OverlayBits_s.THA_ConfirmButton = TRUE;
        v_ScreenRequest_t.MeSVS_e_ViewEngReqCode = 34u;

        if ((uint8)(THA_test_counter%100) > 75u)
        {
            v_ScreenRequest_t.MeSVS_px_CplrPosX = 600u;
            v_ScreenRequest_t.MeSVS_px_CplrPosY = 600u;
        }
        else if ((uint8)(THA_test_counter%100) > 50u)
        {
            v_ScreenRequest_t.MeSVS_px_CplrPosX = 100u;
            v_ScreenRequest_t.MeSVS_px_CplrPosY = 300u;
        }
        else if ((uint8)(THA_test_counter%100) > 25u)
        {
            v_ScreenRequest_t.MeSVS_px_CplrPosX = 1100u;
            v_ScreenRequest_t.MeSVS_px_CplrPosY = 300u;
        }
        else if ((uint8)(THA_test_counter%100) > 0u)
        {
            v_ScreenRequest_t.MeSVS_px_CplrPosX = 100u;
            v_ScreenRequest_t.MeSVS_px_CplrPosY = 300u;
        }
        else
        {
            /*Do nothing*/
        }
        break;
        
        case THA_TCS_Msg4:
        v_ScreenRequest_t.MeSVS_e_ViewEngReqCode = 32u;
        v_OverlayBits_s.THA_ConfirmButton = TRUE;
        break;
        
        case THA_TCS_Msg5:
        v_ScreenRequest_t.MeSVS_e_ViewEngReqCode = 32u;
        v_OverlayBits_s.THA_StartButton = TRUE;
        break;
        
        case THA_SM_Msg1:
        v_ScreenRequest_t.MeSVS_e_ViewEngReqCode = 32u;
        break;
        
        case THA_SM_Msg2:
        v_ScreenRequest_t.MeSVS_pct_ProgressBar = (uint8)(THA_test_counter%150);
        if (v_ScreenRequest_t.MeSVS_pct_ProgressBar > 50)
        {
        v_ScreenRequest_t.MeSVS_e_ViewEngReqCode = 32u;
        }
        else
        {
        v_ScreenRequest_t.MeSVS_e_ViewEngReqCode = 34u;
        }
        v_OverlayBits_s.THA_ProgressBar = TRUE;
        break;
    
        case THA_CM_Msg1:
        case THA_CM_Msg2:
        case THA_CM_Msg3:
        case THA_CM_Msg4:
        case THA_CM_Msg5:
        case THA_CM_Msg6:
        case THA_CM_Msg7:
        case THA_CM_Msg8:
        case THA_CM_Msg9:
        case THA_CM_Msg10:
        v_ScreenRequest_t.MeSVS_e_ViewEngReqCode = 32u;
        break;
        
        case THA_EOM_Msg1:
        v_ScreenRequest_t.MeSVS_pct_ProgressBar = (uint8)(THA_test_counter%150);
        v_OverlayBits_s.THA_ProgressBar = TRUE;
        v_ScreenRequest_t.MeSVS_e_ViewEngReqCode = 34u;
        break;
        
        case THA_EOM_Msg2:
        v_OverlayBits_s.THA_ConfirmButton = TRUE;
        v_ScreenRequest_t.MeSVS_e_ViewEngReqCode = 34u;
        break;
        
        case THA_EOM_Msg3:
        v_ScreenRequest_t.MeSVS_e_ViewEngReqCode = 34u;
        break;
        
        case THA_EOM_Msg4:
        v_ScreenRequest_t.MeSVS_e_ViewEngReqCode = 34u;
        break;
        
        case THA_ERR_Msg1:
        v_ScreenRequest_t.MeSVS_e_ViewEngReqCode = 32u;
        break;
        
        case THA_ERR_Msg2:
        v_OverlayBits_s.THA_ConfirmButton = TRUE;
        v_ScreenRequest_t.MeSVS_e_ViewEngReqCode = 32u;
        break;
        
        default:
        break;
    }
    THA_test_counter++;
#endif 

    #if TBD
    VehSpdWhlSpdData_t  v_VehSpdWhlSpdData_t = dataProvider_po->getVehSpdWhlSpdData_t(&o_receive_status_b_p);
#endif
    ME_VehInp_to_IpcSignals_t  v_VehSpdWhlSpdData_t = dataProvider_po->getVehInp_CAN_to_IPC_Data_t(&o_receive_status_b_p);

#ifdef  USE_CAMERA_PARAMETERS
    // update cameras configuration as required
    if (updateCameras_b())
    {
        // force mesh recalculation
        view_manager_update_cameras(vm_po);
    }
#endif

    // check if view-id has changed
    if(memcmp(&v_ScreenRequest_t, &lastScreenRequest_t, sizeof(lastScreenRequest_t)))
    {
        if((v_ScreenRequest_t.MeSVS_e_ViewEngReqCode != lastScreenRequest_t.MeSVS_e_ViewEngReqCode))
        {
            uint8_t     v_ResponseCode_u8 = 0U;
            ME_Debugger_F_Printf_v("View-id changed: %d\n", v_ScreenRequest_t.MeSVS_e_ViewEngReqCode);
            // translate framework view id to internal code - tbd - make sure coding is the same

            if (view_manager_set_layout(vm_po, static_cast<int32_t>(v_ScreenRequest_t.MeSVS_e_ViewEngReqCode)) < 0)
            {
                // failed to set layout; put generic error code
                v_ResponseCode_u8 = 0xFFU;
            }
        }    
        // request sending of screen-response
        v_response_b = true;
    }

    // process camera failure
    uint8_t         v_cameraFailure_u8 = dataProvider_po->getCameraFailure_u8();

#ifdef USE_TWEAK
    // override status if needed
    (__camera_failure != 0 ? v_cameraFailure_u8 = __camera_failure : 0);

    // use camera failure mask from tweak-server - override current failure state
    if (__camera_failure_prev != __camera_failure)
    {
        v_cameraFailure_u8 = __camera_failure_prev = __camera_failure;
    }

    // use camera test mask from tweak-server
    if (__camera_test_prev != __camera_test)
    {
        uint32_t    diff = __camera_test ^ __camera_test_prev;

        if (diff & (1 << 0))
        {
            dataProvider_po->testPatternEnable_v(variants::e_CameraFront, (__camera_test & (1 << 0) ? true : false));
        }
        if (diff & (1 << 1))
        {
            dataProvider_po->testPatternEnable_v(variants::e_CameraLeft, (__camera_test & (1 << 1) ? true : false));
        }
        if (diff & (1 << 2))
        {
            dataProvider_po->testPatternEnable_v(variants::e_CameraRear, (__camera_test & (1 << 2) ? true : false));
        }
        if (diff & (1 << 3))
        {
            dataProvider_po->testPatternEnable_v(variants::e_CameraRight, (__camera_test & (1 << 3) ? true : false));
        }

        __camera_test_prev = __camera_test;
    }
#endif

    if ((v_cameraFailure_u8 != cameraFailure_u8) || 
        (v_OverlayBits_s.RightCam_NA_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.RightCam_NA_b) || // SVS  FID based degradation implementation added using ovl bits
        (v_OverlayBits_s.BackCam_NA_b  != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.BackCam_NA_b ) ||
        (v_OverlayBits_s.LeftCam_NA_b  != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.LeftCam_NA_b ) ||
        (v_OverlayBits_s.FrontCam_NA_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.FrontCam_NA_b))
    {
        // camera failure status changed
        uint8_t*    v_enable_pu8 = v_VehicleState_po->no_camera_enable;
        bool_t      v_update_b = false;
        uint8_t v_svsCamFidSts_u8[NUM_CAMERAS] = { v_OverlayBits_s.FrontCam_NA_b, v_OverlayBits_s.LeftCam_NA_b, v_OverlayBits_s.BackCam_NA_b, v_OverlayBits_s.RightCam_NA_b };
        uint8_t v_svsCamFidMask_u8 = 0U;

        for (uint32_t v_camera_u32 = 0U; v_camera_u32 < NUM_CAMERAS; v_camera_u32++)
        {
            v_svsCamFidMask_u8 = v_svsCamFidMask_u8 | (v_svsCamFidSts_u8[v_camera_u32] << v_camera_u32);
            uint8_t     v_labelEnable_u8 = (((v_cameraFailure_u8 | v_svsCamFidMask_u8) & (1 << v_camera_u32)) != 0U);
            if (v_labelEnable_u8 != v_enable_pu8[v_camera_u32])
            {
                v_enable_pu8[v_camera_u32] = v_labelEnable_u8;
                v_update_b = true;
                cfg_t.cc.enable = !v_labelEnable_u8;
                //printf("\n SV:  v_svsCamFidSts_u8[%d]:%d camFu8:%X fidmask:%X v_enable_pu8[%d]:%d\n ",v_camera_u32, v_svsCamFidSts_u8[v_camera_u32],v_cameraFailure_u8,v_svsCamFidMask_u8,v_camera_u32,v_labelEnable_u8);
            }
        }

        if (v_update_b == true)
        {
            view_manager_update_ui(vm_po);
            view_manager_update_cc(vm_po);
        }

        // update latched copy
        cameraFailure_u8 = v_cameraFailure_u8 | v_svsCamFidMask_u8;
    }

    // process screen-request overlay bits
    if ( (FALSE)
        || (memcmp(&v_OverlayBits_s, &lastScreenRequest_t.MbSVS_bf_OverlayBitsReq ,sizeof(lastScreenRequest_t.MbSVS_bf_OverlayBitsReq)))
        || (memcmp(&v_ScreenRequest_t.AP_HMI_ParkSlot[0], &lastScreenRequest_t.AP_HMI_ParkSlot[0], sizeof(lastScreenRequest_t.AP_HMI_ParkSlot[0])))
        || (memcmp(&v_ScreenRequest_t.AP_HMI_ParkSlot[1], &lastScreenRequest_t.AP_HMI_ParkSlot[1], sizeof(lastScreenRequest_t.AP_HMI_ParkSlot[1])))
        || (memcmp(&v_ScreenRequest_t.AP_HMI_ParkSlot[2], &lastScreenRequest_t.AP_HMI_ParkSlot[2], sizeof(lastScreenRequest_t.AP_HMI_ParkSlot[2])))
        || (memcmp(&v_ScreenRequest_t.AP_HMI_ParkSlot[3], &lastScreenRequest_t.AP_HMI_ParkSlot[3], sizeof(lastScreenRequest_t.AP_HMI_ParkSlot[3])))
        || (memcmp(&v_ScreenRequest_t.AP_HMI_ParkSlot[4], &lastScreenRequest_t.AP_HMI_ParkSlot[4], sizeof(lastScreenRequest_t.AP_HMI_ParkSlot[4])))
        || (memcmp(&v_ScreenRequest_t.AP_HMI_ParkSlot[5], &lastScreenRequest_t.AP_HMI_ParkSlot[5], sizeof(lastScreenRequest_t.AP_HMI_ParkSlot[5])))
        || (v_ScreenRequest_t.AP_HMI_SelectedSlot != lastScreenRequest_t.AP_HMI_SelectedSlot)
        || (v_ScreenRequest_t.AP_HMI_Fullscreen != lastScreenRequest_t.AP_HMI_Fullscreen)
        || (v_ScreenRequest_t.AP_HMI_TopBlackBanner != lastScreenRequest_t.AP_HMI_TopBlackBanner)
        || (v_ScreenRequest_t.AP_HMI_TopRedBanner != lastScreenRequest_t.AP_HMI_TopRedBanner)
        || (v_ScreenRequest_t.AP_HMI_BottomBlackBanner != lastScreenRequest_t.AP_HMI_BottomBlackBanner)
        || (v_ScreenRequest_t.MeSVS_e_THAScreenRequesttoA72 != lastScreenRequest_t.MeSVS_e_THAScreenRequesttoA72)
        || (v_ScreenRequest_t.MeSVS_DesiredTrailerAngle != lastScreenRequest_t.MeSVS_DesiredTrailerAngle)
        || (v_ScreenRequest_t.MeSVS_ActualTrailerAngle != lastScreenRequest_t.MeSVS_ActualTrailerAngle)
        ||  (v_ScreenRequest_t.MeSVS_Orage_Arc_StartAngle != lastScreenRequest_t.MeSVS_Orage_Arc_StartAngle)
        ||  (v_ScreenRequest_t.MeSVS_Red_Arc_StartAngle != lastScreenRequest_t.MeSVS_Red_Arc_StartAngle)
        || (v_ScreenRequest_t.MeSVS_pct_ProgressBar != lastScreenRequest_t.MeSVS_pct_ProgressBar)
        || (v_ScreenRequest_t.MeSVS_px_CplrPosX != lastScreenRequest_t.MeSVS_px_CplrPosX)
        || (v_ScreenRequest_t.MeSVS_px_CplrPosY != lastScreenRequest_t.MeSVS_px_CplrPosY)
        || (v_ScreenRequest_t.MeSVS_px_ScrnTchX != lastScreenRequest_t.MeSVS_px_ScrnTchX)
        || (v_ScreenRequest_t.MeSVS_px_ScrnTchY != lastScreenRequest_t.MeSVS_px_ScrnTchY)
        || (v_thaHitchData_t.HitchCplrPixDiffLongY_s32 != lastThaHitchData_t.HitchCplrPixDiffLongY_s32)
        || (v_thaHitchData_t.HitchPix_p2d.x != lastThaHitchData_t.HitchPix_p2d.x)
        || (v_thaHitchData_t.HitchPix_p2d.y != lastThaHitchData_t.HitchPix_p2d.y)
        || (v_thaHitchData_t.HitchLoc_p3f.x != lastThaHitchData_t.HitchLoc_p3f.x)
        || (v_thaHitchData_t.HitchLoc_p3f.y != lastThaHitchData_t.HitchLoc_p3f.y)
        || (v_thaHitchData_t.HitchLoc_p3f.z != lastThaHitchData_t.HitchLoc_p3f.z)
        || (v_thaHitchData_t.HitchDetctStatus_e != lastThaHitchData_t.HitchDetctStatus_e)
        || (v_thaHitchData_t.CplrDetctStatus_e != lastThaHitchData_t.CplrDetctStatus_e)
        )
    {
        bool_t  v_updateView_b = false;
        bool_t  v_updateApState_b = false;
        bool_t  v_updateTrsc_b = false;
        bool_t  v_updateTHAState_b = false;
        bool_t  v_updateBottomBar_b = false;
        v_response_b = true;
#if 0
        // process view label overlay bits
        if (v_OverlayBits_s.ViewLabelOvlEn != lastScreenRequest_t.OverlayBits_s.ViewLabelOvlEn)
        {
            v_VehicleState_po->label_enable = v_OverlayBits_s.ViewLabelOvlEn;
            v_updateView_b = true;
        }

        if (v_OverlayBits_s.CamViewExitBtnOvlEn != lastScreenRequest_t.OverlayBits_s.CamViewExitBtnOvlEn)
        {
            v_VehicleState_po->exit_enable = v_OverlayBits_s.CamViewExitBtnOvlEn;
            v_updateView_b = true;
        }

        if (v_OverlayBits_s.CheckSurrLabelOvlEn != lastScreenRequest_t.OverlayBits_s.CheckSurrLabelOvlEn)
        {
            v_VehicleState_po->check_enable = v_OverlayBits_s.CheckSurrLabelOvlEn;
            v_updateView_b = true;
        }
#endif
        if (v_OverlayBits_s.XIcon_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.XIcon_b)
        {
            v_VehicleState_po->exit_enable = v_OverlayBits_s.XIcon_b;
            v_updateView_b = true;
        }

        uint32_t cur_zoom = convert_zoom_bits(&v_OverlayBits_s);
        uint32_t last_zoom = convert_zoom_bits(&lastScreenRequest_t.MbSVS_bf_OverlayBitsReq);

        if (cur_zoom != last_zoom)
        {
            v_VehicleState_po->zoom_icon = cur_zoom;
            v_updateView_b = true;
        }
  
        if( (FALSE) 
        ||(v_OverlayBits_s.TopRearButtonSelect_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.TopRearButtonSelect_b)
        ||(v_OverlayBits_s.TopRearButtonNoSelect_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.TopRearButtonNoSelect_b)
        )
        {
            if(v_OverlayBits_s.TopRearButtonNoSelect_b == v_OverlayBits_s.TopRearButtonSelect_b)
            {
                v_VehicleState_po->bottombutton_tvrv = 0;
            }
            else
            {
                v_VehicleState_po->bottombutton_tvrv = (TRUE == v_OverlayBits_s.TopRearButtonNoSelect_b) ? 1  :  2;
            }
            v_updateBottomBar_b = true; 
        }

        if( (FALSE) 
        ||(v_OverlayBits_s.RearCrossButtonSelect_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.RearCrossButtonSelect_b)
        ||(v_OverlayBits_s.RearCrossButtonNoSelect_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.RearCrossButtonNoSelect_b)
        )
        {
            if(v_OverlayBits_s.RearCrossButtonNoSelect_b == v_OverlayBits_s.RearCrossButtonSelect_b)
            {
                v_VehicleState_po->bottombutton_rcpv = 0;
            }
            else
            {
                v_VehicleState_po->bottombutton_rcpv = (TRUE == v_OverlayBits_s.RearCrossButtonNoSelect_b) ? 1  :  2;
            }
            v_updateBottomBar_b = true;
        }

        if( (FALSE) 
        ||(v_OverlayBits_s.FrontCrossButtonSelect_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.FrontCrossButtonSelect_b)
        ||(v_OverlayBits_s.FrontCrossButtonNoSelect_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.FrontCrossButtonNoSelect_b)
        )
        {
            if(v_OverlayBits_s.FrontCrossButtonNoSelect_b == v_OverlayBits_s.FrontCrossButtonSelect_b)
            {
                v_VehicleState_po->bottombutton_fcpv = 0;
            }
            else
            {
                v_VehicleState_po->bottombutton_fcpv = (TRUE == v_OverlayBits_s.FrontCrossButtonNoSelect_b) ? 1  :  2;
            }
            v_updateBottomBar_b = true;
        }

        if( (FALSE) 
        ||(v_OverlayBits_s.TopFrontButtonSelect_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.TopFrontButtonSelect_b)
        ||(v_OverlayBits_s.TopFrontButtonNoSelect_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.TopFrontButtonNoSelect_b)
        )
        {
            if(v_OverlayBits_s.TopFrontButtonNoSelect_b == v_OverlayBits_s.TopFrontButtonSelect_b)
            {
                v_VehicleState_po->bottombutton_tvfv = 0;
            }
            else
            {
                v_VehicleState_po->bottombutton_tvfv = (TRUE == v_OverlayBits_s.TopFrontButtonNoSelect_b) ? 1  :  2;
            }
            v_updateBottomBar_b = true;
        }

        if( (FALSE) 
        ||(v_OverlayBits_s.BackupRearCamButtonSelect_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.BackupRearCamButtonSelect_b)
        ||(v_OverlayBits_s.BackupRearCamButtonNoSelect_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.BackupRearCamButtonNoSelect_b)
        )
        {
            if(v_OverlayBits_s.BackupRearCamButtonNoSelect_b == v_OverlayBits_s.BackupRearCamButtonSelect_b)
            {
                v_VehicleState_po->bottombutton_burv = 0;
            }
            else
            {
                v_VehicleState_po->bottombutton_burv = (TRUE == v_OverlayBits_s.BackupRearCamButtonNoSelect_b) ? 1  :  2;
            }
            v_updateBottomBar_b = true;
        }

        if( (FALSE) 
        ||(v_OverlayBits_s.FrontFaceCamButtonSelect_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.FrontFaceCamButtonSelect_b)
        ||(v_OverlayBits_s.FrontFaceCamButtonNoSelect_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.FrontFaceCamButtonNoSelect_b)
        )
        {
            if(v_OverlayBits_s.FrontFaceCamButtonNoSelect_b == v_OverlayBits_s.FrontFaceCamButtonSelect_b)
            {
                v_VehicleState_po->bottombutton_ffcv = 0;
            }
            else
            {
                v_VehicleState_po->bottombutton_ffcv = (TRUE == v_OverlayBits_s.FrontFaceCamButtonNoSelect_b) ? 1  :  2;
            }
            v_updateBottomBar_b = true;
        }

        if( (FALSE) 
        ||(v_OverlayBits_s.AuxCamButton1Select_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.AuxCamButton1Select_b)
        ||(v_OverlayBits_s.AuxCamButton1NoSelect_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.AuxCamButton1NoSelect_b)
        )
        {
            if(v_OverlayBits_s.AuxCamButton1NoSelect_b == v_OverlayBits_s.AuxCamButton1Select_b)
            {
                v_VehicleState_po->bottombutton_aux = 0;
            }
            else
            {
                v_VehicleState_po->bottombutton_aux = (TRUE == v_OverlayBits_s.AuxCamButton1NoSelect_b) ? 1  :  2;
            }
            v_updateBottomBar_b = true;
        }

        if( (FALSE) 
        ||(v_OverlayBits_s.AuxCamButton2Select_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.AuxCamButton2Select_b)
        ||(v_OverlayBits_s.AuxCamButton2NoSelect_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.AuxCamButton2NoSelect_b)
        )
        {
            if(v_OverlayBits_s.AuxCamButton2NoSelect_b == v_OverlayBits_s.AuxCamButton2Select_b)
            {
                v_VehicleState_po->bottombutton_aux = 0;
            }
            else
            {
                v_VehicleState_po->bottombutton_aux = (TRUE == v_OverlayBits_s.AuxCamButton2NoSelect_b) ? 3  :  4;
            }
            v_updateBottomBar_b = true;
        }

        if( (FALSE) 
        ||(v_OverlayBits_s.MoreCamsButton1NoSelect_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.MoreCamsButton1NoSelect_b)
        ||(v_OverlayBits_s.MoreCamsButton1Select_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.MoreCamsButton1Select_b)
        ||(v_OverlayBits_s.MoreCamsButton2NoSelect_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.MoreCamsButton2NoSelect_b)
        ||(v_OverlayBits_s.MoreCamsButton2Select_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.MoreCamsButton2Select_b)
        ||(v_OverlayBits_s.MoreCamsIconFullScreenNoSelect_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.MoreCamsIconFullScreenNoSelect_b)
        )
        {
            if(TRUE == v_OverlayBits_s.MoreCamsButton1NoSelect_b)
            {
                v_VehicleState_po->more_icon = 1;
                v_VehicleState_po->more_icon_text = 2;
            }
            else if(TRUE == v_OverlayBits_s.MoreCamsButton1Select_b)
            {
                v_VehicleState_po->more_icon = 2;
                v_VehicleState_po->more_icon_text = 2;
            }
            else if(TRUE == v_OverlayBits_s.MoreCamsButton2NoSelect_b)
            {
                v_VehicleState_po->more_icon = 3;
                v_VehicleState_po->more_icon_text = 1;
            }
            else if(TRUE == v_OverlayBits_s.MoreCamsButton2Select_b)
            {
                v_VehicleState_po->more_icon = 4;
                v_VehicleState_po->more_icon_text = 1;
            }
            else if(TRUE == v_OverlayBits_s.MoreCamsIconFullScreenNoSelect_b)
            {
                v_VehicleState_po->more_icon = 5;
                v_VehicleState_po->more_icon_text = 2;
            }
            else
            {
                v_VehicleState_po->more_icon = 0;
                v_VehicleState_po->more_icon_text = 0;
            }
            v_updateBottomBar_b = true;
          
        }

        if(v_updateBottomBar_b)
        {
            view_manager_update_ui(vm_po);
        }

        if (v_OverlayBits_s.LeftDoorFrontOpen_Icon_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.LeftDoorFrontOpen_Icon_b)
        {
            v_VehicleState_po->door_state[0] = v_OverlayBits_s.LeftDoorFrontOpen_Icon_b;
            v_updateView_b = true;
        }

        if (v_OverlayBits_s.RightDoorFrontOpen_Icon_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.RightDoorFrontOpen_Icon_b)
        {
            v_VehicleState_po->door_state[1] = v_OverlayBits_s.RightDoorFrontOpen_Icon_b;
            v_updateView_b = true;
        }

        if (v_OverlayBits_s.LeftDoorRearOpen_Icon_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.LeftDoorRearOpen_Icon_b)
        {
            v_VehicleState_po->door_state[2] = v_OverlayBits_s.LeftDoorRearOpen_Icon_b;
            v_updateView_b = true;
        }

        if (v_OverlayBits_s.RightDoorRearOpen_Icon_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.RightDoorRearOpen_Icon_b)
        {
            v_VehicleState_po->door_state[3] = v_OverlayBits_s.RightDoorRearOpen_Icon_b;
            v_updateView_b = true;
        }

        if (v_OverlayBits_s.BackDoorOpen_Icon_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.BackDoorOpen_Icon_b)
        {
            v_VehicleState_po->door_state[4] = v_OverlayBits_s.BackDoorOpen_Icon_b;
            v_updateView_b = true;
        }
        
        if(v_OverlayBits_s.TopViewBlack_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.TopViewBlack_b) // If calib error FID set top view section will blackout
        {
            v_VehicleState_po->calib_error = v_OverlayBits_s.TopViewBlack_b;
            v_updateView_b = true;
            //printf("\n calib FID received \n");
        }
        if (v_updateView_b)
        {
            view_manager_update_overlays(vm_po);
        }

        // set door status (if not open then closed)
        // v_VehicleState_po->door_state[0] = v_OverlayBits_s.LeftDoorFrontOpen_Icon_b;
        // v_VehicleState_po->door_state[1] = v_OverlayBits_s.RightDoorFrontOpen_Icon_b;
        // v_VehicleState_po->door_state[2] = v_OverlayBits_s.LeftDoorRearOpen_Icon_b;
        // v_VehicleState_po->door_state[3] = v_OverlayBits_s.RightDoorRearOpen_Icon_b;
        // v_VehicleState_po->door_state[4] = v_OverlayBits_s.BackDoorOpen_Icon_b;

#if 0
        // set CTA status (set both front/rear CTA simultaneously for now)
        v_updateView_b = false;

        if (v_OverlayBits_s.RiCTA_OvlEn != lastScreenRequest_t.OverlayBits_s.RiCTA_OvlEn)
        {
            v_VehicleState_po->cta.target_rh = v_VehicleState_po->rcta.target_rh = v_OverlayBits_s.RiCTA_OvlEn;
            v_updateView_b = true;
        }

        if (v_OverlayBits_s.LeCTA_OvlEn != lastScreenRequest_t.OverlayBits_s.LeCTA_OvlEn)
        {
            v_VehicleState_po->cta.target_lh = v_VehicleState_po->rcta.target_lh = v_OverlayBits_s.LeCTA_OvlEn;
            v_updateView_b = true;
        }

        if (v_updateView_b)
        {
            view_manager_update_cta(vm_po);
        }
#endif

        // guidelines overlay control
        v_updateView_b = false;

        if (v_OverlayBits_s.FrontViewDynamics_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.FrontViewDynamics_b)
        {
            v_VehicleState_po->front_gl_enable = v_OverlayBits_s.FrontViewDynamics_b;
            v_updateView_b = true;
        }

        if (v_OverlayBits_s.RearViewDynamics_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.RearViewDynamics_b)
        {
            v_VehicleState_po->rear_gl_enable = v_OverlayBits_s.RearViewDynamics_b;
            v_updateView_b = true;
        }

        if (v_OverlayBits_s.FrontTireTracks_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.FrontTireTracks_b)
        {
            v_VehicleState_po->ffc_gl_enable = v_OverlayBits_s.FrontTireTracks_b;
            v_updateView_b = true;
        }

        if (v_updateView_b)
        {
            view_manager_update_guide(vm_po);
        }

        v_updateApState_b = false;

        uint8_t talbe_ap_inp[12] = {
            v_OverlayBits_s.PDC_FrontLeft_Red_b,
            v_OverlayBits_s.PDC_FrontCenter_Red_b,
            v_OverlayBits_s.PDC_FrontRight_Red_b,
            v_OverlayBits_s.PDC_RearLeft_Red_b,
            v_OverlayBits_s.PDC_RearCenter_Red_b,
            v_OverlayBits_s.PDC_RearRight_Red_b,
            v_OverlayBits_s.PDC_FrontLeft_Yellow_b,
            v_OverlayBits_s.PDC_FrontCenter_Yellow_b,
            v_OverlayBits_s.PDC_FrontRight_Yellow_b,
            v_OverlayBits_s.PDC_RearLeft_Yellow_b,
            v_OverlayBits_s.PDC_RearCenter_Yellow_b,
            v_OverlayBits_s.PDC_RearRight_Yellow_b,
        };

        uint8_t* talbe_ap_out[12] = {
            &v_VehicleState_po->ap.PDC_FrontLeft_Red_b,
            &v_VehicleState_po->ap.PDC_FrontCenter_Red_b,
            &v_VehicleState_po->ap.PDC_FrontRight_Red_b,
            &v_VehicleState_po->ap.PDC_RearLeft_Red_b,
            &v_VehicleState_po->ap.PDC_RearCenter_Red_b,
            &v_VehicleState_po->ap.PDC_RearRight_Red_b,
            &v_VehicleState_po->ap.PDC_FrontLeft_Yellow_b,
            &v_VehicleState_po->ap.PDC_FrontCenter_Yellow_b,
            &v_VehicleState_po->ap.PDC_FrontRight_Yellow_b,
            &v_VehicleState_po->ap.PDC_RearLeft_Yellow_b,
            &v_VehicleState_po->ap.PDC_RearCenter_Yellow_b,
            &v_VehicleState_po->ap.PDC_RearRight_Yellow_b,
        };

        for (int i = 0; i < 12; i++)
        {
            if (talbe_ap_inp[i] != *talbe_ap_out[i])
            {
                *talbe_ap_out[i] = talbe_ap_inp[i];
                v_updateApState_b = true;
            }
        }

        if (v_updateApState_b)
        {
            // ME_Debugger_F_Printf_v("\
            // FrLeft_R_b %d \n \
            // FrCenter_R_b %d \n \
            // FrRight_R_b %d \n \
            // ReLeft_R_b %d \n \
            // ReCenter_R_b %d \n \
            // ReRight_R_b %d \n \
            // FrLeft_Y_b %d \n \
            // FrCenter_Y_b %d \n \
            // FrRight_Y_b %d \n \
            // ReLeft_Y_b %d \n \
            // ReCenter_Y_b %d \n \
            // ReRight_Y_b %d \n\n"
            // ,v_OverlayBits_s.PDC_FrontLeft_Red_b
            // ,v_OverlayBits_s.PDC_FrontCenter_Red_b
            // ,v_OverlayBits_s.PDC_FrontRight_Red_b
            // ,v_OverlayBits_s.PDC_RearLeft_Red_b
            // ,v_OverlayBits_s.PDC_RearCenter_Red_b
            // ,v_OverlayBits_s.PDC_RearRight_Red_b
            // ,v_OverlayBits_s.PDC_FrontLeft_Yellow_b
            // ,v_OverlayBits_s.PDC_FrontCenter_Yellow_b
            // ,v_OverlayBits_s.PDC_FrontRight_Yellow_b
            // ,v_OverlayBits_s.PDC_RearLeft_Yellow_b
            // ,v_OverlayBits_s.PDC_RearCenter_Yellow_b
            // ,v_OverlayBits_s.PDC_RearRight_Yellow_b
            // );
            view_manager_update_ap(vm_po);
        }

        uint8_t talbe_tha_inp[5] = {
            v_OverlayBits_s.THA_ProgressBar,
            v_OverlayBits_s.THA_StartButton,
            v_OverlayBits_s.THA_ConfirmButton,
            v_OverlayBits_s.THA_TriangleOverlay,
            v_OverlayBits_s.THA_CouplerBulletIcon
        };

        uint8_t* talbe_tha_out[5] = {
            &v_VehicleState_po->tha_progress_enable,
            &v_VehicleState_po->tha_start_enable,
            &v_VehicleState_po->tha_confirm_enable,
            &v_VehicleState_po->tha_gl_enable,
            &v_VehicleState_po->tha_coupler_enable
        };

        uint8_t tha_button;

        if (v_OverlayBits_s.THA_ButtonSelectable != 0)
        {
            tha_button = 1;
        }
        else if (v_OverlayBits_s.THA_ButtonGrey != 0)
        {
            tha_button = 2;
        }
        else
        {
            tha_button = 0;
        }

        if (tha_button != v_VehicleState_po->tha_button)
        {
            v_VehicleState_po->tha_button = tha_button;
            v_updateTHAState_b = true;
        }

        for (int i = 0; i < (sizeof(talbe_tha_inp) / sizeof(talbe_tha_inp[0])); i++)
        {
            if (talbe_tha_inp[i] != *talbe_tha_out[i])
            {
                *talbe_tha_out[i] = talbe_tha_inp[i];
                v_updateTHAState_b = true;
            }
        }

        if (v_ScreenRequest_t.MeSVS_px_CplrPosX != lastScreenRequest_t.MeSVS_px_CplrPosX)
        {
            v_VehicleState_po->tha_coupler_pos[0] = v_ScreenRequest_t.MeSVS_px_CplrPosX;
            v_updateTHAState_b = true;
        }

        if (v_ScreenRequest_t.MeSVS_px_CplrPosY != lastScreenRequest_t.MeSVS_px_CplrPosY)
        {
            v_VehicleState_po->tha_coupler_pos[1] = v_ScreenRequest_t.MeSVS_px_CplrPosY;
            v_updateTHAState_b = true;
        }

        if((v_thaHitchData_t.HitchCplrPixDiffLongY_s32 != lastThaHitchData_t.HitchCplrPixDiffLongY_s32)
        || (v_ScreenRequest_t.MeSVS_e_THAScreenRequesttoA72 != lastScreenRequest_t.MeSVS_e_THAScreenRequesttoA72)
        || (v_thaHitchData_t.CplrDetctStatus_e != lastThaHitchData_t.CplrDetctStatus_e))
        {
            static int32_t tha_progress_acc = 0;
            static int32_t tha_prog_dist_mm = 1;
            static int32_t tha_minCouplerDist_mm = 1;
            if((THA_SM_Msg2 == v_ScreenRequest_t.MeSVS_e_THAScreenRequesttoA72) 
            && ((THA_SM_Msg2 != lastScreenRequest_t.MeSVS_e_THAScreenRequesttoA72) || (tha_prog_dist_mm == 1))) {
                int32_t tha_target_prog = PIXEL_TO_DISTACE_GAUSSIAN(v_thaHitchData_t.HitchCplrPixDiffLongY_s32);
				tha_prog_dist_mm = (tha_target_prog > THA_DELTA_THRESHOLD2_MM) ? (tha_target_prog - THA_DELTA_THRESHOLD2_MM) : 1;
                tha_minCouplerDist_mm = tha_prog_dist_mm;
                //ME_Debugger_F_Printf_v("SV PRG Init distance <%d, %dmm>\n", v_thaHitchData_t.HitchCplrPixDiffLongY_s32, tha_prog_dist_mm);
            }

            // Filter input values only when progress bar is visible
            if((TRUE == v_OverlayBits_s.THA_ProgressBar) && (v_thaHitchData_t.HitchCplrPixDiffLongY_s32 > THA_DELTA_THRESHOLD2)) {
                tha_progress_acc = (int32_t) ((THA_PRG_FILTER_ALPHA * v_thaHitchData_t.HitchCplrPixDiffLongY_s32) + ((1.0f - THA_PRG_FILTER_ALPHA) * tha_progress_acc));    
            }
            else
            {
                tha_progress_acc = v_thaHitchData_t.HitchCplrPixDiffLongY_s32;
            }
            
            uint8_t tha_progress_bar = THA_PROGRESS_MIN;
            if((tha_prog_dist_mm == 1) || (THA_EOM_Msg1 == v_ScreenRequest_t.MeSVS_e_THAScreenRequesttoA72)
                || (v_thaHitchData_t.HitchCplrPixDiffLongY_s32 <= THA_DELTA_THRESHOLD2))
			{
                tha_progress_bar = THA_PROGRESS_MAX;
            }
            else
			{
                sint32_t couplerDist_mm = PIXEL_TO_DISTACE_GAUSSIAN(tha_progress_acc) - THA_DELTA_THRESHOLD2_MM;
                tha_minCouplerDist_mm = (couplerDist_mm < tha_minCouplerDist_mm) ? couplerDist_mm : tha_minCouplerDist_mm;
                tha_progress_bar = thaCalculateProgressBarPercentage(tha_prog_dist_mm, tha_minCouplerDist_mm);
            }
            
            if (v_VehicleState_po->tha_progress_bar != tha_progress_bar) {
                v_VehicleState_po->tha_progress_bar = tha_progress_bar;
                v_updateTHAState_b = true;
            }

            //sint32_t cp_mm = PIXEL_TO_DISTACE_GAUSSIAN(tha_progress_acc) - THA_DELTA_THRESHOLD2_MM;
            //ME_Debugger_F_Printf_v("SV PRG : alg <%d : %d, %d, %dmm> => prg <%d>\n", v_OverlayBits_s.THA_ProgressBar, v_thaHitchData_t.HitchCplrPixDiffLongY_s32, tha_progress_acc, cp_mm, tha_progress_bar);
        }

        if((v_thaHitchData_t.HitchPix_p2d.x != lastThaHitchData_t.HitchPix_p2d.x) 
        || (v_thaHitchData_t.HitchPix_p2d.y != lastThaHitchData_t.HitchPix_p2d.y)
        || (v_thaHitchData_t.HitchLoc_p3f.x != lastThaHitchData_t.HitchLoc_p3f.x)
        || (v_thaHitchData_t.HitchLoc_p3f.y != lastThaHitchData_t.HitchLoc_p3f.y)
        || (v_thaHitchData_t.HitchLoc_p3f.z != lastThaHitchData_t.HitchLoc_p3f.z)
        || (v_thaHitchData_t.HitchDetctStatus_e != lastThaHitchData_t.HitchDetctStatus_e))
        {
            hitch_xyz[0] = static_cast<int32_t>(v_thaHitchData_t.HitchLoc_p3f.x);
            hitch_xyz[1] = static_cast<int32_t>(v_thaHitchData_t.HitchLoc_p3f.y);
            hitch_xyz[2] = static_cast<int32_t>(v_thaHitchData_t.HitchLoc_p3f.z);
            ME_Debugger_F_Printf_v("SV HITCH : des <%d, %d, %d> => det <%d : %d, %d> => ", hitch_xyz[0], hitch_xyz[1], hitch_xyz[2], 
                v_thaHitchData_t.HitchDetctStatus_e, v_thaHitchData_t.HitchPix_p2d.x, v_thaHitchData_t.HitchPix_p2d.y);
            cfg_vehicle_t* vehicle_data = &cfg_t.vehicle;
            static bool hitchDetStatus = false;
            static float32_t rawX = 0;
            static float32_t rawY = 0;
            if(e_Hitch_Detected == v_thaHitchData_t.HitchDetctStatus_e) {
                hitchDetStatus |= true;
                // Convert the THA detected coordinate from 640x400 to raw coordinate 1920x1280
                // THA has internal 1H and 1V flip for algo view
                rawX = THA_ALGO_VIEW_WIDTH - v_thaHitchData_t.HitchPix_p2d.x;
                rawY = THA_ALGO_VIEW_HEIGHT - v_thaHitchData_t.HitchPix_p2d.y;
                // Normalize the values [0..1]
                rawX = rawX / THA_ALGO_VIEW_WIDTH;
                rawY = rawY / THA_ALGO_VIEW_HEIGHT;
            }

            if(true == hitchDetStatus) {
                // Convert the raw co-ord to world for given view
				float32_t result_xy[2] = {0,0};
                raw_2_world_v_rear(rawX, rawY, hitch_xyz[2], result_xy);
                hitch_xyz[0] = -((int32_t)result_xy[0] - vehicle_data->wheel_base);
                hitch_xyz[1] = (int32_t)result_xy[1];
                ME_Debugger_F_Printf_v("raw <%0.2f, %0.2f> => con <%d : %d, %d> => ", rawX, rawY, (int32_t)result_xy[0], hitch_xyz[0], hitch_xyz[1]);
            }
            // Update the hitch location to start the triangle overlay
            int32_t relHitch_x = hitch_xyz[0] - (vehicle_data->wheel_base + vehicle_data->rear_overhang);
			update_hitch_position_v(relHitch_x, hitch_xyz[1], hitch_xyz[2]);
            ME_Debugger_F_Printf_v("final <%d, %d, %d>\n", relHitch_x, hitch_xyz[1], hitch_xyz[2]);
            v_updateTHAState_b = true;
        }

        if ((v_ScreenRequest_t.MeSVS_e_THAScreenRequesttoA72 != lastScreenRequest_t.MeSVS_e_THAScreenRequesttoA72) 
            || (v_OverlayBits_s.THA_Updated_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.THA_Updated_b))
        {
            v_VehicleState_po->tha_message_id = v_ScreenRequest_t.MeSVS_e_THAScreenRequesttoA72;
            v_updateTHAState_b = true;
        }

        if (v_updateTHAState_b)
        {
            view_manager_update_guide(vm_po);
			view_manager_update_tha(vm_po);
			view_manager_update_ui(vm_po);
		}

        if (update_ap(&v_ScreenRequest_t, &v_OverlayBits_s, v_VehicleState_po))
        {
            view_manager_update_ui(vm_po);
        }
        
        if (v_ScreenRequest_t.MeSVS_px_ScrnTchX != lastScreenRequest_t.MeSVS_px_ScrnTchX
            || v_ScreenRequest_t.MeSVS_px_ScrnTchY != lastScreenRequest_t.MeSVS_px_ScrnTchY)
        {
        	IsTouchValid = view_manager_mouse_tha(vm_po, v_ScreenRequest_t.MeSVS_px_ScrnTchX, v_ScreenRequest_t.MeSVS_px_ScrnTchY);
        }

        if (v_ScreenRequest_t.MeSVS_px_CplrPosX != lastScreenRequest_t.MeSVS_px_CplrPosX
            || v_ScreenRequest_t.MeSVS_px_CplrPosY != lastScreenRequest_t.MeSVS_px_CplrPosY)
        {
            ME_Debugger_F_Printf_v("THA CPLR <%d, %d> =>", v_ScreenRequest_t.MeSVS_px_CplrPosX, v_ScreenRequest_t.MeSVS_px_CplrPosY);
        	float32_t raw_pos_camera[2] = {0.0f, 0.0f};
            if (view_manager_mouse_get_coord(vm_po, v_ScreenRequest_t.MeSVS_px_CplrPosX, v_ScreenRequest_t.MeSVS_px_CplrPosY, raw_pos_camera) == 0)
            {
                // Normalize the values [0..1]
                float rawX = raw_pos_camera[0] / CWidth;
                float rawY = raw_pos_camera[1] / CHeight;
                float32_t world_xy[2] = {0,0};
                raw_2_world_v_rear(rawX, rawY, (int32_t)v_thaHitchData_t.HitchLoc_p3f.z, world_xy);
                cfg_vehicle_t* vehicle_data = &cfg_t.vehicle;
                world_xy[0] = -((int32_t)world_xy[0] - vehicle_data->wheel_base);
                bool isInside = isInsideTriangle_THA(world_xy[0], world_xy[1]);
                if(isInside) {
                    // The touch is inside triangle, send actual raw XY values.
                    THA_cplr_raw_pos[0] = raw_pos_camera[0];
                    THA_cplr_raw_pos[1] = raw_pos_camera[1];
                } else {
                    // The touch is not inside triangle, send 0 to abort.
                    THA_cplr_raw_pos[0] = 0;
                    THA_cplr_raw_pos[1] = 0;
                }
                ME_Debugger_F_Printf_v(" <%f, %f>", THA_cplr_raw_pos[0], THA_cplr_raw_pos[1]);
            }
            ME_Debugger_F_Printf_v("\n");
        }
        
        v_updateTrsc_b = false;

        // if (v_OverlayBits_s.TRSC_JackKnifeRed != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.TRSC_JackKnifeRed)
        // {
        //     v_VehicleState_po->trsc_red_enable = v_OverlayBits_s.TRSC_JackKnifeRed;
        //     v_updateTrsc_b = true;
        // }

        // if (v_OverlayBits_s.TRSC_JackKnifeOrange != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.TRSC_JackKnifeOrange)
        // {
        //     v_VehicleState_po->trsc_orange_enable = v_OverlayBits_s.TRSC_JackKnifeOrange;
        //     v_updateTrsc_b = true;
        // }

        if (v_OverlayBits_s.TRSC_Enable != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.TRSC_Enable)
        {
            v_VehicleState_po->trsc_enable = v_OverlayBits_s.TRSC_Enable;
            v_updateTrsc_b = true;
        }

        if (v_ScreenRequest_t.MeSVS_DesiredTrailerAngle != lastScreenRequest_t.MeSVS_DesiredTrailerAngle)
        {
            v_VehicleState_po->trsc_jk_angle_pct = v_ScreenRequest_t.MeSVS_DesiredTrailerAngle;
            v_updateTrsc_b = true;
        }

        if (v_ScreenRequest_t.MeSVS_ActualTrailerAngle != lastScreenRequest_t.MeSVS_ActualTrailerAngle)
        {
            v_VehicleState_po->trsc_tad_angle_pct = v_ScreenRequest_t.MeSVS_ActualTrailerAngle;
            v_updateTrsc_b = true;
        }

        if (v_ScreenRequest_t.MeSVS_Orage_Arc_StartAngle != lastScreenRequest_t.MeSVS_Orage_Arc_StartAngle)
        {
            v_VehicleState_po->trsc_angle0 = v_ScreenRequest_t.MeSVS_Orage_Arc_StartAngle;
            v_updateTrsc_b = true;
        }

        if (v_ScreenRequest_t.MeSVS_Red_Arc_StartAngle != lastScreenRequest_t.MeSVS_Red_Arc_StartAngle)
        {
            v_VehicleState_po->trsc_angle1 = v_ScreenRequest_t.MeSVS_Red_Arc_StartAngle;
            v_updateTrsc_b = true;
        }

        if (v_OverlayBits_s.TRSC_TrailerRed != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.TRSC_TrailerRed)
        {
            v_VehicleState_po->trsc_red_trailer = v_OverlayBits_s.TRSC_TrailerRed;
            v_updateTrsc_b = true;
        }

        if (v_updateTrsc_b)
        {
            // ME_Debugger_F_Printf_v("trsc_jk_angle_pct = %d, trsc_tad_angle_pct = %d, trsc_orange_enable = %d, trsc_red_enable = %d, trsc_enable = %d\n"
            // ,v_VehicleState_po->trsc_jk_angle_pct
            // ,v_VehicleState_po->trsc_tad_angle_pct
            // ,v_VehicleState_po->trsc_orange_enable
            // ,v_VehicleState_po->trsc_red_enable
            // ,v_VehicleState_po->trsc_enable);
            view_manager_update_trsc(vm_po);
        }

        uint8_t trg_auto;

        if (v_OverlayBits_s.Auto_Select_b != 0)
        {
            trg_auto = 1;
        }
        else if (v_OverlayBits_s.Auto_NoSelect_b != 0)
        {
            trg_auto = 2;
        }
        else
        {
            trg_auto = 0;
        }

        if (trg_auto != v_VehicleState_po->trg_auto)
        {
            v_VehicleState_po->trg_auto = trg_auto;
            v_updateView_b = true;
        }

        
        if (v_updateView_b)
        {
            view_manager_update_overlays(vm_po);
        }

        if (updateServiceCalib_b(&v_OverlayBits_s, &v_VehicleState_po->aiming))
        {
            view_manager_update_aiming_error(vm_po);
        }
    }

    // update vehicle state
    if ( (FALSE)
    || (lastVehSpdWhlSpdData_t.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig != v_VehSpdWhlSpdData_t.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig)
    || (lastVehSpdWhlSpdData_t.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_LwsAngle != v_VehSpdWhlSpdData_t.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_LwsAngle)
    || (lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.EnableStaticGuidelines_b != v_OverlayBits_s.EnableStaticGuidelines_b)
    )
    {
        float32_t   v_vehSpeed_f = v_VehSpdWhlSpdData_t.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig;
        float32_t   v_steeringAngle_f = v_VehSpdWhlSpdData_t.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_LwsAngle;

        if((TRUE == v_VehSpdWhlSpdData_t.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.StaticGrid) || (TRUE == v_OverlayBits_s.EnableStaticGuidelines_b))
        {
            v_steeringAngle_f = 0.0f;
            //printf("\n SV static gld enable \n");
        }

        v_VehicleState_po->speed = v_vehSpeed_f;

        // force guidelines update if steering angle has changed
        if (v_steeringAngle_f != v_VehicleState_po->steering)
        {
            v_VehicleState_po->steering = v_steeringAngle_f;
            view_manager_update_guide(vm_po);
        }

        // latch last state
        lastVehSpdWhlSpdData_t.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig = v_VehSpdWhlSpdData_t.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig;
        lastVehSpdWhlSpdData_t.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_LwsAngle = v_VehSpdWhlSpdData_t.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_LwsAngle;
    }

    if((lastVehSpdWhlSpdData_t.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.LanguageSelection != v_VehSpdWhlSpdData_t.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.LanguageSelection) ||
        (v_OverlayBits_s.DefaultEngLang_b != lastScreenRequest_t.MbSVS_bf_OverlayBitsReq.DefaultEngLang_b))
    {
        int32_t value = 0;
       if(TRUE == v_OverlayBits_s.DefaultEngLang_b)
       {
            value = 0; // defualt english language based on FID status
            //printf("\n default language FID received \n");
       }
       else
       {
            switch (v_VehSpdWhlSpdData_t.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.LanguageSelection) 
            {
                case 0x00: //Italian
                    value = 6;
                    break;
                case 0x02: // English
                    value = 1; 
                    break;
                case 0x03: // Espanol
                    value = 2; 
                    break;
                case 0x04: // Francais
                    value = 5; 
                    break;
                case 0x05: // Portugese
                    value = 8; 
                    break;
                case 0x08: // Brazilian
                    value = 7; 
                    break;
                case 0x0A: // Mexican
                    value = 3; 
                    break;
                case 0x0B: // English_US
                    value = 0; 
                    break;
                case 0x0C: // Canadian
                    value = 4; 
                    break;
                case 0x11: // Arabic
                    value = 9; 
                    break;
                case 0x01: // German
                    value = 10; 
                    break;
                case 0x07: // Dutch
                    value = 11; 
                    break;
                case 0x06: // Polish
                    value = 12; 
                    break;
                case 0x0D: // Russian-Cyrillic
                    value = 13; 
                    break;
                case 0x09: // Turkish
                    value = 14; 
                    break;
                default: // English_US
                    value = 0; 
                    break;
            }
        }
        char buf[256];
        config_change_language_runtime((int32_t)value, buf);
        ME_Debugger_F_Printf_v("language: %s\n", buf);

        vm_ui_language_reload(vm_po, buf);
        view_manager_update_ap(vm_po);
        view_manager_update_ui(vm_po);
        
        lastVehSpdWhlSpdData_t.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.LanguageSelection = v_VehSpdWhlSpdData_t.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.LanguageSelection;
    }
#if 0
    // update PAS state
    if (memcmp(&lastPasState_o, &v_PasState_o, sizeof(v_PasState_o)))
    {
        pas_state_t*    v_PasState_po = &v_VehicleState_po->pas;

        // global PAS state
        v_PasState_po->state = v_PasState_o.state;

        ME_Debugger_F_Printf_v("PAS state: %u\n", v_PasState_o.state);

        // individual sonar fault state - reorder as it is stored in different order
        v_PasState_po->sonar_state[0] = v_PasState_o.sonar_state[1];
        v_PasState_po->sonar_state[1] = v_PasState_o.sonar_state[2];
        v_PasState_po->sonar_state[2] = v_PasState_o.sonar_state[0];
        v_PasState_po->sonar_state[3] = v_PasState_o.sonar_state[4];
        v_PasState_po->sonar_state[4] = v_PasState_o.sonar_state[3];
        v_PasState_po->sonar_state[5] = v_PasState_o.sonar_state[5];

        // area-information
        memcpy(&v_PasState_po->area_info, &v_PasState_o.area_info, sizeof(v_PasState_o.area_info));

        // force update of PAS overlays
        view_manager_update_pas(vm_po);

        // latch last PAS state reported
        lastPasState_o = v_PasState_o;
    }
#endif

#if TBD
    // update Object-Detection-Overlay
    if (ENABLE_ODO && memcmp(&lastOdoState_o, &v_OdoState_o, sizeof(v_OdoState_o)))
    {
        odo_state_t*    v_OdoState_po = &v_VehicleState_po->odo;

        // copy nearest-object position coordinates
        memcpy(&v_OdoState_po->near_x, v_OdoState_o.near_x, sizeof(v_OdoState_o.near_x));
        memcpy(&v_OdoState_po->near_y, v_OdoState_o.near_y, sizeof(v_OdoState_o.near_y));

        // copy detection reliability values
        memcpy(&v_OdoState_po->reli, v_OdoState_o.reli, sizeof(v_OdoState_o.reli));

        // force update of ODO overlay
        view_manager_update_odo(vm_po);

        // latch last received ODO state
        lastOdoState_o = v_OdoState_o;
    }
#endif

    // latch most recent screen request (view-id only maybe? - tbd)
    lastScreenRequest_t = v_ScreenRequest_t;
    lastThaHitchData_t = v_thaHitchData_t;
    return v_response_b;
}

uint8_t sv::thaCalculateProgressBarPercentage(int16_t targetDist_mm, sint32_t couplerDist_mm) 
{
    sint32_t progBarPerc = 0;
    if(targetDist_mm > 0) {
        progBarPerc = (((targetDist_mm - couplerDist_mm) * THA_PROGRESS_MAX) / targetDist_mm);
    }

    if (progBarPerc > THA_PROGRESS_MAX)
    {
      progBarPerc = THA_PROGRESS_MAX;
    }
    else if ((progBarPerc <= THA_PROGRESS_MIN))
    {
      progBarPerc = THA_PROGRESS_MIN;
    }
    else
    {
      /*Do Nothing*/
    }
    return (uint8_t)progBarPerc;
}

bool sv::isInsideTriangle_THA(float worldX, float worldY) {
    bool inArc3 = true;
    bool inTri1 = true;
    bool otArc1 = true;
    bool otArc2 = true;

    /*
     *             Arc3
     *        ___-------___
     *        \    Tri1   /
     *         \         /
     *          \       /
     *           )     (
     *            )   (
     *      Arc1   ) (   Arc2
     *              "
     *            Hitch
     * 
     * Radius Arc1/2 {r=7.5m}
     * Center Arc1/2 {x=, y=}
     * Radius Arc3   {r=6m (yaml)}
     * Center Arc3   {x=hitchX, y=hitchY}
     * Bottom of Triangle {x=hitchX, y=hitchY}
     * Triangle bottom angle {a=60 (yaml)}
     */

    cfg_vehicle_t* vehicle_data = &cfg_t.vehicle;
    cfg_guide_tha_t* tha = &cfg_t.guide.tha;
    static uint32_t turnRadius = 7500;

    const uint32_t turnCenterY = sqrt(pow(turnRadius, 2) - pow(hitch_xyz[0]-vehicle_data->wheel_base, 2));
    ME_Debugger_F_Printf_v(" W<%d, %d> H<%d, %d, %d, %d, %d>", (int)vehicle_data->wheel_base, (int)worldX, (int)worldY, hitch_xyz[0], hitch_xyz[1], hitch_xyz[2], turnRadius);
    // Check if inside Arc3
    {
        int dist = sqrt(pow((worldX - hitch_xyz[0]), 2) + pow((worldY - hitch_xyz[1]), 2));
        inArc3 = (dist <= (tha->length + 2500));
        ME_Debugger_F_Printf_v(" A3=%d<%d>", inArc3, dist);
    }

    // Check if inside Traingle1
    {
        float angle = atan2(worldY - hitch_xyz[1], worldX - hitch_xyz[0]);
        float32_t v_det_angle = cfg_t.guide.tha.det_angle;
        angle = angle * 180.0 / M_PI;
        float stAngle = (-v_det_angle/2) ;
        float edAngle = (+v_det_angle/2) ;
        inTri1 = (angle >= stAngle) && (angle <= edAngle);
        ME_Debugger_F_Printf_v(" Angle T1 deg=%d<%.2f>", inTri1, angle);
    }
#if 1 /* Disabled until new arc design */
    // Check if outside Arc1
    {
        int x1 = pow((worldX - vehicle_data->wheel_base), 2);
        ME_Debugger_F_Printf_v("x =%d\n", x1);

        int y1 = pow((worldY - -((float32_t)turnCenterY)), 2);
        ME_Debugger_F_Printf_v("y =%d\n", y1);

        int dist1 = sqrt(x1 + y1);

        otArc1 = (dist1 > turnRadius);
        ME_Debugger_F_Printf_v(" A1=%d<%d>", otArc1, dist1);
    }
    
    // Check if outside Arc2
    {
        int x2 = pow((worldX - vehicle_data->wheel_base), 2);
        ME_Debugger_F_Printf_v("x =%d\n", x2);

        int y2 = pow((worldY - ((float32_t)turnCenterY)), 2);
        ME_Debugger_F_Printf_v("y =%d\n", y2);

        int dist2 = sqrt(x2 + y2);

        otArc2 = (dist2 > turnRadius);
        ME_Debugger_F_Printf_v(" A2=%d<%d> CY<%d>", otArc2, dist2, turnCenterY);
    }
#endif
    return inArc3 && inTri1 && otArc1 && otArc2;
}

/// @brief  Cleanup function (stub, never called)
void sv::clear_v()
{
    if (use_png)
    {
        png_loader_destroy(png_po);
    }
}

/// @brief  Deinitialization function (stub, never called)
void sv::deinit_v()
{
    if (inited_b)
    {
        clear_v();
        inited_b = false;
    }
}

/*KuSa - Start*/
void sv::updateSteeringCoeff()
{
    uint8_t variantId;
    variants::ME_VariantHelper_GetVariantID_b(&variantId); //get variant ID

    if ((variants::e_VariantId5 == variantId) || (variants::e_VariantId4 == variantId) || (variants::e_VariantId19 == variantId))
    {
        // overwrite steering coeeficients setting C = 55 CF
        cfg_t.vehicle.steering_coef[0] = 0;
        cfg_t.vehicle.steering_coef[1] = 0.0593083;
        cfg_t.vehicle.steering_coef[2] = 0;
    }
    else if ((variants::e_VariantId7 == variantId) || (variants::e_VariantId3 == variantId)|| (variants::e_VariantId9 == variantId) || (variants::e_VariantId10 == variantId) || (variants::e_VariantId11 == variantId) || (variants::e_VariantId18 == variantId))
    {
        // overwrite steering coeeficients setting C = 63 CF
        cfg_t.vehicle.steering_coef[0] = 0;
        cfg_t.vehicle.steering_coef[1] = 0.0670865;
        cfg_t.vehicle.steering_coef[2] = 0;
    }
    else 
    {
        // overwrite steering coeeficients setting C = 60 CF
        cfg_t.vehicle.steering_coef[0] = 0;
        cfg_t.vehicle.steering_coef[1] = 0.0640842;
        cfg_t.vehicle.steering_coef[2] = 0;
    }
    
    ME_Debugger_F_Printf_v("Steering coefficient updated to : %f  %f %f", cfg_t.vehicle.steering_coef[0], cfg_t.vehicle.steering_coef[1], cfg_t.vehicle.steering_coef[2] );

/*KuSa - end*/
}

} //namespace ovl3d
