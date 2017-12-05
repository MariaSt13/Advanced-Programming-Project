
#include <iostream>
#include <limits>
#include "Menu.h"
#include "ConsoleBoard.h"
#include "HumanLocalPlayer.h"
#include "StandardGameLogic.h"
#include "AIPlayer.h"
#include "ReversiGame.h"

using namespace std;
/*
 * constructor. runs the menu of the game.
 * rows - number of rows in the board game.
 * cols - number of columns in the board game.
 */
Menu::Menu(const int &rows,const int &cols): rowNumber(rows), colNumber(cols){
    runMenu();
}
/*
 * runs the menu. show it and get the player choise.
 */
void Menu::runMenu(){
    // print menu
    cout << "Please choose game mode:" << endl;
    cout << "(1) Human player" << endl;
    cout << "(2) AI player" << endl;
    cout << "(3) Remote player" << endl;

    // mode of the game
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
/*
 * runs the game by the mode choise.
 * mode - the number of the mode chosen.
 */
void Menu::runGame(const int &mode) {
    Board* b =  new ConsoleBoard(rowNumber, colNumber);
    Player* blackActor;
    Player* whiteActor;
    ReversiGame::mode currentMode;
    GameLogic* standardGameLogic = new StandardGameLogic();
    GameLogic* standardGameLogic2 = new StandardGameLogic();

    if ( mode == ReversiGame::humanAgainsHuman) {
        blackActor = new HumanLocalPlayer(b->blackActor);
        whiteActor = new HumanLocalPlayer(b->whiteActor);
        currentMode = ReversiGame::humanAgainsHuman;
    } else if ( mode == ReversiGame::humanAgainstAI) {
        blackActor = new HumanLocalPlayer(b->blackActor);
        // send a copy of the logic to the AI player.
        whiteActor = new AIPlayer(b->whiteActor,standardGameLogic2, b);
        currentMode = ReversiGame::humanAgainstAI;
    } else if(mode == ReversiGame::remoteGame) {

    }
    ReversiGame game = ReversiGame(b,blackActor,whiteActor,standardGameLogic,currentMode);

    //free memory
    delete(b);
    delete(blackActor);
    delete(whiteActor);
    delete(standardGameLogic);
    delete(standardGameLogic2);
}