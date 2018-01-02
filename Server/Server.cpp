
#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <boost/algorithm/string.hpp>
using namespace boost;
using namespace std;

/**
 * constructor.
 * @param port-port number.
 */
Server::Server(int port,CommandsManager *commandManager): port(port),commandManager(commandManager), serverSocket(0),openServer(true){
    cout << "Server" << endl;
}

/**
 * open server for connecting clients.
 */
void Server::start() {

    //array of clients socket
    int clientSocket[MAX_CONNECTED_CLIENTS];

    // Create a socket point
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    //error with socket.
    if (serverSocket == -1) {
        throw "Error opening socket";
    }

    // Assign a local address to the socket
    struct sockaddr_in serverAddress;
    bzero((void *)&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);

    //error.
    if (bind(serverSocket, (struct sockaddr
    *)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }


    //Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    // Define the client socket's structures
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen = sizeof((struct sockaddr*) &clientAddress);

    while(true){
        openServer = true;
        //connection to client.
        cout << "Waiting for client connections..." << endl;

        //accept a new client connection
        int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);
        cout << "Client connected" << endl;

        if (clientSocket == -1) {
            throw "Error on accept";
        }

        handleClient(clientSocket);

        close(clientSocket);
        }


}

/**
 * Handle requests from a specific client.
 * @param clientSocket1 - the server reads from this client.
 * @param clientSocket2 - the server writes to this client.
 */
void Server::handleClient(int clientSocket) {
    char s[ARRAY_SIZE] = {0};
    string command;
    vector<string> args;

    //read a new move
    int n = read(clientSocket, &s, sizeof(s));

    //the game is over
    if(strcmp(s, "End") == 0){
        this->openServer = false;
        return;
    }

    //error
    if (n == -1) {
        cout << "Error reading arg1" << endl;
        this->openServer = false;
        return;
    }

    //clientSocket disconnected
    if (n == 0) {
        cout << "Client disconnected" << endl;
        this->openServer = false;
        return;
    }

    split(args,s,is_any_of(" "));
    command = args.at(0);
    args.erase(args.begin());
    commandManager->executeCommand(command,args);
}

/**
 * close server.
 */
void Server::stop() {
    close(serverSocket);
}
