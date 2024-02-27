#include <iostream>

class Parametr
{
public:
    double height;
    double width;
    double length;
};
class Stul
{
public:
    Parametr stulPar;
    std::string name;
    Stul(double w, double h, double l, std::string n) : stulPar({w, h, l}), name(n) {}
    void display()
    {
        std::cout << "Имя предмета: " << name << std::endl;
        std::cout << "Ширина: " << stulPar.width << std::endl;
        std::cout << "Высота: " << stulPar.height << std::endl;
        std::cout << "Длина: " << stulPar.length << std::endl;
    }
};
class Parta
{
public:
    Parametr partaPar;
    std::string name;
    Parta(double w, double h, double l, std::string n) : partaPar({w, h, l}), name(n) {}
    void display()
    {
        std::cout << "Имя предмета: " << name << std::endl;
        std::cout << "Ширина: " << partaPar.width << std::endl;
        std::cout << "Высота: " << partaPar.height << std::endl;
        std::cout << "Длина: " << partaPar.length << std::endl;
    }
};
class Monitor
{
public:
    bool monvkl;
    static int resX;
    static int resY;
    static int diag;
    std::string name;
    Monitor(bool v, std::string n) : monvkl(v), name(n) {}
    void display()
    {
        std::cout << "Имя предмета: " << name << std::endl;
        std::cout << "Разрешение экрана: " << resX << " на " << resY << " пикселей" << std::endl;
        std::cout << "Диагональ: " << diag << " дюймов" << std::endl;
        std::cout << (monvkl ? "Включен" : "Выключен") << std::endl;
    }
};
class PK
{
public:
    static std::string proc;
    static std::string vid;
    static int mem;
    static int ram;
    bool pkvkl;
    std::string name;
    PK(bool v, std::string n) : pkvkl(v), name(n) {}
    void display()
    {
        std::cout << "Имя предмета: " << name << std::endl;
        std::cout << "Процессор: " << proc << std::endl;
        std::cout << "Видеокарта: " << vid << std::endl;
        std::cout << "Постоянная память: " << mem << " Гб" << std::endl;
        std::cout << "Оперативная память: " << ram << " Гб" << std::endl;
        std::cout << (pkvkl ? "Включен" : "Выключен") << std::endl;
    }
};
class Bespoleznie
{
public:
    Parametr bespPar;
    std::string name;
    Bespoleznie(double w, double h, double l, std::string n) : bespPar({w, h, l}), name(n) {}
    void display()
    {
        std::cout << "Имя предмета: " << name << std::endl;
        std::cout << "Ширина: " << bespPar.width << std::endl;
        std::cout << "Высота: " << bespPar.height << std::endl;
        std::cout << "Длина: " << bespPar.length << std::endl;
    }
};
class Shkaf
{
public:
    Parametr shkafPar;
    std::string material;
    std::string name;
    Shkaf(double w, double h, double l, std::string m, std::string n) : shkafPar({w, h, l}), material(m), name(n) {}
    void display()
    {
        std::cout << "Имя предмета: " << name << std::endl;
        std::cout << "Материал: " << material << std::endl;
        std::cout << "Ширина: " << shkafPar.width << std::endl;
        std::cout << "Высота: " << shkafPar.height << std::endl;
        std::cout << "Длина: " << shkafPar.length << std::endl;
    }
};
/// Характеристики мониторов
int Monitor::resX = 3840;
int Monitor::resY = 2160;
int Monitor::diag = 27;
/// Характеристики самих блоков
std::string PK::proc = "Intel core i9 -12400F";
std::string PK::vid = "NVIDIA RTX 5090";
int PK::mem = 1024;
int PK::ram = 32;
int main()
{
          
}