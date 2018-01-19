#include <unistd.h>
#include "ThreadPool.h"

/**
 * constructor.
 * @param threadsNum -number of threads.
 */
ThreadPool::ThreadPool(int threadsNum):stopped(false) {
    threads = new pthread_t[threadsNum];
    for (int i = 0; i < threadsNum; i++) {
        pthread_create(threads + i, NULL, execute, this);
    }
    pthread_mutex_init(&lock, NULL); {
}

/**
 * This function add a new task to the queue.
 * @param task - a new task.
 */
void ThreadPool::addTask(Task *task) {
    tasksQueue.push(task);
}

/**
 * This function set "stopped" to true.
 */
void ThreadPool::terminate() {
    pthread_mutex_destroy(&lock);
    stopped = true;
}

/**
 * destructor.
 */
ThreadPool::~ThreadPool() {
    delete[] threads;
}

/**
 * This function go over all tasks and call "execute" function.
 */
void ThreadPool::executeTasks() {
    while (!stopped) {
        pthread_mutex_lock(&lock);
        if (!tasksQueue.empty()) {
            Task* task = tasksQueue.front();
            tasksQueue.pop();
            pthread_mutex_unlock(&lock);
            task ->execute();
        }
        else {
            pthread_mutex_unlock(&lock);
            sleep(1);
        }
    }
}


/**
 *  This function executes task.
 * @param arg - arguments to function.
 * @returns
 */
void *ThreadPool::execute(void *arg) {
    ThreadPool *pool = (ThreadPool *) arg;
    pool -> executeTasks();
}
    void ThreadPool::addTask(Task *task) {

    }
    void ThreadPool::addTask(Task *task) {

    }
