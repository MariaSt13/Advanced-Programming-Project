

#ifndef EX4_READDEFINITIONFILE_H
#define EX4_READDEFINITIONFILE_H

#include <fstream>
#include <iostream>
#include <map>

using namespace std;

/**
 * This class opens a definition file
 * and creates a map of definitions.
 */
class ReadDefinitionFile {

public:

    //read file and create map
    map<string,string> getVectorDefinition(const char* s)const;
};


#endif //EX4_READDEFINITIONFILE_H
