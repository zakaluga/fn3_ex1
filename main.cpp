#include <iostream>

class Position {
private:
    double _positionX;
    double _positionY;
    double _positionZ;
public:
    Position(double positionX, double positionY, double positionZ): _positionX(positionX), _positionY(positionY), _positionZ(positionZ) {       
    }
    void move(double x, double y, double z) {
        _positionX = x;
        _positionY = y;
        _positionZ = z;
    }
};
class Table {
public:
    Position pos;
    Table(Position p) : pos(p){}
    
    void printInfo(){}
};
class Computer {
private:


public:

};


int main()
{
    Table parta(Position(1, 1, 1));
    std::cout << "Привет Мир!" << std::endl;
    return 0;
}