#include "QtUtils/PropertyBrowser/Properties/ColorProperty.h"

#include <platform/PlatformAPI.h>

#include <QColor.h>

#include <qtpropertybrowser.h>
#include <qtpropertymanager.h>
#include <qttreepropertybrowser.h>

#include "QtUtils/PropertyBrowser/PropertyFactory.h"

namespace ce
{

ColorProperty::ColorProperty()
  : BaseProperty()
  , colorProp_po(NULL)
  , colorManager_po(NULL)
  , ignoreUpdates_b(false)
{
}

ColorProperty::~ColorProperty()
{
}

void ColorProperty::init_v(tsdk::PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b)
{
  BaseProperty::init_v(b_PropFactory_po, i_GroupName_po, b_Parent_po, i_ReadOnly_b);

  colorManager_po = propFactory_po->getColorManager_po(i_ReadOnly_b);
  colorProp_po    = colorManager_po->addProperty(i_GroupName_po);

  connect(colorManager_po, SIGNAL(valueChanged(QtProperty*, const QColor&)), this, SLOT(valueChanged(QtProperty*, const QColor&)));
}

QtProperty* ColorProperty::getTopLevelProperty() const
{
  Assert(NULL != colorProp_po);
  return colorProp_po;
}

void ColorProperty::setColor(const QColor& i_Color_ro)
{
  ignoreUpdates_b = true;

  colorManager_po->setValue(colorProp_po, i_Color_ro);

  ignoreUpdates_b = false;
}

void ColorProperty::valueChanged(QtProperty* i_Property_po, const QColor& i_Color_ro)
{
  if (ignoreUpdates_b)
  {
    return;
  }

  if (colorProp_po == i_Property_po)
  {
    emit colorChanged(i_Color_ro);
  }
}

} // namespace ce