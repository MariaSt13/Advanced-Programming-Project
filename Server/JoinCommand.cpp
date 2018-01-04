//
// Created by linoy on 27/12/17.
//

#include <sstream>
#include <unistd.h>
#include <iostream>
#include "JoinCommand.h"
#include "GameManager.h"
#include "GameListManager.h"

/**
 * constructor.
 */
JoinCommand::JoinCommand() {

}

/**
 * execute client request: adding him to the game.
 * @param args - arguments vector.
 */
void JoinCommand::execute(vector<string> args){

    string name = args.at(0);
    istringstream is(args.at(1));
    int secondPlayerSocket;
    is >> secondPlayerSocket;
    int returnVal = -1;
    GameManager gameManager = NULL;

    Game* game = GameListManager::getInstance()->getGame(name);

    //check if the game is exist
    if(game != NULL){

        //check if the player can join to the game
        if(game->getStatus() == Game::waiting){
            returnVal = 0;
            game->joinToGame(secondPlayerSocket);
            gameManager = GameManager(game);
        }

    }

    int n = write(secondPlayerSocket, &returnVal, sizeof(returnVal));

    //error
    if(n == -1) {
        throw "error writing to socket";
    }

    //if the process ended successfully
    if(returnVal == 0){
        //run the game
        gameManager.run();
    }

}
