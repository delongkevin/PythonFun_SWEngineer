#include "FilePathManager.h"


FilePathManager::FilePathManager(QObject* parent /*= 0*/)
  : QtAbstractPropertyManager(parent)
{

}

FilePathManager::~FilePathManager()
{

}

QString FilePathManager::value(const QtProperty *property) const
{
	// We return empty data from getter functions if an unknown property is supplied; otherwise we return the data from the property map: 
	if (!theValues.contains(property)) return "";
	return theValues[property].value;
}

QString FilePathManager::filter(const QtProperty *property) const
{
	if (!theValues.contains(property)) return "";
	return theValues[property].filter;
}

// In the setter functions, we ignore attempts to set the values of unknown properties, 
// and only commit new data to the property map. We emit the base class's propertyChanged() signal to notify
// other components of any changes. However, note that the setFilter() does not need to do this because it does not change the property's value. 
void FilePathManager::setValue(QtProperty* property, const QString& val)
{
	if (!theValues.contains(property)) return;
	Data data = theValues[property];
	if (data.value == val) return;
	data.value = val;
	theValues[property] = data;
	emit propertyChanged(property);
	emit valueChanged(property, data.value);
}

void FilePathManager::setFilter(QtProperty* property, const QString& val)
{
	if (!theValues.contains(property)) return;
	Data data = theValues[property];
	if (data.filter == val) return;
	data.filter = val;
	theValues[property] = data;
	emit propertyChanged(property);
  emit valueChanged(property, data.filter);
}
