
#include <iostream>
#include "Menu.h"
#include "ConsoleInterface.h"

int main() {

    //create a new game.
    UserInterface* userInterface = new ConsoleInterface();
    try {
        Menu(8, 8, userInterface);
    } catch (char const* msg) {
        cout << "Error:" << msg << endl;
        delete(userInterface);
        return 1;
    }
    delete(userInterface);
    return 0;
}