//
// Created by maria on 25/12/17.
//

#include <iostream>
#include <limits>
#include "ConsoleInterface.h"

void ConsoleInterface::waiting() const {
    cout << "Waiting for other player's move..." << endl;
}

void ConsoleInterface::currentBoard(const Board *b) const {
    cout << endl << "current board:" << endl << endl;
    printBoard(b);
}

void ConsoleInterface::printBoard(const Board *b) const {
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

void ConsoleInterface::printNumberedRow(int size) const {
    for (int k = 1; k < size ; k++) {
        cout << " | ";
        cout << k;
    }
    cout << " ";
    printSeparator(size);
}

void ConsoleInterface::printSeparator(int size) const {
    cout << "|" << endl;
    for (int i = 1; i < size; ++i) {
        cout << "----";
    }
    cout << "--" << endl;
}

void ConsoleInterface::noMoves(Board::disk d) const {
    char c = d;
    cout << c << " had no moves" << endl << endl;
}

void ConsoleInterface::played(Board::disk player, Point step) const {
    char c = player;
    cout << c << " played" << step << endl << endl;
}

void ConsoleInterface::gameOver() const {
    cout <<"Game over. ";
}

void ConsoleInterface::winner(Board::disk d) const {
    if (d == Board::blackActor) {
        cout <<"The winner is: the black player.";
    }
    if (d == Board::whiteActor) {
        cout <<"The winner is: the white player.";
    }
}

void ConsoleInterface::draw() const {
    cout <<"It's a draw.";
}

void ConsoleInterface::invalidInput() const {
    cout << "Invalid input" << endl;
}

void ConsoleInterface::askForMove() const {
    cout << "please enter your move row col (for example: 1 2):";
}

void ConsoleInterface::yourMove(Board::disk d) const {
    char c = d;
    cout << c;
    cout <<  ": It's your move." << endl;
}

void ConsoleInterface::noMoves() const {
    cout <<  "no possible moves. play passes back to the other player." << endl;
}

void ConsoleInterface::possibleMoves(const vector<Point> &v) const {
    cout <<  "your possible moves: ";

    //print possible points
    for (int i = 0; i < v.size() ; i++) {
        cout << v.at(i);
        if(i != v.size() -1){
            cout << ",";
        }
    }
}

void ConsoleInterface::mainMenu() const {
    cout << "Please choose game mode:" << endl;
    cout << "(1) Human player" << endl;
    cout << "(2) AI player" << endl;
    cout << "(3) Remote player" << endl;
}
void ConsoleInterface::invalidTryAgain() const {
    cout << " invalid input. Please try again" << endl;
}
void ConsoleInterface::commandMenu() const {
    cout << "Please select an option:" << endl;
    cout << "start <name> - to start a new game with that name " << endl;
    cout << "list_games - to see games that can be joined" <<  endl;
    cout << "join <name> - to join a game with that name" << endl;
}
void ConsoleInterface::nameTaken() const {
    cout << "This name is already taken. Please try a different name" << endl;
}

void ConsoleInterface::noSuchGame() const {
    cout << "A game with this name doesn't exist. Please choose an existing game" << endl;
}

void ConsoleInterface::printListGames(char *list) const {
    cout << list << endl;
}

int ConsoleInterface::chooseMode() {
    int chosenMode;
    cin >> chosenMode;
    cin.ignore();
    return chosenMode;
}
void ConsoleInterface::wrongMode() {
    if(cin.fail()) {
        this->invalidTryAgain();
        // get rid of failure state
        cin.clear();

        // discard 'bad' character(s)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else {
        this->invalidTryAgain();
    }
}
string ConsoleInterface::getCommand() {
    string s;
    getline(cin, s);
    return s;
}

Point ConsoleInterface::choosePoint() {
    int row;
    int col;
    cin >> row >> col;

    if(cin.fail()){
        // get rid of failure state
        cin.clear();

        // discard 'bad' character(s)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return Point(-1,-1);
    }

    return Point(row, col);
}
