#ifndef EX4_SERVERDATEMANAGER_H
#define EX4_SERVERDATEMANAGER_H


#include <sys/types.h>
#include <vector>
#include "ThreadPool.h"

using namespace std;

/**
 * A singleton class that manages data for
 * the server: a the vector of pthreads and
 * a vector of clients sockets.
 */
class ServerDataManager {
private:
    //constructor
    ServerDataManager(){};

    //destructor
     ~ServerDataManager();

    vector<int> socketsList;

    static ServerDataManager* instance;
    static pthread_mutex_t lock;
    ThreadPool *pool;

public:
    //get instance of singleton
    static ServerDataManager* getInstance();

    //add threadPool object
    void addThreadPool(ThreadPool *pool);

    // close the thread pool
    void terminateThreadPool();

    //add socket to list
    void addSocket(int socket);

    //remove socket from list
    void removeSocket(int socket);

    void removeAllSockets();
};


#endif //EX4_SERVERDATEMANAGER_H
