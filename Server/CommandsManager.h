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
    
    //get instance
    static CommandsManager* getInstance();
    
    //find Command object in the map and calls his execute function.
    void executeCommand(string command, vector<string>args);


private:
    //a singleton
    static CommandsManager* instance;

    static pthread_mutex_t lock;

    //constructor
    CommandsManager();
    
    //destructor
    ~CommandsManager();

    map <string, Command*> commandsMap;
};


#endif //EX4_COMMANDSMANAGER_H
