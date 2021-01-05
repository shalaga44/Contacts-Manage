//
// Created by shalaga44 on 1/5/21.
//
#include "../../include/tests.h"

void set_get_test();

void database_name_test();

int main() {
    set_get_test();
    database_name_test();

    return 0;
}

void database_name_test() {
    for (ContactField cf: CONTACTS_FIELDS_LIST)
        for(char c: cf.getDBName())
            assert(c != ' ');
}

void set_get_test() {
    const string name = "Mohamed Moawia";
    auto contact = Contact();
    contact.set(CONTACT_FIELD_NAME, name);
    assert(contact.get(CONTACT_FIELD_NAME) == name);
}
