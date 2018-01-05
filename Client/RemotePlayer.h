#ifndef EXAM1_REMOTEPLAYER_H
#define EXAM1_REMOTEPLAYER_H
#define MAX_ARRAY_SIZE 7
#include <boost/algorithm/string.hpp>
#include "Player.h"
#include "Client.h"

/**
 * This class extends player class and represent
 * a remote player .
 */
class RemotePlayer: public Player {

public:

    //constructor.
    RemotePlayer(Board::disk d, Client client);

     /**
     * The player in his turn choose point
     * to put in his disk.
     */
    virtual Point chooseStep(UserInterface* userInterface) const;

    //destructor.
    virtual ~RemotePlayer(){};

private:

    const Client client;
};


#endif //EXAM1_REMOTEPLAYER_H
