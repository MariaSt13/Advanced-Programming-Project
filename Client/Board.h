
#ifndef EXAM1_BOARD_H
#define EXAM1_BOARD_H
#include "Point.h"

//forward deceleration.
class UserInterface;

/**
* A board class that represents the Reversi game board.
* Each slot in the table can contain one of the following values:
* 'X' A slot ofThe Black Actor.
* 'O' A slot ofThe White Actor.
*  Or an empty slot.
 */
class Board {
public:
    //disk mark.
    enum disk{blackActor = 'X',whiteActor = 'O', empty = ' '};

    //constructor.
    Board(const int &rowSize, const int &colSize, UserInterface* userInterface);

    //deep copy constructor
    Board(Board* board);

    //destructor
    ~Board();

    /**
    * The function get a point and return
    * true if the point is in the board range.
    * else , return false.
    */
    bool pointIsInRange(const Point &p) const;

    /**
    * checks if the board id full.
    * if there is no empty cells return true.
    * else return false.
    */
    bool ifBoardIsFull() const;

    //return number of disks in the board of the player.
    int numOfPlayerDisks(disk d)const ;

    //get functions.
    const int getColSize() const ;
    const int getRowSize() const;
    disk** getArray ()const;
    UserInterface *getUserInterface() const;

    //display board game.
    void displayBoard() const;

private:
    //A two-dimensional array that represents the game board.
    disk** array;

    //size of the array.
    const int colSize;
    const int rowSize;

    UserInterface* userInterface;
    // allocates memory for the board
    void allocateBoard();
};
#endif //EXAM1_BOARD_H