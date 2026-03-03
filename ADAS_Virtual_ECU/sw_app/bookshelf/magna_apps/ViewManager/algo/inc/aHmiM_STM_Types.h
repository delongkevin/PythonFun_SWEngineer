/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:   aHmiM_STM_Types
 * DESIGN:  Fries S.
 * DESCRIPTION:
 *    Normal Operation Sub State Machine for the aHmiM Module
 * ======================================================================== */


#ifndef AHMIM_STM_TYPES_H_
#define AHMIM_STM_TYPES_H_


/* ######################################################################################################
 * --- HEADER VERSION ---
 * ###################################################################################################### */
#define AHMIM_STM_TYPES_D_VERSION_ID_H "$Id: aHmiM_STM_Types.h 1.1.3.1 2021/04/05 22:25:13IST Gopinath Ramanathan (gopirama) Draft  $"
/* ------------------------------------------------------------------------------------------------------ */


/* ######################################################################################################
 * --- global typedef ENUMs ---
 * ###################################################################################################### */
#define aHmiM_STM_D_NO_ERROR                  0x00U
#define aHmiM_STM_D_INPUT_ERROR               0x01U
#define aHmiM_STM_D_SIZE_ERROR                0x02U
#define aHmiM_STM_D_INTERNAL_IDX_ERROR        0x10U
#define aHmiM_STM_D_POINTER_ERROR             0x20u
/* ------------------------------------------------------------------------------------------------------ */


/* ######################################################################################################
 * --- global typedef ENUMs ---
 * ###################################################################################################### */
typedef u8 aHmiM_STM_Error_t;                  /* create special error type */
/* ------------------------------------------------------------------------------------------------------ */


#if defined(AHMIM_STM_C_) || defined(AHMIM_STM_CFG_C_)
  /* ######################################################################################################
   * --- module global SUB macros // take with care // HANDS OFF!!! ---
   * ###################################################################################################### */
  #define aHmiM_STM_D_ARRAY_SIZE(ARRAY)                                     (sizeof(ARRAY)/sizeof(ARRAY[0]))
  /* --- (internal do not modify) declare fx enum element name --- */
  #define aHmiM_STM_D_DECLARE_FX_ENUM_ITEM_NAME(STATE_ENUM,FX_NAME)         aHmiM_STM_e_##STATE_ENUM##FX_NAME
  /* --- (internal do not modify) declare fx list name --- */
  #define aHmiM_STM_D_DECLARE_FX_LIST_NAME(STATE_ENUM)                      aHmiM_STM_c_FX_LIST##STATE_ENUM
  /* --- (internal do not modify) declare state list name --- */
  #define aHmiM_STM_D_DECLARE_STATE_LIST_NAME(STATE_ENUM)                   aHmiM_STM_c_ST_LIST##STATE_ENUM

  /* ------------------------------------------------------------------------------------------------------ */
  /* --- define unique fx item on the special position in a fx list [source: aHmiM_STM_FX_Condition_pbf] --- */
  /* ------------------------------------------------------------------------------------------------------ */
  /*  STATE_ENUM  : an element from the enumeration list "aHmiM_STM_E_StateMachineList_t" (source: hmimgr_cfg.h)
      FX_NAME     : a name of the function which should be placed in the array list "FX_ITEM_ARRAY" at already defined index position
    ------------------------------------------------------------------------------------------------------ */
  #define aHmiM_STM_D_DEFINE_FX_ITEM(STATE_ENUM,FX_NAME)                                                \
          [aHmiM_STM_D_DECLARE_FX_ENUM_ITEM_NAME(STATE_ENUM,FX_NAME)]=FX_NAME
//Removed braces due to Porting
  /* ------------------------------------------------------------------------------------------------------ */
  /* --- define unique fx enum item on the special position in a fx list [source: aHmiM_STM_FX_Condition_pbf] --- */
  /* ------------------------------------------------------------------------------------------------------ */
  /*  STATE_ENUM  : an element from the enumeration list "aHmiM_STM_E_StateMachineList_t" (source: hmimgr_cfg.h)
      FX_NAME     : a name of the function which should be defined as index (or bit) position.
    ------------------------------------------------------------------------------------------------------ */
  #define aHmiM_STM_D_DEFINE_FX_ENUM_ITEM                                                               \
          aHmiM_STM_D_DECLARE_FX_ENUM_ITEM_NAME

  /* ------------------------------------------------------------------------------------------------------ */
  /* --- define state condition for only one condition [source: aHmiM_STM_FX_ConditionPattern_t] --- */
  /* ------------------------------------------------------------------------------------------------------ */
  /*  STATE_ENUM  : an element from the enumeration list "aHmiM_STM_E_StateMachineList_t" (source: hmimgr_cfg.h)
      FX_NAME     : a name of the function which returns the already defined bit position
      FX_RESULT   : define return value for the function "FX_NAME" (TRUE or FALSE)  (aHmiM_STM_FX_Condition_pbf)
      FX_FILTER   : determine here if the return value (FX_RESULT) or TRUE bit should be used as a result 
                    if FX_FILTER is set to TRUE then result is always TRUE
    ------------------------------------------------------------------------------------------------------ */
  #define aHmiM_STM_D_DEFINE_STATE_CONDITION(STATE_ENUM,FX_NAME,FX_RESULT,FX_FILTER)                    \
          ((FX_FILTER ? (TRUE):(FX_RESULT)) ? (0x01UL << (aHmiM_STM_D_DECLARE_FX_ENUM_ITEM_NAME(STATE_ENUM,FX_NAME))) : 0x00UL)

  /* ------------------------------------------------------------------------------------------------------ */
  /* --- define unique st item for a st list [source: aHmiM_STM_S_StateCondition_t] --- */
  /* ------------------------------------------------------------------------------------------------------ */
  /*  NEW_STATE_ENUM        : an element from the enumeration list "aHmiM_STM_E_StateMachineList_t" (source: hmimgr_cfg.h)
      FX_CONDITION_PATTERN  : define the functions pattern here for the "NEW_STATE_ENUM" element to which should be switched if result matches.
      FX_FILTER_PATTERN     : define the AND filter pattern here which combines with FX_CONDITION_PATTERN
    ------------------------------------------------------------------------------------------------------ */
  #define aHmiM_STM_D_DEFINE_STATE_ITEM(NEW_STATE_ENUM,FX_CONDITION_PATTERN)          \
          {NEW_STATE_ENUM,FX_CONDITION_PATTERN(FALSE),FX_CONDITION_PATTERN(TRUE)}

  /* ------------------------------------------------------------------------------------------------------ */
  /* --- create unique fx enum element [source: aHmiM_STM_E_FX_EnumElement_##STATE_ENUM##FX_NAME generated automaticaly by compiler] --- */
  /* --- create unique fx list [source: aHmiM_STM_FX_Condition_pbf / generated automaticaly by compiler] --- */
  /* --- create unique st list [source: aHmiM_STM_S_StateCondition_t / generated automaticaly by compiler] --- */
  /* ------------------------------------------------------------------------------------------------------ */
  /*  STATE_ENUM        : an element from the enumeration list "aHmiM_STM_E_StateMachineList_t" (source: hmimgr_cfg.h)
      FX_ITEM_ARRAY     : entire list with functions which should be executed for the state "STATE_ENUM" only
      STATE_ITEM_ARRAY  : entire list with states which should be checked for the state "STATE_ENUM" only
    ------------------------------------------------------------------------------------------------------ */
  #define aHmiM_STM_D_CREATE_FX_LIST_EXT(STATE_ENUM,FX_ITEM_ARRAY,STATE_ITEM_ARRAY)                                                       \
          typedef enum                                                                                                                    \
          { FX_ITEM_ARRAY(STATE_ENUM,FX_ENUM_ITEM) }                                                                                      \
          aHmiM_STM_E_FX_EnumElement_##STATE_ENUM;                                                                                        \
          static const aHmiM_STM_FX_Condition_pbf aHmiM_STM_D_DECLARE_FX_LIST_NAME(STATE_ENUM)[] = {FX_ITEM_ARRAY(STATE_ENUM,FX_ITEM)};   \
          static const aHmiM_STM_S_StateCondition_t aHmiM_STM_D_DECLARE_STATE_LIST_NAME(STATE_ENUM)[] = {STATE_ITEM_ARRAY};

  /* ------------------------------------------------------------------------------------------------------ */
  /* --- define unique state description item [source: aHmiM_STM_S_StateDescriptor_t] --- */
  /* ------------------------------------------------------------------------------------------------------ */
  /*  STATE_ENUM  : an element from the enumeration list "aHmiM_STM_E_StateMachineList_t" (source: hmimgr_cfg.h)
      FX_OnStart  : a function which should be executed at first call of the new state. (NULL is valid)
      FX_OnRun    : a function which should be executed at every call of the current state. (NULL is valid)
      FX_OnStop   : a function which should be executed at last call of the current state before switch to next. (NULL is valid)
    ------------------------------------------------------------------------------------------------------ */
  #define aHmiM_STM_D_DEFINE_STATE_DESCRIPTOR_ITEM(STATE_ENUM,FX_OnStart,FX_OnRun,FX_OnStop)          \
          [STATE_ENUM]={FX_OnStart,                                                                   \
                        FX_OnRun,                                                                     \
                        FX_OnStop,                                                                    \
                        aHmiM_STM_D_DECLARE_FX_LIST_NAME(STATE_ENUM),                                 \
                        aHmiM_STM_D_DECLARE_STATE_LIST_NAME(STATE_ENUM),                              \
                        (u8)aHmiM_STM_D_ARRAY_SIZE(aHmiM_STM_D_DECLARE_FX_LIST_NAME(STATE_ENUM)),     \
                        (u8)aHmiM_STM_D_ARRAY_SIZE(aHmiM_STM_D_DECLARE_STATE_LIST_NAME(STATE_ENUM))}
  /* ------------------------------------------------------------------------------------------------------ */


  /* ######################################################################################################
   * --- module global type definitions ---
   * ###################################################################################################### */
  typedef u16 aHmiM_STM_FX_ConditionPattern_t;                         /* create special function pattern type */
  /* ------------------------------------------------------------------------------------------------------ */
  typedef BOOL (*const aHmiM_STM_FX_Condition_pbf)(aHmiM_STM_E_StateMachineList_t ST_CurrState_e);  /* create condition function type */
  typedef void   (*const aHmiM_STM_FX_Event_pf)(aHmiM_STM_E_StateMachineList_t ST_CurrState_e);     /* create event function type     */
  /* ------------------------------------------------------------------------------------------------------ */
  typedef struct  aHmiM_STM_S_StateCondition_s                          /* aHmiM_STM_D_DEFINE_STATE_ITEM(...) */
  { 
    aHmiM_STM_E_StateMachineList_t  NewState_e;                         /* new state in a big state machine */
    aHmiM_STM_FX_ConditionPattern_t FX_ConditionPattern_t;              /* FX test pattern */
    aHmiM_STM_FX_ConditionPattern_t FX_FilterPattern_t;                 /* FX AND filter pattern */
  } aHmiM_STM_S_StateCondition_t;                                       /* descriptor of a test pattern to switch to another state  */
  /* ------------------------------------------------------------------------------------------------------ */
  typedef struct  aHmiM_STM_S_StateDescriptor_e                         /* aHmiM_STM_D_DEFINE_STATE_DESCRIPTOR_ITEM(...)  */
  { 
    /* --- state event functions ---  */
    const  aHmiM_STM_FX_Event_pf          FX_OnStartEvent_pf;           /* event function on enter the new state      */
    const  aHmiM_STM_FX_Event_pf          FX_OnRunEvent_pf;             /*    -"-         on run the current state    */
    const  aHmiM_STM_FX_Event_pf          FX_OnStopEvent_pf;            /*    -"-         on stop the current state   */
    /* --- state condition functions ---  */
    const  aHmiM_STM_FX_Condition_pbf     *FX_ConditionList_pabf;       /* pointer to the list with test functions    */
    const  aHmiM_STM_S_StateCondition_t   *ST_ConditionList_pas;        /* pointer to the list with state conditions  */
              u8                          FX_ConditionListLength_u8;    /* length of the test function list */
              u8                          ST_ConditionListLength_u8;    /* length of the state machine list */
  } aHmiM_STM_S_StateDescriptor_t;
  /* ------------------------------------------------------------------------------------------------------ */
#endif  /*  AHMIM_STM_C_  ||  AHMIM_STM_CFG_C_  */


/* === End Of Header File ================================================= */
#else
//  #error Multiple include of aHmiM_STM_Types.h
//Commented due to Porting
#endif /* AHMIM_STM_TYPES_H_ */

