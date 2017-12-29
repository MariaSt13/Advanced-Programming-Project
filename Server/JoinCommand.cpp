//
// Created by linoy on 27/12/17.
//

#include <sstream>
#include <unistd.h>
#include "JoinCommand.h"

JoinCommand::JoinCommand() {

}

void JoinCommand::execute(vector<string> args) const {

    string name = args.at(0);
    istringstream is(args.at(1));
    int secondPlayerSocket;
    is >> secondPlayerSocket;

    bool validChoice = false;

    //loop go over games list and look for game with the same name
    for (vector<Game*>::const_iterator it = this->games.begin(); it < this->games.end(); it++) {
        //check a game with this name exists and can be joined
        if((*it)->getName() == name && !(*it)->getStatus() == Game::waiting){
            validChoice = true;
            (*it)->joinToGame(secondPlayerSocket);
            // also close sockets and open socket for game and run gameRoom

            break;
        }
    }
    // there is no game with this name or its already running
    if(!validChoice) {
        char s[1] = {-1};
        int n = write(secondPlayerSocket, &s, sizeof(s));

        //error
        if(n == -1) {
            throw "error writing to socket";
        }
    }
}
