//
// Created by maria on 25/12/17.
//

#ifndef EX4_DISPLAY_H
#define EX4_DISPLAY_H


#include "Board.h"

class Display {
public:
    virtual void waiting() const = 0;
    virtual void currentBoard(const Board* b) const = 0;
    virtual void printBoard(const Board* b) const= 0;
    virtual void noMoves(Board::disk d) const = 0;
    virtual void played(Board::disk player, Point step) const = 0;
    virtual void gameOver() const = 0;
    virtual void winner(Board::disk d) const= 0;
    virtual void draw() const = 0;
    virtual void invalidInput() const = 0;
    virtual void askForMove() const = 0;
    virtual void yourMove(Board::disk d) const = 0;
    virtual void noMoves()const = 0;
    virtual void possibleMoves(const vector<Point> &v) const = 0;
    virtual void mainMenu() const = 0;
    virtual void invalidTryAgain() const = 0;
    virtual void commandMenu()const = 0;

};
#endif //EX4_DISPLAY_H
