#ifndef EX4_GAMEMANAGER_H
#define EX4_GAMEMANAGER_H
#define MAX_CONNECTED_CLIENTS 2
#define ARRAY_SIZE 7


#include <vector>
#include "Game.h"
using namespace std;

/**
 * this class manages one game and connected between the players.
 */
class GameManager {
private:
    Game* game;

public:
    //constructor
    GameManager(Game* game);

    //start game communication
    void run();

    //handle clients request
    void handleClient(int clientSocket1,int clientSocket2);
};


#endif //EX4_GAMEMANAGER_H
