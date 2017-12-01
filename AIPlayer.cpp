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
    cout<<endl<<"****************in min max algorithm****************" <<endl;
    vector<Point> v1;
    vector<Point> v2;
    Board* copyBoard = new ConsoleBoard(this->board);
    Board* copyBoard2;
    int mScore;
    vector< pair<Point,int > > v;
    Player* blackActor = new HumanLocalPlayer(board->blackActor);
    int mMaxScore = 0;

    //Step1 :Given the current board mode, find all possible moves of the AI player
    v1 = this->gameLogic->returnValidMoves(this,copyBoard);

    //Step 2: For each possible move m:
    for (vector<Point>::const_iterator it = v1.begin(); it < v1.end(); it++) {

        //initialize possible move m.
        Point m = (*it);

        cout<<"AI point " << m <<": "<<endl;

        //Step 4: make the move and update the status of the board
        gameLogic->flipCells(this, m, copyBoard);

        //get opponent valid steps vector.
        v2 = this->gameLogic->returnValidMoves(blackActor,copyBoard);

        //if this move causes the opponent to have no legal moves.
        if(v2.size() == 0){
            cout<<"this move causes the opponent to have no legal moves. " <<endl;
            delete(copyBoard);
            delete(blackActor);
            return m;
        }

        //Step 5: For all possible moves of the opponent in the new board mode:
        for (vector<Point>::const_iterator it2 = v2.begin(); it2 < v2.end(); it2++) {
            copyBoard2 =  new ConsoleBoard(copyBoard);
            Point currentOpponentPoint = (*it2);

            cout<<"opponent point " << currentOpponentPoint<<": ";

            //make opponent move and update the status of the board
            gameLogic->flipCells(blackActor, currentOpponentPoint, copyBoard2);

            //Step 6: Calculate the opponent's score in the new position(the number of blackActor discs less than a number
            //of computer disks).
            mScore = copyBoard2->numOfPlayerDisks(blackActor->getDisk()) - copyBoard2->numOfPlayerDisks(this->getDisk());
            cout<<"mScore :" << mScore <<",mMaxScore: " << mMaxScore<<endl;

            //Step 7: Set m score as the maximum score that the opponent can receive in the new mode
            if(mScore > mMaxScore || it2 == v2.begin()){
                cout<<"update max score to be: " << mScore<<endl;
                mMaxScore = mScore;
            }
            delete(copyBoard2);
        }

        cout<<"insert max: " << mMaxScore<<endl<<endl;
        cout<<"-------------------------------------------------"<<endl;
        ///add m and the score of m to the vector.
        v.push_back(make_pair(m,mMaxScore));

        //copy board.
        delete(copyBoard);
        copyBoard =  new ConsoleBoard(this->board);
    }


    //Step 8: Select the m move with the lowest score.
    int min = v[0].second;
    int index = 0;

    for (int k = 0; k < v.size(); k++) {
        if(v[k].second < min){
            min = v[k].second;
            index = k;
        }
    }
    // delete allocated memory
    delete(copyBoard);
    delete(blackActor);

    // return the chosen point
    return v[index].first;

}
