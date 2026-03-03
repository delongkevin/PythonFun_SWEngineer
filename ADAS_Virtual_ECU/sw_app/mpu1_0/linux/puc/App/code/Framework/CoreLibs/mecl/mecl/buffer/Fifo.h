//--------------------------------------------------------------------------
/// @file Fifo.h
/// @brief First In First Out Declarations
///
/// IDataProvider is an interface used by the algorithm to define what data
/// is actually needed. Implementation is delegated to a derived data provider
/// that is component/module specific and belongs to the framework implementation.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
///
//  --------------------------------------------------------------------------

// Empty buffer/ Free top
// Tail/Head                     
// v
// |++++++++++++++++++++++++++++++++++++++|

// Full buffer
// Tail                                   Head
// v                                      v
// |--------------------------------------|

// Free bottom
// Head           Tail
// v              v
// |++++++++++++++------------------------|


// Free mid
//                Head          Tail
//                v             v
// |--------------++++++++++++++----------|

#ifndef BUFFER_FIFO_H_
#define BUFFER_FIFO_H_

#include <platform/PlatformAPI.h>

#include "IBuffer.h"

namespace mecl
{

  namespace buffer
  {

    template<const uint32_t bufferSize_u32>
    class Fifo : public IBuffer
    {
    public:

      enum BufferState_e
      {
        e_BufferInit = 0,
        e_BufferFull,
        e_BufferNotEmpty,
        e_BufferOverflow,
        e_BufferInvalid,
        e_BufferError
      };

      struct EntryHeader_s
      {
        uint32_t entrySize_u32;
        uint32_t nextPos_u32;
      };

      static const uint32_t s_EntryHeaderSize_u32 = sizeof(EntryHeader_s);

    public:

      Fifo()
        : IBuffer()
        , writePos_u32(0U)
        , readPos_u32(0U)
        , lastEntryPos_u32(0U)
        , numOfEntries_u32(0U)
        , overflow_b(false)
      {
        ME_Mutex_Init_t(&mutex_s, true);
        ME_Semaphore_Open_t(&sem_s, "sem", e_SofCreate, e_SmfOwn, 0);
      }

      virtual ~Fifo()
      {}

      virtual void init_v()
      {
        writePos_u32 = 0U;
        readPos_u32 = 0U;
        memset(buffer_au8, 0, bufferSize_u32);
      }

      virtual void cleanup_v()
      {
        writePos_u32 = 0U;
        readPos_u32 = 0U;
        memset(buffer_au8, 0, bufferSize_u32);
      }

      virtual bool_t write_b(const void* b_Buffer_pv, uint32_t i_Size_u32)
      {
        ME_Mutex_Lock_t(&mutex_s);

        bool_t v_Result_b = false;
        EntryHeader_s v_EntryHeader_s = { 0U, 0U };

        switch (getWriteState_e(i_Size_u32))
        {
        case e_BufferInit:
        case e_BufferNotEmpty:
        {
          uint32_t v_DataPos_u32 = (writePos_u32 + s_EntryHeaderSize_u32);

          // entry fits into buffer
          v_EntryHeader_s.entrySize_u32 = i_Size_u32;
          v_EntryHeader_s.nextPos_u32 = writePos_u32 + s_EntryHeaderSize_u32 + i_Size_u32;

          memcpy(&buffer_au8[writePos_u32], &v_EntryHeader_s, s_EntryHeaderSize_u32);
          memcpy(&buffer_au8[v_DataPos_u32], b_Buffer_pv, i_Size_u32);

          writePos_u32 += s_EntryHeaderSize_u32 + i_Size_u32;

          numOfEntries_u32++;

          v_Result_b = true;
          break;
        }
        case e_BufferFull:
        {
          v_Result_b = false;
          break;
        }
        case e_BufferOverflow:
        {
          if (overflow_b == true)
          {
            ME_Debugger_F_Printf_v("No!");
          }

          overflow_b = true;

          lastEntryPos_u32 = writePos_u32;

          writePos_u32 = 0;

          uint32_t v_DataPos_u32 = (writePos_u32 + s_EntryHeaderSize_u32);
          // entry fits into buffer
          v_EntryHeader_s.entrySize_u32 = i_Size_u32;
          v_EntryHeader_s.nextPos_u32 = writePos_u32 + s_EntryHeaderSize_u32 + i_Size_u32;

          memcpy(&buffer_au8[writePos_u32], &v_EntryHeader_s, s_EntryHeaderSize_u32);
          memcpy(&buffer_au8[v_DataPos_u32], b_Buffer_pv, i_Size_u32);

          writePos_u32 += s_EntryHeaderSize_u32 + i_Size_u32;

          numOfEntries_u32++;

          v_Result_b = true;
          break;
        }
        case e_BufferError:
        {
          ME_Debugger_F_Printf_v("Fifo Buffer: Error\n");
          break;
        }
        default:
        {
          ME_Debugger_F_Printf_v("Fifo Buffer: State not defined\n");
          break;
        }
        }

        ME_Mutex_UnLock_t(&mutex_s);

        return v_Result_b;
      }

      virtual uint32_t read_u32(void* b_Buffer_pv)
      {
        uint32_t v_Size_u32 = 0;
        EntryHeader_s v_EntryHeader_s;

        if (b_Buffer_pv != NULL)
        {
          ME_Mutex_Lock_t(&mutex_s);

          if (numOfEntries_u32 > 0)
          {
            if (readPos_u32 != writePos_u32)
            {
              if (overflow_b == false || readPos_u32 != lastEntryPos_u32)
              {
                uint32_t v_DataPos_u32 = readPos_u32 + s_EntryHeaderSize_u32;

                memcpy(&v_EntryHeader_s, &buffer_au8[readPos_u32], s_EntryHeaderSize_u32);

                v_Size_u32 = v_EntryHeader_s.entrySize_u32;

                memcpy(b_Buffer_pv, &buffer_au8[v_DataPos_u32], v_Size_u32);
                memset(&buffer_au8[readPos_u32], 0, s_EntryHeaderSize_u32 + v_Size_u32);

                readPos_u32 = v_EntryHeader_s.nextPos_u32;

                numOfEntries_u32--;
              }
              else
              {
                overflow_b = false;

                if (readPos_u32 == lastEntryPos_u32)
                {
                  readPos_u32 = 0;
                }

                memcpy(&v_EntryHeader_s, &buffer_au8[readPos_u32], s_EntryHeaderSize_u32);

                uint32_t v_DataPos_u32 = readPos_u32 + s_EntryHeaderSize_u32;
                memcpy(&v_EntryHeader_s, &buffer_au8[readPos_u32], s_EntryHeaderSize_u32);

                v_Size_u32 = v_EntryHeader_s.entrySize_u32;

                memcpy(b_Buffer_pv, &buffer_au8[v_DataPos_u32], v_Size_u32);
                memset(&buffer_au8[readPos_u32], 0, s_EntryHeaderSize_u32 + v_Size_u32);

                readPos_u32 = v_EntryHeader_s.nextPos_u32;

                numOfEntries_u32--;
              }
            }
          }

          ME_Mutex_UnLock_t(&mutex_s);
        }

        return v_Size_u32;
      }

    private:

      BufferState_e getWriteState_e(uint32_t i_WriteSize_u32)
      {
        BufferState_e v_Result_e = e_BufferInvalid;

        if (writePos_u32 >= bufferSize_u32)
        {
          v_Result_e = e_BufferError;
        }
        else if (writePos_u32 == readPos_u32)
        {
          if ((writePos_u32 + s_EntryHeaderSize_u32 + i_WriteSize_u32) < bufferSize_u32)
          {
            v_Result_e = e_BufferInit;
          }
          else
          {
            if ((0 + s_EntryHeaderSize_u32 + i_WriteSize_u32) < readPos_u32)
            {
              v_Result_e = e_BufferOverflow;
            }
            else
            {
              v_Result_e = e_BufferFull;
            }
          }
        }
        else if (writePos_u32 > readPos_u32)
        {
          if ((writePos_u32 + s_EntryHeaderSize_u32 + i_WriteSize_u32) < bufferSize_u32)
          {
            v_Result_e = e_BufferNotEmpty;
          }
          else
          {
            if ((0 + s_EntryHeaderSize_u32 + i_WriteSize_u32) < readPos_u32)
            {
              v_Result_e = e_BufferOverflow;
            }
            else
            {
              v_Result_e = e_BufferFull;
            }
          }
        }
        else if (writePos_u32 < readPos_u32)
        {
          if ((writePos_u32 + s_EntryHeaderSize_u32 + i_WriteSize_u32) < readPos_u32)
          {
            v_Result_e = e_BufferNotEmpty;
          }
          else
          {
            v_Result_e = e_BufferFull;
          }
        }
        else
        {
          // do nothing
        }

        return v_Result_e;
      }

    private:

      uint8_t buffer_au8[bufferSize_u32];

      uint32_t writePos_u32;

      uint32_t readPos_u32;

      uint32_t lastEntryPos_u32;

      uint32_t numOfEntries_u32;

      bool_t overflow_b;

      // read-write protection for thread safety
      Mutex_s  mutex_s;

      Semaphore_s sem_s;

    };


  } // namespace buffer

} // namespace mecl


#endif /* BUFFER_FIFO_H_ */
