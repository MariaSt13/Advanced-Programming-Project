//
// Created by linoy on 28/12/17.
//

#ifndef EX4_GAME_H
#define EX4_GAME_H

#include <string>
using namespace std;


class Game {
public:
    enum status {waiting, running, finished};
    //constructor
    Game(string name,int socketFirstPLayer);

    //join second player to game
    void joinToGame(int socketPLayer);

    const string getName()const;

    void setStatus(status s);

    const int getSocketFirstPLayer()const;

    const int getSocketSecondPLayer()const;

    status getStatus() const;

private:
    string name;
    status cureentStatus;
    int socketFirstPLayer;
    int socketSecondPLayer;
};


#endif //EX4_GAME_H
