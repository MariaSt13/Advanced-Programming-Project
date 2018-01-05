
#include "CommandMenu.h"
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

/**
 * constructor.
 * @param userInterface - for interaction with the user.
 * @param client - the client.
 */
CommandMenu::CommandMenu(UserInterface *userInterface, Client* client): userInterface(userInterface), client(client) {}


/**
 * Display to the user all the possible commands
 * and let the user choose.
 */
void CommandMenu::runMenu() {
    bool gameStarted = false;
    string command;

   //loop run while the game is not start
   do {
       //connect to server
       client->connectToServer();
           
       int clientSocket = client->getClientSocket();
       userInterface->commandMenu();
       string input = userInterface->getCommand();

       int n = write(clientSocket, input.c_str(), input.length());
       //error
       if (n == -1) {
           throw "error writing to socket";
       }
       if (n == 0) {
           throw "disconnected";
       }

       int invalidInput;
       n = read(clientSocket, &invalidInput, sizeof(invalidInput));
       //error
       if (n == -1) {
           throw "Error reading from socket";
       }
       if (n == 0) {
           throw "disconnected";
       }

       vector<string> args;
       split(args,input,is_any_of(" "));
       command = args.at(0);

       //if the input is valid
       if(!invalidInput){
           //start command
           if (command == "start") {
               int returnValue;
               int n = read(clientSocket, &returnValue, sizeof(returnValue));
               //error
               if (n == -1) {
                   throw "Error reading from socket";
               }
               if (n == 0) {
                   throw "disconnected";
               }
               if(returnValue == -1) {
                   userInterface->nameTaken();
               } else if(returnValue == -2) {
                   userInterface->nameNotEntered();
               }
               else{
                   gameStarted = true;
               }
           }

               //join command
           else if (command == "join") {
               int returnValue;
               int n = read(clientSocket, &returnValue, sizeof(returnValue));
               //error
               if (n == -1) {
                   throw "Error reading from socket";
               }
               if (n == 0) {
                   throw "disconnected";
               }
               if(returnValue == -1) {
                   userInterface->noSuchGame();
               } else if( returnValue == -2) {
                   userInterface->nameNotEntered();
               }
               else{
                   gameStarted = true;
               }
           }

               //list games command
           else if (command == "list_games") {
               // read the length of the list
               int length;
               int n = read(clientSocket, &length, sizeof(length));

               if (n == -1) {
                   throw "Error reading from socket";
               }
               if (n == 0) {
                   throw "disconnected";
               }

               //read the list
               char list[length+1] = {0};
               n = read(clientSocket, &list, sizeof(list));
               if (n == -1) {
                   throw "Error reading from socket";
               }
               if (n == 0) {
                   throw "disconnected";
               }
               userInterface->printListGames(list);
           }
       }
       else
           userInterface->invalidTryAgain();

   } while (!gameStarted);
}
