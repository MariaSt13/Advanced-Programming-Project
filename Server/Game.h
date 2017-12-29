//
// Created by linoy on 28/12/17.
//

#ifndef EX4_GAME_H
#define EX4_GAME_H

#include <string>
using namespace std;


class Game {
public:
    //constructor
    Game(string name,int socketFirstPLayer);

    //join second player to game
    void joinToGame(int socketPLayer);

    const string getName()const;

    void setRun(bool run);

    const int getSocketFirstPLayer()const;

    const int getSocketSecondPLayer()const;

    bool isRun() const;

private:
    bool run;
    string name;
    int socketFirstPLayer;
    int socketSecondPLayer;
};


#endif //EX4_GAME_H
