#ifndef OPENPOINTLISTMODEL_H
#define OPENPOINTLISTMODEL_H

#include "qdatetime.h"
#include <QAbstractTableModel>
#include <QVector>

struct OpenPointListItem
{
    QString subject;
    QString task;
    QString result;
    QString risk;
    QDate schedulefinish;
    QString responsible;
    QDate entrydate;
    QString status;

    bool operator==(const OpenPointListItem &other) const
    {
        return subject == other.subject &&  task == other.task &&  result == other.result &&  risk == other.risk &&  schedulefinish == other.schedulefinish && responsible == other.responsible &&  entrydate == other.entrydate &&  status == other.status;
    }
};

inline QDataStream &operator<<(QDataStream &stream, const OpenPointListItem &openpointlistitem)
{
    return stream << openpointlistitem.subject << openpointlistitem.task << openpointlistitem.result << openpointlistitem.risk << openpointlistitem.schedulefinish << openpointlistitem.responsible << openpointlistitem.entrydate << openpointlistitem.status;
}

inline QDataStream &operator>>(QDataStream &stream, OpenPointListItem &openpointlistitem)
{
    return stream >> openpointlistitem.subject >> openpointlistitem.task >> openpointlistitem.result >> openpointlistitem.risk >> openpointlistitem.schedulefinish >> openpointlistitem.responsible >> openpointlistitem.entrydate >> openpointlistitem.status;
}

class OpenPointListModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    OpenPointListModel(QObject *parent = nullptr);
    OpenPointListModel(const QVector<OpenPointListItem> &m_openpointItems, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    const QVector<OpenPointListItem> &getOpenPointItems() const;

private:
    QVector<OpenPointListItem> m_openpointItems;
};

#endif // OPENPOINTLISTMODEL_H
