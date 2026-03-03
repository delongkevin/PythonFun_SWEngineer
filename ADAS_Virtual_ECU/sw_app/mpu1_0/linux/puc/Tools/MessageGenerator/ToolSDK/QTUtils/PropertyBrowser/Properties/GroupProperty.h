#pragma once

#include <platform/PlatformAPI.h>

#include "QtUtils/PropertyBrowser/Properties/BaseProperty.h"

class QtProperty;

namespace tsdk
{

  class PropertyFactory;

  class GroupProperty : public BaseProperty
  {
    Q_OBJECT

  public:
    GroupProperty();
    virtual ~GroupProperty();

    virtual void init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b) override;
    virtual QtProperty* getTopLevelProperty() const;

  private:
    QtProperty* groupProp_po;
  };


} // namespace ce
