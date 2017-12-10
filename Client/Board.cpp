
#include <iostream>
#include "Board.h"
using namespace std;

/*
 * Deep copy constructor.
 */
Board::Board(Board* board): rowSize(board->getRowSize()), colSize(board->getColSize()){

    allocateBoard();
    disk** arrToCopy = board->getArray();

    //deep copy
    for (int i = 0; i < this->rowSize; i++) {
        for (int j = 0; j < this->colSize ; j++) {
            array[i][j] = arrToCopy[i][j];
        }
    }
}

/**
 * constructor.
 * @param rowSize - number of rows.
 * @param colSize - number of columns.
 */
Board::Board(const int &rowSize,const int &colSize): rowSize(rowSize+1), colSize(colSize+1) {

    //allocate memory
    allocateBoard();
    //Initializes all the cells in the array with a space character.
    for (int i = 0; i < this->rowSize; i++) {
        for (int j = 0; j < this->colSize ; j++) {
            array[i][j] = empty;
        }
    }

    //Boot the cells of the players.
    int x =(this->rowSize)/2;
    int y = (this->colSize)/2;
    array[x][y] = whiteActor;
    array[x+1][y+1] = whiteActor;
    array[x][y+1] = blackActor;
    array[x+1][y] = blackActor;
}

/**
 * the function get a point and return
 * true if the point is in the board range.
 * else , return false.
 * @param p -the point being checked.
 * @return true or false.
 */
bool Board::pointIsInRange(const Point &p) const{
    return p.getX() > 0 && p.getX() < this->rowSize &&
           p.getY()>0 && p.getY() < this->colSize;
}

/**
 * return number of disks in the board of the player.
 * @param d -the type of disk to count.
 * @return number of disks.
 */
int Board::numOfPlayerDisks(disk d)const{
    int count = 0;
    for (int i = 1; i < this->rowSize ; i++) {
        for (int j = 1; j < this->colSize ; j++) {
            if(array[i][j] == d){
                count++;
            }
        }
    }
    return count;
}

/**
 * if there is no empty cells return true.
 * else return false.
 * @return true or false.
 */
bool Board::ifBoardIsFull() const {
    for (int i = 1; i < this->rowSize ; i++) {
        for (int j = 1; j < this->colSize ; j++) {
            if(array[i][j] == empty){
                return false;
            }
        }
    }
    return true;
}

/**
 * @return - rowSize member.
 */
const int Board::getRowSize() const {
    return this->rowSize;
}

/**
 * @return - colSize member.
 */
const int Board::getColSize() const {
    return this->colSize;
}

/**
 * @return -the board matrix
 */
Board::disk **Board::getArray () const {
    return this->array;
}

/*
 * allocate the memory for the board
 */
void Board::allocateBoard() {
    //create new matrix.
    array = new disk*[this->rowSize];

    for (int j = 0; j < this->rowSize; j++) {
        array[j] = new disk[this->colSize];
    }
}

/**
 * destructor.
 */
Board::~Board(){
    //free memory.
    for (int j = 0; j < this->rowSize; j++) {
        delete[] array[j];
    }

    delete[] array;
}