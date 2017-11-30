
#ifndef EXAM1_CONSOLEBOARDTEST_H
#define EXAM1_CONSOLEBOARDTEST_H
#include <gtest/gtest.h>
#include "../ConsoleBoard.h"

#define SIZE_ROW_STANDARD 8
#define SIZE_COL_STANDARD 8
#define SIZE_ROW_SMALL 3
#define SIZE_COL_SMALL 3

class ConsoleBoardTest {
public:
    void fullBoard(ConsoleBoard &b,Board::disk d);
};


#endif //EXAM1_BOARDTEST_H
