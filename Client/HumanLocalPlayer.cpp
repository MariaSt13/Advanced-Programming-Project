
#include "HumanLocalPlayer.h"


using namespace std;
#include <iostream>
#include <limits>

/*
 * constructor.
 */
HumanLocalPlayer::HumanLocalPlayer(Board::disk d): Player(d) {}

/**
 * the player choose his next move in his turn .
 * @return - point.
 */
Point HumanLocalPlayer::chooseStep(UserInterface* userInterface) const {
    Point p = userInterface->choosePoint();
    return p;
}

