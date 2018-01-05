
#include "Menu.h"
#include "ConsoleInterface.h"

int main() {

    //create a new game.
    UserInterface* userInterface = new ConsoleInterface();
    Menu menu = Menu(8,8, userInterface);
    delete(userInterface);
}