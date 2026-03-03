#include "JobKM.h"
#include "KM.h"
#include "DataProviderKM.h"



#ifdef __cplusplus
extern "C" {
#endif

using namespace KM;

static KM::DataProviderKM m_KMDataProvider;
static KM::JobKM m_KMJob((IDataProviderKM *)&m_KMDataProvider);

void KM_Init()
{
  m_KMJob.onInit_b();
}


void KM_Run()
{
  m_KMJob.onRun_b();
}



#ifdef __cplusplus
}
#endif
