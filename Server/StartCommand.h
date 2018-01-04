#ifndef EX4_STARTCOMMAND_H
#define EX4_STARTCOMMAND_H


#include "Command.h"

class StartCommand: public Command {
public:
    StartCommand(){};

    //execute client request.
    virtual void execute(vector<string> args);
};


#endif //EX4_STARTCOMMAND_H
