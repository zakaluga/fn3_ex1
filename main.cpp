#include <iostream>
#include <string>

using namespace std;

class Computer
{
    public:
    int quantity;
    string model;
    Computer(string m, int qu){
       model = m;
       quantity = qu;
    };
    
    void get_info()
    {
        cout<< " Компьютер "<<"Модель: " <<model << " Колличество  " << quantity <<  endl;
    };
        class Monitor
    {
        public:
        int diagonal;
        double grit;
        string type;

        Monitor(int di, double gr, string ty)
    {
            diagonal = di;
            grit = gr;
            type = ty;
    };
        void get_info()
    {
        cout<< " Монитор "<<"Диагональ: " <<diagonal  << " Зернистоть: " << grit << " Модель: " << type << endl;
    };

    };
    class Keyboard{
        public:
        string type;
        string color;

        Keyboard(string cl, string ty){
            type = ty;
            color = cl;
        };
        void get_info()
        {
            cout<< "Клавиатура "<<"Цвет: " << color << " Модель: " << type << endl;
        };

    };
    class Mouse{
        public:
        string type;
        string color;
        string locate;
        Mouse(string cl,string ty,  string lo){

            type = ty;
            color = cl;
            locate = lo;
        };
        void get_info()
        {
            cout<< " Мышь " <<"Цвет: " << color << " Модель: " << type << " Месторасположение в классе: " << locate << endl;
        };
      
    };
};
class Table{
    public:
    int quantity;
    int width;
    int high;
    string material;
    Table(int qu, int wi, int hi, string ma){
     quantity = qu;
     width = wi;
     high = hi;
     material = ma; 
    }
    void get_info()
        {
        cout<< " Стол "<<"Колличество " << quantity << " Ширина:(См) " << width << " Высота:(См) " << high << " Материал: "<< material << endl;
        };
};
class Chair{
     public:
    int quantity;
    int width;
    int high;
    string material;
    string comfort;
    Chair(int qu, int wi, int hi, string ma, string co){
     quantity = qu;
     width = wi;
     high = hi;
     material = ma; 
     comfort = co;
    }
    void get_info()
        {
        cout<< " Стул  "<<"Колличество " << quantity << " Ширина:(См) " << width << " Высота:(См) " << high << " Материал: "<< material << "Комфорт:" << comfort << endl;
        };
};

int main(){
    setlocale(LC_ALL, "RU");
    
    Computer laptop ("Acer", 20);
    laptop.get_info();
    Computer::Monitor monitor(21,0.294, "Lenovo");
    monitor.get_info();
    Computer::Keyboard klava("Чёрный ", "Китайская");
    klava.get_info();
    Computer::Mouse mouse("Серая ", "Китайская", "Стол");
    mouse.get_info();
    Table table (20, 45, 55, "Дерево, Алюминий") ;
    table.get_info();
    Chair chair (20, 45, 55, "Дерево, Алюминий ", " Нормально " ) ;
    chair.get_info();
    return 0;
};
