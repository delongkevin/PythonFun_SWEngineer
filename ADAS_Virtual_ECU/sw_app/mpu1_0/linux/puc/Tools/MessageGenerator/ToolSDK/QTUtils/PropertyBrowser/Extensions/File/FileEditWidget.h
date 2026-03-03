#pragma once

#include <QWidget>

class QToolButton;
class QLineEdit;

class FileEditWidget : public QWidget
{
	Q_OBJECT
public:
	FileEditWidget(QWidget *parent);

	void setFilePath(const QString& val);
	void setFilter(const QString& val);

signals:
	void filePathChanged(const QString& val);

private Q_SLOTS:
    void buttonClicked();


private:    
  QToolButton* m_button;
  QLineEdit*   m_LineEdit;
  QString      m_Filter;
 };
