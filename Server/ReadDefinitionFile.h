

#ifndef EX4_READDEFINITIONFILE_H
#define EX4_READDEFINITIONFILE_H

#include <fstream>
#include <iostream>
#include <map>

using namespace std;

/**
 * this class open a definition file
 * and create a map of definitions.
 */
class ReadDefinitionFile {

public:

    //reaad file and create map
    map<string,string> getVectorDefinition();
};


#endif //EX4_READDEFINITIONFILE_H
