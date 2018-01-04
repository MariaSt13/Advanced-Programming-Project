
#include <unistd.h>
#include <sstream>
#include "ListGamesCommand.h"
#include "GameListManager.h"
#include "ServerDataManager.h"

using namespace std;

ListGamesCommand::ListGamesCommand() {

}

void ListGamesCommand::execute(vector<string> args) {
    istringstream is(args.at(0));
    int clientSocket;
    is >> clientSocket;

    string result = GameListManager::getInstance()->getListOfWaitingGames();

    //write result to client socket
    const char* s = result.c_str();
    int length = result.length();
    // send length of list
    int n = write(clientSocket, &length, sizeof(length));
    //error
    if(n == -1) {
        throw "error writing to socket";
    }

    // send the list
    n = write(clientSocket, s, result.length());

    //error
    if(n == -1) {
        throw "error writing to socket";
    }

    //close client socket
    ServerDataManager::getInstance()->removeSocket(clientSocket);
}
