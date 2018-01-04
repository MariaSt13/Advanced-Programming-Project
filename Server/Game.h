#ifndef EX4_GAME_H
#define EX4_GAME_H

#include <string>
using namespace std;

/**
 * game class that hold all the properties of the game
 * such as game name, game status and clients sockets.
 */
class Game {
public:
    enum status {waiting, running, finished};

    //constructor
    Game(string name,int socketFirstPLayer);

    //join second player to game
    void joinToGame(int socketPLayer);

    //return name of the game.
    const string getName()const;

    //return socket of the first player.
    const int getSocketFirstPLayer()const;

    //return socket the second player.
    const int getSocketSecondPLayer()const;

    //set game status.
    void setStatus(status s);

    //return current status of the game.
    status getStatus() const;

private:
    string name;
    status currentStatus;
    int socketFirstPLayer;
    int socketSecondPLayer;
};
#endif //EX4_GAME_H
