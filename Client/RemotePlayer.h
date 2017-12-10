#ifndef EXAM1_REMOTEPLAYER_H
#define EXAM1_REMOTEPLAYER_H
#include <boost/algorithm/string.hpp>
#include "Player.h"
#include "ConnectToServer.h"

/*
 * this class extends player class and represent
 * a remote player .
 */
class RemotePlayer: public Player {

public:

    //constructor.
    RemotePlayer(Board::disk d, ConnectToServer client);

     /*
     * the player in his turn choose point
     * to put in his disk.
     */
    virtual Point chooseStep() const;

    //destructor.
    virtual ~RemotePlayer(){};

private:

    ConnectToServer client;
};


#endif //EXAM1_REMOTEPLAYER_H
