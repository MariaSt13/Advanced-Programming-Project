//
// Created by maria on 28/11/17.
//

#include <iostream>
#include <limits>
#include "Menu.h"
#include "ConsoleBoard.h"
#include "HumanLocalPlayer.h"
#include "StandardGameLogic.h"
#include "AIPlayer.h"
#include "ReversiGame.h"

using namespace std;

Menu::Menu() {
    runMenu();
}
void Menu::runMenu() {
    cout << "Please choose game mode:" << endl;
    cout << "(1) Human player" << endl;
    cout << "(2) AI player" << endl;

    int chosenMode =  ReversiGame::noMode;
    cin >> chosenMode;
    while (chosenMode != ReversiGame::humanAgainsHuman && chosenMode !=  ReversiGame::humanAgainstAI) {
        if(cin.fail()) {
            cout << " invalid input. Please try again" << endl;
            // get rid of failure state
            cin.clear();

            // discard 'bad' character(s)
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cout << " invalid input. Please try again" << endl;
        }
        cin >> chosenMode;
    }
    runGame(chosenMode);

}
void Menu::runGame(int mode) {
    Board* b =  new ConsoleBoard(3,3);
    Player* blackActor;
    Player* whiteActor;
    ReversiGame::mode currentMode;
    GameLogic* standardGameLogic = new StandardGameLogic();
    if ( mode == ReversiGame::humanAgainsHuman) {
        blackActor = new HumanLocalPlayer(b->blackActor);
        whiteActor = new HumanLocalPlayer(b->whitekActor);
        currentMode = ReversiGame::humanAgainsHuman;
    } else if ( mode == ReversiGame::humanAgainstAI) {
        blackActor = new HumanLocalPlayer(b->blackActor);
        GameLogic* standardGameLogic2 = new StandardGameLogic();
        whiteActor = new AIPlayer(b->whitekActor,standardGameLogic2, b);
        currentMode = ReversiGame::humanAgainstAI;
    }
    ReversiGame game = ReversiGame(b,blackActor,whiteActor,standardGameLogic,currentMode);

    //free memory
    delete(b);
    delete(blackActor);
    delete(whiteActor);
    delete(standardGameLogic);
}