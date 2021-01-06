//
// Created by shalaga44 on 1/6/21.
//
#include "../../include/tests.h"

const char *DATABASE_TESTS_NAME = "ctrlTest.db";

void empty_test();

void add_test();

int main() {
    empty_test();
    add_test();
//    auto ctrlr = Controller(Database(DATABASE_TESTS_NAME));
//    const int SIZE = 20;
//    auto searchList = ctrlr.search("4");
//    assert(searchList.size() == 2);

//    for (const auto &c: searchList)
//        ctrlr.remove(c.getId());
//
//    contactList = ctrlr.allContacts();
//    assert(contactList.size() == (SIZE) - 2);


}

void add_test() {
    auto ctrlr = Controller(Database(DATABASE_TESTS_NAME));
    const int SIZE = 20;
    for (int i = 1; i <= SIZE; ++i) {
        auto c = Contact();
        c.set(CONTACT_FIELD_NAME, to_string(i) + "- User");
        c.set(CONTACT_FIELD_PHONE, to_string(i) + "09999999");
        ctrlr.add(c);
    }
//    auto contactList = ctrlr.allContacts();
//    assert(contactList.size() == SIZE);
//    for (int i = 0; i < SIZE; ++i) {
//        auto c = contactList[i];
//        assert(c.get(CONTACT_FIELD_NAME) == (to_string(i) + "- User"));
//        assert(c.get(CONTACT_FIELD_PHONE) == (to_string(i) + "09999999"));
//    }
}

void empty_test() {
    auto ctrlr = Controller(Database(DATABASE_TESTS_NAME));
    auto contacts = ctrlr.allContacts();
    assert(contacts.empty());
}
