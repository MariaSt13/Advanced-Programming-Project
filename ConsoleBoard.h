//name: linoy cohen
//ID: 206333502

#ifndef EXAM1_EXAMPLE_H
#define EXAM1_EXAMPLE_H
#include "Board.h"

// This class extends board class .
// display of the game board using the console.
class ConsoleBoard: public Board {

public:

    //consturctor.
    ConsoleBoard(const int &rowSize, const int &colSize);

    //deep copy constructor
    ConsoleBoard(Board* board);

    //The function prints the board game.
    void printBoard() const;

    //destructor.
    virtual ~ConsoleBoard();

private:
    //The function prints a numbered row above the game board.
    void printNumberedRow() const;

    //The function prints a separator line.
    // separator line printed between any two lines in the table.
    void printSeparator() const;
};

#endif //EXAM1_EXAMPLE_H
