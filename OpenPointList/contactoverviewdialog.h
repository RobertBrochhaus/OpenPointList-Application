#ifndef CONTACTOVERVIEWDIALOG_H
#define CONTACTOVERVIEWDIALOG_H

#include "contactlistmodel.h"
#include <QItemSelection>
#include <QDialog>

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

    void writeToFile(const QString &fileName);

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
