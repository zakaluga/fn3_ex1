#include <iostream>
#include <string>


enum class TypeFurniture{
    TABLE,
    CHAIR,
    SHELF
};

//enum class SerNumber{
  //  int mass[];
//yes};


class Settings {
    public:
    TypeFurniture type;
    int hight;
    int width;
    Settings(){}
    Settings(TypeFurniture t, int h, int w){
        type = t;
        hight = h;
        width = w;
    }
    
};
//константин борисович

class Table {
public: 

    Table(int h, int w): settings(Settings(TypeFurniture::TABLE, h, w)) {}
    
    Table(Settings s){
        settings = s;
    }
    Settings settings;

    std::string material;
};

class Chair {
public: 
    Settings settings;
    std::string material;
};


class Computer {
public:
    int number;


bool power_check_and_print (std::string power){
    if ((power == "yes") || (power == "Yes") || (power == "y")){
        return true;
    }
    else {
        return false;
    }
    
    
    }
};

class Screen {
public:
    int number;
    int hight;
    int width;
    int scr_resolution;



};

//void raspredelenie{
    //здесь будет распределение всех экземпляров по 2 массивам (рег и нон рег)
//}


int main(){
    std::string pwr;
   // Table table;
    Chair chair;
    Screen scr;
    Computer comp;
    std::cout<<"Is current working?"<<std::endl;
    std::cin>>pwr;
    if (comp.power_check_and_print(pwr)){
        std::cout<<"computer number ??? ready to work"<<std::endl;
        std::cout<<"monitor number ??? is also ready to work"<<std::endl;
    }
    else {
        std::cout<<"this computer and monitir don't work"<<std::endl;
    }


    

    
    //int registred[];
    //int not_registred[];
    

};



