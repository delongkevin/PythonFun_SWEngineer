/*=========================*/
/*     Linker Settings     */
/*=========================*/

--retain="*(.rstvectors)"
--retain="*(.bootCode)"
--retain="*(.startupCode)"
--retain="*(.startupData)"
--retain="*(.intvecs)"
--retain="*(.intc_text)"
--retain="*(.rstvectors)"
--retain="*(.safeRTOSrstvectors)"
--retain="*(.irqStack)"
--retain="*(.fiqStack)"
--retain="*(.abortStack)"
--retain="*(.undStack)"
--retain="*(.svcStack)"

--fill_value=0
--diag_suppress=10063                   /* entry point not _c_int00 */
--stack_size=0x8000
--heap_size=0x10000
--entry_point=_axSafeRTOSresetVectors     /* C RTS boot.asm with added SVC handler	*/

-stack  0x8000  /* SOFTWARE STACK SIZE */
-heap   0x10000 /* HEAP AREA SIZE      */

/*-------------------------------------------*/
/*       Stack Sizes for various modes       */
/*-------------------------------------------*/
__IRQ_STACK_SIZE   = 0x1000;
__FIQ_STACK_SIZE   = 0x1000;
__ABORT_STACK_SIZE = 0x1000;
__UND_STACK_SIZE   = 0x1000;
__SVC_STACK_SIZE   = 0x1000;

/*----------------------------------------------------------------------------*/
/* Section Configuration                                                      */

SECTIONS
{
    GROUP
    {
        .safeRTOSrstvectors                                 : {} palign(8)
        .rstvectors                                         : {} palign(8)
    } > R5F_TCMA_VECS
    GROUP
    {
        .bootCode                                               : {} palign( 8 )
        .startupCode                                            : {} palign( 8 )
        .pinit                                                  : {} align( 32 )
        .MPU_INIT_FUNCTION                                      : {} palign( 8 )
        .startupData                                            : {} palign( 8 ), type = NOINIT
    } > R5F_TCMA


    GROUP : palign(8) > R5F_TCMB0
    {

        .KERNEL_DATA LOAD_START( lnkKernelDataStartAddr ),
                    LOAD_END( lnkKernelDataEndAddr )           : {} palign( 0x800 )
    }

    GROUP : palign(8) > R5F_TCMB0
    {
		
        .fast_isp_code
        {

        isp_qnx_magna.lib<"awb-impl.obj">(.text.estimate_illuminant)
        isp_qnx_magna.lib<"isp-algo.obj">(.text.round_value)
        isp_qnx_magna.lib<"awb-impl.obj">(.text.awb_process)
        isp_qnx_magna.lib<isp_algo.obj>(.text.algorithm_pipeline)
        isp_qnx_magna.lib<magna_controls.obj>(.text.DBLC_CONTROL_run)
        isp_qnx_magna.lib<magna_controls.obj>(.text.SHARPNESS_run)
        isp_qnx_magna.lib<magna_controls.obj>(.text.SATURATION_run)
        isp_qnx_magna.lib<magna_controls.obj>(.text.SINTER_run)
        isp_qnx_magna.lib<magna_controls.obj>(.text.EV_CALC_run)
        isp_qnx_magna.lib<magna_controls.obj>(.text.ISPGAIN_CONTROL_run)
        isp_qnx_magna.lib<magna_controls.obj>(.text.HISTORY_ADAPTIVE_run)
        isp_qnx_magna.lib<magna_controls.obj>(.text.AGAIN_COMPENSATE_run)
        isp_qnx_magna.lib<magna_controls.obj>(.text.EMB_LINE_TRACE_run)
        isp_qnx_magna.lib<magna_controls.obj>(.text.PINK_SUN_COMPENSATE_run)
        isp_qnx_magna.lib<magna_controls.obj>(.text.PREHDRGAIN_CONTROL_run)
        isp_qnx_magna.lib<magna_controls.obj>(.text.AGAIN_CONTROL_run)
        isp_qnx_magna.lib<magna_controls.obj>(.text.AUTO_DUMP_run)
        isp_qnx_magna.lib<magna_controls.obj>(.text.MODES_run)
        isp_qnx_magna.lib<magna_controls.obj>(.text.CONTROLS_run)
        isp_qnx_magna.lib*<isp_algo.obj>(.text.find_table_by_id)
        isp_qnx_magna.lib*<isp_algo.obj>(.text.round_value)
        isp_qnx_magna.lib*<magna_controls.obj>(.text.LTM_CONTROL_run)

        isp_qnx_magna.lib*<magna_controls.obj>(.text.HISTORY_ADAPTIVE_defaults)
        isp_qnx_magna.lib*<magna_controls.obj>(.text.EMB_LINE_TRACE_defaults)
        isp_qnx_magna.lib*<magna_controls.obj>(.text.CONTROLS_defaults)
        isp_qnx_magna.lib*<magna_controls.obj>(.text.PREHDRGAIN_CONTROL_defaults)
        isp_qnx_magna.lib*<magna_controls.obj>(.text.AGAIN_CONTROL_defaults)
        isp_qnx_magna.lib*<magna_controls.obj>(.text.DBLC_CONTROL_defaults)
        isp_qnx_magna.lib*<magna_controls.obj>(.text.SHARPNESS_defaults)
        isp_qnx_magna.lib*<magna_controls.obj>(.text.MODES_defaults)
        isp_qnx_magna.lib*<magna_controls.obj>(.text.AUTO_DUMP_defaults)
        isp_qnx_magna.lib*<magna_controls.obj>(.text.SATURATION_defaults)
        }

    }
 
    .cinit                                                  : {} align( 32 ) > MCU2_0_DDR_DATA_SPACE

    
   asil_data:
   {
   }: {} palign(8) > MCU2_0_DDR_ASILB_DATA_SPACE

    __asilb_data__   : {} palign(8) > MCU2_0_DDR_ASILB_DATA_SPACE
    __asilb_bss__    : {} palign(8) > MCU2_0_DDR_ASILB_DATA_SPACE
    __asilb_code__   : {} palign(8) > MCU2_0_DDR_TEXT_RO_SPACE
    __asilb_const__  : {} palign(8) > MCU2_0_DDR_TEXT_RO_SPACE	



    /* Code sections. */
    GROUP LOAD_START( lnkFlashStartAddr ), LOAD_END( lnkFlashEndAddr )
    {
        .KERNEL_FUNCTION LOAD_START( lnkKernelFuncStartAddr ),
                         LOAD_END( lnkKernelFuncEndAddr )       : {} palign( 0x10000 )
        
        .text               : palign(8)
        .text.hwi           : palign(8)
        .text.cache         : palign(8)
        .text.mpu           : palign(8)
        .text.boot          : palign(8)
        .rodata             : palign(8)
    } > MCU2_0_DDR_TEXT_RO_SPACE
    

    .bss:l3mem              (NOLOAD) : {} > MAIN_OCRAM_MCU2_0
    .bss:ddr_local_mem      (NOLOAD) : {} > DDR_MCU2_0_LOCAL_HEAP
    .bss:app_log_mem        (NOLOAD) : {} > APP_LOG_MEM
    .bss:tiovx_obj_desc_mem (NOLOAD) : {} > TIOVX_OBJ_DESC_MEM
    .bss:ipc_vring_mem      (NOLOAD) : {} > IPC_VRING_MEM
    ipc_shared_Mem_buff (NOINIT) : {} palign(8) > IPC_SHARED_MEM_BUFF_SPACE

    
    GROUP : palign(8) > MAIN_MSRAM1_MCU2_0
    {
        .fast_code
        {

        isp_qnx_magna.lib<isp_autoexposure.obj>(.text.AE_run)
        isp_qnx_magna.lib<isp_awb_wrapper.obj>(.text.AWB_run)
        isp_qnx_magna.lib<profiler.obj>(.text.prof_start)
        isp_qnx_magna.lib<profiler.obj>(.text.prof_end)
        isp_qnx_magna.lib<parameters_storage.obj>(.text.get_param)
        isp_qnx_magna.lib<magna_controls.obj>(.text.TEMPERATURE_run)
        isp_qnx_magna.lib<parameters_storage.obj>(.text.set_param)
        isp_qnx_magna.lib<magna_controls.obj>(.text.TPG_run)
        isp_qnx_magna.lib<isp_process.obj>(.text.isp_algorithms)
        isp_qnx_magna.lib<parameters_storage.obj>(.text.get_buffer_parameter)
        isp_qnx_magna.lib<isp_algo.obj>(.text.get_table_value)
        isp_qnx_magna.lib<isp_algo.obj>(.text.ae_context_push_param)
        isp_qnx_magna.lib*<reg_write_233.obj>(.text.set_all_sensor_params)
        isp_qnx_magna.lib*<reg_write_ox3c.obj>(.text.set_all_sensor_params)
        isp_qnx_magna.lib*<cogent_api.obj>(.text.getInitialIspConfig)
        isp_qnx_magna.lib*<reg_write_233.obj>(.text.parse_regs_from_emb_line_ar233)
        isp_qnx_magna.lib*<isp_algo.obj>(.text.get_max_phase)
        isp_qnx_magna.lib*<cogent_api.obj>(.text.tweak_table_isp_create)
        isp_qnx_magna.lib*<def_cfg_233.obj>(.text.set_default_isp_233)
        isp_qnx_magna.lib*<isp_awb_wrapper.obj>(.text.AWB_defaults)
        isp_qnx_magna.lib*<cogent_api.obj>(.text.algorithm_controls_init)
        isp_qnx_magna.lib*<isp_autoexposure.obj>(.text.AE_defaults)
        isp_qnx_magna.lib*<parameters_storage.obj>(.text.get_param_address)
        isp_qnx_magna.lib*<cogent_api.obj>(.text.get_val_to_struct)
        isp_qnx_magna.lib*<parameters_storage.obj>(.text.push_buffer_parameters)
        isp_qnx_magna.lib*<config_reader_aux.obj>(.text.get_string_from_id)
		isp_qnx_magna.lib*<cogent_api.obj>(.text.getInitialSensorConfig)
        isp_qnx_magna.lib*<parameters_storage.obj>(.text.set_param_ui)
        isp_qnx_magna.lib*<magna_controls.obj>(.text.SINTER_defaults)
        isp_qnx_magna.lib*<magna_controls.obj>(.text.EV_CALC_defaults)
        isp_qnx_magna.lib*<magna_controls.obj>(.text.LTM_CONTROL_defaults)
        isp_qnx_magna.lib*<magna_controls.obj>(.text.CCM_INTERP_defaults)
        isp_qnx_magna.lib*<magna_controls.obj>(.text.AGAIN_COMPENSATE_defaults)
        isp_qnx_magna.lib*<magna_controls.obj>(.text.PINK_SUN_COMPENSATE_defaults)
        isp_qnx_magna.lib*<magna_controls.obj>(.text.TPG_defaults)
        isp_qnx_magna.lib*<magna_controls.obj>(.text.TEMPERATURE_defaults)
        isp_qnx_magna.lib*<magna_controls.obj>(.text.ISPGAIN_CONTROL_defaults)
        isp_qnx_magna.lib*<profiler.obj>(.text.print_prof)
        isp_qnx_magna.lib*<reg_write_233.obj>(.text.yuv_data_pack)
        isp_qnx_magna.lib*<config_dump.obj>(.text.drvISP_tivxVpaccogent_hydra3_ispConfig_dump)
        isp_qnx_magna.lib*<isp_aux.obj>(.text.get_saturation_matrix)
        isp_qnx_magna.lib*<parameters_storage.obj>(.text.get_parameters_storage)
        isp_qnx_magna.lib*<config_reader_aux.obj>(.text.set_isp_val)
        isp_qnx_magna.lib*<magna_controls.obj>(.text.CCM_INTERP_run)
        isp_qnx_magna.lib*<reg_write_ox3c.obj>(.text.parse_regs_from_emb_line_ox3c)
        isp_qnx_magna.lib*<reg_write_ox3c.obj>(.text.calc_snr_ox3c)
        isp_qnx_magna.lib*<cogent_api.obj>(.text.processFrame)
        isp_qnx_magna.lib*<cogent_api.obj>(.text.apply_new_settings)
		isp_qnx_magna.lib*<cogent_api.obj>(.text.get_global_isp_tables)

        vx_target_kernels_vpac_cuc_isp.lib<def_cfg_233.obj>(.text.set_default_isp_config_233)
        vx_target_kernels_vpac_cuc_isp.lib<def_cfg_233.obj>(.text.set_default_mergeCfg)
        vx_target_kernels_vpac_cuc_isp.lib<def_cfg_233.obj>(.text.set_default_pwl_lut_cfg)
        vx_target_kernels_vpac_cuc_isp.lib<def_cfg_233.obj>(.text.set_default_rfe_pwl_zero)
        vx_target_kernels_vpac_cuc_isp.lib*<processing.obj>(.text.send_all_sensor_params)
        vx_target_kernels_vpac_cuc_isp.lib*<vx_vpac_cuc_rc_target.obj>(.text.tivxVpacVissDeleteConfigBuffer)
        vx_target_kernels_vpac_cuc_isp.lib*<processing.obj>(.text.rc_init)

        vx_target_kernels_imaging_aewb.lib*<vx_aewb_target.obj>(.text.tivxAewbProcess)
        vx_target_kernels_imaging_aewb.lib*<vx_aewb_target.obj>(.text.tivxAewbCreate)

        ti_imaging_dcc.lib*<process_binary.obj>(.text.dcc_update)
        ti_imaging_dcc.lib*<process_binary.obj>(.text.process_binary_dcc)
        ti_imaging_dcc.lib*<dcc_ti.obj>(.text.Dcc_Create)

        vx_target_kernels_display_m2m.lib*<vx_display_m2m_target.obj>(.text.tivxDisplayM2MDelete)

        vx_target_kernels_vpac_viss.lib*<vx_vpac_viss_target.obj>(.text.tivxVpacVissCreate)
        vx_target_kernels_vpac_cuc_isp.lib*<vx_vpac_cuc_rc_target.obj>(.text.tivxVpacCucRcProcess)
        vx_target_kernels_vpac_cuc_isp.lib<processing.obj>(.text.rc_sensor_write)
        vx_target_kernels_vpac_cuc_isp.lib<vx_vpac_cuc_viss_target_driver.obj>(.text.tivxVpacCucVissSetConfigInDrv)
        vx_target_kernels_vpac_cuc_isp.lib<processing.obj>(.text.rc_process)
        vx_target_kernels_vpac_viss.lib<vx_vpac_viss_target.obj>(.text.tivxVpacVissUnmapUserDesc)
        vx_target_kernels_vpac_viss.lib*<vx_vpac_viss_target_drv.obj>(.text.tivxVpacVissSetConfigInDrv)
        vx_target_kernels_vpac_viss.lib*<vx_vpac_viss_target_drv.obj>(.text.tivxVpacVissSetConfigBuffer)
        vx_target_kernels_vpac_viss.lib*<vx_vpac_viss_target_dcc.obj>(.text.tivxVpacVissSetParamsFromDcc)
        vx_target_kernels_vpac_viss.lib*<vx_vpac_viss_target_dcc.obj>(.text.tivxVpacVissInitDcc)
        vx_target_kernels_vpac_viss.lib*<vx_vpac_viss_target_dcc.obj>(.text.tivxVpacVissSetH3aSrcParams)
        vx_target_kernels_vpac_viss.lib*<vx_vpac_viss_target_defaults.obj>(.text.tivxVpacVissSetDefaultParams)
        vx_target_kernels_vpac_viss.lib*<vx_vpac_viss_target.obj>(.text.tivxVpacVissMapStorageFormat)
        vx_target_kernels_vpac_viss.lib*<vx_vpac_viss_target.obj>(.text.tivxVpacVissMapUserDesc)
        vx_target_kernels_vpac_viss.lib*<vx_vpac_viss_target.obj>(.text.vhwaVissFreeCtxMem)
        vx_target_kernels_vpac_viss.lib*<vx_vpac_viss_target.obj>(.text.tivxVpacVissFreeObject)
        vx_target_kernels_vpac_viss.lib*<vx_vpac_viss_target_dcc.obj>(.text.tivxVpacVissDeInitDcc)
        vx_target_kernels_vpac_viss.lib*<vx_vpac_viss_target.obj>(.text.tivxVpacVissCheckInputDesc)

        vx_platform_psdk_j7_rtos.lib*<tivx_event.obj>(.text.tivxEventWait)
        vx_platform_psdk_j7_rtos.lib*<tivx_event.obj>(.text.tivxEventPost)
        vx_platform_psdk_j7_rtos.lib*<tivx_mem.obj>(.text.tivxMemShared2PhysPtr)
        vx_platform_psdk_j7_rtos.lib*<tivx_mem.obj>(.text.tivxMemBufferAlloc)
        vx_platform_psdk_j7_rtos.lib*<tivx_event.obj>(.text.tivxEventCreate)
        vx_platform_psdk_j7_rtos.lib*<tivx_mutex.obj>(.text.tivxMutexDelete)
        vx_platform_psdk_j7_rtos.lib*<tivx_event.obj>(.text.tivxEventDelete)
        vx_platform_psdk_j7_rtos.lib*<tivx_mutex.obj>(.text.tivxMutexCreate)
        vx_platform_psdk_j7_rtos.lib*<tivx_ipc.obj>(.text.tivxGetSelfCpuId)
        vx_platform_psdk_j7_rtos.lib*<tivx_mem.obj>(.text.tivxMemFree)
        vx_platform_psdk_j7_rtos.lib*<tivx_mem.obj>(.text.tivxMemAlloc)
        vx_platform_psdk_j7_rtos.lib*<tivx_mutex.obj>(.text.tivxMutexUnlock)
        vx_platform_psdk_j7_rtos.lib*<tivx_mutex.obj>(.text.tivxMutexLock)

        vx_target_kernels_vpac_cuc_isp.lib*<vx_vpac_cuc_viss_target.obj>(.text.tivxVpacCucVissProcess)

        app_utils_dss.lib*<app_dss_defaults.obj>(.text.appDssDefaultInit)

        dss.aer5f*<dss_dispPriv.oer5f>(.text.Dss_dispDrvPrivInit)
        ipc.aer5f*<ipc_osal.oer5f>(.text.Ipc_osalHIsrGateDelete)
        vx_framework.lib*<vx_node.obj>(.text.ownNodeSetParameter)

        ipc.aer5f*<ipc_osal.oer5f>(.text.Ipc_osalHIsrGateEnter)
        app_utils_udma.lib*<app_udma_utils.obj>(.text.appUdmaCopy1D)
        vx_platform_psdk_j7_rtos.lib*<tivx_platform.obj>(.text.tivxPlatformGetTimeInUsecs)
        ti.osal.aer5f*<SemaphoreP_SafeRTOS.oer5f>(.text.SemaphoreP_delete)
        ti.osal.aer5f*<SemaphoreP_SafeRTOS.oer5f>(.text.SemaphoreP_create)
        app_utils_mem.lib*<app_mem_free_rtos.obj>(.text.appMemGetDmaBufFd)
        ti_imaging_awbalg.lib*<TI_aaa_awb.obj>(.text.TI_AWB_do)
        ti.csl.aer5f*<csl_dssVideoPipe.oer5f>(.text.CSL_dssVidPipeSetConfig)
        ti_imaging_aealg.lib*<TI_aaa_ae.obj>(.text.TI_AE_init)

        ti.csl.aer5f*<csl_dssVideoPipe.oer5f>(.text.CSL_dssVidPipeSetFir2)
        ti.csl.aer5f*<csl_dssVideoPipe.oer5f>(.text.CSL_dssVidPipeGetRowIncYuvSp)
        ti.csl.aer5f*<csl_dssVideoPipe.oer5f>(.text.CSL_dssVidPipeSetCSCCoeff)
        ti.csl.aer5f*<csl_dssVideoPipe.oer5f>(.text.CSL_dssVidPipeGetScalerCoeff)
        ti.csl.aer5f*<csl_dssVideoPipe.oer5f>(.text.Fvid2_isDataFmtRgb)
        ti.csl.aer5f*<csl_dssVideoPipe.oer5f>(.text.Fvid2_isDataFmtRgb16bit)
        ti.csl.aer5f*<csl_dssWbPipe.oer5f>(.text.CSL_dssWbPipeSetConfig)


        ti_imaging_awbalg.lib*<TI_aaa_awb.obj>(.text.avg3)
        ti_imaging_awbalg.lib*<TI_aaa_awb.obj>(.text.wgt3)
        ti_imaging_awbalg.lib*<TI_aaa_awb.obj>(.text.sort_array)

        ti.osal.aer5f*<SemaphoreP_SafeRTOS.oer5f>(.text.SemaphoreP_Params_init)
        ti.osal.aer5f*<SemaphoreP_SafeRTOS.oer5f>(.text.SemaphoreP_constructCounting)
        ti.osal.aer5f*<SemaphoreP_SafeRTOS.oer5f>(.text.SemaphoreP_constructBinary)
        ti.osal.aer5f*<HwiP_safertos.oer5f>(.text.HwiP_restore)
        ti.osal.aer5f*<DebugP_nonos.oer5f>(.text.Osal_DebugP_assert_fcn)
        ti.osal.aer5f*<HwiP_safertos.oer5f>(.text.HwiP_disable)
        ti.osal.aer5f*<SemaphoreP_SafeRTOS.oer5f>(.text.SemaphoreP_post)
        ti.osal.aer5f*<SemaphoreP_SafeRTOS.oer5f>(.text.SemaphoreP_pend)


        app_utils_udma.lib*<app_udma_utils.obj>(.text.appUdmaCopy2D)
        app_utils_udma.lib*<app_udma_utils.obj>(.text.appUdmaTransfer)
        app_utils_udma.lib*<app_udma_utils.obj>(.text.appUdmaCacheInv)
        app_utils_udma.lib*<app_udma_utils.obj>(.text.appUdmaCacheWb)

        app_utils_dss.lib*<app_dss_defaults.obj>(.text.appDctrlDefaultInit)
        app_utils_dss.lib*<app_dctrl.obj>(.text.appDctrlInit)
        app_utils_dss.lib*<app_dss.obj>(.text.appDssInit)
        app_utils_dss.lib*<app_dss_soc.obj>(.text.appDssConfigureUB941AndUB925)
        app_utils_dss.lib*<app_dss_soc.obj>(.text.appDssConfigureBoard)
        app_utils_dss.lib*<app_dss_soc.obj>(.text.appDssConfigurePm)

        fvid2.aer5f*<fvid2_drvMgr.oer5f>(.text.Fvid2_getProcessedRequest)
        fvid2.aer5f*<fvid2_drvMgr.oer5f>(.text.Fvid2_processRequest)
        fvid2.aer5f*<fvid2_drvMgr.oer5f>(.text.Fvid2_control)
        fvid2.aer5f*<fvid2_drvMgr.oer5f>(.text.Fvid2_dequeue)
        fvid2.aer5f*<fvid2_drvMgr.oer5f>(.text.Fvid2_create)
        fvid2.aer5f*<fvid2_drvMgr.oer5f>(.text.Fvid2_delete)

        vx_platform_psdk_j7_rtos.lib*<tivx_mem.obj>(.text.tivxMemHost2SharedPtr)
        vx_platform_psdk_j7_rtos.lib*<tivx_mem.obj>(.text.tivxMemBufferFree)
        vx_platform_psdk_j7_rtos.lib*<tivx_mem.obj>(.text.tivxMemBufferUnmap)
        vx_platform_psdk_j7_rtos.lib*<tivx_mem.obj>(.text.tivxMemBufferMap)
        vx_platform_psdk_j7_rtos.lib*<tivx_mem.obj>(.text.tivxMemShared2TargetPtr)

        vx_target_kernels_vpac_viss.lib*<vx_vpac_viss_target_defaults.obj>(.text.tivxVpacVissDefaultMapMergeParams)
        vx_target_kernels_vpac_viss.lib*<vx_vpac_viss_target_defaults.obj>(.text.tivxVpacVissDefaultMapPwlParams)
        vx_target_kernels_vpac_viss.lib*<vx_vpac_viss_target_dcc.obj>(.text.tivxVpacVissDccMapBlc)
        vx_target_kernels_vpac_viss.lib*<vx_vpac_viss_target_dcc.obj>(.text.tivxVpacVissDccMapCCMParams)
        vx_target_kernels_vpac_viss.lib*<vx_vpac_viss_target_dcc.obj>(.text.tivxVpacVissDccMapYeeParams)
        vx_target_kernels_vpac_viss.lib*<vx_vpac_viss_target_dcc.obj>(.text.tivxVpacVissDccMapDpcParams)
        vx_target_kernels_vpac_viss.lib*<vx_vpac_viss_target_dcc.obj>(.text.tivxVpacVissDccMapNsf4Params)
        vx_target_kernels_vpac_viss.lib*<vx_vpac_viss_target_dcc.obj>(.text.tivxVpacVissDccMapRfeParams)
        vx_framework.lib*<vx_target_kernel_instance.obj>(.text.tivxGetTargetKernelInstanceContext)

        vx_target_kernels_imaging_aewb.lib*<vx_aewb_target.obj>(.text.getWbPrgFromSensor)
        vx_target_kernels_vpac_cuc_isp.lib*<def_cfg_ox3c.obj>(.text.set_default_isp_config_ox3c)
        vx_target_kernels_vpac_cuc_isp.lib*<common_sensor_api.obj>(.text.set_register_byte_array_via_iss)

        vx_framework.lib*<vx_debug.obj>(.text.tivx_print)
        vx_framework.lib*<vx_target.obj>(.text.ownTargetTaskMain)
        vx_framework.lib*<vx_target_kernel_instance.obj>(.text.tivxSetTargetKernelInstanceContext)


        ti_imaging_dcc.lib*<dcc_ti.obj>(.text.calc_dcc_outbuf_size)
        ti_imaging_dcc.lib*<parse_data.obj>(.text.find_parpack)
        ti_imaging_dcc.lib*<parse_data.obj>(.text.find_use_case_block)
        ti_imaging_dcc.lib*<parse_data.obj>(.text.parse_header_data)
        ti_imaging_dcc.lib*<process_binary.obj>(.text.update_driver_ptr)

        ti_imaging_awbalg.lib*<TI_aaa_awb.obj>(.text.TI_AWB_init)
        ti_imaging_awbalg.lib*<TI_aaa_awb.obj>(.text.TI_AWB_stab)
        ti_imaging_aealg.lib*<TI_aaa_ae.obj>(.text.TI_AE_do)

        app_utils_mem.lib*<app_mem_free_rtos.obj>(.text.appMemAlloc)
        app_utils_remote_service.lib*<app_remote_service.obj>(.text.appRemoteServiceRun)


        vhwa.aer5f*<vhwa_m2mVissApi.oer5f>(.text.vhwa_m2mVissProcessReq)
        vhwa.aer5f*<csl_nsf4.oer5f>(.text.CSL_nsf4vSetConfig)

        app_utils_ipc.lib*<app_ipc_rtos.obj>(.text.appIpcGetSelfCpuId)



        libc.a*<e_pow.c.obj>(.text.pow)
        libc.a*<e_sqrt.c.obj>(.text.sqrt)
        libc.a*<e_log10f.c.obj>(.text.log10f)
        libc.a*<s_scalbn.c.obj>(.text.scalbn)
        libc.a*<s_scalbnf.c.obj>(.text.scalbnf)


        dss.aer5f*<dss_evtMgr.oer5f>(.text.Dss_evtMgrMasterIsr)
        dss.aer5f*<dss_m2mDisp.oer5f>(.text.Dss_m2mDrvDispPipeCfgChk)

        ViewManager.lib*<aHmiM_STM_Functions.obj>(.text.aHmiM_STM_f_OnEntry_v)
        udma.aer5f*<udma_event.oer5f>(.text.Udma_eventIsrFxn)

        ti.csl.aer5f*<csl_intaggr.oer5f>(.text.CSL_intaggrClrIntr)
        ti.csl.aer5f*<csl_intaggr.oer5f>(.text.CSL_intaggrIsIntrPending)
        udma.aer5f*<udma_event.oer5f>(.text.Udma_assertLocal)
        ti.osal.aer5f*<TimerP_nonos.oer5f>(.text.TimerP_getTimeInUsecs)

        vhwa.aer5f*<csl_hts.oer5f>(.text.CSL_htsThreadStart)
        vhwa.aer5f*<csl_hts.oer5f>(.text.CSL_htsSetThreadConfig)
        vhwa.aer5f*<csl_lse.oer5f>(.text.CSL_lseSetConfig)
        vhwa.aer5f*<vhwa_m2mVissCsl.oer5f>(.text.Vhwa_memVissSetVissSizeAndPath)
        vhwa.aer5f*<vhwa_m2mVissApi.oer5f>(.text.vhwaVissCheckFrameList)


        fvid2.aer5f*<fvid2_utils.oer5f>(.text.Fvid2Utils_constructLinkList)
        fvid2.aer5f*<fvid2_drvMgr.oer5f>(.text.Fvid2_copyFrameList)
        fvid2.aer5f*<fvid2_utils.oer5f>(.text.Fvid2Utils_dequeue)
        fvid2.aer5f*<fvid2_drvMgr.oer5f>(.text.fdmFreeChannelObject)
        fvid2.aer5f*<fvid2_utils.oer5f>(.text.Fvid2Utils_memcpy)


        ipc.aer5f*<ipc_api.oer5f>(.text.RPMessage_recv)
        ipc.aer5f*<ipc_api.oer5f>(.text.RPMessage_send)
        ipc.aer5f*<ipc_mp.oer5f>(.text.Ipc_mpGetName)
        ipc.aer5f*<ipc_mp.oer5f>(.text.Ipc_mpGetSelfName)
        app_utils_ipc.lib*<app_ipc_rtos.obj>(.text.appIpcGetIpcCpuId)
        app_utils_ipc.lib*<app_ipc_rtos.obj>(.text.appIpcIsCpuEnabled)

        app_utils_remote_service.lib*<app_remote_service.obj>(.text.appRemoteServiceRunHandler)

        app_utils_mem.lib*<app_mem_free_rtos.obj>(.text.appMemCacheInv)
        app_utils_mem.lib*<app_mem_free_rtos.obj>(.text.appMemCacheWb)
        app_utils_mem.lib*<app_mem_free_rtos.obj>(.text.appMemCacheWbInv)


        ti_imaging_aealg.lib*<TI_aaa_ae.obj>(.text.search_in_range)

        vx_framework.lib*<vx_graph.obj>(.text.ownGraphClearState)
        vx_framework.lib*<vx_log_rt_trace.obj>(.text.ownLogRtTraceGraphExeStart)
        vx_framework.lib*<vx_log_rt_trace.obj>(.text.ownLogRtTraceNodeExeEnd)
        vx_framework.lib*<vx_log_rt_trace.obj>(.text.ownLogRtTraceTargetExeEnd)
        vx_framework.lib*<vx_reference.obj>(.text.ownReferenceLock)
        vx_framework.lib*<vx_reference.obj>(.text.ownReferenceUnlock)
        vx_framework.lib*<vx_target.obj>(.text.ownTargetSetDefaultCreateParams)
        vx_framework.lib*<vx_target.obj>(.text.ownTargetNodeSendCommand)
        vx_framework.lib*<vx_target_kernel.obj>(.text.ownTargetKernelDelete)
        vx_framework.lib*<vx_target_kernel_instance.obj>(.text.ownTargetKernelInstanceFree)
        vx_framework.lib*<vx_target_kernel.obj>(.text.ownTargetKernelCreate)
        vx_framework.lib*<vx_obj_desc.obj>(.text.tivx_obj_desc_memcpy)
        vx_framework.lib*<vx_target_kernel_instance.obj>(.text.ownTargetKernelInstanceGetIndex)
        vx_framework.lib*<vx_target_kernel_instance.obj>(.text.ownTargetKernelInstanceAlloc)
        vx_framework.lib*<vx_target.obj>(.text.ownTargetTriggerNode)
        vx_framework.lib*<vx_obj_desc.obj>(.text.ownObjDescSend)
        vx_framework.lib*<vx_target_acquire_parameters.obj>(.text.ownTargetNodeDescReleaseAllParameters)
        vx_framework.lib*<vx_graph.obj>(.text.ownSetGraphState)
        vx_framework.lib*<vx_graph.obj>(.text.ownSendGraphCompletedEvent)
        vx_framework.lib*<vx_node.obj>(.text.ownNodeCheckAndSendErrorEvent)
        vx_framework.lib*<vx_node.obj>(.text.ownNodeCheckAndSendCompletionEvent)
        vx_framework.lib*<vx_graph_pipeline.obj>(.text.ownCheckGraphCompleted)
        vx_framework.lib*<vx_node.obj>(.text.ownNodeGetNumOutNodes)
        vx_framework.lib*<vx_node.obj>(.text.ownNodeExecuteUserCallback)
        vx_framework.lib*<vx_target_acquire_parameters.obj>(.text.ownTargetNodeDescAcquireAllParameters)
        vx_framework.lib*<vx_target.obj>(.text.ownTargetNodeDescNodeExecuteTargetKernel)
        vx_framework.lib*<vx_target.obj>(.text.ownTargetNodeDescNodeExecuteUserKernel)
        vx_framework.lib*<vx_target_acquire_parameters.obj>(.text.ownTargetNodeDescAcquireAllParametersForPipeup)
        vx_framework.lib*<vx_data_ref_queue.obj>(.text.ownDataRefQueueSendRefConsumedEvent)
        vx_framework.lib*<vx_reference.obj>(.text.ownReferenceGetHandleFromObjDescId)
        vx_framework.lib*<vx_target_kernel_instance.obj>(.text.ownTargetKernelInstanceGet)
        vx_framework.lib*<vx_obj_desc.obj>(.text.ownObjDescIsValidType)
        vx_framework.lib*<vx_log_rt_trace.obj>(.text.ownLogRtTraceTargetExeStart)
        vx_framework.lib*<vx_obj_desc.obj>(.text.ownObjDescGet)

        vx_platform_psdk_j7_rtos.lib*<tivx_queue.obj>(.text.tivxQueueGet)
        vx_platform_psdk_j7_rtos.lib*<tivx_platform_rtos.obj>(.text.ownPlatformTaskInit)
        vx_platform_psdk_j7_rtos.lib*<tivx_platform.obj>(.text.ownPlatformPrintf)


        libc.a*<fputc.c.obj>(.text.putchar)

        vx_target_kernels_vpac_cuc_isp.lib*<common_sensor_api.obj>(.text.get_register_via_iss)

        vx_target_kernels_vpac_viss.lib*<vx_vpac_viss_target_dcc.obj>(.text.calc_dcc_gain_EV)

        diagnostics.obj*(.text.Diagnostics_Run)

        libclang_rt.builtins.a*<aeabi_div0.c.obj>(.text.__aeabi_ldiv0)

        vx_framework.lib*<vx_delay.obj>(.text.vxAgeDelay)

        ti.csl.aer5f*<csl_cache.oer5f>(.text.CSL_armR5CacheInv)
        ti.csl.aer5f*<csl_cache.oer5f>(.text.CSL_armR5CacheWb)

        ApplicationTasks.obj*(.text.*)
        BaseSwTasks.obj*(.text.*)

        app_utils_misc.lib*<app_utils_task_init.obj>(.text.appUtilsTaskInit)
        vx_framework.lib*<vx_target_kernel.obj>(.text.ownTargetKernelExecute)
        vx_framework.lib*<vx_target.obj>(.text.ownTargetSetTimestamp)
        vx_framework.lib*<vx_obj_desc_queue.obj>(.text.ownObjDescQueueAddBlockedNode)
        vx_framework.lib*<vx_node.obj>(.text.vxRetrieveNodeCallback)
        vx_framework.lib*<vx_graph_pipeline.obj>(.text.ownGraphEnqueueFreeObjDesc)
        vx_framework.lib*<vx_graph.obj>(.text.ownUpdateGraphPerf)
        vx_framework.lib*<vx_log_rt_trace.obj>(.text.ownLogRtTraceGraphExeEnd)
        vx_framework.lib*<vx_graph_pipeline.obj>(.text.ownGraphScheduleGraph)
        vx_framework.lib*<vx_node.obj>(.text.ownUpdateNodePerf)
        vx_framework.lib*<vx_event_queue.obj>(.text.ownEventQueueAddEvent)
        vx_platform_psdk_j7_rtos.lib*<tivx_platform_rtos.obj>(.text.ownPlatformSystemUnlock)
        vx_framework.lib*<vx_obj_desc_queue.obj>(.text.ownObjDescQueueDequeue)
        vx_framework.lib*<vx_obj_desc_queue.obj>(.text.ownObjDescQueueExtractBlockedNodes)
        vx_framework.lib*<vx_obj_desc_queue.obj>(.text.ownObjDescQueueEnqueue)
        vx_platform_psdk_j7_rtos.lib*<tivx_platform_rtos.obj>(.text.ownPlatformSystemLock)
        vx_platform_psdk_j7_rtos.lib*<tivx_ipc.obj>(.text.ownIpcSendMsg)
        vx_framework.lib*<vx_target.obj>(.text.ownTargetQueueObjDesc)
        vx_framework.lib*<vx_target.obj>(.text.ownTargetGetCpuId)
        vx_framework.lib*<vx_log_resource.obj>(.text.ownLogResourceAlloc)
        vx_framework.lib*<vx_target_kernel.obj>(.text.ownTargetKernelGet)
        vx_framework.lib*<vx_log_resource.obj>(.text.ownLogResourceFree)
        vx_framework.lib*<vx_target_kernel_instance.obj>(.text.tivxTargetKernelInstanceGetKernel)
        vx_framework.lib*<vx_target_kernel.obj>(.text.ownTargetKernelControl)
        vx_framework.lib*<vx_target.obj>(.text.strncpy)
        vx_framework.lib*<vx_log_rt_trace.obj>(.text.ownLogRtTraceLogEvent)
        vx_framework.lib*<vx_node.obj>(.text.ownNodeClearExecuteState)
        ti.osal.aer5f*<CacheP_nonos.oer5f>(.text.CacheP_wbInv)
        app_utils_remote_service.lib*<app_remote_service.obj>(.text.strcmp)
        ipc.aer5f*<ipc_virtio.oer5f>(.text.Virtio_kick)
        ipc.aer5f*<ipc_virtio.oer5f>(.text.Virtio_addUsedBuf)
        ipc.aer5f*<ipc_virtio.oer5f>(.text.Virtio_getAvailBuf)
        ipc.aer5f*<ipc_mp.oer5f>(.text.Ipc_mpGetSelfId)
        ipc.aer5f*<ipc_utils.oer5f>(.text.IpcUtils_HeapFree)
        ipc.aer5f*<ipc_utils.oer5f>(.text.IpcUtils_QgetHead)
        ipc.aer5f*<ipc_utils.oer5f>(.text.IpcUtils_QisEmpty)
        ipc.aer5f*<ipc_utils.oer5f>(.text.SystemP_printf)
        fvid2.aer5f*<fvid2_utils.oer5f>(.text.dutilsUnLinkDouble)
        vhwa.aer5f*<csl_ee.oer5f>(.text.CSL_eeStop)
        vhwa.aer5f*<csl_ee.oer5f>(.text.CSL_eeStart)
        vhwa.aer5f*<csl_h3a.oer5f>(.text.CSL_h3aStop)
        vhwa.aer5f*<csl_h3a.oer5f>(.text.CSL_h3aStart)
        vhwa.aer5f*<csl_nsf4.oer5f>(.text.CSL_nsf4vSetFrameConfig)
        vhwa.aer5f*<csl_visstop.oer5f>(.text.CSL_vissTopNsf4Enable)
        vhwa.aer5f*<csl_glbce.oer5f>(.text.CSL_glbceStart)
        vhwa.aer5f*<csl_glbce.oer5f>(.text.CSL_glbceSetConfig)
        vhwa.aer5f*<csl_visstop.oer5f>(.text.CSL_vissTopGlbceEnable)
        vhwa.aer5f*<csl_rawfe.oer5f>(.text.CSL_rfeSetFrameConfig)
        vhwa.aer5f*<csl_cac.oer5f>(.text.CSL_cacSetFrameConfig)
        vhwa.aer5f*<csl_visstop.oer5f>(.text.CSL_vissTopCacEnable)
        vhwa.aer5f*<csl_visstop.oer5f>(.text.CSL_vissTopMuxConfig)
        vhwa.aer5f*<csl_visstop.oer5f>(.text.CSL_vissTopFcp2InSelect)
        vhwa.aer5f*<csl_ee.oer5f>(.text.CSL_eeSetFrameConfig)
        vhwa.aer5f*<csl_visstop.oer5f>(.text.CSL_vissTopFcp2Enable)
        vhwa.aer5f*<csl_fcp.oer5f>(.text.CSL_fcpSetOutputMux)
        vhwa.aer5f*<csl_fcp.oer5f>(.text.CSL_fcpSetFrameConfig)
        vhwa.aer5f*<csl_lse.oer5f>(.text.LseCheckCfg)
        vhwa.aer5f*<csl_hts.oer5f>(.text.HtsSetSchConfig)
        vhwa.aer5f*<csl_hts.oer5f>(.text.HtsCheckConfig)
        vhwa.aer5f*<csl_hts.oer5f>(.text.HtsDmaSchConsStop)
        vhwa.aer5f*<csl_hts.oer5f>(.text.HtsSchProdStop)
        vhwa.aer5f*<csl_hts.oer5f>(.text.HtsDmaSchProdStop)
        ti.osal.aer5f*<Arch_util.oer5f>(.text.osalArch_TimeStampGetFreqKHz)
        ti.osal.aer5f*<Arch_util.oer5f>(.text.osalArch_TimestampGet64)
        udma.aer5f*<udma_utils.oer5f>(.text.Udma_printf)
        libclang_rt.builtins.a*<lshrdi3.S.obj>(.text.__aeabi_llsr)
        libclang_rt.builtins.a*<ashldi3.S.obj>(.text.__aeabi_llsl)
        signalmanager.lib*<SignalDef.obj>(.text.SigMgr_PpChmslCamSCCalib_TbSVS_S_ChmslCamSCCalibDataToNVM_t_Put)
        ViewManager.lib*<aHmiM_STM_Functions.obj>(.text.AP_HMI_ViewID_Decoding)
        signalmanager.lib*<SignalDef.obj>(.text.SigMgr_PpSVSToDiag_SVSToDiag_t_Put)
        cam_testpattern.obj*(.text.cam_testpattern)
        ViewManager.lib*<aHmiM_STM_Functions.obj>(.text.aHmiM_STM_f_EvaluateRVCNormalTrajectories_v)
        ViewManager.lib*<aHmiM_STM_Functions.obj>(.text.aHmiM_STM_f_EvaluateTopViewOverlayGroups_v)
        ViewManager.lib*<aHmiM_STM_Functions.obj>(.text.aHmiM_STM_f_EvaluateFrontTopTrajectories_v)
        ViewManager.lib*<aHmiM_STM_Functions.obj>(.text.aHmiM_STM_f_EvaluateRearTopTrajectories_v)
        ViewManager.lib*<aHmiM_STM_Functions.obj>(.text.aHmiM_STM_f_ZoomIcoHandlingSpeed_v)
        ViewManager.lib*<aHmiM_STM_Functions.obj>(.text.aHmiM_STM_f_EvaluateCHMSLTrajectories_v)
        ViewManager.lib*<aHmiM_STM_Functions.obj>(.text.aHmiM_STM_f_clear_chmsl_NVM_coordinates)
        signalmanager.lib*<SignalDef.obj>(.text.SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_Get)
        signalmanager.lib*<SignalDef.obj>(.text.SigMgr_Data_DiagToSVS_t_Get)
        ViewManager.lib*<aHmiM_STM_Functions.obj>(.text.aHmiM_STM_f_EvaluateFFCVTrajectories_v)
        signalmanager.lib*<SignalDef.obj>(.text.SigMgr_Data_HMIInfoToAP_t_Put)
        signalmanager.lib*<SignalDef.obj>(.text.SigMgr_Data_IHMIInfoToFPA_t_Put)
        ViewManager.lib*<aHmiM_STM_Functions.obj>(.text.aHmiM_STM_f_Entry_AutoPark_View_v)
        ViewManager.lib*<aHmiM_STM_Functions.obj>(.text.aHmiM_STM_f_CheckViewGuard_NotReverseGearEngaged_b)
        ViewManager.lib*<aHmiM_STM_Functions.obj>(.text.aHmiM_STM_f_XButtonHandlingDefault)
        ViewManager.lib*<aHmiM_STM_Functions.obj>(.text.aHmiM_STF_F_EvaluateJackKnifeOverlays_v)
        ViewManager.lib*<aHmiM_STM_Functions.obj>(.text.EvaluateBottomBarButtons)
        signalmanager.lib*<SignalDef.obj>(.text.SigMgr_PpSvsToVCAN_SvsToVCAN_t_Put)
        ViewManager.lib*<aHmiM_STM_Functions.obj>(.text.aHmiM_STM_f_Evaluate_HMIView_DisplayView_v)
        signalmanager.lib*<SignalDef.obj>(.text.SigMgr_PpScreenResponse_ScreenResponse_t_Get)
        ViewManager.lib*<aHmiM_STM_Functions.obj>(.text.memcmp)
        signalmanager.lib*<SignalDef.obj>(.text.SigMgr_PpScreenRequest_ScreenRequest_t_Put)
        signalmanager.lib*<SignalDef.obj>(.text.SigMgr_Data_CalDataProvider_MCU_2_0_Def_Get)
        fvid2.aer5f*<trace.oer5f>(.text.GT_assertLocal)
        vhwa.aer5f*<vhwa_m2mVissApi.oer5f>(.text.vhwaM2mVissSubmitRequest)
        app_utils_remote_service.lib*<app_remote_service.obj>(.text.strncpy)
        ti.osal.aer5f*<HeapP_freertos.oer5f>(.text.HeapP_alloc)
        vx_framework.lib*<vx_log_rt_trace.obj>(.text.ownLogRtTraceNodeExeStart)
        safety.obj*(.text.camera_set_for_reset)
        safety.obj*(.text.camera_report_error_status)
        isp_qnx_magna.lib*<crc32c.obj>(.text.crc_update)
        isp_qnx_magna.lib*<config_reader_aux.obj>(.text.set_val_to_struct)
        libclang_rt.builtins.a*<fixsfdi.S.obj>(.text.__aeabi_f2lz)
        isp_qnx_magna.lib*<reg_write_ox3c.obj>(.text.functions_init_ox3c)
        isp_qnx_magna.lib*<reg_write_233.obj>(.text.functions_init_ar233)
        vx_target_kernels_vpac_cuc_isp.lib*<def_cfg_ox3c.obj>(.text.set_default_mergeCfg)
        vx_target_kernels_vpac_cuc_isp.lib*<def_cfg_ox3c.obj>(.text.set_default_pwl_lut_cfg)
        vx_target_kernels_vpac_cuc_isp.lib*<def_cfg_ox3c.obj>(.text.set_default_rfe_pwl_zero)
        ti_imaging_dcc.lib*<parse_data.obj>(.text.dcc_search_NSF4)
        ti_imaging_dcc.lib*<parse_data.obj>(.text.dcc_search_DPC)
        ti_imaging_dcc.lib*<parse_data.obj>(.text.dcc_search_YEE)
        ti_imaging_dcc.lib*<parse_data.obj>(.text.dcc_interp_CCM)
        app_utils_mem.lib*<app_mem_free_rtos.obj>(.text.appMemCloseDmaBufFd)
        app_utils_mem.lib*<app_mem_free_rtos.obj>(.text.appMemGetVirt2PhyBufPtr)
        fvid2.aer5f*<trace.oer5f>(.text.GT_trace0)
        ti.osal.aer5f*<Utils_SafeRTOS.oer5f>(.text.Osal_DebugP_assert)
        sciclient.aer5f*<sciclient_pm.oer5f>(.text.Sciclient_pmSetModuleClkParent)
        sciclient.aer5f*<sciclient_pm.oer5f>(.text.Sciclient_pmModuleClkRequest)
        sciclient.aer5f*<sciclient_pm.oer5f>(.text.Sciclient_pmSetModuleClkFreq)
        sciclient.aer5f*<sciclient_pm.oer5f>(.text.Sciclient_pmSetModuleState)
        app_utils_dss.lib*<app_dss_soc.obj>(.text.appDssConfigureDP)
        dss.aer5f*<dss_init.oer5f>(.text.Dss_init)
        dss.aer5f*<dss_init.oer5f>(.text.Dss_initParamsInit)
        app_utils_remote_service.lib*<app_remote_service.obj>(.text.appRemoteServiceRegister)
        app_utils_dss.lib*<app_dss_defaults.obj>(.text.appDctrlPathInfoInit)
        ti.osal.aer5f*<CacheP_nonos.oer5f>(.text.CacheP_wb)
        udma.aer5f*<udma_soc.oer5f>(.text.Udma_isCacheCoherent)
        ti.osal.aer5f*<TaskP_SafeRTOS.oer5f>(.text.TaskP_yield)
        udma.aer5f*<udma_ring_common.oer5f>(.text.Udma_ringDequeueRaw)
        udma.aer5f*<udma_ch.oer5f>(.text.Udma_chGetCqRingHandle)
        udma.aer5f*<udma_ring_common.oer5f>(.text.Udma_ringQueueRaw)
        udma.aer5f*<udma_ch.oer5f>(.text.Udma_chGetFqRingHandle)
        app_utils_udma.lib*<app_udma_utils.obj>(.text.appUdmaCopy2DLocal)
        ti.kernel.safertos.aer5f*<queue.oer5f>(.text.xQueueReceiveFromISRKrnl)
        ti.kernel.safertos.aer5f*<apiWrapper.oer5f>(.text.xQueueSend)
        ti.kernel.safertos.aer5f*<queue.oer5f>(.text.xQueueSendFromISRKrnl)
        ti.kernel.safertos.aer5f*<portable.oer5f>(.text.vPortEnterCritical)
        ti.osal.aer5f*<Arch_util.oer5f>(.text.OsalArch_globalDisableInterrupt)
        ti.kernel.safertos.aer5f*<portable.oer5f>(.text.vPortExitCritical)
        ti.kernel.safertos.aer5f*<apiWrapper.oer5f>(.text.xTaskIsSchedulerStarted)
        ti.osal.aer5f*<Arch_util.oer5f>(.text.OsalArch_globalRestoreInterrupt)
        ti.kernel.safertos.aer5f*<apiWrapper.oer5f>(.text.xQueueReceive)
        ti.osal.aer5f*<Utils_SafeRTOS.oer5f>(.text.Osal_isInISRContext)
        ti.kernel.safertos.aer5f*<apiSemaphoreWrapper.oer5f>(.text.xSemaphoreCreateBinary)
        ti.kernel.safertos.aer5f*<apiSemaphoreWrapper.oer5f>(.text.xSemaphoreCreateCounting)
        ti.csl.aer5f*<csl_dssWbPipe.oer5f>(.text.CSL_dssWbPipeGetRowIncYuvSp)
        ti.csl.aer5f*<csl_dssWbPipe.oer5f>(.text.CSL_dssWbPipeSetFir2)
        ti.csl.aer5f*<csl_dssWbPipe.oer5f>(.text.CSL_dssWbPipeGetScalerCoeff)
        ti.csl.aer5f*<csl_dssWbPipe.oer5f>(.text.CSL_dssWbPipeGetChromaRes)
        ti.csl.aer5f*<csl_dssWbPipe.oer5f>(.text.CSL_dssWbPipeSetCSCCoeff)
        ti.csl.aer5f*<csl_dssWbPipe.oer5f>(.text.CSL_dssWbPipeConvFvid2DataFmt)
        ti.csl.aer5f*<csl_dssWbPipe.oer5f>(.text.Fvid2_isDataFmtRgb)
        libclang_rt.builtins.a*<aeabi_uldivmod.S.obj>(.text.__aeabi_uldivmod)
        ti.osal.aer5f*<CacheP_nonos.oer5f>(.text.CacheP_Inv)
        isp_qnx_magna.lib*<cogent_api.obj>(.text.setManufacturingTestMode)
        isp_qnx_magna.lib*<tweak_wrapper.obj>(.text.tweak_init)
        libclang_rt.builtins.a*<floatdisf.S.obj>(.text.__aeabi_l2f)
        libc.a*<s_roundf.c.obj>(.text.roundf)
        libc.a*<printf.c.obj>(.text.printf)
        ti.osal.aer5f*<HeapP_freertos.oer5f>(.text.HeapP_free)
        libclang_rt.builtins.a*<divsi3.S.obj>(.text.__aeabi_idiv)
        libc.a*<s_frexp.c.obj>(.text.frexpl)
        libclang_rt.builtins.a*<udivsi3.S.obj>(.text.__aeabi_uidiv)
        app_utils_console_io.lib*<app_log_rtos.obj>(.text.appLogGetGlobalTimeInUsec)
        libclang_rt.builtins.a*<aeabi_uldivmod.S.obj>(.text.__aeabi_uldivmod.2)
        libc.a*<memmov.c.obj>(.text.memmove)
        }
		
		.common_fast_code
        {
            *<aeabi_memcpy.S.obj>(.text)
            *<aeabi_memmove.S.obj>(.text)
            //*<aeabi_uldivmod.S.obj>(.text)
            app_utils_console_io.lib*<app_log_writer.obj>(.text.appLogPrintf)
            app_utils_console_io.lib*<app_log_rtos.obj>(.text.appLogWrUnLock)
            app_utils_console_io.lib*<app_log_writer.obj>(.text.appLogWrPutString)
            app_utils_console_io.lib*<app_log_rtos.obj>(.text.appLogGetTimeInUsec)
            app_utils_console_io.lib*<app_log_rtos.obj>(.text.appLogWrLock)
            *(.text.ceilf)
            *(.text.floorf)
            *(.text.logf)
            *(.text.expf)
            *(.text.qsort)
            *(.text.fflush)
            *(.text.powf)
            *(.text.__aeabi_llsl)
            *<aeabi_memset.S.obj>(.text)
            *<memcpy32.S.obj>(.text:memcpy)
            *<memset32.S.obj>(.text:memset)
            *(.text.sqrtf)
            *(.text.__aeabi_errno_addr)
            *(.text.puts)
            *(.text.fputs)
            *(.text.log2f)
            *(.text.__TI_wrt_ok)
            *(.text.memchr)
            *(.text.__TI_doflush)
            *(.text.snprintf)
            *(.text:__TI_printfi)
            *(.text.vsnprintf)
            *(.text.__aeabi_uidiv)
            *(.text.__aeabi_uldivmod)
            *(.text._pconv_a)
            *(.text._pconv_e)
            *(.text._pconv_f)
            *(.text._pconv_g)
            *(.text.memccpy)
            *(.text.strlen)
            *(.text.write)
            *(.text.fseek)
            *(.text.fseeko)
            *(.text.lseek)
            *(.text.free)
            *(.text.malloc)
            *(.text.setvbuf)
            *(.text.free_list_remove)
            *(.text.free_list_insert)
            *(.text.aligned_alloc)
            *(.text.atoi)
            *(.text.wcslen)
            *(.text.frexpl)
            *(.text.ldexp)
            *(.text.split)
            *(.text.__TI_ltoa)
            *(.text.strchr)
            *(.text._fcpy)
            *(.text._ecpy)
            *(.text._mcpy)
            *(.text.fcvt)
            *(.text.ceil)
            *(.text.floor)

            //libc.a<e_sqrtf.c.obj>(.text.sqrtf)
            //--library=libc.a<fputs.c.obj>(.text.puts)
            //--library=libc.a<e_log2f.c.obj>(.text.log2f)
            app_utils_mem.lib*<app_mem_free_rtos.obj>(.text.appMemFree)
        }
        .fast_udma_code
        {
            udma.aer5f*<udma.oer5f>(.text.Udma_defaultPhyToVirtFxn)
            udma.aer5f*<udma_rm.oer5f>(.text.Udma_rmFreeBlkCopyCh)
            udma.aer5f*<udma_rm.oer5f>(.text.Udma_rmFreeBlkCopyHcCh)
            udma.aer5f*<udma_rm.oer5f>(.text.Udma_rmFreeBlkCopyUhcCh)
            udma.aer5f*<udma_rm.oer5f>(.text.Udma_rmFreeRxHcCh)
            udma.aer5f*<udma_rm.oer5f>(.text.Udma_rmFreeRxUhcCh)
            udma.aer5f*<udma_rm.oer5f>(.text.Udma_rmFreeTxHcCh)
            udma.aer5f*<udma_rm.oer5f>(.text.Udma_rmFreeTxUhcCh)
        }
        .fast_data
        {
            vx_target_kernels_imaging_aewb.lib*<vx_aewb_target.obj>(.rodata.ts1_5_awb_calc_data)
            isp_qnx_magna.lib*<reg_write_ox3c.obj>(.rodata.parse_histogram_ox3c)
        }
        .isp_tcm      
    }

   /* Data sections. */
    GROUP  palign( 0x10000 ), LOAD_START( lnkRamStartAddr ), LOAD_END( lnkRamEndAddr )
    {
        .bss                                                    : {} align( 4 )
        .far                                                    : {} align( 4 )
        .data                                                   : {} palign( 128 )
        .boardcfg_data                                          : {} palign( 128 )
        .sysmem                                                 : {}
        .bss.devgroup*                                          : {} align( 4 )
        .bss:taskStackSection                                   : {}
        .const.devgroup*                                        : {} align( 4 )
        /*ipc_data_buffer (NOINIT)                                : {} palign(128)*/
	    .tracebuf                				                : {} align(1024)

    /* Additional sections settings. */

        .data_buffer                                            : {} palign(128)
        /* USB or any other LLD buffer for benchmarking */
        .benchmark_buffer (NOLOAD)                              : {} ALIGN (8)

    /* Stack sections. */
        .stack  RUN_START( lnkStacksStartAddr ) : {}                            align(4)
        .irqStack                               : {. = . + __IRQ_STACK_SIZE;}   align(4)
        RUN_START(__IRQ_STACK_START)
        RUN_END(__IRQ_STACK_END)

        .fiqStack                               : {. = . + __FIQ_STACK_SIZE;}   align(4)
        RUN_START(__FIQ_STACK_START)
        RUN_END(__FIQ_STACK_END)

        .abortStack                             : {. = . + __ABORT_STACK_SIZE;} align(4)
        RUN_START(__ABORT_STACK_START)
        RUN_END(__ABORT_STACK_END)

        .undStack                               : {. = . + __UND_STACK_SIZE;}   align(4)
        RUN_START(__UND_STACK_START)
        RUN_END(__UND_STACK_END)

        .svcStack    END( lnkStacksEndAddr )    : {. = . + __SVC_STACK_SIZE;}   align(4)
        RUN_START(__SVC_STACK_START)
        RUN_END(__SVC_STACK_END)
    } > MCU2_0_DDR_DATA_SPACE   (HIGH)
}

/*-------------------------------- END ---------------------------------------*/
