
#include "StandardGameLogicTest.h"
#include <gtest/gtest.h>
#include "../StandardGameLogic.h"
#include "../HumanLocalPlayer.h"
#include "../ConsoleBoard.h"

#define SIZE_ROW_STANDARD 8
#define SIZE_COL_STANDARD 8
#define SIZE_ROW_SMALL 3
#define SIZE_COL_SMALL 3

/*
 * test 1: check that returnValidMoves function work correctly.
 */
TEST(GameLogicTest,returnValidMovesTest){
    StandardGameLogic gameLogic = StandardGameLogic();
    ConsoleBoard b = ConsoleBoard(SIZE_ROW_STANDARD, SIZE_COL_STANDARD);

    //check black actor valid steps.
    HumanLocalPlayer blackPlayer = HumanLocalPlayer(b.blackActor);
    vector<Point> v1 = gameLogic.returnValidMoves(&blackPlayer,&b);
    vector<Point> v2;
    v2.push_back(Point(3,4));
    v2.push_back(Point(4,3));
    v2.push_back(Point(5,6));
    v2.push_back(Point(6,5));
    for (vector<Point>::const_iterator it = v1.begin(); it < v1.end(); it++) {
        EXPECT_TRUE((*it).ifThePointIsInVector(v2));
    }
    EXPECT_FALSE(Point(7,1).ifThePointIsInVector(v1));
    EXPECT_FALSE(Point(8,1).ifThePointIsInVector(v1));
    EXPECT_FALSE(Point(7,3).ifThePointIsInVector(v1));
    EXPECT_FALSE(Point(1,1).ifThePointIsInVector(v1));

    //check white actor valid steps.
    HumanLocalPlayer whitePLayer = HumanLocalPlayer(b.whiteActor);
    v1.clear();
    v1 = gameLogic.returnValidMoves(&whitePLayer,&b);
    v2.clear();
    v2.push_back(Point(3,5));
    v2.push_back(Point(5,3));
    v2.push_back(Point(4,6));
    v2.push_back(Point(6,4));

    for (vector<Point>::const_iterator it = v1.begin(); it < v1.end(); it++) {
        EXPECT_TRUE((*it).ifThePointIsInVector(v2));
    }
    EXPECT_FALSE(Point(3,4).ifThePointIsInVector(v1));
    EXPECT_FALSE(Point(4,3).ifThePointIsInVector(v1));
    EXPECT_FALSE(Point(4,9).ifThePointIsInVector(v1));
    EXPECT_FALSE(Point(6,5).ifThePointIsInVector(v1));
}


/*
 * test 2: check that returnValidMoves function work correctly on
 * small board.
 */
TEST(GameLogicTest,returnValidMovesSmallBoardTest){
    StandardGameLogic gameLogic = StandardGameLogic();
    ConsoleBoard b = ConsoleBoard(SIZE_ROW_SMALL, SIZE_COL_SMALL);

    //check black actor valid steps.
    HumanLocalPlayer blackPlayer = HumanLocalPlayer(b.blackActor);
    vector<Point> v1 = gameLogic.returnValidMoves(&blackPlayer,&b);
    vector<Point> v2;
    v2.push_back(Point(1,2));
    v2.push_back(Point(2,1));
    for (vector<Point>::const_iterator it = v1.begin(); it < v1.end(); it++) {
        EXPECT_TRUE((*it).ifThePointIsInVector(v2));
    }
    EXPECT_FALSE(Point(1,1).ifThePointIsInVector(v1));
    EXPECT_FALSE(Point(1,3).ifThePointIsInVector(v1));

    //check white actor valid steps.
    HumanLocalPlayer whitePLayer = HumanLocalPlayer(b.whiteActor);
    v1.clear();
    v1 = gameLogic.returnValidMoves(&whitePLayer,&b);
    v2.clear();
    v2.push_back(Point(1,3));
    v2.push_back(Point(3,1));
    for (vector<Point>::const_iterator it = v1.begin(); it < v1.end(); it++) {
        EXPECT_TRUE((*it).ifThePointIsInVector(v2));
    }
    EXPECT_FALSE(Point(1,1).ifThePointIsInVector(v1));
    EXPECT_FALSE(Point(1,2).ifThePointIsInVector(v1));
}


/*
 * test 3: check that if the game start with full board or
 * there is no valid moves. return valid moves return empty
 * vactor.
 */
TEST(GameLogicTest,returnValdMovesWithFullBoard){
    StandardGameLogic gameLogic = StandardGameLogic();
    ConsoleBoard b = ConsoleBoard(SIZE_ROW_STANDARD, SIZE_COL_STANDARD);
    HumanLocalPlayer whitePlayer = HumanLocalPlayer(b.whiteActor);
    HumanLocalPlayer blackPlayer = HumanLocalPlayer(b.blackActor);
    Board::disk** array =  b.getArray();
    for (int i = 0; i < b.getRowSize(); i++) {
        for (int j = 0; j < b.getColSize() ; j++) {
            array[i][j] = b.blackActor;
        }
    }
    //check full board.
    vector<Point> v1 = gameLogic.returnValidMoves(&whitePlayer,&b);
    vector<Point> v2 = gameLogic.returnValidMoves(&blackPlayer,&b);
    EXPECT_TRUE(v1.empty());
    EXPECT_TRUE(v2.empty());

    //no valid moves.
    array[2][4] = b.empty;
    array[1][8] = b.empty;
    v1 = gameLogic.returnValidMoves(&whitePlayer,&b);
    v2 = gameLogic.returnValidMoves(&blackPlayer,&b);
    EXPECT_TRUE(v1.empty());
    EXPECT_TRUE(v2.empty());

    //no valid moves.
    array[3][1] = b.whiteActor;
    array[4][7] = b.whiteActor;
    v1 = gameLogic.returnValidMoves(&whitePlayer,&b);
    v2 = gameLogic.returnValidMoves(&blackPlayer,&b);
    EXPECT_TRUE(v1.empty());
    EXPECT_TRUE(v2.empty());
}

/*
 * test 4: check that if the game start with full board or
 * there is no valid moves. return valid moves return empty
 * vactor on small board.
 */
TEST(GameLogicTest,returnValdMovesWithFullBoardSmallBoard){
    StandardGameLogic gameLogic = StandardGameLogic();
    ConsoleBoard b = ConsoleBoard(SIZE_ROW_SMALL, SIZE_COL_SMALL);
    HumanLocalPlayer whitePlayer = HumanLocalPlayer(b.whiteActor);
    HumanLocalPlayer blackPlayer = HumanLocalPlayer(b.blackActor);
    Board::disk** array =  b.getArray();
    for (int i = 0; i < b.getRowSize(); i++) {
        for (int j = 0; j < b.getColSize() ; j++) {
            array[i][j] = b.blackActor;
        }
    }
    //check full board.
    vector<Point> v1 = gameLogic.returnValidMoves(&whitePlayer,&b);
    vector<Point> v2 = gameLogic.returnValidMoves(&blackPlayer,&b);
    EXPECT_TRUE(v1.empty());
    EXPECT_TRUE(v2.empty());

    //no valid moves.
    array[1][1] = b.empty;
    v1 = gameLogic.returnValidMoves(&whitePlayer,&b);
    v2 = gameLogic.returnValidMoves(&blackPlayer,&b);
    EXPECT_TRUE(v1.empty());
    EXPECT_TRUE(v2.empty());

    //no valid moves.
    array[1][2] = b.whiteActor;
    array[1][1] = b.whiteActor;
    array[1][3] = b.empty;
    v1 = gameLogic.returnValidMoves(&whitePlayer,&b);
    v2 = gameLogic.returnValidMoves(&blackPlayer,&b);
    EXPECT_TRUE(v1.empty());
    EXPECT_TRUE(v2.empty());
}