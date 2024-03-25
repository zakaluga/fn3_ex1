#ifndef spec_h
#define spec_h

#include "includes.h"


class Identification {  //position, dimensions, idd
private:
    double _positionX;
    double _positionY;
    double _positionZ;
    double _length; //x
    double _width;  //y
    double _height; //z
    uint32_t _id = 0;   //if item is not registered = 0
public:
    Identification() {

    }
    Identification(double positionX, double positionY, double positionZ, double length, double width, double height, uint32_t id):
     _positionX(positionX), _positionY(positionY), _positionZ(positionZ), _length(length), _width(width), _height(height), _id(id) {       
    }
    
//Position block start
    void SetPositionX(double val) {
        _positionX = val;
    }
    double GetPositionX() {
        return this->_positionX;
    }
    
    void SetPositionY(double val) {
        _positionY = val;
    }
    double GetPositionY() {
        return this->_positionY;
    }
    
    void SetPositionZ(double val) {
        _positionZ = val;
    }
    double GetPositionZ() {
        return this->_positionZ;
    }
//Position block end

//Dimensions block start
    void SetLength(double val){
        _length = val;
    }
    double GetLength(){
        return this->_length;
    }
    
    void SetWidth(double val){
        _width = val;
    }
    double GetWidth(){
        return this->_width;
    }
    
    void SetHeight(double val){
        _height = val;
    }
    double GetHeight() {
        return this->_height;
    }
//Dimensions block end

//Id block start
    void SetId(uint32_t val) {
        _id = val;
    }
    uint32_t GetId() {
        return this->_id;
    }
//Id block end

//Cout block start



//Cout block end
};
class Table {   //material, Identification
private:
    std::string _material = "";
    Identification _ids;
public:
    Table(Identification ids, std::string material) : _ids(ids), _material(material){}
    
    //Material block start
    void SetMaterial(std::string val) {
        _material = val;
    }
    std::string GetMaterial() {
        return this->_material;
    }
    //Material block end

    void printInfo(){
        std::cout << "\n Table: \n" << "id: ";
    }
    ~Table() = default;
};
class Computer {    //cpu speed, Identification
private:
    double _cpuSpeed;
   Identification _ids;
public:
    Computer(Identification ids, double cpuSpeed) : _ids(ids), _cpuSpeed(cpuSpeed){}
    
    //CpuSpeed block start
    void SetCpuCSpeed(double val) {
        _cpuSpeed = val;
    }
    double GetCpuSpeed() {
        return this->_cpuSpeed;
    }
    //CpuSpeed block end

    void printInfo(){}
    ~Computer() = default;
};
class Monitor { //resolution, Identification
private:
    struct Resolution {
        uint32_t x;
        uint32_t y;
    };
    Identification _ids;
    Resolution _reso;
public:  
    void SetResolution(Resolution val) {
        this->_reso.x = val.x;
        this->_reso.y = val.y;
    }
    Resolution GetResolution() {
        return this->_reso;
    }
    void SetId(Identification val) {
        this->_ids = val;
    }
    Identification GetId() {
        return this->_ids;
    }

    Monitor(Identification ids, Resolution reso) : _ids(ids), _reso(reso){}
    
    void printInfo() {}

    ~Monitor() = default;
};
class Book {
private:
    std::string _name;
    char _isbn[15];
public:
    void SetName(std::string val) {
        _name = val;
    }
    std::string GetName() {
        return this->_name;
    }
    void SetIsbn(char var[15]) {
        memcpy(_isbn, var, 15);
    }
    char* GetIsbn() {
        return this->_isbn;
    }
};
class Unregistered {
private:

public:
    Identification _ids;
    Unregistered(Identification ids): _ids(ids) {}
};

#endif