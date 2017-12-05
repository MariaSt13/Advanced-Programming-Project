
#ifndef EXAM1_GAMELOGIC_H
#define EXAM1_GAMELOGIC_H
#include "Board.h"
#include "Point.h"
#include "Player.h"
#include <vector>
#include <map>

using namespace std;

/*
 * this class encapsulates the logic of the reversi game.
 */
class GameLogic{

public:
    /*
     * The function places a disc where the player has selected
     * And calls a function that turns the opponent's disks.
     */
    virtual void flipCells (const Player* player,const Point &newPoint,const Board* b) = 0;

    //The function returns a vector with all possible steps for the player.
    virtual vector<Point> returnValidMoves (const Player* p, const Board* b) = 0;

    //destructor.
    virtual ~GameLogic(){};
};

#endif //EXAM1_GAMELOGIC_H
