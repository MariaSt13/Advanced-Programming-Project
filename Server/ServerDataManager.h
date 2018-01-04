//
// Created by maria on 04/01/18.
//

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

    vector<int> sockets;

    static ServerDataManager* instance;
    static pthread_mutex_t lock;

public:
    static ServerDataManager* getInstance();

    void addPthread(pthread_t pthread);

    void removePhtread(pthread_t pthread);

    void addSocket(int socket);
    void removeSocket(int socket);
};


#endif //EX4_SERVERDATEMANAGER_H
