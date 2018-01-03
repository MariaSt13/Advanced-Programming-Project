//
// Created by linoy on 27/12/17.
//

#include <sstream>
#include <unistd.h>
#include <iostream>
#include "JoinCommand.h"
#include "GameManager.h"

JoinCommand::JoinCommand() {

}

void JoinCommand::execute(vector<string> args){

    string name = args.at(0);
    istringstream is(args.at(1));
    int secondPlayerSocket;
    is >> secondPlayerSocket;
    int returnVal = -1;
    GameManager gameManager = NULL;

    cout <<"list size: "<<listGames.size()<<" ";
    //loop go over games list and look for game with the same name
    for (vector<Game*>::const_iterator it = listGames.begin(); it < listGames.end(); it++) {

        //check a game with this name exists and can be joined
        cout  <<"status: "<< (*it)->getStatus();
        if((*it)->getName() == name && (*it)->getStatus() == Game::waiting){
            returnVal = 0;
            (*it)->joinToGame(secondPlayerSocket);
            //close sockets and open socket for game

            gameManager = GameManager(*it);
            break;
        }
    }

    int n = write(secondPlayerSocket, &returnVal, sizeof(returnVal));

    //error
    if(n == -1) {
        throw "error writing to socket";
    }

    if(returnVal == 0){
        //run the game
        gameManager.run();
    }

}
