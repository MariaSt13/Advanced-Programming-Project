#include <gtest/gtest.h>
#include "../AIPlayer.h"
#include "../StandardGameLogic.h"
#include "../ConsoleBoard.h"
#include "../HumanLocalPlayer.h"

#define ROW_SIZE 8
#define COL_SIZE 8

TEST(AIplayerTest, checkChoseCell) {
    Board::disk  d = Board::whiteActor;
    StandardGameLogic l = StandardGameLogic();
    ConsoleBoard b = ConsoleBoard(ROW_SIZE, COL_SIZE);
    HumanLocalPlayer h = HumanLocalPlayer(b.blackActor);
    Board::disk** array =  b.getArray();
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(3,4),&b);
    AIPlayer p = AIPlayer(d, &l, &b);
    EXPECT_EQ(p.chooseStep(), Point(3,3));

}