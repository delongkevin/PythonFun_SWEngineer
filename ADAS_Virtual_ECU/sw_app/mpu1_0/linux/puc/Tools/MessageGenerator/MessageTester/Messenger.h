#pragma once

#include <QtGui/QMainWindow>

#include <ui_MessengerUi.h>
#include "MessageGenerator.h"
#include <QTUtils/PropertyBrowser/PropertyFactory.h>
#include <Network/ThreadedClient.h>


#include <osal/threading/Mutex.h>

namespace osal
{
  class INetwork;
}

namespace tsdk
{
  class BaseProperty;
  class GroupProperty;
  class IntProperty;
  class StringProperty;
}

namespace messenger
{

struct NetworkData_s
{
  uint8_t     data[512];
  size_t      dataLength;
  // Timestamp
};

class Messenger : public QMainWindow, public osal::INetworkMsgHandler
{
  Q_OBJECT

public:
  Messenger(QWidget* parent = 0, Qt::WFlags flags = 0);
  virtual ~Messenger();

  // connect to a target via ip and port. also creates a background thread for onReceive -> blocks
  bool connectToTarget(const char* ip, sint32_t port);

  // disconnect from the target
  void disconnectFromTarget();

  // Load messages from XML file Name and Update UI
  bool loadMessages(const char* xmlFile);

  // QT paintEvent update loop just updates the logger ui
  virtual void paintEvent(QPaintEvent *paintEvent);

  // logging utility
  void logText(const char* text, uint32_t color);
  void logText(const QString& text, uint32_t color);

  // load settings from xml file
  bool loadSettings(const char* fileName);

public:
  // INetworkMsgHandler receive function
  virtual void onReceive_v(uint8_t* b_Buffer_pu8, size_t i_BufferLength_t) ME_OVERRIDE;

private:
  // Create all properties based on datatypes for a Message
  void createProperties(const mg::DataTypeVector_t& dataTypes, tsdk::BaseProperty* parent);

  // retrieve all data from Properties and create a buffer for messages
  void writeSendDataTypes(const mg::DataTypeVector_t& dataTypes, uint8_t* buffer, uint32_t& dataIndex, bool endianess, uint32_t subPropIndexOffset);

  // check if a Message id is in the ignore list
  bool isIgnored(const std::string& messageIDHex);

  // add message id to ignore
  bool ignoreMessage(const std::string& messageIDHex);

  // retrieve loaded message from hex id (maybe NULL if nothing was found)
  const mg::Message* const getMessageFromHexID(const std::string& messageIDHex) const;

  // --- Slots configured via QT Designer --- (see Signal/slot handling)
private slots:
    // Load XML file via dialog box
  void slotLoad();

  // Load XML file containing the settings
  void slotLoadSettings();

  // called when a message item was clicked (used to update Property Browser)
  void onMessageItemClicked(QListWidgetItem* item);

  // sends selected message and the data set via properties to the connected target
  void onSend();

  // ignores the specific message from the watch list
  void onIgnore();

  // removes a message from the ignore list
  void onWatch();

  // connect via ip and port from UI
  void onConnect();

  // disconnect from target
  void onDisconnect();


private:
  typedef std::set<std::string> IgnoreList_t;
  Ui::EditorUi                      m_UI;               ///< Our cute QT UI
  mg::MessageGenerator              m_MsgGen;           ///< The Message Generator to load messages and its data types
  tsdk::PropertyFactory             m_PropFactory;      ///< Property Factory creates the properties we need
  tsdk::GroupProperty*              m_GroupProp;        ///< Message Group property
  tsdk::StringProperty*             m_IdProp;           ///< Static ID property, value updated in onMessageItemClicked
  std::vector<tsdk::BaseProperty*>  m_SubProps;         ///< List of properties, list is filled in onMessageItemClicked
  uint32_t                          m_MsgIndex;         ///< current selected msg index;
  tsdk::ThreadedClient              m_Client;           ///< The client connecting to the target
  osal::Mutex                       m_NetworkMutex;     ///< mutual exclusion for receiving messages
  std::vector<NetworkData_s>        m_NetworkData;      ///< Buffer the log data received via NetworkThread in onReceive function
  bool                              m_FileDialogOpened; ///< true if file dialog is currently opened, used to deactivate QT update()
  IgnoreList_t                      m_IgnoreList;       ///< messages to Ignore
};

} // namespace gde