
#include "ConsoleBoard.h"
#include <iostream>
using namespace std;

/*
 * constructor
 */
ConsoleBoard::ConsoleBoard(const int &rowSize, const int &colSize) : Board(rowSize, colSize) {}
/*
 * copy constructor
 */
ConsoleBoard::ConsoleBoard(Board* board): Board(board){};

/*
 * The function prints the game board
 * return - void.
 */
void ConsoleBoard::printBoard() const {

    printNumberedRow();

    //A loop that prints the contents of each cell in the array.
    for (int i = 1; i < this->rowSize; i++) {
        cout << i;
        for (int j = 1; j < this->colSize; j++) {
            cout << "| ";
            cout << char(array[i][j]);
            cout << " ";
        }
        printSeparator();
    }
}

/*
 * The function prints a numbered row above the game board.
 * return:void.
 */
void ConsoleBoard::printNumberedRow() const {
    for (int k = 1; k < this->colSize ; k++) {
        cout << " | ";
        cout << k;
    }
    cout << " ";
    printSeparator();
}

/*
 * The function prints a separator line.
 * separator line printed between any two lines in the table.
 * return:void.
 */
void ConsoleBoard::printSeparator() const {
    cout << "|" << endl;
    for (int i = 1; i < this->colSize; ++i) {
        cout << "----";
    }
    cout << "--" << endl;
}

// destructor.
ConsoleBoard::~ConsoleBoard(){}