
#ifndef EX4_SERVER_H
#define EX4_SERVER_H
#define MAX_CONNECTED_CLIENTS 2

class Server {

public:

    Server(int port);
    void start();
    void stop();

private:

    int port;
    int serverSocket; // the socket's file descriptor
    bool openServer;
    void handleClient(int clientSocket1,int clientSocket2);
};
#endif //EX4_SERVER_H
