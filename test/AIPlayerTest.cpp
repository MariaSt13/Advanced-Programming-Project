#include <gtest/gtest.h>
#include "../AIPlayer.h"
#include "../StandardGameLogic.h"
#include "../ConsoleBoard.h"
#include "../HumanLocalPlayer.h"

#define ROW_SIZE 8
#define COL_SIZE 8
/*
 * Test 1: check for black 1 step at 3,4. white should play 3,3
 * then black playes 3,2. white should play 2,2.
 */
TEST(AIplayerTest, checkChoseCell1) {
    Board::disk  d = Board::whiteActor;
    StandardGameLogic l = StandardGameLogic();
    ConsoleBoard b = ConsoleBoard(ROW_SIZE, COL_SIZE);
    HumanLocalPlayer h = HumanLocalPlayer(b.blackActor);
    AIPlayer p = AIPlayer(d, &l, &b);
    Board::disk** array =  b.getArray();

    //black playes 3,4. white should play 3,3.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(3,4),&b);
    EXPECT_EQ(p.chooseStep(), Point(3,3));
    l.flipCells(&p, Point(3,3),&b);

    //black playes 3,2. white should play 2,2.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(3,2),&b);
    EXPECT_EQ(p.chooseStep(), Point(2,2));
    l.flipCells(&p, Point(2,2),&b);

    //black playes 4,3. white should play 4,2.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(4,3),&b);
    EXPECT_EQ(p.chooseStep(), Point(4,2));
    l.flipCells(&p, Point(4,2),&b);

    //black playes 1,1. white should play 3,5.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(1,1),&b);
    EXPECT_EQ(p.chooseStep(), Point(3,5));
    l.flipCells(&p, Point(3,5),&b);

    //black playes 5,6. white should play 6,5.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(5,6),&b);
    EXPECT_EQ(p.chooseStep(), Point(6,5));
    l.flipCells(&p, Point(6,5),&b);

    //black playes 6,6. white should play 6,7.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(6,6),&b);
    EXPECT_EQ(p.chooseStep(), Point(6,7));
    l.flipCells(&p, Point(6,7),&b);

    //black playes 7,7. white should play 8,8.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(7,7),&b);
    EXPECT_EQ(p.chooseStep(), Point(8,8));
    l.flipCells(&p, Point(8,8),&b);

    //black playes 5,2. white should play 3,1.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(5,2),&b);
    EXPECT_EQ(p.chooseStep(), Point(3,1));
    l.flipCells(&p, Point(3,1),&b);

    //black playes 4,6. white should play 3,6.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(4,6),&b);
    EXPECT_EQ(p.chooseStep(), Point(3,6));
    l.flipCells(&p, Point(3,6),&b);

    //black playes 6,4. white should play 5,3.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(6,4),&b);
    EXPECT_EQ(p.chooseStep(), Point(5,3));
    l.flipCells(&p, Point(5,3),&b);

    //black playes 6,8. white should play 6,1.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(6,8),&b);
    EXPECT_EQ(p.chooseStep(), Point(6,1));
    l.flipCells(&p, Point(6,1),&b);

    //black playes 2,4. white should play 2,4.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(2,4),&b);
    EXPECT_EQ(p.chooseStep(), Point(7,6));
    l.flipCells(&p, Point(7,6),&b);

    //black playes 8,5. white should play 1,4.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(8,5),&b);
    EXPECT_EQ(p.chooseStep(), Point(1,4));
    l.flipCells(&p, Point(1,4),&b);

    //black playes 6,2. white should play 6,3.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(6,2),&b);
    EXPECT_EQ(p.chooseStep(), Point(6,3));
    l.flipCells(&p, Point(6,3),&b);

    //black playes 7,8. white should play 1,2.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(7,8),&b);
    EXPECT_EQ(p.chooseStep(), Point(1,2));
    l.flipCells(&p, Point(1,2),&b);

}

/*
 * Test 2: check for black 1 step at 6,5. white should play 4,6
 * then black playes 3,3. white should play 4,3.
 */
TEST(AIplayerTest, checkChoseCell2) {
    Board::disk  d = Board::whiteActor;
    StandardGameLogic l = StandardGameLogic();
    ConsoleBoard b = ConsoleBoard(ROW_SIZE, COL_SIZE);
    HumanLocalPlayer h = HumanLocalPlayer(b.blackActor);
    Board::disk** array =  b.getArray();
    AIPlayer p = AIPlayer(d, &l, &b);

    //black playes 6,5. white should play 4,6.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(6,5),&b);
    EXPECT_EQ(p.chooseStep(), Point(4,6));
    l.flipCells(&p, Point(4,6),&b);

    //black playes 3,3. white should play 4,3.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(3,3),&b);
    EXPECT_EQ(p.chooseStep(), Point(4,3));
    l.flipCells(&p, Point(4,3),&b);

    //black playes 5,3. white should play 4,2.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(5,3),&b);
    EXPECT_EQ(p.chooseStep(), Point(4,2));
    l.flipCells(&p, Point(4,2),&b);

    //black playes 3,4. white should play 7,6.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(3,4),&b);
    EXPECT_EQ(p.chooseStep(), Point(7,6));
    l.flipCells(&p, Point(7,6),&b);

    //black playes 7,5. white should play 2,4.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(7,5),&b);
    EXPECT_EQ(p.chooseStep(), Point(2,4));
    l.flipCells(&p, Point(2,4),&b);

    //black playes 3,5. white should play 3,6.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(3,5),&b);
    EXPECT_EQ(p.chooseStep(), Point(3,6));
    l.flipCells(&p, Point(3,6),&b);

    //black playes 7,7. white should play 6,2.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(7,7),&b);
    EXPECT_EQ(p.chooseStep(), Point(6,2));
    l.flipCells(&p, Point(6,2),&b);

    //black playes 3,7. white should play 8,7.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(3,7),&b);
    EXPECT_EQ(p.chooseStep(), Point(8,7));
    l.flipCells(&p, Point(8,7),&b);

    //black playes 4,1. white should play 3,8.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(4,1),&b);
    EXPECT_EQ(p.chooseStep(), Point(3,8));
    l.flipCells(&p, Point(3,8),&b);

    //black playes 6,3. white should play 6,4.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(6,3),&b);
    EXPECT_EQ(p.chooseStep(), Point(6,4));
    l.flipCells(&p, Point(6,4),&b);

    //black playes 7,3. white should play 8,3.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(7,3),&b);
    EXPECT_EQ(p.chooseStep(), Point(8,3));
    l.flipCells(&p, Point(8,3),&b);

    //black playes 2,3. white should play 2,2.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(2,3),&b);
    EXPECT_EQ(p.chooseStep(), Point(2,2));
    l.flipCells(&p, Point(2,2),&b);

    //black playes 7,2. white should play 8,1.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(7,2),&b);
    EXPECT_EQ(p.chooseStep(), Point(8,1));
    l.flipCells(&p, Point(8,1),&b);

    //black playes 1,5. white should play 2,5.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(1,5),&b);
    EXPECT_EQ(p.chooseStep(), Point(2,5));
    l.flipCells(&p, Point(2,5),&b);

    //black playes 4,7. white should play 5,6.
    l.returnValidMoves(&h,&b);
    l.flipCells(&h, Point(4,7),&b);
    EXPECT_EQ(p.chooseStep(), Point(5,6));
    l.flipCells(&p, Point(5,6),&b);
}