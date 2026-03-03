#ifndef NVMDEF_USER_TYPE_H_INCLUDE
#define NVMDEF_USER_TYPE_H_INCLUDE

FUNC(void, NVM_PUBLIC_CODE) NvM_LossOfRedundancyCbk(NvM_BlockIdType BlockId);

extern VAR(CDP_TbSVS_S_SVSCamCurrentCalibData_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock_copy; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
extern VAR(CDP_TbSVS_S_SVSCamEOLCalibData_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock_copy; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
extern VAR(CDP_TbSVS_S_SVSCamOCCalibData_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock_copy; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
extern VAR(CDP_TbSVS_S_SVSCamSCCalibData_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock_copy; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */

extern VAR(ME_Hydra2defs_S_CodingTableExt_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_SWC_ProxiConfigMgr_ProxiConfigTable_MirrorBlock_copy; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
extern VAR(ME_Hydra2defs_S_PROXI_error_Data_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_SWC_ProxiConfigMgr_ProxiErrorData_MirrorBlock_copy; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */

extern VAR(uint8, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_INIT) Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_MirrorBlock_copy;
extern VAR(INVMSignalManager_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CDD_IPCHandler_FPA_Slot_Data_MirrorBlock_copy;
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_Safety_Guard_SafeStat2_ResetReason_MirrorBlock_copy;
extern VAR(Arr_2Byte, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_MirrorBlock_copy; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */

extern VAR(SecureLogRecord_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP)Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup1_Mirror_Copy;
extern VAR(SecureLogRecord_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP)Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup2_Mirror_Copy;

extern VAR(FinalAssemblySerialNumber_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_FrontCamSerialNumber_MirrorBlock_copy; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
extern VAR(FinalAssemblySerialNumber_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_LeftCamSerialNumber_MirrorBlock_copy; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
extern VAR(FinalAssemblySerialNumber_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_RearCamSerialNumber_MirrorBlock_copy; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
extern VAR(FinalAssemblySerialNumber_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_RightCamSerialNumber_MirrorBlock_copy; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */

#endif
