#include <iostream>

class Laptop
{
public:
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

    Laptop(int EffVal, int ClockVal, int CapVal) : efficiency(EffVal), processor_clock_frequency(ClockVal), processor_capacity(CapVal) {}
    ~Laptop() = default;

private:
    int efficiency = 0;
    int processor_clock_frequency = 0;
    int processor_capacity = 0;
};

class Pen
{
public:
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

    Pen(int procent, bool wm) : charge(procent), WithMe(wm) {}
    ~Pen() = default;

private:
    int charge = 100;
    bool WithMe = true;
};

class Table
{
public:
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

    Table(int h, int len, int wd, int w, std::string mat) : height(h), weight(w), lenght(len), width(wd), material(mat) {}
    ~Table() = default;

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

    Notebook(int k, int pn): kol(k), page_number(pn){}
    ~Notebook() = default;

private:
    int kol = 0;
    int page_number = 0;
    bool Isnew = true;
};