//
// Created by shalaga44 on 12/24/20.
//

#include <string>
#include <vector>
#include <exception>
#include <fstream>
#include <iostream>
#include "VCARDReader.h"
#include "../VCARDContact/VCARDContact.h"
#include "../utils/StringUtils.h"

std::string VCARDReader::sayHello() {
    return "Hello";
}

bool VCARDReader::isLineName(string line) {
    vector<string> lineList = split(line, ':');
    string lineType = lineList[0];
    if (lineType == vcardNameQ) return true;
    else return false;

}

vector<VCARDContact> VCARDReader::readVCARDFrom(const std::string path) {
    vector<VCARDContact> contactsList = vector<VCARDContact>();;
    string line;
    ifstream file;
    file.open(path);
    if (!file.is_open()) throw invalid_argument("file not found");
    getline(file, line);
    if (trim(line) != vcardStartQ) throw invalid_argument("this is not a vCard");
    getline(file, line);
    if (trim(line) != vcardVersionQ) throw invalid_argument("this vCard is invalid");
    VCARDContact contact = VCARDContact("");
    while (getline(file, line)) {
        line = trim(line);
        if (isLineName(line)) contact.setName(getLineValue(line));

    }
    contactsList.push_back(contact);
    return contactsList;

}


 string VCARDReader::getLineValue(string line) {
    vector<string> lineList = split(line, ':');
    string lineValue;
    for (int i = 1; i < lineList.size() - 1; ++i)
        lineValue += lineList[i] + ":";
    lineValue += lineList[lineList.size() - 1];
    return lineValue;
}

VCARDReader::VCARDReader() {

}
