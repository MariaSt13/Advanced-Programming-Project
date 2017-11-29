#include <iostream>
#include "AIPlayer.h"
#include "ConsoleBoard.h"
#include "HumanLocalPlayer.h"


/*
 * constructor.
 */
AIPlayer::AIPlayer(Board::disk d, GameLogic* gameLogic, Board* board): Player(d), gameLogic(gameLogic),board(board){}

/*
 * The AI player chooses his turn with minimax algorithm.
 */
Point AIPlayer::chooseStep() const {
    vector<Point> v1;
    vector<Point> v2;
    Board* copyBoard = new ConsoleBoard(this->board);
    Board* copyBoard2;
    int currentScore;
    vector< pair<Point,int > > score;
    Player* blackActor = new HumanLocalPlayer(board->blackActor);

    //get AI valid steps vector.
    v1 = this->gameLogic->returnValidMoves(this,copyBoard);

    //this loop go over all AI valid steps.
    for (vector<Point>::const_iterator it = v1.begin(); it < v1.end(); it++) {

        //initialize current point.
        Point currentAIPoint = (*it);

        //makes AI player's step.
        gameLogic->flipCells(this, currentAIPoint, copyBoard);

        //get opponent valid steps vector.
        v2 = this->gameLogic->returnValidMoves(blackActor,copyBoard);

        //there is no steps for opponent.
        if(v2.size() == 0 ){
            delete(copyBoard);
            delete(blackActor);
            return currentAIPoint;
        }

        //this loop go over all opponent valid steps.
        for (vector<Point>::const_iterator it2 = v2.begin(); it2 < v2.end(); it2++) {
            copyBoard2 =  new ConsoleBoard(copyBoard);
            Point currentOpponentPoint = (*it2);
            //makes opponent player's step.
            gameLogic->flipCells(blackActor, currentOpponentPoint, copyBoard2);

            //calculate score for this step and push to vector.
            currentScore = copyBoard2->numOfPlayerDisks(blackActor->getDisk()) - copyBoard2->numOfPlayerDisks(this->getDisk());
            score.push_back(make_pair(currentAIPoint,currentScore));
            delete(copyBoard2);
        }

        //copy board.
        delete(copyBoard);
        copyBoard =  new ConsoleBoard(this->board);
    }


    //find the index of the minimum score.
    int min = score[0].second;
    int index = 0;

    for (int k = 0; k < score.size(); k++) {
        if(score[k].second < min){
            min = score[k].second;
            index = k;
        }
    }
    // delete allocated memory
    delete(copyBoard);
    delete(blackActor);

    // return the chosen point
    return score[index].first;

}
