#include <iostream>
#include <string>



class Specifications{
    std::string name;
    int hight;
    int width;
    //int count;
public:
    Specifications(std::string name_, int hight_, int width_) : name(name_), hight(hight_), width(width_) {}
    void Print() {
        std::cout<<"Информация об объекте: "<<std::endl<<"Название: "<<name<<std::endl<<"Размер: "<<hight<<"x"<<width<<std::endl;
        


    }
    

};



class Portraits{
    Specifications portrait = Specifications("name", 10, 20);
public:

    
    void Get() {
        portrait.Print();
    }
   
};
Portraits pictures[25];
//pictures [1] {"Пифаго́р Са́мосский", 10, 20};






class Table_chair{
    Specifications table = Specifications("Парта", 50, 100);
    Specifications chair = Specifications("Стул", 35, 35);
    int count;
public: 
    void Get (){
        table.Print();
        chair.Print();
    }


};




/*int main() {
    Portraits port[20];
    std::cin >> "input";
    port[0].get();

}*/





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
    std::cout<<"На текущий момент инвентарь аудитории состоит из: "<<std::endl;
    Table_chair tables;
    tables.Get();
    
    


    

    
    //int registred[];
    //int not_registred[];
    

};


