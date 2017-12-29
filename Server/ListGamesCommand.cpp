//
// Created by linoy on 27/12/17.
//

#include <unistd.h>
#include <sstream>
#include "ListGamesCommand.h"

ListGamesCommand::ListGamesCommand() {

}

void ListGamesCommand::execute(vector<string> args) const {
    istringstream is(args.at(0));
    int playerSocket;
    is >> playerSocket;
    string result;

    //loop go over games list and look for games that can be joined
    for (vector<Game*>::const_iterator it = this->games.begin(); it < this->games.end(); it++) {
        //if the game is not running yet
        if(!(*it)->getStatus() == Game::waiting){
            string name = (*it)->getName();
            result = result + name + "\n";
        }
    }

    //write result to client socket
    const char* s = result.c_str();
    int n = write(playerSocket, &s, result.length());

    //error
    if(n == -1) {
        throw "error writing to socket";
    }
}
