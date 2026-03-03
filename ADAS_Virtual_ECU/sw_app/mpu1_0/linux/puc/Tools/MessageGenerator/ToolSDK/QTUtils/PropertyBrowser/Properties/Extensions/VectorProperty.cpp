#include "VectorProperty.h"

#include <qttreepropertybrowser.h>

#include "QTUtils/PropertyBrowser/PropertyFactory.h"
#include "QTUtils/PropertyBrowser/Properties/BaseProperty.h"
#include <QtUtils/PropertyBrowser/Extensions/Vector/VectorPropertyManager.h>

namespace tsdk
{

VectorProperty::VectorProperty()
  : BaseProperty()
  , vectorProp_po(NULL)
  , ignoreUpdates_b(false)
  , vectorManager_po(NULL)
{

}

VectorProperty::~VectorProperty()
{

}

void VectorProperty::init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b)
{
  BaseProperty::init_v(b_PropFactory_po, i_GroupName_po, b_Parent_po, i_ReadOnly_b);

  vectorManager_po = propFactory_po->getVectorManager_po(i_ReadOnly_b);

  vectorProp_po = vectorManager_po->addProperty(i_GroupName_po);

  connect(vectorManager_po, SIGNAL(signalAddValue(QtProperty*)), 
          this, SLOT(slotAddValue(QtProperty*)));

  connect(vectorManager_po, SIGNAL(signalDeleteValue(QtProperty*, uint32_t)), 
          this, SLOT(slotDeleteValue(QtProperty*, uint32_t)));

  connect(vectorManager_po, SIGNAL(signalDeleteAll(QtProperty*)), 
          this, SLOT(slotDeleteAll(QtProperty*)));
}

QtProperty* VectorProperty::getTopLevelProperty() const
{
  return vectorProp_po;
}

void VectorProperty::setNumValues(uint32_t numVals)
{
  vectorManager_po->setNumValues(vectorProp_po, numVals);
}

void VectorProperty::setName(const QString& vecName)
{
  vectorManager_po->setVectorName(vectorProp_po, vecName);
}

void VectorProperty::setPropertyWidget(QWidget* propWidget)
{
  vectorManager_po->setPropertyWidget(vectorProp_po, propWidget);
}

void VectorProperty::slotAddValue(QtProperty* prop)
{
  if (ignoreUpdates_b)
  {
    return;
  }

  if (vectorProp_po == prop)
  {
    emit signalAddValue();
  }
}

void VectorProperty::slotDeleteValue(QtProperty* prop, uint32_t index)
{
  if (ignoreUpdates_b)
  {
    return;
  }

  if (vectorProp_po == prop)
  {
    emit signalDeleteValue(index);
  }
}

void VectorProperty::slotDeleteAll(QtProperty* prop)
{
  if (ignoreUpdates_b)
  {
    return;
  }

  if (vectorProp_po == prop)
  {
    emit signalDeleteAll();
  }
}

} // namespace tsdk