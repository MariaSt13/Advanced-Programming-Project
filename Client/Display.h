//
// Created by maria on 25/12/17.
//

#ifndef EX4_DISPLAY_H
#define EX4_DISPLAY_H


#include "Board.h"

class Display {
    virtual void waiting() const;
    virtual void currentBoard(Board* b) const;
    virtual void printBoard(Board* b) const;
    virtual void noMoves(Board::disk d) const;
    virtual void played(Board::disk player, Point step) const;
    virtual void gameOver() const;
    virtual void winner(Board::disk d) const;
    virtual void invalidInput() const;
    virtual void askForMove() const;
    virtual void yourMove(Board::disk d) const;
    virtual void noMoves()const;
    virtual void possibleMoves(const vector<Point> &v) const;

};
#endif //EX4_DISPLAY_H
