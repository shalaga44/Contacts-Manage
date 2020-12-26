//
// Created by shalaga44 on 12/24/20.
//

#ifndef CONTACTSMANAGER_VCARDCONTACT_H
#define CONTACTSMANAGER_VCARDCONTACT_H

#include "string"

using namespace std;

class VCARDContact {
public:
    VCARDContact(const std::string name);
    VCARDContact();

    string username = "";

    void setName(const string &name);
};


#endif //CONTACTSMANAGER_VCARDCONTACT_H
