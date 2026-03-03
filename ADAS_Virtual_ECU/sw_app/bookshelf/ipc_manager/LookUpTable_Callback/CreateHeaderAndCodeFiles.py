#--------------------------------------------------------------------------------#
#   @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                  #
#                                                                                #
#   This is an unpublished work of authorship, which contains                    #
#   trade secrets, created in 2021.  Magna Electronics owns all                  #
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
#   @author Jesse Estes (Jesse.Estes@magna.com)                                  #
#--------------------------------------------------------------------------------#

###                              VERSION CONTROL                               ###
# V1:   basic functionality. generates two files: ipc_lookup_table.c and 
#           ipc_lookup_table.h
###                             END VERSION CONTROL                            ###

import os, ctypes, filecmp
import shutil, sys
import pandas as pd
from datetime import datetime

# create a new folder if the desired path does not exist
path = 'GeneratedFiles'
if not os.path.isdir(path):
    os.mkdir(path)

# create the header file
path = 'GeneratedFiles/'
header_file = open(path + 'ipc_lookup_table.h', 'w')

# set the workbook title
workbook = "../../Stellantis_L2H4060_IPC_SignalDef.xlsm"
tab_IpcLut = 'IPC_LookupTable'
tab_version = 'Version'

#--------------------------------------------------------------------------------#
#                                 Configuration                                  #
#--------------------------------------------------------------------------------#

#Column name
COL_MSG_NAME = 'Variable_Port_Name'
COL_DATA_TYPE = 'Data_Type'
COL_SOURCE = 'Source'
COL_MEM_REGION = 'Memory Region'
COL_BUFF_CNT = 'Buffer count'

#Core index
MPU1_0 = 0
MCU1_0 = 1
MCU2_0 = 2
MCU2_1 = 3
MCU3_0 = 4
MCU3_1 = 5
C66x_1 = 6
C66x_2 = 7

#List of cores
coreList = ['MPU1_0', 'MCU1_0', 'MCU2_0', 'MCU2_1', 'MCU3_0', 'MCU3_1', 'C66x_1', 'C66x_2']

#destination Core bit mask
coreBitMaskList = ["MPU1_0_BITMSK_0", "MCU1_0_BITMSK_1", "MCU2_0_BITMSK_2", "MCU2_1_BITMSK_3", "MCU3_0_BITMSK_4", "MCU3_1_BITMSK_5", "C66x_1_BITMSK_6", "C66x_2_BITMSK_7"]

#Precompiler switch list corresponding to each core
precompierSwitchList = ['(BUILD_MPU1_0)', '(BUILD_MCU1_0)', '(BUILD_MCU2_0)', '(BUILD_MCU2_1)', '(BUILD_MCU3_0)', '(BUILD_MCU3_1)', '(BUILD_C66x_1)', '(BUILD_C66x_2)']

#Memory region for Shared memory
memoryRegionList = ['DDR','MEMORY_2', 'MEMORY_3']
memoryRegionBaseAddrList = ['ipc_shared_Mem_buff','memoryRegion_2','memoryRegion_3']

#MessageID length alignment
MSG_ID_LEN_ALIGNEMENT = 64

#--------------------------------------------------------------------------------#
#                                 Variables                                  #
#--------------------------------------------------------------------------------#
#Signal Ids for enum
signalEnumIds = ""

#Message counter list corresponding to each core for Tx
txMsgCntrList = [0, 0, 0, 0, 0, 0, 0, 0]

#Number of Rx messages configured for all cores
rxMsgCntrList = [0, 0, 0, 0, 0, 0, 0, 0]

# create a DataFrame for version
versionDf = pd.read_excel(workbook, sheet_name = tab_version, header = 1, index_col = 0)

#Extract excel file version, modified date and current date and time
fileVersion = versionDf['Version'].iloc[-1]
fileDate = versionDf['Date'].iloc[-1]
GenerationDate = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

# create a DataFrame for the LUT data
data = pd.read_excel(workbook, sheet_name = tab_IpcLut, header = 0, index_col = 0)

#Extract below info
#1. Number of messages to transmit (Per core) 
#2. Total number messages to Receive (Per core) 
#3. Signal names Macros

# loop through all values in the DataFrame
for index, row in data.iterrows():
    # check the value of Variable Name/Port Name column of the current row
    if str(row[COL_MSG_NAME]) != 'nan':
        for Idx in range(len(coreList)):
            if str(row[COL_SOURCE]) == coreList[Idx]:
                #1. Extract Number of messages to transmit
                txMsgCntrList[Idx] += 1
                       
            elif (str(row[coreList[Idx]]) == '1.0') or (str(row[coreList[Idx]]) == '1'):
                #2. Extract Number of messages to Rx
                rxMsgCntrList[Idx] += 1
                
        #3. Extarct signal enum Ids
        if(index == 1):
            signalEnumIds += '    e_IpcMsgId_' + (str(row[COL_MSG_NAME]) + ' = 1').ljust(MSG_ID_LEN_ALIGNEMENT) + ',    /* 0x' + str(hex(index)[2:]).upper().zfill(4) + ' */\n'
        else:
            signalEnumIds += '    e_IpcMsgId_' + str(row[COL_MSG_NAME]).ljust(MSG_ID_LEN_ALIGNEMENT) + ',    /* 0x' + str(hex(index)[2:]).upper().zfill(4) + ' */\n'
signalEnumIds += str('    e_IpcMsgId_MAX_COUNT').ljust(MSG_ID_LEN_ALIGNEMENT)+', \n'    

# write the initial comments and configuration to the C header file. EDIT AS NEEDED
header_file.write(
    '/**' +
    '\n * @file ipc_lookup_table.h' +
    '\n * @brief Maintains look up table'
    '\n *' +
    '\n * @details This file maintains look up table using which Destination Core or' +
    '\n *          Destination software module can be identified in association with' +
    '\n *          Message ID' +
    '\n *'
    '\n * --------------------------------------------------------------------------' +
    '\n * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>' +
    '\n *' 
    '\n *   This is an unpublished work of authorship, which contains' +
    '\n *   trade secrets, created in 2021. Magna Electronics owns all' +
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
    '\n * @author ---- (---- @magna.com)' +
    '\n */' +
    '\n' +
    '\n#ifndef IPC_LOOKUP_TABLE_H_' +
    '\n#define IPC_LOOKUP_TABLE_H_' +
    '\n/* ===========================================================================' +
    '\n *' +
    '\n *   Include Files' +
    '\n *' +
    '\n * ======================================================================== */' +
    '\n' +
    '\n#include <stdio.h>' +
    '\n#include <stdint.h>' +
    '\n/* ===========================================================================' +
    '\n *' +
    '\n *   Defines' +
    '\n *' +
    '\n * ======================================================================== */' +
    '\n/* Number of Message ID configured to transmit and receive */'
)

for Idx in range(len(coreList)):
    header_file.write('\n#if defined' + precompierSwitchList[Idx])
    #Write D_NUMBER_OF_TX_MESSAGES
    header_file.write('\n#define D_NUMBER_OF_TX_MESSAGES            (' + str(str(txMsgCntrList[Idx]) + 'U)').ljust(5) + ' /* IPC lookup table size for TX */')
    #Write D_NUMBER_OF_RX_MESSAGES
    header_file.write('\n#define D_NUMBER_OF_RX_MESSAGES            (' + str(str(rxMsgCntrList[Idx]) + 'U)').ljust(5) + ' /* IPC lookup table size for RX */')
    header_file.write('\n#endif\n')
        
#Write Message ID Macros and structure declaration
header_file.write(
    '\n/* ===========================================================================' +
    '\n *' +
    '\n *   Global Data Types' +
    '\n *' +
    '\n * ======================================================================== */' +
    '\n/* enum for IPC message Ids */' +
    '\ntypedef enum IpcMsgId_e' +
    '\n{' +
    '\n' + signalEnumIds +
    '} IpcMsgId_t;' +
    '\n\n/* ===========================================================================' +
    '\n*' +
    '\n*   Global Variables' +
    '\n*' +
    '\n* ========================================================================= */'
)

header_file.write('\n\n/* ===========================================================================')
header_file.write('\n*')
header_file.write('\n*   Function Prototypes')
header_file.write('\n*')
header_file.write('\n* ========================================================================= */')

# write the end of the header file
header_file.write(
    '\n' +
    '\n/* ===========================================================================' +
    '\n *' +
    '\n *   End of Header File' +
    '\n *' +
    '\n * ======================================================================== */' +
    '\n#endif // IPC_LOOKUP_TABLE_H_' +
    '\n'
)

# close the header file
header_file.close()

# create the C code file
code_file = open(path + 'ipc_lookup_table.c', 'w')

# write to the C code file until the lookup table is reached
code_file.write(
    '/**' +
    '\n * @file ipc_lookup_table.c' +
    '\n * @brief Maintains look up table'
    '\n *' +
    '\n * @details This file maintains look up table using which Destination Core or' +
    '\n *          Destination software module can be identified in association with' +
    '\n *          Message ID' +
    '\n *'
    '\n * --------------------------------------------------------------------------' +
    '\n * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>' +
    '\n *' 
    '\n *   This is an unpublished work of authorship, which contains' +
    '\n *   trade secrets, created in 2021. Magna Electronics owns all' +
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
    '\n * @author ---- (---- @magna.com)' +
    '\n */' +
    '\n' +
    '\n/* ===========================================================================' +
    '\n *' +
    '\n *   Fisker_L2H5010_IPC_SignalDef.xlsm Version' +
    '\n *' +
    '\n * ======================================================================== */' +
    '\n/*'
    '\n * Excel file Version:  ' + str(fileVersion) +
    '\n * Excel file Mod Date: ' + str(fileDate) +
    '\n * Generated on:        ' + str(GenerationDate) +
    '\n */'
    '\n\n/* ===========================================================================' +
    '\n *' +
    '\n *   Include Files' +
    '\n *' +
    '\n * ======================================================================== */' +
    '\n#include \"ipc_lookup_table_include.h\"' +
    '\n' +
    '\n/* ===========================================================================' +
    '\n*' +
    '\n*   Defines' +
    '\n*' +
    '\n* ========================================================================= */' +
    '\n#if defined(BUILD_MCU2_0)' +
    '\n#define  TRUE   1' +
    '\n#define  FALSE  0' +
    '\n#endif' +
    '\n\n/* ===========================================================================' +
    '\n *' +
    '\n *   Function Prototypes' +
    '\n *' +
    '\n * ========================================================================= */' +
    '\n/* Callback functions prototype for signal handler */'
)

# loop through all values in the DataFrame
for index, row in data.iterrows():
    # check the value of Variable Name/Port Name column of the current row
    if str(row[COL_MSG_NAME]) != 'nan':
        dstCoreListCnt = 0
        for Idx in range(len(coreList)):
            #print(str(row[coreList[Idx]]))
            if (str(row[coreList[Idx]]) == '1.0') or (str(row[coreList[Idx]]) == '1'):                
                if dstCoreListCnt == 0:
                    code_file.write('\n#if defined' + precompierSwitchList[Idx])
                else:
                    code_file.write(' || defined' + precompierSwitchList[Idx])
                dstCoreListCnt += 1
                
        if dstCoreListCnt > 0:
            code_file.write('\nstatic void callback_MsgId_' + str(hex(index)[2:]).upper().zfill(4) + '(const void* i_msgData_ps);')
            code_file.write('\n#define D_IPC_CALLBACK_FUNC_' + str(hex(index)[2:]).upper().zfill(4) + '   (&callback_MsgId_' + str(hex(index)[2:]).upper().zfill(4) + ')')
            code_file.write('\n#endif\n')

code_file.write(
    '\n/* ===========================================================================' +
    '\n*' +
    '\n* Typedefs' +
    '\n*' +
    '\n* ========================================================================= */' +
    '\n/* Structure to occupy space in shared memory for signal handler data */' +
    '\n#if (D_NUMBER_OF_TX_MESSAGES > 0)'
)

for core in coreList:
    #Reinit Total shared buff count for next core
    code_file.write('\n\n#if defined(BUILD_' + core + ')')
    code_file.write('\n/* Structure definition for signal handler data with CRC32 */')
    # loop through all values in the DataFrame
    for index, row in data.iterrows():
        if str(row[COL_SOURCE]) == core:        
            # check the value of Variable Name/Port Name column of the current row
            if str(row[COL_MSG_NAME]) != 'nan':
                code_file.write('\ntypedef struct {')
                code_file.write('\n    ' + str(row[COL_DATA_TYPE]).ljust(45) + 'msgIdData_s;')
                code_file.write('\n    uint32_t                                msgIdCrc32_u32;')
                code_file.write('\n}msgIdDataStruct' + str(hex(index)[2:]).upper().zfill(4) + '_t;')
                code_file.write('\n')
    
    code_file.write('\n/* Declare shared memory buffers for above structures */')
    # loop through all values in the DataFrame
    for index, row in data.iterrows():
        if str(row[COL_SOURCE]) == core:        
            # check the value of Variable Name/Port Name column of the current row
            if str(row[COL_MSG_NAME]) != 'nan':
                for MemIdx in range(len(memoryRegionList)):
                    if( str(row[COL_MEM_REGION]) == memoryRegionList[MemIdx] ):
                        code_file.write(str('\nstatic msgIdDataStruct' + str(hex(index)[2:]).upper().zfill(4) + '_t').ljust(45) + 'msgIdStruct' + str(hex(index)[2:]).upper().zfill(4) + '_as[' + str(int(row[COL_BUFF_CNT])) + '] __attribute__ ((section("' + memoryRegionBaseAddrList[MemIdx] + '"), aligned(4)));')
                        break
    
    code_file.write('\n\n/* Shared memory buffer states */')
    # loop through all values in the DataFrame
    for index, row in data.iterrows():
        if str(row[COL_SOURCE]) == core:        
            # check the value of Variable Name/Port Name column of the current row
            if str(row[COL_MSG_NAME]) != 'nan':
                code_file.write('\nstatic IpcSmBuffState_t                            msgIdSmBuffState' + str(hex(index)[2:]).upper().zfill(4) + '_as[' + str(int(row[COL_BUFF_CNT])) + '];')
    
    # loop through all values in the DataFrame
    code_file.write('\n\n/* Shared memory buffer base addresss and size of corresponding message id */')
    for index, row in data.iterrows():
        if str(row[COL_SOURCE]) == core:        
            # check the value of Variable Name/Port Name column of the current row
            if str(row[COL_MSG_NAME]) != 'nan':
                code_file.write('\n#define D_SMBUFF_BASE_ADDR_' + str(hex(index)[2:]).upper().zfill(4) + '             ((sizeof(' + str(row[COL_DATA_TYPE]) + ')>D_IPC_MAX_DATA_PAYLOAD_SIZE) ? (uint8_t *)&msgIdStruct' + str(hex(index)[2:]).upper().zfill(4) + '_as[0].msgIdData_s : NULL)')
                code_file.write('\n#define D_SMBUFF_STRUCT_SIZE_' + str(hex(index)[2:]).upper().zfill(4) + '           (sizeof(msgIdDataStruct' + str(hex(index)[2:]).upper().zfill(4) + '_t))')
                code_file.write('\n')
                
    code_file.write('\n#endif')            
code_file.write('\n#endif')  
code_file.write('\n')
code_file.write('\n/* Shared memory buffer data size (Size occuiped by data, no CRC32) */')
# loop through all values in the DataFrame
for index, row in data.iterrows():
    # check the value of Variable Name/Port Name column of the current row
    if str(row[COL_MSG_NAME]) != 'nan':
        code_file.write('\n#define D_SMBUFF_DATA_SIZE_' + str(hex(index)[2:]).upper().zfill(4) + '             (sizeof(' + str(row[COL_DATA_TYPE]) + '))')


code_file.write(
    '\n\n/* ===========================================================================' +
    '\n*' +
    '\n* Private variables' +
    '\n*' +
    '\n* ========================================================================= */' +
    '\n/* Counter variable for each Message ID */'
)

# loop through all values in the DataFrame
for index, row in data.iterrows():
    # check the value of Variable Name/Port Name column of the current row
    if str(row[COL_MSG_NAME]) != 'nan':
        code_file.write('\n\n#if defined(BUILD_' + str(row[COL_SOURCE]) + ')')
        for Idx in range(len(coreList)):
            if (str(row[coreList[Idx]]) == '1.0') or (str(row[coreList[Idx]]) == '1'):
                code_file.write(' || defined' + precompierSwitchList[Idx])
        code_file.write('\nstatic uint32_t v_ipcMsgIdCnt_' + str(hex(index)[2:]).upper().zfill(4) + '_u32;')
        code_file.write('\n#define D_IPC_MSG_ID_CNT_' + str(hex(index)[2:]).upper().zfill(4) + '   (&v_ipcMsgIdCnt_' + str(hex(index)[2:]).upper().zfill(4) + '_u32)')
        code_file.write('\n#endif')

code_file.write(       
    '\n\n/* ===========================================================================' +
    '\n *' +
    '\n *   Global Data Types' +
    '\n *' +
    '\n * ======================================================================== */' +
    '\n/* Configuration for Tx messages */' +
    '\n#if (D_NUMBER_OF_TX_MESSAGES > 0)' +
    '\n\nconst ipcLutAttrTx_t V_ipcLutAttrTx_as[D_NUMBER_OF_TX_MESSAGES] = {' +
    '\n    /*          MSG_ID                                                               (                       MPU1_0            MCU1_0            MCU2_0            MCU2_1            MCU3_0            MCU3_1            C66X_1            C66X_2            Resv              Resv        )       Base address,             smBuffSize,                 DataSize,       buffCnt,  MessageIdCntr,         smBuffStateAddr,       */'
)

# Write Tx lookup table
for core in coreList:
    code_file.write('\n#if defined(BUILD_' + core + ')')
    # loop through all values in the DataFrame
    for index, row in data.iterrows():
        if str(row[COL_SOURCE]) == core:        
            # check the value of Variable Name/Port Name column of the current row
            if str(row[COL_MSG_NAME]) != 'nan':
                
                # write the Message ID
                code_file.write('\n    {  (uint16_t)e_IpcMsgId_' + str(row[COL_MSG_NAME]).ljust(MSG_ID_LEN_ALIGNEMENT) + ',')
            
                # write Distination core bit mask
                code_file.write('  ( CORE_BITMSK_CLR')
                
                # check all destination core
                for Idx in range(len(coreList)):  
                    if (str(row[coreList[Idx]]) == '1.0') or (str(row[coreList[Idx]]) == '1'):
                        #if the value is 1, core specific bitmask 
                        code_file.write(' | ' + coreBitMaskList[Idx])
                    else:
                        # otherwise leave blank
                        code_file.write('                  ')

                # Empty for Core 8   
                code_file.write('                  ')
                
                # Empty for Core 9 
                code_file.write('                  ')
                
                code_file.write(' ),')
                
                code_file.write('  D_SMBUFF_BASE_ADDR_' + str(hex(index)[2:]).upper().zfill(4) + ',')
                code_file.write(' D_SMBUFF_STRUCT_SIZE_' + str(hex(index)[2:]).upper().zfill(4) + ',')
                code_file.write(' D_SMBUFF_DATA_SIZE_' + str(hex(index)[2:]).upper().zfill(4) + ',')
                #Write shared memory buffer count for perticular message ID
                code_file.write(' ' + str(int(row[COL_BUFF_CNT])) + ',')
                code_file.write(' D_IPC_MSG_ID_CNT_' + str(hex(index)[2:]).upper().zfill(4) + ',')
                code_file.write(' &msgIdSmBuffState' + str(hex(index)[2:]).upper().zfill(4) + '_as[0]  },')
                
    code_file.write('\n\n#endif\n')
# print the end of the table
code_file.write('\n};')

code_file.write('\n\n#endif')
code_file.write('\n\n/* Configuration for Rx messages */')
code_file.write('\n#if (D_NUMBER_OF_RX_MESSAGES > 0)')
code_file.write('\nconst ipcLutAttrRx_t V_ipcLutAttrRx_as[D_NUMBER_OF_RX_MESSAGES] = {')
code_file.write('\n    /*          MSG_ID                                                                   DataSize,              MessageIdPrevCntr     Callback function      */')

# Write Rx lookup table
for core in coreList:
    code_file.write('\n#if defined(BUILD_' + core + ')')
    # loop through all values in the DataFrame
    for index, row in data.iterrows():
        # check the value of Variable Name/Port Name column of the current row
        if str(row[COL_MSG_NAME]) != 'nan':
            if (row[core]) == 1:
                # write the Message ID
                code_file.write('\n    {  (uint16_t)e_IpcMsgId_' + str(row[COL_MSG_NAME]).ljust(MSG_ID_LEN_ALIGNEMENT) + ',')
                code_file.write(' D_SMBUFF_DATA_SIZE_' + str(hex(index)[2:]).upper().zfill(4) + ',')
                code_file.write(' D_IPC_MSG_ID_CNT_' + str(hex(index)[2:]).upper().zfill(4) + ',')
                code_file.write(' D_IPC_CALLBACK_FUNC_' + str(hex(index)[2:]).upper().zfill(4) + '  },')
    code_file.write('\n#endif\n')
code_file.write('};')
code_file.write('\n#endif')

code_file.write(
'\n\n/* ===========================================================================' +
'\n*' +
'\n*   Private functions definition' +
'\n*' +
'\n* ========================================================================= */' +
'\n/* Callback function definition */'
)

dstCores = []
# loop through all values in the DataFrame
for message_id, row in data.iterrows():
    # check the value of Variable Name/Port Name column of the current row
    if str(row[COL_MSG_NAME]) != 'nan':
        dstCores.clear()
        for Idx in range(len(coreList)):
            if (row[coreList[Idx]] == 1):
                dstCores.append(coreList[Idx])
                
        if len(dstCores) != 0:
            code_file.write('\n\n#if defined(BUILD_' + dstCores[0] + ')')
            for Idx in range(1, len(dstCores)):
                code_file.write(' || defined(BUILD_' + dstCores[Idx] + ')')

            code_file.write(
                '\nstatic void callback_MsgId_' + str(hex(message_id)[2:]).upper().zfill(4) + '(const void* i_msgData_ps)' +
                '\n{' +
                '\n#if defined(BUILD_MPU1_0)' +
                '\n    IPC_F_addEvent_b(i_msgData_ps, e_IpcMsgId_' + str(row[COL_MSG_NAME]).strip() + ');' +
                '\n#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)' +
                '\n    (void)Rte_Write_' + str(row[COL_MSG_NAME]).strip() + '((const ' + str(row[COL_DATA_TYPE]).strip() + '*)' + 'i_msgData_ps);' +
                '\n#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)' +
                '\n    SigMgr_' + str(row[COL_MSG_NAME]).strip() + '_Put((' + str(row[COL_DATA_TYPE]).strip() + '*)' + 'i_msgData_ps);' +
                '\n#endif' +
                '\n}' +
                '\n#endif'
                )

        
code_file.write(
'\n' +
'\n/* ===========================================================================' +
'\n*' +
'\n*   Global functions' +
'\n*' +
'\n* ========================================================================= */' +
'\n/*' +
'\n * Purpose: Initialize all global variables accessed by pointer in IPC lookup table.' +
'\n * Description: IPC manager will call this function to initiaize all global variable used' +
'\n *              by IPC lookup table' +
'\n * Return Type : void' +
'\n*/' +
'\nvoid IPC_F_lookupTblInit_v (void)' +
'\n{' +
'\n#if ((D_NUMBER_OF_TX_MESSAGES > 0) || (D_NUMBER_OF_RX_MESSAGES > 0))' +
'\n    uint16_t v_msgIdx_u16;' +
'\n#endif' +
'\n' +
'\n#if (D_NUMBER_OF_TX_MESSAGES > 0)' +
'\n    uint8_t v_buffStateIdx_u8;' +
'\n' +
'\n    for(v_msgIdx_u16 = 0; v_msgIdx_u16 < D_NUMBER_OF_TX_MESSAGES; v_msgIdx_u16++)' +
'\n    {' +
'\n        /* Initialize shared memory buffer state variable */' +
'\n        if (V_ipcLutAttrTx_as[v_msgIdx_u16].buffStateAddr_ps != NULL)' +
'\n        {' +
'\n            for(v_buffStateIdx_u8 = 0; v_buffStateIdx_u8 < V_ipcLutAttrTx_as[v_msgIdx_u16].buffCnt_u8 ; v_buffStateIdx_u8++)' +
'\n            {' +
'\n                V_ipcLutAttrTx_as[v_msgIdx_u16].buffStateAddr_ps[v_buffStateIdx_u8].buffInUse_u16 = 0;' +
'\n                V_ipcLutAttrTx_as[v_msgIdx_u16].buffStateAddr_ps[v_buffStateIdx_u8].timer_u8 = 0;' +
'\n                V_ipcLutAttrTx_as[v_msgIdx_u16].buffStateAddr_ps[v_buffStateIdx_u8].currPktNum_u16 = 0;' +
'\n            }' +
'\n        }' +
'\n    }' +
'\n#endif' +
'\n' +
'\n#if (D_NUMBER_OF_RX_MESSAGES > 0)' +
'\n    for(v_msgIdx_u16 = 0; v_msgIdx_u16 < D_NUMBER_OF_RX_MESSAGES; v_msgIdx_u16++)' +
'\n    {' +
'\n        /* Initialize Message counter */' +
'\n        if (V_ipcLutAttrRx_as[v_msgIdx_u16].msgIdCntrPrev_pu32 != NULL)' +
'\n        {' +
'\n            *(V_ipcLutAttrRx_as[v_msgIdx_u16].msgIdCntrPrev_pu32) = 0;' +
'\n        }' +
'\n    }' +
'\n#endif' +
'\n}'
)

# print an end of file comment
code_file.write(
    '\n' +
    '\n/* ===========================================================================' +
    '\n *' +
    '\n *   End of Code File' +
    '\n *' +
    '\n * ======================================================================== */' +
    '\n'
)

# close the code file
code_file.close()

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
    path = os.path.join(os.getcwd(), 'GeneratedFiles')
    os.startfile(path)

# copy generated files to src and inc directory
shutil.copy('GeneratedFiles/ipc_lookup_table.c', '../src/') 
shutil.copy('GeneratedFiles/ipc_lookup_table.h', '../inc/') 
