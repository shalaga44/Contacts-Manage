//
// Created by shalaga44 on 12/24/20.
//

#ifndef CONTACTSMANAGER_VCARDREADER_H
#define CONTACTSMANAGER_VCARDREADER_H


#include "../VCARDContact/VCARDContact.h"
#include <vector>

class VCARDReader {
public:
    VCARDReader();

    bool isLineName(string basicString);

    std::string sayHello();

    vector<VCARDContact> readVCARDFrom(const std::string path);

    vector<VCARDContact> getAllContacts() const;

    const string vcardStartQ = "BEGIN:VCARD";
    const string vcardVersionQ = "VERSION:2.1";
    const string vcardNameQ = "N";

    string getLineValue(string basicString);

    void setContactNameByIndex(const string &basicString, int index);
};


#endif //CONTACTSMANAGER_VCARDREADER_H
