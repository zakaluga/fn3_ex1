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
        std::cout << "Item name: " << name << " | Number: " << count << " | Size: "
                  << size << " | Material: " << material
                  << " | Extra information: " << extraInf;
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
        File << "Item name: " << name << " | Number: " << count << " | Size: "
             << size << " | Material: " << material
             << " | Extra information: " << extraInf;
        File << "\n";
    }
};
class ClassroomInventory
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
    void addInToFile(std::ofstream &file)
    {
        file << "Common items:\n";
        for (int i = 0; i < registeredItems.size(); ++i)
        {
            registeredItems[i].addInToFile(file);
        };
        file << "Unusuall items:\n";
        for (int i = 0; i < unregisteredItems.size(); ++i)
        {
            unregisteredItems[i].addInToFile(file);
        }
    }
};
void Menu(int &choice, std::map<std::string, AggregatedSettings> &item, std::ofstream &file, ClassroomInventory &inventory)
{
    static int i = 0;
    AggregatedSettings temp;
    std::string choosenName;
    int choiseForCase3;
    std::cout << "Menu:\n";
    std::cout << "1) Add standart item.\n";
    std::cout << "2) Add unusual item.\n";
    std::cout << "3) Change setting of item.\n";
    std::cout << "4) Clean file.\n";
    std::cout << "5) Exit.\n";
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        temp.getInf();
        item[temp.name] = temp;
        inventory.addRegisteredItem(temp);
        i++;
        break;
    case 2:
        temp.getInf();
        item[temp.name] = temp;
        inventory.addUnregisteredItem(temp);
        i++;
        break;
    case 3:
        std::cout << "Which item will be changed: ";
        std::cin >> choosenName;
        std::cout << "Which setting you want to change?\n";
        std::cout << "1) Number of items\n";
        std::cout << "2) Size\n";
        std::cout << "3) Material\n";
        std::cout << "4) Extra information\n";
        std::cout << "5) Exit\n";
        std::cin >> choiseForCase3;
        switch (choiseForCase3)
        {
        case 1:
            std::cout << "Enter new count: ";
            std::cin >> item[choosenName].count;
            break;
        case 2:
            std::cout << "Enter new size: ";
            std::cin >> item[choosenName].size;
            break;
        case 3:
            std::cout << "Enter new material: ";
            std::cin >> item[choosenName].material;
            break;
        case 4:
            std::cout << "Enter new extra information: ";
            std::cin.ignore();
            std::getline(std::cin, item[choosenName].extraInf);
            break;
        case 5:
            break;

        default:
            std::cout << "No match!";
            break;
        }

        break;
    case 4:
        file.clear();
        break;

    case 5:
        inventory.addInToFile(file);
        break;

    default:
        std::cout << "No match!";
        break;
    }
};
int main()
{
    ClassroomInventory inventory;
    std::map<std::string, AggregatedSettings> Items;
    int choise;
    std::ofstream File("Result.txt");
    while (choise != 5)
    {
        Menu(choise, Items, File, inventory);
    }
    File.close();
    return 0;
}