#ifndef SIGNALMGR_BASE_H_NAME
#define SIGNALMGR_BASE_H_NAME

#include "SignalMgr.cfg"
#include "SignalMgrTypes.h"
#include <string.h>


#if SIGNALMGR_CFG_RTOS == SIGNALMGR_CFG_RTOS_TIRTOS

	#include <ti/sysbios/knl/Semaphore.h>
	#include <ti/sysbios/BIOS.h>
	#include <xdc/runtime/Error.h>
	#include <xdc/runtime/System.h>

#elif SIGNALMGR_CFG_RTOS == SIGNALMGR_CFG_RTOS_FREERTOS
	#include <ti/osal/osal.h>
#endif

#if SIGNALMGR_CFG_RTOS  == SIGNALMGR_CFG_RTOS_FREERTOS
	#if !defined(BUILD_MCU2_0) && !defined(BUILD_MCU2_1)
		#include <app_log.h>
		#define SIGMGR_GETLOCALTIMESTAMP_PROVIDER   appLogGetTimeInUsec()
	#else
		//Need to fix later
		#define SIGMGR_GETLOCALTIMESTAMP_PROVIDER   (0)
	#endif
#endif


namespace SignalMgr
{


	template<class dtype>
	class SignalMgr_BareIf
	{

	protected:
		SignalMgr_MetaData m_SignalMetaData;

	public:

		virtual bool_t Set(dtype *data)
		{
			m_SignalMetaData.FreshnessCount+=1;
			m_SignalMetaData.LastUpdatedTimeStamp=SIGMGR_GETLOCALTIMESTAMP_PROVIDER;

			return TRUE;
		}

		virtual SignalMgr_MetaData Get_MetaData()
		{
			return m_SignalMetaData;
		}

		virtual bool_t Init(const char* uid_name, const dtype* InitVal,bool_t ZeroMemory)
		{
			bool_t bRet = TRUE;

			m_SignalMetaData.FreshnessCount=0;
			m_SignalMetaData.LastUpdatedTimeStamp=0;

			return bRet;
		}

		virtual bool_t Init(const char* uid_name)
		{
			bool_t bRet = TRUE;
			return bRet;
		}
	};

	template <class dtype, unsigned int CallbackQueueSize>
	class SignalMgr_Notifier : public SignalMgr_BareIf<dtype>
	{
		void ( *m_Callback[CallbackQueueSize])(const dtype * const);
		uint8_t m_CallbackQueueCurrIndex;

	public:



		SignalMgr_Notifier()
		{
			m_CallbackQueueCurrIndex = 0;
		}

		~SignalMgr_Notifier()
		{

		}

		bool_t RegisterCallback(void ( *Callback)(const dtype * const))
		{
			bool_t bRet = FALSE;
			bool_t bFound = FALSE;

			for (unsigned int i = 0; i < m_CallbackQueueCurrIndex; i++)
			{
				if ((i < m_CallbackQueueCurrIndex) && (m_Callback[i] == Callback))
				{
					//ignore: adding the same callback again
					bFound=true;
					break;
				}
			}

			//Todo: Get a semaphore!
			//Critical Section
			if(bFound == FALSE)
			{
				if (m_CallbackQueueCurrIndex < CallbackQueueSize)
				{
					m_Callback[m_CallbackQueueCurrIndex] = Callback;
					m_CallbackQueueCurrIndex++;
					bRet = TRUE;
				}
			}
			//End Critical Section

			return bRet;
		}

		virtual bool_t Set(dtype *data)
		{
			bool_t bRet = TRUE;

			bRet &=SignalMgr_BareIf<dtype>::Set(data);

			for (unsigned int i = 0; i < m_CallbackQueueCurrIndex; i++)
			{
				if (m_Callback[i] != nullptr)
				{
					m_Callback[i](data);
				}

			}

			return bRet;
		}
	};





	template <class dtype>
	class SignalMgr_BasicData : public SignalMgr_BareIf<dtype>
	{

	protected:
		dtype m_Data;

	public:


		SignalMgr_BasicData()
		{

		}

		~SignalMgr_BasicData()
		{
			// no dynamic allocation hence nothing to free
		}

		virtual bool_t Set(dtype* data)
		{
			bool_t bRet = TRUE;

			bRet &=SignalMgr_BareIf<dtype>::Set(data);
			memcpy(&m_Data, data, sizeof(m_Data));
			return bRet;
		}

		void Get(dtype* data)
		{
			memcpy(data, &m_Data, sizeof(m_Data));
		}

		dtype* GetDataObjRef()
		{
			return &m_Data;
		}

		virtual bool_t Init(const char* uid_name)
		{
			return Init(uid_name,NULL,TRUE);
		}

		virtual bool_t Init(const char* uid_name, const dtype* InitVal,bool_t ZeroMemory)
		{
			bool_t bRet = TRUE;

			bRet &= SignalMgr_BareIf<dtype>::Init(uid_name);
			if ((InitVal == NULL) || (ZeroMemory == TRUE))
			{
				memset(&m_Data, 0, sizeof(m_Data));
			}
			else
			{
				memcpy(&m_Data, (const void *)InitVal, sizeof(m_Data));
			}

			return bRet;
		}


	};

	template <class dtype, unsigned int CallbackQueueSize>
	class SignalMgr_BasicData_WithNotifier : public SignalMgr_BasicData<dtype>, public SignalMgr_Notifier<dtype, CallbackQueueSize>
	{
	public:
		virtual bool_t Set(dtype* data)
		{
			bool_t bRet = TRUE;
			bRet &= SignalMgr_BasicData<dtype>::Set(data);
			if (bRet == TRUE)
			{
				bRet &= SignalMgr_Notifier<dtype, CallbackQueueSize>::Set(&this->m_Data);
			}
			return bRet;
		}

		virtual bool_t Init(const char* uid_name, const dtype* InitVal, bool_t ZeroMemory)
		{
			bool_t bRet = TRUE;

			bRet &= SignalMgr_BasicData<dtype>::Init(uid_name, InitVal, ZeroMemory);
			bRet &= SignalMgr_Notifier<dtype,CallbackQueueSize>::Init(uid_name);

			return bRet;
		}

		virtual bool_t Init(const char* uid_name)
		{
			return Init(uid_name,NULL,TRUE);
		}

	};



	template <class dtype>
	class SignalMgr_ProtectedData : public SignalMgr_BasicData<dtype>
	{
	private:
		bool_t bSemCreated;

	#if SIGNALMGR_CFG_RTOS == SIGNALMGR_CFG_RTOS_TIRTOS
		Semaphore_Struct SemStruct;
		Semaphore_Params SemParams;
		Semaphore_Handle m_Sem;
	#elif SIGNALMGR_CFG_RTOS == SIGNALMGR_CFG_RTOS_FREERTOS
		SemaphoreP_Params SemParams;
		SemaphoreP_Handle m_Sem;
	#endif
	public:
		SignalMgr_ProtectedData()
		{
			bSemCreated=FALSE;

		}

		~SignalMgr_ProtectedData()
		{
			if(bSemCreated == TRUE)
			{
				#if SIGNALMGR_CFG_RTOS == SIGNALMGR_CFG_RTOS_FREERTOS
				//Semaphore_delete(&m_Sem);
				#endif
			}
		}


		bool_t lock()
		{
			bool_t Ret = TRUE;

			//OS Api to lock
			#if SIGNALMGR_CFG_RTOS == SIGNALMGR_CFG_RTOS_FREERTOS
			if(bSemCreated == TRUE)
			{
				(void)SemaphoreP_pend(m_Sem, SemaphoreP_WAIT_FOREVER);
			}
			#endif
			return Ret;
		}


		bool_t unlock()
		{
			bool_t Ret = TRUE;
			//Os Api to unlock
			#if SIGNALMGR_CFG_RTOS == SIGNALMGR_CFG_RTOS_FREERTOS
			if(bSemCreated == TRUE)
			{
				SemaphoreP_post(m_Sem);
			}
			#endif

			return Ret;
		}

		virtual bool_t Init(const char* uid_name)
		{
			return Init(uid_name,NULL,TRUE);
		}

		virtual bool_t Init(const char* uid_name, const dtype* InitVal, bool_t ZeroMemory)
		{
			bool_t bRet = TRUE;

			//Create a semaphore from uuid

			#if SIGNALMGR_CFG_RTOS == SIGNALMGR_CFG_RTOS_TIRTOS

			Semaphore_Params_init(&SemParams);
			SemParams.mode = Semaphore_Mode_BINARY;
			Semaphore_construct(&SemStruct, 1, &SemParams);
			m_Sem=SemaphoreP_handle(&SemStruct);
			bSemCreated = TRUE;

			#elif SIGNALMGR_CFG_RTOS == SIGNALMGR_CFG_RTOS_FREERTOS
			/* Default parameter initialization */
			SemaphoreP_Params_init(&SemParams);
			SemParams.mode = SemaphoreP_Mode_BINARY;			
			/* create the semaphore block */
			m_Sem= SemaphoreP_create(1, &SemParams);
			if (m_Sem == (SemaphoreP_Handle) NULL)
			{
				bSemCreated = FALSE;
			}
			else
			{
				bSemCreated = TRUE;
			}
			#endif

			bRet &= SignalMgr_BasicData<dtype>::Init(uid_name, InitVal, ZeroMemory);

			return bRet;
		}

		virtual bool_t Set(dtype* data)
		{
			bool_t Ret=TRUE;
			Ret&=lock();
			if (Ret == TRUE)
			{
				Ret &= SignalMgr_BasicData<dtype>::Set(data);
				Ret &= unlock();
			}
			return Ret;
		}

	};

	template <class dtype, unsigned int CallbackQueueSize>
	class SignalMgr_ProtectedData_WithNotifier : public SignalMgr_ProtectedData<dtype>, public SignalMgr_Notifier<dtype, CallbackQueueSize>
	{
	public:
		virtual bool_t Set(dtype* data)
		{
			bool_t bRet = TRUE;
			bRet &= SignalMgr_ProtectedData<dtype>::lock();
			if (bRet == TRUE)
			{
				bRet &= SignalMgr_BasicData<dtype>::Set(data);
				if (bRet == TRUE)
				{
					bRet &= SignalMgr_Notifier<dtype, CallbackQueueSize>::Set(&this->m_Data);
				}
				bRet &= SignalMgr_ProtectedData<dtype>::unlock();
			}
			return bRet;
		}

		virtual bool_t Init(const char* uid_name, const dtype* InitVal, bool_t ZeroMemory)
		{
			bool_t bRet = TRUE;

			bRet &= SignalMgr_ProtectedData<dtype>::Init(uid_name, InitVal, ZeroMemory);
			bRet &= SignalMgr_Notifier<dtype, CallbackQueueSize>::Init(uid_name);

			return bRet;
		}

		virtual bool_t Init(const char* uid_name)
		{
			return Init(uid_name,NULL,TRUE);
		}



	};
}





#endif
