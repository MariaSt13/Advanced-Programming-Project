#include "GameListManager.h"

GameListManager* GameListManager::instance = 0;
pthread_mutex_t  GameListManager::lock;

/**
 * Get the instance of the singleton.
 * @return instance - instance of GameListManager object.
 */
GameListManager *GameListManager::getInstance() {
    if(instance == 0){

        pthread_mutex_lock(&lock);
        if(instance == 0){
            instance = new GameListManager();
        }
        pthread_mutex_unlock(&lock);
    }
    return instance;
}

/**
 * This function adds a game to the list.
 * @param game - the pointer to the game.
 */
void GameListManager::addGame(Game *game) {
    pthread_mutex_lock(&lock);
    this->listGames.push_back(game);
    pthread_mutex_unlock(&lock);
}


/**
 * This function gets a pointer to a game
 * and removes the game from the list.
 * @param game - pointer to a game.
 */
void GameListManager::removeGame(Game *game) {
    //remove from list
    pthread_mutex_lock(&lock);
    for (int i = 0; i < listGames.size(); ++i) {
        if(game->getName() == listGames.at(i)->getName()){
            listGames.erase(listGames.begin() + i);
        }
    }
    pthread_mutex_unlock(&lock);
}

/**
 * This function gets a name and returns
 * a pointer to the game with that name.
 * @param gameName - name of the game.
 * @return - pointer to the game if it is exist.
 * otherwise return NULL.
 */
Game *GameListManager::getGame(string gameName) {
    //go over list
    pthread_mutex_lock(&lock);
    for (vector<Game*>::const_iterator it = listGames.begin(); it < listGames.end(); it++) {

        //check if a game with this name i s exist
        if((*it)->getName() == gameName)
            return *it;
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

/**
 * @return - a string which is a list of all the games that are waiting.
 */
string GameListManager::getListOfWaitingGames() {
    string result;

    //loop go over games list and look for games that can be joined
    pthread_mutex_lock(&lock);
    for (vector<Game*>::const_iterator it = listGames.begin(); it < listGames.end(); it++) {
        //if the game is not running yet
        if((*it)->getStatus() == Game::waiting){
            string name = (*it)->getName();
            result = result + name + "\n";
        }
    }
    pthread_mutex_unlock(&lock);
    return result;
}

/**
 * constructor
 */
GameListManager::GameListManager() {

}

/**
 * destructor
 */
GameListManager::~GameListManager() {
    //free memory
    for (vector<Game*>::const_iterator it = listGames.begin(); it < listGames.end(); it++) {
        delete (*it);
    }
    if(instance!=0){
        delete instance;
    }
}
