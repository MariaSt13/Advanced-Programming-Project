//name: linoy cohen
//ID: 206333502

#include <iostream>
#include "Board.h"
#include "ConsoleBoard.h"
#include "HumanLocalPlayer.h"
#include "GameLogic.h"
#include "StandardGameLogic.h"
#include "ReversiGame.h"
using namespace std;

int main() {

    //create a new game.
    Board* b =  new ConsoleBoard(8,8);
    Player* blackActor = new HumanLocalPlayer(b->blackActor);
    Player* whiteActor = new HumanLocalPlayer(b->whitekActor);
    GameLogic* standardGameLogic = new StandardGameLogic();
    ReversiGame game = ReversiGame(b,blackActor,whiteActor,standardGameLogic);

    //free memory
    delete(b);
    delete(blackActor);
    delete(whiteActor);
    delete(standardGameLogic);
    return 0;
}