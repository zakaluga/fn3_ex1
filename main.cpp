#include <iostream>

class Parametr
{
public:
    double width;
    double height;
    double length;
};
class Stul
{
public:
    Parametr stulPar;
    std::string name;
    Stul() : stulPar({0.5, 1, 0.5}), name("Стул ") {}
    Stul(double w, double h, double l, std::string n) : stulPar({w, h, l}), name(n) {}
    void display()
    {
        std::cout << "Имя предмета: " << name << std::endl;
        std::cout << "Ширина: " << stulPar.width << " м\n";
        std::cout << "Высота: " << stulPar.height << " м\n";
        std::cout << "Длина: " << stulPar.length << " м\n";
    }
};
class Parta
{
public:
    Parametr partaPar;
    std::string name;
    Parta(): partaPar({0.75, 1, 2.5}), name("Парта "){}
    Parta(double w, double h, double l, std::string n) : partaPar({w, h, l}), name(n) {}
    void display()
    {
        std::cout << "Имя предмета: " << name << std::endl;
        std::cout << "Ширина: " << partaPar.width << " м\n";
        std::cout << "Высота: " << partaPar.height << " м\n";
        std::cout << "Длина: " << partaPar.length << " м\n";
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
    Monitor() : monvkl(false), name("Монитор "){}
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
    PK() : pkvkl(false), name("Системный блок "){}
    PK(bool v, std::string n) : pkvkl(v), name(n) {}
    void display()
    {
        std::cout << "Имя предмета: " << name << std::endl;
        std::cout << "Процессор: " << proc << std::endl;
        std::cout << "Видеокарта: " << vid << std::endl;
        std::cout << "Постоянная память: " << mem << " Гб\n";
        std::cout << "Оперативная память: " << ram << " Гб\n";
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
        std::cout << "Ширина: " << bespPar.width << " м\n";
        std::cout << "Высота: " << bespPar.height << " м\n";
        std::cout << "Длина: " << bespPar.length << " м\n";
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
        std::cout << "Материал: " << material << " м\n";
        std::cout << "Ширина: " << shkafPar.width << " м\n";
        std::cout << "Высота: " << shkafPar.height << " м\n";
        std::cout << "Длина: " << shkafPar.length << " м\n";
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
    const int kolvoStulov = 33;
    const int kolvoPart = 20;
    const int kolvoMoniks = 15;
    Stul *stulya = new Stul[kolvoStulov];
    Parta *parts = new Parta[kolvoPart];
    Monitor *monitors = new Monitor[kolvoMoniks];
    PK *komps = new PK[kolvoMoniks];
    std::cout << "Список стульев:\n"; 
    for (int i = 0; i < kolvoStulov; i++)
    {
        stulya[i].name = stulya[i].name + std::to_string(i + 1);
        stulya[i].display();
    }
    std::cout << "\n";
    std::cout << "Список парт:\n";
    for (int i = 0; i < kolvoPart; i++)
    {
        parts[i].name = parts[i].name + std::to_string(i + 1);
        parts[i].display();
    }
    std::cout << "\n";
    std::cout << "Список мониторов:\n";
    for (int i = 0; i < kolvoMoniks; i++)
    {
        monitors[i].name = monitors[i].name + std::to_string(i + 1);
        monitors[i].display();
    }
    std::cout << "\n";
    std::cout << "Список системных блоков:\n";
    for (int i = 0; i < kolvoMoniks; i++)
    {
        komps[i].name = komps[i].name + std::to_string(i + 1);
        komps[i].display();
    }
}