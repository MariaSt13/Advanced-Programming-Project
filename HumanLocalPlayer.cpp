//name: linoy cohen
//ID: 206333502

#include "HumanLocalPlayer.h"
using namespace std;
#include <iostream>
#include <limits>

HumanLocalPlayer::HumanLocalPlayer(Board::disk d): Player(d) {}

// the player choose his next move in his turn .
Point HumanLocalPlayer::chooseStep() const {
    int row;
    int col;
    cin >> row >> col;

    if(cin.fail()){
        // get rid of failure state
        cin.clear();

        // discard 'bad' character(s)
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
       return Point(-1,-1);
    }

    return Point(row, col);
}

