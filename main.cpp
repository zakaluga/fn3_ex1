#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <locale>
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
    std::string about;
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
        if (kolvo > 0)
        {
            std::cout << "Материал объекта: ";
            std::cin >> material;
            std::cout << "Размеры: ";
            std::cin >> length >> width >> height;
        }
    }
    void getUnreg()
    {
        getInf();
        std::cout << "Дополнительная информация об объекте: ";
        std::cin >> about;
    }
    void addInToFile(std::ofstream &File)
    {
        File << "Предмет: " << name << "   Количество: " << kolvo << "   Размеры: "
             << length << " x " << width << " x " << height << "   Материал: " << material;
        File << "\n";
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
    setlocale(LC_ALL, "Ru");
    std::ofstream List("Result.txt");
    List.clear();
    int unregTypeCount;
    ClassroomInv inventory;

    std::cout << "Стулья:\n";
    Parametr stul;
    stul.name = "Стул";
    stul.getInf();
    inventory.addRegisteredItem(stul);
    stul.addInToFile(List);

    Parametr parta;
    std::cout << "Парты:\n";
    parta.name = "Парта";
    parta.getInf();
    inventory.addRegisteredItem(parta);
    parta.addInToFile(List);

    Parametr scaf;
    std::cout << "Шкафы:\n";
    scaf.name = "Шкаф";
    scaf.getInf();
    inventory.addRegisteredItem(scaf);
    scaf.addInToFile(List);
    
    std::cout << "Сколько типов незарегистрированных объектов у вас будет? ";
    std::cin >> unregTypeCount;

    if (unregTypeCount > 0)
    {
        Parametr unreg;
        Parametr unregitems[unregTypeCount];
        for (int i = 0; i < unregTypeCount; i++)
        {
            unregitems[i].getUnreg();
            inventory.addUnregisteredItem(unregitems[i]);
            unregitems[i].addInToFile(List);
        }
        delete[] unregitems;
    }
    List.close();
    return 0;
}