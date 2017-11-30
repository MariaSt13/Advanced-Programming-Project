
#ifndef ADVANCED_PROGRAMMING_PROJECT_ALPLAYER_H
#define ADVANCED_PROGRAMMING_PROJECT_ALPLAYER_H

#include "GameLogic.h"
#include "Player.h"

/*
 * this class extends player class and represent AI player.
 */
class AIPlayer: public Player  {

public:

    /*
     * constructor.
     * d: the type of disk the player is.
     * gameLogic - pointer to the logic of this game.
     * board - a pointer to the game board.
     */
    AIPlayer(Board::disk d, GameLogic *gameLogic, Board *board);

    //destructor.
    virtual ~AIPlayer(){};

    /*
     * The player in his turn choose where to put is disk.
     */
    virtual Point chooseStep()const;

private:

    Board* board;
    GameLogic* gameLogic;

};


#endif //ADVANCED_PROGRAMMING_PROJECT_ALPLAYER_H
