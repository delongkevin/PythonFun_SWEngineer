/*
 * Enums.h
 *
 *  Created on: 30-Jul-2022
 *      Author: Bhagwan Patil
 */


#ifndef _ENUMS_H
#define _ENUMS_H

/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/
/*Bit MAsk for Bit Extraction*/
#define BIT_MASK_ONE_BIT         0x01u
#define BIT_MASK_TWO_BIT         0x03u
#define BIT_MASK_THREE_BIT       0x07u
#define BIT_MASK_FOUR_BIT        0x0Fu
#define BIT_MASK_FIVE_BIT        0x1Fu
#define BIT_MASK_SIX_BIT         0x3Fu
#define BIT_MASK_SEVEN_BIT       0x7Fu
#define BIT_MASK                 0xFFu
#define BIT_MASK_UPR             0xFF00u
#define BIT_MASK_LWR             0x00FFu
#define BIT_MSK_THIRD_NIBBLE     0x0F00u
#define BIT_MSK_SECOND_NIBBLE    0x00F0u
#define BIT_MASK_FIFTH_BIT       0x10u
#define BIT_MASK_SIXTH_BIT       0x20u

/*Byte Mask for Byte Extraction*/
#define FIRST_BYTE_MASK         0x000000FFu
#define SECOND_BYTE_MASK        0x0000FF00u
#define THIRD_BYTE_MASK       	0x00FF0000u
#define FOURTH_BYTE_MASK        0xFF000000u


/*Shift Bits Macro*/
#define BIT_SHIFT_ZERO_BIT        0u
#define BIT_SHIFT_ONE_BIT         1u
#define BIT_SHIFT_TWO_BIT         2u
#define BIT_SHIFT_THREE_BIT       3u
#define BIT_SHIFT_FOUR_BIT        4u
#define BIT_SHIFT_FIVE_BIT        5u
#define BIT_SHIFT_SIX_BIT         6u
#define BIT_SHIFT_SEVEN_BIT       7u
#define BIT_SHIFT_EIGHT_BIT       8u
#define BIT_SHIFT_NINE_BIT        9u
#define BIT_SHIFT_FOURTEEN_BIT    14u
#define BIT_SHIFT_SIXTEEN_BIT     16u
#define BIT_SHIFT_TWENTYFOUR_BIT  24u

#define THOUSAND                          1000u
#define SIX_THOUSAND                      6000u
#define TEN_THOUSAND                      10000u
#define TWELVE_THOUSAND                   1200u
#define FIFTEEN_HUNDRED                   1500u
#define EIGHTEEN_HUNDRED                  1800u
#define THOUSAND_TWO_NINETY_NINE          1299u
#define THOUSAND_TWO_THIRTY_ONE           1231u
#define THOUSAND_ONE_THIRTY               1130u
#define THOUSAND_SEVENTY_SEVEN            1077u
#define THOUSAND_TWENTY_EIGHT             1028u
#define THOUSAND_FOUR_FOURTY              1440u
#define THREE_THOUSAND_FOURTY_SIX         3046U
#define FOUR_THOUSAND_NINETY_SIX          4096u
#define THREE_THOUSAND                    3000u
#define FIFTY_ONE_THOUSAND_SEVEN_HUNDRED  51700u
#define FOUR_THOUSAND_SEVEN_HUNDRED       4700u
#define THIRTY_SIX_THOUSAND_TWO_TEN       36210u
#define THREE_THOUSAND_TEN                3010u
#define DEFAULT_VALUE                     0x0000u
#define THREE_HUNDRED_SIXTY               360u
#define FIVE_HUNDRED_ELEVEN				  511u			/* 511 = 0x1FF */
#define ONE_THOUSAND_TWENTY_THREE         1023u         /* 1023 = 0x3FF */
#define FOUR_THOUSAND_NINETY_FIVE         4095u        /* 4095 = 0xFFF */
#define EIGHT_THOUSAND_ONE_HUNDRED_NINETY_ONE  8191u   /* 8191 = 0x1FFF */
#define TWO_HUNDRED_FIFTY_FIVE            255u         /* 255 = 0xFF */
#define SEVEN_HUNDRED_SIXTY_EIGHT         768u
#define SIXTY_FIVE_THOUSAND_FIVE_HUNDRED_THIRTY_FIVE  65535       /*65535 =0xFFFF */
#define ONE_THOUSAND_TWENTY_FOUR          1024u
#define TWO_HUNDRED_SIXTEEN               216u         /* 216  */
#define NINETEEN_HUNDRED_TEWNTY           1920u
#define D_SPEED_CONV_FACTOR (0.0625f)

/* DID lenght define*/
#define DID_F186_DATA_LEN           3U
#define DID_F122_DATA_LEN           100U
#define DID_F132_DATA_LEN           10U
#define DID_F154_DATA_LEN           2U
#define DID_FDF2_DATA_LEN           1U
#define DID_FD61_DATA_LEN           12U

#define DID_1921_DATA_LEN            9u
#define DID_4451_SIZE_LEN           44u
#define DID_2010_DATA_LEN            2U
#define DID_5500_SIZE_LEN           42U
#define DID_5501_SIZE_LEN           48u
#define CAM_FD1C_SIZE_LEN           13u
#define DID_201A_SIZE_LEN           20u
#define DID_201B_SIZE_LEN           12u
#define DID_F1A6_DATA_LEN           6U
#define DID_2945_DATA_LEN           200u
#define DID_5100_SIZE_LEN           04u
#define DID_5102_DATA_LEN           34u
#define DID_5103_DATA_LEN           41u
#define DID_5106_SIZE_LEN           10u
#define DID_5107_SIZE_LEN           12u
#define DID_5108_SIZE_LEN           10u
#define DID_5109_SIZE_LEN           12u
#define DID_510B_SIZE_LEN            3u
#define DID_5300_SIZE_LEN           13u
#define DID_5301_SIZE_LEN           13u
#define DID_5302_SIZE_LEN           13u
#define DID_5303_SIZE_LEN           12u
#define DID_5304_SIZE_LEN           12u
#define DID_5305_SIZE_LEN           12u
#define DID_FD60_SIZE_LEN           28u
#define DID_2026_SIZE_LEN            8u
#define DID_5104_DATA_LEN            5u
#define DID_5105_DATA_LEN           19u

 /*Bit postion*/
 #define ZEROTH_BIT         0x0u
 #define FIRST_BIT         0x1u
 #define SECOND_BIT        0x2u
 #define THIRD_BIT         0x3u
 #define FOURTH_BIT        0x4u
 #define FIFTH_BIT         0x5u
 #define SIXTH_BIT         0x6u
 #define SEVENTH_BIT       0x7u
 #define EIGHTH_BIT        0x8u
 #define NINTH_BIT         0x9u
 #define TENTH_BIT         0xAu

 /*Byte postion*/
 #define ZEROTH_BYTE        0x0u
 #define FIRST_BYTE         0x1u
 #define SECOND_BYTE        0x2u
 #define THIRD_BYTE         0x3u
 #define FOURTH_BYTE        0x4u
 #define FIFTH_BYTE         0x5u
 #define SIXTH_BYTE         0x6u
 #define SEVENTH_BYTE       0x7u
 #define EIGHTH_BYTE        0x8u
 #define NINTH_BYTE         0x9u
 #define TENTH_BYTE         0xAu

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define INCREMENT_VALUE_BYONE(x) ((x)++)
#define RESET_VALUE_TOZERO(x) ((x) = 0U)
#define LEFTSHIFT_BIT(x, pos)   ((x) << (pos))
#define RIGHTSHIFT_BIT(x, pos)  ((x) >> (pos))
#define CHECK_BIT(x, Bit)    ((x) & (Bit))

/**********************************************************************************************************************
 *  Routine Status
 *********************************************************************************************************************/
#define RID_STATUS_NOTCOMPLETE                 0xFFu
#define RID_STATUS_COMPLETE                    0x00u
#define RID_STATUS_ABORT                       0x01u
#define RID_STATUS_ACTIVE                       0x02u


/**********************************************************************************************************************
 *  FullAutoParkSystem
 *********************************************************************************************************************/
#define FULL_AUTO_PARK_SYSTEM_OFF  0x00u
#define FULL_AUTO_PARK_SYSTEM_ON  0x01u

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum CameraID
{
  frontCam = 0u,
  leftCam,
  rearCam,
  rightCam
} CameraID;

enum ApaON_e
{
	e_ENABLE_SEEKING_STATE=1u,
	e_ENABLE_ENGAGED_SEMI_STATE,
	e_ENABLE_ENGAGED_FULL_STATE
};

enum Numbers_e
{
    e_ZERO =0u,
    e_ONE,
    e_TWO,
    e_THREE,
    e_FOUR,
    e_FIVE,
    e_SIX,
    e_SEVEN,
    e_EIGHT,
    e_NINE,
    e_TEN,
    e_ELEVEN,
    e_TWELVE,
    e_THIRTEEN,
    e_FOURTEEN,
    e_FIFTEEN,
    e_SIXTEEN,
    e_SEVENTEEN,
    e_EIGHTEEN,
    e_NINETEEN,
    e_TWENTY,
    e_TWENTY_ONE,
    e_TWENTY_TWO,
    e_TWENTY_THREE,
    e_TWENTY_FOUR,
    e_TWENTY_FIVE,
    e_TWENTY_SIX,
    e_TWENTY_SEVEN,
    e_TWENTY_EIGHT,
    e_TWENTY_NINE,
    e_THIRTY,
    e_THIRTY_ONE,
    e_THIRTY_TWO,
    e_THIRTY_THREE,
    e_THIRTY_FOUR,
    e_THIRTY_FIVE,
    e_THIRTY_SIX,
    e_THIRTY_SEVEN,
    e_THIRTY_EIGHT,
    e_THIRTY_NINE,
    e_FORTY,
    e_FORTY_ONE,
    e_FORTY_TWO,
    e_FORTY_THREE,
    e_FORTY_FOUR,
    e_FORTY_FIVE,
    e_FORTY_SIX,
    e_FORTY_SEVEN,
    e_FORTY_EIGHT,
    e_FORTY_NINE,
    e_FIFTY,
    e_FIFTY_ONE,
    e_FIFTY_TWO,
    e_FIFTY_THREE,
    e_FIFTY_FOUR,
    e_FIFTY_FIVE,
    e_FIFTY_SIX,
    e_FIFTY_SEVEN,
    e_FIFTY_EIGHT,
    e_FIFTY_NINE,
    e_SIXTY,
    e_SIXTY_ONE,
    e_SIXTY_TWO,
    e_SIXTY_THREE,
    e_SIXTY_FOUR,
    e_SIXTY_FIVE,
    e_SIXTY_SIX,
    e_SIXTY_SEVEN,
    e_SIXTY_EIGHT,
    e_SIXTY_NINE,
    e_SEVENTY,
    e_SEVENTY_ONE,
    e_SEVENTY_TWO,
    e_SEVENTY_THREE,
    e_SEVENTY_FOUR,
    e_SEVENTY_FIVE,
    e_SEVENTY_SIX,
    e_SEVENTY_SEVEN,
    e_SEVENTY_EIGHT,
    e_SEVENTY_NINE,
    e_EIGHTY,
    e_EIGHTY_ONE,
    e_EIGHTY_TWO,
    e_EIGHTY_THREE,
    e_EIGHTY_FOUR,
    e_EIGHTY_FIVE,
    e_EIGHTY_SIX,
    e_EIGHTY_SEVEN,
    e_EIGHTY_EIGHT,
    e_EIGHTY_NINE,
    e_NINETY,
    e_NINETY_ONE,
    e_NINETY_TWO,
    e_NINETY_THREE,
    e_NINETY_FOUR,
    e_NINETY_FIVE,
    e_NINETY_SIX,
    e_NINETY_SEVEN,
    e_NINETY_EIGHT,
    e_NINETY_NINE,
    e_ONE_HUNDRED,
    e_ONE_ONE,
    e_ONE_TWO,
    e_ONE_THREE,
    e_ONE_FOUR,
    e_ONE_FIVE,
    e_ONE_SIX,
    e_ONE_SEVEN,
    e_ONE_EIGHT,
    e_ONE_NINE,
    e_ONE_TEN,
    e_ONE_ELEVEN,
    e_ONE_TWELVE,
    e_ONE_THIRTEEN,
    e_ONE_FOURTEEN,
    e_ONE_FIFTEEN,
    e_ONE_SIXTEEN,
    e_ONE_SEVENTEEN,
    e_ONE_EIGHTEEN,
    e_ONE_NINETEEN,
    e_ONE_TWENTY,
    e_ONE_TWENTY_ONE,
    e_ONE_TWENTY_TWO,
    e_ONE_TWENTY_THREE,
    e_ONE_TWENTY_FOUR,
    e_ONE_TWENTY_FIVE,
    e_ONE_TWENTY_SIX,
    e_ONE_TWENTY_SEVEN,
    e_ONE_TWENTY_EIGHT,
    e_ONE_TWENTY_NINE,
    e_ONE_THIRTY,
    e_ONE_THIRTY_ONE,
    e_ONE_THIRTY_TWO,
    e_ONE_THIRTY_THREE,
    e_ONE_THIRTY_FOUR,
    e_ONE_THIRTY_FIVE,
    e_ONE_THIRTY_SIX,
    e_ONE_THIRTY_SEVEN,
    e_ONE_THIRTY_EIGHT,
    e_ONE_THIRTY_NINE,
    e_ONE_FORTY,
    e_ONE_FORTY_ONE,
    e_ONE_FORTY_TWO,
    e_ONE_FORTY_THREE,
    e_ONE_FORTY_FOUR,
    e_ONE_FORTY_FIVE,
    e_ONE_FORTY_SIX,
    e_ONE_FORTY_SEVEN,
    e_ONE_FORTY_EIGHT,
    e_ONE_FORTY_NINE,
    e_ONE_FIFTY,
    e_ONE_FIFTY_ONE,
    e_ONE_FIFTY_TWO,
    e_ONE_FIFTY_THREE,
    e_ONE_FIFTY_FOUR,
    e_ONE_FIFTY_FIVE,
    e_ONE_FIFTY_SIX,
    e_ONE_FIFTY_SEVEN,
    e_ONE_FIFTY_EIGHT,
    e_ONE_FIFTY_NINE,
    e_ONE_SIXTY,
    e_ONE_SIXTY_ONE,
    e_ONE_SIXTY_TWO,
    e_ONE_SIXTY_THREE,
    e_ONE_SIXTY_FOUR,
    e_ONE_SIXTY_FIVE,
    e_ONE_SIXTY_SIX,
    e_ONE_SIXTY_SEVEN,
    e_ONE_SIXTY_EIGHT,
    e_ONE_SIXTY_NINE,
    e_ONE_SEVENTY,
    e_ONE_SEVENTY_ONE,
    e_ONE_SEVENTY_TWO,
    e_ONE_SEVENTY_THREE,
    e_ONE_SEVENTY_FOUR,
    e_ONE_SEVENTY_FIVE,
    e_ONE_SEVENTY_SIX,
    e_ONE_SEVENTY_SEVEN,
    e_ONE_SEVENTY_EIGHT,
    e_ONE_SEVENTY_NINE,
    e_ONE_EIGHTY,
    e_ONE_EIGHTY_ONE,
    e_ONE_EIGHTY_TWO,
    e_ONE_EIGHTY_THREE,
    e_ONE_EIGHTY_FOUR,
    e_ONE_EIGHTY_FIVE,
    e_ONE_EIGHTY_SIX,
    e_ONE_EIGHTY_SEVEN,
    e_ONE_EIGHTY_EIGHT,
    e_ONE_EIGHTY_NINE,
    e_ONE_NINETY,
    e_ONE_NINETY_ONE,
    e_ONE_NINETY_TWO,
    e_ONE_NINETY_THREE,
    e_ONE_NINETY_FOUR,
    e_ONE_NINETY_FIVE,
    e_ONE_NINETY_SIX,
    e_ONE_NINETY_SEVEN,
    e_ONE_NINETY_EIGHT,
    e_ONE_NINETY_NINE,
	e_TWO_HUNDRED
};

enum Proxi_enum
{
e_TWO_HUNDRED_TWO = 202u,
e_TWO_TEN = 210u,
e_TWO_TWELEVE = 212u,
e_TWO_FORTY_EIGHT = 248u,
e_TWO_FIFTY_TWO = 252,
e_TWO_FIFTY_SIX = 256,
e_THREE_SIXTY = 360u,
e_SIX_SEVENTY = 670u,
e_NINE_EIGHTY = 980u,
e_NINE_TWENTY_FIVE = 925u,
e_EIGHT_SIXTY = 860u,
e_EIGHT_SIXTEEN = 816u,
e_SEVEN_EIGHTY_EIGHT = 788u,
e_SEVEN_SIXTY = 760u,
e_SEVEN_THIRTY_TWO = 732u,
e_SEVEN_TEN = 710u,
e_SIX_THIRTY = 630u,
e_FIVE_EIGHTY_FIVE = 585u,
e_FIVE_FIFTY_SEVEN = 557u,
e_FIVE_TWENTY_EIGHT = 528u,
e_FOUR_NINETY_NINE = 499u,
e_FOUR_SIXTY_FIVE = 465u,
e_FOUR_TWENTY_FIVE = 425u,
e_THREE_NINETY_SIX = 396u,
e_THREE_SIXTY_ONE = 361u,
e_THREE_THIRTY_TWO = 332u,
e_TWO_NINETY_ONE = 291u,
e_NEG_FIFTY = -50,
e_NEG_THIRTY_SEVEN = -37,
e_NEG_EIGHTEEN = -18,
e_NEG_EIGHT = -8
};

typedef enum {
	MCU1_0_Error_Fault_0 = 0,
	MCU1_0_Error_Fault_1 = 1,
	MCU1_0_Error_Fault_2 = 2,
	MCU1_0_Error_Fault_3 = 3,
	MCU1_0_Error_Fault_4 = 4,
	MCU1_0_Error_Fault_5 = 5,
	MCU1_0_Error_Fault_6 = 6,
	MCU1_0_Error_Fault_7 = 7,
	MCU1_0_Error_Fault_8 = 8,
	MCU1_0_Error_Fault_9 = 9,
	MCU1_0_Error_Fault_10 = 10,
	MCU1_0_Error_Fault_11 = 11,
	MCU1_0_Error_Fault_12 = 12,
	MCU1_0_Error_Fault_13 = 13,
	MCU1_0_Error_Fault_14 = 14,
	MCU1_0_Error_Fault_15 = 15,
	MCU1_0_Error_Fault_16 = 16,
	MCU1_0_Error_Fault_17 = 17,
	MCU1_0_Error_Fault_18 = 18,
	MCU1_0_Error_Fault_19 = 19,
	MCU1_0_Error_Fault_20 = 20,
	MCU1_0_Error_Fault_21 = 21,
	MCU1_0_Error_Fault_22 = 22,
	MCU1_0_Error_Fault_23 = 23,
	MCU1_0_Error_Fault_24 = 24,
	MCU1_0_Error_Fault_25 = 25,
	MCU1_0_Error_Fault_26 = 26,
	MCU1_0_Error_Fault_27 = 27,
	MCU1_0_Error_Fault_28 = 28,
	MCU1_0_Error_Fault_29 = 29,
	MCU1_0_Error_Fault_30 = 30,
	MCU1_0_Error_Fault_31 = 31,
	MCU1_0_Error_Fault_32 = 32,
	MCU1_0_Error_Fault_33 = 33,
	MCU1_0_Error_Fault_34 = 34,
	MCU1_0_Error_Fault_35 = 35,
	MCU1_0_Error_Fault_Max =255
}Error_FaultNum_MCU1_0;

#define SET_BIT(arg1,arg2) (arg1 |=  (TRUE<<arg2))
#define CLR_BIT(arg1,arg2) (arg1 &= ~(TRUE<<arg2))


#define ENUM_CLEAR_VALUE 0x00U  		/*0x00U*/
#define ENUM_SET_VALUE 0x01U    		/*0x01*/



# define EndiannessByteSwap32(x)                    x = (uint32)  ((((uint32)((x) & 0xFF000000UL)) >> 24u) | \
                                                    ( ((uint32)((x) & 0x00FF0000UL)) >>  8u) | \
                                                    ( ((uint32)((x) & 0x0000FF00UL)) <<  8u) | \
                                                    ( ((uint32)((x) & 0x000000FFUL)) << 24u))



#define EndiannessByteSwap16(x)                    x = ( (uint16)((x) >> 8u) | (uint16)((x) << 8u) )




#endif /**/
