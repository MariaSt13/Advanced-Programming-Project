
#include <iostream>
#include "Point.h"
using namespace std;

/**
 * constructor.
 * @param x - x value of the point
 * @param y - y value of the point
 */
Point::Point(const int &x,const int &y) : x(x), y(y){}


/**
 * Overloading operator <
 */
bool Point:: operator <(const Point& p) const{
    if (p.x > x)
        return true;
    else if (x > p.x)
        return false;
    else if (p.y > y)
        return true;
    else if (y > p.y)
        return false;
    return false;
}

/**
 * This function gets a vector of points and
 * returns 'true' if this point is exist in
 * the vector. else return 'false'.
 * @param v -  vector of points.
 */
bool Point:: ifThePointIsInVector(const vector<Point> &v) const {

    for (vector<Point>::const_iterator it2 = v.begin(); it2 < v.end(); it2++) {
        int x1 = (*it2).getX();
        int y1 = (*it2).getY();

        if(x == x1 && y ==y1){
            return true;
        }
    }
    return false;
}


/**
 * Overloading operator ==
 */
bool Point:: operator ==(const Point& p) const{
    return ((p.x == x) && (p.y == y));
}
/**
 * Overloading operator <<
 */
ostream &operator<<(ostream &out, const Point &pp) {
    out << '(' << pp.x << ',' << pp.y << ')';
}

/**
 * @return - x value of the point
 */
int Point::getX() const {
    return this->x;
}

/**
 * @return - y value of the point
 */
int Point::getY() const {
    return this->y;
}