//
// Created by maria on 04/12/17.
//

#include <unistd.h>
#include <iostream>
#include "RemotePlayer.h"
using namespace boost;
using namespace std;


RemotePlayer::RemotePlayer(Board::disk d, int clientSocket): Player(d),clientSocket(clientSocket) {}

Point RemotePlayer::chooseStep() const {
    char s[7];
    vector<string> vector;
    int x,y;

    int n = read(clientSocket,&s, sizeof(s));

    if (n == -1) {
        throw "Error reading result";
    }

    //if there are no valid.
    if (strcmp(s, "NoMove") == 0) {
        memset(s, '\0', 7);
        return Point(-1,-1);
    }
    
    x = s[0];
    y = s[2];
   /* istringstream isX (vector.at(0));
    isX >> x;

    istringstream isY (vector.at(1));
    isY >> y;*/
    memset(s, '\0', 7);
    return Point(x, y);
}
