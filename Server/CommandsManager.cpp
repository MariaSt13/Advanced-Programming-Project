#include <sstream>
#include <unistd.h>
#include "CommandsManager.h"
#include "StartCommand.h"
#include "ListGamesCommand.h"
#include "JoinCommand.h"
#include "ServerDataManager.h"

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
 * This function searches for the requested command
 * in the map and calls its execute function.
 * @param command- string of the command name.
 * @param args - vector of arguments to execute function.
 */
void CommandsManager::executeCommand(string command, vector<string> args) {
    int returnVal = -1;
    if(commandsMap.count(command) != 0){
        returnVal = 0;
    }
    istringstream is(args.at(0));
    int clientSocket;
    is >> clientSocket;

    //write to client 0 if command is valid and
    int n = write(clientSocket, &returnVal, sizeof(returnVal));

    //error
    if(n == -1) {
        throw "error writing to socket";
    }

    //if the command is valid
    if(returnVal == 0){
        Command *commandObj = commandsMap[command];
        commandObj->execute(args);
    }
    else{
        //close client socket
        ServerDataManager::getInstance()->removeSocket(clientSocket);
    }
}

/**
 * destructor
 */
CommandsManager::~CommandsManager() {
    map<string, Command *>::iterator it;

    //free memory
    for (it = commandsMap.begin(); it != commandsMap.end(); it++)
        delete it->second;
    if(instance!=0){
        delete instance;
    }
}

/**
 * Get the instance of the singleton.
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
