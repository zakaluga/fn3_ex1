#include "../header_files/includes.h"

class Laptop
{
public:
    Laptop(int EffVal, int ClockVal, int CapVal) : efficiency(EffVal), processor_clock_frequency(ClockVal), processor_capacity(CapVal) {}
    ~Laptop() = default;

    int GetEfficienty()
    {
        return this->efficiency;
    }

    void SetEfficienty(int val)
    {
        this->efficiency = val;
    }

    int GetProcessor_clock_frequency()
    {
        return this->processor_clock_frequency;
    }

    void SetProcessor_clock_frequency(int val)
    {
        this->processor_clock_frequency = val;
    }

    int GetProcessorCapacity()
    {
        return this->processor_capacity;
    }

    void SetProcessorCapacity(int val)
    {
        this->processor_capacity = val;
    }

    template <class T, class U>
    void addLaptop(std::map<T, std::vector<U>> &inf, int cnt = 1)
    {
        for (int i = 0; i < cnt; ++i)
        {
            inf["Laptop"].push_back(*this);
        }
    }

private:
    int efficiency = 0;
    int processor_clock_frequency = 0;
    int processor_capacity = 0;
};

class Pen
{
public:
    Pen(int procent, bool wm) : charge(procent), WithMe(wm) {}
    ~Pen() = default;

    int GetCharge()
    {
        return this->charge;
    }

    void SetCharge(int val)
    {
        this->charge = val;
    }

    bool IsEmpty()
    {
        if (this->WithMe)
        {
            return this->charge == 0 ? true : false;
        }
    }

    template <class T, class U>
    void addPen(std::map<U, std::vector<T>> &inf, int cnt = 1)
    {
        for (int i = 0; i < cnt; ++i)
        {
            inf["Pen"].push_back(*this);
        }
    }

private:
    int charge = 100;
    bool WithMe = true;
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

bool isdigit(const std::string s)
{
    bool ans = true;
    for (int i = 0; i < s.length(); ++i)
    {
        ans = ans && ('0' <= s[i] <= '9');
    }
    return ans;
}

template <class T, class U>
std::map<T, std::vector<U>> inf;

// Заменить данные
// добавить данные

int main()
{
    std::cout << "You can choose\n1. Laptop\n2. Pen\n3. Table\n4. Notebook" << std::endl;
    std::cout << "Enter number of obgect: ";
    int n;
    std::cin >> n;
    int count;
    std::cout << "Enter count of objects: ";
    std::cin >> count;
    std::cout << std::endl;
    switch (n)
    {
    case 1:
    {
        std::cout << "Enter efficiency: ";
        int ef;
        std::cin >> ef;
        std::cout << "Enter processor clock frequency: ";
        int freq;
        std::cin >> freq;
        std::cout << "Enter processor capacity: ";
        int cap;
        std::cin >> cap;
        std::cout << std::endl;
        Laptop laptop(ef, freq, cap);
        laptop.addLaptop(inf<std::string, Laptop>);
        bool finish = false;
        while (!finish)
        {
            bool flag = false;
            std::cout << "Availible operations\n1. Get/Set efficiency, write 1 and print Get or Set or Add and value\n";
            std::cout << "2. Get/Set processor clock frequency, write 2 and print Get or Set or Add and value\n";
            std::cout << "3. Get/Set processor capacity, write 3 and print Get or Set or Add and value\n";
            std::cout << "4. Add element\n";
            std::cout << "5. Count of elements\n";
            std::cout << "Enter number of operation: ";
            int k;
            std::cin >> k;
            std::string s;
            switch (k)
            {
            case 1:
            {
                std::cin >> s;
                if (s == "Get" || s == "get")
                {
                    std::cout << laptop.GetEfficienty() << std::endl;
                }
                else
                {
                    if (s == "Set" || s == "set")
                    {
                        std::string val;
                        std::cin >> val;
                        if (isdigit(val))
                        {
                            laptop.SetEfficienty(std::stoi(val));
                        }
                        else
                        {
                            while (s != "Set" || s != "set" || s != "Get" || s != "get")
                            {
                                std::cout << "Enter correct command: ";
                                std::cin >> s;
                                flag = true;
                            }
                        }
                    }
                }
                break;
            }
            case 2:
            {
                std::cin >> s;

                if (s == "Get" || s == "get")
                {
                    std::cout << laptop.GetProcessor_clock_frequency() << std::endl;
                }
                else
                {
                    if (s == "Set" || s == "set")
                    {
                        std::string val;
                        std::cin >> val;
                        if (isdigit(val))
                        {
                            laptop.SetProcessor_clock_frequency(std::stoi(val));
                        }
                        else
                        {
                            while ((!isdigit(val)))
                            {
                                std::cout << "Enter correct value: ";
                                std::cin >> val;
                            }
                        }
                    }
                    else
                    {
                        while (s != "Set" || s != "set" || s != "Get" || s != "get")
                        {
                            std::cout << "Enter correct command: ";
                            std::cin >> s;
                            flag = true;
                        }
                    }
                }
                break;
            }
            case 3:
            {
                std::cin >> s;
                if (s == "Get" || s == "get")
                {
                    std::cout << laptop.GetProcessorCapacity() << std::endl;
                }
                else
                {
                    if (s == "Set" || s == "set")
                    {
                        std::string val;
                        std::cin >> val;
                        if (isdigit(val))
                        {
                            laptop.SetProcessorCapacity(std::stoi(val));
                        }
                        else
                        {
                            while (!isdigit(val))
                            {
                                std::cout << "Enter correct value: ";
                                std::cin >> val;
                            }
                        }
                    }
                    else
                    {
                        while (s != "Set" || s != "set" || s != "Get" || s != "get")
                        {
                            std::cout << "Enter correct command: ";
                            std::cin >> s;
                            flag = true;
                        }
                    }
                }
                break;
            }
            case 4:
            {
                std::cout << "Enter parametrs of new Laptop:\n";
                std::cout << "Enter efficiency: ";
                int ef1;
                std::cin >> ef1;
                std::cout << "Enter processor clock frequency: ";
                int freq1;
                std::cin >> freq1;
                std::cout << "Enter processor capacity: ";
                int cap1;
                std::cin >> cap1;
                std::cout << "Enter count of objects: ";
                int cnt;
                std::cin >> cnt;
                Laptop laptop1(ef1, freq1, cap1);
                laptop1.addLaptop(inf<std::string, Laptop>, cnt);
                break;
            }
            case 5:
            {
                std::cout << inf<std::string, Laptop>["Laptop"].size() << std::endl;
                break;
            }
            default:
            {
                while (k < 1 || k > 5)
                {
                    std::cout << "Enter correct number of command: ";
                    std::cin >> k;
                    flag = true;
                }
            }
                //     if (flag)
                //     {
                //         std::cout << "If you want to continue to work with class Laptop press [y] else press [n]: ";
                //         char symbol;
                //         std::cin >> symbol;
                //         if (symbol == 'n')
                //         {
                //             finish = true;
                //         }
                //         else
                //         {
                //             if (symbol != 'y')
                //             {
                //                 while (symbol != 'y' && symbol != 'n')
                //                 {
                //                     std::cout << "Enter correct command: ";
                //                     std::cin >> symbol;
                //                 }
                //             }
                //             else
                //             {
                //                 continue;
                //             }
                //         }
                //     }
                // }
                // break;
            }
        }
    }
    case 2:
    {
        std::cout << "Enter cahrge of your pen: ";
        int charge;
        std::cin >> charge;
        std::cout << "Press 1 if your pen with you else press 0: ";
        bool withMe;
        std::cin >> withMe;
        Pen pen(charge, withMe);
    }   break;
    case 3:
    {
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
    case 4:
    {
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
    default:
        while (n < 1 || n > 4)
        {
            std::cout << "Enter correct number of object: ";
            std::cin >> n;
        }

        return 0;
    }
}
