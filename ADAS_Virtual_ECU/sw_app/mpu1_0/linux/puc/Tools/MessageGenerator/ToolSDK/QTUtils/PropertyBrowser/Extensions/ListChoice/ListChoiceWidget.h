#pragma once

#include <QWidget>

#include "ListChoiceManager.h"
#include "QTUtils/Dialogs/ListDialog.h"

class QToolButton;
class QLineEdit;

class ListChoiceWidget : public QWidget
{
  Q_OBJECT
public:
  ListChoiceWidget(QWidget *parent);
  void setListName(const QString& listName);
  void setListItems(const QList<ListDialogItemData>& items);
  void setSelection(const QVariant& value);

signals:
  void userDataChanged(const QVariant& val);

private Q_SLOTS:
  void buttonClicked();


private:    
  QToolButton* m_Button;
  QLineEdit*   m_LineEdit;
  QString      m_ListName;
  QVariant     m_UserData;
  QList<ListDialogItemData> m_ListItems;
};
