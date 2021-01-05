//
// Created by shalaga44 on 1/5/21.
//
#include "../../include/tests.h"

int main() {
    const string name = "Mohamed Moawia";
    const string phone = "0123456789";
    auto DB = Database("test.db");
    auto contact = Contact();
    contact.set(CONTACT_FIELD_NAME, name);
    contact.set(CONTACT_FIELD_PHONE, phone);
    DB.addContact(contact);
    for (Contact c: DB.getAllContacts()) {
        assert(c.get(CONTACT_FIELD_NAME) == name);
    }

}