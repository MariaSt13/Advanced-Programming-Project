
#ifndef EX4_CONECTTOSERVER_H
#define EX4_CONECTTOSERVER_H
#include <string>
#define MAX_SIZE 7
using namespace std;

/**
 * this class connects the client to the server.
 */
class ConnectToServer {
public:

    //constructor.
    ConnectToServer(const char *serverIP, int serverPort);

    //connect player to server.
    void connectToServer();

    //return the color of the player. 1 - black , 2 - white.
    int readTypeOfPlayer();

    //return socket number.
    int getClientSocket() const;

    //write to server
    void writeToServer(char* s, int clientSocket)const;

    //return arraySize
    const int getArraySize()const;

private:
    //maximum number of characters in the array.
    const int arraySize;

    const char *serverIP;
    int serverPort;
    int clientSocket;
};

#endif //EX4_CONECTTOSERVER_H
