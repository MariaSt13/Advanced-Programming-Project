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
    string s;
    vector<string> vector;
    int x,y;

    int n = read(clientSocket,&s, sizeof(s));

    if (n == -1) {
        throw "Error reading result";
    }

    //if there are no valid.
    if (s.compare("NoMove") == 0) {
        return Point(-1,-1);
    }

    split(vector,s,boost::is_any_of(' '));

    if(vector.size() == 2){
        istringstream isX (vector.at(0));
        isX >> x;

        istringstream isY (vector.at(1));
        isY >> y;
    }

    return Point(x, y);
}
