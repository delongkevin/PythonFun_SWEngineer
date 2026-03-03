/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           algo_defaults.h
 *  @brief
 *
 *  @version        3.31
 *  @author         Mikhail Vakhrushev
 *  @date           10.04.2020
 *
 * =========================================================================
 *
 *  @par          Change History:
 *
 * ========================================================================= */

/* PRQA S 1055 ++ */
/* PRQA S 3412 ++ */
/* PRQA S 0842 ++ */
/* PRQA S 0342 ++ */

#ifndef ALGO_DEFAULT_H
#define ALGO_DEFAULT_H

#include "parameters_storage.h"

#define ALGO_IMPL(NAME) extern void NAME##_defaults(parameters_storage_t* s);
#include"algo_reg.h"

static inline void algo_defaults(parameters_storage_t* s)
{
    #define ALGO_IMPL(NAME) NAME##_defaults(s);
    #include"algo_reg.h"
}

#endif //ALGO_DEFAULT_H
/* PRQA S 1055 -- */
/* PRQA S 3412 -- */
/* PRQA S 0842 -- */
/* PRQA S 0342 -- */

