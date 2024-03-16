#include <iostream>
#include <string>
#include <fstream>
#include <vector>
class Parametr
{
public:
    double length;
    double width;
    double height;
    int kolvo;
    std::string name;
    std::string material;
    std::string number;
    void display()
    {
        std::cout << "Предмет: " << name << "  Количество: " << kolvo << "  Размеры: "
                  << length << " x " << width << " x " << height << "  Материал: " << material;
        std::cout << "\n";
    }
    void getInf()
    {
        std::cout << "Количество объектов: ";
        std::cin >> kolvo;
        std::cout << "Материал объекта: ";
        std::cin >> material;
        std::cout << "Размеры: ";
        std::cin >> length >> width >> height;
    }
};
class ClassroomInv
{
private:
    std::vector<Parametr> registeredItems;
    std::vector<Parametr> unregisteredItems;

public:
    void addRegisteredItem(const Parametr &item)
    {
        registeredItems.push_back(item);
    }

    void addUnregisteredItem(const Parametr &item)
    {
        unregisteredItems.push_back(item);
    }
};
int main()
{
    setlocale(LC_ALL, "Rus");
    ClassroomInv inventory;
    std::cout << "Стулья:\n";
    Parametr stul;
    stul.name = "Стул";
    stul.getInf();
    inventory.addRegisteredItem(stul);
    stul.display();

    Parametr parta;
    std::cout << "Парты:\n";
    parta.name = "Парта";
    parta.getInf();
    inventory.addRegisteredItem(parta);
    parta.display();

    Parametr scaf;
    std::cout << "Шкафы:\n";
    scaf.name = "Шкаф";
    scaf.getInf();
    inventory.addRegisteredItem(scaf);
    scaf.display();
}