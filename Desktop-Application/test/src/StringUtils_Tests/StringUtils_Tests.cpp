//
// Created by shalaga44 on 1/5/21.
//

#include "../../include/tests.h"

void search_test();

void string_lower_test();

int main() {
    search_test();
    string_lower_test();
    return 0;
}

void string_lower_test() {
    assert(transformToLower("Mohamed Moawia") == "mohamed moawia");
    assert(transformToLower("Mohamed_Moawia") == "mohamed_moawia");
    assert(transformToLower("Mohamed_Moawia123") == "mohamed_moawia123");
}

void search_test() {
    assert(isContaining("Mohamed Moawia", "Mohamed"));
    assert(isContaining("Mohamed Moawia", "mohamed"));
    assert(!isContaining("Mohamed Moawia", "mohaed"));
    assert(isContaining("01234567", "567"));
    assert(!isContaining("01234567", "657"));
}
