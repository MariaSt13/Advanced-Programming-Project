//
// Created by linoy on 27/12/17.
//

#ifndef EX4_PLAYCOMMAND_H
#define EX4_PLAYCOMMAND_H


#include "Command.h"

class PlayCommand: public Command {
public:
    PlayCommand();

    //execute client request.
    virtual void execute(vector<string> args) const;
};


#endif //EX4_PLAYCOMMAND_H
