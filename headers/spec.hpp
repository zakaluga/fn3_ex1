#ifndef spec_h
#define spec_h
#include "includes.h"
struct ID {
private:
    uint16_t _id;   //identification number
public:
    void SetId(uint16_t valId) {
        this->_id = valId;
    }
    uint16_t GetId() {
        return this->_id;
    }
    ID(): _id(0){};
};
class Move {    //movable object
private:
    double _x;  //x coordinate. point located in the center of an object
    double _y;  //y coordinate. point located in the center of an object
    double _z;  //z coordinate. point located in the center of an object
public:
    void SetX(double valX) {    //setter X
        this->_x = valX;
    }
    void SetY(double valY) {    //setter Y
        this->_y = valY;
    }
    void SetZ(double valZ) {    //setter Z
        this->_z = valZ;
    }
    double GetX() {             //getter X
        return this->_x;
    }
    double GetY() {             //getter Y
        return this->_y;
    }
    double GetZ() {             //getter Z
        return this->_z;
    }
    
    Move(): _x(0), _y(0), _z(0) {}
    ~Move() = default;
};
class Sizes {   //defines in constructor
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
    Sizes(double sizeX, double sizeY, double sizeZ): 
        _sizeX(sizeX), _sizeY(sizeY), _sizeZ(sizeZ) {}
    ~Sizes() = default;
};
class Book: public Move, Sizes, ID {
private:
    std::string _isbn;  //defines in constructor
    std::string _name;  //defines in constructor
public:  
    Book(double sizeX, double sizeY, double sizeZ, std::string isbn, std::string name): 
        Sizes(sizeX, sizeY, sizeZ), _isbn(isbn), _name(name) {}
    ~Book() = default;
};
class Furniture: public Move, Sizes, ID {
private:
    std::string _materials;
    std::string _name;
public:
    Furniture(double sizeX, double sizeY, double sizeZ, std::string materials, std::string name): 
        Sizes(sizeX, sizeY, sizeZ), _materials(materials), _name(name) {}
    ~Furniture() = default;
};

struct working {
private:
    bool power;
    bool packed;
public:
    bool GetPower() { return this->power; }
    bool GetPacked() { return this->packed; }
    void SetPower(bool valPow) { power = valPow; }
    void SetPacked(bool valpacked) { packed = valpacked; }
    bool isWorking() { if (power && packed) return true; }
};
class Computer: public Move, Sizes, ID, working {
public:
    Computer(double sizeX, double sizeY, double sizeZ): Sizes(sizeX, sizeY, sizeZ){}
    ~Computer() = default;
};
class Monitor: public Move, Sizes, ID {
public:
    Monitor(double sizeX, double sizeY, double sizeZ): Sizes(sizeX, sizeY, sizeZ){}
    ~Monitor() = default;

};
class Unregistered: public Move, Sizes, ID {
private:
    std::string _materials;
    std::string _name;
public:
    Unregistered(double sizeX, double sizeY, double sizeZ, std::string materials, std::string name): 
        Sizes(sizeX, sizeY, sizeZ), _materials(materials), _name(name) {}
    ~Unregistered() = default;
};
#endif