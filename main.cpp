#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <cstdio>
class AggregatedSettings
{
public:
    std::string name;
    std::string size;
    std::string material;
    std::string extraInf;
    std::string location = "Classroom";
    void display()
    {
        std::cout << "Item name: " << name << " | Size: "
                  << size << " | Material: " << material << " | Location: " << location
                  << " | Extra information: " << extraInf << "\n";
    }
    void getedinf()
    {
        std::cin.ignore();
        std::cout << "Material of item: ";
        std::getline(std::cin, material);
        std::cout << "Size: ";
        std::getline(std::cin, size);
        std::cout << "Extra information extraInf item: ";
        std::getline(std::cin, extraInf);
    }
    void getnotedinf()
    {
        std::cout << "Enter information: ";
        std::getline(std::cin, extraInf);
    }
    void addInToFile(std::ofstream &File)
    {
        File << "Item name: " << name << " | Size: "
             << size << " | Material: " << material
             << " | Extra information: " << extraInf << "\n";
    }
    void addInToTempfile(std::fstream &File)
    {
        File << name << "\n";
        File << size << "\n";
        File << material << "\n";
        File << extraInf << "\n";
        File << location << "\n";
    }
    void clear()
    {
        name = "";
        size = "";
        material = "";
        extraInf = "";
        location = "Classroom";
    }
};
std::vector<std::string> makenumber(std::string name, int count)
{
    std::vector<std::string> temp;
    for (int i = 0; i < count; i++)
    {
        temp.push_back(name + std::to_string(i + 1));
    }
    return temp;
}
class ClassroomInventory
{
private:
    std::vector<AggregatedSettings> items;

public:
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
            file.ignore();
            getline(file, temp.size);
            getline(file, temp.material);
            getline(file, temp.extraInf);
            getline(file, temp.location);
            map[temp.name] = temp;
            if (!temp.name.empty())
            {
                gg.push_back(temp.name);
                map[temp.name].display();
            }
        }
    }
    std::cout << "\n";
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
bool correct(std::string x)
{
    std::vector<std::string> right;
    for (int i = 0; i < 7; i++)
    {
        right.push_back(std::to_string(i + 1));
    }
    for (int i = 0; i < 7; i++)
    {
        if (x == right[i])
        {
            return true;
            break;
        }
    }
    return false;
}
void Menu(ClassroomInventory &inventory)
{
    std::vector<std::string> numbers;
    int tempcount;
    std::string tempname;
    int choiseForCase3;
    std::vector<std::ofstream> files;
    std::string tempchoice;
    int choice;
    std::vector<std::string> names;
    std::map<std::string, AggregatedSettings> items;
    std::ofstream file("Result.txt");
    std::fstream tempfile("DON'T_CLICK_HERE.txt", std::ios::out | std::ios::in);
    AggregatedSettings temp;
    std::string choosenName;
    std::string deletename;
    scanfile(tempfile, items, names);
    tempfile.close();
    tempfile.open("DON'T_CLICK_HERE.txt", std::ios::out | std::ios::in | std::ios::trunc);
    while (choice != 7)
    {
        std::cout << "\n";
        std::cout << "Menu:\n";
        std::cout << "1) Add educational item.\n";
        std::cout << "2) Add NOT educational item.\n";
        std::cout << "3) Change setting of item.\n";
        std::cout << "4) Delete all items.\n";
        std::cout << "5) Delete choosen item\n";
        std::cout << "6) Display all items\n";
        std::cout << "7) Exit.\n";
        std::getline(std::cin, tempchoice);
        while (!correct(tempchoice))
        {
            std::cout << "Wrong point, try again\n";
            std::getline(std::cin, tempchoice);
        }
        choice = std::stoi(tempchoice);
        switch (choice)
        {
        case 1:
            std::cout << "Enter name of item: ";
            std::cin >> tempname;
            std::cout << "Enter number of items: ";
            std::cin >> tempcount;
            numbers = makenumber(tempname, tempcount);
            while (findItem(names, numbers[0]))
            {
                std::cout << "Such a name has already been found, come up with a new one\n";
                std::cin >> tempname;
                numbers = makenumber(tempname, tempcount);
            }
            temp.getedinf();
            for (int i = 0; i < tempcount; i++)
            {
                temp.name = numbers[i];
                items[temp.name] = temp;
                names.push_back(temp.name);
            }
            temp.clear();
            break;
        case 2:
            std::cout << "Enter name of item: ";
            std::cin >> tempname;
            std::cout << "Enter number of items: ";
            std::cin >> tempcount;
            numbers = makenumber(tempname, tempcount);
            while (findItem(names, numbers[0]))
            {
                std::cout << "Such a name has already been found, come up with a new one\n";
                std::cin >> tempname;
                numbers = makenumber(tempname, tempcount);
            }
            temp.getnotedinf();
            for (int i; i < tempcount; i++)
            {
                temp.name = numbers[i];
                items[temp.name] = temp;
                names.push_back(temp.name);
            }
            temp.clear();
            break;
        case 3:
            std::cout << "Which item will be changed: ";
            std::getline(std::cin, choosenName);
            if (findItem(names, choosenName))
            {
                std::cout << "Which setting you want to change?\n";
                std::cout << "1) Size\n";
                std::cout << "2) Material\n";
                std::cout << "3) Extra information\n";
                std::cout << "4) Exit\n";
                std::getline(std::cin, tempchoice);
                while (!correct(tempchoice))
                {
                    std::cout << "Wrong point, try again\n";
                    std::getline(std::cin, tempchoice);
                }
                choiseForCase3 = std::stoi(tempchoice);
                switch (choiseForCase3)
                {
                case 1:
                    std::cout << "Enter new size: ";
                    std::getline(std::cin, items[choosenName].size);
                    break;
                case 2:
                    std::cout << "Enter new material: ";
                    std::getline(std::cin, items[choosenName].material);
                    break;
                case 3:
                    std::cout << "Enter new extra information: ";
                    std::getline(std::cin, items[choosenName].extraInf);
                    break;
                case 4:
                    break;
                }
                break;
            }
            else
            {
                std::cout << "Wrong name\n";
                break;
            }
            break;

        case 4:
            for (int i = 0; i < names.size(); i++)
            {
                std::remove((names[i] + ".txt").c_str());
            }
            file.clear();
            tempfile.clear();
            items.clear();
            names.clear();
            break;
        case 5:
            std::cout << "Which item will be deleted?: ";
            std::getline(std::cin, deletename);
            if (findItem(names, deletename))
            {
                items[deletename].clear();
                for (auto it = names.begin(); it != names.end(); ++it)
                {
                    if (*it == deletename)
                    {
                        names.erase(it);
                        break;
                    }
                }
            }
            else
            {
                std::cout << "Wrong name\n";
                break;
            }
            break;
        case 6:
            for (int i = 0; i < names.size(); i++)
            {
                items[names[i]].display();
            }
            break;
        case 7:
            for (int i = 0; i < names.size(); i++)
            {
                inventory.addItems(items[names[i]]);
            }
            inventory.addInToFile(file, tempfile);
            file.close();
            tempfile.close();
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