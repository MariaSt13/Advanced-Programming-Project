//
// Created by maria on 29/12/17.
//

#include "CommandMenu.h"
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;
CommandMenu::CommandMenu(Display *display, Client* client): display(display), client(client) {

}
void CommandMenu::runMenu() {


    string command;
   do {
       //connect to server
       try {
           client->connectToServer();
       } catch (char const *msg) {
           cout << "Failed to connect to server. Reason:" << msg << endl;
           exit(1);
       }
       int clientSocket = client->getClientSocket();
       display->commandMenu();

       char input[56];
       cin.ignore();
       cin.getline(input, sizeof(input));
       cin.ignore();

       //const char *s = input.c_str();
       int n = write(clientSocket, &input, sizeof(input));
       //error
       if (n == -1) {
           throw "error writing to socket";
       }

       vector<string> args;
       split(args,input,is_any_of(" "));
       command = args.at(0);
   } while (command == "list_games");
}
