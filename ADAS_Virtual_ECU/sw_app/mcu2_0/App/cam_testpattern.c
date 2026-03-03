/*

*/

#include <ti/osal/osal.h>

#include "cogent_api.h"

extern int32_t set_register_via_iss(uint32_t channel_id, uint32_t reg_addr, uint32_t value);

int32_t cam_testpattern(uint32_t sensorIdx, uint8_t pattern)
{
	/* DD-ID: {A6ED63B4-1B49-445e-B0CD-AE5A09DEF6E8}*/
    int32_t status = -1;
    v3xISP_ManufacturingTestType_t testtype;
    static uint8_t cam_reg_update = 0;

    testtype = (v3xISP_ManufacturingTestType_t)pattern;

        set_register_via_iss(sensorIdx, 0x3187, 0xFF);
        set_register_via_iss(sensorIdx, 0x4f00, 0x3F);
        set_register_via_iss(sensorIdx, 0x4f01, 0xFF);
        set_register_via_iss(sensorIdx, 0x4f02, 0xFF);
      //setManufacturingTestMode(sensorIdx, testtype);
    switch(pattern)
    {
        case ISP_MANUFACTURING_COLOR_BAR:
            status =  set_register_via_iss(sensorIdx, 0x5240, 0x01);
            status |=  set_register_via_iss(sensorIdx, 0x5440, 0x01);
            status |=  set_register_via_iss(sensorIdx, 0x5640, 0x01);
            status |=  set_register_via_iss(sensorIdx, 0x5840, 0x01);
            status |=  set_register_via_iss(sensorIdx, 0x5004, 0x1f);
            status |=  set_register_via_iss(sensorIdx, 0x5005, 0x00);
            status |=  set_register_via_iss(sensorIdx, 0x5006, 0x1f);
            status |=  set_register_via_iss(sensorIdx, 0x5007, 0x1f);
            break;
        case ISP_MANUFACTURING_COLOR_BAR_GRADIENT:
            status =  set_register_via_iss(sensorIdx, 0x5240, 0x11);
            status |=  set_register_via_iss(sensorIdx, 0x5440, 0x11);
            status |=  set_register_via_iss(sensorIdx, 0x5640, 0x11);
            status |=  set_register_via_iss(sensorIdx, 0x5840, 0x11);
            status |=  set_register_via_iss(sensorIdx, 0x5004, 0x1f);
            status |=  set_register_via_iss(sensorIdx, 0x5005, 0x00);
            status |=  set_register_via_iss(sensorIdx, 0x5006, 0x1f);
            status |=  set_register_via_iss(sensorIdx, 0x5007, 0x1f);
            break;
        case ISP_MANUFACTURING_TEST_NONE:
        default:
            status =  set_register_via_iss(sensorIdx, 0x5240, 0x0f);
            status |=  set_register_via_iss(sensorIdx, 0x5440, 0x0f);
            status |=  set_register_via_iss(sensorIdx, 0x5640, 0x0f);
            status |=  set_register_via_iss(sensorIdx, 0x5840, 0x0f);
            status |=  set_register_via_iss(sensorIdx, 0x5004, 0x1e);
            status |=  set_register_via_iss(sensorIdx, 0x5005, 0x1e);
            status |=  set_register_via_iss(sensorIdx, 0x5006, 0x1e);
            status |=  set_register_via_iss(sensorIdx, 0x5007, 0x1e);
    }

    return status;
}


