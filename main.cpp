#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <locale>
#include <windows.h>
#include <map>
class AggregatedSettings
{
public:
    std::string size;
    int count;
    std::string name;
    std::string material;
    std::string number;
    std::string extraInf;
    void display()
    {
        std::cout << "Item name: " << name << "  Quantity: " << count << "  Size: "
                  << size << "  Material: " << material
                  << "  Extra information: " << extraInf;
        std::cout << "\n";
    }
    void getInf()
    {
        std::cout << "Enter item name: ";
        std::cin >> name;
        std::cout << "Number of items: ";
        std::cin >> count;
        if (count > 0)
        {
            std::cout << "Material of item: ";
            std::cin >> material;
            std::cout << "Size: ";
            std::cin.ignore();
            std::getline(std::cin, size);
            std::cout << "Extra information extraInf item: ";
            std::cin.ignore();
            std::getline(std::cin, extraInf);
        }
    }
    void addInToFile(std::ofstream &File)
    {
        File << "Item name: " << name << "  Quantity: " << count << "  Size: "
             << size << "  Material: " << material
             << "  Extra information: " << extraInf;
        File << "\n";
    }
};
class ClassroomInv
{
private:
    int tempCount;
    std::vector<AggregatedSettings> registeredItems;
    std::vector<AggregatedSettings> unregisteredItems;

public:
    void addRegisteredItem(const AggregatedSettings &item)
    {
        registeredItems.push_back(item);
    }
    void addUnregisteredItem(const AggregatedSettings &item)
    {
        unregisteredItems.push_back(item);
    }
    void deleteItems()
    {
        registeredItems.clear();
        unregisteredItems.clear();
    }
    void getTempCount()
    {
        std::cout << "Enter number of types registred items: ";
        std::cin >> tempCount;
    }
};
void Menu(int choice, std::map<std::string, AggregatedSettings> &item, std::ofstream &file)
{
    int i;
    AggregatedSettings temp;
    std::cout << "Меню:\n";
    std::cout << "1) Добавить стандартный предмет.\n";
    std::cout << "2) Добавить нестандартный предмет.\n";
    std::cout << "3) Изменить свойство выбранного предмета.\n";
    std::cout << "4) Изменить количество предметов выбранного типа.\n";
    std::cout << "5) Выйти из программы.\n";
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        temp.getInf();
        temp.addInToFile(file);
        item[temp.name] = temp;
        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;

    default:
        std::cout << "Такого пункта меню нет!";
        break;
    }
};
int main()
{
    std::map<std::string, AggregatedSettings> Regitems;
    int choise;
    setlocale(LC_ALL, "Russian");
    std::ofstream List("Result.txt");
    while (choise != 5)
    {
    }
    return 0;
}