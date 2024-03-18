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
                  << length << " x " << width << " x " << height << "  Material: " << material;
        std::cout << "\n";
    }
    void getInf()
    {
        std::cout << "Number of items: ";
        std::cin >> kolvo;
        if (kolvo > 0)
        {
            std::cout << "Material of item: ";
            std::cin >> material;
            std::cout << "Size: ";
            std::cin >> length >> width >> height;
        }
    }
    void getUnreg()
    {
        getInf();
        std::cout << "Extra information about item: ";
        std::cin >> about;
    }
    void addInToFile(std::ofstream &File)
    {
        File << "Item name: " << name << "  Quantity: " << kolvo << "  Size: "
                  << length << " x " << width << " x " << height << "  Material: " << material;
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
    void deleteItems(){
        registeredItems.clear();
        unregisteredItems.clear();
    }
};
int main()
{
    std::ofstream List("Result.txt");
    List.clear();
    int unregTypeCount;
    ClassroomInv inventory;
    std::cout << "Registred items:\n";

    std::cout << "Chairs:\n";
    Parametr stul;
    stul.name = "Chair";
    stul.getInf();
    inventory.addRegisteredItem(stul);
    stul.addInToFile(List);

    Parametr parta;
    std::cout << "Desks:\n";
    parta.name = "Dessk";
    parta.getInf();
    inventory.addRegisteredItem(parta);
    parta.addInToFile(List);

    Parametr scaf;
    std::cout << "Wardrobes:\n";
    scaf.name = "Wardrobe";
    scaf.getInf();
    inventory.addRegisteredItem(scaf);
    scaf.addInToFile(List);

    Parametr board;
    std::cout << "Boards:\n";
    board.name = "Board";
    board.getInf();
    inventory.addRegisteredItem(board);
    board.addInToFile(List);
    
    std::cout << "How many types of unregistered items will you have? ";
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
    inventory.deleteItems();
    return 0;
}