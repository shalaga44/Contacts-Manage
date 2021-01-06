//
// Created by shalaga44 on 1/5/21.
//

#ifndef DESKTOP_APPLICATION_UI_H
#define DESKTOP_APPLICATION_UI_H

#include <ncurses.h>
#include <Controller/Controller.h>
#include <vector>
#include <string>

using namespace std;

class UI {
private:


    void Initialization();

    Controller controller;

public:

    UI(const Controller &controller);

    ~UI();

//    void ChoiceUI(vector<Contact> vector);

    void ListContactUI();

    void DeleteContactUI();

    void updateContactUI();

    void AddContactUI();

    void SearchContactUI();

    void MainOptionsUI();

    string getInputString();

    void SearchUI();

    void SingleContactUI(Contact contact);
};

#endif //DESKTOP_APPLICATION_UI_H
