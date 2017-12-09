
#include <iostream>
#include <limits>
#include <cstdlib>
#include "Menu.h"
#include "ConsoleBoard.h"
#include "HumanLocalPlayer.h"
#include "StandardGameLogic.h"
#include "AIPlayer.h"
#include "ReversiGame.h"
#include "RemotePlayer.h"
#include "ReadDefinitionFile.h"

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
    while (chosenMode != ReversiGame::humanAgainsHuman && chosenMode !=  ReversiGame::humanAgainstAI && chosenMode != ReversiGame::remoteGame) {
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

    ReadDefinitionFile read = ReadDefinitionFile();
    map<string,string> myMap = read.getVectorDefinition();
    string ip = myMap.find("ip")->second;
    int port;
    istringstream isX (myMap.find("port")->second);
    isX >> port;
    ConnectToServer client(ip.c_str(),port);


    Player* humanPlayer;
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
        currentMode = ReversiGame::remoteGame;
        try {
            client.connectToServer();
        } catch (const char *msg) {
            cout << "Failed to connect to server. Reason:" << msg << endl;
            exit(-1);
        }
        int color = client.readTypeOfPlayer();
        // This player connected first so he is black
        if (color == 1) {
            blackActor = new HumanLocalPlayer(b->blackActor);
            whiteActor = new RemotePlayer(b->whiteActor, client.getClientSocket());
            humanPlayer = blackActor;
        } else if (color == 2) { // this player connected second so he is white
            whiteActor = new HumanLocalPlayer(b->whiteActor);
            blackActor = new RemotePlayer(b->blackActor, client.getClientSocket());
            humanPlayer = whiteActor;
        }
    }

    ReversiGame game = ReversiGame(b, blackActor, whiteActor, standardGameLogic, currentMode, client,humanPlayer);

    //free memory
    delete(b);
    delete(blackActor);
    delete(whiteActor);
    delete(standardGameLogic);
    delete(standardGameLogic2);
}