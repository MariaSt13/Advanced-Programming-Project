//
// Created by linoy on 27/12/17.
//

#include <unistd.h>
#include <sstream>
#include <iostream>
#include "ListGamesCommand.h"
using namespace std;

ListGamesCommand::ListGamesCommand() {

}

void ListGamesCommand::execute(vector<string> args) {
    istringstream is(args.at(0));
    int clientSocket;
    is >> clientSocket;
    string result;

    //loop go over games list and look for games that can be joined
    for (vector<Game*>::const_iterator it = listGames.begin(); it < listGames.end(); it++) {
        //if the game is not running yet
        if(!(*it)->getStatus() == Game::waiting){
            string name = (*it)->getName();
            result = result + name + "\n";
        }
    }

    //write result to client socket
    const char* s = result.c_str();
    cout << "list games!!";
    int n = write(clientSocket, &s, result.length());

    //error
    if(n == -1) {
        throw "error writing to socket";
    }

    //close client socket
    close(clientSocket);
}
