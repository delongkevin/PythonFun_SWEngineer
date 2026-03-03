#include "ThreadedClient.h"
#include "osal/networking/SocketClient.h"

namespace tsdk
{

  ThreadedClient::ThreadedClient()
    : m_Network(NULL)
    , m_NetworkRunnable(NULL)
  {
  }

  ThreadedClient::~ThreadedClient()
  {
    Disconnect();
  }

  bool_t ThreadedClient::Connect(const char* ip, sint32_t port, osal::INetworkMsgHandler* handler)
  {
    Disconnect();

    // create connection and register Messenger for the onReceive function called by NetworkMessageRunnable
    osal::SocketClient* client = new osal::SocketClient();
    client->init_b(e_SptTcp, ip, port);
    m_Network = client;

    bool success = ME_Socket_IsValid_b(&client->getSocketHandle_t());
    if (success)
    {
      if (handler)
      {
        m_Network->registerHandler_b(handler);
      }

      // start thread for network processing
      m_NetworkRunnable = new NetworkMessageRunnable(m_Network);
      m_NetworkThread.start_v(m_NetworkRunnable);
      m_NetworkThread.setName_v("NetworkThread");
    }
    else
    {
      Disconnect();
    }

    return success;
  }

  bool_t ThreadedClient::IsConnected() const
  {
    return (NULL != m_Network);
  }

  bool_t ThreadedClient::Send(const uint8_t* b_Buffer_pu8, size_t i_BufferLength_t)
  {
    bool_t v_Success_b = IsConnected();
    
    if (v_Success_b)
    {
      v_Success_b = m_Network->send_b(b_Buffer_pu8, i_BufferLength_t);
    }

    return v_Success_b;
  }

  bool_t ThreadedClient::Disconnect()
  {
    if (m_NetworkRunnable)
    {
      m_NetworkThread.terminate_v();
      m_NetworkThread.join_v();

      m_NetworkRunnable->terminate_v();
      delete m_NetworkRunnable;
      m_NetworkRunnable = NULL;
    }

    if (m_Network)
    {
      m_Network->shutdown_v();
      delete m_Network;
      m_Network = NULL;
    }

    return true;
  }

} // namespace tsdk