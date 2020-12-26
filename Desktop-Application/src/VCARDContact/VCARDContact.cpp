//
// Created by shalaga44 on 12/24/20.
//

#include "VCARDContact.h"

VCARDContact::VCARDContact(const std::string name) {
    this->username = name;
}

void VCARDContact::setName(const string &name) {
    VCARDContact::username = name;
}

VCARDContact::VCARDContact() {

}
