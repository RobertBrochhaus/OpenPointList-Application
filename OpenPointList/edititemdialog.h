#ifndef EDITITEMDIALOG_H
#define EDITITEMDIALOG_H

#include <QDialog>

#include "contactitem.h"

namespace Ui {
class EditItemDialog;
}

class EditItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditItemDialog(const ContactItem item, QWidget *parent = nullptr);
    ~EditItemDialog();

    ContactItem item() const;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::EditItemDialog *ui;
    ContactItem m_item;
};

#endif // EDITITEMDIALOG_H
