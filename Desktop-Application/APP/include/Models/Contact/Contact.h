//
// Created by shalaga44 on 1/5/21.
//

#ifndef DESKTOP_APPLICATION_CONTACT_H
#define DESKTOP_APPLICATION_CONTACT_H

#include <map>
#include <string>
#include <ostream>
#include "Models/ContactField/ContactField.h"

using namespace std;

class Contact {
private:
    map<string, string> infoMap = map<string, string>();
public:
    void set(ContactField field, string value);

    string get(const ContactField& field) const;

    friend ostream &operator<<(ostream &os, const Contact &contact);
};

#endif //DESKTOP_APPLICATION_CONTACT_H
