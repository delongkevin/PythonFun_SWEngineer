#pragma once

#include <qtpropertybrowser.h>

#include <QMap>
#include <platform/PlatformAPI.h>

class VectorPropertyManager : public QtAbstractPropertyManager
{
  Q_OBJECT
public:
  VectorPropertyManager(QObject* parent = 0);
  ~VectorPropertyManager();

  QString vectorName(const QtProperty *property) const;
  uint32_t numValues(const QtProperty* property) const;
  QWidget* propertyWidget(QtProperty* property) const;

public slots:
  void setVectorName(QtProperty* property, const QString& vecName);
  void setNumValues(QtProperty* property, uint32_t numVals);
  void setPropertyWidget(QtProperty* property, QWidget* propWidget);
  void addValue(QtProperty* property);
  void deleteValue(QtProperty* property, uint32_t index);
  void deleteAll(QtProperty* property);
    
signals:
  void signalSetNumValues(QtProperty* property, uint32_t numVals);
  void signalAddValue(QtProperty* property);
  void signalDeleteValue(QtProperty* property, uint32_t index);
  void signalDeleteAll(QtProperty* property);

protected:
  QString valueText(const QtProperty *property) const
  {
    return QString::number(numValues(property)); //value(property);
  }
  void initializeProperty(QtProperty *property)
  {
    Data data;
    data.numValues = 0;
    data.vectorName = "Vector";

    theValues[property] = data;
  }
  void uninitializeProperty(QtProperty *property)
  {
    theValues.remove(property);
  }
private:
  struct Data 
  {
    QString vectorName;
    uint32_t numValues;
    QWidget* propertyWidget;
  };
  QMap<const QtProperty *, Data> theValues;
};

