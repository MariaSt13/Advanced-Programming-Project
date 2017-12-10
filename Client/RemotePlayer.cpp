#include <unistd.h>
#include <iostream>
#include "RemotePlayer.h"
using namespace std;

/**
 * constructor.
 * @param d - disk.
 * @param clientSocket - client socket number.
 */
RemotePlayer::RemotePlayer(Board::disk d, Client client): Player(d),client(client) {}

/**
 * the player gets the move from the server.
 * @return - point.
 */
Point RemotePlayer::chooseStep() const {
    const int size = this->client.getArraySize();
    char s[size];
    int x,y;

    //read from server
    int n = read(this->client.getClientSocket(),&s, sizeof(s));

    //error
    if (n == -1)
        throw "Error reading result";

    // other player disconnected
    if(n == 0)
        throw "other player disconnected";

    //if there are no valid.
    if (strcmp(s, "NoMove") == 0) {
        memset(s, '\0', size);
        return Point(-1,-1);
    }
    
    x = s[0];
    y = s[2];

    memset(s, '\0', size);
    return Point(x, y);
}
