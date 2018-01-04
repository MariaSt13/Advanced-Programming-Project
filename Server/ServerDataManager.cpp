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
    this->socketsList.push_back(socket);
}

/**
 * this function remove pthread from pthreads vector and closes it.
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
 * this function remove socket from sockets vector and closes it.
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
 * constructor.
 */
ServerDataManager::ServerDataManager() {}
