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
    cout <<"list size: "<< listGames.size()<<" ";
    for (vector<Game*>::const_iterator it = listGames.begin(); it < listGames.end(); it++) {
        //if equal set returnVal to -1
        if((*it)->getName() == name){
            returnVal = -1;
            break;
        }
    }

    //create a new game and push to games list
    if(returnVal == 0){
        Game* g = new Game(name,firstPlayerSocket);
        listGames.push_back(g);
        cout << "game started";
    }


    int n = write(firstPlayerSocket, &returnVal, sizeof(returnVal));

    //error
    if(n == -1) {
        throw "error writing to socket";
    }

    if(returnVal == -1){
        //close client socket
        close(firstPlayerSocket);
    }
}