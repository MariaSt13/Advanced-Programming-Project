#include "Server.h"
#include <iostream>
#include <stdlib.h>
#include <map>
#include <sstream>
#include "ReadDefinitionFile.h"

using namespace std;
int main() {

    //get port number and create server.
    ReadDefinitionFile read = ReadDefinitionFile();
    map<string,string> myMap;

    try{
        myMap = read.getVectorDefinition("/home/maria/Documents/git/Advanced-Programming-Project/Server/serverDefinitionFile.txt");
    } catch (char const* msg){
        cout << "Error: " << msg << endl;
        exit(1);
    }


    int port;
    istringstream isX (myMap.find("port")->second);
    isX >> port;
    CommandsManager *commandsManager = new CommandsManager();
    Server server(port,commandsManager);

    //open server
    try {
        server.start();
        cout << "Enter exit to stop server" <<endl;
        string str;
        cin >> str;
        
        if (str == "exit") {
            server.stop();
        }
    } catch (char const* msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(1);
    }
}

