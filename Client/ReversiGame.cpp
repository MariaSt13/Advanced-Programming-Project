
#include <iostream>
#include <cstdlib>
#include "ReversiGame.h"
using namespace std;

/**
 * constructor.
 * @param gameBoard - the board game
 * @param blackPlayer - the black player
 * @param whitePlayer - the white player
 * @param gameLogic - the logic of the game
 * @param m - the mode of the game
 * @param server - info of the server.
 * @param humanPlayer -the disk of the human player (relevant in remote game).
 * @param userInterface - the type of userInterface in this game.
 */
ReversiGame::ReversiGame(const Board *gameBoard, const Player *blackPlayer,const Player *whitePlayer,
                         GameLogic *gameLogic, mode m, Client client,Board::disk humanPlayer, UserInterface* display):
        gameBoard(gameBoard),blackPlayer(blackPlayer),whitePlayer(whitePlayer),gameLogic(gameLogic),
        currentMode(m), client(client), humanPlayer(humanPlayer), userInterface(display){

    this->hisTurn = this->blackPlayer;
    play();
}

/**
 * This function runs the game.
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
                   this->currentMode == humanAgainstHuman || (this->currentMode == remoteGame && this->hisTurn->getDisk() == this->humanPlayer));

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
                    char s[MAX_ARRAY_SIZE];
                    s[0] = (char)step.getX();
                    s[1]= ' ';
                    s[2] = (char)step.getY();

                    //send move to server
                    client.writeToServer(s,client.getClientSocket());
                }

            //no possible moves and if is remote game.
            } else {
                if(this->currentMode == remoteGame){
                    char s[MAX_ARRAY_SIZE] = "NoMove";
                    client.writeToServer(s,client.getClientSocket());
                }
            }
        }

        //if it is virtual player
        else{

            //remote game mode.
            if(this->currentMode == remoteGame) {
                printCurrentBoard(); // print update board after local player choice
                userInterface->waiting();
            }

            //current player choose step.
            try{
                step = this->hisTurn->chooseStep(userInterface);
            }
            catch(char const* msg){
                cout << "failed read other player step. Result:" << msg << endl;
                exit(1);
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

/**
 * Prints the current board.
 */
void ReversiGame::printCurrentBoard()const {
    //print board and current player.
    userInterface->currentBoard(this->gameBoard);
}

/**
 * print last point.
 * @param step - last point.
 * @param virtualOpponentPlayLastTurn - if the last turn was by a virtual player.
 */
void ReversiGame::printChoosenPoint(Point step,bool virtualOpponentPlayLastTurn){
    changeTurn();
    Board::disk c = (this->hisTurn->getDisk());
    if(!virtualOpponentPlayLastTurn){
        userInterface->noMoves(c);
    }
    else{
        userInterface->played(c, step);
    }
    changeTurn();
}

/**
 *  shows the final board and the winner.
 */
void ReversiGame::gameOver()const{
    printCurrentBoard();
    userInterface->gameOver();
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
        userInterface->winner(blackPlayer->getDisk());
    }
    else if(countBlack < countWhite){
        userInterface->winner(whitePlayer->getDisk());
    }
    else if(countBlack == countWhite){
        userInterface->draw();
    }

    //if it is remote game.
    if(this->currentMode == this->remoteGame){
        char s[MAX_ARRAY_SIZE] = "End";
        client.writeToServer(s,client.getClientSocket());
    }
}

/**
 * Checks if the game is over.
 * if the game is over return true, else return false.
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
 * Gets the step from the player.
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
                userInterface->invalidInput();
            }
            firstTry = false;
            userInterface->askForMove();
            step = this->hisTurn->chooseStep(userInterface);

        } while (!step.ifThePointIsInVector(v));

    return step;
}

/**
 * Prints the possible moves of the player in his turn.
 * @param v vector of points.
 * @return bool - if there are possible moves.
 */
bool ReversiGame::printPossibleMoves(const vector<Point> &v)const {
    Board::disk c = (this->hisTurn->getDisk());
    userInterface->yourMove(c);

    //if there is no possible moves.
    if(v.size() == 0){
        userInterface->noMoves();
        return false;
    }
    userInterface->possibleMoves(v);
    return true;
}


/**
 * Switch between the players turn.
 */
void  ReversiGame::changeTurn (){
    if(this->hisTurn == this->blackPlayer){
        this->hisTurn = this->whitePlayer;
    }
    else{
        this->hisTurn = this->blackPlayer;
    }
}