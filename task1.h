#include <iostream>

class Laptop
{
public:
    int GetEfficienty()
    {
        return this->efficiency;
    }

    int SetEfficienty(int val)
    {
        this->efficiency = val;
    }

    int GetProcessor_clock_frequency()
    {
        return this->processor_clock_frequency;
    }

    int SetEfficienty(int val)
    {
        this->processor_clock_frequency = val;
    }

    int GetProcessorCapacity()
    {
        return this->processor_capacity;
    }

    int SetEfficienty(int val)
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

    int SetCharge(int val)
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
    int GetHeight()
    {
        return this->height;
    }

    int SetHeight(int val)
    {
        this->height = val;
    }

    int GetWeight()
    {
        return this->weight;
    }

    int SetWeight(int val)
    {
        this->weight = val;
    }

    int GetLenght()
    {
        return this->lenght;
    }

    int SetLenght(int val)
    {
        this->lenght = val;
    }

    int GetWidth()
    {
        return this->width;
    }

    int SetWidth(int val)
    {
        this->width = val;
    }

    std::string GetMaterial(){
        return this->material;
    }

    std::string SetMaterial(std::string val){
        this->material = val;
    }

Table(int h, int w, int len, int wd, std::string mat): height(h), weight(w), lenght(len), width(wd), material(mat){}
private:
    int height = 0;
    int weight = 0;
    int lenght = 0;
    int width = 0;
    std::string material = "";
};

int main(){}