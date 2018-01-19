
#include "Task.h"
#include <pthread.h>
#include <queue>

#ifndef EX4_THREADPOOL_H
#define EX4_THREADPOOL_H

using namespace std;

/**
 * ThreadPool class.
 */
class ThreadPool {

public:
    ThreadPool(int threadsNum);
    void addTask(Task *task);
    void terminate();
    virtual~ThreadPool();

private:
    queue<Task *> tasksQueue;
    pthread_t * threads;
    pthread_mutex_t lock;
    bool stopped;
    void executeTasks();
    static void *execute(void *arg);
};


#endif //EX4_THREADPOOL_H
