#include "ListDialog.h"
#include <QDialogButtonBox>
#include <QPushButton>

#include "ui_ListDialog.h"


ListDialog::ListDialog(QWidget* parent /*= nullptr*/)
  : QDialog(parent)
  , m_SelectedItem(nullptr)
{
  m_Ui = new Ui::ListDialogUi();
	m_Ui->setupUi(this);

	connect(m_Ui->ListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(selectionChanged(QListWidgetItem*)));

	m_Ui->ButtonBox->button(QDialogButtonBox::Ok)->setEnabled(isValid());
}

ListDialog::~ListDialog()
{

}

bool ListDialog::getSelectionUserData(QVariant& userData) const
{
  if (m_SelectedItem)
  {
    userData = m_SelectedItem->data(Qt::UserRole);
    return true;
  }
  else
  {
    return false;
  }
}

void ListDialog::setListValues(const QList<ListDialogItemData>& items)
{
  m_Ui->ListWidget->clear();

  for (int i = 0; i < items.size(); ++i)
  {
    QListWidgetItem* item = new QListWidgetItem();

    //item->setIcon(QIcon(items[i].Icon));
    item->setText(items[i].Text);
    item->setData(Qt::UserRole, items[i].UserData);

    m_Ui->ListWidget->addItem(item);
  }
}

void ListDialog::setSelection(const QVariant& selectedUserData)
{
  // TODO
}

bool ListDialog::isValid() const
{
  return m_SelectedItem != nullptr;
}

void ListDialog::selectionChanged(QListWidgetItem* item)
{
  m_SelectedItem = item;

  m_Ui->ButtonBox->button(QDialogButtonBox::Ok)->setEnabled(isValid());
}
