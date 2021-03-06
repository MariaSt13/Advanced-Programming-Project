#include <iostream>
#include "Menu.h"
#include "HumanLocalPlayer.h"
#include "StandardGameLogic.h"
#include "AIPlayer.h"
#include "ReversiGame.h"
#include "RemotePlayer.h"
#include "ReadDefinitionFile.h"
#include "CommandMenu.h"
using namespace std;
/*
 * constructor. runs the menu of the game.
 * rows - number of rows in the board game.
 * cols - number of columns in the board game.
 */
Menu::Menu(const int &rows,const int &cols, UserInterface* userInterface): rowNumber(rows), colNumber(cols), userInterface(userInterface){
    runMenu();
}
/*
 * runs the menu. show it and get the player choise.
 */
void Menu::runMenu()const{
    // print menu
    userInterface->mainMenu();

    // mode of the game
    int chosenMode = userInterface->chooseMode();
    while (chosenMode != ReversiGame::humanAgainstHuman && chosenMode !=  ReversiGame::humanAgainstAI &&
           chosenMode != ReversiGame::remoteGame) {
        userInterface->wrongMode();
        chosenMode = userInterface->chooseMode();
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
    Board* b =  new Board(rowNumber, colNumber,userInterface);
    Player* blackActor;
    Player* whiteActor;
    ReversiGame::mode currentMode;
    GameLogic* standardGameLogic = new StandardGameLogic();
    GameLogic* standardGameLogic2 = new StandardGameLogic();

    //get port and ip number and create client object.
    ReadDefinitionFile read = ReadDefinitionFile();
    map<string,string> myMap;

    myMap = read.getVectorDefinition("clientDefinitionFile.txt");

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
            int color;
            try {
                currentMode = ReversiGame::remoteGame;

                CommandMenu menu = CommandMenu(userInterface, &client);
                menu.runMenu();

                color = client.readTypeOfPlayer();
            }catch(char const* msg){
                //free memory
                delete(b);
                delete(standardGameLogic);
                delete(standardGameLogic2);
                return;
            }

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
        try {
            ReversiGame(b, blackActor, whiteActor, standardGameLogic, currentMode, client, humanPlayer, userInterface);
        }catch (char const* msg) {
        cout << "Error:" << msg << endl;
        //free memory
        delete(b);
        delete(blackActor);
        delete(whiteActor);
        delete(standardGameLogic);
        delete(standardGameLogic2);
        return;
    }

    //free memory
    delete(b);
    delete(blackActor);
    delete(whiteActor);
    delete(standardGameLogic);
    delete(standardGameLogic2);
}