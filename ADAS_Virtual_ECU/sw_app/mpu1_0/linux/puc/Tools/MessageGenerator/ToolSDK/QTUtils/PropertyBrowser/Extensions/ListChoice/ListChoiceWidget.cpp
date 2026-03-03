#include "ListChoiceWidget.h"

#include <QFileDialog>
#include <QToolButton>
#include <QLineEdit>
#include <QBoxLayout>
#include <QApplication>

ListChoiceWidget::ListChoiceWidget(QWidget *parent)
  : QWidget(parent)
  , m_Button(new QToolButton(this))
  , m_LineEdit(new QLineEdit)
  , m_ListName("List")
{
  QHBoxLayout* lt = new QHBoxLayout(this);
  enum { DecorationMargin = 4 };
  if (QApplication::layoutDirection() == Qt::LeftToRight)
    lt->setContentsMargins(DecorationMargin, 0, 0, 0);
  else
    lt->setContentsMargins(0, 0, DecorationMargin, 0);
  
  lt->setSpacing(0);
  lt->addWidget(m_LineEdit);
  lt->addItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Ignored));
  
  m_Button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Ignored);
  m_Button->setFixedWidth(40);

  setFocusProxy(m_Button);
  setFocusPolicy(m_Button->focusPolicy());

  m_Button->setText(tr("..."));
  connect(m_Button, SIGNAL(clicked()), this, SLOT(buttonClicked()));

  lt->addWidget(m_Button);
}

void ListChoiceWidget::setListName(const QString& listName)
{
  m_ListName = listName;
  m_LineEdit->setText(listName);
}

void ListChoiceWidget::setListItems(const QList<ListDialogItemData>& items)
{
  m_ListItems = items;
}

void ListChoiceWidget::setSelection(const QVariant& value)
{
  m_UserData = value;
}

void ListChoiceWidget::buttonClicked()
{
  ListDialog dlg(this);

  dlg.setListValues(m_ListItems);

  // exec dialog, dont care about ok / cancel buttons
  if (dlg.exec() == QDialog::Accepted)
  {
    QVariant dlgUserData;
    if (dlg.getSelectionUserData(dlgUserData))
    {
      setSelection(dlgUserData);
      emit userDataChanged(dlgUserData);
    }
  }
}

