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
    os << "Contact(\n\t";
    int size = std::size(CONTACTS_FIELDS_LIST);
    for (int i = 0; i < size - 1; ++i)
        os << CONTACTS_FIELDS_LIST[i].getTitle() << ": " << contact.get(CONTACTS_FIELDS_LIST[i]) << "), (";

    os << CONTACTS_FIELDS_LIST[size - 1].getDBName() + ")";

    return os;
}

