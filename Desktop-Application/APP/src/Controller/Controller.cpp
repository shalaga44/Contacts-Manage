//
// Created by shalaga44 on 1/6/21.
//


#include "../../include/DataBase/DataBase.h"
#include "../../include/Controller/Controller.h"
#include "../../include/Models/Contact/Contact.h"


Controller::Controller(const Database &database) : DB(database) {

}

vector<Contact> Controller::search(string searchText) {
    return DB.search(searchText);
}

Contact Controller::contactAt(int index) {
    return DB.contactAt(index);
}

vector<Contact> Controller::allContacts() {
    return DB.getAllContacts();
}

void Controller::add(const Contact& contact) {
    DB.addContact(contact);
}

void Controller::remove(int id) {
    DB.remove(id);
}
