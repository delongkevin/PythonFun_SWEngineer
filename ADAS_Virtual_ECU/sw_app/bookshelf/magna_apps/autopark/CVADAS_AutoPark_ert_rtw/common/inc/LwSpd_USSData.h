#ifndef LwSpd_USSData_H_INCGUARD 
#define LwSpd_USSData_H_INCGUARD 


typedef struct
{
	uint32_t timestamp;
	uint16_t firingSensors;
}Firing_Sensors;

typedef struct 
{
	uint32_t timestamp;
	uint8_t firingSequence;
}Firing_Sequence;

typedef struct 
{
	unsigned short Sig_Snr_EEPROM_Fail;
	unsigned short Sig_Snr_High_Voltage;
	unsigned short Sig_Snr_Low_Voltage;
	unsigned short Sig_Snr_RAM_Fail;
}Diag_1;

typedef struct 
{
	unsigned char Sig_Disturbance_Detected;
	unsigned char Sig_FW_Inconsistant_Snr;
	unsigned char Sig_ECU_EEPROM_Fail;
	unsigned char Sig_ECU_Low_Voltage;
	unsigned char Sig_ECU_High_Voltage;
	unsigned char Sig_Comm_Snr_Error;
	unsigned short Sig_Snr_Transducer_Error;
	unsigned short Sig_Snr_Abnormal;
	unsigned short Sig_Snr_Blockage;
	unsigned short Sig_Snr_Disconnect;
}Diag_2;

typedef struct 
{
	unsigned short Sig_SnrDat_FSR_Dir1_cm;
	unsigned short Sig_SnrDat_FOR_Dir1_cm;
	unsigned short Sig_SnrDat_FIR_Dir1_cm;
	unsigned short Sig_SnrDat_FIL_Dir1_cm;
	unsigned short Sig_SnrDat_FOL_Dir1_cm;
	unsigned short Sig_SnrDat_FSL_Dir1_cm;
}Front_Direct;

struct Front_Indirect_1
{
	unsigned short Sig_SnrDat_sFSR_Indir_FOR_cm;
	unsigned short Sig_SnrDat_sFOR_Indir_FSR_cm;
	unsigned short Sig_SnrDat_sFOR_Indir_FIR_cm;
	unsigned short Sig_SnrDat_sFIR_Indir_FOR_cm;
	unsigned short Sig_SnrDat_sFIR_Indir_FIL_cm;
	unsigned short Sig_SnrDat_sFIL_Indir_FIR_cm;
};

struct Front_Indirect_2
{
	unsigned short Sig_SnrDat_sFIL_Indir_FOL_cm;
	unsigned short Sig_SnrDat_sFOL_Indir_FIL_cm;
	unsigned short Sig_SnrDat_sFOL_Indir_FSL_cm;
	unsigned short Sig_SnrDat_sFSL_Indir_FOL_cm;
};

typedef struct 
{
	unsigned short Sig_SnrDat_FSR_Dir2_cm;
	unsigned short Sig_SnrDat_FOR_Dir2_cm;
	unsigned short Sig_SnrDat_FIR_Dir2_cm;
	unsigned short Sig_SnrDat_FIL_Dir2_cm;
	unsigned short Sig_SnrDat_FOL_Dir2_cm;
	unsigned short Sig_SnrDat_FSL_Dir2_cm;
}Front_Direct_2;

typedef struct 
{
	unsigned short Sig_SnsDat_FSL_Timestamp_us;
	unsigned short Sig_SnsDat_FSL_DirEcho1_cm;
	unsigned short Sig_SnsDat_FSL_DirEcho2_cm;
	unsigned short Sig_SnsDat_FSR_Timestamp_us;
	unsigned short Sig_SnsDat_FSR_DirEcho1_cm;
	unsigned short Sig_SnsDat_FSR_DirEcho2_cm;
}FrontPSM_Echoes;

typedef struct 
{
	unsigned short Sig_SnrDat_RSR_Dir1_cm;
	unsigned short Sig_SnrDat_ROR_Dir1_cm;
	unsigned short Sig_SnrDat_RIR_Dir1_cm;
	unsigned short Sig_SnrDat_RIL_Dir1_cm;
	unsigned short Sig_SnrDat_ROL_Dir1_cm;
	unsigned short Sig_SnrDat_RSL_Dir1_cm;
}Rear_Direct;

struct Rear_Indirect_1
{
	unsigned short Sig_SnrDat_sRSL_Indir_ROL_cm;
	unsigned short Sig_SnrDat_sROL_Indir_RSL_cm;
	unsigned short Sig_SnrDat_sROL_Indir_RIL_cm;
	unsigned short Sig_SnrDat_sRIL_Indir_ROL_cm;
	unsigned short Sig_SnrDat_sRIL_Indir_RIR_cm;
	unsigned short Sig_SnrDat_sRIR_Indir_RIL_cm;
};

struct Rear_Indirect_2
{
	unsigned short Sig_SnrDat_sRIR_Indir_ROR_cm;
	unsigned short Sig_SnrDat_sROR_Indir_RIR_cm;
	unsigned short Sig_SnrDat_sROR_Indir_RSR_cm;
	unsigned short Sig_SnrDat_sRSR_Indir_ROR_cm;
};

typedef struct 
{
	unsigned short Sig_SnrDat_RSR_Dir2_cm;
	unsigned short Sig_SnrDat_ROR_Dir2_cm;
	unsigned short Sig_SnrDat_RIR_Dir2_cm;
	unsigned short Sig_SnrDat_RIL_Dir2_cm;
	unsigned short Sig_SnrDat_ROL_Dir2_cm;
	unsigned short Sig_SnrDat_RSL_Dir2_cm;
}Rear_Direct_2;

typedef struct 
{
	unsigned short Sig_SnsDat_RSL_Timestamp_us;
	unsigned short Sig_SnsDat_RSL_DirEcho1_cm;
	unsigned short Sig_SnsDat_RSL_DirEcho2_cm;
	unsigned short Sig_SnsDat_RSR_Timestamp_us;
	unsigned short Sig_SnsDat_RSR_DirEcho1_cm;
	unsigned short Sig_SnsDat_RSR_DirEcho2_cm;
}RearSide_Echoes;

typedef struct 
{
	float32_t Fisker_Point_Map_X;
	float32_t Fisker_Point_Map_Y;
	sint16_t Fisker_Point_Map_Height;
	uint8_t Fisker_Point_Map_Cruising_Age;
	uint8_t Fisker_Point_Map_Confidence;
	uint8_t Fisker_Point_Map_Age;
	float32_t Fisker_Point_Map_Reserved;
}Triangulated_Points;

struct USSSectorData
{
	uint8_t FrontZones[6]; // Left to right  (FSL FOL FIL FIR FOR FSR)
	uint8_t RearZones[6]; // Left to right  (RSL ROL RIL RIR ROR RSR)
};

enum ParkingMode
{
	US_PARKMODE_STANDBY = 0,
	US_PARKMODE_SCANNING,
	US_PARKMODE_PARKING
};
typedef struct 
{
	/*
	@@ SUB_STRUCTURE = m_FiringSensor
	@@ STRUCTURE = USSData_Input
	@@ DATA_TYPE = STRUCTURE Firing_Sensors
	@@ END
	*/
	Firing_Sensors m_FiringSensor;//not used /* <IPC signal name: IME_US_FiringSensorsOutputBuff_t> firing sensors information */
	Firing_Sequence m_FiringSequence; // Not available in Source
	Diag_1 m_Diag1; //  not used /* <IPC signal name: IMsgCAN1_ME_Diag_1_t> diagnostic signals */
	Diag_2 m_Diag2; //  not used /* <IPC signal name: IMsgCAN1_ME_Diag_2_t> diagnostic signals */
	/*
    @@ SUB_STRUCTURE = m_Front_Direct 
    @@ STRUCTURE = USSData_Input
    @@ DATA_TYPE = STRUCTURE Front_Direct
    @@ DIMENSION = 2 SPLIT
    @@ END
    */
	Front_Direct m_Front_Direct[2];//Source: [0]: /* <IPC signal name: IMsgCAN1_ME_SnsDat_Front_Direct_t> front direct echoes */, [1]: /* <IPC signal name: IMsgCAN1_ME_SnsDat_Front_Direct_2_t> front direct 2 echoes */:   
	Front_Indirect_1 m_Front_Indirect_1; // not used 
	Front_Indirect_2 m_Front_Indirect_2; // not used 
	/*
    @@ SUB_STRUCTURE = m_FrontPSM_Echoes 
    @@ STRUCTURE = USSData_Input
    @@ DATA_TYPE = STRUCTURE FrontPSM_Echoes
    @@ END
    */
	FrontPSM_Echoes m_FrontPSM_Echoes;//not used  /* <IPC signal name: IMsgCAN1_ME_SnsDat_FrontPSM_Echoes_t> front PSM side echoes */
	/*
    @@ SUB_STRUCTURE = m_Rear_Direct 
    @@ STRUCTURE = USSData_Input
    @@ DATA_TYPE = STRUCTURE Rear_Direct
    @@ DIMENSION = 2 SPLIT
    @@ END
    */
	Rear_Direct m_Rear_Direct[2]; // Source: [0]: /* <IPC signal name: IMsgCAN1_ME_SnsDat_Rear_Direct_t> rear direct echoes*/, [1]: /* <IPC signal name: IMsgCAN1_ME_SnsDat_Rear_Direct_2_t> rear direct 2 echoes */
	Rear_Indirect_1 m_Rear_Indirect_1; // not used
	Rear_Indirect_2 m_Rear_Indirect_2; // not used
	/*
    @@ SUB_STRUCTURE = m_RearSide_Echoes 
    @@ STRUCTURE = USSData_Input
    @@ DATA_TYPE = STRUCTURE RearSide_Echoes
    @@ END
    */
	RearSide_Echoes m_RearSide_Echoes; /* <IPC signal name: IMsgCAN1_ME_SnsDat_RearSide_Echoes_t> rear side echoes */ 
	Triangulated_Points TriangulatedPoints[96]; // not used
	bool_t m_fault;
	USSSectorData m_sectorZoneData;
}USSData_Input;

struct USSSectorDistances
{
	float32_t FrontDistances[6]; // Left to right  (FSL FOL FIL FIR FOR FSR)
	float32_t RearDistances[6]; // Left to right  (RSL ROL RIL RIR ROR RSR)
};

typedef struct 
{
	/*
	@@ ELEMENT = m_SetUSSParkingMode
	@@ STRUCTURE = USSData_Output
	@@ A2L_TYPE = PARAMETER
	@@ DATA_TYPE = UBYTE
	@@ END
	*/
	ParkingMode m_SetUSSParkingMode;
	USSSectorData m_sectorZoneData;
	USSSectorDistances m_sectorZoneDist;
}USSData_Output;

#endif 
