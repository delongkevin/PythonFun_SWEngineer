/* PRQA S 3774 ++ */
/* PRQA S 3805 ++ */
/* PRQA S 1461 ++ */
/* PRQA S 3341 ++ */
/* PRQA S 0602 ++ */
/* PRQA S 1411 ++ */
/* PRQA S 1317 ++ */
/* PRQA S 2984 ++ */

// 0)    BR, AE, NIGHT MODE, AWB
// 1)    AGAIN TABLE
// 2)    AGAIN_OUT (set up agnalog gain using info from NM and GAIN TABLES), EV_ESTIMATE
// 3)
// 4)    HISTORY SENSOR (prepare history sensor values with required delay)
// 5)    ISP_GAIN_OUT(set up ISP GAIN)
// 6)    SINTER(set up sinter using ISP gain and history sensor gain)

///0
    ALGO_IMPL(TEMPERATURE)/* PRQA S 0883 */
    ALGO_IMPL(TPG)
    ALGO_IMPL(AWB)
    ALGO_IMPL(AE)
    ALGO_IMPL(CONTROLS)
    ALGO_IMPL(MODES)
    ALGO_IMPL(AUTO_DUMP)

///2
    ALGO_IMPL(AGAIN_CONTROL)
    ALGO_IMPL(PREHDRGAIN_CONTROL)

///3
    ALGO_IMPL(PINK_SUN_COMPENSATE)
    ALGO_IMPL(EMB_LINE_TRACE)
    ALGO_IMPL(AGAIN_COMPENSATE)
    ALGO_IMPL(CCM_INTERP)

///4
    ALGO_IMPL(HISTORY_ADAPTIVE)

#ifdef MAGNA_PSA
    ALGO_IMPL(STATISTIC_UPDATE) /* PRQA S 1402 */
#endif

///5
    ALGO_IMPL(ISPGAIN_CONTROL) /* PRQA S 1402 */
    ALGO_IMPL(LTM_CONTROL) /* PRQA S 1402 */

///6
    ALGO_IMPL(EV_CALC) /* PRQA S 1402 */
    ALGO_IMPL(SINTER) /* PRQA S 1402 */
///7
    ALGO_IMPL(SATURATION) /* PRQA S 1402 */
    ALGO_IMPL(SHARPNESS) /* PRQA S 1402 */
    ALGO_IMPL(DBLC_CONTROL) /* PRQA S 1402 */



#undef ALGO_IMPL /* PRQA S 0841 */  /* PRQA S 0842 */

/* PRQA S 3774 -- */
/* PRQA S 3805 -- */
/* PRQA S 1461 -- */
/* PRQA S 3341 -- */
/* PRQA S 0602 -- */
/* PRQA S 1411 -- */
/* PRQA S 1317 -- */
/* PRQA S 2984 -- */
