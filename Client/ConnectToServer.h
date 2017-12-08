
#ifndef EX4_CONECTTOSERVER_H
#define EX4_CONECTTOSERVER_H
#include <string>
using namespace std;


class ConnectToServer {
public:
    ConnectToServer(const char *serverIP, int serverPort);
    void connectToServer();
    int readTypeOfPlayer();
    int getClientSocket() const;
    //write to server
    void writeToServer(string s, int clientSocket)const;

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};


#endif //EX4_CONECTTOSERVER_H
