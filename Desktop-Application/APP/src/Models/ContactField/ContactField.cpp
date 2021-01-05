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

string ContactField::getDBName() {
    int n = name.length();
    int res_ind = 0;
    for (int i = 0; i < n; i++) {
        if ((name[i] >= 'a' && name[i] <= 'z')
            || (name[i] >= 'A' && name[i] <= 'Z')
            || (name[i] >= '0' && name[i] <= '9'))
            name[res_ind++] = name[i];
        else {
            name[i + 1] = toupper(name[i + 1]);
            continue;
        }
    }

    return name.substr(0, res_ind);
}
