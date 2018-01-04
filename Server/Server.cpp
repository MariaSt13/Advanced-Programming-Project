
#include "Server.h"
#include "ServerDataManager.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <sstream>

using namespace boost;
using namespace std;

/**
 * constructor.
 * @param port-port number.
 */
Server::Server(int port): port(port), serverSocket(0), serverThreadId(0){
    cout << "Server" << endl;
}

/**
 * Open server for connecting clients.
 */
void Server::start() {
    
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
    pthread_create(&serverThreadId, NULL, &acceptClients, reinterpret_cast<void *>(serverSocket));
}

/**
 * Handle requests from a specific client.
 * @param clientSocket - the server reads from this client.
 */
void* Server::handleClient(void* socket) {
    ServerDataManager::getInstance()->addPthread(pthread_self());
    long clientSocket = (long) socket;
    char s[ARRAY_SIZE] = {0};
    string command;
    vector<string> argsToCommand;

    //read a new command
    int n = read(clientSocket, &s, sizeof(s));

    //error
    if (n == -1) {
        cout << "Error reading command" << endl;
        return NULL;
    }

    //clientSocket disconnected
    if (n == 0) {
        cout << "Client disconnected" << endl;
        return NULL;
    }

    split(argsToCommand,s,is_any_of(" "));
    command = argsToCommand.at(0);
    argsToCommand.erase(argsToCommand.begin());
    stringstream ss;
    ss << clientSocket;
    argsToCommand.push_back(ss.str());

    CommandsManager::getInstance()->executeCommand(command,argsToCommand);
    ServerDataManager::getInstance()->removePthread(pthread_self());
}

void* Server::acceptClients(void *socket) {
    long serverSocket = (long) socket;
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen = sizeof((struct sockaddr*) &clientAddress);

    while(true){
        //connection to client.
        cout << "Waiting for client connections..." << endl;

        //accept a new client connection
        int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);
        cout << "Client connected" << endl;
        ServerDataManager::getInstance()->addSocket(clientSocket);

        if (clientSocket == -1) {
            throw "Error on accept";
        }

        pthread_t threadId;
        pthread_create(&threadId, NULL,(&handleClient), reinterpret_cast<void *>(clientSocket));
    }
}
/**
 * close server.
 */
void Server::stop() {
    ServerDataManager::getInstance()->removeAllSockets();
    ServerDataManager::getInstance()->removeAllPthreads();
    pthread_cancel(this->serverThreadId);
    close(serverSocket);
}
