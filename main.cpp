#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
class AggregatedSettings
{
public:
    int count;
    std::string name;
    std::string size;
    std::string material;
    std::string extraInf;
    std::map<std::string, std::string> func;
    void display()
    {
        std::cout << "Item name: " << name << " | Number: " << count << " | Size: "
                  << size << " | Material: " << material
                  << " | Extra information: " << extraInf;
        std::cout << "\n";
    }
    void noteddisplay()
    {
        std::cout << "Item name: " << name << " | Number: " << count << " | Extra information: " << extraInf;
        std::cout << "\n";
    }
    void getinf()
    {
        std::cout << "Enter item name: ";
        std::cin >> name;
        std::cout << "Number of items: ";
        std::cin >> count;
        if (count > 0)
        {
            std::cout << "Material of item: ";
            std::cin.ignore();
            std::getline(std::cin, material);
            std::cout << "Size: ";
            std::getline(std::cin, size);
            std::cout << "Extra information extraInf item: ";
            std::getline(std::cin, extraInf);
        }
    }
    void getnotedinf()
    {
        std::cout << "Enter item name: ";
        std::cin >> name;
        std::cout << "Number of items: ";
        std::cin >> count;
        std::cout << "Enter information: ";
        std::cin.ignore();
        std::getline(std::cin, extraInf);
    }
    void addInToFile(std::ofstream &File)
    {
        File << "Item name: " << name << " | Number: " << count << " | Size: "
             << size << " | Material: " << material
             << " | Extra information: " << extraInf;
        File << "\n";
    }
    void addInToTempfile(std::fstream &File)
    {
        File << name << "\n";
        File << count << "\n";
        File << size << "\n";
        File << material << "\n";
        File << extraInf << "\n";
    }
    void clear()
    {
        count = 0;
        name = "";
        size = "";
        material = "";
        extraInf = "";
    }
};
class ClassroomInventory
{
public:
    int tempCount;
    std::vector<AggregatedSettings> items;
    void addItems(const AggregatedSettings &item)
    {
        items.push_back(item);
    }
    void addInToFile(std::ofstream &file, std::fstream &tempfile)
    {
        for (int i = 0; i < items.size(); ++i)
        {
            items[i].addInToFile(file);
            items[i].addInToTempfile(tempfile);
        };
    }
};
void scanfile(std::fstream &file, std::map<std::string, AggregatedSettings> &map, std::vector<std::string> &gg)
{
    AggregatedSettings temp;
    std::string line;
    if (file.is_open())
    {
        file.seekg(0);
        while (getline(file, line))
        {
            temp.name = line;
            file >> temp.count;
            file.ignore();
            getline(file, temp.size);
            getline(file, temp.material);
            getline(file, temp.extraInf);
            map[temp.name] = temp;
            if (!temp.name.empty())
            {
                gg.push_back(temp.name);
                map[temp.name].display();
            }
        }
    }
}
bool findItem(std::vector<std::string> vect, std::string name)
{
    for (int i = 0; i < vect.size(); i++)
    {
        if (name == vect[i])
        {
            return true;
            break;
        }
    }
    return false;
}

void Menu(ClassroomInventory &inventory)
{
    int choice;
    std::vector<std::string> gg;
    std::map<std::string, AggregatedSettings> items;
    std::ofstream file("Result.txt");
    std::fstream tempfile("DON'T_CLICK_HERE.txt", std::ios::out | std::ios::in);
    AggregatedSettings temp;
    std::string choosenName;
    std::string deletename;
    scanfile(tempfile, items, gg);
    tempfile.close();
    tempfile.open("DON'T_CLICK_HERE.txt", std::ios::out | std::ios::in | std::ios::trunc);
    while (choice != 7)
    {
        int choiseForCase3;
        std::cout << "Menu:\n";
        std::cout << "1) Add study item.\n";
        std::cout << "2) Add not educational item.\n";
        std::cout << "3) Change setting of reg item.\n";
        std::cout << "4) Delete all items.\n";
        std::cout << "5) Delete choosen item\n";
        std::cout << "6) Display all items\n";
        std::cout << "7) Exit.\n";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            temp.getinf();
            if (temp.count > 0)
            {
                items[temp.name] = temp;
                gg.push_back(temp.name);
                temp.clear();
            }
            break;
        case 2:
            temp.getnotedinf();
            if (temp.count > 0)
            {
                items[temp.name] = temp;
                gg.push_back(temp.name);
                temp.clear();
            }
            break;
        case 3:
            std::cout << "Which item will be changed: ";
            std::cin >> choosenName;
            if (findItem(gg, choosenName))
            {
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
                    std::cin >> items[choosenName].count;
                    break;
                case 2:
                    std::cout << "Enter new size: ";
                    std::cin.ignore();
                    std::getline(std::cin, items[choosenName].size);
                    break;
                case 3:
                    std::cout << "Enter new material: ";
                    std::cin.ignore();
                    std::getline(std::cin, items[choosenName].material);
                    break;
                case 4:
                    std::cout << "Enter new extra information: ";
                    std::cin.ignore();
                    std::getline(std::cin, items[choosenName].extraInf);
                    break;
                case 5:
                    break;

                default:
                    std::cout << "No match!\n";
                    break;
                }
                break;
            }
            else
            {
                std::cout << "Wrong name\n";
            }

        case 4:
            file.clear();
            tempfile.clear();
            items.clear();
            break;
        case 5:
            std::cout << "Which item will be deleted?: ";
            std::cin >> deletename;
            if (findItem(gg, deletename))
            {
                items[deletename].clear();
                for (auto it = gg.begin(); it != gg.end(); ++it)
                {
                    if (*it == deletename)
                    {
                        gg.erase(it);
                        break;
                    }
                }
            }
            break;
        case 6:
            for (int i = 0; i < gg.size(); i++)
            {
                items[gg[i]].display();
            }
            break;

        case 7:
            for (int i = 0; i < gg.size(); i++)
            {
                inventory.addItems(items[gg[i]]);
            }
            inventory.addInToFile(file, tempfile);
            file.close();
            tempfile.close();
            break;

        default:
            std::cout << "No match!\n";
            break;
        }
    }
};
int main()
{
    ClassroomInventory inventory;
    Menu(inventory);
    return 0;
}