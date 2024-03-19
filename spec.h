#ifndef spec_h
#define spec_h

#include <iostream>

class Identification {
private:
    double _positionX;
    double _positionY;
    double _positionZ;
    double _length; //x
    double _width;  //y
    double _height; //z
    uint32_t _id;
public:
    Identification(double positionX, double positionY, double positionZ, double length, double width, double height, uint32_t id):
     _positionX(positionX), _positionY(positionY), _positionZ(positionZ), _length(length), _width(width), _height(height), _id(id) {       
    }
    double SetPositionX(double val) {
        _positionX = val;
    }
    double GetPositionX() {
        return this->_positionX;
    }
    double SetPositionY(double val) {
        _positionY = val;
    }
    double GetPositionY() {
        return this->_positionY;
    }
    double SetPositionZ(double val) {
        _positionZ = val;
    }
    double GetPositionZ() {
        return this->_positionZ;
    }
    void move(double x, double y, double z) {
        _positionX = x;
        _positionY = y;
        _positionZ = z;
    }
    void def(uint32_t id) {
        _id = id;
    }

};


class Table {
private:

public:
    Identification _ids;
    Table(Identification ids) : _ids(ids){}
    
    void printInfo(){}
    ~Table() = default;
};
class Computer {
private:

public:
    Identification _ids;
    Computer(Identification ids) : _ids(ids){}
    
    void printInfo(){}
    ~Computer() = default;
};
class Monitor {
private:
    struct Resolution {
        uint32_t _x;
        uint32_t _y;
    };
public:  
    Identification _ids;
    Resolution _reso;
    Monitor(Identification ids, Resolution xy) : _ids(ids), _reso(xy){}
    
    void printInfo() {}

    ~Monitor() = default;
};
class Laptop {
private:
public: 
    Identification _ids;
    Monitor _mon;
    Laptop(Identification ids, Monitor mon, Computer comp): _ids(ids), _mon(mon) {} 

    void printInfo() {

    }

    ~Laptop() = default;
};

#endif