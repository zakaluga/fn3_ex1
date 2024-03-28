#ifndef spec_h
#define spec_h

#include "includes.h"


class Dimensions {  //position, sizes
private:
    double _positionX;
    double _positionY;
    double _positionZ;
    double _length; //x
    double _width;  //y
    double _height; //z
public:
    Dimensions(double positionX, double positionY, double positionZ, double length, double width, double height):
     _positionX(positionX), _positionY(positionY), _positionZ(positionZ), _length(length), _width(width), _height(height) {       
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

//Cout block start



//Cout block end
};
class Table {   //Dimensions, id, material
private:
    std::string _material = "";
    Dimensions _ids;
    uint32_t _id;
public:
    Table(Dimensions ids, uint32_t id, std::string material) : _ids(ids), _id(id), _material(material){}
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
    //Id block start
    void SetId(uint32_t val) {
        _id = val;
    }
    uint32_t GetId() {
        return this->_id;
    }
//Id block end
    ~Table() = default;
};
class Computer {    //Dimensions, id, cpu speed
private:
    Dimensions _ids;
    uint32_t _id;
public:
    Computer(Dimensions ids, uint32_t id) : _ids(ids), _id(id){} 
    

//Id block start
    void SetId(uint32_t val) {
        _id = val;
    }
    uint32_t GetId() {
        return this->_id;
    }
//Id block end
    void printInfo(){}
    ~Computer() = default;
};
class Monitor { //Dimensions, id, resolution
private:
    struct Resolution {
        uint32_t x;
        uint32_t y;
    };
    Dimensions _ids;
    uint32_t _id;
    Resolution _reso;
public:
    Monitor(Dimensions ids, uint32_t id, Resolution reso) : _ids(ids), _id(id), _reso(reso){}  
    void SetResolution(Resolution val) {
        this->_reso.x = val.x;
        this->_reso.y = val.y;
    }
    Resolution GetResolution() {
        return this->_reso;
    }
    void SetId(Dimensions val) {
        this->_ids = val;
    }
    Dimensions GetId() {
        return this->_ids;
    }
    
    void printInfo() {}

    ~Monitor() = default;
};
class Book {    //Dimensions, id, name, isbn
private:
    std::string _name;
    std::string _isbn;
    Dimensions _ids;
    uint32_t _id;
public:
    Book(Dimensions ids, uint32_t id, std::string name, std::string isbn): _ids(ids), _id(id), _name(name), _isbn(isbn) {}
    void SetName(std::string val) {
        _name = val;
    }
    std::string GetName() {
        return this->_name;
    }
    void SetIsbn(std::string var) {
        _isbn = var;
    }
    std::string GetIsbn() {
        return this->_isbn;
    }
};
class Unregistered {
private:
    Dimensions _ids;
    
public:
    Unregistered(Dimensions ids): _ids(ids) {}
    
};

#endif