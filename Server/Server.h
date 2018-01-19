
#ifndef EX4_SERVER_H
#define EX4_SERVER_H

#include "CommandsManager.h"
#include "ThreadPool.h"

#define MAX_CONNECTED_CLIENTS 10
#define ARRAY_SIZE 56
#define THREADS_NUM 5

/**
 * Server class.
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
    pthread_t serverThreadId;
    static void* handleClient(void * socket);
    static void* acceptClients(void *socket);
};
#endif //EX4_SERVER_H