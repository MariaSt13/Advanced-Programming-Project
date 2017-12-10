//
// Created by linoy on 10/12/17.
//

#include <gtest/gtest.h>
#include "../ReadDefinitionFile.h"

/*
 * Test 1:that the function create a correct
 * map of key and value from text file.
 */
TEST(ReadDefinitionFileTest, checkMap) {
    ReadDefinitionFile read = ReadDefinitionFile();
    map<string,string> myMap;

    try{
        myMap = read.getVectorDefinition("fileTest1.txt");
    } catch (char const* msg){
        cout << "Error: " << msg << endl;
        exit(1);
    }

    //check value of key in the map
    EXPECT_EQ(myMap.find("name")->second,"alice");
    EXPECT_EQ(myMap.find("size")->second,"8");
    EXPECT_EQ(myMap.find("height")->second,"155");
    EXPECT_EQ(myMap.find("weight")->second,"50");
    EXPECT_EQ(myMap.find("hair color")->second,"brown");
    EXPECT_EQ(myMap.find("grade")->second,"100");
    EXPECT_EQ(myMap.find("school")->second,"bar ilan");
    EXPECT_EQ(myMap.find("telephone")->second,"052");
    EXPECT_EQ(myMap.find("class")->second,"b");
    EXPECT_EQ(myMap.find("eyes color")->second,"blue");

    //clear map
    myMap.clear();

    try{
        myMap = read.getVectorDefinition("fileTest2.txt");
    } catch (char const* msg){
        cout << "Error: " << msg << endl;
        exit(1);
    }

    //check value of key in the map
    EXPECT_EQ(myMap.find("name")->second,"bob");
    EXPECT_EQ(myMap.find("height")->second,"220");
    EXPECT_EQ(myMap.find("weight")->second,"80");
    EXPECT_EQ(myMap.find("hair color")->second,"yellow");
    EXPECT_EQ(myMap.find("city")->second,"tel aviv");
    EXPECT_EQ(myMap.find("telephone")->second,"000-0000");
    EXPECT_EQ(myMap.find("grade")->second,"60");
    EXPECT_EQ(myMap.find("size")->second,"56");
    EXPECT_EQ(myMap.find("class")->second,"h");
    EXPECT_EQ(myMap.find("eyes color")->second,"brown");
}