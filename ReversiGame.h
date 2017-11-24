//name: linoy cohen
//ID: 206333502

#ifndef EXAM1_REVERSIGAME_H
#define EXAM1_REVERSIGAME_H
#include "Board.h"
#include "Player.h"
#include "GameLogic.h"

//this class runs the game. The game ends when the entire
// board is filled or when there are no further possible
// moves to either side.
class ReversiGame {
private:
    const Board* gameBoard;
    const Player* whitePlayer;
    const Player* blackPlayer;
    GameLogic* gameLogic;
    const Player* hisTurn;

    //switch between the players turn.
    void changeTurn();

    //print the possible moves of the player in his turn.
    bool printPossibleMoves(const vector<Point> &v) const ;

    //print the final board and the winner.
    void gameOver() const;

public:
    //constructor.
    ReversiGame(const Board* gameBoard,const Player* whitePlayer,const Player* blackPlayer,GameLogic* gameLogic);

    //this function run the game.
    void play();

    // if the game end return true, else
    // return false.
    bool isGameOver();

};


#endif //EXAM1_REVERSIGAME_H
