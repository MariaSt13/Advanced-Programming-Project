//
// Created by maria on 04/01/18.
//

#include <pthread.h>
#include <unistd.h>
#include "ServerDataManager.h"

ServerDataManager* ServerDataManager::instance = 0;
pthread_mutex_t  ServerDataManager::lock;


/**
 * get instance of singleton.
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
 * this function add pthread to pthreads vector.
 * @param pthread - pthread id number.
 */
void ServerDataManager::addPthread(pthread_t pthread) {
    this->pthreadList.push_back(pthread);
}

/**
 * this function add socket to sockets vector.
 * @param socket - socket number.
 */
void ServerDataManager::addSocket(int socket) {
    this->sockets.push_back(socket);
}

/**
 * this function remove pthread from pthreads vector.
 * @param pthread - pthread id number.
 */
void ServerDataManager::removePthread(pthread_t pthread) {
    pthread_cancel(pthread);
}

/**
 * this function remove socket from sockets vector.
 * @param socket - socket number.
 */
void ServerDataManager::removeSocket(int socket) {
    close(socket);
}

/**
 * constructor.
 */
ServerDataManager::ServerDataManager() {}
