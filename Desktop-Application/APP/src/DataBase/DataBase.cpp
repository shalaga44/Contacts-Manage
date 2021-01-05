//
// Created by shalaga44 on 1/5/21.
//

#include "../../../APP/include/DataBase/DataBase.h"
#include "../../include/Models/ContactField/ContactField.h"
#include <sqlite3.h>
#include <iostream>
#include <exception>
#include <utility>
#include <vector>
#include <string>
#include <main.h>

Database::~Database() {
    sqlite3_close(DB);
}

Database::Database(const char *databasePath) {
    status = sqlite3_open(databasePath, &DB);
    checkDataBaseIsOpen();
}

void Database::checkDataBaseIsOpen() {
    if (status)
        throw DatabaseException(sqlite3_errmsg(DB));
}

void Database::addContact(Contact contact) {
    createContactTable();
    addContactToDatabase(std::move(contact));
}

void Database::createContactTable() {
    string contactsSql;

    int size = std::size(CONTACTS_FIELDS_LIST);
    for (int i = 0; i < size - 1; ++i)
        contactsSql += CONTACTS_FIELDS_LIST[i].getDBName() + " TEXT , ";

    contactsSql += CONTACTS_FIELDS_LIST[size - 1].getDBName() + " TEXT";


    string sql = "CREATE TABLE IF NOT EXISTS " + DATABASE_CONTACT_TABLE_NAME + "("
                 + DATABASE_CONTACT_FIELD_ID + " INTEGER default 0 constraint Contact_pk primary key autoincrement, "
                 + contactsSql
                 + ");";
    char *messageError;
    int statusCreateTable = sqlite3_exec(DB, sql.c_str(), nullptr, nullptr, &messageError);
    if (statusCreateTable != SQLITE_OK)
        throw DatabaseException(messageError);
}

void Database::addContactToDatabase(Contact contact) {
    string contactsFieldSql;
    int size = std::size(CONTACTS_FIELDS_LIST);
    for (int i = 0; i < size - 1; ++i)
        contactsFieldSql += CONTACTS_FIELDS_LIST[i].getDBName() + " , ";

    contactsFieldSql += CONTACTS_FIELDS_LIST[size - 1].getDBName();

    string contactValueSql;
    for (int i = 0; i < size - 1; ++i)
        contactValueSql += contact.get(CONTACTS_FIELDS_LIST[i]) + "' , '";
    contactValueSql += contact.get(CONTACTS_FIELDS_LIST[size - 1]);


    string sql = "INSERT INTO " + DATABASE_CONTACT_TABLE_NAME
                 + "("
                 + contactsFieldSql
                 + ")"
                 + " VALUES( '"
                 + contactValueSql
                 + "');";
//    println(sql);
    char *messageError;
    int statusInsertContact = sqlite3_exec(DB, sql.c_str(), nullptr, nullptr, &messageError);
    if (statusInsertContact != SQLITE_OK) {
        throw DatabaseException(messageError);
    }
}

vector<Contact> Database::getAllContacts() {
    string query = "SELECT * FROM Contact;";
    contacts.clear();
    sqlite3_exec(DB, query.c_str(), [](void *data, int argc, char **values, char **fields) -> int {
        auto contact = Contact();
        for (int i = 0; i < argc; i++)
            contact.set(ContactField(fields[i]), values[i]);
        contacts.push_back(contact);
        return 0;
    }, nullptr, nullptr);
    return contacts;
}

vector<Contact> Database::search(string searchText) {
    auto matchContacts = vector<Contact>();
    vector<Contact> allContacts = getAllContacts();
    for (const Contact &contact: allContacts)
        for (const ContactField &field: CONTACTS_FIELDS_LIST) {
            auto value = contact.get(field);
            size_t found = value.find(searchText);
            if (found != string::npos) {
                matchContacts.push_back(contact);
                break;
            }
        }

    return matchContacts;
}


