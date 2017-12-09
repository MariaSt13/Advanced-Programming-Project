#include "Server.h"
#include <iostream>
#include <stdlib.h>
#include <map>
#include <sstream>
#include "ReadDefinitionFile.h"

using namespace std;
int main() {

    ReadDefinitionFile read = ReadDefinitionFile();
    map<string,string> myMap = read.getVectorDefinition();
    int port;
    istringstream isX (myMap.find("port")->second);
    isX >> port;

    Server server(port);
    try {
        server.start();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
}

