#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <list>

struct Base
{
    int width;
    int length;
    int hight;
    std::string color;
};

void Print_string(std::string name)
{
    std::cout << "" << name << std::endl;
};

void Print_digit(int digit)
{
    std::cout << "tjdtyj" << digit << std::endl;
};

class Computers
{
    std::string serial_number;
    std::string graph_card;
    std::string cpu;

public:
    Computers(std::string _serial_number, std::string _graph_card, std::string _cpu)
    {
        serial_number = _serial_number;
        graph_card = _graph_card;
        cpu = _cpu;
    }
    void Set_number(){

    };
    std::string Get_number()
    {
        return serial_number;
    };
    void Set_card(){

    };
    std::string Get_card()
    {
        return graph_card;
    };
    void Set_cpu(){

    };
    std::string Get_cpu()
    {
        return cpu;
    };
};

std::ostream &operator<<(std::ostream &out, const Computers &computer)
{
    return out << "computer's number: " << computer.Get_number() << std::endl
               << "computer's graphic card: " << computer.Get_card() << std::endl
               << "computer's CPU: " << computer.Get_cpu() << std::endl;
}

class Monitors
{
    Base screen;
    int resolution;
};

class Portaits
{
    Base picture;
    std::string name;
};

class Tables
{
};

bool IsDigit(std::string str)
{
    size_t z = str.length();
    for (size_t i = 0; i < z; i++)
    {
        if (!std::isdigit(str[i]))
        {
            return false;
        }
    };
    return true;
};

void Menu_Print()
{
    using namespace std;
    for (int i = 0; i < 3; i++)
    {
        cout << endl;
    }
    cout << "MENU" << endl;
    cout << "1. Show  computer's list" << endl;
    cout << "2. Show table's list" << endl;
    cout << "3. Show chair's list" << endl;
    cout << "4. Show portaits's list" << endl;
    cout << "5. Show all lists" << endl;
}

int main()
{
    using namespace std;
    setlocale(LC_ALL, "Rus");
    string choisestr;

    /*ofstream myfile;
    myfile.open("inventar.txt");
    myfile.
*/

    list<Computers> List_computer;
    // List_1.push_back(Computers(a));

    Menu_Print(); // печать менюшки

    for (int i = 0; i < 3; i++)
    {
        cout << endl;
    }

    cin >> choisestr;

    for (int i = 0; i < 3; i++)
    {
        cout << endl;
    }
    while (!IsDigit(choisestr))
    {
        cout << "Wrong number. Enter value again:\n";
        cin >> choisestr;
        for (int i = 0; i < 3; i++)
        {
            cout << endl;
        }
    }

    int first_choise = stoi(choisestr);
    Menu_Print();
    switch (first_choise)
    {
    case 1: // список компьютеров
        // list<Computers>::iterator i = List_computer.begin();
        for (auto i = List_computer.begin(); i != List_computer.end(); i++)
        { // т.к. итератор - это по сути ссылка на эл-т кон-та, то чтоб получить значение эл-та, нужно разыменовать итератор
            cout << *i << endl;
        }

        int second_coise;
        cout << "1.1 Emplace new element" << endl;
        cout << "1.2 Delete element" << endl;
        cout << "1.3 Change some element's characteristic"<<endl; 
        
        cin >> second_coise;

        switch (second_coise)
        {
        case 1:
            string comp_number;
            string comp_card;
            string comp_cpu;

            cout << "Enter computer's number: ";
            cin >> comp_number;
            cout << "Enter computer's graphic card: ";
            cin >> comp_card;
            cout << "Enter computer's CPU: ";
            cin >> comp_cpu;
            Computers new_object{comp_number, comp_card, comp_cpu};

            List_computer.push_back(new_object);

            break;
        case 2:
            auto p = List_computer.begin();
            cout<<"Which one element you want to remove?"
            
            
            List_computer.erase(p) //нужно поместить в р индекс удаляемого элемента 
            //или 
            List_computer.remove( value )
        };

    default:
        cout << "There is no such option" 
        break;
    };
};
