//
// Created by linoy on 08/12/17.
//

#include <vector>
#include "ReadDefiniationFile.h"
#include <boost/algorithm/string.hpp>

using namespace boost;


void ReadDefiniationFile::readiFile() {

    // open a file in read mode.
    ifstream file;
    file.open("DefiniationFile.txt");
    int pairSize = 2;
    string line;
    vector v < pair<string,string> >;
    vector buffer <string>;

    //if the file is open.
    if(file.is_open()){

        //read line by line.
        while(getline(file,line)){
            split(buffer,line,is_any_of(":"));

            //make pair
            if(buffer.size() == pairSize){
                v.push_back(make_pair(buffer.at(0),buffer.at(1)));
            }

        }
        file.close();
    }

    //if there is error with open file.
    else
        throw "Error: cannot open file";

}
