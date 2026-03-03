#ifndef US_MGR_HEIGHT_RNN
#define US_MGR_HEIGHT_RNN
#include "US_MgrHeightAlgo.h"
#include "US_ComInputBuffer_Global.h"

#if (US_D_HEIGHT_ALGO_TYPE_TO_USE == HEIGHT_ALGO_RNN)
#include "US_Mgr_FrontNoiseRNN.h"
#include "US_Mgr_RearNoiseRNN.h"
#include "US_Mgr_FrontNormalRNN.h"
#include "US_Mgr_RearNormalRNN.h"
#include "US_MgrMath.h"
#include "US_SnrCfg_Global.h"

/*DNN Network */
#define REAR_HIDDEN_SIZE_GRU_NOISE   (6u)
#define REAR_INPUT_LAYER_SIZE_NOISE  (2u * REAR_HIDDEN_SIZE_GRU_NOISE)
#define REAR_COMBINED_SIZE_NOISE     (3U*REAR_HIDDEN_SIZE_GRU_NOISE)
#define REAR_HIDDEN_SIZE_GRU         (7u)
#define REAR_INPUT_LAYER_SIZE        (2U * REAR_HIDDEN_SIZE_GRU)
#define REAR_COMBINED_SIZE           (3U * REAR_HIDDEN_SIZE_GRU)
#define FRONT_HIDDEN_SIZE_GRU_NOISE  (6u)
#define FRONT_INPUT_LAYER_SIZE_NOISE (2u * FRONT_HIDDEN_SIZE_GRU_NOISE)
#define FRONT_COMBINED_SIZE_NOISE    (3U*FRONT_HIDDEN_SIZE_GRU_NOISE)
#define FRONT_HIDDEN_SIZE_GRU        (7u)
#define FORWARD_PASS_LAYER_SIZE      (32u)
#define FRONT_CONCAT_SIZE            (22u)
#define REAR_CONCAT_SIZE             (18u)
#define FRONT_INPUT_LAYER_SIZE       (2U * FRONT_HIDDEN_SIZE_GRU)
#define FRONT_COMBINED_SIZE          (3U * FRONT_HIDDEN_SIZE_GRU)
#define RELU_SLOPE                   (0.01f)
/*Unit Test*/
#define UNIT_TEST_FRONT_LIVE         (0u)
#define UNIT_TEST_REAR_LIVE          (0u)
/*DT VEHICLE VARIANTS*/
#define DNN_LARAMIE_VAR              (0U)
#define DNN_REBEL_VAR                (1U)
#define DNN_TUNGSTEN_VAR             (2U)
#define DNN_TRX_VAR                  (3U)
/*Post Processing settings*/
#define f_MIN_CLASS_PROB             (0.75f)
#define f_MIN_SUM_FILTER_AVG         (0.5f)
#define f_VEH_SPD_THRESHOLD          (3.5f)
#define WINDOW_FILTER_SIZE           (10U)
/*Height Classification Types*/
#define HEIGHT_ALGO_CURB_CLASS       (0u)
#define HEIGHT_ALGO_TUNNEL_CLASS     (1u)
#define HEIGHT_ALGO_POLE_CLASS       (2u)
#define HEIGHT_ALGO_VEHICLE_CLASS    (3u)
#define HEIGHT_ALGO_WALL_CLASS       (4u)
#define HEIGHT_ALGO_NUM_CLASSES      (5u)
/*Data Input Conditioning*/
#define HEIGHT_ALGO_NORMAL_EH_SCALE  (1.0f)
#define HEIGHT_ALGO_NOISE_EH_SCALE   (100.0f)
#define HEIGHT_ALGO_NUM_ECHOES       (3u)
#define DNN_OUTER_RIGHT_ENTRY        (0u)
#define DNN_OUTER_LEFT_ENTRY         (3u)
#define HEIGHT_ALGO_NUM_SENSORS      (4u)
#define US_D_TOF_TEMP_DEFAULT        (20.0f)
#define f_ReluSlope                  (0.01f)
#define u_WindowBufferSize           (10U)
#define u_SumBufferSize              (3U)


#if UNIT_TEST_FRONT_LIVE || UNIT_TEST_REAR_LIVE
#include <UART_stdio.h>
#include "unit_test\test_vehspd.h"
#include"unit_test\test_echo1Idx.h"
#include"unit_test\test_echo2Idx.h"
#include"unit_test\test_echo3Idx.h"
#include"unit_test\test_fHeight1.h"
#include"unit_test\test_fHeight2.h"
#include"unit_test\test_fHeight3.h"
#include"unit_test\test_numEchoes.h"
#include"unit_test\test_sDist1.h"
#include"unit_test\test_sDist2.h"
#include"unit_test\test_sDist3.h"
#include"unit_test\test_uConf1.h"
#include"unit_test\test_uWidth1.h"
#include"unit_test\test_uWidth2.h"
#include"unit_test\test_prndl.h"
#include"unit_test\test_AmbTemp.h"
static uint8_t globalcounter = 0;
static uint8_t vehspd_globalcounter = 0;
static uint8_t gearcounter = 0;
#endif

static uint8_t Get_VariantID(void);
static void Rear_Height_Algo_RNN(void);
static void Front_Height_Algo_RNN(void);
static void Reset_Front_RNN(void);
static void Reset_Rear_RNN(void);
static bool_t Front_height_estimation_RNN(const US_S_HeightAlgoInput_t sHeightInput[HEIGHT_ALGO_NUM_SENSORS],
                                          const float32_t f_VehSpdkph,
                                          const float32_t f_AmbTemp,
                                          const uint8_t u_veh_var);
static bool_t Front_height_estimation_RNN_noise( const US_S_HeightAlgoInput_t sHeightInput[HEIGHT_ALGO_NUM_SENSORS],
                                                 const float32_t f_VehSpdkph,
                                                 const float32_t f_AmbTemp,
                                                 const uint8_t   u_veh_var);

static bool_t Rear_height_estimation_RNN(const US_S_HeightAlgoInput_t sHeightInput[HEIGHT_ALGO_NUM_SENSORS], 
                                         const float32_t f_VehSpdkph,
                                         const float32_t f_AmbTemp);

static bool_t Rear_height_estimation_RNN_noise( const US_S_HeightAlgoInput_t sHeightInput[HEIGHT_ALGO_NUM_SENSORS],
                                                const float32_t f_VehSpdkph,
                                                const float32_t f_AmbTemp);

static void Height_Algo_RNN_Input_Raw(const US_S_SensorRec_t* const sOneSensorRec,
                                        const US_S_SignedDist_t* const sOneSensorRecDist,
                                        US_S_HeightAlgoInput_t* const sHeightInput,
                                        const uint8_t u_phys_group);

static bool_t Height_Output_Filter(const bool_t bIsHighFlag, const uint8_t u_phys_grp);

/* Global var */
static uint8_t u_HeightWindowFilterBuffer[TWO][WINDOW_FILTER_SIZE]={{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};
static uint8_t u_HeightFilterIdx[TWO]={0,0};
static float32_t f_rear_hidden_array[REAR_HIDDEN_SIZE_GRU]={0};
static float32_t f_rear_hidden_array_noise[REAR_HIDDEN_SIZE_GRU]={0};
static float32_t f_front_hidden_array[FRONT_HIDDEN_SIZE_GRU]={0};
static float32_t f_front_hidden_array_noise[FRONT_HIDDEN_SIZE_GRU]={0};
static bool_t b_prevNoiseRNNActive[TWO] = {ME_FALSE, ME_FALSE};
static uint8_t g_HeightClass[TWO];
static bool_t b_globHeightFlag[TWO] = {ME_FALSE, ME_FALSE};
static bool_t b_globHeightFlagFiltered[TWO] = {ME_FALSE, ME_FALSE};
static float32_t f_classProb[TWO][HEIGHT_ALGO_NUM_CLASSES];

#endif
#endif
