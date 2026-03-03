# L2H4060 (Stellantis) Project
----------------------------------

In SSM module, if there are any changes made in below list of data items, Autosar spreadsheets
need to be updated and generated new arxml files (in sw\bookshelf\SSM\asr folder). Once the 
arxml files are generated, autosar files has to be generated from that and integrated into the main line.

List of data items:
1. Enumerations in SSM_ApplicationStatus type

2. List of Applications in SSM_MCU_1_0_Applications enumerated type
3. List of Applications in SSM_MCU_2_0_Applications enumerated type
4. List of Applications in SSM_MCU_2_1_Applications enumerated type
5. List of Applications in SSM_MCU_QNX_Applications enumerated 

6. Declaration of the structure SSM_1_0_CoreStatus_i
7. Declaration of the structure SSM_2_0_CoreStatus_i
8. Declaration of the structure SSM_QNX_CoreStatus_i

9. Declaration of the structure SSM_SystemState_i



