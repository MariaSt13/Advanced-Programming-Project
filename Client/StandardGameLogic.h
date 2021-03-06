
#ifndef EXAM1_STANDARDGAMELOGIC_H
#define EXAM1_STANDARDGAMELOGIC_H

#include "GameLogic.h"
#include <vector>
#include <map>

/**
 * This class extends GameLogic and encapsulates
 * the standard logic of the reversi game.
 */
class StandardGameLogic: public GameLogic {

public:

    /**
    * The function places a disc where the player has selected
    * and flips the opponents cells by the map.
    * bool updateMap - first update the map. (when return valid moves was not called before that.)
    */
    virtual void flipCells (const Player* player,const Point &newPoint, const Board* b, bool updateMap);

    //The function returns a vector with all possible steps for the player.
    virtual vector<Point> returnValidMoves (const Player* p,const Board* b);

    //destructor.
    virtual ~StandardGameLogic();

private:
    /**
     * A map where the keys are the legal points that
     *the player can choose. for each point the value
     *in the map is a vector of enemy points that need
     *to be reversed.
     */
    map <Point,vector <Point> > pointsMap;

    /**
     * The function get a point and check if it is a valid point
     * (possible move) for the player.
     */
    void checkPoint(const Player* player,const Point &p,const Board* b, vector<Point> &vector);

    /**
     * The function get a points and check if selecting this point
     * will reverse the opponent disks.
     */
    Point ifReverseOpponentDisk(const Player* player,const Point &p,const Board* b,const int &i, const int &j);

};


#endif //EXAM1_STANDARDGAMELOGIC_H
