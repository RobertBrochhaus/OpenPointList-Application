#include "sharedcontactlist.h"

SharedContactList::SharedContactList()
{
 // Add test data
 m_contactItems.append( ContactItem("Nachname", "Vorname", "Firma", "Rolle", "Mail", "Telefon"));
}


SharedContactList* SharedContactList::instance(){
    static SharedContactList* model = new SharedContactList();
    return model;
}

QList<ContactItem>* SharedContactList::contactItems(){
    return &m_contactItems;
}
