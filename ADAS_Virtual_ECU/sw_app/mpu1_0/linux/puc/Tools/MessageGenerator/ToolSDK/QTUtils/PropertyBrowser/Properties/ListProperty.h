#pragma once

#include <QObject.h>
#include <QVariantList>
#include <platform/PlatformAPI.h>

#include "QtUtils/PropertyBrowser/Properties/BaseProperty.h"

class QtProperty;
class QtVariantPropertyManager;

namespace tsdk
{

class PropertyFactory;
class GroupProperty;

class ListProperty : public BaseProperty
{
  Q_OBJECT

public:
  ListProperty();
  virtual ~ListProperty();

  virtual void init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b) override;
  virtual QtProperty* getTopLevelProperty() const;

  void clear_v();
  void updateValues_v(QVariant::Type i_Type_ro, const QVariantList& i_Values_ro, sint32_t i_NumDecimals_s32 = 2);

public slots:
    void listItemChanged(QtProperty* property, const QVariant& i_Variant_ro);

signals:
    void onListItemChanged(uint32_t i_Index_u32, const QVariant& i_NewValue_ro);

private:
  GroupProperty* groupProp_po;
  QtVariantPropertyManager* variantManager_po;
};


} // namespace ce
