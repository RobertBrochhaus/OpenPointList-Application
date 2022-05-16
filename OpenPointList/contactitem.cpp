#include "contactitem.h"

ContactItem::ContactItem()
{

}

ContactItem::ContactItem(QString surname, QString forename, QString company, QString role, QString mail, QString phone):
    m_surname(surname), m_forename(forename), m_company(company), m_role(role), m_mail(mail), m_phone(phone)
{
}

QString ContactItem::surname() const
{
    return m_surname;
}

void ContactItem::setSurname(const QString &surname)
{
    m_surname = surname;
}

QString ContactItem::forename() const
{
    return m_forename;
}

void ContactItem::setForename(const QString &forename)
{
    m_forename = forename;
}

QString ContactItem::company() const
{
    return m_company;
}

void ContactItem::setCompany(const QString &company)
{
    m_company = company;
}

QString ContactItem::role() const
{
    return m_role;
}

void ContactItem::setRole(const QString &role)
{
    m_role = role;
}

QString ContactItem::mail() const
{
    return m_mail;
}

void ContactItem::setMail(const QString &mail)
{
    m_mail = mail;
}

QString ContactItem::phone() const
{
    return m_phone;
}

void ContactItem::setPhone(const QString &phone)
{
    m_phone = phone;
}
