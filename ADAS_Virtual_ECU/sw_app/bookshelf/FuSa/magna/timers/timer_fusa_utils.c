/*
* @Author: Pradeep Raikar
* @Date:   2023-08-24 11:20:50
* @Last Modified by:   Manatheykad, Shalhoob
* @Last Modified time: 2023-09-25 17:23:23
*/

#include "timer_fusa_utils.h"

static thresholdCounterVal gthresholdVal_5msec,gthresholdVal_1msec;
thresholdCounterVal getCurrentTaskThresholdVal_5msec(void)
{
  /* DD-ID: {C3D2758C-A7BC-4819-BDB6-A76D4A786467}*/
	
	return gthresholdVal_5msec;
}
thresholdCounterVal getCurrentTaskThresholdVal_1msec(void)
{
  /* DD-ID: {4A1C8E46-E0A2-4f6d-9385-CCBB2B626F88}*/
	return gthresholdVal_1msec;
}
void resetTaskThresholdCounterVal_5msec(void)
{
  /* DD-ID: {908F6953-B798-408b-8AB2-991DBC8A6844}*/
	gthresholdVal_5msec.max_thresholdCounter=0U;
	gthresholdVal_5msec.min_thresholdCounter=0U;
}
void resetTaskThresholdCounterVal_1msec(void)
{
  /* DD-ID: {44F7DC4F-B6AE-4fba-947C-C5E7380FBC15}*/
	gthresholdVal_1msec.max_thresholdCounter=0U;
	gthresholdVal_1msec.min_thresholdCounter=0U;
}
void updateTaskThresholdCounterVal_5msec(uint64_t val,uint64_t maxLimit,uint64_t minLimit)
{
  /* DD-ID: {A24E4219-C258-472f-8362-A0041FE40056}*/
	if(val>maxLimit)
	{
		gthresholdVal_5msec.max_thresholdCounter++;
	}
	else
	{
		gthresholdVal_5msec.max_thresholdCounter = 0;
	}

	if(val<minLimit)
	{
		gthresholdVal_5msec.min_thresholdCounter++;
	}
	else
	{
		gthresholdVal_5msec.min_thresholdCounter = 0;
	}
	
}

void updateTaskThresholdCounterVal_1msec(uint64_t val,uint64_t maxLimit,uint64_t minLimit)
{
  /* DD-ID: {120C3CA3-0C05-4f06-998C-C96D92D77F54}*/
	if(val>maxLimit)
	{
		gthresholdVal_1msec.max_thresholdCounter++;
	}
	else
	{
		gthresholdVal_1msec.max_thresholdCounter = 0;
	}

	if(val<minLimit)
	{
		gthresholdVal_1msec.min_thresholdCounter++;
	}
	else
	{
		gthresholdVal_1msec.min_thresholdCounter = 0;
	}
	
}