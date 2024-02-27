#include <iostream>

class Properties {
private:
    double _positionX;
    double _positionY;
    double _positionZ;
    uint16_t _id; 
public:
    Properties(double positionX, double positionY, double positionZ, uint16_t id) {
        _positionX = positionX;
        _positionY = positionY;
        _positionZ = positionZ;
        _id = id;
    }
    void move(double x, double y, double z) {
        _positionX = x;
        _positionY = y;
        _positionZ = z;
    }
};
class Table {
public:
    Properties info;
    Table(Properties p) : info(p){}
    
    void printInfo(){}
};


int main()
{
    Table parta(Properties(1, 1, 1, 1));
    std::cout << "Привет Мир!" << std::endl;
    return 0;
}