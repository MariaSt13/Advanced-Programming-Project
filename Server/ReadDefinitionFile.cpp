
#include <vector>
#include "ReadDefinitionFile.h"
#include <boost/algorithm/string.hpp>
using namespace boost;
using namespace std;


/**
 * This class opens a definition file
 * and creates a map of definitions.
 * @param s - the path to the difintion file.
 * @return - map.
 */
map<string,string> ReadDefinitionFile::getVectorDefinition(const char* s)const {
    int pairSize = 2;
    string line;
    map<string,string> myMap;
    vector<string> buffer;

    // open a file in read mode.
    ifstream file;
    file.open(s);

    //if the file is open.
    if(file.is_open()){

        //read line by line.
        while(getline(file,line)){
            split(buffer,line,is_any_of(":"));

            //make pair
            if(buffer.size() == pairSize){
                trim(buffer.at(0));
                trim(buffer.at(1));
                myMap.insert(make_pair(buffer.at(0),buffer.at(1)));
            }

        }
        file.close();
    }

        //if there is error with open file.
    else
        throw "Error: cannot open file";

    return myMap;
}