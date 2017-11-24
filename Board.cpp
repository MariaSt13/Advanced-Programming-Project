//name: linoy cohen
//ID: 206333502

#include <iostream>
#include "Board.h"
using namespace std;

//constructor.
Board::Board(const int &rowSize,const int &colSize): rowSize(rowSize+1), colSize(colSize+1) {

    //create new matrix.
    array = new disk*[this->rowSize];

    for (int j = 0; j < this->rowSize; j++) {
        array[j] = new disk[this->colSize];
    }

    //Initializes all the cells in the array with a space character.
    for (int i = 0; i < this->rowSize; i++) {
        for (int j = 0; j < this->colSize ; j++) {
            array[i][j] = empty;
        }

    }

    //Boot the cells of the players.
    int x =(this->rowSize)/2;
    int y = (this->colSize)/2;
    array[x][y] = whitekActor;
    array[x+1][y+1] = whitekActor;
    array[x][y+1] = blackActor;
    array[x+1][y] = blackActor;
}

// the function get a point and return
// true if the point is in the board range.
// else , return false.
// return : bool.
bool Board::pointIsInRange(const Point &p) const{
    return p.getX() > 0 && p.getX() < this->rowSize &&
           p.getY()>0 && p.getY() < this->colSize;
}

// if tere is no empty cells return true.
// else return false.
//return : bool.
bool Board::ifBoardIsFull() const {
    for (int i = 1; i < this->rowSize ; i++) {
        for (int j = 1; j < this->colSize ; j++) {
            if(array[i][j] == ' '){
                return false;
            }
        }
    }
    return true;
}

// return rowSize member.
const int Board::getRowSize() const {
    return this->rowSize;
}

// return colSize member.
const int Board::getColSize() const {
    return this->colSize;
}

// reutrn array member.
Board:: disk **Board::getArray () const {
    return this->array;
}

//destructor.
Board::~Board(){
    //free memory.
    for (int j = 0; j < this->rowSize; j++) {
        delete[] array[j];
    }

    delete[] array;
}