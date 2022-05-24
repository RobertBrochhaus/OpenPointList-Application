#ifndef CONTACTLISTMODEL_H
#define CONTACTLISTMODEL_H

#include "contactitem.h"
#include <QAbstractTableModel>

class ContactListModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ContactListModel(QList<ContactItem> *contactItems, QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    //Delete rows
    virtual bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    const QList<ContactItem> &getContactItems() const;

    // Add and Edit
    void addItem(ContactItem item);
    void updateItem(int row, ContactItem item);

private:
    QList<ContactItem> *m_contactItems;
};

inline QDataStream &operator<<(QDataStream &out, const ContactItem &contact)
{
    return out << contact.surname() << contact.forename() << contact.company() << contact.role() << contact.mail() << contact.phone();
}

inline QDataStream &operator>>(QDataStream &in, ContactItem &contact)
{
    QString surname;
    QString forename;
    QString company;
    QString role;
    QString mail;
    QString phone;

    in >> surname >> forename >> company >> role >> mail >> phone;
    contact = ContactItem(surname, forename, company, role, mail, phone);
    return in;
}

#endif // CONTACTLISTMODEL_H
