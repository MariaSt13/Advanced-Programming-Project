
#ifndef EX4_CONECTTOSERVER_H
#define EX4_CONECTTOSERVER_H
#include <string>
using namespace std;

/**
 * this class connect the client to the server.
 */
class ConnectToServer {
public:

    //constructor.
    ConnectToServer(const char *serverIP, int serverPort);

    //connect player to server.
    void connectToServer();

    //return the color of the player. 1-black , 2 -white.
    int readTypeOfPlayer();

    //return socket number.
    int getClientSocket() const;

    //write to server
    void writeToServer(char* s, int clientSocket)const;

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};

#endif //EX4_CONECTTOSERVER_H
