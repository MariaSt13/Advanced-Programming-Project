//
// Created by linoy on 27/12/17.
//

#ifndef EX4_LISTGAMESCOMMAND_H
#define EX4_LISTGAMESCOMMAND_H


#include "Command.h"

class ListGamesCommand: public Command {
public:
    ListGamesCommand();
    //execute client request.
    virtual void execute(vector<string> args) const;
};


#endif //EX4_LISTGAMESCOMMAND_H
