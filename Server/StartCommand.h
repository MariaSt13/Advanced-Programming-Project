//
// Created by linoy on 27/12/17.
//

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
