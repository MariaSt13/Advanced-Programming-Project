#include <gtest/gtest.h>
#include "../AIPlayer.h"
#include "../StandardGameLogic.h"
#include "../Board.h"
#include "../HumanLocalPlayer.h"
#include "../ConsoleInterface.h"

#define ROW_SIZE 8
#define COL_SIZE 8
/*
 * Test 1: check for black 1 step at 3,4. white should play 3,3
 * then black playes 3,2. white should play 2,2.
 * to the opponent there are one or more valid moves.
 */
TEST(AIplayerTest, checkChooseCell1) {
    Board::disk  d = Board::whiteActor;
    StandardGameLogic l = StandardGameLogic();
    ConsoleInterface user = ConsoleInterface();
    Board b = Board(ROW_SIZE, COL_SIZE,&user);
    HumanLocalPlayer h = HumanLocalPlayer(b.blackActor);
    AIPlayer p = AIPlayer(d, &l, &b);
    Board::disk** array =  b.getArray();

    //black playes 3,4. white should play 3,3.
    l.flipCells(&h, Point(3,4),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(3,3));
    l.flipCells(&p, Point(3,3),&b,true);

    //black playes 3,2. white should play 2,2.
    l.flipCells(&h, Point(3,2),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(2,2));
    l.flipCells(&p, Point(2,2),&b,true);

    //black playes 4,3. white should play 4,2.
    l.flipCells(&h, Point(4,3),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(4,2));
    l.flipCells(&p, Point(4,2),&b,true);

    //black playes 1,1. white should play 3,5.
    l.flipCells(&h, Point(1,1),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(3,5));
    l.flipCells(&p, Point(3,5),&b,true);

    //black playes 5,6. white should play 6,5.
    l.flipCells(&h, Point(5,6),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(6,5));
    l.flipCells(&p, Point(6,5),&b,true);

    //black playes 6,6. white should play 6,7.
    l.flipCells(&h, Point(6,6),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(6,7));
    l.flipCells(&p, Point(6,7),&b,true);

    //black playes 7,7. white should play 8,8.
    l.flipCells(&h, Point(7,7),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(8,8));
    l.flipCells(&p, Point(8,8),&b,true);

    //black playes 5,2. white should play 3,1.
    l.flipCells(&h, Point(5,2),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(3,1));
    l.flipCells(&p, Point(3,1),&b,true);

    //black playes 4,6. white should play 3,6.
    l.flipCells(&h, Point(4,6),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(3,6));
    l.flipCells(&p, Point(3,6),&b,true);

    //black playes 6,4. white should play 5,3.
    l.flipCells(&h, Point(6,4),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(5,3));
    l.flipCells(&p, Point(5,3),&b,true);

    //black playes 6,8. white should play 6,1.
    l.flipCells(&h, Point(6,8),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(6,1));
    l.flipCells(&p, Point(6,1),&b,true);

    //black playes 2,4. white should play 7,6.
    l.flipCells(&h, Point(2,4),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(7,6));
    l.flipCells(&p, Point(7,6),&b,true);

    //black playes 8,5. white should play 1,4.
    l.flipCells(&h, Point(8,5),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(1,4));
    l.flipCells(&p, Point(1,4),&b,true);

    //black playes 6,2. white should play 6,3.
    l.flipCells(&h, Point(6,2),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(6,3));
    l.flipCells(&p, Point(6,3),&b,true);

    //black playes 7,8. white should play 1,2.
    l.flipCells(&h, Point(7,8),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(1,2));
    l.flipCells(&p, Point(1,2),&b,true);

}

/*
 * Test 2: check for black 1 step at 6,5. white should play 4,6
 * then black playes 3,3. white should play 4,3.
 * to the opponent there are one or more valid moves.
 */
TEST(AIplayerTest, checkChooseCell2) {
    Board::disk  d = Board::whiteActor;
    StandardGameLogic l = StandardGameLogic();
    ConsoleInterface user = ConsoleInterface();
    Board b = Board(ROW_SIZE, COL_SIZE,&user);
    HumanLocalPlayer h = HumanLocalPlayer(b.blackActor);
    Board::disk** array =  b.getArray();
    AIPlayer p = AIPlayer(d, &l, &b);

    //black playes 6,5. white should play 4,6.
    l.flipCells(&h, Point(6,5),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(4,6));
    l.flipCells(&p, Point(4,6),&b,true);

    //black playes 3,3. white should play 4,3.
    l.flipCells(&h, Point(3,3),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(4,3));
    l.flipCells(&p, Point(4,3),&b,true);

    //black playes 5,3. white should play 4,2.
    l.flipCells(&h, Point(5,3),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(4,2));
    l.flipCells(&p, Point(4,2),&b,true);

    //black playes 3,4. white should play 7,6.
    l.flipCells(&h, Point(3,4),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(7,6));
    l.flipCells(&p, Point(7,6),&b,true);

    //black playes 7,5. white should play 2,4.
    l.flipCells(&h, Point(7,5),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(2,4));
    l.flipCells(&p, Point(2,4),&b,true);

    //black playes 3,5. white should play 3,6.
    l.flipCells(&h, Point(3,5),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(3,6));
    l.flipCells(&p, Point(3,6),&b,true);

    //black playes 7,7. white should play 6,2.
    l.flipCells(&h, Point(7,7),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(6,2));
    l.flipCells(&p, Point(6,2),&b,true);

    //black playes 3,7. white should play 8,7.
    l.flipCells(&h, Point(3,7),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(8,7));
    l.flipCells(&p, Point(8,7),&b,true);

    //black playes 4,1. white should play 3,8.
    l.flipCells(&h, Point(4,1),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(3,8));
    l.flipCells(&p, Point(3,8),&b,true);

    //black playes 6,3. white should play 6,4.
    l.flipCells(&h, Point(6,3),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(6,4));
    l.flipCells(&p, Point(6,4),&b,true);

    //black playes 7,3. white should play 8,3.
    l.flipCells(&h, Point(7,3),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(8,3));
    l.flipCells(&p, Point(8,3),&b,true);

    //black playes 2,3. white should play 2,2.
    l.flipCells(&h, Point(2,3),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(2,2));
    l.flipCells(&p, Point(2,2),&b,true);

    //black playes 7,2. white should play 8,1.
    l.flipCells(&h, Point(7,2),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(8,1));
    l.flipCells(&p, Point(8,1),&b,true);

    //black playes 1,5. white should play 2,5.
    l.flipCells(&h, Point(1,5),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(2,5));
    l.flipCells(&p, Point(2,5),&b,true);

    //black playes 4,7. white should play 5,6.
    l.flipCells(&h, Point(4,7),&b,true);
    EXPECT_EQ(p.chooseStep(&user), Point(5,6));
    l.flipCells(&p, Point(5,6),&b,true);
}

/*
 * Test 3: check that the AIPlayer choose the
 * move that causes the opponent to have no legal moves.
 */
TEST(AIplayerTest, checkChooseCellBlackPlayerHasNoMoves) {
    Board::disk  d = Board::whiteActor;
    StandardGameLogic l = StandardGameLogic();
    ConsoleInterface user = ConsoleInterface();
    Board b = Board(ROW_SIZE, COL_SIZE,&user);
    HumanLocalPlayer h = HumanLocalPlayer(b.blackActor);
    Board::disk** array =  b.getArray();
    AIPlayer p = AIPlayer(d, &l, &b);

    for (int i = 1; i < b.getRowSize(); i++) {
        for (int j = 1; j < b.getColSize() ; j++) {
            array[i][j] = b.blackActor;
        }
    }

    array[7][1] = b.whiteActor;
    array[8][1] = b.whiteActor;
    array[7][8] =  b.empty;
    array[8][8] =  b.empty;

    EXPECT_EQ(p.chooseStep(&user), Point(8,8));

    for (int i = 1; i < b.getRowSize(); i++) {
        for (int j = 1; j < b.getColSize() ; j++) {
            array[i][j] = b.blackActor;
        }
    }

    array[3][4] = b.whiteActor;
    array[5][4] = b.whiteActor;
    array[1][5] = b.whiteActor;
    array[1][1] = b.whiteActor;
    array[5][5] = b.empty;
    array[4][5] = b.empty;
    array[5][6] = b.empty;
    EXPECT_EQ(p.chooseStep(&user), Point(4,5));
}