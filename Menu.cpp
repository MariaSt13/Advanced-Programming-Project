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
    int chosenMode = 0;
    cin >> chosenMode;
    while (chosenMode != 1 && chosenMode != 2) {
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
    Board* b =  new ConsoleBoard(8,8);
    Player* blackActor;
    Player* whiteActor;
    GameLogic* standardGameLogic = new StandardGameLogic();
    if ( mode == 1) {
        blackActor = new HumanLocalPlayer(b->blackActor);
        whiteActor = new HumanLocalPlayer(b->whitekActor);
    } else if ( mode == 2) {
        blackActor = new HumanLocalPlayer(b->blackActor);
        whiteActor = new AIPlayer(b->whitekActor,standardGameLogic, b);
    }
    ReversiGame game = ReversiGame(b,blackActor,whiteActor,standardGameLogic);

    //free memory
    delete(b);
    delete(blackActor);
    delete(whiteActor);
    delete(standardGameLogic);
}