#include "VectorEditWidget.h"

#include <QFileDialog>
#include <QToolButton>
#include <QLineEdit>
#include <QBoxLayout>
#include <QApplication>

VectorEditWidget::VectorEditWidget(QWidget *parent)
  : QWidget(parent)
  , m_button(new QToolButton(this))
  , m_NumValues(0)
  , m_VectorName("Vector")
  , m_PropertyWidget(nullptr)
{
  QHBoxLayout* lt = new QHBoxLayout(this);
  enum { DecorationMargin = 4 };
  if (QApplication::layoutDirection() == Qt::LeftToRight)
    lt->setContentsMargins(DecorationMargin, 0, 0, 0);
  else
    lt->setContentsMargins(0, 0, DecorationMargin, 0);
  
  lt->setSpacing(0);
  lt->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Ignored));
  
  m_button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Ignored);
  m_button->setFixedWidth(40);

  setFocusProxy(m_button);
  setFocusPolicy(m_button->focusPolicy());

  m_button->setText(tr("..."));
  connect(m_button, SIGNAL(clicked()), this, SLOT(buttonClicked()));

  lt->addWidget(m_button);
}

void VectorEditWidget::setNumValues(uint32_t numVals)
{
  m_NumValues = numVals;
}

void VectorEditWidget::setVectorName(const QString& vecName)
{
  m_VectorName = vecName;
}

void VectorEditWidget::setPropertyWidget(QWidget* propertyWidget)
{
  m_PropertyWidget = propertyWidget;
}

void VectorEditWidget::buttonClicked()
{
  VectorDialog dlg(this);
  dlg.setRootItemName(m_VectorName);
  //dlg.setPropertyWidget(m_PropertyWidget);
  //dlg.setWindowModality(Qt::NonModal);

  // add numValues entries
  for (uint32_t i = 0; i < m_NumValues; ++i)
  {
    dlg.add();
  }

  // connect signal / slots
  connect(&dlg, SIGNAL(signalAdd()), this, SLOT(onAdd()));
  connect(&dlg, SIGNAL(signalDeleteItem(uint32_t)), this, SLOT(onDelete(uint32_t)));
  connect(&dlg, SIGNAL(signalDeleteAll()), this, SLOT(onDeleteAll()));

  // exec dialog, dont care about ok / cancel buttons
  dlg.exec();

  // disconnect signal / slots
  disconnect(&dlg, SIGNAL(signalAdd()), this, SLOT(onAdd()));
  disconnect(&dlg, SIGNAL(signalDeleteItem(uint32_t)), this, SLOT(onDelete(uint32_t)));
  disconnect(&dlg, SIGNAL(signalDeleteAll()), this, SLOT(onDeleteAll()));



  dlg.setPropertyWidget(nullptr);
  m_PropertyWidget = nullptr;
}

void VectorEditWidget::onAdd()
{
  ++m_NumValues;

  emit signalAddItem();
}

void VectorEditWidget::onDelete(uint32_t index)
{
  if (m_NumValues > 0)
  {
    --m_NumValues;
  }

  emit signalDeleteItem(index);
}

void VectorEditWidget::onDeleteAll()
{
  emit signalDeleteAll();
}

