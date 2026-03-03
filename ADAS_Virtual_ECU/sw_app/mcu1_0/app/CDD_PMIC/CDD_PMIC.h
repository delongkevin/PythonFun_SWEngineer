#ifndef CDD_PMIC_H_
#define CDD_PMIC_H_
 

/**
 * \file     PMIC_CDD.h
 * \brief    PMIC CDD Manager Module
 * \author   Bhagwan Patil
 * \version
 * \details  h file public description of module
 */

#define D_DEVICEID_LEOA_PMIC        0x01
#define D_DEVICEID_LEOB_PMIC        0x02
#define D_DEVICEID_HERA_PMIC        0x03
#define INVALID_PMIC_SLAVE_ADDR     (0xFFU)

#define D_PMIC_LDO_REG_DATA           0x3F
#define D_PMIC_CLKMON_DIS_LEOA        0x13 
#define D_PMIC_CLKMON_DIS_LEOB        0x10
#define D_MISC_CTRL_REG               0x81
#define D_PMIC_BUCK5_REG_DATA         0x33
#define D_BUCK5_CTRL_REG              0x0C

#define D_LDO1_PG_WINDOW              0x27
#define D_LDO2_PG_WINDOW              0x28
#define D_LDO3_PG_WINDOW              0x29
#define D_LDO4_PG_WINDOW              0x2A

#define D_BUCK1_PG_WINDOW             0x18
#define D_BUCK3_PG_WINDOW             0x1A
#define D_BUCK4_PG_WINDOW             0x1B
#define D_BUCK5_PG_WINDOW             0x1C

#define D_ARRAY_SIZE                   20u

#define D_PMIC_ZERO_VALUE             0x00
#define D_PMIC_NINE_VALUE             0x09

extern void I2C0_TxEndNotification(void);
extern void I2C0_TxErrorNotification(void);

#endif

