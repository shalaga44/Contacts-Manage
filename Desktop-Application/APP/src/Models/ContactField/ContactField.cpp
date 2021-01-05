//
// Created by shalaga44 on 1/5/21.
//

#include <string>
#include <utility>
#include "../../../include/Models/ContactField/ContactField.h"

ContactField::ContactField(string name)
        : name(std::move(name)) {}

ContactField::ContactField(string name, bool hasMultipleValues) :
        name(std::move(name)),
        hasMultipleValues(hasMultipleValues) {}

string ContactField::getDBName() const {
    string s = name;
    int n = s.length();

    int res_ind = 0;
    for (int i = 0; i < n; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z')
            || (s[i] >= 'A' && s[i] <= 'Z')
            || (s[i] >= '0' && s[i] <= '9'))
            s[res_ind++] = s[i];
        else {
            s[i + 1] = toupper(s[i + 1]);
            continue;
        }
    }

    return s.substr(0, res_ind);
}

string ContactField::getTitle() const {
    return name;
}
