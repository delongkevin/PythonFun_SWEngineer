#pragma once

#include <QtUtils/PropertyBrowser/Properties/BaseProperty.h>

#include <vector>

class VectorPropertyManager;

namespace tsdk
{
class PropertyFactory;

class VectorProperty : public tsdk::BaseProperty
{

Q_OBJECT

public:
  VectorProperty();
  virtual ~VectorProperty();

  virtual void init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b) override;
  virtual QtProperty* getTopLevelProperty() const;

  void setNumValues(uint32_t numVals);
  void setName(const QString& vecName);
  void setPropertyWidget(QWidget* propWidget);

private slots:
  void slotAddValue(QtProperty* prop);
  void slotDeleteValue(QtProperty* prop, uint32_t index);
  void slotDeleteAll(QtProperty* prop);

signals:
  void signalAddValue();
  void signalDeleteValue(uint32_t index);
  void signalDeleteAll();

private:
  QtProperty*             vectorProp_po;
  bool                    ignoreUpdates_b;
  VectorPropertyManager*  vectorManager_po;
};


} // namespace tsdk