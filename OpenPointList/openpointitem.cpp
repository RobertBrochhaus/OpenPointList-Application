#include "openpointitem.h"

OpenPointItem::OpenPointItem()
{

}

OpenPointItem::OpenPointItem(QString subject, QString task, QString result, int risk, QDate scheduledfinish, QString responsible, QDate entrydate, int status):
    m_subject(subject), m_task(task), m_result(result), m_risk(risk), m_scheduledfinish(scheduledfinish), m_responsible(responsible), m_entrydate(entrydate), m_status(status)
{
}

QString OpenPointItem::subject() const
{
    return m_subject;
}

void OpenPointItem::setSubject(const QString &subject)
{
    m_subject = subject;
}

QString OpenPointItem::task() const
{
    return m_task;
}

void OpenPointItem::setTask(const QString &task)
{
    m_task = task;
}

QString OpenPointItem::result() const
{
    return m_result;
}

void OpenPointItem::setResult(const QString &result)
{
    m_result = result;
}

int OpenPointItem::risk() const
{
    return m_risk;
}

void OpenPointItem::setRisk(const int &risk)
{
    m_risk = risk;
}

QDate OpenPointItem::scheduledfinish() const
{
    return m_scheduledfinish;
}

void OpenPointItem::setScheduledfinish(const QDate &scheduledfinish)
{
    m_scheduledfinish = scheduledfinish;
}

QString OpenPointItem::responsible() const
{
    return m_responsible;
}

void OpenPointItem::setResponsible(const QString &responsible)
{
    m_responsible = responsible;
}

QDate OpenPointItem::entrydate() const
{
    return m_entrydate;
}

void OpenPointItem::setEntrydate(const QDate &entrydate)
{
    m_entrydate = entrydate;
}

 int OpenPointItem::status() const
{
    return m_status;
}

void OpenPointItem::setStatus(const int &status)
{
    m_status = status;
}
