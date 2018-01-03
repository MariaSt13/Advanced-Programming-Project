//
// Created by linoy on 27/12/17.
//

#include "CommandsManager.h"
#include "StartCommand.h"
#include "ListGamesCommand.h"
#include "JoinCommand.h"
#include "PlayCommand.h"
#include "CloseCommand.h"

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
 * this function find Command object in the map
 * and calls his execute function.
 * @param command- string of the command.
 * @param args - vector of arguments to execute.
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
}

/**
 * @return instance of command manager.
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
