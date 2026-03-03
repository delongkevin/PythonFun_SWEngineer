#include "osal/networking/UDPSenderReceiver.h"

#include "MessageGenerator.h"
#include "QApplication"
#include "Messenger.h"


void startUiVersion( QApplication& application )
{
  messenger::Messenger* msgApp = new messenger::Messenger();
  msgApp->setAttribute(Qt::WA_DeleteOnClose);
  msgApp->show();
  
  //msgApp->loadSettings("MessengerSettings.xml");
  // set data editor active and execute
  application.setActiveWindow(msgApp);
  application.exec();
}

int main(int argc, char *argv[])
{
  QApplication application(argc, argv);

  startUiVersion(application);

  return 0;
}