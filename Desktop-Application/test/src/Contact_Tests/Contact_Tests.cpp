//
// Created by shalaga44 on 1/5/21.
//
#include "../../include/tests.h"

int main() {
    const string name = "Mohamed Moawia";
    auto contact = Contact();
    contact.set("Name", name);
    assert(contact.get("Name")== name);

    return 0;
}