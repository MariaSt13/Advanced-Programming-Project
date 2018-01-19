#ifndef EX4_TASK_H
#define EX4_TASK_H


/**
 * Task interface.
 */
class Task {

public:
    Task(void * (*func)(void *args), void* args):
    func(func), arg(args){}
    void execute(){
        func(arg);
    }

    //destructor
    virtual ~Task(){};

private:
    void * (*func)(void *arg);
    void *arg;
};


#endif //EX4_TASK_H
