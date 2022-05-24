#ifndef SHAREDCONTACTLIST_H
#define SHAREDCONTACTLIST_H

#include <QList>
#include "contactitem.h"

class SharedContactList
{
private:
    SharedContactList();

public:
    QList<ContactItem> *contactItems();

    static SharedContactList* instance();

private:
    QList<ContactItem> m_contactItems;
};

#endif // SHAREDCONTACTLIST_H
