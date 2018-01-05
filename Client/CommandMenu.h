#ifndef EX4_COMMANDMENU_H
#define EX4_COMMANDMENU_H
#define ARRAY_SIZE 56

#include "UserInterface.h"
#include "Client.h"

class CommandMenu {
public:
    CommandMenu(UserInterface* userInterface, Client* client);
    void runMenu();

private:
    UserInterface* userInterface;
    Client* client;
};


#endif //EX4_COMMANDMENU_H
