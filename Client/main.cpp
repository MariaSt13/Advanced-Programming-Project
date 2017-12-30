
#include "Menu.h"
#include "ConsoleDisplay.h"

int main() {

    //create a new game.
    Display* display = new ConsoleDisplay();
    Menu menu = Menu(8,8, display);
    delete(display);
}