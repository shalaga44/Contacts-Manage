//
// Created by shalaga44 on 1/5/21.
//

#include <string>
#include <utility>
#include "../../../APP/include/ContactField/ContactField.h"

ContactField::ContactField(string name)
        : name(std::move(name)) {}

ContactField::ContactField(string name, bool hasMultipleValues) :
        name(std::move(name)),
        hasMultipleValues(hasMultipleValues) {}

string ContactField::getDBName() {
    return name;
}
