#include <unistd.h>
#include <sstream>
#include <iostream>
#include "ListGamesCommand.h"
#include "GameListManager.h"
#include "ServerDataManager.h"

using namespace std;

/**
 * Execute client request: return a list
 * of games that the user can join them.
 * @param args - arguments vector.
 */
void ListGamesCommand::execute(vector<string> args) {
    istringstream is(args.at(0));
    int clientSocket;
    is >> clientSocket;

    string result = GameListManager::getInstance()->getListOfWaitingGames();

    //write result to client socket
    const char* s = result.c_str();

    //send length of list
    int length = result.length();
    if (length == 0) {
        result = "There are no games in the list yet.";
        length = result.length();
        s = result.c_str();
    }
    int n = write(clientSocket, &length, sizeof(length));

    //error
    if(n == -1) {
        cout << "error writing to socket" << endl;
        return;
    }

    //send the list
    n = write(clientSocket, s, result.length());

    //error
    if(n == -1) {
        cout << "error writing to socket" << endl;
        return;
    }
    if (n == 0) {
        cout << "Client disconnected" << endl;
        return;
    }

    //close client socket
    ServerDataManager::getInstance()->removeSocket(clientSocket);
}
