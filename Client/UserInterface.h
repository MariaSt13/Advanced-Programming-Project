#ifndef EX4_DISPLAY_H
#define EX4_DISPLAY_H


#include "Board.h"

/**
 * This class are responsible for interaction
 * with the user: input and output.
 */
class UserInterface {
public:
    //prints output
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
    virtual void nameTaken()const =0;
    virtual void noSuchGame() const=0;
    virtual void printListGames(char* list)const=0;
    virtual void wrongMode() = 0;
    virtual void nameNotEntered() const =0;

    //get input
    virtual int chooseMode() =0;
    virtual string getCommand() = 0;
    virtual Point choosePoint()=0;

};
#endif //EX4_DISPLAY_H
