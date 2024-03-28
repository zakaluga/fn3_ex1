#ifndef spec_h
#define spec_h
#include "includes.h"

class Move {
private:
    double _x;  //x coordinate. point located in the center of an object
    double _y;  //y coordinate. point located in the center of an object
    double _z;  //z coordinate. point located in the center of an object
    double _sizeX;  //length
    double _sizeY;  //width
    double _sizeZ;  //height
public:
    //getters and setters block
    void SetX(double valX) {
        this->_x = valX;
    }
    double GetX() {
        return this->_x;
    }
    void SetY(double valY) {
        this->_y = valY;
    }
    double GetY() {
        return this->_y;
    }
    void SetZ(double valZ) {
        this->_z = valZ;
    }
    double GetZ() {
        return this->_z;
    }
    Move() {}
    Move(double x, double y, double z, double sizeX, double sizeY, double sizeZ): _x(x), _y(y), _z(z), _sizeX(sizeX), _sizeY(sizeY), _sizeZ(sizeZ) {

    }
    ~Move(){}
};


#endif