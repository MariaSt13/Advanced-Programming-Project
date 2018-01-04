#include <unistd.h>
#include <iostream>
#include <cstring>
#include "GameManager.h"
#include "GameListManager.h"

GameManager::GameManager(Game* game) : game(game) {}

/**
 * this function start game communication.
 */
void GameManager::run() {

    //array of clients socket
    int clientSocket[MAX_CONNECTED_CLIENTS];
    clientSocket[0] = game->getSocketFirstPLayer();
    clientSocket[1] = game->getSocketSecondPLayer();

    //send to client his color.1- black , 2-white.
    for (int i = 0; i < MAX_CONNECTED_CLIENTS; i++) {
        int result = i + 1;
        int n = write(clientSocket[i], &result, sizeof(result));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }
    }

    //while the game is running.
    while (game->getStatus() == Game::running) {
        for (int i = 0; i < MAX_CONNECTED_CLIENTS; i++) {
            if (game->getStatus() == Game::running)
                handleClient(clientSocket[i], clientSocket[(i + 1) % 2]);
        }
    }
}


/**
 * Handle requests from a specific client.
 * @param clientSocket1- the server reads from this client.
 * @param clientSocket2 - the server writes to this client.
 */
void GameManager::handleClient(int clientSocket1,int clientSocket2) {
        char s[ARRAY_SIZE] = {0};

        //read a new move
        int n = read(clientSocket1, &s, sizeof(s));

        //if the game is over
        if(strcmp(s, "End") == 0){
            game->setStatus(Game::finished);
            GameListManager::getInstance()->removeGame(game);
            return;
        }

        //error
        if (n == -1) {
            cout << "Error reading arg1" << endl;
            game->setStatus(Game::finished);
            return;
        }

        //clientSocket1 disconnected
        if (n == 0) {
            cout << "Client disconnected" << endl;
            game->setStatus(Game::finished);
            return;
        }

        // Write the result back to clientSocket2.
        n = write(clientSocket2, &s, sizeof(s));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
            game->setStatus(Game::finished);
            return;
        }
        memset(s, '\0', ARRAY_SIZE);
}

