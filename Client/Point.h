
#ifndef EXAM1_POINT1_H
#define EXAM1_POINT1_H
#include <sstream>
#include <vector>
using namespace std;

/**
 * Point class.
 * Points represented by x and y value.
 */
class Point{

private:
     int x;
     int y;

public:
    /**
    * constructor.
    * @param x - x value of the point
    * @param y - y value of the point
    */
    Point(const int &x,const int &y);

    /**
     * this function get a vector of points and
     * return 'true' if this point is exist in
     * the vector. else return 'false'.
     * @param v -  vector of points.
     */
    bool ifThePointIsInVector(const vector<Point> &v) const;

    //operator overloading.
    friend ostream &operator <<(ostream &out, const Point &pp);
    bool operator ==(const Point& p) const;
    bool operator <(const Point& p) const;

    //get functions.
    int getX() const;
    int getY() const ;
};


#endif //EXAM1_POINT1_H
