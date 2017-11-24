//name: linoy cohen
//ID: 206333502

#ifndef EXAM1_POINT1_H
#define EXAM1_POINT1_H
#include <sstream>
#include <vector>
using namespace std;

// point class.
// points represent by x and y value.
class Point{

private:
     int x;
     int y;

public:
    //constructor.
    Point(const int &x,const int &y);

    //this function get a vector of points and
    // return 'true' if this point is exist in
    // the vector. else return 'false'.
    bool ifThePointIsInVector(const vector<Point> &v) const;

    //opertor overloading.
    friend ostream &operator <<(ostream &out, const Point &pp);
    bool operator ==(const Point& p) const;
    bool operator <(const Point& p) const;

    //get functions.
    int getX() const;
    int getY() const ;
};


#endif //EXAM1_POINT1_H
