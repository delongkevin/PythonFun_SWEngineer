#pragma once

#include <QTreeWidget>

class TreeItemBase;
class FolderItem;

class TreeBase : public QTreeWidget
{
  Q_OBJECT
public:
  TreeBase(QWidget *parent = 0);
  virtual ~TreeBase();

  // override this method to create custom context menus. if no context menu is needed, just return nullptr
  virtual QMenu* onCreateContextMenu(TreeItemBase* treeItem);
  virtual void onTreeItemChanged(TreeItemBase* treeItem, int column);
  virtual void onTreeItemClicked(TreeItemBase* treeItem, int column);
  virtual void onTreeItemDeleted(TreeItemBase* treeItem);

  void addItem(TreeItemBase* treeItem, QTreeWidgetItem* parent);
  void deleteItem(TreeItemBase* treeItem);
  TreeItemBase* getCurrentItem() const;
  TreeItemBase* getContextMenuItem() const;
  void deleteCurrentItem();

  FolderItem* createFolderItem(const char* itemName, QTreeWidgetItem* parent, unsigned int userData);

private:
  void deleteItemRecursive(TreeItemBase* treeItem);

  virtual void contextMenuEvent(QContextMenuEvent* evt) override;
  
private slots:
  void treeItemChanged(QTreeWidgetItem* item, int column);
  void treeItemClicked(QTreeWidgetItem *item, int column);
  void treeItemExpanded(QTreeWidgetItem* item);
  void treeItemCollapsed(QTreeWidgetItem* item);

private slots:
  void actionDeleteItem();

protected:
  QAction*         deleteItemAction;

private:
  TreeItemBase*    contextMenuItem;
};