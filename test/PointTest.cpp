//
// Created by linoy on 29/11/17.
//

#include <gtest/gtest.h>
#include "PointTest.h"
#include "../Point.h"

/*
 * test if the function that check if cureent point is in the given vector
 */
TEST(PointTest, ifPointIsInVector) {
    vector<Point> v;
    Point p1 = Point(2,1);
    Point p2 = Point(5,6);
    Point p3 = Point(1,1);
    Point p4 = Point(7,5);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    //points in vector
    EXPECT_TRUE(p1.ifThePointIsInVector(v));
    EXPECT_TRUE(p2.ifThePointIsInVector(v));
    EXPECT_TRUE(p3.ifThePointIsInVector(v));
    EXPECT_TRUE(p4.ifThePointIsInVector(v));

    //points not in vector
    EXPECT_FALSE(Point(-1,-1).ifThePointIsInVector(v));
    EXPECT_FALSE(Point(4,2).ifThePointIsInVector(v));
    EXPECT_FALSE(Point(8,5).ifThePointIsInVector(v));
    EXPECT_FALSE(Point(0,0).ifThePointIsInVector(v));
    EXPECT_FALSE(Point(3,4).ifThePointIsInVector(v));
}
/*
 * test operator == overloading
 */
TEST(PointTest, testEqual) {
    //equal
    EXPECT_TRUE(Point(4,4) == Point(4,4));
    int x= 5;
    int y =1;
    EXPECT_TRUE(Point(x,y) == Point(5,1));
    EXPECT_TRUE(Point(2,6) == Point(2,6));
    //not equal
    EXPECT_FALSE(Point(5,3) == Point(1,2));
    EXPECT_FALSE(Point(7,3) == Point(7,2));
    EXPECT_FALSE(Point(x,y) == Point(y,x));
}
/*
 * test operator < overloading
 */
TEST(PointTest, smallTest) {
    // small
    EXPECT_TRUE(Point(2,3) < Point(4,5));
    EXPECT_TRUE(Point(3,4) < Point(6,2));
    EXPECT_TRUE(Point(3,1) < Point(3,6));
    // big
    EXPECT_FALSE(Point(5,6) < Point(3,2));
    EXPECT_FALSE(Point(5,7) < Point(5,1));
    EXPECT_FALSE(Point(6,3) < Point(4,6));
}