#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <tuple>
#include <cctype>
#include<fstream>

class Laptop
{
public:
    Laptop(int EffVal, int ClockVal, int CapVal) : efficiency(EffVal), ProcessorClockFrequency(ClockVal), ProcessorCapacity(CapVal)
    {
        curSerialNumber = serialNumber;
        serialNumber++;
    }
    Laptop()
    {
        curSerialNumber = serialNumber;
        serialNumber++;
    }
    ~Laptop()
    {
        serialNumber--;
    };

    int GetEfficienty()
    {
        return this->efficiency;
    }

    void SetEfficienty(int val)
    {
        this->efficiency = val;
    }

    int GetProcessorClockFrequency()
    {
        return this->ProcessorClockFrequency;
    }

    void SetProcessorClockFrequency(int val)
    {
        this->ProcessorClockFrequency = val;
    }

    int GetProcessorCapacity()
    {
        return this->ProcessorCapacity;
    }

    void SetProcessorCapacity(int val)
    {
        this->ProcessorCapacity = val;
    }

    template <class T>
    void addLaptop(std::vector<T> &inf)
    {
        inf.push_back(*this);
    }

    int curSerialNumber;

private:
    int efficiency = 0;
    int ProcessorClockFrequency = 0;
    int ProcessorCapacity = 0;
    static inline int serialNumber{};
};

class Parameter
{
public:
    Parameter(std::string on, std::string subscr, std::string wtd) : objectName(on), subscription(subscr), whatToDo(wtd){};
    Parameter() = default;
    ~Parameter() = default;
    std::string getObjectName()
    {
        return this->objectName;
    }
    void setObjectName(std::string &str)
    {
        this->objectName = str;
    }

    std::string getWhatToDo()
    {
        return this->whatToDo;
    }

    void setWhatToDo(std::string &str)
    {
        this->whatToDo = str;
    }

    std::string getSubscription()
    {
        return this->subscription;
    }

    void setSubscription(std::string &str)
    {
        this->subscription = str;
    }
    template <class T>
    void addParam(std::vector<T> &inf)
    {
        inf.push_back(*this);
    }

private:
    std::string objectName;
    std::string whatToDo;
    std::string subscription;
};
class Table
{
public:
    Table(int h, int len, int wd, int w, std::string mat) : height(h), weight(w), lenght(len), width(wd), material(mat)
    {
        curSerialNumber = serialNumber;
        serialNumber++;
    }
    Table()
    {
        curSerialNumber = serialNumber;
        serialNumber++;
    };
    ~Table()
    {
        serialNumber--;
    }

    int GetHeight()
    {
        return this->height;
    }

    void SetHeight(int val)
    {
        this->height = val;
    }

    int GetWeight()
    {
        return this->weight;
    }

    void SetWeight(int val)
    {
        this->weight = val;
    }

    int GetLenght()
    {
        return this->lenght;
    }

    void SetLenght(int val)
    {
        this->lenght = val;
    }

    int GetWidth()
    {
        return this->width;
    }

    void SetWidth(int val)
    {
        this->width = val;
    }

    std::string GetMaterial()
    {
        return this->material;
    }

    void SetMaterial(std::string val)
    {
        this->material = val;
    }

    template <class T>
    void addTable(std::vector<T> &inf)
    {
        inf.push_back(*this);
    }
    int curSerialNumber;

private:
    int height = 0;
    int lenght = 0;
    int width = 0;
    int weight = 0;
    static inline int serialNumber{};

    std::string material = "";
};

class Book
{
public:
    Book(int k, int pn) : kol(k), pageNumber(pn)
    {
        curSerialNumber = serialNumber;
        serialNumber++;
    }
    Book()
    {
        curSerialNumber = serialNumber;
        serialNumber++;
    }
    ~Book()
    {
        serialNumber--;
    }

    int GetKol()
    {
        return this->kol;
    }

    void SetKol(int val)
    {
        this->kol = val;
    }

    int GetPageNumber()
    {
        return this->pageNumber;
    }

    void SetPageNumber(int val)
    {
        this->pageNumber = val;
        if (val > 0)
        {
            this->Isnew = false;
        }
        else
        {
            this->Isnew = true;
        }
    }

    void MakeUsed()
    {
        this->Isnew = false;
    }

    bool GetIsnew()
    {
        return this->Isnew;
    }

    template <class T>
    void addBook(std::vector<T> &inf)
    {
        inf.push_back(*this);
    }
    int curSerialNumber;

private:
    int kol = 0;
    int pageNumber = 0;
    bool Isnew = true;
    static inline int serialNumber{};
};

bool Digit(const std::string s)
{
    bool ans = true;
    for (int i = 0; i < s.length(); ++i)
    {
        ans = ans && std::isdigit(s[i]);
    }
    return ans;
}

void intCheck(int &value)
{
    std::string valuestr;
    std::cin >> valuestr;
    if (Digit(valuestr))
    {
        value = std::stoi(valuestr);
    }
    else
    {
        while (!Digit(valuestr))
        {
            std::cout << "Enter value: ";
            std::cin >> valuestr;
        }
        value = std::stoi(valuestr);
    }
}

template <class T, class U>
std::map<T, std::vector<U>> inf;

// 1 показать все
// 2 добавить элемент
// 3 очистить все
// 4 записать в файл
// 5 загрузить из файла
// 6 выйти без сохранения

int main()
{
    std::ifstream fin;
    fin.open("classes_information.txt", std::ios::in);
    std::string currentLine;
    std::string keyName;
    std::vector<int> spaces;
    while (std::getline(fin, currentLine))
    {
        if (currentLine.find(" ") == currentLine.rfind(" "))
        {
            keyName = currentLine.substr(currentLine.find(" ") + 1, 50);
        }
        else
        {
            if (keyName == "Laptop")
            {
                Laptop *fileLaptop = new Laptop();
                for (int i = 0; i < currentLine.length(); i++)
                {
                    if (currentLine[i] == ' ')
                    {
                        spaces.push_back(i);
                    }
                }
                int fileef = std::stoi(currentLine.substr(0, spaces[0]));
                int filecl = std::stoi(currentLine.substr(spaces[0] + 1, spaces[1] - spaces[0] - 1));
                int filecap = std::stoi(currentLine.substr(spaces[1] + 1, spaces[2] - spaces[1] - 1));
                fileLaptop->SetEfficienty(fileef);
                fileLaptop->SetProcessorCapacity(filecap);
                fileLaptop->SetProcessorClockFrequency(filecl);
                fileLaptop->addLaptop(inf<std::string, Laptop>["Laptop"]);
                spaces.clear();
            }
            if (keyName == "Table")
            {
                Table *fileTable = new Table();
                for (int i = 0; i < currentLine.length(); i++)
                {
                    if (currentLine[i] == ' ')
                    {
                        spaces.push_back(i);
                    }
                }
                int filehigh = std::stoi(currentLine.substr(0, spaces[0]));
                int filelen = std::stoi(currentLine.substr(spaces[0] + 1, spaces[1] - spaces[0] - 1));
                int filewid = std::stoi(currentLine.substr(spaces[1] + 1, spaces[2] - spaces[1] - 1));
                int fileweight = std::stoi(currentLine.substr(spaces[2] + 1, spaces[3] - spaces[2] - 1));
                std::string filemat = currentLine.substr(spaces[3] + 1, spaces[4] - spaces[3] - 1);
                fileTable->SetHeight(filehigh);
                fileTable->SetLenght(filelen);
                fileTable->SetWidth(filewid);
                fileTable->SetWeight(fileweight);
                fileTable->SetMaterial(filemat);
                fileTable->addTable(inf<std::string, Table>["Table"]);
                spaces.clear();
            }
            if (keyName == "Book")
            {
                Book *fileBook = new Book();
                for (int i = 0; i < currentLine.length(); i++)
                {
                    if (currentLine[i] == ' ')
                    {
                        spaces.push_back(i);
                    }
                }
                int filekol = std::stoi(currentLine.substr(0, spaces[0]));
                int filecurPage = std::stoi(currentLine.substr(spaces[0] + 1, spaces[1] - spaces[0] - 1));
                int fileNew = std::stoi(currentLine.substr(spaces[1] + 1, spaces[2] - spaces[1] - 1));
                fileBook->SetKol(filekol);
                fileBook->SetPageNumber(filecurPage);
                fileBook->addBook(inf<std::string, Book>["Book"]);
                spaces.clear();
            }
            if (keyName == "Parameter")
            {
                Parameter *fileObject = new Parameter();
                for (int i = 0; i < currentLine.length(); i++)
                {
                    if (currentLine[i] == ' ')
                    {
                        spaces.push_back(i);
                    }
                }
                std::string fileName = currentLine.substr(0, spaces[0]);
                std::string fileTodo = currentLine.substr(spaces[0] + 1, currentLine.rfind(" ") - spaces[0] - 1);
                std::string filesubscr = currentLine.substr(currentLine.rfind(" ") + 1, currentLine.size() - 1);
                fileObject->setObjectName(fileName);
                fileObject->setWhatToDo(fileTodo);
                fileObject->setSubscription(filesubscr);
                fileObject->addParam(inf<std::string, Parameter>[fileName]);
                spaces.clear();
            }
        }
    }
    fin.close();
    if (inf<std::string, Laptop>.size() == 0)
    {
        std::cout << "No laptops in the database" << std::endl;
    }
    else
    {
        std::cout << "There is some laptops in the database";
    }

    if (inf<std::string, Table>.size() == 0)
    {
        std::cout << "No tables in the database" << std::endl;
    }
    else
    {
        std::cout << "There is some tables in the database";
    }
    if (inf<std::string, Parameter>.size() == 0)
    {
        std::cout << "No abstracts in the database" << std::endl;
    }
    else
    {
        std::cout << "There is some abstracts in the database";
    }
    if (inf<std::string, Book>.size() == 0)
    {
        std::cout << "No books in the database" << std::endl;
    }
    else
    {
        std::cout << "There is some books in the database";
    }
    int classOfObject = 0;
    std::set<std::string> namesOfClasses;
    int operation = 0;
    while (classOfObject != 7)
    {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. View all data" << std::endl;
        std::cout << "2. Add new data" << std::endl;
        std::cout << "3. Delete all data" << std::endl;
        std::cout << "4. Save to default file" << std::endl;
        std::cout << "5. Save to another file" << std::endl;
        std::cout << "6. Load from another file" << std::endl;
        std::cout << "7. Exit without saving" << std::endl;
        intCheck(operation);
        std::cout << std::endl;
        switch (operation)
        {
        case 1:
        {
            std::cout << "Laptops {";
            for (int i = 0; i < inf<std::string, Laptop>["Laptop"].size(); ++i)
            {
                std::cout << "{";
                std::cout << inf<std::string, Laptop>["Laptop"][i].GetEfficienty() << ", ";
                std::cout << inf<std::string, Laptop>["Laptop"][i].GetProcessorClockFrequency() << ", ";
                std::cout << inf<std::string, Laptop>["Laptop"][i].GetProcessorCapacity();
                if (i != inf<std::string, Laptop>["Laptop"].size() - 1)
                {
                    std::cout << "}, ";
                }
                else
                {
                    std::cout << "}";
                }
            }
            std::cout << "}\n";
            std::cout << std::endl;
            std::cout << "Tables {";
            for (int i = 0; i < inf<std::string, Table>["Table"].size(); ++i)
            {
                std::cout << "{";
                std::cout << inf<std::string, Table>["Table"][i].GetHeight() << ", ";
                std::cout << inf<std::string, Table>["Table"][i].GetLenght() << ", ";
                std::cout << inf<std::string, Table>["Table"][i].GetWidth() << ", ";
                std::cout << inf<std::string, Table>["Table"][i].GetWeight() << ", ";
                std::cout << inf<std::string, Table>["Table"][i].GetMaterial();
                if (i != inf<std::string, Table>["Table"].size() - 1)
                {
                    std::cout << "}, ";
                }
                else
                {
                    std::cout << "}";
                }
            }
            std::cout << "}\n";
            std::cout << std::endl;
            std::cout << "Books {";
            for (int i = 0; i < inf<std::string, Book>["Book"].size(); ++i)
            {
                std::cout << "{";
                std::cout << inf<std::string, Book>["Book"][i].GetKol() << ", ";
                std::cout << inf<std::string, Book>["Book"][i].GetPageNumber() << ", ";
                std::cout << inf<std::string, Book>["Book"][i].GetIsnew();
                if (i != inf<std::string, Book>["Book"].size() - 1)
                {
                    std::cout << "}, ";
                }
                else
                {
                    std::cout << "}";
                }
            }
            std::cout << "}\n";
            std::cout << std::endl;
            std::cout << "Abstract {";
            for (auto it = namesOfClasses.begin(); it != namesOfClasses.end(); ++it)
            {
                for (int i = 0; i < inf<std::string, Parameter>[*it].size(); ++i)
                {
                    std::cout << "{";
                    std::cout << *it << ", ";
                    std::cout << inf<std::string, Parameter>[*it][i].getWhatToDo() << ", ";
                    std::cout << inf<std::string, Parameter>[*it][i].getSubscription();
                }
            }
            std::cout << "}\n";
            std::cout << std::endl;
            break;
        }
        case 2:
        {
            std::cout << "You can choose:\n1. Academic object\n2. Abstract object\n3. Exit" << std::endl;
            intCheck(classOfObject);
            switch (classOfObject)
            {
            case 1:
            {
                std::cout << "You can choose:\n1. Laptop\n2. Table\n3. Book\n4. Exit to main menu" << std::endl;
                std::cout << "Enter number of object: ";

                int n;
                intCheck(n);
                switch (n)
                {
                case 1:
                {
                    std::cout << "Enter count of objects: ";
                    int count;
                    intCheck(count);
                    std::cout << std::endl;
                    std::cout << "Enter efficiency: ";
                    int ef;
                    intCheck(ef);
                    std::cout << "Enter processor clock frequency: ";
                    int freq;
                    intCheck(freq);
                    std::cout << "Enter processor capacity: ";
                    int cap;
                    intCheck(cap);
                    std::cout << std::endl;
                    Laptop laptop(ef, freq, cap);
                    for (int i = 0; i < count; ++i)
                    {
                        laptop.addLaptop(inf<std::string, Laptop>["Laptop"]);
                    }
                    bool finish = false;
                    while (!finish)
                    {
                        std::cout << "Availible operations\n1. Get/Set efficiency, write 1 and print Get or Set and value\n";
                        std::cout << "2. Get/Set processor clock frequency, write 2 and print Get or Set and value\n";
                        std::cout << "3. Get/Set processor capacity, write 3 and print Get or Set and value\n";
                        std::cout << "4. Add element\n";
                        std::cout << "5. Change element\n";
                        std::cout << "6. Delete all Laptop elements\n";
                        std::cout << "7. Return to academic object menu\n";
                        std::cout << "Enter number of operation: ";
                        bool flag = false;
                        int k;
                        intCheck(k);
                        std::string s;
                        switch (k)
                        {
                        case 1:
                        {
                            int changeNumber;
                            std::cout << "Enter number of element: ";
                            intCheck(changeNumber);
                            std::cout << "Enter command: ";
                            std::cin >> s;
                            if (s != "Set" || s != "set" || s != "Get" || s != "get")
                            {
                                while (s != "Set" && s != "set" && s != "Get" && s != "get")
                                {
                                    std::cout << "Enter correct command: \n";
                                    std::cin >> s;
                                }
                            }
                            if (s == "Get" || s == "get")
                            {
                                std::cout << inf<std::string, Laptop>["Laptop"][changeNumber - 1].GetEfficienty() << std::endl;
                            }
                            if (s == "Set" || s == "set")
                            {
                                int val;
                                intCheck(val);
                                inf<std::string, Laptop>["Laptop"][changeNumber - 1].SetEfficienty(val);
                            }
                            break;
                        }
                        case 2:
                        {
                            int changeNumber;
                            std::cout << "Enter number of element: ";
                            intCheck(changeNumber);
                            std::cout << "Enter command: ";
                            std::cin >> s;
                            if (s != "Set" || s != "set" || s != "Get" || s != "get")
                            {
                                while (s != "Set" && s != "set" && s != "Get" && s != "get")
                                {
                                    std::cout << "Enter correct command: ";
                                    std::cin >> s;
                                }
                            }
                            if (s == "Get" || s == "get")
                            {
                                std::cout << inf<std::string, Laptop>["Laptop"][changeNumber - 1].GetProcessorClockFrequency() << std::endl;
                            }
                            if (s == "Set" || s == "set")
                            {
                                int val;
                                intCheck(val);
                                inf<std::string, Laptop>["Laptop"][changeNumber - 1].SetProcessorClockFrequency(val);
                            }
                            break;
                        }
                        case 3:
                        {
                            int changeNumber;
                            std::cout << "Enter number of element: ";
                            intCheck(changeNumber);
                            std::cout << "Enter command: ";
                            std::cin >> s;
                            if (s != "Set" || s != "set" || s != "Get" || s != "get")
                            {
                                while (s != "Set" && s != "set" && s != "Get" && s != "get")
                                {
                                    std::cout << "Enter correct command: ";
                                    std::cin >> s;
                                }
                            }
                            if (s == "Get" || s == "get")
                            {
                                std::cout << inf<std::string, Laptop>["Laptop"][changeNumber - 1].GetProcessorCapacity() << std::endl;
                            }
                            if (s == "Set" || s == "set")
                            {
                                int val;
                                intCheck(val);
                                inf<std::string, Laptop>["Laptop"][changeNumber - 1].SetProcessorCapacity(val);
                            }
                            break;
                        }
                        case 4:
                        {
                            std::cout << "Enter parametrs of new Laptop:\n";
                            std::cout << "Enter efficiency: ";
                            int ef1;
                            intCheck(ef1);
                            std::cout << "Enter processor clock frequency: ";
                            int freq1;
                            intCheck(freq1);
                            std::cout << "Enter processor capacity: ";
                            int cap1;
                            intCheck(cap1);
                            std::cout << "Enter count of objects: ";
                            int cnt;
                            intCheck(cnt);
                            Laptop newLaptop(ef1, freq1, cap1);
                            for (int i = 0; i < cnt; i++)
                            {
                                newLaptop.addLaptop(inf<std::string, Laptop>["Laptop"]);
                            }
                            break;
                        }
                        case 5:
                        {
                            std::cout << "What number of element do you want to change: ";
                            int pos;
                            intCheck(pos);
                            std::cout << "Enter new efficiency: ";
                            int ef;
                            intCheck(ef);
                            std::cout << "Enter new processor clock frequency: ";
                            int freq;
                            intCheck(freq);
                            std::cout << "Enter new processor capacity: ";
                            int cap;
                            intCheck(cap);
                            inf<std::string, Laptop>["Laptop"][pos - 1].SetEfficienty(ef);
                            inf<std::string, Laptop>["Laptop"][pos - 1].SetProcessorClockFrequency(freq);
                            inf<std::string, Laptop>["Laptop"][pos - 1].SetProcessorCapacity(cap);
                            break;
                        }
                        case 6:
                        {
                            inf<std::string, Laptop>["Laptop"].clear();
                            break;
                        }
                        case 7:
                        {
                            finish = true;
                            flag = true;
                            break;
                        }
                        default:
                        {
                            while (k < 1 || k > 7)
                            {
                                intCheck(k);
                            }
                            break;
                        }
                        }

                        if (!flag)
                        {
                            std::cout << "If you want to continue to work with class Laptop press [y] else press [n]: ";
                            char symbol;
                            std::cin >> symbol;
                            while (symbol != 'y' && symbol != 'n')
                            {
                                std::cout << "Enter correct command: ";
                                std::cin >> symbol;
                            }
                            if (symbol == 'n')
                            {
                                finish = true;
                            }
                            else
                            {
                                continue;
                            }
                        }
                    }
                    break;
                }
                case 2:
                {
                    std::cout << "Enter count of objects: ";

                    int count;
                    intCheck(count);
                    std::cout << std::endl;
                    std::cout << "Enter height of the table: ";
                    int height;
                    intCheck(height);
                    std::cout << "Enter lenght of the table: ";
                    int len;
                    intCheck(len);
                    std::cout << "Enter width of the table: ";
                    int width;
                    intCheck(width);
                    std::cout << "Enter weight of the table: ";
                    int weight;
                    intCheck(weight);
                    std::cout << "Enter material of the table: ";
                    std::string material;
                    std::getline(std::cin, material);
                    std::getline(std::cin, material);
                    Table table(height, len, width, weight, material);
                    for (int i = 0; i < count; i++)
                    {
                        table.addTable(inf<std::string, Table>["Table"]);
                    }
                    bool finish = false;
                    while (!finish)
                    {
                        std::cout << "Availible operations\n1. Get/Set height, write 1 and print Get or Set and value\n";
                        std::cout << "2. Get/Set lenght, write 2 and print Get or Set and value\n";
                        std::cout << "3. Get/Set width, write 3 and print Get or Set and value\n";
                        std::cout << "4. Get/Set weight, write 2 and print Get or Set and value\n";
                        std::cout << "5. Get/Set material, write 2 and print Get or Set and value\n";
                        std::cout << "6. Add elements\n";
                        std::cout << "7. Change elements\n";
                        std::cout << "8. Delete all Table elements\n";
                        std::cout << "9. Return to academic object menu\n";
                        std::cout << "Enter number of operation: ";
                        bool flag = false;
                        int k;
                        intCheck(k);
                        std::string s;
                        switch (k)
                        {
                        case 1:
                        {
                            int changeNumber;
                            std::cout << "Enter number of element: ";
                            intCheck(changeNumber);
                            std::cout << "Enter command: ";
                            std::cin >> s;
                            if (s != "Set" || s != "set" || s != "Get" || s != "get")
                            {
                                while (s != "Set" && s != "set" && s != "Get" && s != "get")
                                {
                                    std::cout << "Enter correct command: ";
                                    std::cin >> s;
                                }
                            }
                            if (s == "Get" || s == "get")
                            {
                                std::cout << inf<std::string, Table>["Table"][changeNumber - 1].GetHeight() << std::endl;
                            }
                            if (s == "Set" || s == "set")
                            {
                                int val;
                                intCheck(val);
                                inf<std::string, Table>["Table"][changeNumber - 1].SetHeight(val);
                            }
                            break;
                        }
                        case 2:
                        {
                            int changeNumber;
                            std::cout << "Enter number of element: ";
                            intCheck(changeNumber);
                            std::cout << "Enter command: ";
                            std::cin >> s;
                            if (s != "Set" || s != "set" || s != "Get" || s != "get")
                            {
                                while (s != "Set" && s != "set" && s != "Get" && s != "get")
                                {
                                    std::cout << "Enter correct command: ";
                                    std::cin >> s;
                                }
                            }
                            if (s == "Get" || s == "get")
                            {
                                std::cout << inf<std::string, Table>["Table"][changeNumber - 1].GetLenght() << std::endl;
                            }
                            if (s == "Set" || s == "set")
                            {
                                int val;
                                intCheck(val);
                                inf<std::string, Table>["Table"][changeNumber - 1].SetLenght(val);
                            }
                            break;
                        }
                        case 3:
                        {
                            int changeNumber;
                            std::cout << "Enter number of element: ";
                            intCheck(changeNumber);
                            std::cout << "Enter command: ";
                            std::cin >> s;
                            if (s != "Set" || s != "set" || s != "Get" || s != "get")
                            {
                                while (s != "Set" && s != "set" && s != "Get" && s != "get")
                                {
                                    std::cout << "Enter correct command: ";
                                    std::cin >> s;
                                }
                            }
                            if (s == "Get" || s == "get")
                            {
                                std::cout << inf<std::string, Table>["Table"][changeNumber - 1].GetWidth() << std::endl;
                            }
                            if (s == "Set" || s == "set")
                            {
                                int val;
                                intCheck(val);
                                inf<std::string, Table>["Table"][changeNumber - 1].SetWidth(val);
                            }
                            break;
                        }
                        case 4:
                        {
                            int changeNumber;
                            std::cout << "Enter number of element: ";
                            intCheck(changeNumber);
                            std::cout << "Enter command: ";
                            std::cin >> s;
                            if (s != "Set" || s != "set" || s != "Get" || s != "get")
                            {
                                while (s != "Set" && s != "set" && s != "Get" && s != "get")
                                {
                                    std::cout << "Enter correct command: ";
                                    std::cin >> s;
                                }
                            }
                            if (s == "Get" || s == "get")
                            {
                                std::cout << inf<std::string, Table>["Table"][changeNumber - 1].GetWeight() << std::endl;
                            }
                            if (s == "Set" || s == "set")
                            {
                                int val;
                                intCheck(val);
                                inf<std::string, Table>["Table"][changeNumber - 1].SetWeight(val);
                            }
                            break;
                        }
                        case 5:
                        {
                            int changeNumber;
                            std::cout << "Enter number of element: ";
                            intCheck(changeNumber);
                            std::cout << "Enter command: ";
                            std::cin >> s;
                            if (s != "Set" || s != "set" || s != "Get" || s != "get")
                            {
                                while (s != "Set" && s != "set" && s != "Get" && s != "get")
                                {
                                    std::cout << "Enter correct command: ";
                                    std::cin >> s;
                                }
                            }
                            if (s == "Get" || s == "get")
                            {
                                std::cout << inf<std::string, Table>["Table"][changeNumber - 1].GetMaterial() << std::endl;
                            }
                            if (s == "Set" || s == "set")
                            {
                                std::string val;
                                std::getline(std::cin, val);
                                inf<std::string, Table>["Table"][changeNumber - 1].SetMaterial(val);
                            }
                            break;
                        }
                        case 6:
                        {
                            std::cout << "Enter parametrs of new Table:\n";
                            std::cout << "Enter height: ";
                            int newHeight;
                            intCheck(newHeight);
                            std::cout << "Enter lenght: ";
                            int newLen;
                            intCheck(newLen);
                            std::cout << "Enter width: ";
                            int newWidth;
                            intCheck(newWidth);
                            std::cout << "Enter weight: ";
                            int newWeight;
                            intCheck(newWeight);
                            std::cout << "Enter material: ";
                            std::string newMaterial;
                            std::cin >> newMaterial;
                            std::cout << "Enter count of objects: ";
                            int cnt;
                            intCheck(cnt);
                            Table newTable(newHeight, newLen, newWidth, newWeight, newMaterial);
                            for (int i = 0; i < cnt; i++)
                            {
                                newTable.addTable(inf<std::string, Table>["Table"]);
                            }
                            break;
                        }
                        case 7:
                        {
                            std::cout << "What number of element do you want to change: ";
                            int pos;
                            intCheck(pos);
                            std::cout << "Enter parametrs of new Table:\n";
                            std::cout << "Enter height: ";
                            int newHeight;
                            intCheck(newHeight);
                            std::cout << "Enter lenght: ";
                            int newLen;
                            intCheck(newLen);
                            std::cout << "Enter width: ";
                            int newWidth;
                            intCheck(newWidth);
                            std::cout << "Enter weight: ";
                            int newWeight;
                            intCheck(newWeight);
                            std::cout << "Enter material: ";
                            std::string newMaterial;
                            std::cin >> newMaterial;
                            inf<std::string, Table>["Table"][pos - 1].SetHeight(newHeight);
                            inf<std::string, Table>["Table"][pos - 1].SetLenght(newLen);
                            inf<std::string, Table>["Table"][pos - 1].SetWidth(newWidth);
                            inf<std::string, Table>["Table"][pos - 1].SetWeight(newWeight);
                            inf<std::string, Table>["Table"][pos - 1].SetMaterial(newMaterial);
                            break;
                        }

                        case 8:
                        {
                            inf<std::string, Table>["Table"].clear();
                            break;
                        }
                        case 9:
                        {
                            finish = true;
                            flag = true;
                            break;
                        }
                        default:
                        {
                            while (k < 1 || k > 9)
                            {
                                std::cout << "Enter correct number of command: ";
                                std::cin >> k;
                            }
                            break;
                        }
                        }

                        if (!flag)
                        {
                            std::cout << "If you want to continue to work with class Laptop press [y] else press [n]: ";
                            char symbol;
                            std::cin >> symbol;
                            if (symbol == 'n')
                            {
                                finish = true;
                            }
                            else
                            {
                                if (symbol != 'y')
                                {
                                    while (symbol != 'y' && symbol != 'n')
                                    {
                                        std::cout << "Enter correct command: ";
                                        std::cin >> symbol;
                                    }
                                }
                                else
                                {
                                    continue;
                                }
                            }
                        }
                    }
                    break;
                }
                case 3:
                {
                    std::cout << "Enter count of objects: ";
                    int count;
                    intCheck(count);
                    std::cout << std::endl;
                    std::cout << "Enter kol pages of Book: ";
                    int kol;
                    intCheck(kol);
                    std::cout << "Enter current page of Book: ";
                    int curPage;
                    intCheck(curPage);
                    Book book(kol, curPage);
                    if (curPage != 0)
                    {
                        book.MakeUsed();
                    }
                    for (int i = 0; i < count; i++)
                    {
                        book.addBook(inf<std::string, Book>["Book"]);
                    }
                    bool finish = false;
                    while (!finish)
                    {
                        std::cout << "Availible operations\n1. Get quantity of pages, write 1 and print Get\n";
                        std::cout << "2. Get/Set number of current page, write 2 and print Get or Set and value\n";
                        std::cout << "3. Add element\n";
                        std::cout << "4. Change element\n";
                        std::cout << "5. Delete all books\n";
                        std::cout << "6. Return to main menu\n";
                        std::cout << "Enter number of operation: ";
                        bool flag = false;
                        int k;
                        intCheck(k);
                        std::string s;
                        switch (k)
                        {
                        case 1:
                        {
                            int changeNumber;
                            std::cout << "Enter number of element: ";
                            intCheck(changeNumber);
                            std::cout << "Enter command: ";
                            std::cin >> s;
                            if (s != "Get" || s != "get")
                            {
                                while (s != "Get" && s != "get")
                                {
                                    std::cout << "Enter correct command: ";
                                    std::cin >> s;
                                }
                                std::cout << inf<std::string, Book>["Book"][changeNumber - 1].GetKol() << std::endl;
                            }
                            break;
                        }
                        case 2:
                        {
                            int changeNumber;
                            std::cout << "Enter number of element: ";
                            intCheck(changeNumber);
                            std::cout << "Enter command: ";
                            std::cin >> s;
                            if (s != "Set" || s != "set" || s != "Get" || s != "get")
                            {
                                while (s != "Set" && s != "set" && s != "Get" && s != "get")
                                {
                                    std::cout << "Enter correct command: ";
                                    std::cin >> s;
                                }
                            }
                            if (s == "Get" || s == "get")
                            {
                                std::cout << inf<std::string, Book>["Book"][changeNumber - 1].GetPageNumber() << std::endl;
                            }
                            if (s == "Set" || s == "set")
                            {
                                int val;
                                intCheck(val);
                                inf<std::string, Book>["Book"][changeNumber - 1].SetPageNumber(val);
                            }
                            break;
                        }
                        case 3:
                        {
                            std::cout << "Enter parametrs of new book:\n";
                            std::cout << std::endl;
                            std::cout << "Enter kol pages of Book: ";
                            int newKol;
                            intCheck(newKol);
                            std::cout << "Enter current page of Book: ";
                            int newCurPage;
                            intCheck(newCurPage);
                            Book newBook(newKol, newCurPage);
                            if (newCurPage != 0)
                            {
                                newBook.MakeUsed();
                            }
                            std::cout << "Enter count of objects: ";
                            int cnt;
                            intCheck(cnt);
                            for (int i = 0; i < cnt; i++)
                            {
                                newBook.addBook(inf<std::string, Book>["Book"]);
                            }
                            break;
                        }
                        case 4:
                        {
                            int changeNumber;
                            std::cout << "Enter number of element: ";
                            intCheck(changeNumber);
                            std::cout << "Enter parametrs of new book:\n";
                            std::cout << std::endl;
                            std::cout << "Enter kol pages of Book: ";
                            int newKol;
                            intCheck(newKol);
                            std::cout << "Enter current page of Book: ";
                            int newCurPage;
                            intCheck(newCurPage);
                            inf<std::string, Book>["Book"][changeNumber - 1].SetKol(newKol);
                            inf<std::string, Book>["Book"][changeNumber - 1].SetPageNumber(newCurPage);
                            break;
                        }
                        case 5:
                        {
                            inf<std::string, Book>["Book"].clear();
                            break;
                        }
                        case 6:
                        {
                            finish = true;
                            flag = true;
                            break;
                        }
                        default:
                        {
                            while (k < 1 || k > 6)
                            {
                                intCheck(k);
                            }
                            break;
                        }
                        }

                        if (!flag)
                        {
                            std::cout << "If you want to continue to work with class Laptop press [y] else press [n]: ";
                            char symbol;
                            std::cin >> symbol;
                            if (symbol == 'n')
                            {
                                finish = true;
                            }
                            else
                            {
                                if (symbol != 'y')
                                {
                                    while (symbol != 'y' && symbol != 'n')
                                    {
                                        std::cout << "Enter correct command: ";
                                        std::cin >> symbol;
                                    }
                                }
                                else
                                {
                                    continue;
                                }
                            }
                        }
                    }
                }
                case 4:
                {
                    break;
                }
                default:
                    while (n < 1 || n > 4)
                    {
                        intCheck(n);
                    }
                }
                break;
            }
            case 2:
            {
                std::cout << "Enter name of object: ";
                std::string className;
                std::cin >> className;
                std::cout << std::endl;
                std::cout << "Enter count of objects: ";
                int ocnt;
                intCheck(ocnt);
                std::cout << "Enter subscription of object: ";
                std::string subscr;
                std::cin >> subscr;
                std::cout << "What action would you like to do with object:\n";
                std::string action;
                std::getline(std::cin, action);
                std::getline(std::cin, action);
                std::cout << std::endl;
                Parameter parameter(className, subscr, action);
                for (int i = 1; i < ocnt; i++)
                {
                    parameter.addParam(inf<std::string, Parameter>[className]);
                }
                parameter.addParam(inf<std::string, Parameter>[className]);
                namesOfClasses.insert(className);
                bool finish = false;
                int countOfElements = ocnt;
                while (!finish)
                {
                    std::cout << "Availible operations:\n1. Get name of class, write 1 and get\n";
                    std::cout << "2. Get/Set serial number, write 2 and print Get or Set and value\n";
                    std::cout << "3. Get/Set action, write 3 and print Get or Set and value\n";
                    std::cout << "4. Add element\n";
                    std::cout << "5. Change element\n";
                    std::cout << "8. Delete all elements\n";
                    std::cout << "9. Return to main menu\n";
                    std::cout << "Enter number of operation: ";
                    bool flag = false;
                    int k;
                    intCheck(k);
                    std::string s;
                    switch (k)
                    {
                    case 1:
                    {
                        int changeNumber;
                        std::cout << "Enter number of element: ";
                        intCheck(changeNumber);
                        std::cout << "Enter command: ";
                        std::cin >> s;
                        if (s != "Get" || s != "get")
                        {
                            while (s != "Get" && s != "get")
                            {
                                std::cout << "Enter correct command: ";
                                std::cin >> s;
                            }
                            std::cout << inf<std::string, Parameter>[className][changeNumber - 1].getObjectName() << std::endl;
                        }
                        else
                        {
                            std::cout << inf<std::string, Parameter>[className][changeNumber - 1].getObjectName() << std::endl;
                        }
                        break;
                    }
                    case 2:
                    {
                        int changeNumber;
                        std::cout << "Enter number of element: ";
                        intCheck(changeNumber);
                        std::cout << "Enter command: ";
                        std::cin >> s;
                        if (s != "Set" || s != "set" || s != "Get" || s != "get")
                        {
                            while (s != "Set" && s != "set" && s != "Get" && s != "get")
                            {
                                std::cout << "Enter correct command: ";
                                std::cin >> s;
                            }
                        }
                        if (s == "Get" || s == "get")
                        {
                            std::cout << inf<std::string, Parameter>[className][changeNumber - 1].getSubscription() << std::endl;
                        }
                        if (s == "Set" || s == "set")
                        {
                            std::string val;
                            std::cin >> val;
                            inf<std::string, Parameter>[className][changeNumber - 1].setSubscription(val);
                        }
                        break;
                    }
                    case 3:
                    {
                        int changeNumber;
                        std::cout << "Enter number of element: ";
                        intCheck(changeNumber);
                        std::cout << "Enter command: ";
                        std::cin >> s;
                        if (s != "Set" || s != "set" || s != "Get" || s != "get")
                        {
                            while (s != "Set" && s != "set" && s != "Get" && s != "get")
                            {
                                std::cout << "Enter correct command: ";
                                std::cin >> s;
                            }
                        }
                        if (s == "Get" || s == "get")
                        {
                            std::cout << inf<std::string, Parameter>[className][changeNumber - 1].getWhatToDo() << std::endl;
                        }
                        if (s == "Set" || s == "set")
                        {
                            std::string val;
                            std::getline(std::cin, val);
                            inf<std::string, Parameter>[className][changeNumber - 1].setWhatToDo(val);
                        }
                        break;
                    }
                    case 4:
                    {
                        std::cout << "Enter parametrs of new object:\n";
                        std::cout << "Enter name of new class: ";
                        std::string newClassName;
                        std::cin >> newClassName;
                        std::cout << "Enter subscription: ";
                        std::string subscription;
                        std::cin >> subscription;
                        std::cout << "Enter what do you want to do: ";
                        std::string newAction;
                        std::getline(std::cin, newAction);
                        std::getline(std::cin, newAction);
                        std::cout << "Enter count of objects: ";
                        int cnt;
                        intCheck(cnt);
                        Parameter newParameter(newClassName, subscription, newAction);
                        for (int i = 0; i < cnt; ++i)
                        {
                            newParameter.addParam(inf<std::string, Parameter>[newClassName]);
                        }
                        namesOfClasses.insert(newClassName);
                        break;
                    }
                    case 5:
                    {
                        std::cout << "Enter parametrs of object:\n";
                        std::cout << "Enter name of class: ";
                        std::string newClassName;
                        std::cin >> newClassName;
                        std::cout << "Enter subscription: ";
                        std::string newSubscription;
                        std::cin >> newSubscription;
                        std::cout << "Enter what do you want to do: ";
                        std::string newAction;
                        std::getline(std::cin, newAction);
                        std::getline(std::cin, newAction);
                        int changeNumber;
                        std::cout << "Enter number of object: ";
                        intCheck(changeNumber);
                        inf<std::string, Parameter>[newClassName][changeNumber - 1].setWhatToDo(newAction);
                        inf<std::string, Parameter>[newClassName][changeNumber - 1].setSubscription(newSubscription);
                        break;
                    }
                    case 8:
                    {
                        inf<std::string, Parameter>.clear();
                        namesOfClasses.clear();
                        countOfElements = 0;
                        break;
                    }
                    case 9:
                    {
                        finish = true;
                        flag = true;
                        break;
                    }
                    default:
                    {
                        while (k < 1 || k > 9)
                        {
                            intCheck(k);
                        }
                        break;
                    }
                    }

                    if (!flag)
                    {
                        std::cout << "If you want to continue to work with abstract class, press [y] else press [n]: ";
                        char symbol;
                        std::cin >> symbol;
                        if (symbol == 'n')
                        {
                            finish = true;
                        }
                        else
                        {
                            if (symbol != 'y')
                            {
                                while (symbol != 'y' && symbol != 'n')
                                {
                                    std::cout << "Enter correct command: ";
                                    std::cin >> symbol;
                                }
                            }
                            else
                            {
                                continue;
                            }
                        }
                    }
                }
                break;
            }
            }
            break;
        }
        case 3:
        {
            inf<std::string, Laptop>.clear();
            inf<std::string, Table>.clear();
            inf<std::string, Book>.clear();
            inf<std::string, Parameter>.clear();
            namesOfClasses.clear();
            break;
        }
        case 4:
        {
            std::ofstream fout;
            fout.open("classes_information.txt", std::ios::out | std::ofstream::trunc);
            fout << "class Laptop" << std::endl;
            for (int i = 0; i < inf<std::string, Laptop>["Laptop"].size(); ++i)
            {
                fout << inf<std::string, Laptop>["Laptop"][i].GetEfficienty() << " ";
                fout << inf<std::string, Laptop>["Laptop"][i].GetProcessorClockFrequency() << " ";
                fout << inf<std::string, Laptop>["Laptop"][i].GetProcessorCapacity();
                fout << std::endl;
            }

            fout << "class Table" << std::endl;
            for (int i = 0; i < inf<std::string, Table>["Table"].size(); ++i)
            {
                fout << inf<std::string, Table>["Table"][i].GetHeight() << " ";
                fout << inf<std::string, Table>["Table"][i].GetLenght() << " ";
                fout << inf<std::string, Table>["Table"][i].GetWidth() << " ";
                fout << inf<std::string, Table>["Table"][i].GetWeight() << " ";
                fout << inf<std::string, Table>["Table"][i].GetMaterial();
                std::cout << std::endl;
            }

            fout << "class Book" << std::endl;
            for (int i = 0; i < inf<std::string, Book>["Book"].size(); ++i)
            {
                for (int j = 0; j < inf<std::string, Book>["Book"].size(); ++j)
                {
                    fout << inf<std::string, Book>["Book"][i].GetKol() << " ";
                    fout << inf<std::string, Book>["Book"][i].GetPageNumber() << " ";
                    fout << inf<std::string, Book>["Book"][i].GetIsnew();
                    fout << std::endl;
                }
            }

            fout << "class Parameter" << std::endl;
            for (auto it = namesOfClasses.begin(); it != namesOfClasses.end(); ++it)
            {
                for (int i = 0; i < inf<std::string, Parameter>[*it].size(); ++i)
                {
                    fout << *it << " ";
                    fout << inf<std::string, Parameter>[*it][i].getWhatToDo() << " ";
                    fout << inf<std::string, Parameter>[*it][i].getSubscription();
                    fout << std::endl;
                }
            }
            fout.close();
            break;
        }
        case 5:
        {
            std::ofstream fout;
            fout.open("reserv.txt", std::ios::out | std::ofstream::trunc);
            fout << "class Laptop" << std::endl;
            for (int i = 0; i < inf<std::string, Laptop>["Laptop"].size(); ++i)
            {
                fout << inf<std::string, Laptop>["Laptop"][i].GetEfficienty() << " ";
                fout << inf<std::string, Laptop>["Laptop"][i].GetProcessorClockFrequency() << " ";
                fout << inf<std::string, Laptop>["Laptop"][i].GetProcessorCapacity();
                fout << std::endl;
            }

            fout << "class Table" << std::endl;
            for (int i = 0; i < inf<std::string, Table>["Table"].size(); ++i)
            {
                fout << inf<std::string, Table>["Table"][i].GetHeight() << " ";
                fout << inf<std::string, Table>["Table"][i].GetLenght() << " ";
                fout << inf<std::string, Table>["Table"][i].GetWidth() << " ";
                fout << inf<std::string, Table>["Table"][i].GetWeight() << " ";
                fout << inf<std::string, Table>["Table"][i].GetMaterial();
                std::cout << std::endl;
            }

            fout << "class Book" << std::endl;
            for (int i = 0; i < inf<std::string, Book>["Book"].size(); ++i)
            {
                for (int j = 0; j < inf<std::string, Book>["Book"].size(); ++j)
                {
                    fout << inf<std::string, Book>["Book"][i].GetKol() << " ";
                    fout << inf<std::string, Book>["Book"][i].GetPageNumber() << " ";
                    fout << inf<std::string, Book>["Book"][i].GetIsnew();
                    fout << std::endl;
                }
            }

            fout << "class Parameter" << std::endl;
            for (auto it = namesOfClasses.begin(); it != namesOfClasses.end(); ++it)
            {
                for (int i = 0; i < inf<std::string, Parameter>[*it].size(); ++i)
                {
                    fout << *it << " ";
                    fout << inf<std::string, Parameter>[*it][i].getWhatToDo() << " ";
                    fout << inf<std::string, Parameter>[*it][i].getSubscription();
                    fout << std::endl;
                }
            }
            fout.close();
            break;
        }
        case 6:
        {
            inf<std::string, Laptop>.clear();
            inf<std::string, Table>.clear();
            inf<std::string, Book>.clear();
            inf<std::string, Parameter>.clear();
            namesOfClasses.clear();
            std::ifstream fin;
            fin.open("reserv.txt", std::ios::in);
            std::string currentLine;
            std::string keyName;
            std::vector<int> spaces;
            while (std::getline(fin, currentLine))
            {
                if (currentLine.find(" ") == currentLine.rfind(" "))
                {
                    keyName = currentLine.substr(currentLine.find(" ") + 1, 50);
                }
                else
                {
                    if (keyName == "Laptop")
                    {
                        Laptop *fileLaptop = new Laptop();
                        for (int i = 0; i < currentLine.length(); i++)
                        {
                            if (currentLine[i] == ' ')
                            {
                                spaces.push_back(i);
                            }
                        }
                        int fileef = std::stoi(currentLine.substr(0, spaces[0]));
                        int filecl = std::stoi(currentLine.substr(spaces[0] + 1, spaces[1] - spaces[0] - 1));
                        int filecap = std::stoi(currentLine.substr(spaces[1] + 1, spaces[2] - spaces[1] - 1));
                        fileLaptop->SetEfficienty(fileef);
                        fileLaptop->SetProcessorCapacity(filecap);
                        fileLaptop->SetProcessorClockFrequency(filecl);
                        fileLaptop->addLaptop(inf<std::string, Laptop>["Laptop"]);
                        spaces.clear();
                    }
                    if (keyName == "Table")
                    {
                        Table *fileTable = new Table();
                        for (int i = 0; i < currentLine.length(); i++)
                        {
                            if (currentLine[i] == ' ')
                            {
                                spaces.push_back(i);
                            }
                        }
                        int filehigh = std::stoi(currentLine.substr(0, spaces[0]));
                        int filelen = std::stoi(currentLine.substr(spaces[0] + 1, spaces[1] - spaces[0] - 1));
                        int filewid = std::stoi(currentLine.substr(spaces[1] + 1, spaces[2] - spaces[1] - 1));
                        int fileweight = std::stoi(currentLine.substr(spaces[2] + 1, spaces[3] - spaces[2] - 1));
                        std::string filemat = currentLine.substr(spaces[3] + 1, spaces[4] - spaces[3] - 1);
                        fileTable->SetHeight(filehigh);
                        fileTable->SetLenght(filelen);
                        fileTable->SetWidth(filewid);
                        fileTable->SetWeight(fileweight);
                        fileTable->SetMaterial(filemat);
                        fileTable->addTable(inf<std::string, Table>["Table"]);
                        spaces.clear();
                    }
                    if (keyName == "Book")
                    {
                        Book *fileBook = new Book();
                        for (int i = 0; i < currentLine.length(); i++)
                        {
                            if (currentLine[i] == ' ')
                            {
                                spaces.push_back(i);
                            }
                        }
                        int filekol = std::stoi(currentLine.substr(0, spaces[0]));
                        int filecurPage = std::stoi(currentLine.substr(spaces[0] + 1, spaces[1] - spaces[0] - 1));
                        int fileNew = std::stoi(currentLine.substr(spaces[1] + 1, spaces[2] - spaces[1] - 1));
                        fileBook->SetKol(filekol);
                        fileBook->SetPageNumber(filecurPage);
                        fileBook->addBook(inf<std::string, Book>["Book"]);
                        spaces.clear();
                    }
                    if (keyName == "Parameter")
                    {
                        Parameter *fileObject = new Parameter();
                        for (int i = 0; i < currentLine.length(); i++)
                        {
                            if (currentLine[i] == ' ')
                            {
                                spaces.push_back(i);
                            }
                        }
                        std::string fileName = currentLine.substr(0, spaces[0]);
                        std::string fileTodo = currentLine.substr(spaces[0] + 1, currentLine.rfind(" ") - spaces[0] - 1);
                        std::string filesubscr = currentLine.substr(currentLine.rfind(" ") + 1, currentLine.size() - 1);
                        fileObject->setObjectName(fileName);
                        fileObject->setWhatToDo(fileTodo);
                        fileObject->setSubscription(filesubscr);
                        fileObject->addParam(inf<std::string, Parameter>[fileName]);
                        spaces.clear();
                    }
                }
            }
            fin.close();
            break;
        }
        case 7:
        {
            return 0;
        }
        default:
            break;
        }
    }
    return 0;
}