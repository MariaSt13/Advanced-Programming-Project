#include "StartCommand.h"
#include "GameListManager.h"
#include "ServerDataManager.h"
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

    //if there is no game with this name
    if(GameListManager::getInstance()->getGame(name) == NULL){
       //create a new game and push to games list
       Game* g = new Game(name,firstPlayerSocket);
       GameListManager::getInstance()->addGame(g);
       cout << "game started";
    }

    //if game with this name is already exist
    else{
       returnVal = -1;
    }

    int n = write(firstPlayerSocket, &returnVal, sizeof(returnVal));

    //error
    if(n == -1) {
        throw "error writing to socket";
    }

    if(returnVal == -1){
        //close client socket
        ServerDataManager::getInstance()->removeSocket(firstPlayerSocket);
    }
}