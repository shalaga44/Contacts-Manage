//
// Created by shalaga44 on 1/5/21.
//

#include "Models/Contact/Contact.h"

void Contact::set(ContactField field, string value) {
    infoMap[field.getDBName()] = value;
}

string Contact::get(ContactField field) {
    return infoMap[field.getDBName()];
}
