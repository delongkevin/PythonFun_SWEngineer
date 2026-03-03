#pragma once

#include <QDialog>

#include "ui_VectorDialog.h"

#include <platform/PlatformAPI.h>

class QTreeWidgetItem;

class VectorDialog : public QDialog
{
	Q_OBJECT

public:
	VectorDialog(QWidget* parent = nullptr);
	~VectorDialog();

  void setRootItemName(const QString& txt);
  void setPropertyWidget(QWidget* propWidget);

public slots:
	void add();
	void up();
	void down();
	void deleteItem();
	void deleteAll();

signals:
  void signalAdd();
  void signalUp(uint32_t leftIdx, uint32_t rightIdx);
  void signalDown(uint32_t leftIdx, uint32_t rightIdx);
  void signalDeleteItem(uint32_t index);
  void signalDeleteAll();

private:
  void updateTreeItemNames();

private:
	Ui::VectorDialogUi ui;
	QTreeWidgetItem* rootItem;
};
