#include "contactoverviewdialog.h"
#include "edititemdialog.h"
#include "ui_contactoverviewdialog.h"
#include "contactlistmodel.h"
#include "sharedcontactlist.h"

#include <QMessageBox>
#include <QFileDialog>

ContactOverviewDialog::ContactOverviewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactOverviewDialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("Contact Overview"));

    m_contactlistModel = new ContactListModel(SharedContactList::instance()-> contactItems(), this);

    ui->tableView->setModel(m_contactlistModel);
    connect(ui->tableView->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(tableSelectionChanged(QItemSelection)));
    ui->tableView->setColumnWidth(0, this->width()/6);
    ui->tableView->setColumnWidth(1, this->width()/6);
    ui->tableView->setColumnWidth(2, this->width()/6);
    ui->tableView->setColumnWidth(3, this->width()/6);
    ui->tableView->setColumnWidth(4, this->width()/6);
    ui->tableView->setColumnWidth(5, this->width()/6);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

ContactOverviewDialog::~ContactOverviewDialog()
{
    delete ui;
}

void ContactOverviewDialog::tableSelectionChanged(const QItemSelection &selected){
    bool anySelected = selected.indexes().size() > 0;
    ui->RemoveContactButton->setEnabled(anySelected);
    ui->EditContactButton->setEnabled(anySelected);
}

void ContactOverviewDialog::on_EditContactButton_clicked()
{
    on_tableView_activated(ui->tableView->currentIndex());
}

void ContactOverviewDialog::on_AddContactButton_clicked()
{
    EditItemDialog editItemDialog(ContactItem(), this);
    if(editItemDialog.exec() == QDialog::Accepted) {
        m_contactlistModel->addItem(editItemDialog.item());
    }
}

void ContactOverviewDialog::on_RemoveContactButton_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if(index.row() >= 0 && index.row() < m_contactlistModel->rowCount()){
        if(QMessageBox::question(this, "Remove item", "Do you really want to remove this item?", "Yes delete it", "No Keep it") == 0){
            m_contactlistModel->removeRow(index.row());
        }
    }
}

void ContactOverviewDialog::on_tableView_activated(const QModelIndex &index)
{
    if(index.row() >= 0 && index.row() < m_contactlistModel->rowCount()){
        EditItemDialog editItemDialog(SharedContactList::instance()->contactItems()->at(index.row()), this);
        if(editItemDialog.exec() == QDialog::Accepted){
            m_contactlistModel->updateItem(index.row(), editItemDialog.item());
        }
    }
}
void ContactOverviewDialog::mousePressEvent(QMouseEvent *event)
{
  ui->tableView->clearSelection();
}

void ContactOverviewDialog::on_pushButtonSave_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    if (!fileName.isEmpty()){
        ContactOverviewDialog::writeToFile(fileName);
    }
}

void ContactOverviewDialog::writeToFile(const QString &fileName)
{
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        return;
    }

    QDataStream out(&file);
    out << m_contactlistModel->getContactItems();
}

void ContactOverviewDialog::on_pushButtonLoad_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty())
        ContactOverviewDialog::readFromFile(fileName);
}

void ContactOverviewDialog::readFromFile(const QString &fileName)
{
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
            file.errorString());
        return;
    }

    QList<ContactItem> m_contactItems;

    QDataStream in(&file);
    in >> m_contactItems;

    if (m_contactItems.isEmpty()) {
        QMessageBox::information(this, tr("No OpenList Item in file"),
                                 tr("The file does not contain any OpenList Item."));
    } else {
        for (const auto &contact: qAsConst(m_contactItems))
            m_contactlistModel->addItem(contact);
    }
}

void ContactOverviewDialog::on_actionLoad_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty())
        ContactOverviewDialog::readFromFile(fileName);
}
