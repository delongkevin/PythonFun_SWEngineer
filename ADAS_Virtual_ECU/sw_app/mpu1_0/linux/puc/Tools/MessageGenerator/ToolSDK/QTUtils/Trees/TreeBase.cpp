#include "TreeBase.h"

#include <QMenu>
#include <QEvent>
#include <QTreeWidgetItem>
#include <QEvent.h>

#include <platform/PlatformAPI.h>

#include <QtUtils/Resources/Icons.h>

#include "QTUtils/Trees/Items/FolderItem.h"

TreeBase::TreeBase(QWidget *parent /*= 0*/)
  : QTreeWidget(parent)
{
  // the tracked context menu item
  contextMenuItem = nullptr;

  // connect TreeWidget signals and slots
  connect(this, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(treeItemChanged(QTreeWidgetItem*, int)));
  connect(this, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(treeItemClicked(QTreeWidgetItem*, int)));
  connect(this, SIGNAL(itemExpanded(QTreeWidgetItem*)), this, SLOT(treeItemExpanded(QTreeWidgetItem*)));
  connect(this, SIGNAL(itemCollapsed(QTreeWidgetItem*)), this, SLOT(treeItemCollapsed(QTreeWidgetItem*)));


  // delete item action
  deleteItemAction = new QAction(tsdk::Icons::Get()->Delete, tr("&Delete"), this);
  deleteItemAction->setShortcut(QKeySequence::Delete);
  deleteItemAction->setShortcutContext(Qt::WidgetWithChildrenShortcut);
  connect(deleteItemAction, SIGNAL(triggered()), this, SLOT(actionDeleteItem()));
  addAction(deleteItemAction);
}

TreeBase::~TreeBase()
{

}

QMenu* TreeBase::onCreateContextMenu(TreeItemBase* treeItem)
{
  return nullptr;
}

void TreeBase::onTreeItemChanged(TreeItemBase* treeItem, int column)
{

}

void TreeBase::onTreeItemClicked(TreeItemBase* treeItem, int column)
{

}

void TreeBase::onTreeItemDeleted(TreeItemBase* treeItem)
{

}

void TreeBase::addItem(TreeItemBase* treeItem, QTreeWidgetItem* parent)
{
  Assert(treeItem != nullptr);

  treeItem->onAdd();

  if (parent == nullptr)
  {
    addTopLevelItem(treeItem);
  }
  else
  {
    parent->addChild(treeItem);
    parent->setExpanded(true);
  }
}

void TreeBase::deleteItem(TreeItemBase* treeItem)
{
  Assert(nullptr != treeItem);

  // call onDelete for all TreeItemBase classes
  if (treeItem)
  {
    deleteItemRecursive(treeItem);
  }

  // delete from tree
  if (treeItem != nullptr)
  {
    if (treeItem->parent())
    {
      treeItem->parent()->removeChild(treeItem);
    }
    else
    {
      invisibleRootItem()->removeChild(treeItem);
    }
  }
}

TreeItemBase* TreeBase::getCurrentItem() const
{
  TreeItemBase* item = dynamic_cast<TreeItemBase*>(currentItem());
  Assert(nullptr != item);
  return item;
}

TreeItemBase* TreeBase::getContextMenuItem() const
{
  return contextMenuItem;
}

void TreeBase::deleteCurrentItem()
{
  TreeItemBase* item = getCurrentItem();
  deleteItem(item);
}

FolderItem* TreeBase::createFolderItem(const char* itemName, QTreeWidgetItem* parent, uint32_t userData)
{
  FolderItem* item = new FolderItem();
  item->setText(0, itemName);
  item->setFlags(item->flags() | Qt::ItemIsEditable);
  item->setData(0, Qt::UserRole, QVariant(userData));
  
  addItem(item, parent);
  
  return item;
}

void TreeBase::deleteItemRecursive(TreeItemBase* treeItem)
{
  for (int i = 0; i < treeItem->childCount(); ++i)
  {
    QTreeWidgetItem* currChild = treeItem->child(i);
    TreeItemBase* child = dynamic_cast<TreeItemBase*>(currChild);
    Assert(nullptr != child);

    if (child)
    {
      deleteItemRecursive(child);
    }
  }

  treeItem->onDelete();
  onTreeItemDeleted(treeItem);
}

void TreeBase::contextMenuEvent(QContextMenuEvent* evt)
{
  QTreeWidgetItem* item = itemAt(evt->pos());

  contextMenuItem = dynamic_cast<TreeItemBase*>(item);

  QMenu* menu = onCreateContextMenu(contextMenuItem);

  if (menu)
  {
    menu->exec(evt->globalPos());
  }

  delete menu;
  menu = nullptr;
}

void TreeBase::treeItemChanged(QTreeWidgetItem* item, int column)
{
  TreeItemBase* treeItemBase = dynamic_cast<TreeItemBase*>(item);
  Assert(nullptr != treeItemBase);

  if (treeItemBase)
  {
    treeItemBase->onChange();
  }

  onTreeItemChanged(treeItemBase, column);
}

void TreeBase::treeItemClicked(QTreeWidgetItem *item, int column)
{
  TreeItemBase* treeItemBase = dynamic_cast<TreeItemBase*>(item);
  Assert(nullptr != treeItemBase);

  if (treeItemBase)
  {
    treeItemBase->onClicked();
  }

  onTreeItemClicked(treeItemBase, column);
}

void TreeBase::treeItemExpanded(QTreeWidgetItem* item)
{
  TreeItemBase* treeItemBase = dynamic_cast<TreeItemBase*>(item);
  Assert(nullptr != treeItemBase);

  if (treeItemBase)
  {
    treeItemBase->onExpand();
  }
}

void TreeBase::treeItemCollapsed(QTreeWidgetItem* item)
{
  TreeItemBase* treeItemBase = dynamic_cast<TreeItemBase*>(item);
  Assert(nullptr != treeItemBase);

  if (treeItemBase)
  {
    treeItemBase->onCollapse();
  }
}

void TreeBase::actionDeleteItem()
{
  deleteCurrentItem();
}