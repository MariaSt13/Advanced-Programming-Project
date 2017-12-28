//
// Created by linoy on 28/12/17.
//

#include "Game.h"

/**
 * constructor
 * @param name - name of the game
 * @param socketFirstPLayer - number socket of the first player.
 */
Game::Game(string name, int socketFirstPLayer):name(name),socketFirstPLayer(socketFirstPLayer),run(false) {}


/**
 * join second player to the game.
 * @param socketPLayer - number socket of the second player.
 */
void Game::joinToGame(int socketPLayer) {
    this->socketSecondPLayer = socketPLayer;
    this->run = true;
}

const string Game::getName()const {
    return this->name;
}

bool Game::isRun() const {
    return run;
}
