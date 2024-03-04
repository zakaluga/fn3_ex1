#include <iostream>


class Identification {
private:
    double _positionX;
    double _positionY;
    double _positionZ;
    uint32_t _id;
public:
    Identification(double positionX, double positionY, double positionZ, uint32_t id): _positionX(positionX), _positionY(positionY), _positionZ(positionZ), _id(id) {       
    }
    void move(double x, double y, double z) {
        _positionX = x;
        _positionY = y;
        _positionZ = z;
    }
    void def(uint32_t p) {
        _id = p;
    }
};


class Table {
public:
    Identification ids;
    Table(Identification p) : ids(p){}
    
    void printInfo(){}
};
class Computer {
public:
    Identification ids;
    Computer(Identification p) : ids(p){}
   
    void printInfo(){}
};
class Monitor {
private:
    struct Resolution {
        uint32_t _x;
        uint32_t _y;
    };
public:
    
    Identification ids;
    Resolution reso;
    Monitor(Identification p, Resolution xy) : ids(p), reso(xy){}
    
    void printInfo() {
        
    }
};


int main()
{
    
    return 0;
}
