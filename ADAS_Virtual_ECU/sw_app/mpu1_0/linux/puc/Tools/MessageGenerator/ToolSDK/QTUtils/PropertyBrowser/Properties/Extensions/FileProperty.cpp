#include "QtUtils/PropertyBrowser/Properties/Extensions/FileProperty.h"

#include <platform/PlatformAPI.h>

#include <qtpropertybrowser.h>
#include <qtpropertymanager.h>
#include <qttreepropertybrowser.h>

#include "QtUtils/PropertyBrowser/PropertyFactory.h"
#include "QtUtils/PropertyBrowser/Extensions/File/FilePathManager.h"

namespace tsdk
{

FileProperty::FileProperty()
  : BaseProperty()
  , fileProp_po(NULL)
  , fileManager_po(NULL)
  , ignoreUpdates_b(false)
{
}

FileProperty::~FileProperty()
{
}

void FileProperty::init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b)
{
  BaseProperty::init_v(b_PropFactory_po, i_GroupName_po, b_Parent_po, i_ReadOnly_b);

  fileManager_po = propFactory_po->getFileManager_po(i_ReadOnly_b);
  fileProp_po    = fileManager_po->addProperty(i_GroupName_po);

  fileManager_po->setValue(fileProp_po, "");
  fileManager_po->setFilter(fileProp_po, "");


  connect(fileManager_po, SIGNAL(valueChanged(QtProperty*, const QString&)), this, SLOT(valueChanged(QtProperty*, const QString&)));
}

QtProperty* FileProperty::getTopLevelProperty() const
{
  Assert(NULL != fileProp_po);
  return fileProp_po;
}

void FileProperty::setFilePath(const QString& path)
{
  fileManager_po->setValue(fileProp_po, path);
}

void FileProperty::setFilter(const QString& filter)
{
  fileManager_po->setFilter(fileProp_po, filter);
}

void FileProperty::valueChanged(QtProperty* i_Property_po, const QString& value)
{
  if (ignoreUpdates_b)
  {
    return;
  }

  if (fileProp_po == i_Property_po)
  {
    emit fileChanged(value);
  }
}

} // namespace ce