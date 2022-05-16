#include "contactlistmodel.h"

ContactListModel::ContactListModel(QList<ContactItem> *contactItems, QObject *parent)
    : QAbstractTableModel(parent), m_contactItems(contactItems)
{
}

QVariant ContactListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole){
        if(orientation == Qt::Horizontal) {
            switch(section) {
            case 0: return "Surname";
            case 1: return "Forename";
            case 2: return "Company";
            case 3: return "Role";
            case 4: return "Mail";
            case 5: return "Phone";
            }
        } else {
            return QString::number(section + 1);
        }
    }
    return QVariant();
}

int ContactListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_contactItems->size();
}

int ContactListModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return 6;
}

QVariant ContactListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if(role == Qt::DisplayRole){
        const ContactItem& item = m_contactItems->at(index.row());

        switch(index.column()){
        case 0: return item.surname();
        case 1: return item.forename();
        case 2: return item.company();
        case 3: return item.role();
        case 4: return item.mail();
        case 5: return item.phone();
        }
    }
    return QVariant();
}

bool ContactListModel::removeRows(int row, int count, const QModelIndex &parent) {
    if(row >= rowCount() || row+count-1 >= rowCount()){
        return false;
    }
    beginRemoveRows(parent, row, row+count-1);

    for (int i = 0; i < count; i++){
        m_contactItems->removeAt(row);
    }
    endRemoveRows();

    return true;
}

void ContactListModel::addItem(ContactItem item){
beginInsertRows(QModelIndex(), rowCount(), rowCount());
m_contactItems->append(item);
endInsertRows();
};
void ContactListModel::updateItem(int row, ContactItem item){
  (*m_contactItems)[row] = item;
    emit dataChanged(createIndex(row,0), createIndex(row, columnCount() -1));
};
