#ifndef EX4_COMMAND_H
#define EX4_COMMAND_H
#include <string>
#include <vector>
#include "Game.h"

using namespace std;

/**
 * an abstract command class.
 */
class Command {
public:
    //execute command requested by the user.
    virtual void execute(vector<string> args) = 0;

    //destructor.
    virtual ~Command(){};
};
#endif //EX4_COMMAND_H
