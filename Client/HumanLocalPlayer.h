
#ifndef EXAM1_HUMANLOCALPLAYER_H
#define EXAM1_HUMANLOCALPLAYER_H

#include "Player.h"

/**
 * This class extends player class and represent
 * a human player who plays on this computer.
 */
class HumanLocalPlayer: public Player {
public:
    //constructor.
    HumanLocalPlayer(Board::disk d);

    //destructor.
    virtual ~HumanLocalPlayer(){};

    /**
     * the player in his turn choose point
     * to put in his disk.
     */
    virtual Point chooseStep(UserInterface* userInterface)const;
};


#endif //EXAM1_HUMANLOCALPLAYER_H
