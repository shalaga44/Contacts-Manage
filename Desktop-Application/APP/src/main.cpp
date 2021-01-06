#include "main.h"

int main() {
    UI app(Controller(Database("main.DB")));
    app.MainOptionsUI();

    return 0;
}
