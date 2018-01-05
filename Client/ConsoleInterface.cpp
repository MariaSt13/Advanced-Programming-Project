#include <iostream>
#include <limits>
#include "ConsoleInterface.h"

/**
 * Prints for user that the program is waiting
 * to the second user to choose step.
 */
void ConsoleInterface::waiting() const {
    cout << "Waiting for other player's move..." << endl;
}


/**
 * prints the current board to thr user.
 * @param b - the board.
 */
void ConsoleInterface::currentBoard(const Board *b) const {
    cout << endl << "current board:" << endl << endl;
    printBoard(b);
}


/**
 * prints the current board to thr user.
 * @param b - the board.
 */
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

/**
 * Prints numbered row above the board.
 * @param size - row size.
 */
void ConsoleInterface::printNumberedRow(int size) const {
    for (int k = 1; k < size ; k++) {
        cout << " | ";
        cout << k;
    }
    cout << " ";
    printSeparator(size);
}

/**
 * Prints separator line to separate board rows.
 * @param size - size of the separator.
 */
void ConsoleInterface::printSeparator(int size) const {
    cout << "|" << endl;
    for (int i = 1; i < size; ++i) {
        cout << "----";
    }
    cout << "--" << endl;
}


/**
 * Prints that the player whose disk is d had no moves.
 * @param d - the player disk.
 */
void ConsoleInterface::noMoves(Board::disk d) const {
    char c = d;
    cout << c << " had no moves" << endl << endl;
}


/**
 * Prints last player disk and his choice.
 * @param player - last played user.
 * @param step - the step he had chosen.
 */
void ConsoleInterface::played(Board::disk player, Point step) const {
    char c = player;
    cout << c << " played" << step << endl << endl;
}

/**
 * Prints that the game is over.
 */
void ConsoleInterface::gameOver() const {
    cout <<"Game over. ";
}


/**
 * Prints the winner at the end of the game.
 * @param d - winner player disk.
 */
void ConsoleInterface::winner(Board::disk d) const {
    if (d == Board::blackActor) {
        cout <<"The winner is: the black player.";
    }
    if (d == Board::whiteActor) {
        cout <<"The winner is: the white player.";
    }
}

/**
 * Prints that the game is over with draw.
 */
void ConsoleInterface::draw() const {
    cout <<"It's a draw.";
}

/**
 * Prints an error message of invalid input.
 */
void ConsoleInterface::invalidInput() const {
    cout << "Invalid input" << endl;
}

/**
 * Prints to the user that he need to chose step.
 */
void ConsoleInterface::askForMove() const {
    cout << "please enter your move row col (for example: 1 2):";
}

/**
 * Prints to the user that it is his turn to play.
 * @param d - player disk.
 */
void ConsoleInterface::yourMove(Board::disk d) const {
    char c = d;
    cout << c;
    cout <<  ": It's your move." << endl;
}

/**
 * Prints a message of no possible moves.
 */
void ConsoleInterface::noMoves() const {
    cout <<  "no possible moves. play passes back to the other player." << endl;
}

/**
 * Prints to the user all his possible moves.
 * @param v - vector of possible moves.
 */
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

/**
 * Prints the main menu.
 */
void ConsoleInterface::mainMenu() const {
    cout << "Please choose game mode:" << endl;
    cout << "(1) Human player" << endl;
    cout << "(2) AI player" << endl;
    cout << "(3) Remote player" << endl;
}

/**
 * Prints an error message of invalid input.
 */
void ConsoleInterface::invalidTryAgain() const {
    cout << "invalid input. Please try again" << endl;
}

/**
 * Prints to the user all possible commands.
 */
void ConsoleInterface::commandMenu() const {
    cout << "Please select an option:" << endl;
    cout << "start <name> - to start a new game with that name " << endl;
    cout << "list_games - to see games that can be joined" <<  endl;
    cout << "join <name> - to join a game with that name" << endl;
}

/**
 * Prints an error message of invalid input.
 */
void ConsoleInterface::nameTaken() const {
    cout << "This name is already taken. Please try a different name" << endl;
}

/**
 * Prints an error message of invalid input.
 */
void ConsoleInterface::noSuchGame() const {
    cout << "A game with this name doesn't exist. Please choose an existing game" << endl;
}

/**
 * Prints all the games that the user can join.
 * @param list - list of waiting games.
 */
void ConsoleInterface::printListGames(char *list) const {
    cout << list << endl;
}

/**
 * Prints an error message of invalid input by calling
 * invalidTryAgain function if cin failed.
 */
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

/**
 * Get choose from the user.
 * @return - the selected mode.
 */
int ConsoleInterface::chooseMode() {
    int chosenMode;
    cin >> chosenMode;
    cin.ignore();
    return chosenMode;
}

/**
 * Get choose from the user.
 * @return - the selected command.
 */
string ConsoleInterface::getCommand() {
    string s;
    getline(cin, s);
    return s;
}

/**
 * Get choose from the user.
 * @return - the selected point.
 */
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
