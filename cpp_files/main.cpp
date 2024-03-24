#include "../header_files/includes.h"

class Laptop
{
public:
    Laptop(int EffVal, int ClockVal, int CapVal) : efficiency(EffVal), ProcessorClockFrequency(ClockVal), ProcessorCapacity(CapVal) {}
    Laptop() = default;
    ~Laptop() = default;

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
    int isExist(std::vector<std::vector<T>> v)
    {
        bool ans = false;
        for (int i = 0; i < v.size(); ++i)
        {
            if (!std::empty(v[i]))
            {
                ans = (v[i][0].ProcessorCapacity == this->ProcessorCapacity) &&
                      (v[i][0].efficiency == this->efficiency) &&
                      (v[i][0].ProcessorClockFrequency == this->ProcessorClockFrequency);
            }
            if (ans)
            {
                return i;
            }
        }
        return -1;
    }

    template <class T>
    void addLaptop(std::vector<std::vector<T>> &inf, int cnt = 1)
    {
        int t = this->isExist(inf);
        if (t >= 0)
        {
            for (int i = 0; i < cnt; ++i)
            {
                inf[t].push_back(*this);
            }
        }
        else
        {
            std::vector<Laptop> v(cnt, *this);
            inf.push_back(v);
        }
    }

private:
    int efficiency = 0;
    int ProcessorClockFrequency = 0;
    int ProcessorCapacity = 0;
};

class Parameter
{
public:
    Parameter(std::string on, int sn, std::string wtd) : objectName(on), serialNumber(sn), whatToDo(wtd){};
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

    int getSerialNumber()
    {
        return this->serialNumber;
    }

    void setSerialNumber(int val)
    {
        this->serialNumber = val;
    }

    std::string getWhatToDo()
    {
        return this->whatToDo;
    }

    void setWhatToDo(std::string &str)
    {
        this->whatToDo = str;
    }

    template <class T>
    int isExist(std::vector<std::vector<T>> v)
    {
        bool ans = false;
        for (int i = 0; i < v.size(); ++i)
        {
            if (!std::empty(v[i]))
            {
                ans = (v[i][0].getSerialNumber() == this->serialNumber) && (v[i][0].getWhatToDo() == this->whatToDo);
            }
            if (ans)
            {
                return i;
            }
        }
        return -1;
    }

    template <class T>
    void addParam(std::vector<std::vector<T>> &inf, int cnt = 1)
    {
        int t = this->isExist(inf);
        if (t >= 0)
        {
            for (int i = 0; i < cnt; ++i)
            {
                inf[t].push_back(*this);
            }
        }
        else
        {
            std::vector<Parameter> v(cnt, *this);
            inf.push_back(v);
        }
    }

private:
    std::string objectName;
    int serialNumber;
    std::string whatToDo;
};
class Table
{
public:
    Table(int h, int len, int wd, int w, std::string mat) : height(h), weight(w), lenght(len), width(wd), material(mat) {}
    Table() = default;
    ~Table() = default;

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
    int isExist(std::vector<std::vector<T>> v)
    {
        bool ans = false;
        for (int i = 0; i < v.size(); ++i)
        {
            if (!std::empty(v[i]))
            {
                ans = (v[i][0].height == this->height) &&
                      (v[i][0].lenght == this->lenght) &&
                      (v[i][0].width == this->width) &&
                      (v[i][0].weight == this->weight) &&
                      (v[i][0].material == this->material);
            }
            if (ans)
            {
                return i;
            }
        }
        return -1;
    }

    template <class T>
    void addTable(std::vector<std::vector<T>> &inf, int cnt = 1)
    {
        int t = this->isExist(inf);
        if (t >= 0)
        {
            for (int i = 0; i < cnt; ++i)
            {
                inf[t].push_back(*this);
            }
        }
        else
        {
            std::vector<Table> v(cnt, *this);
            inf.push_back(v);
        }
    }

private:
    int height = 0;
    int lenght = 0;
    int width = 0;
    int weight = 0;
    std::string material = "";
};

class Book
{
public:
    Book(int k, int pn) : kol(k), pageNumber(pn) {}
    Book() = default;
    ~Book() = default;

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
    int isExist(std::vector<std::vector<T>> v)
    {
        bool ans = false;
        for (int i = 0; i < v.size(); ++i)
        {
            if (!std::empty(v[i]))
            {
                ans = (v[i][0].kol == this->kol) &&
                      (v[i][0].pageNumber == this->pageNumber);
            }
            if (ans)
            {
                return i;
            }
        }
        return -1;
    }

    template <class T>
    void addBook(std::vector<std::vector<T>> &inf, int cnt = 1)
    {
        int t = this->isExist(inf);
        if (t >= 0)
        {
            for (int i = 0; i < cnt; ++i)
            {
                inf[t].push_back(*this);
            }
        }
        else
        {
            std::vector<Book> v(cnt, *this);
            inf.push_back(v);
        }
    }

private:
    int kol = 0;
    int pageNumber = 0;
    bool Isnew = true;
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
std::map<T, std::vector<std::vector<U>>> inf;

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
                int filecnt = std::stoi(currentLine.substr(spaces[2] + 1, currentLine.size() - 1));
                fileLaptop->SetEfficienty(fileef);
                fileLaptop->SetProcessorCapacity(filecap);
                fileLaptop->SetProcessorClockFrequency(filecl);
                fileLaptop->addLaptop(inf<std::string, Laptop>["Laptop"], filecnt);
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
                int filecnt = std::stoi(currentLine.substr(spaces[4] + 1, currentLine.size() - 1));
                fileTable->SetHeight(filehigh);
                fileTable->SetLenght(filelen);
                fileTable->SetWidth(filewid);
                fileTable->SetWeight(fileweight);
                fileTable->SetMaterial(filemat);
                fileTable->addTable(inf<std::string, Table>["Table"], filecnt);
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
                int filecnt = std::stoi(currentLine.substr(spaces[2] + 1, currentLine.size() - 1));
                fileBook->SetKol(filekol);
                fileBook->SetPageNumber(filecurPage);
                fileBook->addBook(inf<std::string, Book>["Book"], filecnt);
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
                int fileNumber = std::stoi(currentLine.substr(spaces[0] + 1, spaces[1] - spaces[0] - 1));
                std::string fileTodo = currentLine.substr(spaces[1] + 1, currentLine.rfind(" ") - spaces[1] - 1);
                int filecnt = std::stoi(currentLine.substr(currentLine.rfind(" ") + 1, currentLine.size() - 1));
                fileObject->setObjectName(fileName);
                fileObject->setSerialNumber(fileNumber);
                fileObject->setWhatToDo(fileTodo);
                fileObject->addParam(inf<std::string, Parameter>[fileName], filecnt);
                spaces.clear();
            }
        }
    }
    fin.close();

    int classOfObject = 0;
    std::set<std::string> namesOfClasses;
    while (classOfObject != 3)
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
            case 1: // Full debag of class Laptop
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
                laptop.addLaptop(inf<std::string, Laptop>["Laptop"], count);
                bool finish = false;
                while (!finish)
                {
                    std::cout << "Availible operations\n1. Get/Set efficiency, write 1 and print Get or Set and value\n";
                    std::cout << "2. Get/Set processor clock frequency, write 2 and print Get or Set and value\n";
                    std::cout << "3. Get/Set processor capacity, write 3 and print Get or Set and value\n";
                    std::cout << "4. Add element\n";
                    std::cout << "5. Count of elements\n";
                    std::cout << "6. Count of diffrent elements\n";
                    std::cout << "7. Show diffrent elements\n";
                    std::cout << "8. Delete all Laptop elements\n";
                    std::cout << "9. Return to academic object menu\n";
                    std::cout << "Enter number of operation: ";
                    bool flag = false;
                    int k;
                    intCheck(k);
                    std::string s;
                    switch (k)
                    {
                    case 1: // Полностью протестирован
                    {
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
                            std::cout << laptop.GetEfficienty() << std::endl;
                        }
                        if (s == "Set" || s == "set")
                        {
                            int val;
                            intCheck(val);
                            int exist = laptop.isExist(inf<std::string, Laptop>["Laptop"]);
                            if (exist >= 0)
                            {
                                for (int j = 0; j < inf<std::string, Laptop>["Laptop"][exist].size(); ++j)
                                {
                                    inf<std::string, Laptop>["Laptop"][exist][j].SetEfficienty(val);
                                }
                            }
                            laptop.SetEfficienty(val);
                        }
                        break;
                    }
                    case 2:
                    {
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
                            std::cout << laptop.GetProcessorClockFrequency() << std::endl;
                        }
                        if (s == "Set" || s == "set")
                        {
                            int val;
                            intCheck(val);
                            int exist = laptop.isExist(inf<std::string, Laptop>["Laptop"]);
                            if (exist >= 0)
                            {
                                for (int j = 0; j < inf<std::string, Laptop>["Laptop"][exist].size(); ++j)
                                {
                                    inf<std::string, Laptop>["Laptop"][exist][j].SetProcessorClockFrequency(val);
                                }
                            }
                            laptop.SetProcessorClockFrequency(val);
                        }
                        break;
                    }
                    case 3:
                    {
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
                            std::cout << laptop.GetProcessorCapacity() << std::endl;
                        }
                        if (s == "Set" || s == "set")
                        {
                            int val;
                            intCheck(val);
                            int exist = laptop.isExist(inf<std::string, Laptop>["Laptop"]);
                            if (exist >= 0)
                            {
                                for (int j = 0; j < inf<std::string, Laptop>["Laptop"][exist].size(); ++j)
                                {
                                    inf<std::string, Laptop>["Laptop"][exist][j].SetProcessorCapacity(val);
                                }
                            }
                            laptop.SetProcessorCapacity(val);
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
                        newLaptop.addLaptop(inf<std::string, Laptop>["Laptop"], cnt);
                        break;
                    }
                    case 5:
                    {
                        int ans = 0;
                        for (int i = 0; i < inf<std::string, Laptop>["Laptop"].size(); ++i)
                        {
                            ans += inf<std::string, Laptop>["Laptop"][i].size();
                        }
                        std::cout << ans << std::endl;
                        break;
                    }
                    case 6:
                    {
                        std::cout << inf<std::string, Laptop>["Laptop"].size() << std::endl;
                        break;
                    }
                    case 7:
                    {
                        std::cout << std::endl;
                        for (int i = 0; i < inf<std::string, Laptop>["Laptop"].size(); ++i)
                        {
                            std::cout << "Efficienty: " << inf<std::string, Laptop>["Laptop"][i][0].GetEfficienty() << std::endl;
                            std::cout << "Processor clock frequency: " << inf<std::string, Laptop>["Laptop"][i][0].GetProcessorClockFrequency() << std::endl;
                            std::cout << "Processor capacity: " << inf<std::string, Laptop>["Laptop"][i][0].GetProcessorCapacity() << std::endl;
                            std::cout << std::endl;
                        }
                        std::cout << std::endl;
                        break;
                    }
                    case 8:
                    {
                        inf<std::string, Laptop>["Laptop"].clear();
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
                table.addTable(inf<std::string, Table>["Table"], count);
                bool finish = false;
                while (!finish)
                {
                    std::cout << "Availible operations\n1. Get/Set height, write 1 and print Get or Set and value\n";
                    std::cout << "2. Get/Set lenght, write 2 and print Get or Set and value\n";
                    std::cout << "3. Get/Set width, write 3 and print Get or Set and value\n";
                    std::cout << "4. Get/Set weight, write 2 and print Get or Set and value\n";
                    std::cout << "5. Get/Set material, write 2 and print Get or Set and value\n";
                    std::cout << "6. Add element\n";
                    std::cout << "7. Count of elements\n";
                    std::cout << "8. Count of diffrent elements\n";
                    std::cout << "9. Show diffrent elements\n";
                    std::cout << "10. Delete all Laptop elements\n";
                    std::cout << "11. Return to academic object menu\n";
                    std::cout << "Enter number of operation: ";
                    bool flag = false;
                    int k;
                    intCheck(k);
                    std::string s;
                    switch (k)
                    {
                    case 1:
                    {
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
                            std::cout << table.GetHeight() << std::endl;
                        }
                        if (s == "Set" || s == "set")
                        {
                            int val;
                            intCheck(val);
                            int exist = table.isExist(inf<std::string, Table>["Table"]);
                            if (exist >= 0)
                            {
                                for (int j = 0; j < inf<std::string, Table>["Table"][exist].size(); ++j)
                                {
                                    inf<std::string, Table>["Table"][exist][j].SetHeight(val);
                                }
                            }
                            table.SetHeight(val);
                        }
                        break;
                    }
                    case 2:
                    {
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
                            std::cout << table.GetLenght() << std::endl;
                        }
                        if (s == "Set" || s == "set")
                        {
                            int val;
                            intCheck(val);
                            int exist = table.isExist(inf<std::string, Table>["Table"]);
                            if (exist >= 0)
                            {
                                for (int j = 0; j < inf<std::string, Table>["Table"][exist].size(); ++j)
                                {
                                    inf<std::string, Table>["Table"][exist][j].SetLenght(val);
                                }
                            }
                            table.SetLenght(val);
                        }
                        break;
                    }
                    case 3:
                    {
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
                            std::cout << table.GetWidth() << std::endl;
                        }
                        if (s == "Set" || s == "set")
                        {
                            int val;
                            intCheck(val);
                            int exist = table.isExist(inf<std::string, Table>["Table"]);
                            if (exist >= 0)
                            {
                                for (int j = 0; j < inf<std::string, Table>["Table"][exist].size(); ++j)
                                {
                                    inf<std::string, Table>["Table"][exist][j].SetWidth(val);
                                }
                            }
                            table.SetWidth(val);
                        }
                        break;
                    }
                    case 4:
                    {
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
                            std::cout << table.GetWeight() << std::endl;
                        }
                        if (s == "Set" || s == "set")
                        {
                            int val;
                            intCheck(val);
                            int exist = table.isExist(inf<std::string, Table>["Table"]);
                            if (exist >= 0)
                            {
                                for (int j = 0; j < inf<std::string, Table>["Table"][exist].size(); ++j)
                                {
                                    inf<std::string, Table>["Table"][exist][j].SetWeight(val);
                                }
                            }
                            table.SetWeight(val);
                        }
                        break;
                    }
                    case 5:
                    {
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
                            std::cout << table.GetMaterial() << std::endl;
                        }
                        if (s == "Set" || s == "set")
                        {
                            std::string val;
                            std::getline(std::cin, val);
                            int exist = table.isExist(inf<std::string, Table>["Table"]);
                            if (exist >= 0)
                            {
                                for (int j = 0; j < inf<std::string, Table>["Table"][exist].size(); ++j)
                                {
                                    inf<std::string, Table>["Table"][exist][j].SetMaterial(val);
                                }
                            }
                            table.SetMaterial(val);
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
                        newTable.addTable(inf<std::string, Table>["Table"], cnt);
                        break;
                    }
                    case 7:
                    {
                        int ans = 0;
                        for (int i = 0; i < inf<std::string, Table>["Table"].size(); ++i)
                        {
                            ans += inf<std::string, Table>["Table"][i].size();
                        }
                        std::cout << ans << std::endl;
                        break;
                    }
                    case 8:
                    {
                        std::cout << inf<std::string, Table>["Table"].size() << std::endl;
                        break;
                    }
                    case 9:
                    {
                        std::cout << std::endl;
                        for (int i = 0; i < inf<std::string, Table>["Table"].size(); ++i)
                        {
                            std::cout << "Height: " << inf<std::string, Table>["Table"][i][0].GetHeight() << std::endl;
                            std::cout << "Lenght: " << inf<std::string, Table>["Table"][i][0].GetLenght() << std::endl;
                            std::cout << "Width: " << inf<std::string, Table>["Table"][i][0].GetWidth() << std::endl;
                            std::cout << "Weight: " << inf<std::string, Table>["Table"][i][0].GetWeight() << std::endl;
                            std::cout << "Material: " << inf<std::string, Table>["Table"][i][0].GetMaterial() << std::endl;
                            std::cout << std::endl;
                        }
                        std::cout << std::endl;
                        break;
                    }
                    case 10:
                    {
                        inf<std::string, Table>["Table"].clear();
                        break;
                    }
                    case 11:
                    {
                        finish = true;
                        flag = true;
                        break;
                    }
                    default:
                    {
                        while (k < 1 || k > 11)
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
                book.addBook(inf<std::string, Book>["Book"], count);
                bool finish = false;
                while (!finish)
                {
                    std::cout << "Availible operations\n1. Get quantity of pages, write 1 and print Get\n";
                    std::cout << "2. Get/Set number of current page, write 2 and print Get or Set and value\n";
                    std::cout << "3. Add element\n";
                    std::cout << "4. Count of elements\n";
                    std::cout << "5. Count of diffrent elements\n";
                    std::cout << "6. Show diffrent elements\n";
                    std::cout << "7. Delete all books\n";
                    std::cout << "8. Return to main menu\n";
                    std::cout << "Enter number of operation: ";
                    bool flag = false;
                    int k;
                    intCheck(k);
                    std::string s;
                    switch (k)
                    {
                    case 1:
                    {
                        std::cin >> s;
                        if (s != "Get" || s != "get")
                        {
                            while (s != "Get" && s != "get")
                            {
                                std::cout << "Enter correct command: ";
                                std::cin >> s;
                            }
                            std::cout << book.GetKol() << std::endl;
                        }
                        break;
                    }
                    case 2:
                    {
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
                            std::cout << book.GetPageNumber() << std::endl;
                        }
                        if (s == "Set" || s == "set")
                        {
                            int val;
                            intCheck(val);
                            int exist = book.isExist(inf<std::string, Book>["Book"]);
                            if (exist >= 0)
                            {
                                for (int j = 0; j < inf<std::string, Book>["Book"][exist].size(); ++j)
                                {
                                    inf<std::string, Book>["Book"][exist][j].SetPageNumber(val);
                                }
                            }
                            book.SetPageNumber(val);
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
                        newBook.addBook(inf<std::string, Book>["Book"], cnt);
                        break;
                    }
                    case 4:
                    {
                        int ans = 0;
                        for (int i = 0; i < inf<std::string, Book>["Book"].size(); ++i)
                        {
                            ans += inf<std::string, Book>["Book"][i].size();
                        }
                        std::cout << ans << std::endl;
                        break;
                    }
                    case 5:
                    {
                        std::cout << inf<std::string, Book>["Book"].size() << std::endl;
                        break;
                    }
                    case 6:
                    {
                        std::cout << std::endl;
                        for (int i = 0; i < inf<std::string, Book>["Book"].size(); ++i)
                        {
                            std::cout << "Quantity of pages: " << inf<std::string, Book>["Book"][i][0].GetKol() << std::endl;
                            std::cout << "Current page: " << inf<std::string, Book>["Book"][i][0].GetPageNumber() << std::endl;
                            if (inf<std::string, Book>["Book"][i][0].GetIsnew())
                            {
                                std::cout << "Book is new" << std::endl;
                            }
                            else
                            {
                                std::cout << "Book is used" << std::endl;
                            }
                            std::cout << std::endl;
                        }
                        std::cout << std::endl;
                        break;
                    }
                    case 7:
                    {
                        inf<std::string, Book>["Book"].clear();
                        break;
                    }
                    case 8:
                    {
                        finish = true;
                        flag = true;
                        break;
                    }
                    default:
                    {
                        while (k < 1 || k > 8)
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
            std::cout << "Enter serial number of object: ";
            int serialNumber;
            intCheck(serialNumber);
            std::cout << "What action would you like to do with object:\n";
            std::string action;
            std::getline(std::cin, action);
            std::getline(std::cin, action);
            std::cout << std::endl;
            Parameter parameter(className, serialNumber, action);
            parameter.addParam(inf<std::string, Parameter>[className], ocnt);
            namesOfClasses.insert(className);
            bool finish = false;
            int countOfElements = ocnt;
            while (!finish)
            {
                std::cout << "Availible operations:\n1. Get name of class, write 1 and get\n";
                std::cout << "2. Get/Set serial number, write 2 and print Get or Set and value\n";
                std::cout << "3. Get/Set action, write 3 and print Get or Set and value\n";
                std::cout << "4. Add element\n";
                std::cout << "5. Count of elements\n";
                std::cout << "6. Count of diffrent elements\n";
                std::cout << "7. Show diffrent elements\n";
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
                    std::cin >> s;
                    if (s != "Get" || s != "get")
                    {
                        while (s != "Get" && s != "get")
                        {
                            std::cout << "Enter correct command: ";
                            std::cin >> s;
                        }
                        std::cout << parameter.getObjectName() << std::endl;
                    }
                    else
                    {
                        std::cout << parameter.getObjectName() << std::endl;
                    }
                    break;
                }
                case 2:
                {
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
                        std::cout << parameter.getSerialNumber() << std::endl;
                    }
                    if (s == "Set" || s == "set")
                    {
                        int val;
                        intCheck(val);
                        int exist = parameter.isExist(inf<std::string, Parameter>[className]);
                        if (exist >= 0)
                        {
                            for (int j = 0; j < inf<std::string, Parameter>[className][exist].size(); ++j)
                            {
                                inf<std::string, Parameter>[className][exist][j].setSerialNumber(val);
                            }
                        }
                    }
                    break;
                }
                case 3:
                {
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
                        std::cout << parameter.getWhatToDo() << std::endl;
                    }
                    if (s == "Set" || s == "set")
                    {
                        std::cout << std::endl;
                        std::string val;
                        std::getline(std::cin, val);
                        int exist = parameter.isExist(inf<std::string, Parameter>[className]);
                        if (exist >= 0)
                        {
                            for (int j = 0; j < inf<std::string, Parameter>[className][exist].size(); ++j)
                            {
                                inf<std::string, Parameter>[className][exist][j].setWhatToDo(val);
                            }
                        }
                    }
                    break;
                }
                case 4:
                {
                    std::cout << "Enter parametrs of new object:\n";
                    std::cout << "Enter name of new class: ";
                    std::string newClassName;
                    std::cin >> newClassName;
                    std::cout << "Enter serial number: ";
                    int newSerialNumber;
                    intCheck(newSerialNumber);
                    std::cout << "Enter what do you want to do: ";
                    std::string newAction;
                    std::getline(std::cin, newAction);
                    std::getline(std::cin, newAction);
                    std::cout << "Enter count of objects: ";
                    int cnt;
                    intCheck(cnt);
                    Parameter newParameter(newClassName, newSerialNumber, newAction);
                    newParameter.addParam(inf<std::string, Parameter>[newClassName], cnt);
                    countOfElements += cnt;
                    namesOfClasses.insert(newClassName);
                    break;
                }
                case 5:
                {
                    std::cout << countOfElements << std::endl;
                    break;
                }
                case 6:
                {
                    std::cout << namesOfClasses.size() << std::endl;
                    break;
                }
                case 7:
                {
                    std::cout << std::endl;
                    for (auto it = namesOfClasses.begin(); it != namesOfClasses.end(); ++it)
                    {
                        for (int j = 0; j < inf<std::string, Parameter>[*it].size(); j++)
                        {
                            std::cout << "Name of class: " << inf<std::string, Parameter>[*it][j][0].getObjectName() << std::endl;
                            std::cout << "Serial number: " << inf<std::string, Parameter>[*it][j][0].getSerialNumber() << std::endl;
                            std::cout << "What you can do with this object: " << inf<std::string, Parameter>[*it][j][0].getWhatToDo() << std::endl;
                            std::cout << std::endl;
                        }
                    }
                    std::cout << std::endl;
                    break;
                    break;
                }
                case 8:
                {
                    for (auto it = namesOfClasses.begin(); it != namesOfClasses.end(); ++it)
                    {
                        inf<std::string, Parameter>[*it].clear();
                    }
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
        case 3:
        {
            std::ofstream fout;
            fout.open("classes_information.txt", std::ios::out | std::ofstream::trunc);
            fout << "class Laptop" << std::endl;
            for (int i = 0; i < inf<std::string, Laptop>["Laptop"].size(); ++i)
            {
                fout << inf<std::string, Laptop>["Laptop"][i][0].GetEfficienty() << " ";
                fout << inf<std::string, Laptop>["Laptop"][i][0].GetProcessorClockFrequency() << " ";
                fout << inf<std::string, Laptop>["Laptop"][i][0].GetProcessorCapacity() << " ";
                fout << inf<std::string, Laptop>["Laptop"][i].size() << std::endl;
            }

            fout << "class Table" << std::endl;
            for (int i = 0; i < inf<std::string, Table>["Table"].size(); ++i)
            {
                fout << inf<std::string, Table>["Table"][i][0].GetHeight() << " ";
                fout << inf<std::string, Table>["Table"][i][0].GetLenght() << " ";
                fout << inf<std::string, Table>["Table"][i][0].GetWidth() << " ";
                fout << inf<std::string, Table>["Table"][i][0].GetWeight() << " ";
                fout << inf<std::string, Table>["Table"][i][0].GetMaterial() << " ";
                fout << inf<std::string, Table>["Table"][i].size() << std::endl;
            }

            fout << "class Book" << std::endl;
            for (int i = 0; i < inf<std::string, Book>["Book"].size(); ++i)
            {
                fout << inf<std::string, Book>["Book"][i][0].GetKol() << " ";
                fout << inf<std::string, Book>["Book"][i][0].GetPageNumber() << " ";
                fout << inf<std::string, Book>["Book"][i][0].GetIsnew() << " ";
                fout << inf<std::string, Book>["Book"][i].size() << std::endl;
            }

            fout << "class Parameter" << std::endl;
            for (auto it = namesOfClasses.begin(); it != namesOfClasses.end(); ++it)
            {
                for (int i = 0; i < inf<std::string, Parameter>[*it].size(); ++i)
                {
                    fout << *it << " ";
                    fout << inf<std::string, Parameter>[*it][i][0].getSerialNumber() << " ";
                    fout << inf<std::string, Parameter>[*it][i][0].getWhatToDo() << " ";
                    fout << inf<std::string, Parameter>[*it][i].size() << std::endl;
                }
            }
            fout.close();
            return 0;
        }

        default:
            while (classOfObject < 1 || classOfObject > 3)
            {
                intCheck(classOfObject);
            }
            break;
        }
    }
    return 0;
}