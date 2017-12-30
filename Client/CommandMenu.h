//
// Created by maria on 29/12/17.
//

#ifndef EX4_COMMANDMENU_H
#define EX4_COMMANDMENU_H


#include "Display.h"

class CommandMenu {
public:
    CommandMenu(Display* display);
    void runMenu(int clientSocket);

private:
    Display* display;
};


#endif //EX4_COMMANDMENU_H
