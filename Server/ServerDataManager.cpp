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
 * This function gets a ThreadPool object and saves it.
 * @param pool - ThreadPool.
 */
void ServerDataManager::addThreadPool(ThreadPool *pool) {
    this->pool = pool;
}

/**
 * This function closes the threadPool.
 */
void ServerDataManager::terminateThreadPool() {
    this->pool->terminate();
}
/**
 * This function adds socket to sockets list.
 * @param socket - socket number.
 */
void ServerDataManager::addSocket(int socket) {
    this->socketsList.push_back(socket);
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
 * This function closes all the sockets in the list and clears the list.
 */
void ServerDataManager::removeAllSockets() {
    for (vector<int>::const_iterator it = socketsList.begin(); it < socketsList.end(); it++) {
        close(*it);
    }

    socketsList.clear();
}

/**
 * destructor.
 */
ServerDataManager::~ServerDataManager() {
    if(instance!=0){
        delete(instance);
    }
}