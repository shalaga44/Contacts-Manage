//
// Created by shalaga44 on 1/5/21.
//
#include "../../include/tests.h"

const char *DATABASE_TESTS_NAME = "test.db";
const string TEST_CONTACT_0_NAME = "Mohamed Moawia";
const string TEST_CONTACT_0_PHONE = "0123456789";

void add_contact_test();

void search_test();

void edit_test();

int main() {
    add_contact_test();
    search_test();
    edit_test();
    auto DB = Database(DATABASE_TESTS_NAME);
    vector<Contact> result = DB.search("moawia");
    assert(!result.empty());
    for (Contact c:result) {
        int id = c.getId();
        DB.remove(id);
    }
    result = DB.search("moawia");
    assert(result.empty());


}

void edit_test() {
    const string NEW_NAME = "Mohamed Moawia El-Bashir";
    auto DB = Database(DATABASE_TESTS_NAME);
    vector<Contact> result = DB.search("moawia");
    assert(!result.empty());
    int id = stoi(result[0].get(CONTACT_DATABASE_FIELD_ID));
    DB.edit(id, CONTACT_FIELD_NAME, NEW_NAME);

    result = DB.search("bashir");
    auto me = result[0];
    assert(me.get(CONTACT_FIELD_NAME) == NEW_NAME);
}

void search_test() {
    auto DB = Database(DATABASE_TESTS_NAME);
    string searchText = "mohamed";
    vector<Contact> result = DB.search(searchText);
    assert(result.size() == 1);
    assert(result[0].get(CONTACT_FIELD_NAME) == TEST_CONTACT_0_NAME);
}

void add_contact_test() {

    auto DB = Database(DATABASE_TESTS_NAME);
    auto contact = Contact();
    contact.set(CONTACT_FIELD_NAME, TEST_CONTACT_0_NAME);
    contact.set(CONTACT_FIELD_PHONE, TEST_CONTACT_0_PHONE);
    DB.addContact(contact);
    for (Contact c: DB.getAllContacts()) {
        assert(c.get(CONTACT_FIELD_NAME) == TEST_CONTACT_0_NAME);
    }

}