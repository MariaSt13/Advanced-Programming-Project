//
// Created by linoy on 28/11/17.
//

#ifndef ADVANCED_PROGRAMMING_PROJECT_ALPLAYER_H
#define ADVANCED_PROGRAMMING_PROJECT_ALPLAYER_H


#include "Player.h"

class AlPlayer: public Player  {

public:
    //constructor.
    AlPlayer(Board::disk d);

    //destructor.
    virtual ~HumanLocalPlayer(){};

    //the player in his turn choose point
    //to put in his disk.
    virtual Point chooseStep()const;

};


#endif //ADVANCED_PROGRAMMING_PROJECT_ALPLAYER_H
