//
// Created by linoy on 27/12/17.
//

#include <sstream>
#include <unistd.h>
#include <iostream>
#include "JoinCommand.h"
#include "GameManager.h"
#include "GameListManager.h"

JoinCommand::JoinCommand() {

}

void JoinCommand::execute(vector<string> args){

    string name = args.at(0);
    istringstream is(args.at(1));
    int secondPlayerSocket;
    is >> secondPlayerSocket;
    int returnVal = -1;
    GameManager gameManager = NULL;

    Game* g = GameListManager::getInstance()->getGame(name);
    //check if the game is exist
    if(g != NULL){

        //check if the player can join to the game
        if( g->getStatus() == Game::waiting){
            returnVal = 0;
            g->joinToGame(secondPlayerSocket);
            //close sockets and open socket for game

            gameManager = GameManager(g);
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
