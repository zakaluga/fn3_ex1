#include <iostream>
#include <string>
class Parametr
{
public:
    double length;
    double width;
    double height;
    const int kolvo;
    std::string name;
    void display()
    {
        std::cout << "Предмет: " << name << "\tКоличество: " << kolvo << " шт\t"
                  << "Характеристики: " << length << " x " << width << " x " << height << "\n";
        std::cout << "\n";
    }
};
class Stul
{
public:
    Parametr stulPar;
    std::string &name = stulPar.name;
    Stul() : stulPar({50, 100, 50, 15, "Стул "}) {}
    Stul(double l, double w, double h, const int k, std::string n) : stulPar({w, h, l, k, n}) {}
    void display()
    {
        stulPar.display();
    };
};
class Parta
{
public:
    Parametr partaPar;
    std::string &name = partaPar.name;
    Parta() : partaPar({75, 100, 250, 10, "Парта "}) {}
    Parta(double w, double h, double l, const int k, std::string n) : partaPar({w, h, l, k, n}) {}
    void display()
    {
        partaPar.display();
    };
};
class PK
{
public:
    const int kolvo;
    bool pkvkl;
    int resX;
    int resY;
    int diag;
    int mem;
    int ram;
    std::string proc;
    std::string vid;
    std::string name;
    PK() : kolvo(15), resX(3840), resY(2160), diag(27), proc("Intel core i7-14700k"), vid("NVIDIA 4060"), mem(1024), ram(32), pkvkl(false), name("ПК ") {}
    PK(const int k, int x, int y, int d, std::string p, std::string v, int m, int r, bool vkl, std::string n) : kolvo(k), resX(x), resY(y), diag(d), proc(p), vid(v), mem(m), ram(r), pkvkl(vkl), name(n) {}
    void display()
    {
        std::cout << "Предмет: " << name << "\tКоличество: " << kolvo << " шт\t"
                  << "Разрешение экрана: " << resX << " x " << resX << "пикселей\t"
                  << "Диагональ: " << diag << " дюймов\t"
                  << "Постоянная память: " << mem << " ГБ\t"
                  << "Оперативная память: " << ram << " Гб\t"
                  << "Процессор: " << proc << "\tВидеокарта: " << vid << "\n";
        std::cout << "\n";
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
        std::cout << "Ширина: " << bespPar.width << " см\n";
        std::cout << "Высота: " << bespPar.height << " см\n";
        std::cout << "Длина: " << bespPar.length << " см\n";
    }
};
class Shkaf
{
public:
    Parametr shkafPar;
    std::string material;
    std::string name;
    Shkaf(double w, double h, double l, std::string m, std::string n) : shkafPar({w, h, l}), material(m), name(n) {}
};
template <typename T>
T *makeArr(const int kolvo)
{
    T *klass = new T[kolvo];
    return klass;
    for (int i = 0; i < kolvo; i++)
    {
        klass[i].name = klass[i].name + std::to_string(i + 1);
        klass[i].display();
    }
};
int main()
{
    Stul *stulArr = makeArr<Stul>(1);
    Parta *partaArr = makeArr<Parta>(5);
    stulArr[1].display();
    delete[] stulArr;
    delete[] partaArr;
}