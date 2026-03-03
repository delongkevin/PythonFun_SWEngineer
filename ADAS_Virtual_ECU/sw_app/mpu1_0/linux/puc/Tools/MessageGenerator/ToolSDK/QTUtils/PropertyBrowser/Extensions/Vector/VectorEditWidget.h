#pragma once

#include <QWidget>

#include "VectorPropertyManager.h"
#include "QTUtils/Dialogs/VectorDialog.h"

class QToolButton;
class QLineEdit;

class VectorEditWidget : public QWidget
{
  Q_OBJECT
public:
  VectorEditWidget(QWidget *parent);
  void setNumValues(uint32_t numVals);
  void setVectorName(const QString& vecName);
  void setPropertyWidget(QWidget* propertyWidget);

signals:
  void signalAddItem();
  void signalDeleteItem(uint32_t index);
  void signalDeleteAll();

private Q_SLOTS:
  void buttonClicked();
  void onAdd();
  void onDelete(uint32_t index);
  void onDeleteAll();

private:    
  QToolButton* m_button;
  uint32_t     m_NumValues;
  QString      m_VectorName;
  QWidget*     m_PropertyWidget;
};
