
#include <iostream>
#include <unistd.h>
#include <cstdlib>

using namespace std;
#include "ReversiGame.h"

/**
 * constructor.
 * @param gameBoard - the board game
 * @param blackPlayer - the black player
 * @param whitePlayer - the white player
 * @param gameLogic - the logic of the game
 * @param m - the mode of the game
 */
ReversiGame::ReversiGame(const Board *gameBoard, const Player *blackPlayer,const Player *whitePlayer,
                         GameLogic *gameLogic, mode m, ConnectToServer server,Player* humanPlayer):
        gameBoard(gameBoard),blackPlayer(blackPlayer),whitePlayer(whitePlayer),gameLogic(gameLogic),
        currentMode(m), serverInfo(server), humanPlayer(humanPlayer){

    this->hisTurn = this->blackPlayer;
    play();
}

/*
 * this function run the game.
 */
void ReversiGame::play() {
    Point step = Point(-1,-1);
    vector<Point> v;
    bool firstTimeInLoop = true;
    bool virtualOpponentPlayLastTurn = false;

    //running the game
    while(!isGameOver()) {

        bool firstTry = true;
        bool ifItIsHumanPLayer = ((this->currentMode == humanAgainstAI && this->hisTurn->getDisk() == this->gameBoard->blackActor) ||
                   this->currentMode == humanAgainstHuman || (this->currentMode == remoteGame && this->hisTurn->getDisk() == this->humanPlayer->getDisk()));

        //if it is turn of human player.
        if(ifItIsHumanPLayer){

            //get a vector of possible points
            v = this->gameLogic->returnValidMoves(this->hisTurn, this->gameBoard);

            printCurrentBoard();

            //if the opponent is a virtual player , print his last move.
            if((this->currentMode == remoteGame || this->currentMode == humanAgainstAI) && !firstTimeInLoop){
                printChoosenPoint(step,virtualOpponentPlayLastTurn);
            }

            //if there are possible move to current player.
            if(printPossibleMoves(v)) {
                step = getStep(firstTry,v);

                //makes the current player's choice and changes the next player's turn.
                gameLogic->flipCells(this->hisTurn, step, gameBoard, false);

                //is this is remote game mode.
                if (this->currentMode == remoteGame) {
                    char s[7];
                    s[0] = (char)step.getX();
                    s[1]= ' ';
                    s[2] = (char)step.getY();

                    //send move to server
                    serverInfo.writeToServer(s,serverInfo.getClientSocket());
                }

            //no possible moves and if is remote game.
            } else {
                if(this->currentMode == remoteGame){
                    char s[7] = "NoMove";
                    serverInfo.writeToServer(s,serverInfo.getClientSocket());
                }
            }
        }

        //if it is virtual player
        else{

            //remote game mode.
            if(this->currentMode == remoteGame) {
                printCurrentBoard(); // print update board after local player choice
                cout << "Waiting for other player's move..." << endl;
            }

            //current player choose step.
            try{
                step = this->hisTurn->chooseStep();
            }
            catch(char const* msg){
                cout << "failed read other player step. Result:" << msg << endl;
                exit(-1);
            }


            //if there are possible move to current player.
            if (!(step == Point(-1,-1))){
                //makes the current player's choice and changes the next player's turn.
                gameLogic->flipCells(this->hisTurn, step, gameBoard, true);
                virtualOpponentPlayLastTurn = true;
            }

            //if there are no possible move to current player.
            else
                virtualOpponentPlayLastTurn = false;
        }
        changeTurn();
        firstTimeInLoop = false;
    }
    gameOver();
}

/*
 * prints the current board.
 */
void ReversiGame::printCurrentBoard()const {
    //print board and current player.
    cout << endl << "current board:" << endl << endl;
    this->gameBoard->printBoard();
}

/*
 * print last point.
 * @param step - last point.
 */
void ReversiGame::printChoosenPoint(Point step,bool virtualOpponentPlayLastTurn){
    changeTurn();
    char c = (this->hisTurn->getDisk());
    if(!virtualOpponentPlayLastTurn){
        cout << c << " had no moves" << endl << endl;
    }
    else{
        cout << c << " played" << step << endl << endl;
    }
    changeTurn();
}

/*
 *  print the final board and the winner.
 */
void ReversiGame::gameOver()const{
    printCurrentBoard();
    cout <<"Game over. ";
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
        cout <<"The winner is: the black player.";
    }
    else if(countBlack < countWhite){
        cout <<"The winner is: the white player.";
    }
    else if(countBlack == countWhite){
        cout <<"It's a draw.";
    }

    //if it is remote game.
    if(this->currentMode == this->remoteGame){
        char s[4] = "End";
        serverInfo.writeToServer(s,serverInfo.getClientSocket());
    }
}

/*
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

/*
 * gets the step from the player.
 * @param firstTry - true if it is the first try.
 * @param v vector of points.
 * @return Point.
 */
Point ReversiGame:: getStep(bool firstTry,vector<Point> v){
    //get input from the player.
    Point step = Point(-1, -1);
        cout << endl << endl;
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

/*
 * print the possible moves of the player in his turn.
 * @param v vector of points.
 * @return bool.
 */
bool ReversiGame::printPossibleMoves(const vector<Point> &v)const {
    char c = (this->hisTurn->getDisk());
    cout << c;
    cout <<  ": It's your move." << endl;

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


/*
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