
#include "ConsoleBoardTest.h"
#include <gtest/gtest.h>
#include "../ConsoleBoard.h"

/*
 * test 1: check that copy constructor work correctly.
 */
TEST(BoardTest,copyConstuctorTest){
    ConsoleBoardTest test = ConsoleBoardTest();
    ConsoleBoard b =  ConsoleBoard(SIZE_ROW_STANDARD,SIZE_COL_STANDARD);
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
 * test 2: check that copy constructor work correctly
 * on small board.
 */
TEST(BoardTest,copyConstuctorSmallBoardTest){
    ConsoleBoardTest test = ConsoleBoardTest();
    ConsoleBoard b =  ConsoleBoard(SIZE_ROW_SMALL,SIZE_COL_SMALL);
    Board::disk** array =  b.getArray();
    array[1][1] = b.blackActor;
    array[3][3] = b.blackActor;
    array[2][1] = b.blackActor;
    array[2][2] = b.blackActor;

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
 * test 3: check that fullBoard function work correctly.
 */
TEST(BoardTest,fullBoardTest){
    ConsoleBoardTest test = ConsoleBoardTest();
    ConsoleBoard b =  ConsoleBoard(SIZE_ROW_STANDARD,SIZE_COL_STANDARD);
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
 * test 4: check that fullBoard function work correctly
 * on small board.
 */
TEST(BoardTest,fullBoardSmallTest){
    ConsoleBoardTest test = ConsoleBoardTest();
    ConsoleBoard b =  ConsoleBoard(SIZE_ROW_SMALL,SIZE_COL_SMALL);
    Board::disk** array =  b.getArray();

    //full board
    test.fullBoard(b,b.blackActor);

    EXPECT_TRUE(b.ifBoardIsFull());
    array[3][3] = b.empty;
    EXPECT_FALSE(b.ifBoardIsFull());
    array[3][3] = b.whiteActor;
    EXPECT_TRUE(b.ifBoardIsFull());

    //empty board.
    test.fullBoard(b,b.empty);

    EXPECT_FALSE(b.ifBoardIsFull());
    array[2][2] = b.whiteActor;
    EXPECT_FALSE(b.ifBoardIsFull());
}


/*
 * test 5: check that pointIsInRange function work correctly.
 */
TEST(BoardTest,BoardLimitsTest){
    ConsoleBoard b =  ConsoleBoard(SIZE_ROW_STANDARD,SIZE_COL_STANDARD);
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
 * test 6: check that pointIsInRange function work correctly.
 */
TEST(BoardTest,BoardLimitsSmallBoardTest){
    ConsoleBoard b =  ConsoleBoard(SIZE_ROW_SMALL,SIZE_COL_SMALL);
    EXPECT_FALSE(b.pointIsInRange(Point(-1,-1)));
    EXPECT_FALSE(b.pointIsInRange(Point(4,4)));
    EXPECT_FALSE(b.pointIsInRange(Point(-7,-5)));
    EXPECT_FALSE(b.pointIsInRange(Point(-1,0)));
    EXPECT_FALSE(b.pointIsInRange(Point(0,-1)));
    EXPECT_FALSE(b.pointIsInRange(Point(0,1)));
    EXPECT_FALSE(b.pointIsInRange(Point(1,0)));
    EXPECT_FALSE(b.pointIsInRange(Point(3,0)));
    EXPECT_FALSE(b.pointIsInRange(Point(0,9)));
    EXPECT_FALSE(b.pointIsInRange(Point(4,3)));
    EXPECT_FALSE(b.pointIsInRange(Point(3,-5)));
    EXPECT_FALSE(b.pointIsInRange(Point(0,0)));
    EXPECT_FALSE(b.pointIsInRange(Point(-3,3)));
    EXPECT_FALSE(b.pointIsInRange(Point(3,-1)));
    EXPECT_FALSE(b.pointIsInRange(Point(-1,3)));
    EXPECT_FALSE(b.pointIsInRange(Point(3,4)));

    //check all the points in the board.
    for (int i = 1; i < b.getRowSize(); i++) {
        for (int j = 1; j < b.getColSize() ; j++) {
            EXPECT_TRUE(b.pointIsInRange(Point(i,j)));
        }
    }
}


/*
 * test 7: check that numOfPlayerDisks function work correctly.
 */
TEST(BoardTest,countDiskTest){
    ConsoleBoardTest test = ConsoleBoardTest();
    ConsoleBoard b =  ConsoleBoard(SIZE_ROW_STANDARD,SIZE_COL_STANDARD);
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


/*
 * test 8: check that numOfPlayerDisks function work correctly
 * on small board.
 */
TEST(BoardTest,countDiskSmallBoardTest){
    ConsoleBoardTest test = ConsoleBoardTest();
    ConsoleBoard b =  ConsoleBoard(SIZE_ROW_SMALL,SIZE_ROW_SMALL);
    EXPECT_TRUE(b.numOfPlayerDisks(b.blackActor) == 2);
    EXPECT_TRUE(b.numOfPlayerDisks(b.whiteActor) == 2);
    Board::disk** array =  b.getArray();
    array[1][1] = b.blackActor;
    EXPECT_TRUE(b.numOfPlayerDisks(b.blackActor) == 3);
    array[3][3] = b.blackActor;
    array[1][3] = b.blackActor;
    array[1][2] = b.whiteActor;
    array[2][2] = b.whiteActor;
    EXPECT_TRUE(b.numOfPlayerDisks(b.blackActor) == 5);
    EXPECT_TRUE(b.numOfPlayerDisks(b.whiteActor) == 2);

    //full board
    test.fullBoard(b,b.blackActor);

    EXPECT_TRUE(b.numOfPlayerDisks(b.blackActor) == 9);
    EXPECT_TRUE(b.numOfPlayerDisks(b.whiteActor) == 0);

    //empty board
    test.fullBoard(b,b.empty);
    EXPECT_TRUE(b.numOfPlayerDisks(b.blackActor) == 0);
    EXPECT_TRUE(b.numOfPlayerDisks(b.whiteActor) == 0);
}

/**
 * full all the board cells.
 * @param b board.
 * @param d disk.
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