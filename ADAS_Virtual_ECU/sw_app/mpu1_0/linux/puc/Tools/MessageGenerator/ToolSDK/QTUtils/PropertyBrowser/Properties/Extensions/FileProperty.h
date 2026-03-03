#pragma once

#include <platform/PlatformAPI.h>

#include "QtUtils/PropertyBrowser/Properties/BaseProperty.h"

class QtProperty;
class FilePathManager;

namespace tsdk
{

class PropertyFactory;

class FileProperty : public BaseProperty
{
  Q_OBJECT

public:
  FileProperty();
  virtual ~FileProperty();

  virtual void init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b) override;
  virtual QtProperty* getTopLevelProperty() const;

  void setFilePath(const QString& path);
  void setFilter(const QString& filter);

signals:
  void fileChanged(const QString& value);

private slots:
  void valueChanged(QtProperty* i_Property_po, const QString& value);

private:
  QtProperty*       fileProp_po;
  FilePathManager*  fileManager_po;
  bool              ignoreUpdates_b;
};


} // namespace ce

