#ifndef EX4_SERVERDATEMANAGER_H
#define EX4_SERVERDATEMANAGER_H


#include <sys/types.h>
#include <vector>

using namespace std;

class ServerDataManager {
private:
    //constructor
    ServerDataManager();

    //destructor
     ~ServerDataManager();

    //list of threads
    vector<pthread_t> pthreadList;

    vector<int> socketsList;

    static ServerDataManager* instance;
    static pthread_mutex_t lock;

public:
    //get instance of singleton
    static ServerDataManager* getInstance();

    //add pthread to list
    void addPthread(pthread_t pthread);

    //remove pthread from list
    void removePthread(pthread_t pthread);

    void removeAllPthreads();

    //add socket to list
    void addSocket(int socket);

    //remove socket from list
    void removeSocket(int socket);

    void removeAllSockets();
};


#endif //EX4_SERVERDATEMANAGER_H
