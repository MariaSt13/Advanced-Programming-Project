
#include "StandardGameLogicTest.h"
#include <gtest/gtest.h>
#include "../StandardGameLogic.h"
#include "../HumanLocalPlayer.h"
#include "../ConsoleBoard.h"



/*
 * test 1: check that returnValidMoves function work correctly.
 */
TEST(GameLogicTest,returnValidMovesTest){
    StandardGameLogic gameLogic = StandardGameLogic();
    ConsoleBoard b = ConsoleBoard(SIZE_ROW, SIZE_COL);
    HumanLocalPlayer whitePlayer = HumanLocalPlayer(b.whiteActor);
    vector<Point> v1 = gameLogic.returnValidMoves(&whitePlayer,&b);
    vector<Point> v2;
    v2.push_back(Point(3,4));
    v2.push_back(Point(4,3));
    v2.push_back(Point(5,6));
    v2.push_back(Point(6,5));

}


/*
 * test 2: check that if the game start with full board
 * the game is over.
 */
TEST(GameLogicTest,returnValdMovesWithFullBoard){
    StandardGameLogic gameLogic = StandardGameLogic();
    ConsoleBoard b = ConsoleBoard(SIZE_ROW, SIZE_COL);
    HumanLocalPlayer whitePlayer = HumanLocalPlayer(b.whiteActor);
    HumanLocalPlayer blackPlayer = HumanLocalPlayer(b.blackActor);
    Board::disk** array =  b.getArray();
    for (int i = 0; i < b.getRowSize(); i++) {
        for (int j = 0; j < b.getColSize() ; j++) {
            array[i][j] = b.blackActor;
        }
    }
    vector<Point> v1 = gameLogic.returnValidMoves(&whitePlayer,&b);
    vector<Point> v2 = gameLogic.returnValidMoves(&blackPlayer,&b);
    EXPECT_TRUE(v1.empty());
    EXPECT_TRUE(v2.empty());
}


/*
 * test 3: check function flipCells work correctly.
 */
TEST(GameLogicTest,flipCells){


}

