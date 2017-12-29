//
// Created by linoy on 28/12/17.
//

#include "Game.h"

/**
 * constructor
 * @param name - name of the game
 * @param socketFirstPLayer - number socket of the first player.
 */
Game::Game(string name, int socketFirstPLayer):name(name),socketFirstPLayer(socketFirstPLayer),cureentStatus(waiting) {}


/**
 * join second player to the game.
 * @param socketPLayer - number socket of the second player.
 */
void Game::joinToGame(int socketPLayer) {
    this->socketSecondPLayer = socketPLayer;
    this->cureentStatus = running;
}

void Game::setStatus(status s) {
    this->cureentStatus = s;
}

const string Game::getName()const {
    return this->name;
}

Game::status Game::getStatus() const {
    return cureentStatus;
}

const int Game::getSocketFirstPLayer() const {
    return this->socketFirstPLayer;
}

const int Game::getSocketSecondPLayer() const {
    return this->socketSecondPLayer;
}
