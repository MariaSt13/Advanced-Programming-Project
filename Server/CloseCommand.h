//
// Created by linoy on 27/12/17.
//

#ifndef EX4_CLOSECOMMAND_H
#define EX4_CLOSECOMMAND_H


#include "Command.h"

class CloseCommand: public Command {
public:
    //execute client request.
    virtual void execute(vector<string> args) const;
};


#endif //EX4_CLOSECOMMAND_H
