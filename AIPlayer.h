//
// Created by linoy on 28/11/17.
//

#ifndef ADVANCED_PROGRAMMING_PROJECT_ALPLAYER_H
#define ADVANCED_PROGRAMMING_PROJECT_ALPLAYER_H

#include "GameLogic.h"
#include "Player.h"

class AIPlayer: public Player  {

public:

    //constructor.
    AIPlayer(Board::disk d, GameLogic *gameLogic, Board *board);

    //destructor.
    virtual ~AIPlayer(){};

    //the player in his turn choose point
    //to put in his disk.
    virtual Point chooseStep()const;

private:

    Board* board;

    GameLogic* gameLogic;

};


#endif //ADVANCED_PROGRAMMING_PROJECT_ALPLAYER_H
