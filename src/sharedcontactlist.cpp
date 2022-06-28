#include "sharedcontactlist.h"

SharedContactList::SharedContactList()
{
}

SharedContactList* SharedContactList::instance(){
    static SharedContactList* model = new SharedContactList();
    return model;
}

QList<ContactItem>* SharedContactList::contactItems(){
    return &m_contactItems;
}
