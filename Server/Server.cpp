
#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <cerrno>

using namespace std;

/**
 * constructor.
 * @param port-port number.
 */
Server::Server(int port): port(port), serverSocket(0),openServer(true) {
    cout << "Server" << endl;
}

/**
 * initialize server.
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


    // Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);

    int clientSocket[MAX_CONNECTED_CLIENTS];
    while(true){
        //connection all clients.
        for (int i = 0; i < MAX_CONNECTED_CLIENTS; i++) {
            // Define the client socket's structures
            struct sockaddr_in clientAddress;
            socklen_t clientAddressLen;

            //connection to client.
            cout << "Waiting for client connections..." << endl;

            //accept a new client connection
            clientSocket[i] = accept(serverSocket, (struct
                    sockaddr *)&clientAddress, &clientAddressLen);
            cout << "Client connected" << endl;

            if (clientSocket[i] == -1) {
                char buffer[256];
                char *errorMessage = strerror_r(errno, buffer, 256); // get string message from errno
                throw "Error on accept";
            }
        }

        //send to client his number.1- black , 2-white.
        for (int i = 0; i < MAX_CONNECTED_CLIENTS; i++) {
            int result =  i+1;
            int n = write(clientSocket[i], &result, sizeof(result));
            if (n == -1) {
                cout << "Error writing to socket" << endl;
                return;
            }
        }

        //while the game is run.
        while(openServer){
            for (int i = 0; i < MAX_CONNECTED_CLIENTS; i++) {
                handleClient(clientSocket[i] ,clientSocket[(i+1) % 2]);
            }
        }

        for (int i = 0; i < MAX_CONNECTED_CLIENTS; i++) {
            // Close communication with the client
            close(clientSocket[i]);
        }
    }

}

/**
 *  * Handle requests from a specific client.
 * @param clientSocket1
 * @param clientSocket2
 */
void Server::handleClient(int clientSocket1,int clientSocket2) {
    char s[7] = {0};

    //read new exercise arguments
    int n = read(clientSocket1, &s, sizeof(s));

    //the game is over
    if(strcmp(s, "End") == 0){
        this->openServer = false;
        return;
    }

    if (n == -1) {
        cout << "Error reading arg1" << endl;
        this->openServer = false;
        return;
    }

    if (n == 0) {
        cout << "Client disconnected" << endl;
        this->openServer = false;
        return;
    }
    // Write the result back to the client.
    n = write(clientSocket2, &s, sizeof(s));
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        return;
    }
    memset(s, '\0', 7);
}

/**
 * close server.
 */
void Server::stop() {
    close(serverSocket);
}