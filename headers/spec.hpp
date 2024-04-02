#ifndef spec_h
#define spec_h
#include "includes.h"
struct ID {
private:
    uint16_t _id;
public:
    void SetId(uint16_t valId) {
        this->_id = valId;
    }
    uint16_t GetId() {
        return this->_id;
    }
    ID(): _id(0){};
};
class Move {
private:
    double _x;  //x coordinate. point located in the center of an object
    double _y;  //y coordinate. point located in the center of an object
    double _z;  //z coordinate. point located in the center of an object
public:
    void SetX(double valX) { //getters and setters block
        this->_x = valX;
    }
    void SetY(double valY) {
        this->_y = valY;
    }
    void SetZ(double valZ) {
        this->_z = valZ;
    }
    double GetX() {
        return this->_x;
    }
    double GetY() {
        return this->_y;
    }
    double GetZ() {
        return this->_z;
    }
    
    Move(): _x(0), _y(0), _z(0) {}
    ~Move() = default;
};
class Sizes {
private:
    double _sizeX;  //length
    double _sizeY;  //width
    double _sizeZ;  //height
public:
    double GetSizeX() {
        return this->_sizeX;
    }
    double GetSizeY() {
        return this->_sizeY;
    }
    double GetSizeZ() {
        return this->_sizeZ;
    }
    /*void SetSizeX(double varX){
        this->_sizeX = varX;
    }
    void SetSizeY(double varY) {
        this->_sizeY = varY;
    }
    void SetSizeZ(double varZ) {
        this->_sizeZ = varZ;
    }*/
    Sizes(double sizeX, double sizeY, double sizeZ): _sizeX(sizeX), _sizeY(sizeY), _sizeZ(sizeZ) {}
    ~Sizes() = default;
};
class Book: public Move, Sizes, ID {
private:
    std::string _isbn;
    std::string _name;
public:
    
    Book(double sizeX, double sizeY, double sizeZ, std::string isbn, std::string name): Sizes(sizeX, sizeY, sizeZ), _isbn(isbn), _name(name) {}
    ~Book() = default;
};
class Table: public Move, Sizes, ID {
public:
    
    Table(double sizeX, double sizeY, double sizeZ): Sizes(sizeX, sizeY, sizeZ) {}
    ~Table() = default;
};




#endif