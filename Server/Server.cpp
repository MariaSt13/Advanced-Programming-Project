
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


    // Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);

    while(true){
        openServer = true;

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
                throw "Error on accept";
            }
        }

        //send to client his color.1- black , 2-white.
        for (int i = 0; i < MAX_CONNECTED_CLIENTS; i++) {
            int result =  i+1;
            int n = write(clientSocket[i], &result, sizeof(result));
            if (n == -1) {
                cout << "Error writing to socket" << endl;
                return;
            }
        }

        //while the game is running.
        while (openServer){
            for (int i = 0; i < MAX_CONNECTED_CLIENTS; i++) {
                if(openServer)
                    handleClient(clientSocket[i] ,clientSocket[(i+1) % 2]);
            }
        }

        // Close communication with all clients
        for (int i = 0; i < MAX_CONNECTED_CLIENTS; i++) {
            close(clientSocket[i]);
        }
    }

}

/**
 * Handle requests from a specific client.
 * @param clientSocket1 - the server reads from this client.
 * @param clientSocket2 - the server writes to this client.
 */
void Server::handleClient(int clientSocket1,int clientSocket2) {
    char s[7] = {0};

    //read a new move
    int n = read(clientSocket1, &s, sizeof(s));

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

    //clientSocket1 disconnected
    if (n == 0) {
        cout << "Client disconnected" << endl;
        this->openServer = false;
        return;
    }

    // Write the result back to clientSocket2.
    n = write(clientSocket2, &s, sizeof(s));
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        this->openServer = false;
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