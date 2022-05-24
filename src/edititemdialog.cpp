#include "edititemdialog.h"
#include "ui_edititemdialog.h"

EditItemDialog::EditItemDialog(const ContactItem item, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditItemDialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("Add/Edit Contact Overview Entry"));

    m_item = item;

    ui->surnameEdit->setText(item.surname());
    ui->forenameEdit->setText(item.forename());
    ui->companyEdit->setText(item.company());
    ui->roleEdit->setText(item.role());
    ui->mailEdit->setText(item.mail());
    ui->phoneEdit->setText(item.phone());
}

EditItemDialog::~EditItemDialog()
{
    delete ui;
}

ContactItem EditItemDialog::item() const
{
    return m_item;
}

void EditItemDialog::on_buttonBox_accepted()
{
    m_item.setSurname(ui->surnameEdit->text());
    m_item.setForename(ui->forenameEdit->text());
    m_item.setCompany(ui->companyEdit->text());
    m_item.setRole(ui->roleEdit->text());
    m_item.setMail(ui->mailEdit->text());
    m_item.setPhone(ui->phoneEdit->text());
}

