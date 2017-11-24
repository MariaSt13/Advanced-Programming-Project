//name: linoy cohen
//ID: 206333502

#ifndef EXAM1_STANDARDGAMELOGIC_H
#define EXAM1_STANDARDGAMELOGIC_H

#include "GameLogic.h"
#include <vector>
#include <map>


class StandardGameLogic: public GameLogic {

public:

    //The function places a disc where the player has selected
    //And calls a function that turns the opponent's disks.
    virtual void flipCells (const Player* player,const Point &newPoint, const Board* b);

    //The function returns a vector with all possible steps for the player.
    virtual vector<Point> returnValidMoves (const Player* p,const Board* b);

    //destructor.
    virtual ~StandardGameLogic();

private:
    //map where the keys are the legal points that
    //the player can choose. for each point the value
    //in the map is a vector of enemy points that need
    //to be reversed.
    map <Point,vector <Point> > pointsMap;

    // the function get a point and check if it is a valid point
    // (possible move) for the player.
    vector<Point> checkPoint(const Player* player,const Point &p,const Board* b);

    // the function get a points and check if selecting this point
    // will reverse the opponent disks.
    bool ifReverseOpponentDisk(const Player* player,const Point &p,const Board* b,const int &i, const int &j);

};


#endif //EXAM1_STANDARDGAMELOGIC_H
