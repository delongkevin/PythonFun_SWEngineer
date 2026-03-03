#pragma once

#include <osal/threading/IRunnable.h>
#include <osal/networking/INetwork.h>
#include <osal/threading/Thread.h>
#include <osal/networking/INetworkMsgHandler.h>

namespace osal
{
  class INetworkMsgHandler;
}

namespace tsdk
{
  class NetworkMessageRunnable : public osal::IRunnable
  {
  public:
    explicit NetworkMessageRunnable(osal::INetwork* b_NetInterface_po)
      : osal::IRunnable()
      , network_po(b_NetInterface_po)
      , run_b(true)
    { }
    virtual ~NetworkMessageRunnable() { }

    virtual void init_v()
    {
      // init data
    }

    virtual void run_v()
    {
      for( ; true == run_b; )
      {
        if(NULL != network_po)
        {
          network_po->process_b();
        }
      }
    }

    virtual void cleanup_v()
    {
      // cleanup data
    }

    void terminate_v()
    {
      run_b = false;
    }

  private:
    osal::INetwork* network_po;
    bool_t run_b;
  };

  class ThreadedClient
  {
  public:
    ThreadedClient();
    ~ThreadedClient();

    bool_t Connect(const char* ip, sint32_t port, osal::INetworkMsgHandler* handler); 
    bool_t IsConnected() const;
    bool_t Send(const uint8_t* b_Buffer_pu8, size_t i_BufferLength_t);
    bool_t Disconnect();

  private:
    osal::INetwork*                   m_Network;          ///< Interface to send network messages
    NetworkMessageRunnable*           m_NetworkRunnable;  ///< IRunnable Interface implementation
    osal::Thread                      m_NetworkThread;    ///< Thread for receiving messages

  };

} // namespace tsdk