#pragma once

#include <qtpropertybrowser.h>

#include <QMap>

// Our custom FilePathManager is derived from the QtAbstractPropertyManager, enriching the interface with its attributes, 
// and providing the required getter and setter functions for our custom property. 
// The valueChanged() and filterChanged() signals are used to communicate with custom editor factories (shown later), 
// and can also be generally used to monitor properties. We define a simple data structure to store the state of the value 
// and filter for each file path property, and record each file path property in a private map.

//The FilePathManager must also reimplement several protected functions provided by its base class that are needed by the framework 
// : valueText() returns a string representation of the property's value, initializeProperty() initializes a new property, 
// and uninitializeProperty() is used to clean up when a property is deleted. 
class FilePathManager : public QtAbstractPropertyManager
{
	Q_OBJECT
public:
	FilePathManager(QObject* parent = 0);
	~FilePathManager();

	QString value(const QtProperty *property) const;
	QString filter(const QtProperty *property) const;
public slots:
	void setValue(QtProperty* property, const QString& val);
	void setFilter(QtProperty* property, const QString& val);
signals:
	void valueChanged(QtProperty* property, const QString& val);
	void filterChanged(QtProperty* property, const QString& val);
protected:
	QString valueText(const QtProperty *property) const
	{
		return value(property);
	}
	void initializeProperty(QtProperty *property)
	{
		theValues[property] = Data();
	}
	void uninitializeProperty(QtProperty *property)
	{
		theValues.remove(property);
	}
private:
	struct Data {
		QString value;
		QString filter;
	};
	QMap<const QtProperty *, Data> theValues;
};