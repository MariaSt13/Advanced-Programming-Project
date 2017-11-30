
#include "ConsoleBoardTest.h"
#include <gtest/gtest.h>
#include "../ConsoleBoard.h"

/*
 * test 1: check that copy constructor work correctly.
 */
TEST(BoardTest,copyConstuctor){
    ConsoleBoardTest test = ConsoleBoardTest();
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

    ConsoleBoard copyBoard =  ConsoleBoard(&b);
    Board::disk** copyBoardArr =  copyBoard.getArray();
    //compare
    for (int i = 0; i < b.getRowSize(); i++) {
        for (int j = 0; j < b.getColSize() ; j++) {
            EXPECT_TRUE(array[i][j] == copyBoardArr[i][j]);
        }
    }

    //empty board
    test.fullBoard(b,b.empty);


    ConsoleBoard copyBoard2 =  ConsoleBoard(&b);
    Board::disk** copyBoardArr2 =  copyBoard2.getArray();

    //compare
    for (int i = 0; i < b.getRowSize(); i++) {
        for (int j = 0; j < b.getColSize() ; j++) {
            EXPECT_TRUE(array[i][j] == copyBoardArr2[i][j]);
        }
    }

}

/*
 * test 2: check that fullBoard function work correctly.
 */
TEST(BoardTest,fullBoard){
    ConsoleBoardTest test = ConsoleBoardTest();
    ConsoleBoard b =  ConsoleBoard(SIZE_ROW,SIZE_COL);
    Board::disk** array =  b.getArray();

    //full board
    test.fullBoard(b,b.blackActor);

    EXPECT_TRUE(b.ifBoardIsFull());
    array[5][4] = b.empty;
    EXPECT_FALSE(b.ifBoardIsFull());
    array[5][4] = b.whiteActor;
    EXPECT_TRUE(b.ifBoardIsFull());

    //empty board.
    test.fullBoard(b,b.empty);

    EXPECT_FALSE(b.ifBoardIsFull());
    array[8][4] = b.whiteActor;
    EXPECT_FALSE(b.ifBoardIsFull());
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
    EXPECT_FALSE(b.pointIsInRange(Point(10,10)));
    EXPECT_FALSE(b.pointIsInRange(Point(9,-5)));
    EXPECT_FALSE(b.pointIsInRange(Point(0,0)));
    EXPECT_FALSE(b.pointIsInRange(Point(8,9)));
    EXPECT_FALSE(b.pointIsInRange(Point(8,-1)));
    EXPECT_FALSE(b.pointIsInRange(Point(-1,8)));
    EXPECT_FALSE(b.pointIsInRange(Point(9,9)));
    EXPECT_FALSE(b.pointIsInRange(Point(9,8)));
    EXPECT_FALSE(b.pointIsInRange(Point(-8,-6)));

    //check all the points in the board.
    for (int i = 1; i < b.getRowSize(); i++) {
        for (int j = 1; j < b.getColSize() ; j++) {
            EXPECT_TRUE(b.pointIsInRange(Point(i,j)));
        }
    }
}

/*
 * test 2: check that numOfPlayerDisks function work correctly.
 */
TEST(BoardTest,countDisk){
    ConsoleBoardTest test = ConsoleBoardTest();
    ConsoleBoard b =  ConsoleBoard(SIZE_ROW,SIZE_COL);
    EXPECT_TRUE(b.numOfPlayerDisks(b.blackActor) == 2);
    EXPECT_TRUE(b.numOfPlayerDisks(b.whiteActor) == 2);
    Board::disk** array =  b.getArray();
    array[1][1] = b.blackActor;
    array[4][7] = b.blackActor;
    EXPECT_TRUE(b.numOfPlayerDisks(b.blackActor) == 4);
    EXPECT_TRUE(b.numOfPlayerDisks(b.whiteActor) == 2);
    array[8][8] = b.blackActor;
    array[2][3] = b.blackActor;
    array[4][6] = b.whiteActor;
    array[4][1] = b.whiteActor;
    array[1][6] = b.whiteActor;
    array[2][2] = b.whiteActor;
    EXPECT_TRUE(b.numOfPlayerDisks(b.blackActor) == 6);
    EXPECT_TRUE(b.numOfPlayerDisks(b.whiteActor) == 6);

    //full board
    test.fullBoard(b,b.blackActor);

    EXPECT_TRUE(b.numOfPlayerDisks(b.blackActor) == 64);
    EXPECT_TRUE(b.numOfPlayerDisks(b.whiteActor) == 0);

    //empty board
    test.fullBoard(b,b.empty);
    EXPECT_TRUE(b.numOfPlayerDisks(b.blackActor) == 0);
    EXPECT_TRUE(b.numOfPlayerDisks(b.whiteActor) == 0);
}

/**
 * full all the board cells.
 * @param b
 * @param d
 */
void ConsoleBoardTest:: fullBoard(ConsoleBoard &b,Board::disk d){
    Board::disk** array =  b.getArray();
    //empty board.
    for (int i = 1; i < b.getRowSize(); i++) {
        for (int j = 1; j < b.getColSize() ; j++) {
            array[i][j] = d;
        }
    }
}