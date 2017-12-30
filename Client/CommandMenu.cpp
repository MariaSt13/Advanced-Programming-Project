//
// Created by maria on 29/12/17.
//

#include "CommandMenu.h"
#include <iostream>
#include <unistd.h>

using namespace std;

CommandMenu::CommandMenu(Display *display): display(display) {

}
void CommandMenu::runMenu(int clientSocket) {
    display->commandMenu();

    string input;
    cin >> input;

    const char* s = input.c_str();
    int n = write(clientSocket, &s, input.length());
    //error
    if(n == -1) {
        throw "error writing to socket";
    }

}
