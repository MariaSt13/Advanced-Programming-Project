//
// Created by linoy on 27/12/17.
//
#ifndef EX4_COMMANDSMANAGER_H
#define EX4_COMMANDSMANAGER_H

#include <string>
#include <vector>
#include <map>
#include "Command.h"


using namespace std;

class CommandsManager {

public:
    //constructor
    CommandsManager();

    //find Command object in the map and calls his execute function.
    void executeCommand(string command, vector<string>args);

    //destructor
    ~CommandsManager();

private:
    map <string, Command*> commandsMap;
};


#endif //EX4_COMMANDSMANAGER_H
