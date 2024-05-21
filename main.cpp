#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <cstdio>
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
bool correct(std::string x, int n)
{
    std::vector<std::string> right;
    for (int i = 0; i < n; i++)
    {
        right.push_back(std::to_string(i + 1));
    }
    for (int i = 0; i < n; i++)
    {
        if (x == right[i])
        {
            return true;
            break;
        }
    }
    return false;
}
class AggregatedSettings
{
public:
    int funcscounter;
    std::string name;
    std::string size;
    std::string material;
    std::string extraInf;
    std::string location = "Classroom";
    std::string number;
    std::map<std::string, std::string> functions;
    std::vector<std::string> funcnames;
    void display()
    {
        std::cout << "Item name: " << name << " | Size: "
                  << size << " | Material: " << material << " | Location: " << location
                  << " | Tag: " << number << " | Extra information: " << extraInf << "\n";
        if (funcscounter != 0)
        {
            std::cout << "Functions: \n";
            for (int i = 0; i < funcscounter; i++)
            {
                std::cout << funcnames[i] << ": " << functions[funcnames[i]] << "\n";
            }
        }
    }
    void getfuncs()
    {
        std::string funcname;
        std::string deletename;
        std::string changename;
        std::string funcvalue;
        int choice;
        std::string tempchoice;
        while (choice != 5)
        {
            std::cout << "\n";
            std::cout << "1) Add new function\n";
            std::cout << "2) Change function value\n";
            std::cout << "3) Delete concrete function\n";
            std::cout << "4) Delete all function\n";
            std::cout << "5) Exit\n";
            std::getline(std::cin, tempchoice);
            while (!correct(tempchoice, 5))
            {
                std::cout << "Wrong point, try again\n";
                std::getline(std::cin, tempchoice);
            }
            choice = std::stoi(tempchoice);
            switch (choice)
            {
            case 1:
                funcname.clear();
                funcvalue.clear();
                std::cout << "Enter function name: ";
                std::getline(std::cin, funcname);
                while (findItem(funcnames, funcname))
                {
                    std::cout << "Such a name already exists come up with a new one: ";
                    std::getline(std::cin, funcname);
                }
                std::cout << "Enter function value: ";
                std::getline(std::cin, funcvalue);
                functions[funcname] = funcvalue;
                funcnames.push_back(funcname);

                break;
            case 2:
                std::cout << "Which function will be changed: ";
                std::getline(std::cin, changename);
                if (findItem(funcnames, changename))
                {
                    std::cout << "New function value: ";
                    std::getline(std::cin, functions[changename]);
                }
                else
                {
                    std::cout << "Wrong function name\n";
                    break;
                }
                break;
                break;
            case 3:
                if (findItem(funcnames, deletename))
                {
                    functions[deletename].clear();
                    for (auto it = funcnames.begin(); it != funcnames.end(); ++it)
                    {
                        if (*it == deletename)
                        {
                            funcnames.erase(it);
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
            case 4:
                functions.clear();
                funcnames.clear();
                break;
            case 5:
                funcscounter = functions.size();
                break;

            default:
                std::cout << "Wrong point, try again\n";
                break;
            }
        }
    }
    void getedinf()
    {
        std::cin.ignore();
        std::cout << "Material of item: ";
        std::getline(std::cin, material);
        std::cout << "Size: ";
        std::getline(std::cin, size);
        std::cout << "Location of item: ";
        std::getline(std::cin, location);
        std::cout << "Tag of item: ";
        std::getline(std::cin, number);
        std::cout << "Extra information: ";
        std::getline(std::cin, extraInf);
    }
    void getnotedinf()
    {

        std::cin.ignore();
        std::cout << "Tag of item: ";
        std::getline(std::cin, number);
        std::cout << "Enter information: ";
        std::getline(std::cin, extraInf);
        getfuncs();
    }
    void addInToFile(std::ofstream &File)
    {
        File << "Item name: " << name << " | Size: "
             << size << " | Material: " << material << " | Location: " << location << " | Tag: " << number
             << " | Extra information: " << extraInf << "\n";
        if (funcscounter != 0)
        {
            File << "Functions: \n";
            for (int i = 0; i < funcscounter; i++)
            {
                File << funcnames[i] << ": " << functions[funcnames[i]] << "\n";
            }
        }
    }
    void addInToTempfile(std::fstream &File)
    {
        File << name << "\n";
        File << size << "\n";
        File << material << "\n";
        File << location << "\n";
        File << number << "\n";
        File << extraInf << "\n";
        File << funcscounter << "\n";
        for (int i = 0; i < funcscounter; i++)
        {
            File << funcnames[i] << "\n"
                 << functions[funcnames[i]] << "\n";
        }
    }
    void clear()
    {
        name.clear();
        size.clear();
        material.clear();
        extraInf.clear();
        location = "Classroom";
        number.clear();
        functions.clear();
        funcnames.clear();
        funcscounter = 0;
    }
};
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
    std::string line1;
    std::string line;
    std::string funcname;
    std::string funcvalue;
    if (file.is_open())
    {
        file.seekg(0);
        while (getline(file, line))
        {
            AggregatedSettings temp;
            temp.name = line;
            getline(file, temp.size);
            getline(file, temp.material);
            getline(file, temp.location);
            getline(file, temp.number);
            getline(file, temp.extraInf);
            getline(file, line1);
            temp.funcscounter = std::stoi(line1);
            for (int i = 0; i < temp.funcscounter; i++)
            {
                getline(file, funcname);
                getline(file, funcvalue);
                temp.functions[funcname] = funcvalue;
                temp.funcnames.push_back(funcname);
            }
            map[temp.number] = temp;
            if (!temp.name.empty())
            {
                gg.push_back(temp.number);
                map[temp.number].display();
            }
        }
    }
    std::cout << "\n";
}

void Menu(ClassroomInventory &inventory)
{
    std::string choice7;
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
    while (choice != 9)
    {
        std::cout << "\n";
        std::cout << "Menu:\n";
        std::cout << "1) Add educational item.\n";
        std::cout << "2) Add NOT educational item.\n";
        std::cout << "3) Change setting of item.\n";
        std::cout << "4) Delete all items.\n";
        std::cout << "5) Delete choosen item\n";
        std::cout << "6) Display all items\n";
        std::cout << "7) Change functions\n";
        std::cout << "8) Save in to file\n";
        std::cout << "9) Exit.\n";
        std::getline(std::cin, tempchoice);
        while (!correct(tempchoice, 9))
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
            for (int i = 0; i < tempcount; i++)
            {
                temp.name = tempname;
                temp.getedinf();
                items[temp.number] = temp;
                names.push_back(temp.number);
            }
            temp.clear();
            break;
        case 2:
            std::cout << "Enter name of item: ";
            std::cin >> tempname;
            std::cout << "Enter number of items: ";
            std::cin >> tempcount;
            for (int i = 0; i < tempcount; i++)
            {
                temp.name = tempname;
                temp.getnotedinf();
                items[temp.number] = temp;
                names.push_back(temp.number);
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
                while (!correct(tempchoice, 4))
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
            std::cout << "Which item will be changed: ";
            std::getline(std::cin, choice7);
            if (findItem(names, choice7))
            {
                items[choice7].getfuncs();
            }
            else
            {
                std::cout << "Wrong function name\n";
                break;
            }
            break;
        case 8:
            for (int i = 0; i < names.size(); i++)
            {
                inventory.addItems(items[names[i]]);
            }
            inventory.addInToFile(file, tempfile);
            file.close();
            tempfile.close();
            break;
        case 9:
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