#include <gtest/gtest.h>
#include "../AIPlayer.h"
#include "../StandardGameLogic.h"
#include "../ConsoleBoard.h"
#include "../HumanLocalPlayer.h"

#define ROW_SIZE 8
#define COL_SIZE 8
/*
 * Test 1: check for black 1 step at 3,4. white should play 3,3
 * then black playes 3,2. white shouldplay 2,2.
 */
TEST(AIplayerTest, checkChoseCell1) {
    Board::disk  d = Board::whiteActor;
    StandardGameLogic l = StandardGameLogic();
    ConsoleBoard b = ConsoleBoard(ROW_SIZE, COL_SIZE);
    HumanLocalPlayer h = HumanLocalPlayer(b.blackActor);
    Board::disk** array =  b.getArray();
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(3,4),&b);
    AIPlayer p = AIPlayer(d, &l, &b);
    EXPECT_EQ(p.chooseStep(), Point(3,3));
    l.flipCells(&p, Point(3,3),&b);
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(3,2),&b);
    EXPECT_EQ(p.chooseStep(), Point(2,2));

}

/*
 * Test 2: check for black 1 step at 6,5. white should play 4,6
 * then black playes 3,3. white shouldplay 4,3.
 */
TEST(AIplayerTest, checkChoseCell2) {
    Board::disk  d = Board::whiteActor;
    StandardGameLogic l = StandardGameLogic();
    ConsoleBoard b = ConsoleBoard(ROW_SIZE, COL_SIZE);
    HumanLocalPlayer h = HumanLocalPlayer(b.blackActor);
    Board::disk** array =  b.getArray();
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(6,5),&b);
    AIPlayer p = AIPlayer(d, &l, &b);
    EXPECT_EQ(p.chooseStep(), Point(4,6));
    l.flipCells(&p, Point(4,6),&b);
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(3,3),&b);
    EXPECT_EQ(p.chooseStep(), Point(4,3));
}