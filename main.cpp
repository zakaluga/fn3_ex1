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
    Stul(double w, double h, double l) : stulPar({w, h, l}) {}
    void display()
    {
        std::cout << "Ширина: " << stulPar.width << std::endl;
        std::cout << "Высота: " << stulPar.height << std::endl;
        std::cout << "Длина: " << stulPar.length << std::endl;
    }
};
class Parta
{
public:
    Parametr partaPar;
    Parta(double w, double h, double l) : partaPar({w, h, l}) {}
    void display()
    {
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
    Monitor(bool v) : monvkl(v) {}
    void display()
    {
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
    PK(bool v) : pkvkl(v) {}
    void display()
    {
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
    Stul stul(1, 0.5, 0.75);
    stul.display();
    Parta parta(1, 1, 2.5);
    parta.display();
    Monitor monitor(true);
    monitor.display();
    PK pk(false);
    pk.display();
    Bespoleznie kartina(0.1, 0.5, 0.7, "Картина Эйнштейна");
    kartina.display();
}