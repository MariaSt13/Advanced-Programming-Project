//
// Created by maria on 25/12/17.
//

#ifndef EX4_CONSOLEDISPLAY_H
#define EX4_CONSOLEDISPLAY_H


#include "Display.h"

class ConsoleDisplay: public Display {
public:
    virtual void waiting() const;
    virtual void currentBoard(const Board* b) const;
    virtual void printBoard(const Board* b) const;
    virtual void noMoves(Board::disk d) const;
    virtual void played(Board::disk player, Point step) const;
    virtual void gameOver() const;
    virtual void winner(Board::disk d) const;
    virtual void draw() const;
    virtual void invalidInput() const;
    virtual void askForMove() const;
    virtual void yourMove(Board::disk d) const;
    virtual void noMoves()const;
    virtual void possibleMoves(const vector<Point> &v) const;

private:
    //The function prints a numbered row above the game board.
    void printNumberedRow(int size) const;

    /*
     * The function prints a separator line.
     * separator line printed between any two lines in the table.
     */
    void printSeparator(int size) const;
};


#endif //EX4_CONSOLEDISPLAY_H
