//
// Created by maria on 04/12/17.
//

#include "Player.h"
#ifndef EXAM1_REMOTEPLAYER_H
#define EXAM1_REMOTEPLAYER_H
#include <boost/algorithm/string.hpp>


class RemotePlayer: public Player {

public:
    RemotePlayer(Board::disk d, int clientSocket);

    virtual Point chooseStep() const;

    //destructor.
    virtual ~RemotePlayer(){};

private:

    int clientSocket;
};


#endif //EXAM1_REMOTEPLAYER_H
