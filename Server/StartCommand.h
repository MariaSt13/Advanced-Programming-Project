#ifndef EX4_STARTCOMMAND_H
#define EX4_STARTCOMMAND_H


#include "Command.h"

/**
 * This class extends Command.
 * The start command is responsible for create a
 * new game and add it to the games list.
 */
class StartCommand: public Command {
public:
    //constructor
    StartCommand(){};

    //execute client request.
    virtual void execute(vector<string> args);
};


#endif //EX4_STARTCOMMAND_H
