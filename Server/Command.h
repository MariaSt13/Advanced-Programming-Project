//
// Created by linoy on 27/12/17.
//

#ifndef EX4_COMMAND_H
#define EX4_COMMAND_H
#include <string>
#include <vector>
using namespace std;


class Command {
private:
    //list of games names that player can join.
    vector<string> games;

public:
    //execute client request.
    virtual void execute(vector<string> args)const = 0;

    //destructor.
    virtual ~Command(){};
};


#endif //EX4_COMMAND_H
