//
// Created by shalaga44 on 1/5/21.
//
#include "../../include/tests.h"

int main() {
    const string name = "Mohamed Moawia";
    auto contact = Contact();
    contact.set(CONTACT_FIELD_NAME, name);
    assert(contact.get(CONTACT_FIELD_NAME) == name);
    return 0;
}