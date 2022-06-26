#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include "contactlistmodel.h"
#include "openpointlistmodel.h"
#include "qitemselectionmodel.h"
#include "sharedcontactlist.h"
#include "contactoverview.h"


QT_BEGIN_NAMESPACE
class QSortFilterProxyModel;
class QItemSelectionModel;
QT_END_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void resizeEvent(QResizeEvent *event);

    void updateActions(const QItemSelection &selection);

    void writeToFile(const QString &fileName);
    void readFromFile(const QString &fileName);

    void setSourceModel(QAbstractItemModel *model);

public slots:

    void on_actionSave_triggered();

    void on_actionLoad_triggered();

    void on_tableView_activated(const QModelIndex &index);

    void editEntry();

    void mousePressEvent(QMouseEvent *event);

private slots:

    void showAddEntryDialog();

    void addEntry(const QString &subject, const QString &task, const QString &result, const QString &risk, const QDate &schedulefinish, const QString &responsible, const QDate &entrydate, const QString &status);

    void on_pushButton_clicked();

    void on_additempushButton_clicked();

    void on_edititempushButton_clicked();

    void on_removeitempushButton_clicked();



signals:

    void selectionChanged (const QItemSelection &selected);

private:
    Ui::MainWindow *ui;
    ContactOverview *contactOverview;
    OpenPointListModel *openpointlistModel;
    ContactListModel *m_contactlistModel;
    QSortFilterProxyModel *proxyModel;
};
#endif // MAINWINDOW_H
