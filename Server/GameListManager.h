#ifndef EX4_GAMELISTMANAGER_H
#define EX4_GAMELISTMANAGER_H

#include <vector>
#include "Game.h"

/**
 * A singleton class that manages the games list.
 * this class perform actions on the list such as
 * adding or removing game, searching game in the list
 * and return list of waiting games.
 */
class GameListManager {
private:
    //constructor
    GameListManager();

    //destructor
    ~GameListManager();

    //list of games names that player can join.
    vector<Game*> listGames;

    static GameListManager* instance;
    static pthread_mutex_t lock;

public:
    //get instance of singleton
    static GameListManager* getInstance();

    //add game to the list
    void addGame(Game* game);

    //remove game from the list
    void removeGame(Game* game);

    //search game in list
    Game* getGame(string gameName);

    //return list of all the games that are waiting.
    string getListOfWaitingGames();
};


#endif //EX4_GAMELISTMANAGER_H
