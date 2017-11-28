//name: linoy cohen
//ID: 206333502

#include <iostream>
#include "Point.h"
using namespace std;

//constuctor.
Point::Point(const int &x,const int &y) : x(x), y(y){}


//overloading opertor.
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

//this function get a vector of points and
// return 'true' if this point is exist in
// the vector. else return 'false'.
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


//overloading opertor.
bool Point:: operator ==(const Point& p) const{
    return ((p.x == x) && (p.y == y));
}

ostream &operator<<(ostream &out, const Point &pp) {
    out << '(' << pp.x << ',' << pp.y << ')';
}

int Point::getX() const {
    return this->x;
}

int Point::getY() const {
    return this->y;
}