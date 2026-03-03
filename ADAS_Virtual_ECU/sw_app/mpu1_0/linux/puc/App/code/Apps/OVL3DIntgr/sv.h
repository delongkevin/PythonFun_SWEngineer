
#ifndef PUC_APP_CODE_APPS_OVL3DINTGR_SV_H_
#define PUC_APP_CODE_APPS_OVL3DINTGR_SV_H_

#include "sv/inc/sv_api.h"
#include <mutex>
#include <list>
#include <queue>

#include <bsp/graphics/Window.h>
#include <bsp/graphics/Screen.h>

#include "IDataProviderOvl3D.h"

#ifndef NUM_RENDER_BUFS
#define NUM_RENDER_BUFS 3U
#endif

#ifndef NUM_CAM_BUFS
#define NUM_CAM_BUFS 4U
#endif

#define NUM_CAMERAS 4U

namespace ovl3d
{

class IDataProviderOvl3D;


class sv {
public:
    /// @brief  Class constructor
    sv(IDataProviderOvl3D* i_DataProvider_ro);

    /// @brief  Class destructor
    virtual ~sv();

    /// @brief  Initialization function
    bool_t  init_b(bsp::Screen *screen, bsp::Window* window, Pixmap_t* _pixmaps, int cnt);

    /// @brief  Update SVS state and produce new frame
    void    update_v(uint32_t i_index_u32, uint32_t i_frameNum_u32, uint32_t i_video_buffer_inxd);

    /// @brief  Set-up tweak server interface
    void    tweak_on_connect_v();

    /// @brief  Deinitialization function (stub, never called)
    void    deinit_v();

    void raw_2_world_v_rear(float32_t raw_x, float32_t raw_y, int32_t refWorld_z, float32_t result_xy[2]);
    void update_hitch_position_v(int32_t world_x, int32_t world_y, int32_t world_z);

private:
    /// @brief  Pixmaps array (just for reference?)
    Pixmap_t                        pixmaps_aapo[NUM_CAMERAS][NUM_CAM_BUFS];

    /// @brief  PNG loader data
    png_data_t*                     png_po;

    /// @brief  Data provider handle
    IDataProviderOvl3D*             dataProvider_po;

    /// @brief   Last latched screen request
    ScreenRequest_t                 lastScreenRequest_t;
    //THARelated_ScreenReq_t          lastTHARequest_t;
    THA_HitchData_t                 lastThaHitchData_t;
    int32_t hitch_xyz[3];

    uint32_t dWidth_u32;
    uint32_t dHeight_u32;

#if TBD
    /// @brief   Last latched vehicle speed data
    VehSpdWhlSpdData_t              lastVehSpdWhlSpdData_t;
#endif
    ME_VehInp_to_IpcSignals_t       lastVehSpdWhlSpdData_t;

    /// @brief   Current camera parameters versions
    uint32_t                        cameraVersion_au32[NUM_CAMERAS];

    /// @brief   Camera failure mask
    uint8_t                         cameraFailure_u8;

    /// @brief  SVS configuration data
    cfg_data_t                      cfg_t;

    /// @brief  View manager handle
    view_manager_t*                 vm_po;

    /// @brief  Rendering context
    render_context_t                renderContext_t;

    /// @brief  Textures wrapping camera buffers
    texture_data_t*                 textures_aapo[NUM_CAM_BUFS][NUM_CAMERAS];

    /// @brief  Display handle (SVS internal)
    display_data_t*                 display_po;

    /// @brief  Window handle (SVS internal)
    window_data_t*                  window_po;

    /// @brief  Window info (SVS internal)
    window_info_t                   windowInfo_t;

    /// @brief  Last rendered textures
    texture_data_t*                 renderTextures_apo[NUM_CAMERAS];
    uint32_t                        latestIndex_u32;
    uint32_t                        latestOutBufferIndx_u32;

    /// @brief  SVS engine initialization completion flag
    bool                            inited_b;

private:
    /// @brief  Setup camera parameters
    void    setupCameraParams_v(sensor::CameraParams& i_meclCfg_ro, uint32_t i_camera_u32);

    /// @brief  Set configuration
    bool_t  setupConfig_b();

    /// @brief  Update camera parameters
    bool_t  updateCameras_b();

    /// @brief  Update view-manager state from shared memory
    bool_t  updateState_b();

    /// @brief  Clear window background
    void    drawBackground_v();

    /// @brief  Rendering function
    void    draw_v();

    /// @brief  Cleanup function (stub)
    void    clear_v();

    /// @brief  initiate the check of input/output buffer ids on MCU2_0 core (stub)
    void    run_check_ctlvals_v();


    /// @brief  get vehicle parameters from variant manager
    void getVehicleDesignValues_v(cfg_vehicle_t* vehicle);

    /// @brief  SVS context initialization callback
    static int context_init_cb(display_data_t *display, window_data_t *window, void *data);

    /// @brief  SVS frame drawing callback
    static void redraw_cb(display_data_t *display, void *data);

    /// @brief  SVS input processing callback
    static void input_cb(display_data_t *display, void *data, widget_event_t *event);

    /// @brief  AlgoView rendering thread
    static void* algoViewProcessingThread_pv(void *i_Args_pv);

    /// @brief  Calculate THA progress percentage 
    static uint8_t thaCalculateProgressBarPercentage(int16_t targetDist_mm, sint32_t couplerDist_mm);
    
    /// @brief  Check if world point is inside THA triangle
    bool isInsideTriangle_THA(float worldX, float worldY);

    /*KuSa*/
    void updateSteeringCoeff(void);
};

}

#endif /* PUC_APP_CODE_APPS_OVL3DINTGR_SV_H_ */
