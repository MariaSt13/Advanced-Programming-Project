//
// Created by maria on 25/12/17.
//

#include <iostream>
#include "ConsoleDisplay.h"

void ConsoleDisplay::waiting() const {
    cout << "Waiting for other player's move..." << endl;
}

void ConsoleDisplay::currentBoard(const Board *b) const {
    cout << endl << "current board:" << endl << endl;
    printBoard(b);
}

void ConsoleDisplay::printBoard(const Board *b) const {
    Board::disk** array = b->getArray();
    printNumberedRow(b->getColSize());

    //A loop that prints the contents of each cell in the array.
    for (int i = 1; i < b->getRowSize(); i++) {
        cout << i;
        for (int j = 1; j < b->getColSize(); j++) {
            cout << "| ";
            cout << char(array[i][j]);
            cout << " ";
        }
        printSeparator(b->getColSize());
    }
}

void ConsoleDisplay::printNumberedRow(int size) const {
    for (int k = 1; k < size ; k++) {
        cout << " | ";
        cout << k;
    }
    cout << " ";
    printSeparator(size);
}

void ConsoleDisplay::printSeparator(int size) const {
    cout << "|" << endl;
    for (int i = 1; i < size; ++i) {
        cout << "----";
    }
    cout << "--" << endl;
}

void ConsoleDisplay::noMoves(Board::disk d) const {
    char c = d;
    cout << c << " had no moves" << endl << endl;
}

void ConsoleDisplay::played(Board::disk player, Point step) const {
    char c = player;
    cout << c << " played" << step << endl << endl;
}

void ConsoleDisplay::gameOver() const {
    cout <<"Game over. ";
}

void ConsoleDisplay::winner(Board::disk d) const {
    if (d == Board::blackActor) {
        cout <<"The winner is: the black player.";
    }
    if (d == Board::whiteActor) {
        cout <<"The winner is: the white player.";
    }
}

void ConsoleDisplay::draw() const {
    cout <<"It's a draw.";
}

void ConsoleDisplay::invalidInput() const {
    cout << "Invalid input" << endl;
}

void ConsoleDisplay::askForMove() const {
    cout << "please enter your move row col (for example: 1 2):";
}

void ConsoleDisplay::yourMove(Board::disk d) const {
    char c = d;
    cout << c;
    cout <<  ": It's your move." << endl;
}

void ConsoleDisplay::noMoves() const {
    cout <<  "no possible moves. play passes back to the other player." << endl;
}

void ConsoleDisplay::possibleMoves(const vector<Point> &v) const {
    cout <<  "your possible moves: ";

    //print possible points
    for (int i = 0; i < v.size() ; i++) {
        cout << v.at(i);
        if(i != v.size() -1){
            cout << ",";
        }
    }
}