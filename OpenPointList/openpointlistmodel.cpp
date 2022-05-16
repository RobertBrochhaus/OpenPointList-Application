#include "openpointlistmodel.h"
#include <QItemSelection>

OpenPointListModel::OpenPointListModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

OpenPointListModel::OpenPointListModel(const QVector<OpenPointListItem> &m_openpointItems, QObject *parent):
    QAbstractTableModel(parent)
  , m_openpointItems(m_openpointItems)
{
}

int OpenPointListModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 :  m_openpointItems.size();
}

int OpenPointListModel::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 8;
}

QVariant OpenPointListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= m_openpointItems.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        const auto &openpointItems = m_openpointItems.at(index.row());

        switch (index.column()) {
            case 0:
                return openpointItems.subject;
            case 1:
                return openpointItems.task;
            case 2:
                return openpointItems.result;
            case 3:
                return openpointItems.risk;
            case 4:
                return openpointItems.schedulefinish;
            case 5:
                return openpointItems.responsible;
            case 6:
                return openpointItems.entrydate;
            case 7:
                return openpointItems.status;
            default:
                break;
        }
    }
    return QVariant();
}

QVariant OpenPointListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return tr("Subject");
            case 1:
                return tr("Task");
            case 2:
                return tr("Result");
            case 3:
                return tr("Risk");
            case 4:
                return tr("Schedule Finish");
            case 5:
                return tr("Responsible");
            case 6:
                return tr("Entry Date");
            case 7:
                return tr("Status");
            default:
                break;
        }
    }
    return QVariant();
}

Qt::ItemFlags OpenPointListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

bool OpenPointListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        const int row = index.row();
        auto openpointItems = m_openpointItems.value(row);

        switch (index.column()) {
            case 0:
                openpointItems.subject = value.toString();
                break;
            case 1:
                openpointItems.task = value.toString();
                break;
            case 2:
                openpointItems.result = value.toString();
                break;
            case 3:
                openpointItems.risk = value.toString();
                break;
            case 4:
                openpointItems.schedulefinish = value.toDate();
                break;
            case 5:
                openpointItems.responsible = value.toString();
                break;
            case 6:
                openpointItems.entrydate = value.toDate();
                break;
            case 7:
                openpointItems.status = value.toString();
                break;
            default:
                return false;
        }

        m_openpointItems.replace(row, openpointItems);
        emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});

        return true;
    }

    return false;
}

bool OpenPointListModel::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row)
        m_openpointItems.insert(position, { QString(), QString(), QString(), QString(), QDate(), QString(), QDate(), QString()});

    endInsertRows();
    return true;
}

bool OpenPointListModel::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row)
        m_openpointItems.removeAt(position);

    endRemoveRows();
    return true;
}

const QVector<OpenPointListItem> &OpenPointListModel::getOpenPointItems() const
{
    return m_openpointItems;
}
