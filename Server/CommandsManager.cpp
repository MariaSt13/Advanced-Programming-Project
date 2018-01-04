#include "CommandsManager.h"
#include "StartCommand.h"
#include "ListGamesCommand.h"
#include "JoinCommand.h"

CommandsManager* CommandsManager::instance = 0;
pthread_mutex_t  CommandsManager::lock;

/**
 * constructor
 */
CommandsManager::CommandsManager() {
    //add commands to the map
    this->commandsMap["start"] = new StartCommand();
    this->commandsMap["list_games"] = new ListGamesCommand();
    this->commandsMap["join"] = new JoinCommand();
}

/**
 * this function searches for the requested command
 * in the map calls its execute function.
 * @param command- string of the command name.
 * @param args - vector of arguments to execute function.
 */
void CommandsManager::executeCommand(string command, vector<string> args) {
    Command *commandObj = commandsMap[command];
    commandObj->execute(args);
}

/**
 * destructor
 */
CommandsManager::~CommandsManager() {
    map<string, Command *>::iterator it;

    //free memory
    for (it = commandsMap.begin(); it != commandsMap.end(); it++)
        delete it->second;
    delete instance;
}

/**
 * get instance of a singleton.
 * @return instance of CommandsManager object.
 */
CommandsManager *CommandsManager::getInstance() {
    if(instance == 0){
        pthread_mutex_lock(&lock);
        if(instance == 0){
            instance = new CommandsManager();
        }
        pthread_mutex_unlock(&lock);
    }
    return instance;
}
