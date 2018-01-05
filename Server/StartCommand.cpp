#include "StartCommand.h"
#include "GameListManager.h"
#include "ServerDataManager.h"
#include <sstream>
#include <unistd.h>

using namespace std;

/**
 * Execute client request: create a
 * new game and add it to the games list.
 * @param args - arguments vector.
 */
void StartCommand::execute(vector<string> args){
    int returnVal = -1;
    int firstPlayerSocket;
    istringstream is(args.at(0));
    is >> firstPlayerSocket;

    //if arguments vector is valid
    if(args.size() >= 2){
        string name = args.at(1);

        //if there is no game with this name
        if(GameListManager::getInstance()->getGame(name) == NULL){
            //create a new game and push to games list
            Game* g = new Game(name,firstPlayerSocket);
            GameListManager::getInstance()->addGame(g);
            returnVal = 0;
        }
    // not enough arguments
    } else {
        returnVal = -2;
    }

    int n = write(firstPlayerSocket, &returnVal, sizeof(returnVal));

    //error
    if(n == -1) {
        throw "error writing to socket";
    }

    if(returnVal != 0){
        //close client socket
        ServerDataManager::getInstance()->removeSocket(firstPlayerSocket);
    }
    ServerDataManager::getInstance()->removePthread(pthread_self());
}