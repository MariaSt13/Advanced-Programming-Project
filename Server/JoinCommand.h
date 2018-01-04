#ifndef EX4_JOINCOMMAND_H
#define EX4_JOINCOMMAND_H


#include "Command.h"
/**
 * this class extends Command.
 * the join command is responsible for adding the
 * second player to the game.
 */
class JoinCommand: public Command {
public:
    //constructor
    JoinCommand();

    //execute client request.
    virtual void execute(vector<string> args);
};


#endif //EX4_JOINCOMMAND_H
