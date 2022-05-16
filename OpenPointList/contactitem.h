#ifndef CONTACTITEM_H
#define CONTACTITEM_H


#include <QString>

class ContactItem
{
public:
    ContactItem();
    ContactItem(QString surname, QString forename, QString company, QString role, QString mail, QString phone);

    QString surname() const;
    void setSurname(const QString &surname);

    QString forename() const;
    void setForename(const QString &forename);

    QString company() const;
    void setCompany(const QString &company);

    QString role() const;
    void setRole(const QString &role);

    QString mail() const;
    void setMail(const QString &mail);

    QString phone() const;
    void setPhone(const QString &phone);

private:
    QString m_surname;
    QString m_forename;
    QString m_company;
    QString m_role;
    QString m_mail;
    QString m_phone;
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
#endif // CONTACTITEM_H
