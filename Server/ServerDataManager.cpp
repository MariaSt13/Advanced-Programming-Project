#include <pthread.h>
#include <unistd.h>
#include "ServerDataManager.h"

ServerDataManager* ServerDataManager::instance = 0;
pthread_mutex_t  ServerDataManager::lock;


/**
 * Get the instance of the singleton.
 * @return instance - instance of ServerDataManager class.
 */
ServerDataManager *ServerDataManager::getInstance() {
    if(instance == 0){

        pthread_mutex_lock(&lock);
        if(instance == 0){
            instance = new ServerDataManager();
        }
        pthread_mutex_unlock(&lock);
    }
    return instance;
}

/**
 * This function adds pthread to pthreads vector.
 * @param pthread - pthread id number.
 */
void ServerDataManager::addPthread(pthread_t pthread) {
    this->pthreadList.push_back(pthread);
}

/**
 * This function adds socket to sockets list.
 * @param socket - socket number.
 */
void ServerDataManager::addSocket(int socket) {
    this->socketsList.push_back(socket);
}

/**
 * This function removes pthread from pthreads list and closes it.
 * @param pthread - pthread id number.
 */
void ServerDataManager::removePthread(pthread_t pthread) {
    //remove from list
    for (int i = 0; i < pthreadList.size(); ++i) {
        if(pthread == pthreadList.at(i)){
            pthreadList.erase(pthreadList.begin() + i);
        }
    }
    pthread_cancel(pthread);
}

/**
 * This function removes socket from sockets vector and closes it.
 * @param socket - socket number.
 */
void ServerDataManager::removeSocket(int socket) {
    //remove from list
    for (int i = 0; i < socketsList.size(); ++i) {
        if(socket == socketsList.at(i)){
            socketsList.erase(socketsList.begin() + i);
        }
    }
    close(socket);
}

/**
 * This function closes all the pthreads in the list and clears the list.
 */
void ServerDataManager::removeAllPthreads() {
    for (vector<pthread_t>::const_iterator it = pthreadList.begin(); it < pthreadList.end(); it++) {
        pthread_cancel(*it);
    }
    pthreadList.clear();
}
/**
 * This function closes all the sockets in the list and clears the list.
 */
void ServerDataManager::removeAllSockets() {
    for (vector<int>::const_iterator it = socketsList.begin(); it < socketsList.end(); it++) {
        close(*it);
    }

    socketsList.clear();
}

/**
 * constructor.
 */
ServerDataManager::ServerDataManager() {}

/**
 * destructor.
 */
ServerDataManager::~ServerDataManager() {
    delete(instance);
}