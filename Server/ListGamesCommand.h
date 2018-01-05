#ifndef EX4_LISTGAMESCOMMAND_H
#define EX4_LISTGAMESCOMMAND_H


#include "Command.h"

/**
 * This class implements Command.
 * The List Games command is responsible for returning a list
 * of games that the user can join them.
 */
class ListGamesCommand: public Command {
public:
    //constructor
    ListGamesCommand(){};

    //execute client request.
    virtual void execute(vector<string> args) ;
};


#endif //EX4_LISTGAMESCOMMAND_H
