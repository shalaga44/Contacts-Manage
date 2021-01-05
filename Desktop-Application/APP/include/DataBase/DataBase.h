//
// Created by shalaga44 on 1/5/21.
//

#ifndef DESKTOP_APPLICATION_DATABASE_H
#define DESKTOP_APPLICATION_DATABASE_H

#include <sqlite3.h>
#include "../Models/Contact/Contact.h"
#include <vector>


class Database {
private:
    inline static const string DATABASE_CONTACT_TABLE_NAME = "Contact";
    sqlite3 *DB = nullptr;
    int status = 0;
    inline static vector<Contact> contacts;

    void createContactTable();

    void addContactToDatabase(Contact contact);

    void checkDataBaseIsOpen();

public:


    explicit Database(const char *databasePath);

    ~Database();


    void addContact(Contact contact);

    vector<Contact> search(string searchText);

    void remove(int index);

    void edit(int index, ContactField field, string value);

    vector<Contact> getAllContacts();

    class DatabaseException : public exception {
    public:
        const char *msg;

        explicit DatabaseException(const char *msg) {
            this->msg = msg;
        }

        ~DatabaseException() noexcept override {
            delete msg;

        }

        const char *what() const noexcept override {
            return msg;
        }
    };
};

#endif //DESKTOP_APPLICATION_DATABASE_H
