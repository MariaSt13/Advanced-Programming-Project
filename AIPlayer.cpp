//
// Created by linoy on 28/11/17.
//

#include "AIPlayer.h"


Point AIPlayer::chooseStep() const {


}

AIPlayer::AIPlayer(Board::disk d, GameLogic* gameLogic, Board* board): Player(d), gameLogic(gameLogic),board(board){}