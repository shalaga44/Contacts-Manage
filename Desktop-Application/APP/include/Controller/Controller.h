//
// Created by shalaga44 on 1/6/21.
//

#ifndef DESKTOP_APPLICATION_CONTROLLER_H
#define DESKTOP_APPLICATION_CONTROLLER_H

#include <DataBase/DataBase.h>
#include <Models/Contact/Contact.h>
#include <vector>

class Controller {
public:
    Database DB;

    explicit Controller(const Database &database);

    vector<Contact> search(string searchText);

    void add(const Contact &contact);

    void remove(int id);

    Contact contactAt(int index);

    vector<Contact> allContacts();
};

#endif //DESKTOP_APPLICATION_CONTROLLER_H
