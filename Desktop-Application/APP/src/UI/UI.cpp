//
// Created by shalaga44 on 1/5/21.
//

#include <Models/Contact/Contact.h>
#include "../../../APP/include/UI/UI.h"

void UI::Initialization() {

    initscr();
    curs_set(0);
//    MainOptionsUI();

}

void UI::MainOptionsUI() {
    string options[] = {
            "x: close program",
            "l: list contacts",
            "a: add contact",
            "d: delete contact",
            "u: update contact",
            "s: search for contact",
    };

    bool mainLoop = true;
    while (mainLoop) {

        clear();
        printw("Options:");
        for (string o: options) {
            printw(("\n\t" + o).c_str());
        }
        int ch = getch();
        switch (ch) {
            case 'l':
                ListContactUI();
                break;
            case 'd':
                DeleteContactUI();
                break;
            case 'u':
                updateContactUI();
                break;
            case 'a':
                AddContactUI();
                break;
            case 's':
                SearchContactUI();
                break;
            case 'x':
                mainLoop = false;
                break;
            default:
                break;

        }

    }
}

UI::~UI() {
    endwin();
}

string UI::getInputString() {
    string input;
    nocbreak();


    int ch = getch();

    while (ch != '\n') {
        input.push_back(ch);
        ch = getch();
    }


    return input;
}

void liveInput(string &input, bool &isEnterPressed) {
    int ch = getch();
    if (ch == ERR) return;
    if (ch == '\n') { isEnterPressed = true; }
    if (ch == 127) {
        if (!input.empty())
            input.pop_back();
    } else input.push_back(ch);
}

bool liveInput(string &input) {
    int ch = getch();
    if (ch == ERR) return true;
    if (ch == '\n') { return false; }
    if (ch == 127) {
        if (!input.empty())
            input.pop_back();
    } else input.push_back(ch);
    return true;
}

bool liveInput(string &input, int y, int x) {
    int ch = getch();
    if (ch == ERR) {
        return true;
    }
    if (ch == '\n') {
        return false;
    }
    if (ch == 127) {
        if (!input.empty()) {
            int oldY, oldX;
            getyx(stdscr, oldY, oldX);
            mvprintw(y, x + input.length() - 1, " ");
            input.pop_back();
            move(oldY, oldX);
        }
    } else {
        int oldY, oldX;
        getyx(stdscr, oldY, oldX);
        input.push_back(ch);
        mvprintw(y, x, input.c_str());
        move(oldY, oldX);


    };
    return true;
}


void UI::SearchUI() {
//    noecho();
////    cbreak();
////    nodelay(stdscr, true);
////    timeout(-1);
//    curs_set(0);
//    vector<Contact> &Contacts = *new vector<Contact>();
//    int y, x;
//    string input = "  ";
//    while (!input.empty()) input.pop_back();
//    bool isEnterPressed = false;
//
//    vector<Contact> &matchList = *new vector<Contact>();
//    while (true) {
//        matchList = controller.search(input);
//        if (isEnterPressed) {
//            printw(to_string(matchList.size()).c_str());
////            ChoiceUI(matchList);
//            break;
//        }
//        liveInput(input, isEnterPressed);
//
//        clear();
//        printw(input.c_str());
//        y = x = 0;
//        for (const Contact &c:matchList) {
//            move(++y, x);
//            printw((c.get(CONTACT_DATABASE_FIELD_ID) + "- " + c.get(CONTACT_FIELD_NAME).c_str()).c_str());
//        }
//    }


}

//void UI::ChoiceUI(vector<Contact> contacts) {
//    keypad(stdscr, true);
//    printw(to_string(contacts.size()).c_str());
//    int _choice, x, y;
//    int highlight = 0;
//
//    bool isEnterPressed = false;
//    while (!isEnterPressed) {
//        _choice = wgetch(stdscr);
//        switch (_choice) {
//            case KEY_UP:
//                highlight--;
//                if (highlight < -1) highlight = 0;
//                break;
//            case KEY_DOWN:
//                highlight++;
//                if (highlight > contacts.size()) highlight = contacts.size() - 1;
//                break;
//            case KEY_ENTER:
//                isEnterPressed = true;
//                break;
//            default:
//                break;
//
//        }
//        x = y = 0;
//        for (int i = 0; i < contacts.size(); ++i) {
////            if (i == highlight)
//            wattron(stdscr, A_REVERSE);
//            move(++y, x);
//            printw(contacts[i].get(CONTACT_FIELD_NAME).c_str());
////            wattroff(stdscr, A_REVERSE);
//        }
//
//
//    }
//    keypad(stdscr, false);
//
//}

void UI::ListContactUI() {
    clear();
    noecho();
    string header = "List Contact:";
    const int headerLength = header.length();
    printw(header.c_str());

    int i = 0;
    auto contactsList = DB.search("mo");
    for (const auto &c: contactsList) {
        printw(("\n\t" + to_string(i++) + "- " + c.get(CONTACT_FIELD_NAME)).c_str());

    }
    string input;
    while (liveInput(input, 0, headerLength)) {}
    int index;
    try { index = stoi(input); }
    catch (std::invalid_argument &e) { return; }

    int id = contactsList[index].getId();
    auto contact = DB.contactAt(id);
    SingleContactUI(contact);


}

void UI::DeleteContactUI() {
    clear();
    noecho();
    string header = "Delete Contact:";
    const int headerLength = header.length();
    printw(header.c_str());

    int i = 0;
    auto contactsList = DB.search("mo");
    for (const auto &c: contactsList) {
        printw(("\n\t" + to_string(i++) + "- " + c.get(CONTACT_FIELD_NAME)).c_str());

    }
    string input;
    while (liveInput(input, 0, headerLength)) {}
    int index;
    try { index = stoi(input); }
    catch (std::invalid_argument &e) { return; }

    int id = contactsList[index].getId();
    DB.remove(id);

}

void UI::updateContactUI() {
    clear();
    printw("Update Contact:");
    getch();
}

void UI::AddContactUI() {
    clear();
    noecho();
    string header = "Add Contact:";
    printw(header.c_str());
    string input;
    auto c = Contact();
    int y, x;
    for (const ContactField& field: CONTACTS_FIELDS_LIST) {
        input = "";
        string text = "\n\t" + field.getTitle() + ": ";
        printw(text.c_str());
        getyx(stdscr, y, x);
        while (liveInput(input, y, x)) {}
        c.set(field, input);
        clrtoeol();
        move(0, header.length());
    }


    DB.addContact(c);
}

void UI::SearchContactUI() {
    clear();
    noecho();
    string header = "Search for Contact:";
    const int headerLength = header.length();
    printw(header.c_str());
    auto contactsList = DB.search("");
    int i = 0;
    for (auto c: contactsList) {
        printw(("\n\t" + to_string(i++) + "- " + c.get(CONTACT_FIELD_NAME)).c_str());

    }

    bool isInputChanged = false;

    string input, oldInput;
    while (liveInput(input)) {
        if (oldInput != input) isInputChanged = true;
        if (isInputChanged) {
            clear();
            noecho();
            move(0, 0);
            printw(header.c_str());
            printw(input.c_str());
            int i = 0;
            for (const auto &c: DB.search(input)) {
                printw(("\n\t" + to_string(i++) + "- " + c.get(CONTACT_FIELD_NAME)).c_str());

            }
            oldInput = input;
            isInputChanged = false;
        }
    }

    int index;
    try { index = stoi(input); }
    catch (std::invalid_argument &e) { return; }

    int id = contactsList[index].getId();
    auto contact = DB.contactAt(id);
    SingleContactUI(contact);

}

UI::UI() {
    Initialization();

}

void UI::SingleContactUI(Contact contact) {
    clear();
    noecho();
    printw("Contact:");
    for (ContactField field: CONTACTS_FIELDS_LIST) {
        string value = contact.get(field);
        string fieldName = field.getTitle();
        if (value.empty()) continue;
        printw(("\n\t" + fieldName + ": " + value).c_str());
    }
    getch();

}



