//
// Created by linoy on 08/12/17.
//

#include <vector>
#include "ReadDefinitionFile.h"
#include <boost/algorithm/string.hpp>
#include <map>

using namespace boost;
using namespace std;


map<string,string> ReadDefinitionFile::getVectorDefinition() {

    // open a file in read mode.
    ifstream file;
    file.open("./DefinitionFile.txt");
    int pairSize = 2;
    string line;
    map<string,string> myMap;
    vector<string> buffer;

    //if the file is open.
    if(file.is_open()){
        cout << "open";
        //read line by line.
        while(getline(file,line)){
            split(buffer,line,is_any_of(":"));
            cout << buffer.at(0) << " " << buffer.at(1);
            //make pair
            if(buffer.size() == pairSize){
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
