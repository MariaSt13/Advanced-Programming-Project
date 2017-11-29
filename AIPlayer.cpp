//
// Created by linoy on 28/11/17.
//

#include "AIPlayer.h"
#include "ConsoleBoard.h"
#include "HumanLocalPlayer.h"


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
    for (int i = 0; i < v1.size() ; i++) {

        //initialize current point.
        Point currentAIPoint = v1.at(i);

        //makes AI player's step.
        gameLogic->flipCells(this, currentAIPoint, copyBoard);

        //get opponent valid steps vector.
        v2 = this->gameLogic->returnValidMoves(blackActor,copyBoard);

        //this loop go over all opponent valid steps.
        for (int j = 0; j < v2.size(); j++) {
            copyBoard2 =  new ConsoleBoard(copyBoard);
            Point currentOpponentPoint = v2.at(j);
            //makes opponent player's step.
            gameLogic->flipCells(blackActor, currentOpponentPoint, copyBoard2);

            //calculate score for this step and push to vector.
           // currentScore = copyBoard2->numOfPlayerDisks(blackActor) - copyBoard2->numOfPlayerDisks(this);
            score.push_back(make_pair(currentAIPoint,currentScore));

        }

        //copy board.
        copyBoard =  new ConsoleBoard(this->board);
    }


    //find the index of the minimum score.
    int min = 0;
    int index =0;

    for (int k = 0; k < score.size(); k++) {
        if(score[k].second < min){
            min = score[k].second;
            index = k;
        }
    }

    return score[index].first;

}


//constructor.
AIPlayer::AIPlayer(Board::disk d, GameLogic* gameLogic, Board* board): Player(d), gameLogic(gameLogic),board(board){}