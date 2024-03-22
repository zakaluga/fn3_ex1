#include "../header_files/includes.h"

class Laptop
{
public:
    Laptop(int EffVal, int ClockVal, int CapVal) : efficiency(EffVal), ProcessorClockFrequency(ClockVal), processor_capacity(CapVal) {}
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
        return this->processor_capacity;
    }

    void SetProcessorCapacity(int val)
    {
        this->processor_capacity = val;
    }

    template <class T>
    int isExist(std::vector<std::vector<T>> v)
    {
        bool ans = false;
        for (int i = 0; i < v.size(); ++i)
        {
            if (!std::empty(v[i]))
            {
                ans = (v[i][0].processor_capacity == this->processor_capacity) &&
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
    int processor_capacity = 0;
};

class Parameter
{
public:
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

    int getserialNumber()
    {
        return this->serialNumber;
    }

    void setserialNumber(int val)
    {
        this->serialNumber = val;
    }

    std::string getwhatToDo()
    {
        return this->whatToDo;
    }

    void setwhatToDo(std::string &str)
    {
        this->whatToDo = str;
    }

    template <class T>
    int isExist(std::vector<std::vector<T>> v)
    {
        bool ans = false;
        for (int i = 0; i < v.size.size(); ++i)
        {
            if (!std::empty(v[i]))
            {
                ans = (v[i][0].getserialNumber() == this->serialNumber) && (v[i][0].getwhatToDo() == this->whatToDo);
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

    template <class T, class U>
    void addTable(std::map<T, std::vector<U>> &inf, int cnt = 1)
    {

        for (int i = 0; i < cnt; ++i)
        {
            inf["Table"].push_back(*this);
        }
    }

private:
    int height = 0;
    int lenght = 0;
    int width = 0;
    int weight = 0;
    std::string material = "";
};

class Notebook
{
public:
    Notebook(int k, int pn) : kol(k), page_number(pn) {}
    ~Notebook() = default;

    int GetKol()
    {
        return this->kol;
    }

    int GetPageNumber()
    {
        return this->page_number;
    }

    void SetPageNumber(int val)
    {
        this->page_number = val;
    }

    void MakeUsed()
    {
        this->Isnew = false;
    }

    template <class T, class U>
    void addBook(std::map<T, std::vector<U>> &inf, int cnt = 1)
    {

        for (int i = 0; i < cnt; ++i)
        {
            inf["Book"].push_back(*this);
        }
    }

private:
    int kol = 0;
    int page_number = 0;
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

template <class T, class U>
std::map<T, std::vector<std::vector<U>>> inf;

int main()
{
    int classOfObject = 0;
    while (classOfObject != 3)
    {
        std::cout << "You can choose:\n1. Academic object\n2. Abstract object\n3. Exit" << std::endl;
        std::cin >> classOfObject;
        switch (classOfObject)
        {
        case 1:
        {
            std::cout << "You can choose:\n1. Laptop\n2. Table\n3. Notebook\n4. Exit to main menu" << std::endl;
            std::cout << "Enter number of object: ";

            std::string nstr;
            int n;
            std::cin >> nstr;
            if (Digit(nstr))
            {
                n = std::stoi(nstr);
            }
            else
            {
                while (!Digit(nstr))
                {
                    std::cout << "Enter correct number of object: ";
                    std::cin >> nstr;
                }
                n = std::stoi(nstr);
            }
            switch (n)
            {
            case 1: // Full debag of class Laptop
            {
                std::cout << "Enter count of objects: ";

                std::string countstr;
                int count;
                std::cin >> countstr;
                if (Digit(countstr))
                {
                    count = std::stoi(countstr);
                }
                else
                {
                    while (!Digit(countstr))
                    {
                        std::cout << "Enter correct count: ";
                        std::cin >> countstr;
                    }
                    count = std::stoi(countstr);
                }

                std::cout << std::endl;
                std::cout << "Enter efficiency: ";
                std::string efstr;
                int ef;
                std::cin >> efstr;
                if (Digit(efstr))
                {
                    ef = std::stoi(efstr);
                }
                else
                {
                    while (!Digit(efstr))
                    {
                        std::cout << "Enter correct efficienty: ";
                        std::cin >> efstr;
                    }
                    ef = std::stoi(efstr);
                }
                std::cout << "Enter processor clock frequency: ";
                std::string freqstr;
                int freq;
                std::cin >> freqstr;
                if (Digit(freqstr))
                {
                    freq = std::stoi(freqstr);
                }
                else
                {
                    while (!Digit(freqstr))
                    {
                        std::cout << "Enter correct frequency: ";
                        std::cin >> freqstr;
                    }
                    freq = std::stoi(freqstr);
                }
                std::cout << "Enter processor capacity: ";
                std::string capstr;
                int cap;
                std::cin >> capstr;
                if (Digit(capstr))
                {
                    cap = std::stoi(capstr);
                }
                else
                {
                    while (!Digit(capstr))
                    {
                        std::cout << "Enter correct capacity: ";
                        std::cin >> capstr;
                    }
                    cap = std::stoi(capstr);
                }
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
                    std::cin >> k;
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
                                std::cout << "Enter correct command: ";
                                std::cin >> s;
                            }
                        }
                        if (s == "Get" || s == "get")
                        {
                            std::cout << laptop.GetEfficienty() << std::endl;
                        }
                        if (s == "Set" || s == "set")
                        {
                            std::string val;
                            std::cin >> val;
                            if (Digit(val))
                            {
                                laptop.SetEfficienty(std::stoi(val));
                            }
                            else
                            {
                                while (!Digit(val))
                                {
                                    std::cout << "Enter correct value: ";
                                    std::cin >> val;
                                }
                                laptop.SetEfficienty(std::stoi(val));
                            }
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
                            std::string val;
                            std::cin >> val;
                            if (Digit(val))
                            {
                                laptop.SetProcessorClockFrequency(std::stoi(val));
                            }
                            else
                            {
                                while (!Digit(val))
                                {
                                    std::cout << "Enter correct value: ";
                                    std::cin >> val;
                                }
                                laptop.SetProcessorClockFrequency(std::stoi(val));
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
                            std::cout << laptop.GetProcessorCapacity() << std::endl;
                        }
                        if (s == "Set" || s == "set")
                        {
                            std::string val;
                            std::cin >> val;
                            if (Digit(val))
                            {
                                laptop.SetProcessorCapacity(std::stoi(val));
                            }
                            else
                            {
                                while (!Digit(val))
                                {
                                    std::cout << "Enter correct value: ";
                                    std::cin >> val;
                                }
                                laptop.SetProcessorCapacity(std::stoi(val));
                            }
                        }
                        break;
                    }
                    case 4:
                    {
                        std::cout << "Enter parametrs of new Laptop:\n";
                        std::cout << "Enter efficiency: ";
                        int ef1;
                        std::string ef1str;
                        std::cin >> ef1str;
                        if (Digit(ef1str))
                        {
                            ef1 = std::stoi(ef1str);
                        }
                        else
                        {
                            while (!Digit(ef1str))
                            {
                                std::cout << "Enter correct efficienty: ";
                                std::cin >> efstr;
                            }
                            ef1 = std::stoi(ef1str);
                        }
                        std::cout << "Enter processor clock frequency: ";
                        std::string freq1str;
                        int freq1;
                        std::cin >> freq1str;
                        if (Digit(freq1str))
                        {
                            freq1 = std::stoi(freq1str);
                        }
                        else
                        {
                            while (!Digit(freq1str))
                            {
                                std::cout << "Enter correct efficienty: ";
                                std::cin >> freq1str;
                            }
                            freq1 = std::stoi(freq1str);
                        }
                        std::cout << "Enter processor capacity: ";
                        std::string cap1str;
                        int cap1;
                        std::cin >> cap1str;
                        if (Digit(cap1str))
                        {
                            cap1 = std::stoi(cap1str);
                        }
                        else
                        {
                            while (!Digit(cap1str))
                            {
                                std::cout << "Enter correct efficienty: ";
                                std::cin >> cap1str;
                            }
                            cap1 = std::stoi(cap1str);
                        }
                        std::cout << "Enter count of objects: ";
                        std::string cntstr;
                        int cnt;
                        std::cin >> cntstr;
                        if (Digit(cntstr))
                        {
                            cnt = std::stoi(cntstr);
                        }
                        else
                        {
                            while (!Digit(cntstr))
                            {
                                std::cout << "Enter correct efficienty: ";
                                std::cin >> cntstr;
                            }
                            cnt = std::stoi(cntstr);
                        }
                        Laptop laptop1(ef1, freq1, cap1);
                        laptop1.addLaptop(inf<std::string, Laptop>["Laptop"], cnt);
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
            case 2:
            {
                std::cout << "Enter count of objects: ";

                std::string countstr;
                int count;
                std::cin >> countstr;
                if (Digit(countstr))
                {
                    count = std::stoi(countstr);
                }
                else
                {
                    while (!Digit(countstr))
                    {
                        std::cout << "Enter correct count: ";
                        std::cin >> countstr;
                    }
                    count = std::stoi(countstr);
                }

                std::cout << std::endl;
                std::cout << "Enter height of the table: ";
                int height;
                std::cin >> height;
                std::cout << "Enter lenght of the table: ";
                int len;
                std::cin >> len;
                std::cout << "Enter width of the table: ";
                int width;
                std::cin >> width;
                std::cout << "Enter weight of the table: ";
                int weight;
                std::cin >> weight;
                std::cout << "Enter material of the table: ";
                std::string mat;
                std::cin >> mat;
                Table table(height, len, width, weight, mat);
                break;
            }
            case 3:
            {
                std::cout << "Enter count of objects: ";

                std::string countstr;
                int count;
                std::cin >> countstr;
                if (Digit(countstr))
                {
                    count = std::stoi(countstr);
                }
                else
                {
                    while (!Digit(countstr))
                    {
                        std::cout << "Enter correct count: ";
                        std::cin >> countstr;
                    }
                    count = std::stoi(countstr);
                }

                std::cout << std::endl;
                std::cout << "Enter kol pages of notebook: ";
                int kol;
                std::cin >> kol;
                std::cout << "Enter current page of notebook: ";
                int curPage;
                std::cin >> curPage;
                Notebook notebook(kol, curPage);
                if (curPage != 0)
                {
                    notebook.MakeUsed();
                }
                break;
            }
            case 4:
            {
                break;
            }
            default:
                while (n < 1 || n > 3)
                {
                    std::cout << "Enter correct number of object: ";
                    std::cin >> n;
                }
            }
        }
        case 2:{
            break;
        }
        case 3:{
            return 0;
        }

        default:
            while (classOfObject < 1 || classOfObject > 3)
            {
                std::cout << "Enter correct number of object: ";
                std::cin >> classOfObject;
            }
            break;
        }
    }
    return 0;
}