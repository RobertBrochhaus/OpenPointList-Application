
#include "editopenpointitemdialog.h"
#include "ui_editopenpointitemdialog.h"

EditOpenPointItemDialog::EditOpenPointItemDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditOpenPointItemDialog)
{
    ui->setupUi(this);

    setWindowTitle(tr("Add/Edit OpenPointList Entry"));
    ui->scheduledfinishdateEdit->setDate(QDate::currentDate());
    ui->entrydatedateEdit->setDate(QDate::currentDate());

}

EditOpenPointItemDialog::~EditOpenPointItemDialog()
{
    delete ui;
}

QString EditOpenPointItemDialog::subject() const
{
    return ui->subjectlineEdit->text();
}

QString EditOpenPointItemDialog::task() const
{
    return ui->tasktextEdit->toPlainText();
}

QString EditOpenPointItemDialog::result() const
{
    return ui->resultlineEdit->text();
}

QString EditOpenPointItemDialog::risk() const
{
    return ui->riskcomboBox->currentText();
}

QDate EditOpenPointItemDialog::schedulefinish() const
{
    return ui->scheduledfinishdateEdit->date();
}

QString EditOpenPointItemDialog::responsible() const
{
    return ui->responsiblelineEdit->text();
}

QDate EditOpenPointItemDialog::entrydate() const
{
    return ui->entrydatedateEdit->date();
}

QString EditOpenPointItemDialog::status() const
{
    return ui->statuscomboBox->currentText();
}

void EditOpenPointItemDialog::editOpenPointListItem(const QString &subject, const QString &task, const QString &result, const QString &risk, const QDate &schedulefinish, const QString &responsible, const QDate &entrydate, const QString &status)
{
    ui->subjectlineEdit->setText(subject);
    ui->tasktextEdit->setPlainText(task);
    ui->resultlineEdit->setText(result);
    ui->riskcomboBox->setCurrentText(risk);
    ui->scheduledfinishdateEdit->setDate(schedulefinish);
    ui->responsiblelineEdit->setText(responsible);
    ui->entrydatedateEdit->setDate(entrydate);
    ui->statuscomboBox->setCurrentText(status);
}
