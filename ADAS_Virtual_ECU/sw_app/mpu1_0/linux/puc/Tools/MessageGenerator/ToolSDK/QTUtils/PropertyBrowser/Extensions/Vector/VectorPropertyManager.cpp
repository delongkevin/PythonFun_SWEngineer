#include "VectorPropertyManager.h"


VectorPropertyManager::VectorPropertyManager(QObject* parent /*= 0*/)
  : QtAbstractPropertyManager(parent)
{

}

VectorPropertyManager::~VectorPropertyManager()
{

}

QString VectorPropertyManager::vectorName(const QtProperty *property) const
{
  if (!theValues.contains(property)) 
    return "";

  return theValues[property].vectorName;
}

uint32_t VectorPropertyManager::numValues(const QtProperty* property) const
{
  if (!theValues.contains(property)) 
    return 0;

  return theValues[property].numValues;
}

QWidget* VectorPropertyManager::propertyWidget(QtProperty* property) const
{
  if (!theValues.contains(property)) 
    return 0;

  return theValues[property].propertyWidget;
}

void VectorPropertyManager::setVectorName(QtProperty* property, const QString& vecName)
{
  if (!theValues.contains(property)) 
    return;

  Data data = theValues[property];
  if (data.vectorName == vecName) 
    return;

  data.vectorName = vecName;
  theValues[property] = data;

  emit propertyChanged(property);
}

void VectorPropertyManager::setNumValues(QtProperty* property, uint32_t numVals)
{
  if (!theValues.contains(property)) 
    return;

  Data data = theValues[property];
  if (data.numValues == numVals) 
    return;

  data.numValues = numVals;
  theValues[property] = data;

  emit propertyChanged(property);
  emit signalSetNumValues(property, data.numValues);
}

void VectorPropertyManager::setPropertyWidget(QtProperty* property, QWidget* propWidget)
{
  if (!theValues.contains(property)) 
    return;

  Data data = theValues[property];
  if (data.propertyWidget == propWidget) 
    return;

  data.propertyWidget = propWidget;
  theValues[property] = data;

  emit propertyChanged(property);
}

void VectorPropertyManager::addValue(QtProperty* property)
{
  if (!theValues.contains(property)) return;

  theValues[property].numValues++;

  emit propertyChanged(property);
  emit signalAddValue(property);
}

void VectorPropertyManager::deleteValue(QtProperty* property, uint32_t index)
{
  if (!theValues.contains(property)) return;

  Data data = theValues[property];
  if (data.numValues > 0)
  {
    --theValues[property].numValues;
  }

  emit propertyChanged(property);
  emit signalDeleteValue(property, index);
}

void VectorPropertyManager::deleteAll(QtProperty* property)
{
  if (!theValues.contains(property)) return;

  theValues[property].numValues = 0;

  emit propertyChanged(property);
  emit signalDeleteAll(property);
}

