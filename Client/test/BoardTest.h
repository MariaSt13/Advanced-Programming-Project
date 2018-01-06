
#ifndef EXAM1_BoardTEST_H
#define EXAM1_BoardTEST_H
#include <gtest/gtest.h>
#include "../Board.h"

#define SIZE_ROW_STANDARD 8
#define SIZE_COL_STANDARD 8
#define SIZE_ROW_SMALL 3
#define SIZE_COL_SMALL 3

class BoardTest {
public:
    void fullBoard(Board &b,Board::disk d);
};


#endif //EXAM1_BOARDTEST_H
