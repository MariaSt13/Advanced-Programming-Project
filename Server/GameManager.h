//
// Created by linoy on 29/12/17.
//

#ifndef EX4_GAMEMANAGER_H
#define EX4_GAMEMANAGER_H
#define MAX_CONNECTED_CLIENTS 2
#define ARRAY_SIZE 7


#include "Game.h"

class GameManager {
private:
    Game game;

public:
    //constructor
    GameManager(Game game);

    void run();

    void handleClient(int clientSocket1,int clientSocket2);

};


#endif //EX4_GAMEMANAGER_H
