#include "Game.h"

/**
 * constructor.
 * @param name - name of the game.
 * @param socketFirstPLayer - socket number of the first player.
 */
Game::Game(string name, int socketFirstPLayer):name(name),socketFirstPLayer(socketFirstPLayer),currentStatus(waiting) {}


/**
 * Join a second player to the game.
 * @param socketPLayer - socket number of the second player.
 */
void Game::joinToGame(int socketPLayer) {
    this->socketSecondPLayer = socketPLayer;
    this->currentStatus = running;
}

/**
 * Sets the status of the game.
 * @param s - new status.
 */
void Game::setStatus(status s) {
    this->currentStatus = s;
}

/**
 * @return - the name of the game.
 */
const string Game::getName()const {
    return this->name;
}

/**
 * @return - current status of the game.
 */
Game::status Game::getStatus() const {
    return currentStatus;
}

/**
 * @return - socket number of the first player.
 */
const int Game::getSocketFirstPLayer() const {
    return this->socketFirstPLayer;
}

/**
 * @return - socket number of the second player.
 */
const int Game::getSocketSecondPLayer() const {
    return this->socketSecondPLayer;
}
