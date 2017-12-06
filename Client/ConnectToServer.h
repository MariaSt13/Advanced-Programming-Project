
#ifndef EX4_CONECTTOSERVER_H
#define EX4_CONECTTOSERVER_H


class ConnectToServer {
public:
    ConnectToServer(const char *serverIP, int serverPort);
    void connectToServer();
    int readTypeOfPlayer();
    int getClientSocket() const;
private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};


#endif //EX4_CONECTTOSERVER_H
