#ifndef EDITOPENPOINTITEMDIALOG_H
#define EDITOPENPOINTITEMDIALOG_H

#include "openpointlistmodel.h"
#include "qcombobox.h"
#include "qdatetimeedit.h"
#include "qlineedit.h"
#include "qtextedit.h"
#include <QDialog>

namespace Ui {
class EditOpenPointItemDialog;
}

class EditOpenPointItemDialog : public QDialog
{
    Q_OBJECT

public:
    EditOpenPointItemDialog(QWidget *parent = nullptr);
    ~EditOpenPointItemDialog();

    QString subject() const;
    QString task() const;
    QString result() const;
    QString risk() const;
    QDate   schedulefinish() const;
    QString responsible() const;
    QDate   entrydate() const;
    QString status() const;

    void editOpenPointListItem(const QString &subject, const QString &task, const QString &result, const QString &risk, const QDate &schedulefinish, const QString &responsible, const QDate &entrydate, const QString &status);

private slots:


private:
    Ui::EditOpenPointItemDialog *ui;
};

#endif // EDITOPENPOINTITEMDIALOG_H
