#include "GameListManager.h"

GameListManager* GameListManager::instance = 0;
pthread_mutex_t  GameListManager::lock;

/**
 * get instance of a singleton.
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
 * this function add game to list.
 * @param game - pointer to game.
 */
void GameListManager::addGame(Game *game) {
    this->listGames.push_back(game);
}


/**
 * this function get pointer to game
 * and remove this game from the list.
 * @param game - pointer to game.
 */
void GameListManager::removeGame(Game *game) {
    //remove from list
    for (int i = 0; i < listGames.size(); ++i) {
        if(game->getName() == listGames.at(i)->getName()){
            listGames.erase(listGames.begin() + i);
        }
    }
}

/**
 * this function get a name and return
 * pointer to the game with that name.
 * @param gameName - name of the game.
 * @return - pointer to the game if it is exist.
 * otherwise return NULL.
 */
Game *GameListManager::getGame(string gameName) {

    //go over list
    for (vector<Game*>::const_iterator it = listGames.begin(); it < listGames.end(); it++) {

        //check if a game with this name i s exist
        if((*it)->getName() == gameName)
            return *it;
    }
    return NULL;
}

/**
 * return string which is a list of all the games that are waiting.
 * @return
 */
string GameListManager::getListOfWaitingGames() {
    string result;

    //loop go over games list and look for games that can be joined
    for (vector<Game*>::const_iterator it = listGames.begin(); it < listGames.end(); it++) {
        //if the game is not running yet
        if((*it)->getStatus() == Game::waiting){
            string name = (*it)->getName();
            result = result + name + "\n";
        }
    }

    return result;
}

/**
 * constructor
 */
GameListManager::GameListManager() {

}
