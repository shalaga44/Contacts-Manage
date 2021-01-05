//
// Created by shalaga44 on 1/5/21.
//
#include "../../include/tests.h"

void add_contact_test();

int main() {
    add_contact_test();
    auto DB = Database("test.db");
    string searchText = "Mohamed";
    vector<Contact> result = DB.search(searchText);
    assert(result.size() == 1);
    assert(result[0].get(CONTACT_FIELD_NAME) == "Mohamed Moawia");


}

void add_contact_test() {
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