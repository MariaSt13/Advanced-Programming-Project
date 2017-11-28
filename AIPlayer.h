//
// Created by linoy on 28/11/17.
//

#ifndef ADVANCED_PROGRAMMING_PROJECT_ALPLAYER_H
#define ADVANCED_PROGRAMMING_PROJECT_ALPLAYER_H


#include "Player.h"
#include "GameLogic.h"

class AlPlayer: public Player  {

public:
    //constructor.
    AlPlayer(Board::disk d, GameLogic gameLogic, Board board);

    //destructor.
    virtual ~AlPlayer(){};

    //the player in his turn choose point
    //to put in his disk.
    virtual Point chooseStep()const;

private:

    Board board;

    GameLogic gameLogic

};


#endif //ADVANCED_PROGRAMMING_PROJECT_ALPLAYER_H
