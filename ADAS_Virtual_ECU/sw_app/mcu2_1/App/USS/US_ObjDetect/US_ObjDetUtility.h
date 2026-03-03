/*
 * US_ObjDetUtility.h
 *
 *  Created on: Sep 13, 2021
 *      Author: jonapais
 */

#ifndef US_OBJDETUTILITY_H_
#define US_OBJDETUTILITY_H_

void UssOD_SortPointsByConfidence(US_S_SnrPoint_t *psSnrPntGrp_,
                                  uint8_t * puGrpSnrPntSortIdx_,
                                  uint8_t uLowIdx,
                                  uint8_t uNumPoints);

#endif /* US_OBJDETUTILITY_H_ */
