#ifndef DLT_ENV_H_
#define DLT_ENV_H_

/* --- Public Typedefinitions, Enumerations, Defines ------------------------------- */

/* Some QACPP/C++-rules cannot be followed, because the header is used for both C and C++,
 * hence the following rules are deactivated: */
/* PRQA S 1026 EOF */ /* Macro may be used as a constant expression */
/* PRQA S 2000 EOF */ /* functions in the global scope */
/* PRQA S 2400 EOF */ /* functions in global namespace */

/* PRQA S 1052 EOF */ /* This file contains some commented out compiler switches by design */

/* QA-C */
/* PRQA S 3205 EOF */  /* Suppressed QAC warning, identifiers provided for other DLT modules */
/* PRQA S 3210 EOF */  /* Suppressed QAC warning, functions provided for other DLT modules */
/* PRQA S 3447 EOF */  /* Suppressed QAC warning, functions are declared in a header file */
/* PRQA S 3448 EOF */  /* Suppressed QAC warning, type definitions are declared in a header file */


/* define string type */
#include <platform/PlatformSpecs.h>
#include "dlt_cfg.h"
#include <stdint.h>

#ifndef s8
  typedef sint8_t  s8;
#endif

#ifndef u8
  typedef uint8_t u8;
#endif

#ifndef s16
  typedef sint16_t s16;
#endif

#ifndef u16
  typedef uint16_t u16;
#endif

/* TODO - ugl - #ifndef s32
  typedef sint32_t s32;
#endif */

/* TODO - ugl workaround for sint32 see above - */
#ifndef s32
  typedef int32_t s32;
#endif

#ifndef u32
  typedef uint32_t u32;
#endif

/* TODO - ugl already defined in MeclTypes.h - #ifndef char_t
   typedef char char_t;
#endif */

#if defined(_MSC_VER) || defined(_GOOGLE_TEST_BUILD) || defined(__MINGW32__)
#ifdef BOOL
#undef BOOL
#endif
typedef int BOOL;
#else
typedef u8 BOOL;
#endif

/* TODO - ugl multi declaration see SigM - #ifndef Std_ReturnType
typedef uint8_t Std_ReturnType;
#endif */

/* TODO - ugl workaround for Std_ReturnType see above - */
typedef uint8_t DltStd_ReturnType;

#ifndef string
  typedef const char* string;
#endif

  /* -------------------------------------------------------------------------- */
  /**
   * 8.1.1 PduIdType - [SWS_COMTYPE_00005]
   *
   * This type is used within the entire AUTOSAR Com Stack except for bus drivers.
   */
#ifndef sPdu_s_Id_t
  typedef u8  sPdu_s_Id_t;
#endif

  /* possible states for the pdu
     because of the limitations of the buffer pool implementation
     de-allocating memory may temporarily fail. In this case the pdu is
     marked obsolete. Function sPdu_F_RelObsolete_v will try to
     free obsolete PDUs.

       Free:  can be allocated
       Alloc: in use by the software
       Obsolete: marked to be freed
   */

/* TODO - ugl multi declaration see SigM - typedef enum sPdu_e_PduState_e
  {
     sPdu_e_PDU_UNUSED = 0,
     sPdu_e_PDU_IN_USE,
     sPdu_e_PDU_OBSOLETE
  } sPdu_e_PduState_t; */

/* TODO - ugl workaround for sPdu_e_PduState_e see above */
  typedef enum sDltPdu_e_PduState_e
  {
     sDltPdu_e_PDU_UNUSED = 0,
     sDltPdu_e_PDU_IN_USE,
     sDltPdu_e_PDU_OBSOLETE
  } sDltPdu_e_PduState_t;


  /* the pdu structure
     PDUs are used to keep track of messages.
  */

/* TODO - ugl multi declaration see SigM - #ifndef sPdu_s_PduInfo_t
  typedef struct sPdu_s_PduInfo_s
  { */
    /* data needed for the interface to buffers */
    /*u8 *PduData_pu8; */       /* pointer to the memory block */
    /* u16 PduSize_u16; */      /* size of the memory block */
    /*u8  BufPool_u8; */    /* pool containing the memory block */
    /*sPdu_e_PduState_t  PduStatus_e; */     /* pdu status */
    /*sPdu_s_Id_t PduId_t; */   /* self referencing PDU ID to build id from pointer */
    /* data needed by the transport layer */
    /*u8 IsoTpChannel_u8; */   /* the communication channel */
    /*u16 IsoTpDataLen_u16;*/  /* the length of used data */
    /* queuing */
    /*struct sPdu_s_PduInfo_s *NextPdu_ps;
  } sPdu_s_PduInfo_t;
#endif */

 /* TODO - ugl workaround for sPdu_s_PduInfo_s see above */
  typedef struct sDltPdu_s_PduInfo_s
  {
    /* data needed for the interface to buffers */
    u8 *PduData_pu8;       /* pointer to the memory block */
    u16 PduSize_u16;       /* size of the memory block */
    u8  BufPool_u8;        /* pool containing the memory block */
    sDltPdu_e_PduState_t  PduStatus_e;      /* pdu status */
    sPdu_s_Id_t PduId_t;    /* self referencing PDU ID to build id from pointer */
    /* data needed by the transport layer */
    u8 IsoTpChannel_u8;    /* the communication channel */
    u16 IsoTpDataLen_u16;  /* the length of used data */
    /* queuing */
    struct sDltPdu_s_PduInfo_s *NextPdu_ps;
  } sDltPdu_s_PduInfo_t;


/* defines which should provided by the environment */
typedef u8 sDem_s_EventId_t;
typedef u8 sDem_s_UdsStatusByte_t;
typedef u8 sDcm_s_RoeState_t;
typedef u8 sDcm_s_OpStatus_t;
typedef u8 sDcm_s_NegativeResponseCode_t;
typedef u8 RetryInfoType_t;
typedef u8 BufReq_ReturnType_t;
typedef u8 sGpt_s_Channel_t;
typedef u8 sGpt_s_Value_t;

/**
 * 8.3.3  Dlt_SessionIDType - [SWS_Dlt_00225]
 * This type describes the Session ID - is platform depended,
 * can be set individually (possible values are u8, u16 and u32)
 */
typedef u32 sDlt_s_SessionId_t;

/**
 * 8.3.4  Dlt_ApplicationIDType - [SWS_Dlt_00226]
 * This type describes the Application ID - is platform depended, can be set individual
 */
typedef u32 sDlt_s_ApplicationId_t;

/**
 * 8.3.5  Dlt_ContextIDType - [SWS_Dlt_00227]
 * This type describe the Context ID - is platform depended, can be set individual
 */
typedef u32  sDlt_s_ContextId_t;

/**
 *
 * This type describe the Timestamp for a specific dlt message
 */
typedef u32  sDlt_s_Timestamp_t;

/**
 * 8.3.6  Dlt_MessageIDType - [SWS_Dlt_00228]
 * contains the unique Message ID for a message - is platform depended, can be set individual
 */
typedef u8  sDlt_s_MessageId_t;

/* -------------------------------------------------------------------------- */

#ifndef FALSE
#define FALSE (0U)
#endif
#ifndef TRUE
#define TRUE (1U)
#endif

#ifndef E_OK
#define E_OK (0U)
#endif
#ifndef E_NOT_OK
#define E_NOT_OK (1U)
#endif


#ifndef STD_ON
#define STD_ON TRUE
#endif

#ifndef STD_OFF
#define STD_OFF FALSE
#endif

/* -------------------------------------------------------------------------- */
/* configuration of DLT behavior */

/* TODO - ugl 8.1.2 and 8.1.3 move to dltpdu.c/.h ? */

/**
 * 8.1.2 PduLengthType - [SWS_COMTYPE_00008]
 *
 * This type shall be used within the entire AUTOSAR Com Stack of an ECU except for bus drivers.
 */
#if (sPdu_D_PDU_LENGTH_MAX < (0xFFU + 1U))
typedef u8  sDltPdu_s_Length_t;
#elif (sPdu_D_PDU_LENGTH_MAX < (0xFFFFU + 1U))
typedef u16 sDltPdu_s_Length_t;
#elif (sPdu_D_PDU_LENGTH_MAX < (0xFFFFFFFFu + 1U))
typedef u32 sDltPdu_s_Length_t;
#else
#error symbol sPdu_D_PDU_LENGTH_MAX is out of bounds
#endif

/**
 * 8.1.3 PduInfoType - [SWS_COMTYPE_00011]
 *
 * Variables of this type shall be used to store the basic information about a PDU of
 * any type,  namely  a  pointer  variable  pointing  to  its  SDU  (payload),  and
 * the corresponding length of the SDU in bytes.
 */
typedef struct sDltPdu_s_Info_s
{
  u8 *                SduDataPrt_pu8;
  sDltPdu_s_Length_t  SduLength_t;
} sDltPdu_s_Info_t;

/* --- Public Function Declarations ------------------------------------------------ */
extern void sDltEnv_Memset_v(void* i_Dest_pv, s16 i_Value_u8, u16 i_Size_u16);

extern u16 sDltEnv_Strlen_u16(const char_t* i_Name_pc);

extern void sDltEnv_MemCpy_v(void* i_Dest_pv, const void* i_Src_pv, u16 i_Size_u16);

/* --------------------------------------------------------------------------------- */
#endif /* DLT_ENV_H_ */

/* --------------------------------------------------------------------------------- */
/* END OF FILE: dlt_env.h */
