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
};