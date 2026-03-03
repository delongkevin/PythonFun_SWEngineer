#include "QtUtils/PropertyBrowser/Properties/ComboBoxProperty.h"

#include <platform/PlatformAPI.h>

#include <qtpropertybrowser.h>
#include <qtpropertymanager.h>
#include <qttreepropertybrowser.h>
#include <QStringList>

#include "QtUtils/PropertyBrowser/PropertyFactory.h"

namespace tsdk
{

ComboBoxProperty::ComboBoxProperty()
  : BaseProperty()
  , enumManager_po(NULL)
  , enumProperty_po(NULL)
  , ignoreValueChanged_b(false)
{

}

ComboBoxProperty::~ComboBoxProperty()
{
}

void ComboBoxProperty::init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b)
{
  BaseProperty::init_v(b_PropFactory_po, i_GroupName_po, b_Parent_po, i_ReadOnly_b);

  enumManager_po  = propFactory_po->getEnumManager_po(i_ReadOnly_b);
  enumProperty_po = enumManager_po->addProperty(i_GroupName_po);

  connect(enumManager_po, SIGNAL(valueChanged(QtProperty*, int)), this, SLOT(valueChanged(QtProperty*, int)));
}

QtProperty* ComboBoxProperty::getTopLevelProperty() const
{
  Assert(NULL != enumProperty_po);
  return enumProperty_po;
}

void ComboBoxProperty::setValues_v(const QList<QString>& i_Values_ro)
{
  Assert(NULL != enumProperty_po);
  Assert(NULL != enumManager_po);

  ignoreValueChanged_b = true;

  enumManager_po->setEnumNames(enumProperty_po, i_Values_ro);

  ignoreValueChanged_b = false;
}

void ComboBoxProperty::select_v(const QString& i_Value_ro)
{
  ignoreValueChanged_b = true;

  sint32_t selectionIndex_s32 = findIndex_s32(i_Value_ro);
  if (selectionIndex_s32 != -1)
  {
    enumManager_po->setValue(enumProperty_po, selectionIndex_s32);
  }
  else
  {
    enumManager_po->setValue(enumProperty_po, 0);
  }

  ignoreValueChanged_b = false;
}

void ComboBoxProperty::valueChanged(QtProperty* i_Property_po, int i_Value_s32)
{
  if (ignoreValueChanged_b)
  {
    return;
  }

  if (enumProperty_po == i_Property_po)
  {
    const QStringList& v_Enums_ro = enumManager_po->enumNames(enumProperty_po);
    const QString& v_StringVal_o = v_Enums_ro.at(i_Value_s32);

    emit enumSelectionChanged(v_StringVal_o);
  }
}

sint32_t ComboBoxProperty::findIndex_s32(const QString& i_Name_ro)
{
  const QStringList& v_Enums_ro = enumManager_po->enumNames(enumProperty_po);
  sint32_t v_Index_s32 = -1;

  for (sint32_t i = 0; i < v_Enums_ro.size(); ++i)
  {
    const QString& v_Enum_ro = v_Enums_ro.at(i);
    if (v_Enum_ro == i_Name_ro)
    {
      v_Index_s32 = i;
    }

  }

  return v_Index_s32;
}

} // namespace ce