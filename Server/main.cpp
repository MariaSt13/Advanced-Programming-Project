#include "Server.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include "ReadDefinitionFile.h"

using namespace std;
/**
 * main function
 * @return int.
 */
int main() {

    //get port number and create server.
    ReadDefinitionFile read = ReadDefinitionFile();
    map<string,string> myMap;

    try{
        myMap = read.getVectorDefinition("serverDefinitionFile.txt");
    } catch (char const* msg){
        cout << "Error: " << msg << endl;
        exit(1);
    }


    int port;
    istringstream isX (myMap.find("port")->second);
    isX >> port;
    Server server(port);

    //open server
    string str;
    try {
        server.start();
        cout << "Enter exit to stop server" <<endl;
        do {
            cin >> str;
        } while (str != "exit");

        if (str == "exit") {
            server.stop();
        }
    } catch (char const* msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(1);
    }
    return 0;
}

