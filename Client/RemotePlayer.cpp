//
// Created by maria on 04/12/17.
//

#include <unistd.h>
#include <iostream>
#include "RemotePlayer.h"
using namespace std;

/**
 * constructor.
 * @param d - disk.
 * @param clientSocket - client socket number.
 */
RemotePlayer::RemotePlayer(Board::disk d, int clientSocket): Player(d),clientSocket(clientSocket) {}

/**
 * the player choose his next move in his turn .
 * @return - point.
 */
Point RemotePlayer::chooseStep() const {
    char s[7];
    vector<string> vector;
    int x,y;

    //read from server
    int n = read(clientSocket,&s, sizeof(s));
    cout << "s-->" <<s;
    cout << "n-->" <<n;
    //error
    if (n == -1)
        throw "Error reading result";

    // other player disconnected
    if(n == 0)
        throw "Error reading result: other player disconnected";

    //if there are no valid.
    if (strcmp(s, "NoMove") == 0) {
        memset(s, '\0', 7);
        return Point(-1,-1);
    }
    
    x = s[0];
    y = s[2];

    memset(s, '\0', 7);
    return Point(x, y);
}
