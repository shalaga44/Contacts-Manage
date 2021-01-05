//
// Created by shalaga44 on 1/5/21.
//
#include "../../../include/Utils/StringUtils/StringUtils.h"

bool isContaining(string text, string searchText) {
    const string &lowerText = transformToLower(text);
    const string &lowerSearchText = transformToLower(searchText);
    size_t found = lowerText.find(lowerSearchText);
    if (found != string::npos) {
        return true;
    }
    return false;
}

char asciitolower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

string transformToLower(string text) {
    string lowerText = text;
    for (char & charRef : lowerText) {
        charRef = asciitolower(charRef);
    }
    return lowerText;
}
