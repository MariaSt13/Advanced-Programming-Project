//
// Created by maria on 29/12/17.
//

#include "CommandMenu.h"
#include <iostream>
#include <unistd.h>

using namespace std;

void CommandMenu::runMenu(int clientSocket) {
    cout << "Please select an option:" << endl;
    cout << "start <name> - to start a new game with that name " << endl;
    cout << "list_games - to see games that can be joined" <<  endl;
    cout << "join <name> - to join a game with that name" << endl;

    string input;
    cin >> input;

    const char* s = input.c_str();
    int n = write(clientSocket, &s, input.length());
    //error
    if(n == -1) {
        throw "error writing to socket";
    }

}
