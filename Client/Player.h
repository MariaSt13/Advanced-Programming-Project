#ifndef EXAM1_PLAYER_H
#define EXAM1_PLAYER_H

#include "Point.h"
#include "Board.h"
#include "UserInterface.h"

/*
 * player class.
 * a player can choose his moves.
 */
class Player{
public:

    // the player choose his next move in his turn.
    virtual Point chooseStep(UserInterface* userInterface) const = 0;

    //constructor.
    Player(Board::disk d): d(d){} ;

    //destructor.
    virtual ~Player() {};

    //get disk type
    Board::disk getDisk()const{
        return this->d;
    }

private:
    //the type of the player : white or black.
    Board::disk d;
};

#endif //EXAM1_PLAYER_H
