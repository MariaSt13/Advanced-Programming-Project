#ifndef EXAM1_REMOTEPLAYER_H
#define EXAM1_REMOTEPLAYER_H
#include <boost/algorithm/string.hpp>
#include "Player.h"

/*
 * this class extends player class and represent
 * a remote player .
 */
class RemotePlayer: public Player {

public:

    //constructor.
    RemotePlayer(Board::disk d, int clientSocket);

     /*
     * the player in his turn choose point
     * to put in his disk.
     */
    virtual Point chooseStep() const;

    //destructor.
    virtual ~RemotePlayer(){};

private:

    int clientSocket;
};


#endif //EXAM1_REMOTEPLAYER_H
