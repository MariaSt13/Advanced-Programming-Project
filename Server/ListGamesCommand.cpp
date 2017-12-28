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

    //loop go over games list and look fot games that can be joined
    for (vector<Game*>::const_iterator it = this->games.begin(); it < this->games.end(); it++) {
        //if the game is not running yet
        if(!(*it)->isRun()){
            string name = (*it)->getName();
            const char* s = name.c_str();
            int n = write(playerSocket, &s, name.length());

            //error
            if(n == -1) {
                throw "error writing to socket";
            }
        }
    }
}
