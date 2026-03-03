#ifndef ProxiMgrIpcDataTypes_H_INCGUARD
#define ProxiMgrIpcDataTypes_H_INCGUARD

typedef struct Proxi_to_IpcSignals_t
{
    boolean PRX_bValid_b;
    boolean PRX_TrlrHitchAssPres_b;
    boolean PRX_CanNod63_b;
    boolean PRX_CanNod67_b;
    boolean PRX_CanNod95_b;
    boolean PRX_CanNod14_b;
    boolean PRX_CanNod27_b;
    boolean PRX_SRT_b;
    boolean PRX_StopNStrt_b;
    boolean PRX_DrvSide_b;
    boolean PRX_ParkWithStop_b;
    boolean PRX_FrwFacingCam_b;
    boolean PRX_PAMCfg_b;
    boolean PRX_SemiAutoPrkgSys_b;
    boolean PRX_PullOutCtrlPres_b;
    boolean PRX_FullAutoPrkgSys_b;
    boolean PRX_SurroundViewCamera_b;
    boolean PRX_RvcEnbl_b;
    boolean PRX_AuxTrlrCam_b;
    boolean PRX_TrlrSurroundPresence_b;
    boolean PRX_TRGPresence_b;
    boolean PRX_TRSCPresence_b;
/* _GB_ : Not available at mcu1_0 Proxi */
    boolean PRX_ParksensePres_b;
    boolean PRX_ParkSenseCamView_b;
    boolean PRX_CvadasEthernet_b;
    boolean PRX_CanNode29_b;
    uint8 PRX_TcaseType_u8;
    uint8 PRX_SpecialPckgVP_u8;
/* Not available at mcu1_0 Proxi */
    uint8 PRX_VehLineCfg_u8;
    uint8 PRX_Wheelbase_u8;
    uint8 PRX_RadioDispTyp_u8;
    uint8 PRX_variantID_u8;
    uint8 PRX_StrRatRckPinionTyp_u8;
    uint8 PRX_AutonomyLvl_u8;
    uint8 PRX_DrvTypVrnt_u8;
    uint8 PRX_GbTyp_u8;
    uint8 PRX_PAMTunSet_u8;
    uint8 PRX_ModelYear_u8;
    uint8 PRX_HybTyp_u8;
    uint8 PRX_CountryCode_u8;
    uint8 PRX_MirrorType_u8;
    uint16 PRX_TyreSz_u16;
    float32 PRX_VehTyreSize_f32;
} ME_Proxi_to_IpcSignals_t;

typedef struct ME_ProxiToMPU1_0_Def_s
{
    boolean PRX_bValid_b;
    boolean PRX_TrlrHitchAssPres_b;
    boolean PRX_CanNod63_b;
    boolean PRX_CanNod67_b;
    boolean PRX_CanNod95_b;
    boolean PRX_CanNod14_b;
    boolean PRX_CanNod27_b;
    boolean PRX_SRT_b;
    boolean PRX_StopNStrt_b;
    boolean PRX_DrvSide_b;
    boolean PRX_ParkWithStop_b;
    boolean PRX_FrwFacingCam_b;
    boolean PRX_PAMCfg_b;
    boolean PRX_SemiAutoPrkgSys_b;
    boolean PRX_PullOutCtrlPres_b;
    boolean PRX_FullAutoPrkgSys_b;
    boolean PRX_SurroundViewCamera_b;
    boolean PRX_RvcEnbl_b;
    boolean PRX_AuxTrlrCam_b;
    boolean PRX_TrlrSurroundPresence_b;
    boolean PRX_TRGPresence_b;
    boolean PRX_TRSCPresence_b;
/* _GB_ : Not available at mcu1_0 Proxi */
    boolean PRX_ParksensePres_b;
    boolean PRX_ParkSenseCamView_b;
    boolean PRX_CvadasEthernet_b;
    boolean PRX_CanNode29_b;
    uint8 PRX_TcaseType_u8;
    uint8 PRX_SpecialPckgVP_u8;
/* Not available at mcu1_0 Proxi */
    uint8 PRX_VehLineCfg_u8;
    uint8 PRX_Wheelbase_u8;
    uint8 PRX_RadioDispTyp_u8;
    uint8 PRX_variantID_u8;
    uint8 PRX_StrRatRckPinionTyp_u8;
    uint8 PRX_AutonomyLvl_u8;
    uint8 PRX_DrvTypVrnt_u8;
    uint8 PRX_GbTyp_u8;
    uint8 PRX_PAMTunSet_u8;
    uint8 PRX_ModelYear_u8;
    uint8 PRX_HybTyp_u8;
    uint8 PRX_CountryCode_u8;
    uint8 PRX_MirrorType_u8;
    uint16 PRX_TyreSz_u16;
    float32 PRX_VehTyreSize_f32;
} ME_ProxiToMPU1_0_Def_t;

typedef struct ME_ProxiToMCU2_0_Def_s
{
    boolean PRX_bValid_b;
    boolean PRX_TrlrHitchAssPres_b;
    boolean PRX_CanNod63_b;
    boolean PRX_CanNod67_b;
    boolean PRX_CanNod95_b;
    boolean PRX_CanNod14_b;
    boolean PRX_CanNod27_b;
    boolean PRX_SRT_b;
    boolean PRX_StopNStrt_b;
    boolean PRX_DrvSide_b;
    boolean PRX_ParkWithStop_b;
    boolean PRX_FrwFacingCam_b;
    boolean PRX_PAMCfg_b;
    boolean PRX_SemiAutoPrkgSys_b;
    boolean PRX_PullOutCtrlPres_b;
    boolean PRX_FullAutoPrkgSys_b;
    boolean PRX_SurroundViewCamera_b;
    boolean PRX_RvcEnbl_b;
    boolean PRX_AuxTrlrCam_b;
    boolean PRX_TrlrSurroundPresence_b;
    boolean PRX_TRGPresence_b;
    boolean PRX_TRSCPresence_b;
/* _GB_ : Not available at mcu1_0 Proxi */
    boolean PRX_ParksensePres_b;
    boolean PRX_ParkSenseCamView_b;
    boolean PRX_CvadasEthernet_b;
    boolean PRX_CanNode29_b;
    uint8 PRX_TcaseType_u8;
    uint8 PRX_SpecialPckgVP_u8;
/* Not available at mcu1_0 Proxi */
    uint8 PRX_VehLineCfg_u8;
    uint8 PRX_Wheelbase_u8;
    uint8 PRX_RadioDispTyp_u8;
    uint8 PRX_variantID_u8;
    uint8 PRX_StrRatRckPinionTyp_u8;
    uint8 PRX_AutonomyLvl_u8;
    uint8 PRX_DrvTypVrnt_u8;
    uint8 PRX_GbTyp_u8;
    uint8 PRX_PAMTunSet_u8;
    uint8 PRX_ModelYear_u8;
    uint8 PRX_HybTyp_u8;
    uint8 PRX_CountryCode_u8;
    uint8 PRX_MirrorType_u8;
    uint16 PRX_TyreSz_u16;
    float32 PRX_VehTyreSize_f32;
} ME_ProxiToMCU2_0_Def_t;

typedef struct ME_ProxiToMCU2_1_Def_s
{
    boolean PRX_bValid_b;
    boolean PRX_TrlrHitchAssPres_b;
    boolean PRX_CanNod63_b;
    boolean PRX_CanNod67_b;
    boolean PRX_CanNod95_b;
    boolean PRX_CanNod14_b;
    boolean PRX_CanNod27_b;
    boolean PRX_SRT_b;
    boolean PRX_StopNStrt_b;
    boolean PRX_DrvSide_b;
    boolean PRX_ParkWithStop_b;
    boolean PRX_FrwFacingCam_b;
    boolean PRX_PAMCfg_b;
    boolean PRX_SemiAutoPrkgSys_b;
    boolean PRX_PullOutCtrlPres_b;
    boolean PRX_FullAutoPrkgSys_b;
    boolean PRX_SurroundViewCamera_b;
    boolean PRX_RvcEnbl_b;
    boolean PRX_AuxTrlrCam_b;
    boolean PRX_TrlrSurroundPresence_b;
    boolean PRX_TRGPresence_b;
    boolean PRX_TRSCPresence_b;
/* _GB_ : Not available at mcu1_0 Proxi */
    boolean PRX_ParksensePres_b;
    boolean PRX_ParkSenseCamView_b;
    boolean PRX_CvadasEthernet_b;
    boolean PRX_CanNode29_b;
    uint8 PRX_TcaseType_u8;
    uint8 PRX_SpecialPckgVP_u8;
/* Not available at mcu1_0 Proxi */
    uint8 PRX_VehLineCfg_u8;
    uint8 PRX_Wheelbase_u8;
    uint8 PRX_RadioDispTyp_u8;
    uint8 PRX_variantID_u8;
    uint8 PRX_StrRatRckPinionTyp_u8;
    uint8 PRX_AutonomyLvl_u8;
    uint8 PRX_DrvTypVrnt_u8;
    uint8 PRX_GbTyp_u8;
    uint8 PRX_PAMTunSet_u8;
    uint8 PRX_ModelYear_u8;
    uint8 PRX_HybTyp_u8;
    uint8 PRX_CountryCode_u8;
    uint8 PRX_MirrorType_u8;
    uint16 PRX_TyreSz_u16;
    float32 PRX_VehTyreSize_f32;
} ME_ProxiToMCU2_1_Def_t;
#endif
