//
// Created by linoy on 03/01/18.
//

#ifndef EX4_GAMELISTMANAGER_H
#define EX4_GAMELISTMANAGER_H


#include <vector>
#include "Game.h"

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
    static GameListManager* getInstance();

    void addGame(Game* game);

    void removeGame(Game* game);

    Game* getGame(string gameName);

    string getListOfWaitingGames();
};


#endif //EX4_GAMELISTMANAGER_H
