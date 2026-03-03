#include "ListProperty.h"

#include <qtpropertybrowser.h>
#include <qtpropertymanager.h>
#include <qttreepropertybrowser.h>
#include <QtVariantProperty>

#include "QtUtils/PropertyBrowser/PropertyFactory.h"
#include "QtUtils/PropertyBrowser/Properties/GroupProperty.h"

namespace tsdk
{

ListProperty::ListProperty()
  : BaseProperty()
  , groupProp_po(NULL)
  , variantManager_po(NULL)
{

}

ListProperty::~ListProperty()
{
}

void ListProperty::init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b)
{
  BaseProperty::init_v(b_PropFactory_po, i_GroupName_po, b_Parent_po, i_ReadOnly_b);

  groupProp_po = propFactory_po->createProperty_po<GroupProperty>(i_GroupName_po, b_Parent_po, false);

  variantManager_po = propFactory_po->getVariantManager_po(i_ReadOnly_b);

  connect(variantManager_po, SIGNAL(valueChanged(QtProperty*, const QVariant&)), this, SLOT(listItemChanged(QtProperty*, const QVariant&)));
}

QtProperty* ListProperty::getTopLevelProperty() const
{
  return groupProp_po->getTopLevelProperty();
}

void ListProperty::clear_v()
{
  foreach(QtProperty* item, groupProp_po->getTopLevelProperty()->subProperties())
  {
    groupProp_po->getTopLevelProperty()->removeSubProperty(item);
  }
}

void ListProperty::updateValues_v(QVariant::Type i_Type_ro, const QVariantList& i_Values_ro, sint32_t i_NumDecimals_s32)
{
  while (groupProp_po->getTopLevelProperty()->subProperties().size() < i_Values_ro.size())
  {
    QString v_IndexName_o = QString::number(groupProp_po->getTopLevelProperty()->subProperties().size());
    QtProperty* v_SubProperty_Po = variantManager_po->addProperty(i_Type_ro, v_IndexName_o);
    variantManager_po->setAttribute(v_SubProperty_Po, QLatin1String("decimals"), QVariant(i_NumDecimals_s32));
    groupProp_po->getTopLevelProperty()->addSubProperty(v_SubProperty_Po);
  }

  uint v_Index_u32 = 0U;
  foreach(QVariant v_Value_ro, i_Values_ro)
  {
    QtProperty* v_SubProperty_Po = groupProp_po->getTopLevelProperty()->subProperties().at(v_Index_u32);
    variantManager_po->setValue(v_SubProperty_Po, v_Value_ro);

    ++v_Index_u32;
  }
}

void ListProperty::listItemChanged(QtProperty* property, const QVariant& i_Variant_ro)
{
  foreach(QtProperty* item, groupProp_po->getTopLevelProperty()->subProperties())
  {
    if (property == item)
    {
      QString v_IndexName_o = item->propertyName();
      emit onListItemChanged(v_IndexName_o.toUInt(), i_Variant_ro);

      break;
    }

  }
}

} // namespace ce