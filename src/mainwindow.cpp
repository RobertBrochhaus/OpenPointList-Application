#include "mainwindow.h"
#include "contactoverviewdialog.h"
#include "editopenpointitemdialog.h"
#include "ui_mainwindow.h"
#include "sharedcontactlist.h"
#include "contactlistmodel.h"

#include <QDialog>
#include <QSortFilterProxyModel>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , openpointlistModel(new OpenPointListModel(this))
{
    ui->setupUi(this);
    setStyleSheet(":/stylesheet.qss");

    ui->tableView->setModel(openpointlistModel);
    setWindowTitle(tr("OpenPointList Application"));

    connect(ui->tableView->selectionModel(), &QItemSelectionModel::selectionChanged,this, &MainWindow::selectionChanged);
    connect(ui->tableView->selectionModel(), &QItemSelectionModel::selectionChanged,this, &MainWindow::updateActions);

    ui->searchfilterlineEdit->setFixedWidth(120);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
  ui->tableView->clearSelection();
}

void MainWindow::resizeEvent(QResizeEvent *event) {

    ui->tableView->setColumnWidth(0, this->width()*0.125);
    ui->tableView->setColumnWidth(1, this->width()*0.225);
    ui->tableView->setColumnWidth(2, this->width()*0.125);
    ui->tableView->setColumnWidth(3, this->width()*0.025);
    ui->tableView->setColumnWidth(4, this->width()*0.125);
    ui->tableView->setColumnWidth(5, this->width()*0.125);
    ui->tableView->setColumnWidth(6, this->width()*0.125);
    ui->tableView->setColumnWidth(7, this->width()*0.125);

    QMainWindow::resizeEvent(event);
    ui->tableView->horizontalHeader()->setMaximumSectionSize(this->width());
}

void MainWindow::showAddEntryDialog()
{
    {
        EditOpenPointItemDialog editOpenPointDialog;

        if (editOpenPointDialog.exec())
            addEntry(editOpenPointDialog.subject(), editOpenPointDialog.task(), editOpenPointDialog.result(), editOpenPointDialog.risk(), editOpenPointDialog.schedulefinish(), editOpenPointDialog.responsible(), editOpenPointDialog.entrydate(), editOpenPointDialog.status());
    }
}

void MainWindow::addEntry(const QString &subject, const QString &task, const QString &result, const QString &risk, const QDate &schedulefinish, const QString &responsible, const QDate &entrydate, const QString &status)
{
    if (!openpointlistModel->getOpenPointItems().contains({ subject, task, result, risk, schedulefinish, responsible, entrydate, status })) {
        openpointlistModel->insertRows(0, 1, QModelIndex());

        QModelIndex
        index = openpointlistModel->index(0, 0, QModelIndex());
        openpointlistModel->setData(index, subject, Qt::EditRole);
        index = openpointlistModel->index(0, 1, QModelIndex());
        openpointlistModel->setData(index, task, Qt::EditRole);
        index = openpointlistModel->index(0, 2, QModelIndex());
        openpointlistModel->setData(index, result, Qt::EditRole);
        index = openpointlistModel->index(0, 3, QModelIndex());
        openpointlistModel->setData(index, risk, Qt::EditRole);
        index = openpointlistModel->index(0, 4, QModelIndex());
        openpointlistModel->setData(index, schedulefinish, Qt::EditRole);
        index = openpointlistModel->index(0, 5, QModelIndex());
        openpointlistModel->setData(index, responsible, Qt::EditRole);
        index = openpointlistModel->index(0, 6, QModelIndex());
        openpointlistModel->setData(index, entrydate, Qt::EditRole);
        index = openpointlistModel->index(0, 7, QModelIndex());
        openpointlistModel->setData(index, status, Qt::EditRole);

    } else {
        QMessageBox::information(this, tr("Duplicate Name"),
            tr("The name \"%1\" already exists.").arg(subject));
    }
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
     if(index.row() >= 0 && index.row() < 2){
        editEntry();
     }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateActions(const QItemSelection &selection)
{
    QModelIndexList indexes = selection.indexes();

    if (!indexes.isEmpty()) {
        ui->removeitempushButton->setEnabled(true);
        ui->edititempushButton->setEnabled(true);
    } else {
        ui->removeitempushButton->setEnabled(false);
        ui->edititempushButton->setEnabled(false);
    }
}

void MainWindow::on_pushButton_clicked()
{
   ContactOverviewDialog contactOverviewDialog;
   contactOverviewDialog.setModal(true);
   contactOverviewDialog.exec();
}

void MainWindow::on_additempushButton_clicked()
{
    EditOpenPointItemDialog editOpenPointDialog;

    if (editOpenPointDialog.exec())
        addEntry(editOpenPointDialog.subject(), editOpenPointDialog.task(), editOpenPointDialog.result(), editOpenPointDialog.risk(), editOpenPointDialog.schedulefinish(), editOpenPointDialog.responsible(), editOpenPointDialog.entrydate(), editOpenPointDialog.status());
}

void MainWindow::on_edititempushButton_clicked()
{
    editEntry();
}

void MainWindow::on_removeitempushButton_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if(index.row() >= 0 && index.row() < 2){
        if(QMessageBox::question(this, "Remove item", "Do you really want to remove this item?", "Yes delete it", "No Keep it") == 0){
            openpointlistModel->removeRow(index.row());
        }
    }
}

void MainWindow::editEntry()
{
    const QModelIndexList indexes = ui->tableView->selectionModel()->selectedRows();

    QString subject;
    QString task;
    QString result;
    QString risk;
    QDate schedulefinish;
    QString responsible;
    QDate entrydate;
    QString status;
    int row = -1;

    for (const QModelIndex &index : indexes) {
        row = index.row();
        QModelIndex subjectIndex = openpointlistModel->index(row, 0, QModelIndex());
        QVariant varSubject = openpointlistModel->data(subjectIndex, Qt::DisplayRole);
        subject = varSubject.toString();

        QModelIndex taskIndex = openpointlistModel->index(row, 1, QModelIndex());
        QVariant varTask = openpointlistModel->data(taskIndex, Qt::DisplayRole);
        task = varTask.toString();

        QModelIndex resultIndex = openpointlistModel->index(row, 2, QModelIndex());
        QVariant varResult = openpointlistModel->data(resultIndex, Qt::DisplayRole);
        result = varResult.toString();

        QModelIndex riskIndex = openpointlistModel->index(row, 3, QModelIndex());
        QVariant varRisk = openpointlistModel->data(riskIndex, Qt::DisplayRole);
        risk = varRisk.toString();

        QModelIndex schedulefinishIndex = openpointlistModel->index(row, 4, QModelIndex());
        QVariant varSchedulefinish = openpointlistModel->data(schedulefinishIndex, Qt::DisplayRole);
        schedulefinish = varSchedulefinish.toDate();

        QModelIndex responsibleIndex = openpointlistModel->index(row, 5, QModelIndex());
        QVariant varResponsible = openpointlistModel->data(responsibleIndex, Qt::DisplayRole);
        responsible = varTask.toString();

        QModelIndex entrydateIndex = openpointlistModel->index(row, 6, QModelIndex());
        QVariant varEntrydate = openpointlistModel->data(entrydateIndex, Qt::DisplayRole);
        entrydate = varEntrydate.toDate();

        QModelIndex statusIndex = openpointlistModel->index(row, 7, QModelIndex());
        QVariant varStatus = openpointlistModel->data(statusIndex, Qt::DisplayRole);
        status = varStatus.toString();

    }

    EditOpenPointItemDialog editOpenPointDialog;
    editOpenPointDialog.setWindowTitle(tr("Edit a Contact"));
    editOpenPointDialog.editOpenPointListItem(subject, task, result, risk, schedulefinish, responsible, entrydate, status);

    if (editOpenPointDialog.exec()) {

        const QString newSubject = editOpenPointDialog.subject();
        if (newSubject != subject) {
            const QModelIndex index = openpointlistModel->index(row, 0, QModelIndex());
            openpointlistModel->setData(index, newSubject, Qt::EditRole);
        }

        const QString newTask = editOpenPointDialog.task();
        if (newTask != task) {
             const QModelIndex index = openpointlistModel->index(row, 1, QModelIndex());
             openpointlistModel->setData(index, newTask, Qt::EditRole);
        }

        const QString newResult = editOpenPointDialog.result();
        if (newResult != result) {
            const QModelIndex index = openpointlistModel->index(row, 2, QModelIndex());
            openpointlistModel->setData(index, newResult, Qt::EditRole);
        }

        const QString newRisk = editOpenPointDialog.risk();
        if (newRisk != risk) {
             const QModelIndex index = openpointlistModel->index(row, 3, QModelIndex());
             openpointlistModel->setData(index, newRisk, Qt::EditRole);
        }

        const QDate newSchedulefinish = editOpenPointDialog.schedulefinish();
        if (newSchedulefinish != schedulefinish) {
            const QModelIndex index = openpointlistModel->index(row, 4, QModelIndex());
            openpointlistModel->setData(index, newSchedulefinish, Qt::EditRole);
        }

        const QString newResponsible = editOpenPointDialog.responsible();
        if (newResponsible != responsible) {
             const QModelIndex index = openpointlistModel->index(row, 5, QModelIndex());
             openpointlistModel->setData(index, newResponsible, Qt::EditRole);

        }
        const QDate newEntrydate = editOpenPointDialog.entrydate();
        if (newEntrydate != entrydate) {
            const QModelIndex index = openpointlistModel->index(row, 6, QModelIndex());
            openpointlistModel->setData(index, newEntrydate, Qt::EditRole);
        }

        const QString newStatus = editOpenPointDialog.status();
        if (newStatus != status) {
             const QModelIndex index = openpointlistModel->index(row, 7, QModelIndex());
             openpointlistModel->setData(index, newStatus, Qt::EditRole);
        }
     }
}
void MainWindow::writeToFile(const QString &fileName)
{
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        return;
    }

    QString projectname;
    projectname = ui->lineEdit->text();


    QDataStream out(&file);
    out << openpointlistModel->OpenPointListModel::getOpenPointItems();
    out << projectname;
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    if (!fileName.isEmpty()){
        MainWindow::writeToFile(fileName);
    }
}

void MainWindow::readFromFile(const QString &fileName)
{
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
            file.errorString());
        return;
    }

    QString projectname;
    QVector<OpenPointListItem> m_openpointItems;

    QDataStream in(&file);
    in >> m_openpointItems;
    in >> projectname;

    ui->lineEdit->setText(projectname);

    if (m_openpointItems.isEmpty()) {
        QMessageBox::information(this, tr("No OpenList Item in file"),
                                 tr("The file does not contain any OpenList Item."));
    } else {
        for (const auto &openpointlistitem: qAsConst(m_openpointItems))
            addEntry(openpointlistitem.subject,
                     openpointlistitem.task,
                     openpointlistitem.result,
                     openpointlistitem.risk,
                     openpointlistitem.schedulefinish,
                     openpointlistitem.responsible,
                     openpointlistitem.entrydate,
                     openpointlistitem.status);
    }
}

void MainWindow::on_actionLoad_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty())
        MainWindow::readFromFile(fileName);
}


