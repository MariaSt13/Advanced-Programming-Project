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
    bool gameStarted = false;


    string command;
    cin.ignore();
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

       char input[ARRAY_SIZE] = {0};
       cin.getline(input, sizeof(input));

       int n = write(clientSocket, &input, sizeof(input));
       //error
       if (n == -1) {
           throw "error writing to socket";
       }

       vector<string> args;
       split(args,input,is_any_of(" "));
       command = args.at(0);

       if (command == "start") {
           int returnValue;
           int n = read(clientSocket, &returnValue, sizeof(returnValue));
           //error
           if (n == -1) {
               throw "Error reading from socket";
           }
           if(returnValue == -1) {
               cout << "This name is already taken. please try a different name" << endl;
           }
           else{
               gameStarted = true;
           }
       }

       if (command == "join") {
           int returnValue;
           int n = read(clientSocket, &returnValue, sizeof(returnValue));
           //error
           if (n == -1) {
               throw "Error reading from socket";
           }
           if(returnValue == -1) {
               cout << "game not exist, please choose an exist game" << endl;
           }
           else{
               gameStarted = true;
           }
       }

   } while (!gameStarted);
}
