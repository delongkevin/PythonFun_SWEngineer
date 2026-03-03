

#if defined(BUILD_MCU2_0) || defined (BUILD_MCU2_1)
#include "ApplicationTasks.h"
#include "BaseSwTasks.h"
#endif
#if defined (BUILD_MCU2_1)
#include "SafetyTasks.h"
#endif

#ifdef ADDRUNTIMESTATS
#if defined (BUILD_MCU2_1) || defined (BUILD_MCU2_0)
  typedef enum
 {
	#if defined (BUILD_MCU2_1)
	s_Task_APP_B_10msec,    	
	s_TasK_APP_QM_10msec,     
	s_Task_SAFETY_APP_50msec, 
	s_TasK_SAFETY_BSW_10msec, 
	s_Task_BSW_B_Idle,	      
	s_Task_BSW_B_1msec,     	
	s_Task_BSW_B_10msec,      
	s_TasK_BSW_QM_10msec,   	
	s_TasK_BSW_QM1_10msec,  	
	s_Task_en_TasK_BSW_QM_HighPriority_OnEvent,
	#endif
	#if defined (BUILD_MCU2_0)
 	s_Task_APP_B_10msec,   	
	s_TasK_APP_QM_10msec,    	
	s_Task_APP_B_30msec,   	
	s_Task_BSW_B_10msec, 		
	s_TasK_BSW_QM_10msec,		
	s_TasK_BSW_QM1_10msec,     
	s_Task_en_TasK_BSW_QM_HighPriority_OnEvent,
	s_TasK_BSW_QM_TI_100msec,  
	#endif
	s_TASK_MAX,
 }TaskIndex;
 typedef struct
 {
  TaskIndex Task_ID;
  uint32_t Task_LowAdd;
  uint32_t Task_HighAdd;
  uint32_t Task_Size;
 }StackUsage_Task;
 
 extern volatile StackUsage_Task TaskStackData[s_TASK_MAX]; 

 #endif
 #endif

/*****************************Function decleartion*************************************/
#ifdef ADDRUNTIMESTATS
#if defined (BUILD_MCU2_1) || defined (BUILD_MCU2_0)
void RunTimeStatsData_SendData(void);
void AddRuntimeStats_StackUsage(void);
#endif 
#endif

#if defined (BUILD_MCU2_1)
#ifdef ADDRUNTIMESTATS
void RunTimeStats_BswSafety_Stop_Task(en_SAFETY_Tasks_Def taskId);
void RunTimeStats_BswSafety_Start_Task(en_SAFETY_Tasks_Def taskId);
void RunTimeStats_AppSafety_Stop_Task(en_SAFETY_Tasks_Def taskId);
void RunTimeStats_AppSafety_Start_Task(en_SAFETY_Tasks_Def taskId);
#endif 
#endif

#if defined(BUILD_MCU2_0) || defined (BUILD_MCU2_1)
#ifdef ADDRUNTIMESTATS
void RunTimeStats_APP_Stop_Task(en_APP_Tasks_Def taskId);
void RunTimeStats_APP_Start_Task(en_APP_Tasks_Def taskId);
void RunTimeStats_BSW_Stop_Task(en_BSW_Tasks_Def taskId);
void RunTimeStats_BSW_Start_Task(en_BSW_Tasks_Def taskId);
#endif 
#endif