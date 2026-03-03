/*
 * US_ObjDetUtility.c
 *
 *  Created on: Sep 8, 2021
 *      Author: jonapais
 */
/*PRQA S 0816 ++ */
/*PRQA S 1011, 0857, 0776, 0604 ++ */
/* PRQA S 1852 ++ */ /* Signed or unsigned has no impact */
/* PRQA S 1860 ++ */ /* Generated value is og unsigned type*/
/* PRQA S 4434 ++ */ /*Conversion has no impact */
/* PRQA S 0292 ++ */ /*Special characters in comments have no functional impact */

#include "US_ME_Typedefs_Global.h"
#include "US_ObjDetTriang.h"
#include "US_ObjDet_Global.h"
#include "US_ObjDetUtility.h"

static uint8_t * puGrpSnrPntSortIdx;
static US_S_SnrPoint_t * psSnrPntGrp;

static void UssOD_QuickSortSwap(uint8_t* a, uint8_t* b);
static uint8_t UssOD_PartitionSortArray(uint8_t uLowIdx, uint8_t uHighIdx);

/*===========================================================================
 * brief An iterative implementation of quick sort to sort point map by confidence level.
 *
 * \param uint8_t uGrpIdx  Group index.
 * \param uint8_t uLowIdx  Lowest index to sort
 * \param uint8_t uHighIdx Num of points to sort, starting at the lowest idx
 * \return uint8_t Partition index
 * \remarks Modified version of www.geeksforgeeks.org/c-program-for-iterative-quick-sort/
 *          MIT License allows modification and distribution of adapted SW, for profit,
 *          for the software to increase the art of the possible.
 */
/* ===========================================================================
 * Name:	 UssOD_SortPointsByConfidence
 * Remarks:  DD-ID: {1328EAA1-BB53-406c-BC8D-F105863400E4}
 * Req.-ID: 13420481
 * ===========================================================================*/
void UssOD_SortPointsByConfidence(US_S_SnrPoint_t *psSnrPntGrp_,
                                  uint8_t * puGrpSnrPntSortIdx_,
                                  uint8_t uLowIdx,
                                  uint8_t uNumPoints)
{
    if ((uNumPoints >= TWO)
        && (uNumPoints <= US_D_POINT_BUFFER_SIZE))
    {
        uint8_t uHighIdx = uLowIdx + uNumPoints - ONE;
#if 0
        puGrpSnrPntSortIdx = UssOD_sGetSnrPntSortIdxList(uGrpIdx);
        psSnrPntGrp = UssOD_sGetSnrPntBuff(uGrpIdx);
#endif
        puGrpSnrPntSortIdx = puGrpSnrPntSortIdx_;
        psSnrPntGrp = psSnrPntGrp_;

        // Create an auxiliary stack
#if 0
        uint8_t uSortStack[uHighIdx - uLowIdx + 1]; // Considered dynamic array.  Not allowed by some embedded compilers.
#endif
        uint8_t uSortStack[US_D_POINT_BUFFER_SIZE + THREE];  // Use max fixed length array instead.

        /* initialize top of stack */
        sint8_t iStackTop = 1;

        /* push initial values of l and h to stack*/
        uSortStack[ZERO] = uLowIdx;
        uSortStack[ONE] = uHighIdx;

        // Keep popping from stack while is not empty
        while (iStackTop >= 0)
        {
            // Pop h and l
            if (iStackTop >= 1)
            {
                uHighIdx = uSortStack[iStackTop--];
                uLowIdx = uSortStack[iStackTop--];
            }
            // Set pivot element at its correct position
            // in sorted array
            uint8_t uPartIdx = UssOD_PartitionSortArray(uLowIdx, uHighIdx);

            // If there are elements on left side of pivot,
            // then push left side to stack
            if (uPartIdx - 1 > uLowIdx)
            {
                if (iStackTop < (int8_t)US_D_POINT_BUFFER_SIZE - 2)
                {
                    uSortStack[++iStackTop] = uLowIdx;
                    uSortStack[++iStackTop] = uPartIdx - 1;
                }
            }

            // If there are elements on right side of pivot,
            // then push right side to stack
            if (uPartIdx + 1 < uHighIdx)
            {
                if (iStackTop < (int8_t)US_D_POINT_BUFFER_SIZE - 2)
                {
                    uSortStack[++iStackTop] = uPartIdx + 1;
                    uSortStack[++iStackTop] = uHighIdx;
                }
            }
        }
    }
}

/*===========================================================================
 * \brief An iterative implementation of quick sort - Array partition
 *
 * \param uint8_t uLowIdxb
 * \param uint8_t uHighIdx
 * \return uint8_t Partition index
 * \remarks
 */
/* ===========================================================================
 * Name:	 UssOD_PartitionSortArray
 * Remarks:  DD-ID: {CBB51E83-FAE1-4abb-8965-651E7E0A985D}
 * ===========================================================================*/
static uint8_t UssOD_PartitionSortArray(uint8_t uLowIdx, uint8_t uHighIdx)
{
    uint8_t uCompIdx = puGrpSnrPntSortIdx[uHighIdx];
    sint8_t i = (uLowIdx - 1); /* PRQA S 4460 */ /*Conversion has no impact */
    sint8_t j;

    for (j = (sint8_t) uLowIdx; j <= uHighIdx - 1; j++)
    {
        /* COMPARISON AND SWAP FUNCTION */
#if 1
        if (psSnrPntGrp[puGrpSnrPntSortIdx[j]].uConf > psSnrPntGrp[uCompIdx].uConf)
        {
            i++;
            UssOD_QuickSortSwap(&puGrpSnrPntSortIdx[i], &puGrpSnrPntSortIdx[j]);
        }
#endif
#if 0
        test1 = psSnrPntGrp[uPartPntIdxList[j]].uConf << 8 |uPartPntIdxList[j];
        test2 = psSnrPntGrp[uCompIdx].uConf | uCompIdx;

        if (test1 > test2)
        {
            i++;
            UssOD_QuickSortSwap(&uPartPntIdxList[i], &uPartPntIdxList[j]);
        }
#endif
#if 0

        if (uPartPntIdxList[j] <= uCompIdx)
        {
            i++;
            UssOD_QuickSortSwap(&uPartPntIdxList[i], &uPartPntIdxList[j]);
        }
#endif
        /* END COMPARISON AND SWAP FUNCTION */
    }
    UssOD_QuickSortSwap(&puGrpSnrPntSortIdx[i + 1], &puGrpSnrPntSortIdx[uHighIdx]);
    return (i + 1);
}

/*===========================================================================
 * \brief An iterative implementation of quick sort - Element Swap
 *
 * \param uint8_t* a
 * \param uint8_t* b
 * \return none
 * \remarks Swaps uint8_t pointed to by a, b
 */
/* ===========================================================================
 * Name:	 UssOD_QuickSortSwap
 * Remarks:  DD-ID: {644F004D-242A-487c-A5D2-99CD9E9B7592}
 * ===========================================================================*/
static void UssOD_QuickSortSwap(uint8_t* a, uint8_t* b)
{
    uint8_t t = *a;
    *a = *b;
    *b = t;
}



