/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_SWC_PartNumMgr_Type.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application types header file for SW-C <SWC_PartNumMgr>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PARTNUMMGR_TYPE_H
# define RTE_SWC_PARTNUMMGR_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef DCM_E_POSITIVERESPONSE
#   define DCM_E_POSITIVERESPONSE (0U)
#  endif

#  ifndef DCM_E_GENERALREJECT
#   define DCM_E_GENERALREJECT (16U)
#  endif

#  ifndef DCM_E_SERVICENOTSUPPORTED
#   define DCM_E_SERVICENOTSUPPORTED (17U)
#  endif

#  ifndef DCM_E_SUBFUNCTIONNOTSUPPORTED
#   define DCM_E_SUBFUNCTIONNOTSUPPORTED (18U)
#  endif

#  ifndef DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT
#   define DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT (19U)
#  endif

#  ifndef DCM_E_RESPONSETOOLONG
#   define DCM_E_RESPONSETOOLONG (20U)
#  endif

#  ifndef DCM_E_BUSYREPEATREQUEST
#   define DCM_E_BUSYREPEATREQUEST (33U)
#  endif

#  ifndef DCM_E_CONDITIONSNOTCORRECT
#   define DCM_E_CONDITIONSNOTCORRECT (34U)
#  endif

#  ifndef DCM_E_REQUESTSEQUENCEERROR
#   define DCM_E_REQUESTSEQUENCEERROR (36U)
#  endif

#  ifndef DCM_E_NORESPONSEFROMSUBNETCOMPONENT
#   define DCM_E_NORESPONSEFROMSUBNETCOMPONENT (37U)
#  endif

#  ifndef DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION
#   define DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION (38U)
#  endif

#  ifndef DCM_E_REQUESTOUTOFRANGE
#   define DCM_E_REQUESTOUTOFRANGE (49U)
#  endif

#  ifndef DCM_E_SECURITYACCESSDENIED
#   define DCM_E_SECURITYACCESSDENIED (51U)
#  endif

#  ifndef DCM_E_AUTHENTICATIONREQUIRED
#   define DCM_E_AUTHENTICATIONREQUIRED (52U)
#  endif

#  ifndef DCM_E_INVALIDKEY
#   define DCM_E_INVALIDKEY (53U)
#  endif

#  ifndef DCM_E_EXCEEDNUMBEROFATTEMPTS
#   define DCM_E_EXCEEDNUMBEROFATTEMPTS (54U)
#  endif

#  ifndef DCM_E_REQUIREDTIMEDELAYNOTEXPIRED
#   define DCM_E_REQUIREDTIMEDELAYNOTEXPIRED (55U)
#  endif

#  ifndef DCM_E_CVF_INVALIDTIMEPERIOD
#   define DCM_E_CVF_INVALIDTIMEPERIOD (80U)
#  endif

#  ifndef DCM_E_CVF_INVALIDSIGNATURE
#   define DCM_E_CVF_INVALIDSIGNATURE (81U)
#  endif

#  ifndef DCM_E_CVF_INVALIDCHAINOFTRUST
#   define DCM_E_CVF_INVALIDCHAINOFTRUST (82U)
#  endif

#  ifndef DCM_E_CVF_INVALIDTYPE
#   define DCM_E_CVF_INVALIDTYPE (83U)
#  endif

#  ifndef DCM_E_CVF_INVALIDFORMAT
#   define DCM_E_CVF_INVALIDFORMAT (84U)
#  endif

#  ifndef DCM_E_CVF_INVALIDCONTENT
#   define DCM_E_CVF_INVALIDCONTENT (85U)
#  endif

#  ifndef DCM_E_CVF_INVALIDSCOPE
#   define DCM_E_CVF_INVALIDSCOPE (86U)
#  endif

#  ifndef DCM_E_CVF_INVALIDCERTIFICATEREVOKED
#   define DCM_E_CVF_INVALIDCERTIFICATEREVOKED (87U)
#  endif

#  ifndef DCM_E_OWNERSHIPVERIFICATIONFAILED
#   define DCM_E_OWNERSHIPVERIFICATIONFAILED (88U)
#  endif

#  ifndef DCM_E_CHALLENGECALCULATIONFAILED
#   define DCM_E_CHALLENGECALCULATIONFAILED (89U)
#  endif

#  ifndef DCM_E_UPLOADDOWNLOADNOTACCEPTED
#   define DCM_E_UPLOADDOWNLOADNOTACCEPTED (112U)
#  endif

#  ifndef DCM_E_TRANSFERDATASUSPENDED
#   define DCM_E_TRANSFERDATASUSPENDED (113U)
#  endif

#  ifndef DCM_E_GENERALPROGRAMMINGFAILURE
#   define DCM_E_GENERALPROGRAMMINGFAILURE (114U)
#  endif

#  ifndef DCM_E_WRONGBLOCKSEQUENCECOUNTER
#   define DCM_E_WRONGBLOCKSEQUENCECOUNTER (115U)
#  endif

#  ifndef DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING
#   define DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING (120U)
#  endif

#  ifndef DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION
#   define DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION (126U)
#  endif

#  ifndef DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION
#   define DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION (127U)
#  endif

#  ifndef DCM_E_RPMTOOHIGH
#   define DCM_E_RPMTOOHIGH (129U)
#  endif

#  ifndef DCM_E_RPMTOOLOW
#   define DCM_E_RPMTOOLOW (130U)
#  endif

#  ifndef DCM_E_ENGINEISRUNNING
#   define DCM_E_ENGINEISRUNNING (131U)
#  endif

#  ifndef DCM_E_ENGINEISNOTRUNNING
#   define DCM_E_ENGINEISNOTRUNNING (132U)
#  endif

#  ifndef DCM_E_ENGINERUNTIMETOOLOW
#   define DCM_E_ENGINERUNTIMETOOLOW (133U)
#  endif

#  ifndef DCM_E_TEMPERATURETOOHIGH
#   define DCM_E_TEMPERATURETOOHIGH (134U)
#  endif

#  ifndef DCM_E_TEMPERATURETOOLOW
#   define DCM_E_TEMPERATURETOOLOW (135U)
#  endif

#  ifndef DCM_E_VEHICLESPEEDTOOHIGH
#   define DCM_E_VEHICLESPEEDTOOHIGH (136U)
#  endif

#  ifndef DCM_E_VEHICLESPEEDTOOLOW
#   define DCM_E_VEHICLESPEEDTOOLOW (137U)
#  endif

#  ifndef DCM_E_THROTTLE_PEDALTOOHIGH
#   define DCM_E_THROTTLE_PEDALTOOHIGH (138U)
#  endif

#  ifndef DCM_E_THROTTLE_PEDALTOOLOW
#   define DCM_E_THROTTLE_PEDALTOOLOW (139U)
#  endif

#  ifndef DCM_E_TRANSMISSIONRANGENOTINNEUTRAL
#   define DCM_E_TRANSMISSIONRANGENOTINNEUTRAL (140U)
#  endif

#  ifndef DCM_E_TRANSMISSIONRANGENOTINGEAR
#   define DCM_E_TRANSMISSIONRANGENOTINGEAR (141U)
#  endif

#  ifndef DCM_E_BRAKESWITCH_NOTCLOSED
#   define DCM_E_BRAKESWITCH_NOTCLOSED (143U)
#  endif

#  ifndef DCM_E_SHIFTERLEVERNOTINPARK
#   define DCM_E_SHIFTERLEVERNOTINPARK (144U)
#  endif

#  ifndef DCM_E_TORQUECONVERTERCLUTCHLOCKED
#   define DCM_E_TORQUECONVERTERCLUTCHLOCKED (145U)
#  endif

#  ifndef DCM_E_VOLTAGETOOHIGH
#   define DCM_E_VOLTAGETOOHIGH (146U)
#  endif

#  ifndef DCM_E_VOLTAGETOOLOW
#   define DCM_E_VOLTAGETOOLOW (147U)
#  endif

#  ifndef DCM_E_VMSCNC_0
#   define DCM_E_VMSCNC_0 (240U)
#  endif

#  ifndef DCM_E_VMSCNC_1
#   define DCM_E_VMSCNC_1 (241U)
#  endif

#  ifndef DCM_E_VMSCNC_2
#   define DCM_E_VMSCNC_2 (242U)
#  endif

#  ifndef DCM_E_VMSCNC_3
#   define DCM_E_VMSCNC_3 (243U)
#  endif

#  ifndef DCM_E_VMSCNC_4
#   define DCM_E_VMSCNC_4 (244U)
#  endif

#  ifndef DCM_E_VMSCNC_5
#   define DCM_E_VMSCNC_5 (245U)
#  endif

#  ifndef DCM_E_VMSCNC_6
#   define DCM_E_VMSCNC_6 (246U)
#  endif

#  ifndef DCM_E_VMSCNC_7
#   define DCM_E_VMSCNC_7 (247U)
#  endif

#  ifndef DCM_E_VMSCNC_8
#   define DCM_E_VMSCNC_8 (248U)
#  endif

#  ifndef DCM_E_VMSCNC_9
#   define DCM_E_VMSCNC_9 (249U)
#  endif

#  ifndef DCM_E_VMSCNC_A
#   define DCM_E_VMSCNC_A (250U)
#  endif

#  ifndef DCM_E_VMSCNC_B
#   define DCM_E_VMSCNC_B (251U)
#  endif

#  ifndef DCM_E_VMSCNC_C
#   define DCM_E_VMSCNC_C (252U)
#  endif

#  ifndef DCM_E_VMSCNC_D
#   define DCM_E_VMSCNC_D (253U)
#  endif

#  ifndef DCM_E_VMSCNC_E
#   define DCM_E_VMSCNC_E (254U)
#  endif

#  ifndef DCM_INITIAL
#   define DCM_INITIAL (0U)
#  endif

#  ifndef DCM_PENDING
#   define DCM_PENDING (1U)
#  endif

#  ifndef DCM_CANCEL
#   define DCM_CANCEL (2U)
#  endif

#  ifndef DCM_FORCE_RCRRP_OK
#   define DCM_FORCE_RCRRP_OK (3U)
#  endif

#  ifndef DCM_FORCE_RCRRP_NOT_OK
#   define DCM_FORCE_RCRRP_NOT_OK (64U)
#  endif

#  ifndef NVM_REQ_OK
#   define NVM_REQ_OK (0U)
#  endif

#  ifndef NVM_REQ_NOT_OK
#   define NVM_REQ_NOT_OK (1U)
#  endif

#  ifndef NVM_REQ_PENDING
#   define NVM_REQ_PENDING (2U)
#  endif

#  ifndef NVM_REQ_INTEGRITY_FAILED
#   define NVM_REQ_INTEGRITY_FAILED (3U)
#  endif

#  ifndef NVM_REQ_BLOCK_SKIPPED
#   define NVM_REQ_BLOCK_SKIPPED (4U)
#  endif

#  ifndef NVM_REQ_NV_INVALIDATED
#   define NVM_REQ_NV_INVALIDATED (5U)
#  endif

#  ifndef NVM_REQ_CANCELED
#   define NVM_REQ_CANCELED (6U)
#  endif

#  ifndef NVM_REQ_REDUNDANCY_FAILED
#   define NVM_REQ_REDUNDANCY_FAILED (7U)
#  endif

#  ifndef NVM_REQ_RESTORED_FROM_ROM
#   define NVM_REQ_RESTORED_FROM_ROM (8U)
#  endif

#  ifndef NVM_READ_BLOCK
#   define NVM_READ_BLOCK (6U)
#  endif

#  ifndef NVM_WRITE_BLOCK
#   define NVM_WRITE_BLOCK (7U)
#  endif

#  ifndef NVM_RESTORE_BLOCK_DEFAULTS
#   define NVM_RESTORE_BLOCK_DEFAULTS (8U)
#  endif

#  ifndef NVM_ERASE_BLOCK
#   define NVM_ERASE_BLOCK (9U)
#  endif

#  ifndef NVM_INVALIDATE_NV_BLOCK
#   define NVM_INVALIDATE_NV_BLOCK (11U)
#  endif

#  ifndef NVM_READ_ALL
#   define NVM_READ_ALL (12U)
#  endif

#  ifndef SSM_APPSTATE_UNINIT
#   define SSM_APPSTATE_UNINIT (0U)
#  endif

#  ifndef SSM_APPSTATE_INIT
#   define SSM_APPSTATE_INIT (1U)
#  endif

#  ifndef SSM_APPSTATE_RUNNING
#   define SSM_APPSTATE_RUNNING (2U)
#  endif

#  ifndef SSM_APPSTATE_DEGRADED
#   define SSM_APPSTATE_DEGRADED (3U)
#  endif

#  ifndef SSM_APPSTATE_STOPPED
#   define SSM_APPSTATE_STOPPED (4U)
#  endif

#  ifndef SSM_APPSTATE_MAX
#   define SSM_APPSTATE_MAX (5U)
#  endif

#  ifndef SSM_APPSTATE_UNINIT
#   define SSM_APPSTATE_UNINIT (0U)
#  endif

#  ifndef SSM_APPSTATE_INIT
#   define SSM_APPSTATE_INIT (1U)
#  endif

#  ifndef SSM_APPSTATE_RUNNING
#   define SSM_APPSTATE_RUNNING (2U)
#  endif

#  ifndef SSM_APPSTATE_DEGRADED
#   define SSM_APPSTATE_DEGRADED (3U)
#  endif

#  ifndef SSM_APPSTATE_STOPPED
#   define SSM_APPSTATE_STOPPED (4U)
#  endif

#  ifndef SSM_APPSTATE_MAX
#   define SSM_APPSTATE_MAX (5U)
#  endif

#  ifndef SSM_SlaveCore_State_Unknown
#   define SSM_SlaveCore_State_Unknown (0U)
#  endif

#  ifndef SSM_SlaveCore_State_BSP_Booting
#   define SSM_SlaveCore_State_BSP_Booting (1U)
#  endif

#  ifndef SSM_SlaveCore_State_BSP_Init_Done
#   define SSM_SlaveCore_State_BSP_Init_Done (2U)
#  endif

#  ifndef SSM_SlaveCore_State_Calibrated
#   define SSM_SlaveCore_State_Calibrated (3U)
#  endif

#  ifndef SSM_SlaveCore_State_AppInitialized
#   define SSM_SlaveCore_State_AppInitialized (4U)
#  endif

#  ifndef SSM_SlaveCore_State_Running
#   define SSM_SlaveCore_State_Running (5U)
#  endif

#  ifndef SSM_SlaveCore_State_MAX
#   define SSM_SlaveCore_State_MAX (6U)
#  endif

#  ifndef SSM_SlaveCore_State_Unknown
#   define SSM_SlaveCore_State_Unknown (0U)
#  endif

#  ifndef SSM_SlaveCore_State_BSP_Booting
#   define SSM_SlaveCore_State_BSP_Booting (1U)
#  endif

#  ifndef SSM_SlaveCore_State_BSP_Init_Done
#   define SSM_SlaveCore_State_BSP_Init_Done (2U)
#  endif

#  ifndef SSM_SlaveCore_State_Calibrated
#   define SSM_SlaveCore_State_Calibrated (3U)
#  endif

#  ifndef SSM_SlaveCore_State_AppInitialized
#   define SSM_SlaveCore_State_AppInitialized (4U)
#  endif

#  ifndef SSM_SlaveCore_State_Running
#   define SSM_SlaveCore_State_Running (5U)
#  endif

#  ifndef SSM_SlaveCore_State_MAX
#   define SSM_SlaveCore_State_MAX (6U)
#  endif

#  ifndef SSM_DEGRADEDSTATE_MAX
#   define SSM_DEGRADEDSTATE_MAX (0U)
#  endif

#  ifndef SSM_STATE_BOOTING
#   define SSM_STATE_BOOTING (0U)
#  endif

#  ifndef SSM_STATE_IPCREADY
#   define SSM_STATE_IPCREADY (1U)
#  endif

#  ifndef SSM_STATE_RUNNING
#   define SSM_STATE_RUNNING (2U)
#  endif

#  ifndef SSM_STATE_DEGRADED
#   define SSM_STATE_DEGRADED (3U)
#  endif

#  ifndef SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP
#   define SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP (4U)
#  endif

#  ifndef SSM_STATE_SHUTTINGDOWN_REMOTECORES
#   define SSM_STATE_SHUTTINGDOWN_REMOTECORES (5U)
#  endif

#  ifndef SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE
#   define SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE (6U)
#  endif

#  ifndef SSM_STATE_OFF
#   define SSM_STATE_OFF (7U)
#  endif

#  ifndef SSM_STATE_BOOT_ERROR
#   define SSM_STATE_BOOT_ERROR (8U)
#  endif

#  ifndef SSM_STATE_MAX
#   define SSM_STATE_MAX (9U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PARTNUMMGR_TYPE_H */
