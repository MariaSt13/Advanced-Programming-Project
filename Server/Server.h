
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
    Server(int port,CommandsManager *commandManager);

    //open server for connecting clients.
    void start();

    //close server
    void stop();

    struct arguments{
        CommandsManager* manager;
        int socket;
    };
    static arguments args;

private:
    int port;
    int serverSocket; // the socket's file descriptor
    pthread_t serverThreadId;
    CommandsManager *commandManager;
    static void* handleClient(void * socket);
    static void* acceptClients(void *socket);
    //maximum number of characters in the array.
};
#endif //EX4_SERVER_H