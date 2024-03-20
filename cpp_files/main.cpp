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

    Notebook(int k, int pn): kol(k), page_number(pn){}
    ~Notebook() = default;

    int GetKol(){
        return this->kol;
    }

    int GetPageNumber(){
        return this->page_number;
    }

    void SetPageNumber(int val){
        this->page_number = val;
    }

    void MakeUsed(){
        this->Isnew = false;
    }

private:
    int kol = 0;
    int page_number = 0;
    bool Isnew = true;
};

template <class T>
void addLaptop(std::map<std::string, std::vector<T>> &inf, std::vector<T> &v, int &cnt, std::tuple<int, int, int> &t)
{

    Laptop laptop(std::get<0>(t), std::get<1>(t), std::get<2>(t));
    for (int i = 0; i < cnt; ++i)
    {
        v.push_back(laptop);
    }
    inf.insert(inf.end(), {"Laptop", v});
}

template <class T>
void addPen(std::map<std::string, std::vector<T>> &inf, std::vector<T> &v, int &cnt, std::pair<int, bool> &t)
{

    Pen pen(t.first, t.second);
    for (int i = 0; i < cnt; ++i)
    {
        v.push_back(pen);
    }
    inf.insert(inf.end(), {"Pen", v});
}

template <class U>
void addTable(std::map<std::string, std::vector<U>> &inf, std::vector<U> &v, int &cnt, std::tuple<int, int, int, int, std::string> &t)
{

    Table table(std::get<0>(t), std::get<1>(t), std::get<2>(t), std::get<3>(t), std::get<4>(t));
    for (int i = 0; i < cnt; ++i)
    {
        v.push_back(table);
    }
    inf.insert(inf.end(), {"Table", v});
}

template <class U>
void addNotebook(std::map<std::string, std::vector<U>> &inf, std::vector<U> &v, int &cnt, std::pair<int, int> &t)
{

    Notebook book(t.first, t.second);
    for (int i = 0; i < cnt; ++i)
    {
        v.push_back(book);
    }
    inf.insert(inf.end(), {"Notebook", v});
}

template<class U>
std::map<std::string, std::vector<U>> inf;

template<class T>
std::vector<T> sp;

int main()
{
    std::cout << "You can choose\n1. Laptop\n2. Pen\n3. Table\n4. Notebook" << std::endl;
    int n;
    std::cin >> n;
    int count;
    std::cout << "Enter count of objects: ";
    std::cin >> count;
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
        Laptop laptop(ef, freq, cap);
        addLaptop(inf<std::string, std::vector<Laptop>>, sp<Laptop>, count, std::make_tuple(ef, freq, cap));
        bool finish = true;
        while (finish)
        {
            std::cout << "Availible operations\n1. Get/Set efficiency, write 1 and print get or set and value\n";
            std::cout << "2. Get/Set processor clock frequency, write 2 and print get or set and value\n";
            std::cout << "3. Get/Set processor capacity, write 3 and print get or set and value\n";
            int k;
            std::string s;
            std::cin >> k >> s;
            switch (k)
            {
            case 1:
            {
                if (s == "get")
                {
                    std::cout << laptop.GetEfficienty();
                }
                else
                {
                    int val;
                    std::cin >> val;
                    laptop.SetEfficienty(val);
                }
                break;
            }
            case 2:
            {
                if (s == "get")
                {
                    std::cout << laptop.GetProcessor_clock_frequency();
                }
                else
                {
                    int val;
                    std::cin >> val;
                    laptop.SetProcessor_clock_frequency(val);
                }
                break;
            }
            case 3:
            {
                if (s == "get")
                {
                    std::cout << laptop.GetProcessorCapacity();
                }
                else
                {
                    int val;
                    std::cin >> val;
                    laptop.SetProcessorCapacity(val);
                }
                break;
            }
            default:
                break;
            }
            // Как будто никто смотреть это не будет
        }
        break;
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
        break;
    }
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
        break;
    }
    return 0;
}
