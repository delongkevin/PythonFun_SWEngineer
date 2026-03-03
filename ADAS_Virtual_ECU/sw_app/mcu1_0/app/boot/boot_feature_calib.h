/*
*
* Copyright (c) 2019 Texas Instruments Incorporated
*
* All rights reserved not granted herein.
*
* Limited License.
*
* Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
* license under copyrights and patents it now or hereafter owns or controls to make,
* have made, use, import, offer to sell and sell ("Utilize") this software subject to the
* terms herein.  With respect to the foregoing patent license, such license is granted
* solely to the extent that any such patent is necessary to Utilize the software alone.
* The patent license shall not apply to any combinations which include this software,
* other than combinations with devices manufactured by or for TI ("TI Devices").
* No hardware patent is licensed hereunder.
*
* Redistributions must preserve existing copyright notices and reproduce this license
* (including the above copyright notice and the disclaimer and (if applicable) source
* code license limitations below) in the documentation and/or other materials provided
* with the distribution
*
* Redistribution and use in binary form, without modification, are permitted provided
* that the following conditions are met:
*
* *       No reverse engineering, decompilation, or disassembly of this software is
* permitted with respect to any software provided in binary form.
*
* *       any redistribution and use are licensed by TI for use only with TI Devices.
*
* *       Nothing shall obligate TI to provide you with source code for the software
* licensed and provided to you in object code.
*
* If software source code is provided to you, modification and redistribution of the
* source code are permitted provided that the following conditions are met:
*
* *       any redistribution and use of the source code, including any resulting derivative
* works, are licensed by TI for use only with TI Devices.
*
* *       any redistribution and use of any object code compiled from the source code
* and any resulting derivative works, are licensed by TI for use only with TI Devices.
*
* Neither the name of Texas Instruments Incorporated nor the names of its suppliers
*
* may be used to endorse or promote products derived from this software without
* specific prior written permission.
*
* DISCLAIMER.
*
* THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL TI AND TI'S LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
* OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
* OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/
#include "CalDataProvider_defs.h"

#ifndef BOOT_FEATURE_CALIB_H_
#define BOOT_FEATURE_CALIB_H_
/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#define FEATURE_CAL_DATA_FLASH_ADDR         (0x4580200U)  // Added 512 KB FCA header for secure flashing of cal. data 
#define FEATURE_CAL_OFFSET_HEADER_ADDR      (0x4580220U)
#define FEATURE_CALIBRATION_START_STR       (0x52545343U)
#define FEATURE_CALIBRATION_END_STR         (0x444E4543U)

extern bool APACalib_CRC_flag;
extern bool TRSCCalib_CRC_flag;
extern bool SVSCalib_CRC_flag;
extern bool THACalib_CRC_flag;
extern bool FODCalib_CRC_flag;

typedef struct Features_Cal_Offset_Header_s
{
    uint32_t magic_str_start;
    uint32_t USS_Start;
    uint32_t USS_Variant_Size;
    uint32_t USS_Vatint_Nos;
    uint32_t USS_Actual_Length;
    uint32_t USS_rsvd[4];
    uint32_t THA_Start;
    uint32_t THA_Variant_Size;
    uint32_t THA_Vatint_Nos;
    uint32_t THA_rsvd[5];
    uint32_t APA_Start;
    uint32_t APA_Variant_Size;
    uint32_t APA_Vatint_Nos;
    uint32_t APA_rsvd[5];
    uint32_t SVS_Start;
    uint32_t SVS_Variant_Size;
    uint32_t SVS_Vatint_Nos;
    uint32_t SVS_rsvd[5];
    uint32_t TRSC_Start;
    uint32_t TRSC_Variant_Size;
    uint32_t TRSC_Vatint_Nos;
    uint32_t TRSC_rsvd[5];
    uint32_t FOD_Start;
    uint32_t FOD_Variant_Size;
    uint32_t FOD_Vatint_Nos;
    uint32_t FOD_rsvd[5];
    uint32_t LMD_Start;
    uint32_t LMD_Variant_Size;
    uint32_t LMD_Vatint_Nos;
    uint32_t LMD_rsvd[5];
    uint32_t rsvd[198];
    uint32_t magic_str_end;
}Features_Cal_Offset_Header_t;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
void Get_USS_Calibration_Data(USS_Calibration_Data_t* calData, USS_Calibration_data_2_t* calData_2);
void Get_THA_Calibration_Data_MCU2_1(THA_Calibration_data_MCU2_1_t* calData);
void Get_THA_Calibration_Data_MPU1_0(THA_Calibration_data_MPU1_0_t* calData);
void Get_TRSC_Calibration_Data_MCU2_1(TRSC_Calibration_data_MCU2_1_t* calData);
void Get_TRSC_Calibration_Data_MPU1_0(TRSC_Calibration_data_MPU1_0_t* calData);
void Get_APA_Calibration_Data_MPU1_0(APA_Calibration_data_MPU1_0_t* calData);
void Get_APA_Calibration_Data_MCU2_1(APA_Calibration_data_MCU2_1_t* calData);
void Get_FOD_Calibration_Data(FOD_Calibration_data_t* calData);
void Get_LMD_Calibration_Data(LMD_Calibration_data_t* calData);
void Get_SVS_Calibration_Data(SVS_Calibration_data_t* calData);

#endif  /* #ifndef BOOT_FEATURE_CALIB_H_ */
/* @} */
