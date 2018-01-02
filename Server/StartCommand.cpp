//
// Created by linoy on 27/12/17.
//

#include "StartCommand.h"
#include <sstream>
#include <unistd.h>
#include <iostream>

using namespace std;

void StartCommand::execute(vector<string> args){
    string name = args.at(0);
    istringstream is(args.at(1));
    int firstPlayerSocket;
    is >> firstPlayerSocket;
    int returnVal = 0;

    //loop go over games list and look for game with the same name
    for (vector<Game*>::const_iterator it = this->games.begin(); it < this->games.end(); it++) {
        //if equal set returnVal to -1
        if((*it)->getName() == name){
            returnVal = -1;
            break;
        }
    }

    //create a new game and push to games list
    if(returnVal == 0){
        Game* g = new Game(name,firstPlayerSocket);
        this->games.push_back(g);
        cout << "game started";
    }


    int n = write(firstPlayerSocket, &returnVal, sizeof(returnVal));

    //error
    if(n == -1) {
        throw "error writing to socket";
    }
}