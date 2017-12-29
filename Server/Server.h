
#ifndef EX4_SERVER_H
#define EX4_SERVER_H

#include "CommandsManager.h"

#define MAX_CONNECTED_CLIENTS 10
#define ARRAY_SIZE 56

/**
 * server class.
 */
class Server {

public:

    //constructor.
    Server(int port);

    //open server for connecting clients.
    void start();

    //close server
    void stop();

private:
    int port;
    int serverSocket; // the socket's file descriptor
    bool openServer;
    void handleClient(int clientSocket,CommandsManager commandManager);
    //maximum number of characters in the array.
};
#endif //EX4_SERVER_H