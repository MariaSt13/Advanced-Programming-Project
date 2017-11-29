//name: linoy cohen
//ID: 206333502

#include <iostream>
using namespace std;
#include "ReversiGame.h"
#include "string"

/**
 * constructor.
 * @param gameBoard
 * @param blackPlayer
 * @param whitePlayer
 * @param gameLogic
 * @param m
 */
ReversiGame::ReversiGame(const Board *gameBoard, const Player *blackPlayer,const Player *whitePlayer, GameLogic *gameLogic, mode m):
    gameBoard(gameBoard),blackPlayer(blackPlayer),whitePlayer(whitePlayer),gameLogic(gameLogic),currentMode(m){
    this->hisTurn = this->blackPlayer;
    play();
}

/**
 * this function run the game.
 */
void ReversiGame::play() {
    Point step = Point(-1,-1);
    bool firstTimeInLoop = true;
    bool virtualOponentPlaylastTurn = false;

    //running the game
    while(!isGameOver()) {

        bool firstTry = true;
        bool ifItisHumanPLayer = ((this->currentMode == humanAgainstAI && this->hisTurn->getDisk() == this->gameBoard->blackActor) ||
                   this->currentMode == humanAgainsHuman);

        //get a vector of possible points and print it.
        vector<Point> v = this->gameLogic->returnValidMoves(this->hisTurn, this->gameBoard);

        //if it is turn of human player.
        if(ifItisHumanPLayer){
            printCurrentBoard();

            //if the opponent is a virtual player , print his last move.
            if(this->currentMode == humanAgainstAI && !firstTimeInLoop){
                printChoosenPoint(step,virtualOponentPlaylastTurn);
            }

            //if there are possible move to current player.
            if(printPossibleMoves(v)) {

                step = getStep(firstTry,v);

                //makes the current player's choice and changes the next player's turn.
                gameLogic->flipCells(this->hisTurn, step, gameBoard);
            }
        }

        //if it is virtual player
        else{

            //if there are possible move to current player.
            if(v.size() != 0){
                step = this->hisTurn->chooseStep();

                //makes the current player's choice and changes the next player's turn.
                gameLogic->flipCells(this->hisTurn, step, gameBoard);
                virtualOponentPlaylastTurn = true;
            }
            else{
                virtualOponentPlaylastTurn = false;
            }
        }
        changeTurn();
        firstTimeInLoop = false;
    }
    gameOver();
}

/**
 * print the current board.
 */
void ReversiGame::printCurrentBoard()const {
    //print board and current player.
    cout << "\n" << "current board:\n\n";
    this->gameBoard->printBoard();
}

/**
 * print last point.
 * @param step - last point.
 */
void ReversiGame::printChoosenPoint(Point step,bool virtualOponentPlaylastTurn){
    changeTurn();
    char c = (this->hisTurn->getDisk());
    if(!virtualOponentPlaylastTurn){
        cout <<c<< " had no moves"<<endl<<endl;
    }
    else{
        cout <<c<< " played" << step<<endl<<endl;
    }
    changeTurn();
}

/**
 *  print the final board and the winner.
 */
void ReversiGame::gameOver()const{
    printCurrentBoard();
    cout <<"game over. ";
    int countWhite = 0;
    int countBlack = 0;
    Board::disk ** array = gameBoard->getArray();

    //the function checks which player has more discs on the board.
    for (int i = 1; i < gameBoard->getRowSize() ; i++) {
        for (int j = 1; j < gameBoard->getColSize(); j++) {
            if(array[i][j] == blackPlayer->getDisk()){
                countBlack++;
            }
            else if(array[i][j] == whitePlayer->getDisk()){
                countWhite++;
            }
        }
    }

    //prints the winning player.
    if(countBlack > countWhite){
        cout <<"winner: the black player";
    }
    else if(countBlack < countWhite){
        cout <<"winner: the white player";
    }
    else if(countBlack == countWhite){
        cout <<"no winner";
    }
}

/**
 * if the game end return true, else return false.
 * @return bool.
 */
bool ReversiGame::isGameOver() {
    //if the there is no empty cells return true.
    if(this->gameBoard->ifBoardIsFull()){
        return true;
    }

    vector<Point> v1;
    vector<Point> v2;

    v1 = this->gameLogic->returnValidMoves(this->hisTurn,this->gameBoard);

    //if there is no possible moves to current player.
    if(v1.size()==0){
        changeTurn();
        v2 = this->gameLogic->returnValidMoves(this->hisTurn,this->gameBoard);

        //when there are no further possible moves to either side.
        if(v2.size() == 0){
            return true;
        }
        changeTurn();
        return false;
    }
}

/**
 *
 * @param firstTry - true if it is the first try.
 * @param v vector of points.
 * @return Point.
 */
Point ReversiGame:: getStep(bool firstTry,vector<Point> v){
    //get input from the player.
    Point step = Point(-1, -1);
        cout << "\n\n";
        do {
            if(!firstTry){
                cout << "Invalid input" << endl;
            }
            firstTry = false;
            cout << "please enter your move row col (for example: 1 2):";
            step = this->hisTurn->chooseStep();

        } while (!step.ifThePointIsInVector(v));

    return step;
}

/**
 * print the possible moves of the player in his turn.
 * @param v vector of points.
 * @return bool.
 */
bool ReversiGame::printPossibleMoves(const vector<Point> &v)const {
    char c = (this->hisTurn->getDisk());
    cout << c;
    cout <<  ": It's your move.\n";

    //if there is no possible moves.
    if(v.size() == 0){
        cout <<  "no possible moves. play passes back to the other player." << endl;
        return false;
    }
    cout <<  "your possible moves: ";

    //print possible points
    for (int i = 0; i < v.size() ; i++) {
        cout << v.at(i);
        if(i != v.size() -1){
            cout << ",";
        }
    }
    return true;
}


/**
 * switch between the players turn.
 */
void  ReversiGame::changeTurn (){
    if(this->hisTurn == this->blackPlayer){
        this->hisTurn = this->whitePlayer;
    }
    else{
        this->hisTurn = this->blackPlayer;
    }
}