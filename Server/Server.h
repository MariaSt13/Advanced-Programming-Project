
#ifndef EX4_SERVER_H
#define EX4_SERVER_H
#define MAX_CONNECTED_CLIENTS 10
#define ARRAY_SIZE 7

#include <pthread.h>
#include <vector>
using namespace std;
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
    vector <pthread_t> threads;
    void handleClient(int clientSocket1,int clientSocket2);
    static void* serverFlow(void* clientSocket);
};
#endif //EX4_SERVER_H
