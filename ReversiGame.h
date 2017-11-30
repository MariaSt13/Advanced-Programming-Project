
#ifndef EXAM1_REVERSIGAME_H
#define EXAM1_REVERSIGAME_H
#include "Board.h"
#include "Player.h"
#include "GameLogic.h"

/*
 * this class runs the game. The game ends when the entire
 * board is filled or when there are no further possible
 * moves to both sides.
 */
class ReversiGame {

public:

    //game mode.
    enum mode{noMode = 0, humanAgainstAI = 2,humanAgainsHuman= 1};

    //constructor.
    ReversiGame(const Board* gameBoard,const Player* whitePlayer,const Player* blackPlayer,GameLogic* gameLogic,mode m);


    //this function run the game.
    void play();

private:
    const Board* gameBoard;
    const Player* whitePlayer;
    const Player* blackPlayer;
    GameLogic* gameLogic;
    const Player* hisTurn;
    mode currentMode;

    // gets the step from the player
    Point getStep(bool firstTry,vector<Point> v);

    /*
     * if the game end  - return true
     * else return false.
     */
    bool isGameOver();
    
    //print the step that played.
    void  printCurrentBoard()const;

    //print the step that played.
    void  printChoosenPoint(Point p,bool virtualOponentPlaylastTurn);

    //switch between the players turn.
    void changeTurn();

    //print the possible moves of the player in his turn.
    bool printPossibleMoves(const vector<Point> &v) const ;

    //print the final board and the winner.
    void gameOver() const;

};


#endif //EXAM1_REVERSIGAME_H
