#include "VectorDialog.h"

VectorDialog::VectorDialog(QWidget* parent /*= nullptr*/)
{
	ui.setupUi(this);

	connect(ui.AddButton, SIGNAL(clicked()), this, SLOT(add()));
	connect(ui.UpButton, SIGNAL(clicked()), this, SLOT(up()));
	connect(ui.DownButton, SIGNAL(clicked()), this, SLOT(down()));
	connect(ui.DeleteButton, SIGNAL(clicked()), this, SLOT(deleteItem()));
	connect(ui.DeleteAllButton, SIGNAL(clicked()), this, SLOT(deleteAll()));
	
	rootItem = new QTreeWidgetItem();
	rootItem->setText(0, "Vector");
	ui.treeWidget->addTopLevelItem(rootItem);

  ui.buttonBox->button(QDialogButtonBox::Cancel)->setVisible(false);
}

VectorDialog::~VectorDialog()
{
}

void VectorDialog::setRootItemName(const QString& txt)
{
  rootItem->setText(0, txt);
}

void VectorDialog::setPropertyWidget(QWidget* propWidget)
{
  ui.PropertyWidget->setWidget(propWidget);
}

void VectorDialog::add()
{
	QTreeWidgetItem* item = new QTreeWidgetItem();

	rootItem->addChild(item);
  rootItem->setExpanded(true);

  // set name
  int index = rootItem->indexOfChild(item);
  item->setText(0, QString::number(index));

  emit signalAdd();
}

void VectorDialog::up()
{
	QTreeWidgetItem* item = ui.treeWidget->currentItem();
	int row = ui.treeWidget->currentIndex().row();
	if (item && row > 0)
	{
		QTreeWidgetItem* parent = item->parent();
		int index = parent->indexOfChild(item);
		QTreeWidgetItem* child = parent->takeChild(index);
		parent->insertChild(index - 1, child);
		ui.treeWidget->setCurrentItem(item);

		// update vector
		//std::swap(vectorItems.at(index - 1), vectorItems.at(index));

    emit signalUp(uint32_t(index - 1), uint32_t(index));
	}
}

void VectorDialog::down()
{
	QTreeWidgetItem* item = ui.treeWidget->currentItem();

	QTreeWidgetItem* parent = item->parent();
	if (!parent)
	{
		return;
	}

	int row = ui.treeWidget->currentIndex().row();
	if (item && row < parent->childCount() - 1)
	{
		int index = parent->indexOfChild(item);
		QTreeWidgetItem* child = parent->takeChild(index);
		parent->insertChild(index + 1, child);
		ui.treeWidget->setCurrentItem(item);

		// update vector
		//std::swap(vectorItems.at(index + 1), vectorItems.at(index));

    emit signalDown(uint32_t(index + 1), uint32_t(index));
	}
}

void VectorDialog::deleteItem()
{
	QTreeWidgetItem* item = ui.treeWidget->currentItem();
	
	// don't do this for root items
	QTreeWidgetItem* parent = item->parent();
	if (parent == nullptr)
	{
		return;
	}

	// save index before deletion
	int index = parent->indexOfChild(item);
	parent->removeChild(item);

  updateTreeItemNames();

	// update vector
	//vectorItems.erase(vectorItems.begin() + index);

  emit signalDeleteItem(uint32_t(index));
}

void VectorDialog::deleteAll()
{
	for (int i = 0; i < ui.treeWidget->topLevelItemCount(); ++i)
	{
		qDeleteAll(ui.treeWidget->topLevelItem(i)->takeChildren());
	}

	//vectorItems.clear();

  emit signalDeleteAll();
}

void VectorDialog::updateTreeItemNames()
{
  QTreeWidgetItemIterator it(ui.treeWidget);
  uint32_t index = 0;

  while (*it) 
  {
    if ( (*it) != rootItem)
    {
      (*it)->setText(0, QString::number(index++));
    }

    ++it;
  }
}
