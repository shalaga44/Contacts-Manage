//
// Created by shalaga44 on 1/5/21.
//
#include "../../include/tests.h"

const char *DATABASE_TESTS_NAME = "test.db";
const string TEST_CONTACT_0_NAME = "Mohamed Moawia";
const string TEST_CONTACT_0_PHONE = "0123456789";

void add_test();

void search_test();

void edit_test();

void remove_test();

void addManyTestContacts(Database &DB, int count);

void paging_test();

void contactAt_test();

int main() {
    add_test();
    search_test();
    edit_test();
    remove_test();
    paging_test();
    contactAt_test();
}

void contactAt_test() {
    auto DB = Database(DATABASE_TESTS_NAME);
    const vector<Contact> &contacts = DB.getAllContacts();
    assert(!contacts.empty());
    Contact contact0 = contacts[0];
    const int id = contact0.getId();
    auto contactAt0 = DB.contactAt(id);
    for(const ContactField& field: CONTACTS_FIELDS_LIST){
        assert(contact0.get(field) == contactAt0.get(field));
    }
}

void paging_test() {
    auto DB = Database(DATABASE_TESTS_NAME);
    const int PAGE_SIZE = 10;
    const int TOTAL_PAGES = 10;
    addManyTestContacts(DB, PAGE_SIZE * TOTAL_PAGES);
    for (int pageIndex = 0; pageIndex < TOTAL_PAGES; ++pageIndex) {
        vector<Contact> page = DB.getContactPage(pageIndex, PAGE_SIZE);
        assert(page.size() == PAGE_SIZE);
    }
}

void addManyTestContacts(Database &DB, int count) {
    for (int i = 0; i < count; ++i) {
        auto contact = Contact();
        contact.set(CONTACT_FIELD_NAME, to_string(i + 1));
        DB.addContact(contact);

    }
}

void remove_test() {
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
    int id = result[0].getId();
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

void add_test() {

    auto DB = Database(DATABASE_TESTS_NAME);
    auto contact = Contact();
    contact.set(CONTACT_FIELD_NAME, TEST_CONTACT_0_NAME);
    contact.set(CONTACT_FIELD_PHONE, TEST_CONTACT_0_PHONE);
    DB.addContact(contact);
    for (const Contact &c: DB.getAllContacts()) {
        assert(c.get(CONTACT_FIELD_NAME) == TEST_CONTACT_0_NAME);
    }

}