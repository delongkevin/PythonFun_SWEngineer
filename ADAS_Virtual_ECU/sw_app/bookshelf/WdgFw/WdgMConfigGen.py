#--------------------------------------------------------------------------------#
#   @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                  #
#                                                                                #
#   This is an unpublished work of authorship, which contains                    #
#   trade secrets, created in 2022.  Magna Electronics owns all                  #
#   rights to this work and intends to maintain it in confidence                 #
#   to preserve its trade secret status. Magna Electronics                       #
#   reserves the right, under the copyright laws of the United                   #
#   States or those of any other country that may have jurisdiction,             #
#   to protect this work as an unpublished work, in the event of                 #
#   an inadvertent or deliberate unauthorized publication.                       #
#   Magna Electronics also reserves its rights under all copyright               #
#   laws to protect this work as a published work, when appropriate.             #
#   Those having access to this work may not copy it, use it,                    #
#   modify it, or disclose the information contained in it without               #
#   the written authorization of Magna Electronics.                              #
#                                                                                #
#   @author Pramod Kumar (pramod.kumar1@magna.com)                               #
#--------------------------------------------------------------------------------#

###                              VERSION CONTROL                               ###
# V1:   basic functionality. generates WdgM config files: xxx and xxx            #
###                             END VERSION CONTROL                            ###

import os, ctypes, filecmp
import pandas as pd
from datetime import datetime

#--------------------------------------------------------------------------------#
#                             Script Configuration                               #
#--------------------------------------------------------------------------------#
#corelist
corelist = ['mcu2_1']

# create a new folder if the desired path does not exist
dst_folder = 'GeneratedFiles'
dst_path = dst_folder + '/'

#WDGM config Files
WDGM_CFG_SRC_FILE = 'WdgM_Cfg.c'
WDGM_CFG_HDR_FILE = 'WdgM_Cfg.h'

# set the workbook title
Wdgm_cfg_excel_file = 'WdgFw_Config_Generator.xlsx'
tab_version = 'Version'
tab_General = ['MCU2_1_WdgMGeneral', 'MCU3_0_WdgMGeneral', 'MCU2_0_WdgMGeneral', 'MPU1_0_WdgMGeneral' ]
tab_Configset = ['MCU2_1_WdgMConfigset', 'MCU3_0_WdgMConfigset', 'MCU2_0_WdgMConfigset', 'MPU1_0_WdgMConfigset']

#Tab General - Column name
COL_PARAMETER = 'Parameter'
COL_VALUE = 'Value'

#Tab ConfigSet - Column name
COL_SUPERVISED_ENTITY = 'Supervised Entity'
COL_SUPERVISION_CHECKPOINT = 'Supervision Checkpoint'
COL_SUPERVISION_TYPE = 'Supervision Type'
COL_SUPERVISION_REF_CYCLE = 'SupervisionReferenceCycle'
COL_EXPECTED_ALIVE_INDICATIONS = 'ExpectedAliveIndications'
COL_MAX_MARGIN = 'MaxMargin'
COL_MIN_MARGIN = 'MinMargin'

#WDGM general config parameters
TRIGGER_CONDITION_PARAM = 'Trigger Condition Value (*10ms)'

#--------------------------------------------------------------------------------#
#                                 Variables                                  #
#--------------------------------------------------------------------------------#
sup_entity = []
sup_CP = []
sup_RefCyl = []
alive_ind = []
max_margin = []
min_margin = []

#--------------------------------------------------------------------------------#
#                          Data frames for excel files                           #
#--------------------------------------------------------------------------------#

# create a DataFrame for version
versionDf = pd.read_excel(Wdgm_cfg_excel_file, sheet_name = tab_version, header = 1, index_col = 0)

#Extract excel file version, modified date and current date and time
fileVersion = versionDf['Version'].iloc[-1]
fileDate = versionDf['Date'].iloc[-1]
GenerationDate = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

for core in corelist:
    # create a DataFrame for tab general
    general_df = pd.read_excel(Wdgm_cfg_excel_file, sheet_name = tab_General[corelist.index(core)], header = 0, index_col = 0)

    for index, row in general_df.iterrows():
        if str(row[COL_PARAMETER]) ==  TRIGGER_CONDITION_PARAM:
            Trigger_condition_val = str(row[COL_VALUE])
            
    del general_df

    # create a DataFrame for tab configset
    configSet_df = pd.read_excel(Wdgm_cfg_excel_file, sheet_name = tab_Configset[corelist.index(core)], header = 1, index_col = 0)

    # loop through all values in mcu2_1_df_configSet DataFrame
    for index, row in configSet_df.iterrows():
        if str(row[COL_SUPERVISED_ENTITY]) not in sup_entity:
            sup_entity.append(str(row[COL_SUPERVISED_ENTITY]))

            if (row[COL_SUPERVISION_TYPE] == 'Alive'):
                sup_CP.append(str(row[COL_SUPERVISION_CHECKPOINT]))
                sup_RefCyl.append(str(row[COL_SUPERVISION_REF_CYCLE]))
                alive_ind.append(str(row[COL_EXPECTED_ALIVE_INDICATIONS]))
                max_margin.append(str(row[COL_MAX_MARGIN]))
                min_margin.append(str(row[COL_MIN_MARGIN]))

    del configSet_df
    

    #--------------------------------------------------------------------------------#
    #                              Generate WdgM_Cfg.h                               #
    #--------------------------------------------------------------------------------#
    # Check/create target folder
    if not os.path.isdir(dst_path + core):
        os.mkdir(dst_path + core)

    # create header file
    wdgm_cfg_h_file = open(dst_path + core + '/' + WDGM_CFG_HDR_FILE, 'w')

    # write the initial comments and configuration to the C header file. EDIT AS NEEDED
    wdgm_cfg_h_file.write(
        '/**' +
        '\n * @file WdgM_Cfg.h' +
        '\n * @brief Watchdog manager config header file'
        '\n *' +
        '\n * @details This is generated config file for watchdog manager' +
        '\n *'
        '\n * --------------------------------------------------------------------------' +
        '\n * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>' +
        '\n *' +
        '\n *   This is an unpublished work of authorship, which contains' +
        '\n *   trade secrets, created in 2022. Magna Electronics owns all' +
        '\n *   rights to this work and intends to maintain it in confidence' +
        '\n *   to preserve its trade secret status. Magna Electronics' +
        '\n *   reserves the right, under the copyright laws of the United' +
        '\n *   States or those of any other country that may have jurisdiction,' +
        '\n *   to protect this work as an unpublished work, in the event of' +
        '\n *   an inadvertent or deliberate unauthorized publication.' +
        '\n *   Magna Electronics also reserves its rights under all copyright' +
        '\n *   laws to protect this work as a published work, when appropriate.' +
        '\n *   Those having access to this work may not copy it, use it,' +
        '\n *   modify it, or disclose the information contained in it without' +
        '\n *   the written authorization of Magna Electronics.' +
        '\n *' +
        '\n * --------------------------------------------------------------------------' +
        '\n * @author Pramod Kumar (Pramod.kumar1@magna.com)' +
        '\n */' +
        '\n' +
        '\n#if !defined (WDGM_CFG_H)' +
        '\n# define WDGM_CFG_H' +
        '\n' +
        '\n/**********************************************************************************************************************' +
        '\n *  INCLUDES' +
        '\n *********************************************************************************************************************/' +
        '\n# include "WdgM_Types.h"' +
        '\n' +
        '\n' +
        '\n/**********************************************************************************************************************' +
        '\n *  VERSION INFORMATION' +
        '\n *********************************************************************************************************************/' +
        '\n#define WDGM_CFG_MAJOR_VERSION (6u)' +
        '\n#define WDGM_CFG_MINOR_VERSION (0u)' +
        '\n#define WDGM_CFG_PATCH_VERSION (1u)' +
        '\n' +
        '\n#ifndef WDGM_DUMMY_STATEMENT' +
        '\n#define WDGM_DUMMY_STATEMENT(v) (v)=(v)' +
        '\n#endif' +
        '\n' +
        '\n' +
        '\n/* Module config related defines */' +
        '\n# define WDGM_NR_OF_CHECKPOINTS           (' + str(len(sup_CP)) + 'u)' +
        '\n# define WDGM_NR_OF_ENTITIES              (' + str(len(sup_entity)) + 'u)' +
        '\n# define WDGM_NR_OF_ALLOWED_CALLERS       (1u)' +
        '\n# define WDGM_NR_OF_GLOBAL_TRANSITIONS    (0u)' +
        '\n# define WDGM_NR_OF_LOCAL_TRANSITIONS     (0u)' +
        '\n# define WDGM_NR_OF_WATCHDOGS_CORE0       (1u)' +
        '\n# define WDGM_NR_OF_TRIGGER_MODES_CORE0   (1u)' +
        '\n' +
        '\n/* Checkpoints for supervised entities */'
    )

    for idx, cp in enumerate(sup_CP):
        wdgm_cfg_h_file.write('\n# define WdgMConf_WdgMCheckpoint_' + cp + ' (' + str(idx) + 'u)')

    wdgm_cfg_h_file.write('\n\n/* Supervised entities */')

    for idx, se in enumerate(sup_entity):
        wdgm_cfg_h_file.write('\n# define WdgMConf_WdgMSupervisedEntity_' + se + ' (' + str(idx) + 'u)')

    wdgm_cfg_h_file.write(
        '\n' +
        '\n' +
        '\nextern CONST(WdgM_ConfigType, WDGM_CONST) WdgMConfig_Mode0_core0;' +
        '\n' +
        '\n#endif /* WDGM_CFG_H*/' +
        '\n' +
        '\n/**********************************************************************************************************************' +
        '\n *  END OF FILE: WdgM_Cfg.h' +
        '\n *********************************************************************************************************************/' +
        '\n' +
        '\n'
    )
     
    # close the header file
    wdgm_cfg_h_file.close()

    #--------------------------------------------------------------------------------#
    #                              Generate WdgM_Cfg.c                               #
    #--------------------------------------------------------------------------------#

    # create the C code file
    wdgm_cfg_c_file = open(dst_path + core + '/' + WDGM_CFG_SRC_FILE, 'w')

    # write to the C code file
    wdgm_cfg_c_file.write(
        '/**' +
        '\n * @file WdgM_Cfg.c' +
        '\n * @brief Watchdog manager config header file'
        '\n *' +
        '\n * @details This is generated config file for watchdog manager' +
        '\n *'
        '\n * --------------------------------------------------------------------------' +
        '\n * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>' +
        '\n *' 
        '\n *   This is an unpublished work of authorship, which contains' +
        '\n *   trade secrets, created in 2022. Magna Electronics owns all' +
        '\n *   rights to this work and intends to maintain it in confidence' +
        '\n *   to preserve its trade secret status. Magna Electronics' +
        '\n *   reserves the right, under the copyright laws of the United' +
        '\n *   States or those of any other country that may have jurisdiction,' +
        '\n *   to protect this work as an unpublished work, in the event of' +
        '\n *   an inadvertent or deliberate unauthorized publication.' +
        '\n *   Magna Electronics also reserves its rights under all copyright' +
        '\n *   laws to protect this work as a published work, when appropriate.' +
        '\n *   Those having access to this work may not copy it, use it,' +
        '\n *   modify it, or disclose the information contained in it without' +
        '\n *   the written authorization of Magna Electronics.' +
        '\n *' +
        '\n * --------------------------------------------------------------------------' +
        '\n * @author Pramod Kumar (Pramod.kumar1@magna.com)' +
        '\n */' +
        '\n' +
        '\n/* ===========================================================================' +
        '\n *' +
        '\n *   ' + Wdgm_cfg_excel_file +
        '\n *' +
        '\n * ======================================================================== */' +
        '\n/*' +
        '\n * Excel file Version:  ' + str(fileVersion) +
        '\n * Excel file Mod Date: ' + str(fileDate) +
        '\n * Generated on:        ' + str(GenerationDate) +
        '\n*/'
        '\n\n\n/**********************************************************************************************************************'+
        '\n *  INCLUDES' +
        '\n *********************************************************************************************************************/'+
        '\n#include "WdgM.h"' +
        '\n' +
        '\n/**********************************************************************************************************************'+
        '\n *  VERSION INFORMATION AND CHECK' +
        '\n *********************************************************************************************************************/'+
        '\n#define WDGM_CFG_C_MAJOR_VERSION (6u)' +
        '\n#define WDGM_CFG_C_MINOR_VERSION (0u)' +
        '\n#define WDGM_CFG_C_PATCH_VERSION (1u)' +
        '\n' +
        '\n' +
        '\n/* Check the version of WdgM_Cfg header file */' +
        '\n#if ( (WDGM_CFG_MAJOR_VERSION != WDGM_CFG_C_MAJOR_VERSION) \\' +
        '\n   || (WDGM_CFG_MINOR_VERSION != WDGM_CFG_C_MINOR_VERSION) \\' +
        '\n   || (WDGM_CFG_PATCH_VERSION != WDGM_CFG_C_PATCH_VERSION) )' +
        '\n# error "Version numbers of WdgM_Cfg.c and WdgM_Cfg.h are inconsistent!"' +
        '\n#endif' +
        '\n' +
        '\n#if !defined (WDGM_LOCAL) /* COV_WDGM_COMPATIBILITY */' +
        '\n# define WDGM_LOCAL static' +
        '\n#endif' +
        '\n' +
        '\nWDGM_LOCAL VAR(WdgM_DataGSType, WDGM_VAR_NOINIT) StatusGS_core0;' +
        '\nWDGM_LOCAL VAR(WdgM_EntityGSType, WDGM_VAR_NOINIT) EntityGS [WDGM_NR_OF_ENTITIES];' +
        '\n' +
        '\n/* Local Status for Supervised Entities */'
    )

    for idx, se in enumerate(sup_entity):
        wdgm_cfg_c_file.write('\nWDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_' + str(idx) + ';')

    wdgm_cfg_c_file.write('\n\n/* Local Alive Counters for checkpoints */' )

    for idx, se in enumerate(sup_entity):
        wdgm_cfg_c_file.write('\nWDGM_LOCAL VAR(WdgM_AliveCounterLType, WDGM_VAR_NOINIT) Alive_CounterL_' + str(idx) + ';')

    wdgm_cfg_c_file.write('\n\n/* Global Status for Supervised Entities */' )

    for idx, se in enumerate(sup_entity):
        wdgm_cfg_c_file.write('\nWDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_' + str(idx) + ';')

    wdgm_cfg_c_file.write('\n\n/* Global Alive Counters for checkpoint */' )

    for idx, se in enumerate(sup_entity):
        wdgm_cfg_c_file.write('\nWDGM_LOCAL VAR(WdgM_AliveCounterGType, WDGM_VAR_NOINIT) Alive_CounterG_' + str(idx) + ';')

    wdgm_cfg_c_file.write(
        '\n' +
        '\n/* RAM section for Global Status */' +
        '\nWDGM_LOCAL VAR(WdgM_DataGType, WDGM_VAR_NOINIT) StatusG_core0;' +
        '\n' +
        '\n/* Global variables */' +
        '\nWDGM_LOCAL VAR(WdgM_GlobalVariablesType, WDGM_VAR_NOINIT) GlobalVariables_core0;' +
        '\n'
        '\nWDGM_LOCAL CONST(WdgM_CheckPointType, WDGM_CONST) WdgMCheckPoint[WDGM_NR_OF_CHECKPOINTS] =' +
        '\n{'
    ) 


    for idx, cp in enumerate(sup_CP):
        wdgm_cfg_c_file.write(
        '\n  {' +
        '\n    WdgMConf_WdgMCheckpoint_' + cp + '/*  WdgMCheckpointId  */ ,' +
        '\n    FALSE /*  WdgMIsEndCheckpoint  */ ,' +
        '\n    FALSE /*  WdgMIsEndCheckpointGlobal  */ ,' +
        '\n    ' + alive_ind[idx] + 'u /*  WdgMExpectedAliveIndications  */ ,' +
        '\n    ' + min_margin[idx] + 'u /*  WdgMMinMargin  */ ,' +
        '\n    ' + max_margin[idx] + 'u /*  WdgMMaxMargin  */ ,' +
        '\n    ' + sup_RefCyl[idx] + 'u /*  WdgMSupervisionReferenceCycle  */ ,' +
        '\n    &Alive_CounterL_' + str(idx) + '/*  WdgMAliveLRef  */ ,' +
        '\n    &Alive_CounterG_' + str(idx) + '/*  WdgMAliveGRef  */ ,' +
        '\n    FALSE /*  WdgMDeadlineMonitoring  */ ,' +
        '\n    0u /*  WdgMOutgoingDeadlineMax  */ ,' +
        '\n    0u /*  NrOfLocalTransitions  */ ,' +
        '\n    NULL_PTR /*  WdgMLocalTransitionRef  */ ,' +
        '\n    0u /*  NrOfGlobalTransitions  */ ,' +
        '\n    NULL_PTR /*  WdgMGlobalTransitionsRef  */ ,' +
        '\n    FALSE /*  WdgMStartsAGlobalTransition  */ ,' +
        '\n    0u /*  NrOfStartedGlobalTransitions  */ ,' +
        '\n    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */' +
        '\n  } /*  [' + str(idx) + ']  */'
        )
    wdgm_cfg_c_file.write('\n};')

    wdgm_cfg_c_file.write(
        '\n' +
        '\n' +
        '\nWDGM_LOCAL CONST(WdgM_SupervisedEntityType, WDGM_CONST) WdgMSupervisedEntity[WDGM_NR_OF_ENTITIES] =' +
        '\n{'
        )

    for idx, se in enumerate(sup_entity):
        wdgm_cfg_c_file.write(
        '\n  {' +
        '\n    WdgMConf_WdgMSupervisedEntity_' + se + ' /*  WdgMSupervisedEntity  */ ,' +
        '\n    FALSE /*  WdgMEnableEntityDeactivation  */ ,' +
        '\n    WdgMConf_WdgMCheckpoint_' + cp + ' /*  WdgMCheckpointLocInitialId  */ , ' +
        '\n    1u /*  NrOfCheckpoints  */ ,' +
        '\n    &WdgMCheckPoint[' + str(idx) + '] /*  WdgMCheckpointRef  */ ,' +
        '\n    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ ,' +
        '\n    0u /*  WdgMFailedSupervisionRefCycleTol  */ ,' +
        '\n    0u /*  WdgMFailedDeadlineRefCycleTol  */ ,' +
        '\n    0u /*  WdgMDeadlineReferenceCycle  */ ,' +
        '\n    0u /*  WdgMFailedProgramFlowRefCycleTol  */ ,' +
        '\n    0u /*  WdgMProgramFlowReferenceCycle  */ ,' +
        '\n    FALSE /*  WdgMProgramFlowMonitoring  */ ,' +
        '\n    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ ,' +
        '\n    NULL_PTR /*  WdgM_LocalStatusChangeNotification  */ ,' +
        '\n    &EntityStatusL_' + str(idx) + ' /*  EntityStatusLRef  */ ,' +
        '\n    &EntityStatusG_' + str(idx) + ' /*  EntityStatusGRef  */ ,' +
        '\n    0u /*  WdgMEntityCoreId  */' +
        '\n  } /*  [' + str(idx) + ']  */'
        )
    wdgm_cfg_c_file.write('\n};')


    wdgm_cfg_c_file.write(
        '\n' +
        '\n' +
        '\nWDGM_LOCAL CONST(WdgM_TriggerModeType, WDGM_CONST) WdgMTriggerMode_core0[WDGM_NR_OF_WATCHDOGS_CORE0 * WDGM_NR_OF_TRIGGER_MODES_CORE0] =' +
        '\n{' +
        '\n  {' +
        '\n    ' + Trigger_condition_val + 'u /*   (condition value)  WdgMTriggerTimeout  */ ,' +
        '\n    ' + Trigger_condition_val + 'u /*  WdgMTicksPerSecond[Hz]=1000 , WdgMTriggerTimeoutTicks  */ ,' +
        '\n    WDGIF_FAST_MODE /*  WdgMWatchdogMode  */ ,' +
        '\n    0u /*  WdgMDeviceIndex  */' +
        '\n  } /*  WdgMTriggerModeId 0  */' +
        '\n};' +
        '\n' +
        '\nWDGM_LOCAL CONST(WdgM_WatchdogDeviceType, WDGM_CONST) WdgMWatchdogDevice0[WDGM_NR_OF_WATCHDOGS_CORE0] =' +
        '\n{' +
        '\n  {' +
        '\n    &WdgMTriggerMode_core0[0] /*  WdgMTriggerModeRef  */' +
        '\n  } /*  [0]  */' +
        '\n};' +
        '\n' +
        '\n' +
        '\nWDGM_LOCAL CONST(WdgM_CallersType, WDGM_CONST) WdgMAllowedCallers[WDGM_NR_OF_ALLOWED_CALLERS] =' +
        '\n{' +
        '\n  {' +
        '\n    0u /*  WdgMAllowedCaller  */' +
        '\n  } /*  [0]  */' +
        '\n};' +
        '\n' +
        '\n' +
        '\nCONST(WdgM_ConfigType, WDGM_CONST) WdgMConfig_Mode0_core0 =' +
        '\n{' +
        '\n  6u /*  WdgMConfigMajorVersion  */ ,' +
        '\n  0u /*  WdgMConfigMinorVersion  */ ,' +
        '\n  0u /*  WdgMConfigId  */ ,' +
        '\n  0u /*  WdgMInitialTriggerModeId  */ ,' +
        '\n  0u /*  WdgMExpiredSupervisionCycleTol  */ ,' +
        '\n  WDGM_INVALID_SE_ID /*  WdgMGlobInitialEntityId  */ ,' +
        '\n  WDGM_INVALID_CP_ID /*  WdgMGlobInitialCheckpointId  */ ,' +
        '\n  WDGM_NR_OF_GLOBAL_TRANSITIONS /*  NrOfGlobalTransitions  */ ,' +
        '\n  NULL_PTR /*  WdgMGlobalTransitions  */ ,' +
        '\n  WDGM_NR_OF_WATCHDOGS_CORE0 /*  NrOfWatchdogDevices  */ ,' +
        '\n  WDGM_NR_OF_TRIGGER_MODES_CORE0 /*  NrOfTriggerModes  */ ,' +
        '\n  WdgMWatchdogDevice0 /*  WdgMWatchdogDeviceRef  */ ,' +
        '\n  WDGM_NR_OF_ALLOWED_CALLERS /*  NrOfAllowedCallers  */ ,' +
        '\n  WdgMAllowedCallers /*  WdgMCallersRef  */ ,' +
        '\n  WDGM_NR_OF_ENTITIES /*  NrOfSupervisedEntities  */ ,' +
        '\n  WdgMSupervisedEntity /*  WdgMSupervisedEntityRef  */ ,' +
        '\n  &StatusG_core0 /*  DataGRef  */ ,' +
        '\n  &StatusGS_core0 /*  DataGSRef  */ ,' +
        '\n  EntityGS /*  EntityGSRef  */ ,' +
        '\n  NULL_PTR /*  GlobalTransitionFlagsGSRef  */ ,' +
        '\n  NULL_PTR /*  WdgM_GlobalStatusChangeNotification  */ ,' +
        '\n  &GlobalVariables_core0 /*  WdgMGlobalVariables  */ ,' +
        '\n  0u /*  WdgMModeCoreAssignment  */ ,' +
        '\n  12u /*  WdgMConfigChecksum  */' +
        '\n};' +
        '\n' +
        '\n/**********************************************************************************************************************' +
        '\n *  END OF FILE: WdgM_Cfg.c' +
        '\n *********************************************************************************************************************/' +
        '\n' +
        '\n'
    )


    # close the code file
    wdgm_cfg_c_file.close()
    
    # clear all array
    sup_entity.clear()
    sup_CP.clear()
    sup_RefCyl.clear()
    alive_ind.clear()
    max_margin.clear()
    min_margin.clear()

# set the title and message to be displayed to the user after the script finishes
title = 'Files Created'
message = 'Files created from the given data.\nWould you like to open them in File Explorer?'

# make the message box have buttons 'Yes' and 'No'
style = 4

# set the response types to variables
YES = 6
NO = 7

# create a MessageBox and display it to the user
result = ctypes.windll.user32.MessageBoxW(None, message, title, style)

# check what button the user pressed
if result == YES:
    # if they pressed 'Yes', open the directory in File Explorer
    dst_path = os.path.join(os.getcwd(), dst_folder)
    os.startfile(dst_path)