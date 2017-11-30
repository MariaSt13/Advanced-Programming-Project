
#ifndef EXAM1_CONSOLEBOARDTEST_H
#define EXAM1_CONSOLEBOARDTEST_H
#include <gtest/gtest.h>
#include "../ConsoleBoard.h"

#define SIZE_ROW 8
#define SIZE_COL 8

class ConsoleBoardTest {
public:
    void fullBoard(ConsoleBoard &b,Board::disk d);
};


#endif //EXAM1_BOARDTEST_H
