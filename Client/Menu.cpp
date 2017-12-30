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
#include "ConsoleDisplay.h"
#include "CommandMenu.h"
using namespace std;
/*
 * constructor. runs the menu of the game.
 * rows - number of rows in the board game.
 * cols - number of columns in the board game.
 */
Menu::Menu(const int &rows,const int &cols, Display* display): rowNumber(rows), colNumber(cols), display(display){
    runMenu();
}
/*
 * runs the menu. show it and get the player choise.
 */
void Menu::runMenu()const{
    // print menu
    display->mainMenu();

    // mode of the game
    int chosenMode =  ReversiGame::noMode;
    cin >> chosenMode;
    while (chosenMode != ReversiGame::humanAgainstHuman && chosenMode !=  ReversiGame::humanAgainstAI && chosenMode != ReversiGame::remoteGame) {
        if(cin.fail()) {
            display->invalidTryAgain();
            // get rid of failure state
            cin.clear();

            // discard 'bad' character(s)
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            display->invalidTryAgain();
        }
        cin >> chosenMode;
    }
    runGame(chosenMode);

}
/*
 * runs the game by the mode choice.
 * mode - the number of the mode chosen.
 */
void Menu::runGame(const int &mode)const {
    const int connectedFirst = 1;
    const int connectedSecond = 2;
    Board* b =  new ConsoleBoard(rowNumber, colNumber);
    Player* blackActor;
    Player* whiteActor;
    ReversiGame::mode currentMode;
    GameLogic* standardGameLogic = new StandardGameLogic();
    GameLogic* standardGameLogic2 = new StandardGameLogic();

    //get port and ip number and create client object.
    ReadDefinitionFile read = ReadDefinitionFile();
    map<string,string> myMap;
    try{
        myMap = read.getVectorDefinition("/home/linoy/Desktop/myGIt/Advanced-Programming-Project/Client/clientDefinitionFile.txt");
    }
    catch (char const* msg){
        cout << "Failed to file. Reason:" << msg << endl;
        exit(1);
    }
    string ip = myMap.find("ip")->second;
    int port;
    istringstream isX (myMap.find("port")->second);
    isX >> port;
    Client client(ip.c_str(),port);


    Board::disk humanPlayer;

    switch(mode){

        case ReversiGame::humanAgainstHuman:
            blackActor = new HumanLocalPlayer(b->blackActor);
            whiteActor = new HumanLocalPlayer(b->whiteActor);
            currentMode = ReversiGame::humanAgainstHuman;
            break;

        case ReversiGame::humanAgainstAI:
            blackActor = new HumanLocalPlayer(b->blackActor);
            // send a copy of the logic to the AI player.
            whiteActor = new AIPlayer(b->whiteActor,standardGameLogic2, b);
            currentMode = ReversiGame::humanAgainstAI;
            break;

        case ReversiGame::remoteGame:
            currentMode = ReversiGame::remoteGame;

            //connect to server
            try {
                client.connectToServer();
            } catch (char const* msg) {
                cout << "Failed to connect to server. Reason:" << msg << endl;
                exit(1);
            }

            CommandMenu menu = CommandMenu(display);
            menu.runMenu(client.getClientSocket());

            int color = client.readTypeOfPlayer();

            // This player connected first so he is black
            if (color == connectedFirst) {
                blackActor = new HumanLocalPlayer(b->blackActor);
                whiteActor = new RemotePlayer(b->whiteActor, client);
                humanPlayer = b->blackActor;

                // this player connected second so he is white
            } else if (color == connectedSecond) {
                whiteActor = new HumanLocalPlayer(b->whiteActor);
                blackActor = new RemotePlayer(b->blackActor, client);
                humanPlayer = b->whiteActor;
            }
            break;
    }
    ReversiGame(b, blackActor, whiteActor, standardGameLogic, currentMode, client,humanPlayer, display);

    //free memory
    delete(b);
    delete(blackActor);
    delete(whiteActor);
    delete(standardGameLogic);
    delete(standardGameLogic2);
}