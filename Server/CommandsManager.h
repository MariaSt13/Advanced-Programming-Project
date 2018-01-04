#ifndef EX4_COMMANDSMANAGER_H
#define EX4_COMMANDSMANAGER_H

#include <string>
#include <vector>
#include <map>
#include "Command.h"
using namespace std;


/**
 * A singleton class that connects the server with
 * the requested command.
 */
class CommandsManager {
private:
    //a singleton
    static CommandsManager* instance;

    //constructor
    CommandsManager();

    //destructor
    ~CommandsManager();

    static pthread_mutex_t lock;
    map <string, Command*> commandsMap;

public:
    //get instance of singleton
    static CommandsManager* getInstance();
    
    //searches for the requested command in the map calls its execute function.
    void executeCommand(string command, vector<string>args);
};


#endif //EX4_COMMANDSMANAGER_H
