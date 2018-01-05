#ifndef EX4_COMMANDMENU_H
#define EX4_COMMANDMENU_H
#define ARRAY_SIZE 56

#include "UserInterface.h"
#include "Client.h"
/**
 * This class runs the client-server
 * communication protocol menu. The class
 * display to the user all the possible commands
 * and let the user choose.
 */
class CommandMenu {
public:
    //constructor
    CommandMenu(UserInterface* userInterface, Client* client);

    //run the menu
    void runMenu();

private:
    UserInterface* userInterface;
    Client* client;
};


#endif //EX4_COMMANDMENU_H
