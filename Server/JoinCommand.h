//
// Created by linoy on 27/12/17.
//

#ifndef EX4_JOINCOMMAND_H
#define EX4_JOINCOMMAND_H


#include "Command.h"

class JoinCommand: public Command {
public:
    JoinCommand();

    //execute client request.
    virtual void execute(vector<string> args) const;
};


#endif //EX4_JOINCOMMAND_H
