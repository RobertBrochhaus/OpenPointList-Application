#ifndef OPENPOINTITEM_H
#define OPENPOINTITEM_H

#include "qcombobox.h"
#include <QString>
#include <QDate>
#include <QList>

class OpenPointItem
{
public:
    OpenPointItem();
    OpenPointItem(QString subject, QString task, QString result, int risk, QDate scheduledfinish, QString responsible, QDate entrydate, int status);

    QString subject() const;
    void setSubject(const QString &subject);

    QString task() const;
    void setTask(const QString &task);

    QString result() const;
    void setResult(const QString &result);

    int risk() const;
    void setRisk(const int &risk);

    QDate scheduledfinish() const;
    void setScheduledfinish(const QDate &scheduledfininsh);

    QString responsible() const;
    void setResponsible(const QString &responsible);

    QDate entrydate() const;
    void setEntrydate(const QDate &entrydate);

    int status() const;
    void setStatus(const int &status);

private:
    QString m_subject;
    QString m_task;
    QString m_result;
    int m_risk;
    QDate m_scheduledfinish;
    QString m_responsible;
    QDate m_entrydate;
    int m_status;
};

#endif // OPENPOINTITEM_H
