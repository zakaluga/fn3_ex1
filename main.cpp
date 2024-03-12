#include <iostream>
#include <clocale>

using namespace std;


struct Parameter {
    double height, width, length;

    Parameter(double h, double w, double l) : height(h), width(w), length(l) {};

    void display() const {
        cout << "Ширина: " << width << endl;
        cout << "Высота: " << height << endl;
        cout << "Длина: " << length << endl;
    }
};

class Chair {
public:
    Parameter parameter;

    Chair(double w, double h, double l) : parameter(w, h, l) {}
    
    void display() const {
        cout << "Стул" << endl;
        parameter.display();
        cout << endl;
    }
};

class Table {
public:
    Parameter parameter;

    Table(double w, double h, double l) :parameter(w, h, l) {}

    void display() const {
        cout << "Парта" << endl;
        parameter.display();
        cout << endl;
    }
};

class Monitor {
public:
    bool is_turned_on;
    static int resX;
    static int resY;
    static int diagonal;

    Monitor(bool v) : is_turned_on(v) {}

    void display() const  {
        cout << "Монитор" << endl << 
                "Разрешение экрана: " << resX << " на " << resY << " пикселей" << endl << 
                "Диагональ: " << diagonal << " дюймов" << endl << 
                (is_turned_on ? "Включен" : "Выключен") << endl << endl;
    }
};

class PC {
public:
    static string processor;
    static string video_card;

    static int mem;
    static int ram;

    bool is_turned_on;

    PC(bool v) : is_turned_on(v) {}

    void display() const {
        cout << "Компьютер" << endl <<
                "Процессор: " << processor << endl <<
                "Видеокарта: " << video_card << endl <<
                "Постоянная память: " << mem << " Гб" << endl <<
                "Оперативная память: " << ram << " Гб" << endl <<
                (is_turned_on ? "Включен" : "Выключен") << endl << endl;
    }
};

class Unregistered {
public:
    Parameter parameter;

    string name;

    Unregistered(double w, double h, double l, string n) : parameter(w, h, l), name(n) {}

    void display() {
        cout << "Незарегистрированный предмет" << endl << 
                "Имя предмета: " << name << endl;
        parameter.display();
        cout << endl;
    }
};

/// Характеристики мониторов
int Monitor::resX = 3840;
int Monitor::resY = 2160;
int Monitor::diagonal = 27;

/// Характеристики самих блоков
std::string PC::processor = "Intel core i9 -12400F";
std::string PC::video_card = "NVIDIA RTX 5090";
int PC::mem = 1024;
int PC::ram = 32;

int main() {
    setlocale(LC_ALL, "Russian");

    Chair chair(1, 0.5, 0.75);
    chair.display();

    Table table(1, 1, 2.5);
    table.display();
    
    Monitor monitor(true);
    monitor.display();
    
    PC pc(false);
    pc.display();
    
    Unregistered picture(0.1, 0.5, 0.7, "Картина Эйнштейна");
    picture.display();
}