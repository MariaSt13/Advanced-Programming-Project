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
 * @return instance.
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

void ServerDataManager::addPthread(pthread_t pthread) {
    this->pthreadList.push_back(pthread);
}

void ServerDataManager::addSocket(int socket) {
    this->sockets.push_back(socket);
}

void ServerDataManager::removePhtread(pthread_t pthread) {
    pthread_cancel(pthread);
}

void ServerDataManager::removeSocket(int socket) {
    close(socket);
}