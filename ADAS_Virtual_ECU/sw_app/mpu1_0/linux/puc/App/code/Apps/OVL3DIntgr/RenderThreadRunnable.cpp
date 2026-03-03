#include "RenderThreadRunnable.h"

#include <variants/VariantHelper.h>

#ifdef ME_PLATFORM_QNX
#include <EGL/egl.h>
#include <screen/screen.h>
#include <errno.h>
#include <assert.h>
#endif
#include <osal/io/File.h>


#include "IDataProviderOvl3D.h"
#ifdef ENABLE_RUNTIME_STATS
#define PROFILE_RenderThread     (1u)
#endif
#if PROFILE_RenderThread
#include "osal/system/Clock.h"
static uint32_t v_AvgRenderThreadRuntime_u32 = 0;
static uint32_t v_RenderThreadRunCntr_u32 = 0;
static uint32_t v_AvgRenderThreadPeriodicity_u32 = 0;
static uint32_t v_PreviousTime_u32 = 0;
static uint32_t v_RenderThreadRuntimeData = 0; //Runtime Data contains Execution Time and Periodicity, 31-16: Execution Time and 15-0: Periodicity
static PerformanceStatsEnable_t PerformanceStatsTHEnable_dp;

#endif
#define GPU_DRIVER_AVAILABLE

// PRQA S 3080 EOF // by design, EGL API
// PRQA S 4244 EOF // by design, EGL API
// PRQA S 3710 EOF // by design, SCREEN API
// PRQA S 3840 EOF // by design, SCREEN API
// PRQA S 3054 EOF // by design, SCREEN API, flag enum handling
// PRQA S 1051 EOF // documentation, no code
// PRQA S 4327 EOF // used maybe in future, keep that code
// PRQA S 4244 EOF // by design, STL iterators
// PRQA S 4211 EOF // by design
// PRQA S 3222 EOF // by design, no modifications
// PRQA S 3270 EOF // by design
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

namespace ovl3d
{

/// @brief	Class constructor
RenderThreadRunnable::RenderThreadRunnable(IDataProviderOvl3D& i_DataProvider_ro)
    : IRunnable()
    , dataProvider_ro(i_DataProvider_ro)
    , screen_o()
    , window_o()
    , isRunning_b(false)
    , data_s()
    , dataMutex_o()
    , isPlaying_b(true)
    , sv(&i_DataProvider_ro)
{
}

/// @brief  Class destructor
RenderThreadRunnable::~RenderThreadRunnable()
{
}

/// @brief  Render thread initialization
void RenderThreadRunnable::init_v()
{
	int ret;

#ifdef GPU_DRIVER_AVAILABLE
    // create screen context
    screen_o.createContext_b();

#ifdef ME_PLATFORM_QNX
    // create window with two output buffers
    window_o.setRenderBuffer_v(dataProvider_ro.getRenderBuffer_pv(0), dataProvider_ro.getRenderBuffer_pv(1), dataProvider_ro.getRenderBuffer_pv(2));
#endif

    uint32_t width_u32;
    uint32_t height_u32;
    dataProvider_ro.getResolutionInfo_v(width_u32, height_u32);
    // COGENT: this is the window you can render to. You can hook this up with you EGL implementation.
    window_o.create_b(screen_o.getContext_t(), bsp::e_WindowUsageOpenGles2, width_u32, height_u32, 0, 0, 3);
    isRunning_b = true;
#endif // GPU_DRIVER_AVAILABLE

}


/// @brief  Thread processing function
bool_t RenderThreadRunnable::run_b()
{
#if PROFILE_RenderThread
  PerformanceStatsTHEnable_dp = dataProvider_ro.get_PerformanceStatsEnable();
  static osal::Time start;
  volatile uint32_t v_Start_t = 0;
  volatile uint32_t v_End_t = 0;
  volatile uint32_t currPeriodicity = 0;
  if (TRUE ==  PerformanceStatsTHEnable_dp.RunTimeStatsEnable)
  {
    v_Start_t = __get_time_usec();
    currPeriodicity = v_Start_t - v_PreviousTime_u32;
  }
#endif
    bool_t  v_result_b = true;

    uint32_t width_u32;
    uint32_t height_u32;
    dataProvider_ro.getResolutionInfo_v(width_u32, height_u32);

#ifdef ME_PLATFORM_QNX
	static bool_t s_streamInit_b = true;

	// init streaming
	if (s_streamInit_b == true)
    {
		int ret;
        Pixmap_t pix[NUM_CAMERAS][NUM_CAM_BUFS] = {0};
#if 1		
#define ME_SCREEN_FLUSH \
		ret = screen_flush_context(screen_o.getContext_t(), 0); \
		if (ret != EOK) { \
			perror(" screen_flush_context() "); \
			system("pidin info"); \
        } 
#endif				
        ME_Debugger_F_Printf_v("Render-thread: query camera buffers...\n");

        for(uint32_t v_I_u32 = 0; v_I_u32 < NUM_CAMERAS; v_I_u32++)
        {
            bsp::VideoInputBufferDesc2_t    v_desc_t;

            dataProvider_ro.getVideoInputBuffer_pv(static_cast<variants::Camera_t>(v_I_u32), v_desc_t);

            sint32_t    v_bufsize_s32 = v_desc_t.bufsize_au32[0] + v_desc_t.bufsize_au32[1] + v_desc_t.bufsize_au32[2];

			for (uint32_t v_StreamIndex_u32 = 0; v_StreamIndex_u32 < bsp::c_MaxBuffer2_u32; ++ v_StreamIndex_u32)
            {
				Buffer_t created_buf;

                if (1) ME_Debugger_F_Printf_v("cam-%u: buf-#%u: %u*%u, bufsize: %u/%u/%u, stride: %u/%u/%u, offset: %u/%u/%u, format: %u, ptr: %p\n",
                                       v_I_u32, v_StreamIndex_u32, v_desc_t.size_au32[0], v_desc_t.size_au32[1],
                                       v_desc_t.bufsize_au32[0], v_desc_t.bufsize_au32[1], v_desc_t.bufsize_au32[2],
                                       v_desc_t.stride_au32[0], v_desc_t.stride_au32[1], v_desc_t.stride_au32[2],
                                       v_desc_t.offset_aau32[v_StreamIndex_u32][0], v_desc_t.offset_aau32[v_StreamIndex_u32][1], v_desc_t.offset_aau32[v_StreamIndex_u32][2],
                                       v_desc_t.format_u32, v_desc_t.buffers_apv[v_StreamIndex_u32]);

				ret = screen_create_buffer(&created_buf);
				Assert(ret == EOK);
				ME_SCREEN_FLUSH
				ret = screen_set_buffer_property_iv(created_buf, SCREEN_PROPERTY_SIZE, (const int*)&v_bufsize_s32);
				Assert(ret == EOK);
				ME_SCREEN_FLUSH
				ret = screen_set_buffer_property_iv(created_buf, SCREEN_PROPERTY_BUFFER_SIZE, (const int*)v_desc_t.size_au32);
				Assert(ret == EOK);
				ME_SCREEN_FLUSH 
				ret = screen_set_buffer_property_iv(created_buf, SCREEN_PROPERTY_FORMAT, (const int*)&v_desc_t.format_u32);
				Assert(ret == EOK);
				ME_SCREEN_FLUSH 
				ret = screen_set_buffer_property_iv(created_buf, SCREEN_PROPERTY_STRIDE, (const int*)&v_desc_t.stride_au32[0]);
				Assert(ret == EOK);
				ME_SCREEN_FLUSH
                sint32_t    val = 1;
				ret = screen_set_buffer_property_iv(created_buf, SCREEN_PROPERTY_PHYSICALLY_CONTIGUOUS, &val);
				Assert(ret == EOK);
				ME_SCREEN_FLUSH
				ret = screen_set_buffer_property_iv(created_buf, SCREEN_PROPERTY_PLANAR_OFFSETS, (const int*)v_desc_t.offset_aau32[v_StreamIndex_u32]);
				Assert(ret == EOK);
				ME_SCREEN_FLUSH 
				ret = screen_set_buffer_property_pv(created_buf, SCREEN_PROPERTY_POINTER, &v_desc_t.buffers_apv[v_StreamIndex_u32]);
				Assert(ret == EOK);
				ME_SCREEN_FLUSH 

				stream_o[v_I_u32].buffer_at[v_StreamIndex_u32] = created_buf;

				Pixmap_t screen_pix;
				// pixmap
				ret = screen_create_pixmap(&screen_pix, screen_o.getContext_t());
				Assert(ret == EOK);
				ME_SCREEN_FLUSH 
				sint32_t usage = SCREEN_USAGE_WRITE | SCREEN_USAGE_READ | SCREEN_USAGE_NATIVE | SCREEN_USAGE_OPENGL_ES3;
				ret = screen_set_pixmap_property_iv(screen_pix, SCREEN_PROPERTY_USAGE, &usage);
				Assert(ret == EOK);
				ME_SCREEN_FLUSH 
				ret = screen_set_pixmap_property_iv(screen_pix, SCREEN_PROPERTY_FORMAT, (const int*)&v_desc_t.format_u32);
				Assert(ret == EOK);
				ME_SCREEN_FLUSH 
				ret = screen_set_pixmap_property_iv(screen_pix, SCREEN_PROPERTY_BUFFER_SIZE, (const int*)v_desc_t.size_au32);
				Assert(ret == EOK);
				ME_SCREEN_FLUSH
				ret = screen_attach_pixmap_buffer(screen_pix, created_buf);
				if(ret != EOK)
					system("pidin info");
				Assert(ret == EOK);
				ME_SCREEN_FLUSH 
				stream_o[v_I_u32].pixmap_at[v_StreamIndex_u32] = screen_pix;
				pix[v_I_u32][v_StreamIndex_u32]=screen_pix;

            } // for (stream index)
        } // for cameras

        screen_flush_context(screen_o.getContext_t(), SCREEN_WAIT_IDLE);
        v_result_b = sv.init_b(&screen_o, &window_o, &pix[0][0], (NUM_CAM_BUFS*NUM_CAMERAS));
		Assert(v_result_b);
		
		// start video input
		dataProvider_ro.setIsPlaying_v(true);

        s_streamInit_b = false;
    }
#endif // ME_PLATFORM_QNX

    // Input frame number
    static uint32_t s_frameNum_u32;

    // Wait for an output frame availability
    uint32_t    v_inputBufIdx_u32, v_outputBufIdx_u32;

    if (dataProvider_ro.startRendering_b(v_inputBufIdx_u32, v_outputBufIdx_u32, s_frameNum_u32))
    {
        uint32_t    v_index_au32[NUM_CAMERAS];

        // all cameras are using same input buffer index
        for(uint32_t v_i_u32 = 0U; v_i_u32 < NUM_CAMERAS; v_i_u32++)
        {
            v_index_au32[v_i_u32] = v_inputBufIdx_u32;
        }

        // process camera buffers
        sv.update_v(v_inputBufIdx_u32, s_frameNum_u32, v_outputBufIdx_u32);

        static uint32_t count;

        if(++count == 10U)
        {
            static bool_t oneTime = true;

            if(!oneTime)
            {

                uint32_t    t0 = __get_time_usec();

                dump("/tmp/output1.dmp", dataProvider_ro.getRenderBuffer_pv(0), width_u32 * height_u32 * 4);

                uint32_t    t1 = __get_time_usec();

                dump("/tmp/output2.dmp", dataProvider_ro.getRenderBuffer_pv(1), width_u32 * height_u32 * 4);

                uint32_t    t2 = __get_time_usec();

                dump("/tmp/output3.dmp", dataProvider_ro.getRenderBuffer_pv(2), width_u32 * height_u32 * 4);

                uint32_t    t3 = __get_time_usec();

                ME_Debugger_F_Printf_v("output store time: %u,%u,%u (%u)\n", t1 - t0, t2 - t1, t3 - t2, t3 - t0);

                void   *buf = malloc(width_u32 * height_u32 * 4);

                t0 = __get_time_usec();

                memcpy(buf, dataProvider_ro.getRenderBuffer_pv(0), width_u32 * height_u32 * 4);

                t1 = __get_time_usec();

                dump("/tmp/output1.dmp", buf, width_u32 * height_u32 * 4);

                t2 = __get_time_usec();

                ME_Debugger_F_Printf_v("output-2: %u,%u (%u)\n", t1 - t0, t2 - t1, t2 - t0);

                for (uint32_t v_I_u32 = 0U; v_I_u32 < NUM_CAMERAS; v_I_u32++)
                {
                    bsp::VideoInputBufferDesc2_t    v_desc_t;
                    dataProvider_ro.getVideoInputBuffer_pv(static_cast<variants::Camera_t>(v_I_u32), v_desc_t);

                    char    v_buf_s8[64];
                    snprintf(v_buf_s8, sizeof(v_buf_s8), "/tmp/input%u.dmp", v_I_u32);
                    dump(v_buf_s8, v_desc_t.buffers_apv[v_inputBufIdx_u32], v_desc_t.bufsize_au32[0] + v_desc_t.bufsize_au32[1] + v_desc_t.bufsize_au32[2]);
                }

                oneTime = true;
            }
        }
        else if (0 && count == 300)
        {
            ME_Debugger_F_Printf_v("disable cameras...");
            dataProvider_ro.setIsPlaying_v(false);
            ME_Thread_Sleep_t(5000);
            ME_Debugger_F_Printf_v("enable cameras...");
            dataProvider_ro.setIsPlaying_v(true);
        }
    }
    else
    {
        ME_Debugger_F_Printf_v("startRendering Failed\n");
    }
#if PROFILE_RenderThread
  if (TRUE ==  PerformanceStatsTHEnable_dp.RunTimeStatsEnable)
  {
    v_End_t = __get_time_usec();
    //ME_Debugger_F_Printf_v("RenderThread: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
    v_RenderThreadRunCntr_u32++; //Increment the run counter for averaging purpose
    v_AvgRenderThreadPeriodicity_u32 = ((v_AvgRenderThreadPeriodicity_u32 * (v_RenderThreadRunCntr_u32 -1)) + currPeriodicity)/v_RenderThreadRunCntr_u32; //Average Periodicity
    v_AvgRenderThreadRuntime_u32 = ((v_AvgRenderThreadRuntime_u32 * (v_RenderThreadRunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_RenderThreadRunCntr_u32; //New Average  
    v_RenderThreadRuntimeData = (((v_AvgRenderThreadRuntime_u32/1000U)<<16U) | ((v_AvgRenderThreadPeriodicity_u32/1000U) & 0xFFFF));
    dataProvider_ro.setRenderThreadRuntime(v_RenderThreadRuntimeData);
    //ME_Debugger_F_Printf_v("RenderThread: E: %lld P: %lld \n", v_AvgRenderThreadRuntime_u32, v_AvgRenderThreadPeriodicity_u32);
    v_PreviousTime_u32 = v_Start_t;
  }
#endif
    return v_result_b;
}

void RenderThreadRunnable::cleanup_v()
{
}

void RenderThreadRunnable::stop_v()
{
}

} // namespace ovl3d
