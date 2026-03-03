#pragma once

#include <QDialog>
#include <QIcon>
#include <QVariant>

class QString;
class QListWidgetItem;


namespace Ui
{
  class ListDialogUi;
}


struct ListDialogItemData
{
  QString   Text;
  QVariant  UserData;

  bool operator==(const ListDialogItemData &other) const
  {
    return Text == other.Text &&
           UserData == other.UserData;
  }

};

class ListDialog : public QDialog
{
	Q_OBJECT

public:
	ListDialog(QWidget* parent = nullptr);
	~ListDialog();

  bool getSelectionUserData(QVariant& userData) const;

	void setListValues(const QList<ListDialogItemData>& items);
  void setSelection(const QVariant& selectedUserData);

  bool isValid() const;

private slots:
	void selectionChanged(QListWidgetItem* item);

private:
	Ui::ListDialogUi*    m_Ui;
  QVariant             m_SelectedUserData;
  QListWidgetItem*     m_SelectedItem;
};
