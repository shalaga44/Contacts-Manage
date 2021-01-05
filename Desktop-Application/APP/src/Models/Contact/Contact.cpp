//
// Created by shalaga44 on 1/5/21.
//


#include "../../../include/Models/Contact/Contact.h"
#include "../../../include/Models/ContactField/ContactField.h"
#include <utility>

using namespace std;

void Contact::set(ContactField field, string value) {
    infoMap[field.getDBName()] = value;
}

string Contact::get(const ContactField &field) const {
    try { return infoMap.at(field.getDBName()); }
    catch (const std::out_of_range &e) { return ""; }

}

ostream &operator<<(ostream &os, const Contact &contact) {
    os << "Contact:\n        ";
    int size = std::size(CONTACTS_FIELDS_LIST);
    for (int i = 0; i < size - 1; ++i) {

        const ContactField field = CONTACTS_FIELDS_LIST[i];

        const string &value = contact.get(field);
        if (value.empty()) continue;
        os << field.getTitle() << ": " << value << "    ";
    }
    const ContactField &field = CONTACTS_FIELDS_LIST[size - 1];
    const string &value = contact.get(field);
    if (!value.empty())
        os << field.getTitle() << ": " << value << "    ";

    return os;
}

int Contact::getId() {
    return stoi(get(CONTACT_DATABASE_FIELD_ID));
}

Contact::~Contact() {
    infoMap.clear();
}

