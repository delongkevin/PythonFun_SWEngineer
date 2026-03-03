#include "FileEditWidget.h"

#include <QFileDialog>
#include <QToolButton>
#include <QLineEdit>
#include <QBoxLayout>
#include <QApplication>

FileEditWidget::FileEditWidget(QWidget *parent) 
  : QWidget(parent)
  , m_button(new QToolButton)
  , m_LineEdit(new QLineEdit)
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

  m_button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Ignored);
  m_button->setFixedWidth(40);

  setFocusProxy(m_button);
  setFocusPolicy(m_button->focusPolicy());

  m_button->setText(tr("..."));
  connect(m_button, SIGNAL(clicked()), this, SLOT(buttonClicked()));

  lt->addWidget(m_button);
}

void FileEditWidget::setFilePath(const QString& val)
{
  m_LineEdit->setText(val);
}

void FileEditWidget::setFilter(const QString& val)
{
  m_Filter = val;
}

void FileEditWidget::buttonClicked()
{
  QString oldFilePath = m_LineEdit->text();
  QString newFilePath = QFileDialog::getOpenFileName(this, tr("Open File"), "",  m_Filter);
  if (oldFilePath != newFilePath && !newFilePath.isEmpty())
  {
    setFilePath(newFilePath);
    emit filePathChanged(newFilePath);
  }

}
