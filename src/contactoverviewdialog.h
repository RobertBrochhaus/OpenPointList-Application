#ifndef CONTACTOVERVIEWDIALOG_H
#define CONTACTOVERVIEWDIALOG_H

#include "contactlistmodel.h"
#include <QItemSelection>
#include <QDialog>
#include <QFile>

namespace Ui {
class ContactOverviewDialog;
}

class ContactOverviewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ContactOverviewDialog(QWidget *parent = nullptr);
    ~ContactOverviewDialog();

    void mousePressEvent(QMouseEvent *event);

    void writeToFile(QFile &file);

    void readFromFile(QFile &file);

    void addItem(ContactItem item);


private slots:

    void tableSelectionChanged(const QItemSelection &selected);

    void on_RemoveContactButton_clicked();

    void on_EditContactButton_clicked();

    void on_AddContactButton_clicked();

    void on_tableView_activated(const QModelIndex &index);


private:
    Ui::ContactOverviewDialog *ui;
    ContactListModel *m_contactlistModel;
};

#endif // CONTACTOVERVIEWDIALOG_H
