//
// Created by linoy on 29/11/17.
//

#include "ConsoleBoardTest.h"
#include <gtest/gtest.h>
#include "../ConsoleBoard.h"

/*
 * test 1: check that copy constructor work correctly.
 */
TEST(BoardTest,copyConstuctor){
    ConsoleBoard b =  ConsoleBoard(SIZE_ROW,SIZE_COL);
    Board::disk** array =  b.getArray();
    array[4][6] = b.blackActor;
    array[4][5] = b.blackActor;
    array[1][6] = b.blackActor;
    array[2][3] = b.blackActor;
    array[4][6] = b.whiteActor;
    array[4][5] = b.whiteActor;
    array[1][6] = b.whiteActor;
    array[2][3] = b.whiteActor;
    bool answer = true;

    ConsoleBoard copyBoard =  ConsoleBoard(&b);
    Board::disk** copyBoardArr =  b.getArray();
    for (int i = 0; i < b.getRowSize(); i++) {
        for (int j = 0; j < b.getColSize() ; j++) {
            if(  array[i][j] != copyBoardArr[i][j]){
                answer = false;
            }
        }
    }
    //EXPECT_TRUE(answer);
}

/*
 * test 2: check that fullBoard function work correctly.
 */
TEST(BoardTest,fullBoard){
    ConsoleBoard b =  ConsoleBoard(SIZE_ROW,SIZE_COL);
    Board::disk** array =  b.getArray();

    for (int i = 0; i < b.getRowSize(); i++) {
        for (int j = 0; j < b.getColSize() ; j++) {
            array[i][j] = b.blackActor;
        }
    }
    EXPECT_TRUE(b.ifBoardIsFull());
    array[5][4] = b.empty;
    EXPECT_FALSE(b.ifBoardIsFull());
    array[5][4] = b.whiteActor;
    EXPECT_TRUE(b.ifBoardIsFull());
}


/*
 * test 2: check that pointIsInRange function work correctly.
 */
TEST(BoardTest,BoardLimits){
    ConsoleBoard b =  ConsoleBoard(SIZE_ROW,SIZE_COL);
    EXPECT_FALSE(b.pointIsInRange(Point(-1,-1)));
    EXPECT_FALSE(b.pointIsInRange(Point(9,9)));
    EXPECT_FALSE(b.pointIsInRange(Point(-7,-5)));
    EXPECT_FALSE(b.pointIsInRange(Point(-1,0)));
    EXPECT_FALSE(b.pointIsInRange(Point(0,-1)));
    EXPECT_FALSE(b.pointIsInRange(Point(0,1)));
    EXPECT_FALSE(b.pointIsInRange(Point(1,0)));
    EXPECT_FALSE(b.pointIsInRange(Point(9,0)));
    EXPECT_FALSE(b.pointIsInRange(Point(0,9)));
    EXPECT_TRUE(b.pointIsInRange(Point(8,8)));
    EXPECT_TRUE(b.pointIsInRange(Point(1,1)));
    EXPECT_TRUE(b.pointIsInRange(Point(5,4)));
    EXPECT_TRUE(b.pointIsInRange(Point(1,8)));
    EXPECT_TRUE(b.pointIsInRange(Point(4,1)));
}

/*
 * test 2: check that numOfPlayerDisks function work correctly.
 */
TEST(BoardTest,countDisk){
    ConsoleBoard b =  ConsoleBoard(SIZE_ROW,SIZE_COL);
    EXPECT_TRUE(b.numOfPlayerDisks(b.blackActor) == 2);
    EXPECT_TRUE(b.numOfPlayerDisks(b.whiteActor) == 2);
    Board::disk** array =  b.getArray();
    array[1][1] = b.blackActor;
    array[4][7] = b.blackActor;
    array[8][8] = b.blackActor;
    array[2][3] = b.blackActor;
    array[4][6] = b.whiteActor;
    array[4][1] = b.whiteActor;
    array[1][6] = b.whiteActor;
    array[2][3] = b.whiteActor;
    EXPECT_TRUE(b.numOfPlayerDisks(b.blackActor) == 6);
    EXPECT_TRUE(b.numOfPlayerDisks(b.whiteActor) == 6);
}