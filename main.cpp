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
    std::string about;
    void display()
    {
        std::cout << "Item name: " << name << "  Quantity: " << kolvo << "  Size: "
                  << length << " x " << width << " x " << height << "  Material: " << material
                  << "  Extra information: " << about;
        std::cout << "\n";
    }
    void getInf()
    {
        std::cout << "Enter item name: ";
        std::cin >> name;
        std::cout << "Number of items: ";
        std::cin >> kolvo;
        if (kolvo > 0)
        {
            std::cout << "Material of item: ";
            std::cin >> material;
            std::cout << "Size: ";
            std::cin >> length >> width >> height;
            std::cout << "Extra information about item: ";
            std::cin.ignore();
            std::getline(std::cin, about);
        }
    }
    void addInToFile(std::ofstream &File)
    {
        File << "Item name: " << name << "  Quantity: " << kolvo << "  Size: "
             << length << " x " << width << " x " << height << "  Material: " << material
             << "  Extra information: " << about;
        File << "\n";
    }
};
class ClassroomInv
{
private:
    int tempCount;
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
    void fillTempArr(ClassroomInv inv, std::ofstream &File)
    {
        Parametr *tempArr = new Parametr[tempCount];
        for (int i = 0; i < tempCount; i++)
        {
            tempArr[i].getInf();
            inv.addRegisteredItem(tempArr[i]);
            tempArr[i].addInToFile(File);
        }
        delete[] tempArr;
    }
};
int main()
{
    std::ofstream List("Result.txt");
    List.clear();
    int unregTypeCount;
    ClassroomInv inventory;

    std::cout << "Registred items:\n";
    inventory.getTempCount();
    inventory.fillTempArr(inventory, List);

    std::cout << "How many types of unregistered items will you have? ";
    std::cin >> unregTypeCount;

    if (unregTypeCount > 0)
    {
        Parametr unreg;
        Parametr *unregitems = new Parametr[unregTypeCount];
        for (int i = 0; i < unregTypeCount; i++)
        {
            unregitems[i].getInf();
            inventory.addUnregisteredItem(unregitems[i]);
            unregitems[i].addInToFile(List);
        }
        delete[] unregitems;
    }
    List.close();
    inventory.deleteItems();
    return 0;
}