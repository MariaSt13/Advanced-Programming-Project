
#include "Client.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

using namespace std;

/**
 * constructor.
 * @param serverIP - ip number.
 * @param serverPort - port number.
 */
Client::Client(const char *serverIP, int serverPort):
        serverIP(serverIP), serverPort(serverPort),
        clientSocket(0){
}


/**
 * this function connect client to server.
 */
void Client::connectToServer() {
    // Create a socket point
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1)
        throw "Error opening socket";

    // Convert the ip string to a network address
    struct in_addr address;
    if (!inet_aton(serverIP, &address))
        throw "Can't parse IP address";

    // Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *)&address, sizeof address, AF_INET);

    //error
    if (server == NULL) {
        throw "Host is unreachable";
    }

    // Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char *)&address, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char *)&serverAddress.sin_addr.s_addr, (char *)server->h_addr, server->h_length);

    // htons converts values between host and network byte orders
    serverAddress.sin_port = htons(serverPort);

    // Establish a connection with the TCP server
    if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }
    cout << "Connected to server" << endl;
    cout << "Waiting for other player to join..." << endl;
}


/**
 * this function returns the color of the player.
 * 1 - black , 2 - white.
 * @return - int.
 */
int Client::readTypeOfPlayer()const {
    int result;
    int n = read(clientSocket, &result, sizeof(result));

    //error
    if (n == -1)
        throw "Error reading result from socket";

    return result;
};


/**
 * this function returns client socket number.
 * @return - int socket number.
 */
int Client::getClientSocket() const{
    return clientSocket;
}


/**
 * this function writes to the server.
 * @param s - the message to the server.
 * @param clientSocket - socket number.
 */
void Client::writeToServer(char* s, int clientSocket)const{
    //write to server
    char s2[ARRAY_SIZE] = {0};
    strcpy(s2,s);
    int nS = write(clientSocket, &s2, sizeof(s2));

    //error
    if(n == -1) {
        throw "error writing to socket";
    }
    memset(s2, '\0', ARRAY_SIZE);
}