
#include "StandardGameLogic.h"
using namespace std;

/**
 * The function returns a vector with all possible steps for the player.
 */
vector<Point> StandardGameLogic::returnValidMoves(const Player* p ,const Board* b) {
    Board::disk** array = b->getArray();
    vector<Point> v;
    pointsMap.clear();

    //check every point in the matrix
    for (int i = 1; i < b->getRowSize() ; i++) {
        for (int j = 1; j < b->getColSize(); j++) {
            //check if the point is a valid move for the player
            checkPoint(p,Point(i,j),b ,v);
        }
    }
    return v;
}

/**
 * The function get a point and check if it is a valid point (possible move) for the player.
 * @param player - current player.
 * @param p - the point that is checked.
 * @param b - current board.
 * @param vec - vector of possible points.
 */
void StandardGameLogic::checkPoint(const Player* player, const Point &p, const Board* b, vector<Point> &vec) {
    Board::disk** array = b->getArray();
    int x = p.getX();
    int y = p.getY();

    //if the cell is of th current player
    if(array[x][y] == player->getDisk()){

        //the loop goes through all the cell's neighbors.
        for (int i = -1; i < 2 ; i++) {
            for (int j = -1; j < 2 ; j++) {

                Point cuurentNeighbor = Point(x+i,y+j);

                //If the point is not outside the boundaries of the matrix
                if( b->pointIsInRange(cuurentNeighbor)){

                    //If it is cell of the opposing player
                    if(array[x+i][y+j] != Board::empty && array[x+i][y+j] != player->getDisk()){

                        //if there will be reversion of the opponent's washers
                        Point point = ifReverseOpponentDisk(player,Point(x,y),b,i,j);

                        if(b->pointIsInRange(point)){
                            if(!point.ifThePointIsInVector(vec)){
                                vec.push_back(point);
                            }
                        }
                    }
                }
            }
        }
    }
}

/**
 * The function get a points and check if selecting this point will reverse the opponent disks.
 * @param player - current player.
 * @param p - the point that is checked.
 * @param b - current board.
 * @param i - index
 * @param j - index
 * @return - possible point.
 */
Point StandardGameLogic::ifReverseOpponentDisk(const Player* player,const  Point &p,  const Board* b,
                                               const int &i,const int &j) {
    Board::disk** array = b->getArray();
    Point currentPoint = p;
    vector<Point> v;
    int x = currentPoint.getX() + i;
    int y = currentPoint.getY() + j;
    Point point = Point(x,y);

    /*
     * while the point is not outside the boundaries of the matrix and
     * the point is not empty and not the player color.
     */
    while(b->pointIsInRange(point) && array[point.getX()][point.getY()] != Board::empty &&
            array[point.getX()][point.getY()] != player->getDisk()){

        //if the point is not exist in the vector
        if(!point.ifThePointIsInVector(v)){
            v.push_back(point);
        }

        x = point.getX() + i;
        y = point.getY() + j;
        point = Point(x,y);
    }

    //if it is cell empty and in board
    if(b->pointIsInRange(point)){
        if(array[x][y] == Board::empty){
            //if this point key is already exist in the map.
            if(pointsMap.find(point) != pointsMap.end()){
                pointsMap[point].insert(pointsMap[point].end(),v.begin(),v.end());
            }
            else{
                pointsMap[point] = v;
            }
            return point;
        }
    }

    return Point(-1,-1);
}

/**
 * The function places a disc where the player has selected
 * and flips the opponents cells by the map.
 * @param player - current player.
 * @param newPoint - the placed point.
 * @param b - board.
 * @param updateMap - first update the map. (when return valid moves was not called before that.)
 */
void StandardGameLogic::flipCells(const Player* player,const Point &newPoint, const Board* b, bool updateMap) {
    if ( updateMap == true) {
        returnValidMoves(player, b);
    }
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