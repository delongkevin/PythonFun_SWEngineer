#include "Messenger.h"

#include <QDir.h>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QByteArray>

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

#include <platform/stdlib/ME_Assert.h>
#include <platform/stdlib/utils/DataSerializer.h>
#include <osal/networking/SocketServer.h>

#include <QTUtils/PropertyBrowser/Properties/StringProperty.h>
#include <QTUtils/PropertyBrowser/Properties/GroupProperty.h>
#include <QTUtils/PropertyBrowser/Properties/BoolProperty.h>
#include <QTUtils/PropertyBrowser/Properties/FloatProperty.h>
#include <QTUtils/PropertyBrowser/Properties/IntProperty.h>

#include "Message.h"

namespace messenger
{

Messenger::Messenger(QWidget* parent /*= 0*/, Qt::WFlags flags /*= 0*/)
	: QMainWindow(parent, flags)
{
	m_UI.setupUi(this);

  // qt signal slot connect handling
  connect(m_UI.messageList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onMessageItemClicked(QListWidgetItem*)));

  // property factory
  m_PropFactory.init_v(m_UI.PropertyBrowser);
  m_GroupProp = m_PropFactory.createProperty_po<tsdk::GroupProperty>("Message", NULL, true);
  m_GroupProp->addTopLevelProperty_v();

  m_IdProp = m_PropFactory.createProperty_po<tsdk::StringProperty>("ID", m_GroupProp->getTopLevelProperty(), true);
  m_IdProp->addTopLevelProperty_v();

  m_FileDialogOpened = false;
}

Messenger::~Messenger()
{
  // release everything
  disconnectFromTarget();

  // qt signal slot disconnect handling
  disconnect(m_UI.messageList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onMessageItemClicked(QListWidgetItem*)));
}


bool Messenger::connectToTarget(const char* ip, sint32_t port)
{
  // log connect text
  QString connectText;
  connectText.sprintf("Connecting to address= %s Port= %d", ip, port); 
  logText(connectText, 0x000000);

  bool_t v_Success_b = m_Client.Connect(ip, port, this);

  // log success
  if (v_Success_b)
  {
    logText("Connection success", 0x00FF00);
  }
  else
  {
    logText("Connection failed", 0xFF0000);
  }

  return v_Success_b;
}

void Messenger::disconnectFromTarget()
{
  logText("Disconnect from target", 0xFF0000);

  m_Client.Disconnect();


}


bool Messenger::loadMessages(const char* xmlFile)
{
  // make sure we have a valid input
  if (!xmlFile)
  {
    return false;
  }

  // load all messages in xml file
  bool success = m_MsgGen.load(xmlFile);
  
  // failed to load
  if (!success)
  {
    return false;
  }

  QString loggerText = "--- Loading Messages ---\n";

  // clear previous list add all messages to the UI, clear list before
  m_UI.messageList->clear();
  m_UI.messageListWatch->clear();
  m_UI.messageListIgnore->clear();
  m_IgnoreList.clear();
  const std::vector<mg::Message>& msgs = m_MsgGen.getMessages();
  for (size_t i = 0; i < msgs.size(); ++i)
  {
    QListWidgetItem* item = new QListWidgetItem();
    QString messageName = QString::fromStdString(msgs[i].getName());
    item->setText(messageName);
    item->setData(Qt::UserRole, i);
    m_UI.messageList->addItem(item);

    // copy items for messageListWatch
    m_UI.messageListWatch->addItem(new QListWidgetItem(*item));

    loggerText += messageName;
    loggerText += "\n";
  }

  loggerText += "--- Loading Finished ---\n";

  m_UI.loggerTextEdit->appendPlainText(loggerText);
  
  return success;
}

void Messenger::paintEvent(QPaintEvent *paintEvent)
{
  // skip if file dialog is currently opened
  if (m_FileDialogOpened)
  {
    return;
  }

  // we access the logbuffer here, so take the mutex
  m_NetworkMutex.take_b();

  if (!m_NetworkData.empty())
  {
    // only update ui with one string for better performance
    QString finalLogString;

    for (size_t i = 0; i < m_NetworkData.size(); ++i)
    {
      const NetworkData_s& networkData = m_NetworkData[i];

      // read id from protocol
      uint32_t v_Index_u32 = 0;
      uint16_t v_Messaged_u16 = ME_DataSerializer_Read_u16(&networkData.data[0], &v_Index_u32, true);

      // convert to hex string
      std::stringstream ssHexId;
      ssHexId << std::hex << std::uppercase << v_Messaged_u16;
      std::string hexId = ssHexId.str();
      
      // and check if we need to ignore this message
      if (!isIgnored(hexId))
      {
        const mg::Message* currentMessage = getMessageFromHexID(hexId);

        std::stringstream ss;
        // convert to hex id
        ss << "--- Received ---" << std::endl;
        ss << "ID      : " << hexId;
        if (currentMessage)
        {
          ss << "  " << currentMessage->getName();
        }
        ss << "\n";
        ss << "Data  : ";

        // retrieve data in readable format
        size_t v_DataIndex_u32 = v_Index_u32;
        while (v_DataIndex_u32 < networkData.dataLength)
        {
          ss << std::to_string((long long)networkData.data[v_DataIndex_u32]) << " ";

          ++v_DataIndex_u32;
        }

        finalLogString += QString::fromStdString(ss.str());

        //don't add newline for last entry, qt will append a new line
        if (i + 1 != m_NetworkData.size())
        {
          finalLogString += "\n";
        }
      }

    } 

    if (!finalLogString.isEmpty())
    {
      m_UI.loggerTextEdit->appendPlainText(finalLogString);
    }


    m_NetworkData.clear();
  } // if (!m_LogBuffer.empty())

  // release mutex
  m_NetworkMutex.give_v();

  // and keep updating the whole time
  update();
}


void Messenger::logText(const char* text, uint32_t color /*= 0x000000*/)
{
  // get hex color as string
  std::stringstream ss;
  ss << std::setfill('0') << std::setw(6) << std::hex << std::uppercase << color;
  std::string colorHex = ss.str();

  // prepare log string
  QString logString;
  logString.sprintf("<p style=\"color:#%s\";>%s</p>", colorHex.c_str(), text);

  // finally append text edit with html
  m_UI.loggerTextEdit->appendHtml(logString);
}

void Messenger::logText(const QString& text, uint32_t color /*= 0x000000*/)
{
  // make copy, is important! getting const ref is evil knevil.
  std::string textStd = text.toStdString();
  logText(textStd.c_str(), color);
}

bool Messenger::loadSettings(const char* fileName)
{
  const char* address = NULL;
  int port = 7000;
  const char* modelFile = NULL;

  // load settings file
  tinyxml2::XMLDocument xmlDoc;
  bool success = (xmlDoc.LoadFile(fileName) == tinyxml2::XML_SUCCESS);
  if (!success)
  {
    logText("No or incorrect Settings file found", 0xFF0000);
    return false;
  }

  // Load address and port
  const tinyxml2::XMLElement* connectionTag = xmlDoc.FirstChildElement("Connection");
  if (connectionTag)
  {
    address = connectionTag->Attribute("Address");
    if (NULL == address)
    {
      logText("No Address attribute found", 0xFF0000);
    }

    if (connectionTag->QueryIntAttribute("Port", &port) != tinyxml2::XML_SUCCESS)
    {
      logText("No Port attribute found", 0xFF0000);
    }
  }
  else
  {
    logText("No Connection Tag found", 0xFF0000);
  }

  // Load Model File
  std::vector<std::string> ignoredIDs;
  const tinyxml2::XMLElement* modelTag = xmlDoc.FirstChildElement("Model");
  if (modelTag)
  {
    modelFile = modelTag->Attribute("File");
    if (NULL == modelFile)
    {
      logText("No file attribute found", 0xFF0000);
    }

    const tinyxml2::XMLElement* ignoreMessageElement = modelTag->FirstChildElement("IgnoreMessage");
    while (ignoreMessageElement != nullptr)
    {
      const char* ignoreMessageID = ignoreMessageElement->Attribute("ID");
      if (ignoreMessageID)
      {
        ignoredIDs.push_back(ignoreMessageID);
      }

      // check for further IgnoreMessage Sibling Elements
      ignoreMessageElement = ignoreMessageElement->NextSiblingElement("IgnoreMessage");
    }



  }
  else
  {
    logText("No Model Tag found", 0xFF0000);
  }

  // laod all messages if model file exists
  if (modelFile)
  {
    loadMessages(modelFile);

    // and if we have some ignored ids found in xml, ignore them
    for (size_t i = 0; i < ignoredIDs.size(); ++i)
    {
      ignoreMessage(ignoredIDs[i]);
    }

  }

  if (address)
  {
    // update UI
    m_UI.lineEditAddress->setText(address);
    m_UI.spinBoxPort->setValue(port);

    // and execute the connection to target
    connectToTarget(address, port);
  }

  return success;
}

void Messenger::onReceive_v(uint8_t* b_Buffer_pu8, size_t i_BufferLength_t)
{
  // we need to read at least 2 bytes for the ID
  if (i_BufferLength_t < 2 || i_BufferLength_t >= 512)
  {
    return;
  }

  m_NetworkMutex.take_b();

  Assert(i_BufferLength_t < 512);

  NetworkData_s logInfo;
  logInfo.dataLength = i_BufferLength_t;
  memcpy(&logInfo.data[0], b_Buffer_pu8, i_BufferLength_t);

  m_NetworkData.push_back(logInfo);

  m_NetworkMutex.give_v();
}



void Messenger::createProperties(const mg::DataTypeVector_t& dataTypes, tsdk::BaseProperty* parent)
{
  for (size_t i = 0; i < dataTypes.size(); ++i)
  {
    const mg::DataType& dataType = dataTypes[i];

    tsdk::BaseProperty* dataProperty = NULL;

    switch (dataType.getDataType())
    {
    case mg::e_Bool_t:
      {
        dataProperty = m_PropFactory.createProperty_po<tsdk::BoolProperty>(dataType.getName().c_str(), parent->getTopLevelProperty(), false);

        dataProperty->addTopLevelProperty_v();
        m_SubProps.push_back(dataProperty);
        break;
      }
    case mg::e_Uint8_t:
    case mg::e_Uint16_t:
    case mg::e_Uint32_t:
    case mg::e_Uint64_t:
    case mg::e_Sint8_t:
    case mg::e_Sint16_t:
    case mg::e_Sint32_t:
    case mg::e_Sint64_t:
      {
        if (dataType.isArray())
        {
          dataProperty = m_PropFactory.createProperty_po<tsdk::GroupProperty>(dataType.getName().c_str(), parent->getTopLevelProperty(), true);
          dataProperty->addTopLevelProperty_v();
          m_SubProps.push_back(dataProperty);

          for (size_t arr = 0; arr < dataType.getArrayLength(); ++arr)
          {
            std::string propName = dataType.getName();
            propName += "_";
            propName += std::to_string((long long)arr);

            tsdk::BaseProperty* arrDataProperty = m_PropFactory.createProperty_po<tsdk::IntProperty>(propName.c_str(), dataProperty->getTopLevelProperty(), false);
            arrDataProperty->addTopLevelProperty_v();
            m_SubProps.push_back(arrDataProperty);
          }


        }
        else
        {
          // kinda dirty, use int property for everything here, but it's actually not very correct.
          dataProperty = m_PropFactory.createProperty_po<tsdk::IntProperty>(dataType.getName().c_str(), parent->getTopLevelProperty(), false);

          dataProperty->addTopLevelProperty_v();
          m_SubProps.push_back(dataProperty);
        }

        break;
      }
    case mg::e_Float32_t:
    case mg::e_Float64_t:
      {
        // float property uses always double internally
        dataProperty = m_PropFactory.createProperty_po<tsdk::FloatProperty>(dataType.getName().c_str(), parent->getTopLevelProperty(), false);

        dataProperty->addTopLevelProperty_v();
        m_SubProps.push_back(dataProperty);
        break;
      }
    case mg::e_Struct:
      {
        // creat struct property
        dataProperty = m_PropFactory.createProperty_po<tsdk::GroupProperty>(dataType.getName().c_str(), parent->getTopLevelProperty(), true);

        // and recursively add everything in the structs
        createProperties(dataType.getStructMembers(), dataProperty);
        parent->addTopLevelProperty_v();

        dataProperty->addTopLevelProperty_v();
        m_SubProps.push_back(dataProperty);
        break;
      }
    case mg::e_DataTypeCount:
    case mg::e_DataTypeInvalid:
    default:
      dataProperty = NULL;
      break;
    }

  }
}

void Messenger::writeSendDataTypes(const mg::DataTypeVector_t& dataTypes, uint8_t* buffer, uint32_t& dataIndex, bool endianess, uint32_t subPropIndexOffset)
{
  uint32_t bitFieldCounter  = 0;
  uint8_t  bitFieldData     = 0;
  uint32_t currentSubPropIndexOffset = subPropIndexOffset;

  for (size_t i = 0; i < dataTypes.size(); ++i)
  {
    uint32_t subPropIndex = i + currentSubPropIndexOffset;
    Assert(subPropIndex < m_SubProps.size());

    const mg::DataType& dataType = dataTypes[i];
    switch (dataType.getDataType())
    {
    case mg::e_Bool_t:
      {
        tsdk::BoolProperty* v_BoolProperty_po = static_cast<tsdk::BoolProperty*>(m_SubProps[subPropIndex]);
        Assert(v_BoolProperty_po);
        if (v_BoolProperty_po)
        {
          bool_t v_Val_b = v_BoolProperty_po->getValue_b();
          ME_DataSerializer_Write_u8(&buffer[0], &dataIndex, static_cast<uint8_t>(v_Val_b), endianess);
        }

        break;
      }
    case mg::e_Uint8_t:
      {

        //if (v_Property_po)
        //{
          if (dataType.isArray())
          {
            tsdk::GroupProperty* v_Property_po = static_cast<tsdk::GroupProperty*>(m_SubProps[subPropIndex]);
            Assert(v_Property_po);

            Assert(subPropIndex + dataType.getArrayLength() < m_SubProps.size());

            for (size_t arr = 0; arr < dataType.getArrayLength(); ++arr)
            {
              tsdk::IntProperty* v_ArrProperty_po = static_cast<tsdk::IntProperty*>(m_SubProps[subPropIndex + arr + 1]);
              Assert(v_Property_po);

              uint8_t v_Value_u8 = static_cast<uint8_t>(v_ArrProperty_po->getValue_s32());
                ME_DataSerializer_Write_u8(&buffer[0], &dataIndex, v_Value_u8, endianess);
            }

            currentSubPropIndexOffset += dataType.getArrayLength();

          }
          else if (dataType.getBitLength() != 1)
          {
            tsdk::IntProperty* v_Property_po = static_cast<tsdk::IntProperty*>(m_SubProps[subPropIndex]);
            Assert(v_Property_po);
            uint8_t v_Value_u8 = static_cast<uint8_t>(v_Property_po->getValue_s32());
            ME_DataSerializer_Write_u8(&buffer[0], &dataIndex, v_Value_u8, endianess);
          }

          else
          {
            tsdk::IntProperty* v_Property_po = static_cast<tsdk::IntProperty*>(m_SubProps[subPropIndex]);
            Assert(v_Property_po);
            uint8_t v_Value_u8 = static_cast<uint8_t>(v_Property_po->getValue_s32());
            std::cout << "BitField Counter: " << bitFieldCounter << " Property: " << v_Property_po->groupName_o.toStdString() << std::endl;

            // bitfields only work for uint8_t s right now
            bitFieldData |= v_Value_u8 << bitFieldCounter;
            ++bitFieldCounter;
            if (bitFieldCounter == 8)
            {
              ME_DataSerializer_Write_u8(&buffer[0], &dataIndex, bitFieldData, endianess);
              bitFieldCounter = 0;
              bitFieldData = 0;
            }
          }


        //}

        break;
      }
    case mg::e_Uint16_t:
      {
        tsdk::IntProperty* v_Property_po = static_cast<tsdk::IntProperty*>(m_SubProps[subPropIndex]);
        Assert(v_Property_po);
        if (v_Property_po)
        {
          ME_DataSerializer_Write_u16(&buffer[0], &dataIndex, static_cast<uint16_t>(v_Property_po->getValue_s32()), endianess);
        }

        break;
      }
    case mg::e_Uint32_t:
      {
        tsdk::IntProperty* v_Property_po = static_cast<tsdk::IntProperty*>(m_SubProps[subPropIndex]);
        Assert(v_Property_po);
        if (v_Property_po)
        {
          ME_DataSerializer_Write_u32(&buffer[0], &dataIndex, static_cast<uint32_t>(v_Property_po->getValue_s32()), endianess);
        }

        break;
      }
    case mg::e_Uint64_t:
      {
        tsdk::IntProperty* v_Property_po = static_cast<tsdk::IntProperty*>(m_SubProps[subPropIndex]);
        Assert(v_Property_po);
        if (v_Property_po)
        {
          ME_DataSerializer_Write_u64(&buffer[0], &dataIndex, static_cast<uint64_t>(v_Property_po->getValue_s32()), endianess);
        }

        break;
      }
    case mg::e_Sint8_t:
      {
        tsdk::IntProperty* v_Property_po = static_cast<tsdk::IntProperty*>(m_SubProps[subPropIndex]);
        Assert(v_Property_po);
        if (v_Property_po)
        {
          ME_DataSerializer_Write_s8(&buffer[0], &dataIndex, static_cast<sint8_t>(v_Property_po->getValue_s32()), endianess);
        }

        break;
      }
    case mg::e_Sint16_t:
      {
        tsdk::IntProperty* v_Property_po = static_cast<tsdk::IntProperty*>(m_SubProps[subPropIndex]);
        Assert(v_Property_po);
        if (v_Property_po)
        {
          ME_DataSerializer_Write_s16(&buffer[0], &dataIndex, static_cast<sint16_t>(v_Property_po->getValue_s32()), endianess);
        }

        break;
      }
    case mg::e_Sint32_t:
      {
        tsdk::IntProperty* v_Property_po = static_cast<tsdk::IntProperty*>(m_SubProps[subPropIndex]);
        Assert(v_Property_po);
        if (v_Property_po)
        {
          ME_DataSerializer_Write_s32(&buffer[0], &dataIndex, static_cast<sint32_t>(v_Property_po->getValue_s32()), endianess);
        }

        break;
      }
    case mg::e_Sint64_t:
      {
        tsdk::IntProperty* v_Property_po = static_cast<tsdk::IntProperty*>(m_SubProps[subPropIndex]);
        Assert(v_Property_po);
        if (v_Property_po)
        {
          ME_DataSerializer_Write_s64(&buffer[0], &dataIndex, static_cast<sint64_t>(v_Property_po->getValue_s32()), endianess);
        }

        break;
      }
    case mg::e_Float32_t:
      {
        tsdk::FloatProperty* v_Property_po = static_cast<tsdk::FloatProperty*>(m_SubProps[subPropIndex]);
        Assert(v_Property_po);
        if (v_Property_po)
        {
          ME_DataSerializer_Write_f32(&buffer[0], &dataIndex, static_cast<float32_t>(v_Property_po->getValue_f32()), endianess);
        }

        break;
      }
    case mg::e_Float64_t:
      {
        // not supported right now
        Assert(false);
        break;
      }
    case mg::e_Struct:
      {
        // recursive call for structs (currently only bitfield support)
        writeSendDataTypes(dataType.getStructMembers(), buffer, dataIndex, endianess, i);
        break;
      }
    case mg::e_DataTypeCount:
    case mg::e_DataTypeInvalid:
    default:
      {
        Assert(false);
        break;
      }
    } // switch
  } // for

}

bool Messenger::isIgnored(const std::string& messageIDHex)
{
  return (m_IgnoreList.find(messageIDHex) != m_IgnoreList.end());
}

bool Messenger::ignoreMessage(const std::string& messageIDHex)
{
  const mg::Message* foundMessage = getMessageFromHexID(messageIDHex);

  if (foundMessage)
  {
    m_IgnoreList.insert(foundMessage->getId());

    // UI Stuff
    QList<QListWidgetItem*> foundItems = m_UI.messageListWatch->findItems(foundMessage->getName().c_str(), Qt::MatchExactly); 
    if (!foundItems.empty())
    {
      // copy item over to ignore list
      m_UI.messageListIgnore->addItem(new QListWidgetItem(*foundItems[0]));

      // remove the item from watch list
      m_UI.messageListWatch->removeItemWidget(foundItems[0]);
      delete foundItems[0];
    }

  }

  return foundMessage != NULL;
}

const mg::Message* const Messenger::getMessageFromHexID(const std::string& messageIDHex) const
{
  const mg::Message* foundMessage = NULL;

  const std::vector<mg::Message>& messages = m_MsgGen.getMessages();
  for (size_t i = 0; i < messages.size(); ++i)
  {
    const mg::Message& curr = messages[i];
    if (curr.getId() == messageIDHex)
    {
      foundMessage = &curr;
      break;
    }
  }

  return foundMessage;
}

void Messenger::slotLoad()
{
  m_FileDialogOpened = true;

  QString fileName = QFileDialog::getOpenFileName(this, "Load XML Message Model", "", tr("XML (*.xml);;"));
  if(!fileName.isEmpty())
  {
    loadMessages(fileName.toStdString().c_str());
  }	

  m_FileDialogOpened = false;
}

void Messenger::slotLoadSettings()
{
  m_FileDialogOpened = true;

  QString fileName = QFileDialog::getOpenFileName(this, "Load XML Settings File", "", tr("XML (*.xml);;"));
  if(!fileName.isEmpty())
  {
    loadSettings(fileName.toStdString().c_str());
  }	

  m_FileDialogOpened = false;
}

void Messenger::onMessageItemClicked(QListWidgetItem* item)
{
  bool convertOk = false;
  m_MsgIndex = item->data(Qt::UserRole).toUInt(&convertOk);
  if (convertOk)
  {
    // clear previous properties
    for (size_t i = 0; i < m_SubProps.size(); ++i)
    {
      m_GroupProp->removeSubProperty(m_SubProps[i]);
    }
    m_SubProps.clear();

    // get the current message by index
    const std::vector<mg::Message>& msgs = m_MsgGen.getMessages();
    if (m_MsgIndex < msgs.size())
    {
      const mg::Message& currentMsg = msgs[m_MsgIndex];

      // update id
      m_IdProp->setValue_v(currentMsg.getId().c_str());
      
      // update all data types
      createProperties(currentMsg.getDataTypes(), m_GroupProp);
    }
  }
}

void Messenger::onSend()
{
  const std::vector<mg::Message>& msgs = m_MsgGen.getMessages();

  // invalid index
  if (m_MsgIndex > msgs.size())
  {
    logText("Invalid MsgIndex -> Select a message before sending...", 0xFF0000);
    return;
  }

  mg::Message currentMsg = msgs[m_MsgIndex];

  if (m_Client.IsConnected())
  {
    // convert string to uint16 hex value
    uint16_t v_RequestType_u16;   
    std::stringstream ssIn;
    ssIn << std::hex << currentMsg.getId();
    ssIn >> v_RequestType_u16;

    // declare buffer
    uint8_t v_Buffer_au8[512];
    memset(v_Buffer_au8, 0, sizeof(v_Buffer_au8));

    // write header
    uint32_t v_Index_u32 = 0;
    ME_DataSerializer_Write_u16(&v_Buffer_au8[0], &v_Index_u32, v_RequestType_u16, true);

    // wirte payload data
    mg::DataTypeVector_t dataTypes = currentMsg.getDataTypes();
    // index for m_SubProperties
    writeSendDataTypes(dataTypes, &v_Buffer_au8[0], v_Index_u32, true, 0);

    // send data via network interface
    m_Client.Send(&v_Buffer_au8[0], v_Index_u32);

    // log the data that was sent via Network
    std::stringstream ss;
    ss << "--- Send ---" << std::endl;
    ss << "ID      : " << std::hex << v_RequestType_u16 << "\n";
    ss << "Data  : ";

    size_t v_DataIndex_u32 = 2;
    while (v_DataIndex_u32 < v_Index_u32)
    {
      ss << std::to_string((long long)v_Buffer_au8[v_DataIndex_u32]) << " ";
      ++v_DataIndex_u32;
    }

    m_UI.loggerTextEdit->appendPlainText(QString::fromStdString(ss.str()));

  }

}

void Messenger::onIgnore()
{
  if (m_UI.messageListWatch->selectedItems().isEmpty())
  {
    return;
  }

  // get selected item from the Watch list, that we want to switch to ignore list
  QListWidgetItem* selectedItem = m_UI.messageListWatch->selectedItems()[0];
  if (!selectedItem)
  {
    return;
  }

  bool convertOk = false;
  uint32_t itemIndex = selectedItem->data(Qt::UserRole).toUInt(&convertOk);
  if (!convertOk)
  {
    return;
  }

  if (itemIndex < m_MsgGen.getMessages().size() && itemIndex >= 0)
  {
    // get message to ignore and insert into ignore list
    const mg::Message& ignoreMsg = m_MsgGen.getMessages().at(itemIndex);
    ignoreMessage(ignoreMsg.getId());
  }
}

void Messenger::onWatch()
{
  if (m_UI.messageListIgnore->selectedItems().isEmpty())
  {
    return;
  }

  // get selected item from the ignore list, that we want to switch to watch list
  QListWidgetItem* selectedItem = m_UI.messageListIgnore->selectedItems()[0];
  if (!selectedItem)
  {
    return;
  }

  bool convertOk = false;
  uint32_t itemIndex = selectedItem->data(Qt::UserRole).toUInt(&convertOk);
  if (!convertOk)
  {
    return;
  }

  if (itemIndex < m_MsgGen.getMessages().size() && itemIndex >= 0)
  {
    // get message to ignore and insert into ignore list
    const mg::Message& ignoreMsg = m_MsgGen.getMessages().at(itemIndex);
    m_IgnoreList.erase(ignoreMsg.getId());


    // copy item over to ignore list
    m_UI.messageListWatch->addItem(new QListWidgetItem(*selectedItem));

    // remove the item from watch list
    m_UI.messageListIgnore->removeItemWidget(selectedItem);
    delete selectedItem;
  }
}

void Messenger::onConnect()
{
  std::string ipAddressStd = m_UI.lineEditAddress->text().toStdString();
  const char* ipAddress = ipAddressStd.c_str();
  int port = m_UI.spinBoxPort->value();

  connectToTarget(ipAddress, port);
}

void Messenger::onDisconnect()
{
  disconnectFromTarget();
}

} // namespace gde