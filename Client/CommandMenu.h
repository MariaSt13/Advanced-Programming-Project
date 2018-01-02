//
// Created by maria on 29/12/17.
//

#ifndef EX4_COMMANDMENU_H
#define EX4_COMMANDMENU_H
#define ARRAY_SIZE 56

#include "Display.h"
#include "Client.h"

class CommandMenu {
public:
    CommandMenu(Display* display, Client* client);
    void runMenu();

private:
    Display* display;
    Client* client;
};


#endif //EX4_COMMANDMENU_H
