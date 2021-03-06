#include <sstream>
#include <unistd.h>
#include <iostream>
#include "JoinCommand.h"
#include "GameManager.h"
#include "GameListManager.h"

/**
 * Execute client request: adding him to the game.
 * @param args - arguments vector.
 */
void JoinCommand::execute(vector<string> args){
    int returnVal = -1;
    int secondPlayerSocket;
    istringstream is(args.at(0));
    is >> secondPlayerSocket;
    GameManager gameManager = NULL;

    //if arguments vector is valid
    if(args.size() >= 2){
        string name = args.at(1);

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
    // not enough arguments
    } else {
        returnVal = -2;
    }


    int n = write(secondPlayerSocket, &returnVal, sizeof(returnVal));

    //error
    if(n == -1) {
        cout << "error writing to socket" << endl;
        return;
    }
    if (n == 0) {
        cout << "Client disconnected" << endl;
        return;
    }

    //if the process ended successfully
    if(returnVal == 0){
        //run the game
        gameManager.run();
    }

}
