//name: linoy cohen
//ID: 206333502

#include "StandardGameLogic.h"
using namespace std;
#include <iostream>

//The function returns a vector with all possible steps for the player.
vector<Point> StandardGameLogic::returnValidMoves(const Player* p ,const Board* b) {
    Board::disk** array = b->getArray();
    vector<Point> v;
    pointsMap.clear();

    //check every point in the matrix
    for (int i = 1; i < b->getRowSize() ; i++) {
        for (int j = 1; j < b->getColSize(); j++) {
            //update vector
            vector<Point> temp = checkPoint(p,Point(i,j),b);
            v.insert(v.end(),temp.begin(),temp.end());
        }
    }
    return v;
}

// the function get a point and check if it is a valid point
// (possible move) for the player.
vector<Point> StandardGameLogic::checkPoint(const Player* player, const Point &p, const Board* b) {
    vector<Point> v;
    Board::disk** array = b->getArray();
    int x = p.getX();
    int y = p.getY();

    //if the cell is empty.
    if(array[x][y] == ' '){

        //the loop goes through all the cell's neighbors.
        for (int i = -1; i < 2 ; i++) {
            for (int j = -1; j < 2 ; j++) {

                Point cuurentNeighbor = Point(x+i,y+j);

                //If the point is not outside the boundaries of the matrix
                if( b->pointIsInRange(cuurentNeighbor)){

                    //If it is cell of the opposing player
                    if(array[x+i][y+j] != ' ' && array[x+i][y+j] != player->getDisk()){

                        //if there will be reversion of the opponent's washers
                        if(ifReverseOpponentDisk(player,Point((x),(y)),b,i,j)){

                            Point point = Point((x),(y));

                            if(!point.ifThePointIsInVector(v)){
                                v.push_back(p);
                            }
                        }
                    }
                }
            }
        }
    }
    return v;
}

// the function get a points and check if selecting this point
// will reverse the opponent disks.
bool StandardGameLogic::ifReverseOpponentDisk(const Player* player,const  Point &p,  const Board* b,const int &i,const int &j) {
    Board::disk** array = b->getArray();
    Point currentPoint = p;
    vector<Point> v;
    int x = currentPoint.getX() + i;
    int y = currentPoint.getY() + j;
    Point point = Point(x,y);

    //while the point is not outside the boundaries of the matrix and
    // the point is not empty.
    while(b->pointIsInRange(point) && array[point.getX()][point.getY()] != ' '){

        //if it is cell of current player.
        if(array[x][y] == player->getDisk()){

            //if this point key is already exist in the map.
            if(pointsMap.find(currentPoint) != pointsMap.end()){
                pointsMap[currentPoint].insert(pointsMap[currentPoint].end(),v.begin(),v.end());
            }
            else{
                pointsMap[currentPoint] = v;
            }
            return true;
        }

        //if the point is not exist in the vector
        if(!point.ifThePointIsInVector(v)){
            v.push_back(point);
        }

        x = point.getX() + i;
        y = point.getY() + j;
        point = Point(x,y);
    }
    return false;
}

//The function places a disc where the player has selected
//And calls a function that turns the opponent's disks.
void StandardGameLogic::flipCells(const Player* player,const Point &newPoint, const Board* b) {
    Board::disk** array = b->getArray();
    array[newPoint.getX()][newPoint.getY()] = player->getDisk();
    vector<Point> v = pointsMap[newPoint];

    //reverse opponent cells.
    for (int i = 0; i < v.size() ; i++) {
        Point pointToReverse = v[i];
        array[pointToReverse.getX()][pointToReverse.getY()] = player->getDisk();
    }

    //clear map
    pointsMap.clear();

}

//destructor.
StandardGameLogic::~StandardGameLogic() {}